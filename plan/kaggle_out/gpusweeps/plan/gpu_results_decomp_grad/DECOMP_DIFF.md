# Decomposition / meta differential

- operators: 558, samples: 558, input variants: 7923
- variants where at least one decomposition ran: 7319
- decomposition mismatches: 126  (confirmed by torch.compile: 113)
- meta / fake-tensor mismatches: 37 (data-dependent ops that cannot run on fake tensors, not counted: 196)
- wall: 820.0 s

- operators whose child interpreter died (native abort / timeout): nn.functional.ctc_loss (rc -6), nn.functional.pdist (rc -11)

| kind | op | variant | shapes | dtypes | detail | confirmed |
|---|---|---|---|---|---|---|
| decomp | bmm | zero_dim | [[], [10, 10, 5]] | ['torch.float32', 'torch.float32'] | [exception] exception type differs: RuntimeError vs IndexError :: Dimension specified as 1 | False |
| decomp | mv | zero_dim | [[], [10]] | ['torch.float32', 'torch.float32'] | [exception] exception type differs: IndexError vs RuntimeError :: matrix @ vector expected | True |
| decomp | mv | dtype_bool | [[5, 10], [10]] | ['torch.bool', 'torch.float32'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | addcdiv | dtype_int64 | [[], [5, 5, 1], [1, 5]] | ['torch.int64', 'torch.int64', 'torch.int64'] | [exception] ref raised RuntimeError, test returned normally | True |
| decomp | cross | dtype_bool | [[5, 3, 5], [5, 3, 5]] | ['torch.bool', 'torch.float32'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | frac | dtype_int64 | [[20, 20]] | ['torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | stft | empty_last | [[3, 0]] | ['torch.float32'] | [exception] exception type differs: RuntimeError vs IndexError :: index is out of bounds f | False |
| decomp | stft | size1_last | [[3, 1]] | ['torch.float32'] | [exception] exception type differs: RuntimeError vs IndexError :: index -8 is out of bound | False |
| decomp | stft | zero_dim | [[]] | ['torch.float32'] | [exception] exception type differs: RuntimeError vs IndexError :: index -8 is out of bound | False |
| decomp | stft | dtype_bool | [[3, 100]] | ['torch.bool'] | [exception] exception type differs: NotImplementedError vs RuntimeError :: stft(CPUBoolTyp | True |
| decomp | isin | dtype_bool | [[20], [5]] | ['torch.bool', 'torch.float32'] | [exception] ref raised RuntimeError, test returned normally | False |
| decomp | logaddexp | dtype_int64 | [[10, 1, 5], [10, 5]] | ['torch.int64', 'torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | logaddexp2 | dtype_int64 | [[5, 5], [5, 5]] | ['torch.int64', 'torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | std_mean | huge | [[5, 5, 5]] | ['torch.float32'] | [value] output[0]: NaN/Inf pattern differs from the float64 truth | True |
| decomp | std_mean | tiny | [[5, 5, 5]] | ['torch.float32'] | [value] output[2]: compiled err vs fp64 = 1.092e-02 exceeds 4.0x eager err 1.855e-09 | True |
| decomp | std_mean | huge | [[5]] | ['torch.float32'] | [value] output[0]: NaN/Inf pattern differs from the float64 truth | True |
| decomp | std_mean | tiny | [[5]] | ['torch.float32'] | [value] output[2]: compiled err vs fp64 = 1.890e-01 exceeds 4.0x eager err 1.728e-08 | True |
| decomp | softmax | dtype_int64 | [[5, 5]] | ['torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.cross_entropy | empty_last | [[2, 0], [2]] | ['torch.float32', 'torch.int64'] | [exception] exception type differs: IndexError vs RuntimeError :: index 0 is out of bounds | True |
| decomp | nn.functional.cross_entropy | dtype_int64 | [[2, 3], [2]] | ['torch.int64', 'torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | native_batch_norm | dtype_int64 | [[2, 1], [1], [1], [1], [1]] | ['torch.int64', 'torch.int64', 'torch.int64', 'torch.int64', 'torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.adaptive_max_pool2d | dtype_int64 | [[1, 4, 4, 3]] | ['torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.binary_cross_entropy_with_logits | dtype_float16 | [[5, 5], [5, 5]] | ['torch.float16', 'torch.float16'] | [metadata] output[0].dtype: torch.float16 vs torch.float32 | True |
| meta | nn.functional.binary_cross_entropy_with_logits | dtype_float16 | [[5, 5], [5, 5]] | ['torch.float16', 'torch.float16'] | output[0] dtype torch.float32 vs real torch.float16 | None |
| decomp | nn.functional.binary_cross_entropy_with_logits | dtype_bfloat16 | [[5, 5], [5, 5]] | ['torch.bfloat16', 'torch.bfloat16'] | [metadata] output[0].dtype: torch.bfloat16 vs torch.float32 | True |
| meta | nn.functional.binary_cross_entropy_with_logits | dtype_bfloat16 | [[5, 5], [5, 5]] | ['torch.bfloat16', 'torch.bfloat16'] | output[0] dtype torch.float32 vs real torch.bfloat16 | None |
| decomp | nn.functional.group_norm | huge | [[1, 3]] | ['torch.float32'] | [value] output[0]: NaN/Inf present on one side only | False |
| decomp | nn.functional.pad | empty_dim0 | [[0, 3, 3]] | ['torch.float32'] | [exception] ref raised RuntimeError, test returned normally | False |
| decomp | nn.functional.pad | empty_last | [[1, 3, 0]] | ['torch.float32'] | [exception] exception type differs: RuntimeError vs IndexError :: index is out of bounds f | False |
| decomp | nn.functional.pad | size1_last | [[1, 3, 1]] | ['torch.float32'] | [exception] exception type differs: RuntimeError vs IndexError :: index -2 is out of bound | False |
| decomp | nn.functional.pad | dtype_bool | [[1, 3, 3]] | ['torch.bool'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.pad | empty_last | [[1, 3, 0]] | ['torch.float32'] | [exception] exception type differs: RuntimeError vs IndexError :: index is out of bounds f | False |
| decomp | nn.functional.pad | dtype_bool | [[1, 3, 3]] | ['torch.bool'] | [exception] ref raised NotImplementedError, test returned normally | True |
| meta_stride | nn.functional.pad | channels_last | [[4, 2, 5, 5]] | ['torch.float32'] | output[0] stride (60, 30, 2, 1) vs real (60, 1, 4, 2) | None |
| decomp | nn.functional.pad | dtype_bool | [[4, 2, 5, 5]] | ['torch.bool'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.hardswish | dtype_int64 | [[10, 10]] | ['torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.hardswish | dtype_bool | [[10, 10]] | ['torch.bool'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.hardswish | nan_inf | [[10, 10]] | ['torch.float32'] | [value] output[1]: NaN/Inf pattern differs from the float64 truth | True |
| decomp | nn.functional.unfold | dtype_int64 | [[2, 3, 5, 5]] | ['torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| meta | nn.functional.interpolate | empty_dim0 | [[0, 3, 4]] | ['torch.float32'] | fake-tensor path raised TypeError: cond must be a bool, but got <class 'int'> | None |
| decomp | nn.functional.interpolate | empty_last | [[2, 3, 0]] | ['torch.float32'] | [exception] exception type differs: RuntimeError vs ZeroDivisionError :: division by zero | True |
| decomp | nn.functional.interpolate | dtype_int64 | [[2, 3, 4]] | ['torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.interpolate | dtype_bool | [[2, 3, 4]] | ['torch.bool'] | [exception] ref raised NotImplementedError, test returned normally | True |
| meta | nn.functional.interpolate | empty_dim0 | [[0, 3, 4, 5]] | ['torch.float32'] | fake-tensor path raised TypeError: cond must be a bool, but got <class 'int'> | None |
| decomp | nn.functional.interpolate | empty_last | [[2, 3, 4, 0]] | ['torch.float32'] | [exception] exception type differs: RuntimeError vs IndexError :: index is out of bounds f | False |
| decomp | nn.functional.interpolate | dtype_int64 | [[2, 3, 4, 5]] | ['torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.interpolate | dtype_bool | [[2, 3, 4, 5]] | ['torch.bool'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.interpolate | dtype_int64 | [[2, 3, 4]] | ['torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.interpolate | dtype_bool | [[2, 3, 4]] | ['torch.bool'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.soft_margin_loss | dtype_int64 | [[5], [5]] | ['torch.int64', 'torch.int64'] | [exception] ref raised RuntimeError, test returned normally | True |
| meta | nn.functional.upsample_nearest | empty_dim0 | [[0, 3, 4]] | ['torch.float32'] | fake-tensor path raised TypeError: cond must be a bool, but got <class 'int'> | None |
| decomp | nn.functional.upsample_nearest | empty_last | [[2, 3, 0]] | ['torch.float32'] | [exception] exception type differs: RuntimeError vs IndexError :: index is out of bounds f | False |
| decomp | nn.functional.upsample_nearest | dtype_int64 | [[2, 3, 4]] | ['torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.upsample_nearest | dtype_bool | [[2, 3, 4]] | ['torch.bool'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.multi_margin_loss | dtype_int64 | [[5], []] | ['torch.int64', 'torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.multi_margin_loss | nan_inf | [[5], []] | ['torch.float32', 'torch.int64'] | [value] output[0]: NaN/Inf pattern differs from the float64 truth | True |
| decomp | nn.functional.multilabel_margin_loss | dtype_int64 | [[10, 5], [10, 5]] | ['torch.int64', 'torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.multilabel_margin_loss | nan_inf | [[10, 5], [10, 5]] | ['torch.float32', 'torch.int64'] | [value] output[0]: NaN/Inf pattern differs from the float64 truth | True |
| decomp | nn.functional.multilabel_soft_margin_loss | dtype_int64 | [[5, 5], [5, 5]] | ['torch.int64', 'torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.max_pool1d | dtype_int64 | [[1, 2, 6]] | ['torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | max_pool2d_with_indices_backward | size1_last | [[2, 2, 6, 1]] | ['torch.float32'] | [value] output[0]: compiled err vs fp64 = 1.000e+00 exceeds 4.0x eager err 0.000e+00 | True |
| decomp | max_pool2d_with_indices_backward | base | [[2, 2, 3, 6]] | ['torch.float32'] | [exception] test raised AttributeError, ref returned normally :: module 'torch._inductor'  | False |
| decomp | nn.functional.max_pool3d | base | [[2, 3, 6, 5]] | ['torch.float32'] | [exception] test raised AttributeError, ref returned normally :: module 'torch._inductor'  | False |
| decomp | nn.functional.max_unpool1d | dtype_int64 | [[2, 2, 2], [2, 2, 2]] | ['torch.int64', 'torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.max_unpool1d | dtype_bool | [[2, 2, 2], [2, 2, 2]] | ['torch.bool', 'torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.max_unpool1d | dtype_int64 | [[1, 2, 2], [1, 2, 2]] | ['torch.int64', 'torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.max_unpool1d | dtype_bool | [[1, 2, 2], [1, 2, 2]] | ['torch.bool', 'torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| meta_stride | nn.functional.max_unpool2d | base | [[2, 2, 2, 6], [2, 2, 2, 6]] | ['torch.float32', 'torch.int64'] | output[0] stride (36, 18, 6, 1) vs real (36, 1, 12, 2) | None |
| meta_stride | nn.functional.max_unpool2d | noncontig | [[2, 2, 2, 6], [2, 2, 2, 6]] | ['torch.float32', 'torch.int64'] | output[0] stride (36, 18, 6, 1) vs real (36, 1, 12, 2) | None |
| meta_stride | nn.functional.max_unpool2d | channels_last | [[2, 2, 2, 6], [2, 2, 2, 6]] | ['torch.float32', 'torch.int64'] | output[0] stride (36, 18, 6, 1) vs real (36, 1, 12, 2) | None |
| decomp | nn.functional.max_unpool2d | dtype_int64 | [[2, 2, 2, 6], [2, 2, 2, 6]] | ['torch.int64', 'torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.max_unpool2d | dtype_bool | [[2, 2, 2, 6], [2, 2, 2, 6]] | ['torch.bool', 'torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| meta_stride | nn.functional.max_unpool2d | huge | [[2, 2, 2, 6], [2, 2, 2, 6]] | ['torch.float32', 'torch.int64'] | output[0] stride (36, 18, 6, 1) vs real (36, 1, 12, 2) | None |
| meta_stride | nn.functional.max_unpool2d | tiny | [[2, 2, 2, 6], [2, 2, 2, 6]] | ['torch.float32', 'torch.int64'] | output[0] stride (36, 18, 6, 1) vs real (36, 1, 12, 2) | None |
| meta_stride | nn.functional.max_unpool2d | dtype_float16 | [[2, 2, 2, 6], [2, 2, 2, 6]] | ['torch.float16', 'torch.int64'] | output[0] stride (36, 18, 6, 1) vs real (36, 1, 12, 2) | None |
| meta_stride | nn.functional.max_unpool2d | dtype_bfloat16 | [[2, 2, 2, 6], [2, 2, 2, 6]] | ['torch.bfloat16', 'torch.int64'] | output[0] stride (36, 18, 6, 1) vs real (36, 1, 12, 2) | None |
| meta_stride | nn.functional.max_unpool2d | channels_last | [[2, 2, 1, 3], [2, 2, 1, 3]] | ['torch.float32', 'torch.int64'] | output[0] stride (36, 18, 6, 1) vs real (36, 1, 12, 2) | None |
| decomp | nn.functional.max_unpool2d | dtype_int64 | [[2, 2, 1, 3], [2, 2, 1, 3]] | ['torch.int64', 'torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.max_unpool2d | dtype_bool | [[2, 2, 1, 3], [2, 2, 1, 3]] | ['torch.bool', 'torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.max_unpool3d | dtype_int64 | [[2, 2, 2, 4, 3], [2, 2, 2, 4, 3]] | ['torch.int64', 'torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.max_unpool3d | dtype_bool | [[2, 2, 2, 4, 3], [2, 2, 2, 4, 3]] | ['torch.bool', 'torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.max_unpool3d | dtype_int64 | [[1, 2, 2, 2, 2], [1, 2, 2, 2, 2]] | ['torch.int64', 'torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.max_unpool3d | dtype_bool | [[1, 2, 2, 2, 2], [1, 2, 2, 2, 2]] | ['torch.bool', 'torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| meta_stride | nn.functional.glu | channels_last | [[2, 3, 8, 8]] | ['torch.float32'] | output[1] stride (192, 1, 24, 3) vs real (192, 64, 8, 1) | None |
| decomp | nn.functional.prelu | dtype_int64 | [[5], [1]] | ['torch.int64', 'torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.celu | dtype_int64 | [[1, 0, 3]] | ['torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.celu | dtype_bool | [[1, 0, 3]] | ['torch.bool'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.silu | dtype_int64 | [[1, 0, 3]] | ['torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.silu | dtype_bool | [[1, 0, 3]] | ['torch.bool'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.hardsigmoid | dtype_int64 | [[1, 0, 3]] | ['torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.hardsigmoid | dtype_bool | [[1, 0, 3]] | ['torch.bool'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.logsigmoid | dtype_int64 | [[1, 0, 3]] | ['torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.threshold | dtype_bool | [[5, 5]] | ['torch.bool'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.binary_cross_entropy | dtype_int64 | [[5, 5], [5, 5]] | ['torch.int64', 'torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.binary_cross_entropy | dtype_bool | [[5, 5], [5, 5]] | ['torch.bool', 'torch.float32'] | [exception] ref raised RuntimeError, test returned normally | True |
| decomp | nn.functional.binary_cross_entropy | nan_inf | [[5, 5], [5, 5]] | ['torch.float32', 'torch.float32'] | [exception] ref raised RuntimeError, test returned normally | True |
| decomp | nn.functional.binary_cross_entropy | huge | [[5, 5], [5, 5]] | ['torch.float32', 'torch.float32'] | [exception] ref raised RuntimeError, test returned normally | True |
| decomp | nn.functional.hardshrink | dtype_int64 | [[5, 5]] | ['torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.hardtanh | nan_inf | [[20]] | ['torch.float32'] | [value] output[1]: compiled err vs fp64 = 7.500e-01 exceeds 4.0x eager err 0.000e+00 | True |
| decomp | nn.functional.gelu | dtype_int64 | [[10, 10]] | ['torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.gelu | dtype_bool | [[10, 10]] | ['torch.bool'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.relu6 | nan_inf | [[20]] | ['torch.float32'] | [value] output[1]: compiled err vs fp64 = 7.500e-01 exceeds 4.0x eager err 0.000e+00 | True |
| decomp | mvlgamma | dtype_bool | [[5, 5]] | ['torch.bool'] | [exception] ref raised RuntimeError, test returned normally | True |
| decomp | mvlgamma | dtype_bool | [[]] | ['torch.bool'] | [exception] ref raised RuntimeError, test returned normally | True |
| decomp | mvlgamma | dtype_bool | [[]] | ['torch.bool'] | [exception] ref raised RuntimeError, test returned normally | True |
| decomp | round | dtype_int64 | [[20]] | ['torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | round | dtype_bool | [[20]] | ['torch.bool'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | round | dtype_int64 | [[]] | ['torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | round | dtype_bool | [[]] | ['torch.bool'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | round | dtype_int64 | [[1, 0, 3]] | ['torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | round | dtype_bool | [[1, 0, 3]] | ['torch.bool'] | [exception] ref raised NotImplementedError, test returned normally | True |
| meta | unsafe_split | empty_dim0 | [[0, 5, 5]] | ['torch.float32'] | fake-tensor path raised IndexError: list assignment index out of range | None |
| decomp | lerp | dtype_int64 | [[5, 5], [5, 5, 5], [5]] | ['torch.int64', 'torch.int64', 'torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | index_copy | empty_dim0 | [[0], [1], [1]] | ['torch.float32', 'torch.int64', 'torch.float32'] | [exception] exception type differs: RuntimeError vs IndexError :: index is out of bounds f | False |
| decomp | index_add | empty_last | [[5, 0], [5], [5, 5]] | ['torch.float32', 'torch.int64', 'torch.float32'] | [exception] exception type differs: RuntimeError vs IndexError :: index is out of bounds f | False |
| decomp | trace | dtype_bool | [[5, 5]] | ['torch.bool'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | trace | dtype_float16 | [[5, 5]] | ['torch.float16'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | trace | dtype_bfloat16 | [[5, 5]] | ['torch.bfloat16'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.smooth_l1_loss | dtype_int64 | [[5, 5], [5, 5]] | ['torch.int64', 'torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.smooth_l1_loss | nan_inf | [[5, 5], [5, 5]] | ['torch.float32', 'torch.float32'] | [value] output[1]: NaN/Inf pattern differs from the float64 truth | True |
| decomp | log_softmax | dtype_int64 | [[5, 10, 5]] | ['torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | logit | nan_inf | [[]] | ['torch.float32'] | [value] output[1]: NaN/Inf pattern differs from the float64 truth | True |
| decomp | nn.functional.softplus | dtype_int64 | [[20]] | ['torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.mse_loss | dtype_int64 | [[5], [5]] | ['torch.int64', 'torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.mse_loss | dtype_bool | [[5], [5]] | ['torch.bool', 'torch.float32'] | [exception] ref raised RuntimeError, test returned normally | True |
| decomp | nn.functional.grid_sample | empty_last | [[2, 3, 5, 0], [2, 5, 5, 2]] | ['torch.float32', 'torch.float32'] | [exception] exception type differs: RuntimeError vs IndexError :: index is out of bounds f | True |
| decomp | nn.functional.grid_sample | dtype_int64 | [[2, 3, 5, 5], [2, 5, 5, 2]] | ['torch.int64', 'torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | grid_sampler_2d | empty_last | [[2, 3, 5, 0], [2, 13, 10, 2]] | ['torch.float32', 'torch.float32'] | [exception] exception type differs: RuntimeError vs IndexError :: index is out of bounds f | True |
| decomp | grid_sampler_2d | zero_dim | [[], [2, 13, 10, 2]] | ['torch.float32', 'torch.float32'] | [exception] exception type differs: IndexError vs ValueError :: not enough values to unpac | True |
| decomp | grid_sampler_2d | dtype_int64 | [[2, 3, 5, 20], [2, 13, 10, 2]] | ['torch.int64', 'torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | std | huge | [[5, 5, 5]] | ['torch.float32'] | [value] output[0]: NaN/Inf pattern differs from the float64 truth | True |
| decomp | std | tiny | [[5, 5, 5]] | ['torch.float32'] | [value] output[1]: compiled err vs fp64 = 1.083e-02 exceeds 4.0x eager err 1.376e-09 | True |
| decomp | std | huge | [[5]] | ['torch.float32'] | [value] output[0]: NaN/Inf pattern differs from the float64 truth | True |
| decomp | std | tiny | [[5]] | ['torch.float32'] | [value] output[1]: compiled err vs fp64 = 1.890e-01 exceeds 4.0x eager err 1.132e-08 | True |
| decomp | nn.functional.nll_loss | channels_last | [[2, 3, 2, 2], [2, 2, 2]] | ['torch.float32', 'torch.int64'] | [exception] ref raised RuntimeError, test returned normally | True |
| decomp | nn.functional.nll_loss | dtype_int64 | [[2, 3, 2, 2], [2, 2, 2]] | ['torch.int64', 'torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.nll_loss | dtype_bool | [[2, 3, 2, 2], [2, 2, 2]] | ['torch.bool', 'torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.nll_loss | dtype_float16 | [[2, 3, 2, 2], [2, 2, 2]] | ['torch.float16', 'torch.int64'] | [exception] ref raised RuntimeError, test returned normally | True |
| decomp | nn.functional.nll_loss | dtype_bfloat16 | [[2, 3, 2, 2], [2, 2, 2]] | ['torch.bfloat16', 'torch.int64'] | [exception] ref raised RuntimeError, test returned normally | True |
| decomp | nn.functional.huber_loss | dtype_int64 | [[5, 5, 5], [5, 5, 5]] | ['torch.int64', 'torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.huber_loss | dtype_bool | [[5, 5, 5], [5, 5, 5]] | ['torch.bool', 'torch.float32'] | [exception] ref raised RuntimeError, test returned normally | True |
| meta_stride | nn.functional.channel_shuffle | channels_last | [[2, 6, 8, 8]] | ['torch.float32'] | output[0] stride (384, 64, 8, 1) vs real (384, 1, 48, 6) | None |
| meta_stride | fft.fft | dtype_int64 | [[5, 6, 7]] | ['torch.int64'] | output[0] stride (42, 7, 1) vs real (1, 35, 5) | None |
| meta_stride | fft.fft | dtype_bool | [[5, 6, 7]] | ['torch.bool'] | output[0] stride (42, 7, 1) vs real (1, 35, 5) | None |
| meta_stride | fft.hfft | base | [[5, 6, 7]] | ['torch.float32'] | output[1] stride (84, 14, 2) vs real (2, 70, 10) | None |
| meta_stride | fft.hfft | size1_last | [[5, 6, 1]] | ['torch.float32'] | output[1] stride (12, 2, 2) vs real (2, 10, 60) | None |
| meta_stride | fft.hfft | prime_dim0 | [[7, 6, 7]] | ['torch.float32'] | output[1] stride (84, 14, 2) vs real (2, 98, 14) | None |
| meta_stride | fft.hfft | noncontig | [[5, 6, 7]] | ['torch.float32'] | output[1] stride (84, 14, 2) vs real (2, 70, 10) | None |
| meta_stride | fft.hfft | prime_all | [[7, 11, 13]] | ['torch.float32'] | output[1] stride (286, 26, 2) vs real (2, 182, 14) | None |
| meta_stride | fft.hfft | nan_inf | [[5, 6, 7]] | ['torch.float32'] | output[1] stride (84, 14, 2) vs real (2, 70, 10) | None |
| meta_stride | fft.hfft | huge | [[5, 6, 7]] | ['torch.float32'] | output[1] stride (84, 14, 2) vs real (2, 70, 10) | None |
| meta_stride | fft.hfft | tiny | [[5, 6, 7]] | ['torch.float32'] | output[1] stride (84, 14, 2) vs real (2, 70, 10) | None |
| meta_stride | fft.hfftn | base | [[5, 6, 7]] | ['torch.float32'] | output[1] stride (84, 14, 2) vs real (2, 70, 10) | None |
| meta_stride | fft.hfftn | size1_last | [[5, 6, 1]] | ['torch.float32'] | output[1] stride (12, 2, 2) vs real (2, 10, 60) | None |
| meta_stride | fft.hfftn | prime_dim0 | [[7, 6, 7]] | ['torch.float32'] | output[1] stride (84, 14, 2) vs real (2, 98, 14) | None |
| meta_stride | fft.hfftn | noncontig | [[5, 6, 7]] | ['torch.float32'] | output[1] stride (84, 14, 2) vs real (2, 70, 10) | None |
| meta_stride | fft.hfftn | prime_all | [[7, 11, 13]] | ['torch.float32'] | output[1] stride (286, 26, 2) vs real (2, 182, 14) | None |
| meta_stride | fft.hfftn | nan_inf | [[5, 6, 7]] | ['torch.float32'] | output[1] stride (84, 14, 2) vs real (2, 70, 10) | None |
| meta_stride | fft.hfftn | huge | [[5, 6, 7]] | ['torch.float32'] | output[1] stride (84, 14, 2) vs real (2, 70, 10) | None |
| meta_stride | fft.hfftn | tiny | [[5, 6, 7]] | ['torch.float32'] | output[1] stride (84, 14, 2) vs real (2, 70, 10) | None |
| meta_stride | fft.rfft | dtype_int64 | [[5, 6, 7]] | ['torch.int64'] | output[0] stride (42, 7, 1) vs real (1, 21, 3) | None |
| meta_stride | fft.rfft | dtype_bool | [[5, 6, 7]] | ['torch.bool'] | output[0] stride (42, 7, 1) vs real (1, 21, 3) | None |
| decomp | linalg.cross | dtype_bool | [[5, 3, 5], [5, 3, 5]] | ['torch.bool', 'torch.float32'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | masked.softmax | dtype_int64 | [[5, 10, 5]] | ['torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | masked.softmin | dtype_int64 | [[5, 10, 5]] | ['torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | masked.logaddexp | dtype_int64 | [[5, 5], [5, 5]] | ['torch.int64', 'torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
