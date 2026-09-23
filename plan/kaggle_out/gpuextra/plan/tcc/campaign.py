"""Plan section 25 RQ5: the real-world campaign and its status ledger.

Progress is flushed after every program so a long run survives a reboot, and
every confirmed failure carries a status from the plan's list:

    Generated / Submitted / Confirmed / Fixed / Duplicate / Invalid / Pending
"""
from __future__ import annotations

import json
import os
import time
from dataclasses import dataclass, field
from typing import Any, Dict, List, Optional

STATUSES = ("Generated", "Submitted", "Confirmed", "Fixed", "Duplicate", "Invalid", "Pending")


@dataclass
class Progress:
    path: str
    completed: Dict[str, Dict[str, Any]] = field(default_factory=dict)
    started: float = field(default_factory=time.time)

    @classmethod
    def load(cls, path: str) -> "Progress":
        p = cls(path=path)
        if os.path.exists(path):
            try:
                with open(path, encoding="utf-8") as fh:
                    d = json.load(fh)
                p.completed = d.get("completed", {})
                p.started = d.get("started", p.started)
            except Exception:
                pass
        return p

    def done(self, name: str) -> bool:
        return name in self.completed

    def mark(self, name: str, n_records: int, n_tests: int = 0, error: Optional[str] = None) -> None:
        self.completed[name] = {"records": n_records, "tests": n_tests, "error": error, "at": time.time()}
        d = os.path.dirname(self.path)
        if d:
            os.makedirs(d, exist_ok=True)
        with open(self.path, "w", encoding="utf-8") as fh:
            json.dump({"completed": self.completed, "started": self.started}, fh, indent=2)

    def summary(self) -> Dict[str, Any]:
        return {"programs": len(self.completed),
                "candidates": sum(v.get("records", 0) for v in self.completed.values()),
                "tests": sum(v.get("tests", 0) for v in self.completed.values()),
                "errors": sum(1 for v in self.completed.values() if v.get("error"))}


def _status_path(out_dir: str) -> str:
    return os.path.join(out_dir, "status.json")


def load_status(out_dir: str) -> Dict[str, Dict[str, Any]]:
    p = _status_path(out_dir)
    if os.path.exists(p):
        with open(p, encoding="utf-8") as fh:
            return json.load(fh)
    return {}


def refresh_status(out_dir: str) -> Dict[str, Dict[str, Any]]:
    """Pick up every report directory; new ones start as Generated."""
    st = load_status(out_dir)
    if not os.path.isdir(out_dir):
        return st
    for nm in sorted(os.listdir(out_dir)):
        md = os.path.join(out_dir, nm, "metadata.json")
        if not os.path.exists(md):
            continue
        with open(md, encoding="utf-8") as fh:
            meta = json.load(fh)
        e = st.setdefault(nm, {"status": "Generated"})
        e.update({k: meta.get(k) for k in ("program", "stage", "priority", "factor", "probe", "reproducibility")})
    with open(_status_path(out_dir), "w", encoding="utf-8") as fh:
        json.dump(st, fh, indent=2, ensure_ascii=False)
    return st


def set_status(out_dir: str, sig: str, status: str) -> None:
    if status not in STATUSES:
        raise ValueError(f"status must be one of {STATUSES}")
    st = refresh_status(out_dir)
    st.setdefault(sig, {})["status"] = status
    with open(_status_path(out_dir), "w", encoding="utf-8") as fh:
        json.dump(st, fh, indent=2, ensure_ascii=False)
    md = os.path.join(out_dir, sig, "metadata.json")
    if os.path.exists(md):
        with open(md, encoding="utf-8") as fh:
            meta = json.load(fh)
        meta["status"] = status
        with open(md, "w", encoding="utf-8") as fh:
            json.dump(meta, fh, indent=2, ensure_ascii=False)


def write_campaign_summary(out_dir: str, progress: Progress) -> str:
    st = refresh_status(out_dir)
    counts = {s: 0 for s in STATUSES}
    for e in st.values():
        counts[e.get("status", "Generated")] = counts.get(e.get("status", "Generated"), 0) + 1
    L = ["# Campaign", "", f"- started: {time.strftime('%Y-%m-%d %H:%M', time.localtime(progress.started))}"]
    for k, v in progress.summary().items():
        L.append(f"- {k}: {v}")
    L += ["", "## Status ledger (plan RQ5)", "", "| status | n |", "|---|---:|"]
    for s in STATUSES:
        L.append(f"| {s} | {counts.get(s, 0)} |")
    L += ["", "| signature | program | stage | priority | factor | repro | status |", "|---|---|---|---|---|---|---|"]
    for sig, e in st.items():
        L.append(f"| `{sig}` | {e.get('program')} | {e.get('stage')} | {e.get('priority')} | "
                 f"{e.get('factor') or '-'} | {e.get('reproducibility')} | {e.get('status')} |")
    conv = counts.get("Confirmed", 0) + counts.get("Fixed", 0)
    total = len(st)
    L += ["", f"conversion (developer-actionable / generated): {conv}/{total}"]
    path = os.path.join(out_dir, "CAMPAIGN.md")
    os.makedirs(out_dir, exist_ok=True)
    with open(path, "w", encoding="utf-8") as fh:
        fh.write("\n".join(L) + "\n")
    return path


