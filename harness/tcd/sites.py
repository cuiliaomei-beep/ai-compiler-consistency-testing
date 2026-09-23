"""Plan section 5.1: compilation-boundary identification.

Everything downstream of here analyses *a function*. This module answers
where those functions come from in a real project: every point at which
Python crosses into a compiler or JIT, what gets compiled, with which options,
what the compiled code can reach, and what state outside the function it
touches. Phase 1 is then run only on functions reachable from a site - the
plan's demand-driven traversal - instead of on the whole project.

Boundaries recognised::

    torch.compile(f, ...)        @torch.compile    @torch.compile(...)
    torch._dynamo.optimize(...)  (the pre-2.0 spelling of the same thing)
    torch.jit.script(f)          @torch.jit.script
    torch.jit.trace(f, example)
    @triton.jit                  @triton.autotune(...) / @triton.heuristics(...)
    @tilelang.jit

plus project wrappers: a function whose body applies one of the above to its
own parameter is itself a boundary, and every use of that wrapper is a site.
Real projects almost never call ``torch.compile`` directly at each model; they
route it through a ``maybe_compile`` helper, and a scanner that only knows
the raw API sees none of them.

Purely syntactic. It reads the file, never imports it - project code is not
executed by looking for its compilation sites.
"""
from __future__ import annotations

import ast
import builtins
import os
from dataclasses import dataclass, field
from typing import Dict, Iterator, List, Optional, Set, Tuple

#: attribute paths that name a boundary, and the canonical API each is
_BOUNDARY_APIS: Dict[str, str] = {
    "torch.compile": "torch.compile",
    "torch._dynamo.optimize": "torch.compile",
    "torch.jit.script": "torch.jit.script",
    "torch.jit.trace": "torch.jit.trace",
    "triton.jit": "triton.jit",
    "triton.autotune": "triton.jit",     # only ever stacked on a @triton.jit kernel
    "triton.heuristics": "triton.jit",
    "tilelang.jit": "tilelang.jit",
}

_SKIP_DIRS = {".git", "__pycache__", "node_modules", ".venv", "venv", "build",
              "dist", ".tox", ".mypy_cache", ".eggs", "site-packages"}

#: names that are almost always modules, not mutable state, when read globally
_MODULE_ROOTS = {"torch", "triton", "tl", "tilelang", "np", "numpy", "math",
                 "F", "nn", "os", "sys", "functools", "itertools", "typing",
                 "logging", "warnings", "einops", "jax", "tvm"}

_BUILTINS = set(dir(builtins))


@dataclass
class CompilationSite:
    """One crossing from Python into a compiler. Plan section 5.1."""

    file: str
    line: int
    #: decorator | call | wrapper_decorator | wrapper_call
    form: str
    #: canonical API: torch.compile | torch.jit.script | torch.jit.trace |
    #: triton.jit | tilelang.jit
    api: str
    #: the compiled function / class, when the source names it
    target: Optional[str] = None
    #: positional argument expressions (for the call form: what is compiled,
    #: and for ``jit.trace`` the example inputs)
    arguments: List[str] = field(default_factory=list)
    #: ``backend=`` for torch.compile, as written
    backend: Optional[str] = None
    #: remaining keyword options as source text
    options: Dict[str, str] = field(default_factory=dict)
    #: functions in the same file reachable from the target
    reachable: List[str] = field(default_factory=list)
    #: names read / written outside the target's own scope
    external_reads: List[str] = field(default_factory=list)
    external_writes: List[str] = field(default_factory=list)
    #: the project wrapper this site went through, if any
    via_wrapper: Optional[str] = None

    def as_dict(self) -> Dict[str, object]:
        return {
            "file": self.file, "line": self.line, "form": self.form,
            "api": self.api, "target": self.target, "arguments": self.arguments,
            "backend": self.backend, "options": self.options,
            "reachable": self.reachable,
            "external_reads": self.external_reads,
            "external_writes": self.external_writes,
            "via_wrapper": self.via_wrapper,
        }


