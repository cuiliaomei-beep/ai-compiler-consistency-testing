import torch
torch.manual_seed(0)

def model():
    normed = inst_norm(x)              # [15, 13, 13, 13]
    pooled = pool1(normed)             # [15, 13,  1,  1]
    pooled2 = pool2(pooled)            # [15, 13,  1,  1]
    # where broadcasts pooled [15,13,1,1] against normed [15,13,13,13]
    selected = torch.where(pooled > 0, pooled, normed)   # ← wrong in compiled
    return torch.sub(pooled2, selected)

args = (...)  # see execution_trace.json

eager = model(*args)
torch._dynamo.reset()
compiled = torch.compile(model, backend='inductor')(*args)
print('eager   :', eager)
print('compiled:', compiled)
