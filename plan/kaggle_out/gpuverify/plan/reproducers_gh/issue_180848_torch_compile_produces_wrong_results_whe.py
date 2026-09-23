# source: https://github.com/pytorch/pytorch/issues/180848
# title: `torch.compile` produces wrong results when fusing `adaptive_avg_pool2d` with `flatten + sum`
# state: closed  created: 2026-04-20
# mined automatically; the harness records the torch.compile target and its first call

# These are all correct (diff ≈ 0):
torch.compile(lambda x: F.adaptive_avg_pool2d(x, 7))(x)           # pool only
torch.compile(lambda x: F.adaptive_avg_pool2d(x, 7).sum())(x)     # pool + sum
torch.compile(lambda x: F.adaptive_avg_pool2d(x, 7).flatten(1))(x) # pool + flatten

# This is WRONG (diff ≈ 3.6):
torch.compile(lambda x: F.adaptive_avg_pool2d(x, 7).flatten(1).sum(-1))(x)
