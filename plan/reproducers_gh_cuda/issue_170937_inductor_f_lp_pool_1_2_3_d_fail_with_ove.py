# source: https://github.com/pytorch/pytorch/issues/170937
# title: [Inductor] F.lp_pool{1,2,3}d fail with OverflowError when norm_type=float('inf')
# state: closed  created: 2025-12-20
# mined automatically; the harness records the torch.compile target and its first call

import torch
import torch.nn.functional as F

def test_lp_pool_variant(dim, input_shape):
    print(f"\n{'='*10} Testing lp_pool{dim}d {'='*10}")
    op_func = getattr(F, f"lp_pool{dim}d")
    
    def fn(x):
        # The issue is triggered by norm_type=float("inf")
        return op_func(x, norm_type=float("inf"), kernel_size=3, stride=1)

    x = torch.randn(*input_shape)

    # 1. Eager Mode (Success)
    try:
        fn(x)
        print(f"[Eager] lp_pool{dim}d success.")
    except Exception as e:
        print(f"[Eager] lp_pool{dim}d failed: {e}")

    # 2. Compile Mode (Fail)
    opt_fn = torch.compile(fn, backend="inductor")
    try:
        opt_fn(x)
        print(f"[Compile] lp_pool{dim}d success.")
    except Exception as e:
        print(f"[Compile] lp_pool{dim}d failed!")
        # Only printing the key error message for brevity
        print(f"    Error: {str(e).splitlines()[0]}")

# Test 1D, 2D, and 3D
test_lp_pool_variant(1, (4, 16, 100))
test_lp_pool_variant(2, (4, 16, 32, 32))
test_lp_pool_variant(3, (4, 16, 16, 16, 16))
