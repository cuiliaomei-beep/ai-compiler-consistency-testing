import torch
torch.manual_seed(0)

def eager(input, top, left, height, width):

    output = input - torch.tensor([left, top, left, top], dtype=input.dtype, device=input.device)

    output[..., 0::2].clamp_(min=0, max=width)

    output[..., 1::2].clamp_(min=0, max=height)

    return output

args = (torch.randn(1, 4).to(torch.float16),)

eager = eager(*args)
torch._dynamo.reset()
compiled = torch.compile(eager, backend='eager')(*args)
print('eager   :', eager)
print('compiled:', compiled)
