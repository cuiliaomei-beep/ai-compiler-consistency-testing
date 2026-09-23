# source: https://github.com/pytorch/pytorch/issues/181735
# title: [vLLM][inductor][triton] decompose_triton_kernel_wrapper_functional AssertionError under dynamic shapes
# state: closed  created: 2026-04-28
# mined automatically; the harness records the torch.compile target and its first call

import torch
import triton
import triton.language as tl


@triton.jit
def _fill_kernel(
    buf_ptr,
    num_tokens,
    stride_t,
    stride_i,
    INNER: tl.constexpr,
):
    pid = tl.program_id(0)
    if pid >= num_tokens:
        return
    for i in range(INNER):
        tl.store(buf_ptr + pid * stride_t + i * stride_i, 1.0)


def fn(x: torch.Tensor) -> torch.Tensor:
    num_tokens = x.shape[0]
    n_groups = 1            # ← (1) size-1 leading dim
    inner = 8
    aligned_T = ((num_tokens + 3) // 4) * 4   # padded length, SymInt-derived

    # (2) as_strided view; stride[0] = inner * aligned_T is a SymInt expression.
    buf = torch.empty(
        n_groups * inner * aligned_T,
        dtype=torch.float32,
        device=x.device,
    ).as_strided(
        (n_groups, num_tokens, inner),
        (inner * aligned_T, 1, aligned_T),
    )

    # (3) triton kernel mutates `buf` -> goes into tensors_to_clone.
    _fill_kernel[(num_tokens,)](
        buf,
        num_tokens,
        stride_t=buf.stride(1),
        stride_i=buf.stride(2),
        INNER=inner,
    )
    return buf + x.sum()


def main() -> None:
    torch.set_default_device("cuda")
    compiled = torch.compile(fn, dynamic=True, fullgraph=True)
    for n in (64, 128, 256):
        x = torch.randn(n, 8)
        out = compiled(x)
        torch.cuda.synchronize()
        print(f"n={n} ok, sum={out.sum().item():.2f}")


if __name__ == "__main__":
    main()
