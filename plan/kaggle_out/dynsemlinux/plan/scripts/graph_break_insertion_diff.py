"""7.6  Graph-break insertion as a metamorphic relation over the Dynamo python-semantics corpus (tcc/dynamo_semantics*.py,
185 programs).  Every program is rewritten by AST so that `torch._dynamo.graph_break()` follows each statement --
variant "top": only the function's top-level statements; variant "deep": also inside for/while/if/with/try bodies
(never inside nested defs, lambdas or comprehensions).  graph_break() is a no-op in eager, so the eager result of the
rewritten program equals the original's; the compiled result must equal it too.  Programs whose divergence status
changes relative to the un-rewritten baseline (run in the same process, same torch) are the leads: Dynamo's resume
functions must carry locals, side effects, exception state and generator state across every break.
    python scripts/graph_break_insertion_diff.py [--backend eager|aot_eager|inductor]  -> results/graph_break_insertion/<backend>/
"""
import argparse
import ast
import inspect
import json
import os
import sys
import tempfile
import textwrap

os.environ.setdefault("TORCHINDUCTOR_CACHE_DIR", tempfile.mkdtemp(prefix="tcc_gb_"))
sys.path.insert(0, os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
from tcc.compat import ensure_msvc_env  # noqa: E402

ensure_msvc_env()
import torch  # noqa: E402

from tcc import dynamo_semantics as ds  # noqa: E402

GB = ast.parse("torch._dynamo.graph_break()").body[0]


class Insert(ast.NodeTransformer):
    def __init__(self, deep):
        self.deep = deep
        self.depth = 0

    def _body(self, stmts):
        out = []
        for s in stmts:
            s = self.visit(s) if self.deep else s
            out.append(s)
            if not isinstance(s, (ast.Return, ast.Raise, ast.Continue, ast.Break, ast.Global, ast.Nonlocal, ast.Pass)):
                out.append(ast.copy_location(GB, s))
        return out

    def generic_visit(self, node):
        if isinstance(node, (ast.FunctionDef, ast.AsyncFunctionDef, ast.Lambda, ast.ClassDef)):
            return node  # do not descend into nested definitions
        for field in ("body", "orelse", "finalbody"):
            if hasattr(node, field) and isinstance(getattr(node, field), list) and getattr(node, field) and isinstance(getattr(node, field)[0], ast.stmt):
                setattr(node, field, self._body(getattr(node, field)))
        if isinstance(node, ast.Try):
            for h in node.handlers:
                h.body = self._body(h.body)
        return node


def rewrite(f, deep):
    src = textwrap.dedent(inspect.getsource(f))
    mod = ast.parse(src)
    fn = mod.body[0]
    assert isinstance(fn, ast.FunctionDef), ast.dump(fn)[:80]
    fn.decorator_list = []
    fn.name = "_rw"
    fn.body = Insert(deep)._body(fn.body) if not deep else Insert(deep).generic_visit(fn).body
    ast.fix_missing_locations(mod)
    ns = dict(f.__globals__)
    exec(compile(mod, f"<rw:{f.__name__}>", "exec"), ns)  # noqa: S102
    g = ns["_rw"]
    g.__globals__.update({k: v for k, v in ns.items() if k not in g.__globals__})
    return g, sum(isinstance(n, ast.Expr) and isinstance(n.value, ast.Call) and ast.unparse(n.value) == "torch._dynamo.graph_break()" for n in ast.walk(fn))


def run_variant(programs, backend, log):
    ds.PROGRAMS.clear(); ds.PROGRAMS.update(programs)
    res = ds.sweep(backend=backend, log=log)
    return {(d["program"], d["call"]): (d["what"], d["eager"], d["compiled"]) for d in res["divergences"]}


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--backend", default="eager")
    a = ap.parse_args()
    out_dir = os.path.join("results", "graph_break_insertion", a.backend)
    os.makedirs(out_dir, exist_ok=True)
    original = dict(ds.PROGRAMS)
    print(f"torch {torch.__version__}; {len(original)} programs; backend {a.backend}", flush=True)
    quiet = lambda *s: None  # noqa: E731
    base = run_variant(original, a.backend, quiet)
    print(f"baseline divergences: {len(base)}", flush=True)
    report = {"torch": torch.__version__, "backend": a.backend, "baseline": len(base), "variants": {}}
    for deep in (False, True):
        vname = "deep" if deep else "top"
        rw, counts, failed = {}, {}, {}
        for name, f in original.items():
            try:
                rw[name], counts[name] = rewrite(f, deep)
            except Exception as ex:  # noqa: BLE001
                failed[name] = f"{type(ex).__name__}: {ex}"[:120]
        div = run_variant(rw, a.backend, quiet)
        new = {k: v for k, v in div.items() if k not in base}
        gone = {k: v for k, v in base.items() if k not in div}
        changed = {k: (base[k], v) for k, v in div.items() if k in base and base[k][2] != v[2]}
        print(f"[{vname}] rewritten {len(rw)} (breaks inserted: {sum(counts.values())}), rewrite failed {len(failed)}; divergences {len(div)}: new {len(new)}, gone {len(gone)}, changed {len(changed)}", flush=True)
        for k, v in new.items():
            print(f"  NEW  {k[0]:<36} call{k[1]} {v[0]:<6} eager={v[1][:100]}  compiled={v[2][:100]}", flush=True)
        for k, (b, v) in changed.items():
            print(f"  CHG  {k[0]:<36} call{k[1]} {v[0]:<6} base={b[2][:80]}  now={v[2][:80]}", flush=True)
        for k, v in gone.items():
            print(f"  GONE {k[0]:<36} call{k[1]} (baseline diverged, rewritten does not)", flush=True)
        report["variants"][vname] = {"rewritten": len(rw), "breaks": sum(counts.values()), "rewrite_failed": failed,
                                     "new": {f"{k[0]}#{k[1]}": v for k, v in new.items()}, "gone": {f"{k[0]}#{k[1]}": v for k, v in gone.items()},
                                     "changed": {f"{k[0]}#{k[1]}": v for k, v in changed.items()}, "all": {f"{k[0]}#{k[1]}": v for k, v in div.items()}}
    json.dump(report, open(os.path.join(out_dir, "report.json"), "w", encoding="utf-8"), indent=1)
    print("DONE", flush=True)


if __name__ == "__main__":
    main()
