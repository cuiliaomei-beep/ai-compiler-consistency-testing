# source: https://github.com/pytorch/pytorch/issues/157909
# title: Inconsistent behavior between eager and compiled mode for `F.conv_transpose2d`
# state: closed  created: 2025-07-09
# mined automatically; the harness records the torch.compile target and its first call

import torch
import torch.nn as nn
import torch.nn.functional as F

class MyModel(nn.Module):
    def __init__(self):
        super().__init__()
        self.weight = nn.Parameter(torch.randn(1, 1, 2, 2, requires_grad=True))

    def forward(self, x):
        return F.conv_transpose2d(x, self.weight, stride=2, padding=2)

if __name__ == "__main__":
    model = MyModel().to("cuda")
    input_tensor = torch.randn(1, 1, 2, 2).to("cuda")

    try:
        with torch.no_grad():
            output = model(input_tensor)
        print("Eager output:", output)
    except Exception as e:
        print("Error:", e)

    try:
        with torch.no_grad():
            output = model.to("cpu")(input_tensor.to("cpu"))
        print("Eager output cpu:", output)
    except Exception as e:
        print("Error:", e)

    compiled_model = torch.compile(model, dynamic=True, backend='cudagraphs').to("cuda")
    input_tensor = input_tensor.to("cuda")

    try:
        with torch.no_grad():
            output = compiled_model(input_tensor)
        print("Compiled output:", output)
    except Exception as e:
        print("Error:", e)
