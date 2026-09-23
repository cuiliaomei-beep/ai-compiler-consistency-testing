"""Build toxic_compile/ISSUE_OUTCOMES.md (the record the paper's numbers come from) out of
results/issue_status/raw.json (refresh it first with scripts/issue_status_report.py) plus the hand-made verdicts below.

A verdict is only as strong as its evidence, which is quoted in the table:
  FIXED      closed as completed by a landed pull request that says "Fixes #N"
  CONFIRMED  a PyTorch maintainer / member engaged with it as a real defect (human triage by a team member, assignment,
             "tracked under ...", invitation to send a fix)
  REPRODUCED someone else reproduced / root-caused it or opened a fix PR, but no maintainer has spoken yet
  DISPUTED   a maintainer considers the behaviour expected
  NO RESPONSE only bot labels so far  (note: on pytorch/pytorch the `triaged` label is often put by github-actions[bot];
             it counts as human triage only when the timeline shows a team member applied it)
"""
import datetime
import json
import os

PLAN = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
ROOT = os.path.dirname(PLAN)
rows = json.load(open(os.path.join(PLAN, "results", "issue_status", "raw.json"), encoding="utf-8"))

VERDICT = {   # issue number -> (verdict, evidence)
    197101: ("FIXED", "PR #197221 “Fixes #197101” landed as c8e4ab54e0 (2026-09-17); human-triaged by williamwen42 (`triaged`, `dynamo-triaged`)"),
    197104: ("FIXED", "PR #197128 by maintainer yushangdi landed as bc77d149b7 (2026-09-16); issue was assigned to yushangdi"),
    197085: ("CONFIRMED", "human-triaged by williamwen42, who also added `module: correctness (silent)`; fix PR #197768 open (“Fixes”)"),
    197088: ("CONFIRMED", "assigned to contributor oonyshch (“Taking a look”, 2026-09-17)"),
    197094: ("CONFIRMED", "williamwen42 (MEMBER) triaged it, added `has workaround`, cc'd and assigned hameerabbasi"),
    197095: ("CONFIRMED", "malfet (core maintainer): “eager raises correctly and the compiled path bypasses it”; made a member of his umbrella #197554 “[PT2] Validation lost”; yashb98 volunteered a fix"),
    197110: ("CONFIRMED", "human-triaged by williamwen42, who told a volunteer “feel free to open a PR”; fix PR #197443 open"),
    197091: ("REPRODUCED", "fix PR #197162 open (“Fixes”), no maintainer comment yet"),
    197093: ("REPRODUCED", "tsho reproduced it on 2.14.0 and a source build and located the cause (`LazySymNodeFormatString.__repr__`); waits for the `actionable` label before sending a PR"),
    197097: ("REPRODUCED", "fix PR #197231 open (“Fixes”)"),
    197099: ("REPRODUCED", "fix PR #197152 open (“Fixes”)"),
    197105: ("REPRODUCED", "contributor N0AHZACH took it; fix PR #197193 open"),
    197107: ("REPRODUCED", "two volunteers; fix PR #197214 open"),
    197108: ("REPRODUCED", "contributor he-yufeng root-caused it to the Welford lowering path; fix PR #197165 open"),
    197112: ("REPRODUCED", "DannyChee1 reproduced it on nightly 2.15.0.dev20260915 and traced it to `exact_dtype=True` on the `abs` ref (#140288)"),
    197096: ("DISPUTED", "yushangdi (AOTI maintainer): “kinda expected behavior” — mutation of lifted constants is unsupported after functionalization; still open"),
    # --- updates 2026-09-22 (morning refresh)
    197109: ("CONFIRMED", "eellison (maintainer) diagnosed it (“This is due to the decomp not preserving channels last”), retitled it “[Fake Tensor/Decomps] …” and added `module: fakeTensor`, `module: decompositions`"),
    197087: ("REPRODUCED", "chinmayirm located the cause (index expression printed with Python `str()`, `**` reaches the C++ kernel); no maintainer comment yet"),
    197888: ("CONFIRMED", "eellison added `high priority` and the issue was assigned to mlazos within a day; a volunteer offered a fix"),
    197896: ("CONFIRMED", "ezyang (core maintainer) added `actionable`; syerva-g posted a root-cause analysis and opened fix PR #198055 (“Fixes”; closed and reopened, open as of 2026-09-23)"),
    197887: ("REPRODUCED", "fix PR #198035 “[aot_autograd] Restore version checks for saved input views” open (“Fixes”); chinmayirm confirmed the `_reinterpret_tensor` / version-counter analysis"),
    197893: ("REPRODUCED", "chinmayirm confirmed the root cause in `joint_graph.remove_no_ops` and volunteered; no maintainer comment yet"),
    197894: ("REPRODUCED", "fix PR #198053 “Fix FX codegen precedence for negative pow bases” open (“Fixes”, by buyan-kh); a second volunteer asked to be assigned"),
    197895: ("REPRODUCED", "chinmayirm confirmed the `floor(div_rn(a, b))` analysis and volunteered"),
    40840: ("CONFIRMED", "JAX maintainer jakevdp self-assigned, thanked for the report and noted the same bug in NumPy (< 2.4.0 for gcd, still present for lcm in 2.5.3); fix PR #40842 open with a regression test"),
}
DRAFT_OVERRIDE = {197109: "0913/25"}   # titles edited by maintainers no longer match the local draft
EXTRA = [   # filed items that are not issues of the user's account in these repos
    ("0920/03", "pytorch/pytorch", "comment under #143649", "https://github.com/pytorch/pytorch/issues/143649#issuecomment-5761796627", "2026-09-21", "NO RESPONSE", "no reply yet"),
    ("0920/04", "pytorch/pytorch", "comment under #197554", "https://github.com/pytorch/pytorch/issues/197554#issuecomment-5761854781", "2026-09-21", "NO RESPONSE", "no reply yet"),
    ("0920/05", "Microsoft Visual C++", "Developer Community 11155532", "https://developercommunity.visualstudio.com/t/MSVC-x64-optimizer-folds-two-consecutive/11155532", "2026-09-21", "NO RESPONSE", "status: new"),
    ("0920/17", "Microsoft Visual C++", "Developer Community 11155535", "https://developercommunity.visualstudio.com/t/MSVC-x64-optimizer-removes-_mm_add_psx/11155535", "2026-09-21", "NO RESPONSE", "status: new"),
    ("0920/18", "Microsoft Visual C++", "Developer Community 11155537", "https://developercommunity.visualstudio.com/t/MSVC-x64-optimizer-folds-compare-and-ble/11155537", "2026-09-21", "NO RESPONSE", "status: new"),
    ("0920/14", "pytorch/pytorch", "comment under #191499", "https://github.com/pytorch/pytorch/issues/191499#issuecomment-5769459765", "2026-09-22", "NO RESPONSE", "no reply yet"),
    ("0920/20", "pytorch/pytorch", "comment under #185337 (closed)", "https://github.com/pytorch/pytorch/issues/185337#issuecomment-5769623200", "2026-09-22", "NO RESPONSE", "no reply yet; asked for reopen"),
    ("0920/22", "pytorch/pytorch", "second comment under #197554", "https://github.com/pytorch/pytorch/issues/197554#issuecomment-5769650186", "2026-09-22", "NO RESPONSE", "no reply yet"),
    ("0920/24", "pytorch/pytorch", "comment under #174386 (closed)", "https://github.com/pytorch/pytorch/issues/174386#issuecomment-5769669193", "2026-09-22", "NO RESPONSE", "no reply yet; asked for reopen"),
    ("0920/25", "pytorch/pytorch", "comment under own #197889", "https://github.com/pytorch/pytorch/issues/197889#issuecomment-5769751990", "2026-09-22", "NO RESPONSE", "supplement to own issue"),
    ("0920/27", "pytorch/pytorch", "comment under #183607", "https://github.com/pytorch/pytorch/issues/183607#issuecomment-5769757314", "2026-09-22", "NO RESPONSE", "no reply yet"),
    ("0920/29", "pytorch/pytorch", "third comment under #197554", "https://github.com/pytorch/pytorch/issues/197554#issuecomment-5770289099", "2026-09-22", "NO RESPONSE", "no reply yet"),
    ("0920/30", "pytorch/pytorch", "comment under own #198071", "https://github.com/pytorch/pytorch/issues/198071#issuecomment-5770296071", "2026-09-22", "NO RESPONSE", "supplement to own issue"),
    ("0920/32", "pytorch/pytorch", "correction comment under own #197084", "https://github.com/pytorch/pytorch/issues/197084#issuecomment-5770677350", "2026-09-22", "NO RESPONSE", "points to #198118 as the root cause"),
    ("0920/37", "pytorch/pytorch", "comment under own #198155 (CUDA numbers)", "https://github.com/pytorch/pytorch/issues/198155#issuecomment-5773214257", "2026-09-22", "NO RESPONSE", "supplement to own issue"),
    ("0920/38", "pytorch/pytorch", "comment under own #198118 (lstsq backward, FlopCounterMode)", "https://github.com/pytorch/pytorch/issues/198118#issuecomment-5773243640", "2026-09-22", "NO RESPONSE", "supplement to own issue"),
    ("0920/41b", "pytorch/pytorch", "comment under own #198190 (trigger condition, iterator family)", "https://github.com/pytorch/pytorch/issues/198190#issuecomment-5776320367", "2026-09-22", "NO RESPONSE", "supplement to own issue"),
    ("0920/42b", "pytorch/pytorch", "comment under own #198192 (handler shapes)", "https://github.com/pytorch/pytorch/issues/198192#issuecomment-5778031868", "2026-09-22", "NO RESPONSE", "supplement to own issue"),
]

