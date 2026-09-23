"""One-off: the records written in this session carry the dates 2026-09-22 / 2026-09-23, but the machine date never left 2026-09-21
(the labels were guessed from the amount of work, not read from the clock).  Put the real date back everywhere.
Version strings such as 2.15.0.dev20260921 are real and are not touched (different format)."""
import glob
import os
import re

ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
MEM = r"C:\Users\clm\.claude\projects\d--wsl-personal-dr-paper\memory"
files = (glob.glob(os.path.join(ROOT, "0920issues", "*.md"))
         + [os.path.join(ROOT, "plan", n) for n in ("TO_SUBMIT.md", "EXECUTION_REPORT.md", "NEXT_DIRECTIONS.md")]
         + glob.glob(os.path.join(MEM, "*.md")))
NOTE = "（注：本会话里曾把后半段工作误标为 09-22 / 09-23，实际机器日期一直是 2026-09-21；下面“凌晨 / 上午 / 中午 / 晚 / 夜 / 深夜”只表示先后顺序，不是真实钟点。脚本文件名里的 0922 / 0923 同理。）"
total = 0
for p in files:
    s = open(p, encoding="utf-8").read()
    t = re.sub(r"2026-09-2[23]", "2026-09-21", s)
    t = re.sub(r"(?<![\d-])09-2[23](?![\d])", "09-21", t)
    if p.endswith("EXECUTION_REPORT.md") and NOTE not in t:
        i = t.find("**当前断点（2026-09-21")
        if i >= 0:
            t = t[:i] + NOTE + "\n\n" + t[i:]
    if t != s:
        n = len(re.findall(r"2026-09-2[23]|(?<![\d-])09-2[23](?![\d])", s))
        total += n
        open(p, "w", encoding="utf-8").write(t)
        print(f"{n:3d} fixed in {os.path.relpath(p, ROOT) if p.startswith(ROOT) else os.path.basename(p)}")
print("total", total)
