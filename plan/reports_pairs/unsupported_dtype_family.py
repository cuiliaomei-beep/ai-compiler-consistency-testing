"""Representative members of the 'eager kernel not implemented for this dtype, compiled function computes anyway'
family found by scripts/opinfo_edge_sweep.py --unsupported (134 ops on Linux).  Shows what the compiled function returns."""
import os, sys, tempfile
os.environ.setdefault("TORCHINDUCTOR_CACHE_DIR", tempfile.mkdtemp(prefix="tcc_ud_"))
try:
    sys.path.insert(0, os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
    from tcc.compat import ensure_msvc_env
    ensure_msvc_env()
except Exception:  # noqa: BLE001
    pass
import torch, torch.nn.functional as F

print("torch", torch.__version__)
i64 = torch.tensor([[1, -2, 3], [4, 0, -6]]); i8 = i64.to(torch.int8); b = torch.tensor([[True, False, True], [False, True, True]])
f32 = torch.tensor([[1.5, -2.25, 3.0], [0.5, 0.0, -6.0]]); h = f32.half(); c64 = f32.to(torch.complex64)
CASES = {
    "softmax(int64, dim=1)": (lambda: torch.softmax(i64, 1)), "log_softmax(int8)": (lambda: torch.log_softmax(i8, 1)), "var(int64)": (lambda: torch.var(i64)), "std(int8, dim=1)": (lambda: torch.std(i8, 1)),
    "frac(int64)": (lambda: torch.frac(i64)), "logaddexp(int64, int64)": (lambda: torch.logaddexp(i64, i64)), "hypot(int8, int8)": (lambda: torch.hypot(i8, i8)), "nextafter(int64, int64)": (lambda: torch.nextafter(i64, i64)),
    "F.mish(int64)": (lambda: F.mish(i64)), "F.hardswish(int8)": (lambda: F.hardswish(i8)), "F.logsigmoid(int64)": (lambda: F.logsigmoid(i64)), "F.mse_loss(int64, int64)": (lambda: F.mse_loss(i64, i64)),
    "F.huber_loss(int8, int8)": (lambda: F.huber_loss(i8, i8)), "F.cross_entropy(int64 logits)": (lambda: F.cross_entropy(i64, torch.tensor([0, 1]))), "F.nll_loss(int64)": (lambda: F.nll_loss(i64, torch.tensor([0, 1]))),
    "F.unfold(int64)": (lambda: F.unfold(i64[None, None].float().long(), 2)), "F.adaptive_avg_pool2d(int8)": (lambda: F.adaptive_avg_pool2d(i8[None], 1)), "F.avg_pool2d(int8)": (lambda: F.avg_pool2d(i8[None], 2)),
    "bitwise_and(float32, float32)": (lambda: torch.bitwise_and(f32, f32)), "bitwise_not(float32)": (lambda: torch.bitwise_not(f32)), "float32 | float32": (lambda: f32.__ror__(f32)), "bitwise_xor(float16)": (lambda: torch.bitwise_xor(h, h)),
    "matmul(bool, bool)": (lambda: b @ b.T), "conv2d(bool)": (lambda: F.conv2d(b[None, None].expand(1, 1, 2, 3), torch.ones(1, 1, 2, 2, dtype=torch.bool))), "pow(bool, bool)": (lambda: torch.pow(b, b)),
    "round(bool)": (lambda: torch.round(b)), "clamp(bool, 0, 1)": (lambda: torch.clamp(b, 0, 1)), "argmax(bool)": (lambda: torch.argmax(b)), "fmod(bool, bool)": (lambda: torch.fmod(b, b)), "F.threshold(bool)": (lambda: F.threshold(b, 0.5, 0.0)),
    "F.one_hot(float32)": (lambda: F.one_hot(f32.abs().long().float(), 7)), "F.one_hot(int32)": (lambda: F.one_hot(i64.abs().to(torch.int32), 7)),
    "special.bessel_j0(float16)": (lambda: torch.special.bessel_j0(h)), "special.ndtri(bfloat16)": (lambda: torch.special.ndtri(h.bfloat16().clamp(0.1, 0.9))), "special.erfcx(float16)": (lambda: torch.special.erfcx(h)),
    "F.batch_norm(complex64)": (lambda: F.batch_norm(c64, None, None, training=True)), "F.mse_loss(complex64, complex64)": (lambda: F.mse_loss(c64, c64)), "nansum(complex64)": (lambda: torch.nansum(c64)), "xlogy(complex64, complex64)": (lambda: torch.xlogy(c64, c64)),
    "F.avg_pool3d(float16)": (lambda: F.avg_pool3d(h[None, None, None].expand(1, 1, 2, 2, 3), 2)), "F.multi_margin_loss(float16)": (lambda: F.multi_margin_loss(h, torch.tensor([0, 1]))),
}
def show(r):
    if isinstance(r, torch.Tensor):
        return f"returns {str(r.dtype).split('.')[-1]} {r.flatten()[:4].tolist()}{'...' if r.numel() > 4 else ''}"
    return "returns " + repr(r)[:50]
n_silent = 0
for name, f in CASES.items():
    try:
        e = show(f())
    except Exception as ex:  # noqa: BLE001
        e = f"raises {type(ex).__name__}: {str(ex)[:48]}"
    torch._dynamo.reset()
    try:
        c = show(torch.compile(f)())
    except Exception as ex:  # noqa: BLE001
        c = f"raises {type(ex).__name__}"
    flag = "!!" if e.startswith("raises") and c.startswith("returns") else "  "
    n_silent += flag == "!!"
    print(f"{flag} {name:32s} eager {e:62s} compiled {c}", flush=True)
print(n_silent, "of", len(CASES), "silent")
