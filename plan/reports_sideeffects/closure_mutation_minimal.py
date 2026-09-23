import torch
print("torch", torch.__version__)

def variant(kind, compile_it):
    log, cnt = [], {"n": 0}
    class Helper:
        def touch(self):
            log.append("touch"); cnt["n"] += 1
            return self
    def helper_fn():
        log.append("fn"); cnt["n"] += 1
    outer = Helper()
    def f(x):
        if kind == "method of object created inside f":
            Helper().touch()
        elif kind == "method of object created outside f":
            outer.touch()
        elif kind == "nested function":
            helper_fn()
        elif kind == "object created inside f, mutation also returned":
            h = Helper().touch()
            return x + len(log)
        return x + 1
    g = torch.compile(f, backend="eager", fullgraph=True) if compile_it else f
    out = [g(torch.ones(1)).item(), g(torch.ones(1)).item()]
    return log, cnt["n"], out

for kind in ("method of object created inside f", "method of object created outside f", "nested function",
             "object created inside f, mutation also returned"):
    torch._dynamo.reset(); e = variant(kind, False)
    torch._dynamo.reset(); c = variant(kind, True)
    print(f"{kind}\n   eager    log={e[0]} n={e[1]} out={e[2]}\n   compiled log={c[0]} n={c[1]} out={c[2]}   {'<-- differs' if e != c else ''}")
