<!-- 提交信息（不要复制到 issue 里） -->
# pytorch/pytorch — 0920 issue 21（中：静默错值；nightly 上 eager 已接受该输入）

| 项 | 值 |
|---|---|
| 仓库 | https://github.com/pytorch/pytorch |
| 验证版本 | torch 2.14.0+cpu：eager 与 `aot_eager` 抛 `RuntimeError: value cannot be converted to type int8_t without overflow`，Inductor 返回错值；nightly 2.15.0.dev20260911+cpu：eager 与 `aot_eager` **返回原张量**（边界视为"无约束"），Inductor 仍返回同样的错值。Windows x64；Linux 复核（Kaggle，`plan/kaggle_out/intublinux.log`、`intubgpu.log`）：Linux CPU 两个版本输出与下文逐字相同，CUDA（T4，2.14.0+cu130）上 Inductor 同样返回 `[-24, -24, -24, -24, -24]` |
| **提交 issue 链接** | https://github.com/pytorch/pytorch/issues/new?template=pt2-bug-report.yml |
| 使用的模板 | `.github/ISSUE_TEMPLATE/pt2-bug-report.yml` |
| 提交前查重 | 2026-09-21：`clamp int8 overflow inductor` 等：无同报告。**相关（2026-09-21 晚复查补充）**：open #107702（2023，“标量超出张量 dtype 范围时各处行为不一致”的总帖，讲的是 eager）；PR #193169（2026-08，让 eager 的 `clamp` 对越界的界做饱和处理——这就是 nightly 上 eager 不再报错而是原样返回的原因），Inductor 的 lowering 没有跟着改，本条报的正是这个剩余的不一致。与 0920 第 12 条（`np.clip` 经 torch._numpy）现象相同但入口不同：那条在 Dynamo 的 numpy 翻译层，本条是 `torch.clamp` 本身经 Inductor |
| 证据包 | `plan/reports_intub/floor_divide_python_example.py`（后半段 clamp 用例）、`plan/reports_intub/inductor_value_leads.py`；发现来源 `plan/scripts/int_ub_sweep.py`（`int_unary:clamp_wide`、`clamp_min_big`） |
| 建议标签 | oncall: pt2, module: inductor, module: correctness (silent) |
| 备注 | 在 2.14 上这也属于 #197554（Validation lost）一类；nightly 上 eager 语义已变成"越界边界不起作用"，Inductor 的绕回结果就成了纯粹的错值，所以单独报 |

---

## Title

[inductor] `torch.clamp` with a Python bound outside the dtype's range wraps the bound: `clamp(int8_tensor, -1000, 1000)` returns `-24` for every element

## Body

### 🐛 Describe the bug

**Summary.** `torch.clamp` on an integer tensor with Python-integer bounds that do not fit the tensor's dtype does not agree between eager and Inductor: for an int8 tensor, `clamp(x, -1000, 1000)` returns `x` unchanged in eager on nightly (and raises "value cannot be converted to type int8_t without overflow" in eager on 2.14.0), while Inductor returns `-24` for every element on both versions, and `clamp(x, max=300)` turns `127` into `44`. A user who clamps to a generous range that happens to exceed a narrow dtype gets a tensor of constants after compiling, with no error in either version. Because Inductor converts the bound to the tensor's dtype before comparing (`1000 -> int8 -24`, `300 -> 44`), every integer clamp whose bound is outside the dtype's range is affected.

```python
import torch

x = torch.tensor([-128, -3, 0, 5, 127], dtype=torch.int8)
for name, fn in (("clamp(x, -1000, 1000)", lambda t: torch.clamp(t, -1000, 1000)),
                 ("clamp(x, max=300)", lambda t: torch.clamp(t, max=300))):
    out = []
    for backend in (None, "aot_eager", "inductor"):
        torch._dynamo.reset()
        try:
            out.append(str((fn if backend is None else torch.compile(fn, backend=backend))(x.clone()).tolist()))
        except Exception as e:
            out.append("raises " + type(e).__name__)
    print(f"{name:22s} eager {out[0]} | aot_eager {out[1]} | inductor {out[2]}")
```

torch 2.14.0+cpu:

```
clamp(x, -1000, 1000)  eager raises RuntimeError | aot_eager raises RuntimeError | inductor [-24, -24, -24, -24, -24]
clamp(x, max=300)      eager raises RuntimeError | aot_eager raises RuntimeError | inductor [-128, -3, 0, 5, 44]
```

nightly 2.15.0.dev20260911+cpu:

```
clamp(x, -1000, 1000)  eager [-128, -3, 0, 5, 127] | aot_eager [-128, -3, 0, 5, 127] | inductor [-24, -24, -24, -24, -24]
clamp(x, max=300)      eager [-128, -3, 0, 5, 127] | aot_eager [-128, -3, 0, 5, 127] | inductor [-128, -3, 0, 5, 44]
```

`1000` as int8 is `-24` and `300` as int8 is `44`: the lower bound `-1000` wraps to `24`, the upper bound to `-24`, and `min(max(x, 24), -24)` is `-24` everywhere.

Eager's behaviour changed with #193169 (saturate out-of-range integer scalar `clamp` bounds, part of #107702); the Inductor lowering was not updated with it, which is the remaining inconsistency reported here.

**Possible fix.** In the Inductor lowering of `clamp` / `clamp_min` / `clamp_max`, when a bound is a Python scalar and the input dtype is integral, saturate the bound to `torch.iinfo(dtype)` before it is turned into a constant of the input dtype (a bound beyond the range then becomes a no-op, which is what eager does on nightly), instead of casting it with wrap-around.

### Error logs

No error is raised under Inductor; the values differ as shown above.

### Versions

```
PyTorch version: 2.14.0+cpu   (and nightly 2.15.0.dev20260911+cpu; same results on Linux CPU, nightly 2.15.0.dev20260920, and CUDA 2.14.0+cu130 on a Tesla T4)
OS: Microsoft Windows 11 Pro for Workstations (10.0.26200 64-bit)
MSVC: Microsoft (R) C/C++ Optimizing Compiler Version 19.44.35228 for x64
Python version: 3.14.7 (64-bit runtime)
Is CUDA available: False
CPU: 11th Gen Intel(R) Core(TM) i9-11900T @ 1.50GHz
[pip3] numpy==2.5.2
[pip3] torch==2.14.0+cpu
```
