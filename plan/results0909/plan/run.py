#!/usr/bin/env python
"""tcc command line.

    python run.py selfcheck [--offline]          two-level self-check
    python run.py list [--tag T]                 registered programs
    python run.py sites <path>                   5.1 compilation-site discovery
    python run.py analyze [--programs a,b]       5.2 + 6-8 IR and semantic factors
    python run.py obligations [--yaml DIR]       9-10 SCS and test obligations
    python run.py plan                           11-15 contexts / pairs / sequences
    python run.py run [--backend inductor]       full pipeline -> reports/
    python run.py bench                          RQ1 ground-truth benchmark
    python run.py baselines                      RQ2 random vs ours (+ external adapters)
    python run.py ablate                         RQ3 A0..A6/FULL
    python run.py cache                          RQ4 cache / specialization detection
    python run.py campaign                       RQ5 real-world run with status tracking
    python run.py experiments [--only A,B]       experiments A-E
    python run.py metrics                        section 27
    python run.py all                            everything, in order
"""
from __future__ import annotations

import argparse
import json
import os
import sys
import time

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)

from tcc.compat import HAVE_TORCH, ensure_msvc_env, environment  # noqa: E402

ensure_msvc_env()

RESULTS = os.path.join(HERE, "results")
REPORTS = os.path.join(HERE, "reports")


def _programs(args):
    from tcc import corpus  # noqa: F401
    from tcc.program import all_programs, get
    from tcc.seeds import programs_from_dir

    ps = []
    if getattr(args, "nnsmith", 0):
        from tcc.baselines import nnsmith_programs
        ok, rejected = nnsmith_programs(n=args.nnsmith, seed=args.seed)
        print(f"NNSmith: {len(ok)} model(s) generated, {len(rejected)} rejected")
        ps += ok
    if getattr(args, "opinfo", 0):
        from tcc.seeds import programs_from_opinfo
        ok, rejected = programs_from_opinfo(limit=args.opinfo, seed=args.seed,
                                            samples_per_op=args.opinfo_samples)
        print(f"OpInfo: {len(ok)} operator sample(s) as programs, {len(rejected)} rejected")
        ps += ok
    if getattr(args, "programs", None):
        ps += [get(n.strip()) for n in args.programs.split(",") if n.strip()]
    elif getattr(args, "from_dir", None) and getattr(args, "file", None):
        # one reproducer, for isolated (per-process) campaigns
        from tcc.seeds import _probe_in_subprocess, load_reproducer
        full = os.path.join(args.from_dir, args.file)
        alive, why = _probe_in_subprocess(full, 90.0)
        p, why2 = load_reproducer(full) if alive else (None, why)
        if p is None:
            print(f"    reject {args.file}: {why2}")
        else:
            ps.append(p)
    elif getattr(args, "from_dir", None):
        ok, rejected = programs_from_dir(args.from_dir)
        print(f"loaded {len(ok)} reproducer(s) from {args.from_dir}, {len(rejected)} rejected")
        for nm, why in rejected[:20]:
            print(f"    reject {nm}: {why}")
        ps += ok
    elif not getattr(args, "no_corpus", False):
        ps += all_programs(tag=getattr(args, "tag", None))   # corpus, plus any --nnsmith/--opinfo programs
    sl = getattr(args, "slice", None)
    if sl:
        a, _, b = sl.partition(":")
        ps = ps[int(a or 0):int(b) if b else None]
    dev = getattr(args, "device", None)
    if dev:
        from tcc.seeds import programs_on_device
        ps = programs_on_device(ps, dev)
    return ps


def _dump(path, obj):
    os.makedirs(os.path.dirname(path), exist_ok=True)
    with open(path, "w", encoding="utf-8") as fh:
        json.dump(obj, fh, indent=2, ensure_ascii=False, default=str)
    return path


# --------------------------------------------------------------------------

def cmd_selfcheck(args):
    from tcc.selfcheck import failed, format_checks, run_selfcheck
    print("\ntcc self-check\n" + "=" * 72)
    checks = run_selfcheck(include_torch=not args.offline)
    print(format_checks(checks))
    return 1 if failed(checks) else 0


def cmd_list(args):
    ps = _programs(args)
    print(f"\n{len(ps)} program(s)")
    for p in ps:
        print(f"  {p.name:<24} tags={','.join(p.tags):<36} {p.notes[:60]}")
    return 0


