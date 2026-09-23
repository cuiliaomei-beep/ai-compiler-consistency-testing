# source: https://github.com/pytorch/pytorch/issues/177652
# title: [inductor] torch.compile's RNG state is inconsistent with eager on non-contiguous tensor when size >= 16
# state: closed  created: 2026-03-17
# mined automatically; the harness records the torch.compile target and its first call

import torch
import itertools
torch._inductor.config.fallback_random = True

def fn(x):
    torch.manual_seed(0)
    return torch.randn_like(x)

# shape[0] * shape[1] >= 16 and shape[0], shape[1] != 1
for shape in itertools.product(range(1, 17), range(1, 17)):
    shape = shape
    x1 = torch.zeros(shape).permute(1, 0)
    x2 = torch.zeros(shape).permute(1, 0)
    
    cfunc = torch.compile(fn, backend='inductor')
    
    torch.manual_seed(0)
    out1 = fn(x1)
    # print(f'{out1=}')
    
    torch.manual_seed(0)
    out2 = fn(x1)
    # print(f'{out2=}')
    
    torch.manual_seed(0)
    out3 = cfunc(x2)
    # print(f'{out3=}')
    
    torch.manual_seed(0)
    out4 = cfunc(x2)
    # print(f'{out4=}')
    
    try:
        torch.testing.assert_close(out1, out3, equal_nan=True)
    except AssertionError as e:
        print(f'Shape {shape} will cause inconsistency.')
