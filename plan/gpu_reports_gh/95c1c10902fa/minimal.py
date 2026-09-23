import torch
torch.manual_seed(0)

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

args = (torch.randn(1, 8, 512),)

eager = f(*args)
torch._dynamo.reset()
compiled = torch.compile(f, backend='inductor')(*args)
print('eager   :', eager)
print('compiled:', compiled)
