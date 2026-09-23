"""Census: programs that are mathematically the identity.  Does the compiled output share storage with the input when eager's does not?"""
import os, sys
sys.path.insert(0, os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
try:
    from tcc.compat import ensure_msvc_env; ensure_msvc_env()
except Exception:
    pass
import torch, torch.nn.functional as F
print("torch", torch.__version__)
P = {
    "x + 0": lambda x: x + 0, "x * ones(3) in graph": lambda x: x * torch.ones(3), "x + zeros(3) in graph": lambda x: x + torch.zeros(3),
    "x - zeros_like(x)": lambda x: x - torch.zeros_like(x), "x / ones_like(x)": lambda x: x / torch.ones_like(x),
    "x * full_like(x, 1)": lambda x: x * torch.full_like(x, 1.0), "cat([x])": lambda x: torch.cat([x]), "cat([x, empty])": lambda x: torch.cat([x, x[:0]]),
    "stack([x])[0]": lambda x: torch.stack([x])[0], "x.repeat(1)": lambda x: x.repeat(1), "x.roll(0)": lambda x: x.roll(0), "x.flip([])": lambda x: x.flip([]),
    "where(True, x, y)": lambda x: torch.where(torch.ones(3, dtype=torch.bool), x, x + 1), "where(c, x, x)": lambda x: torch.where(x > 0, x, x),
    "maximum(x, x)": lambda x: torch.maximum(x, x), "x.pow(1)": lambda x: x.pow(1), "x.pow(1.0)": lambda x: x ** 1.0, "x.clamp()": lambda x: x.clamp(min=None, max=float("inf")),
    "x.float() (already f32)": lambda x: x.float() + 0.0, "x.double().float()": lambda x: x.double().float(), "x.cumsum on len-1 dim": lambda x: x.reshape(3, 1).cumsum(1).reshape(3),
    "x.sum(len-1 dim)": lambda x: x.reshape(3, 1).sum(1), "x.mean(len-1 dim)": lambda x: x.reshape(3, 1).mean(1), "dropout p=0 train": lambda x: F.dropout(x, 0.0, True),
    "x.index_select(all)": lambda x: x.index_select(0, torch.arange(3)), "x[arange]": lambda x: x[torch.arange(3)], "x.gather(identity)": lambda x: x.gather(0, torch.arange(3)),
    "x.masked_fill(none)": lambda x: x.masked_fill(torch.zeros(3, dtype=torch.bool), 9.0), "lerp(x, y, 0)": lambda x: torch.lerp(x, x + 1, 0.0),
    "addcmul value=0": lambda x: torch.addcmul(x, x, x, value=0), "x.nan_to_num()": lambda x: x.nan_to_num(), "pad 0": lambda x: F.pad(x, (0, 0)),
    "x.neg().neg()": lambda x: x.neg().neg(), "x.t().t() 2d": None, "slice_scatter full": lambda x: torch.slice_scatter(torch.zeros(3), x, 0, 0, 3),
    "x.abs() of positive": lambda x: x.abs(), "relu of positive": lambda x: torch.relu(x), "x.detach()": lambda x: x.detach() * 1,
    "int: x | 0": None, "int: x << 0": None, "int: x // 1": None, "bool: x & True": None,
}
P["x.t().t() 2d"] = lambda x: (x.reshape(3, 1).t().t() * 1).reshape(3)
ints = {"int: x | 0": lambda x: x | 0, "int: x << 0": lambda x: x << 0, "int: x // 1": lambda x: x // 1, "int: x ^ 0": lambda x: x ^ 0, "int: x & -1": lambda x: x & -1, "int: x * 1": lambda x: x * 1}
for k in list(P):
    if P[k] is None:
        del P[k]
def census(name, f, make):
    row = []
    for backend in (None, "aot_eager", "inductor"):
        torch._dynamo.reset()
        x = make()
        try:
            y = (f if backend is None else torch.compile(f, backend=backend))(x)
            row.append("same-object" if y is x else ("shares-storage" if y.untyped_storage().data_ptr() == x.untyped_storage().data_ptr() else "fresh"))
        except Exception as e:
            row.append("ERR " + type(e).__name__)
    flag = "!!" if row[2] != row[0] or row[1] != row[0] else "  "
    print(f"{flag} {name:26s} eager={row[0]:15s} aot_eager={row[1]:15s} inductor={row[2]}", flush=True)
for name, f in P.items():
    census(name, f, lambda: torch.tensor([1.0, 2.0, 3.0]))
for name, f in ints.items():
    census(name, f, lambda: torch.tensor([1, 2, 3]))
census("bool: x & True", lambda x: x & True, lambda: torch.tensor([True, False, True]))
census("bool: x | False", lambda x: x | False, lambda: torch.tensor([True, False, True]))
