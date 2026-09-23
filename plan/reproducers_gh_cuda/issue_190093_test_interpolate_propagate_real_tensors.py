# source: https://github.com/pytorch/pytorch/issues/190093
# title: test_interpolate_propagate_real_tensors_cuda fails CUDA mem-leak check: real CUDA tensor from data-dependent .tolist() retained past dynamo.reset()
# state: closed  created: 2026-07-15
# mined automatically; the harness records the torch.compile target and its first call

import gc, torch, torch._functorch.config
torch.cuda.init()
gc.collect(); torch.cuda.synchronize(); torch.cuda.empty_cache()
base = torch.cuda.memory_allocated()
with torch._functorch.config.patch(fake_tensor_propagate_real_tensors=True):
    @torch.compile(backend="eager", fullgraph=True)
    def f(mask, box):
        mask = torch.randn(1, 1, 30, 30, device="cuda")
        h, w = box.tolist()
        return mask.sum() + h + w
    f(torch.tensor([30, 30], device="cuda"), torch.tensor([68, 32], device="cuda"))
torch._dynamo.reset(); gc.collect(); torch.cuda.synchronize(); torch.cuda.empty_cache()
print(torch.cuda.memory_allocated() - base)   # 512, expected 0
