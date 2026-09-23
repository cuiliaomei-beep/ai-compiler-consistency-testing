"""Execution modes: eager, fp64 reference, cold compile, warm cache, layered.

Two things here are easy to get wrong and both are load-bearing.

**1. There are two cache layers, not one.** ``torch._dynamo.reset()`` clears
the *in-process* caches. It does **not** clear the on-disk FX-graph / Inductor
/ Triton caches, which survive the reset and even the process. A "cold" run
that silently hits the disk cache is not cold, and the whole cold-vs-warm
judgement (D2) is then meaningless. :func:`cache_scope` makes the choice
explicit.

**2. Compilation must be counted, not guessed.** Changing dtype usually makes
a guard fail and triggers a *recompile* — which is correct behaviour, not a
bug. The interesting event is a context switch that produced **no** recompile
yet changed semantics. We count real backend invocations, so that filter is
exact.
"""
from __future__ import annotations

import contextlib
import os
import time
from typing import Any, Dict, List, Optional, Tuple

from .case import Case, Context
from .snapshot import Observation, observe
from .torchcompat import (
    CompileCounter,
    compile_fn,
    counters_snapshot,
    dynamo_reset,
    frames_total,
    is_infra_failure,
    seed_everything,
    sync,
    torch,
)

# Layered backends, in the order the plan bisects them.
E0_EAGER = "E0_eager"
E1_DYNAMO = "E1_dynamo_eager"
E2_AOT = "E2_aot_eager"
E3_INDUCTOR = "E3_inductor"

LAYERS: List[Tuple[str, Optional[str]]] = [
    (E0_EAGER, None),
    (E1_DYNAMO, "eager"),
    (E2_AOT, "aot_eager"),
    (E3_INDUCTOR, "inductor"),
]


@contextlib.contextmanager
def cache_scope(disk_cache: bool):
    """Enable or disable the *on-disk* compilation caches for this block.

    Pass ``False`` for a genuinely cold compile. Pass ``True`` to probe
    cross-process cache reuse, which no existing tool tests.
    """
    env_keys = ("TORCHINDUCTOR_FX_GRAPH_CACHE", "TORCHINDUCTOR_AUTOGRAD_CACHE")
    saved_env = {k: os.environ.get(k) for k in env_keys}
    saved_cfg: Dict[str, Any] = {}
    cfg = None
    try:
        cfg = torch._inductor.config if torch is not None else None
    except Exception:
        cfg = None

    for k in env_keys:
        os.environ[k] = "1" if disk_cache else "0"
    if cfg is not None:
        for attr in ("fx_graph_cache", "autograd_cache"):
            if hasattr(cfg, attr):
                saved_cfg[attr] = getattr(cfg, attr)
                try:
                    setattr(cfg, attr, bool(disk_cache))
                except Exception:
                    saved_cfg.pop(attr, None)
    try:
        yield
    finally:
        for k, v in saved_env.items():
            if v is None:
                os.environ.pop(k, None)
            else:
                os.environ[k] = v
        if cfg is not None:
            for attr, v in saved_cfg.items():
                try:
                    setattr(cfg, attr, v)
                except Exception:
                    pass


def build_inputs(case: Case, ctx: Context, seed: int = 0):
    """Build inputs for a context **deterministically**.

    Every oracle in this harness compares two executions of the same context,
    so those executions must receive bit-identical inputs. ``make_inputs``
    typically calls ``torch.randn``, which means calling it twice yields
    different tensors — and then the value and mutation oracles are comparing
    unrelated data and fire on every single case.

    Seeding immediately before each build is what makes the comparison valid.
    (The harness self-check exists to catch exactly this class of mistake: it
    was caught here.)
    """
    seed_everything(seed)
    return case.make_inputs(ctx)


def _run(case: Case, ctx: Context, fn, mode: str,
         counter: Optional[CompileCounter], seed: int = 0) -> Observation:
    """Deterministic build + deterministic call."""
    inputs = build_inputs(case, ctx, seed)
    seed_everything(seed)  # again, so in-function randomness matches too
    params = None
    if case.parameters is not None:
        try:
            params = list(case.parameters())
        except Exception:
            params = None
    return _invoke(fn, inputs, mode, counter, params=params)


def _leaves(inputs: Any, params: Optional[List[Any]]) -> List[Any]:
    """Tensors a backward pass can produce gradients for."""
    from .snapshot import flatten
    out = [t for t in flatten(inputs)[0]
           if isinstance(t, torch.Tensor) and t.requires_grad and t.is_leaf]
    for p in params or []:
        if isinstance(p, torch.Tensor) and p.requires_grad:
            out.append(p)
    return out


