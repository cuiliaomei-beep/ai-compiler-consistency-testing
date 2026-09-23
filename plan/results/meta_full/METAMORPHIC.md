# Metamorphic relations between compiled executions

- operators: 572, samples: 572, compiles: 7360, relation checks: 7212 (not applicable in eager: 448, infra: 0)
- violations: 3, of which the plain eager-vs-compiled oracle also differs: 0
- wall: 590.4 s

| relation | op | variant | shapes | dtypes | detail | standard oracle differs |
|---|---|---|---|---|---|---|
| config | cov | dynamic | [[1, 2]] | ['torch.float32'] | [exception] test raised TorchRuntimeError, ref returned normally (config-side wrong) | False |
| config | max_pool2d_with_indices_backward | dynamic | [[2, 3, 6]] | ['torch.float32'] | [exception] test raised TorchRuntimeError, ref returned normally (config-side wrong) | False |
| config | masked.argmin | dynamic | [[3, 2, 1, 2]] | ['torch.float32'] | [exception] test raised InductorError, ref returned normally (config-side wrong) | False |
