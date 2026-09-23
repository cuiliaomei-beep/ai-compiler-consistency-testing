<!-- 提交信息（不要复制到 issue 里） -->
# Microsoft Visual C++（Developer Community）— 0920 issue 05（高：C++ 编译器误编译；PyTorch 之下的一层）

| 项 | 值 |
|---|---|
| 提交目标 | **Visual Studio Developer Community**（不是 GitHub）：https://developercommunity.visualstudio.com/cpp/report —— 需要用微软账号登录，选 "C++" → "Report a problem" |
| **怎么填（Developer Community 是三步表单）** | ① *Enter your problem*：**Description** 框里粘贴本文件 `## Body` 标题下面的全部内容（到文件末尾，或到“以下不属于给微软的正文”那条分隔线为止；编辑器识别 Markdown，三个反引号的代码块会正常渲染）；下面的 “Choose how the issue impacts you” 可选 *It's more difficult to complete my work*（或留空）；点 **Search**。② *Recommended solution*：页面会列出相似工单——扫一眼有没有同一个问题（本稿搜 `_mm256_abs_epi32`）；没有就点继续 / *Submit a new ticket*。③ *Submit a ticket*：把自动生成的标题**整个换成**本文件 `## Title` 下面那一行；产品选 Visual Studio 2022（17.14）/ C++；可把 `plan/reports_rewrites/msvc_abs/abs_abs.cpp` 作为附件上传（可选，附件只有微软能看到）；提交。提交后把反馈页网址（`https://developercommunity.visualstudio.com/t/…/数字`）贴给我登记。 |
| 验证版本 | MSVC 19.44.35228 x64（VS 2022 17.14）；`/Od` 正确，`/O1`、`/O2`、`/O2 /arch:AVX2`、`/O2 /arch:AVX512` 都错。本机没有更新的 MSVC，提交前如能在 VS 2026 / 最新 17.14.x 上再试一次更好（网页版 Compiler Explorer 选 "x64 msvc v19.latest" 即可，把下面的程序贴进去加 `/O2`） |
| 提交前查重 | 2026-09-21：Web 搜索 `MSVC miscompile _mm256_abs_epi32 abs(abs(x))`、`pabsd optimized away MSVC` 等，未找到同报告（Developer Community 站内搜索无法用脚本访问，**提交前请在站内再搜一次 `_mm256_abs_epi32` / `pabsd`**） |
| 证据包 | `plan/reports_rewrites/msvc_abs/abs_abs.cpp`（独立 C++ 复现）、`build_and_run.py`（四档优化级别编译并运行）、`asm.py`（打印三个函数的汇编）；PyTorch 侧表现 `plan/reports_rewrites/abs_abs_int.py`；发现来源 `plan/scripts/rewrite_precondition_diff.py`（用例 `abs_abs`，int8） |
| 怎么发现的 | `torch.compile(lambda t: t.abs().abs())` 在 Windows 上对 int8 / int16 / int32 的负数返回原值（-2 → -2）；Inductor 生成的 C++ 是对的（`tmp0.abs().abs()` → `_mm512_abs_epi32(_mm512_abs_epi32(v))`），错在 MSVC |
| 对 PyTorch 的影响 | Windows 上 CPU Inductor 的整数 `abs(abs(x))` 静默错；int64 用 xor/sub 实现、浮点用 andnot，不受影响；Linux（gcc）已复核不受影响（Kaggle `tcc-rewritelinux`：2.14.0 与 nightly 0920 上 int8/16/32/64 × 长度 5/40 全部与 eager 相等；T4 CUDA 也相等）→ 仅 MSVC。PyTorch 侧是否另开 issue：建议**先报微软**，拿到反馈编号后再视情况给 PyTorch 提一个"Windows 上绕开"的小 issue（见文末） |

---

## Title

MSVC x64 optimizer folds two consecutive packed-absolute-value intrinsics (`_mm_abs_epi32`, `_mm256_abs_epi8/16/32`, `_mm512_abs_epi32`) into a no-op: `abs(abs(x))` returns `x`

## Body

**Summary.** With `/O1` or `/O2` (with or without `/arch:AVX2` / `/arch:AVX512`), MSVC 19.44.35228 for x64 compiles `_mm256_abs_epi32(_mm256_abs_epi32(v))` to a plain load and store, so negative elements come back unchanged, while `/Od` returns their absolute value; one application and three applications (folded to one) are correct. Any code that applies the intrinsic twice to the same value, directly or after two helper functions are inlined, silently produces negative "absolute values". Because the pair is removed as if `pabs*` were an involution like negation (`f(f(x)) == x`) rather than an idempotent operation (`f(f(x)) == f(x)`), the 128-, 256- and 512-bit forms and the 8-, 16- and 32-bit element widths are all affected.

