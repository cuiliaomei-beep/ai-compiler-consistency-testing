"""Re-run the reproducer of pytorch #174386 (closed as completed 2026-05-10) and close variants."""
import os, sys
sys.path.insert(0, os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
try:
    from tcc.compat import ensure_msvc_env; ensure_msvc_env()
except Exception:
    pass
import torch
print("torch", torch.__version__)
torch._inductor.config.fallback_random = True
torch.use_deterministic_algorithms(True)
cases = {
    "#174386 verbatim: empty_like(torch.randn(4, 4)) created inside": lambda x: torch.empty_like(torch.randn(4, 4)),
    "empty_like(x), x is a graph input": lambda x: torch.empty_like(x),
    "x.new_empty(4)": lambda x: x.new_empty(4),
    "torch.empty(5)": lambda x: torch.empty(5),
    "torch.empty(3, dtype=int32) (eager fills INT_MAX)": lambda x: torch.empty(3, dtype=torch.int32),
    "empty_like(x) + 0 (consumed in the graph)": lambda x: torch.empty_like(x) + 0,
}
for name, f in cases.items():
    torch._dynamo.reset()
    x = torch.ones(4, 4)
    e, c = f(x), torch.compile(f)(x)
    filled = lambda t: bool(t.isnan().all()) if t.is_floating_point() else bool((t == torch.iinfo(t.dtype).max).all())
    print(f"{name:64s} eager filled: {filled(e)!s:5s}  compiled filled: {filled(c)}")
