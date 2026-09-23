"""Direct reproducers for the two nightly-only grad leads (nll_loss channels_last, quantile prime_dim0)."""
import os, sys
sys.path.insert(0, os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
from tcc.compat import ensure_msvc_env
ensure_msvc_env()
import torch
import torch.nn.functional as F
from torch.testing._internal.common_methods_invocations import op_db

print("torch", torch.__version__)
torch.manual_seed(0)


def show_exc(e):
    return f"{type(e).__name__}: {str(e).splitlines()[0][:140]}"


# --- lead 1: nll_loss on a channels_last 4-D input, forward + backward ---
def nll(x, t):
    return F.nll_loss(x, t)


for tag, mk in [("contiguous", lambda: torch.randn(2, 3, 2, 2)),
                ("channels_last", lambda: torch.randn(2, 3, 2, 2).to(memory_format=torch.channels_last))]:
    t = torch.randint(0, 3, (2, 2, 2))
    for name, fn in [("eager", nll), ("inductor", torch.compile(nll)), ("aot_eager", torch.compile(nll, backend="aot_eager"))]:
        x = mk().requires_grad_()
        try:
            y = fn(x, t)
            y.backward()
            print(f"[nll_loss {tag}] {name:<9}: loss={y.item():.4f} grad_stride={x.grad.stride()} ok")
        except Exception as e:
            print(f"[nll_loss {tag}] {name:<9}: {show_exc(e)}")

# --- lead 2: quantile gradient with a prime-sized leading dim, all OpInfo samples ---
qi = [o for o in op_db if o.name == "quantile"][0]
n = 0
for s in qi.sample_inputs("cpu", torch.float32, requires_grad=False):
    x0 = s.input
    if x0.dim() == 0:
        continue
    shape = list(x0.shape); shape[0] = 7
    args, kw = s.args, dict(s.kwargs)
    def run(fn, dtype):
        x = torch.randn(*shape, dtype=dtype).requires_grad_()
        a = [t.to(dtype) if isinstance(t, torch.Tensor) and t.is_floating_point() else t for t in args]
        out = fn(x, *a, **kw)
        out.sum().backward()
        return x.grad
    try:
        g64 = run(torch.quantile, torch.float64)
        ge = run(torch.quantile, torch.float32)
        gc = run(torch.compile(torch.quantile), torch.float32)
        ee = (ge.double() - g64).abs().max().item(); ec = (gc.double() - g64).abs().max().item()
        flag = "  <-- MISMATCH" if ec > max(4 * ee, 1e-5) else ""
        print(f"[quantile] shape={tuple(shape)} args={[getattr(a,'shape',a) for a in args]} kw={kw}: eager_err={ee:.2e} compiled_err={ec:.2e}{flag}")
        n += 1
    except Exception as e:
        print(f"[quantile] shape={tuple(shape)} kw={kw}: {show_exc(e)}")
print("samples", n)