def _backward(inputs: Any, out: Any, params: Optional[List[Any]]
              ) -> Tuple[Optional[List[Any]], Optional[str]]:
    """O6: gradients of a scalar over every differentiable leaf.

    Uses ``torch.autograd.grad`` rather than ``.backward()`` so nothing
    accumulates into ``.grad`` between executions - the eager and compiled runs
    share module parameters, and accumulated gradients would make the second
    run's gradient look wrong by exactly the first run's amount.

    Returns ``(grads, None)`` on success, ``(None, None)`` when there is nothing
    to differentiate, and ``(None, reason)`` when backward was attempted and
    failed - the last case is itself an observation: a compiled function whose
    outputs no longer require grad cannot be trained.
    """
    if torch is None:
        return None, None
    from .snapshot import flatten
    leaves = _leaves(inputs, params)
    if not leaves:
        return None, None
    outs = [o for o in flatten(out)[0]
            if isinstance(o, torch.Tensor) and o.is_floating_point()]
    if not outs:
        return None, None
    live = [o for o in outs if o.requires_grad]
    if not live:
        return None, "no output requires grad although an input does"
    try:
        # cast to float64 before summing so float16 outputs do not overflow
        # the loss; the gradient flowing back is cast to the leaf's dtype
        loss = sum(o.to(torch.float64).sum() for o in live)
        grads = torch.autograd.grad(loss, leaves, allow_unused=True,
                                    retain_graph=False)
        return [g.detach().clone() if g is not None else None for g in grads], None
    except Exception as e:  # noqa: BLE001
        return None, f"{type(e).__name__}: {str(e)[:200]}"


def _invoke(fn, inputs, mode: str, counter: Optional[CompileCounter],
            params: Optional[List[Any]] = None) -> Observation:
    """Call ``fn(*inputs)`` and turn the result into an Observation."""
    before = counters_snapshot()
    if counter is not None:
        counter.reset()
    exc: Optional[BaseException] = None
    out: Any = None
    t0 = time.perf_counter()
    try:
        out = fn(*inputs)
        sync()
    except Exception as e:  # noqa: BLE001 - an exception IS an observation
        exc = e
    wall = time.perf_counter() - t0

    grads, grad_error = (None, None) if exc is not None else _backward(inputs, out, params)

    obs = observe(mode, inputs, out, exc)
    obs.grads = grads
    obs.grad_error = grad_error
    obs.infra_error = (not obs.ok) and is_infra_failure(obs.exception, obs.exception_msg)
    obs.compiles = counter.count if counter is not None else 0
    obs.frames_delta = frames_total(counters_snapshot()) - frames_total(before)
    obs.wall_s = wall
    return obs


def run_eager(case: Case, ctx: Context, seed: int = 0) -> Observation:
    return _run(case, ctx, case.fn, E0_EAGER, None, seed)


# --------------------------------------------------------------------------
# fp64 reference
# --------------------------------------------------------------------------

def _to_fp64(obj: Any) -> Any:
    if torch is None:
        return obj
    if isinstance(obj, torch.Tensor):
        if obj.is_floating_point():
            t = obj.detach().to(torch.float64)
            t.requires_grad_(obj.requires_grad)
            return t
        return obj.detach().clone()
    if isinstance(obj, (list, tuple)):
        conv = [_to_fp64(v) for v in obj]
        return type(obj)(conv) if isinstance(obj, tuple) else conv
    if isinstance(obj, dict):
        return {k: _to_fp64(v) for k, v in obj.items()}
    return obj


def run_fp64_reference(case: Case, ctx: Context, seed: int = 0) -> Optional[Observation]:
    """Eager execution with float inputs promoted to float64.

    Built from the *same seed* as every other execution of this context, so the
    reference describes the same problem the others solved.

    Returns ``None`` when it cannot be built (no float64 kernel on the device,
    dtype-sensitive control flow, ...). Callers then fall back to a plain
    tolerance, and the report says so.
    """
    if case.skip_fp64 or torch is None:
        return None
    try:
        inputs = _to_fp64(build_inputs(case, ctx, seed))
    except Exception:
        return None
    seed_everything(seed)
    params = None
    if case.parameters is not None:
        try:
            params = list(case.parameters())
        except Exception:
            params = None
    obs = _invoke(case.fn, inputs, "fp64_ref", None, params=params)
    return obs if obs.ok else None


