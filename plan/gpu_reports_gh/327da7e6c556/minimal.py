import torch
torch.manual_seed(0)

def cu_seqlens(mask):
    lengths = mask.sum(dim=-1, dtype=torch.int32)
    return F.pad(torch.cumsum(lengths, dim=0, dtype=torch.int32), (1, 0))

args = (torch.randint(0, 4, (1, 16384,)).to(torch.bool),)

eager = cu_seqlens(*args)
torch._dynamo.reset()
compiled = torch.compile(cu_seqlens, backend='inductor')(*args)
print('eager   :', eager)
print('compiled:', compiled)
