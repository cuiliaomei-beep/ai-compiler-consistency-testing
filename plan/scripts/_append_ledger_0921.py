"""One-off: append the 2026-09-21 candidates (int/IEEE sweep triage) to TO_SUBMIT.md."""
import os

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
p = os.path.join(ROOT, "TO_SUBMIT.md")
s = open(p, encoding="utf-8").read()
MARK = "## 2026-09-21 新增（8.2 整数/IEEE 语义扫描分诊）"
if MARK not in s:
    s += f"""

{MARK}

全部 Inductor 独有（aot_eager 与 eager 一致），2.14.0 与 nightly 2.15.0.dev20260911 都复现；草稿 `../0920issues/07–11`；**未提交**。

| # | 发现 | 状态 | 提交稿 | 查重 | 根因 |
|---|---|---|---|---|---|
| 37 | int8/uint8 的 `min/max/amin/amax/argmin/argmax` 在 ≥16 个元素时错：全正数据 `min`=0、`argmin`=**-1**；全负 int8 `max`=0、`argmax`=-1；int16+ 正常 | **待评论**（open #191499 只报了 Apple Silicon 的 amin=0；补 x86-64、amax、arg*=-1） | `0920issues/07-*.md`；`reports_intub/int8_minmax_vector_padding.py` | #191499 同根因 | 生成代码 `Vectorized<uint8_t>::loadu(ptr, 16)` 只装 16 个元素，其余 16 个通道补 0 却参与归约 |
| 38 | **浮点 `//`：`1.0 // 0.1` 得 10（eager 与 Python 得 9）**；`0.5//0.1`→5、`6.0//0.2`→30；float32 与 float64；`div(rounding_mode='floor')` 同 | **待提交（中–高）** | `0920issues/08-*.md`；`reports_intub/floor_divide_python_example.py` | 无同报告；相关 open #184408（CUDA trunc 差 1） | `_inductor/lowering.py::_floor_div_floating` = `floor(div_rn(a,b))`；eager 是 fmod 算法 |
| 39 | **CPU 向量化 `remainder`/`%`**：除数 ±inf 得 nan、`1e20 % 3` 得 0、`-0.0 % 1` 丢符号；长度 3 正确、长度 ≥8 错 | **待提交（中–高）** | `0920issues/09-*.md`；`reports_intub/remainder_vector_vs_tail.py` | open #194345 是 CUDA 且称"compiled CPU 正确"（他们用单元素输入）；#186875 是半精度 + 标量 | `codegen/cpp.py::CppVecOverrides.remainder`：`a - floordiv(a,b)*b`；标量路径用 `mod()` |
| 40 | 显式 `x.half().float()` / `x.bfloat16().float()` 往返被消掉（`70000→inf` 也没了） | **待评论**（#185337 已 closed completed，请求 reopen） | `0920issues/10-*.md` | #185337 | Inductor 消除成对 dtype 转换 |
| 41 | `torch.clamp(int8, -1000, 1000)` 在 Inductor 下全为 -24、`clamp(max=300)` 把 127 变 44；2.14 eager 报错、nightly eager 返回原张量 | **待提交（中）** | `0920issues/11-*.md` | 无同报告 | clamp 的 Python 边界被按张量 dtype 绕回 |

不报：`atanh(次正规数)`→0 与 `erf` 3e-5 相对误差（精度类，量级小）；有符号零 15 条（`maximum/minimum/fmax/fmin/clamp(0.0,-0.0)`、`remainder(-0.0,·)`、`relu6(-0.0)`、`atanh(-0.0)`）——open #188680 伞形 issue 讨论的正是测试对有符号零不敏感，可在其下补清单；float→int 越界转换（C++ 与文档均为未定义）；eager `div(trunc)`/`lcm` 崩溃（重复 #138425 / #121343）。
"""
    open(p, "w", encoding="utf-8").write(s)
    print("ledger appended")
else:
    print("already there")
