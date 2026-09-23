# source: https://github.com/pytorch/pytorch/issues/175156
# title: [inductor] Multiple randint calls cause inconsistent RNG results between eager and compiled mode after fixing the rng seed
# state: closed  created: 2026-02-17
# mined automatically; the harness records the torch.compile target and its first call

import torch
import torch._dynamo
torch._inductor.config.fallback_random = True

def fn():
    torch.manual_seed(0)
    out = torch.randint(0, 100, (4,1), dtype=torch.int64)  # Shape and integer range are not important.
    other = torch.randint(0, 100, (2,1), dtype=torch.int64) # No inconsistency if remove this line, although the value won't be returned.
    return out
    
cfunc = torch.compile(fn, backend='inductor')
torch.manual_seed(0)
out1 = fn()
torch.manual_seed(0)
out2 = cfunc()

print(f'{out1=}')
'''
out1=tensor([[44],
        [39],
        [33],
        [60]])
'''
print(f'{out2=}')
'''
out2=tensor([[33],
        [60],
        [63],
        [79]])
'''

torch.testing.assert_close(out1, out2, equal_nan=True)
