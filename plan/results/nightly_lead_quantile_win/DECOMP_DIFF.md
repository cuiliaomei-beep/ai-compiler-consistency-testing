# Decomposition / meta differential

- operators: 2, samples: 4, input variants: 64
- variants where at least one decomposition ran: 59
- decomposition mismatches: 0  (confirmed by torch.compile: 0)
- meta / fake-tensor mismatches: 0 (data-dependent ops that cannot run on fake tensors, not counted: 0)
- wall: 1.0 s

| kind | op | variant | shapes | dtypes | detail | confirmed |
|---|---|---|---|---|---|---|
