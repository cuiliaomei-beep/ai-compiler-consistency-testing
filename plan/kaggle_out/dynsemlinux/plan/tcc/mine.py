"""Plan section 11, seed source 2: reproducers mined from the project's issue tracker.

Searches GitHub issues for Python code blocks that call ``torch.compile`` and
writes each as a reproducer file for ``--from-dir``. The safety gate in
:mod:`tcc.seeds` decides what may execute; this module only fetches text.
"""
from __future__ import annotations

import json
import os
import re
import time
import urllib.parse
import urllib.request
from typing import Any, Dict, List, Optional, Tuple

_FENCE = re.compile(r"```(?:python|py|python3)?\s*\n(.*?)```", re.S)


def _get(url: str, token: Optional[str]) -> Any:
    import ssl
    req = urllib.request.Request(url, headers={"Accept": "application/vnd.github+json", "User-Agent": "tcc-mine"})
    if token:
        req.add_header("Authorization", f"Bearer {token}")
    try:
        import certifi  # type: ignore
        ctx = ssl.create_default_context(cafile=certifi.where())
    except Exception:
        ctx = ssl.create_default_context()
    with urllib.request.urlopen(req, timeout=30, context=ctx) as resp:
        remaining = resp.headers.get("X-RateLimit-Remaining")
        return json.loads(resp.read().decode("utf-8")), remaining


def search_issues(query: str, repo: str = "pytorch/pytorch", pages: int = 3, per_page: int = 30,
                  token: Optional[str] = None, sort: str = "created") -> List[Dict[str, Any]]:
    token = token or os.environ.get("GITHUB_TOKEN")
    out: List[Dict[str, Any]] = []
    for page in range(1, pages + 1):
        q = urllib.parse.quote(f"repo:{repo} is:issue {query}")
        url = f"https://api.github.com/search/issues?q={q}&per_page={per_page}&page={page}&sort={sort}&order=desc"
        try:
            data, remaining = _get(url, token)
        except Exception as e:  # noqa: BLE001
            print(f"  search page {page} failed: {type(e).__name__}: {e}")
            break
        items = data.get("items", [])
        out.extend(items)
        if len(items) < per_page:
            break
        if remaining is not None and int(remaining) <= 1:
            time.sleep(61)
        else:
            time.sleep(7)  # unauthenticated search: 10 requests / minute
    return out


def _slug(title: str, n: int = 40) -> str:
    s = re.sub(r"[^A-Za-z0-9]+", "_", title).strip("_").lower()
    return s[:n].rstrip("_") or "issue"


def extract_blocks(body: str) -> List[str]:
    return [b.strip() for b in _FENCE.findall(body or "") if "torch" in b]


def usable_block(code: str, allow_cuda: bool = False) -> Tuple[bool, str]:
    if "torch.compile" not in code and "_dynamo.optimize" not in code and "@torch.compile" not in code:
        return False, "no torch.compile call"
    if len(code) > 6000:
        return False, "too long"
    if not allow_cuda and ("cuda" in code or "device_type=\"cuda\"" in code):
        return False, "cuda"
    if any(k in code for k in ("pip install", "import transformers", "import torchvision", "from transformers",
                               "import timm", "import diffusers", "load_state_dict", "from_pretrained",
                               "torch.hub", "torch.distributed", "torch.load(")):
        return False, "external dependency or weights"
    try:
        compile(code, "<issue>", "exec")
    except SyntaxError:
        return False, "does not parse"
    return True, "ok"


def mine(out_dir: str, queries: Optional[List[str]] = None, pages: int = 3, repo: str = "pytorch/pytorch",
         log=print, allow_cuda: bool = False) -> Dict[str, Any]:
    os.makedirs(out_dir, exist_ok=True)
    queries = queries or [
        '"torch.compile" "wrong result" in:body',
        '"torch.compile" "incorrect" in:body label:"module: inductor"',
        '"torch.compile" "eager" "different" in:body label:"oncall: pt2"',
        '"torch.compile" "inconsistent" in:body',
        '"torch.compile" label:"module: dynamic shapes" in:body',
        '"torch.compile" "silently" in:body',
    ]
    seen: set = set()
    written: List[Dict[str, Any]] = []
    rejected: Dict[str, int] = {}
    for q in queries:
        items = search_issues(q, repo=repo, pages=pages)
        log(f"  query {q!r}: {len(items)} issue(s)")
        for it in items:
            n = it.get("number")
            if n in seen or "pull_request" in it:
                continue
            seen.add(n)
            blocks = extract_blocks(it.get("body") or "")
            chosen = None
            why = "no python block with torch"
            for b in blocks:
                ok, why = usable_block(b, allow_cuda)
                if ok:
                    chosen = b
                    break
            if chosen is None:
                rejected[why] = rejected.get(why, 0) + 1
                continue
            name = f"issue_{n}_{_slug(it.get('title', ''))}.py"
            header = (f"# source: {it.get('html_url')}\n# title: {it.get('title')}\n"
                      f"# state: {it.get('state')}  created: {(it.get('created_at') or '')[:10]}\n"
                      f"# mined automatically; the harness records the torch.compile target and its first call\n\n")
            with open(os.path.join(out_dir, name), "w", encoding="utf-8") as fh:
                fh.write(header + chosen + "\n")
            written.append({"number": n, "file": name, "title": it.get("title"), "state": it.get("state"),
                            "url": it.get("html_url")})
    with open(os.path.join(out_dir, "MANIFEST.json"), "w", encoding="utf-8") as fh:
        json.dump({"repo": repo, "queries": queries, "written": written, "rejected": rejected},
                  fh, indent=2, ensure_ascii=False)
    log(f"  written {len(written)} reproducer(s) to {out_dir}; rejected {rejected}")
    return {"written": written, "rejected": rejected}
