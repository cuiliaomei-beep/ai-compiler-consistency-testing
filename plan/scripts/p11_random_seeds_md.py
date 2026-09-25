"""Render results/p11_baselines/random_seeds.md from random_seeds_summary.json (numbers are never typed by hand).

    python scripts/p11_random_seeds_md.py --dir results/p11_baselines
"""
from __future__ import annotations

import argparse
import json
import os
import sys

sys.path.insert(0, os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
from tcc.faults import FAULTS  # noqa: E402


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--dir", default="results/p11_baselines")
    ap.add_argument("--extra", default=None, help="markdown file appended verbatim (notes)")
    args = ap.parse_args()
    S = json.load(open(os.path.join(args.dir, "random_seeds_summary.json"), encoding="utf-8"))
    env = None
    for cand in ("random_seeds_summary_run0.json",):
        p = os.path.join(args.dir, cand)
        if os.path.exists(p):
            env = json.load(open(p, encoding="utf-8")).get("env")
    rows, st, pf = S["rows"], S["stats"], S["per_fault"]
    L = ["# Random baseline (B1): per-seed results", "",
         "Setting: identical to the `B1_random` leg of `tcc.experiments.rq2_baselines` that produced `results/RQ2.md` "
         "(`random_plan_builder(budget=12, seed=s, sequences=True, oracles=OUTPUT_ONLY, level=\"B1\")`, backend `eager`, "
         "12 tests per program, all 19 injected faults of `tcc/faults.py`, `check_fixed=False`). "
         "Seeds 0-2 are the three seeds whose mean the paper reports; seeds 3-9 are new. "
         "Script: `scripts/p11_random_seeds.py`; per-seed JSON: `random_seed<N>.json` (seeds 0-4 here, 5-9 in `seeds5to9/`).",
         "", "## Per seed", "",
         "| seed | faults detected (of 19) | tests executed | invalid tests | invalid rate | unique failure clusters | mean TTF (s) | mean tests-to-detect | wall (s) |",
         "|---:|---:|---:|---:|---:|---:|---:|---:|---:|"]
    for r in rows:
        L.append(f"| {r['seed']} | {r['detected']} | {r['tests_executed']} | {r['tests_invalid']} | {r['invalid_rate']:.3f} | "
                 f"{r['unique_failure_clusters']} | {r['mean_ttf_s']} | {r['mean_tests_to_detect']} | {r['wall_s']} |")
    d = st["detected"]
    L += ["", "## Statistics over the seeds", "",
          "| quantity | n | mean | median | min | max | std (sample) |", "|---|---:|---:|---:|---:|---:|---:|"]
    for key, label in (("detected", "faults detected"), ("tests_executed", "tests executed"), ("tests_invalid", "invalid tests"),
                       ("invalid_rate", "invalid rate"), ("unique_failure_clusters", "unique failure clusters"), ("wall_s", "wall time (s)")):
        v = st[key]
        L.append(f"| {label} | {st['n_seeds']} | {v['mean']} | {v['median']} | {v['min']} | {v['max']} | {v['stdev']} |")
    L += ["", f"Mean over seeds 0-2 (the paper's three seeds): **{st['detected_first3_mean']}** faults detected.",
          f"Mean over all {st['n_seeds']} seeds: **{d['mean']}** (median {d['median']}, min {d['min']}, max {d['max']}, sd {d['stdev']}).", ""]
    L += ["## Per fault: detection frequency and time to first detection", "",
          "`ttd` = tests executed on that fault's programs (in `programs_for(fault)` order) up to and including the first detecting test; "
          "`ttf` = wall seconds over the same span. Statistics are over the seeds that detected the fault.", "",
          "| fault | category | detected in seeds | ttd mean | ttd median | ttd min | ttd max | ttf mean (s) | ttf max (s) | detecting programs |",
          "|---|---|---:|---:|---:|---:|---:|---:|---:|---|"]
    for f in FAULTS:
        v = pf[f.id]
        t = v["tests_to_detect_cumulative_over_fault_programs"]
        w = v["ttf_s_cumulative"]
        L.append(f"| {f.id} | {f.category} | {v['detected_in_seeds']}/{v['of']} | "
                 + (f"{t['mean']} | {t['median']} | {t['min']} | {t['max']} | {w['mean']} | {w['max']} | " if t else "- | - | - | - | - | - | ")
                 + f"{', '.join(v['programs_that_detected']) or '-'} |")
    never = [f.id for f in FAULTS if pf[f.id]["detected_in_seeds"] == 0]
    always = [f.id for f in FAULTS if pf[f.id]["detected_in_seeds"] == pf[f.id]["of"]]
    L += ["", f"Never detected by Random in any seed ({len(never)}): {', '.join(never)}.",
          f"Detected in every seed ({len(always)}): {', '.join(always)}.", ""]
    if args.extra and os.path.exists(args.extra):
        L += ["", open(args.extra, encoding="utf-8").read()]
    open(os.path.join(args.dir, "random_seeds.md"), "w", encoding="utf-8").write("\n".join(L) + "\n")
    print("\n".join(L[:40]))


if __name__ == "__main__":
    main()
