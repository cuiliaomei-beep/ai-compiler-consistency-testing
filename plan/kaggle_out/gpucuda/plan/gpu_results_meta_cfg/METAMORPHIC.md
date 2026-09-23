# Metamorphic relations between compiled executions

- operators: 561, samples: 1080, compiles: 6455, relation checks: 5375 (not applicable in eager: 0, infra: 0)
- violations: 9, of which the plain eager-vs-compiled oracle also differs: 0
- wall: 1786.2 s

| relation | op | variant | shapes | dtypes | detail | standard oracle differs |
|---|---|---|---|---|---|---|
| config | combinations | dynamic | [[2]] | ['torch.float32'] | [exception] test raised TorchRuntimeError, ref returned normally (config-side wrong) | False |
| config | cov | dynamic | [[1, 2]] | ['torch.float32'] | [exception] test raised TorchRuntimeError, ref returned normally (config-side wrong) | False |
| config | quantile | dynamic | [[3, 2, 1, 2], [2]] | ['torch.float32', 'torch.float32'] | [exception] test raised TorchRuntimeError, ref returned normally (config-side wrong) | False |
| config | nanquantile | dynamic | [[3, 2, 1, 2], [2]] | ['torch.float32', 'torch.float32'] | [exception] test raised TorchRuntimeError, ref returned normally (config-side wrong) | False |
| config | nn.functional.adaptive_avg_pool2d | dynamic | [[2, 8, 8, 8]] | ['torch.float32'] | [exception] test raised InductorError, ref returned normally (config-side wrong) | False |
| config | nn.functional.interpolate | dynamic | [[2, 3, 4, 4]] | ['torch.float32'] | [exception] test raised InductorError, ref returned normally (config-side wrong) | False |
| config | nn.functional.upsample_bilinear | dynamic | [[2, 3, 4, 4]] | ['torch.float32'] | [exception] test raised InductorError, ref returned normally (config-side wrong) | False |
| config | max_pool2d_with_indices_backward | dynamic | [[1, 2, 6, 6]] | ['torch.float32'] | [exception] test raised TorchRuntimeError, ref returned normally (config-side wrong) | False |
| config | new_zeros | cudagraphs | [[5]] | ['torch.float32'] | [metadata] output[0].device: cpu vs cuda (config-side wrong) | False |
