"""RQ1: detection effectiveness on a ground-truth benchmark (plan sections 21, 25).

Two sources of ground truth:

* **Injected faults** (``tcc.faults``): every fault is one known consistency
  defect with a known trigger and a known oracle. "Buggy version" = the
  fault, "fixed version" = the real compiler. Recall per category and false
  positives on the fixed version come out of the same loop.
* **Historical bugs** (``benchmark/historical_bugs.json``): entries with a
  Python reproducer, a buggy and a fixed version, and the expected semantic
  factor. They run on whatever PyTorch is installed; an entry's expected
  outcome is therefore "detected" only if the installed version is the buggy
  one. The loader records which case applies rather than guessing.
"""
from __future__ import annotations

import json
import os
import time
from dataclasses import dataclass, field
from typing import Any, Callable, Dict, List, Optional, Sequence

from .execute import E0_EAGER, E1_DYNAMO, E3_INDUCTOR
from .faults import FAULTS, Fault, FaultyCompiler
from .oracle import Config
from .program import Program, get
from .runner import RunOptions, RunResult, run_program
from .scs import DeriveOptions

DEFAULT_PROGRAMS = ["dtype_reduce", "shape_boundary", "python_flag_semantic"]
_LAYOUT_PROGRAMS = ["stride_read", "contiguous_read", "view_inplace", "noncontig_copy"]


def programs_for(fault: Fault) -> List[str]:
    if fault.programs:
        return fault.programs
    if fault.trigger_factor == "layout":
        return _LAYOUT_PROGRAMS
    return DEFAULT_PROGRAMS


@dataclass
class Entry:
    fault: str
    program: str
    category: str
    defect_class: str
    detected: bool = False
    stage: Optional[str] = None
    kinds: List[str] = field(default_factory=list)
    tests_executed: int = 0
    tests_to_detect: Optional[int] = None
    ttf_s: Optional[float] = None
    invalid: int = 0
    compiles: int = 0
    wall_s: float = 0.0
    error: Optional[str] = None
    probe: Optional[str] = None
    warm_only: bool = False

    def as_dict(self) -> Dict[str, Any]:
        return dict(vars(self))


def bench_options(fault: Optional[Fault], backend: str, budget: int, reruns: int,
                  derive: Optional[DeriveOptions] = None, plan_builder=None, oracles=None,
                  level: str = "FULL", stop_at_first: bool = True, do_matrix: bool = True,
                  do_layered: bool = True, max_contexts: int = 12) -> RunOptions:
    """Run options with the fault injected at E3 and used by the matrix probe."""
    factory = (lambda: FaultyCompiler(fault, backend)) if fault else None
    from .execute import TorchCompiler
    real = lambda: TorchCompiler(backend)  # noqa: E731
    return RunOptions(
        backend=backend, reruns=reruns, seed=0, derive=derive or DeriveOptions(), level=level,
        layers=[(E0_EAGER, None), (E1_DYNAMO, "eager"), (E3_INDUCTOR, backend)],
        compiler_factory=factory or real, inject_layer=E3_INDUCTOR, plan_builder=plan_builder,
        oracles=oracles, test_budget=budget, stop_at_first=stop_at_first, do_matrix=do_matrix,
        do_layered=do_layered, fault_id=fault.id if fault else None, max_contexts=max_contexts)


def run_entry(fault: Optional[Fault], program: Program, opts: RunOptions,
              out_dir: Optional[str] = None) -> Entry:
    e = Entry(fault.id if fault else "none", program.name,
              fault.category if fault else "-", fault.defect_class if fault else "-")
    r: RunResult = run_program(program, opts, Config())
    e.tests_executed, e.invalid, e.compiles, e.wall_s = r.tests_executed, r.tests_invalid, r.compile_count, r.wall_s
    e.error = r.error
    fails = r.failures
    if fails:
        e.detected = True
        e.stage = fails[0].triage.stage
        e.kinds = list(fails[0].triage.kinds)
        e.probe = fails[0].probe
        e.warm_only = bool(fails[0].triage.warm_only)
        e.tests_to_detect = r.first_failure_test
        e.ttf_s = r.ttf_s
        if out_dir:
            from .report import write_report
            for rec in fails:
                write_report(os.path.join(out_dir, "bench_reports"), rec)
    return e


