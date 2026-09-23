# source: https://github.com/pytorch/pytorch/issues/179561
# title: [inductor] `x.to(torch.bfloat16).float()` precision cast silently elided during fusion
# state: closed  created: 2026-04-07
# mined automatically; the harness records the torch.compile target and its first call

import torch
import torch._dynamo

torch.manual_seed(0)
x = torch.randn(4, 32, 32, device='cuda')
w = torch.randn(32, 32, device='cuda')

def fn(x, w):
    x = torch.matmul(x, w)
    x = x.to(torch.bfloat16).float()  # intentional precision truncation
    x = x * torch.sigmoid(x)
    return x.sum(dim=1)

# Eager (correct)
eager_out = fn(x, w)

# Inductor (incorrect — cast is elided)
torch._dynamo.reset()
compiled_fn = torch.compile(fn, backend='inductor')
inductor_out = compiled_fn(x.clone(), w.clone())

# aot_eager (correct — preserves cast)
torch._dynamo.reset()
aot_fn = torch.compile(fn, backend='aot_eager')
aot_out = aot_fn(x.clone(), w.clone())

print('eager vs inductor: ', (eager_out - inductor_out).abs().max().item())
# => 0.109 (WRONG — should be ~0)
print('eager vs aot_eager:', (eager_out - aot_out).abs().max().item())
# => 0.0 (correct)

# Proof that inductor output matches "no cast at all":
def fn_no_cast(x, w):
    x = torch.matmul(x, w)
    # bf16 cast removed
    x = x * torch.sigmoid(x)
    return x.sum(dim=1)

no_cast_out = fn_no_cast(x, w)
print('inductor vs fn_without_cast:', (inductor_out - no_cast_out).abs().max().item())
# => 1.5e-5 (inductor behaves as if cast never existed)
