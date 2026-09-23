# Real model reproducer (NEXT_DIRECTIONS 5.7): convnext_tiny / bf16_autocast
# torchvision 0.29.0+cpu; random weights, fixed seed; input 2x3x64x64.
import torch
import torchvision

torch.manual_seed(0)
SIZE = 64

model = torchvision.models.convnext_tiny(weights=None)
model.eval()
x = torch.randn(2, 3, SIZE, SIZE)


def f(x):
    with torch.autocast(x.device.type, dtype=torch.bfloat16):
        return model(x)


print(torch.compile(f)(x))
