"""One-off: fold the Linux CPU / nightly / T4 re-check (Kaggle tcc-intublinux, tcc-intubgpu, 2026-09-21) into drafts 07-11."""
import os

D = os.path.join(os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__)))), "0920issues")


def rw(name, pairs):
    p = os.path.join(D, name)
    s = open(p, encoding="utf-8").read()
    for a, b in pairs:
        assert a in s, (name, a[:70])
        s = s.replace(a, b)
    open(p, "w", encoding="utf-8").write(s)


LINUX = "Linux 复核（Kaggle，`plan/kaggle_out/intublinux.log`、`intubgpu.log`）"

rw("07-comment-on-191499-int8-minmax-argmin-x86.md", [
    ("| 验证版本 | torch 2.14.0+cpu 与 nightly 2.15.0.dev20260911+cpu，Windows 11 x64（AVX2，MSVC）；",
     "| 验证版本 | torch 2.14.0+cpu 与 nightly 2.15.0.dev20260911+cpu，Windows 11 x64（AVX2，MSVC）；" + LINUX +
     "：两台 Linux x86-64 机器（GCC）上同样出错但**错法不同**——一台 `argmin`=0、全负 int8 的 `max`=1；另一台 `min`=0、`argmin`=**-8473051087277178060（未初始化的下标）**；nightly 2.15.0.dev20260920 同样；CUDA（Triton）正确；"),
    ("- int16, int32, int64 and floating dtypes are correct on the same data.",
     "- int16, int32, int64 and floating dtypes are correct on the same data, and so is CUDA (Triton).\n"
     "- **The wrong value depends on the CPU.** The same script on two Linux x86-64 machines (GCC, torch 2.14.0 and nightly 2.15.0.dev20260920) gives "
     "`argmin = 0`, `max = 1` (all-negative int8, eager `-1`), `argmax = 0` on one, and `min = 0`, `argmin = -8473051087277178060`, `max = 0`, `argmax = 0` on the other; "
     "the last index is uninitialised memory, so the lanes that were not loaded are not even guaranteed to be zero."),
])
rw("08-inductor-float-floor-divide-off-by-one.md", [
    ("| 验证版本 | torch 2.14.0+cpu 与 nightly 2.15.0.dev20260911+cpu（Windows，CPU）；",
     "| 验证版本 | torch 2.14.0+cpu 与 nightly 2.15.0.dev20260911+cpu（Windows，CPU）；" + LINUX + "：Linux CPU 2.14.0 与 nightly 2.15.0.dev20260920、**Tesla T4 CUDA 2.14.0+cu130 输出逐字相同**；"),
    ("(torch 2.14.0 and nightly, CPU; `aot_eager` matches eager)", "(torch 2.14.0 and nightly, CPU and CUDA, Windows and Linux; `aot_eager` matches eager)"),
    ("Same output on nightly 2.15.0.dev20260911+cpu.", "Same output on nightly (2.15.0.dev20260911 on Windows, 2.15.0.dev20260920 on Linux), on Linux CPU with 2.14.0, and on CUDA (Tesla T4, 2.14.0+cu130)."),
])
rw("09-inductor-cpu-vectorized-remainder-nan-and-length-dependent.md", [
    ("| 验证版本 | torch 2.14.0+cpu 与 nightly 2.15.0.dev20260911+cpu（Windows，AVX2）；",
     "| 验证版本 | torch 2.14.0+cpu 与 nightly 2.15.0.dev20260911+cpu（Windows，AVX2）；" + LINUX +
     "：Linux CPU 2.14.0 与 nightly 2.15.0.dev20260920 同样出错，且其中一台机器上**连 3 个元素的张量也得 nan**（尾部也走带掩码的向量路径），另一台与 Windows 一样是长度 3 正确、长度 8 错；CUDA（Triton）正确；"),
    ("## Title\n\n[inductor][cpu] Vectorized `torch.remainder` / `%` returns NaN for an infinite divisor and 0 for large quotients; the same element is correct in the scalar tail, so the result depends on the tensor length",
     "## Title\n\n[inductor][cpu] Vectorized `torch.remainder` / `%` returns NaN for an infinite divisor and 0 for large quotients; elements handled by the scalar tail are correct, so the result depends on the tensor length and on the CPU"),
    ("while the same elements in a 3-element tensor are computed correctly (torch 2.14.0 and nightly, float32 and float64; `aot_eager` matches eager; `torch.fmod` is unaffected).",
     "while on an AVX2 machine the same elements in a 3-element tensor are computed correctly because they take the scalar tail (torch 2.14.0 and nightly, Windows and Linux, float32 and float64; `aot_eager` matches eager; `torch.fmod` and CUDA are unaffected)."),
    ("Related: #194345",
     "The length dependence is specific to the instruction set: on one Linux x86-64 machine the 3-element call above also returns `[nan, nan, nan]`, because there the tail is vectorized with a masked load as well; on another Linux machine and on Windows (AVX2) the output is exactly the one shown.\n\nRelated: #194345"),
    ("Same output on nightly 2.15.0.dev20260911+cpu.", "Same output on nightly (2.15.0.dev20260911 on Windows, 2.15.0.dev20260920 on Linux)."),
])
rw("10-comment-on-185337-explicit-half-cast-roundtrip-still-elided.md", [
    ("| 验证版本 | torch 2.14.0+cpu 与 nightly 2.15.0.dev20260911+cpu，Windows x64；",
     "| 验证版本 | torch 2.14.0+cpu 与 nightly 2.15.0.dev20260911+cpu，Windows x64；" + LINUX + "：Linux CPU 2.14.0 与 nightly 2.15.0.dev20260920 输出相同；**CUDA（T4，2.14.0+cu130）上同样被消掉**（`[0.1, 70000.0]` 原样返回）；"),
    ("This still reproduces on the 2.14.0 release and on nightly (2.15.0.dev20260911+cpu), with a smaller program than the one above: no reduction is needed, the explicit round trip alone is dropped on CPU.",
     "This still reproduces on the 2.14.0 release and on nightly (2.15.0.dev20260911 on Windows, 2.15.0.dev20260920 on Linux), with a smaller program than the one above: no reduction is needed, the explicit round trip alone is dropped. It is not limited to the CPU backend either: on CUDA (Tesla T4, 2.14.0+cu130) `torch.compile(lambda t: t.half().float())` returns `[0.1, 70000.0]` unchanged where eager returns `[0.09997558, inf]`."),
])
rw("11-inductor-clamp-out-of-range-python-bounds-wrap.md", [
    ("Windows x64 |", "Windows x64；" + LINUX + "：Linux CPU 两个版本输出与下文逐字相同，CUDA（T4，2.14.0+cu130）上 Inductor 同样返回 `[-24, -24, -24, -24, -24]` |"),
    ("PyTorch version: 2.14.0+cpu   (and nightly 2.15.0.dev20260911+cpu)", "PyTorch version: 2.14.0+cpu   (and nightly 2.15.0.dev20260911+cpu; same results on Linux CPU, nightly 2.15.0.dev20260920, and CUDA 2.14.0+cu130 on a Tesla T4)"),
])
r = os.path.join(D, "README.md")
s = open(r, encoding="utf-8").read()
s = s.replace("07–11 的 Linux CPU（2.14 + nightly）与 T4 CUDA 复核任务：`tcc-intublinux`、`tcc-intubgpu`（结果在 `plan/kaggle_out/`，出来后补进各草稿头部）。",
              "07–11 已在 Linux CPU（2.14.0 与 nightly 2.15.0.dev20260920）和 T4 CUDA 上复核（`plan/kaggle_out/intublinux.log`、`intubgpu.log`），结果已写进各草稿：08、10、11 在 CPU 与 CUDA 上逐字相同；07、09 是 CPU 专属，且不同 CPU 上错法不同（07 在一台机器上 `argmin` 返回未初始化的大负数；09 在一台机器上 3 个元素也得 nan）。")
open(r, "w", encoding="utf-8").write(s)
print("patched 07-11 + README")
