# source: https://github.com/pytorch/pytorch/issues/187935
# title: [Inductor][CUDA] torch.signbit loses negative zero sign for float64 inputs
# state: closed  created: 2026-06-23
# mined automatically; the harness records the torch.compile target and its first call

import torch
import torch._inductor.config

torch._inductor.config.fallback_random = True

print("torch:", torch.__version__)
print("cuda:", torch.version.cuda)

device = "cuda"
dtype = torch.float64

def fn(x):
    return torch.signbit(x)

# Constructing a tensor that contains -0.0
x = torch.tensor(
    [
        [ 1.0, -0.0,  0.0],
        [-1.0, -0.0,  2.5]
    ],
    device=device,
    dtype=dtype,
)

print("Input Tensor:")
print(x)

y_eager = fn(x)

compiled_fn = torch.compile(fn, backend="inductor", fullgraph=True)
y_compiled = compiled_fn(x)

print("\nEager Output:")
print(y_eager)

print("\nCompiled Output:")
print(y_compiled)

print("\ntorch.equal:", torch.equal(y_eager, y_compiled))

# Assert exact match since output is boolean
torch.testing.assert_close(y_eager, y_compiled, rtol=0, atol=0)
