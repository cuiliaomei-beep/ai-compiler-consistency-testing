"""Plan section 25, RQ3: does the static analysis actually earn its keep?

This is the experiment the whole method stands or falls on. The claim is that
statically deciding *which factors are worth changing* beats mutating tensor
attributes without a target. Until now it could not be run honestly, because
the contexts were hard-coded and identical for every function - so "with static
analysis" and "without" were the same thing.

The ladder follows the plan:

    A0   dynamic random only
    A1   + tensor metadata          (dtype / requires_grad attribute reads)
    A2   + flow-sensitive           (boundary predicates from branches)
    A3   + shape/index relations    (section 7)
    A4   + alias/mutation           (layout obligations from alias structure)
    A5   + semantic context signature
    A6   + cache sequences          (warm probes)

**On the metric.** The plan's headline metric is bugs found, and with zero real
bugs so far that cannot separate the levels. So the primary measure here is
*distinct compilations triggered per test*: each distinct compilation is one
more specialised artifact actually exercised, which is a direct measure of how
much of the compiler's behaviour space a strategy reached. Validity rate is
reported alongside, because a strategy that generates unusable contexts is
spending budget on nothing.
"""
from __future__ import annotations

import random
import time
from dataclasses import dataclass, field
from typing import Any, Dict, List, Optional, Sequence, Tuple

from .analysis import Analysis, analyze_source
from .case import Case, Context
from .obligation import (
    CONTIGUOUS,
    DTYPE,
    FLAG,
    REQUIRES_GRAD,
    SCALAR,
    SHAPE,
    Obligation,
    derive_obligations,
    derive_scs,
    obligations_to_contexts,
)

LEVELS = ["A0", "A1", "A2", "A3", "A4", "A5", "A6", "FULL"]

#: which obligation kinds each level is allowed to use
_ALLOWED: Dict[str, set] = {
    "A0": set(),
    "A1": {DTYPE, REQUIRES_GRAD},
    "A2": {DTYPE, REQUIRES_GRAD, SHAPE, FLAG, SCALAR},
    "A3": {DTYPE, REQUIRES_GRAD, SHAPE, FLAG, SCALAR},
    "A4": {DTYPE, REQUIRES_GRAD, SHAPE, FLAG, SCALAR, CONTIGUOUS},
    "A5": {DTYPE, REQUIRES_GRAD, SHAPE, FLAG, SCALAR, CONTIGUOUS},
    "A6": {DTYPE, REQUIRES_GRAD, SHAPE, FLAG, SCALAR, CONTIGUOUS},
    "FULL": {DTYPE, REQUIRES_GRAD, SHAPE, FLAG, SCALAR, CONTIGUOUS},
}

#: levels that may use the section-7 index relations
_INDEX_LEVELS = {"A3", "A4", "A5", "A6", "FULL"}
#: levels that run warm-cache sequences
_WARM_LEVELS = {"A6", "FULL"}

_RANDOM_DTYPES = ["float16", "float32", "float64", "bfloat16"]


# --------------------------------------------------------------------------
# A0: the honest random baseline
# --------------------------------------------------------------------------

def random_contexts(n_args: int, budget: int, seed: int = 0) -> List[Context]:
    """Contexts with no knowledge of the program at all.

    This is the strawman the method has to beat, and it must be a *fair*
    strawman: it varies the same axes the derived strategy can vary - dtype,
    a dimension's size, an argument's value, contiguity - it simply has no idea
    which of them this function reads.
    """
    rng = random.Random(seed)
    out: List[Context] = [Context("base", {"variant": "base"})]
    for i in range(budget):
        kind = rng.choice(["dtype", "resize", "substitute", "noncontig", "grad"])
        f: Dict[str, Any] = {"variant": "base"}
        if kind == "dtype":
            f["dtype"] = rng.choice(_RANDOM_DTYPES)
        elif kind == "resize":
            f["resize"] = {"arg": rng.randrange(max(1, n_args)),
                           "dim": rng.randrange(3),
                           "value": rng.choice([1, 2, 3, 7, 15, 16, 17, 31, 32, 33, 64])}
        elif kind == "substitute":
            f["substitute"] = {"arg": rng.randrange(max(1, n_args)),
                               "value": rng.choice([True, False, 0, 1, 2, -1, None])}
        elif kind == "noncontig":
            f["variant"] = "noncontig"
        else:
            f["requires_grad"] = {"arg": rng.randrange(max(1, n_args)), "value": True}
        out.append(Context(f"rand{i}", f))
    return out


