# source: https://github.com/pytorch/pytorch/issues/174016
# title: [Inductor] cumprod backward produces incorrect gradients when input contains zeros
# state: closed  created: 2026-02-01
# mined automatically; the harness records the torch.compile target and its first call

import torch

device = 'cuda'
torch.manual_seed(42)

def test():
    # Create input with zeros
    x = torch.rand(4, 8, 32, device=device, requires_grad=True)
    x.data[:, 4, :] = 0  # Insert zeros at position 4
    x_ref = x.clone().detach().requires_grad_(True)

    def fn(x):
        return x.cumprod(dim=1).sum()

    # Eager backward
    fn(x_ref).backward()

    # Compiled backward with inductor
    torch._dynamo.reset()
    compiled_fn = torch.compile(fn, fullgraph=True, backend='inductor')
    compiled_fn(x).backward()

    # Compare gradients
    print(f"Eager grad at zeros: {x_ref.grad[0, 4, :3]}")
    print(f"Inductor grad at zeros: {x.grad[0, 4, :3]}")  # All zeros - WRONG!
    
    torch.testing.assert_close(x.grad, x_ref.grad, atol=1e-4, rtol=1e-4)

test()
