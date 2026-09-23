"""Stage attribution, priority, failure signatures and dedup.

Layered bisection is not only a localization aid — it is the cheapest triage
filter the harness has, and using it that way is what keeps the confirmation
rate up:

* a divergence already visible at ``backend="eager"`` is **Dynamo capture
  semantics**. Most such reports are documented-unsupported behaviour or graph
  break semantics, and get closed as won't-fix. Low priority.
* a divergence that appears only at ``aot_eager`` implicates
  **functionalization** — where alias and in-place handling lives. High.
* a divergence that appears only at ``inductor`` is **lowering / codegen**
  against an intermediate representation the project already accepts. This is
  the class maintainers act on. High.
* ``cold != warm`` needs no eager run at all, so it carries no floating-point
  tolerance argument. Highest.

Filtering on this *before* a human looks at anything removes most of the
candidates that were never going to be accepted.
"""
from __future__ import annotations

import hashlib
import json
import os
from dataclasses import dataclass, field
from typing import Any, Dict, List, Optional, Tuple

from .execution import E0_EAGER, E1_DYNAMO, E2_AOT, E3_INDUCTOR
from .oracle import (
    ALIAS,
    ALIAS_NONCONTRACTUAL,
    Comparison,
    Config,
    GRADIENT,
    MUTATION,
    compare,
)
from .snapshot import Observation

# stages
STAGE_DYNAMO = "dynamo_capture"
STAGE_AOT = "aot_functionalization"
STAGE_INDUCTOR = "inductor_codegen"
STAGE_SPECIALIZATION = "specialization_cache"
STAGE_COMPILE_NONDET = "compile_nondeterminism"
STAGE_NONE = "none"

# priorities
P_HIGH = "high"
P_MEDIUM = "medium"
P_LOW = "low"
P_INFO = "info"

_PRIORITY_ORDER = {P_HIGH: 0, P_MEDIUM: 1, P_LOW: 2, P_INFO: 3}


@dataclass
class Triage:
    stage: str
    priority: str
    rationale: str
    kinds: List[str] = field(default_factory=list)
    recompiled: Optional[bool] = None
    guard_suspicious: bool = False
    #: layers dropped because the toolchain, not the program, failed there
    layers_unavailable: List[str] = field(default_factory=list)

    @property
    def submittable(self) -> bool:
        """Would we put a human's time on this?"""
        return self.stage != STAGE_NONE and self.priority in (P_HIGH, P_MEDIUM)

    def as_dict(self) -> Dict[str, Any]:
        return {
            "stage": self.stage,
            "priority": self.priority,
            "rationale": self.rationale,
            "kinds": list(self.kinds),
            "recompiled": self.recompiled,
            "guard_suspicious": self.guard_suspicious,
            "layers_unavailable": list(self.layers_unavailable),
            "submittable": self.submittable,
        }


