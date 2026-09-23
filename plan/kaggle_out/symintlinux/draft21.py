import operator
import torch, torch.fx

g = torch.fx.Graph()
x = g.placeholder("x")
g.output(g.call_function(operator.pow, (-2, x)))
gm = torch.fx.GraphModule(torch.nn.Module(), g)
print(gm.code.strip())
print("Interpreter:", torch.fx.Interpreter(gm).run(2), " GraphModule.forward:", gm(2), " Python (-2) ** 2:", (-2) ** 2)

def alternating_sign(x):
    return x * (-1) ** x.shape[0]

for backend in ("eager", "aot_eager"):
    torch._dynamo.reset()
    f = torch.compile(alternating_sign, backend=backend, dynamic=True)
    print(backend, [(n, alternating_sign(torch.ones(n))[0].item(), f(torch.ones(n))[0].item()) for n in (2, 3, 4)], "  # (n, eager, compiled)")
