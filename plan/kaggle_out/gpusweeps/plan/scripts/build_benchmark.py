"""Fill benchmark/historical_bugs.json (plan section 21) from the two issue-reproducer campaigns.

The same reproducers (reproducers_gh/) were run on torch 2.10.0+cu128 (Kaggle T4, gpu_reports_gh_cpu_set/) and
on torch 2.14.0+cpu (reports_gh/). Entries:

  fixed   : issue closed, detected on 2.10, not detected on 2.14  -> BuggyVersion 2.10, FixedVersion 2.14 (+ fix
            commit / "in release" from scripts/fix_in_release.py when --fix-status is given)
  present : issue open, detected on both                         -> positive controls, no fixed version yet
  device? : detected on 2.10/cuda only, issue open                -> may be a CUDA-only defect, listed but not counted

usage: python scripts/build_benchmark.py [--fix-status]   (fix-status queries GitHub, ~3 requests per issue)
       python scripts/build_benchmark.py --old reports_gh_cpu_2.10 --old-version "2.10.0+cpu (Kaggle CPU)" \
                                         --new reports_gh_cpu_2.14 --new-version "2.14.0+cpu (Kaggle CPU)" --verified
       (same-device pair: both report dirs must contain KNOWN_BUGS.md from scripts/gh_summary.py)
"""
import argparse
import json
import os
import re
import sys

HERE = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
ap = argparse.ArgumentParser()
ap.add_argument("--fix-status", action="store_true")
ap.add_argument("--old", default="gpu_reports_gh_cpu_set", help="report dir of the older torch (buggy side)")
ap.add_argument("--new", default="reports_gh", help="report dir of the newer torch (fixed side)")
ap.add_argument("--old-version", default="2.10.0+cu128 (Kaggle T4, --device cuda)")
ap.add_argument("--new-version", default="2.14.0+cpu")
ap.add_argument("--verified", action="store_true", help="both runs on the same device: mark entries Verified")
ARGS = ap.parse_args()


def parse_known(path):
    rows = {}
    for ln in open(path, encoding="utf-8"):
        m = re.match(r"\| (issue_\S+) \| #(\d+) \| (open|closed) \| (yes|-) \| ([^|]*) \| (\d+) \|", ln)
        if m:
            rows[m.group(1)] = {"issue": int(m.group(2)), "state": m.group(3), "detected": m.group(4) == "yes",
                                "stages": m.group(5).strip(), "tests": int(m.group(6))}
    return rows


def main():
    old = parse_known(os.path.join(HERE, ARGS.old, "KNOWN_BUGS.md"))     # older torch (buggy side)
    new = parse_known(os.path.join(HERE, ARGS.new, "KNOWN_BUGS.md"))     # newer torch (fixed side)
    manifest = {w["file"][:-3]: w for w in json.load(open(os.path.join(HERE, "reproducers_gh", "MANIFEST.json"),
                                                           encoding="utf-8"))["written"]}
    fixed, present, device_only = [], [], []
    for prog, o in old.items():
        n = new.get(prog)
        if n is None:
            continue
        if o["state"] == "closed" and o["detected"] and not n["detected"]:
            fixed.append((prog, o, n))
        elif o["state"] == "open" and o["detected"] and n["detected"]:
            present.append((prog, o, n))
        elif o["state"] == "open" and o["detected"] and not n["detected"]:
            device_only.append((prog, o, n))
    print(f"programs on both versions: {len(set(old) & set(new))}; fixed-between: {len(fixed)}, present-on-both: {len(present)}, "
          f"2.10/cuda-only (open): {len(device_only)}")

    fix_status = {}
    if ARGS.fix_status:
        sys.path.insert(0, os.path.join(HERE, "scripts"))
        import fix_in_release
        rows = fix_in_release.main("v2.14.0", [str(o["issue"]) for _, o, _ in fixed])
        fix_status = {r["issue"]: r for r in rows}
        with open(os.path.join(HERE, "benchmark", "fix_status_2.14.json"), "w", encoding="utf-8") as fh:
            json.dump(rows, fh, indent=2)
    elif os.path.exists(os.path.join(HERE, "benchmark", "fix_status_2.14.json")):
        fix_status = {r["issue"]: r for r in json.load(open(os.path.join(HERE, "benchmark", "fix_status_2.14.json")))}

    entries = []
    k = 0

    def entry(prog, o, n, kind):
        nonlocal k
        k += 1
        w = manifest.get(prog, {})
        fs = fix_status.get(str(o["issue"])) or fix_status.get(o["issue"]) or {}
        stage = o["stages"] if o["stages"] and "earlier" not in o["stages"] else (n["stages"] if kind == "present" else "")
        return {
            "BugID": f"PT-{k:04d}",
            "Project": "pytorch/pytorch",
            "Kind": kind,
            "BuggyVersion": ARGS.old_version,
            "FixedVersion": (f"{ARGS.new_version} (not detected)" + (f"; fix commit {fs.get('fix_commit')[:10]}"
                             if fs.get("fix_commit") else "") + (", in v2.14.0" if fs.get("in_release") else ""))
            if kind == "fixed" else (f"still open on {ARGS.new_version}" if kind == "present"
                                     else f"not detected on {ARGS.new_version} (open issue)"),
            "PythonEntry": f"reproducers_gh/{prog}.py",
            "SemanticFactor": "see issue",
            "ExpectedBehavior": "eager result of the reproducer",
            "ActualBehavior": (w.get("title") or "")[:160],
            "CompilerStage": stage.replace(" ", "") or "unknown",
            "OriginalIssue": w.get("url", f"https://github.com/pytorch/pytorch/issues/{o['issue']}"),
            "Detected": {ARGS.old_version: o["detected"], ARGS.new_version: n["detected"]},
            "Verified": bool(ARGS.verified and kind == "fixed"),
            "Note": ("same device for both runs" if ARGS.verified else
                     "device differs between the two runs (cuda vs cpu); a same-device pair is needed before Verified=true"),
        }

    for prog, o, n in fixed:
        entries.append(entry(prog, o, n, "fixed"))
    for prog, o, n in present:
        entries.append(entry(prog, o, n, "present"))
    for prog, o, n in device_only:
        entries.append(entry(prog, o, n, "device?"))

    path = os.path.join(HERE, "benchmark", "historical_bugs.json")
    doc = json.load(open(path, encoding="utf-8"))
    doc["entries"] = entries
    doc["_provenance"] = (f"built by scripts/build_benchmark.py from {ARGS.old}/KNOWN_BUGS.md ({ARGS.old_version}) "
                          f"and {ARGS.new}/KNOWN_BUGS.md ({ARGS.new_version}); same reproducer files")
    with open(path, "w", encoding="utf-8") as fh:
        json.dump(doc, fh, indent=2, ensure_ascii=False)
    print(f"written {path}: {len(entries)} entries")
    for e in entries:
        print(f"  {e['BugID']} {e['Kind']:<8} #{e['OriginalIssue'].rsplit('/', 1)[-1]:<7} {e['CompilerStage']:<40} {e['ActualBehavior'][:60]}")


if __name__ == "__main__":
    main()
