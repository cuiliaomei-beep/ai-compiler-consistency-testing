"""Observable semantics of one execution (plan section 2).

    Obs(r) = <value, shape, dtype, exception, mutation, alias, gradient>

Alias information is recorded as a *relation* over the flattened list
``[inputs..., outputs...]`` (which indices share storage), never as raw
pointers: eager and compiled executions allocate different memory, so
``data_ptr()`` differs every time and means nothing.
"""
from __future__ import annotations

import os
import traceback
from dataclasses import dataclass, field
from typing import Any, Dict, FrozenSet, List, Optional, Sequence, Tuple

from .compat import torch


def is_tensor(x: Any) -> bool:
    return torch is not None and isinstance(x, torch.Tensor)


def top_frame(exc: BaseException) -> Optional[str]:
    try:
        frames = traceback.extract_tb(exc.__traceback__)
        if not frames:
            return None
        f = frames[-1]
        return f"{os.path.basename(f.filename)}:{f.lineno}:{f.name}"
    except Exception:
        return None


def flatten(obj: Any) -> Tuple[List[Any], str]:
    """Flatten nested containers; the structure string is compared too."""
    items: List[Any] = []

    def walk(o: Any) -> str:
        if is_tensor(o):
            items.append(o)
            return "T"
        if isinstance(o, (list, tuple)):
            kind = "L" if isinstance(o, list) else "P"
            return f"{kind}[{','.join(walk(v) for v in o)}]"
        if isinstance(o, dict):
            keys = sorted(o.keys(), key=repr)
            return "D{" + ",".join(f"{k!r}:{walk(o[k])}" for k in keys) + "}"
        items.append(o)
        return type(o).__name__

    return items, walk(obj)


@dataclass(frozen=True)
class TensorMeta:
    shape: Tuple[int, ...]
    dtype: str
    device: str
    stride: Tuple[int, ...]
    contiguous: bool
    requires_grad: bool
    storage_offset: int
    is_view: bool

    @staticmethod
    def of(t: Any) -> Optional["TensorMeta"]:
        if not is_tensor(t):
            return None
        try:
            stride = tuple(int(s) for s in t.stride())
        except Exception:
            stride = ()
        try:
            contiguous = bool(t.is_contiguous())
        except Exception:
            contiguous = True
        try:
            offset = int(t.storage_offset())
        except Exception:
            offset = 0
        return TensorMeta(tuple(int(d) for d in t.shape), str(t.dtype),
                          str(t.device).split(":")[0], stride, contiguous,
                          bool(t.requires_grad), offset, t._base is not None)

    def as_dict(self) -> Dict[str, Any]:
        return {"shape": list(self.shape), "dtype": self.dtype, "device": self.device,
                "stride": list(self.stride), "contiguous": self.contiguous,
                "requires_grad": self.requires_grad, "storage_offset": self.storage_offset,
                "is_view": self.is_view}


def _storage_id(t: Any) -> Optional[int]:
    if not is_tensor(t):
        return None
    for getter in (lambda: t.untyped_storage().data_ptr(),
                   lambda: t.storage().data_ptr(), lambda: t.data_ptr()):
        try:
            return int(getter())
        except Exception:
            continue
    return None


def alias_relation(tensors: Sequence[Any]) -> FrozenSet[Tuple[int, int]]:
    by: Dict[int, List[int]] = {}
    for i, t in enumerate(tensors):
        sid = _storage_id(t)
        if sid is not None:
            by.setdefault(sid, []).append(i)
    pairs = set()
    for idxs in by.values():
        for a in range(len(idxs)):
            for b in range(a + 1, len(idxs)):
                pairs.add((idxs[a], idxs[b]))
    return frozenset(pairs)


def clone_tree(obj: Any) -> Any:
    if is_tensor(obj):
        try:
            return obj.detach().clone()
        except Exception:
            return obj
    if isinstance(obj, tuple):
        return tuple(clone_tree(v) for v in obj)
    if isinstance(obj, list):
        return [clone_tree(v) for v in obj]
    if isinstance(obj, dict):
        return {k: clone_tree(v) for k, v in obj.items()}
    return obj


