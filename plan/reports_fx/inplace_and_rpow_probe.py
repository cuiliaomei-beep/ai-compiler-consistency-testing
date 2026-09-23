import operator, torch, torch.fx
print("torch", torch.__version__)
def graph(target, args, method=False):
    g = torch.fx.Graph(); x = g.placeholder("x")
    n = g.call_method(target, (x,) + args) if method else g.call_function(target, (x,) + args)
    g.output(n); return torch.fx.GraphModule(torch.nn.Module(), g)
def run(f):
    try: return f()
    except Exception as e: return f"raises {type(e).__name__}: {str(e)[:60]}"
TI = torch.tensor([1, -2, 3]); TF = torch.tensor([1.5, -2.0, 3.0])
print("--- plain Python / eager")
def py_iadd(x): x += -2.5; return x
print("x += -2.5 on int64 tensor :", run(lambda: py_iadd(TI.clone())))
print("operator.iadd(x, -2.5)    :", run(lambda: operator.iadd(TI.clone(), -2.5)))
for name, gm, arg in (("operator.iadd(x, -2.5), int64 x", graph(operator.iadd, (-2.5,)), TI), ("operator.itruediv(x, -2), int64 x", graph(operator.itruediv, (-2,)), TI),
                      ("call_method __rpow__(-2), float x", graph("__rpow__", (-2,), True), TF), ("call_method __rsub__(-2), float x", graph("__rsub__", (-2,), True), TF)):
    print("---", name); print(gm.code.strip())
    print("   Interpreter        :", run(lambda: torch.fx.Interpreter(gm).run(arg.clone())))
    print("   GraphModule.forward:", run(lambda: gm(arg.clone())))
print("--- direct:", run(lambda: TF.__rpow__(-2)), "| (-2) ** TF =", (-2) ** TF, "| torch.Tensor.__rpow__(TF, -2) =", torch.Tensor.__rpow__(TF, -2))
