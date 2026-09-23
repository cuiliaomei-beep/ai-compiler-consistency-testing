"""6.7 PR-driven differential: which operators did recent merged PRs touch, and do they still agree with their
decompositions / with eager on the nightly?

Step 1 (this script): list commits merged into pytorch/pytorch main in the last N days that touch eager kernels
(aten/src/ATen/native/**), decompositions (torch/_decomp, torch/_refs) or Inductor lowerings
(torch/_inductor/lowering.py, decomposition.py, codegen/*). Extract candidate operator names from the changed
file names and commit titles, intersect with the OpInfo database, and write results/pr_ops.json.
Step 2 (printed command): run the decomposition / metamorphic differential only on those operators with the
nightly interpreter, e.g.
    ..\\venv_nightly\\Scripts\\python.exe run.py decomp --grad --only <ops> --samples 2 --out results/pr_decomp

Uses the public GitHub API (60 requests/hour without GITHUB_TOKEN); each page of commits is one request.
    python scripts/pr_driven_diff.py --days 7 [--token ...]
"""
import argparse
import json
import os
import re
import ssl
import sys
import time
import urllib.parse
import urllib.request
from datetime import datetime, timedelta, timezone

HERE = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, HERE)

PATH_FILTERS = ("aten/src/ATen/native/", "torch/_decomp/", "torch/_refs/", "torch/_inductor/lowering.py",
                "torch/_inductor/decomposition.py", "torch/_inductor/codegen/", "torch/_prims_common/", "torch/_meta_registrations.py",
                "torch/_dynamo/variables/", "torch/optim/")


def _get(url, token=None):
    req = urllib.request.Request(url, headers={"Accept": "application/vnd.github+json", "User-Agent": "tcc-pr-diff"})
    if token:
        req.add_header("Authorization", f"Bearer {token}")
    ctx = None
    try:
        import certifi
        ctx = ssl.create_default_context(cafile=certifi.where())
    except Exception:  # noqa: BLE001
        pass
    for attempt in range(4):
        try:
            with urllib.request.urlopen(req, timeout=60, context=ctx) as r:
                return json.load(r)
        except Exception as e:  # noqa: BLE001
            if attempt == 3:
                raise
            time.sleep(10)


def opinfo_names():
    from torch.testing._internal.common_methods_invocations import op_db
    names = set()
    for o in op_db:
        names.add(o.name)
        names.add(o.name.split(".")[-1])
    return names


WORD = re.compile(r"[A-Za-z_][A-Za-z0-9_]{2,}")


def candidates_from(text):
    out = set()
    for w in WORD.findall(text):
        w2 = w.lower()
        out.add(w2)
        for pre in ("aten::", "torch.", "F.", "nn.functional."):
            if w.startswith(pre):
                out.add(w[len(pre):].lower())
    return out


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--days", type=int, default=7)
    ap.add_argument("--token", default=os.environ.get("GITHUB_TOKEN"))
    ap.add_argument("--max-commits", type=int, default=300)
    ap.add_argument("--out", default=os.path.join(HERE, "results", "pr_ops.json"))
    a = ap.parse_args()
    since = (datetime.now(timezone.utc) - timedelta(days=a.days)).strftime("%Y-%m-%dT%H:%M:%SZ")
    names = opinfo_names()
    lowered = {n.lower(): n for n in names}
    hits = {}
    seen = 0
    for path in PATH_FILTERS:
        page = 1
        while seen < a.max_commits:
            url = ("https://api.github.com/repos/pytorch/pytorch/commits?" +
                   urllib.parse.urlencode({"sha": "main", "since": since, "path": path.rstrip("/"), "per_page": 100, "page": page}))
            try:
                commits = _get(url, a.token)
            except Exception as e:  # noqa: BLE001
                print(f"  {path}: request failed ({str(e)[:80]})")
                break
            if not isinstance(commits, list) or not commits:
                break
            for c in commits:
                seen += 1
                title = (c.get("commit", {}).get("message") or "").splitlines()[0]
                if re.search(r"\[(MPS|ROCm|XPU|MTIA|HPU|CUDA|cuda|Intel GPU)\]|MPS|ROCm|XPU|MTIA", title):
                    continue          # other backends: not observable on CPU
                sha = c.get("sha", "")[:9]
                cands = candidates_from(title) & set(lowered)
                # generic words that happen to be op names
                cands -= {"add", "sub", "mul", "div", "pow", "all", "any", "max", "min", "sum", "mean", "fill", "view", "clone", "copy", "index", "where", "split", "cat", "stack", "sort", "sign", "abs", "exp", "log", "real", "imag", "diag", "flip", "roll", "take", "put", "narrow", "select", "slice", "permute", "expand", "repeat", "tile", "unfold", "fold", "trace", "item", "float", "double", "half", "int", "long", "short", "bool", "complex", "new_zeros", "zeros", "ones", "empty", "full", "arange", "linspace", "eye", "rand", "randn", "randint", "normal", "uniform", "bernoulli", "multinomial", "dropout", "linear", "conv", "norm", "std", "var", "gather", "scatter", "masked", "nonzero", "unique", "clamp", "round", "floor", "ceil", "trunc", "frac", "sqrt", "rsqrt", "square", "sin", "cos", "tan", "sigmoid", "softmax", "relu", "gelu", "silu", "tanh", "erf", "lerp", "addmm", "bmm", "mm", "matmul", "dot", "outer", "inner", "cross", "cumsum", "cumprod", "prod", "argmax", "argmin", "topk", "kthvalue", "median", "mode", "quantile"} if len(cands) > 6 else set()
                if cands:
                    for cnd in cands:
                        hits.setdefault(lowered[cnd], []).append(f"{sha} {title[:90]}")
            if len(commits) < 100:
                break
            page += 1
        time.sleep(1)
    ops = sorted(hits)
    json.dump({"since": since, "commits_seen": seen, "ops": hits}, open(a.out, "w", encoding="utf-8"), indent=1)
    print(f"since {since}: {seen} commits scanned, {len(ops)} OpInfo operators named in commit titles -> {a.out}")
    for op in ops:
        print(f"  {op:<32} {hits[op][0]}")
    if ops:
        only = ",".join(ops)
        print("\nnext (nightly):")
        print(f"  ..\\venv_nightly\\Scripts\\python.exe run.py decomp --grad --only {only} --samples 2 --out results/pr_decomp")
        print(f"  ..\\venv_nightly\\Scripts\\python.exe run.py metamorphic --only {only} --relations config --out results/pr_meta")


if __name__ == "__main__":
    main()
