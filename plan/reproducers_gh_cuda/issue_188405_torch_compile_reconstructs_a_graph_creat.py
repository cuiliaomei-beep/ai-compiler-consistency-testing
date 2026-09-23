# source: https://github.com/pytorch/pytorch/issues/188405
# title: torch.compile reconstructs a graph-created torch.Stream/torch.Event subclass as the base class, losing the subclass type across a graph break
# state: open  created: 2026-06-29
# mined automatically; the harness records the torch.compile target and its first call

import torch
import torch.nn as nn
from torch._dynamo.variables.user_defined import UserDefinedClassVariable


# A minimal out-of-tree backend: Stream/Event subclasses of torch.Stream/Event.
class MyStream(torch.Stream):
    pass


class MyEvent(torch.Event):
    def wait(self, stream=None):
        if stream is None:
            stream = torch.accelerator.current_stream()
        # Backends typically assume the stream is their own subclass; in C++ this is
        # a reinterpret_cast to the backend stream struct. Raise here to surface the
        # type loss deterministically (no device required, no record() needed).
        if not isinstance(stream, MyStream):
            raise RuntimeError(
                f"Expected MyStream, got {type(stream).__name__} "
                f"(subclass type lost during dynamo reconstruction)"
            )
        # Skip the real wait() to avoid depending on device event/stream support.
        return None


# Register the subclasses with dynamo, mirroring how in-tree backends
# (cuda/xpu/hpu) are listed in _in_graph_classes.
_orig_in_graph = UserDefinedClassVariable._in_graph_classes
UserDefinedClassVariable._in_graph_classes = staticmethod(
    lambda: _orig_in_graph() | {MyStream, MyEvent}
)


class Net(nn.Module):
    def forward(self, x):
        s = MyStream()
        e = MyEvent()
        torch._dynamo.graph_break()  # forces reconstruction of s/e on resume
        e.wait(s)  # reconstructed s must still be MyStream, not torch.Stream
        return x


if __name__ == "__main__":
    out = torch.compile(Net(), backend="eager", fullgraph=False)(torch.ones((2, 2)))
    print("OK:", out.shape)
