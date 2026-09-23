# source: https://github.com/pytorch/pytorch/issues/145372
# title: [XPU] torch.nn.functional.pad brings wrong results with torch.compile on Intel GPU
# state: closed  created: 2025-01-22
# mined automatically; the harness records the torch.compile target and its first call

import torch

class Model(torch.nn.Module):
    def __init__(self):
        super().__init__()

    def forward(self, *args):
        pad = torch.nn.functional.pad(args[0], (0, 1, 1, 0), mode = 'constant', value = 0.5)
        return pad

m = Model()

inp = torch.randn((1, 1), dtype=torch.float32)
print(inp)
# tensor([[-0.5137]])

m.to('cpu')
cpu_out = m(inp.to('cpu'))
print(cpu_out)
# tensor([[ 0.5000,  0.5000],
#         [-0.5137,  0.5000]])

m.to('xpu')
xpu_out = m(inp.to('xpu'))
print(xpu_out)
# tensor([[ 0.5000,  0.5000],
#         [-0.5137,  0.5000]], device='xpu:0')

opt = torch.compile(m, fullgraph=True, backend='inductor', mode=None)

opt.to('cpu')
cpu_out = opt(inp.to('cpu'))
print(cpu_out)
# tensor([[ 0.5000,  0.5000],
#         [-0.5137,  0.5000]])

opt.to('xpu')
xpu_out = opt(inp.to('xpu'))
print(xpu_out) # Different!
# tensor([[-0.5137, -0.5137],
#         [-0.5137, -0.5137]], device='xpu:0')
