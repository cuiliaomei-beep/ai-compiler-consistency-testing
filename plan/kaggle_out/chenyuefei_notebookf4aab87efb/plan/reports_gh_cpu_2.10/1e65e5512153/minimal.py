import torch
torch.manual_seed(0)

def forward(self, x):
        x = self.conv1(x)
        x = self.rrelu(x)
        x = x.view(x.size(0), -1)
        x = self.fc(x)
        return x

args = (torch.randn(1, 3, 32, 32).requires_grad_(True),)

eager = f(*args)
torch._dynamo.reset()
compiled = torch.compile(f, backend='inductor')(*args)
print('eager   :', eager)
print('compiled:', compiled)
