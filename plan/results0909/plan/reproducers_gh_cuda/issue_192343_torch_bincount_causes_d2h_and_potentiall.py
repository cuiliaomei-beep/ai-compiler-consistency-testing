# source: https://github.com/pytorch/pytorch/issues/192343
# title: `torch.bincount` causes `D2H` and potentially breaks `cuda graph` and `torch.compile` and `overlap compute`
# state: open  created: 2026-08-06
# mined automatically; the harness records the torch.compile target and its first call

import torch


def test(X, minlength=1024):
    X = X + 1
    r = torch.bincount(X).float()
    return r - 1
compiledtest = torch.compile(test, mode="reduce-overhead")

a = torch.randint(0, 32, (1,), device="cuda")
b = torch.randint(0, 32, (1,), device="cuda")
c = torch.randint(0, 32, (1,), device="cuda")

p = torch.profiler.profile(
    activities=[
        torch.profiler.ProfilerActivity.CPU,
        torch.profiler.ProfilerActivity.CUDA,
    ],
    profile_memory=True,
    record_shapes=True,
)
p.start()
with torch.profiler.record_function("test"):
    with torch.profiler.record_function("mybincount"):
        test(a)
    with torch.profiler.record_function("mybincount2"):
        compiledtest(a)
    with torch.profiler.record_function("mybincount3"):
        compiledtest(b)
    with torch.profiler.record_function("mybincount4"):
        compiledtest(c)
p.stop()
p.export_chrome_trace("cuda test test")
