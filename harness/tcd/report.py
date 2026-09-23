"""Failure records and developer-facing issue drafts.

The drafts here are **drafts**. Nothing is filed automatically: every report is
read by a person before it reaches a tracker. What the harness contributes is
the part that is tedious and error-prone by hand — the environment block, the
controlled-vs-changed factor list, the cold/warm evidence table, and the stage
attribution — so the human time goes into judging the bug rather than
assembling the paperwork.
"""
from __future__ import annotations

import json
import os
from dataclasses import dataclass, field
from typing import Any, Dict, List, Optional

from .oracle import Comparison
from .torchcompat import environment
from .triage import Triage


@dataclass
class FailureRecord:
    signature: str
    case: str
    triage: Triage
    #: "layered" (D1: eager vs compiled) or "warm" (D2: cold vs warm)
    probe: str
    context: Dict[str, Any] = field(default_factory=dict)
    context_b: Optional[Dict[str, Any]] = None
    factor_changed: str = ""
    comparisons: Dict[str, Comparison] = field(default_factory=dict)
    observations: Dict[str, Any] = field(default_factory=dict)
    fp64_available: bool = False
    reruns_agreeing: int = 0
    reruns_total: int = 0
    env: Dict[str, Any] = field(default_factory=environment)
    notes: str = ""
    #: result of plan 17.2 minimization, when it was run
    minimized: Optional[Dict[str, Any]] = None
    #: standalone script a maintainer can paste and run
    reproducer: Optional[str] = None
    #: plan 18.5 duplicate search result, when it was run
    duplicates: Optional[Dict[str, Any]] = None
    #: plan 18.1 step 8: anything still looking sensitive after sanitising
    sanitize_warnings: List[str] = field(default_factory=list)

    def as_dict(self) -> Dict[str, Any]:
        return {
            "signature": self.signature,
            "case": self.case,
            "probe": self.probe,
            "triage": self.triage.as_dict(),
            "context": self.context,
            "context_b": self.context_b,
            "factor_changed": self.factor_changed,
            "fp64_available": self.fp64_available,
            "reproducibility": f"{self.reruns_agreeing}/{self.reruns_total}",
            "comparisons": {k: v.as_dict() for k, v in self.comparisons.items()},
            "observations": self.observations,
            "environment": self.env,
            "notes": self.notes,
            "minimized": self.minimized,
            "duplicates": self.duplicates,
            "sanitize_warnings": self.sanitize_warnings,
        }


_STAGE_HINT = {
    "dynamo_capture": "TorchDynamo (graph capture)",
    "aot_functionalization": "AOTAutograd / functionalization",
    "inductor_codegen": "TorchInductor (lowering / codegen)",
    "specialization_cache": "guard / specialization / compiled-artifact cache",
    "compile_nondeterminism": "compilation state leaking across compiles",
}


_EV_LABEL = {
    "shape": "shape", "dtype": "dtype", "actual_shape": "actual shape",
    "n_mismatch": "mismatching elements", "n_total": "total elements",
    "max_abs_error": "max absolute error", "max_rel_error": "max relative error",
    "first_mismatch_index": "first mismatch at index",
    "eager_err_vs_fp64": "eager error vs float64",
    "compiled_err_vs_fp64": "compiled error vs float64",
    "budget": "accepted budget",
}


def _evidence_block(ev: dict) -> List[str]:
    """Render the concrete expected/actual evidence a maintainer needs."""
    if not ev:
        return []
    lines = ["", "    ```"]
    for k in ("shape", "dtype", "actual_shape", "n_mismatch", "n_total",
              "max_abs_error", "max_rel_error", "first_mismatch_index",
              "eager_err_vs_fp64", "compiled_err_vs_fp64", "budget"):
        if k in ev:
            lines.append(f"    {_EV_LABEL[k]:<26}: {ev[k]}")
    if "first_mismatch_expected" in ev:
        lines.append(f"    {'expected at that index':<26}: {ev['first_mismatch_expected']}")
        lines.append(f"    {'actual at that index':<26}: {ev['first_mismatch_actual']}")
    if "expected_preview" in ev:
        lines.append(f"    {'expected':<26}: {ev['expected_preview']}")
        lines.append(f"    {'actual':<26}: {ev['actual_preview']}")
    if "evidence_error" in ev:
        lines.append(f"    (evidence unavailable: {ev['evidence_error']})")
    lines.append("    ```")
    return lines


