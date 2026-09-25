"""P11-1: per-seed results of the NNSmith baseline (B3, native input) on the injected-fault benchmark.

Re-runs the ``B3_nnsmith_native`` leg of ``tcc.experiments.rq2_baselines`` (8 NNSmith models, the tool's
own single input, cold eager-vs-compiled, all oracles, every injected fault) for several model seeds.
``rq2_baselines`` used seed 0 only.

    python scripts/p11_nnsmith_seeds.py --seeds 3 --models 8 --budget 12 --out results/p11_baselines
"""
from __future__ import annotations

import argparse
import json
import os
import statistics
import sys
import time

sys.path.insert(0, os.path.dirname(os.path.dirname(os.path.abspath(__file__))))

from tcc import corpus  # noqa: F401,E402
from tcc.baselines import nnsmith_programs  # noqa: E402
from tcc.experiments import _external_bench  # noqa: E402
from tcc.faults import FAULTS  # noqa: E402


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--seeds", type=int, default=3)
    ap.add_argument("--first-seed", type=int, default=0)
    ap.add_argument("--models", type=int, default=8)
    ap.add_argument("--budget", type=int, default=12)
    ap.add_argument("--backend", default="eager")
    ap.add_argument("--out", default="results/p11_baselines")
    args = ap.parse_args()
    os.makedirs(args.out, exist_ok=True)
    rows = []
    for s in range(args.first_seed, args.first_seed + args.seeds):
        t0 = time.perf_counter()
        ps, rej = nnsmith_programs(n=args.models, seed=s)
        gen_wall = time.perf_counter() - t0
        if not ps:
            print(f"seed {s}: no programs ({rej})", flush=True)
            continue
        t1 = time.perf_counter()
        res = _external_bench(ps, args.backend, args.budget, native=True)
        wall = time.perf_counter() - t1
        res["seed"] = s
        res["generation_wall_s"] = round(gen_wall, 1)
        res["bench_wall_s"] = round(wall, 1)
        res["rejected"] = rej
        res["program_notes"] = [p.notes for p in ps]
        with open(os.path.join(args.out, f"nnsmith_native_seed{s}.json"), "w", encoding="utf-8") as fh:
            json.dump(res, fh, indent=1, default=str)
        det = [f for f, v in res.get("detected_by_fault", {}).items() if v] if "detected_by_fault" in res else None
        row = {"seed": s, "models": len(ps), "rejected": len(rej), "detected": res["detected"], "faults": res["faults"],
               "detected_ids": det, "tests_executed": res["tests_executed"], "tests_invalid": res["tests_invalid"],
               "mean_ttf_s": res["mean_ttf_s"], "unique_failures": res["unique_failures"],
               "generation_wall_s": round(gen_wall, 1), "bench_wall_s": round(wall, 1)}
        rows.append(row)
        print(f"seed {s}: {len(ps)} models, detected {res['detected']}/{res['faults']} tests {res['tests_executed']} "
              f"invalid {res['tests_invalid']} gen {gen_wall:.1f}s bench {wall:.1f}s", flush=True)
    dets = [r["detected"] for r in rows]
    stats = {"n_seeds": len(rows), "mean": statistics.mean(dets) if dets else None,
             "median": statistics.median(dets) if dets else None, "min": min(dets) if dets else None,
             "max": max(dets) if dets else None, "stdev": statistics.stdev(dets) if len(dets) > 1 else 0.0}
    with open(os.path.join(args.out, "nnsmith_seeds_summary.json"), "w", encoding="utf-8") as fh:
        json.dump({"rows": rows, "stats": stats, "models_per_seed": args.models, "budget": args.budget,
                   "backend": args.backend}, fh, indent=1, default=str)
    print(json.dumps(stats, indent=1))


if __name__ == "__main__":
    main()
