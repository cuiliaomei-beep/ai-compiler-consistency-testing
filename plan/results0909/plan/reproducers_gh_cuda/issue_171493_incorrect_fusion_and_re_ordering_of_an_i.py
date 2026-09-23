# source: https://github.com/pytorch/pytorch/issues/171493
# title: incorrect fusion and re-ordering of an index_add
# state: closed  created: 2025-12-30
# mined automatically; the harness records the torch.compile target and its first call

import torch

print('torch version:', torch.__version__)

class Example(torch.nn.Module):
    def __init__(self):
        super().__init__()

    def forward(self, f, batch):

        # f are node features
        # batch is pyg style batch tensor
        
        # 1. some scaling
        f_u = f**2 + 0.00987654321
        
        # 2. reduce f_u to per batch
        n_batch = batch.max() + 1
        F_u_mol = torch.zeros((n_batch, f.shape[1]), device=f.device, dtype=f.dtype)
        F_u_mol.index_add_(0, batch, f_u)         
        
        # uncomment this for correct output
        # torch._dynamo.graph_break()

        # expand back to per node so we can scale the node features
        # also add epsilon so we never divide by zero
        F_u_at_atom = F_u_mol[batch] + 1e-6
        
        # scale the node features by the graph features
        _f = f_u /F_u_at_atom

        return _f

device = 'cuda'

# Create a single graph with many nodes
f = torch.ones(1024, 1, device=device) 
batch = torch.zeros(1024, dtype=torch.long, device=device)

# if we have more than one batch it will work fine
# uncomment this for correct output
# batch[-1] = 1

model = Example().to(device)
compiled_model = torch.compile(model)

# 1. Eager Mode (Correct Answer)
# F_u should be (1024 * (1^2 + 0.0098...)) approx 1034.11
# _f should be approx (1.0098 / 1034.11) = 0.00097
eager_out = model(f, batch)

# 2. Compiled Mode (Incorrect)
compiled_out = compiled_model(f, batch)


print(f"Eager Mean:    {eager_out.mean().item():.6f}")
print(f"Compiled Mean: {compiled_out.mean().item():.6f}")

# Check for discrepancy
diff = (eager_out - compiled_out).abs().max().item()
if diff > 1e-4:
    print(f"BUG REPRODUCED! Max Difference: {diff:.6f}")
else:
    print("Bug not triggered.")
