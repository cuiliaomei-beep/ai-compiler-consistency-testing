import torch
torch.manual_seed(0)

def forward(self, x):
        x = x.transpose(1, 2)
        x = F.relu(self.conv1(x))
        x = self.pool(x)
        x = x.transpose(1, 2)
        x, _ = self.gru(x)
        x = self.dropout1(x[:, -1, :])
        x = F.relu(self.fc1(x))
        x = F.relu(self.fc2(x))
        x = self.dropout2(x)
        x = self.fc3(x)
        x = self.activation(x)
        return x

args = (torch.randn(1, 100, 1).requires_grad_(True),)

eager = f(*args)
torch._dynamo.reset()
compiled = torch.compile(f, backend='inductor')(*args)
print('eager   :', eager)
print('compiled:', compiled)
