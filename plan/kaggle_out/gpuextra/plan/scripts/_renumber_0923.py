"""One-off (2026-09-23): renumber 0920issues/ by priority, highest first, so the user can file from 01 downwards.

Order respects two dependencies: the #197554 comment needs the issue number of the saved-view report (new 01 before new 04),
and the second #197554 comment goes after the first; the three MSVC reports keep their relative order.
"""
import glob
import os
import re

PLAN = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
ISSUES = os.path.join(os.path.dirname(PLAN), "0920issues")

ORDER = ["01", "14", "19", "04", "16", "06", "15", "21", "08", "12", "05", "02", "09", "07", "22", "23", "17", "18", "03", "10", "11", "20"]   # old numbers, new priority order
MAP = {old: f"{i + 1:02d}" for i, old in enumerate(ORDER)}

files = {os.path.basename(f)[:2]: f for f in glob.glob(os.path.join(ISSUES, "[0-9][0-9]-*.md"))}
assert sorted(files) == sorted(ORDER), (sorted(files), sorted(ORDER))
if os.path.exists(os.path.join(ISSUES, ".renumbered_0923")):
    raise SystemExit("already renumbered")

# explicit cross-references between drafts (found with grep), by OLD file number
XREF = {
    "04": [("#<fill in after filing 01>", "#<fill in after filing %s>" % MAP["01"]), ("第 01 条（保存的视图", "第 %s 条（保存的视图" % MAP["01"])],
    "17": [("16 号的 abs(abs)", "%s 号的 abs(abs)" % MAP["16"]), ("（见 15 号稿）", "（见 %s 号稿）" % MAP["15"])],
    "18": [("（与 16、17 各一张单）", "（与 %s、%s 各一张单）" % (MAP["16"], MAP["17"])), ("16 号 abs(abs) 10 个、17 号", "%s 号 abs(abs) 10 个、%s 号" % (MAP["16"], MAP["17"]))],
    "20": [("与 04 号评论稿同一个伞形 issue；04 讲的是", "与 %s 号评论稿同一个伞形 issue；%s 讲的是" % (MAP["04"], MAP["04"])), ("先发 04）", "先发 %s）" % MAP["04"])],
}

# 1. edit contents, 2. rename through temporary names
for old, path in files.items():
    s = open(path, encoding="utf-8").read()
    lines = s.split("\n")
    lines[1] = re.sub(r"(0920 issue |0920 第 )%s\b" % old, lambda m: m.group(1) + MAP[old], lines[1])
    s = "\n".join(lines)
    for a, b in XREF.get(old, []):
        assert a in s, (old, a)
        s = s.replace(a, b)
    open(path, "w", encoding="utf-8").write(s)
for old, path in files.items():
    os.rename(path, os.path.join(ISSUES, "tmp_" + os.path.basename(path)))
for old, path in files.items():
    base = os.path.basename(path)
    os.rename(os.path.join(ISSUES, "tmp_" + base), os.path.join(ISSUES, MAP[old] + base[2:]))

# README: renumber the table rows, sort them, replace the order line, add the old->new map
readme = os.path.join(ISSUES, "README.md")
s = open(readme, encoding="utf-8").read()
rows = re.findall(r"^\| \d\d \|.*\n", s, re.M)
first, last = s.index(rows[0]), s.index(rows[-1]) + len(rows[-1])
new_rows = []
for r in rows:
    old = r[2:4]
    r = "| " + MAP[old] + r[4:]
    r = r.replace("（04 之后）", "（%s 之后）" % MAP["04"])
    new_rows.append(r)
new_rows.sort(key=lambda r: r[2:4])
s = s[:first] + "".join(new_rows) + s[last:]
s = re.sub(r"^建议提交顺序：.*$",
           "**编号即提交顺序（2026-09-23 按优先级从高到低重排，从 01 开始往下提交即可）。** 三个依赖已体现在编号里：%s（#197554 评论）最后一句要填 01 提交后得到的 issue 号；%s（#197554 第二条评论）排在 %s 之后；%s–%s–%s 是微软 Developer Community 的三张单（不是 GitHub，需微软账号，%s 和 %s 优先级低于 %s 所以排在后面）。\n\n"
           "旧编号 → 新编号：" % (MAP["04"], MAP["20"], MAP["04"], MAP["16"], MAP["17"], MAP["18"], MAP["17"], MAP["18"], MAP["16"])
           + "、".join(f"{o}→{MAP[o]}" for o in sorted(MAP)) + "（旧 13 已删除：他人已报 #197434）。`plan/` 下的台账、执行报告、记忆里 2026-09-23 之前的条目用的是旧编号。",
           s, count=1, flags=re.M)
