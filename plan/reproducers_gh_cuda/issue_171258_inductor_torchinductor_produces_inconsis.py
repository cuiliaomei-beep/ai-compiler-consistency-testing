# source: https://github.com/pytorch/pytorch/issues/171258
# title: [Inductor] TorchInductor produces inconsistent results with eager for `aten.fractional_max_pool2d`
# state: closed  created: 2025-12-24
# mined automatically; the harness records the torch.compile target and its first call

import torch

def model_func(self, kernel_size, output_size, random_samples):
    out = torch.ops.aten.fractional_max_pool2d(self, kernel_size=kernel_size,output_size=output_size, random_samples=random_samples)
    return out

op_config = {'self':torch.randn([1, 3, 224, 224],dtype=torch.float32, device='cuda'),'kernel_size':[3, 3],'output_size':[112, 112],'random_samples':torch.randn([1, 3, 2],dtype=torch.float32, device='cuda')}

compiled_eager = torch.compile(model_func, backend="eager")
out1 = compiled_eager(**op_config)
out2 = compiled_eager(**op_config)
torch.testing.assert_close(out1, out2)
print("No randomness!")



compiled_inductor = torch.compile(model_func, backend="inductor", options={"trace.enabled": True,})
out_inductor = compiled_inductor(**op_config)
torch.testing.assert_close(out1, out_inductor)
