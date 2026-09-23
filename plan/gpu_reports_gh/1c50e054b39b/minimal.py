import torch
torch.manual_seed(0)

def model_func(grad_output, self):
    out = torch.ops.aten.hardswish_backward(grad_output, self=self,)
    out = out + 1  # inconcsistency only when add this line
    return out

args = (...)  # see execution_trace.json

eager = model_func(*args)
torch._dynamo.reset()
compiled = torch.compile(model_func, backend='eager')(*args)
print('eager   :', eager)
print('compiled:', compiled)
