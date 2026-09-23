"""One-off bookkeeping (2026-09-22): Kaggle Linux/CUDA re-check (tcc-rewritelinux / tcc-rewritegpu) written back to drafts 14-16."""
import os

PLAN = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
ISSUES = os.path.join(os.path.dirname(PLAN), "0920issues")


def edit(name, old, new):
    import glob
    path = glob.glob(os.path.join(ISSUES, name))[0]
    s = open(path, encoding="utf-8").read()
    if new in s:
        return
    assert old in s, (name, old[:50])
    open(path, "w", encoding="utf-8").write(s.replace(old, new, 1))


K = "Linux 复核（Kaggle `tcc-rewritelinux` / `tcc-rewritegpu`，`plan/kaggle_out/rewritelinux.log`、`rewritegpu.log`）"
edit("14-*.md", "用户级复现需要 Inductor（`aot_eager` 正确） |",
     "用户级复现需要 Inductor（`aot_eager` 正确）；" + K + "：Linux CPU 2.14.0 与 nightly 2.15.0.dev20260920 两个代码块输出逐字相同（max diff 282；三个内核 False）；**CUDA（T4，2.14.0+cu130）上编译后的梯度正确** → 只影响 CPU 内核 |")
edit("14-*.md", "Same output on nightly 2.15.0.dev20260911+cpu.",
     "Same output on nightly (2.15.0.dev20260911 on Windows, 2.15.0.dev20260920 on Linux) and on Linux with 2.14.0. On CUDA (Tesla T4, 2.14.0+cu130) the compiled gradient matches eager, so only the CPU kernels are affected.")
edit("15-*.md", "Linux / CUDA 复核见 Kaggle `tcc-rewritelinux` / `tcc-rewritegpu`（结果出来后补一句） |",
     K + "：Linux CPU 2.14.0 与 nightly 2.15.0.dev20260920 输出逐字相同；**CUDA（T4，2.14.0+cu130）同样 `out is x: True`、输入被改成 6.0** → 与设备无关 |")
edit("15-*.md", "returns the input object itself (`out is x` is `True`; with `requires_grad` it is a different object that shares the input's storage), on torch 2.14.0 and nightly.",
     "returns the input object itself (`out is x` is `True`; with `requires_grad` it is a different object that shares the input's storage), on torch 2.14.0 and nightly, CPU and CUDA.")
edit("15-*.md", "Same output on nightly 2.15.0.dev20260911+cpu.",
     "Same output on nightly (2.15.0.dev20260911 on Windows, 2.15.0.dev20260920 on Linux), on Linux CPU with 2.14.0, and on CUDA (Tesla T4, 2.14.0+cu130), so the behaviour comes from the shared FX pass and not from a backend.")
edit("16-*.md", "Linux（gcc）待 Kaggle 复核确认不受影响。",
     "Linux（gcc）已复核不受影响（Kaggle `tcc-rewritelinux`：2.14.0 与 nightly 0920 上 int8/16/32/64 × 长度 5/40 全部与 eager 相等；T4 CUDA 也相等）→ 仅 MSVC。")
edit("16-*.md", "are not affected, and the same kernel built with GCC is expected to be correct.",
     "are not affected, and the same kernel built with GCC on Linux returns the correct result.")
print("ok")