# --------------------------------------------------------------------------
# level -> contexts
# --------------------------------------------------------------------------

def contexts_for_level(case: Case, level: str, budget: int,
                       seed: int = 0) -> Tuple[List[Context], float, int]:
    """Contexts a given ablation level would produce.

    Returns ``(contexts, analysis_seconds, n_obligations)`` - the analysis cost
    is part of the comparison, since a strategy that needs a minute of static
    analysis to save one test has not helped.
    """
    src = case.source
    n_args = len(case.contexts[0].factors) if case.contexts else 1
    try:
        import inspect
        if not src:
            src = inspect.getsource(case.fn)
    except Exception:
        src = None

    if level == "A0" or not src:
        return random_contexts(_arity(case), budget, seed), 0.0, 0

    t0 = time.perf_counter()
    analysis = analyze_source(src)
    scs = derive_scs(analysis)
    if level not in _INDEX_LEVELS:
        analysis = _strip_index_relations(analysis)
        scs = derive_scs(analysis)
    obligations = derive_obligations(analysis, scs)
    allowed = _ALLOWED.get(level, set())
    obligations = [ob for ob in obligations if ob.kind in allowed]
    elapsed = time.perf_counter() - t0

    contexts = obligations_to_contexts(obligations, analysis.params,
                                       max_contexts=budget + 1)
    # If the program yields fewer obligations than the budget, top up with
    # random contexts. Otherwise a level that derives little would win on
    # validity simply by testing almost nothing, which is not a fair comparison.
    #
    # Padding is marked by name, not by an extra factor: a factor would count
    # as a difference in ``Context.differing_factors`` and could exclude
    # legitimate single-factor pairs from the warm probes.
    if len(contexts) < budget + 1:
        extra = random_contexts(_arity(case), budget + 1 - len(contexts), seed)
        for c in extra[1:]:
            if len(contexts) >= budget + 1:
                break
            contexts.append(Context(f"{_PAD_PREFIX}{c.name}", dict(c.factors)))
    return contexts, elapsed, len(obligations)


_PAD_PREFIX = "pad_"


def is_padding(ctx: Context) -> bool:
    """Filler added to equalise budgets, not something the analysis derived."""
    return ctx.name.startswith(_PAD_PREFIX)


def _arity(case: Case) -> int:
    try:
        args = case.make_inputs(case.contexts[0])
        return max(1, len(args))
    except Exception:
        return 1


def _strip_index_relations(a: Analysis) -> Analysis:
    from dataclasses import replace as dc_replace
    return dc_replace(a, index_relations=[])


# --------------------------------------------------------------------------
# measurement
# --------------------------------------------------------------------------

@dataclass
class LevelResult:
    level: str
    cases: int = 0
    contexts: int = 0
    valid_contexts: int = 0
    #: of the valid ones, how many the analysis actually derived (not filler)
    derived_contexts: int = 0
    obligations: int = 0
    compilations: int = 0
    distinct_specializations: int = 0
    candidates: int = 0
    analysis_seconds: float = 0.0
    wall_seconds: float = 0.0
    warm_probes: int = 0

    @property
    def valid_rate(self) -> float:
        return self.valid_contexts / self.contexts if self.contexts else 0.0

    @property
    def specializations_per_test(self) -> float:
        return (self.distinct_specializations / self.valid_contexts
                if self.valid_contexts else 0.0)

    def as_dict(self) -> Dict[str, Any]:
        return {
            "level": self.level, "cases": self.cases,
            "contexts": self.contexts, "valid_contexts": self.valid_contexts,
            "derived_contexts": self.derived_contexts,
            "valid_rate": round(self.valid_rate, 3),
            "obligations": self.obligations,
            "compilations": self.compilations,
            "distinct_specializations": self.distinct_specializations,
            "specializations_per_test": round(self.specializations_per_test, 3),
            "candidates": self.candidates,
            "analysis_seconds": round(self.analysis_seconds, 3),
            "wall_seconds": round(self.wall_seconds, 1),
            "warm_probes": self.warm_probes,
        }


