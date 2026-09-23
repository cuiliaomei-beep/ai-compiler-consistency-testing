# source: https://github.com/pytorch/pytorch/issues/176599
# title: torch.compile bypasses `@property` setter and getter logic during compilation.
# state: closed  created: 2026-03-05
# mined automatically; the harness records the torch.compile target and its first call

def test_property_getter_setter():
    class Box:
        def __init__(self, v):
            self._v = v
        @property
        def value(self):
            return self._v + 1
        @value.setter
        def value(self, v):
            self._v = v * 2
    def fn(x):
        b = Box(3)
        b.value = 5        # setter: _v becomes 10
        return x + b.value  # getter: 10 + 1 = 11
    inp = torch.tensor([0.0])
    eager = fn(inp)
    compiled = torch.compile(fn, backend="eager")(inp)
    assert torch.equal(eager, compiled), f"Expected {eager}, got {compiled}"
