"""torch.linalg.pinv and torch.linalg.polar on complex input return wrong values as soon as a TorchDispatchMode is active
(even one that only forwards), and therefore under torch.compile, whose runtime wrapper runs the graph under
_AnalyzeCustomOpInputOutputMode.  One conjugation taken inside the ATen kernel (`vh.mH()`) is dropped:
pinv comes back as vh.mT @ diag(1/s) @ u.mH.  The same formula written op by op is right under the mode."""
import torch
from torch.utils._python_dispatch import TorchDispatchMode

print("torch", torch.__version__, "cuda", torch.cuda.is_available())


class Forward(TorchDispatchMode):
    def __torch_dispatch__(self, func, types, args=(), kwargs=None):
        return func(*args, **(kwargs or {}))


def manual_pinv(a):
    u, s, vh = torch.linalg.svd(a, full_matrices=False)
    return vh.mH @ torch.diag(1 / s).to(a.dtype) @ u.mH


for dev in ["cpu"] + (["cuda"] if torch.cuda.is_available() else []):
    for dt in (torch.complex64, torch.complex128, torch.float32):
        torch.manual_seed(0)
        A = torch.randn(4, 3, dtype=dt, device=dev)
        ref_pinv, ref_P = torch.linalg.pinv(A), torch.linalg.polar(A)[1]
        with Forward():
            m_pinv, m_P, m_manual = torch.linalg.pinv(A), torch.linalg.polar(A)[1], manual_pinv(A)
        torch._dynamo.reset()
        c_pinv = torch.compile(torch.linalg.pinv)(A)
        torch._dynamo.reset()
        c_P = torch.compile(lambda x: torch.linalg.polar(x)[1])(A)
        u, s, vh = torch.linalg.svd(A, full_matrices=False)
        wrong_formula = vh.mT @ torch.diag(1 / s).to(dt) @ u.mH
        print(f"[{dev}] {str(dt):16s} pinv: |mode - eager| {(m_pinv - ref_pinv).abs().max().item():.3g}  |compile - eager| {(c_pinv - ref_pinv).abs().max().item():.3g}  "
              f"|mode - op-by-op formula| {(m_manual - ref_pinv).abs().max().item():.3g}  mode == vh.mT@S@u.mH: {torch.allclose(m_pinv, wrong_formula, atol=1e-4)}  "
              f"A@pinv@A==A under compile: {torch.allclose(A @ c_pinv @ A, A, atol=1e-4)}", flush=True)
        print(f"[{dev}] {str(dt):16s} polar P: |mode - eager| {(m_P - ref_P).abs().max().item():.3g}  |compile - eager| {(c_P - ref_P).abs().max().item():.3g}  "
              f"U@P==A under compile: {torch.allclose(torch.linalg.polar(A)[0] @ c_P, A, atol=1e-4)}", flush=True)
