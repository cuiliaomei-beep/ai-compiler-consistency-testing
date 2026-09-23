# source: https://github.com/pytorch/pytorch/issues/178046
# title: `torch.compile` silently accepts `nn.Parameter` as `fill_value` in `torch.full()` where eager raises TypeError
# state: closed  created: 2026-03-21
# mined automatically; the harness records the torch.compile target and its first call

import torch
import torch.nn as nn

class Model(nn.Module):
    def __init__(self):
        super().__init__()
        self.fill_value = nn.Parameter(torch.tensor(1.0))

    def forward(self, x):
        batch_size, seq_len = x.shape[:2]
        # nn.Parameter passed directly to torch.full() — should be .item()
        constant = torch.full(
            (batch_size, seq_len, seq_len),
            fill_value=self.fill_value,  # <-- Parameter, not scalar!
            dtype=x.dtype,
            device=x.device,
        )
        return torch.cumsum(constant, dim=-1)

model = Model().cuda()
x = torch.randn(2, 8, 32, device="cuda")

# Eager: TypeError
try:
    model(x)
    print("eager: OK")
except TypeError as e:
    print(f"eager: ERROR — {e}")

# Compiled: silently succeeds
torch._dynamo.reset()
compiled_model = torch.compile(model, fullgraph=True)
try:
    out = compiled_model(x)
    print(f"compile: OK shape={out.shape}")
except Exception as e:
    print(f"compile: ERROR — {e}")
