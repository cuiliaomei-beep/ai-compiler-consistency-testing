"""Summarise TorchProbe runs (tests.jsonl written by scratchpad/p11/run_temisu.py) into JSON + a Markdown table.

    python scripts/p11_torchprobe_summary.py <tests.jsonl> [<tests.jsonl> ...] --out results/p11_baselines --tag n10
"""
from __future__ import annotations

import argparse
import collections
import json
import os
import statistics


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("jsonl", nargs="+")
    ap.add_argument("--out", required=True)
    ap.add_argument("--tag", required=True)
    args = ap.parse_args()
    rows = []
    for p in args.jsonl:
        with open(p, encoding="utf-8") as fh:
            rows += [json.loads(l) for l in fh if l.strip()]
    seeds = sorted({r["seed"] for r in rows})
    seed_fail = [r for r in rows if r.get("status") == "seed_generation_failed"]
    tests = [r for r in rows if "k" in r]
    by_mut = collections.OrderedDict()
    for m in ("origin", "modify_then_recover", "desolve_op", "insert_tcb", "subfunction"):
        rs = [r for r in tests if r["mutation"] == m]
        by_mut[m] = {
            "tests": len(rs),
            "pass": sum(r["status"] == "pass" for r in rs),
            "inconsistent": sum(r["status"] == "inconsistent" for r in rs),
            "compile_or_run_error": sum(r["status"] == "compile_or_run_error" for r in rs),
            "other_status": collections.Counter(r["status"] for r in rs if r["status"] not in ("pass", "inconsistent", "compile_or_run_error")),
            "eager_valid": sum(r.get("eager_valid") is True for r in rs),
            "eager_invalid": sum(r.get("eager_valid") is False for r in rs),
            "changed_program": sum(1 for r in rs if m != "origin" and r.get("n_lines") is not None),
            "wall_s_sum": round(sum(r.get("wall_s", 0.0) for r in rs), 1),
            "wall_s_median": round(statistics.median([r["wall_s"] for r in rs]), 2) if rs else None,
        }
    # did a mutation actually change the code? compare line counts with the previous test of the same seed
    prev = {}
    unchanged = collections.Counter()
    for r in tests:
        key = r["seed"]
        if r["mutation"] != "origin" and key in prev and r.get("n_lines") == prev[key]:
            unchanged[r["mutation"]] += 1
        prev[key] = r.get("n_lines")
    failures = [{k: r.get(k) for k in ("seed", "k", "mutation", "status", "error", "eager_valid", "eager_error",
                                         "eager_vs_oracle", "maxdiff_compiled_vs_oracle", "compiled_vs_eager_maxdiff")}
                for r in tests if r["status"] != "pass"]
    total_wall = round(sum(r.get("wall_s", 0.0) for r in tests) + sum(r.get("seed_wall_s", 0.0) for r in rows if r.get("k") == 0), 1)
    summ = {"tag": args.tag, "files": args.jsonl, "seeds": len(seeds), "seed_range": [seeds[0], seeds[-1]] if seeds else None,
            "seed_generation_failed": len(seed_fail),
            "tests": len(tests), "pass": sum(r["status"] == "pass" for r in tests),
            "inconsistent": sum(r["status"] == "inconsistent" for r in tests),
            "compile_or_run_error": sum(r["status"] == "compile_or_run_error" for r in tests),
            "eager_valid": sum(r.get("eager_valid") is True for r in tests),
            "eager_invalid": sum(r.get("eager_valid") is False for r in tests),
            "mutation_left_code_unchanged": dict(unchanged),
            "n_ops": dict(collections.Counter(r.get("n_ops") for r in tests if r["k"] == 0)),
            "by_mutation": by_mut, "failures": failures,
            "wall_s_tests_plus_seed_generation": total_wall,
            "wall_s_tests_only": round(sum(r.get("wall_s", 0.0) for r in tests), 1),
            "wall_s_median_per_test": round(statistics.median([r["wall_s"] for r in tests]), 2) if tests else None}
    os.makedirs(args.out, exist_ok=True)
    json.dump(summ, open(os.path.join(args.out, f"torchprobe_run_{args.tag}.json"), "w", encoding="utf-8"), indent=1, default=str)
    L = [f"| mutation | tests | pass | inconsistent | compile/run error | eager-valid | eager-invalid | code unchanged by mutation | wall sum (s) | wall median (s) |",
         "|---|---:|---:|---:|---:|---:|---:|---:|---:|---:|"]
    for m, v in by_mut.items():
        L.append(f"| {m} | {v['tests']} | {v['pass']} | {v['inconsistent']} | {v['compile_or_run_error']} | {v['eager_valid']} | "
                 f"{v['eager_invalid']} | {unchanged.get(m, 0) if m != 'origin' else '-'} | {v['wall_s_sum']} | {v['wall_s_median']} |")
    L.append(f"| **all** | {summ['tests']} | {summ['pass']} | {summ['inconsistent']} | {summ['compile_or_run_error']} | "
             f"{summ['eager_valid']} | {summ['eager_invalid']} | {sum(unchanged.values())} | {summ['wall_s_tests_only']} | {summ['wall_s_median_per_test']} |")
    open(os.path.join(args.out, f"torchprobe_run_{args.tag}.md"), "w", encoding="utf-8").write("\n".join(L) + "\n")
    print("\n".join(L))
    print(json.dumps({k: v for k, v in summ.items() if k not in ("by_mutation", "files")}, indent=1, default=str))


if __name__ == "__main__":
    main()
