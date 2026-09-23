# Decomposition / meta differential

- operators: 21, samples: 42, input variants: 699
- variants where at least one decomposition ran: 637
- decomposition mismatches: 13  (confirmed by torch.compile: 8)
- meta / fake-tensor mismatches: 4 (data-dependent ops that cannot run on fake tensors, not counted: 0)
- wall: 154.2 s

| kind | op | variant | shapes | dtypes | detail | confirmed |
|---|---|---|---|---|---|---|
| decomp | softmax | dtype_int64 | [[5, 10, 5]] | ['torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.pad | empty_dim0 | [[0, 3]] | ['torch.float32'] | [exception] ref raised RuntimeError, test returned normally | False |
| decomp | nn.functional.pad | empty_last | [[1, 0]] | ['torch.float32'] | [exception] exception type differs: RuntimeError vs IndexError :: index is out of bounds f | False |
| decomp | nn.functional.pad | size1_last | [[1, 1]] | ['torch.float32'] | [exception] ref raised RuntimeError, test returned normally | False |
| decomp | nn.functional.pad | dtype_bool | [[1, 3]] | ['torch.bool'] | [exception] ref raised NotImplementedError, test returned normally | True |
| meta_stride | nn.functional.pad | channels_last | [[3, 3, 5, 5]] | ['torch.float32'] | output[0] stride (245, 49, 7, 1) vs real (245, 1, 35, 5) | None |
| decomp | nn.functional.pad | empty_last | [[1, 3, 0]] | ['torch.float32'] | [exception] exception type differs: RuntimeError vs IndexError :: index is out of bounds f | False |
| decomp | nn.functional.pad | dtype_bool | [[1, 3, 3]] | ['torch.bool'] | [exception] ref raised NotImplementedError, test returned normally | True |
| meta_stride | nn.functional.pad | channels_last | [[3, 3, 5, 5]] | ['torch.float32'] | output[1] stride (75, 25, 5, 1) vs real (75, 1, 15, 3) | None |
| decomp | nn.functional.pad | dtype_bool | [[8, 1, 5, 5]] | ['torch.bool'] | [exception] ref raised NotImplementedError, test returned normally | True |
| decomp | nn.functional.pad | empty_last | [[2, 6, 5, 0]] | ['torch.float32'] | [exception] exception type differs: RuntimeError vs IndexError :: index is out of bounds f | False |
| meta_stride | nn.functional.pad | channels_last | [[2, 6, 5, 5]] | ['torch.float32'] | output[1] stride (150, 25, 5, 1) vs real (150, 1, 30, 6) | None |
| decomp | log_softmax | dtype_int64 | [[5]] | ['torch.int64'] | [exception] ref raised NotImplementedError, test returned normally | True |
| meta | log_softmax | dtype_bool | [[5, 0, 0]] | ['torch.bool'] | fake-tensor path raised NotImplementedError: Subtraction, the `-` operator, with two bool  | None |
| decomp | std | huge | [[5, 5, 5]] | ['torch.float32'] | [value] output[0]: NaN/Inf pattern differs from the float64 truth | True |
| decomp | std | tiny | [[5, 5, 5]] | ['torch.float32'] | [value] output[1]: compiled err vs fp64 = 1.090e-02 exceeds 4.0x eager err 7.987e-10 | True |
| decomp | std | tiny | [[3, 4, 5]] | ['torch.float32'] | [value] output[1]: compiled err vs fp64 = 4.330e-01 exceeds 4.0x eager err 5.909e-08 | True |
