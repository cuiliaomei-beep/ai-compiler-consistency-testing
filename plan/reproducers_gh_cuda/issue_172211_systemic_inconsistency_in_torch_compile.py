# source: https://github.com/pytorch/pytorch/issues/172211
# title: Systemic inconsistency in torch.compile(): Random noise propagates differently causing order-of-magnitude output differences
# state: closed  created: 2026-01-12
# mined automatically; the harness records the torch.compile target and its first call

import torch
import torch.nn as nn
import torch.nn.functional as F
import random
CUDA_AVAILABLE = torch.cuda.is_available()
TORCH_CUDNN_SDPA_ENABLED = False

class MultiLayerDNN(nn.Module):

    def __init__(self):
        super().__init__()
        self.conv1 = nn.Conv2d(3, 16, kernel_size=3, padding=1)
        self.bn = nn.BatchNorm2d(16)
        self.relu = nn.ReLU()
        self.sigmoid = nn.Sigmoid()
        self.tanh = nn.Tanh()
        self.fc = nn.Linear(16 * 14 * 14, 64)
        self.lstm = nn.LSTM(64, 32, num_layers=2, batch_first=True)
        self.out = nn.Linear(32, 10)

    def forward(self, x):
        x = self.conv1(x)
        x = self.bn(x)
        x = self.relu(x)
        x = F.max_pool2d(x, 2)
        x = torch.flatten(x + 8.4580700712934e-07 * torch.randn_like(x), 1)
        x = self.fc(x)
        x = self.tanh(x)
        x = x.unsqueeze(1)
        x, _ = self.lstm(x)
        x = x[:, -1, :]
        x = self.sigmoid(x)
        x = self.out(x)
        x = x + torch.randn_like(x)
        return x

def get_default_model():
    return MultiLayerDNN()

def get_sample_inputs():
    return (torch.randn(8, 3, 28, 28),)

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
