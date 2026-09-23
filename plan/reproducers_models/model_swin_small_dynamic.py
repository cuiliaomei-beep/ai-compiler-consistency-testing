# Real model reproducer (NEXT_DIRECTIONS 5.7): swin_small / dynamic
# torchvision 0.29.0+cpu; random weights, fixed seed; input 2x3x64x64.
import torch
import torchvision

torch.manual_seed(0)
SIZE = 64

model = torchvision.models.swin_transformer.SwinTransformer(patch_size=[4, 4], embed_dim=24, depths=[2, 2], num_heads=[2, 2], window_size=[4, 4])
model.eval()
x = torch.randn(2, 3, SIZE, SIZE)

compiled = torch.compile(model, dynamic=True)
print(compiled(x))
