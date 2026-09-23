"""Minimal, self-contained checks for the second decomposition-sweep batch (torch 2.14 CPU).

C  linalg.vector_norm on an empty batch (0, 5) reduced over the non-empty dim
F  interpolate whose input or output spatial size is 0
A  binary_cross_entropy on bf16/fp16 inputs with a float32 weight (output dtype)
"""
import os
import sys

HERE = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, HERE)
from tcc.compat import ensure_msvc_env  # noqa: E402

ensure_msvc_env()
import torch  # noqa: E402
import torch.nn.functional as F  # noqa: E402

print(torch.__version__)


def run(label, fn, *args, backends=("aot_eager", "inductor")):
    def show(r):
        if isinstance(r, tuple):
            return "(" + ", ".join(show(x) for x in r) + ")"
        if isinstance(r, torch.Tensor):
            s = f"{tuple(r.shape)} {str(r.dtype).replace('torch.', '')}"
            if r.numel() <= 8:
                s += f" {r.tolist()}"
            elif r.is_floating_point():
                s += f" nan={int(torch.isnan(r).sum())}/{r.numel()}"
            return s
        return repr(r)
    try:
        e = fn(*args)
        es = show(e)
    except Exception as ex:
        es = f"{type(ex).__name__}: {str(ex)[:90]}"
    out = [f"eager: {es}"]
    for b in backends:
        torch._dynamo.reset()
        try:
            c = torch.compile(fn, backend=b)(*args)
            cs = show(c)
        except Exception as ex:
            inner = ex
            while getattr(inner, "__cause__", None) is not None:
                inner = inner.__cause__
            cs = f"{type(inner).__name__}: {str(inner)[:90]}"
        out.append(f"{b}: {cs}")
    print(f"[{label}]\n   " + "\n   ".join(out))


# ---- C: vector_norm on an empty batch ----
x = torch.empty(0, 5)
for ord_ in (float("inf"), float("-inf"), -1.0, -2.1, 0.5, 2.0, 0.0):
    run(f"C vector_norm ord={ord_} dim=-1 on (0,5)", lambda x, o=ord_: torch.linalg.vector_norm(x, ord=o, dim=-1), x)
run("C vector_norm ord=inf dim=-1 on (0,5) via torch.norm", lambda x: torch.norm(x, p=float("inf"), dim=-1), x)
run("C vector_norm ord=inf dim=0 on (5,0) (reducing the empty dim, eager raises)",
    lambda x: torch.linalg.vector_norm(x, ord=float("inf"), dim=0), torch.empty(5, 0))

# ---- F: interpolate with a zero-size spatial dim ----
run("F interpolate W=0 -> size 3 nearest", lambda x: F.interpolate(x, size=3, mode="nearest"), torch.empty(2, 3, 0))
run("F interpolate W=0 -> size 3 linear", lambda x: F.interpolate(x, size=3, mode="linear"), torch.empty(2, 3, 0))
run("F interpolate 2d (H,W)=(0,4) -> (3,3) bilinear", lambda x: F.interpolate(x, size=(3, 3), mode="bilinear"),
    torch.empty(1, 2, 0, 4))
run("F interpolate W=1 scale 0.6 (output 0) nearest", lambda x: F.interpolate(x, scale_factor=0.6, mode="nearest",
                                                                             recompute_scale_factor=False),
    torch.randn(2, 3, 1))
run("F interpolate W=1 scale 0.6 recompute", lambda x: F.interpolate(x, scale_factor=0.6, mode="nearest",
                                                                    recompute_scale_factor=True), torch.randn(2, 3, 1))

# ---- A: binary_cross_entropy dtype with a float32 weight ----
for dt in (torch.bfloat16, torch.float16):
    p = torch.rand(4, 3).to(dt)
    t = torch.rand(4, 3).to(dt)
    w = torch.rand(4, 3)
    run(f"A BCE {dt} inputs, float32 weight, mean", lambda p, t, w: F.binary_cross_entropy(p, t, weight=w), p, t, w)
    run(f"A BCE {dt} inputs, float32 weight, none", lambda p, t, w: F.binary_cross_entropy(p, t, weight=w,
                                                                                            reduction="none"), p, t, w)
    run(f"A BCE {dt} inputs, no weight", lambda p, t: F.binary_cross_entropy(p, t), p, t)
    run(f"A BCE {dt} inputs, {dt} weight", lambda p, t, w: F.binary_cross_entropy(p, t, weight=w), p, t, w.to(dt))
    run(f"A BCE-with-logits {dt} inputs, float32 weight", lambda p, t, w: F.binary_cross_entropy_with_logits(
        p, t, weight=w), p, t, w)
    run(f"A BCE {dt} inputs, float32 weight, target float32", lambda p, t, w: F.binary_cross_entropy(p, t, weight=w),
        p, t.float(), w)
