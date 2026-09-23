# Decomposition / meta differential

- operators: 562, samples: 562, input variants: 7945
- variants where at least one decomposition ran: 7334
- decomposition mismatches: 125  (confirmed by torch.compile: 112)
- meta / fake-tensor mismatches: 5 (data-dependent ops that cannot run on fake tensors, not counted: 123)
- wall: 721.0 s

- operators whose child interpreter died (native abort / timeout): nn.functional.pdist (rc 3221225620)

| kind | op | variant | shapes | dtypes | detail | confirmed |
|---|---|---|---|---|---|---|
| decomp | bmm | zero_dim | [[], [10, 10, 5]] | ['torch.float32', 'torch.float32'] | [exception] exception type differs: RuntimeError vs IndexError :: tuple index out of range | False |
| decomp | mv | zero_dim | [[], [10]] | ['torch.float32', 'torch.float32'] | [exception] exception type differs: IndexError vs RuntimeError :: matrix @ vector expected | True |
| decomp | mv | dtype_bool | [[5, 10], [10]] | ['torch.bool', 'torch.float32'] | [exception] ref raised RuntimeError, test returned normally | True |
| decomp | bmm | zero_dim | [[], [2, 1, 32]] | ['torch.float32', 'torch.float32'] | [exception] exception type differs: RuntimeError vs IndexError :: tuple index out of range | False |
| decomp | cross | dtype_bool | [[5, 3, 5], [5, 3, 5]] | ['torch.bool', 'torch.float32'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | frac | dtype_int64 | [[20, 20]] | ['torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | isin | dtype_bool | [[20], [5]] | ['torch.bool', 'torch.float32'] | [exception] ref raised RuntimeError, test returned normally | False |
| decomp | logaddexp | dtype_int64 | [[10, 1, 5], [1, 10, 5]] | ['torch.int64', 'torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | logaddexp2 | dtype_int64 | [[5, 5], [5, 5]] | ['torch.int64', 'torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | softmax | dtype_int64 | [[5]] | ['torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.softmin | dtype_int64 | [[5]] | ['torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.cross_entropy | empty_last | [[2, 0], [2, 3]] | ['torch.float32', 'torch.float32'] | [exception] exception type differs: RuntimeError vs AssertionError :: 0D or 1D target tens | True |
| decomp | nn.functional.cross_entropy | size1_last | [[2, 1], [2, 3]] | ['torch.float32', 'torch.float32'] | [exception] exception type differs: RuntimeError vs AssertionError :: 0D or 1D target tens | True |
| decomp | nn.functional.linear_cross_entropy | dtype_int64 | [[8, 3], [4, 3], [8]] | ['torch.int64', 'torch.int64', 'torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.linear_cross_entropy | dtype_int64 | [[4, 2], [2, 1, 2, 1, 2], [4, 1, 2, 1]] | ['torch.int64', 'torch.int64', 'torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | False |
| decomp | nn.functional.linear_cross_entropy | dtype_float16 | [[4, 2], [2, 1, 2, 1, 2], [4, 1, 2, 1]] | ['torch.float16', 'torch.float16', 'torch.int64'] | [exception] ref raised RuntimeError, test returned normally | False |
| decomp | nn.functional.linear_cross_entropy | dtype_bfloat16 | [[4, 2], [2, 1, 2, 1, 2], [4, 1, 2, 1]] | ['torch.bfloat16', 'torch.bfloat16', 'torch.int64'] | [exception] ref raised RuntimeError, test returned normally | False |
| decomp | nn.functional.linear_cross_entropy | dtype_int64 | [[8], [8, 8], []] | ['torch.int64', 'torch.int64', 'torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.linear_cross_entropy | dtype_int64 | [[4, 3], [2, 3, 3], [4, 3]] | ['torch.int64', 'torch.int64', 'torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | False |
| decomp | nn.functional.linear_cross_entropy | base | [[8, 8], [8, 8], [8]] | ['torch.float32', 'torch.float32', 'torch.int64'] | [exception] test raised TypeError, ref returned normally :: mm() got an unexpected keyword | False |
| decomp | nn.functional.linear_cross_entropy | size1_dim0 | [[1, 8], [8, 8], [8]] | ['torch.float32', 'torch.float32', 'torch.int64'] | [exception] test raised TypeError, ref returned normally :: mm() got an unexpected keyword | False |
| decomp | nn.functional.linear_cross_entropy | noncontig | [[8, 8], [8, 8], [8]] | ['torch.float32', 'torch.float32', 'torch.int64'] | [exception] test raised TypeError, ref returned normally :: mm() got an unexpected keyword | False |
| decomp | nn.functional.linear_cross_entropy | nan_inf | [[8, 8], [8, 8], [8]] | ['torch.float32', 'torch.float32', 'torch.int64'] | [exception] test raised TypeError, ref returned normally :: mm() got an unexpected keyword | False |
| decomp | nn.functional.linear_cross_entropy | huge | [[8, 8], [8, 8], [8]] | ['torch.float32', 'torch.float32', 'torch.int64'] | [exception] test raised TypeError, ref returned normally :: mm() got an unexpected keyword | False |
| decomp | nn.functional.linear_cross_entropy | tiny | [[8, 8], [8, 8], [8]] | ['torch.float32', 'torch.float32', 'torch.int64'] | [exception] test raised TypeError, ref returned normally :: mm() got an unexpected keyword | False |
| decomp | nn.functional.linear_cross_entropy | dtype_float16 | [[8, 8], [8, 8], [8]] | ['torch.float16', 'torch.float16', 'torch.int64'] | [exception] test raised TypeError, ref returned normally :: mm() got an unexpected keyword | False |
| decomp | nn.functional.linear_cross_entropy | dtype_bfloat16 | [[8, 8], [8, 8], [8]] | ['torch.bfloat16', 'torch.bfloat16', 'torch.int64'] | [exception] test raised TypeError, ref returned normally :: mm() got an unexpected keyword | False |
| decomp | native_batch_norm | dtype_int64 | [[2, 1], [1], [1], [1], [1]] | ['torch.int64', 'torch.int64', 'torch.int64', 'torch.int64', 'torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.pad | empty_last | [[0, 3, 3, 0]] | ['torch.float32'] | [exception] exception type differs: RuntimeError vs IndexError :: index is out of bounds f | False |
| decomp | nn.functional.pad | size1_last | [[0, 3, 3, 1]] | ['torch.float32'] | [exception] ref raised RuntimeError, test returned normally | False |
| decomp | nn.functional.pad | dtype_bool | [[0, 3, 3, 3]] | ['torch.bool'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.pad | empty_last | [[1, 3, 3, 3, 0]] | ['torch.float32'] | [exception] exception type differs: RuntimeError vs IndexError :: index is out of bounds f | False |
| decomp | nn.functional.pad | dtype_bool | [[1, 3, 3, 3, 3]] | ['torch.bool'] | [exception] ref raised NotImplementedError, test returned normally | True |
| meta_stride | nn.functional.pad | channels_last | [[4, 2, 5, 5]] | ['torch.float32'] | output[1] stride (50, 25, 5, 1) vs real (50, 1, 10, 2) | None |
| decomp | nn.functional.pad | dtype_bool | [[4, 2, 5, 5]] | ['torch.bool'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.hardswish | dtype_int64 | [[10, 10]] | ['torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.hardswish | dtype_bool | [[10, 10]] | ['torch.bool'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.hardswish | nan_inf | [[10, 10]] | ['torch.float32'] | [value] output[1]: NaN/Inf pattern differs from the float64 truth | True |
| decomp | nn.functional.unfold | dtype_int64 | [[2, 3, 5, 5]] | ['torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| meta | nn.functional.interpolate | empty_dim0 | [[0, 3, 4]] | ['torch.float32'] | fake-tensor path raised TypeError: cond must be a bool, but got <class 'int'> | None |
| decomp | nn.functional.interpolate | empty_last | [[2, 3, 0]] | ['torch.float32'] | [exception] exception type differs: RuntimeError vs IndexError :: index is out of bounds f | False |
| decomp | nn.functional.interpolate | dtype_int64 | [[2, 3, 4]] | ['torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.interpolate | dtype_bool | [[2, 3, 4]] | ['torch.bool'] | [exception] ref raised NotImplementedError, test returned normally | True |
| meta | nn.functional.interpolate | empty_dim0 | [[0, 3, 4, 4]] | ['torch.float32'] | fake-tensor path raised TypeError: cond must be a bool, but got <class 'int'> | None |
| decomp | nn.functional.interpolate | empty_last | [[2, 3, 4, 0]] | ['torch.float32'] | [exception] exception type differs: RuntimeError vs ZeroDivisionError :: division by zero | True |
| decomp | nn.functional.interpolate | dtype_int64 | [[2, 3, 4, 4]] | ['torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.interpolate | dtype_bool | [[2, 3, 4, 4]] | ['torch.bool'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.interpolate | empty_last | [[2, 3, 0]] | ['torch.float32'] | [exception] exception type differs: RuntimeError vs IndexError :: index is out of bounds f | True |
| decomp | nn.functional.interpolate | dtype_int64 | [[2, 3, 4]] | ['torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.interpolate | dtype_bool | [[2, 3, 4]] | ['torch.bool'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.soft_margin_loss | dtype_int64 | [[5, 5, 5], [5, 5, 5]] | ['torch.int64', 'torch.int64'] | [exception] ref raised RuntimeError, test returned normally | True |
| meta | nn.functional.upsample_nearest | empty_dim0 | [[0, 3, 4]] | ['torch.float32'] | fake-tensor path raised TypeError: cond must be a bool, but got <class 'int'> | None |
| decomp | nn.functional.upsample_nearest | empty_last | [[2, 3, 0]] | ['torch.float32'] | [exception] exception type differs: RuntimeError vs ZeroDivisionError :: division by zero | True |
| decomp | nn.functional.upsample_nearest | dtype_int64 | [[2, 3, 4]] | ['torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.upsample_nearest | dtype_bool | [[2, 3, 4]] | ['torch.bool'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.multi_margin_loss | dtype_int64 | [[10, 5], [10]] | ['torch.int64', 'torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.multilabel_margin_loss | dtype_int64 | [[5], [5]] | ['torch.int64', 'torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.multilabel_margin_loss | nan_inf | [[5], [5]] | ['torch.float32', 'torch.int64'] | [value] output[0]: NaN/Inf pattern differs from the float64 truth | True |
| decomp | nn.functional.multilabel_soft_margin_loss | dtype_int64 | [[5, 5], [5, 5]] | ['torch.int64', 'torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.max_pool1d | dtype_int64 | [[2, 2, 6]] | ['torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | max_pool2d_with_indices_backward | base | [[1, 2, 3, 6]] | ['torch.float32'] | [exception] test raised AttributeError, ref returned normally :: module 'torch._inductor'  | False |
| decomp | max_pool2d_with_indices_backward | size1_last | [[1, 2, 3, 1]] | ['torch.float32'] | [value] output[0]: compiled err vs fp64 = 1.000e+00 exceeds 4.0x eager err 0.000e+00 | True |
| decomp | max_pool2d_with_indices_backward | dtype_int64 | [[1, 2, 3, 6]] | ['torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.max_pool3d | base | [[1, 2, 6, 6, 5]] | ['torch.float32'] | [exception] test raised AttributeError, ref returned normally :: module 'torch._inductor'  | False |
| decomp | nn.functional.max_unpool1d | dtype_int64 | [[1, 2, 2], [1, 2, 2]] | ['torch.int64', 'torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.max_unpool1d | dtype_bool | [[1, 2, 2], [1, 2, 2]] | ['torch.bool', 'torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.max_unpool1d | dtype_int64 | [[1, 2, 2], [1, 2, 2]] | ['torch.int64', 'torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.max_unpool1d | dtype_bool | [[1, 2, 2], [1, 2, 2]] | ['torch.bool', 'torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.max_unpool2d | dtype_int64 | [[1, 2, 2, 7], [1, 2, 2, 7]] | ['torch.int64', 'torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.max_unpool2d | dtype_bool | [[1, 2, 2, 7], [1, 2, 2, 7]] | ['torch.bool', 'torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.max_unpool2d | dtype_int64 | [[1, 2, 1, 2], [1, 2, 1, 2]] | ['torch.int64', 'torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.max_unpool2d | dtype_bool | [[1, 2, 1, 2], [1, 2, 1, 2]] | ['torch.bool', 'torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.max_unpool3d | dtype_int64 | [[1, 2, 2, 4, 2], [1, 2, 2, 4, 2]] | ['torch.int64', 'torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.max_unpool3d | dtype_bool | [[1, 2, 2, 4, 2], [1, 2, 2, 4, 2]] | ['torch.bool', 'torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.max_unpool3d | dtype_int64 | [[1, 2, 2, 3, 1], [1, 2, 2, 3, 1]] | ['torch.int64', 'torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.max_unpool3d | dtype_bool | [[1, 2, 2, 3, 1], [1, 2, 2, 3, 1]] | ['torch.bool', 'torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.linear | dtype_bool | [[8], [8, 8], [8]] | ['torch.bool', 'torch.float32', 'torch.float32'] | [exception] ref raised RuntimeError, test returned normally | True |
| decomp | nn.functional.prelu | dtype_int64 | [[], []] | ['torch.int64', 'torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.celu | dtype_int64 | [[20]] | ['torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.celu | dtype_bool | [[20]] | ['torch.bool'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.silu | dtype_int64 | [[]] | ['torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.hardsigmoid | dtype_int64 | [[20]] | ['torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.hardsigmoid | dtype_bool | [[20]] | ['torch.bool'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.logsigmoid | dtype_int64 | [[1, 0, 3]] | ['torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.threshold | dtype_bool | [[5, 5, 5]] | ['torch.bool'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.binary_cross_entropy | dtype_int64 | [[5, 5], [5, 5]] | ['torch.int64', 'torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.binary_cross_entropy | dtype_bool | [[5, 5], [5, 5]] | ['torch.bool', 'torch.float32'] | [exception] ref raised RuntimeError, test returned normally | True |
| decomp | nn.functional.binary_cross_entropy | nan_inf | [[5, 5], [5, 5]] | ['torch.float32', 'torch.float32'] | [exception] ref raised RuntimeError, test returned normally | True |
| decomp | nn.functional.binary_cross_entropy | huge | [[5, 5], [5, 5]] | ['torch.float32', 'torch.float32'] | [exception] ref raised RuntimeError, test returned normally | True |
| decomp | nn.functional.hardshrink | dtype_int64 | [[5, 5]] | ['torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.hardtanh | nan_inf | [[5, 5]] | ['torch.float32'] | [value] output[1]: compiled err vs fp64 = 7.500e-01 exceeds 4.0x eager err 0.000e+00 | True |
| decomp | nn.functional.gelu | dtype_int64 | [[10, 10]] | ['torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.gelu | dtype_bool | [[10, 10]] | ['torch.bool'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | mm | zero_dim | [[], [10, 5]] | ['torch.float32', 'torch.float32'] | [exception] exception type differs: RuntimeError vs IndexError :: Dimension specified as - | False |
| decomp | mvlgamma | dtype_bool | [[5, 5]] | ['torch.bool'] | [exception] ref raised RuntimeError, test returned normally | True |
| decomp | mvlgamma | dtype_bool | [[]] | ['torch.bool'] | [exception] ref raised RuntimeError, test returned normally | True |
| decomp | mvlgamma | dtype_bool | [[5, 5]] | ['torch.bool'] | [exception] ref raised RuntimeError, test returned normally | True |
| decomp | mvlgamma | dtype_bool | [[5, 5]] | ['torch.bool'] | [exception] ref raised RuntimeError, test returned normally | True |
| decomp | mvlgamma | dtype_bool | [[]] | ['torch.bool'] | [exception] ref raised RuntimeError, test returned normally | True |
| decomp | mvlgamma | dtype_bool | [[5, 5]] | ['torch.bool'] | [exception] ref raised RuntimeError, test returned normally | True |
| decomp | round | dtype_int64 | [[]] | ['torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | round | dtype_bool | [[]] | ['torch.bool'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | round | dtype_int64 | [[20]] | ['torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | round | dtype_bool | [[20]] | ['torch.bool'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | round | dtype_int64 | [[]] | ['torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | round | dtype_bool | [[]] | ['torch.bool'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | lerp | dtype_bool | [[5, 5], [5]] | ['torch.bool', 'torch.float32'] | [exception] exception type differs: RuntimeError vs NotImplementedError :: Subtraction, th | False |
| decomp | index_copy | empty_dim0 | [[0], [1], [1]] | ['torch.float32', 'torch.int64', 'torch.float32'] | [exception] exception type differs: RuntimeError vs IndexError :: index is out of bounds f | False |
| decomp | trace | dtype_bool | [[7, 5]] | ['torch.bool'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.smooth_l1_loss | dtype_int64 | [[5, 5], [5, 5]] | ['torch.int64', 'torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.smooth_l1_loss | nan_inf | [[5, 5], [5, 5]] | ['torch.float32', 'torch.float32'] | [value] output[1]: NaN/Inf pattern differs from the float64 truth | True |
| decomp | log_softmax | dtype_int64 | [[5, 5]] | ['torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | logit | nan_inf | [[]] | ['torch.float32'] | [value] output[1]: NaN/Inf pattern differs from the float64 truth | True |
| decomp | nn.functional.softplus | dtype_int64 | [[1, 0, 3]] | ['torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.mse_loss | dtype_int64 | [[5], [5]] | ['torch.int64', 'torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.grid_sample | empty_last | [[2, 3, 5, 0], [2, 5, 5, 2]] | ['torch.float32', 'torch.float32'] | [exception] exception type differs: RuntimeError vs IndexError :: index is out of bounds f | True |
| decomp | nn.functional.grid_sample | dtype_int64 | [[2, 3, 5, 5], [2, 5, 5, 2]] | ['torch.int64', 'torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | grid_sampler_2d | empty_last | [[2, 3, 5, 0], [2, 13, 10, 2]] | ['torch.float32', 'torch.float32'] | [exception] exception type differs: RuntimeError vs IndexError :: index is out of bounds f | True |
| decomp | grid_sampler_2d | zero_dim | [[], [2, 13, 10, 2]] | ['torch.float32', 'torch.float32'] | [exception] exception type differs: IndexError vs ValueError :: not enough values to unpac | True |
| decomp | grid_sampler_2d | dtype_int64 | [[2, 3, 5, 20], [2, 13, 10, 2]] | ['torch.int64', 'torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | std | huge | [[5, 5, 5]] | ['torch.float32'] | [value] output[0]: NaN/Inf pattern differs from the float64 truth | True |
| decomp | std | tiny | [[5, 5, 5]] | ['torch.float32'] | [value] output[1]: compiled err vs fp64 = 1.087e-02 exceeds 4.0x eager err 9.739e-10 | True |
| decomp | std | huge | [[5, 5]] | ['torch.float32'] | [value] output[0]: NaN/Inf pattern differs from the float64 truth | True |
| decomp | std | tiny | [[5, 5]] | ['torch.float32'] | [value] output[1]: compiled err vs fp64 = 5.806e-02 exceeds 4.0x eager err 3.939e-09 | True |
| decomp | nn.functional.nll_loss | empty_dim0 | [[0], []] | ['torch.float32', 'torch.int64'] | [exception] exception type differs: RuntimeError vs AssertionError :: weight tensor should | True |
| decomp | nn.functional.nll_loss | size1_dim0 | [[1], []] | ['torch.float32', 'torch.int64'] | [exception] exception type differs: RuntimeError vs AssertionError :: weight tensor should | True |
| decomp | nn.functional.nll_loss | dtype_int64 | [[3], []] | ['torch.int64', 'torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.nll_loss | dtype_bool | [[3], []] | ['torch.bool', 'torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.nll_loss | dtype_float16 | [[3], []] | ['torch.float16', 'torch.int64'] | [exception] ref raised RuntimeError, test returned normally | True |
| decomp | nn.functional.nll_loss | dtype_bfloat16 | [[3], []] | ['torch.bfloat16', 'torch.int64'] | [exception] ref raised RuntimeError, test returned normally | True |
| decomp | nn.functional.huber_loss | dtype_int64 | [[5, 5, 5], [5, 5, 5]] | ['torch.int64', 'torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.huber_loss | dtype_bool | [[5, 5, 5], [5, 5, 5]] | ['torch.bool', 'torch.float32'] | [exception] ref raised RuntimeError, test returned normally | True |
| decomp | nn.functional.pixel_shuffle | empty_dim0 | [[0, 9, 2, 2]] | ['torch.float32'] | [exception] ref raised RuntimeError, test returned normally | True |
| decomp | nn.functional.pixel_shuffle | empty_last | [[1, 9, 2, 0]] | ['torch.float32'] | [exception] ref raised RuntimeError, test returned normally | True |
| decomp | nn.functional.pixel_unshuffle | empty_dim0 | [[0, 1, 6, 6]] | ['torch.float32'] | [exception] ref raised RuntimeError, test returned normally | True |
| decomp | nn.functional.pixel_unshuffle | empty_last | [[1, 1, 6, 0]] | ['torch.float32'] | [exception] ref raised RuntimeError, test returned normally | True |
| meta_stride | nn.functional.channel_shuffle | channels_last | [[1, 4, 10, 10]] | ['torch.float32'] | output[0] stride (400, 100, 10, 1) vs real (400, 1, 40, 4) | None |
| decomp | linalg.cross | dtype_bool | [[1, 3], [5, 3]] | ['torch.bool', 'torch.float32'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | bmm | zero_dim | [[], [10, 10, 5]] | ['torch.float32', 'torch.float32'] | [exception] exception type differs: RuntimeError vs IndexError :: tuple index out of range | False |
| decomp | masked.softmax | dtype_int64 | [[5, 10, 5]] | ['torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | masked.log_softmax | dtype_int64 | [[5, 10, 5]] | ['torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | masked.logaddexp | dtype_int64 | [[5], [5]] | ['torch.int64', 'torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | bmm | zero_dim | [[], [16, 1, 64]] | ['torch.float32', 'torch.float32'] | [exception] exception type differs: RuntimeError vs IndexError :: tuple index out of range | False |