# --------------------------------------------------------------------------
# name resolution
# --------------------------------------------------------------------------

def _import_map(tree: ast.Module) -> Dict[str, str]:
    """Local name -> dotted origin, for every import in the module."""
    m: Dict[str, str] = {}
    for node in ast.walk(tree):
        if isinstance(node, ast.Import):
            for a in node.names:
                m[a.asname or a.name.split(".")[0]] = a.name if a.asname else a.name.split(".")[0]
        elif isinstance(node, ast.ImportFrom) and node.module:
            for a in node.names:
                m[a.asname or a.name] = f"{node.module}.{a.name}"
    return m


def _dotted(node: ast.AST, imports: Dict[str, str]) -> Optional[str]:
    """``torch.jit.script`` / ``tc`` / ``jit.script`` -> canonical dotted path."""
    parts: List[str] = []
    while isinstance(node, ast.Attribute):
        parts.append(node.attr)
        node = node.value
    if not isinstance(node, ast.Name):
        return None
    root = imports.get(node.id, node.id)
    return ".".join([root] + list(reversed(parts)))


def _api_of(node: ast.AST, imports: Dict[str, str]) -> Optional[str]:
    d = _dotted(node, imports)
    return _BOUNDARY_APIS.get(d) if d else None


def _unparse(node: ast.AST) -> str:
    try:
        return ast.unparse(node)
    except Exception:  # pragma: no cover
        return "<expr>"


# --------------------------------------------------------------------------
# per-file scan
# --------------------------------------------------------------------------

@dataclass
class _Module:
    path: str
    tree: ast.Module
    imports: Dict[str, str]
    #: "f" or "Class.method" -> definition
    functions: Dict[str, ast.AST]
    #: module-level assigned names (candidates for external state)
    module_names: Set[str]
    #: wrapper name -> api it applies
    wrappers: Dict[str, str]


def _collect_functions(tree: ast.Module) -> Dict[str, ast.AST]:
    out: Dict[str, ast.AST] = {}
    for node in tree.body:
        if isinstance(node, (ast.FunctionDef, ast.AsyncFunctionDef)):
            out[node.name] = node
        elif isinstance(node, ast.ClassDef):
            out[node.name] = node
            for sub in node.body:
                if isinstance(sub, (ast.FunctionDef, ast.AsyncFunctionDef)):
                    out[f"{node.name}.{sub.name}"] = sub
    return out


def _module_names(tree: ast.Module) -> Set[str]:
    names: Set[str] = set()
    for node in tree.body:
        if isinstance(node, (ast.Assign, ast.AnnAssign, ast.AugAssign)):
            targets = node.targets if isinstance(node, ast.Assign) else [node.target]
            for t in targets:
                if isinstance(t, ast.Name):
                    names.add(t.id)
                elif isinstance(t, ast.Tuple):
                    names.update(e.id for e in t.elts if isinstance(e, ast.Name))
    return names


def _find_wrappers(functions: Dict[str, ast.AST], imports: Dict[str, str]) -> Dict[str, str]:
    """Functions that apply a boundary API to one of their own parameters."""
    out: Dict[str, str] = {}
    for name, fn in functions.items():
        if not isinstance(fn, (ast.FunctionDef, ast.AsyncFunctionDef)):
            continue
        params = {a.arg for a in fn.args.args + fn.args.kwonlyargs}
        for node in ast.walk(fn):
            if isinstance(node, ast.Call):
                api = _api_of(node.func, imports)
                if api and node.args and isinstance(node.args[0], ast.Name) \
                        and node.args[0].id in params:
                    out[name] = api
                    break
    return out


def _load(path: str) -> Optional[_Module]:
    try:
        with open(path, "r", encoding="utf-8", errors="replace") as fh:
            src = fh.read()
        tree = ast.parse(src)
    except (OSError, SyntaxError, ValueError):
        return None
    imports = _import_map(tree)
    functions = _collect_functions(tree)
    return _Module(path=path, tree=tree, imports=imports, functions=functions,
                   module_names=_module_names(tree),
                   wrappers=_find_wrappers(functions, imports))


