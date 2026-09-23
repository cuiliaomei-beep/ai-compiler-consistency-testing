"""Numbers for the paper from data/findings.csv (73 filed items) and the sweep logs.
    python data/stats.py            -> prints every count used in the text and writes data/stats.json
Column legend (findings.csv):
  layer   Dy Dynamo | AOT AOTAutograd | De decompositions/meta | In Inductor | Ex export/AOTI | Eg eager kernel | Fx torch.fx | DM dispatch mode | Ext other target
  symptom S silent | F failure of a program eager accepts | C process crash / hang
  axis    P-scs source-derived semantic factor | P-edge boundary value | P-dtype dtype factor | P-corpus program corpus
          Q-seq call sequence / cache | Q-context execution context or mode | Q-gbreak graph-break placement | Q-artifact artifact path | X-cross other compiler
  oracle  VALUE DTYPE LAYOUT META GRAD PRECISION ALIAS EXC STATE CRASH TRACEERR
  attribution A strict consistency failure of the compile pipeline | B root cause outside the pipeline | C other target
  status  fixed (merged or fix PR by any developer) | confirmed | pending | rejected
"""
import collections
import csv
import json
import os

HERE = os.path.dirname(os.path.abspath(__file__))
rows = list(csv.DictReader(open(os.path.join(HERE, "findings.csv"), encoding="utf-8")))
assert len(rows) == 73, len(rows)


def count(key, sub=None):
    return collections.Counter(r[key] for r in rows if sub is None or sub(r))


out = {}
out["total"] = len(rows)
out["kind"] = dict(count("kind"))
out["round"] = dict(count("round"))
out["status"] = dict(count("status"))
out["status_by_round"] = {rd: dict(count("status", lambda r, rd=rd: r["round"] == rd)) for rd in ("1", "2")}
out["attribution"] = dict(count("attribution"))
out["attribution_issues_only"] = dict(count("attribution", lambda r: r["kind"] == "issue"))
out["layer"] = dict(count("layer"))
out["symptom"] = dict(count("symptom"))
out["symptom_A"] = dict(count("symptom", lambda r: r["attribution"] == "A"))
out["axis"] = dict(count("axis"))
out["axis_group"] = dict(collections.Counter(("program side" if r["axis"].startswith("P-") else "path side" if r["axis"].startswith("Q-") else "cross-target") for r in rows))
out["axis_group_A"] = dict(collections.Counter(("program side" if r["axis"].startswith("P-") else "path side") for r in rows if r["attribution"] == "A"))
out["oracle"] = dict(count("oracle"))
out["oracle_A"] = dict(count("oracle", lambda r: r["attribution"] == "A"))
# findings that only a non-value observable can see (A only)
non_value = {"DTYPE", "LAYOUT", "META", "GRAD", "PRECISION", "ALIAS", "EXC", "STATE", "CRASH"}
out["A_needing_non_value_oracle"] = sum(1 for r in rows if r["attribution"] == "A" and r["oracle"] in non_value)
out["A_total"] = sum(1 for r in rows if r["attribution"] == "A")
out["round2_path_side_new_issues"] = [r["id"] for r in rows if r["round"] == "2" and r["axis"].startswith("Q-") and r["kind"] == "issue"]
out["fixed_ids"] = [r["id"] for r in rows if r["status"] == "fixed"]
out["fixed_layers"] = dict(count("layer", lambda r: r["status"] == "fixed"))
json.dump(out, open(os.path.join(HERE, "stats.json"), "w", encoding="utf-8"), indent=1, ensure_ascii=False)
for k, v in out.items():
    print(f"{k:32s} {v}")
