# source: https://github.com/pytorch/pytorch/issues/188536
# title: Graph-break reconstruction loses identity of graph-created torch.Event subclasses; record() and wait() operate on different event objects
# state: open  created: 2026-06-30
# mined automatically; the harness records the torch.compile target and its first call

import torch
import torch.nn as nn
from torch._dynamo.variables.user_defined import UserDefinedClassVariable


class MyEvent(torch.Event):
    _counter = 0

    def __init__(self, *args, **kwargs):
        super().__init__(*args, **kwargs)
        MyEvent._counter += 1
        self.eid = MyEvent._counter  # stable logical identity per object

    def record(self, stream=None):
        print(f"  [record] eid={self.eid} id={id(self)}")
        return None

    def wait(self, stream=None):
        print(f"  [wait]   eid={self.eid} id={id(self)}")
        return None


class MyStream(torch.Stream):
    def record_event(self, event=None):
        return None

    def wait_event(self, event):
        return None


_orig = UserDefinedClassVariable._in_graph_classes
UserDefinedClassVariable._in_graph_classes = staticmethod(
    lambda: _orig() | {MyStream, MyEvent}
)


class Net(nn.Module):
    def forward(self, x):
        s = MyStream()
        e = MyEvent()
        e.record(s)
        torch._dynamo.graph_break()  # forces reconstruction of s/e on resume
        e.wait(s)
        return x


if __name__ == "__main__":
    print("=== record() before graph break, wait() after ===")
    out = torch.compile(Net(), backend="eager", fullgraph=False)(torch.ones((2, 2)))
    print("out:", out.shape)
