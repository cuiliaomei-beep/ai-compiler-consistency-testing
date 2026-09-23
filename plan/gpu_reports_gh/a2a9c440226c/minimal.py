import torch
torch.manual_seed(0)

def model_func(self, kernel_size, output_size, random_samples):
    out = torch.ops.aten.fractional_max_pool2d(self, kernel_size=kernel_size,output_size=output_size, random_samples=random_samples)
    return out

args = (...)  # see execution_trace.json

eager = model_func(*args)
torch._dynamo.reset()
compiled = torch.compile(model_func, backend='eager')(*args)
print('eager   :', eager)
print('compiled:', compiled)
