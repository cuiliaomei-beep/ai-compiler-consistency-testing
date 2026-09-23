"""Phase 1: Python-level alias / view / mutation dependency analysis.

This is the technical core of the plan. Published measurements make the case
for it precisely: on a 77-bug torch.compile benchmark, five state-of-the-art
tools together detect 6 of 22 memory-related bugs, and the stated reason is
**not** missing operator coverage — every in-place operator was already
covered — but that those tools "fail to synthesise the complex, bug-triggering
usage patterns", because the bugs need in-place writes applied to *complex
tensor aliases or views constructed via under-explored patterns*.

So we do not synthesise those structures blindly. We **read them out of the
program**, state what the compiler must therefore preserve, and then perturb
them systematically.

The analysis is deliberately shallow: AST only, no symbolic execution, no
whole-program points-to. It has to be sound enough to *propose tests*, not to
prove safety — a wrong guess costs one extra test, and the dynamic oracles are
what actually decide.
"""
from __future__ import annotations

import ast
import inspect
import textwrap
from dataclasses import dataclass, field
from typing import Any, Callable, Dict, List, Optional, Sequence, Set, Tuple

# --------------------------------------------------------------------------
# vocabulary
# --------------------------------------------------------------------------

#: methods that return a tensor sharing storage with the receiver
VIEW_METHODS = {
    "view", "reshape", "permute", "transpose", "t", "squeeze", "unsqueeze",
    "expand", "expand_as", "select", "narrow", "as_strided", "detach",
    "flatten", "ravel", "unfold", "diagonal", "split", "chunk", "unbind",
    "view_as", "real", "imag", "movedim", "swapaxes", "swapdims", "alias",
}

#: methods that write through the receiver
INPLACE_EXTRA = {"copy_", "zero_", "fill_", "resize_", "set_", "scatter_",
                 "index_put_", "masked_fill_", "clamp_", "normal_", "uniform_"}

#: attributes whose value can change the compiled artifact's semantics
FACTOR_ATTRS = {
    "shape": "shape", "dtype": "dtype", "device": "device", "ndim": "rank",
    "requires_grad": "requires_grad", "is_cuda": "device", "itemsize": "dtype",
}
FACTOR_METHODS = {
    "size": "shape", "stride": "stride", "is_contiguous": "contiguous",
    "dim": "rank", "numel": "shape", "element_size": "dtype", "type": "dtype",
}


def _is_inplace_method(name: str) -> bool:
    return (name.endswith("_") and not name.startswith("_")) or name in INPLACE_EXTRA


# --------------------------------------------------------------------------
# results
# --------------------------------------------------------------------------

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
    partial: bool = False   # writes a sub-region (indexed / sliced) rather than all


@dataclass
class Fact:
    """A property the compiler must preserve, stated over program names.

    Each fact becomes a test obligation plus an oracle assertion.
    """
    id: str
    kind: str          # mutation_visible | partial_write | write_order | alias_returned
    statement: str
    names: List[str] = field(default_factory=list)
    lines: List[int] = field(default_factory=list)
    oracle: str = "mutation"   # which oracle checks it

    def as_dict(self) -> Dict[str, Any]:
        return {
            "id": self.id, "kind": self.kind, "statement": self.statement,
            "names": self.names, "lines": self.lines, "oracle": self.oracle,
        }


@dataclass
class Factor:
    """A semantic factor the program actually reads."""
    expr: str
    kind: str                  # shape | dtype | device | stride | rank | ...
    line: int
    in_branch: bool = False    # read inside a condition: changes control flow

    def as_dict(self) -> Dict[str, Any]:
        return {"expr": self.expr, "kind": self.kind, "line": self.line,
                "in_branch": self.in_branch}


@dataclass
class Boundary:
    """Values worth testing, derived from a predicate in the source.

    ``param`` and ``dim`` are what make a boundary *actionable*: knowing that
    ``x.shape[0] >= 32`` matters is useless unless the generator can also tell
    which argument to resize and along which dimension.
    """
    expr: str
    op: str
    constant: int
    values: List[int]
    line: int
    #: parameter the predicate reads, when it could be resolved
    param: Optional[str] = None
    #: which of that parameter's dimensions, for shape predicates
    dim: Optional[int] = None
    #: shape | scalar - a shape predicate resizes a tensor, a scalar
    #: predicate substitutes an argument value
    kind: str = "shape"

    def as_dict(self) -> Dict[str, Any]:
        return {"expr": self.expr, "op": self.op, "constant": self.constant,
                "values": self.values, "line": self.line, "param": self.param,
                "dim": self.dim, "kind": self.kind}


