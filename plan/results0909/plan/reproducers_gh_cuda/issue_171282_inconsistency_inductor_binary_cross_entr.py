# source: https://github.com/pytorch/pytorch/issues/171282
# title: [Inconsistency][Inductor] binary_cross_entropy_with_logits returns different dtypes between Eager and Inductor
# state: closed  created: 2025-12-25
# mined automatically; the harness records the torch.compile target and its first call

import torch

def model_func(self, target, weight):
    out = torch.ops.aten.binary_cross_entropy_with_logits(
        self,
        target=target,
        weight=weight,
        pos_weight=None,
        reduction=2,  # mean
    )
    return out

op_config = {
    "self": torch.randn([4, 5, 6], dtype=torch.bfloat16, device="cuda"),
    "target": torch.randn([4, 5, 6], dtype=torch.bfloat16, device="cuda"),
    "weight": torch.randn([6], dtype=torch.float32, device="cuda"),
}

compiled_eager = torch.compile(model_func, backend="eager")
out_eager = compiled_eager(**op_config)

compiled_inductor = torch.compile(model_func, backend="inductor")
out_inductor = compiled_inductor(**op_config)

torch.testing.assert_close(out_eager, out_inductor)
