# A stateful module target: BatchNorm updates its running statistics on every call,
# so two eager runs differ unless the harness restores the module state before each
# execution (Program.reset). Kept as a regression check for the loader.
import torch

torch.manual_seed(0)


class Net(torch.nn.Module):
    def __init__(self):
        super().__init__()
        self.bn = torch.nn.BatchNorm2d(3)
        self.conv = torch.nn.Conv2d(3, 3, 3, padding=1)

    def forward(self, x):
        return self.conv(self.bn(x)).relu().sum(dim=(2, 3))


model = Net()
x = torch.randn(2, 3, 8, 8)
compiled = torch.compile(model)
print(compiled(x))
