import torch
torch.manual_seed(0)

def fn(a, b):
    return torch._foreach_sub(a, b, alpha=2.0)

args = ([tensor([ 0.1940,  2.1614, -0.1721,  0.8491], device='cuda:0'), tensor([ 0.1391, -0.1082, -0.7174,  0.7566], device='cuda:0'), tensor([-0.5187,  1.2268,  0.6255, -0.9117], device='cuda:0')], [tensor([-0.6974, -1.8688, -0.8832, -1.6627], device='cuda:0'), tensor([-1.2682, -0.0383, -0.1029,  1.4400], device='cuda:0'), tensor([ 1.4640, -0.3238,  0.7740,  1.5892], device='cuda:0')])

eager = fn(*args)
torch._dynamo.reset()
compiled = torch.compile(fn, backend='inductor')(*args)
print('eager   :', eager)
print('compiled:', compiled)
