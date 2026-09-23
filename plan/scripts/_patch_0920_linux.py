"""One-off: record the Linux re-check (Kaggle tcc-xtargetlinux, 2026-09-20) in drafts 05 and 06."""
import os

D = os.path.join(os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__)))), "0920issues")


def rw(name, pairs):
    p = os.path.join(D, name)
    s = open(p, encoding="utf-8").read()
    for a, b in pairs:
        assert a in s, (name, a[:60])
        s = s.replace(a, b)
    open(p, "w", encoding="utf-8").write(s)


rw("05-jax-gcd-lcm-never-terminates-on-int-min.md", [
    ("**提交前建议在 Linux 上再跑一次同一脚本**（Kaggle 或 Colab），把结果补一句 |",
     "**Linux 已复核**（Kaggle，Linux x86-64，jax 0.11.2，Python 3.12：同一张表，逐行相同，`plan/kaggle_out/xtargetlinux.log`） |"),
    ("platform: Windows 11 (10.0.26200), AMD64\n```",
     "platform: Windows 11 (10.0.26200), AMD64\n```\n\nThe same ten probes give the same result on Linux x86-64 (jax 0.11.2, Python 3.12, CPU)."),
])
rw("06-numba-np-remainder-int-min-minus-one-kills-process.md", [
    ("Linux x86-64 上同一条 `idiv` 指令会触发 SIGFPE，**提交前建议在 Linux 上再跑一次同一脚本**并补一句 |",
     "**Linux 已复核**（Kaggle，Linux x86-64，numba 0.67.0，Python 3.12：同一张表，崩溃处子进程退出码 -8 = SIGFPE，`plan/kaggle_out/xtargetlinux.log`） |"),
    ("There is no Python exception: on Windows the process exits with status `0xC0000095` (integer overflow), which is the hardware trap of `idiv`.",
     "There is no Python exception: on Windows the process exits with status `0xC0000095` (integer overflow) and on Linux it is killed by `SIGFPE`, which is the hardware trap of `idiv`."),
    ("Environment: numba 0.67.0, llvmlite 0.49.0, numpy 2.5.3, Python 3.14.7, Windows 11 (10.0.26200) x64, Intel Core i9-11900T.",
     "Environment: numba 0.67.0, llvmlite 0.49.0, numpy 2.5.3, Python 3.14.7, Windows 11 (10.0.26200) x64, Intel Core i9-11900T. The table is identical on Linux x86-64 (numba 0.67.0, numpy 2.5.3, Python 3.12), where the three failing rows die with SIGFPE."),
])
readme = os.path.join(D, "README.md")
s = open(readme, encoding="utf-8").read()
s = s.replace("待提交（Linux 复核任务 `tcc-xtargetlinux` 已推送，结果见 `plan/kaggle_out/`）", "待提交（Windows + Linux 均已复核）")
s = s.replace("待提交（同上，等 Linux 复核）", "待提交（Windows + Linux 均已复核，Linux 上是 SIGFPE）")
open(readme, "w", encoding="utf-8").write(s)
print("patched")
