import torch
torch.manual_seed(0)

def forward(self, x):
        batch_size, seq_len = x.shape[:2]
        # nn.Parameter passed directly to torch.full() — should be .item()
        constant = torch.full(
            (batch_size, seq_len, seq_len),
            fill_value=self.fill_value,  # <-- Parameter, not scalar!
            dtype=x.dtype,
            device=x.device,
        )
        return torch.cumsum(constant, dim=-1)

args = (torch.randn(2, 8, 32),)

eager = f(*args)
torch._dynamo.reset()
compiled = torch.compile(f, backend='eager')(*args)
print('eager   :', eager)
print('compiled:', compiled)
