# source: https://github.com/pytorch/pytorch/issues/157248
# title: [inductor] [triton backend] `Conv2d-unsqueeze-AdaptiveAvgPool3d` output incorrect results on inductor
# state: closed  created: 2025-06-30
# mined automatically; the harness records the torch.compile target and its first call

import torch
import torch.nn as nn
import torch.nn.functional as F
from torch._inductor import config

config.fallback_random = True
torch.set_grad_enabled(False)
torch.manual_seed(0)


class Model(torch.nn.Module):

    def __init__(self):
        super().__init__()
        self.conv = torch.nn.Conv2d(3, 16, kernel_size=3, stride=1, padding=1)
        self.adaptive_pool = torch.nn.AdaptiveAvgPool3d((4, 4, 4))

    def forward(self, x):
        x = self.conv(x)
        # torch._dynamo.graph_break()
        x = x.unsqueeze(1)
        # torch._dynamo.graph_break()
        x = self.adaptive_pool(x)
        return x


model = Model()


input_tensor = torch.randn(2, 3, 32, 32)

inputs = [input_tensor]


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

print(torch.allclose(output, c_output, rtol=1e-3, atol=1e-3))
print(torch.max(torch.abs(c_output - output)))

fp64 = run_test(model.to(dtype=torch.float64), [x.to(dtype=torch.float64) for x in inputs], device, 'eager')
print(torch._dynamo.utils.same(output, c_output, fp64))
