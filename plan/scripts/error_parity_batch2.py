"""8.1 batch 2: "validation lost" programs (umbrella pytorch/pytorch#197554).

Each case is a tiny program `case(C)` where `C` wraps the function to be compiled (identity for the eager run).
Eager must raise; a compiled run that returns instead is a lost validation.  Unlike batch 1 (OpInfo error_inputs)
these cases cover validation classes OpInfo has few samples for: shape contracts of the index/scatter family,
dtype contracts, `out=` contracts, in-place type promotion, writes through overlapping memory, autograd's
in-place rules, and saved-tensor modification detected at backward time.

    python scripts/error_parity_batch2.py --isolate [--backends eager,aot_eager,inductor] [--dynamic]
    python scripts/error_parity_batch2.py --report
"""
import argparse
import json
import os
import sys

sys.path.insert(0, os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
from tcc.compat import ensure_msvc_env  # noqa: E402

ensure_msvc_env()
import torch  # noqa: E402
import torch.nn.functional as F  # noqa: E402

from tcc.sweep_common import exc_info, jsonl_append, run_isolated, tensors_of  # noqa: E402

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
torch._dynamo.config.recompile_limit = 10 ** 4
CASES = {}


def case(fn):
    CASES[fn.__name__] = fn
    return fn


def T(*s, dtype=torch.float32):
    return torch.arange(1, 1 + int(torch.tensor(s).prod()), dtype=torch.float32).reshape(*s).to(dtype) / 7


def I(*v, dtype=torch.int64):
    return torch.tensor(list(v), dtype=dtype)


# ---- shape contracts of the index / scatter family ---------------------------------------------------------------
@case
def index_add_source_shape(C): return C(lambda x, i, s: torch.index_add(x, 0, i, s))(torch.zeros(3, 2), I(0, 2), T(2))
@case
def index_add_source_rows(C): return C(lambda x, i, s: torch.index_add(x, 0, i, s))(torch.zeros(4, 3), I(0, 2), T(3, 3))
@case
def index_add_index_2d(C): return C(lambda x, i, s: torch.index_add(x, 0, i, s))(torch.zeros(4, 3), I(0, 1).reshape(1, 2), T(2, 3))
@case
def index_copy_source_rows(C): return C(lambda x, i, s: torch.index_copy(x, 0, i, s))(torch.zeros(4, 3), I(0, 2), T(3, 3))
@case
def index_fill_index_2d(C): return C(lambda x, i: torch.index_fill(x, 0, i, 1.0))(torch.zeros(4, 3), I(0, 1).reshape(1, 2))
@case
def index_select_index_2d(C): return C(lambda x, i: torch.index_select(x, 0, i))(T(4, 3), I(0, 1, 2, 3).reshape(2, 2))
@case
def index_select_negative(C): return C(lambda x, i: torch.index_select(x, 1, i))(T(4, 5), I(-1, 0))
@case
def index_add_negative(C): return C(lambda x, i, s: torch.index_add(x, 0, i, s))(torch.zeros(4, 3), I(-1), T(1, 3))
@case
def index_copy_negative(C): return C(lambda x, i, s: torch.index_copy(x, 0, i, s))(torch.zeros(4, 3), I(-1), T(1, 3))
@case
def index_fill_negative(C): return C(lambda x, i: torch.index_fill(x, 0, i, 1.0))(torch.zeros(4, 3), I(-5))
@case
def scatter_src_smaller(C): return C(lambda x, i, s: torch.scatter(x, 0, i, s))(torch.zeros(3, 5), I(0, 1, 2, 0, 1).reshape(1, 5), T(1, 3))
@case
def scatter_index_wider(C): return C(lambda x, i, s: torch.scatter(x, 0, i, s))(torch.zeros(3, 2), I(0, 1, 2).reshape(1, 3), T(1, 3))
@case
def scatter_add_src_smaller(C): return C(lambda x, i, s: torch.scatter_add(x, 0, i, s))(torch.zeros(3, 5), I(0, 1, 2, 0, 1).reshape(1, 5), T(1, 3))
@case
def scatter_reduce_src_smaller(C): return C(lambda x, i, s: torch.scatter_reduce(x, 0, i, s, "sum"))(torch.zeros(3, 5), I(0, 1, 2, 0, 1).reshape(1, 5), T(1, 3))
@case
def scatter_rank_mismatch(C): return C(lambda x, i, s: torch.scatter(x, 0, i, s))(torch.zeros(3, 5), I(0, 1), T(2))
@case
def gather_index_wider(C): return C(lambda x, i: torch.gather(x, 1, i))(T(2, 2), torch.zeros(3, 2, dtype=torch.int64))
@case
def gather_rank_mismatch(C): return C(lambda x, i: torch.gather(x, 0, i))(T(2, 2), I(0, 1))
@case
def gather_index_int32(C): return C(lambda x, i: torch.gather(x, 1, i))(T(2, 2), torch.zeros(2, 2, dtype=torch.int32))
@case
def take_along_dim_rank(C): return C(lambda x, i: torch.take_along_dim(x, i, 1))(T(2, 3), I(0, 1))
@case
def masked_scatter_short_source(C): return C(lambda x, m, s: torch.masked_scatter(x, m, s))(torch.zeros(5), torch.ones(5, dtype=torch.bool), T(2))
@case
def masked_fill_mask_shape(C): return C(lambda x, m: torch.masked_fill(x, m, 1.0))(torch.zeros(4, 3), torch.ones(5, dtype=torch.bool))
@case
def masked_fill_mask_dtype(C): return C(lambda x, m: torch.masked_fill(x, m, 1.0))(torch.zeros(4), torch.ones(4))
@case
def masked_select_mask_dtype(C): return C(lambda x, m: torch.masked_select(x, m))(T(4), torch.ones(4))
@case
def where_cond_dtype(C): return C(lambda c, a, b: torch.where(c, a, b))(torch.ones(4), T(4), T(4))
@case
def put_source_short(C): return C(lambda x, i, s: torch.index_put(x, (i,), s))(torch.zeros(6), I(0, 1, 2), T(2))
@case
def index_put_values_shape(C): return C(lambda x, i, v: torch.index_put(x, (i,), v))(torch.zeros(4, 5), I(0, 1), T(3, 5))
@case
def setitem_values_shape(C):
    def f(x, v):
        x = x.clone(); x[1:3] = v; return x
    return C(f)(torch.zeros(4, 5), T(3, 5))
@case
def setitem_bool_mask_count(C):
    def f(x, m, v):
        x = x.clone(); x[m] = v; return x
    return C(f)(torch.zeros(5), I(1, 1, 1, 0, 0).bool(), T(2))
@case
def embedding_float_indices(C): return C(lambda i, w: F.embedding(i, w))(T(3), T(10, 3))
@case
def embedding_bag_offsets_nonzero(C): return C(lambda i, w, o: F.embedding_bag(i, w, o))(I(0, 1, 2), T(10, 3), I(1))
@case
def one_hot_float(C): return C(lambda x: F.one_hot(x, 5))(T(3))
@case
def nll_loss_float_target(C): return C(lambda x, t: F.nll_loss(x, t))(T(3, 5).log_softmax(1), T(3))
@case
def nll_loss_weight_shape(C): return C(lambda x, t, w: F.nll_loss(x, t, weight=w))(T(3, 5).log_softmax(1), I(0, 1, 2), T(4))
@case
def cross_entropy_batch_mismatch(C): return C(lambda x, t: F.cross_entropy(x, t))(T(3, 5), I(0, 1))
@case
def bce_target_shape(C): return C(lambda x, t: F.binary_cross_entropy(x, t))(torch.full((3, 2), 0.5), torch.full((3,), 0.5))
@case
def bce_out_of_range(C): return C(lambda x, t: F.binary_cross_entropy(x, t))(torch.tensor([1.5, 0.2]), torch.tensor([1.0, 0.0]))
@case
def mse_no_broadcast(C): return C(lambda x, t: F.mse_loss(x, t))(T(3, 2), T(3, 5))
@case
def repeat_interleave_output_size(C): return C(lambda x, r: torch.repeat_interleave(x, r, output_size=9))(T(3), I(1, 2, 3))
@case
def bincount_float(C): return C(lambda x: torch.bincount(x))(T(3))
@case
def bincount_2d(C): return C(lambda x: torch.bincount(x))(I(0, 1, 2, 3).reshape(2, 2))
@case
def bucketize_2d_boundaries(C): return C(lambda x, b: torch.bucketize(x, b))(T(3), T(2, 3))
@case
def searchsorted_shape(C): return C(lambda s, v: torch.searchsorted(s, v))(T(2, 3), T(3, 4))
@case
def histc_min_gt_max(C): return C(lambda x: torch.histc(x, bins=4, min=2.0, max=1.0))(T(8))
@case
def pixel_shuffle_indivisible(C): return C(lambda x: F.pixel_shuffle(x, 2))(T(1, 6, 2, 2))
@case
def pixel_unshuffle_indivisible(C): return C(lambda x: F.pixel_unshuffle(x, 2))(T(1, 1, 3, 3))
@case
def unflatten_bad_sizes(C): return C(lambda x: x.unflatten(0, (2, 5)))(T(6))
@case
def fold_bad_shape(C): return C(lambda x: F.fold(x, (4, 4), (2, 2)))(T(1, 5, 9))
@case
def unfold_kernel_too_big(C): return C(lambda x: F.unfold(x, (5, 5)))(T(1, 1, 3, 3))
@case
def avg_pool_pad_too_big(C): return C(lambda x: F.avg_pool2d(x, 2, padding=2))(T(1, 1, 4, 4))
@case
def max_pool_pad_too_big(C): return C(lambda x: F.max_pool2d(x, 2, padding=2))(T(1, 1, 4, 4))
@case
def adaptive_pool_zero_output(C): return C(lambda x: F.adaptive_avg_pool2d(x, (0, 2)))(T(1, 1, 4, 4))
@case
def adaptive_max_pool_empty_input(C): return C(lambda x: F.adaptive_max_pool2d(x, 2))(torch.empty(1, 1, 0, 4))
@case
def conv_kernel_bigger_than_input(C): return C(lambda x, w: F.conv2d(x, w))(T(1, 1, 2, 2), T(1, 1, 3, 3))
@case
def conv_zero_stride(C): return C(lambda x, w: F.conv2d(x, w, stride=0))(T(1, 1, 4, 4), T(1, 1, 3, 3))
@case
def conv_bias_shape(C): return C(lambda x, w, b: F.conv2d(x, w, b))(T(1, 1, 4, 4), T(2, 1, 3, 3), T(3))
@case
def linear_bias_shape(C): return C(lambda x, w, b: F.linear(x, w, b))(T(2, 3), T(4, 3), T(5))
@case
def layer_norm_weight_shape(C): return C(lambda x, w: F.layer_norm(x, (3,), w))(T(2, 3), T(4))
@case
def group_norm_weight_shape(C): return C(lambda x, w: F.group_norm(x, 2, w))(T(2, 4, 3), T(3))
@case
def batch_norm_running_shape(C): return C(lambda x, m, v: F.batch_norm(x, m, v))(T(2, 3), torch.zeros(4), torch.ones(4))
@case
def instance_norm_running_shape(C): return C(lambda x, m, v: F.instance_norm(x, m, v))(T(2, 3, 4), torch.zeros(5), torch.ones(5))
@case
def prelu_weight_shape(C): return C(lambda x, w: F.prelu(x, w))(T(2, 3, 4), T(5))
@case
def interpolate_negative_scale(C): return C(lambda x: F.interpolate(x, scale_factor=-1.0))(T(1, 1, 4))
@case
def grid_sample_batch_mismatch(C): return C(lambda x, g: F.grid_sample(x, g, align_corners=False))(T(2, 1, 3, 3), torch.zeros(1, 2, 2, 2))
@case
def pad_circular_too_big(C): return C(lambda x: F.pad(x, (4, 4), mode="circular"))(T(1, 1, 3))
@case
def pad_replicate_empty(C): return C(lambda x: F.pad(x, (1, 1), mode="replicate"))(torch.empty(1, 1, 0))
@case
def diag_embed_same_dims(C): return C(lambda x: torch.diag_embed(x, dim1=0, dim2=0))(T(3))
@case
def tril_1d(C): return C(lambda x: torch.tril(x))(T(3))
@case
def cross_dim_size(C): return C(lambda a, b: torch.linalg.cross(a, b))(T(2, 4), T(2, 4))
@case
def dot_size_mismatch(C): return C(lambda a, b: torch.dot(a, b))(T(3), T(4))
@case
def mv_size_mismatch(C): return C(lambda a, b: torch.mv(a, b))(T(3, 4), T(3))
@case
def addmm_bias_shape(C): return C(lambda b, x, y: torch.addmm(b, x, y))(T(5), T(2, 3), T(3, 4))
@case
def baddbmm_batch_mismatch(C): return C(lambda b, x, y: torch.baddbmm(b, x, y))(T(2, 2, 4), T(2, 2, 3), T(3, 3, 4))
@case
def einsum_size_mismatch(C): return C(lambda a, b: torch.einsum("ij,jk->ik", a, b))(T(2, 3), T(4, 5))
@case
def tensordot_mismatch(C): return C(lambda a, b: torch.tensordot(a, b, dims=1))(T(2, 3), T(4, 5))
@case
def kron_ok_control(C): return C(lambda a, b: torch.kron(a, b))(T(2), T(3))   # valid control: nobody may raise
# ---- dtype contracts ------------------------------------------------------------------------------------------
@case
def mm_dtype_mismatch(C): return C(lambda a, b: torch.mm(a, b))(T(2, 3), T(3, 2, dtype=torch.float64))
@case
def bmm_dtype_mismatch(C): return C(lambda a, b: torch.bmm(a, b))(T(1, 2, 3), T(1, 3, 2, dtype=torch.float64))
@case
def dot_dtype_mismatch(C): return C(lambda a, b: torch.dot(a, b))(T(3), T(3, dtype=torch.float64))
@case
def addmm_dtype_mismatch(C): return C(lambda b, x, y: torch.addmm(b, x, y))(T(2, 4, dtype=torch.float64), T(2, 3), T(3, 4))
@case
def linear_dtype_mismatch(C): return C(lambda x, w: F.linear(x, w))(T(2, 3), T(4, 3, dtype=torch.float64))
@case
def conv_dtype_mismatch(C): return C(lambda x, w: F.conv2d(x, w))(T(1, 1, 4, 4), T(1, 1, 3, 3, dtype=torch.float64))
@case
def layer_norm_dtype_mismatch(C): return C(lambda x, w: F.layer_norm(x, (3,), w))(T(2, 3), T(3, dtype=torch.float64))
@case
def mm_int_float(C): return C(lambda a, b: torch.mm(a, b))(torch.ones(2, 3, dtype=torch.int64), T(3, 2))
@case
def softmax_int(C): return C(lambda x: torch.softmax(x, 0))(I(1, 2, 3))
@case
def mean_int(C): return C(lambda x: torch.mean(x))(I(1, 2, 3))
@case
def std_int(C): return C(lambda x: torch.std(x))(I(1, 2, 3))
@case
def sqrt_bool_out_int(C): return C(lambda x: torch.sqrt(x, out=torch.empty(3, dtype=torch.int64)))(T(3))
@case
def add_out_int(C): return C(lambda a, b: torch.add(a, b, out=torch.empty(3, dtype=torch.int64)))(T(3), T(3))
@case
def mul_out_bool(C): return C(lambda a, b: torch.mul(a, b, out=torch.empty(3, dtype=torch.bool)))(T(3), T(3))
@case
def sum_out_int(C): return C(lambda a: torch.sum(a, 0, out=torch.empty((), dtype=torch.int64)))(T(3))
@case
def mm_out_dtype(C): return C(lambda a, b: torch.mm(a, b, out=torch.empty(2, 2, dtype=torch.float64)))(T(2, 3), T(3, 2))
@case
def cat_out_dtype(C): return C(lambda a, b: torch.cat((a, b), out=torch.empty(6, dtype=torch.int32)))(T(3), T(3))
@case
def complex_out_dtype(C): return C(lambda a, b: torch.complex(a, b, out=torch.empty(3, dtype=torch.complex128)))(T(3), T(3))
@case
def complex_mixed_inputs(C): return C(lambda a, b: torch.complex(a, b))(T(3), T(3, dtype=torch.float64))
@case
def polar_mixed_inputs(C): return C(lambda a, b: torch.polar(a, b))(T(3), T(3, dtype=torch.float64))
@case
def view_as_complex_odd(C): return C(lambda a: torch.view_as_complex(a))(T(3, 3))
@case
def lerp_dtype_mismatch(C): return C(lambda a, b, w: torch.lerp(a, b, w))(T(3), T(3), T(3, dtype=torch.float64))
@case
def clamp_tensor_none(C): return C(lambda a: torch.clamp(a))(T(3))
@case
def arange_float_to_int_overflow(C): return C(lambda: torch.arange(0, 3e9, 1e9, dtype=torch.int8))()
# ---- in-place type promotion and overlapping memory ----------------------------------------------------------------
@case
def inplace_add_float_scalar_to_int(C): return C(lambda x: x.add_(1.5))(I(1, 2, 3))
@case
def inplace_mul_float_tensor_to_int(C): return C(lambda x, y: x.mul_(y))(I(1, 2, 3), T(3))
@case
def inplace_div_int(C): return C(lambda x: x.div_(2))(I(1, 2, 3))
@case
def inplace_add_complex_to_float(C): return C(lambda x: x.add_(1j))(T(3))
@case
def inplace_bool_sub(C): return C(lambda x: x.sub_(x))(I(1, 0, 1).bool())
@case
def inplace_broadcast_grow(C): return C(lambda x, y: x.add_(y))(T(3), T(2, 3))
@case
def inplace_on_expanded(C): return C(lambda x: x.add_(1))(torch.zeros(1, 3).expand(4, 3))
@case
def inplace_copy_to_expanded(C): return C(lambda x, y: x.copy_(y))(torch.zeros(1, 3).expand(4, 3), T(4, 3))
@case
def out_is_expanded(C): return C(lambda a, b, o: torch.add(a, b, out=o))(T(4, 3), T(4, 3), torch.zeros(1, 3).expand(4, 3))
@case
def out_overlaps_input_take(C): return C(lambda x: torch.take(x, I(1, 2), out=x[:2]))(torch.arange(3))
@case
def out_overlaps_input_cumsum(C): return C(lambda x: torch.cumsum(x[1:], 0, out=x[:-1]))(T(6))
@case
def out_overlaps_input_flip(C): return C(lambda x: torch.index_select(x, 0, I(3, 2, 1, 0), out=x))(T(4))
@case
def inplace_index_add_on_expanded(C): return C(lambda x, i, s: x.index_add_(0, i, s))(torch.zeros(1, 3).expand(4, 3), I(0, 1), T(2, 3))
@case
def inplace_masked_fill_on_expanded(C): return C(lambda x, m: x.masked_fill_(m, 1.0))(torch.zeros(1, 3).expand(4, 3), torch.ones(4, 3, dtype=torch.bool))
@case
def inplace_scatter_on_expanded(C): return C(lambda x, i, s: x.scatter_(0, i, s))(torch.zeros(1, 3).expand(4, 3), torch.zeros(1, 3, dtype=torch.int64), T(1, 3))
@case
def inplace_as_strided_overlap(C): return C(lambda x: torch.as_strided(x, (3, 3), (1, 1)).add_(1))(torch.zeros(5))
@case
def resize_shared_storage(C): return C(lambda x: x[:2].resize_(10))(T(4))
# ---- autograd's in-place rules ---------------------------------------------------------------------------------------
@case
def leaf_inplace(C):
    x = T(3).requires_grad_()
    return C(lambda x: x.add_(1))(x)
@case
def leaf_view_inplace(C):
    x = T(3).requires_grad_()
    return C(lambda x: x[:2].mul_(2))(x)
@case
def saved_output_modified(C):
    x = T(3).requires_grad_()
    def fwd(x):
        y = x.exp(); y.mul_(2); return y
    C(fwd)(x).sum().backward()
    return x.grad
@case
def saved_input_modified(C):
    x = T(3).requires_grad_()
    def fwd(x):
        a = x * 1; y = a.pow(2); a.add_(1); return y
    C(fwd)(x).sum().backward()
    return x.grad
@case
def saved_modified_after_return(C):
    x = T(3).requires_grad_()
    out = C(lambda x: x.sigmoid())(x)
    out.data.mul_(0)                        # .data bypasses the version counter in eager as well: control
    out.sum().backward()
    return x.grad
@case
def saved_modified_after_return_tracked(C):
    x = T(3).requires_grad_()
    out = C(lambda x: x.sigmoid())(x)
    with torch.no_grad():
        out.mul_(0)                         # eager: backward raises (saved output was modified)
    out.sum().backward()
    return x.grad
@case
def saved_weight_modified_before_backward(C):
    w = T(3, 3).requires_grad_()
    x = T(2, 3)
    out = C(lambda x, w: (x @ w).tanh())(x, w)
    with torch.no_grad():
        w.add_(1)                           # eager: mm saved w -> backward raises
    out.sum().backward()
    return w.grad
@case
def saved_input_modified_before_backward(C):
    w = T(3, 3).requires_grad_()
    x = T(2, 3)
    out = C(lambda x, w: x @ w)(x, w)
    x.add_(1)                               # eager: x is saved for dW -> backward raises
    out.sum().backward()
    return w.grad
@case
def multi_view_inplace(C):
    x = T(4).requires_grad_()
    def fwd(x):
        a, b = (x * 1).unbind(0)[:2]; a.add_(1); return a + b
    out = C(fwd)(x)
    out.backward()
    return x.grad
@case
def detach_inplace_then_backward(C):
    x = T(3).requires_grad_()
    def fwd(x):
        y = x.exp(); y.detach().zero_(); return y
    C(fwd)(x).sum().backward()
    return x.grad
@case
def backward_twice(C):
    x = T(3).requires_grad_()
    out = C(lambda x: x.exp().sum())(x)
    out.backward(); out.backward()
    return x.grad
@case
def grad_of_non_scalar(C):
    x = T(3).requires_grad_()
    C(lambda x: x.exp())(x).backward()
    return x.grad
@case
def integer_requires_grad(C): return C(lambda x: x.requires_grad_())(I(1, 2, 3))


def classify(e_exc, c_exc):
    if e_exc is None:
        return "ok_valid" if c_exc is None else "COMPILE_RAISES"
    if c_exc is None:
        return "SILENT"
    return "ok" if isinstance(c_exc, type(e_exc)) or type(e_exc).__name__ in str(c_exc) or str(e_exc)[:50] in str(c_exc) else "OTHER_TYPE"


def run(name, backend, dynamic):
    fn = CASES[name]
    torch._dynamo.reset()
    torch.manual_seed(0)
    C = (lambda f: f) if backend is None else (lambda f: torch.compile(f, backend=backend, dynamic=dynamic))
    try:
        v = fn(C)
        ts = tensors_of(v)
        return None, [f"{tuple(t.shape)} {t.dtype} {t.detach().flatten()[:8].tolist()}" for t in ts][:2]
    except Exception as e:  # noqa: BLE001
        return e, None


def report(path):
    rows = [json.loads(l) for l in open(path, encoding="utf-8") if l.strip()]
    from collections import Counter
    print(len(rows), dict(Counter(r["verdict"] for r in rows)))
    for r in rows:
        if r["verdict"] in ("ok", "ok_valid"):
            continue
        print(f"\n[{r['verdict']}] {r['op']}")
        print("   eager    :", r.get("eager_ref"), r.get("eager_value") or "")
        for b, x in r.get("backends", {}).items():
            print(f"   {b:9s}: {x['verdict']:14s} {x.get('exc') or x.get('value')}"[:330])
        if r["verdict"] == "CRASH":
            print("   ", r.get("returncode"), r.get("tail", "")[-300:])


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--only", default=None)
    ap.add_argument("--backends", default="eager,aot_eager,inductor")
    ap.add_argument("--dynamic", action="store_true")
    ap.add_argument("--isolate", action="store_true")
    ap.add_argument("--report", action="store_true")
    ap.add_argument("--out-jsonl", default=os.path.join(ROOT, "results", "error_parity", "batch2.jsonl"))
    a = ap.parse_args()
    os.makedirs(os.path.dirname(a.out_jsonl), exist_ok=True)
    if a.report:
        return report(a.out_jsonl)
    names = a.only.split(",") if a.only else list(CASES)
    if a.isolate:
        extra = ["--backends", a.backends] + (["--dynamic"] if a.dynamic else [])
        run_isolated(os.path.abspath(__file__), names, extra, a.out_jsonl, timeout=900)
        return
    for n in names:
        e_exc, e_val = run(n, None, None)
        rec = {"op": n, "eager_ref": exc_info(e_exc)[:300] if e_exc else "returned", "eager_value": e_val, "backends": {}}
        worst = "ok" if e_exc else "ok_valid"
        for b in a.backends.split(","):
            c_exc, c_val = run(n, b, a.dynamic or None)
            v = classify(e_exc, c_exc)
            rec["backends"][b] = {"verdict": v, "exc": exc_info(c_exc)[:300] if c_exc else None, "value": c_val}
            if v == "SILENT" or (v in ("COMPILE_RAISES", "OTHER_TYPE") and worst != "SILENT"):
                worst = v
            if v == "ok_valid" and e_val != c_val and worst == "ok_valid":
                worst = "VALUE_DIFF"
        rec["verdict"] = worst
        jsonl_append(a.out_jsonl, rec)
        if worst not in ("ok", "ok_valid"):
            print(f"  !! {n}: {worst} | " + " ".join(f"{b}={x['verdict']}" for b, x in rec["backends"].items()), flush=True)


if __name__ == "__main__":
    main()
