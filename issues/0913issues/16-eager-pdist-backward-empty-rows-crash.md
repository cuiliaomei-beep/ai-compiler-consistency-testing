<!-- 提交信息（不要复制到 issue 里）；Summary 段按 SUMMARY_WRITING_GUIDE.md 的三句结构写：事实 / 困惑 / 暴露 -->
# pytorch/pytorch — issue 16

| 项 | 值 |
|---|---|
| 提交优先级 | 16 / 27 |
| 原候选编号 | TO_SUBMIT.md 第 7 条；草稿 `plan/issues_0910/07-*.md` |
| 仓库 | https://github.com/pytorch/pytorch |
| 验证版本 | torch 2.14.0+cpu（git `08187d9e0fba026dc8217405802ab5381dc88d90`），Windows 11 |
| **提交 issue 链接** | https://github.com/pytorch/pytorch/issues/new?template=bug-report.yml |
| 使用的模板 | `.github/ISSUE_TEMPLATE/bug-report.yml`（🐛 Bug Report；不是 compile 问题，用普通模板） |
| 提交前查重 | https://github.com/pytorch/pytorch/issues?q=is%3Aissue%20pdist%20backward%20empty · https://github.com/pytorch/pytorch/issues?q=is%3Aissue%20pdist%20integer%20division%20by%20zero · 2026-09-10 五组关键词无同报告；#183814（closed，pdist 的动态形状 DDE）与崩溃无关 |
| 证据包 | `plan/reports_decomp/pdist_empty_backward_crash/`（`minimal_verified.py` 逐例子进程运行、`DEDUP.md`），`plan/scripts/find_crash_variant.py nn.functional.pdist --grad` |
| 建议标签 | module: autograd, module: crash, module: cpu, topic: bug |
| 备注 | Windows 2.14.0+cpu：退出码 0xC0000094（STATUS_INTEGER_DIVIDE_BY_ZERO）；**Linux（Kaggle，torch 2.10.0+cpu，Python 3.12.13，Linux 6.12 / glibc 2.35）：SIGSEGV**，2026-09-10 验证，同样是前两例崩、后两例正常。`kaggle/verify/pdist_crash_linux.py` |

---

## Title

Backward of `F.pdist` on an input with zero rows crashes the process (SIGSEGV on Linux, integer division by zero on Windows), no Python exception

## Body

### 🐛 Describe the bug

**Summary.** The backward of `F.pdist` on an input with zero rows does not fail gracefully: the forward returns an empty `(0,)` tensor, and `.backward()` terminates the interpreter — SIGSEGV on Linux, `STATUS_INTEGER_DIVIDE_BY_ZERO` on Windows — with no Python exception (torch 2.10.0 through 2.14.0 and nightly); inputs with one or two rows are fine and CUDA is unaffected. A user whose batch happens to be empty loses the process rather than getting an error. Because the CPU `pdist_backward` kernel divides by the number of rows without guarding zero, the crash is decided by the input shape alone, and torch.compile reaches the same kernel.

`torch.nn.functional.pdist` accepts an input with zero rows and returns an empty `(0,)` tensor, but calling `.backward()` on that result terminates the interpreter: on Linux the process is killed by **SIGSEGV**, on Windows it exits with `0xC0000094` (`STATUS_INTEGER_DIVIDE_BY_ZERO`). No Python exception is raised, so a training loop whose batch happens to be empty dies without a traceback. Inputs with one row (zero pairs) and two rows are fine, so the backward kernel does not guard `n == 0`. Reproduced on torch 2.14.0+cpu (Windows) and torch 2.10.0+cpu (Linux, Kaggle).

Minimal reproducer (run each case in a fresh interpreter; the failing ones kill the process):

```python
import torch

n, d = 0, 4
x = torch.randn(n, d, requires_grad=True)
y = torch.nn.functional.pdist(x)
print("forward ok, output shape", tuple(y.shape))     # (0,)
y.sum().backward()                                    # <-- process dies here for n == 0
print("backward ok, grad shape", tuple(x.grad.shape))
```

Driver that runs the four cases in subprocesses:

```python
import subprocess, sys
CASE = '''
import sys, torch
n, d = int(sys.argv[1]), int(sys.argv[2])
x = torch.randn(n, d, requires_grad=True)
y = torch.nn.functional.pdist(x)
print("forward ok, output shape", tuple(y.shape), flush=True)
y.sum().backward()
print("backward ok, grad shape", tuple(x.grad.shape), flush=True)
'''
for n, d in ((0, 1), (0, 4), (1, 4), (2, 4)):
    r = subprocess.run([sys.executable, "-c", CASE, str(n), str(d)], capture_output=True, text=True)
    print(f"pdist on ({n}, {d}):", " | ".join(r.stdout.split("\n")[:2]),
          "" if r.returncode == 0 else f"<-- process died, exit code {r.returncode & 0xFFFFFFFF:#x}")
```

Output, Linux (Kaggle CPU notebook, torch 2.10.0+cpu, Python 3.12.13, Linux 6.12.90 / glibc 2.35):

```
torch 2.10.0+cpu | Linux-6.12.90+-x86_64-with-glibc2.35 | 3.12.13
pdist on (0, 1): forward ok, output shape (0,)   <-- process killed by signal 11 (SIGSEGV)
pdist on (0, 4): forward ok, output shape (0,)   <-- process killed by signal 11 (SIGSEGV)
pdist on (1, 4): forward ok, output shape (0,) | backward ok, grad shape (1, 4)
pdist on (2, 4): forward ok, output shape (1,) | backward ok, grad shape (2, 4)
```

Output, Windows 11 (torch 2.14.0+cpu, Python 3.14.7):

```
torch 2.14.0+cpu | Windows-11-10.0.26200-SP0 | 3.14.7
pdist on (0, 1): forward ok, output shape (0,)   <-- process died, exit code 0xc0000094
pdist on (0, 4): forward ok, output shape (0,)   <-- process died, exit code 0xc0000094
pdist on (1, 4): forward ok, output shape (0,) | backward ok, grad shape (1, 4)
pdist on (2, 4): forward ok, output shape (1,) | backward ok, grad shape (2, 4)
```

On CUDA (Tesla T4, same torch 2.10.0+cu128) the backward returns a `(0, 4)` gradient normally, so the crash is in the CPU `pdist_backward` kernel only.

Still present on nightly torch 2.15.0.dev20260911+cu130 (nightly, git fb8ff0f1, Kaggle: Tesla T4 + Linux CPU), Linux CPU: the child process dies with exit code -11 (SIGSEGV) right after `forward ok (0,)`; CUDA backward still returns a `(0, 4)` gradient.

Expected: either the backward returns a zero gradient of shape `(0, d)` (consistent with the forward accepting the input), or the forward rejects zero-row inputs with a `RuntimeError`. A hard crash is never acceptable.

Observed: the interpreter is killed inside `pdist_backward` (CPU) — SIGSEGV on Linux, integer division by zero on Windows, i.e. the `n == 0` case is not handled. `torch.compile` does not help since the compiled path calls the same kernel.

Found by a differential harness that runs every OpInfo sample forward + backward on edge-shape variants (here: the batch dimension resized to 0).

### Versions

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
