"""Plan section 5.2: a lightweight IR over the Python front end.

Two representations, as the plan asks:

**AST level** - each statement becomes one or more IR nodes of nine kinds::

    Assign  Call  Branch  Loop  Index  Mutation  Return  Raise  StateRead  StateWrite

and four dependency kinds connect them::

    data     a node uses a name another node defined (def-use, in program order)
    control  a node sits inside a Branch / Loop
    alias    a node's target shares storage with another node's target
    state    a StateWrite precedes a StateRead of the same global / attribute

**Bytecode level** - what the AST cannot see: the callable *actually* invoked
after decorators are applied (``torch.compile`` returns a wrapper around the
original; ``functools.wraps`` hides another), free variables closed over, and
dynamic dispatch (``getattr``, table lookups) whose targets are only known at
run time. :func:`bytecode_info` reads these off the live function object.

The IR is deliberately not a CFG with basic blocks: Phase 1 needs to know
*which statements depend on which* to derive obligations and to slice a
failing program down to its cause (17.2), and a dependency graph over
statements is the smallest structure that answers both.
"""
from __future__ import annotations

import ast
import builtins
import dis
import inspect
import textwrap
from dataclasses import dataclass, field
from typing import Any, Callable, Dict, List, Optional, Set, Tuple

from .analysis import _Walker, _base_name, _is_inplace_method

KINDS = ("Assign", "Call", "Branch", "Loop", "Index", "Mutation", "Return",
         "Raise", "StateRead", "StateWrite")
DEP_KINDS = ("data", "control", "alias", "state")

_BUILTINS = set(dir(builtins))
#: global names that are modules, not state, when they appear in a function
_MODULE_ROOTS = {"torch", "triton", "tl", "tilelang", "np", "numpy", "math",
                 "F", "nn", "os", "sys", "functools", "itertools", "einops"}


@dataclass
class IRNode:
    id: int
    kind: str
    line: int
    text: str
    defs: List[str] = field(default_factory=list)
    uses: List[str] = field(default_factory=list)
    #: kind-specific: callee for Call, method for Mutation, name for State*
    detail: str = ""

    def as_dict(self) -> Dict[str, Any]:
        return {"id": self.id, "kind": self.kind, "line": self.line,
                "text": self.text, "defs": self.defs, "uses": self.uses,
                "detail": self.detail}


@dataclass
class Dep:
    src: int      # the node depended upon
    dst: int      # the node that depends
    kind: str

    def as_dict(self) -> Dict[str, Any]:
        return {"src": self.src, "dst": self.dst, "kind": self.kind}


@dataclass
class IR:
    function: str
    params: List[str]
    nodes: List[IRNode] = field(default_factory=list)
    deps: List[Dep] = field(default_factory=list)
    error: Optional[str] = None

    def counts(self) -> Dict[str, int]:
        c = {k: 0 for k in KINDS}
        for n in self.nodes:
            c[n.kind] = c.get(n.kind, 0) + 1
        d = {k: 0 for k in DEP_KINDS}
        for e in self.deps:
            d[e.kind] = d.get(e.kind, 0) + 1
        return {"nodes": len(self.nodes), **{f"n_{k}": v for k, v in c.items()},
                "deps": len(self.deps), **{f"d_{k}": v for k, v in d.items()}}

    def backward_slice(self, nid: int, kinds: Tuple[str, ...] = DEP_KINDS) -> List[int]:
        """Every node ``nid`` transitively depends on (17.2's slice)."""
        seen: Set[int] = set()
        todo = [nid]
        while todo:
            cur = todo.pop()
            for e in self.deps:
                if e.dst == cur and e.kind in kinds and e.src not in seen:
                    seen.add(e.src)
                    todo.append(e.src)
        return sorted(seen)

    def forward_slice(self, nid: int, kinds: Tuple[str, ...] = DEP_KINDS) -> List[int]:
        """Every node that transitively depends on ``nid``."""
        seen: Set[int] = set()
        todo = [nid]
        while todo:
            cur = todo.pop()
            for e in self.deps:
                if e.src == cur and e.kind in kinds and e.dst not in seen:
                    seen.add(e.dst)
                    todo.append(e.dst)
        return sorted(seen)

    def as_dict(self) -> Dict[str, Any]:
        return {"function": self.function, "params": self.params,
                "nodes": [n.as_dict() for n in self.nodes],
                "deps": [d.as_dict() for d in self.deps],
                "counts": self.counts(), "error": self.error}


