import torch
torch.manual_seed(0)

def opinfo_new_empty_strided(*args):
    return torch.new_empty_strided(*args, (2, 3), (7, 8), dtype=torch.float32, device='cpu')

args = (torch.randn(5),)

eager = opinfo_new_empty_strided(*args)
torch._dynamo.reset()
compiled = torch.compile(opinfo_new_empty_strided, backend='eager')(*args)
print('eager   :', eager)
print('compiled:', compiled)
