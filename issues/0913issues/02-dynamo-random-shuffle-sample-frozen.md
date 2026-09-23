<!-- 提交信息（不要复制到 issue 里）；Summary 段按 SUMMARY_WRITING_GUIDE.md 的三句结构写：事实 / 困惑 / 暴露 -->
# pytorch/pytorch — issue 02

| 项 | 值 |
|---|---|
| 提交优先级 | 02 / 27 |
| 原候选编号 | TO_SUBMIT.md 第 14 条；草稿 `plan/issues_0910/14-*.md` |
| 仓库 | https://github.com/pytorch/pytorch |
| 验证版本 | torch 2.14.0+cpu（Windows 11 与 Linux/Kaggle）；nightly 2.15.0.dev20260911+cpu（Windows）/ dev20260912+cpu（Linux）。backend=eager 与 inductor 相同，dynamic=False |
| **提交 issue 链接** | https://github.com/pytorch/pytorch/issues/new?template=pt2-bug-report.yml |
| 使用的模板 | `.github/ISSUE_TEMPLATE/pt2-bug-report.yml`（🐛 torch.compile Bug Report，label: oncall: pt2） |
| 提交前查重 | https://github.com/pytorch/pytorch/issues?q=is%3Aissue%20random.shuffle%20torch.compile · https://github.com/pytorch/pytorch/issues?q=is%3Aissue%20random.sample%20dynamo · 相关 open #196437（`random.Random` 实例 + dynamic=True 第 4 次调用重复上一值；入口不同，这里是模块级函数、静态形状、每次都重复）· PR #188083（已合并 2026-07-06，把模块级 `random.seed` 接入 RandomVariable，并提到 shuffle/sample 已走该路径）· PR #185971（`random.Random` 回放修复，未合并） |
| 证据包 | `plan/reports_dynsem/random_module/minimal_verified.py`（下方脚本），`plan/scripts/diag_random_compile.py`（逐函数对照），`plan/kaggle_out/randomlinux.txt`（Linux 2.14 + nightly 输出），`plan/results/dynsem/DYNSEM.md`（6.6 扫描原始命中） |
| 建议标签 | oncall: pt2, module: dynamo, module: correctness (silent) |
| 备注 | 根因在 `torch/_dynamo/variables/misc.py` `RandomVariable.shuffle/sample`：置换 / 抽样下标在**追踪时**用 `self.random`（RNG 状态的副本）算出并作为常量写进图，没有像 `random()/randint()` 那样经 `call_random_fn` 在运行时回放；而且运行时全局 RNG 也不被推进（或推进的步数不对）。draft 15 是同一代码区域的另一个症状，可合并成一个 issue |

---

## Title

[dynamo] `random.shuffle` / `random.sample` inside a compiled function return the same permutation on every call (eager advances the RNG)

## Body

### 🐛 Describe the bug

**Summary.** Inside a compiled function, `random.shuffle` and `random.sample` do not behave as in eager: eager draws a fresh permutation or sample on every call, while the compiled function returns the permutation computed when the graph was traced on every subsequent call, and the global RNG state afterwards also differs from eager's (torch 2.14.0 and nightly, backend `eager` and `inductor`). A user who compiles a training step that shuffles or subsamples in Python gets one fixed order for the whole run without any error, warning or graph break. Because the order is fixed at trace time by Dynamo's `RandomVariable` rather than drawn by the program, the result depends on when the function was first compiled, not on the seed the program set.

Inside a `torch.compile`d function, `random.shuffle(lst)` and `random.sample(population, k)` produce the **same result on every call**. Eager code draws from the global RNG each time and gets a different permutation / sample. The other supported `random` functions (`random.random`, `randint`, `randrange`, `uniform`, `choice`, `choices`, `gauss`) do advance correctly, so a program that shuffles its inputs (data augmentation, negative sampling, dropout of list elements, ...) silently runs with one fixed order once compiled. The global RNG state after the compiled calls is also different from eager's, so unrelated randomness downstream diverges too.

```python
import random
import torch


def shuffle_fn(x):
    lst = [1, 2, 3, 4, 5]
    random.shuffle(lst)
    return x + lst[0], lst


def sample_fn(x):
    s = random.sample(range(100), 2)
    return x + s[0], s


for name, fn in [("shuffle", shuffle_fn), ("sample", sample_fn)]:
    cf = torch.compile(fn, backend="eager")           # same with the default Inductor backend
    random.seed(7); eager = [fn(torch.zeros(1))[1] for _ in range(3)]
    random.seed(7); comp = [cf(torch.zeros(1))[1] for _ in range(3)]
    print(name, "eager   :", eager)
    print(name, "compiled:", comp)
```

Output (torch 2.14.0+cpu; identical on the 2026-09-11/12 nightlies, on Windows and Linux, and with `backend="inductor"`):

```
shuffle eager   : [[5, 1, 4, 2, 3], [3, 4, 2, 5, 1], [4, 3, 1, 2, 5]]
shuffle compiled: [[5, 1, 4, 2, 3], [5, 1, 4, 2, 3], [5, 1, 4, 2, 3]]
sample eager   : [[41, 19], [50, 83], [6, 9]]
sample compiled: [[41, 19], [41, 19], [41, 19]]
```

The first compiled call is right (it matches the first eager call), every later call replays it. `random.random()` after two compiled `shuffle` calls returns `0.0724…` while eager returns `0.9097…` from the same seed, i.e. the global RNG is not advanced the way eager advances it either.

For comparison, the same loop with `random.random()`, `random.randint(0, 1000)`, `random.uniform(0, 10)`, `random.choice([...])`, `random.choices(...)` and `random.gauss(0, 1)` in place of `shuffle`/`sample` gives identical sequences eager vs compiled (`scripts/diag_random_compile.py` in the evidence pack prints all of them).

Expected: `shuffle`/`sample` inside the compiled function behave like eager (different result per call, global RNG advanced), or Dynamo graph-breaks on them. Silently freezing the permutation is the worst of the three options.

Where it comes from (2.14.0 sources, `torch/_dynamo/variables/misc.py`, `RandomVariable`): `shuffle` and `sample` compute the permutation / the sampled indices **at trace time** with `self.random` (a copy of the RNG state taken when tracing started) and bake the reordered `ListVariable` into the graph:

```python
perm = list(range(len(seq.items)))
self.random.shuffle(perm)
seq.items[:] = [seq.items[i] for i in perm]          # constant order in the compiled code
...
indices = self.random.sample(range(len(elems)), k)
return variables.ListVariable([elems[i] for i in indices], ...)
```

whereas `random`/`randint`/`randrange`/`uniform` go through `_call_random` → `call_random_fn`, which records the call and re-executes it at run time (`output_graph.py`, `random_calls`). `shuffle`/`sample` have no run-time counterpart, so the trace-time draw is the only draw.

A second symptom from the same code is that `random.seed(k)` *inside* the compiled function is not applied on the first (compiling) call — `random.seed(0); random.random()` returns `0.9654…` on the first call and the correct `0.7579…` afterwards. I can file that separately if preferred (repro in the same script: `seed_fn`).

### Error logs

No error; silent wrong result (see output above).

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

Also reproduced on Linux (Kaggle, torch 2.14.0+cpu and 2.15.0.dev20260912+cpu, Python 3.11).
