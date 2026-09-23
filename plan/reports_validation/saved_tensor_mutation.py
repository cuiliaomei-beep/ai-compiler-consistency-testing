"""A tensor saved for backward is modified in place between forward and backward.

Eager raises "one of the variables needed for gradient computation has been modified by an inplace operation".
Which compiled backends still detect it?  One process per (case, backend).
"""
import os, subprocess, sys
sys.path.insert(0, os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
CASES = ["mm_input", "mm_weight", "linear_input", "mul_other", "sigmoid_output", "mm_input_clone_ref", "mlp_input", "conv_input"]
BACKENDS = ["none", "eager", "aot_eager", "aot_eager_decomp_partition", "inductor"]

def child(case, backend):
    from tcc.compat import ensure_msvc_env; ensure_msvc_env()
    import torch
    torch.manual_seed(0)
    C = (lambda f: f) if backend == "none" else (lambda f: torch.compile(f, backend=backend))
    x = torch.arange(6.).reshape(2, 3) / 7
    w = (torch.arange(9.).reshape(3, 3) / 5).requires_grad_()
    expected = None
    if case in ("mm_input", "mm_input_clone_ref"):
        expected = x.clone().t() @ torch.ones(2, 3)          # dL/dw for the forward that actually ran
        out = C(lambda x, w: x @ w)(x, w); x.add_(1); out.sum().backward(); g = w.grad
    elif case == "mm_weight":
        out = C(lambda x, w: (x @ w).tanh())(x, w)
        with torch.no_grad(): w.add_(1)
        out.sum().backward(); g = w.grad
    elif case == "linear_input":
        expected = torch.ones(2, 3).t() @ x.clone()
        out = C(lambda x, w: torch.nn.functional.linear(x, w))(x, w); x.mul_(3); out.sum().backward(); g = w.grad
    elif case == "mul_other":
        expected = x.clone()
        v = torch.ones(2, 3, requires_grad=True)
        out = C(lambda x, v: x * v)(x, v); x.zero_(); out.sum().backward(); g = v.grad
    elif case == "sigmoid_output":
        v = torch.ones(3, requires_grad=True)
        out = C(lambda v: v.sigmoid())(v)
        with torch.no_grad(): out.mul_(0)
        out.sum().backward(); g = v.grad
    elif case == "mlp_input":
        m = torch.nn.Sequential(torch.nn.Linear(3, 4), torch.nn.ReLU(), torch.nn.Linear(4, 1))
        ref = [p.clone() for p in m.parameters()]
        out = C(m)(x); x.add_(100); out.sum().backward(); g = m[0].weight.grad
    elif case == "conv_input":
        xi = torch.arange(16.).reshape(1, 1, 4, 4) / 9
        k = torch.ones(1, 1, 3, 3, requires_grad=True)
        expected = torch.nn.functional.unfold(xi.clone(), 3).sum(-1).reshape(1, 1, 3, 3)
        out = C(lambda a, k: torch.nn.functional.conv2d(a, k))(xi, k); xi.add_(1); out.sum().backward(); g = k.grad
    msg = f"returned grad {g.flatten()[:6].tolist()}"
    if expected is not None:
        msg += f" | grad of the forward that ran: {expected.flatten()[:6].tolist()} | equal={torch.allclose(g, expected)}"
    print("RESULT", msg)

if len(sys.argv) == 3:
    try:
        child(sys.argv[1], sys.argv[2])
    except Exception as e:
        print("RESULT raised", type(e).__name__ + ":", str(e).splitlines()[0][:110])
else:
    import torch; print("torch", torch.__version__, sys.version.split()[0])
    for c in CASES:
        print("==", c)
        for b in BACKENDS:
            p = subprocess.run([sys.executable, __file__, c, b], capture_output=True, text=True, timeout=900, encoding="utf-8", errors="replace")
            line = [l for l in p.stdout.splitlines() if l.startswith("RESULT")]
            print(f"   {b:10s}", line[0][7:] if line else "EXIT " + hex(p.returncode & 0xffffffff) + p.stderr[-200:])
