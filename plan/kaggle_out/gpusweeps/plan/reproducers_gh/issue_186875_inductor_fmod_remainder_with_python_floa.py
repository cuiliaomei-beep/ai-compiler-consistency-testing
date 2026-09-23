# source: https://github.com/pytorch/pytorch/issues/186875
# title: [Inductor] fmod/remainder with Python float scalar diverge from eager for bf16/fp16 on CPU (same class as #185517)
# state: open  created: 2026-06-10
# mined automatically; the harness records the torch.compile target and its first call

import torch

def f(x):
    return torch.fmod(x, 1.7), torch.remainder(x, 1.7)

x = torch.tensor([1.703125, -1.703125], dtype=torch.bfloat16)  # 1.703125 == bf16(1.7)
eager = f(x)
comp = torch.compile(f)(x)
print(eager[0].tolist(), eager[1].tolist())   # [0.0, -0.0]            [0.0, -0.0]
print(comp[0].tolist(), comp[1].tolist())     # [0.00312..., -0.00312...] [0.00312..., 1.6953125]
