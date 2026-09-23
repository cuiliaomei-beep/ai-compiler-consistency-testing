# source: https://github.com/pytorch/pytorch/issues/192219
# title: BUG: Inductor `as_strided` silently reads out of bounds
# state: closed  created: 2026-08-05
# mined automatically; the harness records the torch.compile target and its first call

import torch, triton, triton.language as tl

N, R, SKIP, POISON, DEV = 2048, 4, 1, 12345.0, "cuda"

@triton.jit
def maybe_fill(out_ptr, do_write, n_cols, BLOCK: tl.constexpr):
    """Fill out_ptr[0:n_cols] with 1.0, but only when do_write != 0."""
    if do_write != 0:
        offs = tl.arange(0, BLOCK)
        tl.store(out_ptr + offs, 1.0, mask=offs < n_cols)

def run():
    base = torch.zeros(R, N, device=DEV, dtype=torch.float32)
    for i in range(R):
        row = base[i : i + 1]                       # view, storage_offset = i * N
        maybe_fill[(1,)](row, 0 if i == SKIP else 1, N, BLOCK=N)
        base[i : i + 1] = row                       # write-back
    return base

def poison_allocator(count=2048):
    junk = [torch.full((N,), POISON, device=DEV, dtype=torch.float32) for _ in range(count)]
    del junk
    torch.cuda.synchronize()

expected = torch.zeros(R, N, device=DEV)
expected[[i for i in range(R) if i != SKIP]] = 1.0

poison_allocator(); eager = run().clone()
cf = torch.compile(run, fullgraph=True); cf()      # compile before poisoning
poison_allocator(); compiled = cf().clone()

print("eager    matches:", torch.equal(eager, expected))
print("compiled matches:", torch.equal(compiled, expected))
print("freed-memory value present:", int((compiled == POISON).sum()), "elements")