```cpp
#include <immintrin.h>
#include <cstdio>
#include <cstdint>

__declspec(noinline) void abs1(const int32_t* in, int32_t* out) {
    __m256i v = _mm256_loadu_si256((const __m256i*)in);
    _mm256_storeu_si256((__m256i*)out, _mm256_abs_epi32(v));
}
__declspec(noinline) void abs2(const int32_t* in, int32_t* out) {
    __m256i v = _mm256_loadu_si256((const __m256i*)in);
    _mm256_storeu_si256((__m256i*)out, _mm256_abs_epi32(_mm256_abs_epi32(v)));
}
__declspec(noinline) void abs3(const int32_t* in, int32_t* out) {
    __m256i v = _mm256_loadu_si256((const __m256i*)in);
    _mm256_storeu_si256((__m256i*)out, _mm256_abs_epi32(_mm256_abs_epi32(_mm256_abs_epi32(v))));
}

int main() {
    int32_t in[8] = {-8, -7, -6, -5, -4, -3, -2, -1}, out[8];
    void (*fns[3])(const int32_t*, int32_t*) = {abs1, abs2, abs3};
    const char* names[3] = {"abs(x)          ", "abs(abs(x))     ", "abs(abs(abs(x)))"};
    for (int k = 0; k < 3; ++k) {
        fns[k](in, out);
        std::printf("%s", names[k]);
        for (int i = 0; i < 8; ++i) std::printf(" %d", out[i]);
        std::printf("\n");
    }
}
```

`cl /nologo /EHsc /Od repro.cpp && repro.exe`

```
abs(x)           8 7 6 5 4 3 2 1
abs(abs(x))      8 7 6 5 4 3 2 1
abs(abs(abs(x))) 8 7 6 5 4 3 2 1
```

`cl /nologo /EHsc /O2 repro.cpp && repro.exe` (same with `/O1`, `/O2 /arch:AVX2`, `/O2 /arch:AVX512`)

```
abs(x)           8 7 6 5 4 3 2 1
abs(abs(x))      -8 -7 -6 -5 -4 -3 -2 -1
abs(abs(abs(x))) 8 7 6 5 4 3 2 1
```

Generated code at `/O2 /arch:AVX2` (`/FAs`); `abs2` contains no `vpabsd` at all:

```asm
abs1:   vpabsd  ymm0, YMMWORD PTR [rcx]
        vmovdqu YMMWORD PTR [rdx], ymm0
abs2:   vmovdqu ymm0, YMMWORD PTR [rcx]      ; both vpabsd removed
        vmovdqu YMMWORD PTR [rdx], ymm0
abs3:   vpabsd  ymm1, YMMWORD PTR [rcx]      ; three folded to one (correct)
        vmovdqu YMMWORD PTR [rdx], ymm1
```

The same happens for `_mm_abs_epi32` (128-bit), `_mm256_abs_epi8`, `_mm256_abs_epi16` and `_mm512_abs_epi32` (a larger test file that covers these is available on request).

**Expected.** `pabs(pabs(x))` may be simplified to `pabs(x)`, not to `x`.

**Where it was found.** PyTorch's `torch.compile` CPU backend emits `at::vec::Vectorized<int32_t>::abs()`, which is `_mm256_abs_epi32` / `_mm512_abs_epi32`; for the Python program `x.abs().abs()` on an int8 / int16 / int32 tensor the generated C++ is correct and the MSVC-built kernel returns the negative inputs unchanged. int64 (implemented with compare / xor / sub) and floating point are not affected, and the same kernel built with GCC on Linux returns the correct result.

**Compiler.** `Microsoft (R) C/C++ Optimizing Compiler Version 19.44.35228 for x64` (Visual Studio 2022 17.14), Windows 11 Pro 10.0.26200, Intel Core i9-11900T.

---

<!-- 以下不属于给微软的正文 -->
## 附：PyTorch 侧的表现（备用，先不提交）

```python
import torch
x = torch.tensor([-2, -1, 0, 1, 2], dtype=torch.int32)
f = lambda t: t.abs().abs()
print(f(x), torch.compile(f)(x))
# Windows + MSVC 19.44: tensor([2, 1, 0, 1, 2]) tensor([-2, -1, 0, 1, 2])
```

若之后要给 PyTorch 提，修法建议：Inductor 在 pointwise 链里对幂等一元算子做 CSE 式化简（`abs(abs(x)) → abs(x)`，顺带省一次运算），或在 `vec256_int.h` / `vec512_int.h` 的 `abs()` 上对 MSVC 改用 `max(x, 0 - x)` 写法绕开。属于"工具链缺陷在 PyTorch 上的表现"，优先级低于微软侧的报告。
