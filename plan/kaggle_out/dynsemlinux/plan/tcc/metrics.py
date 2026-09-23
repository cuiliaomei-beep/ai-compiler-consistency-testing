"""Plan section 27: efficiency and scalability measurements."""
from __future__ import annotations

import os
import time
import tracemalloc
from dataclasses import dataclass, field
from typing import Any, Dict, List, Optional, Sequence

from .program import Program


@dataclass
class Metrics:
    python_loc: int = 0
    functions_analyzed: int = 0
    compilation_sites: int = 0
    ir_nodes: int = 0
    ir_deps: int = 0
    semantic_factors: int = 0
    scalar_factors: int = 0
    boundaries: int = 0
    index_relations: int = 0
    facts: int = 0
    test_obligations: int = 0
    contexts: int = 0
    sequences: int = 0
    static_analysis_ms: float = 0.0
    test_generation_ms: float = 0.0
    execution_s: float = 0.0
    compile_count: int = 0
    tests_executed: int = 0
    peak_memory_mb: float = 0.0
    per_program: List[Dict[str, Any]] = field(default_factory=list)

    def as_dict(self) -> Dict[str, Any]:
        d = {k: v for k, v in vars(self).items() if k != "per_program"}
        for k in ("static_analysis_ms", "test_generation_ms", "execution_s", "peak_memory_mb"):
            d[k] = round(d[k], 3)
        d["per_program"] = self.per_program
        return d


def _loc(src: Optional[str]) -> int:
    if not src:
        return 0
    return sum(1 for ln in src.splitlines() if ln.strip() and not ln.strip().startswith("#"))


def collect_static(programs: Sequence[Program], opt=None, max_contexts: int = 12) -> Metrics:
    """Phase 1 + 2 cost over a corpus (no execution)."""
    from .generate import build_plan
    from .sites import scan_source

    m = Metrics()
    tracemalloc.start()
    t0 = time.perf_counter()
    for p in programs:
        src = p.get_source() or ""
        m.python_loc += _loc(src)
        m.functions_analyzed += 1
        try:
            m.compilation_sites += len(scan_source(f"import torch\n{src}\ncompiled = torch.compile({p.fn.__name__})\n"))
        except Exception:
            pass
        plan = build_plan(p, opt, max_contexts)
        a = plan.analysis
        m.ir_nodes += len(a.ir.nodes) if a.ir else 0
        m.ir_deps += len(a.ir.deps) if a.ir else 0
        m.semantic_factors += len(a.factors)
        m.scalar_factors += len(a.scalars)
        m.boundaries += len(a.boundaries)
        m.index_relations += len(a.index_relations)
        m.facts += len(a.facts)
        m.test_obligations += len(plan.obligations)
        m.contexts += len(plan.contexts)
        m.sequences += len(plan.sequences)
        m.static_analysis_ms += a.analysis_ms
        m.test_generation_ms += plan.generation_ms
        m.per_program.append({"program": p.name, "loc": _loc(src), "ir_nodes": len(a.ir.nodes) if a.ir else 0,
                              "factors": len(a.factors), "scalars": len(a.scalars),
                              "boundaries": len(a.boundaries), "facts": len(a.facts),
                              "obligations": len(plan.obligations), "contexts": len(plan.contexts),
                              "sequences": len(plan.sequences), "analysis_ms": round(a.analysis_ms, 3),
                              "generation_ms": round(plan.generation_ms, 3)})
    _, peak = tracemalloc.get_traced_memory()
    tracemalloc.stop()
    m.peak_memory_mb = peak / 1e6
    m.execution_s = time.perf_counter() - t0
    return m


def process_peak_mb() -> Optional[float]:
    try:
        import psutil  # type: ignore
        return psutil.Process(os.getpid()).memory_info().peak_wset / 1e6  # type: ignore[attr-defined]
    except Exception:
        try:
            import resource  # type: ignore
            return resource.getrusage(resource.RUSAGE_SELF).ru_maxrss / 1024.0
        except Exception:
            return None


def format_metrics(m: Metrics) -> str:
    L = ["  Efficiency (plan section 27)"]
    for k, v in m.as_dict().items():
        if k == "per_program":
            continue
        L.append(f"    {k:<22}: {v}")
    return "\n".join(L)
