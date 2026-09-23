import torch
torch.manual_seed(0)

def model_func(self, dtype):
    out = torch.ops.aten.view_copy(self, dtype=dtype,)
    return out

args = (...)  # see execution_trace.json

eager = model_func(*args)
torch._dynamo.reset()
compiled = torch.compile(model_func, backend='eager')(*args)
print('eager   :', eager)
print('compiled:', compiled)
