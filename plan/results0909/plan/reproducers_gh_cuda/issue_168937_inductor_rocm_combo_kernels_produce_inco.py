# source: https://github.com/pytorch/pytorch/issues/168937
# title: [Inductor] ROCm combo kernels produce incorrect scalar results due to missing store masks
# state: closed  created: 2025-11-24
# mined automatically; the harness records the torch.compile target and its first call

import torch

torch._inductor.config.combo_kernels = True
torch._dynamo.config.assume_static_by_default = False

def fn(x):
    return (
        x.mean(),
        torch.mean(x, -2, keepdim=True),
    )

x = torch.randn([1, 2, 4, 8], device="cuda")
eager_out = fn(x)

c_fn = torch.compile(fn)
compile_out = c_fn(x)
print("Eager out:", eager_out)
print("Compiled out:", compile_out)
assert torch.allclose(eager_out[0], compile_out[0])
