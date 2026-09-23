"""One-off bookkeeping (2026-09-22): C++ toolchain-layer differential (10.13) -> drafts 17, 18; README / ledger / directions / report / memory."""
import os, re

PLAN = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
ISSUES = os.path.join(os.path.dirname(PLAN), "0920issues")

readme = os.path.join(ISSUES, "README.md")
s = open(readme, encoding="utf-8").read()
if "| 17 |" not in s:
    row16 = re.search(r"^\| 16 \|.*$", s, re.M).group(0)
    s = s.replace(row16, row16 + "\n"
        "| 17 | **Microsoft Visual C++** | 新反馈 | **MSVC 把向量 `_mm*_add_p{s,d}(x, 0.0)` 整个消掉，`-0.0 + 0.0` 得 `-0.0`（应为 `+0.0`）；`/fp:strict` 下也一样**，而标量 `x + 0.0f` 是对的（保留 `addss`）；128/256/512 位、ps/pd、零在左或右、`setzero` 或 `set1(0)` 都中 | 中（违反 /fp:strict；只影响零的符号） | 待提交（需微软账号） |\n"
        "| 18 | **Microsoft Visual C++** | 新反馈 | **MSVC `/arch:AVX2` 下把 `blendv(x, y, cmp(x, y, LE))`（`(x<=y)?y:x`）折叠成 `vmaxps(y, x)`，±0 平局时选错操作数**（`<` 形式折叠是精确的，`<=` 不是）；`min` 形式、pd、256 位同样；`/fp:strict` 下也一样；差分里 2,256 个函数全部归到这一条；已确认在 Inductor 上不表现 | 中（同上） | 待提交（需微软账号） |")
s = s.replace("建议提交顺序：01 → 14 → 15 → 16（微软）→", "建议提交顺序：01 → 14 → 15 → 16（微软；17、18 随后各开一张单）→")
if "cxx_intrinsic_algebra_diff.py" not in s:
    s = s.rstrip("\n") + "\n" + (
        "| `scripts/cxx_intrinsic_algebra_diff.py` | **C++ 工具链层**差分：109,754 个 SSE/AVX2/AVX-512 内建函数组合（U∘U、B(U,·)、B1(B2)、常量重结合、select 惯用法、洗牌、int↔float 往返），`/Od` 对 `/O1`/`/O2`/`/arch:AVX2`/`/arch:AVX512`（MSVC），`-O0` 对 `-O1/2/3`（g++/clang++，Kaggle `tcc-cxxalgebra`）；16、17、18 的来源 |\n"
        "| `scripts/cxx_algebra_families.py` | 把差分结果按内建函数贪心分族（几千个差异 → 几族） |\n"
        "| `scripts/run_issue_cpp_snippet.py` | 把草稿里的 ```cpp 代码块原样用 `cl` 在指定选项下编译运行（Git Bash 下要加 `MSYS_NO_PATHCONV=1`） |\n")
open(readme, "w", encoding="utf-8").write(s)


def edit(path, old, new):
    t = open(path, encoding="utf-8").read()
    if new in t:
        return
    assert old in t, (path, old[:50])
    open(path, "w", encoding="utf-8").write(t.replace(old, new, 1))


edit(os.path.join(PLAN, "TO_SUBMIT.md"),
     "**台账 43 更正（2026-09-21 深夜）**",
     "| 47 | **MSVC：向量 `add_p{s,d}(x, 0.0)` 被消掉，-0.0 不再变 +0.0；`/fp:strict` 也一样**（标量正确） | **待提交到 Developer Community（中）**（10.13 `cxx_intrinsic_algebra_diff.py`） | `0920issues/17-*.md`；`reports_rewrites/msvc_addzero/` | Web 无同报告 | 30 个差异函数（3 宽度 × ps/pd × 5 种写法）；`/Od` 对 |\n"
     "| 48 | **MSVC `/arch:AVX2`：`blendv(x,y,cmp LE)` → `vmaxps(y,x)`，±0 平局选错**；min 形式、pd、256 位同样；`/fp:strict` 也一样 | **待提交到 Developer Community（中）**（同上，词表 v2） | `0920issues/18-*.md`；`reports_rewrites/msvc_blend/` | Web 无同报告 | 2,256 个差异函数全部含 `blendv_p*` + `_CMP_LE_OS`；`<` 形式折叠精确；Inductor 上不表现（已查） |\n\n"
     "10.13 C++ 工具链层差分总账（MSVC 19.44，109,754 个组合，5 档选项）：值差异只有三族（abs∘abs 10、add-zero 30、LE-select 2,256），另有 148 个仅 NaN 载荷/符号不同（操作数交换，允许）。整数域除 abs∘abs 外全部一致（饱和加减重结合、移位、pack、洗牌、select 均无差异）。g++ 11.4 / clang++ 14 的同款差分在 Kaggle `tcc-cxxalgebra`（结果见 `kaggle_out/cxxalgebra.log`）。\n\n"
     "**台账 43 更正（2026-09-21 深夜）**")

