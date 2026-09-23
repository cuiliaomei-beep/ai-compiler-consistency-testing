"""12.1  Ops that have both a dedicated Inductor lowering and a _refs/_decomp decomposition with a dtype / validation
special case: eager vs aot_eager (decomposition) vs inductor (lowering) on inputs that hit the special case."""
import os, sys, tempfile
os.environ.setdefault("TORCHINDUCTOR_CACHE_DIR", tempfile.mkdtemp(prefix="tcc_ld_"))
try:
    sys.path.insert(0, os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
    from tcc.compat import ensure_msvc_env
    ensure_msvc_env()
except Exception:  # noqa: BLE001
    pass
import torch
import torch.nn.functional as F

print("torch", torch.__version__)
i8 = torch.tensor([[1, -2], [3, 4]], dtype=torch.int8); u8 = torch.tensor([[1, 200], [3, 4]], dtype=torch.uint8); b = torch.tensor([[True, False], [True, True]])
i64 = torch.tensor([[1, -2], [3, 4]]); f = torch.tensor([[1.5, -2.25], [3.0, 4.0]])
NAN = float("nan")
P = {
    "mean(int8)": (lambda x: torch.mean(x), i8), "mean(int8, dtype=float)": (lambda x: torch.mean(x, dtype=torch.float32), i8), "mean(bool)": (lambda x: torch.mean(x), b),
    "sub(bool, bool)": (lambda x: x - x, b), "sub(bool, 1)": (lambda x: x - 1, b), "rsub(1, bool)": (lambda x: 1 - x, b), "sub(bool, bool, alpha=2)": (lambda x: torch.sub(x, x, alpha=2), b),
    "ldexp(int8, int8)": (lambda x: torch.ldexp(x, x), i8), "ldexp(bool, bool)": (lambda x: torch.ldexp(x, x), b), "ldexp(uint8, 2)": (lambda x: torch.ldexp(x, torch.tensor(2)), u8),
    "arange(0, 5, 0.5)": (lambda x: torch.arange(0, 5, 0.5) + x[0, 0], f), "arange(5) * x": (lambda x: torch.arange(5) * x[0, 0], i8), "arange(0.0, 5)": (lambda x: torch.arange(0.0, 5) + x[0, 0], f),
    "arange(3, dtype=uint8) - 5": (lambda x: torch.arange(3, dtype=torch.uint8) - 5 + x[0, 0], u8), "arange(2**31, 2**31+3)": (lambda x: torch.arange(2 ** 31, 2 ** 31 + 3) + x[0, 0], i64),
    "where(cond, 1, 2.5)": (lambda x: torch.where(x, 1, 2.5), b), "where(cond, 1, 2)": (lambda x: torch.where(x, 1, 2), b), "where(cond, True, 2)": (lambda x: torch.where(x, True, 2), b),
    "where(cond, int8, 300)": (lambda x: torch.where(x, i8, 300), b), "where(cond, uint8, -1)": (lambda x: torch.where(x, u8, -1), b), "where(cond, int8, 2.5)": (lambda x: torch.where(x, i8, 2.5), b),
    "round(int8, decimals=-1)": (lambda x: torch.round(x, decimals=-1), i8), "round(int8)": (lambda x: torch.round(x), i8), "round(f, decimals=-1)": (lambda x: torch.round(x, decimals=-1), f),
    "round(uint8, decimals=1)": (lambda x: torch.round(x, decimals=1), u8),
    "bucketize(int8, bounds, out_int32)": (lambda x: torch.bucketize(x, torch.tensor([0, 2, 4], dtype=torch.int8), out_int32=True), i8),
    "bucketize(f, int bounds)": (lambda x: torch.bucketize(x, torch.tensor([0, 2, 4])), f), "bucketize(int8, float bounds)": (lambda x: torch.bucketize(x, torch.tensor([0.5, 2.5])), i8),
    "prod(bool)": (lambda x: torch.prod(x), b), "prod(uint8)": (lambda x: torch.prod(x), u8), "prod(int8, dim=0)": (lambda x: torch.prod(x, 0), i8), "sum(bool)": (lambda x: torch.sum(x), b),
    "sum(uint8)": (lambda x: torch.sum(x), u8), "sum(int8, dtype=int8)": (lambda x: torch.sum(x, dtype=torch.int8), i8), "cumsum(bool)": (lambda x: torch.cumsum(x, 0), b), "cumprod(uint8)": (lambda x: torch.cumprod(x, 0), u8),
    "exponential_(int8)": (lambda x: x.clone().exponential_(), i8), "exponential_(bool)": (lambda x: x.clone().exponential_(), b),
    "pow(int8, 1)": (lambda x: torch.pow(x, 1), i8), "pow(1, int8)": (lambda x: torch.pow(1, x), i8), "pow(int8, 0)": (lambda x: torch.pow(x, 0), i8), "pow(uint8, 2)": (lambda x: torch.pow(x, 2), u8),
    "pow(int8, 2.0)": (lambda x: torch.pow(x, 2.0), i8), "pow(2, uint8)": (lambda x: torch.pow(2, x), u8), "pow(bool, 2)": (lambda x: torch.pow(x, 2), b), "pow(int8, -1)": (lambda x: torch.pow(x, -1), i8),
    "logical_and(int8, uint8)": (lambda x: torch.logical_and(x, u8), i8), "logical_not(uint8)": (lambda x: torch.logical_not(x), u8), "logical_xor(f, int8)": (lambda x: torch.logical_xor(x, i8), f),
    "addcdiv(int8, int8, int8)": (lambda x: torch.addcdiv(x, x, x), i8), "addcmul(int8, int8, int8, value=2.5)": (lambda x: torch.addcmul(x, x, x, value=2.5), i8), "addcmul(f, f, f, value=2)": (lambda x: torch.addcmul(x, x, x, value=2), f),
    "sign(bool)": (lambda x: torch.sign(x), b), "sign(uint8)": (lambda x: torch.sign(x), u8), "signbit(uint8)": (lambda x: torch.signbit(x), u8), "abs(bool)": (lambda x: torch.abs(x), b), "abs(uint8)": (lambda x: torch.abs(x), u8),
    "floor(int8)": (lambda x: torch.floor(x), i8), "ceil(bool)": (lambda x: torch.ceil(x), b), "trunc(uint8)": (lambda x: torch.trunc(x), u8), "frexp(int8)": (lambda x: torch.frexp(x), i8),
    "isinf(int8)": (lambda x: torch.isinf(x), i8), "isnan(bool)": (lambda x: torch.isnan(x), b), "reciprocal(int8)": (lambda x: torch.reciprocal(x), i8), "reciprocal(bool)": (lambda x: torch.reciprocal(x), b),
    "sqrt(uint8)": (lambda x: torch.sqrt(x), u8), "sigmoid(int8)": (lambda x: torch.sigmoid(x), i8), "exp(bool)": (lambda x: torch.exp(x), b), "atan2(int8, uint8)": (lambda x: torch.atan2(x, u8), i8),
    "copysign(int8, 2)": (lambda x: torch.copysign(x, 2), i8), "copysign(f, int8)": (lambda x: torch.copysign(x, i8), f), "digamma(uint8)": (lambda x: torch.digamma(x), u8), "i0(int8)": (lambda x: torch.i0(x), i8),
    "upsample_nearest1d(int8)": (lambda x: F.interpolate(x[None], scale_factor=2, mode="nearest"), i8), "upsample_nearest2d(uint8)": (lambda x: F.interpolate(x[None, None], scale_factor=2, mode="nearest"), u8),
    "glu(int8)": (lambda x: F.glu(x), i8), "embedding(uint8 weight)": (lambda x: F.embedding(i64.clamp(0, 3), x.repeat(2, 1)), u8), "embedding(bool weight)": (lambda x: F.embedding(i64.clamp(0, 3), x.repeat(2, 1)), b),
    "constant_pad_nd(bool, value=2)": (lambda x: F.pad(x, (1, 1), value=2), b), "constant_pad_nd(int8, value=2.5)": (lambda x: F.pad(x, (1, 1), value=2.5), i8),
    "constant_pad_nd(uint8, value=-1)": (lambda x: F.pad(x, (1, 1), value=-1), u8), "constant_pad_nd(int8, value=300)": (lambda x: F.pad(x, (1, 1), value=300), i8),
    "slice_scatter(bool)": (lambda x: torch.slice_scatter(x, torch.zeros(2, 1, dtype=torch.bool), 1, 0, 1), b), "diagonal_scatter(uint8)": (lambda x: torch.diagonal_scatter(x, torch.tensor([9, 9], dtype=torch.uint8)), u8),
    "amax(bool)": (lambda x: torch.amax(x), b), "amin(uint8, dim=(0,1))": (lambda x: torch.amin(x, dim=(0, 1)), u8), "cat(int8, uint8)": (lambda x: torch.cat([x, u8]), i8), "cat(bool, int8)": (lambda x: torch.cat([x, i8]), b),
    "cat(int8, f)": (lambda x: torch.cat([x, f]), i8), "repeat(bool)": (lambda x: x.repeat(2, 1), b), "native_dropout(p=1)": (lambda x: torch.native_dropout(x, 1.0, True), f), "native_dropout(p=0)": (lambda x: torch.native_dropout(x, 0.0, True), f),
    "split(int8, 0)": (lambda x: torch.split(x, 1, 0), i8), "unbind(bool)": (lambda x: torch.unbind(x), b), "squeeze(dims=(0,1)) on (1,1)": (lambda x: torch.squeeze(x[:1, :1], (0, 1)), i8), "expand(uint8)": (lambda x: x[:, :1].expand(2, 3), u8),
    "addmm(int8)": (lambda x: torch.addmm(x, x, x), i8), "addmm(uint8, beta=0)": (lambda x: torch.addmm(x, x, x, beta=0), u8), "addmm(f, beta=0, nan)": (lambda x: torch.addmm(x * NAN, x, x, beta=0), f),
    "baddbmm(int8)": (lambda x: torch.baddbmm(x[None], x[None], x[None]), i8), "baddbmm(f, beta=0 nan)": (lambda x: torch.baddbmm((x * NAN)[None], x[None], x[None], beta=0), f),
    "addmm(bool)": (lambda x: torch.addmm(x, x, x), b), "adaptive_avg_pool2d(int8)": (lambda x: F.adaptive_avg_pool2d(x[None].float(), 1), i8),
    "adaptive_max_pool2d(1,1)": (lambda x: F.adaptive_max_pool2d(x[None], (1, 1), return_indices=True), f), "adaptive_max_pool2d(1,1) int8": (lambda x: F.adaptive_max_pool2d(x[None], (1, 1), return_indices=True), i8),
}


def show(r):
    if isinstance(r, torch.Tensor):
        return f"{r.tolist()} {str(r.dtype).split('.')[-1]}"
    return "(" + ", ".join(show(t) for t in r) + ")"


for name, (fn, x) in P.items():
    outs = {}
    for backend in (None, "aot_eager", "inductor"):
        torch._dynamo.reset()
        try:
            r = fn(x.clone()) if backend is None else torch.compile(fn, backend=backend)(x.clone())
            outs[backend or "eager"] = show(r)
        except Exception as e:  # noqa: BLE001
            outs[backend or "eager"] = "raises " + type(e).__name__
    vals = list(outs.values())
    flag = "  " if vals[0] == vals[1] == vals[2] else ("!!" if vals[2] != vals[0] else "aot")
    print(f"{flag} {name:38s} eager {vals[0][:60]:60s} | aot_eager {vals[1][:40]:40s} | inductor {vals[2][:60]}", flush=True)
