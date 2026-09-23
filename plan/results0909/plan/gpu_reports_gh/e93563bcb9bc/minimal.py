import torch
torch.manual_seed(0)

def compiled_matmul(x, y):
    return torch.matmul(x, y)

args = (torch.randn(2, 8, 8).to(torch.float16), torch.randn(2, 8, 64))

eager = compiled_matmul(*args)
torch._dynamo.reset()
compiled = torch.compile(compiled_matmul, backend='inductor')(*args)
print('eager   :', eager)
print('compiled:', compiled)
