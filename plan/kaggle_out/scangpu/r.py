"""T4 follow-ups of the OpInfo edge sweep: cumprod / cumsum with 0, inf, nan under Inductor (Triton associative scan)
and torch.any on uint8 (return dtype)."""
import torch
print("torch", torch.__version__, "cuda", torch.cuda.is_available())
INF, NAN = float("inf"), float("nan")
devs = ["cpu"] + (["cuda"] if torch.cuda.is_available() else [])
vecs = {"[1, 0, inf, 2]": [1.0, 0.0, INF, 2.0], "[inf, 0, 1]": [INF, 0.0, 1.0], "[-0.0, 2, -3]": [-0.0, 2.0, -3.0], "[2, nan, 0]": [2.0, NAN, 0.0],
        "[1e20, 1e20, 0]": [1e20, 1e20, 0.0], "[0, inf]": [0.0, INF], "[-inf, -0.0, 5]": [-INF, -0.0, 5.0], "[3, 0, 0, 7] x12": [3.0, 0.0, 0.0, 7.0] * 12}
for dev in devs:
    for dt in (torch.float32, torch.float16, torch.float64):
        for name, v in vecs.items():
            for opn, op in (("cumprod", lambda x: torch.cumprod(x, 0)), ("cumsum", lambda x: torch.cumsum(x, 0))):
                x = torch.tensor(v, dtype=dt, device=dev)
                torch._dynamo.reset()
                e = op(x); c = torch.compile(op)(x)
                same = torch.equal(e.isnan(), c.isnan()) and torch.equal(e.nan_to_num().double(), c.nan_to_num().double()) and torch.equal(torch.signbit(e), torch.signbit(c))
                if not same:
                    print(f"[{dev}] {str(dt):14s} {opn:8s} {name:18s} eager {e[:6].tolist()} compiled {c[:6].tolist()}", flush=True)
    x = torch.tensor([[0, 3], [0, 0]], dtype=torch.uint8, device=dev)
    for name, f in {"torch.any(x)": lambda x: torch.any(x), "torch.all(x)": lambda x: torch.all(x), "x.any(0)": lambda x: x.any(0), "any(x) * 200 + 100": lambda x: torch.any(x) * 200 + 100}.items():
        torch._dynamo.reset(); e = f(x); c = torch.compile(f)(x)
        print(f"[{dev}] {name:22s} eager {e.tolist()} {e.dtype}   inductor {c.tolist()} {c.dtype}", flush=True)
print("DONE")
