#include "common.h"
static NOINLINE void f0(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_andnot_ps(x, _mm512_roundscale_ps(x, 0 | _MM_FROUND_NO_EXC)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f1(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_andnot_ps(_mm512_roundscale_ps(x, 0 | _MM_FROUND_NO_EXC), x); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f2(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_add_ps(x, x); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f3(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_add_ps(x, _mm512_setzero_ps()); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f4(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_add_ps(_mm512_setzero_ps(), x); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f5(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_add_ps(x, _mm512_set1_ps(-0.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f6(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_add_ps(_mm512_set1_ps(-0.0f), x); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f7(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_add_ps(x, _mm512_set1_ps(1.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f8(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_add_ps(_mm512_set1_ps(1.0f), x); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f9(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_add_ps(x, _mm512_set1_ps(-1.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f10(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_add_ps(_mm512_set1_ps(-1.0f), x); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f11(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_add_ps(x, _mm512_set1_ps(std::numeric_limits<float>::infinity())); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f12(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_add_ps(_mm512_set1_ps(std::numeric_limits<float>::infinity()), x); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f13(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_add_ps(x, _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN())); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f14(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_add_ps(_mm512_set1_ps(std::numeric_limits<float>::quiet_NaN()), x); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f15(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_add_ps(_mm512_add_ps(x, _mm512_setzero_ps()), _mm512_setzero_ps()); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f16(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_add_ps(_mm512_add_ps(x, _mm512_setzero_ps()), _mm512_set1_ps(-0.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f17(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_add_ps(_mm512_add_ps(x, _mm512_setzero_ps()), _mm512_set1_ps(1.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f18(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_add_ps(_mm512_add_ps(x, _mm512_setzero_ps()), _mm512_set1_ps(-1.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f19(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_add_ps(_mm512_add_ps(x, _mm512_setzero_ps()), _mm512_set1_ps(std::numeric_limits<float>::infinity())); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f20(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_add_ps(_mm512_add_ps(x, _mm512_setzero_ps()), _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN())); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f21(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_add_ps(_mm512_add_ps(x, _mm512_set1_ps(-0.0f)), _mm512_setzero_ps()); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f22(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_add_ps(_mm512_add_ps(x, _mm512_set1_ps(-0.0f)), _mm512_set1_ps(-0.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f23(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_add_ps(_mm512_add_ps(x, _mm512_set1_ps(-0.0f)), _mm512_set1_ps(1.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f24(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_add_ps(_mm512_add_ps(x, _mm512_set1_ps(-0.0f)), _mm512_set1_ps(-1.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f25(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_add_ps(_mm512_add_ps(x, _mm512_set1_ps(-0.0f)), _mm512_set1_ps(std::numeric_limits<float>::infinity())); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f26(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_add_ps(_mm512_add_ps(x, _mm512_set1_ps(-0.0f)), _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN())); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f27(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_add_ps(_mm512_add_ps(x, _mm512_set1_ps(1.0f)), _mm512_setzero_ps()); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f28(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_add_ps(_mm512_add_ps(x, _mm512_set1_ps(1.0f)), _mm512_set1_ps(-0.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f29(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_add_ps(_mm512_add_ps(x, _mm512_set1_ps(1.0f)), _mm512_set1_ps(1.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f30(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_add_ps(_mm512_add_ps(x, _mm512_set1_ps(1.0f)), _mm512_set1_ps(-1.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f31(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_add_ps(_mm512_add_ps(x, _mm512_set1_ps(1.0f)), _mm512_set1_ps(std::numeric_limits<float>::infinity())); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f32(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_add_ps(_mm512_add_ps(x, _mm512_set1_ps(1.0f)), _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN())); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f33(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_add_ps(_mm512_add_ps(x, _mm512_set1_ps(-1.0f)), _mm512_setzero_ps()); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f34(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_add_ps(_mm512_add_ps(x, _mm512_set1_ps(-1.0f)), _mm512_set1_ps(-0.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f35(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_add_ps(_mm512_add_ps(x, _mm512_set1_ps(-1.0f)), _mm512_set1_ps(1.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f36(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_add_ps(_mm512_add_ps(x, _mm512_set1_ps(-1.0f)), _mm512_set1_ps(-1.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f37(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_add_ps(_mm512_add_ps(x, _mm512_set1_ps(-1.0f)), _mm512_set1_ps(std::numeric_limits<float>::infinity())); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f38(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_add_ps(_mm512_add_ps(x, _mm512_set1_ps(-1.0f)), _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN())); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f39(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_add_ps(_mm512_add_ps(x, _mm512_set1_ps(std::numeric_limits<float>::infinity())), _mm512_setzero_ps()); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f40(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_add_ps(_mm512_add_ps(x, _mm512_set1_ps(std::numeric_limits<float>::infinity())), _mm512_set1_ps(-0.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f41(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_add_ps(_mm512_add_ps(x, _mm512_set1_ps(std::numeric_limits<float>::infinity())), _mm512_set1_ps(1.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f42(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_add_ps(_mm512_add_ps(x, _mm512_set1_ps(std::numeric_limits<float>::infinity())), _mm512_set1_ps(-1.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f43(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_add_ps(_mm512_add_ps(x, _mm512_set1_ps(std::numeric_limits<float>::infinity())), _mm512_set1_ps(std::numeric_limits<float>::infinity())); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f44(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_add_ps(_mm512_add_ps(x, _mm512_set1_ps(std::numeric_limits<float>::infinity())), _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN())); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f45(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_add_ps(_mm512_add_ps(x, _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN())), _mm512_setzero_ps()); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f46(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_add_ps(_mm512_add_ps(x, _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN())), _mm512_set1_ps(-0.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f47(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_add_ps(_mm512_add_ps(x, _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN())), _mm512_set1_ps(1.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f48(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_add_ps(_mm512_add_ps(x, _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN())), _mm512_set1_ps(-1.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f49(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_add_ps(_mm512_add_ps(x, _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN())), _mm512_set1_ps(std::numeric_limits<float>::infinity())); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f50(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_add_ps(_mm512_add_ps(x, _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN())), _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN())); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f51(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_sub_ps(x, x); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f52(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_sub_ps(x, _mm512_setzero_ps()); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f53(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_sub_ps(_mm512_setzero_ps(), x); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f54(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_sub_ps(x, _mm512_set1_ps(-0.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f55(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_sub_ps(_mm512_set1_ps(-0.0f), x); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f56(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_sub_ps(x, _mm512_set1_ps(1.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f57(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_sub_ps(_mm512_set1_ps(1.0f), x); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f58(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_sub_ps(x, _mm512_set1_ps(-1.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f59(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_sub_ps(_mm512_set1_ps(-1.0f), x); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f60(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_sub_ps(x, _mm512_set1_ps(std::numeric_limits<float>::infinity())); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f61(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_sub_ps(_mm512_set1_ps(std::numeric_limits<float>::infinity()), x); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f62(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_sub_ps(x, _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN())); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f63(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_sub_ps(_mm512_set1_ps(std::numeric_limits<float>::quiet_NaN()), x); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f64(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_sub_ps(_mm512_sub_ps(x, _mm512_setzero_ps()), _mm512_setzero_ps()); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f65(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_sub_ps(_mm512_sub_ps(x, _mm512_setzero_ps()), _mm512_set1_ps(-0.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f66(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_sub_ps(_mm512_sub_ps(x, _mm512_setzero_ps()), _mm512_set1_ps(1.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f67(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_sub_ps(_mm512_sub_ps(x, _mm512_setzero_ps()), _mm512_set1_ps(-1.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f68(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_sub_ps(_mm512_sub_ps(x, _mm512_setzero_ps()), _mm512_set1_ps(std::numeric_limits<float>::infinity())); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f69(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_sub_ps(_mm512_sub_ps(x, _mm512_setzero_ps()), _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN())); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f70(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_sub_ps(_mm512_sub_ps(x, _mm512_set1_ps(-0.0f)), _mm512_setzero_ps()); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f71(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_sub_ps(_mm512_sub_ps(x, _mm512_set1_ps(-0.0f)), _mm512_set1_ps(-0.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f72(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_sub_ps(_mm512_sub_ps(x, _mm512_set1_ps(-0.0f)), _mm512_set1_ps(1.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f73(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_sub_ps(_mm512_sub_ps(x, _mm512_set1_ps(-0.0f)), _mm512_set1_ps(-1.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f74(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_sub_ps(_mm512_sub_ps(x, _mm512_set1_ps(-0.0f)), _mm512_set1_ps(std::numeric_limits<float>::infinity())); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f75(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_sub_ps(_mm512_sub_ps(x, _mm512_set1_ps(-0.0f)), _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN())); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f76(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_sub_ps(_mm512_sub_ps(x, _mm512_set1_ps(1.0f)), _mm512_setzero_ps()); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f77(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_sub_ps(_mm512_sub_ps(x, _mm512_set1_ps(1.0f)), _mm512_set1_ps(-0.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f78(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_sub_ps(_mm512_sub_ps(x, _mm512_set1_ps(1.0f)), _mm512_set1_ps(1.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f79(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_sub_ps(_mm512_sub_ps(x, _mm512_set1_ps(1.0f)), _mm512_set1_ps(-1.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f80(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_sub_ps(_mm512_sub_ps(x, _mm512_set1_ps(1.0f)), _mm512_set1_ps(std::numeric_limits<float>::infinity())); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f81(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_sub_ps(_mm512_sub_ps(x, _mm512_set1_ps(1.0f)), _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN())); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f82(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_sub_ps(_mm512_sub_ps(x, _mm512_set1_ps(-1.0f)), _mm512_setzero_ps()); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f83(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_sub_ps(_mm512_sub_ps(x, _mm512_set1_ps(-1.0f)), _mm512_set1_ps(-0.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f84(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_sub_ps(_mm512_sub_ps(x, _mm512_set1_ps(-1.0f)), _mm512_set1_ps(1.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f85(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_sub_ps(_mm512_sub_ps(x, _mm512_set1_ps(-1.0f)), _mm512_set1_ps(-1.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f86(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_sub_ps(_mm512_sub_ps(x, _mm512_set1_ps(-1.0f)), _mm512_set1_ps(std::numeric_limits<float>::infinity())); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f87(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_sub_ps(_mm512_sub_ps(x, _mm512_set1_ps(-1.0f)), _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN())); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f88(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_sub_ps(_mm512_sub_ps(x, _mm512_set1_ps(std::numeric_limits<float>::infinity())), _mm512_setzero_ps()); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f89(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_sub_ps(_mm512_sub_ps(x, _mm512_set1_ps(std::numeric_limits<float>::infinity())), _mm512_set1_ps(-0.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f90(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_sub_ps(_mm512_sub_ps(x, _mm512_set1_ps(std::numeric_limits<float>::infinity())), _mm512_set1_ps(1.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f91(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_sub_ps(_mm512_sub_ps(x, _mm512_set1_ps(std::numeric_limits<float>::infinity())), _mm512_set1_ps(-1.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f92(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_sub_ps(_mm512_sub_ps(x, _mm512_set1_ps(std::numeric_limits<float>::infinity())), _mm512_set1_ps(std::numeric_limits<float>::infinity())); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f93(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_sub_ps(_mm512_sub_ps(x, _mm512_set1_ps(std::numeric_limits<float>::infinity())), _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN())); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f94(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_sub_ps(_mm512_sub_ps(x, _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN())), _mm512_setzero_ps()); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f95(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_sub_ps(_mm512_sub_ps(x, _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN())), _mm512_set1_ps(-0.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f96(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_sub_ps(_mm512_sub_ps(x, _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN())), _mm512_set1_ps(1.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f97(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_sub_ps(_mm512_sub_ps(x, _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN())), _mm512_set1_ps(-1.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f98(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_sub_ps(_mm512_sub_ps(x, _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN())), _mm512_set1_ps(std::numeric_limits<float>::infinity())); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f99(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_sub_ps(_mm512_sub_ps(x, _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN())), _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN())); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f100(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_mul_ps(x, x); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f101(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_mul_ps(x, _mm512_setzero_ps()); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f102(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_mul_ps(_mm512_setzero_ps(), x); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f103(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_mul_ps(x, _mm512_set1_ps(-0.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f104(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_mul_ps(_mm512_set1_ps(-0.0f), x); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f105(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_mul_ps(x, _mm512_set1_ps(1.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f106(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_mul_ps(_mm512_set1_ps(1.0f), x); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f107(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_mul_ps(x, _mm512_set1_ps(-1.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f108(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_mul_ps(_mm512_set1_ps(-1.0f), x); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f109(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_mul_ps(x, _mm512_set1_ps(std::numeric_limits<float>::infinity())); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f110(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_mul_ps(_mm512_set1_ps(std::numeric_limits<float>::infinity()), x); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f111(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_mul_ps(x, _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN())); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f112(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_mul_ps(_mm512_set1_ps(std::numeric_limits<float>::quiet_NaN()), x); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f113(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_mul_ps(_mm512_mul_ps(x, _mm512_setzero_ps()), _mm512_setzero_ps()); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f114(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_mul_ps(_mm512_mul_ps(x, _mm512_setzero_ps()), _mm512_set1_ps(-0.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f115(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_mul_ps(_mm512_mul_ps(x, _mm512_setzero_ps()), _mm512_set1_ps(1.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f116(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_mul_ps(_mm512_mul_ps(x, _mm512_setzero_ps()), _mm512_set1_ps(-1.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f117(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_mul_ps(_mm512_mul_ps(x, _mm512_setzero_ps()), _mm512_set1_ps(std::numeric_limits<float>::infinity())); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f118(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_mul_ps(_mm512_mul_ps(x, _mm512_setzero_ps()), _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN())); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f119(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_mul_ps(_mm512_mul_ps(x, _mm512_set1_ps(-0.0f)), _mm512_setzero_ps()); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f120(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_mul_ps(_mm512_mul_ps(x, _mm512_set1_ps(-0.0f)), _mm512_set1_ps(-0.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f121(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_mul_ps(_mm512_mul_ps(x, _mm512_set1_ps(-0.0f)), _mm512_set1_ps(1.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f122(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_mul_ps(_mm512_mul_ps(x, _mm512_set1_ps(-0.0f)), _mm512_set1_ps(-1.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f123(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_mul_ps(_mm512_mul_ps(x, _mm512_set1_ps(-0.0f)), _mm512_set1_ps(std::numeric_limits<float>::infinity())); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f124(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_mul_ps(_mm512_mul_ps(x, _mm512_set1_ps(-0.0f)), _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN())); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f125(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_mul_ps(_mm512_mul_ps(x, _mm512_set1_ps(1.0f)), _mm512_setzero_ps()); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f126(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_mul_ps(_mm512_mul_ps(x, _mm512_set1_ps(1.0f)), _mm512_set1_ps(-0.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f127(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_mul_ps(_mm512_mul_ps(x, _mm512_set1_ps(1.0f)), _mm512_set1_ps(1.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f128(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_mul_ps(_mm512_mul_ps(x, _mm512_set1_ps(1.0f)), _mm512_set1_ps(-1.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f129(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_mul_ps(_mm512_mul_ps(x, _mm512_set1_ps(1.0f)), _mm512_set1_ps(std::numeric_limits<float>::infinity())); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f130(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_mul_ps(_mm512_mul_ps(x, _mm512_set1_ps(1.0f)), _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN())); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f131(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_mul_ps(_mm512_mul_ps(x, _mm512_set1_ps(-1.0f)), _mm512_setzero_ps()); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f132(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_mul_ps(_mm512_mul_ps(x, _mm512_set1_ps(-1.0f)), _mm512_set1_ps(-0.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f133(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_mul_ps(_mm512_mul_ps(x, _mm512_set1_ps(-1.0f)), _mm512_set1_ps(1.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f134(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_mul_ps(_mm512_mul_ps(x, _mm512_set1_ps(-1.0f)), _mm512_set1_ps(std::numeric_limits<float>::infinity())); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f135(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_mul_ps(_mm512_mul_ps(x, _mm512_set1_ps(-1.0f)), _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN())); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f136(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_mul_ps(_mm512_mul_ps(x, _mm512_set1_ps(std::numeric_limits<float>::infinity())), _mm512_setzero_ps()); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f137(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_mul_ps(_mm512_mul_ps(x, _mm512_set1_ps(std::numeric_limits<float>::infinity())), _mm512_set1_ps(-0.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f138(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_mul_ps(_mm512_mul_ps(x, _mm512_set1_ps(std::numeric_limits<float>::infinity())), _mm512_set1_ps(1.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f139(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_mul_ps(_mm512_mul_ps(x, _mm512_set1_ps(std::numeric_limits<float>::infinity())), _mm512_set1_ps(-1.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f140(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_mul_ps(_mm512_mul_ps(x, _mm512_set1_ps(std::numeric_limits<float>::infinity())), _mm512_set1_ps(std::numeric_limits<float>::infinity())); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f141(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_mul_ps(_mm512_mul_ps(x, _mm512_set1_ps(std::numeric_limits<float>::infinity())), _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN())); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f142(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_mul_ps(_mm512_mul_ps(x, _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN())), _mm512_setzero_ps()); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f143(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_mul_ps(_mm512_mul_ps(x, _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN())), _mm512_set1_ps(-0.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f144(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_mul_ps(_mm512_mul_ps(x, _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN())), _mm512_set1_ps(1.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f145(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_mul_ps(_mm512_mul_ps(x, _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN())), _mm512_set1_ps(-1.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f146(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_mul_ps(_mm512_mul_ps(x, _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN())), _mm512_set1_ps(std::numeric_limits<float>::infinity())); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f147(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_mul_ps(_mm512_mul_ps(x, _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN())), _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN())); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f148(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_div_ps(x, x); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f149(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_div_ps(x, _mm512_setzero_ps()); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f150(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_div_ps(_mm512_setzero_ps(), x); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f151(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_div_ps(x, _mm512_set1_ps(-0.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f152(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_div_ps(_mm512_set1_ps(-0.0f), x); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f153(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_div_ps(x, _mm512_set1_ps(1.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f154(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_div_ps(_mm512_set1_ps(1.0f), x); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f155(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_div_ps(x, _mm512_set1_ps(-1.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f156(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_div_ps(_mm512_set1_ps(-1.0f), x); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f157(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_div_ps(x, _mm512_set1_ps(std::numeric_limits<float>::infinity())); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f158(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_div_ps(_mm512_set1_ps(std::numeric_limits<float>::infinity()), x); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f159(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_div_ps(x, _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN())); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f160(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_div_ps(_mm512_set1_ps(std::numeric_limits<float>::quiet_NaN()), x); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f161(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_div_ps(_mm512_div_ps(x, _mm512_setzero_ps()), _mm512_setzero_ps()); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f162(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_div_ps(_mm512_div_ps(x, _mm512_setzero_ps()), _mm512_set1_ps(-0.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f163(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_div_ps(_mm512_div_ps(x, _mm512_setzero_ps()), _mm512_set1_ps(1.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f164(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_div_ps(_mm512_div_ps(x, _mm512_setzero_ps()), _mm512_set1_ps(-1.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f165(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_div_ps(_mm512_div_ps(x, _mm512_setzero_ps()), _mm512_set1_ps(std::numeric_limits<float>::infinity())); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f166(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_div_ps(_mm512_div_ps(x, _mm512_setzero_ps()), _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN())); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f167(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_div_ps(_mm512_div_ps(x, _mm512_set1_ps(-0.0f)), _mm512_setzero_ps()); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f168(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_div_ps(_mm512_div_ps(x, _mm512_set1_ps(-0.0f)), _mm512_set1_ps(-0.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f169(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_div_ps(_mm512_div_ps(x, _mm512_set1_ps(-0.0f)), _mm512_set1_ps(1.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f170(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_div_ps(_mm512_div_ps(x, _mm512_set1_ps(-0.0f)), _mm512_set1_ps(-1.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f171(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_div_ps(_mm512_div_ps(x, _mm512_set1_ps(-0.0f)), _mm512_set1_ps(std::numeric_limits<float>::infinity())); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f172(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_div_ps(_mm512_div_ps(x, _mm512_set1_ps(-0.0f)), _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN())); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f173(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_div_ps(_mm512_div_ps(x, _mm512_set1_ps(1.0f)), _mm512_setzero_ps()); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f174(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_div_ps(_mm512_div_ps(x, _mm512_set1_ps(1.0f)), _mm512_set1_ps(-0.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f175(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_div_ps(_mm512_div_ps(x, _mm512_set1_ps(1.0f)), _mm512_set1_ps(1.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f176(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_div_ps(_mm512_div_ps(x, _mm512_set1_ps(1.0f)), _mm512_set1_ps(-1.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f177(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_div_ps(_mm512_div_ps(x, _mm512_set1_ps(1.0f)), _mm512_set1_ps(std::numeric_limits<float>::infinity())); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f178(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_div_ps(_mm512_div_ps(x, _mm512_set1_ps(1.0f)), _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN())); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f179(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_div_ps(_mm512_div_ps(x, _mm512_set1_ps(-1.0f)), _mm512_setzero_ps()); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f180(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_div_ps(_mm512_div_ps(x, _mm512_set1_ps(-1.0f)), _mm512_set1_ps(-0.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f181(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_div_ps(_mm512_div_ps(x, _mm512_set1_ps(-1.0f)), _mm512_set1_ps(1.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f182(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_div_ps(_mm512_div_ps(x, _mm512_set1_ps(-1.0f)), _mm512_set1_ps(-1.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f183(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_div_ps(_mm512_div_ps(x, _mm512_set1_ps(-1.0f)), _mm512_set1_ps(std::numeric_limits<float>::infinity())); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f184(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_div_ps(_mm512_div_ps(x, _mm512_set1_ps(-1.0f)), _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN())); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f185(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_div_ps(_mm512_div_ps(x, _mm512_set1_ps(std::numeric_limits<float>::infinity())), _mm512_setzero_ps()); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f186(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_div_ps(_mm512_div_ps(x, _mm512_set1_ps(std::numeric_limits<float>::infinity())), _mm512_set1_ps(-0.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f187(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_div_ps(_mm512_div_ps(x, _mm512_set1_ps(std::numeric_limits<float>::infinity())), _mm512_set1_ps(1.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f188(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_div_ps(_mm512_div_ps(x, _mm512_set1_ps(std::numeric_limits<float>::infinity())), _mm512_set1_ps(-1.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f189(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_div_ps(_mm512_div_ps(x, _mm512_set1_ps(std::numeric_limits<float>::infinity())), _mm512_set1_ps(std::numeric_limits<float>::infinity())); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f190(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_div_ps(_mm512_div_ps(x, _mm512_set1_ps(std::numeric_limits<float>::infinity())), _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN())); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f191(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_div_ps(_mm512_div_ps(x, _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN())), _mm512_setzero_ps()); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f192(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_div_ps(_mm512_div_ps(x, _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN())), _mm512_set1_ps(-0.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f193(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_div_ps(_mm512_div_ps(x, _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN())), _mm512_set1_ps(1.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f194(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_div_ps(_mm512_div_ps(x, _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN())), _mm512_set1_ps(-1.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f195(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_div_ps(_mm512_div_ps(x, _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN())), _mm512_set1_ps(std::numeric_limits<float>::infinity())); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f196(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_div_ps(_mm512_div_ps(x, _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN())), _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN())); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f197(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_min_ps(x, x); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f198(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_min_ps(x, _mm512_setzero_ps()); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f199(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_min_ps(_mm512_setzero_ps(), x); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f200(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_min_ps(x, _mm512_set1_ps(-0.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f201(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_min_ps(_mm512_set1_ps(-0.0f), x); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f202(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_min_ps(x, _mm512_set1_ps(1.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f203(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_min_ps(_mm512_set1_ps(1.0f), x); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f204(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_min_ps(x, _mm512_set1_ps(-1.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f205(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_min_ps(_mm512_set1_ps(-1.0f), x); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f206(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_min_ps(x, _mm512_set1_ps(std::numeric_limits<float>::infinity())); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f207(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_min_ps(_mm512_set1_ps(std::numeric_limits<float>::infinity()), x); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f208(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_min_ps(x, _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN())); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f209(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_min_ps(_mm512_set1_ps(std::numeric_limits<float>::quiet_NaN()), x); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f210(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_min_ps(_mm512_min_ps(x, _mm512_setzero_ps()), _mm512_setzero_ps()); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f211(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_min_ps(_mm512_min_ps(x, _mm512_setzero_ps()), _mm512_set1_ps(-0.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f212(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_min_ps(_mm512_min_ps(x, _mm512_setzero_ps()), _mm512_set1_ps(1.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f213(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_min_ps(_mm512_min_ps(x, _mm512_setzero_ps()), _mm512_set1_ps(-1.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f214(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_min_ps(_mm512_min_ps(x, _mm512_setzero_ps()), _mm512_set1_ps(std::numeric_limits<float>::infinity())); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f215(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_min_ps(_mm512_min_ps(x, _mm512_setzero_ps()), _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN())); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f216(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_min_ps(_mm512_min_ps(x, _mm512_set1_ps(-0.0f)), _mm512_setzero_ps()); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f217(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_min_ps(_mm512_min_ps(x, _mm512_set1_ps(-0.0f)), _mm512_set1_ps(-0.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f218(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_min_ps(_mm512_min_ps(x, _mm512_set1_ps(-0.0f)), _mm512_set1_ps(1.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f219(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_min_ps(_mm512_min_ps(x, _mm512_set1_ps(-0.0f)), _mm512_set1_ps(-1.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f220(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_min_ps(_mm512_min_ps(x, _mm512_set1_ps(-0.0f)), _mm512_set1_ps(std::numeric_limits<float>::infinity())); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f221(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_min_ps(_mm512_min_ps(x, _mm512_set1_ps(-0.0f)), _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN())); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f222(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_min_ps(_mm512_min_ps(x, _mm512_set1_ps(1.0f)), _mm512_setzero_ps()); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f223(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_min_ps(_mm512_min_ps(x, _mm512_set1_ps(1.0f)), _mm512_set1_ps(-0.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f224(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_min_ps(_mm512_min_ps(x, _mm512_set1_ps(1.0f)), _mm512_set1_ps(1.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f225(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_min_ps(_mm512_min_ps(x, _mm512_set1_ps(1.0f)), _mm512_set1_ps(-1.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f226(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_min_ps(_mm512_min_ps(x, _mm512_set1_ps(1.0f)), _mm512_set1_ps(std::numeric_limits<float>::infinity())); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f227(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_min_ps(_mm512_min_ps(x, _mm512_set1_ps(1.0f)), _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN())); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f228(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_min_ps(_mm512_min_ps(x, _mm512_set1_ps(-1.0f)), _mm512_setzero_ps()); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f229(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_min_ps(_mm512_min_ps(x, _mm512_set1_ps(-1.0f)), _mm512_set1_ps(-0.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f230(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_min_ps(_mm512_min_ps(x, _mm512_set1_ps(-1.0f)), _mm512_set1_ps(1.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f231(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_min_ps(_mm512_min_ps(x, _mm512_set1_ps(-1.0f)), _mm512_set1_ps(-1.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f232(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_min_ps(_mm512_min_ps(x, _mm512_set1_ps(-1.0f)), _mm512_set1_ps(std::numeric_limits<float>::infinity())); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f233(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_min_ps(_mm512_min_ps(x, _mm512_set1_ps(-1.0f)), _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN())); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f234(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_min_ps(_mm512_min_ps(x, _mm512_set1_ps(std::numeric_limits<float>::infinity())), _mm512_setzero_ps()); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f235(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_min_ps(_mm512_min_ps(x, _mm512_set1_ps(std::numeric_limits<float>::infinity())), _mm512_set1_ps(-0.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f236(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_min_ps(_mm512_min_ps(x, _mm512_set1_ps(std::numeric_limits<float>::infinity())), _mm512_set1_ps(1.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f237(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_min_ps(_mm512_min_ps(x, _mm512_set1_ps(std::numeric_limits<float>::infinity())), _mm512_set1_ps(-1.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f238(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_min_ps(_mm512_min_ps(x, _mm512_set1_ps(std::numeric_limits<float>::infinity())), _mm512_set1_ps(std::numeric_limits<float>::infinity())); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f239(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_min_ps(_mm512_min_ps(x, _mm512_set1_ps(std::numeric_limits<float>::infinity())), _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN())); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f240(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_min_ps(_mm512_min_ps(x, _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN())), _mm512_setzero_ps()); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f241(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_min_ps(_mm512_min_ps(x, _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN())), _mm512_set1_ps(-0.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f242(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_min_ps(_mm512_min_ps(x, _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN())), _mm512_set1_ps(1.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f243(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_min_ps(_mm512_min_ps(x, _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN())), _mm512_set1_ps(-1.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f244(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_min_ps(_mm512_min_ps(x, _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN())), _mm512_set1_ps(std::numeric_limits<float>::infinity())); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f245(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_min_ps(_mm512_min_ps(x, _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN())), _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN())); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f246(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_max_ps(x, x); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f247(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_max_ps(x, _mm512_setzero_ps()); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f248(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_max_ps(_mm512_setzero_ps(), x); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f249(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_max_ps(x, _mm512_set1_ps(-0.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f250(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_max_ps(_mm512_set1_ps(-0.0f), x); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f251(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_max_ps(x, _mm512_set1_ps(1.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f252(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_max_ps(_mm512_set1_ps(1.0f), x); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f253(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_max_ps(x, _mm512_set1_ps(-1.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f254(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_max_ps(_mm512_set1_ps(-1.0f), x); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f255(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_max_ps(x, _mm512_set1_ps(std::numeric_limits<float>::infinity())); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f256(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_max_ps(_mm512_set1_ps(std::numeric_limits<float>::infinity()), x); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f257(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_max_ps(x, _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN())); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f258(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_max_ps(_mm512_set1_ps(std::numeric_limits<float>::quiet_NaN()), x); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f259(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_max_ps(_mm512_max_ps(x, _mm512_setzero_ps()), _mm512_setzero_ps()); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f260(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_max_ps(_mm512_max_ps(x, _mm512_setzero_ps()), _mm512_set1_ps(-0.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f261(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_max_ps(_mm512_max_ps(x, _mm512_setzero_ps()), _mm512_set1_ps(1.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f262(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_max_ps(_mm512_max_ps(x, _mm512_setzero_ps()), _mm512_set1_ps(-1.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f263(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_max_ps(_mm512_max_ps(x, _mm512_setzero_ps()), _mm512_set1_ps(std::numeric_limits<float>::infinity())); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f264(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_max_ps(_mm512_max_ps(x, _mm512_setzero_ps()), _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN())); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f265(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_max_ps(_mm512_max_ps(x, _mm512_set1_ps(-0.0f)), _mm512_setzero_ps()); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f266(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_max_ps(_mm512_max_ps(x, _mm512_set1_ps(-0.0f)), _mm512_set1_ps(-0.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f267(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_max_ps(_mm512_max_ps(x, _mm512_set1_ps(-0.0f)), _mm512_set1_ps(1.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f268(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_max_ps(_mm512_max_ps(x, _mm512_set1_ps(-0.0f)), _mm512_set1_ps(-1.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f269(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_max_ps(_mm512_max_ps(x, _mm512_set1_ps(-0.0f)), _mm512_set1_ps(std::numeric_limits<float>::infinity())); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f270(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_max_ps(_mm512_max_ps(x, _mm512_set1_ps(-0.0f)), _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN())); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f271(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_max_ps(_mm512_max_ps(x, _mm512_set1_ps(1.0f)), _mm512_setzero_ps()); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f272(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_max_ps(_mm512_max_ps(x, _mm512_set1_ps(1.0f)), _mm512_set1_ps(-0.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f273(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_max_ps(_mm512_max_ps(x, _mm512_set1_ps(1.0f)), _mm512_set1_ps(1.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f274(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_max_ps(_mm512_max_ps(x, _mm512_set1_ps(1.0f)), _mm512_set1_ps(-1.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f275(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_max_ps(_mm512_max_ps(x, _mm512_set1_ps(1.0f)), _mm512_set1_ps(std::numeric_limits<float>::infinity())); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f276(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_max_ps(_mm512_max_ps(x, _mm512_set1_ps(1.0f)), _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN())); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f277(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_max_ps(_mm512_max_ps(x, _mm512_set1_ps(-1.0f)), _mm512_setzero_ps()); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f278(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_max_ps(_mm512_max_ps(x, _mm512_set1_ps(-1.0f)), _mm512_set1_ps(-0.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f279(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_max_ps(_mm512_max_ps(x, _mm512_set1_ps(-1.0f)), _mm512_set1_ps(1.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f280(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_max_ps(_mm512_max_ps(x, _mm512_set1_ps(-1.0f)), _mm512_set1_ps(-1.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f281(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_max_ps(_mm512_max_ps(x, _mm512_set1_ps(-1.0f)), _mm512_set1_ps(std::numeric_limits<float>::infinity())); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f282(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_max_ps(_mm512_max_ps(x, _mm512_set1_ps(-1.0f)), _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN())); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f283(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_max_ps(_mm512_max_ps(x, _mm512_set1_ps(std::numeric_limits<float>::infinity())), _mm512_setzero_ps()); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f284(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_max_ps(_mm512_max_ps(x, _mm512_set1_ps(std::numeric_limits<float>::infinity())), _mm512_set1_ps(-0.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f285(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_max_ps(_mm512_max_ps(x, _mm512_set1_ps(std::numeric_limits<float>::infinity())), _mm512_set1_ps(1.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f286(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_max_ps(_mm512_max_ps(x, _mm512_set1_ps(std::numeric_limits<float>::infinity())), _mm512_set1_ps(-1.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f287(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_max_ps(_mm512_max_ps(x, _mm512_set1_ps(std::numeric_limits<float>::infinity())), _mm512_set1_ps(std::numeric_limits<float>::infinity())); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f288(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_max_ps(_mm512_max_ps(x, _mm512_set1_ps(std::numeric_limits<float>::infinity())), _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN())); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f289(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_max_ps(_mm512_max_ps(x, _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN())), _mm512_setzero_ps()); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f290(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_max_ps(_mm512_max_ps(x, _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN())), _mm512_set1_ps(-0.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f291(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_max_ps(_mm512_max_ps(x, _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN())), _mm512_set1_ps(1.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f292(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_max_ps(_mm512_max_ps(x, _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN())), _mm512_set1_ps(-1.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f293(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_max_ps(_mm512_max_ps(x, _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN())), _mm512_set1_ps(std::numeric_limits<float>::infinity())); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f294(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_max_ps(_mm512_max_ps(x, _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN())), _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN())); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f295(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_and_ps(x, x); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f296(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_and_ps(x, _mm512_setzero_ps()); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f297(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_and_ps(_mm512_setzero_ps(), x); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f298(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_and_ps(x, _mm512_set1_ps(-0.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f299(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_and_ps(_mm512_set1_ps(-0.0f), x); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f300(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_and_ps(x, _mm512_set1_ps(1.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f301(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_and_ps(_mm512_set1_ps(1.0f), x); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f302(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_and_ps(x, _mm512_set1_ps(-1.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f303(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_and_ps(_mm512_set1_ps(-1.0f), x); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f304(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_and_ps(x, _mm512_set1_ps(std::numeric_limits<float>::infinity())); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f305(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_and_ps(_mm512_set1_ps(std::numeric_limits<float>::infinity()), x); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f306(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_and_ps(x, _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN())); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f307(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_and_ps(_mm512_set1_ps(std::numeric_limits<float>::quiet_NaN()), x); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f308(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_and_ps(_mm512_and_ps(x, _mm512_setzero_ps()), _mm512_setzero_ps()); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f309(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_and_ps(_mm512_and_ps(x, _mm512_setzero_ps()), _mm512_set1_ps(-0.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f310(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_and_ps(_mm512_and_ps(x, _mm512_setzero_ps()), _mm512_set1_ps(1.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f311(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_and_ps(_mm512_and_ps(x, _mm512_setzero_ps()), _mm512_set1_ps(-1.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f312(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_and_ps(_mm512_and_ps(x, _mm512_setzero_ps()), _mm512_set1_ps(std::numeric_limits<float>::infinity())); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f313(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_and_ps(_mm512_and_ps(x, _mm512_setzero_ps()), _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN())); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f314(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_and_ps(_mm512_and_ps(x, _mm512_set1_ps(-0.0f)), _mm512_setzero_ps()); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f315(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_and_ps(_mm512_and_ps(x, _mm512_set1_ps(-0.0f)), _mm512_set1_ps(-0.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f316(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_and_ps(_mm512_and_ps(x, _mm512_set1_ps(-0.0f)), _mm512_set1_ps(1.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f317(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_and_ps(_mm512_and_ps(x, _mm512_set1_ps(-0.0f)), _mm512_set1_ps(-1.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f318(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_and_ps(_mm512_and_ps(x, _mm512_set1_ps(-0.0f)), _mm512_set1_ps(std::numeric_limits<float>::infinity())); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f319(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_and_ps(_mm512_and_ps(x, _mm512_set1_ps(-0.0f)), _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN())); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f320(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_and_ps(_mm512_and_ps(x, _mm512_set1_ps(1.0f)), _mm512_setzero_ps()); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f321(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_and_ps(_mm512_and_ps(x, _mm512_set1_ps(1.0f)), _mm512_set1_ps(-0.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f322(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_and_ps(_mm512_and_ps(x, _mm512_set1_ps(1.0f)), _mm512_set1_ps(1.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f323(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_and_ps(_mm512_and_ps(x, _mm512_set1_ps(1.0f)), _mm512_set1_ps(-1.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f324(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_and_ps(_mm512_and_ps(x, _mm512_set1_ps(1.0f)), _mm512_set1_ps(std::numeric_limits<float>::infinity())); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f325(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_and_ps(_mm512_and_ps(x, _mm512_set1_ps(1.0f)), _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN())); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f326(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_and_ps(_mm512_and_ps(x, _mm512_set1_ps(-1.0f)), _mm512_setzero_ps()); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f327(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_and_ps(_mm512_and_ps(x, _mm512_set1_ps(-1.0f)), _mm512_set1_ps(-0.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f328(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_and_ps(_mm512_and_ps(x, _mm512_set1_ps(-1.0f)), _mm512_set1_ps(1.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f329(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_and_ps(_mm512_and_ps(x, _mm512_set1_ps(-1.0f)), _mm512_set1_ps(-1.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f330(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_and_ps(_mm512_and_ps(x, _mm512_set1_ps(-1.0f)), _mm512_set1_ps(std::numeric_limits<float>::infinity())); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f331(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_and_ps(_mm512_and_ps(x, _mm512_set1_ps(-1.0f)), _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN())); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f332(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_and_ps(_mm512_and_ps(x, _mm512_set1_ps(std::numeric_limits<float>::infinity())), _mm512_setzero_ps()); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f333(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_and_ps(_mm512_and_ps(x, _mm512_set1_ps(std::numeric_limits<float>::infinity())), _mm512_set1_ps(-0.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f334(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_and_ps(_mm512_and_ps(x, _mm512_set1_ps(std::numeric_limits<float>::infinity())), _mm512_set1_ps(1.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f335(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_and_ps(_mm512_and_ps(x, _mm512_set1_ps(std::numeric_limits<float>::infinity())), _mm512_set1_ps(-1.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f336(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_and_ps(_mm512_and_ps(x, _mm512_set1_ps(std::numeric_limits<float>::infinity())), _mm512_set1_ps(std::numeric_limits<float>::infinity())); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f337(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_and_ps(_mm512_and_ps(x, _mm512_set1_ps(std::numeric_limits<float>::infinity())), _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN())); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f338(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_and_ps(_mm512_and_ps(x, _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN())), _mm512_setzero_ps()); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f339(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_and_ps(_mm512_and_ps(x, _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN())), _mm512_set1_ps(-0.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f340(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_and_ps(_mm512_and_ps(x, _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN())), _mm512_set1_ps(1.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f341(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_and_ps(_mm512_and_ps(x, _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN())), _mm512_set1_ps(-1.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f342(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_and_ps(_mm512_and_ps(x, _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN())), _mm512_set1_ps(std::numeric_limits<float>::infinity())); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f343(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_and_ps(_mm512_and_ps(x, _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN())), _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN())); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f344(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_or_ps(x, x); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f345(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_or_ps(x, _mm512_setzero_ps()); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f346(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_or_ps(_mm512_setzero_ps(), x); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f347(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_or_ps(x, _mm512_set1_ps(-0.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f348(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_or_ps(_mm512_set1_ps(-0.0f), x); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f349(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_or_ps(x, _mm512_set1_ps(1.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f350(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_or_ps(_mm512_set1_ps(1.0f), x); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f351(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_or_ps(x, _mm512_set1_ps(-1.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f352(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_or_ps(_mm512_set1_ps(-1.0f), x); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f353(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_or_ps(x, _mm512_set1_ps(std::numeric_limits<float>::infinity())); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f354(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_or_ps(_mm512_set1_ps(std::numeric_limits<float>::infinity()), x); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f355(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_or_ps(x, _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN())); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f356(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_or_ps(_mm512_set1_ps(std::numeric_limits<float>::quiet_NaN()), x); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f357(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_or_ps(_mm512_or_ps(x, _mm512_setzero_ps()), _mm512_setzero_ps()); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f358(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_or_ps(_mm512_or_ps(x, _mm512_setzero_ps()), _mm512_set1_ps(-0.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f359(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_or_ps(_mm512_or_ps(x, _mm512_setzero_ps()), _mm512_set1_ps(1.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f360(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_or_ps(_mm512_or_ps(x, _mm512_setzero_ps()), _mm512_set1_ps(-1.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f361(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_or_ps(_mm512_or_ps(x, _mm512_setzero_ps()), _mm512_set1_ps(std::numeric_limits<float>::infinity())); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f362(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_or_ps(_mm512_or_ps(x, _mm512_setzero_ps()), _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN())); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f363(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_or_ps(_mm512_or_ps(x, _mm512_set1_ps(-0.0f)), _mm512_setzero_ps()); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f364(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_or_ps(_mm512_or_ps(x, _mm512_set1_ps(-0.0f)), _mm512_set1_ps(-0.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f365(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_or_ps(_mm512_or_ps(x, _mm512_set1_ps(-0.0f)), _mm512_set1_ps(1.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f366(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_or_ps(_mm512_or_ps(x, _mm512_set1_ps(-0.0f)), _mm512_set1_ps(-1.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f367(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_or_ps(_mm512_or_ps(x, _mm512_set1_ps(-0.0f)), _mm512_set1_ps(std::numeric_limits<float>::infinity())); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f368(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_or_ps(_mm512_or_ps(x, _mm512_set1_ps(-0.0f)), _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN())); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f369(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_or_ps(_mm512_or_ps(x, _mm512_set1_ps(1.0f)), _mm512_setzero_ps()); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f370(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_or_ps(_mm512_or_ps(x, _mm512_set1_ps(1.0f)), _mm512_set1_ps(-0.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f371(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_or_ps(_mm512_or_ps(x, _mm512_set1_ps(1.0f)), _mm512_set1_ps(1.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f372(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_or_ps(_mm512_or_ps(x, _mm512_set1_ps(1.0f)), _mm512_set1_ps(-1.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f373(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_or_ps(_mm512_or_ps(x, _mm512_set1_ps(1.0f)), _mm512_set1_ps(std::numeric_limits<float>::infinity())); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f374(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_or_ps(_mm512_or_ps(x, _mm512_set1_ps(1.0f)), _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN())); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f375(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_or_ps(_mm512_or_ps(x, _mm512_set1_ps(-1.0f)), _mm512_setzero_ps()); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f376(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_or_ps(_mm512_or_ps(x, _mm512_set1_ps(-1.0f)), _mm512_set1_ps(-0.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f377(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_or_ps(_mm512_or_ps(x, _mm512_set1_ps(-1.0f)), _mm512_set1_ps(1.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f378(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_or_ps(_mm512_or_ps(x, _mm512_set1_ps(-1.0f)), _mm512_set1_ps(-1.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f379(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_or_ps(_mm512_or_ps(x, _mm512_set1_ps(-1.0f)), _mm512_set1_ps(std::numeric_limits<float>::infinity())); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f380(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_or_ps(_mm512_or_ps(x, _mm512_set1_ps(-1.0f)), _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN())); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f381(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_or_ps(_mm512_or_ps(x, _mm512_set1_ps(std::numeric_limits<float>::infinity())), _mm512_setzero_ps()); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f382(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_or_ps(_mm512_or_ps(x, _mm512_set1_ps(std::numeric_limits<float>::infinity())), _mm512_set1_ps(-0.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f383(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_or_ps(_mm512_or_ps(x, _mm512_set1_ps(std::numeric_limits<float>::infinity())), _mm512_set1_ps(1.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f384(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_or_ps(_mm512_or_ps(x, _mm512_set1_ps(std::numeric_limits<float>::infinity())), _mm512_set1_ps(-1.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f385(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_or_ps(_mm512_or_ps(x, _mm512_set1_ps(std::numeric_limits<float>::infinity())), _mm512_set1_ps(std::numeric_limits<float>::infinity())); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f386(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_or_ps(_mm512_or_ps(x, _mm512_set1_ps(std::numeric_limits<float>::infinity())), _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN())); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f387(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_or_ps(_mm512_or_ps(x, _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN())), _mm512_setzero_ps()); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f388(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_or_ps(_mm512_or_ps(x, _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN())), _mm512_set1_ps(-0.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f389(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_or_ps(_mm512_or_ps(x, _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN())), _mm512_set1_ps(1.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f390(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_or_ps(_mm512_or_ps(x, _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN())), _mm512_set1_ps(-1.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f391(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_or_ps(_mm512_or_ps(x, _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN())), _mm512_set1_ps(std::numeric_limits<float>::infinity())); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f392(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_or_ps(_mm512_or_ps(x, _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN())), _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN())); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f393(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_xor_ps(x, x); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f394(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_xor_ps(x, _mm512_setzero_ps()); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f395(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_xor_ps(_mm512_setzero_ps(), x); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f396(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_xor_ps(x, _mm512_set1_ps(-0.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f397(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_xor_ps(_mm512_set1_ps(-0.0f), x); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f398(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_xor_ps(x, _mm512_set1_ps(1.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f399(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_xor_ps(_mm512_set1_ps(1.0f), x); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f400(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_xor_ps(x, _mm512_set1_ps(-1.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f401(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_xor_ps(_mm512_set1_ps(-1.0f), x); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f402(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_xor_ps(x, _mm512_set1_ps(std::numeric_limits<float>::infinity())); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f403(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_xor_ps(_mm512_set1_ps(std::numeric_limits<float>::infinity()), x); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f404(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_xor_ps(x, _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN())); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f405(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_xor_ps(_mm512_set1_ps(std::numeric_limits<float>::quiet_NaN()), x); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f406(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_xor_ps(_mm512_xor_ps(x, _mm512_setzero_ps()), _mm512_setzero_ps()); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f407(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_xor_ps(_mm512_xor_ps(x, _mm512_setzero_ps()), _mm512_set1_ps(-0.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f408(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_xor_ps(_mm512_xor_ps(x, _mm512_setzero_ps()), _mm512_set1_ps(1.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f409(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_xor_ps(_mm512_xor_ps(x, _mm512_setzero_ps()), _mm512_set1_ps(-1.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f410(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_xor_ps(_mm512_xor_ps(x, _mm512_setzero_ps()), _mm512_set1_ps(std::numeric_limits<float>::infinity())); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f411(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_xor_ps(_mm512_xor_ps(x, _mm512_setzero_ps()), _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN())); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f412(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_xor_ps(_mm512_xor_ps(x, _mm512_set1_ps(-0.0f)), _mm512_setzero_ps()); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f413(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_xor_ps(_mm512_xor_ps(x, _mm512_set1_ps(-0.0f)), _mm512_set1_ps(1.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f414(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_xor_ps(_mm512_xor_ps(x, _mm512_set1_ps(-0.0f)), _mm512_set1_ps(-1.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f415(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_xor_ps(_mm512_xor_ps(x, _mm512_set1_ps(-0.0f)), _mm512_set1_ps(std::numeric_limits<float>::infinity())); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f416(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_xor_ps(_mm512_xor_ps(x, _mm512_set1_ps(-0.0f)), _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN())); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f417(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_xor_ps(_mm512_xor_ps(x, _mm512_set1_ps(1.0f)), _mm512_setzero_ps()); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f418(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_xor_ps(_mm512_xor_ps(x, _mm512_set1_ps(1.0f)), _mm512_set1_ps(-0.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f419(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_xor_ps(_mm512_xor_ps(x, _mm512_set1_ps(1.0f)), _mm512_set1_ps(1.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f420(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_xor_ps(_mm512_xor_ps(x, _mm512_set1_ps(1.0f)), _mm512_set1_ps(-1.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f421(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_xor_ps(_mm512_xor_ps(x, _mm512_set1_ps(1.0f)), _mm512_set1_ps(std::numeric_limits<float>::infinity())); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f422(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_xor_ps(_mm512_xor_ps(x, _mm512_set1_ps(1.0f)), _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN())); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f423(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_xor_ps(_mm512_xor_ps(x, _mm512_set1_ps(-1.0f)), _mm512_setzero_ps()); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f424(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_xor_ps(_mm512_xor_ps(x, _mm512_set1_ps(-1.0f)), _mm512_set1_ps(-0.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f425(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_xor_ps(_mm512_xor_ps(x, _mm512_set1_ps(-1.0f)), _mm512_set1_ps(1.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f426(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_xor_ps(_mm512_xor_ps(x, _mm512_set1_ps(-1.0f)), _mm512_set1_ps(-1.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f427(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_xor_ps(_mm512_xor_ps(x, _mm512_set1_ps(-1.0f)), _mm512_set1_ps(std::numeric_limits<float>::infinity())); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f428(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_xor_ps(_mm512_xor_ps(x, _mm512_set1_ps(-1.0f)), _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN())); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f429(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_xor_ps(_mm512_xor_ps(x, _mm512_set1_ps(std::numeric_limits<float>::infinity())), _mm512_setzero_ps()); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f430(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_xor_ps(_mm512_xor_ps(x, _mm512_set1_ps(std::numeric_limits<float>::infinity())), _mm512_set1_ps(-0.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f431(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_xor_ps(_mm512_xor_ps(x, _mm512_set1_ps(std::numeric_limits<float>::infinity())), _mm512_set1_ps(1.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f432(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_xor_ps(_mm512_xor_ps(x, _mm512_set1_ps(std::numeric_limits<float>::infinity())), _mm512_set1_ps(-1.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f433(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_xor_ps(_mm512_xor_ps(x, _mm512_set1_ps(std::numeric_limits<float>::infinity())), _mm512_set1_ps(std::numeric_limits<float>::infinity())); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f434(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_xor_ps(_mm512_xor_ps(x, _mm512_set1_ps(std::numeric_limits<float>::infinity())), _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN())); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f435(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_xor_ps(_mm512_xor_ps(x, _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN())), _mm512_setzero_ps()); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f436(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_xor_ps(_mm512_xor_ps(x, _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN())), _mm512_set1_ps(-0.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f437(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_xor_ps(_mm512_xor_ps(x, _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN())), _mm512_set1_ps(1.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f438(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_xor_ps(_mm512_xor_ps(x, _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN())), _mm512_set1_ps(-1.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f439(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_xor_ps(_mm512_xor_ps(x, _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN())), _mm512_set1_ps(std::numeric_limits<float>::infinity())); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f440(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_xor_ps(_mm512_xor_ps(x, _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN())), _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN())); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f441(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_andnot_ps(x, x); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f442(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_andnot_ps(x, _mm512_setzero_ps()); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f443(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_andnot_ps(_mm512_setzero_ps(), x); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f444(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_andnot_ps(x, _mm512_set1_ps(-0.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f445(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_andnot_ps(_mm512_set1_ps(-0.0f), x); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f446(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_andnot_ps(x, _mm512_set1_ps(1.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f447(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_andnot_ps(_mm512_set1_ps(1.0f), x); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f448(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_andnot_ps(x, _mm512_set1_ps(-1.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f449(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_andnot_ps(_mm512_set1_ps(-1.0f), x); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f450(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_andnot_ps(x, _mm512_set1_ps(std::numeric_limits<float>::infinity())); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f451(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_andnot_ps(_mm512_set1_ps(std::numeric_limits<float>::infinity()), x); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f452(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_andnot_ps(x, _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN())); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f453(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_andnot_ps(_mm512_set1_ps(std::numeric_limits<float>::quiet_NaN()), x); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f454(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_andnot_ps(_mm512_andnot_ps(x, _mm512_setzero_ps()), _mm512_setzero_ps()); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f455(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_andnot_ps(_mm512_andnot_ps(x, _mm512_setzero_ps()), _mm512_set1_ps(-0.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f456(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_andnot_ps(_mm512_andnot_ps(x, _mm512_setzero_ps()), _mm512_set1_ps(1.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f457(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_andnot_ps(_mm512_andnot_ps(x, _mm512_setzero_ps()), _mm512_set1_ps(-1.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f458(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_andnot_ps(_mm512_andnot_ps(x, _mm512_setzero_ps()), _mm512_set1_ps(std::numeric_limits<float>::infinity())); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f459(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_andnot_ps(_mm512_andnot_ps(x, _mm512_setzero_ps()), _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN())); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f460(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_andnot_ps(_mm512_andnot_ps(x, _mm512_set1_ps(-0.0f)), _mm512_setzero_ps()); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f461(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_andnot_ps(_mm512_andnot_ps(x, _mm512_set1_ps(-0.0f)), _mm512_set1_ps(-0.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f462(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_andnot_ps(_mm512_andnot_ps(x, _mm512_set1_ps(-0.0f)), _mm512_set1_ps(1.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f463(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_andnot_ps(_mm512_andnot_ps(x, _mm512_set1_ps(-0.0f)), _mm512_set1_ps(-1.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f464(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_andnot_ps(_mm512_andnot_ps(x, _mm512_set1_ps(-0.0f)), _mm512_set1_ps(std::numeric_limits<float>::infinity())); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f465(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_andnot_ps(_mm512_andnot_ps(x, _mm512_set1_ps(-0.0f)), _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN())); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f466(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_andnot_ps(_mm512_andnot_ps(x, _mm512_set1_ps(1.0f)), _mm512_setzero_ps()); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f467(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_andnot_ps(_mm512_andnot_ps(x, _mm512_set1_ps(1.0f)), _mm512_set1_ps(-0.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f468(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_andnot_ps(_mm512_andnot_ps(x, _mm512_set1_ps(1.0f)), _mm512_set1_ps(1.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f469(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_andnot_ps(_mm512_andnot_ps(x, _mm512_set1_ps(1.0f)), _mm512_set1_ps(-1.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f470(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_andnot_ps(_mm512_andnot_ps(x, _mm512_set1_ps(1.0f)), _mm512_set1_ps(std::numeric_limits<float>::infinity())); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f471(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_andnot_ps(_mm512_andnot_ps(x, _mm512_set1_ps(1.0f)), _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN())); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f472(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_andnot_ps(_mm512_andnot_ps(x, _mm512_set1_ps(-1.0f)), _mm512_setzero_ps()); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f473(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_andnot_ps(_mm512_andnot_ps(x, _mm512_set1_ps(-1.0f)), _mm512_set1_ps(-0.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f474(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_andnot_ps(_mm512_andnot_ps(x, _mm512_set1_ps(-1.0f)), _mm512_set1_ps(1.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f475(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_andnot_ps(_mm512_andnot_ps(x, _mm512_set1_ps(-1.0f)), _mm512_set1_ps(-1.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f476(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_andnot_ps(_mm512_andnot_ps(x, _mm512_set1_ps(-1.0f)), _mm512_set1_ps(std::numeric_limits<float>::infinity())); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f477(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_andnot_ps(_mm512_andnot_ps(x, _mm512_set1_ps(-1.0f)), _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN())); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f478(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_andnot_ps(_mm512_andnot_ps(x, _mm512_set1_ps(std::numeric_limits<float>::infinity())), _mm512_setzero_ps()); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f479(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_andnot_ps(_mm512_andnot_ps(x, _mm512_set1_ps(std::numeric_limits<float>::infinity())), _mm512_set1_ps(-0.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f480(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_andnot_ps(_mm512_andnot_ps(x, _mm512_set1_ps(std::numeric_limits<float>::infinity())), _mm512_set1_ps(1.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f481(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_andnot_ps(_mm512_andnot_ps(x, _mm512_set1_ps(std::numeric_limits<float>::infinity())), _mm512_set1_ps(-1.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f482(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_andnot_ps(_mm512_andnot_ps(x, _mm512_set1_ps(std::numeric_limits<float>::infinity())), _mm512_set1_ps(std::numeric_limits<float>::infinity())); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f483(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_andnot_ps(_mm512_andnot_ps(x, _mm512_set1_ps(std::numeric_limits<float>::infinity())), _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN())); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f484(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_andnot_ps(_mm512_andnot_ps(x, _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN())), _mm512_setzero_ps()); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f485(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_andnot_ps(_mm512_andnot_ps(x, _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN())), _mm512_set1_ps(-0.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f486(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_andnot_ps(_mm512_andnot_ps(x, _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN())), _mm512_set1_ps(1.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f487(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_andnot_ps(_mm512_andnot_ps(x, _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN())), _mm512_set1_ps(-1.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f488(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_andnot_ps(_mm512_andnot_ps(x, _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN())), _mm512_set1_ps(std::numeric_limits<float>::infinity())); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f489(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_andnot_ps(_mm512_andnot_ps(x, _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN())), _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN())); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f490(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_add_ps(_mm512_add_ps(x, y), y); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f491(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_add_ps(x, _mm512_add_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f492(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_add_ps(_mm512_add_ps(x, y), x); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f493(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_add_ps(y, _mm512_add_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f494(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_add_ps(_mm512_sub_ps(x, y), y); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f495(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_add_ps(x, _mm512_sub_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f496(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_add_ps(_mm512_sub_ps(x, y), x); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f497(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_add_ps(y, _mm512_sub_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f498(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_add_ps(_mm512_mul_ps(x, y), y); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f499(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_add_ps(x, _mm512_mul_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f500(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_add_ps(_mm512_mul_ps(x, y), x); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f501(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_add_ps(y, _mm512_mul_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f502(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_add_ps(_mm512_div_ps(x, y), y); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f503(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_add_ps(x, _mm512_div_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f504(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_add_ps(_mm512_div_ps(x, y), x); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f505(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_add_ps(y, _mm512_div_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f506(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_add_ps(_mm512_min_ps(x, y), y); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f507(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_add_ps(x, _mm512_min_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f508(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_add_ps(_mm512_min_ps(x, y), x); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f509(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_add_ps(y, _mm512_min_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f510(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_add_ps(_mm512_max_ps(x, y), y); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f511(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_add_ps(x, _mm512_max_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f512(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_add_ps(_mm512_max_ps(x, y), x); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f513(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_add_ps(y, _mm512_max_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f514(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_add_ps(_mm512_and_ps(x, y), y); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f515(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_add_ps(x, _mm512_and_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f516(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_add_ps(_mm512_and_ps(x, y), x); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f517(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_add_ps(y, _mm512_and_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f518(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_add_ps(_mm512_or_ps(x, y), y); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f519(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_add_ps(x, _mm512_or_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f520(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_add_ps(_mm512_or_ps(x, y), x); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f521(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_add_ps(y, _mm512_or_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f522(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_add_ps(_mm512_xor_ps(x, y), y); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f523(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_add_ps(x, _mm512_xor_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f524(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_add_ps(_mm512_xor_ps(x, y), x); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f525(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_add_ps(y, _mm512_xor_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f526(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_add_ps(_mm512_andnot_ps(x, y), y); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f527(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_add_ps(x, _mm512_andnot_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f528(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_add_ps(_mm512_andnot_ps(x, y), x); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f529(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_add_ps(y, _mm512_andnot_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f530(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_sub_ps(_mm512_add_ps(x, y), y); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f531(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_sub_ps(x, _mm512_add_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f532(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_sub_ps(_mm512_add_ps(x, y), x); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f533(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_sub_ps(y, _mm512_add_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f534(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_sub_ps(_mm512_sub_ps(x, y), y); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f535(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_sub_ps(x, _mm512_sub_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f536(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_sub_ps(_mm512_sub_ps(x, y), x); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f537(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_sub_ps(y, _mm512_sub_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f538(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_sub_ps(_mm512_mul_ps(x, y), y); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f539(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_sub_ps(x, _mm512_mul_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f540(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_sub_ps(_mm512_mul_ps(x, y), x); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f541(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_sub_ps(y, _mm512_mul_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f542(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_sub_ps(_mm512_div_ps(x, y), y); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f543(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_sub_ps(x, _mm512_div_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f544(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_sub_ps(_mm512_div_ps(x, y), x); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f545(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_sub_ps(y, _mm512_div_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f546(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_sub_ps(_mm512_min_ps(x, y), y); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f547(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_sub_ps(x, _mm512_min_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f548(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_sub_ps(_mm512_min_ps(x, y), x); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f549(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_sub_ps(y, _mm512_min_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f550(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_sub_ps(_mm512_max_ps(x, y), y); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f551(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_sub_ps(x, _mm512_max_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f552(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_sub_ps(_mm512_max_ps(x, y), x); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f553(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_sub_ps(y, _mm512_max_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f554(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_sub_ps(_mm512_and_ps(x, y), y); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f555(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_sub_ps(x, _mm512_and_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f556(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_sub_ps(_mm512_and_ps(x, y), x); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f557(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_sub_ps(y, _mm512_and_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f558(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_sub_ps(_mm512_or_ps(x, y), y); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f559(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_sub_ps(x, _mm512_or_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f560(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_sub_ps(_mm512_or_ps(x, y), x); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f561(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_sub_ps(y, _mm512_or_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f562(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_sub_ps(_mm512_xor_ps(x, y), y); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f563(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_sub_ps(x, _mm512_xor_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f564(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_sub_ps(_mm512_xor_ps(x, y), x); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f565(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_sub_ps(y, _mm512_xor_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f566(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_sub_ps(_mm512_andnot_ps(x, y), y); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f567(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_sub_ps(x, _mm512_andnot_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f568(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_sub_ps(_mm512_andnot_ps(x, y), x); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f569(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_sub_ps(y, _mm512_andnot_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f570(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_mul_ps(_mm512_add_ps(x, y), y); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f571(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_mul_ps(x, _mm512_add_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f572(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_mul_ps(_mm512_add_ps(x, y), x); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f573(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_mul_ps(y, _mm512_add_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f574(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_mul_ps(_mm512_sub_ps(x, y), y); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f575(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_mul_ps(x, _mm512_sub_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f576(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_mul_ps(_mm512_sub_ps(x, y), x); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f577(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_mul_ps(y, _mm512_sub_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f578(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_mul_ps(_mm512_mul_ps(x, y), y); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f579(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_mul_ps(x, _mm512_mul_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f580(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_mul_ps(_mm512_mul_ps(x, y), x); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f581(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_mul_ps(y, _mm512_mul_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f582(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_mul_ps(_mm512_div_ps(x, y), y); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f583(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_mul_ps(x, _mm512_div_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f584(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_mul_ps(_mm512_div_ps(x, y), x); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f585(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_mul_ps(y, _mm512_div_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f586(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_mul_ps(_mm512_min_ps(x, y), y); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f587(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_mul_ps(x, _mm512_min_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f588(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_mul_ps(_mm512_min_ps(x, y), x); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f589(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_mul_ps(y, _mm512_min_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f590(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_mul_ps(_mm512_max_ps(x, y), y); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f591(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_mul_ps(x, _mm512_max_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f592(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_mul_ps(_mm512_max_ps(x, y), x); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f593(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_mul_ps(y, _mm512_max_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f594(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_mul_ps(_mm512_and_ps(x, y), y); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f595(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_mul_ps(x, _mm512_and_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f596(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_mul_ps(_mm512_and_ps(x, y), x); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f597(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_mul_ps(y, _mm512_and_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f598(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_mul_ps(_mm512_or_ps(x, y), y); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f599(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_mul_ps(x, _mm512_or_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f600(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_mul_ps(_mm512_or_ps(x, y), x); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f601(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_mul_ps(y, _mm512_or_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f602(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_mul_ps(_mm512_xor_ps(x, y), y); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f603(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_mul_ps(x, _mm512_xor_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f604(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_mul_ps(_mm512_xor_ps(x, y), x); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f605(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_mul_ps(y, _mm512_xor_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f606(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_mul_ps(_mm512_andnot_ps(x, y), y); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f607(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_mul_ps(x, _mm512_andnot_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f608(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_mul_ps(_mm512_andnot_ps(x, y), x); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f609(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_mul_ps(y, _mm512_andnot_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f610(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_div_ps(_mm512_add_ps(x, y), y); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f611(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_div_ps(x, _mm512_add_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f612(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_div_ps(_mm512_add_ps(x, y), x); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f613(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_div_ps(y, _mm512_add_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f614(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_div_ps(_mm512_sub_ps(x, y), y); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f615(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_div_ps(x, _mm512_sub_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f616(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_div_ps(_mm512_sub_ps(x, y), x); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f617(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_div_ps(y, _mm512_sub_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f618(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_div_ps(_mm512_mul_ps(x, y), y); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f619(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_div_ps(x, _mm512_mul_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f620(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_div_ps(_mm512_mul_ps(x, y), x); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f621(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_div_ps(y, _mm512_mul_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f622(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_div_ps(_mm512_div_ps(x, y), y); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f623(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_div_ps(x, _mm512_div_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f624(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_div_ps(_mm512_div_ps(x, y), x); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f625(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_div_ps(y, _mm512_div_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f626(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_div_ps(_mm512_min_ps(x, y), y); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f627(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_div_ps(x, _mm512_min_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f628(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_div_ps(_mm512_min_ps(x, y), x); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f629(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_div_ps(y, _mm512_min_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f630(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_div_ps(_mm512_max_ps(x, y), y); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f631(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_div_ps(x, _mm512_max_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f632(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_div_ps(_mm512_max_ps(x, y), x); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f633(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_div_ps(y, _mm512_max_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f634(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_div_ps(_mm512_and_ps(x, y), y); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f635(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_div_ps(x, _mm512_and_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f636(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_div_ps(_mm512_and_ps(x, y), x); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f637(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_div_ps(y, _mm512_and_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f638(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_div_ps(_mm512_or_ps(x, y), y); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f639(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_div_ps(x, _mm512_or_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f640(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_div_ps(_mm512_or_ps(x, y), x); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f641(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_div_ps(y, _mm512_or_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f642(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_div_ps(_mm512_xor_ps(x, y), y); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f643(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_div_ps(x, _mm512_xor_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f644(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_div_ps(_mm512_xor_ps(x, y), x); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f645(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_div_ps(y, _mm512_xor_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f646(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_div_ps(_mm512_andnot_ps(x, y), y); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f647(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_div_ps(x, _mm512_andnot_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f648(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_div_ps(_mm512_andnot_ps(x, y), x); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f649(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_div_ps(y, _mm512_andnot_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f650(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_min_ps(_mm512_add_ps(x, y), y); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f651(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_min_ps(x, _mm512_add_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f652(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_min_ps(_mm512_add_ps(x, y), x); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f653(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_min_ps(y, _mm512_add_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f654(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_min_ps(_mm512_sub_ps(x, y), y); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f655(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_min_ps(x, _mm512_sub_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f656(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_min_ps(_mm512_sub_ps(x, y), x); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f657(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_min_ps(y, _mm512_sub_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f658(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_min_ps(_mm512_mul_ps(x, y), y); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f659(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_min_ps(x, _mm512_mul_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f660(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_min_ps(_mm512_mul_ps(x, y), x); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f661(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_min_ps(y, _mm512_mul_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f662(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_min_ps(_mm512_div_ps(x, y), y); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f663(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_min_ps(x, _mm512_div_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f664(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_min_ps(_mm512_div_ps(x, y), x); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f665(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_min_ps(y, _mm512_div_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f666(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_min_ps(_mm512_min_ps(x, y), y); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f667(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_min_ps(x, _mm512_min_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f668(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_min_ps(_mm512_min_ps(x, y), x); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f669(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_min_ps(y, _mm512_min_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f670(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_min_ps(_mm512_max_ps(x, y), y); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f671(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_min_ps(x, _mm512_max_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f672(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_min_ps(_mm512_max_ps(x, y), x); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f673(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_min_ps(y, _mm512_max_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f674(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_min_ps(_mm512_and_ps(x, y), y); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f675(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_min_ps(x, _mm512_and_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f676(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_min_ps(_mm512_and_ps(x, y), x); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f677(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_min_ps(y, _mm512_and_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f678(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_min_ps(_mm512_or_ps(x, y), y); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f679(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_min_ps(x, _mm512_or_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f680(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_min_ps(_mm512_or_ps(x, y), x); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f681(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_min_ps(y, _mm512_or_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f682(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_min_ps(_mm512_xor_ps(x, y), y); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f683(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_min_ps(x, _mm512_xor_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f684(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_min_ps(_mm512_xor_ps(x, y), x); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f685(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_min_ps(y, _mm512_xor_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f686(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_min_ps(_mm512_andnot_ps(x, y), y); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f687(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_min_ps(x, _mm512_andnot_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f688(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_min_ps(_mm512_andnot_ps(x, y), x); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f689(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_min_ps(y, _mm512_andnot_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f690(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_max_ps(_mm512_add_ps(x, y), y); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f691(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_max_ps(x, _mm512_add_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f692(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_max_ps(_mm512_add_ps(x, y), x); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f693(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_max_ps(y, _mm512_add_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f694(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_max_ps(_mm512_sub_ps(x, y), y); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f695(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_max_ps(x, _mm512_sub_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f696(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_max_ps(_mm512_sub_ps(x, y), x); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f697(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_max_ps(y, _mm512_sub_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f698(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_max_ps(_mm512_mul_ps(x, y), y); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f699(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_max_ps(x, _mm512_mul_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f700(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_max_ps(_mm512_mul_ps(x, y), x); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f701(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_max_ps(y, _mm512_mul_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f702(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_max_ps(_mm512_div_ps(x, y), y); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f703(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_max_ps(x, _mm512_div_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f704(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_max_ps(_mm512_div_ps(x, y), x); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f705(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_max_ps(y, _mm512_div_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f706(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_max_ps(_mm512_min_ps(x, y), y); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f707(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_max_ps(x, _mm512_min_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f708(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_max_ps(_mm512_min_ps(x, y), x); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f709(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_max_ps(y, _mm512_min_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f710(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_max_ps(_mm512_max_ps(x, y), y); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f711(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_max_ps(x, _mm512_max_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f712(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_max_ps(_mm512_max_ps(x, y), x); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f713(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_max_ps(y, _mm512_max_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f714(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_max_ps(_mm512_and_ps(x, y), y); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f715(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_max_ps(x, _mm512_and_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f716(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_max_ps(_mm512_and_ps(x, y), x); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f717(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_max_ps(y, _mm512_and_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f718(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_max_ps(_mm512_or_ps(x, y), y); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f719(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_max_ps(x, _mm512_or_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f720(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_max_ps(_mm512_or_ps(x, y), x); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f721(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_max_ps(y, _mm512_or_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f722(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_max_ps(_mm512_xor_ps(x, y), y); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f723(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_max_ps(x, _mm512_xor_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f724(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_max_ps(_mm512_xor_ps(x, y), x); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f725(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_max_ps(y, _mm512_xor_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f726(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_max_ps(_mm512_andnot_ps(x, y), y); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f727(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_max_ps(x, _mm512_andnot_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f728(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_max_ps(_mm512_andnot_ps(x, y), x); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f729(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_max_ps(y, _mm512_andnot_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f730(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_and_ps(_mm512_add_ps(x, y), y); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f731(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_and_ps(x, _mm512_add_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f732(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_and_ps(_mm512_add_ps(x, y), x); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f733(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_and_ps(y, _mm512_add_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f734(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_and_ps(_mm512_sub_ps(x, y), y); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f735(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_and_ps(x, _mm512_sub_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f736(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_and_ps(_mm512_sub_ps(x, y), x); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f737(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_and_ps(y, _mm512_sub_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f738(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_and_ps(_mm512_mul_ps(x, y), y); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f739(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_and_ps(x, _mm512_mul_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f740(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_and_ps(_mm512_mul_ps(x, y), x); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f741(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_and_ps(y, _mm512_mul_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f742(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_and_ps(_mm512_div_ps(x, y), y); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f743(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_and_ps(x, _mm512_div_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f744(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_and_ps(_mm512_div_ps(x, y), x); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f745(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_and_ps(y, _mm512_div_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f746(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_and_ps(_mm512_min_ps(x, y), y); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f747(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_and_ps(x, _mm512_min_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f748(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_and_ps(_mm512_min_ps(x, y), x); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f749(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_and_ps(y, _mm512_min_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f750(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_and_ps(_mm512_max_ps(x, y), y); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f751(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_and_ps(x, _mm512_max_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f752(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_and_ps(_mm512_max_ps(x, y), x); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f753(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_and_ps(y, _mm512_max_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f754(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_and_ps(_mm512_and_ps(x, y), y); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f755(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_and_ps(x, _mm512_and_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f756(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_and_ps(_mm512_and_ps(x, y), x); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f757(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_and_ps(y, _mm512_and_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f758(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_and_ps(_mm512_or_ps(x, y), y); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f759(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_and_ps(x, _mm512_or_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f760(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_and_ps(_mm512_or_ps(x, y), x); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f761(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_and_ps(y, _mm512_or_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f762(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_and_ps(_mm512_xor_ps(x, y), y); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f763(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_and_ps(x, _mm512_xor_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f764(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_and_ps(_mm512_xor_ps(x, y), x); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f765(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_and_ps(y, _mm512_xor_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f766(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_and_ps(_mm512_andnot_ps(x, y), y); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f767(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_and_ps(x, _mm512_andnot_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f768(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_and_ps(_mm512_andnot_ps(x, y), x); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f769(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_and_ps(y, _mm512_andnot_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f770(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_or_ps(_mm512_add_ps(x, y), y); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f771(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_or_ps(x, _mm512_add_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f772(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_or_ps(_mm512_add_ps(x, y), x); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f773(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_or_ps(y, _mm512_add_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f774(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_or_ps(_mm512_sub_ps(x, y), y); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f775(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_or_ps(x, _mm512_sub_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f776(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_or_ps(_mm512_sub_ps(x, y), x); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f777(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_or_ps(y, _mm512_sub_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f778(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_or_ps(_mm512_mul_ps(x, y), y); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f779(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_or_ps(x, _mm512_mul_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f780(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_or_ps(_mm512_mul_ps(x, y), x); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f781(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_or_ps(y, _mm512_mul_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f782(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_or_ps(_mm512_div_ps(x, y), y); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f783(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_or_ps(x, _mm512_div_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f784(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_or_ps(_mm512_div_ps(x, y), x); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f785(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_or_ps(y, _mm512_div_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f786(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_or_ps(_mm512_min_ps(x, y), y); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f787(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_or_ps(x, _mm512_min_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f788(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_or_ps(_mm512_min_ps(x, y), x); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f789(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_or_ps(y, _mm512_min_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f790(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_or_ps(_mm512_max_ps(x, y), y); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f791(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_or_ps(x, _mm512_max_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f792(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_or_ps(_mm512_max_ps(x, y), x); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f793(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_or_ps(y, _mm512_max_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f794(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_or_ps(_mm512_and_ps(x, y), y); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f795(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_or_ps(x, _mm512_and_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f796(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_or_ps(_mm512_and_ps(x, y), x); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f797(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_or_ps(y, _mm512_and_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f798(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_or_ps(_mm512_or_ps(x, y), y); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f799(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_or_ps(x, _mm512_or_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f800(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_or_ps(_mm512_or_ps(x, y), x); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f801(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_or_ps(y, _mm512_or_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f802(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_or_ps(_mm512_xor_ps(x, y), y); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f803(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_or_ps(x, _mm512_xor_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f804(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_or_ps(_mm512_xor_ps(x, y), x); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f805(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_or_ps(y, _mm512_xor_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f806(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_or_ps(_mm512_andnot_ps(x, y), y); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f807(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_or_ps(x, _mm512_andnot_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f808(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_or_ps(_mm512_andnot_ps(x, y), x); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f809(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_or_ps(y, _mm512_andnot_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f810(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_xor_ps(_mm512_add_ps(x, y), y); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f811(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_xor_ps(x, _mm512_add_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f812(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_xor_ps(_mm512_add_ps(x, y), x); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f813(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_xor_ps(y, _mm512_add_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f814(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_xor_ps(_mm512_sub_ps(x, y), y); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f815(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_xor_ps(x, _mm512_sub_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f816(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_xor_ps(_mm512_sub_ps(x, y), x); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f817(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_xor_ps(y, _mm512_sub_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f818(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_xor_ps(_mm512_mul_ps(x, y), y); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f819(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_xor_ps(x, _mm512_mul_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f820(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_xor_ps(_mm512_mul_ps(x, y), x); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f821(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_xor_ps(y, _mm512_mul_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f822(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_xor_ps(_mm512_div_ps(x, y), y); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f823(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_xor_ps(x, _mm512_div_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f824(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_xor_ps(_mm512_div_ps(x, y), x); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f825(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_xor_ps(y, _mm512_div_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f826(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_xor_ps(_mm512_min_ps(x, y), y); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f827(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_xor_ps(x, _mm512_min_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f828(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_xor_ps(_mm512_min_ps(x, y), x); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f829(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_xor_ps(y, _mm512_min_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f830(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_xor_ps(_mm512_max_ps(x, y), y); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f831(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_xor_ps(x, _mm512_max_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f832(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_xor_ps(_mm512_max_ps(x, y), x); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f833(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_xor_ps(y, _mm512_max_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f834(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_xor_ps(_mm512_and_ps(x, y), y); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f835(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_xor_ps(x, _mm512_and_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f836(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_xor_ps(_mm512_and_ps(x, y), x); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f837(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_xor_ps(y, _mm512_and_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f838(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_xor_ps(_mm512_or_ps(x, y), y); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f839(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_xor_ps(x, _mm512_or_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f840(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_xor_ps(_mm512_or_ps(x, y), x); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f841(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_xor_ps(y, _mm512_or_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f842(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_xor_ps(_mm512_xor_ps(x, y), y); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f843(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_xor_ps(x, _mm512_xor_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f844(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_xor_ps(_mm512_xor_ps(x, y), x); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f845(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_xor_ps(y, _mm512_xor_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f846(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_xor_ps(_mm512_andnot_ps(x, y), y); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f847(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_xor_ps(x, _mm512_andnot_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f848(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_xor_ps(_mm512_andnot_ps(x, y), x); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f849(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_xor_ps(y, _mm512_andnot_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f850(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_andnot_ps(_mm512_add_ps(x, y), y); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f851(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_andnot_ps(x, _mm512_add_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f852(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_andnot_ps(_mm512_add_ps(x, y), x); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f853(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_andnot_ps(y, _mm512_add_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f854(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_andnot_ps(_mm512_sub_ps(x, y), y); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f855(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_andnot_ps(x, _mm512_sub_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f856(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_andnot_ps(_mm512_sub_ps(x, y), x); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f857(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_andnot_ps(y, _mm512_sub_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f858(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_andnot_ps(_mm512_mul_ps(x, y), y); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f859(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_andnot_ps(x, _mm512_mul_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f860(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_andnot_ps(_mm512_mul_ps(x, y), x); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f861(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_andnot_ps(y, _mm512_mul_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f862(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_andnot_ps(_mm512_div_ps(x, y), y); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f863(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_andnot_ps(x, _mm512_div_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f864(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_andnot_ps(_mm512_div_ps(x, y), x); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f865(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_andnot_ps(y, _mm512_div_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f866(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_andnot_ps(_mm512_min_ps(x, y), y); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f867(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_andnot_ps(x, _mm512_min_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f868(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_andnot_ps(_mm512_min_ps(x, y), x); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f869(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_andnot_ps(y, _mm512_min_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f870(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_andnot_ps(_mm512_max_ps(x, y), y); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f871(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_andnot_ps(x, _mm512_max_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f872(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_andnot_ps(_mm512_max_ps(x, y), x); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f873(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_andnot_ps(y, _mm512_max_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f874(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_andnot_ps(_mm512_and_ps(x, y), y); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f875(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_andnot_ps(x, _mm512_and_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f876(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_andnot_ps(_mm512_and_ps(x, y), x); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f877(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_andnot_ps(y, _mm512_and_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f878(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_andnot_ps(_mm512_or_ps(x, y), y); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f879(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_andnot_ps(x, _mm512_or_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f880(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_andnot_ps(_mm512_or_ps(x, y), x); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f881(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_andnot_ps(y, _mm512_or_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f882(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_andnot_ps(_mm512_xor_ps(x, y), y); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f883(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_andnot_ps(x, _mm512_xor_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f884(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_andnot_ps(_mm512_xor_ps(x, y), x); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f885(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_andnot_ps(y, _mm512_xor_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f886(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_andnot_ps(_mm512_andnot_ps(x, y), y); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f887(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_andnot_ps(x, _mm512_andnot_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f888(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_andnot_ps(_mm512_andnot_ps(x, y), x); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f889(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_andnot_ps(y, _mm512_andnot_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f890(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_sqrt_pd(_mm512_sqrt_pd(x)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f891(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_sqrt_pd(_mm512_xor_pd(x, _mm512_set1_pd(-0.0))); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f892(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_sqrt_pd(_mm512_andnot_pd(_mm512_set1_pd(-0.0), x)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f893(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_sqrt_pd(_mm512_sub_pd(_mm512_setzero_pd(), x)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f894(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_sqrt_pd(_mm512_mul_pd(x, _mm512_set1_pd(-1.0))); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f895(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_sqrt_pd(_mm512_roundscale_pd(x, 1 | _MM_FROUND_NO_EXC)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f896(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_sqrt_pd(_mm512_roundscale_pd(x, 2 | _MM_FROUND_NO_EXC)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f897(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_sqrt_pd(_mm512_roundscale_pd(x, 0 | _MM_FROUND_NO_EXC)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f898(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_xor_pd(_mm512_sqrt_pd(x), _mm512_set1_pd(-0.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f899(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_xor_pd(_mm512_xor_pd(x, _mm512_set1_pd(-0.0)), _mm512_set1_pd(-0.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f900(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_xor_pd(_mm512_andnot_pd(_mm512_set1_pd(-0.0), x), _mm512_set1_pd(-0.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f901(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_xor_pd(_mm512_sub_pd(_mm512_setzero_pd(), x), _mm512_set1_pd(-0.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f902(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_xor_pd(_mm512_mul_pd(x, _mm512_set1_pd(-1.0)), _mm512_set1_pd(-0.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f903(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_xor_pd(_mm512_roundscale_pd(x, 1 | _MM_FROUND_NO_EXC), _mm512_set1_pd(-0.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f904(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_xor_pd(_mm512_roundscale_pd(x, 2 | _MM_FROUND_NO_EXC), _mm512_set1_pd(-0.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f905(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_xor_pd(_mm512_roundscale_pd(x, 0 | _MM_FROUND_NO_EXC), _mm512_set1_pd(-0.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f906(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_andnot_pd(_mm512_set1_pd(-0.0), _mm512_sqrt_pd(x)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f907(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_andnot_pd(_mm512_set1_pd(-0.0), _mm512_xor_pd(x, _mm512_set1_pd(-0.0))); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f908(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_andnot_pd(_mm512_set1_pd(-0.0), _mm512_andnot_pd(_mm512_set1_pd(-0.0), x)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f909(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_andnot_pd(_mm512_set1_pd(-0.0), _mm512_sub_pd(_mm512_setzero_pd(), x)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f910(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_andnot_pd(_mm512_set1_pd(-0.0), _mm512_mul_pd(x, _mm512_set1_pd(-1.0))); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f911(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_andnot_pd(_mm512_set1_pd(-0.0), _mm512_roundscale_pd(x, 1 | _MM_FROUND_NO_EXC)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f912(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_andnot_pd(_mm512_set1_pd(-0.0), _mm512_roundscale_pd(x, 2 | _MM_FROUND_NO_EXC)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f913(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_andnot_pd(_mm512_set1_pd(-0.0), _mm512_roundscale_pd(x, 0 | _MM_FROUND_NO_EXC)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f914(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_sub_pd(_mm512_setzero_pd(), _mm512_sqrt_pd(x)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f915(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_sub_pd(_mm512_setzero_pd(), _mm512_xor_pd(x, _mm512_set1_pd(-0.0))); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f916(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_sub_pd(_mm512_setzero_pd(), _mm512_andnot_pd(_mm512_set1_pd(-0.0), x)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f917(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_sub_pd(_mm512_setzero_pd(), _mm512_sub_pd(_mm512_setzero_pd(), x)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f918(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_sub_pd(_mm512_setzero_pd(), _mm512_mul_pd(x, _mm512_set1_pd(-1.0))); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f919(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_sub_pd(_mm512_setzero_pd(), _mm512_roundscale_pd(x, 1 | _MM_FROUND_NO_EXC)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f920(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_sub_pd(_mm512_setzero_pd(), _mm512_roundscale_pd(x, 2 | _MM_FROUND_NO_EXC)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f921(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_sub_pd(_mm512_setzero_pd(), _mm512_roundscale_pd(x, 0 | _MM_FROUND_NO_EXC)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f922(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_mul_pd(_mm512_sqrt_pd(x), _mm512_set1_pd(-1.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f923(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_mul_pd(_mm512_xor_pd(x, _mm512_set1_pd(-0.0)), _mm512_set1_pd(-1.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f924(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_mul_pd(_mm512_andnot_pd(_mm512_set1_pd(-0.0), x), _mm512_set1_pd(-1.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f925(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_mul_pd(_mm512_sub_pd(_mm512_setzero_pd(), x), _mm512_set1_pd(-1.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f926(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_mul_pd(_mm512_mul_pd(x, _mm512_set1_pd(-1.0)), _mm512_set1_pd(-1.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f927(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_mul_pd(_mm512_roundscale_pd(x, 1 | _MM_FROUND_NO_EXC), _mm512_set1_pd(-1.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f928(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_mul_pd(_mm512_roundscale_pd(x, 2 | _MM_FROUND_NO_EXC), _mm512_set1_pd(-1.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f929(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_mul_pd(_mm512_roundscale_pd(x, 0 | _MM_FROUND_NO_EXC), _mm512_set1_pd(-1.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f930(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_roundscale_pd(_mm512_sqrt_pd(x), 1 | _MM_FROUND_NO_EXC); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f931(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_roundscale_pd(_mm512_xor_pd(x, _mm512_set1_pd(-0.0)), 1 | _MM_FROUND_NO_EXC); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f932(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_roundscale_pd(_mm512_andnot_pd(_mm512_set1_pd(-0.0), x), 1 | _MM_FROUND_NO_EXC); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f933(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_roundscale_pd(_mm512_sub_pd(_mm512_setzero_pd(), x), 1 | _MM_FROUND_NO_EXC); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f934(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_roundscale_pd(_mm512_mul_pd(x, _mm512_set1_pd(-1.0)), 1 | _MM_FROUND_NO_EXC); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f935(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_roundscale_pd(_mm512_roundscale_pd(x, 1 | _MM_FROUND_NO_EXC), 1 | _MM_FROUND_NO_EXC); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f936(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_roundscale_pd(_mm512_roundscale_pd(x, 2 | _MM_FROUND_NO_EXC), 1 | _MM_FROUND_NO_EXC); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f937(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_roundscale_pd(_mm512_roundscale_pd(x, 0 | _MM_FROUND_NO_EXC), 1 | _MM_FROUND_NO_EXC); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f938(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_roundscale_pd(_mm512_sqrt_pd(x), 2 | _MM_FROUND_NO_EXC); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f939(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_roundscale_pd(_mm512_xor_pd(x, _mm512_set1_pd(-0.0)), 2 | _MM_FROUND_NO_EXC); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f940(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_roundscale_pd(_mm512_andnot_pd(_mm512_set1_pd(-0.0), x), 2 | _MM_FROUND_NO_EXC); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f941(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_roundscale_pd(_mm512_sub_pd(_mm512_setzero_pd(), x), 2 | _MM_FROUND_NO_EXC); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f942(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_roundscale_pd(_mm512_mul_pd(x, _mm512_set1_pd(-1.0)), 2 | _MM_FROUND_NO_EXC); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f943(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_roundscale_pd(_mm512_roundscale_pd(x, 1 | _MM_FROUND_NO_EXC), 2 | _MM_FROUND_NO_EXC); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f944(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_roundscale_pd(_mm512_roundscale_pd(x, 2 | _MM_FROUND_NO_EXC), 2 | _MM_FROUND_NO_EXC); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f945(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_roundscale_pd(_mm512_roundscale_pd(x, 0 | _MM_FROUND_NO_EXC), 2 | _MM_FROUND_NO_EXC); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f946(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_roundscale_pd(_mm512_sqrt_pd(x), 0 | _MM_FROUND_NO_EXC); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f947(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_roundscale_pd(_mm512_xor_pd(x, _mm512_set1_pd(-0.0)), 0 | _MM_FROUND_NO_EXC); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f948(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_roundscale_pd(_mm512_andnot_pd(_mm512_set1_pd(-0.0), x), 0 | _MM_FROUND_NO_EXC); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f949(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_roundscale_pd(_mm512_sub_pd(_mm512_setzero_pd(), x), 0 | _MM_FROUND_NO_EXC); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f950(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_roundscale_pd(_mm512_mul_pd(x, _mm512_set1_pd(-1.0)), 0 | _MM_FROUND_NO_EXC); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f951(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_roundscale_pd(_mm512_roundscale_pd(x, 1 | _MM_FROUND_NO_EXC), 0 | _MM_FROUND_NO_EXC); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f952(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_roundscale_pd(_mm512_roundscale_pd(x, 2 | _MM_FROUND_NO_EXC), 0 | _MM_FROUND_NO_EXC); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f953(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_roundscale_pd(_mm512_roundscale_pd(x, 0 | _MM_FROUND_NO_EXC), 0 | _MM_FROUND_NO_EXC); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f954(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_sqrt_pd(_mm512_sqrt_pd(_mm512_sqrt_pd(x))); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f955(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_xor_pd(_mm512_xor_pd(_mm512_xor_pd(x, _mm512_set1_pd(-0.0)), _mm512_set1_pd(-0.0)), _mm512_set1_pd(-0.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f956(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_andnot_pd(_mm512_set1_pd(-0.0), _mm512_andnot_pd(_mm512_set1_pd(-0.0), _mm512_andnot_pd(_mm512_set1_pd(-0.0), x))); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f957(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_sub_pd(_mm512_setzero_pd(), _mm512_sub_pd(_mm512_setzero_pd(), _mm512_sub_pd(_mm512_setzero_pd(), x))); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f958(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_mul_pd(_mm512_mul_pd(_mm512_mul_pd(x, _mm512_set1_pd(-1.0)), _mm512_set1_pd(-1.0)), _mm512_set1_pd(-1.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f959(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_roundscale_pd(_mm512_roundscale_pd(_mm512_roundscale_pd(x, 1 | _MM_FROUND_NO_EXC), 1 | _MM_FROUND_NO_EXC), 1 | _MM_FROUND_NO_EXC); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f960(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_roundscale_pd(_mm512_roundscale_pd(_mm512_roundscale_pd(x, 2 | _MM_FROUND_NO_EXC), 2 | _MM_FROUND_NO_EXC), 2 | _MM_FROUND_NO_EXC); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f961(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_roundscale_pd(_mm512_roundscale_pd(_mm512_roundscale_pd(x, 0 | _MM_FROUND_NO_EXC), 0 | _MM_FROUND_NO_EXC), 0 | _MM_FROUND_NO_EXC); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f962(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_sqrt_pd(_mm512_add_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f963(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_add_pd(_mm512_sqrt_pd(x), y); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f964(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_add_pd(x, _mm512_sqrt_pd(y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f965(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_add_pd(_mm512_sqrt_pd(x), _mm512_sqrt_pd(y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f966(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_add_pd(x, _mm512_sqrt_pd(x)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f967(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_add_pd(_mm512_sqrt_pd(x), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f968(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_sqrt_pd(_mm512_sub_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f969(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_sub_pd(_mm512_sqrt_pd(x), y); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f970(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_sub_pd(x, _mm512_sqrt_pd(y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f971(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_sub_pd(_mm512_sqrt_pd(x), _mm512_sqrt_pd(y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f972(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_sub_pd(x, _mm512_sqrt_pd(x)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f973(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_sub_pd(_mm512_sqrt_pd(x), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f974(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_sqrt_pd(_mm512_mul_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f975(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_mul_pd(_mm512_sqrt_pd(x), y); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f976(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_mul_pd(x, _mm512_sqrt_pd(y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f977(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_mul_pd(_mm512_sqrt_pd(x), _mm512_sqrt_pd(y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f978(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_mul_pd(x, _mm512_sqrt_pd(x)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f979(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_mul_pd(_mm512_sqrt_pd(x), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f980(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_sqrt_pd(_mm512_div_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f981(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_div_pd(_mm512_sqrt_pd(x), y); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f982(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_div_pd(x, _mm512_sqrt_pd(y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f983(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_div_pd(_mm512_sqrt_pd(x), _mm512_sqrt_pd(y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f984(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_div_pd(x, _mm512_sqrt_pd(x)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f985(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_div_pd(_mm512_sqrt_pd(x), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f986(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_sqrt_pd(_mm512_min_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f987(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_min_pd(_mm512_sqrt_pd(x), y); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f988(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_min_pd(x, _mm512_sqrt_pd(y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f989(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_min_pd(_mm512_sqrt_pd(x), _mm512_sqrt_pd(y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f990(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_min_pd(x, _mm512_sqrt_pd(x)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f991(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_min_pd(_mm512_sqrt_pd(x), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f992(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_sqrt_pd(_mm512_max_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f993(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_max_pd(_mm512_sqrt_pd(x), y); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f994(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_max_pd(x, _mm512_sqrt_pd(y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f995(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_max_pd(_mm512_sqrt_pd(x), _mm512_sqrt_pd(y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f996(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_max_pd(x, _mm512_sqrt_pd(x)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f997(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_max_pd(_mm512_sqrt_pd(x), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f998(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_sqrt_pd(_mm512_and_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f999(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_and_pd(_mm512_sqrt_pd(x), y); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1000(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_and_pd(x, _mm512_sqrt_pd(y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1001(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_and_pd(_mm512_sqrt_pd(x), _mm512_sqrt_pd(y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1002(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_and_pd(x, _mm512_sqrt_pd(x)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1003(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_and_pd(_mm512_sqrt_pd(x), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1004(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_sqrt_pd(_mm512_or_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1005(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_or_pd(_mm512_sqrt_pd(x), y); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1006(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_or_pd(x, _mm512_sqrt_pd(y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1007(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_or_pd(_mm512_sqrt_pd(x), _mm512_sqrt_pd(y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1008(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_or_pd(x, _mm512_sqrt_pd(x)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1009(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_or_pd(_mm512_sqrt_pd(x), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1010(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_sqrt_pd(_mm512_xor_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1011(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_xor_pd(_mm512_sqrt_pd(x), y); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1012(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_xor_pd(x, _mm512_sqrt_pd(y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1013(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_xor_pd(_mm512_sqrt_pd(x), _mm512_sqrt_pd(y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1014(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_xor_pd(x, _mm512_sqrt_pd(x)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1015(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_xor_pd(_mm512_sqrt_pd(x), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1016(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_sqrt_pd(_mm512_andnot_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1017(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_andnot_pd(_mm512_sqrt_pd(x), y); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1018(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_andnot_pd(x, _mm512_sqrt_pd(y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1019(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_andnot_pd(_mm512_sqrt_pd(x), _mm512_sqrt_pd(y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1020(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_andnot_pd(x, _mm512_sqrt_pd(x)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1021(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_andnot_pd(_mm512_sqrt_pd(x), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1022(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_xor_pd(_mm512_add_pd(x, y), _mm512_set1_pd(-0.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1023(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_add_pd(_mm512_xor_pd(x, _mm512_set1_pd(-0.0)), y); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1024(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_add_pd(x, _mm512_xor_pd(y, _mm512_set1_pd(-0.0))); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1025(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_add_pd(_mm512_xor_pd(x, _mm512_set1_pd(-0.0)), _mm512_xor_pd(y, _mm512_set1_pd(-0.0))); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1026(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_add_pd(x, _mm512_xor_pd(x, _mm512_set1_pd(-0.0))); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1027(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_add_pd(_mm512_xor_pd(x, _mm512_set1_pd(-0.0)), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1028(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_xor_pd(_mm512_sub_pd(x, y), _mm512_set1_pd(-0.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1029(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_sub_pd(_mm512_xor_pd(x, _mm512_set1_pd(-0.0)), y); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1030(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_sub_pd(x, _mm512_xor_pd(y, _mm512_set1_pd(-0.0))); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1031(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_sub_pd(_mm512_xor_pd(x, _mm512_set1_pd(-0.0)), _mm512_xor_pd(y, _mm512_set1_pd(-0.0))); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1032(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_sub_pd(x, _mm512_xor_pd(x, _mm512_set1_pd(-0.0))); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1033(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_sub_pd(_mm512_xor_pd(x, _mm512_set1_pd(-0.0)), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1034(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_xor_pd(_mm512_mul_pd(x, y), _mm512_set1_pd(-0.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1035(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_mul_pd(_mm512_xor_pd(x, _mm512_set1_pd(-0.0)), y); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1036(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_mul_pd(x, _mm512_xor_pd(y, _mm512_set1_pd(-0.0))); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1037(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_mul_pd(_mm512_xor_pd(x, _mm512_set1_pd(-0.0)), _mm512_xor_pd(y, _mm512_set1_pd(-0.0))); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1038(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_mul_pd(x, _mm512_xor_pd(x, _mm512_set1_pd(-0.0))); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1039(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_mul_pd(_mm512_xor_pd(x, _mm512_set1_pd(-0.0)), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1040(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_xor_pd(_mm512_div_pd(x, y), _mm512_set1_pd(-0.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1041(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_div_pd(_mm512_xor_pd(x, _mm512_set1_pd(-0.0)), y); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1042(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_div_pd(x, _mm512_xor_pd(y, _mm512_set1_pd(-0.0))); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1043(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_div_pd(_mm512_xor_pd(x, _mm512_set1_pd(-0.0)), _mm512_xor_pd(y, _mm512_set1_pd(-0.0))); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1044(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_div_pd(x, _mm512_xor_pd(x, _mm512_set1_pd(-0.0))); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1045(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_div_pd(_mm512_xor_pd(x, _mm512_set1_pd(-0.0)), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1046(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_xor_pd(_mm512_min_pd(x, y), _mm512_set1_pd(-0.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1047(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_min_pd(_mm512_xor_pd(x, _mm512_set1_pd(-0.0)), y); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1048(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_min_pd(x, _mm512_xor_pd(y, _mm512_set1_pd(-0.0))); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1049(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_min_pd(_mm512_xor_pd(x, _mm512_set1_pd(-0.0)), _mm512_xor_pd(y, _mm512_set1_pd(-0.0))); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1050(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_min_pd(x, _mm512_xor_pd(x, _mm512_set1_pd(-0.0))); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1051(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_min_pd(_mm512_xor_pd(x, _mm512_set1_pd(-0.0)), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1052(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_xor_pd(_mm512_max_pd(x, y), _mm512_set1_pd(-0.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1053(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_max_pd(_mm512_xor_pd(x, _mm512_set1_pd(-0.0)), y); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1054(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_max_pd(x, _mm512_xor_pd(y, _mm512_set1_pd(-0.0))); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1055(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_max_pd(_mm512_xor_pd(x, _mm512_set1_pd(-0.0)), _mm512_xor_pd(y, _mm512_set1_pd(-0.0))); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1056(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_max_pd(x, _mm512_xor_pd(x, _mm512_set1_pd(-0.0))); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1057(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_max_pd(_mm512_xor_pd(x, _mm512_set1_pd(-0.0)), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1058(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_xor_pd(_mm512_and_pd(x, y), _mm512_set1_pd(-0.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1059(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_and_pd(_mm512_xor_pd(x, _mm512_set1_pd(-0.0)), y); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1060(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_and_pd(x, _mm512_xor_pd(y, _mm512_set1_pd(-0.0))); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1061(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_and_pd(_mm512_xor_pd(x, _mm512_set1_pd(-0.0)), _mm512_xor_pd(y, _mm512_set1_pd(-0.0))); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1062(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_and_pd(x, _mm512_xor_pd(x, _mm512_set1_pd(-0.0))); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1063(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_and_pd(_mm512_xor_pd(x, _mm512_set1_pd(-0.0)), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1064(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_xor_pd(_mm512_or_pd(x, y), _mm512_set1_pd(-0.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1065(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_or_pd(_mm512_xor_pd(x, _mm512_set1_pd(-0.0)), y); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1066(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_or_pd(x, _mm512_xor_pd(y, _mm512_set1_pd(-0.0))); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1067(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_or_pd(_mm512_xor_pd(x, _mm512_set1_pd(-0.0)), _mm512_xor_pd(y, _mm512_set1_pd(-0.0))); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1068(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_or_pd(x, _mm512_xor_pd(x, _mm512_set1_pd(-0.0))); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1069(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_or_pd(_mm512_xor_pd(x, _mm512_set1_pd(-0.0)), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1070(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_xor_pd(_mm512_xor_pd(x, y), _mm512_set1_pd(-0.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1071(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_xor_pd(_mm512_xor_pd(x, _mm512_set1_pd(-0.0)), y); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1072(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_xor_pd(x, _mm512_xor_pd(y, _mm512_set1_pd(-0.0))); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1073(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_xor_pd(_mm512_xor_pd(x, _mm512_set1_pd(-0.0)), _mm512_xor_pd(y, _mm512_set1_pd(-0.0))); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1074(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_xor_pd(x, _mm512_xor_pd(x, _mm512_set1_pd(-0.0))); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1075(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_xor_pd(_mm512_xor_pd(x, _mm512_set1_pd(-0.0)), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1076(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_xor_pd(_mm512_andnot_pd(x, y), _mm512_set1_pd(-0.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1077(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_andnot_pd(_mm512_xor_pd(x, _mm512_set1_pd(-0.0)), y); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1078(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_andnot_pd(x, _mm512_xor_pd(y, _mm512_set1_pd(-0.0))); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1079(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_andnot_pd(_mm512_xor_pd(x, _mm512_set1_pd(-0.0)), _mm512_xor_pd(y, _mm512_set1_pd(-0.0))); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1080(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_andnot_pd(x, _mm512_xor_pd(x, _mm512_set1_pd(-0.0))); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1081(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_andnot_pd(_mm512_xor_pd(x, _mm512_set1_pd(-0.0)), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1082(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_andnot_pd(_mm512_set1_pd(-0.0), _mm512_add_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1083(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_add_pd(_mm512_andnot_pd(_mm512_set1_pd(-0.0), x), y); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1084(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_add_pd(x, _mm512_andnot_pd(_mm512_set1_pd(-0.0), y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1085(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_add_pd(_mm512_andnot_pd(_mm512_set1_pd(-0.0), x), _mm512_andnot_pd(_mm512_set1_pd(-0.0), y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1086(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_add_pd(x, _mm512_andnot_pd(_mm512_set1_pd(-0.0), x)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1087(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_add_pd(_mm512_andnot_pd(_mm512_set1_pd(-0.0), x), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1088(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_andnot_pd(_mm512_set1_pd(-0.0), _mm512_sub_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1089(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_sub_pd(_mm512_andnot_pd(_mm512_set1_pd(-0.0), x), y); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1090(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_sub_pd(x, _mm512_andnot_pd(_mm512_set1_pd(-0.0), y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1091(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_sub_pd(_mm512_andnot_pd(_mm512_set1_pd(-0.0), x), _mm512_andnot_pd(_mm512_set1_pd(-0.0), y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1092(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_sub_pd(x, _mm512_andnot_pd(_mm512_set1_pd(-0.0), x)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1093(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_sub_pd(_mm512_andnot_pd(_mm512_set1_pd(-0.0), x), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1094(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_andnot_pd(_mm512_set1_pd(-0.0), _mm512_mul_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1095(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_mul_pd(_mm512_andnot_pd(_mm512_set1_pd(-0.0), x), y); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1096(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_mul_pd(x, _mm512_andnot_pd(_mm512_set1_pd(-0.0), y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1097(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_mul_pd(_mm512_andnot_pd(_mm512_set1_pd(-0.0), x), _mm512_andnot_pd(_mm512_set1_pd(-0.0), y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1098(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_mul_pd(x, _mm512_andnot_pd(_mm512_set1_pd(-0.0), x)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1099(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_mul_pd(_mm512_andnot_pd(_mm512_set1_pd(-0.0), x), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1100(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_andnot_pd(_mm512_set1_pd(-0.0), _mm512_div_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1101(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_div_pd(_mm512_andnot_pd(_mm512_set1_pd(-0.0), x), y); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1102(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_div_pd(x, _mm512_andnot_pd(_mm512_set1_pd(-0.0), y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1103(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_div_pd(_mm512_andnot_pd(_mm512_set1_pd(-0.0), x), _mm512_andnot_pd(_mm512_set1_pd(-0.0), y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1104(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_div_pd(x, _mm512_andnot_pd(_mm512_set1_pd(-0.0), x)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1105(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_div_pd(_mm512_andnot_pd(_mm512_set1_pd(-0.0), x), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1106(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_andnot_pd(_mm512_set1_pd(-0.0), _mm512_min_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1107(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_min_pd(_mm512_andnot_pd(_mm512_set1_pd(-0.0), x), y); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1108(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_min_pd(x, _mm512_andnot_pd(_mm512_set1_pd(-0.0), y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1109(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_min_pd(_mm512_andnot_pd(_mm512_set1_pd(-0.0), x), _mm512_andnot_pd(_mm512_set1_pd(-0.0), y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1110(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_min_pd(x, _mm512_andnot_pd(_mm512_set1_pd(-0.0), x)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1111(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_min_pd(_mm512_andnot_pd(_mm512_set1_pd(-0.0), x), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1112(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_andnot_pd(_mm512_set1_pd(-0.0), _mm512_max_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1113(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_max_pd(_mm512_andnot_pd(_mm512_set1_pd(-0.0), x), y); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1114(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_max_pd(x, _mm512_andnot_pd(_mm512_set1_pd(-0.0), y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1115(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_max_pd(_mm512_andnot_pd(_mm512_set1_pd(-0.0), x), _mm512_andnot_pd(_mm512_set1_pd(-0.0), y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1116(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_max_pd(x, _mm512_andnot_pd(_mm512_set1_pd(-0.0), x)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1117(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_max_pd(_mm512_andnot_pd(_mm512_set1_pd(-0.0), x), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1118(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_andnot_pd(_mm512_set1_pd(-0.0), _mm512_and_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1119(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_and_pd(_mm512_andnot_pd(_mm512_set1_pd(-0.0), x), y); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1120(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_and_pd(x, _mm512_andnot_pd(_mm512_set1_pd(-0.0), y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1121(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_and_pd(_mm512_andnot_pd(_mm512_set1_pd(-0.0), x), _mm512_andnot_pd(_mm512_set1_pd(-0.0), y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1122(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_and_pd(x, _mm512_andnot_pd(_mm512_set1_pd(-0.0), x)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1123(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_and_pd(_mm512_andnot_pd(_mm512_set1_pd(-0.0), x), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1124(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_andnot_pd(_mm512_set1_pd(-0.0), _mm512_or_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1125(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_or_pd(_mm512_andnot_pd(_mm512_set1_pd(-0.0), x), y); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1126(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_or_pd(x, _mm512_andnot_pd(_mm512_set1_pd(-0.0), y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1127(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_or_pd(_mm512_andnot_pd(_mm512_set1_pd(-0.0), x), _mm512_andnot_pd(_mm512_set1_pd(-0.0), y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1128(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_or_pd(x, _mm512_andnot_pd(_mm512_set1_pd(-0.0), x)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1129(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_or_pd(_mm512_andnot_pd(_mm512_set1_pd(-0.0), x), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1130(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_andnot_pd(_mm512_set1_pd(-0.0), _mm512_xor_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1131(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_xor_pd(_mm512_andnot_pd(_mm512_set1_pd(-0.0), x), y); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1132(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_xor_pd(x, _mm512_andnot_pd(_mm512_set1_pd(-0.0), y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1133(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_xor_pd(_mm512_andnot_pd(_mm512_set1_pd(-0.0), x), _mm512_andnot_pd(_mm512_set1_pd(-0.0), y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1134(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_xor_pd(x, _mm512_andnot_pd(_mm512_set1_pd(-0.0), x)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1135(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_xor_pd(_mm512_andnot_pd(_mm512_set1_pd(-0.0), x), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1136(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_andnot_pd(_mm512_set1_pd(-0.0), _mm512_andnot_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1137(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_andnot_pd(_mm512_andnot_pd(_mm512_set1_pd(-0.0), x), y); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1138(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_andnot_pd(x, _mm512_andnot_pd(_mm512_set1_pd(-0.0), y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1139(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_andnot_pd(_mm512_andnot_pd(_mm512_set1_pd(-0.0), x), _mm512_andnot_pd(_mm512_set1_pd(-0.0), y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1140(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_andnot_pd(x, _mm512_andnot_pd(_mm512_set1_pd(-0.0), x)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1141(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_andnot_pd(_mm512_andnot_pd(_mm512_set1_pd(-0.0), x), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1142(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_sub_pd(_mm512_setzero_pd(), _mm512_add_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1143(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_add_pd(_mm512_sub_pd(_mm512_setzero_pd(), x), y); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1144(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_add_pd(x, _mm512_sub_pd(_mm512_setzero_pd(), y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1145(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_add_pd(_mm512_sub_pd(_mm512_setzero_pd(), x), _mm512_sub_pd(_mm512_setzero_pd(), y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1146(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_add_pd(x, _mm512_sub_pd(_mm512_setzero_pd(), x)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1147(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_add_pd(_mm512_sub_pd(_mm512_setzero_pd(), x), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1148(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_sub_pd(_mm512_setzero_pd(), _mm512_sub_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1149(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_sub_pd(_mm512_sub_pd(_mm512_setzero_pd(), x), y); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1150(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_sub_pd(x, _mm512_sub_pd(_mm512_setzero_pd(), y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1151(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_sub_pd(_mm512_sub_pd(_mm512_setzero_pd(), x), _mm512_sub_pd(_mm512_setzero_pd(), y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1152(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_sub_pd(x, _mm512_sub_pd(_mm512_setzero_pd(), x)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1153(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_sub_pd(_mm512_sub_pd(_mm512_setzero_pd(), x), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1154(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_sub_pd(_mm512_setzero_pd(), _mm512_mul_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1155(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_mul_pd(_mm512_sub_pd(_mm512_setzero_pd(), x), y); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1156(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_mul_pd(x, _mm512_sub_pd(_mm512_setzero_pd(), y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1157(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_mul_pd(_mm512_sub_pd(_mm512_setzero_pd(), x), _mm512_sub_pd(_mm512_setzero_pd(), y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1158(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_mul_pd(x, _mm512_sub_pd(_mm512_setzero_pd(), x)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1159(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_mul_pd(_mm512_sub_pd(_mm512_setzero_pd(), x), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1160(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_sub_pd(_mm512_setzero_pd(), _mm512_div_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1161(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_div_pd(_mm512_sub_pd(_mm512_setzero_pd(), x), y); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1162(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_div_pd(x, _mm512_sub_pd(_mm512_setzero_pd(), y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1163(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_div_pd(_mm512_sub_pd(_mm512_setzero_pd(), x), _mm512_sub_pd(_mm512_setzero_pd(), y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1164(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_div_pd(x, _mm512_sub_pd(_mm512_setzero_pd(), x)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1165(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_div_pd(_mm512_sub_pd(_mm512_setzero_pd(), x), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1166(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_sub_pd(_mm512_setzero_pd(), _mm512_min_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1167(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_min_pd(_mm512_sub_pd(_mm512_setzero_pd(), x), y); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1168(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_min_pd(x, _mm512_sub_pd(_mm512_setzero_pd(), y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1169(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_min_pd(_mm512_sub_pd(_mm512_setzero_pd(), x), _mm512_sub_pd(_mm512_setzero_pd(), y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1170(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_min_pd(x, _mm512_sub_pd(_mm512_setzero_pd(), x)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1171(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_min_pd(_mm512_sub_pd(_mm512_setzero_pd(), x), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1172(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_sub_pd(_mm512_setzero_pd(), _mm512_max_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1173(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_max_pd(_mm512_sub_pd(_mm512_setzero_pd(), x), y); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1174(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_max_pd(x, _mm512_sub_pd(_mm512_setzero_pd(), y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1175(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_max_pd(_mm512_sub_pd(_mm512_setzero_pd(), x), _mm512_sub_pd(_mm512_setzero_pd(), y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1176(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_max_pd(x, _mm512_sub_pd(_mm512_setzero_pd(), x)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1177(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_max_pd(_mm512_sub_pd(_mm512_setzero_pd(), x), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1178(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_sub_pd(_mm512_setzero_pd(), _mm512_and_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1179(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_and_pd(_mm512_sub_pd(_mm512_setzero_pd(), x), y); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1180(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_and_pd(x, _mm512_sub_pd(_mm512_setzero_pd(), y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1181(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_and_pd(_mm512_sub_pd(_mm512_setzero_pd(), x), _mm512_sub_pd(_mm512_setzero_pd(), y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1182(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_and_pd(x, _mm512_sub_pd(_mm512_setzero_pd(), x)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1183(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_and_pd(_mm512_sub_pd(_mm512_setzero_pd(), x), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1184(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_sub_pd(_mm512_setzero_pd(), _mm512_or_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1185(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_or_pd(_mm512_sub_pd(_mm512_setzero_pd(), x), y); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1186(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_or_pd(x, _mm512_sub_pd(_mm512_setzero_pd(), y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1187(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_or_pd(_mm512_sub_pd(_mm512_setzero_pd(), x), _mm512_sub_pd(_mm512_setzero_pd(), y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1188(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_or_pd(x, _mm512_sub_pd(_mm512_setzero_pd(), x)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1189(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_or_pd(_mm512_sub_pd(_mm512_setzero_pd(), x), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1190(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_sub_pd(_mm512_setzero_pd(), _mm512_xor_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1191(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_xor_pd(_mm512_sub_pd(_mm512_setzero_pd(), x), y); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1192(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_xor_pd(x, _mm512_sub_pd(_mm512_setzero_pd(), y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1193(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_xor_pd(_mm512_sub_pd(_mm512_setzero_pd(), x), _mm512_sub_pd(_mm512_setzero_pd(), y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1194(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_xor_pd(x, _mm512_sub_pd(_mm512_setzero_pd(), x)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1195(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_xor_pd(_mm512_sub_pd(_mm512_setzero_pd(), x), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1196(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_sub_pd(_mm512_setzero_pd(), _mm512_andnot_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1197(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_andnot_pd(_mm512_sub_pd(_mm512_setzero_pd(), x), y); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1198(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_andnot_pd(x, _mm512_sub_pd(_mm512_setzero_pd(), y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1199(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_andnot_pd(_mm512_sub_pd(_mm512_setzero_pd(), x), _mm512_sub_pd(_mm512_setzero_pd(), y)); _mm512_storeu_pd((double*)po, r); }
extern const Entry table_94[] = {
  {"512:_mm512_andnot_ps(x, _mm512_roundscale_ps(x, 0 | _MM_FROUND_NO_EXC))", f0, 1, 512},
  {"512:_mm512_andnot_ps(_mm512_roundscale_ps(x, 0 | _MM_FROUND_NO_EXC), x)", f1, 1, 512},
  {"512:_mm512_add_ps(x, x)", f2, 1, 512},
  {"512:_mm512_add_ps(x, _mm512_setzero_ps())", f3, 1, 512},
  {"512:_mm512_add_ps(_mm512_setzero_ps(), x)", f4, 1, 512},
  {"512:_mm512_add_ps(x, _mm512_set1_ps(-0.0f))", f5, 1, 512},
  {"512:_mm512_add_ps(_mm512_set1_ps(-0.0f), x)", f6, 1, 512},
  {"512:_mm512_add_ps(x, _mm512_set1_ps(1.0f))", f7, 1, 512},
  {"512:_mm512_add_ps(_mm512_set1_ps(1.0f), x)", f8, 1, 512},
  {"512:_mm512_add_ps(x, _mm512_set1_ps(-1.0f))", f9, 1, 512},
  {"512:_mm512_add_ps(_mm512_set1_ps(-1.0f), x)", f10, 1, 512},
  {"512:_mm512_add_ps(x, _mm512_set1_ps(std::numeric_limits<float>::infinity()))", f11, 1, 512},
  {"512:_mm512_add_ps(_mm512_set1_ps(std::numeric_limits<float>::infinity()), x)", f12, 1, 512},
  {"512:_mm512_add_ps(x, _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN()))", f13, 1, 512},
  {"512:_mm512_add_ps(_mm512_set1_ps(std::numeric_limits<float>::quiet_NaN()), x)", f14, 1, 512},
  {"512:_mm512_add_ps(_mm512_add_ps(x, _mm512_setzero_ps()), _mm512_setzero_ps())", f15, 1, 512},
  {"512:_mm512_add_ps(_mm512_add_ps(x, _mm512_setzero_ps()), _mm512_set1_ps(-0.0f))", f16, 1, 512},
  {"512:_mm512_add_ps(_mm512_add_ps(x, _mm512_setzero_ps()), _mm512_set1_ps(1.0f))", f17, 1, 512},
  {"512:_mm512_add_ps(_mm512_add_ps(x, _mm512_setzero_ps()), _mm512_set1_ps(-1.0f))", f18, 1, 512},
  {"512:_mm512_add_ps(_mm512_add_ps(x, _mm512_setzero_ps()), _mm512_set1_ps(std::numeric_limits<float>::infinity()))", f19, 1, 512},
  {"512:_mm512_add_ps(_mm512_add_ps(x, _mm512_setzero_ps()), _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN()))", f20, 1, 512},
  {"512:_mm512_add_ps(_mm512_add_ps(x, _mm512_set1_ps(-0.0f)), _mm512_setzero_ps())", f21, 1, 512},
  {"512:_mm512_add_ps(_mm512_add_ps(x, _mm512_set1_ps(-0.0f)), _mm512_set1_ps(-0.0f))", f22, 1, 512},
  {"512:_mm512_add_ps(_mm512_add_ps(x, _mm512_set1_ps(-0.0f)), _mm512_set1_ps(1.0f))", f23, 1, 512},
  {"512:_mm512_add_ps(_mm512_add_ps(x, _mm512_set1_ps(-0.0f)), _mm512_set1_ps(-1.0f))", f24, 1, 512},
  {"512:_mm512_add_ps(_mm512_add_ps(x, _mm512_set1_ps(-0.0f)), _mm512_set1_ps(std::numeric_limits<float>::infinity()))", f25, 1, 512},
  {"512:_mm512_add_ps(_mm512_add_ps(x, _mm512_set1_ps(-0.0f)), _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN()))", f26, 1, 512},
  {"512:_mm512_add_ps(_mm512_add_ps(x, _mm512_set1_ps(1.0f)), _mm512_setzero_ps())", f27, 1, 512},
  {"512:_mm512_add_ps(_mm512_add_ps(x, _mm512_set1_ps(1.0f)), _mm512_set1_ps(-0.0f))", f28, 1, 512},
  {"512:_mm512_add_ps(_mm512_add_ps(x, _mm512_set1_ps(1.0f)), _mm512_set1_ps(1.0f))", f29, 1, 512},
  {"512:_mm512_add_ps(_mm512_add_ps(x, _mm512_set1_ps(1.0f)), _mm512_set1_ps(-1.0f))", f30, 1, 512},
  {"512:_mm512_add_ps(_mm512_add_ps(x, _mm512_set1_ps(1.0f)), _mm512_set1_ps(std::numeric_limits<float>::infinity()))", f31, 1, 512},
  {"512:_mm512_add_ps(_mm512_add_ps(x, _mm512_set1_ps(1.0f)), _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN()))", f32, 1, 512},
  {"512:_mm512_add_ps(_mm512_add_ps(x, _mm512_set1_ps(-1.0f)), _mm512_setzero_ps())", f33, 1, 512},
  {"512:_mm512_add_ps(_mm512_add_ps(x, _mm512_set1_ps(-1.0f)), _mm512_set1_ps(-0.0f))", f34, 1, 512},
  {"512:_mm512_add_ps(_mm512_add_ps(x, _mm512_set1_ps(-1.0f)), _mm512_set1_ps(1.0f))", f35, 1, 512},
  {"512:_mm512_add_ps(_mm512_add_ps(x, _mm512_set1_ps(-1.0f)), _mm512_set1_ps(-1.0f))", f36, 1, 512},
  {"512:_mm512_add_ps(_mm512_add_ps(x, _mm512_set1_ps(-1.0f)), _mm512_set1_ps(std::numeric_limits<float>::infinity()))", f37, 1, 512},
  {"512:_mm512_add_ps(_mm512_add_ps(x, _mm512_set1_ps(-1.0f)), _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN()))", f38, 1, 512},
  {"512:_mm512_add_ps(_mm512_add_ps(x, _mm512_set1_ps(std::numeric_limits<float>::infinity())), _mm512_setzero_ps())", f39, 1, 512},
  {"512:_mm512_add_ps(_mm512_add_ps(x, _mm512_set1_ps(std::numeric_limits<float>::infinity())), _mm512_set1_ps(-0.0f))", f40, 1, 512},
  {"512:_mm512_add_ps(_mm512_add_ps(x, _mm512_set1_ps(std::numeric_limits<float>::infinity())), _mm512_set1_ps(1.0f))", f41, 1, 512},
  {"512:_mm512_add_ps(_mm512_add_ps(x, _mm512_set1_ps(std::numeric_limits<float>::infinity())), _mm512_set1_ps(-1.0f))", f42, 1, 512},
  {"512:_mm512_add_ps(_mm512_add_ps(x, _mm512_set1_ps(std::numeric_limits<float>::infinity())), _mm512_set1_ps(std::numeric_limits<float>::infinity()))", f43, 1, 512},
  {"512:_mm512_add_ps(_mm512_add_ps(x, _mm512_set1_ps(std::numeric_limits<float>::infinity())), _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN()))", f44, 1, 512},
  {"512:_mm512_add_ps(_mm512_add_ps(x, _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN())), _mm512_setzero_ps())", f45, 1, 512},
  {"512:_mm512_add_ps(_mm512_add_ps(x, _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN())), _mm512_set1_ps(-0.0f))", f46, 1, 512},
  {"512:_mm512_add_ps(_mm512_add_ps(x, _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN())), _mm512_set1_ps(1.0f))", f47, 1, 512},
  {"512:_mm512_add_ps(_mm512_add_ps(x, _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN())), _mm512_set1_ps(-1.0f))", f48, 1, 512},
  {"512:_mm512_add_ps(_mm512_add_ps(x, _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN())), _mm512_set1_ps(std::numeric_limits<float>::infinity()))", f49, 1, 512},
  {"512:_mm512_add_ps(_mm512_add_ps(x, _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN())), _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN()))", f50, 1, 512},
  {"512:_mm512_sub_ps(x, x)", f51, 1, 512},
  {"512:_mm512_sub_ps(x, _mm512_setzero_ps())", f52, 1, 512},
  {"512:_mm512_sub_ps(_mm512_setzero_ps(), x)", f53, 1, 512},
  {"512:_mm512_sub_ps(x, _mm512_set1_ps(-0.0f))", f54, 1, 512},
  {"512:_mm512_sub_ps(_mm512_set1_ps(-0.0f), x)", f55, 1, 512},
  {"512:_mm512_sub_ps(x, _mm512_set1_ps(1.0f))", f56, 1, 512},
  {"512:_mm512_sub_ps(_mm512_set1_ps(1.0f), x)", f57, 1, 512},
  {"512:_mm512_sub_ps(x, _mm512_set1_ps(-1.0f))", f58, 1, 512},
  {"512:_mm512_sub_ps(_mm512_set1_ps(-1.0f), x)", f59, 1, 512},
  {"512:_mm512_sub_ps(x, _mm512_set1_ps(std::numeric_limits<float>::infinity()))", f60, 1, 512},
  {"512:_mm512_sub_ps(_mm512_set1_ps(std::numeric_limits<float>::infinity()), x)", f61, 1, 512},
  {"512:_mm512_sub_ps(x, _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN()))", f62, 1, 512},
  {"512:_mm512_sub_ps(_mm512_set1_ps(std::numeric_limits<float>::quiet_NaN()), x)", f63, 1, 512},
  {"512:_mm512_sub_ps(_mm512_sub_ps(x, _mm512_setzero_ps()), _mm512_setzero_ps())", f64, 1, 512},
  {"512:_mm512_sub_ps(_mm512_sub_ps(x, _mm512_setzero_ps()), _mm512_set1_ps(-0.0f))", f65, 1, 512},
  {"512:_mm512_sub_ps(_mm512_sub_ps(x, _mm512_setzero_ps()), _mm512_set1_ps(1.0f))", f66, 1, 512},
  {"512:_mm512_sub_ps(_mm512_sub_ps(x, _mm512_setzero_ps()), _mm512_set1_ps(-1.0f))", f67, 1, 512},
  {"512:_mm512_sub_ps(_mm512_sub_ps(x, _mm512_setzero_ps()), _mm512_set1_ps(std::numeric_limits<float>::infinity()))", f68, 1, 512},
  {"512:_mm512_sub_ps(_mm512_sub_ps(x, _mm512_setzero_ps()), _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN()))", f69, 1, 512},
  {"512:_mm512_sub_ps(_mm512_sub_ps(x, _mm512_set1_ps(-0.0f)), _mm512_setzero_ps())", f70, 1, 512},
  {"512:_mm512_sub_ps(_mm512_sub_ps(x, _mm512_set1_ps(-0.0f)), _mm512_set1_ps(-0.0f))", f71, 1, 512},
  {"512:_mm512_sub_ps(_mm512_sub_ps(x, _mm512_set1_ps(-0.0f)), _mm512_set1_ps(1.0f))", f72, 1, 512},
  {"512:_mm512_sub_ps(_mm512_sub_ps(x, _mm512_set1_ps(-0.0f)), _mm512_set1_ps(-1.0f))", f73, 1, 512},
  {"512:_mm512_sub_ps(_mm512_sub_ps(x, _mm512_set1_ps(-0.0f)), _mm512_set1_ps(std::numeric_limits<float>::infinity()))", f74, 1, 512},
  {"512:_mm512_sub_ps(_mm512_sub_ps(x, _mm512_set1_ps(-0.0f)), _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN()))", f75, 1, 512},
  {"512:_mm512_sub_ps(_mm512_sub_ps(x, _mm512_set1_ps(1.0f)), _mm512_setzero_ps())", f76, 1, 512},
  {"512:_mm512_sub_ps(_mm512_sub_ps(x, _mm512_set1_ps(1.0f)), _mm512_set1_ps(-0.0f))", f77, 1, 512},
  {"512:_mm512_sub_ps(_mm512_sub_ps(x, _mm512_set1_ps(1.0f)), _mm512_set1_ps(1.0f))", f78, 1, 512},
  {"512:_mm512_sub_ps(_mm512_sub_ps(x, _mm512_set1_ps(1.0f)), _mm512_set1_ps(-1.0f))", f79, 1, 512},
  {"512:_mm512_sub_ps(_mm512_sub_ps(x, _mm512_set1_ps(1.0f)), _mm512_set1_ps(std::numeric_limits<float>::infinity()))", f80, 1, 512},
  {"512:_mm512_sub_ps(_mm512_sub_ps(x, _mm512_set1_ps(1.0f)), _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN()))", f81, 1, 512},
  {"512:_mm512_sub_ps(_mm512_sub_ps(x, _mm512_set1_ps(-1.0f)), _mm512_setzero_ps())", f82, 1, 512},
  {"512:_mm512_sub_ps(_mm512_sub_ps(x, _mm512_set1_ps(-1.0f)), _mm512_set1_ps(-0.0f))", f83, 1, 512},
  {"512:_mm512_sub_ps(_mm512_sub_ps(x, _mm512_set1_ps(-1.0f)), _mm512_set1_ps(1.0f))", f84, 1, 512},
  {"512:_mm512_sub_ps(_mm512_sub_ps(x, _mm512_set1_ps(-1.0f)), _mm512_set1_ps(-1.0f))", f85, 1, 512},
  {"512:_mm512_sub_ps(_mm512_sub_ps(x, _mm512_set1_ps(-1.0f)), _mm512_set1_ps(std::numeric_limits<float>::infinity()))", f86, 1, 512},
  {"512:_mm512_sub_ps(_mm512_sub_ps(x, _mm512_set1_ps(-1.0f)), _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN()))", f87, 1, 512},
  {"512:_mm512_sub_ps(_mm512_sub_ps(x, _mm512_set1_ps(std::numeric_limits<float>::infinity())), _mm512_setzero_ps())", f88, 1, 512},
  {"512:_mm512_sub_ps(_mm512_sub_ps(x, _mm512_set1_ps(std::numeric_limits<float>::infinity())), _mm512_set1_ps(-0.0f))", f89, 1, 512},
  {"512:_mm512_sub_ps(_mm512_sub_ps(x, _mm512_set1_ps(std::numeric_limits<float>::infinity())), _mm512_set1_ps(1.0f))", f90, 1, 512},
  {"512:_mm512_sub_ps(_mm512_sub_ps(x, _mm512_set1_ps(std::numeric_limits<float>::infinity())), _mm512_set1_ps(-1.0f))", f91, 1, 512},
  {"512:_mm512_sub_ps(_mm512_sub_ps(x, _mm512_set1_ps(std::numeric_limits<float>::infinity())), _mm512_set1_ps(std::numeric_limits<float>::infinity()))", f92, 1, 512},
  {"512:_mm512_sub_ps(_mm512_sub_ps(x, _mm512_set1_ps(std::numeric_limits<float>::infinity())), _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN()))", f93, 1, 512},
  {"512:_mm512_sub_ps(_mm512_sub_ps(x, _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN())), _mm512_setzero_ps())", f94, 1, 512},
  {"512:_mm512_sub_ps(_mm512_sub_ps(x, _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN())), _mm512_set1_ps(-0.0f))", f95, 1, 512},
  {"512:_mm512_sub_ps(_mm512_sub_ps(x, _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN())), _mm512_set1_ps(1.0f))", f96, 1, 512},
  {"512:_mm512_sub_ps(_mm512_sub_ps(x, _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN())), _mm512_set1_ps(-1.0f))", f97, 1, 512},
  {"512:_mm512_sub_ps(_mm512_sub_ps(x, _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN())), _mm512_set1_ps(std::numeric_limits<float>::infinity()))", f98, 1, 512},
  {"512:_mm512_sub_ps(_mm512_sub_ps(x, _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN())), _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN()))", f99, 1, 512},
  {"512:_mm512_mul_ps(x, x)", f100, 1, 512},
  {"512:_mm512_mul_ps(x, _mm512_setzero_ps())", f101, 1, 512},
  {"512:_mm512_mul_ps(_mm512_setzero_ps(), x)", f102, 1, 512},
  {"512:_mm512_mul_ps(x, _mm512_set1_ps(-0.0f))", f103, 1, 512},
  {"512:_mm512_mul_ps(_mm512_set1_ps(-0.0f), x)", f104, 1, 512},
  {"512:_mm512_mul_ps(x, _mm512_set1_ps(1.0f))", f105, 1, 512},
  {"512:_mm512_mul_ps(_mm512_set1_ps(1.0f), x)", f106, 1, 512},
  {"512:_mm512_mul_ps(x, _mm512_set1_ps(-1.0f))", f107, 1, 512},
  {"512:_mm512_mul_ps(_mm512_set1_ps(-1.0f), x)", f108, 1, 512},
  {"512:_mm512_mul_ps(x, _mm512_set1_ps(std::numeric_limits<float>::infinity()))", f109, 1, 512},
  {"512:_mm512_mul_ps(_mm512_set1_ps(std::numeric_limits<float>::infinity()), x)", f110, 1, 512},
  {"512:_mm512_mul_ps(x, _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN()))", f111, 1, 512},
  {"512:_mm512_mul_ps(_mm512_set1_ps(std::numeric_limits<float>::quiet_NaN()), x)", f112, 1, 512},
  {"512:_mm512_mul_ps(_mm512_mul_ps(x, _mm512_setzero_ps()), _mm512_setzero_ps())", f113, 1, 512},
  {"512:_mm512_mul_ps(_mm512_mul_ps(x, _mm512_setzero_ps()), _mm512_set1_ps(-0.0f))", f114, 1, 512},
  {"512:_mm512_mul_ps(_mm512_mul_ps(x, _mm512_setzero_ps()), _mm512_set1_ps(1.0f))", f115, 1, 512},
  {"512:_mm512_mul_ps(_mm512_mul_ps(x, _mm512_setzero_ps()), _mm512_set1_ps(-1.0f))", f116, 1, 512},
  {"512:_mm512_mul_ps(_mm512_mul_ps(x, _mm512_setzero_ps()), _mm512_set1_ps(std::numeric_limits<float>::infinity()))", f117, 1, 512},
  {"512:_mm512_mul_ps(_mm512_mul_ps(x, _mm512_setzero_ps()), _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN()))", f118, 1, 512},
  {"512:_mm512_mul_ps(_mm512_mul_ps(x, _mm512_set1_ps(-0.0f)), _mm512_setzero_ps())", f119, 1, 512},
  {"512:_mm512_mul_ps(_mm512_mul_ps(x, _mm512_set1_ps(-0.0f)), _mm512_set1_ps(-0.0f))", f120, 1, 512},
  {"512:_mm512_mul_ps(_mm512_mul_ps(x, _mm512_set1_ps(-0.0f)), _mm512_set1_ps(1.0f))", f121, 1, 512},
  {"512:_mm512_mul_ps(_mm512_mul_ps(x, _mm512_set1_ps(-0.0f)), _mm512_set1_ps(-1.0f))", f122, 1, 512},
  {"512:_mm512_mul_ps(_mm512_mul_ps(x, _mm512_set1_ps(-0.0f)), _mm512_set1_ps(std::numeric_limits<float>::infinity()))", f123, 1, 512},
  {"512:_mm512_mul_ps(_mm512_mul_ps(x, _mm512_set1_ps(-0.0f)), _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN()))", f124, 1, 512},
  {"512:_mm512_mul_ps(_mm512_mul_ps(x, _mm512_set1_ps(1.0f)), _mm512_setzero_ps())", f125, 1, 512},
  {"512:_mm512_mul_ps(_mm512_mul_ps(x, _mm512_set1_ps(1.0f)), _mm512_set1_ps(-0.0f))", f126, 1, 512},
  {"512:_mm512_mul_ps(_mm512_mul_ps(x, _mm512_set1_ps(1.0f)), _mm512_set1_ps(1.0f))", f127, 1, 512},
  {"512:_mm512_mul_ps(_mm512_mul_ps(x, _mm512_set1_ps(1.0f)), _mm512_set1_ps(-1.0f))", f128, 1, 512},
  {"512:_mm512_mul_ps(_mm512_mul_ps(x, _mm512_set1_ps(1.0f)), _mm512_set1_ps(std::numeric_limits<float>::infinity()))", f129, 1, 512},
  {"512:_mm512_mul_ps(_mm512_mul_ps(x, _mm512_set1_ps(1.0f)), _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN()))", f130, 1, 512},
  {"512:_mm512_mul_ps(_mm512_mul_ps(x, _mm512_set1_ps(-1.0f)), _mm512_setzero_ps())", f131, 1, 512},
  {"512:_mm512_mul_ps(_mm512_mul_ps(x, _mm512_set1_ps(-1.0f)), _mm512_set1_ps(-0.0f))", f132, 1, 512},
  {"512:_mm512_mul_ps(_mm512_mul_ps(x, _mm512_set1_ps(-1.0f)), _mm512_set1_ps(1.0f))", f133, 1, 512},
  {"512:_mm512_mul_ps(_mm512_mul_ps(x, _mm512_set1_ps(-1.0f)), _mm512_set1_ps(std::numeric_limits<float>::infinity()))", f134, 1, 512},
  {"512:_mm512_mul_ps(_mm512_mul_ps(x, _mm512_set1_ps(-1.0f)), _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN()))", f135, 1, 512},
  {"512:_mm512_mul_ps(_mm512_mul_ps(x, _mm512_set1_ps(std::numeric_limits<float>::infinity())), _mm512_setzero_ps())", f136, 1, 512},
  {"512:_mm512_mul_ps(_mm512_mul_ps(x, _mm512_set1_ps(std::numeric_limits<float>::infinity())), _mm512_set1_ps(-0.0f))", f137, 1, 512},
  {"512:_mm512_mul_ps(_mm512_mul_ps(x, _mm512_set1_ps(std::numeric_limits<float>::infinity())), _mm512_set1_ps(1.0f))", f138, 1, 512},
  {"512:_mm512_mul_ps(_mm512_mul_ps(x, _mm512_set1_ps(std::numeric_limits<float>::infinity())), _mm512_set1_ps(-1.0f))", f139, 1, 512},
  {"512:_mm512_mul_ps(_mm512_mul_ps(x, _mm512_set1_ps(std::numeric_limits<float>::infinity())), _mm512_set1_ps(std::numeric_limits<float>::infinity()))", f140, 1, 512},
  {"512:_mm512_mul_ps(_mm512_mul_ps(x, _mm512_set1_ps(std::numeric_limits<float>::infinity())), _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN()))", f141, 1, 512},
  {"512:_mm512_mul_ps(_mm512_mul_ps(x, _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN())), _mm512_setzero_ps())", f142, 1, 512},
  {"512:_mm512_mul_ps(_mm512_mul_ps(x, _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN())), _mm512_set1_ps(-0.0f))", f143, 1, 512},
  {"512:_mm512_mul_ps(_mm512_mul_ps(x, _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN())), _mm512_set1_ps(1.0f))", f144, 1, 512},
  {"512:_mm512_mul_ps(_mm512_mul_ps(x, _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN())), _mm512_set1_ps(-1.0f))", f145, 1, 512},
  {"512:_mm512_mul_ps(_mm512_mul_ps(x, _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN())), _mm512_set1_ps(std::numeric_limits<float>::infinity()))", f146, 1, 512},
  {"512:_mm512_mul_ps(_mm512_mul_ps(x, _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN())), _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN()))", f147, 1, 512},
  {"512:_mm512_div_ps(x, x)", f148, 1, 512},
  {"512:_mm512_div_ps(x, _mm512_setzero_ps())", f149, 1, 512},
  {"512:_mm512_div_ps(_mm512_setzero_ps(), x)", f150, 1, 512},
  {"512:_mm512_div_ps(x, _mm512_set1_ps(-0.0f))", f151, 1, 512},
  {"512:_mm512_div_ps(_mm512_set1_ps(-0.0f), x)", f152, 1, 512},
  {"512:_mm512_div_ps(x, _mm512_set1_ps(1.0f))", f153, 1, 512},
  {"512:_mm512_div_ps(_mm512_set1_ps(1.0f), x)", f154, 1, 512},
  {"512:_mm512_div_ps(x, _mm512_set1_ps(-1.0f))", f155, 1, 512},
  {"512:_mm512_div_ps(_mm512_set1_ps(-1.0f), x)", f156, 1, 512},
  {"512:_mm512_div_ps(x, _mm512_set1_ps(std::numeric_limits<float>::infinity()))", f157, 1, 512},
  {"512:_mm512_div_ps(_mm512_set1_ps(std::numeric_limits<float>::infinity()), x)", f158, 1, 512},
  {"512:_mm512_div_ps(x, _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN()))", f159, 1, 512},
  {"512:_mm512_div_ps(_mm512_set1_ps(std::numeric_limits<float>::quiet_NaN()), x)", f160, 1, 512},
  {"512:_mm512_div_ps(_mm512_div_ps(x, _mm512_setzero_ps()), _mm512_setzero_ps())", f161, 1, 512},
  {"512:_mm512_div_ps(_mm512_div_ps(x, _mm512_setzero_ps()), _mm512_set1_ps(-0.0f))", f162, 1, 512},
  {"512:_mm512_div_ps(_mm512_div_ps(x, _mm512_setzero_ps()), _mm512_set1_ps(1.0f))", f163, 1, 512},
  {"512:_mm512_div_ps(_mm512_div_ps(x, _mm512_setzero_ps()), _mm512_set1_ps(-1.0f))", f164, 1, 512},
  {"512:_mm512_div_ps(_mm512_div_ps(x, _mm512_setzero_ps()), _mm512_set1_ps(std::numeric_limits<float>::infinity()))", f165, 1, 512},
  {"512:_mm512_div_ps(_mm512_div_ps(x, _mm512_setzero_ps()), _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN()))", f166, 1, 512},
  {"512:_mm512_div_ps(_mm512_div_ps(x, _mm512_set1_ps(-0.0f)), _mm512_setzero_ps())", f167, 1, 512},
  {"512:_mm512_div_ps(_mm512_div_ps(x, _mm512_set1_ps(-0.0f)), _mm512_set1_ps(-0.0f))", f168, 1, 512},
  {"512:_mm512_div_ps(_mm512_div_ps(x, _mm512_set1_ps(-0.0f)), _mm512_set1_ps(1.0f))", f169, 1, 512},
  {"512:_mm512_div_ps(_mm512_div_ps(x, _mm512_set1_ps(-0.0f)), _mm512_set1_ps(-1.0f))", f170, 1, 512},
  {"512:_mm512_div_ps(_mm512_div_ps(x, _mm512_set1_ps(-0.0f)), _mm512_set1_ps(std::numeric_limits<float>::infinity()))", f171, 1, 512},
  {"512:_mm512_div_ps(_mm512_div_ps(x, _mm512_set1_ps(-0.0f)), _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN()))", f172, 1, 512},
  {"512:_mm512_div_ps(_mm512_div_ps(x, _mm512_set1_ps(1.0f)), _mm512_setzero_ps())", f173, 1, 512},
  {"512:_mm512_div_ps(_mm512_div_ps(x, _mm512_set1_ps(1.0f)), _mm512_set1_ps(-0.0f))", f174, 1, 512},
  {"512:_mm512_div_ps(_mm512_div_ps(x, _mm512_set1_ps(1.0f)), _mm512_set1_ps(1.0f))", f175, 1, 512},
  {"512:_mm512_div_ps(_mm512_div_ps(x, _mm512_set1_ps(1.0f)), _mm512_set1_ps(-1.0f))", f176, 1, 512},
  {"512:_mm512_div_ps(_mm512_div_ps(x, _mm512_set1_ps(1.0f)), _mm512_set1_ps(std::numeric_limits<float>::infinity()))", f177, 1, 512},
  {"512:_mm512_div_ps(_mm512_div_ps(x, _mm512_set1_ps(1.0f)), _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN()))", f178, 1, 512},
  {"512:_mm512_div_ps(_mm512_div_ps(x, _mm512_set1_ps(-1.0f)), _mm512_setzero_ps())", f179, 1, 512},
  {"512:_mm512_div_ps(_mm512_div_ps(x, _mm512_set1_ps(-1.0f)), _mm512_set1_ps(-0.0f))", f180, 1, 512},
  {"512:_mm512_div_ps(_mm512_div_ps(x, _mm512_set1_ps(-1.0f)), _mm512_set1_ps(1.0f))", f181, 1, 512},
  {"512:_mm512_div_ps(_mm512_div_ps(x, _mm512_set1_ps(-1.0f)), _mm512_set1_ps(-1.0f))", f182, 1, 512},
  {"512:_mm512_div_ps(_mm512_div_ps(x, _mm512_set1_ps(-1.0f)), _mm512_set1_ps(std::numeric_limits<float>::infinity()))", f183, 1, 512},
  {"512:_mm512_div_ps(_mm512_div_ps(x, _mm512_set1_ps(-1.0f)), _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN()))", f184, 1, 512},
  {"512:_mm512_div_ps(_mm512_div_ps(x, _mm512_set1_ps(std::numeric_limits<float>::infinity())), _mm512_setzero_ps())", f185, 1, 512},
  {"512:_mm512_div_ps(_mm512_div_ps(x, _mm512_set1_ps(std::numeric_limits<float>::infinity())), _mm512_set1_ps(-0.0f))", f186, 1, 512},
  {"512:_mm512_div_ps(_mm512_div_ps(x, _mm512_set1_ps(std::numeric_limits<float>::infinity())), _mm512_set1_ps(1.0f))", f187, 1, 512},
  {"512:_mm512_div_ps(_mm512_div_ps(x, _mm512_set1_ps(std::numeric_limits<float>::infinity())), _mm512_set1_ps(-1.0f))", f188, 1, 512},
  {"512:_mm512_div_ps(_mm512_div_ps(x, _mm512_set1_ps(std::numeric_limits<float>::infinity())), _mm512_set1_ps(std::numeric_limits<float>::infinity()))", f189, 1, 512},
  {"512:_mm512_div_ps(_mm512_div_ps(x, _mm512_set1_ps(std::numeric_limits<float>::infinity())), _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN()))", f190, 1, 512},
  {"512:_mm512_div_ps(_mm512_div_ps(x, _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN())), _mm512_setzero_ps())", f191, 1, 512},
  {"512:_mm512_div_ps(_mm512_div_ps(x, _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN())), _mm512_set1_ps(-0.0f))", f192, 1, 512},
  {"512:_mm512_div_ps(_mm512_div_ps(x, _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN())), _mm512_set1_ps(1.0f))", f193, 1, 512},
  {"512:_mm512_div_ps(_mm512_div_ps(x, _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN())), _mm512_set1_ps(-1.0f))", f194, 1, 512},
  {"512:_mm512_div_ps(_mm512_div_ps(x, _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN())), _mm512_set1_ps(std::numeric_limits<float>::infinity()))", f195, 1, 512},
  {"512:_mm512_div_ps(_mm512_div_ps(x, _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN())), _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN()))", f196, 1, 512},
  {"512:_mm512_min_ps(x, x)", f197, 1, 512},
  {"512:_mm512_min_ps(x, _mm512_setzero_ps())", f198, 1, 512},
  {"512:_mm512_min_ps(_mm512_setzero_ps(), x)", f199, 1, 512},
  {"512:_mm512_min_ps(x, _mm512_set1_ps(-0.0f))", f200, 1, 512},
  {"512:_mm512_min_ps(_mm512_set1_ps(-0.0f), x)", f201, 1, 512},
  {"512:_mm512_min_ps(x, _mm512_set1_ps(1.0f))", f202, 1, 512},
  {"512:_mm512_min_ps(_mm512_set1_ps(1.0f), x)", f203, 1, 512},
  {"512:_mm512_min_ps(x, _mm512_set1_ps(-1.0f))", f204, 1, 512},
  {"512:_mm512_min_ps(_mm512_set1_ps(-1.0f), x)", f205, 1, 512},
  {"512:_mm512_min_ps(x, _mm512_set1_ps(std::numeric_limits<float>::infinity()))", f206, 1, 512},
  {"512:_mm512_min_ps(_mm512_set1_ps(std::numeric_limits<float>::infinity()), x)", f207, 1, 512},
  {"512:_mm512_min_ps(x, _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN()))", f208, 1, 512},
  {"512:_mm512_min_ps(_mm512_set1_ps(std::numeric_limits<float>::quiet_NaN()), x)", f209, 1, 512},
  {"512:_mm512_min_ps(_mm512_min_ps(x, _mm512_setzero_ps()), _mm512_setzero_ps())", f210, 1, 512},
  {"512:_mm512_min_ps(_mm512_min_ps(x, _mm512_setzero_ps()), _mm512_set1_ps(-0.0f))", f211, 1, 512},
  {"512:_mm512_min_ps(_mm512_min_ps(x, _mm512_setzero_ps()), _mm512_set1_ps(1.0f))", f212, 1, 512},
  {"512:_mm512_min_ps(_mm512_min_ps(x, _mm512_setzero_ps()), _mm512_set1_ps(-1.0f))", f213, 1, 512},
  {"512:_mm512_min_ps(_mm512_min_ps(x, _mm512_setzero_ps()), _mm512_set1_ps(std::numeric_limits<float>::infinity()))", f214, 1, 512},
  {"512:_mm512_min_ps(_mm512_min_ps(x, _mm512_setzero_ps()), _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN()))", f215, 1, 512},
  {"512:_mm512_min_ps(_mm512_min_ps(x, _mm512_set1_ps(-0.0f)), _mm512_setzero_ps())", f216, 1, 512},
  {"512:_mm512_min_ps(_mm512_min_ps(x, _mm512_set1_ps(-0.0f)), _mm512_set1_ps(-0.0f))", f217, 1, 512},
  {"512:_mm512_min_ps(_mm512_min_ps(x, _mm512_set1_ps(-0.0f)), _mm512_set1_ps(1.0f))", f218, 1, 512},
  {"512:_mm512_min_ps(_mm512_min_ps(x, _mm512_set1_ps(-0.0f)), _mm512_set1_ps(-1.0f))", f219, 1, 512},
  {"512:_mm512_min_ps(_mm512_min_ps(x, _mm512_set1_ps(-0.0f)), _mm512_set1_ps(std::numeric_limits<float>::infinity()))", f220, 1, 512},
  {"512:_mm512_min_ps(_mm512_min_ps(x, _mm512_set1_ps(-0.0f)), _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN()))", f221, 1, 512},
  {"512:_mm512_min_ps(_mm512_min_ps(x, _mm512_set1_ps(1.0f)), _mm512_setzero_ps())", f222, 1, 512},
  {"512:_mm512_min_ps(_mm512_min_ps(x, _mm512_set1_ps(1.0f)), _mm512_set1_ps(-0.0f))", f223, 1, 512},
  {"512:_mm512_min_ps(_mm512_min_ps(x, _mm512_set1_ps(1.0f)), _mm512_set1_ps(1.0f))", f224, 1, 512},
  {"512:_mm512_min_ps(_mm512_min_ps(x, _mm512_set1_ps(1.0f)), _mm512_set1_ps(-1.0f))", f225, 1, 512},
  {"512:_mm512_min_ps(_mm512_min_ps(x, _mm512_set1_ps(1.0f)), _mm512_set1_ps(std::numeric_limits<float>::infinity()))", f226, 1, 512},
  {"512:_mm512_min_ps(_mm512_min_ps(x, _mm512_set1_ps(1.0f)), _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN()))", f227, 1, 512},
  {"512:_mm512_min_ps(_mm512_min_ps(x, _mm512_set1_ps(-1.0f)), _mm512_setzero_ps())", f228, 1, 512},
  {"512:_mm512_min_ps(_mm512_min_ps(x, _mm512_set1_ps(-1.0f)), _mm512_set1_ps(-0.0f))", f229, 1, 512},
  {"512:_mm512_min_ps(_mm512_min_ps(x, _mm512_set1_ps(-1.0f)), _mm512_set1_ps(1.0f))", f230, 1, 512},
  {"512:_mm512_min_ps(_mm512_min_ps(x, _mm512_set1_ps(-1.0f)), _mm512_set1_ps(-1.0f))", f231, 1, 512},
  {"512:_mm512_min_ps(_mm512_min_ps(x, _mm512_set1_ps(-1.0f)), _mm512_set1_ps(std::numeric_limits<float>::infinity()))", f232, 1, 512},
  {"512:_mm512_min_ps(_mm512_min_ps(x, _mm512_set1_ps(-1.0f)), _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN()))", f233, 1, 512},
  {"512:_mm512_min_ps(_mm512_min_ps(x, _mm512_set1_ps(std::numeric_limits<float>::infinity())), _mm512_setzero_ps())", f234, 1, 512},
  {"512:_mm512_min_ps(_mm512_min_ps(x, _mm512_set1_ps(std::numeric_limits<float>::infinity())), _mm512_set1_ps(-0.0f))", f235, 1, 512},
  {"512:_mm512_min_ps(_mm512_min_ps(x, _mm512_set1_ps(std::numeric_limits<float>::infinity())), _mm512_set1_ps(1.0f))", f236, 1, 512},
  {"512:_mm512_min_ps(_mm512_min_ps(x, _mm512_set1_ps(std::numeric_limits<float>::infinity())), _mm512_set1_ps(-1.0f))", f237, 1, 512},
  {"512:_mm512_min_ps(_mm512_min_ps(x, _mm512_set1_ps(std::numeric_limits<float>::infinity())), _mm512_set1_ps(std::numeric_limits<float>::infinity()))", f238, 1, 512},
  {"512:_mm512_min_ps(_mm512_min_ps(x, _mm512_set1_ps(std::numeric_limits<float>::infinity())), _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN()))", f239, 1, 512},
  {"512:_mm512_min_ps(_mm512_min_ps(x, _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN())), _mm512_setzero_ps())", f240, 1, 512},
  {"512:_mm512_min_ps(_mm512_min_ps(x, _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN())), _mm512_set1_ps(-0.0f))", f241, 1, 512},
  {"512:_mm512_min_ps(_mm512_min_ps(x, _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN())), _mm512_set1_ps(1.0f))", f242, 1, 512},
  {"512:_mm512_min_ps(_mm512_min_ps(x, _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN())), _mm512_set1_ps(-1.0f))", f243, 1, 512},
  {"512:_mm512_min_ps(_mm512_min_ps(x, _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN())), _mm512_set1_ps(std::numeric_limits<float>::infinity()))", f244, 1, 512},
  {"512:_mm512_min_ps(_mm512_min_ps(x, _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN())), _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN()))", f245, 1, 512},
  {"512:_mm512_max_ps(x, x)", f246, 1, 512},
  {"512:_mm512_max_ps(x, _mm512_setzero_ps())", f247, 1, 512},
  {"512:_mm512_max_ps(_mm512_setzero_ps(), x)", f248, 1, 512},
  {"512:_mm512_max_ps(x, _mm512_set1_ps(-0.0f))", f249, 1, 512},
  {"512:_mm512_max_ps(_mm512_set1_ps(-0.0f), x)", f250, 1, 512},
  {"512:_mm512_max_ps(x, _mm512_set1_ps(1.0f))", f251, 1, 512},
  {"512:_mm512_max_ps(_mm512_set1_ps(1.0f), x)", f252, 1, 512},
  {"512:_mm512_max_ps(x, _mm512_set1_ps(-1.0f))", f253, 1, 512},
  {"512:_mm512_max_ps(_mm512_set1_ps(-1.0f), x)", f254, 1, 512},
  {"512:_mm512_max_ps(x, _mm512_set1_ps(std::numeric_limits<float>::infinity()))", f255, 1, 512},
  {"512:_mm512_max_ps(_mm512_set1_ps(std::numeric_limits<float>::infinity()), x)", f256, 1, 512},
  {"512:_mm512_max_ps(x, _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN()))", f257, 1, 512},
  {"512:_mm512_max_ps(_mm512_set1_ps(std::numeric_limits<float>::quiet_NaN()), x)", f258, 1, 512},
  {"512:_mm512_max_ps(_mm512_max_ps(x, _mm512_setzero_ps()), _mm512_setzero_ps())", f259, 1, 512},
  {"512:_mm512_max_ps(_mm512_max_ps(x, _mm512_setzero_ps()), _mm512_set1_ps(-0.0f))", f260, 1, 512},
  {"512:_mm512_max_ps(_mm512_max_ps(x, _mm512_setzero_ps()), _mm512_set1_ps(1.0f))", f261, 1, 512},
  {"512:_mm512_max_ps(_mm512_max_ps(x, _mm512_setzero_ps()), _mm512_set1_ps(-1.0f))", f262, 1, 512},
  {"512:_mm512_max_ps(_mm512_max_ps(x, _mm512_setzero_ps()), _mm512_set1_ps(std::numeric_limits<float>::infinity()))", f263, 1, 512},
  {"512:_mm512_max_ps(_mm512_max_ps(x, _mm512_setzero_ps()), _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN()))", f264, 1, 512},
  {"512:_mm512_max_ps(_mm512_max_ps(x, _mm512_set1_ps(-0.0f)), _mm512_setzero_ps())", f265, 1, 512},
  {"512:_mm512_max_ps(_mm512_max_ps(x, _mm512_set1_ps(-0.0f)), _mm512_set1_ps(-0.0f))", f266, 1, 512},
  {"512:_mm512_max_ps(_mm512_max_ps(x, _mm512_set1_ps(-0.0f)), _mm512_set1_ps(1.0f))", f267, 1, 512},
  {"512:_mm512_max_ps(_mm512_max_ps(x, _mm512_set1_ps(-0.0f)), _mm512_set1_ps(-1.0f))", f268, 1, 512},
  {"512:_mm512_max_ps(_mm512_max_ps(x, _mm512_set1_ps(-0.0f)), _mm512_set1_ps(std::numeric_limits<float>::infinity()))", f269, 1, 512},
  {"512:_mm512_max_ps(_mm512_max_ps(x, _mm512_set1_ps(-0.0f)), _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN()))", f270, 1, 512},
  {"512:_mm512_max_ps(_mm512_max_ps(x, _mm512_set1_ps(1.0f)), _mm512_setzero_ps())", f271, 1, 512},
  {"512:_mm512_max_ps(_mm512_max_ps(x, _mm512_set1_ps(1.0f)), _mm512_set1_ps(-0.0f))", f272, 1, 512},
  {"512:_mm512_max_ps(_mm512_max_ps(x, _mm512_set1_ps(1.0f)), _mm512_set1_ps(1.0f))", f273, 1, 512},
  {"512:_mm512_max_ps(_mm512_max_ps(x, _mm512_set1_ps(1.0f)), _mm512_set1_ps(-1.0f))", f274, 1, 512},
  {"512:_mm512_max_ps(_mm512_max_ps(x, _mm512_set1_ps(1.0f)), _mm512_set1_ps(std::numeric_limits<float>::infinity()))", f275, 1, 512},
  {"512:_mm512_max_ps(_mm512_max_ps(x, _mm512_set1_ps(1.0f)), _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN()))", f276, 1, 512},
  {"512:_mm512_max_ps(_mm512_max_ps(x, _mm512_set1_ps(-1.0f)), _mm512_setzero_ps())", f277, 1, 512},
  {"512:_mm512_max_ps(_mm512_max_ps(x, _mm512_set1_ps(-1.0f)), _mm512_set1_ps(-0.0f))", f278, 1, 512},
  {"512:_mm512_max_ps(_mm512_max_ps(x, _mm512_set1_ps(-1.0f)), _mm512_set1_ps(1.0f))", f279, 1, 512},
  {"512:_mm512_max_ps(_mm512_max_ps(x, _mm512_set1_ps(-1.0f)), _mm512_set1_ps(-1.0f))", f280, 1, 512},
  {"512:_mm512_max_ps(_mm512_max_ps(x, _mm512_set1_ps(-1.0f)), _mm512_set1_ps(std::numeric_limits<float>::infinity()))", f281, 1, 512},
  {"512:_mm512_max_ps(_mm512_max_ps(x, _mm512_set1_ps(-1.0f)), _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN()))", f282, 1, 512},
  {"512:_mm512_max_ps(_mm512_max_ps(x, _mm512_set1_ps(std::numeric_limits<float>::infinity())), _mm512_setzero_ps())", f283, 1, 512},
  {"512:_mm512_max_ps(_mm512_max_ps(x, _mm512_set1_ps(std::numeric_limits<float>::infinity())), _mm512_set1_ps(-0.0f))", f284, 1, 512},
  {"512:_mm512_max_ps(_mm512_max_ps(x, _mm512_set1_ps(std::numeric_limits<float>::infinity())), _mm512_set1_ps(1.0f))", f285, 1, 512},
  {"512:_mm512_max_ps(_mm512_max_ps(x, _mm512_set1_ps(std::numeric_limits<float>::infinity())), _mm512_set1_ps(-1.0f))", f286, 1, 512},
  {"512:_mm512_max_ps(_mm512_max_ps(x, _mm512_set1_ps(std::numeric_limits<float>::infinity())), _mm512_set1_ps(std::numeric_limits<float>::infinity()))", f287, 1, 512},
  {"512:_mm512_max_ps(_mm512_max_ps(x, _mm512_set1_ps(std::numeric_limits<float>::infinity())), _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN()))", f288, 1, 512},
  {"512:_mm512_max_ps(_mm512_max_ps(x, _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN())), _mm512_setzero_ps())", f289, 1, 512},
  {"512:_mm512_max_ps(_mm512_max_ps(x, _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN())), _mm512_set1_ps(-0.0f))", f290, 1, 512},
  {"512:_mm512_max_ps(_mm512_max_ps(x, _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN())), _mm512_set1_ps(1.0f))", f291, 1, 512},
  {"512:_mm512_max_ps(_mm512_max_ps(x, _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN())), _mm512_set1_ps(-1.0f))", f292, 1, 512},
  {"512:_mm512_max_ps(_mm512_max_ps(x, _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN())), _mm512_set1_ps(std::numeric_limits<float>::infinity()))", f293, 1, 512},
  {"512:_mm512_max_ps(_mm512_max_ps(x, _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN())), _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN()))", f294, 1, 512},
  {"512:_mm512_and_ps(x, x)", f295, 1, 512},
  {"512:_mm512_and_ps(x, _mm512_setzero_ps())", f296, 1, 512},
  {"512:_mm512_and_ps(_mm512_setzero_ps(), x)", f297, 1, 512},
  {"512:_mm512_and_ps(x, _mm512_set1_ps(-0.0f))", f298, 1, 512},
  {"512:_mm512_and_ps(_mm512_set1_ps(-0.0f), x)", f299, 1, 512},
  {"512:_mm512_and_ps(x, _mm512_set1_ps(1.0f))", f300, 1, 512},
  {"512:_mm512_and_ps(_mm512_set1_ps(1.0f), x)", f301, 1, 512},
  {"512:_mm512_and_ps(x, _mm512_set1_ps(-1.0f))", f302, 1, 512},
  {"512:_mm512_and_ps(_mm512_set1_ps(-1.0f), x)", f303, 1, 512},
  {"512:_mm512_and_ps(x, _mm512_set1_ps(std::numeric_limits<float>::infinity()))", f304, 1, 512},
  {"512:_mm512_and_ps(_mm512_set1_ps(std::numeric_limits<float>::infinity()), x)", f305, 1, 512},
  {"512:_mm512_and_ps(x, _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN()))", f306, 1, 512},
  {"512:_mm512_and_ps(_mm512_set1_ps(std::numeric_limits<float>::quiet_NaN()), x)", f307, 1, 512},
  {"512:_mm512_and_ps(_mm512_and_ps(x, _mm512_setzero_ps()), _mm512_setzero_ps())", f308, 1, 512},
  {"512:_mm512_and_ps(_mm512_and_ps(x, _mm512_setzero_ps()), _mm512_set1_ps(-0.0f))", f309, 1, 512},
  {"512:_mm512_and_ps(_mm512_and_ps(x, _mm512_setzero_ps()), _mm512_set1_ps(1.0f))", f310, 1, 512},
  {"512:_mm512_and_ps(_mm512_and_ps(x, _mm512_setzero_ps()), _mm512_set1_ps(-1.0f))", f311, 1, 512},
  {"512:_mm512_and_ps(_mm512_and_ps(x, _mm512_setzero_ps()), _mm512_set1_ps(std::numeric_limits<float>::infinity()))", f312, 1, 512},
  {"512:_mm512_and_ps(_mm512_and_ps(x, _mm512_setzero_ps()), _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN()))", f313, 1, 512},
  {"512:_mm512_and_ps(_mm512_and_ps(x, _mm512_set1_ps(-0.0f)), _mm512_setzero_ps())", f314, 1, 512},
  {"512:_mm512_and_ps(_mm512_and_ps(x, _mm512_set1_ps(-0.0f)), _mm512_set1_ps(-0.0f))", f315, 1, 512},
  {"512:_mm512_and_ps(_mm512_and_ps(x, _mm512_set1_ps(-0.0f)), _mm512_set1_ps(1.0f))", f316, 1, 512},
  {"512:_mm512_and_ps(_mm512_and_ps(x, _mm512_set1_ps(-0.0f)), _mm512_set1_ps(-1.0f))", f317, 1, 512},
  {"512:_mm512_and_ps(_mm512_and_ps(x, _mm512_set1_ps(-0.0f)), _mm512_set1_ps(std::numeric_limits<float>::infinity()))", f318, 1, 512},
  {"512:_mm512_and_ps(_mm512_and_ps(x, _mm512_set1_ps(-0.0f)), _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN()))", f319, 1, 512},
  {"512:_mm512_and_ps(_mm512_and_ps(x, _mm512_set1_ps(1.0f)), _mm512_setzero_ps())", f320, 1, 512},
  {"512:_mm512_and_ps(_mm512_and_ps(x, _mm512_set1_ps(1.0f)), _mm512_set1_ps(-0.0f))", f321, 1, 512},
  {"512:_mm512_and_ps(_mm512_and_ps(x, _mm512_set1_ps(1.0f)), _mm512_set1_ps(1.0f))", f322, 1, 512},
  {"512:_mm512_and_ps(_mm512_and_ps(x, _mm512_set1_ps(1.0f)), _mm512_set1_ps(-1.0f))", f323, 1, 512},
  {"512:_mm512_and_ps(_mm512_and_ps(x, _mm512_set1_ps(1.0f)), _mm512_set1_ps(std::numeric_limits<float>::infinity()))", f324, 1, 512},
  {"512:_mm512_and_ps(_mm512_and_ps(x, _mm512_set1_ps(1.0f)), _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN()))", f325, 1, 512},
  {"512:_mm512_and_ps(_mm512_and_ps(x, _mm512_set1_ps(-1.0f)), _mm512_setzero_ps())", f326, 1, 512},
  {"512:_mm512_and_ps(_mm512_and_ps(x, _mm512_set1_ps(-1.0f)), _mm512_set1_ps(-0.0f))", f327, 1, 512},
  {"512:_mm512_and_ps(_mm512_and_ps(x, _mm512_set1_ps(-1.0f)), _mm512_set1_ps(1.0f))", f328, 1, 512},
  {"512:_mm512_and_ps(_mm512_and_ps(x, _mm512_set1_ps(-1.0f)), _mm512_set1_ps(-1.0f))", f329, 1, 512},
  {"512:_mm512_and_ps(_mm512_and_ps(x, _mm512_set1_ps(-1.0f)), _mm512_set1_ps(std::numeric_limits<float>::infinity()))", f330, 1, 512},
  {"512:_mm512_and_ps(_mm512_and_ps(x, _mm512_set1_ps(-1.0f)), _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN()))", f331, 1, 512},
  {"512:_mm512_and_ps(_mm512_and_ps(x, _mm512_set1_ps(std::numeric_limits<float>::infinity())), _mm512_setzero_ps())", f332, 1, 512},
  {"512:_mm512_and_ps(_mm512_and_ps(x, _mm512_set1_ps(std::numeric_limits<float>::infinity())), _mm512_set1_ps(-0.0f))", f333, 1, 512},
  {"512:_mm512_and_ps(_mm512_and_ps(x, _mm512_set1_ps(std::numeric_limits<float>::infinity())), _mm512_set1_ps(1.0f))", f334, 1, 512},
  {"512:_mm512_and_ps(_mm512_and_ps(x, _mm512_set1_ps(std::numeric_limits<float>::infinity())), _mm512_set1_ps(-1.0f))", f335, 1, 512},
  {"512:_mm512_and_ps(_mm512_and_ps(x, _mm512_set1_ps(std::numeric_limits<float>::infinity())), _mm512_set1_ps(std::numeric_limits<float>::infinity()))", f336, 1, 512},
  {"512:_mm512_and_ps(_mm512_and_ps(x, _mm512_set1_ps(std::numeric_limits<float>::infinity())), _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN()))", f337, 1, 512},
  {"512:_mm512_and_ps(_mm512_and_ps(x, _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN())), _mm512_setzero_ps())", f338, 1, 512},
  {"512:_mm512_and_ps(_mm512_and_ps(x, _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN())), _mm512_set1_ps(-0.0f))", f339, 1, 512},
  {"512:_mm512_and_ps(_mm512_and_ps(x, _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN())), _mm512_set1_ps(1.0f))", f340, 1, 512},
  {"512:_mm512_and_ps(_mm512_and_ps(x, _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN())), _mm512_set1_ps(-1.0f))", f341, 1, 512},
  {"512:_mm512_and_ps(_mm512_and_ps(x, _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN())), _mm512_set1_ps(std::numeric_limits<float>::infinity()))", f342, 1, 512},
  {"512:_mm512_and_ps(_mm512_and_ps(x, _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN())), _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN()))", f343, 1, 512},
  {"512:_mm512_or_ps(x, x)", f344, 1, 512},
  {"512:_mm512_or_ps(x, _mm512_setzero_ps())", f345, 1, 512},
  {"512:_mm512_or_ps(_mm512_setzero_ps(), x)", f346, 1, 512},
  {"512:_mm512_or_ps(x, _mm512_set1_ps(-0.0f))", f347, 1, 512},
  {"512:_mm512_or_ps(_mm512_set1_ps(-0.0f), x)", f348, 1, 512},
  {"512:_mm512_or_ps(x, _mm512_set1_ps(1.0f))", f349, 1, 512},
  {"512:_mm512_or_ps(_mm512_set1_ps(1.0f), x)", f350, 1, 512},
  {"512:_mm512_or_ps(x, _mm512_set1_ps(-1.0f))", f351, 1, 512},
  {"512:_mm512_or_ps(_mm512_set1_ps(-1.0f), x)", f352, 1, 512},
  {"512:_mm512_or_ps(x, _mm512_set1_ps(std::numeric_limits<float>::infinity()))", f353, 1, 512},
  {"512:_mm512_or_ps(_mm512_set1_ps(std::numeric_limits<float>::infinity()), x)", f354, 1, 512},
  {"512:_mm512_or_ps(x, _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN()))", f355, 1, 512},
  {"512:_mm512_or_ps(_mm512_set1_ps(std::numeric_limits<float>::quiet_NaN()), x)", f356, 1, 512},
  {"512:_mm512_or_ps(_mm512_or_ps(x, _mm512_setzero_ps()), _mm512_setzero_ps())", f357, 1, 512},
  {"512:_mm512_or_ps(_mm512_or_ps(x, _mm512_setzero_ps()), _mm512_set1_ps(-0.0f))", f358, 1, 512},
  {"512:_mm512_or_ps(_mm512_or_ps(x, _mm512_setzero_ps()), _mm512_set1_ps(1.0f))", f359, 1, 512},
  {"512:_mm512_or_ps(_mm512_or_ps(x, _mm512_setzero_ps()), _mm512_set1_ps(-1.0f))", f360, 1, 512},
  {"512:_mm512_or_ps(_mm512_or_ps(x, _mm512_setzero_ps()), _mm512_set1_ps(std::numeric_limits<float>::infinity()))", f361, 1, 512},
  {"512:_mm512_or_ps(_mm512_or_ps(x, _mm512_setzero_ps()), _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN()))", f362, 1, 512},
  {"512:_mm512_or_ps(_mm512_or_ps(x, _mm512_set1_ps(-0.0f)), _mm512_setzero_ps())", f363, 1, 512},
  {"512:_mm512_or_ps(_mm512_or_ps(x, _mm512_set1_ps(-0.0f)), _mm512_set1_ps(-0.0f))", f364, 1, 512},
  {"512:_mm512_or_ps(_mm512_or_ps(x, _mm512_set1_ps(-0.0f)), _mm512_set1_ps(1.0f))", f365, 1, 512},
  {"512:_mm512_or_ps(_mm512_or_ps(x, _mm512_set1_ps(-0.0f)), _mm512_set1_ps(-1.0f))", f366, 1, 512},
  {"512:_mm512_or_ps(_mm512_or_ps(x, _mm512_set1_ps(-0.0f)), _mm512_set1_ps(std::numeric_limits<float>::infinity()))", f367, 1, 512},
  {"512:_mm512_or_ps(_mm512_or_ps(x, _mm512_set1_ps(-0.0f)), _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN()))", f368, 1, 512},
  {"512:_mm512_or_ps(_mm512_or_ps(x, _mm512_set1_ps(1.0f)), _mm512_setzero_ps())", f369, 1, 512},
  {"512:_mm512_or_ps(_mm512_or_ps(x, _mm512_set1_ps(1.0f)), _mm512_set1_ps(-0.0f))", f370, 1, 512},
  {"512:_mm512_or_ps(_mm512_or_ps(x, _mm512_set1_ps(1.0f)), _mm512_set1_ps(1.0f))", f371, 1, 512},
  {"512:_mm512_or_ps(_mm512_or_ps(x, _mm512_set1_ps(1.0f)), _mm512_set1_ps(-1.0f))", f372, 1, 512},
  {"512:_mm512_or_ps(_mm512_or_ps(x, _mm512_set1_ps(1.0f)), _mm512_set1_ps(std::numeric_limits<float>::infinity()))", f373, 1, 512},
  {"512:_mm512_or_ps(_mm512_or_ps(x, _mm512_set1_ps(1.0f)), _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN()))", f374, 1, 512},
  {"512:_mm512_or_ps(_mm512_or_ps(x, _mm512_set1_ps(-1.0f)), _mm512_setzero_ps())", f375, 1, 512},
  {"512:_mm512_or_ps(_mm512_or_ps(x, _mm512_set1_ps(-1.0f)), _mm512_set1_ps(-0.0f))", f376, 1, 512},
  {"512:_mm512_or_ps(_mm512_or_ps(x, _mm512_set1_ps(-1.0f)), _mm512_set1_ps(1.0f))", f377, 1, 512},
  {"512:_mm512_or_ps(_mm512_or_ps(x, _mm512_set1_ps(-1.0f)), _mm512_set1_ps(-1.0f))", f378, 1, 512},
  {"512:_mm512_or_ps(_mm512_or_ps(x, _mm512_set1_ps(-1.0f)), _mm512_set1_ps(std::numeric_limits<float>::infinity()))", f379, 1, 512},
  {"512:_mm512_or_ps(_mm512_or_ps(x, _mm512_set1_ps(-1.0f)), _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN()))", f380, 1, 512},
  {"512:_mm512_or_ps(_mm512_or_ps(x, _mm512_set1_ps(std::numeric_limits<float>::infinity())), _mm512_setzero_ps())", f381, 1, 512},
  {"512:_mm512_or_ps(_mm512_or_ps(x, _mm512_set1_ps(std::numeric_limits<float>::infinity())), _mm512_set1_ps(-0.0f))", f382, 1, 512},
  {"512:_mm512_or_ps(_mm512_or_ps(x, _mm512_set1_ps(std::numeric_limits<float>::infinity())), _mm512_set1_ps(1.0f))", f383, 1, 512},
  {"512:_mm512_or_ps(_mm512_or_ps(x, _mm512_set1_ps(std::numeric_limits<float>::infinity())), _mm512_set1_ps(-1.0f))", f384, 1, 512},
  {"512:_mm512_or_ps(_mm512_or_ps(x, _mm512_set1_ps(std::numeric_limits<float>::infinity())), _mm512_set1_ps(std::numeric_limits<float>::infinity()))", f385, 1, 512},
  {"512:_mm512_or_ps(_mm512_or_ps(x, _mm512_set1_ps(std::numeric_limits<float>::infinity())), _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN()))", f386, 1, 512},
  {"512:_mm512_or_ps(_mm512_or_ps(x, _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN())), _mm512_setzero_ps())", f387, 1, 512},
  {"512:_mm512_or_ps(_mm512_or_ps(x, _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN())), _mm512_set1_ps(-0.0f))", f388, 1, 512},
  {"512:_mm512_or_ps(_mm512_or_ps(x, _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN())), _mm512_set1_ps(1.0f))", f389, 1, 512},
  {"512:_mm512_or_ps(_mm512_or_ps(x, _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN())), _mm512_set1_ps(-1.0f))", f390, 1, 512},
  {"512:_mm512_or_ps(_mm512_or_ps(x, _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN())), _mm512_set1_ps(std::numeric_limits<float>::infinity()))", f391, 1, 512},
  {"512:_mm512_or_ps(_mm512_or_ps(x, _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN())), _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN()))", f392, 1, 512},
  {"512:_mm512_xor_ps(x, x)", f393, 1, 512},
  {"512:_mm512_xor_ps(x, _mm512_setzero_ps())", f394, 1, 512},
  {"512:_mm512_xor_ps(_mm512_setzero_ps(), x)", f395, 1, 512},
  {"512:_mm512_xor_ps(x, _mm512_set1_ps(-0.0f))", f396, 1, 512},
  {"512:_mm512_xor_ps(_mm512_set1_ps(-0.0f), x)", f397, 1, 512},
  {"512:_mm512_xor_ps(x, _mm512_set1_ps(1.0f))", f398, 1, 512},
  {"512:_mm512_xor_ps(_mm512_set1_ps(1.0f), x)", f399, 1, 512},
  {"512:_mm512_xor_ps(x, _mm512_set1_ps(-1.0f))", f400, 1, 512},
  {"512:_mm512_xor_ps(_mm512_set1_ps(-1.0f), x)", f401, 1, 512},
  {"512:_mm512_xor_ps(x, _mm512_set1_ps(std::numeric_limits<float>::infinity()))", f402, 1, 512},
  {"512:_mm512_xor_ps(_mm512_set1_ps(std::numeric_limits<float>::infinity()), x)", f403, 1, 512},
  {"512:_mm512_xor_ps(x, _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN()))", f404, 1, 512},
  {"512:_mm512_xor_ps(_mm512_set1_ps(std::numeric_limits<float>::quiet_NaN()), x)", f405, 1, 512},
  {"512:_mm512_xor_ps(_mm512_xor_ps(x, _mm512_setzero_ps()), _mm512_setzero_ps())", f406, 1, 512},
  {"512:_mm512_xor_ps(_mm512_xor_ps(x, _mm512_setzero_ps()), _mm512_set1_ps(-0.0f))", f407, 1, 512},
  {"512:_mm512_xor_ps(_mm512_xor_ps(x, _mm512_setzero_ps()), _mm512_set1_ps(1.0f))", f408, 1, 512},
  {"512:_mm512_xor_ps(_mm512_xor_ps(x, _mm512_setzero_ps()), _mm512_set1_ps(-1.0f))", f409, 1, 512},
  {"512:_mm512_xor_ps(_mm512_xor_ps(x, _mm512_setzero_ps()), _mm512_set1_ps(std::numeric_limits<float>::infinity()))", f410, 1, 512},
  {"512:_mm512_xor_ps(_mm512_xor_ps(x, _mm512_setzero_ps()), _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN()))", f411, 1, 512},
  {"512:_mm512_xor_ps(_mm512_xor_ps(x, _mm512_set1_ps(-0.0f)), _mm512_setzero_ps())", f412, 1, 512},
  {"512:_mm512_xor_ps(_mm512_xor_ps(x, _mm512_set1_ps(-0.0f)), _mm512_set1_ps(1.0f))", f413, 1, 512},
  {"512:_mm512_xor_ps(_mm512_xor_ps(x, _mm512_set1_ps(-0.0f)), _mm512_set1_ps(-1.0f))", f414, 1, 512},
  {"512:_mm512_xor_ps(_mm512_xor_ps(x, _mm512_set1_ps(-0.0f)), _mm512_set1_ps(std::numeric_limits<float>::infinity()))", f415, 1, 512},
  {"512:_mm512_xor_ps(_mm512_xor_ps(x, _mm512_set1_ps(-0.0f)), _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN()))", f416, 1, 512},
  {"512:_mm512_xor_ps(_mm512_xor_ps(x, _mm512_set1_ps(1.0f)), _mm512_setzero_ps())", f417, 1, 512},
  {"512:_mm512_xor_ps(_mm512_xor_ps(x, _mm512_set1_ps(1.0f)), _mm512_set1_ps(-0.0f))", f418, 1, 512},
  {"512:_mm512_xor_ps(_mm512_xor_ps(x, _mm512_set1_ps(1.0f)), _mm512_set1_ps(1.0f))", f419, 1, 512},
  {"512:_mm512_xor_ps(_mm512_xor_ps(x, _mm512_set1_ps(1.0f)), _mm512_set1_ps(-1.0f))", f420, 1, 512},
  {"512:_mm512_xor_ps(_mm512_xor_ps(x, _mm512_set1_ps(1.0f)), _mm512_set1_ps(std::numeric_limits<float>::infinity()))", f421, 1, 512},
  {"512:_mm512_xor_ps(_mm512_xor_ps(x, _mm512_set1_ps(1.0f)), _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN()))", f422, 1, 512},
  {"512:_mm512_xor_ps(_mm512_xor_ps(x, _mm512_set1_ps(-1.0f)), _mm512_setzero_ps())", f423, 1, 512},
  {"512:_mm512_xor_ps(_mm512_xor_ps(x, _mm512_set1_ps(-1.0f)), _mm512_set1_ps(-0.0f))", f424, 1, 512},
  {"512:_mm512_xor_ps(_mm512_xor_ps(x, _mm512_set1_ps(-1.0f)), _mm512_set1_ps(1.0f))", f425, 1, 512},
  {"512:_mm512_xor_ps(_mm512_xor_ps(x, _mm512_set1_ps(-1.0f)), _mm512_set1_ps(-1.0f))", f426, 1, 512},
  {"512:_mm512_xor_ps(_mm512_xor_ps(x, _mm512_set1_ps(-1.0f)), _mm512_set1_ps(std::numeric_limits<float>::infinity()))", f427, 1, 512},
  {"512:_mm512_xor_ps(_mm512_xor_ps(x, _mm512_set1_ps(-1.0f)), _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN()))", f428, 1, 512},
  {"512:_mm512_xor_ps(_mm512_xor_ps(x, _mm512_set1_ps(std::numeric_limits<float>::infinity())), _mm512_setzero_ps())", f429, 1, 512},
  {"512:_mm512_xor_ps(_mm512_xor_ps(x, _mm512_set1_ps(std::numeric_limits<float>::infinity())), _mm512_set1_ps(-0.0f))", f430, 1, 512},
  {"512:_mm512_xor_ps(_mm512_xor_ps(x, _mm512_set1_ps(std::numeric_limits<float>::infinity())), _mm512_set1_ps(1.0f))", f431, 1, 512},
  {"512:_mm512_xor_ps(_mm512_xor_ps(x, _mm512_set1_ps(std::numeric_limits<float>::infinity())), _mm512_set1_ps(-1.0f))", f432, 1, 512},
  {"512:_mm512_xor_ps(_mm512_xor_ps(x, _mm512_set1_ps(std::numeric_limits<float>::infinity())), _mm512_set1_ps(std::numeric_limits<float>::infinity()))", f433, 1, 512},
  {"512:_mm512_xor_ps(_mm512_xor_ps(x, _mm512_set1_ps(std::numeric_limits<float>::infinity())), _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN()))", f434, 1, 512},
  {"512:_mm512_xor_ps(_mm512_xor_ps(x, _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN())), _mm512_setzero_ps())", f435, 1, 512},
  {"512:_mm512_xor_ps(_mm512_xor_ps(x, _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN())), _mm512_set1_ps(-0.0f))", f436, 1, 512},
  {"512:_mm512_xor_ps(_mm512_xor_ps(x, _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN())), _mm512_set1_ps(1.0f))", f437, 1, 512},
  {"512:_mm512_xor_ps(_mm512_xor_ps(x, _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN())), _mm512_set1_ps(-1.0f))", f438, 1, 512},
  {"512:_mm512_xor_ps(_mm512_xor_ps(x, _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN())), _mm512_set1_ps(std::numeric_limits<float>::infinity()))", f439, 1, 512},
  {"512:_mm512_xor_ps(_mm512_xor_ps(x, _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN())), _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN()))", f440, 1, 512},
  {"512:_mm512_andnot_ps(x, x)", f441, 1, 512},
  {"512:_mm512_andnot_ps(x, _mm512_setzero_ps())", f442, 1, 512},
  {"512:_mm512_andnot_ps(_mm512_setzero_ps(), x)", f443, 1, 512},
  {"512:_mm512_andnot_ps(x, _mm512_set1_ps(-0.0f))", f444, 1, 512},
  {"512:_mm512_andnot_ps(_mm512_set1_ps(-0.0f), x)", f445, 1, 512},
  {"512:_mm512_andnot_ps(x, _mm512_set1_ps(1.0f))", f446, 1, 512},
  {"512:_mm512_andnot_ps(_mm512_set1_ps(1.0f), x)", f447, 1, 512},
  {"512:_mm512_andnot_ps(x, _mm512_set1_ps(-1.0f))", f448, 1, 512},
  {"512:_mm512_andnot_ps(_mm512_set1_ps(-1.0f), x)", f449, 1, 512},
  {"512:_mm512_andnot_ps(x, _mm512_set1_ps(std::numeric_limits<float>::infinity()))", f450, 1, 512},
  {"512:_mm512_andnot_ps(_mm512_set1_ps(std::numeric_limits<float>::infinity()), x)", f451, 1, 512},
  {"512:_mm512_andnot_ps(x, _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN()))", f452, 1, 512},
  {"512:_mm512_andnot_ps(_mm512_set1_ps(std::numeric_limits<float>::quiet_NaN()), x)", f453, 1, 512},
  {"512:_mm512_andnot_ps(_mm512_andnot_ps(x, _mm512_setzero_ps()), _mm512_setzero_ps())", f454, 1, 512},
  {"512:_mm512_andnot_ps(_mm512_andnot_ps(x, _mm512_setzero_ps()), _mm512_set1_ps(-0.0f))", f455, 1, 512},
  {"512:_mm512_andnot_ps(_mm512_andnot_ps(x, _mm512_setzero_ps()), _mm512_set1_ps(1.0f))", f456, 1, 512},
  {"512:_mm512_andnot_ps(_mm512_andnot_ps(x, _mm512_setzero_ps()), _mm512_set1_ps(-1.0f))", f457, 1, 512},
  {"512:_mm512_andnot_ps(_mm512_andnot_ps(x, _mm512_setzero_ps()), _mm512_set1_ps(std::numeric_limits<float>::infinity()))", f458, 1, 512},
  {"512:_mm512_andnot_ps(_mm512_andnot_ps(x, _mm512_setzero_ps()), _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN()))", f459, 1, 512},
  {"512:_mm512_andnot_ps(_mm512_andnot_ps(x, _mm512_set1_ps(-0.0f)), _mm512_setzero_ps())", f460, 1, 512},
  {"512:_mm512_andnot_ps(_mm512_andnot_ps(x, _mm512_set1_ps(-0.0f)), _mm512_set1_ps(-0.0f))", f461, 1, 512},
  {"512:_mm512_andnot_ps(_mm512_andnot_ps(x, _mm512_set1_ps(-0.0f)), _mm512_set1_ps(1.0f))", f462, 1, 512},
  {"512:_mm512_andnot_ps(_mm512_andnot_ps(x, _mm512_set1_ps(-0.0f)), _mm512_set1_ps(-1.0f))", f463, 1, 512},
  {"512:_mm512_andnot_ps(_mm512_andnot_ps(x, _mm512_set1_ps(-0.0f)), _mm512_set1_ps(std::numeric_limits<float>::infinity()))", f464, 1, 512},
  {"512:_mm512_andnot_ps(_mm512_andnot_ps(x, _mm512_set1_ps(-0.0f)), _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN()))", f465, 1, 512},
  {"512:_mm512_andnot_ps(_mm512_andnot_ps(x, _mm512_set1_ps(1.0f)), _mm512_setzero_ps())", f466, 1, 512},
  {"512:_mm512_andnot_ps(_mm512_andnot_ps(x, _mm512_set1_ps(1.0f)), _mm512_set1_ps(-0.0f))", f467, 1, 512},
  {"512:_mm512_andnot_ps(_mm512_andnot_ps(x, _mm512_set1_ps(1.0f)), _mm512_set1_ps(1.0f))", f468, 1, 512},
  {"512:_mm512_andnot_ps(_mm512_andnot_ps(x, _mm512_set1_ps(1.0f)), _mm512_set1_ps(-1.0f))", f469, 1, 512},
  {"512:_mm512_andnot_ps(_mm512_andnot_ps(x, _mm512_set1_ps(1.0f)), _mm512_set1_ps(std::numeric_limits<float>::infinity()))", f470, 1, 512},
  {"512:_mm512_andnot_ps(_mm512_andnot_ps(x, _mm512_set1_ps(1.0f)), _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN()))", f471, 1, 512},
  {"512:_mm512_andnot_ps(_mm512_andnot_ps(x, _mm512_set1_ps(-1.0f)), _mm512_setzero_ps())", f472, 1, 512},
  {"512:_mm512_andnot_ps(_mm512_andnot_ps(x, _mm512_set1_ps(-1.0f)), _mm512_set1_ps(-0.0f))", f473, 1, 512},
  {"512:_mm512_andnot_ps(_mm512_andnot_ps(x, _mm512_set1_ps(-1.0f)), _mm512_set1_ps(1.0f))", f474, 1, 512},
  {"512:_mm512_andnot_ps(_mm512_andnot_ps(x, _mm512_set1_ps(-1.0f)), _mm512_set1_ps(-1.0f))", f475, 1, 512},
  {"512:_mm512_andnot_ps(_mm512_andnot_ps(x, _mm512_set1_ps(-1.0f)), _mm512_set1_ps(std::numeric_limits<float>::infinity()))", f476, 1, 512},
  {"512:_mm512_andnot_ps(_mm512_andnot_ps(x, _mm512_set1_ps(-1.0f)), _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN()))", f477, 1, 512},
  {"512:_mm512_andnot_ps(_mm512_andnot_ps(x, _mm512_set1_ps(std::numeric_limits<float>::infinity())), _mm512_setzero_ps())", f478, 1, 512},
  {"512:_mm512_andnot_ps(_mm512_andnot_ps(x, _mm512_set1_ps(std::numeric_limits<float>::infinity())), _mm512_set1_ps(-0.0f))", f479, 1, 512},
  {"512:_mm512_andnot_ps(_mm512_andnot_ps(x, _mm512_set1_ps(std::numeric_limits<float>::infinity())), _mm512_set1_ps(1.0f))", f480, 1, 512},
  {"512:_mm512_andnot_ps(_mm512_andnot_ps(x, _mm512_set1_ps(std::numeric_limits<float>::infinity())), _mm512_set1_ps(-1.0f))", f481, 1, 512},
  {"512:_mm512_andnot_ps(_mm512_andnot_ps(x, _mm512_set1_ps(std::numeric_limits<float>::infinity())), _mm512_set1_ps(std::numeric_limits<float>::infinity()))", f482, 1, 512},
  {"512:_mm512_andnot_ps(_mm512_andnot_ps(x, _mm512_set1_ps(std::numeric_limits<float>::infinity())), _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN()))", f483, 1, 512},
  {"512:_mm512_andnot_ps(_mm512_andnot_ps(x, _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN())), _mm512_setzero_ps())", f484, 1, 512},
  {"512:_mm512_andnot_ps(_mm512_andnot_ps(x, _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN())), _mm512_set1_ps(-0.0f))", f485, 1, 512},
  {"512:_mm512_andnot_ps(_mm512_andnot_ps(x, _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN())), _mm512_set1_ps(1.0f))", f486, 1, 512},
  {"512:_mm512_andnot_ps(_mm512_andnot_ps(x, _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN())), _mm512_set1_ps(-1.0f))", f487, 1, 512},
  {"512:_mm512_andnot_ps(_mm512_andnot_ps(x, _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN())), _mm512_set1_ps(std::numeric_limits<float>::infinity()))", f488, 1, 512},
  {"512:_mm512_andnot_ps(_mm512_andnot_ps(x, _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN())), _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN()))", f489, 1, 512},
  {"512:_mm512_add_ps(_mm512_add_ps(x, y), y)", f490, 1, 512},
  {"512:_mm512_add_ps(x, _mm512_add_ps(x, y))", f491, 1, 512},
  {"512:_mm512_add_ps(_mm512_add_ps(x, y), x)", f492, 1, 512},
  {"512:_mm512_add_ps(y, _mm512_add_ps(x, y))", f493, 1, 512},
  {"512:_mm512_add_ps(_mm512_sub_ps(x, y), y)", f494, 1, 512},
  {"512:_mm512_add_ps(x, _mm512_sub_ps(x, y))", f495, 1, 512},
  {"512:_mm512_add_ps(_mm512_sub_ps(x, y), x)", f496, 1, 512},
  {"512:_mm512_add_ps(y, _mm512_sub_ps(x, y))", f497, 1, 512},
  {"512:_mm512_add_ps(_mm512_mul_ps(x, y), y)", f498, 1, 512},
  {"512:_mm512_add_ps(x, _mm512_mul_ps(x, y))", f499, 1, 512},
  {"512:_mm512_add_ps(_mm512_mul_ps(x, y), x)", f500, 1, 512},
  {"512:_mm512_add_ps(y, _mm512_mul_ps(x, y))", f501, 1, 512},
  {"512:_mm512_add_ps(_mm512_div_ps(x, y), y)", f502, 1, 512},
  {"512:_mm512_add_ps(x, _mm512_div_ps(x, y))", f503, 1, 512},
  {"512:_mm512_add_ps(_mm512_div_ps(x, y), x)", f504, 1, 512},
  {"512:_mm512_add_ps(y, _mm512_div_ps(x, y))", f505, 1, 512},
  {"512:_mm512_add_ps(_mm512_min_ps(x, y), y)", f506, 1, 512},
  {"512:_mm512_add_ps(x, _mm512_min_ps(x, y))", f507, 1, 512},
  {"512:_mm512_add_ps(_mm512_min_ps(x, y), x)", f508, 1, 512},
  {"512:_mm512_add_ps(y, _mm512_min_ps(x, y))", f509, 1, 512},
  {"512:_mm512_add_ps(_mm512_max_ps(x, y), y)", f510, 1, 512},
  {"512:_mm512_add_ps(x, _mm512_max_ps(x, y))", f511, 1, 512},
  {"512:_mm512_add_ps(_mm512_max_ps(x, y), x)", f512, 1, 512},
  {"512:_mm512_add_ps(y, _mm512_max_ps(x, y))", f513, 1, 512},
  {"512:_mm512_add_ps(_mm512_and_ps(x, y), y)", f514, 1, 512},
  {"512:_mm512_add_ps(x, _mm512_and_ps(x, y))", f515, 1, 512},
  {"512:_mm512_add_ps(_mm512_and_ps(x, y), x)", f516, 1, 512},
  {"512:_mm512_add_ps(y, _mm512_and_ps(x, y))", f517, 1, 512},
  {"512:_mm512_add_ps(_mm512_or_ps(x, y), y)", f518, 1, 512},
  {"512:_mm512_add_ps(x, _mm512_or_ps(x, y))", f519, 1, 512},
  {"512:_mm512_add_ps(_mm512_or_ps(x, y), x)", f520, 1, 512},
  {"512:_mm512_add_ps(y, _mm512_or_ps(x, y))", f521, 1, 512},
  {"512:_mm512_add_ps(_mm512_xor_ps(x, y), y)", f522, 1, 512},
  {"512:_mm512_add_ps(x, _mm512_xor_ps(x, y))", f523, 1, 512},
  {"512:_mm512_add_ps(_mm512_xor_ps(x, y), x)", f524, 1, 512},
  {"512:_mm512_add_ps(y, _mm512_xor_ps(x, y))", f525, 1, 512},
  {"512:_mm512_add_ps(_mm512_andnot_ps(x, y), y)", f526, 1, 512},
  {"512:_mm512_add_ps(x, _mm512_andnot_ps(x, y))", f527, 1, 512},
  {"512:_mm512_add_ps(_mm512_andnot_ps(x, y), x)", f528, 1, 512},
  {"512:_mm512_add_ps(y, _mm512_andnot_ps(x, y))", f529, 1, 512},
  {"512:_mm512_sub_ps(_mm512_add_ps(x, y), y)", f530, 1, 512},
  {"512:_mm512_sub_ps(x, _mm512_add_ps(x, y))", f531, 1, 512},
  {"512:_mm512_sub_ps(_mm512_add_ps(x, y), x)", f532, 1, 512},
  {"512:_mm512_sub_ps(y, _mm512_add_ps(x, y))", f533, 1, 512},
  {"512:_mm512_sub_ps(_mm512_sub_ps(x, y), y)", f534, 1, 512},
  {"512:_mm512_sub_ps(x, _mm512_sub_ps(x, y))", f535, 1, 512},
  {"512:_mm512_sub_ps(_mm512_sub_ps(x, y), x)", f536, 1, 512},
  {"512:_mm512_sub_ps(y, _mm512_sub_ps(x, y))", f537, 1, 512},
  {"512:_mm512_sub_ps(_mm512_mul_ps(x, y), y)", f538, 1, 512},
  {"512:_mm512_sub_ps(x, _mm512_mul_ps(x, y))", f539, 1, 512},
  {"512:_mm512_sub_ps(_mm512_mul_ps(x, y), x)", f540, 1, 512},
  {"512:_mm512_sub_ps(y, _mm512_mul_ps(x, y))", f541, 1, 512},
  {"512:_mm512_sub_ps(_mm512_div_ps(x, y), y)", f542, 1, 512},
  {"512:_mm512_sub_ps(x, _mm512_div_ps(x, y))", f543, 1, 512},
  {"512:_mm512_sub_ps(_mm512_div_ps(x, y), x)", f544, 1, 512},
  {"512:_mm512_sub_ps(y, _mm512_div_ps(x, y))", f545, 1, 512},
  {"512:_mm512_sub_ps(_mm512_min_ps(x, y), y)", f546, 1, 512},
  {"512:_mm512_sub_ps(x, _mm512_min_ps(x, y))", f547, 1, 512},
  {"512:_mm512_sub_ps(_mm512_min_ps(x, y), x)", f548, 1, 512},
  {"512:_mm512_sub_ps(y, _mm512_min_ps(x, y))", f549, 1, 512},
  {"512:_mm512_sub_ps(_mm512_max_ps(x, y), y)", f550, 1, 512},
  {"512:_mm512_sub_ps(x, _mm512_max_ps(x, y))", f551, 1, 512},
  {"512:_mm512_sub_ps(_mm512_max_ps(x, y), x)", f552, 1, 512},
  {"512:_mm512_sub_ps(y, _mm512_max_ps(x, y))", f553, 1, 512},
  {"512:_mm512_sub_ps(_mm512_and_ps(x, y), y)", f554, 1, 512},
  {"512:_mm512_sub_ps(x, _mm512_and_ps(x, y))", f555, 1, 512},
  {"512:_mm512_sub_ps(_mm512_and_ps(x, y), x)", f556, 1, 512},
  {"512:_mm512_sub_ps(y, _mm512_and_ps(x, y))", f557, 1, 512},
  {"512:_mm512_sub_ps(_mm512_or_ps(x, y), y)", f558, 1, 512},
  {"512:_mm512_sub_ps(x, _mm512_or_ps(x, y))", f559, 1, 512},
  {"512:_mm512_sub_ps(_mm512_or_ps(x, y), x)", f560, 1, 512},
  {"512:_mm512_sub_ps(y, _mm512_or_ps(x, y))", f561, 1, 512},
  {"512:_mm512_sub_ps(_mm512_xor_ps(x, y), y)", f562, 1, 512},
  {"512:_mm512_sub_ps(x, _mm512_xor_ps(x, y))", f563, 1, 512},
  {"512:_mm512_sub_ps(_mm512_xor_ps(x, y), x)", f564, 1, 512},
  {"512:_mm512_sub_ps(y, _mm512_xor_ps(x, y))", f565, 1, 512},
  {"512:_mm512_sub_ps(_mm512_andnot_ps(x, y), y)", f566, 1, 512},
  {"512:_mm512_sub_ps(x, _mm512_andnot_ps(x, y))", f567, 1, 512},
  {"512:_mm512_sub_ps(_mm512_andnot_ps(x, y), x)", f568, 1, 512},
  {"512:_mm512_sub_ps(y, _mm512_andnot_ps(x, y))", f569, 1, 512},
  {"512:_mm512_mul_ps(_mm512_add_ps(x, y), y)", f570, 1, 512},
  {"512:_mm512_mul_ps(x, _mm512_add_ps(x, y))", f571, 1, 512},
  {"512:_mm512_mul_ps(_mm512_add_ps(x, y), x)", f572, 1, 512},
  {"512:_mm512_mul_ps(y, _mm512_add_ps(x, y))", f573, 1, 512},
  {"512:_mm512_mul_ps(_mm512_sub_ps(x, y), y)", f574, 1, 512},
  {"512:_mm512_mul_ps(x, _mm512_sub_ps(x, y))", f575, 1, 512},
  {"512:_mm512_mul_ps(_mm512_sub_ps(x, y), x)", f576, 1, 512},
  {"512:_mm512_mul_ps(y, _mm512_sub_ps(x, y))", f577, 1, 512},
  {"512:_mm512_mul_ps(_mm512_mul_ps(x, y), y)", f578, 1, 512},
  {"512:_mm512_mul_ps(x, _mm512_mul_ps(x, y))", f579, 1, 512},
  {"512:_mm512_mul_ps(_mm512_mul_ps(x, y), x)", f580, 1, 512},
  {"512:_mm512_mul_ps(y, _mm512_mul_ps(x, y))", f581, 1, 512},
  {"512:_mm512_mul_ps(_mm512_div_ps(x, y), y)", f582, 1, 512},
  {"512:_mm512_mul_ps(x, _mm512_div_ps(x, y))", f583, 1, 512},
  {"512:_mm512_mul_ps(_mm512_div_ps(x, y), x)", f584, 1, 512},
  {"512:_mm512_mul_ps(y, _mm512_div_ps(x, y))", f585, 1, 512},
  {"512:_mm512_mul_ps(_mm512_min_ps(x, y), y)", f586, 1, 512},
  {"512:_mm512_mul_ps(x, _mm512_min_ps(x, y))", f587, 1, 512},
  {"512:_mm512_mul_ps(_mm512_min_ps(x, y), x)", f588, 1, 512},
  {"512:_mm512_mul_ps(y, _mm512_min_ps(x, y))", f589, 1, 512},
  {"512:_mm512_mul_ps(_mm512_max_ps(x, y), y)", f590, 1, 512},
  {"512:_mm512_mul_ps(x, _mm512_max_ps(x, y))", f591, 1, 512},
  {"512:_mm512_mul_ps(_mm512_max_ps(x, y), x)", f592, 1, 512},
  {"512:_mm512_mul_ps(y, _mm512_max_ps(x, y))", f593, 1, 512},
  {"512:_mm512_mul_ps(_mm512_and_ps(x, y), y)", f594, 1, 512},
  {"512:_mm512_mul_ps(x, _mm512_and_ps(x, y))", f595, 1, 512},
  {"512:_mm512_mul_ps(_mm512_and_ps(x, y), x)", f596, 1, 512},
  {"512:_mm512_mul_ps(y, _mm512_and_ps(x, y))", f597, 1, 512},
  {"512:_mm512_mul_ps(_mm512_or_ps(x, y), y)", f598, 1, 512},
  {"512:_mm512_mul_ps(x, _mm512_or_ps(x, y))", f599, 1, 512},
  {"512:_mm512_mul_ps(_mm512_or_ps(x, y), x)", f600, 1, 512},
  {"512:_mm512_mul_ps(y, _mm512_or_ps(x, y))", f601, 1, 512},
  {"512:_mm512_mul_ps(_mm512_xor_ps(x, y), y)", f602, 1, 512},
  {"512:_mm512_mul_ps(x, _mm512_xor_ps(x, y))", f603, 1, 512},
  {"512:_mm512_mul_ps(_mm512_xor_ps(x, y), x)", f604, 1, 512},
  {"512:_mm512_mul_ps(y, _mm512_xor_ps(x, y))", f605, 1, 512},
  {"512:_mm512_mul_ps(_mm512_andnot_ps(x, y), y)", f606, 1, 512},
  {"512:_mm512_mul_ps(x, _mm512_andnot_ps(x, y))", f607, 1, 512},
  {"512:_mm512_mul_ps(_mm512_andnot_ps(x, y), x)", f608, 1, 512},
  {"512:_mm512_mul_ps(y, _mm512_andnot_ps(x, y))", f609, 1, 512},
  {"512:_mm512_div_ps(_mm512_add_ps(x, y), y)", f610, 1, 512},
  {"512:_mm512_div_ps(x, _mm512_add_ps(x, y))", f611, 1, 512},
  {"512:_mm512_div_ps(_mm512_add_ps(x, y), x)", f612, 1, 512},
  {"512:_mm512_div_ps(y, _mm512_add_ps(x, y))", f613, 1, 512},
  {"512:_mm512_div_ps(_mm512_sub_ps(x, y), y)", f614, 1, 512},
  {"512:_mm512_div_ps(x, _mm512_sub_ps(x, y))", f615, 1, 512},
  {"512:_mm512_div_ps(_mm512_sub_ps(x, y), x)", f616, 1, 512},
  {"512:_mm512_div_ps(y, _mm512_sub_ps(x, y))", f617, 1, 512},
  {"512:_mm512_div_ps(_mm512_mul_ps(x, y), y)", f618, 1, 512},
  {"512:_mm512_div_ps(x, _mm512_mul_ps(x, y))", f619, 1, 512},
  {"512:_mm512_div_ps(_mm512_mul_ps(x, y), x)", f620, 1, 512},
  {"512:_mm512_div_ps(y, _mm512_mul_ps(x, y))", f621, 1, 512},
  {"512:_mm512_div_ps(_mm512_div_ps(x, y), y)", f622, 1, 512},
  {"512:_mm512_div_ps(x, _mm512_div_ps(x, y))", f623, 1, 512},
  {"512:_mm512_div_ps(_mm512_div_ps(x, y), x)", f624, 1, 512},
  {"512:_mm512_div_ps(y, _mm512_div_ps(x, y))", f625, 1, 512},
  {"512:_mm512_div_ps(_mm512_min_ps(x, y), y)", f626, 1, 512},
  {"512:_mm512_div_ps(x, _mm512_min_ps(x, y))", f627, 1, 512},
  {"512:_mm512_div_ps(_mm512_min_ps(x, y), x)", f628, 1, 512},
  {"512:_mm512_div_ps(y, _mm512_min_ps(x, y))", f629, 1, 512},
  {"512:_mm512_div_ps(_mm512_max_ps(x, y), y)", f630, 1, 512},
  {"512:_mm512_div_ps(x, _mm512_max_ps(x, y))", f631, 1, 512},
  {"512:_mm512_div_ps(_mm512_max_ps(x, y), x)", f632, 1, 512},
  {"512:_mm512_div_ps(y, _mm512_max_ps(x, y))", f633, 1, 512},
  {"512:_mm512_div_ps(_mm512_and_ps(x, y), y)", f634, 1, 512},
  {"512:_mm512_div_ps(x, _mm512_and_ps(x, y))", f635, 1, 512},
  {"512:_mm512_div_ps(_mm512_and_ps(x, y), x)", f636, 1, 512},
  {"512:_mm512_div_ps(y, _mm512_and_ps(x, y))", f637, 1, 512},
  {"512:_mm512_div_ps(_mm512_or_ps(x, y), y)", f638, 1, 512},
  {"512:_mm512_div_ps(x, _mm512_or_ps(x, y))", f639, 1, 512},
  {"512:_mm512_div_ps(_mm512_or_ps(x, y), x)", f640, 1, 512},
  {"512:_mm512_div_ps(y, _mm512_or_ps(x, y))", f641, 1, 512},
  {"512:_mm512_div_ps(_mm512_xor_ps(x, y), y)", f642, 1, 512},
  {"512:_mm512_div_ps(x, _mm512_xor_ps(x, y))", f643, 1, 512},
  {"512:_mm512_div_ps(_mm512_xor_ps(x, y), x)", f644, 1, 512},
  {"512:_mm512_div_ps(y, _mm512_xor_ps(x, y))", f645, 1, 512},
  {"512:_mm512_div_ps(_mm512_andnot_ps(x, y), y)", f646, 1, 512},
  {"512:_mm512_div_ps(x, _mm512_andnot_ps(x, y))", f647, 1, 512},
  {"512:_mm512_div_ps(_mm512_andnot_ps(x, y), x)", f648, 1, 512},
  {"512:_mm512_div_ps(y, _mm512_andnot_ps(x, y))", f649, 1, 512},
  {"512:_mm512_min_ps(_mm512_add_ps(x, y), y)", f650, 1, 512},
  {"512:_mm512_min_ps(x, _mm512_add_ps(x, y))", f651, 1, 512},
  {"512:_mm512_min_ps(_mm512_add_ps(x, y), x)", f652, 1, 512},
  {"512:_mm512_min_ps(y, _mm512_add_ps(x, y))", f653, 1, 512},
  {"512:_mm512_min_ps(_mm512_sub_ps(x, y), y)", f654, 1, 512},
  {"512:_mm512_min_ps(x, _mm512_sub_ps(x, y))", f655, 1, 512},
  {"512:_mm512_min_ps(_mm512_sub_ps(x, y), x)", f656, 1, 512},
  {"512:_mm512_min_ps(y, _mm512_sub_ps(x, y))", f657, 1, 512},
  {"512:_mm512_min_ps(_mm512_mul_ps(x, y), y)", f658, 1, 512},
  {"512:_mm512_min_ps(x, _mm512_mul_ps(x, y))", f659, 1, 512},
  {"512:_mm512_min_ps(_mm512_mul_ps(x, y), x)", f660, 1, 512},
  {"512:_mm512_min_ps(y, _mm512_mul_ps(x, y))", f661, 1, 512},
  {"512:_mm512_min_ps(_mm512_div_ps(x, y), y)", f662, 1, 512},
  {"512:_mm512_min_ps(x, _mm512_div_ps(x, y))", f663, 1, 512},
  {"512:_mm512_min_ps(_mm512_div_ps(x, y), x)", f664, 1, 512},
  {"512:_mm512_min_ps(y, _mm512_div_ps(x, y))", f665, 1, 512},
  {"512:_mm512_min_ps(_mm512_min_ps(x, y), y)", f666, 1, 512},
  {"512:_mm512_min_ps(x, _mm512_min_ps(x, y))", f667, 1, 512},
  {"512:_mm512_min_ps(_mm512_min_ps(x, y), x)", f668, 1, 512},
  {"512:_mm512_min_ps(y, _mm512_min_ps(x, y))", f669, 1, 512},
  {"512:_mm512_min_ps(_mm512_max_ps(x, y), y)", f670, 1, 512},
  {"512:_mm512_min_ps(x, _mm512_max_ps(x, y))", f671, 1, 512},
  {"512:_mm512_min_ps(_mm512_max_ps(x, y), x)", f672, 1, 512},
  {"512:_mm512_min_ps(y, _mm512_max_ps(x, y))", f673, 1, 512},
  {"512:_mm512_min_ps(_mm512_and_ps(x, y), y)", f674, 1, 512},
  {"512:_mm512_min_ps(x, _mm512_and_ps(x, y))", f675, 1, 512},
  {"512:_mm512_min_ps(_mm512_and_ps(x, y), x)", f676, 1, 512},
  {"512:_mm512_min_ps(y, _mm512_and_ps(x, y))", f677, 1, 512},
  {"512:_mm512_min_ps(_mm512_or_ps(x, y), y)", f678, 1, 512},
  {"512:_mm512_min_ps(x, _mm512_or_ps(x, y))", f679, 1, 512},
  {"512:_mm512_min_ps(_mm512_or_ps(x, y), x)", f680, 1, 512},
  {"512:_mm512_min_ps(y, _mm512_or_ps(x, y))", f681, 1, 512},
  {"512:_mm512_min_ps(_mm512_xor_ps(x, y), y)", f682, 1, 512},
  {"512:_mm512_min_ps(x, _mm512_xor_ps(x, y))", f683, 1, 512},
  {"512:_mm512_min_ps(_mm512_xor_ps(x, y), x)", f684, 1, 512},
  {"512:_mm512_min_ps(y, _mm512_xor_ps(x, y))", f685, 1, 512},
  {"512:_mm512_min_ps(_mm512_andnot_ps(x, y), y)", f686, 1, 512},
  {"512:_mm512_min_ps(x, _mm512_andnot_ps(x, y))", f687, 1, 512},
  {"512:_mm512_min_ps(_mm512_andnot_ps(x, y), x)", f688, 1, 512},
  {"512:_mm512_min_ps(y, _mm512_andnot_ps(x, y))", f689, 1, 512},
  {"512:_mm512_max_ps(_mm512_add_ps(x, y), y)", f690, 1, 512},
  {"512:_mm512_max_ps(x, _mm512_add_ps(x, y))", f691, 1, 512},
  {"512:_mm512_max_ps(_mm512_add_ps(x, y), x)", f692, 1, 512},
  {"512:_mm512_max_ps(y, _mm512_add_ps(x, y))", f693, 1, 512},
  {"512:_mm512_max_ps(_mm512_sub_ps(x, y), y)", f694, 1, 512},
  {"512:_mm512_max_ps(x, _mm512_sub_ps(x, y))", f695, 1, 512},
  {"512:_mm512_max_ps(_mm512_sub_ps(x, y), x)", f696, 1, 512},
  {"512:_mm512_max_ps(y, _mm512_sub_ps(x, y))", f697, 1, 512},
  {"512:_mm512_max_ps(_mm512_mul_ps(x, y), y)", f698, 1, 512},
  {"512:_mm512_max_ps(x, _mm512_mul_ps(x, y))", f699, 1, 512},
  {"512:_mm512_max_ps(_mm512_mul_ps(x, y), x)", f700, 1, 512},
  {"512:_mm512_max_ps(y, _mm512_mul_ps(x, y))", f701, 1, 512},
  {"512:_mm512_max_ps(_mm512_div_ps(x, y), y)", f702, 1, 512},
  {"512:_mm512_max_ps(x, _mm512_div_ps(x, y))", f703, 1, 512},
  {"512:_mm512_max_ps(_mm512_div_ps(x, y), x)", f704, 1, 512},
  {"512:_mm512_max_ps(y, _mm512_div_ps(x, y))", f705, 1, 512},
  {"512:_mm512_max_ps(_mm512_min_ps(x, y), y)", f706, 1, 512},
  {"512:_mm512_max_ps(x, _mm512_min_ps(x, y))", f707, 1, 512},
  {"512:_mm512_max_ps(_mm512_min_ps(x, y), x)", f708, 1, 512},
  {"512:_mm512_max_ps(y, _mm512_min_ps(x, y))", f709, 1, 512},
  {"512:_mm512_max_ps(_mm512_max_ps(x, y), y)", f710, 1, 512},
  {"512:_mm512_max_ps(x, _mm512_max_ps(x, y))", f711, 1, 512},
  {"512:_mm512_max_ps(_mm512_max_ps(x, y), x)", f712, 1, 512},
  {"512:_mm512_max_ps(y, _mm512_max_ps(x, y))", f713, 1, 512},
  {"512:_mm512_max_ps(_mm512_and_ps(x, y), y)", f714, 1, 512},
  {"512:_mm512_max_ps(x, _mm512_and_ps(x, y))", f715, 1, 512},
  {"512:_mm512_max_ps(_mm512_and_ps(x, y), x)", f716, 1, 512},
  {"512:_mm512_max_ps(y, _mm512_and_ps(x, y))", f717, 1, 512},
  {"512:_mm512_max_ps(_mm512_or_ps(x, y), y)", f718, 1, 512},
  {"512:_mm512_max_ps(x, _mm512_or_ps(x, y))", f719, 1, 512},
  {"512:_mm512_max_ps(_mm512_or_ps(x, y), x)", f720, 1, 512},
  {"512:_mm512_max_ps(y, _mm512_or_ps(x, y))", f721, 1, 512},
  {"512:_mm512_max_ps(_mm512_xor_ps(x, y), y)", f722, 1, 512},
  {"512:_mm512_max_ps(x, _mm512_xor_ps(x, y))", f723, 1, 512},
  {"512:_mm512_max_ps(_mm512_xor_ps(x, y), x)", f724, 1, 512},
  {"512:_mm512_max_ps(y, _mm512_xor_ps(x, y))", f725, 1, 512},
  {"512:_mm512_max_ps(_mm512_andnot_ps(x, y), y)", f726, 1, 512},
  {"512:_mm512_max_ps(x, _mm512_andnot_ps(x, y))", f727, 1, 512},
  {"512:_mm512_max_ps(_mm512_andnot_ps(x, y), x)", f728, 1, 512},
  {"512:_mm512_max_ps(y, _mm512_andnot_ps(x, y))", f729, 1, 512},
  {"512:_mm512_and_ps(_mm512_add_ps(x, y), y)", f730, 1, 512},
  {"512:_mm512_and_ps(x, _mm512_add_ps(x, y))", f731, 1, 512},
  {"512:_mm512_and_ps(_mm512_add_ps(x, y), x)", f732, 1, 512},
  {"512:_mm512_and_ps(y, _mm512_add_ps(x, y))", f733, 1, 512},
  {"512:_mm512_and_ps(_mm512_sub_ps(x, y), y)", f734, 1, 512},
  {"512:_mm512_and_ps(x, _mm512_sub_ps(x, y))", f735, 1, 512},
  {"512:_mm512_and_ps(_mm512_sub_ps(x, y), x)", f736, 1, 512},
  {"512:_mm512_and_ps(y, _mm512_sub_ps(x, y))", f737, 1, 512},
  {"512:_mm512_and_ps(_mm512_mul_ps(x, y), y)", f738, 1, 512},
  {"512:_mm512_and_ps(x, _mm512_mul_ps(x, y))", f739, 1, 512},
  {"512:_mm512_and_ps(_mm512_mul_ps(x, y), x)", f740, 1, 512},
  {"512:_mm512_and_ps(y, _mm512_mul_ps(x, y))", f741, 1, 512},
  {"512:_mm512_and_ps(_mm512_div_ps(x, y), y)", f742, 1, 512},
  {"512:_mm512_and_ps(x, _mm512_div_ps(x, y))", f743, 1, 512},
  {"512:_mm512_and_ps(_mm512_div_ps(x, y), x)", f744, 1, 512},
  {"512:_mm512_and_ps(y, _mm512_div_ps(x, y))", f745, 1, 512},
  {"512:_mm512_and_ps(_mm512_min_ps(x, y), y)", f746, 1, 512},
  {"512:_mm512_and_ps(x, _mm512_min_ps(x, y))", f747, 1, 512},
  {"512:_mm512_and_ps(_mm512_min_ps(x, y), x)", f748, 1, 512},
  {"512:_mm512_and_ps(y, _mm512_min_ps(x, y))", f749, 1, 512},
  {"512:_mm512_and_ps(_mm512_max_ps(x, y), y)", f750, 1, 512},
  {"512:_mm512_and_ps(x, _mm512_max_ps(x, y))", f751, 1, 512},
  {"512:_mm512_and_ps(_mm512_max_ps(x, y), x)", f752, 1, 512},
  {"512:_mm512_and_ps(y, _mm512_max_ps(x, y))", f753, 1, 512},
  {"512:_mm512_and_ps(_mm512_and_ps(x, y), y)", f754, 1, 512},
  {"512:_mm512_and_ps(x, _mm512_and_ps(x, y))", f755, 1, 512},
  {"512:_mm512_and_ps(_mm512_and_ps(x, y), x)", f756, 1, 512},
  {"512:_mm512_and_ps(y, _mm512_and_ps(x, y))", f757, 1, 512},
  {"512:_mm512_and_ps(_mm512_or_ps(x, y), y)", f758, 1, 512},
  {"512:_mm512_and_ps(x, _mm512_or_ps(x, y))", f759, 1, 512},
  {"512:_mm512_and_ps(_mm512_or_ps(x, y), x)", f760, 1, 512},
  {"512:_mm512_and_ps(y, _mm512_or_ps(x, y))", f761, 1, 512},
  {"512:_mm512_and_ps(_mm512_xor_ps(x, y), y)", f762, 1, 512},
  {"512:_mm512_and_ps(x, _mm512_xor_ps(x, y))", f763, 1, 512},
  {"512:_mm512_and_ps(_mm512_xor_ps(x, y), x)", f764, 1, 512},
  {"512:_mm512_and_ps(y, _mm512_xor_ps(x, y))", f765, 1, 512},
  {"512:_mm512_and_ps(_mm512_andnot_ps(x, y), y)", f766, 1, 512},
  {"512:_mm512_and_ps(x, _mm512_andnot_ps(x, y))", f767, 1, 512},
  {"512:_mm512_and_ps(_mm512_andnot_ps(x, y), x)", f768, 1, 512},
  {"512:_mm512_and_ps(y, _mm512_andnot_ps(x, y))", f769, 1, 512},
  {"512:_mm512_or_ps(_mm512_add_ps(x, y), y)", f770, 1, 512},
  {"512:_mm512_or_ps(x, _mm512_add_ps(x, y))", f771, 1, 512},
  {"512:_mm512_or_ps(_mm512_add_ps(x, y), x)", f772, 1, 512},
  {"512:_mm512_or_ps(y, _mm512_add_ps(x, y))", f773, 1, 512},
  {"512:_mm512_or_ps(_mm512_sub_ps(x, y), y)", f774, 1, 512},
  {"512:_mm512_or_ps(x, _mm512_sub_ps(x, y))", f775, 1, 512},
  {"512:_mm512_or_ps(_mm512_sub_ps(x, y), x)", f776, 1, 512},
  {"512:_mm512_or_ps(y, _mm512_sub_ps(x, y))", f777, 1, 512},
  {"512:_mm512_or_ps(_mm512_mul_ps(x, y), y)", f778, 1, 512},
  {"512:_mm512_or_ps(x, _mm512_mul_ps(x, y))", f779, 1, 512},
  {"512:_mm512_or_ps(_mm512_mul_ps(x, y), x)", f780, 1, 512},
  {"512:_mm512_or_ps(y, _mm512_mul_ps(x, y))", f781, 1, 512},
  {"512:_mm512_or_ps(_mm512_div_ps(x, y), y)", f782, 1, 512},
  {"512:_mm512_or_ps(x, _mm512_div_ps(x, y))", f783, 1, 512},
  {"512:_mm512_or_ps(_mm512_div_ps(x, y), x)", f784, 1, 512},
  {"512:_mm512_or_ps(y, _mm512_div_ps(x, y))", f785, 1, 512},
  {"512:_mm512_or_ps(_mm512_min_ps(x, y), y)", f786, 1, 512},
  {"512:_mm512_or_ps(x, _mm512_min_ps(x, y))", f787, 1, 512},
  {"512:_mm512_or_ps(_mm512_min_ps(x, y), x)", f788, 1, 512},
  {"512:_mm512_or_ps(y, _mm512_min_ps(x, y))", f789, 1, 512},
  {"512:_mm512_or_ps(_mm512_max_ps(x, y), y)", f790, 1, 512},
  {"512:_mm512_or_ps(x, _mm512_max_ps(x, y))", f791, 1, 512},
  {"512:_mm512_or_ps(_mm512_max_ps(x, y), x)", f792, 1, 512},
  {"512:_mm512_or_ps(y, _mm512_max_ps(x, y))", f793, 1, 512},
  {"512:_mm512_or_ps(_mm512_and_ps(x, y), y)", f794, 1, 512},
  {"512:_mm512_or_ps(x, _mm512_and_ps(x, y))", f795, 1, 512},
  {"512:_mm512_or_ps(_mm512_and_ps(x, y), x)", f796, 1, 512},
  {"512:_mm512_or_ps(y, _mm512_and_ps(x, y))", f797, 1, 512},
  {"512:_mm512_or_ps(_mm512_or_ps(x, y), y)", f798, 1, 512},
  {"512:_mm512_or_ps(x, _mm512_or_ps(x, y))", f799, 1, 512},
  {"512:_mm512_or_ps(_mm512_or_ps(x, y), x)", f800, 1, 512},
  {"512:_mm512_or_ps(y, _mm512_or_ps(x, y))", f801, 1, 512},
  {"512:_mm512_or_ps(_mm512_xor_ps(x, y), y)", f802, 1, 512},
  {"512:_mm512_or_ps(x, _mm512_xor_ps(x, y))", f803, 1, 512},
  {"512:_mm512_or_ps(_mm512_xor_ps(x, y), x)", f804, 1, 512},
  {"512:_mm512_or_ps(y, _mm512_xor_ps(x, y))", f805, 1, 512},
  {"512:_mm512_or_ps(_mm512_andnot_ps(x, y), y)", f806, 1, 512},
  {"512:_mm512_or_ps(x, _mm512_andnot_ps(x, y))", f807, 1, 512},
  {"512:_mm512_or_ps(_mm512_andnot_ps(x, y), x)", f808, 1, 512},
  {"512:_mm512_or_ps(y, _mm512_andnot_ps(x, y))", f809, 1, 512},
  {"512:_mm512_xor_ps(_mm512_add_ps(x, y), y)", f810, 1, 512},
  {"512:_mm512_xor_ps(x, _mm512_add_ps(x, y))", f811, 1, 512},
  {"512:_mm512_xor_ps(_mm512_add_ps(x, y), x)", f812, 1, 512},
  {"512:_mm512_xor_ps(y, _mm512_add_ps(x, y))", f813, 1, 512},
  {"512:_mm512_xor_ps(_mm512_sub_ps(x, y), y)", f814, 1, 512},
  {"512:_mm512_xor_ps(x, _mm512_sub_ps(x, y))", f815, 1, 512},
  {"512:_mm512_xor_ps(_mm512_sub_ps(x, y), x)", f816, 1, 512},
  {"512:_mm512_xor_ps(y, _mm512_sub_ps(x, y))", f817, 1, 512},
  {"512:_mm512_xor_ps(_mm512_mul_ps(x, y), y)", f818, 1, 512},
  {"512:_mm512_xor_ps(x, _mm512_mul_ps(x, y))", f819, 1, 512},
  {"512:_mm512_xor_ps(_mm512_mul_ps(x, y), x)", f820, 1, 512},
  {"512:_mm512_xor_ps(y, _mm512_mul_ps(x, y))", f821, 1, 512},
  {"512:_mm512_xor_ps(_mm512_div_ps(x, y), y)", f822, 1, 512},
  {"512:_mm512_xor_ps(x, _mm512_div_ps(x, y))", f823, 1, 512},
  {"512:_mm512_xor_ps(_mm512_div_ps(x, y), x)", f824, 1, 512},
  {"512:_mm512_xor_ps(y, _mm512_div_ps(x, y))", f825, 1, 512},
  {"512:_mm512_xor_ps(_mm512_min_ps(x, y), y)", f826, 1, 512},
  {"512:_mm512_xor_ps(x, _mm512_min_ps(x, y))", f827, 1, 512},
  {"512:_mm512_xor_ps(_mm512_min_ps(x, y), x)", f828, 1, 512},
  {"512:_mm512_xor_ps(y, _mm512_min_ps(x, y))", f829, 1, 512},
  {"512:_mm512_xor_ps(_mm512_max_ps(x, y), y)", f830, 1, 512},
  {"512:_mm512_xor_ps(x, _mm512_max_ps(x, y))", f831, 1, 512},
  {"512:_mm512_xor_ps(_mm512_max_ps(x, y), x)", f832, 1, 512},
  {"512:_mm512_xor_ps(y, _mm512_max_ps(x, y))", f833, 1, 512},
  {"512:_mm512_xor_ps(_mm512_and_ps(x, y), y)", f834, 1, 512},
  {"512:_mm512_xor_ps(x, _mm512_and_ps(x, y))", f835, 1, 512},
  {"512:_mm512_xor_ps(_mm512_and_ps(x, y), x)", f836, 1, 512},
  {"512:_mm512_xor_ps(y, _mm512_and_ps(x, y))", f837, 1, 512},
  {"512:_mm512_xor_ps(_mm512_or_ps(x, y), y)", f838, 1, 512},
  {"512:_mm512_xor_ps(x, _mm512_or_ps(x, y))", f839, 1, 512},
  {"512:_mm512_xor_ps(_mm512_or_ps(x, y), x)", f840, 1, 512},
  {"512:_mm512_xor_ps(y, _mm512_or_ps(x, y))", f841, 1, 512},
  {"512:_mm512_xor_ps(_mm512_xor_ps(x, y), y)", f842, 1, 512},
  {"512:_mm512_xor_ps(x, _mm512_xor_ps(x, y))", f843, 1, 512},
  {"512:_mm512_xor_ps(_mm512_xor_ps(x, y), x)", f844, 1, 512},
  {"512:_mm512_xor_ps(y, _mm512_xor_ps(x, y))", f845, 1, 512},
  {"512:_mm512_xor_ps(_mm512_andnot_ps(x, y), y)", f846, 1, 512},
  {"512:_mm512_xor_ps(x, _mm512_andnot_ps(x, y))", f847, 1, 512},
  {"512:_mm512_xor_ps(_mm512_andnot_ps(x, y), x)", f848, 1, 512},
  {"512:_mm512_xor_ps(y, _mm512_andnot_ps(x, y))", f849, 1, 512},
  {"512:_mm512_andnot_ps(_mm512_add_ps(x, y), y)", f850, 1, 512},
  {"512:_mm512_andnot_ps(x, _mm512_add_ps(x, y))", f851, 1, 512},
  {"512:_mm512_andnot_ps(_mm512_add_ps(x, y), x)", f852, 1, 512},
  {"512:_mm512_andnot_ps(y, _mm512_add_ps(x, y))", f853, 1, 512},
  {"512:_mm512_andnot_ps(_mm512_sub_ps(x, y), y)", f854, 1, 512},
  {"512:_mm512_andnot_ps(x, _mm512_sub_ps(x, y))", f855, 1, 512},
  {"512:_mm512_andnot_ps(_mm512_sub_ps(x, y), x)", f856, 1, 512},
  {"512:_mm512_andnot_ps(y, _mm512_sub_ps(x, y))", f857, 1, 512},
  {"512:_mm512_andnot_ps(_mm512_mul_ps(x, y), y)", f858, 1, 512},
  {"512:_mm512_andnot_ps(x, _mm512_mul_ps(x, y))", f859, 1, 512},
  {"512:_mm512_andnot_ps(_mm512_mul_ps(x, y), x)", f860, 1, 512},
  {"512:_mm512_andnot_ps(y, _mm512_mul_ps(x, y))", f861, 1, 512},
  {"512:_mm512_andnot_ps(_mm512_div_ps(x, y), y)", f862, 1, 512},
  {"512:_mm512_andnot_ps(x, _mm512_div_ps(x, y))", f863, 1, 512},
  {"512:_mm512_andnot_ps(_mm512_div_ps(x, y), x)", f864, 1, 512},
  {"512:_mm512_andnot_ps(y, _mm512_div_ps(x, y))", f865, 1, 512},
  {"512:_mm512_andnot_ps(_mm512_min_ps(x, y), y)", f866, 1, 512},
  {"512:_mm512_andnot_ps(x, _mm512_min_ps(x, y))", f867, 1, 512},
  {"512:_mm512_andnot_ps(_mm512_min_ps(x, y), x)", f868, 1, 512},
  {"512:_mm512_andnot_ps(y, _mm512_min_ps(x, y))", f869, 1, 512},
  {"512:_mm512_andnot_ps(_mm512_max_ps(x, y), y)", f870, 1, 512},
  {"512:_mm512_andnot_ps(x, _mm512_max_ps(x, y))", f871, 1, 512},
  {"512:_mm512_andnot_ps(_mm512_max_ps(x, y), x)", f872, 1, 512},
  {"512:_mm512_andnot_ps(y, _mm512_max_ps(x, y))", f873, 1, 512},
  {"512:_mm512_andnot_ps(_mm512_and_ps(x, y), y)", f874, 1, 512},
  {"512:_mm512_andnot_ps(x, _mm512_and_ps(x, y))", f875, 1, 512},
  {"512:_mm512_andnot_ps(_mm512_and_ps(x, y), x)", f876, 1, 512},
  {"512:_mm512_andnot_ps(y, _mm512_and_ps(x, y))", f877, 1, 512},
  {"512:_mm512_andnot_ps(_mm512_or_ps(x, y), y)", f878, 1, 512},
  {"512:_mm512_andnot_ps(x, _mm512_or_ps(x, y))", f879, 1, 512},
  {"512:_mm512_andnot_ps(_mm512_or_ps(x, y), x)", f880, 1, 512},
  {"512:_mm512_andnot_ps(y, _mm512_or_ps(x, y))", f881, 1, 512},
  {"512:_mm512_andnot_ps(_mm512_xor_ps(x, y), y)", f882, 1, 512},
  {"512:_mm512_andnot_ps(x, _mm512_xor_ps(x, y))", f883, 1, 512},
  {"512:_mm512_andnot_ps(_mm512_xor_ps(x, y), x)", f884, 1, 512},
  {"512:_mm512_andnot_ps(y, _mm512_xor_ps(x, y))", f885, 1, 512},
  {"512:_mm512_andnot_ps(_mm512_andnot_ps(x, y), y)", f886, 1, 512},
  {"512:_mm512_andnot_ps(x, _mm512_andnot_ps(x, y))", f887, 1, 512},
  {"512:_mm512_andnot_ps(_mm512_andnot_ps(x, y), x)", f888, 1, 512},
  {"512:_mm512_andnot_ps(y, _mm512_andnot_ps(x, y))", f889, 1, 512},
  {"512:_mm512_sqrt_pd(_mm512_sqrt_pd(x))", f890, 2, 512},
  {"512:_mm512_sqrt_pd(_mm512_xor_pd(x, _mm512_set1_pd(-0.0)))", f891, 2, 512},
  {"512:_mm512_sqrt_pd(_mm512_andnot_pd(_mm512_set1_pd(-0.0), x))", f892, 2, 512},
  {"512:_mm512_sqrt_pd(_mm512_sub_pd(_mm512_setzero_pd(), x))", f893, 2, 512},
  {"512:_mm512_sqrt_pd(_mm512_mul_pd(x, _mm512_set1_pd(-1.0)))", f894, 2, 512},
  {"512:_mm512_sqrt_pd(_mm512_roundscale_pd(x, 1 | _MM_FROUND_NO_EXC))", f895, 2, 512},
  {"512:_mm512_sqrt_pd(_mm512_roundscale_pd(x, 2 | _MM_FROUND_NO_EXC))", f896, 2, 512},
  {"512:_mm512_sqrt_pd(_mm512_roundscale_pd(x, 0 | _MM_FROUND_NO_EXC))", f897, 2, 512},
  {"512:_mm512_xor_pd(_mm512_sqrt_pd(x), _mm512_set1_pd(-0.0))", f898, 2, 512},
  {"512:_mm512_xor_pd(_mm512_xor_pd(x, _mm512_set1_pd(-0.0)), _mm512_set1_pd(-0.0))", f899, 2, 512},
  {"512:_mm512_xor_pd(_mm512_andnot_pd(_mm512_set1_pd(-0.0), x), _mm512_set1_pd(-0.0))", f900, 2, 512},
  {"512:_mm512_xor_pd(_mm512_sub_pd(_mm512_setzero_pd(), x), _mm512_set1_pd(-0.0))", f901, 2, 512},
  {"512:_mm512_xor_pd(_mm512_mul_pd(x, _mm512_set1_pd(-1.0)), _mm512_set1_pd(-0.0))", f902, 2, 512},
  {"512:_mm512_xor_pd(_mm512_roundscale_pd(x, 1 | _MM_FROUND_NO_EXC), _mm512_set1_pd(-0.0))", f903, 2, 512},
  {"512:_mm512_xor_pd(_mm512_roundscale_pd(x, 2 | _MM_FROUND_NO_EXC), _mm512_set1_pd(-0.0))", f904, 2, 512},
  {"512:_mm512_xor_pd(_mm512_roundscale_pd(x, 0 | _MM_FROUND_NO_EXC), _mm512_set1_pd(-0.0))", f905, 2, 512},
  {"512:_mm512_andnot_pd(_mm512_set1_pd(-0.0), _mm512_sqrt_pd(x))", f906, 2, 512},
  {"512:_mm512_andnot_pd(_mm512_set1_pd(-0.0), _mm512_xor_pd(x, _mm512_set1_pd(-0.0)))", f907, 2, 512},
  {"512:_mm512_andnot_pd(_mm512_set1_pd(-0.0), _mm512_andnot_pd(_mm512_set1_pd(-0.0), x))", f908, 2, 512},
  {"512:_mm512_andnot_pd(_mm512_set1_pd(-0.0), _mm512_sub_pd(_mm512_setzero_pd(), x))", f909, 2, 512},
  {"512:_mm512_andnot_pd(_mm512_set1_pd(-0.0), _mm512_mul_pd(x, _mm512_set1_pd(-1.0)))", f910, 2, 512},
  {"512:_mm512_andnot_pd(_mm512_set1_pd(-0.0), _mm512_roundscale_pd(x, 1 | _MM_FROUND_NO_EXC))", f911, 2, 512},
  {"512:_mm512_andnot_pd(_mm512_set1_pd(-0.0), _mm512_roundscale_pd(x, 2 | _MM_FROUND_NO_EXC))", f912, 2, 512},
  {"512:_mm512_andnot_pd(_mm512_set1_pd(-0.0), _mm512_roundscale_pd(x, 0 | _MM_FROUND_NO_EXC))", f913, 2, 512},
  {"512:_mm512_sub_pd(_mm512_setzero_pd(), _mm512_sqrt_pd(x))", f914, 2, 512},
  {"512:_mm512_sub_pd(_mm512_setzero_pd(), _mm512_xor_pd(x, _mm512_set1_pd(-0.0)))", f915, 2, 512},
  {"512:_mm512_sub_pd(_mm512_setzero_pd(), _mm512_andnot_pd(_mm512_set1_pd(-0.0), x))", f916, 2, 512},
  {"512:_mm512_sub_pd(_mm512_setzero_pd(), _mm512_sub_pd(_mm512_setzero_pd(), x))", f917, 2, 512},
  {"512:_mm512_sub_pd(_mm512_setzero_pd(), _mm512_mul_pd(x, _mm512_set1_pd(-1.0)))", f918, 2, 512},
  {"512:_mm512_sub_pd(_mm512_setzero_pd(), _mm512_roundscale_pd(x, 1 | _MM_FROUND_NO_EXC))", f919, 2, 512},
  {"512:_mm512_sub_pd(_mm512_setzero_pd(), _mm512_roundscale_pd(x, 2 | _MM_FROUND_NO_EXC))", f920, 2, 512},
  {"512:_mm512_sub_pd(_mm512_setzero_pd(), _mm512_roundscale_pd(x, 0 | _MM_FROUND_NO_EXC))", f921, 2, 512},
  {"512:_mm512_mul_pd(_mm512_sqrt_pd(x), _mm512_set1_pd(-1.0))", f922, 2, 512},
  {"512:_mm512_mul_pd(_mm512_xor_pd(x, _mm512_set1_pd(-0.0)), _mm512_set1_pd(-1.0))", f923, 2, 512},
  {"512:_mm512_mul_pd(_mm512_andnot_pd(_mm512_set1_pd(-0.0), x), _mm512_set1_pd(-1.0))", f924, 2, 512},
  {"512:_mm512_mul_pd(_mm512_sub_pd(_mm512_setzero_pd(), x), _mm512_set1_pd(-1.0))", f925, 2, 512},
  {"512:_mm512_mul_pd(_mm512_mul_pd(x, _mm512_set1_pd(-1.0)), _mm512_set1_pd(-1.0))", f926, 2, 512},
  {"512:_mm512_mul_pd(_mm512_roundscale_pd(x, 1 | _MM_FROUND_NO_EXC), _mm512_set1_pd(-1.0))", f927, 2, 512},
  {"512:_mm512_mul_pd(_mm512_roundscale_pd(x, 2 | _MM_FROUND_NO_EXC), _mm512_set1_pd(-1.0))", f928, 2, 512},
  {"512:_mm512_mul_pd(_mm512_roundscale_pd(x, 0 | _MM_FROUND_NO_EXC), _mm512_set1_pd(-1.0))", f929, 2, 512},
  {"512:_mm512_roundscale_pd(_mm512_sqrt_pd(x), 1 | _MM_FROUND_NO_EXC)", f930, 2, 512},
  {"512:_mm512_roundscale_pd(_mm512_xor_pd(x, _mm512_set1_pd(-0.0)), 1 | _MM_FROUND_NO_EXC)", f931, 2, 512},
  {"512:_mm512_roundscale_pd(_mm512_andnot_pd(_mm512_set1_pd(-0.0), x), 1 | _MM_FROUND_NO_EXC)", f932, 2, 512},
  {"512:_mm512_roundscale_pd(_mm512_sub_pd(_mm512_setzero_pd(), x), 1 | _MM_FROUND_NO_EXC)", f933, 2, 512},
  {"512:_mm512_roundscale_pd(_mm512_mul_pd(x, _mm512_set1_pd(-1.0)), 1 | _MM_FROUND_NO_EXC)", f934, 2, 512},
  {"512:_mm512_roundscale_pd(_mm512_roundscale_pd(x, 1 | _MM_FROUND_NO_EXC), 1 | _MM_FROUND_NO_EXC)", f935, 2, 512},
  {"512:_mm512_roundscale_pd(_mm512_roundscale_pd(x, 2 | _MM_FROUND_NO_EXC), 1 | _MM_FROUND_NO_EXC)", f936, 2, 512},
  {"512:_mm512_roundscale_pd(_mm512_roundscale_pd(x, 0 | _MM_FROUND_NO_EXC), 1 | _MM_FROUND_NO_EXC)", f937, 2, 512},
  {"512:_mm512_roundscale_pd(_mm512_sqrt_pd(x), 2 | _MM_FROUND_NO_EXC)", f938, 2, 512},
  {"512:_mm512_roundscale_pd(_mm512_xor_pd(x, _mm512_set1_pd(-0.0)), 2 | _MM_FROUND_NO_EXC)", f939, 2, 512},
  {"512:_mm512_roundscale_pd(_mm512_andnot_pd(_mm512_set1_pd(-0.0), x), 2 | _MM_FROUND_NO_EXC)", f940, 2, 512},
  {"512:_mm512_roundscale_pd(_mm512_sub_pd(_mm512_setzero_pd(), x), 2 | _MM_FROUND_NO_EXC)", f941, 2, 512},
  {"512:_mm512_roundscale_pd(_mm512_mul_pd(x, _mm512_set1_pd(-1.0)), 2 | _MM_FROUND_NO_EXC)", f942, 2, 512},
  {"512:_mm512_roundscale_pd(_mm512_roundscale_pd(x, 1 | _MM_FROUND_NO_EXC), 2 | _MM_FROUND_NO_EXC)", f943, 2, 512},
  {"512:_mm512_roundscale_pd(_mm512_roundscale_pd(x, 2 | _MM_FROUND_NO_EXC), 2 | _MM_FROUND_NO_EXC)", f944, 2, 512},
  {"512:_mm512_roundscale_pd(_mm512_roundscale_pd(x, 0 | _MM_FROUND_NO_EXC), 2 | _MM_FROUND_NO_EXC)", f945, 2, 512},
  {"512:_mm512_roundscale_pd(_mm512_sqrt_pd(x), 0 | _MM_FROUND_NO_EXC)", f946, 2, 512},
  {"512:_mm512_roundscale_pd(_mm512_xor_pd(x, _mm512_set1_pd(-0.0)), 0 | _MM_FROUND_NO_EXC)", f947, 2, 512},
  {"512:_mm512_roundscale_pd(_mm512_andnot_pd(_mm512_set1_pd(-0.0), x), 0 | _MM_FROUND_NO_EXC)", f948, 2, 512},
  {"512:_mm512_roundscale_pd(_mm512_sub_pd(_mm512_setzero_pd(), x), 0 | _MM_FROUND_NO_EXC)", f949, 2, 512},
  {"512:_mm512_roundscale_pd(_mm512_mul_pd(x, _mm512_set1_pd(-1.0)), 0 | _MM_FROUND_NO_EXC)", f950, 2, 512},
  {"512:_mm512_roundscale_pd(_mm512_roundscale_pd(x, 1 | _MM_FROUND_NO_EXC), 0 | _MM_FROUND_NO_EXC)", f951, 2, 512},
  {"512:_mm512_roundscale_pd(_mm512_roundscale_pd(x, 2 | _MM_FROUND_NO_EXC), 0 | _MM_FROUND_NO_EXC)", f952, 2, 512},
  {"512:_mm512_roundscale_pd(_mm512_roundscale_pd(x, 0 | _MM_FROUND_NO_EXC), 0 | _MM_FROUND_NO_EXC)", f953, 2, 512},
  {"512:_mm512_sqrt_pd(_mm512_sqrt_pd(_mm512_sqrt_pd(x)))", f954, 2, 512},
  {"512:_mm512_xor_pd(_mm512_xor_pd(_mm512_xor_pd(x, _mm512_set1_pd(-0.0)), _mm512_set1_pd(-0.0)), _mm512_set1_pd(-0.0))", f955, 2, 512},
  {"512:_mm512_andnot_pd(_mm512_set1_pd(-0.0), _mm512_andnot_pd(_mm512_set1_pd(-0.0), _mm512_andnot_pd(_mm512_set1_pd(-0.0), x)))", f956, 2, 512},
  {"512:_mm512_sub_pd(_mm512_setzero_pd(), _mm512_sub_pd(_mm512_setzero_pd(), _mm512_sub_pd(_mm512_setzero_pd(), x)))", f957, 2, 512},
  {"512:_mm512_mul_pd(_mm512_mul_pd(_mm512_mul_pd(x, _mm512_set1_pd(-1.0)), _mm512_set1_pd(-1.0)), _mm512_set1_pd(-1.0))", f958, 2, 512},
  {"512:_mm512_roundscale_pd(_mm512_roundscale_pd(_mm512_roundscale_pd(x, 1 | _MM_FROUND_NO_EXC), 1 | _MM_FROUND_NO_EXC), 1 | _MM_FROUND_NO_EXC)", f959, 2, 512},
  {"512:_mm512_roundscale_pd(_mm512_roundscale_pd(_mm512_roundscale_pd(x, 2 | _MM_FROUND_NO_EXC), 2 | _MM_FROUND_NO_EXC), 2 | _MM_FROUND_NO_EXC)", f960, 2, 512},
  {"512:_mm512_roundscale_pd(_mm512_roundscale_pd(_mm512_roundscale_pd(x, 0 | _MM_FROUND_NO_EXC), 0 | _MM_FROUND_NO_EXC), 0 | _MM_FROUND_NO_EXC)", f961, 2, 512},
  {"512:_mm512_sqrt_pd(_mm512_add_pd(x, y))", f962, 2, 512},
  {"512:_mm512_add_pd(_mm512_sqrt_pd(x), y)", f963, 2, 512},
  {"512:_mm512_add_pd(x, _mm512_sqrt_pd(y))", f964, 2, 512},
  {"512:_mm512_add_pd(_mm512_sqrt_pd(x), _mm512_sqrt_pd(y))", f965, 2, 512},
  {"512:_mm512_add_pd(x, _mm512_sqrt_pd(x))", f966, 2, 512},
  {"512:_mm512_add_pd(_mm512_sqrt_pd(x), x)", f967, 2, 512},
  {"512:_mm512_sqrt_pd(_mm512_sub_pd(x, y))", f968, 2, 512},
  {"512:_mm512_sub_pd(_mm512_sqrt_pd(x), y)", f969, 2, 512},
  {"512:_mm512_sub_pd(x, _mm512_sqrt_pd(y))", f970, 2, 512},
  {"512:_mm512_sub_pd(_mm512_sqrt_pd(x), _mm512_sqrt_pd(y))", f971, 2, 512},
  {"512:_mm512_sub_pd(x, _mm512_sqrt_pd(x))", f972, 2, 512},
  {"512:_mm512_sub_pd(_mm512_sqrt_pd(x), x)", f973, 2, 512},
  {"512:_mm512_sqrt_pd(_mm512_mul_pd(x, y))", f974, 2, 512},
  {"512:_mm512_mul_pd(_mm512_sqrt_pd(x), y)", f975, 2, 512},
  {"512:_mm512_mul_pd(x, _mm512_sqrt_pd(y))", f976, 2, 512},
  {"512:_mm512_mul_pd(_mm512_sqrt_pd(x), _mm512_sqrt_pd(y))", f977, 2, 512},
  {"512:_mm512_mul_pd(x, _mm512_sqrt_pd(x))", f978, 2, 512},
  {"512:_mm512_mul_pd(_mm512_sqrt_pd(x), x)", f979, 2, 512},
  {"512:_mm512_sqrt_pd(_mm512_div_pd(x, y))", f980, 2, 512},
  {"512:_mm512_div_pd(_mm512_sqrt_pd(x), y)", f981, 2, 512},
  {"512:_mm512_div_pd(x, _mm512_sqrt_pd(y))", f982, 2, 512},
  {"512:_mm512_div_pd(_mm512_sqrt_pd(x), _mm512_sqrt_pd(y))", f983, 2, 512},
  {"512:_mm512_div_pd(x, _mm512_sqrt_pd(x))", f984, 2, 512},
  {"512:_mm512_div_pd(_mm512_sqrt_pd(x), x)", f985, 2, 512},
  {"512:_mm512_sqrt_pd(_mm512_min_pd(x, y))", f986, 2, 512},
  {"512:_mm512_min_pd(_mm512_sqrt_pd(x), y)", f987, 2, 512},
  {"512:_mm512_min_pd(x, _mm512_sqrt_pd(y))", f988, 2, 512},
  {"512:_mm512_min_pd(_mm512_sqrt_pd(x), _mm512_sqrt_pd(y))", f989, 2, 512},
  {"512:_mm512_min_pd(x, _mm512_sqrt_pd(x))", f990, 2, 512},
  {"512:_mm512_min_pd(_mm512_sqrt_pd(x), x)", f991, 2, 512},
  {"512:_mm512_sqrt_pd(_mm512_max_pd(x, y))", f992, 2, 512},
  {"512:_mm512_max_pd(_mm512_sqrt_pd(x), y)", f993, 2, 512},
  {"512:_mm512_max_pd(x, _mm512_sqrt_pd(y))", f994, 2, 512},
  {"512:_mm512_max_pd(_mm512_sqrt_pd(x), _mm512_sqrt_pd(y))", f995, 2, 512},
  {"512:_mm512_max_pd(x, _mm512_sqrt_pd(x))", f996, 2, 512},
  {"512:_mm512_max_pd(_mm512_sqrt_pd(x), x)", f997, 2, 512},
  {"512:_mm512_sqrt_pd(_mm512_and_pd(x, y))", f998, 2, 512},
  {"512:_mm512_and_pd(_mm512_sqrt_pd(x), y)", f999, 2, 512},
  {"512:_mm512_and_pd(x, _mm512_sqrt_pd(y))", f1000, 2, 512},
  {"512:_mm512_and_pd(_mm512_sqrt_pd(x), _mm512_sqrt_pd(y))", f1001, 2, 512},
  {"512:_mm512_and_pd(x, _mm512_sqrt_pd(x))", f1002, 2, 512},
  {"512:_mm512_and_pd(_mm512_sqrt_pd(x), x)", f1003, 2, 512},
  {"512:_mm512_sqrt_pd(_mm512_or_pd(x, y))", f1004, 2, 512},
  {"512:_mm512_or_pd(_mm512_sqrt_pd(x), y)", f1005, 2, 512},
  {"512:_mm512_or_pd(x, _mm512_sqrt_pd(y))", f1006, 2, 512},
  {"512:_mm512_or_pd(_mm512_sqrt_pd(x), _mm512_sqrt_pd(y))", f1007, 2, 512},
  {"512:_mm512_or_pd(x, _mm512_sqrt_pd(x))", f1008, 2, 512},
  {"512:_mm512_or_pd(_mm512_sqrt_pd(x), x)", f1009, 2, 512},
  {"512:_mm512_sqrt_pd(_mm512_xor_pd(x, y))", f1010, 2, 512},
  {"512:_mm512_xor_pd(_mm512_sqrt_pd(x), y)", f1011, 2, 512},
  {"512:_mm512_xor_pd(x, _mm512_sqrt_pd(y))", f1012, 2, 512},
  {"512:_mm512_xor_pd(_mm512_sqrt_pd(x), _mm512_sqrt_pd(y))", f1013, 2, 512},
  {"512:_mm512_xor_pd(x, _mm512_sqrt_pd(x))", f1014, 2, 512},
  {"512:_mm512_xor_pd(_mm512_sqrt_pd(x), x)", f1015, 2, 512},
  {"512:_mm512_sqrt_pd(_mm512_andnot_pd(x, y))", f1016, 2, 512},
  {"512:_mm512_andnot_pd(_mm512_sqrt_pd(x), y)", f1017, 2, 512},
  {"512:_mm512_andnot_pd(x, _mm512_sqrt_pd(y))", f1018, 2, 512},
  {"512:_mm512_andnot_pd(_mm512_sqrt_pd(x), _mm512_sqrt_pd(y))", f1019, 2, 512},
  {"512:_mm512_andnot_pd(x, _mm512_sqrt_pd(x))", f1020, 2, 512},
  {"512:_mm512_andnot_pd(_mm512_sqrt_pd(x), x)", f1021, 2, 512},
  {"512:_mm512_xor_pd(_mm512_add_pd(x, y), _mm512_set1_pd(-0.0))", f1022, 2, 512},
  {"512:_mm512_add_pd(_mm512_xor_pd(x, _mm512_set1_pd(-0.0)), y)", f1023, 2, 512},
  {"512:_mm512_add_pd(x, _mm512_xor_pd(y, _mm512_set1_pd(-0.0)))", f1024, 2, 512},
  {"512:_mm512_add_pd(_mm512_xor_pd(x, _mm512_set1_pd(-0.0)), _mm512_xor_pd(y, _mm512_set1_pd(-0.0)))", f1025, 2, 512},
  {"512:_mm512_add_pd(x, _mm512_xor_pd(x, _mm512_set1_pd(-0.0)))", f1026, 2, 512},
  {"512:_mm512_add_pd(_mm512_xor_pd(x, _mm512_set1_pd(-0.0)), x)", f1027, 2, 512},
  {"512:_mm512_xor_pd(_mm512_sub_pd(x, y), _mm512_set1_pd(-0.0))", f1028, 2, 512},
  {"512:_mm512_sub_pd(_mm512_xor_pd(x, _mm512_set1_pd(-0.0)), y)", f1029, 2, 512},
  {"512:_mm512_sub_pd(x, _mm512_xor_pd(y, _mm512_set1_pd(-0.0)))", f1030, 2, 512},
  {"512:_mm512_sub_pd(_mm512_xor_pd(x, _mm512_set1_pd(-0.0)), _mm512_xor_pd(y, _mm512_set1_pd(-0.0)))", f1031, 2, 512},
  {"512:_mm512_sub_pd(x, _mm512_xor_pd(x, _mm512_set1_pd(-0.0)))", f1032, 2, 512},
  {"512:_mm512_sub_pd(_mm512_xor_pd(x, _mm512_set1_pd(-0.0)), x)", f1033, 2, 512},
  {"512:_mm512_xor_pd(_mm512_mul_pd(x, y), _mm512_set1_pd(-0.0))", f1034, 2, 512},
  {"512:_mm512_mul_pd(_mm512_xor_pd(x, _mm512_set1_pd(-0.0)), y)", f1035, 2, 512},
  {"512:_mm512_mul_pd(x, _mm512_xor_pd(y, _mm512_set1_pd(-0.0)))", f1036, 2, 512},
  {"512:_mm512_mul_pd(_mm512_xor_pd(x, _mm512_set1_pd(-0.0)), _mm512_xor_pd(y, _mm512_set1_pd(-0.0)))", f1037, 2, 512},
  {"512:_mm512_mul_pd(x, _mm512_xor_pd(x, _mm512_set1_pd(-0.0)))", f1038, 2, 512},
  {"512:_mm512_mul_pd(_mm512_xor_pd(x, _mm512_set1_pd(-0.0)), x)", f1039, 2, 512},
  {"512:_mm512_xor_pd(_mm512_div_pd(x, y), _mm512_set1_pd(-0.0))", f1040, 2, 512},
  {"512:_mm512_div_pd(_mm512_xor_pd(x, _mm512_set1_pd(-0.0)), y)", f1041, 2, 512},
  {"512:_mm512_div_pd(x, _mm512_xor_pd(y, _mm512_set1_pd(-0.0)))", f1042, 2, 512},
  {"512:_mm512_div_pd(_mm512_xor_pd(x, _mm512_set1_pd(-0.0)), _mm512_xor_pd(y, _mm512_set1_pd(-0.0)))", f1043, 2, 512},
  {"512:_mm512_div_pd(x, _mm512_xor_pd(x, _mm512_set1_pd(-0.0)))", f1044, 2, 512},
  {"512:_mm512_div_pd(_mm512_xor_pd(x, _mm512_set1_pd(-0.0)), x)", f1045, 2, 512},
  {"512:_mm512_xor_pd(_mm512_min_pd(x, y), _mm512_set1_pd(-0.0))", f1046, 2, 512},
  {"512:_mm512_min_pd(_mm512_xor_pd(x, _mm512_set1_pd(-0.0)), y)", f1047, 2, 512},
  {"512:_mm512_min_pd(x, _mm512_xor_pd(y, _mm512_set1_pd(-0.0)))", f1048, 2, 512},
  {"512:_mm512_min_pd(_mm512_xor_pd(x, _mm512_set1_pd(-0.0)), _mm512_xor_pd(y, _mm512_set1_pd(-0.0)))", f1049, 2, 512},
  {"512:_mm512_min_pd(x, _mm512_xor_pd(x, _mm512_set1_pd(-0.0)))", f1050, 2, 512},
  {"512:_mm512_min_pd(_mm512_xor_pd(x, _mm512_set1_pd(-0.0)), x)", f1051, 2, 512},
  {"512:_mm512_xor_pd(_mm512_max_pd(x, y), _mm512_set1_pd(-0.0))", f1052, 2, 512},
  {"512:_mm512_max_pd(_mm512_xor_pd(x, _mm512_set1_pd(-0.0)), y)", f1053, 2, 512},
  {"512:_mm512_max_pd(x, _mm512_xor_pd(y, _mm512_set1_pd(-0.0)))", f1054, 2, 512},
  {"512:_mm512_max_pd(_mm512_xor_pd(x, _mm512_set1_pd(-0.0)), _mm512_xor_pd(y, _mm512_set1_pd(-0.0)))", f1055, 2, 512},
  {"512:_mm512_max_pd(x, _mm512_xor_pd(x, _mm512_set1_pd(-0.0)))", f1056, 2, 512},
  {"512:_mm512_max_pd(_mm512_xor_pd(x, _mm512_set1_pd(-0.0)), x)", f1057, 2, 512},
  {"512:_mm512_xor_pd(_mm512_and_pd(x, y), _mm512_set1_pd(-0.0))", f1058, 2, 512},
  {"512:_mm512_and_pd(_mm512_xor_pd(x, _mm512_set1_pd(-0.0)), y)", f1059, 2, 512},
  {"512:_mm512_and_pd(x, _mm512_xor_pd(y, _mm512_set1_pd(-0.0)))", f1060, 2, 512},
  {"512:_mm512_and_pd(_mm512_xor_pd(x, _mm512_set1_pd(-0.0)), _mm512_xor_pd(y, _mm512_set1_pd(-0.0)))", f1061, 2, 512},
  {"512:_mm512_and_pd(x, _mm512_xor_pd(x, _mm512_set1_pd(-0.0)))", f1062, 2, 512},
  {"512:_mm512_and_pd(_mm512_xor_pd(x, _mm512_set1_pd(-0.0)), x)", f1063, 2, 512},
  {"512:_mm512_xor_pd(_mm512_or_pd(x, y), _mm512_set1_pd(-0.0))", f1064, 2, 512},
  {"512:_mm512_or_pd(_mm512_xor_pd(x, _mm512_set1_pd(-0.0)), y)", f1065, 2, 512},
  {"512:_mm512_or_pd(x, _mm512_xor_pd(y, _mm512_set1_pd(-0.0)))", f1066, 2, 512},
  {"512:_mm512_or_pd(_mm512_xor_pd(x, _mm512_set1_pd(-0.0)), _mm512_xor_pd(y, _mm512_set1_pd(-0.0)))", f1067, 2, 512},
  {"512:_mm512_or_pd(x, _mm512_xor_pd(x, _mm512_set1_pd(-0.0)))", f1068, 2, 512},
  {"512:_mm512_or_pd(_mm512_xor_pd(x, _mm512_set1_pd(-0.0)), x)", f1069, 2, 512},
  {"512:_mm512_xor_pd(_mm512_xor_pd(x, y), _mm512_set1_pd(-0.0))", f1070, 2, 512},
  {"512:_mm512_xor_pd(_mm512_xor_pd(x, _mm512_set1_pd(-0.0)), y)", f1071, 2, 512},
  {"512:_mm512_xor_pd(x, _mm512_xor_pd(y, _mm512_set1_pd(-0.0)))", f1072, 2, 512},
  {"512:_mm512_xor_pd(_mm512_xor_pd(x, _mm512_set1_pd(-0.0)), _mm512_xor_pd(y, _mm512_set1_pd(-0.0)))", f1073, 2, 512},
  {"512:_mm512_xor_pd(x, _mm512_xor_pd(x, _mm512_set1_pd(-0.0)))", f1074, 2, 512},
  {"512:_mm512_xor_pd(_mm512_xor_pd(x, _mm512_set1_pd(-0.0)), x)", f1075, 2, 512},
  {"512:_mm512_xor_pd(_mm512_andnot_pd(x, y), _mm512_set1_pd(-0.0))", f1076, 2, 512},
  {"512:_mm512_andnot_pd(_mm512_xor_pd(x, _mm512_set1_pd(-0.0)), y)", f1077, 2, 512},
  {"512:_mm512_andnot_pd(x, _mm512_xor_pd(y, _mm512_set1_pd(-0.0)))", f1078, 2, 512},
  {"512:_mm512_andnot_pd(_mm512_xor_pd(x, _mm512_set1_pd(-0.0)), _mm512_xor_pd(y, _mm512_set1_pd(-0.0)))", f1079, 2, 512},
  {"512:_mm512_andnot_pd(x, _mm512_xor_pd(x, _mm512_set1_pd(-0.0)))", f1080, 2, 512},
  {"512:_mm512_andnot_pd(_mm512_xor_pd(x, _mm512_set1_pd(-0.0)), x)", f1081, 2, 512},
  {"512:_mm512_andnot_pd(_mm512_set1_pd(-0.0), _mm512_add_pd(x, y))", f1082, 2, 512},
  {"512:_mm512_add_pd(_mm512_andnot_pd(_mm512_set1_pd(-0.0), x), y)", f1083, 2, 512},
  {"512:_mm512_add_pd(x, _mm512_andnot_pd(_mm512_set1_pd(-0.0), y))", f1084, 2, 512},
  {"512:_mm512_add_pd(_mm512_andnot_pd(_mm512_set1_pd(-0.0), x), _mm512_andnot_pd(_mm512_set1_pd(-0.0), y))", f1085, 2, 512},
  {"512:_mm512_add_pd(x, _mm512_andnot_pd(_mm512_set1_pd(-0.0), x))", f1086, 2, 512},
  {"512:_mm512_add_pd(_mm512_andnot_pd(_mm512_set1_pd(-0.0), x), x)", f1087, 2, 512},
  {"512:_mm512_andnot_pd(_mm512_set1_pd(-0.0), _mm512_sub_pd(x, y))", f1088, 2, 512},
  {"512:_mm512_sub_pd(_mm512_andnot_pd(_mm512_set1_pd(-0.0), x), y)", f1089, 2, 512},
  {"512:_mm512_sub_pd(x, _mm512_andnot_pd(_mm512_set1_pd(-0.0), y))", f1090, 2, 512},
  {"512:_mm512_sub_pd(_mm512_andnot_pd(_mm512_set1_pd(-0.0), x), _mm512_andnot_pd(_mm512_set1_pd(-0.0), y))", f1091, 2, 512},
  {"512:_mm512_sub_pd(x, _mm512_andnot_pd(_mm512_set1_pd(-0.0), x))", f1092, 2, 512},
  {"512:_mm512_sub_pd(_mm512_andnot_pd(_mm512_set1_pd(-0.0), x), x)", f1093, 2, 512},
  {"512:_mm512_andnot_pd(_mm512_set1_pd(-0.0), _mm512_mul_pd(x, y))", f1094, 2, 512},
  {"512:_mm512_mul_pd(_mm512_andnot_pd(_mm512_set1_pd(-0.0), x), y)", f1095, 2, 512},
  {"512:_mm512_mul_pd(x, _mm512_andnot_pd(_mm512_set1_pd(-0.0), y))", f1096, 2, 512},
  {"512:_mm512_mul_pd(_mm512_andnot_pd(_mm512_set1_pd(-0.0), x), _mm512_andnot_pd(_mm512_set1_pd(-0.0), y))", f1097, 2, 512},
  {"512:_mm512_mul_pd(x, _mm512_andnot_pd(_mm512_set1_pd(-0.0), x))", f1098, 2, 512},
  {"512:_mm512_mul_pd(_mm512_andnot_pd(_mm512_set1_pd(-0.0), x), x)", f1099, 2, 512},
  {"512:_mm512_andnot_pd(_mm512_set1_pd(-0.0), _mm512_div_pd(x, y))", f1100, 2, 512},
  {"512:_mm512_div_pd(_mm512_andnot_pd(_mm512_set1_pd(-0.0), x), y)", f1101, 2, 512},
  {"512:_mm512_div_pd(x, _mm512_andnot_pd(_mm512_set1_pd(-0.0), y))", f1102, 2, 512},
  {"512:_mm512_div_pd(_mm512_andnot_pd(_mm512_set1_pd(-0.0), x), _mm512_andnot_pd(_mm512_set1_pd(-0.0), y))", f1103, 2, 512},
  {"512:_mm512_div_pd(x, _mm512_andnot_pd(_mm512_set1_pd(-0.0), x))", f1104, 2, 512},
  {"512:_mm512_div_pd(_mm512_andnot_pd(_mm512_set1_pd(-0.0), x), x)", f1105, 2, 512},
  {"512:_mm512_andnot_pd(_mm512_set1_pd(-0.0), _mm512_min_pd(x, y))", f1106, 2, 512},
  {"512:_mm512_min_pd(_mm512_andnot_pd(_mm512_set1_pd(-0.0), x), y)", f1107, 2, 512},
  {"512:_mm512_min_pd(x, _mm512_andnot_pd(_mm512_set1_pd(-0.0), y))", f1108, 2, 512},
  {"512:_mm512_min_pd(_mm512_andnot_pd(_mm512_set1_pd(-0.0), x), _mm512_andnot_pd(_mm512_set1_pd(-0.0), y))", f1109, 2, 512},
  {"512:_mm512_min_pd(x, _mm512_andnot_pd(_mm512_set1_pd(-0.0), x))", f1110, 2, 512},
  {"512:_mm512_min_pd(_mm512_andnot_pd(_mm512_set1_pd(-0.0), x), x)", f1111, 2, 512},
  {"512:_mm512_andnot_pd(_mm512_set1_pd(-0.0), _mm512_max_pd(x, y))", f1112, 2, 512},
  {"512:_mm512_max_pd(_mm512_andnot_pd(_mm512_set1_pd(-0.0), x), y)", f1113, 2, 512},
  {"512:_mm512_max_pd(x, _mm512_andnot_pd(_mm512_set1_pd(-0.0), y))", f1114, 2, 512},
  {"512:_mm512_max_pd(_mm512_andnot_pd(_mm512_set1_pd(-0.0), x), _mm512_andnot_pd(_mm512_set1_pd(-0.0), y))", f1115, 2, 512},
  {"512:_mm512_max_pd(x, _mm512_andnot_pd(_mm512_set1_pd(-0.0), x))", f1116, 2, 512},
  {"512:_mm512_max_pd(_mm512_andnot_pd(_mm512_set1_pd(-0.0), x), x)", f1117, 2, 512},
  {"512:_mm512_andnot_pd(_mm512_set1_pd(-0.0), _mm512_and_pd(x, y))", f1118, 2, 512},
  {"512:_mm512_and_pd(_mm512_andnot_pd(_mm512_set1_pd(-0.0), x), y)", f1119, 2, 512},
  {"512:_mm512_and_pd(x, _mm512_andnot_pd(_mm512_set1_pd(-0.0), y))", f1120, 2, 512},
  {"512:_mm512_and_pd(_mm512_andnot_pd(_mm512_set1_pd(-0.0), x), _mm512_andnot_pd(_mm512_set1_pd(-0.0), y))", f1121, 2, 512},
  {"512:_mm512_and_pd(x, _mm512_andnot_pd(_mm512_set1_pd(-0.0), x))", f1122, 2, 512},
  {"512:_mm512_and_pd(_mm512_andnot_pd(_mm512_set1_pd(-0.0), x), x)", f1123, 2, 512},
  {"512:_mm512_andnot_pd(_mm512_set1_pd(-0.0), _mm512_or_pd(x, y))", f1124, 2, 512},
  {"512:_mm512_or_pd(_mm512_andnot_pd(_mm512_set1_pd(-0.0), x), y)", f1125, 2, 512},
  {"512:_mm512_or_pd(x, _mm512_andnot_pd(_mm512_set1_pd(-0.0), y))", f1126, 2, 512},
  {"512:_mm512_or_pd(_mm512_andnot_pd(_mm512_set1_pd(-0.0), x), _mm512_andnot_pd(_mm512_set1_pd(-0.0), y))", f1127, 2, 512},
  {"512:_mm512_or_pd(x, _mm512_andnot_pd(_mm512_set1_pd(-0.0), x))", f1128, 2, 512},
  {"512:_mm512_or_pd(_mm512_andnot_pd(_mm512_set1_pd(-0.0), x), x)", f1129, 2, 512},
  {"512:_mm512_andnot_pd(_mm512_set1_pd(-0.0), _mm512_xor_pd(x, y))", f1130, 2, 512},
  {"512:_mm512_xor_pd(_mm512_andnot_pd(_mm512_set1_pd(-0.0), x), y)", f1131, 2, 512},
  {"512:_mm512_xor_pd(x, _mm512_andnot_pd(_mm512_set1_pd(-0.0), y))", f1132, 2, 512},
  {"512:_mm512_xor_pd(_mm512_andnot_pd(_mm512_set1_pd(-0.0), x), _mm512_andnot_pd(_mm512_set1_pd(-0.0), y))", f1133, 2, 512},
  {"512:_mm512_xor_pd(x, _mm512_andnot_pd(_mm512_set1_pd(-0.0), x))", f1134, 2, 512},
  {"512:_mm512_xor_pd(_mm512_andnot_pd(_mm512_set1_pd(-0.0), x), x)", f1135, 2, 512},
  {"512:_mm512_andnot_pd(_mm512_set1_pd(-0.0), _mm512_andnot_pd(x, y))", f1136, 2, 512},
  {"512:_mm512_andnot_pd(_mm512_andnot_pd(_mm512_set1_pd(-0.0), x), y)", f1137, 2, 512},
  {"512:_mm512_andnot_pd(x, _mm512_andnot_pd(_mm512_set1_pd(-0.0), y))", f1138, 2, 512},
  {"512:_mm512_andnot_pd(_mm512_andnot_pd(_mm512_set1_pd(-0.0), x), _mm512_andnot_pd(_mm512_set1_pd(-0.0), y))", f1139, 2, 512},
  {"512:_mm512_andnot_pd(x, _mm512_andnot_pd(_mm512_set1_pd(-0.0), x))", f1140, 2, 512},
  {"512:_mm512_andnot_pd(_mm512_andnot_pd(_mm512_set1_pd(-0.0), x), x)", f1141, 2, 512},
  {"512:_mm512_sub_pd(_mm512_setzero_pd(), _mm512_add_pd(x, y))", f1142, 2, 512},
  {"512:_mm512_add_pd(_mm512_sub_pd(_mm512_setzero_pd(), x), y)", f1143, 2, 512},
  {"512:_mm512_add_pd(x, _mm512_sub_pd(_mm512_setzero_pd(), y))", f1144, 2, 512},
  {"512:_mm512_add_pd(_mm512_sub_pd(_mm512_setzero_pd(), x), _mm512_sub_pd(_mm512_setzero_pd(), y))", f1145, 2, 512},
  {"512:_mm512_add_pd(x, _mm512_sub_pd(_mm512_setzero_pd(), x))", f1146, 2, 512},
  {"512:_mm512_add_pd(_mm512_sub_pd(_mm512_setzero_pd(), x), x)", f1147, 2, 512},
  {"512:_mm512_sub_pd(_mm512_setzero_pd(), _mm512_sub_pd(x, y))", f1148, 2, 512},
  {"512:_mm512_sub_pd(_mm512_sub_pd(_mm512_setzero_pd(), x), y)", f1149, 2, 512},
  {"512:_mm512_sub_pd(x, _mm512_sub_pd(_mm512_setzero_pd(), y))", f1150, 2, 512},
  {"512:_mm512_sub_pd(_mm512_sub_pd(_mm512_setzero_pd(), x), _mm512_sub_pd(_mm512_setzero_pd(), y))", f1151, 2, 512},
  {"512:_mm512_sub_pd(x, _mm512_sub_pd(_mm512_setzero_pd(), x))", f1152, 2, 512},
  {"512:_mm512_sub_pd(_mm512_sub_pd(_mm512_setzero_pd(), x), x)", f1153, 2, 512},
  {"512:_mm512_sub_pd(_mm512_setzero_pd(), _mm512_mul_pd(x, y))", f1154, 2, 512},
  {"512:_mm512_mul_pd(_mm512_sub_pd(_mm512_setzero_pd(), x), y)", f1155, 2, 512},
  {"512:_mm512_mul_pd(x, _mm512_sub_pd(_mm512_setzero_pd(), y))", f1156, 2, 512},
  {"512:_mm512_mul_pd(_mm512_sub_pd(_mm512_setzero_pd(), x), _mm512_sub_pd(_mm512_setzero_pd(), y))", f1157, 2, 512},
  {"512:_mm512_mul_pd(x, _mm512_sub_pd(_mm512_setzero_pd(), x))", f1158, 2, 512},
  {"512:_mm512_mul_pd(_mm512_sub_pd(_mm512_setzero_pd(), x), x)", f1159, 2, 512},
  {"512:_mm512_sub_pd(_mm512_setzero_pd(), _mm512_div_pd(x, y))", f1160, 2, 512},
  {"512:_mm512_div_pd(_mm512_sub_pd(_mm512_setzero_pd(), x), y)", f1161, 2, 512},
  {"512:_mm512_div_pd(x, _mm512_sub_pd(_mm512_setzero_pd(), y))", f1162, 2, 512},
  {"512:_mm512_div_pd(_mm512_sub_pd(_mm512_setzero_pd(), x), _mm512_sub_pd(_mm512_setzero_pd(), y))", f1163, 2, 512},
  {"512:_mm512_div_pd(x, _mm512_sub_pd(_mm512_setzero_pd(), x))", f1164, 2, 512},
  {"512:_mm512_div_pd(_mm512_sub_pd(_mm512_setzero_pd(), x), x)", f1165, 2, 512},
  {"512:_mm512_sub_pd(_mm512_setzero_pd(), _mm512_min_pd(x, y))", f1166, 2, 512},
  {"512:_mm512_min_pd(_mm512_sub_pd(_mm512_setzero_pd(), x), y)", f1167, 2, 512},
  {"512:_mm512_min_pd(x, _mm512_sub_pd(_mm512_setzero_pd(), y))", f1168, 2, 512},
  {"512:_mm512_min_pd(_mm512_sub_pd(_mm512_setzero_pd(), x), _mm512_sub_pd(_mm512_setzero_pd(), y))", f1169, 2, 512},
  {"512:_mm512_min_pd(x, _mm512_sub_pd(_mm512_setzero_pd(), x))", f1170, 2, 512},
  {"512:_mm512_min_pd(_mm512_sub_pd(_mm512_setzero_pd(), x), x)", f1171, 2, 512},
  {"512:_mm512_sub_pd(_mm512_setzero_pd(), _mm512_max_pd(x, y))", f1172, 2, 512},
  {"512:_mm512_max_pd(_mm512_sub_pd(_mm512_setzero_pd(), x), y)", f1173, 2, 512},
  {"512:_mm512_max_pd(x, _mm512_sub_pd(_mm512_setzero_pd(), y))", f1174, 2, 512},
  {"512:_mm512_max_pd(_mm512_sub_pd(_mm512_setzero_pd(), x), _mm512_sub_pd(_mm512_setzero_pd(), y))", f1175, 2, 512},
  {"512:_mm512_max_pd(x, _mm512_sub_pd(_mm512_setzero_pd(), x))", f1176, 2, 512},
  {"512:_mm512_max_pd(_mm512_sub_pd(_mm512_setzero_pd(), x), x)", f1177, 2, 512},
  {"512:_mm512_sub_pd(_mm512_setzero_pd(), _mm512_and_pd(x, y))", f1178, 2, 512},
  {"512:_mm512_and_pd(_mm512_sub_pd(_mm512_setzero_pd(), x), y)", f1179, 2, 512},
  {"512:_mm512_and_pd(x, _mm512_sub_pd(_mm512_setzero_pd(), y))", f1180, 2, 512},
  {"512:_mm512_and_pd(_mm512_sub_pd(_mm512_setzero_pd(), x), _mm512_sub_pd(_mm512_setzero_pd(), y))", f1181, 2, 512},
  {"512:_mm512_and_pd(x, _mm512_sub_pd(_mm512_setzero_pd(), x))", f1182, 2, 512},
  {"512:_mm512_and_pd(_mm512_sub_pd(_mm512_setzero_pd(), x), x)", f1183, 2, 512},
  {"512:_mm512_sub_pd(_mm512_setzero_pd(), _mm512_or_pd(x, y))", f1184, 2, 512},
  {"512:_mm512_or_pd(_mm512_sub_pd(_mm512_setzero_pd(), x), y)", f1185, 2, 512},
  {"512:_mm512_or_pd(x, _mm512_sub_pd(_mm512_setzero_pd(), y))", f1186, 2, 512},
  {"512:_mm512_or_pd(_mm512_sub_pd(_mm512_setzero_pd(), x), _mm512_sub_pd(_mm512_setzero_pd(), y))", f1187, 2, 512},
  {"512:_mm512_or_pd(x, _mm512_sub_pd(_mm512_setzero_pd(), x))", f1188, 2, 512},
  {"512:_mm512_or_pd(_mm512_sub_pd(_mm512_setzero_pd(), x), x)", f1189, 2, 512},
  {"512:_mm512_sub_pd(_mm512_setzero_pd(), _mm512_xor_pd(x, y))", f1190, 2, 512},
  {"512:_mm512_xor_pd(_mm512_sub_pd(_mm512_setzero_pd(), x), y)", f1191, 2, 512},
  {"512:_mm512_xor_pd(x, _mm512_sub_pd(_mm512_setzero_pd(), y))", f1192, 2, 512},
  {"512:_mm512_xor_pd(_mm512_sub_pd(_mm512_setzero_pd(), x), _mm512_sub_pd(_mm512_setzero_pd(), y))", f1193, 2, 512},
  {"512:_mm512_xor_pd(x, _mm512_sub_pd(_mm512_setzero_pd(), x))", f1194, 2, 512},
  {"512:_mm512_xor_pd(_mm512_sub_pd(_mm512_setzero_pd(), x), x)", f1195, 2, 512},
  {"512:_mm512_sub_pd(_mm512_setzero_pd(), _mm512_andnot_pd(x, y))", f1196, 2, 512},
  {"512:_mm512_andnot_pd(_mm512_sub_pd(_mm512_setzero_pd(), x), y)", f1197, 2, 512},
  {"512:_mm512_andnot_pd(x, _mm512_sub_pd(_mm512_setzero_pd(), y))", f1198, 2, 512},
  {"512:_mm512_andnot_pd(_mm512_sub_pd(_mm512_setzero_pd(), x), _mm512_sub_pd(_mm512_setzero_pd(), y))", f1199, 2, 512},
};
extern const int size_94 = 1200;
