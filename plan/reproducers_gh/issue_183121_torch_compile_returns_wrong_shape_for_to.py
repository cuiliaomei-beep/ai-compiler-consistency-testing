# source: https://github.com/pytorch/pytorch/issues/183121
# title: torch.compile returns wrong shape for torch.norm(dim=-1) when reduced dimension has size 1
# state: closed  created: 2026-05-10
# mined automatically; the harness records the torch.compile target and its first call

import torch
import torch.nn as nn

class M(nn.Module):
    def forward(self, x):
        return x.norm(dim=-1)

m = M()
torch._dynamo.reset()
c = torch.compile(m)

x = torch.rand(5, 7, 1)

es = m(x).shape
cs = c(x).shape

print(f"eager   shape = {tuple(es)}")
print(f"compile shape = {tuple(cs)}")
print("BUG" if es != cs else "OK")