# --------------------------------------------------------------------------
# helpers
# --------------------------------------------------------------------------

def _names_loaded(node: ast.AST) -> List[str]:
    out: List[str] = []
    for n in ast.walk(node):
        if isinstance(n, ast.Name) and isinstance(n.ctx, ast.Load) and n.id not in out:
            out.append(n.id)
    return out


def _names_stored(node: ast.AST) -> List[str]:
    out: List[str] = []
    for n in ast.walk(node):
        if isinstance(n, ast.Name) and isinstance(n.ctx, ast.Store) and n.id not in out:
            out.append(n.id)
    return out


def _unparse(node: ast.AST) -> str:
    try:
        return ast.unparse(node)
    except Exception:  # pragma: no cover
        return "<expr>"


def _callee(node: ast.Call) -> str:
    return _unparse(node.func)


# --------------------------------------------------------------------------
# builder
# --------------------------------------------------------------------------

class _Builder:
    def __init__(self, fn: ast.AST, params: List[str]) -> None:
        self.ir = IR(function=getattr(fn, "name", "<fn>"), params=list(params))
        self.params = set(params)
        # every name bound anywhere in the function: reads of anything else
        # are reads of external state
        self.local: Set[str] = set(params)
        for n in ast.walk(fn):
            if isinstance(n, ast.Name) and isinstance(n.ctx, ast.Store):
                self.local.add(n.id)
            elif isinstance(n, (ast.Import, ast.ImportFrom)):
                self.local.update((a.asname or a.name.split(".")[0]) for a in n.names)
        self.declared_global: Set[str] = set()
        for n in ast.walk(fn):
            if isinstance(n, (ast.Global, ast.Nonlocal)):
                self.declared_global.update(n.names)
        self.local -= self.declared_global

        self.last_def: Dict[str, int] = {}
        self.last_state_write: Dict[str, int] = {}
        self.ctrl: List[int] = []
        self.walker = _Walker()          # reused for its view-edge rule
        # parameters are defined "before" the body, by a virtual node -1
        for p in params:
            self.last_def[p] = -1

    # -- node creation -------------------------------------------------
    def _new(self, kind: str, line: int, text: str, defs: List[str],
             uses: List[str], detail: str = "") -> IRNode:
        node = IRNode(len(self.ir.nodes), kind, line, text, list(defs), list(uses), detail)
        self.ir.nodes.append(node)
        if self.ctrl:
            self.ir.deps.append(Dep(self.ctrl[-1], node.id, "control"))
        for u in uses:
            d = self.last_def.get(u)
            if d is not None and d >= 0:
                self.ir.deps.append(Dep(d, node.id, "data"))
        return node

    def _state_reads(self, expr: ast.AST, line: int, consumer_uses: List[str]) -> List[int]:
        """StateRead nodes for external names this expression reads."""
        ids: List[int] = []
        seen: Set[str] = set()
        for n in ast.walk(expr):
            key: Optional[str] = None
            if isinstance(n, ast.Name) and isinstance(n.ctx, ast.Load):
                if n.id in self.local or n.id in _BUILTINS or n.id in _MODULE_ROOTS:
                    continue
                key = n.id
            elif isinstance(n, ast.Attribute) and isinstance(n.ctx, ast.Load) \
                    and isinstance(n.value, ast.Name):
                base = n.value.id
                if base == "self" or (base not in self.local and base not in _BUILTINS
                                      and base not in _MODULE_ROOTS):
                    key = f"{base}.{n.attr}"
            if key is None or key in seen:
                continue
            seen.add(key)
            node = self._new("StateRead", line, key, [], [], detail=key)
            w = self.last_state_write.get(key)
            if w is not None:
                self.ir.deps.append(Dep(w, node.id, "state"))
            ids.append(node.id)
        return ids

    def _expr_nodes(self, expr: ast.AST, line: int) -> List[int]:
        """Call and Index nodes for the sub-expressions, innermost first."""
        ids: List[int] = []
        for n in ast.walk(expr):
            pass
        # ast.walk is breadth-first; we want inner calls before outer ones so
        # data flows in evaluation order. Collect then reverse.
        found: List[ast.AST] = [n for n in ast.walk(expr)
                                if isinstance(n, (ast.Call, ast.Subscript))]
        for n in reversed(found):
            if isinstance(n, ast.Call):
                uses = _names_loaded(n)
                node = self._new("Call", line, _unparse(n), [], uses, detail=_callee(n))
                ids.append(node.id)
            elif isinstance(n, ast.Subscript) and isinstance(n.ctx, ast.Load):
                base = _base_name(n.value)
                uses = _names_loaded(n)
                node = self._new("Index", line, _unparse(n), [], uses, detail=base or "")
                ids.append(node.id)
        return ids

    def _link(self, producers: List[int], consumer: int, kind: str = "data") -> None:
        for p in producers:
            self.ir.deps.append(Dep(p, consumer, kind))

    # -- statements ----------------------------------------------------
    def body(self, stmts: List[ast.stmt]) -> None:
        for s in stmts:
            self.stmt(s)

    def stmt(self, s: ast.stmt) -> None:
        line = getattr(s, "lineno", 0)
        if isinstance(s, ast.If):
            pre = self._state_reads(s.test, line, []) + self._expr_nodes(s.test, line)
            node = self._new("Branch", line, f"if {_unparse(s.test)}", [], _names_loaded(s.test))
            self._link(pre, node.id)
            self.ctrl.append(node.id)
            self.body(s.body)
            self.body(s.orelse)
            self.ctrl.pop()
        elif isinstance(s, ast.While):
            pre = self._state_reads(s.test, line, []) + self._expr_nodes(s.test, line)
            node = self._new("Loop", line, f"while {_unparse(s.test)}", [], _names_loaded(s.test))
            self._link(pre, node.id)
            self.ctrl.append(node.id)
            self.body(s.body)
            self.body(s.orelse)
            self.ctrl.pop()
        elif isinstance(s, (ast.For, ast.AsyncFor)):
            pre = self._state_reads(s.iter, line, []) + self._expr_nodes(s.iter, line)
            defs = _names_stored(s.target)
            node = self._new("Loop", line, f"for {_unparse(s.target)} in {_unparse(s.iter)}",
                             defs, _names_loaded(s.iter))
            self._link(pre, node.id)
            for d in defs:
                self.last_def[d] = node.id
            self.ctrl.append(node.id)
            self.body(s.body)
            self.body(s.orelse)
            self.ctrl.pop()
        elif isinstance(s, (ast.Assign, ast.AnnAssign)):
            value = s.value
            targets = s.targets if isinstance(s, ast.Assign) else [s.target]
            if value is None:
                return
            pre = self._state_reads(value, line, []) + self._expr_nodes(value, line)
            for t in targets:
                self._assign(t, value, line, pre, op=None)
        elif isinstance(s, ast.AugAssign):
            pre = self._state_reads(s.value, line, []) + self._expr_nodes(s.value, line)
            self._assign(s.target, s.value, line, pre, op=type(s.op).__name__)
        elif isinstance(s, ast.Expr):
            pre = self._state_reads(s.value, line, []) + self._expr_nodes(s.value, line)
            v = s.value
            if isinstance(v, ast.Call) and isinstance(v.func, ast.Attribute) \
                    and _is_inplace_method(v.func.attr):
                recv = _base_name(v.func.value)
                if recv:
                    node = self._new("Mutation", line, _unparse(v), [recv],
                                     _names_loaded(v), detail=v.func.attr)
                    self._link(pre, node.id)
                    self.last_def[recv] = node.id
                    if recv not in self.local:
                        self._state_write(recv, line, node.id)
        elif isinstance(s, ast.Return):
            if s.value is None:
                self._new("Return", line, "return", [], [])
                return
            pre = self._state_reads(s.value, line, []) + self._expr_nodes(s.value, line)
            node = self._new("Return", line, f"return {_unparse(s.value)}", [],
                             _names_loaded(s.value))
            self._link(pre, node.id)
        elif isinstance(s, ast.Raise):
            uses = _names_loaded(s.exc) if s.exc else []
            pre = (self._state_reads(s.exc, line, []) + self._expr_nodes(s.exc, line)) if s.exc else []
            node = self._new("Raise", line, _unparse(s), [], uses,
                             detail=_unparse(s.exc) if s.exc else "")
            self._link(pre, node.id)
        elif isinstance(s, ast.Assert):
            pre = self._state_reads(s.test, line, []) + self._expr_nodes(s.test, line)
            node = self._new("Branch", line, f"assert {_unparse(s.test)}", [],
                             _names_loaded(s.test), detail="assert")
            self._link(pre, node.id)
        elif isinstance(s, (ast.With, ast.AsyncWith)):
            for item in s.items:
                pre = self._expr_nodes(item.context_expr, line)
                defs = _names_stored(item.optional_vars) if item.optional_vars else []
                node = self._new("Assign", line, _unparse(item.context_expr), defs,
                                 _names_loaded(item.context_expr), detail="with")
                self._link(pre, node.id)
                for d in defs:
                    self.last_def[d] = node.id
            self.body(s.body)
        elif isinstance(s, ast.Try):
            self.body(s.body)
            for h in s.handlers:
                node = self._new("Branch", getattr(h, "lineno", line),
                                 f"except {_unparse(h.type) if h.type else ''}",
                                 [h.name] if h.name else [], [], detail="except")
                if h.name:
                    self.last_def[h.name] = node.id
                self.ctrl.append(node.id)
                self.body(h.body)
                self.ctrl.pop()
            self.body(s.orelse)
            self.body(s.finalbody)
        elif isinstance(s, ast.Delete):
            for t in s.targets:
                base = _base_name(t)
                if base:
                    node = self._new("Mutation", line, _unparse(s), [base], [base], detail="del")
                    self.last_def[base] = node.id
        elif isinstance(s, (ast.FunctionDef, ast.AsyncFunctionDef, ast.ClassDef)):
            node = self._new("Assign", line, f"def {s.name}", [s.name], [], detail="nested_def")
            self.last_def[s.name] = node.id
        # Pass, Global, Nonlocal, Import: no node

    def _assign(self, target: ast.AST, value: ast.AST, line: int,
                pre: List[int], op: Optional[str]) -> None:
        uses = _names_loaded(value)
        if isinstance(target, ast.Name):
            if op is not None:
                # x += v rebinds for immutables and mutates for tensors: the
                # tensor reading is the one that matters to a compiler
                node = self._new("Mutation", line, f"{target.id} {op}= {_unparse(value)}",
                                 [target.id], [target.id] + uses, detail=f"aug_{op}")
            else:
                node = self._new("Assign", line, f"{target.id} = {_unparse(value)}",
                                 [target.id], uses)
                edge = self.walker._view_edge(target.id, value, line)
                if edge is not None:
                    src_node = self.last_def.get(edge.source)
                    if src_node is not None and src_node >= 0:
                        self.ir.deps.append(Dep(src_node, node.id, "alias"))
                    node.detail = f"alias_of:{edge.source}:{edge.op}"
            self._link(pre, node.id)
            self.last_def[target.id] = node.id
            if target.id in self.declared_global:
                self._state_write(target.id, line, node.id)
            return
        if isinstance(target, (ast.Tuple, ast.List)):
            defs = _names_stored(target)
            node = self._new("Assign", line, f"{_unparse(target)} = {_unparse(value)}", defs, uses)
            self._link(pre, node.id)
            for d in defs:
                self.last_def[d] = node.id
            return
        # x[i] = v / obj.attr = v: a write through the base
        base = _base_name(target)
        text = f"{_unparse(target)} {op + '=' if op else '='} {_unparse(value)}"
        node = self._new("Mutation", line, text, [base] if base else [],
                         ([base] if base else []) + uses + _names_loaded(target),
                         detail="subscript_store" if isinstance(target, ast.Subscript)
                         else "attribute_store")
        self._link(pre, node.id)
        if base:
            self.last_def[base] = node.id
            if isinstance(target, ast.Attribute) and (base == "self" or base not in self.local):
                self._state_write(f"{base}.{target.attr}", line, node.id)
            elif base not in self.local:
                self._state_write(base, line, node.id)

    def _state_write(self, key: str, line: int, producer: int) -> None:
        node = self._new("StateWrite", line, key, [], [], detail=key)
        self.ir.deps.append(Dep(producer, node.id, "data"))
        self.last_state_write[key] = node.id


