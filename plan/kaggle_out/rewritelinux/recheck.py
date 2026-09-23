import torch
print('torch', torch.__version__, flush=True)
print()
print('===== draft 14 block 0', flush=True)
try:
    import torch, torch.nn.functional as F
    
    torch.manual_seed(0)
    f = lambda t: F.adaptive_max_pool3d(t, (2, 3, 5))
    x = torch.randperm(1 * 4 * 4 * 6 * 5).float().reshape(1, 4, 4, 6, 5)
    for name, xin in (("contiguous", x), ("channels_last_3d", x.contiguous(memory_format=torch.channels_last_3d))):
        grads = []
        for backend in (None, "aot_eager", "inductor"):
            torch._dynamo.reset()
            t = xin.detach().clone(memory_format=torch.preserve_format).requires_grad_()
            out = (f if backend is None else torch.compile(f, backend=backend))(t)
            (out * torch.arange(1.0, out.numel() + 1).reshape(out.shape)).sum().backward()
            grads.append(t.grad.clone())
        print(f"{name:17s} aot_eager == eager: {torch.equal(grads[0], grads[1])}   inductor == eager: {torch.equal(grads[0], grads[2])}"
              f"   max diff {(grads[0] - grads[2]).abs().max().item():.0f}")
except Exception as e:
    print('EXC', type(e).__name__, str(e)[:300])
print()
print('===== draft 14 block 1', flush=True)
try:
    import torch, torch.nn.functional as F
    
    torch.manual_seed(0)
    A = torch.ops.aten
    x3 = torch.randperm(240).float().reshape(1, 4, 4, 3, 5)
    x3w = torch.cat([x3, x3], 3)
    x2 = torch.randperm(120).float().reshape(1, 4, 6, 5)
    rs2, rs3 = torch.full((1, 4, 2), 0.5), torch.full((1, 4, 3), 0.5)
    cases = []
    v, i = F.adaptive_max_pool3d(x3, (2, 3, 5), return_indices=True)
    cases.append(("adaptive_max_pool3d_backward", lambda go, idx: A.adaptive_max_pool3d_backward(go, x3, idx), v, i, torch.channels_last_3d))
    v, i = F.adaptive_max_pool2d(x2, (3, 5), return_indices=True)
    cases.append(("adaptive_max_pool2d_backward", lambda go, idx: A.adaptive_max_pool2d_backward(go, x2, idx), v, i, torch.channels_last))
    v, i = F.max_pool3d(x3, 2, 1, return_indices=True)
    cases.append(("max_pool3d_with_indices_backward", lambda go, idx: A.max_pool3d_with_indices_backward(go, x3, [2, 2, 2], [1, 1, 1], [0, 0, 0], [1, 1, 1], False, idx), v, i, torch.channels_last_3d))
    v, i = F.fractional_max_pool2d(x2, 2, output_size=(3, 3), return_indices=True, _random_samples=rs2)
    cases.append(("fractional_max_pool2d_backward", lambda go, idx: A.fractional_max_pool2d_backward(go, x2, [2, 2], [3, 3], idx), v, i, torch.channels_last))
    v, i = F.fractional_max_pool3d(x3w, 2, output_size=(2, 2, 2), return_indices=True, _random_samples=rs3)
    cases.append(("fractional_max_pool3d_backward", lambda go, idx: A.fractional_max_pool3d_backward(go, x3w, [2, 2, 2], [2, 2, 2], idx), v, i, torch.channels_last_3d))
    for name, fn, v, idx, fmt in cases:
        go = torch.arange(1.0, v.numel() + 1).reshape(v.shape)
        idx_nc = idx.contiguous(memory_format=fmt)                      # equal values, channels_last strides
        same = torch.equal(fn(go, idx), fn(go, idx_nc))
        print(f"{name:34s} indices strides {str(tuple(idx_nc.stride())):22s} same gradient as with contiguous indices: {same}")
except Exception as e:
    print('EXC', type(e).__name__, str(e)[:300])
print()
print('===== draft 15 block 0', flush=True)
try:
    import torch
    
    def scale(logits, temperature):
        return logits / temperature
    
    def momentum_step(buf, momentum):
        return buf * momentum
    
    def add_bias(x, bias):
        return x + bias
    
    for name, f, arg in (("logits / 1.0", scale, 1.0), ("logits / 0.9", scale, 0.9),
                         ("buf * 1.0", momentum_step, 1.0), ("x + 0", add_bias, 0)):
        for backend in ("eager (no compile)", "aot_eager", "inductor"):
            torch._dynamo.reset()
            g = f if backend.startswith("eager") else torch.compile(f, backend=backend)
            x = torch.ones(3)
            out = g(x, arg)
            same = out is x
            out.add_(5)                     # the caller updates the *result* in place
            print(f"{name:13s} {backend:19s} out is x: {str(same):5s}  x afterwards: {x.tolist()}")
except Exception as e:
    print('EXC', type(e).__name__, str(e)[:300])

print()
print('===== int abs(abs(x)) (MSVC-only?)', flush=True)
import torch
for dev in (["cpu"] + (["cuda"] if torch.cuda.is_available() else [])):
    for dt in (torch.int8, torch.int16, torch.int32, torch.int64):
        for n in (5, 40):
            x = (torch.arange(n) - n // 2).to(dt).to(dev)
            f = lambda t: t.abs().abs()
            torch._dynamo.reset()
            print(dev, dt, n, "equal", torch.equal(f(x), torch.compile(f)(x)), flush=True)
print()
print('===== draft 15 on CUDA', flush=True)
if torch.cuda.is_available():
    for name, f in (("x / 1.0", lambda x: x / 1.0), ("x * 1.0", lambda x: x * 1.0), ("x + 0", lambda x: x + 0), ("x / 0.9", lambda x: x / 0.9)):
        for backend in ("aot_eager", "inductor"):
            torch._dynamo.reset()
            x = torch.ones(3, device="cuda")
            out = torch.compile(f, backend=backend)(x)
            same = out is x
            out.add_(5)
            print("cuda", name, backend, "out is x:", same, "x afterwards:", x.tolist(), flush=True)
    print('===== draft 14 on CUDA (adaptive_max_pool3d channels_last_3d grad)', flush=True)
    import torch.nn.functional as F
    torch.manual_seed(0)
    x0 = torch.randperm(2 * 3 * 6 * 7 * 8).float().reshape(2, 3, 6, 7, 8).cuda().contiguous(memory_format=torch.channels_last_3d)
    f = lambda t: F.adaptive_max_pool3d(t, (3, 3, 3))
    xe = x0.clone(memory_format=torch.preserve_format).requires_grad_(); f(xe).sum().backward()
    torch._dynamo.reset()
    xc = x0.clone(memory_format=torch.preserve_format).requires_grad_(); torch.compile(f)(xc).sum().backward()
    print("cuda adaptive_max_pool3d chlast grad equal:", torch.equal(xe.grad, xc.grad), "max diff", (xe.grad - xc.grad).abs().max().item())
else:
    print("no cuda")
