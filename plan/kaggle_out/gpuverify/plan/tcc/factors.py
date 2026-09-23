"""Plan sections 6-8: semantic factor analysis.

Given a function's source, decide **which Python semantic factors could change
what the compiled artifact must compute**. Not every tensor attribute is a
factor - only the ones the program actually reads on a path to an observable
result. The output is consumed by :mod:`tcc.scs` (signature + obligations).

Section 6.1  TensorState abstraction per tensor parameter
Section 6.2  Python scalar / flag analysis (``if use_fast:``)
Section 6.3  shape boundary constraints (``x.shape[0] >= 32`` -> 31/32/33,
             ``n % 16 == 0`` -> 15/16/17/31/32/33)
Section 7    shape -> index relations (``n = x.shape[0]; i = n-1; x[i]``)
Section 8    alias / mutation facts (``y = x.view(-1); y[0] += 1; return x``)
"""
from __future__ import annotations

import ast
import inspect
import textwrap
from dataclasses import dataclass, field
from typing import Any, Dict, List, Optional, Set, Tuple

from .ir import IR, build_ir_from_source, base_name, is_inplace_method, unparse

FACTOR_ATTRS = {
    "shape": "shape", "dtype": "dtype", "device": "device", "ndim": "rank",
    "requires_grad": "requires_grad", "is_cuda": "device", "itemsize": "dtype",
    "layout": "layout", "is_sparse": "layout", "grad": "requires_grad",
}
FACTOR_METHODS = {
    "size": "shape", "stride": "stride", "is_contiguous": "contiguous",
    "dim": "rank", "numel": "shape", "element_size": "dtype", "type": "dtype",
    "storage_offset": "stride", "is_floating_point": "dtype", "is_complex": "dtype",
    "__len__": "shape",
}


# --------------------------------------------------------------------------
# results
# --------------------------------------------------------------------------

@dataclass
class TensorState:
    """Section 6.1: the abstract state kept per tensor parameter."""
    param: str
    reads: List[str] = field(default_factory=list)      # rank/shape[d]/dtype/device/stride[d]/contiguous/requires_grad
    alias_group: List[str] = field(default_factory=list)
    mutated: bool = False

    def as_dict(self) -> Dict[str, Any]:
        return {"param": self.param, "reads": self.reads,
                "alias_group": self.alias_group, "mutated": self.mutated}


@dataclass
class Factor:
    expr: str
    kind: str            # shape | dtype | device | stride | contiguous | rank | requires_grad | layout
    param: Optional[str]
    dim: Optional[int]
    line: int
    in_branch: bool = False
    reaches_observable: bool = True
    ir_node: Optional[int] = None

    def as_dict(self) -> Dict[str, Any]:
        return {"expr": self.expr, "kind": self.kind, "param": self.param, "dim": self.dim,
                "line": self.line, "in_branch": self.in_branch,
                "reaches_observable": self.reaches_observable}


@dataclass
class ScalarFactor:
    """Section 6.2: a non-tensor parameter that steers control flow or values."""
    param: str
    role: str             # flag | none_check | compare | index | loop_bound | reshape_dim | string | container
    values: List[Any]
    line: int
    reason: str

    def as_dict(self) -> Dict[str, Any]:
        return {"param": self.param, "role": self.role, "values": self.values,
                "line": self.line, "reason": self.reason}


@dataclass
class Boundary:
    """Section 6.3: values that straddle a predicate constant."""
    expr: str
    op: str
    constant: int
    values: List[int]
    line: int
    param: Optional[str] = None
    dim: Optional[int] = None
    kind: str = "shape"   # shape | scalar | stride | rank

    def as_dict(self) -> Dict[str, Any]:
        return {"expr": self.expr, "op": self.op, "constant": self.constant,
                "values": self.values, "line": self.line, "param": self.param,
                "dim": self.dim, "kind": self.kind}


@dataclass
class IndexRelation:
    """Section 7: ``x.shape[0] -> n -> i -> x[i]`` with ``0 <= i < x.shape[0]``."""
    index_expr: str
    source_param: str
    source_dim: int
    chain: List[str]
    indexed_param: str
    offset: int
    line: int
    op: str = "index"     # index | slice | gather | scatter | reshape | view | mask

    def constraint(self) -> str:
        off = f" {self.offset:+d}" if self.offset else ""
        return f"0 <= {self.index_expr} < {self.source_param}.shape[{self.source_dim}]  (index = dim{off})"

    def probe_sizes(self) -> List[int]:
        base = max(1, -self.offset)
        return sorted({base, base + 1, base + 2})

    def as_dict(self) -> Dict[str, Any]:
        return {"index_expr": self.index_expr, "source_param": self.source_param,
                "source_dim": self.source_dim, "chain": self.chain,
                "indexed_param": self.indexed_param, "offset": self.offset,
                "line": self.line, "op": self.op, "constraint": self.constraint(),
                "probe_sizes": self.probe_sizes()}


