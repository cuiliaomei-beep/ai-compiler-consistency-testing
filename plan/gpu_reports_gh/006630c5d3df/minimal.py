import torch
torch.manual_seed(0)

def model_func(self, target, weight):
    out = torch.ops.aten.binary_cross_entropy_with_logits(
        self,
        target=target,
        weight=weight,
        pos_weight=None,
        reduction=2,  # mean
    )
    return out

args = (...)  # see execution_trace.json

eager = model_func(*args)
torch._dynamo.reset()
compiled = torch.compile(model_func, backend='eager')(*args)
print('eager   :', eager)
print('compiled:', compiled)
