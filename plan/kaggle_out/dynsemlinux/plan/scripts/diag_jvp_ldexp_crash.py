"""torch.func.jvp over torch.ldexp inside torch.compile: does the process die? (run each case in a child process)"""
import subprocess, sys
CASES = {
    "eager jvp": "torch.func.jvp(f, (x,), (t,))",
    "compile(eager) jvp": "torch.compile(lambda x, t: torch.func.jvp(f, (x,), (t,)), backend='eager')(x, t)",
    "compile(aot_eager) jvp": "torch.compile(lambda x, t: torch.func.jvp(f, (x,), (t,)), backend='aot_eager')(x, t)",
    "compile(inductor) jvp": "torch.compile(lambda x, t: torch.func.jvp(f, (x,), (t,)))(x, t)",
    "compile(aot_eager) forward only": "torch.compile(f, backend='aot_eager')(x)",
    "compile(aot_eager) backward": "torch.compile(f, backend='aot_eager')(x.requires_grad_()).sum().backward()",
}
PRE = "import torch; torch.manual_seed(0); e = torch.randint(-3, 3, (3, 4)).float(); f = lambda a: torch.ldexp(a, e); x = torch.randn(3, 4); t = torch.randn(3, 4); "
print("torch", subprocess.run([sys.executable, "-c", "import torch; print(torch.__version__)"], capture_output=True, text=True).stdout.strip())
for name, code in CASES.items():
    r = subprocess.run([sys.executable, "-c", PRE + code + "; print('ok')"], capture_output=True, text=True, encoding="utf-8", errors="replace", timeout=600)
    tail = [l for l in (r.stdout + r.stderr).splitlines() if l.strip() and "Warning" not in l and not l.startswith("  ")]
    print(f"[{name}] exit={r.returncode} ({hex(r.returncode & 0xFFFFFFFF) if r.returncode else 'ok'}) last: {tail[-1][:120] if tail else ''}")
