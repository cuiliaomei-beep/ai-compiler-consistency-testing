import torch
torch.manual_seed(0)

def h(x, y):
    pred = torch.tensor(True)

    def true_fn():
        return torch.ones(x.shape[0], x.shape[1])

    def false_fn():
        return torch.zeros(x.shape[0], y.shape[1])

    return torch.cond(pred, true_fn, false_fn)

args = (torch.randn(5, 7), torch.randn(5, 8))

eager = h(*args)
torch._dynamo.reset()
compiled = torch.compile(h, backend='eager')(*args)
print('eager   :', eager)
print('compiled:', compiled)
