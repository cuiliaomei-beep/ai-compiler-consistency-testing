"""PR-driven leads: F.pad on channels_last input (output strides eager vs compiled), linalg.pinv complex gradient."""
import os, sys
sys.path.insert(0, os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
try:
    from tcc.compat import ensure_msvc_env; ensure_msvc_env()
except Exception:
    pass
import torch, torch.nn.functional as F
print("torch", torch.__version__)
torch._dynamo.config.recompile_limit = 1000
x = torch.randn(2, 3, 5, 5).contiguous(memory_format=torch.channels_last)
for mode in ("constant", "reflect", "replicate", "circular"):
    for pad in ((1, 1, 1, 1), (1, 0), (0, 0, 1, 1)):
        fn = lambda t, mode=mode, pad=pad: F.pad(t, pad, mode=mode)
        try:
            e = fn(x)
        except Exception as ex:
            print(f"[pad {mode} {pad}] eager raises {type(ex).__name__}"); continue
        torch._dynamo.reset()
        outs = {}
        for b in ("aot_eager", "inductor"):
            try:
                c = torch.compile(fn, backend=b)(x); outs[b] = (c.stride(), torch.equal(c, e))
            except Exception as ex:
                outs[b] = f"raise {type(ex).__name__}"
        flag = "" if all(isinstance(v, tuple) and v[0] == e.stride() for v in outs.values()) else "   <-- STRIDE DIFF"
        print(f"[pad {mode} {pad}] eager stride={e.stride()} | " + " | ".join(f"{k}={v}" for k, v in outs.items()) + flag)

# pinv gradient, real vs complex
def pinv_grad(fn, a):
    a = a.clone().requires_grad_()
    out = fn(a)
    (out.abs() ** 2).sum().backward() if a.is_complex() else out.pow(2).sum().backward()
    return a.grad
g = torch.Generator().manual_seed(0)
for dt in (torch.float32, torch.complex64):
    for shape in ((50, 2), (3, 2), (4, 4)):
        base = torch.randn(shape, generator=g)
        a = (torch.complex(base, torch.randn(shape, generator=g)) if dt.is_complex else base).to(dt)
        truth = pinv_grad(torch.linalg.pinv, a.to(torch.complex128 if dt.is_complex else torch.float64))
        ge = pinv_grad(torch.linalg.pinv, a)
        torch._dynamo.reset()
        try:
            gc = pinv_grad(torch.compile(torch.linalg.pinv), a)
            ee = (ge.to(truth.dtype) - truth).abs().max().item(); ec = (gc.to(truth.dtype) - truth).abs().max().item()
            flag = "   <-- DIFF" if ec > max(4 * ee, 1e-4) else ""
            print(f"[pinv grad {str(dt).split('.')[-1]} {shape}] eager_err={ee:.2e} compiled_err={ec:.2e}{flag}")
        except Exception as ex:
            print(f"[pinv grad {str(dt).split('.')[-1]} {shape}] compiled raises {type(ex).__name__}: {str(ex)[:100]}")
