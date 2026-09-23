"""dynamic=True Dynamo leads: f-string format spec on .item() float; namedtuple == with tensors -> RecursionError."""
import collections, sys, torch
print("torch", torch.__version__)
torch._dynamo.config.recompile_limit = 100


def run(label, fn, *args, dynamic=True, backend="eager"):
    torch._dynamo.reset()
    for name, f in (("eager", fn), (f"compile(dynamic={dynamic})", torch.compile(fn, backend=backend, dynamic=dynamic))):
        try:
            print(f"[{label}] {name:<22}: {f(*args)!r}"[:160])
        except Exception as e:
            print(f"[{label}] {name:<22}: raise {type(e).__name__}: {str(e).splitlines()[0][:110]}")


x = torch.randn(3, 4)
run("fstring .3f on item()", lambda t: f"{t.sum().item():.3f}", x)
run("fstring .3f on item() static", lambda t: f"{t.sum().item():.3f}", x, dynamic=False)
run("format() on item()", lambda t: "{:.2f}".format(t.sum().item()), x)
run("fstring :d on int item", lambda t: f"{t.shape[0]:d}", x)
run("fstring :d on int(item)", lambda t: f"{int(t.sum().item()):d}", x)
run("fstring plain on item()", lambda t: f"{t.sum().item()}", x)
run("str() of item()", lambda t: str(round(t.sum().item(), 2)), x)
run("fstring .3f on shape-derived float", lambda t: f"{t.shape[0] / 2:.3f}", x)

NT = collections.namedtuple("NT", "u v")
run("namedtuple == (tensors)", lambda t: NT(t, t + 1) == NT(t, t + 1), x)
run("namedtuple == static", lambda t: NT(t, t + 1) == NT(t, t + 1), x, dynamic=False)
run("tuple == (tensors)", lambda t: (t, t + 1) == (t, t + 1), x)
run("list == (tensors)", lambda t: [t, t + 1] == [t, t + 1], x)
run("namedtuple == scalar fields", lambda t: NT(1, 2) == NT(1, 2), x)
run("namedtuple == 1-elem tensors", lambda t: NT(t[0, 0], t[0, 1]) == NT(t[0, 0], t[0, 1]), x)
