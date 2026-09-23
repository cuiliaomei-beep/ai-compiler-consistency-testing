<!-- 提交信息（不要复制到 GitHub） -->
# pytorch/pytorch — 0920 第 24 条：在 #174386 下的**评论稿**（已关闭为 completed，但 CPU 上仍复现）

| 项 | 值 |
|---|---|
| 评论位置 | https://github.com/pytorch/pytorch/issues/174386 （"`torch.compile` ignores `torch.use_deterministic_algorithms(True)` on `empty_like`"，dlibk，2026-02-05；标签 high priority；2026-03-02 关闭 → 03-12 被 eellison 重开 → 2026-05-10 再次以 completed 关闭，commit 87f82e72a4；相关 PR #174718 仍 open） |
| **提交网址** | https://github.com/pytorch/pytorch/issues/174386#new_comment_field |
| **怎么提交（是评论，不是新 issue）** | issue 已 closed（completed）但未锁定，可以评论；你不是原作者，没有 Reopen 按钮，稿子末尾已请维护者 reopen。① 登录 GitHub 后打开上面的提交网址，滚到页面最底部的评论框；② 在 **Write** 页签粘贴本文件 `## Comment` 标题**下面**到文件末尾的全部内容（不含这一行标题和上面这张表）；③ 点 **Preview** 检查渲染；④ 点绿色 **Comment**；⑤ 点评论右上角时间戳，把 `…#issuecomment-…` 链接贴给我登记。 |
| 为什么是评论 | 同一缺陷、原 issue 的复现程序**原样**在 2.14.0 与 nightly 上仍然失败；新开 issue 会被判重复。原是 22 号稿（#197554 第二条评论）的第 3 项，2026-09-22 当天查重时发现 #174386，拆出单独成稿 |
| 验证版本 | torch 2.14.0+cpu 与 nightly 2.15.0.dev20260911+cpu（Windows）；Linux CPU 2.14.0 与 nightly 2.15.0.dev20260921 同样不填充；Tesla T4 CUDA（2.14.0+cu130）：浮点 `empty*` 已填充，**整数 dtype 仍不填充**（Kaggle `tcc-safetylinux` / `tcc-safetygpu`，`plan/kaggle_out/safetylinux.log`、`safetygpu.log`）。`aot_eager` 与 eager 一致 |
| 提交前查重 | 2026-09-22：`deterministic fill_uninitialized_memory inductor`、`use_deterministic_algorithms empty_like compile`：#174386 即本体；无更新的同类报告 |
| 证据包 | `plan/reports_surgery/issue_174386_recheck.py`（原复现 + 5 个变体）、`deterministic_mode_parity.py`（7 种 `empty*` × CPU/CUDA）；发现来源 `plan/scripts/model_surgery_diff.py`（10.4，用例 `deterministic_mode_empty_is_filled`） |
| 优先级 | 中–低（原 issue 带 high priority 标签，所以值得补一句；排在 22 之后） |

---

## Comment

This still reproduces on CPU after the second close: the reproducer from the description, unchanged, fails on the 2.14.0 release and on nightly (2.15.0.dev20260911 on Windows, 2.15.0.dev20260921 on Linux), and so do the neighbouring factory functions. On CUDA (Tesla T4, 2.14.0+cu130) floating-point `empty*` results are filled now, but integer ones are not (`torch.empty(3, dtype=torch.int32)` is `INT_MAX` in eager and arbitrary under Inductor). `backend="aot_eager"` matches eager in every row, so it is the Inductor allocation path.

```python
import torch

torch._inductor.config.fallback_random = True
torch.use_deterministic_algorithms(True)

def filled(t):          # eager's documented fill: NaN for floating point, the maximum value for integers
    return bool(t.isnan().all()) if t.is_floating_point() else bool((t == torch.iinfo(t.dtype).max).all())

cases = {
    "empty_like(torch.randn(4, 4))   (reproducer of this issue)": lambda x: torch.empty_like(torch.randn(4, 4)),
    "empty_like(x), x a graph input": lambda x: torch.empty_like(x),
    "x.new_empty(4)": lambda x: x.new_empty(4),
    "torch.empty(5)": lambda x: torch.empty(5),
    "torch.empty(3, dtype=torch.int32)": lambda x: torch.empty(3, dtype=torch.int32),
    "empty_like(x) + 0": lambda x: torch.empty_like(x) + 0,
}
print(torch.__version__)
for name, f in cases.items():
    torch._dynamo.reset()
    x = torch.ones(4, 4)
    print(f"{name:60s} eager filled: {filled(f(x))!s:5s}  inductor filled: {filled(torch.compile(f)(x))}")
```

```
2.14.0+cpu
empty_like(torch.randn(4, 4))   (reproducer of this issue)   eager filled: True   inductor filled: False
empty_like(x), x a graph input                               eager filled: True   inductor filled: False
x.new_empty(4)                                               eager filled: True   inductor filled: False
torch.empty(5)                                               eager filled: True   inductor filled: False
torch.empty(3, dtype=torch.int32)                            eager filled: True   inductor filled: False
empty_like(x) + 0                                            eager filled: True   inductor filled: False
```

The last row shows it is not only about returning the buffer: a program that consumes the "uninitialized" values computes on arbitrary memory where eager computes on NaN. Could this be reopened? #174718 is still open and may be the missing piece for the C++ wrapper (`empty_strided_cpu`).
