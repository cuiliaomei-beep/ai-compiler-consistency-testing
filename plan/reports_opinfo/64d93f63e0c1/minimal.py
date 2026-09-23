import torch
torch.manual_seed(0)

def opinfo_max_pool2d_with_indices_backward(*args):
    return torch.max_pool2d_with_indices_backward(*args, **{'kernel_size': (3, 2), 'stride': (2, 1), 'ceil_mode': False, 'padding': 1, 'dilation': (1, 2), 'return_indices': True})

args = (torch.randn(2, 2, 6, 6)  # NOTE: non-contiguous in the failing run,)

eager = opinfo_max_pool2d_with_indices_backward(*args)
torch._dynamo.reset()
compiled = torch.compile(opinfo_max_pool2d_with_indices_backward, backend='eager')(*args)
print('eager   :', eager)
print('compiled:', compiled)
