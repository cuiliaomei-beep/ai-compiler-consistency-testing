# source: https://github.com/pytorch/pytorch/issues/183082
# title: Inductor CPU returns wrong argmax after sin_() and transpose
# state: closed  created: 2026-05-10
# mined automatically; the harness records the torch.compile target and its first call

import torch

def f(x):
    x = x.clone()
    x.sin_()
    return x.t().argmax()

x = torch.tensor([
    [-1.5256, -0.7502, -0.6540, -1.6095, -0.1002, -0.6092, -0.9798],
    [-1.6091, -0.7121,  0.3037, -0.7773, -0.2515, -0.2223,  1.6871],
    [ 0.2284,  0.4676, -0.6970, -1.1608,  0.6995,  0.1991,  0.8657],
    [ 0.2444, -0.6629,  0.8073,  1.1017, -0.1759, -2.2456, -1.4465],
    [ 0.0612, -0.6177, -0.7981, -0.1316, -0.7984,  0.3357,  0.2753],
])

eager = f(x)
compiled = torch.compile(f, backend="inductor")(x)

print("eager =", eager.item())
print("compiled =", compiled.item())
