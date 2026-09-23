# 历史缺陷基准（计划 §21）

`historical_bugs.json` 只是清单骨架：字段严格对应计划 §21 的十个字段，`entries` 为空，
因为本机只有一个 PyTorch 版本（2.14.0+cpu），无法同时验证 buggy/fixed 两个版本，
而未经验证的 issue 编号不应写进 ground truth。

填充流程：

1. 从 toxic-compilation 数据集中筛出 code-generation deviation / JIT specialization /
   cache integrity / wrong generated code 四类事件；
2. 逐条核对 §21 的六条标准（Python reproducer、明确的 eager 行为、可运行的 compiled 行为、
   buggy 版本、fixed 版本、确属 consistency）；
3. 把 reproducer 写成本目录下的 `.py` 文件：定义 `f`（或 `torch.compile` 目标）与 `args`；
4. 在 `entries` 中登记一条，`Verified` 置 `true`；
5. `python run.py bench --historical benchmark/historical_bugs.json` 会在当前安装的 PyTorch 上运行每条，
   并按"当前版本是否为 BuggyVersion"记录预期结果（检出 / 不应检出）。

在历史基准可用之前，RQ1 使用 `tcc/faults.py` 的 19 个注入缺陷作为受控 ground truth：
每个缺陷对应计划 §1 的一类问题（codegen deviation / specialization / cache），
带已知触发因子与应触发的 oracle；"fixed 版本"即真实编译器（无注入）。