def cmd_sites(args):
    from tcc.sites import format_sites, scan_path
    sites = scan_path(args.path)
    print(f"\ncompilation sites under {args.path}: {len(sites)}\n" + "=" * 72)
    print(format_sites(sites))
    if args.json:
        _dump(args.json, [s.as_dict() for s in sites])
        print(f"\nwritten to {args.json}")
    return 0


def cmd_analyze(args):
    from tcc.factors import analyze, format_analysis
    from tcc.ir import format_ir
    ps = _programs(args)
    print("\nPhase 1: IR + semantic factor analysis\n" + "=" * 72)
    out = {}
    for p in ps:
        a = analyze(p.fn, p.get_source())
        print(f"\n{p.name}")
        if args.ir and a.ir:
            print(format_ir(a.ir))
        print(format_analysis(a))
        out[p.name] = a.as_dict()
    if args.json:
        _dump(args.json, out)
        print(f"\nwritten to {args.json}")
    return 0


def cmd_obligations(args):
    from tcc.factors import analyze
    from tcc.scs import derive_obligations, derive_scs, format_obligations, obligations_to_yaml
    ps = _programs(args)
    print("\nSemantic Context Signature + Test Obligations\n" + "=" * 72)
    for p in ps:
        a = analyze(p.fn, p.get_source())
        scs = derive_scs(a)
        obs = derive_obligations(a, scs)
        print(f"\n{p.name}")
        print(format_obligations(scs, obs))
        if args.yaml:
            os.makedirs(args.yaml, exist_ok=True)
            with open(os.path.join(args.yaml, f"{p.name}.yaml"), "w", encoding="utf-8") as fh:
                fh.write(obligations_to_yaml(obs))
    if args.yaml:
        print(f"\nYAML written to {args.yaml}/")
    return 0


def cmd_plan(args):
    from tcc.generate import build_plan, format_plan
    ps = _programs(args)
    print("\nPhase 2: test plans\n" + "=" * 72)
    out = {}
    for p in ps:
        plan = build_plan(p, max_contexts=args.max_contexts)
        print(f"\n{p.name}")
        print(format_plan(plan))
        out[p.name] = plan.as_dict()
    if args.json:
        _dump(args.json, out)
    return 0


def cmd_run(args):
    if not HAVE_TORCH:
        print("PyTorch is required.")
        return 2
    from tcc.campaign import Progress, write_campaign_summary
    from tcc.oracle import Config
    from tcc.report import DedupStore, write_report, write_summary
    from tcc.runner import RunOptions, run_program
    ps = _programs(args)
    if not ps:
        print("no programs selected")
        return 2
    opts = RunOptions(backend=args.backend, disk_cache=args.disk_cache, reruns=args.reruns,
                      do_layered=not args.matrix_only, do_matrix=not args.layered_only, seed=args.seed,
                      keep_info=args.keep_info, minimize=args.minimize, minimize_budget=args.minimize_budget,
                      max_contexts=args.max_contexts, test_budget=args.test_budget,
                      time_budget_s=args.time_budget, search_duplicates=args.search_duplicates,
                      duplicate_repo=args.duplicate_repo)
    store = DedupStore(os.path.join(args.out, "_dedup.json"))
    env = environment()
    print(f"\ntorch {env['torch']}  device {env['device_name']}  backend={opts.backend}  reruns={opts.reruns}")
    print(f"{len(ps)} program(s) -> {args.out}\n")
    progress = Progress.load(os.path.join(args.out, "progress.json"))
    if progress.completed and not args.restart:
        ps = [p for p in ps if not progress.done(p.name)]
        print(f"resuming: {len(progress.completed)} done, {len(ps)} remaining")
    elif args.restart:
        progress = Progress(path=os.path.join(args.out, "progress.json"))
    allrec, results = [], []
    t0 = time.perf_counter()
    cfg = Config(strict_stride=args.strict_stride)
    for p in ps:
        t1 = time.perf_counter()
        r = run_program(p, opts, cfg, store, log=print)
        dt = time.perf_counter() - t1
        sub = [x for x in r.records if x.triage.submittable]
        print(f"  {p.name:<24} {len(r.records)} candidate(s), {len(sub)} submittable, "
              f"{r.tests_executed} tests, {r.compile_count} compiles  [{dt:.1f}s]"
              + (f"  ERROR {r.error}" if r.error else ""), flush=True)
        for rec in r.records:
            d = write_report(args.out, rec)
            print(f"    {'*' if rec.triage.submittable else ' '} {rec.triage.priority:<6} {rec.triage.stage:<22} "
                  f"{rec.factor_changed or '-':<20} {os.path.relpath(d, args.out)}", flush=True)
        allrec += r.records
        results.append(r.as_dict())
        store.save()
        progress.mark(p.name, len(r.records), r.tests_executed, r.error)
    store.save()
    write_summary(args.out, allrec, {"torch": env["torch"], "device": env["device_name"], "backend": opts.backend,
                                     "programs": len(ps), "candidates": len(allrec),
                                     "submittable": sum(1 for r in allrec if r.triage.submittable),
                                     "unique signatures": store.stats()["unique"],
                                     "elapsed": f"{time.perf_counter() - t0:.1f}s"})
    # a resumed run must not discard the results of the programs it skipped
    prev_path = os.path.join(args.out, "run_results.json")
    if os.path.exists(prev_path) and not args.restart:
        try:
            with open(prev_path, encoding="utf-8") as fh:
                prev = json.load(fh)
            done_now = {r["program"] for r in results}
            results = [r for r in prev if r.get("program") not in done_now] + results
        except Exception:
            pass
    _dump(prev_path, results)
    write_campaign_summary(args.out, progress)
    print(f"\n{len(allrec)} candidate(s); summary at {os.path.join(args.out, 'SUMMARY.md')}")
    return 0


