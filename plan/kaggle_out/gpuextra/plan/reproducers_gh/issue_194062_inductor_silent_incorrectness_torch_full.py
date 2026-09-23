# source: https://github.com/pytorch/pytorch/issues/194062
# title: [inductor] [silent incorrectness] torch.full ignores dtype when fill_value is symbolic
# state: open  created: 2026-08-19
# mined automatically; the harness records the torch.compile target and its first call

import torch, torch._dynamo as dynamo
dynamo.config.capture_scalar_outputs = True

def f(x):
    return torch.full((2,), x.item(), dtype=torch.bool).sum()

print(f(torch.tensor(3)))                                 # tensor(2)  eager
print(torch.compile(f, fullgraph=True)(torch.tensor(3)))  # tensor(6)  inductor
