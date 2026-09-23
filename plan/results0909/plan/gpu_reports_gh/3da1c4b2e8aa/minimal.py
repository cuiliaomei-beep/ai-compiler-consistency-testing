import torch
torch.manual_seed(0)

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

args = (torch.randn(16, 1).requires_grad_(True), torch.randint(0, 4, (16,)))

eager = f(*args)
torch._dynamo.reset()
compiled = torch.compile(f, backend='inductor')(*args)
print('eager   :', eager)
print('compiled:', compiled)
