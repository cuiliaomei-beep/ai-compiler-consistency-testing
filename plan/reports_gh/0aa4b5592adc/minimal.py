import torch
torch.manual_seed(0)

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

args = (torch.randn(1, 3, 2, 16).requires_grad_(True),)

eager = f(*args)
torch._dynamo.reset()
compiled = torch.compile(f, backend='inductor')(*args)
print('eager   :', eager)
print('compiled:', compiled)
