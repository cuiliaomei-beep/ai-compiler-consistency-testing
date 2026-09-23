"""Orchestration: probe, confirm, deduplicate, record.

Two probes per case:

* **D1 layered** — eager against ``eager`` / ``aot_eager`` / ``inductor``
  backends, for every context.
* **D2 warm** — cold-compiled B against warm-after-A B, for every ordered pair
  of contexts differing in exactly one factor.

The pass is deliberately cheap first and expensive only on candidates: a
divergence is re-run several times with a fixed seed before it becomes a
record, because a finding that does not reproduce wastes a maintainer's time
and costs more credibility than it gains.
"""
from __future__ import annotations

from dataclasses import dataclass, replace
from typing import Any, Dict, List, Optional, Tuple

from .case import Case, Context
from .execution import (
    E0_EAGER,
    run_cold,
    run_eager,
    run_fp64_reference,
    run_layered,
    run_return_trip,
    run_warm_pair,
)
from .oracle import Config
from .report import FailureRecord
from .torchcompat import seed_everything
from .triage import (
    DedupStore,
    STAGE_NONE,
    Triage,
    signature,
    triage_layers,
    triage_return_trip,
    triage_warm,
)


@dataclass
class RunOptions:
    backend: str = "inductor"
    disk_cache: bool = False
    #: confirmation re-runs for a candidate (0 disables confirmation)
    reruns: int = 2
    do_layered: bool = True
    do_warm: bool = True
    seed: int = 0
    #: keep info-level rows (guard-suspicious, etc.) in the output
    keep_info: bool = False
    #: run the A -> B -> A return trip (plan section 15)
    do_return_trip: bool = True
    #: minimize submittable candidates (plan section 17.2). Off by default
    #: because each step costs a compile; turn it on for the candidates that
    #: are actually going to be filed.
    minimize: bool = False
    minimize_budget: int = 20
    #: query the tracker for possible duplicates (plan 18.5). Off by default:
    #: it makes network requests and the public API is rate limited.
    search_duplicates: bool = False
    duplicate_repo: str = "pytorch/pytorch"
    #: override the D1 ladder; used by ``run.py validate`` to inject a
    #: deliberately wrong layer and prove the pipeline emits records at all
    layers: Optional[List[Tuple[str, Optional[str]]]] = None


def valid_contexts(case: Case, opts: "RunOptions") -> List[Context]:
    """Keep only the contexts this case can actually run under, in eager.

    Context variants are generated mechanically (cast the dtype, make the input
    non-contiguous, resize a dimension), so some of them are simply nonsense for
    a given function - casting the inputs of a complex-valued kernel to float16,
    for instance. Eager then raises, and every comparison against that context
    reports an "exception divergence" that the compiler had nothing to do with.

    A context under which the *reference* cannot run is not evidence about the
    compiler. Validate first, and say how many were dropped rather than
    silently shrinking the search space.
    """
    ok: List[Context] = []
    for ctx in case.contexts:
        try:
            obs = run_eager(case, ctx, opts.seed)
        except Exception:
            continue
        if obs.ok:
            ok.append(ctx)
    return ok


def _exc_bits(obs_map: Dict[str, Any]) -> Tuple[Optional[str], Optional[str]]:
    for obs in obs_map.values():
        if getattr(obs, "ok", True) is False:
            return getattr(obs, "exception", None), getattr(obs, "exc_frame", None)
    return None, None


def _confirm(probe_fn, expect_stage: str, n: int) -> Tuple[int, int]:
    """Re-run a probe ``n`` times; count how often it reaches the same verdict."""
    if n <= 0:
        return 1, 1
    agree = 0
    for _ in range(n):
        try:
            tri = probe_fn()
        except Exception:
            continue
        if tri.stage == expect_stage:
            agree += 1
    return agree, n


def probe_layered(
    case: Case,
    ctx: Context,
    opts: RunOptions,
    cfg: Config,
) -> Tuple[Triage, Dict[str, Any], Dict[str, Any], bool]:
    fp64 = run_fp64_reference(case, ctx, seed=opts.seed)
    layers = run_layered(case, ctx, disk_cache=opts.disk_cache, seed=opts.seed,
                         layers=opts.layers)
    tri, comps = triage_layers(layers, fp64, cfg)
    obs_summary = {k: v.summary() for k, v in layers.items()}
    return tri, comps, obs_summary, fp64 is not None


