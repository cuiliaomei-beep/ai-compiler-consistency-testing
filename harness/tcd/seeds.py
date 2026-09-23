"""Load imported issue reproducers as harness cases.

``tools/import_seeds.py`` writes a manifest; this turns each entry into a live
:class:`tcd.case.Case`. Keeping the manifest as data rather than generating
Python source means provenance survives: every case still carries the incident
id, the issue title, and the project it came from, so a finding can be traced
back to the report it was derived from.

Only run this against a manifest produced by the importer, whose safety gates
decide what is allowed to execute at all. This module does not re-check them.
"""
from __future__ import annotations

import json
import os
from typing import Any, Callable, Dict, List, Optional, Tuple

from .case import Case, Context, register
from .torchcompat import torch

DEFAULT_MANIFEST = os.path.join(
    os.path.dirname(os.path.dirname(os.path.abspath(__file__))), "seeds", "manifest.json"
)

_DTYPES = {
    "float16": "float16", "float32": "float32",
    "float64": "float64", "bfloat16": "bfloat16",
}


# --------------------------------------------------------------------------
# context transforms
# --------------------------------------------------------------------------

def _cast(t: Any, dtype_name: str) -> Any:
    if torch is None or not isinstance(t, torch.Tensor):
        return t
    if not t.is_floating_point():
        return t
    try:
        return t.to(getattr(torch, dtype_name))
    except Exception:
        return t


def _make_noncontiguous(t: Any) -> Any:
    """Same values, non-unit innermost stride.

    Built by writing into every other column of a wider buffer and returning
    that strided view, so the *values* are untouched and only the layout
    differs. That is what makes a divergence attributable to layout rather
    than to different data.
    """
    if torch is None or not isinstance(t, torch.Tensor) or t.dim() == 0:
        return t
    if not t.is_contiguous():
        return t  # already the interesting case
    try:
        shape = list(t.shape)
        shape[-1] *= 2
        big = torch.empty(shape, dtype=t.dtype, device=t.device)
        view = big[..., ::2]
        view.copy_(t)
        if t.requires_grad:
            view.requires_grad_(True)
        return view
    except Exception:
        return t


def _resize_dim(t: Any, dim: int, n: int) -> Any:
    """Resize one dimension to exactly ``n``, keeping the data plausible.

    Shorter: slice. Longer: tile then slice. Either way the result is a fresh
    contiguous tensor, so a later in-place write cannot reach the original.
    """
    if torch is None or not isinstance(t, torch.Tensor) or t.dim() == 0:
        return t
    if not (-t.dim() <= dim < t.dim()):
        return t
    dim = dim % t.dim()
    cur = t.shape[dim]
    if cur == n or n <= 0:
        return t
    try:
        if n < cur:
            return t.narrow(dim, 0, n).clone()
        reps = [1] * t.dim()
        reps[dim] = (n + cur - 1) // cur
        return t.repeat(*reps).narrow(dim, 0, n).clone()
    except Exception:
        return t


def _resize_dim0(t: Any, n: int) -> Any:
    return _resize_dim(t, 0, n)


