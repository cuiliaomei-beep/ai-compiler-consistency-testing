"""Compiled optimizer.step(): which Adam hyper-parameter change between steps is not picked up?"""
import os, sys
sys.path.insert(0, os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
try:
    from tcc.compat import ensure_msvc_env; ensure_msvc_env()
except Exception:
    pass
import torch
print("torch", torch.__version__)

def run(compiled, change, backend="eager", opt_cls=torch.optim.Adam):
    torch._dynamo.reset()
    p = torch.nn.Parameter(torch.tensor([1.0, -2.0, 3.0]))
    opt = opt_cls([p], lr=0.1)
    step = torch.compile(lambda: opt.step(), backend=backend) if compiled else opt.step
    hist = []
    for k in range(4):
        if k == 2:
            change(opt.param_groups[0])
        opt.zero_grad(); (p ** 2).sum().backward(); step()
        hist.append(p.detach().clone())
    return hist

changes = {"lr 0.1 -> 0.5": lambda g: g.__setitem__("lr", 0.5), "betas -> (0.5, 0.5)": lambda g: g.__setitem__("betas", (0.5, 0.5)),
           "eps -> 1.0": lambda g: g.__setitem__("eps", 1.0), "weight_decay -> 0.5": lambda g: g.__setitem__("weight_decay", 0.5),
           "no change": lambda g: None}
for cls in (torch.optim.Adam, torch.optim.AdamW, torch.optim.SGD, torch.optim.RMSprop):
    for name, ch in changes.items():
        if cls in (torch.optim.SGD,) and ("betas" in name or "eps" in name):
            continue
        if cls is torch.optim.RMSprop and "betas" in name:
            continue
        e, c = run(False, ch, opt_cls=cls), run(True, ch, opt_cls=cls)
        diffs = [float((a - b).abs().max()) for a, b in zip(e, c)]
        print(f"{cls.__name__:8s} {name:22s} max |eager - compiled| per step: {['%.2e' % d for d in diffs]}")