@dataclass
class IndexRelation:
    """A chain from a shape read to an indexing operation. Plan section 7.

    ``n = x.shape[0]; i = n - 1; y = x[i]`` recovers as
    ``x.shape[0] -> n -> i -> x[i]``, yielding the constraint ``0 <= i < n``.

    The goal is not to prove index safety - it is to find which shape/index
    relations could send eager and generated code down *different* semantic
    paths. Those are exactly the sizes worth probing: one below the derived
    bound, at it, and one above.
    """
    index_expr: str          # the expression used as an index
    source_param: str        # the tensor whose shape it came from
    source_dim: int
    chain: List[str]         # the names it flowed through
    indexed_param: str       # the tensor actually indexed
    offset: int              # constant offset relative to the dimension
    line: int

    def constraint(self) -> str:
        off = f" {self.offset:+d}" if self.offset else ""
        return f"0 <= {self.index_expr} < {self.source_param}.shape[{self.source_dim}]" \
               f"   (index = dim{off})"

    def probe_sizes(self) -> List[int]:
        """Dimension sizes that straddle where this index becomes invalid."""
        base = max(1, -self.offset)
        return sorted({base, base + 1, base + 2})

    def as_dict(self) -> Dict[str, Any]:
        return {"index_expr": self.index_expr, "source_param": self.source_param,
                "source_dim": self.source_dim, "chain": self.chain,
                "indexed_param": self.indexed_param, "offset": self.offset,
                "line": self.line, "constraint": self.constraint()}


@dataclass
class ParamFlag:
    """A parameter that steers control flow, and the values worth covering.

    Plan section 6.2: ``if use_fast:`` means the two branches are different
    programs after compilation, so both must be executed. Without this the
    generator never varies non-tensor arguments at all.
    """
    param: str
    values: List[Any]
    line: int
    reason: str

    def as_dict(self) -> Dict[str, Any]:
        return {"param": self.param, "values": self.values,
                "line": self.line, "reason": self.reason}


@dataclass
class Analysis:
    function: str
    params: List[str]
    returns: List[str]
    aliases: List[AliasEdge] = field(default_factory=list)
    mutations: List[Mutation] = field(default_factory=list)
    alias_groups: List[List[str]] = field(default_factory=list)
    facts: List[Fact] = field(default_factory=list)
    factors: List[Factor] = field(default_factory=list)
    boundaries: List[Boundary] = field(default_factory=list)
    flags: List[ParamFlag] = field(default_factory=list)
    index_relations: List[IndexRelation] = field(default_factory=list)
    operators: List[str] = field(default_factory=list)
    error: Optional[str] = None

    def as_dict(self) -> Dict[str, Any]:
        return {
            "function": self.function,
            "params": self.params,
            "returns": self.returns,
            "aliases": [vars(a) for a in self.aliases],
            "mutations": [vars(m) for m in self.mutations],
            "alias_groups": self.alias_groups,
            "facts": [f.as_dict() for f in self.facts],
            "factors": [f.as_dict() for f in self.factors],
            "boundaries": [b.as_dict() for b in self.boundaries],
            "flags": [f.as_dict() for f in self.flags],
            "index_relations": [r.as_dict() for r in self.index_relations],
            "operators": self.operators,
            "error": self.error,
        }


# --------------------------------------------------------------------------
# the visitor
# --------------------------------------------------------------------------

def _base_name(node: ast.AST) -> Optional[str]:
    """The root Name of an expression like ``x``, ``x[0]``, ``x.a[1]``."""
    while True:
        if isinstance(node, ast.Name):
            return node.id
        if isinstance(node, (ast.Subscript, ast.Attribute)):
            node = node.value
            continue
        return None


