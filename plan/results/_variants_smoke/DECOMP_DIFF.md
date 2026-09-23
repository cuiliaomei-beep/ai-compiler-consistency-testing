# Decomposition / meta differential

- operators: 6, samples: 6, input variants: 22
- variants where at least one decomposition ran: 10
- decomposition mismatches: 0  (confirmed by torch.compile: 0)
- meta / fake-tensor mismatches: 0 (data-dependent ops that cannot run on fake tensors, not counted: 0)
- wall: 0.6 s

| kind | op | variant | shapes | dtypes | detail | confirmed |
|---|---|---|---|---|---|---|
