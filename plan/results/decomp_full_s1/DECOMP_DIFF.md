# Decomposition / meta differential

- operators: 580, samples: 1118, input variants: 15545
- variants where at least one decomposition ran: 6334
- decomposition mismatches: 161  (confirmed by torch.compile: 139)
- meta / fake-tensor mismatches: 34 (data-dependent ops that cannot run on fake tensors, not counted: 164)
- wall: 677.0 s

| kind | op | variant | shapes | dtypes | detail | confirmed |
|---|---|---|---|---|---|---|
| decomp | bmm | zero_dim | [[], [10, 10, 5]] | ['torch.float32', 'torch.float32'] | [exception] exception type differs: RuntimeError vs IndexError :: tuple index out of range | False |
| decomp | mv | zero_dim | [[], [10]] | ['torch.float32', 'torch.float32'] | [exception] exception type differs: IndexError vs RuntimeError :: matrix @ vector expected | True |
| decomp | mv | dtype_bool | [[5, 10], [10]] | ['torch.bool', 'torch.float32'] | [exception] ref raised RuntimeError, test returned normally | True |
| decomp | bmm | size1_dim0 | [[1, 128, 1], [8, 1, 256]] | ['torch.float32', 'torch.float32'] | [exception] ref raised RuntimeError, test returned normally | False |
| decomp | bmm | zero_dim | [[], [8, 1, 256]] | ['torch.float32', 'torch.float32'] | [exception] exception type differs: RuntimeError vs IndexError :: tuple index out of range | False |
| decomp | bmm | dtype_bool | [[8, 128, 1], [8, 1, 256]] | ['torch.bool', 'torch.float32'] | [exception] ref raised RuntimeError, test returned normally | False |
| decomp | cross | dtype_bool | [[5, 3, 5], [5, 3, 5]] | ['torch.bool', 'torch.float32'] | [exception] ref raised NotImplementedError, test returned normally | True |
| meta | expand | zero_dim | [[]] | ['torch.float32'] | fake-tensor path raised RuntimeError: Trying to create tensor with negative dimension -1:  | None |
| decomp | frac | dtype_int64 | [[20, 20]] | ['torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | stft | empty_dim0 | [[0]] | ['torch.float32'] | [exception] exception type differs: RuntimeError vs IndexError :: index is out of bounds f | False |
| decomp | stft | size1_dim0 | [[1]] | ['torch.float32'] | [exception] exception type differs: RuntimeError vs IndexError :: index -5 is out of bound | False |
| decomp | stft | zero_dim | [[]] | ['torch.float32'] | [exception] exception type differs: RuntimeError vs IndexError :: index -5 is out of bound | False |
| decomp | stft | empty_last | [[3, 0]] | ['torch.float32'] | [exception] exception type differs: RuntimeError vs IndexError :: index is out of bounds f | False |
| decomp | stft | size1_last | [[3, 1]] | ['torch.float32'] | [exception] exception type differs: RuntimeError vs IndexError :: index -8 is out of bound | False |
| decomp | stft | zero_dim | [[]] | ['torch.float32'] | [exception] exception type differs: RuntimeError vs IndexError :: index -8 is out of bound | False |
| decomp | isin | dtype_bool | [[5], [20]] | ['torch.bool', 'torch.float32'] | [exception] ref raised RuntimeError, test returned normally | False |
| decomp | logaddexp | dtype_int64 | [[10, 1, 5], [1, 10, 5]] | ['torch.int64', 'torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | logaddexp2 | dtype_int64 | [[5, 5], [5, 5]] | ['torch.int64', 'torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | std_mean | huge | [[5, 5, 5]] | ['torch.float32'] | [value] output[0]: NaN/Inf pattern differs from the float64 truth | True |
| decomp | std_mean | huge | [[5, 5]] | ['torch.float32'] | [value] output[0]: NaN/Inf pattern differs from the float64 truth | True |
| decomp | heaviside | dtype_bool | [[0, 1, 3], [0, 10, 3]] | ['torch.bool', 'torch.float32'] | [exception] ref raised RuntimeError, test returned normally | True |
| decomp | softmax | dtype_int64 | [[5, 0, 0]] | ['torch.int64'] | [exception] test raised RuntimeError, ref returned normally :: value cannot be converted t | True |
| decomp | softmax | dtype_bool | [[5, 0, 0]] | ['torch.bool'] | [exception] test raised NotImplementedError, ref returned normally :: Subtraction, the `-` | True |
| decomp | softmax | dtype_int64 | [[5, 5]] | ['torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.softmin | dtype_int64 | [[5, 5]] | ['torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.cross_entropy | empty_last | [[2, 0], [2]] | ['torch.float32', 'torch.int64'] | [exception] exception type differs: IndexError vs RuntimeError :: index 0 is out of bounds | True |
| decomp | nn.functional.cross_entropy | dtype_int64 | [[2, 3], [2]] | ['torch.int64', 'torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.linear_cross_entropy | dtype_bool | [[3], [4, 3], [4]] | ['torch.bool', 'torch.float32', 'torch.float32'] | [exception] ref raised RuntimeError, test returned normally | False |
| decomp | nn.functional.linear_cross_entropy | dtype_float16 | [[3], [4, 3], [4]] | ['torch.float16', 'torch.float16', 'torch.float16'] | [exception] ref raised RuntimeError, test returned normally | False |
| decomp | nn.functional.linear_cross_entropy | dtype_bfloat16 | [[3], [4, 3], [4]] | ['torch.bfloat16', 'torch.bfloat16', 'torch.bfloat16'] | [exception] ref raised RuntimeError, test returned normally | False |
| meta_stride | native_group_norm | base | [[2, 6, 5, 3], [6], [6]] | ['torch.float32', 'torch.float32', 'torch.float32'] | output[0] stride (90, 15, 3, 1) vs real (90, 1, 18, 6) | None |
| meta_stride | native_group_norm | noncontig | [[2, 6, 5, 3], [6], [6]] | ['torch.float32', 'torch.float32', 'torch.float32'] | output[0] stride (90, 15, 3, 1) vs real (90, 1, 18, 6) | None |
| meta_stride | native_group_norm | channels_last | [[2, 6, 5, 3], [6], [6]] | ['torch.float32', 'torch.float32', 'torch.float32'] | output[0] stride (90, 15, 3, 1) vs real (90, 1, 18, 6) | None |
| decomp | native_group_norm | dtype_int64 | [[2, 6, 5, 3], [6], [6]] | ['torch.int64', 'torch.int64', 'torch.int64'] | [exception] exception type differs: NotImplementedError vs RuntimeError :: var_mean only s | True |
| meta_stride | native_group_norm | huge | [[2, 6, 5, 3], [6], [6]] | ['torch.float32', 'torch.float32', 'torch.float32'] | output[0] stride (90, 15, 3, 1) vs real (90, 1, 18, 6) | None |
| meta_stride | native_group_norm | tiny | [[2, 6, 5, 3], [6], [6]] | ['torch.float32', 'torch.float32', 'torch.float32'] | output[0] stride (90, 15, 3, 1) vs real (90, 1, 18, 6) | None |
| meta_stride | native_group_norm | dtype_float16 | [[2, 6, 5, 3], [6], [6]] | ['torch.float16', 'torch.float16', 'torch.float16'] | output[0] stride (90, 15, 3, 1) vs real (90, 1, 18, 6) | None |
| meta_stride | native_group_norm | dtype_bfloat16 | [[2, 6, 5, 3], [6], [6]] | ['torch.bfloat16', 'torch.bfloat16', 'torch.bfloat16'] | output[0] stride (90, 15, 3, 1) vs real (90, 1, 18, 6) | None |
| decomp | native_group_norm | empty_last | [[0, 0], [2], [2]] | ['torch.float32', 'torch.float32', 'torch.float32'] | [exception] test raised RuntimeError, ref returned normally :: The size of tensor a (0) mu | True |
| meta | native_group_norm | empty_last | [[0, 0], [2], [2]] | ['torch.float32', 'torch.float32', 'torch.float32'] | fake-tensor path raised RuntimeError: Attempting to broadcast a dimension of length 2 at - | None |
| decomp | native_group_norm | size1_last | [[0, 1], [2], [2]] | ['torch.float32', 'torch.float32', 'torch.float32'] | [metadata] output[0].shape: (0, 1) vs (0, 2) | True |
| meta | native_group_norm | size1_last | [[0, 1], [2], [2]] | ['torch.float32', 'torch.float32', 'torch.float32'] | output[0] shape (0, 2) vs real (0, 1) | None |
| decomp | native_group_norm | dtype_int64 | [[0, 2], [2], [2]] | ['torch.int64', 'torch.int64', 'torch.int64'] | [exception] test raised RuntimeError, ref returned normally :: var_mean only support float | True |
| meta | native_group_norm | dtype_int64 | [[0, 2], [2], [2]] | ['torch.int64', 'torch.int64', 'torch.int64'] | fake-tensor path raised RuntimeError: mean(): could not infer output dtype. Input dtype mu | None |
| decomp | native_layer_norm | dtype_int64 | [[1], [1], [1]] | ['torch.int64', 'torch.int64', 'torch.int64'] | [exception] exception type differs: NotImplementedError vs RuntimeError :: var_mean only s | True |
| decomp | native_layer_norm | dtype_bool | [[2, 2, 3]] | ['torch.bool'] | [exception] exception type differs: NotImplementedError vs RuntimeError :: var_mean only s | True |
| decomp | native_batch_norm | empty_dim0 | [[0, 2, 3]] | ['torch.float32'] | [exception] ref raised RuntimeError, test returned normally | True |
| decomp | native_batch_norm | empty_last | [[1, 2, 0]] | ['torch.float32'] | [exception] ref raised RuntimeError, test returned normally | True |
| decomp | native_batch_norm | zero_dim | [[]] | ['torch.float32'] | [exception] ref raised RuntimeError, test returned normally | True |
| decomp | native_batch_norm | dtype_int64 | [[1, 2, 3]] | ['torch.int64'] | [exception] exception type differs: NotImplementedError vs RuntimeError :: var_mean only s | True |
| decomp | native_batch_norm | dtype_bool | [[1, 2, 3]] | ['torch.bool'] | [exception] exception type differs: NotImplementedError vs RuntimeError :: var_mean only s | True |
| decomp | native_batch_norm | prime_all | [[7, 11, 13], [2], [2], [2], [2]] | ['torch.float32', 'torch.float32', 'torch.float32', 'torch.float32', 'torch.float32'] | [exception] test raised RuntimeError, ref returned normally :: The size of tensor a (11) m | True |
| meta | native_batch_norm | prime_all | [[7, 11, 13], [2], [2], [2], [2]] | ['torch.float32', 'torch.float32', 'torch.float32', 'torch.float32', 'torch.float32'] | fake-tensor path raised RuntimeError: Attempting to broadcast a dimension of length 2 at - | None |
| decomp | native_batch_norm | dtype_int64 | [[3, 2, 4], [2], [2], [2], [2]] | ['torch.int64', 'torch.int64', 'torch.int64', 'torch.int64', 'torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.adaptive_max_pool1d | dtype_int64 | [[3, 4, 4]] | ['torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.adaptive_max_pool1d | dtype_bool | [[3, 4, 4]] | ['torch.bool'] | [exception] exception type differs: NotImplementedError vs RuntimeError :: argmax(): does  | True |
| decomp | nn.functional.adaptive_max_pool3d | dtype_int64 | [[4, 4, 3, 5]] | ['torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.adaptive_max_pool3d | dtype_bool | [[4, 4, 3, 5]] | ['torch.bool'] | [exception] exception type differs: NotImplementedError vs RuntimeError :: argmax(): does  | True |
| decomp | nn.functional.instance_norm | dtype_int64 | [[3, 2, 3, 4]] | ['torch.int64'] | [exception] exception type differs: NotImplementedError vs RuntimeError :: var_mean only s | True |
| decomp | nn.functional.instance_norm | dtype_bool | [[3, 2, 3, 4]] | ['torch.bool'] | [exception] exception type differs: NotImplementedError vs RuntimeError :: var_mean only s | True |
| decomp | nn.functional.layer_norm | dtype_int64 | [[1, 2]] | ['torch.int64'] | [exception] exception type differs: NotImplementedError vs RuntimeError :: var_mean only s | True |
| decomp | nn.functional.layer_norm | dtype_bool | [[1, 2]] | ['torch.bool'] | [exception] exception type differs: NotImplementedError vs RuntimeError :: var_mean only s | True |
| decomp | nn.functional.pad | empty_dim0 | [[0, 3]] | ['torch.float32'] | [exception] ref raised RuntimeError, test returned normally | False |
| decomp | nn.functional.pad | empty_last | [[1, 0]] | ['torch.float32'] | [exception] exception type differs: RuntimeError vs IndexError :: index is out of bounds f | False |
| decomp | nn.functional.pad | size1_last | [[1, 1]] | ['torch.float32'] | [exception] exception type differs: RuntimeError vs IndexError :: index -2 is out of bound | False |
| decomp | nn.functional.pad | dtype_bool | [[1, 3]] | ['torch.bool'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.pad | size1_last | [[0, 3, 3, 1]] | ['torch.float32'] | [exception] ref raised RuntimeError, test returned normally | False |
| decomp | nn.functional.pad | empty_last | [[1, 3, 0]] | ['torch.float32'] | [exception] exception type differs: RuntimeError vs IndexError :: index is out of bounds f | False |
| decomp | nn.functional.pad | dtype_bool | [[1, 3, 3]] | ['torch.bool'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.pad | empty_last | [[2, 6, 5, 0]] | ['torch.float32'] | [exception] exception type differs: RuntimeError vs IndexError :: index is out of bounds f | False |
| decomp | nn.functional.pad | dtype_bool | [[2, 6, 5, 5]] | ['torch.bool'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.hardswish | dtype_int64 | [[10, 10]] | ['torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.hardswish | dtype_bool | [[10, 10]] | ['torch.bool'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.unfold | zero_dim | [[]] | ['torch.float32'] | [exception] exception type differs: IndexError vs RuntimeError :: Expected 3D or 4D (batch | True |
| decomp | nn.functional.unfold | dtype_int64 | [[2, 3, 5, 5]] | ['torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| meta | nn.functional.interpolate | empty_dim0 | [[0, 3, 4, 4]] | ['torch.float32'] | fake-tensor path raised TypeError: cond must be a bool, but got <class 'int'> | None |
| decomp | nn.functional.interpolate | empty_last | [[2, 3, 4, 0]] | ['torch.float32'] | [exception] exception type differs: RuntimeError vs ZeroDivisionError :: division by zero | True |
| decomp | nn.functional.interpolate | dtype_int64 | [[2, 3, 4, 4]] | ['torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.interpolate | dtype_bool | [[2, 3, 4, 4]] | ['torch.bool'] | [exception] ref raised NotImplementedError, test returned normally | True |
| meta | nn.functional.interpolate | empty_dim0 | [[0, 3, 4, 4]] | ['torch.float32'] | fake-tensor path raised TypeError: cond must be a bool, but got <class 'int'> | None |
| decomp | nn.functional.interpolate | empty_last | [[2, 3, 4, 0]] | ['torch.float32'] | [exception] exception type differs: RuntimeError vs IndexError :: index is out of bounds f | True |
| decomp | nn.functional.interpolate | dtype_int64 | [[2, 3, 4, 4]] | ['torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.interpolate | dtype_bool | [[2, 3, 4, 4]] | ['torch.bool'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.interpolate | empty_last | [[2, 3, 4, 0]] | ['torch.float32'] | [exception] exception type differs: RuntimeError vs ZeroDivisionError :: division by zero | True |
| decomp | nn.functional.interpolate | size1_last | [[2, 3, 4, 1]] | ['torch.float32'] | [exception] exception type differs: RuntimeError vs ZeroDivisionError :: division by zero | True |
| decomp | nn.functional.interpolate | empty_last | [[2, 3, 0]] | ['torch.float32'] | [exception] exception type differs: RuntimeError vs IndexError :: index is out of bounds f | True |
| decomp | nn.functional.interpolate | dtype_int64 | [[2, 3, 4]] | ['torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.interpolate | dtype_bool | [[2, 3, 4]] | ['torch.bool'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.interpolate | empty_last | [[2, 3, 0]] | ['torch.float32'] | [exception] exception type differs: RuntimeError vs ZeroDivisionError :: division by zero | True |
| decomp | nn.functional.soft_margin_loss | size1_dim0 | [[1], [5]] | ['torch.float32', 'torch.float32'] | [exception] ref raised RuntimeError, test returned normally | True |
| decomp | nn.functional.soft_margin_loss | zero_dim | [[], [5]] | ['torch.float32', 'torch.float32'] | [exception] ref raised RuntimeError, test returned normally | True |
| decomp | nn.functional.soft_margin_loss | dtype_int64 | [[5], [5]] | ['torch.int64', 'torch.int64'] | [exception] ref raised RuntimeError, test returned normally | True |
| decomp | nn.functional.soft_margin_loss | dtype_bool | [[5], [5]] | ['torch.bool', 'torch.float32'] | [exception] ref raised NotImplementedError, test returned normally | True |
| meta | nn.functional.upsample_nearest | empty_dim0 | [[0, 3, 4, 4]] | ['torch.float32'] | fake-tensor path raised TypeError: cond must be a bool, but got <class 'int'> | None |
| decomp | nn.functional.upsample_nearest | empty_last | [[2, 3, 4, 0]] | ['torch.float32'] | [exception] exception type differs: RuntimeError vs ZeroDivisionError :: division by zero | True |
| decomp | nn.functional.upsample_nearest | dtype_int64 | [[2, 3, 4, 4]] | ['torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.upsample_nearest | dtype_bool | [[2, 3, 4, 4]] | ['torch.bool'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.upsample_nearest | empty_last | [[2, 3, 4, 4, 0]] | ['torch.float32'] | [exception] exception type differs: RuntimeError vs IndexError :: index is out of bounds f | True |
| decomp | nn.functional.multi_margin_loss | dtype_int64 | [[5], []] | ['torch.int64', 'torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.multi_margin_loss | nan_inf | [[5], []] | ['torch.float32', 'torch.int64'] | [value] output[0]: NaN/Inf pattern differs from the float64 truth | True |
| decomp | nn.functional.multi_margin_loss | dtype_float16 | [[5], []] | ['torch.float16', 'torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.multi_margin_loss | dtype_bfloat16 | [[5], []] | ['torch.bfloat16', 'torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.multilabel_margin_loss | dtype_int64 | [[], []] | ['torch.int64', 'torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.multilabel_margin_loss | dtype_float16 | [[], []] | ['torch.float16', 'torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.multilabel_margin_loss | dtype_bfloat16 | [[], []] | ['torch.bfloat16', 'torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.multilabel_margin_loss | nan_inf | [[10, 5], [10, 5]] | ['torch.float32', 'torch.int64'] | [value] output[0]: NaN/Inf pattern differs from the float64 truth | True |
| decomp | nn.functional.multilabel_soft_margin_loss | dtype_int64 | [[5, 5], [5, 5]] | ['torch.int64', 'torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.max_pool1d | dtype_int64 | [[1, 2, 3]] | ['torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.max_pool2d | size1_last | [[2, 2, 3, 1]] | ['torch.float32'] | [value] output[1]: non-float values differ exactly | True |
| decomp | max_pool2d_with_indices_backward | dtype_int64 | [[2, 3, 6]] | ['torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.max_unpool1d | dtype_int64 | [[1, 2, 3], [1, 2, 3]] | ['torch.int64', 'torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.max_unpool1d | dtype_bool | [[1, 2, 3], [1, 2, 3]] | ['torch.bool', 'torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.max_unpool1d | dtype_int64 | [[1, 2, 1], [1, 2, 1]] | ['torch.int64', 'torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.max_unpool1d | dtype_bool | [[1, 2, 1], [1, 2, 1]] | ['torch.bool', 'torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.max_unpool2d | dtype_int64 | [[1, 2, 1, 2], [1, 2, 1, 2]] | ['torch.int64', 'torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.max_unpool2d | dtype_bool | [[1, 2, 1, 2], [1, 2, 1, 2]] | ['torch.bool', 'torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.max_unpool2d | dtype_int64 | [[1, 2, 1, 2], [1, 2, 1, 2]] | ['torch.int64', 'torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.max_unpool2d | dtype_bool | [[1, 2, 1, 2], [1, 2, 1, 2]] | ['torch.bool', 'torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.max_unpool3d | dtype_int64 | [[2, 2, 3, 4, 3], [2, 2, 3, 4, 3]] | ['torch.int64', 'torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.max_unpool3d | dtype_bool | [[2, 2, 3, 4, 3], [2, 2, 3, 4, 3]] | ['torch.bool', 'torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.max_unpool3d | dtype_int64 | [[1, 2, 2, 2, 2], [1, 2, 2, 2, 2]] | ['torch.int64', 'torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.max_unpool3d | dtype_bool | [[1, 2, 2, 2, 2], [1, 2, 2, 2, 2]] | ['torch.bool', 'torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.prelu | dtype_int64 | [[5, 10, 5], []] | ['torch.int64', 'torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.celu | dtype_int64 | [[1, 0, 3]] | ['torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.celu | dtype_bool | [[1, 0, 3]] | ['torch.bool'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.silu | dtype_int64 | [[1, 0, 3]] | ['torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.hardsigmoid | dtype_int64 | [[1, 0, 3]] | ['torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.hardsigmoid | dtype_bool | [[1, 0, 3]] | ['torch.bool'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.logsigmoid | dtype_int64 | [[1, 0, 3]] | ['torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.threshold | dtype_bool | [[]] | ['torch.bool'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.batch_norm | dtype_int64 | [[3, 2, 3, 4], [2], [2], [2], [2]] | ['torch.int64', 'torch.int64', 'torch.int64', 'torch.int64', 'torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.binary_cross_entropy | dtype_int64 | [[5, 5], [5, 5]] | ['torch.int64', 'torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.binary_cross_entropy | dtype_bool | [[5, 5], [5, 5]] | ['torch.bool', 'torch.float32'] | [exception] ref raised RuntimeError, test returned normally | True |
| decomp | nn.functional.binary_cross_entropy | nan_inf | [[5, 5], [5, 5]] | ['torch.float32', 'torch.float32'] | [exception] ref raised RuntimeError, test returned normally | True |
| decomp | nn.functional.binary_cross_entropy | huge | [[5, 5], [5, 5]] | ['torch.float32', 'torch.float32'] | [exception] ref raised RuntimeError, test returned normally | True |
| decomp | nn.functional.hardshrink | dtype_int64 | [[5, 5]] | ['torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.gelu | dtype_int64 | [[10, 10]] | ['torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.gelu | dtype_bool | [[10, 10]] | ['torch.bool'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | mvlgamma | dtype_bool | [[]] | ['torch.bool'] | [exception] ref raised RuntimeError, test returned normally | True |
| decomp | mvlgamma | dtype_bool | [[]] | ['torch.bool'] | [exception] ref raised RuntimeError, test returned normally | True |
| decomp | mvlgamma | dtype_bool | [[5, 5]] | ['torch.bool'] | [exception] ref raised RuntimeError, test returned normally | True |
| decomp | mvlgamma | dtype_bool | [[5, 5]] | ['torch.bool'] | [exception] ref raised RuntimeError, test returned normally | True |
| decomp | mvlgamma | dtype_bool | [[5, 5]] | ['torch.bool'] | [exception] ref raised RuntimeError, test returned normally | True |
| decomp | mvlgamma | dtype_bool | [[]] | ['torch.bool'] | [exception] ref raised RuntimeError, test returned normally | True |
| decomp | round | dtype_int64 | [[1, 0, 3]] | ['torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | round | dtype_bool | [[1, 0, 3]] | ['torch.bool'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | round | dtype_int64 | [[1, 0, 3]] | ['torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | round | dtype_bool | [[1, 0, 3]] | ['torch.bool'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | round | dtype_int64 | [[]] | ['torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | round | dtype_bool | [[]] | ['torch.bool'] | [exception] ref raised NotImplementedError, test returned normally | True |
| meta | tensor_split | base | [[5, 5, 5], [3]] | ['torch.float32', 'torch.int64'] | fake-tensor path raised RuntimeError: The tensor has a non-zero number of elements, but it | None |
| meta | tensor_split | empty_dim0 | [[0, 5, 5], [3]] | ['torch.float32', 'torch.int64'] | fake-tensor path raised RuntimeError: The tensor has a non-zero number of elements, but it | None |
| meta | tensor_split | size1_dim0 | [[1, 5, 5], [3]] | ['torch.float32', 'torch.int64'] | fake-tensor path raised RuntimeError: The tensor has a non-zero number of elements, but it | None |
| meta | tensor_split | empty_last | [[5, 5, 0], [3]] | ['torch.float32', 'torch.int64'] | fake-tensor path raised RuntimeError: The tensor has a non-zero number of elements, but it | None |
| meta | tensor_split | size1_last | [[5, 5, 1], [3]] | ['torch.float32', 'torch.int64'] | fake-tensor path raised RuntimeError: The tensor has a non-zero number of elements, but it | None |
| meta | tensor_split | prime_dim0 | [[7, 5, 5], [3]] | ['torch.float32', 'torch.int64'] | fake-tensor path raised RuntimeError: The tensor has a non-zero number of elements, but it | None |
| meta | tensor_split | noncontig | [[5, 5, 5], [3]] | ['torch.float32', 'torch.int64'] | fake-tensor path raised RuntimeError: The tensor has a non-zero number of elements, but it | None |
| meta | tensor_split | prime_all | [[7, 11, 13], [3]] | ['torch.float32', 'torch.int64'] | fake-tensor path raised RuntimeError: The tensor has a non-zero number of elements, but it | None |
| meta | tensor_split | dtype_int64 | [[5, 5, 5], [3]] | ['torch.int64', 'torch.int64'] | fake-tensor path raised RuntimeError: The tensor has a non-zero number of elements, but it | None |
| meta | tensor_split | dtype_bool | [[5, 5, 5], [3]] | ['torch.bool', 'torch.int64'] | fake-tensor path raised RuntimeError: The tensor has a non-zero number of elements, but it | None |
| meta | tensor_split | nan_inf | [[5, 5, 5], [3]] | ['torch.float32', 'torch.int64'] | fake-tensor path raised RuntimeError: The tensor has a non-zero number of elements, but it | None |
| meta | tensor_split | huge | [[5, 5, 5], [3]] | ['torch.float32', 'torch.int64'] | fake-tensor path raised RuntimeError: The tensor has a non-zero number of elements, but it | None |
| meta | tensor_split | tiny | [[5, 5, 5], [3]] | ['torch.float32', 'torch.int64'] | fake-tensor path raised RuntimeError: The tensor has a non-zero number of elements, but it | None |
| meta | tensor_split | dtype_float16 | [[5, 5, 5], [3]] | ['torch.float16', 'torch.int64'] | fake-tensor path raised RuntimeError: The tensor has a non-zero number of elements, but it | None |
| meta | tensor_split | dtype_bfloat16 | [[5, 5, 5], [3]] | ['torch.bfloat16', 'torch.int64'] | fake-tensor path raised RuntimeError: The tensor has a non-zero number of elements, but it | None |
| decomp | lerp | dtype_int64 | [[5], [5, 5, 5], [5, 5]] | ['torch.int64', 'torch.int64', 'torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | index_add | zero_dim | [[], [1], [1]] | ['torch.float32', 'torch.int64', 'torch.float32'] | [exception] ref raised RuntimeError, test returned normally | True |
| decomp | trace | dtype_bool | [[5, 7]] | ['torch.bool'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.smooth_l1_loss | dtype_int64 | [[5], [5]] | ['torch.int64', 'torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | log_softmax | dtype_int64 | [[5, 5]] | ['torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.softplus | dtype_int64 | [[]] | ['torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.grid_sample | dtype_int64 | [[2, 3, 5, 5], [2, 5, 5, 2]] | ['torch.int64', 'torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.grid_sample | dtype_bool | [[2, 3, 5, 5], [2, 5, 5, 2]] | ['torch.bool', 'torch.float32'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | grid_sampler_2d | dtype_int64 | [[2, 3, 5, 20], [2, 13, 10, 2]] | ['torch.int64', 'torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | grid_sampler_2d | dtype_bool | [[2, 3, 5, 20], [2, 13, 10, 2]] | ['torch.bool', 'torch.float32'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | std | huge | [[5, 5, 5]] | ['torch.float32'] | [value] output[0]: NaN/Inf pattern differs from the float64 truth | True |
| decomp | std | huge | [[5, 5]] | ['torch.float32'] | [value] output[0]: NaN/Inf pattern differs from the float64 truth | True |
| decomp | nn.functional.nll_loss | dtype_int64 | [[3], []] | ['torch.int64', 'torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.huber_loss | dtype_int64 | [[5, 5, 5], [5, 5, 5]] | ['torch.int64', 'torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.huber_loss | dtype_bool | [[5, 5, 5], [5, 5, 5]] | ['torch.bool', 'torch.float32'] | [exception] ref raised RuntimeError, test returned normally | True |
| decomp | nn.functional.pixel_unshuffle | empty_dim0 | [[0, 1, 6, 6]] | ['torch.float32'] | [metadata] output[0].shape: (0, 1, 6, 6) vs (0, 9, 2, 2) | True |
| meta | nn.functional.pixel_unshuffle | empty_dim0 | [[0, 1, 6, 6]] | ['torch.float32'] | output[0] shape (0, 9, 2, 2) vs real (0, 1, 6, 6) | None |
| decomp | nn.functional.pixel_unshuffle | empty_last | [[1, 1, 6, 0]] | ['torch.float32'] | [metadata] output[0].shape: (1, 1, 6, 0) vs (1, 9, 2, 0) | True |
| meta | nn.functional.pixel_unshuffle | empty_last | [[1, 1, 6, 0]] | ['torch.float32'] | output[0] shape (1, 9, 2, 0) vs real (1, 1, 6, 0) | None |
| meta_stride | nn.functional.channel_shuffle | channels_last | [[2, 6, 8, 8]] | ['torch.float32'] | output[0] stride (384, 64, 8, 1) vs real (384, 1, 48, 6) | None |
| meta_stride | nn.functional.channel_shuffle | channels_last | [[1, 4, 10, 10]] | ['torch.float32'] | output[0] stride (400, 100, 10, 1) vs real (400, 1, 40, 4) | None |
| decomp | linalg.cross | dtype_bool | [[5, 3, 5], [5, 3, 5]] | ['torch.bool', 'torch.float32'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | linalg.pinv | dtype_bool | [[2, 3, 1], [2, 50, 1]] | ['torch.bool', 'torch.float32'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | masked.softmax | dtype_int64 | [[5, 10, 5]] | ['torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | masked.log_softmax | dtype_int64 | [[5]] | ['torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | masked.softmin | dtype_int64 | [[5]] | ['torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | masked.logaddexp | dtype_int64 | [[5, 10, 5], [5, 10, 5]] | ['torch.int64', 'torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | bmm | size1_dim0 | [[1, 7, 1], [3, 1, 11]] | ['torch.float32', 'torch.float32'] | [exception] ref raised RuntimeError, test returned normally | False |
| decomp | bmm | dtype_bool | [[3, 7, 1], [3, 1, 11]] | ['torch.bool', 'torch.float32'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | bmm | dtype_bool | [[8, 128, 1], [8, 1, 256]] | ['torch.bool', 'torch.float32'] | [exception] ref raised RuntimeError, test returned normally | False |
