"""Injected consistency defects: the ground-truth detection benchmark.

Plan section 21 asks for a historical benchmark with buggy and fixed
versions. Those entries need a reproducer that runs on a *buggy* PyTorch
build, which a single-version machine cannot provide. This module supplies
the complementary, fully controlled half: each :class:`Fault` wraps a real
``torch.compile`` artifact and injects **one** of the three defect classes
the plan targets (code-generation deviation, JIT specialization
inconsistency, cache consistency failure), at a known trigger condition.

The "fixed version" of every fault is the real compiler (``fault=None``),
so false positives on fixed versions (RQ1) are measured for free.

Every fault records which semantic-factor family and which oracle should
catch it, so per-category recall (RQ1) and the ablation (RQ3) have labels.
"""
from __future__ import annotations

from dataclasses import dataclass, field
from typing import Any, Callable, Dict, List, Optional, Tuple

from .compat import torch
from .execute import Compiler, TorchCompiler
from .program import Context

# RQ1 categories
CAT_SHAPE = "shape"
CAT_DTYPE = "dtype"
CAT_CONTROL = "control_flow"
CAT_ALIAS = "alias_mutation"
CAT_CODEGEN = "codegen"
CAT_SPECIALIZATION = "specialization"
CAT_CACHE = "cache"

# plan section 1 defect classes
CLASS_CODEGEN = "code_generation_deviation"
CLASS_SPECIALIZATION = "jit_specialization_inconsistency"
CLASS_CACHE = "cache_consistency_failure"


def _first_tensor(args: Tuple[Any, ...]):
    for a in args:
        if torch is not None and isinstance(a, torch.Tensor):
            return a
    return None


def _perturb(out: Any, delta: float = 1.0) -> Any:
    if torch is not None and isinstance(out, torch.Tensor):
        if out.is_floating_point():
            return out + delta
        return out
    if isinstance(out, (list, tuple)):
        conv = [_perturb(v, delta) for v in out]
        return type(out)(conv) if isinstance(out, tuple) else conv
    if isinstance(out, dict):
        return {k: _perturb(v, delta) for k, v in out.items()}
    return out


def _clone(out: Any) -> Any:
    if torch is not None and isinstance(out, torch.Tensor):
        return out.clone()
    if isinstance(out, (list, tuple)):
        conv = [_clone(v) for v in out]
        return type(out)(conv) if isinstance(out, tuple) else conv
    if isinstance(out, dict):
        return {k: _clone(v) for k, v in out.items()}
    return out


def _cast_tree(obj: Any, dtype) -> Any:
    if torch is not None and isinstance(obj, torch.Tensor) and obj.is_floating_point():
        return obj.to(dtype)
    if isinstance(obj, (list, tuple)):
        conv = [_cast_tree(v, dtype) for v in obj]
        return type(obj)(conv) if isinstance(obj, tuple) else conv
    if isinstance(obj, dict):
        return {k: _cast_tree(v, dtype) for k, v in obj.items()}
    return obj


def _dtype_of(args: Tuple[Any, ...]):
    t = _first_tensor(args)
    return t.dtype if t is not None else None


def _shape_key(args: Tuple[Any, ...]) -> Tuple:
    return tuple(tuple(a.shape) if torch is not None and isinstance(a, torch.Tensor) else None
                 for a in args)


@dataclass
class Fault:
    id: str
    defect_class: str
    category: str
    description: str
    #: factor family whose variation is needed to trigger it
    trigger_factor: str
    #: oracle expected to detect it
    oracle: str
    #: needs a warm sequence (cold-only probing cannot see it)
    needs_sequence: bool = False
    apply: Optional[Callable] = None
    #: which built-in programs the fault is meaningful on (empty = any)
    programs: List[str] = field(default_factory=list)

    def as_dict(self) -> Dict[str, Any]:
        return {"id": self.id, "defect_class": self.defect_class, "category": self.category,
                "description": self.description, "trigger_factor": self.trigger_factor,
                "oracle": self.oracle, "needs_sequence": self.needs_sequence, "programs": self.programs}


