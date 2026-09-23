"""12.6  Statement-level graph-break insertion applied to the side-effect corpus (scripts/side_effect_diff.py, 76 cases).
Each case receives a wrapper C; here C = compile(rewrite(f)) where rewrite() inserts torch._dynamo.graph_break()
after every top-level statement of f's body (closures are preserved: the rewritten code object is re-bound to the
original cells; lambdas and nn.Modules are passed through unchanged).  Observations (return value, mutated state,
exception type) must equal eager's, exactly as in side_effect_diff.  Cases whose status changes relative to the
plain-compile run are the leads.
    python scripts/side_effect_graph_break_diff.py [--backend eager|aot_eager|inductor] -> results/side_effects_gb/<backend>.jsonl
"""
import argparse
import ast
import inspect
import json
import os
import sys
import tempfile
import textwrap
import types

os.environ.setdefault("TORCHINDUCTOR_CACHE_DIR", tempfile.mkdtemp(prefix="tcc_segb_"))
HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, os.path.dirname(HERE))
sys.path.insert(0, HERE)
from tcc.compat import ensure_msvc_env  # noqa: E402

ensure_msvc_env()
import torch  # noqa: E402

import side_effect_diff as sed  # noqa: E402

GB = ast.parse("torch._dynamo.graph_break()").body[0]
STOP = (ast.Return, ast.Raise, ast.Continue, ast.Break, ast.Global, ast.Nonlocal, ast.Pass)


def rewrite(fn):
    """Return a copy of `fn` with a graph break after every top-level statement; closures / defaults preserved."""
    if not isinstance(fn, types.FunctionType) or fn.__name__ == "<lambda>":
        return fn, 0
    try:
        src = textwrap.dedent(inspect.getsource(fn))
    except (OSError, TypeError):
        return fn, 0
    mod = ast.parse(src)
    fdef = mod.body[0]
    if not isinstance(fdef, ast.FunctionDef):
        return fn, 0
    fdef.decorator_list = []
    body, n = [], 0
    for s in fdef.body:
        body.append(s)
        if not isinstance(s, STOP):
            body.append(ast.copy_location(GB, s)); n += 1
    fdef.body = body
    free = fn.__code__.co_freevars
    # wrap in an outer function that provides the free variables so the inner code object has the same closure shape
    outer = ast.parse(f"def __outer__({', '.join(free)}):\n    return None")
    outer.body[0].body = [fdef, ast.Return(ast.Name(fdef.name, ast.Load()))]
    ast.fix_missing_locations(outer)
    g = dict(fn.__globals__)
    g.setdefault("torch", torch)
    exec(compile(outer, fn.__code__.co_filename, "exec"), g)  # noqa: S102
    cells = dict(zip(fn.__code__.co_freevars, fn.__closure__ or ()))
    # find the inner code object
    inner_code = next(c for c in g["__outer__"].__code__.co_consts if isinstance(c, types.CodeType) and c.co_name == fdef.name)
    closure = tuple(cells[name] for name in inner_code.co_freevars) if inner_code.co_freevars else None
    new = types.FunctionType(inner_code, fn.__globals__, fn.__name__, fn.__defaults__, closure)
    new.__kwdefaults__ = fn.__kwdefaults__
    return new, n


def observe_with(name, C):
    torch._dynamo.reset()
    torch.manual_seed(0)
    try:
        return sed.norm(sed.CASES[name](C))
    except Exception as e:  # noqa: BLE001
        return {"raised": type(e).__name__, "msg": str(e).splitlines()[0][:160] if str(e) else ""}


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--backend", default="eager")
    ap.add_argument("--only", default=None)
    a = ap.parse_args()
    os.makedirs("results/side_effects_gb", exist_ok=True)
    out = open(f"results/side_effects_gb/{a.backend}.jsonl", "w", encoding="utf-8")
    names = a.only.split(",") if a.only else list(sed.CASES)
    print(f"torch {torch.__version__}; {len(names)} cases; backend {a.backend}", flush=True)
    inserted = {}

    def C_plain(f):
        return torch.compile(f, backend=a.backend)

    def C_gb(f):
        g, n = rewrite(f)
        inserted[id(f)] = n
        return torch.compile(g, backend=a.backend)

    n_new = 0
    for name in names:
        e = observe_with(name, lambda f: f)
        p = observe_with(name, C_plain)
        inserted.clear()
        g = observe_with(name, C_gb)
        n_ins = sum(inserted.values())
        both_raise = lambda x, y: isinstance(x, dict) and "raised" in x and isinstance(y, dict) and "raised" in y  # noqa: E731
        same_p = sed.close(e, p) or both_raise(e, p)
        same_g = sed.close(e, g) or both_raise(e, g)
        rec = {"case": name, "breaks": n_ins, "plain_same": same_p, "gb_same": same_g, "eager": e, "plain": p, "gb": g}
        rec["verdict"] = "ok" if same_g else ("NEW" if same_p else "DIFF(both)")
        out.write(json.dumps(rec) + "\n"); out.flush()
        if rec["verdict"] != "ok" or n_ins == 0:
            tag = rec["verdict"] if rec["verdict"] != "ok" else "no-breaks"
            if rec["verdict"] == "NEW":
                n_new += 1
            print(f"  {tag:10s} {name:44s} breaks={n_ins}  eager={json.dumps(e)[:90]}  gb={json.dumps(g)[:110]}", flush=True)
    print(f"DONE: {n_new} cases newly diverge with graph breaks", flush=True)


if __name__ == "__main__":
    main()