# --------------------------------------------------------------------------
# entry points
# --------------------------------------------------------------------------

def build_ir(src: str, name: str = "<fn>") -> IR:
    try:
        tree = ast.parse(textwrap.dedent(src))
    except SyntaxError as e:
        return IR(function=name, params=[], error=f"SyntaxError: {e}")
    fn = next((n for n in ast.walk(tree)
               if isinstance(n, (ast.FunctionDef, ast.AsyncFunctionDef))), None)
    if fn is None:
        return IR(function=name, params=[], error="no function definition found")
    params = [a.arg for a in fn.args.args] + [a.arg for a in fn.args.kwonlyargs]
    b = _Builder(fn, params)
    b.body(fn.body)
    return b.ir


def ir_of(fn: Callable) -> IR:
    try:
        src = inspect.getsource(fn)
    except (OSError, TypeError) as e:
        return IR(function=getattr(fn, "__name__", "<fn>"), params=[],
                  error=f"source unavailable: {e}")
    return build_ir(src, getattr(fn, "__name__", "<fn>"))


def format_ir(ir: IR) -> str:
    L: List[str] = [f"  IR({ir.function}({', '.join(ir.params)}))"]
    if ir.error:
        L.append(f"  ERROR: {ir.error}")
        return "\n".join(L)
    by_dst: Dict[int, List[Tuple[int, str]]] = {}
    for d in ir.deps:
        by_dst.setdefault(d.dst, []).append((d.src, d.kind))
    for n in ir.nodes:
        deps = by_dst.get(n.id, [])
        dep_txt = ""
        if deps:
            parts = [f"{k[0]}:{','.join(str(s) for s, kk in deps if kk == k)}"
                     for k in DEP_KINDS if any(kk == k for _, kk in deps)]
            dep_txt = "   <- " + " ".join(parts)
        L.append(f"    n{n.id:<3} L{n.line:<3} {n.kind:<10} {n.text[:52]:<52}{dep_txt}")
    c = ir.counts()
    L.append(f"  {c['nodes']} nodes, {c['deps']} deps "
             f"(data {c['d_data']}, control {c['d_control']}, "
             f"alias {c['d_alias']}, state {c['d_state']})")
    return "\n".join(L)


