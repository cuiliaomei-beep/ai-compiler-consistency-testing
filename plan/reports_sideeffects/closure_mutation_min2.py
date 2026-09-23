import torch
print("torch", torch.__version__)

def make(kind):
    state = {"n": 0} if kind.startswith("dict") else []
    class Helper:
        def touch(self):
            if kind == "dict +=":
                state["n"] += 1
            elif kind == "dict setitem":
                state["k"] = 1
            elif kind == "list append":
                state.append(1)
            elif kind == "list +=":
                state.extend([1])
    def f(x):
        Helper().touch()
        return x + 1
    return f, state

for kind in ("dict +=", "dict setitem", "list append", "list +="):
    res = []
    for comp in (False, True):
        torch._dynamo.reset()
        f, state = make(kind)
        g = torch.compile(f, backend="eager", fullgraph=True) if comp else f
        g(torch.ones(1)); g(torch.ones(1))
        res.append(str(state))
    print(f"{kind:13s} eager {res[0]:12s} compiled {res[1]:12s} {'<-- side effect lost' if res[0] != res[1] else ''}")
