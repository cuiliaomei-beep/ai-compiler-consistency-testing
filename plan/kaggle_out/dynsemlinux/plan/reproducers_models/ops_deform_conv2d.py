# torchvision.ops.deform_conv2d under torch.compile
import torch
import torchvision

torch.manual_seed(0)
x = torch.randn(1, 4, 10, 10)
offset = torch.randn(1, 2 * 3 * 3, 8, 8) * 0.5
weight = torch.randn(6, 4, 3, 3)
mask = torch.rand(1, 3 * 3, 8, 8)


def f(x, offset, weight, mask):
    return torchvision.ops.deform_conv2d(x, offset, weight, mask=mask)


print(torch.compile(f)(x, offset, weight, mask))
