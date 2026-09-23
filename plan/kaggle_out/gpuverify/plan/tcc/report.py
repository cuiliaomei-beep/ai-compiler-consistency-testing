"""Plan section 18: developer-ready issue report generation.

18.2  the information collected automatically
18.3  the ``issue.md`` template
18.4  the per-failure output directory
18.5  failure signature + local clustering (tracker search is optional)
18.6  nothing is submitted automatically; a person reviews every draft
"""
from __future__ import annotations

import hashlib
import json
import os
import re
from dataclasses import dataclass, field
from typing import Any, Dict, List, Optional

from .compat import environment
from .localize import STAGE_LABEL, Triage
from .oracle import Comparison, Finding


@dataclass
class FailureRecord:
    signature: str
    program: str
    project: str
    triage: Triage
    probe: str                                   # layered | matrix
    context: Dict[str, Any] = field(default_factory=dict)
    context_b: Optional[Dict[str, Any]] = None
    factor_changed: str = ""
    controlled: Dict[str, Any] = field(default_factory=dict)
    obligation: Optional[Dict[str, Any]] = None  # why this test was generated (from Phase 1)
    comparisons: Dict[str, Comparison] = field(default_factory=dict)
    cache: Optional[Dict[str, Any]] = None
    observations: Dict[str, Any] = field(default_factory=dict)
    fp64_available: bool = False
    reruns_agreeing: int = 0
    reruns_total: int = 0
    seed: int = 0
    backend: str = "inductor"
    compile_options: Dict[str, Any] = field(default_factory=dict)
    env: Dict[str, Any] = field(default_factory=environment)
    notes: str = ""
    minimized: Optional[Dict[str, Any]] = None
    reproducer: Optional[str] = None
    expected_text: str = ""
    actual_text: str = ""
    duplicates: Optional[Dict[str, Any]] = None
    sanitize_warnings: List[str] = field(default_factory=list)
    execution_sequence: List[str] = field(default_factory=list)
    #: Generated / Submitted / Confirmed / Fixed / Duplicate / Invalid / Pending
    status: str = "Generated"
    fault: Optional[str] = None   # injected-fault benchmark id when applicable

    def as_dict(self) -> Dict[str, Any]:
        return {
            "signature": self.signature, "program": self.program, "project": self.project,
            "probe": self.probe, "triage": self.triage.as_dict(), "context": self.context,
            "context_b": self.context_b, "factor_changed": self.factor_changed,
            "controlled": self.controlled, "obligation": self.obligation,
            "comparisons": {k: v.as_dict() for k, v in self.comparisons.items()},
            "cache": self.cache, "observations": self.observations,
            "fp64_available": self.fp64_available,
            "reproducibility": f"{self.reruns_agreeing}/{self.reruns_total}", "seed": self.seed,
            "backend": self.backend, "compile_options": self.compile_options,
            "environment": self.env, "notes": self.notes, "minimized": self.minimized,
            "duplicates": self.duplicates, "sanitize_warnings": self.sanitize_warnings,
            "execution_sequence": self.execution_sequence, "status": self.status,
            "fault": self.fault,
        }


# --------------------------------------------------------------------------
# 18.5 signature + dedup
# --------------------------------------------------------------------------

def ast_hash(source: Optional[str]) -> str:
    if not source:
        return ""
    import ast
    import textwrap
    try:
        tree = ast.parse(textwrap.dedent(source))
        for n in ast.walk(tree):
            for attr in ("lineno", "col_offset", "end_lineno", "end_col_offset"):
                if hasattr(n, attr):
                    setattr(n, attr, 0)
        dump = ast.dump(tree, include_attributes=False)
    except SyntaxError:
        dump = source
    return hashlib.sha1(dump.encode()).hexdigest()[:8]


def signature(project: str, stage: str, factor: str, kinds: List[str], exception: Optional[str] = None,
              frame: Optional[str] = None, source: Optional[str] = None,
              cold_warm: str = "") -> str:
    """project | compiler stage | semantic factor | oracle type | exception | frame | AST | cold/warm."""
    factor_kind = re.sub(r"\[.*?\]|=.*$", "", factor).split(".")[-1] if factor else ""
    raw = "|".join([project, stage, factor_kind, ",".join(sorted(set(kinds))), exception or "",
                    frame or "", ast_hash(source), cold_warm])
    return hashlib.sha1(raw.encode()).hexdigest()[:12]


