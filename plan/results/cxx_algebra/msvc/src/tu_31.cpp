#include "common.h"
static NOINLINE void f0(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hadd_ps(y, _mm_xor_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hadd_ps(_mm_andnot_ps(x, y), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f2(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hadd_ps(x, _mm_andnot_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f3(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hadd_ps(_mm_andnot_ps(x, y), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f4(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hadd_ps(y, _mm_andnot_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f5(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hadd_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f6(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hadd_ps(x, _mm_cmp_ps(x, y, _CMP_EQ_OQ)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f7(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hadd_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f8(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hadd_ps(y, _mm_cmp_ps(x, y, _CMP_EQ_OQ)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f9(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hadd_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f10(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hadd_ps(x, _mm_cmp_ps(x, y, _CMP_LT_OS)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f11(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hadd_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f12(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hadd_ps(y, _mm_cmp_ps(x, y, _CMP_LT_OS)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f13(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hadd_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f14(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hadd_ps(x, _mm_cmp_ps(x, y, _CMP_LE_OS)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f15(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hadd_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f16(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hadd_ps(y, _mm_cmp_ps(x, y, _CMP_LE_OS)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f17(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hadd_ps(_mm_cmp_ps(x, y, _CMP_NEQ_UQ), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f18(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hadd_ps(x, _mm_cmp_ps(x, y, _CMP_NEQ_UQ)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f19(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hadd_ps(_mm_cmp_ps(x, y, _CMP_NEQ_UQ), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f20(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hadd_ps(y, _mm_cmp_ps(x, y, _CMP_NEQ_UQ)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f21(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hadd_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f22(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hadd_ps(x, _mm_cmp_ps(x, y, _CMP_UNORD_Q)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f23(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hadd_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f24(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hadd_ps(y, _mm_cmp_ps(x, y, _CMP_UNORD_Q)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f25(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hadd_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f26(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hadd_ps(x, _mm_cmp_ps(x, y, _CMP_NLT_US)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f27(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hadd_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f28(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hadd_ps(y, _mm_cmp_ps(x, y, _CMP_NLT_US)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f29(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hadd_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f30(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hadd_ps(x, _mm_cmp_ps(x, y, _CMP_GT_OS)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f31(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hadd_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f32(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hadd_ps(y, _mm_cmp_ps(x, y, _CMP_GT_OS)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f33(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hadd_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LT_OS)), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f34(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hadd_ps(x, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LT_OS))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f35(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hadd_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LT_OS)), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f36(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hadd_ps(y, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LT_OS))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f37(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hadd_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LT_OS)), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f38(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hadd_ps(x, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LT_OS))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f39(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hadd_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LT_OS)), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f40(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hadd_ps(y, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LT_OS))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f41(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hadd_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), y)), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f42(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hadd_ps(x, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), y))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f43(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hadd_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), y)), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f44(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hadd_ps(y, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), y))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f45(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hadd_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LE_OS)), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f46(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hadd_ps(x, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LE_OS))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f47(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hadd_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LE_OS)), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f48(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hadd_ps(y, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LE_OS))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f49(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hadd_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LE_OS)), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f50(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hadd_ps(x, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LE_OS))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f51(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hadd_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LE_OS)), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f52(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hadd_ps(y, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LE_OS))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f53(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hadd_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), y)), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f54(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hadd_ps(x, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), y))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f55(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hadd_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), y)), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f56(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hadd_ps(y, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), y))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f57(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hadd_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_GT_OS)), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f58(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hadd_ps(x, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_GT_OS))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f59(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hadd_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_GT_OS)), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f60(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hadd_ps(y, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_GT_OS))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f61(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hadd_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_GT_OS)), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f62(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hadd_ps(x, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_GT_OS))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f63(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hadd_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_GT_OS)), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f64(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hadd_ps(y, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_GT_OS))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f65(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hadd_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), y)), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f66(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hadd_ps(x, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), y))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f67(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hadd_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), y)), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f68(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hadd_ps(y, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), y))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f69(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hadd_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_NLT_US)), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f70(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hadd_ps(x, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_NLT_US))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f71(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hadd_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_NLT_US)), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f72(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hadd_ps(y, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_NLT_US))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f73(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hadd_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_NLT_US)), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f74(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hadd_ps(x, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_NLT_US))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f75(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hadd_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_NLT_US)), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f76(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hadd_ps(y, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_NLT_US))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f77(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hadd_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), y)), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f78(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hadd_ps(x, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), y))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f79(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hadd_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), y)), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f80(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hadd_ps(y, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), y))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f81(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hadd_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_EQ_OQ)), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f82(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hadd_ps(x, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_EQ_OQ))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f83(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hadd_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_EQ_OQ)), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f84(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hadd_ps(y, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_EQ_OQ))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f85(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hadd_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_EQ_OQ)), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f86(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hadd_ps(x, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_EQ_OQ))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f87(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hadd_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_EQ_OQ)), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f88(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hadd_ps(y, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_EQ_OQ))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f89(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hadd_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), y)), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f90(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hadd_ps(x, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), y))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f91(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hadd_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), y)), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f92(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hadd_ps(y, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), y))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f93(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hadd_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_UNORD_Q)), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f94(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hadd_ps(x, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_UNORD_Q))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f95(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hadd_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_UNORD_Q)), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f96(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hadd_ps(y, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_UNORD_Q))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f97(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hadd_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_UNORD_Q)), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f98(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hadd_ps(x, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_UNORD_Q))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f99(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hadd_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_UNORD_Q)), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f100(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hadd_ps(y, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_UNORD_Q))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f101(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hadd_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), y)), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f102(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hadd_ps(x, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), y))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f103(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hadd_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), y)), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f104(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hadd_ps(y, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), y))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f105(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hadd_ps(_mm_unpacklo_ps(x, y), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f106(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hadd_ps(x, _mm_unpacklo_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f107(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hadd_ps(_mm_unpacklo_ps(x, y), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f108(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hadd_ps(y, _mm_unpacklo_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f109(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hadd_ps(_mm_unpackhi_ps(x, y), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f110(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hadd_ps(x, _mm_unpackhi_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f111(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hadd_ps(_mm_unpackhi_ps(x, y), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f112(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hadd_ps(y, _mm_unpackhi_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f113(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hadd_ps(_mm_hadd_ps(x, y), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f114(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hadd_ps(x, _mm_hadd_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f115(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hadd_ps(_mm_hadd_ps(x, y), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f116(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hadd_ps(y, _mm_hadd_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f117(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hadd_ps(_mm_hsub_ps(x, y), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f118(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hadd_ps(x, _mm_hsub_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f119(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hadd_ps(_mm_hsub_ps(x, y), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f120(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hadd_ps(y, _mm_hsub_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f121(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hadd_ps(_mm_shuffle_ps(x, y, 0x1b), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f122(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hadd_ps(x, _mm_shuffle_ps(x, y, 0x1b)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f123(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hadd_ps(_mm_shuffle_ps(x, y, 0x1b), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f124(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hadd_ps(y, _mm_shuffle_ps(x, y, 0x1b)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f125(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hadd_ps(_mm_shuffle_ps(x, y, 0x39), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f126(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hadd_ps(x, _mm_shuffle_ps(x, y, 0x39)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f127(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hadd_ps(_mm_shuffle_ps(x, y, 0x39), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f128(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hadd_ps(y, _mm_shuffle_ps(x, y, 0x39)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f129(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hadd_ps(_mm_shuffle_ps(x, y, 0x93), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f130(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hadd_ps(x, _mm_shuffle_ps(x, y, 0x93)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f131(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hadd_ps(_mm_shuffle_ps(x, y, 0x93), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f132(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hadd_ps(y, _mm_shuffle_ps(x, y, 0x93)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f133(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hadd_ps(_mm_shuffle_ps(x, y, 0x4e), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f134(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hadd_ps(x, _mm_shuffle_ps(x, y, 0x4e)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f135(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hadd_ps(_mm_shuffle_ps(x, y, 0x4e), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f136(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hadd_ps(y, _mm_shuffle_ps(x, y, 0x4e)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f137(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hsub_ps(_mm_add_ps(x, y), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f138(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hsub_ps(x, _mm_add_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f139(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hsub_ps(_mm_add_ps(x, y), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f140(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hsub_ps(y, _mm_add_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f141(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hsub_ps(_mm_sub_ps(x, y), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f142(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hsub_ps(x, _mm_sub_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f143(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hsub_ps(_mm_sub_ps(x, y), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f144(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hsub_ps(y, _mm_sub_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f145(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hsub_ps(_mm_mul_ps(x, y), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f146(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hsub_ps(x, _mm_mul_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f147(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hsub_ps(_mm_mul_ps(x, y), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f148(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hsub_ps(y, _mm_mul_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f149(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hsub_ps(_mm_div_ps(x, y), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f150(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hsub_ps(x, _mm_div_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f151(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hsub_ps(_mm_div_ps(x, y), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f152(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hsub_ps(y, _mm_div_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f153(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hsub_ps(_mm_min_ps(x, y), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f154(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hsub_ps(x, _mm_min_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f155(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hsub_ps(_mm_min_ps(x, y), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f156(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hsub_ps(y, _mm_min_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f157(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hsub_ps(_mm_max_ps(x, y), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f158(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hsub_ps(x, _mm_max_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f159(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hsub_ps(_mm_max_ps(x, y), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f160(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hsub_ps(y, _mm_max_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f161(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hsub_ps(_mm_and_ps(x, y), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f162(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hsub_ps(x, _mm_and_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f163(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hsub_ps(_mm_and_ps(x, y), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f164(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hsub_ps(y, _mm_and_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f165(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hsub_ps(_mm_or_ps(x, y), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f166(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hsub_ps(x, _mm_or_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f167(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hsub_ps(_mm_or_ps(x, y), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f168(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hsub_ps(y, _mm_or_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f169(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hsub_ps(_mm_xor_ps(x, y), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f170(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hsub_ps(x, _mm_xor_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f171(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hsub_ps(_mm_xor_ps(x, y), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f172(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hsub_ps(y, _mm_xor_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f173(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hsub_ps(_mm_andnot_ps(x, y), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f174(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hsub_ps(x, _mm_andnot_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f175(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hsub_ps(_mm_andnot_ps(x, y), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f176(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hsub_ps(y, _mm_andnot_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f177(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hsub_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f178(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hsub_ps(x, _mm_cmp_ps(x, y, _CMP_EQ_OQ)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f179(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hsub_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f180(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hsub_ps(y, _mm_cmp_ps(x, y, _CMP_EQ_OQ)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f181(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hsub_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f182(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hsub_ps(x, _mm_cmp_ps(x, y, _CMP_LT_OS)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f183(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hsub_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f184(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hsub_ps(y, _mm_cmp_ps(x, y, _CMP_LT_OS)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f185(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hsub_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f186(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hsub_ps(x, _mm_cmp_ps(x, y, _CMP_LE_OS)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f187(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hsub_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f188(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hsub_ps(y, _mm_cmp_ps(x, y, _CMP_LE_OS)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f189(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hsub_ps(_mm_cmp_ps(x, y, _CMP_NEQ_UQ), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f190(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hsub_ps(x, _mm_cmp_ps(x, y, _CMP_NEQ_UQ)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f191(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hsub_ps(_mm_cmp_ps(x, y, _CMP_NEQ_UQ), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f192(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hsub_ps(y, _mm_cmp_ps(x, y, _CMP_NEQ_UQ)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f193(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hsub_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f194(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hsub_ps(x, _mm_cmp_ps(x, y, _CMP_UNORD_Q)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f195(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hsub_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f196(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hsub_ps(y, _mm_cmp_ps(x, y, _CMP_UNORD_Q)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f197(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hsub_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f198(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hsub_ps(x, _mm_cmp_ps(x, y, _CMP_NLT_US)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f199(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hsub_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f200(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hsub_ps(y, _mm_cmp_ps(x, y, _CMP_NLT_US)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f201(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hsub_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f202(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hsub_ps(x, _mm_cmp_ps(x, y, _CMP_GT_OS)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f203(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hsub_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f204(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hsub_ps(y, _mm_cmp_ps(x, y, _CMP_GT_OS)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f205(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hsub_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LT_OS)), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f206(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hsub_ps(x, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LT_OS))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f207(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hsub_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LT_OS)), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f208(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hsub_ps(y, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LT_OS))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f209(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hsub_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LT_OS)), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f210(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hsub_ps(x, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LT_OS))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f211(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hsub_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LT_OS)), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f212(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hsub_ps(y, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LT_OS))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f213(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hsub_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), y)), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f214(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hsub_ps(x, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), y))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f215(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hsub_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), y)), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f216(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hsub_ps(y, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), y))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f217(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hsub_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LE_OS)), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f218(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hsub_ps(x, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LE_OS))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f219(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hsub_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LE_OS)), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f220(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hsub_ps(y, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LE_OS))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f221(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hsub_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LE_OS)), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f222(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hsub_ps(x, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LE_OS))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f223(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hsub_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LE_OS)), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f224(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hsub_ps(y, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LE_OS))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f225(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hsub_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), y)), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f226(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hsub_ps(x, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), y))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f227(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hsub_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), y)), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f228(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hsub_ps(y, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), y))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f229(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hsub_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_GT_OS)), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f230(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hsub_ps(x, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_GT_OS))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f231(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hsub_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_GT_OS)), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f232(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hsub_ps(y, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_GT_OS))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f233(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hsub_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_GT_OS)), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f234(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hsub_ps(x, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_GT_OS))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f235(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hsub_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_GT_OS)), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f236(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hsub_ps(y, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_GT_OS))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f237(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hsub_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), y)), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f238(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hsub_ps(x, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), y))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f239(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hsub_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), y)), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f240(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hsub_ps(y, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), y))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f241(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hsub_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_NLT_US)), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f242(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hsub_ps(x, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_NLT_US))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f243(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hsub_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_NLT_US)), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f244(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hsub_ps(y, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_NLT_US))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f245(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hsub_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_NLT_US)), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f246(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hsub_ps(x, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_NLT_US))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f247(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hsub_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_NLT_US)), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f248(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hsub_ps(y, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_NLT_US))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f249(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hsub_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), y)), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f250(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hsub_ps(x, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), y))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f251(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hsub_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), y)), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f252(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hsub_ps(y, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), y))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f253(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hsub_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_EQ_OQ)), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f254(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hsub_ps(x, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_EQ_OQ))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f255(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hsub_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_EQ_OQ)), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f256(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hsub_ps(y, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_EQ_OQ))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f257(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hsub_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_EQ_OQ)), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f258(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hsub_ps(x, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_EQ_OQ))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f259(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hsub_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_EQ_OQ)), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f260(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hsub_ps(y, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_EQ_OQ))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f261(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hsub_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), y)), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f262(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hsub_ps(x, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), y))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f263(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hsub_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), y)), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f264(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hsub_ps(y, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), y))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f265(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hsub_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_UNORD_Q)), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f266(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hsub_ps(x, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_UNORD_Q))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f267(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hsub_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_UNORD_Q)), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f268(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hsub_ps(y, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_UNORD_Q))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f269(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hsub_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_UNORD_Q)), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f270(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hsub_ps(x, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_UNORD_Q))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f271(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hsub_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_UNORD_Q)), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f272(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hsub_ps(y, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_UNORD_Q))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f273(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hsub_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), y)), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f274(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hsub_ps(x, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), y))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f275(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hsub_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), y)), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f276(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hsub_ps(y, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), y))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f277(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hsub_ps(_mm_unpacklo_ps(x, y), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f278(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hsub_ps(x, _mm_unpacklo_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f279(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hsub_ps(_mm_unpacklo_ps(x, y), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f280(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hsub_ps(y, _mm_unpacklo_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f281(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hsub_ps(_mm_unpackhi_ps(x, y), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f282(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hsub_ps(x, _mm_unpackhi_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f283(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hsub_ps(_mm_unpackhi_ps(x, y), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f284(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hsub_ps(y, _mm_unpackhi_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f285(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hsub_ps(_mm_hadd_ps(x, y), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f286(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hsub_ps(x, _mm_hadd_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f287(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hsub_ps(_mm_hadd_ps(x, y), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f288(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hsub_ps(y, _mm_hadd_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f289(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hsub_ps(_mm_hsub_ps(x, y), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f290(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hsub_ps(x, _mm_hsub_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f291(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hsub_ps(_mm_hsub_ps(x, y), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f292(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hsub_ps(y, _mm_hsub_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f293(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hsub_ps(_mm_shuffle_ps(x, y, 0x1b), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f294(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hsub_ps(x, _mm_shuffle_ps(x, y, 0x1b)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f295(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hsub_ps(_mm_shuffle_ps(x, y, 0x1b), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f296(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hsub_ps(y, _mm_shuffle_ps(x, y, 0x1b)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f297(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hsub_ps(_mm_shuffle_ps(x, y, 0x39), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f298(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hsub_ps(x, _mm_shuffle_ps(x, y, 0x39)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f299(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hsub_ps(_mm_shuffle_ps(x, y, 0x39), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f300(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hsub_ps(y, _mm_shuffle_ps(x, y, 0x39)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f301(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hsub_ps(_mm_shuffle_ps(x, y, 0x93), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f302(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hsub_ps(x, _mm_shuffle_ps(x, y, 0x93)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f303(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hsub_ps(_mm_shuffle_ps(x, y, 0x93), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f304(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hsub_ps(y, _mm_shuffle_ps(x, y, 0x93)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f305(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hsub_ps(_mm_shuffle_ps(x, y, 0x4e), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f306(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hsub_ps(x, _mm_shuffle_ps(x, y, 0x4e)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f307(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hsub_ps(_mm_shuffle_ps(x, y, 0x4e), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f308(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hsub_ps(y, _mm_shuffle_ps(x, y, 0x4e)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f309(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_add_ps(x, y), y, 0x1b); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f310(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(x, _mm_add_ps(x, y), 0x1b); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f311(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_add_ps(x, y), x, 0x1b); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f312(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(y, _mm_add_ps(x, y), 0x1b); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f313(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_sub_ps(x, y), y, 0x1b); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f314(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(x, _mm_sub_ps(x, y), 0x1b); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f315(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_sub_ps(x, y), x, 0x1b); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f316(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(y, _mm_sub_ps(x, y), 0x1b); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f317(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_mul_ps(x, y), y, 0x1b); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f318(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(x, _mm_mul_ps(x, y), 0x1b); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f319(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_mul_ps(x, y), x, 0x1b); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f320(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(y, _mm_mul_ps(x, y), 0x1b); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f321(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_div_ps(x, y), y, 0x1b); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f322(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(x, _mm_div_ps(x, y), 0x1b); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f323(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_div_ps(x, y), x, 0x1b); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f324(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(y, _mm_div_ps(x, y), 0x1b); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f325(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_min_ps(x, y), y, 0x1b); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f326(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(x, _mm_min_ps(x, y), 0x1b); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f327(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_min_ps(x, y), x, 0x1b); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f328(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(y, _mm_min_ps(x, y), 0x1b); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f329(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_max_ps(x, y), y, 0x1b); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f330(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(x, _mm_max_ps(x, y), 0x1b); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f331(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_max_ps(x, y), x, 0x1b); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f332(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(y, _mm_max_ps(x, y), 0x1b); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f333(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_and_ps(x, y), y, 0x1b); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f334(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(x, _mm_and_ps(x, y), 0x1b); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f335(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_and_ps(x, y), x, 0x1b); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f336(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(y, _mm_and_ps(x, y), 0x1b); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f337(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_or_ps(x, y), y, 0x1b); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f338(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(x, _mm_or_ps(x, y), 0x1b); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f339(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_or_ps(x, y), x, 0x1b); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f340(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(y, _mm_or_ps(x, y), 0x1b); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f341(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_xor_ps(x, y), y, 0x1b); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f342(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(x, _mm_xor_ps(x, y), 0x1b); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f343(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_xor_ps(x, y), x, 0x1b); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f344(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(y, _mm_xor_ps(x, y), 0x1b); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f345(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_andnot_ps(x, y), y, 0x1b); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f346(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(x, _mm_andnot_ps(x, y), 0x1b); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f347(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_andnot_ps(x, y), x, 0x1b); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f348(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(y, _mm_andnot_ps(x, y), 0x1b); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f349(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), y, 0x1b); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f350(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(x, _mm_cmp_ps(x, y, _CMP_EQ_OQ), 0x1b); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f351(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), x, 0x1b); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f352(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(y, _mm_cmp_ps(x, y, _CMP_EQ_OQ), 0x1b); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f353(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), y, 0x1b); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f354(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(x, _mm_cmp_ps(x, y, _CMP_LT_OS), 0x1b); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f355(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), x, 0x1b); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f356(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(y, _mm_cmp_ps(x, y, _CMP_LT_OS), 0x1b); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f357(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), y, 0x1b); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f358(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(x, _mm_cmp_ps(x, y, _CMP_LE_OS), 0x1b); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f359(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), x, 0x1b); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f360(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(y, _mm_cmp_ps(x, y, _CMP_LE_OS), 0x1b); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f361(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_cmp_ps(x, y, _CMP_NEQ_UQ), y, 0x1b); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f362(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(x, _mm_cmp_ps(x, y, _CMP_NEQ_UQ), 0x1b); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f363(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_cmp_ps(x, y, _CMP_NEQ_UQ), x, 0x1b); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f364(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(y, _mm_cmp_ps(x, y, _CMP_NEQ_UQ), 0x1b); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f365(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), y, 0x1b); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f366(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(x, _mm_cmp_ps(x, y, _CMP_UNORD_Q), 0x1b); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f367(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), x, 0x1b); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f368(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(y, _mm_cmp_ps(x, y, _CMP_UNORD_Q), 0x1b); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f369(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), y, 0x1b); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f370(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(x, _mm_cmp_ps(x, y, _CMP_NLT_US), 0x1b); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f371(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), x, 0x1b); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f372(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(y, _mm_cmp_ps(x, y, _CMP_NLT_US), 0x1b); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f373(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), y, 0x1b); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f374(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(x, _mm_cmp_ps(x, y, _CMP_GT_OS), 0x1b); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f375(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), x, 0x1b); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f376(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(y, _mm_cmp_ps(x, y, _CMP_GT_OS), 0x1b); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f377(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LT_OS)), y, 0x1b); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f378(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(x, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LT_OS)), 0x1b); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f379(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LT_OS)), x, 0x1b); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f380(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(y, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LT_OS)), 0x1b); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f381(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LT_OS)), y, 0x1b); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f382(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(x, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LT_OS)), 0x1b); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f383(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LT_OS)), x, 0x1b); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f384(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(y, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LT_OS)), 0x1b); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f385(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), y)), y, 0x1b); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f386(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(x, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), y)), 0x1b); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f387(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), y)), x, 0x1b); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f388(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(y, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), y)), 0x1b); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f389(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LE_OS)), y, 0x1b); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f390(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(x, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LE_OS)), 0x1b); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f391(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LE_OS)), x, 0x1b); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f392(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(y, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LE_OS)), 0x1b); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f393(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LE_OS)), y, 0x1b); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f394(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(x, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LE_OS)), 0x1b); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f395(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LE_OS)), x, 0x1b); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f396(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(y, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LE_OS)), 0x1b); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f397(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), y)), y, 0x1b); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f398(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(x, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), y)), 0x1b); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f399(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), y)), x, 0x1b); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f400(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(y, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), y)), 0x1b); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f401(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_GT_OS)), y, 0x1b); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f402(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(x, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_GT_OS)), 0x1b); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f403(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_GT_OS)), x, 0x1b); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f404(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(y, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_GT_OS)), 0x1b); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f405(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_GT_OS)), y, 0x1b); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f406(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(x, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_GT_OS)), 0x1b); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f407(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_GT_OS)), x, 0x1b); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f408(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(y, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_GT_OS)), 0x1b); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f409(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), y)), y, 0x1b); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f410(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(x, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), y)), 0x1b); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f411(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), y)), x, 0x1b); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f412(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(y, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), y)), 0x1b); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f413(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_NLT_US)), y, 0x1b); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f414(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(x, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_NLT_US)), 0x1b); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f415(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_NLT_US)), x, 0x1b); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f416(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(y, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_NLT_US)), 0x1b); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f417(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_NLT_US)), y, 0x1b); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f418(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(x, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_NLT_US)), 0x1b); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f419(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_NLT_US)), x, 0x1b); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f420(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(y, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_NLT_US)), 0x1b); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f421(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), y)), y, 0x1b); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f422(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(x, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), y)), 0x1b); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f423(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), y)), x, 0x1b); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f424(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(y, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), y)), 0x1b); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f425(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_EQ_OQ)), y, 0x1b); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f426(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(x, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_EQ_OQ)), 0x1b); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f427(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_EQ_OQ)), x, 0x1b); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f428(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(y, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_EQ_OQ)), 0x1b); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f429(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_EQ_OQ)), y, 0x1b); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f430(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(x, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_EQ_OQ)), 0x1b); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f431(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_EQ_OQ)), x, 0x1b); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f432(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(y, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_EQ_OQ)), 0x1b); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f433(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), y)), y, 0x1b); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f434(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(x, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), y)), 0x1b); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f435(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), y)), x, 0x1b); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f436(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(y, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), y)), 0x1b); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f437(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_UNORD_Q)), y, 0x1b); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f438(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(x, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_UNORD_Q)), 0x1b); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f439(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_UNORD_Q)), x, 0x1b); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f440(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(y, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_UNORD_Q)), 0x1b); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f441(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_UNORD_Q)), y, 0x1b); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f442(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(x, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_UNORD_Q)), 0x1b); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f443(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_UNORD_Q)), x, 0x1b); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f444(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(y, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_UNORD_Q)), 0x1b); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f445(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), y)), y, 0x1b); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f446(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(x, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), y)), 0x1b); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f447(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), y)), x, 0x1b); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f448(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(y, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), y)), 0x1b); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f449(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_unpacklo_ps(x, y), y, 0x1b); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f450(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(x, _mm_unpacklo_ps(x, y), 0x1b); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f451(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_unpacklo_ps(x, y), x, 0x1b); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f452(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(y, _mm_unpacklo_ps(x, y), 0x1b); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f453(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_unpackhi_ps(x, y), y, 0x1b); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f454(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(x, _mm_unpackhi_ps(x, y), 0x1b); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f455(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_unpackhi_ps(x, y), x, 0x1b); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f456(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(y, _mm_unpackhi_ps(x, y), 0x1b); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f457(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_hadd_ps(x, y), y, 0x1b); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f458(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(x, _mm_hadd_ps(x, y), 0x1b); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f459(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_hadd_ps(x, y), x, 0x1b); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f460(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(y, _mm_hadd_ps(x, y), 0x1b); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f461(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_hsub_ps(x, y), y, 0x1b); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f462(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(x, _mm_hsub_ps(x, y), 0x1b); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f463(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_hsub_ps(x, y), x, 0x1b); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f464(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(y, _mm_hsub_ps(x, y), 0x1b); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f465(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_shuffle_ps(x, y, 0x1b), y, 0x1b); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f466(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(x, _mm_shuffle_ps(x, y, 0x1b), 0x1b); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f467(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_shuffle_ps(x, y, 0x1b), x, 0x1b); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f468(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(y, _mm_shuffle_ps(x, y, 0x1b), 0x1b); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f469(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_shuffle_ps(x, y, 0x39), y, 0x1b); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f470(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(x, _mm_shuffle_ps(x, y, 0x39), 0x1b); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f471(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_shuffle_ps(x, y, 0x39), x, 0x1b); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f472(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(y, _mm_shuffle_ps(x, y, 0x39), 0x1b); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f473(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_shuffle_ps(x, y, 0x93), y, 0x1b); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f474(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(x, _mm_shuffle_ps(x, y, 0x93), 0x1b); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f475(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_shuffle_ps(x, y, 0x93), x, 0x1b); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f476(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(y, _mm_shuffle_ps(x, y, 0x93), 0x1b); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f477(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_shuffle_ps(x, y, 0x4e), y, 0x1b); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f478(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(x, _mm_shuffle_ps(x, y, 0x4e), 0x1b); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f479(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_shuffle_ps(x, y, 0x4e), x, 0x1b); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f480(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(y, _mm_shuffle_ps(x, y, 0x4e), 0x1b); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f481(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_add_ps(x, y), y, 0x39); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f482(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(x, _mm_add_ps(x, y), 0x39); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f483(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_add_ps(x, y), x, 0x39); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f484(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(y, _mm_add_ps(x, y), 0x39); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f485(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_sub_ps(x, y), y, 0x39); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f486(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(x, _mm_sub_ps(x, y), 0x39); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f487(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_sub_ps(x, y), x, 0x39); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f488(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(y, _mm_sub_ps(x, y), 0x39); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f489(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_mul_ps(x, y), y, 0x39); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f490(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(x, _mm_mul_ps(x, y), 0x39); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f491(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_mul_ps(x, y), x, 0x39); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f492(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(y, _mm_mul_ps(x, y), 0x39); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f493(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_div_ps(x, y), y, 0x39); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f494(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(x, _mm_div_ps(x, y), 0x39); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f495(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_div_ps(x, y), x, 0x39); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f496(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(y, _mm_div_ps(x, y), 0x39); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f497(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_min_ps(x, y), y, 0x39); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f498(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(x, _mm_min_ps(x, y), 0x39); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f499(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_min_ps(x, y), x, 0x39); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f500(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(y, _mm_min_ps(x, y), 0x39); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f501(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_max_ps(x, y), y, 0x39); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f502(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(x, _mm_max_ps(x, y), 0x39); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f503(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_max_ps(x, y), x, 0x39); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f504(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(y, _mm_max_ps(x, y), 0x39); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f505(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_and_ps(x, y), y, 0x39); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f506(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(x, _mm_and_ps(x, y), 0x39); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f507(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_and_ps(x, y), x, 0x39); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f508(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(y, _mm_and_ps(x, y), 0x39); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f509(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_or_ps(x, y), y, 0x39); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f510(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(x, _mm_or_ps(x, y), 0x39); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f511(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_or_ps(x, y), x, 0x39); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f512(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(y, _mm_or_ps(x, y), 0x39); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f513(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_xor_ps(x, y), y, 0x39); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f514(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(x, _mm_xor_ps(x, y), 0x39); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f515(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_xor_ps(x, y), x, 0x39); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f516(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(y, _mm_xor_ps(x, y), 0x39); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f517(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_andnot_ps(x, y), y, 0x39); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f518(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(x, _mm_andnot_ps(x, y), 0x39); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f519(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_andnot_ps(x, y), x, 0x39); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f520(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(y, _mm_andnot_ps(x, y), 0x39); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f521(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), y, 0x39); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f522(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(x, _mm_cmp_ps(x, y, _CMP_EQ_OQ), 0x39); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f523(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), x, 0x39); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f524(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(y, _mm_cmp_ps(x, y, _CMP_EQ_OQ), 0x39); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f525(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), y, 0x39); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f526(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(x, _mm_cmp_ps(x, y, _CMP_LT_OS), 0x39); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f527(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), x, 0x39); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f528(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(y, _mm_cmp_ps(x, y, _CMP_LT_OS), 0x39); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f529(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), y, 0x39); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f530(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(x, _mm_cmp_ps(x, y, _CMP_LE_OS), 0x39); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f531(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), x, 0x39); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f532(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(y, _mm_cmp_ps(x, y, _CMP_LE_OS), 0x39); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f533(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_cmp_ps(x, y, _CMP_NEQ_UQ), y, 0x39); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f534(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(x, _mm_cmp_ps(x, y, _CMP_NEQ_UQ), 0x39); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f535(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_cmp_ps(x, y, _CMP_NEQ_UQ), x, 0x39); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f536(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(y, _mm_cmp_ps(x, y, _CMP_NEQ_UQ), 0x39); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f537(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), y, 0x39); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f538(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(x, _mm_cmp_ps(x, y, _CMP_UNORD_Q), 0x39); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f539(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), x, 0x39); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f540(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(y, _mm_cmp_ps(x, y, _CMP_UNORD_Q), 0x39); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f541(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), y, 0x39); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f542(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(x, _mm_cmp_ps(x, y, _CMP_NLT_US), 0x39); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f543(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), x, 0x39); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f544(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(y, _mm_cmp_ps(x, y, _CMP_NLT_US), 0x39); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f545(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), y, 0x39); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f546(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(x, _mm_cmp_ps(x, y, _CMP_GT_OS), 0x39); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f547(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), x, 0x39); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f548(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(y, _mm_cmp_ps(x, y, _CMP_GT_OS), 0x39); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f549(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LT_OS)), y, 0x39); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f550(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(x, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LT_OS)), 0x39); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f551(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LT_OS)), x, 0x39); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f552(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(y, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LT_OS)), 0x39); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f553(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LT_OS)), y, 0x39); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f554(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(x, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LT_OS)), 0x39); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f555(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LT_OS)), x, 0x39); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f556(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(y, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LT_OS)), 0x39); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f557(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), y)), y, 0x39); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f558(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(x, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), y)), 0x39); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f559(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), y)), x, 0x39); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f560(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(y, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), y)), 0x39); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f561(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LE_OS)), y, 0x39); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f562(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(x, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LE_OS)), 0x39); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f563(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LE_OS)), x, 0x39); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f564(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(y, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LE_OS)), 0x39); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f565(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LE_OS)), y, 0x39); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f566(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(x, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LE_OS)), 0x39); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f567(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LE_OS)), x, 0x39); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f568(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(y, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LE_OS)), 0x39); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f569(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), y)), y, 0x39); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f570(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(x, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), y)), 0x39); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f571(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), y)), x, 0x39); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f572(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(y, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), y)), 0x39); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f573(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_GT_OS)), y, 0x39); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f574(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(x, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_GT_OS)), 0x39); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f575(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_GT_OS)), x, 0x39); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f576(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(y, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_GT_OS)), 0x39); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f577(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_GT_OS)), y, 0x39); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f578(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(x, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_GT_OS)), 0x39); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f579(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_GT_OS)), x, 0x39); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f580(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(y, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_GT_OS)), 0x39); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f581(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), y)), y, 0x39); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f582(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(x, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), y)), 0x39); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f583(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), y)), x, 0x39); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f584(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(y, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), y)), 0x39); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f585(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_NLT_US)), y, 0x39); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f586(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(x, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_NLT_US)), 0x39); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f587(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_NLT_US)), x, 0x39); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f588(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(y, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_NLT_US)), 0x39); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f589(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_NLT_US)), y, 0x39); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f590(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(x, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_NLT_US)), 0x39); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f591(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_NLT_US)), x, 0x39); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f592(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(y, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_NLT_US)), 0x39); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f593(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), y)), y, 0x39); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f594(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(x, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), y)), 0x39); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f595(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), y)), x, 0x39); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f596(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(y, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), y)), 0x39); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f597(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_EQ_OQ)), y, 0x39); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f598(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(x, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_EQ_OQ)), 0x39); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f599(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_EQ_OQ)), x, 0x39); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f600(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(y, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_EQ_OQ)), 0x39); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f601(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_EQ_OQ)), y, 0x39); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f602(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(x, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_EQ_OQ)), 0x39); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f603(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_EQ_OQ)), x, 0x39); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f604(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(y, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_EQ_OQ)), 0x39); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f605(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), y)), y, 0x39); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f606(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(x, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), y)), 0x39); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f607(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), y)), x, 0x39); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f608(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(y, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), y)), 0x39); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f609(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_UNORD_Q)), y, 0x39); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f610(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(x, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_UNORD_Q)), 0x39); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f611(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_UNORD_Q)), x, 0x39); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f612(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(y, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_UNORD_Q)), 0x39); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f613(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_UNORD_Q)), y, 0x39); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f614(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(x, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_UNORD_Q)), 0x39); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f615(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_UNORD_Q)), x, 0x39); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f616(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(y, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_UNORD_Q)), 0x39); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f617(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), y)), y, 0x39); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f618(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(x, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), y)), 0x39); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f619(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), y)), x, 0x39); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f620(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(y, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), y)), 0x39); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f621(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_unpacklo_ps(x, y), y, 0x39); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f622(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(x, _mm_unpacklo_ps(x, y), 0x39); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f623(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_unpacklo_ps(x, y), x, 0x39); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f624(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(y, _mm_unpacklo_ps(x, y), 0x39); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f625(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_unpackhi_ps(x, y), y, 0x39); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f626(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(x, _mm_unpackhi_ps(x, y), 0x39); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f627(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_unpackhi_ps(x, y), x, 0x39); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f628(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(y, _mm_unpackhi_ps(x, y), 0x39); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f629(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_hadd_ps(x, y), y, 0x39); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f630(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(x, _mm_hadd_ps(x, y), 0x39); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f631(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_hadd_ps(x, y), x, 0x39); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f632(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(y, _mm_hadd_ps(x, y), 0x39); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f633(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_hsub_ps(x, y), y, 0x39); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f634(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(x, _mm_hsub_ps(x, y), 0x39); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f635(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_hsub_ps(x, y), x, 0x39); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f636(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(y, _mm_hsub_ps(x, y), 0x39); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f637(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_shuffle_ps(x, y, 0x1b), y, 0x39); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f638(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(x, _mm_shuffle_ps(x, y, 0x1b), 0x39); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f639(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_shuffle_ps(x, y, 0x1b), x, 0x39); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f640(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(y, _mm_shuffle_ps(x, y, 0x1b), 0x39); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f641(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_shuffle_ps(x, y, 0x39), y, 0x39); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f642(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(x, _mm_shuffle_ps(x, y, 0x39), 0x39); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f643(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_shuffle_ps(x, y, 0x39), x, 0x39); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f644(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(y, _mm_shuffle_ps(x, y, 0x39), 0x39); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f645(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_shuffle_ps(x, y, 0x93), y, 0x39); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f646(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(x, _mm_shuffle_ps(x, y, 0x93), 0x39); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f647(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_shuffle_ps(x, y, 0x93), x, 0x39); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f648(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(y, _mm_shuffle_ps(x, y, 0x93), 0x39); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f649(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_shuffle_ps(x, y, 0x4e), y, 0x39); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f650(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(x, _mm_shuffle_ps(x, y, 0x4e), 0x39); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f651(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_shuffle_ps(x, y, 0x4e), x, 0x39); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f652(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(y, _mm_shuffle_ps(x, y, 0x4e), 0x39); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f653(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_add_ps(x, y), y, 0x93); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f654(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(x, _mm_add_ps(x, y), 0x93); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f655(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_add_ps(x, y), x, 0x93); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f656(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(y, _mm_add_ps(x, y), 0x93); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f657(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_sub_ps(x, y), y, 0x93); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f658(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(x, _mm_sub_ps(x, y), 0x93); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f659(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_sub_ps(x, y), x, 0x93); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f660(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(y, _mm_sub_ps(x, y), 0x93); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f661(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_mul_ps(x, y), y, 0x93); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f662(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(x, _mm_mul_ps(x, y), 0x93); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f663(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_mul_ps(x, y), x, 0x93); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f664(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(y, _mm_mul_ps(x, y), 0x93); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f665(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_div_ps(x, y), y, 0x93); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f666(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(x, _mm_div_ps(x, y), 0x93); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f667(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_div_ps(x, y), x, 0x93); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f668(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(y, _mm_div_ps(x, y), 0x93); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f669(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_min_ps(x, y), y, 0x93); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f670(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(x, _mm_min_ps(x, y), 0x93); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f671(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_min_ps(x, y), x, 0x93); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f672(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(y, _mm_min_ps(x, y), 0x93); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f673(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_max_ps(x, y), y, 0x93); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f674(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(x, _mm_max_ps(x, y), 0x93); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f675(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_max_ps(x, y), x, 0x93); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f676(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(y, _mm_max_ps(x, y), 0x93); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f677(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_and_ps(x, y), y, 0x93); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f678(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(x, _mm_and_ps(x, y), 0x93); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f679(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_and_ps(x, y), x, 0x93); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f680(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(y, _mm_and_ps(x, y), 0x93); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f681(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_or_ps(x, y), y, 0x93); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f682(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(x, _mm_or_ps(x, y), 0x93); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f683(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_or_ps(x, y), x, 0x93); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f684(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(y, _mm_or_ps(x, y), 0x93); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f685(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_xor_ps(x, y), y, 0x93); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f686(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(x, _mm_xor_ps(x, y), 0x93); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f687(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_xor_ps(x, y), x, 0x93); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f688(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(y, _mm_xor_ps(x, y), 0x93); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f689(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_andnot_ps(x, y), y, 0x93); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f690(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(x, _mm_andnot_ps(x, y), 0x93); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f691(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_andnot_ps(x, y), x, 0x93); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f692(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(y, _mm_andnot_ps(x, y), 0x93); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f693(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), y, 0x93); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f694(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(x, _mm_cmp_ps(x, y, _CMP_EQ_OQ), 0x93); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f695(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), x, 0x93); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f696(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(y, _mm_cmp_ps(x, y, _CMP_EQ_OQ), 0x93); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f697(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), y, 0x93); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f698(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(x, _mm_cmp_ps(x, y, _CMP_LT_OS), 0x93); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f699(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), x, 0x93); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f700(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(y, _mm_cmp_ps(x, y, _CMP_LT_OS), 0x93); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f701(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), y, 0x93); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f702(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(x, _mm_cmp_ps(x, y, _CMP_LE_OS), 0x93); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f703(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), x, 0x93); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f704(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(y, _mm_cmp_ps(x, y, _CMP_LE_OS), 0x93); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f705(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_cmp_ps(x, y, _CMP_NEQ_UQ), y, 0x93); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f706(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(x, _mm_cmp_ps(x, y, _CMP_NEQ_UQ), 0x93); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f707(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_cmp_ps(x, y, _CMP_NEQ_UQ), x, 0x93); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f708(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(y, _mm_cmp_ps(x, y, _CMP_NEQ_UQ), 0x93); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f709(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), y, 0x93); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f710(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(x, _mm_cmp_ps(x, y, _CMP_UNORD_Q), 0x93); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f711(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), x, 0x93); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f712(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(y, _mm_cmp_ps(x, y, _CMP_UNORD_Q), 0x93); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f713(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), y, 0x93); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f714(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(x, _mm_cmp_ps(x, y, _CMP_NLT_US), 0x93); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f715(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), x, 0x93); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f716(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(y, _mm_cmp_ps(x, y, _CMP_NLT_US), 0x93); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f717(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), y, 0x93); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f718(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(x, _mm_cmp_ps(x, y, _CMP_GT_OS), 0x93); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f719(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), x, 0x93); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f720(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(y, _mm_cmp_ps(x, y, _CMP_GT_OS), 0x93); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f721(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LT_OS)), y, 0x93); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f722(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(x, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LT_OS)), 0x93); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f723(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LT_OS)), x, 0x93); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f724(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(y, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LT_OS)), 0x93); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f725(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LT_OS)), y, 0x93); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f726(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(x, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LT_OS)), 0x93); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f727(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LT_OS)), x, 0x93); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f728(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(y, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LT_OS)), 0x93); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f729(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), y)), y, 0x93); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f730(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(x, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), y)), 0x93); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f731(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), y)), x, 0x93); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f732(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(y, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), y)), 0x93); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f733(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LE_OS)), y, 0x93); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f734(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(x, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LE_OS)), 0x93); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f735(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LE_OS)), x, 0x93); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f736(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(y, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LE_OS)), 0x93); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f737(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LE_OS)), y, 0x93); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f738(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(x, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LE_OS)), 0x93); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f739(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LE_OS)), x, 0x93); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f740(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(y, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LE_OS)), 0x93); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f741(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), y)), y, 0x93); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f742(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(x, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), y)), 0x93); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f743(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), y)), x, 0x93); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f744(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(y, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), y)), 0x93); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f745(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_GT_OS)), y, 0x93); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f746(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(x, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_GT_OS)), 0x93); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f747(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_GT_OS)), x, 0x93); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f748(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(y, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_GT_OS)), 0x93); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f749(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_GT_OS)), y, 0x93); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f750(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(x, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_GT_OS)), 0x93); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f751(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_GT_OS)), x, 0x93); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f752(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(y, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_GT_OS)), 0x93); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f753(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), y)), y, 0x93); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f754(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(x, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), y)), 0x93); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f755(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), y)), x, 0x93); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f756(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(y, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), y)), 0x93); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f757(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_NLT_US)), y, 0x93); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f758(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(x, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_NLT_US)), 0x93); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f759(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_NLT_US)), x, 0x93); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f760(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(y, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_NLT_US)), 0x93); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f761(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_NLT_US)), y, 0x93); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f762(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(x, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_NLT_US)), 0x93); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f763(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_NLT_US)), x, 0x93); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f764(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(y, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_NLT_US)), 0x93); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f765(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), y)), y, 0x93); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f766(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(x, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), y)), 0x93); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f767(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), y)), x, 0x93); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f768(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(y, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), y)), 0x93); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f769(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_EQ_OQ)), y, 0x93); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f770(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(x, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_EQ_OQ)), 0x93); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f771(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_EQ_OQ)), x, 0x93); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f772(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(y, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_EQ_OQ)), 0x93); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f773(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_EQ_OQ)), y, 0x93); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f774(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(x, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_EQ_OQ)), 0x93); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f775(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_EQ_OQ)), x, 0x93); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f776(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(y, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_EQ_OQ)), 0x93); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f777(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), y)), y, 0x93); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f778(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(x, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), y)), 0x93); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f779(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), y)), x, 0x93); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f780(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(y, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), y)), 0x93); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f781(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_UNORD_Q)), y, 0x93); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f782(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(x, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_UNORD_Q)), 0x93); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f783(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_UNORD_Q)), x, 0x93); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f784(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(y, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_UNORD_Q)), 0x93); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f785(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_UNORD_Q)), y, 0x93); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f786(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(x, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_UNORD_Q)), 0x93); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f787(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_UNORD_Q)), x, 0x93); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f788(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(y, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_UNORD_Q)), 0x93); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f789(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), y)), y, 0x93); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f790(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(x, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), y)), 0x93); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f791(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), y)), x, 0x93); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f792(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(y, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), y)), 0x93); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f793(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_unpacklo_ps(x, y), y, 0x93); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f794(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(x, _mm_unpacklo_ps(x, y), 0x93); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f795(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_unpacklo_ps(x, y), x, 0x93); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f796(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(y, _mm_unpacklo_ps(x, y), 0x93); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f797(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_unpackhi_ps(x, y), y, 0x93); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f798(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(x, _mm_unpackhi_ps(x, y), 0x93); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f799(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_unpackhi_ps(x, y), x, 0x93); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f800(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(y, _mm_unpackhi_ps(x, y), 0x93); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f801(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_hadd_ps(x, y), y, 0x93); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f802(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(x, _mm_hadd_ps(x, y), 0x93); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f803(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_hadd_ps(x, y), x, 0x93); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f804(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(y, _mm_hadd_ps(x, y), 0x93); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f805(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_hsub_ps(x, y), y, 0x93); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f806(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(x, _mm_hsub_ps(x, y), 0x93); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f807(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_hsub_ps(x, y), x, 0x93); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f808(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(y, _mm_hsub_ps(x, y), 0x93); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f809(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_shuffle_ps(x, y, 0x1b), y, 0x93); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f810(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(x, _mm_shuffle_ps(x, y, 0x1b), 0x93); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f811(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_shuffle_ps(x, y, 0x1b), x, 0x93); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f812(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(y, _mm_shuffle_ps(x, y, 0x1b), 0x93); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f813(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_shuffle_ps(x, y, 0x39), y, 0x93); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f814(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(x, _mm_shuffle_ps(x, y, 0x39), 0x93); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f815(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_shuffle_ps(x, y, 0x39), x, 0x93); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f816(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(y, _mm_shuffle_ps(x, y, 0x39), 0x93); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f817(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_shuffle_ps(x, y, 0x93), y, 0x93); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f818(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(x, _mm_shuffle_ps(x, y, 0x93), 0x93); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f819(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_shuffle_ps(x, y, 0x93), x, 0x93); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f820(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(y, _mm_shuffle_ps(x, y, 0x93), 0x93); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f821(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_shuffle_ps(x, y, 0x4e), y, 0x93); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f822(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(x, _mm_shuffle_ps(x, y, 0x4e), 0x93); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f823(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_shuffle_ps(x, y, 0x4e), x, 0x93); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f824(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(y, _mm_shuffle_ps(x, y, 0x4e), 0x93); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f825(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_add_ps(x, y), y, 0x4e); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f826(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(x, _mm_add_ps(x, y), 0x4e); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f827(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_add_ps(x, y), x, 0x4e); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f828(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(y, _mm_add_ps(x, y), 0x4e); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f829(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_sub_ps(x, y), y, 0x4e); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f830(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(x, _mm_sub_ps(x, y), 0x4e); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f831(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_sub_ps(x, y), x, 0x4e); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f832(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(y, _mm_sub_ps(x, y), 0x4e); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f833(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_mul_ps(x, y), y, 0x4e); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f834(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(x, _mm_mul_ps(x, y), 0x4e); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f835(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_mul_ps(x, y), x, 0x4e); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f836(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(y, _mm_mul_ps(x, y), 0x4e); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f837(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_div_ps(x, y), y, 0x4e); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f838(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(x, _mm_div_ps(x, y), 0x4e); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f839(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_div_ps(x, y), x, 0x4e); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f840(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(y, _mm_div_ps(x, y), 0x4e); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f841(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_min_ps(x, y), y, 0x4e); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f842(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(x, _mm_min_ps(x, y), 0x4e); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f843(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_min_ps(x, y), x, 0x4e); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f844(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(y, _mm_min_ps(x, y), 0x4e); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f845(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_max_ps(x, y), y, 0x4e); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f846(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(x, _mm_max_ps(x, y), 0x4e); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f847(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_max_ps(x, y), x, 0x4e); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f848(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(y, _mm_max_ps(x, y), 0x4e); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f849(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_and_ps(x, y), y, 0x4e); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f850(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(x, _mm_and_ps(x, y), 0x4e); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f851(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_and_ps(x, y), x, 0x4e); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f852(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(y, _mm_and_ps(x, y), 0x4e); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f853(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_or_ps(x, y), y, 0x4e); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f854(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(x, _mm_or_ps(x, y), 0x4e); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f855(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_or_ps(x, y), x, 0x4e); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f856(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(y, _mm_or_ps(x, y), 0x4e); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f857(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_xor_ps(x, y), y, 0x4e); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f858(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(x, _mm_xor_ps(x, y), 0x4e); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f859(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_xor_ps(x, y), x, 0x4e); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f860(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(y, _mm_xor_ps(x, y), 0x4e); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f861(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_andnot_ps(x, y), y, 0x4e); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f862(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(x, _mm_andnot_ps(x, y), 0x4e); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f863(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_andnot_ps(x, y), x, 0x4e); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f864(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(y, _mm_andnot_ps(x, y), 0x4e); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f865(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), y, 0x4e); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f866(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(x, _mm_cmp_ps(x, y, _CMP_EQ_OQ), 0x4e); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f867(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), x, 0x4e); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f868(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(y, _mm_cmp_ps(x, y, _CMP_EQ_OQ), 0x4e); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f869(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), y, 0x4e); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f870(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(x, _mm_cmp_ps(x, y, _CMP_LT_OS), 0x4e); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f871(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), x, 0x4e); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f872(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(y, _mm_cmp_ps(x, y, _CMP_LT_OS), 0x4e); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f873(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), y, 0x4e); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f874(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(x, _mm_cmp_ps(x, y, _CMP_LE_OS), 0x4e); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f875(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), x, 0x4e); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f876(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(y, _mm_cmp_ps(x, y, _CMP_LE_OS), 0x4e); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f877(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_cmp_ps(x, y, _CMP_NEQ_UQ), y, 0x4e); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f878(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(x, _mm_cmp_ps(x, y, _CMP_NEQ_UQ), 0x4e); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f879(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_cmp_ps(x, y, _CMP_NEQ_UQ), x, 0x4e); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f880(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(y, _mm_cmp_ps(x, y, _CMP_NEQ_UQ), 0x4e); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f881(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), y, 0x4e); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f882(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(x, _mm_cmp_ps(x, y, _CMP_UNORD_Q), 0x4e); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f883(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), x, 0x4e); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f884(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(y, _mm_cmp_ps(x, y, _CMP_UNORD_Q), 0x4e); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f885(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), y, 0x4e); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f886(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(x, _mm_cmp_ps(x, y, _CMP_NLT_US), 0x4e); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f887(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), x, 0x4e); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f888(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(y, _mm_cmp_ps(x, y, _CMP_NLT_US), 0x4e); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f889(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), y, 0x4e); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f890(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(x, _mm_cmp_ps(x, y, _CMP_GT_OS), 0x4e); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f891(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), x, 0x4e); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f892(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(y, _mm_cmp_ps(x, y, _CMP_GT_OS), 0x4e); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f893(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LT_OS)), y, 0x4e); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f894(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(x, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LT_OS)), 0x4e); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f895(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LT_OS)), x, 0x4e); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f896(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(y, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LT_OS)), 0x4e); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f897(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LT_OS)), y, 0x4e); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f898(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(x, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LT_OS)), 0x4e); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f899(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LT_OS)), x, 0x4e); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f900(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(y, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LT_OS)), 0x4e); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f901(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), y)), y, 0x4e); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f902(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(x, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), y)), 0x4e); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f903(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), y)), x, 0x4e); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f904(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(y, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), y)), 0x4e); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f905(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LE_OS)), y, 0x4e); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f906(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(x, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LE_OS)), 0x4e); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f907(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LE_OS)), x, 0x4e); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f908(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(y, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LE_OS)), 0x4e); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f909(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LE_OS)), y, 0x4e); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f910(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(x, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LE_OS)), 0x4e); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f911(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LE_OS)), x, 0x4e); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f912(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(y, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LE_OS)), 0x4e); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f913(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), y)), y, 0x4e); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f914(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(x, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), y)), 0x4e); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f915(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), y)), x, 0x4e); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f916(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(y, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), y)), 0x4e); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f917(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_GT_OS)), y, 0x4e); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f918(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(x, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_GT_OS)), 0x4e); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f919(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_GT_OS)), x, 0x4e); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f920(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(y, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_GT_OS)), 0x4e); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f921(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_GT_OS)), y, 0x4e); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f922(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(x, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_GT_OS)), 0x4e); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f923(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_GT_OS)), x, 0x4e); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f924(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(y, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_GT_OS)), 0x4e); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f925(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), y)), y, 0x4e); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f926(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(x, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), y)), 0x4e); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f927(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), y)), x, 0x4e); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f928(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(y, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), y)), 0x4e); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f929(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_NLT_US)), y, 0x4e); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f930(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(x, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_NLT_US)), 0x4e); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f931(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_NLT_US)), x, 0x4e); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f932(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(y, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_NLT_US)), 0x4e); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f933(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_NLT_US)), y, 0x4e); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f934(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(x, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_NLT_US)), 0x4e); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f935(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_NLT_US)), x, 0x4e); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f936(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(y, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_NLT_US)), 0x4e); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f937(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), y)), y, 0x4e); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f938(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(x, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), y)), 0x4e); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f939(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), y)), x, 0x4e); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f940(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(y, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), y)), 0x4e); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f941(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_EQ_OQ)), y, 0x4e); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f942(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(x, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_EQ_OQ)), 0x4e); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f943(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_EQ_OQ)), x, 0x4e); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f944(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(y, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_EQ_OQ)), 0x4e); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f945(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_EQ_OQ)), y, 0x4e); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f946(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(x, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_EQ_OQ)), 0x4e); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f947(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_EQ_OQ)), x, 0x4e); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f948(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(y, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_EQ_OQ)), 0x4e); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f949(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), y)), y, 0x4e); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f950(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(x, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), y)), 0x4e); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f951(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), y)), x, 0x4e); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f952(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(y, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), y)), 0x4e); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f953(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_UNORD_Q)), y, 0x4e); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f954(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(x, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_UNORD_Q)), 0x4e); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f955(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_UNORD_Q)), x, 0x4e); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f956(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(y, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_UNORD_Q)), 0x4e); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f957(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_UNORD_Q)), y, 0x4e); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f958(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(x, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_UNORD_Q)), 0x4e); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f959(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_UNORD_Q)), x, 0x4e); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f960(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(y, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_UNORD_Q)), 0x4e); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f961(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), y)), y, 0x4e); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f962(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(x, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), y)), 0x4e); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f963(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), y)), x, 0x4e); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f964(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(y, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), y)), 0x4e); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f965(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_unpacklo_ps(x, y), y, 0x4e); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f966(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(x, _mm_unpacklo_ps(x, y), 0x4e); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f967(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_unpacklo_ps(x, y), x, 0x4e); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f968(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(y, _mm_unpacklo_ps(x, y), 0x4e); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f969(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_unpackhi_ps(x, y), y, 0x4e); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f970(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(x, _mm_unpackhi_ps(x, y), 0x4e); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f971(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_unpackhi_ps(x, y), x, 0x4e); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f972(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(y, _mm_unpackhi_ps(x, y), 0x4e); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f973(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_hadd_ps(x, y), y, 0x4e); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f974(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(x, _mm_hadd_ps(x, y), 0x4e); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f975(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_hadd_ps(x, y), x, 0x4e); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f976(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(y, _mm_hadd_ps(x, y), 0x4e); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f977(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_hsub_ps(x, y), y, 0x4e); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f978(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(x, _mm_hsub_ps(x, y), 0x4e); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f979(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_hsub_ps(x, y), x, 0x4e); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f980(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(y, _mm_hsub_ps(x, y), 0x4e); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f981(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_shuffle_ps(x, y, 0x1b), y, 0x4e); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f982(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(x, _mm_shuffle_ps(x, y, 0x1b), 0x4e); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f983(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_shuffle_ps(x, y, 0x1b), x, 0x4e); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f984(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(y, _mm_shuffle_ps(x, y, 0x1b), 0x4e); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f985(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_shuffle_ps(x, y, 0x39), y, 0x4e); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f986(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(x, _mm_shuffle_ps(x, y, 0x39), 0x4e); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f987(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_shuffle_ps(x, y, 0x39), x, 0x4e); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f988(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(y, _mm_shuffle_ps(x, y, 0x39), 0x4e); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f989(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_shuffle_ps(x, y, 0x93), y, 0x4e); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f990(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(x, _mm_shuffle_ps(x, y, 0x93), 0x4e); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f991(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_shuffle_ps(x, y, 0x93), x, 0x4e); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f992(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(y, _mm_shuffle_ps(x, y, 0x93), 0x4e); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f993(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_shuffle_ps(x, y, 0x4e), y, 0x4e); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f994(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(x, _mm_shuffle_ps(x, y, 0x4e), 0x4e); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f995(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_shuffle_ps(x, y, 0x4e), x, 0x4e); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f996(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(y, _mm_shuffle_ps(x, y, 0x4e), 0x4e); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f997(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sqrt_pd(_mm_sqrt_pd(x)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f998(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sqrt_pd(_mm_xor_pd(x, _mm_set1_pd(-0.0))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f999(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sqrt_pd(_mm_andnot_pd(_mm_set1_pd(-0.0), x)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1000(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sqrt_pd(_mm_sub_pd(_mm_setzero_pd(), x)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1001(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sqrt_pd(_mm_mul_pd(x, _mm_set1_pd(-1.0))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1002(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sqrt_pd(_mm_floor_pd(x)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1003(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sqrt_pd(_mm_ceil_pd(x)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1004(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sqrt_pd(_mm_round_pd(x, _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1005(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sqrt_pd(_mm_permute_pd(x, 0x5)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1006(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sqrt_pd(_mm_permute_pd(x, 0xa)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1007(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sqrt_pd(_mm_permute_pd(x, 0x3)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1008(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(_mm_sqrt_pd(x), _mm_set1_pd(-0.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1009(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(_mm_xor_pd(x, _mm_set1_pd(-0.0)), _mm_set1_pd(-0.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1010(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(_mm_andnot_pd(_mm_set1_pd(-0.0), x), _mm_set1_pd(-0.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1011(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(_mm_sub_pd(_mm_setzero_pd(), x), _mm_set1_pd(-0.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1012(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(_mm_mul_pd(x, _mm_set1_pd(-1.0)), _mm_set1_pd(-0.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1013(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(_mm_floor_pd(x), _mm_set1_pd(-0.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1014(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(_mm_ceil_pd(x), _mm_set1_pd(-0.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1015(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(_mm_round_pd(x, _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC), _mm_set1_pd(-0.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1016(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(_mm_permute_pd(x, 0x5), _mm_set1_pd(-0.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1017(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(_mm_permute_pd(x, 0xa), _mm_set1_pd(-0.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1018(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(_mm_permute_pd(x, 0x3), _mm_set1_pd(-0.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1019(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(_mm_set1_pd(-0.0), _mm_sqrt_pd(x)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1020(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(_mm_set1_pd(-0.0), _mm_xor_pd(x, _mm_set1_pd(-0.0))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1021(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(_mm_set1_pd(-0.0), _mm_andnot_pd(_mm_set1_pd(-0.0), x)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1022(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(_mm_set1_pd(-0.0), _mm_sub_pd(_mm_setzero_pd(), x)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1023(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(_mm_set1_pd(-0.0), _mm_mul_pd(x, _mm_set1_pd(-1.0))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1024(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(_mm_set1_pd(-0.0), _mm_floor_pd(x)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1025(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(_mm_set1_pd(-0.0), _mm_ceil_pd(x)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1026(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(_mm_set1_pd(-0.0), _mm_round_pd(x, _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1027(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(_mm_set1_pd(-0.0), _mm_permute_pd(x, 0x5)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1028(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(_mm_set1_pd(-0.0), _mm_permute_pd(x, 0xa)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1029(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(_mm_set1_pd(-0.0), _mm_permute_pd(x, 0x3)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1030(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sub_pd(_mm_setzero_pd(), _mm_sqrt_pd(x)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1031(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sub_pd(_mm_setzero_pd(), _mm_xor_pd(x, _mm_set1_pd(-0.0))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1032(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sub_pd(_mm_setzero_pd(), _mm_andnot_pd(_mm_set1_pd(-0.0), x)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1033(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sub_pd(_mm_setzero_pd(), _mm_sub_pd(_mm_setzero_pd(), x)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1034(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sub_pd(_mm_setzero_pd(), _mm_mul_pd(x, _mm_set1_pd(-1.0))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1035(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sub_pd(_mm_setzero_pd(), _mm_floor_pd(x)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1036(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sub_pd(_mm_setzero_pd(), _mm_ceil_pd(x)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1037(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sub_pd(_mm_setzero_pd(), _mm_round_pd(x, _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1038(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sub_pd(_mm_setzero_pd(), _mm_permute_pd(x, 0x5)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1039(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sub_pd(_mm_setzero_pd(), _mm_permute_pd(x, 0xa)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1040(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sub_pd(_mm_setzero_pd(), _mm_permute_pd(x, 0x3)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1041(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_mul_pd(_mm_sqrt_pd(x), _mm_set1_pd(-1.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1042(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_mul_pd(_mm_xor_pd(x, _mm_set1_pd(-0.0)), _mm_set1_pd(-1.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1043(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_mul_pd(_mm_andnot_pd(_mm_set1_pd(-0.0), x), _mm_set1_pd(-1.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1044(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_mul_pd(_mm_sub_pd(_mm_setzero_pd(), x), _mm_set1_pd(-1.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1045(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_mul_pd(_mm_mul_pd(x, _mm_set1_pd(-1.0)), _mm_set1_pd(-1.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1046(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_mul_pd(_mm_floor_pd(x), _mm_set1_pd(-1.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1047(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_mul_pd(_mm_ceil_pd(x), _mm_set1_pd(-1.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1048(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_mul_pd(_mm_round_pd(x, _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC), _mm_set1_pd(-1.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1049(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_mul_pd(_mm_permute_pd(x, 0x5), _mm_set1_pd(-1.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1050(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_mul_pd(_mm_permute_pd(x, 0xa), _mm_set1_pd(-1.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1051(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_mul_pd(_mm_permute_pd(x, 0x3), _mm_set1_pd(-1.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1052(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_floor_pd(_mm_sqrt_pd(x)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1053(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_floor_pd(_mm_xor_pd(x, _mm_set1_pd(-0.0))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1054(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_floor_pd(_mm_andnot_pd(_mm_set1_pd(-0.0), x)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1055(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_floor_pd(_mm_sub_pd(_mm_setzero_pd(), x)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1056(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_floor_pd(_mm_mul_pd(x, _mm_set1_pd(-1.0))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1057(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_floor_pd(_mm_floor_pd(x)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1058(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_floor_pd(_mm_ceil_pd(x)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1059(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_floor_pd(_mm_round_pd(x, _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1060(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_floor_pd(_mm_permute_pd(x, 0x5)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1061(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_floor_pd(_mm_permute_pd(x, 0xa)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1062(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_floor_pd(_mm_permute_pd(x, 0x3)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1063(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_ceil_pd(_mm_sqrt_pd(x)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1064(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_ceil_pd(_mm_xor_pd(x, _mm_set1_pd(-0.0))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1065(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_ceil_pd(_mm_andnot_pd(_mm_set1_pd(-0.0), x)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1066(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_ceil_pd(_mm_sub_pd(_mm_setzero_pd(), x)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1067(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_ceil_pd(_mm_mul_pd(x, _mm_set1_pd(-1.0))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1068(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_ceil_pd(_mm_floor_pd(x)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1069(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_ceil_pd(_mm_ceil_pd(x)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1070(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_ceil_pd(_mm_round_pd(x, _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1071(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_ceil_pd(_mm_permute_pd(x, 0x5)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1072(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_ceil_pd(_mm_permute_pd(x, 0xa)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1073(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_ceil_pd(_mm_permute_pd(x, 0x3)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1074(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_round_pd(_mm_sqrt_pd(x), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1075(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_round_pd(_mm_xor_pd(x, _mm_set1_pd(-0.0)), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1076(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_round_pd(_mm_andnot_pd(_mm_set1_pd(-0.0), x), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1077(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_round_pd(_mm_sub_pd(_mm_setzero_pd(), x), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1078(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_round_pd(_mm_mul_pd(x, _mm_set1_pd(-1.0)), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1079(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_round_pd(_mm_floor_pd(x), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1080(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_round_pd(_mm_ceil_pd(x), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1081(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_round_pd(_mm_round_pd(x, _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1082(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_round_pd(_mm_permute_pd(x, 0x5), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1083(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_round_pd(_mm_permute_pd(x, 0xa), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1084(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_round_pd(_mm_permute_pd(x, 0x3), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1085(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_sqrt_pd(x), 0x5); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1086(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_xor_pd(x, _mm_set1_pd(-0.0)), 0x5); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1087(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_andnot_pd(_mm_set1_pd(-0.0), x), 0x5); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1088(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_sub_pd(_mm_setzero_pd(), x), 0x5); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1089(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_mul_pd(x, _mm_set1_pd(-1.0)), 0x5); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1090(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_floor_pd(x), 0x5); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1091(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_ceil_pd(x), 0x5); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1092(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_round_pd(x, _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC), 0x5); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1093(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_permute_pd(x, 0x5), 0x5); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1094(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_permute_pd(x, 0xa), 0x5); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1095(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_permute_pd(x, 0x3), 0x5); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1096(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_sqrt_pd(x), 0xa); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1097(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_xor_pd(x, _mm_set1_pd(-0.0)), 0xa); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1098(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_andnot_pd(_mm_set1_pd(-0.0), x), 0xa); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1099(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_sub_pd(_mm_setzero_pd(), x), 0xa); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1100(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_mul_pd(x, _mm_set1_pd(-1.0)), 0xa); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1101(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_floor_pd(x), 0xa); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1102(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_ceil_pd(x), 0xa); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1103(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_round_pd(x, _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC), 0xa); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1104(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_permute_pd(x, 0x5), 0xa); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1105(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_permute_pd(x, 0xa), 0xa); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1106(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_permute_pd(x, 0x3), 0xa); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1107(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_sqrt_pd(x), 0x3); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1108(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_xor_pd(x, _mm_set1_pd(-0.0)), 0x3); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1109(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_andnot_pd(_mm_set1_pd(-0.0), x), 0x3); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1110(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_sub_pd(_mm_setzero_pd(), x), 0x3); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1111(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_mul_pd(x, _mm_set1_pd(-1.0)), 0x3); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1112(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_floor_pd(x), 0x3); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1113(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_ceil_pd(x), 0x3); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1114(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_round_pd(x, _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC), 0x3); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1115(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_permute_pd(x, 0x5), 0x3); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1116(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_permute_pd(x, 0xa), 0x3); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1117(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_permute_pd(x, 0x3), 0x3); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1118(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sqrt_pd(_mm_sqrt_pd(_mm_sqrt_pd(x))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1119(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(_mm_xor_pd(_mm_xor_pd(x, _mm_set1_pd(-0.0)), _mm_set1_pd(-0.0)), _mm_set1_pd(-0.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1120(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(_mm_set1_pd(-0.0), _mm_andnot_pd(_mm_set1_pd(-0.0), _mm_andnot_pd(_mm_set1_pd(-0.0), x))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1121(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sub_pd(_mm_setzero_pd(), _mm_sub_pd(_mm_setzero_pd(), _mm_sub_pd(_mm_setzero_pd(), x))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1122(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_mul_pd(_mm_mul_pd(_mm_mul_pd(x, _mm_set1_pd(-1.0)), _mm_set1_pd(-1.0)), _mm_set1_pd(-1.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1123(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_floor_pd(_mm_floor_pd(_mm_floor_pd(x))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1124(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_ceil_pd(_mm_ceil_pd(_mm_ceil_pd(x))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1125(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_round_pd(_mm_round_pd(_mm_round_pd(x, _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1126(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_permute_pd(_mm_permute_pd(x, 0x5), 0x5), 0x5); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1127(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_permute_pd(_mm_permute_pd(x, 0xa), 0xa), 0xa); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1128(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_permute_pd(_mm_permute_pd(x, 0x3), 0x3), 0x3); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1129(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sqrt_pd(_mm_add_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1130(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_add_pd(_mm_sqrt_pd(x), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1131(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_add_pd(x, _mm_sqrt_pd(y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1132(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_add_pd(_mm_sqrt_pd(x), _mm_sqrt_pd(y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1133(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_add_pd(x, _mm_sqrt_pd(x)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1134(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_add_pd(_mm_sqrt_pd(x), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1135(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sqrt_pd(_mm_sub_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1136(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sub_pd(_mm_sqrt_pd(x), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1137(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sub_pd(x, _mm_sqrt_pd(y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1138(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sub_pd(_mm_sqrt_pd(x), _mm_sqrt_pd(y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1139(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sub_pd(x, _mm_sqrt_pd(x)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1140(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sub_pd(_mm_sqrt_pd(x), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1141(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sqrt_pd(_mm_mul_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1142(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_mul_pd(_mm_sqrt_pd(x), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1143(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_mul_pd(x, _mm_sqrt_pd(y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1144(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_mul_pd(_mm_sqrt_pd(x), _mm_sqrt_pd(y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1145(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_mul_pd(x, _mm_sqrt_pd(x)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1146(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_mul_pd(_mm_sqrt_pd(x), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1147(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sqrt_pd(_mm_div_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1148(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_div_pd(_mm_sqrt_pd(x), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1149(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_div_pd(x, _mm_sqrt_pd(y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1150(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_div_pd(_mm_sqrt_pd(x), _mm_sqrt_pd(y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1151(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_div_pd(x, _mm_sqrt_pd(x)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1152(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_div_pd(_mm_sqrt_pd(x), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1153(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sqrt_pd(_mm_min_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1154(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_min_pd(_mm_sqrt_pd(x), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1155(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_min_pd(x, _mm_sqrt_pd(y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1156(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_min_pd(_mm_sqrt_pd(x), _mm_sqrt_pd(y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1157(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_min_pd(x, _mm_sqrt_pd(x)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1158(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_min_pd(_mm_sqrt_pd(x), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1159(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sqrt_pd(_mm_max_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1160(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_max_pd(_mm_sqrt_pd(x), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1161(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_max_pd(x, _mm_sqrt_pd(y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1162(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_max_pd(_mm_sqrt_pd(x), _mm_sqrt_pd(y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1163(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_max_pd(x, _mm_sqrt_pd(x)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1164(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_max_pd(_mm_sqrt_pd(x), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1165(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sqrt_pd(_mm_and_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1166(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_and_pd(_mm_sqrt_pd(x), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1167(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_and_pd(x, _mm_sqrt_pd(y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1168(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_and_pd(_mm_sqrt_pd(x), _mm_sqrt_pd(y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1169(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_and_pd(x, _mm_sqrt_pd(x)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1170(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_and_pd(_mm_sqrt_pd(x), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1171(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sqrt_pd(_mm_or_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1172(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_or_pd(_mm_sqrt_pd(x), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1173(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_or_pd(x, _mm_sqrt_pd(y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1174(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_or_pd(_mm_sqrt_pd(x), _mm_sqrt_pd(y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1175(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_or_pd(x, _mm_sqrt_pd(x)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1176(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_or_pd(_mm_sqrt_pd(x), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1177(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sqrt_pd(_mm_xor_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1178(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(_mm_sqrt_pd(x), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1179(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(x, _mm_sqrt_pd(y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1180(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(_mm_sqrt_pd(x), _mm_sqrt_pd(y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1181(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(x, _mm_sqrt_pd(x)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1182(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(_mm_sqrt_pd(x), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1183(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sqrt_pd(_mm_andnot_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1184(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(_mm_sqrt_pd(x), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1185(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(x, _mm_sqrt_pd(y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1186(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(_mm_sqrt_pd(x), _mm_sqrt_pd(y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1187(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(x, _mm_sqrt_pd(x)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1188(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(_mm_sqrt_pd(x), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1189(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sqrt_pd(_mm_cmp_pd(x, y, _CMP_EQ_OQ)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1190(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_cmp_pd(_mm_sqrt_pd(x), y, _CMP_EQ_OQ); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1191(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_cmp_pd(x, _mm_sqrt_pd(y), _CMP_EQ_OQ); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1192(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_cmp_pd(_mm_sqrt_pd(x), _mm_sqrt_pd(y), _CMP_EQ_OQ); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1193(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_cmp_pd(x, _mm_sqrt_pd(x), _CMP_EQ_OQ); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1194(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_cmp_pd(_mm_sqrt_pd(x), x, _CMP_EQ_OQ); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1195(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sqrt_pd(_mm_cmp_pd(x, y, _CMP_LT_OS)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1196(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_cmp_pd(_mm_sqrt_pd(x), y, _CMP_LT_OS); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1197(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_cmp_pd(x, _mm_sqrt_pd(y), _CMP_LT_OS); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1198(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_cmp_pd(_mm_sqrt_pd(x), _mm_sqrt_pd(y), _CMP_LT_OS); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1199(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_cmp_pd(x, _mm_sqrt_pd(x), _CMP_LT_OS); _mm_storeu_pd((double*)po, r); }
extern const Entry table_31[] = {
  {"128:_mm_hadd_ps(y, _mm_xor_ps(x, y))", f0, 1, 128},
  {"128:_mm_hadd_ps(_mm_andnot_ps(x, y), y)", f1, 1, 128},
  {"128:_mm_hadd_ps(x, _mm_andnot_ps(x, y))", f2, 1, 128},
  {"128:_mm_hadd_ps(_mm_andnot_ps(x, y), x)", f3, 1, 128},
  {"128:_mm_hadd_ps(y, _mm_andnot_ps(x, y))", f4, 1, 128},
  {"128:_mm_hadd_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), y)", f5, 1, 128},
  {"128:_mm_hadd_ps(x, _mm_cmp_ps(x, y, _CMP_EQ_OQ))", f6, 1, 128},
  {"128:_mm_hadd_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), x)", f7, 1, 128},
  {"128:_mm_hadd_ps(y, _mm_cmp_ps(x, y, _CMP_EQ_OQ))", f8, 1, 128},
  {"128:_mm_hadd_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), y)", f9, 1, 128},
  {"128:_mm_hadd_ps(x, _mm_cmp_ps(x, y, _CMP_LT_OS))", f10, 1, 128},
  {"128:_mm_hadd_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), x)", f11, 1, 128},
  {"128:_mm_hadd_ps(y, _mm_cmp_ps(x, y, _CMP_LT_OS))", f12, 1, 128},
  {"128:_mm_hadd_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), y)", f13, 1, 128},
  {"128:_mm_hadd_ps(x, _mm_cmp_ps(x, y, _CMP_LE_OS))", f14, 1, 128},
  {"128:_mm_hadd_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), x)", f15, 1, 128},
  {"128:_mm_hadd_ps(y, _mm_cmp_ps(x, y, _CMP_LE_OS))", f16, 1, 128},
  {"128:_mm_hadd_ps(_mm_cmp_ps(x, y, _CMP_NEQ_UQ), y)", f17, 1, 128},
  {"128:_mm_hadd_ps(x, _mm_cmp_ps(x, y, _CMP_NEQ_UQ))", f18, 1, 128},
  {"128:_mm_hadd_ps(_mm_cmp_ps(x, y, _CMP_NEQ_UQ), x)", f19, 1, 128},
  {"128:_mm_hadd_ps(y, _mm_cmp_ps(x, y, _CMP_NEQ_UQ))", f20, 1, 128},
  {"128:_mm_hadd_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), y)", f21, 1, 128},
  {"128:_mm_hadd_ps(x, _mm_cmp_ps(x, y, _CMP_UNORD_Q))", f22, 1, 128},
  {"128:_mm_hadd_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), x)", f23, 1, 128},
  {"128:_mm_hadd_ps(y, _mm_cmp_ps(x, y, _CMP_UNORD_Q))", f24, 1, 128},
  {"128:_mm_hadd_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), y)", f25, 1, 128},
  {"128:_mm_hadd_ps(x, _mm_cmp_ps(x, y, _CMP_NLT_US))", f26, 1, 128},
  {"128:_mm_hadd_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), x)", f27, 1, 128},
  {"128:_mm_hadd_ps(y, _mm_cmp_ps(x, y, _CMP_NLT_US))", f28, 1, 128},
  {"128:_mm_hadd_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), y)", f29, 1, 128},
  {"128:_mm_hadd_ps(x, _mm_cmp_ps(x, y, _CMP_GT_OS))", f30, 1, 128},
  {"128:_mm_hadd_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), x)", f31, 1, 128},
  {"128:_mm_hadd_ps(y, _mm_cmp_ps(x, y, _CMP_GT_OS))", f32, 1, 128},
  {"128:_mm_hadd_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LT_OS)), y)", f33, 1, 128},
  {"128:_mm_hadd_ps(x, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LT_OS)))", f34, 1, 128},
  {"128:_mm_hadd_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LT_OS)), x)", f35, 1, 128},
  {"128:_mm_hadd_ps(y, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LT_OS)))", f36, 1, 128},
  {"128:_mm_hadd_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LT_OS)), y)", f37, 1, 128},
  {"128:_mm_hadd_ps(x, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LT_OS)))", f38, 1, 128},
  {"128:_mm_hadd_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LT_OS)), x)", f39, 1, 128},
  {"128:_mm_hadd_ps(y, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LT_OS)))", f40, 1, 128},
  {"128:_mm_hadd_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), y)), y)", f41, 1, 128},
  {"128:_mm_hadd_ps(x, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), y)))", f42, 1, 128},
  {"128:_mm_hadd_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), y)), x)", f43, 1, 128},
  {"128:_mm_hadd_ps(y, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), y)))", f44, 1, 128},
  {"128:_mm_hadd_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LE_OS)), y)", f45, 1, 128},
  {"128:_mm_hadd_ps(x, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LE_OS)))", f46, 1, 128},
  {"128:_mm_hadd_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LE_OS)), x)", f47, 1, 128},
  {"128:_mm_hadd_ps(y, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LE_OS)))", f48, 1, 128},
  {"128:_mm_hadd_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LE_OS)), y)", f49, 1, 128},
  {"128:_mm_hadd_ps(x, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LE_OS)))", f50, 1, 128},
  {"128:_mm_hadd_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LE_OS)), x)", f51, 1, 128},
  {"128:_mm_hadd_ps(y, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LE_OS)))", f52, 1, 128},
  {"128:_mm_hadd_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), y)), y)", f53, 1, 128},
  {"128:_mm_hadd_ps(x, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), y)))", f54, 1, 128},
  {"128:_mm_hadd_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), y)), x)", f55, 1, 128},
  {"128:_mm_hadd_ps(y, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), y)))", f56, 1, 128},
  {"128:_mm_hadd_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_GT_OS)), y)", f57, 1, 128},
  {"128:_mm_hadd_ps(x, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_GT_OS)))", f58, 1, 128},
  {"128:_mm_hadd_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_GT_OS)), x)", f59, 1, 128},
  {"128:_mm_hadd_ps(y, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_GT_OS)))", f60, 1, 128},
  {"128:_mm_hadd_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_GT_OS)), y)", f61, 1, 128},
  {"128:_mm_hadd_ps(x, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_GT_OS)))", f62, 1, 128},
  {"128:_mm_hadd_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_GT_OS)), x)", f63, 1, 128},
  {"128:_mm_hadd_ps(y, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_GT_OS)))", f64, 1, 128},
  {"128:_mm_hadd_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), y)), y)", f65, 1, 128},
  {"128:_mm_hadd_ps(x, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), y)))", f66, 1, 128},
  {"128:_mm_hadd_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), y)), x)", f67, 1, 128},
  {"128:_mm_hadd_ps(y, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), y)))", f68, 1, 128},
  {"128:_mm_hadd_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_NLT_US)), y)", f69, 1, 128},
  {"128:_mm_hadd_ps(x, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_NLT_US)))", f70, 1, 128},
  {"128:_mm_hadd_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_NLT_US)), x)", f71, 1, 128},
  {"128:_mm_hadd_ps(y, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_NLT_US)))", f72, 1, 128},
  {"128:_mm_hadd_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_NLT_US)), y)", f73, 1, 128},
  {"128:_mm_hadd_ps(x, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_NLT_US)))", f74, 1, 128},
  {"128:_mm_hadd_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_NLT_US)), x)", f75, 1, 128},
  {"128:_mm_hadd_ps(y, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_NLT_US)))", f76, 1, 128},
  {"128:_mm_hadd_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), y)), y)", f77, 1, 128},
  {"128:_mm_hadd_ps(x, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), y)))", f78, 1, 128},
  {"128:_mm_hadd_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), y)), x)", f79, 1, 128},
  {"128:_mm_hadd_ps(y, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), y)))", f80, 1, 128},
  {"128:_mm_hadd_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_EQ_OQ)), y)", f81, 1, 128},
  {"128:_mm_hadd_ps(x, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_EQ_OQ)))", f82, 1, 128},
  {"128:_mm_hadd_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_EQ_OQ)), x)", f83, 1, 128},
  {"128:_mm_hadd_ps(y, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_EQ_OQ)))", f84, 1, 128},
  {"128:_mm_hadd_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_EQ_OQ)), y)", f85, 1, 128},
  {"128:_mm_hadd_ps(x, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_EQ_OQ)))", f86, 1, 128},
  {"128:_mm_hadd_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_EQ_OQ)), x)", f87, 1, 128},
  {"128:_mm_hadd_ps(y, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_EQ_OQ)))", f88, 1, 128},
  {"128:_mm_hadd_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), y)), y)", f89, 1, 128},
  {"128:_mm_hadd_ps(x, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), y)))", f90, 1, 128},
  {"128:_mm_hadd_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), y)), x)", f91, 1, 128},
  {"128:_mm_hadd_ps(y, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), y)))", f92, 1, 128},
  {"128:_mm_hadd_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_UNORD_Q)), y)", f93, 1, 128},
  {"128:_mm_hadd_ps(x, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_UNORD_Q)))", f94, 1, 128},
  {"128:_mm_hadd_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_UNORD_Q)), x)", f95, 1, 128},
  {"128:_mm_hadd_ps(y, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_UNORD_Q)))", f96, 1, 128},
  {"128:_mm_hadd_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_UNORD_Q)), y)", f97, 1, 128},
  {"128:_mm_hadd_ps(x, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_UNORD_Q)))", f98, 1, 128},
  {"128:_mm_hadd_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_UNORD_Q)), x)", f99, 1, 128},
  {"128:_mm_hadd_ps(y, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_UNORD_Q)))", f100, 1, 128},
  {"128:_mm_hadd_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), y)), y)", f101, 1, 128},
  {"128:_mm_hadd_ps(x, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), y)))", f102, 1, 128},
  {"128:_mm_hadd_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), y)), x)", f103, 1, 128},
  {"128:_mm_hadd_ps(y, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), y)))", f104, 1, 128},
  {"128:_mm_hadd_ps(_mm_unpacklo_ps(x, y), y)", f105, 1, 128},
  {"128:_mm_hadd_ps(x, _mm_unpacklo_ps(x, y))", f106, 1, 128},
  {"128:_mm_hadd_ps(_mm_unpacklo_ps(x, y), x)", f107, 1, 128},
  {"128:_mm_hadd_ps(y, _mm_unpacklo_ps(x, y))", f108, 1, 128},
  {"128:_mm_hadd_ps(_mm_unpackhi_ps(x, y), y)", f109, 1, 128},
  {"128:_mm_hadd_ps(x, _mm_unpackhi_ps(x, y))", f110, 1, 128},
  {"128:_mm_hadd_ps(_mm_unpackhi_ps(x, y), x)", f111, 1, 128},
  {"128:_mm_hadd_ps(y, _mm_unpackhi_ps(x, y))", f112, 1, 128},
  {"128:_mm_hadd_ps(_mm_hadd_ps(x, y), y)", f113, 1, 128},
  {"128:_mm_hadd_ps(x, _mm_hadd_ps(x, y))", f114, 1, 128},
  {"128:_mm_hadd_ps(_mm_hadd_ps(x, y), x)", f115, 1, 128},
  {"128:_mm_hadd_ps(y, _mm_hadd_ps(x, y))", f116, 1, 128},
  {"128:_mm_hadd_ps(_mm_hsub_ps(x, y), y)", f117, 1, 128},
  {"128:_mm_hadd_ps(x, _mm_hsub_ps(x, y))", f118, 1, 128},
  {"128:_mm_hadd_ps(_mm_hsub_ps(x, y), x)", f119, 1, 128},
  {"128:_mm_hadd_ps(y, _mm_hsub_ps(x, y))", f120, 1, 128},
  {"128:_mm_hadd_ps(_mm_shuffle_ps(x, y, 0x1b), y)", f121, 1, 128},
  {"128:_mm_hadd_ps(x, _mm_shuffle_ps(x, y, 0x1b))", f122, 1, 128},
  {"128:_mm_hadd_ps(_mm_shuffle_ps(x, y, 0x1b), x)", f123, 1, 128},
  {"128:_mm_hadd_ps(y, _mm_shuffle_ps(x, y, 0x1b))", f124, 1, 128},
  {"128:_mm_hadd_ps(_mm_shuffle_ps(x, y, 0x39), y)", f125, 1, 128},
  {"128:_mm_hadd_ps(x, _mm_shuffle_ps(x, y, 0x39))", f126, 1, 128},
  {"128:_mm_hadd_ps(_mm_shuffle_ps(x, y, 0x39), x)", f127, 1, 128},
  {"128:_mm_hadd_ps(y, _mm_shuffle_ps(x, y, 0x39))", f128, 1, 128},
  {"128:_mm_hadd_ps(_mm_shuffle_ps(x, y, 0x93), y)", f129, 1, 128},
  {"128:_mm_hadd_ps(x, _mm_shuffle_ps(x, y, 0x93))", f130, 1, 128},
  {"128:_mm_hadd_ps(_mm_shuffle_ps(x, y, 0x93), x)", f131, 1, 128},
  {"128:_mm_hadd_ps(y, _mm_shuffle_ps(x, y, 0x93))", f132, 1, 128},
  {"128:_mm_hadd_ps(_mm_shuffle_ps(x, y, 0x4e), y)", f133, 1, 128},
  {"128:_mm_hadd_ps(x, _mm_shuffle_ps(x, y, 0x4e))", f134, 1, 128},
  {"128:_mm_hadd_ps(_mm_shuffle_ps(x, y, 0x4e), x)", f135, 1, 128},
  {"128:_mm_hadd_ps(y, _mm_shuffle_ps(x, y, 0x4e))", f136, 1, 128},
  {"128:_mm_hsub_ps(_mm_add_ps(x, y), y)", f137, 1, 128},
  {"128:_mm_hsub_ps(x, _mm_add_ps(x, y))", f138, 1, 128},
  {"128:_mm_hsub_ps(_mm_add_ps(x, y), x)", f139, 1, 128},
  {"128:_mm_hsub_ps(y, _mm_add_ps(x, y))", f140, 1, 128},
  {"128:_mm_hsub_ps(_mm_sub_ps(x, y), y)", f141, 1, 128},
  {"128:_mm_hsub_ps(x, _mm_sub_ps(x, y))", f142, 1, 128},
  {"128:_mm_hsub_ps(_mm_sub_ps(x, y), x)", f143, 1, 128},
  {"128:_mm_hsub_ps(y, _mm_sub_ps(x, y))", f144, 1, 128},
  {"128:_mm_hsub_ps(_mm_mul_ps(x, y), y)", f145, 1, 128},
  {"128:_mm_hsub_ps(x, _mm_mul_ps(x, y))", f146, 1, 128},
  {"128:_mm_hsub_ps(_mm_mul_ps(x, y), x)", f147, 1, 128},
  {"128:_mm_hsub_ps(y, _mm_mul_ps(x, y))", f148, 1, 128},
  {"128:_mm_hsub_ps(_mm_div_ps(x, y), y)", f149, 1, 128},
  {"128:_mm_hsub_ps(x, _mm_div_ps(x, y))", f150, 1, 128},
  {"128:_mm_hsub_ps(_mm_div_ps(x, y), x)", f151, 1, 128},
  {"128:_mm_hsub_ps(y, _mm_div_ps(x, y))", f152, 1, 128},
  {"128:_mm_hsub_ps(_mm_min_ps(x, y), y)", f153, 1, 128},
  {"128:_mm_hsub_ps(x, _mm_min_ps(x, y))", f154, 1, 128},
  {"128:_mm_hsub_ps(_mm_min_ps(x, y), x)", f155, 1, 128},
  {"128:_mm_hsub_ps(y, _mm_min_ps(x, y))", f156, 1, 128},
  {"128:_mm_hsub_ps(_mm_max_ps(x, y), y)", f157, 1, 128},
  {"128:_mm_hsub_ps(x, _mm_max_ps(x, y))", f158, 1, 128},
  {"128:_mm_hsub_ps(_mm_max_ps(x, y), x)", f159, 1, 128},
  {"128:_mm_hsub_ps(y, _mm_max_ps(x, y))", f160, 1, 128},
  {"128:_mm_hsub_ps(_mm_and_ps(x, y), y)", f161, 1, 128},
  {"128:_mm_hsub_ps(x, _mm_and_ps(x, y))", f162, 1, 128},
  {"128:_mm_hsub_ps(_mm_and_ps(x, y), x)", f163, 1, 128},
  {"128:_mm_hsub_ps(y, _mm_and_ps(x, y))", f164, 1, 128},
  {"128:_mm_hsub_ps(_mm_or_ps(x, y), y)", f165, 1, 128},
  {"128:_mm_hsub_ps(x, _mm_or_ps(x, y))", f166, 1, 128},
  {"128:_mm_hsub_ps(_mm_or_ps(x, y), x)", f167, 1, 128},
  {"128:_mm_hsub_ps(y, _mm_or_ps(x, y))", f168, 1, 128},
  {"128:_mm_hsub_ps(_mm_xor_ps(x, y), y)", f169, 1, 128},
  {"128:_mm_hsub_ps(x, _mm_xor_ps(x, y))", f170, 1, 128},
  {"128:_mm_hsub_ps(_mm_xor_ps(x, y), x)", f171, 1, 128},
  {"128:_mm_hsub_ps(y, _mm_xor_ps(x, y))", f172, 1, 128},
  {"128:_mm_hsub_ps(_mm_andnot_ps(x, y), y)", f173, 1, 128},
  {"128:_mm_hsub_ps(x, _mm_andnot_ps(x, y))", f174, 1, 128},
  {"128:_mm_hsub_ps(_mm_andnot_ps(x, y), x)", f175, 1, 128},
  {"128:_mm_hsub_ps(y, _mm_andnot_ps(x, y))", f176, 1, 128},
  {"128:_mm_hsub_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), y)", f177, 1, 128},
  {"128:_mm_hsub_ps(x, _mm_cmp_ps(x, y, _CMP_EQ_OQ))", f178, 1, 128},
  {"128:_mm_hsub_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), x)", f179, 1, 128},
  {"128:_mm_hsub_ps(y, _mm_cmp_ps(x, y, _CMP_EQ_OQ))", f180, 1, 128},
  {"128:_mm_hsub_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), y)", f181, 1, 128},
  {"128:_mm_hsub_ps(x, _mm_cmp_ps(x, y, _CMP_LT_OS))", f182, 1, 128},
  {"128:_mm_hsub_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), x)", f183, 1, 128},
  {"128:_mm_hsub_ps(y, _mm_cmp_ps(x, y, _CMP_LT_OS))", f184, 1, 128},
  {"128:_mm_hsub_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), y)", f185, 1, 128},
  {"128:_mm_hsub_ps(x, _mm_cmp_ps(x, y, _CMP_LE_OS))", f186, 1, 128},
  {"128:_mm_hsub_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), x)", f187, 1, 128},
  {"128:_mm_hsub_ps(y, _mm_cmp_ps(x, y, _CMP_LE_OS))", f188, 1, 128},
  {"128:_mm_hsub_ps(_mm_cmp_ps(x, y, _CMP_NEQ_UQ), y)", f189, 1, 128},
  {"128:_mm_hsub_ps(x, _mm_cmp_ps(x, y, _CMP_NEQ_UQ))", f190, 1, 128},
  {"128:_mm_hsub_ps(_mm_cmp_ps(x, y, _CMP_NEQ_UQ), x)", f191, 1, 128},
  {"128:_mm_hsub_ps(y, _mm_cmp_ps(x, y, _CMP_NEQ_UQ))", f192, 1, 128},
  {"128:_mm_hsub_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), y)", f193, 1, 128},
  {"128:_mm_hsub_ps(x, _mm_cmp_ps(x, y, _CMP_UNORD_Q))", f194, 1, 128},
  {"128:_mm_hsub_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), x)", f195, 1, 128},
  {"128:_mm_hsub_ps(y, _mm_cmp_ps(x, y, _CMP_UNORD_Q))", f196, 1, 128},
  {"128:_mm_hsub_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), y)", f197, 1, 128},
  {"128:_mm_hsub_ps(x, _mm_cmp_ps(x, y, _CMP_NLT_US))", f198, 1, 128},
  {"128:_mm_hsub_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), x)", f199, 1, 128},
  {"128:_mm_hsub_ps(y, _mm_cmp_ps(x, y, _CMP_NLT_US))", f200, 1, 128},
  {"128:_mm_hsub_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), y)", f201, 1, 128},
  {"128:_mm_hsub_ps(x, _mm_cmp_ps(x, y, _CMP_GT_OS))", f202, 1, 128},
  {"128:_mm_hsub_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), x)", f203, 1, 128},
  {"128:_mm_hsub_ps(y, _mm_cmp_ps(x, y, _CMP_GT_OS))", f204, 1, 128},
  {"128:_mm_hsub_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LT_OS)), y)", f205, 1, 128},
  {"128:_mm_hsub_ps(x, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LT_OS)))", f206, 1, 128},
  {"128:_mm_hsub_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LT_OS)), x)", f207, 1, 128},
  {"128:_mm_hsub_ps(y, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LT_OS)))", f208, 1, 128},
  {"128:_mm_hsub_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LT_OS)), y)", f209, 1, 128},
  {"128:_mm_hsub_ps(x, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LT_OS)))", f210, 1, 128},
  {"128:_mm_hsub_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LT_OS)), x)", f211, 1, 128},
  {"128:_mm_hsub_ps(y, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LT_OS)))", f212, 1, 128},
  {"128:_mm_hsub_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), y)), y)", f213, 1, 128},
  {"128:_mm_hsub_ps(x, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), y)))", f214, 1, 128},
  {"128:_mm_hsub_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), y)), x)", f215, 1, 128},
  {"128:_mm_hsub_ps(y, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), y)))", f216, 1, 128},
  {"128:_mm_hsub_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LE_OS)), y)", f217, 1, 128},
  {"128:_mm_hsub_ps(x, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LE_OS)))", f218, 1, 128},
  {"128:_mm_hsub_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LE_OS)), x)", f219, 1, 128},
  {"128:_mm_hsub_ps(y, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LE_OS)))", f220, 1, 128},
  {"128:_mm_hsub_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LE_OS)), y)", f221, 1, 128},
  {"128:_mm_hsub_ps(x, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LE_OS)))", f222, 1, 128},
  {"128:_mm_hsub_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LE_OS)), x)", f223, 1, 128},
  {"128:_mm_hsub_ps(y, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LE_OS)))", f224, 1, 128},
  {"128:_mm_hsub_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), y)), y)", f225, 1, 128},
  {"128:_mm_hsub_ps(x, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), y)))", f226, 1, 128},
  {"128:_mm_hsub_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), y)), x)", f227, 1, 128},
  {"128:_mm_hsub_ps(y, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), y)))", f228, 1, 128},
  {"128:_mm_hsub_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_GT_OS)), y)", f229, 1, 128},
  {"128:_mm_hsub_ps(x, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_GT_OS)))", f230, 1, 128},
  {"128:_mm_hsub_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_GT_OS)), x)", f231, 1, 128},
  {"128:_mm_hsub_ps(y, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_GT_OS)))", f232, 1, 128},
  {"128:_mm_hsub_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_GT_OS)), y)", f233, 1, 128},
  {"128:_mm_hsub_ps(x, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_GT_OS)))", f234, 1, 128},
  {"128:_mm_hsub_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_GT_OS)), x)", f235, 1, 128},
  {"128:_mm_hsub_ps(y, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_GT_OS)))", f236, 1, 128},
  {"128:_mm_hsub_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), y)), y)", f237, 1, 128},
  {"128:_mm_hsub_ps(x, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), y)))", f238, 1, 128},
  {"128:_mm_hsub_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), y)), x)", f239, 1, 128},
  {"128:_mm_hsub_ps(y, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), y)))", f240, 1, 128},
  {"128:_mm_hsub_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_NLT_US)), y)", f241, 1, 128},
  {"128:_mm_hsub_ps(x, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_NLT_US)))", f242, 1, 128},
  {"128:_mm_hsub_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_NLT_US)), x)", f243, 1, 128},
  {"128:_mm_hsub_ps(y, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_NLT_US)))", f244, 1, 128},
  {"128:_mm_hsub_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_NLT_US)), y)", f245, 1, 128},
  {"128:_mm_hsub_ps(x, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_NLT_US)))", f246, 1, 128},
  {"128:_mm_hsub_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_NLT_US)), x)", f247, 1, 128},
  {"128:_mm_hsub_ps(y, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_NLT_US)))", f248, 1, 128},
  {"128:_mm_hsub_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), y)), y)", f249, 1, 128},
  {"128:_mm_hsub_ps(x, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), y)))", f250, 1, 128},
  {"128:_mm_hsub_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), y)), x)", f251, 1, 128},
  {"128:_mm_hsub_ps(y, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), y)))", f252, 1, 128},
  {"128:_mm_hsub_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_EQ_OQ)), y)", f253, 1, 128},
  {"128:_mm_hsub_ps(x, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_EQ_OQ)))", f254, 1, 128},
  {"128:_mm_hsub_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_EQ_OQ)), x)", f255, 1, 128},
  {"128:_mm_hsub_ps(y, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_EQ_OQ)))", f256, 1, 128},
  {"128:_mm_hsub_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_EQ_OQ)), y)", f257, 1, 128},
  {"128:_mm_hsub_ps(x, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_EQ_OQ)))", f258, 1, 128},
  {"128:_mm_hsub_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_EQ_OQ)), x)", f259, 1, 128},
  {"128:_mm_hsub_ps(y, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_EQ_OQ)))", f260, 1, 128},
  {"128:_mm_hsub_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), y)), y)", f261, 1, 128},
  {"128:_mm_hsub_ps(x, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), y)))", f262, 1, 128},
  {"128:_mm_hsub_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), y)), x)", f263, 1, 128},
  {"128:_mm_hsub_ps(y, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), y)))", f264, 1, 128},
  {"128:_mm_hsub_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_UNORD_Q)), y)", f265, 1, 128},
  {"128:_mm_hsub_ps(x, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_UNORD_Q)))", f266, 1, 128},
  {"128:_mm_hsub_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_UNORD_Q)), x)", f267, 1, 128},
  {"128:_mm_hsub_ps(y, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_UNORD_Q)))", f268, 1, 128},
  {"128:_mm_hsub_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_UNORD_Q)), y)", f269, 1, 128},
  {"128:_mm_hsub_ps(x, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_UNORD_Q)))", f270, 1, 128},
  {"128:_mm_hsub_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_UNORD_Q)), x)", f271, 1, 128},
  {"128:_mm_hsub_ps(y, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_UNORD_Q)))", f272, 1, 128},
  {"128:_mm_hsub_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), y)), y)", f273, 1, 128},
  {"128:_mm_hsub_ps(x, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), y)))", f274, 1, 128},
  {"128:_mm_hsub_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), y)), x)", f275, 1, 128},
  {"128:_mm_hsub_ps(y, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), y)))", f276, 1, 128},
  {"128:_mm_hsub_ps(_mm_unpacklo_ps(x, y), y)", f277, 1, 128},
  {"128:_mm_hsub_ps(x, _mm_unpacklo_ps(x, y))", f278, 1, 128},
  {"128:_mm_hsub_ps(_mm_unpacklo_ps(x, y), x)", f279, 1, 128},
  {"128:_mm_hsub_ps(y, _mm_unpacklo_ps(x, y))", f280, 1, 128},
  {"128:_mm_hsub_ps(_mm_unpackhi_ps(x, y), y)", f281, 1, 128},
  {"128:_mm_hsub_ps(x, _mm_unpackhi_ps(x, y))", f282, 1, 128},
  {"128:_mm_hsub_ps(_mm_unpackhi_ps(x, y), x)", f283, 1, 128},
  {"128:_mm_hsub_ps(y, _mm_unpackhi_ps(x, y))", f284, 1, 128},
  {"128:_mm_hsub_ps(_mm_hadd_ps(x, y), y)", f285, 1, 128},
  {"128:_mm_hsub_ps(x, _mm_hadd_ps(x, y))", f286, 1, 128},
  {"128:_mm_hsub_ps(_mm_hadd_ps(x, y), x)", f287, 1, 128},
  {"128:_mm_hsub_ps(y, _mm_hadd_ps(x, y))", f288, 1, 128},
  {"128:_mm_hsub_ps(_mm_hsub_ps(x, y), y)", f289, 1, 128},
  {"128:_mm_hsub_ps(x, _mm_hsub_ps(x, y))", f290, 1, 128},
  {"128:_mm_hsub_ps(_mm_hsub_ps(x, y), x)", f291, 1, 128},
  {"128:_mm_hsub_ps(y, _mm_hsub_ps(x, y))", f292, 1, 128},
  {"128:_mm_hsub_ps(_mm_shuffle_ps(x, y, 0x1b), y)", f293, 1, 128},
  {"128:_mm_hsub_ps(x, _mm_shuffle_ps(x, y, 0x1b))", f294, 1, 128},
  {"128:_mm_hsub_ps(_mm_shuffle_ps(x, y, 0x1b), x)", f295, 1, 128},
  {"128:_mm_hsub_ps(y, _mm_shuffle_ps(x, y, 0x1b))", f296, 1, 128},
  {"128:_mm_hsub_ps(_mm_shuffle_ps(x, y, 0x39), y)", f297, 1, 128},
  {"128:_mm_hsub_ps(x, _mm_shuffle_ps(x, y, 0x39))", f298, 1, 128},
  {"128:_mm_hsub_ps(_mm_shuffle_ps(x, y, 0x39), x)", f299, 1, 128},
  {"128:_mm_hsub_ps(y, _mm_shuffle_ps(x, y, 0x39))", f300, 1, 128},
  {"128:_mm_hsub_ps(_mm_shuffle_ps(x, y, 0x93), y)", f301, 1, 128},
  {"128:_mm_hsub_ps(x, _mm_shuffle_ps(x, y, 0x93))", f302, 1, 128},
  {"128:_mm_hsub_ps(_mm_shuffle_ps(x, y, 0x93), x)", f303, 1, 128},
  {"128:_mm_hsub_ps(y, _mm_shuffle_ps(x, y, 0x93))", f304, 1, 128},
  {"128:_mm_hsub_ps(_mm_shuffle_ps(x, y, 0x4e), y)", f305, 1, 128},
  {"128:_mm_hsub_ps(x, _mm_shuffle_ps(x, y, 0x4e))", f306, 1, 128},
  {"128:_mm_hsub_ps(_mm_shuffle_ps(x, y, 0x4e), x)", f307, 1, 128},
  {"128:_mm_hsub_ps(y, _mm_shuffle_ps(x, y, 0x4e))", f308, 1, 128},
  {"128:_mm_shuffle_ps(_mm_add_ps(x, y), y, 0x1b)", f309, 1, 128},
  {"128:_mm_shuffle_ps(x, _mm_add_ps(x, y), 0x1b)", f310, 1, 128},
  {"128:_mm_shuffle_ps(_mm_add_ps(x, y), x, 0x1b)", f311, 1, 128},
  {"128:_mm_shuffle_ps(y, _mm_add_ps(x, y), 0x1b)", f312, 1, 128},
  {"128:_mm_shuffle_ps(_mm_sub_ps(x, y), y, 0x1b)", f313, 1, 128},
  {"128:_mm_shuffle_ps(x, _mm_sub_ps(x, y), 0x1b)", f314, 1, 128},
  {"128:_mm_shuffle_ps(_mm_sub_ps(x, y), x, 0x1b)", f315, 1, 128},
  {"128:_mm_shuffle_ps(y, _mm_sub_ps(x, y), 0x1b)", f316, 1, 128},
  {"128:_mm_shuffle_ps(_mm_mul_ps(x, y), y, 0x1b)", f317, 1, 128},
  {"128:_mm_shuffle_ps(x, _mm_mul_ps(x, y), 0x1b)", f318, 1, 128},
  {"128:_mm_shuffle_ps(_mm_mul_ps(x, y), x, 0x1b)", f319, 1, 128},
  {"128:_mm_shuffle_ps(y, _mm_mul_ps(x, y), 0x1b)", f320, 1, 128},
  {"128:_mm_shuffle_ps(_mm_div_ps(x, y), y, 0x1b)", f321, 1, 128},
  {"128:_mm_shuffle_ps(x, _mm_div_ps(x, y), 0x1b)", f322, 1, 128},
  {"128:_mm_shuffle_ps(_mm_div_ps(x, y), x, 0x1b)", f323, 1, 128},
  {"128:_mm_shuffle_ps(y, _mm_div_ps(x, y), 0x1b)", f324, 1, 128},
  {"128:_mm_shuffle_ps(_mm_min_ps(x, y), y, 0x1b)", f325, 1, 128},
  {"128:_mm_shuffle_ps(x, _mm_min_ps(x, y), 0x1b)", f326, 1, 128},
  {"128:_mm_shuffle_ps(_mm_min_ps(x, y), x, 0x1b)", f327, 1, 128},
  {"128:_mm_shuffle_ps(y, _mm_min_ps(x, y), 0x1b)", f328, 1, 128},
  {"128:_mm_shuffle_ps(_mm_max_ps(x, y), y, 0x1b)", f329, 1, 128},
  {"128:_mm_shuffle_ps(x, _mm_max_ps(x, y), 0x1b)", f330, 1, 128},
  {"128:_mm_shuffle_ps(_mm_max_ps(x, y), x, 0x1b)", f331, 1, 128},
  {"128:_mm_shuffle_ps(y, _mm_max_ps(x, y), 0x1b)", f332, 1, 128},
  {"128:_mm_shuffle_ps(_mm_and_ps(x, y), y, 0x1b)", f333, 1, 128},
  {"128:_mm_shuffle_ps(x, _mm_and_ps(x, y), 0x1b)", f334, 1, 128},
  {"128:_mm_shuffle_ps(_mm_and_ps(x, y), x, 0x1b)", f335, 1, 128},
  {"128:_mm_shuffle_ps(y, _mm_and_ps(x, y), 0x1b)", f336, 1, 128},
  {"128:_mm_shuffle_ps(_mm_or_ps(x, y), y, 0x1b)", f337, 1, 128},
  {"128:_mm_shuffle_ps(x, _mm_or_ps(x, y), 0x1b)", f338, 1, 128},
  {"128:_mm_shuffle_ps(_mm_or_ps(x, y), x, 0x1b)", f339, 1, 128},
  {"128:_mm_shuffle_ps(y, _mm_or_ps(x, y), 0x1b)", f340, 1, 128},
  {"128:_mm_shuffle_ps(_mm_xor_ps(x, y), y, 0x1b)", f341, 1, 128},
  {"128:_mm_shuffle_ps(x, _mm_xor_ps(x, y), 0x1b)", f342, 1, 128},
  {"128:_mm_shuffle_ps(_mm_xor_ps(x, y), x, 0x1b)", f343, 1, 128},
  {"128:_mm_shuffle_ps(y, _mm_xor_ps(x, y), 0x1b)", f344, 1, 128},
  {"128:_mm_shuffle_ps(_mm_andnot_ps(x, y), y, 0x1b)", f345, 1, 128},
  {"128:_mm_shuffle_ps(x, _mm_andnot_ps(x, y), 0x1b)", f346, 1, 128},
  {"128:_mm_shuffle_ps(_mm_andnot_ps(x, y), x, 0x1b)", f347, 1, 128},
  {"128:_mm_shuffle_ps(y, _mm_andnot_ps(x, y), 0x1b)", f348, 1, 128},
  {"128:_mm_shuffle_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), y, 0x1b)", f349, 1, 128},
  {"128:_mm_shuffle_ps(x, _mm_cmp_ps(x, y, _CMP_EQ_OQ), 0x1b)", f350, 1, 128},
  {"128:_mm_shuffle_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), x, 0x1b)", f351, 1, 128},
  {"128:_mm_shuffle_ps(y, _mm_cmp_ps(x, y, _CMP_EQ_OQ), 0x1b)", f352, 1, 128},
  {"128:_mm_shuffle_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), y, 0x1b)", f353, 1, 128},
  {"128:_mm_shuffle_ps(x, _mm_cmp_ps(x, y, _CMP_LT_OS), 0x1b)", f354, 1, 128},
  {"128:_mm_shuffle_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), x, 0x1b)", f355, 1, 128},
  {"128:_mm_shuffle_ps(y, _mm_cmp_ps(x, y, _CMP_LT_OS), 0x1b)", f356, 1, 128},
  {"128:_mm_shuffle_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), y, 0x1b)", f357, 1, 128},
  {"128:_mm_shuffle_ps(x, _mm_cmp_ps(x, y, _CMP_LE_OS), 0x1b)", f358, 1, 128},
  {"128:_mm_shuffle_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), x, 0x1b)", f359, 1, 128},
  {"128:_mm_shuffle_ps(y, _mm_cmp_ps(x, y, _CMP_LE_OS), 0x1b)", f360, 1, 128},
  {"128:_mm_shuffle_ps(_mm_cmp_ps(x, y, _CMP_NEQ_UQ), y, 0x1b)", f361, 1, 128},
  {"128:_mm_shuffle_ps(x, _mm_cmp_ps(x, y, _CMP_NEQ_UQ), 0x1b)", f362, 1, 128},
  {"128:_mm_shuffle_ps(_mm_cmp_ps(x, y, _CMP_NEQ_UQ), x, 0x1b)", f363, 1, 128},
  {"128:_mm_shuffle_ps(y, _mm_cmp_ps(x, y, _CMP_NEQ_UQ), 0x1b)", f364, 1, 128},
  {"128:_mm_shuffle_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), y, 0x1b)", f365, 1, 128},
  {"128:_mm_shuffle_ps(x, _mm_cmp_ps(x, y, _CMP_UNORD_Q), 0x1b)", f366, 1, 128},
  {"128:_mm_shuffle_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), x, 0x1b)", f367, 1, 128},
  {"128:_mm_shuffle_ps(y, _mm_cmp_ps(x, y, _CMP_UNORD_Q), 0x1b)", f368, 1, 128},
  {"128:_mm_shuffle_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), y, 0x1b)", f369, 1, 128},
  {"128:_mm_shuffle_ps(x, _mm_cmp_ps(x, y, _CMP_NLT_US), 0x1b)", f370, 1, 128},
  {"128:_mm_shuffle_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), x, 0x1b)", f371, 1, 128},
  {"128:_mm_shuffle_ps(y, _mm_cmp_ps(x, y, _CMP_NLT_US), 0x1b)", f372, 1, 128},
  {"128:_mm_shuffle_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), y, 0x1b)", f373, 1, 128},
  {"128:_mm_shuffle_ps(x, _mm_cmp_ps(x, y, _CMP_GT_OS), 0x1b)", f374, 1, 128},
  {"128:_mm_shuffle_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), x, 0x1b)", f375, 1, 128},
  {"128:_mm_shuffle_ps(y, _mm_cmp_ps(x, y, _CMP_GT_OS), 0x1b)", f376, 1, 128},
  {"128:_mm_shuffle_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LT_OS)), y, 0x1b)", f377, 1, 128},
  {"128:_mm_shuffle_ps(x, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LT_OS)), 0x1b)", f378, 1, 128},
  {"128:_mm_shuffle_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LT_OS)), x, 0x1b)", f379, 1, 128},
  {"128:_mm_shuffle_ps(y, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LT_OS)), 0x1b)", f380, 1, 128},
  {"128:_mm_shuffle_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LT_OS)), y, 0x1b)", f381, 1, 128},
  {"128:_mm_shuffle_ps(x, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LT_OS)), 0x1b)", f382, 1, 128},
  {"128:_mm_shuffle_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LT_OS)), x, 0x1b)", f383, 1, 128},
  {"128:_mm_shuffle_ps(y, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LT_OS)), 0x1b)", f384, 1, 128},
  {"128:_mm_shuffle_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), y)), y, 0x1b)", f385, 1, 128},
  {"128:_mm_shuffle_ps(x, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), y)), 0x1b)", f386, 1, 128},
  {"128:_mm_shuffle_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), y)), x, 0x1b)", f387, 1, 128},
  {"128:_mm_shuffle_ps(y, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), y)), 0x1b)", f388, 1, 128},
  {"128:_mm_shuffle_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LE_OS)), y, 0x1b)", f389, 1, 128},
  {"128:_mm_shuffle_ps(x, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LE_OS)), 0x1b)", f390, 1, 128},
  {"128:_mm_shuffle_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LE_OS)), x, 0x1b)", f391, 1, 128},
  {"128:_mm_shuffle_ps(y, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LE_OS)), 0x1b)", f392, 1, 128},
  {"128:_mm_shuffle_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LE_OS)), y, 0x1b)", f393, 1, 128},
  {"128:_mm_shuffle_ps(x, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LE_OS)), 0x1b)", f394, 1, 128},
  {"128:_mm_shuffle_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LE_OS)), x, 0x1b)", f395, 1, 128},
  {"128:_mm_shuffle_ps(y, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LE_OS)), 0x1b)", f396, 1, 128},
  {"128:_mm_shuffle_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), y)), y, 0x1b)", f397, 1, 128},
  {"128:_mm_shuffle_ps(x, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), y)), 0x1b)", f398, 1, 128},
  {"128:_mm_shuffle_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), y)), x, 0x1b)", f399, 1, 128},
  {"128:_mm_shuffle_ps(y, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), y)), 0x1b)", f400, 1, 128},
  {"128:_mm_shuffle_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_GT_OS)), y, 0x1b)", f401, 1, 128},
  {"128:_mm_shuffle_ps(x, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_GT_OS)), 0x1b)", f402, 1, 128},
  {"128:_mm_shuffle_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_GT_OS)), x, 0x1b)", f403, 1, 128},
  {"128:_mm_shuffle_ps(y, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_GT_OS)), 0x1b)", f404, 1, 128},
  {"128:_mm_shuffle_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_GT_OS)), y, 0x1b)", f405, 1, 128},
  {"128:_mm_shuffle_ps(x, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_GT_OS)), 0x1b)", f406, 1, 128},
  {"128:_mm_shuffle_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_GT_OS)), x, 0x1b)", f407, 1, 128},
  {"128:_mm_shuffle_ps(y, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_GT_OS)), 0x1b)", f408, 1, 128},
  {"128:_mm_shuffle_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), y)), y, 0x1b)", f409, 1, 128},
  {"128:_mm_shuffle_ps(x, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), y)), 0x1b)", f410, 1, 128},
  {"128:_mm_shuffle_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), y)), x, 0x1b)", f411, 1, 128},
  {"128:_mm_shuffle_ps(y, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), y)), 0x1b)", f412, 1, 128},
  {"128:_mm_shuffle_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_NLT_US)), y, 0x1b)", f413, 1, 128},
  {"128:_mm_shuffle_ps(x, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_NLT_US)), 0x1b)", f414, 1, 128},
  {"128:_mm_shuffle_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_NLT_US)), x, 0x1b)", f415, 1, 128},
  {"128:_mm_shuffle_ps(y, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_NLT_US)), 0x1b)", f416, 1, 128},
  {"128:_mm_shuffle_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_NLT_US)), y, 0x1b)", f417, 1, 128},
  {"128:_mm_shuffle_ps(x, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_NLT_US)), 0x1b)", f418, 1, 128},
  {"128:_mm_shuffle_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_NLT_US)), x, 0x1b)", f419, 1, 128},
  {"128:_mm_shuffle_ps(y, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_NLT_US)), 0x1b)", f420, 1, 128},
  {"128:_mm_shuffle_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), y)), y, 0x1b)", f421, 1, 128},
  {"128:_mm_shuffle_ps(x, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), y)), 0x1b)", f422, 1, 128},
  {"128:_mm_shuffle_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), y)), x, 0x1b)", f423, 1, 128},
  {"128:_mm_shuffle_ps(y, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), y)), 0x1b)", f424, 1, 128},
  {"128:_mm_shuffle_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_EQ_OQ)), y, 0x1b)", f425, 1, 128},
  {"128:_mm_shuffle_ps(x, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_EQ_OQ)), 0x1b)", f426, 1, 128},
  {"128:_mm_shuffle_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_EQ_OQ)), x, 0x1b)", f427, 1, 128},
  {"128:_mm_shuffle_ps(y, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_EQ_OQ)), 0x1b)", f428, 1, 128},
  {"128:_mm_shuffle_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_EQ_OQ)), y, 0x1b)", f429, 1, 128},
  {"128:_mm_shuffle_ps(x, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_EQ_OQ)), 0x1b)", f430, 1, 128},
  {"128:_mm_shuffle_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_EQ_OQ)), x, 0x1b)", f431, 1, 128},
  {"128:_mm_shuffle_ps(y, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_EQ_OQ)), 0x1b)", f432, 1, 128},
  {"128:_mm_shuffle_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), y)), y, 0x1b)", f433, 1, 128},
  {"128:_mm_shuffle_ps(x, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), y)), 0x1b)", f434, 1, 128},
  {"128:_mm_shuffle_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), y)), x, 0x1b)", f435, 1, 128},
  {"128:_mm_shuffle_ps(y, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), y)), 0x1b)", f436, 1, 128},
  {"128:_mm_shuffle_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_UNORD_Q)), y, 0x1b)", f437, 1, 128},
  {"128:_mm_shuffle_ps(x, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_UNORD_Q)), 0x1b)", f438, 1, 128},
  {"128:_mm_shuffle_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_UNORD_Q)), x, 0x1b)", f439, 1, 128},
  {"128:_mm_shuffle_ps(y, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_UNORD_Q)), 0x1b)", f440, 1, 128},
  {"128:_mm_shuffle_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_UNORD_Q)), y, 0x1b)", f441, 1, 128},
  {"128:_mm_shuffle_ps(x, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_UNORD_Q)), 0x1b)", f442, 1, 128},
  {"128:_mm_shuffle_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_UNORD_Q)), x, 0x1b)", f443, 1, 128},
  {"128:_mm_shuffle_ps(y, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_UNORD_Q)), 0x1b)", f444, 1, 128},
  {"128:_mm_shuffle_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), y)), y, 0x1b)", f445, 1, 128},
  {"128:_mm_shuffle_ps(x, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), y)), 0x1b)", f446, 1, 128},
  {"128:_mm_shuffle_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), y)), x, 0x1b)", f447, 1, 128},
  {"128:_mm_shuffle_ps(y, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), y)), 0x1b)", f448, 1, 128},
  {"128:_mm_shuffle_ps(_mm_unpacklo_ps(x, y), y, 0x1b)", f449, 1, 128},
  {"128:_mm_shuffle_ps(x, _mm_unpacklo_ps(x, y), 0x1b)", f450, 1, 128},
  {"128:_mm_shuffle_ps(_mm_unpacklo_ps(x, y), x, 0x1b)", f451, 1, 128},
  {"128:_mm_shuffle_ps(y, _mm_unpacklo_ps(x, y), 0x1b)", f452, 1, 128},
  {"128:_mm_shuffle_ps(_mm_unpackhi_ps(x, y), y, 0x1b)", f453, 1, 128},
  {"128:_mm_shuffle_ps(x, _mm_unpackhi_ps(x, y), 0x1b)", f454, 1, 128},
  {"128:_mm_shuffle_ps(_mm_unpackhi_ps(x, y), x, 0x1b)", f455, 1, 128},
  {"128:_mm_shuffle_ps(y, _mm_unpackhi_ps(x, y), 0x1b)", f456, 1, 128},
  {"128:_mm_shuffle_ps(_mm_hadd_ps(x, y), y, 0x1b)", f457, 1, 128},
  {"128:_mm_shuffle_ps(x, _mm_hadd_ps(x, y), 0x1b)", f458, 1, 128},
  {"128:_mm_shuffle_ps(_mm_hadd_ps(x, y), x, 0x1b)", f459, 1, 128},
  {"128:_mm_shuffle_ps(y, _mm_hadd_ps(x, y), 0x1b)", f460, 1, 128},
  {"128:_mm_shuffle_ps(_mm_hsub_ps(x, y), y, 0x1b)", f461, 1, 128},
  {"128:_mm_shuffle_ps(x, _mm_hsub_ps(x, y), 0x1b)", f462, 1, 128},
  {"128:_mm_shuffle_ps(_mm_hsub_ps(x, y), x, 0x1b)", f463, 1, 128},
  {"128:_mm_shuffle_ps(y, _mm_hsub_ps(x, y), 0x1b)", f464, 1, 128},
  {"128:_mm_shuffle_ps(_mm_shuffle_ps(x, y, 0x1b), y, 0x1b)", f465, 1, 128},
  {"128:_mm_shuffle_ps(x, _mm_shuffle_ps(x, y, 0x1b), 0x1b)", f466, 1, 128},
  {"128:_mm_shuffle_ps(_mm_shuffle_ps(x, y, 0x1b), x, 0x1b)", f467, 1, 128},
  {"128:_mm_shuffle_ps(y, _mm_shuffle_ps(x, y, 0x1b), 0x1b)", f468, 1, 128},
  {"128:_mm_shuffle_ps(_mm_shuffle_ps(x, y, 0x39), y, 0x1b)", f469, 1, 128},
  {"128:_mm_shuffle_ps(x, _mm_shuffle_ps(x, y, 0x39), 0x1b)", f470, 1, 128},
  {"128:_mm_shuffle_ps(_mm_shuffle_ps(x, y, 0x39), x, 0x1b)", f471, 1, 128},
  {"128:_mm_shuffle_ps(y, _mm_shuffle_ps(x, y, 0x39), 0x1b)", f472, 1, 128},
  {"128:_mm_shuffle_ps(_mm_shuffle_ps(x, y, 0x93), y, 0x1b)", f473, 1, 128},
  {"128:_mm_shuffle_ps(x, _mm_shuffle_ps(x, y, 0x93), 0x1b)", f474, 1, 128},
  {"128:_mm_shuffle_ps(_mm_shuffle_ps(x, y, 0x93), x, 0x1b)", f475, 1, 128},
  {"128:_mm_shuffle_ps(y, _mm_shuffle_ps(x, y, 0x93), 0x1b)", f476, 1, 128},
  {"128:_mm_shuffle_ps(_mm_shuffle_ps(x, y, 0x4e), y, 0x1b)", f477, 1, 128},
  {"128:_mm_shuffle_ps(x, _mm_shuffle_ps(x, y, 0x4e), 0x1b)", f478, 1, 128},
  {"128:_mm_shuffle_ps(_mm_shuffle_ps(x, y, 0x4e), x, 0x1b)", f479, 1, 128},
  {"128:_mm_shuffle_ps(y, _mm_shuffle_ps(x, y, 0x4e), 0x1b)", f480, 1, 128},
  {"128:_mm_shuffle_ps(_mm_add_ps(x, y), y, 0x39)", f481, 1, 128},
  {"128:_mm_shuffle_ps(x, _mm_add_ps(x, y), 0x39)", f482, 1, 128},
  {"128:_mm_shuffle_ps(_mm_add_ps(x, y), x, 0x39)", f483, 1, 128},
  {"128:_mm_shuffle_ps(y, _mm_add_ps(x, y), 0x39)", f484, 1, 128},
  {"128:_mm_shuffle_ps(_mm_sub_ps(x, y), y, 0x39)", f485, 1, 128},
  {"128:_mm_shuffle_ps(x, _mm_sub_ps(x, y), 0x39)", f486, 1, 128},
  {"128:_mm_shuffle_ps(_mm_sub_ps(x, y), x, 0x39)", f487, 1, 128},
  {"128:_mm_shuffle_ps(y, _mm_sub_ps(x, y), 0x39)", f488, 1, 128},
  {"128:_mm_shuffle_ps(_mm_mul_ps(x, y), y, 0x39)", f489, 1, 128},
  {"128:_mm_shuffle_ps(x, _mm_mul_ps(x, y), 0x39)", f490, 1, 128},
  {"128:_mm_shuffle_ps(_mm_mul_ps(x, y), x, 0x39)", f491, 1, 128},
  {"128:_mm_shuffle_ps(y, _mm_mul_ps(x, y), 0x39)", f492, 1, 128},
  {"128:_mm_shuffle_ps(_mm_div_ps(x, y), y, 0x39)", f493, 1, 128},
  {"128:_mm_shuffle_ps(x, _mm_div_ps(x, y), 0x39)", f494, 1, 128},
  {"128:_mm_shuffle_ps(_mm_div_ps(x, y), x, 0x39)", f495, 1, 128},
  {"128:_mm_shuffle_ps(y, _mm_div_ps(x, y), 0x39)", f496, 1, 128},
  {"128:_mm_shuffle_ps(_mm_min_ps(x, y), y, 0x39)", f497, 1, 128},
  {"128:_mm_shuffle_ps(x, _mm_min_ps(x, y), 0x39)", f498, 1, 128},
  {"128:_mm_shuffle_ps(_mm_min_ps(x, y), x, 0x39)", f499, 1, 128},
  {"128:_mm_shuffle_ps(y, _mm_min_ps(x, y), 0x39)", f500, 1, 128},
  {"128:_mm_shuffle_ps(_mm_max_ps(x, y), y, 0x39)", f501, 1, 128},
  {"128:_mm_shuffle_ps(x, _mm_max_ps(x, y), 0x39)", f502, 1, 128},
  {"128:_mm_shuffle_ps(_mm_max_ps(x, y), x, 0x39)", f503, 1, 128},
  {"128:_mm_shuffle_ps(y, _mm_max_ps(x, y), 0x39)", f504, 1, 128},
  {"128:_mm_shuffle_ps(_mm_and_ps(x, y), y, 0x39)", f505, 1, 128},
  {"128:_mm_shuffle_ps(x, _mm_and_ps(x, y), 0x39)", f506, 1, 128},
  {"128:_mm_shuffle_ps(_mm_and_ps(x, y), x, 0x39)", f507, 1, 128},
  {"128:_mm_shuffle_ps(y, _mm_and_ps(x, y), 0x39)", f508, 1, 128},
  {"128:_mm_shuffle_ps(_mm_or_ps(x, y), y, 0x39)", f509, 1, 128},
  {"128:_mm_shuffle_ps(x, _mm_or_ps(x, y), 0x39)", f510, 1, 128},
  {"128:_mm_shuffle_ps(_mm_or_ps(x, y), x, 0x39)", f511, 1, 128},
  {"128:_mm_shuffle_ps(y, _mm_or_ps(x, y), 0x39)", f512, 1, 128},
  {"128:_mm_shuffle_ps(_mm_xor_ps(x, y), y, 0x39)", f513, 1, 128},
  {"128:_mm_shuffle_ps(x, _mm_xor_ps(x, y), 0x39)", f514, 1, 128},
  {"128:_mm_shuffle_ps(_mm_xor_ps(x, y), x, 0x39)", f515, 1, 128},
  {"128:_mm_shuffle_ps(y, _mm_xor_ps(x, y), 0x39)", f516, 1, 128},
  {"128:_mm_shuffle_ps(_mm_andnot_ps(x, y), y, 0x39)", f517, 1, 128},
  {"128:_mm_shuffle_ps(x, _mm_andnot_ps(x, y), 0x39)", f518, 1, 128},
  {"128:_mm_shuffle_ps(_mm_andnot_ps(x, y), x, 0x39)", f519, 1, 128},
  {"128:_mm_shuffle_ps(y, _mm_andnot_ps(x, y), 0x39)", f520, 1, 128},
  {"128:_mm_shuffle_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), y, 0x39)", f521, 1, 128},
  {"128:_mm_shuffle_ps(x, _mm_cmp_ps(x, y, _CMP_EQ_OQ), 0x39)", f522, 1, 128},
  {"128:_mm_shuffle_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), x, 0x39)", f523, 1, 128},
  {"128:_mm_shuffle_ps(y, _mm_cmp_ps(x, y, _CMP_EQ_OQ), 0x39)", f524, 1, 128},
  {"128:_mm_shuffle_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), y, 0x39)", f525, 1, 128},
  {"128:_mm_shuffle_ps(x, _mm_cmp_ps(x, y, _CMP_LT_OS), 0x39)", f526, 1, 128},
  {"128:_mm_shuffle_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), x, 0x39)", f527, 1, 128},
  {"128:_mm_shuffle_ps(y, _mm_cmp_ps(x, y, _CMP_LT_OS), 0x39)", f528, 1, 128},
  {"128:_mm_shuffle_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), y, 0x39)", f529, 1, 128},
  {"128:_mm_shuffle_ps(x, _mm_cmp_ps(x, y, _CMP_LE_OS), 0x39)", f530, 1, 128},
  {"128:_mm_shuffle_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), x, 0x39)", f531, 1, 128},
  {"128:_mm_shuffle_ps(y, _mm_cmp_ps(x, y, _CMP_LE_OS), 0x39)", f532, 1, 128},
  {"128:_mm_shuffle_ps(_mm_cmp_ps(x, y, _CMP_NEQ_UQ), y, 0x39)", f533, 1, 128},
  {"128:_mm_shuffle_ps(x, _mm_cmp_ps(x, y, _CMP_NEQ_UQ), 0x39)", f534, 1, 128},
  {"128:_mm_shuffle_ps(_mm_cmp_ps(x, y, _CMP_NEQ_UQ), x, 0x39)", f535, 1, 128},
  {"128:_mm_shuffle_ps(y, _mm_cmp_ps(x, y, _CMP_NEQ_UQ), 0x39)", f536, 1, 128},
  {"128:_mm_shuffle_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), y, 0x39)", f537, 1, 128},
  {"128:_mm_shuffle_ps(x, _mm_cmp_ps(x, y, _CMP_UNORD_Q), 0x39)", f538, 1, 128},
  {"128:_mm_shuffle_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), x, 0x39)", f539, 1, 128},
  {"128:_mm_shuffle_ps(y, _mm_cmp_ps(x, y, _CMP_UNORD_Q), 0x39)", f540, 1, 128},
  {"128:_mm_shuffle_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), y, 0x39)", f541, 1, 128},
  {"128:_mm_shuffle_ps(x, _mm_cmp_ps(x, y, _CMP_NLT_US), 0x39)", f542, 1, 128},
  {"128:_mm_shuffle_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), x, 0x39)", f543, 1, 128},
  {"128:_mm_shuffle_ps(y, _mm_cmp_ps(x, y, _CMP_NLT_US), 0x39)", f544, 1, 128},
  {"128:_mm_shuffle_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), y, 0x39)", f545, 1, 128},
  {"128:_mm_shuffle_ps(x, _mm_cmp_ps(x, y, _CMP_GT_OS), 0x39)", f546, 1, 128},
  {"128:_mm_shuffle_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), x, 0x39)", f547, 1, 128},
  {"128:_mm_shuffle_ps(y, _mm_cmp_ps(x, y, _CMP_GT_OS), 0x39)", f548, 1, 128},
  {"128:_mm_shuffle_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LT_OS)), y, 0x39)", f549, 1, 128},
  {"128:_mm_shuffle_ps(x, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LT_OS)), 0x39)", f550, 1, 128},
  {"128:_mm_shuffle_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LT_OS)), x, 0x39)", f551, 1, 128},
  {"128:_mm_shuffle_ps(y, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LT_OS)), 0x39)", f552, 1, 128},
  {"128:_mm_shuffle_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LT_OS)), y, 0x39)", f553, 1, 128},
  {"128:_mm_shuffle_ps(x, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LT_OS)), 0x39)", f554, 1, 128},
  {"128:_mm_shuffle_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LT_OS)), x, 0x39)", f555, 1, 128},
  {"128:_mm_shuffle_ps(y, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LT_OS)), 0x39)", f556, 1, 128},
  {"128:_mm_shuffle_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), y)), y, 0x39)", f557, 1, 128},
  {"128:_mm_shuffle_ps(x, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), y)), 0x39)", f558, 1, 128},
  {"128:_mm_shuffle_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), y)), x, 0x39)", f559, 1, 128},
  {"128:_mm_shuffle_ps(y, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), y)), 0x39)", f560, 1, 128},
  {"128:_mm_shuffle_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LE_OS)), y, 0x39)", f561, 1, 128},
  {"128:_mm_shuffle_ps(x, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LE_OS)), 0x39)", f562, 1, 128},
  {"128:_mm_shuffle_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LE_OS)), x, 0x39)", f563, 1, 128},
  {"128:_mm_shuffle_ps(y, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LE_OS)), 0x39)", f564, 1, 128},
  {"128:_mm_shuffle_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LE_OS)), y, 0x39)", f565, 1, 128},
  {"128:_mm_shuffle_ps(x, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LE_OS)), 0x39)", f566, 1, 128},
  {"128:_mm_shuffle_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LE_OS)), x, 0x39)", f567, 1, 128},
  {"128:_mm_shuffle_ps(y, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LE_OS)), 0x39)", f568, 1, 128},
  {"128:_mm_shuffle_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), y)), y, 0x39)", f569, 1, 128},
  {"128:_mm_shuffle_ps(x, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), y)), 0x39)", f570, 1, 128},
  {"128:_mm_shuffle_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), y)), x, 0x39)", f571, 1, 128},
  {"128:_mm_shuffle_ps(y, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), y)), 0x39)", f572, 1, 128},
  {"128:_mm_shuffle_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_GT_OS)), y, 0x39)", f573, 1, 128},
  {"128:_mm_shuffle_ps(x, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_GT_OS)), 0x39)", f574, 1, 128},
  {"128:_mm_shuffle_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_GT_OS)), x, 0x39)", f575, 1, 128},
  {"128:_mm_shuffle_ps(y, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_GT_OS)), 0x39)", f576, 1, 128},
  {"128:_mm_shuffle_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_GT_OS)), y, 0x39)", f577, 1, 128},
  {"128:_mm_shuffle_ps(x, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_GT_OS)), 0x39)", f578, 1, 128},
  {"128:_mm_shuffle_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_GT_OS)), x, 0x39)", f579, 1, 128},
  {"128:_mm_shuffle_ps(y, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_GT_OS)), 0x39)", f580, 1, 128},
  {"128:_mm_shuffle_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), y)), y, 0x39)", f581, 1, 128},
  {"128:_mm_shuffle_ps(x, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), y)), 0x39)", f582, 1, 128},
  {"128:_mm_shuffle_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), y)), x, 0x39)", f583, 1, 128},
  {"128:_mm_shuffle_ps(y, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), y)), 0x39)", f584, 1, 128},
  {"128:_mm_shuffle_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_NLT_US)), y, 0x39)", f585, 1, 128},
  {"128:_mm_shuffle_ps(x, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_NLT_US)), 0x39)", f586, 1, 128},
  {"128:_mm_shuffle_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_NLT_US)), x, 0x39)", f587, 1, 128},
  {"128:_mm_shuffle_ps(y, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_NLT_US)), 0x39)", f588, 1, 128},
  {"128:_mm_shuffle_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_NLT_US)), y, 0x39)", f589, 1, 128},
  {"128:_mm_shuffle_ps(x, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_NLT_US)), 0x39)", f590, 1, 128},
  {"128:_mm_shuffle_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_NLT_US)), x, 0x39)", f591, 1, 128},
  {"128:_mm_shuffle_ps(y, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_NLT_US)), 0x39)", f592, 1, 128},
  {"128:_mm_shuffle_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), y)), y, 0x39)", f593, 1, 128},
  {"128:_mm_shuffle_ps(x, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), y)), 0x39)", f594, 1, 128},
  {"128:_mm_shuffle_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), y)), x, 0x39)", f595, 1, 128},
  {"128:_mm_shuffle_ps(y, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), y)), 0x39)", f596, 1, 128},
  {"128:_mm_shuffle_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_EQ_OQ)), y, 0x39)", f597, 1, 128},
  {"128:_mm_shuffle_ps(x, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_EQ_OQ)), 0x39)", f598, 1, 128},
  {"128:_mm_shuffle_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_EQ_OQ)), x, 0x39)", f599, 1, 128},
  {"128:_mm_shuffle_ps(y, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_EQ_OQ)), 0x39)", f600, 1, 128},
  {"128:_mm_shuffle_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_EQ_OQ)), y, 0x39)", f601, 1, 128},
  {"128:_mm_shuffle_ps(x, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_EQ_OQ)), 0x39)", f602, 1, 128},
  {"128:_mm_shuffle_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_EQ_OQ)), x, 0x39)", f603, 1, 128},
  {"128:_mm_shuffle_ps(y, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_EQ_OQ)), 0x39)", f604, 1, 128},
  {"128:_mm_shuffle_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), y)), y, 0x39)", f605, 1, 128},
  {"128:_mm_shuffle_ps(x, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), y)), 0x39)", f606, 1, 128},
  {"128:_mm_shuffle_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), y)), x, 0x39)", f607, 1, 128},
  {"128:_mm_shuffle_ps(y, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), y)), 0x39)", f608, 1, 128},
  {"128:_mm_shuffle_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_UNORD_Q)), y, 0x39)", f609, 1, 128},
  {"128:_mm_shuffle_ps(x, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_UNORD_Q)), 0x39)", f610, 1, 128},
  {"128:_mm_shuffle_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_UNORD_Q)), x, 0x39)", f611, 1, 128},
  {"128:_mm_shuffle_ps(y, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_UNORD_Q)), 0x39)", f612, 1, 128},
  {"128:_mm_shuffle_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_UNORD_Q)), y, 0x39)", f613, 1, 128},
  {"128:_mm_shuffle_ps(x, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_UNORD_Q)), 0x39)", f614, 1, 128},
  {"128:_mm_shuffle_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_UNORD_Q)), x, 0x39)", f615, 1, 128},
  {"128:_mm_shuffle_ps(y, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_UNORD_Q)), 0x39)", f616, 1, 128},
  {"128:_mm_shuffle_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), y)), y, 0x39)", f617, 1, 128},
  {"128:_mm_shuffle_ps(x, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), y)), 0x39)", f618, 1, 128},
  {"128:_mm_shuffle_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), y)), x, 0x39)", f619, 1, 128},
  {"128:_mm_shuffle_ps(y, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), y)), 0x39)", f620, 1, 128},
  {"128:_mm_shuffle_ps(_mm_unpacklo_ps(x, y), y, 0x39)", f621, 1, 128},
  {"128:_mm_shuffle_ps(x, _mm_unpacklo_ps(x, y), 0x39)", f622, 1, 128},
  {"128:_mm_shuffle_ps(_mm_unpacklo_ps(x, y), x, 0x39)", f623, 1, 128},
  {"128:_mm_shuffle_ps(y, _mm_unpacklo_ps(x, y), 0x39)", f624, 1, 128},
  {"128:_mm_shuffle_ps(_mm_unpackhi_ps(x, y), y, 0x39)", f625, 1, 128},
  {"128:_mm_shuffle_ps(x, _mm_unpackhi_ps(x, y), 0x39)", f626, 1, 128},
  {"128:_mm_shuffle_ps(_mm_unpackhi_ps(x, y), x, 0x39)", f627, 1, 128},
  {"128:_mm_shuffle_ps(y, _mm_unpackhi_ps(x, y), 0x39)", f628, 1, 128},
  {"128:_mm_shuffle_ps(_mm_hadd_ps(x, y), y, 0x39)", f629, 1, 128},
  {"128:_mm_shuffle_ps(x, _mm_hadd_ps(x, y), 0x39)", f630, 1, 128},
  {"128:_mm_shuffle_ps(_mm_hadd_ps(x, y), x, 0x39)", f631, 1, 128},
  {"128:_mm_shuffle_ps(y, _mm_hadd_ps(x, y), 0x39)", f632, 1, 128},
  {"128:_mm_shuffle_ps(_mm_hsub_ps(x, y), y, 0x39)", f633, 1, 128},
  {"128:_mm_shuffle_ps(x, _mm_hsub_ps(x, y), 0x39)", f634, 1, 128},
  {"128:_mm_shuffle_ps(_mm_hsub_ps(x, y), x, 0x39)", f635, 1, 128},
  {"128:_mm_shuffle_ps(y, _mm_hsub_ps(x, y), 0x39)", f636, 1, 128},
  {"128:_mm_shuffle_ps(_mm_shuffle_ps(x, y, 0x1b), y, 0x39)", f637, 1, 128},
  {"128:_mm_shuffle_ps(x, _mm_shuffle_ps(x, y, 0x1b), 0x39)", f638, 1, 128},
  {"128:_mm_shuffle_ps(_mm_shuffle_ps(x, y, 0x1b), x, 0x39)", f639, 1, 128},
  {"128:_mm_shuffle_ps(y, _mm_shuffle_ps(x, y, 0x1b), 0x39)", f640, 1, 128},
  {"128:_mm_shuffle_ps(_mm_shuffle_ps(x, y, 0x39), y, 0x39)", f641, 1, 128},
  {"128:_mm_shuffle_ps(x, _mm_shuffle_ps(x, y, 0x39), 0x39)", f642, 1, 128},
  {"128:_mm_shuffle_ps(_mm_shuffle_ps(x, y, 0x39), x, 0x39)", f643, 1, 128},
  {"128:_mm_shuffle_ps(y, _mm_shuffle_ps(x, y, 0x39), 0x39)", f644, 1, 128},
  {"128:_mm_shuffle_ps(_mm_shuffle_ps(x, y, 0x93), y, 0x39)", f645, 1, 128},
  {"128:_mm_shuffle_ps(x, _mm_shuffle_ps(x, y, 0x93), 0x39)", f646, 1, 128},
  {"128:_mm_shuffle_ps(_mm_shuffle_ps(x, y, 0x93), x, 0x39)", f647, 1, 128},
  {"128:_mm_shuffle_ps(y, _mm_shuffle_ps(x, y, 0x93), 0x39)", f648, 1, 128},
  {"128:_mm_shuffle_ps(_mm_shuffle_ps(x, y, 0x4e), y, 0x39)", f649, 1, 128},
  {"128:_mm_shuffle_ps(x, _mm_shuffle_ps(x, y, 0x4e), 0x39)", f650, 1, 128},
  {"128:_mm_shuffle_ps(_mm_shuffle_ps(x, y, 0x4e), x, 0x39)", f651, 1, 128},
  {"128:_mm_shuffle_ps(y, _mm_shuffle_ps(x, y, 0x4e), 0x39)", f652, 1, 128},
  {"128:_mm_shuffle_ps(_mm_add_ps(x, y), y, 0x93)", f653, 1, 128},
  {"128:_mm_shuffle_ps(x, _mm_add_ps(x, y), 0x93)", f654, 1, 128},
  {"128:_mm_shuffle_ps(_mm_add_ps(x, y), x, 0x93)", f655, 1, 128},
  {"128:_mm_shuffle_ps(y, _mm_add_ps(x, y), 0x93)", f656, 1, 128},
  {"128:_mm_shuffle_ps(_mm_sub_ps(x, y), y, 0x93)", f657, 1, 128},
  {"128:_mm_shuffle_ps(x, _mm_sub_ps(x, y), 0x93)", f658, 1, 128},
  {"128:_mm_shuffle_ps(_mm_sub_ps(x, y), x, 0x93)", f659, 1, 128},
  {"128:_mm_shuffle_ps(y, _mm_sub_ps(x, y), 0x93)", f660, 1, 128},
  {"128:_mm_shuffle_ps(_mm_mul_ps(x, y), y, 0x93)", f661, 1, 128},
  {"128:_mm_shuffle_ps(x, _mm_mul_ps(x, y), 0x93)", f662, 1, 128},
  {"128:_mm_shuffle_ps(_mm_mul_ps(x, y), x, 0x93)", f663, 1, 128},
  {"128:_mm_shuffle_ps(y, _mm_mul_ps(x, y), 0x93)", f664, 1, 128},
  {"128:_mm_shuffle_ps(_mm_div_ps(x, y), y, 0x93)", f665, 1, 128},
  {"128:_mm_shuffle_ps(x, _mm_div_ps(x, y), 0x93)", f666, 1, 128},
  {"128:_mm_shuffle_ps(_mm_div_ps(x, y), x, 0x93)", f667, 1, 128},
  {"128:_mm_shuffle_ps(y, _mm_div_ps(x, y), 0x93)", f668, 1, 128},
  {"128:_mm_shuffle_ps(_mm_min_ps(x, y), y, 0x93)", f669, 1, 128},
  {"128:_mm_shuffle_ps(x, _mm_min_ps(x, y), 0x93)", f670, 1, 128},
  {"128:_mm_shuffle_ps(_mm_min_ps(x, y), x, 0x93)", f671, 1, 128},
  {"128:_mm_shuffle_ps(y, _mm_min_ps(x, y), 0x93)", f672, 1, 128},
  {"128:_mm_shuffle_ps(_mm_max_ps(x, y), y, 0x93)", f673, 1, 128},
  {"128:_mm_shuffle_ps(x, _mm_max_ps(x, y), 0x93)", f674, 1, 128},
  {"128:_mm_shuffle_ps(_mm_max_ps(x, y), x, 0x93)", f675, 1, 128},
  {"128:_mm_shuffle_ps(y, _mm_max_ps(x, y), 0x93)", f676, 1, 128},
  {"128:_mm_shuffle_ps(_mm_and_ps(x, y), y, 0x93)", f677, 1, 128},
  {"128:_mm_shuffle_ps(x, _mm_and_ps(x, y), 0x93)", f678, 1, 128},
  {"128:_mm_shuffle_ps(_mm_and_ps(x, y), x, 0x93)", f679, 1, 128},
  {"128:_mm_shuffle_ps(y, _mm_and_ps(x, y), 0x93)", f680, 1, 128},
  {"128:_mm_shuffle_ps(_mm_or_ps(x, y), y, 0x93)", f681, 1, 128},
  {"128:_mm_shuffle_ps(x, _mm_or_ps(x, y), 0x93)", f682, 1, 128},
  {"128:_mm_shuffle_ps(_mm_or_ps(x, y), x, 0x93)", f683, 1, 128},
  {"128:_mm_shuffle_ps(y, _mm_or_ps(x, y), 0x93)", f684, 1, 128},
  {"128:_mm_shuffle_ps(_mm_xor_ps(x, y), y, 0x93)", f685, 1, 128},
  {"128:_mm_shuffle_ps(x, _mm_xor_ps(x, y), 0x93)", f686, 1, 128},
  {"128:_mm_shuffle_ps(_mm_xor_ps(x, y), x, 0x93)", f687, 1, 128},
  {"128:_mm_shuffle_ps(y, _mm_xor_ps(x, y), 0x93)", f688, 1, 128},
  {"128:_mm_shuffle_ps(_mm_andnot_ps(x, y), y, 0x93)", f689, 1, 128},
  {"128:_mm_shuffle_ps(x, _mm_andnot_ps(x, y), 0x93)", f690, 1, 128},
  {"128:_mm_shuffle_ps(_mm_andnot_ps(x, y), x, 0x93)", f691, 1, 128},
  {"128:_mm_shuffle_ps(y, _mm_andnot_ps(x, y), 0x93)", f692, 1, 128},
  {"128:_mm_shuffle_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), y, 0x93)", f693, 1, 128},
  {"128:_mm_shuffle_ps(x, _mm_cmp_ps(x, y, _CMP_EQ_OQ), 0x93)", f694, 1, 128},
  {"128:_mm_shuffle_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), x, 0x93)", f695, 1, 128},
  {"128:_mm_shuffle_ps(y, _mm_cmp_ps(x, y, _CMP_EQ_OQ), 0x93)", f696, 1, 128},
  {"128:_mm_shuffle_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), y, 0x93)", f697, 1, 128},
  {"128:_mm_shuffle_ps(x, _mm_cmp_ps(x, y, _CMP_LT_OS), 0x93)", f698, 1, 128},
  {"128:_mm_shuffle_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), x, 0x93)", f699, 1, 128},
  {"128:_mm_shuffle_ps(y, _mm_cmp_ps(x, y, _CMP_LT_OS), 0x93)", f700, 1, 128},
  {"128:_mm_shuffle_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), y, 0x93)", f701, 1, 128},
  {"128:_mm_shuffle_ps(x, _mm_cmp_ps(x, y, _CMP_LE_OS), 0x93)", f702, 1, 128},
  {"128:_mm_shuffle_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), x, 0x93)", f703, 1, 128},
  {"128:_mm_shuffle_ps(y, _mm_cmp_ps(x, y, _CMP_LE_OS), 0x93)", f704, 1, 128},
  {"128:_mm_shuffle_ps(_mm_cmp_ps(x, y, _CMP_NEQ_UQ), y, 0x93)", f705, 1, 128},
  {"128:_mm_shuffle_ps(x, _mm_cmp_ps(x, y, _CMP_NEQ_UQ), 0x93)", f706, 1, 128},
  {"128:_mm_shuffle_ps(_mm_cmp_ps(x, y, _CMP_NEQ_UQ), x, 0x93)", f707, 1, 128},
  {"128:_mm_shuffle_ps(y, _mm_cmp_ps(x, y, _CMP_NEQ_UQ), 0x93)", f708, 1, 128},
  {"128:_mm_shuffle_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), y, 0x93)", f709, 1, 128},
  {"128:_mm_shuffle_ps(x, _mm_cmp_ps(x, y, _CMP_UNORD_Q), 0x93)", f710, 1, 128},
  {"128:_mm_shuffle_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), x, 0x93)", f711, 1, 128},
  {"128:_mm_shuffle_ps(y, _mm_cmp_ps(x, y, _CMP_UNORD_Q), 0x93)", f712, 1, 128},
  {"128:_mm_shuffle_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), y, 0x93)", f713, 1, 128},
  {"128:_mm_shuffle_ps(x, _mm_cmp_ps(x, y, _CMP_NLT_US), 0x93)", f714, 1, 128},
  {"128:_mm_shuffle_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), x, 0x93)", f715, 1, 128},
  {"128:_mm_shuffle_ps(y, _mm_cmp_ps(x, y, _CMP_NLT_US), 0x93)", f716, 1, 128},
  {"128:_mm_shuffle_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), y, 0x93)", f717, 1, 128},
  {"128:_mm_shuffle_ps(x, _mm_cmp_ps(x, y, _CMP_GT_OS), 0x93)", f718, 1, 128},
  {"128:_mm_shuffle_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), x, 0x93)", f719, 1, 128},
  {"128:_mm_shuffle_ps(y, _mm_cmp_ps(x, y, _CMP_GT_OS), 0x93)", f720, 1, 128},
  {"128:_mm_shuffle_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LT_OS)), y, 0x93)", f721, 1, 128},
  {"128:_mm_shuffle_ps(x, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LT_OS)), 0x93)", f722, 1, 128},
  {"128:_mm_shuffle_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LT_OS)), x, 0x93)", f723, 1, 128},
  {"128:_mm_shuffle_ps(y, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LT_OS)), 0x93)", f724, 1, 128},
  {"128:_mm_shuffle_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LT_OS)), y, 0x93)", f725, 1, 128},
  {"128:_mm_shuffle_ps(x, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LT_OS)), 0x93)", f726, 1, 128},
  {"128:_mm_shuffle_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LT_OS)), x, 0x93)", f727, 1, 128},
  {"128:_mm_shuffle_ps(y, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LT_OS)), 0x93)", f728, 1, 128},
  {"128:_mm_shuffle_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), y)), y, 0x93)", f729, 1, 128},
  {"128:_mm_shuffle_ps(x, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), y)), 0x93)", f730, 1, 128},
  {"128:_mm_shuffle_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), y)), x, 0x93)", f731, 1, 128},
  {"128:_mm_shuffle_ps(y, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), y)), 0x93)", f732, 1, 128},
  {"128:_mm_shuffle_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LE_OS)), y, 0x93)", f733, 1, 128},
  {"128:_mm_shuffle_ps(x, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LE_OS)), 0x93)", f734, 1, 128},
  {"128:_mm_shuffle_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LE_OS)), x, 0x93)", f735, 1, 128},
  {"128:_mm_shuffle_ps(y, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LE_OS)), 0x93)", f736, 1, 128},
  {"128:_mm_shuffle_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LE_OS)), y, 0x93)", f737, 1, 128},
  {"128:_mm_shuffle_ps(x, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LE_OS)), 0x93)", f738, 1, 128},
  {"128:_mm_shuffle_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LE_OS)), x, 0x93)", f739, 1, 128},
  {"128:_mm_shuffle_ps(y, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LE_OS)), 0x93)", f740, 1, 128},
  {"128:_mm_shuffle_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), y)), y, 0x93)", f741, 1, 128},
  {"128:_mm_shuffle_ps(x, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), y)), 0x93)", f742, 1, 128},
  {"128:_mm_shuffle_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), y)), x, 0x93)", f743, 1, 128},
  {"128:_mm_shuffle_ps(y, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), y)), 0x93)", f744, 1, 128},
  {"128:_mm_shuffle_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_GT_OS)), y, 0x93)", f745, 1, 128},
  {"128:_mm_shuffle_ps(x, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_GT_OS)), 0x93)", f746, 1, 128},
  {"128:_mm_shuffle_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_GT_OS)), x, 0x93)", f747, 1, 128},
  {"128:_mm_shuffle_ps(y, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_GT_OS)), 0x93)", f748, 1, 128},
  {"128:_mm_shuffle_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_GT_OS)), y, 0x93)", f749, 1, 128},
  {"128:_mm_shuffle_ps(x, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_GT_OS)), 0x93)", f750, 1, 128},
  {"128:_mm_shuffle_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_GT_OS)), x, 0x93)", f751, 1, 128},
  {"128:_mm_shuffle_ps(y, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_GT_OS)), 0x93)", f752, 1, 128},
  {"128:_mm_shuffle_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), y)), y, 0x93)", f753, 1, 128},
  {"128:_mm_shuffle_ps(x, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), y)), 0x93)", f754, 1, 128},
  {"128:_mm_shuffle_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), y)), x, 0x93)", f755, 1, 128},
  {"128:_mm_shuffle_ps(y, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), y)), 0x93)", f756, 1, 128},
  {"128:_mm_shuffle_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_NLT_US)), y, 0x93)", f757, 1, 128},
  {"128:_mm_shuffle_ps(x, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_NLT_US)), 0x93)", f758, 1, 128},
  {"128:_mm_shuffle_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_NLT_US)), x, 0x93)", f759, 1, 128},
  {"128:_mm_shuffle_ps(y, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_NLT_US)), 0x93)", f760, 1, 128},
  {"128:_mm_shuffle_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_NLT_US)), y, 0x93)", f761, 1, 128},
  {"128:_mm_shuffle_ps(x, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_NLT_US)), 0x93)", f762, 1, 128},
  {"128:_mm_shuffle_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_NLT_US)), x, 0x93)", f763, 1, 128},
  {"128:_mm_shuffle_ps(y, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_NLT_US)), 0x93)", f764, 1, 128},
  {"128:_mm_shuffle_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), y)), y, 0x93)", f765, 1, 128},
  {"128:_mm_shuffle_ps(x, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), y)), 0x93)", f766, 1, 128},
  {"128:_mm_shuffle_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), y)), x, 0x93)", f767, 1, 128},
  {"128:_mm_shuffle_ps(y, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), y)), 0x93)", f768, 1, 128},
  {"128:_mm_shuffle_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_EQ_OQ)), y, 0x93)", f769, 1, 128},
  {"128:_mm_shuffle_ps(x, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_EQ_OQ)), 0x93)", f770, 1, 128},
  {"128:_mm_shuffle_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_EQ_OQ)), x, 0x93)", f771, 1, 128},
  {"128:_mm_shuffle_ps(y, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_EQ_OQ)), 0x93)", f772, 1, 128},
  {"128:_mm_shuffle_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_EQ_OQ)), y, 0x93)", f773, 1, 128},
  {"128:_mm_shuffle_ps(x, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_EQ_OQ)), 0x93)", f774, 1, 128},
  {"128:_mm_shuffle_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_EQ_OQ)), x, 0x93)", f775, 1, 128},
  {"128:_mm_shuffle_ps(y, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_EQ_OQ)), 0x93)", f776, 1, 128},
  {"128:_mm_shuffle_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), y)), y, 0x93)", f777, 1, 128},
  {"128:_mm_shuffle_ps(x, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), y)), 0x93)", f778, 1, 128},
  {"128:_mm_shuffle_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), y)), x, 0x93)", f779, 1, 128},
  {"128:_mm_shuffle_ps(y, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), y)), 0x93)", f780, 1, 128},
  {"128:_mm_shuffle_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_UNORD_Q)), y, 0x93)", f781, 1, 128},
  {"128:_mm_shuffle_ps(x, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_UNORD_Q)), 0x93)", f782, 1, 128},
  {"128:_mm_shuffle_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_UNORD_Q)), x, 0x93)", f783, 1, 128},
  {"128:_mm_shuffle_ps(y, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_UNORD_Q)), 0x93)", f784, 1, 128},
  {"128:_mm_shuffle_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_UNORD_Q)), y, 0x93)", f785, 1, 128},
  {"128:_mm_shuffle_ps(x, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_UNORD_Q)), 0x93)", f786, 1, 128},
  {"128:_mm_shuffle_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_UNORD_Q)), x, 0x93)", f787, 1, 128},
  {"128:_mm_shuffle_ps(y, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_UNORD_Q)), 0x93)", f788, 1, 128},
  {"128:_mm_shuffle_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), y)), y, 0x93)", f789, 1, 128},
  {"128:_mm_shuffle_ps(x, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), y)), 0x93)", f790, 1, 128},
  {"128:_mm_shuffle_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), y)), x, 0x93)", f791, 1, 128},
  {"128:_mm_shuffle_ps(y, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), y)), 0x93)", f792, 1, 128},
  {"128:_mm_shuffle_ps(_mm_unpacklo_ps(x, y), y, 0x93)", f793, 1, 128},
  {"128:_mm_shuffle_ps(x, _mm_unpacklo_ps(x, y), 0x93)", f794, 1, 128},
  {"128:_mm_shuffle_ps(_mm_unpacklo_ps(x, y), x, 0x93)", f795, 1, 128},
  {"128:_mm_shuffle_ps(y, _mm_unpacklo_ps(x, y), 0x93)", f796, 1, 128},
  {"128:_mm_shuffle_ps(_mm_unpackhi_ps(x, y), y, 0x93)", f797, 1, 128},
  {"128:_mm_shuffle_ps(x, _mm_unpackhi_ps(x, y), 0x93)", f798, 1, 128},
  {"128:_mm_shuffle_ps(_mm_unpackhi_ps(x, y), x, 0x93)", f799, 1, 128},
  {"128:_mm_shuffle_ps(y, _mm_unpackhi_ps(x, y), 0x93)", f800, 1, 128},
  {"128:_mm_shuffle_ps(_mm_hadd_ps(x, y), y, 0x93)", f801, 1, 128},
  {"128:_mm_shuffle_ps(x, _mm_hadd_ps(x, y), 0x93)", f802, 1, 128},
  {"128:_mm_shuffle_ps(_mm_hadd_ps(x, y), x, 0x93)", f803, 1, 128},
  {"128:_mm_shuffle_ps(y, _mm_hadd_ps(x, y), 0x93)", f804, 1, 128},
  {"128:_mm_shuffle_ps(_mm_hsub_ps(x, y), y, 0x93)", f805, 1, 128},
  {"128:_mm_shuffle_ps(x, _mm_hsub_ps(x, y), 0x93)", f806, 1, 128},
  {"128:_mm_shuffle_ps(_mm_hsub_ps(x, y), x, 0x93)", f807, 1, 128},
  {"128:_mm_shuffle_ps(y, _mm_hsub_ps(x, y), 0x93)", f808, 1, 128},
  {"128:_mm_shuffle_ps(_mm_shuffle_ps(x, y, 0x1b), y, 0x93)", f809, 1, 128},
  {"128:_mm_shuffle_ps(x, _mm_shuffle_ps(x, y, 0x1b), 0x93)", f810, 1, 128},
  {"128:_mm_shuffle_ps(_mm_shuffle_ps(x, y, 0x1b), x, 0x93)", f811, 1, 128},
  {"128:_mm_shuffle_ps(y, _mm_shuffle_ps(x, y, 0x1b), 0x93)", f812, 1, 128},
  {"128:_mm_shuffle_ps(_mm_shuffle_ps(x, y, 0x39), y, 0x93)", f813, 1, 128},
  {"128:_mm_shuffle_ps(x, _mm_shuffle_ps(x, y, 0x39), 0x93)", f814, 1, 128},
  {"128:_mm_shuffle_ps(_mm_shuffle_ps(x, y, 0x39), x, 0x93)", f815, 1, 128},
  {"128:_mm_shuffle_ps(y, _mm_shuffle_ps(x, y, 0x39), 0x93)", f816, 1, 128},
  {"128:_mm_shuffle_ps(_mm_shuffle_ps(x, y, 0x93), y, 0x93)", f817, 1, 128},
  {"128:_mm_shuffle_ps(x, _mm_shuffle_ps(x, y, 0x93), 0x93)", f818, 1, 128},
  {"128:_mm_shuffle_ps(_mm_shuffle_ps(x, y, 0x93), x, 0x93)", f819, 1, 128},
  {"128:_mm_shuffle_ps(y, _mm_shuffle_ps(x, y, 0x93), 0x93)", f820, 1, 128},
  {"128:_mm_shuffle_ps(_mm_shuffle_ps(x, y, 0x4e), y, 0x93)", f821, 1, 128},
  {"128:_mm_shuffle_ps(x, _mm_shuffle_ps(x, y, 0x4e), 0x93)", f822, 1, 128},
  {"128:_mm_shuffle_ps(_mm_shuffle_ps(x, y, 0x4e), x, 0x93)", f823, 1, 128},
  {"128:_mm_shuffle_ps(y, _mm_shuffle_ps(x, y, 0x4e), 0x93)", f824, 1, 128},
  {"128:_mm_shuffle_ps(_mm_add_ps(x, y), y, 0x4e)", f825, 1, 128},
  {"128:_mm_shuffle_ps(x, _mm_add_ps(x, y), 0x4e)", f826, 1, 128},
  {"128:_mm_shuffle_ps(_mm_add_ps(x, y), x, 0x4e)", f827, 1, 128},
  {"128:_mm_shuffle_ps(y, _mm_add_ps(x, y), 0x4e)", f828, 1, 128},
  {"128:_mm_shuffle_ps(_mm_sub_ps(x, y), y, 0x4e)", f829, 1, 128},
  {"128:_mm_shuffle_ps(x, _mm_sub_ps(x, y), 0x4e)", f830, 1, 128},
  {"128:_mm_shuffle_ps(_mm_sub_ps(x, y), x, 0x4e)", f831, 1, 128},
  {"128:_mm_shuffle_ps(y, _mm_sub_ps(x, y), 0x4e)", f832, 1, 128},
  {"128:_mm_shuffle_ps(_mm_mul_ps(x, y), y, 0x4e)", f833, 1, 128},
  {"128:_mm_shuffle_ps(x, _mm_mul_ps(x, y), 0x4e)", f834, 1, 128},
  {"128:_mm_shuffle_ps(_mm_mul_ps(x, y), x, 0x4e)", f835, 1, 128},
  {"128:_mm_shuffle_ps(y, _mm_mul_ps(x, y), 0x4e)", f836, 1, 128},
  {"128:_mm_shuffle_ps(_mm_div_ps(x, y), y, 0x4e)", f837, 1, 128},
  {"128:_mm_shuffle_ps(x, _mm_div_ps(x, y), 0x4e)", f838, 1, 128},
  {"128:_mm_shuffle_ps(_mm_div_ps(x, y), x, 0x4e)", f839, 1, 128},
  {"128:_mm_shuffle_ps(y, _mm_div_ps(x, y), 0x4e)", f840, 1, 128},
  {"128:_mm_shuffle_ps(_mm_min_ps(x, y), y, 0x4e)", f841, 1, 128},
  {"128:_mm_shuffle_ps(x, _mm_min_ps(x, y), 0x4e)", f842, 1, 128},
  {"128:_mm_shuffle_ps(_mm_min_ps(x, y), x, 0x4e)", f843, 1, 128},
  {"128:_mm_shuffle_ps(y, _mm_min_ps(x, y), 0x4e)", f844, 1, 128},
  {"128:_mm_shuffle_ps(_mm_max_ps(x, y), y, 0x4e)", f845, 1, 128},
  {"128:_mm_shuffle_ps(x, _mm_max_ps(x, y), 0x4e)", f846, 1, 128},
  {"128:_mm_shuffle_ps(_mm_max_ps(x, y), x, 0x4e)", f847, 1, 128},
  {"128:_mm_shuffle_ps(y, _mm_max_ps(x, y), 0x4e)", f848, 1, 128},
  {"128:_mm_shuffle_ps(_mm_and_ps(x, y), y, 0x4e)", f849, 1, 128},
  {"128:_mm_shuffle_ps(x, _mm_and_ps(x, y), 0x4e)", f850, 1, 128},
  {"128:_mm_shuffle_ps(_mm_and_ps(x, y), x, 0x4e)", f851, 1, 128},
  {"128:_mm_shuffle_ps(y, _mm_and_ps(x, y), 0x4e)", f852, 1, 128},
  {"128:_mm_shuffle_ps(_mm_or_ps(x, y), y, 0x4e)", f853, 1, 128},
  {"128:_mm_shuffle_ps(x, _mm_or_ps(x, y), 0x4e)", f854, 1, 128},
  {"128:_mm_shuffle_ps(_mm_or_ps(x, y), x, 0x4e)", f855, 1, 128},
  {"128:_mm_shuffle_ps(y, _mm_or_ps(x, y), 0x4e)", f856, 1, 128},
  {"128:_mm_shuffle_ps(_mm_xor_ps(x, y), y, 0x4e)", f857, 1, 128},
  {"128:_mm_shuffle_ps(x, _mm_xor_ps(x, y), 0x4e)", f858, 1, 128},
  {"128:_mm_shuffle_ps(_mm_xor_ps(x, y), x, 0x4e)", f859, 1, 128},
  {"128:_mm_shuffle_ps(y, _mm_xor_ps(x, y), 0x4e)", f860, 1, 128},
  {"128:_mm_shuffle_ps(_mm_andnot_ps(x, y), y, 0x4e)", f861, 1, 128},
  {"128:_mm_shuffle_ps(x, _mm_andnot_ps(x, y), 0x4e)", f862, 1, 128},
  {"128:_mm_shuffle_ps(_mm_andnot_ps(x, y), x, 0x4e)", f863, 1, 128},
  {"128:_mm_shuffle_ps(y, _mm_andnot_ps(x, y), 0x4e)", f864, 1, 128},
  {"128:_mm_shuffle_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), y, 0x4e)", f865, 1, 128},
  {"128:_mm_shuffle_ps(x, _mm_cmp_ps(x, y, _CMP_EQ_OQ), 0x4e)", f866, 1, 128},
  {"128:_mm_shuffle_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), x, 0x4e)", f867, 1, 128},
  {"128:_mm_shuffle_ps(y, _mm_cmp_ps(x, y, _CMP_EQ_OQ), 0x4e)", f868, 1, 128},
  {"128:_mm_shuffle_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), y, 0x4e)", f869, 1, 128},
  {"128:_mm_shuffle_ps(x, _mm_cmp_ps(x, y, _CMP_LT_OS), 0x4e)", f870, 1, 128},
  {"128:_mm_shuffle_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), x, 0x4e)", f871, 1, 128},
  {"128:_mm_shuffle_ps(y, _mm_cmp_ps(x, y, _CMP_LT_OS), 0x4e)", f872, 1, 128},
  {"128:_mm_shuffle_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), y, 0x4e)", f873, 1, 128},
  {"128:_mm_shuffle_ps(x, _mm_cmp_ps(x, y, _CMP_LE_OS), 0x4e)", f874, 1, 128},
  {"128:_mm_shuffle_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), x, 0x4e)", f875, 1, 128},
  {"128:_mm_shuffle_ps(y, _mm_cmp_ps(x, y, _CMP_LE_OS), 0x4e)", f876, 1, 128},
  {"128:_mm_shuffle_ps(_mm_cmp_ps(x, y, _CMP_NEQ_UQ), y, 0x4e)", f877, 1, 128},
  {"128:_mm_shuffle_ps(x, _mm_cmp_ps(x, y, _CMP_NEQ_UQ), 0x4e)", f878, 1, 128},
  {"128:_mm_shuffle_ps(_mm_cmp_ps(x, y, _CMP_NEQ_UQ), x, 0x4e)", f879, 1, 128},
  {"128:_mm_shuffle_ps(y, _mm_cmp_ps(x, y, _CMP_NEQ_UQ), 0x4e)", f880, 1, 128},
  {"128:_mm_shuffle_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), y, 0x4e)", f881, 1, 128},
  {"128:_mm_shuffle_ps(x, _mm_cmp_ps(x, y, _CMP_UNORD_Q), 0x4e)", f882, 1, 128},
  {"128:_mm_shuffle_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), x, 0x4e)", f883, 1, 128},
  {"128:_mm_shuffle_ps(y, _mm_cmp_ps(x, y, _CMP_UNORD_Q), 0x4e)", f884, 1, 128},
  {"128:_mm_shuffle_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), y, 0x4e)", f885, 1, 128},
  {"128:_mm_shuffle_ps(x, _mm_cmp_ps(x, y, _CMP_NLT_US), 0x4e)", f886, 1, 128},
  {"128:_mm_shuffle_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), x, 0x4e)", f887, 1, 128},
  {"128:_mm_shuffle_ps(y, _mm_cmp_ps(x, y, _CMP_NLT_US), 0x4e)", f888, 1, 128},
  {"128:_mm_shuffle_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), y, 0x4e)", f889, 1, 128},
  {"128:_mm_shuffle_ps(x, _mm_cmp_ps(x, y, _CMP_GT_OS), 0x4e)", f890, 1, 128},
  {"128:_mm_shuffle_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), x, 0x4e)", f891, 1, 128},
  {"128:_mm_shuffle_ps(y, _mm_cmp_ps(x, y, _CMP_GT_OS), 0x4e)", f892, 1, 128},
  {"128:_mm_shuffle_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LT_OS)), y, 0x4e)", f893, 1, 128},
  {"128:_mm_shuffle_ps(x, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LT_OS)), 0x4e)", f894, 1, 128},
  {"128:_mm_shuffle_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LT_OS)), x, 0x4e)", f895, 1, 128},
  {"128:_mm_shuffle_ps(y, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LT_OS)), 0x4e)", f896, 1, 128},
  {"128:_mm_shuffle_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LT_OS)), y, 0x4e)", f897, 1, 128},
  {"128:_mm_shuffle_ps(x, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LT_OS)), 0x4e)", f898, 1, 128},
  {"128:_mm_shuffle_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LT_OS)), x, 0x4e)", f899, 1, 128},
  {"128:_mm_shuffle_ps(y, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LT_OS)), 0x4e)", f900, 1, 128},
  {"128:_mm_shuffle_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), y)), y, 0x4e)", f901, 1, 128},
  {"128:_mm_shuffle_ps(x, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), y)), 0x4e)", f902, 1, 128},
  {"128:_mm_shuffle_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), y)), x, 0x4e)", f903, 1, 128},
  {"128:_mm_shuffle_ps(y, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), y)), 0x4e)", f904, 1, 128},
  {"128:_mm_shuffle_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LE_OS)), y, 0x4e)", f905, 1, 128},
  {"128:_mm_shuffle_ps(x, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LE_OS)), 0x4e)", f906, 1, 128},
  {"128:_mm_shuffle_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LE_OS)), x, 0x4e)", f907, 1, 128},
  {"128:_mm_shuffle_ps(y, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LE_OS)), 0x4e)", f908, 1, 128},
  {"128:_mm_shuffle_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LE_OS)), y, 0x4e)", f909, 1, 128},
  {"128:_mm_shuffle_ps(x, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LE_OS)), 0x4e)", f910, 1, 128},
  {"128:_mm_shuffle_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LE_OS)), x, 0x4e)", f911, 1, 128},
  {"128:_mm_shuffle_ps(y, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LE_OS)), 0x4e)", f912, 1, 128},
  {"128:_mm_shuffle_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), y)), y, 0x4e)", f913, 1, 128},
  {"128:_mm_shuffle_ps(x, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), y)), 0x4e)", f914, 1, 128},
  {"128:_mm_shuffle_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), y)), x, 0x4e)", f915, 1, 128},
  {"128:_mm_shuffle_ps(y, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), y)), 0x4e)", f916, 1, 128},
  {"128:_mm_shuffle_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_GT_OS)), y, 0x4e)", f917, 1, 128},
  {"128:_mm_shuffle_ps(x, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_GT_OS)), 0x4e)", f918, 1, 128},
  {"128:_mm_shuffle_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_GT_OS)), x, 0x4e)", f919, 1, 128},
  {"128:_mm_shuffle_ps(y, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_GT_OS)), 0x4e)", f920, 1, 128},
  {"128:_mm_shuffle_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_GT_OS)), y, 0x4e)", f921, 1, 128},
  {"128:_mm_shuffle_ps(x, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_GT_OS)), 0x4e)", f922, 1, 128},
  {"128:_mm_shuffle_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_GT_OS)), x, 0x4e)", f923, 1, 128},
  {"128:_mm_shuffle_ps(y, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_GT_OS)), 0x4e)", f924, 1, 128},
  {"128:_mm_shuffle_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), y)), y, 0x4e)", f925, 1, 128},
  {"128:_mm_shuffle_ps(x, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), y)), 0x4e)", f926, 1, 128},
  {"128:_mm_shuffle_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), y)), x, 0x4e)", f927, 1, 128},
  {"128:_mm_shuffle_ps(y, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), y)), 0x4e)", f928, 1, 128},
  {"128:_mm_shuffle_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_NLT_US)), y, 0x4e)", f929, 1, 128},
  {"128:_mm_shuffle_ps(x, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_NLT_US)), 0x4e)", f930, 1, 128},
  {"128:_mm_shuffle_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_NLT_US)), x, 0x4e)", f931, 1, 128},
  {"128:_mm_shuffle_ps(y, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_NLT_US)), 0x4e)", f932, 1, 128},
  {"128:_mm_shuffle_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_NLT_US)), y, 0x4e)", f933, 1, 128},
  {"128:_mm_shuffle_ps(x, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_NLT_US)), 0x4e)", f934, 1, 128},
  {"128:_mm_shuffle_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_NLT_US)), x, 0x4e)", f935, 1, 128},
  {"128:_mm_shuffle_ps(y, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_NLT_US)), 0x4e)", f936, 1, 128},
  {"128:_mm_shuffle_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), y)), y, 0x4e)", f937, 1, 128},
  {"128:_mm_shuffle_ps(x, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), y)), 0x4e)", f938, 1, 128},
  {"128:_mm_shuffle_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), y)), x, 0x4e)", f939, 1, 128},
  {"128:_mm_shuffle_ps(y, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), y)), 0x4e)", f940, 1, 128},
  {"128:_mm_shuffle_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_EQ_OQ)), y, 0x4e)", f941, 1, 128},
  {"128:_mm_shuffle_ps(x, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_EQ_OQ)), 0x4e)", f942, 1, 128},
  {"128:_mm_shuffle_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_EQ_OQ)), x, 0x4e)", f943, 1, 128},
  {"128:_mm_shuffle_ps(y, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_EQ_OQ)), 0x4e)", f944, 1, 128},
  {"128:_mm_shuffle_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_EQ_OQ)), y, 0x4e)", f945, 1, 128},
  {"128:_mm_shuffle_ps(x, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_EQ_OQ)), 0x4e)", f946, 1, 128},
  {"128:_mm_shuffle_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_EQ_OQ)), x, 0x4e)", f947, 1, 128},
  {"128:_mm_shuffle_ps(y, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_EQ_OQ)), 0x4e)", f948, 1, 128},
  {"128:_mm_shuffle_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), y)), y, 0x4e)", f949, 1, 128},
  {"128:_mm_shuffle_ps(x, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), y)), 0x4e)", f950, 1, 128},
  {"128:_mm_shuffle_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), y)), x, 0x4e)", f951, 1, 128},
  {"128:_mm_shuffle_ps(y, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), y)), 0x4e)", f952, 1, 128},
  {"128:_mm_shuffle_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_UNORD_Q)), y, 0x4e)", f953, 1, 128},
  {"128:_mm_shuffle_ps(x, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_UNORD_Q)), 0x4e)", f954, 1, 128},
  {"128:_mm_shuffle_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_UNORD_Q)), x, 0x4e)", f955, 1, 128},
  {"128:_mm_shuffle_ps(y, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_UNORD_Q)), 0x4e)", f956, 1, 128},
  {"128:_mm_shuffle_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_UNORD_Q)), y, 0x4e)", f957, 1, 128},
  {"128:_mm_shuffle_ps(x, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_UNORD_Q)), 0x4e)", f958, 1, 128},
  {"128:_mm_shuffle_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_UNORD_Q)), x, 0x4e)", f959, 1, 128},
  {"128:_mm_shuffle_ps(y, _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_UNORD_Q)), 0x4e)", f960, 1, 128},
  {"128:_mm_shuffle_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), y)), y, 0x4e)", f961, 1, 128},
  {"128:_mm_shuffle_ps(x, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), y)), 0x4e)", f962, 1, 128},
  {"128:_mm_shuffle_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), y)), x, 0x4e)", f963, 1, 128},
  {"128:_mm_shuffle_ps(y, _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), y)), 0x4e)", f964, 1, 128},
  {"128:_mm_shuffle_ps(_mm_unpacklo_ps(x, y), y, 0x4e)", f965, 1, 128},
  {"128:_mm_shuffle_ps(x, _mm_unpacklo_ps(x, y), 0x4e)", f966, 1, 128},
  {"128:_mm_shuffle_ps(_mm_unpacklo_ps(x, y), x, 0x4e)", f967, 1, 128},
  {"128:_mm_shuffle_ps(y, _mm_unpacklo_ps(x, y), 0x4e)", f968, 1, 128},
  {"128:_mm_shuffle_ps(_mm_unpackhi_ps(x, y), y, 0x4e)", f969, 1, 128},
  {"128:_mm_shuffle_ps(x, _mm_unpackhi_ps(x, y), 0x4e)", f970, 1, 128},
  {"128:_mm_shuffle_ps(_mm_unpackhi_ps(x, y), x, 0x4e)", f971, 1, 128},
  {"128:_mm_shuffle_ps(y, _mm_unpackhi_ps(x, y), 0x4e)", f972, 1, 128},
  {"128:_mm_shuffle_ps(_mm_hadd_ps(x, y), y, 0x4e)", f973, 1, 128},
  {"128:_mm_shuffle_ps(x, _mm_hadd_ps(x, y), 0x4e)", f974, 1, 128},
  {"128:_mm_shuffle_ps(_mm_hadd_ps(x, y), x, 0x4e)", f975, 1, 128},
  {"128:_mm_shuffle_ps(y, _mm_hadd_ps(x, y), 0x4e)", f976, 1, 128},
  {"128:_mm_shuffle_ps(_mm_hsub_ps(x, y), y, 0x4e)", f977, 1, 128},
  {"128:_mm_shuffle_ps(x, _mm_hsub_ps(x, y), 0x4e)", f978, 1, 128},
  {"128:_mm_shuffle_ps(_mm_hsub_ps(x, y), x, 0x4e)", f979, 1, 128},
  {"128:_mm_shuffle_ps(y, _mm_hsub_ps(x, y), 0x4e)", f980, 1, 128},
  {"128:_mm_shuffle_ps(_mm_shuffle_ps(x, y, 0x1b), y, 0x4e)", f981, 1, 128},
  {"128:_mm_shuffle_ps(x, _mm_shuffle_ps(x, y, 0x1b), 0x4e)", f982, 1, 128},
  {"128:_mm_shuffle_ps(_mm_shuffle_ps(x, y, 0x1b), x, 0x4e)", f983, 1, 128},
  {"128:_mm_shuffle_ps(y, _mm_shuffle_ps(x, y, 0x1b), 0x4e)", f984, 1, 128},
  {"128:_mm_shuffle_ps(_mm_shuffle_ps(x, y, 0x39), y, 0x4e)", f985, 1, 128},
  {"128:_mm_shuffle_ps(x, _mm_shuffle_ps(x, y, 0x39), 0x4e)", f986, 1, 128},
  {"128:_mm_shuffle_ps(_mm_shuffle_ps(x, y, 0x39), x, 0x4e)", f987, 1, 128},
  {"128:_mm_shuffle_ps(y, _mm_shuffle_ps(x, y, 0x39), 0x4e)", f988, 1, 128},
  {"128:_mm_shuffle_ps(_mm_shuffle_ps(x, y, 0x93), y, 0x4e)", f989, 1, 128},
  {"128:_mm_shuffle_ps(x, _mm_shuffle_ps(x, y, 0x93), 0x4e)", f990, 1, 128},
  {"128:_mm_shuffle_ps(_mm_shuffle_ps(x, y, 0x93), x, 0x4e)", f991, 1, 128},
  {"128:_mm_shuffle_ps(y, _mm_shuffle_ps(x, y, 0x93), 0x4e)", f992, 1, 128},
  {"128:_mm_shuffle_ps(_mm_shuffle_ps(x, y, 0x4e), y, 0x4e)", f993, 1, 128},
  {"128:_mm_shuffle_ps(x, _mm_shuffle_ps(x, y, 0x4e), 0x4e)", f994, 1, 128},
  {"128:_mm_shuffle_ps(_mm_shuffle_ps(x, y, 0x4e), x, 0x4e)", f995, 1, 128},
  {"128:_mm_shuffle_ps(y, _mm_shuffle_ps(x, y, 0x4e), 0x4e)", f996, 1, 128},
  {"128:_mm_sqrt_pd(_mm_sqrt_pd(x))", f997, 2, 128},
  {"128:_mm_sqrt_pd(_mm_xor_pd(x, _mm_set1_pd(-0.0)))", f998, 2, 128},
  {"128:_mm_sqrt_pd(_mm_andnot_pd(_mm_set1_pd(-0.0), x))", f999, 2, 128},
  {"128:_mm_sqrt_pd(_mm_sub_pd(_mm_setzero_pd(), x))", f1000, 2, 128},
  {"128:_mm_sqrt_pd(_mm_mul_pd(x, _mm_set1_pd(-1.0)))", f1001, 2, 128},
  {"128:_mm_sqrt_pd(_mm_floor_pd(x))", f1002, 2, 128},
  {"128:_mm_sqrt_pd(_mm_ceil_pd(x))", f1003, 2, 128},
  {"128:_mm_sqrt_pd(_mm_round_pd(x, _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC))", f1004, 2, 128},
  {"128:_mm_sqrt_pd(_mm_permute_pd(x, 0x5))", f1005, 2, 128},
  {"128:_mm_sqrt_pd(_mm_permute_pd(x, 0xa))", f1006, 2, 128},
  {"128:_mm_sqrt_pd(_mm_permute_pd(x, 0x3))", f1007, 2, 128},
  {"128:_mm_xor_pd(_mm_sqrt_pd(x), _mm_set1_pd(-0.0))", f1008, 2, 128},
  {"128:_mm_xor_pd(_mm_xor_pd(x, _mm_set1_pd(-0.0)), _mm_set1_pd(-0.0))", f1009, 2, 128},
  {"128:_mm_xor_pd(_mm_andnot_pd(_mm_set1_pd(-0.0), x), _mm_set1_pd(-0.0))", f1010, 2, 128},
  {"128:_mm_xor_pd(_mm_sub_pd(_mm_setzero_pd(), x), _mm_set1_pd(-0.0))", f1011, 2, 128},
  {"128:_mm_xor_pd(_mm_mul_pd(x, _mm_set1_pd(-1.0)), _mm_set1_pd(-0.0))", f1012, 2, 128},
  {"128:_mm_xor_pd(_mm_floor_pd(x), _mm_set1_pd(-0.0))", f1013, 2, 128},
  {"128:_mm_xor_pd(_mm_ceil_pd(x), _mm_set1_pd(-0.0))", f1014, 2, 128},
  {"128:_mm_xor_pd(_mm_round_pd(x, _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC), _mm_set1_pd(-0.0))", f1015, 2, 128},
  {"128:_mm_xor_pd(_mm_permute_pd(x, 0x5), _mm_set1_pd(-0.0))", f1016, 2, 128},
  {"128:_mm_xor_pd(_mm_permute_pd(x, 0xa), _mm_set1_pd(-0.0))", f1017, 2, 128},
  {"128:_mm_xor_pd(_mm_permute_pd(x, 0x3), _mm_set1_pd(-0.0))", f1018, 2, 128},
  {"128:_mm_andnot_pd(_mm_set1_pd(-0.0), _mm_sqrt_pd(x))", f1019, 2, 128},
  {"128:_mm_andnot_pd(_mm_set1_pd(-0.0), _mm_xor_pd(x, _mm_set1_pd(-0.0)))", f1020, 2, 128},
  {"128:_mm_andnot_pd(_mm_set1_pd(-0.0), _mm_andnot_pd(_mm_set1_pd(-0.0), x))", f1021, 2, 128},
  {"128:_mm_andnot_pd(_mm_set1_pd(-0.0), _mm_sub_pd(_mm_setzero_pd(), x))", f1022, 2, 128},
  {"128:_mm_andnot_pd(_mm_set1_pd(-0.0), _mm_mul_pd(x, _mm_set1_pd(-1.0)))", f1023, 2, 128},
  {"128:_mm_andnot_pd(_mm_set1_pd(-0.0), _mm_floor_pd(x))", f1024, 2, 128},
  {"128:_mm_andnot_pd(_mm_set1_pd(-0.0), _mm_ceil_pd(x))", f1025, 2, 128},
  {"128:_mm_andnot_pd(_mm_set1_pd(-0.0), _mm_round_pd(x, _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC))", f1026, 2, 128},
  {"128:_mm_andnot_pd(_mm_set1_pd(-0.0), _mm_permute_pd(x, 0x5))", f1027, 2, 128},
  {"128:_mm_andnot_pd(_mm_set1_pd(-0.0), _mm_permute_pd(x, 0xa))", f1028, 2, 128},
  {"128:_mm_andnot_pd(_mm_set1_pd(-0.0), _mm_permute_pd(x, 0x3))", f1029, 2, 128},
  {"128:_mm_sub_pd(_mm_setzero_pd(), _mm_sqrt_pd(x))", f1030, 2, 128},
  {"128:_mm_sub_pd(_mm_setzero_pd(), _mm_xor_pd(x, _mm_set1_pd(-0.0)))", f1031, 2, 128},
  {"128:_mm_sub_pd(_mm_setzero_pd(), _mm_andnot_pd(_mm_set1_pd(-0.0), x))", f1032, 2, 128},
  {"128:_mm_sub_pd(_mm_setzero_pd(), _mm_sub_pd(_mm_setzero_pd(), x))", f1033, 2, 128},
  {"128:_mm_sub_pd(_mm_setzero_pd(), _mm_mul_pd(x, _mm_set1_pd(-1.0)))", f1034, 2, 128},
  {"128:_mm_sub_pd(_mm_setzero_pd(), _mm_floor_pd(x))", f1035, 2, 128},
  {"128:_mm_sub_pd(_mm_setzero_pd(), _mm_ceil_pd(x))", f1036, 2, 128},
  {"128:_mm_sub_pd(_mm_setzero_pd(), _mm_round_pd(x, _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC))", f1037, 2, 128},
  {"128:_mm_sub_pd(_mm_setzero_pd(), _mm_permute_pd(x, 0x5))", f1038, 2, 128},
  {"128:_mm_sub_pd(_mm_setzero_pd(), _mm_permute_pd(x, 0xa))", f1039, 2, 128},
  {"128:_mm_sub_pd(_mm_setzero_pd(), _mm_permute_pd(x, 0x3))", f1040, 2, 128},
  {"128:_mm_mul_pd(_mm_sqrt_pd(x), _mm_set1_pd(-1.0))", f1041, 2, 128},
  {"128:_mm_mul_pd(_mm_xor_pd(x, _mm_set1_pd(-0.0)), _mm_set1_pd(-1.0))", f1042, 2, 128},
  {"128:_mm_mul_pd(_mm_andnot_pd(_mm_set1_pd(-0.0), x), _mm_set1_pd(-1.0))", f1043, 2, 128},
  {"128:_mm_mul_pd(_mm_sub_pd(_mm_setzero_pd(), x), _mm_set1_pd(-1.0))", f1044, 2, 128},
  {"128:_mm_mul_pd(_mm_mul_pd(x, _mm_set1_pd(-1.0)), _mm_set1_pd(-1.0))", f1045, 2, 128},
  {"128:_mm_mul_pd(_mm_floor_pd(x), _mm_set1_pd(-1.0))", f1046, 2, 128},
  {"128:_mm_mul_pd(_mm_ceil_pd(x), _mm_set1_pd(-1.0))", f1047, 2, 128},
  {"128:_mm_mul_pd(_mm_round_pd(x, _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC), _mm_set1_pd(-1.0))", f1048, 2, 128},
  {"128:_mm_mul_pd(_mm_permute_pd(x, 0x5), _mm_set1_pd(-1.0))", f1049, 2, 128},
  {"128:_mm_mul_pd(_mm_permute_pd(x, 0xa), _mm_set1_pd(-1.0))", f1050, 2, 128},
  {"128:_mm_mul_pd(_mm_permute_pd(x, 0x3), _mm_set1_pd(-1.0))", f1051, 2, 128},
  {"128:_mm_floor_pd(_mm_sqrt_pd(x))", f1052, 2, 128},
  {"128:_mm_floor_pd(_mm_xor_pd(x, _mm_set1_pd(-0.0)))", f1053, 2, 128},
  {"128:_mm_floor_pd(_mm_andnot_pd(_mm_set1_pd(-0.0), x))", f1054, 2, 128},
  {"128:_mm_floor_pd(_mm_sub_pd(_mm_setzero_pd(), x))", f1055, 2, 128},
  {"128:_mm_floor_pd(_mm_mul_pd(x, _mm_set1_pd(-1.0)))", f1056, 2, 128},
  {"128:_mm_floor_pd(_mm_floor_pd(x))", f1057, 2, 128},
  {"128:_mm_floor_pd(_mm_ceil_pd(x))", f1058, 2, 128},
  {"128:_mm_floor_pd(_mm_round_pd(x, _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC))", f1059, 2, 128},
  {"128:_mm_floor_pd(_mm_permute_pd(x, 0x5))", f1060, 2, 128},
  {"128:_mm_floor_pd(_mm_permute_pd(x, 0xa))", f1061, 2, 128},
  {"128:_mm_floor_pd(_mm_permute_pd(x, 0x3))", f1062, 2, 128},
  {"128:_mm_ceil_pd(_mm_sqrt_pd(x))", f1063, 2, 128},
  {"128:_mm_ceil_pd(_mm_xor_pd(x, _mm_set1_pd(-0.0)))", f1064, 2, 128},
  {"128:_mm_ceil_pd(_mm_andnot_pd(_mm_set1_pd(-0.0), x))", f1065, 2, 128},
  {"128:_mm_ceil_pd(_mm_sub_pd(_mm_setzero_pd(), x))", f1066, 2, 128},
  {"128:_mm_ceil_pd(_mm_mul_pd(x, _mm_set1_pd(-1.0)))", f1067, 2, 128},
  {"128:_mm_ceil_pd(_mm_floor_pd(x))", f1068, 2, 128},
  {"128:_mm_ceil_pd(_mm_ceil_pd(x))", f1069, 2, 128},
  {"128:_mm_ceil_pd(_mm_round_pd(x, _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC))", f1070, 2, 128},
  {"128:_mm_ceil_pd(_mm_permute_pd(x, 0x5))", f1071, 2, 128},
  {"128:_mm_ceil_pd(_mm_permute_pd(x, 0xa))", f1072, 2, 128},
  {"128:_mm_ceil_pd(_mm_permute_pd(x, 0x3))", f1073, 2, 128},
  {"128:_mm_round_pd(_mm_sqrt_pd(x), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)", f1074, 2, 128},
  {"128:_mm_round_pd(_mm_xor_pd(x, _mm_set1_pd(-0.0)), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)", f1075, 2, 128},
  {"128:_mm_round_pd(_mm_andnot_pd(_mm_set1_pd(-0.0), x), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)", f1076, 2, 128},
  {"128:_mm_round_pd(_mm_sub_pd(_mm_setzero_pd(), x), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)", f1077, 2, 128},
  {"128:_mm_round_pd(_mm_mul_pd(x, _mm_set1_pd(-1.0)), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)", f1078, 2, 128},
  {"128:_mm_round_pd(_mm_floor_pd(x), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)", f1079, 2, 128},
  {"128:_mm_round_pd(_mm_ceil_pd(x), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)", f1080, 2, 128},
  {"128:_mm_round_pd(_mm_round_pd(x, _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)", f1081, 2, 128},
  {"128:_mm_round_pd(_mm_permute_pd(x, 0x5), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)", f1082, 2, 128},
  {"128:_mm_round_pd(_mm_permute_pd(x, 0xa), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)", f1083, 2, 128},
  {"128:_mm_round_pd(_mm_permute_pd(x, 0x3), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)", f1084, 2, 128},
  {"128:_mm_permute_pd(_mm_sqrt_pd(x), 0x5)", f1085, 2, 128},
  {"128:_mm_permute_pd(_mm_xor_pd(x, _mm_set1_pd(-0.0)), 0x5)", f1086, 2, 128},
  {"128:_mm_permute_pd(_mm_andnot_pd(_mm_set1_pd(-0.0), x), 0x5)", f1087, 2, 128},
  {"128:_mm_permute_pd(_mm_sub_pd(_mm_setzero_pd(), x), 0x5)", f1088, 2, 128},
  {"128:_mm_permute_pd(_mm_mul_pd(x, _mm_set1_pd(-1.0)), 0x5)", f1089, 2, 128},
  {"128:_mm_permute_pd(_mm_floor_pd(x), 0x5)", f1090, 2, 128},
  {"128:_mm_permute_pd(_mm_ceil_pd(x), 0x5)", f1091, 2, 128},
  {"128:_mm_permute_pd(_mm_round_pd(x, _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC), 0x5)", f1092, 2, 128},
  {"128:_mm_permute_pd(_mm_permute_pd(x, 0x5), 0x5)", f1093, 2, 128},
  {"128:_mm_permute_pd(_mm_permute_pd(x, 0xa), 0x5)", f1094, 2, 128},
  {"128:_mm_permute_pd(_mm_permute_pd(x, 0x3), 0x5)", f1095, 2, 128},
  {"128:_mm_permute_pd(_mm_sqrt_pd(x), 0xa)", f1096, 2, 128},
  {"128:_mm_permute_pd(_mm_xor_pd(x, _mm_set1_pd(-0.0)), 0xa)", f1097, 2, 128},
  {"128:_mm_permute_pd(_mm_andnot_pd(_mm_set1_pd(-0.0), x), 0xa)", f1098, 2, 128},
  {"128:_mm_permute_pd(_mm_sub_pd(_mm_setzero_pd(), x), 0xa)", f1099, 2, 128},
  {"128:_mm_permute_pd(_mm_mul_pd(x, _mm_set1_pd(-1.0)), 0xa)", f1100, 2, 128},
  {"128:_mm_permute_pd(_mm_floor_pd(x), 0xa)", f1101, 2, 128},
  {"128:_mm_permute_pd(_mm_ceil_pd(x), 0xa)", f1102, 2, 128},
  {"128:_mm_permute_pd(_mm_round_pd(x, _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC), 0xa)", f1103, 2, 128},
  {"128:_mm_permute_pd(_mm_permute_pd(x, 0x5), 0xa)", f1104, 2, 128},
  {"128:_mm_permute_pd(_mm_permute_pd(x, 0xa), 0xa)", f1105, 2, 128},
  {"128:_mm_permute_pd(_mm_permute_pd(x, 0x3), 0xa)", f1106, 2, 128},
  {"128:_mm_permute_pd(_mm_sqrt_pd(x), 0x3)", f1107, 2, 128},
  {"128:_mm_permute_pd(_mm_xor_pd(x, _mm_set1_pd(-0.0)), 0x3)", f1108, 2, 128},
  {"128:_mm_permute_pd(_mm_andnot_pd(_mm_set1_pd(-0.0), x), 0x3)", f1109, 2, 128},
  {"128:_mm_permute_pd(_mm_sub_pd(_mm_setzero_pd(), x), 0x3)", f1110, 2, 128},
  {"128:_mm_permute_pd(_mm_mul_pd(x, _mm_set1_pd(-1.0)), 0x3)", f1111, 2, 128},
  {"128:_mm_permute_pd(_mm_floor_pd(x), 0x3)", f1112, 2, 128},
  {"128:_mm_permute_pd(_mm_ceil_pd(x), 0x3)", f1113, 2, 128},
  {"128:_mm_permute_pd(_mm_round_pd(x, _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC), 0x3)", f1114, 2, 128},
  {"128:_mm_permute_pd(_mm_permute_pd(x, 0x5), 0x3)", f1115, 2, 128},
  {"128:_mm_permute_pd(_mm_permute_pd(x, 0xa), 0x3)", f1116, 2, 128},
  {"128:_mm_permute_pd(_mm_permute_pd(x, 0x3), 0x3)", f1117, 2, 128},
  {"128:_mm_sqrt_pd(_mm_sqrt_pd(_mm_sqrt_pd(x)))", f1118, 2, 128},
  {"128:_mm_xor_pd(_mm_xor_pd(_mm_xor_pd(x, _mm_set1_pd(-0.0)), _mm_set1_pd(-0.0)), _mm_set1_pd(-0.0))", f1119, 2, 128},
  {"128:_mm_andnot_pd(_mm_set1_pd(-0.0), _mm_andnot_pd(_mm_set1_pd(-0.0), _mm_andnot_pd(_mm_set1_pd(-0.0), x)))", f1120, 2, 128},
  {"128:_mm_sub_pd(_mm_setzero_pd(), _mm_sub_pd(_mm_setzero_pd(), _mm_sub_pd(_mm_setzero_pd(), x)))", f1121, 2, 128},
  {"128:_mm_mul_pd(_mm_mul_pd(_mm_mul_pd(x, _mm_set1_pd(-1.0)), _mm_set1_pd(-1.0)), _mm_set1_pd(-1.0))", f1122, 2, 128},
  {"128:_mm_floor_pd(_mm_floor_pd(_mm_floor_pd(x)))", f1123, 2, 128},
  {"128:_mm_ceil_pd(_mm_ceil_pd(_mm_ceil_pd(x)))", f1124, 2, 128},
  {"128:_mm_round_pd(_mm_round_pd(_mm_round_pd(x, _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)", f1125, 2, 128},
  {"128:_mm_permute_pd(_mm_permute_pd(_mm_permute_pd(x, 0x5), 0x5), 0x5)", f1126, 2, 128},
  {"128:_mm_permute_pd(_mm_permute_pd(_mm_permute_pd(x, 0xa), 0xa), 0xa)", f1127, 2, 128},
  {"128:_mm_permute_pd(_mm_permute_pd(_mm_permute_pd(x, 0x3), 0x3), 0x3)", f1128, 2, 128},
  {"128:_mm_sqrt_pd(_mm_add_pd(x, y))", f1129, 2, 128},
  {"128:_mm_add_pd(_mm_sqrt_pd(x), y)", f1130, 2, 128},
  {"128:_mm_add_pd(x, _mm_sqrt_pd(y))", f1131, 2, 128},
  {"128:_mm_add_pd(_mm_sqrt_pd(x), _mm_sqrt_pd(y))", f1132, 2, 128},
  {"128:_mm_add_pd(x, _mm_sqrt_pd(x))", f1133, 2, 128},
  {"128:_mm_add_pd(_mm_sqrt_pd(x), x)", f1134, 2, 128},
  {"128:_mm_sqrt_pd(_mm_sub_pd(x, y))", f1135, 2, 128},
  {"128:_mm_sub_pd(_mm_sqrt_pd(x), y)", f1136, 2, 128},
  {"128:_mm_sub_pd(x, _mm_sqrt_pd(y))", f1137, 2, 128},
  {"128:_mm_sub_pd(_mm_sqrt_pd(x), _mm_sqrt_pd(y))", f1138, 2, 128},
  {"128:_mm_sub_pd(x, _mm_sqrt_pd(x))", f1139, 2, 128},
  {"128:_mm_sub_pd(_mm_sqrt_pd(x), x)", f1140, 2, 128},
  {"128:_mm_sqrt_pd(_mm_mul_pd(x, y))", f1141, 2, 128},
  {"128:_mm_mul_pd(_mm_sqrt_pd(x), y)", f1142, 2, 128},
  {"128:_mm_mul_pd(x, _mm_sqrt_pd(y))", f1143, 2, 128},
  {"128:_mm_mul_pd(_mm_sqrt_pd(x), _mm_sqrt_pd(y))", f1144, 2, 128},
  {"128:_mm_mul_pd(x, _mm_sqrt_pd(x))", f1145, 2, 128},
  {"128:_mm_mul_pd(_mm_sqrt_pd(x), x)", f1146, 2, 128},
  {"128:_mm_sqrt_pd(_mm_div_pd(x, y))", f1147, 2, 128},
  {"128:_mm_div_pd(_mm_sqrt_pd(x), y)", f1148, 2, 128},
  {"128:_mm_div_pd(x, _mm_sqrt_pd(y))", f1149, 2, 128},
  {"128:_mm_div_pd(_mm_sqrt_pd(x), _mm_sqrt_pd(y))", f1150, 2, 128},
  {"128:_mm_div_pd(x, _mm_sqrt_pd(x))", f1151, 2, 128},
  {"128:_mm_div_pd(_mm_sqrt_pd(x), x)", f1152, 2, 128},
  {"128:_mm_sqrt_pd(_mm_min_pd(x, y))", f1153, 2, 128},
  {"128:_mm_min_pd(_mm_sqrt_pd(x), y)", f1154, 2, 128},
  {"128:_mm_min_pd(x, _mm_sqrt_pd(y))", f1155, 2, 128},
  {"128:_mm_min_pd(_mm_sqrt_pd(x), _mm_sqrt_pd(y))", f1156, 2, 128},
  {"128:_mm_min_pd(x, _mm_sqrt_pd(x))", f1157, 2, 128},
  {"128:_mm_min_pd(_mm_sqrt_pd(x), x)", f1158, 2, 128},
  {"128:_mm_sqrt_pd(_mm_max_pd(x, y))", f1159, 2, 128},
  {"128:_mm_max_pd(_mm_sqrt_pd(x), y)", f1160, 2, 128},
  {"128:_mm_max_pd(x, _mm_sqrt_pd(y))", f1161, 2, 128},
  {"128:_mm_max_pd(_mm_sqrt_pd(x), _mm_sqrt_pd(y))", f1162, 2, 128},
  {"128:_mm_max_pd(x, _mm_sqrt_pd(x))", f1163, 2, 128},
  {"128:_mm_max_pd(_mm_sqrt_pd(x), x)", f1164, 2, 128},
  {"128:_mm_sqrt_pd(_mm_and_pd(x, y))", f1165, 2, 128},
  {"128:_mm_and_pd(_mm_sqrt_pd(x), y)", f1166, 2, 128},
  {"128:_mm_and_pd(x, _mm_sqrt_pd(y))", f1167, 2, 128},
  {"128:_mm_and_pd(_mm_sqrt_pd(x), _mm_sqrt_pd(y))", f1168, 2, 128},
  {"128:_mm_and_pd(x, _mm_sqrt_pd(x))", f1169, 2, 128},
  {"128:_mm_and_pd(_mm_sqrt_pd(x), x)", f1170, 2, 128},
  {"128:_mm_sqrt_pd(_mm_or_pd(x, y))", f1171, 2, 128},
  {"128:_mm_or_pd(_mm_sqrt_pd(x), y)", f1172, 2, 128},
  {"128:_mm_or_pd(x, _mm_sqrt_pd(y))", f1173, 2, 128},
  {"128:_mm_or_pd(_mm_sqrt_pd(x), _mm_sqrt_pd(y))", f1174, 2, 128},
  {"128:_mm_or_pd(x, _mm_sqrt_pd(x))", f1175, 2, 128},
  {"128:_mm_or_pd(_mm_sqrt_pd(x), x)", f1176, 2, 128},
  {"128:_mm_sqrt_pd(_mm_xor_pd(x, y))", f1177, 2, 128},
  {"128:_mm_xor_pd(_mm_sqrt_pd(x), y)", f1178, 2, 128},
  {"128:_mm_xor_pd(x, _mm_sqrt_pd(y))", f1179, 2, 128},
  {"128:_mm_xor_pd(_mm_sqrt_pd(x), _mm_sqrt_pd(y))", f1180, 2, 128},
  {"128:_mm_xor_pd(x, _mm_sqrt_pd(x))", f1181, 2, 128},
  {"128:_mm_xor_pd(_mm_sqrt_pd(x), x)", f1182, 2, 128},
  {"128:_mm_sqrt_pd(_mm_andnot_pd(x, y))", f1183, 2, 128},
  {"128:_mm_andnot_pd(_mm_sqrt_pd(x), y)", f1184, 2, 128},
  {"128:_mm_andnot_pd(x, _mm_sqrt_pd(y))", f1185, 2, 128},
  {"128:_mm_andnot_pd(_mm_sqrt_pd(x), _mm_sqrt_pd(y))", f1186, 2, 128},
  {"128:_mm_andnot_pd(x, _mm_sqrt_pd(x))", f1187, 2, 128},
  {"128:_mm_andnot_pd(_mm_sqrt_pd(x), x)", f1188, 2, 128},
  {"128:_mm_sqrt_pd(_mm_cmp_pd(x, y, _CMP_EQ_OQ))", f1189, 2, 128},
  {"128:_mm_cmp_pd(_mm_sqrt_pd(x), y, _CMP_EQ_OQ)", f1190, 2, 128},
  {"128:_mm_cmp_pd(x, _mm_sqrt_pd(y), _CMP_EQ_OQ)", f1191, 2, 128},
  {"128:_mm_cmp_pd(_mm_sqrt_pd(x), _mm_sqrt_pd(y), _CMP_EQ_OQ)", f1192, 2, 128},
  {"128:_mm_cmp_pd(x, _mm_sqrt_pd(x), _CMP_EQ_OQ)", f1193, 2, 128},
  {"128:_mm_cmp_pd(_mm_sqrt_pd(x), x, _CMP_EQ_OQ)", f1194, 2, 128},
  {"128:_mm_sqrt_pd(_mm_cmp_pd(x, y, _CMP_LT_OS))", f1195, 2, 128},
  {"128:_mm_cmp_pd(_mm_sqrt_pd(x), y, _CMP_LT_OS)", f1196, 2, 128},
  {"128:_mm_cmp_pd(x, _mm_sqrt_pd(y), _CMP_LT_OS)", f1197, 2, 128},
  {"128:_mm_cmp_pd(_mm_sqrt_pd(x), _mm_sqrt_pd(y), _CMP_LT_OS)", f1198, 2, 128},
  {"128:_mm_cmp_pd(x, _mm_sqrt_pd(x), _CMP_LT_OS)", f1199, 2, 128},
};
extern const int size_31 = 1200;
