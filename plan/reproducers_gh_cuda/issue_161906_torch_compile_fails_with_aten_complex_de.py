# source: https://github.com/pytorch/pytorch/issues/161906
# title: `torch.compile` fails with `aten.complex.default` size/stride assertion when using STFT output recombined into complex tensor
# state: closed  created: 2025-09-01
# mined automatically; the harness records the torch.compile target and its first call

import torch
import torch.nn as nn

class M(nn.Module):
    def __init__(self, n_fft=512, hop=160, win=320):
        super().__init__()
        self.n_fft, self.hop, self.win = n_fft, hop, win
        # Register window as buffer so it moves with .to(device)
        self.register_buffer("window", torch.hann_window(win))
        # Introduce parameter for broadcasting / stride ops
        self.p = nn.Parameter(torch.tensor(2.0))

    def forward(self, x: torch.Tensor) -> torch.Tensor:
        S = torch.stft(
            x, n_fft=self.n_fft, hop_length=self.hop, win_length=self.win,
            return_complex=True, window=self.window, pad_mode="constant"
        )
        R = torch.abs(S.real)   # unary op on real
        I = S.imag / self.p     # scalar divide with Parameter (stride/broadcast)
        Z = torch.complex(R, I) # recombine -> triggers aten.complex.default
        return Z

def main():
    device = "cuda" if torch.cuda.is_available() else "cpu"
    torch.manual_seed(0)

    x = torch.randn(1, 16000, device=device)
    m = M().to(device)

    # Eager: works fine
    z_eager = m(x)
    assert z_eager.is_complex()
    print("eager mode OK:", z_eager.shape, z_eager.is_complex())

    # Compile: runtime stride assertion in aten.complex.default
    m_c = torch.compile(m)
    z_compiled = m_c(x)

if __name__ == "__main__":
    main()
