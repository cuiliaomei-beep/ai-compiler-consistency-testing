#!/usr/bin/env python
"""CLI for the consistency harness.

    python run.py selfcheck                 # validate the oracles
    python run.py validate                  # validate the reporting pipeline
    python run.py list                      # show registered cases
    python run.py run --tag alias           # probe cases, write reports/
    python run.py run --cases view_inplace --backend inductor --reruns 3

Note: --backend selects the compiler for the D2 (cold vs warm) probe. The D1
ladder is always eager -> eager -> aot_eager -> inductor, because that fixed
sequence is what makes stage attribution possible.
"""
from __future__ import annotations

import argparse
import inspect
import os
import sys
import time

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))

from tcd import cases_builtin  # noqa: F401,E402  (registers the hand-written cases)
from tcd.case import all_cases, get  # noqa: E402
from tcd.seeds import load_seed_cases, manifest_summary  # noqa: E402
from tcd.oracle import Config  # noqa: E402
from tcd.report import write_record, write_summary  # noqa: E402
from tcd.runner import RunOptions, run_case  # noqa: E402
from tcd.selfcheck import failed, format_checks, run_selfcheck  # noqa: E402
from tcd.campaign import Progress, write_campaign_summary  # noqa: E402
from tcd.torchcompat import HAVE_TORCH, ensure_msvc_env, environment  # noqa: E402

# Inductor's Windows CPU backend shells out to MSVC, which needs INCLUDE/LIB in
# the environment and not just cl.exe on PATH. Import them here so the harness
# works from an ordinary shell instead of only from a Native Tools prompt.
ensure_msvc_env()

# Imported issue reproducers, if tools/import_seeds.py has been run. These are
# the real ammunition; the hand-written cases only validate the machinery.
_SEEDS_LOADED = len(load_seed_cases()) if HAVE_TORCH else 0
from tcd.triage import DedupStore  # noqa: E402


def _repro_source(case) -> str:
    """Assemble a standalone-ish reproducer from the case definition."""
    parts = ["import torch", ""]
    for fn in (case.fn, case.make_inputs):
        try:
            parts.append(inspect.getsource(fn).rstrip())
            parts.append("")
        except (OSError, TypeError):
            parts.append(f"# source unavailable for {getattr(fn, '__name__', fn)!r}")
    parts.append("# contexts:")
    for c in case.contexts:
        parts.append(f"#   {c.name}: {c.factors}")
    return "\n".join(parts) + "\n"


def cmd_selfcheck(args) -> int:
    print("\nHarness self-check")
    print("=" * 72)
    checks = run_selfcheck(include_torch=not args.offline)
    print(format_checks(checks))
    print()
    if not HAVE_TORCH and not args.offline:
        print("  PyTorch is not installed here. Run this on the machine that has it;")
        print("  the offline checks above still validate signatures and dedup.")
        print()
    return 1 if failed(checks) else 0


def cmd_list(args) -> int:
    cases = all_cases(tag=args.tag)
    ms = manifest_summary()
    print(f"\n{len(cases)} case(s) registered "
          f"({_SEEDS_LOADED} from imported reproducers)")
    if ms["exists"]:
        print(f"  manifest: {ms['entries']} entries  {ms.get('projects')}")
    else:
        print("  no seed manifest - run: python tools/import_seeds.py")
    print()
    for c in cases:
        print(f"  {c.name}")
        print(f"      tags     : {', '.join(c.tags)}")
        print(f"      contexts : {', '.join(x.name for x in c.contexts)}")
        print(f"      pairs    : {len(c.context_pairs())} single-factor ordered pairs")
        if c.notes:
            print(f"      note     : {c.notes.splitlines()[0]}")
        print()
    return 0