@dataclass
class AliasEdge:
    target: str
    source: str
    op: str
    line: int


@dataclass
class Mutation:
    target: str
    op: str
    line: int
    partial: bool = False
    in_branch: bool = False


@dataclass
class Fact:
    """Section 8: a structural property the compiler must preserve."""
    id: str
    kind: str        # mutation_visible | partial_write | write_order | alias_returned | state_write | exception_path
    statement: str
    names: List[str] = field(default_factory=list)
    lines: List[int] = field(default_factory=list)
    oracle: str = "mutation"

    def as_dict(self) -> Dict[str, Any]:
        return {"id": self.id, "kind": self.kind, "statement": self.statement,
                "names": self.names, "lines": self.lines, "oracle": self.oracle}


@dataclass
class Analysis:
    function: str
    params: List[str]
    returns: List[str]
    tensor_states: List[TensorState] = field(default_factory=list)
    factors: List[Factor] = field(default_factory=list)
    scalars: List[ScalarFactor] = field(default_factory=list)
    boundaries: List[Boundary] = field(default_factory=list)
    index_relations: List[IndexRelation] = field(default_factory=list)
    aliases: List[AliasEdge] = field(default_factory=list)
    mutations: List[Mutation] = field(default_factory=list)
    alias_groups: List[List[str]] = field(default_factory=list)
    facts: List[Fact] = field(default_factory=list)
    state_reads: List[str] = field(default_factory=list)
    state_writes: List[str] = field(default_factory=list)
    raises: List[str] = field(default_factory=list)
    reshape_dims: List[str] = field(default_factory=list)
    loop_bounds: List[str] = field(default_factory=list)
    #: parameters read together in one predicate (``flag and x.shape[0] > 32``)
    predicate_groups: List[List[str]] = field(default_factory=list)
    ir: Optional[IR] = None
    error: Optional[str] = None
    analysis_ms: float = 0.0

    def as_dict(self) -> Dict[str, Any]:
        return {
            "function": self.function, "params": self.params, "returns": self.returns,
            "tensor_states": [t.as_dict() for t in self.tensor_states],
            "factors": [f.as_dict() for f in self.factors],
            "scalars": [s.as_dict() for s in self.scalars],
            "boundaries": [b.as_dict() for b in self.boundaries],
            "index_relations": [r.as_dict() for r in self.index_relations],
            "aliases": [vars(a) for a in self.aliases],
            "mutations": [vars(m) for m in self.mutations],
            "alias_groups": self.alias_groups,
            "facts": [f.as_dict() for f in self.facts],
            "state_reads": self.state_reads, "state_writes": self.state_writes,
            "raises": self.raises, "reshape_dims": self.reshape_dims,
            "loop_bounds": self.loop_bounds, "predicate_groups": self.predicate_groups,
            "error": self.error,
            "analysis_ms": round(self.analysis_ms, 3),
            "ir_nodes": len(self.ir.nodes) if self.ir else 0,
        }


# --------------------------------------------------------------------------
# small AST helpers
# --------------------------------------------------------------------------

def _straddle(opname: str, k: int, mirrored: bool = False) -> List[int]:
    """``k`` first, then the neighbour on the other side of the predicate, then the rest."""
    if mirrored:
        opname = {"Gt": "Lt", "Lt": "Gt", "GtE": "LtE", "LtE": "GtE"}.get(opname, opname)
    if opname in ("GtE", "Lt"):        # x >= k : k is True, k-1 is False
        return _dedupe([k, k - 1, k + 1])
    if opname in ("Gt", "LtE"):        # x > k  : k is False, k+1 is True
        return _dedupe([k, k + 1, k - 1])
    return _dedupe([k, k + 1, k - 1])  # ==, != and anything else


def _dedupe(vals: List[int]) -> List[int]:
    out: List[int] = []
    for v in vals:
        if v not in out:
            out.append(v)
    return out


def _int_const(node: ast.AST) -> Optional[int]:
    if isinstance(node, ast.Constant) and isinstance(node.value, int) and not isinstance(node.value, bool):
        return node.value
    if isinstance(node, ast.UnaryOp) and isinstance(node.op, ast.USub):
        v = _int_const(node.operand)
        return -v if v is not None else None
    return None


def _resolve_target(node: ast.AST) -> Tuple[Optional[str], Optional[int], str]:
    """``x.shape[0]`` -> (x, 0, shape); ``x.size(1)`` -> (x, 1, shape); ``n`` -> (n, None, scalar)."""
    if isinstance(node, ast.Subscript) and isinstance(node.value, ast.Attribute) \
            and node.value.attr == "shape":
        b = base_name(node.value.value)
        d = _int_const(node.slice)
        if b is not None and d is not None:
            return b, d, "shape"
    if isinstance(node, ast.Call) and isinstance(node.func, ast.Attribute) \
            and node.func.attr in ("size", "stride"):
        b = base_name(node.func.value)
        d = _int_const(node.args[0]) if node.args else None
        if b is not None and d is not None:
            return b, d, "shape" if node.func.attr == "size" else "stride"
    if isinstance(node, ast.Call) and isinstance(node.func, ast.Name) and node.func.id == "len" \
            and node.args:
        b = base_name(node.args[0])
        if b is not None:
            return b, 0, "shape"
    if isinstance(node, ast.Attribute) and node.attr in ("ndim",):
        b = base_name(node.value)
        if b is not None:
            return b, None, "rank"
    if isinstance(node, ast.Call) and isinstance(node.func, ast.Attribute) and node.func.attr == "dim":
        b = base_name(node.func.value)
        if b is not None:
            return b, None, "rank"
    if isinstance(node, ast.Name):
        return node.id, None, "scalar"
    return None, None, "shape"


