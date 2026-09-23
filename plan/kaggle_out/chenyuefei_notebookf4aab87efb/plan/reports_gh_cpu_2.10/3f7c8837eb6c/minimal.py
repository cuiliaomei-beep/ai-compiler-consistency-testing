import torch
torch.manual_seed(0)

def fn(x):
    x = _m_t3759174(x)
    x = _m_t3759182(x)
    x = _m_t3759183(x)
    return torch.softmax(x, dim=0).mean()

args = (torch.randn(3, 5, 14, 15).requires_grad_(True),)

eager = fn(*args)
torch._dynamo.reset()
compiled = torch.compile(fn, backend='eager')(*args)
print('eager   :', eager)
print('compiled:', compiled)
