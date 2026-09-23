"""Metamorphic relations between compiled executions (NEXT_DIRECTIONS 5.3).

Both sides of every relation are *compiled* results, so the "the compiler is
allowed to change numerics" argument does not apply; eager is used only to
*validate* that the relation holds for this operator and sample, never as the
reference value.

Relations
- ``config``  : the same function compiled under different Inductor configurations
                (vectorisation off, split reductions off, cpp_wrapper, dynamic, ...)
- ``split``   : f(x) == cat(f(x[:k]), f(x[k:])) along dim 0 - hits per-size kernel
                generation (tails, non power-of-two sizes) and recompilation
- ``layout``  : f(x) == f(strided copy of x) - the compiled kernel must not depend
                on the input layout
- ``reuse``   : calling the compiled function twice on the *same* input objects
                gives the same answer - copy-back / stale-read defects

Every violation also records whether plain eager-vs-compiled already differs, so
the report separates "new because metamorphic" from "the standard oracle would
have found it too".
"""
from __future__ import annotations

import contextlib
import json
import os
import time
from dataclasses import dataclass, field
from typing import Any, Callable, Dict, List, Optional, Sequence, Tuple

from .compat import compile_fn, dynamo_reset, seed_everything, torch
from .decomp_diff import _clone, _clones, _fp64, _run, _eligible, _describe
from .observe import Observation, flatten, is_tensor, observe
from .oracle import Config, compare
from .program import make_noncontiguous


# --------------------------------------------------------------------------
# Inductor configurations (CPU-safe set; GPU ones are added when CUDA is present)
# --------------------------------------------------------------------------

def config_sets(device: str = "cpu") -> Dict[str, Dict[str, Any]]:
    """name -> torch._inductor.config patch. ``base`` is the default configuration."""
    cfgs: Dict[str, Dict[str, Any]] = {
        "base": {},
        "no_vec": {"cpp.simdlen": 1},
        "no_split_reduction": {"split_reductions": False},
        "unroll_reductions": {"unroll_reductions_threshold": 1},
        "no_fusion": {"epilogue_fusion": False, "max_fusion_size": 1},
        "no_pattern_matcher": {"pattern_matcher": False},
        "no_inplace": {"inplace_buffers": False},
        "cpp_wrapper": {"cpp_wrapper": True},
        "emulate_casts": {"emulate_precision_casts": True},
        # 6.1 (2026-09-12): more cold codegen paths, each an independent code path in Inductor
        "coordinate_descent": {"coordinate_descent_tuning": True},
        "padding": {"comprehensive_padding": True, "shape_padding": True},
        "no_layout_opt": {"layout_optimization": False},
        "decompose_mm": {"decompose_mem_bound_mm": True},
        "simd8": {"cpp.simdlen": 8},
        "simd16": {"cpp.simdlen": 16},
        "cpp_dynamic_threads": {"cpp.dynamic_threads": True},
        "cpp_no_tiling": {"cpp.enable_tiling_heuristics": False},
        "cpp_min_chunk1": {"cpp.min_chunk_size": 1},
        "scatter_no_fallback": {"cpp.fallback_scatter_reduce_sum": False},
        "aggressive_fusion": {"aggressive_fusion": True},
        "no_reorder": {"reorder_for_locality": False},
        "no_caches": {"force_disable_caches": True},
        "no_size_asserts": {"size_asserts": False},
        # opt-in (not in the default set: slow): GEMM/conv template autotuning, CPU C++ templates included
        "max_autotune": {"max_autotune": True, "max_autotune_gemm": True},
        "freezing": {"freezing": True},
    }
    if device == "cuda":
        cfgs.update({
            "no_persistent_reductions": {"triton.persistent_reductions": False},
            "cudagraphs": {"triton.cudagraphs": True},
            "no_multi_kernel": {"triton.multi_kernel": 0},
        })
    return cfgs


def _known_config_keys() -> set:
    try:
        from torch._inductor import config as IC
        return set(IC._config.keys()) if hasattr(IC, "_config") else set()
    except Exception:
        return set()


