# source: https://github.com/pytorch/pytorch/issues/167629
# title: [Compile Error] TorchDynamo fails to compile model with scalar argument passed to tensor.copy_() (type mismatch)
# state: closed  created: 2025-11-12
# mined automatically; the harness records the torch.compile target and its first call

import torch
import torch.nn as nn
import torch.nn.functional as F

class TestModel(nn.Module):

    def __init__(self):
        super().__init__()
        self.fc = nn.Linear(10, 5)

    def forward(self, x):
        x = self.fc(x)
        src = torch.randn_like(x)
        x.copy_(1)
        return x

def get_default_model():
    return TestModel()

def get_sample_inputs():
    x = torch.randn(3, 10, requires_grad=True)
    return (x,)

def main():
    model = get_default_model()
    model.eval()
    inputs = get_sample_inputs()
    with torch.no_grad():
        output = model(*inputs)
    print('TestModel executed successfully!')
    print('Input shape:', inputs[0].shape)
    print('Output shape:', output.shape)
    print('Model parameters:', sum((p.numel() for p in model.parameters())))
    try:
        compiled_model = torch.compile(model, fullgraph=True)
        with torch.no_grad():
            output_compile = compiled_model(*inputs)

        print(f'Compile  shape: {output_compile.shape}')
    except Exception as e:
        print(f'\nOriginal exception:\n {e}')
if __name__ == '__main__':
    main()
