# torchvision.ops.nms under torch.compile (data-dependent output shape)
import torch
import torchvision

torch.manual_seed(0)
boxes = torch.rand(32, 4) * 50
boxes[:, 2:] += boxes[:, :2] + 1
scores = torch.rand(32)


def f(boxes, scores):
    keep = torchvision.ops.nms(boxes, scores, 0.5)
    return boxes[keep].sum(dim=0), keep.numel()


print(torch.compile(f)(boxes, scores))
