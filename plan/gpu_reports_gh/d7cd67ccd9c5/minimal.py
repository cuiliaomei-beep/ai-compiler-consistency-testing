import torch
torch.manual_seed(0)

def model_func(grad, self):
    return torch.ops.aten.infinitely_differentiable_gelu_backward(
        grad, self=self
    )

args = (...)  # see execution_trace.json

eager = model_func(*args)
torch._dynamo.reset()
compiled = torch.compile(model_func, backend='eager')(*args)
print('eager   :', eager)
print('compiled:', compiled)
