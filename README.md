# Consistency Testing of AI Compiler Stacks by Varying the Compilation

本仓库收录这项研究的全部材料：检测工具源代码、实验数据与运行记录、向 PyTorch 等项目提交的 issue 稿件，以及论文的 LaTeX 工程。研究对象是 `torch.compile`：同一份 Python 源码在 eager 执行与编译执行之间出现可观察的不一致（源码–制品一致性失效）。方法的核心是在程序不变的前提下逐个改变编译方式（graph break 位置、后端层、执行上下文、制品路径），与源码和算子元数据推导出的程序侧因子一起构成单因子执行矩阵，用七类可观察量比较，并按编译层归因。

仓库为私有，仅对受邀成员开放。

## 目录总览

| 路径 | 内容 |
|---|---|
| [`paper_tcc/`](paper_tcc/) | 论文 LaTeX 工程（ACM acmsmall 双盲送审版）与编译好的 `main.pdf` |
| [`plan/`](plan/) | 检测工具 `tcc` 的源代码、实验脚本、全部实验结果与研究台账 |
| [`issues/`](issues/) | 两批 issue 稿件（Markdown），每篇含复现代码、真实输出和查重记录 |
| [`harness/`](harness/) | 早期的最小闭环实现 `tcd`（研究计划 v2.1 的 M1 里程碑），保留作对照 |
| [`docs/`](docs/) | 研究计划、过程记录、阶段汇报、issue 摘要写作规范 |
| [`ISSUE_OUTCOMES.md`](ISSUE_OUTCOMES.md) | 73 项提交的维护者反应统计（论文中所有计数的唯一来源） |

## 论文：`paper_tcc/`

| 路径 | 内容 |
|---|---|
| `main.tex` | 导言区与各章 `\input`，不含正文 |
| `macros.tex` | 宏包、工具名宏、配色、代码与图表样式 |
| `sections/00-abstract.tex` … `08-conclusion.tex` | 摘要、引言、背景、方法、分析器、评估（RQ1–RQ6）、讨论、相关工作、结论，每章一个文件 |
| `figures/fig-*.tex` | 每张图一个 TikZ / pgfplots 文件 |
| `tables/tab-*.tex` | 每张表一个文件；`tab-bugs.tex` 是 55 条 issue 总表 |
| `data/findings.csv` | 73 项发现的分类表（层、症状、因子、可观察量、状态） |
| `data/stats.py`、`data/stats.json` | 由 `findings.csv` 计算正文中出现的全部计数 |
| `bib/references.bib` | 参考文献，全部取自 dblp；`fetch_dblp.py` 生成，`apply_keys.py` 替换引用键 |
| `build.ps1` | 编译脚本：pdflatex → bibtex → pdflatex ×2，产物写到 `build/` |
| `main.pdf` | 当前版本的编译结果 |
| `README.md` | 各图表的数据出处、参考文献规则、版面检查方法 |

编译：

```powershell
cd paper_tcc
powershell -ExecutionPolicy Bypass -File build.ps1
```

也可以把整个 `paper_tcc/` 上传到 Overleaf，主文件为 `main.tex`。

## 工具与实验：`plan/`

### 源代码

| 路径 | 内容 |
|---|---|
| `run.py` | 命令行入口：自检、逐阶段查看、完整流水线、批量 campaign |
| `tcc/` | 检测工具主体，按四个阶段组织（见下表） |
| `scripts/` | 146 个实验与分诊脚本：各类差分扫描（`*_diff.py`、`*_sweep.py`）、候选确认（`confirm_*.py`）、根因诊断（`diag_*.py`）、issue 工具（`check_issue_drafts.py`、`run_issue_snippet.py`、`mark_filed.py`、`issue_status_report.py`、`issue_outcomes.py`）；以下划线开头的是一次性的台账整理脚本 |
| `kaggle/` | Linux / CUDA 复现与扫描任务：`drive.py` 负责推送、查询、拉取 Kaggle 任务，`make_*_job.py` 生成任务包，`jobs/` 是任务定义 |
| `tests/` | 离线测试（不依赖 torch） |
| `benchmark/` | 历史 issue 基准：`historical_bugs.json` 与在 PyTorch 2.14 上的修复状态 |
| `reproducers_*/` | 独立复现脚本（CPU、CUDA、模型级），每个文件定义 `f` 与 `args` |

`tcc/` 的模块：

