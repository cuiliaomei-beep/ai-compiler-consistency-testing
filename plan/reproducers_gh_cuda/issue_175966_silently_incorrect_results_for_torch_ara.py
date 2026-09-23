# source: https://github.com/pytorch/pytorch/issues/175966
# title: Silently incorrect results for torch.arange + Inductor
# state: closed  created: 2026-02-27
# mined automatically; the harness records the torch.compile target and its first call

import torch

def kek(x):
    return torch.arange(
        0, 11, device=x.device, dtype=torch.int64
    ) * torch.tensor([int(1e9)], dtype=torch.int64, device=x.device)

x = torch.zeros(1, device='cuda')

print(kek(x))
# output:
# tensor([          0,  1000000000,  2000000000,  3000000000,  4000000000,
#          5000000000,  6000000000,  7000000000,  8000000000,  9000000000,
#         10000000000], device='cuda:0')


print(torch.compile(kek, backend="aot_eager_decomp_partition")(x))
# output:
# tensor([          0,  1000000000,  2000000000,  3000000000,  4000000000,
#          5000000000,  6000000000,  7000000000,  8000000000,  9000000000,
#         10000000000], device='cuda:0')


print(torch.compile(kek, backend="inductor")(x))
# output:
# tensor([          0,  1000000000,  2000000000, -1294967296,  -294967296,
#           705032704,  1705032704, -1589934592,  -589934592,   410065408,
#          1410065408], device='cuda:0')