class DedupStore:
    def __init__(self, path: str):
        self.path = path
        self.entries: Dict[str, Dict[str, Any]] = {}
        if path and os.path.exists(path):
            try:
                with open(path, encoding="utf-8") as fh:
                    self.entries = json.load(fh)
            except Exception:
                self.entries = {}

    def add(self, sig: str, meta: Dict[str, Any]) -> bool:
        if sig in self.entries:
            self.entries[sig]["count"] = self.entries[sig].get("count", 1) + 1
            return False
        self.entries[sig] = {"count": 1, **meta}
        return True

    def save(self) -> None:
        if not self.path:
            return
        d = os.path.dirname(self.path)
        if d:
            os.makedirs(d, exist_ok=True)
        with open(self.path, "w", encoding="utf-8") as fh:
            json.dump(self.entries, fh, indent=2, ensure_ascii=False, sort_keys=True)

    def stats(self) -> Dict[str, int]:
        return {"unique": len(self.entries), "total": sum(e.get("count", 1) for e in self.entries.values())}


def search_github_issues(query: str, repo: str = "pytorch/pytorch", limit: int = 5,
                         token: Optional[str] = None) -> Dict[str, Any]:
    """Plan 18.5: look for possible duplicates in the project's tracker.

    Uses the public search API (10 requests/minute without a token; set
    ``GITHUB_TOKEN`` for more). Returns candidates, never a verdict: a person
    decides whether a hit is the same defect.
    """
    import json as _json
    import os as _os
    import urllib.parse
    import urllib.request
    token = token or _os.environ.get("GITHUB_TOKEN")
    q = urllib.parse.quote(f"repo:{repo} {query}")
    url = f"https://api.github.com/search/issues?q={q}&per_page={limit}"
    req = urllib.request.Request(url, headers={"Accept": "application/vnd.github+json",
                                               "User-Agent": "tcc-dedup"})
    if token:
        req.add_header("Authorization", f"Bearer {token}")
    import ssl
    contexts = []
    try:
        import certifi  # type: ignore
        contexts.append(("certifi", ssl.create_default_context(cafile=certifi.where())))
    except Exception:
        pass
    contexts.append(("system", ssl.create_default_context()))
    # last resort for interpreters without a CA bundle: a read-only public lookup
    contexts.append(("unverified", ssl._create_unverified_context()))
    data = None
    err = None
    used = None
    for name, ctx in contexts:
        try:
            with urllib.request.urlopen(req, timeout=20, context=ctx) as resp:
                data = _json.loads(resp.read().decode("utf-8"))
            used = name
            break
        except Exception as e:  # noqa: BLE001
            err = f"{type(e).__name__}: {e}"
            if "CERTIFICATE_VERIFY_FAILED" not in str(e):
                break
    if data is None:
        return {"query": query, "searched": False, "error": err, "candidates": []}
    cands = [{"number": it.get("number"), "title": it.get("title"), "url": it.get("html_url"),
              "state": it.get("state"), "is_pr": "pull_request" in it,
              "created": (it.get("created_at") or "")[:10]} for it in data.get("items", [])]
    return {"query": query, "searched": True, "error": None, "candidates": cands, "tls": used}


def dedup_query(rec: "FailureRecord") -> str:
    """A tracker query built from the failure signature's ingredients."""
    # a reproducer mined from an issue carries its title: that is the best query
    for ln in (rec.notes or "").splitlines():
        if ln.startswith("# title:") or (ln and not ln.startswith(("loaded from", "http", "compile options"))
                                         and len(ln.split()) >= 3):
            title = ln.replace("# title:", "").strip()
            import re as _re
            words = [w for w in _re.findall(r"[A-Za-z_][A-Za-z0-9_.]{2,}", title)
                     if w.lower() not in ("the", "and", "with", "when", "for", "not", "does", "torch.compile")]
            if words:
                return " ".join(words[:8])
    words = ["torch.compile"]
    src = rec.reproducer or ""
    import re as _re
    ops = sorted(set(_re.findall(r"torch\.(?:ops\.aten\.)?([A-Za-z_][A-Za-z0-9_.]*)\(", src)))
    ops = [o for o in ops if o not in ("compile", "randn", "manual_seed", "tensor", "randint")]
    words += ops[:2]
    if rec.factor_changed == "compile":
        words.append("dynamic")
    for f in [x for c in rec.comparisons.values() for x in c.findings]:
        ev = f.evidence or {}
        msg = ev.get("message") or ev.get("test_message") or ""
        m = _re.search(r"got ([A-Za-z]+Error)\('([^'\n]{10,80})", msg) or _re.search(r"([A-Za-z]+Error): ([^\n]{10,80})", msg)
        if m:
            words.append(f'"{m.group(2)[:60]}"')
            break
    return " ".join(words)


