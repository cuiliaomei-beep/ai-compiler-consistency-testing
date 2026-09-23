import torch
torch.manual_seed(0)

def model():
    normed = inst_norm(x)
    pooled = pool1(normed)
    selected = torch.where(pooled > 0, pooled, normed)
    return selected

args = (...)  # see execution_trace.json

eager = model(*args)
torch._dynamo.reset()
compiled = torch.compile(model, backend='inductor')(*args)
print('eager   :', eager)
print('compiled:', compiled)
