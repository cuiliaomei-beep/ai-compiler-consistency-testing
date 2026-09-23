<!-- 提交信息（不要复制到 issue 里）；Summary 段按 SUMMARY_WRITING_GUIDE.md 的三句结构写：事实 / 困惑 / 暴露 -->
# pytorch/pytorch — issue 17

| 项 | 值 |
|---|---|
| 提交优先级 | 17 / 27 |
| 原候选编号 | TO_SUBMIT.md 第 15 条；草稿 `plan/issues_0910/15-*.md` |
| 仓库 | https://github.com/pytorch/pytorch |
| 验证版本 | torch 2.14.0+cpu（Windows + Linux）；nightly 2.15.0.dev20260911 (Win) / dev20260912 (Linux)。backend=eager 与 inductor 相同 |
| **提交 issue 链接** | https://github.com/pytorch/pytorch/issues/new?template=pt2-bug-report.yml |
| 使用的模板 | `.github/ISSUE_TEMPLATE/pt2-bug-report.yml`（🐛 torch.compile Bug Report，label: oncall: pt2） |
| 提交前查重 | https://github.com/pytorch/pytorch/issues?q=is%3Aissue%20random.seed%20dynamo · PR #188083（2026-07-06 合并："Route module-level random.seed through RandomVariable"——修的是 graph break，不是首调用语义）· open #196437（`random.Random` + dynamic=True，不同症状） |
| 证据包 | `plan/reports_dynsem/random_module/minimal_verified.py`（`seed_fn`），`plan/scripts/diag_random_compile.py`（"seed inside" 段），`plan/kaggle_out/randomlinux.txt` |
| 建议标签 | oncall: pt2, module: dynamo, module: correctness (silent) |
| 备注 | 可并入 draft 14（同一 `RandomVariable`）。单独报的理由：症状不同（只有第一次调用错），修法也可能不同 |

---

## Title

[dynamo] `random.seed()` inside a compiled function is ignored on the first (compiling) call — first call returns values from a different RNG state

## Body

### 🐛 Describe the bug

**Summary.** `random.seed(k)` inside a compiled function does not take effect on the first call: eager returns the seeded values on every call, while the compiled function returns values from an unseeded stream on the compiling call and the seeded values from the second call on, for `random.random`, `randint`, `randrange` and `uniform` (torch 2.14.0 and nightly, Windows and Linux). A user who checks reproducibility with a single call sees a mismatch that disappears on re-run, which is easy to mistake for flakiness. Because the seed updates Dynamo's trace-time copy of the RNG while the values handed back on that first call come from the live one, the outcome is decided by whether the call compiled or replayed.

When a compiled function calls `random.seed(k)` and then `random.random()` / `randint` / `randrange` / `uniform`, the **first** call of the compiled function returns values that do not come from the seeded stream; from the second call on the values are correct. Eager returns the seeded values every time.

```python
import random
import torch


def seed_fn(x):
    random.seed(0)
    return x + random.random(), random.random(), random.randint(0, 100)


cf = torch.compile(seed_fn, backend="eager")     # same with backend="inductor"
print("eager   :", [seed_fn(torch.zeros(1))[1:] for _ in range(3)])
print("compiled:", [cf(torch.zeros(1))[1:] for _ in range(3)])
```

```
eager   : [(0.7579544029403025, 53), (0.7579544029403025, 53), (0.7579544029403025, 53)]
compiled: [(0.9654648863619172, 62), (0.7579544029403025, 53), (0.7579544029403025, 53)]
```

Single-call variants (torch 2.14.0, `scripts/diag_random_compile.py`), two calls each, eager vs compiled:

```
random.seed(0); random.random()          eager [0.8444, 0.8444]   compiled [0.7580, 0.8444]
random.seed(0); random.randint(0, 1000)  eager [864, 864]         compiled [394, 864]
random.seed(0); random.randrange(1000)   eager [864, 864]         compiled [394, 864]
random.seed(0); random.uniform(0, 10)    eager [8.4442, 8.4442]   compiled [7.5795, 8.4442]
random.seed(0); 3x random.random()       eager (0.8444, 0.7580, 0.4206) x2
                                         compiled (0.2589, 0.5113, 0.4049) then correct
```

`random.gauss`, `random.choice`, `random.choices`, `random.sample`, `random.shuffle` after an in-function `random.seed` are consistent (they take other paths). With the seed set *outside* the function the value-producing calls are all consistent.

Expected: the first call gives the same values as every later call and as eager. A first-call-only discrepancy is especially easy to miss in tests.

Likely mechanism (`torch/_dynamo/variables/misc.py`, `RandomVariable` / `_call_random` with `call_random_fn`): the in-frame `seed()` updates Dynamo's trace-time copy of the RNG, the value calls are recorded for run-time replay from a captured state, but on the compiling call the values handed back to the user come from the live global RNG that was never re-seeded (the trace-time `getattr(self.random, name)(...)` advances the copy, not the module RNG). From the second call on the recorded replay is used and the results are right.

### Error logs

No error; silent wrong result on the first call.

### Versions

(torch 2.14.0+cpu, Windows 11, Python 3.14, MSVC 19.44 — `python -m torch.utils.collect_env` output below; the same reproducer was also run on the 2026-09-11 nightly wheel.)

```
PyTorch version: 2.14.0+cpu
Is debug build: False
CUDA used to build PyTorch: None
ROCM used to build PyTorch: N/A

OS: Microsoft Windows 11 Pro for Workstations (10.0.26200 64-bit)
GCC version: Could not collect
Clang version: Could not collect
CMake version: Could not collect
Libc version: N/A
MSVC: Microsoft (R) C/C++ Optimizing Compiler Version 19.44.35228 for x64 (used by Inductor's C++ backend)

Python version: 3.14.7 (tags/v3.14.7:823f032, Aug  5 2026, 10:51:32) [MSC v.1944 64 bit (AMD64)] (64-bit runtime)
Python platform: Windows-11-10.0.26200-SP0
Is CUDA available: False
CUDA runtime version: No CUDA
GPU models and configuration: No CUDA
Is XPU available: False
Is XNNPACK available: False

CPU:
Name: 11th Gen Intel(R) Core(TM) i9-11900T @ 1.50GHz
Manufacturer: GenuineIntel
Architecture: 9

Versions of relevant libraries:
[pip3] numpy==2.5.2
[pip3] torch==2.14.0+cpu
[pip3] torchvision==0.29.0+cpu
[conda] Could not collect
```

Also reproduced on Linux (Kaggle, torch 2.14.0+cpu and 2.15.0.dev20260912+cpu).