# --------------------------------------------------------------------------
# 18.1 step 8: environment sanitisation
# --------------------------------------------------------------------------

_SECRET = re.compile(r"(ghp_[A-Za-z0-9]{20,}|github_pat_[A-Za-z0-9_]{20,}|sk-[A-Za-z0-9]{20,}|"
                     r"AKIA[0-9A-Z]{16}|hf_[A-Za-z0-9]{20,})")
_HOME = re.compile(r"([A-Za-z]:\\Users\\[^\\\s\"']+|/home/[^/\s\"']+|/Users/[^/\s\"']+)")


def sanitize_text(s: str) -> str:
    s = _SECRET.sub("<redacted-token>", s)
    return _HOME.sub("<home>", s)


def sanitize_obj(o: Any) -> Any:
    if isinstance(o, str):
        return sanitize_text(o)
    if isinstance(o, dict):
        return {k: sanitize_obj(v) for k, v in o.items()}
    if isinstance(o, (list, tuple)):
        return [sanitize_obj(v) for v in o]
    return o


def check_clean(s: str) -> List[str]:
    out = []
    if _SECRET.search(s):
        out.append("a token-like string survived sanitisation")
    if re.search(r"password|passwd|secret=", s, re.I):
        out.append("a password/secret-like word is present")
    return out


# --------------------------------------------------------------------------
# 18.3 the issue template
# --------------------------------------------------------------------------

_EV = {"shape": "shape", "dtype": "dtype", "actual_shape": "actual shape",
       "n_mismatch": "mismatching elements", "n_total": "total elements",
       "max_abs_error": "max absolute error", "max_rel_error": "max relative error",
       "first_mismatch_index": "first mismatching element", "eager_err_vs_fp64": "eager error vs float64",
       "compiled_err_vs_fp64": "compiled error vs float64", "budget": "accepted budget",
       "exception": "exception", "message": "message", "lost": "alias pairs lost",
       "gained": "alias pairs gained"}


def _difference_block(rec: FailureRecord) -> str:
    L: List[str] = []
    for name, cmp in rec.comparisons.items():
        if not cmp.differs:
            continue
        L.append(f"{name}:")
        for f in cmp.findings:
            L.append(f"  [{f.kind}] {f.detail}")
            ev = f.evidence or {}
            for k in ("max_abs_error", "first_mismatch_index", "n_mismatch", "n_total",
                      "eager_err_vs_fp64", "compiled_err_vs_fp64", "budget", "exception", "message",
                      "lost", "gained"):
                if k in ev:
                    L.append(f"      {_EV[k]:<26}: {ev[k]}")
            if "first_mismatch_expected" in ev:
                L.append(f"      {'expected at that index':<26}: {ev['first_mismatch_expected']}")
                L.append(f"      {'actual at that index':<26}: {ev['first_mismatch_actual']}")
    return "\n".join(L) if L else "(no findings recorded)"


def _cache_table(rec: FailureRecord) -> str:
    c = rec.cache
    if not c:
        return ""
    def r(x: Optional[Dict[str, Any]], default: str) -> str:
        if x is None:
            return default
        return "**incorrect**" if x.get("differs") else "correct"
    rows = [
        "| Execution | Result |", "|---|---|",
        "| eager(B) | reference |",
        f"| compiled cold(B) | {r(c.get('eager_vs_cold'), 'n/a')} |",
        f"| compiled A -> warm B | {r(c.get('eager_vs_warm') or c.get('cold_vs_warm'), 'n/a')} |",
        f"| cold(B) vs warm(B) | {'**differs**' if c.get('cold_vs_warm', {}).get('differs') else 'same'} |",
        f"| recompile on A -> B | {'yes' if c.get('recompiled_on_switch') else '**no**'} |",
    ]
    if c.get("return_trip") is not None:
        rows.append(f"| compiled A -> B -> A vs A | "
                    f"{'**differs**' if c['return_trip'].get('differs') else 'same'} |")
        rows.append(f"| recompile on B -> A | {'yes' if c.get('recompiled_on_return') else '**no**'} |")
    return "\n".join(rows)


