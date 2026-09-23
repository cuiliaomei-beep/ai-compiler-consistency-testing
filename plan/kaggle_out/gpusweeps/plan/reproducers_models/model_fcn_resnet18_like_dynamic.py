# Real model reproducer (NEXT_DIRECTIONS 5.7): fcn_resnet18_like / dynamic
# torchvision 0.29.0+cpu; random weights, fixed seed; input 2x3x64x64.
import torch
import torchvision

torch.manual_seed(0)
SIZE = 64


class SegNet(torch.nn.Module):
    """FCN-style head on the first two resnet18 stages (segmentation = interpolate + conv)."""

    def __init__(self):
        super().__init__()
        r = torchvision.models.resnet18(weights=None)
        self.stem = torch.nn.Sequential(r.conv1, r.bn1, r.relu, r.maxpool, r.layer1, r.layer2)
        self.head = torch.nn.Sequential(torch.nn.Conv2d(128, 32, 3, padding=1), torch.nn.BatchNorm2d(32),
                                        torch.nn.ReLU(), torch.nn.Dropout(0.1), torch.nn.Conv2d(32, 5, 1))

    def forward(self, x):
        h, w = x.shape[-2:]
        y = self.head(self.stem(x))
        return torch.nn.functional.interpolate(y, size=(h, w), mode="bilinear", align_corners=False)


model = SegNet()
model.eval()
x = torch.randn(2, 3, SIZE, SIZE)

compiled = torch.compile(model, dynamic=True)
print(compiled(x))
