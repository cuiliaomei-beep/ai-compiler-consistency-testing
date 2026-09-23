# Decomposition / meta differential

- operators: 21, samples: 21, input variants: 297
- variants where at least one decomposition ran: 271
- decomposition mismatches: 5  (confirmed by torch.compile: 3)
- meta / fake-tensor mismatches: 0 (data-dependent ops that cannot run on fake tensors, not counted: 2)
- wall: 7.3 s

| kind | op | variant | shapes | dtypes | detail | confirmed |
|---|---|---|---|---|---|---|
| decomp | bmm | zero_dim | [[], [10, 10, 5]] | ['torch.float32', 'torch.float32'] | [exception] exception type differs: RuntimeError vs IndexError :: tuple index out of range | False |
| decomp | masked.softmax | dtype_int64 | [[5, 5]] | ['torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | masked.softmin | dtype_int64 | [[5, 5]] | ['torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | masked.logaddexp | dtype_int64 | [[5, 5], [5, 5]] | ['torch.int64', 'torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | bmm | zero_dim | [[], [8, 1, 256]] | ['torch.float32', 'torch.float32'] | [exception] exception type differs: RuntimeError vs IndexError :: tuple index out of range | False |
