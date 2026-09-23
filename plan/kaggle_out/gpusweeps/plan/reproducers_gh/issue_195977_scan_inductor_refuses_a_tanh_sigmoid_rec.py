# source: https://github.com/pytorch/pytorch/issues/195977
# title: [scan] inductor refuses a tanh/sigmoid recurrence under autograd ("scan might be aliasing the input or the output!"): ScanAutogradOp returns the carry twice as a saved intermediate
# state: open  created: 2026-09-04
# mined automatically; the harness records the torch.compile target and its first call

import torch
from torch._higher_order_ops.scan import scan

torch.manual_seed(0)
B, T, D = 4, 16, 8
W = torch.nn.Parameter(torch.randn(D, D) * 0.1)   # requires_grad=True


def rollout(state0, xs):
    def body(s, x):
        s_new = torch.tanh(s @ W + x)
        return s_new, s_new.clone()            # documented pattern: emitted slice is a clone of the carry
    _, ys = scan(body, state0, xs)
    return ys


for backend in ("aot_eager", "inductor"):
    torch._dynamo.reset()
    try:
        ys = torch.compile(rollout, backend=backend, fullgraph=True)(torch.zeros(B, D), torch.randn(T, B, D))
        ys.sum().backward()
        print(f"{backend:<10} OK   W.grad norm = {W.grad.norm():.4f}")
        W.grad = None
    except Exception as err:  # noqa: BLE001
        last = [line for line in str(err).splitlines() if "alias" in line][0].strip()
        print(f"{backend:<10} FAIL {type(err).__name__}: {last}")

W.requires_grad_(False)
torch._dynamo.reset()
torch.compile(rollout, backend="inductor", fullgraph=True)(torch.zeros(B, D), torch.randn(T, B, D))
print("inductor   OK   with W.requires_grad=False")
