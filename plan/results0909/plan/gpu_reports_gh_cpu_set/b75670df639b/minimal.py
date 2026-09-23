import torch
torch.manual_seed(0)

def fn(logits, prob_targets, weight):
    return F.cross_entropy(
        logits,
        prob_targets,
        weight=weight,
        reduction="none",
    )

args = (torch.randn(4, 3), torch.randn(4, 3), torch.randn(3))

eager = fn(*args)
torch._dynamo.reset()
compiled = torch.compile(fn, backend='eager')(*args)
print('eager   :', eager)
print('compiled:', compiled)
