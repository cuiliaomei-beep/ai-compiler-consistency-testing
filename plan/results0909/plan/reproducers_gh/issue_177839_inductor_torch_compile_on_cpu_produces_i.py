# source: https://github.com/pytorch/pytorch/issues/177839
# title: [inductor] torch.compile on CPU produces incorrect result when applying `logit` on sliced tensor with specific shape
# state: closed  created: 2026-03-19
# mined automatically; the harness records the torch.compile target and its first call

import torch
import itertools

def fn(x):
    return torch.special.logit(x, eps=0.51)  # Condition: eps > 0.5
    
cfunc = torch.compile(fn, backend='eager')
    
# Inconsistency-triggering condition: shape1 >= 2 and shape2 - cut_value >= 16.
for shape1, shape2, cut_value in itertools.product(range(1, 3), range(15, 21), range(1, 6)):
    shape = (shape1, shape2)
    x1 = torch.full(shape, 0.3)
    x1 = x1[:, :(shape2 - cut_value)]  # No inconsistency if removing the slicing.
    x2 = x1.clone()
    
    out1 = fn(x1)
    out2 = cfunc(x2)
    
    try:
        torch.testing.assert_close(out1, out2, equal_nan=True)
        print(f'Passed for shape={shape}, cut_value={cut_value}')
    except AssertionError:
        print(f'out1={out1},\nout2={out2}')
        print(f'Failed for shape={shape}, cut_value={cut_value}')
