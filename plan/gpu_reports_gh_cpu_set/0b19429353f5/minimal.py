import torch
torch.manual_seed(0)

def model():
    mean = torch.zeros((4,), dtype=torch.float32)
    std = torch.full((4,), -1.0, dtype=torch.float32)
    return torch.normal(mean, std)

args = (...)  # see execution_trace.json

eager = model(*args)
torch._dynamo.reset()
compiled = torch.compile(model, backend='inductor')(*args)
print('eager   :', eager)
print('compiled:', compiled)