class FaultyCompiler(Compiler):
    """A real compiled artifact with one injected defect layered on top."""

    def __init__(self, fault: Fault, backend: str = "eager"):
        self.fault = fault
        self.inner = TorchCompiler(backend)
        self.name = f"faulty[{fault.id}]@{backend}"
        self.state: Dict[str, Any] = {}

    def compile(self, fn: Callable, ctx: Optional[Context] = None) -> Callable:
        compiled = self.inner.compile(fn, ctx)
        state = self.state
        state.clear()
        state["ctx"] = ctx
        fault = self.fault

        def wrapped(*args):
            return fault.apply(fn, compiled, args, state, self.inner)  # type: ignore[misc]

        return wrapped

    def reset(self) -> None:
        self.inner.reset()
        self.state.clear()

    def compiles_since_reset(self) -> int:
        return self.inner.compiles_since_reset()

    def mark(self) -> None:
        self.inner.mark()


# --------------------------------------------------------------------------
# code-generation semantic deviation
# --------------------------------------------------------------------------

def _f_codegen_value(fn, compiled, args, state, inner):
    return _perturb(compiled(*args), 1.0)


def _make_boundary(k: int, dim: int = 0):
    def f(fn, compiled, args, state, inner):
        t = _first_tensor(args)
        out = compiled(*args)
        if t is not None and t.dim() > dim and t.shape[dim] == k:
            return _perturb(out, 1.0)
        return out
    return f


def _make_mod(k: int, residue: int = 1):
    def f(fn, compiled, args, state, inner):
        t = _first_tensor(args)
        out = compiled(*args)
        if t is not None and t.dim() > 0 and t.shape[0] % k == residue:
            return _perturb(out, 1.0)
        return out
    return f


def _f_noncontig(fn, compiled, args, state, inner):
    out = compiled(*args)
    if any(torch is not None and isinstance(a, torch.Tensor) and not a.is_contiguous() for a in args):
        return _perturb(out, 1.0)
    return out


def _f_drop_mutation(fn, compiled, args, state, inner):
    # in-place writes land on private copies: the caller never sees them
    priv = tuple(a.detach().clone().requires_grad_(a.requires_grad)
                 if torch is not None and isinstance(a, torch.Tensor) else a for a in args)
    return compiled(*priv)


def _f_alias_to_copy(fn, compiled, args, state, inner):
    return _clone(compiled(*args))


def _f_swallow_exception(fn, compiled, args, state, inner):
    try:
        return compiled(*args)
    except Exception:
        t = _first_tensor(args)
        return torch.zeros_like(t) if t is not None else None


class _DoubleGrad(torch.autograd.Function if torch is not None else object):  # type: ignore[misc]
    @staticmethod
    def forward(ctx, x):
        return x.view_as(x)

    @staticmethod
    def backward(ctx, g):
        return g * 2.0


def _f_wrong_gradient(fn, compiled, args, state, inner):
    out = compiled(*args)
    if torch is not None and isinstance(out, torch.Tensor) and out.requires_grad:
        return _DoubleGrad.apply(out)
    if isinstance(out, tuple):
        return tuple(_DoubleGrad.apply(o) if isinstance(o, torch.Tensor) and o.requires_grad else o
                     for o in out)
    return out


def _f_fp16_precision(fn, compiled, args, state, inner):
    """Codegen computes float16 inputs in float16 with an extra rounding step."""
    t = _first_tensor(args)
    out = compiled(*args)
    if t is not None and t.dtype == torch.float16 and isinstance(out, torch.Tensor):
        return (out.float() * 1.02).half()
    return out


def _f_dynamic_flag(fn, compiled, args, state, inner):
    ctx = state.get("ctx")
    out = compiled(*args)
    if ctx is not None and isinstance(ctx.get("compile"), dict) and ctx.get("compile").get("dynamic"):
        return _perturb(out, 1.0)
    return out


def _make_scalar_boundary(arg_i: int, value: Any):
    def f(fn, compiled, args, state, inner):
        out = compiled(*args)
        if len(args) > arg_i and args[arg_i] == value:
            return _perturb(out, 1.0)
        return out
    return f


# --------------------------------------------------------------------------
# JIT specialization inconsistency (under-specialization -> stale reuse)
# --------------------------------------------------------------------------

def _f_under_specialize_dtype(fn, compiled, args, state, inner):
    """Artifact keyed on shape only: a dtype switch reuses the old artifact."""
    key = _shape_key(args)
    dt = _dtype_of(args)
    art = state.setdefault("artifacts", {})
    if key in art and dt is not None and art[key] != dt:
        old = art[key]
        out = compiled(*_cast_tree(args, old))       # same guards as before: no recompile
        return _cast_tree(out, dt)
    if dt is not None:
        art[key] = dt
    return compiled(*args)


