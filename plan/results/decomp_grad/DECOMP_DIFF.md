# Decomposition / meta differential

- operators: 570, samples: 570, input variants: 7979
- variants where at least one decomposition ran: 7383
- decomposition mismatches: 237  (confirmed by torch.compile: 122)
- meta / fake-tensor mismatches: 200 (data-dependent ops that cannot run on fake tensors, not counted: 85)
- wall: 814.3 s

- operators whose child interpreter died (native abort / timeout): nn.functional.pdist (rc 3221225620)

| kind | op | variant | shapes | dtypes | detail | confirmed |
|---|---|---|---|---|---|---|
| decomp | bmm | zero_dim | [[], [10, 10, 5]] | ['torch.float32', 'torch.float32'] | [exception] exception type differs: RuntimeError vs IndexError :: tuple index out of range | False |
| decomp | mv | zero_dim | [[], [10]] | ['torch.float32', 'torch.float32'] | [exception] exception type differs: IndexError vs RuntimeError :: matrix @ vector expected | True |
| decomp | mv | dtype_bool | [[5, 10], [10]] | ['torch.bool', 'torch.float32'] | [exception] ref raised RuntimeError, test returned normally | True |
| decomp | bmm | zero_dim | [[], [3, 1, 11]] | ['torch.float32', 'torch.float32'] | [exception] exception type differs: RuntimeError vs IndexError :: tuple index out of range | False |
| decomp | broadcast_tensors | base | [[3], [1, 2, 1], [1, 1], [5, 1, 1]] | ['torch.float32', 'torch.float32', 'torch.float32', 'torch.float32'] | [exception] test raised TypeError, ref returned normally :: unsupported operand type(s) fo | False |
| decomp | broadcast_tensors | empty_dim0 | [[0], [1, 2, 1], [1, 1], [5, 1, 1]] | ['torch.float32', 'torch.float32', 'torch.float32', 'torch.float32'] | [exception] test raised TypeError, ref returned normally :: unsupported operand type(s) fo | False |
| decomp | broadcast_tensors | size1_dim0 | [[1], [1, 2, 1], [1, 1], [5, 1, 1]] | ['torch.float32', 'torch.float32', 'torch.float32', 'torch.float32'] | [exception] test raised TypeError, ref returned normally :: unsupported operand type(s) fo | False |
| decomp | broadcast_tensors | noncontig | [[3], [1, 2, 1], [1, 1], [5, 1, 1]] | ['torch.float32', 'torch.float32', 'torch.float32', 'torch.float32'] | [exception] test raised TypeError, ref returned normally :: unsupported operand type(s) fo | False |
| decomp | broadcast_tensors | zero_dim | [[], [1, 2, 1], [1, 1], [5, 1, 1]] | ['torch.float32', 'torch.float32', 'torch.float32', 'torch.float32'] | [exception] test raised TypeError, ref returned normally :: unsupported operand type(s) fo | False |
| decomp | broadcast_tensors | dtype_bool | [[3], [1, 2, 1], [1, 1], [5, 1, 1]] | ['torch.bool', 'torch.float32', 'torch.float32', 'torch.float32'] | [exception] test raised TypeError, ref returned normally :: unsupported operand type(s) fo | False |
| decomp | broadcast_tensors | nan_inf | [[3], [1, 2, 1], [1, 1], [5, 1, 1]] | ['torch.float32', 'torch.float32', 'torch.float32', 'torch.float32'] | [exception] test raised TypeError, ref returned normally :: unsupported operand type(s) fo | False |
| decomp | broadcast_tensors | huge | [[3], [1, 2, 1], [1, 1], [5, 1, 1]] | ['torch.float32', 'torch.float32', 'torch.float32', 'torch.float32'] | [exception] test raised TypeError, ref returned normally :: unsupported operand type(s) fo | False |
| decomp | broadcast_tensors | tiny | [[3], [1, 2, 1], [1, 1], [5, 1, 1]] | ['torch.float32', 'torch.float32', 'torch.float32', 'torch.float32'] | [exception] test raised TypeError, ref returned normally :: unsupported operand type(s) fo | False |
| decomp | broadcast_tensors | dtype_float16 | [[3], [1, 2, 1], [1, 1], [5, 1, 1]] | ['torch.float16', 'torch.float16', 'torch.float16', 'torch.float16'] | [exception] test raised TypeError, ref returned normally :: unsupported operand type(s) fo | False |
| decomp | broadcast_tensors | dtype_bfloat16 | [[3], [1, 2, 1], [1, 1], [5, 1, 1]] | ['torch.bfloat16', 'torch.bfloat16', 'torch.bfloat16', 'torch.bfloat16'] | [exception] test raised TypeError, ref returned normally :: unsupported operand type(s) fo | False |
| decomp | chunk | base | [[5, 5, 5]] | ['torch.float32'] | [exception] test raised TypeError, ref returned normally :: unsupported operand type(s) fo | False |
| decomp | chunk | empty_dim0 | [[0, 5, 5]] | ['torch.float32'] | [exception] test raised TypeError, ref returned normally :: unsupported operand type(s) fo | False |
| decomp | chunk | size1_dim0 | [[1, 5, 5]] | ['torch.float32'] | [exception] test raised TypeError, ref returned normally :: unsupported operand type(s) fo | False |
| decomp | chunk | empty_last | [[5, 5, 0]] | ['torch.float32'] | [exception] test raised TypeError, ref returned normally :: unsupported operand type(s) fo | False |
| decomp | chunk | size1_last | [[5, 5, 1]] | ['torch.float32'] | [exception] test raised TypeError, ref returned normally :: unsupported operand type(s) fo | False |
| decomp | chunk | prime_dim0 | [[7, 5, 5]] | ['torch.float32'] | [exception] test raised TypeError, ref returned normally :: unsupported operand type(s) fo | False |
| decomp | chunk | noncontig | [[5, 5, 5]] | ['torch.float32'] | [exception] test raised TypeError, ref returned normally :: unsupported operand type(s) fo | False |
| decomp | chunk | prime_all | [[7, 11, 13]] | ['torch.float32'] | [exception] test raised TypeError, ref returned normally :: unsupported operand type(s) fo | False |
| decomp | chunk | nan_inf | [[5, 5, 5]] | ['torch.float32'] | [exception] test raised TypeError, ref returned normally :: unsupported operand type(s) fo | False |
| decomp | chunk | huge | [[5, 5, 5]] | ['torch.float32'] | [exception] test raised TypeError, ref returned normally :: unsupported operand type(s) fo | False |
| decomp | chunk | tiny | [[5, 5, 5]] | ['torch.float32'] | [exception] test raised TypeError, ref returned normally :: unsupported operand type(s) fo | False |
| decomp | chunk | dtype_float16 | [[5, 5, 5]] | ['torch.float16'] | [exception] test raised TypeError, ref returned normally :: unsupported operand type(s) fo | False |
| decomp | chunk | dtype_bfloat16 | [[5, 5, 5]] | ['torch.bfloat16'] | [exception] test raised TypeError, ref returned normally :: unsupported operand type(s) fo | False |
| decomp | unsafe_chunk | base | [[5, 5, 5]] | ['torch.float32'] | [exception] test raised TypeError, ref returned normally :: unsupported operand type(s) fo | False |
| decomp | unsafe_chunk | empty_dim0 | [[0, 5, 5]] | ['torch.float32'] | [exception] test raised TypeError, ref returned normally :: unsupported operand type(s) fo | False |
| decomp | unsafe_chunk | empty_last | [[5, 5, 0]] | ['torch.float32'] | [exception] test raised TypeError, ref returned normally :: unsupported operand type(s) fo | False |
| decomp | unsafe_chunk | size1_last | [[5, 5, 1]] | ['torch.float32'] | [exception] test raised TypeError, ref returned normally :: unsupported operand type(s) fo | False |
| decomp | unsafe_chunk | prime_dim0 | [[7, 5, 5]] | ['torch.float32'] | [exception] test raised TypeError, ref returned normally :: unsupported operand type(s) fo | False |
| decomp | unsafe_chunk | noncontig | [[5, 5, 5]] | ['torch.float32'] | [exception] test raised TypeError, ref returned normally :: unsupported operand type(s) fo | False |
| decomp | unsafe_chunk | prime_all | [[7, 11, 13]] | ['torch.float32'] | [exception] test raised TypeError, ref returned normally :: unsupported operand type(s) fo | False |
| decomp | unsafe_chunk | nan_inf | [[5, 5, 5]] | ['torch.float32'] | [exception] test raised TypeError, ref returned normally :: unsupported operand type(s) fo | False |
| decomp | unsafe_chunk | huge | [[5, 5, 5]] | ['torch.float32'] | [exception] test raised TypeError, ref returned normally :: unsupported operand type(s) fo | False |
| decomp | unsafe_chunk | tiny | [[5, 5, 5]] | ['torch.float32'] | [exception] test raised TypeError, ref returned normally :: unsupported operand type(s) fo | False |
| decomp | unsafe_chunk | dtype_float16 | [[5, 5, 5]] | ['torch.float16'] | [exception] test raised TypeError, ref returned normally :: unsupported operand type(s) fo | False |
| decomp | unsafe_chunk | dtype_bfloat16 | [[5, 5, 5]] | ['torch.bfloat16'] | [exception] test raised TypeError, ref returned normally :: unsupported operand type(s) fo | False |
| decomp | cross | dtype_bool | [[5, 3, 5], [5, 3, 5]] | ['torch.bool', 'torch.float32'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | frac | dtype_int64 | [[20, 20]] | ['torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | stft | empty_last | [[3, 0]] | ['torch.float32'] | [exception] exception type differs: RuntimeError vs IndexError :: index is out of bounds f | False |
| decomp | stft | size1_last | [[3, 1]] | ['torch.float32'] | [exception] exception type differs: RuntimeError vs IndexError :: index -8 is out of bound | False |
| decomp | stft | zero_dim | [[]] | ['torch.float32'] | [exception] exception type differs: RuntimeError vs IndexError :: index -8 is out of bound | False |
| decomp | geqrf | base | [[0, 5, 5]] | ['torch.float32'] | [exception] exception type differs: NotImplementedError vs TypeError :: unsupported operan | False |
| decomp | geqrf | empty_last | [[0, 5, 0]] | ['torch.float32'] | [exception] exception type differs: NotImplementedError vs TypeError :: unsupported operan | False |
| decomp | geqrf | size1_last | [[0, 5, 1]] | ['torch.float32'] | [exception] exception type differs: NotImplementedError vs TypeError :: unsupported operan | False |
| decomp | geqrf | prime_dim0 | [[0, 5, 5]] | ['torch.float32'] | [exception] exception type differs: NotImplementedError vs TypeError :: unsupported operan | False |
| decomp | geqrf | noncontig | [[0, 5, 5]] | ['torch.float32'] | [exception] exception type differs: NotImplementedError vs TypeError :: unsupported operan | False |
| decomp | geqrf | nan_inf | [[0, 5, 5]] | ['torch.float32'] | [exception] exception type differs: NotImplementedError vs TypeError :: unsupported operan | False |
| decomp | geqrf | huge | [[0, 5, 5]] | ['torch.float32'] | [exception] exception type differs: NotImplementedError vs TypeError :: unsupported operan | False |
| decomp | geqrf | tiny | [[0, 5, 5]] | ['torch.float32'] | [exception] exception type differs: NotImplementedError vs TypeError :: unsupported operan | False |
| decomp | isin | dtype_bool | [[20], [5]] | ['torch.bool', 'torch.float32'] | [exception] ref raised RuntimeError, test returned normally | False |
| decomp | logaddexp | dtype_int64 | [[10, 1, 5], [1, 10, 5]] | ['torch.int64', 'torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | logaddexp2 | dtype_int64 | [[5, 5], [5, 5]] | ['torch.int64', 'torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | lu_unpack | base | [[3, 3, 4, 5], [3, 3, 4]] | ['torch.float32', 'torch.int32'] | [exception] test raised TypeError, ref returned normally :: unsupported operand type(s) fo | False |
| decomp | lu_unpack | noncontig | [[3, 3, 4, 5], [3, 3, 4]] | ['torch.float32', 'torch.int32'] | [exception] test raised TypeError, ref returned normally :: unsupported operand type(s) fo | False |
| decomp | lu_unpack | channels_last | [[3, 3, 4, 5], [3, 3, 4]] | ['torch.float32', 'torch.int32'] | [exception] test raised TypeError, ref returned normally :: unsupported operand type(s) fo | False |
| decomp | lu_unpack | nan_inf | [[3, 3, 4, 5], [3, 3, 4]] | ['torch.float32', 'torch.int32'] | [exception] test raised TypeError, ref returned normally :: unsupported operand type(s) fo | False |
| decomp | lu_unpack | huge | [[3, 3, 4, 5], [3, 3, 4]] | ['torch.float32', 'torch.int32'] | [exception] test raised TypeError, ref returned normally :: unsupported operand type(s) fo | False |
| decomp | lu_unpack | tiny | [[3, 3, 4, 5], [3, 3, 4]] | ['torch.float32', 'torch.int32'] | [exception] test raised TypeError, ref returned normally :: unsupported operand type(s) fo | False |
| decomp | lu_unpack | dtype_float16 | [[3, 3, 4, 5], [3, 3, 4]] | ['torch.float16', 'torch.int32'] | [exception] test raised TypeError, ref returned normally :: unsupported operand type(s) fo | False |
| decomp | lu_unpack | dtype_bfloat16 | [[3, 3, 4, 5], [3, 3, 4]] | ['torch.bfloat16', 'torch.int32'] | [exception] test raised TypeError, ref returned normally :: unsupported operand type(s) fo | False |
| decomp | var_mean | base | [[5, 5, 5]] | ['torch.float32'] | [exception] test raised TypeError, ref returned normally :: unsupported operand type(s) fo | False |
| decomp | var_mean | empty_dim0 | [[0, 5, 5]] | ['torch.float32'] | [exception] test raised TypeError, ref returned normally :: unsupported operand type(s) fo | False |
| decomp | var_mean | size1_dim0 | [[1, 5, 5]] | ['torch.float32'] | [exception] test raised TypeError, ref returned normally :: unsupported operand type(s) fo | False |
| decomp | var_mean | empty_last | [[5, 5, 0]] | ['torch.float32'] | [exception] test raised TypeError, ref returned normally :: unsupported operand type(s) fo | False |
| decomp | var_mean | size1_last | [[5, 5, 1]] | ['torch.float32'] | [exception] test raised TypeError, ref returned normally :: unsupported operand type(s) fo | False |
| decomp | var_mean | prime_dim0 | [[7, 5, 5]] | ['torch.float32'] | [exception] test raised TypeError, ref returned normally :: unsupported operand type(s) fo | False |
| decomp | var_mean | noncontig | [[5, 5, 5]] | ['torch.float32'] | [exception] test raised TypeError, ref returned normally :: unsupported operand type(s) fo | False |
| decomp | var_mean | prime_all | [[7, 11, 13]] | ['torch.float32'] | [exception] test raised TypeError, ref returned normally :: unsupported operand type(s) fo | False |
| decomp | var_mean | nan_inf | [[5, 5, 5]] | ['torch.float32'] | [exception] test raised TypeError, ref returned normally :: unsupported operand type(s) fo | False |
| decomp | var_mean | huge | [[5, 5, 5]] | ['torch.float32'] | [exception] test raised TypeError, ref returned normally :: unsupported operand type(s) fo | False |
| decomp | var_mean | tiny | [[5, 5, 5]] | ['torch.float32'] | [exception] test raised TypeError, ref returned normally :: unsupported operand type(s) fo | False |
| decomp | var_mean | dtype_float16 | [[5, 5, 5]] | ['torch.float16'] | [exception] test raised TypeError, ref returned normally :: unsupported operand type(s) fo | False |
| decomp | var_mean | dtype_bfloat16 | [[5, 5, 5]] | ['torch.bfloat16'] | [exception] test raised TypeError, ref returned normally :: unsupported operand type(s) fo | False |
| decomp | var_mean | base | [[0]] | ['torch.float32'] | [exception] test raised TypeError, ref returned normally :: unsupported operand type(s) fo | True |
| decomp | var_mean | noncontig | [[0]] | ['torch.float32'] | [exception] test raised TypeError, ref returned normally :: unsupported operand type(s) fo | True |
| decomp | var_mean | nan_inf | [[0]] | ['torch.float32'] | [exception] test raised TypeError, ref returned normally :: unsupported operand type(s) fo | True |
| decomp | var_mean | huge | [[0]] | ['torch.float32'] | [exception] test raised TypeError, ref returned normally :: unsupported operand type(s) fo | True |
| decomp | var_mean | tiny | [[0]] | ['torch.float32'] | [exception] test raised TypeError, ref returned normally :: unsupported operand type(s) fo | True |
| decomp | var_mean | dtype_float16 | [[0]] | ['torch.float16'] | [exception] test raised TypeError, ref returned normally :: unsupported operand type(s) fo | True |
| decomp | var_mean | dtype_bfloat16 | [[0]] | ['torch.bfloat16'] | [exception] test raised TypeError, ref returned normally :: unsupported operand type(s) fo | True |
| decomp | var_mean | base | [[5, 5, 5]] | ['torch.float32'] | [exception] test raised TypeError, ref returned normally :: unsupported operand type(s) fo | False |
| decomp | var_mean | empty_dim0 | [[0, 5, 5]] | ['torch.float32'] | [exception] test raised TypeError, ref returned normally :: unsupported operand type(s) fo | False |
| decomp | var_mean | size1_dim0 | [[1, 5, 5]] | ['torch.float32'] | [exception] test raised TypeError, ref returned normally :: unsupported operand type(s) fo | False |
| decomp | var_mean | empty_last | [[5, 5, 0]] | ['torch.float32'] | [exception] test raised TypeError, ref returned normally :: unsupported operand type(s) fo | False |
| decomp | var_mean | size1_last | [[5, 5, 1]] | ['torch.float32'] | [exception] test raised TypeError, ref returned normally :: unsupported operand type(s) fo | False |
| decomp | var_mean | prime_dim0 | [[7, 5, 5]] | ['torch.float32'] | [exception] test raised TypeError, ref returned normally :: unsupported operand type(s) fo | False |
| decomp | var_mean | noncontig | [[5, 5, 5]] | ['torch.float32'] | [exception] test raised TypeError, ref returned normally :: unsupported operand type(s) fo | False |
| decomp | var_mean | prime_all | [[7, 11, 13]] | ['torch.float32'] | [exception] test raised TypeError, ref returned normally :: unsupported operand type(s) fo | False |
| decomp | var_mean | nan_inf | [[5, 5, 5]] | ['torch.float32'] | [exception] test raised TypeError, ref returned normally :: unsupported operand type(s) fo | False |
| decomp | var_mean | huge | [[5, 5, 5]] | ['torch.float32'] | [exception] test raised TypeError, ref returned normally :: unsupported operand type(s) fo | False |
| decomp | var_mean | tiny | [[5, 5, 5]] | ['torch.float32'] | [exception] test raised TypeError, ref returned normally :: unsupported operand type(s) fo | False |
| decomp | var_mean | dtype_float16 | [[5, 5, 5]] | ['torch.float16'] | [exception] test raised TypeError, ref returned normally :: unsupported operand type(s) fo | False |
| decomp | var_mean | dtype_bfloat16 | [[5, 5, 5]] | ['torch.bfloat16'] | [exception] test raised TypeError, ref returned normally :: unsupported operand type(s) fo | False |
| decomp | var_mean | base | [[0]] | ['torch.float32'] | [exception] test raised TypeError, ref returned normally :: unsupported operand type(s) fo | True |
| decomp | var_mean | noncontig | [[0]] | ['torch.float32'] | [exception] test raised TypeError, ref returned normally :: unsupported operand type(s) fo | True |
| decomp | var_mean | nan_inf | [[0]] | ['torch.float32'] | [exception] test raised TypeError, ref returned normally :: unsupported operand type(s) fo | True |
| decomp | var_mean | huge | [[0]] | ['torch.float32'] | [exception] test raised TypeError, ref returned normally :: unsupported operand type(s) fo | True |
| decomp | var_mean | tiny | [[0]] | ['torch.float32'] | [exception] test raised TypeError, ref returned normally :: unsupported operand type(s) fo | True |
| decomp | var_mean | dtype_float16 | [[0]] | ['torch.float16'] | [exception] test raised TypeError, ref returned normally :: unsupported operand type(s) fo | True |
| decomp | var_mean | dtype_bfloat16 | [[0]] | ['torch.bfloat16'] | [exception] test raised TypeError, ref returned normally :: unsupported operand type(s) fo | True |
| decomp | std_mean | base | [[0, 5]] | ['torch.float32'] | [exception] test raised TypeError, ref returned normally :: unsupported operand type(s) fo | False |
| decomp | std_mean | empty_last | [[0, 0]] | ['torch.float32'] | [exception] test raised TypeError, ref returned normally :: unsupported operand type(s) fo | False |
| decomp | std_mean | size1_last | [[0, 1]] | ['torch.float32'] | [exception] test raised TypeError, ref returned normally :: unsupported operand type(s) fo | True |
| decomp | std_mean | prime_dim0 | [[0, 5]] | ['torch.float32'] | [exception] test raised TypeError, ref returned normally :: unsupported operand type(s) fo | False |
| decomp | std_mean | noncontig | [[0, 5]] | ['torch.float32'] | [exception] test raised TypeError, ref returned normally :: unsupported operand type(s) fo | False |
| decomp | std_mean | nan_inf | [[0, 5]] | ['torch.float32'] | [exception] test raised TypeError, ref returned normally :: unsupported operand type(s) fo | False |
| decomp | std_mean | huge | [[0, 5]] | ['torch.float32'] | [exception] test raised TypeError, ref returned normally :: unsupported operand type(s) fo | False |
| decomp | std_mean | tiny | [[0, 5]] | ['torch.float32'] | [exception] test raised TypeError, ref returned normally :: unsupported operand type(s) fo | False |
| decomp | std_mean | dtype_float16 | [[0, 5]] | ['torch.float16'] | [exception] test raised TypeError, ref returned normally :: unsupported operand type(s) fo | False |
| decomp | std_mean | dtype_bfloat16 | [[0, 5]] | ['torch.bfloat16'] | [exception] test raised TypeError, ref returned normally :: unsupported operand type(s) fo | False |
| decomp | std_mean | base | [[0, 5]] | ['torch.float32'] | [exception] test raised TypeError, ref returned normally :: unsupported operand type(s) fo | True |
| decomp | std_mean | empty_last | [[0, 0]] | ['torch.float32'] | [exception] test raised TypeError, ref returned normally :: unsupported operand type(s) fo | True |
| decomp | std_mean | size1_last | [[0, 1]] | ['torch.float32'] | [exception] test raised TypeError, ref returned normally :: unsupported operand type(s) fo | True |
| decomp | std_mean | prime_dim0 | [[0, 5]] | ['torch.float32'] | [exception] test raised TypeError, ref returned normally :: unsupported operand type(s) fo | True |
| decomp | std_mean | noncontig | [[0, 5]] | ['torch.float32'] | [exception] test raised TypeError, ref returned normally :: unsupported operand type(s) fo | True |
| decomp | std_mean | nan_inf | [[0, 5]] | ['torch.float32'] | [exception] test raised TypeError, ref returned normally :: unsupported operand type(s) fo | True |
| decomp | std_mean | huge | [[0, 5]] | ['torch.float32'] | [exception] test raised TypeError, ref returned normally :: unsupported operand type(s) fo | True |
| decomp | std_mean | tiny | [[0, 5]] | ['torch.float32'] | [exception] test raised TypeError, ref returned normally :: unsupported operand type(s) fo | True |
| decomp | std_mean | dtype_float16 | [[0, 5]] | ['torch.float16'] | [exception] test raised TypeError, ref returned normally :: unsupported operand type(s) fo | True |
| decomp | std_mean | dtype_bfloat16 | [[0, 5]] | ['torch.bfloat16'] | [exception] test raised TypeError, ref returned normally :: unsupported operand type(s) fo | True |
| decomp | meshgrid | base | [[3], [], [3]] | ['torch.float32', 'torch.float32', 'torch.float32'] | [exception] test raised TypeError, ref returned normally :: unsupported operand type(s) fo | False |
| decomp | meshgrid | empty_dim0 | [[0], [], [3]] | ['torch.float32', 'torch.float32', 'torch.float32'] | [exception] test raised TypeError, ref returned normally :: unsupported operand type(s) fo | False |
| decomp | meshgrid | size1_dim0 | [[1], [], [3]] | ['torch.float32', 'torch.float32', 'torch.float32'] | [exception] test raised TypeError, ref returned normally :: unsupported operand type(s) fo | False |
| decomp | meshgrid | noncontig | [[3], [], [3]] | ['torch.float32', 'torch.float32', 'torch.float32'] | [exception] test raised TypeError, ref returned normally :: unsupported operand type(s) fo | False |
| decomp | meshgrid | zero_dim | [[], [], [3]] | ['torch.float32', 'torch.float32', 'torch.float32'] | [exception] test raised TypeError, ref returned normally :: unsupported operand type(s) fo | False |
| decomp | meshgrid | nan_inf | [[3], [], [3]] | ['torch.float32', 'torch.float32', 'torch.float32'] | [exception] test raised TypeError, ref returned normally :: unsupported operand type(s) fo | False |
| decomp | meshgrid | huge | [[3], [], [3]] | ['torch.float32', 'torch.float32', 'torch.float32'] | [exception] test raised TypeError, ref returned normally :: unsupported operand type(s) fo | False |
| decomp | meshgrid | tiny | [[3], [], [3]] | ['torch.float32', 'torch.float32', 'torch.float32'] | [exception] test raised TypeError, ref returned normally :: unsupported operand type(s) fo | False |
| decomp | meshgrid | dtype_float16 | [[3], [], [3]] | ['torch.float16', 'torch.float16', 'torch.float16'] | [exception] test raised TypeError, ref returned normally :: unsupported operand type(s) fo | False |
| decomp | meshgrid | dtype_bfloat16 | [[3], [], [3]] | ['torch.bfloat16', 'torch.bfloat16', 'torch.bfloat16'] | [exception] test raised TypeError, ref returned normally :: unsupported operand type(s) fo | False |
| decomp | softmax | dtype_int64 | [[5, 5]] | ['torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.softmin | dtype_int64 | [[5, 0, 0]] | ['torch.int64'] | [exception] test raised RuntimeError, ref returned normally :: value cannot be converted t | True |
| decomp | nn.functional.cross_entropy | empty_last | [[2, 0], [2]] | ['torch.float32', 'torch.int64'] | [exception] exception type differs: IndexError vs RuntimeError :: index 0 is out of bounds | True |
| decomp | nn.functional.cross_entropy | dtype_int64 | [[2, 3], [2]] | ['torch.int64', 'torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.linear_cross_entropy | base | [[8], [8, 8], []] | ['torch.float32', 'torch.float32', 'torch.int64'] | [exception] test raised TypeError, ref returned normally :: mm() got an unexpected keyword | False |
| meta | nn.functional.linear_cross_entropy | base | [[8], [8, 8], []] | ['torch.float32', 'torch.float32', 'torch.int64'] | fake-tensor path raised AssertionError: Please convert all Tensors to FakeTensors first or | None |
| decomp | nn.functional.linear_cross_entropy | noncontig | [[8], [8, 8], []] | ['torch.float32', 'torch.float32', 'torch.int64'] | [exception] test raised TypeError, ref returned normally :: mm() got an unexpected keyword | False |
| meta | nn.functional.linear_cross_entropy | noncontig | [[8], [8, 8], []] | ['torch.float32', 'torch.float32', 'torch.int64'] | fake-tensor path raised AssertionError: Please convert all Tensors to FakeTensors first or | None |
| decomp | nn.functional.linear_cross_entropy | nan_inf | [[8], [8, 8], []] | ['torch.float32', 'torch.float32', 'torch.int64'] | [exception] test raised TypeError, ref returned normally :: mm() got an unexpected keyword | False |
| meta | nn.functional.linear_cross_entropy | nan_inf | [[8], [8, 8], []] | ['torch.float32', 'torch.float32', 'torch.int64'] | fake-tensor path raised AssertionError: Please convert all Tensors to FakeTensors first or | None |
| decomp | nn.functional.linear_cross_entropy | huge | [[8], [8, 8], []] | ['torch.float32', 'torch.float32', 'torch.int64'] | [exception] test raised TypeError, ref returned normally :: mm() got an unexpected keyword | False |
| meta | nn.functional.linear_cross_entropy | huge | [[8], [8, 8], []] | ['torch.float32', 'torch.float32', 'torch.int64'] | fake-tensor path raised AssertionError: Please convert all Tensors to FakeTensors first or | None |
| decomp | nn.functional.linear_cross_entropy | tiny | [[8], [8, 8], []] | ['torch.float32', 'torch.float32', 'torch.int64'] | [exception] test raised TypeError, ref returned normally :: mm() got an unexpected keyword | False |
| meta | nn.functional.linear_cross_entropy | tiny | [[8], [8, 8], []] | ['torch.float32', 'torch.float32', 'torch.int64'] | fake-tensor path raised AssertionError: Please convert all Tensors to FakeTensors first or | None |
| decomp | nn.functional.linear_cross_entropy | dtype_float16 | [[8], [8, 8], []] | ['torch.float16', 'torch.float16', 'torch.int64'] | [exception] test raised TypeError, ref returned normally :: mm() got an unexpected keyword | False |
| meta | nn.functional.linear_cross_entropy | dtype_float16 | [[8], [8, 8], []] | ['torch.float16', 'torch.float16', 'torch.int64'] | fake-tensor path raised AssertionError: Please convert all Tensors to FakeTensors first or | None |
| decomp | nn.functional.linear_cross_entropy | dtype_bfloat16 | [[8], [8, 8], []] | ['torch.bfloat16', 'torch.bfloat16', 'torch.int64'] | [exception] test raised TypeError, ref returned normally :: mm() got an unexpected keyword | False |
| meta | nn.functional.linear_cross_entropy | dtype_bfloat16 | [[8], [8, 8], []] | ['torch.bfloat16', 'torch.bfloat16', 'torch.int64'] | fake-tensor path raised AssertionError: Please convert all Tensors to FakeTensors first or | None |
| meta | nn.functional.linear_cross_entropy | base | [[8], [8, 8], []] | ['torch.float32', 'torch.float32', 'torch.int64'] | fake-tensor path raised AssertionError: Please convert all Tensors to FakeTensors first or | None |
| meta | nn.functional.linear_cross_entropy | noncontig | [[8], [8, 8], []] | ['torch.float32', 'torch.float32', 'torch.int64'] | fake-tensor path raised AssertionError: Please convert all Tensors to FakeTensors first or | None |
| decomp | nn.functional.linear_cross_entropy | dtype_int64 | [[8], [8, 8], []] | ['torch.int64', 'torch.int64', 'torch.int64'] | [exception] ref raised RuntimeError, test returned normally | True |
| decomp | nn.functional.linear_cross_entropy | dtype_bool | [[8], [8, 8], []] | ['torch.bool', 'torch.float32', 'torch.int64'] | [exception] ref raised RuntimeError, test returned normally | True |
| meta | nn.functional.linear_cross_entropy | nan_inf | [[8], [8, 8], []] | ['torch.float32', 'torch.float32', 'torch.int64'] | fake-tensor path raised AssertionError: Please convert all Tensors to FakeTensors first or | None |
| meta | nn.functional.linear_cross_entropy | huge | [[8], [8, 8], []] | ['torch.float32', 'torch.float32', 'torch.int64'] | fake-tensor path raised AssertionError: Please convert all Tensors to FakeTensors first or | None |
| meta | nn.functional.linear_cross_entropy | tiny | [[8], [8, 8], []] | ['torch.float32', 'torch.float32', 'torch.int64'] | fake-tensor path raised AssertionError: Please convert all Tensors to FakeTensors first or | None |
| meta | nn.functional.linear_cross_entropy | base | [[3], [4, 3], []] | ['torch.float32', 'torch.float32', 'torch.int64'] | fake-tensor path raised AssertionError: Please convert all Tensors to FakeTensors first or | None |
| meta | nn.functional.linear_cross_entropy | noncontig | [[3], [4, 3], []] | ['torch.float32', 'torch.float32', 'torch.int64'] | fake-tensor path raised AssertionError: Please convert all Tensors to FakeTensors first or | None |
| meta | nn.functional.linear_cross_entropy | nan_inf | [[3], [4, 3], []] | ['torch.float32', 'torch.float32', 'torch.int64'] | fake-tensor path raised AssertionError: Please convert all Tensors to FakeTensors first or | None |
| meta | nn.functional.linear_cross_entropy | huge | [[3], [4, 3], []] | ['torch.float32', 'torch.float32', 'torch.int64'] | fake-tensor path raised AssertionError: Please convert all Tensors to FakeTensors first or | None |
| meta | nn.functional.linear_cross_entropy | tiny | [[3], [4, 3], []] | ['torch.float32', 'torch.float32', 'torch.int64'] | fake-tensor path raised AssertionError: Please convert all Tensors to FakeTensors first or | None |
| meta | nn.functional.linear_cross_entropy | dtype_float16 | [[3], [4, 3], []] | ['torch.float16', 'torch.float16', 'torch.int64'] | fake-tensor path raised AssertionError: Please convert all Tensors to FakeTensors first or | None |
| meta | nn.functional.linear_cross_entropy | dtype_bfloat16 | [[3], [4, 3], []] | ['torch.bfloat16', 'torch.bfloat16', 'torch.int64'] | fake-tensor path raised AssertionError: Please convert all Tensors to FakeTensors first or | None |
| meta | nn.functional.linear_cross_entropy | base | [[8, 8], [8, 8], [8, 8]] | ['torch.float32', 'torch.float32', 'torch.float32'] | fake-tensor path raised AssertionError: Please convert all Tensors to FakeTensors first or | None |
| meta | nn.functional.linear_cross_entropy | noncontig | [[8, 8], [8, 8], [8, 8]] | ['torch.float32', 'torch.float32', 'torch.float32'] | fake-tensor path raised AssertionError: Please convert all Tensors to FakeTensors first or | None |
| meta | nn.functional.linear_cross_entropy | nan_inf | [[8, 8], [8, 8], [8, 8]] | ['torch.float32', 'torch.float32', 'torch.float32'] | fake-tensor path raised AssertionError: Please convert all Tensors to FakeTensors first or | None |
| meta | nn.functional.linear_cross_entropy | huge | [[8, 8], [8, 8], [8, 8]] | ['torch.float32', 'torch.float32', 'torch.float32'] | fake-tensor path raised AssertionError: Please convert all Tensors to FakeTensors first or | None |
| meta | nn.functional.linear_cross_entropy | tiny | [[8, 8], [8, 8], [8, 8]] | ['torch.float32', 'torch.float32', 'torch.float32'] | fake-tensor path raised AssertionError: Please convert all Tensors to FakeTensors first or | None |
| meta | nn.functional.binary_cross_entropy_with_logits | base | [[5, 5], [5, 5]] | ['torch.float32', 'torch.float32'] | fake-tensor path raised AssertionError: Please convert all Tensors to FakeTensors first or | None |
| meta | nn.functional.binary_cross_entropy_with_logits | noncontig | [[5, 5], [5, 5]] | ['torch.float32', 'torch.float32'] | fake-tensor path raised AssertionError: Please convert all Tensors to FakeTensors first or | None |
| meta | nn.functional.binary_cross_entropy_with_logits | nan_inf | [[5, 5], [5, 5]] | ['torch.float32', 'torch.float32'] | fake-tensor path raised AssertionError: Please convert all Tensors to FakeTensors first or | None |
| meta | nn.functional.binary_cross_entropy_with_logits | huge | [[5, 5], [5, 5]] | ['torch.float32', 'torch.float32'] | fake-tensor path raised AssertionError: Please convert all Tensors to FakeTensors first or | None |
| meta | nn.functional.binary_cross_entropy_with_logits | tiny | [[5, 5], [5, 5]] | ['torch.float32', 'torch.float32'] | fake-tensor path raised AssertionError: Please convert all Tensors to FakeTensors first or | None |
| meta | nn.functional.binary_cross_entropy_with_logits | dtype_float16 | [[5, 5], [5, 5]] | ['torch.float16', 'torch.float16'] | fake-tensor path raised AssertionError: Please convert all Tensors to FakeTensors first or | None |
| meta | nn.functional.binary_cross_entropy_with_logits | dtype_bfloat16 | [[5, 5], [5, 5]] | ['torch.bfloat16', 'torch.bfloat16'] | fake-tensor path raised AssertionError: Please convert all Tensors to FakeTensors first or | None |
| meta | nn.functional.instance_norm | base | [[3, 2, 3, 4]] | ['torch.float32'] | fake-tensor path raised AssertionError: Please convert all Tensors to FakeTensors first or | None |
| meta | nn.functional.instance_norm | size1_dim0 | [[1, 2, 3, 4]] | ['torch.float32'] | fake-tensor path raised AssertionError: Please convert all Tensors to FakeTensors first or | None |
| meta | nn.functional.instance_norm | empty_last | [[3, 2, 3, 0]] | ['torch.float32'] | fake-tensor path raised AssertionError: Please convert all Tensors to FakeTensors first or | None |
| meta | nn.functional.instance_norm | size1_last | [[3, 2, 3, 1]] | ['torch.float32'] | fake-tensor path raised AssertionError: Please convert all Tensors to FakeTensors first or | None |
| meta | nn.functional.instance_norm | prime_dim0 | [[7, 2, 3, 4]] | ['torch.float32'] | fake-tensor path raised AssertionError: Please convert all Tensors to FakeTensors first or | None |
| meta | nn.functional.instance_norm | noncontig | [[3, 2, 3, 4]] | ['torch.float32'] | fake-tensor path raised AssertionError: Please convert all Tensors to FakeTensors first or | None |
| meta | nn.functional.instance_norm | channels_last | [[3, 2, 3, 4]] | ['torch.float32'] | fake-tensor path raised AssertionError: Please convert all Tensors to FakeTensors first or | None |
| meta | nn.functional.instance_norm | nan_inf | [[3, 2, 3, 4]] | ['torch.float32'] | fake-tensor path raised AssertionError: Please convert all Tensors to FakeTensors first or | None |
| meta | nn.functional.instance_norm | huge | [[3, 2, 3, 4]] | ['torch.float32'] | fake-tensor path raised AssertionError: Please convert all Tensors to FakeTensors first or | None |
| meta | nn.functional.instance_norm | tiny | [[3, 2, 3, 4]] | ['torch.float32'] | fake-tensor path raised AssertionError: Please convert all Tensors to FakeTensors first or | None |
| meta | nn.functional.instance_norm | dtype_float16 | [[3, 2, 3, 4]] | ['torch.float16'] | fake-tensor path raised AssertionError: Please convert all Tensors to FakeTensors first or | None |
| meta | nn.functional.instance_norm | dtype_bfloat16 | [[3, 2, 3, 4]] | ['torch.bfloat16'] | fake-tensor path raised AssertionError: Please convert all Tensors to FakeTensors first or | None |
| decomp | nn.functional.pad | empty_last | [[1, 3, 0]] | ['torch.float32'] | [exception] exception type differs: RuntimeError vs IndexError :: index is out of bounds f | False |
| decomp | nn.functional.pad | size1_last | [[1, 3, 1]] | ['torch.float32'] | [exception] exception type differs: RuntimeError vs IndexError :: index -2 is out of bound | False |
| decomp | nn.functional.pad | dtype_bool | [[1, 3, 3]] | ['torch.bool'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.pad | empty_last | [[0, 3, 3, 0]] | ['torch.float32'] | [exception] exception type differs: RuntimeError vs IndexError :: index is out of bounds f | False |
| decomp | nn.functional.pad | dtype_bool | [[0, 3, 3, 3]] | ['torch.bool'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.pad | empty_last | [[5, 6, 4, 0]] | ['torch.float32'] | [exception] exception type differs: RuntimeError vs IndexError :: index is out of bounds f | False |
| meta_stride | nn.functional.pad | channels_last | [[5, 6, 4, 4]] | ['torch.float32'] | output[1] stride (96, 16, 4, 1) vs real (96, 1, 24, 6) | None |
| decomp | nn.functional.pad | dtype_bool | [[5, 6, 4, 4]] | ['torch.bool'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.hardswish | dtype_int64 | [[10, 10]] | ['torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.hardswish | dtype_bool | [[10, 10]] | ['torch.bool'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.hardswish | nan_inf | [[10, 10]] | ['torch.float32'] | [value] output[1]: NaN/Inf pattern differs from the float64 truth | True |
| decomp | nn.functional.unfold | dtype_int64 | [[0, 1, 5, 5]] | ['torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| meta | nn.functional.interpolate | empty_dim0 | [[0, 3, 4]] | ['torch.float32'] | fake-tensor path raised TypeError: cond must be a bool, but got <class 'int'> | None |
| decomp | nn.functional.interpolate | empty_last | [[2, 3, 0]] | ['torch.float32'] | [exception] exception type differs: RuntimeError vs ZeroDivisionError :: division by zero | True |
| decomp | nn.functional.interpolate | dtype_int64 | [[2, 3, 4]] | ['torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.interpolate | dtype_bool | [[2, 3, 4]] | ['torch.bool'] | [exception] ref raised NotImplementedError, test returned normally | True |
| meta | nn.functional.interpolate | empty_dim0 | [[0, 3, 4]] | ['torch.float32'] | fake-tensor path raised TypeError: cond must be a bool, but got <class 'int'> | None |
| decomp | nn.functional.interpolate | empty_last | [[2, 3, 0]] | ['torch.float32'] | [exception] exception type differs: RuntimeError vs ZeroDivisionError :: division by zero | True |
| decomp | nn.functional.interpolate | dtype_int64 | [[2, 3, 4]] | ['torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.interpolate | dtype_bool | [[2, 3, 4]] | ['torch.bool'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.interpolate | dtype_int64 | [[2, 3, 4]] | ['torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.interpolate | dtype_bool | [[2, 3, 4]] | ['torch.bool'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.soft_margin_loss | dtype_int64 | [[], []] | ['torch.int64', 'torch.int64'] | [exception] ref raised RuntimeError, test returned normally | True |
| meta | nn.functional.upsample_nearest | empty_dim0 | [[0, 3, 4, 4, 4]] | ['torch.float32'] | fake-tensor path raised TypeError: cond must be a bool, but got <class 'int'> | None |
| decomp | nn.functional.upsample_nearest | empty_last | [[2, 3, 4, 4, 0]] | ['torch.float32'] | [exception] exception type differs: RuntimeError vs ZeroDivisionError :: division by zero | True |
| decomp | nn.functional.upsample_nearest | dtype_int64 | [[2, 3, 4, 4, 4]] | ['torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.upsample_nearest | dtype_bool | [[2, 3, 4, 4, 4]] | ['torch.bool'] | [exception] ref raised NotImplementedError, test returned normally | True |
| meta | nn.functional.multi_margin_loss | base | [[10, 5], [10]] | ['torch.float32', 'torch.int64'] | fake-tensor path raised AssertionError: Please convert all Tensors to FakeTensors first or | None |
| meta | nn.functional.multi_margin_loss | noncontig | [[10, 5], [10]] | ['torch.float32', 'torch.int64'] | fake-tensor path raised AssertionError: Please convert all Tensors to FakeTensors first or | None |
| decomp | nn.functional.multi_margin_loss | dtype_int64 | [[10, 5], [10]] | ['torch.int64', 'torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| meta | nn.functional.multi_margin_loss | nan_inf | [[10, 5], [10]] | ['torch.float32', 'torch.int64'] | fake-tensor path raised AssertionError: Please convert all Tensors to FakeTensors first or | None |
| meta | nn.functional.multi_margin_loss | huge | [[10, 5], [10]] | ['torch.float32', 'torch.int64'] | fake-tensor path raised AssertionError: Please convert all Tensors to FakeTensors first or | None |
| meta | nn.functional.multi_margin_loss | tiny | [[10, 5], [10]] | ['torch.float32', 'torch.int64'] | fake-tensor path raised AssertionError: Please convert all Tensors to FakeTensors first or | None |
| decomp | nn.functional.multilabel_margin_loss | dtype_int64 | [[], []] | ['torch.int64', 'torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| meta | nn.functional.multilabel_soft_margin_loss | base | [[5, 5], [5, 5]] | ['torch.float32', 'torch.float32'] | fake-tensor path raised AssertionError: Please convert all Tensors to FakeTensors first or | None |
| meta | nn.functional.multilabel_soft_margin_loss | size1_dim0 | [[1, 5], [5, 5]] | ['torch.float32', 'torch.float32'] | fake-tensor path raised AssertionError: Please convert all Tensors to FakeTensors first or | None |
| meta | nn.functional.multilabel_soft_margin_loss | size1_last | [[5, 1], [5, 5]] | ['torch.float32', 'torch.float32'] | fake-tensor path raised AssertionError: Please convert all Tensors to FakeTensors first or | None |
| meta | nn.functional.multilabel_soft_margin_loss | noncontig | [[5, 5], [5, 5]] | ['torch.float32', 'torch.float32'] | fake-tensor path raised AssertionError: Please convert all Tensors to FakeTensors first or | None |
| decomp | nn.functional.multilabel_soft_margin_loss | dtype_int64 | [[5, 5], [5, 5]] | ['torch.int64', 'torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| meta | nn.functional.multilabel_soft_margin_loss | nan_inf | [[5, 5], [5, 5]] | ['torch.float32', 'torch.float32'] | fake-tensor path raised AssertionError: Please convert all Tensors to FakeTensors first or | None |
| meta | nn.functional.multilabel_soft_margin_loss | huge | [[5, 5], [5, 5]] | ['torch.float32', 'torch.float32'] | fake-tensor path raised AssertionError: Please convert all Tensors to FakeTensors first or | None |
| meta | nn.functional.multilabel_soft_margin_loss | tiny | [[5, 5], [5, 5]] | ['torch.float32', 'torch.float32'] | fake-tensor path raised AssertionError: Please convert all Tensors to FakeTensors first or | None |
| meta | nn.functional.multilabel_soft_margin_loss | dtype_float16 | [[5, 5], [5, 5]] | ['torch.float16', 'torch.float16'] | fake-tensor path raised AssertionError: Please convert all Tensors to FakeTensors first or | None |
| meta | nn.functional.multilabel_soft_margin_loss | dtype_bfloat16 | [[5, 5], [5, 5]] | ['torch.bfloat16', 'torch.bfloat16'] | fake-tensor path raised AssertionError: Please convert all Tensors to FakeTensors first or | None |
| decomp | max_pool2d_with_indices_backward | dtype_int64 | [[2, 2, 6, 6]] | ['torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.max_unpool1d | dtype_int64 | [[1, 2, 4], [1, 2, 4]] | ['torch.int64', 'torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.max_unpool1d | dtype_bool | [[1, 2, 4], [1, 2, 4]] | ['torch.bool', 'torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.max_unpool1d | dtype_int64 | [[1, 2, 2], [1, 2, 2]] | ['torch.int64', 'torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.max_unpool1d | dtype_bool | [[1, 2, 2], [1, 2, 2]] | ['torch.bool', 'torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.max_unpool2d | dtype_int64 | [[1, 2, 2, 7], [1, 2, 2, 7]] | ['torch.int64', 'torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.max_unpool2d | dtype_bool | [[1, 2, 2, 7], [1, 2, 2, 7]] | ['torch.bool', 'torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.max_unpool2d | dtype_int64 | [[1, 2, 1, 3], [1, 2, 1, 3]] | ['torch.int64', 'torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.max_unpool2d | dtype_bool | [[1, 2, 1, 3], [1, 2, 1, 3]] | ['torch.bool', 'torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.max_unpool3d | dtype_int64 | [[1, 2, 2, 4, 2], [1, 2, 2, 4, 2]] | ['torch.int64', 'torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.max_unpool3d | dtype_bool | [[1, 2, 2, 4, 2], [1, 2, 2, 4, 2]] | ['torch.bool', 'torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.max_unpool3d | dtype_int64 | [[1, 2, 1, 2, 2], [1, 2, 1, 2, 2]] | ['torch.int64', 'torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.max_unpool3d | dtype_bool | [[1, 2, 1, 2, 2], [1, 2, 1, 2, 2]] | ['torch.bool', 'torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.prelu | dtype_int64 | [[5, 10, 5], []] | ['torch.int64', 'torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.celu | dtype_int64 | [[20]] | ['torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.celu | dtype_bool | [[20]] | ['torch.bool'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.silu | dtype_int64 | [[1, 0, 3]] | ['torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.hardsigmoid | dtype_int64 | [[20]] | ['torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.hardsigmoid | dtype_bool | [[20]] | ['torch.bool'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.logsigmoid | dtype_int64 | [[1, 0, 3]] | ['torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.threshold | dtype_bool | [[5, 5]] | ['torch.bool'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.binary_cross_entropy | dtype_int64 | [[5], [5]] | ['torch.int64', 'torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.binary_cross_entropy | dtype_bool | [[5], [5]] | ['torch.bool', 'torch.float32'] | [exception] ref raised RuntimeError, test returned normally | True |
| decomp | nn.functional.binary_cross_entropy | nan_inf | [[5], [5]] | ['torch.float32', 'torch.float32'] | [exception] ref raised RuntimeError, test returned normally | True |
| decomp | nn.functional.binary_cross_entropy | huge | [[5], [5]] | ['torch.float32', 'torch.float32'] | [exception] ref raised RuntimeError, test returned normally | True |
| decomp | nn.functional.hardshrink | dtype_int64 | [[]] | ['torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.gelu | dtype_int64 | [[10, 10]] | ['torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.gelu | dtype_bool | [[10, 10]] | ['torch.bool'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | mm | zero_dim | [[], [10, 5]] | ['torch.float32', 'torch.float32'] | [exception] exception type differs: RuntimeError vs IndexError :: Dimension specified as - | False |
| decomp | mvlgamma | dtype_bool | [[5, 5]] | ['torch.bool'] | [exception] ref raised RuntimeError, test returned normally | True |
| decomp | mvlgamma | dtype_bool | [[]] | ['torch.bool'] | [exception] ref raised RuntimeError, test returned normally | True |
| decomp | mvlgamma | dtype_bool | [[]] | ['torch.bool'] | [exception] ref raised RuntimeError, test returned normally | True |
| decomp | mvlgamma | dtype_bool | [[]] | ['torch.bool'] | [exception] ref raised RuntimeError, test returned normally | True |
| decomp | mvlgamma | dtype_bool | [[]] | ['torch.bool'] | [exception] ref raised RuntimeError, test returned normally | True |
| decomp | mvlgamma | dtype_bool | [[5, 5]] | ['torch.bool'] | [exception] ref raised RuntimeError, test returned normally | True |
| decomp | round | dtype_int64 | [[]] | ['torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | round | dtype_bool | [[]] | ['torch.bool'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | round | dtype_int64 | [[20]] | ['torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | round | dtype_bool | [[20]] | ['torch.bool'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | round | dtype_int64 | [[]] | ['torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | round | dtype_bool | [[]] | ['torch.bool'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | lerp | dtype_int64 | [[5, 5], [5], [5, 5]] | ['torch.int64', 'torch.int64', 'torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | lerp | dtype_bool | [[5, 5], [5], [5, 5]] | ['torch.bool', 'torch.float32', 'torch.float32'] | [exception] exception type differs: RuntimeError vs NotImplementedError :: Subtraction, th | False |
| decomp | index_copy | empty_dim0 | [[0], [1], [1]] | ['torch.float32', 'torch.int64', 'torch.float32'] | [exception] exception type differs: RuntimeError vs IndexError :: index is out of bounds f | False |
| decomp | index_add | zero_dim | [[], [1], [1]] | ['torch.float32', 'torch.int64', 'torch.float32'] | [exception] ref raised RuntimeError, test returned normally | True |
| decomp | trace | dtype_bool | [[5, 7]] | ['torch.bool'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.smooth_l1_loss | dtype_int64 | [[5, 5], [5, 5]] | ['torch.int64', 'torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.smooth_l1_loss | nan_inf | [[5, 5], [5, 5]] | ['torch.float32', 'torch.float32'] | [value] output[1]: NaN/Inf pattern differs from the float64 truth | True |
| decomp | log_softmax | dtype_int64 | [[]] | ['torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| meta | nn.functional.embedding_bag | base | [[10, 5], [5]] | ['torch.float32', 'torch.int64'] | fake-tensor path raised AssertionError: Please convert all Tensors to FakeTensors first or | None |
| meta | nn.functional.embedding_bag | empty_last | [[10, 0], [5]] | ['torch.float32', 'torch.int64'] | fake-tensor path raised AssertionError: Please convert all Tensors to FakeTensors first or | None |
| meta | nn.functional.embedding_bag | size1_last | [[10, 1], [5]] | ['torch.float32', 'torch.int64'] | fake-tensor path raised AssertionError: Please convert all Tensors to FakeTensors first or | None |
| meta | nn.functional.embedding_bag | noncontig | [[10, 5], [5]] | ['torch.float32', 'torch.int64'] | fake-tensor path raised AssertionError: Please convert all Tensors to FakeTensors first or | None |
| meta | nn.functional.embedding_bag | nan_inf | [[10, 5], [5]] | ['torch.float32', 'torch.int64'] | fake-tensor path raised AssertionError: Please convert all Tensors to FakeTensors first or | None |
| meta | nn.functional.embedding_bag | huge | [[10, 5], [5]] | ['torch.float32', 'torch.int64'] | fake-tensor path raised AssertionError: Please convert all Tensors to FakeTensors first or | None |
| meta | nn.functional.embedding_bag | tiny | [[10, 5], [5]] | ['torch.float32', 'torch.int64'] | fake-tensor path raised AssertionError: Please convert all Tensors to FakeTensors first or | None |
| meta | nn.functional.multi_head_attention_forward | base | [[3, 2], [3, 2], [3, 2], [6], [2], [2], [2, 2], [2]] | ['torch.float32', 'torch.float32', 'torch.float32', 'torch.float32', 'torch.float32', 'torch.float32', 'torch.float32', 'torch.float32'] | fake-tensor path raised AssertionError: Please convert all Tensors to FakeTensors first or | None |
| meta | nn.functional.multi_head_attention_forward | noncontig | [[3, 2], [3, 2], [3, 2], [6], [2], [2], [2, 2], [2]] | ['torch.float32', 'torch.float32', 'torch.float32', 'torch.float32', 'torch.float32', 'torch.float32', 'torch.float32', 'torch.float32'] | fake-tensor path raised AssertionError: Please convert all Tensors to FakeTensors first or | None |
| meta | nn.functional.multi_head_attention_forward | nan_inf | [[3, 2], [3, 2], [3, 2], [6], [2], [2], [2, 2], [2]] | ['torch.float32', 'torch.float32', 'torch.float32', 'torch.float32', 'torch.float32', 'torch.float32', 'torch.float32', 'torch.float32'] | fake-tensor path raised AssertionError: Please convert all Tensors to FakeTensors first or | None |
| meta | nn.functional.multi_head_attention_forward | huge | [[3, 2], [3, 2], [3, 2], [6], [2], [2], [2, 2], [2]] | ['torch.float32', 'torch.float32', 'torch.float32', 'torch.float32', 'torch.float32', 'torch.float32', 'torch.float32', 'torch.float32'] | fake-tensor path raised AssertionError: Please convert all Tensors to FakeTensors first or | None |
| meta | nn.functional.multi_head_attention_forward | tiny | [[3, 2], [3, 2], [3, 2], [6], [2], [2], [2, 2], [2]] | ['torch.float32', 'torch.float32', 'torch.float32', 'torch.float32', 'torch.float32', 'torch.float32', 'torch.float32', 'torch.float32'] | fake-tensor path raised AssertionError: Please convert all Tensors to FakeTensors first or | None |
| decomp | nn.functional.softplus | dtype_int64 | [[]] | ['torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.mse_loss | dtype_int64 | [[5], [5]] | ['torch.int64', 'torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.grid_sample | empty_last | [[2, 3, 5, 0], [2, 5, 5, 2]] | ['torch.float32', 'torch.float32'] | [exception] exception type differs: RuntimeError vs IndexError :: index is out of bounds f | True |
| decomp | nn.functional.grid_sample | dtype_int64 | [[2, 3, 5, 5], [2, 5, 5, 2]] | ['torch.int64', 'torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | grid_sampler_2d | empty_last | [[2, 3, 5, 0], [2, 13, 10, 2]] | ['torch.float32', 'torch.float32'] | [exception] exception type differs: RuntimeError vs IndexError :: index is out of bounds f | True |
| decomp | grid_sampler_2d | zero_dim | [[], [2, 13, 10, 2]] | ['torch.float32', 'torch.float32'] | [exception] exception type differs: IndexError vs ValueError :: not enough values to unpac | True |
| decomp | grid_sampler_2d | dtype_int64 | [[2, 3, 5, 20], [2, 13, 10, 2]] | ['torch.int64', 'torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | std | huge | [[5]] | ['torch.float32'] | [value] output[0]: NaN/Inf pattern differs from the float64 truth | True |
| decomp | std | tiny | [[5]] | ['torch.float32'] | [value] output[1]: compiled err vs fp64 = 1.162e-02 exceeds 4.0x eager err 1.118e-09 | True |
| decomp | nn.functional.ctc_loss | size1_last | [[50, 16, 1], [16, 30], [16], [16]] | ['torch.float32', 'torch.int64', 'torch.int64', 'torch.int64'] | [value] output[1]: compiled err vs fp64 = 2.440e+18 exceeds 4.0x eager err 3.706e+13 | False |
| decomp | nn.functional.nll_loss | empty_dim0 | [[0], []] | ['torch.float32', 'torch.int64'] | [exception] exception type differs: IndexError vs RuntimeError :: index 0 is out of bounds | True |
| decomp | nn.functional.nll_loss | dtype_int64 | [[3], []] | ['torch.int64', 'torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.huber_loss | dtype_int64 | [[5, 5, 5], [5, 5, 5]] | ['torch.int64', 'torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.huber_loss | dtype_bool | [[5, 5, 5], [5, 5, 5]] | ['torch.bool', 'torch.float32'] | [exception] ref raised RuntimeError, test returned normally | True |
| meta | repeat_interleave | base | [[2, 3, 4]] | ['torch.float32'] | fake-tensor path raised AssertionError: Please convert all Tensors to FakeTensors first or | None |
| meta | repeat_interleave | empty_dim0 | [[0, 3, 4]] | ['torch.float32'] | fake-tensor path raised AssertionError: Please convert all Tensors to FakeTensors first or | None |
| meta | repeat_interleave | size1_dim0 | [[1, 3, 4]] | ['torch.float32'] | fake-tensor path raised AssertionError: Please convert all Tensors to FakeTensors first or | None |
| meta | repeat_interleave | empty_last | [[2, 3, 0]] | ['torch.float32'] | fake-tensor path raised AssertionError: Please convert all Tensors to FakeTensors first or | None |
| meta | repeat_interleave | size1_last | [[2, 3, 1]] | ['torch.float32'] | fake-tensor path raised AssertionError: Please convert all Tensors to FakeTensors first or | None |
| meta | repeat_interleave | prime_dim0 | [[7, 3, 4]] | ['torch.float32'] | fake-tensor path raised AssertionError: Please convert all Tensors to FakeTensors first or | None |
| meta | repeat_interleave | noncontig | [[2, 3, 4]] | ['torch.float32'] | fake-tensor path raised AssertionError: Please convert all Tensors to FakeTensors first or | None |
| meta | repeat_interleave | dtype_int64 | [[2, 3, 4]] | ['torch.int64'] | fake-tensor path raised AssertionError: Please convert all Tensors to FakeTensors first or | None |
| meta | repeat_interleave | dtype_bool | [[2, 3, 4]] | ['torch.bool'] | fake-tensor path raised AssertionError: Please convert all Tensors to FakeTensors first or | None |
| meta | repeat_interleave | nan_inf | [[2, 3, 4]] | ['torch.float32'] | fake-tensor path raised AssertionError: Please convert all Tensors to FakeTensors first or | None |
| meta | repeat_interleave | huge | [[2, 3, 4]] | ['torch.float32'] | fake-tensor path raised AssertionError: Please convert all Tensors to FakeTensors first or | None |
| meta | repeat_interleave | tiny | [[2, 3, 4]] | ['torch.float32'] | fake-tensor path raised AssertionError: Please convert all Tensors to FakeTensors first or | None |
| meta | repeat_interleave | dtype_float16 | [[2, 3, 4]] | ['torch.float16'] | fake-tensor path raised AssertionError: Please convert all Tensors to FakeTensors first or | None |
| meta | repeat_interleave | dtype_bfloat16 | [[2, 3, 4]] | ['torch.bfloat16'] | fake-tensor path raised AssertionError: Please convert all Tensors to FakeTensors first or | None |
| meta_stride | nn.functional.channel_shuffle | channels_last | [[2, 6, 8, 8]] | ['torch.float32'] | output[0] stride (384, 64, 8, 1) vs real (384, 1, 48, 6) | None |
| decomp | linalg.cross | dtype_bool | [[5, 3], [5, 3]] | ['torch.bool', 'torch.float32'] | [exception] ref raised NotImplementedError, test returned normally | True |
| meta | linalg.matrix_rank | base | [[0, 0, 0]] | ['torch.float32'] | fake-tensor path raised AssertionError: Please convert all Tensors to FakeTensors first or | None |
| meta | linalg.matrix_rank | empty_last | [[0, 0, 0]] | ['torch.float32'] | fake-tensor path raised AssertionError: Please convert all Tensors to FakeTensors first or | None |
| meta | linalg.matrix_rank | size1_last | [[0, 0, 0]] | ['torch.float32'] | fake-tensor path raised AssertionError: Please convert all Tensors to FakeTensors first or | None |
| meta | linalg.matrix_rank | prime_dim0 | [[0, 0, 0]] | ['torch.float32'] | fake-tensor path raised AssertionError: Please convert all Tensors to FakeTensors first or | None |
| meta | linalg.matrix_rank | noncontig | [[0, 0, 0]] | ['torch.float32'] | fake-tensor path raised AssertionError: Please convert all Tensors to FakeTensors first or | None |
| meta | linalg.matrix_rank | nan_inf | [[0, 0, 0]] | ['torch.float32'] | fake-tensor path raised AssertionError: Please convert all Tensors to FakeTensors first or | None |
| meta | linalg.matrix_rank | huge | [[0, 0, 0]] | ['torch.float32'] | fake-tensor path raised AssertionError: Please convert all Tensors to FakeTensors first or | None |
| meta | linalg.matrix_rank | tiny | [[0, 0, 0]] | ['torch.float32'] | fake-tensor path raised AssertionError: Please convert all Tensors to FakeTensors first or | None |
| meta | linalg.pinv | dtype_bool | [[0, 50, 1], [0, 50, 1]] | ['torch.bool', 'torch.float32'] | fake-tensor path raised RuntimeError: expected scalar type torch.bool but found torch.floa | None |
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
