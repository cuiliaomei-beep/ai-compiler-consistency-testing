import torch
torch.manual_seed(0)

def foo(input):
    interpolate = torch.nn.functional.interpolate(
        input,
        size=[40, 40],
        scale_factor=None,
        mode="bicubic",
        align_corners=None,
        recompute_scale_factor=None,
        antialias=False,
    )
    squeeze = interpolate.squeeze(0)
    argmin = squeeze.argmin(1)
    return argmin

args = (torch.randn(1, 2, 1, 1).to(torch.float16),)

eager = foo(*args)
torch._dynamo.reset()
compiled = torch.compile(foo, backend='inductor')(*args)
print('eager   :', eager)
print('compiled:', compiled)
