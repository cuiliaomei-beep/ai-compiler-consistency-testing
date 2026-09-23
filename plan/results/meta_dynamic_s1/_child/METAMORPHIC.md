# Metamorphic relations between compiled executions

- operators: 16, samples: 46, compiles: 92, relation checks: 46 (not applicable in eager: 0, infra: 0)
- violations: 1, of which the plain eager-vs-compiled oracle also differs: 0
- wall: 190.9 s

| relation | op | variant | shapes | dtypes | detail | standard oracle differs |
|---|---|---|---|---|---|---|
| config | masked.argmax | dynamic | [[3, 2, 1, 2]] | ['torch.float32'] | [exception] test raised InductorError, ref returned normally (config-side wrong) | False |
