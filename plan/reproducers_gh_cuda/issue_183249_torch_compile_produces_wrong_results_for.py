# source: https://github.com/pytorch/pytorch/issues/183249
# title: `torch.compile` produces wrong results for `fractional_max_pool2d` when `_random_samples` is not provided
# state: open  created: 2026-05-11
# mined automatically; the harness records the torch.compile target and its first call

import torch
import torch._inductor
torch._inductor.config.force_disable_caches = True

x = torch.randn(1, 3, 16, 16, device='cuda')

# Eager
torch.manual_seed(42); torch.cuda.manual_seed(42)
eager_out, eager_idx = torch.nn.functional.fractional_max_pool2d(
    x, 3, output_size=(4, 4), return_indices=True)

# Compiled
torch._dynamo.reset()
torch.manual_seed(42); torch.cuda.manual_seed(42)
comp_out, comp_idx = torch.compile(
    lambda x: torch.nn.functional.fractional_max_pool2d(
        x, 3, output_size=(4, 4), return_indices=True),
    backend='inductor'
)(x)

print(f"Index mismatches: {(eager_idx != comp_idx).sum().item()}/{eager_idx.numel()}")
print(f"Value max_diff: {(eager_out - comp_out).abs().max().item():.4f}")
# Index mismatches: 6/48
# Value max_diff: 1.2810
