# source: https://github.com/pytorch/pytorch/issues/176310
# title: [inductor] cudagraph trees breaks with partitioned graphs with nested inputs
# state: closed  created: 2026-03-03
# mined automatically; the harness records the torch.compile target and its first call

import torch
from torch._higher_order_ops.while_loop import while_loop

torch._inductor.config.triton.slow_path_cudagraph_asserts = True

w = torch.randn(16, 16, device="cuda")
b = torch.randn(16, device="cuda")

def f(x):
    y = x @ w

    def cond_fn(i, carry):
        return i < 3

    def body_fn(i, carry):
        return i + 1, carry + b

    _, y = while_loop(cond_fn, body_fn, (torch.tensor(0, device="cuda"), y))
    return y

x = torch.randn(4, 16, device="cuda")
compiled = torch.compile(f, mode="reduce-overhead", fullgraph=True)
for i in range(3):
    result = compiled(x)