def cmd_analyze(args) -> int:
    """Phase 1: what must the compiler preserve about each case?"""
    from tcd.analysis import analyze, analyze_source, format_analysis  # noqa: E402
    from tcd.ir import build_ir, bytecode_info, format_bytecode, format_ir  # noqa: E402

    if args.cases:
        cases = [get(n.strip()) for n in args.cases.split(",") if n.strip()]
    else:
        cases = all_cases(tag=args.tag)

    print("\nStatic alias / mutation analysis")
    print("=" * 72)
    n_facts = 0
    for case in cases:
        src = case.source
        if src is None:
            try:
                src = inspect.getsource(case.fn)
            except (OSError, TypeError):
                src = None
        a = analyze_source(src, case.name) if src else analyze(case.fn)
        n_facts += len(a.facts)
        print(f"\n{case.name}")
        print(format_analysis(a))
        if args.ir and src:
            print(format_ir(build_ir(src, case.name)))
        if args.bytecode:
            print(format_bytecode(bytecode_info(case.fn)))
        if args.json:
            import json
            os.makedirs(args.json, exist_ok=True)
            payload = a.as_dict()
            if args.ir and src:
                payload["ir"] = build_ir(src, case.name).as_dict()
            if args.bytecode:
                payload["bytecode"] = bytecode_info(case.fn).as_dict()
            with open(os.path.join(args.json, f"{case.name}.json"), "w",
                      encoding="utf-8") as fh:
                json.dump(payload, fh, indent=2, ensure_ascii=False)
    print(f"\n{'=' * 72}")
    print(f"{len(cases)} case(s), {n_facts} fact(s) derived")
    if args.json:
        print(f"written to {args.json}/")
    return 0


def cmd_sites(args) -> int:
    """Plan 5.1: where does this code cross into a compiler, and what is reachable?"""
    from tcd.analysis import analyze_source, format_analysis  # noqa: E402
    from tcd.ir import build_ir, format_ir  # noqa: E402
    from tcd.obligation import (contexts_for_source,  # noqa: E402
                                format_obligations)
    from tcd.sites import format_sites, scan_path, site_source  # noqa: E402

    t0 = time.perf_counter()
    sites = scan_path(args.path)
    dt = time.perf_counter() - t0
    print(f"\nCompilation sites under {args.path}")
    print("=" * 72)
    print(format_sites(sites))
    by_api = {}
    for s in sites:
        by_api[s.api] = by_api.get(s.api, 0) + 1
    print(f"\n{len(sites)} site(s) in {dt:.2f}s  {by_api}")

    if args.analyze:
        print("\nPhase 1 on each site target")
        print("=" * 72)
        seen = set()
        n_ok = 0
        for s in sites:
            key = (s.file, s.target)
            if key in seen:
                continue
            seen.add(key)
            src = site_source(s)
            if not src:
                continue
            a = analyze_source(src, s.target or "<fn>")
            if a.error:
                continue
            n_ok += 1
            print(f"\n{os.path.basename(s.file)}:{s.line}  {s.target}")
            print(format_analysis(a))
            if args.ir:
                print(format_ir(build_ir(src, s.target or "<fn>")))
            ctxs, scs, obl = contexts_for_source(src)
            print(format_obligations(scs, obl))
            print(f"  -> {len(ctxs)} context(s)")
        print(f"\n{n_ok} target(s) analysed")

    if args.json:
        import json
        d = os.path.dirname(args.json)
        if d:
            os.makedirs(d, exist_ok=True)
        with open(args.json, "w", encoding="utf-8") as fh:
            json.dump([s.as_dict() for s in sites], fh, indent=2, ensure_ascii=False)
        print(f"written to {args.json}")
    return 0


def cmd_experiments(args) -> int:
    """Plan 26: experiments A-E."""
    from tcd.experiments import (experiment_a, experiment_b, experiment_c,  # noqa: E402
                                 experiment_d, experiment_e, format_experiment)

    which = [w.strip().upper() for w in args.which.split(",") if w.strip()]
    results = []
    print("\nKey experiments (plan section 26)")
    print("=" * 72)
    for w in which:
        if w == "A":
            r = experiment_a(backend=args.backend, seed=args.seed)
        elif w == "B":
            r = experiment_b(backend=args.backend, seed=args.seed)
        elif w == "C":
            r = experiment_c(backend=args.backend, seed=args.seed)
        elif w == "D":
            r = experiment_d(seed=args.seed, real_backend=args.backend)
        elif w == "E":
            from tcd.cases_model import iter_chain_cases, validate_cases  # noqa: E402
            cases = list(iter_chain_cases(count=args.chains, depth=3, seed=args.seed))
            cases, _bad = validate_cases(cases)
            r = experiment_e(cases, backend=args.backend, seed=args.seed)
        else:
            print(f"  unknown experiment {w!r}")
            continue
        print(format_experiment(r))
        results.append(r)

    if args.out:
        import json
        d = os.path.dirname(args.out)
        if d:
            os.makedirs(d, exist_ok=True)
        with open(args.out, "w", encoding="utf-8") as fh:
            json.dump({"environment": environment(),
                       "backend": args.backend,
                       "experiments": [r.as_dict() for r in results]},
                      fh, indent=2, ensure_ascii=False)
        print(f"\nwritten to {args.out}")
    return 0


