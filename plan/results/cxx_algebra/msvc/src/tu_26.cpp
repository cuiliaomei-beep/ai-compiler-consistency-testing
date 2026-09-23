#include "common.h"
static NOINLINE void f0(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_mul_ps(y, _mm_cmp_ps(x, y, _CMP_NEQ_UQ)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_mul_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f2(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_mul_ps(x, _mm_cmp_ps(x, y, _CMP_UNORD_Q)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f3(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_mul_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f4(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_mul_ps(y, _mm_cmp_ps(x, y, _CMP_UNORD_Q)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f5(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_mul_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f6(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_mul_ps(x, _mm_cmp_ps(x, y, _CMP_NLT_US)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f7(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_mul_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f8(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_mul_ps(y, _mm_cmp_ps(x, y, _CMP_NLT_US)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f9(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_mul_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f10(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_mul_ps(x, _mm_cmp_ps(x, y, _CMP_GT_OS)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f11(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_mul_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f12(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_mul_ps(y, _mm_cmp_ps(x, y, _CMP_GT_OS)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f13(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_mul_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LT_OS)), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f14(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_mul_ps(x, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LT_OS))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f15(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_mul_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LT_OS)), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f16(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_mul_ps(y, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LT_OS))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f17(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_mul_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LT_OS)), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f18(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_mul_ps(x, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LT_OS))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f19(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_mul_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LT_OS)), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f20(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_mul_ps(y, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LT_OS))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f21(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_mul_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), y)), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f22(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_mul_ps(x, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), y))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f23(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_mul_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), y)), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f24(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_mul_ps(y, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), y))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f25(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_mul_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LE_OS)), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f26(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_mul_ps(x, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LE_OS))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f27(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_mul_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LE_OS)), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f28(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_mul_ps(y, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LE_OS))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f29(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_mul_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LE_OS)), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f30(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_mul_ps(x, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LE_OS))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f31(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_mul_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LE_OS)), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f32(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_mul_ps(y, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LE_OS))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f33(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_mul_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), y)), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f34(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_mul_ps(x, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), y))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f35(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_mul_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), y)), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f36(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_mul_ps(y, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), y))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f37(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_mul_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_GT_OS)), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f38(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_mul_ps(x, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_GT_OS))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f39(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_mul_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_GT_OS)), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f40(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_mul_ps(y, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_GT_OS))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f41(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_mul_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_GT_OS)), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f42(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_mul_ps(x, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_GT_OS))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f43(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_mul_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_GT_OS)), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f44(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_mul_ps(y, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_GT_OS))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f45(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_mul_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), y)), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f46(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_mul_ps(x, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), y))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f47(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_mul_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), y)), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f48(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_mul_ps(y, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), y))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f49(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_mul_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_NLT_US)), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f50(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_mul_ps(x, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_NLT_US))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f51(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_mul_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_NLT_US)), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f52(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_mul_ps(y, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_NLT_US))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f53(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_mul_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_NLT_US)), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f54(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_mul_ps(x, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_NLT_US))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f55(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_mul_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_NLT_US)), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f56(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_mul_ps(y, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_NLT_US))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f57(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_mul_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), y)), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f58(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_mul_ps(x, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), y))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f59(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_mul_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), y)), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f60(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_mul_ps(y, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), y))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f61(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_mul_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_EQ_OQ)), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f62(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_mul_ps(x, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_EQ_OQ))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f63(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_mul_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_EQ_OQ)), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f64(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_mul_ps(y, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_EQ_OQ))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f65(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_mul_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_EQ_OQ)), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f66(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_mul_ps(x, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_EQ_OQ))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f67(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_mul_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_EQ_OQ)), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f68(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_mul_ps(y, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_EQ_OQ))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f69(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_mul_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), y)), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f70(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_mul_ps(x, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), y))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f71(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_mul_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), y)), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f72(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_mul_ps(y, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), y))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f73(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_mul_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_UNORD_Q)), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f74(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_mul_ps(x, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_UNORD_Q))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f75(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_mul_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_UNORD_Q)), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f76(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_mul_ps(y, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_UNORD_Q))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f77(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_mul_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_UNORD_Q)), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f78(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_mul_ps(x, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_UNORD_Q))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f79(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_mul_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_UNORD_Q)), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f80(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_mul_ps(y, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_UNORD_Q))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f81(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_mul_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), y)), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f82(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_mul_ps(x, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), y))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f83(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_mul_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), y)), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f84(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_mul_ps(y, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), y))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f85(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_mul_ps(_mm_unpacklo_ps(x, y), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f86(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_mul_ps(x, _mm_unpacklo_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f87(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_mul_ps(_mm_unpacklo_ps(x, y), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f88(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_mul_ps(y, _mm_unpacklo_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f89(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_mul_ps(_mm_unpackhi_ps(x, y), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f90(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_mul_ps(x, _mm_unpackhi_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f91(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_mul_ps(_mm_unpackhi_ps(x, y), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f92(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_mul_ps(y, _mm_unpackhi_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f93(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_mul_ps(_mm_hadd_ps(x, y), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f94(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_mul_ps(x, _mm_hadd_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f95(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_mul_ps(_mm_hadd_ps(x, y), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f96(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_mul_ps(y, _mm_hadd_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f97(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_mul_ps(_mm_hsub_ps(x, y), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f98(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_mul_ps(x, _mm_hsub_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f99(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_mul_ps(_mm_hsub_ps(x, y), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f100(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_mul_ps(y, _mm_hsub_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f101(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_mul_ps(_mm_shuffle_ps(x, y, 0x1b), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f102(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_mul_ps(x, _mm_shuffle_ps(x, y, 0x1b)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f103(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_mul_ps(_mm_shuffle_ps(x, y, 0x1b), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f104(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_mul_ps(y, _mm_shuffle_ps(x, y, 0x1b)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f105(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_mul_ps(_mm_shuffle_ps(x, y, 0x39), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f106(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_mul_ps(x, _mm_shuffle_ps(x, y, 0x39)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f107(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_mul_ps(_mm_shuffle_ps(x, y, 0x39), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f108(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_mul_ps(y, _mm_shuffle_ps(x, y, 0x39)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f109(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_mul_ps(_mm_shuffle_ps(x, y, 0x93), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f110(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_mul_ps(x, _mm_shuffle_ps(x, y, 0x93)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f111(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_mul_ps(_mm_shuffle_ps(x, y, 0x93), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f112(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_mul_ps(y, _mm_shuffle_ps(x, y, 0x93)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f113(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_mul_ps(_mm_shuffle_ps(x, y, 0x4e), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f114(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_mul_ps(x, _mm_shuffle_ps(x, y, 0x4e)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f115(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_mul_ps(_mm_shuffle_ps(x, y, 0x4e), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f116(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_mul_ps(y, _mm_shuffle_ps(x, y, 0x4e)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f117(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_div_ps(_mm_add_ps(x, y), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f118(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_div_ps(x, _mm_add_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f119(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_div_ps(_mm_add_ps(x, y), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f120(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_div_ps(y, _mm_add_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f121(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_div_ps(_mm_sub_ps(x, y), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f122(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_div_ps(x, _mm_sub_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f123(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_div_ps(_mm_sub_ps(x, y), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f124(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_div_ps(y, _mm_sub_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f125(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_div_ps(_mm_mul_ps(x, y), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f126(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_div_ps(x, _mm_mul_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f127(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_div_ps(_mm_mul_ps(x, y), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f128(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_div_ps(y, _mm_mul_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f129(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_div_ps(_mm_div_ps(x, y), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f130(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_div_ps(x, _mm_div_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f131(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_div_ps(_mm_div_ps(x, y), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f132(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_div_ps(y, _mm_div_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f133(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_div_ps(_mm_min_ps(x, y), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f134(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_div_ps(x, _mm_min_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f135(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_div_ps(_mm_min_ps(x, y), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f136(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_div_ps(y, _mm_min_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f137(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_div_ps(_mm_max_ps(x, y), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f138(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_div_ps(x, _mm_max_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f139(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_div_ps(_mm_max_ps(x, y), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f140(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_div_ps(y, _mm_max_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f141(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_div_ps(_mm_and_ps(x, y), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f142(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_div_ps(x, _mm_and_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f143(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_div_ps(_mm_and_ps(x, y), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f144(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_div_ps(y, _mm_and_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f145(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_div_ps(_mm_or_ps(x, y), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f146(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_div_ps(x, _mm_or_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f147(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_div_ps(_mm_or_ps(x, y), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f148(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_div_ps(y, _mm_or_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f149(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_div_ps(_mm_xor_ps(x, y), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f150(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_div_ps(x, _mm_xor_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f151(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_div_ps(_mm_xor_ps(x, y), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f152(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_div_ps(y, _mm_xor_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f153(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_div_ps(_mm_andnot_ps(x, y), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f154(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_div_ps(x, _mm_andnot_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f155(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_div_ps(_mm_andnot_ps(x, y), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f156(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_div_ps(y, _mm_andnot_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f157(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_div_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f158(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_div_ps(x, _mm_cmp_ps(x, y, _CMP_EQ_OQ)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f159(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_div_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f160(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_div_ps(y, _mm_cmp_ps(x, y, _CMP_EQ_OQ)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f161(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_div_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f162(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_div_ps(x, _mm_cmp_ps(x, y, _CMP_LT_OS)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f163(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_div_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f164(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_div_ps(y, _mm_cmp_ps(x, y, _CMP_LT_OS)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f165(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_div_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f166(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_div_ps(x, _mm_cmp_ps(x, y, _CMP_LE_OS)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f167(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_div_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f168(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_div_ps(y, _mm_cmp_ps(x, y, _CMP_LE_OS)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f169(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_div_ps(_mm_cmp_ps(x, y, _CMP_NEQ_UQ), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f170(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_div_ps(x, _mm_cmp_ps(x, y, _CMP_NEQ_UQ)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f171(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_div_ps(_mm_cmp_ps(x, y, _CMP_NEQ_UQ), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f172(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_div_ps(y, _mm_cmp_ps(x, y, _CMP_NEQ_UQ)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f173(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_div_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f174(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_div_ps(x, _mm_cmp_ps(x, y, _CMP_UNORD_Q)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f175(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_div_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f176(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_div_ps(y, _mm_cmp_ps(x, y, _CMP_UNORD_Q)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f177(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_div_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f178(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_div_ps(x, _mm_cmp_ps(x, y, _CMP_NLT_US)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f179(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_div_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f180(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_div_ps(y, _mm_cmp_ps(x, y, _CMP_NLT_US)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f181(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_div_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f182(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_div_ps(x, _mm_cmp_ps(x, y, _CMP_GT_OS)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f183(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_div_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f184(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_div_ps(y, _mm_cmp_ps(x, y, _CMP_GT_OS)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f185(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_div_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LT_OS)), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f186(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_div_ps(x, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LT_OS))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f187(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_div_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LT_OS)), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f188(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_div_ps(y, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LT_OS))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f189(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_div_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LT_OS)), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f190(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_div_ps(x, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LT_OS))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f191(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_div_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LT_OS)), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f192(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_div_ps(y, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LT_OS))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f193(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_div_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), y)), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f194(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_div_ps(x, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), y))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f195(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_div_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), y)), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f196(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_div_ps(y, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), y))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f197(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_div_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LE_OS)), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f198(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_div_ps(x, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LE_OS))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f199(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_div_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LE_OS)), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f200(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_div_ps(y, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LE_OS))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f201(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_div_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LE_OS)), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f202(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_div_ps(x, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LE_OS))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f203(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_div_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LE_OS)), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f204(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_div_ps(y, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LE_OS))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f205(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_div_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), y)), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f206(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_div_ps(x, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), y))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f207(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_div_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), y)), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f208(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_div_ps(y, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), y))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f209(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_div_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_GT_OS)), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f210(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_div_ps(x, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_GT_OS))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f211(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_div_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_GT_OS)), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f212(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_div_ps(y, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_GT_OS))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f213(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_div_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_GT_OS)), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f214(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_div_ps(x, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_GT_OS))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f215(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_div_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_GT_OS)), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f216(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_div_ps(y, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_GT_OS))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f217(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_div_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), y)), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f218(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_div_ps(x, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), y))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f219(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_div_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), y)), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f220(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_div_ps(y, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), y))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f221(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_div_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_NLT_US)), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f222(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_div_ps(x, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_NLT_US))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f223(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_div_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_NLT_US)), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f224(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_div_ps(y, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_NLT_US))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f225(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_div_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_NLT_US)), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f226(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_div_ps(x, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_NLT_US))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f227(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_div_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_NLT_US)), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f228(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_div_ps(y, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_NLT_US))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f229(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_div_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), y)), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f230(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_div_ps(x, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), y))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f231(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_div_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), y)), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f232(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_div_ps(y, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), y))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f233(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_div_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_EQ_OQ)), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f234(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_div_ps(x, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_EQ_OQ))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f235(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_div_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_EQ_OQ)), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f236(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_div_ps(y, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_EQ_OQ))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f237(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_div_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_EQ_OQ)), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f238(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_div_ps(x, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_EQ_OQ))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f239(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_div_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_EQ_OQ)), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f240(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_div_ps(y, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_EQ_OQ))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f241(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_div_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), y)), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f242(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_div_ps(x, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), y))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f243(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_div_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), y)), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f244(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_div_ps(y, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), y))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f245(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_div_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_UNORD_Q)), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f246(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_div_ps(x, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_UNORD_Q))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f247(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_div_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_UNORD_Q)), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f248(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_div_ps(y, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_UNORD_Q))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f249(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_div_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_UNORD_Q)), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f250(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_div_ps(x, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_UNORD_Q))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f251(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_div_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_UNORD_Q)), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f252(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_div_ps(y, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_UNORD_Q))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f253(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_div_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), y)), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f254(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_div_ps(x, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), y))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f255(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_div_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), y)), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f256(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_div_ps(y, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), y))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f257(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_div_ps(_mm_unpacklo_ps(x, y), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f258(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_div_ps(x, _mm_unpacklo_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f259(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_div_ps(_mm_unpacklo_ps(x, y), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f260(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_div_ps(y, _mm_unpacklo_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f261(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_div_ps(_mm_unpackhi_ps(x, y), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f262(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_div_ps(x, _mm_unpackhi_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f263(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_div_ps(_mm_unpackhi_ps(x, y), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f264(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_div_ps(y, _mm_unpackhi_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f265(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_div_ps(_mm_hadd_ps(x, y), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f266(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_div_ps(x, _mm_hadd_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f267(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_div_ps(_mm_hadd_ps(x, y), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f268(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_div_ps(y, _mm_hadd_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f269(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_div_ps(_mm_hsub_ps(x, y), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f270(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_div_ps(x, _mm_hsub_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f271(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_div_ps(_mm_hsub_ps(x, y), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f272(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_div_ps(y, _mm_hsub_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f273(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_div_ps(_mm_shuffle_ps(x, y, 0x1b), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f274(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_div_ps(x, _mm_shuffle_ps(x, y, 0x1b)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f275(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_div_ps(_mm_shuffle_ps(x, y, 0x1b), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f276(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_div_ps(y, _mm_shuffle_ps(x, y, 0x1b)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f277(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_div_ps(_mm_shuffle_ps(x, y, 0x39), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f278(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_div_ps(x, _mm_shuffle_ps(x, y, 0x39)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f279(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_div_ps(_mm_shuffle_ps(x, y, 0x39), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f280(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_div_ps(y, _mm_shuffle_ps(x, y, 0x39)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f281(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_div_ps(_mm_shuffle_ps(x, y, 0x93), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f282(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_div_ps(x, _mm_shuffle_ps(x, y, 0x93)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f283(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_div_ps(_mm_shuffle_ps(x, y, 0x93), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f284(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_div_ps(y, _mm_shuffle_ps(x, y, 0x93)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f285(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_div_ps(_mm_shuffle_ps(x, y, 0x4e), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f286(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_div_ps(x, _mm_shuffle_ps(x, y, 0x4e)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f287(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_div_ps(_mm_shuffle_ps(x, y, 0x4e), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f288(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_div_ps(y, _mm_shuffle_ps(x, y, 0x4e)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f289(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_min_ps(_mm_add_ps(x, y), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f290(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_min_ps(x, _mm_add_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f291(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_min_ps(_mm_add_ps(x, y), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f292(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_min_ps(y, _mm_add_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f293(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_min_ps(_mm_sub_ps(x, y), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f294(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_min_ps(x, _mm_sub_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f295(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_min_ps(_mm_sub_ps(x, y), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f296(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_min_ps(y, _mm_sub_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f297(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_min_ps(_mm_mul_ps(x, y), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f298(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_min_ps(x, _mm_mul_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f299(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_min_ps(_mm_mul_ps(x, y), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f300(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_min_ps(y, _mm_mul_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f301(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_min_ps(_mm_div_ps(x, y), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f302(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_min_ps(x, _mm_div_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f303(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_min_ps(_mm_div_ps(x, y), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f304(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_min_ps(y, _mm_div_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f305(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_min_ps(_mm_min_ps(x, y), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f306(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_min_ps(x, _mm_min_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f307(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_min_ps(_mm_min_ps(x, y), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f308(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_min_ps(y, _mm_min_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f309(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_min_ps(_mm_max_ps(x, y), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f310(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_min_ps(x, _mm_max_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f311(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_min_ps(_mm_max_ps(x, y), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f312(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_min_ps(y, _mm_max_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f313(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_min_ps(_mm_and_ps(x, y), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f314(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_min_ps(x, _mm_and_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f315(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_min_ps(_mm_and_ps(x, y), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f316(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_min_ps(y, _mm_and_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f317(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_min_ps(_mm_or_ps(x, y), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f318(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_min_ps(x, _mm_or_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f319(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_min_ps(_mm_or_ps(x, y), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f320(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_min_ps(y, _mm_or_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f321(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_min_ps(_mm_xor_ps(x, y), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f322(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_min_ps(x, _mm_xor_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f323(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_min_ps(_mm_xor_ps(x, y), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f324(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_min_ps(y, _mm_xor_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f325(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_min_ps(_mm_andnot_ps(x, y), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f326(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_min_ps(x, _mm_andnot_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f327(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_min_ps(_mm_andnot_ps(x, y), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f328(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_min_ps(y, _mm_andnot_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f329(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_min_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f330(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_min_ps(x, _mm_cmp_ps(x, y, _CMP_EQ_OQ)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f331(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_min_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f332(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_min_ps(y, _mm_cmp_ps(x, y, _CMP_EQ_OQ)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f333(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_min_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f334(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_min_ps(x, _mm_cmp_ps(x, y, _CMP_LT_OS)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f335(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_min_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f336(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_min_ps(y, _mm_cmp_ps(x, y, _CMP_LT_OS)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f337(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_min_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f338(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_min_ps(x, _mm_cmp_ps(x, y, _CMP_LE_OS)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f339(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_min_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f340(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_min_ps(y, _mm_cmp_ps(x, y, _CMP_LE_OS)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f341(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_min_ps(_mm_cmp_ps(x, y, _CMP_NEQ_UQ), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f342(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_min_ps(x, _mm_cmp_ps(x, y, _CMP_NEQ_UQ)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f343(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_min_ps(_mm_cmp_ps(x, y, _CMP_NEQ_UQ), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f344(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_min_ps(y, _mm_cmp_ps(x, y, _CMP_NEQ_UQ)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f345(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_min_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f346(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_min_ps(x, _mm_cmp_ps(x, y, _CMP_UNORD_Q)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f347(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_min_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f348(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_min_ps(y, _mm_cmp_ps(x, y, _CMP_UNORD_Q)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f349(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_min_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f350(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_min_ps(x, _mm_cmp_ps(x, y, _CMP_NLT_US)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f351(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_min_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f352(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_min_ps(y, _mm_cmp_ps(x, y, _CMP_NLT_US)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f353(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_min_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f354(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_min_ps(x, _mm_cmp_ps(x, y, _CMP_GT_OS)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f355(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_min_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f356(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_min_ps(y, _mm_cmp_ps(x, y, _CMP_GT_OS)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f357(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_min_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LT_OS)), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f358(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_min_ps(x, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LT_OS))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f359(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_min_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LT_OS)), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f360(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_min_ps(y, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LT_OS))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f361(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_min_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LT_OS)), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f362(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_min_ps(x, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LT_OS))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f363(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_min_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LT_OS)), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f364(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_min_ps(y, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LT_OS))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f365(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_min_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), y)), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f366(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_min_ps(x, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), y))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f367(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_min_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), y)), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f368(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_min_ps(y, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), y))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f369(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_min_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LE_OS)), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f370(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_min_ps(x, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LE_OS))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f371(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_min_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LE_OS)), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f372(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_min_ps(y, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LE_OS))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f373(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_min_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LE_OS)), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f374(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_min_ps(x, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LE_OS))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f375(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_min_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LE_OS)), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f376(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_min_ps(y, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LE_OS))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f377(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_min_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), y)), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f378(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_min_ps(x, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), y))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f379(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_min_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), y)), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f380(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_min_ps(y, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), y))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f381(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_min_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_GT_OS)), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f382(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_min_ps(x, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_GT_OS))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f383(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_min_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_GT_OS)), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f384(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_min_ps(y, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_GT_OS))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f385(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_min_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_GT_OS)), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f386(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_min_ps(x, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_GT_OS))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f387(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_min_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_GT_OS)), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f388(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_min_ps(y, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_GT_OS))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f389(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_min_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), y)), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f390(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_min_ps(x, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), y))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f391(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_min_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), y)), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f392(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_min_ps(y, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), y))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f393(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_min_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_NLT_US)), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f394(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_min_ps(x, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_NLT_US))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f395(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_min_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_NLT_US)), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f396(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_min_ps(y, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_NLT_US))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f397(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_min_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_NLT_US)), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f398(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_min_ps(x, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_NLT_US))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f399(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_min_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_NLT_US)), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f400(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_min_ps(y, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_NLT_US))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f401(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_min_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), y)), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f402(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_min_ps(x, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), y))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f403(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_min_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), y)), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f404(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_min_ps(y, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), y))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f405(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_min_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_EQ_OQ)), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f406(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_min_ps(x, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_EQ_OQ))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f407(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_min_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_EQ_OQ)), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f408(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_min_ps(y, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_EQ_OQ))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f409(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_min_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_EQ_OQ)), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f410(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_min_ps(x, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_EQ_OQ))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f411(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_min_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_EQ_OQ)), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f412(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_min_ps(y, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_EQ_OQ))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f413(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_min_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), y)), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f414(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_min_ps(x, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), y))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f415(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_min_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), y)), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f416(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_min_ps(y, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), y))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f417(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_min_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_UNORD_Q)), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f418(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_min_ps(x, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_UNORD_Q))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f419(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_min_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_UNORD_Q)), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f420(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_min_ps(y, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_UNORD_Q))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f421(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_min_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_UNORD_Q)), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f422(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_min_ps(x, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_UNORD_Q))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f423(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_min_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_UNORD_Q)), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f424(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_min_ps(y, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_UNORD_Q))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f425(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_min_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), y)), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f426(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_min_ps(x, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), y))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f427(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_min_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), y)), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f428(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_min_ps(y, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), y))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f429(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_min_ps(_mm_unpacklo_ps(x, y), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f430(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_min_ps(x, _mm_unpacklo_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f431(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_min_ps(_mm_unpacklo_ps(x, y), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f432(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_min_ps(y, _mm_unpacklo_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f433(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_min_ps(_mm_unpackhi_ps(x, y), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f434(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_min_ps(x, _mm_unpackhi_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f435(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_min_ps(_mm_unpackhi_ps(x, y), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f436(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_min_ps(y, _mm_unpackhi_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f437(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_min_ps(_mm_hadd_ps(x, y), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f438(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_min_ps(x, _mm_hadd_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f439(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_min_ps(_mm_hadd_ps(x, y), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f440(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_min_ps(y, _mm_hadd_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f441(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_min_ps(_mm_hsub_ps(x, y), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f442(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_min_ps(x, _mm_hsub_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f443(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_min_ps(_mm_hsub_ps(x, y), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f444(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_min_ps(y, _mm_hsub_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f445(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_min_ps(_mm_shuffle_ps(x, y, 0x1b), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f446(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_min_ps(x, _mm_shuffle_ps(x, y, 0x1b)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f447(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_min_ps(_mm_shuffle_ps(x, y, 0x1b), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f448(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_min_ps(y, _mm_shuffle_ps(x, y, 0x1b)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f449(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_min_ps(_mm_shuffle_ps(x, y, 0x39), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f450(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_min_ps(x, _mm_shuffle_ps(x, y, 0x39)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f451(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_min_ps(_mm_shuffle_ps(x, y, 0x39), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f452(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_min_ps(y, _mm_shuffle_ps(x, y, 0x39)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f453(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_min_ps(_mm_shuffle_ps(x, y, 0x93), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f454(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_min_ps(x, _mm_shuffle_ps(x, y, 0x93)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f455(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_min_ps(_mm_shuffle_ps(x, y, 0x93), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f456(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_min_ps(y, _mm_shuffle_ps(x, y, 0x93)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f457(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_min_ps(_mm_shuffle_ps(x, y, 0x4e), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f458(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_min_ps(x, _mm_shuffle_ps(x, y, 0x4e)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f459(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_min_ps(_mm_shuffle_ps(x, y, 0x4e), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f460(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_min_ps(y, _mm_shuffle_ps(x, y, 0x4e)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f461(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_max_ps(_mm_add_ps(x, y), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f462(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_max_ps(x, _mm_add_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f463(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_max_ps(_mm_add_ps(x, y), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f464(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_max_ps(y, _mm_add_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f465(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_max_ps(_mm_sub_ps(x, y), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f466(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_max_ps(x, _mm_sub_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f467(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_max_ps(_mm_sub_ps(x, y), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f468(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_max_ps(y, _mm_sub_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f469(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_max_ps(_mm_mul_ps(x, y), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f470(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_max_ps(x, _mm_mul_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f471(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_max_ps(_mm_mul_ps(x, y), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f472(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_max_ps(y, _mm_mul_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f473(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_max_ps(_mm_div_ps(x, y), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f474(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_max_ps(x, _mm_div_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f475(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_max_ps(_mm_div_ps(x, y), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f476(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_max_ps(y, _mm_div_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f477(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_max_ps(_mm_min_ps(x, y), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f478(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_max_ps(x, _mm_min_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f479(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_max_ps(_mm_min_ps(x, y), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f480(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_max_ps(y, _mm_min_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f481(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_max_ps(_mm_max_ps(x, y), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f482(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_max_ps(x, _mm_max_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f483(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_max_ps(_mm_max_ps(x, y), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f484(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_max_ps(y, _mm_max_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f485(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_max_ps(_mm_and_ps(x, y), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f486(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_max_ps(x, _mm_and_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f487(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_max_ps(_mm_and_ps(x, y), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f488(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_max_ps(y, _mm_and_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f489(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_max_ps(_mm_or_ps(x, y), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f490(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_max_ps(x, _mm_or_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f491(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_max_ps(_mm_or_ps(x, y), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f492(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_max_ps(y, _mm_or_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f493(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_max_ps(_mm_xor_ps(x, y), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f494(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_max_ps(x, _mm_xor_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f495(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_max_ps(_mm_xor_ps(x, y), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f496(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_max_ps(y, _mm_xor_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f497(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_max_ps(_mm_andnot_ps(x, y), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f498(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_max_ps(x, _mm_andnot_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f499(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_max_ps(_mm_andnot_ps(x, y), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f500(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_max_ps(y, _mm_andnot_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f501(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_max_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f502(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_max_ps(x, _mm_cmp_ps(x, y, _CMP_EQ_OQ)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f503(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_max_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f504(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_max_ps(y, _mm_cmp_ps(x, y, _CMP_EQ_OQ)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f505(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_max_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f506(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_max_ps(x, _mm_cmp_ps(x, y, _CMP_LT_OS)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f507(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_max_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f508(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_max_ps(y, _mm_cmp_ps(x, y, _CMP_LT_OS)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f509(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_max_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f510(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_max_ps(x, _mm_cmp_ps(x, y, _CMP_LE_OS)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f511(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_max_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f512(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_max_ps(y, _mm_cmp_ps(x, y, _CMP_LE_OS)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f513(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_max_ps(_mm_cmp_ps(x, y, _CMP_NEQ_UQ), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f514(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_max_ps(x, _mm_cmp_ps(x, y, _CMP_NEQ_UQ)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f515(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_max_ps(_mm_cmp_ps(x, y, _CMP_NEQ_UQ), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f516(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_max_ps(y, _mm_cmp_ps(x, y, _CMP_NEQ_UQ)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f517(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_max_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f518(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_max_ps(x, _mm_cmp_ps(x, y, _CMP_UNORD_Q)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f519(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_max_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f520(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_max_ps(y, _mm_cmp_ps(x, y, _CMP_UNORD_Q)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f521(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_max_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f522(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_max_ps(x, _mm_cmp_ps(x, y, _CMP_NLT_US)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f523(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_max_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f524(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_max_ps(y, _mm_cmp_ps(x, y, _CMP_NLT_US)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f525(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_max_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f526(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_max_ps(x, _mm_cmp_ps(x, y, _CMP_GT_OS)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f527(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_max_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f528(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_max_ps(y, _mm_cmp_ps(x, y, _CMP_GT_OS)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f529(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_max_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LT_OS)), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f530(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_max_ps(x, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LT_OS))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f531(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_max_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LT_OS)), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f532(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_max_ps(y, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LT_OS))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f533(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_max_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LT_OS)), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f534(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_max_ps(x, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LT_OS))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f535(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_max_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LT_OS)), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f536(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_max_ps(y, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LT_OS))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f537(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_max_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), y)), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f538(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_max_ps(x, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), y))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f539(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_max_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), y)), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f540(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_max_ps(y, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), y))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f541(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_max_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LE_OS)), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f542(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_max_ps(x, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LE_OS))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f543(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_max_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LE_OS)), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f544(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_max_ps(y, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LE_OS))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f545(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_max_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LE_OS)), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f546(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_max_ps(x, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LE_OS))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f547(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_max_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LE_OS)), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f548(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_max_ps(y, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LE_OS))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f549(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_max_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), y)), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f550(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_max_ps(x, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), y))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f551(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_max_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), y)), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f552(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_max_ps(y, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), y))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f553(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_max_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_GT_OS)), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f554(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_max_ps(x, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_GT_OS))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f555(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_max_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_GT_OS)), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f556(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_max_ps(y, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_GT_OS))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f557(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_max_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_GT_OS)), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f558(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_max_ps(x, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_GT_OS))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f559(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_max_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_GT_OS)), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f560(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_max_ps(y, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_GT_OS))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f561(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_max_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), y)), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f562(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_max_ps(x, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), y))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f563(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_max_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), y)), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f564(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_max_ps(y, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), y))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f565(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_max_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_NLT_US)), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f566(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_max_ps(x, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_NLT_US))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f567(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_max_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_NLT_US)), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f568(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_max_ps(y, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_NLT_US))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f569(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_max_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_NLT_US)), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f570(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_max_ps(x, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_NLT_US))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f571(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_max_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_NLT_US)), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f572(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_max_ps(y, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_NLT_US))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f573(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_max_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), y)), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f574(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_max_ps(x, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), y))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f575(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_max_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), y)), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f576(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_max_ps(y, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), y))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f577(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_max_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_EQ_OQ)), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f578(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_max_ps(x, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_EQ_OQ))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f579(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_max_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_EQ_OQ)), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f580(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_max_ps(y, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_EQ_OQ))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f581(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_max_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_EQ_OQ)), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f582(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_max_ps(x, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_EQ_OQ))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f583(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_max_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_EQ_OQ)), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f584(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_max_ps(y, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_EQ_OQ))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f585(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_max_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), y)), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f586(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_max_ps(x, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), y))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f587(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_max_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), y)), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f588(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_max_ps(y, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), y))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f589(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_max_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_UNORD_Q)), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f590(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_max_ps(x, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_UNORD_Q))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f591(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_max_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_UNORD_Q)), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f592(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_max_ps(y, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_UNORD_Q))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f593(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_max_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_UNORD_Q)), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f594(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_max_ps(x, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_UNORD_Q))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f595(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_max_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_UNORD_Q)), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f596(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_max_ps(y, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_UNORD_Q))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f597(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_max_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), y)), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f598(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_max_ps(x, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), y))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f599(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_max_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), y)), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f600(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_max_ps(y, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), y))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f601(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_max_ps(_mm_unpacklo_ps(x, y), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f602(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_max_ps(x, _mm_unpacklo_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f603(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_max_ps(_mm_unpacklo_ps(x, y), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f604(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_max_ps(y, _mm_unpacklo_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f605(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_max_ps(_mm_unpackhi_ps(x, y), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f606(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_max_ps(x, _mm_unpackhi_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f607(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_max_ps(_mm_unpackhi_ps(x, y), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f608(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_max_ps(y, _mm_unpackhi_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f609(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_max_ps(_mm_hadd_ps(x, y), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f610(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_max_ps(x, _mm_hadd_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f611(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_max_ps(_mm_hadd_ps(x, y), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f612(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_max_ps(y, _mm_hadd_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f613(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_max_ps(_mm_hsub_ps(x, y), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f614(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_max_ps(x, _mm_hsub_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f615(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_max_ps(_mm_hsub_ps(x, y), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f616(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_max_ps(y, _mm_hsub_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f617(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_max_ps(_mm_shuffle_ps(x, y, 0x1b), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f618(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_max_ps(x, _mm_shuffle_ps(x, y, 0x1b)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f619(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_max_ps(_mm_shuffle_ps(x, y, 0x1b), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f620(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_max_ps(y, _mm_shuffle_ps(x, y, 0x1b)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f621(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_max_ps(_mm_shuffle_ps(x, y, 0x39), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f622(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_max_ps(x, _mm_shuffle_ps(x, y, 0x39)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f623(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_max_ps(_mm_shuffle_ps(x, y, 0x39), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f624(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_max_ps(y, _mm_shuffle_ps(x, y, 0x39)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f625(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_max_ps(_mm_shuffle_ps(x, y, 0x93), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f626(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_max_ps(x, _mm_shuffle_ps(x, y, 0x93)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f627(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_max_ps(_mm_shuffle_ps(x, y, 0x93), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f628(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_max_ps(y, _mm_shuffle_ps(x, y, 0x93)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f629(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_max_ps(_mm_shuffle_ps(x, y, 0x4e), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f630(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_max_ps(x, _mm_shuffle_ps(x, y, 0x4e)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f631(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_max_ps(_mm_shuffle_ps(x, y, 0x4e), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f632(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_max_ps(y, _mm_shuffle_ps(x, y, 0x4e)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f633(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_and_ps(_mm_add_ps(x, y), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f634(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_and_ps(x, _mm_add_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f635(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_and_ps(_mm_add_ps(x, y), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f636(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_and_ps(y, _mm_add_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f637(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_and_ps(_mm_sub_ps(x, y), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f638(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_and_ps(x, _mm_sub_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f639(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_and_ps(_mm_sub_ps(x, y), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f640(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_and_ps(y, _mm_sub_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f641(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_and_ps(_mm_mul_ps(x, y), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f642(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_and_ps(x, _mm_mul_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f643(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_and_ps(_mm_mul_ps(x, y), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f644(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_and_ps(y, _mm_mul_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f645(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_and_ps(_mm_div_ps(x, y), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f646(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_and_ps(x, _mm_div_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f647(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_and_ps(_mm_div_ps(x, y), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f648(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_and_ps(y, _mm_div_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f649(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_and_ps(_mm_min_ps(x, y), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f650(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_and_ps(x, _mm_min_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f651(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_and_ps(_mm_min_ps(x, y), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f652(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_and_ps(y, _mm_min_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f653(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_and_ps(_mm_max_ps(x, y), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f654(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_and_ps(x, _mm_max_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f655(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_and_ps(_mm_max_ps(x, y), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f656(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_and_ps(y, _mm_max_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f657(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_and_ps(_mm_and_ps(x, y), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f658(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_and_ps(x, _mm_and_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f659(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_and_ps(_mm_and_ps(x, y), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f660(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_and_ps(y, _mm_and_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f661(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_and_ps(_mm_or_ps(x, y), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f662(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_and_ps(x, _mm_or_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f663(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_and_ps(_mm_or_ps(x, y), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f664(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_and_ps(y, _mm_or_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f665(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_and_ps(_mm_xor_ps(x, y), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f666(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_and_ps(x, _mm_xor_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f667(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_and_ps(_mm_xor_ps(x, y), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f668(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_and_ps(y, _mm_xor_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f669(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_and_ps(_mm_andnot_ps(x, y), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f670(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_and_ps(x, _mm_andnot_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f671(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_and_ps(_mm_andnot_ps(x, y), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f672(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_and_ps(y, _mm_andnot_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f673(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_and_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f674(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_and_ps(x, _mm_cmp_ps(x, y, _CMP_EQ_OQ)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f675(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_and_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f676(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_and_ps(y, _mm_cmp_ps(x, y, _CMP_EQ_OQ)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f677(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_and_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f678(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_and_ps(x, _mm_cmp_ps(x, y, _CMP_LT_OS)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f679(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_and_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f680(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_and_ps(y, _mm_cmp_ps(x, y, _CMP_LT_OS)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f681(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_and_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f682(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_and_ps(x, _mm_cmp_ps(x, y, _CMP_LE_OS)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f683(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_and_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f684(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_and_ps(y, _mm_cmp_ps(x, y, _CMP_LE_OS)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f685(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_and_ps(_mm_cmp_ps(x, y, _CMP_NEQ_UQ), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f686(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_and_ps(x, _mm_cmp_ps(x, y, _CMP_NEQ_UQ)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f687(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_and_ps(_mm_cmp_ps(x, y, _CMP_NEQ_UQ), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f688(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_and_ps(y, _mm_cmp_ps(x, y, _CMP_NEQ_UQ)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f689(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_and_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f690(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_and_ps(x, _mm_cmp_ps(x, y, _CMP_UNORD_Q)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f691(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_and_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f692(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_and_ps(y, _mm_cmp_ps(x, y, _CMP_UNORD_Q)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f693(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_and_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f694(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_and_ps(x, _mm_cmp_ps(x, y, _CMP_NLT_US)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f695(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_and_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f696(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_and_ps(y, _mm_cmp_ps(x, y, _CMP_NLT_US)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f697(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_and_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f698(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_and_ps(x, _mm_cmp_ps(x, y, _CMP_GT_OS)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f699(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_and_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f700(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_and_ps(y, _mm_cmp_ps(x, y, _CMP_GT_OS)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f701(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_and_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LT_OS)), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f702(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_and_ps(x, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LT_OS))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f703(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_and_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LT_OS)), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f704(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_and_ps(y, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LT_OS))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f705(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_and_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LT_OS)), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f706(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_and_ps(x, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LT_OS))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f707(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_and_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LT_OS)), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f708(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_and_ps(y, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LT_OS))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f709(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_and_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), y)), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f710(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_and_ps(x, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), y))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f711(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_and_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), y)), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f712(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_and_ps(y, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), y))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f713(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_and_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LE_OS)), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f714(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_and_ps(x, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LE_OS))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f715(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_and_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LE_OS)), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f716(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_and_ps(y, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LE_OS))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f717(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_and_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LE_OS)), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f718(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_and_ps(x, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LE_OS))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f719(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_and_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LE_OS)), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f720(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_and_ps(y, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LE_OS))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f721(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_and_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), y)), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f722(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_and_ps(x, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), y))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f723(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_and_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), y)), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f724(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_and_ps(y, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), y))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f725(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_and_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_GT_OS)), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f726(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_and_ps(x, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_GT_OS))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f727(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_and_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_GT_OS)), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f728(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_and_ps(y, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_GT_OS))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f729(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_and_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_GT_OS)), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f730(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_and_ps(x, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_GT_OS))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f731(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_and_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_GT_OS)), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f732(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_and_ps(y, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_GT_OS))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f733(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_and_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), y)), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f734(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_and_ps(x, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), y))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f735(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_and_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), y)), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f736(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_and_ps(y, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), y))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f737(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_and_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_NLT_US)), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f738(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_and_ps(x, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_NLT_US))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f739(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_and_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_NLT_US)), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f740(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_and_ps(y, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_NLT_US))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f741(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_and_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_NLT_US)), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f742(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_and_ps(x, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_NLT_US))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f743(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_and_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_NLT_US)), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f744(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_and_ps(y, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_NLT_US))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f745(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_and_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), y)), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f746(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_and_ps(x, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), y))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f747(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_and_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), y)), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f748(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_and_ps(y, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), y))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f749(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_and_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_EQ_OQ)), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f750(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_and_ps(x, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_EQ_OQ))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f751(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_and_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_EQ_OQ)), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f752(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_and_ps(y, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_EQ_OQ))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f753(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_and_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_EQ_OQ)), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f754(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_and_ps(x, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_EQ_OQ))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f755(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_and_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_EQ_OQ)), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f756(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_and_ps(y, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_EQ_OQ))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f757(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_and_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), y)), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f758(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_and_ps(x, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), y))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f759(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_and_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), y)), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f760(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_and_ps(y, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), y))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f761(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_and_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_UNORD_Q)), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f762(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_and_ps(x, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_UNORD_Q))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f763(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_and_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_UNORD_Q)), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f764(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_and_ps(y, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_UNORD_Q))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f765(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_and_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_UNORD_Q)), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f766(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_and_ps(x, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_UNORD_Q))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f767(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_and_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_UNORD_Q)), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f768(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_and_ps(y, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_UNORD_Q))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f769(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_and_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), y)), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f770(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_and_ps(x, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), y))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f771(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_and_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), y)), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f772(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_and_ps(y, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), y))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f773(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_and_ps(_mm_unpacklo_ps(x, y), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f774(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_and_ps(x, _mm_unpacklo_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f775(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_and_ps(_mm_unpacklo_ps(x, y), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f776(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_and_ps(y, _mm_unpacklo_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f777(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_and_ps(_mm_unpackhi_ps(x, y), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f778(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_and_ps(x, _mm_unpackhi_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f779(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_and_ps(_mm_unpackhi_ps(x, y), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f780(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_and_ps(y, _mm_unpackhi_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f781(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_and_ps(_mm_hadd_ps(x, y), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f782(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_and_ps(x, _mm_hadd_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f783(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_and_ps(_mm_hadd_ps(x, y), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f784(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_and_ps(y, _mm_hadd_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f785(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_and_ps(_mm_hsub_ps(x, y), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f786(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_and_ps(x, _mm_hsub_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f787(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_and_ps(_mm_hsub_ps(x, y), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f788(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_and_ps(y, _mm_hsub_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f789(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_and_ps(_mm_shuffle_ps(x, y, 0x1b), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f790(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_and_ps(x, _mm_shuffle_ps(x, y, 0x1b)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f791(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_and_ps(_mm_shuffle_ps(x, y, 0x1b), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f792(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_and_ps(y, _mm_shuffle_ps(x, y, 0x1b)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f793(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_and_ps(_mm_shuffle_ps(x, y, 0x39), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f794(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_and_ps(x, _mm_shuffle_ps(x, y, 0x39)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f795(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_and_ps(_mm_shuffle_ps(x, y, 0x39), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f796(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_and_ps(y, _mm_shuffle_ps(x, y, 0x39)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f797(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_and_ps(_mm_shuffle_ps(x, y, 0x93), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f798(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_and_ps(x, _mm_shuffle_ps(x, y, 0x93)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f799(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_and_ps(_mm_shuffle_ps(x, y, 0x93), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f800(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_and_ps(y, _mm_shuffle_ps(x, y, 0x93)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f801(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_and_ps(_mm_shuffle_ps(x, y, 0x4e), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f802(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_and_ps(x, _mm_shuffle_ps(x, y, 0x4e)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f803(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_and_ps(_mm_shuffle_ps(x, y, 0x4e), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f804(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_and_ps(y, _mm_shuffle_ps(x, y, 0x4e)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f805(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(_mm_add_ps(x, y), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f806(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(x, _mm_add_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f807(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(_mm_add_ps(x, y), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f808(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(y, _mm_add_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f809(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(_mm_sub_ps(x, y), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f810(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(x, _mm_sub_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f811(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(_mm_sub_ps(x, y), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f812(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(y, _mm_sub_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f813(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(_mm_mul_ps(x, y), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f814(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(x, _mm_mul_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f815(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(_mm_mul_ps(x, y), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f816(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(y, _mm_mul_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f817(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(_mm_div_ps(x, y), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f818(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(x, _mm_div_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f819(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(_mm_div_ps(x, y), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f820(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(y, _mm_div_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f821(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(_mm_min_ps(x, y), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f822(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(x, _mm_min_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f823(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(_mm_min_ps(x, y), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f824(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(y, _mm_min_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f825(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(_mm_max_ps(x, y), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f826(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(x, _mm_max_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f827(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(_mm_max_ps(x, y), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f828(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(y, _mm_max_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f829(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(_mm_and_ps(x, y), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f830(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(x, _mm_and_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f831(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(_mm_and_ps(x, y), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f832(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(y, _mm_and_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f833(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(_mm_or_ps(x, y), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f834(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(x, _mm_or_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f835(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(_mm_or_ps(x, y), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f836(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(y, _mm_or_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f837(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(_mm_xor_ps(x, y), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f838(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(x, _mm_xor_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f839(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(_mm_xor_ps(x, y), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f840(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(y, _mm_xor_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f841(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(_mm_andnot_ps(x, y), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f842(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(x, _mm_andnot_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f843(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(_mm_andnot_ps(x, y), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f844(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(y, _mm_andnot_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f845(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f846(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(x, _mm_cmp_ps(x, y, _CMP_EQ_OQ)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f847(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f848(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(y, _mm_cmp_ps(x, y, _CMP_EQ_OQ)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f849(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f850(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(x, _mm_cmp_ps(x, y, _CMP_LT_OS)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f851(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f852(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(y, _mm_cmp_ps(x, y, _CMP_LT_OS)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f853(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f854(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(x, _mm_cmp_ps(x, y, _CMP_LE_OS)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f855(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f856(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(y, _mm_cmp_ps(x, y, _CMP_LE_OS)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f857(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(_mm_cmp_ps(x, y, _CMP_NEQ_UQ), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f858(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(x, _mm_cmp_ps(x, y, _CMP_NEQ_UQ)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f859(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(_mm_cmp_ps(x, y, _CMP_NEQ_UQ), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f860(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(y, _mm_cmp_ps(x, y, _CMP_NEQ_UQ)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f861(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f862(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(x, _mm_cmp_ps(x, y, _CMP_UNORD_Q)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f863(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f864(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(y, _mm_cmp_ps(x, y, _CMP_UNORD_Q)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f865(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f866(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(x, _mm_cmp_ps(x, y, _CMP_NLT_US)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f867(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f868(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(y, _mm_cmp_ps(x, y, _CMP_NLT_US)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f869(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f870(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(x, _mm_cmp_ps(x, y, _CMP_GT_OS)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f871(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f872(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(y, _mm_cmp_ps(x, y, _CMP_GT_OS)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f873(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LT_OS)), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f874(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(x, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LT_OS))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f875(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LT_OS)), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f876(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(y, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LT_OS))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f877(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LT_OS)), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f878(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(x, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LT_OS))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f879(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LT_OS)), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f880(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(y, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LT_OS))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f881(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), y)), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f882(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(x, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), y))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f883(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), y)), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f884(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(y, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), y))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f885(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LE_OS)), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f886(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(x, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LE_OS))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f887(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LE_OS)), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f888(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(y, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LE_OS))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f889(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LE_OS)), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f890(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(x, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LE_OS))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f891(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LE_OS)), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f892(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(y, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LE_OS))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f893(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), y)), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f894(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(x, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), y))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f895(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), y)), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f896(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(y, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), y))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f897(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_GT_OS)), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f898(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(x, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_GT_OS))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f899(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_GT_OS)), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f900(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(y, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_GT_OS))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f901(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_GT_OS)), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f902(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(x, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_GT_OS))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f903(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_GT_OS)), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f904(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(y, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_GT_OS))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f905(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), y)), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f906(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(x, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), y))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f907(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), y)), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f908(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(y, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), y))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f909(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_NLT_US)), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f910(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(x, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_NLT_US))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f911(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_NLT_US)), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f912(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(y, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_NLT_US))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f913(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_NLT_US)), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f914(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(x, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_NLT_US))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f915(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_NLT_US)), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f916(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(y, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_NLT_US))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f917(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), y)), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f918(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(x, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), y))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f919(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), y)), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f920(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(y, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), y))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f921(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_EQ_OQ)), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f922(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(x, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_EQ_OQ))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f923(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_EQ_OQ)), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f924(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(y, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_EQ_OQ))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f925(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_EQ_OQ)), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f926(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(x, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_EQ_OQ))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f927(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_EQ_OQ)), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f928(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(y, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_EQ_OQ))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f929(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), y)), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f930(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(x, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), y))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f931(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), y)), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f932(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(y, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), y))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f933(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_UNORD_Q)), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f934(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(x, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_UNORD_Q))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f935(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_UNORD_Q)), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f936(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(y, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_UNORD_Q))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f937(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_UNORD_Q)), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f938(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(x, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_UNORD_Q))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f939(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_UNORD_Q)), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f940(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(y, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_UNORD_Q))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f941(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), y)), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f942(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(x, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), y))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f943(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), y)), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f944(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(y, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), y))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f945(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(_mm_unpacklo_ps(x, y), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f946(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(x, _mm_unpacklo_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f947(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(_mm_unpacklo_ps(x, y), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f948(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(y, _mm_unpacklo_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f949(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(_mm_unpackhi_ps(x, y), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f950(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(x, _mm_unpackhi_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f951(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(_mm_unpackhi_ps(x, y), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f952(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(y, _mm_unpackhi_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f953(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(_mm_hadd_ps(x, y), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f954(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(x, _mm_hadd_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f955(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(_mm_hadd_ps(x, y), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f956(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(y, _mm_hadd_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f957(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(_mm_hsub_ps(x, y), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f958(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(x, _mm_hsub_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f959(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(_mm_hsub_ps(x, y), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f960(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(y, _mm_hsub_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f961(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(_mm_shuffle_ps(x, y, 0x1b), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f962(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(x, _mm_shuffle_ps(x, y, 0x1b)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f963(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(_mm_shuffle_ps(x, y, 0x1b), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f964(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(y, _mm_shuffle_ps(x, y, 0x1b)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f965(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(_mm_shuffle_ps(x, y, 0x39), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f966(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(x, _mm_shuffle_ps(x, y, 0x39)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f967(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(_mm_shuffle_ps(x, y, 0x39), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f968(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(y, _mm_shuffle_ps(x, y, 0x39)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f969(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(_mm_shuffle_ps(x, y, 0x93), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f970(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(x, _mm_shuffle_ps(x, y, 0x93)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f971(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(_mm_shuffle_ps(x, y, 0x93), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f972(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(y, _mm_shuffle_ps(x, y, 0x93)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f973(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(_mm_shuffle_ps(x, y, 0x4e), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f974(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(x, _mm_shuffle_ps(x, y, 0x4e)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f975(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(_mm_shuffle_ps(x, y, 0x4e), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f976(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(y, _mm_shuffle_ps(x, y, 0x4e)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f977(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(_mm_add_ps(x, y), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f978(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(x, _mm_add_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f979(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(_mm_add_ps(x, y), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f980(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(y, _mm_add_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f981(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(_mm_sub_ps(x, y), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f982(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(x, _mm_sub_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f983(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(_mm_sub_ps(x, y), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f984(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(y, _mm_sub_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f985(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(_mm_mul_ps(x, y), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f986(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(x, _mm_mul_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f987(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(_mm_mul_ps(x, y), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f988(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(y, _mm_mul_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f989(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(_mm_div_ps(x, y), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f990(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(x, _mm_div_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f991(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(_mm_div_ps(x, y), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f992(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(y, _mm_div_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f993(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(_mm_min_ps(x, y), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f994(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(x, _mm_min_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f995(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(_mm_min_ps(x, y), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f996(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(y, _mm_min_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f997(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(_mm_max_ps(x, y), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f998(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(x, _mm_max_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f999(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(_mm_max_ps(x, y), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1000(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(y, _mm_max_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1001(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(_mm_and_ps(x, y), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1002(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(x, _mm_and_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1003(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(_mm_and_ps(x, y), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1004(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(y, _mm_and_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1005(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(_mm_or_ps(x, y), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1006(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(x, _mm_or_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1007(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(_mm_or_ps(x, y), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1008(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(y, _mm_or_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1009(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(_mm_xor_ps(x, y), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1010(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(x, _mm_xor_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1011(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(_mm_xor_ps(x, y), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1012(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(y, _mm_xor_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1013(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(_mm_andnot_ps(x, y), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1014(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(x, _mm_andnot_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1015(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(_mm_andnot_ps(x, y), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1016(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(y, _mm_andnot_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1017(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1018(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(x, _mm_cmp_ps(x, y, _CMP_EQ_OQ)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1019(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1020(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(y, _mm_cmp_ps(x, y, _CMP_EQ_OQ)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1021(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1022(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(x, _mm_cmp_ps(x, y, _CMP_LT_OS)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1023(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1024(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(y, _mm_cmp_ps(x, y, _CMP_LT_OS)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1025(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1026(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(x, _mm_cmp_ps(x, y, _CMP_LE_OS)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1027(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1028(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(y, _mm_cmp_ps(x, y, _CMP_LE_OS)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1029(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(_mm_cmp_ps(x, y, _CMP_NEQ_UQ), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1030(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(x, _mm_cmp_ps(x, y, _CMP_NEQ_UQ)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1031(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(_mm_cmp_ps(x, y, _CMP_NEQ_UQ), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1032(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(y, _mm_cmp_ps(x, y, _CMP_NEQ_UQ)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1033(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1034(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(x, _mm_cmp_ps(x, y, _CMP_UNORD_Q)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1035(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1036(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(y, _mm_cmp_ps(x, y, _CMP_UNORD_Q)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1037(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1038(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(x, _mm_cmp_ps(x, y, _CMP_NLT_US)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1039(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1040(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(y, _mm_cmp_ps(x, y, _CMP_NLT_US)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1041(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1042(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(x, _mm_cmp_ps(x, y, _CMP_GT_OS)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1043(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1044(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(y, _mm_cmp_ps(x, y, _CMP_GT_OS)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1045(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LT_OS)), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1046(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(x, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LT_OS))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1047(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LT_OS)), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1048(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(y, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LT_OS))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1049(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LT_OS)), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1050(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(x, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LT_OS))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1051(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LT_OS)), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1052(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(y, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LT_OS))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1053(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), y)), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1054(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(x, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), y))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1055(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), y)), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1056(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(y, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), y))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1057(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LE_OS)), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1058(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(x, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LE_OS))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1059(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LE_OS)), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1060(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(y, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LE_OS))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1061(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LE_OS)), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1062(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(x, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LE_OS))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1063(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LE_OS)), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1064(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(y, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LE_OS))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1065(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), y)), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1066(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(x, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), y))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1067(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), y)), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1068(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(y, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), y))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1069(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_GT_OS)), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1070(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(x, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_GT_OS))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1071(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_GT_OS)), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1072(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(y, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_GT_OS))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1073(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_GT_OS)), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1074(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(x, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_GT_OS))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1075(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_GT_OS)), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1076(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(y, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_GT_OS))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1077(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), y)), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1078(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(x, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), y))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1079(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), y)), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1080(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(y, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), y))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1081(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_NLT_US)), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1082(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(x, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_NLT_US))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1083(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_NLT_US)), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1084(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(y, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_NLT_US))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1085(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_NLT_US)), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1086(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(x, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_NLT_US))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1087(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_NLT_US)), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1088(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(y, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_NLT_US))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1089(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), y)), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1090(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(x, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), y))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1091(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), y)), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1092(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(y, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), y))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1093(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_EQ_OQ)), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1094(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(x, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_EQ_OQ))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1095(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_EQ_OQ)), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1096(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(y, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_EQ_OQ))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1097(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_EQ_OQ)), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1098(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(x, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_EQ_OQ))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1099(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_EQ_OQ)), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1100(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(y, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_EQ_OQ))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1101(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), y)), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1102(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(x, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), y))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1103(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), y)), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1104(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(y, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), y))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1105(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_UNORD_Q)), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1106(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(x, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_UNORD_Q))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1107(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_UNORD_Q)), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1108(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(y, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_UNORD_Q))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1109(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_UNORD_Q)), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1110(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(x, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_UNORD_Q))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1111(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_UNORD_Q)), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1112(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(y, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_UNORD_Q))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1113(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), y)), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1114(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(x, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), y))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1115(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), y)), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1116(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(y, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), y))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1117(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(_mm_unpacklo_ps(x, y), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1118(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(x, _mm_unpacklo_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1119(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(_mm_unpacklo_ps(x, y), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1120(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(y, _mm_unpacklo_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1121(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(_mm_unpackhi_ps(x, y), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1122(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(x, _mm_unpackhi_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1123(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(_mm_unpackhi_ps(x, y), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1124(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(y, _mm_unpackhi_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1125(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(_mm_hadd_ps(x, y), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1126(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(x, _mm_hadd_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1127(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(_mm_hadd_ps(x, y), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1128(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(y, _mm_hadd_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1129(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(_mm_hsub_ps(x, y), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1130(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(x, _mm_hsub_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1131(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(_mm_hsub_ps(x, y), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1132(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(y, _mm_hsub_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1133(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(_mm_shuffle_ps(x, y, 0x1b), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1134(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(x, _mm_shuffle_ps(x, y, 0x1b)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1135(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(_mm_shuffle_ps(x, y, 0x1b), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1136(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(y, _mm_shuffle_ps(x, y, 0x1b)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1137(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(_mm_shuffle_ps(x, y, 0x39), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1138(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(x, _mm_shuffle_ps(x, y, 0x39)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1139(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(_mm_shuffle_ps(x, y, 0x39), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1140(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(y, _mm_shuffle_ps(x, y, 0x39)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1141(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(_mm_shuffle_ps(x, y, 0x93), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1142(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(x, _mm_shuffle_ps(x, y, 0x93)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1143(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(_mm_shuffle_ps(x, y, 0x93), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1144(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(y, _mm_shuffle_ps(x, y, 0x93)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1145(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(_mm_shuffle_ps(x, y, 0x4e), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1146(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(x, _mm_shuffle_ps(x, y, 0x4e)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1147(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(_mm_shuffle_ps(x, y, 0x4e), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1148(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(y, _mm_shuffle_ps(x, y, 0x4e)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1149(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_andnot_ps(_mm_add_ps(x, y), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1150(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_andnot_ps(x, _mm_add_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1151(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_andnot_ps(_mm_add_ps(x, y), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1152(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_andnot_ps(y, _mm_add_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1153(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_andnot_ps(_mm_sub_ps(x, y), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1154(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_andnot_ps(x, _mm_sub_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1155(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_andnot_ps(_mm_sub_ps(x, y), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1156(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_andnot_ps(y, _mm_sub_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1157(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_andnot_ps(_mm_mul_ps(x, y), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1158(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_andnot_ps(x, _mm_mul_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1159(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_andnot_ps(_mm_mul_ps(x, y), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1160(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_andnot_ps(y, _mm_mul_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1161(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_andnot_ps(_mm_div_ps(x, y), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1162(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_andnot_ps(x, _mm_div_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1163(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_andnot_ps(_mm_div_ps(x, y), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1164(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_andnot_ps(y, _mm_div_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1165(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_andnot_ps(_mm_min_ps(x, y), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1166(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_andnot_ps(x, _mm_min_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1167(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_andnot_ps(_mm_min_ps(x, y), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1168(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_andnot_ps(y, _mm_min_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1169(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_andnot_ps(_mm_max_ps(x, y), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1170(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_andnot_ps(x, _mm_max_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1171(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_andnot_ps(_mm_max_ps(x, y), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1172(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_andnot_ps(y, _mm_max_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1173(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_andnot_ps(_mm_and_ps(x, y), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1174(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_andnot_ps(x, _mm_and_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1175(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_andnot_ps(_mm_and_ps(x, y), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1176(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_andnot_ps(y, _mm_and_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1177(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_andnot_ps(_mm_or_ps(x, y), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1178(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_andnot_ps(x, _mm_or_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1179(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_andnot_ps(_mm_or_ps(x, y), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1180(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_andnot_ps(y, _mm_or_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1181(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_andnot_ps(_mm_xor_ps(x, y), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1182(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_andnot_ps(x, _mm_xor_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1183(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_andnot_ps(_mm_xor_ps(x, y), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1184(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_andnot_ps(y, _mm_xor_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1185(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_andnot_ps(_mm_andnot_ps(x, y), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1186(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_andnot_ps(x, _mm_andnot_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1187(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_andnot_ps(_mm_andnot_ps(x, y), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1188(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_andnot_ps(y, _mm_andnot_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1189(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1190(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_andnot_ps(x, _mm_cmp_ps(x, y, _CMP_EQ_OQ)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1191(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1192(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_andnot_ps(y, _mm_cmp_ps(x, y, _CMP_EQ_OQ)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1193(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1194(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_andnot_ps(x, _mm_cmp_ps(x, y, _CMP_LT_OS)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1195(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1196(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_andnot_ps(y, _mm_cmp_ps(x, y, _CMP_LT_OS)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1197(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1198(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_andnot_ps(x, _mm_cmp_ps(x, y, _CMP_LE_OS)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1199(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), x); _mm_storeu_ps((float*)po, r); }
extern const Entry table_26[] = {
  {"128:_mm_mul_ps(y, _mm_cmp_ps(x, y, _CMP_NEQ_UQ))", f0, 1, 128},
  {"128:_mm_mul_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), y)", f1, 1, 128},
  {"128:_mm_mul_ps(x, _mm_cmp_ps(x, y, _CMP_UNORD_Q))", f2, 1, 128},
  {"128:_mm_mul_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), x)", f3, 1, 128},
  {"128:_mm_mul_ps(y, _mm_cmp_ps(x, y, _CMP_UNORD_Q))", f4, 1, 128},
  {"128:_mm_mul_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), y)", f5, 1, 128},
  {"128:_mm_mul_ps(x, _mm_cmp_ps(x, y, _CMP_NLT_US))", f6, 1, 128},
  {"128:_mm_mul_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), x)", f7, 1, 128},
  {"128:_mm_mul_ps(y, _mm_cmp_ps(x, y, _CMP_NLT_US))", f8, 1, 128},
  {"128:_mm_mul_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), y)", f9, 1, 128},
  {"128:_mm_mul_ps(x, _mm_cmp_ps(x, y, _CMP_GT_OS))", f10, 1, 128},
  {"128:_mm_mul_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), x)", f11, 1, 128},
  {"128:_mm_mul_ps(y, _mm_cmp_ps(x, y, _CMP_GT_OS))", f12, 1, 128},
  {"128:_mm_mul_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LT_OS)), y)", f13, 1, 128},
  {"128:_mm_mul_ps(x, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LT_OS)))", f14, 1, 128},
  {"128:_mm_mul_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LT_OS)), x)", f15, 1, 128},
  {"128:_mm_mul_ps(y, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LT_OS)))", f16, 1, 128},
  {"128:_mm_mul_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LT_OS)), y)", f17, 1, 128},
  {"128:_mm_mul_ps(x, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LT_OS)))", f18, 1, 128},
  {"128:_mm_mul_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LT_OS)), x)", f19, 1, 128},
  {"128:_mm_mul_ps(y, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LT_OS)))", f20, 1, 128},
  {"128:_mm_mul_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), y)), y)", f21, 1, 128},
  {"128:_mm_mul_ps(x, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), y)))", f22, 1, 128},
  {"128:_mm_mul_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), y)), x)", f23, 1, 128},
  {"128:_mm_mul_ps(y, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), y)))", f24, 1, 128},
  {"128:_mm_mul_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LE_OS)), y)", f25, 1, 128},
  {"128:_mm_mul_ps(x, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LE_OS)))", f26, 1, 128},
  {"128:_mm_mul_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LE_OS)), x)", f27, 1, 128},
  {"128:_mm_mul_ps(y, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LE_OS)))", f28, 1, 128},
  {"128:_mm_mul_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LE_OS)), y)", f29, 1, 128},
  {"128:_mm_mul_ps(x, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LE_OS)))", f30, 1, 128},
  {"128:_mm_mul_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LE_OS)), x)", f31, 1, 128},
  {"128:_mm_mul_ps(y, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LE_OS)))", f32, 1, 128},
  {"128:_mm_mul_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), y)), y)", f33, 1, 128},
  {"128:_mm_mul_ps(x, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), y)))", f34, 1, 128},
  {"128:_mm_mul_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), y)), x)", f35, 1, 128},
  {"128:_mm_mul_ps(y, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), y)))", f36, 1, 128},
  {"128:_mm_mul_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_GT_OS)), y)", f37, 1, 128},
  {"128:_mm_mul_ps(x, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_GT_OS)))", f38, 1, 128},
  {"128:_mm_mul_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_GT_OS)), x)", f39, 1, 128},
  {"128:_mm_mul_ps(y, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_GT_OS)))", f40, 1, 128},
  {"128:_mm_mul_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_GT_OS)), y)", f41, 1, 128},
  {"128:_mm_mul_ps(x, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_GT_OS)))", f42, 1, 128},
  {"128:_mm_mul_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_GT_OS)), x)", f43, 1, 128},
  {"128:_mm_mul_ps(y, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_GT_OS)))", f44, 1, 128},
  {"128:_mm_mul_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), y)), y)", f45, 1, 128},
  {"128:_mm_mul_ps(x, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), y)))", f46, 1, 128},
  {"128:_mm_mul_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), y)), x)", f47, 1, 128},
  {"128:_mm_mul_ps(y, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), y)))", f48, 1, 128},
  {"128:_mm_mul_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_NLT_US)), y)", f49, 1, 128},
  {"128:_mm_mul_ps(x, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_NLT_US)))", f50, 1, 128},
  {"128:_mm_mul_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_NLT_US)), x)", f51, 1, 128},
  {"128:_mm_mul_ps(y, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_NLT_US)))", f52, 1, 128},
  {"128:_mm_mul_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_NLT_US)), y)", f53, 1, 128},
  {"128:_mm_mul_ps(x, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_NLT_US)))", f54, 1, 128},
  {"128:_mm_mul_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_NLT_US)), x)", f55, 1, 128},
  {"128:_mm_mul_ps(y, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_NLT_US)))", f56, 1, 128},
  {"128:_mm_mul_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), y)), y)", f57, 1, 128},
  {"128:_mm_mul_ps(x, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), y)))", f58, 1, 128},
  {"128:_mm_mul_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), y)), x)", f59, 1, 128},
  {"128:_mm_mul_ps(y, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), y)))", f60, 1, 128},
  {"128:_mm_mul_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_EQ_OQ)), y)", f61, 1, 128},
  {"128:_mm_mul_ps(x, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_EQ_OQ)))", f62, 1, 128},
  {"128:_mm_mul_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_EQ_OQ)), x)", f63, 1, 128},
  {"128:_mm_mul_ps(y, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_EQ_OQ)))", f64, 1, 128},
  {"128:_mm_mul_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_EQ_OQ)), y)", f65, 1, 128},
  {"128:_mm_mul_ps(x, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_EQ_OQ)))", f66, 1, 128},
  {"128:_mm_mul_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_EQ_OQ)), x)", f67, 1, 128},
  {"128:_mm_mul_ps(y, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_EQ_OQ)))", f68, 1, 128},
  {"128:_mm_mul_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), y)), y)", f69, 1, 128},
  {"128:_mm_mul_ps(x, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), y)))", f70, 1, 128},
  {"128:_mm_mul_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), y)), x)", f71, 1, 128},
  {"128:_mm_mul_ps(y, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), y)))", f72, 1, 128},
  {"128:_mm_mul_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_UNORD_Q)), y)", f73, 1, 128},
  {"128:_mm_mul_ps(x, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_UNORD_Q)))", f74, 1, 128},
  {"128:_mm_mul_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_UNORD_Q)), x)", f75, 1, 128},
  {"128:_mm_mul_ps(y, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_UNORD_Q)))", f76, 1, 128},
  {"128:_mm_mul_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_UNORD_Q)), y)", f77, 1, 128},
  {"128:_mm_mul_ps(x, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_UNORD_Q)))", f78, 1, 128},
  {"128:_mm_mul_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_UNORD_Q)), x)", f79, 1, 128},
  {"128:_mm_mul_ps(y, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_UNORD_Q)))", f80, 1, 128},
  {"128:_mm_mul_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), y)), y)", f81, 1, 128},
  {"128:_mm_mul_ps(x, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), y)))", f82, 1, 128},
  {"128:_mm_mul_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), y)), x)", f83, 1, 128},
  {"128:_mm_mul_ps(y, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), y)))", f84, 1, 128},
  {"128:_mm_mul_ps(_mm_unpacklo_ps(x, y), y)", f85, 1, 128},
  {"128:_mm_mul_ps(x, _mm_unpacklo_ps(x, y))", f86, 1, 128},
  {"128:_mm_mul_ps(_mm_unpacklo_ps(x, y), x)", f87, 1, 128},
  {"128:_mm_mul_ps(y, _mm_unpacklo_ps(x, y))", f88, 1, 128},
  {"128:_mm_mul_ps(_mm_unpackhi_ps(x, y), y)", f89, 1, 128},
  {"128:_mm_mul_ps(x, _mm_unpackhi_ps(x, y))", f90, 1, 128},
  {"128:_mm_mul_ps(_mm_unpackhi_ps(x, y), x)", f91, 1, 128},
  {"128:_mm_mul_ps(y, _mm_unpackhi_ps(x, y))", f92, 1, 128},
  {"128:_mm_mul_ps(_mm_hadd_ps(x, y), y)", f93, 1, 128},
  {"128:_mm_mul_ps(x, _mm_hadd_ps(x, y))", f94, 1, 128},
  {"128:_mm_mul_ps(_mm_hadd_ps(x, y), x)", f95, 1, 128},
  {"128:_mm_mul_ps(y, _mm_hadd_ps(x, y))", f96, 1, 128},
  {"128:_mm_mul_ps(_mm_hsub_ps(x, y), y)", f97, 1, 128},
  {"128:_mm_mul_ps(x, _mm_hsub_ps(x, y))", f98, 1, 128},
  {"128:_mm_mul_ps(_mm_hsub_ps(x, y), x)", f99, 1, 128},
  {"128:_mm_mul_ps(y, _mm_hsub_ps(x, y))", f100, 1, 128},
  {"128:_mm_mul_ps(_mm_shuffle_ps(x, y, 0x1b), y)", f101, 1, 128},
  {"128:_mm_mul_ps(x, _mm_shuffle_ps(x, y, 0x1b))", f102, 1, 128},
  {"128:_mm_mul_ps(_mm_shuffle_ps(x, y, 0x1b), x)", f103, 1, 128},
  {"128:_mm_mul_ps(y, _mm_shuffle_ps(x, y, 0x1b))", f104, 1, 128},
  {"128:_mm_mul_ps(_mm_shuffle_ps(x, y, 0x39), y)", f105, 1, 128},
  {"128:_mm_mul_ps(x, _mm_shuffle_ps(x, y, 0x39))", f106, 1, 128},
  {"128:_mm_mul_ps(_mm_shuffle_ps(x, y, 0x39), x)", f107, 1, 128},
  {"128:_mm_mul_ps(y, _mm_shuffle_ps(x, y, 0x39))", f108, 1, 128},
  {"128:_mm_mul_ps(_mm_shuffle_ps(x, y, 0x93), y)", f109, 1, 128},
  {"128:_mm_mul_ps(x, _mm_shuffle_ps(x, y, 0x93))", f110, 1, 128},
  {"128:_mm_mul_ps(_mm_shuffle_ps(x, y, 0x93), x)", f111, 1, 128},
  {"128:_mm_mul_ps(y, _mm_shuffle_ps(x, y, 0x93))", f112, 1, 128},
  {"128:_mm_mul_ps(_mm_shuffle_ps(x, y, 0x4e), y)", f113, 1, 128},
  {"128:_mm_mul_ps(x, _mm_shuffle_ps(x, y, 0x4e))", f114, 1, 128},
  {"128:_mm_mul_ps(_mm_shuffle_ps(x, y, 0x4e), x)", f115, 1, 128},
  {"128:_mm_mul_ps(y, _mm_shuffle_ps(x, y, 0x4e))", f116, 1, 128},
  {"128:_mm_div_ps(_mm_add_ps(x, y), y)", f117, 1, 128},
  {"128:_mm_div_ps(x, _mm_add_ps(x, y))", f118, 1, 128},
  {"128:_mm_div_ps(_mm_add_ps(x, y), x)", f119, 1, 128},
  {"128:_mm_div_ps(y, _mm_add_ps(x, y))", f120, 1, 128},
  {"128:_mm_div_ps(_mm_sub_ps(x, y), y)", f121, 1, 128},
  {"128:_mm_div_ps(x, _mm_sub_ps(x, y))", f122, 1, 128},
  {"128:_mm_div_ps(_mm_sub_ps(x, y), x)", f123, 1, 128},
  {"128:_mm_div_ps(y, _mm_sub_ps(x, y))", f124, 1, 128},
  {"128:_mm_div_ps(_mm_mul_ps(x, y), y)", f125, 1, 128},
  {"128:_mm_div_ps(x, _mm_mul_ps(x, y))", f126, 1, 128},
  {"128:_mm_div_ps(_mm_mul_ps(x, y), x)", f127, 1, 128},
  {"128:_mm_div_ps(y, _mm_mul_ps(x, y))", f128, 1, 128},
  {"128:_mm_div_ps(_mm_div_ps(x, y), y)", f129, 1, 128},
  {"128:_mm_div_ps(x, _mm_div_ps(x, y))", f130, 1, 128},
  {"128:_mm_div_ps(_mm_div_ps(x, y), x)", f131, 1, 128},
  {"128:_mm_div_ps(y, _mm_div_ps(x, y))", f132, 1, 128},
  {"128:_mm_div_ps(_mm_min_ps(x, y), y)", f133, 1, 128},
  {"128:_mm_div_ps(x, _mm_min_ps(x, y))", f134, 1, 128},
  {"128:_mm_div_ps(_mm_min_ps(x, y), x)", f135, 1, 128},
  {"128:_mm_div_ps(y, _mm_min_ps(x, y))", f136, 1, 128},
  {"128:_mm_div_ps(_mm_max_ps(x, y), y)", f137, 1, 128},
  {"128:_mm_div_ps(x, _mm_max_ps(x, y))", f138, 1, 128},
  {"128:_mm_div_ps(_mm_max_ps(x, y), x)", f139, 1, 128},
  {"128:_mm_div_ps(y, _mm_max_ps(x, y))", f140, 1, 128},
  {"128:_mm_div_ps(_mm_and_ps(x, y), y)", f141, 1, 128},
  {"128:_mm_div_ps(x, _mm_and_ps(x, y))", f142, 1, 128},
  {"128:_mm_div_ps(_mm_and_ps(x, y), x)", f143, 1, 128},
  {"128:_mm_div_ps(y, _mm_and_ps(x, y))", f144, 1, 128},
  {"128:_mm_div_ps(_mm_or_ps(x, y), y)", f145, 1, 128},
  {"128:_mm_div_ps(x, _mm_or_ps(x, y))", f146, 1, 128},
  {"128:_mm_div_ps(_mm_or_ps(x, y), x)", f147, 1, 128},
  {"128:_mm_div_ps(y, _mm_or_ps(x, y))", f148, 1, 128},
  {"128:_mm_div_ps(_mm_xor_ps(x, y), y)", f149, 1, 128},
  {"128:_mm_div_ps(x, _mm_xor_ps(x, y))", f150, 1, 128},
  {"128:_mm_div_ps(_mm_xor_ps(x, y), x)", f151, 1, 128},
  {"128:_mm_div_ps(y, _mm_xor_ps(x, y))", f152, 1, 128},
  {"128:_mm_div_ps(_mm_andnot_ps(x, y), y)", f153, 1, 128},
  {"128:_mm_div_ps(x, _mm_andnot_ps(x, y))", f154, 1, 128},
  {"128:_mm_div_ps(_mm_andnot_ps(x, y), x)", f155, 1, 128},
  {"128:_mm_div_ps(y, _mm_andnot_ps(x, y))", f156, 1, 128},
  {"128:_mm_div_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), y)", f157, 1, 128},
  {"128:_mm_div_ps(x, _mm_cmp_ps(x, y, _CMP_EQ_OQ))", f158, 1, 128},
  {"128:_mm_div_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), x)", f159, 1, 128},
  {"128:_mm_div_ps(y, _mm_cmp_ps(x, y, _CMP_EQ_OQ))", f160, 1, 128},
  {"128:_mm_div_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), y)", f161, 1, 128},
  {"128:_mm_div_ps(x, _mm_cmp_ps(x, y, _CMP_LT_OS))", f162, 1, 128},
  {"128:_mm_div_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), x)", f163, 1, 128},
  {"128:_mm_div_ps(y, _mm_cmp_ps(x, y, _CMP_LT_OS))", f164, 1, 128},
  {"128:_mm_div_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), y)", f165, 1, 128},
  {"128:_mm_div_ps(x, _mm_cmp_ps(x, y, _CMP_LE_OS))", f166, 1, 128},
  {"128:_mm_div_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), x)", f167, 1, 128},
  {"128:_mm_div_ps(y, _mm_cmp_ps(x, y, _CMP_LE_OS))", f168, 1, 128},
  {"128:_mm_div_ps(_mm_cmp_ps(x, y, _CMP_NEQ_UQ), y)", f169, 1, 128},
  {"128:_mm_div_ps(x, _mm_cmp_ps(x, y, _CMP_NEQ_UQ))", f170, 1, 128},
  {"128:_mm_div_ps(_mm_cmp_ps(x, y, _CMP_NEQ_UQ), x)", f171, 1, 128},
  {"128:_mm_div_ps(y, _mm_cmp_ps(x, y, _CMP_NEQ_UQ))", f172, 1, 128},
  {"128:_mm_div_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), y)", f173, 1, 128},
  {"128:_mm_div_ps(x, _mm_cmp_ps(x, y, _CMP_UNORD_Q))", f174, 1, 128},
  {"128:_mm_div_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), x)", f175, 1, 128},
  {"128:_mm_div_ps(y, _mm_cmp_ps(x, y, _CMP_UNORD_Q))", f176, 1, 128},
  {"128:_mm_div_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), y)", f177, 1, 128},
  {"128:_mm_div_ps(x, _mm_cmp_ps(x, y, _CMP_NLT_US))", f178, 1, 128},
  {"128:_mm_div_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), x)", f179, 1, 128},
  {"128:_mm_div_ps(y, _mm_cmp_ps(x, y, _CMP_NLT_US))", f180, 1, 128},
  {"128:_mm_div_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), y)", f181, 1, 128},
  {"128:_mm_div_ps(x, _mm_cmp_ps(x, y, _CMP_GT_OS))", f182, 1, 128},
  {"128:_mm_div_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), x)", f183, 1, 128},
  {"128:_mm_div_ps(y, _mm_cmp_ps(x, y, _CMP_GT_OS))", f184, 1, 128},
  {"128:_mm_div_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LT_OS)), y)", f185, 1, 128},
  {"128:_mm_div_ps(x, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LT_OS)))", f186, 1, 128},
  {"128:_mm_div_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LT_OS)), x)", f187, 1, 128},
  {"128:_mm_div_ps(y, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LT_OS)))", f188, 1, 128},
  {"128:_mm_div_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LT_OS)), y)", f189, 1, 128},
  {"128:_mm_div_ps(x, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LT_OS)))", f190, 1, 128},
  {"128:_mm_div_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LT_OS)), x)", f191, 1, 128},
  {"128:_mm_div_ps(y, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LT_OS)))", f192, 1, 128},
  {"128:_mm_div_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), y)), y)", f193, 1, 128},
  {"128:_mm_div_ps(x, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), y)))", f194, 1, 128},
  {"128:_mm_div_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), y)), x)", f195, 1, 128},
  {"128:_mm_div_ps(y, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), y)))", f196, 1, 128},
  {"128:_mm_div_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LE_OS)), y)", f197, 1, 128},
  {"128:_mm_div_ps(x, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LE_OS)))", f198, 1, 128},
  {"128:_mm_div_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LE_OS)), x)", f199, 1, 128},
  {"128:_mm_div_ps(y, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LE_OS)))", f200, 1, 128},
  {"128:_mm_div_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LE_OS)), y)", f201, 1, 128},
  {"128:_mm_div_ps(x, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LE_OS)))", f202, 1, 128},
  {"128:_mm_div_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LE_OS)), x)", f203, 1, 128},
  {"128:_mm_div_ps(y, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LE_OS)))", f204, 1, 128},
  {"128:_mm_div_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), y)), y)", f205, 1, 128},
  {"128:_mm_div_ps(x, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), y)))", f206, 1, 128},
  {"128:_mm_div_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), y)), x)", f207, 1, 128},
  {"128:_mm_div_ps(y, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), y)))", f208, 1, 128},
  {"128:_mm_div_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_GT_OS)), y)", f209, 1, 128},
  {"128:_mm_div_ps(x, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_GT_OS)))", f210, 1, 128},
  {"128:_mm_div_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_GT_OS)), x)", f211, 1, 128},
  {"128:_mm_div_ps(y, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_GT_OS)))", f212, 1, 128},
  {"128:_mm_div_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_GT_OS)), y)", f213, 1, 128},
  {"128:_mm_div_ps(x, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_GT_OS)))", f214, 1, 128},
  {"128:_mm_div_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_GT_OS)), x)", f215, 1, 128},
  {"128:_mm_div_ps(y, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_GT_OS)))", f216, 1, 128},
  {"128:_mm_div_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), y)), y)", f217, 1, 128},
  {"128:_mm_div_ps(x, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), y)))", f218, 1, 128},
  {"128:_mm_div_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), y)), x)", f219, 1, 128},
  {"128:_mm_div_ps(y, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), y)))", f220, 1, 128},
  {"128:_mm_div_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_NLT_US)), y)", f221, 1, 128},
  {"128:_mm_div_ps(x, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_NLT_US)))", f222, 1, 128},
  {"128:_mm_div_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_NLT_US)), x)", f223, 1, 128},
  {"128:_mm_div_ps(y, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_NLT_US)))", f224, 1, 128},
  {"128:_mm_div_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_NLT_US)), y)", f225, 1, 128},
  {"128:_mm_div_ps(x, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_NLT_US)))", f226, 1, 128},
  {"128:_mm_div_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_NLT_US)), x)", f227, 1, 128},
  {"128:_mm_div_ps(y, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_NLT_US)))", f228, 1, 128},
  {"128:_mm_div_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), y)), y)", f229, 1, 128},
  {"128:_mm_div_ps(x, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), y)))", f230, 1, 128},
  {"128:_mm_div_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), y)), x)", f231, 1, 128},
  {"128:_mm_div_ps(y, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), y)))", f232, 1, 128},
  {"128:_mm_div_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_EQ_OQ)), y)", f233, 1, 128},
  {"128:_mm_div_ps(x, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_EQ_OQ)))", f234, 1, 128},
  {"128:_mm_div_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_EQ_OQ)), x)", f235, 1, 128},
  {"128:_mm_div_ps(y, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_EQ_OQ)))", f236, 1, 128},
  {"128:_mm_div_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_EQ_OQ)), y)", f237, 1, 128},
  {"128:_mm_div_ps(x, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_EQ_OQ)))", f238, 1, 128},
  {"128:_mm_div_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_EQ_OQ)), x)", f239, 1, 128},
  {"128:_mm_div_ps(y, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_EQ_OQ)))", f240, 1, 128},
  {"128:_mm_div_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), y)), y)", f241, 1, 128},
  {"128:_mm_div_ps(x, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), y)))", f242, 1, 128},
  {"128:_mm_div_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), y)), x)", f243, 1, 128},
  {"128:_mm_div_ps(y, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), y)))", f244, 1, 128},
  {"128:_mm_div_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_UNORD_Q)), y)", f245, 1, 128},
  {"128:_mm_div_ps(x, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_UNORD_Q)))", f246, 1, 128},
  {"128:_mm_div_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_UNORD_Q)), x)", f247, 1, 128},
  {"128:_mm_div_ps(y, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_UNORD_Q)))", f248, 1, 128},
  {"128:_mm_div_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_UNORD_Q)), y)", f249, 1, 128},
  {"128:_mm_div_ps(x, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_UNORD_Q)))", f250, 1, 128},
  {"128:_mm_div_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_UNORD_Q)), x)", f251, 1, 128},
  {"128:_mm_div_ps(y, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_UNORD_Q)))", f252, 1, 128},
  {"128:_mm_div_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), y)), y)", f253, 1, 128},
  {"128:_mm_div_ps(x, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), y)))", f254, 1, 128},
  {"128:_mm_div_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), y)), x)", f255, 1, 128},
  {"128:_mm_div_ps(y, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), y)))", f256, 1, 128},
  {"128:_mm_div_ps(_mm_unpacklo_ps(x, y), y)", f257, 1, 128},
  {"128:_mm_div_ps(x, _mm_unpacklo_ps(x, y))", f258, 1, 128},
  {"128:_mm_div_ps(_mm_unpacklo_ps(x, y), x)", f259, 1, 128},
  {"128:_mm_div_ps(y, _mm_unpacklo_ps(x, y))", f260, 1, 128},
  {"128:_mm_div_ps(_mm_unpackhi_ps(x, y), y)", f261, 1, 128},
  {"128:_mm_div_ps(x, _mm_unpackhi_ps(x, y))", f262, 1, 128},
  {"128:_mm_div_ps(_mm_unpackhi_ps(x, y), x)", f263, 1, 128},
  {"128:_mm_div_ps(y, _mm_unpackhi_ps(x, y))", f264, 1, 128},
  {"128:_mm_div_ps(_mm_hadd_ps(x, y), y)", f265, 1, 128},
  {"128:_mm_div_ps(x, _mm_hadd_ps(x, y))", f266, 1, 128},
  {"128:_mm_div_ps(_mm_hadd_ps(x, y), x)", f267, 1, 128},
  {"128:_mm_div_ps(y, _mm_hadd_ps(x, y))", f268, 1, 128},
  {"128:_mm_div_ps(_mm_hsub_ps(x, y), y)", f269, 1, 128},
  {"128:_mm_div_ps(x, _mm_hsub_ps(x, y))", f270, 1, 128},
  {"128:_mm_div_ps(_mm_hsub_ps(x, y), x)", f271, 1, 128},
  {"128:_mm_div_ps(y, _mm_hsub_ps(x, y))", f272, 1, 128},
  {"128:_mm_div_ps(_mm_shuffle_ps(x, y, 0x1b), y)", f273, 1, 128},
  {"128:_mm_div_ps(x, _mm_shuffle_ps(x, y, 0x1b))", f274, 1, 128},
  {"128:_mm_div_ps(_mm_shuffle_ps(x, y, 0x1b), x)", f275, 1, 128},
  {"128:_mm_div_ps(y, _mm_shuffle_ps(x, y, 0x1b))", f276, 1, 128},
  {"128:_mm_div_ps(_mm_shuffle_ps(x, y, 0x39), y)", f277, 1, 128},
  {"128:_mm_div_ps(x, _mm_shuffle_ps(x, y, 0x39))", f278, 1, 128},
  {"128:_mm_div_ps(_mm_shuffle_ps(x, y, 0x39), x)", f279, 1, 128},
  {"128:_mm_div_ps(y, _mm_shuffle_ps(x, y, 0x39))", f280, 1, 128},
  {"128:_mm_div_ps(_mm_shuffle_ps(x, y, 0x93), y)", f281, 1, 128},
  {"128:_mm_div_ps(x, _mm_shuffle_ps(x, y, 0x93))", f282, 1, 128},
  {"128:_mm_div_ps(_mm_shuffle_ps(x, y, 0x93), x)", f283, 1, 128},
  {"128:_mm_div_ps(y, _mm_shuffle_ps(x, y, 0x93))", f284, 1, 128},
  {"128:_mm_div_ps(_mm_shuffle_ps(x, y, 0x4e), y)", f285, 1, 128},
  {"128:_mm_div_ps(x, _mm_shuffle_ps(x, y, 0x4e))", f286, 1, 128},
  {"128:_mm_div_ps(_mm_shuffle_ps(x, y, 0x4e), x)", f287, 1, 128},
  {"128:_mm_div_ps(y, _mm_shuffle_ps(x, y, 0x4e))", f288, 1, 128},
  {"128:_mm_min_ps(_mm_add_ps(x, y), y)", f289, 1, 128},
  {"128:_mm_min_ps(x, _mm_add_ps(x, y))", f290, 1, 128},
  {"128:_mm_min_ps(_mm_add_ps(x, y), x)", f291, 1, 128},
  {"128:_mm_min_ps(y, _mm_add_ps(x, y))", f292, 1, 128},
  {"128:_mm_min_ps(_mm_sub_ps(x, y), y)", f293, 1, 128},
  {"128:_mm_min_ps(x, _mm_sub_ps(x, y))", f294, 1, 128},
  {"128:_mm_min_ps(_mm_sub_ps(x, y), x)", f295, 1, 128},
  {"128:_mm_min_ps(y, _mm_sub_ps(x, y))", f296, 1, 128},
  {"128:_mm_min_ps(_mm_mul_ps(x, y), y)", f297, 1, 128},
  {"128:_mm_min_ps(x, _mm_mul_ps(x, y))", f298, 1, 128},
  {"128:_mm_min_ps(_mm_mul_ps(x, y), x)", f299, 1, 128},
  {"128:_mm_min_ps(y, _mm_mul_ps(x, y))", f300, 1, 128},
  {"128:_mm_min_ps(_mm_div_ps(x, y), y)", f301, 1, 128},
  {"128:_mm_min_ps(x, _mm_div_ps(x, y))", f302, 1, 128},
  {"128:_mm_min_ps(_mm_div_ps(x, y), x)", f303, 1, 128},
  {"128:_mm_min_ps(y, _mm_div_ps(x, y))", f304, 1, 128},
  {"128:_mm_min_ps(_mm_min_ps(x, y), y)", f305, 1, 128},
  {"128:_mm_min_ps(x, _mm_min_ps(x, y))", f306, 1, 128},
  {"128:_mm_min_ps(_mm_min_ps(x, y), x)", f307, 1, 128},
  {"128:_mm_min_ps(y, _mm_min_ps(x, y))", f308, 1, 128},
  {"128:_mm_min_ps(_mm_max_ps(x, y), y)", f309, 1, 128},
  {"128:_mm_min_ps(x, _mm_max_ps(x, y))", f310, 1, 128},
  {"128:_mm_min_ps(_mm_max_ps(x, y), x)", f311, 1, 128},
  {"128:_mm_min_ps(y, _mm_max_ps(x, y))", f312, 1, 128},
  {"128:_mm_min_ps(_mm_and_ps(x, y), y)", f313, 1, 128},
  {"128:_mm_min_ps(x, _mm_and_ps(x, y))", f314, 1, 128},
  {"128:_mm_min_ps(_mm_and_ps(x, y), x)", f315, 1, 128},
  {"128:_mm_min_ps(y, _mm_and_ps(x, y))", f316, 1, 128},
  {"128:_mm_min_ps(_mm_or_ps(x, y), y)", f317, 1, 128},
  {"128:_mm_min_ps(x, _mm_or_ps(x, y))", f318, 1, 128},
  {"128:_mm_min_ps(_mm_or_ps(x, y), x)", f319, 1, 128},
  {"128:_mm_min_ps(y, _mm_or_ps(x, y))", f320, 1, 128},
  {"128:_mm_min_ps(_mm_xor_ps(x, y), y)", f321, 1, 128},
  {"128:_mm_min_ps(x, _mm_xor_ps(x, y))", f322, 1, 128},
  {"128:_mm_min_ps(_mm_xor_ps(x, y), x)", f323, 1, 128},
  {"128:_mm_min_ps(y, _mm_xor_ps(x, y))", f324, 1, 128},
  {"128:_mm_min_ps(_mm_andnot_ps(x, y), y)", f325, 1, 128},
  {"128:_mm_min_ps(x, _mm_andnot_ps(x, y))", f326, 1, 128},
  {"128:_mm_min_ps(_mm_andnot_ps(x, y), x)", f327, 1, 128},
  {"128:_mm_min_ps(y, _mm_andnot_ps(x, y))", f328, 1, 128},
  {"128:_mm_min_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), y)", f329, 1, 128},
  {"128:_mm_min_ps(x, _mm_cmp_ps(x, y, _CMP_EQ_OQ))", f330, 1, 128},
  {"128:_mm_min_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), x)", f331, 1, 128},
  {"128:_mm_min_ps(y, _mm_cmp_ps(x, y, _CMP_EQ_OQ))", f332, 1, 128},
  {"128:_mm_min_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), y)", f333, 1, 128},
  {"128:_mm_min_ps(x, _mm_cmp_ps(x, y, _CMP_LT_OS))", f334, 1, 128},
  {"128:_mm_min_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), x)", f335, 1, 128},
  {"128:_mm_min_ps(y, _mm_cmp_ps(x, y, _CMP_LT_OS))", f336, 1, 128},
  {"128:_mm_min_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), y)", f337, 1, 128},
  {"128:_mm_min_ps(x, _mm_cmp_ps(x, y, _CMP_LE_OS))", f338, 1, 128},
  {"128:_mm_min_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), x)", f339, 1, 128},
  {"128:_mm_min_ps(y, _mm_cmp_ps(x, y, _CMP_LE_OS))", f340, 1, 128},
  {"128:_mm_min_ps(_mm_cmp_ps(x, y, _CMP_NEQ_UQ), y)", f341, 1, 128},
  {"128:_mm_min_ps(x, _mm_cmp_ps(x, y, _CMP_NEQ_UQ))", f342, 1, 128},
  {"128:_mm_min_ps(_mm_cmp_ps(x, y, _CMP_NEQ_UQ), x)", f343, 1, 128},
  {"128:_mm_min_ps(y, _mm_cmp_ps(x, y, _CMP_NEQ_UQ))", f344, 1, 128},
  {"128:_mm_min_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), y)", f345, 1, 128},
  {"128:_mm_min_ps(x, _mm_cmp_ps(x, y, _CMP_UNORD_Q))", f346, 1, 128},
  {"128:_mm_min_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), x)", f347, 1, 128},
  {"128:_mm_min_ps(y, _mm_cmp_ps(x, y, _CMP_UNORD_Q))", f348, 1, 128},
  {"128:_mm_min_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), y)", f349, 1, 128},
  {"128:_mm_min_ps(x, _mm_cmp_ps(x, y, _CMP_NLT_US))", f350, 1, 128},
  {"128:_mm_min_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), x)", f351, 1, 128},
  {"128:_mm_min_ps(y, _mm_cmp_ps(x, y, _CMP_NLT_US))", f352, 1, 128},
  {"128:_mm_min_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), y)", f353, 1, 128},
  {"128:_mm_min_ps(x, _mm_cmp_ps(x, y, _CMP_GT_OS))", f354, 1, 128},
  {"128:_mm_min_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), x)", f355, 1, 128},
  {"128:_mm_min_ps(y, _mm_cmp_ps(x, y, _CMP_GT_OS))", f356, 1, 128},
  {"128:_mm_min_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LT_OS)), y)", f357, 1, 128},
  {"128:_mm_min_ps(x, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LT_OS)))", f358, 1, 128},
  {"128:_mm_min_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LT_OS)), x)", f359, 1, 128},
  {"128:_mm_min_ps(y, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LT_OS)))", f360, 1, 128},
  {"128:_mm_min_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LT_OS)), y)", f361, 1, 128},
  {"128:_mm_min_ps(x, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LT_OS)))", f362, 1, 128},
  {"128:_mm_min_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LT_OS)), x)", f363, 1, 128},
  {"128:_mm_min_ps(y, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LT_OS)))", f364, 1, 128},
  {"128:_mm_min_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), y)), y)", f365, 1, 128},
  {"128:_mm_min_ps(x, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), y)))", f366, 1, 128},
  {"128:_mm_min_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), y)), x)", f367, 1, 128},
  {"128:_mm_min_ps(y, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), y)))", f368, 1, 128},
  {"128:_mm_min_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LE_OS)), y)", f369, 1, 128},
  {"128:_mm_min_ps(x, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LE_OS)))", f370, 1, 128},
  {"128:_mm_min_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LE_OS)), x)", f371, 1, 128},
  {"128:_mm_min_ps(y, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LE_OS)))", f372, 1, 128},
  {"128:_mm_min_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LE_OS)), y)", f373, 1, 128},
  {"128:_mm_min_ps(x, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LE_OS)))", f374, 1, 128},
  {"128:_mm_min_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LE_OS)), x)", f375, 1, 128},
  {"128:_mm_min_ps(y, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LE_OS)))", f376, 1, 128},
  {"128:_mm_min_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), y)), y)", f377, 1, 128},
  {"128:_mm_min_ps(x, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), y)))", f378, 1, 128},
  {"128:_mm_min_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), y)), x)", f379, 1, 128},
  {"128:_mm_min_ps(y, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), y)))", f380, 1, 128},
  {"128:_mm_min_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_GT_OS)), y)", f381, 1, 128},
  {"128:_mm_min_ps(x, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_GT_OS)))", f382, 1, 128},
  {"128:_mm_min_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_GT_OS)), x)", f383, 1, 128},
  {"128:_mm_min_ps(y, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_GT_OS)))", f384, 1, 128},
  {"128:_mm_min_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_GT_OS)), y)", f385, 1, 128},
  {"128:_mm_min_ps(x, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_GT_OS)))", f386, 1, 128},
  {"128:_mm_min_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_GT_OS)), x)", f387, 1, 128},
  {"128:_mm_min_ps(y, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_GT_OS)))", f388, 1, 128},
  {"128:_mm_min_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), y)), y)", f389, 1, 128},
  {"128:_mm_min_ps(x, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), y)))", f390, 1, 128},
  {"128:_mm_min_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), y)), x)", f391, 1, 128},
  {"128:_mm_min_ps(y, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), y)))", f392, 1, 128},
  {"128:_mm_min_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_NLT_US)), y)", f393, 1, 128},
  {"128:_mm_min_ps(x, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_NLT_US)))", f394, 1, 128},
  {"128:_mm_min_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_NLT_US)), x)", f395, 1, 128},
  {"128:_mm_min_ps(y, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_NLT_US)))", f396, 1, 128},
  {"128:_mm_min_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_NLT_US)), y)", f397, 1, 128},
  {"128:_mm_min_ps(x, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_NLT_US)))", f398, 1, 128},
  {"128:_mm_min_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_NLT_US)), x)", f399, 1, 128},
  {"128:_mm_min_ps(y, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_NLT_US)))", f400, 1, 128},
  {"128:_mm_min_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), y)), y)", f401, 1, 128},
  {"128:_mm_min_ps(x, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), y)))", f402, 1, 128},
  {"128:_mm_min_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), y)), x)", f403, 1, 128},
  {"128:_mm_min_ps(y, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), y)))", f404, 1, 128},
  {"128:_mm_min_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_EQ_OQ)), y)", f405, 1, 128},
  {"128:_mm_min_ps(x, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_EQ_OQ)))", f406, 1, 128},
  {"128:_mm_min_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_EQ_OQ)), x)", f407, 1, 128},
  {"128:_mm_min_ps(y, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_EQ_OQ)))", f408, 1, 128},
  {"128:_mm_min_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_EQ_OQ)), y)", f409, 1, 128},
  {"128:_mm_min_ps(x, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_EQ_OQ)))", f410, 1, 128},
  {"128:_mm_min_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_EQ_OQ)), x)", f411, 1, 128},
  {"128:_mm_min_ps(y, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_EQ_OQ)))", f412, 1, 128},
  {"128:_mm_min_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), y)), y)", f413, 1, 128},
  {"128:_mm_min_ps(x, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), y)))", f414, 1, 128},
  {"128:_mm_min_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), y)), x)", f415, 1, 128},
  {"128:_mm_min_ps(y, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), y)))", f416, 1, 128},
  {"128:_mm_min_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_UNORD_Q)), y)", f417, 1, 128},
  {"128:_mm_min_ps(x, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_UNORD_Q)))", f418, 1, 128},
  {"128:_mm_min_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_UNORD_Q)), x)", f419, 1, 128},
  {"128:_mm_min_ps(y, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_UNORD_Q)))", f420, 1, 128},
  {"128:_mm_min_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_UNORD_Q)), y)", f421, 1, 128},
  {"128:_mm_min_ps(x, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_UNORD_Q)))", f422, 1, 128},
  {"128:_mm_min_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_UNORD_Q)), x)", f423, 1, 128},
  {"128:_mm_min_ps(y, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_UNORD_Q)))", f424, 1, 128},
  {"128:_mm_min_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), y)), y)", f425, 1, 128},
  {"128:_mm_min_ps(x, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), y)))", f426, 1, 128},
  {"128:_mm_min_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), y)), x)", f427, 1, 128},
  {"128:_mm_min_ps(y, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), y)))", f428, 1, 128},
  {"128:_mm_min_ps(_mm_unpacklo_ps(x, y), y)", f429, 1, 128},
  {"128:_mm_min_ps(x, _mm_unpacklo_ps(x, y))", f430, 1, 128},
  {"128:_mm_min_ps(_mm_unpacklo_ps(x, y), x)", f431, 1, 128},
  {"128:_mm_min_ps(y, _mm_unpacklo_ps(x, y))", f432, 1, 128},
  {"128:_mm_min_ps(_mm_unpackhi_ps(x, y), y)", f433, 1, 128},
  {"128:_mm_min_ps(x, _mm_unpackhi_ps(x, y))", f434, 1, 128},
  {"128:_mm_min_ps(_mm_unpackhi_ps(x, y), x)", f435, 1, 128},
  {"128:_mm_min_ps(y, _mm_unpackhi_ps(x, y))", f436, 1, 128},
  {"128:_mm_min_ps(_mm_hadd_ps(x, y), y)", f437, 1, 128},
  {"128:_mm_min_ps(x, _mm_hadd_ps(x, y))", f438, 1, 128},
  {"128:_mm_min_ps(_mm_hadd_ps(x, y), x)", f439, 1, 128},
  {"128:_mm_min_ps(y, _mm_hadd_ps(x, y))", f440, 1, 128},
  {"128:_mm_min_ps(_mm_hsub_ps(x, y), y)", f441, 1, 128},
  {"128:_mm_min_ps(x, _mm_hsub_ps(x, y))", f442, 1, 128},
  {"128:_mm_min_ps(_mm_hsub_ps(x, y), x)", f443, 1, 128},
  {"128:_mm_min_ps(y, _mm_hsub_ps(x, y))", f444, 1, 128},
  {"128:_mm_min_ps(_mm_shuffle_ps(x, y, 0x1b), y)", f445, 1, 128},
  {"128:_mm_min_ps(x, _mm_shuffle_ps(x, y, 0x1b))", f446, 1, 128},
  {"128:_mm_min_ps(_mm_shuffle_ps(x, y, 0x1b), x)", f447, 1, 128},
  {"128:_mm_min_ps(y, _mm_shuffle_ps(x, y, 0x1b))", f448, 1, 128},
  {"128:_mm_min_ps(_mm_shuffle_ps(x, y, 0x39), y)", f449, 1, 128},
  {"128:_mm_min_ps(x, _mm_shuffle_ps(x, y, 0x39))", f450, 1, 128},
  {"128:_mm_min_ps(_mm_shuffle_ps(x, y, 0x39), x)", f451, 1, 128},
  {"128:_mm_min_ps(y, _mm_shuffle_ps(x, y, 0x39))", f452, 1, 128},
  {"128:_mm_min_ps(_mm_shuffle_ps(x, y, 0x93), y)", f453, 1, 128},
  {"128:_mm_min_ps(x, _mm_shuffle_ps(x, y, 0x93))", f454, 1, 128},
  {"128:_mm_min_ps(_mm_shuffle_ps(x, y, 0x93), x)", f455, 1, 128},
  {"128:_mm_min_ps(y, _mm_shuffle_ps(x, y, 0x93))", f456, 1, 128},
  {"128:_mm_min_ps(_mm_shuffle_ps(x, y, 0x4e), y)", f457, 1, 128},
  {"128:_mm_min_ps(x, _mm_shuffle_ps(x, y, 0x4e))", f458, 1, 128},
  {"128:_mm_min_ps(_mm_shuffle_ps(x, y, 0x4e), x)", f459, 1, 128},
  {"128:_mm_min_ps(y, _mm_shuffle_ps(x, y, 0x4e))", f460, 1, 128},
  {"128:_mm_max_ps(_mm_add_ps(x, y), y)", f461, 1, 128},
  {"128:_mm_max_ps(x, _mm_add_ps(x, y))", f462, 1, 128},
  {"128:_mm_max_ps(_mm_add_ps(x, y), x)", f463, 1, 128},
  {"128:_mm_max_ps(y, _mm_add_ps(x, y))", f464, 1, 128},
  {"128:_mm_max_ps(_mm_sub_ps(x, y), y)", f465, 1, 128},
  {"128:_mm_max_ps(x, _mm_sub_ps(x, y))", f466, 1, 128},
  {"128:_mm_max_ps(_mm_sub_ps(x, y), x)", f467, 1, 128},
  {"128:_mm_max_ps(y, _mm_sub_ps(x, y))", f468, 1, 128},
  {"128:_mm_max_ps(_mm_mul_ps(x, y), y)", f469, 1, 128},
  {"128:_mm_max_ps(x, _mm_mul_ps(x, y))", f470, 1, 128},
  {"128:_mm_max_ps(_mm_mul_ps(x, y), x)", f471, 1, 128},
  {"128:_mm_max_ps(y, _mm_mul_ps(x, y))", f472, 1, 128},
  {"128:_mm_max_ps(_mm_div_ps(x, y), y)", f473, 1, 128},
  {"128:_mm_max_ps(x, _mm_div_ps(x, y))", f474, 1, 128},
  {"128:_mm_max_ps(_mm_div_ps(x, y), x)", f475, 1, 128},
  {"128:_mm_max_ps(y, _mm_div_ps(x, y))", f476, 1, 128},
  {"128:_mm_max_ps(_mm_min_ps(x, y), y)", f477, 1, 128},
  {"128:_mm_max_ps(x, _mm_min_ps(x, y))", f478, 1, 128},
  {"128:_mm_max_ps(_mm_min_ps(x, y), x)", f479, 1, 128},
  {"128:_mm_max_ps(y, _mm_min_ps(x, y))", f480, 1, 128},
  {"128:_mm_max_ps(_mm_max_ps(x, y), y)", f481, 1, 128},
  {"128:_mm_max_ps(x, _mm_max_ps(x, y))", f482, 1, 128},
  {"128:_mm_max_ps(_mm_max_ps(x, y), x)", f483, 1, 128},
  {"128:_mm_max_ps(y, _mm_max_ps(x, y))", f484, 1, 128},
  {"128:_mm_max_ps(_mm_and_ps(x, y), y)", f485, 1, 128},
  {"128:_mm_max_ps(x, _mm_and_ps(x, y))", f486, 1, 128},
  {"128:_mm_max_ps(_mm_and_ps(x, y), x)", f487, 1, 128},
  {"128:_mm_max_ps(y, _mm_and_ps(x, y))", f488, 1, 128},
  {"128:_mm_max_ps(_mm_or_ps(x, y), y)", f489, 1, 128},
  {"128:_mm_max_ps(x, _mm_or_ps(x, y))", f490, 1, 128},
  {"128:_mm_max_ps(_mm_or_ps(x, y), x)", f491, 1, 128},
  {"128:_mm_max_ps(y, _mm_or_ps(x, y))", f492, 1, 128},
  {"128:_mm_max_ps(_mm_xor_ps(x, y), y)", f493, 1, 128},
  {"128:_mm_max_ps(x, _mm_xor_ps(x, y))", f494, 1, 128},
  {"128:_mm_max_ps(_mm_xor_ps(x, y), x)", f495, 1, 128},
  {"128:_mm_max_ps(y, _mm_xor_ps(x, y))", f496, 1, 128},
  {"128:_mm_max_ps(_mm_andnot_ps(x, y), y)", f497, 1, 128},
  {"128:_mm_max_ps(x, _mm_andnot_ps(x, y))", f498, 1, 128},
  {"128:_mm_max_ps(_mm_andnot_ps(x, y), x)", f499, 1, 128},
  {"128:_mm_max_ps(y, _mm_andnot_ps(x, y))", f500, 1, 128},
  {"128:_mm_max_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), y)", f501, 1, 128},
  {"128:_mm_max_ps(x, _mm_cmp_ps(x, y, _CMP_EQ_OQ))", f502, 1, 128},
  {"128:_mm_max_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), x)", f503, 1, 128},
  {"128:_mm_max_ps(y, _mm_cmp_ps(x, y, _CMP_EQ_OQ))", f504, 1, 128},
  {"128:_mm_max_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), y)", f505, 1, 128},
  {"128:_mm_max_ps(x, _mm_cmp_ps(x, y, _CMP_LT_OS))", f506, 1, 128},
  {"128:_mm_max_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), x)", f507, 1, 128},
  {"128:_mm_max_ps(y, _mm_cmp_ps(x, y, _CMP_LT_OS))", f508, 1, 128},
  {"128:_mm_max_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), y)", f509, 1, 128},
  {"128:_mm_max_ps(x, _mm_cmp_ps(x, y, _CMP_LE_OS))", f510, 1, 128},
  {"128:_mm_max_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), x)", f511, 1, 128},
  {"128:_mm_max_ps(y, _mm_cmp_ps(x, y, _CMP_LE_OS))", f512, 1, 128},
  {"128:_mm_max_ps(_mm_cmp_ps(x, y, _CMP_NEQ_UQ), y)", f513, 1, 128},
  {"128:_mm_max_ps(x, _mm_cmp_ps(x, y, _CMP_NEQ_UQ))", f514, 1, 128},
  {"128:_mm_max_ps(_mm_cmp_ps(x, y, _CMP_NEQ_UQ), x)", f515, 1, 128},
  {"128:_mm_max_ps(y, _mm_cmp_ps(x, y, _CMP_NEQ_UQ))", f516, 1, 128},
  {"128:_mm_max_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), y)", f517, 1, 128},
  {"128:_mm_max_ps(x, _mm_cmp_ps(x, y, _CMP_UNORD_Q))", f518, 1, 128},
  {"128:_mm_max_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), x)", f519, 1, 128},
  {"128:_mm_max_ps(y, _mm_cmp_ps(x, y, _CMP_UNORD_Q))", f520, 1, 128},
  {"128:_mm_max_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), y)", f521, 1, 128},
  {"128:_mm_max_ps(x, _mm_cmp_ps(x, y, _CMP_NLT_US))", f522, 1, 128},
  {"128:_mm_max_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), x)", f523, 1, 128},
  {"128:_mm_max_ps(y, _mm_cmp_ps(x, y, _CMP_NLT_US))", f524, 1, 128},
  {"128:_mm_max_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), y)", f525, 1, 128},
  {"128:_mm_max_ps(x, _mm_cmp_ps(x, y, _CMP_GT_OS))", f526, 1, 128},
  {"128:_mm_max_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), x)", f527, 1, 128},
  {"128:_mm_max_ps(y, _mm_cmp_ps(x, y, _CMP_GT_OS))", f528, 1, 128},
  {"128:_mm_max_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LT_OS)), y)", f529, 1, 128},
  {"128:_mm_max_ps(x, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LT_OS)))", f530, 1, 128},
  {"128:_mm_max_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LT_OS)), x)", f531, 1, 128},
  {"128:_mm_max_ps(y, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LT_OS)))", f532, 1, 128},
  {"128:_mm_max_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LT_OS)), y)", f533, 1, 128},
  {"128:_mm_max_ps(x, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LT_OS)))", f534, 1, 128},
  {"128:_mm_max_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LT_OS)), x)", f535, 1, 128},
  {"128:_mm_max_ps(y, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LT_OS)))", f536, 1, 128},
  {"128:_mm_max_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), y)), y)", f537, 1, 128},
  {"128:_mm_max_ps(x, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), y)))", f538, 1, 128},
  {"128:_mm_max_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), y)), x)", f539, 1, 128},
  {"128:_mm_max_ps(y, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), y)))", f540, 1, 128},
  {"128:_mm_max_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LE_OS)), y)", f541, 1, 128},
  {"128:_mm_max_ps(x, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LE_OS)))", f542, 1, 128},
  {"128:_mm_max_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LE_OS)), x)", f543, 1, 128},
  {"128:_mm_max_ps(y, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LE_OS)))", f544, 1, 128},
  {"128:_mm_max_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LE_OS)), y)", f545, 1, 128},
  {"128:_mm_max_ps(x, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LE_OS)))", f546, 1, 128},
  {"128:_mm_max_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LE_OS)), x)", f547, 1, 128},
  {"128:_mm_max_ps(y, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LE_OS)))", f548, 1, 128},
  {"128:_mm_max_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), y)), y)", f549, 1, 128},
  {"128:_mm_max_ps(x, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), y)))", f550, 1, 128},
  {"128:_mm_max_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), y)), x)", f551, 1, 128},
  {"128:_mm_max_ps(y, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), y)))", f552, 1, 128},
  {"128:_mm_max_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_GT_OS)), y)", f553, 1, 128},
  {"128:_mm_max_ps(x, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_GT_OS)))", f554, 1, 128},
  {"128:_mm_max_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_GT_OS)), x)", f555, 1, 128},
  {"128:_mm_max_ps(y, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_GT_OS)))", f556, 1, 128},
  {"128:_mm_max_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_GT_OS)), y)", f557, 1, 128},
  {"128:_mm_max_ps(x, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_GT_OS)))", f558, 1, 128},
  {"128:_mm_max_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_GT_OS)), x)", f559, 1, 128},
  {"128:_mm_max_ps(y, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_GT_OS)))", f560, 1, 128},
  {"128:_mm_max_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), y)), y)", f561, 1, 128},
  {"128:_mm_max_ps(x, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), y)))", f562, 1, 128},
  {"128:_mm_max_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), y)), x)", f563, 1, 128},
  {"128:_mm_max_ps(y, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), y)))", f564, 1, 128},
  {"128:_mm_max_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_NLT_US)), y)", f565, 1, 128},
  {"128:_mm_max_ps(x, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_NLT_US)))", f566, 1, 128},
  {"128:_mm_max_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_NLT_US)), x)", f567, 1, 128},
  {"128:_mm_max_ps(y, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_NLT_US)))", f568, 1, 128},
  {"128:_mm_max_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_NLT_US)), y)", f569, 1, 128},
  {"128:_mm_max_ps(x, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_NLT_US)))", f570, 1, 128},
  {"128:_mm_max_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_NLT_US)), x)", f571, 1, 128},
  {"128:_mm_max_ps(y, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_NLT_US)))", f572, 1, 128},
  {"128:_mm_max_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), y)), y)", f573, 1, 128},
  {"128:_mm_max_ps(x, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), y)))", f574, 1, 128},
  {"128:_mm_max_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), y)), x)", f575, 1, 128},
  {"128:_mm_max_ps(y, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), y)))", f576, 1, 128},
  {"128:_mm_max_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_EQ_OQ)), y)", f577, 1, 128},
  {"128:_mm_max_ps(x, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_EQ_OQ)))", f578, 1, 128},
  {"128:_mm_max_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_EQ_OQ)), x)", f579, 1, 128},
  {"128:_mm_max_ps(y, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_EQ_OQ)))", f580, 1, 128},
  {"128:_mm_max_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_EQ_OQ)), y)", f581, 1, 128},
  {"128:_mm_max_ps(x, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_EQ_OQ)))", f582, 1, 128},
  {"128:_mm_max_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_EQ_OQ)), x)", f583, 1, 128},
  {"128:_mm_max_ps(y, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_EQ_OQ)))", f584, 1, 128},
  {"128:_mm_max_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), y)), y)", f585, 1, 128},
  {"128:_mm_max_ps(x, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), y)))", f586, 1, 128},
  {"128:_mm_max_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), y)), x)", f587, 1, 128},
  {"128:_mm_max_ps(y, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), y)))", f588, 1, 128},
  {"128:_mm_max_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_UNORD_Q)), y)", f589, 1, 128},
  {"128:_mm_max_ps(x, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_UNORD_Q)))", f590, 1, 128},
  {"128:_mm_max_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_UNORD_Q)), x)", f591, 1, 128},
  {"128:_mm_max_ps(y, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_UNORD_Q)))", f592, 1, 128},
  {"128:_mm_max_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_UNORD_Q)), y)", f593, 1, 128},
  {"128:_mm_max_ps(x, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_UNORD_Q)))", f594, 1, 128},
  {"128:_mm_max_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_UNORD_Q)), x)", f595, 1, 128},
  {"128:_mm_max_ps(y, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_UNORD_Q)))", f596, 1, 128},
  {"128:_mm_max_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), y)), y)", f597, 1, 128},
  {"128:_mm_max_ps(x, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), y)))", f598, 1, 128},
  {"128:_mm_max_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), y)), x)", f599, 1, 128},
  {"128:_mm_max_ps(y, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), y)))", f600, 1, 128},
  {"128:_mm_max_ps(_mm_unpacklo_ps(x, y), y)", f601, 1, 128},
  {"128:_mm_max_ps(x, _mm_unpacklo_ps(x, y))", f602, 1, 128},
  {"128:_mm_max_ps(_mm_unpacklo_ps(x, y), x)", f603, 1, 128},
  {"128:_mm_max_ps(y, _mm_unpacklo_ps(x, y))", f604, 1, 128},
  {"128:_mm_max_ps(_mm_unpackhi_ps(x, y), y)", f605, 1, 128},
  {"128:_mm_max_ps(x, _mm_unpackhi_ps(x, y))", f606, 1, 128},
  {"128:_mm_max_ps(_mm_unpackhi_ps(x, y), x)", f607, 1, 128},
  {"128:_mm_max_ps(y, _mm_unpackhi_ps(x, y))", f608, 1, 128},
  {"128:_mm_max_ps(_mm_hadd_ps(x, y), y)", f609, 1, 128},
  {"128:_mm_max_ps(x, _mm_hadd_ps(x, y))", f610, 1, 128},
  {"128:_mm_max_ps(_mm_hadd_ps(x, y), x)", f611, 1, 128},
  {"128:_mm_max_ps(y, _mm_hadd_ps(x, y))", f612, 1, 128},
  {"128:_mm_max_ps(_mm_hsub_ps(x, y), y)", f613, 1, 128},
  {"128:_mm_max_ps(x, _mm_hsub_ps(x, y))", f614, 1, 128},
  {"128:_mm_max_ps(_mm_hsub_ps(x, y), x)", f615, 1, 128},
  {"128:_mm_max_ps(y, _mm_hsub_ps(x, y))", f616, 1, 128},
  {"128:_mm_max_ps(_mm_shuffle_ps(x, y, 0x1b), y)", f617, 1, 128},
  {"128:_mm_max_ps(x, _mm_shuffle_ps(x, y, 0x1b))", f618, 1, 128},
  {"128:_mm_max_ps(_mm_shuffle_ps(x, y, 0x1b), x)", f619, 1, 128},
  {"128:_mm_max_ps(y, _mm_shuffle_ps(x, y, 0x1b))", f620, 1, 128},
  {"128:_mm_max_ps(_mm_shuffle_ps(x, y, 0x39), y)", f621, 1, 128},
  {"128:_mm_max_ps(x, _mm_shuffle_ps(x, y, 0x39))", f622, 1, 128},
  {"128:_mm_max_ps(_mm_shuffle_ps(x, y, 0x39), x)", f623, 1, 128},
  {"128:_mm_max_ps(y, _mm_shuffle_ps(x, y, 0x39))", f624, 1, 128},
  {"128:_mm_max_ps(_mm_shuffle_ps(x, y, 0x93), y)", f625, 1, 128},
  {"128:_mm_max_ps(x, _mm_shuffle_ps(x, y, 0x93))", f626, 1, 128},
  {"128:_mm_max_ps(_mm_shuffle_ps(x, y, 0x93), x)", f627, 1, 128},
  {"128:_mm_max_ps(y, _mm_shuffle_ps(x, y, 0x93))", f628, 1, 128},
  {"128:_mm_max_ps(_mm_shuffle_ps(x, y, 0x4e), y)", f629, 1, 128},
  {"128:_mm_max_ps(x, _mm_shuffle_ps(x, y, 0x4e))", f630, 1, 128},
  {"128:_mm_max_ps(_mm_shuffle_ps(x, y, 0x4e), x)", f631, 1, 128},
  {"128:_mm_max_ps(y, _mm_shuffle_ps(x, y, 0x4e))", f632, 1, 128},
  {"128:_mm_and_ps(_mm_add_ps(x, y), y)", f633, 1, 128},
  {"128:_mm_and_ps(x, _mm_add_ps(x, y))", f634, 1, 128},
  {"128:_mm_and_ps(_mm_add_ps(x, y), x)", f635, 1, 128},
  {"128:_mm_and_ps(y, _mm_add_ps(x, y))", f636, 1, 128},
  {"128:_mm_and_ps(_mm_sub_ps(x, y), y)", f637, 1, 128},
  {"128:_mm_and_ps(x, _mm_sub_ps(x, y))", f638, 1, 128},
  {"128:_mm_and_ps(_mm_sub_ps(x, y), x)", f639, 1, 128},
  {"128:_mm_and_ps(y, _mm_sub_ps(x, y))", f640, 1, 128},
  {"128:_mm_and_ps(_mm_mul_ps(x, y), y)", f641, 1, 128},
  {"128:_mm_and_ps(x, _mm_mul_ps(x, y))", f642, 1, 128},
  {"128:_mm_and_ps(_mm_mul_ps(x, y), x)", f643, 1, 128},
  {"128:_mm_and_ps(y, _mm_mul_ps(x, y))", f644, 1, 128},
  {"128:_mm_and_ps(_mm_div_ps(x, y), y)", f645, 1, 128},
  {"128:_mm_and_ps(x, _mm_div_ps(x, y))", f646, 1, 128},
  {"128:_mm_and_ps(_mm_div_ps(x, y), x)", f647, 1, 128},
  {"128:_mm_and_ps(y, _mm_div_ps(x, y))", f648, 1, 128},
  {"128:_mm_and_ps(_mm_min_ps(x, y), y)", f649, 1, 128},
  {"128:_mm_and_ps(x, _mm_min_ps(x, y))", f650, 1, 128},
  {"128:_mm_and_ps(_mm_min_ps(x, y), x)", f651, 1, 128},
  {"128:_mm_and_ps(y, _mm_min_ps(x, y))", f652, 1, 128},
  {"128:_mm_and_ps(_mm_max_ps(x, y), y)", f653, 1, 128},
  {"128:_mm_and_ps(x, _mm_max_ps(x, y))", f654, 1, 128},
  {"128:_mm_and_ps(_mm_max_ps(x, y), x)", f655, 1, 128},
  {"128:_mm_and_ps(y, _mm_max_ps(x, y))", f656, 1, 128},
  {"128:_mm_and_ps(_mm_and_ps(x, y), y)", f657, 1, 128},
  {"128:_mm_and_ps(x, _mm_and_ps(x, y))", f658, 1, 128},
  {"128:_mm_and_ps(_mm_and_ps(x, y), x)", f659, 1, 128},
  {"128:_mm_and_ps(y, _mm_and_ps(x, y))", f660, 1, 128},
  {"128:_mm_and_ps(_mm_or_ps(x, y), y)", f661, 1, 128},
  {"128:_mm_and_ps(x, _mm_or_ps(x, y))", f662, 1, 128},
  {"128:_mm_and_ps(_mm_or_ps(x, y), x)", f663, 1, 128},
  {"128:_mm_and_ps(y, _mm_or_ps(x, y))", f664, 1, 128},
  {"128:_mm_and_ps(_mm_xor_ps(x, y), y)", f665, 1, 128},
  {"128:_mm_and_ps(x, _mm_xor_ps(x, y))", f666, 1, 128},
  {"128:_mm_and_ps(_mm_xor_ps(x, y), x)", f667, 1, 128},
  {"128:_mm_and_ps(y, _mm_xor_ps(x, y))", f668, 1, 128},
  {"128:_mm_and_ps(_mm_andnot_ps(x, y), y)", f669, 1, 128},
  {"128:_mm_and_ps(x, _mm_andnot_ps(x, y))", f670, 1, 128},
  {"128:_mm_and_ps(_mm_andnot_ps(x, y), x)", f671, 1, 128},
  {"128:_mm_and_ps(y, _mm_andnot_ps(x, y))", f672, 1, 128},
  {"128:_mm_and_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), y)", f673, 1, 128},
  {"128:_mm_and_ps(x, _mm_cmp_ps(x, y, _CMP_EQ_OQ))", f674, 1, 128},
  {"128:_mm_and_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), x)", f675, 1, 128},
  {"128:_mm_and_ps(y, _mm_cmp_ps(x, y, _CMP_EQ_OQ))", f676, 1, 128},
  {"128:_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), y)", f677, 1, 128},
  {"128:_mm_and_ps(x, _mm_cmp_ps(x, y, _CMP_LT_OS))", f678, 1, 128},
  {"128:_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), x)", f679, 1, 128},
  {"128:_mm_and_ps(y, _mm_cmp_ps(x, y, _CMP_LT_OS))", f680, 1, 128},
  {"128:_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), y)", f681, 1, 128},
  {"128:_mm_and_ps(x, _mm_cmp_ps(x, y, _CMP_LE_OS))", f682, 1, 128},
  {"128:_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), x)", f683, 1, 128},
  {"128:_mm_and_ps(y, _mm_cmp_ps(x, y, _CMP_LE_OS))", f684, 1, 128},
  {"128:_mm_and_ps(_mm_cmp_ps(x, y, _CMP_NEQ_UQ), y)", f685, 1, 128},
  {"128:_mm_and_ps(x, _mm_cmp_ps(x, y, _CMP_NEQ_UQ))", f686, 1, 128},
  {"128:_mm_and_ps(_mm_cmp_ps(x, y, _CMP_NEQ_UQ), x)", f687, 1, 128},
  {"128:_mm_and_ps(y, _mm_cmp_ps(x, y, _CMP_NEQ_UQ))", f688, 1, 128},
  {"128:_mm_and_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), y)", f689, 1, 128},
  {"128:_mm_and_ps(x, _mm_cmp_ps(x, y, _CMP_UNORD_Q))", f690, 1, 128},
  {"128:_mm_and_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), x)", f691, 1, 128},
  {"128:_mm_and_ps(y, _mm_cmp_ps(x, y, _CMP_UNORD_Q))", f692, 1, 128},
  {"128:_mm_and_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), y)", f693, 1, 128},
  {"128:_mm_and_ps(x, _mm_cmp_ps(x, y, _CMP_NLT_US))", f694, 1, 128},
  {"128:_mm_and_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), x)", f695, 1, 128},
  {"128:_mm_and_ps(y, _mm_cmp_ps(x, y, _CMP_NLT_US))", f696, 1, 128},
  {"128:_mm_and_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), y)", f697, 1, 128},
  {"128:_mm_and_ps(x, _mm_cmp_ps(x, y, _CMP_GT_OS))", f698, 1, 128},
  {"128:_mm_and_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), x)", f699, 1, 128},
  {"128:_mm_and_ps(y, _mm_cmp_ps(x, y, _CMP_GT_OS))", f700, 1, 128},
  {"128:_mm_and_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LT_OS)), y)", f701, 1, 128},
  {"128:_mm_and_ps(x, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LT_OS)))", f702, 1, 128},
  {"128:_mm_and_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LT_OS)), x)", f703, 1, 128},
  {"128:_mm_and_ps(y, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LT_OS)))", f704, 1, 128},
  {"128:_mm_and_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LT_OS)), y)", f705, 1, 128},
  {"128:_mm_and_ps(x, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LT_OS)))", f706, 1, 128},
  {"128:_mm_and_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LT_OS)), x)", f707, 1, 128},
  {"128:_mm_and_ps(y, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LT_OS)))", f708, 1, 128},
  {"128:_mm_and_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), y)), y)", f709, 1, 128},
  {"128:_mm_and_ps(x, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), y)))", f710, 1, 128},
  {"128:_mm_and_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), y)), x)", f711, 1, 128},
  {"128:_mm_and_ps(y, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), y)))", f712, 1, 128},
  {"128:_mm_and_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LE_OS)), y)", f713, 1, 128},
  {"128:_mm_and_ps(x, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LE_OS)))", f714, 1, 128},
  {"128:_mm_and_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LE_OS)), x)", f715, 1, 128},
  {"128:_mm_and_ps(y, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LE_OS)))", f716, 1, 128},
  {"128:_mm_and_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LE_OS)), y)", f717, 1, 128},
  {"128:_mm_and_ps(x, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LE_OS)))", f718, 1, 128},
  {"128:_mm_and_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LE_OS)), x)", f719, 1, 128},
  {"128:_mm_and_ps(y, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LE_OS)))", f720, 1, 128},
  {"128:_mm_and_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), y)), y)", f721, 1, 128},
  {"128:_mm_and_ps(x, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), y)))", f722, 1, 128},
  {"128:_mm_and_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), y)), x)", f723, 1, 128},
  {"128:_mm_and_ps(y, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), y)))", f724, 1, 128},
  {"128:_mm_and_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_GT_OS)), y)", f725, 1, 128},
  {"128:_mm_and_ps(x, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_GT_OS)))", f726, 1, 128},
  {"128:_mm_and_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_GT_OS)), x)", f727, 1, 128},
  {"128:_mm_and_ps(y, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_GT_OS)))", f728, 1, 128},
  {"128:_mm_and_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_GT_OS)), y)", f729, 1, 128},
  {"128:_mm_and_ps(x, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_GT_OS)))", f730, 1, 128},
  {"128:_mm_and_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_GT_OS)), x)", f731, 1, 128},
  {"128:_mm_and_ps(y, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_GT_OS)))", f732, 1, 128},
  {"128:_mm_and_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), y)), y)", f733, 1, 128},
  {"128:_mm_and_ps(x, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), y)))", f734, 1, 128},
  {"128:_mm_and_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), y)), x)", f735, 1, 128},
  {"128:_mm_and_ps(y, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), y)))", f736, 1, 128},
  {"128:_mm_and_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_NLT_US)), y)", f737, 1, 128},
  {"128:_mm_and_ps(x, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_NLT_US)))", f738, 1, 128},
  {"128:_mm_and_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_NLT_US)), x)", f739, 1, 128},
  {"128:_mm_and_ps(y, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_NLT_US)))", f740, 1, 128},
  {"128:_mm_and_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_NLT_US)), y)", f741, 1, 128},
  {"128:_mm_and_ps(x, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_NLT_US)))", f742, 1, 128},
  {"128:_mm_and_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_NLT_US)), x)", f743, 1, 128},
  {"128:_mm_and_ps(y, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_NLT_US)))", f744, 1, 128},
  {"128:_mm_and_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), y)), y)", f745, 1, 128},
  {"128:_mm_and_ps(x, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), y)))", f746, 1, 128},
  {"128:_mm_and_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), y)), x)", f747, 1, 128},
  {"128:_mm_and_ps(y, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), y)))", f748, 1, 128},
  {"128:_mm_and_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_EQ_OQ)), y)", f749, 1, 128},
  {"128:_mm_and_ps(x, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_EQ_OQ)))", f750, 1, 128},
  {"128:_mm_and_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_EQ_OQ)), x)", f751, 1, 128},
  {"128:_mm_and_ps(y, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_EQ_OQ)))", f752, 1, 128},
  {"128:_mm_and_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_EQ_OQ)), y)", f753, 1, 128},
  {"128:_mm_and_ps(x, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_EQ_OQ)))", f754, 1, 128},
  {"128:_mm_and_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_EQ_OQ)), x)", f755, 1, 128},
  {"128:_mm_and_ps(y, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_EQ_OQ)))", f756, 1, 128},
  {"128:_mm_and_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), y)), y)", f757, 1, 128},
  {"128:_mm_and_ps(x, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), y)))", f758, 1, 128},
  {"128:_mm_and_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), y)), x)", f759, 1, 128},
  {"128:_mm_and_ps(y, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), y)))", f760, 1, 128},
  {"128:_mm_and_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_UNORD_Q)), y)", f761, 1, 128},
  {"128:_mm_and_ps(x, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_UNORD_Q)))", f762, 1, 128},
  {"128:_mm_and_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_UNORD_Q)), x)", f763, 1, 128},
  {"128:_mm_and_ps(y, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_UNORD_Q)))", f764, 1, 128},
  {"128:_mm_and_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_UNORD_Q)), y)", f765, 1, 128},
  {"128:_mm_and_ps(x, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_UNORD_Q)))", f766, 1, 128},
  {"128:_mm_and_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_UNORD_Q)), x)", f767, 1, 128},
  {"128:_mm_and_ps(y, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_UNORD_Q)))", f768, 1, 128},
  {"128:_mm_and_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), y)), y)", f769, 1, 128},
  {"128:_mm_and_ps(x, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), y)))", f770, 1, 128},
  {"128:_mm_and_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), y)), x)", f771, 1, 128},
  {"128:_mm_and_ps(y, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), y)))", f772, 1, 128},
  {"128:_mm_and_ps(_mm_unpacklo_ps(x, y), y)", f773, 1, 128},
  {"128:_mm_and_ps(x, _mm_unpacklo_ps(x, y))", f774, 1, 128},
  {"128:_mm_and_ps(_mm_unpacklo_ps(x, y), x)", f775, 1, 128},
  {"128:_mm_and_ps(y, _mm_unpacklo_ps(x, y))", f776, 1, 128},
  {"128:_mm_and_ps(_mm_unpackhi_ps(x, y), y)", f777, 1, 128},
  {"128:_mm_and_ps(x, _mm_unpackhi_ps(x, y))", f778, 1, 128},
  {"128:_mm_and_ps(_mm_unpackhi_ps(x, y), x)", f779, 1, 128},
  {"128:_mm_and_ps(y, _mm_unpackhi_ps(x, y))", f780, 1, 128},
  {"128:_mm_and_ps(_mm_hadd_ps(x, y), y)", f781, 1, 128},
  {"128:_mm_and_ps(x, _mm_hadd_ps(x, y))", f782, 1, 128},
  {"128:_mm_and_ps(_mm_hadd_ps(x, y), x)", f783, 1, 128},
  {"128:_mm_and_ps(y, _mm_hadd_ps(x, y))", f784, 1, 128},
  {"128:_mm_and_ps(_mm_hsub_ps(x, y), y)", f785, 1, 128},
  {"128:_mm_and_ps(x, _mm_hsub_ps(x, y))", f786, 1, 128},
  {"128:_mm_and_ps(_mm_hsub_ps(x, y), x)", f787, 1, 128},
  {"128:_mm_and_ps(y, _mm_hsub_ps(x, y))", f788, 1, 128},
  {"128:_mm_and_ps(_mm_shuffle_ps(x, y, 0x1b), y)", f789, 1, 128},
  {"128:_mm_and_ps(x, _mm_shuffle_ps(x, y, 0x1b))", f790, 1, 128},
  {"128:_mm_and_ps(_mm_shuffle_ps(x, y, 0x1b), x)", f791, 1, 128},
  {"128:_mm_and_ps(y, _mm_shuffle_ps(x, y, 0x1b))", f792, 1, 128},
  {"128:_mm_and_ps(_mm_shuffle_ps(x, y, 0x39), y)", f793, 1, 128},
  {"128:_mm_and_ps(x, _mm_shuffle_ps(x, y, 0x39))", f794, 1, 128},
  {"128:_mm_and_ps(_mm_shuffle_ps(x, y, 0x39), x)", f795, 1, 128},
  {"128:_mm_and_ps(y, _mm_shuffle_ps(x, y, 0x39))", f796, 1, 128},
  {"128:_mm_and_ps(_mm_shuffle_ps(x, y, 0x93), y)", f797, 1, 128},
  {"128:_mm_and_ps(x, _mm_shuffle_ps(x, y, 0x93))", f798, 1, 128},
  {"128:_mm_and_ps(_mm_shuffle_ps(x, y, 0x93), x)", f799, 1, 128},
  {"128:_mm_and_ps(y, _mm_shuffle_ps(x, y, 0x93))", f800, 1, 128},
  {"128:_mm_and_ps(_mm_shuffle_ps(x, y, 0x4e), y)", f801, 1, 128},
  {"128:_mm_and_ps(x, _mm_shuffle_ps(x, y, 0x4e))", f802, 1, 128},
  {"128:_mm_and_ps(_mm_shuffle_ps(x, y, 0x4e), x)", f803, 1, 128},
  {"128:_mm_and_ps(y, _mm_shuffle_ps(x, y, 0x4e))", f804, 1, 128},
  {"128:_mm_or_ps(_mm_add_ps(x, y), y)", f805, 1, 128},
  {"128:_mm_or_ps(x, _mm_add_ps(x, y))", f806, 1, 128},
  {"128:_mm_or_ps(_mm_add_ps(x, y), x)", f807, 1, 128},
  {"128:_mm_or_ps(y, _mm_add_ps(x, y))", f808, 1, 128},
  {"128:_mm_or_ps(_mm_sub_ps(x, y), y)", f809, 1, 128},
  {"128:_mm_or_ps(x, _mm_sub_ps(x, y))", f810, 1, 128},
  {"128:_mm_or_ps(_mm_sub_ps(x, y), x)", f811, 1, 128},
  {"128:_mm_or_ps(y, _mm_sub_ps(x, y))", f812, 1, 128},
  {"128:_mm_or_ps(_mm_mul_ps(x, y), y)", f813, 1, 128},
  {"128:_mm_or_ps(x, _mm_mul_ps(x, y))", f814, 1, 128},
  {"128:_mm_or_ps(_mm_mul_ps(x, y), x)", f815, 1, 128},
  {"128:_mm_or_ps(y, _mm_mul_ps(x, y))", f816, 1, 128},
  {"128:_mm_or_ps(_mm_div_ps(x, y), y)", f817, 1, 128},
  {"128:_mm_or_ps(x, _mm_div_ps(x, y))", f818, 1, 128},
  {"128:_mm_or_ps(_mm_div_ps(x, y), x)", f819, 1, 128},
  {"128:_mm_or_ps(y, _mm_div_ps(x, y))", f820, 1, 128},
  {"128:_mm_or_ps(_mm_min_ps(x, y), y)", f821, 1, 128},
  {"128:_mm_or_ps(x, _mm_min_ps(x, y))", f822, 1, 128},
  {"128:_mm_or_ps(_mm_min_ps(x, y), x)", f823, 1, 128},
  {"128:_mm_or_ps(y, _mm_min_ps(x, y))", f824, 1, 128},
  {"128:_mm_or_ps(_mm_max_ps(x, y), y)", f825, 1, 128},
  {"128:_mm_or_ps(x, _mm_max_ps(x, y))", f826, 1, 128},
  {"128:_mm_or_ps(_mm_max_ps(x, y), x)", f827, 1, 128},
  {"128:_mm_or_ps(y, _mm_max_ps(x, y))", f828, 1, 128},
  {"128:_mm_or_ps(_mm_and_ps(x, y), y)", f829, 1, 128},
  {"128:_mm_or_ps(x, _mm_and_ps(x, y))", f830, 1, 128},
  {"128:_mm_or_ps(_mm_and_ps(x, y), x)", f831, 1, 128},
  {"128:_mm_or_ps(y, _mm_and_ps(x, y))", f832, 1, 128},
  {"128:_mm_or_ps(_mm_or_ps(x, y), y)", f833, 1, 128},
  {"128:_mm_or_ps(x, _mm_or_ps(x, y))", f834, 1, 128},
  {"128:_mm_or_ps(_mm_or_ps(x, y), x)", f835, 1, 128},
  {"128:_mm_or_ps(y, _mm_or_ps(x, y))", f836, 1, 128},
  {"128:_mm_or_ps(_mm_xor_ps(x, y), y)", f837, 1, 128},
  {"128:_mm_or_ps(x, _mm_xor_ps(x, y))", f838, 1, 128},
  {"128:_mm_or_ps(_mm_xor_ps(x, y), x)", f839, 1, 128},
  {"128:_mm_or_ps(y, _mm_xor_ps(x, y))", f840, 1, 128},
  {"128:_mm_or_ps(_mm_andnot_ps(x, y), y)", f841, 1, 128},
  {"128:_mm_or_ps(x, _mm_andnot_ps(x, y))", f842, 1, 128},
  {"128:_mm_or_ps(_mm_andnot_ps(x, y), x)", f843, 1, 128},
  {"128:_mm_or_ps(y, _mm_andnot_ps(x, y))", f844, 1, 128},
  {"128:_mm_or_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), y)", f845, 1, 128},
  {"128:_mm_or_ps(x, _mm_cmp_ps(x, y, _CMP_EQ_OQ))", f846, 1, 128},
  {"128:_mm_or_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), x)", f847, 1, 128},
  {"128:_mm_or_ps(y, _mm_cmp_ps(x, y, _CMP_EQ_OQ))", f848, 1, 128},
  {"128:_mm_or_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), y)", f849, 1, 128},
  {"128:_mm_or_ps(x, _mm_cmp_ps(x, y, _CMP_LT_OS))", f850, 1, 128},
  {"128:_mm_or_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), x)", f851, 1, 128},
  {"128:_mm_or_ps(y, _mm_cmp_ps(x, y, _CMP_LT_OS))", f852, 1, 128},
  {"128:_mm_or_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), y)", f853, 1, 128},
  {"128:_mm_or_ps(x, _mm_cmp_ps(x, y, _CMP_LE_OS))", f854, 1, 128},
  {"128:_mm_or_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), x)", f855, 1, 128},
  {"128:_mm_or_ps(y, _mm_cmp_ps(x, y, _CMP_LE_OS))", f856, 1, 128},
  {"128:_mm_or_ps(_mm_cmp_ps(x, y, _CMP_NEQ_UQ), y)", f857, 1, 128},
  {"128:_mm_or_ps(x, _mm_cmp_ps(x, y, _CMP_NEQ_UQ))", f858, 1, 128},
  {"128:_mm_or_ps(_mm_cmp_ps(x, y, _CMP_NEQ_UQ), x)", f859, 1, 128},
  {"128:_mm_or_ps(y, _mm_cmp_ps(x, y, _CMP_NEQ_UQ))", f860, 1, 128},
  {"128:_mm_or_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), y)", f861, 1, 128},
  {"128:_mm_or_ps(x, _mm_cmp_ps(x, y, _CMP_UNORD_Q))", f862, 1, 128},
  {"128:_mm_or_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), x)", f863, 1, 128},
  {"128:_mm_or_ps(y, _mm_cmp_ps(x, y, _CMP_UNORD_Q))", f864, 1, 128},
  {"128:_mm_or_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), y)", f865, 1, 128},
  {"128:_mm_or_ps(x, _mm_cmp_ps(x, y, _CMP_NLT_US))", f866, 1, 128},
  {"128:_mm_or_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), x)", f867, 1, 128},
  {"128:_mm_or_ps(y, _mm_cmp_ps(x, y, _CMP_NLT_US))", f868, 1, 128},
  {"128:_mm_or_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), y)", f869, 1, 128},
  {"128:_mm_or_ps(x, _mm_cmp_ps(x, y, _CMP_GT_OS))", f870, 1, 128},
  {"128:_mm_or_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), x)", f871, 1, 128},
  {"128:_mm_or_ps(y, _mm_cmp_ps(x, y, _CMP_GT_OS))", f872, 1, 128},
  {"128:_mm_or_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LT_OS)), y)", f873, 1, 128},
  {"128:_mm_or_ps(x, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LT_OS)))", f874, 1, 128},
  {"128:_mm_or_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LT_OS)), x)", f875, 1, 128},
  {"128:_mm_or_ps(y, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LT_OS)))", f876, 1, 128},
  {"128:_mm_or_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LT_OS)), y)", f877, 1, 128},
  {"128:_mm_or_ps(x, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LT_OS)))", f878, 1, 128},
  {"128:_mm_or_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LT_OS)), x)", f879, 1, 128},
  {"128:_mm_or_ps(y, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LT_OS)))", f880, 1, 128},
  {"128:_mm_or_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), y)), y)", f881, 1, 128},
  {"128:_mm_or_ps(x, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), y)))", f882, 1, 128},
  {"128:_mm_or_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), y)), x)", f883, 1, 128},
  {"128:_mm_or_ps(y, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), y)))", f884, 1, 128},
  {"128:_mm_or_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LE_OS)), y)", f885, 1, 128},
  {"128:_mm_or_ps(x, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LE_OS)))", f886, 1, 128},
  {"128:_mm_or_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LE_OS)), x)", f887, 1, 128},
  {"128:_mm_or_ps(y, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LE_OS)))", f888, 1, 128},
  {"128:_mm_or_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LE_OS)), y)", f889, 1, 128},
  {"128:_mm_or_ps(x, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LE_OS)))", f890, 1, 128},
  {"128:_mm_or_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LE_OS)), x)", f891, 1, 128},
  {"128:_mm_or_ps(y, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LE_OS)))", f892, 1, 128},
  {"128:_mm_or_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), y)), y)", f893, 1, 128},
  {"128:_mm_or_ps(x, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), y)))", f894, 1, 128},
  {"128:_mm_or_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), y)), x)", f895, 1, 128},
  {"128:_mm_or_ps(y, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), y)))", f896, 1, 128},
  {"128:_mm_or_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_GT_OS)), y)", f897, 1, 128},
  {"128:_mm_or_ps(x, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_GT_OS)))", f898, 1, 128},
  {"128:_mm_or_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_GT_OS)), x)", f899, 1, 128},
  {"128:_mm_or_ps(y, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_GT_OS)))", f900, 1, 128},
  {"128:_mm_or_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_GT_OS)), y)", f901, 1, 128},
  {"128:_mm_or_ps(x, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_GT_OS)))", f902, 1, 128},
  {"128:_mm_or_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_GT_OS)), x)", f903, 1, 128},
  {"128:_mm_or_ps(y, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_GT_OS)))", f904, 1, 128},
  {"128:_mm_or_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), y)), y)", f905, 1, 128},
  {"128:_mm_or_ps(x, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), y)))", f906, 1, 128},
  {"128:_mm_or_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), y)), x)", f907, 1, 128},
  {"128:_mm_or_ps(y, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), y)))", f908, 1, 128},
  {"128:_mm_or_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_NLT_US)), y)", f909, 1, 128},
  {"128:_mm_or_ps(x, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_NLT_US)))", f910, 1, 128},
  {"128:_mm_or_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_NLT_US)), x)", f911, 1, 128},
  {"128:_mm_or_ps(y, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_NLT_US)))", f912, 1, 128},
  {"128:_mm_or_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_NLT_US)), y)", f913, 1, 128},
  {"128:_mm_or_ps(x, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_NLT_US)))", f914, 1, 128},
  {"128:_mm_or_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_NLT_US)), x)", f915, 1, 128},
  {"128:_mm_or_ps(y, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_NLT_US)))", f916, 1, 128},
  {"128:_mm_or_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), y)), y)", f917, 1, 128},
  {"128:_mm_or_ps(x, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), y)))", f918, 1, 128},
  {"128:_mm_or_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), y)), x)", f919, 1, 128},
  {"128:_mm_or_ps(y, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), y)))", f920, 1, 128},
  {"128:_mm_or_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_EQ_OQ)), y)", f921, 1, 128},
  {"128:_mm_or_ps(x, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_EQ_OQ)))", f922, 1, 128},
  {"128:_mm_or_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_EQ_OQ)), x)", f923, 1, 128},
  {"128:_mm_or_ps(y, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_EQ_OQ)))", f924, 1, 128},
  {"128:_mm_or_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_EQ_OQ)), y)", f925, 1, 128},
  {"128:_mm_or_ps(x, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_EQ_OQ)))", f926, 1, 128},
  {"128:_mm_or_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_EQ_OQ)), x)", f927, 1, 128},
  {"128:_mm_or_ps(y, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_EQ_OQ)))", f928, 1, 128},
  {"128:_mm_or_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), y)), y)", f929, 1, 128},
  {"128:_mm_or_ps(x, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), y)))", f930, 1, 128},
  {"128:_mm_or_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), y)), x)", f931, 1, 128},
  {"128:_mm_or_ps(y, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), y)))", f932, 1, 128},
  {"128:_mm_or_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_UNORD_Q)), y)", f933, 1, 128},
  {"128:_mm_or_ps(x, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_UNORD_Q)))", f934, 1, 128},
  {"128:_mm_or_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_UNORD_Q)), x)", f935, 1, 128},
  {"128:_mm_or_ps(y, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_UNORD_Q)))", f936, 1, 128},
  {"128:_mm_or_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_UNORD_Q)), y)", f937, 1, 128},
  {"128:_mm_or_ps(x, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_UNORD_Q)))", f938, 1, 128},
  {"128:_mm_or_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_UNORD_Q)), x)", f939, 1, 128},
  {"128:_mm_or_ps(y, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_UNORD_Q)))", f940, 1, 128},
  {"128:_mm_or_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), y)), y)", f941, 1, 128},
  {"128:_mm_or_ps(x, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), y)))", f942, 1, 128},
  {"128:_mm_or_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), y)), x)", f943, 1, 128},
  {"128:_mm_or_ps(y, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), y)))", f944, 1, 128},
  {"128:_mm_or_ps(_mm_unpacklo_ps(x, y), y)", f945, 1, 128},
  {"128:_mm_or_ps(x, _mm_unpacklo_ps(x, y))", f946, 1, 128},
  {"128:_mm_or_ps(_mm_unpacklo_ps(x, y), x)", f947, 1, 128},
  {"128:_mm_or_ps(y, _mm_unpacklo_ps(x, y))", f948, 1, 128},
  {"128:_mm_or_ps(_mm_unpackhi_ps(x, y), y)", f949, 1, 128},
  {"128:_mm_or_ps(x, _mm_unpackhi_ps(x, y))", f950, 1, 128},
  {"128:_mm_or_ps(_mm_unpackhi_ps(x, y), x)", f951, 1, 128},
  {"128:_mm_or_ps(y, _mm_unpackhi_ps(x, y))", f952, 1, 128},
  {"128:_mm_or_ps(_mm_hadd_ps(x, y), y)", f953, 1, 128},
  {"128:_mm_or_ps(x, _mm_hadd_ps(x, y))", f954, 1, 128},
  {"128:_mm_or_ps(_mm_hadd_ps(x, y), x)", f955, 1, 128},
  {"128:_mm_or_ps(y, _mm_hadd_ps(x, y))", f956, 1, 128},
  {"128:_mm_or_ps(_mm_hsub_ps(x, y), y)", f957, 1, 128},
  {"128:_mm_or_ps(x, _mm_hsub_ps(x, y))", f958, 1, 128},
  {"128:_mm_or_ps(_mm_hsub_ps(x, y), x)", f959, 1, 128},
  {"128:_mm_or_ps(y, _mm_hsub_ps(x, y))", f960, 1, 128},
  {"128:_mm_or_ps(_mm_shuffle_ps(x, y, 0x1b), y)", f961, 1, 128},
  {"128:_mm_or_ps(x, _mm_shuffle_ps(x, y, 0x1b))", f962, 1, 128},
  {"128:_mm_or_ps(_mm_shuffle_ps(x, y, 0x1b), x)", f963, 1, 128},
  {"128:_mm_or_ps(y, _mm_shuffle_ps(x, y, 0x1b))", f964, 1, 128},
  {"128:_mm_or_ps(_mm_shuffle_ps(x, y, 0x39), y)", f965, 1, 128},
  {"128:_mm_or_ps(x, _mm_shuffle_ps(x, y, 0x39))", f966, 1, 128},
  {"128:_mm_or_ps(_mm_shuffle_ps(x, y, 0x39), x)", f967, 1, 128},
  {"128:_mm_or_ps(y, _mm_shuffle_ps(x, y, 0x39))", f968, 1, 128},
  {"128:_mm_or_ps(_mm_shuffle_ps(x, y, 0x93), y)", f969, 1, 128},
  {"128:_mm_or_ps(x, _mm_shuffle_ps(x, y, 0x93))", f970, 1, 128},
  {"128:_mm_or_ps(_mm_shuffle_ps(x, y, 0x93), x)", f971, 1, 128},
  {"128:_mm_or_ps(y, _mm_shuffle_ps(x, y, 0x93))", f972, 1, 128},
  {"128:_mm_or_ps(_mm_shuffle_ps(x, y, 0x4e), y)", f973, 1, 128},
  {"128:_mm_or_ps(x, _mm_shuffle_ps(x, y, 0x4e))", f974, 1, 128},
  {"128:_mm_or_ps(_mm_shuffle_ps(x, y, 0x4e), x)", f975, 1, 128},
  {"128:_mm_or_ps(y, _mm_shuffle_ps(x, y, 0x4e))", f976, 1, 128},
  {"128:_mm_xor_ps(_mm_add_ps(x, y), y)", f977, 1, 128},
  {"128:_mm_xor_ps(x, _mm_add_ps(x, y))", f978, 1, 128},
  {"128:_mm_xor_ps(_mm_add_ps(x, y), x)", f979, 1, 128},
  {"128:_mm_xor_ps(y, _mm_add_ps(x, y))", f980, 1, 128},
  {"128:_mm_xor_ps(_mm_sub_ps(x, y), y)", f981, 1, 128},
  {"128:_mm_xor_ps(x, _mm_sub_ps(x, y))", f982, 1, 128},
  {"128:_mm_xor_ps(_mm_sub_ps(x, y), x)", f983, 1, 128},
  {"128:_mm_xor_ps(y, _mm_sub_ps(x, y))", f984, 1, 128},
  {"128:_mm_xor_ps(_mm_mul_ps(x, y), y)", f985, 1, 128},
  {"128:_mm_xor_ps(x, _mm_mul_ps(x, y))", f986, 1, 128},
  {"128:_mm_xor_ps(_mm_mul_ps(x, y), x)", f987, 1, 128},
  {"128:_mm_xor_ps(y, _mm_mul_ps(x, y))", f988, 1, 128},
  {"128:_mm_xor_ps(_mm_div_ps(x, y), y)", f989, 1, 128},
  {"128:_mm_xor_ps(x, _mm_div_ps(x, y))", f990, 1, 128},
  {"128:_mm_xor_ps(_mm_div_ps(x, y), x)", f991, 1, 128},
  {"128:_mm_xor_ps(y, _mm_div_ps(x, y))", f992, 1, 128},
  {"128:_mm_xor_ps(_mm_min_ps(x, y), y)", f993, 1, 128},
  {"128:_mm_xor_ps(x, _mm_min_ps(x, y))", f994, 1, 128},
  {"128:_mm_xor_ps(_mm_min_ps(x, y), x)", f995, 1, 128},
  {"128:_mm_xor_ps(y, _mm_min_ps(x, y))", f996, 1, 128},
  {"128:_mm_xor_ps(_mm_max_ps(x, y), y)", f997, 1, 128},
  {"128:_mm_xor_ps(x, _mm_max_ps(x, y))", f998, 1, 128},
  {"128:_mm_xor_ps(_mm_max_ps(x, y), x)", f999, 1, 128},
  {"128:_mm_xor_ps(y, _mm_max_ps(x, y))", f1000, 1, 128},
  {"128:_mm_xor_ps(_mm_and_ps(x, y), y)", f1001, 1, 128},
  {"128:_mm_xor_ps(x, _mm_and_ps(x, y))", f1002, 1, 128},
  {"128:_mm_xor_ps(_mm_and_ps(x, y), x)", f1003, 1, 128},
  {"128:_mm_xor_ps(y, _mm_and_ps(x, y))", f1004, 1, 128},
  {"128:_mm_xor_ps(_mm_or_ps(x, y), y)", f1005, 1, 128},
  {"128:_mm_xor_ps(x, _mm_or_ps(x, y))", f1006, 1, 128},
  {"128:_mm_xor_ps(_mm_or_ps(x, y), x)", f1007, 1, 128},
  {"128:_mm_xor_ps(y, _mm_or_ps(x, y))", f1008, 1, 128},
  {"128:_mm_xor_ps(_mm_xor_ps(x, y), y)", f1009, 1, 128},
  {"128:_mm_xor_ps(x, _mm_xor_ps(x, y))", f1010, 1, 128},
  {"128:_mm_xor_ps(_mm_xor_ps(x, y), x)", f1011, 1, 128},
  {"128:_mm_xor_ps(y, _mm_xor_ps(x, y))", f1012, 1, 128},
  {"128:_mm_xor_ps(_mm_andnot_ps(x, y), y)", f1013, 1, 128},
  {"128:_mm_xor_ps(x, _mm_andnot_ps(x, y))", f1014, 1, 128},
  {"128:_mm_xor_ps(_mm_andnot_ps(x, y), x)", f1015, 1, 128},
  {"128:_mm_xor_ps(y, _mm_andnot_ps(x, y))", f1016, 1, 128},
  {"128:_mm_xor_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), y)", f1017, 1, 128},
  {"128:_mm_xor_ps(x, _mm_cmp_ps(x, y, _CMP_EQ_OQ))", f1018, 1, 128},
  {"128:_mm_xor_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), x)", f1019, 1, 128},
  {"128:_mm_xor_ps(y, _mm_cmp_ps(x, y, _CMP_EQ_OQ))", f1020, 1, 128},
  {"128:_mm_xor_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), y)", f1021, 1, 128},
  {"128:_mm_xor_ps(x, _mm_cmp_ps(x, y, _CMP_LT_OS))", f1022, 1, 128},
  {"128:_mm_xor_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), x)", f1023, 1, 128},
  {"128:_mm_xor_ps(y, _mm_cmp_ps(x, y, _CMP_LT_OS))", f1024, 1, 128},
  {"128:_mm_xor_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), y)", f1025, 1, 128},
  {"128:_mm_xor_ps(x, _mm_cmp_ps(x, y, _CMP_LE_OS))", f1026, 1, 128},
  {"128:_mm_xor_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), x)", f1027, 1, 128},
  {"128:_mm_xor_ps(y, _mm_cmp_ps(x, y, _CMP_LE_OS))", f1028, 1, 128},
  {"128:_mm_xor_ps(_mm_cmp_ps(x, y, _CMP_NEQ_UQ), y)", f1029, 1, 128},
  {"128:_mm_xor_ps(x, _mm_cmp_ps(x, y, _CMP_NEQ_UQ))", f1030, 1, 128},
  {"128:_mm_xor_ps(_mm_cmp_ps(x, y, _CMP_NEQ_UQ), x)", f1031, 1, 128},
  {"128:_mm_xor_ps(y, _mm_cmp_ps(x, y, _CMP_NEQ_UQ))", f1032, 1, 128},
  {"128:_mm_xor_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), y)", f1033, 1, 128},
  {"128:_mm_xor_ps(x, _mm_cmp_ps(x, y, _CMP_UNORD_Q))", f1034, 1, 128},
  {"128:_mm_xor_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), x)", f1035, 1, 128},
  {"128:_mm_xor_ps(y, _mm_cmp_ps(x, y, _CMP_UNORD_Q))", f1036, 1, 128},
  {"128:_mm_xor_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), y)", f1037, 1, 128},
  {"128:_mm_xor_ps(x, _mm_cmp_ps(x, y, _CMP_NLT_US))", f1038, 1, 128},
  {"128:_mm_xor_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), x)", f1039, 1, 128},
  {"128:_mm_xor_ps(y, _mm_cmp_ps(x, y, _CMP_NLT_US))", f1040, 1, 128},
  {"128:_mm_xor_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), y)", f1041, 1, 128},
  {"128:_mm_xor_ps(x, _mm_cmp_ps(x, y, _CMP_GT_OS))", f1042, 1, 128},
  {"128:_mm_xor_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), x)", f1043, 1, 128},
  {"128:_mm_xor_ps(y, _mm_cmp_ps(x, y, _CMP_GT_OS))", f1044, 1, 128},
  {"128:_mm_xor_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LT_OS)), y)", f1045, 1, 128},
  {"128:_mm_xor_ps(x, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LT_OS)))", f1046, 1, 128},
  {"128:_mm_xor_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LT_OS)), x)", f1047, 1, 128},
  {"128:_mm_xor_ps(y, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LT_OS)))", f1048, 1, 128},
  {"128:_mm_xor_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LT_OS)), y)", f1049, 1, 128},
  {"128:_mm_xor_ps(x, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LT_OS)))", f1050, 1, 128},
  {"128:_mm_xor_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LT_OS)), x)", f1051, 1, 128},
  {"128:_mm_xor_ps(y, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LT_OS)))", f1052, 1, 128},
  {"128:_mm_xor_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), y)), y)", f1053, 1, 128},
  {"128:_mm_xor_ps(x, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), y)))", f1054, 1, 128},
  {"128:_mm_xor_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), y)), x)", f1055, 1, 128},
  {"128:_mm_xor_ps(y, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), y)))", f1056, 1, 128},
  {"128:_mm_xor_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LE_OS)), y)", f1057, 1, 128},
  {"128:_mm_xor_ps(x, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LE_OS)))", f1058, 1, 128},
  {"128:_mm_xor_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LE_OS)), x)", f1059, 1, 128},
  {"128:_mm_xor_ps(y, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LE_OS)))", f1060, 1, 128},
  {"128:_mm_xor_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LE_OS)), y)", f1061, 1, 128},
  {"128:_mm_xor_ps(x, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LE_OS)))", f1062, 1, 128},
  {"128:_mm_xor_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LE_OS)), x)", f1063, 1, 128},
  {"128:_mm_xor_ps(y, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LE_OS)))", f1064, 1, 128},
  {"128:_mm_xor_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), y)), y)", f1065, 1, 128},
  {"128:_mm_xor_ps(x, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), y)))", f1066, 1, 128},
  {"128:_mm_xor_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), y)), x)", f1067, 1, 128},
  {"128:_mm_xor_ps(y, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), y)))", f1068, 1, 128},
  {"128:_mm_xor_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_GT_OS)), y)", f1069, 1, 128},
  {"128:_mm_xor_ps(x, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_GT_OS)))", f1070, 1, 128},
  {"128:_mm_xor_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_GT_OS)), x)", f1071, 1, 128},
  {"128:_mm_xor_ps(y, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_GT_OS)))", f1072, 1, 128},
  {"128:_mm_xor_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_GT_OS)), y)", f1073, 1, 128},
  {"128:_mm_xor_ps(x, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_GT_OS)))", f1074, 1, 128},
  {"128:_mm_xor_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_GT_OS)), x)", f1075, 1, 128},
  {"128:_mm_xor_ps(y, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_GT_OS)))", f1076, 1, 128},
  {"128:_mm_xor_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), y)), y)", f1077, 1, 128},
  {"128:_mm_xor_ps(x, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), y)))", f1078, 1, 128},
  {"128:_mm_xor_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), y)), x)", f1079, 1, 128},
  {"128:_mm_xor_ps(y, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), y)))", f1080, 1, 128},
  {"128:_mm_xor_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_NLT_US)), y)", f1081, 1, 128},
  {"128:_mm_xor_ps(x, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_NLT_US)))", f1082, 1, 128},
  {"128:_mm_xor_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_NLT_US)), x)", f1083, 1, 128},
  {"128:_mm_xor_ps(y, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_NLT_US)))", f1084, 1, 128},
  {"128:_mm_xor_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_NLT_US)), y)", f1085, 1, 128},
  {"128:_mm_xor_ps(x, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_NLT_US)))", f1086, 1, 128},
  {"128:_mm_xor_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_NLT_US)), x)", f1087, 1, 128},
  {"128:_mm_xor_ps(y, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_NLT_US)))", f1088, 1, 128},
  {"128:_mm_xor_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), y)), y)", f1089, 1, 128},
  {"128:_mm_xor_ps(x, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), y)))", f1090, 1, 128},
  {"128:_mm_xor_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), y)), x)", f1091, 1, 128},
  {"128:_mm_xor_ps(y, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), y)))", f1092, 1, 128},
  {"128:_mm_xor_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_EQ_OQ)), y)", f1093, 1, 128},
  {"128:_mm_xor_ps(x, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_EQ_OQ)))", f1094, 1, 128},
  {"128:_mm_xor_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_EQ_OQ)), x)", f1095, 1, 128},
  {"128:_mm_xor_ps(y, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_EQ_OQ)))", f1096, 1, 128},
  {"128:_mm_xor_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_EQ_OQ)), y)", f1097, 1, 128},
  {"128:_mm_xor_ps(x, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_EQ_OQ)))", f1098, 1, 128},
  {"128:_mm_xor_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_EQ_OQ)), x)", f1099, 1, 128},
  {"128:_mm_xor_ps(y, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_EQ_OQ)))", f1100, 1, 128},
  {"128:_mm_xor_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), y)), y)", f1101, 1, 128},
  {"128:_mm_xor_ps(x, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), y)))", f1102, 1, 128},
  {"128:_mm_xor_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), y)), x)", f1103, 1, 128},
  {"128:_mm_xor_ps(y, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), y)))", f1104, 1, 128},
  {"128:_mm_xor_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_UNORD_Q)), y)", f1105, 1, 128},
  {"128:_mm_xor_ps(x, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_UNORD_Q)))", f1106, 1, 128},
  {"128:_mm_xor_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_UNORD_Q)), x)", f1107, 1, 128},
  {"128:_mm_xor_ps(y, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_UNORD_Q)))", f1108, 1, 128},
  {"128:_mm_xor_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_UNORD_Q)), y)", f1109, 1, 128},
  {"128:_mm_xor_ps(x, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_UNORD_Q)))", f1110, 1, 128},
  {"128:_mm_xor_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_UNORD_Q)), x)", f1111, 1, 128},
  {"128:_mm_xor_ps(y, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_UNORD_Q)))", f1112, 1, 128},
  {"128:_mm_xor_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), y)), y)", f1113, 1, 128},
  {"128:_mm_xor_ps(x, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), y)))", f1114, 1, 128},
  {"128:_mm_xor_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), y)), x)", f1115, 1, 128},
  {"128:_mm_xor_ps(y, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), y)))", f1116, 1, 128},
  {"128:_mm_xor_ps(_mm_unpacklo_ps(x, y), y)", f1117, 1, 128},
  {"128:_mm_xor_ps(x, _mm_unpacklo_ps(x, y))", f1118, 1, 128},
  {"128:_mm_xor_ps(_mm_unpacklo_ps(x, y), x)", f1119, 1, 128},
  {"128:_mm_xor_ps(y, _mm_unpacklo_ps(x, y))", f1120, 1, 128},
  {"128:_mm_xor_ps(_mm_unpackhi_ps(x, y), y)", f1121, 1, 128},
  {"128:_mm_xor_ps(x, _mm_unpackhi_ps(x, y))", f1122, 1, 128},
  {"128:_mm_xor_ps(_mm_unpackhi_ps(x, y), x)", f1123, 1, 128},
  {"128:_mm_xor_ps(y, _mm_unpackhi_ps(x, y))", f1124, 1, 128},
  {"128:_mm_xor_ps(_mm_hadd_ps(x, y), y)", f1125, 1, 128},
  {"128:_mm_xor_ps(x, _mm_hadd_ps(x, y))", f1126, 1, 128},
  {"128:_mm_xor_ps(_mm_hadd_ps(x, y), x)", f1127, 1, 128},
  {"128:_mm_xor_ps(y, _mm_hadd_ps(x, y))", f1128, 1, 128},
  {"128:_mm_xor_ps(_mm_hsub_ps(x, y), y)", f1129, 1, 128},
  {"128:_mm_xor_ps(x, _mm_hsub_ps(x, y))", f1130, 1, 128},
  {"128:_mm_xor_ps(_mm_hsub_ps(x, y), x)", f1131, 1, 128},
  {"128:_mm_xor_ps(y, _mm_hsub_ps(x, y))", f1132, 1, 128},
  {"128:_mm_xor_ps(_mm_shuffle_ps(x, y, 0x1b), y)", f1133, 1, 128},
  {"128:_mm_xor_ps(x, _mm_shuffle_ps(x, y, 0x1b))", f1134, 1, 128},
  {"128:_mm_xor_ps(_mm_shuffle_ps(x, y, 0x1b), x)", f1135, 1, 128},
  {"128:_mm_xor_ps(y, _mm_shuffle_ps(x, y, 0x1b))", f1136, 1, 128},
  {"128:_mm_xor_ps(_mm_shuffle_ps(x, y, 0x39), y)", f1137, 1, 128},
  {"128:_mm_xor_ps(x, _mm_shuffle_ps(x, y, 0x39))", f1138, 1, 128},
  {"128:_mm_xor_ps(_mm_shuffle_ps(x, y, 0x39), x)", f1139, 1, 128},
  {"128:_mm_xor_ps(y, _mm_shuffle_ps(x, y, 0x39))", f1140, 1, 128},
  {"128:_mm_xor_ps(_mm_shuffle_ps(x, y, 0x93), y)", f1141, 1, 128},
  {"128:_mm_xor_ps(x, _mm_shuffle_ps(x, y, 0x93))", f1142, 1, 128},
  {"128:_mm_xor_ps(_mm_shuffle_ps(x, y, 0x93), x)", f1143, 1, 128},
  {"128:_mm_xor_ps(y, _mm_shuffle_ps(x, y, 0x93))", f1144, 1, 128},
  {"128:_mm_xor_ps(_mm_shuffle_ps(x, y, 0x4e), y)", f1145, 1, 128},
  {"128:_mm_xor_ps(x, _mm_shuffle_ps(x, y, 0x4e))", f1146, 1, 128},
  {"128:_mm_xor_ps(_mm_shuffle_ps(x, y, 0x4e), x)", f1147, 1, 128},
  {"128:_mm_xor_ps(y, _mm_shuffle_ps(x, y, 0x4e))", f1148, 1, 128},
  {"128:_mm_andnot_ps(_mm_add_ps(x, y), y)", f1149, 1, 128},
  {"128:_mm_andnot_ps(x, _mm_add_ps(x, y))", f1150, 1, 128},
  {"128:_mm_andnot_ps(_mm_add_ps(x, y), x)", f1151, 1, 128},
  {"128:_mm_andnot_ps(y, _mm_add_ps(x, y))", f1152, 1, 128},
  {"128:_mm_andnot_ps(_mm_sub_ps(x, y), y)", f1153, 1, 128},
  {"128:_mm_andnot_ps(x, _mm_sub_ps(x, y))", f1154, 1, 128},
  {"128:_mm_andnot_ps(_mm_sub_ps(x, y), x)", f1155, 1, 128},
  {"128:_mm_andnot_ps(y, _mm_sub_ps(x, y))", f1156, 1, 128},
  {"128:_mm_andnot_ps(_mm_mul_ps(x, y), y)", f1157, 1, 128},
  {"128:_mm_andnot_ps(x, _mm_mul_ps(x, y))", f1158, 1, 128},
  {"128:_mm_andnot_ps(_mm_mul_ps(x, y), x)", f1159, 1, 128},
  {"128:_mm_andnot_ps(y, _mm_mul_ps(x, y))", f1160, 1, 128},
  {"128:_mm_andnot_ps(_mm_div_ps(x, y), y)", f1161, 1, 128},
  {"128:_mm_andnot_ps(x, _mm_div_ps(x, y))", f1162, 1, 128},
  {"128:_mm_andnot_ps(_mm_div_ps(x, y), x)", f1163, 1, 128},
  {"128:_mm_andnot_ps(y, _mm_div_ps(x, y))", f1164, 1, 128},
  {"128:_mm_andnot_ps(_mm_min_ps(x, y), y)", f1165, 1, 128},
  {"128:_mm_andnot_ps(x, _mm_min_ps(x, y))", f1166, 1, 128},
  {"128:_mm_andnot_ps(_mm_min_ps(x, y), x)", f1167, 1, 128},
  {"128:_mm_andnot_ps(y, _mm_min_ps(x, y))", f1168, 1, 128},
  {"128:_mm_andnot_ps(_mm_max_ps(x, y), y)", f1169, 1, 128},
  {"128:_mm_andnot_ps(x, _mm_max_ps(x, y))", f1170, 1, 128},
  {"128:_mm_andnot_ps(_mm_max_ps(x, y), x)", f1171, 1, 128},
  {"128:_mm_andnot_ps(y, _mm_max_ps(x, y))", f1172, 1, 128},
  {"128:_mm_andnot_ps(_mm_and_ps(x, y), y)", f1173, 1, 128},
  {"128:_mm_andnot_ps(x, _mm_and_ps(x, y))", f1174, 1, 128},
  {"128:_mm_andnot_ps(_mm_and_ps(x, y), x)", f1175, 1, 128},
  {"128:_mm_andnot_ps(y, _mm_and_ps(x, y))", f1176, 1, 128},
  {"128:_mm_andnot_ps(_mm_or_ps(x, y), y)", f1177, 1, 128},
  {"128:_mm_andnot_ps(x, _mm_or_ps(x, y))", f1178, 1, 128},
  {"128:_mm_andnot_ps(_mm_or_ps(x, y), x)", f1179, 1, 128},
  {"128:_mm_andnot_ps(y, _mm_or_ps(x, y))", f1180, 1, 128},
  {"128:_mm_andnot_ps(_mm_xor_ps(x, y), y)", f1181, 1, 128},
  {"128:_mm_andnot_ps(x, _mm_xor_ps(x, y))", f1182, 1, 128},
  {"128:_mm_andnot_ps(_mm_xor_ps(x, y), x)", f1183, 1, 128},
  {"128:_mm_andnot_ps(y, _mm_xor_ps(x, y))", f1184, 1, 128},
  {"128:_mm_andnot_ps(_mm_andnot_ps(x, y), y)", f1185, 1, 128},
  {"128:_mm_andnot_ps(x, _mm_andnot_ps(x, y))", f1186, 1, 128},
  {"128:_mm_andnot_ps(_mm_andnot_ps(x, y), x)", f1187, 1, 128},
  {"128:_mm_andnot_ps(y, _mm_andnot_ps(x, y))", f1188, 1, 128},
  {"128:_mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), y)", f1189, 1, 128},
  {"128:_mm_andnot_ps(x, _mm_cmp_ps(x, y, _CMP_EQ_OQ))", f1190, 1, 128},
  {"128:_mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), x)", f1191, 1, 128},
  {"128:_mm_andnot_ps(y, _mm_cmp_ps(x, y, _CMP_EQ_OQ))", f1192, 1, 128},
  {"128:_mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), y)", f1193, 1, 128},
  {"128:_mm_andnot_ps(x, _mm_cmp_ps(x, y, _CMP_LT_OS))", f1194, 1, 128},
  {"128:_mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), x)", f1195, 1, 128},
  {"128:_mm_andnot_ps(y, _mm_cmp_ps(x, y, _CMP_LT_OS))", f1196, 1, 128},
  {"128:_mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), y)", f1197, 1, 128},
  {"128:_mm_andnot_ps(x, _mm_cmp_ps(x, y, _CMP_LE_OS))", f1198, 1, 128},
  {"128:_mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), x)", f1199, 1, 128},
};
extern const int size_26 = 1200;
