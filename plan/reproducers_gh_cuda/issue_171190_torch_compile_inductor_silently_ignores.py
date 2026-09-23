# source: https://github.com/pytorch/pytorch/issues/171190
# title: torch.compile (Inductor) silently ignores explicit dtype casts in SDPA, diverging from eager semantics
# state: closed  created: 2025-12-23
# mined automatically; the harness records the torch.compile target and its first call

import torch
import torch.nn as nn

torch.manual_seed(0)

class AttentionWithDtypeConversion(nn.Module):
    def __init__(self, num_heads=4, head_dim=16):
        super().__init__()
        self.num_heads = num_heads
        self.head_dim = head_dim
        self.scale_factor = head_dim ** (-0.5)
        self.query_proj = nn.Linear(64, num_heads * head_dim)
        self.key_proj = nn.Linear(64, num_heads * head_dim)
        self.value_proj = nn.Linear(64, num_heads * head_dim)
        self.softmax = nn.Softmax(dim=-1)

    def forward(self, query, key, value):
        batch_size = query.size(0)
        
        q = self.query_proj(query).view(batch_size, -1, self.num_heads, self.head_dim)
        k = self.key_proj(key).view(batch_size, -1, self.num_heads, self.head_dim)
        v = self.value_proj(value).view(batch_size, -1, self.num_heads, self.head_dim)
        
        q = q.permute(0, 2, 1, 3)
        k = k.permute(0, 2, 1, 3)
        v = v.permute(0, 2, 1, 3)
        
        # Compute attention scores
        scores = torch.matmul(q, k.transpose(-2, -1)) * self.scale_factor
        
        # Explicit dtype conversion: scores -> float32 for numerical stability
        scores = scores.float()
        attn_weights = self.softmax(scores)
        
        # Explicit dtype conversion: attn_weights -> float16
        attn_weights = attn_weights.half()
        
        # This matmul fails in eager mode: attn_weights is float16, v is float32
        output = torch.matmul(attn_weights, v)
        
        output = output.permute(0, 2, 1, 3).contiguous()
        return output.view(batch_size, -1, self.num_heads * self.head_dim)


model = AttentionWithDtypeConversion().cuda()
query = torch.randn(2, 32, 64, device='cuda')
key = torch.randn(2, 32, 64, device='cuda')
value = torch.randn(2, 32, 64, device='cuda')

with torch.no_grad():
    # Eager mode - raises error
    print("Eager mode:")
    try:
        eager_output = model(query, key, value)
        print(f"  Output shape: {eager_output.shape}")
    except RuntimeError as e:
        print(f"  Error: {e}")
    
    # Compiled mode - succeeds (unexpected!)
    print("\nCompiled mode:")
    compiled_model = torch.compile(model, backend='inductor')
    try:
        compiled_output = compiled_model(query, key, value)
        print(f"  Output shape: {compiled_output.shape}")
        print("  Compiled mode succeeded (semantic inconsistency!)")
    except RuntimeError as e:
        print(f"  Error: {e}")
