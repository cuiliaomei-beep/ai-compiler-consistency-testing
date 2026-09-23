# source: https://github.com/pytorch/pytorch/issues/161150
# title: multiplication and softmax throws incorrect results under torch.compile
# state: closed  created: 2025-08-21
# mined automatically; the harness records the torch.compile target and its first call

import torch
torch.manual_seed(100)


class M(torch.nn.Module):
    def __init__(self):
        super().__init__()
        self.scale = torch.tensor([-1.7e14])

    def forward(self, x):
        for _ in range(3):
            x = x * self.scale
        softmaxed = torch.softmax(x, dim=0)
        return x, softmaxed


m = M()
opt = torch.compile(m)
inp = torch.randn((1,10))

m_out = m(inp)
opt_out = opt(inp)

print(f"[Eager] Softmax Input: ", m_out[0])
print(f"[Eager] Softmax output: ", m_out[-1])

print(f"[Compile] Softmax Input: ", opt_out[0])
print(f"[Compile] Softmax output: ", opt_out[-1])
