# source: https://github.com/pytorch/pytorch/issues/192985
# title: Dynamo silently drops custom `jvp` of `autograd.Function` under `torch.func.jvp`, producing wrong tangents
# state: open  created: 2026-08-11
# mined automatically; the harness records the torch.compile target and its first call

import torch


class SinWithZeroJvp(torch.autograd.Function):
    @staticmethod
    def forward(x):
        return torch.sin(x)

    @staticmethod
    def setup_context(ctx, inputs, output):
        ctx.save_for_forward(*inputs)
        ctx.save_for_backward(*inputs)

    @staticmethod
    def backward(ctx, grad):
        return torch.zeros_like(grad)

    @staticmethod
    def jvp(ctx, dx):
        return torch.zeros_like(dx)


def f(x, dx):
    return torch.func.jvp(SinWithZeroJvp.apply, (x,), (dx,))[1]


x, dx = torch.randn(4), torch.randn(4)
print(f(x, dx))  # zeros: custom jvp respected
print(
    torch.compile(f, backend="aot_eager", fullgraph=True)(x, dx)
)  # cos(x)*dx: custom jvp dropped

# Backward mode is handled correctly for comparison:
xg = x.clone().requires_grad_()
torch.compile(lambda t: SinWithZeroJvp.apply(t).sum())(xg).backward()
print(xg.grad)  # zeros: custom backward respected
