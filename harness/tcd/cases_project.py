"""Plan sections 11.1 (seed sources 3 and 4) and 21: cases from real code.

Two seed sources the plan lists that the other corpora do not cover:

**Signature / annotation construction (11.1 item 4).** Given only a function
object, build a legal input tuple from its signature: annotations first,
defaults second, and parameter-name conventions last. This is what turns a
compilation site found by :mod:`tcd.sites` into something Phase 2 can run.

**Official examples (11.1 item 3).** PyTorch ships its examples inside
docstrings, as ``>>>`` lines. Those are official, offline, and already legal
by construction. :func:`iter_doctest_cases` extracts the ones that build
tensors and then call the documented operator.

Both sources produce *candidate* cases. Whether one is usable is decided the
same way as everywhere else in the harness: eager has to run under the base
context, or the case is dropped before it can produce a phantom divergence.

Importing a project file executes its module-level code. ``cases_from_file``
therefore only runs when asked for explicitly, and never on a path the user
did not name.
"""
from __future__ import annotations

import importlib.util
import inspect
import os
import re
import sys
from typing import Any, Callable, Dict, Iterator, List, Optional, Sequence, Tuple

from .case import Case, Context
from .torchcompat import seed_everything, torch

# --------------------------------------------------------------------------
# 11.1 item 4: signature-driven construction
# --------------------------------------------------------------------------

#: parameter-name conventions, used only when neither annotation nor default
#: says what a parameter is
_INT_NAMES = re.compile(r"^(n|k|m|dim|axis|size|num_\w+|n_\w+|count|steps?|depth|"
                        r"width|height|batch\w*|seq\w*|hidden\w*|channels?|groups?|"
                        r"kernel\w*|stride|padding|dilation|chunks?|repeats?|blocks?)$")
_FLAG_NAMES = re.compile(r"^(use_\w+|is_\w+|enable\w*|has_\w+|training|inplace|"
                         r"keepdim|bias|fast|flag\w*|do_\w+|with_\w+|return_\w+)$")
_FLOAT_NAMES = re.compile(r"^(eps|alpha|beta|gamma|scale|lr|p|rate|temperature|"
                          r"momentum|dropout|weight_decay|threshold|tol\w*|factor)$")

DEFAULT_SHAPE = (4, 8)


def _from_annotation(ann: Any, name: str) -> Tuple[bool, Any]:
    """(recognised, maker) for an annotation."""
    text = ann if isinstance(ann, str) else getattr(ann, "__name__", repr(ann))
    text = str(text)
    if torch is not None and (ann is torch.Tensor or "Tensor" in text):
        return True, lambda: torch.randn(*DEFAULT_SHAPE)
    if ann is int or text == "int":
        return True, lambda: 4
    if ann is float or text == "float":
        return True, lambda: 0.5
    if ann is bool or text == "bool":
        return True, lambda: True
    if ann is str or text == "str":
        return True, lambda: "mean"
    if "Optional" in text or "None" in text:
        return True, lambda: None
    if "List" in text or "list" in text or "Sequence" in text or "Tuple" in text:
        return True, lambda: [1, 2]
    return False, None


def _from_name(name: str) -> Callable[[], Any]:
    if _FLAG_NAMES.match(name):
        return lambda: True
    if _INT_NAMES.match(name):
        return lambda: 4
    if _FLOAT_NAMES.match(name):
        return lambda: 0.5
    # everything else is assumed to be a tensor: it is the common case in
    # compiled code, and a wrong guess is caught by the eager validity gate
    return lambda: torch.randn(*DEFAULT_SHAPE)


def argument_makers(fn: Callable) -> Optional[List[Tuple[str, Callable[[], Any]]]]:
    """One maker per positional parameter, or ``None`` when the signature is
    unreadable (builtins, C extensions)."""
    try:
        sig = inspect.signature(fn)
    except (TypeError, ValueError):
        return None
    makers: List[Tuple[str, Callable[[], Any]]] = []
    for p in sig.parameters.values():
        if p.kind in (p.VAR_POSITIONAL, p.VAR_KEYWORD):
            continue
        if p.name == "self":
            continue
        if p.default is not inspect.Parameter.empty:
            d = p.default
            if torch is not None and isinstance(d, torch.Tensor):
                makers.append((p.name, lambda _d=d: _d.detach().clone()))
            else:
                makers.append((p.name, lambda _d=d: _d))
            continue
        if p.annotation is not inspect.Parameter.empty:
            ok, maker = _from_annotation(p.annotation, p.name)
            if ok:
                makers.append((p.name, maker))
                continue
        makers.append((p.name, _from_name(p.name)))
    return makers


