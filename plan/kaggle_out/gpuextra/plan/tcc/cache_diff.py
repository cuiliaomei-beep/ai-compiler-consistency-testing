"""Cross-process disk-cache differential (NEXT_DIRECTIONS 5.6, plan section 14).

Does the FX-graph / AOTAutograd disk cache key cover everything that is *baked* into a
compiled graph? Sequence per case:

    process A: cache dir empty -> compile f with constant v1 -> run
    process B: same cache dir  -> the same source with constant v2 -> compile -> run

Both processes report eager and compiled outputs plus the cache counters. In B:

- cache **miss**              : correct (the key saw the change)
- cache **hit**, result right : the constant is a runtime input, fine
- cache **hit**, result wrong : the key did not cover the baked value  -> defect

Each case is a small script with a ``{V}`` placeholder. Constants reach the graph
through the binding forms of 5.4 (closure, global, attribute, default arg, tensor
constant created inside the graph, ...) and through process-global state that
changes codegen or semantics (default dtype, matmul precision, deterministic
algorithms, inductor config, frozen parameters).
"""
from __future__ import annotations

import json
import os
import shutil
import subprocess
import sys
import tempfile
import time
from typing import Any, Dict, List, Optional, Tuple

CHILD = r'''
import json, sys, math, torch
from torch._dynamo.utils import counters
torch.manual_seed(0)
{setup}

x = {input}
def _lst(t):
    if isinstance(t, (tuple, list)):
        return [_lst(a) for a in t]
    if isinstance(t, torch.Tensor):
        return {{"shape": list(t.shape), "dtype": str(t.dtype), "vals": t.detach().flatten().double().tolist()[:64]}}
    return t
res = {{}}
try:
    e = f(*x) if isinstance(x, tuple) else f(x)
    res["eager"] = _lst(e)
except Exception as ex:
    res["eager_error"] = f"{{type(ex).__name__}}: {{str(ex)[:120]}}"
try:
    cf = torch.compile(f)
    c = cf(*x) if isinstance(x, tuple) else cf(x)
    res["compiled"] = _lst(c)
except Exception as ex:
    inner = ex
    while getattr(inner, "__cause__", None) is not None:
        inner = inner.__cause__
    res["compiled_error"] = f"{{type(inner).__name__}}: {{str(inner)[:160]}}"
ind = counters["inductor"]
res["fx_hit"] = int(ind.get("fxgraph_cache_hit", 0))
res["fx_miss"] = int(ind.get("fxgraph_cache_miss", 0))
res["fx_bypass"] = int(ind.get("fxgraph_cache_bypass", 0))
aot = counters["aot_autograd"]
res["aot_hit"] = int(aot.get("autograd_cache_hit", 0))
res["aot_miss"] = int(aot.get("autograd_cache_miss", 0))
res["aot_bypass"] = int(aot.get("autograd_cache_bypass", 0))
print("RESULT " + json.dumps(res))
'''

