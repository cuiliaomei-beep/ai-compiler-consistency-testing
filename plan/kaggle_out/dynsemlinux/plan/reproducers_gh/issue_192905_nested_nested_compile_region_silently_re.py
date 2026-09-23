# source: https://github.com/pytorch/pytorch/issues/192905
# title: Nested nested_compile_region silently reuses a body specialized on the inner region's guards
# state: open  created: 2026-08-11
# mined automatically; the harness records the torch.compile target and its first call

import torch

ncr = torch.compiler.nested_compile_region


class Layer(torch.nn.Module):
    def __init__(self, flag):
        super().__init__()
        self.flag = flag


@ncr
def inner(layer, x):
    if layer.flag:          # guard lands in the INNER region's trace
        return x.sin()
    return x.cos()


@ncr
def outer(layer, x):
    return inner(layer, x) + 1.0


layers = [Layer(True), Layer(False), Layer(True), Layer(False)]


def fn(x):
    return sum(outer(l, x) for l in layers)


x = torch.randn(8)
print(fn(x))
print(torch.compile(fn, backend="aot_eager", fullgraph=True)(x))
