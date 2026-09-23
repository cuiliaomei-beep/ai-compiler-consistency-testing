import torch
torch.manual_seed(0)

def model():
    x = torch.ones([7, 7])
    t = bn1(x)
    t = gn(t)
    # normalised residual: t + t / clamp(t, min=1e-6)
    t = torch.addcdiv(t, t, torch.clamp(t, min=1e-6))   # ← wrong in compiled
    t = bn2(t)
    return t

args = (...)  # see execution_trace.json

eager = model(*args)
torch._dynamo.reset()
compiled = torch.compile(model, backend='inductor')(*args)
print('eager   :', eager)
print('compiled:', compiled)