def render_issue(rec: FailureRecord) -> str:
    env = rec.env
    t = rec.triage
    factor = rec.factor_changed or "(single context)"
    fa = rec.context.get("factors") or {}
    fb = (rec.context_b or {}).get("factors") or {}
    a_val = fa.get(rec.factor_changed, "(base)") if rec.factor_changed else "-"
    b_val = fb.get(rec.factor_changed, "(base)") if rec.factor_changed else "-"
    controlled = "\n".join(f"{k}: unchanged ({v})" for k, v in rec.controlled.items()) or \
                 "shape / dtype / stride / device / compile flags: unchanged"
    title = (f"# [{rec.project.split('/')[-1]} compile] Incorrect result when `{factor}` changes"
             if rec.factor_changed else
             f"# [{rec.project.split('/')[-1]} compile] Compiled execution inconsistent with eager "
             f"({', '.join(t.kinds) or 'divergence'})")
    summary = (f"The compiled execution is inconsistent with Python eager execution when `{factor}` "
               f"changes from `{a_val}` to `{b_val}`." if rec.factor_changed else
               f"The compiled execution is inconsistent with Python eager execution for context "
               f"`{rec.context.get('name')}`.")
    why = ""
    if rec.obligation:
        why = (f"\nThis test was generated because the static analysis found: "
               f"{rec.obligation.get('origin')} (factor `{rec.obligation.get('factor')}`, "
               f"oracles {rec.obligation.get('oracles')}).")
    cache = _cache_table(rec)
    dup = ""
    if rec.duplicates and rec.duplicates.get("candidates"):
        dup = "\n## Possible existing issues\n\n" + "\n".join(
            f"- {c.get('url')} — {c.get('title')}" for c in rec.duplicates["candidates"]) + "\n"
    minim = ""
    if rec.minimized:
        m = rec.minimized
        if m.get("reproduces"):
            minim = (f"\n## Minimization\n\nProgram {m.get('original_lines')} -> {m.get('final_lines')} lines, "
                     f"inputs {m.get('original_numel')} -> {m.get('final_numel')} elements; "
                     f"{m.get('steps_kept')} reductions kept of {m.get('steps_tried')} tried.\n"
                     + "".join(f"- {s}\n" for s in m.get("log") or []))
        else:
            minim = f"\n## Minimization\n\n_Not minimized: {(m.get('log') or ['?'])[0]}_\n"
    warn = ""
    if rec.sanitize_warnings:
        warn = "\n## Before filing\n\n" + "".join(f"- **{w}**\n" for w in rec.sanitize_warnings)
    fp = ("A float64 reference was computed; numeric findings are reported only when the compiled error "
          "against that reference exceeds the eager error by more than the configured multiplier."
          if rec.fp64_available else
          "No float64 reference could be built; a dtype-aware tolerance was used instead.")
    return f"""{title}

<!-- DRAFT generated by tcc. Review every section before filing (plan 18.6). -->

## Summary
{summary}
{t.rationale}{why}

## Environment
- Python: {env.get('python')}
- Framework: PyTorch {env.get('torch')}
- Compiler backend: {rec.backend}{(' ' + json.dumps(rec.compile_options)) if rec.compile_options else ''}
- Commit/version: {env.get('torch_git')}
- CUDA/ROCm: {env.get('cuda') or env.get('rocm') or 'none (CPU)'}
- GPU: {env.get('device_name')}
- OS: {env.get('os')}
- Triton: {env.get('triton')}

## Minimal Reproducer

```python
{(rec.reproducer or '# see minimal.py').rstrip()}
```

## Expected Behavior

Eager/reference result:

```text
{rec.expected_text.rstrip() or '(see expected.txt)'}
```

## Actual Behavior

Compiled result:

```text
{rec.actual_text.rstrip() or '(see actual.txt)'}
```

## Trigger Condition

Changed semantic factor:

```text
{factor}: {a_val} -> {b_val}
```

Controlled factors:

```text
{controlled}
```

Execution sequence:

```text
{chr(10).join(rec.execution_sequence) or 'eager(x); reset; compiled(x)'}
```
{('''
## Cache / Specialization Evidence

''' + cache + '\n') if cache else ''}
## Difference

```text
{_difference_block(rec)}
```

## Suspected Stage

```text
{STAGE_LABEL.get(t.stage, t.stage)}
```

Attribution basis: first divergent layer = {t.first_divergent_layer or 'n/a'}; {t.rationale}

## Accuracy methodology

{fp}

## Reproducibility

```text
Reproduced {rec.reruns_agreeing}/{rec.reruns_total} runs with fixed seed {rec.seed}.
```
{minim}{dup}{warn}"""


# --------------------------------------------------------------------------
# 18.4 output directory
# --------------------------------------------------------------------------

