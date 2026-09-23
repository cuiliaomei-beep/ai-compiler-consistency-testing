"""Plan section 16: staged localization, and the verdict a probe produces.

    E0 == E1 == E2, E3 != E0   ->  Inductor lowering / codegen
    E0 != E1                   ->  Dynamo graph capture
    E1 == E0, E2 != E0         ->  AOTAutograd / functionalization
    E3 == E0, E4 != E0         ->  Triton / CUDA code path

and for the execution matrix of section 14:

    E2 == C2cold, E2 != C2warm ->  specialization / cache consistency
    C1 != C1' after A->B->A    ->  incorrect cache invalidation
"""
from __future__ import annotations

from dataclasses import dataclass, field, replace
from typing import Any, Dict, List, Optional, Sequence, Tuple

from .execute import E0_EAGER, E1_DYNAMO, E2_AOT, E3_INDUCTOR, E4_TRITON, Matrix
from .observe import Observation
from .oracle import ALIAS, ALIAS_NONCONTRACTUAL, CacheVerdict, Comparison, Config, MUTATION, compare

STAGE_DYNAMO = "dynamo_capture"
STAGE_AOT = "aot_functionalization"
STAGE_INDUCTOR = "inductor_codegen"
STAGE_TRITON = "triton_codegen"
STAGE_SPECIALIZATION = "specialization_cache"
STAGE_INVALIDATION = "cache_invalidation"
STAGE_NONDET = "compile_nondeterminism"
STAGE_NONE = "none"

P_HIGH, P_MEDIUM, P_LOW, P_INFO = "high", "medium", "low", "info"
_ORDER = {P_HIGH: 0, P_MEDIUM: 1, P_LOW: 2, P_INFO: 3}

STAGE_LABEL = {
    STAGE_DYNAMO: "TorchDynamo (graph capture)",
    STAGE_AOT: "AOTAutograd / functionalization",
    STAGE_INDUCTOR: "TorchInductor (lowering / codegen)",
    STAGE_TRITON: "Triton / CUDA code path",
    STAGE_SPECIALIZATION: "cache specialization (guard / stale artifact reuse)",
    STAGE_INVALIDATION: "cache invalidation (A -> B -> A)",
    STAGE_NONDET: "compilation state leaking across compiles",
    STAGE_NONE: "no divergence",
}


@dataclass
class Triage:
    stage: str
    priority: str
    rationale: str
    kinds: List[str] = field(default_factory=list)
    recompiled: Optional[bool] = None
    guard_suspicious: bool = False
    warm_only: bool = False
    layers_unavailable: List[str] = field(default_factory=list)
    first_divergent_layer: Optional[str] = None

    @property
    def submittable(self) -> bool:
        return self.stage != STAGE_NONE and self.priority in (P_HIGH, P_MEDIUM)

    @property
    def is_failure(self) -> bool:
        return self.stage != STAGE_NONE

    def as_dict(self) -> Dict[str, Any]:
        return {"stage": self.stage, "stage_label": STAGE_LABEL.get(self.stage, self.stage),
                "priority": self.priority, "rationale": self.rationale, "kinds": list(self.kinds),
                "recompiled": self.recompiled, "guard_suspicious": self.guard_suspicious,
                "warm_only": self.warm_only, "layers_unavailable": list(self.layers_unavailable),
                "first_divergent_layer": self.first_divergent_layer, "submittable": self.submittable}


_ATTRIBUTION = {
    E1_DYNAMO: (STAGE_DYNAMO, P_LOW, "divergence already present at backend='eager': Dynamo graph-capture "
                                     "semantics (often documented-unsupported behaviour)"),
    E2_AOT: (STAGE_AOT, P_HIGH, "eager and backend='eager' agree but aot_eager differs: AOTAutograd / "
                                "functionalization (alias and in-place handling)"),
    E3_INDUCTOR: (STAGE_INDUCTOR, P_HIGH, "all pre-Inductor layers agree and only Inductor differs: "
                                          "lowering / code generation"),
    E4_TRITON: (STAGE_TRITON, P_HIGH, "Inductor CPU path agrees, only the Triton/CUDA path differs"),
}


