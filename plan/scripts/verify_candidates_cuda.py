"""Re-check every TO_SUBMIT candidate plus the GPU-only leads on the current device (meant for CUDA, torch 2.14).

    python scripts/verify_candidates_cuda.py [cuda|cpu]

Self-contained: no tcc imports. Prints one block per case with eager / compiled results so the output can be
pasted into the issue drafts as the "also on CUDA" evidence.
"""
import os
import subprocess
import sys
import tempfile
import traceback

import torch
import torch.nn.functional as F

DEV = sys.argv[1] if len(sys.argv) > 1 else ("cuda" if torch.cuda.is_available() else "cpu")
print("torch", torch.__version__, "| device", DEV, "|", torch.cuda.get_device_name(0) if DEV == "cuda" else "")


def inner(e):
    while getattr(e, "__cause__", None) is not None:
        e = e.__cause__
    msg = str(e)
    extra = ""
    if "compile error" in msg.lower():        # surface the compiler's own diagnostic line(s)
        import re
        hits = [ln.strip() for ln in msg.splitlines() if re.search(r"error[: ]", ln) and "Command" not in ln][:2]
        extra = " || " + " | ".join(h[:160] for h in hits)
    return (f"{type(e).__name__}: {msg[:140]}" + extra).replace("\n", " ")


def show(v):
    if isinstance(v, tuple):
        return "(" + ", ".join(show(a) for a in v) + ")"
    if isinstance(v, torch.Tensor):
        s = f"{tuple(v.shape)} {str(v.dtype).replace('torch.', '')} {v.device.type} stride={tuple(v.stride())}"
        if v.numel() <= 6:
            s += f" {v.detach().cpu().tolist()}"
        elif v.is_floating_point():
            s += f" nan={int(torch.isnan(v).sum())} max={v.detach().float().abs().max().item():.4g}"
        return s
    return repr(v)


def case(label, fn, *args, backends=("inductor",), dynamic=None, inductor_cfg=None):
    print(f"\n[{label}]")
    try:
        print("   eager    :", show(fn(*args)))
    except Exception as e:  # noqa: BLE001
        print("   eager    :", inner(e))
    for b in backends:
        torch._dynamo.reset()
        try:
            if inductor_cfg:
                from torch._inductor import config as IC
                with IC.patch(inductor_cfg):
                    out = torch.compile(fn, backend=b, dynamic=dynamic)(*args)
            else:
                out = torch.compile(fn, backend=b, dynamic=dynamic)(*args)
            print(f"   {b:<9}:", show(out))
        except Exception as e:  # noqa: BLE001
            print(f"   {b:<9}:", inner(e))


def child(label, code):
    """Run a snippet in a fresh interpreter (cases that may kill the process / poison the CUDA context)."""
    r = subprocess.run([sys.executable, "-c", code], capture_output=True, text=True)
    out = r.stdout.strip().replace("\n", " | ")
    tail = ""
    if r.returncode != 0:
        err = (r.stderr or "").strip().splitlines()
        tail = f"   <-- child exit {r.returncode}: {err[-1][:140] if err else ''}"
    print(f"\n[{label} (child process)]\n   {out}{tail}")


d = DEV
torch.manual_seed(0)
SYNC = "torch.cuda.synchronize()" if d == "cuda" else "pass"

# 01 argmin ** (CPU C++ printer; the CUDA/Triton printer is separate - check whether it shares the bug)
x, m = torch.randn(3, 4, 4, device=d), torch.randn(1, 4, 4, device=d)
case("01 argmin broadcast equal dims dynamic=True", lambda x, m: (x + m).argmin(), x, m, dynamic=True)

# 03 interpolate zero-size spatial dim (an OOB read may be an illegal memory access on CUDA -> child process)
child("03 interpolate (2,3,0)->3", f"""
import torch, torch.nn.functional as F
x = torch.empty(2, 3, 0, device={d!r})
f = lambda x: F.interpolate(x, size=3, mode="nearest")
try:
    print("eager:", tuple(f(x).shape))
except Exception as e:
    print("eager:", type(e).__name__, str(e)[:80])
out = torch.compile(f)(x); {SYNC}
print("inductor:", tuple(out.shape), "nan", int(torch.isnan(out).sum().item()))
""")

# 04 vector_norm empty batch
case("04 vector_norm ord=inf dim=-1 on (0,5)", lambda x: torch.linalg.vector_norm(x, ord=float("inf"), dim=-1),
     torch.empty(0, 5, device=d), backends=("aot_eager", "inductor"))
case("04 vector_norm ord=inf dim=1 on (0,5)", lambda x: torch.linalg.vector_norm(x, ord=float("inf"), dim=1),
     torch.empty(0, 5, device=d))

# 05 std tiny / large, with gradient
xs = torch.randn(5, device=d) * 1e-30
case("05 std of 1e-30 values", torch.std, xs)


def grad_std(fn, x):
    xx = x.clone().requires_grad_(True)
    (g,) = torch.autograd.grad(fn(xx), xx)
    return g


print("   grad eager   :", show(grad_std(torch.std, xs)))
torch._dynamo.reset()
try:
    print("   grad inductor:", show(grad_std(torch.compile(torch.std), xs)))
except Exception as e:  # noqa: BLE001
    print("   grad inductor:", inner(e))
case("05 std of (4,8)*1e30", torch.std, torch.randn(4, 8, device=d) * 1e30)

# 06 var_mean / std_mean on an empty tensor
case("06 var_mean empty", torch.var_mean, torch.randn(0, device=d), backends=("aot_eager", "inductor"))
case("06 std_mean empty", torch.std_mean, torch.randn(0, device=d))

