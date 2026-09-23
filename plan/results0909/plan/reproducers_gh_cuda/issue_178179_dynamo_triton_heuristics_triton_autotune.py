# source: https://github.com/pytorch/pytorch/issues/178179
# title: Dynamo + `triton.heuristics` + `triton.autotune` with `prune_configs_by` -> `AssertionError: Can't construct an AttrSource without a valid base source`
# state: closed  created: 2026-03-23
# mined automatically; the harness records the torch.compile target and its first call

import sys
import traceback

import torch
import triton
import triton.language as tl


def print_versions():
    print(f"Python:  {sys.version.split()[0]}")
    print(f"PyTorch: {torch.__version__}")
    print(f"Triton:  {triton.__version__}")
    if torch.cuda.is_available():
        print(f"GPU:     {torch.cuda.get_device_name(0)}")
    print()


def noop_prune(configs, named_args, **kwargs):
    return configs


# Case 1: autotune + prune (no heuristics) → WORKS
@triton.autotune(
    configs=(
        triton.Config({"BLOCK": 128}, num_warps=4),
        triton.Config({"BLOCK": 256}, num_warps=4),
    ),
    key=["N"],
    prune_configs_by={"early_config_prune": noop_prune},
)
@triton.jit
def kernel_prune_only(x_ptr, out_ptr, N, BLOCK: tl.constexpr):
    pid = tl.program_id(0)
    offs = pid * BLOCK + tl.arange(0, BLOCK)
    mask = offs < N
    tl.store(out_ptr + offs, tl.load(x_ptr + offs, mask=mask) * 2, mask=mask)


# Case 2: autotune + heuristics (no prune) → WORKS
@triton.autotune(
    configs=(
        triton.Config({"BLOCK": 128}, num_warps=4),
        triton.Config({"BLOCK": 256}, num_warps=4),
    ),
    key=["N"],
)
@triton.heuristics({"EVEN": lambda args: args["N"] % 128 == 0})
@triton.jit
def kernel_heuristics_only(x_ptr, out_ptr, N, BLOCK: tl.constexpr, EVEN: tl.constexpr):
    pid = tl.program_id(0)
    offs = pid * BLOCK + tl.arange(0, BLOCK)
    mask = offs < N
    tl.store(out_ptr + offs, tl.load(x_ptr + offs, mask=mask) * 2, mask=mask)


# Case 3: autotune + heuristics + prune → CRASHES
@triton.autotune(
    configs=(
        triton.Config({"BLOCK": 128}, num_warps=4),
        triton.Config({"BLOCK": 256}, num_warps=4),
    ),
    key=["N"],
    prune_configs_by={"early_config_prune": noop_prune},
)
@triton.heuristics({"EVEN": lambda args: args["N"] % 128 == 0})
@triton.jit
def kernel_heuristics_and_prune(x_ptr, out_ptr, N, BLOCK: tl.constexpr, EVEN: tl.constexpr):
    pid = tl.program_id(0)
    offs = pid * BLOCK + tl.arange(0, BLOCK)
    mask = offs < N
    tl.store(out_ptr + offs, tl.load(x_ptr + offs, mask=mask) * 2, mask=mask)


def run_test(name, kernel, x, expect_fail=False):
    def fn(x):
        out = torch.empty_like(x)
        kernel[(triton.cdiv(x.numel(), 128),)](x, out, x.numel())
        return out

    compiled = torch.compile(fn, fullgraph=True, backend="eager")
    torch._dynamo.reset()
    print(f"  {name}: ", end="", flush=True)
    try:
        result = compiled(x)
        if torch.allclose(result, x * 2):
            print("UNEXPECTED PASS (bug may be fixed!)" if expect_fail else "PASS")
        else:
            print("WRONG RESULT")
    except AssertionError as e:
        if "AttrSource" in str(e) or "valid base source" in str(e):
            tag = "EXPECTED FAIL" if expect_fail else "UNEXPECTED FAIL"
            print(f"{tag}: {e}")
        else:
            print(f"FAIL: AssertionError: {e}")
            traceback.print_exc()
    except Exception as e:
        print(f"FAIL: {type(e).__name__}: {e}")
        traceback.print_exc()


def main():
    print("=" * 72)
    print("Dynamo bug: @triton.heuristics + prune_configs_by")
    print("=" * 72)
    print()
    print_versions()

    if not torch.cuda.is_available():
        print("ERROR: No GPU available.")
        sys.exit(1)

    x = torch.randn(1024, device="cuda")

    print("Test 1: autotune + prune_configs_by (no heuristics)")
    run_test("prune_only", kernel_prune_only, x)
    print()
    print("Test 2: autotune + heuristics (no prune_configs_by)")
    run_test("heuristics_only", kernel_heuristics_only, x)
    print()
    print("Test 3: autotune + heuristics + prune_configs_by")
    print("  This is the bug.")
    run_test("heuristics_and_prune", kernel_heuristics_and_prune, x, expect_fail=True)
    print()


if __name__ == "__main__":
    main()
