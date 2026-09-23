"""Summarise results/export_roundtrip/<dtype>.jsonl: per path (SL / AO) and class, list the ops; separate the entries
that also differ under plain torch.compile (Inductor-general, triaged in earlier sweeps) from the path-specific ones.
    python scripts/export_roundtrip_report.py [results/export_roundtrip/float32.jsonl]
"""
import collections
import json
import sys


def main(path="results/export_roundtrip/float32.jsonl"):
    rows = [json.loads(l) for l in open(path, encoding="utf-8") if l.strip()]
    verdicts = collections.Counter(r["verdict"].split(":")[0] for r in rows)
    print(len(rows), "ops;", dict(verdicts))
    by = collections.defaultdict(list)
    for r in rows:
        for d in r["diffs"]:
            by[(d["path"], d["class"])].append((r["op"], d["detail"][:110]))
    for (p, c), items in sorted(by.items()):
        print(f"\n== {p} {c} ({len(items)})")
        for op, det in items:
            print(f"   {op:40s} {det}")
    errs = collections.Counter()
    for r in rows:
        for e in r["errors"]:
            errs[e.split(":")[0][:60]] += 1
    print("\n== infrastructure errors (not differences):", errs.most_common(12))


if __name__ == "__main__":
    main(*sys.argv[1:])