# --------------------------------------------------------------------------
# bytecode layer
# --------------------------------------------------------------------------

@dataclass
class BytecodeInfo:
    """What the live function object says that the AST cannot."""

    #: wrapper layers unwrapped to reach the real code object, outermost first
    wrappers: List[str] = field(default_factory=list)
    #: the function whose bytecode was read
    resolved: str = ""
    globals_loaded: List[str] = field(default_factory=list)
    attrs_loaded: List[str] = field(default_factory=list)
    n_calls: int = 0
    #: names closed over - state the AST of the function alone never shows
    freevars: List[str] = field(default_factory=list)
    #: evidence of run-time dispatch the AST cannot resolve
    dynamic_dispatch: List[str] = field(default_factory=list)
    error: Optional[str] = None

    def as_dict(self) -> Dict[str, Any]:
        return {"wrappers": self.wrappers, "resolved": self.resolved,
                "globals_loaded": self.globals_loaded,
                "attrs_loaded": self.attrs_loaded, "n_calls": self.n_calls,
                "freevars": self.freevars, "dynamic_dispatch": self.dynamic_dispatch,
                "error": self.error}


def unwrap(fn: Any, limit: int = 8) -> Tuple[Any, List[str]]:
    """Peel ``torch.compile`` / ``functools.wraps`` / method layers.

    The AST of a decorated function describes the *original*; the object the
    program calls is the wrapper. Both matter: the original's body is what
    Phase 1 reads, the wrapper is what Phase 2 executes.
    """
    layers: List[str] = []
    cur = fn
    for _ in range(limit):
        nxt = None
        for attr in ("_torchdynamo_orig_callable", "_orig_mod", "__wrapped__"):
            inner = getattr(cur, attr, None)
            if inner is not None and inner is not cur:
                layers.append(f"{type(cur).__name__}.{attr}")
                nxt = inner
                break
        if nxt is None and inspect.ismethod(cur):
            layers.append("bound_method")
            nxt = cur.__func__
        if nxt is None:
            break
        cur = nxt
    return cur, layers


