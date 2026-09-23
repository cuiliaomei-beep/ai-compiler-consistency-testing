import torch
torch.manual_seed(0)

def forward(self, x):
        b, t, _ = x.shape
        q = self.q(x).view(b, t, H, D).permute(0, 2, 1, 3)   # (B, H, T, D)
        k = self.k(x).view(b, t, H, D).permute(0, 2, 3, 1)   # (B, H, D, T) pre-transposed
        v = self.v(x).view(b, t, H, D).permute(0, 2, 1, 3)   # (B, H, T, D)
        w = (torch.matmul(q, k) * (D ** -0.5)).softmax(dim=-1)
        return (w @ v).permute(0, 2, 1, 3).reshape(b, t, E)

args = (torch.randn(1, 8, 64).requires_grad_(True),)

eager = f(*args)
torch._dynamo.reset()
compiled = torch.compile(f, backend='inductor')(*args)
print('eager   :', eager)
print('compiled:', compiled)