def _make_under_specialize_scalar(arg_i: int):
    """Artifact ignores a Python scalar argument: the first value sticks."""
    def f(fn, compiled, args, state, inner):
        key = _shape_key(args)
        art = state.setdefault("scalars", {})
        if len(args) <= arg_i:
            return compiled(*args)
        if key in art and art[key] != args[arg_i]:
            a2 = list(args)
            a2[arg_i] = art[key]
            return compiled(*a2)
        art[key] = args[arg_i]
        return compiled(*args)
    return f


def _f_under_specialize_layout(fn, compiled, args, state, inner):
    """Artifact ignores contiguity: a non-contiguous input is read as if contiguous."""
    key = _shape_key(args)
    lay = tuple(bool(a.is_contiguous()) if torch is not None and isinstance(a, torch.Tensor) else None
                for a in args)
    art = state.setdefault("layouts", {})
    if key in art and art[key] != lay:
        # reinterpret the storage with contiguous strides - the classic stride bug
        bad = []
        for a in args:
            if torch is not None and isinstance(a, torch.Tensor) and not a.is_contiguous():
                try:
                    st = a.untyped_storage()
                    n = a.numel()
                    flat = torch.empty(0, dtype=a.dtype, device=a.device).set_(st, a.storage_offset(), (n,))
                    bad.append(flat.reshape(a.shape))
                    continue
                except Exception:
                    pass
            bad.append(a)
        return compiled(*bad)
    art[key] = lay
    return compiled(*args)


def _f_under_specialize_grad(fn, compiled, args, state, inner):
    """Artifact ignores requires_grad: outputs of a grad call are detached."""
    key = _shape_key(args)
    rg = tuple(bool(a.requires_grad) if torch is not None and isinstance(a, torch.Tensor) else None
               for a in args)
    art = state.setdefault("grad", {})
    if key in art and art[key] != rg:
        det = tuple(a.detach() if torch is not None and isinstance(a, torch.Tensor) else a for a in args)
        out = compiled(*det)
        return out
    art[key] = rg
    return compiled(*args)


# --------------------------------------------------------------------------
# cache consistency failure (invalidation / cross-context leakage)
# --------------------------------------------------------------------------

def _f_stale_on_return(fn, compiled, args, state, inner):
    """A -> B -> A: returning to A keeps computing with B's dtype."""
    key = _shape_key(args)
    dt = _dtype_of(args)
    hist = state.setdefault("history", {})
    seen = hist.setdefault(key, [])
    if dt is not None and dt in seen and seen[-1] != dt:
        # we have been at dt before and switched away: the cache answers with the latest
        out = compiled(*_cast_tree(args, seen[-1]))
        return _cast_tree(out, dt)
    if dt is not None and (not seen or seen[-1] != dt):
        seen.append(dt)
    return compiled(*args)


def _f_result_cache_by_shape(fn, compiled, args, state, inner):
    """The artifact memoises its *output* by input shape (a real class of bug)."""
    key = _shape_key(args)
    memo = state.setdefault("memo", {})
    if key in memo:
        return _clone(memo[key])
    out = compiled(*args)
    memo[key] = _clone(out)
    return out


# --------------------------------------------------------------------------
# registry
# --------------------------------------------------------------------------