def _index_names(node: ast.AST) -> List[str]:
    out: List[str] = []

    def walk(n: ast.AST) -> None:
        if isinstance(n, ast.Name):
            out.append(n.id)
        elif isinstance(n, ast.Tuple):
            for e in n.elts:
                walk(e)
        elif isinstance(n, ast.Slice):
            for p in (n.lower, n.upper, n.step):
                if p is not None:
                    walk(p)
        elif isinstance(n, (ast.BinOp,)):
            walk(n.left)
            walk(n.right)
        elif isinstance(n, ast.UnaryOp):
            walk(n.operand)
    walk(node)
    return out


# --------------------------------------------------------------------------
# the walker
# --------------------------------------------------------------------------

class _Walker(ast.NodeVisitor):
    def __init__(self, params: List[str]):
        self.params = params
        self.factors: List[Factor] = []
        self.scalars: List[ScalarFactor] = []
        self.boundaries: List[Boundary] = []
        self.index_relations: List[IndexRelation] = []
        self.aliases: List[AliasEdge] = []
        self.mutations: List[Mutation] = []
        self.returns: List[str] = []
        self.escapes: List[str] = []
        self.raises: List[str] = []
        self.reshape_dims: List[str] = []
        self.loop_bounds: List[str] = []
        self.predicate_groups: List[List[str]] = []
        self._depth = 0        # inside a predicate expression
        self._body = 0         # inside a branch / loop body
        self._shape_bind: Dict[str, Tuple[str, int, int, List[str]]] = {}

    # -- statements -------------------------------------------------------
    def visit_Assign(self, node: ast.Assign) -> None:
        for t in node.targets:
            if isinstance(t, ast.Name):
                self._track_shape(t.id, node.value, node.lineno)
                self._alias_edge(t.id, node.value, node.lineno)
            elif isinstance(t, ast.Tuple):
                for e in t.elts:
                    if isinstance(e, ast.Name):
                        self._alias_edge(e.id, node.value, node.lineno, unpack=True)
            else:
                b = base_name(t)
                if b:
                    self.mutations.append(Mutation(b, f"store:{unparse(t)}", node.lineno,
                                                   partial=isinstance(t, ast.Subscript),
                                                   in_branch=self._body > 0))
                    if isinstance(t, ast.Attribute):
                        self.escapes.append(b)
        self.generic_visit(node)

    def visit_AugAssign(self, node: ast.AugAssign) -> None:
        b = base_name(node.target)
        if b:
            self.mutations.append(Mutation(b, f"augassign:{unparse(node.target)}", node.lineno,
                                           partial=not isinstance(node.target, ast.Name),
                                           in_branch=self._body > 0))
        self.generic_visit(node)

    def visit_Call(self, node: ast.Call) -> None:
        f = node.func
        if isinstance(f, ast.Attribute):
            recv = base_name(f.value)
            if recv and is_inplace_method(f.attr):
                partial = isinstance(f.value, ast.Subscript) or f.attr in {
                    "scatter_", "index_put_", "masked_fill_", "copy_"}
                self.mutations.append(Mutation(recv, f.attr, node.lineno, partial, self._body > 0))
            if recv and f.attr in FACTOR_METHODS:
                kind = FACTOR_METHODS[f.attr]
                dim = _int_const(node.args[0]) if node.args else None
                self.factors.append(Factor(unparse(node), kind, recv, dim, node.lineno, self._depth > 0))
            if recv and f.attr in ("view", "reshape", "expand", "repeat", "unflatten"):
                for a in node.args:
                    for nm in _index_names(a):
                        if nm in self.params or nm in self._shape_bind:
                            self.reshape_dims.append(f"{recv}.{f.attr}({unparse(a)})")
                        if nm in self.params:
                            self.scalars.append(ScalarFactor(nm, "reshape_dim", [1, 2, 4, 8], node.lineno,
                                                             f"used as a {f.attr} dimension of {recv}"))
            if recv and f.attr in ("gather", "scatter", "scatter_", "index_select", "masked_select",
                                   "masked_fill", "masked_fill_", "index_put_", "take", "index_add_"):
                for a in node.args:
                    for nm in _index_names(a):
                        if nm in self._shape_bind:
                            p, d, off, chain = self._shape_bind[nm]
                            self.index_relations.append(IndexRelation(
                                nm, p, d, chain + [f"{recv}.{f.attr}({nm})"], recv, off,
                                node.lineno, op=f.attr.rstrip("_")))
        if isinstance(f, ast.Name) and f.id == "len" and node.args:
            b = base_name(node.args[0])
            if b:
                self.factors.append(Factor(unparse(node), "shape", b, 0, node.lineno, self._depth > 0))
        self.generic_visit(node)

    def visit_Attribute(self, node: ast.Attribute) -> None:
        if node.attr in FACTOR_ATTRS:
            b = base_name(node.value)
            if b:
                self.factors.append(Factor(unparse(node), FACTOR_ATTRS[node.attr], b, None,
                                           node.lineno, self._depth > 0))
        self.generic_visit(node)

    def visit_Subscript(self, node: ast.Subscript) -> None:
        if isinstance(node.value, ast.Attribute) and node.value.attr == "shape":
            b = base_name(node.value.value)
            d = _int_const(node.slice)
            if b:
                # replace the generic "x.shape" factor with the precise dim
                self.factors.append(Factor(unparse(node), "shape", b, d, node.lineno, self._depth > 0))
        else:
            self._record_index(node)
        self.generic_visit(node)

    def visit_Return(self, node: ast.Return) -> None:
        v = node.value
        if isinstance(v, ast.Name):
            self.returns.append(v.id)
        elif isinstance(v, (ast.Tuple, ast.List)):
            for e in v.elts:
                if isinstance(e, ast.Name):
                    self.returns.append(e.id)
        self.generic_visit(node)

    def visit_Raise(self, node: ast.Raise) -> None:
        self.raises.append(unparse(node.exc) if node.exc else "re-raise")
        self.generic_visit(node)

    def visit_Assert(self, node: ast.Assert) -> None:
        self._scan_predicate(node.test)
        self.raises.append(f"assert {unparse(node.test)}")
        self.generic_visit(node)

    # -- control flow -----------------------------------------------------
    def _visit_body(self, stmts: List[ast.stmt]) -> None:
        self._body += 1
        for s in stmts:
            self.visit(s)
        self._body -= 1

    def visit_If(self, node: ast.If) -> None:
        self._scan_predicate(node.test)
        self._depth += 1
        self.visit(node.test)
        self._depth -= 1
        self._visit_body(node.body + node.orelse)

    def visit_IfExp(self, node: ast.IfExp) -> None:
        self._scan_predicate(node.test)
        self.generic_visit(node)

    def visit_While(self, node: ast.While) -> None:
        self._scan_predicate(node.test)
        self.loop_bounds.append(unparse(node.test))
        self._depth += 1
        self.visit(node.test)
        self._depth -= 1
        self._visit_body(node.body + node.orelse)

    def visit_For(self, node: ast.For) -> None:
        it = node.iter
        self.loop_bounds.append(unparse(it))
        if isinstance(it, ast.Call) and isinstance(it.func, ast.Name) and it.func.id == "range":
            for a in it.args:
                p, d, k = _resolve_target(a)
                if p in self.params:
                    if k == "shape" and d is not None:
                        self.factors.append(Factor(unparse(a), "shape", p, d, node.lineno, True))
                    elif k == "scalar":
                        self.scalars.append(ScalarFactor(p, "loop_bound", [0, 1, 2, 3], node.lineno,
                                                         "used as a range() bound"))
                for nm in _index_names(a):
                    if nm in self._shape_bind:
                        p2, d2, off, chain = self._shape_bind[nm]
                        self.factors.append(Factor(nm, "shape", p2, d2, node.lineno, True))
        self._depth += 1
        self.visit(it)
        self._depth -= 1
        self._visit_body(node.body + node.orelse)

    # -- helpers ----------------------------------------------------------
    def _alias_edge(self, target: str, value: ast.AST, line: int, unpack: bool = False) -> None:
        if isinstance(value, ast.Call) and isinstance(value.func, ast.Attribute):
            from .ir import VIEW_METHODS
            if value.func.attr in VIEW_METHODS:
                src = base_name(value.func.value)
                if src:
                    self.aliases.append(AliasEdge(target, src, value.func.attr, line))
                    return
        if isinstance(value, ast.Attribute) and value.attr in ("T", "mT", "H", "mH", "real", "imag"):
            src = base_name(value.value)
            if src:
                self.aliases.append(AliasEdge(target, src, value.attr, line))
                return
        if isinstance(value, ast.Subscript) and not unpack:
            if isinstance(value.value, ast.Attribute) and value.value.attr in ("shape", "stride"):
                return
            src = base_name(value.value)
            if src:
                has_slice = isinstance(value.slice, ast.Slice) or (
                    isinstance(value.slice, ast.Tuple) and any(isinstance(e, ast.Slice) for e in value.slice.elts))
                self.aliases.append(AliasEdge(target, src, "slice" if has_slice else "index", line))
                return
        if isinstance(value, ast.Name) and not unpack:
            self.aliases.append(AliasEdge(target, value.id, "rebind", line))

    def _track_shape(self, target: str, value: ast.AST, line: int) -> None:
        p, d, k = _resolve_target(value)
        if k == "shape" and p is not None and d is not None:
            self._shape_bind[target] = (p, d, 0, [f"{p}.shape[{d}]"])
            return
        if isinstance(value, ast.BinOp) and isinstance(value.op, (ast.Add, ast.Sub)):
            for a, b in ((value.left, value.right), (value.right, value.left)):
                if isinstance(a, ast.Name) and a.id in self._shape_bind:
                    c = _int_const(b)
                    if c is None:
                        continue
                    pp, dd, off, chain = self._shape_bind[a.id]
                    delta = c if isinstance(value.op, ast.Add) else -c
                    if b is value.left and isinstance(value.op, ast.Sub):
                        continue  # c - n is not an offset of n
                    self._shape_bind[target] = (pp, dd, off + delta, chain + [target])
                    return
        if isinstance(value, ast.BinOp) and isinstance(value.op, (ast.FloorDiv, ast.Mult, ast.Mod)):
            for a in (value.left, value.right):
                if isinstance(a, ast.Name) and a.id in self._shape_bind:
                    pp, dd, off, chain = self._shape_bind[a.id]
                    self._shape_bind[target] = (pp, dd, off, chain + [target])
                    return
        if isinstance(value, ast.Name) and value.id in self._shape_bind:
            pp, dd, off, chain = self._shape_bind[value.id]
            self._shape_bind[target] = (pp, dd, off, chain + [target])
            return
        # idx = torch.arange(n - 1): a value derived from a tracked shape keeps its chain
        if isinstance(value, ast.Call):
            for a in value.args:
                for nm in _index_names(a):
                    if nm in self._shape_bind:
                        pp, dd, off, chain = self._shape_bind[nm]
                        c = 0
                        if isinstance(a, ast.BinOp) and isinstance(a.op, (ast.Add, ast.Sub)):
                            cc = _int_const(a.right)
                            if cc is not None:
                                c = cc if isinstance(a.op, ast.Add) else -cc
                        self._shape_bind[target] = (pp, dd, off + c, chain + [f"{unparse(value.func)}({unparse(a)})", target])
                        return

    def _record_index(self, node: ast.Subscript) -> None:
        b = base_name(node.value)
        if b is None:
            return
        has_slice = isinstance(node.slice, ast.Slice) or (
            isinstance(node.slice, ast.Tuple) and any(isinstance(e, ast.Slice) for e in node.slice.elts))
        for idx in _index_names(node.slice):
            if idx in self._shape_bind:
                p, d, off, chain = self._shape_bind[idx]
                self.index_relations.append(IndexRelation(
                    idx, p, d, chain + [f"{b}[{unparse(node.slice)}]"], b, off,
                    getattr(node, "lineno", 0), op="slice" if has_slice else "index"))
            elif idx in self.params:
                # a scalar parameter used directly as an index
                self.scalars.append(ScalarFactor(idx, "index", [0, 1, -1], getattr(node, "lineno", 0),
                                                 f"used as an index into {b}"))

    def _scan_predicate(self, test: ast.AST) -> None:
        for n in ast.walk(test):
            if isinstance(n, ast.Compare) and len(n.ops) == 1:
                self._boundary(n.left, n.ops[0], n.comparators[0], getattr(n, "lineno", 0))
        self._scan_flags(test)
        if isinstance(test, ast.BoolOp):
            names: List[str] = []
            for n in ast.walk(test):
                if not isinstance(n, ast.Name):
                    continue
                nm = n.id
                if nm in self._shape_bind:
                    nm = self._shape_bind[nm][0]
                if nm in self.params and nm not in names:
                    names.append(nm)
            if len(names) >= 2 and names not in self.predicate_groups:
                self.predicate_groups.append(names)

    def _scan_flags(self, node: ast.AST) -> None:
        line = getattr(node, "lineno", 0)
        if isinstance(node, ast.Name):
            self.scalars.append(ScalarFactor(node.id, "flag", [True, False], line,
                                             "used directly as a branch condition"))
        elif isinstance(node, ast.UnaryOp) and isinstance(node.op, ast.Not):
            self._scan_flags(node.operand)
        elif isinstance(node, ast.BoolOp):
            for v in node.values:
                self._scan_flags(v)
        elif isinstance(node, ast.Compare) and isinstance(node.left, ast.Name) and len(node.comparators) == 1:
            c = node.comparators[0]
            if isinstance(c, ast.Constant):
                if c.value is None:
                    self.scalars.append(ScalarFactor(node.left.id, "none_check", [None, "<non-None>"],
                                                     line, "compared against None"))
                elif isinstance(c.value, str):
                    self.scalars.append(ScalarFactor(node.left.id, "string", [c.value, f"not:{c.value}"],
                                                     line, f"compared against the string {c.value!r}"))
                elif isinstance(c.value, bool):
                    self.scalars.append(ScalarFactor(node.left.id, "flag", [True, False], line,
                                                     "compared against a bool"))
            elif isinstance(c, ast.Attribute):
                # enum-like: mode == Mode.FAST
                self.scalars.append(ScalarFactor(node.left.id, "enum", [unparse(c), f"not:{unparse(c)}"],
                                                 line, f"compared against {unparse(c)}"))
        elif isinstance(node, ast.Call) and isinstance(node.func, ast.Name) and node.func.id == "len" \
                and node.args and isinstance(node.args[0], ast.Name):
            self.scalars.append(ScalarFactor(node.args[0].id, "container", [0, 1, 2], line,
                                             "container length used as a truth value"))
        elif isinstance(node, ast.Compare) and isinstance(node.left, ast.Call) \
                and isinstance(node.left.func, ast.Name) and node.left.func.id == "len":
            pass  # handled as a boundary
        elif isinstance(node, ast.Compare) and isinstance(node.left, ast.Name) \
                and len(node.comparators) == 1 and isinstance(node.ops[0], (ast.In, ast.NotIn)):
            self.scalars.append(ScalarFactor(node.left.id, "container", ["in", "not-in"], line,
                                             f"membership test against {unparse(node.comparators[0])}"))

    def _boundary(self, left: ast.AST, op: ast.AST, right: ast.AST, line: int) -> None:
        const = _int_const(right)
        expr = left
        if const is None:
            const = _int_const(left)
            expr = right
            if const is None:
                return
        opname = type(op).__name__
        if isinstance(expr, ast.BinOp) and isinstance(expr.op, ast.Mod):
            k = _int_const(expr.right)
            if k and k > 1:
                # boundary first, then the tail (k+1), then k-1: tiling and
                # vectorisation defects live at the boundary and its tail
                vals = _dedupe([k, k + 1, k - 1, 2 * k, 2 * k + 1, 2 * k - 1])
                p, d, kind = _resolve_target(expr.left)
                if kind == "scalar" and p in self._shape_bind:
                    pp, dd, off, _ = self._shape_bind[p]
                    vals = _dedupe([v - off for v in vals if v - off > 0])
                    p, d, kind = pp, dd, "shape"
                self.boundaries.append(Boundary(unparse(expr.left), f"%{k}", k, vals, line, p, d, kind))
                return
        if isinstance(expr, ast.BinOp) and isinstance(expr.op, (ast.Mult, ast.FloorDiv)):
            # x.shape[0] * 2 > 64  ->  straddle 32
            kk = _int_const(expr.right)
            if kk:
                base_c = const // kk if isinstance(expr.op, ast.Mult) else const * kk
                p, d, kind = _resolve_target(expr.left)
                vals = _dedupe([v for v in (base_c, base_c + 1, base_c - 1) if v > 0])
                self.boundaries.append(Boundary(unparse(expr), opname, const, vals, line, p, d, kind))
                return
        p, d, kind = _resolve_target(expr)
        if p is None:
            # n - 1 >= 32 style: look for a tracked shape binding
            for nm in _index_names(expr):
                if nm in self._shape_bind:
                    pp, dd, off, _ = self._shape_bind[nm]
                    c2 = const - off
                    vals = _dedupe([v for v in (c2, c2 + 1, c2 - 1) if v > 0])
                    self.boundaries.append(Boundary(unparse(expr), opname, const, vals, line, pp, dd, "shape"))
                    return
            return
        if kind == "scalar" and p in self._shape_bind:
            pp, dd, off, _ = self._shape_bind[p]
            c2 = const - off
            vals = _dedupe([v for v in (c2, c2 + 1, c2 - 1) if v > 0])
            self.boundaries.append(Boundary(unparse(expr), opname, const, vals, line, pp, dd, "shape"))
            return
        # the first two values straddle the predicate: k and its opposite-side
        # neighbour, so a pair of values already covers both branches
        mirrored = expr is right  # constant was on the left: K < x  means  x > K
        vals = _straddle(opname, const, mirrored)
        if kind in ("shape", "rank"):
            vals = [v for v in vals if v > 0]
        self.boundaries.append(Boundary(unparse(expr), opname, const, vals, line, p, d, kind))


