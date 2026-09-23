# source: https://github.com/pytorch/pytorch/issues/189522
# title: `nested_compile_region` + input mutation + a float8_e8m0fnu region
# state: open  created: 2026-07-10
# mined automatically; the harness records the torch.compile target and its first call

import os


# A previously cached successful compile (e.g. from a run with a workaround
# patch active) masks the failure — the cache key ignores such state.
os.environ.setdefault("TORCHINDUCTOR_FORCE_DISABLE_CACHES", "1")

import torch
import torch.nn as nn


torch.set_grad_enabled(False)
DIM, MAX_LEN = 64, 32


class Layer(nn.Module):
    def __init__(self):
        super().__init__()
        self.qkv = nn.Linear(DIM, 3 * DIM)
        self.o = nn.Linear(DIM, DIM)

    def forward(self, x, k_cache, v_cache, pos, scale_e8m0):
        # e8m0 scales enter the region and are only converted — the allowed
        # usage — but their mere presence as HOP args trips the skip.
        scale = scale_e8m0.to(torch.float32).view(1, 1, DIM)
        q, k, v = self.qkv(x).chunk(3, dim=-1)
        # static-cache update: in-place writes to region inputs
        k_cache.index_copy_(1, pos, k)
        v_cache.index_copy_(1, pos, v)
        attn = torch.softmax(q @ k_cache.transpose(-1, -2) / 8.0, dim=-1) @ v_cache
        return self.o(attn) * scale


class Model(nn.Module):
    def __init__(self):
        super().__init__()
        self.layers = nn.ModuleList(Layer() for _ in range(2))

    def forward(self, x, caches, pos, scale_e8m0):
        for layer, (k_cache, v_cache) in zip(self.layers, caches):
            x = x + layer(x, k_cache, v_cache, pos, scale_e8m0)
        return x


def inputs():
    torch.manual_seed(0)
    return (
        torch.randn(1, 4, DIM, device="cuda"),
        [(torch.zeros(1, MAX_LEN, DIM, device="cuda"), torch.zeros(1, MAX_LEN, DIM, device="cuda")) for _ in range(2)],
        torch.arange(4, device="cuda"),
        torch.full((DIM,), 127, dtype=torch.uint8, device="cuda").view(torch.float8_e8m0fnu),
    )


def run(mark_region):
    torch.compiler.reset()
    if mark_region:
        Layer.forward = torch.compiler.nested_compile_region(Layer.__dict__["forward"])
    try:
        torch.manual_seed(0)
        model = Model().cuda()
        ref = model(*inputs())
        out = torch.compile(model, fullgraph=True)(*inputs())
        torch.testing.assert_close(out, ref)
        return "OK"
    except Exception as e:
        return f"FAIL {type(e).__name__}: {str(e).splitlines()[0] if str(e) else e}"
    finally:
        if mark_region:
            del Layer.forward


print(f"torch {torch.__version__}")
print(f"flat compile:   {run(mark_region=False)}")
print(f"region compile: {run(mark_region=True)}")
