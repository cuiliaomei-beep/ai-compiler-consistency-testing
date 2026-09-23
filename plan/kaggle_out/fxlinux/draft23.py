import torch, torch.fx

def mask_invalid(x, nan):                 # `nan`: a boolean mask of invalid entries
    return torch.where(nan, float("nan"), x)

def clip_scores(scores, inf):             # `inf`: a per-element offset; the clamp bound is the constant float("inf")
    return torch.clamp(scores, max=float("inf")) + inf

x = torch.tensor([1.0, 50.0, 3.0])
for f, args in ((mask_invalid, (x, torch.tensor([False, True, False]))), (clip_scores, (x, torch.tensor([10.0, 20.0, 30.0])))):
    gm = torch.fx.symbolic_trace(f)
    print(f.__name__)
    print("    eager              ", f(*args).tolist())
    print("    fx.Interpreter     ", torch.fx.Interpreter(gm).run(*args).tolist())
    print("    GraphModule.forward", gm(*args).tolist())
    print("    " + gm.code.strip().replace("\n", "\n    "))