def triage_layers(
    layers: Dict[str, Observation],
    fp64: Optional[Observation] = None,
    cfg: Optional[Config] = None,
) -> Tuple[Triage, Dict[str, Comparison]]:
    """D1: compare each compiled layer against eager and attribute the stage."""
    cfg = cfg or Config()
    base = layers.get(E0_EAGER)
    comparisons: Dict[str, Comparison] = {}
    if base is None:
        return Triage(STAGE_NONE, P_INFO, "no eager baseline"), comparisons
    if base.infra_error:
        return (
            Triage(STAGE_NONE, P_INFO, "eager baseline itself failed to run",
                   layers_unavailable=[E0_EAGER]),
            comparisons,
        )

    # Walk the ladder in the order it was executed. Deriving the order from the
    # dict rather than a hard-coded triple lets a caller substitute layers
    # (``run.py validate`` injects a deliberately wrong one) and still get a
    # verdict.
    ladder = [m for m in layers if m != E0_EAGER]

    unavailable: List[str] = []
    for mode in ladder:
        obs = layers.get(mode)
        if obs is None:
            continue
        # A layer whose toolchain failed says nothing about semantics. Comparing
        # against it manufactures an "exception divergence" for every case -
        # which is exactly what a missing C++ compiler produced before this
        # guard existed.
        if obs.infra_error:
            unavailable.append(mode)
            continue
        comparisons[mode] = compare(base, obs, fp64, cfg)

    if not comparisons:
        return (
            Triage(STAGE_NONE, P_INFO,
                   "no compiled layer could be evaluated: " + ", ".join(unavailable),
                   layers_unavailable=unavailable),
            comparisons,
        )

    attribution = {
        E1_DYNAMO: (STAGE_DYNAMO, P_LOW,
                    "divergence already present at backend='eager': Dynamo "
                    "graph-capture semantics; frequently documented-unsupported "
                    "behaviour"),
        E2_AOT: (STAGE_AOT, P_HIGH,
                 "eager and backend='eager' agree but aot_eager differs: "
                 "implicates AOTAutograd / functionalization (alias and in-place "
                 "handling)"),
        E3_INDUCTOR: (STAGE_INDUCTOR, P_HIGH,
                      "all pre-Inductor layers agree and only Inductor differs: "
                      "lowering / code generation against an already-accepted IR"),
    }
    for mode in ladder:
        cmp = comparisons.get(mode)
        if cmp is not None and cmp.differs:
            stage, priority, why = attribution.get(
                mode, (f"layer:{mode}", P_HIGH,
                       f"first divergence appears at layer '{mode}'")
            )
            # alias/mutation divergence at the AOT layer is the strongest signal
            # we have; keep it at the top of the queue.
            kinds = cmp.kinds
            # A divergence whose only evidence is a non-contractual alias change
            # is real but not a defect: the operator never promised to return a
            # view. Keep the record, drop it out of the submittable queue.
            if kinds and all(k == ALIAS_NONCONTRACTUAL for k in kinds):
                return (
                    Triage(STAGE_NONE, P_INFO,
                           f"only a non-contractual alias change at '{mode}': the "
                           "operator's schema declares no alias relation, so "
                           "returning copies after compilation is legal",
                           kinds, layers_unavailable=unavailable),
                    comparisons,
                )
            if stage == STAGE_AOT and (ALIAS in kinds or MUTATION in kinds):
                why += " - alias/mutation oracle fired, the highest-value class"
            elif stage == STAGE_AOT and GRADIENT in kinds:
                why += (" - gradient oracle fired where AOTAutograd generates "
                        "the backward graph")
            return (
                Triage(stage, priority, why, kinds, layers_unavailable=unavailable),
                comparisons,
            )

    note = "all evaluated layers agree with eager"
    if unavailable:
        note += f" (not evaluated: {', '.join(unavailable)})"
    return Triage(STAGE_NONE, P_INFO, note, layers_unavailable=unavailable), comparisons


def triage_warm(
    cold: Observation,
    warm: Observation,
    recompiled: bool,
    factor_changed: str,
    fp64: Optional[Observation] = None,
    cfg: Optional[Config] = None,
) -> Tuple[Triage, Comparison]:
    """D2: compare cold-compiled B against warm-after-A B.

    Both sides are compiled artifacts, so no eager-vs-compiled numeric argument
    applies. A difference here is unambiguous.
    """
    cfg = cfg or Config()
    for obs, which in ((cold, "cold"), (warm, "warm")):
        if obs.infra_error:
            return (
                Triage(STAGE_NONE, P_INFO,
                       f"{which} side could not be compiled ({obs.exception}); "
                       "no semantic conclusion available",
                       layers_unavailable=[obs.mode]),
                Comparison(ref_mode=cold.mode, test_mode=warm.mode),
            )
    cmp = compare(cold, warm, fp64, cfg)

    if cmp.differs and not recompiled:
        return (
            Triage(
                STAGE_SPECIALIZATION,
                P_HIGH,
                f"changing '{factor_changed}' did not trigger a recompile, yet the "
                "warm result differs from a cold compile of the same context: the "
                "cached artifact was reused under assumptions that no longer hold",
                cmp.kinds,
                recompiled=False,
            ),
            cmp,
        )
    if cmp.differs and recompiled:
        return (
            Triage(
                STAGE_COMPILE_NONDET,
                P_MEDIUM,
                f"changing '{factor_changed}' did trigger a recompile, but the result "
                "still differs from a cold compile: state leaking across compilations "
                "rather than stale reuse",
                cmp.kinds,
                recompiled=True,
            ),
            cmp,
        )
    if not cmp.differs and not recompiled:
        return (
            Triage(
                STAGE_NONE,
                P_INFO,
                f"'{factor_changed}' changed without a recompile and the result "
                "matched; guards may be under-specified but nothing is observable "
                "yet - useful for steering further mutation",
                [],
                recompiled=False,
                guard_suspicious=True,
            ),
            cmp,
        )
    return Triage(STAGE_NONE, P_INFO, "cold and warm agree", [], recompiled=True), cmp