def _findings_block(rec: FailureRecord) -> str:
    lines: List[str] = []
    for name, cmp in rec.comparisons.items():
        if not cmp.differs:
            continue
        lines.append(f"- **{cmp.ref_mode} vs {cmp.test_mode}**")
        for f in cmp.findings:
            lines.append(f"  - `{f.kind}` {f.detail}")
            lines.extend(_evidence_block(getattr(f, "evidence", {}) or {}))
        if cmp.opaque_outputs:
            lines.append(f"  - _(outputs {cmp.opaque_outputs} could not be compared: "
                         f"not tensors or scalars)_")
    return "\n".join(lines) if lines else "- (no findings recorded)"


def render_issue(rec: FailureRecord, repro_src: Optional[str] = None) -> str:
    """Render a developer-ready issue draft. Review before filing."""
    env = rec.env
    t = rec.triage
    changed = rec.factor_changed or "; ".join(
        f"{k}={v}" for k, v in (rec.context.get("factors") or {}).items()
    )
    title_what = "compiled execution differs from eager"
    if rec.probe == "warm":
        title_what = "warm-cache result differs from a cold compile"

    controlled = []
    fa = (rec.context.get("factors") or {})
    fb = (rec.context_b or {}).get("factors") or {}
    for k in sorted(set(fa) | set(fb)):
        if k != rec.factor_changed:
            controlled.append(f"{k}: unchanged ({fa.get(k)})")

    warm_rows = ""
    if rec.probe == "warm":
        recompiled = t.recompiled
        warm_rows = (
            "\n## Cache / specialization evidence\n\n"
            "| execution | result |\n|---|---|\n"
            "| eager(B) | reference |\n"
            "| compiled cold(B) | matches reference |\n"
            "| compiled A then B (warm) | **differs** |\n"
            f"| recompile triggered by the switch | {'yes' if recompiled else '**no**'} |\n"
        )

    return f"""# [{_STAGE_HINT.get(t.stage, t.stage)}] {title_what} when `{changed}` changes

<!-- DRAFT generated by the consistency harness. Review every section before filing. -->

## Summary

{t.rationale}

Signature `{rec.signature}` · case `{rec.case}` · probe `{rec.probe}`.

## Environment

- Python: {env.get('python')}
- PyTorch: {env.get('torch')} ({env.get('torch_git')})
- CUDA: {env.get('cuda')}
- Device: {env.get('device_name')}
- Triton: {env.get('triton')}
- Platform: {env.get('platform')}

## Minimal reproducer

```python
{repro_src or '# see repro.py next to this file'}
```

## Expected vs actual

{_findings_block(rec)}

## Trigger condition

Changed factor:

```
{rec.factor_changed or '(single context)'}
```

Controlled factors:

```
{chr(10).join(controlled) if controlled else '(none recorded)'}
```
{warm_rows}
## Suspected stage

```
{_STAGE_HINT.get(t.stage, t.stage)}
```

Attribution basis: {t.rationale}

## Accuracy methodology

{'A float64 reference was computed; the compiled result was flagged only because its error against that reference exceeded the eager error by more than the configured multiplier.' if rec.fp64_available else 'No float64 reference could be built for this case, so a plain tolerance was used. Treat the numeric claim with corresponding caution.'}

## Reproducibility

```
Reproduced {rec.reruns_agreeing}/{rec.reruns_total} runs with a fixed seed.
```
{_minimization_section(rec)}{_dup_section(rec)}{_sanitize_section(rec)}"""


def _minimization_section(rec: FailureRecord) -> str:
    m = rec.minimized
    if not m:
        return ("\n## Minimization\n\n_Not minimized. Run with `--minimize` "
                "before filing._\n")
    if not m.get("reproduces"):
        return ("\n## Minimization\n\n_Minimization did not run: "
                f"{m.get('error') or 'the failure did not reproduce on re-probe'}._\n")
    return (f"\n## Minimization\n\n"
            f"Program {m.get('original_lines')} -> {m.get('final_lines')} lines; "
            f"{m.get('steps_kept')} reductions kept out of {m.get('steps_tried')} tried.\n\n"
            + "".join(f"- {s}\n" for s in (m.get("log") or [])))


def _dup_section(rec: FailureRecord) -> str:
    if rec.duplicates is None:
        return ""
    from .prefile import Duplicate, DuplicateReport, render_duplicate_section
    d = rec.duplicates
    rep = DuplicateReport(query=d.get("query", ""), searched=bool(d.get("searched")),
                          error=d.get("error"))
    rep.candidates = [Duplicate(**c) for c in (d.get("candidates") or [])]
    return render_duplicate_section(rep)


