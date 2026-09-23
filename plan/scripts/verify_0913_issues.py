"""Independent re-check of every issue in toxic_compile/0913issues: each case is a fresh subprocess that re-implements
the issue's minimal reproducer from scratch and prints REPRODUCED / NOT_REPRODUCED with the decisive observation.

    python scripts/verify_0913_issues.py            # current interpreter's torch
    ..\\venv_nightly\\Scripts\\python.exe scripts/verify_0913_issues.py
"""
import os
import subprocess
import sys
import textwrap
import time

HERE = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
PRE = textwrap.dedent(f"""
    import sys, os, math
    sys.path.insert(0, {HERE!r})
    try:
        from tcc.compat import ensure_msvc_env; ensure_msvc_env()
    except Exception:
        pass
    import torch, torch.nn.functional as F
    import warnings; warnings.filterwarnings("ignore")
    torch.manual_seed(0)
    def verdict(ok, note):
        print(("REPRODUCED " if ok else "NOT_REPRODUCED ") + note, flush=True)
""")

CASES = {
 "01 pinv/matrix_sqrth complex grad (AOTAutograd)": """
    def loss(a): return (torch.linalg.pinv(a).abs() ** 2).sum()
    def grad(fn, a):
        a = a.detach().clone().requires_grad_(); fn(a).backward(); return a.grad
    a = torch.randn(4, 3, dtype=torch.complex64)
    truth = grad(loss, a.to(torch.complex128))
    err = lambda g: (g.to(truth.dtype) - truth).abs().max().item()
    e, d = err(grad(loss, a)), err(grad(torch.compile(loss, backend="eager"), a))
    torch._dynamo.reset(); c = err(grad(torch.compile(loss, backend="aot_eager"), a))
    a128 = torch.randn(4, 3, dtype=torch.complex128, requires_grad=True)
    torch._dynamo.reset()
    gc_e = torch.autograd.gradcheck(loss, (a128,), eps=1e-6, atol=1e-4, raise_exception=False)
    gc_c = torch.autograd.gradcheck(torch.compile(loss, backend="aot_eager"), (a128,), eps=1e-6, atol=1e-4, raise_exception=False)
    def loss2(a): return (torch.linalg.matrix_sqrth(a @ a.mH + torch.eye(4, dtype=a.dtype)).abs() ** 2).sum()
    b = torch.randn(4, 4, dtype=torch.complex64); t2 = grad(loss2, b.to(torch.complex128))
    torch._dynamo.reset(); c2 = (grad(torch.compile(loss2, backend="aot_eager"), b).to(t2.dtype) - t2).abs().max().item(); e2 = (grad(loss2, b).to(t2.dtype) - t2).abs().max().item()
    verdict(e < 1e-3 and d < 1e-3 and c > 1e-1 and gc_e and not gc_c and e2 < 1e-3 and c2 > 1e-1,
            f"pinv err eager={e:.1e} dynamo-only={d:.1e} aot_eager={c:.1e}; gradcheck eager={gc_e} compiled={gc_c}; matrix_sqrth eager={e2:.1e} aot_eager={c2:.1e}")
 """,
 "02 random.shuffle/sample frozen": """
    import random
    def sh(x):
        lst = [1, 2, 3, 4, 5]; random.shuffle(lst); return x + lst[0], lst
    def sa(x):
        s = random.sample(range(100), 2); return x + s[0], s
    out = {}
    for name, fn in (("shuffle", sh), ("sample", sa)):
        torch._dynamo.reset(); cf = torch.compile(fn, backend="eager")
        random.seed(7); e = [fn(torch.zeros(1))[1] for _ in range(3)]
        random.seed(7); c = [cf(torch.zeros(1))[1] for _ in range(3)]
        out[name] = (e, c)
    frozen = all(len({tuple(v) for v in c}) == 1 for e, c in out.values())
    eager_varies = all(len({tuple(v) for v in e}) == 3 for e, c in out.values())
    verdict(frozen and eager_varies, f"shuffle eager={out['shuffle'][0]} compiled={out['shuffle'][1]}; sample compiled={out['sample'][1]}")
 """,
 "03 jvp(ldexp) under aot_eager crashes process": """
    import subprocess
    code = "import torch; torch.manual_seed(0); e = torch.randint(-3, 3, (3, 4)).float(); f = lambda a: torch.ldexp(a, e); x = torch.randn(3, 4); t = torch.randn(3, 4); torch.compile(lambda x, t: torch.func.jvp(f, (x,), (t,)), backend='aot_eager')(x, t); print('alive')"
    r = subprocess.run([sys.executable, "-c", code], capture_output=True, text=True, timeout=600)
    code2 = code.replace("backend='aot_eager'", "backend='eager'")
    r2 = subprocess.run([sys.executable, "-c", code2], capture_output=True, text=True, timeout=600)
    e = torch.randint(-3, 3, (3, 4)).float(); x = torch.randn(3, 4); t = torch.randn(3, 4)
    ok_eager = torch.func.jvp(lambda a: torch.ldexp(a, e), (x,), (t,))[1].shape == (3, 4)
    verdict(r.returncode not in (0, 1) and r2.returncode == 0 and ok_eager, f"aot_eager child exit={r.returncode & 0xFFFFFFFF:#x}; backend=eager child exit={r2.returncode}; eager jvp ok={ok_eager}")
 """,
 "04 argmin ** in C++ (dynamic=True, CPU)": """
    x = torch.randn(3, 4, 4); m = torch.randn(1, 4, 4)
    def f(x, m): return (x + m).argmin()
    e = f(x, m); s = torch.compile(f)(x, m); torch._dynamo.reset(); a = torch.compile(f, backend="aot_eager", dynamic=True)(x, m); torch._dynamo.reset()
    try:
        torch.compile(f, dynamic=True)(x, m); res = "no error"
    except Exception as ex:
        res = type(ex).__name__ + ": " + ("CppCompileError" if "CppCompileError" in str(ex) else str(ex)[:60])
    verdict("CppCompileError" in res and torch.equal(e, s) and torch.equal(e, a), f"static ok, aot_eager dynamic ok, inductor dynamic -> {res}")
 """,
 "05 cudagraphs new_zeros device (needs CUDA)": """
    if not torch.cuda.is_available():
        print("SKIP needs CUDA; verified on Kaggle Tesla T4: torch 2.10.0+cu128 and 2.14.0+cu130 (kaggle_out/gpuverify, nightlygpu G1/G1b)"); sys.exit(0)
 """,
 "06 std/var fp32 accumulation": """
    xs = torch.randn(5) * 1e-30
    e = torch.std(xs); c = torch.compile(torch.std)(xs)
    def g(fn, v):
        v = v.clone().requires_grad_(); fn(v).backward(); return v.grad
    ge = g(torch.std, xs); torch._dynamo.reset(); gc = g(torch.compile(torch.std), xs)
    big = torch.randn(4, 100003) + 1e5
    truth = big.double().var(-1); ve = big.var(-1); torch._dynamo.reset(); vc = torch.compile(lambda t: t.var(-1))(big)
    re_, rc = ((ve.double() - truth).abs() / truth).max().item(), ((vc.double() - truth).abs() / truth).max().item()
    verdict(e.item() > 0 and c.item() == 0 and ge.abs().sum() > 0 and gc.abs().sum() == 0 and re_ < 1e-6 and rc > 1e-4,
            f"std(1e-30): eager={e.item():.2e} compiled={c.item()}; grad eager nonzero={ge.abs().sum().item() > 0} compiled zero={gc.abs().sum().item() == 0}; var(N(1e5,1)) rel err eager={re_:.1e} compiled={rc:.1e}")
 """,
 "07 jvp _make_dual INTERNAL ASSERT (quantile q tensor)": """
    x, t = torch.randn(3, 4), torch.randn(3, 4); q = torch.tensor([0.25, 0.75])
    f = lambda a: torch.quantile(a, q, dim=0)
    ok_eager = torch.func.jvp(f, (x,), (t,))[1].shape == (2, 4)
    res = {}
    for b in ("eager", "aot_eager", "inductor"):
        torch._dynamo.reset()
        try:
            torch.compile(lambda x, t: torch.func.jvp(f, (x,), (t,)), backend=b)(x, t); res[b] = "ok"
        except Exception as ex:
            res[b] = "ASSERT" if "is_inference" in str(ex) else type(ex).__name__
    verdict(ok_eager and all(v == "ASSERT" for v in res.values()), f"eager ok={ok_eager}; compiled: {res}")
 """,
 "08 ldexp output dtype": """
    cases = {"bool x fp16": (torch.ones(3, 4, dtype=torch.bool), torch.randn(3, 4).half()), "fp16 x fp32": (torch.randn(3, 4).half(), torch.randn(3, 4))}
    res = {}
    for k, (a, b) in cases.items():
        torch._dynamo.reset()
        res[k] = (torch.ldexp(a, b).dtype, torch.compile(torch.ldexp, backend="aot_eager")(a, b).dtype, torch.compile(torch.ldexp)(a, b).dtype)
    ok = res["bool x fp16"] == (torch.float16, torch.float16, torch.float32) and res["fp16 x fp32"] == (torch.float32, torch.float32, torch.float16)
    verdict(ok, str(res))
 """,
 "09 compiled_autograd interpolate isIntList": """
    x = torch.randn(1, 2, 4, 4, requires_grad=True)
    F.interpolate(x, scale_factor=2, mode="bilinear").sum().backward(); x.grad = None
    res = {}
    for mode in ("bilinear", "nearest"):
        torch._dynamo.reset()
        try:
            with torch._dynamo.compiled_autograd._enable(torch.compile(backend="eager")):
                F.interpolate(x, scale_factor=2, mode=mode).sum().backward()
            res[mode] = "ok"
        except Exception as ex:
            res[mode] = "isIntList" if "isIntList" in str(ex) else type(ex).__name__
        x.grad = None
    verdict(res == {"bilinear": "isIntList", "nearest": "ok"}, str(res))
 """,
 "10 f-string format spec under dynamic=True": """
    def f(x): return f"{x.shape[0]:d}"
    x = torch.randn(3, 4)
    e = f(x); s = torch.compile(f, backend="eager", dynamic=False)(x); torch._dynamo.reset()
    try:
        d = torch.compile(f, backend="eager", dynamic=True)(x)
    except Exception as ex:
        d = type(ex).__name__ + (":format code" if "Unknown format code" in str(ex) else "")
    verdict(e == "3" and s == "3" and d.startswith("InternalTorchDynamoError"), f"eager={e!r} static={s!r} dynamic={d}")
 """,
 "11 compile(SGD.step) foreach + complex": """
    def trial(backend, foreach):
        torch._dynamo.reset()
        p = torch.nn.Parameter(torch.complex(torch.randn(3, 2), torch.randn(3, 2))); opt = torch.optim.SGD([p], lr=0.1, foreach=foreach); p.grad = torch.ones_like(p)
        step = torch.compile(opt.step, backend=backend) if backend else opt.step
        try:
            step(); return "ok"
        except Exception as ex:
            return "OpOverload-assert" if "is not an OpOverload" in str(ex) else type(ex).__name__
    r = {"eager": trial(None, True), "aot_eager": trial("aot_eager", True), "inductor": trial("inductor", True), "inductor foreach=False": trial("inductor", False)}
    verdict(r == {"eager": "ok", "aot_eager": "ok", "inductor": "OpOverload-assert", "inductor foreach=False": "ok"}, str(r))
 """,
 "12 interpolate zero-size -> NaN": """
    x = torch.empty(2, 3, 0)
    f = lambda t: F.interpolate(t, size=3)
    try:
        f(x); e = "returned"
    except Exception as ex:
        e = type(ex).__name__
    torch._dynamo.reset()
    try:
        c = torch.compile(f)(x); c = f"shape={tuple(c.shape)} nan={int(torch.isnan(c).sum())}"
    except Exception as ex:
        c = type(ex).__name__
    verdict(e == "RuntimeError" and c.startswith("shape=(2, 3, 3) nan=18"), f"eager={e} inductor={c}")
 """,
 "13 export lifted constant: silent drop / run_decompositions error / AOTI INTERNAL ASSERT": """
    import tempfile
    rm, rv = torch.zeros(3), torch.ones(3)
    class M(torch.nn.Module):
        def forward(self, x): return F.instance_norm(x, running_mean=rm, running_var=rv, use_input_stats=True)
    x = torch.randn(2, 3, 5)
    before = rm.clone(); M()(x); eager_updates = not torch.equal(rm, before)
    rm.copy_(before)
    ep = torch.export.export(M(), (x,)); ep.module()(x); export_updates = not torch.equal(rm, before)
    try:
        ep.run_decompositions(); rd = "ok"
    except Exception as ex:
        rd = "mutated-constant error" if "mutated" in str(ex) else type(ex).__name__
    try:
        torch._inductor.aoti_compile_and_package(ep, package_path=os.path.join(tempfile.mkdtemp(), "m.pt2")); ao = "ok"
    except Exception as ex:
        ao = "INTERNAL ASSERT" if "INTERNAL ASSERT" in str(ex) else type(ex).__name__ + ": " + str(ex)[:60]
    verdict(eager_updates and not export_updates and rd == "mutated-constant error" and ao == "INTERNAL ASSERT", f"eager updates={eager_updates} export updates={export_updates} run_decompositions={rd} aoti={ao}")
 """,
 "14 vector_norm ord=inf dim=-1 empty batch": """
    x = torch.empty(0, 5)
    e = torch.linalg.vector_norm(x, ord=float("inf"), dim=-1).shape
    torch._dynamo.reset()
    try:
        torch.compile(lambda t: torch.linalg.vector_norm(t, ord=float("inf"), dim=-1), backend="aot_eager")(x); c = "ok"
    except Exception as ex:
        c = "empty-dim error" if "empty" in str(ex) else type(ex).__name__
    torch._dynamo.reset(); c1 = tuple(torch.compile(lambda t: torch.linalg.vector_norm(t, ord=float("inf"), dim=1), backend="aot_eager")(x).shape)
    verdict(e == (0,) and c == "empty-dim error" and c1 == (0,), f"eager shape={tuple(e)} compiled dim=-1 -> {c}; dim=1 -> shape {c1}")
 """,
 "15 bce weight dtype / huber mixed": """
    p = torch.rand(3, 4).half() * 0.8 + 0.1; t = torch.rand(3, 4).half(); w = torch.rand(3, 4) + 0.5
    torch._dynamo.reset()
    b = (F.binary_cross_entropy(p, t, weight=w).dtype, torch.compile(lambda a, b, c: F.binary_cross_entropy(a, b, weight=c), backend="aot_eager")(p, t, w).dtype, torch.compile(lambda a, b, c: F.binary_cross_entropy(a, b, weight=c))(p, t, w).dtype)
    torch._dynamo.reset()
    h = (F.huber_loss(p, w).dtype, torch.compile(F.huber_loss, backend="aot_eager")(p, w).dtype, torch.compile(F.huber_loss)(p, w).dtype)
    verdict(b == (torch.float16, torch.float16, torch.float32) and h == (torch.float16, torch.float16, torch.float32), f"bce={b} huber={h}")
 """,
 "16 pdist backward zero rows crashes process": """
    import subprocess
    code = "import torch; x = torch.randn(0, 4, requires_grad=True); y = torch.nn.functional.pdist(x); print('fwd', tuple(y.shape), flush=True); y.sum().backward(); print('bwd ok')"
    r = subprocess.run([sys.executable, "-c", code], capture_output=True, text=True, timeout=300)
    r1 = subprocess.run([sys.executable, "-c", code.replace("randn(0, 4", "randn(1, 4")], capture_output=True, text=True, timeout=300)
    verdict(r.returncode not in (0, 1) and "fwd (0,)" in r.stdout and r1.returncode == 0, f"0 rows: exit={r.returncode & 0xFFFFFFFF:#x} stdout={r.stdout.strip()!r}; 1 row: exit={r1.returncode}")
 """,
 "17 random.seed inside: first call differs": """
    import random
    def f(x):
        random.seed(0); return x + random.random(), random.random(), random.randint(0, 100)
    torch._dynamo.reset(); cf = torch.compile(f, backend="eager")
    e = [f(torch.zeros(1))[1:] for _ in range(3)]; c = [cf(torch.zeros(1))[1:] for _ in range(3)]
    verdict(len(set(e)) == 1 and c[0] != e[0] and c[1] == e[0] and c[2] == e[0], f"eager={e[0]} compiled calls={c}")
 """,
 "18 namedtuple == RecursionError (dynamic=True, Py3.14)": """
    import collections
    NT = collections.namedtuple("NT", "u v")
    x = torch.randn(3, 4)
    def g(t): return NT(t[0, 0], t[0, 1]) == NT(t[0, 0], t[0, 1])
    e = g(x); torch._dynamo.reset()
    try:
        d = torch.compile(g, backend="eager", dynamic=True)(x)
    except RecursionError:
        d = "RecursionError"
    except Exception as ex:
        d = type(ex).__name__
    py = sys.version_info[:2]
    verdict(e is True and d == "RecursionError", f"python={py} eager={e} dynamic=True -> {d} (expected only on Python 3.14; Linux Py3.11 agrees with eager)")
 """,
 "19 bmm max_autotune on Windows": """
    if os.name != "nt":
        print("SKIP Windows-only (verified: Linux passes, Windows fails)"); sys.exit(0)
    from torch._inductor import config as IC
    x = torch.randn(4, 8, 8)
    with IC.patch({"max_autotune": True, "max_autotune_gemm": True}):
        torch._dynamo.reset()
        try:
            torch.compile(torch.bmm)(x, x); b = "ok"
        except Exception as ex:
            b = "cpp_CppMicroGemmFP32Vec not found" if "cpp_CppMicroGemmFP32Vec" in str(ex) else type(ex).__name__
        torch._dynamo.reset()
        try:
            torch.compile(torch.mm)(x[0], x[0]); m = "ok"
        except Exception as ex:
            m = type(ex).__name__
    verdict(b.startswith("cpp_CppMicroGemm") and m == "ok", f"bmm -> {b}; mm -> {m}")
 """,
 "20 AOTI packaging of return_types": """
    import tempfile
    class M(torch.nn.Module):
        def forward(self, x): return torch.max(x, dim=1)
    x = torch.randn(3, 4)
    ep = torch.export.export(M(), (x,)); ok_export = type(ep.module()(x)).__name__ == "max"
    try:
        torch._inductor.aoti_compile_and_package(ep, package_path=os.path.join(tempfile.mkdtemp(), "m.pt2")); ao = "ok"
    except NotImplementedError as ex:
        ao = "NotImplementedError: serialization name" if "serialization name" in str(ex) else "NotImplementedError"
    except Exception as ex:
        ao = type(ex).__name__ + ": " + str(ex)[:60]
    verdict(ok_export and ao.startswith("NotImplementedError: serialization"), f"export ok={ok_export}; aoti -> {ao}")
 """,
 "21 lerp(bool, bool, 0-d weight)": """
    a = torch.randint(0, 2, (3, 4)).bool(); w = torch.tensor(0.3)
    f = lambda a, w: torch.lerp(a, a, w)
    e = f(a, w).dtype; torch._dynamo.reset(); ae = torch.compile(f, backend="aot_eager")(a, w).dtype; torch._dynamo.reset()
    try:
        torch.compile(f)(a, w); i = "ok"
    except Exception as ex:
        i = "bool-subtraction NotImplementedError" if "two bool tensors" in str(ex) else type(ex).__name__
    verdict(e == torch.float32 and ae == torch.float32 and i.startswith("bool-subtraction"), f"eager={e} aot_eager={ae} inductor={i}")
 """,
 "22 sum(half, dtype=bool) / prod(dtype=bool)": """
    x16 = torch.randn(3, 4).half(); x32 = torch.randn(3, 4)
    e1 = torch.sum(x16, dtype=torch.bool).dtype; e2 = torch.prod(x32, dtype=torch.bool).dtype
    torch._dynamo.reset()
    try:
        torch.compile(lambda a: torch.sum(a, dtype=torch.bool))(x16); s = "ok"
    except Exception as ex:
        s = "CppCompileError" if "CppCompileError" in str(ex) else type(ex).__name__
    torch._dynamo.reset()
    try:
        torch.compile(lambda a: torch.prod(a, dtype=torch.bool))(x32); p = "ok"
    except Exception as ex:
        p = "reduction_type assert" if "expected reduction_type" in str(ex) else type(ex).__name__
    verdict(e1 == torch.bool and e2 == torch.bool and s == "CppCompileError" and p == "reduction_type assert", f"eager sum={e1} prod={e2}; inductor sum -> {s}, prod -> {p}")
 """,
 "23 addmm 0-d bias + max_autotune": """
    from torch._inductor import config as IC
    b, x, y = torch.tensor(0.5), torch.randn(2, 2), torch.randn(2, 3)
    f = lambda b, x, y: torch.addmm(b, x, y)
    e = f(b, x, y).shape; torch._dynamo.reset(); d = torch.compile(f)(b, x, y).shape
    with IC.patch({"max_autotune": True, "max_autotune_gemm": True}):
        torch._dynamo.reset()
        try:
            torch.compile(f)(b, x, y); a = "ok"
        except Exception as ex:
            a = "IndexError list index" if "list index out of range" in str(ex) else type(ex).__name__
    verdict(e == (2, 3) and d == (2, 3) and a.startswith("IndexError"), f"eager ok, default compile ok, max_autotune -> {a}")
 """,
 "24 var_mean empty -> mean 0": """
    x = torch.empty(0)
    e = torch.var_mean(x); torch._dynamo.reset(); a = torch.compile(torch.var_mean, backend="aot_eager")(x); torch._dynamo.reset(); c = torch.compile(torch.var_mean)(x)
    verdict(math.isnan(e[1].item()) and math.isnan(a[1].item()) and c[1].item() == 0.0, f"mean: eager={e[1].item()} aot_eager={a[1].item()} inductor={c[1].item()}")
 """,
 "25 channel_shuffle channels_last stride": """
    x = torch.randn(2, 6, 8, 8).contiguous(memory_format=torch.channels_last)
    f = lambda t: F.channel_shuffle(t, 2)
    e = f(x).stride(); torch._dynamo.reset(); a = torch.compile(f, backend="aot_eager")(x).stride(); torch._dynamo.reset(); c = torch.compile(f)(x).stride()
    verdict(e == a and e != c and e[1] == 1 and c[-1] == 1, f"eager={e} aot_eager={a} inductor={c}")
 """,
 "26 str(KeyError) in traced code": """
    def f(x):
        try:
            raise KeyError("k")
        except KeyError as e:
            return x, str(e)
    x = torch.zeros(1); e = f(x)[1]; torch._dynamo.reset(); c = torch.compile(f, backend="eager", fullgraph=True)(x)[1]
    verdict(e == "'k'" and c == "k", f"eager={e!r} compiled={c!r}")
 """,
 "27 abs(complex, out=float64)": """
    z = torch.complex(torch.rand(3, 4) + 0.5, torch.rand(3, 4))
    f = lambda a: torch.abs(a, out=torch.empty(0, dtype=torch.float64))
    e = f(z).dtype; torch._dynamo.reset()
    try:
        torch.compile(f, backend="aot_eager")(z); c = "ok"
    except Exception as ex:
        c = "fake-tensor dtype error" if "dtype" in str(ex) else type(ex).__name__
    g = lambda a: torch.angle(a, out=torch.empty(0, dtype=torch.float64))
    torch._dynamo.reset(); ang = torch.compile(g, backend="aot_eager")(z).dtype
    verdict(e == torch.float64 and c.startswith("fake-tensor") and ang == torch.float64, f"eager abs out=float64 -> {e}; compiled -> {c}; angle out=float64 compiled -> {ang}")
 """,
}


