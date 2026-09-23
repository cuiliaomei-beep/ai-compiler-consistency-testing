import torch
torch.manual_seed(0)

def forward(self, x):
        s = F.softmax(x, dim=-1)
        total = torch.sum(s, dim=-1, keepdim=False)
        return torch.floor(total)

args = (torch.randn(5, 3).to(torch.float64),)

eager = f(*args)
torch._dynamo.reset()
compiled = torch.compile(f, backend='inductor')(*args)
print('eager   :', eager)
print('compiled:', compiled)
