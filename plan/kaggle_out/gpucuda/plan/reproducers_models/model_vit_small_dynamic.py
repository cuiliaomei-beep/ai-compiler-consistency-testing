# Real model reproducer (NEXT_DIRECTIONS 5.7): vit_small / dynamic
# torchvision 0.29.0+cpu; random weights, fixed seed; input 2x3x64x64.
import torch
import torchvision

torch.manual_seed(0)
SIZE = 64

model = torchvision.models.vision_transformer.VisionTransformer(image_size=SIZE, patch_size=8, num_layers=2, num_heads=2, hidden_dim=32, mlp_dim=64)
model.eval()
x = torch.randn(2, 3, SIZE, SIZE)

compiled = torch.compile(model, dynamic=True)
print(compiled(x))
