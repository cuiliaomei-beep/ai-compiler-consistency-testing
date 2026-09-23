# source: https://github.com/pytorch/pytorch/issues/176596
# title: torch.compile does not correctly invoke property setter during object initialization
# state: closed  created: 2026-03-05
# mined automatically; the harness records the torch.compile target and its first call

import torch

def test_property_setter_during_init():
    class Clamped:
        def __init__(self, val):
            self.value = val

        @property
        def value(self):
            return self._value

        @value.setter
        def value(self, v):
            self._value = max(0, min(v, 100))  # clamp to [0, 100]

    def fn(x):
        c = Clamped(int(x.item()))
        return torch.tensor(float(c.value))

    for val in [torch.tensor(50.0), torch.tensor(200.0), torch.tensor(-10.0)]:
        eager = fn(val)
        compiled = torch.compile(fn, backend="eager", fullgraph=False)(val)
        assert torch.equal(eager, compiled), \
            f"For {val}: expected {eager}, got {compiled}"

test_property_setter_during_init()
