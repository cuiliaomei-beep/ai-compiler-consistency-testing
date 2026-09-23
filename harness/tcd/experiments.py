"""Plan section 26: the five key experiments.

Each is a small, targeted measurement with a program chosen to isolate one
claim of the plan. They are not bug-finding runs; they show that the
mechanism does what the plan says it does, on inputs whose answer is known.

    A  shape boundary      does x.shape[0] >= k get k-1 / k / k+1 tested, and how fast
    B  dtype specialization float16 -> float32 with everything else fixed: cold vs warm
    C  control flow        `flag and x.shape[0] > 32`: are all four T/T T/F F/T F/F reached
    D  alias / mutation    what an output-only oracle misses that O4/O5 catch
    E  cache context switch  A -> B  versus  reset -> B

Baselines inside an experiment are only ones that can actually be run here:
"Random" is the uniform strategy; NNSmith generates *programs*, so it cannot
be asked to produce inputs for a given program and is reported as
not-applicable in A and C rather than approximated.
"""
from __future__ import annotations

import random
import time
from dataclasses import dataclass, field
from typing import Any, Callable, Dict, List, Optional, Sequence, Tuple

from .case import Case, Context
from .torchcompat import register_local_backend, torch


@dataclass
class ExperimentResult:
    name: str
    title: str
    rows: List[Dict[str, Any]] = field(default_factory=list)
    notes: List[str] = field(default_factory=list)
    seconds: float = 0.0

    def as_dict(self) -> Dict[str, Any]:
        return {"name": self.name, "title": self.title, "rows": self.rows,
                "notes": self.notes, "seconds": round(self.seconds, 1)}


def _mk_case(name: str, src: str, base_args: Callable[[], Tuple[Any, ...]],
             contexts: List[Context]) -> Case:
    from .seeds import _apply_context
    ns: Dict[str, Any] = {"torch": torch}
    exec(compile(src, f"<exp:{name}>", "exec"), ns)

    def make_inputs(ctx: Context) -> Tuple[Any, ...]:
        from .torchcompat import seed_everything
        seed_everything(0)
        return _apply_context(base_args(), ctx)

    return Case(name=name, fn=ns["f"], make_inputs=make_inputs, contexts=contexts,
                tags=["experiment"], source=src)


# --------------------------------------------------------------------------
# A. shape boundary
# --------------------------------------------------------------------------

def _tests_to_cover(draw: Callable[[random.Random], int], targets: set,
                    rng: random.Random, cap: int = 10_000) -> int:
    hit: set = set()
    n = 0
    while hit != targets and n < cap:
        n += 1
        v = draw(rng)
        if v in targets:
            hit.add(v)
    return n if hit == targets else cap


def experiment_a(backend: str = "aot_eager", ks: Sequence[int] = (8, 16, 32, 64),
                 trials: int = 20, seed: int = 0) -> ExperimentResult:
    from .ablation import _count_specializations
    from .obligation import contexts_for_source

    t0 = time.perf_counter()
    res = ExperimentResult("A", "Shape boundary: x.shape[0] >= k -> k-1 / k / k+1")
    for k in ks:
        src = (f"def f(x):\n    if x.shape[0] >= {k}:\n        return x * 2.0\n"
               f"    return x + 1.0\n")
        targets = {k - 1, k, k + 1}
        ours_ctx, _scs, obl = contexts_for_source(src)
        ours_sizes = [c.get("resize", {}).get("value") for c in ours_ctx
                      if isinstance(c.get("resize"), dict)]
        ours_hit = set(ours_sizes) & targets
        ours_n = len(ours_ctx)

        rng = random.Random(seed)
        # fair random: uniform over a range that contains the boundary and is
        # no larger than twice the constant - a generous prior for a strategy
        # that has not read the program
        rand_n = [_tests_to_cover(lambda r: r.randint(1, 2 * k), targets, rng)
                  for _ in range(trials)]
        rand_mean = sum(rand_n) / len(rand_n)

        # verify each hit value really reaches its own specialisation
        specz = None
        if torch is not None:
            case = _mk_case(f"expA_{k}", src, lambda _k=k: (torch.randn(_k, 4),), ours_ctx)
            try:
                specz = _count_specializations(case, ours_ctx, backend, seed)
            except Exception as e:  # noqa: BLE001
                res.notes.append(f"k={k}: specialization count failed: {type(e).__name__}")
        res.rows.append({
            "k": k, "targets": sorted(targets),
            "ours_tests": ours_n, "ours_covered": len(ours_hit),
            "random_tests_mean": round(rand_mean, 1),
            "random_tests_min": min(rand_n), "random_tests_max": max(rand_n),
            "speedup": round(rand_mean / max(ours_n, 1), 1),
            "specializations": specz,
        })
    res.notes.append("NNSmith: not applicable - it generates programs, not inputs for a "
                     "given program. TorchProbe: no runnable distribution obtained.")
    res.seconds = time.perf_counter() - t0
    return res


