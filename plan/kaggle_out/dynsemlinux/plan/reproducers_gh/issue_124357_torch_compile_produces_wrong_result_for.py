# source: https://github.com/pytorch/pytorch/issues/124357
# title: torch.compile produces wrong result for changing attributes in python class instances
# state: closed  created: 2024-04-18
# mined automatically; the harness records the torch.compile target and its first call

import torch
import torch._dynamo as dynamo
import torch._inductor as inductor
import torch.nn as nn

dynamo.reset()

class ToyModel(torch.nn.Module):
    def __init__(self):
        super(ToyModel, self).__init__()
        self.value = -1
        self.cache = torch.ones([2, 3])
 
    def change_value(self, value):
        self.value = value
 
    def forward(self, value):
        return self.cache + self.value
    
    def print_value(self):
        print(f"model value = {self.value}")
 
  
model = ToyModel()
compiled_function = torch.compile(model, backend="inductor")
 
values = [6, 8, 10]

for value in values:
    model.change_value(value)
    output = compiled_function(value)
    model.print_value()
    print(f"output = {output}")
