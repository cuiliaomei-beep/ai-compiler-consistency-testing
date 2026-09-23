"""str(KeyError(...)) inside a fully traced compiled function drops KeyError's repr-quoting (CPython: str(KeyError('k')) == "'k'")."""
import torch
print("torch", torch.__version__)


def f(x):
    try:
        raise KeyError("k")
    except KeyError as e:
        return x, str(e)


def g(x):
    d = {}
    try:
        d["missing"]
    except KeyError as e:
        return x, str(e)


def h(x):
    try:
        raise KeyError("k")
    except KeyError as e:
        return x, f"key error: {e}"


x = torch.zeros(1)
for fn in (f, g, h):
    torch._dynamo.reset()
    e = fn(x)[1]; c = torch.compile(fn, backend="eager", fullgraph=True)(x)[1]
    print(f"[{fn.__name__}] eager={e!r}  compiled(fullgraph)={c!r}{'   <-- DIFF' if e != c else ''}")
