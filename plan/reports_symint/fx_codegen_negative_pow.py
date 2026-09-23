import operator
import torch, torch.fx
print("torch", torch.__version__)
g = torch.fx.Graph()
x = g.placeholder("x")
g.output(g.call_function(operator.pow, (-2, x)))
gm = torch.fx.GraphModule(torch.nn.Module(), g)
print(gm.code.strip())
print("interpreter (node semantics):", torch.fx.Interpreter(gm).run(2), "  generated forward():", gm(2), "  python (-2) ** 2:", (-2) ** 2)

def f(x):
    return (-2.0) ** x.shape[0] * x          # symbolic_trace keeps shape[0] as a Proxy
traced = torch.fx.symbolic_trace(f)
print(traced.code.strip())
t = torch.ones(2)
print("eager:", f(t).tolist(), " traced:", traced(t).tolist())