def measure_level(cases: Sequence[Case], level: str, budget: int = 8,
                  backend: str = "aot_eager", seed: int = 0) -> LevelResult:
    """Run one ablation level over a set of cases and collect the metrics."""
    from .execution import run_cold, run_eager
    from .oracle import Config
    from .runner import RunOptions, run_case

    res = LevelResult(level=level)
    t_start = time.perf_counter()

    for case in cases:
        contexts, t_analysis, n_obl = contexts_for_level(case, level, budget, seed)
        res.analysis_seconds += t_analysis
        res.obligations += n_obl
        res.contexts += len(contexts)
        res.cases += 1

        usable: List[Context] = []
        for ctx in contexts:
            try:
                obs = run_eager(case, ctx, seed)
            except Exception:
                continue
            if obs.ok:
                usable.append(ctx)
        res.valid_contexts += len(usable)
        res.derived_contexts += sum(1 for c in usable if not is_padding(c))
        if not usable:
            continue

        # Distinct specializations: how many separate compilations these
        # contexts provoke inside one live compiled callable. Reusing one
        # callable is what makes the count meaningful - a fresh compile per
        # context would trivially equal the context count.
        probe = Case(name=case.name, fn=case.fn, make_inputs=case.make_inputs,
                     contexts=usable, tags=case.tags, notes=case.notes,
                     source=case.source, alias_contract=case.alias_contract,
                     skip_fp64=case.skip_fp64)
        try:
            n_compiles = _count_specializations(probe, usable, backend, seed)
        except Exception:
            n_compiles = 0
        res.distinct_specializations += n_compiles
        res.compilations += n_compiles

        opts = RunOptions(backend=backend, reruns=0,
                          do_warm=level in _WARM_LEVELS)
        if level in _WARM_LEVELS:
            res.warm_probes += len(probe.context_pairs())
        try:
            res.candidates += len(run_case(probe, opts, Config()))
        except Exception:
            pass

    res.wall_seconds = time.perf_counter() - t_start
    return res


def _count_specializations(case: Case, contexts: Sequence[Context],
                           backend: str, seed: int) -> int:
    """Compile once, then run every context through it and count recompiles."""
    from .execution import build_inputs
    from .torchcompat import CompileCounter, compile_fn, dynamo_reset, sync

    counter = CompileCounter(backend)
    dynamo_reset()
    fn = compile_fn(case.fn, counter)
    total = 0
    for ctx in contexts:
        counter.reset()
        try:
            fn(*build_inputs(case, ctx, seed))
            sync()
        except Exception:
            continue
        total += counter.count
    dynamo_reset()
    return total


def run_ablation(cases: Sequence[Case], levels: Sequence[str] = LEVELS,
                 budget: int = 8, backend: str = "aot_eager",
                 seed: int = 0) -> List[LevelResult]:
    return [measure_level(cases, lv, budget, backend, seed) for lv in levels]


def format_results(results: Sequence[LevelResult]) -> str:
    head = (f"{'level':<7}{'cases':>6}{'ctx':>6}{'valid':>7}{'derived':>9}{'rate':>7}"
            f"{'oblig':>7}{'specz':>7}{'sp/test':>9}{'cand':>6}"
            f"{'analysis':>10}{'wall':>8}")
    lines = [head, "-" * len(head)]
    for r in results:
        lines.append(
            f"{r.level:<7}{r.cases:>6}{r.contexts:>6}{r.valid_contexts:>7}"
            f"{r.derived_contexts:>9}{r.valid_rate:>7.2f}{r.obligations:>7}"
            f"{r.distinct_specializations:>7}"
            f"{r.specializations_per_test:>9.2f}{r.candidates:>6}"
            f"{r.analysis_seconds:>10.3f}{r.wall_seconds:>8.1f}")
    lines.append("")
    lines.append("  derived = valid contexts the analysis actually produced; "
                 "the rest is filler added to equalise budgets")
    return "\n".join(lines)
