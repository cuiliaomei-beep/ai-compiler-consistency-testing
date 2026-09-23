# source: https://github.com/pytorch/pytorch/issues/180807
# title: [inductor][static launcher] Missing runtime dtype validation for pointer-typed Triton args can silently produce incorrect results
# state: closed  created: 2026-04-20
# mined automatically; the harness records the torch.compile target and its first call

import os
os.environ.setdefault("TORCHINDUCTOR_STRICT_STATIC_CUDA_LAUNCHER", "1")

import torch


@torch.library.custom_op("custom_ops::bad_meta_mul", mutates_args=())
def bad_meta_mul(a: torch.Tensor, b: torch.Tensor) -> torch.Tensor:
    # Runtime implementation returns float32
    return a * b


@bad_meta_mul.register_fake
def bad_meta_mul_fake(a, b):
    # Intentionally wrong fake/meta dtype
    return torch.empty_like(a, dtype=torch.bfloat16)


@torch.compile(fullgraph=True, options={"fx_graph_cache": False})
def f(a, b):
    x = torch.ops.custom_ops.bad_meta_mul(a, b)
    return x + 1


torch.manual_seed(0)
a = torch.randn(1 << 20, device="cuda", dtype=torch.float32)
b = torch.randn(1 << 20, device="cuda", dtype=torch.float32)

ref = torch.ops.custom_ops.bad_meta_mul(a, b) + 1
out = f(a, b)
torch.cuda.synchronize()

diff = (out.float() - ref.float()).abs()
print("out.dtype:", out.dtype)
print("ref.dtype:", ref.dtype)
print("allclose:", torch.allclose(out.float(), ref.float(), atol=1e-4, rtol=1e-4))
print("max_abs_err:", diff.max().item())
print("mean_abs_err:", diff.mean().item())
print("out[:8]:", out[:8].cpu())
print("ref[:8]:", ref[:8].cpu())
