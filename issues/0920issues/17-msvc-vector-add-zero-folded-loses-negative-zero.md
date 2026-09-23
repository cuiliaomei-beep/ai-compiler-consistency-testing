<!-- 提交信息（不要复制到 issue 里） -->
# Microsoft Visual C++（Developer Community）— 0920 issue 17（中：向量 `x + 0.0` 被消掉，`/fp:strict` 下也一样）

| 项 | 值 |
|---|---|
| 提交目标 | **Visual Studio Developer Community**（不是 GitHub）：https://developercommunity.visualstudio.com/cpp/report （与 05 分两张单提交，一张单一个问题） |
| **怎么填（Developer Community 是三步表单）** | ① *Enter your problem*：**Description** 框里粘贴本文件 `## Body` 标题下面的全部内容（到文件末尾，或到“以下不属于给微软的正文”那条分隔线为止；编辑器识别 Markdown，三个反引号的代码块会正常渲染）；下面的 “Choose how the issue impacts you” 可选 *It's more difficult to complete my work*（或留空）；点 **Search**。② *Recommended solution*：页面会列出相似工单——扫一眼有没有同一个问题（本稿搜 `_mm_add_ps setzero`）；没有就点继续 / *Submit a new ticket*。③ *Submit a ticket*：把自动生成的标题**整个换成**本文件 `## Title` 下面那一行；产品选 Visual Studio 2022（17.14）/ C++；可把 `plan/reports_rewrites/msvc_addzero/add_zero.cpp` 作为附件上传（可选，附件只有微软能看到）；提交。提交后把反馈页网址（`https://developercommunity.visualstudio.com/t/…/数字`）贴给我登记。 |
| 验证版本 | MSVC 19.44.35228 x64（VS 2022 17.14）；`/Od` 正确；`/O1`、`/O2`、`/O2 /arch:AVX2`、`/O2 /arch:AVX512`、**`/O2 /fp:strict`** 都错。标量 `x + 0.0f` 在同样选项下是对的（保留了 `addss`） |
| 提交前查重 | 2026-09-21：Web 搜索 `MSVC _mm_add_ps _mm_setzero_ps negative zero /fp:strict` 等，未找到同报告（**提交前请在 Developer Community 站内再搜一次 `_mm_add_ps setzero`**） |
| 证据包 | `plan/reports_rewrites/msvc_addzero/add_zero.cpp`、`build_and_run.py`（四档选项 + 汇编）；发现来源 `plan/scripts/cxx_intrinsic_algebra_diff.py`（10.13 C++ 工具链层差分：42,030 个内建函数组合，`/Od` 对 `/O1`/`/O2`；MSVC 只有两族差异——05 号的 abs(abs) 10 个、本条 30 个） |
| 与 PyTorch 的关系 | 间接：Inductor 的 CPU 内核就是这类内建函数代码；`x + 0.0` 这类算式 Inductor 自己会先消掉（见 07 号稿），所以在 PyTorch 上目前看不到本条单独造成的差异。报告价值在编译器本身：违反 `/fp:precise` / `/fp:strict` 的语义保证 |
| 严重度说明 | 只影响 `-0.0` 的符号（`-0.0 + 0.0` 应为 `+0.0`）。会被后续的 `1/x`、`atan2`、`copysign`、`signbit`、按位比较放大 |

---

## Title

MSVC x64 optimizer removes `_mm_add_ps(x, _mm_setzero_ps())` (also `_mm256_` / `_mm512_`, `ps` and `pd`), returning `-0.0` where IEEE 754 requires `+0.0`, even under `/fp:strict`; the scalar `x + 0.0f` is compiled correctly

## Body

**Summary.** With `/O1` or `/O2`, MSVC 19.44.35228 for x64 compiles `_mm256_add_ps(x, _mm256_setzero_ps())` to a plain load and store, so an element `-0.0` comes back as `-0.0`, whereas `-0.0 + (+0.0)` is `+0.0` and `/Od` returns that; the fold is applied under the default `/fp:precise` and under `/fp:strict` as well. Code that relies on the addition to normalise the zero before `1/x` or `signbit` gets the other sign only in optimised builds. Because the fold `x + 0.0 → x` is made by the intrinsic simplifier rather than by the scalar optimizer, which keeps the `addss` of `float f(float x) { return x + 0.0f; }` in the same build, the `ps` and `pd` additions of all three widths are affected, with the zero on either side, as `setzero` or `set1(0.0f)`.

