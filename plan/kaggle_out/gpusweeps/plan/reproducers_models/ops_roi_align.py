# torchvision.ops.roi_align under torch.compile (custom op with a meta kernel)
import torch
import torchvision

torch.manual_seed(0)
feat = torch.randn(2, 4, 16, 16)
boxes = torch.tensor([[0, 1.0, 1.0, 9.0, 9.0], [1, 2.0, 3.0, 14.0, 12.0], [0, 0.0, 0.0, 15.0, 15.0]])


def f(feat, boxes):
    return torchvision.ops.roi_align(feat, boxes, output_size=(4, 4), spatial_scale=1.0, sampling_ratio=2, aligned=True)


print(torch.compile(f)(feat, boxes))
