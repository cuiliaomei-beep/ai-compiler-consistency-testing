"""Binding-form factor as a Phase-1 program transformation (NEXT_DIRECTIONS 5.4, plan section 6).

For a program's source, every scalar literal in the function body (int / float /
bool / str) is a *binding site*: the same value can reach the operator as a
literal, a module global, a closure cell, an object attribute, a list or dict
element, a default parameter, a positional parameter, or a ``**kwargs`` expansion.
Dynamo specialises each source differently (constant / SymInt / guarded read),
so each form is a distinct program variant with identical semantics. The
variants enter the ordinary pipeline (Phase-1 analysis, contexts, cold/warm,
oracles) like any other program; a divergence on one form only is attributable
to the compiler's treatment of that binding.
"""
from __future__ import annotations

import ast
import textwrap
from typing import Any, Callable, Dict, List, Optional, Sequence, Tuple

from .compat import torch
from .program import Program

FORMS = ("global", "closure", "attribute", "list_elem", "dict_elem", "default_param", "pos_param", "kwargs_expand")


def _function_def(tree: ast.Module, name: str) -> Optional[ast.FunctionDef]:
    for node in ast.walk(tree):
        if isinstance(node, ast.FunctionDef) and node.name == name:
            return node
    for node in tree.body:
        if isinstance(node, ast.FunctionDef):
            return node
    return None


def scalar_sites(fdef: ast.FunctionDef) -> List[Tuple[ast.Constant, Optional[ast.Call], Optional[str]]]:
    """Scalar literals in the body: (node, enclosing call or None, keyword name or None)."""
    out: List[Tuple[ast.Constant, Optional[ast.Call], Optional[str]]] = []
    seen: set = set()

    def visit(node: ast.AST, call: Optional[ast.Call], kw: Optional[str]) -> None:
        if isinstance(node, ast.Constant) and isinstance(node.value, (int, float, bool, str)) \
                and not isinstance(node, ast.JoinedStr) and id(node) not in seen:
            if isinstance(node.value, str) and (len(node.value) > 24 or not node.value):
                return
            seen.add(id(node))
            out.append((node, call, kw))
            return
        if isinstance(node, ast.JoinedStr):
            return
        if isinstance(node, ast.Call):
            visit(node.func, None, None)
            for a in node.args:
                visit(a, node, None)
            for k in node.keywords:
                visit(k.value, node, k.arg)
            return
        for child in ast.iter_child_nodes(node):
            visit(child, None if not isinstance(node, (ast.Call,)) else call, kw if isinstance(node, ast.keyword) else None)

    for stmt in fdef.body:
        if isinstance(stmt, ast.Expr) and isinstance(stmt.value, ast.Constant) and isinstance(stmt.value.value, str):
            continue   # docstring
        visit(stmt, None, None)
    return out


class _Replace(ast.NodeTransformer):
    def __init__(self, target: ast.AST, new: Callable[[], ast.AST]):
        self.target, self.new = target, new

    def visit_Constant(self, node: ast.Constant):
        if node is self.target:
            return ast.copy_location(self.new(), node)
        return node


def _rewrite(src: str, fname: str, site_index: int, form: str) -> Optional[Tuple[str, Any, Optional[str]]]:
    """Return (new_source, literal_value, keyword_name) or None when the form does not apply."""
    tree = ast.parse(src)
    fdef = _function_def(tree, fname)
    if fdef is None:
        return None
    sites = scalar_sites(fdef)
    if site_index >= len(sites):
        return None
    node, call, kw = sites[site_index]
    v = node.value
    lit = repr(v)
    name = f"_bind_k{site_index}"
    prelude: List[str] = []
    if form == "global":
        prelude.append(f"{name} = {lit}")
        _Replace(node, lambda: ast.Name(id=name, ctx=ast.Load())).visit(fdef)
    elif form == "attribute":
        prelude.append(f"class _BindCfg{site_index}:\n    pass\n_bind_cfg{site_index} = _BindCfg{site_index}()\n"
                       f"_bind_cfg{site_index}.k = {lit}")
        _Replace(node, lambda: ast.Attribute(value=ast.Name(id=f"_bind_cfg{site_index}", ctx=ast.Load()), attr="k",
                                             ctx=ast.Load())).visit(fdef)
    elif form == "list_elem":
        prelude.append(f"_bind_list{site_index} = [{lit}]")
        _Replace(node, lambda: ast.Subscript(value=ast.Name(id=f"_bind_list{site_index}", ctx=ast.Load()),
                                             slice=ast.Constant(0), ctx=ast.Load())).visit(fdef)
    elif form == "dict_elem":
        prelude.append(f"_bind_dict{site_index} = {{'k': {lit}}}")
        _Replace(node, lambda: ast.Subscript(value=ast.Name(id=f"_bind_dict{site_index}", ctx=ast.Load()),
                                             slice=ast.Constant("k"), ctx=ast.Load())).visit(fdef)
    elif form == "default_param":
        fdef.args.kwonlyargs.append(ast.arg(arg=name))
        fdef.args.kw_defaults.append(ast.Constant(v))
        _Replace(node, lambda: ast.Name(id=name, ctx=ast.Load())).visit(fdef)
    elif form == "pos_param":
        if fdef.args.vararg is not None or fdef.args.kwonlyargs:
            return None
        fdef.args.args.append(ast.arg(arg=name))
        _Replace(node, lambda: ast.Name(id=name, ctx=ast.Load())).visit(fdef)
    elif form == "closure":
        _Replace(node, lambda: ast.Name(id=name, ctx=ast.Load())).visit(fdef)
        inner = ast.unparse(fdef)
        body = textwrap.indent(inner, "    ")
        new_src = f"def _bind_make{site_index}({name}):\n{body}\n    return {fname}\n{fname} = _bind_make{site_index}({lit})\n"
        return new_src, v, kw
    elif form == "kwargs_expand":
        if call is None or kw is None:
            return None
        prelude.append(f"_bind_opts{site_index} = {{{kw!r}: {lit}}}")
        call.keywords = [k for k in call.keywords if k.arg != kw] + \
            [ast.keyword(arg=None, value=ast.Name(id=f"_bind_opts{site_index}", ctx=ast.Load()))]
    else:
        return None
    ast.fix_missing_locations(fdef)
    new_src = "\n".join(prelude) + ("\n" if prelude else "") + ast.unparse(fdef) + "\n"
    return new_src, v, kw


