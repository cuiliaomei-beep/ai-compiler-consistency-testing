# source: https://github.com/pytorch/pytorch/issues/194593
# title: [torch.compile] kl_divergence(Binomial, Binomial) fails with tensor total_count under fullgraph=True
# state: open  created: 2026-08-24
# mined automatically; the harness records the torch.compile target and its first call

import torch
from torch.distributions import Binomial, kl_divergence

def fn(p_count, p_prob, q_count, q_prob):
    return kl_divergence(
        Binomial(total_count=p_count, probs=p_prob),
        Binomial(total_count=q_count, probs=q_prob),
    )

args = (
    torch.tensor([5.0]),
    torch.tensor([0.2]),
    torch.tensor([3.0]),
    torch.tensor([0.4]),
)

print("eager:", fn(*args))
compiled = torch.compile(fn, backend="inductor", fullgraph=True)
print("compiled:", compiled(*args))
