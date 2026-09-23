"""Plan section 5.1: compilation-boundary identification.

Locates where Python code enters a compiler/JIT::

    torch.compile(f) / @torch.compile / torch.compile(model, backend=..., ...)
    torch.jit.script(...) / torch.jit.trace(...)
    @triton.jit / @triton.autotune(...)
    @tilelang.jit / tilelang.compile(...)

plus project wrappers (any function whose body calls one of those). For each
boundary a :class:`CompilationSite` records the target, the compiler and its
options, the Python functions reachable from the target inside the same
module, and the external state it touches. Only reachable functions are
handed to the later analyses - no whole-project analysis.
"""
from __future__ import annotations

import ast
import os
from dataclasses import dataclass, field
from typing import Any, Dict, List, Optional, Set, Tuple

#: (dotted callee, compiler family)
_COMPILERS: Dict[str, str] = {
    "torch.compile": "torch.compile",
    "torch._dynamo.optimize": "torch.compile",
    "torch.jit.script": "torch.jit.script",
    "torch.jit.trace": "torch.jit.trace",
    "triton.jit": "triton.jit",
    "triton.autotune": "triton.jit",
    "triton.heuristics": "triton.jit",
    "tilelang.jit": "tilelang.jit",
    "tilelang.compile": "tilelang.jit",
    "tl.jit": "tilelang.jit",
}


@dataclass
class CompilationSite:
    file: str
    line: int
    compiler: str                     # torch.compile | torch.jit.script | triton.jit | ...
    form: str                         # decorator | call | wrapper
    target: Optional[str]             # function / class / expression compiled
    arguments: List[str] = field(default_factory=list)
    options: Dict[str, str] = field(default_factory=dict)
    reachable: List[str] = field(default_factory=list)
    external_state: List[str] = field(default_factory=list)
    #: name of the wrapper function when the site lives inside one
    wrapper: Optional[str] = None
    target_source: Optional[str] = None

    def as_dict(self) -> Dict[str, Any]:
        return {
            "file": self.file, "line": self.line, "compiler": self.compiler,
            "form": self.form, "target": self.target, "arguments": self.arguments,
            "options": self.options, "reachable": self.reachable,
            "external_state": self.external_state, "wrapper": self.wrapper,
        }


# --------------------------------------------------------------------------
# helpers
# --------------------------------------------------------------------------

def _dotted(node: ast.AST) -> Optional[str]:
    if isinstance(node, ast.Name):
        return node.id
    if isinstance(node, ast.Attribute):
        base = _dotted(node.value)
        return f"{base}.{node.attr}" if base else None
    if isinstance(node, ast.Call):
        return _dotted(node.func)
    return None


def _resolve_alias(name: Optional[str], aliases: Dict[str, str]) -> Optional[str]:
    """Map ``import torch._dynamo as dyn`` / ``from torch import compile``."""
    if name is None:
        return None
    head, _, rest = name.partition(".")
    if head in aliases:
        full = aliases[head] + (f".{rest}" if rest else "")
        return full
    return name


def _compiler_of(name: Optional[str]) -> Optional[str]:
    if name is None:
        return None
    if name in _COMPILERS:
        return _COMPILERS[name]
    # tolerate deeper attribute chains such as torch.compiler.compile
    for k, v in _COMPILERS.items():
        if name.endswith(k):
            return v
    return None


def _unparse(node: ast.AST) -> str:
    try:
        return ast.unparse(node)
    except Exception:
        return "<expr>"


def _call_options(call: ast.Call) -> Dict[str, str]:
    return {kw.arg or "**": _unparse(kw.value) for kw in call.keywords}


# --------------------------------------------------------------------------
# module scan
# --------------------------------------------------------------------------

class _ModuleIndex:
    def __init__(self, tree: ast.Module, src: str):
        self.tree = tree
        self.src = src
        self.aliases: Dict[str, str] = {}
        self.functions: Dict[str, ast.AST] = {}
        self.calls: Dict[str, Set[str]] = {}
        self.globals_read: Dict[str, Set[str]] = {}
        self.module_names: Set[str] = set()
        self._index()

    def _index(self) -> None:
        for node in self.tree.body:
            if isinstance(node, ast.Import):
                for a in node.names:
                    self.aliases[a.asname or a.name.split(".")[0]] = a.name
            elif isinstance(node, ast.ImportFrom) and node.module:
                for a in node.names:
                    self.aliases[a.asname or a.name] = f"{node.module}.{a.name}"
            elif isinstance(node, (ast.FunctionDef, ast.AsyncFunctionDef, ast.ClassDef)):
                self.functions[node.name] = node
                self.module_names.add(node.name)
            elif isinstance(node, ast.Assign):
                for t in node.targets:
                    if isinstance(t, ast.Name):
                        self.module_names.add(t.id)
        for name, fn in list(self.functions.items()):
            if isinstance(fn, ast.ClassDef):
                for sub in fn.body:
                    if isinstance(sub, (ast.FunctionDef, ast.AsyncFunctionDef)):
                        self.functions[f"{name}.{sub.name}"] = sub
        for name, fn in list(self.functions.items()):
            self.calls[name] = self._callees(fn)
            self.globals_read[name] = self._external(fn)

    def _callees(self, fn: ast.AST) -> Set[str]:
        out: Set[str] = set()
        for n in ast.walk(fn):
            if isinstance(n, ast.Call):
                d = _dotted(n.func)
                if d is None:
                    continue
                if d in self.functions:
                    out.add(d)
                elif d.startswith("self.") and d[5:] in {k.split(".")[-1] for k in self.functions}:
                    for k in self.functions:
                        if k.endswith("." + d[5:]):
                            out.add(k)
        return out

    def _external(self, fn: ast.AST) -> Set[str]:
        """Module-level / closure names the body reads or writes (state deps)."""
        params: Set[str] = set()
        local: Set[str] = set()
        if isinstance(fn, (ast.FunctionDef, ast.AsyncFunctionDef)):
            params = {a.arg for a in fn.args.args + fn.args.kwonlyargs}
            if fn.args.vararg:
                params.add(fn.args.vararg.arg)
            if fn.args.kwarg:
                params.add(fn.args.kwarg.arg)
        for n in ast.walk(fn):
            if isinstance(n, ast.Name) and isinstance(n.ctx, ast.Store):
                local.add(n.id)
            elif isinstance(n, (ast.Global, ast.Nonlocal)):
                local -= set(n.names)
        out: Set[str] = set()
        for n in ast.walk(fn):
            if isinstance(n, ast.Name) and isinstance(n.ctx, ast.Load):
                if n.id in params or n.id in local:
                    continue
                if n.id in self.module_names and n.id not in self.aliases and n.id not in self.functions:
                    out.add(n.id)  # module-level data, not imports or callees
            elif isinstance(n, ast.Attribute) and isinstance(n.value, ast.Name) \
                    and n.value.id == "self" and isinstance(n.ctx, ast.Store):
                out.add(f"self.{n.attr}")
        return out

    def reachable(self, root: str) -> List[str]:
        seen: List[str] = []
        stack = [root]
        while stack:
            cur = stack.pop()
            if cur in seen or cur not in self.functions:
                continue
            seen.append(cur)
            stack.extend(sorted(self.calls.get(cur, ())))
        return seen

    def source_of(self, name: str) -> Optional[str]:
        fn = self.functions.get(name)
        if fn is None:
            return None
        try:
            return ast.get_source_segment(self.src, fn)
        except Exception:
            return None


