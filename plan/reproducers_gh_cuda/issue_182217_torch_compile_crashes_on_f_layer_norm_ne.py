# source: https://github.com/pytorch/pytorch/issues/182217
# title: `torch.compile` crashes on `F.layer_norm(NestedTensor)` — `InternalTorchDynamoError` in guard building
# state: open  created: 2026-05-02
# mined automatically; the harness records the torch.compile target and its first call

import torch
import torch.nn.functional as F

values = torch.randn(15, 8, device="cuda", requires_grad=True)
offsets = torch.tensor([0, 5, 10, 15], device="cuda", dtype=torch.int64)

# Eager: works
nt = torch.nested.nested_tensor_from_jagged(values, offsets)
F.layer_norm(nt, [8]).values().sum().backward()  # OK

# Compiled: crashes
torch._dynamo.reset()

@torch.compile(backend="inductor")
def fn(v, o):
    nt = torch.nested.nested_tensor_from_jagged(v, o)
    return F.layer_norm(nt, [8]).values().sum()

fn(values, offsets)  # InternalTorchDynamoError
