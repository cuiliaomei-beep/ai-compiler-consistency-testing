# export / AOTInductor differential

- operators: 561, samples: 561; export ok/fail: 544/15; AOTI ok/fail: 2/542
- findings: 2 — export-only 2, aoti-only 0, shared with torch.compile(inductor) 0
- wall: 2945.8 s

| path | op | kwargs | shapes | dtypes | detail | inductor too |
|---|---|---|---|---|---|---|
| export | masked_select | {} | [[10], [10, 10]] | ['torch.float32', 'torch.bool'] | [exception] test raised RuntimeError, ref returned normally | False |
| export | nn.functional.multi_head_attention_forward | {'q_proj_weight': tensor([[ 3.8075, -6.0 | [[3, 2, 2], [5, 2, 2], [5, 2, 2], [6], [2], [2], [2, 2], [2]] | ['torch.float32', 'torch.float32', 'torch.float32', 'torch.float32', 'torch.float32', 'torch.float32', 'torch.float32', 'torch.float32'] | [value] output[0]: /ref-test/ = 5.859e+02 exceeds dtype-aware tolerance 5.771e-01 (no fp64 reference | False |
