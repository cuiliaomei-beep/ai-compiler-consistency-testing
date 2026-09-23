"""tcd - a consistency-testing harness for Python-driven compilers.

M1 scope: the minimal closed loop from the research plan.

    eager / cold-compile / warm-cache execution
      -> five consistency oracles, numerics judged against an fp64 reference
      -> layered bisection for stage attribution and triage
      -> failure signature, dedup, and a developer-facing issue draft

Start with ``python run.py selfcheck``. Nothing this harness prints is
evidence until that passes.
"""

__version__ = "0.1.0"

from .case import Case, Context, all_cases, get, register  # noqa: F401
from .oracle import Comparison, Config, Finding, compare  # noqa: F401
from .report import FailureRecord, render_issue, write_record, write_summary  # noqa: F401
from .runner import RunOptions, run_all, run_case  # noqa: F401
from .snapshot import Observation, alias_relation  # noqa: F401
from .triage import DedupStore, Triage, signature  # noqa: F401

__all__ = [
    "Case", "Context", "register", "get", "all_cases",
    "Config", "Comparison", "Finding", "compare",
    "Observation", "alias_relation",
    "Triage", "DedupStore", "signature",
    "RunOptions", "run_case", "run_all",
    "FailureRecord", "render_issue", "write_record", "write_summary",
]
