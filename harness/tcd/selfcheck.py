"""Prove the harness works before trusting anything it says.

Run this first on any new machine. It validates each mechanism the results
depend on, using situations whose answer we already know:

* a **deliberately wrong backend** must make the value oracle fire — if it does
  not, the harness cannot detect a real miscompilation either;
* a **clean run** must produce no findings — otherwise every night's output is
  noise;
* the **compile counter** must read 1 on a cold call and 0 on a repeat — this
  is the exact mechanism the whole cold/warm judgement rests on.

A harness that has not passed this is not evidence.
"""
from __future__ import annotations

from typing import Any, Callable, List, Optional, Tuple

from .case import Case, Context
from .execution import _invoke, build_inputs, run_cold, run_eager, run_fp64_reference
from .oracle import ALIAS, Config, GRADIENT, MUTATION, VALUE, compare
from .snapshot import Observation, alias_relation
from .torchcompat import (
    CompileCounter,
    HAVE_TORCH,
    compile_fn,
    dynamo_reset,
    environment,
    lookup_backend,
    register_local_backend,
    seed_everything,
    torch,
)
from .triage import DedupStore, signature

#: ``ok`` is True (pass), False (the harness is wrong) or None (skipped -
#: something this machine cannot provide, which is not a harness fault).
Check = Tuple[str, Optional[bool], str]


# --------------------------------------------------------------------------
# a deliberately incorrect backend
# --------------------------------------------------------------------------

def _perturb(out: Any) -> Any:
    if torch is not None and isinstance(out, torch.Tensor) and out.is_floating_point():
        return out + 1.0
    if isinstance(out, (list, tuple)):
        conv = [_perturb(v) for v in out]
        return type(out)(conv) if isinstance(out, tuple) else conv
    return out


def poison_backend(gm, example_inputs):
    """A backend that compiles correctly and then returns a wrong answer."""
    forward = gm.forward

    def wrapped(*args, **kwargs):
        return _perturb(forward(*args, **kwargs))

    return wrapped


def identity_backend(gm, example_inputs):
    return gm.forward


def _map_tensors(out: Any, f: Callable[[Any], Any]) -> Any:
    if torch is not None and isinstance(out, torch.Tensor):
        return f(out)
    if isinstance(out, (list, tuple)):
        conv = [_map_tensors(v, f) for v in out]
        return type(out)(conv) if isinstance(out, tuple) else conv
    return out


def poison_grad_backend(gm, example_inputs):
    """Correct forward, backward scaled by two - only O6 can see this."""
    class _DoubleGrad(torch.autograd.Function):
        @staticmethod
        def forward(ctx, x):
            return x.clone()

        @staticmethod
        def backward(ctx, g):
            return g * 2.0

    forward = gm.forward

    def wrapped(*args, **kwargs):
        return _map_tensors(forward(*args, **kwargs),
                            lambda t: _DoubleGrad.apply(t) if t.requires_grad else t)
    return wrapped


def detach_outputs_backend(gm, example_inputs):
    """Correct values whose outputs no longer require grad: training silently stops."""
    forward = gm.forward

    def wrapped(*args, **kwargs):
        return _map_tensors(forward(*args, **kwargs), lambda t: t.detach())
    return wrapped


# Expose them as ordinary backend names so the *whole* pipeline - runner,
# triage, dedup, record and issue draft - can be exercised end to end on any
# machine:
#
#     python run.py run --backend poison     # must produce records
#     python run.py run --backend identity   # must produce none
#
# A run that reports zero candidates is only meaningful if you have checked
# that a run which *should* report some actually does.
register_local_backend("poison", poison_backend)
register_local_backend("identity", identity_backend)
register_local_backend("poison_grad", poison_grad_backend)
register_local_backend("detach_outputs", detach_outputs_backend)


# --------------------------------------------------------------------------
# the fixture under test
# --------------------------------------------------------------------------

def _fixture_fn(x):
    return (x * 2.0 + 1.0).sum(dim=-1)