@contextlib.contextmanager
def inductor_config(patch: Dict[str, Any]):
    from torch._inductor import config as IC
    if not patch:
        yield
        return
    with IC.patch(patch):
        yield


# --------------------------------------------------------------------------
# records
# --------------------------------------------------------------------------

@dataclass
class Violation:
    op: str
    relation: str
    variant: str          # config name / split point / layout kind / call index
    detail: str
    standard_differs: Optional[bool] = None   # eager vs compiled(base) already differs?
    shapes: List[Any] = field(default_factory=list)
    dtypes: List[str] = field(default_factory=list)
    kind: str = "metamorphic"

    def as_dict(self) -> Dict[str, Any]:
        return dict(vars(self))


# --------------------------------------------------------------------------
# helpers
# --------------------------------------------------------------------------

def _compiled(fn: Callable, backend: str, dynamic: Optional[bool], patch: Dict[str, Any],
              args: Tuple[Any, ...], mode: str, calls: int = 1) -> List[Observation]:
    """Compile ``fn`` fresh under ``patch`` and call it ``calls`` times on the same objects."""
    obs: List[Observation] = []
    dynamo_reset()
    try:
        with inductor_config(patch):
            cf = compile_fn(fn, backend, dynamic=dynamic)
            for i in range(calls):
                obs.append(_run(cf, args, f"{mode}#{i}" if calls > 1 else mode))
    except Exception as e:  # noqa: BLE001  (config not accepted by this torch, etc.)
        o = observe(mode, args, None, e, with_grad=False)
        o.infra_error = True
        obs.append(o)
    finally:
        dynamo_reset()
    return obs


def _cat_outputs(a: Any, b: Any) -> Any:
    """Concatenate two half-batch outputs along dim 0, structure-wise."""
    if is_tensor(a) and is_tensor(b):
        if a.dim() == 0 or b.dim() == 0 or tuple(a.shape[1:]) != tuple(b.shape[1:]):
            raise ValueError("not batch-shaped")
        return torch.cat([a, b], dim=0)
    if isinstance(a, (tuple, list)) and isinstance(b, (tuple, list)) and len(a) == len(b):
        return type(a)(_cat_outputs(x, y) for x, y in zip(a, b))
    if isinstance(a, dict) and isinstance(b, dict) and a.keys() == b.keys():
        return {k: _cat_outputs(a[k], b[k]) for k in a}
    if a == b:
        return a
    raise ValueError("outputs are not batch-shaped")


def _split_args(args: Tuple[Any, ...], k: int) -> Tuple[Tuple[Any, ...], Tuple[Any, ...]]:
    """Slice every tensor that shares the batch size along dim 0; leave the rest."""
    n = None
    for a in args:
        if is_tensor(a) and a.dim() >= 1:
            n = a.shape[0]
            break
    lo, hi = [], []
    for a in args:
        if is_tensor(a) and a.dim() >= 1 and a.shape[0] == n:
            lo.append(_clone(a[:k]))
            hi.append(_clone(a[k:]))
        else:
            lo.append(a)
            hi.append(a)
    return tuple(lo), tuple(hi)


def _batch_size(args: Tuple[Any, ...]) -> int:
    for a in args:
        if is_tensor(a) and a.dim() >= 1:
            return int(a.shape[0])
    return 0


def _split_run(fn: Callable, args: Tuple[Any, ...], k: int, runner: Callable[[Tuple[Any, ...], str], Observation],
               mode: str) -> Optional[Observation]:
    lo, hi = _split_args(args, k)
    o1, o2 = runner(lo, mode + "[:k]"), runner(hi, mode + "[k:]")
    if not (o1.ok and o2.ok):
        # propagate an exception on either half as the split observation
        return o1 if not o1.ok else o2
    try:
        combined = _cat_outputs(o1.outputs, o2.outputs)
    except ValueError:
        return None
    return observe(mode, args, combined, None, with_grad=False)


# --------------------------------------------------------------------------
# the sweep
# --------------------------------------------------------------------------

