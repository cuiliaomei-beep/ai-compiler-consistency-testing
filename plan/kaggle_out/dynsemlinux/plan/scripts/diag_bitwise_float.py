"""Inductor evaluates bitwise ops on float tensors that eager rejects, returning bit-pattern garbage."""
import os, sys
sys.path.insert(0, os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
try:
    from tcc.compat import ensure_msvc_env; ensure_msvc_env()
except Exception:
    pass
import torch
print("torch", torch.__version__)
x = torch.tensor([0.5, -1.0, 2.0, 0.0])
y = torch.tensor([1.5, 1.0, 3.0, 1.0])
for name, fn, args in [("bitwise_not", torch.bitwise_not, (x,)), ("bitwise_and", torch.bitwise_and, (x, y)), ("bitwise_or", torch.bitwise_or, (x, y)),
                       ("bitwise_xor", torch.bitwise_xor, (x, y)), ("bitwise_left_shift", torch.bitwise_left_shift, (x, torch.tensor([1., 1., 1., 1.]))),
                       ("bitwise_not bf16", torch.bitwise_not, (x.bfloat16(),)), ("bitwise_not fp64", torch.bitwise_not, (x.double(),))]:
    try:
        e = fn(*args); e = (str(e.dtype), e.tolist())
    except Exception as ex:
        e = f"raise {type(ex).__name__}"
    out = []
    for b in ("aot_eager", "inductor"):
        torch._dynamo.reset()
        try:
            c = torch.compile(fn, backend=b)(*args); out.append(f"{b}=({str(c.dtype).split('.')[-1]}, {[round(v, 4) if v == v else v for v in c.tolist()]})")
        except Exception as ex:
            out.append(f"{b}=raise {type(ex).__name__}")
    print(f"[{name}] eager={e} | " + " | ".join(out))
