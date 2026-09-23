# 在 Linux 上确认 issue 草稿 07（pdist 零行 backward 崩溃）

本机无 WSL。三种免安装的办法，任选其一。

## A. Kaggle（推荐，已有流程）

新建 Notebook（CPU 即可，不用 GPU），两个 cell：

Cell 1 —— 装与 issue 一致的 torch 2.14.0 CPU 版（约 1–2 分钟）：

```
!pip install -q torch==2.14.0 --index-url https://download.pytorch.org/whl/cpu
```

Cell 2 —— 直接粘贴脚本（不依赖数据集）：

```python
import platform, signal, subprocess, sys, torch

CASE = r'''
import sys, torch
n, d = int(sys.argv[1]), int(sys.argv[2])
x = torch.randn(n, d, requires_grad=True)
y = torch.nn.functional.pdist(x)
print("forward ok, output shape", tuple(y.shape), flush=True)
y.sum().backward()
print("backward ok, grad shape", tuple(x.grad.shape), flush=True)
'''
print("torch", torch.__version__, "|", platform.platform(), "|", sys.version.split()[0])
for n, d in ((0, 1), (0, 4), (1, 4), (2, 4)):
    r = subprocess.run([sys.executable, "-c", CASE, str(n), str(d)], capture_output=True, text=True)
    out = " | ".join(r.stdout.strip().splitlines())
    if r.returncode == 0:
        status = ""
    elif r.returncode < 0:
        status = f"   <-- process killed by signal {-r.returncode} ({signal.Signals(-r.returncode).name})"
    else:
        status = f"   <-- process died, exit code {r.returncode & 0xFFFFFFFF:#x}"
    print(f"pdist on ({n}, {d}): {out}{status}")
```

预期输出（Linux）：前两行 `killed by signal 8 (SIGFPE)`，后两行正常。把这段输出连同第一行的版本信息贴进 issue 的
"Error logs"/描述里即可（`torch 2.14.0+cpu | Linux-...-x86_64 | 3.11.x`）。

如果 Cell 1 不想重装 torch，直接跑 Cell 2 也行：Kaggle 自带的 torch 2.10 也会崩，可作为"多版本复现"补充，但 issue 主体仍以 2.14.0 为准。

## B. Google Colab

同上两个 cell，一字不改。

## C. GitHub Actions（能留下公开日志链接）

在任意自己的仓库加 `.github/workflows/pdist.yml`：

```yaml
name: pdist-crash
on: workflow_dispatch
jobs:
  run:
    runs-on: ubuntu-latest
    steps:
      - uses: actions/setup-python@v5
        with: { python-version: "3.12" }
      - run: pip install torch==2.14.0 --index-url https://download.pytorch.org/whl/cpu
      - run: |
          curl -sL <把 pdist_crash_linux.py 放到仓库后用相对路径> || true
          python pdist_crash_linux.py
```

把 `plan/kaggle/verify/pdist_crash_linux.py` 提交到仓库，Actions 页面手动触发，日志 URL 可贴进 issue。

## 不额外验证也可以提交

`pdist_backward` 的 CPU kernel 没有平台相关分支，除零发生在同一段 C++ 里；issue 草稿已写明"verified on Windows
(0xC0000094); expected SIGFPE on Linux"，维护者通常会在 Linux 上自行确认。上面三条只是让报告更硬。
