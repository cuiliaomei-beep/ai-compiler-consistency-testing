"""torch.compile(opt.step) with complex parameters and foreach=True: eager works, Inductor fails."""
import os, sys
sys.path.insert(0, os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
try:
    from tcc.compat import ensure_msvc_env; ensure_msvc_env()
except Exception:
    pass
import torch
print("torch", torch.__version__)


def trial(opt_cls, kw, dtype, backend):
    torch._dynamo.reset()
    g = torch.Generator().manual_seed(0)
    if dtype.is_complex:
        p = torch.nn.Parameter(torch.complex(torch.randn(3, 2, generator=g), torch.randn(3, 2, generator=g)).to(dtype))
    else:
        p = torch.nn.Parameter(torch.randn(3, 2, generator=g).to(dtype))
    opt = opt_cls([p], lr=0.1, **kw)
    p.grad = torch.ones_like(p)
    step = torch.compile(opt.step, backend=backend) if backend else opt.step
    try:
        step(); step()
        return f"ok {p.detach().flatten()[0].item():.4f}"
    except Exception as e:
        msg = str(e).splitlines()
        key = next((l for l in msg if "Error" in l and "raised" not in l), msg[0])
        return f"raise {type(e).__name__}: {key.strip()[:110]}"


for opt_cls, kw in [(torch.optim.SGD, {"foreach": True}), (torch.optim.SGD, {"foreach": False}), (torch.optim.SGD, {"foreach": True, "momentum": 0.9}),
                    (torch.optim.Adam, {"foreach": True}), (torch.optim.Adam, {"foreach": False}), (torch.optim.AdamW, {"foreach": True}),
                    (torch.optim.RMSprop, {"foreach": True}), (torch.optim.Adagrad, {"foreach": True})]:
    for dtype in (torch.complex64, torch.float32):
        res = {b or "eager": trial(opt_cls, kw, dtype, b) for b in (None, "eager", "aot_eager", "inductor")}
        flag = "" if len({v.split()[0] for v in res.values()}) == 1 else "   <-- DIFF"
        print(f"[{opt_cls.__name__} {kw} {str(dtype).split('.')[-1]}] " + " | ".join(f"{k}={v}" for k, v in res.items()) + flag)
