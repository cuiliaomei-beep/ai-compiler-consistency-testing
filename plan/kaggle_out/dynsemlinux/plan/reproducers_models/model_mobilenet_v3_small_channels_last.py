# Real model reproducer (NEXT_DIRECTIONS 5.7): mobilenet_v3_small / channels_last
# torchvision 0.29.0+cpu; random weights, fixed seed; input 2x3x64x64.
import torch
import torchvision

torch.manual_seed(0)
SIZE = 64

model = torchvision.models.mobilenet_v3_small(weights=None)
model.eval()
x = torch.randn(2, 3, SIZE, SIZE)
model = model.to(memory_format=torch.channels_last)
x = x.contiguous(memory_format=torch.channels_last)

compiled = torch.compile(model)
print(compiled(x))
