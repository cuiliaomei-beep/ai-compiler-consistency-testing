<!-- 提交信息（不要复制到 issue 里） -->
# Microsoft Visual C++（Developer Community）— 0920 issue 18（中：`blendv(x, y, x <= y)` 被折叠成 `vmaxps`，±0 平局时选错；`/fp:strict` 下也一样）

| 项 | 值 |
|---|---|
| 提交目标 | **Visual Studio Developer Community**：https://developercommunity.visualstudio.com/cpp/report （与 05、17 各一张单） |
| **怎么填（Developer Community 是三步表单）** | ① *Enter your problem*：**Description** 框里粘贴本文件 `## Body` 标题下面的全部内容（到文件末尾，或到“以下不属于给微软的正文”那条分隔线为止；编辑器识别 Markdown，三个反引号的代码块会正常渲染）；下面的 “Choose how the issue impacts you” 可选 *It's more difficult to complete my work*（或留空）；点 **Search**。② *Recommended solution*：页面会列出相似工单——扫一眼有没有同一个问题（本稿搜 `blendv maxps`）；没有就点继续 / *Submit a new ticket*。③ *Submit a ticket*：把自动生成的标题**整个换成**本文件 `## Title` 下面那一行；产品选 Visual Studio 2022（17.14）/ C++；可把 `plan/reports_rewrites/msvc_blend/blend.cpp` 作为附件上传（可选，附件只有微软能看到）；提交。提交后把反馈页网址（`https://developercommunity.visualstudio.com/t/…/数字`）贴给我登记。 |
| 验证版本 | MSVC 19.44.35228 x64（VS 2022 17.14）。`/Od` 正确；`/O2`（SSE 编码）下 `LE`/`GE` 正确、**`NLE_US` 已经错**；**`/O1 /arch:AVX2`、`/O2 /arch:AVX2`、`/O2 /arch:AVX2 /fp:strict`、`/O2 /arch:AVX512` 错**；256 位版本只要开优化就错（本来就是 VEX 编码） |
| 提交前查重 | 2026-09-21：Web 搜索未找到同报告（**提交前请在 Developer Community 站内再搜一次 `blendv maxps` / `_mm_blendv_ps _mm_cmp_ps`**） |
| 证据包 | `plan/reports_rewrites/msvc_blend/blend.cpp`、`build_and_run.py`（7 档选项 + 汇编）；发现来源 `plan/scripts/cxx_intrinsic_algebra_diff.py`（词表 v2：109,754 个组合；MSVC 共三族差异：05 号 abs(abs) 10 个、17 号 add-zero 30 个、本条约 2,500 个——全部含 `blendv_p{s,d}` / `mask_blend_p{s,d}` + 带等号的谓词 `LE_OS` / `GE_OS` / `NLE_US`；词表 v3 共 124,334 个组合，FMA 族与 AVX-512 整数掩码算子无差异）；分族脚本 `scripts/cxx_algebra_families.py` |
| 与 PyTorch 的关系 | Inductor 的 `Vectorized<float>::blendv` + 比较掩码正是 `torch.where(x <= y, y, x)`、`clamp`、`relu` 变体的生成形式；**已检查：在 Inductor 上不表现**（`plan/reports_rewrites/msvc_blend/inductor_where_le.py`：`torch.where(x <= y, y, x)` 等 4 种写法 × float32/64 × simdlen 256/512，符号位与 eager 全部一致——Inductor 的掩码要经过 `VecMask` 转换，MSVC 匹配不到这个模式）。所以本条是纯编译器报告 |
| 严重度说明 | 只在 `x`、`y` 为 `+0.0` / `-0.0` 平局时结果不同（返回了另一个零）。NaN 情况折叠后仍然正确 |

---

## Title

MSVC x64 optimizer folds compare-and-blend selects with `_CMP_LE_OS` / `_CMP_GE_OS` / `_CMP_NLE_US` into `maxps` / `minps`: wrong operand for zeros of opposite sign (`blendv`, AVX-512 `mask_blend`; also under `/fp:strict`)

## Body

**Summary.** The select `(x <= y) ? y : x`, written as `_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LE_OS))`, returns `y` when the operands compare equal, so for `x = +0.0, y = -0.0` it returns `-0.0` at `/Od`; with `/O1` or `/O2` and `/arch:AVX2` or `/arch:AVX512`, MSVC 19.44.35228 replaces the compare-and-blend pair by `vmaxps y, x`, which returns `x` (`+0.0`) on equality, and `/fp:strict` does not disable the fold. Code that selects between zeros of opposite sign gets the other zero only in optimised VEX-encoded builds (256-bit code already at plain `/O2`). Because predicates that include equality (`_CMP_LE_OS`, `_CMP_GE_OS`, `_CMP_NLE_US`) are folded like the strict ones rather than kept as compare and blend, the `ps` / `pd`, `blendv` and AVX-512 `mask_blend` forms are all affected, `_CMP_NLE_US` even in the SSE encoding.

