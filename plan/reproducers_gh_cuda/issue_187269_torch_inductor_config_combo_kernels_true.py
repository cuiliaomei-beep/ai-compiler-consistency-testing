# source: https://github.com/pytorch/pytorch/issues/187269
# title: torch._inductor.config.combo_kernels = True` crashes inductor codegen with "Dynamic shape on reduction dimension is not supported"
# state: closed  created: 2026-06-14
# mined automatically; the harness records the torch.compile target and its first call

"""
Minimal repro: `torch._inductor.config.combo_kernels = True` crashes inductor
codegen with "Dynamic shape on reduction dimension is not supported" when a combo
kernel groups a *persistent* reduction whose reduction dimension is dynamic.

Run:
    python combo_kernels_dynamic_reduction_repro.py

Expected: prints "OK". Actual: raises during compilation:

    File ".../torch/_inductor/codegen/triton_combo_kernel.py", line 550,
        in codegen_static_numels_sub_kernel
      raise RuntimeError(
    torch._inductor.exc.InductorError: RuntimeError: Dynamic shape on reduction dimension is not supported

Three conditions are jointly required (drop any one and it compiles fine):
  1. combo_kernels = True. The scheduler groups >= 2 independent compatible kernels
     into one ComboKernel (no foreach op needed). Here the two `.sum()`s are grouped.
  2. A *persistent* reduction. inductor's heuristic
     (torch/_inductor/codegen/choices.py: should_use_persistent_reduction) picks
     persistent for a small contiguous (ReductionHint.INNER) reduction. For a dynamic
     numel this branch is only taken when the symbol has a static upper bound <= the
     threshold (64); the torch._check(...) calls supply it. Both reductions need a
     bound -- an unbounded one falls back to a looped (non-persistent) reduction and
     the group no longer trips the assert.
  3. The reduction numel is symbolic (dynamic=True). A persistent reduction emits
     RBLOCK == rnumel as a tl.constexpr, but ComboKernel.codegen_static_numels_sub_kernel
     requires every sub-kernel's reduction numel to be a static int and raises otherwise.

Workaround: torch._inductor.config.combo_kernels = False (the default) compiles fine.

Environment this was observed on:
  torch 2.12.0, torch.version.cuda 13.2, triton 3.7.0, NVIDIA B200 (sm_100), python 3.12
"""

import torch
import torch._inductor.config as inductor_config

inductor_config.combo_kernels = True
# Codegen happens at compile time; a stale on-disk artifact can otherwise mask the
# crash on reruns. Disable caching so the repro is deterministic.
inductor_config.force_disable_caches = True


@torch.compile(dynamic=True)
def fn(a, b):
    # Bound both reduction dims so they stay symbolic but inductor picks a
    # persistent reduction (statically_known_leq(numel, 64)).
    torch._check(a.shape[0] <= 32)
    torch._check(b.shape[0] <= 32)
    return a.sum(), b.sum()


def main():
    assert torch.cuda.is_available(), "needs a CUDA/Triton backend"
    a = torch.randn(16, device="cuda")
    b = torch.randn(16, device="cuda")
    print("OK", fn(a, b))


if __name__ == "__main__":
    main()
