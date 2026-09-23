# source: https://github.com/pytorch/pytorch/issues/183889
# title: torch.compile fails with PendingUnbackedSymbolNotFound for Tensor.add with tensor-derived alpha
# state: closed  created: 2026-05-15
# mined automatically; the harness records the torch.compile target and its first call

import torch
import torch.nn as nn

class M(nn.Module):
    def __init__(self):
        super().__init__()
        self.register_buffer("alpha_buf", torch.tensor(6.0))
        self.register_buffer("other", torch.ones(3, 2))

    def forward(self, x):
        alpha = torch.sub(
            self.alpha_buf,
            torch.tensor(-4.0, dtype=torch.float32, device=x.device),
        )
        return torch.sin(torch.relu(x).add(self.other, alpha=alpha))

model = M().eval()
x = torch.randn(3, 2)

try:
    eager_out = model(x)
    eager = f"OK {tuple(eager_out.shape)}"
except Exception as exc:
    eager = f"{type(exc).__name__} {str(exc).splitlines()[0]}"

try:
    compiled_out = torch.compile(
        model,
        backend="inductor",
        fullgraph=True,
        dynamic=True,
    )(x)
    compiled = f"OK {tuple(compiled_out.shape)}"
except Exception as exc:
    compiled = f"{type(exc).__name__} {str(exc).splitlines()[0]}"

print("x_shape:", tuple(x.shape))
print("alpha:", (model.alpha_buf - torch.tensor(-4.0)).item())
print("eager:", eager)
print("compiled:", compiled)

if eager.startswith("OK") and not compiled.startswith("OK"):
    raise SystemExit(0)

raise SystemExit(1)