# --------------------------------------------------------------------------
# compiled execution
# --------------------------------------------------------------------------

def run_cold(case: Case, ctx: Context, backend: str = "inductor",
             disk_cache: bool = False, seed: int = 0) -> Observation:
    """Fresh compile: reset in-process caches, and by default bypass disk."""
    counter = CompileCounter(backend)
    dynamo_reset()
    with cache_scope(disk_cache):
        fn = compile_fn(case.fn, counter)
        obs = _run(case, ctx, fn, f"cold_{backend}", counter, seed)
    dynamo_reset()
    return obs


def run_warm_pair(
    case: Case,
    ctx_a: Context,
    ctx_b: Context,
    backend: str = "inductor",
    disk_cache: bool = False,
    seed: int = 0,
) -> Tuple[Observation, bool]:
    """Compile under A, then execute under B **without** resetting.

    Returns ``(observation_for_B, recompiled)``. ``recompiled=True`` means a
    guard correctly rejected the cached artifact and a fresh compile happened
    — normal behaviour, and the case where a divergence is *not* evidence of a
    specialization bug. The interesting rows are ``recompiled=False``.
    """
    counter = CompileCounter(backend)
    dynamo_reset()
    with cache_scope(disk_cache):
        fn = compile_fn(case.fn, counter)
        warm_up = _run(case, ctx_a, fn, f"warmup_{backend}", counter, seed)
        if not warm_up.ok:
            # Context A could not run at all, so there is no warm cache to
            # probe. This says nothing about the compiler - marking it as an
            # infrastructure failure keeps it out of the candidate pool, the
            # same way a missing compiler is kept out.
            dynamo_reset()
            obs = Observation(mode=f"warm_{backend}", ok=False,
                              exception="WarmupFailed",
                              exception_msg=f"context A raised {warm_up.exception}",
                              infra_error=True)
            return obs, False
        obs = _run(case, ctx_b, fn, f"warm_{backend}", counter, seed)
    dynamo_reset()
    return obs, obs.compiles > 0


def run_return_trip(
    case: Case,
    ctx_a: Context,
    ctx_b: Context,
    backend: str = "inductor",
    disk_cache: bool = False,
    seed: int = 0,
) -> Tuple[Observation, Observation, bool]:
    """Plan section 15: the ``A -> B -> A`` sequence.

    Two-step switches catch an artifact compiled for A being reused under B.
    The return trip catches the other half: whether coming *back* to A still
    yields A's answer, or whether the cache has been left holding B's
    specialisation under A's guard. That is incorrect cache invalidation
    rather than under-specialisation, and a two-step probe cannot see it.

    Returns ``(first_A, second_A, recompiled_on_return)``.
    """
    counter = CompileCounter(backend)
    dynamo_reset()
    with cache_scope(disk_cache):
        fn = compile_fn(case.fn, counter)
        first = _run(case, ctx_a, fn, f"tripA1_{backend}", counter, seed)
        if not first.ok:
            dynamo_reset()
            return first, first, False
        _run(case, ctx_b, fn, f"tripB_{backend}", counter, seed)
        second = _run(case, ctx_a, fn, f"tripA2_{backend}", counter, seed)
    dynamo_reset()
    return first, second, second.compiles > 0


def run_layered(case: Case, ctx: Context, disk_cache: bool = False,
                seed: int = 0,
                layers: Optional[List[Tuple[str, Optional[str]]]] = None,
                ) -> Dict[str, Observation]:
    """Run E0..E3 so a divergence can be attributed to a compiler stage.

    This is not only localization. It is the harness's cheapest triage filter:
    a divergence already present at ``backend="eager"`` is Dynamo capture
    semantics and is usually documented-unsupported, while one that appears
    only at Inductor is the kind maintainers accept.
    """
    out: Dict[str, Observation] = {}
    for mode, backend in (layers or LAYERS):
        if backend is None:
            out[mode] = run_eager(case, ctx, seed)
            continue
        try:
            out[mode] = run_cold(case, ctx, backend=backend,
                                 disk_cache=disk_cache, seed=seed)
            out[mode].mode = mode
        except Exception as e:  # a backend may be unavailable (no GPU, no triton)
            msg = str(e)[:400]
            obs = Observation(mode=mode, ok=False, exception=type(e).__name__,
                              exception_msg=msg,
                              infra_error=is_infra_failure(type(e).__name__, msg))
            out[mode] = obs
    return out