def run_benchmark(backend: str = "eager", budget: int = 8, reruns: int = 0, only: Optional[str] = None,
                  check_fixed: bool = True, log: Callable[[str], None] = print,
                  out_dir: Optional[str] = None, derive: Optional[DeriveOptions] = None,
                  plan_builder=None, oracles=None, level: str = "FULL", do_matrix: bool = True,
                  faults: Optional[Sequence[Fault]] = None, max_contexts: int = 12) -> Dict[str, Any]:
    from . import corpus  # noqa: F401
    faults = list(faults or FAULTS)
    if only:
        wanted = {s.strip() for s in only.split(",")}
        faults = [f for f in faults if f.id in wanted or f.category in wanted]
    t0 = time.perf_counter()
    entries: List[Entry] = []
    log(f"\nRQ1 benchmark: {len(faults)} injected fault(s), backend={backend}, budget={budget} tests/program, "
        f"level={level}")
    log("=" * 76)
    for f in faults:
        for pname in programs_for(f):
            try:
                p = get(pname)
            except KeyError:
                continue
            opts = bench_options(f, backend, budget, reruns, derive, plan_builder, oracles, level,
                                 do_matrix=do_matrix, max_contexts=max_contexts)
            e = run_entry(f, p, opts, out_dir)
            entries.append(e)
            log(f"  {f.id:<30} {pname:<22} {'DETECTED' if e.detected else 'missed  '} "
                f"tests={e.tests_executed:<3} ttd={e.tests_to_detect if e.tests_to_detect is not None else '-':<3} "
                f"stage={e.stage or '-':<22} {e.wall_s:.1f}s" + (f" ERROR {e.error}" if e.error else ""))

    fixed: List[Entry] = []
    if check_fixed:
        log("\n  fixed versions (real compiler; every failure here is a false positive)")
        seen = set()
        for f in faults:
            for pname in programs_for(f):
                if pname in seen:
                    continue
                seen.add(pname)
                try:
                    p = get(pname)
                except KeyError:
                    continue
                opts = bench_options(None, backend, budget, max(reruns, 1), derive, plan_builder, oracles, level,
                                     stop_at_first=False, do_matrix=do_matrix, max_contexts=max_contexts)
                e = run_entry(None, p, opts, out_dir)
                fixed.append(e)
                log(f"  fixed {pname:<22} {'FALSE POSITIVE' if e.detected else 'clean'} tests={e.tests_executed} "
                    f"{e.stage or ''} {e.kinds or ''}")
    return summarize(entries, fixed, faults, backend, budget, level, time.perf_counter() - t0)


def summarize(entries: List[Entry], fixed: List[Entry], faults: Sequence[Fault], backend: str,
              budget: int, level: str, wall: float) -> Dict[str, Any]:
    by_fault: Dict[str, List[Entry]] = {}
    for e in entries:
        by_fault.setdefault(e.fault, []).append(e)
    detected = {fid: any(x.detected for x in es) for fid, es in by_fault.items()}
    cats: Dict[str, Dict[str, int]] = {}
    classes: Dict[str, Dict[str, int]] = {}
    for f in faults:
        c = cats.setdefault(f.category, {"total": 0, "detected": 0})
        c["total"] += 1
        c["detected"] += int(detected.get(f.id, False))
        k = classes.setdefault(f.defect_class, {"total": 0, "detected": 0})
        k["total"] += 1
        k["detected"] += int(detected.get(f.id, False))
    n_det = sum(detected.values())
    ttd = [e.tests_to_detect for e in entries if e.tests_to_detect is not None]
    ttf = [e.ttf_s for e in entries if e.ttf_s is not None]
    return {
        "backend": backend, "budget": budget, "level": level, "wall_s": round(wall, 1),
        "faults": len(faults), "detected": n_det,
        "recall": round(n_det / max(1, len(faults)), 3),
        "per_category": cats, "per_defect_class": classes,
        "false_positives_on_fixed": sum(1 for e in fixed if e.detected),
        "fixed_programs": len(fixed),
        "mean_tests_to_detect": round(sum(ttd) / len(ttd), 2) if ttd else None,
        "mean_ttf_s": round(sum(ttf) / len(ttf), 2) if ttf else None,
        "tests_executed": sum(e.tests_executed for e in entries),
        "tests_invalid": sum(e.invalid for e in entries),
        "compiles": sum(e.compiles for e in entries),
        "warm_only_detections": sum(1 for e in entries if e.detected and e.warm_only),
        "entries": [e.as_dict() for e in entries],
        "fixed": [e.as_dict() for e in fixed],
        "detected_by_fault": detected,
    }


