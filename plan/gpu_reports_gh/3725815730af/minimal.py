import torch
torch.manual_seed(0)

def f(x):
    y = x @ w

    def cond_fn(i, carry):
        return i < 3

    def body_fn(i, carry):
        return i + 1, carry + b

    _, y = while_loop(cond_fn, body_fn, (torch.tensor(0, device="cuda"), y))
    return y

args = (torch.randn(4, 16),)

eager = f(*args)
torch._dynamo.reset()
compiled = torch.compile(f, backend='eager')(*args)
print('eager   :', eager)
print('compiled:', compiled)
