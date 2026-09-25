"""P11-1: per-seed results of the Random baseline (B1) on the injected-fault benchmark.

Re-runs exactly the B1 leg of ``tcc.experiments.rq2_baselines`` (random_plan_builder with the
output-only oracle, level "B1", budget 12 tests/program, backend eager) for several seeds and
saves what ``_agg`` throws away: per-seed detections (fault ids), tests, invalid tests, wall
time and time-to-first-detection per fault.

Usage: python scripts/p11_random_seeds.py --seeds 5 --budget 12 --out results/p11_baselines
"""
from __future__ import annotations

import argparse
import json
import os
import platform
import statistics
import sys
import time

sys.path.insert(0, os.path.dirname(os.path.dirname(os.path.abspath(__file__))))

from tcc import corpus  # noqa: F401,E402
from tcc.ablation import OUTPUT_ONLY  # noqa: E402
from tcc.baselines import random_plan_builder  # noqa: E402
from tcc.benchmark import run_benchmark  # noqa: E402
from tcc.faults import FAULTS  # noqa: E402


def per_fault_ttd(res):
    """For each fault: first detecting entry (entries are in programs_for(fault) order)."""
    out = {}
    cum = {}
    for e in res["entries"]:
        fid = e["fault"]
        c = cum.setdefault(fid, {"tests_before": 0, "wall_before": 0.0})
        if fid not in out:
            out[fid] = {"detected": False, "program": None, "tests_to_detect_in_program": None,
                        "tests_to_detect_cumulative": None, "ttf_s_in_program": None,
                        "ttf_s_cumulative": None, "stage": None, "kinds": None}
        if e["detected"] and not out[fid]["detected"]:
            out[fid].update({"detected": True, "program": e["program"],
                             "tests_to_detect_in_program": e["tests_to_detect"],
                             "tests_to_detect_cumulative": c["tests_before"] + (e["tests_to_detect"] or 0),
                             "ttf_s_in_program": e["ttf_s"],
                             "ttf_s_cumulative": round(c["wall_before"] + (e["ttf_s"] or 0.0), 3),
                             "stage": e["stage"], "kinds": e["kinds"]})
        c["tests_before"] += e["tests_executed"]
        c["wall_before"] += e["wall_s"]
    return out


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--seeds", type=int, default=5)
    ap.add_argument("--first-seed", type=int, default=0)
    ap.add_argument("--budget", type=int, default=12)
    ap.add_argument("--backend", default="eager")
    ap.add_argument("--out", default="results/p11_baselines")
    ap.add_argument("--check-fixed", action="store_true", help="also run the fixed (real) compiler per seed")
    args = ap.parse_args()
    os.makedirs(args.out, exist_ok=True)
    import torch
    env = {"python": sys.version, "torch": torch.__version__, "platform": platform.platform(),
           "machine": platform.machine(), "cpu_count": os.cpu_count(), "date": time.strftime("%Y-%m-%d %H:%M:%S")}
    rows = []
    for s in range(args.first_seed, args.first_seed + args.seeds):
        t0 = time.perf_counter()
        pb = random_plan_builder(args.budget, seed=s, sequences=True, oracles=OUTPUT_ONLY, level="B1")
        res = run_benchmark(backend=args.backend, budget=args.budget, reruns=0, check_fixed=args.check_fixed,
                            log=lambda x: None, plan_builder=pb, oracles=OUTPUT_ONLY, level="B1",
                            max_contexts=args.budget)
        wall = time.perf_counter() - t0
        res["seed"] = s
        res["wall_s_total"] = round(wall, 1)
        res["per_fault"] = per_fault_ttd(res)
        with open(os.path.join(args.out, f"random_seed{s}.json"), "w", encoding="utf-8") as fh:
            json.dump(res, fh, indent=1, default=str)
        det = [fid for fid, v in res["detected_by_fault"].items() if v]
        uniq = len({(e["fault"], e["stage"], tuple(e["kinds"])) for e in res["entries"] if e["detected"]})
        row = {"seed": s, "detected": res["detected"], "faults": res["faults"], "detected_ids": det,
               "missed_ids": [f.id for f in FAULTS if f.id not in det],
               "tests_executed": res["tests_executed"], "tests_invalid": res["tests_invalid"],
               "invalid_rate": round(res["tests_invalid"] / max(1, res["tests_executed"] + res["tests_invalid"]), 4),
               "compiles": res["compiles"], "wall_s": round(wall, 1),
               "wall_s_entries": round(sum(e["wall_s"] for e in res["entries"]), 1),
               "mean_ttf_s": res["mean_ttf_s"], "mean_tests_to_detect": res["mean_tests_to_detect"],
               "unique_failure_clusters": uniq,
               "false_positives_on_fixed": res["false_positives_on_fixed"] if args.check_fixed else None}
        rows.append(row)
        print(f"seed {s}: detected {res['detected']}/{res['faults']} tests {res['tests_executed']} "
              f"invalid {res['tests_invalid']} wall {wall:.1f}s  missed: {', '.join(row['missed_ids'])}", flush=True)
    dets = [r["detected"] for r in rows]
    stats = {"n_seeds": len(rows), "mean": statistics.mean(dets), "median": statistics.median(dets),
             "min": min(dets), "max": max(dets),
             "stdev": statistics.stdev(dets) if len(dets) > 1 else 0.0,
             "mean_tests": statistics.mean(r["tests_executed"] for r in rows),
             "mean_invalid": statistics.mean(r["tests_invalid"] for r in rows),
             "mean_invalid_rate": statistics.mean(r["invalid_rate"] for r in rows),
             "mean_wall_s": statistics.mean(r["wall_s"] for r in rows),
             "mean_first3": statistics.mean(dets[:3]) if len(dets) >= 3 else None}
    # per-fault detection frequency across seeds
    freq = {}
    for f in FAULTS:
        hits = [r for r in rows if f.id in r["detected_ids"]]
        freq[f.id] = {"category": f.category, "detected_in_seeds": len(hits), "of": len(rows)}
    with open(os.path.join(args.out, "random_seeds_summary.json"), "w", encoding="utf-8") as fh:
        json.dump({"env": env, "budget": args.budget, "backend": args.backend, "oracle": list(OUTPUT_ONLY),
                   "rows": rows, "stats": stats, "per_fault_frequency": freq}, fh, indent=1, default=str)
    # CSV
    fids = [f.id for f in FAULTS]
    with open(os.path.join(args.out, "random_seeds.csv"), "w", encoding="utf-8", newline="") as fh:
        fh.write("seed,detected,faults,tests_executed,tests_invalid,invalid_rate,compiles,wall_s,mean_ttf_s,"
                 "mean_tests_to_detect,unique_failure_clusters," + ",".join(fids) + "\n")
        for r in rows:
            fh.write(f"{r['seed']},{r['detected']},{r['faults']},{r['tests_executed']},{r['tests_invalid']},"
                     f"{r['invalid_rate']},{r['compiles']},{r['wall_s']},{r['mean_ttf_s']},{r['mean_tests_to_detect']},"
                     f"{r['unique_failure_clusters']}," + ",".join("1" if f in r["detected_ids"] else "0" for f in fids) + "\n")
    print(json.dumps(stats, indent=1))


if __name__ == "__main__":
    main()
