# export / AOTInductor differential

- operators: 509, samples: 509; export ok/fail: 497/7; AOTI ok/fail: 464/33
- findings: 7 — export-only 2, aoti-only 3, shared with torch.compile(inductor) 2
- wall: 3327.9 s

- operators whose child interpreter died: slice_scatter (rc 3221225477), kron (rc 3221225477), repeat_interleave (rc 3221225477)

| path | op | kwargs | shapes | dtypes | detail | inductor too |
|---|---|---|---|---|---|---|
| aoti | item | {} | [[1]] | ['torch.float32'] | [structure] output structure differs: float vs T | False |
| aoti | var_mean | {} | [[0, 5]] | ['torch.float32'] | [value] output[1]: NaN/Inf pattern differs from the float64 truth | True |
| aoti | std_mean | {} | [[0]] | ['torch.float32'] | [value] output[1]: NaN/Inf pattern differs from the float64 truth | True |
| export | nn.functional.dropout2d | {'p': 0.5, 'training': True} | [[5, 5, 5, 5]] | ['torch.float32'] | [value] output[0]: compiled err vs fp64 = 1.795e+01 exceeds 4.0x eager err 0.000e+00 | False |
| aoti | nn.functional.dropout2d | {'p': 0.5, 'training': True} | [[5, 5, 5, 5]] | ['torch.float32'] | [value] output[0]: compiled err vs fp64 = 1.795e+01 exceeds 4.0x eager err 0.000e+00 | False |
| export | nn.functional.dropout3d | {'p': 0.5, 'training': True} | [[5, 5, 5, 5]] | ['torch.float32'] | [value] output[0]: compiled err vs fp64 = 1.798e+01 exceeds 4.0x eager err 0.000e+00 | False |
| aoti | nn.functional.dropout3d | {'p': 0.5, 'training': True} | [[5, 5, 5, 5]] | ['torch.float32'] | [value] output[0]: compiled err vs fp64 = 1.795e+01 exceeds 4.0x eager err 0.000e+00 | False |
| aoti | hash_tensor | {'dim': (0, 1, 2, 3), 'keepdim': False} | [[3, 2, 1, 2]] | ['torch.float32'] | [exception] test raised RuntimeError, ref returned normally | False |
