import os, sys
sys.path.insert(0, os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
try:
    from tcc.compat import ensure_msvc_env; ensure_msvc_env()
except Exception:
    pass
import torch, torch.nn.functional as F
print("torch", torch.__version__)
torch.manual_seed(0)

def valid(x, v, idx, nd):
    return torch.equal(x.contiguous().flatten(-nd).gather(-1, idx.flatten(-nd)).view_as(v), v)

def variants(x):
    yield "contiguous", x
    yield "transposed last two", x.transpose(-1, -2).contiguous().transpose(-1, -2)
    yield "channels_last", x.contiguous(memory_format=torch.channels_last_3d if x.dim() == 5 else torch.channels_last)
    yield "sliced [..., ::2]", torch.cat([x, x], -1).reshape(*x.shape[:-1], 2, x.shape[-1]).transpose(-1, -2).reshape(*x.shape[:-1], -1)[..., ::2]

for nd, pool, shape in ((3, F.max_pool3d, (1, 2, 3, 6, 5)), (2, F.max_pool2d, (1, 2, 6, 5))):
    x0 = torch.randperm(int(torch.tensor(shape).prod())).float().reshape(shape)
    for ceil in (False, True):
        f = lambda t: pool(t, kernel_size=3, stride=2, ceil_mode=ceil, return_indices=True)
        for lname, x in variants(x0):
            ev, ei = f(x)
            out = []
            for b in ("aot_eager", "inductor"):
                torch._dynamo.reset()
                cv, ci = torch.compile(f, backend=b)(x)
                out.append(f"{b}: values {'ok' if torch.equal(ev, cv) else 'DIFF'} indices {'ok' if torch.equal(ei, ci) else 'DIFF'} valid={valid(x, cv, ci, nd)}")
            # gradient through the pooled values
            xe = x.detach().clone(memory_format=torch.preserve_format).requires_grad_(); f(xe)[0].sum().backward()
            torch._dynamo.reset()
            xc = x.detach().clone(memory_format=torch.preserve_format).requires_grad_(); torch.compile(f)(xc)[0].sum().backward()
            print(f"max_pool{nd}d ceil={ceil!s:5s} {lname:20s} strides {str(tuple(x.stride())):22s} | " + " | ".join(out) + f" | grad equal={torch.equal(xe.grad, xc.grad)}")