def _split_options(call: Optional[ast.Call]) -> Tuple[Optional[str], Dict[str, str]]:
    backend = None
    options: Dict[str, str] = {}
    if call is None:
        return backend, options
    for kw in call.keywords:
        if kw.arg is None:
            options["**"] = _unparse(kw.value)
        elif kw.arg == "backend":
            backend = _unparse(kw.value)
        else:
            options[kw.arg] = _unparse(kw.value)
    return backend, options


def _resolve_boundary(func: ast.AST, mod: _Module) -> Tuple[Optional[str], Optional[str]]:
    """(api, wrapper_name) for a decorator / call target, or (None, None)."""
    api = _api_of(func, mod.imports)
    if api:
        return api, None
    if isinstance(func, ast.Name) and func.id in mod.wrappers:
        return mod.wrappers[func.id], func.id
    return None, None


def _sites_in(mod: _Module) -> Iterator[CompilationSite]:
    # decorators
    for qname, fn in mod.functions.items():
        for d in getattr(fn, "decorator_list", []):
            call = d if isinstance(d, ast.Call) else None
            func = d.func if isinstance(d, ast.Call) else d
            api, wrapper = _resolve_boundary(func, mod)
            if not api:
                continue
            backend, options = _split_options(call)
            yield CompilationSite(
                file=mod.path, line=getattr(d, "lineno", fn.lineno),
                form="wrapper_decorator" if wrapper else "decorator",
                api=api, target=qname, backend=backend, options=options,
                via_wrapper=wrapper)

    # calls - anywhere, except the defining call inside a wrapper's own body
    wrapper_defs = {mod.functions[w] for w in mod.wrappers if w in mod.functions}
    for node in ast.walk(mod.tree):
        if not isinstance(node, ast.Call):
            continue
        api, wrapper = _resolve_boundary(node.func, mod)
        if not api:
            continue
        if any(_contains(w, node) for w in wrapper_defs) and node.args \
                and isinstance(node.args[0], ast.Name):
            continue  # this is the wrapper's implementation, not a use
        backend, options = _split_options(node)
        args = [_unparse(a) for a in node.args]
        target = args[0] if args else None
        if target is not None and target not in mod.functions:
            # `torch.compile(model)` where model is an instance: keep the
            # expression as the target; reachability then has nothing to walk
            pass
        yield CompilationSite(
            file=mod.path, line=node.lineno,
            form="wrapper_call" if wrapper else "call",
            api=api, target=target, arguments=args[1:] if api == "torch.jit.trace" else args,
            backend=backend, options=options, via_wrapper=wrapper)


def _contains(outer: ast.AST, inner: ast.AST) -> bool:
    return any(n is inner for n in ast.walk(outer))


# --------------------------------------------------------------------------
# reachability and external state
# --------------------------------------------------------------------------

def _calls_in(fn: ast.AST, class_name: Optional[str]) -> Set[str]:
    out: Set[str] = set()
    for node in ast.walk(fn):
        if not isinstance(node, ast.Call):
            continue
        f = node.func
        if isinstance(f, ast.Name):
            out.add(f.id)
        elif isinstance(f, ast.Attribute):
            if isinstance(f.value, ast.Name):
                if f.value.id == "self" and class_name:
                    out.add(f"{class_name}.{f.attr}")
                else:
                    out.add(f"{f.value.id}.{f.attr}")
    return out


def _reachable(mod: _Module, target: str) -> List[str]:
    """Functions in this file reachable from ``target`` through calls."""
    seen: List[str] = []
    todo = [target]
    while todo:
        cur = todo.pop()
        fn = mod.functions.get(cur)
        if fn is None:
            continue
        cls = cur.split(".")[0] if "." in cur else None
        if isinstance(fn, ast.ClassDef):
            # compiling a module class means its forward and what forward calls
            for cand in (f"{cur}.forward", f"{cur}.__call__"):
                if cand in mod.functions and cand not in seen and cand not in todo:
                    todo.append(cand)
            continue
        for callee in _calls_in(fn, cls):
            if callee in mod.functions and callee not in seen and callee != target:
                seen.append(callee)
                todo.append(callee)
    return sorted(seen)


