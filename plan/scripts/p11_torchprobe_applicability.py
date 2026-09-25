"""P11-1: can TorchProbe (soodoshll/temisu) take our programs as seeds?

TorchProbe's seed is an NNSmith GIR: a list of ``(module_or_fn, input_vars, output_vars, nnsmith_op)``
instructions rendered to straight-line SSA tensor code (temisu/ir.py::TFunction), whose every
statement is a tensor-valued NNSmith operator. Its four mutations (temisu/mutator.py) then need a
concrete value profile of every statement (Mutator.profile executes the instruction list).

This script classifies each of our programs by AST features that the TFunction IR cannot represent,
and, for the representable ones, which of the four mutations would have a candidate site.

    python scripts/p11_torchprobe_applicability.py --out results/p11_baselines
"""
from __future__ import annotations

import argparse
import ast
import inspect
import json
import os
import sys
import textwrap
import warnings

warnings.filterwarnings("ignore")
sys.path.insert(0, os.path.dirname(os.path.dirname(os.path.abspath(__file__))))

import torch  # noqa: E402

# operators temisu/ir.py can render (CoreInstruction.render*), by torch call name
TEMISU_RENDERABLE = {
    "relu", "add", "gelu", "leaky_relu", "sigmoid", "sin", "cos", "asin", "acos", "tan", "atan", "abs", "where",
    "sub", "mul", "div", "max", "min", "eq", "gt", "lt", "logical_and", "logical_or", "logical_xor", "pow",
    "floor", "ceil", "clip", "round", "sqrt", "log2", "neg", "softmax", "max_pool2d", "avg_pool2d", "pad",
    "expand", "reshape", "flatten", "transpose", "interpolate", "squeeze", "sum", "mean", "argmin", "argmax",
    "tril", "triu", "cat", "matmul", "to",
}
# NNSmith elementwise ops temisu's desolve_op (operator resolution) accepts
TEMISU_ELEMENTWISE = {"relu", "add", "gelu", "leaky_relu", "sigmoid", "sin", "cos", "asin", "acos", "tan", "atan",
                      "abs", "mul", "div", "max", "min", "eq", "gt", "lt", "logical_and", "logical_or",
                      "logical_xor", "pow", "floor", "ceil", "clip", "round", "sqrt", "log2", "neg"}

TENSOR_ATTR_READS = {"shape", "dtype", "stride", "is_contiguous", "ndim", "dim", "numel", "size", "device",
                     "requires_grad", "item", "tolist", "data_ptr", "storage_offset", "grad"}


