"""Group a decomp sweep's decomp_diff.json for triage; hide families already recorded in TO_SUBMIT.md.

usage: python scripts/decomp_triage.py results/<dir>/decomp_diff.json [--all]
"""
import collections
import json
import re
import sys

path = sys.argv[1]
show_all = "--all" in sys.argv
r = json.load(open(path, encoding="utf-8"))
ms = [m for m in r["mismatches"] if m["kind"] != "data_dependent"]

KNOWN = [
    (r"^(std|var|var_mean|std_mean)$", r"huge|tiny"),                      # TO_SUBMIT 2
    (r"^index_(add|reduce|copy|select)$", r"empty|size1"),                 # #186532 family
    (r"binary_cross_entropy$", r"dtype_|huge|nan_inf"),                    # TO_SUBMIT 5 / missing check
    (r"cross_entropy|multi_margin|multilabel_margin|soft_margin|nll_loss", r"dtype_|size1|empty"),  # #144362 family
    (r"interpolate|upsample", r"empty|size1"),                             # TO_SUBMIT 3
    (r"vector_norm|linalg\.norm", r"empty"),                               # TO_SUBMIT 4
    (r"native_batch_norm", r"empty_dim0|size1_dim0"),
    (r"max_pool2d", r"size1_last"),
    (r"^(bmm|nn\.functional\.pad|stft|linalg\.pinv|pca_lowrank|svd_lowrank|softsign|gaussian_nll_loss|"
     r"multilabel_soft_margin_loss)$", r"."),                              # harness: unconfirmed
]


def known(m):
    for op_re, var_re in KNOWN:
        if re.search(op_re, m["op"]) and re.search(var_re, m["variant"]):
            return True
    return False


groups = collections.OrderedDict()
for m in ms:
    if not show_all and known(m):
        continue
    if m["kind"] == "decomp" and m.get("confirmed") is False:
        continue     # compile matches eager: a quirk of calling the decomposition directly
    key = (m["kind"], m["op"], re.sub(r"\d+(\.\d+)?(e[-+]?\d+)?", "#", m["detail"])[:70])
    groups.setdefault(key, []).append(m)

print(f"{len(ms)} mismatches, {len(groups)} groups after filtering")
for (kind, op, det), items in groups.items():
    variants = sorted({i["variant"] for i in items})
    conf = {i.get("confirmed") for i in items}
    print(f"{kind:<11} {op:<36} {','.join(variants):<40} conf={conf} n={len(items)}")
    print(f"            {items[0]['detail'][:150]}")
    if items[0].get("confirm_detail"):
        print(f"            confirm: {items[0]['confirm_detail'][:120]}")
