# reuse under 0/1 specialisation and environment flips (torch 2.14.0+cpu, cpu)

- checks: 260, flagged: 21; wall 308 s

| angle | case | detail |
|---|---|---|
| 0/1 | mean_over_batch dynamic=False batch=0 | eager `('T', 'torch.float32', (4,), False, [nan, nan, nan, nan])` vs compiled `('T', 'torch.float32', (4,), False, [nan, nan, nan, nan])` |
| 0/1 | mean_over_batch dynamic=True batch=0 | eager `('T', 'torch.float32', (4,), False, [nan, nan, nan, nan])` vs compiled `('T', 'torch.float32', (4,), False, [nan, nan, nan, nan])` |
| 0/1 | mean_over_batch dynamic=None batch=0 | eager `('T', 'torch.float32', (4,), False, [nan, nan, nan, nan])` vs compiled `('T', 'torch.float32', (4,), False, [nan, nan, nan, nan])` |
| 0/1 | batch_norm_train dynamic=False batch=1 | eager `raise:ValueError` vs compiled `raise:TorchRuntimeError` |
| 0/1 | batch_norm_train dynamic=True batch=1 | eager `raise:ValueError` vs compiled `raise:TorchRuntimeError` |
| 0/1 | batch_norm_train dynamic=None batch=1 | eager `raise:ValueError` vs compiled `raise:TorchRuntimeError` |
| 0/1 | var_unbiased dynamic=False batch=0 | eager `('T', 'torch.float32', (4,), False, [nan, nan, nan, nan])` vs compiled `('T', 'torch.float32', (4,), False, [nan, nan, nan, nan])` |
| 0/1 | var_unbiased dynamic=False batch=1 | eager `('T', 'torch.float32', (4,), False, [nan, nan, nan, nan])` vs compiled `('T', 'torch.float32', (4,), False, [nan, nan, nan, nan])` |
| 0/1 | var_unbiased dynamic=True batch=0 | eager `('T', 'torch.float32', (4,), False, [nan, nan, nan, nan])` vs compiled `('T', 'torch.float32', (4,), False, [nan, nan, nan, nan])` |
| 0/1 | var_unbiased dynamic=True batch=1 | eager `('T', 'torch.float32', (4,), False, [nan, nan, nan, nan])` vs compiled `('T', 'torch.float32', (4,), False, [nan, nan, nan, nan])` |
| 0/1 | var_unbiased dynamic=None batch=0 | eager `('T', 'torch.float32', (4,), False, [nan, nan, nan, nan])` vs compiled `('T', 'torch.float32', (4,), False, [nan, nan, nan, nan])` |
| 0/1 | var_unbiased dynamic=None batch=1 | eager `('T', 'torch.float32', (4,), False, [nan, nan, nan, nan])` vs compiled `('T', 'torch.float32', (4,), False, [nan, nan, nan, nan])` |
| 0/1 | std_mean dynamic=False batch=0 | eager `(('T', 'torch.float32', (4,), False, [nan, nan, nan, nan]), ('T', 'torch.float32', (4,), F` vs compiled `(('T', 'torch.float32', (4,), False, [nan, nan, nan, nan]), ('T', 'torch.float32', (4,), F` |
| 0/1 | std_mean dynamic=False batch=1 | eager `(('T', 'torch.float32', (4,), False, [nan, nan, nan, nan]), ('T', 'torch.float32', (4,), F` vs compiled `(('T', 'torch.float32', (4,), False, [nan, nan, nan, nan]), ('T', 'torch.float32', (4,), F` |
| 0/1 | std_mean dynamic=True batch=0 | eager `(('T', 'torch.float32', (4,), False, [nan, nan, nan, nan]), ('T', 'torch.float32', (4,), F` vs compiled `(('T', 'torch.float32', (4,), False, [nan, nan, nan, nan]), ('T', 'torch.float32', (4,), F` |
| 0/1 | std_mean dynamic=True batch=1 | eager `(('T', 'torch.float32', (4,), False, [nan, nan, nan, nan]), ('T', 'torch.float32', (4,), F` vs compiled `(('T', 'torch.float32', (4,), False, [nan, nan, nan, nan]), ('T', 'torch.float32', (4,), F` |
| 0/1 | std_mean dynamic=None batch=0 | eager `(('T', 'torch.float32', (4,), False, [nan, nan, nan, nan]), ('T', 'torch.float32', (4,), F` vs compiled `(('T', 'torch.float32', (4,), False, [nan, nan, nan, nan]), ('T', 'torch.float32', (4,), F` |
| 0/1 | std_mean dynamic=None batch=1 | eager `(('T', 'torch.float32', (4,), False, [nan, nan, nan, nan]), ('T', 'torch.float32', (4,), F` vs compiled `(('T', 'torch.float32', (4,), False, [nan, nan, nan, nan]), ('T', 'torch.float32', (4,), F` |
| env | autocast_bf16 | eager `('T', 'torch.bfloat16', (3, 4), False, [0.0078125, 0.0078125, 0.0078125, 0.0078125, -2.156` vs compiled `('T', 'torch.bfloat16', (3, 4), False, [0.007476806640625, 0.007476806640625, 0.0074768066` |
| env | flush_denormal | eager `('T', 'torch.float32', (3, 4), False, [nan, nan, nan, nan, nan, nan, nan, nan, nan, nan, n` vs compiled `('T', 'torch.float32', (3, 4), False, [nan, nan, nan, nan, nan, nan, nan, nan, nan, nan, n` |
| env | module_train_mode | eager `('T', 'torch.float32', (3, 4), True, [0.0, -2.8091750144958496, 2.7156662940979004, -2.612` vs compiled `('T', 'torch.float32', (3, 4), True, [0.0, -0.0, 0.0, -0.0, -0.0, 0.0, -0.0, 0.36791417002` |
