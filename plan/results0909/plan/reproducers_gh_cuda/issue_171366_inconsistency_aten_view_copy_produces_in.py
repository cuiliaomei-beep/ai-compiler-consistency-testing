# source: https://github.com/pytorch/pytorch/issues/171366
# title: [Inconsistency] aten.view_copy produces inconsistent output shapes between eager and inductor
# state: closed  created: 2025-12-27
# mined automatically; the harness records the torch.compile target and its first call

import torch

def model_func(self, dtype):
    out = torch.ops.aten.view_copy(self, dtype=dtype,)
    return out

op_config = {'self':torch.randint(2, 32, [8, 16],dtype=torch.int32, device='cuda'),'dtype':torch.int64,}

compiled_eager = torch.compile(model_func, backend="eager")
out1 = compiled_eager(**op_config)
compiled_inductor = torch.compile(model_func, backend="inductor")
out_inductor = compiled_inductor(**op_config)
torch.testing.assert_close(out1, out_inductor)
