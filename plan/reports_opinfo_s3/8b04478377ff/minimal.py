import torch
torch.manual_seed(0)

def opinfo_new_empty(*args):
    return torch.new_empty(*args, (10,), dtype=torch.float64)

args = (torch.randn(2),)

# context A then context B on the same compiled callable (no reset)
# A = {} (base)
# B = {'dtype': 'bfloat16'}
args_b = (torch.randn(5).to(torch.bfloat16),)
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
