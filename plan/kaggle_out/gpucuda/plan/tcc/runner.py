"""Orchestration: Phase 1 -> Phase 2 -> Phase 3 -> Phase 4 for one program.

    build_plan            analysis, SCS, obligations, contexts, pairs, sequences
    validate contexts     drop contexts the eager reference itself cannot run
    layered probes        E0..E3 per context            (section 16)
    matrix probes         E1/C1/E2/C2cold/C2warm(+A)    (section 14/15)
    confirmation          deterministic reruns with a fixed seed (18.1 steps 1-5)
    minimization          input + program               (17.2)
    dedup                 failure signature             (18.5)
    report                issue.md and friends          (18.3/18.4)

Everything is budgeted: a test budget per program (plan section 21) and an
optional wall-clock budget, so baselines and ablations run under identical
limits.
"""
from __future__ import annotations

import time
from dataclasses import dataclass, field, replace
from typing import Any, Callable, Dict, List, Optional, Sequence, Tuple

from .execute import (E0_EAGER, LAYERS, Compiler, Matrix, TorchCompiler, build_inputs, execution_matrix,
                      run_eager, run_fp64, run_layered)
from .generate import TestPlan, build_plan
from .localize import STAGE_NONE, Triage, triage_layers, triage_matrix
from .minimize import Target, make_predicate, minimize, render_reproducer
from .oracle import Config
from .program import Context, Program
from .report import DedupStore, FailureRecord, render_values, signature
from .scs import DeriveOptions


@dataclass
class RunOptions:
    backend: str = "inductor"
    disk_cache: bool = False
    reruns: int = 2
    do_layered: bool = True
    do_matrix: bool = True
    seed: int = 0
    keep_info: bool = False
    minimize: bool = False
    minimize_budget: int = 16
    max_contexts: int = 12
    #: maximum ordered context pairs probed with the execution matrix; 0 = all
    max_pairs: int = 24
    #: maximum tests (layered contexts + sequences) per program; 0 = unlimited
    test_budget: int = 0
    #: wall-clock budget per program in seconds; 0 = unlimited
    time_budget_s: float = 0.0
    derive: DeriveOptions = field(default_factory=DeriveOptions)
    level: str = "FULL"
    layers: Optional[List[Tuple[str, Optional[str]]]] = None
    #: compiler factory for the matrix probe (and E3 when ``inject_layer`` is set)
    compiler_factory: Optional[Callable[[], Compiler]] = None
    #: layer whose compiler is replaced by ``compiler_factory`` (benchmark mode)
    inject_layer: Optional[str] = None
    #: override the oracle set (None = what the obligations ask for)
    oracles: Optional[List[str]] = None
    #: a custom plan builder (baselines / ablation): program -> TestPlan
    plan_builder: Optional[Callable[[Program], TestPlan]] = None
    #: stop at the first failure (time-to-first-failure experiments)
    stop_at_first: bool = False
    fault_id: Optional[str] = None
    #: plan 18.5: query the project tracker for possible duplicates (network)
    search_duplicates: bool = False
    duplicate_repo: str = "pytorch/pytorch"


@dataclass
class RunResult:
    program: str
    records: List[FailureRecord] = field(default_factory=list)
    tests_executed: int = 0
    tests_invalid: int = 0
    contexts_pruned: int = 0
    compile_count: int = 0
    wall_s: float = 0.0
    first_failure_test: Optional[int] = None
    ttf_s: Optional[float] = None
    contexts_dropped: List[str] = field(default_factory=list)
    plan: Optional[TestPlan] = None
    error: Optional[str] = None
    layers_unavailable: List[str] = field(default_factory=list)

    @property
    def failures(self) -> List[FailureRecord]:
        return [r for r in self.records if r.triage.is_failure]

    def as_dict(self) -> Dict[str, Any]:
        return {"program": self.program, "n_records": len(self.records),
                "n_failures": len(self.failures),
                "stages": sorted({r.triage.stage for r in self.failures}),
                "tests_executed": self.tests_executed, "tests_invalid": self.tests_invalid,
                "contexts_pruned": self.contexts_pruned,
                "compile_count": self.compile_count, "wall_s": round(self.wall_s, 3),
                "first_failure_test": self.first_failure_test,
                "ttf_s": round(self.ttf_s, 3) if self.ttf_s is not None else None,
                "contexts_dropped": self.contexts_dropped, "error": self.error,
                "layers_unavailable": self.layers_unavailable,
                "plan": self.plan.as_dict() if self.plan else None}


