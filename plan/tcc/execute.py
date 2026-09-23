"""Plan sections 14 and 16: execution modes.

    eager            E(f, x, c)
    fp64 reference   E(f, x64, c)      the numeric truth O1 compares against
    cold compile     reset -> C(f, x, c)
    warm sequence    compile(c1) -> execute(c2) [-> execute(c1)]   no reset
    layered          E0 eager, E1 backend=eager, E2 aot_eager, E3 inductor,
                     E4 inductor + Triton (GPU only)

Two rules. (1) There are two cache layers: ``torch._dynamo.reset()`` clears
the in-process caches but not the on-disk FX-graph / Inductor / Triton caches,
so a "cold" run must disable those explicitly. (2) Recompiles are counted by
wrapping the backend, never guessed from logs.

Faulty compilers (``tcc.faults``) plug in through :class:`Compiler`, so the
same execution matrix runs against real ``torch.compile`` and against
injected defects that form the ground-truth benchmark.
"""
from __future__ import annotations

import time
from dataclasses import dataclass, field
from typing import Any, Callable, Dict, List, Optional, Sequence, Tuple

from .compat import (CompileCounter, cache_scope, compile_fn, counters_snapshot, dynamo_reset,
                     frames_total, has_cuda, has_triton, is_infra_failure, seed_everything, sync,
                     torch)
from .observe import Observation, flatten, is_tensor, observe
from .program import Context, Program, apply_factors

E0_EAGER = "E0_eager"
E1_DYNAMO = "E1_dynamo_eager"
E2_AOT = "E2_aot_eager"
E3_INDUCTOR = "E3_inductor"
E4_TRITON = "E4_inductor_triton"

LAYERS: List[Tuple[str, Optional[str]]] = [
    (E0_EAGER, None), (E1_DYNAMO, "eager"), (E2_AOT, "aot_eager"), (E3_INDUCTOR, "inductor"),
]


def layer_available(mode: str) -> bool:
    if mode == E4_TRITON:
        return has_cuda() and has_triton()
    return True


# --------------------------------------------------------------------------
# compilers
# --------------------------------------------------------------------------

class Compiler:
    """Something that turns ``fn`` into a compiled callable and counts compiles."""

    name: str = "abstract"

    def compile(self, fn: Callable, ctx: Optional[Context] = None) -> Callable:
        raise NotImplementedError

    def reset(self) -> None:
        dynamo_reset()

    def compiles_since_reset(self) -> int:
        return 0

    def mark(self) -> None:
        """Zero the windowed compile counter."""


class TorchCompiler(Compiler):
    """Real ``torch.compile`` with a named backend and a compile counter."""

    def __init__(self, backend: str = "inductor", dynamic: Optional[bool] = None,
                 options: Optional[Dict[str, Any]] = None):
        self.backend = backend
        self.dynamic = dynamic
        self.options = dict(options or {})
        self.name = f"torch.compile[{backend}]"
        self.counter: Optional[CompileCounter] = None

    def compile(self, fn: Callable, ctx: Optional[Context] = None) -> Callable:
        self.counter = CompileCounter(self.backend)
        dyn = self.dynamic
        opts = dict(self.options)
        if ctx is not None and isinstance(ctx.get("compile"), dict):
            c = ctx.get("compile")
            if "dynamic" in c:
                dyn = c["dynamic"]
            opts.update({k: v for k, v in c.items() if k != "dynamic"})
        return compile_fn(fn, self.counter, dynamic=dyn, **opts)

    def compiles_since_reset(self) -> int:
        return self.counter.count if self.counter else 0

    def mark(self) -> None:
        if self.counter:
            self.counter.reset()


# --------------------------------------------------------------------------
# inputs
# --------------------------------------------------------------------------

def build_inputs(program: Program, ctx: Context, seed: int = 0) -> Tuple[Any, ...]:
    """Deterministic inputs: reseed immediately before every build.

    Every oracle compares two executions of the same context, so both must
    receive bit-identical inputs; ``make_inputs`` usually calls ``randn``.
    """
    seed_everything(seed)
    args = program.make_inputs(ctx)
    if not isinstance(args, tuple):
        args = (args,)
    return apply_factors(args, ctx)


