import torch
torch.manual_seed(0)

def m():
    t = inst_norm(x)
    t = pool(t)
    t = F.normalize(t, dim=0)
    return t

args = (...)  # see execution_trace.json

eager = m(*args)
torch._dynamo.reset()
compiled = torch.compile(m, backend='inductor')(*args)
print('eager   :', eager)
print('compiled:', compiled)
