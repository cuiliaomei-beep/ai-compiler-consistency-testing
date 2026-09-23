"""Plan section 27: efficiency and scalability.

The plan asks for one table::

    Python LOC   functions analyzed   compilation sites   CFG nodes
    semantic factors   test obligations
    static-analysis time   test-generation time   execution time
    compile count   peak memory

split into a *static* half (what Phase 1 costs on a body of code) and a
*dynamic* half (what Phase 2/3 cost to run the resulting tests). They are
measured separately because they scale with different things: the static
half with source size, the dynamic half with the number of contexts and the
compiler's own speed.

"CFG nodes" is reported as IR nodes from :mod:`tcd.ir`: the plan's IR is a
statement-level dependency graph, and that is the structure Phase 1 walks.
"""
from __future__ import annotations

import os
import time
from dataclasses import asdict, dataclass, field
from typing import Any, Dict, List, Optional, Sequence

from .case import Case


@dataclass
class StaticMetrics:
    python_loc: int = 0
    files: int = 0
    functions_analyzed: int = 0
    compilation_sites: int = 0
    ir_nodes: int = 0
    ir_deps: int = 0
    semantic_factors: int = 0
    boundaries: int = 0
    index_relations: int = 0
    facts: int = 0
    test_obligations: int = 0
    contexts_generated: int = 0
    site_scan_s: float = 0.0
    static_analysis_s: float = 0.0
    test_generation_s: float = 0.0

    def as_dict(self) -> Dict[str, Any]:
        d = asdict(self)
        for k in ("site_scan_s", "static_analysis_s", "test_generation_s"):
            d[k] = round(d[k], 4)
        return d


@dataclass
class DynamicMetrics:
    cases: int = 0
    contexts: int = 0
    executions: int = 0
    compile_count: int = 0
    execution_s: float = 0.0
    compile_s: float = 0.0
    peak_memory_mb: Optional[float] = None
    backend: str = ""

    def as_dict(self) -> Dict[str, Any]:
        d = asdict(self)
        d["execution_s"] = round(d["execution_s"], 2)
        d["compile_s"] = round(d["compile_s"], 2)
        if d["peak_memory_mb"] is not None:
            d["peak_memory_mb"] = round(d["peak_memory_mb"], 1)
        return d


# --------------------------------------------------------------------------
# peak memory, portably
# --------------------------------------------------------------------------

def peak_memory_mb() -> Optional[float]:
    """Peak resident set of this process, in MB, or None if unreadable.

    ``tracemalloc`` would only see Python allocations; tensor storage lives in
    C++ and the compiler's subprocesses, so the OS's own counter is the one
    that means anything.
    """
    try:
        import psutil  # type: ignore
        mi = psutil.Process().memory_info()
        peak = getattr(mi, "peak_wset", None) or getattr(mi, "rss", None)
        return float(peak) / 1e6 if peak else None
    except Exception:
        pass
    if os.name == "nt":
        try:
            import ctypes
            from ctypes import wintypes

            class PMC(ctypes.Structure):
                _fields_ = [("cb", wintypes.DWORD), ("PageFaultCount", wintypes.DWORD),
                            ("PeakWorkingSetSize", ctypes.c_size_t),
                            ("WorkingSetSize", ctypes.c_size_t),
                            ("QuotaPeakPagedPoolUsage", ctypes.c_size_t),
                            ("QuotaPagedPoolUsage", ctypes.c_size_t),
                            ("QuotaPeakNonPagedPoolUsage", ctypes.c_size_t),
                            ("QuotaNonPagedPoolUsage", ctypes.c_size_t),
                            ("PagefileUsage", ctypes.c_size_t),
                            ("PeakPagefileUsage", ctypes.c_size_t)]
            pmc = PMC()
            pmc.cb = ctypes.sizeof(PMC)
            h = ctypes.windll.kernel32.GetCurrentProcess()
            if ctypes.windll.psapi.GetProcessMemoryInfo(h, ctypes.byref(pmc), pmc.cb):
                return pmc.PeakWorkingSetSize / 1e6
        except Exception:
            return None
    try:
        import resource
        ru = resource.getrusage(resource.RUSAGE_SELF).ru_maxrss
        return float(ru) / 1e3  # KB on Linux
    except Exception:
        return None


# --------------------------------------------------------------------------
# static half
# --------------------------------------------------------------------------

def _loc(path: str) -> int:
    try:
        with open(path, "r", encoding="utf-8", errors="replace") as fh:
            return sum(1 for line in fh if line.strip() and not line.lstrip().startswith("#"))
    except OSError:
        return 0


