# Decomposition / meta differential

- operators: 552, samples: 552, input variants: 1890
- variants where at least one decomposition ran: 1507
- decomposition mismatches: 24  (confirmed by torch.compile: 24)
- meta / fake-tensor mismatches: 0 (data-dependent ops that cannot run on fake tensors, not counted: 31)
- wall: 2620.5 s

- operators whose child interpreter died (native abort / timeout): unbind (rc -999), diagflat (rc -999)

| kind | op | variant | shapes | dtypes | detail | confirmed |
|---|---|---|---|---|---|---|
| decomp | isin | dtype_complex64 | [[20], [5]] | ['torch.complex64', 'torch.complex64'] | [exception] ref raised RuntimeError, test returned normally | False |
| decomp | nn.functional.linear_cross_entropy | base | [[8], [8, 8], []] | ['torch.float32', 'torch.float32', 'torch.int64'] | [exception] test raised TypeError, ref returned normally :: mm() got an unexpected keyword | False |
| decomp | nn.functional.linear_cross_entropy | dtype_complex64 | [[8], [8, 8], []] | ['torch.complex64', 'torch.complex64', 'torch.int64'] | [exception] exception type differs: RuntimeError vs NotImplementedError :: "max_values_cpu | True |
| decomp | native_group_norm | dtype_complex64 | [[1, 3], [3], [3]] | ['torch.complex64', 'torch.complex64', 'torch.complex64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | native_batch_norm | dtype_complex64 | [[2, 1], [1], [1], [1], [1]] | ['torch.complex64', 'torch.complex64', 'torch.complex64', 'torch.complex64', 'torch.complex64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.group_norm | dtype_complex64 | [[1, 2]] | ['torch.complex64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.instance_norm | dtype_complex64 | [[3, 2, 3, 4]] | ['torch.complex64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.interpolate | dtype_complex64 | [[2, 3, 4]] | ['torch.complex64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.interpolate | dtype_complex64 | [[2, 3, 4]] | ['torch.complex64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.upsample_nearest | dtype_complex64 | [[2, 3, 4, 4, 4]] | ['torch.complex64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.max_pool1d | base | [[2, 6]] | ['torch.float32'] | [exception] test raised AttributeError, ref returned normally :: module 'torch._inductor'  | False |
| decomp | nn.functional.max_unpool1d | dtype_complex64 | [[1, 2, 4], [1, 2, 4]] | ['torch.complex64', 'torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.max_unpool1d | dtype_complex64 | [[1, 2, 2], [1, 2, 2]] | ['torch.complex64', 'torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.max_unpool2d | dtype_complex64 | [[1, 2, 2, 7], [1, 2, 2, 7]] | ['torch.complex64', 'torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.max_unpool2d | dtype_complex64 | [[1, 2, 1, 3], [1, 2, 1, 3]] | ['torch.complex64', 'torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.max_unpool3d | dtype_complex64 | [[1, 2, 2, 4, 2], [1, 2, 2, 4, 2]] | ['torch.complex64', 'torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.max_unpool3d | dtype_complex64 | [[1, 2, 1, 2, 2], [1, 2, 1, 2, 2]] | ['torch.complex64', 'torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.hardshrink | dtype_complex64 | [[]] | ['torch.complex64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | index_reduce | dtype_complex64 | [[1], [1], [1]] | ['torch.complex64', 'torch.int64', 'torch.complex64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | xlogy | dtype_complex64 | [[10, 1, 5], [10, 5]] | ['torch.complex64', 'torch.complex64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.smooth_l1_loss | dtype_complex64 | [[5, 5], [5, 5]] | ['torch.complex64', 'torch.complex64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.mse_loss | dtype_complex64 | [[5], [5]] | ['torch.complex64', 'torch.complex64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nanmean | dtype_complex64 | [[3, 2, 1, 2]] | ['torch.complex64'] | [exception] ref raised RuntimeError, test returned normally | True |
| decomp | nansum | dtype_complex64 | [[3]] | ['torch.complex64'] | [exception] ref raised RuntimeError, test returned normally | True |
| decomp | nn.functional.nll_loss | dtype_complex64 | [[3], []] | ['torch.complex64', 'torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.huber_loss | dtype_complex64 | [[5, 5, 5], [5, 5, 5]] | ['torch.complex64', 'torch.complex64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | linalg.pinv | dtype_complex64 | [[50, 2], [3, 2]] | ['torch.complex64', 'torch.complex64'] | [value] output[0]: compiled err vs fp64 = 1.002e-01 exceeds 4.0x eager err 0.000e+00 | True |
