import torch
torch.manual_seed(0)

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

args = (torch.randn(1, 1, 32, 16), torch.randn(1, 1, 32, 16), torch.randn(1, 1, 32, 16), torch.randn(1, 1, 32, 32).to(torch.float64))

eager = f(*args)
torch._dynamo.reset()
compiled = torch.compile(f, backend='inductor')(*args)
print('eager   :', eager)
print('compiled:', compiled)
