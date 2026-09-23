"""One-off (2026-09-23): add the submission URL and step-by-step "how to post" rows to the five comment drafts, and a how-to section to the README."""
import glob
import os

PLAN = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
ISSUES = os.path.join(os.path.dirname(PLAN), "0920issues")

COMMON = ("① 登录 GitHub 后打开上面的提交网址（`#new_comment_field` 会直接跳到页面最底部的评论框；没跳的话手动滚到底，找 “Add a comment”）；"
          "② 评论框保持在 **Write** 页签，把本文件 `## Comment` 标题**下面**到文件末尾的全部内容原样粘贴进去（不要带 `## Comment` 这一行，也不要带上面这张表）；"
          "③ 点 **Preview** 看一眼：代码块、输出块、行内代码都应正常渲染；"
          "④ 点绿色的 **Comment** 按钮。评论没有标题、标签、模板字段，不需要填别的；"
          "⑤ 发出后点评论右上角的时间戳，复制地址栏里形如 `…/issues/NNNN#issuecomment-XXXXXXXX` 的链接，填到 `README.md` 对应行的“状态”列。")

INFO = {
    "03": ("https://github.com/pytorch/pytorch/issues/143649#new_comment_field",
           "issue 处于 open、未锁定（2026-09-23 核对），任何登录用户都能评论。" + COMMON),
    "04": ("https://github.com/pytorch/pytorch/issues/197554#new_comment_field",
           "issue 处于 open、未锁定（2026-09-23 核对，目前 0 条评论）。**粘贴前先改一处**：正文最后一句里的 `#<fill in after filing 01>` 换成 01 号稿提交后得到的 issue 编号（例如 `#198123`）；如果 01 还没提交，就把最后那一整句删掉再发。" + COMMON),
    "14": ("https://github.com/pytorch/pytorch/issues/191499#new_comment_field",
           "issue 处于 open、未锁定（2026-09-23 核对）。" + COMMON),
    "20": ("https://github.com/pytorch/pytorch/issues/185337#new_comment_field",
           "issue 已 **closed（completed）但未锁定**（2026-09-23 核对），关闭的 issue 照样可以评论；你不是原作者，页面上不会有 Reopen 按钮，所以稿子最后一句是请维护者 reopen。"
           + COMMON + " 如果一两周没人理，再考虑把同样内容作为新 issue 提交并在正文里引用 #185337。"),
    "22": ("https://github.com/pytorch/pytorch/issues/197554#new_comment_field",
           "与 04 号是同一个 issue 下的**第二条**评论：先发 04，隔一会儿（或等有人回复后）再发这条，不要合并成一条——两条主题不同，分开便于维护者逐条建成员。" + COMMON),
}

for num, (url, how) in INFO.items():
    path = glob.glob(os.path.join(ISSUES, num + "-*.md"))[0]
    s = open(path, encoding="utf-8").read()
    if "| **提交网址** |" in s:
        continue
    lines = s.split("\n")
    k = next(i for i, l in enumerate(lines) if l.startswith("| 评论位置 |"))
    lines[k + 1:k + 1] = [f"| **提交网址** | {url} |", f"| **怎么提交（是评论，不是新 issue）** | {how} |"]
    open(path, "w", encoding="utf-8").write("\n".join(lines))
    print("updated", os.path.basename(path))

readme = os.path.join(ISSUES, "README.md")
s = open(readme, encoding="utf-8").read()
if "## 评论稿怎么提交" not in s:
    section = (
        "## 评论稿怎么提交（03、04、14、20、22）\n\n"
        "这五份不是“别人已经把同一个 bug 报过了”，而是 GitHub 上已有一个与之同根因 / 专门收集这类问题的 issue，新开一条大概率被标成 duplicate，所以把我们的新信息作为**评论**发到那条 issue 下面。"
        "每份稿子顶部表格里都有 **提交网址**（带 `#new_comment_field`，打开即跳到评论框）和 **怎么提交** 两行。通用步骤：\n\n"
        "1. 登录 GitHub，打开稿子里的提交网址；页面最底部是 “Add a comment” 评论框。\n"
        "2. 在 **Write** 页签里粘贴稿子中 `## Comment` 标题**下面**到文件末尾的全部内容（不含 `## Comment` 这一行，不含顶部的中文表格）。\n"
        "3. 点 **Preview** 检查渲染，再点绿色 **Comment**。评论没有标题 / 标签 / 模板字段，别的都不用填。\n"
        "4. 点评论右上角的时间戳拿到 `…#issuecomment-…` 链接，记到下表“状态”列。\n\n"
        "| 稿 | 发到哪条 issue | 那条 issue 的状态（2026-09-23） | 特别注意 |\n|---|---|---|---|\n"
        "| 03 | https://github.com/pytorch/pytorch/issues/143649 | open，未锁定 | 无 |\n"
        "| 04 | https://github.com/pytorch/pytorch/issues/197554 | open，未锁定，0 条评论 | 先把最后一句的 `#<fill in after filing 01>` 换成 01 的 issue 号 |\n"
        "| 14 | https://github.com/pytorch/pytorch/issues/191499 | open，未锁定 | 无 |\n"
        "| 20 | https://github.com/pytorch/pytorch/issues/185337 | closed（completed），未锁定，仍可评论 | 你没有 Reopen 按钮，稿子末尾已请维护者 reopen |\n"
        "| 22 | https://github.com/pytorch/pytorch/issues/197554 | 同 04 | 在 04 之后单独发一条，不要与 04 合并 |\n\n")
    s = s.replace("## 这一轮查重后**不报**的", section + "## 这一轮查重后**不报**的", 1)
    open(readme, "w", encoding="utf-8").write(s)
    print("README updated")
