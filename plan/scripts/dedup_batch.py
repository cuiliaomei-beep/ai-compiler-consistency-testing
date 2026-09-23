"""Systematic tracker search for every TO_SUBMIT candidate (2026-09-10). Writes results/dedup_0910.md."""
import os
import sys
import time
import urllib.parse

HERE = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, HERE)
from tcc.report import search_github_issues  # noqa: E402

ITEMS = {
    "argmin_pow_dynamic": ["argmin dynamic shapes C++ compile error", "argmax dynamic=True cpp compile error inductor",
                           "inductor cpp ** index expression", "argmin_combine_vec", "masked argmin dynamic compile"],
    "bmm_autotune_windows": ["bmm max_autotune windows", "cpp_CppMicroGemm not found", "CppBmmTemplate windows dllexport",
                             "max_autotune cpu bmm AttributeError function not found", "inductor windows autotune bmm"],
    "interpolate_zero_size": ["interpolate empty tensor compile", "interpolate zero size inductor NaN",
                              "upsample empty input torch.compile", "interpolate output size 0 compile",
                              "Input and output sizes should be greater than 0 compile"],
    "vector_norm_empty_batch": ["vector_norm empty batch compile", "vector_norm inf norm empty tensor compile",
                                "linalg.norm ord inf empty compile", "vector_norm cannot compute the inf norm",
                                "_check_vector_norm_args numel"],
    "std_var_fp32_accumulation": ["std inductor nan large values", "var torch.compile overflow inf", "std compile zero gradient small values",
                                  "inductor var_mean float32 accumulation", "std 1e30 compile nan"],
    "var_mean_empty_mean": ["var_mean empty tensor compile", "std_mean empty inductor mean 0", "var_mean empty nan inductor"],
    "pdist_backward_crash": ["pdist backward empty", "pdist crash zero rows", "pdist_backward segfault",
                             "pdist empty input autograd crash", "pdist integer division by zero"],
    "bce_weight_dtype": ["binary_cross_entropy weight dtype compile", "binary_cross_entropy bfloat16 inductor float32",
                         "binary_cross_entropy inductor different dtype", "BCELoss half compile output dtype"],
    "channel_shuffle_layout": ["channel_shuffle channels_last", "channel_shuffle compile stride", "channel_shuffle memory format inductor",
                               "native_channel_shuffle torch.compile"],
    "addmm_scalar_bias_autotune": ["addmm max_autotune scalar bias", "addmm 0-d bias inductor IndexError",
                                   "tuned_addmm get_stride IndexError", "addmm bias scalar compile crash"],
    "expand_neg_dim": ["expand -1 scalar tensor", "expand negative dimension zero-dim tensor", "expand -1 leading dimension 0-d",
                       "tensor negative shape expand"],
}

lines = ["# Deduplication pass 2026-09-10 (GitHub search API, pytorch/pytorch, issues + PRs)", ""]
for key, queries in ITEMS.items():
    lines.append(f"## {key}")
    for q in queries:
        url = "https://github.com/pytorch/pytorch/issues?q=" + urllib.parse.quote(f"is:issue {q}")
        r = search_github_issues(q, limit=8)
        cands = r.get("candidates", r.get("items", []))
        lines.append(f"- `{q}` — [search]({url})")
        if r.get("error"):
            lines.append(f"  - error: {r['error']}")
        for c in cands[:8]:
            lines.append(f"  - #{c.get('number')} ({c.get('state')}) {c.get('title', '')[:100]}")
        print(key, "|", q, "|", len(cands), flush=True)
        time.sleep(6.5)
    lines.append("")
out = os.path.join(HERE, "results", "dedup_0910.md")
with open(out, "w", encoding="utf-8") as fh:
    fh.write("\n".join(lines) + "\n")
print("written", out)
