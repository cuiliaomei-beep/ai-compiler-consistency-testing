# Decomposition / meta differential

- operators: 2, samples: 2, input variants: 32
- variants where at least one decomposition ran: 31
- decomposition mismatches: 6  (confirmed by torch.compile: 6)
- meta / fake-tensor mismatches: 0 (data-dependent ops that cannot run on fake tensors, not counted: 0)
- wall: 39.4 s

| kind | op | variant | shapes | dtypes | detail | confirmed |
|---|---|---|---|---|---|---|
| decomp | nn.functional.nll_loss | empty_last | [[2, 0], [2]] | ['torch.float32', 'torch.int64'] | [exception] exception type differs: RuntimeError vs AssertionError :: weight tensor should | True |
| decomp | nn.functional.nll_loss | size1_last | [[2, 1], [2]] | ['torch.float32', 'torch.int64'] | [exception] exception type differs: RuntimeError vs AssertionError :: weight tensor should | True |
| decomp | nn.functional.nll_loss | dtype_int64 | [[2, 3], [2]] | ['torch.int64', 'torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.nll_loss | dtype_bool | [[2, 3], [2]] | ['torch.bool', 'torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.nll_loss | dtype_float16 | [[2, 3], [2]] | ['torch.float16', 'torch.int64'] | [exception] ref raised RuntimeError, test returned normally | True |
| decomp | nn.functional.nll_loss | dtype_bfloat16 | [[2, 3], [2]] | ['torch.bfloat16', 'torch.int64'] | [exception] ref raised RuntimeError, test returned normally | True |
