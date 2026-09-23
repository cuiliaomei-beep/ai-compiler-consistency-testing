# source: https://github.com/pytorch/pytorch/issues/178676
# title: `torch.compile` crashes with `CantSplit` TypeError on valid model using `split_with_sizes` + `reshape` + `cat` pattern
# state: closed  created: 2026-03-28
# mined automatically; the harness records the torch.compile target and its first call

import torch
import torch.nn as nn

class Model(nn.Module):
    def __init__(self):
        super().__init__()
        self.embedding = nn.Embedding(num_embeddings=128, embedding_dim=32)
        self.linear = nn.Linear(32, 96)
        self.conv = nn.Conv2d(3, 16, 3, padding=1)

    def forward(self, x, indices):
        embedded = self.embedding(indices)
        linear_out = self.linear(embedded)
        conv_out = self.conv(x)
        batch_size = conv_out.shape[0]
        conv_flat = conv_out.view(batch_size, -1)
        seq_out = linear_out[:, -1, :]
        combined = torch.cat([seq_out, conv_flat], dim=1)
        split_sizes = [32, 64, combined.size(1) - 96]
        chunks = torch.ops.aten.split_with_sizes.default(
            combined, split_sizes=split_sizes, dim=1
        )
        chunk0 = chunks[0]
        chunk1 = chunks[1]
        chunk2 = chunks[2]
        chunk0_reshaped = torch.ops.aten.reshape.default(chunk0, (batch_size, 4, 8))
        chunk1_reshaped = torch.ops.aten.reshape.default(chunk1, (batch_size, 8, 8))
        chunk2_reshaped = torch.ops.aten.reshape.default(chunk2, (batch_size, -1, 8))
        output = torch.ops.aten.cat.default(
            [chunk0_reshaped, chunk1_reshaped, chunk2_reshaped], dim=1
        )
        return output


model = Model().cuda()
x = torch.randn(2, 3, 32, 32, dtype=torch.float32).cuda()
indices = torch.randint(0, 128, (2, 10), dtype=torch.long).cuda()

# Eager: succeeds
with torch.no_grad():
    eager_out = model(x, indices)
    print(f"eager: OK — shape={eager_out.shape}")  # [2, 2060, 8]

# Compiled: crashes
torch._dynamo.reset()
compiled_model = torch.compile(model)
try:
    with torch.no_grad():
        compiled_out = compiled_model(x, indices)
        print(f"compile: OK — shape={compiled_out.shape}")
except Exception as e:
    print(f"compile: ERROR — {type(e).__name__}: {e}")
