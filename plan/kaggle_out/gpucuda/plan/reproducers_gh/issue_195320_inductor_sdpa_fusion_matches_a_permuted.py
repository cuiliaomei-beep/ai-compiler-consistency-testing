# source: https://github.com/pytorch/pytorch/issues/195320
# title: [inductor] SDPA fusion matches a permuted K as if it were key.transpose(-2,-1), silently producing wrong attention outputs
# state: open  created: 2026-08-30
# mined automatically; the harness records the torch.compile target and its first call

import torch
import torch.nn as nn

B, T, H, D = 1, 8, 8, 8          # seq_len == n_heads
E = H * D

class MHA(nn.Module):
    """Multi-head attention where K is permuted straight into the
    transposed layout (B, H, D, T), so the score matmul needs no
    transpose(-2, -1). This is a common hand-written optimisation."""
    def __init__(self):
        super().__init__()
        self.q = nn.Linear(E, E, bias=False)
        self.k = nn.Linear(E, E, bias=False)
        self.v = nn.Linear(E, E, bias=False)

    def forward(self, x):
        b, t, _ = x.shape
        q = self.q(x).view(b, t, H, D).permute(0, 2, 1, 3)   # (B, H, T, D)
        k = self.k(x).view(b, t, H, D).permute(0, 2, 3, 1)   # (B, H, D, T) pre-transposed
        v = self.v(x).view(b, t, H, D).permute(0, 2, 1, 3)   # (B, H, T, D)
        w = (torch.matmul(q, k) * (D ** -0.5)).softmax(dim=-1)
        return (w @ v).permute(0, 2, 1, 3).reshape(b, t, E)

torch.manual_seed(0)
m = MHA().eval()
x = torch.randn(B, T, E)

with torch.no_grad():
    eager = m(x)
    compiled = torch.compile(m, backend="inductor")(x)

print("allclose:", torch.allclose(eager, compiled, atol=1e-4, rtol=1e-3))
print("max abs diff:", (eager - compiled).abs().max().item())