# --------------------------------------------------------------------------
# B. dtype specialization
# --------------------------------------------------------------------------

def experiment_b(backend: str = "aot_eager", seed: int = 0) -> ExperimentResult:
    from .execution import run_cold, run_eager, run_fp64_reference, run_warm_pair
    from .oracle import Config, compare
    from .triage import triage_warm

    t0 = time.perf_counter()
    res = ExperimentResult("B", "dtype specialization: float16 -> float32, shape/value/flag fixed")
    if torch is None:
        res.notes.append("torch unavailable")
        return res
    programs = {
        "affine_sum": "def f(x):\n    return (x * 1.5 + 0.5).sum(dim=-1)\n",
        "softmax": "def f(x):\n    return torch.softmax(x, dim=-1)\n",
        "layernorm": "def f(x):\n    return torch.nn.functional.layer_norm(x, x.shape[-1:])\n",
        "cumsum_exp": "def f(x):\n    return torch.exp(x).cumsum(dim=-1)\n",
    }
    a = Context("fp16", {"variant": "base", "dtype": "float16"})
    b = Context("fp32", {"variant": "base", "dtype": "float32"})
    cfg = Config()
    for name, src in programs.items():
        case = _mk_case(f"expB_{name}", src, lambda: (torch.randn(8, 16),), [a, b])
        row: Dict[str, Any] = {"program": name}
        try:
            eager_b = run_eager(case, b, seed)
            fp64_b = run_fp64_reference(case, b, seed)
            cold_b = run_cold(case, b, backend=backend, seed=seed)
            warm_b, recompiled = run_warm_pair(case, a, b, backend=backend, seed=seed)
            row["cold_vs_eager_kinds"] = compare(eager_b, cold_b, fp64_b, cfg).kinds
            tri, cmp = triage_warm(cold_b, warm_b, recompiled, "dtype", fp64_b, cfg)
            row["recompiled_on_switch"] = recompiled
            row["warm_vs_cold_kinds"] = cmp.kinds
            row["verdict"] = tri.stage
            row["priority"] = tri.priority
        except Exception as e:  # noqa: BLE001
            row["error"] = f"{type(e).__name__}: {str(e)[:100]}"
        res.rows.append(row)
    res.notes.append("expected: every switch recompiles (dtype is guarded) and warm == cold; "
                     "a row with recompiled=False and a non-empty kinds list is a "
                     "specialization defect")
    res.seconds = time.perf_counter() - t0
    return res


# --------------------------------------------------------------------------
# C. control flow
# --------------------------------------------------------------------------

def conjunction_contexts(src: str, max_contexts: int = 16) -> List[Context]:
    """Cross product over the factors a conjunction reads. Plan 26-C.

    ``obligations_to_contexts`` gives single-factor differences from base
    (section 12). A predicate ``flag and x.shape[0] > 32`` has four joint
    outcomes, and single-factor variation from one base reaches only three of
    them; the fourth needs both factors moved at once. This helper adds the
    joint contexts for exactly the factors that appear together in one
    predicate - a bounded product, not a random one.
    """
    import itertools

    from .analysis import analyze_source

    a = analyze_source(src)
    flags = {f.param: f.values for f in a.flags}
    bounds = {(b.param, b.dim): b.values for b in a.boundaries
              if b.kind == "shape" and b.param is not None and b.dim is not None}
    if not flags or not bounds:
        return []
    params = list(a.params)
    out: List[Context] = []
    for (fp, fvals), ((bp, bd), bvals) in itertools.product(flags.items(), bounds.items()):
        for fv, bv in itertools.product(fvals, bvals):
            out.append(Context(
                f"joint_{fp}={fv}_{bp}.d{bd}={bv}",
                {"variant": "base",
                 "substitute": {"arg": params.index(fp), "value": fv},
                 "resize": {"arg": params.index(bp), "dim": bd, "value": bv}}))
            if len(out) >= max_contexts:
                return out
    return out


