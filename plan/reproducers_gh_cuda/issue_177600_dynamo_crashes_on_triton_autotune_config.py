# source: https://github.com/pytorch/pytorch/issues/177600
# title: Dynamo crashes on `triton.autotune` configuration including `prune_configs_by` if kernel is called twice
# state: closed  created: 2026-03-16
# mined automatically; the harness records the torch.compile target and its first call

#!/usr/bin/env python3
"""
Reproducer for PyTorch Dynamo bug with triton.autotune + prune_configs_by.

Tested with:
    - torch 2.10.0+rocm7.1
    - triton 3.6.0
    - AMD MI300X (ROCm)
    Should also reproduce on CUDA with equivalent torch/triton versions.
"""

import sys
import traceback

import torch
import triton
import triton.language as tl


# --- Version info ---

def print_versions():
    print(f"Python:  {sys.version.split()[0]}")
    print(f"PyTorch: {torch.__version__}")
    print(f"Triton:  {triton.__version__}")
    if torch.cuda.is_available():
        print(f"GPU:     {torch.cuda.get_device_name(0)}")
    else:
        print("GPU:     not available")
    print()


# --- Prune function (no-op, just passes configs through) ---

def noop_prune(configs, named_args, **kwargs):
    """A no-op prune function. The bug is triggered by the prune_configs_by
    mechanism itself, not by any particular pruning logic."""
    return configs


# --- Kernel definitions ---

# Kernel WITH prune_configs_by (triggers the bug on second call)
@triton.autotune(
    configs=[
        triton.Config({"BLOCK": 128}, num_warps=4),
        triton.Config({"BLOCK": 256}, num_warps=4),
    ],
    key=["N"],
    prune_configs_by={"early_config_prune": noop_prune},
)
@triton.jit
def add_kernel_with_prune(
    x_ptr, y_ptr, out_ptr, N,
    BLOCK: tl.constexpr,
):
    pid = tl.program_id(0)
    offsets = pid * BLOCK + tl.arange(0, BLOCK)
    mask = offsets < N
    x = tl.load(x_ptr + offsets, mask=mask)
    y = tl.load(y_ptr + offsets, mask=mask)
    tl.store(out_ptr + offsets, x + y, mask=mask)


# Kernel WITHOUT prune_configs_by (works fine, even called twice)
@triton.autotune(
    configs=[
        triton.Config({"BLOCK": 128}, num_warps=4),
        triton.Config({"BLOCK": 256}, num_warps=4),
    ],
    key=["N"],
)
@triton.jit
def add_kernel_no_prune(
    x_ptr, y_ptr, out_ptr, N,
    BLOCK: tl.constexpr,
):
    pid = tl.program_id(0)
    offsets = pid * BLOCK + tl.arange(0, BLOCK)
    mask = offsets < N
    x = tl.load(x_ptr + offsets, mask=mask)
    y = tl.load(y_ptr + offsets, mask=mask)
    tl.store(out_ptr + offsets, x + y, mask=mask)


# --- Wrapper functions ---

def call_kernel(kernel, x, y):
    """Call the given autotuned kernel."""
    out = torch.empty_like(x)
    N = x.numel()
    grid = lambda meta: (triton.cdiv(N, meta["BLOCK"]),)
    kernel[grid](x, y, out, N)
    return out


def fn_with_prune_called_once(x, y):
    """Calls the pruned kernel once. Should work."""
    return call_kernel(add_kernel_with_prune, x, y)


def fn_with_prune_called_twice(x, y):
    """Calls the pruned kernel twice. Triggers the bug."""
    a = call_kernel(add_kernel_with_prune, x, y)
    b = call_kernel(add_kernel_with_prune, a, y)
    return b


def fn_no_prune_called_twice(x, y):
    """Calls the non-pruned kernel twice. Should work."""
    a = call_kernel(add_kernel_no_prune, x, y)
    b = call_kernel(add_kernel_no_prune, a, y)
    return b


# --- Test runner ---

def run_test(name, fn, x, y, expect_fail=False):
    """Run a single test case under torch.compile."""
    compiled_fn = torch.compile(fn, fullgraph=True, backend="eager")
    print(f"  {name}: ", end="", flush=True)
    try:
        result = compiled_fn(x, y)
        # Verify correctness
        expected = fn(x, y)
        if torch.allclose(result, expected):
            if expect_fail:
                print("UNEXPECTED PASS (bug may be fixed!)")
            else:
                print("PASS")
        else:
            print(f"FAIL (wrong result, max diff={torch.max(torch.abs(result - expected)).item():.6f})")
    except AssertionError as e:
        if "already tracked for mutation" in str(e):
            if expect_fail:
                print(f"EXPECTED FAIL: {e}")
            else:
                print(f"UNEXPECTED FAIL: {e}")
        else:
            print(f"FAIL (unexpected assertion): {e}")
            traceback.print_exc()
    except Exception as e:
        print(f"FAIL (unexpected error): {type(e).__name__}: {e}")
        traceback.print_exc()


def main():
    print("=" * 72)
    print("Dynamo + triton.autotune + prune_configs_by bug reproducer")
    print("=" * 72)
    print()
    print_versions()

    if not torch.cuda.is_available():
        print("ERROR: No GPU available. This reproducer requires a GPU.")
        sys.exit(1)

    # Reset Dynamo state between tests to ensure isolation
    device = "cuda"
    N = 1024
    x = torch.randn(N, device=device)
    y = torch.randn(N, device=device)

    print("Test 1: autotune WITHOUT prune_configs_by, kernel called twice")
    print("  Expected: PASS (prune_configs_by is the trigger)")
    torch._dynamo.reset()
    run_test("no_prune_twice", fn_no_prune_called_twice, x, y, expect_fail=False)
    print()

    print("Test 2: autotune WITH prune_configs_by, kernel called ONCE")
    print("  Expected: PASS (bug only triggers on second call)")
    torch._dynamo.reset()
    run_test("prune_once", fn_with_prune_called_once, x, y, expect_fail=False)
    print()

    print("Test 3: autotune WITH prune_configs_by, kernel called TWICE")
    print("  Expected: FAIL with 'already tracked for mutation'")
    print("  This is the bug.")
    torch._dynamo.reset()
    run_test("prune_twice", fn_with_prune_called_twice, x, y, expect_fail=True)
    print()

if __name__ == "__main__":
    main()