def write_report(out_dir: str, rec: FailureRecord, sanitize: bool = True) -> str:
    d = os.path.join(out_dir, rec.signature)
    os.makedirs(d, exist_ok=True)
    clean = sanitize_text if sanitize else (lambda s: s)
    payload = rec.as_dict()
    if sanitize:
        payload = sanitize_obj(payload)
        rec.sanitize_warnings = check_clean(json.dumps(payload, default=str))

    with open(os.path.join(d, "issue.md"), "w", encoding="utf-8") as fh:
        fh.write(clean(render_issue(rec)))
    with open(os.path.join(d, "minimal.py"), "w", encoding="utf-8") as fh:
        fh.write(clean(rec.reproducer or "# reproducer unavailable; see execution_trace.json\n"))
    with open(os.path.join(d, "environment.txt"), "w", encoding="utf-8") as fh:
        for k, v in rec.env.items():
            fh.write(clean(f"{k}: {v}") + "\n")
        fh.write(f"backend: {rec.backend}\ncompile_options: {json.dumps(rec.compile_options)}\n")
    with open(os.path.join(d, "expected.txt"), "w", encoding="utf-8") as fh:
        fh.write(clean(rec.expected_text or "(not captured)\n"))
    with open(os.path.join(d, "actual.txt"), "w", encoding="utf-8") as fh:
        fh.write(clean(rec.actual_text or "(not captured)\n"))
    with open(os.path.join(d, "execution_trace.json"), "w", encoding="utf-8") as fh:
        json.dump(sanitize_obj({"sequence": rec.execution_sequence, "observations": rec.observations,
                                "cache": rec.cache,
                                "comparisons": {k: v.as_dict() for k, v in rec.comparisons.items()}}),
                  fh, indent=2, ensure_ascii=False, default=str)
    with open(os.path.join(d, "semantic_factor.json"), "w", encoding="utf-8") as fh:
        json.dump(sanitize_obj({"factor_changed": rec.factor_changed, "context": rec.context,
                                "context_b": rec.context_b, "controlled": rec.controlled,
                                "obligation": rec.obligation, "triage": rec.triage.as_dict()}),
                  fh, indent=2, ensure_ascii=False, default=str)
    with open(os.path.join(d, "metadata.json"), "w", encoding="utf-8") as fh:
        json.dump({"signature": rec.signature, "program": rec.program, "project": rec.project,
                   "stage": rec.triage.stage, "priority": rec.triage.priority, "kinds": rec.triage.kinds,
                   "factor": rec.factor_changed, "probe": rec.probe, "status": rec.status,
                   "reproducibility": f"{rec.reruns_agreeing}/{rec.reruns_total}",
                   "fault": rec.fault, "backend": rec.backend, "torch": rec.env.get("torch"),
                   "minimized": bool(rec.minimized and rec.minimized.get("reproduces")),
                   "duplicates": (rec.duplicates or {}).get("candidates", [])},
                  fh, indent=2, ensure_ascii=False, default=str)
    with open(os.path.join(d, "record.json"), "w", encoding="utf-8") as fh:
        json.dump(payload, fh, indent=2, ensure_ascii=False, default=str)
    return d


def write_summary(out_dir: str, records: List[FailureRecord], extra: Dict[str, Any]) -> str:
    os.makedirs(out_dir, exist_ok=True)
    path = os.path.join(out_dir, "SUMMARY.md")
    by: Dict[str, List[FailureRecord]] = {}
    for r in records:
        by.setdefault(r.triage.priority, []).append(r)
    L = ["# Run summary", ""]
    for k, v in extra.items():
        L.append(f"- **{k}**: {v}")
    L += ["", "## Candidates by priority", ""]
    for prio in ("high", "medium", "low", "info"):
        rs = by.get(prio, [])
        if not rs:
            continue
        L += [f"### {prio} ({len(rs)})", "", "| signature | program | stage | probe | factor | oracles | repro |",
              "|---|---|---|---|---|---|---|"]
        for r in rs:
            L.append(f"| `{r.signature}` | {r.program} | {r.triage.stage} | {r.probe} | "
                     f"{r.factor_changed or '-'} | {', '.join(r.triage.kinds) or '-'} | "
                     f"{r.reruns_agreeing}/{r.reruns_total} |")
        L.append("")
    with open(path, "w", encoding="utf-8") as fh:
        fh.write("\n".join(L) + "\n")
    return path


def render_values(obs_summary_or_outputs: Any, limit: int = 12) -> str:
    """Short, honest rendering of outputs for expected.txt / actual.txt."""
    from .oracle import _preview
    from .observe import flatten
    try:
        items, struct = flatten(obs_summary_or_outputs)
    except Exception:
        return repr(obs_summary_or_outputs)[:400]
    L = [f"structure: {struct}"]
    for i, it in enumerate(items[:limit]):
        L.append(f"[{i}] {_preview(it)}")
    return "\n".join(L)
