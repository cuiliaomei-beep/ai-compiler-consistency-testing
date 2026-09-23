# source: https://github.com/pytorch/pytorch/issues/178262
# title: [Inductor] Incorrect stride calculation in convolution meta kernel when using torch.compile with GRU and Conv1d combination
# state: closed  created: 2026-03-24
# mined automatically; the harness records the torch.compile target and its first call

import torch
import torch.nn as nn
import torch.nn.functional as F

class RandomActivation(nn.Module):
    def __init__(self):
        super().__init__()
    
    def forward(self, x):
        threshold = torch.rand(1, device=x.device)
        return (x > threshold).float()

class TestModel(nn.Module):
    def __init__(self):
        super().__init__()
        self.conv1 = nn.Conv1d(1, 150, kernel_size=50)
        self.pool = nn.MaxPool1d(4)
        self.gru = nn.GRU(150, 200, batch_first=True)
        self.dropout1 = nn.Dropout(0.25)
        self.fc1 = nn.Linear(200, 128)
        self.fc2 = nn.Linear(128, 35)
        self.dropout2 = nn.Dropout(0.25)
        self.fc3 = nn.Linear(35, 1)
        self.activation = RandomActivation()
    
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

model = TestModel()
model.eval()
inputs = torch.randn(4, 100, 1)

# Eager mode works
with torch.no_grad():
    output = model(inputs)

# Compilation fails
compiled_model = torch.compile(model)
with torch.no_grad():
    output_compile = compiled_model(inputs)  # ERROR
