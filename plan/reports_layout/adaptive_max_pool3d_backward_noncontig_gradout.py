import torch, torch.nn.functional as F
print("torch", torch.__version__)
x = torch.randperm(240).float().reshape(1, 4, 4, 3, 5)
for osize in ((4, 3, 5), (2, 3, 5), (4, 3, 4), (2, 2, 2)):
    v, idx = F.adaptive_max_pool3d(x, osize, return_indices=True)
    go = torch.arange(1.0, v.numel() + 1).reshape(v.shape)
    go_cl = go.contiguous(memory_format=torch.channels_last_3d)          # same values, channels_last_3d strides
    a = torch.ops.aten.adaptive_max_pool3d_backward(go, x, idx)
    b = torch.ops.aten.adaptive_max_pool3d_backward(go_cl, x, idx)
    print(f"adaptive_max_pool3d_backward osize={osize}: grad_output strides {tuple(go_cl.stride())} -> same result as contiguous grad_output: {torch.equal(a, b)}"
          + ("" if torch.equal(a, b) else f"   max diff {(a - b).abs().max().item():.0f}"))
    # user-level eager reproduction: backward through a channels_last_3d upstream gradient
    xr = x.clone().requires_grad_()
    out = F.adaptive_max_pool3d(xr, osize)
    out.backward(go_cl)
    print(f"{'':10s} eager autograd with channels_last_3d upstream grad equals reference: {torch.equal(xr.grad, a)}")
x2 = torch.randperm(120).float().reshape(1, 4, 6, 5)
v, idx = F.adaptive_max_pool2d(x2, (3, 5), return_indices=True)
go = torch.arange(1.0, v.numel() + 1).reshape(v.shape)
print("adaptive_max_pool2d_backward, channels_last grad_output same as contiguous:",
      torch.equal(torch.ops.aten.adaptive_max_pool2d_backward(go, x2, idx), torch.ops.aten.adaptive_max_pool2d_backward(go.contiguous(memory_format=torch.channels_last), x2, idx)))
