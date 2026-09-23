"""Tracker search for the two nightly-only grad leads (2026-09-12)."""
import os, sys
sys.path.insert(0, os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
from tcc.report import search_github_issues
for q in ["nll_loss grad_input must be contiguous", "nll_loss2d backward channels_last",
          "grad_input must be contiguous", "nll_loss channels_last backward error",
          "quantile backward wrong gradient inductor", "quantile gradient torch.compile incorrect", "quantile compile backward"]:
    print("\n##", q)
    try:
        res = search_github_issues(q, limit=8)
        items = res.get("candidates") or res.get("items") or res
        if isinstance(items, dict):
            print("  ", {k: (v if not isinstance(v, list) else len(v)) for k, v in items.items()})
            items = next((v for v in items.values() if isinstance(v, list)), [])
        for r in items:
            print("  ", r if not isinstance(r, dict) else {k: r[k] for k in r if k in ("number", "title", "state", "url", "html_url", "updated_at", "closed_at")})
    except Exception as e:
        print("   ERR", e)