def to_fp64(obj: Any) -> Any:
    if is_tensor(obj):
        if obj.is_floating_point():
            t = obj.detach().to(torch.float64)
            t.requires_grad_(obj.requires_grad)
            return t
        return obj.detach().clone()
    if isinstance(obj, (list, tuple)):
        conv = [to_fp64(v) for v in obj]
        return tuple(conv) if isinstance(obj, tuple) else conv
    if isinstance(obj, dict):
        return {k: to_fp64(v) for k, v in obj.items()}
    return obj


# --------------------------------------------------------------------------
# invocation
# --------------------------------------------------------------------------

def invoke(fn: Callable, inputs: Tuple[Any, ...], mode: str, compiler: Optional[Compiler] = None,
           with_grad: bool = True) -> Observation:
    before = counters_snapshot()
    if compiler is not None:
        compiler.mark()
    exc: Optional[BaseException] = None
    out: Any = None
    t0 = time.perf_counter()
    try:
        out = fn(*inputs)
        sync()
    except Exception as e:  # noqa: BLE001 - an exception is an observation
        exc = e
    wall = time.perf_counter() - t0
    obs = observe(mode, inputs, out, exc, with_grad=with_grad)
    obs.infra_error = (not obs.ok) and is_infra_failure(obs.exception, obs.exception_msg)
    obs.compiles = compiler.compiles_since_reset() if compiler is not None else 0
    obs.frames_delta = frames_total(counters_snapshot()) - frames_total(before)
    obs.wall_s = wall
    return obs


def _run(program: Program, ctx: Context, fn: Callable, mode: str,
         compiler: Optional[Compiler], seed: int) -> Observation:
    if program.reset is not None:
        try:
            program.reset()
        except Exception:
            pass
    inputs = build_inputs(program, ctx, seed)
    seed_everything(seed)
    return invoke(fn, inputs, mode, compiler, with_grad=program.check_grad)


def run_eager(program: Program, ctx: Context, seed: int = 0) -> Observation:
    return _run(program, ctx, program.fn, E0_EAGER, None, seed)


def run_fp64(program: Program, ctx: Context, seed: int = 0) -> Optional[Observation]:
    if program.skip_fp64 or torch is None:
        return None
    try:
        inputs = to_fp64(build_inputs(program, ctx, seed))
    except Exception:
        return None
    seed_everything(seed)
    obs = invoke(program.fn, inputs, "fp64_ref", None, with_grad=program.check_grad)
    return obs if obs.ok else None


def run_cold(program: Program, ctx: Context, compiler: Compiler,
             disk_cache: bool = False, seed: int = 0, mode: Optional[str] = None) -> Observation:
    compiler.reset()
    with cache_scope(disk_cache):
        fn = compiler.compile(program.fn, ctx)
        obs = _run(program, ctx, fn, mode or f"cold[{compiler.name}]", compiler, seed)
    compiler.reset()
    return obs


def run_sequence(program: Program, ctxs: Sequence[Context], compiler: Compiler,
                 disk_cache: bool = False, seed: int = 0) -> List[Observation]:
    """Compile once, then execute every context in order **without a reset**.

    ``obs.compiles > 0`` on a step means a guard rejected the cached artifact
    and a recompile happened - correct behaviour, and the case where a
    divergence is not evidence of a specialization bug.
    """
    compiler.reset()
    out: List[Observation] = []
    with cache_scope(disk_cache):
        fn = compiler.compile(program.fn, ctxs[0] if ctxs else None)
        for i, ctx in enumerate(ctxs):
            obs = _run(program, ctx, fn, f"seq{i}[{ctx.name}]", compiler, seed)
            out.append(obs)
            if not obs.ok and i == 0:
                break  # nothing warm to probe if the first context failed
    compiler.reset()
    return out


