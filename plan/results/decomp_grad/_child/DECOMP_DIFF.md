# Decomposition / meta differential

- operators: 21, samples: 21, input variants: 297
- variants where at least one decomposition ran: 271
- decomposition mismatches: 5  (confirmed by torch.compile: 3)
- meta / fake-tensor mismatches: 103 (data-dependent ops that cannot run on fake tensors, not counted: 2)
- wall: 10.8 s

| kind | op | variant | shapes | dtypes | detail | confirmed |
|---|---|---|---|---|---|---|
| decomp | bmm | zero_dim | [[], [10, 10, 5]] | ['torch.float32', 'torch.float32'] | [exception] exception type differs: RuntimeError vs IndexError :: tuple index out of range | False |
| meta | masked.sum | base | [[3, 2, 1, 2]] | ['torch.float32'] | fake-tensor path raised AssertionError: Please convert all Tensors to FakeTensors first or | None |
| meta | masked.sum | empty_dim0 | [[0, 2, 1, 2]] | ['torch.float32'] | fake-tensor path raised AssertionError: Please convert all Tensors to FakeTensors first or | None |
| meta | masked.sum | size1_dim0 | [[1, 2, 1, 2]] | ['torch.float32'] | fake-tensor path raised AssertionError: Please convert all Tensors to FakeTensors first or | None |
| meta | masked.sum | prime_dim0 | [[7, 2, 1, 2]] | ['torch.float32'] | fake-tensor path raised AssertionError: Please convert all Tensors to FakeTensors first or | None |
| meta | masked.sum | noncontig | [[3, 2, 1, 2]] | ['torch.float32'] | fake-tensor path raised AssertionError: Please convert all Tensors to FakeTensors first or | None |
| meta | masked.sum | channels_last | [[3, 2, 1, 2]] | ['torch.float32'] | fake-tensor path raised AssertionError: Please convert all Tensors to FakeTensors first or | None |
| meta | masked.sum | dtype_int64 | [[3, 2, 1, 2]] | ['torch.int64'] | fake-tensor path raised AssertionError: Please convert all Tensors to FakeTensors first or | None |
| meta | masked.sum | dtype_bool | [[3, 2, 1, 2]] | ['torch.bool'] | fake-tensor path raised AssertionError: Please convert all Tensors to FakeTensors first or | None |
| meta | masked.sum | nan_inf | [[3, 2, 1, 2]] | ['torch.float32'] | fake-tensor path raised AssertionError: Please convert all Tensors to FakeTensors first or | None |
| meta | masked.sum | huge | [[3, 2, 1, 2]] | ['torch.float32'] | fake-tensor path raised AssertionError: Please convert all Tensors to FakeTensors first or | None |
| meta | masked.sum | tiny | [[3, 2, 1, 2]] | ['torch.float32'] | fake-tensor path raised AssertionError: Please convert all Tensors to FakeTensors first or | None |
| meta | masked.sum | dtype_float16 | [[3, 2, 1, 2]] | ['torch.float16'] | fake-tensor path raised AssertionError: Please convert all Tensors to FakeTensors first or | None |
| meta | masked.sum | dtype_bfloat16 | [[3, 2, 1, 2]] | ['torch.bfloat16'] | fake-tensor path raised AssertionError: Please convert all Tensors to FakeTensors first or | None |
| meta | masked.prod | base | [[]] | ['torch.float32'] | fake-tensor path raised AssertionError: Please convert all Tensors to FakeTensors first or | None |
| meta | masked.prod | dtype_int64 | [[]] | ['torch.int64'] | fake-tensor path raised AssertionError: Please convert all Tensors to FakeTensors first or | None |
| meta | masked.prod | dtype_bool | [[]] | ['torch.bool'] | fake-tensor path raised AssertionError: Please convert all Tensors to FakeTensors first or | None |
| meta | masked.prod | nan_inf | [[]] | ['torch.float32'] | fake-tensor path raised AssertionError: Please convert all Tensors to FakeTensors first or | None |
| meta | masked.prod | huge | [[]] | ['torch.float32'] | fake-tensor path raised AssertionError: Please convert all Tensors to FakeTensors first or | None |
| meta | masked.prod | tiny | [[]] | ['torch.float32'] | fake-tensor path raised AssertionError: Please convert all Tensors to FakeTensors first or | None |
| meta | masked.prod | dtype_float16 | [[]] | ['torch.float16'] | fake-tensor path raised AssertionError: Please convert all Tensors to FakeTensors first or | None |
| meta | masked.prod | dtype_bfloat16 | [[]] | ['torch.bfloat16'] | fake-tensor path raised AssertionError: Please convert all Tensors to FakeTensors first or | None |
| meta | masked.cumsum | base | [[5, 10, 5]] | ['torch.float32'] | fake-tensor path raised AssertionError: Please convert all Tensors to FakeTensors first or | None |
| meta | masked.cumsum | empty_dim0 | [[0, 10, 5]] | ['torch.float32'] | fake-tensor path raised AssertionError: Please convert all Tensors to FakeTensors first or | None |
| meta | masked.cumsum | size1_dim0 | [[1, 10, 5]] | ['torch.float32'] | fake-tensor path raised AssertionError: Please convert all Tensors to FakeTensors first or | None |
| meta | masked.cumsum | prime_dim0 | [[7, 10, 5]] | ['torch.float32'] | fake-tensor path raised AssertionError: Please convert all Tensors to FakeTensors first or | None |
| meta | masked.cumsum | noncontig | [[5, 10, 5]] | ['torch.float32'] | fake-tensor path raised AssertionError: Please convert all Tensors to FakeTensors first or | None |
| meta | masked.cumsum | dtype_int64 | [[5, 10, 5]] | ['torch.int64'] | fake-tensor path raised AssertionError: Please convert all Tensors to FakeTensors first or | None |
| meta | masked.cumsum | nan_inf | [[5, 10, 5]] | ['torch.float32'] | fake-tensor path raised AssertionError: Please convert all Tensors to FakeTensors first or | None |
| meta | masked.cumsum | huge | [[5, 10, 5]] | ['torch.float32'] | fake-tensor path raised AssertionError: Please convert all Tensors to FakeTensors first or | None |
| meta | masked.cumsum | tiny | [[5, 10, 5]] | ['torch.float32'] | fake-tensor path raised AssertionError: Please convert all Tensors to FakeTensors first or | None |
| meta | masked.cumsum | dtype_float16 | [[5, 10, 5]] | ['torch.float16'] | fake-tensor path raised AssertionError: Please convert all Tensors to FakeTensors first or | None |
| meta | masked.cumsum | dtype_bfloat16 | [[5, 10, 5]] | ['torch.bfloat16'] | fake-tensor path raised AssertionError: Please convert all Tensors to FakeTensors first or | None |
| meta | masked.cumprod | base | [[]] | ['torch.float32'] | fake-tensor path raised AssertionError: Please convert all Tensors to FakeTensors first or | None |
| meta | masked.cumprod | dtype_int64 | [[]] | ['torch.int64'] | fake-tensor path raised AssertionError: Please convert all Tensors to FakeTensors first or | None |
| meta | masked.cumprod | dtype_bool | [[]] | ['torch.bool'] | fake-tensor path raised AssertionError: Please convert all Tensors to FakeTensors first or | None |
| meta | masked.cumprod | nan_inf | [[]] | ['torch.float32'] | fake-tensor path raised AssertionError: Please convert all Tensors to FakeTensors first or | None |
| meta | masked.cumprod | huge | [[]] | ['torch.float32'] | fake-tensor path raised AssertionError: Please convert all Tensors to FakeTensors first or | None |
| meta | masked.cumprod | tiny | [[]] | ['torch.float32'] | fake-tensor path raised AssertionError: Please convert all Tensors to FakeTensors first or | None |
| meta | masked.cumprod | dtype_float16 | [[]] | ['torch.float16'] | fake-tensor path raised AssertionError: Please convert all Tensors to FakeTensors first or | None |
| meta | masked.cumprod | dtype_bfloat16 | [[]] | ['torch.bfloat16'] | fake-tensor path raised AssertionError: Please convert all Tensors to FakeTensors first or | None |
| meta | masked.amin | base | [[3, 2, 1, 2]] | ['torch.float32'] | fake-tensor path raised AssertionError: Please convert all Tensors to FakeTensors first or | None |
| meta | masked.amin | noncontig | [[3, 2, 1, 2]] | ['torch.float32'] | fake-tensor path raised AssertionError: Please convert all Tensors to FakeTensors first or | None |
| meta | masked.amin | channels_last | [[3, 2, 1, 2]] | ['torch.float32'] | fake-tensor path raised AssertionError: Please convert all Tensors to FakeTensors first or | None |
| meta | masked.amin | dtype_int64 | [[3, 2, 1, 2]] | ['torch.int64'] | fake-tensor path raised AssertionError: Please convert all Tensors to FakeTensors first or | None |
| meta | masked.amin | nan_inf | [[3, 2, 1, 2]] | ['torch.float32'] | fake-tensor path raised AssertionError: Please convert all Tensors to FakeTensors first or | None |
| meta | masked.amin | huge | [[3, 2, 1, 2]] | ['torch.float32'] | fake-tensor path raised AssertionError: Please convert all Tensors to FakeTensors first or | None |
| meta | masked.amin | tiny | [[3, 2, 1, 2]] | ['torch.float32'] | fake-tensor path raised AssertionError: Please convert all Tensors to FakeTensors first or | None |
| meta | masked.amin | dtype_float16 | [[3, 2, 1, 2]] | ['torch.float16'] | fake-tensor path raised AssertionError: Please convert all Tensors to FakeTensors first or | None |
| meta | masked.amin | dtype_bfloat16 | [[3, 2, 1, 2]] | ['torch.bfloat16'] | fake-tensor path raised AssertionError: Please convert all Tensors to FakeTensors first or | None |
| meta | masked.argmax | base | [[3, 2, 1, 2]] | ['torch.float32'] | fake-tensor path raised AssertionError: Please convert all Tensors to FakeTensors first or | None |
| meta | masked.argmax | empty_last | [[3, 2, 1, 0]] | ['torch.float32'] | fake-tensor path raised AssertionError: Please convert all Tensors to FakeTensors first or | None |
| meta | masked.argmax | size1_last | [[3, 2, 1, 1]] | ['torch.float32'] | fake-tensor path raised AssertionError: Please convert all Tensors to FakeTensors first or | None |
| meta | masked.argmax | noncontig | [[3, 2, 1, 2]] | ['torch.float32'] | fake-tensor path raised AssertionError: Please convert all Tensors to FakeTensors first or | None |
| meta | masked.argmax | channels_last | [[3, 2, 1, 2]] | ['torch.float32'] | fake-tensor path raised AssertionError: Please convert all Tensors to FakeTensors first or | None |
| meta | masked.argmax | dtype_int64 | [[3, 2, 1, 2]] | ['torch.int64'] | fake-tensor path raised AssertionError: Please convert all Tensors to FakeTensors first or | None |
| meta | masked.argmax | nan_inf | [[3, 2, 1, 2]] | ['torch.float32'] | fake-tensor path raised AssertionError: Please convert all Tensors to FakeTensors first or | None |
| meta | masked.argmax | huge | [[3, 2, 1, 2]] | ['torch.float32'] | fake-tensor path raised AssertionError: Please convert all Tensors to FakeTensors first or | None |
| meta | masked.argmax | tiny | [[3, 2, 1, 2]] | ['torch.float32'] | fake-tensor path raised AssertionError: Please convert all Tensors to FakeTensors first or | None |
| meta | masked.argmax | dtype_float16 | [[3, 2, 1, 2]] | ['torch.float16'] | fake-tensor path raised AssertionError: Please convert all Tensors to FakeTensors first or | None |
| meta | masked.argmax | dtype_bfloat16 | [[3, 2, 1, 2]] | ['torch.bfloat16'] | fake-tensor path raised AssertionError: Please convert all Tensors to FakeTensors first or | None |
| meta | masked.argmin | base | [[3, 2, 1, 2]] | ['torch.float32'] | fake-tensor path raised AssertionError: Please convert all Tensors to FakeTensors first or | None |
| meta | masked.argmin | empty_dim0 | [[0, 2, 1, 2]] | ['torch.float32'] | fake-tensor path raised AssertionError: Please convert all Tensors to FakeTensors first or | None |
| meta | masked.argmin | size1_dim0 | [[1, 2, 1, 2]] | ['torch.float32'] | fake-tensor path raised AssertionError: Please convert all Tensors to FakeTensors first or | None |
| meta | masked.argmin | prime_dim0 | [[7, 2, 1, 2]] | ['torch.float32'] | fake-tensor path raised AssertionError: Please convert all Tensors to FakeTensors first or | None |
| meta | masked.argmin | noncontig | [[3, 2, 1, 2]] | ['torch.float32'] | fake-tensor path raised AssertionError: Please convert all Tensors to FakeTensors first or | None |
| meta | masked.argmin | channels_last | [[3, 2, 1, 2]] | ['torch.float32'] | fake-tensor path raised AssertionError: Please convert all Tensors to FakeTensors first or | None |
| meta | masked.argmin | dtype_int64 | [[3, 2, 1, 2]] | ['torch.int64'] | fake-tensor path raised AssertionError: Please convert all Tensors to FakeTensors first or | None |
| meta | masked.argmin | nan_inf | [[3, 2, 1, 2]] | ['torch.float32'] | fake-tensor path raised AssertionError: Please convert all Tensors to FakeTensors first or | None |
| meta | masked.argmin | huge | [[3, 2, 1, 2]] | ['torch.float32'] | fake-tensor path raised AssertionError: Please convert all Tensors to FakeTensors first or | None |
| meta | masked.argmin | tiny | [[3, 2, 1, 2]] | ['torch.float32'] | fake-tensor path raised AssertionError: Please convert all Tensors to FakeTensors first or | None |
| meta | masked.argmin | dtype_float16 | [[3, 2, 1, 2]] | ['torch.float16'] | fake-tensor path raised AssertionError: Please convert all Tensors to FakeTensors first or | None |
| meta | masked.argmin | dtype_bfloat16 | [[3, 2, 1, 2]] | ['torch.bfloat16'] | fake-tensor path raised AssertionError: Please convert all Tensors to FakeTensors first or | None |
| meta | masked.mean | base | [[3, 5]] | ['torch.float32'] | fake-tensor path raised AssertionError: Please convert all Tensors to FakeTensors first or | None |
| meta | masked.mean | noncontig | [[3, 5]] | ['torch.float32'] | fake-tensor path raised AssertionError: Please convert all Tensors to FakeTensors first or | None |
| meta | masked.mean | nan_inf | [[3, 5]] | ['torch.float32'] | fake-tensor path raised AssertionError: Please convert all Tensors to FakeTensors first or | None |
| meta | masked.mean | huge | [[3, 5]] | ['torch.float32'] | fake-tensor path raised AssertionError: Please convert all Tensors to FakeTensors first or | None |
| meta | masked.mean | tiny | [[3, 5]] | ['torch.float32'] | fake-tensor path raised AssertionError: Please convert all Tensors to FakeTensors first or | None |
| meta | masked.mean | dtype_float16 | [[3, 5]] | ['torch.float16'] | fake-tensor path raised AssertionError: Please convert all Tensors to FakeTensors first or | None |
| meta | masked.mean | dtype_bfloat16 | [[3, 5]] | ['torch.bfloat16'] | fake-tensor path raised AssertionError: Please convert all Tensors to FakeTensors first or | None |
| meta | masked.norm | base | [[]] | ['torch.float32'] | fake-tensor path raised AssertionError: Please convert all Tensors to FakeTensors first or | None |
| meta | masked.norm | nan_inf | [[]] | ['torch.float32'] | fake-tensor path raised AssertionError: Please convert all Tensors to FakeTensors first or | None |
| meta | masked.norm | huge | [[]] | ['torch.float32'] | fake-tensor path raised AssertionError: Please convert all Tensors to FakeTensors first or | None |
| meta | masked.norm | tiny | [[]] | ['torch.float32'] | fake-tensor path raised AssertionError: Please convert all Tensors to FakeTensors first or | None |
| meta | masked.norm | dtype_float16 | [[]] | ['torch.float16'] | fake-tensor path raised AssertionError: Please convert all Tensors to FakeTensors first or | None |
| meta | masked.norm | dtype_bfloat16 | [[]] | ['torch.bfloat16'] | fake-tensor path raised AssertionError: Please convert all Tensors to FakeTensors first or | None |
| meta | masked.var | base | [[5, 5, 5]] | ['torch.float32'] | fake-tensor path raised AssertionError: Please convert all Tensors to FakeTensors first or | None |
| meta | masked.var | noncontig | [[5, 5, 5]] | ['torch.float32'] | fake-tensor path raised AssertionError: Please convert all Tensors to FakeTensors first or | None |
| meta | masked.var | dtype_int64 | [[5, 5, 5]] | ['torch.int64'] | fake-tensor path raised AssertionError: Please convert all Tensors to FakeTensors first or | None |
| meta | masked.var | nan_inf | [[5, 5, 5]] | ['torch.float32'] | fake-tensor path raised AssertionError: Please convert all Tensors to FakeTensors first or | None |
| meta | masked.var | huge | [[5, 5, 5]] | ['torch.float32'] | fake-tensor path raised AssertionError: Please convert all Tensors to FakeTensors first or | None |
| meta | masked.var | tiny | [[5, 5, 5]] | ['torch.float32'] | fake-tensor path raised AssertionError: Please convert all Tensors to FakeTensors first or | None |
| meta | masked.var | dtype_float16 | [[5, 5, 5]] | ['torch.float16'] | fake-tensor path raised AssertionError: Please convert all Tensors to FakeTensors first or | None |
| meta | masked.var | dtype_bfloat16 | [[5, 5, 5]] | ['torch.bfloat16'] | fake-tensor path raised AssertionError: Please convert all Tensors to FakeTensors first or | None |
| decomp | masked.softmax | dtype_int64 | [[5, 5]] | ['torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| meta | masked.log_softmax | base | [[5, 0, 0]] | ['torch.float32'] | fake-tensor path raised AssertionError: Please convert all Tensors to FakeTensors first or | None |
| meta | masked.log_softmax | empty_last | [[5, 0, 0]] | ['torch.float32'] | fake-tensor path raised AssertionError: Please convert all Tensors to FakeTensors first or | None |
| meta | masked.log_softmax | size1_last | [[5, 0, 0]] | ['torch.float32'] | fake-tensor path raised AssertionError: Please convert all Tensors to FakeTensors first or | None |
| meta | masked.log_softmax | noncontig | [[5, 0, 0]] | ['torch.float32'] | fake-tensor path raised AssertionError: Please convert all Tensors to FakeTensors first or | None |
| meta | masked.log_softmax | dtype_int64 | [[5, 0, 0]] | ['torch.int64'] | fake-tensor path raised AssertionError: Please convert all Tensors to FakeTensors first or | None |
| meta | masked.log_softmax | nan_inf | [[5, 0, 0]] | ['torch.float32'] | fake-tensor path raised AssertionError: Please convert all Tensors to FakeTensors first or | None |
| meta | masked.log_softmax | huge | [[5, 0, 0]] | ['torch.float32'] | fake-tensor path raised AssertionError: Please convert all Tensors to FakeTensors first or | None |
| meta | masked.log_softmax | tiny | [[5, 0, 0]] | ['torch.float32'] | fake-tensor path raised AssertionError: Please convert all Tensors to FakeTensors first or | None |
| meta | masked.log_softmax | dtype_float16 | [[5, 0, 0]] | ['torch.float16'] | fake-tensor path raised AssertionError: Please convert all Tensors to FakeTensors first or | None |
| meta | masked.log_softmax | dtype_bfloat16 | [[5, 0, 0]] | ['torch.bfloat16'] | fake-tensor path raised AssertionError: Please convert all Tensors to FakeTensors first or | None |
| decomp | masked.softmin | dtype_int64 | [[5, 5]] | ['torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | masked.logaddexp | dtype_int64 | [[5, 5], [5, 5]] | ['torch.int64', 'torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | bmm | zero_dim | [[], [8, 1, 256]] | ['torch.float32', 'torch.float32'] | [exception] exception type differs: RuntimeError vs IndexError :: tuple index out of range | False |
