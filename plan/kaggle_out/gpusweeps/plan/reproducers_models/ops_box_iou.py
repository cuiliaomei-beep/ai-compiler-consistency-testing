# torchvision.ops.box_iou / box_convert under torch.compile
import torch
import torchvision

torch.manual_seed(0)
a = torch.rand(6, 4) * 20
a[:, 2:] += a[:, :2] + 1
b = torch.rand(5, 4) * 20
b[:, 2:] += b[:, :2] + 1


def f(a, b):
    iou = torchvision.ops.box_iou(a, b)
    c = torchvision.ops.box_convert(a, "xyxy", "cxcywh")
    return iou, c, torchvision.ops.generalized_box_iou(a, b)


print(torch.compile(f)(a, b))
