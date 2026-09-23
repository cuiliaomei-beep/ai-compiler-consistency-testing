# source: https://github.com/pytorch/pytorch/issues/173133
# title: [Inductor] [CUDA] torch.bucketize produces inconsistent results for nan values between Eager and Inductor modes on CUDA
# state: closed  created: 2026-01-23
# mined automatically; the harness records the torch.compile target and its first call

import torch

# 在 CUDA 上运行
x = torch.tensor([-1.0], device="cuda")  # 负数会产生 nan
thresholds = torch.tensor([0.2, 0.5, 0.8], device="cuda")

# Eager 模式
result_eager = torch.bucketize(torch.rsqrt(x), thresholds, right=True)
# 输出: tensor([3], device='cuda:0')
print(result_eager)
# Inductor 模式
@torch.compile(backend="inductor")
def compiled_func(x, thr):
    return torch.bucketize(torch.rsqrt(x), thr, right=True)

result_inductor = compiled_func(x, thresholds)
print(result_inductor)
# 输出: tensor([0], device='cuda:0')
# ❌ 结果不一致！
