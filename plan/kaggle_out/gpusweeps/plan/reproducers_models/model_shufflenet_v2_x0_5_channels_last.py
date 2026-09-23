# Real model reproducer (NEXT_DIRECTIONS 5.7): shufflenet_v2_x0_5 / channels_last
# torchvision 0.29.0+cpu; random weights, fixed seed; input 2x3x64x64.
import torch
import torchvision

torch.manual_seed(0)
SIZE = 64

model = torchvision.models.shufflenet_v2_x0_5(weights=None)
model.eval()
x = torch.randn(2, 3, SIZE, SIZE)
model = model.to(memory_format=torch.channels_last)
x = x.contiguous(memory_format=torch.channels_last)

compiled = torch.compile(model)
print(compiled(x))
