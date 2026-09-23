"""torch.compile(backend="eager") of torch.func.jvp over torch.addr -> INTERNAL ASSERT in _make_dual; aot_eager / inductor fine."""
import os, sys
sys.path.insert(0, os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
try:
    from tcc.compat import ensure_msvc_env; ensure_msvc_env()
except Exception:
    pass
import torch
print("torch", torch.__version__)
torch.manual_seed(0)
v1, v2 = torch.randn(3), torch.randn(4)
x, t = torch.randn(3, 4), torch.randn(3, 4)
OPS = {"addr": lambda a: torch.addr(a, v1, v2), "addr_beta_alpha": lambda a: torch.addr(a, v1, v2, beta=0.5, alpha=2.0),
       "addmm": lambda a: torch.addmm(a, torch.randn(3, 2), torch.randn(2, 4)), "addcmul": lambda a: torch.addcmul(a, a, a),
       "baddbmm": lambda a: torch.baddbmm(a.unsqueeze(0), torch.randn(1, 3, 2), torch.randn(1, 2, 4)), "addbmm": lambda a: torch.addbmm(a, torch.randn(2, 3, 5), torch.randn(2, 5, 4)),
       "addmv": lambda a: torch.addmv(a[:, 0], torch.randn(3, 4), v2), "outer_plus": lambda a: a + torch.outer(v1, v2)}
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
            out.append(f"{b}=raise {'INTERNAL ASSERT _make_dual' if 'is_inference' in msg else type(e).__name__}")
    print(f"[{name}] " + " | ".join(out))
