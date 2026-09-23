# source: https://github.com/pytorch/pytorch/issues/183369
# title: torch.compile crashes on nested_tensor_from_jagged + layer_norm with InternalTorchDynamoError
# state: open  created: 2026-05-11
# mined automatically; the harness records the torch.compile target and its first call

import torch
import torch.nn.functional as F

device = "cuda" if torch.cuda.is_available() else "cpu"

torch.manual_seed(11)

values = torch.randn(20, 12, device=device, requires_grad=True)
offsets = torch.tensor([0, 6, 11, 14, 20], device=device, dtype=torch.int64)

def fn(v, o):
    nt = torch.nested.nested_tensor_from_jagged(v, o)
    return F.layer_norm(nt, [12]).values().sum()

fn(values, offsets).backward()

torch._dynamo.reset()

try:
    torch.compile(fn, backend="inductor")(
        values.detach().clone().requires_grad_(True),
        offsets,
    )
    print("OK")
except Exception as e:
    msg = str(e).splitlines()[0]
    matched = "InternalTorchDynamoError" in type(e).__name__ or "list index out of range" in repr(e)
    print(f"raised: {type(e).__name__}: {msg[:120]}")
    print("BUG" if matched else "?")
