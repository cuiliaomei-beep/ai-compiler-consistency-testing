"""Was the commit that closed each issue included in a release tag?

    python scripts/fix_in_release.py v2.14.0 160840 172711 ...

For every issue: the `closed` timeline event carries the commit that closed it
(mergebot merges on main). GitHub's compare API then says whether that commit
is an ancestor of the tag ("behind"/"identical" = included in the release).
Rate limit: 60 requests/hour without GITHUB_TOKEN.
"""
import json
import os
import ssl
import sys
import time
import urllib.request

import certifi

CTX = ssl.create_default_context(cafile=certifi.where())
REPO = "pytorch/pytorch"


def get(url):
    req = urllib.request.Request(url, headers={"Accept": "application/vnd.github+json", "User-Agent": "tcc"})
    tok = os.environ.get("GITHUB_TOKEN")
    if tok:
        req.add_header("Authorization", f"Bearer {tok}")
    with urllib.request.urlopen(req, timeout=30, context=CTX) as r:
        return json.load(r)


def main(tag, numbers):
    rows = []
    for n in numbers:
        row = {"issue": n}
        try:
            issue = get(f"https://api.github.com/repos/{REPO}/issues/{n}")
            row["title"] = issue["title"][:70]
            row["closed_at"] = (issue.get("closed_at") or "")[:10]
            row["state_reason"] = issue.get("state_reason")
            events = get(f"https://api.github.com/repos/{REPO}/issues/{n}/events?per_page=100")
            closed = [e for e in events if e.get("event") == "closed"]
            sha = next((e.get("commit_id") for e in reversed(closed) if e.get("commit_id")), None)
            row["fix_commit"] = sha
            if sha:
                cmp = get(f"https://api.github.com/repos/{REPO}/compare/{tag}...{sha}")
                # status of `sha` relative to `tag`: behind/identical => ancestor of tag => in release
                row["status_vs_tag"] = cmp.get("status")
                row["in_release"] = cmp.get("status") in ("behind", "identical")
            else:
                row["status_vs_tag"] = "no commit on the closed event (closed manually / by PR reference)"
                row["in_release"] = None
        except Exception as e:  # noqa: BLE001
            row["error"] = f"{type(e).__name__}: {str(e)[:80]}"
        rows.append(row)
        print(json.dumps(row, ensure_ascii=False))
        time.sleep(1.0)
    return rows


if __name__ == "__main__":
    main(sys.argv[1], sys.argv[2:])
