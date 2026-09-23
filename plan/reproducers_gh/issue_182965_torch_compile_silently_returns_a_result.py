# source: https://github.com/pytorch/pytorch/issues/182965
# title: `torch.compile` silently returns a result for `torch.linalg.cholesky` on non-positive-definite input
# state: closed  created: 2026-05-08
# mined automatically; the harness records the torch.compile target and its first call

import torch

A = torch.tensor(
    [
        [1.0, 2.0],
        [2.0, 1.0],
    ],
    dtype=torch.float32,
)

def fn(x):
    return torch.linalg.cholesky(x)

try:
    y_eager = fn(A)
    print("eager ok:")
    print(y_eager)
except Exception as e:
    print("eager error:")
    print(type(e).__name__)
    print(e)

try:
    compiled_fn = torch.compile(fn, backend="inductor", fullgraph=True)
    y_compiled = compiled_fn(A)
    print("compiled ok:")
    print(y_compiled)
except Exception as e:
    print("compiled error:")
    print(type(e).__name__)
    print(e)
