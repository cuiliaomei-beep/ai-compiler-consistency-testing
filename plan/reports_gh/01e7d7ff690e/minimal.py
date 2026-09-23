import torch
torch.manual_seed(0)

def model():
    t = inst_norm(x)
    t = pool(t)
    t = F.normalize(t, dim=0)
    return t

args = (...)  # see execution_trace.json

eager = model(*args)
torch._dynamo.reset()
compiled = torch.compile(model, backend='inductor')(*args)
print('eager   :', eager)
print('compiled:', compiled)