now = datetime.datetime.now().strftime("%Y-%m-%d %H:%M")
out = [f"# Outcome of every filed issue (both rounds) — snapshot {now}", "",
       "Regenerate: `python scripts/issue_status_report.py && python scripts/issue_outcomes.py` (read-only GitHub queries). Raw data: `plan/results/issue_status/raw.json`.",
       "Verdict definitions are at the top of `plan/scripts/issue_outcomes.py`; every verdict quotes its evidence. "
       "On pytorch/pytorch the `triaged` label is frequently applied by `github-actions[bot]`, so a label alone is **not** counted as confirmation.", ""]
table, count = [], {}
for r in rows:
    v, ev = VERDICT.get(r["number"], ("NO RESPONSE", "only bot-applied labels / no human reaction yet"))
    rnd = "round 1 (0913)" if r["created"] < "2026-09-20" else "round 2 (0920)"
    count.setdefault(rnd, {}).setdefault(v, []).append(f"#{r['number']}")
    r["draft"] = DRAFT_OVERRIDE.get(r["number"], r["draft"])
    table.append(f"| {r['draft']} | {r['repo']} #{r['number']} | {r['created']} | {r['state']}{' (' + r['reason'] + ')' if r['reason'] else ''} | **{v}** | {ev} | {r['title'][:110].replace('|', '¦')} |")