| 阶段 | 模块 |
|---|---|
| 1 编译点与因子推导 | `sites.py`、`ir.py`、`binding.py`、`binding_ast.py`、`factors.py`、`scs.py` |
| 2 种子、变异与执行 | `seeds.py`、`corpus.py`、`program.py`、`generate.py`、`execute.py`、`runner.py` |
| 3 观察、判定、定位、约简 | `observe.py`、`oracle.py`、`localize.py`、`minimize.py` |
| 4 报告与台账 | `report.py`、`campaign.py` |
| 路径与程序侧扫描器 | `aoti_diff.py`、`cache_diff.py`、`decomp_diff.py`、`dtype_matrix.py`、`metamorphic.py`、`sweep_common.py` |
| Python 语义语料 | `dynamo_semantics*.py`，五批共 274 个程序 |
| 评估 | `faults.py`（注入缺陷）、`benchmark.py`、`baselines.py`、`ablation.py`、`experiments.py`、`metrics.py`、`mine.py` |
| 其他 | `selfcheck.py`、`compat.py` |

先跑自检：

```bash
cd plan
python run.py selfcheck --offline
python run.py selfcheck            # 需要 torch
python tests/test_offline.py
```

更多用法见 [`plan/README.md`](plan/README.md)。

### 数据与结果

| 路径 | 内容 |
|---|---|
| `results/` | 本机（Windows，PyTorch 2.14 与 nightly）各项扫描的原始输出、日志与汇总 |
| `reports*/` | 按扫描类别分目录的候选报告，每个候选一个子目录（`issue.md`、`minimal.py`、期望与实际输出、执行轨迹） |
| `gpu_reports*/` | CUDA 上的候选报告 |
| `kaggle_out/` | Kaggle 上 Linux / T4 GPU 任务拉回的结果，每个任务一个目录 |
| `results0909/`、`issues_0910/` | 研究早期的结果与稿件 |

### 研究台账

| 文件 | 内容 |
|---|---|
| `EXECUTION_REPORT.md` | 按时间记录的执行日志，§1 是当前续跑点 |
| `TO_SUBMIT.md` | 每项发现的台账，包括阴性结果和决定不报告的项 |
| `NEXT_DIRECTIONS.md` | 待尝试的测试角度 |
| `paper_notes/` | 论文提纲与改写计划 |

## Issue 稿件：`issues/`

| 路径 | 内容 |
|---|---|
| `0913issues/` | 第一批稿件（29 个文件） |
| `0920issues/` | 第二批稿件（48 个文件）；文件编号即提交顺序，`comment-on-N` 是发在已有 issue 下的评论 |

每篇稿件的代码块都逐字执行过，引用的输出是真实输出；稿件头部表格记录查重日期与关键词。提交前用 `plan/scripts/check_issue_drafts.py` 检查标题长度、摘要格式与模板字段。已提交的链接记录在各目录的 `README.md` 中，第二批另有 `FILED.md` 按提交顺序汇总。

## 文档：`docs/`

| 文件 | 内容 |
|---|---|
| `Research_Plan_v2_Consistency_Detection.md` | 研究计划 v2 |
| `Research_Plan_Updated.md` | 更新后的研究计划 |
| `PROCESS_2026-09-02_22.md` | 9 月 2 日至 22 日的缺陷挖掘过程 |
| `REPORT_2026-09-22.md` | 9 月 22 日的阶段汇报 |
| `SUMMARY_WRITING_GUIDE.md` | issue 摘要的写作规范 |

## 未收入仓库的内容

- Python 虚拟环境、编译中间产物（`.obj`、`.exe`、`.pyc`）、LaTeX 的 `build/` 目录和版本备份 zip。
- 超过 10 MB 的 14 个文本结果文件以 gzip 压缩形式保存（文件名后加 `.gz`），内容完整：`plan/results/cxx_algebra/msvc/out_*.txt`、`plan/kaggle_out/cxxalgebra/.../out_O*.txt`、`plan/reports_opinfo_s4x3/run_results.json`。
- Kaggle 凭据保存在本机用户目录，不在仓库内。

## 环境

- PyTorch 2.14 与 nightly；本机为 Windows 11、Python 3.14，Linux 与 T4 GPU 上的复现在 Kaggle 完成。
- 论文编译用 MiKTeX 25.12 或 TeX Live，需要 `acmart` 文档类。
