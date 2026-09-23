import torch
torch.manual_seed(0)

def compiled_bmm(x, y):
    return torch.bmm(x, y)

args = (torch.randn(2, 8, 8).to(torch.float16), torch.randn(2, 8, 64))

eager = compiled_bmm(*args)
torch._dynamo.reset()
compiled = torch.compile(compiled_bmm, backend='inductor')(*args)
print('eager   :', eager)
print('compiled:', compiled)
