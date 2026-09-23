import torch
torch.manual_seed(0)

def f(x):
    y = torch.nn.functional.dropout(x, 0.5, False)   # training=False -> y IS x
    y += y                                            # in-place mutation of the input
    return y

args = (torch.randn(1),)

eager = f(*args)
torch._dynamo.reset()
compiled = torch.compile(f, backend='inductor')(*args)
print('eager   :', eager)
print('compiled:', compiled)
