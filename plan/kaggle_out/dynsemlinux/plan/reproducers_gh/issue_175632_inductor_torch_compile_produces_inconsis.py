# source: https://github.com/pytorch/pytorch/issues/175632
# title: [inductor] torch.compile produces inconsistent output for attention-like computation when only returning the final output tensor
# state: closed  created: 2026-02-24
# mined automatically; the harness records the torch.compile target and its first call

import torch
torch.manual_seed(0)

def foo(q, k, v, a):
    qk = q @ k.transpose(-2, -1) / 1.0
    qk = qk + a
    attn = torch.softmax(qk, dim=-1)
    output = attn @ v
    return output
    # return output, attn, v  # no inconsistency if also return attn and value

compiled_foo = torch.compile(foo, backend="inductor")

q = torch.randn(1, 1, 64, 64)
k = torch.randn(1, 1, 64, 64)
v = torch.randn(1, 1, 64, 64)
a = torch.randn(64, 64)

res1 = foo(q, k, v, a)
res2 = compiled_foo(q, k, v, a)
torch.testing.assert_close(res1, res2, equal_nan=True)
