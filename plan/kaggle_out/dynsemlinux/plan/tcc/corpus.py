"""Built-in programs: one per semantic-factor family of plan section 3.1.

These are the seeds the pipeline analyses, mutates and executes. Each is
small enough that a divergence is attributable, and each reads exactly the
factor family its name says, so the static analysis has something concrete to
find. They double as the substrate of the injected-fault benchmark.
"""
from __future__ import annotations

from typing import Any, Tuple

from .compat import default_device, torch
from .program import Context, Program, register

DEV = default_device()

SCALE = 2.0          # module-level state read by ``global_state``
_CALLS = {"n": 0}    # module-level state written by ``global_write``


def _r(*shape, dtype=None, requires_grad: bool = False):
    t = torch.randn(*shape, dtype=dtype or torch.float32, device=DEV)
    if requires_grad:
        t.requires_grad_(True)
    return t


# 1 shape boundary ---------------------------------------------------------
def shape_boundary(x):
    if x.shape[0] >= 32:
        return (x * 2.0).sum(dim=0)
    return (x + 1.0).sum(dim=0)


# 2 modulo tiling ----------------------------------------------------------
def mod_tiling(x):
    n = x.shape[0]
    if n % 16 == 0:
        return x.reshape(n // 16, 16, -1).sum(dim=1)
    pad = 16 - n % 16
    y = torch.cat([x, x[:pad]], dim=0)
    return y.reshape(-1, 16, x.shape[1]).sum(dim=1)


# 3 shape -> index chain ---------------------------------------------------
def index_chain(x):
    n = x.shape[0]
    i = n - 1
    y = x[i]
    return y * 2.0 + x[0]


# 4 dtype read -------------------------------------------------------------
def dtype_read(x):
    if x.dtype == torch.float16:
        return (x.float() * x.float()).sum(dim=-1).half()
    return (x * x).sum(dim=-1)


# 5 python flag (mathematically equal branches) ----------------------------
def python_flag(x, fast):
    if fast:
        return x.sum(dim=0) * 0.5
    return (x * 0.5).sum(dim=0)


# 6 python flag (semantically different branches) --------------------------
def python_flag_semantic(x, use_relu):
    if use_relu:
        return x.relu().sum(dim=-1)
    return x.tanh().sum(dim=-1)


# 7 scalar compared against a constant ------------------------------------
def scalar_compare(x, n):
    if n > 4:
        return x[:n].sum(dim=0)
    return x.sum(dim=0) * n


# 8 None check -------------------------------------------------------------
def none_check(x, bias=None):
    if bias is None:
        return x * 2.0
    return x * 2.0 + bias


# 9 view + in-place --------------------------------------------------------
def view_inplace(x):
    y = x.view(-1)
    y[0] = y[0] + 1.0
    return x


# 10 strided sub-view written ---------------------------------------------
def noncontig_copy(x, w):
    z = x[:, ::2]
    z.copy_(w)
    return x


# 11 overlapping views ----------------------------------------------------
def overlapping_views(x):
    a = x[:6]
    b = x[4:]
    a.mul_(2.0)
    b.add_(1.0)
    return x, a, b


# 12 returned alias -------------------------------------------------------
def alias_returned(x):
    y = x.transpose(0, 1)
    return y


# 13 conditional mutation -------------------------------------------------
def conditional_mutation(x):
    if x.shape[0] > 8:
        x.add_(1.0)
    return x


# 14 chunk + in-place on one chunk ----------------------------------------
def chunk_inplace(x):
    a, b = x.chunk(2, dim=0)
    a.mul_(3.0)
    return b + a.sum()


# 15 requires_grad --------------------------------------------------------
def requires_grad_switch(x):
    y = (x * 3.0).relu()
    return y.sum()


# 16 global state read ----------------------------------------------------
def global_state(x):
    return x * SCALE


# 17 closure variable -----------------------------------------------------
def make_closure(k: float):
    def closure_fn(x):
        return x * k + 1.0
    return closure_fn


closure_fn = make_closure(1.5)


# 18 reshape dimension from an argument -----------------------------------
def reshape_dim(x, k):
    return x.reshape(k, -1).sum(dim=1)


# 19 loop bound -----------------------------------------------------------
def loop_bound(x, n):
    for _ in range(n):
        x = x * 1.5 + 1.0
    return x


# 20 exception path -------------------------------------------------------
def exception_path(x):
    if x.shape[0] < 4:
        raise ValueError("need at least 4 rows")
    return x.sum(dim=0)


# 21 container length -----------------------------------------------------
def container_len(xs):
    if len(xs) > 2:
        return xs[0] + xs[2]
    return xs[0] * 2.0


# 22 string mode ----------------------------------------------------------
def string_mode(x, mode):
    if mode == "sum":
        return x.sum(dim=0)
    return x.mean(dim=0)


# 23 stride read ----------------------------------------------------------
def stride_read(x):
    if x.stride(0) == 1:
        return x.t().contiguous().sum(dim=0)
    return x.sum(dim=1)


# 24 mask index (data-dependent shape) ------------------------------------
def mask_index(x):
    m = x > 0
    return x[m].sum()


# 25 gather with shape-derived index --------------------------------------
def gather_shape(x):
    n = x.shape[0]
    idx = torch.arange(n - 1, device=x.device)
    return x.index_select(0, idx).sum(dim=0)


# 26 dtype-sensitive reduction (canonical warm-cache probe) ---------------
def dtype_reduce(x):
    return (x * x).sum(dim=-1) / (x.abs().mean(dim=-1) + 1e-6)


# 27 contiguity read ------------------------------------------------------
def contiguous_read(x):
    if x.is_contiguous():
        return x.view(-1).sum()
    return x.reshape(-1).sum()


# 29 flag AND shape predicate (experiment C: T/T, T/F, F/T, F/F) ----------
def flag_and_shape(x, flag):
    if flag and x.shape[0] > 32:
        return x[:32].sum(dim=0) * 2.0
    return x.sum(dim=0)


# 28 rank read ------------------------------------------------------------
def rank_read(x):
    if x.ndim == 2:
        return x.sum(dim=1)
    return x.sum()


# --------------------------------------------------------------------------
# registration
# --------------------------------------------------------------------------

def _p(name, fn, inputs, tags, notes="", **kw):
    register(Program(name=name, fn=fn, make_inputs=inputs, tags=tags, notes=notes, **kw))


_p("shape_boundary", shape_boundary, lambda c: (_r(32, 16),), ["shape", "control_flow"],
   "branch on x.shape[0] >= 32; the analysis must derive 31/32/33")
_p("mod_tiling", mod_tiling, lambda c: (_r(32, 8),), ["shape", "control_flow"],
   "n % 16 == 0 predicate; the analysis must derive 15/16/17/31/32/33")
_p("index_chain", index_chain, lambda c: (_r(8, 4),), ["shape", "index"],
   "x.shape[0] -> n -> i -> x[i]; probe sizes 1/2/3")
_p("dtype_read", dtype_read, lambda c: (_r(16, 8),), ["dtype", "control_flow"],
   "branch on x.dtype")
_p("python_flag", python_flag, lambda c: (_r(16, 8), True), ["scalar", "control_flow", "cache"],
   "bool flag selects mathematically equal paths")
_p("python_flag_semantic", python_flag_semantic, lambda c: (_r(16, 8), True),
   ["scalar", "control_flow", "cache"], "bool flag selects different maths")
_p("scalar_compare", scalar_compare, lambda c: (_r(16, 8), 6), ["scalar", "control_flow"],
   "int argument compared against 4")
_p("none_check", none_check, lambda c: (_r(8, 8), None), ["scalar", "control_flow"],
   "optional argument compared against None", check_grad=False)
_p("view_inplace", view_inplace, lambda c: (_r(8, 8),), ["alias", "mutation"],
   "FACT: write through a view must reach the caller's x", check_grad=False)
_p("noncontig_copy", noncontig_copy, lambda c: (_r(8, 16), _r(8, 8)), ["alias", "mutation", "layout"],
   "FACT: strided sub-view written; the rest of x preserved", check_grad=False)
_p("overlapping_views", overlapping_views, lambda c: (_r(10),), ["alias", "mutation"],
   "FACT: two overlapping views written in order", check_grad=False)
_p("alias_returned", alias_returned, lambda c: (_r(4, 6),), ["alias"],
   "FACT: the returned transpose must alias x")
_p("conditional_mutation", conditional_mutation, lambda c: (_r(16, 4),), ["alias", "mutation", "shape"],
   "in-place write only on one branch of a shape predicate", check_grad=False)
_p("chunk_inplace", chunk_inplace, lambda c: (_r(8, 4),), ["alias", "mutation"],
   "chunk() returns views; writing one must show through x", check_grad=False)
_p("requires_grad_switch", requires_grad_switch, lambda c: (_r(16, 8, requires_grad=True),),
   ["autograd", "cache"], "requires_grad changes what AOTAutograd builds")
_p("global_state", global_state, lambda c: (_r(8, 8),), ["state"], "reads module-level SCALE")
_p("closure_fn", closure_fn, lambda c: (_r(8, 8),), ["state", "closure"], "reads a closure variable",
   source="def closure_fn(x):\n    return x * k + 1.0\n")
_p("reshape_dim", reshape_dim, lambda c: (_r(8, 8), 4), ["shape", "scalar"],
   "reshape dimension comes from an argument", check_grad=False)
_p("loop_bound", loop_bound, lambda c: (_r(8, 4), 3), ["scalar", "control_flow"],
   "loop count comes from an argument")
_p("exception_path", exception_path, lambda c: (_r(8, 4),), ["shape", "exception"],
   "raises below a shape threshold")
_p("container_len", container_len, lambda c: ([_r(4, 4), _r(4, 4), _r(4, 4)],),
   ["container", "control_flow"], "branch on len(list)", check_grad=False)
_p("string_mode", string_mode, lambda c: (_r(8, 8), "sum"), ["string", "control_flow", "cache"],
   "string argument selects the reduction")
_p("stride_read", stride_read, lambda c: (_r(8, 8),), ["stride", "layout", "control_flow"],
   "branch on x.stride(0)")
_p("mask_index", mask_index, lambda c: (_r(8, 8),), ["index", "dynamic_shape"],
   "boolean-mask indexing; data-dependent output shape", check_grad=False)
_p("gather_shape", gather_shape, lambda c: (_r(8, 4),), ["shape", "index"],
   "index_select with a shape-derived index", check_grad=False)
_p("dtype_reduce", dtype_reduce, lambda c: (_r(64, 128),), ["dtype", "cache"],
   "the canonical dtype warm-cache probe")
_p("contiguous_read", contiguous_read, lambda c: (_r(8, 8),), ["layout", "control_flow"],
   "branch on is_contiguous()")
_p("rank_read", rank_read, lambda c: (_r(8, 8),), ["rank", "control_flow"], "branch on ndim")
_p("flag_and_shape", flag_and_shape, lambda c: (_r(32, 8), True), ["scalar", "shape", "control_flow"],
   "flag and x.shape[0] > 32: needs the 2x2 predicate table")
