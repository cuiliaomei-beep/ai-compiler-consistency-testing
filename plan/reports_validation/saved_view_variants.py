"""Variants of 'a view of a graph input is saved for backward, then the input is modified in place'."""
import os, subprocess, sys
sys.path.insert(0, os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
V = {
 "mm":            ("lambda x, p: x @ p",                                  (2, 3), (3, 3)),
 "t_mm":          ("lambda x, p: x.t() @ p",                              (3, 2), (3, 3)),
 "view_mul":      ("lambda x, p: x.view(3, 2) * p",                       (2, 3), (3, 2)),
 "slice_mul":     ("lambda x, p: x[0] * p",                               (2, 3), (3,)),
 "bmm":           ("lambda x, p: torch.bmm(x, p)",                        (2, 2, 3), (2, 3, 3)),
 "einsum":        ("lambda x, p: torch.einsum('ij,jk->ik', x, p)",        (2, 3), (3, 3)),
 "linear_3d":     ("lambda x, p: torch.nn.functional.linear(x, p)",       (2, 2, 3), (4, 3)),
 "matmul_3d":     ("lambda x, p: torch.matmul(x, p)",                     (2, 2, 3), (3, 3)),
 "addmm":         ("lambda x, p: torch.addmm(p.sum(0), x, p)",            (2, 3), (3, 3)),
 "mul_plain":     ("lambda x, p: x * p",                                  (2, 3), (2, 3)),
 "expand_mul":    ("lambda x, p: x.expand(4, 2, 3) * p",                  (2, 3), (4, 2, 3)),
 "attention_like": ("lambda x, p: torch.softmax(x @ p, -1) @ x.t()[:3].t()", (3, 3), (3, 3)),
}
if len(sys.argv) == 3:
    from tcc.compat import ensure_msvc_env; ensure_msvc_env()
    import torch
    src, sx, sp = V[sys.argv[1]]
    f = eval(src)
    x = torch.arange(1., 1 + torch.Size(sx).numel()).reshape(sx) / 7
    p = (torch.arange(1., 1 + torch.Size(sp).numel()).reshape(sp) / 5).requires_grad_()
    ref = torch.autograd.grad(f(x.clone(), p).sum(), p)[0]           # gradient of the forward that will run
    g = f if sys.argv[2] == "none" else torch.compile(f, backend=sys.argv[2])
    try:
        out = g(x, p); x.add_(1); out.sum().backward()
        print("RESULT", "SILENT, gradient", "correct" if torch.allclose(p.grad, ref) else f"WRONG (max err {(p.grad - ref).abs().max():.3g})")
    except RuntimeError as e:
        print("RESULT raises:", str(e)[:60])
else:
    import torch; print("torch", torch.__version__)
    for k in V:
        row = []
        for b in ("none", "aot_eager", "inductor"):
            pr = subprocess.run([sys.executable, __file__, k, b], capture_output=True, text=True, timeout=900, encoding="utf-8", errors="replace")
            line = [l for l in pr.stdout.splitlines() if l.startswith("RESULT")]
            row.append(f"{b}: {line[0][7:] if line else 'EXIT ' + hex(pr.returncode & 0xffffffff)}")
        print(f"{k:15s} " + " | ".join(row), flush=True)