def _unparse(node: ast.AST) -> str:
    try:
        return ast.unparse(node)
    except Exception:  # pragma: no cover - very old pythons
        return "<expr>"


class _Walker(ast.NodeVisitor):
    def __init__(self) -> None:
        self.aliases: List[AliasEdge] = []
        self.mutations: List[Mutation] = []
        self.factors: List[Factor] = []
        self.boundaries: List[Boundary] = []
        self.flags: List[ParamFlag] = []
        self.index_relations: List[IndexRelation] = []
        self.returns: List[str] = []
        self.escapes: List[str] = []
        self._branch_depth = 0
        #: name -> (param, dim, constant offset, provenance chain)
        self._shape_bind: Dict[str, Tuple[str, int, int, List[str]]] = {}

    # -- structure ------------------------------------------------------
    def visit_Assign(self, node: ast.Assign) -> None:
        for tgt in node.targets:
            if isinstance(tgt, ast.Name):
                self._track_shape_binding(tgt.id, node.value, node.lineno)
                edge = self._view_edge(tgt.id, node.value, node.lineno)
                if edge:
                    self.aliases.append(edge)
            else:
                # x[i] = ... / obj.attr = ... : a write through the base
                base = _base_name(tgt)
                if base:
                    self.mutations.append(
                        Mutation(base, "subscript_store", node.lineno, partial=True)
                    )
                    if isinstance(tgt, ast.Attribute):
                        self.escapes.append(base)
        self.generic_visit(node)

    def visit_AugAssign(self, node: ast.AugAssign) -> None:
        base = _base_name(node.target)
        if base:
            partial = not isinstance(node.target, ast.Name)
            self.mutations.append(Mutation(base, "augassign", node.lineno, partial))
        self.generic_visit(node)

    def visit_Call(self, node: ast.Call) -> None:
        f = node.func
        if isinstance(f, ast.Attribute):
            recv = _base_name(f.value)
            if recv and _is_inplace_method(f.attr):
                partial = isinstance(f.value, ast.Subscript) or f.attr in {
                    "scatter_", "index_put_", "masked_fill_", "copy_"
                }
                self.mutations.append(Mutation(recv, f.attr, node.lineno, partial))
            if recv and f.attr in FACTOR_METHODS:
                self.factors.append(
                    Factor(_unparse(node), FACTOR_METHODS[f.attr], node.lineno,
                           self._branch_depth > 0)
                )
        self.generic_visit(node)

    def visit_Return(self, node: ast.Return) -> None:
        # Only names that ARE the result - the value itself, or a direct element
        # of a returned tuple/list. Walking the whole expression would call
        # `x` "returned" in `return (x * 2).sum()`, and the alias_returned fact
        # would then demand aliasing that the source never promised.
        v = node.value
        if isinstance(v, ast.Name):
            self.returns.append(v.id)
        elif isinstance(v, (ast.Tuple, ast.List)):
            for e in v.elts:
                if isinstance(e, ast.Name):
                    self.returns.append(e.id)
        self.generic_visit(node)

    # -- factors --------------------------------------------------------
    def visit_Attribute(self, node: ast.Attribute) -> None:
        if node.attr in FACTOR_ATTRS and _base_name(node.value):
            self.factors.append(
                Factor(_unparse(node), FACTOR_ATTRS[node.attr], node.lineno,
                       self._branch_depth > 0)
            )
        self.generic_visit(node)

    def visit_Subscript(self, node: ast.Subscript) -> None:
        self._record_index(node)
        self.generic_visit(node)

    # -- control flow ---------------------------------------------------
    def visit_If(self, node: ast.If) -> None:
        self._scan_predicate(node.test)
        self._branch_depth += 1
        for n in node.test.body if hasattr(node.test, "body") else []:
            self.visit(n)
        self.visit(node.test)
        self._branch_depth -= 1
        for stmt in node.body + node.orelse:
            self.visit(stmt)

    def visit_While(self, node: ast.While) -> None:
        self._scan_predicate(node.test)
        self.visit_If(ast.If(test=node.test, body=node.body, orelse=node.orelse))

    # -- helpers --------------------------------------------------------
    def _view_edge(self, target: str, value: ast.AST, line: int) -> Optional[AliasEdge]:
        if isinstance(value, ast.Call) and isinstance(value.func, ast.Attribute):
            if value.func.attr in VIEW_METHODS:
                src = _base_name(value.func.value)
                if src:
                    return AliasEdge(target, src, value.func.attr, line)
        if isinstance(value, ast.Subscript):
            # `n = x.shape[0]` subscripts an attribute, not a tensor - the
            # result is an int, and treating it as a view puts a scalar into the
            # alias group, which then claims the compiler must return it as an
            # alias of x.
            if isinstance(value.value, ast.Attribute) and \
                    value.value.attr in ("shape", "stride"):
                return None
            src = _base_name(value.value)
            if src:
                kind = "slice" if _has_slice(value.slice) else "index"
                return AliasEdge(target, src, kind, line)
        if isinstance(value, ast.Name):
            return AliasEdge(target, value.id, "rebind", line)
        return None

    # -- section 7: shape -> index dataflow ------------------------------
    def _track_shape_binding(self, target: str, value: ast.AST, line: int) -> None:
        """Record ``n = x.shape[0]`` and ``i = n - 1`` style bindings.

        A tiny constant-offset dataflow, deliberately: enough to recover which
        dimension an index derives from and by how much it is displaced, which
        is all the generator needs to pick sizes that straddle the boundary.
        """
        param, dim, kind = _resolve_target(value)
        if kind == "shape" and param is not None and dim is not None:
            self._shape_bind[target] = (param, dim, 0, [f"{param}.shape[{dim}]"])
            return
        # i = n + c  /  i = n - c
        if isinstance(value, ast.BinOp) and isinstance(value.op, (ast.Add, ast.Sub)):
            for a, b in ((value.left, value.right), (value.right, value.left)):
                if isinstance(a, ast.Name) and a.id in self._shape_bind:
                    c = _int_const(b)
                    if c is None:
                        continue
                    p, d, off, chain = self._shape_bind[a.id]
                    delta = c if isinstance(value.op, ast.Add) else -c
                    self._shape_bind[target] = (p, d, off + delta, chain + [target])
                    return
        if isinstance(value, ast.Name) and value.id in self._shape_bind:
            p, d, off, chain = self._shape_bind[value.id]
            self._shape_bind[target] = (p, d, off, chain + [target])

    def _record_index(self, node: ast.Subscript) -> None:
        """When a tracked name is used as an index, the relation is closed."""
        base = _base_name(node.value)
        if base is None:
            return
        for idx in _index_names(node.slice):
            if idx not in self._shape_bind:
                continue
            p, d, off, chain = self._shape_bind[idx]
            self.index_relations.append(IndexRelation(
                index_expr=idx, source_param=p, source_dim=d,
                chain=chain + [f"{base}[{idx}]"], indexed_param=base,
                offset=off, line=getattr(node, "lineno", 0)))

    def _scan_predicate(self, test: ast.AST) -> None:
        for node in ast.walk(test):
            if isinstance(node, ast.Compare) and len(node.ops) == 1:
                self._boundary(node.left, node.ops[0], node.comparators[0], node.lineno)

        self._scan_flags(test)

    def _scan_flags(self, node: ast.AST) -> None:
        """Find names used *as* a truth value, not merely mentioned.

        Only the condition's own structure is examined - descending through
        ``and`` / ``or`` / ``not`` but no further. Walking the whole subtree
        would flag `x` in ``if x.shape[0] >= 32``, and the generator would then
        try to substitute a boolean for a tensor.
        """
        line = getattr(node, "lineno", 0)
        if isinstance(node, ast.Name):
            self.flags.append(ParamFlag(
                node.id, [True, False], line, "used directly as a branch condition"))
        elif isinstance(node, ast.UnaryOp) and isinstance(node.op, ast.Not):
            self._scan_flags(node.operand)
        elif isinstance(node, ast.BoolOp):
            for v in node.values:
                self._scan_flags(v)
        elif isinstance(node, ast.Compare) and isinstance(node.left, ast.Name) \
                and len(node.comparators) == 1 \
                and isinstance(node.comparators[0], ast.Constant) \
                and node.comparators[0].value is None:
            self.flags.append(ParamFlag(
                node.left.id, [True, None], line, "compared against None"))

    def _boundary(self, left: ast.AST, op: ast.AST, right: ast.AST, line: int) -> None:
        const = _int_const(right)
        expr = left
        if const is None:  # try the mirrored form: K < x.shape[0]
            const = _int_const(left)
            expr = right
            if const is None:
                return
        opname = type(op).__name__

        # n % K == 0  ->  straddle multiples of K, where tiling/vectorization lives
        if isinstance(expr, ast.BinOp) and isinstance(expr.op, ast.Mod):
            k = _int_const(expr.right)
            if k and k > 1:
                vals = sorted({k - 1, k, k + 1, 2 * k - 1, 2 * k, 2 * k + 1})
                param, dim, kind = _resolve_target(expr.left)
                self.boundaries.append(
                    Boundary(_unparse(expr.left), f"%{k}", k, vals, line,
                             param=param, dim=dim, kind=kind)
                )
                return

        vals = sorted({const - 1, const, const + 1})
        param, dim, kind = _resolve_target(expr)
        self.boundaries.append(
            Boundary(_unparse(expr), opname, const, vals, line,
                     param=param, dim=dim, kind=kind))


