# source: https://github.com/pytorch/pytorch/issues/168358
# title: index_reduce returns NaN during backward when compiled and using 'amax'/'amin'
# state: closed  created: 2025-11-21
# mined automatically; the harness records the torch.compile target and its first call

import torch
torch._inductor.config.fallback_random = True
torch._dynamo.utils.same


def reduce_max(src, index, dim_size, dim=0):
    out_shape = list(src.shape)
    out_shape[dim] = dim_size
    out = torch.full(
        out_shape,
        float("-inf"),
        dtype=src.dtype,
        device=src.device,
    )

    return out.index_reduce(
        dim,
        index,
        src,
        "amax",
        include_self=False,
    )


src = torch.randn(5).to("cuda")
index = torch.zeros(5, dtype=torch.int64).to("cuda")
dim_size = index.max() + 1

# eager test
src.requires_grad_(True)
sm1 = reduce_max(src, index, dim_size, dim=0)
dsm_dr1 = torch.autograd.grad(
    sm1.sum(),
    src,
)[0]
src = src.detach()

# compiled test
comp_scatter_max = torch.compile(reduce_max)
src.requires_grad_(True)
sm2 = comp_scatter_max(src, index, dim_size, dim=0)
dsm_dr2 = torch.autograd.grad(
    sm2.sum(),
    src,
)[0]
src = src.detach()

print("src: ", src)
print("-"*40)
print(f"Results match: {torch.allclose(sm1, sm2)}")
print("Non compiled: ",sm1)
print("Compiled: ", sm2)
print("-"*40)
print(f"Gradients match: {torch.allclose(dsm_dr1, dsm_dr2)}")
print("Non compiled: ", dsm_dr1)
print("Compiled: ", dsm_dr2)
print("-"*40)
