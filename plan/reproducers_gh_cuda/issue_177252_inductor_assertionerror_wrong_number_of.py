# source: https://github.com/pytorch/pytorch/issues/177252
# title: [Inductor] AssertionError: wrong number of dimensions1 in backward() with dynamic shape involving nonzero() and item()
# state: closed  created: 2026-03-12
# mined automatically; the harness records the torch.compile target and its first call

import torch
torch._dynamo.config.capture_scalar_outputs = True
torch._dynamo.config.capture_dynamic_output_shape_ops = True

def f(x):
    num = x.nonzero().numel()
    num = x.new_tensor([num]).item()
    y = w * x
    return y.sum() / num

x = torch.randn(4)
w = torch.tensor(0.0, requires_grad=True)

loss1 = torch.compile(f, dynamic=True, backend="aot_eager")(x)
loss1.backward()

loss2 = torch.compile(f, dynamic=True, backend="inductor")(x)
loss2.backward() # AssertionError: wrong number of dimensions1
