import torch
torch.manual_seed(0)

def compiled_func(x, thr):
    return torch.bucketize(torch.rsqrt(x), thr, right=True)

args = (torch.randn(1).requires_grad_(True), torch.randn(1))

eager = compiled_func(*args)
torch._dynamo.reset()
compiled = torch.compile(compiled_func, backend='inductor')(*args)
print('eager   :', eager)
print('compiled:', compiled)
