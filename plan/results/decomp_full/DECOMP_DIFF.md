# Decomposition / meta differential

- operators: 576, samples: 1110, input variants: 11911
- variants where at least one decomposition ran: 5506
- decomposition mismatches: 100  (confirmed by torch.compile: 37)
- meta / fake-tensor mismatches: 7 (data-dependent ops that cannot run on fake tensors, not counted: 128)
- wall: 384.3 s

- operators whose child interpreter died (native abort / timeout): linalg.eigvals (rc 3221225477)

| kind | op | variant | shapes | dtypes | detail | confirmed |
|---|---|---|---|---|---|---|
| decomp | bmm | empty_dim0 | [[0, 512, 1], [1, 1, 128]] | ['torch.float32', 'torch.float32'] | [exception] ref raised RuntimeError, test returned normally | False |
| decomp | bmm | prime_dim0 | [[7, 512, 1], [1, 1, 128]] | ['torch.float32', 'torch.float32'] | [exception] ref raised RuntimeError, test returned normally | False |
| decomp | bmm | size1_dim0 | [[1, 128, 1], [8, 1, 256]] | ['torch.float32', 'torch.float32'] | [exception] ref raised RuntimeError, test returned normally | False |
| decomp | stft | empty_dim0 | [[0]] | ['torch.float32'] | [exception] exception type differs: RuntimeError vs IndexError :: index is out of bounds f | False |
| decomp | stft | size1_dim0 | [[1]] | ['torch.float32'] | [exception] exception type differs: RuntimeError vs IndexError :: index -3 is out of bound | False |
| decomp | std_mean | huge | [[5, 5, 5]] | ['torch.float32'] | [value] output[0]: NaN/Inf pattern differs from the float64 truth | True |
| decomp | std_mean | huge | [[5]] | ['torch.float32'] | [value] output[0]: NaN/Inf pattern differs from the float64 truth | True |
| decomp | nn.functional.cross_entropy | empty_last | [[2, 0], [2]] | ['torch.float32', 'torch.int64'] | [exception] exception type differs: RuntimeError vs AssertionError :: weight tensor should | True |
| decomp | nn.functional.cross_entropy | size1_last | [[2, 1], [2]] | ['torch.float32', 'torch.int64'] | [exception] exception type differs: RuntimeError vs AssertionError :: weight tensor should | True |
| decomp | nn.functional.cross_entropy | dtype_float16 | [[2, 3], [2]] | ['torch.float16', 'torch.int64'] | [exception] ref raised RuntimeError, test returned normally | True |
| decomp | nn.functional.cross_entropy | dtype_bfloat16 | [[2, 3], [2]] | ['torch.bfloat16', 'torch.int64'] | [exception] ref raised RuntimeError, test returned normally | True |
| decomp | nn.functional.linear_cross_entropy | dtype_float16 | [[8], [8, 8], []] | ['torch.float16', 'torch.float16', 'torch.int64'] | [exception] ref raised RuntimeError, test returned normally | True |
| decomp | nn.functional.linear_cross_entropy | dtype_bfloat16 | [[8], [8, 8], []] | ['torch.bfloat16', 'torch.bfloat16', 'torch.int64'] | [exception] ref raised RuntimeError, test returned normally | True |
| decomp | native_batch_norm | empty_dim0 | [[0, 1], [1], [1], [1], [1]] | ['torch.float32', 'torch.float32', 'torch.float32', 'torch.float32', 'torch.float32'] | [exception] ref raised RuntimeError, test returned normally | True |
| decomp | native_batch_norm | size1_dim0 | [[1, 1], [1], [1], [1], [1]] | ['torch.float32', 'torch.float32', 'torch.float32', 'torch.float32', 'torch.float32'] | [exception] test raised ZeroDivisionError, ref returned normally :: division by zero | True |
| meta | native_batch_norm | size1_dim0 | [[1, 1], [1], [1], [1], [1]] | ['torch.float32', 'torch.float32', 'torch.float32', 'torch.float32', 'torch.float32'] | fake-tensor path raised ZeroDivisionError: division by zero | None |
| decomp | nn.functional.group_norm | huge | [[1, 3]] | ['torch.float32'] | [value] output[0]: NaN/Inf present on one side only | False |
| decomp | nn.functional.pad | empty_dim0 | [[0, 3]] | ['torch.float32'] | [exception] ref raised RuntimeError, test returned normally | False |
| decomp | nn.functional.pad | empty_last | [[1, 0]] | ['torch.float32'] | [exception] exception type differs: RuntimeError vs IndexError :: index is out of bounds f | False |
| decomp | nn.functional.pad | size1_last | [[1, 1]] | ['torch.float32'] | [exception] ref raised RuntimeError, test returned normally | False |
| decomp | nn.functional.pad | empty_last | [[1, 3, 0]] | ['torch.float32'] | [exception] exception type differs: RuntimeError vs IndexError :: index is out of bounds f | False |
| decomp | nn.functional.pad | empty_last | [[2, 6, 5, 0]] | ['torch.float32'] | [exception] exception type differs: RuntimeError vs IndexError :: index is out of bounds f | False |
| meta | nn.functional.interpolate | empty_dim0 | [[0, 3, 4, 4, 4]] | ['torch.float32'] | fake-tensor path raised TypeError: cond must be a bool, but got <class 'int'> | None |
| decomp | nn.functional.interpolate | empty_last | [[2, 3, 4, 4, 0]] | ['torch.float32'] | [exception] exception type differs: RuntimeError vs IndexError :: index is out of bounds f | True |
| meta | nn.functional.interpolate | empty_dim0 | [[0, 3, 4]] | ['torch.float32'] | fake-tensor path raised TypeError: cond must be a bool, but got <class 'int'> | None |
| decomp | nn.functional.interpolate | empty_last | [[2, 3, 0]] | ['torch.float32'] | [exception] exception type differs: RuntimeError vs ZeroDivisionError :: division by zero | True |
| decomp | nn.functional.interpolate | size1_last | [[2, 3, 1]] | ['torch.float32'] | [exception] ref raised RuntimeError, test returned normally | True |
| decomp | nn.functional.interpolate | empty_last | [[2, 3, 0]] | ['torch.float32'] | [exception] exception type differs: RuntimeError vs IndexError :: index is out of bounds f | True |
| decomp | nn.functional.interpolate | empty_last | [[2, 3, 0]] | ['torch.float32'] | [exception] exception type differs: RuntimeError vs ZeroDivisionError :: division by zero | True |
| decomp | nn.functional.soft_margin_loss | size1_dim0 | [[1, 5, 5], [5, 5, 5]] | ['torch.float32', 'torch.float32'] | [exception] ref raised RuntimeError, test returned normally | True |
| decomp | nn.functional.soft_margin_loss | size1_last | [[5, 5, 1], [5, 5, 5]] | ['torch.float32', 'torch.float32'] | [exception] ref raised RuntimeError, test returned normally | True |
| meta | nn.functional.upsample_nearest | empty_dim0 | [[0, 3, 4, 4, 4]] | ['torch.float32'] | fake-tensor path raised TypeError: cond must be a bool, but got <class 'int'> | None |
| decomp | nn.functional.upsample_nearest | empty_last | [[2, 3, 4, 4, 0]] | ['torch.float32'] | [exception] exception type differs: RuntimeError vs ZeroDivisionError :: division by zero | True |
| decomp | nn.functional.upsample_nearest | size1_last | [[2, 3, 4, 4, 1]] | ['torch.float32'] | [exception] ref raised RuntimeError, test returned normally | True |
| decomp | nn.functional.multi_margin_loss | dtype_float16 | [[], []] | ['torch.float16', 'torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.multi_margin_loss | dtype_bfloat16 | [[], []] | ['torch.bfloat16', 'torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.multilabel_margin_loss | nan_inf | [[10, 5], [10, 5]] | ['torch.float32', 'torch.int64'] | [value] output[0]: NaN/Inf pattern differs from the float64 truth | True |
| decomp | nn.functional.multilabel_margin_loss | dtype_float16 | [[10, 5], [10, 5]] | ['torch.float16', 'torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.multilabel_margin_loss | dtype_bfloat16 | [[10, 5], [10, 5]] | ['torch.bfloat16', 'torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.multilabel_soft_margin_loss | base | [[5, 5], [5, 5]] | ['torch.float32', 'torch.float32'] | [exception] test raised TypeError, ref returned normally :: unsupported operand type(s) fo | False |
| decomp | nn.functional.multilabel_soft_margin_loss | size1_dim0 | [[1, 5], [5, 5]] | ['torch.float32', 'torch.float32'] | [exception] test raised TypeError, ref returned normally :: unsupported operand type(s) fo | False |
| decomp | nn.functional.multilabel_soft_margin_loss | size1_last | [[5, 1], [5, 5]] | ['torch.float32', 'torch.float32'] | [exception] test raised TypeError, ref returned normally :: unsupported operand type(s) fo | False |
| decomp | nn.functional.multilabel_soft_margin_loss | noncontig | [[5, 5], [5, 5]] | ['torch.float32', 'torch.float32'] | [exception] test raised TypeError, ref returned normally :: unsupported operand type(s) fo | False |
| decomp | nn.functional.multilabel_soft_margin_loss | nan_inf | [[5, 5], [5, 5]] | ['torch.float32', 'torch.float32'] | [exception] test raised TypeError, ref returned normally :: unsupported operand type(s) fo | False |
| decomp | nn.functional.multilabel_soft_margin_loss | huge | [[5, 5], [5, 5]] | ['torch.float32', 'torch.float32'] | [exception] test raised TypeError, ref returned normally :: unsupported operand type(s) fo | False |
| decomp | nn.functional.multilabel_soft_margin_loss | tiny | [[5, 5], [5, 5]] | ['torch.float32', 'torch.float32'] | [exception] test raised TypeError, ref returned normally :: unsupported operand type(s) fo | False |
| decomp | nn.functional.multilabel_soft_margin_loss | dtype_float16 | [[5, 5], [5, 5]] | ['torch.float16', 'torch.float16'] | [exception] test raised TypeError, ref returned normally :: unsupported operand type(s) fo | False |
| decomp | nn.functional.multilabel_soft_margin_loss | dtype_bfloat16 | [[5, 5], [5, 5]] | ['torch.bfloat16', 'torch.bfloat16'] | [exception] test raised TypeError, ref returned normally :: unsupported operand type(s) fo | False |
| decomp | nn.functional.max_pool2d | size1_last | [[1, 2, 3, 1]] | ['torch.float32'] | [value] output[1]: non-float values differ exactly | True |
| decomp | max_pool2d_with_indices_backward | size1_last | [[2, 3, 1]] | ['torch.float32'] | [value] output[0]: compiled err vs fp64 = 1.000e+00 exceeds 4.0x eager err 0.000e+00 | True |
| decomp | nn.functional.softsign | base | [[]] | ['torch.float32'] | [exception] test raised TypeError, ref returned normally :: unsupported operand type(s) fo | False |
| decomp | nn.functional.softsign | nan_inf | [[]] | ['torch.float32'] | [exception] test raised TypeError, ref returned normally :: unsupported operand type(s) fo | False |
| decomp | nn.functional.softsign | huge | [[]] | ['torch.float32'] | [exception] test raised TypeError, ref returned normally :: unsupported operand type(s) fo | False |
| decomp | nn.functional.softsign | tiny | [[]] | ['torch.float32'] | [exception] test raised TypeError, ref returned normally :: unsupported operand type(s) fo | False |
| decomp | nn.functional.softsign | dtype_float16 | [[]] | ['torch.float16'] | [exception] test raised TypeError, ref returned normally :: unsupported operand type(s) fo | False |
| decomp | nn.functional.softsign | dtype_bfloat16 | [[]] | ['torch.bfloat16'] | [exception] test raised TypeError, ref returned normally :: unsupported operand type(s) fo | False |
| decomp | nn.functional.softsign | empty_dim0 | [[0]] | ['torch.float32'] | [exception] test raised TypeError, ref returned normally :: unsupported operand type(s) fo | False |
| decomp | nn.functional.softsign | size1_dim0 | [[1]] | ['torch.float32'] | [exception] test raised TypeError, ref returned normally :: unsupported operand type(s) fo | False |
| decomp | nn.functional.softsign | noncontig | [[20]] | ['torch.float32'] | [exception] test raised TypeError, ref returned normally :: unsupported operand type(s) fo | False |
| decomp | nn.functional.binary_cross_entropy | nan_inf | [[5, 5], [5, 5]] | ['torch.float32', 'torch.float32'] | [exception] ref raised RuntimeError, test returned normally | True |
| decomp | nn.functional.binary_cross_entropy | huge | [[5, 5], [5, 5]] | ['torch.float32', 'torch.float32'] | [exception] ref raised RuntimeError, test returned normally | True |
| decomp | nn.functional.binary_cross_entropy | dtype_float16 | [[5, 5], [5, 5]] | ['torch.float16', 'torch.float16'] | [metadata] output[0].dtype: torch.float16 vs torch.float32 | True |
| meta | nn.functional.binary_cross_entropy | dtype_float16 | [[5, 5], [5, 5]] | ['torch.float16', 'torch.float16'] | output[0] dtype torch.float32 vs real torch.float16 | None |
| decomp | nn.functional.binary_cross_entropy | dtype_bfloat16 | [[5, 5], [5, 5]] | ['torch.bfloat16', 'torch.bfloat16'] | [metadata] output[0].dtype: torch.bfloat16 vs torch.float32 | True |
| meta | nn.functional.binary_cross_entropy | dtype_bfloat16 | [[5, 5], [5, 5]] | ['torch.bfloat16', 'torch.bfloat16'] | output[0] dtype torch.float32 vs real torch.bfloat16 | None |
| decomp | svd_lowrank | base | [[2, 3, 2], [2, 3, 2]] | ['torch.float32', 'torch.float32'] | [exception] test raised TypeError, ref returned normally :: unsupported operand type(s) fo | False |
| decomp | svd_lowrank | size1_dim0 | [[1, 3, 2], [2, 3, 2]] | ['torch.float32', 'torch.float32'] | [exception] test raised TypeError, ref returned normally :: unsupported operand type(s) fo | False |
| decomp | svd_lowrank | empty_last | [[2, 3, 0], [2, 3, 2]] | ['torch.float32', 'torch.float32'] | [exception] exception type differs: RuntimeError vs TypeError :: unsupported operand type( | False |
| decomp | svd_lowrank | size1_last | [[2, 3, 1], [2, 3, 2]] | ['torch.float32', 'torch.float32'] | [exception] exception type differs: RuntimeError vs TypeError :: unsupported operand type( | False |
| decomp | svd_lowrank | noncontig | [[2, 3, 2], [2, 3, 2]] | ['torch.float32', 'torch.float32'] | [exception] test raised TypeError, ref returned normally :: unsupported operand type(s) fo | False |
| decomp | svd_lowrank | nan_inf | [[2, 3, 2], [2, 3, 2]] | ['torch.float32', 'torch.float32'] | [exception] exception type differs: _LinAlgError vs TypeError :: unsupported operand type( | False |
| decomp | svd_lowrank | huge | [[2, 3, 2], [2, 3, 2]] | ['torch.float32', 'torch.float32'] | [exception] test raised TypeError, ref returned normally :: unsupported operand type(s) fo | False |
| decomp | svd_lowrank | tiny | [[2, 3, 2], [2, 3, 2]] | ['torch.float32', 'torch.float32'] | [exception] test raised TypeError, ref returned normally :: unsupported operand type(s) fo | False |
| decomp | svd_lowrank | dtype_float16 | [[2, 3, 2], [2, 3, 2]] | ['torch.float16', 'torch.float16'] | [exception] exception type differs: NotImplementedError vs TypeError :: unsupported operan | False |
| decomp | svd_lowrank | dtype_bfloat16 | [[2, 3, 2], [2, 3, 2]] | ['torch.bfloat16', 'torch.bfloat16'] | [exception] exception type differs: RuntimeError vs TypeError :: unsupported operand type( | False |
| decomp | svd_lowrank | dtype_float16 | [[2, 4, 2], [2, 4, 2]] | ['torch.float16', 'torch.float16'] | [exception] exception type differs: RuntimeError vs TypeError :: unsupported operand type( | False |
| decomp | pca_lowrank | base | [[4, 2], [4, 2]] | ['torch.float32', 'torch.float32'] | [exception] test raised TypeError, ref returned normally :: unsupported operand type(s) fo | False |
| decomp | pca_lowrank | empty_dim0 | [[0, 2], [4, 2]] | ['torch.float32', 'torch.float32'] | [exception] exception type differs: ValueError vs TypeError :: unsupported operand type(s) | False |
| decomp | pca_lowrank | size1_dim0 | [[1, 2], [4, 2]] | ['torch.float32', 'torch.float32'] | [exception] exception type differs: ValueError vs TypeError :: unsupported operand type(s) | False |
| decomp | pca_lowrank | empty_last | [[4, 0], [4, 2]] | ['torch.float32', 'torch.float32'] | [exception] exception type differs: RuntimeError vs TypeError :: unsupported operand type( | False |
| decomp | pca_lowrank | size1_last | [[4, 1], [4, 2]] | ['torch.float32', 'torch.float32'] | [exception] exception type differs: RuntimeError vs TypeError :: unsupported operand type( | False |
| decomp | pca_lowrank | prime_dim0 | [[7, 2], [4, 2]] | ['torch.float32', 'torch.float32'] | [exception] test raised TypeError, ref returned normally :: unsupported operand type(s) fo | False |
| decomp | pca_lowrank | noncontig | [[4, 2], [4, 2]] | ['torch.float32', 'torch.float32'] | [exception] test raised TypeError, ref returned normally :: unsupported operand type(s) fo | False |
| decomp | pca_lowrank | nan_inf | [[4, 2], [4, 2]] | ['torch.float32', 'torch.float32'] | [exception] exception type differs: _LinAlgError vs TypeError :: unsupported operand type( | False |
| decomp | pca_lowrank | huge | [[4, 2], [4, 2]] | ['torch.float32', 'torch.float32'] | [exception] test raised TypeError, ref returned normally :: unsupported operand type(s) fo | False |
| decomp | pca_lowrank | tiny | [[4, 2], [4, 2]] | ['torch.float32', 'torch.float32'] | [exception] test raised TypeError, ref returned normally :: unsupported operand type(s) fo | False |
| decomp | pca_lowrank | dtype_float16 | [[4, 2], [4, 2]] | ['torch.float16', 'torch.float16'] | [exception] exception type differs: NotImplementedError vs TypeError :: unsupported operan | False |
| decomp | pca_lowrank | dtype_bfloat16 | [[4, 2], [4, 2]] | ['torch.bfloat16', 'torch.bfloat16'] | [exception] exception type differs: RuntimeError vs TypeError :: unsupported operand type( | False |
| decomp | index_copy | empty_last | [[5, 0], [5], [5, 5]] | ['torch.float32', 'torch.int64', 'torch.float32'] | [exception] exception type differs: RuntimeError vs IndexError :: index is out of bounds f | False |
| decomp | index_reduce | empty_last | [[5, 0], [10], [5, 10]] | ['torch.float32', 'torch.int64', 'torch.float32'] | [exception] ref raised IndexError, test returned normally | True |
| decomp | index_reduce | size1_last | [[5, 1], [10], [5, 10]] | ['torch.float32', 'torch.int64', 'torch.float32'] | [exception] exception type differs: IndexError vs RuntimeError :: index 1 is out of bounds | True |
| decomp | nn.functional.grid_sample | empty_last | [[2, 3, 5, 0], [2, 5, 5, 2]] | ['torch.float32', 'torch.float32'] | [exception] exception type differs: RuntimeError vs IndexError :: index is out of bounds f | True |
| decomp | grid_sampler_2d | empty_last | [[2, 3, 5, 0], [2, 13, 10, 2]] | ['torch.float32', 'torch.float32'] | [exception] exception type differs: RuntimeError vs IndexError :: index is out of bounds f | True |
| decomp | std | huge | [[5, 5, 5]] | ['torch.float32'] | [value] output[0]: NaN/Inf pattern differs from the float64 truth | True |
| decomp | std | huge | [[5, 5]] | ['torch.float32'] | [value] output[0]: NaN/Inf pattern differs from the float64 truth | True |
| decomp | nn.functional.gaussian_nll_loss | base | [[5, 5], [5, 5], [5, 5]] | ['torch.float32', 'torch.float32', 'torch.float32'] | [exception] test raised TypeError, ref returned normally :: unsupported operand type(s) fo | False |
| decomp | nn.functional.gaussian_nll_loss | noncontig | [[5, 5], [5, 5], [5, 5]] | ['torch.float32', 'torch.float32', 'torch.float32'] | [exception] test raised TypeError, ref returned normally :: unsupported operand type(s) fo | False |
| decomp | nn.functional.gaussian_nll_loss | nan_inf | [[5, 5], [5, 5], [5, 5]] | ['torch.float32', 'torch.float32', 'torch.float32'] | [exception] test raised TypeError, ref returned normally :: unsupported operand type(s) fo | False |
| decomp | nn.functional.gaussian_nll_loss | huge | [[5, 5], [5, 5], [5, 5]] | ['torch.float32', 'torch.float32', 'torch.float32'] | [exception] test raised TypeError, ref returned normally :: unsupported operand type(s) fo | False |
| decomp | nn.functional.gaussian_nll_loss | tiny | [[5, 5], [5, 5], [5, 5]] | ['torch.float32', 'torch.float32', 'torch.float32'] | [exception] test raised TypeError, ref returned normally :: unsupported operand type(s) fo | False |
| decomp | nn.functional.gaussian_nll_loss | dtype_float16 | [[5, 5], [5, 5], [5, 5]] | ['torch.float16', 'torch.float16', 'torch.float16'] | [exception] test raised TypeError, ref returned normally :: unsupported operand type(s) fo | False |
| decomp | nn.functional.gaussian_nll_loss | dtype_bfloat16 | [[5, 5], [5, 5], [5, 5]] | ['torch.bfloat16', 'torch.bfloat16', 'torch.bfloat16'] | [exception] test raised TypeError, ref returned normally :: unsupported operand type(s) fo | False |
| decomp | nn.functional.gaussian_nll_loss | size1_last | [[5, 5, 1], [5, 5, 5], [5, 5, 1]] | ['torch.float32', 'torch.float32', 'torch.float32'] | [exception] test raised TypeError, ref returned normally :: unsupported operand type(s) fo | False |
| decomp | linalg.vector_norm | empty_dim0 | [[0, 5]] | ['torch.float32'] | [exception] test raised RuntimeError, ref returned normally :: linalg.vector_norm cannot c | True |
| meta | linalg.vector_norm | empty_dim0 | [[0, 5]] | ['torch.float32'] | fake-tensor path raised RuntimeError: linalg.vector_norm cannot compute the -inf norm on t | None |
| decomp | linalg.pinv | empty_last | [[0, 3, 0], [0, 50, 1]] | ['torch.float32', 'torch.float32'] | [exception] exception type differs: RuntimeError vs TypeError :: unsupported operand type( | False |
| decomp | bmm | size1_dim0 | [[1, 32, 1], [16, 1, 64]] | ['torch.float32', 'torch.float32'] | [exception] ref raised RuntimeError, test returned normally | False |
