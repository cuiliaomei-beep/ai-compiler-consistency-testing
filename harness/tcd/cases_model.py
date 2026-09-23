"""Multi-operator programs: the shape real model code actually has.

Three campaigns over single-operator programs found nothing, and the reason is
probably structural rather than a tuning problem. The 22 memory-related bugs in
the published benchmark come from real model code - several operators in
sequence, views threaded between them, state carried across calls. What we had
been testing was one operator call with a view wrapped around it, which may
simply never reach the complexity where those defects live.

Two sources here, each contributing something single-operator cases cannot:

* ``module_db`` - PyTorch's own database of ``nn.Module`` test cases. Modules
  carry **parameters and buffers**, and some mutate them in place during the
  forward pass (``BatchNorm`` updates ``running_mean`` / ``running_var``). That
  is in-place mutation of *module state* rather than of an input tensor, which
  takes a different path through functionalization.

* **synthesised chains** - several shape-preserving operations composed in
  sequence, with views and in-place writes interleaved between them. This is
  the multi-layer structure, and unlike the module database it is fully under
  our control, so the structural complexity can be dialled up.
"""
from __future__ import annotations

import random
from typing import Any, Dict, Iterator, List, Optional, Sequence, Tuple

from .case import Case, Context, register
from .torchcompat import seed_everything, torch

_MODULE_DB: Optional[List[Any]] = None


def load_module_db() -> Tuple[Optional[List[Any]], Optional[str]]:
    global _MODULE_DB
    if _MODULE_DB is not None:
        return _MODULE_DB, None
    try:
        from torch.testing._internal.common_modules import module_db
        _MODULE_DB = list(module_db)
        return _MODULE_DB, None
    except Exception as e:
        return None, f"{type(e).__name__}: {e}"


def _contexts(src: str) -> List[Context]:
    """Derived from the program under test - plan sections 9 and 10."""
    from .obligation import contexts_for_source
    try:
        contexts, _scs, _obs = contexts_for_source(src)
        return contexts
    except Exception:
        return [Context("base", {"variant": "base"})]


# --------------------------------------------------------------------------
# 1. cases from PyTorch's module database
# --------------------------------------------------------------------------

def iter_module_cases(limit: int = 0, seed: int = 0,
                      training: bool = True) -> Iterator[Case]:
    """One case per module sample.

    ``training=True`` matters: it is the mode in which ``BatchNorm`` and friends
    update their running statistics in place, which is the stateful mutation
    surface this source exists to reach.
    """
    db, err = load_module_db()
    if db is None or torch is None:
        return

    n = 0
    for info in db:
        if limit and n >= limit:
            break
        seed_everything(seed)
        try:
            samples = info.module_inputs_func(info, device="cpu",
                                              dtype=torch.float32,
                                              requires_grad=False,
                                              training=training)
        except Exception:
            continue

        for i, sample in enumerate(samples):
            try:
                mod_cls = info.module_cls
                args, kwargs = sample.constructor_input.args, sample.constructor_input.kwargs
                fwd_args = tuple(sample.forward_input.args)
                fwd_kwargs = dict(sample.forward_input.kwargs)
            except Exception:
                continue
            if fwd_kwargs or not fwd_args:
                continue
            if not (torch is not None and isinstance(fwd_args[0], torch.Tensor)):
                continue
            if len(fwd_args) > 2:
                continue

            case = _build_module_case(info, mod_cls, args, kwargs, fwd_args,
                                      i, training)
            if case is not None:
                n += 1
                yield case
            break  # one sample per module keeps the corpus balanced


