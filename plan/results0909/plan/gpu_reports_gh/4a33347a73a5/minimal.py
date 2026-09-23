import torch
torch.manual_seed(0)

def pattern(A, B, a_scale, b_scale):
    return torch.ops.demo.fp8_gemm(A, B.t(), a_scale, b_scale)

args = (torch.randn(1, 1).requires_grad_(True), torch.randn(1, 1), torch.randn(1, 1), torch.randn(1, 1))

eager = pattern(*args)
torch._dynamo.reset()
compiled = torch.compile(pattern, backend='inductor')(*args)
print('eager   :', eager)
print('compiled:', compiled)
