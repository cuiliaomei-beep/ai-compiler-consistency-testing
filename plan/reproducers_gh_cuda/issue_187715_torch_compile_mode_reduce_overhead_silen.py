# source: https://github.com/pytorch/pytorch/issues/187715
# title: `torch.compile(mode='reduce-overhead')` silently degrades training on ROCm — `cudagraph_trees` has no HIP guard
# state: closed  created: 2026-06-19
# mined automatically; the harness records the torch.compile target and its first call

import torch
import torch._inductor.config as icfg

# A simple training loop
class Net(torch.nn.Module):
    def __init__(self):
        super().__init__()
        self.fc1 = torch.nn.Linear(512, 256)
        self.fc2 = torch.nn.Linear(256, 512)
    def forward(self, x):
        return self.fc2(torch.nn.functional.relu(self.fc1(x)))

def train(model, n_steps=200):
    opt = torch.optim.AdamW(model.parameters(), lr=1e-3)
    losses = []
    for step in range(n_steps):
        x = torch.randn(64, 512, device='cuda')
        y = torch.randn(64, 512, device='cuda')
        loss = torch.nn.functional.mse_loss(model(x), y)
        loss.backward()
        opt.step(); opt.zero_grad()
        if step <= 5 or step % 20 == 0:
            losses.append((step, loss.item()))
    return losses

# ✅ Fine
model1 = Net().cuda()
loss1 = train(model1)
print(f"no compile:                step200 loss={loss1[-1][1]:.4f}")

# ✅ Fine  
model2 = Net().cuda()
model2 = torch.compile(model2, mode='default')
loss2 = train(model2)
print(f"mode='default':            step200 loss={loss2[-1][1]:.4f}")

# ❌ Degraded on ROCm
model3 = Net().cuda()
model3 = torch.compile(model3, mode='reduce-overhead')
loss3 = train(model3)
print(f"mode='reduce-overhead':    step200 loss={loss3[-1][1]:.4f}")

# ❌ Also degraded — this is the underlying cause
icfg.triton.cudagraphs = True
icfg.triton.cudagraph_trees = True  # ← culprit
model4 = Net().cuda()
model4 = torch.compile(model4)
loss4 = train(model4)
print(f"cudagraphs+trees manually: step200 loss={loss4[-1][1]:.4f}")

# ✅ Fine — old cudagraph impl works on ROCm
icfg.triton.cudagraphs = True
icfg.triton.cudagraph_trees = False  # ← old impl, works
model5 = Net().cuda()
model5 = torch.compile(model5)
loss5 = train(model5)
print(f"cudagraphs ONLY (old):     step200 loss={loss5[-1][1]:.4f}")
