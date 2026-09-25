"""P11-1 Setting B: TorchProbe-generated programs judged by our harness against the injected faults.

Loads the mutated programs that the bounded TorchProbe driver (scratchpad/p11/run_temisu.py) saved
(``<name>.py`` = the rendered ``forward(mlist, ...)`` source, ``<name>.pt`` = (module list, inputs)),
wraps each as a :class:`tcc.program.Program` exactly as ``tcc.baselines.nnsmith_programs`` wraps NNSmith
models, and runs ``tcc.experiments._external_bench(native=True)``: one context (the tool's own input),
cold eager-vs-compiled, all oracles, every injected fault. This is the same leg as ``B3_nnsmith_native``.

    python scripts/p11_torchprobe_setting_b.py --programs <dir> --temisu <clone> --out results/p11_baselines
"""
from __future__ import annotations

import argparse
import glob
import json
import os
import sys
import time
import warnings

warnings.filterwarnings("ignore")
sys.path.insert(0, os.path.dirname(os.path.dirname(os.path.abspath(__file__))))


def load_programs(directory: str, only_mutations=None, max_programs: int = 0, only_valid_from=None,
                  first_program: int = 0):
    import torch
    from tcc.program import Program, Context
    valid = None
    if only_valid_from and os.path.exists(only_valid_from):
        valid = set()
        with open(only_valid_from, encoding="utf-8") as fh:
            for line in fh:
                d = json.loads(line)
                if d.get("status") in ("pass", "inductor_unavailable") or d.get("eager_valid") is True:
                    if "k" in d:
                        valid.add(f"seed{d['seed']}_k{d['k']}_{d['mutation']}")
    out, rejected = [], []
    files = []
    for py in sorted(glob.glob(os.path.join(directory, "*.py")), key=lambda q: (int(os.path.basename(q).split("_")[0][4:]), q)):
        mutation = os.path.splitext(os.path.basename(py))[0].split("_", 2)[2]
        if only_mutations and mutation not in only_mutations:
            continue
        files.append(py)
    for py in files[first_program:]:
        name = os.path.splitext(os.path.basename(py))[0]
        mutation = name.split("_", 2)[2]
        if valid is not None and name not in valid:
            rejected.append((name, "not eager-valid in the TorchProbe run"))
            continue
        pt = py[:-3] + ".pt"
        if not os.path.exists(pt):
            rejected.append((name, "no .pt"))
            continue
        try:
            mlist, inputs = torch.load(pt, weights_only=False)
        except Exception as e:  # noqa: BLE001
            rejected.append((name, f"torch.load: {type(e).__name__}: {str(e)[:80]}"))
            continue
        src = open(py, encoding="utf-8").read()
        ns = {"torch": torch}
        try:
            exec(compile(src, py, "exec"), ns)  # noqa: S102 - our own generated code
        except Exception as e:  # noqa: BLE001
            rejected.append((name, f"exec: {type(e).__name__}: {str(e)[:80]}"))
            continue
        forward = ns["forward"]
        import inspect
        params = list(inspect.signature(forward).parameters)[1:]
        frozen = tuple(inputs[p].clone() for p in params)

        def fn(*args, _f=forward, _m=mlist):
            return _f(_m, *args)
        fn.__name__ = name

        def make_inputs(ctx: Context, _fr=frozen):
            return tuple(t.clone() for t in _fr)

        out.append(Program(name=name, fn=fn, make_inputs=make_inputs, tags=["torchprobe", "external", mutation],
                           notes=f"TorchProbe mutation {mutation}; inputs {[tuple(t.shape) for t in frozen]}",
                           source=src, check_grad=False, project="torchprobe"))
        if max_programs and len(out) >= max_programs:
            break
    return out, rejected