def _resolve_target(node: ast.AST) -> Tuple[Optional[str], Optional[int], str]:
    """Which parameter does this predicate read, and how?

    Turns the textual expression into something a generator can act on:

        x.shape[0]  ->  ("x", 0, "shape")     resize x along dim 0
        x.size(1)   ->  ("x", 1, "shape")
        n           ->  ("n", None, "scalar") substitute the argument value

    Returns ``(None, None, "shape")`` when the target cannot be resolved, in
    which case the boundary is still recorded but cannot drive generation.
    """
    # x.shape[K], including negative indices - `x.shape[-1]` is extremely
    # common and was silently unrecognised, so every index chain through the
    # last dimension was lost.
    if isinstance(node, ast.Subscript) and isinstance(node.value, ast.Attribute) \
            and node.value.attr == "shape":
        base = _base_name(node.value.value)
        dim = _int_const(node.slice)
        if base is not None and dim is not None:
            return base, dim, "shape"
    # x.size(K)
    if isinstance(node, ast.Call) and isinstance(node.func, ast.Attribute) \
            and node.func.attr in ("size", "stride"):
        base = _base_name(node.func.value)
        dim = _int_const(node.args[0]) if node.args else None
        if base is not None and dim is not None:
            kind = "shape" if node.func.attr == "size" else "stride"
            return base, dim, kind
    # x.ndim / len(x)
    if isinstance(node, ast.Attribute) and node.attr in ("ndim", "dim"):
        base = _base_name(node.value)
        if base is not None:
            return base, None, "rank"
    # a bare parameter compared to a constant
    if isinstance(node, ast.Name):
        return node.id, None, "scalar"
    return None, None, "shape"


