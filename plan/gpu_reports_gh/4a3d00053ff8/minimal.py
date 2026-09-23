import torch
torch.manual_seed(0)

def f_stft(a):
    return torch.stft(a, n_fft=32, hop_length=16, return_complex=True).abs().sum()

args = (torch.randn(32).requires_grad_(True),)

eager = f_stft(*args)
torch._dynamo.reset()
compiled = torch.compile(f_stft, backend='inductor')(*args)
print('eager   :', eager)
print('compiled:', compiled)
