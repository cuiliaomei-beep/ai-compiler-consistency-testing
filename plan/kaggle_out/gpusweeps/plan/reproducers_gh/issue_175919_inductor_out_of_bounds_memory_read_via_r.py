# source: https://github.com/pytorch/pytorch/issues/175919
# title: [Inductor] Out-of-Bounds Memory Read via `resize` on Overlapping Views
# state: closed  created: 2026-02-26
# mined automatically; the harness records the torch.compile target and its first call

import torch

def fn(x):
    # Base tensor `x` has size 10.
    # We create a valid overlapping view of size 100 pointing entirely inside `x`
    view = torch.as_strided(x, (100,), (0,))
    
    # In Inductor, resizing this view unwraps it to the 10-element base,
    # but wrongly accesses it with stride 1 for the first 50 elements,
    # resulting in reading 40 elements of out-of-bounds memory.
    return torch.ops.aten.resize(view, (50,))

if __name__ == "__main__":
    x = torch.ones(10)
    
    compiled_fn = torch.compile(fn, fullgraph=True)
    
    eager_res = fn(x)
    compiled_res = compiled_fn(x.clone())
    
    print("Eager expected range:", eager_res.min().item(), "to", eager_res.max().item())
    print("Compile actual range:", compiled_res.min().item(), "to", compiled_res.max().item())
    
    if compiled_res.max().item() > 1.0 or compiled_res.min().item() < 1.0:
        print("\n[BUG CONFIRMED] Compiled tensor contains garbage/out-of-bound memory:")
        print(compiled_res)