def _index_names(node: ast.AST) -> List[str]:
    """Names used as an index, anywhere inside the subscript.

    Recursion matters: ``x[..., m:m + 1]`` is a tuple containing an ellipsis and
    a slice whose bound is a binary op over ``m``. Checking only the tuple's
    direct elements finds nothing, and every index chain through a sliced last
    dimension is lost - which is what happened.
    """
    out: List[str] = []

    def walk(n: ast.AST) -> None:
        if isinstance(n, ast.Name):
            out.append(n.id)
        elif isinstance(n, ast.Tuple):
            for e in n.elts:
                walk(e)
        elif isinstance(n, ast.Slice):
            for part in (n.lower, n.upper, n.step):
                if part is not None:
                    walk(part)
        elif isinstance(n, ast.BinOp):
            walk(n.left)
            walk(n.right)
        elif isinstance(n, ast.UnaryOp):
            walk(n.operand)

    walk(node)
    return out


def _has_slice(node: ast.AST) -> bool:
    if isinstance(node, ast.Slice):
        return True
    if isinstance(node, ast.Tuple):
        return any(isinstance(e, ast.Slice) for e in node.elts)
    return False


def _int_const(node: ast.AST) -> Optional[int]:
    if isinstance(node, ast.Constant) and isinstance(node.value, int) \
            and not isinstance(node.value, bool):
        return node.value
    if isinstance(node, ast.UnaryOp) and isinstance(node.op, ast.USub):
        inner = _int_const(node.operand)
        return -inner if inner is not None else None
    return None


