"""Durable progress for long-running campaigns.

The acceptance criterion needs months of continuous fuzzing, and the first
attempt at a full-corpus run proved the original design could not survive it:
the machine was shut down after 110 minutes and every result was lost, because
progress only reached disk when the process finished.

So progress is written **after each case**, not at the end, and a restart skips
what is already done. A campaign that cannot survive a reboot is not a
campaign; it is a demo.
"""
from __future__ import annotations

import json
import os
import time
from dataclasses import dataclass, field
from typing import Any, Dict, List, Optional, Set


@dataclass
class Progress:
    """Case-level completion state, flushed to disk as it advances."""

    path: str
    completed: Set[str] = field(default_factory=set)
    started_at: float = field(default_factory=time.time)
    updated_at: float = field(default_factory=time.time)
    runs: int = 0
    counts: Dict[str, int] = field(default_factory=dict)
    #: cases that raised while being probed - recorded, not silently retried
    errored: Dict[str, str] = field(default_factory=dict)

    @classmethod
    def load(cls, path: str) -> "Progress":
        p = cls(path=path)
        if os.path.exists(path):
            try:
                with open(path, encoding="utf-8") as fh:
                    d = json.load(fh)
                p.completed = set(d.get("completed", []))
                p.started_at = d.get("started_at", p.started_at)
                p.runs = int(d.get("runs", 0))
                p.counts = dict(d.get("counts", {}))
                p.errored = dict(d.get("errored", {}))
            except Exception:
                pass  # a corrupt progress file must not block the campaign
        p.runs += 1
        return p

    def done(self, case_name: str) -> bool:
        return case_name in self.completed

    def mark(self, case_name: str, n_records: int = 0,
             error: Optional[str] = None) -> None:
        self.completed.add(case_name)
        if error:
            self.errored[case_name] = error[:200]
        if n_records:
            self.counts[case_name] = n_records
        self.updated_at = time.time()
        self.save()

    def save(self) -> None:
        d = os.path.dirname(self.path)
        if d:
            os.makedirs(d, exist_ok=True)
        tmp = self.path + ".tmp"
        payload = {
            "completed": sorted(self.completed),
            "started_at": self.started_at,
            "updated_at": self.updated_at,
            "runs": self.runs,
            "counts": self.counts,
            "errored": self.errored,
        }
        # write-then-rename, so a shutdown mid-write cannot corrupt the file
        with open(tmp, "w", encoding="utf-8") as fh:
            json.dump(payload, fh, indent=1)
        os.replace(tmp, self.path)

    def summary(self) -> Dict[str, Any]:
        return {
            "completed_cases": len(self.completed),
            "cases_with_findings": len(self.counts),
            "total_findings": sum(self.counts.values()),
            "errored_cases": len(self.errored),
            "campaign_runs": self.runs,
            "elapsed_hours": round((self.updated_at - self.started_at) / 3600, 2),
        }


def collect_records(out_dir: str) -> List[Dict[str, Any]]:
    """Read every record already on disk.

    Lets the summary be rebuilt from what survived, independently of whichever
    process wrote it.
    """
    out: List[Dict[str, Any]] = []
    if not os.path.isdir(out_dir):
        return out
    for name in sorted(os.listdir(out_dir)):
        p = os.path.join(out_dir, name, "record.json")
        if os.path.exists(p):
            try:
                with open(p, encoding="utf-8") as fh:
                    out.append(json.load(fh))
            except Exception:
                continue
    return out


def write_campaign_summary(out_dir: str, progress: Progress) -> str:
    """Rebuild the campaign summary from records on disk."""
    records = collect_records(out_dir)
    by_prio: Dict[str, List[Dict[str, Any]]] = {}
    for r in records:
        by_prio.setdefault(r.get("triage", {}).get("priority", "?"), []).append(r)

    lines = ["# Campaign summary", ""]
    for k, v in progress.summary().items():
        lines.append(f"- **{k}**: {v}")
    lines += ["", f"- **records on disk**: {len(records)}", ""]

    for prio in ("high", "medium", "low", "info"):
        rs = by_prio.get(prio, [])
        if not rs:
            continue
        lines += [f"## {prio} ({len(rs)})", "",
                  "| signature | case | stage | probe | oracles |",
                  "|---|---|---|---|---|"]
        for r in rs:
            t = r.get("triage", {})
            lines.append(
                f"| `{r.get('signature')}` | {r.get('case')} | {t.get('stage')} "
                f"| {r.get('probe')} | {', '.join(t.get('kinds') or []) or '-'} |")
        lines.append("")

    if progress.errored:
        lines += ["## Cases that errored", "", "| case | error |", "|---|---|"]
        for k, v in sorted(progress.errored.items())[:60]:
            lines.append(f"| {k} | {v} |")

    os.makedirs(out_dir, exist_ok=True)
    path = os.path.join(out_dir, "CAMPAIGN.md")
    with open(path, "w", encoding="utf-8") as fh:
        fh.write("\n".join(lines) + "\n")
    return path
