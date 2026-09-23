# source: https://github.com/pytorch/pytorch/issues/181653
# title: torch.compile(torch.func.grad(fn)) hangs indefinitely on models with pooling ops — sympy.simplify exponential recursion in stride_at
# state: open  created: 2026-04-27
# mined automatically; the harness records the torch.compile target and its first call

# Minimal (crash_069d43ec)
import torch, torch.nn as nn, torch.func as tf

m1, m2, m3 = nn.MaxPool2d(2), nn.AvgPool2d(2), nn.MaxPool2d(2)
t = torch.randn([8, 10, 11, 10])

def fn(x): return m3(m2(m1(x))).mean()

torch.func.grad(fn)(t)                  # OK
torch.compile(torch.func.grad(fn))(t)   # hangs

# Variant 1 (crash_8161ebbd): tanh → RReLU → AvgPool2d → AvgPool2d → MaxPool2d
import torch, torch.nn as nn, torch.func as tf

m1, m2, m3, m4 = nn.RReLU().eval(), nn.AvgPool2d(2), nn.AvgPool2d(2), nn.MaxPool2d(2)
t = torch.randn([10, 12, 16, 12])

def fn(x): return m4(m3(m2(m1(torch.tanh(x))))).mean()
torch.compile(torch.func.grad(fn))(t)   # hangs

# Variant 2 (crash_a22e8c5b): AvgPool2d × 3 → sqrt(clamp)
import torch, torch.nn as nn, torch.func as tf

m1, m2, m3 = nn.AvgPool2d(2), nn.AvgPool2d(2), nn.AvgPool2d(2)
t = torch.randn([5, 12, 15, 10])

def fn(x): return torch.sqrt(torch.clamp(m3(m2(m1(x))), min=1e-6)).mean()

torch.compile(torch.func.grad(fn))(t)   # hangs
