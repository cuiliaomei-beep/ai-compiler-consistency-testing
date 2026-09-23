"""Plan section 5.2: a lightweight IR over the Python front end.

One node per statement, classified as::

    Assign  Call  Branch  Loop  Index  Mutation  Return  Raise  StateRead  StateWrite

and four dependency relations between nodes:

- **data**    : a node uses a name the other node defines (last reaching def)
- **control** : a node is nested inside a Branch / Loop
- **alias**   : the node binds a name to a view of another name
- **state**   : the node reads or writes global / closure / attribute state

The IR is what the semantic-factor analysis (section 6-8) walks to say
"``x.shape[0]`` -> branch -> observable result", and what program
minimization (section 17.2) uses to delete statements the failure does not
need. It is deliberately shallow: no SSA, no symbolic execution. A wrong
guess costs one extra test; the dynamic oracles decide.
"""
from __future__ import annotations

import ast
import builtins
import textwrap
from dataclasses import dataclass, field
from typing import Any, Dict, List, Optional, Set, Tuple

VIEW_METHODS = {
    "view", "reshape", "permute", "transpose", "t", "squeeze", "unsqueeze",
    "expand", "expand_as", "select", "narrow", "as_strided", "detach",
    "flatten", "ravel", "unfold", "diagonal", "split", "chunk", "unbind",
    "view_as", "real", "imag", "movedim", "swapaxes", "swapdims", "alias",
    "T", "mT", "H", "mH",
}
INPLACE_EXTRA = {"copy_", "zero_", "fill_", "resize_", "set_", "scatter_",
                 "index_put_", "masked_fill_", "clamp_", "normal_", "uniform_"}
_BUILTINS = set(dir(builtins))


def is_inplace_method(name: str) -> bool:
    return (name.endswith("_") and not name.startswith("_")) or name in INPLACE_EXTRA


def base_name(node: ast.AST) -> Optional[str]:
    while True:
        if isinstance(node, ast.Name):
            return node.id
        if isinstance(node, (ast.Subscript, ast.Attribute)):
            node = node.value
            continue
        return None


def unparse(node: ast.AST) -> str:
    try:
        return ast.unparse(node)
    except Exception:
        return "<expr>"


@dataclass
class Node:
    id: int
    kind: str
    line: int
    text: str
    defs: List[str] = field(default_factory=list)
    uses: List[str] = field(default_factory=list)
    parent: Optional[int] = None          # control parent
    #: Assign nodes: (target, source, view-op) when the RHS is a view
    alias: Optional[Tuple[str, str, str]] = None
    #: Mutation nodes: (target, op, partial)
    mutation: Optional[Tuple[str, str, bool]] = None
    #: index expressions read in this statement (base, index-text)
    indexes: List[Tuple[str, str]] = field(default_factory=list)
    state: List[str] = field(default_factory=list)
    ast_node: Any = None

    def as_dict(self) -> Dict[str, Any]:
        return {
            "id": self.id, "kind": self.kind, "line": self.line, "text": self.text,
            "defs": self.defs, "uses": self.uses, "parent": self.parent,
            "alias": list(self.alias) if self.alias else None,
            "mutation": list(self.mutation) if self.mutation else None,
            "indexes": [list(i) for i in self.indexes], "state": self.state,
        }


@dataclass
class Dep:
    src: int
    dst: int
    kind: str      # data | control | alias | state
    name: str = ""

    def as_dict(self) -> Dict[str, Any]:
        return {"src": self.src, "dst": self.dst, "kind": self.kind, "name": self.name}


