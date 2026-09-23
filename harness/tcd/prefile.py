"""Plan section 18: the checks that run before a report is filed.

Two of the nine steps in the plan's verification flow were missing, and both
are about what happens between "we have a candidate" and "a maintainer reads
it":

* **step 7, duplicate search** - a report that restates an open issue costs the
  maintainer time and costs the reporter credibility. Filing fifty issues into
  one project makes this the difference between being a contributor and being
  a firehose.
* **step 8, environment sanitisation** - the collected environment carries
  absolute paths, and absolute paths carry usernames. A bug report is a public
  document.

Neither blocks filing on its own. The duplicate search *annotates*; the plan is
explicit that suspected duplicates are flagged in the draft rather than
silently dropped, because the tool is not in a position to decide.
"""
from __future__ import annotations

import json
import os
import re
import urllib.error
import urllib.parse
import urllib.request
from dataclasses import dataclass, field
from typing import Any, Dict, List, Optional, Sequence

# --------------------------------------------------------------------------
# step 8: sanitisation
# --------------------------------------------------------------------------

#: patterns whose *value* must never reach a public report
_SECRET_PATTERNS = [
    (re.compile(r"\bgh[pousr]_[A-Za-z0-9]{16,}\b"), "<github-token>"),
    (re.compile(r"\b(?:sk|pk)-[A-Za-z0-9]{20,}\b"), "<api-key>"),
    (re.compile(r"\bAKIA[0-9A-Z]{16}\b"), "<aws-key>"),
    (re.compile(r"(?i)\b(token|secret|password|passwd|api[_-]?key)\s*[=:]\s*\S+"),
     r"\1=<redacted>"),
]


def _home_candidates() -> List[str]:
    out: List[str] = []
    for key in ("USERPROFILE", "HOME"):
        v = os.environ.get(key)
        if v:
            out.append(v)
    user = os.environ.get("USERNAME") or os.environ.get("USER")
    if user:
        for prefix in ("C:\\Users\\", "/home/", "/Users/"):
            out.append(prefix + user)
    return sorted({p for p in out if p}, key=len, reverse=True)


def sanitize_text(text: str) -> str:
    """Remove home paths, usernames and credential-shaped strings.

    Path replacement runs longest-first so that ``C:\\Users\\alice\\proj`` does
    not get half-replaced by a shorter prefix and leave the name behind.
    """
    if not text:
        return text
    out = text
    for home in _home_candidates():
        out = out.replace(home, "<HOME>")
        out = out.replace(home.replace("\\", "/"), "<HOME>")
    user = os.environ.get("USERNAME") or os.environ.get("USER")
    if user and len(user) >= 3:
        out = re.sub(rf"\b{re.escape(user)}\b", "<user>", out)
    host = os.environ.get("COMPUTERNAME") or os.environ.get("HOSTNAME")
    if host and len(host) >= 3:
        out = re.sub(rf"\b{re.escape(host)}\b", "<host>", out)
    for pat, repl in _SECRET_PATTERNS:
        out = pat.sub(repl, out)
    return out


def sanitize_obj(obj: Any) -> Any:
    """Recursively sanitise strings inside a nested structure."""
    if isinstance(obj, str):
        return sanitize_text(obj)
    if isinstance(obj, dict):
        return {k: sanitize_obj(v) for k, v in obj.items()}
    if isinstance(obj, list):
        return [sanitize_obj(v) for v in obj]
    if isinstance(obj, tuple):
        return tuple(sanitize_obj(v) for v in obj)
    return obj


def check_clean(text: str) -> List[str]:
    """What still looks sensitive after sanitising. Empty means clean."""
    problems: List[str] = []
    for home in _home_candidates():
        if home in text or home.replace("\\", "/") in text:
            problems.append(f"home path still present: {home}")
    user = os.environ.get("USERNAME") or os.environ.get("USER")
    if user and len(user) >= 3 and re.search(rf"\b{re.escape(user)}\b", text):
        problems.append(f"username still present: {user}")
    for pat, _ in _SECRET_PATTERNS:
        if pat.search(text):
            problems.append(f"credential-shaped string matches {pat.pattern[:40]}")
    return problems


# --------------------------------------------------------------------------
# step 7: duplicate search
# --------------------------------------------------------------------------

@dataclass
class Duplicate:
    number: int
    title: str
    url: str
    state: str
    score: float = 0.0

    def as_dict(self) -> Dict[str, Any]:
        return {"number": self.number, "title": self.title, "url": self.url,
                "state": self.state, "score": round(self.score, 3)}


@dataclass
class DuplicateReport:
    query: str
    searched: bool
    candidates: List[Duplicate] = field(default_factory=list)
    error: Optional[str] = None

    def as_dict(self) -> Dict[str, Any]:
        return {"query": self.query, "searched": self.searched,
                "error": self.error,
                "candidates": [c.as_dict() for c in self.candidates]}


