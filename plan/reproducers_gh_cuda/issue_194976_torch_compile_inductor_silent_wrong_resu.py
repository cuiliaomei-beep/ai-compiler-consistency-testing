# source: https://github.com/pytorch/pytorch/issues/194976
# title: [torch.compile][Inductor] Silent wrong results when an automatically dynamic Python float used by clamp reuses a stale value
# state: closed  created: 2026-08-27
# mined automatically; the harness records the torch.compile target and its first call

import torch
import torch.nn.functional as F


def eager_swiglu(x, limit):
    gate, up = torch.chunk(x, 2, dim=-1)
    gate = F.silu(gate).clamp(max=limit)
    up = up.clamp(min=-limit, max=limit)
    return gate * up


@torch.compile(backend="inductor")
def compiled_swiglu(x, limit):
    gate, up = torch.chunk(x, 2, dim=-1)
    gate = F.silu(gate).clamp(max=limit)
    up = up.clamp(min=-limit, max=limit)
    return gate * up


print("torch:", torch.__version__)
print("git_version:", torch.version.git_version)
print("specialize_float:", torch._dynamo.config.specialize_float)

device = "cuda" if torch.cuda.is_available() else "cpu"

cases = [
    ((1, 2), False, 1.0),
    ((1, 4), True, 0.5),
    ((1, 4), True, 1.0),
]

torch._dynamo.reset()

with torch._dynamo.config.patch(specialize_float=False):
    for shape, requires_grad, limit in cases:
        x = torch.full(
            shape,
            0.75,
            device=device,
            dtype=torch.float32,
            requires_grad=requires_grad,
        )
        x_ref = x.detach().clone().requires_grad_(requires_grad)

        actual = compiled_swiglu(x, limit)
        expected = eager_swiglu(x_ref, limit)

        forward_diff = (actual - expected).abs().max().item()
        grad_diff = None

        if requires_grad:
            actual.sum().backward()
            expected.sum().backward()
            grad_diff = (x.grad - x_ref.grad).abs().max().item()

        print(
            f"shape={shape}, requires_grad={requires_grad}, limit={limit}, "
            f"forward_diff={forward_diff}, grad_diff={grad_diff}"
        )