@dataclass
class Observation:
    mode: str
    ok: bool = True
    exception: Optional[str] = None
    exception_msg: Optional[str] = None
    #: innermost exception type along __cause__/__context__ (the program's own error
    #: when the compiler re-raised it inside an envelope such as TorchRuntimeError)
    exception_inner: Optional[str] = None
    exc_frame: Optional[str] = None
    infra_error: bool = False

    outputs: Any = None
    out_struct: str = ""
    out_meta: List[Optional[TensorMeta]] = field(default_factory=list)

    inputs_after: Any = None
    in_meta_after: List[Optional[TensorMeta]] = field(default_factory=list)

    alias: FrozenSet[Tuple[int, int]] = frozenset()
    n_inputs: int = 0

    #: O6: gradient w.r.t. each input that required grad (None when unused)
    grads: Optional[List[Any]] = None
    grad_error: Optional[str] = None

    compiles: int = 0
    frames_delta: int = 0
    wall_s: float = 0.0

    def summary(self) -> Dict[str, Any]:
        return {
            "mode": self.mode, "ok": self.ok, "exception": self.exception,
            "exception_inner": self.exception_inner,
            "exception_msg": (self.exception_msg or "")[:600] or None,
            "out_struct": self.out_struct, "compiles": self.compiles,
            "frames_delta": self.frames_delta, "wall_s": round(self.wall_s, 4),
            "alias_pairs": sorted(self.alias), "n_inputs": self.n_inputs,
            "out_meta": [m.as_dict() if m else None for m in self.out_meta],
            "has_grads": self.grads is not None, "grad_error": self.grad_error,
        }


def _gradients(inputs: Any, outputs: Any) -> Tuple[Optional[List[Any]], Optional[str]]:
    """Backward through a scalar loss over every float output; grads per leaf input."""
    if torch is None:
        return None, None
    in_items, _ = flatten(inputs)
    leaves = [t for t in in_items if is_tensor(t) and t.requires_grad]
    if not leaves:
        return None, None
    out_items, _ = flatten(outputs)
    outs = [o for o in out_items if is_tensor(o) and o.requires_grad and o.is_floating_point()]
    if not outs:
        return [None] * len(leaves), None
    try:
        loss = sum((o.to(torch.float64) if o.dtype != torch.float64 else o).sum() for o in outs)
        grads = torch.autograd.grad(loss, leaves, allow_unused=True, retain_graph=False)
        return [g.detach().clone() if g is not None else None for g in grads], None
    except Exception as e:  # noqa: BLE001
        return None, f"{type(e).__name__}: {str(e)[:160]}"


def observe(mode: str, inputs: Any, outputs: Any, exception: Optional[BaseException],
            with_grad: bool = True) -> Observation:
    in_items, _ = flatten(inputs)
    if exception is not None:
        inner = exception
        for _ in range(8):
            nxt = inner.__cause__ or inner.__context__
            if nxt is None or nxt is inner:
                break
            inner = nxt
        try:
            msg = str(exception)[:1500]
        except Exception as e:  # a broken __repr__ inside the message must not take the run down
            msg = f"<unprintable {type(exception).__name__}: {type(e).__name__}>"
        obs = Observation(mode=mode, ok=False, exception=type(exception).__name__,
                          exception_msg=msg, exc_frame=top_frame(exception),
                          exception_inner=type(inner).__name__, n_inputs=len(in_items))
        obs.inputs_after = clone_tree(inputs)
        obs.in_meta_after = [TensorMeta.of(t) for t in in_items]
        return obs
    out_items, out_struct = flatten(outputs)
    obs = Observation(mode=mode, ok=True, out_struct=out_struct,
                      out_meta=[TensorMeta.of(t) for t in out_items],
                      in_meta_after=[TensorMeta.of(t) for t in in_items],
                      n_inputs=len(in_items))
    obs.alias = alias_relation(list(in_items) + list(out_items))
    if with_grad:
        obs.grads, obs.grad_error = _gradients(inputs, outputs)
    obs.outputs = clone_tree(outputs)
    obs.inputs_after = clone_tree(inputs)
    return obs
