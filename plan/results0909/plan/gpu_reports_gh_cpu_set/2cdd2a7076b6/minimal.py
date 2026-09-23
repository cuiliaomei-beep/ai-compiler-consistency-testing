import torch
torch.manual_seed(0)

def forward(self, x):
        return x.norm(dim=-1)

args = (torch.randn(1),)

eager = f(*args)
torch._dynamo.reset()
compiled = torch.compile(f, backend='inductor')(*args)
print('eager   :', eager)
print('compiled:', compiled)