def bytecode_info(fn: Callable) -> BytecodeInfo:
    info = BytecodeInfo()
    try:
        target, info.wrappers = unwrap(fn)
        code = getattr(target, "__code__", None)
        if code is None and hasattr(target, "forward"):
            target = target.forward
            info.wrappers.append("nn.Module.forward")
            code = getattr(getattr(target, "__func__", target), "__code__", None)
        if code is None:
            info.error = f"no code object on {type(target).__name__}"
            return info
        info.resolved = getattr(target, "__qualname__", getattr(target, "__name__", "?"))
        info.freevars = list(code.co_freevars)
        prev: Optional[str] = None
        for ins in dis.get_instructions(code):
            op = ins.opname
            if op == "LOAD_GLOBAL":
                name = str(ins.argval)
                if name not in info.globals_loaded:
                    info.globals_loaded.append(name)
                if name in ("getattr", "setattr", "globals", "vars", "eval", "exec"):
                    info.dynamic_dispatch.append(f"{name}() at offset {ins.offset}")
            elif op in ("LOAD_ATTR", "LOAD_METHOD"):
                name = str(ins.argval)
                if name not in info.attrs_loaded:
                    info.attrs_loaded.append(name)
                if name in ("__getattribute__", "__getattr__", "__call__"):
                    info.dynamic_dispatch.append(f"{name} at offset {ins.offset}")
            elif op.startswith("CALL"):
                info.n_calls += 1
                # a call whose callee came from a subscript is a table dispatch
                if prev in ("BINARY_SUBSCR", "BINARY_OP"):
                    info.dynamic_dispatch.append(f"callee from subscript at offset {ins.offset}")
            prev = op
    except Exception as e:  # noqa: BLE001
        info.error = f"{type(e).__name__}: {str(e)[:120]}"
    return info


def format_bytecode(info: BytecodeInfo) -> str:
    L: List[str] = ["  bytecode:"]
    if info.error:
        L.append(f"    ERROR: {info.error}")
        return "\n".join(L)
    if info.wrappers:
        L.append(f"    unwrapped : {' -> '.join(info.wrappers)} -> {info.resolved}")
    else:
        L.append(f"    resolved  : {info.resolved} (no wrapper)")
    L.append(f"    globals   : {', '.join(info.globals_loaded) or '-'}")
    L.append(f"    attrs     : {', '.join(info.attrs_loaded[:16]) or '-'}"
             + (" ..." if len(info.attrs_loaded) > 16 else ""))
    L.append(f"    calls     : {info.n_calls}")
    if info.freevars:
        L.append(f"    closure   : {', '.join(info.freevars)}")
    if info.dynamic_dispatch:
        L.append(f"    dynamic   : {'; '.join(info.dynamic_dispatch)}")
    return "\n".join(L)