def _local_names(fn: ast.AST) -> Set[str]:
    names: Set[str] = set()
    if isinstance(fn, (ast.FunctionDef, ast.AsyncFunctionDef)):
        a = fn.args
        names.update(x.arg for x in a.args + a.kwonlyargs + a.posonlyargs)
        if a.vararg:
            names.add(a.vararg.arg)
        if a.kwarg:
            names.add(a.kwarg.arg)
    for node in ast.walk(fn):
        if isinstance(node, ast.Name) and isinstance(node.ctx, (ast.Store, ast.Del)):
            names.add(node.id)
        elif isinstance(node, (ast.Import, ast.ImportFrom)):
            names.update((x.asname or x.name.split(".")[0]) for x in node.names)
        elif isinstance(node, ast.ExceptHandler) and node.name:
            names.add(node.name)
        elif isinstance(node, (ast.FunctionDef, ast.AsyncFunctionDef, ast.ClassDef)) \
                and node is not fn:
            names.add(node.name)
    return names


def _external_state(mod: _Module, fnames: List[str]) -> Tuple[List[str], List[str]]:
    """Global / closure / attribute state read and written by these functions.

    Reads exclude names that are only used as the root of a call
    (``torch.relu(x)`` reads the module ``torch``, which is not state) and
    names defined in this file as functions or classes. What remains is what
    can change between two executions of the compiled artifact without any
    argument changing - precisely what a guard has to see.
    """
    reads: Set[str] = set()
    writes: Set[str] = set()
    for qname in fnames:
        fn = mod.functions.get(qname)
        if fn is None or isinstance(fn, ast.ClassDef):
            continue
        local = _local_names(fn)
        declared_global: Set[str] = set()
        for node in ast.walk(fn):
            if isinstance(node, ast.Global):
                declared_global.update(node.names)
            elif isinstance(node, ast.Nonlocal):
                declared_global.update(node.names)
        local -= declared_global

        call_roots: Set[int] = set()
        for node in ast.walk(fn):
            if isinstance(node, ast.Call) and isinstance(node.func, ast.Attribute):
                base = node.func.value
                while isinstance(base, ast.Attribute):
                    base = base.value
                call_roots.add(id(base))

        for node in ast.walk(fn):
            if isinstance(node, ast.Name):
                n = node.id
                if isinstance(node.ctx, ast.Load):
                    if n in local or n in _BUILTINS or n in _MODULE_ROOTS:
                        continue
                    if n in mod.functions or n in mod.imports:
                        continue
                    if id(node) in call_roots:
                        continue
                    reads.add(n)
                elif isinstance(node.ctx, ast.Store) and n in declared_global:
                    writes.add(n)
            elif isinstance(node, ast.Attribute):
                base = node.value
                if isinstance(base, ast.Name) and (base.id == "self" or base.id not in local):
                    if base.id in _MODULE_ROOTS or base.id in mod.imports:
                        continue
                    key = f"{base.id}.{node.attr}"
                    if isinstance(node.ctx, ast.Store):
                        writes.add(key)
                    elif isinstance(node.ctx, ast.Load) and id(node) not in call_roots \
                            and not _is_call_func(fn, node):
                        reads.add(key)
            elif isinstance(node, ast.Subscript) and isinstance(node.ctx, ast.Store):
                base = node.value
                while isinstance(base, (ast.Attribute, ast.Subscript)):
                    base = base.value
                if isinstance(base, ast.Name) and (base.id == "self" or base.id not in local):
                    writes.add(f"{_unparse(node.value)}[...]")
    return sorted(reads), sorted(writes)