def external_bench_native(programs, backend: str, budget: int, report_dir=None):
    """Same loop as tcc.experiments._external_bench(native=True), but keeps summarize()'s per-fault
    and per-entry detail (the original returns only the _agg() aggregate)."""
    from tcc.ablation import OUTPUT_ONLY
    from tcc.benchmark import bench_options, run_entry, summarize
    from tcc.experiments import _agg
    from tcc.factors import analyze
    from tcc.faults import FAULTS
    from tcc.generate import TestPlan
    from tcc.scs import SCS

    def single(program):
        a = analyze(program.fn, program.get_source())
        return TestPlan(program.name, a, SCS(site=a.function, params=a.params), [], [program.base_context],
                        [], [], list(OUTPUT_ONLY) + ["mutation", "alias", "gradient"], level="native")

    # fixed-version pass (as run_benchmark(check_fixed=True) does for the corpus): a program that already
    # fails on the unmodified compiler cannot serve as a detector; it is set aside and reported separately
    fixed = []
    clean = []
    for p in programs:
        opts = bench_options(None, backend, 1, 1, None, single, None, "native", stop_at_first=False,
                             do_matrix=False, max_contexts=budget)
        opts.time_budget_s = 0.0
        e = run_entry(None, p, opts, report_dir)
        fixed.append(e)
        if not e.detected:
            clean.append(p)
    entries = []
    for f in FAULTS:
        for p in clean:
            opts = bench_options(f, backend, 1, 0, None, single, None, "native", do_matrix=False, max_contexts=budget)
            opts.time_budget_s = 0.0
            entries.append(run_entry(f, p, opts))
    res = summarize(entries, fixed, FAULTS, backend, budget, "native", 0.0)
    agg = _agg([res])
    agg["detected_by_fault"] = res["detected_by_fault"]
    agg["entries"] = res["entries"]
    agg["fixed"] = res["fixed"]
    agg["programs"] = [p.name for p in programs]
    agg["programs_failing_on_real_compiler"] = [e.program for e in fixed if e.detected]
    agg["programs_used_as_detectors"] = [p.name for p in clean]
    return agg


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--programs", required=True)
    ap.add_argument("--temisu", required=True, help="path of the temisu clone (for unpickling TConstFn)")
    ap.add_argument("--tests-jsonl", default=None, help="tests.jsonl of the TorchProbe run; keeps eager-valid programs only")
    ap.add_argument("--mutations", default=None, help="comma list, e.g. origin,subfunction")
    ap.add_argument("--max-programs", type=int, default=0)
    ap.add_argument("--first-program", type=int, default=0, help="skip this many (sorted by seed) programs")
    ap.add_argument("--budget", type=int, default=12)
    ap.add_argument("--backend", default="eager")
    ap.add_argument("--tag", default="all")
    ap.add_argument("--report-dir", default=None, help="write failure reports of the fixed-version pass here")
    ap.add_argument("--out", default="results/p11_baselines")
    args = ap.parse_args()
    sys.path.insert(0, args.temisu)
    from tcc.compat import ensure_msvc_env
    ensure_msvc_env()
    from tcc import corpus  # noqa: F401
    muts = args.mutations.split(",") if args.mutations else None
    ps, rej = load_programs(args.programs, muts, args.max_programs, args.tests_jsonl, args.first_program)
    print(f"{len(ps)} TorchProbe program(s) loaded, {len(rej)} rejected", flush=True)
    for r in rej[:10]:
        print("  rejected", r)
    if not ps:
        return 1
    t0 = time.perf_counter()
    res = external_bench_native(ps, args.backend, args.budget, args.report_dir)
    res["wall_s"] = round(time.perf_counter() - t0, 1)
    res["rejected"] = rej
    res["n_programs"] = len(ps)
    res["programs"] = [p.name for p in ps]
    os.makedirs(args.out, exist_ok=True)
    with open(os.path.join(args.out, f"torchprobe_setting_b_{args.tag}.json"), "w", encoding="utf-8") as fh:
        json.dump(res, fh, indent=1, default=str)
    print(f"TorchProbe(native input, {len(ps)} programs) detected {res['detected']}/{res['faults']} "
          f"tests {res['tests_executed']} invalid {res['tests_invalid']} TTF {res['mean_ttf_s']} wall {res['wall_s']}s; "
          f"{len(res['programs_used_as_detectors'])} of {res['n_programs']} programs clean on the real compiler")
    print("per category:", res["per_category"])
    print("detected:", [k for k, v in res["detected_by_fault"].items() if v])
    print("programs failing on the real compiler (excluded):", res["programs_failing_on_real_compiler"])
    for e in res["fixed"]:
        if e["detected"]:
            print("   ", e["program"], e["stage"], e["kinds"], e["probe"])
    return 0


if __name__ == "__main__":
    sys.exit(main())