# name -> (setup with {V}, input expression, v1, v2, note)
CASES: Dict[str, Tuple[str, str, Any, Any, str]] = {
    "closure_float": ("K = {V}\ndef f(x):\n    return x * K + 1.0", "torch.randn(8)", 1.5, 2.5,
                      "float constant from a global/closure"),
    "closure_int_shape": ("K = {V}\ndef f(x):\n    return x.view(K, -1).sum(1)", "torch.randn(12)", 3, 4,
                          "int constant used as a view size"),
    "int_slice": ("K = {V}\ndef f(x):\n    return x[:K].sum()", "torch.randn(8)", 3, 5, "int constant in a slice"),
    "tensor_const_inside": ("def f(x):\n    return x + torch.tensor({V})", "torch.randn(8)", 1.5, 2.5,
                            "tensor constant created inside the graph"),
    "tensor_const_inside_big": ("def f(x):\n    return x + torch.tensor([{V}] * 100)", "torch.randn(100)", 0.0, 1.0,
                                "100-element tensor constant created inside the graph"),
    "tensor_const_global": ("C = torch.tensor([{V}, {V}])\ndef f(x):\n    return x * C", "torch.randn(2)", 1.5, 2.5,
                            "global tensor captured by the graph"),
    "attr_float": ("class Cfg:\n    k = {V}\ncfg = Cfg()\ndef f(x):\n    return x * cfg.k", "torch.randn(8)", 1.5, 2.5,
                   "object attribute"),
    "default_arg": ("def f(x, k={V}):\n    return x * k", "torch.randn(8)", 1.5, 2.5, "default argument"),
    "math_const": ("def f(x):\n    return x * math.{V}", "torch.randn(8)", "pi", "e", "module attribute (math.pi / math.e)"),
    "str_mode": ("MODE = {V!r}\ndef f(x):\n    return torch.nn.functional.interpolate(x, scale_factor=2, mode=MODE)",
                 "torch.randn(1, 2, 5)", "nearest", "linear", "string constant selecting the kernel"),
    "bool_flag": ("FAST = {V}\ndef f(x):\n    return x.relu() if FAST else x.sigmoid()", "torch.randn(8)", True, False,
                  "bool constant on a branch"),
    "tuple_kernel": ("KS = {V}\ndef f(x):\n    return torch.nn.functional.max_pool2d(x, KS)", "torch.randn(1, 1, 6, 6)",
                     (2, 2), (3, 3), "tuple constant (kernel_size)"),
    "full_inside": ("def f(x):\n    return x + torch.full((4,), {V})", "torch.randn(4)", 1.5, 2.5,
                    "torch.full with a Python scalar inside the graph"),
    "arange_inside": ("def f(x):\n    return x * torch.arange({V}, dtype=torch.float32)", "torch.randn(1)", 4, 6,
                      "arange size constant inside the graph (output shape changes)"),
    "default_dtype": ("torch.set_default_dtype(torch.{V})\ndef f(x):\n    return x + torch.tensor(1.5)",
                      "torch.randn(4, dtype=torch.float32)", "float32", "float64",
                      "process-global default dtype (changes the dtype of a constant made inside the graph)"),
    "matmul_precision": ("torch.set_float32_matmul_precision({V!r})\ndef f(x):\n    return x @ x.t()",
                         "torch.randn(64, 64)", "highest", "medium", "process-global matmul precision"),
    "deterministic": ("torch.use_deterministic_algorithms({V})\ndef f(x):\n    return torch.zeros(4).index_add(0, torch.tensor([0, 0, 1, 2]), x)",
                      "torch.randn(4)", False, True, "process-global deterministic-algorithms flag"),
    "inductor_simdlen": ("torch._inductor.config.cpp.simdlen = {V}\ndef f(x):\n    return (x * 2).sin().sum()",
                         "torch.randn(1000)", "None", 1, "inductor config that changes codegen (vectorisation)"),
    "inductor_epilogue": ("torch._inductor.config.epilogue_fusion = {V}\ndef f(x):\n    return (x @ x.t()).relu()",
                          "torch.randn(16, 16)", True, False, "inductor config epilogue_fusion"),
    "freezing_param": ("torch._inductor.config.freezing = True\nm = torch.nn.Linear(4, 2)\n"
                       "with torch.no_grad():\n    m.weight.fill_({V}); m.bias.zero_()\nm.eval()\n"
                       "def f(x):\n    return m(x)", "torch.ones(3, 4)", 1.0, 2.0,
                       "frozen parameter values (freezing bakes weights as constants)"),
    "module_attr_int": ("class M(torch.nn.Module):\n    def __init__(self):\n        super().__init__()\n        self.g = {V}\n"
                        "    def forward(self, x):\n        return x.view(self.g, -1).sum(1)\nm = M()\n"
                        "def f(x):\n    return m(x)", "torch.randn(12)", 3, 4, "nn.Module int attribute used as a shape"),
    "requires_grad": ("def f(x):\n    return (x * 3).sum()", "torch.randn(4).requires_grad_({V})", False, True,
                      "input requires_grad (AOTAutograd forward-only vs joint graph)"),
    "grad_mode": ("torch.set_grad_enabled({V})\ndef f(x):\n    return (x * 3).sum()", "torch.randn(4, requires_grad=True)",
                  True, False, "process-global grad mode"),
    "num_threads": ("torch.set_num_threads({V})\ndef f(x):\n    return (x * 2).sum()", "torch.randn(100000)", 1, 4,
                    "thread count (changes the parallel reduction order)"),
    "tensor_const_inside_huge": ("def f(x):\n    return x + torch.full((10000,), {V}).cumsum(0)", "torch.randn(10000)",
                                 0.5, 1.5, "10k-element constant folded inside the graph (constant-folding / large-constant path)"),
    "closure_tensor_factory": ("def make(v):\n    c = torch.tensor([v, v + 1.0])\n    def f(x):\n        return x * c\n    return f\n"
                               "f = make({V})", "torch.randn(2)", 1.5, 2.5, "tensor captured by a closure cell"),
    "dynamo_capture_scalar": ("torch._dynamo.config.capture_scalar_outputs = {V}\n"
                              "def f(x):\n    n = int(x.sum().item()) % 3 + 1\n    return torch.ones(n)",
                              "torch.tensor([2.0, 3.0])", False, True, "dynamo config flag (graph break vs unbacked symint)"),
    "compile_options_dynamic": ("import torch._dynamo\nDYN = {V}\n_f = lambda x: (x * 2).sum(0)\n"
                                "def f(x):\n    return _f(x)\ntorch.compile = (lambda _tc: (lambda fn, **kw: _tc(fn, dynamic=DYN, **kw)))(torch.compile)",
                                "torch.randn(5, 3)", False, True, "torch.compile(dynamic=...) flag"),
}