def format_benchmark(res: Dict[str, Any]) -> str:
    L = ["", f"RQ1 summary (level {res['level']}, backend {res['backend']}, budget {res['budget']})",
         f"  detected {res['detected']}/{res['faults']} injected faults (recall {res['recall']})",
         f"  false positives on fixed versions: {res['false_positives_on_fixed']}/{res['fixed_programs']} programs",
         f"  mean tests-to-detect {res['mean_tests_to_detect']}, mean TTF {res['mean_ttf_s']}s, "
         f"tests {res['tests_executed']}, invalid {res['tests_invalid']}, compiles {res['compiles']}",
         "", "  per category:"]
    for c, v in res["per_category"].items():
        L.append(f"    {c:<16} {v['detected']}/{v['total']}")
    L.append("  per defect class:")
    for c, v in res["per_defect_class"].items():
        L.append(f"    {c:<36} {v['detected']}/{v['total']}")
    missed = [k for k, v in res["detected_by_fault"].items() if not v]
    if missed:
        L.append(f"  missed: {', '.join(missed)}")
    return "\n".join(L)


# --------------------------------------------------------------------------
# historical benchmark (plan section 21)
# --------------------------------------------------------------------------

HISTORICAL_SCHEMA = ["BugID", "Project", "BuggyVersion", "FixedVersion", "PythonEntry", "SemanticFactor",
                     "ExpectedBehavior", "ActualBehavior", "CompilerStage", "OriginalIssue"]


def load_historical(path: str) -> List[Dict[str, Any]]:
    if not os.path.exists(path):
        return []
    with open(path, encoding="utf-8") as fh:
        data = json.load(fh)
    return [d for d in data.get("entries", []) if all(k in d for k in HISTORICAL_SCHEMA)]


def run_historical(path: str, backend: str = "inductor", budget: int = 8, log=print) -> Dict[str, Any]:
    """Run every historical entry whose reproducer file exists next to the manifest."""
    from .compat import environment
    from .seeds import load_reproducer
    env = environment()
    entries = load_historical(path)
    base = os.path.dirname(path)
    out = []
    for e in entries:
        repro = os.path.join(base, e["PythonEntry"])
        p, why = load_reproducer(repro)
        row = {"BugID": e["BugID"], "installed": env["torch"], "BuggyVersion": e["BuggyVersion"],
               "FixedVersion": e["FixedVersion"], "expected": "detect" if env["torch"] and
               str(env["torch"]).startswith(str(e["BuggyVersion"])) else "no-detect (fixed or unknown version)"}
        if p is None:
            row["result"] = f"skipped: {why}"
            out.append(row)
            log(f"  {e['BugID']}: {row['result']}")
            continue
        opts = RunOptions(backend=backend, test_budget=budget, reruns=1)
        r = run_program(p, opts, Config())
        row["detected"] = bool(r.failures)
        row["stages"] = sorted({x.triage.stage for x in r.failures})
        row["tests"] = r.tests_executed
        out.append(row)
        log(f"  {e['BugID']}: {'DETECTED' if row['detected'] else 'not detected'} ({row['expected']})")
    return {"manifest": path, "entries": out, "torch": env["torch"]}