def _compiler(opts: RunOptions) -> Compiler:
    return opts.compiler_factory() if opts.compiler_factory else TorchCompiler(opts.backend)


def _input_key(program: Program, ctx: Context, seed: int) -> Optional[Tuple]:
    """A fingerprint of the built inputs: metadata + values + Python scalars."""
    from .observe import flatten, is_tensor
    try:
        items, struct = flatten(build_inputs(program, ctx, seed))
    except Exception:
        return None
    key: List[Any] = [struct, ctx.get("compile")]
    for it in items:
        if is_tensor(it):
            try:
                key.append((tuple(it.shape), str(it.dtype), str(it.device), tuple(it.stride()),
                            bool(it.requires_grad), hash(it.detach().cpu().contiguous().numpy().tobytes())))
            except Exception:
                key.append(("tensor", tuple(it.shape), str(it.dtype)))
        else:
            try:
                key.append(repr(it))
            except Exception:  # objects with a broken __repr__ (flex_attention BlockMask)
                key.append(f"<{type(it).__name__}@{id(it)}>")
    return tuple(key)


def valid_contexts(program: Program, contexts: Sequence[Context], seed: int,
                   allow_raise: bool) -> Tuple[List[Context], List[str]]:
    """Keep contexts the eager reference can run (or deliberately raises in).

    Contexts whose built inputs are identical to the base's (``requires_grad``
    set to the value it already had, a flag substituted with its base value,
    ``device`` cpu -> cpu) test nothing and would be reported as "switched
    without a recompile" for the wrong reason; they are dropped too.
    """
    ok: List[Context] = []
    dropped: List[str] = []
    base_key = _input_key(program, contexts[0], seed) if contexts else None
    # plan 18.1 step 1: the eager reference must itself be deterministic. An op
    # returning uninitialised memory (`new_empty`) or fresh randomness makes any
    # eager-vs-compiled comparison meaningless, so the whole program is skipped.
    if contexts:
        try:
            from .oracle import Config, compare
            e1 = run_eager(program, contexts[0], seed)
            e2 = run_eager(program, contexts[0], seed)
            if e1.ok and e2.ok and compare(e1, e2, None, Config(use_dynamo_same=False)).differs:
                return [], [f"{c.name} (eager itself is nondeterministic)" for c in contexts]
        except Exception:
            pass
    for i, ctx in enumerate(contexts):
        if i > 0 and base_key is not None and _input_key(program, ctx, seed) == base_key:
            dropped.append(f"{ctx.name} (identical to base)")
            continue
        try:
            obs = run_eager(program, ctx, seed)
        except Exception:
            dropped.append(ctx.name)
            continue
        # The base context is the seed itself: if eager raises there, that raise is
        # part of the program's semantics (issue reproducers of "compile silently
        # accepts what eager rejects" look exactly like this) and O3 must see it.
        # Derived contexts that only eager rejects are generator noise unless the
        # program has an explicit raise.
        if obs.ok or (not obs.infra_error and (allow_raise or i == 0)):
            ok.append(ctx)
        else:
            dropped.append(ctx.name)
    return ok, dropped


def _controlled(a: Context, b: Optional[Context], factor: str) -> Dict[str, Any]:
    keys = set(a.factors) | set((b.factors if b else {}))
    return {k: a.factors.get(k) for k in sorted(keys) if k != factor}


