"""F.binary_cross_entropy on bf16/fp16 inputs with a float32 `weight`: Inductor returns float32, eager bf16/fp16.

Verified on torch 2.14.0+cpu (Windows):
    eager      -> () bfloat16      aot_eager -> () bfloat16      inductor -> () float32
Without `weight`, or with a bf16 weight, all three agree on bfloat16. binary_cross_entropy_with_logits with a
float32 weight is consistent (bf16) on 2.14 - that variant was reported as #171282 (closed 2026-03-19); the plain
binary_cross_entropy decomposition (torch/_decomp/decompositions.py: `loss = loss * weight`) still promotes.
Also: with a float32 *target* eager raises "Found dtype Float but expected BFloat16" while inductor computes a
float32 result (missing dtype check on the compile path, #144362 family).
Found by the decomposition/meta differential (plan/tcc/decomp_diff.py), variants dtype_bfloat16 / dtype_float16.
"""
import torch
import torch.nn.functional as F

torch.manual_seed(0)
p = torch.rand(4, 3).to(torch.bfloat16)
t = torch.rand(4, 3).to(torch.bfloat16)
w = torch.rand(4, 3)  # float32


def f(p, t, w):
    return F.binary_cross_entropy(p, t, weight=w)


print(torch.__version__)
print("eager    :", f(p, t, w).dtype, f(p, t, w).item())
for backend in ("aot_eager", "inductor"):
    torch._dynamo.reset()
    out = torch.compile(f, backend=backend)(p, t, w)
    print(f"{backend:<9}:", out.dtype, out.item())
