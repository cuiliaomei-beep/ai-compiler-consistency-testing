# source: https://github.com/pytorch/pytorch/issues/176565
# title: [Inductor] Mismatch between eager and compiled outputs when converting fp32 → bf16 → fp32
# state: closed  created: 2026-03-05
# mined automatically; the harness records the torch.compile target and its first call

import torch

class CastModule(torch.nn.Module):
    def __init__(self):
        super().__init__()

    def forward(self, x):
        bf16_t = x.to(torch.bfloat16)
        fp32_casted_t = bf16_t.to(torch.float32)
        return fp32_casted_t

def func(compile):
    torch.manual_seed(1234)
    x = torch.randn(4, 4).cuda()
    cast_module = CastModule().cuda()
    if compile:
        fp32_casted_t = torch.compile(cast_module)(x)
    else:
        fp32_casted_t = cast_module(x)
    return fp32_casted_t

def compare():
    torch._inductor.config.force_disable_caches = True
    eager_out = func(compile=False)
    compiled_out = func(compile=True)
    assert torch.equal(eager_out, compiled_out), f"Mismatch between eager and compiled outputs: {eager_out} vs {compiled_out}"

if __name__ == "__main__":
    compare()
