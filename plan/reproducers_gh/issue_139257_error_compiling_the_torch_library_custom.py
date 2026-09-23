# source: https://github.com/pytorch/pytorch/issues/139257
# title: Error compiling the torch.library.custom_op with input mutations with set_
# state: open  created: 2024-10-30
# mined automatically; the harness records the torch.compile target and its first call

import torch
from torch import nn

@torch.library.custom_op("mylib::set_data", mutates_args=["param"])
def set_data(param: torch.Tensor, new_data: torch.Tensor) -> None:
    param.set_(new_data) # or param.data = new_data.data


@torch.library.register_fake("mylib::set_data")
def set_data_fake(param: torch.Tensor, new_data: torch.Tensor) -> None:
    param.set_(new_data)
    return None


class SomeModule(nn.Module):
    def __init__(self):
        super().__init__()
        self.param = nn.Parameter(torch.empty(0))

    def forward(self, x):
        x = x * 3
        y = self.param
        set_data(y, x)
        return y / 3


module = SomeModule()  
module = torch.compile(module)

x = torch.randn(3, 3)
with torch.no_grad():
  y = module(x)

print(y)
