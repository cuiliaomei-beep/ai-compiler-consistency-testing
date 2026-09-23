"""Record that a draft of 0920issues/ has been filed by the user.

    python scripts/mark_filed.py 01 https://github.com/pytorch/pytorch/issues/198123
    python scripts/mark_filed.py 04 https://github.com/pytorch/pytorch/issues/197554#issuecomment-3312345678
    python scripts/mark_filed.py --status                # what is filed / what is next

Effects: README "状态" column of that row, a line in 0920issues/FILED.md (number, kind, url, date: the list the paper's
statistics are built from), and -- when 01 is recorded -- the placeholder `#<fill in after filing 01>` in draft 04 is
replaced by the real issue number.
"""
import datetime
import glob
import os
import re
import sys

PLAN = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
ISSUES = os.path.join(os.path.dirname(PLAN), "0920issues")
README = os.path.join(ISSUES, "README.md")
FILED = os.path.join(ISSUES, "FILED.md")
HEADER = "# 已提交记录（论文统计用）\n\n| 稿 | 类型 | 目标 | 链接 | 提交日期 | 后续状态（confirmed / fixed / closed …） |\n|---|---|---|---|---|---|\n"


def rows():
    s = open(README, encoding="utf-8").read()
    nums = re.findall(r"^\| (\d\d[a-z]?) \|", s, re.M)
    return s, list(dict.fromkeys(nums))          # the how-to table repeats the comment drafts; the main table comes first


def status():
    s, nums = rows()
    for n in nums:
        row = re.search(r"^\| %s \|.*$" % n, s, re.M).group(0)
        cells = [c.strip() for c in row.strip("|").split("|")]
        print(n, "|", cells[1][:24], "|", cells[2][:22], "|", cells[-1][:90])


def main():
    if len(sys.argv) == 2 and sys.argv[1] == "--status":
        return status()
    num, url = sys.argv[1], sys.argv[2].strip()
    assert re.match(r"^https://", url), url
    s, nums = rows()
    assert num in nums, (num, nums)
    row = re.search(r"^\| %s \|.*$" % num, s, re.M).group(0)
    cells = row.strip().strip("|").split("|")
    kind = "评论" if "issuecomment" in url else ("反馈" if "developercommunity" in url else "issue")
    m = re.search(r"/issues/(\d+)", url)
    label = (f"已评论 #{m.group(1)}" if kind == "评论" else f"已提交 #{m.group(1)}") if m else "已提交"
    today = datetime.date.today().isoformat()
    cells[-1] = f" **{label}**（{today}）{url} "
    s = s.replace(row, "|" + "|".join(cells) + "|")
    open(README, "w", encoding="utf-8").write(s)

    if not os.path.exists(FILED):
        open(FILED, "w", encoding="utf-8").write(HEADER)
    f = open(FILED, encoding="utf-8").read()
    target = cells[1].strip()
    line = f"| {num} | {kind} | {target} | {url} | {today} |  |\n"
    if url not in f:
        open(FILED, "w", encoding="utf-8").write(f + line)

    if num == "01" and m:
        for p in glob.glob(os.path.join(ISSUES, "04-*.md")):
            t = open(p, encoding="utf-8").read()
            if "#<fill in after filing 01>" in t:
                open(p, "w", encoding="utf-8").write(t.replace("#<fill in after filing 01>", "#" + m.group(1)))
                print("draft 04: placeholder replaced by #" + m.group(1))
    print("recorded", num, label, url)


if __name__ == "__main__":
    main()
