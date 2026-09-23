# Real model reproducer (NEXT_DIRECTIONS 5.7): mobilenet_v2 / dynamic
# torchvision 0.29.0+cpu; random weights, fixed seed; input 2x3x64x64.
import torch
import torchvision

torch.manual_seed(0)
SIZE = 64

model = torchvision.models.mobilenet_v2(weights=None)
model.eval()
x = torch.randn(2, 3, SIZE, SIZE)

compiled = torch.compile(model, dynamic=True)
print(compiled(x))
