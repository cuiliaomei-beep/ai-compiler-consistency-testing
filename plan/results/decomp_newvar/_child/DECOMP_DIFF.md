# Decomposition / meta differential

- operators: 21, samples: 21, input variants: 72
- variants where at least one decomposition ran: 32
- decomposition mismatches: 0  (confirmed by torch.compile: 0)
- meta / fake-tensor mismatches: 0 (data-dependent ops that cannot run on fake tensors, not counted: 1)
- wall: 2.4 s

| kind | op | variant | shapes | dtypes | detail | confirmed |
|---|---|---|---|---|---|---|
