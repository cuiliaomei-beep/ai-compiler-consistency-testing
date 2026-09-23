import torch, torch.fx
print("torch", torch.__version__)

def mask_invalid(x, nan):                    # a parameter called `nan` (e.g. a mask of invalid entries)
    return torch.where(nan, float("nan"), x)

def clip_scores(scores, inf):                # a parameter called `inf` (e.g. a per-row upper limit), plus the constant float("inf")
    return torch.clamp(scores, max=float("inf")) + inf

def uses_module(x, torch_scale, math):       # `math` as a parameter name while the graph needs nothing from it: fine
    return x * torch_scale + math

x = torch.tensor([1.0, -2.0, 3.0])
for f, args in ((mask_invalid, (x, torch.tensor([False, True, False]))), (clip_scores, (x, torch.tensor([10.0, 20.0, 30.0]))), (uses_module, (x, 2.0, 1.0))):
    gm = torch.fx.symbolic_trace(f)
    want, interp = f(*args), torch.fx.Interpreter(gm).run(*args)
    try:
        got = gm(*args)
    except Exception as e:
        got = f"raises {type(e).__name__}: {str(e).splitlines()[0][:70]}"
    show = lambda t: t.tolist() if isinstance(t, torch.Tensor) else t
    print(f"{f.__name__:14s} eager {show(want)} | Interpreter {show(interp)} | GraphModule.forward {show(got)}")
    print("    " + gm.code.strip().replace("\n", "\n    "))