def _obligation_for(plan: TestPlan, ctx: Context, factor: str) -> Optional[Dict[str, Any]]:
    if ctx.origin:
        for ob in plan.obligations:
            if ob.factor == ctx.origin:
                return ob.as_dict()
    keys = [k for k in ctx.factors] if not factor else [factor]
    for ob in plan.obligations:
        head = ob.factor.split(".")[0].split("[")[0]
        for k in keys:
            if k == "dtype" and ob.kind == "dtype":
                return ob.as_dict()
            if k == "layout" and ob.kind in ("contiguous", "stride"):
                return ob.as_dict()
            if k == "resize" and ob.kind == "shape" and isinstance(ctx.get("resize"), dict) \
                    and ob.dim == ctx.get("resize").get("dim"):
                return ob.as_dict()
            if k == "substitute" and ob.kind in ("flag", "scalar"):
                return ob.as_dict()
            if k == "requires_grad" and ob.kind == "requires_grad":
                return ob.as_dict()
            if k == "compile" and ob.kind == "compile_flag":
                return ob.as_dict()
            if k == "device" and ob.kind == "device":
                return ob.as_dict()
            if k == head:
                return ob.as_dict()
    return None


def _confirm(fn: Callable[[], Triage], stage: str, kinds: Sequence[str], n: int) -> Tuple[int, int]:
    if n <= 0:
        return 1, 1
    agree = 0
    for _ in range(n):
        try:
            t = fn()
        except Exception:
            continue
        if t.stage == stage and sorted(t.kinds) == sorted(kinds):
            agree += 1
    return agree, n


def _layer_compilers(opts: RunOptions) -> Optional[Dict[str, Compiler]]:
    if opts.compiler_factory and opts.inject_layer:
        return {opts.inject_layer: opts.compiler_factory()}
    return None


# --------------------------------------------------------------------------
# probes
# --------------------------------------------------------------------------

def probe_layered(program: Program, ctx: Context, opts: RunOptions, cfg: Config, oracles):
    fp64 = run_fp64(program, ctx, opts.seed)
    layers = run_layered(program, ctx, opts.disk_cache, opts.seed, opts.layers, _layer_compilers(opts))
    tri, comps = triage_layers(layers, fp64, cfg, oracles)
    return tri, comps, layers, fp64


def probe_matrix(program: Program, a: Context, b: Context, opts: RunOptions, cfg: Config, oracles):
    m = execution_matrix(program, a, b, _compiler(opts), opts.disk_cache, opts.seed, return_trip=True)
    tri, verdict = triage_matrix(m, cfg, oracles)
    return tri, verdict, m


# --------------------------------------------------------------------------
# the program loop
# --------------------------------------------------------------------------

