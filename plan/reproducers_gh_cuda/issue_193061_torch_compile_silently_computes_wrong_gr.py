# source: https://github.com/pytorch/pytorch/issues/193061
# title: `torch.compile` silently computes wrong gradients for chained modulated LayerNorms with a shared scale/shift parameter (regression 2.9.1 → 2.10.0 due to mix_order_reduction)
# state: closed  created: 2026-08-11
# mined automatically; the harness records the torch.compile target and its first call

import torch
import torch.nn as nn

DIM, SEQ, SMALL_SEQ = 1024, 32768, 4096
dev = 'cuda'


def run(seq=SEQ, n_norms=2, slicing='chunk'):
    torch.manual_seed(0)
    norms = [nn.LayerNorm(DIM, 1e-6, elementwise_affine=False).to(dev)
             for _ in range(n_norms)]
    if slicing == 'separate':
        params = [nn.Parameter(torch.randn(DIM, device=dev) / DIM ** 0.5)
                  for _ in range(2 * n_norms)]
    else:
        table = nn.Parameter(
            torch.randn(1, 2 * n_norms, DIM, device=dev) / DIM ** 0.5)
        params = [table]

    def fn(x):
        if slicing == 'separate':
            mods = params
        elif slicing == 'unbind':
            mods = [s.unsqueeze(1) for s in params[0].unbind(1)]
        else:  # 'chunk' — the failing case
            mods = params[0].chunk(2 * n_norms, dim=1)
        for i, norm in enumerate(norms):
            shift, scale = mods[2 * i], mods[2 * i + 1]
            x = x + (norm(x) * (1 + scale) + shift)
        return x.square().mean()

    fn_c = torch.compile(fn, mode='default', dynamic=False)
    x = torch.randn(1, seq, DIM, device=dev)

    def grads():
        g = [p.grad for p in params]
        for p in params:
            p.grad = None
        return torch.cat([t.reshape(-1) for t in g])

    fn(x).backward()
    g_eager = grads()
    fn_c(x).backward()
    g_compiled = grads()

    rel = ((g_eager - g_compiled).abs().max()
           / g_eager.abs().max().clamp(min=1e-12)).item()
    return rel


CASES = [
    ('chunked table, 2 norms, seq 32768  (THE BUG)', dict()),
    ('same but seq 4096', dict(seq=SMALL_SEQ)),
    ('same but single norm', dict(n_norms=1)),
    ('same but unbind(1)+unsqueeze(1) instead of chunk', dict(slicing='unbind')),
    ('same but 4 independent parameters', dict(slicing='separate')),
]

for name, kwargs in CASES:
    rel = run(**kwargs)
    print(f'{"FAIL" if rel > 0.1 else "ok  "}  max rel grad err {rel:9.3e}  {name}',
          flush=True)

print('\nexpected: first row FAIL (silently wrong grads), all others ok')
