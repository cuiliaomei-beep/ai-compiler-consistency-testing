# source: https://github.com/pytorch/pytorch/issues/193490
# title: Inductor batch_linear_lhs fusion leaks widened row strides to layout-sensitive users (XPU, torch 2.14)
# state: open  created: 2026-08-14
# mined automatically; the harness records the torch.compile target and its first call

import torch
import torch._inductor.config as inductor_config


@torch.library.custom_op("repro::require_contiguous", mutates_args=())
def require_contiguous(x: torch.Tensor) -> torch.Tensor:
    # Stands in for an XPU kernel that requires a contiguous input.
    if not x.is_contiguous():
        raise RuntimeError(
            f"expected contiguous input, got stride={tuple(x.stride())}, "
            f"shape={tuple(x.shape)}"
        )
    return x.clone()


@require_contiguous.register_fake
def _require_contiguous_fake(x: torch.Tensor) -> torch.Tensor:
    return torch.empty_like(x)


class M(torch.nn.Module):
    def __init__(self):
        super().__init__()
        self.proj_large = torch.nn.Linear(64, 192, bias=False)  # feeds the custom op
        self.proj_a = torch.nn.Linear(64, 16, bias=False)      # pointwise, shared input
        self.proj_b = torch.nn.Linear(64, 16, bias=False)      # pointwise, shared input

    def forward(self, x):
        large = require_contiguous(self.proj_large(x))
        a = torch.sin(self.proj_a(x))
        b = torch.cos(self.proj_b(x))
        return torch.cat((large, a, b), dim=1)


def main():
    print("torch:", torch.__version__)
    print(
        "batch_linear_lhs default config:",
        inductor_config.pre_grad_fusion_options.get("batch_linear_lhs"),
    )
    torch.manual_seed(0)
    module = M().eval()
    x = torch.randn(32, 64)

    with torch.no_grad():
        _eager = module(x)  # eager: proj_large out is contiguous, stride (192, 1)

    opts = {
        "pre_grad_fusion_options": {"batch_linear_lhs": {"min_fuse_set_size": 2}},
        "post_grad_fusion_options": {},
    }
    with torch.no_grad(), inductor_config.patch(**opts):
        try:
            torch.compile(module, fullgraph=True)(x)
            print("RESULT: PASS")
        except Exception as e:
            print("RESULT: FAIL (layout-sensitive op got a non-contiguous view)")
            print(" ", type(e).__name__, str(e))


if __name__ == "__main__":
    main()
