# source: https://github.com/pytorch/pytorch/issues/175496
# title: [inductor] model with torch.compile outputs inconsistent result when return value includes detached tensor
# state: closed  created: 2026-02-22
# mined automatically; the harness records the torch.compile target and its first call

import os

os.environ['TORCHINDUCTOR_FORCE_DISABLE_CACHES'] = '1' # The inconsistency will occasionally disappear if remove this.
import torch

def fn(x, y):
    x.div_(y)
    z = torch.nn.functional.softmax(x, dim=-1)
    return z, x.detach()  # The x.detach() part cannot be removed or changed to z, x, even though the inconsistency part is output[0].
    
torch.manual_seed(0)
x1 = torch.randn(2, 4, 4, 4, dtype=torch.float64)
y1 = torch.randn(4, 1, 1, dtype=torch.float64)
# print(y1)
x2 = x1.clone()
y2 = y1.clone()

cfunc = torch.compile(fn)
output1 = fn(x1, y1)
output2 = cfunc(x2, y2)

torch.testing.assert_close(output1[0], output2[0], equal_nan=True)
