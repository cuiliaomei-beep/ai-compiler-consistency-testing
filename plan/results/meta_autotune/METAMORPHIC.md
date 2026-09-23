# Metamorphic relations between compiled executions

- operators: 15, samples: 39, compiles: 78, relation checks: 39 (not applicable in eager: 0, infra: 0)
- violations: 4, of which the plain eager-vs-compiled oracle also differs: 0
- wall: 63.3 s

| relation | op | variant | shapes | dtypes | detail | standard oracle differs |
|---|---|---|---|---|---|---|
| config | addmm | max_autotune | [[], [2, 2], [2, 3]] | ['torch.float32', 'torch.float32', 'torch.float32'] | [exception] test raised InductorError, ref returned normally (config-side wrong) | False |
| config | addmm | max_autotune | [[], [2, 2], [2, 3]] | ['torch.float32', 'torch.float32', 'torch.float32'] | [exception] test raised InductorError, ref returned normally (config-side wrong) | False |
| config | bmm | max_autotune | [[10, 5, 10], [10, 10, 5]] | ['torch.float32', 'torch.float32'] | [exception] test raised InductorError, ref returned normally (config-side wrong) | False |
| config | matmul | max_autotune | [[5, 10], [5, 10, 5]] | ['torch.float32', 'torch.float32'] | [exception] test raised InductorError, ref returned normally (config-side wrong) | False |
