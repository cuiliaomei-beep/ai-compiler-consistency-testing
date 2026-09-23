import os, sys
sys.path.insert(0, os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
try:
    from tcc.compat import ensure_msvc_env; ensure_msvc_env()
except Exception:
    pass
import torch, torch.nn.functional as F
print("torch", torch.__version__)
torch.manual_seed(0)

def tr(x):
    return x.transpose(-1, -2).contiguous().transpose(-1, -2)

cases = [
    ("max_pool2d k=3 (window 9, lowered)",    lambda t: F.max_pool2d(t, 3, 2, return_indices=True), (1, 2, 12, 10), 2),
    ("max_pool2d k=6 (window 36, fallback)",  lambda t: F.max_pool2d(t, 6, 2, return_indices=True), (1, 2, 12, 10), 2),
    ("max_pool3d k=2 (window 8, lowered)",    lambda t: F.max_pool3d(t, 2, 2, return_indices=True), (1, 2, 4, 6, 5), 3),
    ("max_pool3d k=3 (window 27, fallback)",  lambda t: F.max_pool3d(t, 3, 2, return_indices=True), (1, 2, 5, 6, 5), 3),
]
for name, f, shape, nd in cases:
    n = 1
    for s in shape: n *= s
    x = tr(torch.randperm(n).float().reshape(shape))
    ev, ei = f(x)
    torch._dynamo.reset()
    cv, ci = torch.compile(f)(x)
    ok = torch.equal(x.contiguous().flatten(-nd).gather(-1, ci.flatten(-nd)).view_as(cv), cv)
    print(f"{name:38s} values equal={torch.equal(ev, cv)} indices equal={torch.equal(ei, ci)} compiled indices valid={ok}")
    print(f"{'':38s} eager strides: values {tuple(ev.stride())} indices {tuple(ei.stride())} | compiled: values {tuple(cv.stride())} indices {tuple(ci.stride())}")
    if not torch.equal(ei, ci):
        # is the compiled index tensor a stride-permuted view of the right data?
        same_multiset = torch.equal(ei.flatten().sort().values, ci.flatten().sort().values)
        print(f"{'':38s} same multiset of indices: {same_multiset}; eager[0,0] {ei[0, 0].flatten()[:6].tolist()} compiled[0,0] {ci[0, 0].flatten()[:6].tolist()}")