def run_program(program: Program, opts: Optional[RunOptions] = None, cfg: Optional[Config] = None,
                store: Optional[DedupStore] = None, log: Optional[Callable[[str], None]] = None
                ) -> RunResult:
    opts = opts or RunOptions()
    cfg = cfg or Config()
    res = RunResult(program.name)
    t0 = time.perf_counter()
    say = log or (lambda s: None)

    try:
        plan = opts.plan_builder(program) if opts.plan_builder else build_plan(
            program, opts.derive, opts.max_contexts, level=opts.level)
    except Exception as e:  # noqa: BLE001
        res.error = f"plan: {type(e).__name__}: {e}"
        res.wall_s = time.perf_counter() - t0
        return res
    res.plan = plan
    oracles = opts.oracles or plan.oracles
    allow_raise = bool(plan.analysis.raises)

    usable, dropped = valid_contexts(program, plan.contexts, opts.seed, allow_raise)
    res.contexts_dropped = dropped
    # invalid = the eager reference could not run it; pruned = never executed
    res.tests_invalid = sum(1 for d in dropped if "identical to base" not in d)
    res.contexts_pruned = len(dropped) - res.tests_invalid
    if not usable:
        res.wall_s = time.perf_counter() - t0
        return res
    # warm sequences only for contexts whose obligation asked for one (plan 10)
    pairs = [(a, b) for a, b in plan.pairs if a in usable and b in usable
             and (a.warm or a is plan.contexts[0]) and (b.warm or b is plan.contexts[0])
             and not (a is plan.contexts[0] and b is plan.contexts[0])]
    seqs = [s for s in plan.sequences if all(c in usable for c in s)]
    # one execution matrix per ordered pair covers A->B and A->B->A; the mirrored
    # pair covers B->A. Pairs touching the base context come first, so a small
    # budget still probes every factor once.
    base_name = plan.contexts[0].name if plan.contexts else "base"
    ordered_pairs = sorted(pairs, key=lambda ab: (ab[0].name != base_name and ab[1].name != base_name,
                                                  ab[0].name != base_name))
    if opts.max_pairs:
        ordered_pairs = ordered_pairs[:opts.max_pairs]

    def over_budget() -> bool:
        if opts.test_budget and res.tests_executed >= opts.test_budget:
            return True
        if opts.time_budget_s and (time.perf_counter() - t0) >= opts.time_budget_s:
            return True
        return False

    def note_failure() -> None:
        if res.first_failure_test is None:
            res.first_failure_test = res.tests_executed
            res.ttf_s = time.perf_counter() - t0

    def emit(rec: FailureRecord) -> None:
        if store is not None and not store.add(rec.signature, {"program": program.name,
                                                               "stage": rec.triage.stage,
                                                               "factor": rec.factor_changed,
                                                               "probe": rec.probe}):
            return
        if opts.search_duplicates and rec.triage.is_failure:
            from .report import dedup_query, search_github_issues
            rec.duplicates = search_github_issues(dedup_query(rec), repo=opts.duplicate_repo)
        origin = (program.site or {}).get("url") if program.site else None
        if origin:
            # a reproducer that came from an issue: that issue is the first duplicate candidate
            rec.duplicates = rec.duplicates or {"query": "", "searched": False, "error": None, "candidates": []}
            rec.duplicates["candidates"].insert(0, {"number": origin.rstrip("/").split("/")[-1],
                                                    "title": "origin issue of this reproducer",
                                                    "url": origin, "state": None, "is_pr": False, "created": ""})
        res.records.append(rec)

    src = program.get_source() or ""
    fn_name = getattr(program.fn, "__name__", "f")

    # ---------------- layered (D1: eager vs compiled at every stage) ----------------
    def do_layered(ctx: Context) -> None:
            res.tests_executed += 1
            try:
                tri, comps, layers, fp64 = probe_layered(program, ctx, opts, cfg, oracles)
            except Exception as e:  # noqa: BLE001
                say(f"    layered {ctx.name}: ERROR {type(e).__name__}: {str(e)[:80]}")
                return
            res.compile_count += sum(o.compiles for o in layers.values())
            for u in tri.layers_unavailable:
                if u not in res.layers_unavailable:
                    res.layers_unavailable.append(u)
            if tri.stage == STAGE_NONE and not (opts.keep_info and tri.guard_suspicious):
                return
            note_failure()
            agree, total = _confirm(lambda: probe_layered(program, ctx, opts, cfg, oracles)[0],
                                    tri.stage, tri.kinds, opts.reruns)
            first = layers.get(tri.first_divergent_layer or "")
            exc = first.exception if first is not None and not first.ok else None
            frame = first.exc_frame if first is not None and not first.ok else None
            factor = next(iter(ctx.factors), "") if ctx.factors else ""
            sig = signature(program.project, tri.stage, factor, tri.kinds, exc, frame, src, "cold")
            eager = layers.get(E0_EAGER)
            rec = FailureRecord(
                signature=sig, program=program.name, project=program.project, triage=tri,
                probe="layered", context=ctx.as_dict(), factor_changed=factor if ctx.factors else "",
                controlled=_controlled(ctx, None, factor), obligation=_obligation_for(plan, ctx, factor),
                comparisons=comps, observations={k: v.summary() for k, v in layers.items()},
                fp64_available=fp64 is not None, reruns_agreeing=agree, reruns_total=total,
                seed=opts.seed, backend=opts.backend, compile_options=dict(program.compile_options),
                notes=program.notes, fault=opts.fault_id,
                execution_sequence=[f"{m}: {'ok' if o.ok else o.exception}" for m, o in layers.items()],
                expected_text=render_values(eager.outputs) if eager is not None and eager.ok else
                (f"exception {eager.exception}: {eager.exception_msg}" if eager is not None else ""),
                actual_text=(render_values(first.outputs) if first is not None and first.ok else
                             f"exception {first.exception}: {first.exception_msg}" if first else ""),
            )
            rec.reproducer = render_reproducer(src, _recipe(program, ctx), fn_name, ctx, None,
                                               _backend_of_layer(tri.first_divergent_layer, opts))
            if opts.minimize and tri.submittable:
                _minimize_into(rec, program, ctx, None, opts, fn_name)
            emit(rec)

    # ---------------- matrix (D2/D3: cold vs warm, return trip) ----------------
    def do_matrix(a: Context, b: Context) -> None:
            res.tests_executed += 1
            try:
                tri, verdict, m = probe_matrix(program, a, b, opts, cfg, oracles)
            except Exception as e:  # noqa: BLE001
                say(f"    matrix {a.name}->{b.name}: ERROR {type(e).__name__}: {str(e)[:80]}")
                return
            res.compile_count += m.compile_count
            if tri.stage == STAGE_NONE and not (opts.keep_info and tri.guard_suspicious):
                return
            note_failure()
            factor = verdict.factor
            agree, total = _confirm(lambda: probe_matrix(program, a, b, opts, cfg, oracles)[0],
                                    tri.stage, tri.kinds, opts.reruns)
            cw = "warm" + ("-norecompile" if tri.recompiled is False else "")
            sig = signature(program.project, tri.stage, factor, tri.kinds, None, None, src, cw)
            rec = FailureRecord(
                signature=sig, program=program.name, project=program.project, triage=tri,
                probe="matrix", context=a.as_dict(), context_b=b.as_dict(), factor_changed=factor,
                controlled=_controlled(a, b, factor), obligation=_obligation_for(plan, b, factor),
                comparisons={k: v for k, v in (("cold_vs_warm", verdict.cold_vs_warm),
                                               ("eager_vs_cold", verdict.eager_vs_cold),
                                               ("eager_vs_warm", verdict.eager_vs_warm),
                                               ("A_vs_A_after_B", verdict.return_trip)) if v is not None},
                cache=verdict.as_dict(), observations=m.as_dict(), fp64_available=m.fp64_b is not None,
                reruns_agreeing=agree, reruns_total=total, seed=opts.seed, backend=opts.backend,
                compile_options=dict(program.compile_options), notes=program.notes, fault=opts.fault_id,
                execution_sequence=["E1 = eager(A)", "C1 = compiled_cold(A)", "E2 = eager(B)",
                                    "C2cold = compiled_cold(B)", "reset; compiled(A)",
                                    "C2warm = compiled_warm(B)", "C1' = compiled_warm(A)"],
                expected_text=render_values(m.E2.outputs) if m.E2.ok else f"exception {m.E2.exception}",
                actual_text=(render_values(m.C2warm.outputs) if m.C2warm.ok
                             else f"exception {m.C2warm.exception}: {m.C2warm.exception_msg}"),
            )
            rec.reproducer = render_reproducer(src, _recipe(program, a), fn_name, a, b, opts.backend,
                                               recipe_b=_recipe(program, b))
            if opts.minimize and tri.submittable:
                _minimize_into(rec, program, a, b, opts, fn_name)
            emit(rec)

    # ---------------- schedule: interleave cold probes and warm sequences ----------------
    # layered(base), then per factor context c: layered(c), matrix(base -> c); then the
    # remaining pairs. Under a small budget every factor still gets both a cold and a
    # warm probe before any factor gets its second one.
    want_matrix = opts.do_matrix and opts.derive.cache_sequence and bool(seqs)
    schedule: List[Tuple[str, Any]] = []
    if opts.do_layered and usable:
        schedule.append(("layered", usable[0]))
    used_pairs = set()
    for ctx in usable[1:]:
        if opts.do_layered:
            schedule.append(("layered", ctx))
        if want_matrix:
            # A -> B (and A -> B -> A inside the matrix), then the mirrored B -> A:
            # under-specialization is often visible in one direction only
            for a, b in ordered_pairs:
                if {a.name, b.name} == {base_name, ctx.name} and (a.name, b.name) not in used_pairs:
                    schedule.append(("matrix", (a, b)))
                    used_pairs.add((a.name, b.name))
    if want_matrix:
        for a, b in ordered_pairs:
            if (a.name, b.name) not in used_pairs:
                schedule.append(("matrix", (a, b)))
                used_pairs.add((a.name, b.name))
    for kind, item in schedule:
        if over_budget() or (opts.stop_at_first and res.first_failure_test is not None):
            break
        if kind == "layered":
            do_layered(item)
        else:
            do_matrix(*item)

    res.wall_s = time.perf_counter() - t0
    return res


