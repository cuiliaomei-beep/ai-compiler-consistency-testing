# tcc — Toxic Compilation 一致性缺陷自动检测（研究计划实现）

本目录是《研究计划：面向 Toxic Compilation 一致性缺陷的自动检测》
（`../Toxic_Compilation_Consistency_Detection_Research_Plan_Updated.md`）的完整实现，
四个阶段是一条流水线中的连续步骤：

```
Python Program
   │  Phase 1  sites.py / ir.py / factors.py / scs.py     编译边界 → 轻量 IR + 四类依赖 → 语义因子 → SCS → 测试义务
   ▼
Consistency Test Obligations
   │  Phase 2  seeds.py / generate.py / execute.py       种子 → 单因子成对变异 + 边界取值 + 上下文序列 → eager/cold/warm/分层执行
   ▼
   │  Phase 3  observe.py / oracle.py / localize.py / minimize.py   O1–O7 → 分层定位 → 输入/程序最小化
   ▼
   │  Phase 4  report.py / campaign.py                   去重签名 → issue.md + minimal.py + 证据文件 → 状态台账
   ▼
reports/<signature>/
```

实验层：`faults.py`（注入缺陷 = 受控 ground truth）、`benchmark.py`（RQ1）、`baselines.py`（RQ2）、
`ablation.py`（RQ3）、`experiments.py`（RQ4 + 实验 A–E）、`metrics.py`（§27）。

## 先跑自检

```bash
python run.py selfcheck --offline     # Phase 1 的每个例子都按计划文本给出预期结果
python run.py selfcheck               # 编译计数、七个 oracle、分层定位（需要 torch）
python tests/test_offline.py
```

自检没通过之前，流水线输出的任何东西都不算证据：每个 oracle 都用"故意注入的缺陷"验证会报警，
再用真实 `aot_eager` 验证不误报。

## 逐阶段查看

```bash
python run.py sites <文件或目录>                  # §5.1  CompilationSite：target / arguments / options / reachable / external state
python run.py analyze --programs view_inplace --ir   # §5.2 IR + §6–8 因子、边界、shape→index 链、别名/原地写 FACT
python run.py obligations --yaml results/obligations  # §9–10 SCS + 测试义务（YAML）
python run.py plan                                    # §11–15 上下文、单因子对、A→B / B→A / A→B→A 序列
```

## 完整流水线（真实编译器）

```bash
python run.py run --backend inductor --reruns 2 --minimize        # 全部内置程序
python run.py run --from-dir some/reproducers                      # 目录下每个 .py 定义 f 与 args（模板见 reproducers_example/）
python run.py run --nnsmith 10 --backend inductor                  # NNSmith 生成的模型进入同一 harness（Setting B）
python run.py campaign --opinfo 703 --opinfo-samples 3 --seed 4 --no-corpus --out reports_x   # 官方 OpInfo 样本作种子（§21）
python run.py campaign --status <signature>=Confirmed              # RQ5 状态台账
```

输出目录 `reports/<signature>/`：`issue.md`、`minimal.py`、`environment.txt`、`expected.txt`、`actual.txt`、
`execution_trace.json`、`semantic_factor.json`、`metadata.json`（§18.4）。`SUMMARY.md` 按优先级汇总，
`CAMPAIGN.md` 是 Generated/Submitted/Confirmed/Fixed/Duplicate/Invalid/Pending 台账。

## 实验

```bash
python run.py bench      --backend eager --budget 8   # RQ1：19 个注入缺陷的召回 + fixed 版本误报
python run.py ablate     --backend eager --budget 8   # RQ3：A0..A6/FULL
python run.py cache      --backend eager --budget 8   # RQ4：普通差分 / 随机序列 / SCS 序列
python run.py baselines  --backend eager --budget 8   # RQ2：B1 随机 vs 本方法；外部工具适配（--external DIR）
python run.py experiments --backend eager             # 实验 A–E
python run.py metrics                                 # §27
python run.py all                                     # 以上全部
```

`--backend eager` 让注入缺陷实验在秒级完成；换成 `inductor` 则每次冷编译约 1–15 s。

## 本机状态

torch 2.14.0+cpu · Python 3.14 · 无 CUDA/Triton · MSVC 可用（`run.py` 启动时自动导入 vcvars 环境）。
因此 E0–E3（eager / Dynamo / AOTAutograd / Inductor C++）可用，E4（Triton/CUDA）标记为不可用；
Triton、TileLang 只有 `sites.py` 的边界识别，没有执行路径。

## 与计划各节的对应

| 计划 | 实现 |
|---|---|
| §5.1 编译边界 | `sites.py`：torch.compile / jit.script / jit.trace / triton.jit / tilelang.jit + wrapper，可达函数、外部状态 |
| §5.2 IR 与四类依赖 | `ir.py`：Assign/Call/Branch/Loop/Index/Mutation/Return/Raise/StateRead/StateWrite；data/control/alias/state；前后向切片 |
| §6 Tensor 抽象、scalar/flag、边界 | `factors.py`：TensorState、ScalarFactor（flag/none/string/enum/container/index/loop/reshape）、Boundary（k±1、%k） |
| §7 shape→index | `factors.py`：常量偏移数据流、经 `torch.arange` 等调用传播、index/slice/gather/index_select |
| §8 alias/mutation | `factors.py`：别名并查集、FACT（mutation_visible/partial_write/write_order/alias_returned/conditional_mutation/state_write/exception_path） |
| §9 SCS | `scs.py: derive_scs` |
| §10 测试义务 | `scs.py: derive_obligations / obligations_to_yaml` |
| §11 种子 | `seeds.py`：签名/注解构造、记录调用、reproducer 文件、site 派生 |
| §12 单因子变异 | `scs.py: obligations_to_contexts` + `program.py: apply_factors` |
| §13 边界引导 | `factors.py` 边界 → `scs.py` shape 义务 |
| §14 cache 序列与执行矩阵 | `execute.py: execution_matrix`（E1/C1/E2/C2cold/C2warm/C1'） |
| §15 上下文切换 | `generate.py: context_switch_sequences`（A→B、B→A、A→B→A） |
| §16 多层执行定位 | `execute.py: run_layered` + `localize.py: triage_layers` |
| §17.1 O1–O7 | `oracle.py`：value(fp64 规则)/metadata/exception/mutation/alias/gradient + `CacheVerdict` |
| §17.2 最小化 | `minimize.py`：rank/shape/值/参数/容器/flag；切片引导的语句删除 |
| §18 Issue 生成 | `report.py`：18.3 模板、18.4 目录、18.5 签名去重、18.1 步骤 8 脱敏 |
| §21 历史基准 | `benchmark/historical_bugs.json`（骨架）+ `faults.py` 注入缺陷（受控 ground truth） |
| §22–24 基线 | `baselines.py`：B1 随机；FreeFuzz/NNSmith/TorchProbe/TitanFuzz/DeepREL 适配（Setting B 公共 harness） |
| §25 RQ1–RQ5 | `benchmark.py` / `experiments.py` / `ablation.py` / `campaign.py` |
| §26 实验 A–E | `experiments.py` |
| §27 效率 | `metrics.py` |
