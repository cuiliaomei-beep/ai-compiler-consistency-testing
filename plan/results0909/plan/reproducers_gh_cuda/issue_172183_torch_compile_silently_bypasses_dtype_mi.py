# source: https://github.com/pytorch/pytorch/issues/172183
# title: 🐛 torch.compile silently bypasses dtype mismatch checks in SFDP attention patterns
# state: closed  created: 2026-01-11
# mined automatically; the harness records the torch.compile target and its first call

import torch
import torch.nn as nn
import math

torch.manual_seed(0)

class Model(nn.Module):
    def __init__(self, num_heads=8, head_dim=64, dropout_p=0.0):
        super().__init__()
        self.num_heads = num_heads
        self.head_dim = head_dim
        self.dropout_p = dropout_p
        self.q_proj = nn.Linear(head_dim * num_heads, head_dim * num_heads)
        self.k_proj = nn.Linear(head_dim * num_heads, head_dim * num_heads)
        self.v_proj = nn.Linear(head_dim * num_heads, head_dim * num_heads)
        self.out_proj = nn.Linear(head_dim * num_heads, head_dim * num_heads)

    def forward(self, x):
        batch_size, seq_len, _ = x.shape
        q = self.q_proj(x).reshape(batch_size, seq_len, self.num_heads, self.head_dim)
        k = self.k_proj(x).reshape(batch_size, seq_len, self.num_heads, self.head_dim)
        v = self.v_proj(x).reshape(batch_size, seq_len, self.num_heads, self.head_dim)
        q = q.permute(0, 2, 1, 3)
        k = k.permute(0, 2, 1, 3)
        v = v.permute(0, 2, 1, 3)
        
        # Compute attention scores
        div = q @ k.transpose(-2, -1) / math.sqrt(q.size(-1))
        div = div.to(torch.float32)  # Convert to float32
        attn_weight = torch.softmax(div, dim=-1)
        attn_weight = torch.dropout(attn_weight, self.dropout_p, False)
        attn_weight = attn_weight.to(torch.float16)  # Convert to float16
        
        # BUG: attn_weight is float16, v is float32 - dtype mismatch!
        output = attn_weight @ v
        
        output = output.permute(0, 2, 1, 3).reshape(batch_size, seq_len, -1)
        output = self.out_proj(output)
        return output

func = Model().cuda().eval()
x = torch.randn(2, 16, 512).cuda()

with torch.no_grad():
    # Eager mode - correctly raises error
    print("Eager mode:")
    try:
        result = func(x.clone())
        print(f"  Output shape: {result.shape}")
    except RuntimeError as e:
        print(f"  RuntimeError: {e}")
    
    # Compiled mode - silently succeeds (BUG!)
    print("\nCompiled mode:")
    func1 = torch.compile(func)
    try:
        result = func1(x.clone())
        print(f"  Output shape: {result.shape}, dtype: {result.dtype}")
        print("  WARNING: Compiled mode bypassed dtype check!")
    except RuntimeError as e:
        print(f"  RuntimeError: {e}")
