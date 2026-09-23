# source: https://github.com/pytorch/pytorch/issues/191499
# title: [Inductor][CPU] torch.compile returns 0 for short positive uint8/int8 amin reductions on Apple Silicon
# state: open  created: 2026-07-29
# mined automatically; the harness records the torch.compile target and its first call

import torch

print("torch:", torch.__version__)
print("git:", torch.version.git_version)

for dtype in (torch.uint8, torch.int8):
    x = torch.tensor([5, 6, 7, 8], dtype=dtype)

    for dynamic in (False, True):
        torch._dynamo.reset()
        compiled_fn = torch.compile(
            lambda value: torch.amin(value),
            backend="inductor",
            fullgraph=True,
            dynamic=dynamic,
        )

        eager = torch.amin(x)
        compiled = compiled_fn(x)
        print(dtype, "dynamic=", dynamic,
              "eager=", eager.item(),
              "compiled=", compiled.item())

        torch.testing.assert_close(compiled, eager, rtol=0, atol=0)