nd = os.path.join(PLAN, "NEXT_DIRECTIONS.md")
t = open(nd, encoding="utf-8").read()
if "10.13" not in t:
    t = t.rstrip("\n") + "\n\n" + (
        "### 10.13 C++ 工具链层：内建函数组合的优化级别差分（2026-09-22 新增，**已落地**）\n\n"
        "- 动机：草稿 16 表明\"Inductor 生成的 C++ 是对的，错在宿主编译器\"。Inductor CPU 后端的正确性依赖 MSVC/GCC/Clang 对 `Vectorized<T>`（即 x86 内建函数）代码的优化是保语义的，这一层此前没人替 PyTorch 测。\n"
        "- 工具：`scripts/cxx_intrinsic_algebra_diff.py`。不经过 PyTorch，直接生成小函数（代数化简器会去匹配的形状：对合/幂等、常量重结合、select→min/max、洗牌合成、int↔float 往返），同一份源码用 `/Od` 与 `/O1`、`/O2`、`/arch:AVX2`、`/arch:AVX512` 各编一份，在每种 lane 宽度 16 个边界值的全部配对上比较（FNV 哈希；浮点另比一遍 NaN 规范化后的哈希）。编译 11 万个函数只要 30 秒。\n"
        "- 结果（MSVC 19.44）：三个缺陷 → 草稿 16、17、18。整数域、洗牌、pack、int↔float 往返全部干净（负结果）。\n"
        "- 后续：① g++/clang++（Kaggle，`--compiler gcc|clang`）；② 词表 v3：`fmadd` 家族、`mask_*`（AVX-512 掩码算子）、`cvt` 饱和/截断窄化、`maskload/maskstore`（Inductor 尾部处理就用它）；③ 三层组合与\"公共子表达式\"形状 `B(U(x), U(x))`；④ 同样的思路下沉到 Triton→LLVM（`tl.where`/`tl.abs`/`tl.minimum` 组合，`-O0` 对默认）；⑤ 直接拿 Inductor 真实生成的内核（`TORCH_COMPILE_DEBUG` 导出的 .cpp）做 `/Od` vs `/O2` 差分——把现有 sweep 的产物复用成编译器测试语料。\n")
    open(nd, "w", encoding="utf-8").write(t)

edit(os.path.join(PLAN, "EXECUTION_REPORT.md"),
     "**当前断点（2026-09-22 凌晨）**：",
     "**当前断点（2026-09-22 上午）**：新增 10.13 **C++ 工具链层差分** `scripts/cxx_intrinsic_algebra_diff.py`（109,754 个内建函数组合，`/Od` 对优化档）→ MSVC 19.44 三个缺陷：**草稿 16（abs∘abs→x）、17（向量 x+0.0 被消，/fp:strict 也错）、18（LE-select→vmaxps，±0 选错）**，都报给微软 Developer Community（需用户的微软账号，站内先搜重）。14/15 已在 Linux + T4 复核（14 仅 CPU；15 CPU+CUDA 都中）。g++/clang++ 同款差分在 Kaggle `tcc-cxxalgebra`（第一次因给非 AVX-512 机器传了 -mavx512* 而 SIGILL，已修并重推）。10.2 前缀扫描仍在跑，只有 1 ULP 级差异。`0920issues/` 现 18 份。下一步：读 `kaggle_out/cxxalgebra.log`；10.13 后续②⑤（maskload/真实内核语料）；10.3 模型手术/超参数；10.4 安全机制。\n\n"
     "**历史断点（2026-09-22 凌晨）**：")

mem = r"C:\Users\clm\.claude\projects\d--wsl-personal-dr-paper\memory\tcc-plan-status.md"
t = open(mem, encoding="utf-8").read()
line = ("- 2026-09-22 morning: NEW LAYER below PyTorch: scripts/cxx_intrinsic_algebra_diff.py (109,754 compositions of SSE/AVX2/AVX-512 intrinsics, unoptimised vs optimised build, edge values; "
        "families via scripts/cxx_algebra_families.py) found three MSVC 19.44 miscompiles -> 0920issues/16 (abs(abs(x))->x), 17 (vector x+0.0 removed, even /fp:strict), 18 (blendv+cmp LE -> vmaxps, wrong zero on ties, /arch:AVX2). "
        "These go to Visual Studio Developer Community (user needs Microsoft account; search the site first). Drafts 14/15 re-verified on Linux+T4 (14 CPU-only; 15 CPU+CUDA). g++/clang++ run on Kaggle job tcc-cxxalgebra. "
        "Verify C++ drafts with scripts/run_issue_cpp_snippet.py (set MSYS_NO_PATHCONV=1 in Git Bash). Ledger rows 45-48; 18 drafts. Nothing filed by me.\n")
if line not in t:
    open(mem, "w", encoding="utf-8").write(t + line)
print("recorded")