def scan_source(src: str, filename: str = "<string>") -> List[CompilationSite]:
    try:
        tree = ast.parse(src)
    except SyntaxError:
        return []
    idx = _ModuleIndex(tree, src)
    sites: List[CompilationSite] = []

    def add(site: CompilationSite) -> None:
        if site.target and site.target in idx.functions:
            site.reachable = idx.reachable(site.target)
            state: Set[str] = set()
            for r in site.reachable:
                state |= idx.globals_read.get(r, set())
            site.external_state = sorted(state)
            site.target_source = idx.source_of(site.target)
        sites.append(site)

    # decorators
    for name, fn in idx.functions.items():
        for dec in getattr(fn, "decorator_list", []):
            d = _resolve_alias(_dotted(dec), idx.aliases)
            comp = _compiler_of(d)
            if comp is None:
                continue
            opts = _call_options(dec) if isinstance(dec, ast.Call) else {}
            args = [a.arg for a in fn.args.args] if hasattr(fn, "args") else []
            add(CompilationSite(filename, fn.lineno, comp, "decorator", name,
                                arguments=args, options=opts))

    # explicit calls, possibly inside wrappers (decorator calls were handled above)
    enclosing: Dict[int, str] = {}
    decorators = set()
    for name, fn in idx.functions.items():
        for dec in getattr(fn, "decorator_list", []):
            decorators.add(id(dec))
        for n in ast.walk(fn):
            enclosing[id(n)] = name
    for n in ast.walk(tree):
        if not isinstance(n, ast.Call) or id(n) in decorators or not n.args:
            continue
        d = _resolve_alias(_dotted(n.func), idx.aliases)
        comp = _compiler_of(d)
        if comp is None:
            continue
        target = _unparse(n.args[0]) if n.args else None
        wrapper = enclosing.get(id(n))
        form = "wrapper" if wrapper else "call"
        tgt_name = target if target in idx.functions else target
        add(CompilationSite(filename, n.lineno, comp, form, tgt_name,
                            arguments=[_unparse(a) for a in n.args[1:]],
                            options=_call_options(n), wrapper=wrapper))
    return sites


def scan_path(path: str, max_files: int = 2000) -> List[CompilationSite]:
    """Scan a file or a directory tree for compilation sites."""
    out: List[CompilationSite] = []
    files: List[str] = []
    if os.path.isfile(path):
        files = [path]
    else:
        for root, dirs, names in os.walk(path):
            dirs[:] = [d for d in dirs if not d.startswith(".") and d not in
                       ("__pycache__", "node_modules", "build", "dist", ".venv", "venv")]
            for nm in names:
                if nm.endswith(".py"):
                    files.append(os.path.join(root, nm))
            if len(files) >= max_files:
                break
    for f in files[:max_files]:
        try:
            with open(f, encoding="utf-8", errors="replace") as fh:
                src = fh.read()
        except OSError:
            continue
        if not any(k.split(".")[0] in src for k in ("torch", "triton", "tilelang", "tl")):
            continue
        out.extend(scan_source(src, f))
    return out


def format_sites(sites: List[CompilationSite]) -> str:
    if not sites:
        return "  (no compilation site found)"
    L: List[str] = []
    for s in sites:
        L.append(f"  {os.path.basename(s.file)}:{s.line}  {s.compiler:<18} "
                 f"{s.form:<9} target={s.target}")
        if s.options:
            L.append(f"      options  : {s.options}")
        if s.wrapper:
            L.append(f"      wrapper  : {s.wrapper}")
        if s.reachable:
            L.append(f"      reachable: {', '.join(s.reachable)}")
        if s.external_state:
            L.append(f"      state    : {', '.join(s.external_state)}")
    return "\n".join(L)
