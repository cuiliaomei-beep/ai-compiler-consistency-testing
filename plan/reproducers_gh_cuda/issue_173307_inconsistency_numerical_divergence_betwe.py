# source: https://github.com/pytorch/pytorch/issues/173307
# title: [Inconsistency] Numerical divergence between eager and inductor for infinitely_differentiable_gelu_backward in BF16
# state: closed  created: 2026-01-25
# mined automatically; the harness records the torch.compile target and its first call

import torch

def model_func(grad, self):
    return torch.ops.aten.infinitely_differentiable_gelu_backward(
        grad, self=self
    )

# Case 1: FP32 -> consistent
op_config_fp32 = {
    "grad": torch.randn([2,3,5], device="cuda", dtype=torch.float32),
    "self": torch.randn([2,3,5], device="cuda", dtype=torch.float32),
}

# Case 2: BF16 -> inconsistent
op_config_bf16 = {
    "grad": torch.randn([2,3,5], device="cuda", dtype=torch.bfloat16),
    "self": torch.randn([2,3,5], device="cuda", dtype=torch.bfloat16),
}

compiled_eager = torch.compile(model_func, backend="eager")
compiled_inductor = torch.compile(model_func, backend="inductor")

out_eager_fp32 = compiled_eager(**op_config_fp32)
out_inductor_fp32 = compiled_inductor(**op_config_fp32)

out_eager_bf16 = compiled_eager(**op_config_bf16)
out_inductor_bf16 = compiled_inductor(**op_config_bf16)

torch.testing.assert_close(out_eager_fp32, out_inductor_fp32)  # passes
torch.testing.assert_close(out_eager_bf16, out_inductor_bf16)  # fails