def _fixture_inputs(ctx: Context):
    dt = {"float32": torch.float32, "float16": torch.float16}[ctx.get("dtype", "float32")]
    dev = "cuda" if (torch is not None and torch.cuda.is_available()) else "cpu"
    return (torch.randn(16, 32, dtype=dt, device=dev),)


def _fixture_case() -> Case:
    return Case(
        name="_selfcheck_fixture",
        fn=_fixture_fn,
        make_inputs=_fixture_inputs,
        contexts=[Context("fp32", {"dtype": "float32"}), Context("fp16", {"dtype": "float16"})],
        tags=["selfcheck"],
    )


# --------------------------------------------------------------------------
# checks
# --------------------------------------------------------------------------

def _check_offline() -> List[Check]:
    """Checks that need no torch at all."""
    out: List[Check] = []

    s1 = signature("case", "inductor_codegen", ["value"], "dtype")
    s2 = signature("case", "inductor_codegen", ["value"], "dtype")
    s3 = signature("case", "inductor_codegen", ["value"], "shape")
    out.append(("signature is deterministic", s1 == s2, f"{s1} == {s2}"))
    out.append(("signature separates factors", s1 != s3, f"{s1} != {s3}"))

    store = DedupStore(path="")
    first = store.add("aaa", {"case": "x"})
    second = store.add("aaa", {"case": "x"})
    out.append(
        ("dedup suppresses repeats", first and not second,
         f"first={first} second={second} count={store.entries['aaa']['count']}")
    )

    ctx_a = Context("a", {"dtype": "fp32", "rows": 32})
    ctx_b = Context("b", {"dtype": "fp16", "rows": 32})
    diff = ctx_a.differing_factors(ctx_b)
    out.append(("single-factor diff detected", diff == ["dtype"], str(diff)))
    return out