def _backend_of_layer(layer: Optional[str], opts: RunOptions) -> str:
    for mode, backend in (opts.layers or LAYERS):
        if mode == layer and backend:
            return backend
    return opts.backend


def _recipe(program: Program, ctx: Context) -> str:
    from .minimize import describe_inputs
    try:
        return describe_inputs(build_inputs(program, ctx))
    except Exception:
        return ""


def _minimize_into(rec: FailureRecord, program: Program, ctx: Context, ctx_b: Optional[Context],
                   opts: RunOptions, fn_name: str) -> None:
    target = Target(rec.triage.stage, tuple(sorted(rec.triage.kinds)), rec.probe, rec.factor_changed)
    pred = make_predicate(target, lambda: _compiler(opts), opts.seed, opts.layers, opts.oracles)
    if opts.inject_layer and opts.compiler_factory:
        # benchmark mode: the layered predicate must use the injected layer too
        from .execute import run_layered as _rl

        def pred(p, c, cb, _t=target):  # type: ignore[no-redef]
            try:
                if _t.probe == "matrix" and cb is not None:
                    m = execution_matrix(p, c, cb, _compiler(opts), seed=opts.seed)
                    tri, _ = triage_matrix(m, Config(), opts.oracles)
                else:
                    fp64 = run_fp64(p, c, opts.seed)
                    layers = _rl(p, c, seed=opts.seed, layers=opts.layers, compilers=_layer_compilers(opts))
                    tri, _ = triage_layers(layers, fp64, Config(), opts.oracles)
            except Exception:
                return False
            return _t.matches(tri.stage, tri.kinds)
    try:
        m = minimize(program, ctx, target, pred, ctx_b, opts.minimize_budget, opts.minimize_budget)
    except Exception as e:  # noqa: BLE001
        rec.minimized = {"reproduces": False, "log": [f"minimizer error: {type(e).__name__}: {e}"]}
        return
    rec.minimized = m.as_dict()
    if m.reproduces:
        rec.reproducer = render_reproducer(m.source, m.input_recipe, fn_name, ctx, ctx_b, opts.backend,
                                           recipe_b=_recipe(program, ctx_b) if ctx_b else "")


def run_many(programs: Sequence[Program], opts: RunOptions, cfg: Optional[Config] = None,
             store: Optional[DedupStore] = None, on_program=None,
             log: Optional[Callable[[str], None]] = None) -> List[RunResult]:
    out: List[RunResult] = []
    for p in programs:
        try:
            r = run_program(p, opts, cfg, store, log)
        except Exception as e:  # noqa: BLE001
            r = RunResult(p.name, error=f"{type(e).__name__}: {e}")
        out.append(r)
        if on_program is not None:
            on_program(p, r)
    return out
