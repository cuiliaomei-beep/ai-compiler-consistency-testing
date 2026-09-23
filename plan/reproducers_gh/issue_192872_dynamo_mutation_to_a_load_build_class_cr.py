# source: https://github.com/pytorch/pytorch/issues/192872
# title: dynamo: mutation to a LOAD_BUILD_CLASS-created class's sourceless attribute is lost across a graph break
# state: open  created: 2026-08-11
# mined automatically; the harness records the torch.compile target and its first call

import torch
import torch._dynamo

torch._dynamo.config.enable_trace_load_build_class = True


def fn(t):
    class Holder:
        items = []

    Holder.items.append(1)
    y = t * 2
    torch._dynamo.graph_break()
    Holder.items.append(2)
    z = y * 3
    return z.sum() + len(Holder.items)


t = torch.randn(3)
opt_fn = torch.compile(fn, backend="eager")
out = opt_fn(t)
expected = fn(t)
print("compiled:", out.item())
print("eager:   ", expected.item())
assert torch.equal(out, expected), "mismatch"
