<!-- 提交信息（不要复制到 issue 里） -->
# pytorch/pytorch — 0920 issue 43（高：Windows 上 AOTI runner 在一次推理后立刻销毁 → 进程访问违例崩溃；只要模型里有 OpenMP 并行内核（≥ 4096 元素）；`OMP_NUM_THREADS=1`、`cpp.threads=1`、或销毁前 sleep 2 秒都能避免——模型 DLL 在 OpenMP 工作线程仍在自旋时被卸载）

| 项 | 值 |
|---|---|
| 仓库 | https://github.com/pytorch/pytorch |
| 验证版本 | torch 2.14.0+cpu 与 nightly 2.15.0.dev20260911+cpu（Windows 11，MSVC 19.44，Python 3.14，8 核）；Linux（Kaggle `tcc-aotifreelinux2`，2.14 + nightly 0922）：9 种组合全部正常退出——**Windows 独有** |
| **提交 issue 链接** | https://github.com/pytorch/pytorch/issues/new?template=pt2-bug-report.yml |
| 使用的模板 | `.github/ISSUE_TEMPLATE/pt2-bug-report.yml` |
| 提交前查重 | 2026-09-22 21:30：`aoti segfault runner destructor output alias input`、`aoti_load_package segmentation fault`、`AOTInductor crash when model deleted`、`aoti runner free double free`、`AOTI segfault windows destructor`、`aoti output tensor use after free model destroyed`、`AOTIModelPackageLoader destructor`、`AOTI windows crash free`：无同报告。相关但不同：#195090（模型销毁时 unmap mmap 常量，已合入）、#197516（AOTI 加载持 GIL） |
| 证据包 | 7.7 扫描 `scripts/export_roundtrip_edge.py` 在 `slice_scatter` 处进程 segfault（退出码 139）→ 最小化 `$TEMP/ss_min.py` / `ss_var.py` / `ss_size.py` / `ss_omp.py`：与算子无关，只与输出元素数 ≥ 4096（Inductor `cpp.min_chunk_size`，即循环被 `#pragma omp parallel` 化的阈值）有关；`cfg.cpp.threads = 1`、`cfg.cpp.min_chunk_size = 1e9`、`OMP_NUM_THREADS=1`、销毁前 `time.sleep(2)` 四种办法都不崩；`-X faulthandler` 显示多个线程同时 access violation |
| 根因（推断） | `AOTIModelPackageLoader` 析构时 `FreeLibrary` 卸载模型 DLL；MSVC 编译的模型里 `#pragma omp parallel` 的 outlined 函数在该 DLL 内，一次并行区域结束后 OpenMP 工作线程还会自旋等待一段时间（KMP_BLOCKTIME / vcomp 的自旋），此时卸载 DLL → 工作线程执行到已释放的代码页 → 访问违例。sleep 2 秒后线程已休眠，卸载安全；单线程则根本没有工作线程。Linux（gcc/libgomp）不崩：libgomp 的工作线程在并行区域外驻留在 libgomp.so 里，`dlclose` 模型 .so 不影响；MSVC 的 vcomp 工作线程自旋位置在模型 DLL 内（或该 DLL 静态链接了 OpenMP 运行时） |
| 建议标签 | oncall: pt2, module: aotinductor, module: windows, module: crash |

---

## Title

[aoti][windows] Destroying an AOTI runner right after a run crashes the process (access violation) whenever the model has an OpenMP-parallel kernel (output ≥ 4096 elements): the model DLL is unloaded while its OpenMP worker threads are still spinning

## Body

### 🐛 Describe the bug

**Summary.** On Windows, `runner = aoti_load_package(pkg); out = runner(x); del runner` crashes the process with an access violation for a model as small as `x + 1` once `x` has 4096 or more elements, while 1024 elements, or Linux, exit normally (torch 2.14.0 and nightly, MSVC 19.44). A user who loads an AOTI package, runs it once and lets the runner go out of scope gets a hard crash with no Python exception, only for inputs large enough that Inductor parallelised. Because the loader unloads the model DLL as soon as the runner is destroyed, while the OpenMP workers of the last parallel region still spin-wait in code inside that DLL, rather than parking them first, every parallel AOTI model is unsafe to destroy on Windows right after a call.

