# source: https://github.com/pytorch/pytorch/issues/194329
# title: [Inductor][aot_autograd][autocast][dynamic_shape] torch.compile with dynamic=True produces incorrect values for fallback ops (e.g., sum) under autocast due to tracing/runtime autocast state mismatch
# state: open  created: 2026-08-21
# mined automatically; the harness records the torch.compile target and its first call

import torch
from torch import nn
from torch._inductor.lowering import make_fallback

make_fallback(torch.ops.aten.sum)

device = "cuda"
torch.manual_seed(1234)

class Repro(nn.Module):
    def __init__(self, in_features):
        super().__init__()
        self.weight_normed_linear = nn.utils.parametrizations.weight_norm(
            nn.Linear(in_features, out_features=2)
        )
        self.linear = nn.Linear(in_features=2, out_features=1)

    def forward(self, x):
        return self.linear(self.weight_normed_linear(x))

def f(m, x):
    with torch.amp.autocast(device_type=device, dtype=torch.half):
        loss = m(x).sum()
        loss.backward()
    return loss

in_features = 1025
x = torch.randn(2, in_features, dtype=torch.half, requires_grad=True).to(
    device=device
)
m = Repro(in_features)
m = m.to(device)

f(m, x)

ref_grad_list = [p.grad for p in m.parameters()]

for p in m.parameters():
    p.grad = None

opt_f = torch.compile(f, dynamic=True) # fail
# opt_f = torch.compile(f, dynamic=False) # pass

opt_f(m, x)
act_grad_list = [p.grad for p in m.parameters()]
torch.testing.assert_close(ref_grad_list, act_grad_list)
