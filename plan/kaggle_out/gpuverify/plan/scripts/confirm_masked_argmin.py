"""masked.argmin with a broadcast mask under torch.compile(dynamic=True): Inductor C++ compile error?"""
import os
import re
import sys

HERE = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, HERE)
from tcc.compat import ensure_msvc_env  # noqa: E402

ensure_msvc_env()
import torch  # noqa: E402

print(torch.__version__)
torch.manual_seed(0)
x = torch.randn(3, 2, 1, 2)
mask4 = torch.tensor([[[[True, True]], [[False, True]]]])   # (1, 2, 1, 2) broadcasts over dim 0
mask3 = mask4[0]                                            # (2, 1, 2)
mask_full = mask4.expand_as(x).contiguous()                 # (3, 2, 1, 2) no broadcast


def run(label, fn, *args, dyn=True, backend="inductor"):
    try:
        e = fn(*args)
        es = f"{e.tolist() if e.numel() <= 8 else tuple(e.shape)}"
    except Exception as ex:  # noqa: BLE001
        es = f"{type(ex).__name__}: {str(ex)[:80]}"
    torch._dynamo.reset()
    try:
        c = torch.compile(fn, dynamic=dyn, backend=backend)(*args)
        cs = "same" if torch.equal(c, e) else f"DIFF {c.tolist()}"
    except Exception as ex:  # noqa: BLE001
        inner = ex
        while inner.__cause__ is not None:
            inner = inner.__cause__
        msg = str(inner)
        m = re.search(r"error C\d+:[^\n]*", msg)
        cs = f"{type(inner).__name__}: {m.group(0) if m else msg[:200]}"
    print(f"[{label}] dynamic={dyn} {backend}: eager={es} | compiled={cs}")


ops = {"argmin": torch.masked.argmin, "argmax": torch.masked.argmax, "amin": torch.masked.amin,
       "amax": torch.masked.amax, "sum": torch.masked.sum}
for name, op in ops.items():
    run(f"masked.{name} mask(1,2,1,2)", lambda x, m, _o=op: _o(x, mask=m), x, mask4)
run("masked.argmin mask(2,1,2)", lambda x, m: torch.masked.argmin(x, mask=m), x, mask3)
run("masked.argmin mask full (3,2,1,2)", lambda x, m: torch.masked.argmin(x, mask=m), x, mask_full)
run("masked.argmin mask(1,2,1,2) static", lambda x, m: torch.masked.argmin(x, mask=m), x, mask4, dyn=None)
run("masked.argmin mask(1,2,1,2) aot_eager", lambda x, m: torch.masked.argmin(x, mask=m), x, mask4, backend="aot_eager")
run("masked.argmin mask(1,2,1,2) dim=1", lambda x, m: torch.masked.argmin(x, dim=1, mask=m), x, mask4)
run("where(mask, x, inf).argmin() (plain)", lambda x, m: torch.where(m, x, torch.tensor(float("inf"))).argmin(), x, mask4)
run("where(mask, x, inf).argmin() 2-D (4,3) mask (1,3)", lambda x, m: torch.where(m, x, torch.tensor(float("inf"))).argmin(),
    torch.randn(4, 3), torch.tensor([[True, False, True]]))
run("masked.argmin 2-D (4,3) mask (1,3)", lambda x, m: torch.masked.argmin(x, mask=m), torch.randn(4, 3),
    torch.tensor([[True, False, True]]))
