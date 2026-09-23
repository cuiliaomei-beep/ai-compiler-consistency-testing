import copy, io, operator, pickle
import torch, torch.fx

def build(target, arg):
    g = torch.fx.Graph()
    x = g.placeholder("x")
    g.output(g.call_function(target, (x, arg)))
    return torch.fx.GraphModule(torch.nn.Module(), g)

def run(m, t):
    t = t.clone()
    try:
        return f"returns {m(t).tolist()}, input afterwards {t.tolist()}"
    except RuntimeError:
        return "raises RuntimeError"

for name, gm, t in (("operator.iadd(x, 1)", build(operator.iadd, 1), torch.zeros(3)),
                    ("operator.imul(x, 2.5), int64 x", build(operator.imul, 2.5), torch.ones(3, dtype=torch.int64))):
    buf = io.BytesIO(); torch.save(gm, buf); buf.seek(0)
    print(name)
    for how, m in (("original", gm), ("copy.deepcopy", copy.deepcopy(gm)), ("pickle round trip", pickle.loads(pickle.dumps(gm))),
                   ("torch.save / torch.load", torch.load(buf, weights_only=False))):
        body = " ".join(l.strip() for l in m.code.strip().splitlines()[1:-1])
        print(f"    {how:24s} {run(m, t):60s} | {body}")
