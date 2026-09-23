# source: https://github.com/pytorch/pytorch/issues/172209
# title: torch.compile() changes autocast behavior: Different precision handling leads to 20% output differences
# state: closed  created: 2026-01-12
# mined automatically; the harness records the torch.compile target and its first call

import torch
import torch.nn as nn
import torch.nn.functional as F

class TestModel(nn.Module):

    def __init__(self):
        super().__init__()
        self.conv1 = nn.Conv2d(1, 16, kernel_size=3, padding=1)
        self.fc1 = nn.Linear(16 * 16 * 16, 32)
        self.lstm = nn.LSTM(32, 16, batch_first=True)
        self.relu = nn.ReLU()
        self.sigmoid = nn.Sigmoid()
        self.fc2 = nn.Linear(16, 10)

    def forward(self, x):
        x = self.conv1(x)
        x = self.relu(x)
        x = x.view(x.size(0), -1)
        x = self.fc1(x)
        x = x.unsqueeze(1).repeat(1, 5, 1)
        with torch.autocast(device_type='cuda', dtype=torch.float32):
            lstm_out, _ = self.lstm(x)
        lstm_out = lstm_out.mean(dim=1)
        lstm_out = self.sigmoid(lstm_out)
        with torch.autocast(device_type='cpu', dtype=torch.bfloat16):
            final_out = self.fc2(lstm_out)
        target = torch.randint(0, 10, (2,))
        loss = F.cross_entropy(final_out, target)
        return loss

def get_default_model():
    return TestModel()

def get_sample_inputs():
    x = torch.randn(2, 1, 16, 16, requires_grad=True)
    return (x,)

def main():

    torch.manual_seed(42)

    model = get_default_model()
    model.eval()

    inputs = get_sample_inputs()

    with torch.no_grad():
        output = model(*inputs)

    print('Input shape:', inputs[0].shape)
    print('Output shape:', output.shape if hasattr(output, 'shape') else 'N/A')
    print('Output value:', output)

    compiled_model = torch.compile(model)
    with torch.no_grad():
        output_compile = compiled_model(*inputs)

    print(f'Compile shape: {output_compile.shape if hasattr(output_compile, "shape") else "N/A"}')
    print(f'Compile value: {output_compile}')


if __name__ == '__main__':
    main()
