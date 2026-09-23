"""aoti_compile_and_package fails for any model whose output is a torch.return_types.* named tuple.

Verified on torch 2.14.0+cpu: eager / torch.export / torch.compile all fine, packaging raises
    NotImplementedError: No registered serialization name for <class 'torch.return_types.max'> found.
    Please update your _register_pytree_node call with a `serialized_type_name` kwarg.
Returning the unpacked tuple `(v, i)` instead of the named tuple packages fine. Hit for max/min (dim=),
topk, kthvalue, cummax/cummin, aminmax, frexp, geqrf, lu_unpack, nanmedian in the OpInfo sweep
(plan/tcc/aoti_diff.py).
"""
import os
import tempfile

import torch
from torch._inductor import aoti_compile_and_package, aoti_load_package
from torch.export import export


class MaxDim(torch.nn.Module):
    def forward(self, x):
        return torch.max(x, dim=0)        # torch.return_types.max


class MaxDimUnpacked(torch.nn.Module):
    def forward(self, x):
        v, i = torch.max(x, dim=0)
        return v, i


print(torch.__version__)
x = torch.randn(4, 5)
work = tempfile.mkdtemp()
for name, m in (("return_types.max", MaxDim()), ("plain tuple", MaxDimUnpacked())):
    ep = export(m, (x,))
    print(f"{name:<17}: export ok, ep.module() ->", type(ep.module()(x)).__name__)
    try:
        p = aoti_compile_and_package(ep, package_path=os.path.join(work, name[:5] + ".pt2"))
        print(f"{'':<17}  aoti ok ->", [tuple(t.shape) for t in aoti_load_package(p)(x)])
    except Exception as e:  # noqa: BLE001
        print(f"{'':<17}  aoti {type(e).__name__}: {str(e)[:120]}")