def sweep(limit: int = 0, samples_per_op: int = 2, seed: int = 0, dtype: str = "float32",
          backend: str = "inductor", relations: Sequence[str] = ("config", "split", "layout", "reuse"),
          configs: Optional[Sequence[str]] = None, log=print, only: Optional[str] = None,
          jsonl: Optional[str] = None, device: str = "cpu", source: str = "opinfo",
          n_models: int = 50, max_nodes: int = 12) -> Dict[str, Any]:
    """``source``: ``opinfo`` (one operator per case), ``nnsmith`` (generated multi-op graphs),
    ``corpus`` (hand-written programs) or ``both`` (nnsmith + corpus)."""
    from torch.testing._internal.common_methods_invocations import op_db
    import random as _r
    cfg = Config()
    rng = _r.Random(seed)
    dt = getattr(torch, dtype)
    t0 = time.perf_counter()
    all_cfgs = config_sets(device)
    known = _known_config_keys()
    default_set = [c for c in all_cfgs if c not in ("max_autotune", "freezing")]
    chosen = [c for c in (configs or default_set) if c in all_cfgs or c == "dynamic"]
    chosen = [c for c in chosen if c == "dynamic" or all(k in known for k in all_cfgs[c]) or not known]
    stats = {"ops": 0, "samples": 0, "compiles": 0, "relation_checks": 0, "not_applicable": 0,
             "violations": 0, "standard_differs": 0, "infra": 0}
    viol: List[Violation] = []
    wanted = {s.strip() for s in only.split(",")} if only else None
    sink = open(jsonl, "a", encoding="utf-8") if jsonl else None

    def emit(rec: Dict[str, Any]) -> None:
        if sink is not None:
            sink.write(json.dumps(rec, default=str) + "\n")
            sink.flush()

    def record(v: Violation) -> None:
        viol.append(v)
        emit(v.as_dict())
        stats["violations"] += 1
        if v.standard_differs:
            stats["standard_differs"] += 1
        log(f"  {v.relation:<7} {v.op:<34} {v.variant:<20} {v.detail[:70]}  std={v.standard_differs}")

    def _opinfo_cases():
        for op in op_db:
            name = op.name
            if wanted and name not in wanted:
                continue
            if not _eligible(op, dt):
                continue
            if limit and stats["ops"] >= limit:
                break
            try:
                samples = list(op.sample_inputs(device, dt, requires_grad=False))
            except Exception:
                emit({"done": name})
                continue
            samples = [s for s in samples if is_tensor(s.input)
                       and all(not is_tensor(a) or a.layout == torch.strided for a in s.args)]
            if not samples:
                emit({"done": name})
                continue
            cases = []
            for s in rng.sample(samples, min(samples_per_op, len(samples))):
                kwargs = dict(s.kwargs)

                def fn(*a, _op=op.op, _kw=kwargs, **kw):
                    return _op(*a, **{**_kw, **kw})
                cases.append((fn, (s.input,) + tuple(s.args)))
            yield name, cases

    def _program_cases():
        # multi-op graphs: NNSmith models / the hand-written corpus (fusion, buffer reuse, layouts)
        from .program import Context
        from .execute import build_inputs
        progs: List[Any] = []
        if source in ("nnsmith", "both"):
            from .baselines import nnsmith_programs
            ok, rej = nnsmith_programs(n=n_models, seed=seed, max_nodes=max_nodes)
            log(f"NNSmith: {len(ok)} model(s), {len(rej)} rejected")
            progs += ok
        if source in ("corpus", "both"):
            from . import corpus  # noqa: F401
            from .program import all_programs
            progs += [p for p in all_programs() if p.expect == "consistent"]
        for p in progs:
            if wanted and p.name not in wanted:
                continue
            if limit and stats["ops"] >= limit:
                break
            try:
                args = build_inputs(p, p.base_context, seed)
            except Exception:
                emit({"done": p.name})
                continue
            if not any(is_tensor(a) for a in args):
                emit({"done": p.name})
                continue

            def fn(*a, _p=p):
                if _p.reset is not None:
                    _p.reset()
                return _p.fn(*a)
            yield p.name, [(fn, tuple(args))]

    for name, cases in (_opinfo_cases() if source == "opinfo" else _program_cases()):
        stats["ops"] += 1
        seen: set = set()
        for fn, args in cases:
            stats["samples"] += 1
            shapes, dtypes = _describe(args)
            seed_everything(seed)
            real = _run(fn, _clones(args, {})[0], "eager")
            if real.infra_error:
                continue
            ref64 = _fp64(fn, args) if real.ok else None
            # the standard oracle result under the base configuration (also the reuse relation)
            base = _compiled(fn, backend, None, {}, _clones(args, {})[0], "compiled", calls=2)
            stats["compiles"] += 1
            if base[0].infra_error:
                stats["infra"] += 1
                continue
            std = compare(real, base[0], ref64, cfg, ["value", "metadata", "exception"])
            std_differs = std.differs

            def _viol(rel: str, var: str, detail: str) -> None:
                key = (rel, var, detail[:80])
                if key in seen:
                    return
                seen.add(key)
                record(Violation(name, rel, var, detail[:220], std_differs, shapes, dtypes))

            # ---- reuse: same compiled artefact, same objects, second call ----
            if "reuse" in relations and len(base) == 2 and real.ok:
                stats["relation_checks"] += 1
                # relation valid only if eager is idempotent on the same objects
                e_same = _run(fn, real.inputs_after if real.inputs_after is not None else args, "eager")
                if not compare(real, e_same, ref64, cfg, ["value", "metadata", "exception"]).differs:
                    c = compare(base[0], base[1], ref64, cfg, ["value", "metadata", "exception"])
                    if c.differs:
                        _viol("reuse", "call2", f"[{c.findings[0].kind}] {c.findings[0].detail}")
                else:
                    stats["not_applicable"] += 1

            # ---- config differential ----
            if "config" in relations and real.ok:
                for cname in chosen:
                    if cname in ("base", "dynamic"):   # dynamic is a compile flag, handled below
                        continue
                    stats["relation_checks"] += 1
                    o = _compiled(fn, backend, None, all_cfgs[cname], _clones(args, {})[0], f"compiled[{cname}]")[0]
                    stats["compiles"] += 1
                    if o.infra_error:
                        stats["infra"] += 1
                        continue
                    c = compare(base[0], o, ref64, cfg, ["value", "metadata", "exception"])
                    if c.differs:
                        # which side is wrong? eager is the tie-breaker for the label only
                        ce = compare(real, o, ref64, cfg, ["value", "metadata", "exception"])
                        who = "config-side wrong" if ce.differs else "base-side wrong"
                        _viol("config", cname, f"[{c.findings[0].kind}] {c.findings[0].detail} ({who})")
                if "dynamic" in chosen or configs is None:
                    stats["relation_checks"] += 1
                    o = _compiled(fn, backend, True, {}, _clones(args, {})[0], "compiled[dynamic]")[0]
                    stats["compiles"] += 1
                    if o.infra_error:
                        stats["infra"] += 1
                    else:
                        c = compare(base[0], o, ref64, cfg, ["value", "metadata", "exception"])
                        if c.differs:
                            ce = compare(real, o, ref64, cfg, ["value", "metadata", "exception"])
                            who = "config-side wrong" if ce.differs else "base-side wrong"
                            _viol("config", "dynamic", f"[{c.findings[0].kind}] {c.findings[0].detail} ({who})")

            # ---- batch split ----
            n = _batch_size(args)
            if "split" in relations and real.ok and n >= 2:
                for k in sorted({1, n // 2, n - 1}):
                    if not (0 < k < n):
                        continue
                    stats["relation_checks"] += 1
                    e_split = _split_run(fn, args, k, lambda a, m: _run(fn, a, m), "eager-split")
                    if e_split is None or compare(real, e_split, ref64, cfg, ["value", "metadata", "exception"]).differs:
                        stats["not_applicable"] += 1
                        continue   # the relation does not hold for this op/sample in eager
                    dynamo_reset()
                    try:
                        cf = compile_fn(fn, backend)
                        c_split = _split_run(fn, args, k, lambda a, m: _run(cf, a, m), "compiled-split")
                    except Exception:  # noqa: BLE001
                        stats["infra"] += 1
                        continue
                    finally:
                        dynamo_reset()
                    stats["compiles"] += 2
                    if c_split is None or c_split.infra_error:
                        stats["infra"] += 1
                        continue
                    c = compare(base[0], c_split, ref64, cfg, ["value", "metadata", "exception"])
                    if c.differs:
                        ce = compare(real, c_split, ref64, cfg, ["value", "metadata", "exception"])
                        who = "split-side wrong" if ce.differs else "full-side wrong"
                        _viol("split", f"k={k}/{n}", f"[{c.findings[0].kind}] {c.findings[0].detail} ({who})")

            # ---- layout ----
            if "layout" in relations and real.ok and any(is_tensor(a) and a.dim() >= 1 for a in args):
                stats["relation_checks"] += 1
                nc = tuple(make_noncontiguous(a) if is_tensor(a) and a.dim() >= 1 else a for a in args)
                e_nc = _run(fn, _clones(nc, {})[0], "eager-noncontig")
                if compare(real, e_nc, ref64, cfg, ["value", "exception"]).differs:
                    stats["not_applicable"] += 1
                else:
                    o = _compiled(fn, backend, None, {}, _clones(nc, {})[0], "compiled[noncontig]")[0]
                    stats["compiles"] += 1
                    if o.infra_error:
                        stats["infra"] += 1
                    else:
                        c = compare(base[0], o, ref64, cfg, ["value", "exception"])
                        if c.differs:
                            ce = compare(real, o, ref64, cfg, ["value", "exception"])
                            who = "noncontig-side wrong" if ce.differs else "contig-side wrong"
                            _viol("layout", "noncontig", f"[{c.findings[0].kind}] {c.findings[0].detail} ({who})")
        emit({"done": name})
    stats["wall_s"] = round(time.perf_counter() - t0, 1)
    emit({"stats": stats})
    if sink is not None:
        sink.close()
    return {"stats": stats, "mismatches": [v.as_dict() for v in viol]}


def write_report(res: Dict[str, Any], out_dir: str) -> str:
    os.makedirs(out_dir, exist_ok=True)
    with open(os.path.join(out_dir, "metamorphic.json"), "w", encoding="utf-8") as fh:
        json.dump(res, fh, indent=2, default=str)
    st = res["stats"]
    L = ["# Metamorphic relations between compiled executions", "",
         f"- operators: {st.get('ops', 0)}, samples: {st.get('samples', 0)}, compiles: {st.get('compiles', 0)}, "
         f"relation checks: {st.get('relation_checks', 0)} (not applicable in eager: {st.get('not_applicable', 0)}, "
         f"infra: {st.get('infra', 0)})",
         f"- violations: {st.get('violations', 0)}, of which the plain eager-vs-compiled oracle also differs: "
         f"{st.get('standard_differs', 0)}", f"- wall: {st.get('wall_s', 0)} s", ""]
    if res.get("crashes"):
        L.append("- operators whose child interpreter died: "
                 + ", ".join(f"{c['crash']} (rc {c['rc']})" for c in res["crashes"]))
        L.append("")
    L += ["| relation | op | variant | shapes | dtypes | detail | standard oracle differs |",
          "|---|---|---|---|---|---|---|"]
    for m in res["mismatches"]:
        L.append(f"| {m.get('relation')} | {m['op']} | {m['variant']} | {m['shapes']} | {m['dtypes']} | "
                 f"{m['detail'][:100].replace('|', '/')} | {m.get('standard_differs')} |")
    path = os.path.join(out_dir, "METAMORPHIC.md")
    with open(path, "w", encoding="utf-8") as fh:
        fh.write("\n".join(L) + "\n")
    return path
