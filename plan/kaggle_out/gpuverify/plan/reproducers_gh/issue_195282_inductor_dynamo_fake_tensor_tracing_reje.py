# source: https://github.com/pytorch/pytorch/issues/195282
# title: [inductor] Dynamo fake-tensor tracing rejects a valid broadcasting matmul→attention graph with "Expected size for first two dimensions of batch2 tensor", eager runs fine
# state: open  created: 2026-08-29
# mined automatically; the harness records the torch.compile target and its first call

import math
import torch

class Model(torch.nn.Module):
    def __init__(self):
        super().__init__()

    def forward(self, x2):
        clone = torch.clone(x2.transpose(1, 2))
        reshape = torch.reshape(x2, (1, 32, 23, 64))
        pad = torch.nn.functional.pad(reshape, (0, -32, 0, -22, 0, -31, 0, 0), mode='constant', value=0.5)
        v7 = torch.matmul(pad, clone)
        qk = v7 / math.sqrt(v7.size(-1))
        attn_mask = torch.zeros((1, 23, 32, 64), dtype=qk.dtype, device=qk.device)
        qk = qk + attn_mask
        attn_weight = torch.softmax(qk, dim=-1)
        attn_weight = torch.dropout(attn_weight, 0.0, True)
        reshape2 = torch.reshape(x2, (1, 32, 23, 64))
        pad2 = torch.nn.functional.pad(reshape2, (0, -63, 0, 41, 0, -9, 0, 0), mode='constant', value=0.5)
        clone2 = torch.clone(attn_weight)
        return torch.matmul(clone2, pad2)

torch.manual_seed(420)
x2 = torch.randn(1, 32, 23, 64)
model = Model().eval()

eager_out = model(x2)
print('eager OK:', eager_out.shape)

compiled = torch.compile(model, backend='inductor')
compiled_out = compiled(x2)
print('compiled OK:', compiled_out.shape)
