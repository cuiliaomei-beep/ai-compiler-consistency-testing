# source: https://github.com/pytorch/pytorch/issues/185509
# title: [inductor] Silent incorrect gradients with interpolate, conv2d, max_pool2d and torch.where
# state: closed  created: 2026-05-28
# mined automatically; the harness records the torch.compile target and its first call

import torch
import torch.nn.functional as F


def inner(x, weight, bias):
    y = F.interpolate(
        x,
        scale_factor=(1.5, 1.25),
        mode="bilinear",
        align_corners=False,
    )
    y = y[:, :, 1:7, 1:8]

    conv = F.conv2d(y, weight, bias, padding=1)
    pool = F.max_pool2d(conv, kernel_size=3, stride=1, padding=1)
    threshold = pool.mean(dim=(2, 3), keepdim=True)
    return conv, pool, threshold


def make_mask(x, weight, bias):
    conv, _, threshold = inner(x, weight, bias)
    return conv > threshold


def fn(x, weight, bias, mask):
    conv, pool, _ = inner(x, weight, bias)

    return torch.where(mask, conv, pool)


def clone_inputs(xs):
    return [x.detach().clone().requires_grad_(True) for x in xs]


def run(f, xs, mask):
    out = f(*xs, mask)
    out.sum().backward()
    return out.detach(), [x.grad.detach().clone() for x in xs]


def max_diff(a, b):
    return (a - b).abs().max().item()


def main():
    print("torch:", torch.__version__)
    print("cuda:", torch.version.cuda)

    torch.manual_seed(0)
    device = "cpu"

    inputs = [
        torch.randn(2, 3, 6, 7, device=device, requires_grad=True),
        torch.randn(4, 3, 3, 3, device=device, requires_grad=True),
        torch.zeros(4, device=device, requires_grad=True),
    ]

    inputs_eager = clone_inputs(inputs)
    inputs_comp = clone_inputs(inputs)

    torch._dynamo.reset()
    compiled_mask = torch.compile(make_mask, backend="inductor")

    mask_eager = make_mask(*inputs_eager).detach()
    mask_comp = compiled_mask(*inputs_comp).detach()

    print("mask mismatches:", (mask_eager != mask_comp).sum().item(), "/", mask_eager.numel())

    fixed_mask = mask_eager

    inputs_eager = clone_inputs(inputs)
    inputs_comp = clone_inputs(inputs)

    out_eager, grads_eager = run(fn, inputs_eager, fixed_mask)

    torch._dynamo.reset()
    compiled_fn = torch.compile(fn, backend="inductor")
    out_comp, grads_comp = run(compiled_fn, inputs_comp, fixed_mask)

    print("forward max diff:", max_diff(out_eager, out_comp))

    for i, (ge, gc) in enumerate(zip(grads_eager, grads_comp)):
        diff = max_diff(ge, gc)
        mismatches = ((ge - gc).abs() > 1e-3).sum().item()
        print(f"grad[{i}] max diff:", diff)
        print(f"grad[{i}] mismatches > 1e-3:", mismatches, "/", ge.numel())


if __name__ == "__main__":
    main()
