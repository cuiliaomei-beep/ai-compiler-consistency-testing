"""Programs under test and the semantic contexts they execute under.

A :class:`Program` is a Python function that reaches a compilation boundary,
plus a deterministic way to build inputs for a :class:`Context`. A context is
one point in the semantic-factor space of plan section 3.1: tensor metadata
(shape / dtype / device / stride / contiguity / requires_grad), Python values
(int / float / bool / None / enum / str / containers) and compile options.

The contract every ``make_inputs`` must honour: **return freshly allocated
tensors on every call**. The mutation oracle (O4) compares the caller's inputs
after the call, so handing out the same tensor twice makes the second
execution observe the first one's in-place writes.
"""
from __future__ import annotations

import inspect
from dataclasses import dataclass, field
from typing import Any, Callable, Dict, List, Optional, Sequence, Tuple

from .compat import torch

EXPECT_CONSISTENT = "consistent"
EXPECT_DIVERGE = "selfcheck_diverge"
EXPECT_SAME = "selfcheck_same"


@dataclass(frozen=True)
class Context:
    """One point in the semantic factor space."""

    name: str
    factors: Dict[str, Any] = field(default_factory=dict)
    #: does the obligation behind this context ask for a warm-cache sequence?
    warm: bool = True
    #: the obligation factor that produced it (traceability, plan section 10)
    origin: str = ""

    def get(self, key: str, default: Any = None) -> Any:
        return self.factors.get(key, default)

    def differing_factors(self, other: "Context") -> List[str]:
        keys = set(self.factors) | set(other.factors)
        return sorted(k for k in keys if self.factors.get(k) != other.factors.get(k))

    def with_factor(self, key: str, value: Any, name: Optional[str] = None) -> "Context":
        f = dict(self.factors)
        f[key] = value
        return Context(name or f"{self.name}+{key}={_short(value)}", f, self.warm, self.origin)

    def as_dict(self) -> Dict[str, Any]:
        return {"name": self.name, "factors": _jsonable(self.factors), "warm": self.warm,
                "origin": self.origin}


def _short(v: Any) -> str:
    s = repr(v) if not isinstance(v, str) else v
    return s.replace(" ", "")[:24]


def _jsonable(o: Any) -> Any:
    if isinstance(o, dict):
        return {str(k): _jsonable(v) for k, v in o.items()}
    if isinstance(o, (list, tuple)):
        return [_jsonable(v) for v in o]
    if isinstance(o, (int, float, str, bool)) or o is None:
        return o
    return repr(o)


@dataclass
class Program:
    """A function under test at one compilation site."""

    name: str
    fn: Callable
    make_inputs: Callable[[Context], Tuple[Any, ...]]
    base_context: Context = field(default_factory=lambda: Context("base", {}))
    tags: List[str] = field(default_factory=list)
    notes: str = ""
    expect: str = EXPECT_CONSISTENT
    #: source text of ``fn`` (needed when the function was built by ``exec``)
    source: Optional[str] = None
    #: the project the program was taken from (for reports / dedup)
    project: str = "pytorch/pytorch"
    #: skip the float64 reference (ops with no fp64 kernel)
    skip_fp64: bool = False
    #: run the gradient oracle O6 (needs float inputs; costs a backward)
    check_grad: bool = True
    #: extra kwargs passed to torch.compile (compile flags are factors too)
    compile_options: Dict[str, Any] = field(default_factory=dict)
    #: for site-discovered programs: file and line of the compilation site
    site: Optional[Dict[str, Any]] = None
    #: contexts explicitly listed by the author; the generator adds derived ones
    contexts: List[Context] = field(default_factory=list)
    #: called before every execution to restore mutable state the function owns
    #: (an nn.Module's buffers such as BatchNorm running statistics); without it
    #: two eager runs legitimately differ and no oracle can compare anything
    reset: Optional[Callable[[], None]] = None

    def get_source(self) -> Optional[str]:
        if self.source:
            return self.source
        try:
            return inspect.getsource(self.fn)
        except (OSError, TypeError):
            return None

    def param_names(self) -> List[str]:
        try:
            return list(inspect.signature(self.fn).parameters)
        except (TypeError, ValueError):
            return []

    def as_dict(self) -> Dict[str, Any]:
        return {
            "name": self.name, "tags": list(self.tags), "notes": self.notes,
            "expect": self.expect, "project": self.project,
            "base_context": self.base_context.as_dict(),
            "contexts": [c.as_dict() for c in self.contexts],
            "compile_options": dict(self.compile_options), "site": self.site,
        }


# --------------------------------------------------------------------------
# generic factor application (plan 12: change exactly one factor)
# --------------------------------------------------------------------------

_DTYPES = ("float16", "bfloat16", "float32", "float64", "int32", "int64", "bool")


def _cast(t: Any, dtype_name: str) -> Any:
    if torch is None or not isinstance(t, torch.Tensor) or not t.is_floating_point():
        return t
    try:
        out = t.detach().to(getattr(torch, dtype_name))
        if t.requires_grad and out.is_floating_point():
            out.requires_grad_(True)
        return out
    except Exception:
        return t


def make_noncontiguous(t: Any) -> Any:
    """Same values, non-unit innermost stride (layout differs, data does not)."""
    if torch is None or not isinstance(t, torch.Tensor) or t.dim() == 0:
        return t
    if not t.is_contiguous():
        return t
    try:
        shape = list(t.shape)
        shape[-1] *= 2
        big = torch.empty(shape, dtype=t.dtype, device=t.device)
        view = big[..., ::2]
        view.copy_(t.detach())
        if t.requires_grad:
            view.requires_grad_(True)
        return view
    except Exception:
        return t


