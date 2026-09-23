"""Summarise results/<dir>/binding.json: counts by mode/form, form-specific findings, literal failures."""
import collections
import json
import sys

path = sys.argv[1] if len(sys.argv) > 1 else "results/binding_full/binding.json"
r = json.load(open(path, encoding="utf-8"))
ms = r["mismatches"]
print("by (mode, form, literal passes):")
c = collections.Counter((m["mode"], m["form"], bool(m["literal_same"])) for m in ms)
for k, v in sorted(c.items()):
    print("  ", k, v)
print("\nform-specific (literal form passes the same mode):")
for m in ms:
    if m["literal_same"] and m["form"] != "literal":
        print(f"  {m['mode']:<7} {m['op']:<30} {m['slot']}={m['value']!r:<10} {m['form']:<13} {m['detail'][:130]}")
print("\nrebind-mode findings (same compiled artefact, value changed through the same path):")
for m in sorted((m for m in ms if m["mode"] == "rebind"), key=lambda m: (m["op"], m["form"])):
    print(f"  {m['op']:<28} {m['slot']}={m['value']!r:<8} {m['form']:<13} {m['detail'][:150]}")
skip = {"linalg.norm", "max_pool2d_with_indices_backward", "var_mean", "std_mean"}
print("\nother static/dynamic findings:")
for m in ms:
    if m["mode"] != "rebind" and m["op"] not in skip:
        print(f"  {m['mode']:<7} {m['op']:<28} {m['slot']}={m['value']!r:<8} {m['form']:<13} lit={m['literal_same']} "
              f"{m['detail'][:140]}")
print("\nliteral form fails (the standard oracle would report these):")
seen = set()
for m in ms:
    if m["form"] == "literal":
        k = (m["op"], m["mode"])
        if k in seen:
            continue
        seen.add(k)
        print(f"  {m['mode']:<7} {m['op']:<30} {m['slot']}={m['value']!r:<10} {m['detail'][:120]}")