def experiment_c(backend: str = "aot_eager", trials: int = 20, seed: int = 0,
                 k: int = 32) -> ExperimentResult:
    from .ablation import _count_specializations

    t0 = time.perf_counter()
    res = ExperimentResult("C", f"Control flow: flag and x.shape[0] > {k} -> T/T T/F F/T F/F")
    src = (f"def f(x, flag):\n    if flag and x.shape[0] > {k}:\n"
           f"        return x * 2.0\n    return x + 1.0\n")
    ours = conjunction_contexts(src)

    def outcome(flag: bool, n: int) -> Tuple[bool, bool]:
        return (bool(flag), n > k)

    ours_outcomes = set()
    for c in ours:
        fv = c.get("substitute", {}).get("value")
        nv = c.get("resize", {}).get("value")
        if fv is not None and nv is not None:
            ours_outcomes.add(outcome(fv, nv))
    all_four = {(True, True), (True, False), (False, True), (False, False)}

    rng = random.Random(seed)
    rand_n: List[int] = []
    for _ in range(trials):
        hit = set()
        n = 0
        while hit != all_four and n < 10_000:
            n += 1
            hit.add(outcome(rng.random() < 0.5, rng.randint(1, 2 * k)))
        rand_n.append(n)

    specz = None
    if torch is not None and ours:
        case = _mk_case("expC", src, lambda: (torch.randn(k + 1, 4), True), ours)
        try:
            specz = _count_specializations(case, ours, backend, seed)
        except Exception as e:  # noqa: BLE001
            res.notes.append(f"specialization count failed: {type(e).__name__}")
    res.rows.append({
        "ours_tests": len(ours), "ours_outcomes_covered": len(ours_outcomes),
        "ours_contexts": [c.name for c in ours],
        "random_tests_mean": round(sum(rand_n) / len(rand_n), 1),
        "random_tests_min": min(rand_n), "random_tests_max": max(rand_n),
        "specializations": specz,
    })
    res.notes.append("ours = flag values x shape boundary values for the factors that "
                     "share one predicate (bounded product); random = coin flip x "
                     f"uniform size in [1, {2 * k}]")
    res.seconds = time.perf_counter() - t0
    return res


# --------------------------------------------------------------------------
# D. alias / mutation oracle vs output-only
# --------------------------------------------------------------------------

def _clone_tree(obj: Any) -> Any:
    if torch is not None and isinstance(obj, torch.Tensor):
        return obj.detach().clone().requires_grad_(obj.requires_grad)
    if isinstance(obj, (list, tuple)):
        conv = [_clone_tree(v) for v in obj]
        return type(obj)(conv) if isinstance(obj, tuple) else conv
    return obj


def drop_mutation_backend(gm, example_inputs):
    """Correct outputs, but in-place writes never reach the caller.

    This is what an incorrect functionalization looks like from outside: the
    graph computes the right values on private copies and forgets to copy
    them back. An oracle that looks only at return values cannot see it.
    """
    forward = gm.forward

    def wrapped(*args, **kwargs):
        return forward(*[_clone_tree(a) for a in args], **kwargs)
    return wrapped


def copy_outputs_backend(gm, example_inputs):
    """Correct values, but every returned view becomes a fresh copy."""
    forward = gm.forward

    def wrapped(*args, **kwargs):
        return _clone_tree(forward(*args, **kwargs))
    return wrapped


register_local_backend("drop_mutation", drop_mutation_backend)
register_local_backend("copy_outputs", copy_outputs_backend)

_D_PROGRAMS: Dict[str, str] = {
    # in-place through a view; output does not depend on the write
    "view_write_hidden": ("def f(x):\n    v = x[:]\n    v.mul_(0.5)\n"
                          "    return x.shape[0] * 1.0\n"),
    # in-place through a view; output DOES depend on it (value oracle can see)
    "view_write_visible": ("def f(x):\n    v = x[:]\n    v.mul_(0.5)\n"
                           "    return x.sum()\n"),
    # partial write, output independent
    "partial_write": ("def f(x):\n    x[..., ::2].add_(1.0)\n"
                      "    return torch.ones(2)\n"),
    # returned alias of the input
    "returned_view": "def f(x):\n    return x.view(-1)\n",
    # returned alias plus a write ordering
    "write_then_view": ("def f(x):\n    x.add_(1.0)\n    y = x.transpose(0, 1)\n"
                        "    return y\n"),
    # no side effects at all - the control
    "pure": "def f(x):\n    return torch.relu(x) * 2.0\n",
}

_OUTPUT_ONLY = {"value", "exception", "metadata", "structure"}