def _build_module_case(info, mod_cls, ctor_args, ctor_kwargs, fwd_args,
                       index: int, training: bool) -> Optional[Case]:
    from .seeds import _apply_context

    names = [f"a{i}" for i in range(len(fwd_args))]
    src = f"def f({', '.join(names)}):\n    return _MOD({', '.join(names)})\n"

    try:
        module = mod_cls(*ctor_args, **ctor_kwargs)
        module.train(training)
    except Exception:
        return None

    ns: Dict[str, Any] = {"_MOD": module, "torch": torch}
    try:
        exec(compile(src, f"<module:{info.name}:{index}>", "exec"), ns)
    except Exception:
        return None
    fn = ns.get("f")
    if not callable(fn):
        return None

    base = tuple(fwd_args)

    def make_inputs(ctx: Context, _b=base) -> Tuple[Any, ...]:
        fresh = tuple(
            (a.detach().clone().requires_grad_(a.requires_grad)
             if torch is not None and isinstance(a, torch.Tensor) else a)
            for a in _b
        )
        return _apply_context(fresh, ctx)

    safe = info.name.replace(".", "_").replace("-", "_")
    return Case(
        name=f"mod_{safe}_{index}",
        fn=fn,
        make_inputs=make_inputs,
        contexts=_contexts(src),
        tags=["module", info.name],
        notes=f"PyTorch ModuleInfo `{info.name}`"
              + (" (training mode: buffers mutate in place)" if training else ""),
        source=src,
        # O6 compares parameter gradients too - the plan's "parameter gradient"
        # is only reachable through a module with parameters
        parameters=lambda _m=module: list(_m.parameters()),
    )


# --------------------------------------------------------------------------
# 2. synthesised multi-operator chains
# --------------------------------------------------------------------------

#: shape-preserving building blocks, so any two of them compose
_LINKS: List[Tuple[str, str]] = [
    ("relu",     "x = torch.relu(x)"),
    ("sigmoid",  "x = torch.sigmoid(x)"),
    ("tanh",     "x = torch.tanh(x)"),
    ("gelu",     "x = torch.nn.functional.gelu(x)"),
    ("silu",     "x = torch.nn.functional.silu(x)"),
    ("softplus", "x = torch.nn.functional.softplus(x)"),
    ("scale",    "x = x * 0.5"),
    ("shift",    "x = x + 0.25"),
    ("neg_abs",  "x = -torch.abs(x)"),
    ("clampmin", "x = torch.clamp_min(x, -2.0)"),
]

#: structural elements woven between the computation steps - these are what
#: single-operator cases could never express
_STRUCT: List[Tuple[str, str]] = [
    ("view",        "x = x[:]"),
    ("roundtrip",   "x = x.transpose(0, -1).transpose(0, -1)"),
    ("unsq_sq",     "x = x.unsqueeze(0).squeeze(0)"),
    ("alias_write", "_v = x[:]\n    _v.mul_(0.5)"),
    ("strided_write", "_v = x[..., ::2]\n    _v.add_(0.125)"),
    ("cross_write", "x[..., :-1] = x[..., 1:].clone()"),
    ("keep_alias",  "_keep = x[:]\n    x = x + _keep * 0.0"),
]


#: Shape-preserving *branches*. Without these a chain is a straight line, and
#: the flow-sensitive part of the analysis (plan section 6.2/6.3) has nothing
#: to read - which is exactly why the first ablation showed no gain at A2.
_BRANCH: List[Tuple[str, str]] = [
    ("br_flag",
     "if flag:\n        x = x * 2.0\n    else:\n        x = x + 1.0"),
    ("br_flag_act",
     "if flag:\n        x = torch.relu(x)\n    else:\n        x = torch.tanh(x)"),
    ("br_shape8",
     "if x.shape[0] >= 8:\n        x = torch.relu(x)\n    else:\n        x = torch.tanh(x)"),
    ("br_shape16",
     "if x.shape[-1] >= 16:\n        x = x * 0.5\n    else:\n        x = x + 0.5"),
    ("br_mod4",
     "if x.shape[0] % 4 == 0:\n        x = torch.sigmoid(x)\n    else:\n        x = torch.tanh(x)"),
]

#: Index expressions derived from a shape, so the section-7 dataflow has a
#: chain to recover. All are shape-preserving via broadcasting.
_INDEX: List[Tuple[str, str]] = [
    ("idx_last_row",
     "n = x.shape[0]\n    i = n - 1\n    x = x + x[i] * 0.0"),
    ("idx_first_row",
     "n = x.shape[0]\n    j = n - n\n    x = x + x[j] * 0.0"),
    ("idx_col_slice",
     "k = x.shape[-1]\n    m = k - 1\n    x = x + x[..., m:m + 1] * 0.0"),
]


