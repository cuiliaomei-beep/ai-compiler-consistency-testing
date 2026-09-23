import os, sys
sys.path.insert(0, os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
try:
    from tcc.compat import ensure_msvc_env; ensure_msvc_env()
except Exception:
    pass
import torch, torch.nn.functional as F
print("torch", torch.__version__)
torch.manual_seed(0)
base = torch.randperm(1 * 2 * 3 * 6 * 5).float().reshape(1, 2, 3, 6, 5)          # distinct values: no ties

def layouts(x):
    yield "contiguous", x
    yield "transposed(-1,-2)", x.transpose(-1, -2).contiguous().transpose(-1, -2)
    yield "channels_last_3d", x.contiguous(memory_format=torch.channels_last_3d)
    yield "transposed(2,3)", x.transpose(2, 3).contiguous().transpose(2, 3)

print("--- max_pool3d(return_indices=True): values and indices")
f = lambda t: F.max_pool3d(t, 2, return_indices=True)
for name, x in layouts(base):
    ev, ei = f(x)
    row = [f"{name:18s} strides {tuple(x.stride())}"]
    for b in ("aot_eager", "inductor"):
        torch._dynamo.reset()
        cv, ci = torch.compile(f, backend=b)(x)
        row.append(f"{b}: values {'same' if torch.equal(ev, cv) else 'DIFF'}, indices {'same' if torch.equal(ei, ci) else 'DIFF ' + str(ei.flatten()[:4].tolist()) + ' vs ' + str(ci.flatten()[:4].tolist())}")
    # are the compiled indices valid w.r.t. the logical (contiguous) input?  gather must reproduce the values
    ok_e = torch.equal(x.contiguous().flatten(2).gather(2, ei.flatten(2)).view_as(ev), ev)
    ok_c = torch.equal(x.contiguous().flatten(2).gather(2, ci.flatten(2)).view_as(ev), ev)
    print(" | ".join(row), f"| gather(x, idx)==values: eager {ok_e}, inductor {ok_c}")

print("--- max_unpool3d(max_pool3d(x)) round trip and gradient of adaptive_max_pool3d")
for name, x in layouts(base):
    g = lambda t: F.adaptive_max_pool3d(t, (2, 2, 2))
    xe = x.detach().clone(memory_format=torch.preserve_format).requires_grad_(); g(xe).sum().backward()
    torch._dynamo.reset()
    xc = x.detach().clone(memory_format=torch.preserve_format).requires_grad_(); torch.compile(g)(xc).sum().backward()
    print(f"{name:18s} adaptive_max_pool3d grad: nonzeros eager {int(xe.grad.count_nonzero())} compiled {int(xc.grad.count_nonzero())}  equal={torch.equal(xe.grad, xc.grad)}  max diff {(xe.grad - xc.grad).abs().max().item():.3g}")
    h = lambda t: F.max_pool3d(t, 2)
    xe = x.detach().clone(memory_format=torch.preserve_format).requires_grad_(); h(xe).sum().backward()
    torch._dynamo.reset()
    xc = x.detach().clone(memory_format=torch.preserve_format).requires_grad_(); torch.compile(h)(xc).sum().backward()
    print(f"{'':18s} max_pool3d grad:          equal={torch.equal(xe.grad, xc.grad)}  max diff {(xe.grad - xc.grad).abs().max().item():.3g}")
