import torch
torch.manual_seed(0)

def fn(x, obj):
    try:
        m = obj.append     # eager: descr_check raises TypeError HERE (at the bind)
        return x + 1       # dynamo: binds silently -> takes this branch
    except TypeError:
        return x + 2

args = (torch.randn(4).requires_grad_(True), <_repro_issue_190755_some_dynamo_descriptors_tp_descr_get_imp.py.Borrower object at 0x785eb5672720>)

eager = fn(*args)
torch._dynamo.reset()
compiled = torch.compile(fn, backend='eager')(*args)
print('eager   :', eager)
print('compiled:', compiled)
