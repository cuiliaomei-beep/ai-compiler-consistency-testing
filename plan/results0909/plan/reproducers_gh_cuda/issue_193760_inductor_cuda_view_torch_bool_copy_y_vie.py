# source: https://github.com/pytorch/pytorch/issues/193760
# title: [inductor][cuda] `view(torch.bool).copy_(y.view(torch.bool)).view(torch.float32)` silently corrupts data under `torch.compile`
# state: open  created: 2026-08-17
# mined automatically; the harness records the torch.compile target and its first call

import torch

torch.manual_seed(1234)
a = torch.randn(8, 8, device="cuda") * 10
b = torch.randn(8, 8, device="cuda") * 10

def fn(x, y):
    return x.view(torch.bool).copy_(y.view(torch.bool)).view(torch.float32)

eager = fn(a.clone(), b)
torch._dynamo.reset()
compiled = torch.compile(fn)(a.clone(), b)

print("eager == b (bitwise):", torch.equal(eager, b))        # True
print("compiled == b (bitwise):", torch.equal(compiled, b))  # False
print("maxdiff:", (eager - compiled).abs().max().item())     # 21.2665
print("compiled row0[:4]:", compiled[0, :4].tolist())        # [2.37e-38, ...] (bytes 0x01 = bool True)
