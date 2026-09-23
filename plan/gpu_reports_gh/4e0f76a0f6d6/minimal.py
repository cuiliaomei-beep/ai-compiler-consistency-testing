import torch
torch.manual_seed(0)

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

args = (torch.randn(2, 64), torch.randn(2, 64), torch.randn(2, 64))

eager = f(*args)
torch._dynamo.reset()
compiled = torch.compile(f, backend='inductor')(*args)
print('eager   :', eager)
print('compiled:', compiled)
