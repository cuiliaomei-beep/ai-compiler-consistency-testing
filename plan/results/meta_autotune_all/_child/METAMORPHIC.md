# Metamorphic relations between compiled executions

- operators: 16, samples: 31, compiles: 62, relation checks: 31 (not applicable in eager: 0, infra: 0)
- violations: 1, of which the plain eager-vs-compiled oracle also differs: 0
- wall: 87.1 s

| relation | op | variant | shapes | dtypes | detail | standard oracle differs |
|---|---|---|---|---|---|---|
| config | bmm | max_autotune | [[10, 5, 10], [10, 10, 5]] | ['torch.float32', 'torch.float32'] | [exception] test raised InductorError, ref returned normally (config-side wrong) | False |
