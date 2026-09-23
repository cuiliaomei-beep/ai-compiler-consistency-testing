# source: https://github.com/pytorch/pytorch/issues/172184
# title: 🐛 torch.compile silently bypasses device mismatch checks with torch.randperm() in index_add operations
# state: closed  created: 2026-01-11
# mined automatically; the harness records the torch.compile target and its first call

import torch
import torch.nn as nn
import torch.nn.functional as F

torch.manual_seed(0)

class Model(nn.Module):
    def __init__(self):
        super().__init__()
        self.conv = nn.Conv2d(3, 16, kernel_size=3, padding=1)
        self.bn = nn.BatchNorm2d(16)
        self.pool = nn.MaxPool2d(2)
        self.fc = nn.Linear(16 * 16 * 16, 10)

    def forward(self, x, y):
        x = self.conv(x)
        x = self.bn(x)
        x = F.relu(x)
        x = self.pool(x)
        x = x.view(x.size(0), -1)
        x = self.fc(x)
        
        # BUG: randperm creates CPU tensor by default
        idx = torch.randperm(x.size(0))[:y.size(0)]
        
        # index_add with CPU index and CUDA tensors - should fail!
        result = torch.index_add(x, dim=0, source=y, index=idx)
        return result

func = Model().cuda().eval()
x = torch.randn(8, 3, 32, 32).cuda()
y = torch.randn(4, 10).cuda()

with torch.no_grad():
    # Eager mode - correctly raises error
    print("Eager mode:")
    try:
        result = func(x.clone(), y.clone())
        print(f"  Output shape: {result.shape}")
    except RuntimeError as e:
        print(f"  RuntimeError: {e}")
    
    # Compiled mode - silently succeeds (BUG!)
    print("\nCompiled mode:")
    func1 = torch.compile(func)
    try:
        result = func1(x.clone(), y.clone())
        print(f"  Output shape: {result.shape}")
        print("  WARNING: Compiled mode bypassed device check!")
    except RuntimeError as e:
        print(f"  RuntimeError: {e}")
