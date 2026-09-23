# Metamorphic relations between compiled executions

- operators: 583, samples: 1640, compiles: 3264, relation checks: 1624 (not applicable in eager: 0, infra: 0)
- violations: 3, of which the plain eager-vs-compiled oracle also differs: 0
- wall: 3092.3 s

| relation | op | variant | shapes | dtypes | detail | standard oracle differs |
|---|---|---|---|---|---|---|
| config | cov | dynamic | [[3, 2]] | ['torch.float32'] | [exception] test raised TorchRuntimeError, ref returned normally (config-side wrong) | False |
| config | max_pool2d_with_indices_backward | dynamic | [[2, 2, 3, 6]] | ['torch.float32'] | [exception] test raised TorchRuntimeError, ref returned normally (config-side wrong) | False |
| config | masked.argmax | dynamic | [[3, 2, 1, 2]] | ['torch.float32'] | [exception] test raised InductorError, ref returned normally (config-side wrong) | False |
