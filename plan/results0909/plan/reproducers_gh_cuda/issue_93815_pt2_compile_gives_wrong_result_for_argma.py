# source: https://github.com/pytorch/pytorch/issues/93815
# title: [pt2] compile gives wrong result for `argmax` on CUDA tensor of `float16`
# state: closed  created: 2023-02-01
# mined automatically; the harness records the torch.compile target and its first call

import torch

def fn(x):
    return x.argmax(0)

for i in range(100):
    x = torch.randint(-100, 100, (20, 20), dtype=torch.int16)

    cpu = fn(x)
    gpu = fn(x.cuda()).cpu()
    compiled = torch.compile(fn)
    comp = compiled(x.cuda()).cpu()

    print(i)

    assert torch.allclose(cpu, gpu), '\n'.join(['', 'cpu', str(cpu), 'gpu', str(gpu)])
    assert torch.allclose(cpu, comp), '\n'.join(['', 'cpu', str(cpu), 'comp', str(comp)]) # may fail sometimes
