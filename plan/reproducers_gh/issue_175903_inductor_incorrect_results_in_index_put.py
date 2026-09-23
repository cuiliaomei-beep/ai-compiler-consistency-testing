# source: https://github.com/pytorch/pytorch/issues/175903
# title: [Inductor] Incorrect results in `index_put_` when `randperm` views are not injective
# state: closed  created: 2026-02-26
# mined automatically; the harness records the torch.compile target and its first call

import torch
from torch.nn import Module

class Model(Module):
    def forward(self, x):
        p = torch.randperm(5)
        # Create a non-injective (overlapping) view of randperm 
        idx = torch.as_strided(p, (5,), (0,))
        y = x[idx] + 1.0
        x.index_put_((idx,), y, accumulate=False)
        return x

model = Model().eval()
compiled_model = torch.compile(model, fullgraph=True)

torch.manual_seed(42)
input_uncompiled = torch.zeros(5)
output_uncompiled = model(input_uncompiled)

torch.manual_seed(42)
input_compiled = torch.zeros(5)
output_compiled = compiled_model(input_compiled)

print("Uncompiled model output:\n", output_uncompiled)
print("Compiled model output:\n", output_compiled)
torch.testing.assert_close(output_uncompiled, output_compiled, equal_nan=True)
