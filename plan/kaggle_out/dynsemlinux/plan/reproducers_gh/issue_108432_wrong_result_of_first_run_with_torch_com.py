# source: https://github.com/pytorch/pytorch/issues/108432
# title: Wrong result of first run with torch.compile() when backend is using torch.jit.trace() and model has inplace operators 
# state: closed  created: 2023-09-01
# mined automatically; the harness records the torch.compile target and its first call

import torch

class Inplace(torch.nn.Module):
    def __init__(self):
        super(Inplace, self).__init__()

    def forward(self, input, input2):
        input.add_(input2)
        return input.add_(input2)
    
inplace = Inplace()
    
compiled = torch.compile(inplace, backend="aio")

res = inplace(torch.tensor(1), torch.tensor(2))

print(res)

inputs = (torch.tensor(1), torch.tensor(2))

res = compiled(torch.tensor(1), torch.tensor(2))

print(res)

res = compiled(torch.tensor(1), torch.tensor(2))

print(res)