class Features(ast.NodeVisitor):
    def __init__(self):
        self.control_flow = []      # if/for/while/try/with/comprehensions/lambda/nested def/yield/raise/assert
        self.attr_reads = set()     # x.shape, x.dtype, ...
        self.inplace = []           # x[...] = v, x += v, x.add_(v)
        self.calls = set()          # torch.* / method names
        self.non_torch_calls = set()
        self.python_ops = 0         # BinOp on non-obvious tensors is fine; count Compare / BoolOp on scalars
        self.globals_ = set()
        self.returns = 0
        self.return_non_name = False
        self.dyn_index = []         # x[m], x[i], x[n-1] ... (only static slices are renderable)

    def visit_If(self, n): self.control_flow.append("if"); self.generic_visit(n)
    def visit_IfExp(self, n): self.control_flow.append("ifexp"); self.generic_visit(n)
    def visit_For(self, n): self.control_flow.append("for"); self.generic_visit(n)
    def visit_While(self, n): self.control_flow.append("while"); self.generic_visit(n)
    def visit_Try(self, n): self.control_flow.append("try"); self.generic_visit(n)
    def visit_With(self, n): self.control_flow.append("with"); self.generic_visit(n)
    def visit_ListComp(self, n): self.control_flow.append("comprehension"); self.generic_visit(n)
    def visit_SetComp(self, n): self.control_flow.append("comprehension"); self.generic_visit(n)
    def visit_DictComp(self, n): self.control_flow.append("comprehension"); self.generic_visit(n)
    def visit_GeneratorExp(self, n): self.control_flow.append("genexpr"); self.generic_visit(n)
    def visit_Lambda(self, n): self.control_flow.append("lambda"); self.generic_visit(n)
    def visit_Yield(self, n): self.control_flow.append("yield"); self.generic_visit(n)
    def visit_YieldFrom(self, n): self.control_flow.append("yield"); self.generic_visit(n)
    def visit_Raise(self, n): self.control_flow.append("raise"); self.generic_visit(n)
    def visit_Assert(self, n): self.control_flow.append("assert"); self.generic_visit(n)
    def visit_Global(self, n): self.globals_.update(n.names)
    def visit_Nonlocal(self, n): self.globals_.update(n.names)

    def visit_FunctionDef(self, n):
        if getattr(self, "_depth", 0) > 0:
            self.control_flow.append("nested_def")
        self._depth = getattr(self, "_depth", 0) + 1
        self.generic_visit(n)
        self._depth -= 1
    visit_AsyncFunctionDef = visit_FunctionDef

    def visit_ClassDef(self, n): self.control_flow.append("class_def"); self.generic_visit(n)

    def visit_Attribute(self, n):
        if n.attr in TENSOR_ATTR_READS and not isinstance(getattr(n, "ctx", None), ast.Store):
            self.attr_reads.add(n.attr)
        self.generic_visit(n)

    def visit_Assign(self, n):
        for t in n.targets:
            if isinstance(t, (ast.Subscript, ast.Attribute)):
                self.inplace.append(ast.unparse(t))
        self.generic_visit(n)

    def visit_AugAssign(self, n):
        self.inplace.append(ast.unparse(n.target) + " op=")
        self.generic_visit(n)

    def visit_Call(self, n):
        f = n.func
        name = None
        if isinstance(f, ast.Attribute):
            name = f.attr
            base = ast.unparse(f.value)
            if name.endswith("_") and not name.startswith("_"):
                self.inplace.append(f"{base}.{name}()")
            if base.startswith("torch") or base in ("F", "nn"):
                self.calls.add(name)
            else:
                self.calls.add(name)  # method call on a tensor or other object
        elif isinstance(f, ast.Name):
            name = f.id
            self.non_torch_calls.add(name)
        self.generic_visit(n)

    def visit_Subscript(self, n):
        # temisu renders only static slices (renderSlice); tensor / data-dependent indexing has no renderer
        if not isinstance(n.ctx, ast.Store):
            sl = n.slice
            parts = sl.elts if isinstance(sl, ast.Tuple) else [sl]
            static = all(isinstance(p, ast.Slice) and all(x is None or isinstance(x, ast.Constant) for x in (p.lower, p.upper, p.step))
                         or isinstance(p, ast.Constant) for p in parts)
            if not static:
                self.dyn_index.append(ast.unparse(n))
        self.generic_visit(n)

    def visit_Return(self, n):
        self.returns += 1
        if n.value is not None and not isinstance(n.value, (ast.Name, ast.Tuple)):
            self.return_non_name = True
        self.generic_visit(n)