def case_from_function(fn: Callable, name: Optional[str] = None,
                       source: Optional[str] = None,
                       tags: Sequence[str] = ("project",),
                       notes: str = "") -> Optional[Case]:
    """Build a Case for an arbitrary function from its signature alone."""
    if torch is None:
        return None
    makers = argument_makers(fn)
    if makers is None:
        return None
    from .seeds import _apply_context

    def make_inputs(ctx: Context, _m=tuple(makers)) -> Tuple[Any, ...]:
        seed_everything(0)
        return _apply_context(tuple(mk() for _, mk in _m), ctx)

    if source is None:
        try:
            source = inspect.getsource(fn)
        except (OSError, TypeError):
            source = None

    contexts: List[Context] = [Context("base", {"variant": "base"})]
    if source:
        try:
            from .obligation import contexts_for_source
            derived, _scs, _obl = contexts_for_source(source)
            if derived:
                contexts = derived
        except Exception:
            pass

    return Case(
        name=name or f"proj_{getattr(fn, '__name__', 'fn')}",
        fn=fn,
        make_inputs=make_inputs,
        contexts=contexts,
        tags=list(tags),
        notes=notes or f"signature-constructed inputs: "
                       f"{', '.join(n for n, _ in makers)}",
        source=source,
    )


# --------------------------------------------------------------------------
# 21: compile/JIT functions in real project files
# --------------------------------------------------------------------------

def _import_file(path: str) -> Any:
    name = "_tcd_proj_" + re.sub(r"\W", "_", os.path.splitext(os.path.basename(path))[0])
    spec = importlib.util.spec_from_file_location(name, path)
    if spec is None or spec.loader is None:
        raise ImportError(path)
    mod = importlib.util.module_from_spec(spec)
    sys.modules[name] = mod
    d = os.path.dirname(os.path.abspath(path))
    if d not in sys.path:
        sys.path.insert(0, d)
    spec.loader.exec_module(mod)
    return mod


def _resolve(mod: Any, dotted: str) -> Any:
    obj: Any = mod
    for part in dotted.split("."):
        obj = getattr(obj, part)
    return obj


def cases_from_file(path: str, limit: int = 0) -> Tuple[List[Case], List[str]]:
    """Import ``path`` and build a Case for every compilation site's target.

    The target is unwrapped (``torch.compile`` returns a wrapper) so the
    harness compiles the *original* under its own controlled backends rather
    than executing the project's already-compiled object.

    Returns ``(cases, notes)``; notes explain each site that yielded nothing.
    """
    from .ir import unwrap
    from .sites import scan_file, site_source

    notes: List[str] = []
    sites = scan_file(path)
    if not sites:
        return [], [f"{path}: no compilation sites"]
    try:
        mod = _import_file(path)
    except Exception as e:  # noqa: BLE001
        return [], [f"{path}: import failed: {type(e).__name__}: {str(e)[:120]}"]

    cases: List[Case] = []
    seen: set = set()
    for s in sites:
        if not s.target or s.target in seen:
            continue
        try:
            obj = _resolve(mod, s.target)
        except AttributeError:
            notes.append(f"{s.target}: not an attribute of the module (expression target)")
            continue
        seen.add(s.target)
        fn, _layers = unwrap(obj)
        if isinstance(fn, type):
            # a class: instantiate with no arguments and test forward
            try:
                inst = fn()
                fn = inst
            except Exception as e:  # noqa: BLE001
                notes.append(f"{s.target}: cannot instantiate: {type(e).__name__}")
                continue
        if not callable(fn):
            notes.append(f"{s.target}: not callable")
            continue
        src = site_source(s)
        case = case_from_function(
            fn, name=f"proj_{os.path.splitext(os.path.basename(path))[0]}_{s.target.replace('.', '_')}",
            source=src, tags=["project", s.api],
            notes=f"{os.path.basename(path)}:{s.line} {s.api} ({s.form})")
        if case is None:
            notes.append(f"{s.target}: signature unreadable")
            continue
        cases.append(case)
        if limit and len(cases) >= limit:
            break
    return cases, notes


# --------------------------------------------------------------------------
# 11.1 item 3: official docstring examples
# --------------------------------------------------------------------------

_PROMPT = re.compile(r"^\s*>>> ?")
_CONT = re.compile(r"^\s*\.\.\. ?")


