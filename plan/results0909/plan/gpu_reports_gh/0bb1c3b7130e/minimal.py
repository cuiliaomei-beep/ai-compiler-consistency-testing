import torch
torch.manual_seed(0)

def fn(src, index, base_tensor):
    src = src + 10
    base_tensor.scatter_(0, index, src)
    return base_tensor.clone() + 1

args = (torch.randn(1).requires_grad_(True), torch.randint(0, 4, (1,)), torch.randn(1))

eager = fn(*args)
torch._dynamo.reset()
compiled = torch.compile(fn, backend='inductor')(*args)
print('eager   :', eager)
print('compiled:', compiled)