def _is_call_func(fn: ast.AST, attr: ast.Attribute) -> bool:
    for node in ast.walk(fn):
        if isinstance(node, ast.Call) and node.func is attr:
            return True
    return False


# --------------------------------------------------------------------------
# entry points
# --------------------------------------------------------------------------

def iter_py_files(path: str) -> Iterator[str]:
    if os.path.isfile(path):
        if path.endswith(".py"):
            yield path
        return
    for root, dirs, files in os.walk(path):
        dirs[:] = [d for d in dirs if d not in _SKIP_DIRS]
        for f in sorted(files):
            if f.endswith(".py"):
                yield os.path.join(root, f)


def scan_file(path: str) -> List[CompilationSite]:
    mod = _load(path)
    if mod is None:
        return []
    sites: List[CompilationSite] = []
    for s in _sites_in(mod):
        if s.target and s.target in mod.functions:
            s.reachable = _reachable(mod, s.target)
            s.external_reads, s.external_writes = _external_state(
                mod, [s.target] + s.reachable)
        sites.append(s)
    return sites


def scan_path(path: str) -> List[CompilationSite]:
    """Every compilation site under ``path`` (a file or a directory)."""
    out: List[CompilationSite] = []
    for f in iter_py_files(path):
        out.extend(scan_file(f))
    return out


def scan_source(src: str, name: str = "<src>") -> List[CompilationSite]:
    """Scan source text - for tests and for functions built by ``exec``."""
    try:
        tree = ast.parse(src)
    except SyntaxError:
        return []
    imports = _import_map(tree)
    functions = _collect_functions(tree)
    mod = _Module(path=name, tree=tree, imports=imports, functions=functions,
                  module_names=_module_names(tree),
                  wrappers=_find_wrappers(functions, imports))
    sites: List[CompilationSite] = []
    for s in _sites_in(mod):
        if s.target and s.target in mod.functions:
            s.reachable = _reachable(mod, s.target)
            s.external_reads, s.external_writes = _external_state(
                mod, [s.target] + s.reachable)
        sites.append(s)
    return sites


def site_source(site: CompilationSite) -> Optional[str]:
    """Source text of the site's target function, for Phase 1 analysis.

    Returns ``None`` when the target is an expression rather than a definition
    in the same file (``torch.compile(model)`` on an instance).
    """
    if not site.target:
        return None
    mod = _load(site.file)
    if mod is None:
        return None
    fn = mod.functions.get(site.target)
    if fn is None:
        return None
    if isinstance(fn, ast.ClassDef):
        fn = mod.functions.get(f"{site.target}.forward")
        if fn is None:
            return None
    try:
        with open(site.file, "r", encoding="utf-8", errors="replace") as fh:
            src = fh.read()
        seg = ast.get_source_segment(src, fn)
    except Exception:
        return None
    if seg is None:
        return None
    # decorators are not part of the function's semantics for Phase 1, and a
    # decorated function fails ``analyze_source``'s "first def" lookup
    lines = seg.splitlines()
    while lines and lines[0].lstrip().startswith("@"):
        lines.pop(0)
    return "\n".join(lines)


def format_sites(sites: List[CompilationSite]) -> str:
    if not sites:
        return "  no compilation sites found"
    L: List[str] = []
    for s in sites:
        loc = f"{os.path.basename(s.file)}:{s.line}"
        via = f" via {s.via_wrapper}" if s.via_wrapper else ""
        L.append(f"  {loc:<28} {s.api:<16} {s.form:<18} {s.target or '?'}{via}")
        if s.backend:
            L.append(f"      backend  : {s.backend}")
        if s.options:
            L.append(f"      options  : {s.options}")
        if s.arguments and s.api == "torch.jit.trace":
            L.append(f"      examples : {s.arguments}")
        if s.reachable:
            L.append(f"      reachable: {', '.join(s.reachable)}")
        if s.external_reads:
            L.append(f"      reads    : {', '.join(s.external_reads)}")
        if s.external_writes:
            L.append(f"      writes   : {', '.join(s.external_writes)}")
    return "\n".join(L)
