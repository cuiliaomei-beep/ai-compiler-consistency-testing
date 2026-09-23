import torch
torch.manual_seed(0)

def rollout(state0, xs):
    def body(s, x):
        s_new = torch.tanh(s @ W + x)
        return s_new, s_new.clone()            # documented pattern: emitted slice is a clone of the carry
    _, ys = scan(body, state0, xs)
    return ys

args = (torch.randn(4, 8), torch.randn(16, 4, 8))

eager = rollout(*args)
torch._dynamo.reset()
compiled = torch.compile(rollout, backend='eager')(*args)
print('eager   :', eager)
print('compiled:', compiled)
