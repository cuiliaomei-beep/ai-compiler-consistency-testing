"""11.3 / 11.6  One semantics, two wrapper generators: Inductor's default Python wrapper against the C++ wrapper
(`cpp_wrapper=True`, the code path AOTInductor ships).  The kernels are the same; what differs is everything the wrapper
prints itself: arguments of fallback (extern) kernels -- special floats, large ints, bools, None / optional values, int
lists, strings, dtypes, complex scalars --, size expressions, returned Python numbers, aliasing of outputs and input mutation.

Each program is run in eager, under the Python wrapper and under the C++ wrapper, on the same inputs.
    python scripts/cpp_wrapper_diff.py --isolate          # every program in its own process
    python scripts/cpp_wrapper_diff.py --report
"""
import argparse
import json
import math
import os
import sys
import tempfile

sys.path.insert(0, os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
os.environ.setdefault("TORCHINDUCTOR_CACHE_DIR", tempfile.mkdtemp(prefix="tcc_cw_"))
from tcc.compat import ensure_msvc_env  # noqa: E402

ensure_msvc_env()
import torch  # noqa: E402
import torch.nn.functional as F  # noqa: E402

from tcc.sweep_common import jsonl_append, run_isolated  # noqa: E402

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
INF, NAN = float("inf"), float("nan")
torch._dynamo.config.capture_scalar_outputs = True
torch._dynamo.config.capture_dynamic_output_shape_ops = True


def T(*shape, dtype=torch.float32, seed=0):
    g = torch.Generator().manual_seed(seed)
    if dtype.is_floating_point:
        return torch.randn(*shape, generator=g, dtype=dtype)
    if dtype.is_complex:
        return torch.complex(torch.randn(*shape, generator=g), torch.randn(*shape, generator=g)).to(dtype)
    return torch.randint(-5, 6, shape, generator=g, dtype=dtype)


def spd(n):
    a = T(n, n, dtype=torch.float64)
    return a @ a.T + n * torch.eye(n, dtype=torch.float64)


P = {}   # name -> (fn, inputs factory)


def reg(name, fn, make):
    P[name] = (fn, make)


# --- fallback kernels with float arguments at special values
for p in (0.0, 0.5, 1.0, 2.0, 3.0, INF):
    reg(f"cdist p={p}", lambda a, b, p=p: torch.cdist(a, b, p=p), lambda: (T(5, 4), T(6, 4, seed=1)))
for beta, alpha in ((0.5, -2.0), (0.0, 1.0), (-0.0, INF), (NAN, 1.0), (1e-45, 1e38), (1, 3), (0, -0.0)):
    reg(f"addmm beta={beta} alpha={alpha}", lambda c, a, b, beta=beta, alpha=alpha: torch.addmm(c, a, b, beta=beta, alpha=alpha), lambda: (T(4, 4), T(4, 4, seed=1), T(4, 4, seed=2)))
    reg(f"baddbmm beta={beta} alpha={alpha}", lambda c, a, b, beta=beta, alpha=alpha: torch.baddbmm(c, a, b, beta=beta, alpha=alpha), lambda: (T(2, 4, 4), T(2, 4, 4, seed=1), T(2, 4, 4, seed=2)))
for alpha in (3, -7, 2 ** 31 + 1, -2 ** 40, 2 ** 62):
    reg(f"addmm int64 alpha={alpha}", lambda c, a, b, alpha=alpha: torch.addmm(c, a, b, beta=alpha, alpha=alpha), lambda: (T(3, 3, dtype=torch.int64), T(3, 3, dtype=torch.int64, seed=1), T(3, 3, dtype=torch.int64, seed=2)))
    reg(f"addmv int64 alpha={alpha}", lambda c, a, b, alpha=alpha: torch.addmv(c, a, b, beta=2, alpha=alpha), lambda: (T(3, dtype=torch.int64), T(3, 3, dtype=torch.int64, seed=1), T(3, dtype=torch.int64, seed=2)))
for z in (1 + 2j, -0.0 + 0j, complex(INF, 0), complex(0, NAN), 2.5):
    reg(f"complex mul scalar {z}", lambda a, z=z: a * z, lambda: (T(6, dtype=torch.complex64),))
    reg(f"complex addmm alpha {z}", lambda c, a, b, z=z: torch.addmm(c, a, b, alpha=z, beta=z), lambda: (T(3, 3, dtype=torch.complex64), T(3, 3, dtype=torch.complex64, seed=1), T(3, 3, dtype=torch.complex64, seed=2)))
    reg(f"complex full {z}", lambda a, z=z: a + torch.full((6,), z, dtype=torch.complex64), lambda: (T(6, dtype=torch.complex64),))
for p, m in ((2.0, 1e-3), (INF, 0.5), (1.0, 1e30), (0.5, 1.0)):
    reg(f"renorm p={p} maxnorm={m}", lambda a, p=p, m=m: torch.renorm(a, p, 0, m), lambda: (T(4, 5),))
for lo, hi in ((-1.5, 1.5), (0.0, 0.0), (-0.0, 1e-30), (-3e38, 3e38)):
    reg(f"histc min={lo} max={hi}", lambda a, lo=lo, hi=hi: torch.histc(a, bins=7, min=lo, max=hi), lambda: (T(64),))
for rt in (1e-30, 0.5, 0.0, INF):
    reg(f"pinv rtol={rt}", lambda a, rt=rt: torch.linalg.pinv(a, rtol=rt), lambda: (T(4, 3, dtype=torch.float64),))
    reg(f"matrix_rank tol={rt}", lambda a, rt=rt: torch.linalg.matrix_rank(a, tol=rt), lambda: (T(4, 3, dtype=torch.float64),))
reg("lstsq rcond=None", lambda a, b: torch.linalg.lstsq(a, b).solution, lambda: (T(5, 3, dtype=torch.float64), T(5, 2, dtype=torch.float64, seed=1)))
reg("lstsq rcond=1e-3 gelsd", lambda a, b: torch.linalg.lstsq(a, b, rcond=1e-3, driver="gelsd").solution, lambda: (T(5, 3, dtype=torch.float64), T(5, 2, dtype=torch.float64, seed=1)))
for margin, p in ((0.3, 1), (1.0, 2), (-0.5, 1)):
    reg(f"multi_margin_loss p={p} margin={margin}", lambda a, t, margin=margin, p=p: F.multi_margin_loss(a, t, p=p, margin=margin), lambda: (T(6, 5), torch.tensor([0, 1, 2, 3, 4, 0])))
reg("multilabel_margin_loss", lambda a, t: F.multilabel_margin_loss(a, t), lambda: (T(3, 4), torch.tensor([[3, 0, -1, 1], [1, 2, 3, -1], [0, -1, 0, 0]])))
reg("ctc_loss blank=2 zero_infinity", lambda lp, tg: F.ctc_loss(lp.log_softmax(2), tg, torch.tensor([12, 12]), torch.tensor([3, 5]), blank=2, zero_infinity=True), lambda: (T(12, 2, 6), torch.tensor([[1, 3, 4, 0, 0], [5, 5, 1, 3, 4]])))
for scale in (None, 0.37, 0.0, -1.0, 1e10):
    for causal in (False, True):
        reg(f"sdpa scale={scale} causal={causal}", lambda q, k, v, scale=scale, causal=causal: F.scaled_dot_product_attention(q, k, v, is_causal=causal, scale=scale), lambda: (T(1, 2, 5, 8), T(1, 2, 5, 8, seed=1), T(1, 2, 5, 8, seed=2)))
reg("sdpa float mask with -inf", lambda q, k, v, m: F.scaled_dot_product_attention(q, k, v, attn_mask=m), lambda: (T(1, 2, 5, 8), T(1, 2, 5, 8, seed=1), T(1, 2, 5, 8, seed=2), torch.zeros(5, 5).masked_fill(torch.ones(5, 5).triu(1).bool(), -INF)))

# --- bool / string / optional / int-list arguments
for right, i32 in ((False, False), (True, True)):
    reg(f"bucketize right={right} int32={i32}", lambda a, b, right=right, i32=i32: torch.bucketize(a, b, right=right, out_int32=i32), lambda: (T(9), torch.tensor([-1.0, 0.0, 0.0, 1.0])))
    reg(f"searchsorted side right={right}", lambda s, v, right=right, i32=i32: torch.searchsorted(s, v, side="right" if right else "left", out_int32=i32), lambda: (torch.tensor([[-1.0, 0.0, 0.0, 1.0]]), T(1, 9)))
reg("searchsorted sorter", lambda s, v, idx: torch.searchsorted(s, v, sorter=idx), lambda: (torch.tensor([3.0, 1.0, 2.0]), T(5), torch.tensor([1, 2, 0])))
for desc, stable in ((False, True), (True, True), (True, False)):
    reg(f"sort desc={desc} stable={stable}", lambda a, desc=desc, stable=stable: torch.sort(a, dim=0, descending=desc, stable=stable), lambda: (torch.tensor([[1.0, 2.0], [1.0, -0.0], [NAN, 0.0], [1.0, 2.0], [-INF, NAN]]),))
reg("topk smallest unsorted-free", lambda a: torch.topk(a, 3, dim=1, largest=False, sorted=True), lambda: (T(4, 7),))
reg("kthvalue keepdim", lambda a: torch.kthvalue(a, 2, dim=0, keepdim=True), lambda: (T(5, 3),))
reg("mode", lambda a: torch.mode(a, dim=1), lambda: (T(4, 9, dtype=torch.int64),))
reg("median dim nan", lambda a: torch.median(a, dim=1), lambda: (torch.tensor([[1.0, NAN, 3.0], [4.0, 5.0, 6.0]]),))
reg("nanmedian dim", lambda a: torch.nanmedian(a, dim=1, keepdim=True), lambda: (torch.tensor([[1.0, NAN, 3.0], [NAN, NAN, NAN]]),))
reg("cummax / cummin", lambda a: (torch.cummax(a, 0), torch.cummin(a, 1)), lambda: (T(4, 5),))
reg("logcumsumexp", lambda a: torch.logcumsumexp(a, 1), lambda: (T(4, 5),))
reg("cumprod reverse dims", lambda a: torch.cumprod(a, -2), lambda: (T(4, 5, dtype=torch.float64),))
for red, inc in (("amax", False), ("prod", True), ("mean", False), ("sum", True)):
    reg(f"scatter_reduce {red} include_self={inc}", lambda a, i, s, red=red, inc=inc: a.scatter_reduce(0, i, s, reduce=red, include_self=inc), lambda: (T(5), torch.tensor([0, 0, 2, 4, 4, 4]), T(6, seed=1)))
reg("index_put accumulate duplicates", lambda a, i, v: a.index_put((i,), v, accumulate=True), lambda: (T(5), torch.tensor([0, 0, 2, 0]), T(4, seed=1)))
reg("index_add alpha=-2.5", lambda a, i, v: a.index_add(0, i, v, alpha=-2.5), lambda: (T(5, 3), torch.tensor([0, 0, 4]), T(3, 3, seed=1)))
reg("index_add int alpha=2**33", lambda a, i, v: a.index_add(0, i, v, alpha=2 ** 33), lambda: (T(5, 3, dtype=torch.int64), torch.tensor([0, 0, 4]), T(3, 3, dtype=torch.int64, seed=1)))
reg("bincount minlength weights", lambda a, w: torch.bincount(a, weights=w, minlength=9), lambda: (torch.tensor([0, 1, 1, 5]), T(4, dtype=torch.float64)))
reg("repeat_interleave output_size", lambda a, r: torch.repeat_interleave(a, r, dim=0, output_size=6), lambda: (T(3, 2), torch.tensor([1, 2, 3])))
reg("nonzero as_tuple", lambda a: torch.nonzero(a > 0), lambda: (T(4, 4),))
reg("unique sorted counts", lambda a: torch.unique(a, sorted=True, return_inverse=True, return_counts=True), lambda: (T(12, dtype=torch.int64),))
reg("unique_consecutive dim", lambda a: torch.unique_consecutive(a, dim=0, return_counts=True), lambda: (torch.tensor([[1, 1], [1, 1], [2, 0], [1, 1]]),))
reg("masked_select", lambda a: torch.masked_select(a, a > 0), lambda: (T(4, 4),))
for mode in ("sum", "mean", "max"):
    reg(f"embedding_bag {mode} padding_idx", lambda w, i, o, mode=mode: F.embedding_bag(i, w, o, mode=mode, padding_idx=1, include_last_offset=True), lambda: (T(6, 3), torch.tensor([0, 1, 2, 1, 5, 1]), torch.tensor([0, 2, 2, 6])))
reg("embedding_bag per_sample_weights", lambda w, i, o, ps: F.embedding_bag(i, w, o, mode="sum", per_sample_weights=ps), lambda: (T(6, 3), torch.tensor([0, 1, 2, 1, 5, 1]), torch.tensor([0, 2, 2]), T(6, seed=3)))
for aa, ac, sf in ((True, False, None), (True, True, None), (True, False, 0.6), (False, True, 1.7)):
    reg(f"interpolate bicubic antialias={aa} align={ac} scale={sf}", lambda a, aa=aa, ac=ac, sf=sf: F.interpolate(a, size=None if sf else (5, 7), scale_factor=sf, mode="bicubic", antialias=aa, align_corners=ac), lambda: (T(1, 2, 8, 9),))
reg("interpolate bilinear antialias", lambda a: F.interpolate(a, scale_factor=(0.5, 0.75), mode="bilinear", antialias=True, recompute_scale_factor=False), lambda: (T(1, 2, 8, 9),))
reg("max_pool2d dilation ceil", lambda a: F.max_pool2d(a, (3, 2), stride=(2, 1), padding=(1, 0), dilation=(2, 1), ceil_mode=True, return_indices=True), lambda: (T(1, 2, 9, 9),))
reg("max_pool3d", lambda a: F.max_pool3d(a, 2, stride=1, padding=1, ceil_mode=True), lambda: (T(1, 2, 5, 5, 5),))
reg("avg_pool3d divisor_override", lambda a: F.avg_pool3d(a, 2, stride=1, padding=1, count_include_pad=False, divisor_override=3), lambda: (T(1, 2, 5, 5, 5),))
reg("avg_pool2d large kernel divisor", lambda a: F.avg_pool2d(a, 7, stride=2, padding=3, ceil_mode=True, count_include_pad=False, divisor_override=5), lambda: (T(1, 2, 16, 16),))
reg("adaptive_max_pool2d", lambda a: F.adaptive_max_pool2d(a, (3, 2), return_indices=True), lambda: (T(1, 2, 9, 7),))
reg("adaptive_avg_pool3d", lambda a: F.adaptive_avg_pool3d(a, (2, 3, 1)), lambda: (T(1, 2, 5, 6, 4),))
reg("max_unpool2d", lambda a: F.max_unpool2d(*F.max_pool2d(a, 2, return_indices=True), 2, output_size=(9, 9)), lambda: (T(1, 2, 8, 8),))
reg("fractional_max_pool2d samples", lambda a, s: F.fractional_max_pool2d(a, 2, output_size=(4, 4), _random_samples=s), lambda: (T(1, 2, 9, 9), torch.rand(1, 2, 2, generator=torch.Generator().manual_seed(3))))
reg("conv2d same string padding", lambda a, w: F.conv2d(a, w, None, stride=1, padding="same", dilation=(2, 1)), lambda: (T(1, 4, 9, 9), T(6, 4, 3, 3, seed=1)))
reg("conv2d groups stride list", lambda a, w, b: F.conv2d(a, w, b, stride=(2, 1), padding=(0, 2), dilation=(1, 2), groups=2), lambda: (T(1, 4, 9, 9), T(6, 2, 3, 3, seed=1), T(6, seed=2)))
reg("conv_transpose2d output_padding", lambda a, w: F.conv_transpose2d(a, w, None, stride=(2, 3), padding=(1, 0), output_padding=(1, 2), groups=2, dilation=(1, 2)), lambda: (T(1, 4, 5, 5), T(4, 3, 3, 3, seed=1)))
reg("conv1d int64 fallback-free", lambda a, w: F.conv1d(a, w, padding=2), lambda: (T(1, 2, 9, dtype=torch.float64), T(3, 2, 3, dtype=torch.float64, seed=1)))
for norm in (None, "ortho", "forward"):
    reg(f"fft n=7 norm={norm}", lambda a, norm=norm: torch.view_as_real(torch.fft.fft(a, n=7, dim=0, norm=norm)), lambda: (T(5, 3),))
    reg(f"rfft2 irfft2 norm={norm}", lambda a, norm=norm: torch.fft.irfft2(torch.fft.rfft2(a, norm=norm), s=(5, 6), norm=norm), lambda: (T(5, 6),))
reg("stft", lambda a: torch.view_as_real(torch.stft(a, 8, hop_length=3, window=torch.hann_window(8), center=True, normalized=True, onesided=False, return_complex=True)), lambda: (T(40),))
for uplo in ("L", "U"):
    reg(f"eigh {uplo}", lambda a, uplo=uplo: torch.linalg.eigh(a, UPLO=uplo).eigenvalues, lambda: (spd(4),))
    reg(f"cholesky upper={uplo == 'U'}", lambda a, uplo=uplo: torch.linalg.cholesky(a, upper=uplo == "U"), lambda: (spd(4),))
for upper, left, unit in ((True, True, False), (False, False, True), (True, False, True)):
    reg(f"solve_triangular upper={upper} left={left} unit={unit}", lambda a, b, upper=upper, left=left, unit=unit: torch.linalg.solve_triangular(a.triu() if upper else a.tril(), b, upper=upper, left=left, unitriangular=unit), lambda: (spd(4), T(4, 4, dtype=torch.float64, seed=1)))
for mode in ("reduced", "complete", "r"):
    reg(f"qr mode={mode}", lambda a, mode=mode: torch.linalg.qr(a, mode=mode).R.abs(), lambda: (T(5, 3, dtype=torch.float64),))
reg("svd full_matrices=False", lambda a: torch.linalg.svd(a, full_matrices=False).S, lambda: (T(5, 3, dtype=torch.float64),))
reg("matrix_norm nuc / vector_norm inf", lambda a: (torch.linalg.matrix_norm(a, ord="nuc"), torch.linalg.matrix_norm(a, ord=-2), torch.linalg.vector_norm(a, ord=-INF)), lambda: (T(4, 4, dtype=torch.float64),))
reg("lu_factor pivot / lu_solve", lambda a, b: torch.linalg.lu_solve(*torch.linalg.lu_factor(a), b, left=True, adjoint=True), lambda: (spd(4), T(4, 2, dtype=torch.float64, seed=1)))
reg("matrix_exp / det / slogdet", lambda a: (torch.linalg.matrix_exp(a / 4), torch.linalg.det(a), torch.linalg.slogdet(a).logabsdet), lambda: (spd(3),))
reg("cross / tensordot / einsum", lambda a, b: (torch.linalg.cross(a, b, dim=-1), torch.tensordot(a, b, dims=([0], [0])), torch.einsum("ij,kj->ik", a, b)), lambda: (T(4, 3), T(4, 3, seed=1)))
reg("tril_indices offset / triu_indices", lambda a: a[tuple(torch.tril_indices(5, 5, offset=-2))] + a[tuple(torch.triu_indices(5, 5, offset=3))].sum(), lambda: (T(5, 5),))
reg("polar / angle / complex abs", lambda a, b: torch.view_as_real(torch.polar(a.abs(), b)).sum(-1) + torch.polar(a.abs(), b).angle(), lambda: (T(6), T(6, seed=1)))
reg("complex mm / conj / resolve", lambda a, b: torch.view_as_real((a.conj() @ b.mH).resolve_conj()), lambda: (T(3, 3, dtype=torch.complex64), T(3, 3, dtype=torch.complex64, seed=1)))

# --- what the wrapper itself computes: sizes, returned numbers, aliasing, mutation (dynamic shapes on)
reg("D returns ints and floats", lambda a: (a.shape[0] // 3, (a.shape[0] - 10) // 3, (a.shape[0] - 10) % 3, a.shape[0] / 3, round(a.shape[0] / 4), int((a.shape[0] - 10) / 3), max(a.shape[0], 7), a.shape[0] ** 2, math.ceil(a.shape[0] / 3), a.sum()), lambda: (T(9),))
reg("D full with size-derived value", lambda a: torch.full((abs(a.shape[0] - 10) + 1,), (a.shape[0] - 10) // 3) + torch.full((2,), (a.shape[0] - 10) / 4), lambda: (T(9),))
reg("D view with floordiv / mod sizes", lambda a: a[: a.shape[0] // 3 * 3].view(a.shape[0] // 3, -1) + a.shape[0] % 3, lambda: (T(9),))
reg("D item-derived size", lambda a, k: torch.zeros(k.item() * 2 + 1) + a.sum(), lambda: (T(9), torch.tensor(3)))
reg("D item float into fallback arg", lambda c, a, b, s: torch.addmm(c, a, b, beta=s.item(), alpha=1 - s.item()), lambda: (T(4, 4), T(4, 4, seed=1), T(4, 4, seed=2), torch.tensor(0.25, dtype=torch.float64)))
reg("D item int into fallback arg", lambda a, k: torch.kthvalue(a, k.item() + 1, dim=0).values, lambda: (T(9, 3), torch.tensor(3)))
reg("D python float input into fallback", lambda c, a, b, s: torch.addmm(c * s, a, b, beta=s, alpha=s * 2), lambda: (T(4, 4), T(4, 4, seed=1), T(4, 4, seed=2), 0.3))
reg("alias: returns input and view of input", lambda a: (a, a[1:], a.t(), a.view(-1)[::2]), lambda: (T(4, 4),))
reg("alias: same output twice and view of output", lambda a: (lambda b: (b, b, b[0], b.unsqueeze(0)))(a * 2), lambda: (T(4, 4),))
reg("alias: as_strided storage offset", lambda a: (a * 2).as_strided((2, 2), (1, 3), 3), lambda: (T(4, 4),))
reg("outputs: None, scalar, zero-size, 0-dim, bool, int8", lambda a: (None, a.sum(), a[:0], a[0, 0], a > 0, a.to(torch.int8), a.new_zeros(0, 3), 7, 2.5, True), lambda: (T(4, 4),))
reg("mutation: input add_ and returns view", lambda a: (a.add_(1), a[1:].mul_(2), a.sum()), lambda: (T(4, 4),))
reg("mutation: non-contiguous input view", lambda a: (a.t()[1:].add_(3), a.sum()), lambda: (T(4, 4),))
reg("mutation: copy_ dtype change and resize-free", lambda a, b: (a.copy_(b), a.to(torch.float64).sum()), lambda: (T(4, 4), T(4, 4, dtype=torch.int64, seed=1)))
reg("mutation: set via index_put_ / scatter_", lambda a, i: (a.index_put_((i,), a.new_full((), 9.0)), a.scatter_(1, i[None].expand(4, -1)[:, :1], -1.0), a.sum()), lambda: (T(4, 4), torch.tensor([0, 2])))
reg("inputs: non-contiguous, offset, expanded, 0-dim, empty", lambda a, b, c, d, e: (a @ a, b * 2, c + d, e.sum() + d), lambda: (T(6, 6).t()[1:5, 1:5], T(12)[3::2], T(1, 3).expand(4, 3), torch.tensor(2.5), T(0, 3)))
reg("inputs: int / bool / None / list mix", lambda a, n, flag, lst: (a * n + lst[0] if flag else a - n, lst[1] * n), lambda: (T(5), 3, True, [T(5, seed=1), 2.5]))
reg("dtypes: float16 / bfloat16 / uint8 fallback mm-free", lambda a: (a.to(torch.bfloat16).cumsum(0), a.to(torch.float16).sort(0).values, (a * 10).to(torch.uint8).cummax(0).values), lambda: (T(9, 2),))
reg("device / dtype / layout kwargs", lambda a: torch.empty_strided((2, 3), (3, 1), dtype=torch.float64, device="cpu").fill_(1.5) + torch.arange(3, dtype=torch.float64) + torch.ones(2, 3, dtype=torch.int16), lambda: (T(3),))
reg("memory_format channels_last through fallback conv", lambda a, w: F.conv2d(a.contiguous(memory_format=torch.channels_last), w).contiguous(memory_format=torch.channels_last), lambda: (T(1, 4, 9, 9), T(6, 4, 3, 3, seed=1)))


def norm(v, top=True):
    if isinstance(v, torch.Tensor):
        t = v.detach()
        if t.is_complex():
            t = torch.view_as_real(t.resolve_conj())
        return {"dtype": str(v.dtype), "shape": list(v.shape), "stride": list(v.stride()) if v.numel() else [], "vals": [repr(x) for x in t.double().flatten().tolist()[:64]]}
    if isinstance(v, (tuple, list)):
        return [norm(x, False) for x in v]
    if hasattr(v, "_fields") or (hasattr(v, "__iter__") and not isinstance(v, (str, bytes, dict))):
        return [norm(x, False) for x in tuple(v)]
    return f"{type(v).__name__}:{v!r}"


def close(a, b):
    if isinstance(a, dict) and isinstance(b, dict):
        if a["dtype"] != b["dtype"] or a["shape"] != b["shape"]:
            return f"dtype/shape {a['dtype']}{a['shape']} vs {b['dtype']}{b['shape']}"
        for x, y in zip(a["vals"], b["vals"]):
            fx, fy = float(x), float(y)
            if math.isnan(fx) != math.isnan(fy):
                return f"nan pattern {x} vs {y}"
            if not math.isnan(fx) and fx != fy and not (abs(fx - fy) <= 1e-4 * max(1.0, abs(fx), abs(fy))):
                return f"value {x} vs {y}"
        if a["stride"] != b["stride"]:
            return f"stride {a['stride']} vs {b['stride']}"
        return None
    if isinstance(a, list) and isinstance(b, list):
        if len(a) != len(b):
            return f"len {len(a)} vs {len(b)}"
        for x, y in zip(a, b):
            r = close(x, y)
            if r:
                return r
        return None
    if isinstance(a, str) and isinstance(b, str) and a.split(":")[0] == b.split(":")[0] == "float":
        fx, fy = float(a.split(":")[1]), float(b.split(":")[1])
        return None if (fx == fy or (math.isnan(fx) and math.isnan(fy)) or abs(fx - fy) <= 1e-9 * max(1.0, abs(fx))) else f"{a} vs {b}"
    return None if a == b else f"{a} vs {b}"


def observe(f, make):
    args = make()
    try:
        out = f(*args)
        return {"out": norm(out), "inputs_after": [norm(x) for x in args if isinstance(x, torch.Tensor)]}
    except Exception as e:  # noqa: BLE001
        return {"raised": type(e).__name__, "msg": str(e)[:300]}


def compare(e, c):
    if "raised" in e or "raised" in c:
        if "raised" in e and "raised" in c:
            return None
        return ("SILENT: eager raises " + e["raised"]) if "raised" in e else ("RAISES " + c["raised"] + ": " + c["msg"])
    r = close(e["out"], c["out"])
    if r:
        return "VALUE " + r
    r = close(e["inputs_after"], c["inputs_after"])
    return ("MUTATION " + r) if r else None


def run_case(name):
    f, make = P[name]
    dyn = name.startswith("D ")
    rec = {"op": name, "diffs": {}}
    e = observe(f, make)
    rec["eager"] = "raises " + e["raised"] if "raised" in e else "ok"
    for label, opts in (("py_wrapper", {}), ("cpp_wrapper", {"cpp_wrapper": True})):
        torch._dynamo.reset()
        cf = torch.compile(f, dynamic=dyn, options=opts)
        for rep in range(2 if not dyn else 1):
            d = compare(e, observe(cf, make))
            if d:
                rec["diffs"][label] = d
                break
    a, b = rec["diffs"].get("py_wrapper"), rec["diffs"].get("cpp_wrapper")
    rec["verdict"] = "ok" if not a and not b else ("BOTH" if a and b else ("CPP_WRAPPER_ONLY" if b else "PY_WRAPPER_ONLY"))
    return rec


def report(path):
    rows = [json.loads(l) for l in open(path, encoding="utf-8")]
    print(f"{len(rows)} programs;", {v: sum(1 for r in rows if r['verdict'] == v) for v in sorted({r['verdict'] for r in rows})})
    for r in rows:
        if r["verdict"] != "ok":
            print(f"\n[{r['verdict']}] {r['op']}   (eager: {r.get('eager')})")
            for k, v in r["diffs"].items():
                print(f"    {k:12s} {v[:400]}")


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--only", default=None)
    ap.add_argument("--isolate", action="store_true")
    ap.add_argument("--report", action="store_true")
    ap.add_argument("--out-jsonl", default=os.path.join(ROOT, "results", "cppwrap", f"cases_{torch.__version__.split('+')[0]}.jsonl"))
    a = ap.parse_args()
    if a.report:
        return report(a.out_jsonl)
    names = [a.only] if a.only else list(P)
    if a.isolate and not a.only:
        return run_isolated(os.path.abspath(__file__), names, [], a.out_jsonl, timeout=1500)
    for n in names:
        try:
            rec = run_case(n)
        except Exception as e:  # noqa: BLE001
            rec = {"op": n, "verdict": "TOOL_ERROR", "diffs": {"tool": f"{type(e).__name__}: {str(e)[:300]}"}}
        jsonl_append(a.out_jsonl, rec)
        print(rec["verdict"], n, flush=True)


if __name__ == "__main__":
    main()
