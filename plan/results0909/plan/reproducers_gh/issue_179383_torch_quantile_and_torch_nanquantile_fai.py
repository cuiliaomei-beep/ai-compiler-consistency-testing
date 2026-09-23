# source: https://github.com/pytorch/pytorch/issues/179383
# title: `torch.quantile` and `torch.nanquantile` fail under `torch.compile(dynamic=True)`
# state: closed  created: 2026-04-04
# mined automatically; the harness records the torch.compile target and its first call

import torch
import os
os.environ["TORCHDYNAMO_VERBOSE"] = "1"
os.environ["TORCH_LOGS"] = "+dynamo"
def fn(x):
    return torch.quantile(x, 0.5)

x = torch.tensor([1.0, 3.0, 2.0, 5.0, 4.0])

eager_out = fn(x)
print("eager:", eager_out)

compiled_fn = torch.compile(fn, backend="aot_eager_decomp_partition", dynamic=True)
compiled_fn(x)
