import torch
torch.manual_seed(0)

def opinfo_new_empty_strided(*args):
    return torch.new_empty_strided(*args, (2, 3), (7, 8), dtype=torch.float32, device='cpu')

args = (torch.randn(2),)

# context A then context B on the same compiled callable (no reset)
# A = {} (base)
# B = {'dtype': 'float16'}
args_b = (torch.randn(5).to(torch.float16),)
torch._dynamo.reset()
compiled = torch.compile(opinfo_new_empty_strided, backend='inductor')
compiled(*args)              # warm the cache under A
warm = compiled(*args_b)     # execute under B without a reset
torch._dynamo.reset()
cold = torch.compile(opinfo_new_empty_strided, backend='inductor')(*args_b)
eager = opinfo_new_empty_strided(*args_b)
print('eager :', eager)
print('cold  :', cold)
print('warm  :', warm)