def probe_warm(
    case: Case,
    a: Context,
    b: Context,
    opts: RunOptions,
    cfg: Config,
) -> Tuple[Triage, Dict[str, Any], Dict[str, Any], bool]:
    factor = (a.differing_factors(b) or ["<none>"])[0]
    fp64 = run_fp64_reference(case, b, seed=opts.seed)
    cold = run_cold(case, b, backend=opts.backend,
                    disk_cache=opts.disk_cache, seed=opts.seed)
    warm, recompiled = run_warm_pair(
        case, a, b, backend=opts.backend, disk_cache=opts.disk_cache, seed=opts.seed
    )
    tri, cmp = triage_warm(cold, warm, recompiled, factor, fp64, cfg)
    obs_summary = {"cold_B": cold.summary(), "warm_A_to_B": warm.summary()}
    return tri, {"cold_vs_warm": cmp}, obs_summary, fp64 is not None


def run_case(
    case: Case,
    opts: Optional[RunOptions] = None,
    cfg: Optional[Config] = None,
    store: Optional[DedupStore] = None,
) -> List[FailureRecord]:
    opts = opts or RunOptions()
    cfg = cfg or Config()
    records: List[FailureRecord] = []

    # An operator whose schema declares no alias relation may legally return
    # copies after compilation. The finding is still recorded, but marked
    # non-contractual so triage keeps it out of the submittable queue.
    if case.alias_contract is False and cfg.alias_contractual:
        cfg = replace(cfg, alias_contractual=False)

    usable = valid_contexts(case, opts)
    dropped = [c.name for c in case.contexts if c not in usable]
    if not usable:
        return records

    def finish(recs: List[FailureRecord]) -> List[FailureRecord]:
        """Plan 18.1 steps 6-7, applied only to what would actually be filed."""
        for r in recs:
            if not r.triage.submittable:
                continue
            if opts.minimize:
                minimize_record(case, r, opts)
            if opts.search_duplicates:
                search_duplicates(r, opts.duplicate_repo)
        return recs

    # ---------------- D1 ----------------
    if opts.do_layered:
        for ctx in usable:
            seed_everything(opts.seed)
            tri, comps, obs, has_fp64 = probe_layered(case, ctx, opts, cfg)
            if tri.stage == STAGE_NONE and not (opts.keep_info and tri.guard_suspicious):
                continue

            agree, total = _confirm(
                lambda: probe_layered(case, ctx, opts, cfg)[0], tri.stage, opts.reruns
            )
            exc, frame = _exc_bits({})
            sig = signature(case.name, tri.stage, tri.kinds, ctx.name, exc, frame)
            if store is not None and not store.add(
                sig, {"case": case.name, "stage": tri.stage, "probe": "layered"}
            ):
                continue

            records.append(
                FailureRecord(
                    signature=sig,
                    case=case.name,
                    triage=tri,
                    probe="layered",
                    context=ctx.as_dict(),
                    factor_changed="",
                    comparisons=comps,
                    observations=obs,
                    fp64_available=has_fp64,
                    reruns_agreeing=agree,
                    reruns_total=total,
                    notes=case.notes + (
                        f"\n[contexts dropped as inapplicable in eager: "
                        f"{', '.join(dropped)}]" if dropped else ""),
                )
            )

    # ---------------- D2 ----------------
    if opts.do_warm:
        pairs = [(a, b) for a, b in case.context_pairs()
                 if a in usable and b in usable]
        for a, b in pairs:
            seed_everything(opts.seed)
            tri, comps, obs, has_fp64 = probe_warm(case, a, b, opts, cfg)
            interesting = tri.stage != STAGE_NONE or (opts.keep_info and tri.guard_suspicious)
            if not interesting:
                continue

            agree, total = _confirm(
                lambda: probe_warm(case, a, b, opts, cfg)[0], tri.stage, opts.reruns
            )
            factor = (a.differing_factors(b) or ["<none>"])[0]
            sig = signature(case.name, tri.stage, tri.kinds, factor)
            if store is not None and not store.add(
                sig, {"case": case.name, "stage": tri.stage, "probe": "warm", "factor": factor}
            ):
                continue

            records.append(
                FailureRecord(
                    signature=sig,
                    case=case.name,
                    triage=tri,
                    probe="warm",
                    context=a.as_dict(),
                    context_b=b.as_dict(),
                    factor_changed=factor,
                    comparisons=comps,
                    observations=obs,
                    fp64_available=has_fp64,
                    reruns_agreeing=agree,
                    reruns_total=total,
                    notes=case.notes,
                )
            )

    # ---------------- D3: A -> B -> A (plan section 15) ----------------
    if opts.do_warm and opts.do_return_trip:
        pairs = [(a, b) for a, b in case.context_pairs()
                 if a in usable and b in usable]
        for a, b in pairs:
            seed_everything(opts.seed)
            factor = (a.differing_factors(b) or ["<none>"])[0]
            try:
                first, second, recompiled = run_return_trip(
                    case, a, b, backend=opts.backend,
                    disk_cache=opts.disk_cache, seed=opts.seed)
            except Exception:
                continue
            tri, cmp = triage_return_trip(first, second, recompiled, factor, cfg)
            if tri.stage == STAGE_NONE:
                continue
            sig = signature(case.name, tri.stage, tri.kinds, f"trip:{factor}")
            if store is not None and not store.add(
                    sig, {"case": case.name, "stage": tri.stage,
                          "probe": "return_trip", "factor": factor}):
                continue
            records.append(
                FailureRecord(
                    signature=sig,
                    case=case.name,
                    triage=tri,
                    probe="return_trip",
                    context=a.as_dict(),
                    context_b=b.as_dict(),
                    factor_changed=factor,
                    comparisons={"A_vs_A_after_B": cmp},
                    observations={"first_A": first.summary(),
                                  "second_A": second.summary()},
                    fp64_available=False,
                    reruns_agreeing=1,
                    reruns_total=1,
                    notes=case.notes,
                )
            )

    return finish(records)


