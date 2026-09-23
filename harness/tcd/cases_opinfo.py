"""Build cases from PyTorch's own OpInfo database.

The mutation operators need *programs that currently pass*, and the corpus so
far had sixteen of them — nine reproducers of already-reported bugs and seven
hand-written fixtures. A run over that corpus found nothing new, and could not
have: a few hundred executions over three-line functions is not a search.

``torch.testing._internal.common_methods_invocations.op_db`` holds ~700
operators, each with a generator of valid sample inputs — several thousand
known-good invocations that PyTorch's own test suite runs against. They are
maintained upstream, guaranteed valid, and nobody has run them through
structural mutation plus cold/warm differential execution.

Each case is emitted **with source text**, because the mutation operators
rewrite source. The generated function is deliberately plain::

    def f(a0, a1):
        return _OP(a0, a1, **_KW)

so that ``a0[:]``, an injected alias write, or a deepened view can be spliced
into it by the same AST transforms that handle hand-written cases.
"""
from __future__ import annotations

from typing import Any, Dict, Iterator, List, Optional, Sequence, Tuple

from .case import Case, Context, register
from .torchcompat import declares_aliasing, seed_everything, torch

_OP_DB: Optional[List[Any]] = None
_LOAD_ERROR: Optional[str] = None


def load_op_db() -> Tuple[Optional[List[Any]], Optional[str]]:
    """Import op_db lazily; it is slow and pulls in test-only dependencies."""
    global _OP_DB, _LOAD_ERROR
    if _OP_DB is not None or _LOAD_ERROR is not None:
        return _OP_DB, _LOAD_ERROR
    try:
        from torch.testing._internal.common_methods_invocations import op_db
        _OP_DB = list(op_db)
    except Exception as e:  # expecttest missing, version drift, ...
        _LOAD_ERROR = f"{type(e).__name__}: {e}"
    return _OP_DB, _LOAD_ERROR


def _is_tensor(x: Any) -> bool:
    return torch is not None and isinstance(x, torch.Tensor)


def _clone(x: Any) -> Any:
    """Fresh storage, same values, same layout and grad-ness.

    ``make_inputs`` must hand out newly allocated tensors on every call, or one
    execution's in-place writes leak into the next and the mutation oracle
    reports a divergence nobody caused. Cloning is far cheaper than
    regenerating the sample, and ``clone()`` preserves strides.
    """
    if not _is_tensor(x):
        return x
    t = x.detach().clone()
    if x.requires_grad:
        t.requires_grad_(True)
    return t


def _derived_contexts(src: str) -> List[Context]:
    """Contexts derived from the function itself - plan sections 9 and 10.

    Previously three hard-coded contexts were used for every case, identical
    regardless of what the function read. That made the plan's central claim -
    statically decide which factors are worth changing - vacuous.
    """
    from .obligation import contexts_for_source
    try:
        contexts, _scs, _obs = contexts_for_source(src)
        return contexts
    except Exception:
        return [Context("base", {"variant": "base"})]


def _make_source(n_params: int, has_kwargs: bool) -> str:
    names = [f"a{i}" for i in range(n_params)]
    kw = ", **_KW" if has_kwargs else ""
    return f"def f({', '.join(names)}):\n    return _OP({', '.join(names)}{kw})\n"


