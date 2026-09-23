"""Group the differing functions of cxx_intrinsic_algebra_diff.py into families by the intrinsics they contain."""
import collections, json, os, re, sys
comp = sys.argv[1] if len(sys.argv) > 1 else "msvc"
p = os.path.join(os.path.dirname(os.path.dirname(os.path.abspath(__file__))), "results", "cxx_algebra", comp, "diffs.jsonl")
rows = [json.loads(l) for l in open(p, encoding="utf-8")]
for cls in ("value", "nan-bits"):
    names = collections.defaultdict(set)
    for r in rows:
        if r["class"] == cls:
            names[r["name"]].add(r["config"])
    print(f"===== {comp} {cls}: {len(names)} distinct functions")
    tok = collections.Counter()
    for n in names:
        for t in set(re.sub(r"^_mm(256|512)?_", "", x) for x in re.findall(r"_mm\w+", n)):
            tok[t] += 1
    print("most common intrinsics:", tok.most_common(14))
    # greedy cover: repeatedly take the intrinsic that explains most of the remaining functions
    rest = set(names)
    while rest:
        c = collections.Counter()
        for n in rest:
            for t in set(re.sub(r"^_mm(256|512)?_", "", x) for x in re.findall(r"_mm\w+", n)):
                c[t] += 1
        t, k = c.most_common(1)[0]
        hit = sorted(n for n in rest if re.search(r"_mm(256|512)?_" + re.escape(t) + r"\b", n))
        cfgs = collections.Counter(tuple(sorted(names[n])) for n in hit)
        print(f"-- family '{t}': {len(hit)} functions; configs {dict(cfgs)}")
        for n in sorted(hit, key=len)[:4]:
            print("     ", n)
        rest -= set(hit)
        if len(rest) < 3 or cls == "nan-bits":
            for n in sorted(rest, key=len)[:6]:
                print("   rest:", n)
            break