def experiment_d(seed: int = 0, real_backend: str = "aot_eager") -> ExperimentResult:
    from .execution import run_cold, run_eager
    from .oracle import Config, compare

    t0 = time.perf_counter()
    res = ExperimentResult("D", "Alias / mutation: output-only oracle vs O4 mutation + O5 alias")
    if torch is None:
        res.notes.append("torch unavailable")
        return res
    base = Context("base", {"variant": "base"})
    cfg = Config()
    for name, src in _D_PROGRAMS.items():
        case = _mk_case(f"expD_{name}", src, lambda: (torch.randn(4, 6),), [base])
        row: Dict[str, Any] = {"program": name}
        try:
            eager = run_eager(case, base, seed)
            for be in ("drop_mutation", "copy_outputs", real_backend):
                obs = run_cold(case, base, backend=be, seed=seed)
                kinds = compare(eager, obs, None, cfg).kinds
                row[f"{be}:output_only"] = bool(set(kinds) & _OUTPUT_ONLY)
                row[f"{be}:full"] = bool(kinds)
                row[f"{be}:kinds"] = kinds
        except Exception as e:  # noqa: BLE001
            row["error"] = f"{type(e).__name__}: {str(e)[:100]}"
        res.rows.append(row)
    n = len(res.rows)
    for be in ("drop_mutation", "copy_outputs"):
        res.notes.append(
            f"{be}: output-only detects "
            f"{sum(1 for r in res.rows if r.get(f'{be}:output_only'))}/{n}, "
            f"full oracle detects {sum(1 for r in res.rows if r.get(f'{be}:full'))}/{n}")
    res.notes.append(f"{real_backend}: full oracle fires on "
                     f"{sum(1 for r in res.rows if r.get(f'{real_backend}:full'))}/{n} "
                     "(must be 0 - the false-positive control)")
    res.seconds = time.perf_counter() - t0
    return res


# --------------------------------------------------------------------------
# E. cache context switch
# --------------------------------------------------------------------------

def experiment_e(cases: Sequence[Case], backend: str = "aot_eager", seed: int = 0,
                 max_pairs_per_case: int = 6) -> ExperimentResult:
    from .execution import run_cold, run_warm_pair
    from .oracle import Config, compare
    from .runner import RunOptions, valid_contexts
    from .triage import triage_warm

    t0 = time.perf_counter()
    res = ExperimentResult("E", "Cache context switch: A -> B versus reset -> B")
    if torch is None:
        res.notes.append("torch unavailable")
        return res
    cfg = Config()
    opts = RunOptions(backend=backend, reruns=0, seed=seed)
    agree = disagree = recompiles = pairs = 0
    stages: Dict[str, int] = {}
    for case in cases:
        ctxs = valid_contexts(case, opts)
        sub = Case(name=case.name, fn=case.fn, make_inputs=case.make_inputs,
                   contexts=ctxs, source=case.source, parameters=case.parameters)
        for a, b in sub.context_pairs()[:max_pairs_per_case]:
            factor = ",".join(a.differing_factors(b))
            try:
                cold_b = run_cold(sub, b, backend=backend, seed=seed)
                warm_b, recompiled = run_warm_pair(sub, a, b, backend=backend, seed=seed)
            except Exception:
                continue
            if cold_b.infra_error or warm_b.infra_error:
                continue
            pairs += 1
            recompiles += int(recompiled)
            cmp = compare(cold_b, warm_b, None, cfg)
            if cmp.differs:
                disagree += 1
                tri, _ = triage_warm(cold_b, warm_b, recompiled, factor, None, cfg)
                stages[tri.stage] = stages.get(tri.stage, 0) + 1
                res.rows.append({"case": case.name, "A": a.name, "B": b.name,
                                 "factor": factor, "recompiled": recompiled,
                                 "kinds": cmp.kinds, "stage": tri.stage})
            else:
                agree += 1
    res.notes.append(f"pairs {pairs}, agree {agree}, disagree {disagree}, "
                     f"recompiled on switch {recompiles}/{pairs}")
    if stages:
        res.notes.append("disagreements by stage: " + ", ".join(f"{k}={v}" for k, v in stages.items()))
    res.seconds = time.perf_counter() - t0
    return res


# --------------------------------------------------------------------------
# rendering
# --------------------------------------------------------------------------

def format_experiment(r: ExperimentResult) -> str:
    L: List[str] = [f"\nExperiment {r.name}: {r.title}   ({r.seconds:.1f}s)"]
    for row in r.rows:
        bits = []
        for k, v in row.items():
            if isinstance(v, list) and len(v) > 6:
                v = f"[{len(v)} items]"
            bits.append(f"{k}={v}")
        L.append("   " + "  ".join(bits))
    for n in r.notes:
        L.append(f"   note: {n}")
    return "\n".join(L)
