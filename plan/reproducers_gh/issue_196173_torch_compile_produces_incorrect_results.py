# source: https://github.com/pytorch/pytorch/issues/196173
# title: torch.compile produces incorrect results and loses object state mutations for control flow based on mutable object identity
# state: open  created: 2026-09-06
# mined automatically; the harness records the torch.compile target and its first call

import torch


class Holder:
    def __init__(self):
        self.left = object()
        self.right = object()
        self.current = self.left


def fn(x, holder):
    is_left = holder.current is holder.left
    holder.current = holder.right if is_left else holder.left

    if is_left:
        return x.square()
    return -x


def run(callable_fn):
    holder = Holder()
    x = torch.tensor([2.0, 3.0])

    outputs = []
    for i in range(6):
        print(
            f"Before {i}: current is left = "
            f"{holder.current is holder.left}"
        )

        result = callable_fn(x, holder)

        print(
            f"After  {i}: result={result}, "
            f"current is left = {holder.current is holder.left}"
        )

        outputs.append(result)

    return outputs


print("Eager:")
eager_outputs = run(fn)

torch._dynamo.reset()

print("\nCompiled:")
compiled_fn = torch.compile(fn, backend="eager")
compiled_outputs = run(compiled_fn)

for eager, compiled in zip(eager_outputs, compiled_outputs):
    torch.testing.assert_close(compiled, eager)
