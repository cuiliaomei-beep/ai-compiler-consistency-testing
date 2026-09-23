import copy, io, operator, pickle
import torch, torch.fx
print("torch", torch.__version__)

def build(fn):
    g = torch.fx.Graph(); x = g.placeholder("x"); g.output(fn(g, x))
    return torch.fx.GraphModule(torch.nn.Module(), g)

cases = {
    "operator.iadd(x, 1)":        (lambda g, x: g.call_function(operator.iadd, (x, 1)), torch.zeros(3)),
    "operator.imul(x, 2.5) int":  (lambda g, x: g.call_function(operator.imul, (x, 2.5)), torch.ones(3, dtype=torch.int64)),
    "x.__rpow__(-2)":             (lambda g, x: g.call_method("__rpow__", (x, -2)), torch.tensor([2.0, 3.0])),
    "x.__rsub__(1) (control)":    (lambda g, x: g.call_method("__rsub__", (x, 1)), torch.tensor([2.0, 3.0])),
}
def run(m, t):
    t = t.clone()
    try:
        out = m(t)
        return f"returns {out.tolist()}, input afterwards {t.tolist()}"
    except Exception as e:
        return f"raises {type(e).__name__}"
for name, (fn, t) in cases.items():
    gm = build(fn)
    buf = io.BytesIO(); torch.save(gm, buf); buf.seek(0)
    variants = {"original": gm, "copy.deepcopy": copy.deepcopy(gm), "pickle round trip": pickle.loads(pickle.dumps(gm)), "torch.save / torch.load": torch.load(buf, weights_only=False)}
    print(name)
    for vn, m in variants.items():
        body = [l.strip() for l in m.code.strip().splitlines()[1:-1]]
        print(f"    {vn:24s} {run(m, t):62s} | {' '.join(body)}")
