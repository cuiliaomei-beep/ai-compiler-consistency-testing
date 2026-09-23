"""torch.compile(dynamic=True) on CPU: argmin/argmax over a broadcast sum emits `ks1**2` into C++ -> compile error.

Verified on torch 2.14.0+cpu (Windows, MSVC). Generated kernel (line 28 of the .cpp):
    tmp_acc0_vec = argmin_combine_vec<float, 1, 2, true>(tmp_acc0_vec, tmp4, ks1**2*x0 + x1);
Python's `**` is not C++ (MSVC: error C2100 illegal indirection; GCC would reject it too), so every compiler fails.
Trigger: dynamic shapes where two dims of equal size are unified into one symbol (duck sizing, ks1*ks1 -> ks1**2),
a broadcast operand that splits the full reduction into an outer/inner loop, and an arg-reduction (argmin/argmax)
whose *index expression* is printed with the Python printer instead of the C++ one. amin/amax (no index),
static shapes, aot_eager, dim-wise argmin, and distinct inner sizes (3,2,3)+(1,2,3) are all fine.
Found by the metamorphic config differential (plan/tcc/metamorphic.py, relation `config`, variant `dynamic`) on
OpInfo masked.argmin; reduced to plain torch ops here.
"""
import torch

torch.manual_seed(0)
x = torch.randn(3, 4, 4)
m = torch.randn(1, 4, 4)     # broadcast over dim 0; inner dims equal -> one symbol under dynamic shapes


def f(x, m):
    return (x + m).argmin()


print(torch.__version__)
print("eager          :", f(x, m).item())
for label, kw in (("static", {}), ("dynamic=True", {"dynamic": True}),
                  ("dynamic aot_eager", {"dynamic": True, "backend": "aot_eager"})):
    torch._dynamo.reset()
    try:
        print(f"{label:<17}:", torch.compile(f, **kw)(x, m).item())
    except Exception as e:  # noqa: BLE001
        inner = e
        while inner.__cause__ is not None:
            inner = inner.__cause__
        print(f"{label:<17}: {type(inner).__name__}: {str(inner)[:80].encode('ascii', 'replace').decode()}")
print("distinct inner :", torch.compile(f, dynamic=True)(torch.randn(3, 2, 3), torch.randn(1, 2, 3)).item(), "(ok)")