def _apply_context(args: Tuple[Any, ...], ctx: Context) -> Tuple[Any, ...]:
    """Apply one context to an argument tuple.

    Contexts now arrive from :mod:`tcd.obligation`, derived per function, so
    the structured forms below (``resize``, ``substitute``, ``requires_grad``)
    carry an argument index: the obligation knows *which* parameter the source
    predicate read, and acting on the wrong one would test nothing.
    """
    out = list(args)

    # --- structured, obligation-derived transforms ---
    resize = ctx.get("resize")
    if isinstance(resize, dict):
        i, dim, value = resize.get("arg", 0), resize.get("dim", 0), resize.get("value")
        if 0 <= i < len(out) and isinstance(value, int):
            out[i] = _resize_dim(out[i], dim, value)

    sub = ctx.get("substitute")
    if isinstance(sub, dict):
        i = sub.get("arg", 0)
        if 0 <= i < len(out):
            out[i] = sub.get("value")

    rg = ctx.get("requires_grad")
    if isinstance(rg, dict):
        i, value = rg.get("arg", 0), bool(rg.get("value"))
        if 0 <= i < len(out) and torch is not None and isinstance(out[i], torch.Tensor):
            if out[i].is_floating_point():
                t = out[i].detach().clone()
                t.requires_grad_(value)
                out[i] = t

    dtype = ctx.get("dtype")
    if dtype in _DTYPES:
        target = getattr(torch, _DTYPES[dtype]) if torch is not None else None
        # Some operators take a dtype *as an argument* - `_softmax_backward_data`
        # receives `input_dtype` positionally. Casting the tensors while leaving
        # that argument behind builds a self-contradictory program: float64 data
        # declared as float32. The op then computes in the declared precision and
        # the result looks like a miscompilation.
        out = [
            target if (torch is not None and isinstance(a, torch.dtype)
                       and a.is_floating_point and target is not None)
            else _cast(a, _DTYPES[dtype])
            for a in out
        ]
    if ctx.get("variant") == "noncontig":
        out = [_make_noncontiguous(a) for a in out]
    dim0 = ctx.get("resize_dim0")
    if isinstance(dim0, int):
        for i, a in enumerate(out):
            if torch is not None and isinstance(a, torch.Tensor) and a.dim() >= 1:
                out[i] = _resize_dim0(a, dim0)
                break
    return tuple(out)


# --------------------------------------------------------------------------
# building a Case from a manifest entry
# --------------------------------------------------------------------------

def _build_case(entry: Dict[str, Any]) -> Optional[Case]:
    iid = entry["incident_id"]
    base_ns: Dict[str, Any] = {"__name__": f"_seed_{iid}"}
    try:
        exec(compile(entry["prelude"], f"<{iid}:prelude>", "exec"), base_ns)
        exec(compile(entry["fn_source"], f"<{iid}:fn>", "exec"), base_ns)
    except Exception:
        return None

    fn = base_ns.get(entry["fn_name"])
    if not callable(fn):
        return None

    setup_code = compile(entry["setup"], f"<{iid}:setup>", "exec")
    arg_exprs = entry["arg_exprs"]

    def make_inputs(ctx: Context, _ns=base_ns, _setup=setup_code,
                    _args=arg_exprs) -> Tuple[Any, ...]:
        # a shallow copy shares the imports/classes but lets `setup` rebind the
        # input names, so every call allocates its own tensors
        ns = dict(_ns)
        exec(_setup, ns)
        return _apply_context(tuple(eval(a, ns) for a in _args), ctx)

    contexts = [Context(c["name"], dict(c.get("factors") or {}))
                for c in entry.get("contexts", [])]
    if not contexts:
        contexts = [Context("base", {"variant": "base"})]

    refs = entry.get("references") or []
    note = entry.get("title", "")
    if refs:
        note += f"\n{refs[0]}"

    return Case(
        name=f"seed_{iid.replace('TC-', '').replace('-', '_')}",
        fn=fn,
        make_inputs=make_inputs,
        contexts=contexts,
        tags=["seed", entry.get("project", "").split("/")[-1] or "unknown"],
        notes=note,
        source=entry["fn_source"],
    )


def load_seed_cases(manifest: str = DEFAULT_MANIFEST,
                    register_them: bool = True) -> List[Case]:
    """Read the manifest and build (and optionally register) the cases."""
    if not os.path.exists(manifest):
        return []
    with open(manifest, encoding="utf-8") as fh:
        entries = json.load(fh)

    cases: List[Case] = []
    for entry in entries:
        case = _build_case(entry)
        if case is None:
            continue
        cases.append(case)
        if register_them:
            try:
                register(case)
            except ValueError:
                pass  # already registered
    return cases


def manifest_summary(manifest: str = DEFAULT_MANIFEST) -> Dict[str, Any]:
    if not os.path.exists(manifest):
        return {"entries": 0, "path": manifest, "exists": False}
    with open(manifest, encoding="utf-8") as fh:
        entries = json.load(fh)
    projects: Dict[str, int] = {}
    for e in entries:
        p = e.get("project", "?")
        projects[p] = projects.get(p, 0) + 1
    return {"entries": len(entries), "path": manifest, "exists": True,
            "projects": projects}
