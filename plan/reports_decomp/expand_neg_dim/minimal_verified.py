"""Eager-side finding: Tensor.expand with -1 in a new leading dimension is rejected for 1-d+ tensors but accepted for
0-d tensors, producing a tensor with a negative shape.

Verified on torch 2.14.0+cpu:
    torch.tensor(1.5).expand(-1, 5, 5).shape  -> torch.Size([-1, 5, 5]), numel() == -25, sum() == 0., clone() raises
    torch.tensor(1.5).expand(-1).shape        -> torch.Size([-1])
    torch.tensor([1.5]).expand(-1, 5)         -> RuntimeError: The expanded size of the tensor (-1) isn't allowed in a
                                                 leading, non-existing dimension 0   (correct)
torch.compile (aot_eager / inductor) raises "Trying to create tensor with negative dimension -1", i.e. the
compiled path is right and eager is wrong. Found by the FakeTensor-vs-real differential, variant zero_dim.
"""
import torch

print(torch.__version__)
t = torch.tensor(1.5).expand(-1, 5, 5)
print("eager shape:", tuple(t.shape), "numel:", t.numel(), "sum:", t.sum().item())
try:
    t.clone()
except RuntimeError as e:
    print("clone():", e)
try:
    torch.tensor([1.5]).expand(-1, 5)
except RuntimeError as e:
    print("1-d case (correct):", str(e)[:90])
torch._dynamo.reset()
try:
    torch.compile(lambda x: x.expand(-1, 5, 5))(torch.tensor(1.5))
except Exception as e:  # noqa: BLE001
    inner = e
    while inner.__cause__ is not None:
        inner = inner.__cause__
    print("compiled (correct):", type(inner).__name__, str(inner)[:80])
