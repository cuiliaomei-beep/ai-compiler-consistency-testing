# source: https://github.com/pytorch/pytorch/issues/190946
# title: cumsum appears non-deterministic under torch.compile even when use_deterministic_algorithms is enabled
# state: closed  created: 2026-07-23
# mined automatically; the harness records the torch.compile target and its first call

import torch


NUMEL = 1_000_003
REPEATS = 10


def check_repeats(name, fn, x):
    reference = fn(x)
    torch.cuda.synchronize()

    mismatches = 0
    first_mismatch = None
    max_abs_diff = 0.0
    for _ in range(REPEATS):
        result = fn(x)
        torch.cuda.synchronize()
        different = reference.view(torch.int32) != result.view(torch.int32)
        if different.any():
            mismatches += 1
            index = int(torch.where(different)[0][0])
            first_mismatch = (
                index if first_mismatch is None else min(first_mismatch, index)
            )
            max_abs_diff = max(
                max_abs_diff, float((reference - result).abs().max())
            )

    print(
        f"{name}: mismatches={mismatches}/{REPEATS}, "
        f"first_mismatch={first_mismatch}, max_abs_diff={max_abs_diff}"
    )


if not torch.cuda.is_available():
    raise RuntimeError("This reproduction requires a CUDA GPU")

print(f"torch={torch.__version__}")
print(f"cuda={torch.version.cuda}")
print(f"gpu={torch.cuda.get_device_name(0)}")

docs = torch.use_deterministic_algorithms.__doc__ or ""
print(
    "docs_list_float_cuda_cumsum_as_unsupported="
    f"{'cumsum' in docs and 'floating point or complex' in docs}"
)

torch.manual_seed(0)
torch.use_deterministic_algorithms(True, warn_only=False)
x = torch.randn(NUMEL, device="cuda", dtype=torch.float32)

check_repeats("eager", lambda value: torch.cumsum(value, dim=0), x)

compiled_cumsum = torch.compile(lambda value: torch.cumsum(value, dim=0))
check_repeats("compiled", compiled_cumsum, x)