def minimize_record(case: Case, rec: FailureRecord, opts: RunOptions) -> FailureRecord:
    """Attach a minimized reproducer to a record (plan section 17.2).

    Failures that do not survive re-probing are left untouched and marked, not
    silently reported with an unminimized body.
    """
    from .case import Context
    from .minimize import Target, minimize, render_reproducer

    target = Target(stage=rec.triage.stage,
                    kinds=tuple(sorted(rec.triage.kinds)),
                    probe=rec.probe)
    ctx = next((c for c in case.contexts if c.name == rec.context.get("name")), None)
    if ctx is None:
        return rec
    ctx_b = None
    if rec.context_b:
        ctx_b = next((c for c in case.contexts
                      if c.name == rec.context_b.get("name")), None)
    try:
        m = minimize(case, ctx, target, backend=opts.backend, seed=opts.seed,
                     ctx_b=ctx_b, input_budget=opts.minimize_budget,
                     program_budget=opts.minimize_budget)
    except Exception as e:
        rec.minimized = {"reproduces": False, "error": f"{type(e).__name__}: {e}"}
        return rec

    rec.minimized = m.as_dict()
    if m.reproduces:
        rec.reproducer = render_reproducer(
            m, fn_name=getattr(case.fn, "__name__", "f"))
    return rec


def search_duplicates(rec: FailureRecord, repo: str,
                      limit: int = 5) -> FailureRecord:
    """Plan 18.5 step 7: flag possible duplicates, do not decide."""
    from .prefile import build_query, search_github_issues

    query = build_query(rec.case, rec.triage.stage, rec.triage.kinds,
                        rec.factor_changed)
    rec.duplicates = search_github_issues(query, repo=repo, limit=limit).as_dict()
    return rec


def run_all(
    cases: List[Case],
    opts: Optional[RunOptions] = None,
    cfg: Optional[Config] = None,
    store: Optional[DedupStore] = None,
    on_case=None,
) -> List[FailureRecord]:
    out: List[FailureRecord] = []
    for case in cases:
        recs = run_case(case, opts, cfg, store)
        out.extend(recs)
        if on_case is not None:
            on_case(case, recs)
    return out
