import os, sys
sys.path.insert(0, os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
try:
    from tcc.compat import ensure_msvc_env; ensure_msvc_env()
except Exception:
    pass
import torch, torch.nn.functional as F
from torch._subclasses.fake_tensor import FakeTensorMode
print("torch", torch.__version__)
x = torch.randperm(240).float().reshape(1, 4, 4, 3, 5).contiguous(memory_format=torch.channels_last_3d)
for osize in ((4, 3, 5), (4, 3, 4), (2, 3, 5), (4, 3, 1)):
    f = lambda t: F.adaptive_max_pool3d(t, osize, return_indices=True)
    ev, ei = f(x)
    with FakeTensorMode():
        fv, fi = f(torch.empty_strided(x.shape, x.stride()))
    torch._dynamo.reset()
    cv, ci = torch.compile(f)(x)
    ge = x.detach().clone(memory_format=torch.preserve_format).requires_grad_(); o = f(ge)[0]; (o * torch.arange(1., o.numel() + 1).reshape(o.shape)).sum().backward()
    torch._dynamo.reset()
    gc = x.detach().clone(memory_format=torch.preserve_format).requires_grad_(); o = torch.compile(f)(gc)[0]; (o * torch.arange(1., o.numel() + 1).reshape(o.shape)).sum().backward()
    print(f"output_size={osize}: eager strides values {tuple(ev.stride())} indices {tuple(ei.stride())} | fake (meta) values {tuple(fv.stride())} indices {tuple(fi.stride())}")
    print(f"{'':22s} compiled values equal={torch.equal(ev, cv)} indices equal={torch.equal(ei, ci)} grad equal={torch.equal(ge.grad, gc.grad)}")
