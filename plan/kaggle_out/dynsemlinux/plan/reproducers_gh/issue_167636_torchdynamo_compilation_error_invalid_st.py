# source: https://github.com/pytorch/pytorch/issues/167636
# title: TorchDynamo Compilation Error: Invalid Stride Handling for FFT in Custom Model During Compilation
# state: closed  created: 2025-11-12
# mined automatically; the harness records the torch.compile target and its first call

import torch
import torch.nn as nn

class FFTModel(nn.Module):
    def __init__(self, fft_dim=0):
        super().__init__()
        self.fft_dim = fft_dim

    def forward(self, x):
        return torch.fft.fft(x, dim=self.fft_dim)

def get_default_model():
    return FFTModel(fft_dim=0)

def get_sample_inputs():
    x = torch.randn(3, 5, 7, requires_grad=True)
    return (x,)

def main():
    model = get_default_model()
    model.eval()
    inputs = get_sample_inputs()
    with torch.no_grad():
        output = model(*inputs)
    print('FFTModel executed successfully!')
    print('Input shape:', inputs[0].shape)
    print('Output shape:', output.shape)
    print('Model parameters:', sum(p.numel() for p in model.parameters()))
    try:
        compiled_model = torch.compile(model)
        with torch.no_grad():
            output_compile = compiled_model(*inputs)

        print(f'Compile  shape: {output_compile.shape}')
    except Exception as e:
        print(f'\nOriginal exception:\n {e}')

if __name__ == "__main__":
    main()