FAULTS: List[Fault] = [
    Fault("codegen_value", CLASS_CODEGEN, CAT_CODEGEN,
          "generated code adds 1.0 to every float output", "any", "value",
          apply=_f_codegen_value),
    Fault("codegen_boundary_32", CLASS_CODEGEN, CAT_SHAPE,
          "wrong output exactly when x.shape[0] == 32 (tile boundary)", "shape", "value",
          apply=_make_boundary(32), programs=["shape_boundary"]),
    Fault("codegen_boundary_31", CLASS_CODEGEN, CAT_SHAPE,
          "wrong output exactly when x.shape[0] == 31 (boundary - 1)", "shape", "value",
          apply=_make_boundary(31), programs=["shape_boundary"]),
    Fault("codegen_mod16_tail", CLASS_CODEGEN, CAT_SHAPE,
          "wrong output when x.shape[0] % 16 == 1 (vectorization tail)", "shape", "value",
          apply=_make_mod(16, 1), programs=["mod_tiling", "shape_boundary"]),
    Fault("codegen_index_last", CLASS_CODEGEN, CAT_SHAPE,
          "wrong output when x.shape[0] == 1 (index n-1 collapses to 0)", "shape", "value",
          apply=_make_boundary(1), programs=["index_chain"]),
    Fault("codegen_noncontig", CLASS_CODEGEN, CAT_CODEGEN,
          "wrong output for non-contiguous inputs (stride handling)", "layout", "value",
          apply=_f_noncontig),
    Fault("codegen_fp16_rounding", CLASS_CODEGEN, CAT_DTYPE,
          "float16 path applies an extra 2% scaling", "dtype", "value",
          apply=_f_fp16_precision),
    Fault("codegen_dynamic_flag", CLASS_CODEGEN, CAT_CODEGEN,
          "wrong output when compiled with dynamic=True", "compile_flag", "value",
          apply=_f_dynamic_flag),
    Fault("codegen_scalar_edge", CLASS_CODEGEN, CAT_CONTROL,
          "wrong output when the scalar argument equals the predicate constant", "scalar", "value",
          apply=_make_scalar_boundary(1, 4), programs=["scalar_compare", "loop_bound"]),
    Fault("functionalize_drop_mutation", CLASS_CODEGEN, CAT_ALIAS,
          "in-place writes land on private copies: caller's tensors unchanged", "any", "mutation",
          apply=_f_drop_mutation,
          programs=["view_inplace", "noncontig_copy", "overlapping_views", "conditional_mutation",
                    "chunk_inplace"]),
    Fault("functionalize_alias_to_copy", CLASS_CODEGEN, CAT_ALIAS,
          "returned views are materialised as copies", "any", "alias",
          apply=_f_alias_to_copy,
          programs=["alias_returned", "view_inplace", "overlapping_views", "chunk_inplace"]),
    Fault("capture_swallow_exception", CLASS_CODEGEN, CAT_CONTROL,
          "compiled code returns zeros where eager raises", "shape", "exception",
          apply=_f_swallow_exception, programs=["exception_path"]),
    Fault("autograd_wrong_gradient", CLASS_CODEGEN, CAT_CODEGEN,
          "backward produces 2x the correct input gradient", "requires_grad", "gradient",
          apply=_f_wrong_gradient, programs=["requires_grad_switch", "dtype_read", "python_flag_semantic"]),
    Fault("underspec_dtype", CLASS_SPECIALIZATION, CAT_SPECIALIZATION,
          "artifact keyed on shape only: dtype switch reuses the old artifact", "dtype", "value",
          needs_sequence=True, apply=_f_under_specialize_dtype),
    Fault("underspec_scalar", CLASS_SPECIALIZATION, CAT_SPECIALIZATION,
          "artifact ignores a Python scalar/flag argument", "flag", "value",
          needs_sequence=True, apply=_make_under_specialize_scalar(1),
          programs=["python_flag_semantic", "scalar_compare", "string_mode", "loop_bound"]),
    Fault("underspec_layout", CLASS_SPECIALIZATION, CAT_SPECIALIZATION,
          "artifact ignores contiguity: strided input read as contiguous", "layout", "value",
          needs_sequence=True, apply=_f_under_specialize_layout),
    Fault("underspec_requires_grad", CLASS_SPECIALIZATION, CAT_SPECIALIZATION,
          "artifact ignores requires_grad: no graph is built on the warm call", "requires_grad",
          "gradient", needs_sequence=True, apply=_f_under_specialize_grad,
          programs=["requires_grad_switch"]),
    Fault("cache_stale_on_return", CLASS_CACHE, CAT_CACHE,
          "A -> B -> A keeps B's dtype specialisation under A's guard", "dtype", "value",
          needs_sequence=True, apply=_f_stale_on_return),
    Fault("cache_result_memo", CLASS_CACHE, CAT_CACHE,
          "artifact memoises outputs by input shape across calls", "any", "value",
          needs_sequence=True, apply=_f_result_cache_by_shape),
]

FAULT_BY_ID: Dict[str, Fault] = {f.id: f for f in FAULTS}


def get_fault(fid: str) -> Fault:
    return FAULT_BY_ID[fid]


def faulty_compiler(fid: Optional[str], backend: str = "eager") -> Compiler:
    if fid is None:
        return TorchCompiler(backend)
    return FaultyCompiler(get_fault(fid), backend)
