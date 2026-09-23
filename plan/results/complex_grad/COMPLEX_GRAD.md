# complex-input gradients eager vs aot_eager (torch 2.14.0+cpu)

- operators: 327, samples run: 908, flagged: 5; wall 86 s

| op | sample | shapes | eager err | compiled err | scale |
|---|---|---|---|---|---|
| pinverse | 0 | [[5, 5]] | 2.9e-06 | 3.9e+00 | 3.0e+00 |
| linalg.matrix_sqrth | 0 | [[5, 5]] | 1.2e-06 | 4.7e-01 | 1.0e+00 |
| linalg.pinv | 0 | [[5, 5]] | 2.9e-06 | 3.9e+00 | 3.0e+00 |
| linalg.pinv | 1 | [[3, 1], [3, 1]] | 1.1e-06 | 2.0e+00 | 1.5e+00 |
| linalg.pinv | 2 | [[3, 2], [3, 2]] | 9.6e-07 | 9.3e-01 | 1.5e+00 |

## errors (30)

- sparse.sampled_addmm sample 0: RuntimeError: unsupported tensor layout: SparseCsr
- sparse.sampled_addmm sample 1: RuntimeError: unsupported tensor layout: SparseCsr
- sparse.sampled_addmm sample 2: RuntimeError: unsupported tensor layout: SparseCsr
- meshgrid sample 0: RuntimeError: `inputs` argument to `grad()` cannot be empty.
- meshgrid sample 1: RuntimeError: `inputs` argument to `grad()` cannot be empty.
- meshgrid sample 2: RuntimeError: `inputs` argument to `grad()` cannot be empty.
- as_strided sample 2: RuntimeError: setStorage: sizes [2, 2], strides [1, 2], storage offset 10, and itemsize 16 requiring a storage siz
- einsum sample 0: RuntimeError: `inputs` argument to `grad()` cannot be empty.
- einsum sample 1: RuntimeError: `inputs` argument to `grad()` cannot be empty.
- einsum sample 2: RuntimeError: `inputs` argument to `grad()` cannot be empty.
- column_stack sample 0: RuntimeError: `inputs` argument to `grad()` cannot be empty.
- column_stack sample 1: RuntimeError: `inputs` argument to `grad()` cannot be empty.
- column_stack sample 2: RuntimeError: `inputs` argument to `grad()` cannot be empty.
- stack sample 0: RuntimeError: `inputs` argument to `grad()` cannot be empty.
- stack sample 1: RuntimeError: `inputs` argument to `grad()` cannot be empty.
- stack sample 2: RuntimeError: `inputs` argument to `grad()` cannot be empty.
- hstack sample 0: RuntimeError: `inputs` argument to `grad()` cannot be empty.
- hstack sample 1: RuntimeError: `inputs` argument to `grad()` cannot be empty.
- cat sample 0: RuntimeError: `inputs` argument to `grad()` cannot be empty.
- cat sample 1: RuntimeError: `inputs` argument to `grad()` cannot be empty.
- cat sample 2: RuntimeError: `inputs` argument to `grad()` cannot be empty.
- vstack sample 0: RuntimeError: `inputs` argument to `grad()` cannot be empty.
- vstack sample 1: RuntimeError: `inputs` argument to `grad()` cannot be empty.
- dstack sample 0: RuntimeError: `inputs` argument to `grad()` cannot be empty.
- dstack sample 1: RuntimeError: `inputs` argument to `grad()` cannot be empty.
- to_sparse sample 0: RuntimeError: _to_sparse does not support automatic differentiation for outputs with complex dtype.
- to_sparse sample 1: RuntimeError: _to_sparse does not support automatic differentiation for outputs with complex dtype.
- linalg.multi_dot sample 0: RuntimeError: `inputs` argument to `grad()` cannot be empty.
- linalg.multi_dot sample 1: RuntimeError: `inputs` argument to `grad()` cannot be empty.
- linalg.multi_dot sample 2: RuntimeError: `inputs` argument to `grad()` cannot be empty.
