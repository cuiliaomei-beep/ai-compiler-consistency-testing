import torch
torch.manual_seed(0)

def foo(q, k, v, a):
    qk = q @ k.transpose(-2, -1) / 1.0
    qk = qk + a
    attn = torch.softmax(qk, dim=-1)
    output = attn @ v
    return output

args = (torch.randn(1, 1, 64, 64).to(torch.float16), torch.randn(1, 1, 64, 64).to(torch.float16), torch.randn(1, 1, 64, 64).to(torch.float16), torch.randn(64, 64).to(torch.float16))

eager = foo(*args)
torch._dynamo.reset()
compiled = torch.compile(foo, backend='inductor')(*args)
print('eager   :', eager)
print('compiled:', compiled)
