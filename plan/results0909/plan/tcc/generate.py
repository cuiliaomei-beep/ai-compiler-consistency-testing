"""Plan sections 11-15: consistency-oriented test generation.

11  base input      a legal seed (registered builder, signature-derived, or random)
12  pairwise        contexts that differ from the base in exactly one factor
13  boundary        k-1 / k / k+1 for every predicate constant the analysis found
14  cache sequence  compile(x1) -> warm -> execute(x2), x1 and x2 one factor apart
15  context switch  A->B, B->A, A->B->A for every SCS factor

The output is a :class:`TestPlan`: contexts, single-factor pairs, and
sequences, every one traceable to the obligation (and therefore the source
line) that produced it.
"""
from __future__ import annotations

import time
from dataclasses import dataclass, field
from typing import Any, Dict, List, Optional, Sequence, Tuple

from .factors import Analysis, analyze
from .program import Context, Program, single_factor_pairs
from .scs import (SCS, DeriveOptions, Obligation, combination_contexts, derive_obligations, derive_scs,
                  obligations_to_contexts)

PATTERNS = ("A->B", "B->A", "A->B->A")


@dataclass
class TestPlan:
    program: str
    analysis: Analysis
    scs: SCS
    obligations: List[Obligation]
    contexts: List[Context]
    pairs: List[Tuple[Context, Context]] = field(default_factory=list)
    sequences: List[List[Context]] = field(default_factory=list)
    #: which oracles the obligations ask for (union)
    oracles: List[str] = field(default_factory=list)
    generation_ms: float = 0.0
    level: str = "FULL"

    @property
    def n_tests(self) -> int:
        return len(self.contexts) + len(self.sequences)

    def as_dict(self) -> Dict[str, Any]:
        return {
            "program": self.program, "level": self.level,
            "scs": self.scs.as_dict(),
            "obligations": [o.as_dict() for o in self.obligations],
            "contexts": [c.as_dict() for c in self.contexts],
            "pairs": [[a.name, b.name] for a, b in self.pairs],
            "sequences": [[c.name for c in s] for s in self.sequences],
            "oracles": self.oracles, "n_tests": self.n_tests,
            "generation_ms": round(self.generation_ms, 3),
            "analysis_ms": round(self.analysis.analysis_ms, 3),
        }


def context_switch_sequences(pairs: Sequence[Tuple[Context, Context]],
                             patterns: Sequence[str] = PATTERNS) -> List[List[Context]]:
    """Section 15: for every single-factor pair build the switch sequences."""
    seqs: List[List[Context]] = []
    seen = set()
    for a, b in pairs:
        for p in patterns:
            if p == "A->B":
                s = [a, b]
            elif p == "B->A":
                s = [b, a]
            else:
                s = [a, b, a]
            key = tuple(c.name for c in s)
            if key in seen:
                continue
            seen.add(key)
            seqs.append(s)
    return seqs


def build_plan(program: Program, opt: Optional[DeriveOptions] = None, max_contexts: int = 16,
               patterns: Sequence[str] = PATTERNS, level: str = "FULL",
               extra_contexts: Optional[Sequence[Context]] = None) -> TestPlan:
    """Static analysis -> SCS -> obligations -> contexts -> pairs -> sequences."""
    t0 = time.perf_counter()
    opt = opt or DeriveOptions()
    analysis = analyze(program.fn, program.get_source())
    scs = derive_scs(analysis, opt)
    obligations = derive_obligations(analysis, scs, opt)
    combos = combination_contexts(analysis, obligations, analysis.params, program.base_context) \
        if opt.flow_dependency else []
    # predicate tables (experiment C) are reserved slots: they come from the
    # program's own control flow and must not be crowded out by ladder values
    contexts = obligations_to_contexts(obligations, analysis.params, program.base_context,
                                       max(2, max_contexts - len(combos)))
    for c in combos:
        if all(c.name != x.name for x in contexts):
            contexts.append(c)

    # author-listed contexts (seed corpus) are kept; they are single-factor by construction
    for c in list(program.contexts) + list(extra_contexts or []):
        if all(c.name != x.name for x in contexts) and len(contexts) < max_contexts:
            contexts.append(c)

    pairs = single_factor_pairs(contexts)
    # only obligations that ask for a warm sequence contribute their factor to the pairs
    if opt.cache_sequence:
        seqs = context_switch_sequences(pairs, patterns)
    else:
        seqs = []
    oracles: List[str] = []
    for ob in obligations:
        for o in ob.oracles:
            if o not in oracles:
                oracles.append(o)
    if opt.alias_mutation:
        # O4/O5/O6 cost nothing beyond the snapshot already taken, so once the
        # structural analysis is on they run on every test (facts decide which
        # *contexts* are generated, not which observations are compared)
        for o in ("mutation", "alias", "gradient"):
            if o not in oracles:
                oracles.append(o)
    if "exception" not in oracles:
        oracles.append("exception")
    plan = TestPlan(program.name, analysis, scs, obligations, contexts, pairs, seqs, oracles,
                    level=level)
    plan.generation_ms = (time.perf_counter() - t0) * 1000.0
    return plan


def format_plan(plan: TestPlan) -> str:
    L = [f"  plan({plan.program}) level={plan.level}: {len(plan.contexts)} contexts, "
         f"{len(plan.pairs)} single-factor pairs, {len(plan.sequences)} sequences, "
         f"oracles={plan.oracles}"]
    for c in plan.contexts:
        L.append(f"      ctx {c.name:<28} {c.factors}")
    for s in plan.sequences[:12]:
        L.append("      seq " + " -> ".join(c.name for c in s))
    if len(plan.sequences) > 12:
        L.append(f"      ... {len(plan.sequences) - 12} more sequences")
    L.append(f"      analysis {plan.analysis.analysis_ms:.1f} ms, generation {plan.generation_ms:.1f} ms")
    return "\n".join(L)
