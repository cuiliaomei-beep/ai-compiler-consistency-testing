import torch
torch.manual_seed(0)

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

args = (torch.randn(5).requires_grad_(True), torch.randint(0, 4, (5,)), torch.tensor(1))

eager = reduce_max(*args)
torch._dynamo.reset()
compiled = torch.compile(reduce_max, backend='eager')(*args)
print('eager   :', eager)
print('compiled:', compiled)
