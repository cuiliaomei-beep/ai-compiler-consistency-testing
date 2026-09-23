# compiled_autograd (aot_eager) vs eager backward, torch 2.14.0+cpu

- operators: 541, rows: 540, flagged: 20; wall 126 s

| op | finding |
|---|---|
| sparse.sampled_addmm | RuntimeError: unsupported tensor layout: SparseCsr |
| sparse.mm | IndexError: tuple index out of range |
| meshgrid | RuntimeError: `inputs` argument to `grad()` cannot be empty. |
| nn.functional.interpolate | TorchRuntimeError: RuntimeError when making fake tensor call |
| nn.functional.interpolate | TorchRuntimeError: RuntimeError when making fake tensor call |
| nn.functional.interpolate | TorchRuntimeError: RuntimeError when making fake tensor call |
| nn.functional.interpolate | TorchRuntimeError: RuntimeError when making fake tensor call |
| nn.functional.interpolate | TorchRuntimeError: RuntimeError when making fake tensor call |
| nn.functional.interpolate | TorchRuntimeError: RuntimeError when making fake tensor call |
| nn.functional.upsample_bilinear | TorchRuntimeError: RuntimeError when making fake tensor call |
| nn.functional.upsample_nearest | TorchRuntimeError: RuntimeError when making fake tensor call |
| einsum | RuntimeError: `inputs` argument to `grad()` cannot be empty. |
| column_stack | RuntimeError: `inputs` argument to `grad()` cannot be empty. |
| stack | RuntimeError: `inputs` argument to `grad()` cannot be empty. |
| hstack | RuntimeError: `inputs` argument to `grad()` cannot be empty. |
| cat | RuntimeError: `inputs` argument to `grad()` cannot be empty. |
| vstack | RuntimeError: `inputs` argument to `grad()` cannot be empty. |
| dstack | RuntimeError: `inputs` argument to `grad()` cannot be empty. |
| to_sparse | IndexError: tuple index out of range |
| linalg.multi_dot | RuntimeError: `inputs` argument to `grad()` cannot be empty. |