#: words that carry no signal in a compiler bug title
_STOPWORDS = {
    "the", "a", "an", "is", "are", "was", "were", "and", "or", "not", "of",
    "to", "in", "on", "for", "with", "when", "that", "this", "it", "its",
    "compiled", "compile", "result", "results", "output", "error", "issue",
    "bug", "test", "case", "value", "values", "does", "doesn", "different",
}


def build_query(case_name: str, stage: str, kinds: Sequence[str],
                factor: str = "", extra_terms: Sequence[str] = ()) -> str:
    """Turn a failure signature into a search query.

    Kept short on purpose: GitHub's search ranks by relevance, and a long
    conjunction of terms drives recall to zero. Two or three distinctive words
    plus the stage find far more real duplicates than a full description.
    """
    terms: List[str] = []
    # the operator or module under test is usually the strongest term
    m = re.match(r"(?:op|mod|seed|chain)_([A-Za-z0-9_]+?)(?:_\d+)?$",
                 case_name.split("__")[0])
    if m:
        head = m.group(1).replace("_", " ").strip()
        for w in head.split():
            if w.lower() not in _STOPWORDS and len(w) > 2:
                terms.append(w)

    stage_terms = {
        "inductor_codegen": "inductor",
        "aot_functionalization": "functionalization",
        "dynamo_capture": "dynamo",
        "specialization_cache": "recompile guard",
        "compile_nondeterminism": "nondeterministic",
    }
    if stage in stage_terms:
        terms.append(stage_terms[stage])

    kind_terms = {"value": "wrong result", "alias": "aliasing",
                  "mutation": "in-place", "metadata": "stride"}
    for k in kinds:
        if k in kind_terms:
            terms.append(kind_terms[k])

    if factor and factor not in ("", "<none>"):
        terms.append(factor.split(".")[-1].replace("()", ""))
    terms.extend(extra_terms)

    # Budget in *words*, not in terms: several terms are multi-word phrases
    # ("wrong result"), so capping the term count still lets the query grow.
    # GitHub search ranks by relevance and a long conjunction drives recall to
    # zero, so the cap has to bind on what is actually sent.
    seen: List[str] = []
    words = 0
    for t in terms:
        if not t or t in seen:
            continue
        n = len(t.split())
        if words + n > 5:
            continue
        seen.append(t)
        words += n
    return " ".join(seen)


def search_github_issues(query: str, repo: str = "pytorch/pytorch",
                         limit: int = 5, timeout: float = 12.0,
                         token: Optional[str] = None) -> DuplicateReport:
    """Search a repository's issues for possible duplicates.

    Uses the public search API. Unauthenticated requests are rate-limited to a
    handful per minute, so a failure here is expected and reported rather than
    raised - a duplicate check that cannot run must not stop a report from
    being written.
    """
    rep = DuplicateReport(query=query, searched=False)
    if not query.strip():
        rep.error = "empty query"
        return rep

    q = f"repo:{repo} is:issue {query}"
    url = ("https://api.github.com/search/issues?"
           + urllib.parse.urlencode({"q": q, "per_page": limit}))
    req = urllib.request.Request(url, headers={
        "Accept": "application/vnd.github+json",
        "User-Agent": "tcd-consistency-harness",
    })
    tok = token or os.environ.get("GITHUB_TOKEN")
    if tok:
        req.add_header("Authorization", f"Bearer {tok}")

    try:
        with urllib.request.urlopen(req, timeout=timeout) as resp:
            data = json.loads(resp.read().decode("utf-8"))
    except urllib.error.HTTPError as e:
        rep.error = (f"HTTP {e.code}"
                     + (" - unauthenticated search is rate limited; set "
                        "GITHUB_TOKEN to raise the limit" if e.code == 403 else ""))
        return rep
    except Exception as e:
        rep.error = f"{type(e).__name__}: {str(e)[:120]}"
        return rep

    rep.searched = True
    for item in (data.get("items") or [])[:limit]:
        rep.candidates.append(Duplicate(
            number=int(item.get("number", 0)),
            title=str(item.get("title", ""))[:160],
            url=str(item.get("html_url", "")),
            state=str(item.get("state", "")),
            score=float(item.get("score", 0.0)),
        ))
    return rep


def render_duplicate_section(rep: DuplicateReport) -> str:
    """The block appended to an issue draft (plan 18.5: flag, do not drop)."""
    if not rep.searched:
        return ("\n## Possible duplicates\n\n"
                f"_Search did not run ({rep.error or 'unknown reason'}). "
                "Check the tracker manually before filing._\n")
    if not rep.candidates:
        return ("\n## Possible duplicates\n\n"
                f"_No open issue matched `{rep.query}`._\n")
    lines = ["\n## Possible duplicates",
             "",
             f"_Searched for `{rep.query}`. **Review these before filing** - the "
             "tool flags candidates, it does not decide._",
             "",
             "| # | state | title |",
             "|---|---|---|"]
    for c in rep.candidates:
        lines.append(f"| [{c.number}]({c.url}) | {c.state} | {c.title} |")
    return "\n".join(lines) + "\n"
