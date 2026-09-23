import torch
torch.manual_seed(0)

def model_func(x1, x2, dim, eps):
    out = torch.ops.aten.cosine_similarity(x1, x2=x2,dim=dim,eps=eps,)
    return out

args = (...)  # see execution_trace.json

eager = model_func(*args)
torch._dynamo.reset()
compiled = torch.compile(model_func, backend='eager')(*args)
print('eager   :', eager)
print('compiled:', compiled)
