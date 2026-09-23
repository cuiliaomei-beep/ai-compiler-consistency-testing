"""10.1 Rewrite preconditions: graph rewrites that look like no-ops (x + 0, pow(x, 0.5) -> sqrt, cast pairs, clone
removal, cat/split merging, addmm fusion, constant folding) are only valid under conditions the rewrite may not
check: NaN / inf / -0.0 operands, overflow in an intermediate dtype, aliasing with a later mutation, layout.

Every case is a tiny program run in eager and under torch.compile on inputs that violate the usual precondition.
Observations are compared exactly (NaN == NaN, -0.0 != +0.0, dtype, shape) except for a 1e-6 relative slack on
finite floats.  Alias cases return booleans such as `out.data_ptr() == x.data_ptr()` next to the mutated tensors.

    python scripts/rewrite_precondition_diff.py --isolate [--backends aot_eager,inductor]
    python scripts/rewrite_precondition_diff.py --report
"""
import argparse
import json
import math
import os
import sys

sys.path.insert(0, os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
from tcc.compat import ensure_msvc_env  # noqa: E402

ensure_msvc_env()
import torch  # noqa: E402
import torch.nn.functional as F  # noqa: E402

from tcc.sweep_common import jsonl_append, run_isolated  # noqa: E402

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
INF, NAN = float("inf"), float("nan")
torch._dynamo.config.recompile_limit = 10 ** 4


def E(dtype=torch.float32):
    return torch.tensor([0.0, -0.0, NAN, INF, -INF, 1.5, -2.5, 1e-40, -1e-40, 3e38, -3e38, 70000.0, 0.1, 16777217.0, 1e-30, 2.0], dtype=dtype)


def I(dtype=torch.int32):
    ii = torch.iinfo(dtype)
    return torch.tensor([0, 1, -1 if ii.min < 0 else 2, ii.max, ii.min, ii.max - 1, 7, 100], dtype=dtype)


def M(r=3, c=4):
    return (torch.arange(1.0, r * c + 1).reshape(r, c) / 7) - 0.8


# name -> (function, args builder).  All functions are pure unless listed in ALIAS below.
P = {
    # ---- arithmetic identities --------------------------------------------------------------------------------
    "add_zero": (lambda x: x + 0, lambda: (E(),)), "add_fzero": (lambda x: x + 0.0, lambda: (E(),)),
    "add_negzero": (lambda x: x + (-0.0), lambda: (E(),)), "radd_zero": (lambda x: 0 + x, lambda: (E(),)),
    "sub_zero": (lambda x: x - 0, lambda: (E(),)), "rsub_zero": (lambda x: 0 - x, lambda: (E(),)),
    "mul_one": (lambda x: x * 1, lambda: (E(),)), "mul_fone": (lambda x: x * 1.0, lambda: (I(),)),
    "div_one": (lambda x: x / 1, lambda: (I(),)), "fdiv_one": (lambda x: x // 1, lambda: (E(),)),
    "mul_zero": (lambda x: x * 0, lambda: (E(),)), "mul_negzero": (lambda x: x * -0.0, lambda: (E(),)),
    "sub_self": (lambda x: x - x, lambda: (E(),)), "div_self": (lambda x: x / x, lambda: (E(),)),
    "add_neg_self": (lambda x: x + (-x), lambda: (E(),)), "neg_neg": (lambda x: -(-x), lambda: (E(),)),
    "neg_neg_int": (lambda x: -(-x), lambda: (I(torch.int8),)), "abs_abs": (lambda x: x.abs().abs(), lambda: (I(torch.int8),)),
    "mul2_div2": (lambda x: (x * 2) / 2, lambda: (E(),)), "div2_mul2": (lambda x: (x / 2) * 2, lambda: (E(),)),
    "add1_sub1": (lambda x: (x + 1) - 1, lambda: (E(),)), "add_big_sub_big": (lambda x: (x + 1e20) - 1e20, lambda: (E(),)),
    "int_mul2_div2": (lambda x: (x * 2) // 2, lambda: (I(torch.int8),)), "int_add_sub": (lambda x: (x + 100) - 100, lambda: (I(torch.int8),)),
    "int_shl_shr": (lambda x: (x << 3) >> 3, lambda: (I(torch.int8),)), "uint_sub_add": (lambda x: (x - 10) + 10, lambda: (I(torch.uint8),)),
    "x_times_x": (lambda x: x * x, lambda: (E(),)), "square_sqrt": (lambda x: (x * x).sqrt(), lambda: (E(),)),
    "sqrt_square": (lambda x: x.sqrt() ** 2, lambda: (E(),)), "exp_log": (lambda x: x.log().exp(), lambda: (E(),)),
    "log_exp": (lambda x: x.exp().log(), lambda: (E(),)), "log1p_expm1": (lambda x: torch.log1p(torch.expm1(x)), lambda: (E(),)),
    "recip_recip": (lambda x: 1 / (1 / x), lambda: (E(),)), "div_by_recip": (lambda x: x / (1 / x), lambda: (E(),)),
    "max_self": (lambda x: torch.maximum(x, x), lambda: (E(),)), "where_true": (lambda x: torch.where(torch.ones_like(x, dtype=torch.bool), x, x * 0), lambda: (E(),)),
    "where_same": (lambda x: torch.where(x > 0, x, x), lambda: (E(),)), "clamp_inf": (lambda x: x.clamp(-INF, INF), lambda: (E(),)),
    "clamp_min_max_swapped": (lambda x: x.clamp(1.0, -1.0), lambda: (E(),)), "relu_relu": (lambda x: F.relu(F.relu(x)), lambda: (E(),)),
    "nan_to_num_twice": (lambda x: torch.nan_to_num(torch.nan_to_num(x)), lambda: (E(),)),
    # ---- pow family (strength reduction) ---------------------------------------------------------------------------
    "pow_half": (lambda x: x ** 0.5, lambda: (E(),)), "pow_neg_half": (lambda x: x ** -0.5, lambda: (E(),)),
    "pow_1": (lambda x: x ** 1, lambda: (E(),)), "pow_0": (lambda x: x ** 0, lambda: (E(),)), "pow_2": (lambda x: x ** 2, lambda: (E(),)),
    "pow_3": (lambda x: x ** 3, lambda: (E(),)), "pow_m1": (lambda x: x ** -1, lambda: (E(),)), "pow_m2": (lambda x: x ** -2, lambda: (E(),)),
    "pow_f2": (lambda x: x ** 2.0, lambda: (I(torch.int8),)), "pow_int2": (lambda x: x ** 2, lambda: (I(torch.int8),)),
    "pow_int3": (lambda x: x ** 3, lambda: (I(torch.int16),)), "pow_int0": (lambda x: x ** 0, lambda: (I(),)),
    "pow_tensor_half": (lambda x: torch.pow(x, torch.tensor(0.5)), lambda: (E(),)), "pow_third": (lambda x: x ** (1 / 3), lambda: (E(),)),
    "rpow_e": (lambda x: math.e ** x, lambda: (E(),)), "rpow_2": (lambda x: 2 ** x, lambda: (E(),)), "rpow_1": (lambda x: 1 ** x, lambda: (E(),)),
    "rpow_0": (lambda x: 0 ** x, lambda: (E(),)), "rpow_int_2": (lambda x: 2 ** x, lambda: (torch.tensor([0, 1, 5, 31, 32, 62, 63, 64, -1]),)),
    "rsqrt_vs": (lambda x: 1 / x.sqrt(), lambda: (E(),)), "sqrt_recip": (lambda x: (1 / x).sqrt(), lambda: (E(),)),
    "float_power_half": (lambda x: torch.float_power(x, 0.5), lambda: (E(),)),
    # ---- cast pairs -------------------------------------------------------------------------------------------------------
    "cast_same": (lambda x: x.to(torch.float32), lambda: (E(),)), "cast_f64_back": (lambda x: x.double().float(), lambda: (E(),)),
    "cast_f64_narrow": (lambda x: x.float().double(), lambda: (torch.tensor([1e39, 1e-46, 0.1, 16777217.0, -1e39], dtype=torch.float64),)),
    "cast_int_back": (lambda x: x.to(torch.int32).to(torch.float32), lambda: (torch.tensor([0.7, -0.7, 2.5, -2.5, 1e5, 16777217.0]),)),
    "cast_i8_back": (lambda x: x.to(torch.int8).to(torch.int32), lambda: (torch.tensor([1, 127, 128, 255, 256, -129, 1000], dtype=torch.int32),)),
    "cast_u8_back": (lambda x: x.to(torch.uint8).to(torch.int32), lambda: (torch.tensor([1, 255, 256, -1, 1000], dtype=torch.int32),)),
    "cast_bool_back": (lambda x: x.bool().float(), lambda: (E(),)), "cast_bool_int": (lambda x: x.bool().to(torch.int32), lambda: (I(),)),
    "cast_f16_chain": (lambda x: x.half().bfloat16().float(), lambda: (E(),)), "cast_long_double": (lambda x: x.long().double().long(), lambda: (torch.tensor([2 ** 53 + 1, 2 ** 62 + 1, -(2 ** 53) - 1]),)),
    "cast_then_op": (lambda x: (x.half() * 2).float(), lambda: (E(),)), "op_then_cast_back": (lambda x: (x.double() + 1e-9).float(), lambda: (E(),)),
    "int_div_cast": (lambda x: (x / 2).to(torch.int32), lambda: (I(),)), "trunc_cast": (lambda x: x.trunc().to(torch.int64), lambda: (torch.tensor([0.7, -0.7, 2.5, 1e5]),)),
    "type_as_self": (lambda x: x.type_as(x) + x.to(x.dtype), lambda: (E(),)),
    # ---- shape no-ops -----------------------------------------------------------------------------------------------------------
    "view_view": (lambda x: x.view(4, 3).view(2, 6).view(3, 4), lambda: (M(),)), "reshape_same": (lambda x: x.reshape(3, 4) * 1, lambda: (M(),)),
    "t_t": (lambda x: x.t().t() + 0, lambda: (M(),)), "permute_back": (lambda x: x.permute(1, 0).permute(1, 0).contiguous(), lambda: (M(),)),
    "expand_same": (lambda x: x.expand(3, 4) * 2, lambda: (M(),)), "repeat_one": (lambda x: x.repeat(1, 1), lambda: (M(),)),
    "slice_full": (lambda x: x[:, :] * 1, lambda: (M(),)), "slice_full_step": (lambda x: x[::1, 0:4:1], lambda: (M(),)),
    "flip_flip": (lambda x: x.flip(0).flip(0), lambda: (M(),)), "roll_zero": (lambda x: x.roll(0, 1), lambda: (M(),)),
    "roll_full": (lambda x: x.roll(4, 1), lambda: (M(),)), "cat_single": (lambda x: torch.cat([x]), lambda: (M(),)),
    "cat_empty": (lambda x: torch.cat([x, x[:0]]), lambda: (M(),)), "stack_unbind": (lambda x: torch.stack(x.unbind(0)), lambda: (M(),)),
    "split_cat": (lambda x: torch.cat(x.split(1, 1), 1), lambda: (M(),)), "split_cat_other_dim": (lambda x: torch.cat(x.split(2, 1), 0), lambda: (M(),)),
    "split_cat_reordered": (lambda x: torch.cat(x.split(2, 1)[::-1], 1), lambda: (M(),)), "chunk_stack": (lambda x: torch.stack(x.chunk(2, 1), 0), lambda: (M(),)),
    "slices_cat_overlap": (lambda x: torch.cat([x[:, 0:3], x[:, 1:4]], 1), lambda: (M(),)), "slices_cat_adjacent": (lambda x: torch.cat([x[:, 0:2], x[:, 2:4]], 1), lambda: (M(),)),
    "slices_cat_gap": (lambda x: torch.cat([x[:, 0:1], x[:, 2:4]], 1), lambda: (M(),)), "unbind_stack_dim": (lambda x: torch.stack(x.unbind(1), 0), lambda: (M(),)),
    "index_select_all": (lambda x: x.index_select(1, torch.arange(4)), lambda: (M(),)), "gather_identity": (lambda x: x.gather(1, torch.arange(4).expand(3, 4)), lambda: (M(),)),
    "squeeze_unsqueeze": (lambda x: x.unsqueeze(0).squeeze(0).unsqueeze(-1).squeeze(-1), lambda: (M(),)), "pad_zero": (lambda x: F.pad(x, (0, 0, 0, 0)), lambda: (M(),)),
    "pad_neg_then_pos": (lambda x: F.pad(F.pad(x, (-1, -1)), (1, 1)), lambda: (M(),)), "narrow_full": (lambda x: x.narrow(1, 0, 4), lambda: (M(),)),
    # ---- matmul fusions ---------------------------------------------------------------------------------------------------------------
    "addmm_fuse": (lambda b, x, w: b + x @ w, lambda: (M(1, 3)[0], M(2, 4), M(4, 3))), "addmm_fuse_nan_bias": (lambda b, x, w: b + x @ w, lambda: (torch.tensor([NAN, INF, -0.0]), M(2, 4), M(4, 3))),
    "addmm_beta0_nan": (lambda b, x, w: torch.addmm(b, x, w, beta=0), lambda: (torch.full((2, 3), NAN), M(2, 4), M(4, 3))),
    "addmm_alpha0_inf": (lambda b, x, w: torch.addmm(b, x, w, alpha=0), lambda: (M(2, 3), torch.full((2, 4), INF), M(4, 3))),
    "baddbmm_beta0_nan": (lambda b, x, w: torch.baddbmm(b, x, w, beta=0), lambda: (torch.full((2, 2, 3), NAN), M(4, 4).reshape(2, 2, 4), M(8, 3).reshape(2, 4, 3))),
    "mm_times_zero": (lambda x, w: (x @ w) * 0, lambda: (torch.full((2, 4), INF), M(4, 3))), "mm_odd_dims": (lambda x, w: x @ w, lambda: (M(5, 7), M(7, 3))),
    "mm_zero_dim": (lambda x, w: x @ w, lambda: (torch.zeros(2, 0), torch.zeros(0, 3))), "bmm_batch1": (lambda x, w: torch.bmm(x, w), lambda: (M(2, 4).unsqueeze(0), M(4, 3).unsqueeze(0))),
    "linear_3d_bias": (lambda x, w, b: F.linear(x, w, b), lambda: (M(6, 4).reshape(2, 3, 4), M(5, 4), M(1, 5)[0])), "mm_int": (lambda x, w: x @ w, lambda: (torch.arange(6).reshape(2, 3), torch.arange(6).reshape(3, 2))),
    "mm_transposed_views": (lambda x, w: x.t() @ w.t(), lambda: (M(4, 2), M(3, 4))), "matmul_vec_vec": (lambda a, b: a @ b, lambda: (M(1, 5)[0], M(1, 5)[0])),
    "mul_sum_as_dot": (lambda a, b: (a * b).sum(-1), lambda: (torch.tensor([[1e20, 1.0, -1e20]]), torch.tensor([[1.0, 1.0, 1.0]]))),
    # ---- reductions --------------------------------------------------------------------------------------------------------------------
    "sum_sum": (lambda x: x.sum(0).sum(0), lambda: (torch.tensor([[1e20, 1.0], [-1e20, 1.0]]),)), "mean_as_sum": (lambda x: x.mean(), lambda: (E()[5:7],)),
    "sum_softmax": (lambda x: torch.softmax(x, -1).sum(-1), lambda: (M(),)), "softmax_nan_row": (lambda x: torch.softmax(x, -1), lambda: (torch.tensor([[-INF, -INF], [INF, 1.0], [NAN, 1.0]]),)),
    "log_softmax_via_log": (lambda x: torch.softmax(x, -1).log(), lambda: (torch.tensor([[0.0, 1000.0], [-1000.0, 0.0]]),)), "logsumexp_inf": (lambda x: torch.logsumexp(x, -1), lambda: (torch.tensor([[-INF, -INF], [INF, INF], [INF, -INF]]),)),
    "sum_of_cat": (lambda x: torch.cat([x, x * 0]).sum(), lambda: (E(),)), "mean_empty": (lambda x: x[:0].mean(), lambda: (E(),)), "max_single": (lambda x: x[2:3].max(), lambda: (E(),)),
    "amax_nan": (lambda x: x.amax(), lambda: (E(),)), "argmax_ties": (lambda x: x.argmax(), lambda: (torch.tensor([1.0, 3.0, 3.0, 3.0, 2.0]),)), "argmax_nan": (lambda x: x.argmax(), lambda: (E(),)),
    "any_gt": (lambda x: (x > 0).any(), lambda: (E(),)), "all_eq_self": (lambda x: (x == x).all(), lambda: (E(),)), "sum_bool": (lambda x: (x == x).sum(), lambda: (E(),)),
    "var_single": (lambda x: x[:1].var(), lambda: (E(),)), "std_const": (lambda x: torch.full_like(x, 3.0).std(), lambda: (E(),)), "prod_with_zero_inf": (lambda x: x.prod(), lambda: (torch.tensor([0.0, INF, 2.0]),)),
    "cumsum_then_diff": (lambda x: torch.diff(torch.cumsum(x, 0)), lambda: (torch.tensor([1e20, 1.0, -1e20, 1.0]),)), "norm_via_sqrt": (lambda x: (x * x).sum().sqrt(), lambda: (torch.tensor([3e20, 4e20]),)),
    # ---- constant folding ----------------------------------------------------------------------------------------------------------------
    "const_int32_overflow": (lambda x: torch.full((2,), 2147483647, dtype=torch.int32) + 1 + x, lambda: (torch.zeros(2, dtype=torch.int32),)),
    "const_uint8_wrap": (lambda x: torch.full((2,), 250, dtype=torch.uint8) + 10 + x, lambda: (torch.zeros(2, dtype=torch.uint8),)),
    "const_int8_mul": (lambda x: torch.full((2,), 100, dtype=torch.int8) * 3 + x, lambda: (torch.zeros(2, dtype=torch.int8),)),
    "const_half_overflow": (lambda x: torch.full((2,), 60000.0, dtype=torch.float16) * 2 + x, lambda: (torch.zeros(2, dtype=torch.float16),)),
    "const_div_zero": (lambda x: torch.ones(2) / torch.zeros(2) + x, lambda: (torch.zeros(2),)), "const_zero_div_zero": (lambda x: torch.zeros(2) / torch.zeros(2) + x, lambda: (torch.zeros(2),)),
    "const_arange_float": (lambda x: torch.arange(0, 1, 0.1) + x[:10], lambda: (torch.zeros(10),)), "const_arange_len": (lambda x: x[: torch.arange(0, 1, 0.1).shape[0]], lambda: (torch.zeros(12),)),
    "const_linspace": (lambda x: torch.linspace(0, 1, 7) + x[:7], lambda: (torch.zeros(7),)), "const_linspace_int": (lambda x: torch.linspace(0, 10, 4, dtype=torch.int32) + x[:4], lambda: (torch.zeros(4, dtype=torch.int32),)),
    "const_scalar_tensor_precision": (lambda x: x + torch.tensor(16777217.0), lambda: (torch.zeros(2),)), "const_py_scalar_precision": (lambda x: x + 16777217, lambda: (torch.zeros(2),)),
    "const_py_float_third": (lambda x: x * (1 / 3) * 3, lambda: (E(),)), "const_tiny_scalar": (lambda x: x + 1e-45, lambda: (torch.zeros(2),)), "const_f64_scalar_in_f32": (lambda x: x * 1e39, lambda: (torch.ones(2),)),
    "const_int_tensor_big_py": (lambda x: x + 2 ** 31, lambda: (torch.zeros(2, dtype=torch.int64),)), "const_where_scalar": (lambda x: torch.where(x > 0, 1, 2.5), lambda: (E(),)),
    "const_full_like_nan": (lambda x: torch.full_like(x, NAN) * 0 + x, lambda: (torch.zeros(2),)), "const_tri": (lambda x: torch.ones(3, 3).tril() @ x, lambda: (M(3, 2),)),
    "const_eye_mul": (lambda x: torch.eye(3) @ x, lambda: (torch.tensor([[INF, 1.0], [NAN, 2.0], [0.0, -0.0]]),)), "zeros_like_mul_inf": (lambda x: torch.zeros_like(x) * x, lambda: (E(),)),
    "ones_like_pow": (lambda x: torch.ones_like(x) ** x, lambda: (E(),)), "shape_arith": (lambda x: x * (x.shape[0] // 3) + (x.shape[0] % 5) - (x.numel() / 7), lambda: (E(),)),
}


def _alias_cases():
    A = {}

    def a(name):
        def deco(fn):
            A[name] = fn
            return fn
        return deco

    @a("clone_then_mutate_clone")
    def _(C):
        x = E()
        def f(x):
            y = x.clone(); y.add_(1)
            return y
        return [C(f)(x), x]

    @a("clone_then_mutate_source")
    def _(C):
        x = E()
        def f(x):
            y = x.clone(); x.add_(1)
            return y
        return [C(f)(x), x]

    @a("to_same_dtype_returns_self")
    def _(C):
        x = M()
        y = C(lambda x: x.to(torch.float32))(x)
        y.add_(1)
        return [x, y.data_ptr() == x.data_ptr()]

    @a("float_returns_self")
    def _(C):
        x = M(); y = C(lambda x: x.float())(x); y.mul_(2)
        return [x, y.data_ptr() == x.data_ptr()]

    @a("contiguous_returns_self")
    def _(C):
        x = M(); y = C(lambda x: x.contiguous())(x); y.mul_(2)
        return [x, y.data_ptr() == x.data_ptr()]

    @a("reshape_returns_view")
    def _(C):
        x = M(); y = C(lambda x: x.reshape(4, 3))(x); y.mul_(2)
        return [x]

    @a("reshape_of_transposed_copies")
    def _(C):
        x = M(); y = C(lambda x: x.t().reshape(12))(x); y.mul_(2)
        return [x]

    @a("expand_as_self_view")
    def _(C):
        x = M(); y = C(lambda x: x.expand_as(x))(x); y.mul_(2)
        return [x]

    @a("add_zero_is_copy")
    def _(C):
        x = M(); y = C(lambda x: x + 0)(x); y.mul_(2)
        return [x, y.data_ptr() == x.data_ptr()]

    @a("mul_one_is_copy")
    def _(C):
        x = M(); y = C(lambda x: x * 1)(x); y.mul_(2)
        return [x]

    @a("cat_single_is_copy")
    def _(C):
        x = M(); y = C(lambda x: torch.cat([x]))(x); y.mul_(2)
        return [x]

    @a("slice_full_is_view")
    def _(C):
        x = M(); y = C(lambda x: x[:, :])(x); y.mul_(2)
        return [x]

    @a("detach_is_view")
    def _(C):
        x = M(); y = C(lambda x: x.detach())(x); y.mul_(2)
        return [x]

    @a("internal_clone_mutation_order")
    def _(C):
        x = M()
        def f(x):
            a = x.clone(); b = a.view(-1); b[0] = 100.0
            c = x + a
            x[0, 0] = -5.0
            return c, a
        return [C(f)(x), x]

    @a("inplace_on_noop_view_chain")
    def _(C):
        x = M()
        def f(x):
            v = x.view(3, 4).t().t()[:, :]
            v.add_(1)
            return x * 2
        return [C(f)(x), x]

    @a("two_outputs_same_tensor")
    def _(C):
        x = M(); a, b = C(lambda x: (lambda y: (y, y))(x * 2))(x); a.add_(1)
        return [b, a.data_ptr() == b.data_ptr()]

    @a("output_view_of_output")
    def _(C):
        x = M()
        def f(x):
            y = x * 2
            return y, y[0]
        a, b = C(f)(x); b.zero_()
        return [a]

    @a("noop_cast_then_inplace")
    def _(C):
        x = M()
        def f(x):
            y = x.to(torch.float32); y.zero_()
            return x.sum()
        return [C(f)(x), x]

    @a("noop_contiguous_then_inplace")
    def _(C):
        x = M()
        def f(x):
            y = x.contiguous(); y.zero_()
            return x.sum()
        return [C(f)(x), x]

    @a("noncontig_contiguous_then_inplace")
    def _(C):
        x = M().t()
        def f(x):
            y = x.contiguous(); y.zero_()
            return x.sum()
        return [C(f)(x), x]
    return A


ALIAS = _alias_cases()


def norm(o):
    if isinstance(o, torch.Tensor):
        t = o.detach()
        vals = []
        for v in t.flatten().double().tolist() if t.dtype != torch.bool else t.flatten().tolist():
            if isinstance(v, bool):
                vals.append(v)
            elif v != v:
                vals.append("nan")
            elif v == 0:
                vals.append("-0" if math.copysign(1.0, v) < 0 else "0")
            else:
                vals.append(v)
        return {"T": str(t.dtype), "shape": list(t.shape), "v": vals}
    if isinstance(o, (list, tuple)):
        return [norm(x) for x in o]
    if isinstance(o, (bool, int, str)) or o is None:
        return o
    if isinstance(o, float):
        return "nan" if o != o else o
    return repr(type(o).__name__)


def close(a, b):
    if isinstance(a, dict) and isinstance(b, dict):
        if a.get("T") != b.get("T") or a.get("shape") != b.get("shape") or len(a["v"]) != len(b["v"]):
            return False
        for x, y in zip(a["v"], b["v"]):
            if x == y:
                continue
            if isinstance(x, float) and isinstance(y, float) and math.isfinite(x) and math.isfinite(y) and abs(x - y) <= 1e-6 * max(abs(x), abs(y)):
                continue
            return False
        return True
    if isinstance(a, list) and isinstance(b, list):
        return len(a) == len(b) and all(close(x, y) for x, y in zip(a, b))
    return a == b


def observe(name, backend):
    torch._dynamo.reset()
    C = (lambda f: f) if backend is None else (lambda f: torch.compile(f, backend=backend))
    try:
        if name in ALIAS:
            return norm(ALIAS[name](C))
        fn, build = P[name]
        return norm(C(fn)(*build()))
    except Exception as e:  # noqa: BLE001
        return {"raised": type(e).__name__, "msg": (str(e).splitlines() or [""])[0][:160]}


def first_diff(e, o):
    if isinstance(e, dict) and isinstance(o, dict) and "v" in e and "v" in o:
        if e["T"] != o["T"] or e["shape"] != o["shape"]:
            return f"dtype/shape {e['T']}{e['shape']} vs {o['T']}{o['shape']}"
        return "; ".join(f"[{i}] eager {x!r} compiled {y!r}" for i, (x, y) in enumerate(zip(e["v"], o["v"])) if not close({"T": 0, "shape": 0, "v": [x]}, {"T": 0, "shape": 0, "v": [y]}))[:260]
    if isinstance(e, list) and isinstance(o, list) and len(e) == len(o):
        for i, (x, y) in enumerate(zip(e, o)):
            if not close(x, y):
                return f"item {i}: " + first_diff(x, y)
    return f"eager {json.dumps(e)[:120]} compiled {json.dumps(o)[:120]}"


def report(path):
    from collections import Counter
    rows = [json.loads(l) for l in open(path, encoding="utf-8") if l.strip()]
    print(len(rows), dict(Counter(r["verdict"] for r in rows)))
    for r in rows:
        if r["verdict"] == "ok":
            continue
        if r["verdict"] == "CRASH":
            print(f"[CRASH] {r['op']} rc={r.get('returncode')}"); continue
        for b, x in r["backends"].items():
            if not x["same"]:
                print(f"[{b}] {r['op']}: {x['diff']}")


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--only", default=None)
    ap.add_argument("--backends", default="aot_eager,inductor")
    ap.add_argument("--isolate", action="store_true")
    ap.add_argument("--report", action="store_true")
    ap.add_argument("--chunk", type=int, default=12, help="cases per child process when --isolate")
    ap.add_argument("--out-jsonl", default=os.path.join(ROOT, "results", "rewrites", "cases.jsonl"))
    a = ap.parse_args()
    os.makedirs(os.path.dirname(a.out_jsonl), exist_ok=True)
    if a.report:
        return report(a.out_jsonl)
    names = a.only.split(",") if a.only else list(P) + list(ALIAS)
    if a.isolate:
        run_isolated(os.path.abspath(__file__), names, ["--backends", a.backends], a.out_jsonl, timeout=1200)
        return
    for n in names:
        e = observe(n, None)
        rec, bad = {"op": n, "eager": e, "backends": {}}, []
        for b in a.backends.split(","):
            o = observe(n, b)
            same = close(e, o) or (isinstance(e, dict) and "raised" in e and isinstance(o, dict) and "raised" in o)
            rec["backends"][b] = {"same": same, "diff": "" if same else first_diff(e, o)}
            if not same:
                bad.append(b)
        rec["verdict"] = "ok" if not bad else "DIFF:" + "+".join(bad)
        jsonl_append(a.out_jsonl, rec)
        if bad:
            print(f"  !! {n}: {bad}: {rec['backends'][bad[-1]]['diff'][:200]}", flush=True)


if __name__ == "__main__":
    main()