def classify(fn, base_args):
    try:
        src = textwrap.dedent(inspect.getsource(fn))
    except (OSError, TypeError) as e:
        return {"error": f"no source: {e}"}
    try:
        tree = ast.parse(src)
    except SyntaxError as e:
        return {"error": f"syntax: {e}"}
    fdef = next((n for n in tree.body if isinstance(n, (ast.FunctionDef, ast.AsyncFunctionDef))), None)
    if fdef is None:
        return {"error": "no function def"}
    v = Features()
    v.visit(fdef)
    n_params = len(fdef.args.args) + len(fdef.args.kwonlyargs) + (1 if fdef.args.vararg else 0)
    non_tensor_args = [i for i, a in enumerate(base_args) if not isinstance(a, torch.Tensor)] if base_args is not None else None
    n_stmts = len(fdef.body)
    blockers = []
    if v.control_flow:
        blockers.append("control_flow:" + ",".join(sorted(set(v.control_flow))))
    if v.attr_reads:
        blockers.append("python_reads_tensor_metadata:" + ",".join(sorted(v.attr_reads)))
    if v.inplace:
        blockers.append("in_place_mutation")
    if v.dyn_index:
        blockers.append("non_static_indexing:" + ",".join(v.dyn_index[:3]))
    if non_tensor_args:
        blockers.append(f"non_tensor_args:{len(non_tensor_args)}")
    if v.globals_:
        blockers.append("global_state")
    # free variables (closures / module globals other than torch)
    code = fn.__code__
    free = [n for n in code.co_freevars]
    glob = [n for n in code.co_names if n in fn.__globals__ and not inspect.ismodule(fn.__globals__[n])
            and not callable(fn.__globals__[n])]
    if free:
        blockers.append("closure_vars:" + ",".join(free))
    if glob:
        blockers.append("module_globals:" + ",".join(sorted(set(glob))))
    unrenderable = sorted(c for c in v.calls if c not in TEMISU_RENDERABLE)
    other_calls = sorted(c for c in v.non_torch_calls if c not in ("torch",))
    if unrenderable:
        blockers.append("ops_outside_temisu_renderer:" + ",".join(unrenderable))
    if other_calls:
        blockers.append("python_calls:" + ",".join(other_calls))
    representable = not blockers
    elementwise = sorted(c for c in v.calls if c in TEMISU_ELEMENTWISE)
    n_tensor_args = (n_params - len(non_tensor_args)) if non_tensor_args is not None else n_params
    mut = {
        # insert_tcb: needs >= 2 tensors in the profile at some statement (inputs count)
        "insert_tcb": representable and (n_tensor_args + n_stmts - 1) >= 2,
        # desolve_op: an elementwise op from ELEMENTWISE_OP with same-shaped inputs (shape not checked here)
        "desolve_op": representable and bool(elementwise),
        # modify_then_recover: a non-input, non-constant tensor with ndim > 0 defined before another statement
        "modify_then_recover": representable and n_stmts >= 2,
        # subfunction: any statement range
        "subfunction": representable and n_stmts >= 1,
    }
    return {"n_stmts": n_stmts, "n_params": n_params, "non_tensor_args": non_tensor_args,
            "blockers": blockers, "representable_as_torchprobe_seed": representable,
            "mutations_with_candidate_site": [k for k, ok in mut.items() if ok],
            "elementwise_ops": elementwise, "calls": sorted(v.calls)}


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--out", default="results/p11_baselines")
    args = ap.parse_args()
    os.makedirs(args.out, exist_ok=True)
    rows = []
    # corpus (29)
    from tcc import corpus  # noqa: F401
    from tcc.program import all_programs
    for p in all_programs():
        try:
            base = p.make_inputs(p.base_context)
        except Exception:
            base = None
        r = classify(p.fn, base)
        r.update({"set": "corpus29", "program": p.name})
        rows.append(r)
    # dynamo semantics: the first 185 programs in registration order (the three modules dynamo_semantics,
    # dynamo_semantics_more, dynamo_semantics_batch3 hold 77 + 74 + 33 = 184 of them; batch4 registers a few
    # programs interleaved, so index 0..184 also contains one batch4 program). Module is recorded per row.
    from tcc import dynamo_semantics as ds
    n = 0
    for name, f in list(ds.PROGRAMS.items())[:185]:
        n += 1
        r = classify(f, (torch.zeros(2, 2),))
        r.update({"set": "dynsem185", "program": name, "module": f.__module__})
        rows.append(r)
    with open(os.path.join(args.out, "torchprobe_applicability.json"), "w", encoding="utf-8") as fh:
        json.dump(rows, fh, indent=1)
    # summary
    import collections
    summ = {}
    for s in ("corpus29", "dynsem185"):
        rs = [r for r in rows if r["set"] == s]
        rep = [r for r in rs if r.get("representable_as_torchprobe_seed")]
        bl = collections.Counter()
        for r in rs:
            for b in r.get("blockers", []):
                bl[b.split(":")[0]] += 1
        per_mut = collections.Counter(m for r in rep for m in r["mutations_with_candidate_site"])
        summ[s] = {"programs": len(rs), "representable": len(rep), "representable_names": [r["program"] for r in rep],
                   "blocker_frequency": dict(bl), "mutation_candidates_among_representable": dict(per_mut),
                   "modules": dict(collections.Counter(r.get("module", "tcc.corpus") for r in rs))}
    with open(os.path.join(args.out, "torchprobe_applicability_summary.json"), "w", encoding="utf-8") as fh:
        json.dump(summ, fh, indent=1)
    print(json.dumps(summ, indent=1))
    print("dynsem programs counted:", n)
    # markdown table for the corpus
    lines = ["| program | stmts | blockers (why TorchProbe cannot take it as a seed) | mutations with a site |", "|---|---:|---|---|"]
    for r in rows:
        if r["set"] != "corpus29":
            continue
        lines.append(f"| {r['program']} | {r.get('n_stmts', '-')} | {'; '.join(r.get('blockers', [])) or '(representable)'} | "
                     f"{', '.join(r.get('mutations_with_candidate_site', [])) or '-'} |")
    with open(os.path.join(args.out, "torchprobe_applicability_corpus29.md"), "w", encoding="utf-8") as fh:
        fh.write("\n".join(lines) + "\n")


if __name__ == "__main__":
    main()