def main():
    print("torch", subprocess.run([sys.executable, "-c", "import torch; print(torch.__version__)"], capture_output=True, text=True).stdout.strip(), "| python", sys.version.split()[0])
    summary = []
    for name, body in CASES.items():
        t0 = time.time()
        code = PRE + textwrap.dedent(body)
        try:
            r = subprocess.run([sys.executable, "-c", code], capture_output=True, text=True, encoding="utf-8", errors="replace", timeout=900)
            lines = [l for l in r.stdout.splitlines() if l.startswith(("REPRODUCED", "NOT_REPRODUCED", "SKIP"))]
            if lines:
                line = lines[-1]
            elif r.returncode != 0:
                err = [l for l in r.stderr.splitlines() if l.strip()][-1:] or ["?"]
                line = f"ERROR exit={r.returncode & 0xFFFFFFFF:#x} {err[0][:160]}"
            else:
                line = "ERROR no verdict"
        except subprocess.TimeoutExpired:
            line = "ERROR timeout"
        print(f"[{name}] {line}  ({time.time() - t0:.0f}s)", flush=True)
        summary.append((name, line.split()[0]))
    counts = {}
    for _, v in summary:
        counts[v] = counts.get(v, 0) + 1
    print("SUMMARY", counts)


if __name__ == "__main__":
    main()
