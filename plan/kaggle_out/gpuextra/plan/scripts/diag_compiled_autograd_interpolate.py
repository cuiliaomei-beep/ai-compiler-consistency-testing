"""compiled_autograd + F.interpolate backward: eager backward fine, compiled_autograd raises."""
import os, sys
sys.path.insert(0, os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
try:
    from tcc.compat import ensure_msvc_env; ensure_msvc_env()
except Exception:
    pass
import torch, torch.nn.functional as F
print("torch", torch.__version__)
x = torch.randn(1, 2, 4, 4, requires_grad=True)
cases = {
    "nearest size": lambda t: F.interpolate(t, size=(8, 8), mode="nearest"),
    "nearest scale": lambda t: F.interpolate(t, scale_factor=2, mode="nearest"),
    "bilinear": lambda t: F.interpolate(t, scale_factor=2, mode="bilinear", align_corners=False),
    "bicubic": lambda t: F.interpolate(t, scale_factor=2, mode="bicubic"),
    "linear 1d": lambda t: F.interpolate(t[:, :, 0], scale_factor=2, mode="linear"),
    "trilinear": lambda t: F.interpolate(t.unsqueeze(2), scale_factor=2, mode="trilinear"),
    "adaptive_avg_pool2d": lambda t: F.adaptive_avg_pool2d(t, 2),
    "conv2d": lambda t: F.conv2d(t, torch.ones(1, 2, 3, 3)),
}
for name, fn in cases.items():
    x.grad = None
    fn(x).sum().backward(); ge = x.grad.clone(); x.grad = None
    torch._dynamo.reset()
    for backend in ("eager", "aot_eager", "inductor"):
        try:
            with torch._dynamo.compiled_autograd._enable(torch.compile(backend=backend)):
                fn(x).sum().backward()
            r = f"ok (max diff {(x.grad - ge).abs().max().item():.1e})"
        except Exception as e:
            lines = [l for l in str(e).splitlines() if l.strip()]
            inner = next((l for l in lines if "Error" in l and "TorchRuntimeError" not in l), lines[0])
            r = f"raise {type(e).__name__}: {inner.strip()[:140]}"
        x.grad = None
        print(f"[{name}] compiled_autograd({backend}): {r}")