def _check_torch() -> List[Check]:
    out: List[Check] = []
    if not HAVE_TORCH:
        return [("torch importable", False, "PyTorch is not installed in this interpreter")]

    env = environment()
    out.append(("torch importable", True, f"torch {env['torch']}, cuda {env['cuda']}"))

    # backends resolvable
    for name in ("eager", "aot_eager", "inductor"):
        try:
            lookup_backend(name)
            out.append((f"backend '{name}' resolvable", True, "ok"))
        except Exception as e:
            out.append((f"backend '{name}' resolvable", False, str(e)[:160]))

    case = _fixture_case()
    ctx = case.contexts[0]
    ctx2 = case.contexts[1]
    seed_everything(0)

    # --- the compile counter: the mechanism D2 depends on ---
    try:
        counter = CompileCounter("eager")
        dynamo_reset()
        fn = compile_fn(case.fn, counter)
        o1 = _invoke(fn, build_inputs(case, ctx, 0), "cold", counter)
        cold_n = o1.compiles
        o2 = _invoke(fn, build_inputs(case, ctx, 0), "repeat", counter)
        repeat_n = o2.compiles
        o3 = _invoke(fn, build_inputs(case, ctx2, 0), "switched", counter)
        switch_n = o3.compiles
        dynamo_reset()

        out.append(
            ("compile counter: cold compiles once", cold_n == 1, f"compiles={cold_n}")
        )
        out.append(
            ("compile counter: repeat is a cache hit", repeat_n == 0, f"compiles={repeat_n}")
        )
        out.append(
            ("compile counter: dtype switch recompiles", switch_n >= 1,
             f"compiles={switch_n}"
             + ("" if switch_n >= 1 else "  <-- no recompile on a dtype change; "
                                          "not a harness fault, but investigate"))
        )
    except Exception as e:
        out.append(("compile counter", False, f"{type(e).__name__}: {str(e)[:160]}"))

    cfg = Config()

    # --- the value oracle must fire on a deliberately wrong backend ---
    try:
        seed_everything(0)
        ref = run_eager(case, ctx)
        fp64 = run_fp64_reference(case, ctx)
        dynamo_reset()
        bad = compile_fn(case.fn, poison_backend)
        got = _invoke(bad, build_inputs(case, ctx, 0), "poisoned", None)
        dynamo_reset()
        cmp = compare(ref, got, fp64, cfg)
        fired = cmp.differs and VALUE in cmp.kinds
        detail = "; ".join(f.detail for f in cmp.findings)[:200] or "no findings"
        out.append(("value oracle fires on a wrong backend", fired, detail))
    except Exception as e:
        out.append(("value oracle fires on a wrong backend", False,
                    f"{type(e).__name__}: {str(e)[:160]}"))

    # --- and must NOT fire on a correct one ---
    try:
        seed_everything(0)
        ref = run_eager(case, ctx)
        fp64 = run_fp64_reference(case, ctx)
        dynamo_reset()
        good = compile_fn(case.fn, identity_backend)
        got = _invoke(good, build_inputs(case, ctx, 0), "identity", None)
        dynamo_reset()
        cmp = compare(ref, got, fp64, cfg)
        detail = "; ".join(f.detail for f in cmp.findings)[:200] or "clean"
        out.append(("no false positive on a correct backend", not cmp.differs, detail))
    except Exception as e:
        out.append(("no false positive on a correct backend", False,
                    f"{type(e).__name__}: {str(e)[:160]}"))

    # --- fp64 reference is constructible ---
    try:
        fp64 = run_fp64_reference(case, ctx)
        out.append(("fp64 reference builds", fp64 is not None,
                    "built" if fp64 is not None else
                    "unavailable - numeric findings will use the fallback tolerance"))
    except Exception as e:
        out.append(("fp64 reference builds", False, str(e)[:160]))

    # --- alias relation is comparable and pointer-independent ---
    try:
        x = torch.randn(8)
        v = x.view(-1)
        y = torch.randn(8)
        rel_shared = alias_relation([x, v, y])
        rel_none = alias_relation([x.clone(), y.clone()])
        ok = ((0, 1) in rel_shared) and (len(rel_none) == 0)
        out.append(("alias relation detects storage sharing", ok,
                    f"shared={sorted(rel_shared)} independent={sorted(rel_none)}"))

        a = Observation(mode="a", n_inputs=1, alias=rel_shared)
        b = Observation(mode="b", n_inputs=1, alias=frozenset())
        cmp = compare(a, b, None, cfg)
        out.append(("alias oracle fires on a relation change",
                    ALIAS in cmp.kinds, "; ".join(f.detail for f in cmp.findings)[:200]))
    except Exception as e:
        out.append(("alias relation", False, f"{type(e).__name__}: {str(e)[:160]}"))

    # --- O6 gradient oracle: fires on wrong backward, not on a right one ---
    def _grad_input():
        seed_everything(0)
        return (torch.randn(16, 32, requires_grad=True),)

    try:
        ref = _invoke(case.fn, _grad_input(), "eager_grad", None)
        out.append(("O6 eager run produces gradients", ref.grads is not None,
                    f"grads={len(ref.grads) if ref.grads else None} err={ref.grad_error}"))

        dynamo_reset()
        got = _invoke(compile_fn(case.fn, poison_grad_backend), _grad_input(), "poison_grad", None)
        dynamo_reset()
        cmp = compare(ref, got, None, cfg)
        detail = "; ".join(f.detail for f in cmp.findings)[:200] or "no findings"
        out.append(("O6 gradient oracle fires on a backend that doubles backward",
                    GRADIENT in cmp.kinds and VALUE not in cmp.kinds, detail))

        dynamo_reset()
        got = _invoke(compile_fn(case.fn, detach_outputs_backend), _grad_input(), "detached", None)
        dynamo_reset()
        cmp = compare(ref, got, None, cfg)
        detail = "; ".join(f.detail for f in cmp.findings)[:200] or "no findings"
        out.append(("O6 fires when compiled outputs stop requiring grad",
                    GRADIENT in cmp.kinds, detail))

        dynamo_reset()
        got = _invoke(compile_fn(case.fn, "aot_eager"), _grad_input(), "aot_grad", None)
        dynamo_reset()
        cmp = compare(ref, got, None, cfg)
        detail = "; ".join(f.detail for f in cmp.findings)[:200] or "clean"
        out.append(("O6 no false positive on aot_eager",
                    got.grads is not None and GRADIENT not in cmp.kinds, detail))
    except Exception as e:
        out.append(("O6 gradient oracle", False, f"{type(e).__name__}: {str(e)[:160]}"))

    # --- O4 mutation oracle: fires when an in-place write is dropped ---
    try:
        from .experiments import drop_mutation_backend

        def _mut(x):
            x.mul_(0.5)
            return x.sum()

        seed_everything(0)
        base = torch.randn(8)
        ref = _invoke(_mut, (base.clone(),), "eager_mut", None)
        dynamo_reset()
        got = _invoke(compile_fn(_mut, drop_mutation_backend), (base.clone(),), "dropped", None)
        dynamo_reset()
        cmp = compare(ref, got, None, cfg)
        detail = "; ".join(f.detail for f in cmp.findings)[:200] or "no findings"
        out.append(("O4 mutation oracle fires on a dropped in-place write",
                    MUTATION in cmp.kinds and VALUE not in cmp.kinds, detail))
    except Exception as e:
        out.append(("O4 mutation oracle", False, f"{type(e).__name__}: {str(e)[:160]}"))

    # --- a real cold inductor compile actually runs ---
    # Inductor's CPU backend generates C++ and needs a host compiler (cl.exe on
    # Windows, g++ elsewhere). Its absence is an environment gap, not a harness
    # fault: E0/E1/E2 still work, and E2 (aot_eager) is where functionalization
    # lives - the alias/mutation layer this project cares about most.
    try:
        seed_everything(0)
        obs = run_cold(case, ctx, backend="inductor")
        if obs.ok:
            out.append(("inductor cold run executes", True,
                        f"compiles={obs.compiles} {obs.wall_s:.2f}s"))
        else:
            msg = obs.exception_msg or ""
            skip = _looks_like_missing_compiler(msg)
            out.append(("inductor cold run executes", None if skip else False,
                        _compiler_hint(msg) if skip else msg[:160]))
    except Exception as e:
        msg = f"{type(e).__name__}: {e}"
        skip = _looks_like_missing_compiler(msg)
        out.append(("inductor cold run executes", None if skip else False,
                    _compiler_hint(msg) if skip else msg[:160]))

    return out


