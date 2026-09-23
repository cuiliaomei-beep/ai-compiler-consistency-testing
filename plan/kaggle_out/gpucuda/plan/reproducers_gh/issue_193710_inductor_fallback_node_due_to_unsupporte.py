# source: https://github.com/pytorch/pytorch/issues/193710
# title: [inductor] `fallback_node_due_to_unsupported_type` blocks pattern matching on extern-kernel ops with `float8_e8m0fnu` inputs, with no way to opt in
# state: open  created: 2026-08-16
# mined automatically; the harness records the torch.compile target and its first call

"""Minimal repro: an extern-kernel custom op with float8_e8m0fnu inputs can
never be the anchor of an Inductor pattern.

Pure PyTorch, CPU only. Run with:  python repro_e8m0_pattern.py
"""

import torch
from torch._inductor import config
from torch._inductor.lowering import fallback_node_due_to_unsupported_type
from torch._inductor.pattern_matcher import (
    PatternMatcherPass,
    fwd_only,
    register_replacement,
)

lib = torch.library.Library("demo", "FRAGMENT")
lib.define("fp8_gemm(Tensor A, Tensor B, Tensor a_scale, Tensor b_scale) -> Tensor")
lib.define("fused_gemm(Tensor A, Tensor B, Tensor a_scale, Tensor b_scale) -> Tensor")


def _fp8_gemm(A, B, a_scale, b_scale):
    return A @ B


def _fused_gemm(A, B, a_scale, b_scale):
    return A @ B.t()


lib.impl("fp8_gemm", _fp8_gemm, "CompositeExplicitAutograd")
lib.impl("fused_gemm", _fused_gemm, "CompositeExplicitAutograd")
torch.library.register_fake(
    "demo::fp8_gemm",
    lambda A, B, a_scale, b_scale: A.new_empty((A.shape[0], B.shape[1])),
)
torch.library.register_fake(
    "demo::fused_gemm",
    lambda A, B, a_scale, b_scale: A.new_empty((A.shape[0], B.shape[0])),
)


def pattern(A, B, a_scale, b_scale):
    return torch.ops.demo.fp8_gemm(A, B.t(), a_scale, b_scale)


def replacement(A, B, a_scale, b_scale):
    return torch.ops.demo.fused_gemm(A, B, a_scale, b_scale)


def run(scale_dtype):
    patterns = PatternMatcherPass()
    example = [
        torch.empty(16, 32, dtype=torch.bfloat16),
        torch.empty(64, 32, dtype=torch.bfloat16),
        torch.empty(16, dtype=scale_dtype),
        torch.empty(64, dtype=scale_dtype),
    ]
    register_replacement(pattern, replacement, example, fwd_only, patterns)

    stats = {}

    def post_grad_pass(graph):
        for node in graph.nodes:
            if node.target is torch.ops.demo.fp8_gemm.default:
                # The pattern matcher pre-filters candidate anchors with this.
                stats["skipped"] = fallback_node_due_to_unsupported_type(
                    node, allow_cpu_inputs=False
                )
                # ... yet the pattern itself matches the node just fine.
                entry = patterns.patterns[(node.op, node.target)][0]
                stats["matches"] = bool(entry.pattern.match(node))
        stats["replaced"] = patterns.apply(graph)

    torch._dynamo.reset()
    config.post_grad_custom_post_pass = post_grad_pass
    torch.compile(pattern, fullgraph=True, dynamic=False)(*example)
    config.post_grad_custom_post_pass = None

    print(
        f"{str(scale_dtype):28} pattern.match={stats['matches']!s:5} "
        f"skipped_by_prefilter={stats['skipped']!s:5} replacements={stats['replaced']}"
    )


if __name__ == "__main__":
    run(torch.float32)
    run(torch.float8_e8m0fnu)
