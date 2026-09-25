"""P11-1: merge per-seed Random-baseline JSONs (random_seed<N>.json) into one CSV / Markdown / summary.

    python scripts/p11_merge_random_seeds.py results/p11_baselines results/p11_baselines/seeds5to9 --out results/p11_baselines
"""
from __future__ import annotations

import argparse
import glob
import json
import os
import statistics
import sys

sys.path.insert(0, os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
from tcc.faults import FAULTS  # noqa: E402


def load(dirs):
    runs = {}
    for d in dirs:
        for p in glob.glob(os.path.join(d, "random_seed[0-9]*.json")):
            r = json.load(open(p, encoding="utf-8"))
            runs[r["seed"]] = (r, p)
    return [runs[s] for s in sorted(runs)]


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("dirs", nargs="+")
    ap.add_argument("--out", required=True)
    args = ap.parse_args()
    runs = load(args.dirs)
    fids = [f.id for f in FAULTS]
    rows = []
    for res, path in runs:
        det = [fid for fid, v in res["detected_by_fault"].items() if v]
        uniq = len({(e["fault"], e["stage"], tuple(e["kinds"])) for e in res["entries"] if e["detected"]})
        rows.append({"seed": res["seed"], "detected": res["detected"], "faults": res["faults"], "detected_ids": det,
                     "tests_executed": res["tests_executed"], "tests_invalid": res["tests_invalid"],
                     "invalid_rate": round(res["tests_invalid"] / (res["tests_executed"] + res["tests_invalid"]), 4),
                     "compiles": res["compiles"], "wall_s": res["wall_s_total"],
                     "mean_ttf_s": res["mean_ttf_s"], "mean_tests_to_detect": res["mean_tests_to_detect"],
                     "unique_failure_clusters": uniq, "per_fault": res["per_fault"], "file": os.path.relpath(path, args.out)})
    dets = [r["detected"] for r in rows]

    def st(xs):
        return {"mean": round(statistics.mean(xs), 3), "median": statistics.median(xs), "min": min(xs), "max": max(xs),
                "stdev": round(statistics.stdev(xs), 3) if len(xs) > 1 else 0.0}
    stats = {"n_seeds": len(rows), "seeds": [r["seed"] for r in rows], "detected": st(dets),
             "detected_first3_mean": round(statistics.mean(dets[:3]), 3) if len(dets) >= 3 else None,
             "tests_executed": st([r["tests_executed"] for r in rows]),
             "tests_invalid": st([r["tests_invalid"] for r in rows]),
             "invalid_rate": st([r["invalid_rate"] for r in rows]),
             "wall_s": st([r["wall_s"] for r in rows]),
             "unique_failure_clusters": st([r["unique_failure_clusters"] for r in rows]),
             "mean_ttf_s_per_seed": [r["mean_ttf_s"] for r in rows]}
    # per fault: detection frequency and time-to-first-detection statistics over the seeds that detected it
    per_fault = {}
    for f in FAULTS:
        hits = [r["per_fault"][f.id] for r in rows if r["per_fault"].get(f.id, {}).get("detected")]
        ttd_prog = [h["tests_to_detect_in_program"] for h in hits if h["tests_to_detect_in_program"] is not None]
        ttd_cum = [h["tests_to_detect_cumulative"] for h in hits if h["tests_to_detect_cumulative"] is not None]
        ttf_cum = [h["ttf_s_cumulative"] for h in hits if h["ttf_s_cumulative"] is not None]
        per_fault[f.id] = {"category": f.category, "detected_in_seeds": len(hits), "of": len(rows),
                           "programs_that_detected": sorted({h["program"] for h in hits}),
                           "tests_to_detect_in_program": st(ttd_prog) if ttd_prog else None,
                           "tests_to_detect_cumulative_over_fault_programs": st(ttd_cum) if ttd_cum else None,
                           "ttf_s_cumulative": st(ttf_cum) if ttf_cum else None}
    os.makedirs(args.out, exist_ok=True)
    json.dump({"rows": [{k: v for k, v in r.items() if k != "per_fault"} for r in rows], "stats": stats,
               "per_fault": per_fault}, open(os.path.join(args.out, "random_seeds_summary.json"), "w", encoding="utf-8"),
              indent=1, default=str)
    with open(os.path.join(args.out, "random_seeds.csv"), "w", encoding="utf-8", newline="") as fh:
        fh.write("seed,detected,faults,tests_executed,tests_invalid,invalid_rate,compiles,wall_s,mean_ttf_s,"
                 "mean_tests_to_detect,unique_failure_clusters," + ",".join(fids) + "\n")
        for r in rows:
            fh.write(f"{r['seed']},{r['detected']},{r['faults']},{r['tests_executed']},{r['tests_invalid']},"
                     f"{r['invalid_rate']},{r['compiles']},{r['wall_s']},{r['mean_ttf_s']},{r['mean_tests_to_detect']},"
                     f"{r['unique_failure_clusters']}," + ",".join("1" if f in r["detected_ids"] else "0" for f in fids) + "\n")
    # per-fault TTD csv
    with open(os.path.join(args.out, "random_seeds_per_fault.csv"), "w", encoding="utf-8", newline="") as fh:
        fh.write("fault,category," + ",".join(f"seed{r['seed']}_ttd_cum" for r in rows) + ","
                 + ",".join(f"seed{r['seed']}_ttf_s_cum" for r in rows) + "\n")
        for f in FAULTS:
            cells = []
            for r in rows:
                h = r["per_fault"].get(f.id, {})
                cells.append(str(h.get("tests_to_detect_cumulative")) if h.get("detected") else "")
            cells2 = []
            for r in rows:
                h = r["per_fault"].get(f.id, {})
                cells2.append(str(h.get("ttf_s_cumulative")) if h.get("detected") else "")
            fh.write(f"{f.id},{f.category}," + ",".join(cells) + "," + ",".join(cells2) + "\n")
    print(json.dumps(stats, indent=1))
    print(json.dumps({k: (v["detected_in_seeds"], v["of"]) for k, v in per_fault.items()}, indent=1))


if __name__ == "__main__":
    main()
