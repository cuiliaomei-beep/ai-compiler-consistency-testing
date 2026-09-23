# source: https://github.com/pytorch/pytorch/issues/184405
# title: `torch.compile(..., backend="inductor")` returns stale float32 for dtype=None factory op after torch.set_default_dtype(torch.float64)
# state: closed  created: 2026-05-19
# mined automatically; the harness records the torch.compile target and its first call

import os
os.environ.setdefault("CUDA_VISIBLE_DEVICES", "")
os.environ.setdefault("TORCHINDUCTOR_DISABLE_PROGRESS", "1")

import torch
torch.set_num_threads(1)
torch._dynamo.reset()

# 1. Test multiple factory APIs that rely on the implicit global dtype
def test_factory_apis():
    return {
        "ones": torch.ones(2),
        "zeros": torch.zeros(2),
        "tensor": torch.tensor([1.0, 2.0]),
        "arange": torch.arange(2.0),
        "empty": torch.empty(2)
    }

compiled_test = torch.compile(test_factory_apis, backend="inductor")

# 2. Phase 1: Compile under float32 (Dynamo bakes in dtype and caches the graph)
torch.set_default_dtype(torch.float32)
_ = compiled_test()  # Warmup & compile

# 3. Phase 2: Change global dtype and compare Eager vs Compiled behaviors
torch.set_default_dtype(torch.float64)
eager_results = test_factory_apis()
compiled_results = compiled_test()

# 4. Print a markdown-friendly report
print(f"PyTorch Version: {torch.__version__}\n")
print(f"| API Name   | Eager (Expected) | Compiled (Actual) | Bug Present? |")
print(f"|------------|------------------|-------------------|--------------|")

for api in eager_results.keys():
    eager_dt = str(eager_results[api].dtype).replace("torch.", "")
    comp_dt = str(compiled_results[api].dtype).replace("torch.", "")
    has_bug = "❌ YES" if eager_dt != comp_dt else "✅ NO"
    
    print(f"| {api:<10} | {eager_dt:<16} | {comp_dt:<17} | {has_bug:<12} |")
