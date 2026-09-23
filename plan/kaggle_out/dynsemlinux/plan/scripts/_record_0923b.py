"""One-off bookkeeping (2026-09-23 evening): new high-priority draft 02b (stale Python float baked into a cached graph), Summary audit, comment how-to."""
import os
import re

PLAN = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
ISSUES = os.path.join(os.path.dirname(PLAN), "0920issues")

readme = os.path.join(ISSUES, "README.md")
s = open(readme, encoding="utf-8").read()
if "| 02b |" not in s:
    row02 = re.search(r"^\| 02 \|.*\n", s, re.M).group(0)
    s = s.replace(row02, row02 +
        "| 02b | pytorch/pytorch | 新 issue | **变化的 Python float 实参被烤进缓存图（#194976 的残留）**：`f(x, s)` 里 `s` 既有 `x * s` 这样的用法、它的表达式又传给算子的浮点形参时，默认配置的 torch.compile 从第三个取值起一直沿用第二个取值算出的参数；nightly 上 51 个算子里 18 个中招：rms/layer/group/batch/instance_norm 的 eps、batch_norm momentum、huber delta、smooth_l1 beta、label_smoothing、triplet margin、cdist/pairwise p、quantile q、SDPA scale、**`interpolate(scale_factor=…)` 连输出形状都是旧的**；2.14.0 与 nightly 0921、Win/Linux、CPU/CUDA 全复现；关掉 FX 图缓存或 AOTAutograd 缓存任一个即正确；根因已用日志钉死（fake-tensor 传播时特化 → ShapeEnv 守卫被缓存键丢弃） | **高**（默认配置静默错值/错形状） | 待提交（**紧接 02 之后**；编号 02b 是为了不打乱你已在用的编号） |\n", 1)
s = s.replace("**编号即提交顺序（2026-09-23 按优先级从高到低重排，从 01 开始往下提交即可）。**",
              "**编号即提交顺序（2026-09-23 按优先级从高到低重排，从 01 开始往下提交即可；之后新发现的高优先级稿用字母后缀插队，如 `02b` 排在 02 与 03 之间）。**", 1)
if "scalar_arg_sequence_diff.py" not in s:
    s = s.rstrip("\n") + "\n| `scripts/scalar_arg_sequence_diff.py` | 10.9b：100 个程序，Python float / int 实参逐次变化（静态首调 → 自动动态重编译 → 重复值 → 0/1/负数），默认缓存 + 每例全新缓存目录，每次调用都与 eager 比；release 与 nightly 各跑一份（`results/scalar_seq/{release,nightly}.jsonl`）；02b 的来源 |\n"
open(readme, "w", encoding="utf-8").write(s)


def edit(path, old, new):
    t = open(path, encoding="utf-8").read()
    if new in t:
        return
    assert old in t, (path, old[:50])
    open(path, "w", encoding="utf-8").write(t.replace(old, new, 1))


edit(os.path.join(PLAN, "TO_SUBMIT.md"),
     "**2026-09-23 重新编号**",
     "| 54 | **变化的 Python float 实参被烤进缓存图（#194976 残留）**：norm eps / huber delta / label_smoothing / SDPA scale / cdist p / `interpolate(scale_factor)`（错形状）等 18 个算子 | **待提交（高）**（10.9b `scalar_arg_sequence_diff.py`） | `0920issues/02b-*.md`；`reports_scalar_seq/`（普查、最小复现、缓存 2×2） | 无同报告；相关 #194976（closed）、修复 #195040（已在 nightly）、#194817（open PR，仅 SDPA） | Dynamo 图保留符号表达式，fake-tensor 传播特化并记 ShapeEnv 守卫，AOT 烤入常量；重编译得到同一张 Dynamo 图 → AOTAutogradCache 命中旧产物。2.14.0 + nightly 0921，Win/Linux，CPU/CUDA |\n\n"
     "**2026-09-23 重新编号**")
edit(os.path.join(PLAN, "EXECUTION_REPORT.md"),
     "**2026-09-23 补充**：",
     "**2026-09-23 晚**：10.9b `scalar_arg_sequence_diff.py` 在 nightly 上发现 #194976 的残留 → **新草稿 02b（高）**：变化的 Python float 被烤进缓存图，18 个算子中招（含 `interpolate` 错形状）；2.14 + nightly 0921、Win/Linux、CPU/CUDA 都已复核，根因用 `TORCH_LOGS=graph_code,aot_graphs,recompiles` 钉死。release / nightly 两份全量扫描仍在后台跑（`results/scalar_seq/`），跑完看 `--report`：release 上出错的程序预计几十个（都属已修的 #194976，不单独报），nightly 上除 02b 外若还有别的差异需要分诊。\n\n"
     "**2026-09-23 补充**：")
mem = r"C:\Users\clm\.claude\projects\d--wsl-personal-dr-paper\memory\tcc-plan-status.md"
t = open(mem, encoding="utf-8").read()
line = ("- 2026-09-23 evening: new HIGH draft 0920issues/02b (file right after 02): a Python float argument that changes between calls is baked into the cached graph (residual of closed #194976 / fix #195040): "
        "norm eps, huber delta, label_smoothing, SDPA scale, cdist p, interpolate scale_factor (wrong SHAPE) ... 18 of 51 ops on nightly; default config only (either cache off -> correct); 2.14.0 + nightly 0921, Win/Linux, CPU/CUDA. "
        "Found by scripts/scalar_arg_sequence_diff.py (release + nightly runs in results/scalar_seq/). Also today: draft 13 deleted, drafts renumbered by priority (letter suffix for later insertions), comment drafts got a submission URL + how-to, "
        "all Summaries audited against SUMMARY_WRITING_GUIDE.md ([[issue-summary-writing-guide]]). 32-bit indexing boundary on T4: clean. Nothing filed by me.\n")
if line not in t:
    open(mem, "w", encoding="utf-8").write(t + line)
print("recorded")