```python
import gc
import os
import subprocess
import sys
import tempfile

import torch

CHILD = """
import gc, os, sys, time, tempfile, torch
from torch._inductor import aoti_compile_and_package, aoti_load_package

n, variant = int(sys.argv[1]), sys.argv[2]

class M(torch.nn.Module):
    def forward(self, x):
        return x + 1

x = torch.randn(n)
ep = torch.export.export(M(), (x,))
pkg = aoti_compile_and_package(ep, package_path=os.path.join(tempfile.mkdtemp(), "m.pt2"))
runner = aoti_load_package(pkg)
out = runner(x)
assert torch.equal(out, x + 1)
if variant == "sleep":
    time.sleep(2)          # let the OpenMP workers stop spinning
del runner                 # unloads the model DLL
gc.collect()
print("runner destroyed OK", flush=True)
"""

print("torch", torch.__version__)
for n in (1024, 4096, 65536):
    for variant, env in (("plain", {}), ("sleep 2 s before del", {}), ("OMP_NUM_THREADS=1", {"OMP_NUM_THREADS": "1"})):
        r = subprocess.run([sys.executable, "-c", CHILD, str(n), variant.split()[0]], capture_output=True, text=True, env={**os.environ, **env})
        last = (r.stdout.strip().splitlines() or ["<no output>"])[-1]
        print(f"n={n:6d}  {variant:22s} exit code {r.returncode:>11}  {last}")
```

```
torch 2.14.0+cpu
n=  1024  plain                  exit code           0  runner destroyed OK
n=  1024  sleep 2 s before del   exit code           0  runner destroyed OK
n=  1024  OMP_NUM_THREADS=1      exit code           0  runner destroyed OK
n=  4096  plain                  exit code  3221225477  <no output>
n=  4096  sleep 2 s before del   exit code           0  runner destroyed OK
n=  4096  OMP_NUM_THREADS=1      exit code           0  runner destroyed OK
n= 65536  plain                  exit code  3221225477  <no output>
n= 65536  sleep 2 s before del   exit code           0  runner destroyed OK
n= 65536  OMP_NUM_THREADS=1      exit code           0  runner destroyed OK
```

Exit code `3221225477` is `0xC0000005`, STATUS_ACCESS_VIOLATION. The crash does not depend on the operator (first seen with `slice_scatter`, reproduced with `x + 1`, `clone`, `x * 0 + src`), on whether the output tensor is still alive, or on how many inputs the model has; it depends only on whether the generated kernel is parallel. The threshold of 4096 elements is exactly `torch._inductor.config.cpp.min_chunk_size`, below which Inductor does not emit `#pragma omp parallel`; setting `torch._inductor.config.cpp.threads = 1` or `cpp.min_chunk_size = 10**9` before compiling also makes the crash disappear. With `python -X faulthandler` several threads report `Windows fatal exception: access violation` at the same moment, i.e. the OpenMP worker threads, not the main thread.

**Root cause (inferred) and possible fix.** `AOTIModelPackageLoader`'s destructor unloads the model library (`FreeLibrary`). The outlined bodies of `#pragma omp parallel` regions are compiled into that DLL; after a region finishes, the OpenMP runtime keeps the worker threads spin-waiting for a while (the usual block-time optimisation) with return addresses inside the region function that has just been unloaded, so they fault as soon as the pages are gone. Sleeping past the spin window, or running single-threaded, avoids it, which matches this explanation. A fix on the loader side is to make the model quiesce its OpenMP team before the library is unloaded, e.g. run a trivial `omp parallel` region with `omp_set_num_threads(1)` / `omp_set_dynamic` or use the runtime's block-time control (`KMP_BLOCKTIME=0` equivalent, `omp_pause_resource_all` in OpenMP 5.0) in the model container destructor, or not unload the library at all while any runner or output from it exists; at minimum the Windows loader should not `FreeLibrary` a module that owns live OpenMP threads.

### Error logs

No Python exception; the process dies with STATUS_ACCESS_VIOLATION (`0xC0000005`, exit code 3221225477). With `python -X faulthandler` the stderr is the interleaved output of several threads faulting at once (verbatim, first lines):

```
Windows fatal exception: access violationWindows fatal exception: 
access violationThread 0x
00000e34
Current thread's C stack trace (most recent call first):
 [  <cannot get C stack on this system>
tWindows fatal exception: access violation
```

### Versions

```
PyTorch version: 2.14.0+cpu
OS: Microsoft Windows 11 Pro for Workstations (10.0.26200 64-bit)
MSVC: Microsoft (R) C/C++ Optimizing Compiler Version 19.44.35228 for x64
Python version: 3.14.7 (64-bit runtime)
Is CUDA available: False
CPU: 11th Gen Intel(R) Core(TM) i9-11900T @ 1.50GHz (8 cores)
[pip3] numpy==2.5.2
[pip3] torch==2.14.0+cpu
```

Same on nightly 2.15.0.dev20260911+cpu. On Linux x86-64 (Kaggle, torch 2.14.0+cpu and nightly 2.15.0.dev20260922+cpu, gcc) the identical script exits 0 for every case, so this is Windows-specific.
