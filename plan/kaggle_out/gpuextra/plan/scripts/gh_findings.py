"""One line per record for the given issue numbers: what fired, and how big.

    python scripts/gh_findings.py reports_gh 160840 172711 ...
"""
import glob
import json
import os
import sys


def main(report_dir: str, numbers) -> int:
    want = tuple(str(n) for n in numbers)
    for d in sorted(glob.glob(os.path.join(report_dir, "*", "record.json"))):
        r = json.load(open(d, encoding="utf-8"))
        if want and not any(n in r["program"] for n in want):
            continue
        t = r["triage"]
        line = (f"{r['program'][:40]:<40} {r['context']['name']:<18} {t['stage']:<22} "
                f"{','.join(t['kinds']):<10} repro {r['reproducibility']}")
        for k, c in r["comparisons"].items():
            if not c["findings"]:
                continue
            f = c["findings"][0]
            ev = f.get("evidence") or {}
            extra = ev.get("max_abs_error") or ev.get("exception") or ""
            if "eager_err_vs_fp64" in ev:
                extra = f"eager_err {ev['eager_err_vs_fp64']:.2e} compiled_err {ev['compiled_err_vs_fp64']:.2e}"
            line += f" | {k}: {f['detail'][:60]} {extra}"
            break
        print(line)
    return 0


if __name__ == "__main__":
    sys.exit(main(sys.argv[1], sys.argv[2:]))
