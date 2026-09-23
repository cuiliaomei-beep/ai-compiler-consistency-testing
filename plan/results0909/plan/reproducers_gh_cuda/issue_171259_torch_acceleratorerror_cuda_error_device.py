# source: https://github.com/pytorch/pytorch/issues/171259
# title: torch.AcceleratorError: CUDA error: device-side assert triggered
# state: closed  created: 2025-12-24
# mined automatically; the harness records the torch.compile target and its first call

import torch

def model_func(self, target):
    out = torch.ops.aten.multilabel_margin_loss(self, target=target,reduction=2)
    return out

op_config = {'self':torch.randn([8, 10],dtype=torch.float32, device='cuda') * 0.1,'target':torch.randint(-32, 32, [8, 10],dtype=torch.int64, device='cuda')}

compiled_eager = torch.compile(model_func, backend="eager")
out1 = compiled_eager(**op_config)
compiled_inductor = torch.compile(model_func, backend="inductor", options={"trace.enabled": True,})
out_inductor = compiled_inductor(**op_config)
torch.testing.assert_close(out1, out_inductor)  #crash