def triage_layers(layers: Dict[str, Observation], fp64: Optional[Observation], cfg: Optional[Config] = None,
                  oracles: Optional[Sequence[str]] = None) -> Tuple[Triage, Dict[str, Comparison]]:
    cfg = cfg or Config()
    base = layers.get(E0_EAGER)
    comps: Dict[str, Comparison] = {}
    if base is None:
        return Triage(STAGE_NONE, P_INFO, "no eager baseline"), comps
    if base.infra_error:
        return Triage(STAGE_NONE, P_INFO, "eager baseline could not run", layers_unavailable=[E0_EAGER]), comps
    unavailable: List[str] = []
    ladder = [m for m in layers if m != E0_EAGER]
    for mode in ladder:
        obs = layers[mode]
        if obs.infra_error:
            unavailable.append(mode)
            continue
        comps[mode] = compare(base, obs, fp64, cfg, oracles)
    if not comps:
        return Triage(STAGE_NONE, P_INFO, "no compiled layer could be evaluated: " + ", ".join(unavailable),
                      layers_unavailable=unavailable), comps
    for mode in ladder:
        cmp = comps.get(mode)
        if cmp is None or not cmp.differs:
            continue
        stage, prio, why = _ATTRIBUTION.get(mode, (f"layer:{mode}", P_HIGH, f"first divergence at {mode}"))
        kinds = cmp.kinds
        if kinds and all(k == ALIAS_NONCONTRACTUAL for k in kinds):
            return Triage(STAGE_NONE, P_INFO, f"only a non-contractual alias change at {mode}", kinds,
                          layers_unavailable=unavailable), comps
        if stage == STAGE_AOT and (ALIAS in kinds or MUTATION in kinds):
            why += "; alias/mutation oracle fired (highest-value class)"
        return Triage(stage, prio, why, kinds, layers_unavailable=unavailable, first_divergent_layer=mode), comps
    note = "all evaluated layers agree with eager"
    if unavailable:
        note += f" (not evaluated: {', '.join(unavailable)})"
    return Triage(STAGE_NONE, P_INFO, note, layers_unavailable=unavailable), comps


def triage_matrix(m: Matrix, cfg: Optional[Config] = None, oracles: Optional[Sequence[str]] = None
                  ) -> Tuple[Triage, CacheVerdict]:
    """Section 14: ``E2 vs C2cold``, ``E2 vs C2warm``, ``C2cold vs C2warm`` (+ return trip)."""
    cfg = cfg or Config()
    factor = (m.ctx_a.differing_factors(m.ctx_b) or ["<none>"])[0]
    for obs in (m.C2cold, m.C2warm):
        if obs.infra_error:
            v = CacheVerdict(factor, m.recompiled_on_switch, Comparison(m.C2cold.mode, m.C2warm.mode))
            return Triage(STAGE_NONE, P_INFO, f"{obs.mode} could not be compiled ({obs.exception}); "
                                              "no conclusion", layers_unavailable=[obs.mode]), v
    cold_vs_warm = compare(m.C2cold, m.C2warm, m.fp64_b, cfg, oracles)
    e_vs_cold = compare(m.E2, m.C2cold, m.fp64_b, cfg, oracles) if not m.E2.infra_error else None
    e_vs_warm = compare(m.E2, m.C2warm, m.fp64_b, cfg, oracles) if not m.E2.infra_error else None
    trip = None
    if m.C1_return is not None and not m.C1_return.infra_error and not m.C1.infra_error:
        # the same artifact under the same context must agree to the noise floor
        strict = replace(cfg, fallback_rtol=1e-6, fallback_atol=1e-7, ulp_slack=0.25, use_dynamo_same=False)
        trip = compare(m.C1, m.C1_return, None, strict, oracles)
    v = CacheVerdict(factor, m.recompiled_on_switch, cold_vs_warm, e_vs_cold, e_vs_warm, trip,
                     m.recompiled_on_return)

    if v.invalidation_failure and not cold_vs_warm.differs:
        return Triage(STAGE_INVALIDATION, P_HIGH,
                      f"after switching '{factor}' A -> B -> A, A no longer yields its original result "
                      f"({'recompiled on return' if m.recompiled_on_return else 'no recompile on return'})",
                      trip.kinds if trip else [], recompiled=m.recompiled_on_return, warm_only=True), v
    if cold_vs_warm.differs and m.recompiled_on_switch is False:
        return Triage(STAGE_SPECIALIZATION, P_HIGH,
                      f"changing '{factor}' did not trigger a recompile, yet the warm result differs from a "
                      "cold compile of the same context: a cached artifact was reused under assumptions "
                      "that no longer hold", cold_vs_warm.kinds, recompiled=False,
                      warm_only=v.warm_only_failure), v
    if cold_vs_warm.differs:
        return Triage(STAGE_NONDET, P_MEDIUM,
                      f"changing '{factor}' did trigger a recompile, but the result still differs from a cold "
                      "compile: state leaks across compilations", cold_vs_warm.kinds, recompiled=True,
                      warm_only=v.warm_only_failure), v
    if v.guard_suspicious:
        return Triage(STAGE_NONE, P_INFO, f"'{factor}' changed without a recompile and the result matched; "
                                          "guards may be under-specified (informational)", [],
                      recompiled=False, guard_suspicious=True), v
    return Triage(STAGE_NONE, P_INFO, "cold and warm agree", [], recompiled=m.recompiled_on_switch), v


def worst(triages: Sequence[Triage]) -> Triage:
    if not triages:
        return Triage(STAGE_NONE, P_INFO, "nothing evaluated")
    return sorted(triages, key=lambda t: (_ORDER.get(t.priority, 9), t.stage))[0]