def campaign(args) -> int:
    """``run.py campaign``: run the real compiler over everything, or update a status."""
    if args.status:
        sig, _, status = args.status.partition("=")
        set_status(args.out, sig.strip(), status.strip())
        print(f"{sig} -> {status}")
        p = Progress.load(os.path.join(args.out, "progress.json"))
        print(write_campaign_summary(args.out, p))
        return 0
    # a campaign is a full run with confirmation, minimization and every probe
    import run as cli  # type: ignore
    args.minimize = True
    args.reruns = max(args.reruns, 2)
    isolate = bool(getattr(args, "isolate", False))
    if not isolate and not getattr(args, "no_isolate", False):
        try:
            import torch
            isolate = torch.cuda.is_available()   # a device-side assert poisons the whole process
        except Exception:
            isolate = False
    if isolate and not getattr(args, "file", None) and not getattr(args, "slice", None):
        rc = _isolated_campaign(args)
    else:
        rc = cli.cmd_run(args)
    p = Progress.load(os.path.join(args.out, "progress.json"))
    print(write_campaign_summary(args.out, p))
    return rc


_PASS_FLAGS = ("minimize", "search_duplicates", "no_corpus", "keep_info", "strict_stride", "disk_cache",
               "layered_only", "matrix_only", "binding_only")
_PASS_VALUES = ("backend", "reruns", "seed", "max_contexts", "test_budget", "time_budget", "minimize_budget",
                "duplicate_repo", "device", "from_dir", "nnsmith", "opinfo", "opinfo_samples", "tag", "out",
                "binding_variants", "binding_forms")


def _child_argv(args, extra: List[str]) -> List[str]:
    import sys as _sys
    here = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
    argv = [_sys.executable, "-u", os.path.join(here, "run.py"), "run"]
    for k in _PASS_VALUES:
        v = getattr(args, k, None)
        if v not in (None, 0, "", False):
            argv += [f"--{k.replace('_', '-')}", str(v)]
    for k in _PASS_FLAGS:
        if getattr(args, k, False):
            argv.append(f"--{k.replace('_', '-')}")
    return argv + extra


def _isolated_campaign(args) -> int:
    """One child interpreter per reproducer file (or per chunk of generated programs).

    The parent never imports the programs; it only schedules, so a native crash
    or a poisoned CUDA context in a child cannot take the campaign down. Children
    share the output directory and progress.json, so a killed campaign resumes.
    """
    import subprocess
    import sys as _sys
    out = args.out
    os.makedirs(out, exist_ok=True)
    progress = Progress.load(os.path.join(out, "progress.json"))
    units: List[List[str]] = []
    if getattr(args, "from_dir", None):
        names = sorted(f for f in os.listdir(args.from_dir) if f.endswith(".py") and not f.startswith("_"))
        names = [n for n in names if not progress.done(n[:-3])]
        units = [["--file", n] for n in names]
        print(f"isolated campaign: {len(names)} reproducer(s) pending in {args.from_dir}")
    else:
        # count the selection once, then hand out slices
        import run as cli  # type: ignore
        n_total = len(cli._programs(args))
        size = max(1, int(getattr(args, "chunk_size", 25)))
        units = [["--slice", f"{a}:{min(a + size, n_total)}"] for a in range(0, n_total, size)]
        print(f"isolated campaign: {n_total} program(s) in {len(units)} chunk(s) of {size}")
    log_path = os.path.join(out, "isolated_children.log")
    failures = 0
    for i, extra in enumerate(units, 1):
        argv = _child_argv(args, extra)
        label = " ".join(extra)
        t0 = time.time()
        try:
            r = subprocess.run(argv, capture_output=True, text=True, timeout=float(getattr(args, "child_timeout", 2400)))
            tail = "\n".join((r.stdout or "").splitlines()[-12:])
            status = f"exit {r.returncode}"
            if r.returncode != 0:
                failures += 1
                tail += "\n" + "\n".join((r.stderr or "").splitlines()[-6:])
        except subprocess.TimeoutExpired:
            status, tail = "timeout", ""
            failures += 1
        dt = time.time() - t0
        print(f"[{i}/{len(units)}] {label:<50} {status} [{dt:.0f}s]", flush=True)
        for ln in tail.splitlines():
            if "candidate(s)" in ln or ln.strip().startswith(("*", "reject")) or "Error" in ln:
                print("    " + ln.rstrip()[:160], flush=True)
        with open(log_path, "a", encoding="utf-8") as fh:
            fh.write(f"==== {label} {status} [{dt:.0f}s]\n{tail}\n")
        if getattr(args, "from_dir", None) and status != "exit 0":
            # a crashed child never marked its program: record it so a resume skips it
            progress = Progress.load(os.path.join(out, "progress.json"))
            progress.mark(extra[1][:-3], 0, 0, error=status)
    print(f"isolated campaign finished: {len(units)} unit(s), {failures} failed child(ren); log {log_path}")
    return 0
