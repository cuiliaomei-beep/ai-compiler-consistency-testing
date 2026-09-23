"""Inductor: avg_pool{1,2,3}d backward with ceil_mode=True divides the last (overhanging) window by the full kernel
size; eager and aot_eager divide by the window clipped to the padded input.  Forward agrees; only the gradient differs."""
import os, sys, tempfile
os.environ.setdefault("TORCHINDUCTOR_CACHE_DIR", tempfile.mkdtemp(prefix="tcc_ap_"))
try:
    sys.path.insert(0, os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
    from tcc.compat import ensure_msvc_env
    ensure_msvc_env()
except Exception:  # noqa: BLE001
    pass
import torch, torch.nn.functional as F

print("torch", torch.__version__, "cuda", torch.cuda.is_available())


def grad_of(f, x, backend=None):
    x = x.detach().clone().requires_grad_()
    (f if backend is None else torch.compile(f, backend=backend))(x).sum().backward()
    return x.grad


for dev in ["cpu"] + (["cuda"] if torch.cuda.is_available() else []):
    cases = {
        "avg_pool1d k=6 s=3 p=2 ceil count_include_pad=True": (lambda x: F.avg_pool1d(x, 6, stride=3, padding=2, ceil_mode=True, count_include_pad=True), torch.arange(10.0, device=dev).reshape(1, 1, 10)),
        "avg_pool1d k=6 s=3 p=2 ceil count_include_pad=False": (lambda x: F.avg_pool1d(x, 6, stride=3, padding=2, ceil_mode=True, count_include_pad=False), torch.arange(10.0, device=dev).reshape(1, 1, 10)),
        "avg_pool1d k=3 s=2 p=0 ceil (no padding)": (lambda x: F.avg_pool1d(x, 3, stride=2, ceil_mode=True), torch.arange(6.0, device=dev).reshape(1, 1, 6)),
        "avg_pool2d k=3 s=2 p=1 ceil count_include_pad=True": (lambda x: F.avg_pool2d(x, 3, stride=2, padding=1, ceil_mode=True, count_include_pad=True), torch.arange(36.0, device=dev).reshape(1, 1, 6, 6)),
        "avg_pool2d k=3 s=2 p=1 ceil count_include_pad=False": (lambda x: F.avg_pool2d(x, 3, stride=2, padding=1, ceil_mode=True, count_include_pad=False), torch.arange(36.0, device=dev).reshape(1, 1, 6, 6)),
        "avg_pool2d k=3 s=2 p=1 ceil=False (control)": (lambda x: F.avg_pool2d(x, 3, stride=2, padding=1, ceil_mode=False, count_include_pad=True), torch.arange(36.0, device=dev).reshape(1, 1, 6, 6)),
        "avg_pool3d k=2 s=2 p=1 ceil count_include_pad=True": (lambda x: F.avg_pool3d(x, 2, stride=2, padding=1, ceil_mode=True, count_include_pad=True), torch.arange(27.0, device=dev).reshape(1, 1, 3, 3, 3)),
    }
    for name, (f, x) in cases.items():
        torch._dynamo.reset()
        ge, ga, gi = grad_of(f, x), grad_of(f, x, "aot_eager"), grad_of(f, x, "inductor")
        fwd_ok = torch.allclose(f(x), torch.compile(f)(x))
        flag = "  " if torch.allclose(ge, gi) else "!!"
        print(f"{flag} [{dev}] {name:52s} forward same: {fwd_ok}  grad: eager==aot_eager {torch.allclose(ge, ga)}  eager==inductor {torch.allclose(ge, gi)}  max|diff| {(ge - gi).abs().max().item():.4f}", flush=True)
        if flag == "!!":
            print(f"        eager grad tail    {ge.flatten()[-4:].tolist()}\n        inductor grad tail {gi.flatten()[-4:].tolist()}")