def triage_return_trip(
    first: Observation,
    second: Observation,
    recompiled: bool,
    factor_changed: str,
    cfg: Optional[Config] = None,
) -> Tuple[Triage, Comparison]:
    """Plan section 15: verdict for the ``A -> B -> A`` sequence.

    Both observations are context A under the same compiled callable, so they
    must agree bit for bit. A difference means the detour through B left the
    cache in a state that no longer answers A correctly - incorrect cache
    invalidation, which the two-step probe cannot detect.
    """
    cfg = cfg or Config()
    for obs, which in ((first, "first"), (second, "second")):
        if obs.infra_error:
            return (Triage(STAGE_NONE, P_INFO,
                           f"{which} leg could not be compiled ({obs.exception})",
                           layers_unavailable=[obs.mode]),
                    Comparison(ref_mode=first.mode, test_mode=second.mode))

    cmp = compare(first, second, None, cfg)
    if not cmp.differs:
        return (Triage(STAGE_NONE, P_INFO,
                       f"returning to the original context after switching "
                       f"'{factor_changed}' still gives the same answer",
                       recompiled=recompiled), cmp)
    return (
        Triage(
            STAGE_SPECIALIZATION, P_HIGH,
            f"after switching '{factor_changed}' away and back, the original "
            f"context no longer produces its original result "
            f"({'a recompile happened on return' if recompiled else 'no recompile on return'})"
            " - the cache was left invalidated incorrectly",
            cmp.kinds, recompiled=recompiled),
        cmp,
    )


def worst(triages: List[Triage]) -> Triage:
    """The highest-priority verdict among several."""
    if not triages:
        return Triage(STAGE_NONE, P_INFO, "nothing evaluated")
    return sorted(triages, key=lambda t: (_PRIORITY_ORDER.get(t.priority, 9), t.stage))[0]


# --------------------------------------------------------------------------
# failure signature + dedup
# --------------------------------------------------------------------------

def signature(
    case_name: str,
    stage: str,
    kinds: List[str],
    factor: str = "",
    exception: Optional[str] = None,
    frame: Optional[str] = None,
) -> str:
    """A stable identity for a failure, for clustering before human triage.

    Deliberately coarse: two runs of the same underlying defect under slightly
    different shapes must land in the same bucket, or the triage queue fills
    with the same bug a hundred times.
    """
    parts = [
        case_name,
        stage,
        ",".join(sorted(set(kinds))),
        factor,
        exception or "",
        frame or "",
    ]
    raw = "|".join(parts)
    return hashlib.sha1(raw.encode("utf-8")).hexdigest()[:12]


class DedupStore:
    """A JSON-backed signature -> first-occurrence index."""

    def __init__(self, path: str):
        self.path = path
        self.entries: Dict[str, Dict[str, Any]] = {}
        if os.path.exists(path):
            try:
                with open(path, "r", encoding="utf-8") as fh:
                    self.entries = json.load(fh)
            except Exception:
                self.entries = {}

    def seen(self, sig: str) -> bool:
        return sig in self.entries

    def add(self, sig: str, meta: Dict[str, Any]) -> bool:
        """Record an occurrence. Returns True if this signature is new."""
        if sig in self.entries:
            self.entries[sig]["count"] = self.entries[sig].get("count", 1) + 1
            return False
        self.entries[sig] = {"count": 1, **meta}
        return True

    def save(self) -> None:
        d = os.path.dirname(self.path)
        if d:
            os.makedirs(d, exist_ok=True)
        with open(self.path, "w", encoding="utf-8") as fh:
            json.dump(self.entries, fh, indent=2, ensure_ascii=False, sort_keys=True)

    def stats(self) -> Dict[str, int]:
        return {
            "unique": len(self.entries),
            "total": sum(e.get("count", 1) for e in self.entries.values()),
        }
