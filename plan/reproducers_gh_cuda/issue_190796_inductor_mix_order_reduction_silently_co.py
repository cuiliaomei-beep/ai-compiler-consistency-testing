# source: https://github.com/pytorch/pytorch/issues/190796
# title: [inductor] Mix-order reduction silently corrupts conv-bias grads (bf16, sm_120) in 2.10.0 — fixed in 2.11 without regression test?
# state: closed  created: 2026-07-22
# mined automatically; the harness records the torch.compile target and its first call

# NaN repro: torch.compile (inductor) + bf16 autocast, RTX 5090 (sm_120), torch 2.10.0+cu128
import torch
import torch.nn as nn
import torch.nn.functional as F

print(torch.__version__, torch.version.cuda, torch.cuda.get_device_name())


class Block(nn.Module):
    def __init__(self):
        super().__init__()
        self.conv = nn.Conv2d(512, 256, 3, padding=1)
        self.proj = nn.Linear(512, 256)

    def forward(self, x, temb):
        return self.conv(x) + self.proj(F.silu(temb))[:, :, None, None]


torch.manual_seed(0)
model = Block().cuda()
compiled = torch.compile(model)

for step in range(10):
    x = torch.randn(128, 512, 16, 16, device="cuda")
    temb = torch.randn(128, 512, device="cuda")
    y = torch.randn(128, 256, 16, 16, device="cuda")
    with torch.autocast("cuda", torch.bfloat16):
        loss = F.mse_loss(compiled(x, temb), y)
    model.zero_grad(set_to_none=True)
    loss.backward()
    bad = {n: p.grad for n, p in model.named_parameters()
           if not torch.isfinite(p.grad).all()}
    for n, g in bad.items():
        idx = (~torch.isfinite(g)).nonzero().flatten().tolist()
        print(f"step {step}: {n}.grad has {len(idx)} non-finite element(s) at {idx}")
    if bad:
        raise SystemExit(1)
    print(f"step {step}: grads finite")
print("no NaNs (bug not reproduced)")
