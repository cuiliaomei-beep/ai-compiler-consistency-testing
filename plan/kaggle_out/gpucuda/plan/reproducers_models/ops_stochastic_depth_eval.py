# torchvision.ops.StochasticDepth / DropBlock in eval mode (identity) + FrozenBatchNorm2d
import torch
import torchvision

torch.manual_seed(0)


class Net(torch.nn.Module):
    def __init__(self):
        super().__init__()
        self.bn = torchvision.ops.FrozenBatchNorm2d(3)
        self.sd = torchvision.ops.StochasticDepth(0.2, "row")
        self.conv = torch.nn.Conv2d(3, 3, 3, padding=1)

    def forward(self, x):
        return self.sd(self.conv(self.bn(x))) + x


model = Net().eval()
x = torch.randn(2, 3, 8, 8)
print(torch.compile(model)(x))
