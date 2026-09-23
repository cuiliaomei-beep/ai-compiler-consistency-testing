"""torch.fx code generation: names that the generated source relies on (inf, nan, torch, device, NoneType, math ...)
versus user-chosen placeholder / node names.  Interpreter is the reference semantics; GraphModule.forward is the generated code."""
import math, operator
import torch, torch.fx
print("torch", torch.__version__)

def check(name, build, *args):
    try:
        g = build()
        gm = torch.fx.GraphModule(torch.nn.Module(), g)
        want = torch.fx.Interpreter(gm).run(*args)
        got = gm(*args)
        same = (torch.equal(want, got) if isinstance(want, torch.Tensor) else want == got)
        print(("   ok  " if same else "!! DIFF"), name, "" if same else f"| interpreter {want} | forward {got}\n" + gm.code)
    except Exception as e:
        print("   ERR ", name, type(e).__name__, str(e).splitlines()[0][:120])

def g_clamp(ph_name, const):
    def build():
        g = torch.fx.Graph(); x = g.placeholder(ph_name)
        g.output(g.call_function(torch.clamp, (x,), {"max": const})); return g
    return build

x = torch.tensor([1.0, 5.0, -3.0])
for ph in ("x", "inf", "nan", "torch", "device", "math", "operator", "NoneType", "fx_pytree", "pytree", "self", "builtins", "float", "int", "True_", "None_"):
    check(f"placeholder named {ph!r}, clamp(max=inf)", g_clamp(ph, float("inf")), x)
check("placeholder 'nan', where(x>0, x, nan)", lambda: (lambda g: (g.output(g.call_function(torch.where, (g.call_function(operator.gt, (p := g.placeholder("nan"), 0)), p, float("nan")))), g)[1])(torch.fx.Graph()), x)

# symbolic_trace of ordinary functions whose argument names collide
def f_inf(inf):
    return torch.clamp(inf, max=float("inf")) + torch.full((3,), float("inf")).isinf()
def f_nan(nan):
    return torch.nan_to_num(nan, nan=0.0) + torch.tensor(float("nan")).isnan()
def f_torch(torch_):
    return torch_.relu()
for f in (f_inf, f_nan, f_torch):
    try:
        t = torch.fx.symbolic_trace(f)
        print(("   ok  " if torch.equal(t(x), f(x)) else "!! DIFF"), "symbolic_trace", f.__name__, "" if torch.equal(t(x), f(x)) else t.code)
    except Exception as e:
        print("   ERR  symbolic_trace", f.__name__, type(e).__name__, str(e).splitlines()[0][:120])

# node names chosen by the user through Graph.create_node(name=...)
def named(nm):
    def build():
        g = torch.fx.Graph(); p = g.placeholder("x")
        n = g.create_node("call_function", torch.neg, (p,), name=nm)
        g.output(g.call_function(torch.clamp, (n,), {"min": -float("inf"), "max": float("inf")})); return g
    return build
for nm in ("inf", "nan", "torch", "math"):
    check(f"intermediate node named {nm!r}", named(nm), x)
