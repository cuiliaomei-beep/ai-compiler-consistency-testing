"""Plan sections 25-26: RQ2, RQ4 and the key experiments A-E.

RQ1 lives in :mod:`tcc.benchmark`, RQ3 in :mod:`tcc.ablation`, RQ5 in
:mod:`tcc.campaign`. Everything here writes JSON + Markdown under results/.
"""
from __future__ import annotations

import json
import os
import random
import time
from typing import Any, Callable, Dict, List, Optional

from .ablation import OUTPUT_ONLY
from .baselines import availability, random_plan_builder, EXTERNAL
from .benchmark import bench_options, programs_for, run_benchmark, run_entry
from .faults import FAULTS, get_fault
from .oracle import Config
from .program import get
from .runner import RunOptions, run_program
from .scs import DeriveOptions


def _save(out_dir: Optional[str], name: str, obj: Any) -> None:
    if not out_dir:
        return
    os.makedirs(out_dir, exist_ok=True)
    with open(os.path.join(out_dir, name), "w", encoding="utf-8") as fh:
        if name.endswith(".json"):
            json.dump(obj, fh, indent=2, default=str)
        else:
            fh.write(obj)


# --------------------------------------------------------------------------
# RQ2: comparison with existing tools
# --------------------------------------------------------------------------

