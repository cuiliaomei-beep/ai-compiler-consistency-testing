import torch
torch.manual_seed(0)

def _noncontig(t):
    # same values, non-unit innermost stride (a strided view of a wider buffer)
    big = torch.empty(*t.shape[:-1], t.shape[-1] * 2, dtype=t.dtype)
    v = big[..., ::2]
    v.copy_(t)
    return v

def forward(self, x):
        x = self.conv(x)
        x = torch.fft.ifft(x, n=256)
        x = torch.real(x)
        return x

args = (_noncontig(torch.randn(3, 4, 4)),)

eager = f(*args)
torch._dynamo.reset()
compiled = torch.compile(f, backend='inductor')(*args)
print('eager   :', eager)
print('compiled:', compiled)