@dataclass
class IR:
    function: str
    params: List[str]
    nodes: List[Node] = field(default_factory=list)
    deps: List[Dep] = field(default_factory=list)
    error: Optional[str] = None

    def by_kind(self, kind: str) -> List[Node]:
        return [n for n in self.nodes if n.kind == kind]

    def preds(self, nid: int, kinds: Optional[Set[str]] = None) -> List[int]:
        return [d.src for d in self.deps if d.dst == nid and (kinds is None or d.kind in kinds)]

    def succs(self, nid: int, kinds: Optional[Set[str]] = None) -> List[int]:
        return [d.dst for d in self.deps if d.src == nid and (kinds is None or d.kind in kinds)]

    def backward_slice(self, roots: List[int], kinds: Optional[Set[str]] = None) -> Set[int]:
        seen: Set[int] = set()
        stack = list(roots)
        while stack:
            n = stack.pop()
            if n in seen:
                continue
            seen.add(n)
            stack.extend(self.preds(n, kinds))
        return seen

    def forward_slice(self, roots: List[int], kinds: Optional[Set[str]] = None) -> Set[int]:
        seen: Set[int] = set()
        stack = list(roots)
        while stack:
            n = stack.pop()
            if n in seen:
                continue
            seen.add(n)
            stack.extend(self.succs(n, kinds))
        return seen

    def observable_nodes(self) -> List[int]:
        return [n.id for n in self.nodes if n.kind in ("Return", "Raise", "Mutation", "StateWrite")]

    def reaches_observable(self, nid: int) -> bool:
        fwd = self.forward_slice([nid], {"data", "control", "alias"})
        return any(o in fwd for o in self.observable_nodes())

    def as_dict(self) -> Dict[str, Any]:
        return {"function": self.function, "params": self.params,
                "nodes": [n.as_dict() for n in self.nodes],
                "deps": [d.as_dict() for d in self.deps], "error": self.error}


# --------------------------------------------------------------------------
# builder
# --------------------------------------------------------------------------

def _names_loaded(node: ast.AST) -> List[str]:
    return [n.id for n in ast.walk(node) if isinstance(n, ast.Name) and isinstance(n.ctx, ast.Load)]


def _names_stored(node: ast.AST) -> List[str]:
    out: List[str] = []
    for n in ast.walk(node):
        if isinstance(n, ast.Name) and isinstance(n.ctx, ast.Store):
            out.append(n.id)
    return out


def _view_of(value: ast.AST) -> Optional[Tuple[str, str]]:
    """(source name, op) when ``value`` is a view of a name."""
    if isinstance(value, ast.Call) and isinstance(value.func, ast.Attribute):
        if value.func.attr in VIEW_METHODS:
            src = base_name(value.func.value)
            if src:
                return src, value.func.attr
    if isinstance(value, ast.Attribute) and value.attr in ("T", "mT", "H", "mH", "real", "imag"):
        src = base_name(value.value)
        if src:
            return src, value.attr
    if isinstance(value, ast.Subscript):
        if isinstance(value.value, ast.Attribute) and value.value.attr in ("shape", "stride"):
            return None  # x.shape[0] is an int, not a view
        src = base_name(value.value)
        if src:
            has_slice = isinstance(value.slice, ast.Slice) or (
                isinstance(value.slice, ast.Tuple) and any(isinstance(e, ast.Slice) for e in value.slice.elts))
            return src, ("slice" if has_slice else "index")
    if isinstance(value, ast.Name):
        return value.id, "rebind"
    return None


def _index_reads(stmt: ast.AST) -> List[Tuple[str, str]]:
    out: List[Tuple[str, str]] = []
    for n in ast.walk(stmt):
        if isinstance(n, ast.Subscript) and isinstance(n.ctx, ast.Load):
            if isinstance(n.value, ast.Attribute) and n.value.attr in ("shape", "stride"):
                continue
            b = base_name(n.value)
            if b:
                out.append((b, unparse(n.slice)))
    return out


