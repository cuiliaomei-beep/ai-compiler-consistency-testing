"""Rebuild SUMMARY.md for a report directory from the per-record metadata.

Isolated campaigns write SUMMARY.md per child (last child wins); this walks
every <signature>/metadata.json and produces the whole-campaign table.

    python scripts/dir_summary.py gpu_reports_gh
"""
import collections
import json
import os
import sys


def main(report_dir: str) -> int:
    rows = []
    for nm in sorted(os.listdir(report_dir)):
        md = os.path.join(report_dir, nm, "metadata.json")
        if os.path.exists(md):
            m = json.load(open(md, encoding="utf-8"))
            m["signature"] = nm
            rows.append(m)
    prog = {}
    pp = os.path.join(report_dir, "progress.json")
    if os.path.exists(pp):
        prog = json.load(open(pp, encoding="utf-8")).get("completed", {})
    by_prio = collections.defaultdict(list)
    for r in rows:
        by_prio[r.get("priority", "?")].append(r)
    L = ["# Campaign summary (rebuilt from metadata)", "",
         f"- programs completed: {len(prog)}", f"- records: {len(rows)}",
         f"- submittable (high/medium): {sum(1 for r in rows if r.get('priority') in ('high', 'medium'))}",
         f"- torch: {rows[0].get('torch') if rows else '?'}", ""]
    for prio in ("high", "medium", "low", "info"):
        rs = by_prio.get(prio, [])
        if not rs:
            continue
        L += [f"## {prio} ({len(rs)})", "", "| signature | program | stage | probe | factor | oracles | repro | status |",
              "|---|---|---|---|---|---|---|---|"]
        for r in sorted(rs, key=lambda x: (x.get("program", ""), x.get("stage", ""))):
            L.append(f"| `{r['signature']}` | {r.get('program', '')[:50]} | {r.get('stage')} | {r.get('probe')} | "
                     f"{r.get('factor') or '-'} | {', '.join(r.get('kinds') or [])} | {r.get('reproducibility')} | "
                     f"{r.get('status')} |")
        L.append("")
    stages = collections.Counter(r.get("stage") for r in rows)
    L += ["## by stage", ""] + [f"- {k}: {v}" for k, v in stages.most_common()]
    progs = collections.Counter(r.get("program") for r in rows if r.get("priority") in ("high", "medium"))
    L += ["", "## programs with submittable records", ""] + [f"- {k}: {v}" for k, v in progs.most_common()]
    out = os.path.join(report_dir, "SUMMARY_ALL.md")
    with open(out, "w", encoding="utf-8") as fh:
        fh.write("\n".join(L) + "\n")
    print("\n".join(L[:8]))
    print(f"stages: {dict(stages)}")
    print(f"written {out}")
    return 0


if __name__ == "__main__":
    sys.exit(main(sys.argv[1]))
