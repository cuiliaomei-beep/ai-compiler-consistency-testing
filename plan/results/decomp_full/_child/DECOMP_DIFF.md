# Decomposition / meta differential

- operators: 21, samples: 41, input variants: 477
- variants where at least one decomposition ran: 278
- decomposition mismatches: 1  (confirmed by torch.compile: 0)
- meta / fake-tensor mismatches: 0 (data-dependent ops that cannot run on fake tensors, not counted: 0)
- wall: 5.1 s

| kind | op | variant | shapes | dtypes | detail | confirmed |
|---|---|---|---|---|---|---|
| decomp | bmm | size1_dim0 | [[1, 32, 1], [16, 1, 64]] | ['torch.float32', 'torch.float32'] | [exception] ref raised RuntimeError, test returned normally | False |
