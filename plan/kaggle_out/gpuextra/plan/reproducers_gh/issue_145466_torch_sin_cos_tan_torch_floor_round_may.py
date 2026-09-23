# source: https://github.com/pytorch/pytorch/issues/145466
# title: torch.sin/cos/tan+torch.floor/round may bring wrong results with torch.compile
# state: closed  created: 2025-01-23
# mined automatically; the harness records the torch.compile target and its first call

import torch

class Model(torch.nn.Module):
    def __init__(self):
        super().__init__()

    def forward(self, *args):
        cos = torch.cos(args[0])
        floor = torch.floor(cos)
        return floor

m = Model()

inp = torch.randn((32, 32), dtype=torch.float16)  # dtype=torch.float32 may also brings wrong results

m_out = m(inp.to('cpu'))

opt = torch.compile(m)
opt_out = opt(inp.to('cpu'))

torch.testing.assert_close(m_out, opt_out)