for d, repo, what, url, date, v, ev in EXTRA:
    count.setdefault("round 2 (0920)", {}).setdefault(v, []).append(what)
    table.append(f"| {d} | {repo} | {date} | open | **{v}** | {ev} | {what}: {url} |")

# ---- 论文口径（用户 2026-09-23 定，见 CLAUDE.md）：四档，按顺序判定，为 0 的档不列 ----
def bucket(v, ev, prs):
    has_fix_pr = any(p.get("fixes") and p.get("state") in ("open", "merged") for p in (prs or [])) or ("fix PR #" in ev and "closed the same day" not in ev)
    if v == "FIXED" or has_fix_pr:
        return "已修复"
    if v in ("CONFIRMED", "REPRODUCED"):
        return "已确认"
    if v == "DISPUTED":
        return "拒绝"
    return "Pending"

paper = {}
for r in rows:
    v, ev = VERDICT.get(r["number"], ("NO RESPONSE", ""))
    rnd = "round 1 (0913)" if r["created"] < "2026-09-20" else "round 2 (0920)"
    paper.setdefault(rnd, {}).setdefault(bucket(v, ev, r.get("prs")), []).append(f"#{r['number']}")
for d, repo, what, url, date, v, ev in EXTRA:
    paper.setdefault("round 2 (0920)", {}).setdefault(bucket(v, ev, None), []).append(what)
ORDER_ALL = ("已修复", "已确认", "Pending", "拒绝")
ORDER = tuple(b for b in ORDER_ALL if any(paper[r].get(b) for r in paper))  # 为 0 的档不列
out += ["## 论文口径（四档：已修复 = 已合入或已有开发者提交修复 PR；已确认 = 维护者口头确认或有人复现；Pending = 尚无人工回应；拒绝 = 维护者认为是预期行为。为 0 的档不列。）", ""]
out += ["| 轮次 | 提交 | " + " | ".join(ORDER) + " |", "|---|---|" + "---|" * len(ORDER)]
tot = {}
for rnd in sorted(paper):
    n = sum(len(x) for x in paper[rnd].values())
    out.append(f"| {rnd} | {n} | " + " | ".join(str(len(paper[rnd].get(b, []))) or "" for b in ORDER) + " |")
    for b in ORDER:
        tot[b] = tot.get(b, 0) + len(paper[rnd].get(b, []))
out.append(f"| 合计 | {sum(tot.values())} | " + " | ".join(str(tot[b]) for b in ORDER) + " |")
out.append("")
for rnd in sorted(paper):
    for b in ORDER:
        if paper[rnd].get(b):
            out.append(f"- {rnd} {b}（{len(paper[rnd][b])}）：{', '.join(paper[rnd][b])}")
out.append("")
out += ["## Counts", ""]
for rnd in sorted(count):
    total = sum(len(x) for x in count[rnd].values())
    out.append(f"**{rnd}: {total} filed**")
    for v in ("FIXED", "CONFIRMED", "REPRODUCED", "DISPUTED", "NO RESPONSE"):
        if v in count[rnd]:
            out.append(f"- {v}: {len(count[rnd][v])} — {', '.join(count[rnd][v])}")
    out.append("")
r1 = count.get("round 1 (0913)", {})
fixed, conf, rep = len(r1.get("FIXED", [])), len(r1.get("CONFIRMED", [])), len(r1.get("REPRODUCED", []))
out += [f"Round 1 in the paper's terms: {fixed} fixed; {fixed + conf} confirmed by maintainers (fixed + CONFIRMED); "
        f"{fixed + conf + rep} confirmed if independent reproductions / open fix PRs are included; {len([p for r in rows for p in r['prs'] if p['fixes'] and p['state'] == 'open'])} fix PRs are open and would raise the fixed count when they land.", "",
        "**Paper numbers come only from the 论文口径 table above (four buckets fixed by the user on 2026-09-23).**", "",
        "## All items", "", "| draft | issue | filed | state | verdict | evidence | title |", "|---|---|---|---|---|---|---|"] + table
open(os.path.join(ROOT, "ISSUE_OUTCOMES.md"), "w", encoding="utf-8").write("\n".join(out) + "\n")
print("\n".join(out[5:5 + 22]))
