import torch
torch.manual_seed(0)

def model_func(self, target):
    out = torch.ops.aten.multilabel_margin_loss(self, target=target,reduction=2)
    return out

args = (...)  # see execution_trace.json

eager = model_func(*args)
torch._dynamo.reset()
compiled = torch.compile(model_func, backend='eager')(*args)
print('eager   :', eager)
print('compiled:', compiled)
