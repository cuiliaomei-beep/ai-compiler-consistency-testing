import torch
torch.manual_seed(0)

def model():
    # Invalid Bernoulli probabilities — eager checks p in [0, 1]
    p = torch.full((4,), 2.0, dtype=torch.float32)
    return torch.bernoulli(p)

args = (...)  # see execution_trace.json

eager = model(*args)
torch._dynamo.reset()
compiled = torch.compile(model, backend='inductor')(*args)
print('eager   :', eager)
print('compiled:', compiled)
