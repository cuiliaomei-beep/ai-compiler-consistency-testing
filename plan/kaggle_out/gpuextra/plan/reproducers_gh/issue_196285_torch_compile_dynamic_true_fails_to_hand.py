# source: https://github.com/pytorch/pytorch/issues/196285
# title: torch.compile(dynamic=True) fails to handle shape-derived symbolic indices in list.pop()
# state: open  created: 2026-09-08
# mined automatically; the harness records the torch.compile target and its first call

import torch

def fn(x):
    values = [x * 2, x * 3, x * 4]
    selected = values.pop(x.shape[0] - 2)
    return selected +values[0]

x = torch.randn(3)

print("Eager:", fn(x))

for backend in ["eager", "aot_eager", "inductor"]:
    try:
        compiled_fn = torch.compile(
            fn,
            backend=backend,
            fullgraph=True,
            dynamic=True
        )
        result = compiled_fn(x)
        print(f"{backend}: PASS", result)
    except Exception as e:
        print(f"{backend}: FAIL")
        print(type(e).__name__)
        print(e)
