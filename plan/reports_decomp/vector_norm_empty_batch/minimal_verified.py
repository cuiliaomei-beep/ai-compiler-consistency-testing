"""torch.compile rejects linalg.vector_norm(ord=inf/-inf/<0, dim=-1) on an empty *batch*; eager returns an empty result.

Verified on torch 2.14.0+cpu (Windows): eager -> tensor([]) of shape (0,); torch.compile with backend "eager",
"aot_eager" or "inductor" raises at Dynamo's fake-tensor tracing
    linalg.vector_norm cannot compute the inf norm on the dimension -1 because this dimension is empty and the
    operation does not have an identity
The reduced dimension (dim=-1, size 5) is NOT empty; only the batch dimension is. Root cause: the check in
torch/_refs/linalg/__init__.py (_check_vector_norm_args, line 121) evaluates
    sym_or(x.numel() != 0, d < len(shape) and d >= 0 and shape[d] != 0)
with the raw dim, so a negative dim fails whenever numel() == 0. dim=1 / dim=(1,) compile fine.
ord=2 / 0.5 / 0 (which have an identity) are fine with any dim.
Found by the decomposition/meta differential (plan/tcc/decomp_diff.py), variant empty_dim0.
"""
import torch

x = torch.empty(0, 5)


def f(x, d=-1):
    return torch.linalg.vector_norm(x, ord=float("inf"), dim=d)


print(torch.__version__)
print("eager dim=-1 :", f(x))
for d in (-1, 1):
    for backend in ("eager", "aot_eager", "inductor"):
        torch._dynamo.reset()
        try:
            print(f"dim={d:>2} {backend:<9}:", torch.compile(lambda x, _d=d: f(x, _d), backend=backend)(x))
        except Exception as e:  # noqa: BLE001
            inner = e
            while inner.__cause__ is not None:
                inner = inner.__cause__
            print(f"dim={d:>2} {backend:<9}: {type(inner).__name__}: {str(inner)[:110]}")
# also reachable through torch.norm(x, p=float('inf'), dim=-1) and torch.linalg.norm(x, ord=float('inf'), dim=-1)
