"""max_autotune: torch.addmm with a 0-d (scalar) bias crashes in lowering; default config and eager are fine.

Verified on torch 2.14.0+cpu:
    torch.compile(lambda b, x, y: torch.addmm(b, x, y))(torch.tensor(0.5), x, y) with max_autotune=True
    -> InductorError: LoweringException: IndexError: list index out of range   (kernel/mm.py tuned_addmm)
Cause: torch/_inductor/kernel/mm.py line 714 tests `inp.get_stride()[0] == 0` before `len(inp.get_size()) == 2`;
for a 0-d bias get_stride() is () and the index fails. A 1-d bias (broadcast row) and a 2-d bias work.
Open PR #185578 ("Fix addmm max-autotune SliceView bias guard", issue #185533) guards the same expression for
lazy views with maybe_get_stride(); a 0-d bias would still index into an empty tuple unless the rank check is
moved first. Found by the configuration differential (plan/tcc/metamorphic.py, config set `max_autotune`).
"""
import torch
from torch._inductor import config as IC

torch.manual_seed(0)
x, y = torch.randn(2, 2), torch.randn(2, 3)
print(torch.__version__)
for name, bias in (("0-d bias", torch.tensor(0.5)), ("1-d bias", torch.randn(3)), ("2-d bias", torch.randn(2, 3))):
    torch._dynamo.reset()
    try:
        with IC.patch({"max_autotune": True, "max_autotune_gemm": True}):
            out = torch.compile(lambda b, x, y: torch.addmm(b, x, y))(bias, x, y)
        print(f"{name}: ok, matches eager = {torch.allclose(out, torch.addmm(bias, x, y), atol=1e-5)}")
    except Exception as e:  # noqa: BLE001
        inner = e
        while inner.__cause__ is not None:
            inner = inner.__cause__
        print(f"{name}: {type(inner).__name__}: {str(inner)[:80]}")
