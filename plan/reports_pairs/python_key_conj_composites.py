"""With the Python dispatch key included in the thread-local include set (which every TorchDispatchMode does, and which
torch.compile's runtime wrapper does through _AnalyzeCustomOpInputOutputMode), ATen composite kernels that build a
lazy conjugate view internally (.mH()) return wrong values for complex input.  Pure eager, no compiler needed."""
import torch
from torch._C import DispatchKey
from torch.utils._python_dispatch import TorchDispatchMode


class Noop(TorchDispatchMode):
    def __torch_dispatch__(self, func, types, args=(), kwargs=None):
        return func(*args, **(kwargs or {}))

print("torch", torch.__version__)
torch.manual_seed(0)
A = torch.randn(4, 3, dtype=torch.complex64); S = torch.randn(3, 3, dtype=torch.complex64); H = S @ S.mH + 3 * torch.eye(3); tau = torch.randn(3, dtype=torch.complex64)
b = torch.randn(3, 2, dtype=torch.complex64)
CASES = {
    "linalg.pinv(A)": lambda: torch.linalg.pinv(A), "pinverse(A)": lambda: torch.pinverse(A), "linalg.pinv(H, hermitian=True)": lambda: torch.linalg.pinv(H, hermitian=True),
    "linalg.polar(A)[0] U": lambda: torch.linalg.polar(A)[0], "linalg.polar(A)[1] P": lambda: torch.linalg.polar(A)[1],
    "linalg.householder_product": lambda: torch.linalg.householder_product(A, tau), "linalg.lstsq(A, b).solution": lambda: torch.linalg.lstsq(A, torch.randn(4, 2, dtype=torch.complex64, generator=torch.Generator().manual_seed(1))).solution,
    "linalg.matrix_rank": lambda: torch.linalg.matrix_rank(A).to(torch.complex64), "linalg.cond": lambda: torch.linalg.cond(S).to(torch.complex64), "linalg.svdvals": lambda: torch.linalg.svdvals(A).to(torch.complex64),
    "linalg.eigh(H) vectors |v|": lambda: torch.linalg.eigh(H).eigenvectors.abs().to(torch.complex64), "linalg.eig(S) values": lambda: torch.linalg.eig(S).eigenvalues, "linalg.eigvals(S)": lambda: torch.linalg.eigvals(S),
    "linalg.inv(S)": lambda: torch.linalg.inv(S), "linalg.solve(S, b)": lambda: torch.linalg.solve(S, b), "linalg.solve_ex(S, b, left=False)": lambda: torch.linalg.solve(S, b.mH, left=False),
    "linalg.lu_solve(adjoint=True)": lambda: torch.linalg.lu_solve(*torch.linalg.lu_factor(S), b, adjoint=True), "linalg.solve_triangular(upper, left=False)": lambda: torch.linalg.solve_triangular(S.triu(), b.mH, upper=True, left=False),
    "cholesky_inverse": lambda: torch.cholesky_inverse(torch.linalg.cholesky(H)), "cholesky_solve": lambda: torch.cholesky_solve(b, torch.linalg.cholesky(H)), "linalg.cholesky(H, upper=True)": lambda: torch.linalg.cholesky(H, upper=True),
    "linalg.ldl_factor/solve": lambda: torch.linalg.ldl_solve(*torch.linalg.ldl_factor(H), b), "linalg.matrix_exp(S)": lambda: torch.linalg.matrix_exp(S), "linalg.matrix_power(S, -2)": lambda: torch.linalg.matrix_power(S, -2),
    "linalg.det(S)": lambda: torch.linalg.det(S).reshape(1), "linalg.slogdet(S)": lambda: torch.linalg.slogdet(S).sign.reshape(1), "linalg.qr(A).Q": lambda: torch.linalg.qr(A).Q, "linalg.svd(A).U": lambda: torch.linalg.svd(A, full_matrices=False).U,
    "linalg.norm(A, 'nuc')": lambda: torch.linalg.matrix_norm(A, "nuc").to(torch.complex64), "linalg.vector_norm": lambda: torch.linalg.vector_norm(A).to(torch.complex64), "vdot": lambda: torch.vdot(A[:, 0], A[:, 1]).reshape(1),
    "dot": lambda: torch.dot(A[:, 0], A[:, 1]).reshape(1), "linalg.vecdot": lambda: torch.linalg.vecdot(A, A).reshape(-1), "matmul(A.mH, A)": lambda: A.mH @ A, "linalg.multi_dot": lambda: torch.linalg.multi_dot([A.mH, A, S]),
    "linalg.tensorinv": lambda: torch.linalg.tensorinv(S.reshape(3, 3), ind=1), "linalg.tensorsolve": lambda: torch.linalg.tensorsolve(S, b[:, 0]), "cdist-like (A@A.mH).real": lambda: (A @ A.mH).real.to(torch.complex64),
    "linalg.matrix_norm(A, 2)": lambda: torch.linalg.matrix_norm(A, 2).to(torch.complex64), "geqrf/ormqr": lambda: torch.ormqr(*torch.geqrf(S), b, transpose=True), "triangular_solve (deprecated)": lambda: torch.triangular_solve(b, S.triu(), upper=True, transpose=True).solution,
    "fft.fft(A)": lambda: torch.fft.fft(A), "fft.ifft(fft)": lambda: torch.fft.ifft(torch.fft.fft(A)), "stft complex": lambda: torch.stft(A[:, 0].repeat(8), 8, return_complex=True, window=torch.hann_window(8)),
    "conj_physical then mm": lambda: torch.conj_physical(A).mT @ A, "A.conj() @ A": lambda: A.conj().mT @ A, "addmm(S, A.mH, A)": lambda: torch.addmm(S, A.mH, A), "baddbmm": lambda: torch.baddbmm(S[None], A.mH[None], A[None]),
    "einsum('ij,jk', A.mH, A)": lambda: torch.einsum("ij,jk->ik", A.mH, A), "linalg.cross(complex)": lambda: torch.linalg.cross(S, S.mH), "kron(A.mH, S)": lambda: torch.kron(A.mH, S),
}
rows = []
for name, f in CASES.items():
    try:
        plain = f()
        with Noop():
            under = f()
        d = (plain - under).abs().max().item()
        print(f"{'!!' if d > 1e-4 else '  '} {name:42s} max |plain - under no-op TorchDispatchMode| = {d:.3g}", flush=True)
    except Exception as e:
        print(f"?? {name:42s} {type(e).__name__}: {str(e)[:60]}")
