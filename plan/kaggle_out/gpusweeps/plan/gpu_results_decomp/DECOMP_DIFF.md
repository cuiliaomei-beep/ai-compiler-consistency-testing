# Decomposition / meta differential

- operators: 553, samples: 1065, input variants: 15145
- variants where at least one decomposition ran: 5585
- decomposition mismatches: 124  (confirmed by torch.compile: 122)
- meta / fake-tensor mismatches: 85 (data-dependent ops that cannot run on fake tensors, not counted: 234)
- wall: 549.9 s

- operators whose child interpreter died (native abort / timeout): lu_unpack (rc -11)

| kind | op | variant | shapes | dtypes | detail | confirmed |
|---|---|---|---|---|---|---|
| decomp | mv | dtype_bool | [[5, 10], [10]] | ['torch.bool', 'torch.float32'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | addcdiv | dtype_int64 | [[5, 5], [], []] | ['torch.int64', 'torch.int64', 'torch.int64'] | [exception] ref raised RuntimeError, test returned normally | False |
| decomp | cross | dtype_bool | [[5, 3, 5], [5, 3, 5]] | ['torch.bool', 'torch.float32'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | frac | dtype_int64 | [[20, 20]] | ['torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | stft | dtype_bool | [[10]] | ['torch.bool'] | [exception] exception type differs: NotImplementedError vs RuntimeError :: stft(CPUBoolTyp | True |
| decomp | stft | dtype_bool | [[100]] | ['torch.bool'] | [exception] exception type differs: NotImplementedError vs RuntimeError :: stft(CPUBoolTyp | True |
| decomp | isin | dtype_bool | [[20], [5]] | ['torch.bool', 'torch.float32'] | [exception] ref raised RuntimeError, test returned normally | False |
| decomp | logaddexp | dtype_int64 | [[5, 10, 5], [10, 5]] | ['torch.int64', 'torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | logaddexp2 | dtype_int64 | [[5, 5], [5, 5]] | ['torch.int64', 'torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | std_mean | huge | [[5, 5, 5]] | ['torch.float32'] | [value] output[0]: NaN/Inf pattern differs from the float64 truth | True |
| decomp | std_mean | huge | [[5, 5]] | ['torch.float32'] | [value] output[0]: NaN/Inf pattern differs from the float64 truth | True |
| decomp | heaviside | dtype_bool | [[5], []] | ['torch.bool', 'torch.float32'] | [exception] ref raised RuntimeError, test returned normally | True |
| decomp | softmax | dtype_int64 | [[]] | ['torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.softmin | dtype_int64 | [[5, 5]] | ['torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.cross_entropy | dtype_int64 | [[2, 3, 1, 2, 3], [2, 1, 2, 3]] | ['torch.int64', 'torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.cross_entropy | empty_last | [[2, 0], [2]] | ['torch.float32', 'torch.int64'] | [exception] exception type differs: RuntimeError vs AssertionError :: weight tensor should | True |
| decomp | nn.functional.cross_entropy | size1_last | [[2, 1], [2]] | ['torch.float32', 'torch.int64'] | [exception] exception type differs: RuntimeError vs AssertionError :: weight tensor should | True |
| decomp | nn.functional.cross_entropy | dtype_float16 | [[2, 3], [2]] | ['torch.float16', 'torch.int64'] | [exception] ref raised RuntimeError, test returned normally | True |
| decomp | nn.functional.cross_entropy | dtype_bfloat16 | [[2, 3], [2]] | ['torch.bfloat16', 'torch.int64'] | [exception] ref raised RuntimeError, test returned normally | True |
| decomp | native_batch_norm | zero_dim | [[], [1], [1], [1], [1]] | ['torch.float32', 'torch.float32', 'torch.float32', 'torch.float32', 'torch.float32'] | [exception] ref raised RuntimeError, test returned normally | True |
| decomp | native_batch_norm | dtype_int64 | [[2, 1], [1], [1], [1], [1]] | ['torch.int64', 'torch.int64', 'torch.int64', 'torch.int64', 'torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | native_batch_norm | empty_dim0 | [[0, 1], [1], [1], [1], [1]] | ['torch.float32', 'torch.float32', 'torch.float32', 'torch.float32', 'torch.float32'] | [exception] ref raised RuntimeError, test returned normally | True |
| meta | native_batch_norm | size1_dim0 | [[1, 1], [1], [1], [1], [1]] | ['torch.float32', 'torch.float32', 'torch.float32', 'torch.float32', 'torch.float32'] | fake-tensor path raised ZeroDivisionError: float division by zero | None |
| decomp | nn.functional.adaptive_max_pool1d | dtype_int64 | [[4, 4]] | ['torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.binary_cross_entropy_with_logits | dtype_float16 | [[5, 5], [5, 5]] | ['torch.float16', 'torch.float16'] | [metadata] output[0].dtype: torch.float16 vs torch.float32 | True |
| meta | nn.functional.binary_cross_entropy_with_logits | dtype_float16 | [[5, 5], [5, 5]] | ['torch.float16', 'torch.float16'] | output[0] dtype torch.float32 vs real torch.float16 | None |
| decomp | nn.functional.binary_cross_entropy_with_logits | dtype_bfloat16 | [[5, 5], [5, 5]] | ['torch.bfloat16', 'torch.bfloat16'] | [metadata] output[0].dtype: torch.bfloat16 vs torch.float32 | True |
| meta | nn.functional.binary_cross_entropy_with_logits | dtype_bfloat16 | [[5, 5], [5, 5]] | ['torch.bfloat16', 'torch.bfloat16'] | output[0] dtype torch.float32 vs real torch.bfloat16 | None |
| meta_stride | nn.functional.pad | channels_last | [[3, 3, 5, 5]] | ['torch.float32'] | output[0] stride (126, 42, 7, 1) vs real (126, 1, 21, 3) | None |
| decomp | nn.functional.pad | dtype_bool | [[3, 3, 5, 5]] | ['torch.bool'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.pad | size1_last | [[0, 3, 1]] | ['torch.float32'] | [exception] ref raised RuntimeError, test returned normally | False |
| decomp | nn.functional.pad | dtype_bool | [[1, 3, 3]] | ['torch.bool'] | [exception] ref raised NotImplementedError, test returned normally | True |
| meta_stride | nn.functional.pad | channels_last | [[5, 3, 4, 4]] | ['torch.float32'] | output[0] stride (60, 20, 5, 1) vs real (60, 1, 15, 3) | None |
| decomp | nn.functional.pad | dtype_bool | [[5, 3, 4, 4]] | ['torch.bool'] | [exception] ref raised NotImplementedError, test returned normally | True |
| meta_stride | nn.functional.pad | channels_last | [[2, 6, 5, 5]] | ['torch.float32'] | output[0] stride (72, 12, 12, 1) vs real (72, 1, 72, 6) | None |
| decomp | nn.functional.hardswish | dtype_int64 | [[10, 10]] | ['torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.hardswish | dtype_bool | [[10, 10]] | ['torch.bool'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.unfold | dtype_int64 | [[0, 1, 5, 5]] | ['torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| meta | nn.functional.interpolate | empty_dim0 | [[0, 3, 4, 4, 4]] | ['torch.float32'] | fake-tensor path raised TypeError: cond must be a bool, but got <class 'int'> | None |
| decomp | nn.functional.interpolate | dtype_int64 | [[2, 3, 4, 4, 4]] | ['torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.interpolate | dtype_bool | [[2, 3, 4, 4, 4]] | ['torch.bool'] | [exception] ref raised NotImplementedError, test returned normally | True |
| meta | nn.functional.interpolate | empty_dim0 | [[0, 3, 4, 4, 4]] | ['torch.float32'] | fake-tensor path raised TypeError: cond must be a bool, but got <class 'int'> | None |
| decomp | nn.functional.interpolate | dtype_int64 | [[2, 3, 4, 4, 4]] | ['torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.interpolate | dtype_bool | [[2, 3, 4, 4, 4]] | ['torch.bool'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.interpolate | empty_last | [[2, 3, 0]] | ['torch.float32'] | [exception] ref raised RuntimeError, test returned normally | True |
| decomp | nn.functional.interpolate | size1_last | [[2, 3, 1]] | ['torch.float32'] | [exception] ref raised RuntimeError, test returned normally | True |
| decomp | nn.functional.interpolate | dtype_int64 | [[2, 3, 4]] | ['torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.interpolate | dtype_bool | [[2, 3, 4]] | ['torch.bool'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.soft_margin_loss | size1_dim0 | [[1, 5], [5, 5]] | ['torch.float32', 'torch.float32'] | [exception] ref raised RuntimeError, test returned normally | True |
| decomp | nn.functional.soft_margin_loss | size1_last | [[5, 1], [5, 5]] | ['torch.float32', 'torch.float32'] | [exception] ref raised RuntimeError, test returned normally | True |
| decomp | nn.functional.soft_margin_loss | zero_dim | [[], [5, 5]] | ['torch.float32', 'torch.float32'] | [exception] ref raised RuntimeError, test returned normally | True |
| decomp | nn.functional.soft_margin_loss | dtype_int64 | [[5, 5], [5, 5]] | ['torch.int64', 'torch.int64'] | [exception] ref raised RuntimeError, test returned normally | True |
| decomp | nn.functional.soft_margin_loss | dtype_bool | [[5, 5], [5, 5]] | ['torch.bool', 'torch.float32'] | [exception] ref raised RuntimeError, test returned normally | True |
| meta | nn.functional.upsample_nearest | empty_dim0 | [[0, 3, 4]] | ['torch.float32'] | fake-tensor path raised TypeError: cond must be a bool, but got <class 'int'> | None |
| decomp | nn.functional.upsample_nearest | dtype_int64 | [[2, 3, 4]] | ['torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.upsample_nearest | dtype_bool | [[2, 3, 4]] | ['torch.bool'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.multi_margin_loss | dtype_int64 | [[], []] | ['torch.int64', 'torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.multi_margin_loss | dtype_float16 | [[], []] | ['torch.float16', 'torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.multi_margin_loss | dtype_bfloat16 | [[], []] | ['torch.bfloat16', 'torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.multi_margin_loss | nan_inf | [[10, 5], [10]] | ['torch.float32', 'torch.int64'] | [value] output[0]: NaN/Inf pattern differs from the float64 truth | True |
| decomp | nn.functional.multilabel_margin_loss | dtype_int64 | [[10, 5], [10, 5]] | ['torch.int64', 'torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.multilabel_margin_loss | dtype_float16 | [[10, 5], [10, 5]] | ['torch.float16', 'torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.multilabel_margin_loss | dtype_bfloat16 | [[10, 5], [10, 5]] | ['torch.bfloat16', 'torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.multilabel_margin_loss | nan_inf | [[5], [5]] | ['torch.float32', 'torch.int64'] | [value] output[0]: NaN/Inf pattern differs from the float64 truth | True |
| decomp | nn.functional.multilabel_soft_margin_loss | dtype_int64 | [[5], [5]] | ['torch.int64', 'torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.max_unpool1d | dtype_int64 | [[1, 2, 2], [1, 2, 2]] | ['torch.int64', 'torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.max_unpool1d | dtype_bool | [[1, 2, 2], [1, 2, 2]] | ['torch.bool', 'torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.max_unpool1d | dtype_int64 | [[1, 2, 1], [1, 2, 1]] | ['torch.int64', 'torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.max_unpool1d | dtype_bool | [[1, 2, 1], [1, 2, 1]] | ['torch.bool', 'torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| meta_stride | nn.functional.max_unpool2d | base | [[1, 2, 4, 4], [1, 2, 4, 4]] | ['torch.float32', 'torch.int64'] | output[0] stride (72, 36, 6, 1) vs real (72, 1, 12, 2) | None |
| meta_stride | nn.functional.max_unpool2d | size1_dim0 | [[1, 2, 4, 4], [1, 2, 4, 4]] | ['torch.float32', 'torch.int64'] | output[0] stride (72, 36, 6, 1) vs real (72, 1, 12, 2) | None |
| meta_stride | nn.functional.max_unpool2d | noncontig | [[1, 2, 4, 4], [1, 2, 4, 4]] | ['torch.float32', 'torch.int64'] | output[0] stride (72, 36, 6, 1) vs real (72, 1, 12, 2) | None |
| meta_stride | nn.functional.max_unpool2d | channels_last | [[1, 2, 4, 4], [1, 2, 4, 4]] | ['torch.float32', 'torch.int64'] | output[0] stride (72, 36, 6, 1) vs real (72, 1, 12, 2) | None |
| decomp | nn.functional.max_unpool2d | dtype_int64 | [[1, 2, 4, 4], [1, 2, 4, 4]] | ['torch.int64', 'torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.max_unpool2d | dtype_bool | [[1, 2, 4, 4], [1, 2, 4, 4]] | ['torch.bool', 'torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| meta_stride | nn.functional.max_unpool2d | huge | [[1, 2, 4, 4], [1, 2, 4, 4]] | ['torch.float32', 'torch.int64'] | output[0] stride (72, 36, 6, 1) vs real (72, 1, 12, 2) | None |
| meta_stride | nn.functional.max_unpool2d | tiny | [[1, 2, 4, 4], [1, 2, 4, 4]] | ['torch.float32', 'torch.int64'] | output[0] stride (72, 36, 6, 1) vs real (72, 1, 12, 2) | None |
| meta_stride | nn.functional.max_unpool2d | dtype_float16 | [[1, 2, 4, 4], [1, 2, 4, 4]] | ['torch.float16', 'torch.int64'] | output[0] stride (72, 36, 6, 1) vs real (72, 1, 12, 2) | None |
| meta_stride | nn.functional.max_unpool2d | dtype_bfloat16 | [[1, 2, 4, 4], [1, 2, 4, 4]] | ['torch.bfloat16', 'torch.int64'] | output[0] stride (72, 36, 6, 1) vs real (72, 1, 12, 2) | None |
| meta_stride | nn.functional.max_unpool2d | base | [[1, 2, 1, 3], [1, 2, 1, 3]] | ['torch.float32', 'torch.int64'] | output[0] stride (36, 18, 6, 1) vs real (36, 1, 12, 2) | None |
| meta_stride | nn.functional.max_unpool2d | size1_dim0 | [[1, 2, 1, 3], [1, 2, 1, 3]] | ['torch.float32', 'torch.int64'] | output[0] stride (36, 18, 6, 1) vs real (36, 1, 12, 2) | None |
| meta_stride | nn.functional.max_unpool2d | noncontig | [[1, 2, 1, 3], [1, 2, 1, 3]] | ['torch.float32', 'torch.int64'] | output[0] stride (36, 18, 6, 1) vs real (36, 1, 12, 2) | None |
| meta_stride | nn.functional.max_unpool2d | channels_last | [[1, 2, 1, 3], [1, 2, 1, 3]] | ['torch.float32', 'torch.int64'] | output[0] stride (36, 18, 6, 1) vs real (36, 1, 12, 2) | None |
| decomp | nn.functional.max_unpool2d | dtype_int64 | [[1, 2, 1, 3], [1, 2, 1, 3]] | ['torch.int64', 'torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.max_unpool2d | dtype_bool | [[1, 2, 1, 3], [1, 2, 1, 3]] | ['torch.bool', 'torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| meta_stride | nn.functional.max_unpool2d | huge | [[1, 2, 1, 3], [1, 2, 1, 3]] | ['torch.float32', 'torch.int64'] | output[0] stride (36, 18, 6, 1) vs real (36, 1, 12, 2) | None |
| meta_stride | nn.functional.max_unpool2d | tiny | [[1, 2, 1, 3], [1, 2, 1, 3]] | ['torch.float32', 'torch.int64'] | output[0] stride (36, 18, 6, 1) vs real (36, 1, 12, 2) | None |
| meta_stride | nn.functional.max_unpool2d | dtype_float16 | [[1, 2, 1, 3], [1, 2, 1, 3]] | ['torch.float16', 'torch.int64'] | output[0] stride (36, 18, 6, 1) vs real (36, 1, 12, 2) | None |
| meta_stride | nn.functional.max_unpool2d | dtype_bfloat16 | [[1, 2, 1, 3], [1, 2, 1, 3]] | ['torch.bfloat16', 'torch.int64'] | output[0] stride (36, 18, 6, 1) vs real (36, 1, 12, 2) | None |
| meta_stride | nn.functional.max_unpool2d | channels_last | [[1, 2, 2, 2], [1, 2, 2, 2]] | ['torch.float32', 'torch.int64'] | output[0] stride (72, 36, 6, 1) vs real (72, 1, 12, 2) | None |
| decomp | nn.functional.max_unpool3d | dtype_int64 | [[1, 2, 1, 3, 2], [1, 2, 1, 3, 2]] | ['torch.int64', 'torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.max_unpool3d | dtype_bool | [[1, 2, 1, 3, 2], [1, 2, 1, 3, 2]] | ['torch.bool', 'torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.max_unpool3d | dtype_int64 | [[1, 2, 1, 2, 2], [1, 2, 1, 2, 2]] | ['torch.int64', 'torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.max_unpool3d | dtype_bool | [[1, 2, 1, 2, 2], [1, 2, 1, 2, 2]] | ['torch.bool', 'torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.prelu | dtype_int64 | [[5, 5], [5]] | ['torch.int64', 'torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.celu | dtype_int64 | [[1, 0, 3]] | ['torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.celu | dtype_bool | [[1, 0, 3]] | ['torch.bool'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.silu | dtype_int64 | [[]] | ['torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.silu | dtype_bool | [[]] | ['torch.bool'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.hardsigmoid | dtype_int64 | [[]] | ['torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.hardsigmoid | dtype_bool | [[]] | ['torch.bool'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.logsigmoid | dtype_int64 | [[1, 0, 3]] | ['torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.threshold | dtype_bool | [[5, 5, 5]] | ['torch.bool'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.batch_norm | dtype_int64 | [[3, 2, 4], [2], [2], [2], [2]] | ['torch.int64', 'torch.int64', 'torch.int64', 'torch.int64', 'torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.binary_cross_entropy | dtype_int64 | [[5, 5, 5], [5, 5, 5]] | ['torch.int64', 'torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.binary_cross_entropy | dtype_bool | [[5, 5, 5], [5, 5, 5]] | ['torch.bool', 'torch.float32'] | [exception] ref raised RuntimeError, test returned normally | True |
| decomp | nn.functional.binary_cross_entropy | nan_inf | [[5, 5, 5], [5, 5, 5]] | ['torch.float32', 'torch.float32'] | [exception] ref raised RuntimeError, test returned normally | True |
| decomp | nn.functional.binary_cross_entropy | huge | [[5, 5, 5], [5, 5, 5]] | ['torch.float32', 'torch.float32'] | [exception] ref raised RuntimeError, test returned normally | True |
| decomp | nn.functional.binary_cross_entropy | dtype_float16 | [[5, 5], [5, 5]] | ['torch.float16', 'torch.float16'] | [metadata] output[0].dtype: torch.float16 vs torch.float32 | True |
| meta | nn.functional.binary_cross_entropy | dtype_float16 | [[5, 5], [5, 5]] | ['torch.float16', 'torch.float16'] | output[0] dtype torch.float32 vs real torch.float16 | None |
| decomp | nn.functional.binary_cross_entropy | dtype_bfloat16 | [[5, 5], [5, 5]] | ['torch.bfloat16', 'torch.bfloat16'] | [metadata] output[0].dtype: torch.bfloat16 vs torch.float32 | True |
| meta | nn.functional.binary_cross_entropy | dtype_bfloat16 | [[5, 5], [5, 5]] | ['torch.bfloat16', 'torch.bfloat16'] | output[0] dtype torch.float32 vs real torch.bfloat16 | None |
| decomp | nn.functional.hardshrink | dtype_int64 | [[1, 0, 3]] | ['torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.gelu | dtype_int64 | [[10, 10]] | ['torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.gelu | dtype_bool | [[10, 10]] | ['torch.bool'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | mvlgamma | dtype_bool | [[5, 5]] | ['torch.bool'] | [exception] ref raised RuntimeError, test returned normally | True |
| decomp | mvlgamma | dtype_bool | [[]] | ['torch.bool'] | [exception] ref raised RuntimeError, test returned normally | True |
| decomp | mvlgamma | dtype_bool | [[5, 5]] | ['torch.bool'] | [exception] ref raised RuntimeError, test returned normally | True |
| decomp | round | dtype_int64 | [[1, 0, 3]] | ['torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | round | dtype_bool | [[1, 0, 3]] | ['torch.bool'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | round | dtype_int64 | [[20]] | ['torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | round | dtype_bool | [[20]] | ['torch.bool'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | round | dtype_int64 | [[20]] | ['torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | round | dtype_bool | [[20]] | ['torch.bool'] | [exception] ref raised NotImplementedError, test returned normally | True |
| meta | split | empty_dim0 | [[0, 5, 5]] | ['torch.float32'] | fake-tensor path raised IndexError: list assignment index out of range | None |
| meta | split | empty_dim0 | [[0, 5, 5]] | ['torch.float32'] | fake-tensor path raised IndexError: list assignment index out of range | None |
| meta | unsafe_split | empty_dim0 | [[0, 5, 5]] | ['torch.float32'] | fake-tensor path raised IndexError: list assignment index out of range | None |
| decomp | lerp | dtype_int64 | [[5, 5], [5, 5, 5], [5]] | ['torch.int64', 'torch.int64', 'torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | lerp | dtype_bool | [[5, 5], [5, 5, 5], [5]] | ['torch.bool', 'torch.float32', 'torch.float32'] | [exception] ref raised RuntimeError, test returned normally | False |
| decomp | index_add | zero_dim | [[], [1], [1]] | ['torch.float32', 'torch.int64', 'torch.float32'] | [exception] ref raised RuntimeError, test returned normally | True |
| decomp | index_reduce | empty_last | [[5, 0], [10], [5, 10]] | ['torch.float32', 'torch.int64', 'torch.float32'] | [exception] ref raised IndexError, test returned normally | True |
| decomp | trace | dtype_bool | [[5, 5]] | ['torch.bool'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | trace | dtype_float16 | [[5, 5]] | ['torch.float16'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | trace | dtype_bfloat16 | [[5, 5]] | ['torch.bfloat16'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.smooth_l1_loss | dtype_int64 | [[5, 5], [5, 5]] | ['torch.int64', 'torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | log_softmax | dtype_int64 | [[5, 5]] | ['torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | norm | size1_last | [[5, 5, 1]] | ['torch.float32'] | [metadata] output[0].shape: (5, 5) vs (5, 5, 1) | True |
| meta | norm | size1_last | [[5, 5, 1]] | ['torch.float32'] | output[0] shape (5, 5, 1) vs real (5, 5) | None |
| decomp | nn.functional.softplus | dtype_int64 | [[1, 0, 3]] | ['torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.mse_loss | dtype_int64 | [[5], [5]] | ['torch.int64', 'torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.grid_sample | dtype_int64 | [[2, 3, 5, 5], [2, 5, 5, 2]] | ['torch.int64', 'torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.grid_sample | dtype_bool | [[2, 3, 5, 5], [2, 5, 5, 2]] | ['torch.bool', 'torch.float32'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | grid_sampler_2d | dtype_int64 | [[2, 3, 5, 20], [2, 13, 10, 2]] | ['torch.int64', 'torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | grid_sampler_2d | dtype_bool | [[2, 3, 5, 20], [2, 13, 10, 2]] | ['torch.bool', 'torch.float32'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | std | huge | [[3, 4, 5]] | ['torch.float32'] | [value] output[0]: NaN/Inf pattern differs from the float64 truth | True |
| decomp | std | huge | [[5]] | ['torch.float32'] | [value] output[0]: NaN/Inf pattern differs from the float64 truth | True |
| decomp | nn.functional.nll_loss | dtype_int64 | [[3], []] | ['torch.int64', 'torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.nll_loss | dtype_bool | [[3], []] | ['torch.bool', 'torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.nll_loss | dtype_float16 | [[3], []] | ['torch.float16', 'torch.int64'] | [exception] ref raised RuntimeError, test returned normally | True |
| decomp | nn.functional.nll_loss | dtype_bfloat16 | [[3], []] | ['torch.bfloat16', 'torch.int64'] | [exception] ref raised RuntimeError, test returned normally | True |
| decomp | nn.functional.huber_loss | dtype_int64 | [[5, 5], [5, 5]] | ['torch.int64', 'torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.huber_loss | dtype_bool | [[5, 5], [5, 5]] | ['torch.bool', 'torch.float32'] | [exception] ref raised RuntimeError, test returned normally | True |
| meta_stride | nn.functional.channel_shuffle | channels_last | [[2, 6, 8, 8]] | ['torch.float32'] | output[0] stride (384, 64, 8, 1) vs real (384, 1, 48, 6) | None |
| meta_stride | nn.functional.channel_shuffle | channels_last | [[2, 8, 5, 5]] | ['torch.float32'] | output[0] stride (200, 25, 5, 1) vs real (200, 1, 40, 8) | None |
| meta_stride | fft.fft | base | [[5, 6, 7]] | ['torch.float32'] | output[0] stride (42, 7, 1) vs real (1, 35, 5) | None |
| meta_stride | fft.fft | size1_last | [[5, 6, 1]] | ['torch.float32'] | output[0] stride (6, 1, 1) vs real (1, 5, 30) | None |
| meta_stride | fft.fft | prime_dim0 | [[7, 6, 7]] | ['torch.float32'] | output[0] stride (42, 7, 1) vs real (1, 49, 7) | None |
| meta_stride | fft.fft | noncontig | [[5, 6, 7]] | ['torch.float32'] | output[0] stride (42, 7, 1) vs real (1, 35, 5) | None |
| meta_stride | fft.fft | prime_all | [[7, 11, 13]] | ['torch.float32'] | output[0] stride (143, 13, 1) vs real (1, 91, 7) | None |
| meta_stride | fft.fft | dtype_int64 | [[5, 6, 7]] | ['torch.int64'] | output[0] stride (42, 7, 1) vs real (1, 35, 5) | None |
| meta_stride | fft.fft | dtype_bool | [[5, 6, 7]] | ['torch.bool'] | output[0] stride (42, 7, 1) vs real (1, 35, 5) | None |
| meta_stride | fft.fft | nan_inf | [[5, 6, 7]] | ['torch.float32'] | output[0] stride (42, 7, 1) vs real (1, 35, 5) | None |
| meta_stride | fft.fft | huge | [[5, 6, 7]] | ['torch.float32'] | output[0] stride (42, 7, 1) vs real (1, 35, 5) | None |
| meta_stride | fft.fft | tiny | [[5, 6, 7]] | ['torch.float32'] | output[0] stride (42, 7, 1) vs real (1, 35, 5) | None |
| meta_stride | fft.rfft2 | base | [[5, 6, 7]] | ['torch.float32'] | output[0] stride (42, 7, 1) vs real (1, 21, 3) | None |
| meta_stride | fft.rfft2 | size1_last | [[5, 6, 1]] | ['torch.float32'] | output[0] stride (6, 1, 1) vs real (1, 3, 18) | None |
| meta_stride | fft.rfft2 | prime_dim0 | [[7, 6, 7]] | ['torch.float32'] | output[0] stride (42, 7, 1) vs real (1, 28, 4) | None |
| meta_stride | fft.rfft2 | noncontig | [[5, 6, 7]] | ['torch.float32'] | output[0] stride (42, 7, 1) vs real (1, 21, 3) | None |
| meta_stride | fft.rfft2 | prime_all | [[7, 11, 13]] | ['torch.float32'] | output[0] stride (143, 13, 1) vs real (1, 52, 4) | None |
| meta_stride | fft.rfft2 | dtype_int64 | [[5, 6, 7]] | ['torch.int64'] | output[0] stride (42, 7, 1) vs real (1, 21, 3) | None |
| meta_stride | fft.rfft2 | dtype_bool | [[5, 6, 7]] | ['torch.bool'] | output[0] stride (42, 7, 1) vs real (1, 21, 3) | None |
| meta_stride | fft.rfft2 | nan_inf | [[5, 6, 7]] | ['torch.float32'] | output[0] stride (42, 7, 1) vs real (1, 21, 3) | None |
| meta_stride | fft.rfft2 | huge | [[5, 6, 7]] | ['torch.float32'] | output[0] stride (42, 7, 1) vs real (1, 21, 3) | None |
| meta_stride | fft.rfft2 | tiny | [[5, 6, 7]] | ['torch.float32'] | output[0] stride (42, 7, 1) vs real (1, 21, 3) | None |
| meta_stride | fft.rfftn | base | [[5, 6, 7]] | ['torch.float32'] | output[0] stride (24, 4, 1) vs real (4, 20, 1) | None |
| meta_stride | fft.rfftn | size1_last | [[5, 6, 1]] | ['torch.float32'] | output[0] stride (6, 1, 1) vs real (1, 5, 1) | None |
| meta_stride | fft.rfftn | prime_dim0 | [[7, 6, 7]] | ['torch.float32'] | output[0] stride (24, 4, 1) vs real (4, 28, 1) | None |
| meta_stride | fft.rfftn | noncontig | [[5, 6, 7]] | ['torch.float32'] | output[0] stride (24, 4, 1) vs real (4, 20, 1) | None |
| meta_stride | fft.rfftn | prime_all | [[7, 11, 13]] | ['torch.float32'] | output[0] stride (77, 7, 1) vs real (7, 49, 1) | None |
| meta_stride | fft.rfftn | dtype_int64 | [[5, 6, 7]] | ['torch.int64'] | output[0] stride (24, 4, 1) vs real (4, 20, 1) | None |
| meta_stride | fft.rfftn | dtype_bool | [[5, 6, 7]] | ['torch.bool'] | output[0] stride (24, 4, 1) vs real (4, 20, 1) | None |
| meta_stride | fft.rfftn | nan_inf | [[5, 6, 7]] | ['torch.float32'] | output[0] stride (24, 4, 1) vs real (4, 20, 1) | None |
| meta_stride | fft.rfftn | huge | [[5, 6, 7]] | ['torch.float32'] | output[0] stride (24, 4, 1) vs real (4, 20, 1) | None |
| meta_stride | fft.rfftn | tiny | [[5, 6, 7]] | ['torch.float32'] | output[0] stride (24, 4, 1) vs real (4, 20, 1) | None |
| meta_stride | fft.ifft | base | [[5, 6, 7]] | ['torch.float32'] | output[0] stride (42, 7, 1) vs real (42, 1, 6) | None |
| meta_stride | fft.ifft | size1_dim0 | [[1, 6, 7]] | ['torch.float32'] | output[0] stride (42, 7, 1) vs real (42, 1, 6) | None |
| meta_stride | fft.ifft | prime_dim0 | [[7, 6, 7]] | ['torch.float32'] | output[0] stride (42, 7, 1) vs real (42, 1, 6) | None |
| meta_stride | fft.ifft | noncontig | [[5, 6, 7]] | ['torch.float32'] | output[0] stride (42, 7, 1) vs real (42, 1, 6) | None |
| meta_stride | fft.ifft | prime_all | [[7, 11, 13]] | ['torch.float32'] | output[0] stride (143, 13, 1) vs real (143, 1, 11) | None |
| meta_stride | fft.ifft | dtype_int64 | [[5, 6, 7]] | ['torch.int64'] | output[0] stride (42, 7, 1) vs real (42, 1, 6) | None |
| meta_stride | fft.ifft | dtype_bool | [[5, 6, 7]] | ['torch.bool'] | output[0] stride (42, 7, 1) vs real (42, 1, 6) | None |
| meta_stride | fft.ifft | nan_inf | [[5, 6, 7]] | ['torch.float32'] | output[0] stride (42, 7, 1) vs real (42, 1, 6) | None |
| meta_stride | fft.ifft | huge | [[5, 6, 7]] | ['torch.float32'] | output[0] stride (42, 7, 1) vs real (42, 1, 6) | None |
| meta_stride | fft.ifft | tiny | [[5, 6, 7]] | ['torch.float32'] | output[0] stride (42, 7, 1) vs real (42, 1, 6) | None |
| meta_stride | fft.ihfft | base | [[5, 6, 7]] | ['torch.float32'] | output[0] stride (42, 7, 1) vs real (1, 21, 3) | None |
| meta_stride | fft.ihfft | size1_last | [[5, 6, 1]] | ['torch.float32'] | output[0] stride (6, 1, 1) vs real (1, 3, 18) | None |
| meta_stride | fft.ihfft | prime_dim0 | [[7, 6, 7]] | ['torch.float32'] | output[0] stride (42, 7, 1) vs real (1, 28, 4) | None |
| meta_stride | fft.ihfft | noncontig | [[5, 6, 7]] | ['torch.float32'] | output[0] stride (42, 7, 1) vs real (1, 21, 3) | None |
| meta_stride | fft.ihfft | prime_all | [[7, 11, 13]] | ['torch.float32'] | output[0] stride (143, 13, 1) vs real (1, 52, 4) | None |
| meta_stride | fft.ihfft | dtype_int64 | [[5, 6, 7]] | ['torch.int64'] | output[0] stride (42, 7, 1) vs real (1, 21, 3) | None |
| meta_stride | fft.ihfft | dtype_bool | [[5, 6, 7]] | ['torch.bool'] | output[0] stride (42, 7, 1) vs real (1, 21, 3) | None |
| meta_stride | fft.ihfft | nan_inf | [[5, 6, 7]] | ['torch.float32'] | output[0] stride (42, 7, 1) vs real (1, 21, 3) | None |
| meta_stride | fft.ihfft | huge | [[5, 6, 7]] | ['torch.float32'] | output[0] stride (42, 7, 1) vs real (1, 21, 3) | None |
| meta_stride | fft.ihfft | tiny | [[5, 6, 7]] | ['torch.float32'] | output[0] stride (42, 7, 1) vs real (1, 21, 3) | None |
| decomp | linalg.cross | dtype_bool | [[5, 3, 5], [5, 3, 5]] | ['torch.bool', 'torch.float32'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | linalg.vector_norm | size1_last | [[3, 1]] | ['torch.float32'] | [metadata] output[0].shape: (3,) vs (3, 1) | True |
| meta | linalg.vector_norm | size1_last | [[3, 1]] | ['torch.float32'] | output[0] shape (3, 1) vs real (3,) | None |
| decomp | masked.softmax | dtype_int64 | [[5, 5]] | ['torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | masked.log_softmax | dtype_int64 | [[5, 10, 5]] | ['torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | masked.softmin | dtype_int64 | [[]] | ['torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | masked.logaddexp | dtype_int64 | [[5, 10, 5], [5, 10, 5]] | ['torch.int64', 'torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
