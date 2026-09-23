# source: https://github.com/pytorch/pytorch/issues/194001
# title: AOTAutogradCache: stale `guards_expr` from a prior compile causes spurious `ConstraintViolationError` on cache hit
# state: open  created: 2026-08-18
# mined automatically; the harness records the torch.compile target and its first call

# run1.py  -> "RUN1 OK"
@torch.compile()
def func(x):
    if x.size()[0] < 10:
        pass
    return x * 10
t = torch.rand(5, 10); torch._dynamo.mark_dynamic(t, 0); func(t)
