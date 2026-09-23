# source: https://github.com/pytorch/pytorch/issues/172711
# title: torch.compile produces wrong output channels for mkldnn._convolution_transpose_pointwise (FakeTensor shape inference bug) 
# state: closed  created: 2026-01-17
# mined automatically; the harness records the torch.compile target and its first call

import torch
import torch.nn as nn
import torch._dynamo.utils

# Fuzzer requirements: use fallback_random for deterministic RNG
torch._inductor.config.fallback_random = True
torch.set_num_threads(1)

class Model(nn.Module):
    def __init__(self):
        super().__init__()
        # Weight layout: (in_channels, out_channels, kH, kW) - same as nn.ConvTranspose2d
        self.weight = nn.Parameter(torch.randn(3, 8, 3, 3))  # in=3, out=8
        self.bias = nn.Parameter(torch.randn(8))

    def forward(self, x):
        # Schema: mkldnn::_convolution_transpose_pointwise(X, W, B, padding, output_padding, stride, dilation, groups, attr, scalars, algorithm)
        y = torch.ops.mkldnn._convolution_transpose_pointwise.default(
            x,
            self.weight,
            self.bias,
            [1, 1],      # padding
            [1, 1],      # output_padding
            [2, 2],      # stride
            [1, 1],      # dilation
            1,           # groups
            "none",      # attr
            [],          # scalars
            ""           # algorithm
        )
        # Post-ops to prevent trivial elimination
        y = torch.add(y, 3)
        y = torch.clamp_min(y, 0)
        y = torch.clamp_max(y, 6)
        return torch.div(y, 6)

def dump(tag, t):
    print(f"{tag}: shape={tuple(t.shape)}, device={t.device}, dtype={t.dtype}, is_mkldnn={t.is_mkldnn}")

# Fuzzer requirements: reset RNG seed before model creation
torch.manual_seed(9150)
model = Model().eval()
x = torch.randn(4, 3, 16, 16)

print("=== Configuration ===")
dump("input", x)
print(f"weight.shape={tuple(model.weight.shape)}, bias.shape={tuple(model.bias.shape)}")
print(f"Expected output channels: {model.weight.shape[1]} (from weight.shape[1])")

@torch.no_grad()
def test():
    # Fuzzer requirements: reset RNG seed before each execution
    torch.manual_seed(9150)
    print("\n--- Eager ---")
    y1 = model(x)
    dump("eager_out", y1)

    torch.manual_seed(9150)
    print("\n--- torch.compile (fullgraph=True) ---")
    compiled_model = torch.compile(model, fullgraph=True)
    y2 = compiled_model(x)
    dump("compiled_out", y2)

    print("\n--- Verification ---")
    print(f"Shape match: {tuple(y1.shape) == tuple(y2.shape)}")
    
    # NOTE: This is a SHAPE MISMATCH bug, not a numerical precision issue.
    # Shape comparison fails before we can even use torch._dynamo.utils.same()
    # with fp64_ref for numerical comparison.
    if tuple(y1.shape) != tuple(y2.shape):
        raise RuntimeError(
            f"SHAPE MISMATCH: eager={tuple(y1.shape)} compiled={tuple(y2.shape)}\n"
            f"Cannot use torch._dynamo.utils.same() - shapes differ!"
        )
    
    # If shapes matched, we would use fp64_ref comparison (shown for completeness):
    # is_same = torch._dynamo.utils.same(y2, y1, fp64_ref=y1.double(), tol=torch._dynamo.config.repro_tolerance)

test()
