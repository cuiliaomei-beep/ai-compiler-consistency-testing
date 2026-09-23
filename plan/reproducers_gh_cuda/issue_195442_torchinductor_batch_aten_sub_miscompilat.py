# source: https://github.com/pytorch/pytorch/issues/195442
# title: [TorchInductor] `batch_aten_sub` miscompilation drops `alpha`
# state: open  created: 2026-08-31
# mined automatically; the harness records the torch.compile target and its first call

import torch
from torch._inductor import config
from torch._dynamo.utils import counters


class Model(torch.nn.Module):
    def forward(self, x0, y0, x1, y1, x2, y2, x3, y3, x4, y4):
        z0 = torch.ops.aten.sub.Tensor(x0, y0, alpha=2)
        z1 = torch.ops.aten.sub.Tensor(x1, y1, alpha=2)
        z2 = torch.ops.aten.sub.Tensor(x2, y2, alpha=2)
        z3 = torch.ops.aten.sub.Tensor(x3, y3, alpha=2)
        z4 = torch.ops.aten.sub.Tensor(x4, y4, alpha=2)
        return z0, z1, z2, z3, z4


device = "cuda"
inputs = []
for i in range(5):
    x = torch.full((16, 16), 10.0 + i, device=device)
    y = torch.full((16, 16), 3.0 + i, device=device)
    inputs.extend([x, y])

model = Model().eval()
eager_out = model(*inputs)

torch._dynamo.reset()
counters.clear()

with config.patch({
    "post_grad_fusion_options": {"batch_aten_sub": {}}
}):
    compiled_model = torch.compile(model, backend="inductor", fullgraph=True)
    compiled_out = compiled_model(*inputs)

print("batch_aten_sub count:", counters["inductor"]["batch_aten_sub"])
for ref, out in zip(eager_out, compiled_out):
    print(ref[0, 0].item(), out[0, 0].item())

torch.testing.assert_close(compiled_out, eager_out)
