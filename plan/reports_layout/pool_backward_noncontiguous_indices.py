"""Eager ATen pooling backward kernels called with a non-contiguous (channels_last) `indices` tensor."""
import torch, torch.nn.functional as F
print("torch", torch.__version__)
CL3, CL2 = torch.channels_last_3d, torch.channels_last
x3 = torch.randperm(240).float().reshape(1, 4, 4, 3, 5)
x2 = torch.randperm(120).float().reshape(1, 4, 6, 5)
A = torch.ops.aten
cases = []
v, i = F.adaptive_max_pool3d(x3, (2, 3, 5), return_indices=True)
cases.append(("adaptive_max_pool3d_backward", lambda go, idx: A.adaptive_max_pool3d_backward(go, x3, idx), v, i, CL3))
v, i = F.adaptive_max_pool2d(x2, (3, 5), return_indices=True)
cases.append(("adaptive_max_pool2d_backward", lambda go, idx: A.adaptive_max_pool2d_backward(go, x2, idx), v, i, CL2))
v, i = F.max_pool3d(x3, 2, 1, return_indices=True)
cases.append(("max_pool3d_with_indices_backward", lambda go, idx: A.max_pool3d_with_indices_backward(go, x3, [2, 2, 2], [1, 1, 1], [0, 0, 0], [1, 1, 1], False, idx), v, i, CL3))
v, i = F.max_pool2d(x2, 2, 1, return_indices=True)
cases.append(("max_pool2d_with_indices_backward", lambda go, idx: A.max_pool2d_with_indices_backward(go, x2, [2, 2], [1, 1], [0, 0], [1, 1], False, idx), v, i, CL2))
v, i = F.fractional_max_pool2d(x2, 2, output_size=(3, 3), return_indices=True, _random_samples=torch.full((1, 4, 2), 0.5))
cases.append(("fractional_max_pool2d_backward", lambda go, idx: A.fractional_max_pool2d_backward(go, x2, [2, 2], [3, 3], idx), v, i, CL2))
v, i = F.fractional_max_pool3d(torch.cat([x3, x3], 3), 2, output_size=(2, 2, 2), return_indices=True, _random_samples=torch.full((1, 4, 3), 0.5))
cases.append(("fractional_max_pool3d_backward", lambda go, idx: A.fractional_max_pool3d_backward(go, torch.cat([x3, x3], 3), [2, 2, 2], [2, 2, 2], idx), v, i, CL3))
for name, fn, v, idx, fmt in cases:
    go = torch.arange(1.0, v.numel() + 1).reshape(v.shape)
    ref = fn(go, idx)
    idx_nc = idx.contiguous(memory_format=fmt)
    assert torch.equal(idx_nc, idx) and not idx_nc.is_contiguous()
    got = fn(go, idx_nc)
    print(f"{name:34s} indices strides {str(tuple(idx_nc.stride())):22s} same gradient as with contiguous indices: {torch.equal(ref, got)}"
          + ("" if torch.equal(ref, got) else f"   (max diff {(ref - got).abs().max().item():.0f})"))
v, i = F.max_pool2d(x2, 2, 2, return_indices=True)
ref = F.max_unpool2d(v, i, 2); got = F.max_unpool2d(v, i.contiguous(memory_format=CL2), 2)
print(f"{'max_unpool2d (forward)':34s} same result with channels_last indices: {torch.equal(ref, got)}")
v, i = F.max_pool3d(x3, 2, 1, return_indices=True)
ref = F.max_unpool3d(v, i, 2, 1); got = F.max_unpool3d(v, i.contiguous(memory_format=CL3), 2, 1)
print(f"{'max_unpool3d (forward)':34s} same result with channels_last_3d indices: {torch.equal(ref, got)}")
