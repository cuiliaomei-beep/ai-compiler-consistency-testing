"""For issues closed without a commit on the event: find merged PRs that reference
them, and check whether each PR's merge commit is in the release tag.

    python scripts/linked_prs.py v2.14.0 160840 176679 ...
"""
import json
import sys
import time

sys.path.insert(0, __import__("os").path.dirname(__file__))
from fix_in_release import REPO, get  # noqa: E402


def main(tag, numbers):
    for n in numbers:
        row = {"issue": n, "prs": []}
        try:
            q = f"repo:{REPO} is:pr is:merged {n} in:body"
            res = get(f"https://api.github.com/search/issues?q={q.replace(' ', '+')}&per_page=5")
            for it in res.get("items", []):
                pr = get(f"https://api.github.com/repos/{REPO}/pulls/{it['number']}")
                sha = pr.get("merge_commit_sha")
                entry = {"pr": it["number"], "title": it["title"][:60], "merged_at": (pr.get("merged_at") or "")[:10],
                         "sha": sha}
                if sha:
                    cmp = get(f"https://api.github.com/repos/{REPO}/compare/{tag}...{sha}")
                    entry["status_vs_tag"] = cmp.get("status")
                    entry["in_release"] = cmp.get("status") in ("behind", "identical")
                row["prs"].append(entry)
                time.sleep(0.5)
        except Exception as e:  # noqa: BLE001
            row["error"] = f"{type(e).__name__}: {str(e)[:80]}"
        print(json.dumps(row, ensure_ascii=False))
        time.sleep(1.0)


if __name__ == "__main__":
    main(sys.argv[1], sys.argv[2:])