# 07 pdist backward on zero rows (may kill the interpreter)
child("07 pdist (0,4) backward", f"""
import torch
x = torch.randn(0, 4, device={d!r}, requires_grad=True)
y = torch.nn.functional.pdist(x); print("forward ok", tuple(y.shape), flush=True)
y.sum().backward(); {SYNC}
print("backward ok", tuple(x.grad.shape), flush=True)
""")

# 08 BCE dtype with a float32 weight
p, t, w = torch.rand(4, 3, device=d).bfloat16(), torch.rand(4, 3, device=d).bfloat16(), torch.rand(4, 3, device=d)
case("08 BCE bf16 inputs fp32 weight", lambda p, t, w: F.binary_cross_entropy(p, t, weight=w), p, t, w,
     backends=("aot_eager", "inductor"))

# 09 channel_shuffle channels_last
xc = torch.randn(2, 6, 8, 8, device=d).contiguous(memory_format=torch.channels_last)
case("09 channel_shuffle channels_last", lambda x: F.channel_shuffle(x, 2), xc, backends=("aot_eager", "inductor"))

# 10 addmm scalar bias under max_autotune
case("10 addmm 0-d bias max_autotune", lambda b, x, y: torch.addmm(b, x, y), torch.tensor(0.5, device=d),
     torch.randn(2, 2, device=d), torch.randn(2, 3, device=d), inductor_cfg={"max_autotune": True, "max_autotune_gemm": True})

# 02 bmm under max_autotune (Windows-only failure expected; should pass on Linux)
case("02 bmm max_autotune", torch.bmm, torch.randn(4, 8, 8, device=d), torch.randn(4, 8, 8, device=d),
     inductor_cfg={"max_autotune": True, "max_autotune_gemm": True})

# GPU leads from the torch-2.10 T4 sweeps
if d == "cuda":
    case("G1 new_zeros(device='cpu') under cudagraphs", lambda x: x.new_zeros((2, 3), device="cpu"),
         torch.randn(5, device=d), inductor_cfg={"triton.cudagraphs": True})
    case("G1b new_zeros(device='cpu') default config", lambda x: x.new_zeros((2, 3), device="cpu"), torch.randn(5, device=d))
case("G2 adaptive_avg_pool2d output_size as SymInt (dynamic=True, positional param)",
     lambda x, k: F.adaptive_avg_pool2d(x, k), torch.randn(2, 8, 8, 8, device=d), 5, dynamic=True)
case("G3 combinations r=1 dynamic=True", lambda x: torch.combinations(x, r=1), torch.randn(2, device=d), dynamic=True)
case("G4 interpolate scale 2 bilinear dynamic=True", lambda x: F.interpolate(x, scale_factor=2.0, mode="bilinear"),
     torch.randn(2, 3, 4, 4, device=d), dynamic=True)
case("G5 quantile dynamic=True", lambda x, q: torch.quantile(x, q), torch.randn(3, 2, 1, 2, device=d),
     torch.tensor([0.2, 0.7], device=d), dynamic=True)

# rebind leads (same compiled artefact, value changed through a positional parameter -> automatic dynamic / SymInt)
def rebind(label, fn, x, v1, v2):
    print(f"\n[{label}]")
    torch._dynamo.reset()
    try:
        cf = torch.compile(fn)
        print("   call v1  :", show(cf(x, v1)), "| eager", show(fn(x, v1)))
        print("   call v2  :", show(cf(x, v2)), "| eager", show(fn(x, v2)))
    except Exception as e:  # noqa: BLE001
        print("   rebind   :", inner(e))


rebind("G6 nonzero_static size 5 -> 6", lambda x, n: torch.nonzero_static(x, size=n), (torch.randn(3, 3, device=d) > 0), 5, 6)
rebind("G7 grid_sampler_2d interpolation_mode 0 -> 1",
       lambda x, m: torch.grid_sampler_2d(x, torch.zeros(1, 4, 4, 2, device=d), m, 0, False),
       torch.randn(1, 2, 5, 5, device=d), 0, 1)

# 11 / 12 export + AOTI (needs a C++ toolchain; failures are reported, not fatal)
try:
    from torch.export import export
    from torch._inductor import aoti_compile_and_package

    class MaxDim(torch.nn.Module):
        def forward(self, x):
            return torch.max(x, dim=0)

    ep = export(MaxDim(), (torch.randn(4, 5, device=d),))
    try:
        aoti_compile_and_package(ep, package_path=os.path.join(tempfile.mkdtemp(), "m.pt2"))
        print("\n[11 aoti return_types] packaged OK")
    except Exception as e:  # noqa: BLE001
        print("\n[11 aoti return_types]", inner(e))
    RM, RV = torch.zeros(3, device=d), torch.ones(3, device=d)

    class IN(torch.nn.Module):
        def forward(self, x):
            return F.instance_norm(x, RM, RV, use_input_stats=True)

    ep = export(IN(), (torch.randn(2, 3, 4, 4, device=d),))
    try:
        ep.run_decompositions()
        print("[12 run_decompositions] ok")
    except Exception as e:  # noqa: BLE001
        print("[12 run_decompositions]", inner(e))
    try:
        aoti_compile_and_package(ep, package_path=os.path.join(tempfile.mkdtemp(), "n.pt2"))
        print("[12 aoti] packaged OK")
    except Exception as e:  # noqa: BLE001
        print("[12 aoti]", inner(e))
except Exception:  # noqa: BLE001
    traceback.print_exc()
print("\nVERIFY DONE")
