# Decomposition / meta differential

- operators: 14, samples: 28, input variants: 410
- variants where at least one decomposition ran: 229
- decomposition mismatches: 4  (confirmed by torch.compile: 4)
- meta / fake-tensor mismatches: 0 (data-dependent ops that cannot run on fake tensors, not counted: 2)
- wall: 13.4 s

| kind | op | variant | shapes | dtypes | detail | confirmed |
|---|---|---|---|---|---|---|
| decomp | masked.softmax | dtype_int64 | [[5, 5]] | ['torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | masked.log_softmax | dtype_int64 | [[5, 10, 5]] | ['torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | masked.softmin | dtype_int64 | [[]] | ['torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | masked.logaddexp | dtype_int64 | [[5, 10, 5], [5, 10, 5]] | ['torch.int64', 'torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