def _build(op: Any, sample: Any, index: int,
           dtype_name: str) -> Optional[Case]:
    from .seeds import _apply_context  # shared context transforms

    args = (sample.input,) + tuple(getattr(sample, "args", ()) or ())
    kwargs = dict(getattr(sample, "kwargs", {}) or {})

    # A tensor hidden in kwargs would be shared across executions, since only
    # the positional args are rebuilt per call. Skip rather than risk it.
    if any(_is_tensor(v) for v in kwargs.values()):
        return None
    if not args or not _is_tensor(args[0]):
        return None
    if len(args) > 4:
        return None

    src = _make_source(len(args), bool(kwargs))
    ns: Dict[str, Any] = {"_OP": op.op, "_KW": kwargs, "torch": torch}
    try:
        exec(compile(src, f"<opinfo:{op.name}:{index}>", "exec"), ns)
    except Exception:
        return None
    fn = ns.get("f")
    if not callable(fn):
        return None

    base_args = tuple(args)

    def make_inputs(ctx: Context, _base=base_args) -> Tuple[Any, ...]:
        return _apply_context(tuple(_clone(a) for a in _base), ctx)

    # Whether an alias-relation change is even a defect for this operator is
    # decided by its schema, not by what eager happens to do (see
    # torchcompat.declares_aliasing).
    aten_name = op.name.split(".")[-1]
    contract = declares_aliasing(aten_name)

    safe = op.name.replace(".", "_").replace("-", "_")
    return Case(
        alias_contract=contract,
        name=f"op_{safe}_{index}",
        fn=fn,
        make_inputs=make_inputs,
        contexts=_derived_contexts(src),
        tags=["opinfo", op.name],
        notes=f"torch OpInfo `{op.name}` sample #{index} ({dtype_name})",
        source=src,
    )


#: Operators whose schema declares an alias relation are where structural
#: mutation can actually bite: adding a view around `conv2d` cannot produce an
#: aliasing defect, because conv2d never aliases anything. Prioritising this
#: family concentrates the budget where the targeted bug class lives.
def _alias_family(op_name: str) -> bool:
    return declares_aliasing(op_name.split(".")[-1]) is True


def iter_cases(
    limit_ops: int = 0,
    samples_per_op: int = 1,
    dtype: str = "float32",
    device: str = "cpu",
    only: Optional[Sequence[str]] = None,
    seed: int = 0,
    alias_ops_first: bool = False,
) -> Iterator[Case]:
    """Yield cases built from the OpInfo database.

    ``limit_ops=0`` means every operator. ``samples_per_op`` caps how many
    sample inputs are taken per operator, which is the main size dial: the
    database offers several thousand samples in total and a full Inductor pass
    over all of them takes many hours.
    """
    db, err = load_op_db()
    if db is None:
        return
    if torch is None:
        return

    want = getattr(torch, dtype, None)
    if want is None:
        return

    names = set(only) if only else None
    ordered = list(db)
    if alias_ops_first:
        ordered.sort(key=lambda o: 0 if _alias_family(o.name) else 1)
    n_ops = 0
    for op in ordered:
        if names is not None and op.name not in names:
            continue
        if limit_ops and n_ops >= limit_ops:
            break
        n_ops += 1
        seed_everything(seed)
        try:
            samples = op.sample_inputs(device, want, requires_grad=False)
        except Exception:
            continue
        taken = 0
        try:
            for i, sample in enumerate(samples):
                if taken >= samples_per_op:
                    break
                case = _build(op, sample, i, dtype)
                if case is not None:
                    taken += 1
                    yield case
        except Exception:
            continue


def register_opinfo_cases(**kwargs) -> List[Case]:
    """Build and register OpInfo cases; returns the ones that registered."""
    out: List[Case] = []
    for case in iter_cases(**kwargs):
        try:
            register(case)
            out.append(case)
        except ValueError:
            continue
    return out


def validate_cases(cases: Sequence[Case], seed: int = 0
                   ) -> Tuple[List[Case], List[Tuple[str, str]]]:
    """Keep only cases that actually run in eager under their base context.

    A generated case that cannot execute is not a test; it would otherwise show
    up later as an "exception divergence" against every compiled backend.
    """
    from .execution import run_eager

    ok: List[Case] = []
    bad: List[Tuple[str, str]] = []
    for case in cases:
        try:
            obs = run_eager(case, case.contexts[0], seed)
        except Exception as e:
            bad.append((case.name, f"{type(e).__name__}: {str(e)[:80]}"))
            continue
        if obs.ok:
            ok.append(case)
        else:
            bad.append((case.name, f"{obs.exception}: {(obs.exception_msg or '')[:80]}"))
    return ok, bad