# other mentions of draft numbers in the README notes ("已作为 15 号稿的一句附注", "即 10 号评论稿", "并入 20 号", "16、17、18 的来源" ...)
def renum_note(m):
    return m.group(1) + MAP.get(m.group(2), m.group(2)) + m.group(3)
s = re.sub(r"(已作为 )(\d\d)( 号稿)", renum_note, s)
s = re.sub(r"(即 )(\d\d)( 号评论稿)", renum_note, s)
s = re.sub(r"(并入 )(\d\d)( 号)", renum_note, s)
s = re.sub(r"(重新发现 )(\d\d)( 号)", renum_note, s)
s = re.sub(r"(说明 )(\d\d)–(\d\d)( 是 MSVC 特有)", lambda m: "说明 %s、%s、%s 是 MSVC 特有" % (MAP["16"], MAP["17"], MAP["18"]), s)
def renum_list(m):
    nums = re.findall(r"\d\d", m.group(1))
    return "、".join(MAP.get(n, n) for n in nums) + m.group(2)
s = re.sub(r"((?:\d\d、)*\d\d)( 的来源| 的独立复现)", renum_list, s)
s = re.sub(r"(；)(\d\d)( 就是它发现的| 的来源)", renum_note, s)
s = re.sub(r"(\d\d)–(\d\d)( 的独立复现)", lambda m: "%s 等" % "、".join(MAP[o] for o in ("19", "20", "21", "22", "23")) + m.group(3), s)
open(readme, "w", encoding="utf-8").write(s)
open(os.path.join(ISSUES, ".renumbered_0923"), "w").write("old->new: " + ", ".join(f"{o}->{MAP[o]}" for o in sorted(MAP)) + "\n")

# ledger: file pointers
ledger = os.path.join(PLAN, "TO_SUBMIT.md")
t = open(ledger, encoding="utf-8").read()
t = re.sub(r"0920issues/(\d\d)-\*\.md", lambda m: "0920issues/%s-*.md" % MAP.get(m.group(1), m.group(1)), t)
t = t.replace("**台账 43 终态（2026-09-23）**",
              "**2026-09-23 重新编号**：`0920issues/` 按优先级从高到低重排，编号即提交顺序；本文件里的 `0920issues/NN-*.md` 指针已换成新编号，正文叙述里的“草稿 NN”仍是旧编号（旧→新：" + "、".join(f"{o}→{MAP[o]}" for o in sorted(MAP)) + "）。\n\n**台账 43 终态（2026-09-23）**", 1)
open(ledger, "w", encoding="utf-8").write(t)

rep = os.path.join(PLAN, "EXECUTION_REPORT.md")
r = open(rep, encoding="utf-8").read()
marker = re.search(r"\*\*当前断点（2026-09-22 深夜）\*\*：", r)
assert marker
r = r[:marker.start()] + ("**当前断点（2026-09-23）**：用户指示删除草稿 13（他人已报 #197434），并要求把 `0920issues/` 按优先级从高到低重新编号、从 01 开始依次提交 → 已完成（`scripts/_renumber_0923.py`；旧→新：" + "、".join(f"{o}→{MAP[o]}" for o in sorted(MAP)) + "；README 顶部有同一张映射表）。**下文历史断点里的“草稿 NN”都是旧编号。** 后台：`scalar_arg_sequence_diff.py`（release + nightly，`results/scalar_seq/`）、Kaggle `tcc-int32gpu`（32 位索引边界）。\n\n**历史断点（2026-09-22 深夜）**：") + r[marker.end():]
open(rep, "w", encoding="utf-8").write(r)

mem = r"C:\Users\clm\.claude\projects\d--wsl-personal-dr-paper\memory\tcc-plan-status.md"
m = open(mem, encoding="utf-8").read()
line = ("- 2026-09-23: on the user's instruction 0920issues/ was RENUMBERED by priority (file number = filing order, user files from 01 downwards). old->new: "
        + ", ".join(f"{o}->{MAP[o]}" for o in sorted(MAP)) + ". Entries above this line use the OLD numbers. Future new drafts: insert by priority and keep numbers = filing order (ask before renumbering drafts the user may already have filed).\n")
if line not in m:
    open(mem, "w", encoding="utf-8").write(m + line)
print("renumbered:", ", ".join(f"{o}->{MAP[o]}" for o in ORDER))