def cmd_metrics(args) -> int:
    """Plan 27: efficiency and scalability."""
    from tcd.metrics import (format_metrics, measure_dynamic,  # noqa: E402
                             measure_static_cases, measure_static_path)

    static = dynamic = None
    cases = []
    print("\nEfficiency and scalability (plan section 27)")
    print("=" * 72)
    if args.path:
        static = measure_static_path(args.path)
        print(f"  static half over {args.path}")
    else:
        if args.chains:
            from tcd.cases_model import iter_chain_cases, validate_cases  # noqa: E402
            cases = list(iter_chain_cases(count=args.chains, depth=3, seed=0))
            cases, _ = validate_cases(cases)
        else:
            cases = all_cases(tag=args.tag)
        static = measure_static_cases(cases)
        print(f"  static half over {len(cases)} case(s)")
    if args.dynamic and cases:
        dynamic = measure_dynamic(cases, backend=args.backend, budget=args.budget)
    print(format_metrics(static, dynamic))
    if args.out:
        import json
        d = os.path.dirname(args.out)
        if d:
            os.makedirs(d, exist_ok=True)
        with open(args.out, "w", encoding="utf-8") as fh:
            json.dump({"environment": environment(),
                       "static": static.as_dict() if static else None,
                       "dynamic": dynamic.as_dict() if dynamic else None},
                      fh, indent=2, ensure_ascii=False)
        print(f"\nwritten to {args.out}")
    return 0


def cmd_opinfo(args) -> int:
    """Build cases from PyTorch's OpInfo database and report the yield."""
    from tcd.cases_opinfo import iter_cases, load_op_db, validate_cases  # noqa: E402

    db, err = load_op_db()
    if db is None:
        print(f"\nop_db unavailable: {err}")
        print("  try: python -m pip install expecttest")
        return 2

    print(f"\nOpInfo corpus  ({len(db)} operators in the database)")
    print("=" * 72)
    cases = list(iter_cases(limit_ops=args.limit_ops,
                            samples_per_op=args.samples_per_op,
                            dtype=args.dtype))
    print(f"  built     : {len(cases)} case(s)")
    ok, bad = validate_cases(cases)
    print(f"  runnable  : {len(ok)}")
    print(f"  rejected  : {len(bad)}")
    if bad and args.show_rejected:
        for name, why in bad[:40]:
            print(f"      {name:<34} {why}")
    if ok:
        print("\n  examples:")
        for c in ok[:8]:
            print(f"      {c.name:<30} {c.notes}")
    return 0


def cmd_mutate(args) -> int:
    """Generate structural variants and report which survive validation."""
    from tcd.mutate import generate, validate_mutants  # noqa: E402

    if args.cases:
        cases = [get(n.strip()) for n in args.cases.split(",") if n.strip()]
    else:
        cases = all_cases(tag=args.tag)

    print("\nStructure mutation")
    print("=" * 72)
    tot_gen = tot_ok = 0
    for case in cases:
        mutants = generate(case, depth=args.depth,
                           allow_value_changing=args.free_mutation)
        if not mutants:
            print(f"\n{case.name}: no applicable operator")
            continue
        valid, invalid = validate_mutants(case, mutants,
                                          require_semantics=not args.free_mutation)
        tot_gen += len(mutants)
        tot_ok += len(valid)
        print(f"\n{case.name}: {len(mutants)} generated, "
              f"{len(valid)} semantics-preserving")
        for m in valid:
            print(f"  [keep] {m.operator:<18} {m.description}")
        if args.show_invalid:
            for m in invalid:
                print(f"  [drop] {m.operator:<18} {m.invalid_reason[:90]}")

    print(f"\n{'=' * 72}")
    print(f"{tot_gen} mutant(s) generated, {tot_ok} kept "
          f"({100 * tot_ok / tot_gen:.0f}% preserve eager semantics)"
          if tot_gen else "nothing generated")
    return 0


