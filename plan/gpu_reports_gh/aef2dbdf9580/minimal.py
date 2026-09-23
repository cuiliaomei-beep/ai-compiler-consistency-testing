import torch
torch.manual_seed(0)

def f(mask, box):
        mask = torch.randn(1, 1, 30, 30, device="cuda")
        h, w = box.tolist()
        return mask.sum() + h + w

args = (torch.randint(0, 4, (2,)), torch.randint(0, 4, (2,)))

eager = f(*args)
torch._dynamo.reset()
compiled = torch.compile(f, backend='inductor')(*args)
print('eager   :', eager)
print('compiled:', compiled)
