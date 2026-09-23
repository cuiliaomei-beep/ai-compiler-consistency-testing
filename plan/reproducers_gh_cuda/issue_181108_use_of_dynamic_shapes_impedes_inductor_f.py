# source: https://github.com/pytorch/pytorch/issues/181108
# title: Use of dynamic shapes impedes Inductor fusion for XSA projection
# state: open  created: 2026-04-22
# mined automatically; the harness records the torch.compile target and its first call

"""Compare kernel counts: static vs dynamic, unsqueeze vs expand.

Run:
    python test_xsa_mark_dynamic.py
"""

import re
import sys

import torch
import torch.nn.functional as F
from torch._inductor.utils import run_and_get_code


def xsa_unsqueeze(
    output: torch.Tensor,   # (B, T, Hq, D)
    xv: torch.Tensor,       # (B, T, Hkv, D)
) -> tuple[torch.Tensor, torch.Tensor, torch.Tensor]:
    head_dim = xv.shape[-1]
    n_kv = xv.shape[2]
    n_heads = output.shape[2]
    torch._check(output.shape[3] == head_dim)
    torch._check(n_heads % n_kv == 0)
    n_rep = n_heads // n_kv

    vn = F.normalize(xv, dim=-1, eps=1e-6).unsqueeze(3)
    y = output.view(*output.shape[:2], n_kv, n_rep, head_dim)
    ps = (y * vn).sum(dim=-1, keepdim=True)
    cos_sim = ps.squeeze(-1).abs()
    proj_frac = cos_sim / y.norm(dim=-1).clamp(min=1e-6)
    result = (y - ps * vn).view_as(output)
    return result, cos_sim, proj_frac


def xsa_expand(
    output: torch.Tensor,   # (B, T, Hq, D)
    xv: torch.Tensor,       # (B, T, Hkv, D)
) -> tuple[torch.Tensor, torch.Tensor, torch.Tensor]:
    B, T, Hq, D = output.shape
    Hkv = xv.shape[2]
    torch._check(xv.shape[3] == D)
    torch._check(Hq % Hkv == 0)
    gs = Hq // Hkv

    v_exp = xv[:, :, :, None, :].expand(B, T, Hkv, gs, D).reshape(B, T, Hq, D)
    vn = F.normalize(v_exp, p=2, dim=-1, eps=1e-6)
    coeff = (output * vn).sum(dim=-1, keepdim=True)
    projected = output - coeff * vn

    cg = coeff.squeeze(-1).view(B, T, Hkv, gs)
    cos_sim = cg.abs()
    yg = output.view(B, T, Hkv, gs, D)
    proj_frac = cos_sim / yg.norm(dim=-1).clamp(min=1e-6)
    return projected, cos_sim, proj_frac


def run_variant(name, fn, B, T, HQ, HKV, N_REP, D, dynamic):
    device = "cuda"
    dtype = torch.bfloat16
    torch._dynamo.reset()

    output = torch.randn(B, T, HQ, D, device=device, dtype=dtype, requires_grad=True)
    xv = torch.randn(B, T, HKV, D, device=device, dtype=dtype, requires_grad=True)
    g_res = torch.randn(B, T, HQ, D, device=device, dtype=dtype)
    g_cos = torch.randn(B, T, HKV, N_REP, device=device, dtype=dtype)
    g_pf = torch.randn(B, T, HKV, N_REP, device=device, dtype=dtype)

    if dynamic:
        torch._dynamo.mark_dynamic(output, 2)
        torch._dynamo.mark_dynamic(output, 3)
        torch._dynamo.mark_dynamic(xv, 3)
        torch._dynamo.mark_dynamic(g_res, 2)
        torch._dynamo.mark_dynamic(g_res, 3)
        torch._dynamo.mark_dynamic(g_cos, 3)
        torch._dynamo.mark_dynamic(g_pf, 3)

    def fwd_bwd():
        results = fn(output, xv)
        torch.autograd.backward(list(results), [g_res, g_cos, g_pf])

    compiled = torch.compile(fwd_bwd)
    _, codes = run_and_get_code(compiled)

    counts = []
    for i, code in enumerate(codes):
        n = len(re.findall(r"def (triton_\w+)\(", code))
        counts.append(n)
    tag = "dynamic" if dynamic else "static "
    print(f"  {name:20s} {tag}  fwd={counts[0]} bwd={counts[1]}  total={sum(counts)}", file=sys.stderr)


def main():
    assert torch.cuda.is_available()
    B, T, HKV, N_REP, D = 1, 2048, 4, 8, 64
    HQ = HKV * N_REP

    print(f"\n{'variant':20s} {'shapes':8s}  kernels", file=sys.stderr)
    print("-" * 55, file=sys.stderr)

    for fn, name in [(xsa_unsqueeze, "unsqueeze"), (xsa_expand, "expand")]:
        for dynamic in [False, True]:
            run_variant(name, fn, B, T, HQ, HKV, N_REP, D, dynamic)

    import os
    os._exit(0)


if __name__ == "__main__":
    main()
