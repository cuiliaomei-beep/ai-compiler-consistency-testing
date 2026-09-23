import torch
torch.manual_seed(0)

def densify(values, offsets):
    flat = torch.arange(values.size(0), device=values.device)
    batch_idx = torch.searchsorted(offsets[1:], flat, right=True)   # eager: 0..63
    local_idx = flat - offsets[batch_idx]
    out = values.new_zeros(offsets.shape[0] - 1, int(lengths.max()), values.size(1))
    out[batch_idx, local_idx] = values
    return out

args = (...)  # see execution_trace.json

eager = densify(*args)
torch._dynamo.reset()
compiled = torch.compile(densify, backend='inductor')(*args)
print('eager   :', eager)
print('compiled:', compiled)
