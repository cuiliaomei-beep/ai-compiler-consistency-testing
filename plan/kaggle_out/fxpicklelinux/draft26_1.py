import pickle, torch

captured = []
def backend(gm, example_inputs):
    captured.append(gm)
    return gm.forward

def step(buf, g):
    buf += g                      # in-place update of an input buffer
    buf *= 0.5
    return buf.sum()

torch.compile(step, backend=backend)(torch.zeros(3), torch.ones(3))
for name, m in (("captured graph", captured[0]), ("after pickle round trip", pickle.loads(pickle.dumps(captured[0])))):
    buf = torch.zeros(3)
    m(buf, torch.ones(3))
    print(f"{name:24s} buffer afterwards {buf.tolist()}")