def expand(program: Program, max_sites: int = 1, forms: Sequence[str] = FORMS) -> List[Program]:
    """Binding-form variants of ``program`` (the original is not included)."""
    src = program.get_source()
    if not src:
        return []
    src = textwrap.dedent(src)
    fname = getattr(program.fn, "__name__", None)
    if not fname or isinstance(program.fn, (torch.nn.Module if torch is not None else tuple)):
        return []
    try:
        tree = ast.parse(src)
    except SyntaxError:
        return []
    fdef = _function_def(tree, fname)
    if fdef is None:
        return []
    n_sites = min(max_sites, len(scalar_sites(fdef)))
    out: List[Program] = []
    ns_base: Dict[str, Any] = dict(getattr(program.fn, "__globals__", {}))
    ns_base.setdefault("torch", torch)
    # a program that is itself a closure (corpus `closure_fn`): its free variables must resolve too
    code, cells = getattr(program.fn, "__code__", None), getattr(program.fn, "__closure__", None)
    if code is not None and cells:
        for free, cell in zip(code.co_freevars, cells):
            try:
                ns_base[free] = cell.cell_contents
            except ValueError:
                pass
    for i in range(n_sites):
        for form in forms:
            r = _rewrite(src, fname, i, form)
            if r is None:
                continue
            new_src, v, kw = r
            # exec into a real, importable module: Dynamo resolves fn.__module__ through sys.modules, and a
            # function whose globals carry the loader's synthetic module name would fail with
            # InternalTorchDynamoError: ModuleNotFoundError (seen on every issue-reproducer variant)
            import sys as _sys
            import types as _types
            mod_name = f"tcc_bind_{abs(hash((program.name, form, i))) % 10**8:08d}"
            module = _types.ModuleType(mod_name)
            module.__dict__.update(ns_base)
            module.__dict__["__name__"] = mod_name
            _sys.modules[mod_name] = module
            ns = module.__dict__
            try:
                exec(compile(new_src, f"<bind:{program.name}:{form}{i}>", "exec"), ns)
            except Exception:
                _sys.modules.pop(mod_name, None)
                continue
            fn = ns.get(fname)
            if not callable(fn):
                continue
            mk = program.make_inputs
            if form == "pos_param":
                def mk(ctx, _b=program.make_inputs, _v=v):
                    a = _b(ctx)
                    a = a if isinstance(a, tuple) else (a,)
                    return a + (_v,)
            out.append(Program(name=f"{program.name}__bind_{form}{i}", fn=fn, make_inputs=mk,
                               base_context=program.base_context, tags=list(program.tags) + ["binding", f"bind:{form}"],
                               notes=(program.notes + f"\nbinding form {form} for literal {v!r}"
                                      + (f" (keyword {kw})" if kw else "")).strip(),
                               expect=program.expect, source=new_src, project=program.project,
                               skip_fp64=program.skip_fp64, check_grad=program.check_grad,
                               compile_options=dict(program.compile_options), site=program.site,
                               contexts=list(program.contexts), reset=program.reset))
    return out


def expand_all(programs: Sequence[Program], max_sites: int = 1, forms: Sequence[str] = FORMS,
               keep_original: bool = True) -> List[Program]:
    out: List[Program] = []
    for p in programs:
        if keep_original:
            out.append(p)
        out.extend(expand(p, max_sites, forms))
    return out