def rq2_baselines(backend: str = "eager", budget: int = 8, external_dir: Optional[str] = None,
                  log: Callable[[str], None] = print, out_dir: Optional[str] = None,
                  random_seeds: int = 3, nnsmith_models: int = 8) -> Dict[str, Any]:
    from . import corpus  # noqa: F401
    log("\nRQ2: same budget, same harness, same oracle\n" + "=" * 76)
    rows: Dict[str, Any] = {}
    # B1 random (several seeds, output-only oracle as a plain differential tester would use)
    rand = []
    for s in range(random_seeds):
        r = run_benchmark(backend=backend, budget=budget, reruns=0, check_fixed=(s == 0), log=lambda x: None,
                          plan_builder=random_plan_builder(budget, seed=s, sequences=True, oracles=OUTPUT_ONLY, level="B1"),
                          oracles=OUTPUT_ONLY, level="B1", max_contexts=budget)
        rand.append(r)
    rows["B1_random"] = _agg(rand)
    log(f"  B1 Random       detected {rows['B1_random']['detected']}/{rows['B1_random']['faults']}  "
        f"tests {rows['B1_random']['tests_executed']}  TTF {rows['B1_random']['mean_ttf_s']}s")
    # B1' random with the full oracle set: isolates the oracle contribution from the generator's
    rand_full = run_benchmark(backend=backend, budget=budget, reruns=0, check_fixed=False, log=lambda x: None,
                              plan_builder=random_plan_builder(budget, seed=0, sequences=True, level="B1+oracles"),
                              level="B1+oracles", max_contexts=budget)
    rows["B1_random_full_oracle"] = _agg([rand_full])
    log(f"  B1 Random+O1-7  detected {rand_full['detected']}/{rand_full['faults']}  tests {rand_full['tests_executed']}")
    # B5 ours
    ours = run_benchmark(backend=backend, budget=budget, reruns=0, check_fixed=True, log=lambda x: None,
                         level="FULL", max_contexts=budget)
    rows["B5_ours"] = _agg([ours])
    log(f"  B5 Ours         detected {ours['detected']}/{ours['faults']}  tests {ours['tests_executed']}  "
        f"TTF {ours['mean_ttf_s']}s  FP(fixed) {ours['false_positives_on_fixed']}")
    # external tools: availability + Setting B on their generated programs, if provided
    ext = availability()
    rows["external_tools"] = ext
    for t in ext:
        log(f"  {t['tool']:<10} ({t['venue']}): {'available' if t['available'] else 'not installed'} - {t['hint']}")
    # B3 NNSmith, driven programmatically when importable: its models, its single input,
    # our oracle and our injected faults (Setting B), plus the same models with our contexts
    if EXTERNAL["nnsmith"].available():
        from .baselines import nnsmith_programs
        ps, rej = nnsmith_programs(n=nnsmith_models, seed=0)
        log(f"  B3 NNSmith: {len(ps)} model(s) generated, {len(rej)} rejected")
        if ps:
            native = _external_bench(ps, backend, budget, native=True)
            rows["B3_nnsmith_native"] = native
            log(f"  B3 NNSmith(native input) detected {native['detected']}/{native['faults']}  tests {native['tests_executed']}")
            # NNSmith graphs compile slowly (many frames); keep this leg bounded
            ours_ctx = _external_bench(ps[:max(2, nnsmith_models // 2)], backend, min(budget, 8), native=False,
                                       time_budget_s=60.0)
            rows["B3_nnsmith_plus_our_contexts"] = ours_ctx
            log(f"  B3 NNSmith+our contexts   detected {ours_ctx['detected']}/{ours_ctx['faults']}  tests {ours_ctx['tests_executed']}")
    if external_dir:
        from .seeds import programs_from_dir
        ps, rejected = programs_from_dir(external_dir)
        log(f"  Setting B: {len(ps)} external program(s) loaded from {external_dir}, {len(rejected)} rejected")
        setting_b = []
        for p in ps:
            r = run_program(p, RunOptions(backend=backend, test_budget=budget, reruns=1), Config())
            setting_b.append(r.as_dict())
            log(f"    {p.name:<28} {len(r.failures)} failure(s) in {r.tests_executed} tests")
        rows["setting_b_external"] = setting_b
    # metrics of section 25 RQ2
    gens = [k for k in ("B1_random", "B1_random_full_oracle", "B3_nnsmith_native",
                        "B3_nnsmith_plus_our_contexts", "B5_ours") if k in rows]
    for k in gens:
        r = rows[k]
        r["BugDetectionRate"] = r["recall"]
        r["TestEfficiency"] = round(r["unique_failures"] / max(1, r["tests_executed"]), 4)
        r["TTF"] = r["mean_ttf_s"]
    _save(out_dir, "rq2_baselines.json", rows)
    md = ["# RQ2 baselines", "", f"backend {backend}, budget {budget} tests/program, {random_seeds} random seeds", "",
          "| generator | bugs found | unique failure clusters | tests | valid rate | TTF (s) | FP(fixed) | BugDetectionRate | TestEfficiency |",
          "|---|---:|---:|---:|---:|---:|---:|---:|---:|"]
    for k in gens:
        r = rows[k]
        md.append(f"| {k} | {r['detected']}/{r['faults']} | {r['unique_failures']} | {r['tests_executed']} | "
                  f"{r['valid_rate']} | {r['mean_ttf_s']} | {r['false_positives_on_fixed']} | {r['BugDetectionRate']} | "
                  f"{r['TestEfficiency']} |")
    md += ["", "External tools (Setting A needs the tool's own runner; Setting B loads their outputs with --external DIR):", ""]
    for t in ext:
        md.append(f"- {t['tool']} ({t['venue']}): {'available' if t['available'] else 'not installed'} - {t['hint']}")
    _save(out_dir, "RQ2.md", "\n".join(md) + "\n")
    return rows


def _external_bench(programs, backend: str, budget: int, native: bool,
                    time_budget_s: float = 0.0) -> Dict[str, Any]:
    """Run every injected fault over externally generated programs.

    ``native``: one context (the tool's own input), cold eager-vs-compiled, all
    oracles. Otherwise our context generator and sequences are applied to the
    foreign programs under the same budget.
    """
    from .benchmark import Entry, bench_options, run_entry, summarize
    from .faults import FAULTS
    from .generate import TestPlan
    from .scs import SCS
    entries: List[Entry] = []

    def single(program):
        from .factors import analyze
        a = analyze(program.fn, program.get_source())
        return TestPlan(program.name, a, SCS(site=a.function, params=a.params), [], [program.base_context],
                        [], [], list(OUTPUT_ONLY) + ["mutation", "alias", "gradient"], level="native")

    for f in FAULTS:
        for p in programs:
            opts = bench_options(f, backend, 1 if native else budget, 0, None, single if native else None,
                                 None, "native" if native else "FULL", do_matrix=not native,
                                 max_contexts=budget)
            opts.time_budget_s = time_budget_s
            entries.append(run_entry(f, p, opts))
    res = summarize(entries, [], FAULTS, backend, budget, "native" if native else "FULL+external", 0.0)
    r = _agg([res])
    r["programs"] = [p.name for p in programs]
    return r


def _agg(runs: List[Dict[str, Any]]) -> Dict[str, Any]:
    n = len(runs)
    det = sum(r["detected"] for r in runs) / n
    tests = sum(r["tests_executed"] for r in runs) / n
    inval = sum(r["tests_invalid"] for r in runs) / n
    ttf = [r["mean_ttf_s"] for r in runs if r["mean_ttf_s"] is not None]
    uniq = sum(len({(e["fault"], e["stage"], tuple(e["kinds"])) for e in r["entries"] if e["detected"]})
               for r in runs) / n
    return {"faults": runs[0]["faults"], "detected": round(det, 2), "recall": round(det / runs[0]["faults"], 3),
            "tests_executed": round(tests, 1), "tests_invalid": round(inval, 1),
            "valid_rate": round(1 - inval / max(1.0, tests + inval), 3),
            "mean_ttf_s": round(sum(ttf) / len(ttf), 2) if ttf else None,
            "unique_failures": round(uniq, 1),
            "false_positives_on_fixed": runs[0].get("false_positives_on_fixed", 0),
            "per_category": runs[0]["per_category"], "runs": n}


# --------------------------------------------------------------------------
# RQ4: cache / specialization detection
# --------------------------------------------------------------------------

def rq4_cache(backend: str = "eager", budget: int = 8, log: Callable[[str], None] = print,
              out_dir: Optional[str] = None) -> Dict[str, Any]:
    from . import corpus  # noqa: F401
    cache_faults = [f for f in FAULTS if f.needs_sequence]
    log("\nRQ4: cache / specialization detection\n" + "=" * 76)
    settings = {
        "ordinary_eager_vs_compiled": dict(derive=DeriveOptions(cache_sequence=False), do_matrix=False),
        "random_sequence": dict(plan_builder=random_plan_builder(budget, seed=0, sequences=True, level="random-seq"),
                                do_matrix=True),
        "scs_guided_sequence": dict(derive=DeriveOptions(), do_matrix=True),
    }
    out: Dict[str, Any] = {"faults": [f.id for f in cache_faults], "settings": {}}
    for name, kw in settings.items():
        r = run_benchmark(backend=backend, budget=budget, reruns=0, check_fixed=False, log=lambda x: None,
                          faults=cache_faults, level=name, max_contexts=budget, **kw)
        recomp = {}
        for e in r["entries"]:
            if e["detected"]:
                recomp[f"{e['fault']}/{e['program']}"] = {"probe": e["probe"], "warm_only": e["warm_only"],
                                                          "tests_to_trigger": e["tests_to_detect"]}
        out["settings"][name] = {"detected": r["detected"], "faults": r["faults"],
                                 "warm_only_failures": r["warm_only_detections"],
                                 "mean_tests_to_trigger": r["mean_tests_to_detect"],
                                 "tests": r["tests_executed"], "per_category": r["per_category"],
                                 "detected_by_fault": r["detected_by_fault"], "detail": recomp}
        log(f"  {name:<28} known cache bugs {r['detected']}/{r['faults']}  warm-only {r['warm_only_detections']}  "
            f"tests-to-trigger {r['mean_tests_to_detect']}  tests {r['tests_executed']}")
    # the switch table of section 15 on the real compiler: recompile behaviour per factor
    from .execute import TorchCompiler, execution_matrix
    from .generate import build_plan
    from .localize import triage_matrix
    table = []
    for pn in ("dtype_reduce", "python_flag_semantic", "requires_grad_switch", "stride_read", "shape_boundary"):
        p = get(pn)
        plan = build_plan(p, max_contexts=8)
        warm_pairs = [(a, b) for a, b in plan.pairs if a is plan.contexts[0] and b.warm]
        for a, b in warm_pairs[:6]:
            try:
                m = execution_matrix(p, a, b, TorchCompiler(backend), return_trip=True)
            except Exception as e:  # noqa: BLE001
                table.append({"program": pn, "A": a.name, "B": b.name, "error": str(e)[:80]})
                continue
            tri, v = triage_matrix(m, Config())
            table.append({"program": pn, "A": a.name, "B": b.name, "factor": v.factor,
                          "recompiled_A_to_B": v.recompiled_on_switch, "recompiled_B_to_A": v.recompiled_on_return,
                          "cold_vs_warm_differs": v.cold_vs_warm.differs,
                          "return_trip_differs": bool(v.return_trip and v.return_trip.differs),
                          "verdict": tri.stage})
    out["real_compiler_switch_table"] = table
    _save(out_dir, "rq4_cache.json", out)
    md = ["# RQ4 cache / specialization", "", "| setting | known cache bugs detected | warm-only failures | mean tests-to-trigger | tests |",
          "|---|---:|---:|---:|---:|"]
    for name, r in out["settings"].items():
        md.append(f"| {name} | {r['detected']}/{r['faults']} | {r['warm_only_failures']} | {r['mean_tests_to_trigger']} | {r['tests']} |")
    md += ["", "## recompile / cache behaviour of the real compiler (section 15 switch table)", "",
           "| program | A | B | factor | recompile A->B | recompile B->A | cold vs warm | A->B->A | verdict |",
           "|---|---|---|---|---|---|---|---|---|"]
    for t in table:
        if "error" in t:
            md.append(f"| {t['program']} | {t['A']} | {t['B']} | error: {t['error']} | | | | | |")
        else:
            md.append(f"| {t['program']} | {t['A']} | {t['B']} | {t['factor']} | {t['recompiled_A_to_B']} | "
                      f"{t['recompiled_B_to_A']} | {t['cold_vs_warm_differs']} | {t['return_trip_differs']} | {t['verdict']} |")
    _save(out_dir, "RQ4.md", "\n".join(md) + "\n")
    return out


# --------------------------------------------------------------------------
# experiments A-E
# --------------------------------------------------------------------------

def _ttd(fault_id: str, program: str, backend: str, budget: int, plan_builder=None, derive=None,
         oracles=None, do_matrix=True, do_layered=True) -> Dict[str, Any]:
    f = get_fault(fault_id)
    p = get(program)
    opts = bench_options(f, backend, budget, 0, derive, plan_builder, oracles, do_matrix=do_matrix,
                         do_layered=do_layered, max_contexts=budget)
    e = run_entry(f, p, opts)
    return {"detected": e.detected, "tests_to_detect": e.tests_to_detect, "tests": e.tests_executed,
            "stage": e.stage, "kinds": e.kinds, "probe": e.probe, "ttf_s": e.ttf_s}


def experiment_a(backend: str, budget: int, seeds: int = 5) -> Dict[str, Any]:
    """Shape boundary: who reaches k-1 / k / k+1 first?"""
    out: Dict[str, Any] = {"question": "x.shape[0] >= 32: tests to trigger a fault at 31 / 32 / 33-tail"}
    for fid in ("codegen_boundary_31", "codegen_boundary_32", "codegen_mod16_tail"):
        ours = _ttd(fid, "shape_boundary", backend, budget)
        rnd = [_ttd(fid, "shape_boundary", backend, budget,
                    plan_builder=random_plan_builder(budget, seed=s, sequences=False, oracles=OUTPUT_ONLY, level="random"),
                    oracles=OUTPUT_ONLY, do_matrix=False) for s in range(seeds)]
        det = [r for r in rnd if r["detected"]]
        out[fid] = {"ours": ours, "random": {"detected": f"{len(det)}/{seeds}",
                                             "mean_tests_to_detect": round(sum(r['tests_to_detect'] for r in det) / len(det), 1) if det else None,
                                             "runs": rnd}}
    return out


def experiment_b(backend: str, budget: int) -> Dict[str, Any]:
    """dtype specialization: cold vs warm on the same program."""
    cold = _ttd("underspec_dtype", "dtype_reduce", backend, budget, derive=DeriveOptions(cache_sequence=False), do_matrix=False)
    warm = _ttd("underspec_dtype", "dtype_reduce", backend, budget)
    ret = _ttd("cache_stale_on_return", "dtype_reduce", backend, budget)
    return {"question": "float16 <-> float32 with everything else fixed: cold vs warm",
            "cold_only": cold, "cold_plus_warm": warm, "return_trip": ret}


def experiment_c(backend: str, budget: int) -> Dict[str, Any]:
    """Control flow: is the T/T, T/F, F/T, F/F table covered?"""
    from .execute import build_inputs
    from .generate import build_plan
    p = get("flag_and_shape")
    plan = build_plan(p, max_contexts=budget)
    covered = set()
    for c in plan.contexts:
        try:
            x, flag = build_inputs(p, c)
        except Exception:
            continue
        covered.add(("T" if flag else "F") + "/" + ("T" if x.shape[0] > 32 else "F"))
    rnd = set()
    for c in random_plan_builder(budget, seed=0)(p).contexts:
        try:
            x, flag = build_inputs(p, c)
        except Exception:
            continue
        if not hasattr(x, "shape"):
            continue
        rnd.add(("T" if flag else "F") + "/" + ("T" if x.shape[0] > 32 else "F"))
    return {"question": "flag and x.shape[0] > 32: which of T/T, T/F, F/T, F/F are executed",
            "ours": sorted(covered), "ours_contexts": [c.name for c in plan.contexts],
            "random": sorted(rnd), "complete": sorted(covered) == ["F/F", "F/T", "T/F", "T/T"]}


def experiment_d(backend: str, budget: int) -> Dict[str, Any]:
    """Alias / mutation: output-only oracle vs mutation/alias oracle."""
    out: Dict[str, Any] = {"question": "same tests, output-only oracle vs mutation/alias oracle"}
    for fid, pn in (("functionalize_drop_mutation", "view_inplace"), ("functionalize_drop_mutation", "overlapping_views"),
                    ("functionalize_alias_to_copy", "alias_returned"), ("functionalize_drop_mutation", "noncontig_copy")):
        out[f"{fid}/{pn}"] = {"output_only": _ttd(fid, pn, backend, budget, oracles=OUTPUT_ONLY, do_matrix=False),
                              "mutation_alias": _ttd(fid, pn, backend, budget, do_matrix=False)}
    return out


def experiment_e(backend: str, budget: int) -> Dict[str, Any]:
    """Cache context switch: A -> B versus reset -> B."""
    from .execute import execution_matrix
    from .faults import faulty_compiler
    from .localize import triage_matrix
    from .program import Context
    p = get("dtype_reduce")
    a, b = Context("fp16", {"dtype": "float16"}), Context("fp32", {"dtype": "float32"})
    rows = []
    for fid in (None, "underspec_dtype", "cache_stale_on_return", "cache_result_memo"):
        m = execution_matrix(p, a, b, faulty_compiler(fid, backend))
        tri, v = triage_matrix(m, Config())
        rows.append({"compiler": fid or "real", "A->B differs from reset->B": v.cold_vs_warm.differs,
                     "recompiled": v.recompiled_on_switch, "eager_vs_cold": bool(v.eager_vs_cold and v.eager_vs_cold.differs),
                     "eager_vs_warm": bool(v.eager_vs_warm and v.eager_vs_warm.differs),
                     "A->B->A differs": bool(v.return_trip and v.return_trip.differs), "verdict": tri.stage})
    return {"question": "compile(A) -> B  vs  reset -> B; if different, localise cache/guard behaviour", "rows": rows}


def run_experiments(only: Optional[List[str]] = None, backend: str = "eager", budget: int = 8,
                    log: Callable[[str], None] = print, out_dir: Optional[str] = None) -> Dict[str, Any]:
    from . import corpus  # noqa: F401
    exps = {"A": experiment_a, "B": experiment_b, "C": experiment_c, "D": experiment_d, "E": experiment_e}
    res: Dict[str, Any] = {}
    md = ["# Experiments A-E", "", f"backend {backend}, budget {budget}", ""]
    for k, fn in exps.items():
        if only and k not in only:
            continue
        t0 = time.perf_counter()
        log(f"\nExperiment {k}: {fn.__doc__.strip()}")
        try:
            r = fn(backend, budget)
        except Exception as e:  # noqa: BLE001
            r = {"error": f"{type(e).__name__}: {e}"}
        r["wall_s"] = round(time.perf_counter() - t0, 1)
        res[k] = r
        log(json.dumps({kk: vv for kk, vv in r.items() if kk not in ("ours_contexts",)}, indent=1, default=str)[:1500])
        md += [f"## Experiment {k}: {fn.__doc__.strip()}", "", "```json",
               json.dumps(r, indent=1, default=str), "```", ""]
    _save(out_dir, "experiments.json", res)
    _save(out_dir, "EXPERIMENTS.md", "\n".join(md))
    return res
