# source: https://github.com/pytorch/pytorch/issues/179571
# title: `torch.compile` raises error for constant-tensor cumsum pattern (`torch.full → cumsum`) while eager mode succeeds
# state: closed  created: 2026-04-07
# mined automatically; the harness records the torch.compile target and its first call

import os
os.environ["TRITON_BACKENDS_IN_TREE"] = "1"

import torch
import torch.nn as nn

class MonotonicSequenceModel(nn.Module):
    def __init__(self, input_dim=64, hidden_dim=128, seq_len=50, fill_value=1.0, dropout_p=0.1):
        super().__init__()
        self.seq_len = seq_len
        self.fill_value = fill_value

        self.input_proj = nn.Linear(input_dim, hidden_dim)
        self.norm1 = nn.LayerNorm(hidden_dim)

        self.fwd_fc = nn.Linear(hidden_dim, hidden_dim)
        self.bwd_fc = nn.Linear(hidden_dim, hidden_dim)

        self.combine = nn.Linear(hidden_dim * 2, hidden_dim)
        self.norm2 = nn.LayerNorm(hidden_dim)
        self.output_fc = nn.Linear(hidden_dim, hidden_dim)
        self.dropout = nn.Dropout(p=dropout_p)

    def forward(self, x):
        # x: [B, seq_len, input_dim]
        batch_size, seq_len, _ = x.shape

        x = self.input_proj(x)           # [B, seq_len, hidden_dim]
        x = self.norm1(x)

        # Create constant tensor and apply cumsum -> monotonic sequence
        # This is the pointless_cumsum_replacement target pattern:
        #   torch.full((N,), c) -> cumsum(dim=0) == c * arange(1, N+1)
        constant_tensor = torch.full(
            (seq_len,), self.fill_value, dtype=torch.float32, device=x.device
        )

        # Forward monotonic sequence via cumsum of constant
        fwd_seq = torch.cumsum(constant_tensor, dim=0)          # [seq_len]
        fwd_weights = fwd_seq.unsqueeze(0).unsqueeze(-1)        # [1, seq_len, 1]
        fwd_branch = self.fwd_fc(x * fwd_weights)               # [B, seq_len, hidden_dim]

        # Backward monotonic sequence: flip -> cumsum -> flip
        flipped_const = torch.flip(constant_tensor, dims=[0])
        bwd_seq = torch.cumsum(flipped_const, dim=0)
        bwd_seq = torch.flip(bwd_seq, dims=[0])                 # [seq_len]
        bwd_weights = bwd_seq.unsqueeze(0).unsqueeze(-1)        # [1, seq_len, 1]
        bwd_branch = self.bwd_fc(x * bwd_weights)               # [B, seq_len, hidden_dim]

        # Combine forward and backward branches
        combined = torch.cat([fwd_branch, bwd_branch], dim=-1)  # [B, seq_len, hidden_dim*2]
        combined = self.combine(combined)                         # [B, seq_len, hidden_dim]
        combined = self.dropout(combined)

        # Residual connection
        out = x + combined
        out = self.norm2(out)
        out = self.output_fc(out)
        return out


device = "cuda"
torch.manual_seed(42)
model = MonotonicSequenceModel(
    input_dim=64, hidden_dim=128, seq_len=50, fill_value=1.0, dropout_p=0.0
).to(device).eval()
x = torch.randn(4, 50, 64, device=device)

# Eager: runs successfully
with torch.no_grad():
    eager_out = model(x)
print(f"Eager output shape: {eager_out.shape}")
print(f"Eager output range: [{eager_out.min().item():.4f}, {eager_out.max().item():.4f}]")
print("Eager: OK")

# Compiled: raises error
torch._dynamo.reset()
compiled = torch.compile(model, backend="inductor")
try:
    with torch.no_grad():
        comp_out = compiled(x)
    # If it doesn't crash, check for status difference
    diff = (eager_out.float() - comp_out.float()).abs()
    print(f"Compiled max_diff: {diff.max().item():.6e}")
except Exception as e:
    print(f"torch.compile FAILED: {type(e).__name__}: {e}")