def _chain_source(link_ids: Sequence[int], struct_ids: Sequence[int],
                  branch_id: Optional[int] = None,
                  index_id: Optional[int] = None) -> str:
    """Build a small multi-step program, alternating compute and structure.

    A branch or an index relation may be woven in, which is what gives the
    flow-sensitive and shape/index parts of the analysis something to work on.
    """
    params = "x, flag" if branch_id is not None and "flag" in _BRANCH[branch_id][1] else "x"
    lines = [f"def f({params}):"]
    mid = len(link_ids) // 2
    for i, li in enumerate(link_ids):
        if i == mid and index_id is not None:
            lines.append("    " + _INDEX[index_id][1])
        if i == mid and branch_id is not None:
            lines.append("    " + _BRANCH[branch_id][1])
        lines.append("    " + _LINKS[li][1])
        if i < len(struct_ids):
            lines.append("    " + _STRUCT[struct_ids[i]][1])
    lines.append("    return x")
    return "\n".join(lines) + "\n"


def iter_chain_cases(count: int = 120, depth: int = 3, seed: int = 0,
                     shape: Tuple[int, ...] = (8, 16),
                     structured: bool = True) -> Iterator[Case]:
    """Synthesise ``count`` chains of ``depth`` compute steps.

    Deterministic in ``seed``, so a campaign is reproducible and a finding can
    be regenerated exactly.
    """
    from .seeds import _apply_context
    if torch is None:
        return

    rng = random.Random(seed)
    seen: set = set()
    made = 0
    attempts = 0
    while made < count and attempts < count * 12:
        attempts += 1
        links = [rng.randrange(len(_LINKS)) for _ in range(depth)]
        structs = [rng.randrange(len(_STRUCT)) for _ in range(depth - 1)]
        branch = rng.randrange(len(_BRANCH)) if structured and rng.random() < 0.6 else None
        index = rng.randrange(len(_INDEX)) if structured and rng.random() < 0.5 else None
        key = (tuple(links), tuple(structs), branch, index)
        if key in seen:
            continue
        seen.add(key)

        src = _chain_source(links, structs, branch, index)
        ns: Dict[str, Any] = {"torch": torch}
        try:
            exec(compile(src, f"<chain:{made}>", "exec"), ns)
        except Exception:
            continue
        fn = ns.get("f")
        if not callable(fn):
            continue

        n_params = src.split("(", 1)[1].split(")", 1)[0].count(",") + 1

        def make_inputs(ctx: Context, _shape=shape, _seed=seed + made,
                        _n=n_params) -> Tuple[Any, ...]:
            seed_everything(_seed)
            args: List[Any] = [torch.randn(*_shape)]
            if _n > 1:
                args.append(True)   # the flag; contexts substitute the other value
            return _apply_context(tuple(args), ctx)

        recipe = " 鈫?".join(
            _LINKS[l][0] + ("" if i >= len(structs)
                            else " + " + _STRUCT[structs[i]][0])
            for i, l in enumerate(links)
        )
        yield Case(
            name=f"chain_{made:03d}",
            fn=fn,
            make_inputs=make_inputs,
            contexts=_contexts(src),
            tags=["chain"],
            notes=f"synthesised chain: {recipe}",
            source=src,
        )
        made += 1


# --------------------------------------------------------------------------

def validate_cases(cases: Sequence[Case], seed: int = 0
                   ) -> Tuple[List[Case], List[Tuple[str, str]]]:
    """Keep only cases that run in eager and run *deterministically*."""
    from .execution import run_eager
    from .oracle import Config, compare

    ok: List[Case] = []
    bad: List[Tuple[str, str]] = []
    for case in cases:
        ctx = case.contexts[0]
        try:
            a = run_eager(case, ctx, seed)
            if not a.ok:
                bad.append((case.name, f"{a.exception}: {(a.exception_msg or '')[:70]}"))
                continue
            b = run_eager(case, ctx, seed)
        except Exception as e:
            bad.append((case.name, f"{type(e).__name__}: {str(e)[:70]}"))
            continue
        # Modules in training mode update buffers on every call, so a second
        # run legitimately differs. Determinism is checked on the outputs only.
        cmp = compare(a, b, None, Config())
        value_diff = [f for f in cmp.findings if f.kind in ("value", "structure", "exception")]
        if value_diff:
            bad.append((case.name, "nondeterministic: " + value_diff[0].detail[:80]))
            continue
        ok.append(case)
    return ok, bad


def register_all(**kwargs) -> List[Case]:
    out: List[Case] = []
    for case in list(iter_module_cases(**kwargs.get("module", {}))) + \
                list(iter_chain_cases(**kwargs.get("chain", {}))):
        try:
            register(case)
            out.append(case)
        except ValueError:
            continue
    return out

