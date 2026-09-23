# source: https://github.com/pytorch/pytorch/issues/178259
# title: [Inductor] C++ compilation error when converting between int8_t and int64_t in vectorized code with torch.compile
# state: closed  created: 2026-03-24
# mined automatically; the harness records the torch.compile target and its first call

import torch
import torch.nn as nn

class Model1(nn.Module):
    def forward(self, inp):
        triu = torch.triu(inp, diagonal=0)
        reduce_min = torch.min(triu, dim=0)[0]
        return reduce_min

model = Model1()
model.eval()
inputs = torch.randint(-128, 128, (57, 22), dtype=torch.int8)

# Eager mode works
with torch.no_grad():
    output = model(inputs)

# Compilation fails
compiled_model = torch.compile(model)
with torch.no_grad():
    output_compile = compiled_model(inputs)  # ERROR
