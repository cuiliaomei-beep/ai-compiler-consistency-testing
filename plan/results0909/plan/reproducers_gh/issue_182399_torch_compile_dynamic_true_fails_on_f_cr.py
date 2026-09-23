# source: https://github.com/pytorch/pytorch/issues/182399
# title: torch.compile(dynamic=True) fails on F.cross_entropy with probability targets and class weights
# state: closed  created: 2026-05-05
# mined automatically; the harness records the torch.compile target and its first call

import torch
import torch.nn.functional as F

def fn(logits, prob_targets, weight):
    return F.cross_entropy(
        logits,
        prob_targets,
        weight=weight,
        reduction="none",
    )

logits = torch.randn(4, 3)
prob_targets = torch.rand(4, 3)
prob_targets = prob_targets / prob_targets.sum(dim=1, keepdim=True)
weight = torch.tensor([1.0, 2.0, 3.0])

# Eager path succeeds.
out_eager = fn(logits, prob_targets, weight)
print("eager:", out_eager.shape, out_eager.dtype)

# Compiled path fails.
compiled_fn = torch.compile(fn, dynamic=True)
out_compiled = compiled_fn(logits, prob_targets, weight)
print("compiled:", out_compiled.shape, out_compiled.dtype)