# --------------------------------------------------------------------------
# alias groups + facts (section 8)
# --------------------------------------------------------------------------

def _union_find(aliases: List[AliasEdge]) -> Dict[str, str]:
    parent: Dict[str, str] = {}

    def find(a: str) -> str:
        parent.setdefault(a, a)
        while parent[a] != a:
            parent[a] = parent[parent[a]]
            a = parent[a]
        return a

    for e in aliases:
        ra, rb = find(e.target), find(e.source)
        if ra != rb:
            parent[ra] = rb
    return {k: find(k) for k in parent}


def _facts(params: List[str], returns: List[str], mutations: List[Mutation],
           groups: Dict[str, str], escapes: List[str], raises: List[str],
           state_writes: List[str]) -> List[Fact]:
    facts: List[Fact] = []
    n = 0

    def nid() -> str:
        nonlocal n
        n += 1
        return f"FACT-{n}"

    members: Dict[str, List[str]] = {}
    for name, rep in groups.items():
        members.setdefault(rep, []).append(name)

    for m in mutations:
        rep = groups.get(m.target, m.target)
        touched = sorted(set(members.get(rep, [m.target])))
        for p in params:
            if p in touched and p != m.target:
                facts.append(Fact(nid(), "mutation_visible",
                                  f"`{m.target}.{m.op}` writes through an alias of parameter `{p}`; "
                                  f"the caller's `{p}` must change accordingly",
                                  [m.target, p], [m.line], "mutation"))
        if m.target in params:
            facts.append(Fact(nid(), "mutation_visible",
                              f"`{m.target}.{m.op}` writes parameter `{m.target}` in place; "
                              f"the caller must observe the write",
                              [m.target], [m.line], "mutation"))
        if m.partial:
            facts.append(Fact(nid(), "partial_write",
                              f"`{m.target}.{m.op}` writes a sub-region; every element outside it "
                              f"must be preserved exactly", [m.target], [m.line], "mutation"))
        if m.in_branch:
            facts.append(Fact(nid(), "conditional_mutation",
                              f"`{m.target}.{m.op}` happens only on one branch; the write must be "
                              f"visible exactly when the branch is taken", [m.target], [m.line], "mutation"))
    for i in range(len(mutations)):
        for j in range(i + 1, len(mutations)):
            a, b = mutations[i], mutations[j]
            if groups.get(a.target, a.target) == groups.get(b.target, b.target):
                facts.append(Fact(nid(), "write_order",
                                  f"`{a.target}.{a.op}` (line {a.line}) and `{b.target}.{b.op}` "
                                  f"(line {b.line}) write the same storage; their order must be preserved",
                                  [a.target, b.target], [a.line, b.line], "mutation"))
    for r in sorted(set(returns)):
        rep = groups.get(r)
        if rep is None:
            continue
        for p in params:
            if p != r and groups.get(p) == rep:
                facts.append(Fact(nid(), "alias_returned",
                                  f"the returned `{r}` shares storage with parameter `{p}`; the compiled "
                                  f"version must return an alias, not a copy", [r, p], [], "alias"))
    for e in sorted(set(escapes)):
        facts.append(Fact(nid(), "state_write",
                          f"an attribute of `{e}` is assigned; the state change must be visible after the call",
                          [e], [], "mutation"))
    for s in sorted(set(state_writes)):
        facts.append(Fact(nid(), "state_write",
                          f"`{s}` is written; global/module state must change identically", [s], [], "mutation"))
    for r in raises:
        facts.append(Fact(nid(), "exception_path",
                          f"`{r}` can raise; the compiled version must raise under the same condition",
                          [], [], "exception"))
    return facts


