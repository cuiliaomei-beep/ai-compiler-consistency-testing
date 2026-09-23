import torch
torch.manual_seed(0)

def forward(self, x, y):
        x = self.conv(x)
        x = self.bn(x)
        x = F.relu(x)
        x = self.pool(x)
        x = x.view(x.size(0), -1)
        x = self.fc(x)

        # BUG: randperm creates CPU tensor by default
        idx = torch.randperm(x.size(0))[:y.size(0)]

        # index_add with CPU index and CUDA tensors - should fail!
        result = torch.index_add(x, dim=0, source=y, index=idx)
        return result

args = (torch.randn(1, 3, 32, 32), torch.randn(1, 10))

eager = f(*args)
torch._dynamo.reset()
compiled = torch.compile(f, backend='inductor')(*args)
print('eager   :', eager)
print('compiled:', compiled)
