"""8.7  Compare Dynamo python-semantics divergence sets across platforms / Python versions / torch versions.
Each argument is a results directory holding dynsem.json (run.py dynsem --out DIR).  Prints, per (program, call),
which runs diverge and whether the compiled value differs between runs; the interesting rows are those where only
some runs diverge (a platform- or version-specific Dynamo translation defect).
    python scripts/dynsem_platform_compare.py results/dynsem3 kaggle_out/dynsemlinux/plan/results/dynsem_linux_214 ...
"""
import json
import os
import sys


def load(d):
    r = json.load(open(os.path.join(d, "dynsem.json"), encoding="utf-8"))
    return r["mode"], r["programs"], {(x["program"], x["call"]): x for x in r["divergences"]}


def main(dirs):
    runs = [(os.path.basename(os.path.normpath(d)),) + load(d) for d in dirs]
    keys = sorted({k for _, _, _, div in runs for k in div})
    print("runs:", ", ".join(f"{n} ({m}, {p} programs, {len(div)} div)" for n, m, p, div in runs))
    print()
    only_some, all_runs = [], []
    for k in keys:
        flags = [k in div for _, _, _, div in runs]
        row = (k, flags)
        (all_runs if all(flags) else only_some).append(row)
    print(f"== diverge in only some runs ({len(only_some)}):")
    for k, flags in only_some:
        print(f"  {k[0]:<36} call{k[1]}  " + "  ".join(f"{n}:{'DIV' if f else '-  '}" for (n, *_), f in zip(runs, flags)))
        for (n, _, _, div), f in zip(runs, flags):
            if f:
                print(f"      {n}: {div[k]['what']} eager={div[k]['eager'][:70]}  compiled={div[k]['compiled'][:70]}")
    print(f"== diverge in every run ({len(all_runs)}); compiled value differs between runs in:")
    for k, _ in all_runs:
        vals = {div[k]["compiled"] for _, _, _, div in runs}
        if len(vals) > 1:
            print(f"  {k[0]:<36} call{k[1]}: " + " | ".join(f"{n}={div[k]['compiled'][:50]}" for n, _, _, div in runs))


if __name__ == "__main__":
    main(sys.argv[1:])
