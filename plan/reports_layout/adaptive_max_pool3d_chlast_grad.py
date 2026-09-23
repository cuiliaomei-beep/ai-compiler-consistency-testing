import os, sys
sys.path.insert(0, os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
try:
    from tcc.compat import ensure_msvc_env; ensure_msvc_env()
except Exception:
    pass
import torch, torch.nn.functional as F
print("torch", torch.__version__)
x0 = torch.randperm(1 * 4 * 4 * 3 * 5).float().reshape(1, 4, 4, 3, 5)
w_shape = None
for oname, osize in (("(None,None,None)", (None, None, None)), ("(2,2,2)", (2, 2, 2)), ("(3,2,4)", (3, 2, 4))):
    for lname, x in (("contiguous", x0), ("channels_last_3d", x0.contiguous(memory_format=torch.channels_last_3d)),
                     ("transposed", x0.transpose(-1, -2).contiguous().transpose(-1, -2))):
        for fname, f in (("adaptive_max_pool3d", lambda t: F.adaptive_max_pool3d(t, osize)), ("adaptive_max_pool2d", lambda t: F.adaptive_max_pool2d(t[:, :, 0], osize[1:]))):
            res = []
            for b in (None, "aot_eager", "inductor"):
                torch._dynamo.reset()
                t = x.detach().clone(memory_format=torch.preserve_format).requires_grad_()
                out = (f if b is None else torch.compile(f, backend=b))(t)
                w = torch.arange(1.0, out.numel() + 1).reshape(out.shape)          # position-dependent weights expose misplaced gradients
                (out * w).sum().backward()
                res.append(t.grad.clone())
            print(f"{fname:20s} out={oname:17s} {lname:17s} grad aot_eager==eager {torch.equal(res[0], res[1])}  inductor==eager {torch.equal(res[0], res[2])}"
                  + ("" if torch.equal(res[0], res[2]) else f"   max diff {(res[0] - res[2]).abs().max().item():.3g}"))
