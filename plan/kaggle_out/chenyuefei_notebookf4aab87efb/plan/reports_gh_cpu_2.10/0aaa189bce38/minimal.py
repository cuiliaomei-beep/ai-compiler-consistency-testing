import torch
torch.manual_seed(0)

def forward(self, values):
        crow_indices = torch.tensor([0, 2, 4], dtype=torch.int64)
        col_indices = torch.tensor([0, 1, 0, 1], dtype=torch.int64)
        size = (2, 2)
        sparse = torch.ops.aten.sparse_csr_tensor(crow_indices, col_indices, values, size)
        return sparse

args = (torch.randn(4).requires_grad_(True),)

eager = f(*args)
torch._dynamo.reset()
compiled = torch.compile(f, backend='eager')(*args)
print('eager   :', eager)
print('compiled:', compiled)
