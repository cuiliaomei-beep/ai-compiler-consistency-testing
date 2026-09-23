"""Summarise a campaign over mined issue reproducers as a known-bug benchmark.

Every program came from an issue whose state (open / closed) is in MANIFEST.json.
On the installed PyTorch version an *open* issue is expected to still reproduce,
a *closed* one is expected not to (unless it regressed). Detection counts are
therefore a recall / false-positive table in the sense of plan RQ1.

    python scripts/gh_summary.py reproducers_gh reports_gh
"""
import json
import os
import sys


def main(repro_dir: str, report_dir: str) -> int:
    manifest = json.load(open(os.path.join(repro_dir, "MANIFEST.json"), encoding="utf-8"))
    by_file = {w["file"][:-3]: w for w in manifest["written"]}
    results = json.load(open(os.path.join(report_dir, "run_results.json"), encoding="utf-8"))
    # programs finished in an earlier (interrupted) run are only in progress.json;
    # their candidate count is enough for the detected / not-detected table
    seen = {r["program"] for r in results}
    prog_path = os.path.join(report_dir, "progress.json")
    if os.path.exists(prog_path):
        completed = json.load(open(prog_path, encoding="utf-8")).get("completed", {})
        for name, v in completed.items():
            if name not in seen:
                results.append({"program": name, "n_failures": v.get("records", 0), "stages": ["(earlier run)"],
                                "tests_executed": v.get("tests", 0), "error": v.get("error")})
    rows = []
    for r in results:
        meta = by_file.get(r["program"], {})
        rows.append({"program": r["program"], "issue": meta.get("number"), "state": meta.get("state"),
                     "detected": r["n_failures"] > 0, "stages": r.get("stages", []),
                     "tests": r["tests_executed"], "error": r.get("error")})
    tab = {}
    for row in rows:
        k = row["state"] or "?"
        t = tab.setdefault(k, {"programs": 0, "detected": 0})
        t["programs"] += 1
        t["detected"] += int(row["detected"])
    L = ["# Issue-reproducer campaign as a known-bug benchmark", "",
         f"reproducers: {repro_dir}   reports: {report_dir}", "",
         "| issue state | programs | detected | rate |", "|---|---:|---:|---:|"]
    for k, t in sorted(tab.items()):
        L.append(f"| {k} | {t['programs']} | {t['detected']} | {t['detected'] / max(1, t['programs']):.2f} |")
    L += ["", "reading: open = defect expected to be present on this version (detected = recall); "
              "closed = expected fixed (detected = regression candidate or false positive, review needed)", "",
          "| program | issue | state | detected | stages | tests |", "|---|---|---|---|---|---:|"]
    for row in sorted(rows, key=lambda x: (not x["detected"], str(x["state"]), str(x["issue"]))):
        L.append(f"| {row['program'][:60]} | #{row['issue']} | {row['state']} | {'yes' if row['detected'] else '-'} | "
                 f"{', '.join(row['stages'])} | {row['tests']} |")
    out = os.path.join(report_dir, "KNOWN_BUGS.md")
    with open(out, "w", encoding="utf-8") as fh:
        fh.write("\n".join(L) + "\n")
    print("\n".join(L[:12]))
    print(f"\nwritten {out}")
    return 0


if __name__ == "__main__":
    sys.exit(main(sys.argv[1], sys.argv[2]))
