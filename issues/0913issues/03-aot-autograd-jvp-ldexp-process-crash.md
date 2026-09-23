<!-- 提交信息（不要复制到 issue 里）；Summary 段按 SUMMARY_WRITING_GUIDE.md 的三句结构写：事实 / 困惑 / 暴露 -->
# pytorch/pytorch — issue 03

| 项 | 值 |
|---|---|
| 提交优先级 | 03 / 27 |
| 原候选编号 | TO_SUBMIT.md 第 27 条；草稿 `plan/issues_0910/27-*.md` |
| 仓库 | https://github.com/pytorch/pytorch |
| 验证版本 | torch 2.14.0+cpu（Windows 0xC0000005；Linux SIGSEGV exit -11）；nightly 2.15.0.dev20260911（Windows）/ dev20260912（Linux，`kaggle_out/jvplinux.txt`），同 |
| **提交 issue 链接** | https://github.com/pytorch/pytorch/issues/new?template=pt2-bug-report.yml |
| 使用的模板 | `.github/ISSUE_TEMPLATE/pt2-bug-report.yml`（🐛 torch.compile Bug Report，label: oncall: pt2） |
| 提交前查重 | https://github.com/pytorch/pytorch/issues?q=is%3Aissue%20jvp%20compile%20ldexp · https://github.com/pytorch/pytorch/issues?q=is%3Aissue%20forward%20AD%20compile%20crash（`results/dedup_0913d.txt`，无同报告；open #193277 是 autograd.Function 自定义 jvp 被 Dynamo 丢弃，不同） |
| 证据包 | `plan/scripts/diag_jvp_ldexp_crash.py`（每例子进程运行，打印退出码），`plan/results/forward_ad/FORWARD_AD.md`（6.4d 全量：507 个支持前向 AD 的算子中只有 ldexp 让进程消失） |
| 建议标签 | oncall: pt2, module: aotdispatch, module: forward ad, module: crash |
| 备注 | 硬崩溃（access violation / SIGSEGV），没有 Python 异常。inductor 后端不崩（走的分解不同），backend=eager 也不崩，eager 的 jvp 正常，aot_eager 的普通前向/反向对 ldexp 也正常 → 只在 AOTAutograd 处理 ldexp 的 dual tensor 时。ldexp 也是第 18 条（Inductor dtype）的主角 |

---

## Title

[aot_autograd] process crash (access violation) when `torch.func.jvp` over `torch.ldexp` is compiled with `backend="aot_eager"`

## Body

### 🐛 Describe the bug

**Summary.** `torch.func.jvp` over `torch.ldexp` does not survive compilation with `backend="aot_eager"`: eager `jvp`, `backend="eager"` and `inductor` return the tangent, while `aot_eager` terminates the interpreter with an access violation on Windows and SIGSEGV on Linux (torch 2.14.0 and nightly). A user sees the process disappear without a Python traceback, and neither the forward nor the backward pass of the same function under `aot_eager` shows any problem, so the crash is hard to attribute. Because the failure sits in how AOTAutograd handles this operator's dual tensors rather than in the model, it reproduces on any platform with the same one-line function.

```python
import torch

torch.manual_seed(0)
e = torch.randint(-3, 3, (3, 4)).float()
f = lambda a: torch.ldexp(a, e)
x, t = torch.randn(3, 4), torch.randn(3, 4)

torch.func.jvp(f, (x,), (t,))                                                       # eager: fine
torch.compile(lambda x, t: torch.func.jvp(f, (x,), (t,)), backend="eager")(x, t)    # fine
torch.compile(lambda x, t: torch.func.jvp(f, (x,), (t,)))(x, t)                     # inductor: fine
torch.compile(lambda x, t: torch.func.jvp(f, (x,), (t,)), backend="aot_eager")(x, t)   # <-- interpreter dies
```

Running each line in a child process (`scripts/diag_jvp_ldexp_crash.py`), torch 2.14.0+cpu on Windows:

```
[eager jvp]                       exit=0
[compile(eager) jvp]              exit=0
[compile(aot_eager) jvp]          exit=3221225477 (0xc0000005)      <- access violation, no Python traceback
[compile(inductor) jvp]           exit=0
[compile(aot_eager) forward only] exit=0
[compile(aot_eager) backward]     exit=0
```

Identical on the 2026-09-11 nightly, and on Linux / Python 3.11 (torch 2.14.0+cpu and 2.15.0.dev20260912+cpu) where the child exits with SIGSEGV (-11). No warning or Python exception precedes the crash. Every other operator with forward-AD support in the OpInfo database goes through the same `compile(jvp(f))` path without a crash (a sweep over 507 operators; the only other failures are the `_make_dual` internal assertions reported separately), so it is specific to `ldexp`'s forward-mode formula under AOTAutograd.

Expected: same tangent as eager, or a Python-level error.

### Error logs

None — the process exits with 0xC0000005 (Windows access violation) / SIGSEGV (Linux).

### Versions

(torch 2.14.0+cpu, Windows 11, Python 3.14; same on the 2026-09-11 nightly wheel. Full `collect_env` as in the other drafts.)
