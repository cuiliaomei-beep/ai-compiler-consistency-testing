# Decomposition / meta differential

- operators: 1, samples: 1, input variants: 16
- variants where at least one decomposition ran: 10
- decomposition mismatches: 0  (confirmed by torch.compile: 0)
- meta / fake-tensor mismatches: 0 (data-dependent ops that cannot run on fake tensors, not counted: 0)
- wall: 4.1 s

| kind | op | variant | shapes | dtypes | detail | confirmed |
|---|---|---|---|---|---|---|
