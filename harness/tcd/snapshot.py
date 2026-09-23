"""Observable state capture: values, metadata, mutation and alias relations.

The harness compares *observations*, not raw objects. An observation is the
five-tuple from the research plan::

    Obs(r) = < value, exception, input_mutation, alias_relation, output_metadata >

One rule governs the alias part and it is easy to get wrong: **absolute
pointers are not comparable across executions.** Eager and compiled runs
allocate different memory, so ``data_ptr()`` always differs and means nothing.
What *is* comparable is the *relation* — which tensors among (inputs +
outputs) share storage with each other. That relation is the thing a compiler
must preserve, so that is what we record and diff.
"""
from __future__ import annotations

from dataclasses import dataclass, field
from typing import Any, Dict, FrozenSet, List, Optional, Sequence, Tuple

from .torchcompat import torch


# --------------------------------------------------------------------------
# flattening
# --------------------------------------------------------------------------

def _is_tensor(x: Any) -> bool:
    return torch is not None and isinstance(x, torch.Tensor)


def top_frame(exc: BaseException) -> Optional[str]:
    """Deepest traceback frame as ``basename:line:function``.

    Coarse on purpose: it goes into the dedup signature, where the same defect
    reached by slightly different inputs must land in one bucket.
    """
    import os
    import traceback

    try:
        frames = traceback.extract_tb(exc.__traceback__)
        if not frames:
            return None
        f = frames[-1]
        return f"{os.path.basename(f.filename)}:{f.lineno}:{f.name}"
    except Exception:
        return None


def flatten(obj: Any, _path: str = "") -> Tuple[List[Any], str]:
    """Flatten a nested structure into (tensors_and_scalars, structure string).

    The structure string is part of the comparison: a compiled function that
    returns a list where eager returned a tuple has already diverged.
    """
    items: List[Any] = []

    def walk(o: Any, path: str) -> str:
        if _is_tensor(o):
            items.append(o)
            return "T"
        if isinstance(o, (list, tuple)):
            kind = "L" if isinstance(o, list) else "P"
            inner = ",".join(walk(v, f"{path}.{i}") for i, v in enumerate(o))
            return f"{kind}[{inner}]"
        if isinstance(o, dict):
            keys = sorted(o.keys(), key=repr)
            inner = ",".join(f"{k!r}:{walk(o[k], f'{path}.{k}')}" for k in keys)
            return f"D{{{inner}}}"
        items.append(o)
        return type(o).__name__

    struct = walk(obj, _path)
    return items, struct


# --------------------------------------------------------------------------
# metadata
# --------------------------------------------------------------------------

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
        if not _is_tensor(t):
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
        return TensorMeta(
            shape=tuple(int(d) for d in t.shape),
            dtype=str(t.dtype),
            # device *type* only: cuda:0 vs cuda:1 is not a semantic difference
            device=str(t.device).split(":")[0],
            stride=stride,
            contiguous=contiguous,
            requires_grad=bool(t.requires_grad),
            storage_offset=offset,
            is_view=t._base is not None,
        )

    def as_dict(self) -> Dict[str, Any]:
        return {
            "shape": list(self.shape),
            "dtype": self.dtype,
            "device": self.device,
            "stride": list(self.stride),
            "contiguous": self.contiguous,
            "requires_grad": self.requires_grad,
            "storage_offset": self.storage_offset,
            "is_view": self.is_view,
        }


def _storage_id(t: Any) -> Optional[int]:
    """Identity of the underlying allocation, across torch versions."""
    if not _is_tensor(t):
        return None
    for getter in (
        lambda: t.untyped_storage().data_ptr(),
        lambda: t.storage().data_ptr(),
        lambda: t.data_ptr(),
    ):
        try:
            return int(getter())
        except Exception:
            continue
    return None


def alias_relation(tensors: Sequence[Any]) -> FrozenSet[Tuple[int, int]]:
    """Index pairs that share storage.

    Comparable across executions in a way pointers are not. With inputs and
    outputs flattened into one indexed list, this captures input-output
    aliasing (the functionalization question) as well as output-output.
    """
    by_storage: Dict[int, List[int]] = {}
    for i, t in enumerate(tensors):
        sid = _storage_id(t)
        if sid is None:
            continue
        by_storage.setdefault(sid, []).append(i)
    pairs = set()
    for idxs in by_storage.values():
        for a in range(len(idxs)):
            for b in range(a + 1, len(idxs)):
                pairs.add((idxs[a], idxs[b]))
    return frozenset(pairs)


