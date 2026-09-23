# source: https://github.com/pytorch/pytorch/issues/193802
# title: Block scaled 1x128 triton backend generates wrong results
# state: open  created: 2026-08-17
# mined automatically; the harness records the torch.compile target and its first call

import os

# Must precede the torch import: gates whether the blockwise template is offered.
os.environ.setdefault("ENABLE_PERSISTENT_TMA_MATMUL", "1")

import torch
from torch.nn.functional import ScalingType, scaled_mm

torch._inductor.config.max_autotune = True
torch._inductor.config.max_autotune_gemm = True

M, N, K, TILE = 512, 1024, 2048, 128
dev = "cuda"
torch.manual_seed(0)
kb, nb = K // TILE, N // TILE
ri = torch.Tensor.repeat_interleave

# Blockwise scales: 1x128 on A (per row, per 128 of K), 128x128 on B.
#
#   scale_a: (M, K/128)     stride (1, M)
#   scale_b: (K/128, N/128) stride (1, K/128)
sa = (torch.rand(kb, M, device=dev) * 2e-3 + 1e-3).t()
sb = (torch.rand(nb, kb, device=dev) * 2e-3 + 1e-3).t()
assert sa.shape == (M, kb) and sa.stride() == (1, M), (sa.shape, sa.stride())
assert sb.shape == (kb, nb) and sb.stride() == (1, kb), (sb.shape, sb.stride())
sa_full, sb_full = ri(sa, TILE, 1), ri(ri(sb, TILE, 0), TILE, 1)

a = (torch.randn(M, K, device=dev) / sa_full).clamp(-448, 448).to(torch.float8_e4m3fn)
# mat2 must be column-major: build (N, K) row-major, then transpose.
b = ((torch.randn(N, K, device=dev) / sb_full.t())
     .clamp(-448, 448).to(torch.float8_e4m3fn)).t()

ref = (a.float() * sa_full) @ (b.float() * sb_full)
print("scale_a %s stride %s | scale_b %s stride %s"
      % (tuple(sa.shape), sa.stride(), tuple(sb.shape), sb.stride()))


def f(a, b, sa, sb):
    return scaled_mm(a, b, sa, ScalingType.BlockWise1x128,
                     sb, ScalingType.BlockWise128x128, output_dtype=torch.bfloat16)


def report(tag, fn):
    try:
        out = fn(a, b, sa, sb)
        rel = ((out.float() - ref).abs().max() / ref.abs().max()).item()
        print("%-10s ran, rel_err = %-10.6g %s"
              % (tag, rel, "OK" if rel < 5e-2 else "<-- SILENTLY WRONG"))
        return out
    except Exception as e:
        print("%-10s %s: %s" % (tag, type(e).__name__, str(e).splitlines()[0][:100]))
        return None


report("eager:", f)
out = report("compiled:", torch.compile(f))

assert out is not None, "compiled path raised; nothing to assert"
torch.testing.assert_close(out.float(), ref, rtol=5e-2, atol=5e-2)
print("PASS")
