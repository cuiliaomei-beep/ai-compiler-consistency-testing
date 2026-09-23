# Decomposition / meta differential

- operators: 11, samples: 33, input variants: 348
- variants where at least one decomposition ran: 220
- decomposition mismatches: 14  (confirmed by torch.compile: 3)
- meta / fake-tensor mismatches: 0 (data-dependent ops that cannot run on fake tensors, not counted: 12)
- wall: 3.9 s

| kind | op | variant | shapes | dtypes | detail | confirmed |
|---|---|---|---|---|---|---|
| data_dependent | cov | base | [[1, 2]] | ['torch.float32'] | fake-tensor path raised DataDependentOutputException: aten.equal.default | None |
| decomp | cov | empty_dim0 | [[0, 2]] | ['torch.float32'] | [exception] test raised TypeError, ref returned normally :: Multiple dispatch failed for ' | False |
| data_dependent | cov | empty_dim0 | [[0, 2]] | ['torch.float32'] | fake-tensor path raised DataDependentOutputException: aten.equal.default | None |
| data_dependent | cov | size1_dim0 | [[1, 2]] | ['torch.float32'] | fake-tensor path raised DataDependentOutputException: aten.equal.default | None |
| decomp | cov | prime_dim0 | [[7, 2]] | ['torch.float32'] | [exception] test raised TypeError, ref returned normally :: Multiple dispatch failed for ' | False |
| data_dependent | cov | prime_dim0 | [[7, 2]] | ['torch.float32'] | fake-tensor path raised DataDependentOutputException: aten.equal.default | None |
| data_dependent | cov | noncontig | [[1, 2]] | ['torch.float32'] | fake-tensor path raised DataDependentOutputException: aten.equal.default | None |
| data_dependent | cov | nan_inf | [[1, 2]] | ['torch.float32'] | fake-tensor path raised DataDependentOutputException: aten.equal.default | None |
| data_dependent | cov | huge | [[1, 2]] | ['torch.float32'] | fake-tensor path raised DataDependentOutputException: aten.equal.default | None |
| data_dependent | cov | tiny | [[1, 2]] | ['torch.float32'] | fake-tensor path raised DataDependentOutputException: aten.equal.default | None |
| data_dependent | cov | dtype_float16 | [[1, 2]] | ['torch.float16'] | fake-tensor path raised DataDependentOutputException: aten.equal.default | None |
| data_dependent | cov | dtype_bfloat16 | [[1, 2]] | ['torch.bfloat16'] | fake-tensor path raised DataDependentOutputException: aten.equal.default | None |
| decomp | cov | base | [[2, 3]] | ['torch.float32'] | [exception] test raised TypeError, ref returned normally :: Multiple dispatch failed for ' | False |
| decomp | cov | empty_last | [[2, 0]] | ['torch.float32'] | [exception] test raised TypeError, ref returned normally :: Multiple dispatch failed for ' | False |
| data_dependent | cov | empty_last | [[2, 0]] | ['torch.float32'] | fake-tensor path raised DataDependentOutputException: aten.equal.default | None |
| data_dependent | cov | size1_last | [[2, 1]] | ['torch.float32'] | fake-tensor path raised DataDependentOutputException: aten.equal.default | None |
| decomp | cov | noncontig | [[2, 3]] | ['torch.float32'] | [exception] test raised TypeError, ref returned normally :: Multiple dispatch failed for ' | False |
| decomp | cov | nan_inf | [[2, 3]] | ['torch.float32'] | [exception] test raised TypeError, ref returned normally :: Multiple dispatch failed for ' | False |
| decomp | cov | huge | [[2, 3]] | ['torch.float32'] | [exception] test raised TypeError, ref returned normally :: Multiple dispatch failed for ' | False |
| decomp | cov | tiny | [[2, 3]] | ['torch.float32'] | [exception] test raised TypeError, ref returned normally :: Multiple dispatch failed for ' | False |
| decomp | cov | dtype_float16 | [[2, 3]] | ['torch.float16'] | [exception] test raised TypeError, ref returned normally :: Multiple dispatch failed for ' | False |
| decomp | cov | dtype_bfloat16 | [[2, 3]] | ['torch.bfloat16'] | [exception] test raised TypeError, ref returned normally :: Multiple dispatch failed for ' | False |
| decomp | std_mean | huge | [[5]] | ['torch.float32'] | [value] output[0]: NaN/Inf pattern differs from the float64 truth | True |
| decomp | std_mean | huge | [[5]] | ['torch.float32'] | [value] output[0]: NaN/Inf pattern differs from the float64 truth | True |
| decomp | index_add | dtype_bfloat16 | [[1], [1], [1]] | ['torch.bfloat16', 'torch.int64', 'torch.bfloat16'] | [exception] test raised TypeError, ref returned normally :: Multiple dispatch failed for ' | False |
| decomp | index_add | empty_last | [[5, 0], [5], [5, 5]] | ['torch.float32', 'torch.int64', 'torch.float32'] | [exception] test raised IndexError, ref returned normally :: index is out of bounds for di | True |
