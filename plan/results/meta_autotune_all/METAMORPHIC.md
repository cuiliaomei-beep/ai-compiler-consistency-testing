# Metamorphic relations between compiled executions

- operators: 583, samples: 1124, compiles: 2237, relation checks: 1113 (not applicable in eager: 0, infra: 0)
- violations: 3, of which the plain eager-vs-compiled oracle also differs: 0
- wall: 1511.9 s

| relation | op | variant | shapes | dtypes | detail | standard oracle differs |
|---|---|---|---|---|---|---|
| config | bmm | max_autotune | [[10, 5, 10], [10, 10, 5]] | ['torch.float32', 'torch.float32'] | [exception] test raised InductorError, ref returned normally (config-side wrong) | False |
| config | linalg.matrix_power | max_autotune | [[0, 2, 2]] | ['torch.float32'] | [exception] test raised InductorError, ref returned normally (config-side wrong) | False |
| config | bmm | max_autotune | [[10, 5, 10], [10, 10, 5]] | ['torch.float32', 'torch.float32'] | [exception] test raised InductorError, ref returned normally (config-side wrong) | False |