# --------------------------------------------------------------------------
# alias groups + facts
# --------------------------------------------------------------------------

def _group(aliases: Sequence[AliasEdge]) -> Dict[str, str]:
    """Union-find over alias edges; returns name -> representative."""
    parent: Dict[str, str] = {}

    def find(a: str) -> str:
        parent.setdefault(a, a)
        while parent[a] != a:
            parent[a] = parent[parent[a]]
            a = parent[a]
        return a

    def union(a: str, b: str) -> None:
        ra, rb = find(a), find(b)
        if ra != rb:
            parent[ra] = rb

    for e in aliases:
        union(e.target, e.source)
    return {k: find(k) for k in parent}


def _derive_facts(
    params: List[str],
    returns: List[str],
    aliases: List[AliasEdge],
    mutations: List[Mutation],
    groups: Dict[str, str],
) -> List[Fact]:
    facts: List[Fact] = []
    n = 0

    def nid() -> str:
        nonlocal n
        n += 1
        return f"FACT-{n}"

    members: Dict[str, List[str]] = {}
    for name, rep in groups.items():
        members.setdefault(rep, []).append(name)

    # 1. a write through an alias must be visible on the aliased parameter
    for m in mutations:
        rep = groups.get(m.target, m.target)
        touched = sorted(set(members.get(rep, [m.target])))
        visible_params = [p for p in params if p in touched and p != m.target]
        for p in visible_params:
            facts.append(Fact(
                nid(), "mutation_visible",
                f"`{m.target}.{m.op}` writes through an alias of parameter `{p}`, "
                f"so the caller's `{p}` must change",
                names=[m.target, p], lines=[m.line], oracle="mutation",
            ))
        if m.partial:
            facts.append(Fact(
                nid(), "partial_write",
                f"`{m.target}.{m.op}` writes only part of the tensor; every "
                f"element outside the written region must be preserved exactly",
                names=[m.target], lines=[m.line], oracle="mutation",
            ))

    # 2. write ordering between mutations that can touch the same storage
    for i in range(len(mutations)):
        for j in range(i + 1, len(mutations)):
            a, b = mutations[i], mutations[j]
            if groups.get(a.target, a.target) == groups.get(b.target, b.target):
                facts.append(Fact(
                    nid(), "write_order",
                    f"`{a.target}.{a.op}` (line {a.line}) and `{b.target}.{b.op}` "
                    f"(line {b.line}) write the same storage; their order must be "
                    f"preserved",
                    names=[a.target, b.target], lines=[a.line, b.line],
                    oracle="mutation",
                ))

    # 3. a returned alias of a parameter must still be an alias after compiling
    for r in set(returns):
        rep = groups.get(r)
        if rep is None:
            continue
        for p in params:
            if p != r and groups.get(p) == rep:
                facts.append(Fact(
                    nid(), "alias_returned",
                    f"the returned `{r}` shares storage with parameter `{p}`; "
                    f"the compiled version must return an alias, not a copy",
                    names=[r, p], oracle="alias",
                ))
    return facts


def _suggest_operators(
    aliases: List[AliasEdge], mutations: List[Mutation], escapes: List[str]
) -> List[str]:
    """Which structure-mutation operators are applicable to this function."""
    ops: List[str] = []
    if aliases:
        ops.append("DeepenView")
    sources = [e.source for e in aliases]
    if len(sources) != len(set(sources)):
        ops.append("AliasBranch")
    if len(mutations) >= 2:
        ops.append("ReorderMutation")
    if mutations:
        ops.append("AliasMutation")
    ops.append("NonContiguous")
    if escapes:
        ops.append("EscapeAlias")
    return ops


# --------------------------------------------------------------------------
# entry point
# --------------------------------------------------------------------------

