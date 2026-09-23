# paper_tcc —— LaTeX 工程（ACM acmsmall，双盲送审版）

**2026-09-23 重写**：主线改为「编译路径作为测试维度」（见 `plan/paper_notes/PLAN_REWRITE_2026-09-23.md`、`plan/paper_notes/OUTLINE_B_2026-09-23.md`）；RQ 改为六个；蜕变测试只在方法 3.1 末段和相关工作里各提一次。每轮写作后打包到 `backups/`（可回滚）。

模板：`\documentclass[acmsmall,screen,review,anonymous]{acmart}`
当前版面（`python build/measure.py`）：正文 18.5 页（含 55 行的 issue 总表整页），参考文献 3.3 页（55 条），共 23 页。
页数：TOSEM 无硬性上限；用户 2026-09-23 决定不再压缩，此前的 17.8–18 页目标作废。参考文献仍要求 ≤ 4 页、≥ 40 条。

## 目录

| 路径 | 内容 |
|---|---|
| `main.tex` | 只有导言区与各章 `\input`，不放正文 |
| `macros.tex` | 宏包、工具名 `\tool`、配色（Tol 色盲友好色）、listings 与 pgfplots 样式、RQ 答案框 `\rqanswer` |
| `sections/00-abstract.tex … 08-conclusion.tex` | 每章一个文件 |
| `figures/fig-*.tex` | 每张图一个 TikZ/pgfplots 文件（数据直接写在文件里，出处见下表） |
| `tables/tab-*.tex` | 每张表一个文件 |
| `bib/references.bib` | 参考文献（由 `bib/fetch_dblp.py` 生成，不要手改） |
| `bib/fetch_dblp.py` | 从 dblp 取元数据并按 dblp 标准 BibTeX 版式写出；`bib/dblp_cache.json` 是缓存 |
| `bib/apply_keys.py` | 把写作时用的短别名（`nnsmith` 等）替换成 dblp 键；新增引用后跑一次 |
| `build.ps1` | 编译脚本：pdflatex → bibtex → pdflatex ×2，产物在 `build/main.pdf` |
| `build/measure.py` | 量正文页数与参考文献页数（`--png` 同时把每页渲染成 `build/pNN.png` 便于检查版面） |

## 编译

```powershell
powershell -ExecutionPolicy Bypass -File build.ps1      # 产物 build/main.pdf
python build/measure.py --png                            # 页数检查
```

本机装的是 MiKTeX 25.12（`%LOCALAPPDATA%\Programs\MiKTeX`，已开自动装包）；Overleaf 上直接上传整个目录即可（主文件 `main.tex`）。

## 参考文献规则（已按要求实现）

- 全部 55 条来自 dblp；每条前一行 `% https://dblp.org/rec/<key>.html?view=bibtex` 是该条的 dblp BibTeX 链接。
- `title` 值用 `{{...}}`；`editor` 字段不输出；引用键用 dblp 原键 `DBLP:conf/...`。
- **说明**：dblp.org 的网页与 `.bib` 下载被反爬挑战（Anubis）挡住，脚本改走 dblp 官方 SPARQL 接口
  （`https://sparql.dblp.org`）取同一条记录的字段，再按 dblp 标准版式（字段顺序、缩进、`biburl`/`bibsource`）写出。
  与网页导出的差别只有两点：没有 `timestamp` 字段（SPARQL 不提供）；会议名里的缩写大括号是按规则补的。
  如需与网页导出逐字一致，用浏览器打开每条前面的链接复制替换即可。
- 加文献：在 `bib/fetch_dblp.py` 的 `REFS` 里加 dblp 上的准确标题 → `python bib/fetch_dblp.py` →
  在 `bib/apply_keys.py` 的 `ALIAS` 里加别名 → 正文里 `\cite{别名}` → `python bib/apply_keys.py`。

## 图表与数据出处（全部来自 `plan/` 下的实验结果）

| 图/表 | 类型 | 数据出处 |
|---|---|---|
| Fig. 1 示例 | 代码 + 分层结果条 | `issues_0910/14`（random.shuffle）、`issues_0910/06`（var_mean 空张量） |
| Fig. 2 总览 | 流程图 | 研究计划 §4、`NEXT_DIRECTIONS.md` §5–6 |
| Fig. 3 因子分析 | 依赖图 + 义务表 | `tcc/factors.py`、`results/obligations/*.yaml` |
| Fig. 4 执行矩阵 | 时序图 | 研究计划 §14–15、`tcc/execute.py` |
| Tab. 1 oracle | 表 | 研究计划 §17.1、`tcc/oracle.py` |
| Tab. 2 分析器 | 表 | `results/*/**.md` 各扫描的表头统计 |
| Fig. 5 RQ1 | 斜率图 | `EXECUTION_REPORT.md` §6 第 2 条（Kaggle 同设备 2.10 vs 2.14）、`benchmark/historical_bugs.json` |
| Fig. 6 RQ2 | 气泡散点图 | `results/RQ2.md` |
| Fig. 7 RQ3 | 阶梯线 + 堆叠柱 | `results/rq3_ablation.json`（报告 §3 RQ3 表） |
| Fig. 8 RQ4 | 棒棒糖图 + 条形图 | `results/RQ4.md` |
| Tab. 3 全部 55 条 issue（B1–B27、C1–C46 中的 issue 行） | 表（由 `data/findings.csv` 生成，正文不写"轮次"） | `0913issues/`、`0920issues/`，对应关系在 csv 的 draft 列 |
| Fig. 7 RQ6 | 热力图 + 堆叠条 | `data/findings.csv`（因子组 × 层；症状 × 层，68 个 PyTorch 项） |
| Fig. 10 成本–产出 | 对数散点图 | 各扫描的检查次数（报告 §3、§3.O）与 Tab. 3 |
| Tab. 4 负结果 | 表 | 报告 §3（diskcache、knobs、reuse_env、binding、vmap、models、dynsem 第三批） |

## 需要作者确认/以后更新的地方

1. **issue 统计口径（2026-09-23 起）**：四档（已修复 / 已确认 / Pending / 拒绝），数据只来自 `toxic_compile/ISSUE_OUTCOMES.md` 的「论文口径」表；当前 73 项 = 14 / 10 / 48 / 1（摘要、引言、RQ6、结论各出现一次）。`data/findings.csv` 是 73 项的分类表（层、症状、因子轴、可观察量、归因、状态），`python data/stats.py` 打印正文用到的全部计数。
2. **基线**：RQ2 只有 Random 与 NNSmith 是实际跑过的；TorchProbe / FreeFuzz / TitanFuzz 未能在 2.14 上运行，
   已在 5.1 与 6.3（Threats）如实说明。若以后跑了，补进 `figures/fig-rq2.tex`。
3. **前一篇工作**（toxic compilation 实证研究）在引言里以脚注"双盲隐去"形式提及，未进参考文献（dblp 无记录）。
4. 工具名暂用 `\tool` = Tcc，改名只需改 `macros.tex` 一处。
5. 写作遵循 `C:\Users\clm\.claude\skills\academic-research-skills`（academic-paper 的写作风格与 writing quality check：
   避免空泛词、每段先给论点、数字必须可追溯到实验产物、如实写局限与负结果）。
