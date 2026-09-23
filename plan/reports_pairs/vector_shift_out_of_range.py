"""Asymmetry audit: CppOverrides.bitwise_left/right_shift guard negative and too-large shift counts, CppVecOverrides emits a raw `a << b`.
Do vectorised kernels (length >= 16) agree with eager and with the scalar tail (length 3)?"""
import os, sys
sys.path.insert(0, os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
try:
    from tcc.compat import ensure_msvc_env; ensure_msvc_env()
except Exception:
    pass
import torch
print("torch", torch.__version__)
for dt in (torch.int8, torch.uint8, torch.int16, torch.int32, torch.int64):
    bits = torch.iinfo(dt).bits
    counts = [0, 1, bits - 2, bits - 1, bits, bits + 1, 2 * bits, 63, 64, 65, 100, -1, -2, -bits]
    ii = torch.iinfo(dt)
    counts = [c for c in counts if ii.min <= c <= ii.max]
    base = [1, -1 if ii.min < 0 else ii.max, ii.max, ii.min, 5, -5 if ii.min < 0 else 250 % (ii.max + 1)]
    for n in (3, 40):
        a = torch.tensor([base[i % len(base)] for i in range(len(counts) * len(base))][: max(n, 1) * 1000], dtype=dt)
        b = torch.tensor([counts[(i // len(base)) % len(counts)] for i in range(len(a))], dtype=dt)
        if n == 3:
            idx = torch.arange(len(a)); rows = [(a[i:i + 3], b[i:i + 3]) for i in range(0, len(a) - 2, 3)]
        else:
            rows = [(a, b)]
        for opname, f in (("<<", lambda x, y: x << y), (">>", lambda x, y: x >> y)):
            torch._dynamo.reset()
            g = torch.compile(f, dynamic=False)
            bad = []
            for x, y in rows[:40]:
                e, c = f(x, y), g(x, y)
                if not torch.equal(e, c):
                    i = int((e != c).nonzero()[0])
                    bad.append(f"{x[i].item()} {opname} {y[i].item()}: eager {e[i].item()} compiled {c[i].item()}")
            print("!!" if bad else "  ", f"{str(dt):12s} n={n:<3d} {opname}", "; ".join(bad[:4]), f"(+{len(bad) - 4} more)" if len(bad) > 4 else "", flush=True)
