import torch
torch.manual_seed(0)

def opinfo_nn_functional_hinge_embedding_loss_1105(*args):
    return torch.nn.functional.hinge_embedding_loss(*args, reduction='sum', margin=8.396163642458497)

args = (torch.randn(5).requires_grad_(True), torch.randn(5))

eager = opinfo_nn_functional_hinge_embedding_loss_1105(*args)
torch._dynamo.reset()
compiled = torch.compile(opinfo_nn_functional_hinge_embedding_loss_1105, backend='inductor')(*args)
print('eager   :', eager)
print('compiled:', compiled)
