# source: https://github.com/pytorch/pytorch/issues/194548
# title: torch.compile silently accepts zero-batch input to Categorical that eager correctly rejects
# state: open  created: 2026-08-23
# mined automatically; the harness records the torch.compile target and its first call

import torch

def fn(logits):
    d = torch.distributions.Categorical(logits=logits)
    return d.sample()

x = torch.randn(0, 2)

# eager
fn(x)
# RuntimeError: cannot reshape tensor of 0 elements into shape [0, -1]
# because the unspecified dimension size -1 can be any value and is ambiguous

# compiled
torch.compile(fn, backend="inductor")(x)
# succeeds, returns tensor of shape [0]
