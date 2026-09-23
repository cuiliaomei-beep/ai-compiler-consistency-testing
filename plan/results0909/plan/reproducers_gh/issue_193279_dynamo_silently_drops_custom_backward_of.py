# source: https://github.com/pytorch/pytorch/issues/193279
# title: Dynamo silently drops custom `backward` of `autograd.Function` under `torch.func.grad`, producing wrong gradients
# state: closed  created: 2026-08-13
# mined automatically; the harness records the torch.compile target and its first call

import torch


class SinWithZeroBackward(torch.autograd.Function):
    @staticmethod
    def forward(x):
        return torch.sin(x)

    @staticmethod
    def setup_context(ctx, inputs, output):
        ctx.save_for_backward(*inputs)

    @staticmethod
    def backward(ctx, grad):
        return torch.zeros_like(grad)


def loss(x):
    return SinWithZeroBackward.apply(x).sum()


x = torch.randn(4)

print(torch.func.grad(loss)(x))  # zeros: custom backward respected
print(torch.compile(torch.func.grad(loss), backend="aot_eager", fullgraph=True)(x))
print(torch.cos(x))  # what the compiled version actually returns

# Reverse mode outside torch.func is handled correctly, for comparison:
xg = x.clone().requires_grad_()
torch.compile(loss, backend="aot_eager")(xg).backward()
print(xg.grad)  # zeros: custom backward respected
