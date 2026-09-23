import torch
torch.manual_seed(0)

def mod_tiling(x):
    n = x.shape[0]
    if n % 16 == 0:
        return x.reshape(n // 16, 16, -1).sum(dim=1)
    pad = 16 - n % 16
    y = torch.cat([x, x[:pad]], dim=0)
    return y.reshape(-1, 16, x.shape[1]).sum(dim=1)

args = (torch.randn(17, 8),)

eager = mod_tiling(*args)
torch._dynamo.reset()
compiled = torch.compile(mod_tiling, backend='eager')(*args)
print('eager   :', eager)
print('compiled:', compiled)