def _sanitize_section(rec: FailureRecord) -> str:
    if not rec.sanitize_warnings:
        return ""
    lines = ["\n## Before filing - sanitisation warnings", ""]
    for w in rec.sanitize_warnings:
        lines.append(f"- **{w}**")
    lines.append("")
    lines.append("_Remove these by hand; this report is a public document._")
    return "\n".join(lines) + "\n"


def write_record(out_dir: str, rec: FailureRecord, repro_src: Optional[str] = None,
                 sanitize: bool = True) -> str:
    """Write ``<out_dir>/<signature>/`` and return the directory path.

    Sanitisation happens here, at the point bytes reach disk, rather than at
    each producer: one place to get right, and nothing can route around it.
    """
    from .prefile import check_clean, sanitize_obj, sanitize_text

    d = os.path.join(out_dir, rec.signature)
    os.makedirs(d, exist_ok=True)

    payload = rec.as_dict()
    if sanitize:
        payload = sanitize_obj(payload)
        rec.sanitize_warnings = check_clean(json.dumps(payload, default=str))

    with open(os.path.join(d, "record.json"), "w", encoding="utf-8") as fh:
        json.dump(payload, fh, indent=2, ensure_ascii=False, default=str)

    # The minimized reproducer is what a maintainer reads first, so it gets the
    # name the plan promised. When minimization has not run, the file says so
    # rather than passing the untouched case source off as minimal.
    minimal = rec.reproducer
    if minimal is None:
        minimal = ("# NOT MINIMIZED - this is the original case source.\n"
                   "# Run minimization before filing this report.\n\n"
                   + (repro_src or "# source unavailable\n"))
    clean = sanitize_text if sanitize else (lambda s: s)

    with open(os.path.join(d, "minimal.py"), "w", encoding="utf-8") as fh:
        fh.write(clean(minimal))

    with open(os.path.join(d, "issue.md"), "w", encoding="utf-8") as fh:
        fh.write(clean(render_issue(rec, minimal)))

    if repro_src:
        with open(os.path.join(d, "repro.py"), "w", encoding="utf-8") as fh:
            fh.write(clean(repro_src))

    with open(os.path.join(d, "environment.txt"), "w", encoding="utf-8") as fh:
        for k, v in rec.env.items():
            fh.write(clean(f"{k}: {v}") + "\n")

    # plan 18.4: the evidence files a maintainer or a later run may need
    sf = {"factor_changed": rec.factor_changed,
          "context": rec.context, "context_b": rec.context_b,
          "triage": rec.triage.as_dict(), "minimization": rec.minimized}
    with open(os.path.join(d, "semantic_factor.json"), "w", encoding="utf-8") as fh:
        json.dump(sanitize_obj(sf) if sanitize else sf, fh, indent=2,
                  ensure_ascii=False, default=str)

    trace = sanitize_obj(rec.observations) if sanitize else rec.observations
    with open(os.path.join(d, "execution_trace.json"), "w", encoding="utf-8") as fh:
        json.dump(trace, fh, indent=2, ensure_ascii=False, default=str)

    return d


def write_summary(out_dir: str, records: List[FailureRecord], extra: Dict[str, Any]) -> str:
    """One table over the whole run — the thing you read first each morning."""
    os.makedirs(out_dir, exist_ok=True)
    path = os.path.join(out_dir, "SUMMARY.md")

    by_priority: Dict[str, List[FailureRecord]] = {}
    for r in records:
        by_priority.setdefault(r.triage.priority, []).append(r)

    lines = ["# Run summary", ""]
    for k, v in extra.items():
        lines.append(f"- **{k}**: {v}")
    lines += ["", "## Candidates by priority", ""]
    for prio in ("high", "medium", "low", "info"):
        rs = by_priority.get(prio, [])
        if not rs:
            continue
        lines.append(f"### {prio} ({len(rs)})")
        lines.append("")
        lines.append("| signature | case | stage | probe | factor | oracles |")
        lines.append("|---|---|---|---|---|---|")
        for r in rs:
            lines.append(
                f"| `{r.signature}` | {r.case} | {r.triage.stage} | {r.probe} "
                f"| {r.factor_changed or '-'} | {', '.join(r.triage.kinds) or '-'} |"
            )
        lines.append("")

    with open(path, "w", encoding="utf-8") as fh:
        fh.write("\n".join(lines) + "\n")
    return path