def cmd_baseline(args) -> int:
    """Plan sections 22-24, Setting B: same harness, different generators."""
    from tcd.baselines import (  # noqa: E402
        format_setting_b, iter_nnsmith_cases, probe_baselines, run_setting_b)
    from tcd.cases_model import iter_chain_cases  # noqa: E402

    print("\nBaseline availability")
    print("=" * 76)
    statuses = probe_baselines()
    for s in statuses:
        mark = "OK " if s.available else "-- "
        print(f"  [{mark}] {s.name:<12} {s.detail}")

    usable = [s for s in statuses if s.available]
    if not usable:
        print("\nNo baseline implementation is runnable here; nothing to compare.")
        return 2

    gens: Dict[str, Any] = {
        "ours (derived)": lambda: iter_chain_cases(count=args.budget, depth=3,
                                                   structured=True),
    }
    if any(s.name == "NNSmith" and s.available for s in statuses):
        gens["NNSmith"] = lambda: iter_nnsmith_cases(count=args.budget,
                                                     max_nodes=args.max_nodes)

    print(f"\nSetting B - {args.budget} cases per generator, backend {args.backend}")
    print("=" * 76)
    results = run_setting_b(gens, backend=args.backend, case_budget=args.budget)
    print(format_setting_b(results))

    if args.out:
        import json
        os.makedirs(os.path.dirname(args.out) or ".", exist_ok=True)
        with open(args.out, "w", encoding="utf-8") as fh:
            json.dump({"availability": [s.as_dict() for s in statuses],
                       "setting_b": [r.as_dict() for r in results]},
                      fh, indent=2, ensure_ascii=False)
        print(f"\nwritten to {args.out}")
    return 0


def cmd_ablate(args) -> int:
    """Plan section 25, RQ3: does the static analysis earn its keep?"""
    from tcd.ablation import LEVELS, format_results, run_ablation  # noqa: E402
    from tcd.cases_model import iter_chain_cases, validate_cases as vmc  # noqa: E402
    from tcd.cases_opinfo import iter_cases, validate_cases  # noqa: E402

    cases: List[Any] = []
    if args.chains:
        built = list(iter_chain_cases(count=args.chains, depth=args.chain_depth))
        ok, _ = vmc(built)
        cases += ok
    if args.opinfo:
        built = list(iter_cases(limit_ops=args.opinfo, samples_per_op=1))
        ok, _ = validate_cases(built)
        cases += ok
    if args.tag or args.cases:
        cases += ([get(n.strip()) for n in args.cases.split(",") if n.strip()]
                  if args.cases else all_cases(tag=args.tag))
    if not cases:
        print("no cases selected; pass --chains / --opinfo / --tag")
        return 2

    levels = [l.strip() for l in args.levels.split(",")] if args.levels else LEVELS
    print(f"\nRQ3 ablation - {len(cases)} case(s), budget {args.budget} "
          f"context(s) per case, backend {args.backend}")
    print("=" * 76)
    results = run_ablation(cases, levels, args.budget, args.backend)
    print(format_results(results))

    if args.out:
        import json
        os.makedirs(os.path.dirname(args.out) or ".", exist_ok=True)
        with open(args.out, "w", encoding="utf-8") as fh:
            json.dump([r.as_dict() for r in results], fh, indent=2)
        print(f"\nwritten to {args.out}")

    base = next((r for r in results if r.level == "A0"), None)
    full = next((r for r in results if r.level == "FULL"), None)
    if base and full and base.specializations_per_test:
        ratio = full.specializations_per_test / base.specializations_per_test
        print(f"\nFULL vs A0: {ratio:.2f}x specializations per valid test, "
              f"validity {base.valid_rate:.2f} -> {full.valid_rate:.2f}")
        if ratio <= 1.05:
            print("  The static analysis is NOT paying for itself on this corpus.")
    return 0


