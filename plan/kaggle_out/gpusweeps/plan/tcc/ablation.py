"""RQ3: what does each piece of the static analysis contribute?

    A0  dynamic random only (exhaustive factor families, random values, output-only oracle)
    A1  + tensor metadata (dtype / contiguity / requires_grad reads)
    A2  + flow-sensitive dependency (flags, scalars, predicate tables)
    A3  + shape/index relations (boundary values, index-derived sizes)
    A4  + alias/mutation (facts -> mutation/alias/gradient oracles, layout variants)
    A5  + Semantic Context Signature (prune to what the program reads)
    A6  + cache sequences (A->B, B->A, A->B->A with recompile counting)
    FULL

Every level runs the same benchmark under the same test budget. Metrics:
bugs found, tests required, time to first failure, invalid tests, analysis
overhead.
"""
from __future__ import annotations

import time
from typing import Any, Callable, Dict, List, Optional, Sequence

from .baselines import random_plan_builder
from .benchmark import run_benchmark
from .scs import DeriveOptions

LEVELS = ["A0", "A1", "A2", "A3", "A4", "A5", "A6", "FULL"]
OUTPUT_ONLY = ["value", "metadata", "exception"]


def level_config(level: str, budget: int) -> Dict[str, Any]:
    if level == "A0":
        return {"plan_builder": random_plan_builder(budget, sequences=False, oracles=OUTPUT_ONLY, level="A0"),
                "derive": DeriveOptions(cache_sequence=False), "oracles": OUTPUT_ONLY, "do_matrix": False}
    d = DeriveOptions(tensor_metadata=False, flow_dependency=False, shape_index=False, alias_mutation=False,
                      scs_prune=False, cache_sequence=False, include_default_dtype=False,
                      include_compile_flags=False)
    oracles: Optional[List[str]] = OUTPUT_ONLY
    do_matrix = False
    rank = LEVELS.index(level)
    if rank >= 1:
        d.tensor_metadata = True
        d.include_default_dtype = True
        d.include_compile_flags = True
    if rank >= 2:
        d.flow_dependency = True
    if rank >= 3:
        d.shape_index = True
    if rank >= 4:
        d.alias_mutation = True
        oracles = None  # what the obligations ask for (mutation / alias / gradient included)
    if rank >= 5:
        d.scs_prune = True
    if rank >= 6:
        d.cache_sequence = True
        do_matrix = True
    return {"plan_builder": None, "derive": d, "oracles": oracles, "do_matrix": do_matrix}


def run_ablation(backend: str = "eager", budget: int = 8, levels: Optional[Sequence[str]] = None,
                 log: Callable[[str], None] = print, out_dir: Optional[str] = None,
                 only: Optional[str] = None) -> Dict[str, Any]:
    levels = list(levels or LEVELS)
    results: Dict[str, Any] = {"backend": backend, "budget": budget, "levels": {}}
    for lv in levels:
        cfg = level_config(lv, budget)
        t0 = time.perf_counter()
        res = run_benchmark(backend=backend, budget=budget, reruns=0, only=only, check_fixed=(lv == "FULL"),
                            log=lambda s: None, out_dir=None, derive=cfg["derive"], plan_builder=cfg["plan_builder"],
                            oracles=cfg["oracles"], level=lv, do_matrix=cfg["do_matrix"],
                            max_contexts=budget)
        res["wall_s"] = round(time.perf_counter() - t0, 1)
        # analysis overhead: sum of static ms over the entries' plans is not kept; recompute cheaply
        from . import corpus  # noqa: F401
        from .generate import build_plan
        from .program import get
        from .benchmark import programs_for
        from .faults import FAULTS
        seen = set()
        ms = 0.0
        for f in FAULTS:
            for pn in programs_for(f):
                if pn in seen:
                    continue
                seen.add(pn)
                try:
                    p = get(pn)
                except KeyError:
                    continue
                if cfg["plan_builder"] is None:
                    plan = build_plan(p, cfg["derive"], budget, level=lv)
                    ms += plan.analysis.analysis_ms + plan.generation_ms
        res["analysis_overhead_ms"] = round(ms, 1)
        results["levels"][lv] = {k: v for k, v in res.items() if k not in ("entries", "fixed")}
        results["levels"][lv]["entries"] = res["entries"]
        log(f"  {lv:<5} detected {res['detected']:>2}/{res['faults']}  tests {res['tests_executed']:>4}  "
            f"invalid {res['tests_invalid']:>3}  mean-ttd {res['mean_tests_to_detect']}  "
            f"analysis {res['analysis_overhead_ms']} ms  wall {res['wall_s']}s  FP {res['false_positives_on_fixed']}")
    if out_dir:
        import json
        import os
        os.makedirs(out_dir, exist_ok=True)
        with open(os.path.join(out_dir, "rq3_ablation.json"), "w", encoding="utf-8") as fh:
            json.dump(results, fh, indent=2, default=str)
    return results


def format_ablation(res: Dict[str, Any]) -> str:
    L = ["", f"RQ3 ablation (backend {res['backend']}, budget {res['budget']} tests/program)", "",
         "| level | bugs found | tests | invalid | mean tests-to-detect | analysis ms | FP(fixed) | wall s |",
         "|---|---:|---:|---:|---:|---:|---:|---:|"]
    for lv, r in res["levels"].items():
        L.append(f"| {lv} | {r['detected']}/{r['faults']} | {r['tests_executed']} | {r['tests_invalid']} | "
                 f"{r['mean_tests_to_detect']} | {r['analysis_overhead_ms']} | {r['false_positives_on_fixed']} | "
                 f"{r['wall_s']} |")
    L.append("")
    L.append("  per category:")
    cats = sorted({c for r in res["levels"].values() for c in r["per_category"]})
    L.append("  " + " | ".join(["level".ljust(5)] + [c.ljust(14) for c in cats]))
    for lv, r in res["levels"].items():
        L.append("  " + " | ".join([lv.ljust(5)] + [f"{r['per_category'].get(c, {}).get('detected', 0)}/"
                                                    f"{r['per_category'].get(c, {}).get('total', 0)}".ljust(14)
                                                    for c in cats]))
    return "\n".join(L)
