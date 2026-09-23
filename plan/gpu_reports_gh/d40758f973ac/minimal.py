import torch
torch.manual_seed(0)

def fn(q, k, v):
    return F.scaled_dot_product_attention(q, k, v).sum()

args = (torch.randn(1, 1, 1, 33).requires_grad_(True), torch.randn(1, 1, 1, 33), torch.randn(1, 1, 1, 33))

eager = fn(*args)
torch._dynamo.reset()
compiled = torch.compile(fn, backend='inductor')(*args)
print('eager   :', eager)
print('compiled:', compiled)
