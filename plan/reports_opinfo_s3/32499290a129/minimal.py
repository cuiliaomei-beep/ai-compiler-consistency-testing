import torch
torch.manual_seed(0)

def max_pool2d_backward(*args, kernel_size=(), stride=(), padding=(0,), dilation=(1,), ceil_mode=False, **kwargs):
    out, indices = torch.nn.functional.max_pool2d_with_indices(
        *args, kernel_size=kernel_size, stride=stride, padding=padding, dilation=dilation, ceil_mode=ceil_mode, return_indices=True)
    grad_out = torch.ones_like(out)
    if stride is None:
        stride = kernel_size
    out_b = torch.ops.aten.max_pool2d_with_indices_backward.default(
        grad_out, *args, kernel_size, stride, padding, dilation, ceil_mode, indices)
    return out_b

def opinfo_max_pool2d_with_indices_backward(*args):
    return max_pool2d_backward(*args, kernel_size=(3, 2), stride=2, ceil_mode=False, padding=0, dilation=(1, 2), return_indices=False)

args = (torch.randn(1, 2, 3, 6),)

eager = opinfo_max_pool2d_with_indices_backward(*args)
torch._dynamo.reset()
compiled = torch.compile(opinfo_max_pool2d_with_indices_backward, backend='eager')(*args)
print('eager   :', eager)
print('compiled:', compiled)
