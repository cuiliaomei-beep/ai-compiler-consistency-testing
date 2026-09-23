import torch
torch.manual_seed(0)

def _noncontig(t):
    # same values, non-unit innermost stride (a strided view of a wider buffer)
    big = torch.empty(*t.shape[:-1], t.shape[-1] * 2, dtype=t.dtype)
    v = big[..., ::2]
    v.copy_(t)
    return v

def opinfo_max_pool2d_with_indices_backward(*args):
    return torch.max_pool2d_with_indices_backward(*args, kernel_size=3, stride=(2, 1), ceil_mode=True, padding=(1, 1), dilation=(1, 2), return_indices=True)

args = (_noncontig(torch.randn(2, 2, 3, 6)),)

eager = opinfo_max_pool2d_with_indices_backward(*args)
torch._dynamo.reset()
compiled = torch.compile(opinfo_max_pool2d_with_indices_backward, backend='eager')(*args)
print('eager   :', eager)
print('compiled:', compiled)
