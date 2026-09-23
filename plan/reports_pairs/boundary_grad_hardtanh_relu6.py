"""Gradient at exactly the clamp boundary: eager hardtanh/relu6/hardshrink backward gives 0 there, the compiled
function gives 1 (Inductor decomposes hardtanh -> clamp, whose derivative is 1 at the boundary)."""
import os, sys, tempfile
os.environ.setdefault("TORCHINDUCTOR_CACHE_DIR", tempfile.mkdtemp(prefix="tcc_bg_"))
try:
    sys.path.insert(0, os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
    from tcc.compat import ensure_msvc_env
    ensure_msvc_env()
except Exception:  # noqa: BLE001
    pass
import torch, torch.nn.functional as F

print("torch", torch.__version__)
x = torch.tensor([-1.0, -0.5, 0.0, 0.5, 1.0, 6.0, 3.0, -3.0])
fns = {"F.hardtanh(x)  (bounds -1, 1)": lambda x: F.hardtanh(x), "F.relu6(x)  (bounds 0, 6)": lambda x: F.relu6(x), "F.hardtanh(x, -3, 3)": lambda x: F.hardtanh(x, -3.0, 3.0),
       "F.hardshrink(x, 0.5)": lambda x: F.hardshrink(x, 0.5), "F.softshrink(x, 0.5)": lambda x: F.softshrink(x, 0.5), "torch.clamp(x, -1, 1)": lambda x: torch.clamp(x, -1.0, 1.0),
       "F.relu(x)": lambda x: F.relu(x), "F.threshold(x, 0.5, 0)": lambda x: F.threshold(x, 0.5, 0.0), "F.hardswish(x)": lambda x: F.hardswish(x), "F.hardsigmoid(x)": lambda x: F.hardsigmoid(x), "F.leaky_relu(x)": lambda x: F.leaky_relu(x),
       "F.relu6(F.relu(x))  (relu output exactly 0)": lambda x: F.relu6(F.relu(x))}
def grad(f, x):
    x = x.clone().requires_grad_(); f(x).sum().backward(); return x.grad
for name, f in fns.items():
    torch._dynamo.reset()
    e = grad(f, x); c = grad(torch.compile(f), x)
    same = torch.equal(e, c)
    print(f"{'  ' if same else '!!'} {name:44s} x={x.tolist()}\n{'':47s} eager grad    {e.tolist()}\n{'':47s} compiled grad {c.tolist()}", flush=True)
