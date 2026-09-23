# source: https://github.com/pytorch/pytorch/issues/171979
# title: Inductor fails to compile models using `torch.cat` with `axis` keyword argument
# state: closed  created: 2026-01-08
# mined automatically; the harness records the torch.compile target and its first call

import torch.nn as nn
import torch
from torch import nn


class TestModel(nn.Module):

    def __init__(self):
        super(TestModel, self).__init__()
        self.stack = nn.Sequential(
            nn.Linear(256, 128),
            nn.Linear(128, 64),
            nn.Linear(64, 10)
        )

    def forward(self, x, t):
        X = torch.cat([x, t], axis=1)
        X = torch.relu(X)
        return X

input1 = torch.randn(16, 200)
input2 = torch.randn(16, 56)
model = TestModel()


def run_test(model, input, backend):
    try:
        model = torch.compile(model, backend=backend)
        output = model(*input)
        print(f"succeed on {backend}")
    except Exception as e:
        print(f"failed on {backend}:", str(e))
        

run_test(model, [input1, input2], "eager")
run_test(model, [input1, input2], "aot_eager")
run_test(model, [input1, input2], "inductor")