# --------------------------------------------------------------------------
# value snapshots
# --------------------------------------------------------------------------

def clone_value(x: Any) -> Any:
    """A detached copy that survives later in-place writes to the original."""
    if _is_tensor(x):
        try:
            return x.detach().clone()
        except Exception:
            return x
    return x


def clone_tree(obj: Any) -> Any:
    if _is_tensor(obj):
        return clone_value(obj)
    if isinstance(obj, tuple):
        return tuple(clone_tree(v) for v in obj)
    if isinstance(obj, list):
        return [clone_tree(v) for v in obj]
    if isinstance(obj, dict):
        return {k: clone_tree(v) for k, v in obj.items()}
    return obj


@dataclass
class Observation:
    """Everything one execution reveals."""

    mode: str
    ok: bool = True
    exception: Optional[str] = None
    exception_msg: Optional[str] = None
    #: "file.py:line:function" of the deepest frame - part of the dedup signature
    exc_frame: Optional[str] = None
    #: True when the *toolchain* failed (no compiler, no triton, OOM) rather
    #: than the program behaving differently. Such layers are excluded from
    #: comparison entirely - they carry no semantic information.
    infra_error: bool = False

    outputs: Any = None
    out_struct: str = ""
    out_meta: List[Optional[TensorMeta]] = field(default_factory=list)

    # inputs *after* the call, for the mutation oracle
    inputs_after: Any = None
    in_meta_after: List[Optional[TensorMeta]] = field(default_factory=list)

    # relation over [inputs..., outputs...]
    alias: FrozenSet[Tuple[int, int]] = frozenset()
    n_inputs: int = 0

    # O6: one gradient per differentiable leaf (inputs that require grad, then
    # any parameters the case exposes), from a single backward pass. ``None``
    # entries are leaves autograd did not reach. ``grads`` itself is None when
    # there was nothing to differentiate; ``grad_error`` says why backward
    # could not run when it was attempted.
    grads: Optional[List[Any]] = None
    grad_error: Optional[str] = None

    compiles: int = 0
    frames_delta: int = 0
    wall_s: float = 0.0

    def summary(self) -> Dict[str, Any]:
        return {
            "mode": self.mode,
            "ok": self.ok,
            "exception": self.exception,
            "out_struct": self.out_struct,
            "compiles": self.compiles,
            "frames_delta": self.frames_delta,
            "wall_s": round(self.wall_s, 4),
            "alias_pairs": sorted(self.alias),
            "out_meta": [m.as_dict() if m else None for m in self.out_meta],
            "n_grads": len(self.grads) if self.grads is not None else None,
            "grad_error": self.grad_error,
        }


def observe(mode: str, inputs: Any, outputs: Any, exception: Optional[BaseException]) -> Observation:
    """Build an Observation from a completed (or failed) execution."""
    in_items, _ = flatten(inputs)
    if exception is not None:
        obs = Observation(
            mode=mode,
            ok=False,
            exception=type(exception).__name__,
            exception_msg=str(exception)[:400],
            exc_frame=top_frame(exception),
            n_inputs=len(in_items),
        )
        obs.inputs_after = clone_tree(inputs)
        obs.in_meta_after = [TensorMeta.of(t) for t in in_items]
        return obs

    out_items, out_struct = flatten(outputs)
    obs = Observation(
        mode=mode,
        ok=True,
        outputs=clone_tree(outputs),
        out_struct=out_struct,
        out_meta=[TensorMeta.of(t) for t in out_items],
        inputs_after=clone_tree(inputs),
        in_meta_after=[TensorMeta.of(t) for t in in_items],
        n_inputs=len(in_items),
    )
    # relation computed on the LIVE tensors, before cloning breaks aliasing
    obs.alias = alias_relation(list(in_items) + list(out_items))
    return obs