_COMPILER_MARKERS = (
    "InvalidCxxCompiler", "is not found", "Compiler: cl", "cl is not found",
    "no such file or directory: 'g++'", "CppCompileError", "MSVC",
)


def _looks_like_missing_compiler(msg: str) -> bool:
    return any(m.lower() in (msg or "").lower() for m in _COMPILER_MARKERS)


def _compiler_hint(msg: str) -> str:
    return ("SKIP - no host C++ compiler, so Inductor (E3) cannot codegen. "
            "E0/E1/E2 are unaffected; run with --backend aot_eager. "
            "Install MSVC Build Tools (Windows) or g++ to enable E3.")


def run_selfcheck(include_torch: bool = True) -> List[Check]:
    checks = _check_offline()
    if include_torch:
        checks += _check_torch()
    return checks


def failed(checks: List[Check]) -> List[str]:
    """Names of checks that genuinely failed (skips do not count)."""
    return [n for n, ok, _ in checks if ok is False]


def format_checks(checks: List[Check]) -> str:
    width = max((len(n) for n, _, _ in checks), default=10)
    lines = []
    for name, ok, detail in checks:
        mark = "PASS" if ok else ("SKIP" if ok is None else "FAIL")
        lines.append(f"  [{mark}] {name.ljust(width)}  {detail}")

    n_fail = len(failed(checks))
    n_skip = sum(1 for _, ok, _ in checks if ok is None)
    n_pass = len(checks) - n_fail - n_skip
    lines.append("")
    tail = f", {n_skip} skipped" if n_skip else ""
    lines.append(f"  {n_pass}/{len(checks)} checks passed{tail}")
    if n_fail:
        lines.append("  Harness output is NOT trustworthy until these pass.")
    elif n_skip:
        lines.append("  All applicable checks passed. Skipped items limit coverage, "
                     "not correctness.")
    return "\n".join(lines)