```cpp
#include <immintrin.h>
#include <cstdio>
#include <cmath>

__declspec(noinline) void select_le(const float* px, const float* py, float* po) {   // (x <= y) ? y : x
    __m128 x = _mm_loadu_ps(px), y = _mm_loadu_ps(py);
    _mm_storeu_ps(po, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LE_OS)));
}
__declspec(noinline) void select_lt(const float* px, const float* py, float* po) {   // (x <  y) ? y : x
    __m128 x = _mm_loadu_ps(px), y = _mm_loadu_ps(py);
    _mm_storeu_ps(po, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LT_OS)));
}
__declspec(noinline) void select_nle(const float* px, const float* py, float* po) {  // !(x <= y) ? y : x
    __m128 x = _mm_loadu_ps(px), y = _mm_loadu_ps(py);
    _mm_storeu_ps(po, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_NLE_US)));
}
__declspec(noinline) void select_le_min(const double* px, const double* py, double* po) {   // (x <= y) ? x : y
    __m256d x = _mm256_loadu_pd(px), y = _mm256_loadu_pd(py);
    _mm256_storeu_pd(po, _mm256_blendv_pd(y, x, _mm256_cmp_pd(x, y, _CMP_LE_OS)));
}

int main() {
    float x[4] = {+0.0f, -0.0f, 1.0f, 5.0f}, y[4] = {-0.0f, +0.0f, 1.0f, 2.0f}, o[4];
    double xd[4] = {+0.0, -0.0, 1.0, 5.0}, yd[4] = {-0.0, +0.0, 1.0, 2.0}, od[4];
    std::printf("x = +0 -0 1 5,  y = -0 +0 1 2\n");
    select_le(x, y, o);
    std::printf("(x <= y) ? y : x   ->  %s0 %s0 %g %g   (expected -0 +0 1 5)\n", std::signbit(o[0]) ? "-" : "+", std::signbit(o[1]) ? "-" : "+", o[2], o[3]);
    select_lt(x, y, o);
    std::printf("(x <  y) ? y : x   ->  %s0 %s0 %g %g   (expected +0 -0 1 5)\n", std::signbit(o[0]) ? "-" : "+", std::signbit(o[1]) ? "-" : "+", o[2], o[3]);
    select_nle(x, y, o);
    std::printf("!(x <= y) ? y : x  ->  %s0 %s0 %g %g   (expected +0 -0 1 2)\n", std::signbit(o[0]) ? "-" : "+", std::signbit(o[1]) ? "-" : "+", o[2], o[3]);
    select_le_min(xd, yd, od);
    std::printf("(x <= y) ? x : y   ->  %s0 %s0 %g %g   (expected +0 -0 1 2)\n", std::signbit(od[0]) ? "-" : "+", std::signbit(od[1]) ? "-" : "+", od[2], od[3]);
}
```

`cl /nologo /EHsc /Od /arch:AVX2 repro.cpp && repro.exe`

```
x = +0 -0 1 5,  y = -0 +0 1 2
(x <= y) ? y : x   ->  -0 +0 1 5   (expected -0 +0 1 5)
(x <  y) ? y : x   ->  +0 -0 1 5   (expected +0 -0 1 5)
!(x <= y) ? y : x  ->  +0 -0 1 2   (expected +0 -0 1 2)
(x <= y) ? x : y   ->  +0 -0 1 2   (expected +0 -0 1 2)
```

`cl /nologo /EHsc /O2 /arch:AVX2 /fp:strict repro.cpp && repro.exe` (same with `/O1 /arch:AVX2`, `/O2 /arch:AVX2`, `/O2 /arch:AVX512`)

```
x = +0 -0 1 5,  y = -0 +0 1 2
(x <= y) ? y : x   ->  +0 -0 1 5   (expected -0 +0 1 5)
(x <  y) ? y : x   ->  +0 -0 1 5   (expected +0 -0 1 5)
!(x <= y) ? y : x  ->  -0 +0 1 2   (expected +0 -0 1 2)
(x <= y) ? x : y   ->  -0 +0 1 2   (expected +0 -0 1 2)
```

At plain `/O2` (no `/arch`) the first line is still correct, and the `!(x <= y)` line and the 256-bit line are already wrong.

Generated code for `select_le` (`/FAs`):

```asm
; /O2                                  ; /O2 /arch:AVX2
movaps   xmm0, xmm2                    vmovups xmm1, XMMWORD PTR [rdx]        ; y
cmpps    xmm0, xmm1, 2                 vmaxps  xmm1, xmm1, XMMWORD PTR [rcx]  ; max(y, x): returns x on equality
blendvps xmm2, xmm1, xmm0              vmovups XMMWORD PTR [r8], xmm1
```

**Expected.** `(x <= y) ? y : x` has no exact `maxps`/`minps` equivalent (ties must go to `y`, NaNs to `x`; `maxps` sends both to the same operand), so the compare and blend should be kept for the `LE` / `GE` predicates, as they are in the SSE encoding; at least under `/fp:precise` and `/fp:strict`.

**How it was found.** A differential test that builds 109,754 small compositions of SSE/AVX2/AVX-512 intrinsics at `/Od` and at `/O1` / `/O2` and compares the results on edge values; about 2,500 differing functions all contain this pattern (predicates `LE_OS`, `GE_OS`, `NLE_US`; `LT`, `GT`, `NLT`, `EQ`, `NEQ`, `UNORD` selects and all integer selects are compiled correctly).

**Compiler.** `Microsoft (R) C/C++ Optimizing Compiler Version 19.44.35228 for x64` (Visual Studio 2022 17.14), Windows 11 Pro 10.0.26200, Intel Core i9-11900T.
