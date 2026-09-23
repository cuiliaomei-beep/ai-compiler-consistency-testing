# source: https://github.com/pytorch/pytorch/issues/185481
# title: [inductor] argmax over comparison mask is accepted and used for indexing while eager raises
# state: open  created: 2026-05-28
# mined automatically; the harness records the torch.compile target and its first call

import torch
import traceback

def fn(scores, values):
    mask = scores > 0.0
    idx = torch.argmax(mask, dim=1)
    return values[idx].sum()

scores = torch.tensor(
    [[-1.0, 2.0, -3.0],
     [4.0, -5.0, 6.0]],
    dtype=torch.float32,
)

values = torch.tensor([10.0, 20.0, 30.0])

try:
    print("eager:", fn(scores, values))
except Exception as e:
    print("eager error:", type(e).__name__, str(e).splitlines()[0])

for backend in ["eager", "aot_eager", "inductor"]:
    try:
        cf = torch.compile(fn, backend=backend, fullgraph=True)
        print(backend, "compiled:", cf(scores, values))
    except Exception as e:
        print(backend, "compiled error:", type(e).__name__, str(e).splitlines()[0])
        traceback.print_exc(limit=4)
