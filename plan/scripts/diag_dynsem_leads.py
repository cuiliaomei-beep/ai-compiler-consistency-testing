"""Direct reproducers for the first Dynamo-semantics / dtype-matrix leads (2026-09-12)."""
import os, sys, random
sys.path.insert(0, os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
from tcc.compat import ensure_msvc_env
ensure_msvc_env()
import numpy as np
import torch
print("torch", torch.__version__)


def show(label, fn, *args, backends=("eager", "inductor")):
    torch._dynamo.reset()
    try:
        e = fn(*args)
        print(f"[{label}] eager    : {e!r}"[:200])
    except Exception as ex:
        print(f"[{label}] eager    : raise {type(ex).__name__}: {str(ex)[:100]}")
    for b in backends:
        cf = torch.compile(fn, backend=b)
        try:
            for i in range(2):
                c = cf(*args)
            print(f"[{label}] {b:<9}: {c!r}"[:200])
        except Exception as ex:
            print(f"[{label}] {b:<9}: raise {type(ex).__name__}: {str(ex)[:100]}")


x = torch.randn(3, 4)

# 1. random.seed inside the compiled function
def f_seed(t):
    random.seed(0)
    return t * 0 + random.random()
show("random.seed inside", f_seed, x, backends=("eager",))

def f_seed_int(t):
    random.seed(0)
    return random.randint(0, 1000)
show("random.seed + randint", f_seed_int, x, backends=("eager",))

def f_randstate(t):
    st = random.getstate()
    a = random.random()
    random.setstate(st)
    b = random.random()
    return a == b
show("random.getstate/setstate", f_randstate, x, backends=("eager",))

# 2. numpy scalar type name
def f_np(t):
    a = np.int64(3)
    return type(a * 2).__name__, type(a + t.shape[0]).__name__, type(np.float32(0.5) * 2).__name__
show("numpy scalar type names", f_np, x, backends=("eager",))

# 3. full_like with a complex fill value into a real tensor
for dt in (torch.int32, torch.float32):
    show(f"full_like complex fill {dt}", lambda t: torch.full_like(t, 1.5 + 0.5j), x.to(dt))
    show(f"fill_ complex {dt}", lambda t: t.clone().fill_(1.5 + 0.5j), x.to(dt))
    show(f"full complex dtype {dt}", lambda t: torch.full((2,), 1.5 + 0.5j, dtype=t.dtype), x.to(dt))

# 4. masked_fill on a bool tensor with a complex value
show("masked_fill bool complex", lambda t: torch.masked_fill(t, t, 1.5 + 0.5j), x > 0)
show("masked_fill bool complex 0-d", lambda t: torch.masked_fill(t, t, torch.tensor(1.5 + 0.5j)), x > 0)
show("masked_fill int complex", lambda t: torch.masked_fill(t, t > 0, 1.5 + 0.5j), x.to(torch.int64))
