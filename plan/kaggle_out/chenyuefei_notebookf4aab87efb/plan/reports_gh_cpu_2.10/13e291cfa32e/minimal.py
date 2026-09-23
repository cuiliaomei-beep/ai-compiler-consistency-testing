import torch
torch.manual_seed(0)

def forward(self, x):
        x = F.pad(x, (0, 318))
        return x.stft(n_fft=512, hop_length=160, win_length=320,
                       return_complex=True, window=self._window, pad_mode="constant")

args = (torch.randn(2, 2),)

eager = f(*args)
torch._dynamo.reset()
compiled = torch.compile(f, backend='inductor')(*args)
print('eager   :', eager)
print('compiled:', compiled)