def measure_static_path(path: str) -> StaticMetrics:
    """Phase 1 over every compilation site under ``path``."""
    from .analysis import analyze_source
    from .ir import build_ir
    from .obligation import derive_obligations, derive_scs, obligations_to_contexts
    from .sites import iter_py_files, scan_file, site_source

    m = StaticMetrics()
    t0 = time.perf_counter()
    sites = []
    for f in iter_py_files(path):
        m.files += 1
        m.python_loc += _loc(f)
        sites.extend(scan_file(f))
    m.site_scan_s = time.perf_counter() - t0
    m.compilation_sites = len(sites)

    seen = set()
    for s in sites:
        key = (s.file, s.target)
        if key in seen:
            continue
        seen.add(key)
        src = site_source(s)
        if not src:
            continue
        t1 = time.perf_counter()
        a = analyze_source(src, s.target or "<fn>")
        ir = build_ir(src, s.target or "<fn>")
        m.static_analysis_s += time.perf_counter() - t1
        if a.error:
            continue
        m.functions_analyzed += 1
        m.ir_nodes += len(ir.nodes)
        m.ir_deps += len(ir.deps)
        m.semantic_factors += len(a.factors) + len(a.flags)
        m.boundaries += len(a.boundaries)
        m.index_relations += len(a.index_relations)
        m.facts += len(a.facts)
        t2 = time.perf_counter()
        scs = derive_scs(a)
        obl = derive_obligations(a, scs)
        ctxs = obligations_to_contexts(obl, a.params)
        m.test_generation_s += time.perf_counter() - t2
        m.test_obligations += len(obl)
        m.contexts_generated += len(ctxs)
    return m


def measure_static_cases(cases: Sequence[Case]) -> StaticMetrics:
    """Phase 1 over cases that carry source (chains, modules, seeds)."""
    import inspect

    from .analysis import analyze_source
    from .ir import build_ir
    from .obligation import derive_obligations, derive_scs, obligations_to_contexts

    m = StaticMetrics()
    for c in cases:
        src = c.source
        if not src:
            try:
                src = inspect.getsource(c.fn)
            except (OSError, TypeError):
                continue
        m.python_loc += sum(1 for line in src.splitlines() if line.strip())
        t1 = time.perf_counter()
        a = analyze_source(src, c.name)
        ir = build_ir(src, c.name)
        m.static_analysis_s += time.perf_counter() - t1
        if a.error:
            continue
        m.functions_analyzed += 1
        m.ir_nodes += len(ir.nodes)
        m.ir_deps += len(ir.deps)
        m.semantic_factors += len(a.factors) + len(a.flags)
        m.boundaries += len(a.boundaries)
        m.index_relations += len(a.index_relations)
        m.facts += len(a.facts)
        t2 = time.perf_counter()
        scs = derive_scs(a)
        obl = derive_obligations(a, scs)
        ctxs = obligations_to_contexts(obl, a.params)
        m.test_generation_s += time.perf_counter() - t2
        m.test_obligations += len(obl)
        m.contexts_generated += len(ctxs)
    return m


# --------------------------------------------------------------------------
# dynamic half
# --------------------------------------------------------------------------

def measure_dynamic(cases: Sequence[Case], backend: str = "aot_eager",
                    budget: int = 4, seed: int = 0) -> DynamicMetrics:
    """Cold-compile every context of every case, counting compiles and time."""
    from .execution import run_cold, run_eager
    from .runner import RunOptions, valid_contexts

    m = DynamicMetrics(backend=backend)
    opts = RunOptions(backend=backend, reruns=0, seed=seed)
    t0 = time.perf_counter()
    for c in cases:
        ctxs = valid_contexts(c, opts)[:budget]
        if not ctxs:
            continue
        m.cases += 1
        for ctx in ctxs:
            m.contexts += 1
            try:
                run_eager(c, ctx, seed)
                m.executions += 1
                t1 = time.perf_counter()
                obs = run_cold(c, ctx, backend=backend, seed=seed)
                m.compile_s += time.perf_counter() - t1
                m.executions += 1
                m.compile_count += obs.compiles
            except Exception:
                continue
    m.execution_s = time.perf_counter() - t0
    m.peak_memory_mb = peak_memory_mb()
    return m


def format_metrics(static: Optional[StaticMetrics],
                   dynamic: Optional[DynamicMetrics]) -> str:
    L: List[str] = []
    if static is not None:
        L.append("  static (Phase 1)")
        for k, v in static.as_dict().items():
            L.append(f"    {k:<22} {v}")
    if dynamic is not None:
        L.append("  dynamic (Phase 2/3)")
        for k, v in dynamic.as_dict().items():
            L.append(f"    {k:<22} {v}")
    return "\n".join(L)