def cmd_validate(args) -> int:
    """Prove the whole pipeline can emit a record, on this machine, today.

    ``selfcheck`` validates the oracles in isolation. This validates everything
    after them: runner, triage, dedup, record and issue draft. It swaps the top
    layer of the D1 ladder for a backend that deliberately returns a wrong
    answer, so a healthy pipeline MUST report findings.

    Without this, a nightly run that prints "0 candidates" is ambiguous: it
    could mean the code is clean, or that findings are being silently dropped.
    """
    if not HAVE_TORCH:
        print("PyTorch is required for pipeline validation.")
        return 2

    from tcd.execution import E0_EAGER  # noqa: E402

    out_dir = args.out
    opts = RunOptions(
        reruns=0,
        do_warm=False,          # D2 cannot see a uniformly wrong backend by design
        keep_info=False,
        layers=[(E0_EAGER, None), ("E_poison", "poison")],
    )
    store = DedupStore(os.path.join(out_dir, "_dedup.json"))
    cases = all_cases()

    print("\nPipeline validation (eager vs a deliberately wrong backend)")
    print("=" * 72)
    total = 0
    for case in cases:
        recs = run_case(case, opts, Config(), store)
        total += len(recs)
        mark = "PASS" if recs else "FAIL"
        kinds = sorted({k for r in recs for k in r.triage.kinds})
        print(f"  [{mark}] {case.name:<24} {len(recs)} record(s)  {', '.join(kinds)}")
        for r in recs:
            write_record(out_dir, r, _repro_source(case))
    store.save()

    print()
    if total == 0:
        print("  FAIL - the pipeline reported nothing against a backend that")
        print("  returns wrong answers. A '0 candidates' run cannot be trusted.")
        return 1
    print(f"  {total} record(s) written to {out_dir}/ - the pipeline emits findings.")
    print("  A '0 candidates' result from a real run is therefore meaningful.")
    return 0


