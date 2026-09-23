"""(= our own #197108 from the 0913 batch, fix PR #197165 open; rediscovered by scripts/opinfo_edge_sweep.py on 2026-09-22 -- kept as a regression check.)
Inductor: `torch.var_mean` / `std_mean` of a 0-element input returns mean 0 instead of NaN when the output is a scalar
(every dim reduced, or the non-reduced dims have size 1).  Path: use_two_step_variance() is False when the output has
one element -> WelfordReduction.create() -> `if reduction_numel == 0: mean = const(0)` (torch/_inductor/ir.py).
`aten.var` alone and `mean` alone are right; with an output of >1 elements the two-step path is taken and it is right."""
import os, sys, tempfile
os.environ.setdefault("TORCHINDUCTOR_CACHE_DIR", tempfile.mkdtemp(prefix="tcc_vm_"))
try:
    sys.path.insert(0, os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
    from tcc.compat import ensure_msvc_env
    ensure_msvc_env()
except Exception:  # noqa: BLE001
    pass
import torch

print("torch", torch.__version__, "cuda", torch.cuda.is_available())
cases = {
    "var_mean(tensor([]))": (lambda x: torch.var_mean(x), torch.tensor([])),
    "std_mean(tensor([]), correction=0)": (lambda x: torch.std_mean(x, correction=0), torch.tensor([])),
    "var_mean(zeros(1, 0), dim=1)": (lambda x: torch.var_mean(x, dim=1), torch.zeros(1, 0)),
    "var_mean(zeros(0, 3))  (all dims)": (lambda x: torch.var_mean(x), torch.zeros(0, 3)),
    "var_mean(zeros(0, 3), dim=0)  (3 outputs)": (lambda x: torch.var_mean(x, dim=0), torch.zeros(0, 3)),
    "var_mean(zeros(2, 0), dim=1)  (2 outputs)": (lambda x: torch.var_mean(x, dim=1), torch.zeros(2, 0)),
    "x.mean() of tensor([])": (lambda x: x.mean(), torch.tensor([])),
    "var_mean float16 empty": (lambda x: torch.var_mean(x), torch.tensor([], dtype=torch.float16)),
}
for dev in ["cpu"] + (["cuda"] if torch.cuda.is_available() else []):
    for name, (f, x) in cases.items():
        x = x.to(dev)
        e = f(x)
        torch._dynamo.reset()
        c = torch.compile(f)(x)
        e = e if isinstance(e, tuple) else (e,); c = c if isinstance(c, tuple) else (c,)
        same = all(torch.equal(a.isnan(), b.isnan()) and torch.equal(a.nan_to_num(), b.nan_to_num()) for a, b in zip(e, c))
        print(f"[{dev}] {'same' if same else 'DIFF'} {name:44s} eager {[t.tolist() for t in e]}  compiled {[t.tolist() for t in c]}", flush=True)
