import torch
torch.manual_seed(0)

def opinfo_new_empty(*args):
    return torch.new_empty(*args, (3, 2, 2))

args = (torch.randn(0, 5, 0).to(torch.bfloat16),)

# context A then context B on the same compiled callable (no reset)
# A = {'dtype': 'bfloat16'}
# B = {} (base)
args_b = (torch.randn(0, 5, 0),)
torch._dynamo.reset()
compiled = torch.compile(opinfo_new_empty, backend='inductor')
compiled(*args)              # warm the cache under A
warm = compiled(*args_b)     # execute under B without a reset
torch._dynamo.reset()
cold = torch.compile(opinfo_new_empty, backend='inductor')(*args_b)
eager = opinfo_new_empty(*args_b)
print('eager :', eager)
print('cold  :', cold)
print('warm  :', warm)
