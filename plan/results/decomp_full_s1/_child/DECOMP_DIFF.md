# Decomposition / meta differential

- operators: 21, samples: 41, input variants: 586
- variants where at least one decomposition ran: 267
- decomposition mismatches: 7  (confirmed by torch.compile: 5)
- meta / fake-tensor mismatches: 0 (data-dependent ops that cannot run on fake tensors, not counted: 2)
- wall: 23.1 s

| kind | op | variant | shapes | dtypes | detail | confirmed |
|---|---|---|---|---|---|---|
| decomp | masked.softmax | dtype_int64 | [[5, 10, 5]] | ['torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | masked.log_softmax | dtype_int64 | [[5]] | ['torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | masked.softmin | dtype_int64 | [[5]] | ['torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | masked.logaddexp | dtype_int64 | [[5, 10, 5], [5, 10, 5]] | ['torch.int64', 'torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | bmm | size1_dim0 | [[1, 7, 1], [3, 1, 11]] | ['torch.float32', 'torch.float32'] | [exception] ref raised RuntimeError, test returned normally | False |
| decomp | bmm | dtype_bool | [[3, 7, 1], [3, 1, 11]] | ['torch.bool', 'torch.float32'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | bmm | dtype_bool | [[8, 128, 1], [8, 1, 256]] | ['torch.bool', 'torch.float32'] | [exception] ref raised RuntimeError, test returned normally | False |
