# source: https://github.com/pytorch/pytorch/issues/185464
# title: torch.compile produces wrong results for F.multilabel_margin_loss when target contains -1
# state: closed  created: 2026-05-28
# mined automatically; the harness records the torch.compile target and its first call

import torch
import torch.nn.functional as F

device = "cuda"
x = torch.tensor([[1.0, -1.0, 0.5, 0.3, -0.2]], device=device, requires_grad=True)
target = torch.tensor([[0, 1, -1, -1, -1]], device=device, dtype=torch.long)

# Eager (correct)
x_e = x.detach().clone().requires_grad_(True)
loss_e = F.multilabel_margin_loss(x_e, target)
loss_e.backward()
print(f"Eager loss: {loss_e.item()}")       # 1.48
print(f"Eager grad: {x_e.grad}")            # [[-0.4, -0.6, 0.4, 0.4, 0.2]]

# Compiled (WRONG)
torch._dynamo.reset()
x_c = x.detach().clone().requires_grad_(True)
compiled_fn = torch.compile(lambda x: F.multilabel_margin_loss(x, target))
loss_c = compiled_fn(x_c)
loss_c.backward()
print(f"Compiled loss: {loss_c.item()}")     # 1.96 ← WRONG
print(f"Compiled grad: {x_c.grad}")          # [[-1.6, -0.6, 1.0, 1.0, 0.2]] ← WRONG
