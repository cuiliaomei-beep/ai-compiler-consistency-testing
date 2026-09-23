# source: https://github.com/pytorch/pytorch/issues/175854
# title: [Numerical Consistency] Significant drift between Eager and torch.compile triggered by INDUCTOR_SHAPE_PADDING=1 on Conv2d(1x1)
# state: closed  created: 2026-02-26
# mined automatically; the harness records the torch.compile target and its first call

import torch, os
import torch.nn as nn

torch.manual_seed(0)
layer = nn.Conv2d(32, 64, 1, bias=False).eval().cuda()
x = torch.randn(64, 32, 112, 112).cuda()

print(f"Target Op: {layer}")
print(f"Input - NaN: {torch.isnan(x).any()}, Inf: {torch.isinf(x).any()}")
print(f"Input - Min: {x.min():.4f}, Max: {x.max():.4f}, Mean: {x.mean():.4f}")

def get_out(opt):
    mode = "cuda float32 eager" if opt == "0000" else "cuda float compile"
    print(f"\nRunning Mode: {mode}")
    
    for i, key in enumerate(["EPILOGUE_FUSION", "FALLBACK_RANDOM", "SHAPE_PADDING", "DYNAMIC"]):
        os.environ[f"INDUCTOR_{key}"] = opt[i]
    
    with torch.no_grad():
        if opt == "0000": return layer(x)
        return torch.compile(layer)(x)

out_eager = get_out("0000")
out_comp  = get_out("0010")

diff = (out_eager.detach().cpu().float() - out_comp.detach().cpu().float()).abs()
rel_l2 = (torch.norm(diff) / torch.norm(out_eager.detach().cpu().float()).clamp(min=1e-8)).item()

print(f"\nMax Abs Error: {diff.max().item():.6e}")
print(f"Rel L2 Error:  {rel_l2:.6e}")
print(f"Final Status: {'FAILED (Exceeds threshold)' if rel_l2 > 1e-4 else 'PASSED'}")
