import torch
print("torch", torch.__version__)

def run(compile_it):
    log = []
    class CM:
        def __enter__(self):
            log.append("enter"); return self
        def __exit__(self, *a):
            log.append("exit"); return False
    def f(x):
        with CM():
            y = x + 1
        return y * 2
    g = torch.compile(f, backend="eager") if compile_it else f
    out1 = g(torch.ones(2)); out2 = g(torch.ones(2))
    return log

def run_no_cm(compile_it):
    log = []
    class Helper:
        def touch(self):
            log.append("touch"); return self
    def f(x):
        Helper().touch()
        return x + 1
    g = torch.compile(f, backend="eager") if compile_it else f
    g(torch.ones(2)); g(torch.ones(2))
    return log

def run_outer_obj(compile_it):
    log = []
    class CM:
        def __enter__(self):
            log.append("enter"); return self
        def __exit__(self, *a):
            log.append("exit"); return False
    cm = CM()
    def f(x):
        with cm:
            y = x + 1
        return y * 2
    g = torch.compile(f, backend="eager") if compile_it else f
    g(torch.ones(2)); g(torch.ones(2))
    return log

for name, r in (("class defined in enclosing function, `with CM():`", run), ("method call on nested class (no with)", run_no_cm),
                ("instance created outside, `with cm:`", run_outer_obj)):
    torch._dynamo.reset(); e = r(False)
    torch._dynamo.reset(); c = r(True)
    print(f"{name}\n   eager    {e}\n   compiled {c}   {'<-- differs' if e != c else ''}")
import torch._dynamo.utils as u
print("graph breaks / frames:", dict(u.counters["graph_break"]) if hasattr(u, "counters") else "")
