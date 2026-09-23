"""Compare a nightly decomposition-differential JSONL with the local 2.14 runs: report nightly-only and fixed keys.

usage: python scripts/nightly_decomp_diff.py <nightly.jsonl> <baseline.jsonl> [<baseline2.jsonl> ...]
Key = (op, variant, kind). Value-level detail is shown for nightly-only keys.
"""
import json
import sys
from collections import Counter


def load(path):
    recs = {}
    for ln in open(path, encoding="utf-8", errors="replace"):
        ln = ln.strip()
        if not ln:
            continue
        r = json.loads(ln)
        if "op" not in r or r.get("kind") == "data_dependent":
            continue
        recs.setdefault((r["op"], r["variant"], r["kind"]), r)
    return recs


nightly = load(sys.argv[1])
base = {}
for p in sys.argv[2:]:
    base.update(load(p))
base_ops = {k[0] for k in base}
only_n = [k for k in nightly if k not in base]
only_b = [k for k in base if k not in nightly]
print(f"nightly keys {len(nightly)} | baseline keys {len(base)} | nightly-only {len(only_n)} | baseline-only {len(only_b)}")
print("\n## nightly-only (op, variant, kind) -> detail  [* = op never flagged in baseline at all]")
for k in sorted(only_n):
    r = nightly[k]
    star = "*" if k[0] not in base_ops else " "
    print(f"{star} {k[0]:<40} {k[1]:<15} {k[2]:<8} conf={r.get('confirmed')!s:<5} {r.get('detail','')[:110]}")
print("\n## baseline-only (fixed on nightly, or sample/variant-set difference)")
for k in sorted(only_b):
    print(f"  {k[0]:<40} {k[1]:<15} {k[2]:<8} {base[k].get('detail','')[:100]}")
print("\nnightly kinds:", Counter(k[2] for k in nightly), "| baseline kinds:", Counter(k[2] for k in base))
