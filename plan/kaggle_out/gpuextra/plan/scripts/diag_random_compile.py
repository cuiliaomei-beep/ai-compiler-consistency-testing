"""Which python-random calls does Dynamo replay faithfully after random.seed() inside the compiled function?"""
import os, sys, random
sys.path.insert(0, os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
import numpy as np
import torch
print("torch", torch.__version__)
torch._dynamo.config.recompile_limit = 1000

FUNCS = {
    "random": lambda: random.random(),
    "randint": lambda: random.randint(0, 1000),
    "randrange": lambda: random.randrange(1000),
    "uniform": lambda: random.uniform(0, 10),
    "gauss": lambda: random.gauss(0, 1),
    "choice": lambda: random.choice([10, 20, 30, 40]),
    "choices": lambda: random.choices([1, 2, 3], k=2),
    "sample": lambda: random.sample(range(100), 2),
    "shuffle": lambda: (lambda l: (random.shuffle(l), l)[1])([1, 2, 3, 4, 5]),
    "random_x3": lambda: (random.random(), random.random(), random.random()),
    "random_then_randint": lambda: (random.random(), random.randint(0, 100)),
}
for name, g in FUNCS.items():
    def f(t, g=g):
        random.seed(0)
        v = g()
        return t.sum() * 0 + (v[0] if isinstance(v, (tuple, list)) else v), v
    torch._dynamo.reset()
    cf = torch.compile(f, backend="eager")
    x = torch.ones(2)
    e = [f(x)[1] for _ in range(2)]
    try:
        c = [cf(x)[1] for _ in range(2)]
    except Exception as ex:
        c = f"raise {type(ex).__name__}: {str(ex)[:80]}"
    flag = "" if e == c else "   <-- DIFF"
    print(f"[seed inside] {name:<20} eager={e}  compiled={c}{flag}")

# seed OUTSIDE, function called twice: eager advances the global RNG; compiled?
for name, g in FUNCS.items():
    def f(t, g=g):
        v = g()
        return t.sum() * 0 + (v[0] if isinstance(v, (tuple, list)) else v), v
    torch._dynamo.reset()
    cf = torch.compile(f, backend="eager")
    x = torch.ones(2)
    random.seed(7); e = [f(x)[1] for _ in range(3)]
    random.seed(7)
    try:
        c = [cf(x)[1] for _ in range(3)]
    except Exception as ex:
        c = f"raise {type(ex).__name__}: {str(ex)[:80]}"
    flag = "" if e == c else "   <-- DIFF"
    print(f"[seed outside] {name:<20} eager={e}  compiled={c}{flag}")

# aot_eager: full_like with complex fill into a real tensor / masked_fill bool with complex
for b in ("eager", "aot_eager", "inductor"):
    torch._dynamo.reset()
    for label, fn, arg in [("full_like int32 complex", lambda t: torch.full_like(t, 1.5 + 0.5j), torch.ones(2, dtype=torch.int32)),
                           ("masked_fill bool complex", lambda t: torch.masked_fill(t, t, 1.5 + 0.5j), torch.tensor([True, False]))]:
        try:
            r = torch.compile(fn, backend=b)(arg); r = f"{r.dtype} {r.tolist()}"
        except Exception as ex:
            r = f"raise {type(ex).__name__}"
        try:
            e = fn(arg); e = f"{e.dtype} {e.tolist()}"
        except Exception as ex:
            e = f"raise {type(ex).__name__}"
        print(f"[{label}] eager={e}  {b}={r}")