def cmd_run(args) -> int:
    if not HAVE_TORCH:
        print("PyTorch is required to run probes. Use `selfcheck --offline` here.")
        return 2

    if args.from_file:
        # 11.1 item 4 + section 21: compile/JIT functions in a real project
        # file, inputs constructed from their signatures. Importing the file
        # executes its module-level code - only paths named on the command
        # line are ever imported.
        from tcd.cases_model import validate_cases as vmc  # noqa: E402
        from tcd.cases_project import cases_from_file  # noqa: E402
        built, notes = cases_from_file(args.from_file)
        for n in notes:
            print(f"  note: {n}")
        cases, rejected = vmc(built)
        print(f"project file corpus: {len(built)} site target(s), {len(cases)} runnable, "
              f"{len(rejected)} rejected")
    elif args.doctests:
        # 11.1 item 3: official examples from torch.* docstrings
        from tcd.cases_model import validate_cases as vmc  # noqa: E402
        from tcd.cases_project import iter_doctest_cases  # noqa: E402
        built = list(iter_doctest_cases(limit=args.doctests))
        cases, rejected = vmc(built)
        print(f"docstring-example corpus: {len(built)} built, {len(cases)} runnable, "
              f"{len(rejected)} rejected")
    elif args.models or args.chains:
        from tcd.cases_model import (  # noqa: E402
            iter_chain_cases, iter_module_cases, validate_cases as vmc)
        built = []
        if args.models:
            built += list(iter_module_cases(limit=args.models))
        if args.chains:
            built += list(iter_chain_cases(count=args.chains, depth=args.chain_depth))
        cases, rejected = vmc(built)
        print(f"multi-operator corpus: {len(built)} built, {len(cases)} runnable, "
              f"{len(rejected)} rejected")
    elif args.opinfo or args.opinfo_limit:
        from tcd.cases_opinfo import iter_cases, validate_cases  # noqa: E402
        built = list(iter_cases(limit_ops=args.opinfo_limit,
                                samples_per_op=args.opinfo_samples,
                                alias_ops_first=args.alias_ops_first))
        cases, rejected = validate_cases(built)
        print(f"OpInfo corpus: {len(built)} built, {len(cases)} runnable, "
              f"{len(rejected)} rejected")
    elif args.cases:
        cases = [get(n.strip()) for n in args.cases.split(",") if n.strip()]
    else:
        cases = all_cases(tag=args.tag)
    if not cases:
        print("no cases selected")
        return 2

    if args.mutate:
        from tcd.mutate import generate, mutant_cases, validate_mutants  # noqa: E402
        expanded = []
        n_gen = n_kept = 0
        for case in cases:
            expanded.append(case)
            mutants = generate(case, depth=args.mutate_depth,
                               allow_value_changing=args.free_mutation)
            if not mutants:
                continue
            valid, _ = validate_mutants(case, mutants,
                                        require_semantics=not args.free_mutation)
            n_gen += len(mutants)
            n_kept += len(valid)
            expanded.extend(mutant_cases(case, valid))
        print(f"structure mutation: {n_gen} generated, {n_kept} preserve eager "
              f"semantics and were added to the run")
        cases = expanded

    opts = RunOptions(
        backend=args.backend,
        disk_cache=args.disk_cache,
        reruns=args.reruns,
        do_layered=not args.warm_only,
        do_warm=not args.layered_only,
        seed=args.seed,
        keep_info=args.keep_info,
        minimize=args.minimize,
        minimize_budget=args.minimize_budget,
        search_duplicates=args.search_duplicates,
        duplicate_repo=args.duplicate_repo,
    )
    cfg = Config(fp64_multiplier=args.fp64_multiplier, strict_stride=args.strict_stride)
    store = DedupStore(os.path.join(args.out, "_dedup.json"))

    env = environment()
    print(f"\ntorch {env['torch']}  cuda {env['cuda']}  device {env['device_name']}")
    print(f"backend={opts.backend}  disk_cache={opts.disk_cache}  reruns={opts.reruns}")
    print(f"{len(cases)} case(s) -> {args.out}\n")

    # Progress is flushed after every case. A campaign has to survive a reboot:
    # the first full-corpus attempt lost 110 minutes of work to a shutdown
    # because nothing reached disk until the process finished.
    progress = Progress.load(os.path.join(args.out, "progress.json"))
    if progress.completed and not args.restart:
        pending = [c for c in cases if not progress.done(c.name)]
        print(f"resuming: {len(progress.completed)} case(s) already done, "
              f"{len(pending)} remaining")
        cases = pending
    elif args.restart:
        progress = Progress(path=os.path.join(args.out, "progress.json"))
        print("restarting: previous progress discarded")

    all_records = []
    t0 = time.perf_counter()
    for case in cases:
        t1 = time.perf_counter()
        try:
            recs = run_case(case, opts, cfg, store)
        except Exception as e:
            print(f"  {case.name:<24} ERROR {type(e).__name__}: {str(e)[:100]}")
            progress.mark(case.name, 0, error=f"{type(e).__name__}: {e}")
            continue
        dt = time.perf_counter() - t1
        new = [r for r in recs if r.triage.submittable]
        print(f"  {case.name:<24} {len(recs)} candidate(s), "
              f"{len(new)} submittable   [{dt:.1f}s]", flush=True)
        src = _repro_source(case)
        for r in recs:
            d = write_record(args.out, r, src)
            flag = "*" if r.triage.submittable else " "
            print(f"    {flag} {r.triage.priority:<6} {r.triage.stage:<24} "
                  f"{r.signature}  {os.path.relpath(d, args.out)}", flush=True)
        all_records.extend(recs)
        # record + dedup reach disk before we move on
        store.save()
        progress.mark(case.name, len(recs))

    store.save()
    stats = store.stats()
    elapsed = time.perf_counter() - t0
    path = write_summary(args.out, all_records, {
        "torch": env["torch"],
        "device": env["device_name"] or "cpu",
        "backend": opts.backend,
        "cases this run": len(cases),
        "candidates this run": len(all_records),
        "submittable this run": sum(1 for r in all_records if r.triage.submittable),
        "unique signatures": stats["unique"],
        "elapsed": f"{elapsed:.1f}s",
    })
    campaign_path = write_campaign_summary(args.out, progress)
    print(f"\n{len(all_records)} candidate(s) this run, "
          f"{sum(1 for r in all_records if r.triage.submittable)} submittable")
    for k, v in progress.summary().items():
        print(f"  {k}: {v}")
    print(f"summary:  {path}")
    print(f"campaign: {campaign_path}\n")
    return 0


