# source: https://github.com/pytorch/pytorch/issues/185330
# title: [inductor] torch.index_select on uint16 input silently succeeds while eager/aot_eager raise NotImplementedError
# state: closed  created: 2026-05-27
# mined automatically; the harness records the torch.compile target and its first call

import torch
import traceback

def f(x, idx):
    return torch.index_select(x, 0, idx)

x = torch.tensor([10, 20, 30, 40], dtype=torch.uint16)
idx = torch.tensor([0, 2, 1], dtype=torch.int64)

print("x_dtype", x.dtype)
print("idx_dtype", idx.dtype)

for name, runner in [
    ("eager", f),
    ("compile_eager", torch.compile(f, backend="eager", fullgraph=True)),
    ("compile_aot_eager", torch.compile(f, backend="aot_eager", fullgraph=True)),
    ("compile_inductor", torch.compile(f, backend="inductor", fullgraph=True)),
]:
    try:
        out = runner(x, idx)
        print(name, "result:", out)
    except Exception as e:
        print(name, "error:", type(e).__name__, str(e).splitlines()[0])
        traceback.print_exc(limit=5)
