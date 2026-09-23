import torch
torch.manual_seed(0)

def fn(x):
    # Base tensor `x` has size 10.
    # We create a valid overlapping view of size 100 pointing entirely inside `x`
    view = torch.as_strided(x, (100,), (0,))

    # In Inductor, resizing this view unwraps it to the 10-element base,
    # but wrongly accesses it with stride 1 for the first 50 elements,
    # resulting in reading 40 elements of out-of-bounds memory.
    return torch.ops.aten.resize(view, (50,))

args = (torch.randn(2),)

eager = fn(*args)
torch._dynamo.reset()
compiled = torch.compile(fn, backend='inductor')(*args)
print('eager   :', eager)
print('compiled:', compiled)