def _example_blocks(doc: str) -> Iterator[List[str]]:
    """Consecutive ``>>>``/``...`` lines, as blocks of statements."""
    block: List[str] = []
    cur: Optional[str] = None
    for raw in doc.splitlines():
        if _PROMPT.match(raw):
            if cur is not None:
                block.append(cur)
            cur = _PROMPT.sub("", raw)
        elif _CONT.match(raw) and cur is not None:
            cur += "\n" + _CONT.sub("", raw)
        else:
            if cur is not None:
                block.append(cur)
                cur = None
            if block and raw.strip() == "":
                continue
            if block:
                yield block
                block = []
    if cur is not None:
        block.append(cur)
    if block:
        yield block


#: statements an example may contain: tensor construction and the call itself
_ALLOWED_CALL = re.compile(r"^(torch\.|x\.|a\.|b\.|t\.|input\.|F\.)")
_FORBIDDEN = re.compile(r"(import |open\(|__|os\.|sys\.|subprocess|eval\(|exec\(|"
                        r"\.cuda\(|device=|requires_grad|manual_seed|print\(|"
                        r"random\.|save\(|load\()")


def _split_example(block: List[str], op_name: str) -> Optional[Tuple[List[str], str]]:
    """(setup statements, final call expression) when the block fits the shape.

    The shape is: zero or more assignments building tensors, then one
    expression that calls the documented operator. Anything else is rejected
    - this is an example importer, not an interpreter.
    """
    setup: List[str] = []
    call: Optional[str] = None
    for stmt in block:
        if _FORBIDDEN.search(stmt):
            return None
        if "=" in stmt and not stmt.strip().startswith(op_name) and "==" not in stmt:
            lhs = stmt.split("=", 1)[0].strip()
            if not re.match(r"^[A-Za-z_]\w*$", lhs):
                return None
            setup.append(stmt)
        elif op_name in stmt and _ALLOWED_CALL.match(stmt.strip()):
            call = stmt.strip()
    if call is None:
        return None
    return setup, call


def iter_doctest_cases(limit: int = 0, namespace: str = "torch") -> Iterator[Case]:
    """Cases from ``>>>`` examples in the docstrings of ``torch.*`` callables.

    Each case's inputs are the tensors the example itself builds, re-executed
    under a fixed seed for every context; the function is the example's final
    call, with the built names as parameters so contexts can rewrite them.
    """
    if torch is None:
        return
    from .seeds import _apply_context

    ns_obj = torch if namespace == "torch" else _resolve(torch, namespace.split(".", 1)[1])
    made = 0
    for attr in sorted(dir(ns_obj)):
        if attr.startswith("_"):
            continue
        obj = getattr(ns_obj, attr, None)
        doc = getattr(obj, "__doc__", None)
        if not callable(obj) or not doc or ">>>" not in doc:
            continue
        op_name = f"{namespace}.{attr}"
        for bi, block in enumerate(_example_blocks(doc)):
            split = _split_example(block, op_name)
            if split is None:
                continue
            setup, call = split
            names = [s.split("=", 1)[0].strip() for s in setup]
            if not names:
                continue
            # the example's own tensors become the parameters
            fn_src = f"def f({', '.join(names)}):\n    return {call}\n"
            ns: Dict[str, Any] = {"torch": torch, "F": torch.nn.functional}
            try:
                exec(compile(fn_src, f"<doctest:{op_name}:{bi}>", "exec"), ns)
            except Exception:
                continue
            fn = ns["f"]
            setup_code = "\n".join(setup)
            try:
                probe = dict(ns)
                exec(compile(setup_code, f"<doctest:{op_name}:{bi}:setup>", "exec"), probe)
                args = tuple(probe[n] for n in names)
            except Exception:
                continue
            if not any(isinstance(a, torch.Tensor) for a in args):
                continue

            def make_inputs(ctx: Context, _ns=ns, _code=setup_code, _names=tuple(names)
                            ) -> Tuple[Any, ...]:
                seed_everything(0)
                local = dict(_ns)
                exec(compile(_code, "<doctest-setup>", "exec"), local)
                return _apply_context(tuple(local[n] for n in _names), ctx)

            contexts: List[Context] = [Context("base", {"variant": "base"})]
            try:
                from .obligation import contexts_for_source
                derived, _s, _o = contexts_for_source(fn_src)
                if derived:
                    contexts = derived
            except Exception:
                pass
            yield Case(
                name=f"doc_{attr}_{bi}",
                fn=fn,
                make_inputs=make_inputs,
                contexts=contexts,
                tags=["doctest", op_name],
                notes=f"official docstring example {bi} of {op_name}",
                source=fn_src,
            )
            made += 1
            if limit and made >= limit:
                return
            break  # one example per operator keeps the corpus balanced
