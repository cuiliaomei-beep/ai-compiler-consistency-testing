import torch
torch.manual_seed(0)

def container_len(xs):
    if len(xs) > 2:
        return xs[0] + xs[2]
    return xs[0] * 2.0

args = ([tensor([[-1.1258, -1.1524, -0.2506, -0.4339],
        [ 0.8487,  0.6920, -0.3160, -2.1152],
        [ 0.3223, -1.2633,  0.3500,  0.3081],
        [ 0.1198,  1.2377,  1.1168, -0.2473]]), tensor([[-1.3527, -1.6959,  0.5667,  0.7935],
        [ 0.5988, -1.5551, -0.3414,  1.8530],
        [ 0.7502, -0.5855, -0.1734,  0.1835],
        [ 1.3894,  1.5863,  0.9463, -0.8437]]), tensor([[-0.6136,  0.0316, -0.4927,  0.2484],
        [ 0.4397,  0.1124,  0.6408,  0.4412],
        [-0.1023,  0.7924, -0.2897,  0.0525],
        [ 0.5229,  2.3022, -1.4689, -1.5867]])],)

# context A then context B on the same compiled callable (no reset)
# A = {} (base)
# B = {'dtype': 'float16'}
args_b = ([tensor([[-1.1258, -1.1524, -0.2506, -0.4339],
        [ 0.8487,  0.6920, -0.3160, -2.1152],
        [ 0.3223, -1.2633,  0.3500,  0.3081],
        [ 0.1198,  1.2377,  1.1168, -0.2473]]), tensor([[-1.3527, -1.6959,  0.5667,  0.7935],
        [ 0.5988, -1.5551, -0.3414,  1.8530],
        [ 0.7502, -0.5855, -0.1734,  0.1835],
        [ 1.3894,  1.5863,  0.9463, -0.8437]]), tensor([[-0.6136,  0.0316, -0.4927,  0.2484],
        [ 0.4397,  0.1124,  0.6408,  0.4412],
        [-0.1023,  0.7924, -0.2897,  0.0525],
        [ 0.5229,  2.3022, -1.4689, -1.5867]])],)
torch._dynamo.reset()
compiled = torch.compile(container_len, backend='inductor')
compiled(*args)              # warm the cache under A
warm = compiled(*args_b)     # execute under B without a reset
torch._dynamo.reset()
cold = torch.compile(container_len, backend='inductor')(*args_b)
eager = container_len(*args_b)
print('eager :', eager)
print('cold  :', cold)
print('warm  :', warm)
