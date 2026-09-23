#include "common.h"
static NOINLINE void f0(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_mul_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_LE_OS)), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_mul_pd(y, _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_LE_OS))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f2(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_mul_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_LE_OS)), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f3(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_mul_pd(x, _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_LE_OS))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f4(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_mul_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_LE_OS)), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f5(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_mul_pd(y, _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_LE_OS))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f6(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_mul_pd(_mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_LE_OS), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_LE_OS), y)), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f7(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_mul_pd(x, _mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_LE_OS), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_LE_OS), y))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f8(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_mul_pd(_mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_LE_OS), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_LE_OS), y)), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f9(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_mul_pd(y, _mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_LE_OS), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_LE_OS), y))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f10(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_mul_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_GT_OS)), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f11(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_mul_pd(x, _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_GT_OS))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f12(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_mul_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_GT_OS)), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f13(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_mul_pd(y, _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_GT_OS))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f14(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_mul_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_GT_OS)), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f15(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_mul_pd(x, _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_GT_OS))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f16(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_mul_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_GT_OS)), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f17(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_mul_pd(y, _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_GT_OS))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f18(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_mul_pd(_mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_GT_OS), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_GT_OS), y)), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f19(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_mul_pd(x, _mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_GT_OS), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_GT_OS), y))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f20(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_mul_pd(_mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_GT_OS), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_GT_OS), y)), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f21(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_mul_pd(y, _mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_GT_OS), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_GT_OS), y))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f22(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_mul_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_NLT_US)), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f23(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_mul_pd(x, _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_NLT_US))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f24(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_mul_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_NLT_US)), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f25(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_mul_pd(y, _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_NLT_US))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f26(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_mul_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_NLT_US)), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f27(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_mul_pd(x, _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_NLT_US))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f28(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_mul_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_NLT_US)), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f29(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_mul_pd(y, _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_NLT_US))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f30(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_mul_pd(_mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_NLT_US), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_NLT_US), y)), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f31(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_mul_pd(x, _mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_NLT_US), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_NLT_US), y))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f32(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_mul_pd(_mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_NLT_US), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_NLT_US), y)), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f33(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_mul_pd(y, _mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_NLT_US), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_NLT_US), y))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f34(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_mul_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_EQ_OQ)), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f35(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_mul_pd(x, _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_EQ_OQ))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f36(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_mul_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_EQ_OQ)), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f37(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_mul_pd(y, _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_EQ_OQ))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f38(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_mul_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_EQ_OQ)), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f39(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_mul_pd(x, _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_EQ_OQ))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f40(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_mul_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_EQ_OQ)), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f41(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_mul_pd(y, _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_EQ_OQ))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f42(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_mul_pd(_mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_EQ_OQ), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_EQ_OQ), y)), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f43(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_mul_pd(x, _mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_EQ_OQ), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_EQ_OQ), y))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f44(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_mul_pd(_mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_EQ_OQ), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_EQ_OQ), y)), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f45(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_mul_pd(y, _mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_EQ_OQ), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_EQ_OQ), y))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f46(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_mul_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_UNORD_Q)), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f47(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_mul_pd(x, _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_UNORD_Q))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f48(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_mul_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_UNORD_Q)), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f49(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_mul_pd(y, _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_UNORD_Q))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f50(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_mul_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_UNORD_Q)), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f51(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_mul_pd(x, _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_UNORD_Q))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f52(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_mul_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_UNORD_Q)), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f53(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_mul_pd(y, _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_UNORD_Q))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f54(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_mul_pd(_mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_UNORD_Q), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_UNORD_Q), y)), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f55(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_mul_pd(x, _mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_UNORD_Q), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_UNORD_Q), y))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f56(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_mul_pd(_mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_UNORD_Q), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_UNORD_Q), y)), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f57(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_mul_pd(y, _mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_UNORD_Q), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_UNORD_Q), y))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f58(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_mul_pd(_mm_unpacklo_pd(x, y), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f59(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_mul_pd(x, _mm_unpacklo_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f60(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_mul_pd(_mm_unpacklo_pd(x, y), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f61(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_mul_pd(y, _mm_unpacklo_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f62(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_mul_pd(_mm_unpackhi_pd(x, y), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f63(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_mul_pd(x, _mm_unpackhi_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f64(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_mul_pd(_mm_unpackhi_pd(x, y), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f65(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_mul_pd(y, _mm_unpackhi_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f66(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_mul_pd(_mm_hadd_pd(x, y), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f67(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_mul_pd(x, _mm_hadd_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f68(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_mul_pd(_mm_hadd_pd(x, y), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f69(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_mul_pd(y, _mm_hadd_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f70(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_mul_pd(_mm_hsub_pd(x, y), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f71(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_mul_pd(x, _mm_hsub_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f72(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_mul_pd(_mm_hsub_pd(x, y), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f73(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_mul_pd(y, _mm_hsub_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f74(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_div_pd(_mm_add_pd(x, y), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f75(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_div_pd(x, _mm_add_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f76(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_div_pd(_mm_add_pd(x, y), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f77(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_div_pd(y, _mm_add_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f78(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_div_pd(_mm_sub_pd(x, y), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f79(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_div_pd(x, _mm_sub_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f80(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_div_pd(_mm_sub_pd(x, y), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f81(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_div_pd(y, _mm_sub_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f82(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_div_pd(_mm_mul_pd(x, y), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f83(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_div_pd(x, _mm_mul_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f84(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_div_pd(_mm_mul_pd(x, y), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f85(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_div_pd(y, _mm_mul_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f86(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_div_pd(_mm_div_pd(x, y), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f87(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_div_pd(x, _mm_div_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f88(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_div_pd(_mm_div_pd(x, y), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f89(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_div_pd(y, _mm_div_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f90(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_div_pd(_mm_min_pd(x, y), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f91(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_div_pd(x, _mm_min_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f92(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_div_pd(_mm_min_pd(x, y), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f93(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_div_pd(y, _mm_min_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f94(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_div_pd(_mm_max_pd(x, y), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f95(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_div_pd(x, _mm_max_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f96(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_div_pd(_mm_max_pd(x, y), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f97(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_div_pd(y, _mm_max_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f98(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_div_pd(_mm_and_pd(x, y), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f99(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_div_pd(x, _mm_and_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f100(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_div_pd(_mm_and_pd(x, y), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f101(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_div_pd(y, _mm_and_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f102(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_div_pd(_mm_or_pd(x, y), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f103(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_div_pd(x, _mm_or_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f104(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_div_pd(_mm_or_pd(x, y), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f105(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_div_pd(y, _mm_or_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f106(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_div_pd(_mm_xor_pd(x, y), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f107(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_div_pd(x, _mm_xor_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f108(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_div_pd(_mm_xor_pd(x, y), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f109(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_div_pd(y, _mm_xor_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f110(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_div_pd(_mm_andnot_pd(x, y), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f111(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_div_pd(x, _mm_andnot_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f112(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_div_pd(_mm_andnot_pd(x, y), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f113(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_div_pd(y, _mm_andnot_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f114(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_div_pd(_mm_cmp_pd(x, y, _CMP_EQ_OQ), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f115(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_div_pd(x, _mm_cmp_pd(x, y, _CMP_EQ_OQ)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f116(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_div_pd(_mm_cmp_pd(x, y, _CMP_EQ_OQ), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f117(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_div_pd(y, _mm_cmp_pd(x, y, _CMP_EQ_OQ)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f118(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_div_pd(_mm_cmp_pd(x, y, _CMP_LT_OS), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f119(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_div_pd(x, _mm_cmp_pd(x, y, _CMP_LT_OS)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f120(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_div_pd(_mm_cmp_pd(x, y, _CMP_LT_OS), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f121(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_div_pd(y, _mm_cmp_pd(x, y, _CMP_LT_OS)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f122(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_div_pd(_mm_cmp_pd(x, y, _CMP_LE_OS), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f123(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_div_pd(x, _mm_cmp_pd(x, y, _CMP_LE_OS)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f124(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_div_pd(_mm_cmp_pd(x, y, _CMP_LE_OS), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f125(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_div_pd(y, _mm_cmp_pd(x, y, _CMP_LE_OS)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f126(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_div_pd(_mm_cmp_pd(x, y, _CMP_NEQ_UQ), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f127(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_div_pd(x, _mm_cmp_pd(x, y, _CMP_NEQ_UQ)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f128(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_div_pd(_mm_cmp_pd(x, y, _CMP_NEQ_UQ), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f129(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_div_pd(y, _mm_cmp_pd(x, y, _CMP_NEQ_UQ)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f130(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_div_pd(_mm_cmp_pd(x, y, _CMP_UNORD_Q), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f131(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_div_pd(x, _mm_cmp_pd(x, y, _CMP_UNORD_Q)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f132(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_div_pd(_mm_cmp_pd(x, y, _CMP_UNORD_Q), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f133(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_div_pd(y, _mm_cmp_pd(x, y, _CMP_UNORD_Q)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f134(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_div_pd(_mm_cmp_pd(x, y, _CMP_NLT_US), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f135(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_div_pd(x, _mm_cmp_pd(x, y, _CMP_NLT_US)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f136(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_div_pd(_mm_cmp_pd(x, y, _CMP_NLT_US), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f137(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_div_pd(y, _mm_cmp_pd(x, y, _CMP_NLT_US)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f138(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_div_pd(_mm_cmp_pd(x, y, _CMP_GT_OS), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f139(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_div_pd(x, _mm_cmp_pd(x, y, _CMP_GT_OS)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f140(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_div_pd(_mm_cmp_pd(x, y, _CMP_GT_OS), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f141(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_div_pd(y, _mm_cmp_pd(x, y, _CMP_GT_OS)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f142(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_div_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_LT_OS)), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f143(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_div_pd(x, _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_LT_OS))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f144(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_div_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_LT_OS)), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f145(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_div_pd(y, _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_LT_OS))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f146(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_div_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_LT_OS)), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f147(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_div_pd(x, _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_LT_OS))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f148(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_div_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_LT_OS)), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f149(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_div_pd(y, _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_LT_OS))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f150(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_div_pd(_mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_LT_OS), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_LT_OS), y)), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f151(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_div_pd(x, _mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_LT_OS), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_LT_OS), y))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f152(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_div_pd(_mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_LT_OS), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_LT_OS), y)), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f153(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_div_pd(y, _mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_LT_OS), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_LT_OS), y))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f154(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_div_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_LE_OS)), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f155(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_div_pd(x, _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_LE_OS))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f156(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_div_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_LE_OS)), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f157(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_div_pd(y, _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_LE_OS))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f158(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_div_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_LE_OS)), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f159(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_div_pd(x, _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_LE_OS))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f160(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_div_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_LE_OS)), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f161(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_div_pd(y, _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_LE_OS))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f162(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_div_pd(_mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_LE_OS), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_LE_OS), y)), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f163(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_div_pd(x, _mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_LE_OS), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_LE_OS), y))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f164(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_div_pd(_mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_LE_OS), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_LE_OS), y)), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f165(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_div_pd(y, _mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_LE_OS), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_LE_OS), y))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f166(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_div_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_GT_OS)), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f167(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_div_pd(x, _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_GT_OS))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f168(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_div_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_GT_OS)), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f169(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_div_pd(y, _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_GT_OS))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f170(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_div_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_GT_OS)), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f171(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_div_pd(x, _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_GT_OS))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f172(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_div_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_GT_OS)), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f173(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_div_pd(y, _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_GT_OS))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f174(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_div_pd(_mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_GT_OS), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_GT_OS), y)), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f175(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_div_pd(x, _mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_GT_OS), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_GT_OS), y))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f176(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_div_pd(_mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_GT_OS), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_GT_OS), y)), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f177(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_div_pd(y, _mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_GT_OS), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_GT_OS), y))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f178(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_div_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_NLT_US)), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f179(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_div_pd(x, _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_NLT_US))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f180(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_div_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_NLT_US)), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f181(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_div_pd(y, _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_NLT_US))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f182(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_div_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_NLT_US)), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f183(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_div_pd(x, _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_NLT_US))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f184(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_div_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_NLT_US)), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f185(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_div_pd(y, _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_NLT_US))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f186(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_div_pd(_mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_NLT_US), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_NLT_US), y)), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f187(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_div_pd(x, _mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_NLT_US), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_NLT_US), y))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f188(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_div_pd(_mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_NLT_US), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_NLT_US), y)), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f189(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_div_pd(y, _mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_NLT_US), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_NLT_US), y))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f190(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_div_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_EQ_OQ)), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f191(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_div_pd(x, _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_EQ_OQ))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f192(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_div_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_EQ_OQ)), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f193(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_div_pd(y, _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_EQ_OQ))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f194(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_div_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_EQ_OQ)), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f195(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_div_pd(x, _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_EQ_OQ))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f196(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_div_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_EQ_OQ)), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f197(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_div_pd(y, _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_EQ_OQ))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f198(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_div_pd(_mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_EQ_OQ), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_EQ_OQ), y)), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f199(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_div_pd(x, _mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_EQ_OQ), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_EQ_OQ), y))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f200(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_div_pd(_mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_EQ_OQ), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_EQ_OQ), y)), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f201(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_div_pd(y, _mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_EQ_OQ), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_EQ_OQ), y))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f202(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_div_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_UNORD_Q)), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f203(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_div_pd(x, _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_UNORD_Q))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f204(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_div_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_UNORD_Q)), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f205(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_div_pd(y, _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_UNORD_Q))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f206(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_div_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_UNORD_Q)), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f207(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_div_pd(x, _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_UNORD_Q))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f208(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_div_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_UNORD_Q)), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f209(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_div_pd(y, _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_UNORD_Q))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f210(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_div_pd(_mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_UNORD_Q), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_UNORD_Q), y)), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f211(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_div_pd(x, _mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_UNORD_Q), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_UNORD_Q), y))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f212(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_div_pd(_mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_UNORD_Q), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_UNORD_Q), y)), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f213(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_div_pd(y, _mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_UNORD_Q), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_UNORD_Q), y))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f214(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_div_pd(_mm_unpacklo_pd(x, y), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f215(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_div_pd(x, _mm_unpacklo_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f216(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_div_pd(_mm_unpacklo_pd(x, y), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f217(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_div_pd(y, _mm_unpacklo_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f218(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_div_pd(_mm_unpackhi_pd(x, y), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f219(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_div_pd(x, _mm_unpackhi_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f220(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_div_pd(_mm_unpackhi_pd(x, y), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f221(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_div_pd(y, _mm_unpackhi_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f222(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_div_pd(_mm_hadd_pd(x, y), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f223(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_div_pd(x, _mm_hadd_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f224(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_div_pd(_mm_hadd_pd(x, y), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f225(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_div_pd(y, _mm_hadd_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f226(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_div_pd(_mm_hsub_pd(x, y), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f227(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_div_pd(x, _mm_hsub_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f228(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_div_pd(_mm_hsub_pd(x, y), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f229(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_div_pd(y, _mm_hsub_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f230(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_min_pd(_mm_add_pd(x, y), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f231(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_min_pd(x, _mm_add_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f232(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_min_pd(_mm_add_pd(x, y), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f233(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_min_pd(y, _mm_add_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f234(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_min_pd(_mm_sub_pd(x, y), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f235(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_min_pd(x, _mm_sub_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f236(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_min_pd(_mm_sub_pd(x, y), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f237(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_min_pd(y, _mm_sub_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f238(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_min_pd(_mm_mul_pd(x, y), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f239(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_min_pd(x, _mm_mul_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f240(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_min_pd(_mm_mul_pd(x, y), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f241(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_min_pd(y, _mm_mul_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f242(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_min_pd(_mm_div_pd(x, y), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f243(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_min_pd(x, _mm_div_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f244(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_min_pd(_mm_div_pd(x, y), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f245(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_min_pd(y, _mm_div_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f246(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_min_pd(_mm_min_pd(x, y), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f247(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_min_pd(x, _mm_min_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f248(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_min_pd(_mm_min_pd(x, y), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f249(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_min_pd(y, _mm_min_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f250(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_min_pd(_mm_max_pd(x, y), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f251(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_min_pd(x, _mm_max_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f252(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_min_pd(_mm_max_pd(x, y), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f253(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_min_pd(y, _mm_max_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f254(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_min_pd(_mm_and_pd(x, y), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f255(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_min_pd(x, _mm_and_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f256(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_min_pd(_mm_and_pd(x, y), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f257(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_min_pd(y, _mm_and_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f258(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_min_pd(_mm_or_pd(x, y), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f259(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_min_pd(x, _mm_or_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f260(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_min_pd(_mm_or_pd(x, y), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f261(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_min_pd(y, _mm_or_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f262(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_min_pd(_mm_xor_pd(x, y), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f263(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_min_pd(x, _mm_xor_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f264(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_min_pd(_mm_xor_pd(x, y), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f265(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_min_pd(y, _mm_xor_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f266(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_min_pd(_mm_andnot_pd(x, y), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f267(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_min_pd(x, _mm_andnot_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f268(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_min_pd(_mm_andnot_pd(x, y), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f269(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_min_pd(y, _mm_andnot_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f270(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_min_pd(_mm_cmp_pd(x, y, _CMP_EQ_OQ), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f271(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_min_pd(x, _mm_cmp_pd(x, y, _CMP_EQ_OQ)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f272(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_min_pd(_mm_cmp_pd(x, y, _CMP_EQ_OQ), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f273(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_min_pd(y, _mm_cmp_pd(x, y, _CMP_EQ_OQ)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f274(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_min_pd(_mm_cmp_pd(x, y, _CMP_LT_OS), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f275(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_min_pd(x, _mm_cmp_pd(x, y, _CMP_LT_OS)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f276(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_min_pd(_mm_cmp_pd(x, y, _CMP_LT_OS), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f277(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_min_pd(y, _mm_cmp_pd(x, y, _CMP_LT_OS)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f278(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_min_pd(_mm_cmp_pd(x, y, _CMP_LE_OS), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f279(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_min_pd(x, _mm_cmp_pd(x, y, _CMP_LE_OS)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f280(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_min_pd(_mm_cmp_pd(x, y, _CMP_LE_OS), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f281(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_min_pd(y, _mm_cmp_pd(x, y, _CMP_LE_OS)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f282(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_min_pd(_mm_cmp_pd(x, y, _CMP_NEQ_UQ), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f283(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_min_pd(x, _mm_cmp_pd(x, y, _CMP_NEQ_UQ)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f284(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_min_pd(_mm_cmp_pd(x, y, _CMP_NEQ_UQ), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f285(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_min_pd(y, _mm_cmp_pd(x, y, _CMP_NEQ_UQ)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f286(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_min_pd(_mm_cmp_pd(x, y, _CMP_UNORD_Q), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f287(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_min_pd(x, _mm_cmp_pd(x, y, _CMP_UNORD_Q)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f288(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_min_pd(_mm_cmp_pd(x, y, _CMP_UNORD_Q), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f289(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_min_pd(y, _mm_cmp_pd(x, y, _CMP_UNORD_Q)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f290(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_min_pd(_mm_cmp_pd(x, y, _CMP_NLT_US), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f291(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_min_pd(x, _mm_cmp_pd(x, y, _CMP_NLT_US)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f292(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_min_pd(_mm_cmp_pd(x, y, _CMP_NLT_US), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f293(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_min_pd(y, _mm_cmp_pd(x, y, _CMP_NLT_US)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f294(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_min_pd(_mm_cmp_pd(x, y, _CMP_GT_OS), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f295(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_min_pd(x, _mm_cmp_pd(x, y, _CMP_GT_OS)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f296(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_min_pd(_mm_cmp_pd(x, y, _CMP_GT_OS), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f297(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_min_pd(y, _mm_cmp_pd(x, y, _CMP_GT_OS)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f298(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_min_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_LT_OS)), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f299(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_min_pd(x, _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_LT_OS))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f300(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_min_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_LT_OS)), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f301(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_min_pd(y, _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_LT_OS))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f302(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_min_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_LT_OS)), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f303(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_min_pd(x, _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_LT_OS))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f304(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_min_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_LT_OS)), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f305(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_min_pd(y, _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_LT_OS))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f306(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_min_pd(_mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_LT_OS), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_LT_OS), y)), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f307(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_min_pd(x, _mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_LT_OS), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_LT_OS), y))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f308(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_min_pd(_mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_LT_OS), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_LT_OS), y)), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f309(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_min_pd(y, _mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_LT_OS), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_LT_OS), y))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f310(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_min_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_LE_OS)), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f311(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_min_pd(x, _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_LE_OS))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f312(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_min_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_LE_OS)), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f313(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_min_pd(y, _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_LE_OS))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f314(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_min_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_LE_OS)), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f315(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_min_pd(x, _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_LE_OS))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f316(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_min_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_LE_OS)), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f317(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_min_pd(y, _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_LE_OS))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f318(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_min_pd(_mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_LE_OS), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_LE_OS), y)), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f319(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_min_pd(x, _mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_LE_OS), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_LE_OS), y))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f320(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_min_pd(_mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_LE_OS), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_LE_OS), y)), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f321(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_min_pd(y, _mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_LE_OS), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_LE_OS), y))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f322(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_min_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_GT_OS)), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f323(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_min_pd(x, _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_GT_OS))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f324(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_min_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_GT_OS)), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f325(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_min_pd(y, _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_GT_OS))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f326(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_min_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_GT_OS)), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f327(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_min_pd(x, _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_GT_OS))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f328(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_min_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_GT_OS)), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f329(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_min_pd(y, _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_GT_OS))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f330(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_min_pd(_mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_GT_OS), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_GT_OS), y)), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f331(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_min_pd(x, _mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_GT_OS), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_GT_OS), y))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f332(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_min_pd(_mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_GT_OS), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_GT_OS), y)), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f333(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_min_pd(y, _mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_GT_OS), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_GT_OS), y))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f334(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_min_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_NLT_US)), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f335(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_min_pd(x, _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_NLT_US))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f336(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_min_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_NLT_US)), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f337(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_min_pd(y, _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_NLT_US))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f338(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_min_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_NLT_US)), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f339(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_min_pd(x, _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_NLT_US))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f340(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_min_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_NLT_US)), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f341(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_min_pd(y, _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_NLT_US))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f342(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_min_pd(_mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_NLT_US), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_NLT_US), y)), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f343(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_min_pd(x, _mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_NLT_US), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_NLT_US), y))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f344(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_min_pd(_mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_NLT_US), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_NLT_US), y)), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f345(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_min_pd(y, _mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_NLT_US), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_NLT_US), y))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f346(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_min_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_EQ_OQ)), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f347(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_min_pd(x, _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_EQ_OQ))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f348(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_min_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_EQ_OQ)), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f349(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_min_pd(y, _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_EQ_OQ))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f350(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_min_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_EQ_OQ)), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f351(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_min_pd(x, _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_EQ_OQ))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f352(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_min_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_EQ_OQ)), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f353(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_min_pd(y, _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_EQ_OQ))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f354(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_min_pd(_mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_EQ_OQ), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_EQ_OQ), y)), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f355(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_min_pd(x, _mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_EQ_OQ), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_EQ_OQ), y))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f356(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_min_pd(_mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_EQ_OQ), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_EQ_OQ), y)), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f357(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_min_pd(y, _mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_EQ_OQ), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_EQ_OQ), y))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f358(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_min_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_UNORD_Q)), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f359(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_min_pd(x, _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_UNORD_Q))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f360(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_min_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_UNORD_Q)), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f361(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_min_pd(y, _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_UNORD_Q))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f362(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_min_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_UNORD_Q)), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f363(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_min_pd(x, _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_UNORD_Q))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f364(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_min_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_UNORD_Q)), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f365(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_min_pd(y, _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_UNORD_Q))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f366(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_min_pd(_mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_UNORD_Q), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_UNORD_Q), y)), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f367(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_min_pd(x, _mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_UNORD_Q), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_UNORD_Q), y))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f368(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_min_pd(_mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_UNORD_Q), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_UNORD_Q), y)), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f369(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_min_pd(y, _mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_UNORD_Q), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_UNORD_Q), y))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f370(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_min_pd(_mm_unpacklo_pd(x, y), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f371(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_min_pd(x, _mm_unpacklo_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f372(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_min_pd(_mm_unpacklo_pd(x, y), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f373(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_min_pd(y, _mm_unpacklo_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f374(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_min_pd(_mm_unpackhi_pd(x, y), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f375(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_min_pd(x, _mm_unpackhi_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f376(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_min_pd(_mm_unpackhi_pd(x, y), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f377(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_min_pd(y, _mm_unpackhi_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f378(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_min_pd(_mm_hadd_pd(x, y), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f379(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_min_pd(x, _mm_hadd_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f380(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_min_pd(_mm_hadd_pd(x, y), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f381(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_min_pd(y, _mm_hadd_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f382(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_min_pd(_mm_hsub_pd(x, y), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f383(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_min_pd(x, _mm_hsub_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f384(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_min_pd(_mm_hsub_pd(x, y), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f385(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_min_pd(y, _mm_hsub_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f386(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_max_pd(_mm_add_pd(x, y), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f387(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_max_pd(x, _mm_add_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f388(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_max_pd(_mm_add_pd(x, y), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f389(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_max_pd(y, _mm_add_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f390(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_max_pd(_mm_sub_pd(x, y), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f391(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_max_pd(x, _mm_sub_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f392(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_max_pd(_mm_sub_pd(x, y), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f393(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_max_pd(y, _mm_sub_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f394(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_max_pd(_mm_mul_pd(x, y), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f395(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_max_pd(x, _mm_mul_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f396(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_max_pd(_mm_mul_pd(x, y), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f397(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_max_pd(y, _mm_mul_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f398(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_max_pd(_mm_div_pd(x, y), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f399(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_max_pd(x, _mm_div_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f400(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_max_pd(_mm_div_pd(x, y), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f401(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_max_pd(y, _mm_div_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f402(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_max_pd(_mm_min_pd(x, y), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f403(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_max_pd(x, _mm_min_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f404(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_max_pd(_mm_min_pd(x, y), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f405(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_max_pd(y, _mm_min_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f406(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_max_pd(_mm_max_pd(x, y), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f407(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_max_pd(x, _mm_max_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f408(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_max_pd(_mm_max_pd(x, y), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f409(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_max_pd(y, _mm_max_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f410(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_max_pd(_mm_and_pd(x, y), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f411(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_max_pd(x, _mm_and_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f412(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_max_pd(_mm_and_pd(x, y), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f413(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_max_pd(y, _mm_and_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f414(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_max_pd(_mm_or_pd(x, y), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f415(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_max_pd(x, _mm_or_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f416(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_max_pd(_mm_or_pd(x, y), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f417(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_max_pd(y, _mm_or_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f418(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_max_pd(_mm_xor_pd(x, y), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f419(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_max_pd(x, _mm_xor_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f420(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_max_pd(_mm_xor_pd(x, y), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f421(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_max_pd(y, _mm_xor_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f422(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_max_pd(_mm_andnot_pd(x, y), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f423(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_max_pd(x, _mm_andnot_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f424(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_max_pd(_mm_andnot_pd(x, y), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f425(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_max_pd(y, _mm_andnot_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f426(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_max_pd(_mm_cmp_pd(x, y, _CMP_EQ_OQ), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f427(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_max_pd(x, _mm_cmp_pd(x, y, _CMP_EQ_OQ)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f428(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_max_pd(_mm_cmp_pd(x, y, _CMP_EQ_OQ), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f429(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_max_pd(y, _mm_cmp_pd(x, y, _CMP_EQ_OQ)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f430(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_max_pd(_mm_cmp_pd(x, y, _CMP_LT_OS), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f431(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_max_pd(x, _mm_cmp_pd(x, y, _CMP_LT_OS)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f432(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_max_pd(_mm_cmp_pd(x, y, _CMP_LT_OS), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f433(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_max_pd(y, _mm_cmp_pd(x, y, _CMP_LT_OS)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f434(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_max_pd(_mm_cmp_pd(x, y, _CMP_LE_OS), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f435(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_max_pd(x, _mm_cmp_pd(x, y, _CMP_LE_OS)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f436(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_max_pd(_mm_cmp_pd(x, y, _CMP_LE_OS), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f437(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_max_pd(y, _mm_cmp_pd(x, y, _CMP_LE_OS)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f438(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_max_pd(_mm_cmp_pd(x, y, _CMP_NEQ_UQ), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f439(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_max_pd(x, _mm_cmp_pd(x, y, _CMP_NEQ_UQ)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f440(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_max_pd(_mm_cmp_pd(x, y, _CMP_NEQ_UQ), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f441(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_max_pd(y, _mm_cmp_pd(x, y, _CMP_NEQ_UQ)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f442(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_max_pd(_mm_cmp_pd(x, y, _CMP_UNORD_Q), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f443(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_max_pd(x, _mm_cmp_pd(x, y, _CMP_UNORD_Q)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f444(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_max_pd(_mm_cmp_pd(x, y, _CMP_UNORD_Q), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f445(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_max_pd(y, _mm_cmp_pd(x, y, _CMP_UNORD_Q)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f446(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_max_pd(_mm_cmp_pd(x, y, _CMP_NLT_US), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f447(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_max_pd(x, _mm_cmp_pd(x, y, _CMP_NLT_US)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f448(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_max_pd(_mm_cmp_pd(x, y, _CMP_NLT_US), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f449(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_max_pd(y, _mm_cmp_pd(x, y, _CMP_NLT_US)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f450(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_max_pd(_mm_cmp_pd(x, y, _CMP_GT_OS), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f451(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_max_pd(x, _mm_cmp_pd(x, y, _CMP_GT_OS)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f452(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_max_pd(_mm_cmp_pd(x, y, _CMP_GT_OS), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f453(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_max_pd(y, _mm_cmp_pd(x, y, _CMP_GT_OS)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f454(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_max_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_LT_OS)), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f455(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_max_pd(x, _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_LT_OS))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f456(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_max_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_LT_OS)), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f457(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_max_pd(y, _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_LT_OS))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f458(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_max_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_LT_OS)), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f459(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_max_pd(x, _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_LT_OS))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f460(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_max_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_LT_OS)), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f461(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_max_pd(y, _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_LT_OS))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f462(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_max_pd(_mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_LT_OS), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_LT_OS), y)), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f463(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_max_pd(x, _mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_LT_OS), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_LT_OS), y))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f464(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_max_pd(_mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_LT_OS), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_LT_OS), y)), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f465(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_max_pd(y, _mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_LT_OS), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_LT_OS), y))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f466(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_max_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_LE_OS)), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f467(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_max_pd(x, _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_LE_OS))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f468(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_max_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_LE_OS)), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f469(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_max_pd(y, _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_LE_OS))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f470(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_max_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_LE_OS)), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f471(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_max_pd(x, _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_LE_OS))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f472(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_max_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_LE_OS)), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f473(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_max_pd(y, _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_LE_OS))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f474(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_max_pd(_mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_LE_OS), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_LE_OS), y)), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f475(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_max_pd(x, _mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_LE_OS), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_LE_OS), y))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f476(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_max_pd(_mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_LE_OS), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_LE_OS), y)), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f477(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_max_pd(y, _mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_LE_OS), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_LE_OS), y))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f478(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_max_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_GT_OS)), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f479(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_max_pd(x, _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_GT_OS))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f480(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_max_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_GT_OS)), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f481(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_max_pd(y, _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_GT_OS))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f482(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_max_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_GT_OS)), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f483(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_max_pd(x, _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_GT_OS))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f484(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_max_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_GT_OS)), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f485(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_max_pd(y, _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_GT_OS))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f486(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_max_pd(_mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_GT_OS), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_GT_OS), y)), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f487(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_max_pd(x, _mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_GT_OS), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_GT_OS), y))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f488(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_max_pd(_mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_GT_OS), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_GT_OS), y)), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f489(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_max_pd(y, _mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_GT_OS), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_GT_OS), y))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f490(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_max_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_NLT_US)), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f491(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_max_pd(x, _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_NLT_US))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f492(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_max_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_NLT_US)), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f493(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_max_pd(y, _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_NLT_US))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f494(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_max_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_NLT_US)), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f495(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_max_pd(x, _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_NLT_US))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f496(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_max_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_NLT_US)), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f497(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_max_pd(y, _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_NLT_US))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f498(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_max_pd(_mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_NLT_US), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_NLT_US), y)), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f499(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_max_pd(x, _mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_NLT_US), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_NLT_US), y))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f500(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_max_pd(_mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_NLT_US), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_NLT_US), y)), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f501(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_max_pd(y, _mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_NLT_US), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_NLT_US), y))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f502(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_max_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_EQ_OQ)), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f503(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_max_pd(x, _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_EQ_OQ))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f504(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_max_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_EQ_OQ)), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f505(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_max_pd(y, _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_EQ_OQ))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f506(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_max_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_EQ_OQ)), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f507(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_max_pd(x, _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_EQ_OQ))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f508(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_max_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_EQ_OQ)), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f509(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_max_pd(y, _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_EQ_OQ))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f510(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_max_pd(_mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_EQ_OQ), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_EQ_OQ), y)), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f511(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_max_pd(x, _mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_EQ_OQ), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_EQ_OQ), y))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f512(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_max_pd(_mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_EQ_OQ), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_EQ_OQ), y)), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f513(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_max_pd(y, _mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_EQ_OQ), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_EQ_OQ), y))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f514(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_max_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_UNORD_Q)), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f515(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_max_pd(x, _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_UNORD_Q))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f516(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_max_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_UNORD_Q)), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f517(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_max_pd(y, _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_UNORD_Q))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f518(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_max_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_UNORD_Q)), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f519(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_max_pd(x, _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_UNORD_Q))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f520(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_max_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_UNORD_Q)), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f521(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_max_pd(y, _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_UNORD_Q))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f522(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_max_pd(_mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_UNORD_Q), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_UNORD_Q), y)), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f523(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_max_pd(x, _mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_UNORD_Q), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_UNORD_Q), y))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f524(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_max_pd(_mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_UNORD_Q), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_UNORD_Q), y)), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f525(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_max_pd(y, _mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_UNORD_Q), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_UNORD_Q), y))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f526(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_max_pd(_mm_unpacklo_pd(x, y), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f527(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_max_pd(x, _mm_unpacklo_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f528(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_max_pd(_mm_unpacklo_pd(x, y), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f529(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_max_pd(y, _mm_unpacklo_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f530(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_max_pd(_mm_unpackhi_pd(x, y), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f531(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_max_pd(x, _mm_unpackhi_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f532(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_max_pd(_mm_unpackhi_pd(x, y), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f533(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_max_pd(y, _mm_unpackhi_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f534(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_max_pd(_mm_hadd_pd(x, y), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f535(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_max_pd(x, _mm_hadd_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f536(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_max_pd(_mm_hadd_pd(x, y), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f537(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_max_pd(y, _mm_hadd_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f538(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_max_pd(_mm_hsub_pd(x, y), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f539(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_max_pd(x, _mm_hsub_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f540(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_max_pd(_mm_hsub_pd(x, y), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f541(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_max_pd(y, _mm_hsub_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f542(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_and_pd(_mm_add_pd(x, y), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f543(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_and_pd(x, _mm_add_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f544(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_and_pd(_mm_add_pd(x, y), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f545(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_and_pd(y, _mm_add_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f546(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_and_pd(_mm_sub_pd(x, y), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f547(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_and_pd(x, _mm_sub_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f548(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_and_pd(_mm_sub_pd(x, y), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f549(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_and_pd(y, _mm_sub_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f550(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_and_pd(_mm_mul_pd(x, y), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f551(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_and_pd(x, _mm_mul_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f552(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_and_pd(_mm_mul_pd(x, y), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f553(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_and_pd(y, _mm_mul_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f554(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_and_pd(_mm_div_pd(x, y), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f555(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_and_pd(x, _mm_div_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f556(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_and_pd(_mm_div_pd(x, y), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f557(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_and_pd(y, _mm_div_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f558(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_and_pd(_mm_min_pd(x, y), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f559(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_and_pd(x, _mm_min_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f560(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_and_pd(_mm_min_pd(x, y), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f561(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_and_pd(y, _mm_min_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f562(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_and_pd(_mm_max_pd(x, y), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f563(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_and_pd(x, _mm_max_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f564(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_and_pd(_mm_max_pd(x, y), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f565(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_and_pd(y, _mm_max_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f566(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_and_pd(_mm_and_pd(x, y), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f567(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_and_pd(x, _mm_and_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f568(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_and_pd(_mm_and_pd(x, y), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f569(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_and_pd(y, _mm_and_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f570(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_and_pd(_mm_or_pd(x, y), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f571(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_and_pd(x, _mm_or_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f572(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_and_pd(_mm_or_pd(x, y), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f573(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_and_pd(y, _mm_or_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f574(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_and_pd(_mm_xor_pd(x, y), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f575(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_and_pd(x, _mm_xor_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f576(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_and_pd(_mm_xor_pd(x, y), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f577(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_and_pd(y, _mm_xor_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f578(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_and_pd(_mm_andnot_pd(x, y), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f579(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_and_pd(x, _mm_andnot_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f580(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_and_pd(_mm_andnot_pd(x, y), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f581(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_and_pd(y, _mm_andnot_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f582(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_and_pd(_mm_cmp_pd(x, y, _CMP_EQ_OQ), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f583(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_and_pd(x, _mm_cmp_pd(x, y, _CMP_EQ_OQ)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f584(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_and_pd(_mm_cmp_pd(x, y, _CMP_EQ_OQ), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f585(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_and_pd(y, _mm_cmp_pd(x, y, _CMP_EQ_OQ)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f586(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_and_pd(_mm_cmp_pd(x, y, _CMP_LT_OS), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f587(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_and_pd(x, _mm_cmp_pd(x, y, _CMP_LT_OS)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f588(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_and_pd(_mm_cmp_pd(x, y, _CMP_LT_OS), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f589(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_and_pd(y, _mm_cmp_pd(x, y, _CMP_LT_OS)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f590(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_and_pd(_mm_cmp_pd(x, y, _CMP_LE_OS), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f591(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_and_pd(x, _mm_cmp_pd(x, y, _CMP_LE_OS)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f592(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_and_pd(_mm_cmp_pd(x, y, _CMP_LE_OS), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f593(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_and_pd(y, _mm_cmp_pd(x, y, _CMP_LE_OS)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f594(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_and_pd(_mm_cmp_pd(x, y, _CMP_NEQ_UQ), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f595(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_and_pd(x, _mm_cmp_pd(x, y, _CMP_NEQ_UQ)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f596(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_and_pd(_mm_cmp_pd(x, y, _CMP_NEQ_UQ), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f597(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_and_pd(y, _mm_cmp_pd(x, y, _CMP_NEQ_UQ)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f598(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_and_pd(_mm_cmp_pd(x, y, _CMP_UNORD_Q), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f599(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_and_pd(x, _mm_cmp_pd(x, y, _CMP_UNORD_Q)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f600(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_and_pd(_mm_cmp_pd(x, y, _CMP_UNORD_Q), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f601(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_and_pd(y, _mm_cmp_pd(x, y, _CMP_UNORD_Q)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f602(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_and_pd(_mm_cmp_pd(x, y, _CMP_NLT_US), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f603(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_and_pd(x, _mm_cmp_pd(x, y, _CMP_NLT_US)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f604(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_and_pd(_mm_cmp_pd(x, y, _CMP_NLT_US), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f605(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_and_pd(y, _mm_cmp_pd(x, y, _CMP_NLT_US)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f606(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_and_pd(_mm_cmp_pd(x, y, _CMP_GT_OS), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f607(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_and_pd(x, _mm_cmp_pd(x, y, _CMP_GT_OS)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f608(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_and_pd(_mm_cmp_pd(x, y, _CMP_GT_OS), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f609(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_and_pd(y, _mm_cmp_pd(x, y, _CMP_GT_OS)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f610(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_and_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_LT_OS)), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f611(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_and_pd(x, _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_LT_OS))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f612(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_and_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_LT_OS)), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f613(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_and_pd(y, _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_LT_OS))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f614(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_and_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_LT_OS)), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f615(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_and_pd(x, _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_LT_OS))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f616(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_and_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_LT_OS)), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f617(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_and_pd(y, _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_LT_OS))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f618(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_and_pd(_mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_LT_OS), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_LT_OS), y)), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f619(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_and_pd(x, _mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_LT_OS), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_LT_OS), y))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f620(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_and_pd(_mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_LT_OS), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_LT_OS), y)), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f621(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_and_pd(y, _mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_LT_OS), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_LT_OS), y))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f622(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_and_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_LE_OS)), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f623(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_and_pd(x, _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_LE_OS))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f624(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_and_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_LE_OS)), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f625(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_and_pd(y, _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_LE_OS))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f626(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_and_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_LE_OS)), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f627(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_and_pd(x, _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_LE_OS))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f628(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_and_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_LE_OS)), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f629(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_and_pd(y, _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_LE_OS))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f630(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_and_pd(_mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_LE_OS), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_LE_OS), y)), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f631(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_and_pd(x, _mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_LE_OS), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_LE_OS), y))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f632(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_and_pd(_mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_LE_OS), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_LE_OS), y)), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f633(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_and_pd(y, _mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_LE_OS), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_LE_OS), y))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f634(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_and_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_GT_OS)), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f635(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_and_pd(x, _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_GT_OS))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f636(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_and_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_GT_OS)), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f637(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_and_pd(y, _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_GT_OS))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f638(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_and_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_GT_OS)), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f639(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_and_pd(x, _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_GT_OS))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f640(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_and_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_GT_OS)), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f641(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_and_pd(y, _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_GT_OS))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f642(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_and_pd(_mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_GT_OS), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_GT_OS), y)), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f643(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_and_pd(x, _mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_GT_OS), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_GT_OS), y))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f644(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_and_pd(_mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_GT_OS), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_GT_OS), y)), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f645(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_and_pd(y, _mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_GT_OS), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_GT_OS), y))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f646(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_and_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_NLT_US)), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f647(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_and_pd(x, _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_NLT_US))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f648(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_and_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_NLT_US)), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f649(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_and_pd(y, _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_NLT_US))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f650(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_and_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_NLT_US)), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f651(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_and_pd(x, _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_NLT_US))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f652(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_and_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_NLT_US)), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f653(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_and_pd(y, _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_NLT_US))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f654(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_and_pd(_mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_NLT_US), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_NLT_US), y)), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f655(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_and_pd(x, _mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_NLT_US), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_NLT_US), y))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f656(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_and_pd(_mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_NLT_US), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_NLT_US), y)), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f657(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_and_pd(y, _mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_NLT_US), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_NLT_US), y))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f658(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_and_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_EQ_OQ)), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f659(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_and_pd(x, _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_EQ_OQ))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f660(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_and_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_EQ_OQ)), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f661(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_and_pd(y, _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_EQ_OQ))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f662(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_and_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_EQ_OQ)), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f663(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_and_pd(x, _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_EQ_OQ))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f664(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_and_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_EQ_OQ)), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f665(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_and_pd(y, _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_EQ_OQ))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f666(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_and_pd(_mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_EQ_OQ), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_EQ_OQ), y)), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f667(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_and_pd(x, _mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_EQ_OQ), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_EQ_OQ), y))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f668(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_and_pd(_mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_EQ_OQ), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_EQ_OQ), y)), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f669(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_and_pd(y, _mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_EQ_OQ), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_EQ_OQ), y))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f670(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_and_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_UNORD_Q)), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f671(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_and_pd(x, _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_UNORD_Q))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f672(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_and_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_UNORD_Q)), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f673(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_and_pd(y, _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_UNORD_Q))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f674(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_and_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_UNORD_Q)), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f675(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_and_pd(x, _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_UNORD_Q))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f676(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_and_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_UNORD_Q)), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f677(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_and_pd(y, _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_UNORD_Q))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f678(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_and_pd(_mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_UNORD_Q), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_UNORD_Q), y)), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f679(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_and_pd(x, _mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_UNORD_Q), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_UNORD_Q), y))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f680(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_and_pd(_mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_UNORD_Q), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_UNORD_Q), y)), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f681(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_and_pd(y, _mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_UNORD_Q), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_UNORD_Q), y))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f682(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_and_pd(_mm_unpacklo_pd(x, y), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f683(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_and_pd(x, _mm_unpacklo_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f684(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_and_pd(_mm_unpacklo_pd(x, y), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f685(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_and_pd(y, _mm_unpacklo_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f686(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_and_pd(_mm_unpackhi_pd(x, y), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f687(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_and_pd(x, _mm_unpackhi_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f688(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_and_pd(_mm_unpackhi_pd(x, y), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f689(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_and_pd(y, _mm_unpackhi_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f690(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_and_pd(_mm_hadd_pd(x, y), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f691(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_and_pd(x, _mm_hadd_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f692(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_and_pd(_mm_hadd_pd(x, y), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f693(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_and_pd(y, _mm_hadd_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f694(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_and_pd(_mm_hsub_pd(x, y), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f695(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_and_pd(x, _mm_hsub_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f696(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_and_pd(_mm_hsub_pd(x, y), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f697(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_and_pd(y, _mm_hsub_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f698(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_or_pd(_mm_add_pd(x, y), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f699(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_or_pd(x, _mm_add_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f700(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_or_pd(_mm_add_pd(x, y), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f701(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_or_pd(y, _mm_add_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f702(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_or_pd(_mm_sub_pd(x, y), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f703(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_or_pd(x, _mm_sub_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f704(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_or_pd(_mm_sub_pd(x, y), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f705(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_or_pd(y, _mm_sub_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f706(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_or_pd(_mm_mul_pd(x, y), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f707(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_or_pd(x, _mm_mul_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f708(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_or_pd(_mm_mul_pd(x, y), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f709(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_or_pd(y, _mm_mul_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f710(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_or_pd(_mm_div_pd(x, y), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f711(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_or_pd(x, _mm_div_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f712(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_or_pd(_mm_div_pd(x, y), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f713(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_or_pd(y, _mm_div_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f714(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_or_pd(_mm_min_pd(x, y), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f715(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_or_pd(x, _mm_min_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f716(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_or_pd(_mm_min_pd(x, y), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f717(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_or_pd(y, _mm_min_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f718(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_or_pd(_mm_max_pd(x, y), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f719(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_or_pd(x, _mm_max_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f720(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_or_pd(_mm_max_pd(x, y), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f721(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_or_pd(y, _mm_max_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f722(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_or_pd(_mm_and_pd(x, y), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f723(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_or_pd(x, _mm_and_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f724(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_or_pd(_mm_and_pd(x, y), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f725(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_or_pd(y, _mm_and_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f726(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_or_pd(_mm_or_pd(x, y), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f727(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_or_pd(x, _mm_or_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f728(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_or_pd(_mm_or_pd(x, y), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f729(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_or_pd(y, _mm_or_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f730(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_or_pd(_mm_xor_pd(x, y), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f731(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_or_pd(x, _mm_xor_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f732(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_or_pd(_mm_xor_pd(x, y), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f733(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_or_pd(y, _mm_xor_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f734(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_or_pd(_mm_andnot_pd(x, y), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f735(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_or_pd(x, _mm_andnot_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f736(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_or_pd(_mm_andnot_pd(x, y), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f737(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_or_pd(y, _mm_andnot_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f738(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_or_pd(_mm_cmp_pd(x, y, _CMP_EQ_OQ), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f739(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_or_pd(x, _mm_cmp_pd(x, y, _CMP_EQ_OQ)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f740(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_or_pd(_mm_cmp_pd(x, y, _CMP_EQ_OQ), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f741(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_or_pd(y, _mm_cmp_pd(x, y, _CMP_EQ_OQ)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f742(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_or_pd(_mm_cmp_pd(x, y, _CMP_LT_OS), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f743(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_or_pd(x, _mm_cmp_pd(x, y, _CMP_LT_OS)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f744(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_or_pd(_mm_cmp_pd(x, y, _CMP_LT_OS), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f745(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_or_pd(y, _mm_cmp_pd(x, y, _CMP_LT_OS)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f746(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_or_pd(_mm_cmp_pd(x, y, _CMP_LE_OS), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f747(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_or_pd(x, _mm_cmp_pd(x, y, _CMP_LE_OS)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f748(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_or_pd(_mm_cmp_pd(x, y, _CMP_LE_OS), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f749(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_or_pd(y, _mm_cmp_pd(x, y, _CMP_LE_OS)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f750(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_or_pd(_mm_cmp_pd(x, y, _CMP_NEQ_UQ), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f751(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_or_pd(x, _mm_cmp_pd(x, y, _CMP_NEQ_UQ)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f752(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_or_pd(_mm_cmp_pd(x, y, _CMP_NEQ_UQ), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f753(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_or_pd(y, _mm_cmp_pd(x, y, _CMP_NEQ_UQ)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f754(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_or_pd(_mm_cmp_pd(x, y, _CMP_UNORD_Q), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f755(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_or_pd(x, _mm_cmp_pd(x, y, _CMP_UNORD_Q)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f756(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_or_pd(_mm_cmp_pd(x, y, _CMP_UNORD_Q), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f757(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_or_pd(y, _mm_cmp_pd(x, y, _CMP_UNORD_Q)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f758(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_or_pd(_mm_cmp_pd(x, y, _CMP_NLT_US), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f759(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_or_pd(x, _mm_cmp_pd(x, y, _CMP_NLT_US)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f760(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_or_pd(_mm_cmp_pd(x, y, _CMP_NLT_US), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f761(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_or_pd(y, _mm_cmp_pd(x, y, _CMP_NLT_US)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f762(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_or_pd(_mm_cmp_pd(x, y, _CMP_GT_OS), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f763(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_or_pd(x, _mm_cmp_pd(x, y, _CMP_GT_OS)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f764(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_or_pd(_mm_cmp_pd(x, y, _CMP_GT_OS), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f765(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_or_pd(y, _mm_cmp_pd(x, y, _CMP_GT_OS)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f766(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_or_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_LT_OS)), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f767(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_or_pd(x, _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_LT_OS))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f768(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_or_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_LT_OS)), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f769(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_or_pd(y, _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_LT_OS))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f770(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_or_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_LT_OS)), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f771(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_or_pd(x, _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_LT_OS))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f772(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_or_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_LT_OS)), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f773(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_or_pd(y, _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_LT_OS))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f774(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_or_pd(_mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_LT_OS), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_LT_OS), y)), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f775(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_or_pd(x, _mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_LT_OS), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_LT_OS), y))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f776(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_or_pd(_mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_LT_OS), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_LT_OS), y)), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f777(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_or_pd(y, _mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_LT_OS), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_LT_OS), y))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f778(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_or_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_LE_OS)), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f779(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_or_pd(x, _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_LE_OS))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f780(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_or_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_LE_OS)), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f781(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_or_pd(y, _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_LE_OS))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f782(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_or_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_LE_OS)), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f783(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_or_pd(x, _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_LE_OS))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f784(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_or_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_LE_OS)), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f785(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_or_pd(y, _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_LE_OS))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f786(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_or_pd(_mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_LE_OS), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_LE_OS), y)), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f787(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_or_pd(x, _mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_LE_OS), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_LE_OS), y))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f788(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_or_pd(_mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_LE_OS), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_LE_OS), y)), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f789(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_or_pd(y, _mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_LE_OS), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_LE_OS), y))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f790(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_or_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_GT_OS)), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f791(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_or_pd(x, _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_GT_OS))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f792(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_or_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_GT_OS)), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f793(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_or_pd(y, _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_GT_OS))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f794(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_or_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_GT_OS)), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f795(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_or_pd(x, _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_GT_OS))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f796(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_or_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_GT_OS)), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f797(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_or_pd(y, _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_GT_OS))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f798(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_or_pd(_mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_GT_OS), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_GT_OS), y)), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f799(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_or_pd(x, _mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_GT_OS), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_GT_OS), y))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f800(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_or_pd(_mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_GT_OS), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_GT_OS), y)), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f801(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_or_pd(y, _mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_GT_OS), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_GT_OS), y))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f802(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_or_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_NLT_US)), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f803(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_or_pd(x, _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_NLT_US))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f804(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_or_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_NLT_US)), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f805(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_or_pd(y, _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_NLT_US))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f806(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_or_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_NLT_US)), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f807(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_or_pd(x, _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_NLT_US))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f808(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_or_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_NLT_US)), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f809(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_or_pd(y, _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_NLT_US))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f810(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_or_pd(_mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_NLT_US), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_NLT_US), y)), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f811(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_or_pd(x, _mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_NLT_US), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_NLT_US), y))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f812(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_or_pd(_mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_NLT_US), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_NLT_US), y)), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f813(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_or_pd(y, _mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_NLT_US), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_NLT_US), y))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f814(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_or_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_EQ_OQ)), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f815(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_or_pd(x, _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_EQ_OQ))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f816(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_or_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_EQ_OQ)), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f817(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_or_pd(y, _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_EQ_OQ))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f818(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_or_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_EQ_OQ)), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f819(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_or_pd(x, _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_EQ_OQ))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f820(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_or_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_EQ_OQ)), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f821(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_or_pd(y, _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_EQ_OQ))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f822(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_or_pd(_mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_EQ_OQ), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_EQ_OQ), y)), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f823(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_or_pd(x, _mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_EQ_OQ), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_EQ_OQ), y))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f824(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_or_pd(_mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_EQ_OQ), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_EQ_OQ), y)), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f825(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_or_pd(y, _mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_EQ_OQ), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_EQ_OQ), y))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f826(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_or_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_UNORD_Q)), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f827(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_or_pd(x, _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_UNORD_Q))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f828(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_or_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_UNORD_Q)), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f829(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_or_pd(y, _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_UNORD_Q))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f830(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_or_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_UNORD_Q)), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f831(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_or_pd(x, _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_UNORD_Q))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f832(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_or_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_UNORD_Q)), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f833(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_or_pd(y, _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_UNORD_Q))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f834(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_or_pd(_mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_UNORD_Q), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_UNORD_Q), y)), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f835(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_or_pd(x, _mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_UNORD_Q), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_UNORD_Q), y))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f836(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_or_pd(_mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_UNORD_Q), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_UNORD_Q), y)), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f837(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_or_pd(y, _mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_UNORD_Q), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_UNORD_Q), y))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f838(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_or_pd(_mm_unpacklo_pd(x, y), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f839(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_or_pd(x, _mm_unpacklo_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f840(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_or_pd(_mm_unpacklo_pd(x, y), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f841(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_or_pd(y, _mm_unpacklo_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f842(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_or_pd(_mm_unpackhi_pd(x, y), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f843(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_or_pd(x, _mm_unpackhi_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f844(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_or_pd(_mm_unpackhi_pd(x, y), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f845(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_or_pd(y, _mm_unpackhi_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f846(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_or_pd(_mm_hadd_pd(x, y), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f847(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_or_pd(x, _mm_hadd_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f848(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_or_pd(_mm_hadd_pd(x, y), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f849(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_or_pd(y, _mm_hadd_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f850(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_or_pd(_mm_hsub_pd(x, y), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f851(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_or_pd(x, _mm_hsub_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f852(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_or_pd(_mm_hsub_pd(x, y), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f853(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_or_pd(y, _mm_hsub_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f854(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(_mm_add_pd(x, y), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f855(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(x, _mm_add_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f856(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(_mm_add_pd(x, y), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f857(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(y, _mm_add_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f858(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(_mm_sub_pd(x, y), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f859(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(x, _mm_sub_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f860(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(_mm_sub_pd(x, y), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f861(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(y, _mm_sub_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f862(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(_mm_mul_pd(x, y), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f863(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(x, _mm_mul_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f864(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(_mm_mul_pd(x, y), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f865(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(y, _mm_mul_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f866(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(_mm_div_pd(x, y), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f867(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(x, _mm_div_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f868(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(_mm_div_pd(x, y), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f869(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(y, _mm_div_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f870(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(_mm_min_pd(x, y), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f871(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(x, _mm_min_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f872(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(_mm_min_pd(x, y), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f873(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(y, _mm_min_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f874(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(_mm_max_pd(x, y), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f875(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(x, _mm_max_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f876(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(_mm_max_pd(x, y), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f877(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(y, _mm_max_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f878(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(_mm_and_pd(x, y), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f879(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(x, _mm_and_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f880(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(_mm_and_pd(x, y), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f881(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(y, _mm_and_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f882(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(_mm_or_pd(x, y), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f883(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(x, _mm_or_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f884(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(_mm_or_pd(x, y), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f885(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(y, _mm_or_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f886(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(_mm_xor_pd(x, y), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f887(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(x, _mm_xor_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f888(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(_mm_xor_pd(x, y), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f889(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(y, _mm_xor_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f890(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(_mm_andnot_pd(x, y), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f891(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(x, _mm_andnot_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f892(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(_mm_andnot_pd(x, y), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f893(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(y, _mm_andnot_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f894(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(_mm_cmp_pd(x, y, _CMP_EQ_OQ), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f895(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(x, _mm_cmp_pd(x, y, _CMP_EQ_OQ)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f896(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(_mm_cmp_pd(x, y, _CMP_EQ_OQ), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f897(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(y, _mm_cmp_pd(x, y, _CMP_EQ_OQ)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f898(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(_mm_cmp_pd(x, y, _CMP_LT_OS), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f899(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(x, _mm_cmp_pd(x, y, _CMP_LT_OS)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f900(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(_mm_cmp_pd(x, y, _CMP_LT_OS), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f901(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(y, _mm_cmp_pd(x, y, _CMP_LT_OS)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f902(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(_mm_cmp_pd(x, y, _CMP_LE_OS), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f903(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(x, _mm_cmp_pd(x, y, _CMP_LE_OS)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f904(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(_mm_cmp_pd(x, y, _CMP_LE_OS), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f905(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(y, _mm_cmp_pd(x, y, _CMP_LE_OS)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f906(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(_mm_cmp_pd(x, y, _CMP_NEQ_UQ), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f907(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(x, _mm_cmp_pd(x, y, _CMP_NEQ_UQ)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f908(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(_mm_cmp_pd(x, y, _CMP_NEQ_UQ), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f909(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(y, _mm_cmp_pd(x, y, _CMP_NEQ_UQ)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f910(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(_mm_cmp_pd(x, y, _CMP_UNORD_Q), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f911(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(x, _mm_cmp_pd(x, y, _CMP_UNORD_Q)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f912(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(_mm_cmp_pd(x, y, _CMP_UNORD_Q), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f913(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(y, _mm_cmp_pd(x, y, _CMP_UNORD_Q)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f914(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(_mm_cmp_pd(x, y, _CMP_NLT_US), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f915(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(x, _mm_cmp_pd(x, y, _CMP_NLT_US)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f916(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(_mm_cmp_pd(x, y, _CMP_NLT_US), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f917(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(y, _mm_cmp_pd(x, y, _CMP_NLT_US)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f918(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(_mm_cmp_pd(x, y, _CMP_GT_OS), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f919(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(x, _mm_cmp_pd(x, y, _CMP_GT_OS)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f920(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(_mm_cmp_pd(x, y, _CMP_GT_OS), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f921(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(y, _mm_cmp_pd(x, y, _CMP_GT_OS)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f922(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_LT_OS)), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f923(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(x, _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_LT_OS))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f924(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_LT_OS)), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f925(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(y, _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_LT_OS))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f926(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_LT_OS)), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f927(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(x, _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_LT_OS))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f928(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_LT_OS)), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f929(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(y, _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_LT_OS))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f930(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(_mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_LT_OS), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_LT_OS), y)), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f931(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(x, _mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_LT_OS), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_LT_OS), y))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f932(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(_mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_LT_OS), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_LT_OS), y)), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f933(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(y, _mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_LT_OS), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_LT_OS), y))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f934(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_LE_OS)), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f935(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(x, _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_LE_OS))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f936(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_LE_OS)), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f937(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(y, _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_LE_OS))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f938(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_LE_OS)), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f939(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(x, _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_LE_OS))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f940(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_LE_OS)), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f941(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(y, _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_LE_OS))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f942(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(_mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_LE_OS), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_LE_OS), y)), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f943(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(x, _mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_LE_OS), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_LE_OS), y))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f944(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(_mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_LE_OS), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_LE_OS), y)), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f945(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(y, _mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_LE_OS), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_LE_OS), y))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f946(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_GT_OS)), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f947(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(x, _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_GT_OS))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f948(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_GT_OS)), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f949(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(y, _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_GT_OS))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f950(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_GT_OS)), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f951(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(x, _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_GT_OS))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f952(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_GT_OS)), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f953(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(y, _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_GT_OS))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f954(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(_mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_GT_OS), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_GT_OS), y)), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f955(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(x, _mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_GT_OS), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_GT_OS), y))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f956(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(_mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_GT_OS), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_GT_OS), y)), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f957(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(y, _mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_GT_OS), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_GT_OS), y))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f958(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_NLT_US)), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f959(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(x, _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_NLT_US))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f960(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_NLT_US)), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f961(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(y, _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_NLT_US))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f962(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_NLT_US)), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f963(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(x, _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_NLT_US))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f964(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_NLT_US)), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f965(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(y, _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_NLT_US))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f966(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(_mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_NLT_US), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_NLT_US), y)), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f967(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(x, _mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_NLT_US), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_NLT_US), y))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f968(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(_mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_NLT_US), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_NLT_US), y)), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f969(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(y, _mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_NLT_US), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_NLT_US), y))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f970(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_EQ_OQ)), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f971(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(x, _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_EQ_OQ))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f972(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_EQ_OQ)), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f973(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(y, _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_EQ_OQ))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f974(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_EQ_OQ)), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f975(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(x, _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_EQ_OQ))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f976(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_EQ_OQ)), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f977(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(y, _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_EQ_OQ))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f978(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(_mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_EQ_OQ), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_EQ_OQ), y)), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f979(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(x, _mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_EQ_OQ), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_EQ_OQ), y))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f980(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(_mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_EQ_OQ), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_EQ_OQ), y)), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f981(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(y, _mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_EQ_OQ), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_EQ_OQ), y))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f982(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_UNORD_Q)), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f983(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(x, _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_UNORD_Q))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f984(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_UNORD_Q)), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f985(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(y, _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_UNORD_Q))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f986(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_UNORD_Q)), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f987(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(x, _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_UNORD_Q))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f988(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_UNORD_Q)), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f989(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(y, _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_UNORD_Q))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f990(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(_mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_UNORD_Q), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_UNORD_Q), y)), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f991(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(x, _mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_UNORD_Q), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_UNORD_Q), y))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f992(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(_mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_UNORD_Q), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_UNORD_Q), y)), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f993(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(y, _mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_UNORD_Q), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_UNORD_Q), y))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f994(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(_mm_unpacklo_pd(x, y), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f995(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(x, _mm_unpacklo_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f996(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(_mm_unpacklo_pd(x, y), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f997(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(y, _mm_unpacklo_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f998(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(_mm_unpackhi_pd(x, y), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f999(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(x, _mm_unpackhi_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1000(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(_mm_unpackhi_pd(x, y), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1001(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(y, _mm_unpackhi_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1002(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(_mm_hadd_pd(x, y), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1003(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(x, _mm_hadd_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1004(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(_mm_hadd_pd(x, y), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1005(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(y, _mm_hadd_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1006(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(_mm_hsub_pd(x, y), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1007(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(x, _mm_hsub_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1008(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(_mm_hsub_pd(x, y), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1009(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(y, _mm_hsub_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1010(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(_mm_add_pd(x, y), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1011(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(x, _mm_add_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1012(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(_mm_add_pd(x, y), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1013(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(y, _mm_add_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1014(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(_mm_sub_pd(x, y), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1015(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(x, _mm_sub_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1016(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(_mm_sub_pd(x, y), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1017(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(y, _mm_sub_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1018(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(_mm_mul_pd(x, y), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1019(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(x, _mm_mul_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1020(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(_mm_mul_pd(x, y), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1021(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(y, _mm_mul_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1022(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(_mm_div_pd(x, y), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1023(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(x, _mm_div_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1024(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(_mm_div_pd(x, y), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1025(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(y, _mm_div_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1026(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(_mm_min_pd(x, y), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1027(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(x, _mm_min_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1028(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(_mm_min_pd(x, y), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1029(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(y, _mm_min_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1030(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(_mm_max_pd(x, y), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1031(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(x, _mm_max_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1032(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(_mm_max_pd(x, y), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1033(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(y, _mm_max_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1034(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(_mm_and_pd(x, y), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1035(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(x, _mm_and_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1036(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(_mm_and_pd(x, y), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1037(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(y, _mm_and_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1038(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(_mm_or_pd(x, y), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1039(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(x, _mm_or_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1040(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(_mm_or_pd(x, y), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1041(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(y, _mm_or_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1042(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(_mm_xor_pd(x, y), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1043(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(x, _mm_xor_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1044(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(_mm_xor_pd(x, y), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1045(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(y, _mm_xor_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1046(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(_mm_andnot_pd(x, y), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1047(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(x, _mm_andnot_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1048(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(_mm_andnot_pd(x, y), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1049(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(y, _mm_andnot_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1050(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_EQ_OQ), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1051(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(x, _mm_cmp_pd(x, y, _CMP_EQ_OQ)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1052(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_EQ_OQ), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1053(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(y, _mm_cmp_pd(x, y, _CMP_EQ_OQ)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1054(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_LT_OS), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1055(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(x, _mm_cmp_pd(x, y, _CMP_LT_OS)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1056(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_LT_OS), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1057(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(y, _mm_cmp_pd(x, y, _CMP_LT_OS)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1058(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_LE_OS), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1059(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(x, _mm_cmp_pd(x, y, _CMP_LE_OS)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1060(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_LE_OS), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1061(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(y, _mm_cmp_pd(x, y, _CMP_LE_OS)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1062(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_NEQ_UQ), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1063(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(x, _mm_cmp_pd(x, y, _CMP_NEQ_UQ)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1064(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_NEQ_UQ), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1065(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(y, _mm_cmp_pd(x, y, _CMP_NEQ_UQ)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1066(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_UNORD_Q), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1067(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(x, _mm_cmp_pd(x, y, _CMP_UNORD_Q)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1068(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_UNORD_Q), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1069(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(y, _mm_cmp_pd(x, y, _CMP_UNORD_Q)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1070(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_NLT_US), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1071(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(x, _mm_cmp_pd(x, y, _CMP_NLT_US)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1072(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_NLT_US), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1073(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(y, _mm_cmp_pd(x, y, _CMP_NLT_US)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1074(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_GT_OS), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1075(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(x, _mm_cmp_pd(x, y, _CMP_GT_OS)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1076(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_GT_OS), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1077(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(y, _mm_cmp_pd(x, y, _CMP_GT_OS)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1078(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_LT_OS)), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1079(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(x, _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_LT_OS))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1080(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_LT_OS)), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1081(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(y, _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_LT_OS))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1082(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_LT_OS)), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1083(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(x, _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_LT_OS))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1084(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_LT_OS)), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1085(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(y, _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_LT_OS))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1086(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(_mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_LT_OS), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_LT_OS), y)), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1087(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(x, _mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_LT_OS), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_LT_OS), y))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1088(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(_mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_LT_OS), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_LT_OS), y)), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1089(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(y, _mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_LT_OS), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_LT_OS), y))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1090(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_LE_OS)), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1091(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(x, _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_LE_OS))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1092(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_LE_OS)), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1093(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(y, _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_LE_OS))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1094(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_LE_OS)), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1095(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(x, _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_LE_OS))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1096(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_LE_OS)), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1097(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(y, _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_LE_OS))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1098(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(_mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_LE_OS), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_LE_OS), y)), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1099(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(x, _mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_LE_OS), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_LE_OS), y))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1100(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(_mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_LE_OS), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_LE_OS), y)), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1101(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(y, _mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_LE_OS), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_LE_OS), y))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1102(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_GT_OS)), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1103(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(x, _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_GT_OS))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1104(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_GT_OS)), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1105(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(y, _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_GT_OS))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1106(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_GT_OS)), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1107(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(x, _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_GT_OS))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1108(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_GT_OS)), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1109(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(y, _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_GT_OS))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1110(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(_mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_GT_OS), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_GT_OS), y)), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1111(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(x, _mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_GT_OS), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_GT_OS), y))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1112(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(_mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_GT_OS), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_GT_OS), y)), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1113(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(y, _mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_GT_OS), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_GT_OS), y))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1114(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_NLT_US)), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1115(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(x, _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_NLT_US))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1116(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_NLT_US)), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1117(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(y, _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_NLT_US))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1118(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_NLT_US)), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1119(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(x, _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_NLT_US))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1120(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_NLT_US)), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1121(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(y, _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_NLT_US))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1122(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(_mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_NLT_US), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_NLT_US), y)), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1123(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(x, _mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_NLT_US), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_NLT_US), y))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1124(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(_mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_NLT_US), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_NLT_US), y)), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1125(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(y, _mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_NLT_US), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_NLT_US), y))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1126(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_EQ_OQ)), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1127(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(x, _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_EQ_OQ))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1128(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_EQ_OQ)), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1129(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(y, _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_EQ_OQ))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1130(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_EQ_OQ)), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1131(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(x, _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_EQ_OQ))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1132(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_EQ_OQ)), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1133(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(y, _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_EQ_OQ))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1134(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(_mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_EQ_OQ), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_EQ_OQ), y)), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1135(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(x, _mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_EQ_OQ), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_EQ_OQ), y))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1136(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(_mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_EQ_OQ), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_EQ_OQ), y)), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1137(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(y, _mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_EQ_OQ), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_EQ_OQ), y))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1138(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_UNORD_Q)), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1139(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(x, _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_UNORD_Q))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1140(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_UNORD_Q)), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1141(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(y, _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_UNORD_Q))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1142(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_UNORD_Q)), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1143(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(x, _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_UNORD_Q))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1144(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_UNORD_Q)), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1145(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(y, _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_UNORD_Q))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1146(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(_mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_UNORD_Q), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_UNORD_Q), y)), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1147(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(x, _mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_UNORD_Q), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_UNORD_Q), y))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1148(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(_mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_UNORD_Q), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_UNORD_Q), y)), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1149(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(y, _mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_UNORD_Q), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_UNORD_Q), y))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1150(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(_mm_unpacklo_pd(x, y), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1151(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(x, _mm_unpacklo_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1152(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(_mm_unpacklo_pd(x, y), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1153(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(y, _mm_unpacklo_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1154(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(_mm_unpackhi_pd(x, y), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1155(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(x, _mm_unpackhi_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1156(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(_mm_unpackhi_pd(x, y), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1157(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(y, _mm_unpackhi_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1158(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(_mm_hadd_pd(x, y), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1159(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(x, _mm_hadd_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1160(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(_mm_hadd_pd(x, y), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1161(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(y, _mm_hadd_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1162(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(_mm_hsub_pd(x, y), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1163(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(x, _mm_hsub_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1164(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(_mm_hsub_pd(x, y), x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1165(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(y, _mm_hsub_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1166(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_cmp_pd(_mm_add_pd(x, y), y, _CMP_EQ_OQ); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1167(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_cmp_pd(x, _mm_add_pd(x, y), _CMP_EQ_OQ); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1168(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_cmp_pd(_mm_add_pd(x, y), x, _CMP_EQ_OQ); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1169(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_cmp_pd(y, _mm_add_pd(x, y), _CMP_EQ_OQ); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1170(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_cmp_pd(_mm_sub_pd(x, y), y, _CMP_EQ_OQ); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1171(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_cmp_pd(x, _mm_sub_pd(x, y), _CMP_EQ_OQ); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1172(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_cmp_pd(_mm_sub_pd(x, y), x, _CMP_EQ_OQ); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1173(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_cmp_pd(y, _mm_sub_pd(x, y), _CMP_EQ_OQ); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1174(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_cmp_pd(_mm_mul_pd(x, y), y, _CMP_EQ_OQ); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1175(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_cmp_pd(x, _mm_mul_pd(x, y), _CMP_EQ_OQ); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1176(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_cmp_pd(_mm_mul_pd(x, y), x, _CMP_EQ_OQ); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1177(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_cmp_pd(y, _mm_mul_pd(x, y), _CMP_EQ_OQ); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1178(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_cmp_pd(_mm_div_pd(x, y), y, _CMP_EQ_OQ); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1179(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_cmp_pd(x, _mm_div_pd(x, y), _CMP_EQ_OQ); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1180(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_cmp_pd(_mm_div_pd(x, y), x, _CMP_EQ_OQ); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1181(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_cmp_pd(y, _mm_div_pd(x, y), _CMP_EQ_OQ); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1182(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_cmp_pd(_mm_min_pd(x, y), y, _CMP_EQ_OQ); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1183(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_cmp_pd(x, _mm_min_pd(x, y), _CMP_EQ_OQ); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1184(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_cmp_pd(_mm_min_pd(x, y), x, _CMP_EQ_OQ); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1185(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_cmp_pd(y, _mm_min_pd(x, y), _CMP_EQ_OQ); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1186(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_cmp_pd(_mm_max_pd(x, y), y, _CMP_EQ_OQ); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1187(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_cmp_pd(x, _mm_max_pd(x, y), _CMP_EQ_OQ); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1188(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_cmp_pd(_mm_max_pd(x, y), x, _CMP_EQ_OQ); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1189(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_cmp_pd(y, _mm_max_pd(x, y), _CMP_EQ_OQ); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1190(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_cmp_pd(_mm_and_pd(x, y), y, _CMP_EQ_OQ); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1191(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_cmp_pd(x, _mm_and_pd(x, y), _CMP_EQ_OQ); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1192(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_cmp_pd(_mm_and_pd(x, y), x, _CMP_EQ_OQ); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1193(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_cmp_pd(y, _mm_and_pd(x, y), _CMP_EQ_OQ); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1194(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_cmp_pd(_mm_or_pd(x, y), y, _CMP_EQ_OQ); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1195(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_cmp_pd(x, _mm_or_pd(x, y), _CMP_EQ_OQ); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1196(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_cmp_pd(_mm_or_pd(x, y), x, _CMP_EQ_OQ); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1197(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_cmp_pd(y, _mm_or_pd(x, y), _CMP_EQ_OQ); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1198(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_cmp_pd(_mm_xor_pd(x, y), y, _CMP_EQ_OQ); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1199(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_cmp_pd(x, _mm_xor_pd(x, y), _CMP_EQ_OQ); _mm_storeu_pd((double*)po, r); }
extern const Entry table_36[] = {
  {"128:_mm_mul_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_LE_OS)), x)", f0, 2, 128},
  {"128:_mm_mul_pd(y, _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_LE_OS)))", f1, 2, 128},
  {"128:_mm_mul_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_LE_OS)), y)", f2, 2, 128},
  {"128:_mm_mul_pd(x, _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_LE_OS)))", f3, 2, 128},
  {"128:_mm_mul_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_LE_OS)), x)", f4, 2, 128},
  {"128:_mm_mul_pd(y, _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_LE_OS)))", f5, 2, 128},
  {"128:_mm_mul_pd(_mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_LE_OS), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_LE_OS), y)), y)", f6, 2, 128},
  {"128:_mm_mul_pd(x, _mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_LE_OS), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_LE_OS), y)))", f7, 2, 128},
  {"128:_mm_mul_pd(_mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_LE_OS), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_LE_OS), y)), x)", f8, 2, 128},
  {"128:_mm_mul_pd(y, _mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_LE_OS), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_LE_OS), y)))", f9, 2, 128},
  {"128:_mm_mul_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_GT_OS)), y)", f10, 2, 128},
  {"128:_mm_mul_pd(x, _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_GT_OS)))", f11, 2, 128},
  {"128:_mm_mul_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_GT_OS)), x)", f12, 2, 128},
  {"128:_mm_mul_pd(y, _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_GT_OS)))", f13, 2, 128},
  {"128:_mm_mul_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_GT_OS)), y)", f14, 2, 128},
  {"128:_mm_mul_pd(x, _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_GT_OS)))", f15, 2, 128},
  {"128:_mm_mul_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_GT_OS)), x)", f16, 2, 128},
  {"128:_mm_mul_pd(y, _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_GT_OS)))", f17, 2, 128},
  {"128:_mm_mul_pd(_mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_GT_OS), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_GT_OS), y)), y)", f18, 2, 128},
  {"128:_mm_mul_pd(x, _mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_GT_OS), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_GT_OS), y)))", f19, 2, 128},
  {"128:_mm_mul_pd(_mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_GT_OS), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_GT_OS), y)), x)", f20, 2, 128},
  {"128:_mm_mul_pd(y, _mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_GT_OS), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_GT_OS), y)))", f21, 2, 128},
  {"128:_mm_mul_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_NLT_US)), y)", f22, 2, 128},
  {"128:_mm_mul_pd(x, _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_NLT_US)))", f23, 2, 128},
  {"128:_mm_mul_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_NLT_US)), x)", f24, 2, 128},
  {"128:_mm_mul_pd(y, _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_NLT_US)))", f25, 2, 128},
  {"128:_mm_mul_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_NLT_US)), y)", f26, 2, 128},
  {"128:_mm_mul_pd(x, _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_NLT_US)))", f27, 2, 128},
  {"128:_mm_mul_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_NLT_US)), x)", f28, 2, 128},
  {"128:_mm_mul_pd(y, _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_NLT_US)))", f29, 2, 128},
  {"128:_mm_mul_pd(_mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_NLT_US), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_NLT_US), y)), y)", f30, 2, 128},
  {"128:_mm_mul_pd(x, _mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_NLT_US), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_NLT_US), y)))", f31, 2, 128},
  {"128:_mm_mul_pd(_mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_NLT_US), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_NLT_US), y)), x)", f32, 2, 128},
  {"128:_mm_mul_pd(y, _mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_NLT_US), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_NLT_US), y)))", f33, 2, 128},
  {"128:_mm_mul_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_EQ_OQ)), y)", f34, 2, 128},
  {"128:_mm_mul_pd(x, _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_EQ_OQ)))", f35, 2, 128},
  {"128:_mm_mul_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_EQ_OQ)), x)", f36, 2, 128},
  {"128:_mm_mul_pd(y, _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_EQ_OQ)))", f37, 2, 128},
  {"128:_mm_mul_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_EQ_OQ)), y)", f38, 2, 128},
  {"128:_mm_mul_pd(x, _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_EQ_OQ)))", f39, 2, 128},
  {"128:_mm_mul_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_EQ_OQ)), x)", f40, 2, 128},
  {"128:_mm_mul_pd(y, _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_EQ_OQ)))", f41, 2, 128},
  {"128:_mm_mul_pd(_mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_EQ_OQ), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_EQ_OQ), y)), y)", f42, 2, 128},
  {"128:_mm_mul_pd(x, _mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_EQ_OQ), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_EQ_OQ), y)))", f43, 2, 128},
  {"128:_mm_mul_pd(_mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_EQ_OQ), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_EQ_OQ), y)), x)", f44, 2, 128},
  {"128:_mm_mul_pd(y, _mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_EQ_OQ), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_EQ_OQ), y)))", f45, 2, 128},
  {"128:_mm_mul_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_UNORD_Q)), y)", f46, 2, 128},
  {"128:_mm_mul_pd(x, _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_UNORD_Q)))", f47, 2, 128},
  {"128:_mm_mul_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_UNORD_Q)), x)", f48, 2, 128},
  {"128:_mm_mul_pd(y, _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_UNORD_Q)))", f49, 2, 128},
  {"128:_mm_mul_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_UNORD_Q)), y)", f50, 2, 128},
  {"128:_mm_mul_pd(x, _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_UNORD_Q)))", f51, 2, 128},
  {"128:_mm_mul_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_UNORD_Q)), x)", f52, 2, 128},
  {"128:_mm_mul_pd(y, _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_UNORD_Q)))", f53, 2, 128},
  {"128:_mm_mul_pd(_mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_UNORD_Q), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_UNORD_Q), y)), y)", f54, 2, 128},
  {"128:_mm_mul_pd(x, _mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_UNORD_Q), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_UNORD_Q), y)))", f55, 2, 128},
  {"128:_mm_mul_pd(_mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_UNORD_Q), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_UNORD_Q), y)), x)", f56, 2, 128},
  {"128:_mm_mul_pd(y, _mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_UNORD_Q), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_UNORD_Q), y)))", f57, 2, 128},
  {"128:_mm_mul_pd(_mm_unpacklo_pd(x, y), y)", f58, 2, 128},
  {"128:_mm_mul_pd(x, _mm_unpacklo_pd(x, y))", f59, 2, 128},
  {"128:_mm_mul_pd(_mm_unpacklo_pd(x, y), x)", f60, 2, 128},
  {"128:_mm_mul_pd(y, _mm_unpacklo_pd(x, y))", f61, 2, 128},
  {"128:_mm_mul_pd(_mm_unpackhi_pd(x, y), y)", f62, 2, 128},
  {"128:_mm_mul_pd(x, _mm_unpackhi_pd(x, y))", f63, 2, 128},
  {"128:_mm_mul_pd(_mm_unpackhi_pd(x, y), x)", f64, 2, 128},
  {"128:_mm_mul_pd(y, _mm_unpackhi_pd(x, y))", f65, 2, 128},
  {"128:_mm_mul_pd(_mm_hadd_pd(x, y), y)", f66, 2, 128},
  {"128:_mm_mul_pd(x, _mm_hadd_pd(x, y))", f67, 2, 128},
  {"128:_mm_mul_pd(_mm_hadd_pd(x, y), x)", f68, 2, 128},
  {"128:_mm_mul_pd(y, _mm_hadd_pd(x, y))", f69, 2, 128},
  {"128:_mm_mul_pd(_mm_hsub_pd(x, y), y)", f70, 2, 128},
  {"128:_mm_mul_pd(x, _mm_hsub_pd(x, y))", f71, 2, 128},
  {"128:_mm_mul_pd(_mm_hsub_pd(x, y), x)", f72, 2, 128},
  {"128:_mm_mul_pd(y, _mm_hsub_pd(x, y))", f73, 2, 128},
  {"128:_mm_div_pd(_mm_add_pd(x, y), y)", f74, 2, 128},
  {"128:_mm_div_pd(x, _mm_add_pd(x, y))", f75, 2, 128},
  {"128:_mm_div_pd(_mm_add_pd(x, y), x)", f76, 2, 128},
  {"128:_mm_div_pd(y, _mm_add_pd(x, y))", f77, 2, 128},
  {"128:_mm_div_pd(_mm_sub_pd(x, y), y)", f78, 2, 128},
  {"128:_mm_div_pd(x, _mm_sub_pd(x, y))", f79, 2, 128},
  {"128:_mm_div_pd(_mm_sub_pd(x, y), x)", f80, 2, 128},
  {"128:_mm_div_pd(y, _mm_sub_pd(x, y))", f81, 2, 128},
  {"128:_mm_div_pd(_mm_mul_pd(x, y), y)", f82, 2, 128},
  {"128:_mm_div_pd(x, _mm_mul_pd(x, y))", f83, 2, 128},
  {"128:_mm_div_pd(_mm_mul_pd(x, y), x)", f84, 2, 128},
  {"128:_mm_div_pd(y, _mm_mul_pd(x, y))", f85, 2, 128},
  {"128:_mm_div_pd(_mm_div_pd(x, y), y)", f86, 2, 128},
  {"128:_mm_div_pd(x, _mm_div_pd(x, y))", f87, 2, 128},
  {"128:_mm_div_pd(_mm_div_pd(x, y), x)", f88, 2, 128},
  {"128:_mm_div_pd(y, _mm_div_pd(x, y))", f89, 2, 128},
  {"128:_mm_div_pd(_mm_min_pd(x, y), y)", f90, 2, 128},
  {"128:_mm_div_pd(x, _mm_min_pd(x, y))", f91, 2, 128},
  {"128:_mm_div_pd(_mm_min_pd(x, y), x)", f92, 2, 128},
  {"128:_mm_div_pd(y, _mm_min_pd(x, y))", f93, 2, 128},
  {"128:_mm_div_pd(_mm_max_pd(x, y), y)", f94, 2, 128},
  {"128:_mm_div_pd(x, _mm_max_pd(x, y))", f95, 2, 128},
  {"128:_mm_div_pd(_mm_max_pd(x, y), x)", f96, 2, 128},
  {"128:_mm_div_pd(y, _mm_max_pd(x, y))", f97, 2, 128},
  {"128:_mm_div_pd(_mm_and_pd(x, y), y)", f98, 2, 128},
  {"128:_mm_div_pd(x, _mm_and_pd(x, y))", f99, 2, 128},
  {"128:_mm_div_pd(_mm_and_pd(x, y), x)", f100, 2, 128},
  {"128:_mm_div_pd(y, _mm_and_pd(x, y))", f101, 2, 128},
  {"128:_mm_div_pd(_mm_or_pd(x, y), y)", f102, 2, 128},
  {"128:_mm_div_pd(x, _mm_or_pd(x, y))", f103, 2, 128},
  {"128:_mm_div_pd(_mm_or_pd(x, y), x)", f104, 2, 128},
  {"128:_mm_div_pd(y, _mm_or_pd(x, y))", f105, 2, 128},
  {"128:_mm_div_pd(_mm_xor_pd(x, y), y)", f106, 2, 128},
  {"128:_mm_div_pd(x, _mm_xor_pd(x, y))", f107, 2, 128},
  {"128:_mm_div_pd(_mm_xor_pd(x, y), x)", f108, 2, 128},
  {"128:_mm_div_pd(y, _mm_xor_pd(x, y))", f109, 2, 128},
  {"128:_mm_div_pd(_mm_andnot_pd(x, y), y)", f110, 2, 128},
  {"128:_mm_div_pd(x, _mm_andnot_pd(x, y))", f111, 2, 128},
  {"128:_mm_div_pd(_mm_andnot_pd(x, y), x)", f112, 2, 128},
  {"128:_mm_div_pd(y, _mm_andnot_pd(x, y))", f113, 2, 128},
  {"128:_mm_div_pd(_mm_cmp_pd(x, y, _CMP_EQ_OQ), y)", f114, 2, 128},
  {"128:_mm_div_pd(x, _mm_cmp_pd(x, y, _CMP_EQ_OQ))", f115, 2, 128},
  {"128:_mm_div_pd(_mm_cmp_pd(x, y, _CMP_EQ_OQ), x)", f116, 2, 128},
  {"128:_mm_div_pd(y, _mm_cmp_pd(x, y, _CMP_EQ_OQ))", f117, 2, 128},
  {"128:_mm_div_pd(_mm_cmp_pd(x, y, _CMP_LT_OS), y)", f118, 2, 128},
  {"128:_mm_div_pd(x, _mm_cmp_pd(x, y, _CMP_LT_OS))", f119, 2, 128},
  {"128:_mm_div_pd(_mm_cmp_pd(x, y, _CMP_LT_OS), x)", f120, 2, 128},
  {"128:_mm_div_pd(y, _mm_cmp_pd(x, y, _CMP_LT_OS))", f121, 2, 128},
  {"128:_mm_div_pd(_mm_cmp_pd(x, y, _CMP_LE_OS), y)", f122, 2, 128},
  {"128:_mm_div_pd(x, _mm_cmp_pd(x, y, _CMP_LE_OS))", f123, 2, 128},
  {"128:_mm_div_pd(_mm_cmp_pd(x, y, _CMP_LE_OS), x)", f124, 2, 128},
  {"128:_mm_div_pd(y, _mm_cmp_pd(x, y, _CMP_LE_OS))", f125, 2, 128},
  {"128:_mm_div_pd(_mm_cmp_pd(x, y, _CMP_NEQ_UQ), y)", f126, 2, 128},
  {"128:_mm_div_pd(x, _mm_cmp_pd(x, y, _CMP_NEQ_UQ))", f127, 2, 128},
  {"128:_mm_div_pd(_mm_cmp_pd(x, y, _CMP_NEQ_UQ), x)", f128, 2, 128},
  {"128:_mm_div_pd(y, _mm_cmp_pd(x, y, _CMP_NEQ_UQ))", f129, 2, 128},
  {"128:_mm_div_pd(_mm_cmp_pd(x, y, _CMP_UNORD_Q), y)", f130, 2, 128},
  {"128:_mm_div_pd(x, _mm_cmp_pd(x, y, _CMP_UNORD_Q))", f131, 2, 128},
  {"128:_mm_div_pd(_mm_cmp_pd(x, y, _CMP_UNORD_Q), x)", f132, 2, 128},
  {"128:_mm_div_pd(y, _mm_cmp_pd(x, y, _CMP_UNORD_Q))", f133, 2, 128},
  {"128:_mm_div_pd(_mm_cmp_pd(x, y, _CMP_NLT_US), y)", f134, 2, 128},
  {"128:_mm_div_pd(x, _mm_cmp_pd(x, y, _CMP_NLT_US))", f135, 2, 128},
  {"128:_mm_div_pd(_mm_cmp_pd(x, y, _CMP_NLT_US), x)", f136, 2, 128},
  {"128:_mm_div_pd(y, _mm_cmp_pd(x, y, _CMP_NLT_US))", f137, 2, 128},
  {"128:_mm_div_pd(_mm_cmp_pd(x, y, _CMP_GT_OS), y)", f138, 2, 128},
  {"128:_mm_div_pd(x, _mm_cmp_pd(x, y, _CMP_GT_OS))", f139, 2, 128},
  {"128:_mm_div_pd(_mm_cmp_pd(x, y, _CMP_GT_OS), x)", f140, 2, 128},
  {"128:_mm_div_pd(y, _mm_cmp_pd(x, y, _CMP_GT_OS))", f141, 2, 128},
  {"128:_mm_div_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_LT_OS)), y)", f142, 2, 128},
  {"128:_mm_div_pd(x, _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_LT_OS)))", f143, 2, 128},
  {"128:_mm_div_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_LT_OS)), x)", f144, 2, 128},
  {"128:_mm_div_pd(y, _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_LT_OS)))", f145, 2, 128},
  {"128:_mm_div_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_LT_OS)), y)", f146, 2, 128},
  {"128:_mm_div_pd(x, _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_LT_OS)))", f147, 2, 128},
  {"128:_mm_div_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_LT_OS)), x)", f148, 2, 128},
  {"128:_mm_div_pd(y, _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_LT_OS)))", f149, 2, 128},
  {"128:_mm_div_pd(_mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_LT_OS), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_LT_OS), y)), y)", f150, 2, 128},
  {"128:_mm_div_pd(x, _mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_LT_OS), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_LT_OS), y)))", f151, 2, 128},
  {"128:_mm_div_pd(_mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_LT_OS), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_LT_OS), y)), x)", f152, 2, 128},
  {"128:_mm_div_pd(y, _mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_LT_OS), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_LT_OS), y)))", f153, 2, 128},
  {"128:_mm_div_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_LE_OS)), y)", f154, 2, 128},
  {"128:_mm_div_pd(x, _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_LE_OS)))", f155, 2, 128},
  {"128:_mm_div_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_LE_OS)), x)", f156, 2, 128},
  {"128:_mm_div_pd(y, _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_LE_OS)))", f157, 2, 128},
  {"128:_mm_div_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_LE_OS)), y)", f158, 2, 128},
  {"128:_mm_div_pd(x, _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_LE_OS)))", f159, 2, 128},
  {"128:_mm_div_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_LE_OS)), x)", f160, 2, 128},
  {"128:_mm_div_pd(y, _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_LE_OS)))", f161, 2, 128},
  {"128:_mm_div_pd(_mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_LE_OS), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_LE_OS), y)), y)", f162, 2, 128},
  {"128:_mm_div_pd(x, _mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_LE_OS), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_LE_OS), y)))", f163, 2, 128},
  {"128:_mm_div_pd(_mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_LE_OS), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_LE_OS), y)), x)", f164, 2, 128},
  {"128:_mm_div_pd(y, _mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_LE_OS), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_LE_OS), y)))", f165, 2, 128},
  {"128:_mm_div_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_GT_OS)), y)", f166, 2, 128},
  {"128:_mm_div_pd(x, _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_GT_OS)))", f167, 2, 128},
  {"128:_mm_div_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_GT_OS)), x)", f168, 2, 128},
  {"128:_mm_div_pd(y, _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_GT_OS)))", f169, 2, 128},
  {"128:_mm_div_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_GT_OS)), y)", f170, 2, 128},
  {"128:_mm_div_pd(x, _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_GT_OS)))", f171, 2, 128},
  {"128:_mm_div_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_GT_OS)), x)", f172, 2, 128},
  {"128:_mm_div_pd(y, _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_GT_OS)))", f173, 2, 128},
  {"128:_mm_div_pd(_mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_GT_OS), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_GT_OS), y)), y)", f174, 2, 128},
  {"128:_mm_div_pd(x, _mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_GT_OS), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_GT_OS), y)))", f175, 2, 128},
  {"128:_mm_div_pd(_mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_GT_OS), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_GT_OS), y)), x)", f176, 2, 128},
  {"128:_mm_div_pd(y, _mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_GT_OS), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_GT_OS), y)))", f177, 2, 128},
  {"128:_mm_div_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_NLT_US)), y)", f178, 2, 128},
  {"128:_mm_div_pd(x, _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_NLT_US)))", f179, 2, 128},
  {"128:_mm_div_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_NLT_US)), x)", f180, 2, 128},
  {"128:_mm_div_pd(y, _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_NLT_US)))", f181, 2, 128},
  {"128:_mm_div_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_NLT_US)), y)", f182, 2, 128},
  {"128:_mm_div_pd(x, _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_NLT_US)))", f183, 2, 128},
  {"128:_mm_div_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_NLT_US)), x)", f184, 2, 128},
  {"128:_mm_div_pd(y, _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_NLT_US)))", f185, 2, 128},
  {"128:_mm_div_pd(_mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_NLT_US), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_NLT_US), y)), y)", f186, 2, 128},
  {"128:_mm_div_pd(x, _mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_NLT_US), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_NLT_US), y)))", f187, 2, 128},
  {"128:_mm_div_pd(_mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_NLT_US), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_NLT_US), y)), x)", f188, 2, 128},
  {"128:_mm_div_pd(y, _mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_NLT_US), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_NLT_US), y)))", f189, 2, 128},
  {"128:_mm_div_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_EQ_OQ)), y)", f190, 2, 128},
  {"128:_mm_div_pd(x, _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_EQ_OQ)))", f191, 2, 128},
  {"128:_mm_div_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_EQ_OQ)), x)", f192, 2, 128},
  {"128:_mm_div_pd(y, _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_EQ_OQ)))", f193, 2, 128},
  {"128:_mm_div_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_EQ_OQ)), y)", f194, 2, 128},
  {"128:_mm_div_pd(x, _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_EQ_OQ)))", f195, 2, 128},
  {"128:_mm_div_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_EQ_OQ)), x)", f196, 2, 128},
  {"128:_mm_div_pd(y, _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_EQ_OQ)))", f197, 2, 128},
  {"128:_mm_div_pd(_mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_EQ_OQ), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_EQ_OQ), y)), y)", f198, 2, 128},
  {"128:_mm_div_pd(x, _mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_EQ_OQ), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_EQ_OQ), y)))", f199, 2, 128},
  {"128:_mm_div_pd(_mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_EQ_OQ), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_EQ_OQ), y)), x)", f200, 2, 128},
  {"128:_mm_div_pd(y, _mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_EQ_OQ), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_EQ_OQ), y)))", f201, 2, 128},
  {"128:_mm_div_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_UNORD_Q)), y)", f202, 2, 128},
  {"128:_mm_div_pd(x, _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_UNORD_Q)))", f203, 2, 128},
  {"128:_mm_div_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_UNORD_Q)), x)", f204, 2, 128},
  {"128:_mm_div_pd(y, _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_UNORD_Q)))", f205, 2, 128},
  {"128:_mm_div_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_UNORD_Q)), y)", f206, 2, 128},
  {"128:_mm_div_pd(x, _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_UNORD_Q)))", f207, 2, 128},
  {"128:_mm_div_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_UNORD_Q)), x)", f208, 2, 128},
  {"128:_mm_div_pd(y, _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_UNORD_Q)))", f209, 2, 128},
  {"128:_mm_div_pd(_mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_UNORD_Q), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_UNORD_Q), y)), y)", f210, 2, 128},
  {"128:_mm_div_pd(x, _mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_UNORD_Q), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_UNORD_Q), y)))", f211, 2, 128},
  {"128:_mm_div_pd(_mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_UNORD_Q), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_UNORD_Q), y)), x)", f212, 2, 128},
  {"128:_mm_div_pd(y, _mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_UNORD_Q), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_UNORD_Q), y)))", f213, 2, 128},
  {"128:_mm_div_pd(_mm_unpacklo_pd(x, y), y)", f214, 2, 128},
  {"128:_mm_div_pd(x, _mm_unpacklo_pd(x, y))", f215, 2, 128},
  {"128:_mm_div_pd(_mm_unpacklo_pd(x, y), x)", f216, 2, 128},
  {"128:_mm_div_pd(y, _mm_unpacklo_pd(x, y))", f217, 2, 128},
  {"128:_mm_div_pd(_mm_unpackhi_pd(x, y), y)", f218, 2, 128},
  {"128:_mm_div_pd(x, _mm_unpackhi_pd(x, y))", f219, 2, 128},
  {"128:_mm_div_pd(_mm_unpackhi_pd(x, y), x)", f220, 2, 128},
  {"128:_mm_div_pd(y, _mm_unpackhi_pd(x, y))", f221, 2, 128},
  {"128:_mm_div_pd(_mm_hadd_pd(x, y), y)", f222, 2, 128},
  {"128:_mm_div_pd(x, _mm_hadd_pd(x, y))", f223, 2, 128},
  {"128:_mm_div_pd(_mm_hadd_pd(x, y), x)", f224, 2, 128},
  {"128:_mm_div_pd(y, _mm_hadd_pd(x, y))", f225, 2, 128},
  {"128:_mm_div_pd(_mm_hsub_pd(x, y), y)", f226, 2, 128},
  {"128:_mm_div_pd(x, _mm_hsub_pd(x, y))", f227, 2, 128},
  {"128:_mm_div_pd(_mm_hsub_pd(x, y), x)", f228, 2, 128},
  {"128:_mm_div_pd(y, _mm_hsub_pd(x, y))", f229, 2, 128},
  {"128:_mm_min_pd(_mm_add_pd(x, y), y)", f230, 2, 128},
  {"128:_mm_min_pd(x, _mm_add_pd(x, y))", f231, 2, 128},
  {"128:_mm_min_pd(_mm_add_pd(x, y), x)", f232, 2, 128},
  {"128:_mm_min_pd(y, _mm_add_pd(x, y))", f233, 2, 128},
  {"128:_mm_min_pd(_mm_sub_pd(x, y), y)", f234, 2, 128},
  {"128:_mm_min_pd(x, _mm_sub_pd(x, y))", f235, 2, 128},
  {"128:_mm_min_pd(_mm_sub_pd(x, y), x)", f236, 2, 128},
  {"128:_mm_min_pd(y, _mm_sub_pd(x, y))", f237, 2, 128},
  {"128:_mm_min_pd(_mm_mul_pd(x, y), y)", f238, 2, 128},
  {"128:_mm_min_pd(x, _mm_mul_pd(x, y))", f239, 2, 128},
  {"128:_mm_min_pd(_mm_mul_pd(x, y), x)", f240, 2, 128},
  {"128:_mm_min_pd(y, _mm_mul_pd(x, y))", f241, 2, 128},
  {"128:_mm_min_pd(_mm_div_pd(x, y), y)", f242, 2, 128},
  {"128:_mm_min_pd(x, _mm_div_pd(x, y))", f243, 2, 128},
  {"128:_mm_min_pd(_mm_div_pd(x, y), x)", f244, 2, 128},
  {"128:_mm_min_pd(y, _mm_div_pd(x, y))", f245, 2, 128},
  {"128:_mm_min_pd(_mm_min_pd(x, y), y)", f246, 2, 128},
  {"128:_mm_min_pd(x, _mm_min_pd(x, y))", f247, 2, 128},
  {"128:_mm_min_pd(_mm_min_pd(x, y), x)", f248, 2, 128},
  {"128:_mm_min_pd(y, _mm_min_pd(x, y))", f249, 2, 128},
  {"128:_mm_min_pd(_mm_max_pd(x, y), y)", f250, 2, 128},
  {"128:_mm_min_pd(x, _mm_max_pd(x, y))", f251, 2, 128},
  {"128:_mm_min_pd(_mm_max_pd(x, y), x)", f252, 2, 128},
  {"128:_mm_min_pd(y, _mm_max_pd(x, y))", f253, 2, 128},
  {"128:_mm_min_pd(_mm_and_pd(x, y), y)", f254, 2, 128},
  {"128:_mm_min_pd(x, _mm_and_pd(x, y))", f255, 2, 128},
  {"128:_mm_min_pd(_mm_and_pd(x, y), x)", f256, 2, 128},
  {"128:_mm_min_pd(y, _mm_and_pd(x, y))", f257, 2, 128},
  {"128:_mm_min_pd(_mm_or_pd(x, y), y)", f258, 2, 128},
  {"128:_mm_min_pd(x, _mm_or_pd(x, y))", f259, 2, 128},
  {"128:_mm_min_pd(_mm_or_pd(x, y), x)", f260, 2, 128},
  {"128:_mm_min_pd(y, _mm_or_pd(x, y))", f261, 2, 128},
  {"128:_mm_min_pd(_mm_xor_pd(x, y), y)", f262, 2, 128},
  {"128:_mm_min_pd(x, _mm_xor_pd(x, y))", f263, 2, 128},
  {"128:_mm_min_pd(_mm_xor_pd(x, y), x)", f264, 2, 128},
  {"128:_mm_min_pd(y, _mm_xor_pd(x, y))", f265, 2, 128},
  {"128:_mm_min_pd(_mm_andnot_pd(x, y), y)", f266, 2, 128},
  {"128:_mm_min_pd(x, _mm_andnot_pd(x, y))", f267, 2, 128},
  {"128:_mm_min_pd(_mm_andnot_pd(x, y), x)", f268, 2, 128},
  {"128:_mm_min_pd(y, _mm_andnot_pd(x, y))", f269, 2, 128},
  {"128:_mm_min_pd(_mm_cmp_pd(x, y, _CMP_EQ_OQ), y)", f270, 2, 128},
  {"128:_mm_min_pd(x, _mm_cmp_pd(x, y, _CMP_EQ_OQ))", f271, 2, 128},
  {"128:_mm_min_pd(_mm_cmp_pd(x, y, _CMP_EQ_OQ), x)", f272, 2, 128},
  {"128:_mm_min_pd(y, _mm_cmp_pd(x, y, _CMP_EQ_OQ))", f273, 2, 128},
  {"128:_mm_min_pd(_mm_cmp_pd(x, y, _CMP_LT_OS), y)", f274, 2, 128},
  {"128:_mm_min_pd(x, _mm_cmp_pd(x, y, _CMP_LT_OS))", f275, 2, 128},
  {"128:_mm_min_pd(_mm_cmp_pd(x, y, _CMP_LT_OS), x)", f276, 2, 128},
  {"128:_mm_min_pd(y, _mm_cmp_pd(x, y, _CMP_LT_OS))", f277, 2, 128},
  {"128:_mm_min_pd(_mm_cmp_pd(x, y, _CMP_LE_OS), y)", f278, 2, 128},
  {"128:_mm_min_pd(x, _mm_cmp_pd(x, y, _CMP_LE_OS))", f279, 2, 128},
  {"128:_mm_min_pd(_mm_cmp_pd(x, y, _CMP_LE_OS), x)", f280, 2, 128},
  {"128:_mm_min_pd(y, _mm_cmp_pd(x, y, _CMP_LE_OS))", f281, 2, 128},
  {"128:_mm_min_pd(_mm_cmp_pd(x, y, _CMP_NEQ_UQ), y)", f282, 2, 128},
  {"128:_mm_min_pd(x, _mm_cmp_pd(x, y, _CMP_NEQ_UQ))", f283, 2, 128},
  {"128:_mm_min_pd(_mm_cmp_pd(x, y, _CMP_NEQ_UQ), x)", f284, 2, 128},
  {"128:_mm_min_pd(y, _mm_cmp_pd(x, y, _CMP_NEQ_UQ))", f285, 2, 128},
  {"128:_mm_min_pd(_mm_cmp_pd(x, y, _CMP_UNORD_Q), y)", f286, 2, 128},
  {"128:_mm_min_pd(x, _mm_cmp_pd(x, y, _CMP_UNORD_Q))", f287, 2, 128},
  {"128:_mm_min_pd(_mm_cmp_pd(x, y, _CMP_UNORD_Q), x)", f288, 2, 128},
  {"128:_mm_min_pd(y, _mm_cmp_pd(x, y, _CMP_UNORD_Q))", f289, 2, 128},
  {"128:_mm_min_pd(_mm_cmp_pd(x, y, _CMP_NLT_US), y)", f290, 2, 128},
  {"128:_mm_min_pd(x, _mm_cmp_pd(x, y, _CMP_NLT_US))", f291, 2, 128},
  {"128:_mm_min_pd(_mm_cmp_pd(x, y, _CMP_NLT_US), x)", f292, 2, 128},
  {"128:_mm_min_pd(y, _mm_cmp_pd(x, y, _CMP_NLT_US))", f293, 2, 128},
  {"128:_mm_min_pd(_mm_cmp_pd(x, y, _CMP_GT_OS), y)", f294, 2, 128},
  {"128:_mm_min_pd(x, _mm_cmp_pd(x, y, _CMP_GT_OS))", f295, 2, 128},
  {"128:_mm_min_pd(_mm_cmp_pd(x, y, _CMP_GT_OS), x)", f296, 2, 128},
  {"128:_mm_min_pd(y, _mm_cmp_pd(x, y, _CMP_GT_OS))", f297, 2, 128},
  {"128:_mm_min_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_LT_OS)), y)", f298, 2, 128},
  {"128:_mm_min_pd(x, _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_LT_OS)))", f299, 2, 128},
  {"128:_mm_min_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_LT_OS)), x)", f300, 2, 128},
  {"128:_mm_min_pd(y, _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_LT_OS)))", f301, 2, 128},
  {"128:_mm_min_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_LT_OS)), y)", f302, 2, 128},
  {"128:_mm_min_pd(x, _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_LT_OS)))", f303, 2, 128},
  {"128:_mm_min_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_LT_OS)), x)", f304, 2, 128},
  {"128:_mm_min_pd(y, _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_LT_OS)))", f305, 2, 128},
  {"128:_mm_min_pd(_mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_LT_OS), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_LT_OS), y)), y)", f306, 2, 128},
  {"128:_mm_min_pd(x, _mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_LT_OS), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_LT_OS), y)))", f307, 2, 128},
  {"128:_mm_min_pd(_mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_LT_OS), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_LT_OS), y)), x)", f308, 2, 128},
  {"128:_mm_min_pd(y, _mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_LT_OS), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_LT_OS), y)))", f309, 2, 128},
  {"128:_mm_min_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_LE_OS)), y)", f310, 2, 128},
  {"128:_mm_min_pd(x, _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_LE_OS)))", f311, 2, 128},
  {"128:_mm_min_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_LE_OS)), x)", f312, 2, 128},
  {"128:_mm_min_pd(y, _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_LE_OS)))", f313, 2, 128},
  {"128:_mm_min_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_LE_OS)), y)", f314, 2, 128},
  {"128:_mm_min_pd(x, _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_LE_OS)))", f315, 2, 128},
  {"128:_mm_min_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_LE_OS)), x)", f316, 2, 128},
  {"128:_mm_min_pd(y, _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_LE_OS)))", f317, 2, 128},
  {"128:_mm_min_pd(_mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_LE_OS), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_LE_OS), y)), y)", f318, 2, 128},
  {"128:_mm_min_pd(x, _mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_LE_OS), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_LE_OS), y)))", f319, 2, 128},
  {"128:_mm_min_pd(_mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_LE_OS), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_LE_OS), y)), x)", f320, 2, 128},
  {"128:_mm_min_pd(y, _mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_LE_OS), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_LE_OS), y)))", f321, 2, 128},
  {"128:_mm_min_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_GT_OS)), y)", f322, 2, 128},
  {"128:_mm_min_pd(x, _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_GT_OS)))", f323, 2, 128},
  {"128:_mm_min_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_GT_OS)), x)", f324, 2, 128},
  {"128:_mm_min_pd(y, _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_GT_OS)))", f325, 2, 128},
  {"128:_mm_min_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_GT_OS)), y)", f326, 2, 128},
  {"128:_mm_min_pd(x, _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_GT_OS)))", f327, 2, 128},
  {"128:_mm_min_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_GT_OS)), x)", f328, 2, 128},
  {"128:_mm_min_pd(y, _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_GT_OS)))", f329, 2, 128},
  {"128:_mm_min_pd(_mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_GT_OS), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_GT_OS), y)), y)", f330, 2, 128},
  {"128:_mm_min_pd(x, _mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_GT_OS), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_GT_OS), y)))", f331, 2, 128},
  {"128:_mm_min_pd(_mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_GT_OS), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_GT_OS), y)), x)", f332, 2, 128},
  {"128:_mm_min_pd(y, _mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_GT_OS), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_GT_OS), y)))", f333, 2, 128},
  {"128:_mm_min_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_NLT_US)), y)", f334, 2, 128},
  {"128:_mm_min_pd(x, _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_NLT_US)))", f335, 2, 128},
  {"128:_mm_min_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_NLT_US)), x)", f336, 2, 128},
  {"128:_mm_min_pd(y, _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_NLT_US)))", f337, 2, 128},
  {"128:_mm_min_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_NLT_US)), y)", f338, 2, 128},
  {"128:_mm_min_pd(x, _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_NLT_US)))", f339, 2, 128},
  {"128:_mm_min_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_NLT_US)), x)", f340, 2, 128},
  {"128:_mm_min_pd(y, _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_NLT_US)))", f341, 2, 128},
  {"128:_mm_min_pd(_mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_NLT_US), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_NLT_US), y)), y)", f342, 2, 128},
  {"128:_mm_min_pd(x, _mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_NLT_US), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_NLT_US), y)))", f343, 2, 128},
  {"128:_mm_min_pd(_mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_NLT_US), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_NLT_US), y)), x)", f344, 2, 128},
  {"128:_mm_min_pd(y, _mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_NLT_US), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_NLT_US), y)))", f345, 2, 128},
  {"128:_mm_min_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_EQ_OQ)), y)", f346, 2, 128},
  {"128:_mm_min_pd(x, _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_EQ_OQ)))", f347, 2, 128},
  {"128:_mm_min_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_EQ_OQ)), x)", f348, 2, 128},
  {"128:_mm_min_pd(y, _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_EQ_OQ)))", f349, 2, 128},
  {"128:_mm_min_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_EQ_OQ)), y)", f350, 2, 128},
  {"128:_mm_min_pd(x, _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_EQ_OQ)))", f351, 2, 128},
  {"128:_mm_min_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_EQ_OQ)), x)", f352, 2, 128},
  {"128:_mm_min_pd(y, _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_EQ_OQ)))", f353, 2, 128},
  {"128:_mm_min_pd(_mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_EQ_OQ), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_EQ_OQ), y)), y)", f354, 2, 128},
  {"128:_mm_min_pd(x, _mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_EQ_OQ), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_EQ_OQ), y)))", f355, 2, 128},
  {"128:_mm_min_pd(_mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_EQ_OQ), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_EQ_OQ), y)), x)", f356, 2, 128},
  {"128:_mm_min_pd(y, _mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_EQ_OQ), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_EQ_OQ), y)))", f357, 2, 128},
  {"128:_mm_min_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_UNORD_Q)), y)", f358, 2, 128},
  {"128:_mm_min_pd(x, _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_UNORD_Q)))", f359, 2, 128},
  {"128:_mm_min_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_UNORD_Q)), x)", f360, 2, 128},
  {"128:_mm_min_pd(y, _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_UNORD_Q)))", f361, 2, 128},
  {"128:_mm_min_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_UNORD_Q)), y)", f362, 2, 128},
  {"128:_mm_min_pd(x, _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_UNORD_Q)))", f363, 2, 128},
  {"128:_mm_min_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_UNORD_Q)), x)", f364, 2, 128},
  {"128:_mm_min_pd(y, _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_UNORD_Q)))", f365, 2, 128},
  {"128:_mm_min_pd(_mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_UNORD_Q), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_UNORD_Q), y)), y)", f366, 2, 128},
  {"128:_mm_min_pd(x, _mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_UNORD_Q), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_UNORD_Q), y)))", f367, 2, 128},
  {"128:_mm_min_pd(_mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_UNORD_Q), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_UNORD_Q), y)), x)", f368, 2, 128},
  {"128:_mm_min_pd(y, _mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_UNORD_Q), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_UNORD_Q), y)))", f369, 2, 128},
  {"128:_mm_min_pd(_mm_unpacklo_pd(x, y), y)", f370, 2, 128},
  {"128:_mm_min_pd(x, _mm_unpacklo_pd(x, y))", f371, 2, 128},
  {"128:_mm_min_pd(_mm_unpacklo_pd(x, y), x)", f372, 2, 128},
  {"128:_mm_min_pd(y, _mm_unpacklo_pd(x, y))", f373, 2, 128},
  {"128:_mm_min_pd(_mm_unpackhi_pd(x, y), y)", f374, 2, 128},
  {"128:_mm_min_pd(x, _mm_unpackhi_pd(x, y))", f375, 2, 128},
  {"128:_mm_min_pd(_mm_unpackhi_pd(x, y), x)", f376, 2, 128},
  {"128:_mm_min_pd(y, _mm_unpackhi_pd(x, y))", f377, 2, 128},
  {"128:_mm_min_pd(_mm_hadd_pd(x, y), y)", f378, 2, 128},
  {"128:_mm_min_pd(x, _mm_hadd_pd(x, y))", f379, 2, 128},
  {"128:_mm_min_pd(_mm_hadd_pd(x, y), x)", f380, 2, 128},
  {"128:_mm_min_pd(y, _mm_hadd_pd(x, y))", f381, 2, 128},
  {"128:_mm_min_pd(_mm_hsub_pd(x, y), y)", f382, 2, 128},
  {"128:_mm_min_pd(x, _mm_hsub_pd(x, y))", f383, 2, 128},
  {"128:_mm_min_pd(_mm_hsub_pd(x, y), x)", f384, 2, 128},
  {"128:_mm_min_pd(y, _mm_hsub_pd(x, y))", f385, 2, 128},
  {"128:_mm_max_pd(_mm_add_pd(x, y), y)", f386, 2, 128},
  {"128:_mm_max_pd(x, _mm_add_pd(x, y))", f387, 2, 128},
  {"128:_mm_max_pd(_mm_add_pd(x, y), x)", f388, 2, 128},
  {"128:_mm_max_pd(y, _mm_add_pd(x, y))", f389, 2, 128},
  {"128:_mm_max_pd(_mm_sub_pd(x, y), y)", f390, 2, 128},
  {"128:_mm_max_pd(x, _mm_sub_pd(x, y))", f391, 2, 128},
  {"128:_mm_max_pd(_mm_sub_pd(x, y), x)", f392, 2, 128},
  {"128:_mm_max_pd(y, _mm_sub_pd(x, y))", f393, 2, 128},
  {"128:_mm_max_pd(_mm_mul_pd(x, y), y)", f394, 2, 128},
  {"128:_mm_max_pd(x, _mm_mul_pd(x, y))", f395, 2, 128},
  {"128:_mm_max_pd(_mm_mul_pd(x, y), x)", f396, 2, 128},
  {"128:_mm_max_pd(y, _mm_mul_pd(x, y))", f397, 2, 128},
  {"128:_mm_max_pd(_mm_div_pd(x, y), y)", f398, 2, 128},
  {"128:_mm_max_pd(x, _mm_div_pd(x, y))", f399, 2, 128},
  {"128:_mm_max_pd(_mm_div_pd(x, y), x)", f400, 2, 128},
  {"128:_mm_max_pd(y, _mm_div_pd(x, y))", f401, 2, 128},
  {"128:_mm_max_pd(_mm_min_pd(x, y), y)", f402, 2, 128},
  {"128:_mm_max_pd(x, _mm_min_pd(x, y))", f403, 2, 128},
  {"128:_mm_max_pd(_mm_min_pd(x, y), x)", f404, 2, 128},
  {"128:_mm_max_pd(y, _mm_min_pd(x, y))", f405, 2, 128},
  {"128:_mm_max_pd(_mm_max_pd(x, y), y)", f406, 2, 128},
  {"128:_mm_max_pd(x, _mm_max_pd(x, y))", f407, 2, 128},
  {"128:_mm_max_pd(_mm_max_pd(x, y), x)", f408, 2, 128},
  {"128:_mm_max_pd(y, _mm_max_pd(x, y))", f409, 2, 128},
  {"128:_mm_max_pd(_mm_and_pd(x, y), y)", f410, 2, 128},
  {"128:_mm_max_pd(x, _mm_and_pd(x, y))", f411, 2, 128},
  {"128:_mm_max_pd(_mm_and_pd(x, y), x)", f412, 2, 128},
  {"128:_mm_max_pd(y, _mm_and_pd(x, y))", f413, 2, 128},
  {"128:_mm_max_pd(_mm_or_pd(x, y), y)", f414, 2, 128},
  {"128:_mm_max_pd(x, _mm_or_pd(x, y))", f415, 2, 128},
  {"128:_mm_max_pd(_mm_or_pd(x, y), x)", f416, 2, 128},
  {"128:_mm_max_pd(y, _mm_or_pd(x, y))", f417, 2, 128},
  {"128:_mm_max_pd(_mm_xor_pd(x, y), y)", f418, 2, 128},
  {"128:_mm_max_pd(x, _mm_xor_pd(x, y))", f419, 2, 128},
  {"128:_mm_max_pd(_mm_xor_pd(x, y), x)", f420, 2, 128},
  {"128:_mm_max_pd(y, _mm_xor_pd(x, y))", f421, 2, 128},
  {"128:_mm_max_pd(_mm_andnot_pd(x, y), y)", f422, 2, 128},
  {"128:_mm_max_pd(x, _mm_andnot_pd(x, y))", f423, 2, 128},
  {"128:_mm_max_pd(_mm_andnot_pd(x, y), x)", f424, 2, 128},
  {"128:_mm_max_pd(y, _mm_andnot_pd(x, y))", f425, 2, 128},
  {"128:_mm_max_pd(_mm_cmp_pd(x, y, _CMP_EQ_OQ), y)", f426, 2, 128},
  {"128:_mm_max_pd(x, _mm_cmp_pd(x, y, _CMP_EQ_OQ))", f427, 2, 128},
  {"128:_mm_max_pd(_mm_cmp_pd(x, y, _CMP_EQ_OQ), x)", f428, 2, 128},
  {"128:_mm_max_pd(y, _mm_cmp_pd(x, y, _CMP_EQ_OQ))", f429, 2, 128},
  {"128:_mm_max_pd(_mm_cmp_pd(x, y, _CMP_LT_OS), y)", f430, 2, 128},
  {"128:_mm_max_pd(x, _mm_cmp_pd(x, y, _CMP_LT_OS))", f431, 2, 128},
  {"128:_mm_max_pd(_mm_cmp_pd(x, y, _CMP_LT_OS), x)", f432, 2, 128},
  {"128:_mm_max_pd(y, _mm_cmp_pd(x, y, _CMP_LT_OS))", f433, 2, 128},
  {"128:_mm_max_pd(_mm_cmp_pd(x, y, _CMP_LE_OS), y)", f434, 2, 128},
  {"128:_mm_max_pd(x, _mm_cmp_pd(x, y, _CMP_LE_OS))", f435, 2, 128},
  {"128:_mm_max_pd(_mm_cmp_pd(x, y, _CMP_LE_OS), x)", f436, 2, 128},
  {"128:_mm_max_pd(y, _mm_cmp_pd(x, y, _CMP_LE_OS))", f437, 2, 128},
  {"128:_mm_max_pd(_mm_cmp_pd(x, y, _CMP_NEQ_UQ), y)", f438, 2, 128},
  {"128:_mm_max_pd(x, _mm_cmp_pd(x, y, _CMP_NEQ_UQ))", f439, 2, 128},
  {"128:_mm_max_pd(_mm_cmp_pd(x, y, _CMP_NEQ_UQ), x)", f440, 2, 128},
  {"128:_mm_max_pd(y, _mm_cmp_pd(x, y, _CMP_NEQ_UQ))", f441, 2, 128},
  {"128:_mm_max_pd(_mm_cmp_pd(x, y, _CMP_UNORD_Q), y)", f442, 2, 128},
  {"128:_mm_max_pd(x, _mm_cmp_pd(x, y, _CMP_UNORD_Q))", f443, 2, 128},
  {"128:_mm_max_pd(_mm_cmp_pd(x, y, _CMP_UNORD_Q), x)", f444, 2, 128},
  {"128:_mm_max_pd(y, _mm_cmp_pd(x, y, _CMP_UNORD_Q))", f445, 2, 128},
  {"128:_mm_max_pd(_mm_cmp_pd(x, y, _CMP_NLT_US), y)", f446, 2, 128},
  {"128:_mm_max_pd(x, _mm_cmp_pd(x, y, _CMP_NLT_US))", f447, 2, 128},
  {"128:_mm_max_pd(_mm_cmp_pd(x, y, _CMP_NLT_US), x)", f448, 2, 128},
  {"128:_mm_max_pd(y, _mm_cmp_pd(x, y, _CMP_NLT_US))", f449, 2, 128},
  {"128:_mm_max_pd(_mm_cmp_pd(x, y, _CMP_GT_OS), y)", f450, 2, 128},
  {"128:_mm_max_pd(x, _mm_cmp_pd(x, y, _CMP_GT_OS))", f451, 2, 128},
  {"128:_mm_max_pd(_mm_cmp_pd(x, y, _CMP_GT_OS), x)", f452, 2, 128},
  {"128:_mm_max_pd(y, _mm_cmp_pd(x, y, _CMP_GT_OS))", f453, 2, 128},
  {"128:_mm_max_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_LT_OS)), y)", f454, 2, 128},
  {"128:_mm_max_pd(x, _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_LT_OS)))", f455, 2, 128},
  {"128:_mm_max_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_LT_OS)), x)", f456, 2, 128},
  {"128:_mm_max_pd(y, _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_LT_OS)))", f457, 2, 128},
  {"128:_mm_max_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_LT_OS)), y)", f458, 2, 128},
  {"128:_mm_max_pd(x, _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_LT_OS)))", f459, 2, 128},
  {"128:_mm_max_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_LT_OS)), x)", f460, 2, 128},
  {"128:_mm_max_pd(y, _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_LT_OS)))", f461, 2, 128},
  {"128:_mm_max_pd(_mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_LT_OS), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_LT_OS), y)), y)", f462, 2, 128},
  {"128:_mm_max_pd(x, _mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_LT_OS), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_LT_OS), y)))", f463, 2, 128},
  {"128:_mm_max_pd(_mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_LT_OS), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_LT_OS), y)), x)", f464, 2, 128},
  {"128:_mm_max_pd(y, _mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_LT_OS), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_LT_OS), y)))", f465, 2, 128},
  {"128:_mm_max_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_LE_OS)), y)", f466, 2, 128},
  {"128:_mm_max_pd(x, _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_LE_OS)))", f467, 2, 128},
  {"128:_mm_max_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_LE_OS)), x)", f468, 2, 128},
  {"128:_mm_max_pd(y, _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_LE_OS)))", f469, 2, 128},
  {"128:_mm_max_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_LE_OS)), y)", f470, 2, 128},
  {"128:_mm_max_pd(x, _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_LE_OS)))", f471, 2, 128},
  {"128:_mm_max_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_LE_OS)), x)", f472, 2, 128},
  {"128:_mm_max_pd(y, _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_LE_OS)))", f473, 2, 128},
  {"128:_mm_max_pd(_mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_LE_OS), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_LE_OS), y)), y)", f474, 2, 128},
  {"128:_mm_max_pd(x, _mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_LE_OS), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_LE_OS), y)))", f475, 2, 128},
  {"128:_mm_max_pd(_mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_LE_OS), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_LE_OS), y)), x)", f476, 2, 128},
  {"128:_mm_max_pd(y, _mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_LE_OS), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_LE_OS), y)))", f477, 2, 128},
  {"128:_mm_max_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_GT_OS)), y)", f478, 2, 128},
  {"128:_mm_max_pd(x, _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_GT_OS)))", f479, 2, 128},
  {"128:_mm_max_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_GT_OS)), x)", f480, 2, 128},
  {"128:_mm_max_pd(y, _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_GT_OS)))", f481, 2, 128},
  {"128:_mm_max_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_GT_OS)), y)", f482, 2, 128},
  {"128:_mm_max_pd(x, _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_GT_OS)))", f483, 2, 128},
  {"128:_mm_max_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_GT_OS)), x)", f484, 2, 128},
  {"128:_mm_max_pd(y, _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_GT_OS)))", f485, 2, 128},
  {"128:_mm_max_pd(_mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_GT_OS), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_GT_OS), y)), y)", f486, 2, 128},
  {"128:_mm_max_pd(x, _mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_GT_OS), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_GT_OS), y)))", f487, 2, 128},
  {"128:_mm_max_pd(_mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_GT_OS), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_GT_OS), y)), x)", f488, 2, 128},
  {"128:_mm_max_pd(y, _mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_GT_OS), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_GT_OS), y)))", f489, 2, 128},
  {"128:_mm_max_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_NLT_US)), y)", f490, 2, 128},
  {"128:_mm_max_pd(x, _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_NLT_US)))", f491, 2, 128},
  {"128:_mm_max_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_NLT_US)), x)", f492, 2, 128},
  {"128:_mm_max_pd(y, _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_NLT_US)))", f493, 2, 128},
  {"128:_mm_max_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_NLT_US)), y)", f494, 2, 128},
  {"128:_mm_max_pd(x, _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_NLT_US)))", f495, 2, 128},
  {"128:_mm_max_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_NLT_US)), x)", f496, 2, 128},
  {"128:_mm_max_pd(y, _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_NLT_US)))", f497, 2, 128},
  {"128:_mm_max_pd(_mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_NLT_US), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_NLT_US), y)), y)", f498, 2, 128},
  {"128:_mm_max_pd(x, _mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_NLT_US), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_NLT_US), y)))", f499, 2, 128},
  {"128:_mm_max_pd(_mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_NLT_US), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_NLT_US), y)), x)", f500, 2, 128},
  {"128:_mm_max_pd(y, _mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_NLT_US), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_NLT_US), y)))", f501, 2, 128},
  {"128:_mm_max_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_EQ_OQ)), y)", f502, 2, 128},
  {"128:_mm_max_pd(x, _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_EQ_OQ)))", f503, 2, 128},
  {"128:_mm_max_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_EQ_OQ)), x)", f504, 2, 128},
  {"128:_mm_max_pd(y, _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_EQ_OQ)))", f505, 2, 128},
  {"128:_mm_max_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_EQ_OQ)), y)", f506, 2, 128},
  {"128:_mm_max_pd(x, _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_EQ_OQ)))", f507, 2, 128},
  {"128:_mm_max_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_EQ_OQ)), x)", f508, 2, 128},
  {"128:_mm_max_pd(y, _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_EQ_OQ)))", f509, 2, 128},
  {"128:_mm_max_pd(_mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_EQ_OQ), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_EQ_OQ), y)), y)", f510, 2, 128},
  {"128:_mm_max_pd(x, _mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_EQ_OQ), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_EQ_OQ), y)))", f511, 2, 128},
  {"128:_mm_max_pd(_mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_EQ_OQ), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_EQ_OQ), y)), x)", f512, 2, 128},
  {"128:_mm_max_pd(y, _mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_EQ_OQ), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_EQ_OQ), y)))", f513, 2, 128},
  {"128:_mm_max_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_UNORD_Q)), y)", f514, 2, 128},
  {"128:_mm_max_pd(x, _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_UNORD_Q)))", f515, 2, 128},
  {"128:_mm_max_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_UNORD_Q)), x)", f516, 2, 128},
  {"128:_mm_max_pd(y, _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_UNORD_Q)))", f517, 2, 128},
  {"128:_mm_max_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_UNORD_Q)), y)", f518, 2, 128},
  {"128:_mm_max_pd(x, _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_UNORD_Q)))", f519, 2, 128},
  {"128:_mm_max_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_UNORD_Q)), x)", f520, 2, 128},
  {"128:_mm_max_pd(y, _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_UNORD_Q)))", f521, 2, 128},
  {"128:_mm_max_pd(_mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_UNORD_Q), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_UNORD_Q), y)), y)", f522, 2, 128},
  {"128:_mm_max_pd(x, _mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_UNORD_Q), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_UNORD_Q), y)))", f523, 2, 128},
  {"128:_mm_max_pd(_mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_UNORD_Q), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_UNORD_Q), y)), x)", f524, 2, 128},
  {"128:_mm_max_pd(y, _mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_UNORD_Q), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_UNORD_Q), y)))", f525, 2, 128},
  {"128:_mm_max_pd(_mm_unpacklo_pd(x, y), y)", f526, 2, 128},
  {"128:_mm_max_pd(x, _mm_unpacklo_pd(x, y))", f527, 2, 128},
  {"128:_mm_max_pd(_mm_unpacklo_pd(x, y), x)", f528, 2, 128},
  {"128:_mm_max_pd(y, _mm_unpacklo_pd(x, y))", f529, 2, 128},
  {"128:_mm_max_pd(_mm_unpackhi_pd(x, y), y)", f530, 2, 128},
  {"128:_mm_max_pd(x, _mm_unpackhi_pd(x, y))", f531, 2, 128},
  {"128:_mm_max_pd(_mm_unpackhi_pd(x, y), x)", f532, 2, 128},
  {"128:_mm_max_pd(y, _mm_unpackhi_pd(x, y))", f533, 2, 128},
  {"128:_mm_max_pd(_mm_hadd_pd(x, y), y)", f534, 2, 128},
  {"128:_mm_max_pd(x, _mm_hadd_pd(x, y))", f535, 2, 128},
  {"128:_mm_max_pd(_mm_hadd_pd(x, y), x)", f536, 2, 128},
  {"128:_mm_max_pd(y, _mm_hadd_pd(x, y))", f537, 2, 128},
  {"128:_mm_max_pd(_mm_hsub_pd(x, y), y)", f538, 2, 128},
  {"128:_mm_max_pd(x, _mm_hsub_pd(x, y))", f539, 2, 128},
  {"128:_mm_max_pd(_mm_hsub_pd(x, y), x)", f540, 2, 128},
  {"128:_mm_max_pd(y, _mm_hsub_pd(x, y))", f541, 2, 128},
  {"128:_mm_and_pd(_mm_add_pd(x, y), y)", f542, 2, 128},
  {"128:_mm_and_pd(x, _mm_add_pd(x, y))", f543, 2, 128},
  {"128:_mm_and_pd(_mm_add_pd(x, y), x)", f544, 2, 128},
  {"128:_mm_and_pd(y, _mm_add_pd(x, y))", f545, 2, 128},
  {"128:_mm_and_pd(_mm_sub_pd(x, y), y)", f546, 2, 128},
  {"128:_mm_and_pd(x, _mm_sub_pd(x, y))", f547, 2, 128},
  {"128:_mm_and_pd(_mm_sub_pd(x, y), x)", f548, 2, 128},
  {"128:_mm_and_pd(y, _mm_sub_pd(x, y))", f549, 2, 128},
  {"128:_mm_and_pd(_mm_mul_pd(x, y), y)", f550, 2, 128},
  {"128:_mm_and_pd(x, _mm_mul_pd(x, y))", f551, 2, 128},
  {"128:_mm_and_pd(_mm_mul_pd(x, y), x)", f552, 2, 128},
  {"128:_mm_and_pd(y, _mm_mul_pd(x, y))", f553, 2, 128},
  {"128:_mm_and_pd(_mm_div_pd(x, y), y)", f554, 2, 128},
  {"128:_mm_and_pd(x, _mm_div_pd(x, y))", f555, 2, 128},
  {"128:_mm_and_pd(_mm_div_pd(x, y), x)", f556, 2, 128},
  {"128:_mm_and_pd(y, _mm_div_pd(x, y))", f557, 2, 128},
  {"128:_mm_and_pd(_mm_min_pd(x, y), y)", f558, 2, 128},
  {"128:_mm_and_pd(x, _mm_min_pd(x, y))", f559, 2, 128},
  {"128:_mm_and_pd(_mm_min_pd(x, y), x)", f560, 2, 128},
  {"128:_mm_and_pd(y, _mm_min_pd(x, y))", f561, 2, 128},
  {"128:_mm_and_pd(_mm_max_pd(x, y), y)", f562, 2, 128},
  {"128:_mm_and_pd(x, _mm_max_pd(x, y))", f563, 2, 128},
  {"128:_mm_and_pd(_mm_max_pd(x, y), x)", f564, 2, 128},
  {"128:_mm_and_pd(y, _mm_max_pd(x, y))", f565, 2, 128},
  {"128:_mm_and_pd(_mm_and_pd(x, y), y)", f566, 2, 128},
  {"128:_mm_and_pd(x, _mm_and_pd(x, y))", f567, 2, 128},
  {"128:_mm_and_pd(_mm_and_pd(x, y), x)", f568, 2, 128},
  {"128:_mm_and_pd(y, _mm_and_pd(x, y))", f569, 2, 128},
  {"128:_mm_and_pd(_mm_or_pd(x, y), y)", f570, 2, 128},
  {"128:_mm_and_pd(x, _mm_or_pd(x, y))", f571, 2, 128},
  {"128:_mm_and_pd(_mm_or_pd(x, y), x)", f572, 2, 128},
  {"128:_mm_and_pd(y, _mm_or_pd(x, y))", f573, 2, 128},
  {"128:_mm_and_pd(_mm_xor_pd(x, y), y)", f574, 2, 128},
  {"128:_mm_and_pd(x, _mm_xor_pd(x, y))", f575, 2, 128},
  {"128:_mm_and_pd(_mm_xor_pd(x, y), x)", f576, 2, 128},
  {"128:_mm_and_pd(y, _mm_xor_pd(x, y))", f577, 2, 128},
  {"128:_mm_and_pd(_mm_andnot_pd(x, y), y)", f578, 2, 128},
  {"128:_mm_and_pd(x, _mm_andnot_pd(x, y))", f579, 2, 128},
  {"128:_mm_and_pd(_mm_andnot_pd(x, y), x)", f580, 2, 128},
  {"128:_mm_and_pd(y, _mm_andnot_pd(x, y))", f581, 2, 128},
  {"128:_mm_and_pd(_mm_cmp_pd(x, y, _CMP_EQ_OQ), y)", f582, 2, 128},
  {"128:_mm_and_pd(x, _mm_cmp_pd(x, y, _CMP_EQ_OQ))", f583, 2, 128},
  {"128:_mm_and_pd(_mm_cmp_pd(x, y, _CMP_EQ_OQ), x)", f584, 2, 128},
  {"128:_mm_and_pd(y, _mm_cmp_pd(x, y, _CMP_EQ_OQ))", f585, 2, 128},
  {"128:_mm_and_pd(_mm_cmp_pd(x, y, _CMP_LT_OS), y)", f586, 2, 128},
  {"128:_mm_and_pd(x, _mm_cmp_pd(x, y, _CMP_LT_OS))", f587, 2, 128},
  {"128:_mm_and_pd(_mm_cmp_pd(x, y, _CMP_LT_OS), x)", f588, 2, 128},
  {"128:_mm_and_pd(y, _mm_cmp_pd(x, y, _CMP_LT_OS))", f589, 2, 128},
  {"128:_mm_and_pd(_mm_cmp_pd(x, y, _CMP_LE_OS), y)", f590, 2, 128},
  {"128:_mm_and_pd(x, _mm_cmp_pd(x, y, _CMP_LE_OS))", f591, 2, 128},
  {"128:_mm_and_pd(_mm_cmp_pd(x, y, _CMP_LE_OS), x)", f592, 2, 128},
  {"128:_mm_and_pd(y, _mm_cmp_pd(x, y, _CMP_LE_OS))", f593, 2, 128},
  {"128:_mm_and_pd(_mm_cmp_pd(x, y, _CMP_NEQ_UQ), y)", f594, 2, 128},
  {"128:_mm_and_pd(x, _mm_cmp_pd(x, y, _CMP_NEQ_UQ))", f595, 2, 128},
  {"128:_mm_and_pd(_mm_cmp_pd(x, y, _CMP_NEQ_UQ), x)", f596, 2, 128},
  {"128:_mm_and_pd(y, _mm_cmp_pd(x, y, _CMP_NEQ_UQ))", f597, 2, 128},
  {"128:_mm_and_pd(_mm_cmp_pd(x, y, _CMP_UNORD_Q), y)", f598, 2, 128},
  {"128:_mm_and_pd(x, _mm_cmp_pd(x, y, _CMP_UNORD_Q))", f599, 2, 128},
  {"128:_mm_and_pd(_mm_cmp_pd(x, y, _CMP_UNORD_Q), x)", f600, 2, 128},
  {"128:_mm_and_pd(y, _mm_cmp_pd(x, y, _CMP_UNORD_Q))", f601, 2, 128},
  {"128:_mm_and_pd(_mm_cmp_pd(x, y, _CMP_NLT_US), y)", f602, 2, 128},
  {"128:_mm_and_pd(x, _mm_cmp_pd(x, y, _CMP_NLT_US))", f603, 2, 128},
  {"128:_mm_and_pd(_mm_cmp_pd(x, y, _CMP_NLT_US), x)", f604, 2, 128},
  {"128:_mm_and_pd(y, _mm_cmp_pd(x, y, _CMP_NLT_US))", f605, 2, 128},
  {"128:_mm_and_pd(_mm_cmp_pd(x, y, _CMP_GT_OS), y)", f606, 2, 128},
  {"128:_mm_and_pd(x, _mm_cmp_pd(x, y, _CMP_GT_OS))", f607, 2, 128},
  {"128:_mm_and_pd(_mm_cmp_pd(x, y, _CMP_GT_OS), x)", f608, 2, 128},
  {"128:_mm_and_pd(y, _mm_cmp_pd(x, y, _CMP_GT_OS))", f609, 2, 128},
  {"128:_mm_and_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_LT_OS)), y)", f610, 2, 128},
  {"128:_mm_and_pd(x, _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_LT_OS)))", f611, 2, 128},
  {"128:_mm_and_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_LT_OS)), x)", f612, 2, 128},
  {"128:_mm_and_pd(y, _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_LT_OS)))", f613, 2, 128},
  {"128:_mm_and_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_LT_OS)), y)", f614, 2, 128},
  {"128:_mm_and_pd(x, _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_LT_OS)))", f615, 2, 128},
  {"128:_mm_and_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_LT_OS)), x)", f616, 2, 128},
  {"128:_mm_and_pd(y, _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_LT_OS)))", f617, 2, 128},
  {"128:_mm_and_pd(_mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_LT_OS), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_LT_OS), y)), y)", f618, 2, 128},
  {"128:_mm_and_pd(x, _mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_LT_OS), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_LT_OS), y)))", f619, 2, 128},
  {"128:_mm_and_pd(_mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_LT_OS), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_LT_OS), y)), x)", f620, 2, 128},
  {"128:_mm_and_pd(y, _mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_LT_OS), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_LT_OS), y)))", f621, 2, 128},
  {"128:_mm_and_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_LE_OS)), y)", f622, 2, 128},
  {"128:_mm_and_pd(x, _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_LE_OS)))", f623, 2, 128},
  {"128:_mm_and_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_LE_OS)), x)", f624, 2, 128},
  {"128:_mm_and_pd(y, _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_LE_OS)))", f625, 2, 128},
  {"128:_mm_and_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_LE_OS)), y)", f626, 2, 128},
  {"128:_mm_and_pd(x, _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_LE_OS)))", f627, 2, 128},
  {"128:_mm_and_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_LE_OS)), x)", f628, 2, 128},
  {"128:_mm_and_pd(y, _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_LE_OS)))", f629, 2, 128},
  {"128:_mm_and_pd(_mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_LE_OS), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_LE_OS), y)), y)", f630, 2, 128},
  {"128:_mm_and_pd(x, _mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_LE_OS), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_LE_OS), y)))", f631, 2, 128},
  {"128:_mm_and_pd(_mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_LE_OS), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_LE_OS), y)), x)", f632, 2, 128},
  {"128:_mm_and_pd(y, _mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_LE_OS), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_LE_OS), y)))", f633, 2, 128},
  {"128:_mm_and_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_GT_OS)), y)", f634, 2, 128},
  {"128:_mm_and_pd(x, _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_GT_OS)))", f635, 2, 128},
  {"128:_mm_and_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_GT_OS)), x)", f636, 2, 128},
  {"128:_mm_and_pd(y, _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_GT_OS)))", f637, 2, 128},
  {"128:_mm_and_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_GT_OS)), y)", f638, 2, 128},
  {"128:_mm_and_pd(x, _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_GT_OS)))", f639, 2, 128},
  {"128:_mm_and_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_GT_OS)), x)", f640, 2, 128},
  {"128:_mm_and_pd(y, _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_GT_OS)))", f641, 2, 128},
  {"128:_mm_and_pd(_mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_GT_OS), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_GT_OS), y)), y)", f642, 2, 128},
  {"128:_mm_and_pd(x, _mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_GT_OS), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_GT_OS), y)))", f643, 2, 128},
  {"128:_mm_and_pd(_mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_GT_OS), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_GT_OS), y)), x)", f644, 2, 128},
  {"128:_mm_and_pd(y, _mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_GT_OS), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_GT_OS), y)))", f645, 2, 128},
  {"128:_mm_and_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_NLT_US)), y)", f646, 2, 128},
  {"128:_mm_and_pd(x, _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_NLT_US)))", f647, 2, 128},
  {"128:_mm_and_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_NLT_US)), x)", f648, 2, 128},
  {"128:_mm_and_pd(y, _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_NLT_US)))", f649, 2, 128},
  {"128:_mm_and_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_NLT_US)), y)", f650, 2, 128},
  {"128:_mm_and_pd(x, _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_NLT_US)))", f651, 2, 128},
  {"128:_mm_and_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_NLT_US)), x)", f652, 2, 128},
  {"128:_mm_and_pd(y, _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_NLT_US)))", f653, 2, 128},
  {"128:_mm_and_pd(_mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_NLT_US), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_NLT_US), y)), y)", f654, 2, 128},
  {"128:_mm_and_pd(x, _mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_NLT_US), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_NLT_US), y)))", f655, 2, 128},
  {"128:_mm_and_pd(_mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_NLT_US), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_NLT_US), y)), x)", f656, 2, 128},
  {"128:_mm_and_pd(y, _mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_NLT_US), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_NLT_US), y)))", f657, 2, 128},
  {"128:_mm_and_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_EQ_OQ)), y)", f658, 2, 128},
  {"128:_mm_and_pd(x, _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_EQ_OQ)))", f659, 2, 128},
  {"128:_mm_and_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_EQ_OQ)), x)", f660, 2, 128},
  {"128:_mm_and_pd(y, _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_EQ_OQ)))", f661, 2, 128},
  {"128:_mm_and_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_EQ_OQ)), y)", f662, 2, 128},
  {"128:_mm_and_pd(x, _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_EQ_OQ)))", f663, 2, 128},
  {"128:_mm_and_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_EQ_OQ)), x)", f664, 2, 128},
  {"128:_mm_and_pd(y, _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_EQ_OQ)))", f665, 2, 128},
  {"128:_mm_and_pd(_mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_EQ_OQ), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_EQ_OQ), y)), y)", f666, 2, 128},
  {"128:_mm_and_pd(x, _mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_EQ_OQ), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_EQ_OQ), y)))", f667, 2, 128},
  {"128:_mm_and_pd(_mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_EQ_OQ), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_EQ_OQ), y)), x)", f668, 2, 128},
  {"128:_mm_and_pd(y, _mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_EQ_OQ), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_EQ_OQ), y)))", f669, 2, 128},
  {"128:_mm_and_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_UNORD_Q)), y)", f670, 2, 128},
  {"128:_mm_and_pd(x, _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_UNORD_Q)))", f671, 2, 128},
  {"128:_mm_and_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_UNORD_Q)), x)", f672, 2, 128},
  {"128:_mm_and_pd(y, _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_UNORD_Q)))", f673, 2, 128},
  {"128:_mm_and_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_UNORD_Q)), y)", f674, 2, 128},
  {"128:_mm_and_pd(x, _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_UNORD_Q)))", f675, 2, 128},
  {"128:_mm_and_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_UNORD_Q)), x)", f676, 2, 128},
  {"128:_mm_and_pd(y, _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_UNORD_Q)))", f677, 2, 128},
  {"128:_mm_and_pd(_mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_UNORD_Q), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_UNORD_Q), y)), y)", f678, 2, 128},
  {"128:_mm_and_pd(x, _mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_UNORD_Q), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_UNORD_Q), y)))", f679, 2, 128},
  {"128:_mm_and_pd(_mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_UNORD_Q), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_UNORD_Q), y)), x)", f680, 2, 128},
  {"128:_mm_and_pd(y, _mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_UNORD_Q), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_UNORD_Q), y)))", f681, 2, 128},
  {"128:_mm_and_pd(_mm_unpacklo_pd(x, y), y)", f682, 2, 128},
  {"128:_mm_and_pd(x, _mm_unpacklo_pd(x, y))", f683, 2, 128},
  {"128:_mm_and_pd(_mm_unpacklo_pd(x, y), x)", f684, 2, 128},
  {"128:_mm_and_pd(y, _mm_unpacklo_pd(x, y))", f685, 2, 128},
  {"128:_mm_and_pd(_mm_unpackhi_pd(x, y), y)", f686, 2, 128},
  {"128:_mm_and_pd(x, _mm_unpackhi_pd(x, y))", f687, 2, 128},
  {"128:_mm_and_pd(_mm_unpackhi_pd(x, y), x)", f688, 2, 128},
  {"128:_mm_and_pd(y, _mm_unpackhi_pd(x, y))", f689, 2, 128},
  {"128:_mm_and_pd(_mm_hadd_pd(x, y), y)", f690, 2, 128},
  {"128:_mm_and_pd(x, _mm_hadd_pd(x, y))", f691, 2, 128},
  {"128:_mm_and_pd(_mm_hadd_pd(x, y), x)", f692, 2, 128},
  {"128:_mm_and_pd(y, _mm_hadd_pd(x, y))", f693, 2, 128},
  {"128:_mm_and_pd(_mm_hsub_pd(x, y), y)", f694, 2, 128},
  {"128:_mm_and_pd(x, _mm_hsub_pd(x, y))", f695, 2, 128},
  {"128:_mm_and_pd(_mm_hsub_pd(x, y), x)", f696, 2, 128},
  {"128:_mm_and_pd(y, _mm_hsub_pd(x, y))", f697, 2, 128},
  {"128:_mm_or_pd(_mm_add_pd(x, y), y)", f698, 2, 128},
  {"128:_mm_or_pd(x, _mm_add_pd(x, y))", f699, 2, 128},
  {"128:_mm_or_pd(_mm_add_pd(x, y), x)", f700, 2, 128},
  {"128:_mm_or_pd(y, _mm_add_pd(x, y))", f701, 2, 128},
  {"128:_mm_or_pd(_mm_sub_pd(x, y), y)", f702, 2, 128},
  {"128:_mm_or_pd(x, _mm_sub_pd(x, y))", f703, 2, 128},
  {"128:_mm_or_pd(_mm_sub_pd(x, y), x)", f704, 2, 128},
  {"128:_mm_or_pd(y, _mm_sub_pd(x, y))", f705, 2, 128},
  {"128:_mm_or_pd(_mm_mul_pd(x, y), y)", f706, 2, 128},
  {"128:_mm_or_pd(x, _mm_mul_pd(x, y))", f707, 2, 128},
  {"128:_mm_or_pd(_mm_mul_pd(x, y), x)", f708, 2, 128},
  {"128:_mm_or_pd(y, _mm_mul_pd(x, y))", f709, 2, 128},
  {"128:_mm_or_pd(_mm_div_pd(x, y), y)", f710, 2, 128},
  {"128:_mm_or_pd(x, _mm_div_pd(x, y))", f711, 2, 128},
  {"128:_mm_or_pd(_mm_div_pd(x, y), x)", f712, 2, 128},
  {"128:_mm_or_pd(y, _mm_div_pd(x, y))", f713, 2, 128},
  {"128:_mm_or_pd(_mm_min_pd(x, y), y)", f714, 2, 128},
  {"128:_mm_or_pd(x, _mm_min_pd(x, y))", f715, 2, 128},
  {"128:_mm_or_pd(_mm_min_pd(x, y), x)", f716, 2, 128},
  {"128:_mm_or_pd(y, _mm_min_pd(x, y))", f717, 2, 128},
  {"128:_mm_or_pd(_mm_max_pd(x, y), y)", f718, 2, 128},
  {"128:_mm_or_pd(x, _mm_max_pd(x, y))", f719, 2, 128},
  {"128:_mm_or_pd(_mm_max_pd(x, y), x)", f720, 2, 128},
  {"128:_mm_or_pd(y, _mm_max_pd(x, y))", f721, 2, 128},
  {"128:_mm_or_pd(_mm_and_pd(x, y), y)", f722, 2, 128},
  {"128:_mm_or_pd(x, _mm_and_pd(x, y))", f723, 2, 128},
  {"128:_mm_or_pd(_mm_and_pd(x, y), x)", f724, 2, 128},
  {"128:_mm_or_pd(y, _mm_and_pd(x, y))", f725, 2, 128},
  {"128:_mm_or_pd(_mm_or_pd(x, y), y)", f726, 2, 128},
  {"128:_mm_or_pd(x, _mm_or_pd(x, y))", f727, 2, 128},
  {"128:_mm_or_pd(_mm_or_pd(x, y), x)", f728, 2, 128},
  {"128:_mm_or_pd(y, _mm_or_pd(x, y))", f729, 2, 128},
  {"128:_mm_or_pd(_mm_xor_pd(x, y), y)", f730, 2, 128},
  {"128:_mm_or_pd(x, _mm_xor_pd(x, y))", f731, 2, 128},
  {"128:_mm_or_pd(_mm_xor_pd(x, y), x)", f732, 2, 128},
  {"128:_mm_or_pd(y, _mm_xor_pd(x, y))", f733, 2, 128},
  {"128:_mm_or_pd(_mm_andnot_pd(x, y), y)", f734, 2, 128},
  {"128:_mm_or_pd(x, _mm_andnot_pd(x, y))", f735, 2, 128},
  {"128:_mm_or_pd(_mm_andnot_pd(x, y), x)", f736, 2, 128},
  {"128:_mm_or_pd(y, _mm_andnot_pd(x, y))", f737, 2, 128},
  {"128:_mm_or_pd(_mm_cmp_pd(x, y, _CMP_EQ_OQ), y)", f738, 2, 128},
  {"128:_mm_or_pd(x, _mm_cmp_pd(x, y, _CMP_EQ_OQ))", f739, 2, 128},
  {"128:_mm_or_pd(_mm_cmp_pd(x, y, _CMP_EQ_OQ), x)", f740, 2, 128},
  {"128:_mm_or_pd(y, _mm_cmp_pd(x, y, _CMP_EQ_OQ))", f741, 2, 128},
  {"128:_mm_or_pd(_mm_cmp_pd(x, y, _CMP_LT_OS), y)", f742, 2, 128},
  {"128:_mm_or_pd(x, _mm_cmp_pd(x, y, _CMP_LT_OS))", f743, 2, 128},
  {"128:_mm_or_pd(_mm_cmp_pd(x, y, _CMP_LT_OS), x)", f744, 2, 128},
  {"128:_mm_or_pd(y, _mm_cmp_pd(x, y, _CMP_LT_OS))", f745, 2, 128},
  {"128:_mm_or_pd(_mm_cmp_pd(x, y, _CMP_LE_OS), y)", f746, 2, 128},
  {"128:_mm_or_pd(x, _mm_cmp_pd(x, y, _CMP_LE_OS))", f747, 2, 128},
  {"128:_mm_or_pd(_mm_cmp_pd(x, y, _CMP_LE_OS), x)", f748, 2, 128},
  {"128:_mm_or_pd(y, _mm_cmp_pd(x, y, _CMP_LE_OS))", f749, 2, 128},
  {"128:_mm_or_pd(_mm_cmp_pd(x, y, _CMP_NEQ_UQ), y)", f750, 2, 128},
  {"128:_mm_or_pd(x, _mm_cmp_pd(x, y, _CMP_NEQ_UQ))", f751, 2, 128},
  {"128:_mm_or_pd(_mm_cmp_pd(x, y, _CMP_NEQ_UQ), x)", f752, 2, 128},
  {"128:_mm_or_pd(y, _mm_cmp_pd(x, y, _CMP_NEQ_UQ))", f753, 2, 128},
  {"128:_mm_or_pd(_mm_cmp_pd(x, y, _CMP_UNORD_Q), y)", f754, 2, 128},
  {"128:_mm_or_pd(x, _mm_cmp_pd(x, y, _CMP_UNORD_Q))", f755, 2, 128},
  {"128:_mm_or_pd(_mm_cmp_pd(x, y, _CMP_UNORD_Q), x)", f756, 2, 128},
  {"128:_mm_or_pd(y, _mm_cmp_pd(x, y, _CMP_UNORD_Q))", f757, 2, 128},
  {"128:_mm_or_pd(_mm_cmp_pd(x, y, _CMP_NLT_US), y)", f758, 2, 128},
  {"128:_mm_or_pd(x, _mm_cmp_pd(x, y, _CMP_NLT_US))", f759, 2, 128},
  {"128:_mm_or_pd(_mm_cmp_pd(x, y, _CMP_NLT_US), x)", f760, 2, 128},
  {"128:_mm_or_pd(y, _mm_cmp_pd(x, y, _CMP_NLT_US))", f761, 2, 128},
  {"128:_mm_or_pd(_mm_cmp_pd(x, y, _CMP_GT_OS), y)", f762, 2, 128},
  {"128:_mm_or_pd(x, _mm_cmp_pd(x, y, _CMP_GT_OS))", f763, 2, 128},
  {"128:_mm_or_pd(_mm_cmp_pd(x, y, _CMP_GT_OS), x)", f764, 2, 128},
  {"128:_mm_or_pd(y, _mm_cmp_pd(x, y, _CMP_GT_OS))", f765, 2, 128},
  {"128:_mm_or_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_LT_OS)), y)", f766, 2, 128},
  {"128:_mm_or_pd(x, _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_LT_OS)))", f767, 2, 128},
  {"128:_mm_or_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_LT_OS)), x)", f768, 2, 128},
  {"128:_mm_or_pd(y, _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_LT_OS)))", f769, 2, 128},
  {"128:_mm_or_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_LT_OS)), y)", f770, 2, 128},
  {"128:_mm_or_pd(x, _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_LT_OS)))", f771, 2, 128},
  {"128:_mm_or_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_LT_OS)), x)", f772, 2, 128},
  {"128:_mm_or_pd(y, _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_LT_OS)))", f773, 2, 128},
  {"128:_mm_or_pd(_mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_LT_OS), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_LT_OS), y)), y)", f774, 2, 128},
  {"128:_mm_or_pd(x, _mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_LT_OS), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_LT_OS), y)))", f775, 2, 128},
  {"128:_mm_or_pd(_mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_LT_OS), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_LT_OS), y)), x)", f776, 2, 128},
  {"128:_mm_or_pd(y, _mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_LT_OS), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_LT_OS), y)))", f777, 2, 128},
  {"128:_mm_or_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_LE_OS)), y)", f778, 2, 128},
  {"128:_mm_or_pd(x, _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_LE_OS)))", f779, 2, 128},
  {"128:_mm_or_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_LE_OS)), x)", f780, 2, 128},
  {"128:_mm_or_pd(y, _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_LE_OS)))", f781, 2, 128},
  {"128:_mm_or_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_LE_OS)), y)", f782, 2, 128},
  {"128:_mm_or_pd(x, _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_LE_OS)))", f783, 2, 128},
  {"128:_mm_or_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_LE_OS)), x)", f784, 2, 128},
  {"128:_mm_or_pd(y, _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_LE_OS)))", f785, 2, 128},
  {"128:_mm_or_pd(_mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_LE_OS), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_LE_OS), y)), y)", f786, 2, 128},
  {"128:_mm_or_pd(x, _mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_LE_OS), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_LE_OS), y)))", f787, 2, 128},
  {"128:_mm_or_pd(_mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_LE_OS), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_LE_OS), y)), x)", f788, 2, 128},
  {"128:_mm_or_pd(y, _mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_LE_OS), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_LE_OS), y)))", f789, 2, 128},
  {"128:_mm_or_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_GT_OS)), y)", f790, 2, 128},
  {"128:_mm_or_pd(x, _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_GT_OS)))", f791, 2, 128},
  {"128:_mm_or_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_GT_OS)), x)", f792, 2, 128},
  {"128:_mm_or_pd(y, _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_GT_OS)))", f793, 2, 128},
  {"128:_mm_or_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_GT_OS)), y)", f794, 2, 128},
  {"128:_mm_or_pd(x, _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_GT_OS)))", f795, 2, 128},
  {"128:_mm_or_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_GT_OS)), x)", f796, 2, 128},
  {"128:_mm_or_pd(y, _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_GT_OS)))", f797, 2, 128},
  {"128:_mm_or_pd(_mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_GT_OS), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_GT_OS), y)), y)", f798, 2, 128},
  {"128:_mm_or_pd(x, _mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_GT_OS), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_GT_OS), y)))", f799, 2, 128},
  {"128:_mm_or_pd(_mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_GT_OS), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_GT_OS), y)), x)", f800, 2, 128},
  {"128:_mm_or_pd(y, _mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_GT_OS), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_GT_OS), y)))", f801, 2, 128},
  {"128:_mm_or_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_NLT_US)), y)", f802, 2, 128},
  {"128:_mm_or_pd(x, _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_NLT_US)))", f803, 2, 128},
  {"128:_mm_or_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_NLT_US)), x)", f804, 2, 128},
  {"128:_mm_or_pd(y, _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_NLT_US)))", f805, 2, 128},
  {"128:_mm_or_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_NLT_US)), y)", f806, 2, 128},
  {"128:_mm_or_pd(x, _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_NLT_US)))", f807, 2, 128},
  {"128:_mm_or_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_NLT_US)), x)", f808, 2, 128},
  {"128:_mm_or_pd(y, _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_NLT_US)))", f809, 2, 128},
  {"128:_mm_or_pd(_mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_NLT_US), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_NLT_US), y)), y)", f810, 2, 128},
  {"128:_mm_or_pd(x, _mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_NLT_US), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_NLT_US), y)))", f811, 2, 128},
  {"128:_mm_or_pd(_mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_NLT_US), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_NLT_US), y)), x)", f812, 2, 128},
  {"128:_mm_or_pd(y, _mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_NLT_US), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_NLT_US), y)))", f813, 2, 128},
  {"128:_mm_or_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_EQ_OQ)), y)", f814, 2, 128},
  {"128:_mm_or_pd(x, _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_EQ_OQ)))", f815, 2, 128},
  {"128:_mm_or_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_EQ_OQ)), x)", f816, 2, 128},
  {"128:_mm_or_pd(y, _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_EQ_OQ)))", f817, 2, 128},
  {"128:_mm_or_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_EQ_OQ)), y)", f818, 2, 128},
  {"128:_mm_or_pd(x, _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_EQ_OQ)))", f819, 2, 128},
  {"128:_mm_or_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_EQ_OQ)), x)", f820, 2, 128},
  {"128:_mm_or_pd(y, _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_EQ_OQ)))", f821, 2, 128},
  {"128:_mm_or_pd(_mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_EQ_OQ), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_EQ_OQ), y)), y)", f822, 2, 128},
  {"128:_mm_or_pd(x, _mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_EQ_OQ), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_EQ_OQ), y)))", f823, 2, 128},
  {"128:_mm_or_pd(_mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_EQ_OQ), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_EQ_OQ), y)), x)", f824, 2, 128},
  {"128:_mm_or_pd(y, _mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_EQ_OQ), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_EQ_OQ), y)))", f825, 2, 128},
  {"128:_mm_or_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_UNORD_Q)), y)", f826, 2, 128},
  {"128:_mm_or_pd(x, _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_UNORD_Q)))", f827, 2, 128},
  {"128:_mm_or_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_UNORD_Q)), x)", f828, 2, 128},
  {"128:_mm_or_pd(y, _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_UNORD_Q)))", f829, 2, 128},
  {"128:_mm_or_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_UNORD_Q)), y)", f830, 2, 128},
  {"128:_mm_or_pd(x, _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_UNORD_Q)))", f831, 2, 128},
  {"128:_mm_or_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_UNORD_Q)), x)", f832, 2, 128},
  {"128:_mm_or_pd(y, _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_UNORD_Q)))", f833, 2, 128},
  {"128:_mm_or_pd(_mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_UNORD_Q), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_UNORD_Q), y)), y)", f834, 2, 128},
  {"128:_mm_or_pd(x, _mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_UNORD_Q), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_UNORD_Q), y)))", f835, 2, 128},
  {"128:_mm_or_pd(_mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_UNORD_Q), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_UNORD_Q), y)), x)", f836, 2, 128},
  {"128:_mm_or_pd(y, _mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_UNORD_Q), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_UNORD_Q), y)))", f837, 2, 128},
  {"128:_mm_or_pd(_mm_unpacklo_pd(x, y), y)", f838, 2, 128},
  {"128:_mm_or_pd(x, _mm_unpacklo_pd(x, y))", f839, 2, 128},
  {"128:_mm_or_pd(_mm_unpacklo_pd(x, y), x)", f840, 2, 128},
  {"128:_mm_or_pd(y, _mm_unpacklo_pd(x, y))", f841, 2, 128},
  {"128:_mm_or_pd(_mm_unpackhi_pd(x, y), y)", f842, 2, 128},
  {"128:_mm_or_pd(x, _mm_unpackhi_pd(x, y))", f843, 2, 128},
  {"128:_mm_or_pd(_mm_unpackhi_pd(x, y), x)", f844, 2, 128},
  {"128:_mm_or_pd(y, _mm_unpackhi_pd(x, y))", f845, 2, 128},
  {"128:_mm_or_pd(_mm_hadd_pd(x, y), y)", f846, 2, 128},
  {"128:_mm_or_pd(x, _mm_hadd_pd(x, y))", f847, 2, 128},
  {"128:_mm_or_pd(_mm_hadd_pd(x, y), x)", f848, 2, 128},
  {"128:_mm_or_pd(y, _mm_hadd_pd(x, y))", f849, 2, 128},
  {"128:_mm_or_pd(_mm_hsub_pd(x, y), y)", f850, 2, 128},
  {"128:_mm_or_pd(x, _mm_hsub_pd(x, y))", f851, 2, 128},
  {"128:_mm_or_pd(_mm_hsub_pd(x, y), x)", f852, 2, 128},
  {"128:_mm_or_pd(y, _mm_hsub_pd(x, y))", f853, 2, 128},
  {"128:_mm_xor_pd(_mm_add_pd(x, y), y)", f854, 2, 128},
  {"128:_mm_xor_pd(x, _mm_add_pd(x, y))", f855, 2, 128},
  {"128:_mm_xor_pd(_mm_add_pd(x, y), x)", f856, 2, 128},
  {"128:_mm_xor_pd(y, _mm_add_pd(x, y))", f857, 2, 128},
  {"128:_mm_xor_pd(_mm_sub_pd(x, y), y)", f858, 2, 128},
  {"128:_mm_xor_pd(x, _mm_sub_pd(x, y))", f859, 2, 128},
  {"128:_mm_xor_pd(_mm_sub_pd(x, y), x)", f860, 2, 128},
  {"128:_mm_xor_pd(y, _mm_sub_pd(x, y))", f861, 2, 128},
  {"128:_mm_xor_pd(_mm_mul_pd(x, y), y)", f862, 2, 128},
  {"128:_mm_xor_pd(x, _mm_mul_pd(x, y))", f863, 2, 128},
  {"128:_mm_xor_pd(_mm_mul_pd(x, y), x)", f864, 2, 128},
  {"128:_mm_xor_pd(y, _mm_mul_pd(x, y))", f865, 2, 128},
  {"128:_mm_xor_pd(_mm_div_pd(x, y), y)", f866, 2, 128},
  {"128:_mm_xor_pd(x, _mm_div_pd(x, y))", f867, 2, 128},
  {"128:_mm_xor_pd(_mm_div_pd(x, y), x)", f868, 2, 128},
  {"128:_mm_xor_pd(y, _mm_div_pd(x, y))", f869, 2, 128},
  {"128:_mm_xor_pd(_mm_min_pd(x, y), y)", f870, 2, 128},
  {"128:_mm_xor_pd(x, _mm_min_pd(x, y))", f871, 2, 128},
  {"128:_mm_xor_pd(_mm_min_pd(x, y), x)", f872, 2, 128},
  {"128:_mm_xor_pd(y, _mm_min_pd(x, y))", f873, 2, 128},
  {"128:_mm_xor_pd(_mm_max_pd(x, y), y)", f874, 2, 128},
  {"128:_mm_xor_pd(x, _mm_max_pd(x, y))", f875, 2, 128},
  {"128:_mm_xor_pd(_mm_max_pd(x, y), x)", f876, 2, 128},
  {"128:_mm_xor_pd(y, _mm_max_pd(x, y))", f877, 2, 128},
  {"128:_mm_xor_pd(_mm_and_pd(x, y), y)", f878, 2, 128},
  {"128:_mm_xor_pd(x, _mm_and_pd(x, y))", f879, 2, 128},
  {"128:_mm_xor_pd(_mm_and_pd(x, y), x)", f880, 2, 128},
  {"128:_mm_xor_pd(y, _mm_and_pd(x, y))", f881, 2, 128},
  {"128:_mm_xor_pd(_mm_or_pd(x, y), y)", f882, 2, 128},
  {"128:_mm_xor_pd(x, _mm_or_pd(x, y))", f883, 2, 128},
  {"128:_mm_xor_pd(_mm_or_pd(x, y), x)", f884, 2, 128},
  {"128:_mm_xor_pd(y, _mm_or_pd(x, y))", f885, 2, 128},
  {"128:_mm_xor_pd(_mm_xor_pd(x, y), y)", f886, 2, 128},
  {"128:_mm_xor_pd(x, _mm_xor_pd(x, y))", f887, 2, 128},
  {"128:_mm_xor_pd(_mm_xor_pd(x, y), x)", f888, 2, 128},
  {"128:_mm_xor_pd(y, _mm_xor_pd(x, y))", f889, 2, 128},
  {"128:_mm_xor_pd(_mm_andnot_pd(x, y), y)", f890, 2, 128},
  {"128:_mm_xor_pd(x, _mm_andnot_pd(x, y))", f891, 2, 128},
  {"128:_mm_xor_pd(_mm_andnot_pd(x, y), x)", f892, 2, 128},
  {"128:_mm_xor_pd(y, _mm_andnot_pd(x, y))", f893, 2, 128},
  {"128:_mm_xor_pd(_mm_cmp_pd(x, y, _CMP_EQ_OQ), y)", f894, 2, 128},
  {"128:_mm_xor_pd(x, _mm_cmp_pd(x, y, _CMP_EQ_OQ))", f895, 2, 128},
  {"128:_mm_xor_pd(_mm_cmp_pd(x, y, _CMP_EQ_OQ), x)", f896, 2, 128},
  {"128:_mm_xor_pd(y, _mm_cmp_pd(x, y, _CMP_EQ_OQ))", f897, 2, 128},
  {"128:_mm_xor_pd(_mm_cmp_pd(x, y, _CMP_LT_OS), y)", f898, 2, 128},
  {"128:_mm_xor_pd(x, _mm_cmp_pd(x, y, _CMP_LT_OS))", f899, 2, 128},
  {"128:_mm_xor_pd(_mm_cmp_pd(x, y, _CMP_LT_OS), x)", f900, 2, 128},
  {"128:_mm_xor_pd(y, _mm_cmp_pd(x, y, _CMP_LT_OS))", f901, 2, 128},
  {"128:_mm_xor_pd(_mm_cmp_pd(x, y, _CMP_LE_OS), y)", f902, 2, 128},
  {"128:_mm_xor_pd(x, _mm_cmp_pd(x, y, _CMP_LE_OS))", f903, 2, 128},
  {"128:_mm_xor_pd(_mm_cmp_pd(x, y, _CMP_LE_OS), x)", f904, 2, 128},
  {"128:_mm_xor_pd(y, _mm_cmp_pd(x, y, _CMP_LE_OS))", f905, 2, 128},
  {"128:_mm_xor_pd(_mm_cmp_pd(x, y, _CMP_NEQ_UQ), y)", f906, 2, 128},
  {"128:_mm_xor_pd(x, _mm_cmp_pd(x, y, _CMP_NEQ_UQ))", f907, 2, 128},
  {"128:_mm_xor_pd(_mm_cmp_pd(x, y, _CMP_NEQ_UQ), x)", f908, 2, 128},
  {"128:_mm_xor_pd(y, _mm_cmp_pd(x, y, _CMP_NEQ_UQ))", f909, 2, 128},
  {"128:_mm_xor_pd(_mm_cmp_pd(x, y, _CMP_UNORD_Q), y)", f910, 2, 128},
  {"128:_mm_xor_pd(x, _mm_cmp_pd(x, y, _CMP_UNORD_Q))", f911, 2, 128},
  {"128:_mm_xor_pd(_mm_cmp_pd(x, y, _CMP_UNORD_Q), x)", f912, 2, 128},
  {"128:_mm_xor_pd(y, _mm_cmp_pd(x, y, _CMP_UNORD_Q))", f913, 2, 128},
  {"128:_mm_xor_pd(_mm_cmp_pd(x, y, _CMP_NLT_US), y)", f914, 2, 128},
  {"128:_mm_xor_pd(x, _mm_cmp_pd(x, y, _CMP_NLT_US))", f915, 2, 128},
  {"128:_mm_xor_pd(_mm_cmp_pd(x, y, _CMP_NLT_US), x)", f916, 2, 128},
  {"128:_mm_xor_pd(y, _mm_cmp_pd(x, y, _CMP_NLT_US))", f917, 2, 128},
  {"128:_mm_xor_pd(_mm_cmp_pd(x, y, _CMP_GT_OS), y)", f918, 2, 128},
  {"128:_mm_xor_pd(x, _mm_cmp_pd(x, y, _CMP_GT_OS))", f919, 2, 128},
  {"128:_mm_xor_pd(_mm_cmp_pd(x, y, _CMP_GT_OS), x)", f920, 2, 128},
  {"128:_mm_xor_pd(y, _mm_cmp_pd(x, y, _CMP_GT_OS))", f921, 2, 128},
  {"128:_mm_xor_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_LT_OS)), y)", f922, 2, 128},
  {"128:_mm_xor_pd(x, _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_LT_OS)))", f923, 2, 128},
  {"128:_mm_xor_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_LT_OS)), x)", f924, 2, 128},
  {"128:_mm_xor_pd(y, _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_LT_OS)))", f925, 2, 128},
  {"128:_mm_xor_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_LT_OS)), y)", f926, 2, 128},
  {"128:_mm_xor_pd(x, _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_LT_OS)))", f927, 2, 128},
  {"128:_mm_xor_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_LT_OS)), x)", f928, 2, 128},
  {"128:_mm_xor_pd(y, _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_LT_OS)))", f929, 2, 128},
  {"128:_mm_xor_pd(_mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_LT_OS), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_LT_OS), y)), y)", f930, 2, 128},
  {"128:_mm_xor_pd(x, _mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_LT_OS), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_LT_OS), y)))", f931, 2, 128},
  {"128:_mm_xor_pd(_mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_LT_OS), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_LT_OS), y)), x)", f932, 2, 128},
  {"128:_mm_xor_pd(y, _mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_LT_OS), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_LT_OS), y)))", f933, 2, 128},
  {"128:_mm_xor_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_LE_OS)), y)", f934, 2, 128},
  {"128:_mm_xor_pd(x, _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_LE_OS)))", f935, 2, 128},
  {"128:_mm_xor_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_LE_OS)), x)", f936, 2, 128},
  {"128:_mm_xor_pd(y, _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_LE_OS)))", f937, 2, 128},
  {"128:_mm_xor_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_LE_OS)), y)", f938, 2, 128},
  {"128:_mm_xor_pd(x, _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_LE_OS)))", f939, 2, 128},
  {"128:_mm_xor_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_LE_OS)), x)", f940, 2, 128},
  {"128:_mm_xor_pd(y, _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_LE_OS)))", f941, 2, 128},
  {"128:_mm_xor_pd(_mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_LE_OS), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_LE_OS), y)), y)", f942, 2, 128},
  {"128:_mm_xor_pd(x, _mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_LE_OS), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_LE_OS), y)))", f943, 2, 128},
  {"128:_mm_xor_pd(_mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_LE_OS), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_LE_OS), y)), x)", f944, 2, 128},
  {"128:_mm_xor_pd(y, _mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_LE_OS), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_LE_OS), y)))", f945, 2, 128},
  {"128:_mm_xor_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_GT_OS)), y)", f946, 2, 128},
  {"128:_mm_xor_pd(x, _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_GT_OS)))", f947, 2, 128},
  {"128:_mm_xor_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_GT_OS)), x)", f948, 2, 128},
  {"128:_mm_xor_pd(y, _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_GT_OS)))", f949, 2, 128},
  {"128:_mm_xor_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_GT_OS)), y)", f950, 2, 128},
  {"128:_mm_xor_pd(x, _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_GT_OS)))", f951, 2, 128},
  {"128:_mm_xor_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_GT_OS)), x)", f952, 2, 128},
  {"128:_mm_xor_pd(y, _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_GT_OS)))", f953, 2, 128},
  {"128:_mm_xor_pd(_mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_GT_OS), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_GT_OS), y)), y)", f954, 2, 128},
  {"128:_mm_xor_pd(x, _mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_GT_OS), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_GT_OS), y)))", f955, 2, 128},
  {"128:_mm_xor_pd(_mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_GT_OS), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_GT_OS), y)), x)", f956, 2, 128},
  {"128:_mm_xor_pd(y, _mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_GT_OS), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_GT_OS), y)))", f957, 2, 128},
  {"128:_mm_xor_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_NLT_US)), y)", f958, 2, 128},
  {"128:_mm_xor_pd(x, _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_NLT_US)))", f959, 2, 128},
  {"128:_mm_xor_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_NLT_US)), x)", f960, 2, 128},
  {"128:_mm_xor_pd(y, _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_NLT_US)))", f961, 2, 128},
  {"128:_mm_xor_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_NLT_US)), y)", f962, 2, 128},
  {"128:_mm_xor_pd(x, _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_NLT_US)))", f963, 2, 128},
  {"128:_mm_xor_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_NLT_US)), x)", f964, 2, 128},
  {"128:_mm_xor_pd(y, _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_NLT_US)))", f965, 2, 128},
  {"128:_mm_xor_pd(_mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_NLT_US), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_NLT_US), y)), y)", f966, 2, 128},
  {"128:_mm_xor_pd(x, _mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_NLT_US), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_NLT_US), y)))", f967, 2, 128},
  {"128:_mm_xor_pd(_mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_NLT_US), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_NLT_US), y)), x)", f968, 2, 128},
  {"128:_mm_xor_pd(y, _mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_NLT_US), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_NLT_US), y)))", f969, 2, 128},
  {"128:_mm_xor_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_EQ_OQ)), y)", f970, 2, 128},
  {"128:_mm_xor_pd(x, _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_EQ_OQ)))", f971, 2, 128},
  {"128:_mm_xor_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_EQ_OQ)), x)", f972, 2, 128},
  {"128:_mm_xor_pd(y, _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_EQ_OQ)))", f973, 2, 128},
  {"128:_mm_xor_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_EQ_OQ)), y)", f974, 2, 128},
  {"128:_mm_xor_pd(x, _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_EQ_OQ)))", f975, 2, 128},
  {"128:_mm_xor_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_EQ_OQ)), x)", f976, 2, 128},
  {"128:_mm_xor_pd(y, _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_EQ_OQ)))", f977, 2, 128},
  {"128:_mm_xor_pd(_mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_EQ_OQ), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_EQ_OQ), y)), y)", f978, 2, 128},
  {"128:_mm_xor_pd(x, _mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_EQ_OQ), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_EQ_OQ), y)))", f979, 2, 128},
  {"128:_mm_xor_pd(_mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_EQ_OQ), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_EQ_OQ), y)), x)", f980, 2, 128},
  {"128:_mm_xor_pd(y, _mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_EQ_OQ), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_EQ_OQ), y)))", f981, 2, 128},
  {"128:_mm_xor_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_UNORD_Q)), y)", f982, 2, 128},
  {"128:_mm_xor_pd(x, _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_UNORD_Q)))", f983, 2, 128},
  {"128:_mm_xor_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_UNORD_Q)), x)", f984, 2, 128},
  {"128:_mm_xor_pd(y, _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_UNORD_Q)))", f985, 2, 128},
  {"128:_mm_xor_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_UNORD_Q)), y)", f986, 2, 128},
  {"128:_mm_xor_pd(x, _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_UNORD_Q)))", f987, 2, 128},
  {"128:_mm_xor_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_UNORD_Q)), x)", f988, 2, 128},
  {"128:_mm_xor_pd(y, _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_UNORD_Q)))", f989, 2, 128},
  {"128:_mm_xor_pd(_mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_UNORD_Q), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_UNORD_Q), y)), y)", f990, 2, 128},
  {"128:_mm_xor_pd(x, _mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_UNORD_Q), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_UNORD_Q), y)))", f991, 2, 128},
  {"128:_mm_xor_pd(_mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_UNORD_Q), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_UNORD_Q), y)), x)", f992, 2, 128},
  {"128:_mm_xor_pd(y, _mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_UNORD_Q), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_UNORD_Q), y)))", f993, 2, 128},
  {"128:_mm_xor_pd(_mm_unpacklo_pd(x, y), y)", f994, 2, 128},
  {"128:_mm_xor_pd(x, _mm_unpacklo_pd(x, y))", f995, 2, 128},
  {"128:_mm_xor_pd(_mm_unpacklo_pd(x, y), x)", f996, 2, 128},
  {"128:_mm_xor_pd(y, _mm_unpacklo_pd(x, y))", f997, 2, 128},
  {"128:_mm_xor_pd(_mm_unpackhi_pd(x, y), y)", f998, 2, 128},
  {"128:_mm_xor_pd(x, _mm_unpackhi_pd(x, y))", f999, 2, 128},
  {"128:_mm_xor_pd(_mm_unpackhi_pd(x, y), x)", f1000, 2, 128},
  {"128:_mm_xor_pd(y, _mm_unpackhi_pd(x, y))", f1001, 2, 128},
  {"128:_mm_xor_pd(_mm_hadd_pd(x, y), y)", f1002, 2, 128},
  {"128:_mm_xor_pd(x, _mm_hadd_pd(x, y))", f1003, 2, 128},
  {"128:_mm_xor_pd(_mm_hadd_pd(x, y), x)", f1004, 2, 128},
  {"128:_mm_xor_pd(y, _mm_hadd_pd(x, y))", f1005, 2, 128},
  {"128:_mm_xor_pd(_mm_hsub_pd(x, y), y)", f1006, 2, 128},
  {"128:_mm_xor_pd(x, _mm_hsub_pd(x, y))", f1007, 2, 128},
  {"128:_mm_xor_pd(_mm_hsub_pd(x, y), x)", f1008, 2, 128},
  {"128:_mm_xor_pd(y, _mm_hsub_pd(x, y))", f1009, 2, 128},
  {"128:_mm_andnot_pd(_mm_add_pd(x, y), y)", f1010, 2, 128},
  {"128:_mm_andnot_pd(x, _mm_add_pd(x, y))", f1011, 2, 128},
  {"128:_mm_andnot_pd(_mm_add_pd(x, y), x)", f1012, 2, 128},
  {"128:_mm_andnot_pd(y, _mm_add_pd(x, y))", f1013, 2, 128},
  {"128:_mm_andnot_pd(_mm_sub_pd(x, y), y)", f1014, 2, 128},
  {"128:_mm_andnot_pd(x, _mm_sub_pd(x, y))", f1015, 2, 128},
  {"128:_mm_andnot_pd(_mm_sub_pd(x, y), x)", f1016, 2, 128},
  {"128:_mm_andnot_pd(y, _mm_sub_pd(x, y))", f1017, 2, 128},
  {"128:_mm_andnot_pd(_mm_mul_pd(x, y), y)", f1018, 2, 128},
  {"128:_mm_andnot_pd(x, _mm_mul_pd(x, y))", f1019, 2, 128},
  {"128:_mm_andnot_pd(_mm_mul_pd(x, y), x)", f1020, 2, 128},
  {"128:_mm_andnot_pd(y, _mm_mul_pd(x, y))", f1021, 2, 128},
  {"128:_mm_andnot_pd(_mm_div_pd(x, y), y)", f1022, 2, 128},
  {"128:_mm_andnot_pd(x, _mm_div_pd(x, y))", f1023, 2, 128},
  {"128:_mm_andnot_pd(_mm_div_pd(x, y), x)", f1024, 2, 128},
  {"128:_mm_andnot_pd(y, _mm_div_pd(x, y))", f1025, 2, 128},
  {"128:_mm_andnot_pd(_mm_min_pd(x, y), y)", f1026, 2, 128},
  {"128:_mm_andnot_pd(x, _mm_min_pd(x, y))", f1027, 2, 128},
  {"128:_mm_andnot_pd(_mm_min_pd(x, y), x)", f1028, 2, 128},
  {"128:_mm_andnot_pd(y, _mm_min_pd(x, y))", f1029, 2, 128},
  {"128:_mm_andnot_pd(_mm_max_pd(x, y), y)", f1030, 2, 128},
  {"128:_mm_andnot_pd(x, _mm_max_pd(x, y))", f1031, 2, 128},
  {"128:_mm_andnot_pd(_mm_max_pd(x, y), x)", f1032, 2, 128},
  {"128:_mm_andnot_pd(y, _mm_max_pd(x, y))", f1033, 2, 128},
  {"128:_mm_andnot_pd(_mm_and_pd(x, y), y)", f1034, 2, 128},
  {"128:_mm_andnot_pd(x, _mm_and_pd(x, y))", f1035, 2, 128},
  {"128:_mm_andnot_pd(_mm_and_pd(x, y), x)", f1036, 2, 128},
  {"128:_mm_andnot_pd(y, _mm_and_pd(x, y))", f1037, 2, 128},
  {"128:_mm_andnot_pd(_mm_or_pd(x, y), y)", f1038, 2, 128},
  {"128:_mm_andnot_pd(x, _mm_or_pd(x, y))", f1039, 2, 128},
  {"128:_mm_andnot_pd(_mm_or_pd(x, y), x)", f1040, 2, 128},
  {"128:_mm_andnot_pd(y, _mm_or_pd(x, y))", f1041, 2, 128},
  {"128:_mm_andnot_pd(_mm_xor_pd(x, y), y)", f1042, 2, 128},
  {"128:_mm_andnot_pd(x, _mm_xor_pd(x, y))", f1043, 2, 128},
  {"128:_mm_andnot_pd(_mm_xor_pd(x, y), x)", f1044, 2, 128},
  {"128:_mm_andnot_pd(y, _mm_xor_pd(x, y))", f1045, 2, 128},
  {"128:_mm_andnot_pd(_mm_andnot_pd(x, y), y)", f1046, 2, 128},
  {"128:_mm_andnot_pd(x, _mm_andnot_pd(x, y))", f1047, 2, 128},
  {"128:_mm_andnot_pd(_mm_andnot_pd(x, y), x)", f1048, 2, 128},
  {"128:_mm_andnot_pd(y, _mm_andnot_pd(x, y))", f1049, 2, 128},
  {"128:_mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_EQ_OQ), y)", f1050, 2, 128},
  {"128:_mm_andnot_pd(x, _mm_cmp_pd(x, y, _CMP_EQ_OQ))", f1051, 2, 128},
  {"128:_mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_EQ_OQ), x)", f1052, 2, 128},
  {"128:_mm_andnot_pd(y, _mm_cmp_pd(x, y, _CMP_EQ_OQ))", f1053, 2, 128},
  {"128:_mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_LT_OS), y)", f1054, 2, 128},
  {"128:_mm_andnot_pd(x, _mm_cmp_pd(x, y, _CMP_LT_OS))", f1055, 2, 128},
  {"128:_mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_LT_OS), x)", f1056, 2, 128},
  {"128:_mm_andnot_pd(y, _mm_cmp_pd(x, y, _CMP_LT_OS))", f1057, 2, 128},
  {"128:_mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_LE_OS), y)", f1058, 2, 128},
  {"128:_mm_andnot_pd(x, _mm_cmp_pd(x, y, _CMP_LE_OS))", f1059, 2, 128},
  {"128:_mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_LE_OS), x)", f1060, 2, 128},
  {"128:_mm_andnot_pd(y, _mm_cmp_pd(x, y, _CMP_LE_OS))", f1061, 2, 128},
  {"128:_mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_NEQ_UQ), y)", f1062, 2, 128},
  {"128:_mm_andnot_pd(x, _mm_cmp_pd(x, y, _CMP_NEQ_UQ))", f1063, 2, 128},
  {"128:_mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_NEQ_UQ), x)", f1064, 2, 128},
  {"128:_mm_andnot_pd(y, _mm_cmp_pd(x, y, _CMP_NEQ_UQ))", f1065, 2, 128},
  {"128:_mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_UNORD_Q), y)", f1066, 2, 128},
  {"128:_mm_andnot_pd(x, _mm_cmp_pd(x, y, _CMP_UNORD_Q))", f1067, 2, 128},
  {"128:_mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_UNORD_Q), x)", f1068, 2, 128},
  {"128:_mm_andnot_pd(y, _mm_cmp_pd(x, y, _CMP_UNORD_Q))", f1069, 2, 128},
  {"128:_mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_NLT_US), y)", f1070, 2, 128},
  {"128:_mm_andnot_pd(x, _mm_cmp_pd(x, y, _CMP_NLT_US))", f1071, 2, 128},
  {"128:_mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_NLT_US), x)", f1072, 2, 128},
  {"128:_mm_andnot_pd(y, _mm_cmp_pd(x, y, _CMP_NLT_US))", f1073, 2, 128},
  {"128:_mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_GT_OS), y)", f1074, 2, 128},
  {"128:_mm_andnot_pd(x, _mm_cmp_pd(x, y, _CMP_GT_OS))", f1075, 2, 128},
  {"128:_mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_GT_OS), x)", f1076, 2, 128},
  {"128:_mm_andnot_pd(y, _mm_cmp_pd(x, y, _CMP_GT_OS))", f1077, 2, 128},
  {"128:_mm_andnot_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_LT_OS)), y)", f1078, 2, 128},
  {"128:_mm_andnot_pd(x, _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_LT_OS)))", f1079, 2, 128},
  {"128:_mm_andnot_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_LT_OS)), x)", f1080, 2, 128},
  {"128:_mm_andnot_pd(y, _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_LT_OS)))", f1081, 2, 128},
  {"128:_mm_andnot_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_LT_OS)), y)", f1082, 2, 128},
  {"128:_mm_andnot_pd(x, _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_LT_OS)))", f1083, 2, 128},
  {"128:_mm_andnot_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_LT_OS)), x)", f1084, 2, 128},
  {"128:_mm_andnot_pd(y, _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_LT_OS)))", f1085, 2, 128},
  {"128:_mm_andnot_pd(_mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_LT_OS), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_LT_OS), y)), y)", f1086, 2, 128},
  {"128:_mm_andnot_pd(x, _mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_LT_OS), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_LT_OS), y)))", f1087, 2, 128},
  {"128:_mm_andnot_pd(_mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_LT_OS), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_LT_OS), y)), x)", f1088, 2, 128},
  {"128:_mm_andnot_pd(y, _mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_LT_OS), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_LT_OS), y)))", f1089, 2, 128},
  {"128:_mm_andnot_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_LE_OS)), y)", f1090, 2, 128},
  {"128:_mm_andnot_pd(x, _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_LE_OS)))", f1091, 2, 128},
  {"128:_mm_andnot_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_LE_OS)), x)", f1092, 2, 128},
  {"128:_mm_andnot_pd(y, _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_LE_OS)))", f1093, 2, 128},
  {"128:_mm_andnot_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_LE_OS)), y)", f1094, 2, 128},
  {"128:_mm_andnot_pd(x, _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_LE_OS)))", f1095, 2, 128},
  {"128:_mm_andnot_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_LE_OS)), x)", f1096, 2, 128},
  {"128:_mm_andnot_pd(y, _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_LE_OS)))", f1097, 2, 128},
  {"128:_mm_andnot_pd(_mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_LE_OS), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_LE_OS), y)), y)", f1098, 2, 128},
  {"128:_mm_andnot_pd(x, _mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_LE_OS), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_LE_OS), y)))", f1099, 2, 128},
  {"128:_mm_andnot_pd(_mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_LE_OS), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_LE_OS), y)), x)", f1100, 2, 128},
  {"128:_mm_andnot_pd(y, _mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_LE_OS), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_LE_OS), y)))", f1101, 2, 128},
  {"128:_mm_andnot_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_GT_OS)), y)", f1102, 2, 128},
  {"128:_mm_andnot_pd(x, _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_GT_OS)))", f1103, 2, 128},
  {"128:_mm_andnot_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_GT_OS)), x)", f1104, 2, 128},
  {"128:_mm_andnot_pd(y, _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_GT_OS)))", f1105, 2, 128},
  {"128:_mm_andnot_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_GT_OS)), y)", f1106, 2, 128},
  {"128:_mm_andnot_pd(x, _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_GT_OS)))", f1107, 2, 128},
  {"128:_mm_andnot_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_GT_OS)), x)", f1108, 2, 128},
  {"128:_mm_andnot_pd(y, _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_GT_OS)))", f1109, 2, 128},
  {"128:_mm_andnot_pd(_mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_GT_OS), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_GT_OS), y)), y)", f1110, 2, 128},
  {"128:_mm_andnot_pd(x, _mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_GT_OS), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_GT_OS), y)))", f1111, 2, 128},
  {"128:_mm_andnot_pd(_mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_GT_OS), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_GT_OS), y)), x)", f1112, 2, 128},
  {"128:_mm_andnot_pd(y, _mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_GT_OS), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_GT_OS), y)))", f1113, 2, 128},
  {"128:_mm_andnot_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_NLT_US)), y)", f1114, 2, 128},
  {"128:_mm_andnot_pd(x, _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_NLT_US)))", f1115, 2, 128},
  {"128:_mm_andnot_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_NLT_US)), x)", f1116, 2, 128},
  {"128:_mm_andnot_pd(y, _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_NLT_US)))", f1117, 2, 128},
  {"128:_mm_andnot_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_NLT_US)), y)", f1118, 2, 128},
  {"128:_mm_andnot_pd(x, _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_NLT_US)))", f1119, 2, 128},
  {"128:_mm_andnot_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_NLT_US)), x)", f1120, 2, 128},
  {"128:_mm_andnot_pd(y, _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_NLT_US)))", f1121, 2, 128},
  {"128:_mm_andnot_pd(_mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_NLT_US), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_NLT_US), y)), y)", f1122, 2, 128},
  {"128:_mm_andnot_pd(x, _mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_NLT_US), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_NLT_US), y)))", f1123, 2, 128},
  {"128:_mm_andnot_pd(_mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_NLT_US), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_NLT_US), y)), x)", f1124, 2, 128},
  {"128:_mm_andnot_pd(y, _mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_NLT_US), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_NLT_US), y)))", f1125, 2, 128},
  {"128:_mm_andnot_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_EQ_OQ)), y)", f1126, 2, 128},
  {"128:_mm_andnot_pd(x, _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_EQ_OQ)))", f1127, 2, 128},
  {"128:_mm_andnot_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_EQ_OQ)), x)", f1128, 2, 128},
  {"128:_mm_andnot_pd(y, _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_EQ_OQ)))", f1129, 2, 128},
  {"128:_mm_andnot_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_EQ_OQ)), y)", f1130, 2, 128},
  {"128:_mm_andnot_pd(x, _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_EQ_OQ)))", f1131, 2, 128},
  {"128:_mm_andnot_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_EQ_OQ)), x)", f1132, 2, 128},
  {"128:_mm_andnot_pd(y, _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_EQ_OQ)))", f1133, 2, 128},
  {"128:_mm_andnot_pd(_mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_EQ_OQ), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_EQ_OQ), y)), y)", f1134, 2, 128},
  {"128:_mm_andnot_pd(x, _mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_EQ_OQ), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_EQ_OQ), y)))", f1135, 2, 128},
  {"128:_mm_andnot_pd(_mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_EQ_OQ), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_EQ_OQ), y)), x)", f1136, 2, 128},
  {"128:_mm_andnot_pd(y, _mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_EQ_OQ), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_EQ_OQ), y)))", f1137, 2, 128},
  {"128:_mm_andnot_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_UNORD_Q)), y)", f1138, 2, 128},
  {"128:_mm_andnot_pd(x, _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_UNORD_Q)))", f1139, 2, 128},
  {"128:_mm_andnot_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_UNORD_Q)), x)", f1140, 2, 128},
  {"128:_mm_andnot_pd(y, _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_UNORD_Q)))", f1141, 2, 128},
  {"128:_mm_andnot_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_UNORD_Q)), y)", f1142, 2, 128},
  {"128:_mm_andnot_pd(x, _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_UNORD_Q)))", f1143, 2, 128},
  {"128:_mm_andnot_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_UNORD_Q)), x)", f1144, 2, 128},
  {"128:_mm_andnot_pd(y, _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_UNORD_Q)))", f1145, 2, 128},
  {"128:_mm_andnot_pd(_mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_UNORD_Q), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_UNORD_Q), y)), y)", f1146, 2, 128},
  {"128:_mm_andnot_pd(x, _mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_UNORD_Q), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_UNORD_Q), y)))", f1147, 2, 128},
  {"128:_mm_andnot_pd(_mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_UNORD_Q), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_UNORD_Q), y)), x)", f1148, 2, 128},
  {"128:_mm_andnot_pd(y, _mm_or_pd(_mm_and_pd(_mm_cmp_pd(x, y, _CMP_UNORD_Q), x), _mm_andnot_pd(_mm_cmp_pd(x, y, _CMP_UNORD_Q), y)))", f1149, 2, 128},
  {"128:_mm_andnot_pd(_mm_unpacklo_pd(x, y), y)", f1150, 2, 128},
  {"128:_mm_andnot_pd(x, _mm_unpacklo_pd(x, y))", f1151, 2, 128},
  {"128:_mm_andnot_pd(_mm_unpacklo_pd(x, y), x)", f1152, 2, 128},
  {"128:_mm_andnot_pd(y, _mm_unpacklo_pd(x, y))", f1153, 2, 128},
  {"128:_mm_andnot_pd(_mm_unpackhi_pd(x, y), y)", f1154, 2, 128},
  {"128:_mm_andnot_pd(x, _mm_unpackhi_pd(x, y))", f1155, 2, 128},
  {"128:_mm_andnot_pd(_mm_unpackhi_pd(x, y), x)", f1156, 2, 128},
  {"128:_mm_andnot_pd(y, _mm_unpackhi_pd(x, y))", f1157, 2, 128},
  {"128:_mm_andnot_pd(_mm_hadd_pd(x, y), y)", f1158, 2, 128},
  {"128:_mm_andnot_pd(x, _mm_hadd_pd(x, y))", f1159, 2, 128},
  {"128:_mm_andnot_pd(_mm_hadd_pd(x, y), x)", f1160, 2, 128},
  {"128:_mm_andnot_pd(y, _mm_hadd_pd(x, y))", f1161, 2, 128},
  {"128:_mm_andnot_pd(_mm_hsub_pd(x, y), y)", f1162, 2, 128},
  {"128:_mm_andnot_pd(x, _mm_hsub_pd(x, y))", f1163, 2, 128},
  {"128:_mm_andnot_pd(_mm_hsub_pd(x, y), x)", f1164, 2, 128},
  {"128:_mm_andnot_pd(y, _mm_hsub_pd(x, y))", f1165, 2, 128},
  {"128:_mm_cmp_pd(_mm_add_pd(x, y), y, _CMP_EQ_OQ)", f1166, 2, 128},
  {"128:_mm_cmp_pd(x, _mm_add_pd(x, y), _CMP_EQ_OQ)", f1167, 2, 128},
  {"128:_mm_cmp_pd(_mm_add_pd(x, y), x, _CMP_EQ_OQ)", f1168, 2, 128},
  {"128:_mm_cmp_pd(y, _mm_add_pd(x, y), _CMP_EQ_OQ)", f1169, 2, 128},
  {"128:_mm_cmp_pd(_mm_sub_pd(x, y), y, _CMP_EQ_OQ)", f1170, 2, 128},
  {"128:_mm_cmp_pd(x, _mm_sub_pd(x, y), _CMP_EQ_OQ)", f1171, 2, 128},
  {"128:_mm_cmp_pd(_mm_sub_pd(x, y), x, _CMP_EQ_OQ)", f1172, 2, 128},
  {"128:_mm_cmp_pd(y, _mm_sub_pd(x, y), _CMP_EQ_OQ)", f1173, 2, 128},
  {"128:_mm_cmp_pd(_mm_mul_pd(x, y), y, _CMP_EQ_OQ)", f1174, 2, 128},
  {"128:_mm_cmp_pd(x, _mm_mul_pd(x, y), _CMP_EQ_OQ)", f1175, 2, 128},
  {"128:_mm_cmp_pd(_mm_mul_pd(x, y), x, _CMP_EQ_OQ)", f1176, 2, 128},
  {"128:_mm_cmp_pd(y, _mm_mul_pd(x, y), _CMP_EQ_OQ)", f1177, 2, 128},
  {"128:_mm_cmp_pd(_mm_div_pd(x, y), y, _CMP_EQ_OQ)", f1178, 2, 128},
  {"128:_mm_cmp_pd(x, _mm_div_pd(x, y), _CMP_EQ_OQ)", f1179, 2, 128},
  {"128:_mm_cmp_pd(_mm_div_pd(x, y), x, _CMP_EQ_OQ)", f1180, 2, 128},
  {"128:_mm_cmp_pd(y, _mm_div_pd(x, y), _CMP_EQ_OQ)", f1181, 2, 128},
  {"128:_mm_cmp_pd(_mm_min_pd(x, y), y, _CMP_EQ_OQ)", f1182, 2, 128},
  {"128:_mm_cmp_pd(x, _mm_min_pd(x, y), _CMP_EQ_OQ)", f1183, 2, 128},
  {"128:_mm_cmp_pd(_mm_min_pd(x, y), x, _CMP_EQ_OQ)", f1184, 2, 128},
  {"128:_mm_cmp_pd(y, _mm_min_pd(x, y), _CMP_EQ_OQ)", f1185, 2, 128},
  {"128:_mm_cmp_pd(_mm_max_pd(x, y), y, _CMP_EQ_OQ)", f1186, 2, 128},
  {"128:_mm_cmp_pd(x, _mm_max_pd(x, y), _CMP_EQ_OQ)", f1187, 2, 128},
  {"128:_mm_cmp_pd(_mm_max_pd(x, y), x, _CMP_EQ_OQ)", f1188, 2, 128},
  {"128:_mm_cmp_pd(y, _mm_max_pd(x, y), _CMP_EQ_OQ)", f1189, 2, 128},
  {"128:_mm_cmp_pd(_mm_and_pd(x, y), y, _CMP_EQ_OQ)", f1190, 2, 128},
  {"128:_mm_cmp_pd(x, _mm_and_pd(x, y), _CMP_EQ_OQ)", f1191, 2, 128},
  {"128:_mm_cmp_pd(_mm_and_pd(x, y), x, _CMP_EQ_OQ)", f1192, 2, 128},
  {"128:_mm_cmp_pd(y, _mm_and_pd(x, y), _CMP_EQ_OQ)", f1193, 2, 128},
  {"128:_mm_cmp_pd(_mm_or_pd(x, y), y, _CMP_EQ_OQ)", f1194, 2, 128},
  {"128:_mm_cmp_pd(x, _mm_or_pd(x, y), _CMP_EQ_OQ)", f1195, 2, 128},
  {"128:_mm_cmp_pd(_mm_or_pd(x, y), x, _CMP_EQ_OQ)", f1196, 2, 128},
  {"128:_mm_cmp_pd(y, _mm_or_pd(x, y), _CMP_EQ_OQ)", f1197, 2, 128},
  {"128:_mm_cmp_pd(_mm_xor_pd(x, y), y, _CMP_EQ_OQ)", f1198, 2, 128},
  {"128:_mm_cmp_pd(x, _mm_xor_pd(x, y), _CMP_EQ_OQ)", f1199, 2, 128},
};
extern const int size_36 = 1200;
