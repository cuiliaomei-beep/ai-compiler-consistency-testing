"""Plan sections 22-24: comparison against existing tools.

The plan defines two settings, and only the second is implemented here.

**Setting A** runs each tool in its own configuration with its own oracle and
compares bug counts. It answers "which tool finds more" but confounds the
generator with the oracle: a tool that never checks aliasing cannot report an
aliasing bug, and the comparison then measures oracle coverage rather than test
quality.

**Setting B** takes only each tool's *test generator* and feeds its output into
this harness - same oracles, same fp64 rule, same hardware, same PyTorch build,
same budget. That isolates the one variable worth measuring:

    whose generated programs are more likely to trigger a real
    source-artifact consistency failure?

Setting B is also what makes the comparison runnable at all: research fuzzers
pin old dependency versions and frequently will not install beside a current
PyTorch, whereas their generators usually will.

**On what is and is not a baseline here.** Only tools whose actual
implementation runs are included. Re-implementing a paper's described strategy
and calling the result that tool would measure our reading of the paper, not
the tool - so where an implementation cannot be obtained, that is reported as a
gap rather than filled in.
"""
from __future__ import annotations

import time
import warnings
from dataclasses import dataclass, field
from typing import Any, Callable, Dict, Iterator, List, Optional, Sequence, Tuple

from .case import Case, Context
from .torchcompat import seed_everything, torch

# --------------------------------------------------------------------------
# availability
# --------------------------------------------------------------------------

@dataclass
class BaselineStatus:
    name: str
    available: bool
    detail: str
    kind: str = ""   # "generator" | "unavailable"

    def as_dict(self) -> Dict[str, Any]:
        return {"name": self.name, "available": self.available,
                "detail": self.detail, "kind": self.kind}


def probe_baselines() -> List[BaselineStatus]:
    """What can actually be run here, checked rather than assumed."""
    out: List[BaselineStatus] = []

    try:
        with warnings.catch_warnings():
            warnings.simplefilter("ignore")
            from nnsmith.graph_gen import model_gen  # noqa: F401
            from nnsmith.materialize import Model  # noqa: F401
        out.append(BaselineStatus(
            "NNSmith", True,
            "installed from PyPI; SMT-constrained DNN graph generation",
            "generator"))
    except Exception as e:
        out.append(BaselineStatus("NNSmith", False,
                                  f"{type(e).__name__}: {str(e)[:110]}"))

    # The PyPI project called `neuri` is an unrelated API client, not the
    # NeuRI fuzzer. Using it as a baseline would fabricate a comparison, so it
    # is reported unavailable even though the import succeeds.
    try:
        import neuri  # noqa: F401
        looks_right = hasattr(neuri, "graph_gen") or hasattr(neuri, "materialize")
        out.append(BaselineStatus(
            "NeuRI", bool(looks_right),
            "the PyPI package `neuri` is an unrelated API client, not the "
            "NeuRI fuzzer; no usable implementation found"
            if not looks_right else "installed", ""))
    except Exception:
        out.append(BaselineStatus("NeuRI", False, "not installed"))

    for name, why in (
        ("WhiteFox", "requires an LLM service and the published prompt set; "
                     "no pip distribution"),
        ("DeepConstr", "GitHub-only distribution; not attempted here"),
        ("AlignGuard", "no artifact released with the preprint"),
        ("TorchProbe", "GitHub-only distribution; not attempted here"),
    ):
        out.append(BaselineStatus(name, False, why))

    return out


# --------------------------------------------------------------------------
# NNSmith generator -> harness cases
# --------------------------------------------------------------------------

_NNSMITH_STATE: Dict[str, Any] = {}


def _nnsmith_setup() -> Tuple[Any, Any]:
    if "opset" in _NNSMITH_STATE:
        return _NNSMITH_STATE["ModelType"], _NNSMITH_STATE["opset"]
    with warnings.catch_warnings():
        warnings.simplefilter("ignore")
        from nnsmith.materialize import Model
        from nnsmith.narrow_spec import auto_opset
    ModelType = Model.init("torch", backend_target="cpu")
    ModelType.add_seed_setter()
    opset = auto_opset(ModelType, vulops=False)
    _NNSMITH_STATE["ModelType"] = ModelType
    _NNSMITH_STATE["opset"] = opset
    return ModelType, opset