def _subst(text: str, v: Any) -> str:
    """``{V!r}`` -> repr(v); ``{V}`` -> the value as source (strings are inserted verbatim, e.g. math.pi)."""
    return text.replace("{V!r}", repr(v)).replace("{V}", v if isinstance(v, str) else str(v))


def _child_source(setup: str, inp: str, v: Any) -> str:
    return CHILD.format(setup=_subst(setup, v), input=_subst(inp, v))


def _run_child(src: str, cache_dir: str, timeout: float) -> Dict[str, Any]:
    env = dict(os.environ)
    env.update({"TORCHINDUCTOR_CACHE_DIR": cache_dir, "TORCHINDUCTOR_FX_GRAPH_CACHE": "1",
                "TORCHINDUCTOR_AUTOGRAD_CACHE": "1", "PYTHONIOENCODING": "utf-8"})
    try:
        r = subprocess.run([sys.executable, "-c", src], capture_output=True, text=True, env=env, timeout=timeout,
                           encoding="utf-8", errors="replace")
    except subprocess.TimeoutExpired:
        return {"error": "timeout"}
    for ln in (r.stdout or "").splitlines():
        if ln.startswith("RESULT "):
            return json.loads(ln[7:])
    return {"error": f"exit {r.returncode}: {(r.stderr or '')[-300:]}"}


def _same(a: Any, b: Any, tol: float = 1e-5) -> Tuple[bool, str]:
    if isinstance(a, list) and isinstance(b, list) and not (a and isinstance(a[0], dict)):
        if len(a) != len(b):
            return False, "structure"
        for x, y in zip(a, b):
            ok, why = _same(x, y, tol)
            if not ok:
                return False, why
        return True, ""
    if isinstance(a, dict) and isinstance(b, dict):
        if a["shape"] != b["shape"]:
            return False, f"shape {a['shape']} vs {b['shape']}"
        if a["dtype"] != b["dtype"]:
            return False, f"dtype {a['dtype']} vs {b['dtype']}"
        for x, y in zip(a["vals"], b["vals"]):
            if x != x and y != y:
                continue
            if abs(x - y) > tol * max(1.0, abs(x)):
                return False, f"value {x:.6g} vs {y:.6g}"
        return True, ""
    return a == b, "" if a == b else f"{a!r} vs {b!r}"


