"""10.7  32-bit indexing boundary on CUDA (Triton picks int32 index arithmetic when it believes every index fits).

Tensors with more than 2**31 elements, and -- the sharper case -- SMALL views whose storage offset or stride reaches
beyond 2**31, so that numel is tiny but the address arithmetic is not.  int8 data keeps the big buffer at 2 GB.
Every case compares the compiled result with eager on the same input (eager CUDA kernels switch to 64-bit indexing).
"""
import gc
import sys

import torch

print("torch", torch.__version__, "cuda", torch.cuda.is_available(), flush=True)
if not torch.cuda.is_available():
    sys.exit(0)
dev = "cuda"
N = 2 ** 31 + 2 ** 16 + 64          # large enough for the (2**16, 2**15 + 1) view below


def make_big():
    big = torch.empty(N, dtype=torch.int8, device=dev)
    step = 2 ** 27
    for s in range(0, N, step):                                   # value = (index * 7 + index // 1000) % 101, computed chunk-wise in int64
        e = min(s + step, N)
        i = torch.arange(s, e, device=dev, dtype=torch.int64)
        big[s:e] = ((i * 7 + i // 1000) % 101).to(torch.int8)
        del i
    return big


def same(a, b):
    if isinstance(a, (tuple, list)):
        return all(same(x, y) for x, y in zip(a, b))
    return a.dtype == b.dtype and a.shape == b.shape and bool(torch.equal(a, b))


def check(name, f, *args, dynamic=None, warm=None):
    torch._dynamo.reset()
    try:
        cf = torch.compile(f, dynamic=dynamic)
        if warm is not None:
            cf(*warm)                                               # small call first: does the recompile / guard notice the big one?
        got = cf(*args)
        want = f(*args)
        ok = same(want, got)
        extra = ""
        if not ok:
            w, g = (want[0], got[0]) if isinstance(want, (tuple, list)) else (want, got)
            if w.shape == g.shape and w.numel():
                bad = (w != g).flatten().nonzero().flatten()
                extra = f"  #wrong={bad.numel()} first at {bad[0].item()}: eager {w.flatten()[bad[0]].item()} compiled {g.flatten()[bad[0]].item()}"
            else:
                extra = f"  shapes {tuple(w.shape)} vs {tuple(g.shape)}"
        print(("   ok   " if ok else "!! DIFF ") + name + extra, flush=True)
        del got, want
    except Exception as e:  # noqa: BLE001
        print("   ERR  " + name + "  " + type(e).__name__ + ": " + str(e).splitlines()[0][:140], flush=True)
    gc.collect(); torch.cuda.empty_cache()


big = make_big()
print("big buffer ready", big.numel(), "elements", flush=True)
idx_hi = torch.tensor([0, 5, 2 ** 31 - 1, 2 ** 31, 2 ** 31 + 1, N - 1], device=dev)

# --- small views at a large storage offset / with a large stride
check("tail view big[2**31:] + 1", lambda v: v + 1, big[2 ** 31:])
check("tail view, reduction sum", lambda v: v.to(torch.int64).sum(), big[2 ** 31:])
check("tail view, in-place mul_ on a clone of the view's base slice", lambda v: v.clone().mul_(2), big[2 ** 31 - 8: 2 ** 31 + 8])
check("window straddling 2**31", lambda v: v.to(torch.int32) * 3 - 1, big[2 ** 31 - 32: 2 ** 31 + 32])
check("strided view big[::2**20] * 2", lambda v: v * 2, big[:: 2 ** 20])
check("strided view big[5::2**24] cumsum", lambda v: v.to(torch.int64).cumsum(0), big[5:: 2 ** 24])
check("as_strided (2, 3) at offset 2**31 - 2", lambda v: v.to(torch.int16) + 100, big.as_strided((2, 3), (2 ** 30, 3), 2 ** 31 - 2 ** 30 - 8))
check("flip of tail view", lambda v: v.flip(0), big[2 ** 31 - 16:])
check("tail view fed to where / argmax", lambda v: (torch.where(v > 50, v, -v), v.argmax()), big[2 ** 31:])
check("two far-apart views combined", lambda a, b: a.to(torch.int16) + b, big[:64], big[2 ** 31:])
check("tail view matmul-free dot", lambda v: (v.float() * v.float()).sum(), big[2 ** 31:])
check("tail view sort / topk", lambda v: (v.sort().values, v.topk(3).values), big[2 ** 31:])
check("2-D view, last column", lambda m: m[:, -1] + 1, big[: 2 ** 16 * (2 ** 15 + 1)].view(2 ** 16, 2 ** 15 + 1)[-40:])
check("2-D view, row reduction of the last rows", lambda m: m.to(torch.int32).sum(1), big[: 2 ** 16 * (2 ** 15 + 1)].view(2 ** 16, 2 ** 15 + 1)[-3:])

# --- gathers / scatters that address beyond 2**31 in a big tensor
check("index_select beyond 2**31", lambda x, i: x.index_select(0, i), big, idx_hi)
check("advanced indexing x[i] + 1", lambda x, i: x[i] + 1, big, idx_hi)
check("gather beyond 2**31", lambda x, i: x.gather(0, i), big, idx_hi)
check("take beyond 2**31", lambda x, i: x.take(i), big, idx_hi)
check("negative python index x[-3]", lambda x: x[-3] * 2, big)
check("slice with negative bounds x[-40:-8] + 1", lambda x: x[-40:-8] + 1, big)
check("narrow at 2**31 - 4", lambda x: x.narrow(0, 2 ** 31 - 4, 8) * 3, big)
check("roll of the tail window", lambda x: x[2 ** 31 - 8:].roll(3), big)

# --- whole-tensor kernels with more than 2**31 elements (outputs are 2 GB each; run last, free in between)
check("reduction over > 2**31 elements", lambda x: x.to(torch.int64).sum(), big)
check("max / argmax over > 2**31 elements", lambda x: (x.max(), (x == 100).to(torch.int64).sum()), big)
check("expanded scalar, reduction over 2**32 elements", lambda s: s.expand(2 ** 32).to(torch.int64).sum(), torch.ones(1, dtype=torch.int8, device=dev))
check("dynamic=True: small call then > 2**31 tail view", lambda v: v + 1, big[2 ** 31:], dynamic=True, warm=(big[:64],))
check("automatic dynamic: 1000 then 2000 then > 2**31 elements (reduction)", lambda x: x.to(torch.int64).sum(), big, warm=(big[:1000],))
check("dynamic=True: reduction, small then > 2**31", lambda x: (x.to(torch.int64) * 2).sum(), big, dynamic=True, warm=(big[:1000],))
check("pointwise over > 2**31 elements (x + 1)", lambda x: x + 1, big)
check("pointwise, last 8 of > 2**31 elements of (x * 3 - x)", lambda x: (x * 3 - x)[-8:], big)
check("dynamic=True: pointwise small then > 2**31 elements", lambda x: x + 1, big, dynamic=True, warm=(big[:1000],))
check("scatter into > 2**31 buffer", lambda x, i: x.clone().index_fill_(0, i, 7)[i], big, idx_hi)
print("DONE", flush=True)
