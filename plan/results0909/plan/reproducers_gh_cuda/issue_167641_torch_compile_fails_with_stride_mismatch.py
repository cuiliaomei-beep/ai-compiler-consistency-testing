# source: https://github.com/pytorch/pytorch/issues/167641
# title: torch.compile fails with stride mismatch in torch.complex() after FFT operations due to fake kernel inconsistency
# state: closed  created: 2025-11-12
# mined automatically; the harness records the torch.compile target and its first call

import torch
import torch.nn as nn
import torch.fft
class SpectralNet(nn.Module):
    def __init__(self, input_channels=3, num_classes=10):
        super().__init__()
        self.input_channels = input_channels
        self.conv1 = nn.Conv2d(input_channels, 16, kernel_size=3, padding=1)
        self.conv2 = nn.Conv2d(16, 32, kernel_size=3, padding=1)
        self.freq_conv = nn.Conv2d(32, 32, kernel_size=1)
        self.classifier = nn.Sequential(
            nn.AdaptiveAvgPool2d((4, 4)),
            nn.Flatten(),
            nn.Linear(32 * 4 * 4, 128),
            nn.ReLU(),
            nn.Linear(128, num_classes)
        )
    def forward(self, x):
        x = torch.relu(self.conv1(x))
        x = torch.relu(self.conv2(x))
        x_fft = torch.fft.fft2(x)
        x_fft_real = x_fft.real
        x_fft_imag = x_fft.imag
        x_real_processed = self.freq_conv(x_fft_real)
        x_imag_processed = self.freq_conv(x_fft_imag)
        x_processed = torch.complex(x_real_processed, x_imag_processed)
        x_spatial = torch.fft.ifft2(x_processed).real
        output = self.classifier(x_spatial)
        return output
def get_default_model():
    model = SpectralNet(input_channels=3, num_classes=10)
    return model
def get_sample_inputs():
    batch_size = 4
    channels = 3
    height = 32
    width = 32
    x = torch.randn(batch_size, channels, height, width)
    return (x,)
def main():
    model = get_default_model()
    model.eval()
    inputs = get_sample_inputs()
    with torch.no_grad():
        output = model(*inputs)
    print("SpectralNet executed successfully!")
    print(f"Input shape: {inputs[0].shape}")
    print(f"Output shape: {output.shape}")
    print(f"Output strides: {output.stride()}")
    x = torch.randn(8, 16, 32, 32)
    custom_strided = x.as_strided(size=(8, 16, 16, 16),
                                 stride=(16*32*32, 32*32, 32*2, 2))
    print(f"Original tensor strides: {x.stride()}")
    print(f"Custom strided tensor strides: {custom_strided.stride()}")
    x_fft = torch.fft.fft2(x)
    print(f"FFT output strides: {x_fft.stride()}")
    print(f"FFT real part strides: {x_fft.real.stride()}")
    try:
        compiled_model = torch.compile(model)
        with torch.no_grad():
            output_compile = compiled_model(*inputs)

        print(f'Compile  shape: {output_compile.shape}')
    except Exception as e:
        print(f'\nOriginal exception:\n {e}')

if __name__ == "__main__":
    main()
