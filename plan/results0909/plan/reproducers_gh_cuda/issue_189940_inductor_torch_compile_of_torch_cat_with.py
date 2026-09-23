# source: https://github.com/pytorch/pytorch/issues/189940
# title: [inductor] torch.compile of torch.cat with a symbolic (dynamic) concat dim is 2–2.5× slower than eager (symbolic int64 divmod in generated indexing)
# state: open  created: 2026-07-14
# mined automatically; the harness records the torch.compile target and its first call

import torch

def nested_cat_add(q1, k1, v1a, v1b, q2, k2, v2a, v2b):
    v1 = v1a + v1b
    v2 = v2a + v2b
    g1 = torch.cat([q1, k1, v1], dim=-1)
    g2 = torch.cat([q2, k2, v2], dim=-1)
    return torch.cat([g1, g2], dim=-1)

def make_inputs(n):
    widths = [2048, 256, 256, 256, 2048, 256, 256, 256]  # q/k/v head widths
    return [torch.randn(n, w, dtype=torch.bfloat16, device="cuda") for w in widths]

def bench_ms(fn, inputs, warmup=25, iters=100):
    for _ in range(warmup):
        fn(*inputs)
    torch.cuda.synchronize()
    s, e = (torch.cuda.Event(enable_timing=True) for _ in range(2))
    s.record()
    for _ in range(iters):
        fn(*inputs)
    e.record()
    torch.cuda.synchronize()
    return s.elapsed_time(e) / iters

inputs = make_inputs(4096)
eager_ms = bench_ms(nested_cat_add, inputs)

# Make the concat (last) dim a runtime symint.
for t in inputs:
    torch._dynamo.mark_dynamic(t, t.dim() - 1)
compiled = torch.compile(nested_cat_add, dynamic=True)
compiled(*inputs)  # triggers compilation
comp_ms = bench_ms(compiled, inputs)

print(f"eager    : {eager_ms:.4f} ms/iter")
print(f"compiled : {comp_ms:.4f} ms/iter  ({comp_ms / eager_ms:.2f}x eager)")
