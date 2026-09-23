# source: https://github.com/pytorch/pytorch/issues/179534
# title: torch.compile fails on aten.sparse_csr_tensor with DataDependentOutputException (aten._local_scalar_dense)
# state: closed  created: 2026-04-07
# mined automatically; the harness records the torch.compile target and its first call

import torch
import torch.nn as nn

class MinimalSparseModel(nn.Module):

    def forward(self, values):
        crow_indices = torch.tensor([0, 2, 4], dtype=torch.int64)
        col_indices = torch.tensor([0, 1, 0, 1], dtype=torch.int64)
        size = (2, 2)
        sparse = torch.ops.aten.sparse_csr_tensor(crow_indices, col_indices, values, size)
        return sparse
values = torch.tensor([1.0, 2.0, 3.0, 4.0])
model = MinimalSparseModel()
eager_out = model(values)
print(f'Eager output: {eager_out}')
print(f'Eager output shape: {eager_out.shape}')
compiled_model = torch.compile(model, fullgraph=False)
try:
    compiled_out = compiled_model(values)
    print(f'Compiled output: {compiled_out}')
except Exception as e:
    print(f' Compilation failed:')
    print(f'Error type: {type(e).__name__}')
    print(f'Error message: {e}')
