"""F.interpolate on a zero-size spatial dim: eager raises, Inductor returns a tensor full of garbage (NaN).

Verified on torch 2.14.0+cpu (Windows). Eager:
    RuntimeError: Input and output sizes should be greater than 0, but got input (W: 0) and output (W: 3)
backend="aot_eager": IndexError: index is out of bounds for dimension with size 0   (the decomposition's gather)
backend="inductor" : returns shape (2, 3, 3) filled with NaN - the generated kernel reads out of bounds of a
                     0-element buffer (no bounds check is emitted for this load). Same for mode="linear" and 2-D
                     bilinear with (H, W) = (0, 4).
The opposite direction (input W=1, scale_factor=0.6 -> output size 0) also differs: eager raises, compile returns
an empty (2, 3, 0) tensor (recompute_scale_factor=False) or ZeroDivisionError (recompute_scale_factor=True).
Cause: the eager check lives in the C++ kernels (and in the meta registration upsample_common_check), but
upsample_nearest1d.vec / upsample_linear1d.vec are decomposed (CompositeImplicitAutograd py_impl in
torch/_decomp/decompositions.py) before any meta check runs, and the decomposition never validates sizes.
Found by the decomposition/meta differential (plan/tcc/decomp_diff.py), variants empty_last / size1_last.
"""
import torch
import torch.nn.functional as F

x = torch.empty(2, 3, 0)


def f(x):
    return F.interpolate(x, size=3, mode="nearest")


print(torch.__version__)
for name, fn in (("eager", f), ("aot_eager", torch.compile(f, backend="aot_eager")),
                 ("inductor", torch.compile(f, backend="inductor"))):
    torch._dynamo.reset()
    try:
        out = fn(x)
        print(f"{name:<9}: shape {tuple(out.shape)}  nan={int(torch.isnan(out).sum())}/{out.numel()}")
    except Exception as e:  # noqa: BLE001
        inner = e
        while inner.__cause__ is not None:
            inner = inner.__cause__
        print(f"{name:<9}: {type(inner).__name__}: {str(inner)[:120]}")
