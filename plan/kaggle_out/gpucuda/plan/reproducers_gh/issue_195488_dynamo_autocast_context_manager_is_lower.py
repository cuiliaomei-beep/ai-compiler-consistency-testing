# source: https://github.com/pytorch/pytorch/issues/195488
# title: [dynamo] autocast context manager is lowered without try/finally, so an exception leaks autocast state
# state: open  created: 2026-08-31
# mined automatically; the harness records the torch.compile target and its first call

import torch

def probe():
    n = torch.autocast_increment_nesting(); torch.autocast_decrement_nesting()
    return n - 1, torch.is_autocast_enabled('cpu'), torch.get_autocast_dtype('cpu')

@torch.compile(backend='eager', fullgraph=True)
def f(x, idx):
    with torch.amp.autocast('cpu', dtype=torch.bfloat16):
        return x.index_select(0, idx)

x = torch.randn(4, 4); bad = torch.tensor([99])
print('before', probe())
for i in range(3):
    try:
        f(x, bad)
    except IndexError:
        pass
    print('after', i, probe())