class _Builder:
    def __init__(self, fn: ast.AST, params: List[str]):
        self.params = params
        self.nodes: List[Node] = []
        self.deps: List[Dep] = []
        self.local: Set[str] = set(params)
        for n in ast.walk(fn):
            self.local |= set(_names_stored(n))
        self.declared_global: Set[str] = set()
        for n in ast.walk(fn):
            if isinstance(n, (ast.Global, ast.Nonlocal)):
                self.declared_global |= set(n.names)
        self.local -= self.declared_global

    def _new(self, kind: str, stmt: ast.AST, parent: Optional[int]) -> Node:
        node = Node(id=len(self.nodes), kind=kind, line=getattr(stmt, "lineno", 0),
                    text=unparse(stmt).splitlines()[0][:80], parent=parent, ast_node=stmt)
        self.nodes.append(node)
        return node

    def _external(self, stmt: ast.AST) -> List[str]:
        out: List[str] = []
        for nm in _names_loaded(stmt):
            if nm in self.local or nm in _BUILTINS or nm in ("torch", "self"):
                continue
            if nm not in out:
                out.append(nm)
        for n in ast.walk(stmt):
            if isinstance(n, ast.Attribute) and isinstance(n.value, ast.Name) and n.value.id == "self":
                tag = f"self.{n.attr}"
                if tag not in out:
                    out.append(tag)
        return out

    def build(self, body: List[ast.stmt], parent: Optional[int] = None) -> None:
        for stmt in body:
            self._stmt(stmt, parent)

    def _stmt(self, stmt: ast.stmt, parent: Optional[int]) -> None:
        if isinstance(stmt, (ast.If,)):
            n = self._new("Branch", stmt.test, parent)
            n.text = "if " + unparse(stmt.test)
            n.uses = _names_loaded(stmt.test)
            n.indexes = _index_reads(stmt.test)
            n.state = self._external(stmt.test)
            self.build(stmt.body, n.id)
            self.build(stmt.orelse, n.id)
            return
        if isinstance(stmt, (ast.While, ast.For)):
            n = self._new("Loop", stmt, parent)
            if isinstance(stmt, ast.For):
                n.defs = _names_stored(stmt.target)
                n.uses = _names_loaded(stmt.iter)
                n.text = f"for {unparse(stmt.target)} in {unparse(stmt.iter)}"
            else:
                n.uses = _names_loaded(stmt.test)
                n.text = "while " + unparse(stmt.test)
            n.state = self._external(stmt)
            self.build(stmt.body, n.id)
            self.build(stmt.orelse, n.id)
            return
        if isinstance(stmt, (ast.With,)):
            n = self._new("Call", stmt, parent)
            n.uses = [x for it in stmt.items for x in _names_loaded(it.context_expr)]
            n.defs = [x for it in stmt.items if it.optional_vars for x in _names_stored(it.optional_vars)]
            self.build(stmt.body, n.id)
            return
        if isinstance(stmt, ast.Try):
            n = self._new("Branch", stmt, parent)
            n.text = "try"
            self.build(stmt.body, n.id)
            for h in stmt.handlers:
                self.build(h.body, n.id)
            self.build(stmt.orelse, n.id)
            self.build(stmt.finalbody, n.id)
            return
        if isinstance(stmt, ast.Return):
            n = self._new("Return", stmt, parent)
            if stmt.value is not None:
                n.uses = _names_loaded(stmt.value)
                n.indexes = _index_reads(stmt.value)
                n.state = self._external(stmt.value)
            return
        if isinstance(stmt, ast.Raise):
            n = self._new("Raise", stmt, parent)
            n.uses = _names_loaded(stmt)
            return
        if isinstance(stmt, (ast.Assign, ast.AnnAssign, ast.AugAssign)):
            self._assign(stmt, parent)
            return
        if isinstance(stmt, ast.Expr):
            self._expr(stmt, parent)
            return
        if isinstance(stmt, (ast.FunctionDef, ast.AsyncFunctionDef, ast.ClassDef)):
            n = self._new("Assign", stmt, parent)
            n.defs = [stmt.name]
            n.text = f"def {stmt.name}"
            return
        if isinstance(stmt, (ast.Global, ast.Nonlocal)):
            n = self._new("StateRead", stmt, parent)
            n.state = list(stmt.names)
            return
        n = self._new("Call", stmt, parent)
        n.uses = _names_loaded(stmt)
        n.defs = _names_stored(stmt)

    def _assign(self, stmt: ast.stmt, parent: Optional[int]) -> None:
        targets: List[ast.AST]
        value: Optional[ast.AST]
        if isinstance(stmt, ast.Assign):
            targets, value = stmt.targets, stmt.value
        elif isinstance(stmt, ast.AnnAssign):
            targets, value = [stmt.target], stmt.value
        else:
            targets, value = [stmt.target], stmt.value

        # subscript / attribute store is a write through the base name
        for t in targets:
            if isinstance(t, (ast.Subscript, ast.Attribute)) or isinstance(stmt, ast.AugAssign) \
                    and not isinstance(t, ast.Name):
                b = base_name(t)
                if b is None:
                    continue
                n = self._new("Mutation", stmt, parent)
                partial = isinstance(t, ast.Subscript)
                op = "augassign" if isinstance(stmt, ast.AugAssign) else "store"
                n.mutation = (b, f"{op}:{unparse(t)}", partial)
                n.uses = _names_loaded(stmt)
                n.defs = []
                n.indexes = _index_reads(stmt)
                if isinstance(t, ast.Attribute):
                    if b == "self" or b not in self.local:
                        n.kind = "StateWrite"
                        n.state = [unparse(t)]
                n.state += [s for s in self._external(stmt) if s not in n.state]
                return

        n = self._new("Assign", stmt, parent)
        n.defs = [x for t in targets for x in _names_stored(t)]
        n.uses = _names_loaded(value) if value is not None else []
        if isinstance(stmt, ast.AugAssign):
            n.uses += _names_loaded(stmt.target)
        n.indexes = _index_reads(value) if value is not None else []
        n.state = self._external(value) if value is not None else []
        if any(nm in self.declared_global for nm in n.defs):
            n.kind = "StateWrite"
            n.state += [nm for nm in n.defs if nm in self.declared_global]
        if value is not None and len(n.defs) == 1:
            v = _view_of(value)
            if v is not None:
                n.alias = (n.defs[0], v[0], v[1])
        if value is not None and any(isinstance(x, ast.Call) for x in ast.walk(value)) \
                and n.kind == "Assign":
            n.kind = "Assign"  # keep Assign; calls inside are still data flow
        if n.state and n.kind == "Assign":
            # reading module / closure state is a state dependency
            self.deps.append(Dep(n.id, n.id, "state", ",".join(n.state)))

    def _expr(self, stmt: ast.Expr, parent: Optional[int]) -> None:
        v = stmt.value
        if isinstance(v, ast.Call) and isinstance(v.func, ast.Attribute):
            recv = base_name(v.func.value)
            if recv and is_inplace_method(v.func.attr):
                n = self._new("Mutation", stmt, parent)
                partial = isinstance(v.func.value, ast.Subscript) or v.func.attr in {
                    "scatter_", "index_put_", "masked_fill_", "copy_"}
                n.mutation = (recv, v.func.attr, partial)
                n.uses = _names_loaded(stmt)
                n.indexes = _index_reads(stmt)
                n.state = self._external(stmt)
                return
        n = self._new("Call", stmt, parent)
        n.uses = _names_loaded(stmt)
        n.indexes = _index_reads(stmt)
        n.state = self._external(stmt)

    # -- dependencies ---------------------------------------------------
    def link(self) -> None:
        # parameters are defined at entry by a synthetic Param node so that data
        # and alias dependencies on them are explicit (slicing needs the edge)
        entry = Node(id=0, kind="Param", line=0, text="params: " + ", ".join(self.params),
                     defs=list(self.params))
        for n in self.nodes:
            n.id += 1
            if n.parent is not None:
                n.parent += 1
        self.nodes.insert(0, entry)
        for d in self.deps:
            d.src += 1
            d.dst += 1
        last_def: Dict[str, int] = {p: 0 for p in self.params}
        group: Dict[str, str] = {}   # alias union-find: name -> representative

        def find(a: str) -> str:
            group.setdefault(a, a)
            while group[a] != a:
                group[a] = group[group[a]]
                a = group[a]
            return a

        for node in self.nodes[1:]:
            # control
            if node.parent is not None:
                self.deps.append(Dep(node.parent, node.id, "control"))
            # data: each used name -> last node that defined it
            for u in node.uses:
                if u in last_def and last_def[u] != node.id:
                    self.deps.append(Dep(last_def[u], node.id, "data", u))
            if node.mutation is not None:
                tgt = node.mutation[0]
                if tgt in last_def:
                    self.deps.append(Dep(last_def[tgt], node.id, "data", tgt))
                # a write through one name redefines every name sharing its storage
                rep = find(tgt)
                for nm in [k for k in group if find(k) == rep] or [tgt]:
                    last_def[nm] = node.id
                last_def[tgt] = node.id
            # alias
            if node.alias is not None:
                tgt, src, op = node.alias
                if src in last_def:
                    self.deps.append(Dep(last_def[src], node.id, "alias", f"{src}.{op}"))
                ra, rb = find(tgt), find(src)
                if ra != rb:
                    group[ra] = rb
            for d in node.defs:
                last_def[d] = node.id
            # state
            if node.state and node.kind in ("StateRead", "StateWrite"):
                self.deps.append(Dep(node.id, node.id, "state", ",".join(node.state)))


