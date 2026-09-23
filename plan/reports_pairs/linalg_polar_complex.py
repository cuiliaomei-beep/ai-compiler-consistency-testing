"""torch.linalg.polar on a complex input: P (the Hermitian factor) loses the imaginary parts of its off-diagonal
entries under torch.compile."""
import os, sys, tempfile
os.environ.setdefault("TORCHINDUCTOR_CACHE_DIR", tempfile.mkdtemp(prefix="tcc_pol_"))
try:
    sys.path.insert(0, os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
    from tcc.compat import ensure_msvc_env
    ensure_msvc_env()
except Exception:  # noqa: BLE001
    pass
import torch

print("torch", torch.__version__)
a = torch.tensor([[1 + 1j, 2 - 1j], [0.5j, -1 + 0j]], dtype=torch.complex64)
for dev in ["cpu"] + (["cuda"] if torch.cuda.is_available() else []):
    for dt in (torch.complex64, torch.complex128):
        x = a.to(dt).to(dev)
        eU, eP = torch.linalg.polar(x)
        for backend in ("eager", "aot_eager", "inductor"):
            torch._dynamo.reset()
            cU, cP = torch.compile(lambda m: torch.linalg.polar(m), backend=backend)(x)
            print(f"[{dev}] {str(dt):16s} {backend:9s} P[0,1] eager {eP[0, 1].item()}  compiled {cP[0, 1].item()}   |U diff| {(eU - cU).abs().max().item():.2e}  |P diff| {(eP - cP).abs().max().item():.2e}  U@P==A: {torch.allclose(cU @ cP, x, atol=1e-4)}", flush=True)
    x = a.to(dev)
    torch._dynamo.reset()
    gm_holder = []
    def backend(gm, ex):
        gm_holder.append(gm); return gm.forward
    torch.compile(lambda m: torch.linalg.polar(m), backend=backend)(x)
    print("Dynamo graph ops:", [n.target for n in gm_holder[0].graph.nodes if n.op == "call_function"])
    from torch._functorch.aot_autograd import aot_export_module
    try:
        g, _ = aot_export_module(torch.nn.Module().__class__() if False else __import__("torch").fx.symbolic_trace(lambda m: torch.linalg.polar(m)) if False else gm_holder[0], [x], trace_joint=False)
        print("AOT graph:", [str(n.target).split(".")[-2:] if hasattr(n.target, "name") else n.target for n in g.graph.nodes if n.op == "call_function"])
    except Exception as e:
        print("aot_export failed", type(e).__name__, str(e)[:100])
