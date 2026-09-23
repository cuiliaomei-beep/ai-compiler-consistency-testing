# source: https://github.com/pytorch/pytorch/issues/189925
# title: [dynamo] _io.text_encoding causes a graph break (no polyfill)
# state: closed  created: 2026-07-14
# mined automatically; the harness records the torch.compile target and its first call

import torch

@torch.compile(backend="eager", fullgraph=True)
def fn(encoding):
    import _io
    return _io.text_encoding(encoding)

fn(None)
