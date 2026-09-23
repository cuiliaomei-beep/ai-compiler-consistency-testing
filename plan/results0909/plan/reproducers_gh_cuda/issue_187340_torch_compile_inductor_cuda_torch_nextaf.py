# source: https://github.com/pytorch/pytorch/issues/187340
# title: [torch.compile][Inductor][CUDA] torch.nextafter is incorrectly compiled as no-op for non-contiguous float16 tensors
# state: open  created: 2026-06-15
# mined automatically; the harness records the torch.compile target and its first call

import torch

print("torch:", torch.__version__)
print("cuda:", torch.version.cuda)

device = "cuda"
dtype = torch.float16

def fn(x, y):
    return torch.nextafter(x, y)

base = torch.tensor(
    [
        [-0.0, -1.0],
        [ 0.0,  2.0],
        [ 1.0, -2.0],
    ],
    device=device,
    dtype=dtype,
)

x = base.t()          
y = torch.zeros_like(x)

print("x:")
print(x)
print("x.is_contiguous():", x.is_contiguous())
print("x.stride():", x.stride())

y_eager = fn(x, y)

compiled_fn = torch.compile(fn, backend="inductor", fullgraph=True)
y_compiled = compiled_fn(x, y)

print("\neager:")
print(y_eager)

print("\ncompiled:")
print(y_compiled)

print("\ntorch.equal:", torch.equal(y_eager, y_compiled))
print("torch.allclose:", torch.allclose(y_eager, y_compiled))

print("\neager bit pattern:")
print(y_eager.view(torch.int16))

print("\ncompiled bit pattern:")
print(y_compiled.view(torch.int16))

print("\ndiff:")
print(y_compiled - y_eager)
