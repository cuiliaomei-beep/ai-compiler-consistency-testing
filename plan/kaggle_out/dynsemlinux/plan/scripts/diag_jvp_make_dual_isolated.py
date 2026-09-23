"""Forward-mode AD inside torch.compile: each (op, backend) in a FRESH subprocess, so a failed case cannot leak
functorch/Dynamo state into the next one."""
import subprocess, sys
OPS = {
    "addr": "lambda a: torch.addr(a, v1, v2)",
    "addr_beta_alpha": "lambda a: torch.addr(a, v1, v2, beta=0.5, alpha=2.0)",
    "quantile_q0.5": "lambda a: torch.quantile(a, 0.5)",
    "quantile_q0.3_dim1": "lambda a: torch.quantile(a, 0.3, dim=1)",
    "quantile_qtensor_dim0": "lambda a: torch.quantile(a, torch.tensor([0.25, 0.75]), dim=0)",
    "nanquantile_q0.5": "lambda a: torch.nanquantile(a, 0.5)",
    "median_dim": "lambda a: torch.median(a, dim=1)[0]",
}
PRE = "import torch; torch.manual_seed(0); x, t = torch.randn(3, 4), torch.randn(3, 4); v1, v2 = torch.randn(3), torch.randn(4); f = {f}; ref = torch.func.jvp(f, (x,), (t,))[1]; "
CODE = PRE + "r = torch.compile(lambda x, t: torch.func.jvp(f, (x,), (t,)), backend='{b}')(x, t)[1]; print('ok', (r - ref).abs().max().item())"
print("torch", subprocess.run([sys.executable, "-c", "import torch; print(torch.__version__)"], capture_output=True, text=True).stdout.strip())
for name, f in OPS.items():
    out = []
    for b in ("eager", "aot_eager", "inductor"):
        r = subprocess.run([sys.executable, "-c", CODE.format(f=f, b=b)], capture_output=True, text=True, encoding="utf-8", errors="replace", timeout=600)
        if r.returncode == 0 and r.stdout.startswith("ok"):
            out.append(f"{b}=ok")
        else:
            err = r.stderr
            out.append(f"{b}=" + ("ASSERT_make_dual" if "is_inference" in err else ("cl-not-found" if "cl is not found" in err else "raise " + (err.strip().splitlines()[-1][:60] if err.strip() else f"exit {r.returncode}"))))
    print(f"[{name}] " + " | ".join(out), flush=True)
