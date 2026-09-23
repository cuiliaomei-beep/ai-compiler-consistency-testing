"""Collect the current outcome of every issue the user has filed (read-only GitHub queries through `gh api`).

    python scripts/issue_status_report.py            # writes results/issue_status/raw.json and prints a table

For each issue: state / state_reason, who closed it and with which commit, labels put by humans, assignees, comments by
other people, and pull requests that reference it (with their state and whether they landed).  Local drafts are matched by
title (0913issues/, 0920issues/) so every row carries the draft number of its round.
"""
import glob
import json
import os
import re
import subprocess
import sys

PLAN = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
ROOT = os.path.dirname(PLAN)
GH = r"C:\Program Files\GitHub CLI\gh.exe"
USER = "cuiliaomei-beep"
REPOS = ["pytorch/pytorch", "numba/numba", "jax-ml/jax"]
BOTS = {"github-actions[bot]", "pytorch-bot[bot]", "pytorchmergebot", "pull[bot]", "facebook-github-bot", "google-cla[bot]", "dr-ci[bot]"}


def gh(path, *fields, paginate=False):
    cmd = [GH, "api", "-X", "GET", path] + [x for f in fields for x in ("-f", f)] + (["--paginate"] if paginate else [])
    import time
    for attempt in range(6):                                   # the link drops now and then: retry
        r = subprocess.run(cmd, capture_output=True, text=True, encoding="utf-8", errors="replace")
        if not r.returncode:
            break
        time.sleep(5 + 5 * attempt)
    else:
        raise RuntimeError(r.stderr[:300])
    out = r.stdout.strip()
    if paginate and out.startswith("[") and "][" in out:
        out = out.replace("][", ",")
    return json.loads(out)


def norm_title(t):
    return re.sub(r"[^a-z0-9]+", "", t.lower())[:80]


def local_drafts():
    m = {}
    for folder in ("0913issues", "0920issues"):
        for f in glob.glob(os.path.join(ROOT, folder, "[0-9][0-9]*-*.md")):
            s = open(f, encoding="utf-8").read()
            t = re.search(r"## Title\s*\n\s*\n(.+?)\n", s)
            if t:
                m[norm_title(t.group(1))] = f"{folder[:4]}/{os.path.basename(f).split('-')[0]}"
    return m


def main():
    drafts = local_drafts()
    rows = []
    for repo in REPOS:
        items = gh("search/issues", f"q=repo:{repo} is:issue author:{USER}", "per_page=100", "sort=created", "order=asc")["items"]
        for it in items:
            n = it["number"]
            tl = gh(f"repos/{repo}/issues/{n}/timeline", "per_page=100", paginate=True)
            prs, human_labels, closed = [], [], None
            for e in tl:
                ev = e.get("event")
                if ev == "cross-referenced":
                    src = (e.get("source") or {}).get("issue") or {}
                    if src.get("pull_request"):
                        prs.append({"number": src["number"], "title": src["title"], "state": src["state"], "author": src["user"]["login"],
                                    "merged_at": src["pull_request"].get("merged_at"), "fixes": bool(re.search(r"(?i)\b(fix(es|ed)?|close[sd]?|resolve[sd]?)\b[^\n]{0,40}#%d\b" % n, src.get("body") or ""))})
                elif ev == "labeled" and (e.get("actor") or {}).get("login") not in BOTS | {USER}:
                    human_labels.append(f"{e['label']['name']} ({e['actor']['login']})")
                elif ev == "closed":
                    closed = {"by": (e.get("actor") or {}).get("login"), "commit": (e.get("commit_id") or "")[:10], "at": e.get("created_at", "")[:10]}
            comments = [c for c in gh(f"repos/{repo}/issues/{n}/comments", "per_page=100") if c["user"]["login"] not in BOTS | {USER}]
            rows.append({"repo": repo, "number": n, "title": it["title"], "draft": drafts.get(norm_title(it["title"]), "?"), "created": it["created_at"][:10],
                         "state": it["state"], "reason": it.get("state_reason"), "labels": [l["name"] for l in it["labels"]], "human_labels": human_labels,
                         "assignees": [a["login"] for a in it.get("assignees") or []], "closed": closed, "prs": prs,
                         "comments": [{"by": c["user"]["login"], "assoc": c.get("author_association"), "at": c["created_at"][:10], "body": c["body"][:700]} for c in comments]})
            print(f"{repo}#{n} {rows[-1]['draft']:8s} {it['state']:6s} prs={len(prs)} comments={len(comments)} human_labels={len(human_labels)}", flush=True)
    out = os.path.join(PLAN, "results", "issue_status")
    os.makedirs(out, exist_ok=True)
    json.dump(rows, open(os.path.join(out, "raw.json"), "w", encoding="utf-8"), ensure_ascii=False, indent=1)
    print(len(rows), "issues ->", os.path.join(out, "raw.json"))


if __name__ == "__main__":
    main()
