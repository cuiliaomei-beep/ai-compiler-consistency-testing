# source: https://github.com/pytorch/pytorch/issues/189271
# title: [inductor] KeyError in Scheduler.compute_ancestors: self-edge from realizing a reshaped in-place-mutated buffer
# state: closed  created: 2026-07-08
# mined automatically; the harness records the torch.compile target and its first call

import torch

D = 512

with torch.library._scoped_library("mylib", "FRAGMENT") as lib:
    torch.library.define(
        "mylib::attn_bwd",
        "(Tensor dout, Tensor(a!) dq, Tensor(b!) dk, Tensor(c!) dv) -> Tensor",
        tags=torch.Tag.pt2_compliant_tag,
        lib=lib,
    )

    @torch.library.impl("mylib::attn_bwd", "cpu", lib=lib)
    def attn_bwd(dout, dq, dk, dv):
        src = dout.reshape(dq.shape)
        dq.copy_(src)
        dk.copy_(src)
        dv.copy_(src)
        return torch.zeros_like(dq)  # workspace, discarded by caller

    @torch.library.register_fake("mylib::attn_bwd", lib=lib)
    def _(dout, dq, dk, dv):
        return torch.empty_like(dq)

    def f(dout, weight, num_heads):
        head_dim = D // num_heads
        seqlen = dout.shape[0]
        dq = torch.empty(1, seqlen, num_heads, head_dim, dtype=dout.dtype)
        dk = torch.empty(1, seqlen, num_heads, head_dim, dtype=dout.dtype)
        dv = torch.empty(1, seqlen, num_heads, head_dim, dtype=dout.dtype)
        torch.ops.mylib.attn_bwd(dout, dq, dk, dv)  # return discarded
        a = dq.reshape(1, seqlen, D)
        b = dk.reshape(1, seqlen, D)
        c = dv.reshape(1, seqlen, D)
        return (a + b + c) @ weight

    dout = torch.randn(128, D)
    weight = torch.randn(D, D)
    torch._dynamo.mark_dynamic(dout, 0)  # dynamic seqlen forces the realize
    f(dout, weight, 8)                                   # eager: fine
    torch.compile(f, fullgraph=True, dynamic=True)(dout, weight, 8)  # raises
