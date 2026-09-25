import torch


def make(x):
    def gen():
        yield x * 1
        yield x * 2
        return "done"
    return gen()


def consume(it):
    out = [type(it).__name__]
    try:
        while True:
            out.append(next(it).sum().item())
    except StopIteration as e:
        out.append(f"StopIteration.value={e.value!r}")
    return out


x = torch.ones(2)
print("eager   :", consume(make(x)))
print("compiled:", consume(torch.compile(make, backend="eager")(x)))


def accumulate(x):
    def acc(t):
        total = t
        while True:
            v = yield total
            if v is None:
                return
            total = total + v
    g = acc(x)
    next(g)
    torch._dynamo.graph_break()  # any graph break while the generator is suspended
    return [g.send(x).tolist(), g.send(x * 2).tolist()]


print("eager   :", accumulate(x))
try:
    print("compiled:", torch.compile(accumulate, backend="eager")(x))
except AttributeError as e:
    print("compiled:", type(e).__name__, e)
