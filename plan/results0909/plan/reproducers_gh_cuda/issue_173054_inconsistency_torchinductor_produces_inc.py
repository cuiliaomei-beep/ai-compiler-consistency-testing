# source: https://github.com/pytorch/pytorch/issues/173054
# title: [Inconsistency] TorchInductor produces incorrect result for aten.hardswish_backward followed by aten.add
# state: closed  created: 2026-01-22
# mined automatically; the harness records the torch.compile target and its first call

import torch

def model_func(grad_output, self):
    out = torch.ops.aten.hardswish_backward(grad_output, self=self,)
    out = out + 1  # inconcsistency only when add this line
    return out

op_config = {'grad_output':torch.randn([10, 20],dtype=torch.bfloat16, device='cuda'),'self':torch.randn([10, 20],dtype=torch.bfloat16, device='cuda'),}

compiled_eager = torch.compile(model_func, backend="eager")
out1 = compiled_eager(**op_config)
compiled_inductor = torch.compile(model_func, backend="inductor")
out_inductor = compiled_inductor(**op_config)
torch.testing.assert_close(out1, out_inductor)
