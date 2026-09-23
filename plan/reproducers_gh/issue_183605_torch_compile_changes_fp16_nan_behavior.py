# source: https://github.com/pytorch/pytorch/issues/183605
# title: torch.compile changes fp16 NaN behavior for var + rsqrt normalization
# state: closed  created: 2026-05-13
# mined automatically; the harness records the torch.compile target and its first call

import torch

def fn(x):
    var = x.var(dim=-1, keepdim=True)
    return x * torch.rsqrt(var + 1e-9)

x = torch.full((3, 5), 1e-10, dtype=torch.float16)

eager = fn(x)

torch._dynamo.reset()
compiled = torch.compile(fn, backend="inductor")(x)

print("eager:", eager[0, 0].item(), "compile:", compiled[0, 0].item())
print(
    "eager_all_nan:",
    torch.isnan(eager).all().item(),
    "compile_all_zero:",
    (compiled == 0).all().item(),
)
