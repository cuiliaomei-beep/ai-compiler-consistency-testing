"""In-place update of a captured (lifted-constant) tensor: export succeeds silently, run_decompositions raises a
clear error, aoti_compile_and_package raises an INTERNAL ASSERT ("please report a bug").

Verified on torch 2.14.0+cpu. The pattern is F.instance_norm / F.batch_norm whose running_mean / running_var are
plain tensors captured from the enclosing scope (the OpInfo samples do exactly this), not registered buffers:
    eager                     ok   (RM / RV are updated in place)
    torch.compile             ok
    torch.export              ok   (constants lifted; the update is dropped silently)
    ep.run_decompositions()   RuntimeError: Constant lifted_tensor_0 is mutated in the forward method. Pls register it as buffer
    aoti_compile_and_package  RuntimeError: false INTERNAL ASSERT FAILED at ".../ATen/RegisterFunctionalization_2.cpp":8058,
                              please report a bug to PyTorch. mutating a non-functional tensor ...
With registered buffers every step works. Found by the export/AOTI differential (plan/tcc/aoti_diff.py).
"""
import os
import tempfile

import torch
import torch.nn.functional as F
from torch._inductor import aoti_compile_and_package
from torch.export import export

RM, RV = torch.zeros(3), torch.ones(3)


class M(torch.nn.Module):
    def forward(self, x):
        return F.instance_norm(x, RM, RV, use_input_stats=True)


print(torch.__version__)
x = torch.randn(2, 3, 4, 4)
m = M()
m(x)
print("eager: RM updated ->", [round(v, 4) for v in RM.tolist()])
ep = export(m, (x,))
print("export: ok; ep.module()(x) ok:", ep.module()(x).shape)
try:
    ep.run_decompositions()
except Exception as e:  # noqa: BLE001
    print("run_decompositions:", type(e).__name__, str(e)[:100])
try:
    aoti_compile_and_package(ep, package_path=os.path.join(tempfile.mkdtemp(), "m.pt2"))
except Exception as e:  # noqa: BLE001
    print("aoti_compile_and_package:", type(e).__name__, str(e)[:160].replace("\n", " "))
