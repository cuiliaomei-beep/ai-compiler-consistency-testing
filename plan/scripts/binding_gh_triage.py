"""Triage a binding-variant campaign over issue reproducers: which candidates are new relative to the plain run?

usage: python scripts/binding_gh_triage.py <binding campaign dir> <plain campaign dir with KNOWN_BUGS.md>
"""
import collections
import json
import os
import re
import sys

bdir, pdir = sys.argv[1], sys.argv[2]
prog = json.load(open(os.path.join(bdir, "progress.json"), encoding="utf-8")).get("completed", {})
plain = {}
for ln in open(os.path.join(pdir, "KNOWN_BUGS.md"), encoding="utf-8"):
    m = re.match(r"\| (issue_\S+) \| #(\d+) \| (open|closed) \| (yes|-) \|", ln)
    if m:
        plain[m.group(1)] = (m.group(2), m.group(3), m.group(4) == "yes")

by_base = collections.defaultdict(dict)
for name, v in prog.items():
    m = re.match(r"(.+?)__bind_([a-z_]+?)(\d+)$", name)
    base, form = (m.group(1), m.group(2)) if m else (name, "literal")
    by_base[base][form] = int(v.get("records", 0) or 0)

new, known, none = [], [], []
for base, forms in sorted(by_base.items()):
    issue, state, det = plain.get(base, ("?", "?", None))
    hit = {f: n for f, n in forms.items() if n}
    if hit and det is False:
        new.append((base, issue, state, hit, forms))
    elif hit:
        known.append((base, issue, state, hit, forms))
    else:
        none.append(base)
print(f"variant programs: {len(prog)} over {len(by_base)} reproducers; base detected in plain run + variant hits: {len(known)}; "
      f"base NOT detected in plain run but a variant hits: {len(new)}; no hits: {len(none)}")
print("\n== variant-only detections (base program was clean in the plain run) ==")
for base, issue, state, hit, forms in new:
    print(f"  #{issue} ({state}) {base[:60]}  hits={hit}  tried={sorted(forms)}")
print("\n== known (base already detected) ==")
for base, issue, state, hit, forms in known:
    print(f"  #{issue} ({state}) {base[:60]}  hits={hit}")