def cmd_bench(args):
    from tcc.benchmark import format_benchmark, run_benchmark, run_historical
    if args.historical:
        res = run_historical(args.historical, backend=args.backend, budget=args.budget, log=print)
        _dump(os.path.join(args.out, "rq1_historical.json"), res)
        print(f"{len(res['entries'])} historical entr(ies) processed on torch {res['torch']}")
        return 0
    res = run_benchmark(backend=args.backend, budget=args.budget, reruns=args.reruns, only=args.only,
                        check_fixed=not args.no_fixed, log=print, out_dir=args.out)
    print(format_benchmark(res))
    _dump(os.path.join(args.out, "rq1_benchmark.json"), res)
    return 0


def cmd_baselines(args):
    from tcc.experiments import rq2_baselines
    res = rq2_baselines(backend=args.backend, budget=args.budget, external_dir=args.external, log=print,
                        out_dir=args.out)
    return 0 if res else 1


def cmd_ablate(args):
    from tcc.ablation import format_ablation, run_ablation
    res = run_ablation(backend=args.backend, budget=args.budget, levels=args.levels.split(",") if args.levels else None,
                       log=print, out_dir=args.out)
    print(format_ablation(res))
    return 0


def cmd_cache(args):
    from tcc.experiments import rq4_cache
    rq4_cache(backend=args.backend, budget=args.budget, log=print, out_dir=args.out)
    return 0


def cmd_campaign(args):
    from tcc.campaign import campaign
    return campaign(args)


def cmd_experiments(args):
    from tcc.experiments import run_experiments
    run_experiments(only=args.only.split(",") if args.only else None, backend=args.backend, log=print,
                    out_dir=args.out, budget=args.budget)
    return 0


def cmd_metrics(args):
    from tcc.metrics import collect_static, format_metrics
    ps = _programs(args)
    m = collect_static(ps)
    print(format_metrics(m))
    _dump(os.path.join(args.out, "metrics_static.json"), m.as_dict())
    return 0


def cmd_all(args):
    steps = [("selfcheck", cmd_selfcheck), ("analyze", cmd_analyze), ("obligations", cmd_obligations),
             ("plan", cmd_plan), ("metrics", cmd_metrics), ("bench", cmd_bench), ("ablate", cmd_ablate),
             ("cache", cmd_cache), ("baselines", cmd_baselines), ("experiments", cmd_experiments),
             ("run", cmd_run)]
    rc = 0
    for name, fn in steps:
        print(f"\n\n######## {name} ########", flush=True)
        try:
            r = fn(args)
        except SystemExit as e:
            r = int(e.code or 0)
        rc = rc or r
    return rc


