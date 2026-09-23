# source: https://github.com/pytorch/pytorch/issues/185515
# title: [inductor] Tensor.view(dtype) after transpose().contiguous() fails with stale non-contiguous stride
# state: closed  created: 2026-05-28
# mined automatically; the harness records the torch.compile target and its first call

import torch
import traceback

def fn():
    x = torch.tensor(
        [[1.0, -2.5, 0.0], [3.25, -0.0, 5.5]],
        dtype=torch.float32,
    ).t()
    y = x.contiguous().view(torch.uint8)
    return y, torch.count_nonzero(y, dim=1)

try:
    eager = fn()
    print("eager_ok")
    print(eager[0])
    print(eager[1])
except Exception:
    print("eager_error")
    traceback.print_exc(limit=10)

try:
    compiled = torch.compile(fn, backend="inductor")
    out = compiled()
    print("compiled_ok")
    print(out[0])
    print(out[1])
except Exception:
    print("compiled_error")
    traceback.print_exc(limit=20)
