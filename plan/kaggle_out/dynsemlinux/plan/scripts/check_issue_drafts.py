"""Mechanical check of issue drafts before they are handed to the user.  Run it on every batch:

    python scripts/check_issue_drafts.py                      # ../0920issues
    python scripts/check_issue_drafts.py ../0913issues

Rules (see D:\\wsl\\personal\\dr\\paper\\CLAUDE.md and SUMMARY_WRITING_GUIDE.md):
  * Title: one line, at most 256 characters (GitHub rejects longer titles); warn above 200.
  * New-issue drafts (`## Body`): a `**Summary.**` paragraph of exactly three sentences, at most 130 words, third sentence
    starts with "Because", no weakening / inflating words, no first person plural.
  * Comment drafts (`## Comment`): no Summary required; they must carry the submission URL row.
  * No leftover placeholders ("结果出来后补一句", "<fill in").
Exit code 1 if any rule is violated.
"""
import glob
import os
import re
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
folder = os.path.abspath(sys.argv[1]) if len(sys.argv) > 1 else os.path.join(os.path.dirname(os.path.dirname(HERE)), "0920issues")
WEAK = r"\b(seems?|might|I think|we|our|critical|severe|dangerous|malicious|attack|probably|perhaps|appears? to|likely)\b"
bad = 0
for f in sorted(glob.glob(os.path.join(folder, "[0-9][0-9]*-*.md"))):
    s = open(f, encoding="utf-8").read()
    name = os.path.basename(f)
    tag = name.split("-")[0]
    problems, notes = [], []
    is_comment = "## Comment" in s and "## Body" not in s
    if not is_comment:
        m = re.search(r"## Title\s*\n\s*\n(.+?)\n", s)
        if not m:
            problems.append("no ## Title")
        else:
            n = len(m.group(1).strip())
            if n > 256:
                problems.append(f"title {n} chars > 256 (GitHub limit)")
            elif n > 200:
                notes.append(f"title {n} chars (ok, but long)")
        sm = re.search(r"\*\*Summary\.\*\* (.*?)\n\n", s, re.S)
        if not sm:
            problems.append("no **Summary.** paragraph")
        else:
            para = sm.group(1).strip()
            t = re.sub(r"\([^()]*\)", "P", re.sub(r"`[^`]*`", "C", para))
            sents = [x for x in re.split(r"(?<=\.)\s+(?=[A-Z])", t) if x.strip()]
            words = len(para.split())
            if words > 130:
                problems.append(f"Summary {words} words > 130")
            if len(sents) != 3:
                problems.append(f"Summary has {len(sents)} sentences, not 3")
            elif not sents[2].startswith("Because"):
                problems.append("third Summary sentence does not start with 'Because'")
            w = re.findall(WEAK, para, re.I)
            if w:
                problems.append(f"Summary uses {sorted(set(x.lower() for x in w))}")
    else:
        if "**提交网址**" not in s:
            problems.append("comment draft without the 提交网址 row")
    body = s.split("---", 1)[-1]
    if not is_comment:   # the GitHub form fields the draft must fill (missed once: draft 28 had no "Error logs" section)
        m = re.search(r"github\.com/pytorch/pytorch/issues/new\?template=([\w.-]+)", s)
        need = {"pt2-bug-report.yml": ("### 🐛 Describe the bug", "### Error logs", "### Versions"), "bug-report.yml": ("### 🐛 Describe the bug", "### Versions")}
        if m and m.group(1) in need:
            for sec in need[m.group(1)]:
                if sec not in body:
                    problems.append(f"template {m.group(1)} needs a '{sec}' section")
    for ph in ("结果出来后补一句", "<fill in"):
        if ph in s:
            (problems if ph in body else notes).append(f"placeholder left: {ph}")
    bad += bool(problems)
    print(f"{tag:4s} {'COMMENT' if is_comment else 'ISSUE  '} {'FAIL: ' + '; '.join(problems) if problems else 'ok'}{'   [' + '; '.join(notes) + ']' if notes else ''}")
print("\nall drafts pass" if not bad else f"\n{bad} draft(s) FAIL")
sys.exit(1 if bad else 0)
