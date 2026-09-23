# source: https://github.com/pytorch/pytorch/issues/194166
# title: Inductor backend exception (not a graph break planned by dynamo) on aten.nonzero.default from boolean-mask assignment under torch.compile(dynamic=True)
# state: open  created: 2026-08-20
# mined automatically; the harness records the torch.compile target and its first call

import torch

class MaskedBN(torch.nn.Module):
    def __init__(self):
        super().__init__()
        self.norm = torch.nn.BatchNorm1d(8)

    def forward(self, h, mask_bool):
        out = h.clone()
        out[mask_bool] = self.norm(h[mask_bool])
        return out

m = MaskedBN().cuda()
f = torch.compile(m, dynamic=True)
h = torch.randn(64, 8, device="cuda", requires_grad=True)
mask = torch.rand(64, device="cuda") > 0.3
f(h, mask).sum().backward()