# --------------------------------------------------------------------------
# entry points
# --------------------------------------------------------------------------

def analyze_source(src: str, name: str = "<fn>") -> Analysis:
    import time
    t0 = time.perf_counter()
    try:
        tree = ast.parse(textwrap.dedent(src))
    except SyntaxError as e:
        return Analysis(function=name, params=[], returns=[], error=f"SyntaxError: {e}")
    fn = next((n for n in ast.walk(tree) if isinstance(n, (ast.FunctionDef, ast.AsyncFunctionDef))), None)
    if fn is None:
        return Analysis(function=name, params=[], returns=[], error="no function definition found")
    params = [a.arg for a in fn.args.posonlyargs + fn.args.args + fn.args.kwonlyargs]
    if fn.args.vararg is not None:
        params.append(fn.args.vararg.arg)   # `*args`: the first positional stands in for it

    w = _Walker(params)
    for stmt in fn.body:
        w.visit(stmt)

    ir = build_ir_from_source(src, name)
    groups = _union_find(w.aliases)
    members: Dict[str, List[str]] = {}
    for k, rep in groups.items():
        members.setdefault(rep, []).append(k)

    state_reads = sorted({s for n in ir.nodes for s in n.state if n.kind != "StateWrite"})
    state_writes = sorted({s for n in ir.nodes if n.kind == "StateWrite" for s in n.state})

    # dedupe factors, keep the precise shape[d] over the bare shape read
    seen: Set[Tuple[str, int]] = set()
    factors: List[Factor] = []
    for f in w.factors:
        if f.param not in params:
            continue
        key = (f.expr, f.line)
        if key in seen:
            continue
        seen.add(key)
        # does the statement reading it reach an observable node?
        node = next((n for n in ir.nodes if n.line == f.line), None)
        if node is not None:
            f.ir_node = node.id
            f.reaches_observable = ir.reaches_observable(node.id) or node.kind in ("Return", "Branch", "Mutation")
        factors.append(f)
    # drop bare "x.shape" when "x.shape[d]" exists on the same line
    precise = {(f.param, f.line) for f in factors if f.kind == "shape" and f.dim is not None}
    factors = [f for f in factors if not (f.kind == "shape" and f.dim is None and (f.param, f.line) in precise)]

    scalars: List[ScalarFactor] = []
    seen_s: Set[Tuple[str, str]] = set()
    for s in w.scalars:
        if s.param in params and (s.param, s.role) not in seen_s:
            seen_s.add((s.param, s.role))
            scalars.append(s)

    tensor_states: List[TensorState] = []
    for p in params:
        ts = TensorState(p)
        for f in factors:
            if f.param == p:
                tag = f.kind + (f"[{f.dim}]" if f.dim is not None else "")
                if tag not in ts.reads:
                    ts.reads.append(tag)
        rep = groups.get(p)
        ts.alias_group = sorted(members.get(rep, [p])) if rep else [p]
        ts.mutated = any(groups.get(m.target, m.target) == groups.get(p, p) for m in w.mutations)
        tensor_states.append(ts)

    facts = _facts(params, w.returns, w.mutations, groups, w.escapes, w.raises, state_writes)

    a = Analysis(
        function=fn.name, params=params, returns=sorted(set(w.returns)),
        tensor_states=tensor_states, factors=factors, scalars=scalars,
        boundaries=w.boundaries, index_relations=[r for r in w.index_relations if r.source_param in params],
        aliases=w.aliases, mutations=w.mutations,
        alias_groups=[sorted(v) for v in members.values() if len(v) > 1],
        facts=facts, state_reads=state_reads, state_writes=state_writes,
        raises=w.raises, reshape_dims=w.reshape_dims, loop_bounds=w.loop_bounds,
        predicate_groups=w.predicate_groups, ir=ir,
    )
    a.analysis_ms = (time.perf_counter() - t0) * 1000.0
    return a


