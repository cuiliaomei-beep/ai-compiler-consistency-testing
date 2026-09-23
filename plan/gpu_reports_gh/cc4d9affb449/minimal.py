import torch
torch.manual_seed(0)

def forward(self, x):
        x = self.conv1(x)
        x = self.gn1(x)
        x = torch.polygamma(0, x + 0.1)
        x = x.unsqueeze(2)
        x = torch.cumulative_trapezoid(x)
        return x

args = (torch.randn(1, 3, 32, 32).requires_grad_(True),)

eager = f(*args)
torch._dynamo.reset()
compiled = torch.compile(f, backend='inductor')(*args)
print('eager   :', eager)
print('compiled:', compiled)