def run_layered(program: Program, ctx: Context, disk_cache: bool = False, seed: int = 0,
                layers: Optional[List[Tuple[str, Optional[str]]]] = None,
                compilers: Optional[Dict[str, Compiler]] = None) -> Dict[str, Observation]:
    """E0..E3 (E4 when a GPU + Triton exist), so a divergence gets a stage."""
    out: Dict[str, Observation] = {}
    for mode, backend in (layers or LAYERS):
        if backend is None:
            out[mode] = run_eager(program, ctx, seed)
            continue
        if not layer_available(mode):
            out[mode] = Observation(mode=mode, ok=False, exception="LayerUnavailable",
                                    exception_msg="requires CUDA + Triton", infra_error=True)
            continue
        comp = (compilers or {}).get(mode) or TorchCompiler(backend)
        try:
            obs = run_cold(program, ctx, comp, disk_cache=disk_cache, seed=seed, mode=mode)
        except Exception as e:  # backend unavailable, OOM, ...
            msg = str(e)[:400]
            obs = Observation(mode=mode, ok=False, exception=type(e).__name__, exception_msg=msg,
                              infra_error=is_infra_failure(type(e).__name__, msg))
        out[mode] = obs
    return out


# --------------------------------------------------------------------------
# the execution matrix of section 14
# --------------------------------------------------------------------------

@dataclass
class Matrix:
    """``E1, C1, E2, C2cold, C2warm`` (+ the return trip ``C1'``)."""
    ctx_a: Context
    ctx_b: Context
    E1: Observation
    C1: Observation
    E2: Observation
    C2cold: Observation
    C2warm: Observation
    fp64_b: Optional[Observation] = None
    recompiled_on_switch: Optional[bool] = None
    C1_return: Optional[Observation] = None
    recompiled_on_return: Optional[bool] = None
    compile_count: int = 0
    wall_s: float = 0.0

    def as_dict(self) -> Dict[str, Any]:
        return {
            "ctx_a": self.ctx_a.as_dict(), "ctx_b": self.ctx_b.as_dict(),
            "E1": self.E1.summary(), "C1": self.C1.summary(), "E2": self.E2.summary(),
            "C2cold": self.C2cold.summary(), "C2warm": self.C2warm.summary(),
            "C1_return": self.C1_return.summary() if self.C1_return else None,
            "recompiled_on_switch": self.recompiled_on_switch,
            "recompiled_on_return": self.recompiled_on_return,
            "fp64_available": self.fp64_b is not None,
            "compile_count": self.compile_count, "wall_s": round(self.wall_s, 3),
        }


def execution_matrix(program: Program, ctx_a: Context, ctx_b: Context, compiler: Compiler,
                     disk_cache: bool = False, seed: int = 0, return_trip: bool = True) -> Matrix:
    t0 = time.perf_counter()
    E1 = run_eager(program, ctx_a, seed)
    C1 = run_cold(program, ctx_a, compiler, disk_cache, seed, mode="C1_cold")
    E2 = run_eager(program, ctx_b, seed)
    C2cold = run_cold(program, ctx_b, compiler, disk_cache, seed, mode="C2_cold")
    fp64_b = run_fp64(program, ctx_b, seed)
    seq = [ctx_a, ctx_b] + ([ctx_a] if return_trip else [])
    steps = run_sequence(program, seq, compiler, disk_cache, seed)
    if len(steps) >= 2:
        C2warm = steps[1]
        C2warm.mode = "C2_warm(A->B)"
        rec = C2warm.compiles > 0
    else:
        C2warm = Observation(mode="C2_warm(A->B)", ok=False, exception="WarmupFailed",
                             exception_msg=f"context A raised {steps[0].exception if steps else '?'}",
                             infra_error=True)
        rec = None
    m = Matrix(ctx_a, ctx_b, E1, C1, E2, C2cold, C2warm, fp64_b, rec)
    if return_trip and len(steps) >= 3:
        m.C1_return = steps[2]
        m.C1_return.mode = "C1_return(A->B->A)"
        m.recompiled_on_return = steps[2].compiles > 0
    m.compile_count = sum(o.compiles for o in (C1, C2cold)) + sum(o.compiles for o in steps)
    m.wall_s = time.perf_counter() - t0
    return m
