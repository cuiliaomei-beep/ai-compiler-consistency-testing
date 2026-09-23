"""Seed cases.

These are starting points, not the corpus. They exercise one factor family
each, so that a divergence is attributable, and they are written the way the
plan wants generated cases written: *only one factor differs between any two
contexts of the same case.*

The alias/in-place cases (``view_inplace``, ``noncontig_copy``,
``overlapping_views``) are the ones that matter most. Published measurements
show existing tools already cover every in-place operator yet still miss most
of these bugs, because what they cannot synthesise is the surrounding
view/alias structure — which is exactly what these encode.
"""
from __future__ import annotations

from typing import Any, Tuple

from .case import Case, Context, register
from .torchcompat import torch

DEVICE = "cpu"


def _dev() -> str:
    if torch is not None and torch.cuda.is_available():
        return "cuda"
    return DEVICE


def _dtype(name: str):
    return {
        "float16": torch.float16,
        "float32": torch.float32,
        "bfloat16": torch.bfloat16,
        "float64": torch.float64,
    }[name]


def _randn(*shape, dtype: str = "float32", device: str = None, requires_grad: bool = False):
    t = torch.randn(*shape, dtype=_dtype(dtype), device=device or _dev())
    if requires_grad:
        t.requires_grad_(True)
    return t


# --------------------------------------------------------------------------
# 1. shape boundary  ->  the classic tile/vectorization edge
# --------------------------------------------------------------------------

def _f_shape_boundary(x):
    if x.shape[0] >= 32:
        return (x * 2.0).sum(dim=0)
    return (x + 1.0).sum(dim=0)


def _in_shape_boundary(ctx: Context) -> Tuple[Any, ...]:
    n = ctx.get("rows", 32)
    return (_randn(n, 16),)


register(Case(
    name="shape_boundary",
    fn=_f_shape_boundary,
    make_inputs=_in_shape_boundary,
    contexts=[
        Context("rows31", {"rows": 31}),
        Context("rows32", {"rows": 32}),
        Context("rows33", {"rows": 33}),
    ],
    tags=["shape", "control_flow"],
    notes="Branch on a shape predicate; 31/32/33 straddle the boundary the "
          "static analysis would derive from `x.shape[0] >= 32`.",
))


# --------------------------------------------------------------------------
# 2. dtype specialization  ->  the canonical warm-cache probe
# --------------------------------------------------------------------------

def _f_dtype_reduce(x):
    return (x * x).sum(dim=-1) / (x.abs().mean(dim=-1) + 1e-6)


def _in_dtype(ctx: Context) -> Tuple[Any, ...]:
    return (_randn(64, 128, dtype=ctx.get("dtype", "float32")),)


register(Case(
    name="dtype_specialization",
    fn=_f_dtype_reduce,
    make_inputs=_in_dtype,
    contexts=[
        Context("fp32", {"dtype": "float32"}),
        Context("fp16", {"dtype": "float16"}),
        Context("bf16", {"dtype": "bfloat16"}),
    ],
    tags=["dtype", "cache"],
    notes="Same shape, only dtype changes. The warm probe compiles under one "
          "dtype and then executes under another without a reset.",
))


# --------------------------------------------------------------------------
# 3. view + in-place  ->  FACT-1 from the plan
# --------------------------------------------------------------------------

def _f_view_inplace(x):
    y = x.view(-1)
    y[0] = y[0] + 1.0
    return x


def _in_view(ctx: Context) -> Tuple[Any, ...]:
    return (_randn(8, 8, dtype=ctx.get("dtype", "float32")),)


register(Case(
    name="view_inplace",
    fn=_f_view_inplace,
    make_inputs=_in_view,
    contexts=[
        Context("fp32", {"dtype": "float32"}),
        Context("fp16", {"dtype": "float16"}),
    ],
    tags=["alias", "mutation"],
    notes="FACT-1: writing through a view must change the caller's tensor. "
          "The mutation and alias oracles both apply.",
))


# --------------------------------------------------------------------------
# 4. non-contiguous strided write  ->  FACT-2
# --------------------------------------------------------------------------

def _f_noncontig(x, w):
    z = x[:, ::2]
    z.copy_(w)
    return x


def _in_noncontig(ctx: Context) -> Tuple[Any, ...]:
    n = ctx.get("cols", 16)
    dt = ctx.get("dtype", "float32")
    return (_randn(8, n, dtype=dt), _randn(8, n // 2, dtype=dt))


register(Case(
    name="noncontig_copy",
    fn=_f_noncontig,
    make_inputs=_in_noncontig,
    contexts=[
        Context("cols16", {"cols": 16}),
        Context("cols32", {"cols": 32}),
    ],
    tags=["alias", "mutation", "layout"],
    notes="FACT-2: a strided sub-view is written; the untouched elements of x "
          "must be preserved exactly.",
))


# --------------------------------------------------------------------------
# 5. overlapping views  ->  the structure existing tools do not synthesise
# --------------------------------------------------------------------------

def _f_overlapping(x):
    a = x[:6]
    b = x[4:]
    a.mul_(2.0)
    b.add_(1.0)
    return x, a, b


def _in_overlapping(ctx: Context) -> Tuple[Any, ...]:
    return (_randn(10, dtype=ctx.get("dtype", "float32")),)


register(Case(
    name="overlapping_views",
    fn=_f_overlapping,
    make_inputs=_in_overlapping,
    contexts=[
        Context("fp32", {"dtype": "float32"}),
        Context("fp16", {"dtype": "float16"}),
    ],
    tags=["alias", "mutation"],
    notes="Two views over overlapping ranges, written in order. Write ordering "
          "and the alias relation among (x, a, b) must both survive.",
))


# --------------------------------------------------------------------------
# 6. python flag  ->  a non-tensor semantic factor
# --------------------------------------------------------------------------

def _f_flag(x, fast: bool):
    if fast:
        return x.sum(dim=0) * 0.5
    return (x * 0.5).sum(dim=0)


def _in_flag(ctx: Context) -> Tuple[Any, ...]:
    return (_randn(32, 32), bool(ctx.get("fast", True)))


register(Case(
    name="python_flag",
    fn=_f_flag,
    make_inputs=_in_flag,
    contexts=[
        Context("fast", {"fast": True}),
        Context("slow", {"fast": False}),
    ],
    tags=["scalar", "control_flow", "cache"],
    notes="A Python bool selects between two mathematically equal paths. A "
          "warm switch that does not recompile is the interesting outcome.",
))


# --------------------------------------------------------------------------
# 7. requires_grad  ->  changes the traced graph, not the maths
# --------------------------------------------------------------------------

def _f_grad(x):
    y = (x * 3.0).relu()
    return y.sum()


def _in_grad(ctx: Context) -> Tuple[Any, ...]:
    return (_randn(32, 32, requires_grad=bool(ctx.get("requires_grad", False))),)


register(Case(
    name="requires_grad_switch",
    fn=_f_grad,
    make_inputs=_in_grad,
    contexts=[
        Context("nograd", {"requires_grad": False}),
        Context("grad", {"requires_grad": True}),
    ],
    tags=["autograd", "cache"],
    notes="requires_grad changes what AOTAutograd builds while leaving the "
          "forward value unchanged.",
))
