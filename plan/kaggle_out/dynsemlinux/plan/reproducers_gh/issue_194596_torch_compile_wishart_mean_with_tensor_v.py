# source: https://github.com/pytorch/pytorch/issues/194596
# title: [torch.compile] Wishart.mean with tensor-valued df fails under fullgraph=True
# state: open  created: 2026-08-24
# mined automatically; the harness records the torch.compile target and its first call

import torch
from torch.distributions import Wishart

def fn(df, covariance):
    return Wishart(df=df, covariance_matrix=covariance).mean

df = torch.tensor(5.0)
covariance = torch.eye(2)

print("eager:", fn(df, covariance))
compiled = torch.compile(fn, backend="inductor", fullgraph=True)
print("compiled:", compiled(df, covariance))
