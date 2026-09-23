# source: https://github.com/pytorch/pytorch/issues/196198
# title: fullgraph=True does not enforce graph break for Tensor.item() when capture_scalar_outputs=False
# state: open  created: 2026-09-07
# mined automatically; the harness records the torch.compile target and its first call

import torch

compile_count = 0


def counting_backend(gm, example_inputs):
    global compile_count
    compile_count += 1
    print(f"BACKEND CALLED: graph #{compile_count}")
    print(gm.graph)
    return gm.forward


def fn(x):
    scale = x.sum().item()
    return x * scale + 1


old_capture_scalars = torch._dynamo.config.capture_scalar_outputs

try:
    torch._dynamo.config.capture_scalar_outputs = False

    x = torch.tensor([1.0, 2.0, 4.0], requires_grad=True)

    torch._dynamo.reset()
    compile_count = 0

    compiled = torch.compile(
        fn,
        backend=counting_backend,
        fullgraph=True,
    )

    result = compiled(x)

    print("SUCCESS")
    print("result:", result)
    print("compile_count:", compile_count)

finally:
    torch._dynamo.config.capture_scalar_outputs = old_capture_scalars
    torch._dynamo.reset()
