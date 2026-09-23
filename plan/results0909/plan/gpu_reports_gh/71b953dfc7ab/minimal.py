import torch
torch.manual_seed(0)

def my_example():
    torch.manual_seed(0)
    d_float32 = torch.rand((8, 8), device="cpu")
    return d_float32 + d_float32

args = (...)  # see execution_trace.json

eager = my_example(*args)
torch._dynamo.reset()
compiled = torch.compile(my_example, backend='inductor')(*args)
print('eager   :', eager)
print('compiled:', compiled)