def main():
    p = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    sub = p.add_subparsers(dest="cmd", required=True)

    def common(s, out=None):
        s.add_argument("--programs", default=None)
        s.add_argument("--tag", default=None)
        s.add_argument("--from-dir", default=None, help="load reproducer .py files (f + args) as programs")
        s.add_argument("--nnsmith", type=int, default=0, help="also generate N NNSmith models as programs")
        s.add_argument("--opinfo", type=int, default=0, help="also take N PyTorch OpInfo samples as programs")
        s.add_argument("--opinfo-samples", type=int, default=1, help="samples per operator (distinct inputs)")
        s.add_argument("--no-corpus", action="store_true", help="do not add the built-in corpus")
        s.add_argument("--device", default=None, help="move every program's seed inputs to this device (e.g. cuda)")
        s.add_argument("--file", default=None, help="with --from-dir: load only this file")
        s.add_argument("--slice", default=None, help="keep programs [a:b] of the selected list (chunked campaigns)")
        s.add_argument("--isolate", action="store_true",
                       help="campaign: run every program (or chunk) in its own interpreter; a CUDA "
                            "device-side assert or a native crash then costs one program, not the campaign")
        s.add_argument("--no-isolate", action="store_true", help="campaign: never isolate (default: isolate on CUDA)")
        s.add_argument("--chunk-size", type=int, default=25, help="isolated campaign: programs per child for "
                                                                    "corpus/NNSmith/OpInfo selections")
        s.add_argument("--child-timeout", type=int, default=2400, help="isolated campaign: seconds per child")
        s.add_argument("--json", default=None)
        s.add_argument("--backend", default="inductor")
        s.add_argument("--budget", type=int, default=8, help="tests per program for benchmark/ablation")
        s.add_argument("--reruns", type=int, default=1)
        s.add_argument("--only", default=None)
        s.add_argument("--levels", default=None)
        s.add_argument("--external", default=None, help="dir of external-tool generated reproducers")
        s.add_argument("--no-fixed", action="store_true")
        s.add_argument("--historical", default=None, help="bench: run the historical manifest instead")
        s.add_argument("--ir", action="store_true")
        s.add_argument("--yaml", default=None)
        s.add_argument("--max-contexts", type=int, default=12)
        s.add_argument("--out", default=out or RESULTS)
        s.add_argument("--offline", action="store_true")
        s.add_argument("--disk-cache", action="store_true")
        s.add_argument("--seed", type=int, default=0)
        s.add_argument("--keep-info", action="store_true")
        s.add_argument("--minimize", action="store_true")
        s.add_argument("--minimize-budget", type=int, default=16)
        s.add_argument("--test-budget", type=int, default=0)
        s.add_argument("--time-budget", type=float, default=0.0)
        s.add_argument("--layered-only", action="store_true")
        s.add_argument("--matrix-only", action="store_true")
        s.add_argument("--restart", action="store_true")
        s.add_argument("--status", default=None, help="campaign: set <signature>=<Status>")
        s.add_argument("--search-duplicates", action="store_true",
                       help="plan 18.5: query the GitHub tracker for possible duplicates (set GITHUB_TOKEN)")
        s.add_argument("--duplicate-repo", default="pytorch/pytorch")
        s.add_argument("--strict-stride", action="store_true",
                       help="O2: also compare output strides (off by default; compilers may legally change them)")

    for name, fn, out in (("selfcheck", cmd_selfcheck, None), ("list", cmd_list, None),
                          ("analyze", cmd_analyze, None), ("obligations", cmd_obligations, None),
                          ("plan", cmd_plan, None), ("run", cmd_run, REPORTS), ("bench", cmd_bench, None),
                          ("baselines", cmd_baselines, None), ("ablate", cmd_ablate, None),
                          ("cache", cmd_cache, None), ("campaign", cmd_campaign, REPORTS),
                          ("experiments", cmd_experiments, None), ("metrics", cmd_metrics, None),
                          ("all", cmd_all, None)):
        s = sub.add_parser(name)
        common(s, out)
        s.set_defaults(func=fn)
    s = sub.add_parser("mine", help="plan 11 source 2: mine torch.compile reproducers from GitHub issues")
    s.add_argument("--out", default=os.path.join(HERE, "reproducers_gh"))
    s.add_argument("--pages", type=int, default=3)
    s.add_argument("--repo", default="pytorch/pytorch")
    s.add_argument("--allow-cuda", action="store_true", help="keep reproducers that need a GPU")
    s.set_defaults(func=lambda a: (__import__("tcc.mine", fromlist=["mine"]).mine(
        a.out, pages=a.pages, repo=a.repo, log=print, allow_cuda=a.allow_cuda) and 0))
    s = sub.add_parser("sites")
    s.add_argument("path")
    s.add_argument("--json", default=None)
    s.set_defaults(func=cmd_sites)

    args = p.parse_args()
    return args.func(args)


if __name__ == "__main__":
    raise SystemExit(main())
