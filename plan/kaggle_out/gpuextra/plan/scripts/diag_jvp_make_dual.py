"""torch.func.jvp inside torch.compile: INTERNAL ASSERT in _make_dual (InferenceMode::is_enabled() && primal.is_inference() ...) for addr / quantile / nanquantile."""
import os, sys
sys.path.insert(0, os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
try:
    from tcc.compat import ensure_msvc_env; ensure_msvc_env()
except Exception:
    pass
import torch
print("torch", torch.__version__)
torch.manual_seed(0)
x, t = torch.randn(3, 4), torch.randn(3, 4)
v1, v2 = torch.randn(3), torch.randn(4)
OPS = {
    "addr": lambda a: torch.addr(a, v1, v2),
    "addr(beta=0.5, alpha=2)": lambda a: torch.addr(a, v1, v2, beta=0.5, alpha=2.0),
    "quantile q=0.5": lambda a: torch.quantile(a, 0.5),
    "quantile q=0.3 dim=1": lambda a: torch.quantile(a, 0.3, dim=1),
    "quantile q tensor": lambda a: torch.quantile(a, torch.tensor([0.25, 0.75]), dim=0),
    "nanquantile q=0.5": lambda a: torch.nanquantile(a, 0.5),
    "median dim": lambda a: torch.median(a, dim=1)[0],
    "kthvalue": lambda a: torch.kthvalue(a, 2, dim=1)[0],
    "sort values": lambda a: torch.sort(a, dim=1)[0],
}
for name, f in OPS.items():
    ref = torch.func.jvp(f, (x,), (t,))[1]
    out = []
    for b in ("eager", "aot_eager", "inductor"):
        torch._dynamo.reset()
        try:
            r = torch.compile(lambda x, t: torch.func.jvp(f, (x,), (t,)), backend=b)(x, t)[1]
            out.append(f"{b}=ok({(r - ref).abs().max().item():.0e})")
        except Exception as e:
            msg = str(e).splitlines()[0]
            out.append(f"{b}=raise {'INTERNAL ASSERT _make_dual' if 'is_inference' in msg else type(e).__name__ + ': ' + msg[:60]}")
    print(f"[{name}] " + " | ".join(out))
