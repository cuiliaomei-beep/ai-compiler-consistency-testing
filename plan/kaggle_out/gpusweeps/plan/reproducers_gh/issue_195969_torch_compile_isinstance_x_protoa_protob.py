# source: https://github.com/pytorch/pytorch/issues/195969
# title: torch.compile: isinstance(x, ProtoA | ProtoB) silently returns False for runtime_checkable Protocols with non-method members
# state: open  created: 2026-09-04
# mined automatically; the harness records the torch.compile target and its first call

from typing import Protocol, runtime_checkable

import torch


@runtime_checkable
class HasPorts(Protocol):          # non-method (data) member
    ports: tuple[int, ...]


@runtime_checkable
class HasFoo(Protocol):            # method member
    def foo(self) -> int: ...


class Obj:
    ports = (1, 2)

    def foo(self) -> int:
        return 1


def single(o):     return isinstance(o, HasPorts)
def union(o):      return isinstance(o, HasPorts | HasFoo)
def tup(o):        return isinstance(o, (HasPorts, HasFoo))
def union_rev(o):  return isinstance(o, HasFoo | HasPorts)
def workaround(o): return isinstance(o, HasPorts) or isinstance(o, HasFoo)


for fn in (single, union, tup, union_rev, workaround):
    torch._dynamo.reset()
    eager = fn(Obj())
    compiled = torch.compile(fn, backend="eager", fullgraph=True)(Obj())
    print(f"{fn.__name__:<11} eager={eager!s:<6} compiled={compiled!s:<6} "
          f"{'' if eager == compiled else '  <-- WRONG'}")