def run(cases: Optional[List[str]] = None, out_dir: str = "results/diskcache", timeout: float = 600.0, log=print
        ) -> Dict[str, Any]:
    os.makedirs(out_dir, exist_ok=True)
    rows: List[Dict[str, Any]] = []
    t0 = time.time()
    # control: the same source twice must hit, otherwise the shared cache dir does not work and every
    # "miss" below would be meaningless
    setup, inp, v1, _, _ = CASES["closure_float"]
    cache_dir = tempfile.mkdtemp(prefix="tcc_cache_")
    try:
        ca = _run_child(_child_source(setup, inp, v1), cache_dir, timeout)
        cb = _run_child(_child_source(setup, inp, v1), cache_dir, timeout)
    finally:
        shutil.rmtree(cache_dir, ignore_errors=True)
    control_ok = cb.get("fx_hit", 0) > 0 or cb.get("aot_hit", 0) > 0
    log(f"  control (same source twice): A fx miss={ca.get('fx_miss')} aot miss={ca.get('aot_miss')} | "
        f"B fx hit={cb.get('fx_hit')} aot hit={cb.get('aot_hit')} -> {'cache shared OK' if control_ok else 'CACHE NOT SHARED'}")
    for name, (setup, inp, v1, v2, note) in CASES.items():
        if cases and name not in cases:
            continue
        cache_dir = tempfile.mkdtemp(prefix="tcc_cache_")
        try:
            a = _run_child(_child_source(setup, inp, v1), cache_dir, timeout)
            b = _run_child(_child_source(setup, inp, v2), cache_dir, timeout)
        finally:
            shutil.rmtree(cache_dir, ignore_errors=True)
        row: Dict[str, Any] = {"case": name, "note": note, "v1": repr(v1), "v2": repr(v2), "A": a, "B": b}
        if "error" in a or "error" in b:
            row["verdict"] = "infra"
            row["detail"] = a.get("error") or b.get("error")
        elif "compiled_error" in b or "eager_error" in b:
            row["verdict"] = "error"
            row["detail"] = b.get("compiled_error") or b.get("eager_error")
        else:
            ok, why = _same(b["eager"], b["compiled"])
            hit = b["fx_hit"] > 0 or b["aot_hit"] > 0
            row["hit"] = hit
            row["result_ok"] = ok
            if hit and not ok:
                row["verdict"] = "STALE"          # cache hit served a graph compiled for v1
            elif hit:
                row["verdict"] = "hit-ok"
            elif b["fx_bypass"] > 0 or b["aot_bypass"] > 0:
                row["verdict"] = "bypass"
            else:
                row["verdict"] = "miss"
            row["detail"] = why
            # sanity: process A must be self-consistent too
            ok_a, why_a = _same(a.get("eager"), a.get("compiled"))
            if not ok_a:
                row["verdict"] = "A-mismatch"
                row["detail"] = why_a
        rows.append(row)
        log(f"  {name:<24} {row['verdict']:<10} A: hit={a.get('fx_hit')}/aot={a.get('aot_hit')} "
            f"B: fx hit={b.get('fx_hit')} miss={b.get('fx_miss')} aot hit={b.get('aot_hit')} miss={b.get('aot_miss')}  {row.get('detail', '')}")
    res = {"rows": rows, "wall_s": round(time.time() - t0, 1), "control_shared_cache": control_ok,
           "control": {"A": ca, "B": cb}}
    with open(os.path.join(out_dir, "diskcache.json"), "w", encoding="utf-8") as fh:
        json.dump(res, fh, indent=2, default=str)
    L = ["# Cross-process disk-cache differential", "",
         "Process A compiles with v1 into an empty cache dir; process B compiles the same source with v2 against the same dir.",
         "`STALE` = B hit the cache and its compiled result disagrees with B's own eager result.", "",
         f"- control (identical source in two processes): {'cache hit in B — shared cache works' if control_ok else 'NO hit in B — cache not shared, misses below are meaningless'}",
         f"- cases: {len(rows)}, wall {res['wall_s']} s",
         f"- verdicts: " + ", ".join(f"{v}={sum(1 for r in rows if r['verdict'] == v)}"
                                    for v in ("STALE", "hit-ok", "miss", "bypass", "error", "infra", "A-mismatch")), "",
         "| case | what is baked | v1 → v2 | B: fx hit/miss | B: aot hit/miss | verdict | detail |", "|---|---|---|---|---|---|---|"]
    for r in rows:
        b = r["B"]
        L.append(f"| {r['case']} | {r['note']} | {r['v1']} → {r['v2']} | {b.get('fx_hit')}/{b.get('fx_miss')} | "
                 f"{b.get('aot_hit')}/{b.get('aot_miss')} | **{r['verdict']}** | {str(r.get('detail', ''))[:80].replace('|', '/')} |")
    with open(os.path.join(out_dir, "DISKCACHE.md"), "w", encoding="utf-8") as fh:
        fh.write("\n".join(L) + "\n")
    return res
