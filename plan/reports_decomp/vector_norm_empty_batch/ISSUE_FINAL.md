> Superseded 2026-09-10 by `plan/issues_0910/04-vector-norm-empty-batch.md` (root cause corrected: the check uses the
> un-normalized negative `dim`; `dim=1` works, `dim=-1` fails). Kept for history.

# [pt2] `linalg.vector_norm(ord=inf / -inf / <0)` on an empty *batch* fails under `torch.compile`; eager returns an empty result

## Summary

`torch.linalg.vector_norm(x, ord=float("inf"), dim=-1)` with `x` of shape `(0, 5)` returns `tensor([])` (shape
`(0,)`) in eager: the reduced dimension has 5 elements, only the batch dimension is empty. Under `torch.compile`
(both `backend="aot_eager"` and `"inductor"`) the fake-tensor path raises

```
linalg.vector_norm cannot compute the inf norm on an empty tensor because the operation does not have an identity
```

Same for `ord=-inf` and any negative `ord`; `ord=2 / 0.5 / 0` (which have an identity) are fine. Also reachable
through `torch.norm(x, p=float("inf"), dim=-1)` and `torch.linalg.norm`. A batch that happens to be empty (empty
batch through a max-norm / gradient clipping / masked attention with zero rows) therefore crashes compiled code
that works eagerly.

## Environment

- PyTorch 2.14.0+cpu (git 08187d9e0fba026dc8217405802ab5381dc88d90), Python 3.14.7
- Windows 11, CPU only (the failure is in the Python reference used by fake tensors, not in codegen)

## Minimal reproducer

```python
import torch

x = torch.empty(0, 5)

def f(x):
    return torch.linalg.vector_norm(x, ord=float("inf"), dim=-1)

print("eager   :", f(x))                                            # tensor([])
for backend in ("aot_eager", "inductor"):
    torch._dynamo.reset()
    try:
        print(backend, ":", torch.compile(f, backend=backend)(x))
    except Exception as e:
        print(backend, ": raised", type(e).__name__)                # TorchRuntimeError (RuntimeError: ... cannot compute the inf norm on an empty tensor ...)
```

## Expected behavior

`tensor([])` of shape `(0,)`, as in eager: the reduction dimension is not empty.

## Actual behavior

Compile fails at trace time with the "empty tensor / no identity" error.

## Notes

- Root cause: `_check_vector_norm_args` in `torch/_refs/linalg/__init__.py` tests `x.numel() != 0`; with an
  integer `dim` it never looks at `shape[dim]`, so an empty batch with a non-empty reduced dimension is rejected.
  Eager's C++ check is per reduced dimension. The tuple form `dim=(1,)` goes through the branch that does check
  `shape[d]` and compiles fine — only the integer `dim` form fails, which is the common spelling. (`dim=None` on an
  all-empty tensor raises in eager too, as intended.)
- #148809 touched the same check (inlined the size-oblivious guards) but kept the `numel()` test.
- Found by a fake-tensor-vs-real metadata differential over OpInfo samples with empty-batch variants.
