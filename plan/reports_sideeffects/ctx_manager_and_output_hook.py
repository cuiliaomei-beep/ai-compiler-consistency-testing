import contextlib
import torch

print("torch", torch.__version__)
log = []

class CM:
    def __enter__(self):
        log.append("enter"); return self
    def __exit__(self, *a):
        log.append("exit"); return False

class CMState:
    def __init__(self): self.n = 0
    def __enter__(self): self.n += 1; return self
    def __exit__(self, *a): self.n += 10; return False

@contextlib.contextmanager
def gen_cm():
    log.append("g-enter")
    try:
        yield
    finally:
        log.append("g-exit")

def f_class(x):
    with CM():
        y = x + 1
    return y * 2

def f_gen(x):
    with gen_cm():
        y = x + 1
    return y * 2

st = CMState()
def f_state(x):
    with st:
        y = x + 1
    return y * 2

def f_plain(x):
    log.append("plain"); return x + 1

x = torch.ones(2)
for name, f in (("class-based CM", f_class), ("contextlib generator CM", f_gen), ("plain append (control)", f_plain)):
    for backend in (None, "eager"):
        log.clear(); torch._dynamo.reset()
        g = f if backend is None else torch.compile(f, backend=backend)
        g(x); g(x)
        print(f"{name:26s} {'eager   ' if backend is None else 'compiled'} log = {log}")
for backend in (None, "eager"):
    st.n = 0; torch._dynamo.reset()
    g = f_state if backend is None else torch.compile(f_state, backend=backend)
    g(x); g(x)
    print(f"{'CM mutating self.n':26s} {'eager   ' if backend is None else 'compiled'} n = {st.n}")

print("--- hook on an intermediate that is also returned")
def f(x):
    h = x.exp()
    return h, (h * 2).sum()
for backend in (None, "aot_eager"):
    torch._dynamo.reset()
    xx = torch.zeros(3, requires_grad=True)
    h, loss = (f if backend is None else torch.compile(f, backend=backend))(xx)
    seen = []
    h.register_hook(lambda g: (seen.append(None if g is None else g.tolist()), None if g is None else g * 0)[1])
    loss.backward()
    print(f"{'eager   ' if backend is None else 'compiled'} hook saw {seen}  x.grad = {xx.grad.tolist()}")