def resize_dim(t: Any, dim: int, n: int) -> Any:
    """Resize one dimension to ``n`` (slice when shrinking, tile when growing)."""
    if torch is None or not isinstance(t, torch.Tensor) or t.dim() == 0:
        return t
    if not (-t.dim() <= dim < t.dim()):
        return t
    dim = dim % t.dim()
    cur = t.shape[dim]
    if cur == n or n <= 0:
        return t
    try:
        rg = t.requires_grad
        src = t.detach()
        if n < cur:
            out = src.narrow(dim, 0, n).clone()
        else:
            reps = [1] * t.dim()
            reps[dim] = (n + cur - 1) // cur
            out = src.repeat(*reps).narrow(dim, 0, n).clone()
        if rg:
            out.requires_grad_(True)
        return out
    except Exception:
        return t


def transpose_layout(t: Any) -> Any:
    """A transposed (non-contiguous) tensor with the same shape and values."""
    if torch is None or not isinstance(t, torch.Tensor) or t.dim() < 2:
        return t
    try:
        rg = t.requires_grad
        out = t.detach().transpose(-1, -2).contiguous().transpose(-1, -2)
        if rg:
            out.requires_grad_(True)
        return out
    except Exception:
        return t


def apply_factors(args: Tuple[Any, ...], ctx: Context) -> Tuple[Any, ...]:
    """Apply the *structured* factors of a context to an argument tuple.

    Supported keys (each acts on one argument index so the change is
    attributable):

    - ``resize``:        {"arg": i, "dim": d, "value": n}
    - ``substitute``:    {"arg": i, "value": v}      Python scalar / flag / None
    - ``requires_grad``: {"arg": i, "value": bool}
    - ``dtype``:         "float16" | ...  (applied to every float tensor)
    - ``layout``:        "noncontig" | "transposed" | "contiguous"
    - ``device``:        "cpu" | "cuda"
    """
    out = list(args)
    rs = ctx.get("resize")
    if isinstance(rs, dict):
        i = rs.get("arg", 0)
        if 0 <= i < len(out) and isinstance(rs.get("value"), int):
            out[i] = resize_dim(out[i], rs.get("dim", 0), rs["value"])
    sub = ctx.get("substitute")
    if isinstance(sub, dict):
        i = sub.get("arg", 0)
        if 0 <= i < len(out):
            out[i] = sub.get("value")
    rg = ctx.get("requires_grad")
    if isinstance(rg, dict):
        i = rg.get("arg", 0)
        if 0 <= i < len(out) and torch is not None and isinstance(out[i], torch.Tensor) \
                and out[i].is_floating_point():
            t = out[i].detach().clone()
            t.requires_grad_(bool(rg.get("value")))
            out[i] = t
    rk = ctx.get("rank")
    if isinstance(rk, dict):
        i, delta = rk.get("arg", 0), int(rk.get("delta", 1))
        if 0 <= i < len(out) and torch is not None and isinstance(out[i], torch.Tensor):
            t = out[i]
            rgf = t.requires_grad
            try:
                if delta > 0:
                    t2 = t.detach().unsqueeze(0).clone()
                elif t.dim() > 0:
                    t2 = t.detach().select(0, 0).clone()
                else:
                    t2 = t.detach().clone()
                if rgf:
                    t2.requires_grad_(True)
                out[i] = t2
            except Exception:
                pass
    dt = ctx.get("dtype")
    if isinstance(dt, str) and dt in _DTYPES:
        target = getattr(torch, dt) if torch is not None else None
        out = [target if (torch is not None and isinstance(a, torch.dtype)
                          and target is not None and a.is_floating_point)
               else _cast(a, dt) for a in out]
    layout = ctx.get("layout")
    if layout == "noncontig":
        out = [make_noncontiguous(a) for a in out]
    elif layout == "transposed":
        out = [transpose_layout(a) for a in out]
    dev = ctx.get("device")
    if isinstance(dev, str) and torch is not None:
        conv = []
        for a in out:
            if isinstance(a, torch.Tensor):
                try:
                    rgf = a.requires_grad
                    b = a.detach().to(dev)
                    if rgf:
                        b.requires_grad_(True)
                    conv.append(b)
                except Exception:
                    conv.append(a)
            else:
                conv.append(a)
        out = conv
    return tuple(out)


def single_factor_pairs(contexts: Sequence[Context]) -> List[Tuple[Context, Context]]:
    """Ordered pairs that differ in exactly one factor (plan 12 / 14)."""
    pairs: List[Tuple[Context, Context]] = []
    for a in contexts:
        for b in contexts:
            if a is b or a.name == b.name:
                continue
            if len(a.differing_factors(b)) == 1:
                pairs.append((a, b))
    return pairs


# --------------------------------------------------------------------------
# registry
# --------------------------------------------------------------------------

_REGISTRY: Dict[str, Program] = {}


def register(p: Program) -> Program:
    if p.name in _REGISTRY:
        raise ValueError(f"duplicate program name: {p.name}")
    _REGISTRY[p.name] = p
    return p


def get(name: str) -> Program:
    return _REGISTRY[name]


def all_programs(tag: Optional[str] = None, expect: Optional[str] = None) -> List[Program]:
    ps = list(_REGISTRY.values())
    if tag:
        ps = [p for p in ps if tag in p.tags]
    if expect:
        ps = [p for p in ps if p.expect == expect]
    return ps


def clear() -> None:
    _REGISTRY.clear()
