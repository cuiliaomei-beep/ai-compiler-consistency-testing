# source: https://github.com/pytorch/pytorch/issues/158003
# title: [inuctor] [triton] `torch.cumsum` outputs inconsistent results when meeting large tensors
# state: closed  created: 2025-07-10
# mined automatically; the harness records the torch.compile target and its first call

import torch
import torch.nn as nn
import torch.nn.functional as F
from torch._inductor import config
import warnings

config.fallback_random = True
torch.set_grad_enabled(False)
torch.manual_seed(0)


class Model(torch.nn.Module):

    def __init__(self):
        super().__init__()

    def forward(self, x):
        x = torch.cumsum(x, dim=0)
        return x


model = Model()


x = torch.randn(35000, 30000)  # Larger tensors scale up errors


inputs = [x]


def run_test(model, inputs, device, backend):
    torch.manual_seed(0)
    model = model.to(device)
    inputs = [x.to(device) for x in inputs]
    if backend != "eager":
        model = torch.compile(model, backend=backend)
    torch.manual_seed(0)
    output = model(*inputs)
    return output


device = 'cuda'
output = run_test(model, inputs, device, 'eager')
c_output = run_test(model, inputs, device, 'inductor')


print(torch.allclose(output, c_output, rtol=1e-3, atol=1e-3, equal_nan=True))
print(torch.max(torch.abs(c_output - output)))


fp64 = run_test(model.to(dtype=torch.float64), [x.to(dtype=torch.float64) for x in inputs], device, 'eager')
print(torch._dynamo.utils.same(output, c_output, fp64))