def analyze(fn, source: Optional[str] = None) -> Analysis:
    if source is None:
        try:
            source = inspect.getsource(fn)
        except (OSError, TypeError) as e:
            return Analysis(function=getattr(fn, "__name__", "<fn>"), params=[], returns=[],
                            error=f"source unavailable: {e}")
    return analyze_source(source, getattr(fn, "__name__", "<fn>"))


def format_analysis(a: Analysis) -> str:
    L: List[str] = [f"  function : {a.function}({', '.join(a.params)})"]
    if a.error:
        L.append(f"  ERROR    : {a.error}")
        return "\n".join(L)
    if a.returns:
        L.append(f"  returns  : {', '.join(a.returns)}")
    for ts in a.tensor_states:
        if ts.reads or ts.mutated or len(ts.alias_group) > 1:
            L.append(f"  state({ts.param}): reads={ts.reads} alias_group={ts.alias_group} mutated={ts.mutated}")
    if a.factors:
        L.append("  factors  :")
        for f in a.factors:
            tag = "  <- in a branch" if f.in_branch else ""
            tag += "" if f.reaches_observable else "  (does not reach an observable)"
            L.append(f"      {f.expr:<28} [{f.kind}]{tag}")
    if a.scalars:
        L.append("  scalar/flag factors:")
        for s in a.scalars:
            L.append(f"      {s.param:<12} {s.role:<10} -> {s.values}   ({s.reason})")
    if a.boundaries:
        L.append("  boundaries:")
        for b in a.boundaries:
            tgt = f"  [{b.param}" + (f".dim{b.dim}]" if b.dim is not None else "]") if b.param else ""
            L.append(f"      {b.expr} {b.op} {b.constant}  ->  {b.values}{tgt}")
    if a.index_relations:
        L.append("  shape -> index relations:")
        for r in a.index_relations:
            L.append(f"      {' -> '.join(r.chain)}")
            L.append(f"          {r.constraint()}   probe sizes {r.probe_sizes()}")
    if a.aliases:
        L.append("  aliases  :")
        for e in a.aliases:
            L.append(f"      {e.target} <- {e.source}.{e.op}   (line {e.line})")
    if a.alias_groups:
        L.append(f"  groups   : {a.alias_groups}")
    if a.mutations:
        L.append("  mutations:")
        for m in a.mutations:
            L.append(f"      {m.target}.{m.op}{' partial' if m.partial else ''}"
                     f"{' conditional' if m.in_branch else ''}   (line {m.line})")
    if a.state_reads or a.state_writes:
        L.append(f"  state    : reads={a.state_reads} writes={a.state_writes}")
    if a.raises:
        L.append(f"  raises   : {a.raises}")
    if a.reshape_dims:
        L.append(f"  reshape  : {a.reshape_dims}")
    if a.facts:
        L.append("  FACTS the compiler must preserve:")
        for f in a.facts:
            L.append(f"      [{f.id}] ({f.oracle}) {f.statement}")
    L.append(f"  analysis : {a.analysis_ms:.2f} ms, IR {len(a.ir.nodes) if a.ir else 0} nodes")
    return "\n".join(L)
