import os, sys
sys.path.insert(0, os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
try:
    from tcc.compat import ensure_msvc_env; ensure_msvc_env()
except Exception:
    pass
import torch, torch.nn.functional as F
print("torch", torch.__version__)
x3 = torch.randperm(1 * 4 * 4 * 6 * 5).float().reshape(1, 4, 4, 6, 5)
x2 = torch.randperm(1 * 4 * 6 * 5).float().reshape(1, 4, 6, 5)
rs2, rs3 = torch.full((1, 4, 2), 0.5), torch.full((1, 4, 3), 0.5)
cases = [
    ("adaptive_max_pool3d((2, 3, 5))", lambda t: F.adaptive_max_pool3d(t, (2, 3, 5)), x3, torch.channels_last_3d),
    ("adaptive_max_pool2d((3, 5))",    lambda t: F.adaptive_max_pool2d(t, (3, 5)), x2, torch.channels_last),
    ("fractional_max_pool2d",          lambda t: F.fractional_max_pool2d(t, 2, output_size=(3, 3), _random_samples=rs2), x2, torch.channels_last),
    ("fractional_max_pool3d",          lambda t: F.fractional_max_pool3d(t, 2, output_size=(2, 3, 3), _random_samples=rs3), x3, torch.channels_last_3d),
    ("max_pool3d(2, 1)",               lambda t: F.max_pool3d(t, 2, 1), x3, torch.channels_last_3d),
]
for name, f, x, fmt in cases:
    for lname, xin in (("contiguous", x), ("channels_last", x.contiguous(memory_format=fmt))):
        grads = []
        for b in (None, "aot_eager", "inductor"):
            torch._dynamo.reset()
            t = xin.detach().clone(memory_format=torch.preserve_format).requires_grad_()
            out = (f if b is None else torch.compile(f, backend=b))(t)
            (out * torch.arange(1.0, out.numel() + 1).reshape(out.shape)).sum().backward()
            grads.append(t.grad.clone())
        print(f"{name:32s} {lname:14s} grad: aot_eager==eager {torch.equal(grads[0], grads[1])}  inductor==eager {torch.equal(grads[0], grads[2])}"
              + ("" if torch.equal(grads[0], grads[2]) else f"   <-- max diff {(grads[0] - grads[2]).abs().max().item():.0f}"))
