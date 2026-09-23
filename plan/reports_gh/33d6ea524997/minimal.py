import torch
torch.manual_seed(0)

def fn(x, y):
    x = 2 * x  # x = [[0,2],[4,6]]
    c = torch.cat([x, y], dim=1)  # c = [[0,2,0,1], [4,6,2,3]]
    c[:, [1, 0]] = c[:, [0, 1]]  # c should be [[2,0,0,1], [6,4,2,3]]
    return c[:, :2] + x

args = (torch.randint(0, 4, (1, 2,)), torch.randint(0, 4, (1, 2,)))

eager = fn(*args)
torch._dynamo.reset()
compiled = torch.compile(fn, backend='inductor')(*args)
print('eager   :', eager)
print('compiled:', compiled)
