# source: https://github.com/pytorch/pytorch/issues/158930
# title: torch.compile produces incorrect output for transpose + grouped Conv1d operation
# state: closed  created: 2025-07-23
# mined automatically; the harness records the torch.compile target and its first call

import torch
import torch.nn as nn

class TransposeConv(nn.Module):
    def __init__(self):
        super().__init__()
        self.conv = nn.Conv1d(1024, 1024, kernel_size=3, groups=1024, padding=2)

    def forward(self, x):
        # Input: [batch, seq_len, channels] -> transpose -> [batch, channels, seq_len]
        x = x.transpose(1, 2)
        x = self.conv(x)[..., :1]
        return x

device = torch.device('cuda' if torch.cuda.is_available() else 'cpu')
torch.manual_seed(42)

# Input: [batch, seq_len, channels]
x = torch.randn(32, 1, 1024).to(device)

model = TransposeConv().to(device)
compiled_model = torch.compile(model)

print("Testing transpose + Conv1d:")
with torch.no_grad():
    out1 = model(x)
    out2 = compiled_model(x)

match = torch.allclose(out1, out2, rtol=1e-4)
print(f"  Outputs match: {match}")
print(f"  Max diff: {(out1 - out2).abs().max().item():.2e}")
print(f"  Regular output sample: {out1[0, :5, 0]}")
print(f"  Compiled output sample: {out2[0, :5, 0]}")