def analyze_source(src: str, name: str = "<fn>") -> Analysis:
    try:
        tree = ast.parse(textwrap.dedent(src))
    except SyntaxError as e:
        return Analysis(function=name, params=[], returns=[], error=f"SyntaxError: {e}")

    fn = next((n for n in ast.walk(tree)
               if isinstance(n, (ast.FunctionDef, ast.AsyncFunctionDef))), None)
    if fn is None:
        return Analysis(function=name, params=[], returns=[],
                        error="no function definition found")

    params = [a.arg for a in fn.args.args] + [a.arg for a in fn.args.kwonlyargs]

    w = _Walker()
    for stmt in fn.body:
        w.visit(stmt)

    groups_map = _group(w.aliases)
    members: Dict[str, List[str]] = {}
    for k, rep in groups_map.items():
        members.setdefault(rep, []).append(k)

    facts = _derive_facts(params, w.returns, w.aliases, w.mutations, groups_map)

    seen: Set[Tuple[str, int]] = set()
    factors = []
    for f in w.factors:
        key = (f.expr, f.line)
        if key not in seen:
            seen.add(key)
            factors.append(f)

    # only flags that are actually parameters can be varied by the generator
    seen_flags: Set[str] = set()
    flags: List[ParamFlag] = []
    for fl in w.flags:
        if fl.param in params and fl.param not in seen_flags:
            seen_flags.add(fl.param)
            flags.append(fl)

    return Analysis(
        function=fn.name or name,
        params=params,
        returns=sorted(set(w.returns)),
        aliases=w.aliases,
        mutations=w.mutations,
        alias_groups=[sorted(v) for v in members.values() if len(v) > 1],
        facts=facts,
        factors=factors,
        boundaries=w.boundaries,
        flags=flags,
        index_relations=[r for r in w.index_relations if r.source_param in params],
        operators=_suggest_operators(w.aliases, w.mutations, w.escapes),
    )


def analyze(fn: Callable) -> Analysis:
    """Analyse a live function object."""
    try:
        src = inspect.getsource(fn)
    except (OSError, TypeError) as e:
        return Analysis(function=getattr(fn, "__name__", "<fn>"), params=[], returns=[],
                        error=f"source unavailable: {e}")
    return analyze_source(src, getattr(fn, "__name__", "<fn>"))


def format_analysis(a: Analysis) -> str:
    """Human-readable rendering, for `run.py analyze`."""
    L: List[str] = []
    L.append(f"  function : {a.function}({', '.join(a.params)})")
    if a.error:
        L.append(f"  ERROR    : {a.error}")
        return "\n".join(L)
    if a.returns:
        L.append(f"  returns  : {', '.join(a.returns)}")
    if a.aliases:
        L.append("  aliases  :")
        for e in a.aliases:
            L.append(f"      {e.target} <- {e.source}.{e.op}()   (line {e.line})")
    if a.alias_groups:
        L.append(f"  groups   : {a.alias_groups}")
    if a.mutations:
        L.append("  mutations:")
        for m in a.mutations:
            tag = " partial" if m.partial else ""
            L.append(f"      {m.target}.{m.op}{tag}   (line {m.line})")
    if a.factors:
        L.append("  factors  :")
        for f in a.factors:
            tag = "  <- in a branch, controls flow" if f.in_branch else ""
            L.append(f"      {f.expr}  [{f.kind}]{tag}")
    if a.flags:
        L.append("  control-flow flags:")
        for fl in a.flags:
            L.append(f"      {fl.param} -> {fl.values}   ({fl.reason})")
    if a.index_relations:
        L.append("  shape -> index relations:")
        for r in a.index_relations:
            L.append(f"      {' -> '.join(r.chain)}")
            L.append(f"          {r.constraint()}   probe sizes {r.probe_sizes()}")
    if a.boundaries:
        L.append("  boundary values to test:")
        for b in a.boundaries:
            tgt = f"  [{b.param}.dim{b.dim}]" if b.param and b.dim is not None else ""
            L.append(f"      {b.expr} {b.op} {b.constant}  ->  {b.values}{tgt}")
    if a.facts:
        L.append("  FACTS the compiler must preserve:")
        for f in a.facts:
            L.append(f"      [{f.id}] ({f.oracle}) {f.statement}")
    if a.operators:
        L.append(f"  applicable structure operators: {', '.join(a.operators)}")
    return "\n".join(L)
