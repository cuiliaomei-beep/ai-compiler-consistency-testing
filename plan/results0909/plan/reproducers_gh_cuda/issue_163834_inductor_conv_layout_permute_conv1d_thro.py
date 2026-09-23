# source: https://github.com/pytorch/pytorch/issues/163834
# title: [inductor] [conv layout] `permute-Conv1d` throws a layout error
# state: closed  created: 2025-09-25
# mined automatically; the harness records the torch.compile target and its first call

import torch
import torch.nn as nn
import torch.nn.functional as F
from torch._inductor import config

config.fallback_random = True
torch.set_grad_enabled(False)
torch._dynamo.config.capture_scalar_outputs = True


class Model(torch.nn.Module):

    def __init__(self):
        super(Model, self).__init__()
        self.conv = torch.nn.Conv1d(1, 4, kernel_size=3, padding=1)

    def forward(self, x):
        x = x.permute(0, 2, 1).contiguous()
        x = self.conv(x)
        return x


model = Model()
x = torch.randn(1, 16, 1)


inputs = [x]

device = "cuda"
def run_test(model, inputs, device, backend):
    torch.manual_seed(0)
    model.to(device)
    inputs = [input.to(device) for input in inputs]
    if backend != "eager":
        model = torch.compile(model, backend=backend)
    try:
        output = model(*inputs)
        print(f"succeed on {backend}")
    except Exception as e:
        print(e)


run_test(model, inputs, device, 'eager')
run_test(model, inputs, device, 'inductor')
