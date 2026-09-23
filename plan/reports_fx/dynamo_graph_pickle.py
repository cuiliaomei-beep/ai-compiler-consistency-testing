import pickle, torch
print("torch", torch.__version__)
captured = []
def backend(gm, inputs):
    captured.append(gm); return gm.forward
def f(buf, g):
    buf += g                     # in-place update of an input buffer
    buf *= 0.5
    return buf.sum()
torch.compile(f, backend=backend)(torch.zeros(3), torch.ones(3))
gm = captured[0]
print(gm.code.strip())
gm2 = pickle.loads(pickle.dumps(gm))
print("--- after pickle round trip"); print(gm2.code.strip())
for name, m in (("original", gm), ("unpickled", gm2)):
    b = torch.zeros(3); out = m(b, torch.ones(3))
    print(name, "returns", [o.item() if hasattr(o, "item") else o for o in (out if isinstance(out, tuple) else (out,))], "buffer afterwards", b.tolist())
