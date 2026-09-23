# results/ 索引

| 文件 | 计划章节 | 内容 |
|---|---|---|
| `selfcheck_torch.log` | — | torch 级自检（29/29） |
| `rq1_bench.log`, `rq1_benchmark.json` | §25 RQ1 | 19 个注入缺陷的检出、fixed 版本误报、按类别召回 |
| `rq3_ablation.log`, `rq3_ablation.json` | §25 RQ3 | A0…A6/FULL 消融 |
| `rq4_cache.log`, `RQ4.md`, `rq4_cache.json` | §25 RQ4 | 普通差分 / 随机序列 / SCS 序列；真实编译器切换表 |
| `rq2_baselines.log`, `RQ2.md`, `rq2_baselines.json` | §22–25 RQ2 | B1 随机、B3 NNSmith、B5 本方法；外部工具可用性 |
| `experiments.log`, `EXPERIMENTS.md`, `experiments.json` | §26 | 实验 A–E |
| `rq5_campaign.log`, `../reports/` | §25 RQ5 | 第一轮真实编译器运行（35 程序，0 候选） |
| `rq5_campaign2.log`, `../reports_campaign2/` | §25 RQ5 | 第二轮（20 NNSmith + 语料，`--keep-info`） |
| `rq5_opinfo.log`, `../reports_opinfo/` | §25 RQ5 | 第三轮（120 个 OpInfo 样本；`torch.cov` dynamic=True，查重为 PR #190669 的重复） |
| `rq5_opinfo_all.log`, `../reports_opinfo_all/` | §25 RQ5 | 第四轮（545 个 OpInfo 样本；`torch.var_mean` 空张量 mean=0 的非重复发现，见 `0211b330cc67/ISSUE_FINAL.md`） |
| `rq5_opinfo_s3.log`, `../reports_opinfo_s3/` | §25 RQ5 | 第五轮（seed 3，540 个样本；`multi_margin_loss` fp16 → #144362 实例） |
| `rq5_opinfo_s4x3.log`, `../reports_opinfo_s4x3/` | §25 RQ5 | 第六轮（每算子 3 样本，1393 个程序，20 713 项测试；`std_mean` 并入 var_mean 发现） |
| `metrics.log`, `metrics_static.json` | §27 | 静态分析/生成开销 |
| `obligations/*.yaml` | §10 | 每个程序的测试义务 |
| `sites_torch_*.json` | §5.1 | torch 源码上的编译边界 |
| `bench_reports/<sig>/` | §18 | 注入缺陷触发后生成的 issue 草稿样例 |
| `run_smoke.log`, `../reports_smoke/` | — | 最早的 Inductor 冒烟 |

所有 `.log` 由 `scripts/run_experiments.ps1` / `scripts/run_rest.ps1` 生成；结论汇总见 `../EXECUTION_REPORT.md`。