```cpp
#include <immintrin.h>
#include <cstdio>
#include <cmath>

__declspec(noinline) float scalar_add(float x) { return x + 0.0f; }
__declspec(noinline) void sse_add(const float* in, float* out) {
    _mm_storeu_ps(out, _mm_add_ps(_mm_loadu_ps(in), _mm_setzero_ps()));
}
__declspec(noinline) void avx_add(const float* in, float* out) {
    _mm256_storeu_ps(out, _mm256_add_ps(_mm256_loadu_ps(in), _mm256_setzero_ps()));
}
__declspec(noinline) void avx_add_pd(const double* in, double* out) {
    _mm256_storeu_pd(out, _mm256_add_pd(_mm256_setzero_pd(), _mm256_loadu_pd(in)));
}

int main() {
    float in[8], out[8]; double ind[4], outd[4];
    for (int i = 0; i < 8; ++i) in[i] = -0.0f;
    for (int i = 0; i < 4; ++i) ind[i] = -0.0;
    volatile float v = -0.0f;
    std::printf("scalar -0.0f + 0.0f                    sign bit = %d\n", (int)std::signbit(scalar_add(v)));
    sse_add(in, out);      std::printf("_mm_add_ps(x, _mm_setzero_ps())        sign bit = %d\n", (int)std::signbit(out[0]));
    avx_add(in, out);      std::printf("_mm256_add_ps(x, _mm256_setzero_ps())  sign bit = %d\n", (int)std::signbit(out[0]));
    avx_add_pd(ind, outd); std::printf("_mm256_add_pd(_mm256_setzero_pd(), x)  sign bit = %d\n", (int)std::signbit(outd[0]));
}
```

`cl /nologo /EHsc /Od repro.cpp && repro.exe`

```
scalar -0.0f + 0.0f                    sign bit = 0
_mm_add_ps(x, _mm_setzero_ps())        sign bit = 0
_mm256_add_ps(x, _mm256_setzero_ps())  sign bit = 0
_mm256_add_pd(_mm256_setzero_pd(), x)  sign bit = 0
```

`cl /nologo /EHsc /O2 /fp:strict repro.cpp && repro.exe` (same with `/O1`, `/O2`, `/O2 /arch:AVX2`)

```
scalar -0.0f + 0.0f                    sign bit = 0
_mm_add_ps(x, _mm_setzero_ps())        sign bit = 1
_mm256_add_ps(x, _mm256_setzero_ps())  sign bit = 1
_mm256_add_pd(_mm256_setzero_pd(), x)  sign bit = 1
```

Generated code at `/O2` (`/FAs`): the scalar function keeps the addition, the vector function has none.

```asm
scalar_add:  xorps   xmm1, xmm1
             addss   xmm0, xmm1
avx_add:     vmovups ymm1, YMMWORD PTR [rcx]      ; vaddps removed
             vmovups YMMWORD PTR [rdx], ymm1
```

**Expected.** Under `/fp:precise` and `/fp:strict` the addition of `+0.0` is kept (or replaced by something that still maps `-0.0` to `+0.0`); only `x + (-0.0)` and `x - (+0.0)` are identities. `_mm256_sub_ps(x, _mm256_set1_ps(-0.0f))` is handled correctly.

**How it was found.** A differential test that builds 42,030 small compositions of SSE/AVX2/AVX-512 intrinsics at `/Od` and at `/O1` / `/O2` and compares the results on edge values; the only other family of differences it found is reported separately (two consecutive `_mm*_abs_epi*` folded to a no-op).

**Compiler.** `Microsoft (R) C/C++ Optimizing Compiler Version 19.44.35228 for x64` (Visual Studio 2022 17.14), Windows 11 Pro 10.0.26200, Intel Core i9-11900T.