def build_ir_from_source(src: str, name: str = "<fn>") -> IR:
    try:
        tree = ast.parse(textwrap.dedent(src))
    except SyntaxError as e:
        return IR(function=name, params=[], error=f"SyntaxError: {e}")
    fn = next((n for n in ast.walk(tree) if isinstance(n, (ast.FunctionDef, ast.AsyncFunctionDef))), None)
    if fn is None:
        return IR(function=name, params=[], error="no function definition found")
    params = [a.arg for a in fn.args.posonlyargs + fn.args.args + fn.args.kwonlyargs]
    if fn.args.vararg is not None:
        params.append(fn.args.vararg.arg)
    b = _Builder(fn, params)
    b.build(fn.body)
    b.link()
    return IR(function=fn.name, params=params, nodes=b.nodes, deps=b.deps)


def build_ir(fn) -> IR:
    import inspect
    try:
        src = inspect.getsource(fn)
    except (OSError, TypeError) as e:
        return IR(function=getattr(fn, "__name__", "<fn>"), params=[], error=f"source unavailable: {e}")
    return build_ir_from_source(src, getattr(fn, "__name__", "<fn>"))


def format_ir(ir: IR) -> str:
    L = [f"  IR({ir.function}({', '.join(ir.params)})): {len(ir.nodes)} nodes, {len(ir.deps)} deps"]
    if ir.error:
        L.append(f"  ERROR: {ir.error}")
        return "\n".join(L)
    for n in ir.nodes:
        extra = ""
        if n.alias:
            extra = f"  alias {n.alias[0]} <- {n.alias[1]}.{n.alias[2]}"
        elif n.mutation:
            extra = f"  mutates {n.mutation[0]} via {n.mutation[1]}" + (" (partial)" if n.mutation[2] else "")
        if n.state:
            extra += f"  state={n.state}"
        L.append(f"    [{n.id:>2}] {n.kind:<10} L{n.line:<3} {n.text}{extra}")
    kinds = {}
    for d in ir.deps:
        kinds[d.kind] = kinds.get(d.kind, 0) + 1
    L.append(f"    deps: {kinds}")
    return "\n".join(L)