def main() -> int:
    p = argparse.ArgumentParser(description=__doc__,
                                formatter_class=argparse.RawDescriptionHelpFormatter)
    sub = p.add_subparsers(dest="cmd", required=True)

    s = sub.add_parser("selfcheck", help="validate the harness itself")
    s.add_argument("--offline", action="store_true", help="skip every torch-dependent check")
    s.set_defaults(func=cmd_selfcheck)

    s = sub.add_parser("list", help="list registered cases")
    s.add_argument("--tag", default=None)
    s.set_defaults(func=cmd_list)

    s = sub.add_parser("analyze", help="static alias/mutation analysis of cases (Phase 1)")
    s.add_argument("--cases", default=None)
    s.add_argument("--tag", default=None)
    s.add_argument("--ir", action="store_true", help="also print the 5.2 IR with dependencies")
    s.add_argument("--bytecode", action="store_true",
                   help="also read the live function's bytecode (wrappers, closures, dispatch)")
    s.add_argument("--json", default=None, help="also write per-case JSON here")
    s.set_defaults(func=cmd_analyze)

    s = sub.add_parser("sites", help="5.1: find compilation sites in a file or directory")
    s.add_argument("path")
    s.add_argument("--analyze", action="store_true",
                   help="run Phase 1 (analysis, obligations, contexts) on each site target")
    s.add_argument("--ir", action="store_true", help="with --analyze, also print the IR")
    s.add_argument("--json", default=None, help="write the site list here")
    s.set_defaults(func=cmd_sites)

    s = sub.add_parser("experiments", help="26: key experiments A-E")
    s.add_argument("--which", default="A,B,C,D,E")
    s.add_argument("--backend", default="aot_eager")
    s.add_argument("--chains", type=int, default=8, help="corpus size for experiment E")
    s.add_argument("--seed", type=int, default=0)
    s.add_argument("--out", default=None)
    s.set_defaults(func=cmd_experiments)

    s = sub.add_parser("metrics", help="27: efficiency and scalability")
    s.add_argument("--path", default=None, help="measure Phase 1 over a file or directory")
    s.add_argument("--chains", type=int, default=0, help="or over N synthesised chains")
    s.add_argument("--tag", default=None, help="or over registered cases")
    s.add_argument("--dynamic", action="store_true", help="also measure Phase 2/3")
    s.add_argument("--backend", default="aot_eager")
    s.add_argument("--budget", type=int, default=4, help="contexts per case, dynamic half")
    s.add_argument("--out", default=None)
    s.set_defaults(func=cmd_metrics)

    s = sub.add_parser("opinfo", help="build cases from PyTorch's OpInfo database")
    s.add_argument("--limit-ops", type=int, default=0, help="0 = all ~700 operators")
    s.add_argument("--samples-per-op", type=int, default=1)
    s.add_argument("--dtype", default="float32")
    s.add_argument("--show-rejected", action="store_true")
    s.set_defaults(func=cmd_opinfo)

    s = sub.add_parser("mutate", help="generate + validate structural variants")
    s.add_argument("--cases", default=None)
    s.add_argument("--tag", default=None)
    s.add_argument("--show-invalid", action="store_true")
    s.add_argument("--depth", type=int, default=1)
    s.add_argument("--free-mutation", action="store_true")
    s.set_defaults(func=cmd_mutate)

    s = sub.add_parser("baseline", help="RQ2: compare generators in one harness")
    s.add_argument("--budget", type=int, default=30, help="cases per generator")
    s.add_argument("--max-nodes", type=int, default=6, help="NNSmith graph size")
    s.add_argument("--backend", default="aot_eager")
    s.add_argument("--out", default=None)
    s.set_defaults(func=cmd_baseline)

    s = sub.add_parser("ablate", help="RQ3: measure what the static analysis adds")
    s.add_argument("--chains", type=int, default=0)
    s.add_argument("--chain-depth", type=int, default=3)
    s.add_argument("--opinfo", type=int, default=0)
    s.add_argument("--tag", default=None)
    s.add_argument("--cases", default=None)
    s.add_argument("--levels", default=None, help="comma-separated, default all")
    s.add_argument("--budget", type=int, default=8,
                   help="contexts per case, identical for every level")
    s.add_argument("--backend", default="aot_eager")
    s.add_argument("--out", default=None)
    s.set_defaults(func=cmd_ablate)

    s = sub.add_parser("validate", help="prove the pipeline can emit a record at all")
    s.add_argument("--out", default="reports_validate")
    s.set_defaults(func=cmd_validate)

    s = sub.add_parser("run", help="probe cases and write reports")
    s.add_argument("--cases", default=None, help="comma-separated case names")
    s.add_argument("--tag", default=None, help="select cases by tag")
    s.add_argument("--backend", default="inductor")
    s.add_argument("--out", default="reports")
    s.add_argument("--reruns", type=int, default=2, help="confirmation re-runs per candidate")
    s.add_argument("--seed", type=int, default=0)
    s.add_argument("--disk-cache", action="store_true",
                   help="leave the on-disk FX/Inductor caches ENABLED (probes cross-process reuse)")
    s.add_argument("--layered-only", action="store_true", help="D1 only")
    s.add_argument("--warm-only", action="store_true", help="D2 only")
    s.add_argument("--restart", action="store_true",
                   help="discard saved progress and probe every case again")
    s.add_argument("--opinfo", action="store_true",
                   help="probe PyTorch's OpInfo corpus instead of the registry")
    s.add_argument("--opinfo-limit", type=int, default=0,
                   help="cap operators taken from OpInfo (0 = all ~700)")
    s.add_argument("--opinfo-samples", type=int, default=1,
                   help="sample inputs per operator")
    s.add_argument("--mutate", action="store_true",
                   help="also probe validated structural variants of each case")
    s.add_argument("--mutate-depth", type=int, default=1,
                   help="compose this many operators; PyTorch CI already covers "
                        "single-operator OpInfo programs, so depth is the dial "
                        "that reaches unexplored structure")
    s.add_argument("--alias-ops-first", action="store_true",
                   help="prioritise operators whose schema declares aliasing")
    s.add_argument("--models", type=int, default=0,
                   help="probe N cases from PyTorch's nn.Module database "
                        "(stateful: buffers mutate in place during forward)")
    s.add_argument("--chains", type=int, default=0,
                   help="probe N synthesised multi-operator chains")
    s.add_argument("--chain-depth", type=int, default=3,
                   help="compute steps per synthesised chain")
    s.add_argument("--from-file", default=None,
                   help="import this project file and probe every compilation "
                        "site's target with signature-constructed inputs (11.1/21)")
    s.add_argument("--doctests", type=int, default=0,
                   help="probe N official docstring examples from torch.* (11.1)")
    s.add_argument("--free-mutation", action="store_true",
                   help="do not require mutants to preserve the original's "
                        "semantics; each is tested against its own eager "
                        "reference, gated on determinism instead. Enables "
                        "value-changing writes, which identity writes cannot reach")
    s.add_argument("--minimize", action="store_true",
                   help="minimize submittable candidates (plan 17.2): shrink the "
                        "program and its inputs while the same failure survives")
    s.add_argument("--minimize-budget", type=int, default=20,
                   help="max shrink attempts per phase; each costs a compile")
    s.add_argument("--search-duplicates", action="store_true",
                   help="query the tracker for possible duplicates (plan 18.5); "
                        "set GITHUB_TOKEN to avoid the unauthenticated rate limit")
    s.add_argument("--duplicate-repo", default="pytorch/pytorch")
    s.add_argument("--keep-info", action="store_true",
                   help="also record info-level rows such as guard-suspicious switches")
    s.add_argument("--fp64-multiplier", type=float, default=4.0)
    s.add_argument("--strict-stride", action="store_true")
    s.set_defaults(func=cmd_run)

    args = p.parse_args()
    return args.func(args)


if __name__ == "__main__":
    raise SystemExit(main())