def iter_nnsmith_cases(count: int = 40, max_nodes: int = 6,
                       seed: int = 0) -> Iterator[Case]:
    """Wrap NNSmith-generated graphs as harness cases.

    The graph, its operators and its input shapes are entirely NNSmith's
    decisions; only the execution and the oracles are ours. That is the point
    of Setting B.
    """
    if torch is None:
        return
    try:
        ModelType, opset = _nnsmith_setup()
        from nnsmith.graph_gen import model_gen
    except Exception:
        return

    made = 0
    attempt = 0
    while made < count and attempt < count * 4:
        attempt += 1
        try:
            with warnings.catch_warnings():
                warnings.simplefilter("ignore")
                gen = model_gen(opset=opset, max_nodes=max_nodes,
                                seed=seed + attempt)
                ir = gen.make_concrete()
                model = ModelType.from_gir(ir)
                net = model.torch_model
        except Exception:
            continue

        inputs = getattr(model, "input_like", None)
        if not inputs:
            continue
        names = list(inputs.keys())

        def make_inputs(ctx: Context, _net=net, _names=tuple(names),
                        _il=dict(inputs), _s=seed + attempt) -> Tuple[Any, ...]:
            from .seeds import _apply_context
            seed_everything(_s)
            args = []
            for n in _names:
                spec = _il[n]
                shape = tuple(int(d) for d in spec.shape)
                dt = getattr(spec, "dtype", None)
                td = getattr(dt, "torch", None) if dt is not None else None
                t = torch.rand(*shape) if shape else torch.rand(())
                if td is not None and td != torch.float32:
                    try:
                        t = t.to(td)
                    except Exception:
                        pass
                args.append(t)
            return _apply_context(tuple(args), ctx)

        def fn(*args, _net=net, _names=tuple(names)):
            out = _net(*args)
            return out

        yield Case(
            name=f"nnsmith_{made:03d}",
            fn=fn,
            make_inputs=make_inputs,
            # NNSmith models are opaque nn.Modules with no readable source, so
            # the derived-context machinery has nothing to read. A fixed set is
            # used here and the same set is given to our own generator in the
            # comparison, so neither side is advantaged.
            contexts=[Context("base", {"variant": "base"}),
                      Context("noncontig", {"variant": "noncontig"}),
                      Context("dtype_float64", {"variant": "base",
                                                "dtype": "float64"})],
            tags=["baseline", "nnsmith"],
            notes=f"NNSmith-generated graph, {len(ir.insts)} nodes",
        )
        made += 1


# --------------------------------------------------------------------------
# Setting B: same harness, different generators
# --------------------------------------------------------------------------

@dataclass
class GeneratorResult:
    generator: str
    cases: int = 0
    valid_cases: int = 0
    contexts: int = 0
    candidates: int = 0
    submittable: int = 0
    distinct_specializations: int = 0
    gen_seconds: float = 0.0
    probe_seconds: float = 0.0
    time_to_first_candidate: Optional[float] = None

    @property
    def specializations_per_case(self) -> float:
        return (self.distinct_specializations / self.valid_cases
                if self.valid_cases else 0.0)

    def as_dict(self) -> Dict[str, Any]:
        return {
            "generator": self.generator, "cases": self.cases,
            "valid_cases": self.valid_cases, "contexts": self.contexts,
            "candidates": self.candidates, "submittable": self.submittable,
            "distinct_specializations": self.distinct_specializations,
            "specializations_per_case": round(self.specializations_per_case, 3),
            "gen_seconds": round(self.gen_seconds, 2),
            "probe_seconds": round(self.probe_seconds, 1),
            "time_to_first_candidate": (round(self.time_to_first_candidate, 1)
                                        if self.time_to_first_candidate else None),
        }


def run_setting_b(generators: Dict[str, Callable[[], Iterator[Case]]],
                  backend: str = "aot_eager", seed: int = 0,
                  case_budget: int = 40) -> List[GeneratorResult]:
    """Feed each generator's output through the identical harness."""
    from .ablation import _count_specializations
    from .cases_model import validate_cases
    from .oracle import Config
    from .runner import RunOptions, run_case

    results: List[GeneratorResult] = []
    for name, make in generators.items():
        res = GeneratorResult(generator=name)

        t0 = time.perf_counter()
        try:
            built = list(make())[:case_budget]
        except Exception:
            built = []
        res.gen_seconds = time.perf_counter() - t0
        res.cases = len(built)

        ok, _bad = validate_cases(built)
        res.valid_cases = len(ok)

        t1 = time.perf_counter()
        opts = RunOptions(backend=backend, reruns=0, seed=seed)
        for case in ok:
            res.contexts += len(case.contexts)
            try:
                res.distinct_specializations += _count_specializations(
                    case, case.contexts, backend, seed)
            except Exception:
                pass
            try:
                recs = run_case(case, opts, Config())
            except Exception:
                continue
            if recs and res.time_to_first_candidate is None:
                res.time_to_first_candidate = time.perf_counter() - t1
            res.candidates += len(recs)
            res.submittable += sum(1 for r in recs if r.triage.submittable)
        res.probe_seconds = time.perf_counter() - t1
        results.append(res)
    return results


def format_setting_b(results: Sequence[GeneratorResult]) -> str:
    head = (f"{'generator':<16}{'cases':>7}{'valid':>7}{'ctx':>6}{'specz':>7}"
            f"{'sp/case':>9}{'cand':>6}{'submit':>8}{'gen_s':>8}{'probe_s':>9}"
            f"{'TTFC':>8}")
    lines = [head, "-" * len(head)]
    for r in results:
        ttfc = f"{r.time_to_first_candidate:.1f}" if r.time_to_first_candidate else "-"
        lines.append(
            f"{r.generator:<16}{r.cases:>7}{r.valid_cases:>7}{r.contexts:>6}"
            f"{r.distinct_specializations:>7}{r.specializations_per_case:>9.2f}"
            f"{r.candidates:>6}{r.submittable:>8}{r.gen_seconds:>8.1f}"
            f"{r.probe_seconds:>9.1f}{ttfc:>8}")
    lines.append("")
    lines.append("  identical oracles, hardware, PyTorch build and budget; "
                 "only the generator differs")
    return "\n".join(lines)
