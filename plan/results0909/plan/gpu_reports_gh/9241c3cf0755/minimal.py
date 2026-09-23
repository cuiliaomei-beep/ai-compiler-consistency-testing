import torch
torch.manual_seed(0)

def kek(x):
    return torch.arange(
        0, 11, device=x.device, dtype=torch.int64
    ) * torch.tensor([int(1e9)], dtype=torch.int64, device=x.device)

args = (torch.randn(1).requires_grad_(True),)

eager = kek(*args)
torch._dynamo.reset()
compiled = torch.compile(kek, backend='inductor')(*args)
print('eager   :', eager)
print('compiled:', compiled)
