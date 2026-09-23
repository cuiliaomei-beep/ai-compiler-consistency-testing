# source: https://github.com/pytorch/pytorch/issues/171191
# title: torch.compile (Inductor) ignores float64→float32 dtype promotion in SDPA, diverging from eager semantics
# state: closed  created: 2025-12-23
# mined automatically; the harness records the torch.compile target and its first call

import torch
import torch.nn as nn
import torch.nn.functional as F

torch.manual_seed(0)

class AttentionWithFloat64Mask(nn.Module):
    def __init__(self):
        super().__init__()
        self.num_heads = 4
        self.head_size = 16
        self.seq_len = 32

    def forward(self, query, key, value, attention_mask):
        bs = query.size(0)
        n_head = query.size(1)
        head_size = query.size(3)
        
        q = query.view(bs * n_head, -1, head_size)
        k = key.reshape(bs * n_head, -1, head_size)
        v = value.reshape(bs * n_head, -1, head_size)
        
        # Compute attention scores (float32)
        attn_weights = torch.bmm(q, k.transpose(1, 2))
        
        # Add attention mask (float64) to attn_weights (float32)
        # This triggers dtype promotion to float64
        attn_weights = attn_weights.view(bs, n_head, self.seq_len, -1) + attention_mask
        attn_weights = attn_weights.view(bs * n_head, self.seq_len, -1)
        
        # Softmax preserves float64
        attn_weights = F.softmax(attn_weights, dim=-1)
        
        # Conditional conversion (doesn't trigger for float32 query)
        if query.dtype == torch.half:
            attn_weights = attn_weights.to(torch.half)
        
        # This bmm has dtype mismatch: attn_weights (float64) vs v (float32)
        attn_output = torch.bmm(attn_weights, v)
        attn_output = attn_output.view(bs, n_head, self.seq_len, head_size)
        
        return attn_output


model = AttentionWithFloat64Mask().cuda()

# Input tensors
batch_size, num_heads, seq_len, head_size = 2, 4, 32, 16
query = torch.randn(batch_size, num_heads, seq_len, head_size, dtype=torch.float32, device='cuda')
key = torch.randn(batch_size, num_heads, seq_len, head_size, dtype=torch.float32, device='cuda')
value = torch.randn(batch_size, num_heads, seq_len, head_size, dtype=torch.float32, device='cuda')

# Float64 attention mask (causes dtype promotion issue)
attention_mask = torch.randint(-2, 2, (batch_size, num_heads, seq_len, seq_len), 
                                dtype=torch.float64, device='cuda')

with torch.no_grad():
    # Eager mode - raises error
    print("Eager mode:")
    try:
        eager_output = model(query, key, value, attention_mask)
        print(f"  Output shape: {eager_output.shape}")
    except RuntimeError as e:
        print(f"  Error: {e}")
    
    # Compiled mode - succeeds (unexpected!)
    print("\nCompiled mode:")
    compiled_model = torch.compile(model, backend='inductor')
    try:
        compiled_output = compiled_model(query, key, value, attention_mask)
        print(f"  Output shape: {compiled_output.shape}")
        print("  Compiled mode succeeded (semantic inconsistency!)")
    except RuntimeError as e:
        print(f"  Error: {e}")
