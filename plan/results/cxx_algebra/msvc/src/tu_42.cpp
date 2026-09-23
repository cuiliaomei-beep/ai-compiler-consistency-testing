#include "common.h"
static NOINLINE void f0(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_mul_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LT_OQ)), _mm_set1_ps(-1.0f)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_floor_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LT_OQ))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f2(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_ceil_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LT_OQ))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f3(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_round_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LT_OQ)), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f4(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_permute_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LT_OQ)), 0x1b); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f5(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_permute_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LT_OQ)), 0x39); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f6(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_permute_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LT_OQ)), 0x93); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f7(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_permute_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LT_OQ)), 0x4e); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f8(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_cvtepi32_ps(_mm_cvttps_epi32(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LT_OQ)))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f9(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_cvtepi32_ps(_mm_cvtps_epi32(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LT_OQ)))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f10(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_movehdup_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LT_OQ))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f11(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_sqrt_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LT_OQ))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f12(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LT_OQ)), _mm_set1_ps(-0.0f)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f13(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_andnot_ps(_mm_set1_ps(-0.0f), _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LT_OQ))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f14(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_sub_ps(_mm_setzero_ps(), _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LT_OQ))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f15(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_mul_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LT_OQ)), _mm_set1_ps(-1.0f)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f16(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_floor_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LT_OQ))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f17(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_ceil_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LT_OQ))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f18(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_round_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LT_OQ)), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f19(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_permute_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LT_OQ)), 0x1b); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f20(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_permute_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LT_OQ)), 0x39); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f21(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_permute_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LT_OQ)), 0x93); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f22(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_permute_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LT_OQ)), 0x4e); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f23(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_cvtepi32_ps(_mm_cvttps_epi32(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LT_OQ)))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f24(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_cvtepi32_ps(_mm_cvtps_epi32(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LT_OQ)))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f25(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_movehdup_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LT_OQ))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f26(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_fmadd_pd(x, y, _mm_setzero_pd()); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f27(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_fmadd_pd(x, _mm_setzero_pd(), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f28(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_fmadd_pd(_mm_setzero_pd(), x, y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f29(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_fmadd_pd(x, y, _mm_set1_pd(-0.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f30(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_fmadd_pd(x, _mm_set1_pd(-0.0), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f31(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_fmadd_pd(_mm_set1_pd(-0.0), x, y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f32(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_fmadd_pd(x, y, _mm_set1_pd(1.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f33(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_fmadd_pd(x, _mm_set1_pd(1.0), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f34(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_fmadd_pd(_mm_set1_pd(1.0), x, y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f35(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_fmadd_pd(x, y, _mm_set1_pd(-1.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f36(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_fmadd_pd(x, _mm_set1_pd(-1.0), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f37(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_fmadd_pd(_mm_set1_pd(-1.0), x, y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f38(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_fmadd_pd(x, y, _mm_set1_pd(std::numeric_limits<double>::infinity())); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f39(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_fmadd_pd(x, _mm_set1_pd(std::numeric_limits<double>::infinity()), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f40(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_fmadd_pd(_mm_set1_pd(std::numeric_limits<double>::infinity()), x, y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f41(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_fmadd_pd(x, y, _mm_set1_pd(std::numeric_limits<double>::quiet_NaN())); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f42(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_fmadd_pd(x, _mm_set1_pd(std::numeric_limits<double>::quiet_NaN()), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f43(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_fmadd_pd(_mm_set1_pd(std::numeric_limits<double>::quiet_NaN()), x, y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f44(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_fmadd_pd(x, y, x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f45(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_fmadd_pd(x, x, y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f46(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_fmadd_pd(x, y, _mm_mul_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f47(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_fmsub_pd(x, y, _mm_setzero_pd()); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f48(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_fmsub_pd(x, _mm_setzero_pd(), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f49(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_fmsub_pd(_mm_setzero_pd(), x, y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f50(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_fmsub_pd(x, y, _mm_set1_pd(-0.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f51(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_fmsub_pd(x, _mm_set1_pd(-0.0), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f52(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_fmsub_pd(_mm_set1_pd(-0.0), x, y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f53(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_fmsub_pd(x, y, _mm_set1_pd(1.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f54(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_fmsub_pd(x, _mm_set1_pd(1.0), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f55(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_fmsub_pd(_mm_set1_pd(1.0), x, y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f56(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_fmsub_pd(x, y, _mm_set1_pd(-1.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f57(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_fmsub_pd(x, _mm_set1_pd(-1.0), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f58(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_fmsub_pd(_mm_set1_pd(-1.0), x, y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f59(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_fmsub_pd(x, y, _mm_set1_pd(std::numeric_limits<double>::infinity())); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f60(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_fmsub_pd(x, _mm_set1_pd(std::numeric_limits<double>::infinity()), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f61(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_fmsub_pd(_mm_set1_pd(std::numeric_limits<double>::infinity()), x, y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f62(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_fmsub_pd(x, y, _mm_set1_pd(std::numeric_limits<double>::quiet_NaN())); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f63(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_fmsub_pd(x, _mm_set1_pd(std::numeric_limits<double>::quiet_NaN()), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f64(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_fmsub_pd(_mm_set1_pd(std::numeric_limits<double>::quiet_NaN()), x, y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f65(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_fmsub_pd(x, y, x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f66(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_fmsub_pd(x, x, y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f67(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_fmsub_pd(x, y, _mm_mul_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f68(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_fnmadd_pd(x, y, _mm_setzero_pd()); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f69(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_fnmadd_pd(x, _mm_setzero_pd(), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f70(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_fnmadd_pd(_mm_setzero_pd(), x, y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f71(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_fnmadd_pd(x, y, _mm_set1_pd(-0.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f72(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_fnmadd_pd(x, _mm_set1_pd(-0.0), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f73(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_fnmadd_pd(_mm_set1_pd(-0.0), x, y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f74(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_fnmadd_pd(x, y, _mm_set1_pd(1.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f75(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_fnmadd_pd(x, _mm_set1_pd(1.0), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f76(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_fnmadd_pd(_mm_set1_pd(1.0), x, y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f77(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_fnmadd_pd(x, y, _mm_set1_pd(-1.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f78(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_fnmadd_pd(x, _mm_set1_pd(-1.0), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f79(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_fnmadd_pd(_mm_set1_pd(-1.0), x, y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f80(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_fnmadd_pd(x, y, _mm_set1_pd(std::numeric_limits<double>::infinity())); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f81(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_fnmadd_pd(x, _mm_set1_pd(std::numeric_limits<double>::infinity()), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f82(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_fnmadd_pd(_mm_set1_pd(std::numeric_limits<double>::infinity()), x, y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f83(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_fnmadd_pd(x, y, _mm_set1_pd(std::numeric_limits<double>::quiet_NaN())); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f84(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_fnmadd_pd(x, _mm_set1_pd(std::numeric_limits<double>::quiet_NaN()), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f85(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_fnmadd_pd(_mm_set1_pd(std::numeric_limits<double>::quiet_NaN()), x, y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f86(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_fnmadd_pd(x, y, x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f87(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_fnmadd_pd(x, x, y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f88(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_fnmadd_pd(x, y, _mm_mul_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f89(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_fnmsub_pd(x, y, _mm_setzero_pd()); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f90(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_fnmsub_pd(x, _mm_setzero_pd(), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f91(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_fnmsub_pd(_mm_setzero_pd(), x, y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f92(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_fnmsub_pd(x, y, _mm_set1_pd(-0.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f93(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_fnmsub_pd(x, _mm_set1_pd(-0.0), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f94(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_fnmsub_pd(_mm_set1_pd(-0.0), x, y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f95(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_fnmsub_pd(x, y, _mm_set1_pd(1.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f96(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_fnmsub_pd(x, _mm_set1_pd(1.0), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f97(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_fnmsub_pd(_mm_set1_pd(1.0), x, y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f98(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_fnmsub_pd(x, y, _mm_set1_pd(-1.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f99(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_fnmsub_pd(x, _mm_set1_pd(-1.0), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f100(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_fnmsub_pd(_mm_set1_pd(-1.0), x, y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f101(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_fnmsub_pd(x, y, _mm_set1_pd(std::numeric_limits<double>::infinity())); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f102(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_fnmsub_pd(x, _mm_set1_pd(std::numeric_limits<double>::infinity()), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f103(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_fnmsub_pd(_mm_set1_pd(std::numeric_limits<double>::infinity()), x, y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f104(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_fnmsub_pd(x, y, _mm_set1_pd(std::numeric_limits<double>::quiet_NaN())); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f105(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_fnmsub_pd(x, _mm_set1_pd(std::numeric_limits<double>::quiet_NaN()), y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f106(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_fnmsub_pd(_mm_set1_pd(std::numeric_limits<double>::quiet_NaN()), x, y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f107(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_fnmsub_pd(x, y, x); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f108(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_fnmsub_pd(x, x, y); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f109(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_fnmsub_pd(x, y, _mm_mul_pd(x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f110(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_GE_OS)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f111(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_GE_OS)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f112(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_NLE_US)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f113(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_NLE_US)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f114(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_NGT_US)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f115(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_NGT_US)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f116(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_LE_OQ)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f117(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_LE_OQ)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f118(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_GE_OQ)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f119(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_GE_OQ)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f120(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_LT_OQ)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f121(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_LT_OQ)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f122(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sqrt_pd(_mm_fmadd_pd(x, y, _mm_setzero_pd())); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f123(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(_mm_fmadd_pd(x, y, _mm_setzero_pd()), _mm_set1_pd(-0.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f124(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(_mm_set1_pd(-0.0), _mm_fmadd_pd(x, y, _mm_setzero_pd())); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f125(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sub_pd(_mm_setzero_pd(), _mm_fmadd_pd(x, y, _mm_setzero_pd())); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f126(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_mul_pd(_mm_fmadd_pd(x, y, _mm_setzero_pd()), _mm_set1_pd(-1.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f127(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_floor_pd(_mm_fmadd_pd(x, y, _mm_setzero_pd())); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f128(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_ceil_pd(_mm_fmadd_pd(x, y, _mm_setzero_pd())); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f129(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_round_pd(_mm_fmadd_pd(x, y, _mm_setzero_pd()), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f130(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fmadd_pd(x, y, _mm_setzero_pd()), 0x5); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f131(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fmadd_pd(x, y, _mm_setzero_pd()), 0xa); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f132(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fmadd_pd(x, y, _mm_setzero_pd()), 0x3); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f133(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sqrt_pd(_mm_fmadd_pd(x, _mm_setzero_pd(), y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f134(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(_mm_fmadd_pd(x, _mm_setzero_pd(), y), _mm_set1_pd(-0.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f135(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(_mm_set1_pd(-0.0), _mm_fmadd_pd(x, _mm_setzero_pd(), y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f136(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sub_pd(_mm_setzero_pd(), _mm_fmadd_pd(x, _mm_setzero_pd(), y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f137(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_mul_pd(_mm_fmadd_pd(x, _mm_setzero_pd(), y), _mm_set1_pd(-1.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f138(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_floor_pd(_mm_fmadd_pd(x, _mm_setzero_pd(), y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f139(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_ceil_pd(_mm_fmadd_pd(x, _mm_setzero_pd(), y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f140(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_round_pd(_mm_fmadd_pd(x, _mm_setzero_pd(), y), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f141(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fmadd_pd(x, _mm_setzero_pd(), y), 0x5); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f142(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fmadd_pd(x, _mm_setzero_pd(), y), 0xa); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f143(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fmadd_pd(x, _mm_setzero_pd(), y), 0x3); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f144(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sqrt_pd(_mm_fmadd_pd(_mm_setzero_pd(), x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f145(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(_mm_fmadd_pd(_mm_setzero_pd(), x, y), _mm_set1_pd(-0.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f146(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(_mm_set1_pd(-0.0), _mm_fmadd_pd(_mm_setzero_pd(), x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f147(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sub_pd(_mm_setzero_pd(), _mm_fmadd_pd(_mm_setzero_pd(), x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f148(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_mul_pd(_mm_fmadd_pd(_mm_setzero_pd(), x, y), _mm_set1_pd(-1.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f149(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_floor_pd(_mm_fmadd_pd(_mm_setzero_pd(), x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f150(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_ceil_pd(_mm_fmadd_pd(_mm_setzero_pd(), x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f151(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_round_pd(_mm_fmadd_pd(_mm_setzero_pd(), x, y), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f152(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fmadd_pd(_mm_setzero_pd(), x, y), 0x5); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f153(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fmadd_pd(_mm_setzero_pd(), x, y), 0xa); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f154(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fmadd_pd(_mm_setzero_pd(), x, y), 0x3); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f155(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sqrt_pd(_mm_fmadd_pd(x, y, _mm_set1_pd(-0.0))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f156(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(_mm_fmadd_pd(x, y, _mm_set1_pd(-0.0)), _mm_set1_pd(-0.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f157(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(_mm_set1_pd(-0.0), _mm_fmadd_pd(x, y, _mm_set1_pd(-0.0))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f158(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sub_pd(_mm_setzero_pd(), _mm_fmadd_pd(x, y, _mm_set1_pd(-0.0))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f159(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_mul_pd(_mm_fmadd_pd(x, y, _mm_set1_pd(-0.0)), _mm_set1_pd(-1.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f160(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_floor_pd(_mm_fmadd_pd(x, y, _mm_set1_pd(-0.0))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f161(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_ceil_pd(_mm_fmadd_pd(x, y, _mm_set1_pd(-0.0))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f162(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_round_pd(_mm_fmadd_pd(x, y, _mm_set1_pd(-0.0)), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f163(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fmadd_pd(x, y, _mm_set1_pd(-0.0)), 0x5); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f164(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fmadd_pd(x, y, _mm_set1_pd(-0.0)), 0xa); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f165(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fmadd_pd(x, y, _mm_set1_pd(-0.0)), 0x3); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f166(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sqrt_pd(_mm_fmadd_pd(x, _mm_set1_pd(-0.0), y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f167(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(_mm_fmadd_pd(x, _mm_set1_pd(-0.0), y), _mm_set1_pd(-0.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f168(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(_mm_set1_pd(-0.0), _mm_fmadd_pd(x, _mm_set1_pd(-0.0), y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f169(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sub_pd(_mm_setzero_pd(), _mm_fmadd_pd(x, _mm_set1_pd(-0.0), y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f170(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_mul_pd(_mm_fmadd_pd(x, _mm_set1_pd(-0.0), y), _mm_set1_pd(-1.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f171(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_floor_pd(_mm_fmadd_pd(x, _mm_set1_pd(-0.0), y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f172(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_ceil_pd(_mm_fmadd_pd(x, _mm_set1_pd(-0.0), y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f173(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_round_pd(_mm_fmadd_pd(x, _mm_set1_pd(-0.0), y), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f174(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fmadd_pd(x, _mm_set1_pd(-0.0), y), 0x5); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f175(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fmadd_pd(x, _mm_set1_pd(-0.0), y), 0xa); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f176(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fmadd_pd(x, _mm_set1_pd(-0.0), y), 0x3); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f177(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sqrt_pd(_mm_fmadd_pd(_mm_set1_pd(-0.0), x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f178(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(_mm_fmadd_pd(_mm_set1_pd(-0.0), x, y), _mm_set1_pd(-0.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f179(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(_mm_set1_pd(-0.0), _mm_fmadd_pd(_mm_set1_pd(-0.0), x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f180(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sub_pd(_mm_setzero_pd(), _mm_fmadd_pd(_mm_set1_pd(-0.0), x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f181(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_mul_pd(_mm_fmadd_pd(_mm_set1_pd(-0.0), x, y), _mm_set1_pd(-1.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f182(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_floor_pd(_mm_fmadd_pd(_mm_set1_pd(-0.0), x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f183(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_ceil_pd(_mm_fmadd_pd(_mm_set1_pd(-0.0), x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f184(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_round_pd(_mm_fmadd_pd(_mm_set1_pd(-0.0), x, y), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f185(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fmadd_pd(_mm_set1_pd(-0.0), x, y), 0x5); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f186(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fmadd_pd(_mm_set1_pd(-0.0), x, y), 0xa); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f187(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fmadd_pd(_mm_set1_pd(-0.0), x, y), 0x3); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f188(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sqrt_pd(_mm_fmadd_pd(x, y, _mm_set1_pd(1.0))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f189(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(_mm_fmadd_pd(x, y, _mm_set1_pd(1.0)), _mm_set1_pd(-0.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f190(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(_mm_set1_pd(-0.0), _mm_fmadd_pd(x, y, _mm_set1_pd(1.0))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f191(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sub_pd(_mm_setzero_pd(), _mm_fmadd_pd(x, y, _mm_set1_pd(1.0))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f192(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_mul_pd(_mm_fmadd_pd(x, y, _mm_set1_pd(1.0)), _mm_set1_pd(-1.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f193(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_floor_pd(_mm_fmadd_pd(x, y, _mm_set1_pd(1.0))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f194(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_ceil_pd(_mm_fmadd_pd(x, y, _mm_set1_pd(1.0))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f195(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_round_pd(_mm_fmadd_pd(x, y, _mm_set1_pd(1.0)), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f196(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fmadd_pd(x, y, _mm_set1_pd(1.0)), 0x5); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f197(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fmadd_pd(x, y, _mm_set1_pd(1.0)), 0xa); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f198(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fmadd_pd(x, y, _mm_set1_pd(1.0)), 0x3); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f199(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sqrt_pd(_mm_fmadd_pd(x, _mm_set1_pd(1.0), y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f200(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(_mm_fmadd_pd(x, _mm_set1_pd(1.0), y), _mm_set1_pd(-0.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f201(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(_mm_set1_pd(-0.0), _mm_fmadd_pd(x, _mm_set1_pd(1.0), y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f202(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sub_pd(_mm_setzero_pd(), _mm_fmadd_pd(x, _mm_set1_pd(1.0), y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f203(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_mul_pd(_mm_fmadd_pd(x, _mm_set1_pd(1.0), y), _mm_set1_pd(-1.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f204(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_floor_pd(_mm_fmadd_pd(x, _mm_set1_pd(1.0), y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f205(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_ceil_pd(_mm_fmadd_pd(x, _mm_set1_pd(1.0), y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f206(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_round_pd(_mm_fmadd_pd(x, _mm_set1_pd(1.0), y), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f207(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fmadd_pd(x, _mm_set1_pd(1.0), y), 0x5); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f208(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fmadd_pd(x, _mm_set1_pd(1.0), y), 0xa); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f209(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fmadd_pd(x, _mm_set1_pd(1.0), y), 0x3); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f210(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sqrt_pd(_mm_fmadd_pd(_mm_set1_pd(1.0), x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f211(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(_mm_fmadd_pd(_mm_set1_pd(1.0), x, y), _mm_set1_pd(-0.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f212(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(_mm_set1_pd(-0.0), _mm_fmadd_pd(_mm_set1_pd(1.0), x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f213(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sub_pd(_mm_setzero_pd(), _mm_fmadd_pd(_mm_set1_pd(1.0), x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f214(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_mul_pd(_mm_fmadd_pd(_mm_set1_pd(1.0), x, y), _mm_set1_pd(-1.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f215(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_floor_pd(_mm_fmadd_pd(_mm_set1_pd(1.0), x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f216(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_ceil_pd(_mm_fmadd_pd(_mm_set1_pd(1.0), x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f217(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_round_pd(_mm_fmadd_pd(_mm_set1_pd(1.0), x, y), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f218(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fmadd_pd(_mm_set1_pd(1.0), x, y), 0x5); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f219(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fmadd_pd(_mm_set1_pd(1.0), x, y), 0xa); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f220(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fmadd_pd(_mm_set1_pd(1.0), x, y), 0x3); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f221(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sqrt_pd(_mm_fmadd_pd(x, y, _mm_set1_pd(-1.0))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f222(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(_mm_fmadd_pd(x, y, _mm_set1_pd(-1.0)), _mm_set1_pd(-0.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f223(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(_mm_set1_pd(-0.0), _mm_fmadd_pd(x, y, _mm_set1_pd(-1.0))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f224(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sub_pd(_mm_setzero_pd(), _mm_fmadd_pd(x, y, _mm_set1_pd(-1.0))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f225(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_mul_pd(_mm_fmadd_pd(x, y, _mm_set1_pd(-1.0)), _mm_set1_pd(-1.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f226(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_floor_pd(_mm_fmadd_pd(x, y, _mm_set1_pd(-1.0))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f227(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_ceil_pd(_mm_fmadd_pd(x, y, _mm_set1_pd(-1.0))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f228(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_round_pd(_mm_fmadd_pd(x, y, _mm_set1_pd(-1.0)), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f229(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fmadd_pd(x, y, _mm_set1_pd(-1.0)), 0x5); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f230(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fmadd_pd(x, y, _mm_set1_pd(-1.0)), 0xa); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f231(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fmadd_pd(x, y, _mm_set1_pd(-1.0)), 0x3); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f232(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sqrt_pd(_mm_fmadd_pd(x, _mm_set1_pd(-1.0), y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f233(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(_mm_fmadd_pd(x, _mm_set1_pd(-1.0), y), _mm_set1_pd(-0.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f234(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(_mm_set1_pd(-0.0), _mm_fmadd_pd(x, _mm_set1_pd(-1.0), y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f235(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sub_pd(_mm_setzero_pd(), _mm_fmadd_pd(x, _mm_set1_pd(-1.0), y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f236(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_mul_pd(_mm_fmadd_pd(x, _mm_set1_pd(-1.0), y), _mm_set1_pd(-1.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f237(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_floor_pd(_mm_fmadd_pd(x, _mm_set1_pd(-1.0), y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f238(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_ceil_pd(_mm_fmadd_pd(x, _mm_set1_pd(-1.0), y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f239(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_round_pd(_mm_fmadd_pd(x, _mm_set1_pd(-1.0), y), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f240(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fmadd_pd(x, _mm_set1_pd(-1.0), y), 0x5); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f241(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fmadd_pd(x, _mm_set1_pd(-1.0), y), 0xa); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f242(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fmadd_pd(x, _mm_set1_pd(-1.0), y), 0x3); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f243(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sqrt_pd(_mm_fmadd_pd(_mm_set1_pd(-1.0), x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f244(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(_mm_fmadd_pd(_mm_set1_pd(-1.0), x, y), _mm_set1_pd(-0.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f245(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(_mm_set1_pd(-0.0), _mm_fmadd_pd(_mm_set1_pd(-1.0), x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f246(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sub_pd(_mm_setzero_pd(), _mm_fmadd_pd(_mm_set1_pd(-1.0), x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f247(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_mul_pd(_mm_fmadd_pd(_mm_set1_pd(-1.0), x, y), _mm_set1_pd(-1.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f248(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_floor_pd(_mm_fmadd_pd(_mm_set1_pd(-1.0), x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f249(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_ceil_pd(_mm_fmadd_pd(_mm_set1_pd(-1.0), x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f250(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_round_pd(_mm_fmadd_pd(_mm_set1_pd(-1.0), x, y), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f251(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fmadd_pd(_mm_set1_pd(-1.0), x, y), 0x5); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f252(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fmadd_pd(_mm_set1_pd(-1.0), x, y), 0xa); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f253(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fmadd_pd(_mm_set1_pd(-1.0), x, y), 0x3); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f254(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sqrt_pd(_mm_fmadd_pd(x, y, _mm_set1_pd(std::numeric_limits<double>::infinity()))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f255(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(_mm_fmadd_pd(x, y, _mm_set1_pd(std::numeric_limits<double>::infinity())), _mm_set1_pd(-0.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f256(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(_mm_set1_pd(-0.0), _mm_fmadd_pd(x, y, _mm_set1_pd(std::numeric_limits<double>::infinity()))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f257(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sub_pd(_mm_setzero_pd(), _mm_fmadd_pd(x, y, _mm_set1_pd(std::numeric_limits<double>::infinity()))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f258(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_mul_pd(_mm_fmadd_pd(x, y, _mm_set1_pd(std::numeric_limits<double>::infinity())), _mm_set1_pd(-1.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f259(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_floor_pd(_mm_fmadd_pd(x, y, _mm_set1_pd(std::numeric_limits<double>::infinity()))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f260(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_ceil_pd(_mm_fmadd_pd(x, y, _mm_set1_pd(std::numeric_limits<double>::infinity()))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f261(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_round_pd(_mm_fmadd_pd(x, y, _mm_set1_pd(std::numeric_limits<double>::infinity())), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f262(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fmadd_pd(x, y, _mm_set1_pd(std::numeric_limits<double>::infinity())), 0x5); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f263(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fmadd_pd(x, y, _mm_set1_pd(std::numeric_limits<double>::infinity())), 0xa); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f264(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fmadd_pd(x, y, _mm_set1_pd(std::numeric_limits<double>::infinity())), 0x3); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f265(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sqrt_pd(_mm_fmadd_pd(x, _mm_set1_pd(std::numeric_limits<double>::infinity()), y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f266(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(_mm_fmadd_pd(x, _mm_set1_pd(std::numeric_limits<double>::infinity()), y), _mm_set1_pd(-0.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f267(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(_mm_set1_pd(-0.0), _mm_fmadd_pd(x, _mm_set1_pd(std::numeric_limits<double>::infinity()), y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f268(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sub_pd(_mm_setzero_pd(), _mm_fmadd_pd(x, _mm_set1_pd(std::numeric_limits<double>::infinity()), y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f269(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_mul_pd(_mm_fmadd_pd(x, _mm_set1_pd(std::numeric_limits<double>::infinity()), y), _mm_set1_pd(-1.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f270(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_floor_pd(_mm_fmadd_pd(x, _mm_set1_pd(std::numeric_limits<double>::infinity()), y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f271(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_ceil_pd(_mm_fmadd_pd(x, _mm_set1_pd(std::numeric_limits<double>::infinity()), y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f272(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_round_pd(_mm_fmadd_pd(x, _mm_set1_pd(std::numeric_limits<double>::infinity()), y), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f273(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fmadd_pd(x, _mm_set1_pd(std::numeric_limits<double>::infinity()), y), 0x5); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f274(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fmadd_pd(x, _mm_set1_pd(std::numeric_limits<double>::infinity()), y), 0xa); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f275(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fmadd_pd(x, _mm_set1_pd(std::numeric_limits<double>::infinity()), y), 0x3); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f276(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sqrt_pd(_mm_fmadd_pd(_mm_set1_pd(std::numeric_limits<double>::infinity()), x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f277(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(_mm_fmadd_pd(_mm_set1_pd(std::numeric_limits<double>::infinity()), x, y), _mm_set1_pd(-0.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f278(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(_mm_set1_pd(-0.0), _mm_fmadd_pd(_mm_set1_pd(std::numeric_limits<double>::infinity()), x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f279(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sub_pd(_mm_setzero_pd(), _mm_fmadd_pd(_mm_set1_pd(std::numeric_limits<double>::infinity()), x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f280(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_mul_pd(_mm_fmadd_pd(_mm_set1_pd(std::numeric_limits<double>::infinity()), x, y), _mm_set1_pd(-1.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f281(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_floor_pd(_mm_fmadd_pd(_mm_set1_pd(std::numeric_limits<double>::infinity()), x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f282(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_ceil_pd(_mm_fmadd_pd(_mm_set1_pd(std::numeric_limits<double>::infinity()), x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f283(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_round_pd(_mm_fmadd_pd(_mm_set1_pd(std::numeric_limits<double>::infinity()), x, y), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f284(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fmadd_pd(_mm_set1_pd(std::numeric_limits<double>::infinity()), x, y), 0x5); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f285(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fmadd_pd(_mm_set1_pd(std::numeric_limits<double>::infinity()), x, y), 0xa); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f286(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fmadd_pd(_mm_set1_pd(std::numeric_limits<double>::infinity()), x, y), 0x3); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f287(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sqrt_pd(_mm_fmadd_pd(x, y, _mm_set1_pd(std::numeric_limits<double>::quiet_NaN()))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f288(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(_mm_fmadd_pd(x, y, _mm_set1_pd(std::numeric_limits<double>::quiet_NaN())), _mm_set1_pd(-0.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f289(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(_mm_set1_pd(-0.0), _mm_fmadd_pd(x, y, _mm_set1_pd(std::numeric_limits<double>::quiet_NaN()))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f290(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sub_pd(_mm_setzero_pd(), _mm_fmadd_pd(x, y, _mm_set1_pd(std::numeric_limits<double>::quiet_NaN()))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f291(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_mul_pd(_mm_fmadd_pd(x, y, _mm_set1_pd(std::numeric_limits<double>::quiet_NaN())), _mm_set1_pd(-1.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f292(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_floor_pd(_mm_fmadd_pd(x, y, _mm_set1_pd(std::numeric_limits<double>::quiet_NaN()))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f293(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_ceil_pd(_mm_fmadd_pd(x, y, _mm_set1_pd(std::numeric_limits<double>::quiet_NaN()))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f294(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_round_pd(_mm_fmadd_pd(x, y, _mm_set1_pd(std::numeric_limits<double>::quiet_NaN())), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f295(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fmadd_pd(x, y, _mm_set1_pd(std::numeric_limits<double>::quiet_NaN())), 0x5); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f296(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fmadd_pd(x, y, _mm_set1_pd(std::numeric_limits<double>::quiet_NaN())), 0xa); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f297(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fmadd_pd(x, y, _mm_set1_pd(std::numeric_limits<double>::quiet_NaN())), 0x3); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f298(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sqrt_pd(_mm_fmadd_pd(x, _mm_set1_pd(std::numeric_limits<double>::quiet_NaN()), y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f299(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(_mm_fmadd_pd(x, _mm_set1_pd(std::numeric_limits<double>::quiet_NaN()), y), _mm_set1_pd(-0.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f300(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(_mm_set1_pd(-0.0), _mm_fmadd_pd(x, _mm_set1_pd(std::numeric_limits<double>::quiet_NaN()), y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f301(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sub_pd(_mm_setzero_pd(), _mm_fmadd_pd(x, _mm_set1_pd(std::numeric_limits<double>::quiet_NaN()), y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f302(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_mul_pd(_mm_fmadd_pd(x, _mm_set1_pd(std::numeric_limits<double>::quiet_NaN()), y), _mm_set1_pd(-1.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f303(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_floor_pd(_mm_fmadd_pd(x, _mm_set1_pd(std::numeric_limits<double>::quiet_NaN()), y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f304(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_ceil_pd(_mm_fmadd_pd(x, _mm_set1_pd(std::numeric_limits<double>::quiet_NaN()), y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f305(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_round_pd(_mm_fmadd_pd(x, _mm_set1_pd(std::numeric_limits<double>::quiet_NaN()), y), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f306(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fmadd_pd(x, _mm_set1_pd(std::numeric_limits<double>::quiet_NaN()), y), 0x5); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f307(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fmadd_pd(x, _mm_set1_pd(std::numeric_limits<double>::quiet_NaN()), y), 0xa); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f308(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fmadd_pd(x, _mm_set1_pd(std::numeric_limits<double>::quiet_NaN()), y), 0x3); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f309(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sqrt_pd(_mm_fmadd_pd(_mm_set1_pd(std::numeric_limits<double>::quiet_NaN()), x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f310(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(_mm_fmadd_pd(_mm_set1_pd(std::numeric_limits<double>::quiet_NaN()), x, y), _mm_set1_pd(-0.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f311(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(_mm_set1_pd(-0.0), _mm_fmadd_pd(_mm_set1_pd(std::numeric_limits<double>::quiet_NaN()), x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f312(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sub_pd(_mm_setzero_pd(), _mm_fmadd_pd(_mm_set1_pd(std::numeric_limits<double>::quiet_NaN()), x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f313(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_mul_pd(_mm_fmadd_pd(_mm_set1_pd(std::numeric_limits<double>::quiet_NaN()), x, y), _mm_set1_pd(-1.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f314(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_floor_pd(_mm_fmadd_pd(_mm_set1_pd(std::numeric_limits<double>::quiet_NaN()), x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f315(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_ceil_pd(_mm_fmadd_pd(_mm_set1_pd(std::numeric_limits<double>::quiet_NaN()), x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f316(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_round_pd(_mm_fmadd_pd(_mm_set1_pd(std::numeric_limits<double>::quiet_NaN()), x, y), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f317(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fmadd_pd(_mm_set1_pd(std::numeric_limits<double>::quiet_NaN()), x, y), 0x5); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f318(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fmadd_pd(_mm_set1_pd(std::numeric_limits<double>::quiet_NaN()), x, y), 0xa); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f319(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fmadd_pd(_mm_set1_pd(std::numeric_limits<double>::quiet_NaN()), x, y), 0x3); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f320(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sqrt_pd(_mm_fmadd_pd(x, y, x)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f321(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(_mm_fmadd_pd(x, y, x), _mm_set1_pd(-0.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f322(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(_mm_set1_pd(-0.0), _mm_fmadd_pd(x, y, x)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f323(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sub_pd(_mm_setzero_pd(), _mm_fmadd_pd(x, y, x)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f324(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_mul_pd(_mm_fmadd_pd(x, y, x), _mm_set1_pd(-1.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f325(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_floor_pd(_mm_fmadd_pd(x, y, x)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f326(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_ceil_pd(_mm_fmadd_pd(x, y, x)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f327(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_round_pd(_mm_fmadd_pd(x, y, x), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f328(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fmadd_pd(x, y, x), 0x5); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f329(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fmadd_pd(x, y, x), 0xa); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f330(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fmadd_pd(x, y, x), 0x3); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f331(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sqrt_pd(_mm_fmadd_pd(x, x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f332(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(_mm_fmadd_pd(x, x, y), _mm_set1_pd(-0.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f333(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(_mm_set1_pd(-0.0), _mm_fmadd_pd(x, x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f334(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sub_pd(_mm_setzero_pd(), _mm_fmadd_pd(x, x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f335(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_mul_pd(_mm_fmadd_pd(x, x, y), _mm_set1_pd(-1.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f336(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_floor_pd(_mm_fmadd_pd(x, x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f337(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_ceil_pd(_mm_fmadd_pd(x, x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f338(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_round_pd(_mm_fmadd_pd(x, x, y), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f339(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fmadd_pd(x, x, y), 0x5); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f340(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fmadd_pd(x, x, y), 0xa); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f341(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fmadd_pd(x, x, y), 0x3); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f342(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sqrt_pd(_mm_fmadd_pd(x, y, _mm_mul_pd(x, y))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f343(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(_mm_fmadd_pd(x, y, _mm_mul_pd(x, y)), _mm_set1_pd(-0.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f344(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(_mm_set1_pd(-0.0), _mm_fmadd_pd(x, y, _mm_mul_pd(x, y))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f345(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sub_pd(_mm_setzero_pd(), _mm_fmadd_pd(x, y, _mm_mul_pd(x, y))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f346(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_mul_pd(_mm_fmadd_pd(x, y, _mm_mul_pd(x, y)), _mm_set1_pd(-1.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f347(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_floor_pd(_mm_fmadd_pd(x, y, _mm_mul_pd(x, y))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f348(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_ceil_pd(_mm_fmadd_pd(x, y, _mm_mul_pd(x, y))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f349(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_round_pd(_mm_fmadd_pd(x, y, _mm_mul_pd(x, y)), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f350(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fmadd_pd(x, y, _mm_mul_pd(x, y)), 0x5); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f351(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fmadd_pd(x, y, _mm_mul_pd(x, y)), 0xa); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f352(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fmadd_pd(x, y, _mm_mul_pd(x, y)), 0x3); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f353(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sqrt_pd(_mm_fmsub_pd(x, y, _mm_setzero_pd())); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f354(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(_mm_fmsub_pd(x, y, _mm_setzero_pd()), _mm_set1_pd(-0.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f355(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(_mm_set1_pd(-0.0), _mm_fmsub_pd(x, y, _mm_setzero_pd())); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f356(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sub_pd(_mm_setzero_pd(), _mm_fmsub_pd(x, y, _mm_setzero_pd())); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f357(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_mul_pd(_mm_fmsub_pd(x, y, _mm_setzero_pd()), _mm_set1_pd(-1.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f358(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_floor_pd(_mm_fmsub_pd(x, y, _mm_setzero_pd())); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f359(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_ceil_pd(_mm_fmsub_pd(x, y, _mm_setzero_pd())); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f360(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_round_pd(_mm_fmsub_pd(x, y, _mm_setzero_pd()), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f361(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fmsub_pd(x, y, _mm_setzero_pd()), 0x5); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f362(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fmsub_pd(x, y, _mm_setzero_pd()), 0xa); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f363(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fmsub_pd(x, y, _mm_setzero_pd()), 0x3); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f364(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sqrt_pd(_mm_fmsub_pd(x, _mm_setzero_pd(), y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f365(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(_mm_fmsub_pd(x, _mm_setzero_pd(), y), _mm_set1_pd(-0.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f366(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(_mm_set1_pd(-0.0), _mm_fmsub_pd(x, _mm_setzero_pd(), y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f367(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sub_pd(_mm_setzero_pd(), _mm_fmsub_pd(x, _mm_setzero_pd(), y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f368(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_mul_pd(_mm_fmsub_pd(x, _mm_setzero_pd(), y), _mm_set1_pd(-1.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f369(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_floor_pd(_mm_fmsub_pd(x, _mm_setzero_pd(), y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f370(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_ceil_pd(_mm_fmsub_pd(x, _mm_setzero_pd(), y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f371(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_round_pd(_mm_fmsub_pd(x, _mm_setzero_pd(), y), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f372(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fmsub_pd(x, _mm_setzero_pd(), y), 0x5); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f373(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fmsub_pd(x, _mm_setzero_pd(), y), 0xa); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f374(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fmsub_pd(x, _mm_setzero_pd(), y), 0x3); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f375(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sqrt_pd(_mm_fmsub_pd(_mm_setzero_pd(), x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f376(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(_mm_fmsub_pd(_mm_setzero_pd(), x, y), _mm_set1_pd(-0.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f377(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(_mm_set1_pd(-0.0), _mm_fmsub_pd(_mm_setzero_pd(), x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f378(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sub_pd(_mm_setzero_pd(), _mm_fmsub_pd(_mm_setzero_pd(), x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f379(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_mul_pd(_mm_fmsub_pd(_mm_setzero_pd(), x, y), _mm_set1_pd(-1.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f380(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_floor_pd(_mm_fmsub_pd(_mm_setzero_pd(), x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f381(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_ceil_pd(_mm_fmsub_pd(_mm_setzero_pd(), x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f382(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_round_pd(_mm_fmsub_pd(_mm_setzero_pd(), x, y), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f383(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fmsub_pd(_mm_setzero_pd(), x, y), 0x5); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f384(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fmsub_pd(_mm_setzero_pd(), x, y), 0xa); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f385(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fmsub_pd(_mm_setzero_pd(), x, y), 0x3); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f386(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sqrt_pd(_mm_fmsub_pd(x, y, _mm_set1_pd(-0.0))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f387(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(_mm_fmsub_pd(x, y, _mm_set1_pd(-0.0)), _mm_set1_pd(-0.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f388(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(_mm_set1_pd(-0.0), _mm_fmsub_pd(x, y, _mm_set1_pd(-0.0))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f389(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sub_pd(_mm_setzero_pd(), _mm_fmsub_pd(x, y, _mm_set1_pd(-0.0))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f390(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_mul_pd(_mm_fmsub_pd(x, y, _mm_set1_pd(-0.0)), _mm_set1_pd(-1.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f391(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_floor_pd(_mm_fmsub_pd(x, y, _mm_set1_pd(-0.0))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f392(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_ceil_pd(_mm_fmsub_pd(x, y, _mm_set1_pd(-0.0))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f393(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_round_pd(_mm_fmsub_pd(x, y, _mm_set1_pd(-0.0)), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f394(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fmsub_pd(x, y, _mm_set1_pd(-0.0)), 0x5); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f395(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fmsub_pd(x, y, _mm_set1_pd(-0.0)), 0xa); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f396(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fmsub_pd(x, y, _mm_set1_pd(-0.0)), 0x3); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f397(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sqrt_pd(_mm_fmsub_pd(x, _mm_set1_pd(-0.0), y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f398(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(_mm_fmsub_pd(x, _mm_set1_pd(-0.0), y), _mm_set1_pd(-0.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f399(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(_mm_set1_pd(-0.0), _mm_fmsub_pd(x, _mm_set1_pd(-0.0), y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f400(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sub_pd(_mm_setzero_pd(), _mm_fmsub_pd(x, _mm_set1_pd(-0.0), y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f401(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_mul_pd(_mm_fmsub_pd(x, _mm_set1_pd(-0.0), y), _mm_set1_pd(-1.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f402(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_floor_pd(_mm_fmsub_pd(x, _mm_set1_pd(-0.0), y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f403(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_ceil_pd(_mm_fmsub_pd(x, _mm_set1_pd(-0.0), y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f404(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_round_pd(_mm_fmsub_pd(x, _mm_set1_pd(-0.0), y), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f405(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fmsub_pd(x, _mm_set1_pd(-0.0), y), 0x5); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f406(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fmsub_pd(x, _mm_set1_pd(-0.0), y), 0xa); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f407(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fmsub_pd(x, _mm_set1_pd(-0.0), y), 0x3); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f408(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sqrt_pd(_mm_fmsub_pd(_mm_set1_pd(-0.0), x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f409(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(_mm_fmsub_pd(_mm_set1_pd(-0.0), x, y), _mm_set1_pd(-0.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f410(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(_mm_set1_pd(-0.0), _mm_fmsub_pd(_mm_set1_pd(-0.0), x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f411(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sub_pd(_mm_setzero_pd(), _mm_fmsub_pd(_mm_set1_pd(-0.0), x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f412(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_mul_pd(_mm_fmsub_pd(_mm_set1_pd(-0.0), x, y), _mm_set1_pd(-1.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f413(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_floor_pd(_mm_fmsub_pd(_mm_set1_pd(-0.0), x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f414(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_ceil_pd(_mm_fmsub_pd(_mm_set1_pd(-0.0), x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f415(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_round_pd(_mm_fmsub_pd(_mm_set1_pd(-0.0), x, y), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f416(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fmsub_pd(_mm_set1_pd(-0.0), x, y), 0x5); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f417(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fmsub_pd(_mm_set1_pd(-0.0), x, y), 0xa); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f418(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fmsub_pd(_mm_set1_pd(-0.0), x, y), 0x3); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f419(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sqrt_pd(_mm_fmsub_pd(x, y, _mm_set1_pd(1.0))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f420(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(_mm_fmsub_pd(x, y, _mm_set1_pd(1.0)), _mm_set1_pd(-0.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f421(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(_mm_set1_pd(-0.0), _mm_fmsub_pd(x, y, _mm_set1_pd(1.0))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f422(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sub_pd(_mm_setzero_pd(), _mm_fmsub_pd(x, y, _mm_set1_pd(1.0))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f423(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_mul_pd(_mm_fmsub_pd(x, y, _mm_set1_pd(1.0)), _mm_set1_pd(-1.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f424(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_floor_pd(_mm_fmsub_pd(x, y, _mm_set1_pd(1.0))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f425(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_ceil_pd(_mm_fmsub_pd(x, y, _mm_set1_pd(1.0))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f426(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_round_pd(_mm_fmsub_pd(x, y, _mm_set1_pd(1.0)), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f427(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fmsub_pd(x, y, _mm_set1_pd(1.0)), 0x5); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f428(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fmsub_pd(x, y, _mm_set1_pd(1.0)), 0xa); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f429(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fmsub_pd(x, y, _mm_set1_pd(1.0)), 0x3); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f430(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sqrt_pd(_mm_fmsub_pd(x, _mm_set1_pd(1.0), y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f431(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(_mm_fmsub_pd(x, _mm_set1_pd(1.0), y), _mm_set1_pd(-0.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f432(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(_mm_set1_pd(-0.0), _mm_fmsub_pd(x, _mm_set1_pd(1.0), y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f433(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sub_pd(_mm_setzero_pd(), _mm_fmsub_pd(x, _mm_set1_pd(1.0), y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f434(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_mul_pd(_mm_fmsub_pd(x, _mm_set1_pd(1.0), y), _mm_set1_pd(-1.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f435(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_floor_pd(_mm_fmsub_pd(x, _mm_set1_pd(1.0), y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f436(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_ceil_pd(_mm_fmsub_pd(x, _mm_set1_pd(1.0), y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f437(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_round_pd(_mm_fmsub_pd(x, _mm_set1_pd(1.0), y), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f438(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fmsub_pd(x, _mm_set1_pd(1.0), y), 0x5); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f439(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fmsub_pd(x, _mm_set1_pd(1.0), y), 0xa); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f440(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fmsub_pd(x, _mm_set1_pd(1.0), y), 0x3); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f441(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sqrt_pd(_mm_fmsub_pd(_mm_set1_pd(1.0), x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f442(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(_mm_fmsub_pd(_mm_set1_pd(1.0), x, y), _mm_set1_pd(-0.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f443(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(_mm_set1_pd(-0.0), _mm_fmsub_pd(_mm_set1_pd(1.0), x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f444(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sub_pd(_mm_setzero_pd(), _mm_fmsub_pd(_mm_set1_pd(1.0), x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f445(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_mul_pd(_mm_fmsub_pd(_mm_set1_pd(1.0), x, y), _mm_set1_pd(-1.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f446(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_floor_pd(_mm_fmsub_pd(_mm_set1_pd(1.0), x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f447(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_ceil_pd(_mm_fmsub_pd(_mm_set1_pd(1.0), x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f448(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_round_pd(_mm_fmsub_pd(_mm_set1_pd(1.0), x, y), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f449(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fmsub_pd(_mm_set1_pd(1.0), x, y), 0x5); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f450(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fmsub_pd(_mm_set1_pd(1.0), x, y), 0xa); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f451(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fmsub_pd(_mm_set1_pd(1.0), x, y), 0x3); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f452(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sqrt_pd(_mm_fmsub_pd(x, y, _mm_set1_pd(-1.0))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f453(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(_mm_fmsub_pd(x, y, _mm_set1_pd(-1.0)), _mm_set1_pd(-0.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f454(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(_mm_set1_pd(-0.0), _mm_fmsub_pd(x, y, _mm_set1_pd(-1.0))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f455(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sub_pd(_mm_setzero_pd(), _mm_fmsub_pd(x, y, _mm_set1_pd(-1.0))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f456(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_mul_pd(_mm_fmsub_pd(x, y, _mm_set1_pd(-1.0)), _mm_set1_pd(-1.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f457(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_floor_pd(_mm_fmsub_pd(x, y, _mm_set1_pd(-1.0))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f458(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_ceil_pd(_mm_fmsub_pd(x, y, _mm_set1_pd(-1.0))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f459(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_round_pd(_mm_fmsub_pd(x, y, _mm_set1_pd(-1.0)), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f460(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fmsub_pd(x, y, _mm_set1_pd(-1.0)), 0x5); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f461(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fmsub_pd(x, y, _mm_set1_pd(-1.0)), 0xa); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f462(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fmsub_pd(x, y, _mm_set1_pd(-1.0)), 0x3); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f463(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sqrt_pd(_mm_fmsub_pd(x, _mm_set1_pd(-1.0), y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f464(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(_mm_fmsub_pd(x, _mm_set1_pd(-1.0), y), _mm_set1_pd(-0.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f465(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(_mm_set1_pd(-0.0), _mm_fmsub_pd(x, _mm_set1_pd(-1.0), y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f466(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sub_pd(_mm_setzero_pd(), _mm_fmsub_pd(x, _mm_set1_pd(-1.0), y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f467(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_mul_pd(_mm_fmsub_pd(x, _mm_set1_pd(-1.0), y), _mm_set1_pd(-1.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f468(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_floor_pd(_mm_fmsub_pd(x, _mm_set1_pd(-1.0), y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f469(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_ceil_pd(_mm_fmsub_pd(x, _mm_set1_pd(-1.0), y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f470(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_round_pd(_mm_fmsub_pd(x, _mm_set1_pd(-1.0), y), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f471(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fmsub_pd(x, _mm_set1_pd(-1.0), y), 0x5); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f472(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fmsub_pd(x, _mm_set1_pd(-1.0), y), 0xa); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f473(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fmsub_pd(x, _mm_set1_pd(-1.0), y), 0x3); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f474(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sqrt_pd(_mm_fmsub_pd(_mm_set1_pd(-1.0), x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f475(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(_mm_fmsub_pd(_mm_set1_pd(-1.0), x, y), _mm_set1_pd(-0.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f476(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(_mm_set1_pd(-0.0), _mm_fmsub_pd(_mm_set1_pd(-1.0), x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f477(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sub_pd(_mm_setzero_pd(), _mm_fmsub_pd(_mm_set1_pd(-1.0), x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f478(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_mul_pd(_mm_fmsub_pd(_mm_set1_pd(-1.0), x, y), _mm_set1_pd(-1.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f479(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_floor_pd(_mm_fmsub_pd(_mm_set1_pd(-1.0), x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f480(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_ceil_pd(_mm_fmsub_pd(_mm_set1_pd(-1.0), x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f481(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_round_pd(_mm_fmsub_pd(_mm_set1_pd(-1.0), x, y), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f482(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fmsub_pd(_mm_set1_pd(-1.0), x, y), 0x5); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f483(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fmsub_pd(_mm_set1_pd(-1.0), x, y), 0xa); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f484(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fmsub_pd(_mm_set1_pd(-1.0), x, y), 0x3); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f485(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sqrt_pd(_mm_fmsub_pd(x, y, _mm_set1_pd(std::numeric_limits<double>::infinity()))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f486(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(_mm_fmsub_pd(x, y, _mm_set1_pd(std::numeric_limits<double>::infinity())), _mm_set1_pd(-0.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f487(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(_mm_set1_pd(-0.0), _mm_fmsub_pd(x, y, _mm_set1_pd(std::numeric_limits<double>::infinity()))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f488(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sub_pd(_mm_setzero_pd(), _mm_fmsub_pd(x, y, _mm_set1_pd(std::numeric_limits<double>::infinity()))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f489(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_mul_pd(_mm_fmsub_pd(x, y, _mm_set1_pd(std::numeric_limits<double>::infinity())), _mm_set1_pd(-1.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f490(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_floor_pd(_mm_fmsub_pd(x, y, _mm_set1_pd(std::numeric_limits<double>::infinity()))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f491(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_ceil_pd(_mm_fmsub_pd(x, y, _mm_set1_pd(std::numeric_limits<double>::infinity()))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f492(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_round_pd(_mm_fmsub_pd(x, y, _mm_set1_pd(std::numeric_limits<double>::infinity())), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f493(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fmsub_pd(x, y, _mm_set1_pd(std::numeric_limits<double>::infinity())), 0x5); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f494(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fmsub_pd(x, y, _mm_set1_pd(std::numeric_limits<double>::infinity())), 0xa); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f495(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fmsub_pd(x, y, _mm_set1_pd(std::numeric_limits<double>::infinity())), 0x3); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f496(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sqrt_pd(_mm_fmsub_pd(x, _mm_set1_pd(std::numeric_limits<double>::infinity()), y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f497(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(_mm_fmsub_pd(x, _mm_set1_pd(std::numeric_limits<double>::infinity()), y), _mm_set1_pd(-0.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f498(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(_mm_set1_pd(-0.0), _mm_fmsub_pd(x, _mm_set1_pd(std::numeric_limits<double>::infinity()), y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f499(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sub_pd(_mm_setzero_pd(), _mm_fmsub_pd(x, _mm_set1_pd(std::numeric_limits<double>::infinity()), y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f500(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_mul_pd(_mm_fmsub_pd(x, _mm_set1_pd(std::numeric_limits<double>::infinity()), y), _mm_set1_pd(-1.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f501(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_floor_pd(_mm_fmsub_pd(x, _mm_set1_pd(std::numeric_limits<double>::infinity()), y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f502(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_ceil_pd(_mm_fmsub_pd(x, _mm_set1_pd(std::numeric_limits<double>::infinity()), y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f503(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_round_pd(_mm_fmsub_pd(x, _mm_set1_pd(std::numeric_limits<double>::infinity()), y), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f504(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fmsub_pd(x, _mm_set1_pd(std::numeric_limits<double>::infinity()), y), 0x5); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f505(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fmsub_pd(x, _mm_set1_pd(std::numeric_limits<double>::infinity()), y), 0xa); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f506(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fmsub_pd(x, _mm_set1_pd(std::numeric_limits<double>::infinity()), y), 0x3); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f507(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sqrt_pd(_mm_fmsub_pd(_mm_set1_pd(std::numeric_limits<double>::infinity()), x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f508(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(_mm_fmsub_pd(_mm_set1_pd(std::numeric_limits<double>::infinity()), x, y), _mm_set1_pd(-0.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f509(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(_mm_set1_pd(-0.0), _mm_fmsub_pd(_mm_set1_pd(std::numeric_limits<double>::infinity()), x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f510(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sub_pd(_mm_setzero_pd(), _mm_fmsub_pd(_mm_set1_pd(std::numeric_limits<double>::infinity()), x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f511(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_mul_pd(_mm_fmsub_pd(_mm_set1_pd(std::numeric_limits<double>::infinity()), x, y), _mm_set1_pd(-1.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f512(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_floor_pd(_mm_fmsub_pd(_mm_set1_pd(std::numeric_limits<double>::infinity()), x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f513(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_ceil_pd(_mm_fmsub_pd(_mm_set1_pd(std::numeric_limits<double>::infinity()), x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f514(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_round_pd(_mm_fmsub_pd(_mm_set1_pd(std::numeric_limits<double>::infinity()), x, y), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f515(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fmsub_pd(_mm_set1_pd(std::numeric_limits<double>::infinity()), x, y), 0x5); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f516(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fmsub_pd(_mm_set1_pd(std::numeric_limits<double>::infinity()), x, y), 0xa); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f517(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fmsub_pd(_mm_set1_pd(std::numeric_limits<double>::infinity()), x, y), 0x3); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f518(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sqrt_pd(_mm_fmsub_pd(x, y, _mm_set1_pd(std::numeric_limits<double>::quiet_NaN()))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f519(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(_mm_fmsub_pd(x, y, _mm_set1_pd(std::numeric_limits<double>::quiet_NaN())), _mm_set1_pd(-0.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f520(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(_mm_set1_pd(-0.0), _mm_fmsub_pd(x, y, _mm_set1_pd(std::numeric_limits<double>::quiet_NaN()))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f521(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sub_pd(_mm_setzero_pd(), _mm_fmsub_pd(x, y, _mm_set1_pd(std::numeric_limits<double>::quiet_NaN()))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f522(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_mul_pd(_mm_fmsub_pd(x, y, _mm_set1_pd(std::numeric_limits<double>::quiet_NaN())), _mm_set1_pd(-1.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f523(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_floor_pd(_mm_fmsub_pd(x, y, _mm_set1_pd(std::numeric_limits<double>::quiet_NaN()))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f524(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_ceil_pd(_mm_fmsub_pd(x, y, _mm_set1_pd(std::numeric_limits<double>::quiet_NaN()))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f525(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_round_pd(_mm_fmsub_pd(x, y, _mm_set1_pd(std::numeric_limits<double>::quiet_NaN())), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f526(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fmsub_pd(x, y, _mm_set1_pd(std::numeric_limits<double>::quiet_NaN())), 0x5); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f527(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fmsub_pd(x, y, _mm_set1_pd(std::numeric_limits<double>::quiet_NaN())), 0xa); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f528(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fmsub_pd(x, y, _mm_set1_pd(std::numeric_limits<double>::quiet_NaN())), 0x3); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f529(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sqrt_pd(_mm_fmsub_pd(x, _mm_set1_pd(std::numeric_limits<double>::quiet_NaN()), y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f530(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(_mm_fmsub_pd(x, _mm_set1_pd(std::numeric_limits<double>::quiet_NaN()), y), _mm_set1_pd(-0.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f531(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(_mm_set1_pd(-0.0), _mm_fmsub_pd(x, _mm_set1_pd(std::numeric_limits<double>::quiet_NaN()), y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f532(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sub_pd(_mm_setzero_pd(), _mm_fmsub_pd(x, _mm_set1_pd(std::numeric_limits<double>::quiet_NaN()), y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f533(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_mul_pd(_mm_fmsub_pd(x, _mm_set1_pd(std::numeric_limits<double>::quiet_NaN()), y), _mm_set1_pd(-1.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f534(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_floor_pd(_mm_fmsub_pd(x, _mm_set1_pd(std::numeric_limits<double>::quiet_NaN()), y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f535(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_ceil_pd(_mm_fmsub_pd(x, _mm_set1_pd(std::numeric_limits<double>::quiet_NaN()), y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f536(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_round_pd(_mm_fmsub_pd(x, _mm_set1_pd(std::numeric_limits<double>::quiet_NaN()), y), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f537(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fmsub_pd(x, _mm_set1_pd(std::numeric_limits<double>::quiet_NaN()), y), 0x5); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f538(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fmsub_pd(x, _mm_set1_pd(std::numeric_limits<double>::quiet_NaN()), y), 0xa); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f539(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fmsub_pd(x, _mm_set1_pd(std::numeric_limits<double>::quiet_NaN()), y), 0x3); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f540(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sqrt_pd(_mm_fmsub_pd(_mm_set1_pd(std::numeric_limits<double>::quiet_NaN()), x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f541(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(_mm_fmsub_pd(_mm_set1_pd(std::numeric_limits<double>::quiet_NaN()), x, y), _mm_set1_pd(-0.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f542(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(_mm_set1_pd(-0.0), _mm_fmsub_pd(_mm_set1_pd(std::numeric_limits<double>::quiet_NaN()), x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f543(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sub_pd(_mm_setzero_pd(), _mm_fmsub_pd(_mm_set1_pd(std::numeric_limits<double>::quiet_NaN()), x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f544(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_mul_pd(_mm_fmsub_pd(_mm_set1_pd(std::numeric_limits<double>::quiet_NaN()), x, y), _mm_set1_pd(-1.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f545(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_floor_pd(_mm_fmsub_pd(_mm_set1_pd(std::numeric_limits<double>::quiet_NaN()), x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f546(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_ceil_pd(_mm_fmsub_pd(_mm_set1_pd(std::numeric_limits<double>::quiet_NaN()), x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f547(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_round_pd(_mm_fmsub_pd(_mm_set1_pd(std::numeric_limits<double>::quiet_NaN()), x, y), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f548(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fmsub_pd(_mm_set1_pd(std::numeric_limits<double>::quiet_NaN()), x, y), 0x5); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f549(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fmsub_pd(_mm_set1_pd(std::numeric_limits<double>::quiet_NaN()), x, y), 0xa); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f550(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fmsub_pd(_mm_set1_pd(std::numeric_limits<double>::quiet_NaN()), x, y), 0x3); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f551(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sqrt_pd(_mm_fmsub_pd(x, y, x)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f552(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(_mm_fmsub_pd(x, y, x), _mm_set1_pd(-0.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f553(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(_mm_set1_pd(-0.0), _mm_fmsub_pd(x, y, x)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f554(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sub_pd(_mm_setzero_pd(), _mm_fmsub_pd(x, y, x)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f555(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_mul_pd(_mm_fmsub_pd(x, y, x), _mm_set1_pd(-1.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f556(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_floor_pd(_mm_fmsub_pd(x, y, x)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f557(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_ceil_pd(_mm_fmsub_pd(x, y, x)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f558(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_round_pd(_mm_fmsub_pd(x, y, x), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f559(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fmsub_pd(x, y, x), 0x5); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f560(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fmsub_pd(x, y, x), 0xa); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f561(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fmsub_pd(x, y, x), 0x3); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f562(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sqrt_pd(_mm_fmsub_pd(x, x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f563(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(_mm_fmsub_pd(x, x, y), _mm_set1_pd(-0.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f564(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(_mm_set1_pd(-0.0), _mm_fmsub_pd(x, x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f565(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sub_pd(_mm_setzero_pd(), _mm_fmsub_pd(x, x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f566(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_mul_pd(_mm_fmsub_pd(x, x, y), _mm_set1_pd(-1.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f567(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_floor_pd(_mm_fmsub_pd(x, x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f568(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_ceil_pd(_mm_fmsub_pd(x, x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f569(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_round_pd(_mm_fmsub_pd(x, x, y), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f570(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fmsub_pd(x, x, y), 0x5); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f571(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fmsub_pd(x, x, y), 0xa); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f572(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fmsub_pd(x, x, y), 0x3); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f573(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sqrt_pd(_mm_fmsub_pd(x, y, _mm_mul_pd(x, y))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f574(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(_mm_fmsub_pd(x, y, _mm_mul_pd(x, y)), _mm_set1_pd(-0.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f575(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(_mm_set1_pd(-0.0), _mm_fmsub_pd(x, y, _mm_mul_pd(x, y))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f576(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sub_pd(_mm_setzero_pd(), _mm_fmsub_pd(x, y, _mm_mul_pd(x, y))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f577(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_mul_pd(_mm_fmsub_pd(x, y, _mm_mul_pd(x, y)), _mm_set1_pd(-1.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f578(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_floor_pd(_mm_fmsub_pd(x, y, _mm_mul_pd(x, y))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f579(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_ceil_pd(_mm_fmsub_pd(x, y, _mm_mul_pd(x, y))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f580(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_round_pd(_mm_fmsub_pd(x, y, _mm_mul_pd(x, y)), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f581(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fmsub_pd(x, y, _mm_mul_pd(x, y)), 0x5); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f582(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fmsub_pd(x, y, _mm_mul_pd(x, y)), 0xa); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f583(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fmsub_pd(x, y, _mm_mul_pd(x, y)), 0x3); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f584(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sqrt_pd(_mm_fnmadd_pd(x, y, _mm_setzero_pd())); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f585(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(_mm_fnmadd_pd(x, y, _mm_setzero_pd()), _mm_set1_pd(-0.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f586(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(_mm_set1_pd(-0.0), _mm_fnmadd_pd(x, y, _mm_setzero_pd())); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f587(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sub_pd(_mm_setzero_pd(), _mm_fnmadd_pd(x, y, _mm_setzero_pd())); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f588(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_mul_pd(_mm_fnmadd_pd(x, y, _mm_setzero_pd()), _mm_set1_pd(-1.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f589(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_floor_pd(_mm_fnmadd_pd(x, y, _mm_setzero_pd())); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f590(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_ceil_pd(_mm_fnmadd_pd(x, y, _mm_setzero_pd())); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f591(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_round_pd(_mm_fnmadd_pd(x, y, _mm_setzero_pd()), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f592(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fnmadd_pd(x, y, _mm_setzero_pd()), 0x5); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f593(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fnmadd_pd(x, y, _mm_setzero_pd()), 0xa); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f594(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fnmadd_pd(x, y, _mm_setzero_pd()), 0x3); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f595(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sqrt_pd(_mm_fnmadd_pd(x, _mm_setzero_pd(), y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f596(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(_mm_fnmadd_pd(x, _mm_setzero_pd(), y), _mm_set1_pd(-0.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f597(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(_mm_set1_pd(-0.0), _mm_fnmadd_pd(x, _mm_setzero_pd(), y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f598(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sub_pd(_mm_setzero_pd(), _mm_fnmadd_pd(x, _mm_setzero_pd(), y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f599(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_mul_pd(_mm_fnmadd_pd(x, _mm_setzero_pd(), y), _mm_set1_pd(-1.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f600(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_floor_pd(_mm_fnmadd_pd(x, _mm_setzero_pd(), y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f601(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_ceil_pd(_mm_fnmadd_pd(x, _mm_setzero_pd(), y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f602(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_round_pd(_mm_fnmadd_pd(x, _mm_setzero_pd(), y), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f603(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fnmadd_pd(x, _mm_setzero_pd(), y), 0x5); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f604(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fnmadd_pd(x, _mm_setzero_pd(), y), 0xa); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f605(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fnmadd_pd(x, _mm_setzero_pd(), y), 0x3); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f606(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sqrt_pd(_mm_fnmadd_pd(_mm_setzero_pd(), x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f607(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(_mm_fnmadd_pd(_mm_setzero_pd(), x, y), _mm_set1_pd(-0.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f608(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(_mm_set1_pd(-0.0), _mm_fnmadd_pd(_mm_setzero_pd(), x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f609(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sub_pd(_mm_setzero_pd(), _mm_fnmadd_pd(_mm_setzero_pd(), x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f610(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_mul_pd(_mm_fnmadd_pd(_mm_setzero_pd(), x, y), _mm_set1_pd(-1.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f611(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_floor_pd(_mm_fnmadd_pd(_mm_setzero_pd(), x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f612(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_ceil_pd(_mm_fnmadd_pd(_mm_setzero_pd(), x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f613(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_round_pd(_mm_fnmadd_pd(_mm_setzero_pd(), x, y), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f614(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fnmadd_pd(_mm_setzero_pd(), x, y), 0x5); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f615(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fnmadd_pd(_mm_setzero_pd(), x, y), 0xa); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f616(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fnmadd_pd(_mm_setzero_pd(), x, y), 0x3); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f617(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sqrt_pd(_mm_fnmadd_pd(x, y, _mm_set1_pd(-0.0))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f618(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(_mm_fnmadd_pd(x, y, _mm_set1_pd(-0.0)), _mm_set1_pd(-0.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f619(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(_mm_set1_pd(-0.0), _mm_fnmadd_pd(x, y, _mm_set1_pd(-0.0))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f620(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sub_pd(_mm_setzero_pd(), _mm_fnmadd_pd(x, y, _mm_set1_pd(-0.0))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f621(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_mul_pd(_mm_fnmadd_pd(x, y, _mm_set1_pd(-0.0)), _mm_set1_pd(-1.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f622(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_floor_pd(_mm_fnmadd_pd(x, y, _mm_set1_pd(-0.0))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f623(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_ceil_pd(_mm_fnmadd_pd(x, y, _mm_set1_pd(-0.0))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f624(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_round_pd(_mm_fnmadd_pd(x, y, _mm_set1_pd(-0.0)), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f625(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fnmadd_pd(x, y, _mm_set1_pd(-0.0)), 0x5); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f626(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fnmadd_pd(x, y, _mm_set1_pd(-0.0)), 0xa); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f627(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fnmadd_pd(x, y, _mm_set1_pd(-0.0)), 0x3); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f628(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sqrt_pd(_mm_fnmadd_pd(x, _mm_set1_pd(-0.0), y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f629(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(_mm_fnmadd_pd(x, _mm_set1_pd(-0.0), y), _mm_set1_pd(-0.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f630(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(_mm_set1_pd(-0.0), _mm_fnmadd_pd(x, _mm_set1_pd(-0.0), y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f631(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sub_pd(_mm_setzero_pd(), _mm_fnmadd_pd(x, _mm_set1_pd(-0.0), y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f632(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_mul_pd(_mm_fnmadd_pd(x, _mm_set1_pd(-0.0), y), _mm_set1_pd(-1.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f633(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_floor_pd(_mm_fnmadd_pd(x, _mm_set1_pd(-0.0), y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f634(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_ceil_pd(_mm_fnmadd_pd(x, _mm_set1_pd(-0.0), y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f635(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_round_pd(_mm_fnmadd_pd(x, _mm_set1_pd(-0.0), y), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f636(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fnmadd_pd(x, _mm_set1_pd(-0.0), y), 0x5); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f637(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fnmadd_pd(x, _mm_set1_pd(-0.0), y), 0xa); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f638(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fnmadd_pd(x, _mm_set1_pd(-0.0), y), 0x3); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f639(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sqrt_pd(_mm_fnmadd_pd(_mm_set1_pd(-0.0), x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f640(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(_mm_fnmadd_pd(_mm_set1_pd(-0.0), x, y), _mm_set1_pd(-0.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f641(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(_mm_set1_pd(-0.0), _mm_fnmadd_pd(_mm_set1_pd(-0.0), x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f642(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sub_pd(_mm_setzero_pd(), _mm_fnmadd_pd(_mm_set1_pd(-0.0), x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f643(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_mul_pd(_mm_fnmadd_pd(_mm_set1_pd(-0.0), x, y), _mm_set1_pd(-1.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f644(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_floor_pd(_mm_fnmadd_pd(_mm_set1_pd(-0.0), x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f645(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_ceil_pd(_mm_fnmadd_pd(_mm_set1_pd(-0.0), x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f646(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_round_pd(_mm_fnmadd_pd(_mm_set1_pd(-0.0), x, y), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f647(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fnmadd_pd(_mm_set1_pd(-0.0), x, y), 0x5); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f648(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fnmadd_pd(_mm_set1_pd(-0.0), x, y), 0xa); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f649(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fnmadd_pd(_mm_set1_pd(-0.0), x, y), 0x3); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f650(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sqrt_pd(_mm_fnmadd_pd(x, y, _mm_set1_pd(1.0))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f651(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(_mm_fnmadd_pd(x, y, _mm_set1_pd(1.0)), _mm_set1_pd(-0.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f652(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(_mm_set1_pd(-0.0), _mm_fnmadd_pd(x, y, _mm_set1_pd(1.0))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f653(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sub_pd(_mm_setzero_pd(), _mm_fnmadd_pd(x, y, _mm_set1_pd(1.0))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f654(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_mul_pd(_mm_fnmadd_pd(x, y, _mm_set1_pd(1.0)), _mm_set1_pd(-1.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f655(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_floor_pd(_mm_fnmadd_pd(x, y, _mm_set1_pd(1.0))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f656(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_ceil_pd(_mm_fnmadd_pd(x, y, _mm_set1_pd(1.0))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f657(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_round_pd(_mm_fnmadd_pd(x, y, _mm_set1_pd(1.0)), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f658(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fnmadd_pd(x, y, _mm_set1_pd(1.0)), 0x5); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f659(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fnmadd_pd(x, y, _mm_set1_pd(1.0)), 0xa); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f660(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fnmadd_pd(x, y, _mm_set1_pd(1.0)), 0x3); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f661(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sqrt_pd(_mm_fnmadd_pd(x, _mm_set1_pd(1.0), y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f662(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(_mm_fnmadd_pd(x, _mm_set1_pd(1.0), y), _mm_set1_pd(-0.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f663(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(_mm_set1_pd(-0.0), _mm_fnmadd_pd(x, _mm_set1_pd(1.0), y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f664(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sub_pd(_mm_setzero_pd(), _mm_fnmadd_pd(x, _mm_set1_pd(1.0), y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f665(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_mul_pd(_mm_fnmadd_pd(x, _mm_set1_pd(1.0), y), _mm_set1_pd(-1.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f666(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_floor_pd(_mm_fnmadd_pd(x, _mm_set1_pd(1.0), y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f667(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_ceil_pd(_mm_fnmadd_pd(x, _mm_set1_pd(1.0), y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f668(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_round_pd(_mm_fnmadd_pd(x, _mm_set1_pd(1.0), y), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f669(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fnmadd_pd(x, _mm_set1_pd(1.0), y), 0x5); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f670(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fnmadd_pd(x, _mm_set1_pd(1.0), y), 0xa); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f671(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fnmadd_pd(x, _mm_set1_pd(1.0), y), 0x3); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f672(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sqrt_pd(_mm_fnmadd_pd(_mm_set1_pd(1.0), x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f673(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(_mm_fnmadd_pd(_mm_set1_pd(1.0), x, y), _mm_set1_pd(-0.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f674(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(_mm_set1_pd(-0.0), _mm_fnmadd_pd(_mm_set1_pd(1.0), x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f675(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sub_pd(_mm_setzero_pd(), _mm_fnmadd_pd(_mm_set1_pd(1.0), x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f676(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_mul_pd(_mm_fnmadd_pd(_mm_set1_pd(1.0), x, y), _mm_set1_pd(-1.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f677(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_floor_pd(_mm_fnmadd_pd(_mm_set1_pd(1.0), x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f678(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_ceil_pd(_mm_fnmadd_pd(_mm_set1_pd(1.0), x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f679(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_round_pd(_mm_fnmadd_pd(_mm_set1_pd(1.0), x, y), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f680(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fnmadd_pd(_mm_set1_pd(1.0), x, y), 0x5); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f681(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fnmadd_pd(_mm_set1_pd(1.0), x, y), 0xa); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f682(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fnmadd_pd(_mm_set1_pd(1.0), x, y), 0x3); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f683(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sqrt_pd(_mm_fnmadd_pd(x, y, _mm_set1_pd(-1.0))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f684(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(_mm_fnmadd_pd(x, y, _mm_set1_pd(-1.0)), _mm_set1_pd(-0.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f685(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(_mm_set1_pd(-0.0), _mm_fnmadd_pd(x, y, _mm_set1_pd(-1.0))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f686(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sub_pd(_mm_setzero_pd(), _mm_fnmadd_pd(x, y, _mm_set1_pd(-1.0))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f687(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_mul_pd(_mm_fnmadd_pd(x, y, _mm_set1_pd(-1.0)), _mm_set1_pd(-1.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f688(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_floor_pd(_mm_fnmadd_pd(x, y, _mm_set1_pd(-1.0))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f689(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_ceil_pd(_mm_fnmadd_pd(x, y, _mm_set1_pd(-1.0))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f690(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_round_pd(_mm_fnmadd_pd(x, y, _mm_set1_pd(-1.0)), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f691(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fnmadd_pd(x, y, _mm_set1_pd(-1.0)), 0x5); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f692(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fnmadd_pd(x, y, _mm_set1_pd(-1.0)), 0xa); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f693(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fnmadd_pd(x, y, _mm_set1_pd(-1.0)), 0x3); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f694(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sqrt_pd(_mm_fnmadd_pd(x, _mm_set1_pd(-1.0), y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f695(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(_mm_fnmadd_pd(x, _mm_set1_pd(-1.0), y), _mm_set1_pd(-0.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f696(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(_mm_set1_pd(-0.0), _mm_fnmadd_pd(x, _mm_set1_pd(-1.0), y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f697(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sub_pd(_mm_setzero_pd(), _mm_fnmadd_pd(x, _mm_set1_pd(-1.0), y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f698(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_mul_pd(_mm_fnmadd_pd(x, _mm_set1_pd(-1.0), y), _mm_set1_pd(-1.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f699(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_floor_pd(_mm_fnmadd_pd(x, _mm_set1_pd(-1.0), y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f700(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_ceil_pd(_mm_fnmadd_pd(x, _mm_set1_pd(-1.0), y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f701(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_round_pd(_mm_fnmadd_pd(x, _mm_set1_pd(-1.0), y), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f702(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fnmadd_pd(x, _mm_set1_pd(-1.0), y), 0x5); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f703(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fnmadd_pd(x, _mm_set1_pd(-1.0), y), 0xa); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f704(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fnmadd_pd(x, _mm_set1_pd(-1.0), y), 0x3); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f705(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sqrt_pd(_mm_fnmadd_pd(_mm_set1_pd(-1.0), x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f706(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(_mm_fnmadd_pd(_mm_set1_pd(-1.0), x, y), _mm_set1_pd(-0.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f707(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(_mm_set1_pd(-0.0), _mm_fnmadd_pd(_mm_set1_pd(-1.0), x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f708(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sub_pd(_mm_setzero_pd(), _mm_fnmadd_pd(_mm_set1_pd(-1.0), x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f709(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_mul_pd(_mm_fnmadd_pd(_mm_set1_pd(-1.0), x, y), _mm_set1_pd(-1.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f710(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_floor_pd(_mm_fnmadd_pd(_mm_set1_pd(-1.0), x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f711(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_ceil_pd(_mm_fnmadd_pd(_mm_set1_pd(-1.0), x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f712(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_round_pd(_mm_fnmadd_pd(_mm_set1_pd(-1.0), x, y), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f713(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fnmadd_pd(_mm_set1_pd(-1.0), x, y), 0x5); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f714(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fnmadd_pd(_mm_set1_pd(-1.0), x, y), 0xa); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f715(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fnmadd_pd(_mm_set1_pd(-1.0), x, y), 0x3); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f716(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sqrt_pd(_mm_fnmadd_pd(x, y, _mm_set1_pd(std::numeric_limits<double>::infinity()))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f717(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(_mm_fnmadd_pd(x, y, _mm_set1_pd(std::numeric_limits<double>::infinity())), _mm_set1_pd(-0.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f718(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(_mm_set1_pd(-0.0), _mm_fnmadd_pd(x, y, _mm_set1_pd(std::numeric_limits<double>::infinity()))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f719(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sub_pd(_mm_setzero_pd(), _mm_fnmadd_pd(x, y, _mm_set1_pd(std::numeric_limits<double>::infinity()))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f720(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_mul_pd(_mm_fnmadd_pd(x, y, _mm_set1_pd(std::numeric_limits<double>::infinity())), _mm_set1_pd(-1.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f721(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_floor_pd(_mm_fnmadd_pd(x, y, _mm_set1_pd(std::numeric_limits<double>::infinity()))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f722(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_ceil_pd(_mm_fnmadd_pd(x, y, _mm_set1_pd(std::numeric_limits<double>::infinity()))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f723(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_round_pd(_mm_fnmadd_pd(x, y, _mm_set1_pd(std::numeric_limits<double>::infinity())), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f724(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fnmadd_pd(x, y, _mm_set1_pd(std::numeric_limits<double>::infinity())), 0x5); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f725(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fnmadd_pd(x, y, _mm_set1_pd(std::numeric_limits<double>::infinity())), 0xa); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f726(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fnmadd_pd(x, y, _mm_set1_pd(std::numeric_limits<double>::infinity())), 0x3); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f727(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sqrt_pd(_mm_fnmadd_pd(x, _mm_set1_pd(std::numeric_limits<double>::infinity()), y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f728(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(_mm_fnmadd_pd(x, _mm_set1_pd(std::numeric_limits<double>::infinity()), y), _mm_set1_pd(-0.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f729(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(_mm_set1_pd(-0.0), _mm_fnmadd_pd(x, _mm_set1_pd(std::numeric_limits<double>::infinity()), y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f730(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sub_pd(_mm_setzero_pd(), _mm_fnmadd_pd(x, _mm_set1_pd(std::numeric_limits<double>::infinity()), y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f731(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_mul_pd(_mm_fnmadd_pd(x, _mm_set1_pd(std::numeric_limits<double>::infinity()), y), _mm_set1_pd(-1.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f732(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_floor_pd(_mm_fnmadd_pd(x, _mm_set1_pd(std::numeric_limits<double>::infinity()), y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f733(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_ceil_pd(_mm_fnmadd_pd(x, _mm_set1_pd(std::numeric_limits<double>::infinity()), y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f734(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_round_pd(_mm_fnmadd_pd(x, _mm_set1_pd(std::numeric_limits<double>::infinity()), y), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f735(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fnmadd_pd(x, _mm_set1_pd(std::numeric_limits<double>::infinity()), y), 0x5); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f736(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fnmadd_pd(x, _mm_set1_pd(std::numeric_limits<double>::infinity()), y), 0xa); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f737(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fnmadd_pd(x, _mm_set1_pd(std::numeric_limits<double>::infinity()), y), 0x3); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f738(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sqrt_pd(_mm_fnmadd_pd(_mm_set1_pd(std::numeric_limits<double>::infinity()), x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f739(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(_mm_fnmadd_pd(_mm_set1_pd(std::numeric_limits<double>::infinity()), x, y), _mm_set1_pd(-0.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f740(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(_mm_set1_pd(-0.0), _mm_fnmadd_pd(_mm_set1_pd(std::numeric_limits<double>::infinity()), x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f741(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sub_pd(_mm_setzero_pd(), _mm_fnmadd_pd(_mm_set1_pd(std::numeric_limits<double>::infinity()), x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f742(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_mul_pd(_mm_fnmadd_pd(_mm_set1_pd(std::numeric_limits<double>::infinity()), x, y), _mm_set1_pd(-1.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f743(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_floor_pd(_mm_fnmadd_pd(_mm_set1_pd(std::numeric_limits<double>::infinity()), x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f744(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_ceil_pd(_mm_fnmadd_pd(_mm_set1_pd(std::numeric_limits<double>::infinity()), x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f745(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_round_pd(_mm_fnmadd_pd(_mm_set1_pd(std::numeric_limits<double>::infinity()), x, y), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f746(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fnmadd_pd(_mm_set1_pd(std::numeric_limits<double>::infinity()), x, y), 0x5); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f747(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fnmadd_pd(_mm_set1_pd(std::numeric_limits<double>::infinity()), x, y), 0xa); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f748(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fnmadd_pd(_mm_set1_pd(std::numeric_limits<double>::infinity()), x, y), 0x3); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f749(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sqrt_pd(_mm_fnmadd_pd(x, y, _mm_set1_pd(std::numeric_limits<double>::quiet_NaN()))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f750(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(_mm_fnmadd_pd(x, y, _mm_set1_pd(std::numeric_limits<double>::quiet_NaN())), _mm_set1_pd(-0.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f751(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(_mm_set1_pd(-0.0), _mm_fnmadd_pd(x, y, _mm_set1_pd(std::numeric_limits<double>::quiet_NaN()))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f752(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sub_pd(_mm_setzero_pd(), _mm_fnmadd_pd(x, y, _mm_set1_pd(std::numeric_limits<double>::quiet_NaN()))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f753(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_mul_pd(_mm_fnmadd_pd(x, y, _mm_set1_pd(std::numeric_limits<double>::quiet_NaN())), _mm_set1_pd(-1.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f754(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_floor_pd(_mm_fnmadd_pd(x, y, _mm_set1_pd(std::numeric_limits<double>::quiet_NaN()))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f755(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_ceil_pd(_mm_fnmadd_pd(x, y, _mm_set1_pd(std::numeric_limits<double>::quiet_NaN()))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f756(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_round_pd(_mm_fnmadd_pd(x, y, _mm_set1_pd(std::numeric_limits<double>::quiet_NaN())), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f757(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fnmadd_pd(x, y, _mm_set1_pd(std::numeric_limits<double>::quiet_NaN())), 0x5); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f758(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fnmadd_pd(x, y, _mm_set1_pd(std::numeric_limits<double>::quiet_NaN())), 0xa); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f759(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fnmadd_pd(x, y, _mm_set1_pd(std::numeric_limits<double>::quiet_NaN())), 0x3); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f760(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sqrt_pd(_mm_fnmadd_pd(x, _mm_set1_pd(std::numeric_limits<double>::quiet_NaN()), y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f761(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(_mm_fnmadd_pd(x, _mm_set1_pd(std::numeric_limits<double>::quiet_NaN()), y), _mm_set1_pd(-0.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f762(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(_mm_set1_pd(-0.0), _mm_fnmadd_pd(x, _mm_set1_pd(std::numeric_limits<double>::quiet_NaN()), y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f763(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sub_pd(_mm_setzero_pd(), _mm_fnmadd_pd(x, _mm_set1_pd(std::numeric_limits<double>::quiet_NaN()), y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f764(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_mul_pd(_mm_fnmadd_pd(x, _mm_set1_pd(std::numeric_limits<double>::quiet_NaN()), y), _mm_set1_pd(-1.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f765(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_floor_pd(_mm_fnmadd_pd(x, _mm_set1_pd(std::numeric_limits<double>::quiet_NaN()), y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f766(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_ceil_pd(_mm_fnmadd_pd(x, _mm_set1_pd(std::numeric_limits<double>::quiet_NaN()), y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f767(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_round_pd(_mm_fnmadd_pd(x, _mm_set1_pd(std::numeric_limits<double>::quiet_NaN()), y), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f768(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fnmadd_pd(x, _mm_set1_pd(std::numeric_limits<double>::quiet_NaN()), y), 0x5); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f769(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fnmadd_pd(x, _mm_set1_pd(std::numeric_limits<double>::quiet_NaN()), y), 0xa); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f770(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fnmadd_pd(x, _mm_set1_pd(std::numeric_limits<double>::quiet_NaN()), y), 0x3); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f771(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sqrt_pd(_mm_fnmadd_pd(_mm_set1_pd(std::numeric_limits<double>::quiet_NaN()), x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f772(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(_mm_fnmadd_pd(_mm_set1_pd(std::numeric_limits<double>::quiet_NaN()), x, y), _mm_set1_pd(-0.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f773(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(_mm_set1_pd(-0.0), _mm_fnmadd_pd(_mm_set1_pd(std::numeric_limits<double>::quiet_NaN()), x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f774(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sub_pd(_mm_setzero_pd(), _mm_fnmadd_pd(_mm_set1_pd(std::numeric_limits<double>::quiet_NaN()), x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f775(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_mul_pd(_mm_fnmadd_pd(_mm_set1_pd(std::numeric_limits<double>::quiet_NaN()), x, y), _mm_set1_pd(-1.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f776(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_floor_pd(_mm_fnmadd_pd(_mm_set1_pd(std::numeric_limits<double>::quiet_NaN()), x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f777(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_ceil_pd(_mm_fnmadd_pd(_mm_set1_pd(std::numeric_limits<double>::quiet_NaN()), x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f778(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_round_pd(_mm_fnmadd_pd(_mm_set1_pd(std::numeric_limits<double>::quiet_NaN()), x, y), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f779(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fnmadd_pd(_mm_set1_pd(std::numeric_limits<double>::quiet_NaN()), x, y), 0x5); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f780(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fnmadd_pd(_mm_set1_pd(std::numeric_limits<double>::quiet_NaN()), x, y), 0xa); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f781(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fnmadd_pd(_mm_set1_pd(std::numeric_limits<double>::quiet_NaN()), x, y), 0x3); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f782(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sqrt_pd(_mm_fnmadd_pd(x, y, x)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f783(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(_mm_fnmadd_pd(x, y, x), _mm_set1_pd(-0.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f784(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(_mm_set1_pd(-0.0), _mm_fnmadd_pd(x, y, x)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f785(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sub_pd(_mm_setzero_pd(), _mm_fnmadd_pd(x, y, x)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f786(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_mul_pd(_mm_fnmadd_pd(x, y, x), _mm_set1_pd(-1.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f787(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_floor_pd(_mm_fnmadd_pd(x, y, x)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f788(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_ceil_pd(_mm_fnmadd_pd(x, y, x)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f789(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_round_pd(_mm_fnmadd_pd(x, y, x), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f790(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fnmadd_pd(x, y, x), 0x5); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f791(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fnmadd_pd(x, y, x), 0xa); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f792(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fnmadd_pd(x, y, x), 0x3); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f793(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sqrt_pd(_mm_fnmadd_pd(x, x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f794(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(_mm_fnmadd_pd(x, x, y), _mm_set1_pd(-0.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f795(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(_mm_set1_pd(-0.0), _mm_fnmadd_pd(x, x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f796(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sub_pd(_mm_setzero_pd(), _mm_fnmadd_pd(x, x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f797(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_mul_pd(_mm_fnmadd_pd(x, x, y), _mm_set1_pd(-1.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f798(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_floor_pd(_mm_fnmadd_pd(x, x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f799(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_ceil_pd(_mm_fnmadd_pd(x, x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f800(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_round_pd(_mm_fnmadd_pd(x, x, y), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f801(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fnmadd_pd(x, x, y), 0x5); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f802(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fnmadd_pd(x, x, y), 0xa); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f803(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fnmadd_pd(x, x, y), 0x3); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f804(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sqrt_pd(_mm_fnmadd_pd(x, y, _mm_mul_pd(x, y))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f805(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(_mm_fnmadd_pd(x, y, _mm_mul_pd(x, y)), _mm_set1_pd(-0.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f806(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(_mm_set1_pd(-0.0), _mm_fnmadd_pd(x, y, _mm_mul_pd(x, y))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f807(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sub_pd(_mm_setzero_pd(), _mm_fnmadd_pd(x, y, _mm_mul_pd(x, y))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f808(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_mul_pd(_mm_fnmadd_pd(x, y, _mm_mul_pd(x, y)), _mm_set1_pd(-1.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f809(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_floor_pd(_mm_fnmadd_pd(x, y, _mm_mul_pd(x, y))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f810(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_ceil_pd(_mm_fnmadd_pd(x, y, _mm_mul_pd(x, y))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f811(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_round_pd(_mm_fnmadd_pd(x, y, _mm_mul_pd(x, y)), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f812(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fnmadd_pd(x, y, _mm_mul_pd(x, y)), 0x5); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f813(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fnmadd_pd(x, y, _mm_mul_pd(x, y)), 0xa); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f814(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fnmadd_pd(x, y, _mm_mul_pd(x, y)), 0x3); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f815(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sqrt_pd(_mm_fnmsub_pd(x, y, _mm_setzero_pd())); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f816(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(_mm_fnmsub_pd(x, y, _mm_setzero_pd()), _mm_set1_pd(-0.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f817(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(_mm_set1_pd(-0.0), _mm_fnmsub_pd(x, y, _mm_setzero_pd())); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f818(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sub_pd(_mm_setzero_pd(), _mm_fnmsub_pd(x, y, _mm_setzero_pd())); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f819(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_mul_pd(_mm_fnmsub_pd(x, y, _mm_setzero_pd()), _mm_set1_pd(-1.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f820(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_floor_pd(_mm_fnmsub_pd(x, y, _mm_setzero_pd())); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f821(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_ceil_pd(_mm_fnmsub_pd(x, y, _mm_setzero_pd())); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f822(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_round_pd(_mm_fnmsub_pd(x, y, _mm_setzero_pd()), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f823(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fnmsub_pd(x, y, _mm_setzero_pd()), 0x5); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f824(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fnmsub_pd(x, y, _mm_setzero_pd()), 0xa); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f825(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fnmsub_pd(x, y, _mm_setzero_pd()), 0x3); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f826(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sqrt_pd(_mm_fnmsub_pd(x, _mm_setzero_pd(), y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f827(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(_mm_fnmsub_pd(x, _mm_setzero_pd(), y), _mm_set1_pd(-0.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f828(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(_mm_set1_pd(-0.0), _mm_fnmsub_pd(x, _mm_setzero_pd(), y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f829(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sub_pd(_mm_setzero_pd(), _mm_fnmsub_pd(x, _mm_setzero_pd(), y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f830(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_mul_pd(_mm_fnmsub_pd(x, _mm_setzero_pd(), y), _mm_set1_pd(-1.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f831(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_floor_pd(_mm_fnmsub_pd(x, _mm_setzero_pd(), y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f832(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_ceil_pd(_mm_fnmsub_pd(x, _mm_setzero_pd(), y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f833(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_round_pd(_mm_fnmsub_pd(x, _mm_setzero_pd(), y), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f834(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fnmsub_pd(x, _mm_setzero_pd(), y), 0x5); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f835(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fnmsub_pd(x, _mm_setzero_pd(), y), 0xa); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f836(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fnmsub_pd(x, _mm_setzero_pd(), y), 0x3); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f837(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sqrt_pd(_mm_fnmsub_pd(_mm_setzero_pd(), x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f838(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(_mm_fnmsub_pd(_mm_setzero_pd(), x, y), _mm_set1_pd(-0.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f839(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(_mm_set1_pd(-0.0), _mm_fnmsub_pd(_mm_setzero_pd(), x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f840(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sub_pd(_mm_setzero_pd(), _mm_fnmsub_pd(_mm_setzero_pd(), x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f841(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_mul_pd(_mm_fnmsub_pd(_mm_setzero_pd(), x, y), _mm_set1_pd(-1.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f842(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_floor_pd(_mm_fnmsub_pd(_mm_setzero_pd(), x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f843(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_ceil_pd(_mm_fnmsub_pd(_mm_setzero_pd(), x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f844(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_round_pd(_mm_fnmsub_pd(_mm_setzero_pd(), x, y), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f845(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fnmsub_pd(_mm_setzero_pd(), x, y), 0x5); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f846(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fnmsub_pd(_mm_setzero_pd(), x, y), 0xa); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f847(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fnmsub_pd(_mm_setzero_pd(), x, y), 0x3); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f848(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sqrt_pd(_mm_fnmsub_pd(x, y, _mm_set1_pd(-0.0))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f849(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(_mm_fnmsub_pd(x, y, _mm_set1_pd(-0.0)), _mm_set1_pd(-0.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f850(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(_mm_set1_pd(-0.0), _mm_fnmsub_pd(x, y, _mm_set1_pd(-0.0))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f851(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sub_pd(_mm_setzero_pd(), _mm_fnmsub_pd(x, y, _mm_set1_pd(-0.0))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f852(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_mul_pd(_mm_fnmsub_pd(x, y, _mm_set1_pd(-0.0)), _mm_set1_pd(-1.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f853(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_floor_pd(_mm_fnmsub_pd(x, y, _mm_set1_pd(-0.0))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f854(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_ceil_pd(_mm_fnmsub_pd(x, y, _mm_set1_pd(-0.0))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f855(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_round_pd(_mm_fnmsub_pd(x, y, _mm_set1_pd(-0.0)), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f856(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fnmsub_pd(x, y, _mm_set1_pd(-0.0)), 0x5); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f857(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fnmsub_pd(x, y, _mm_set1_pd(-0.0)), 0xa); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f858(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fnmsub_pd(x, y, _mm_set1_pd(-0.0)), 0x3); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f859(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sqrt_pd(_mm_fnmsub_pd(x, _mm_set1_pd(-0.0), y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f860(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(_mm_fnmsub_pd(x, _mm_set1_pd(-0.0), y), _mm_set1_pd(-0.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f861(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(_mm_set1_pd(-0.0), _mm_fnmsub_pd(x, _mm_set1_pd(-0.0), y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f862(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sub_pd(_mm_setzero_pd(), _mm_fnmsub_pd(x, _mm_set1_pd(-0.0), y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f863(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_mul_pd(_mm_fnmsub_pd(x, _mm_set1_pd(-0.0), y), _mm_set1_pd(-1.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f864(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_floor_pd(_mm_fnmsub_pd(x, _mm_set1_pd(-0.0), y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f865(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_ceil_pd(_mm_fnmsub_pd(x, _mm_set1_pd(-0.0), y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f866(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_round_pd(_mm_fnmsub_pd(x, _mm_set1_pd(-0.0), y), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f867(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fnmsub_pd(x, _mm_set1_pd(-0.0), y), 0x5); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f868(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fnmsub_pd(x, _mm_set1_pd(-0.0), y), 0xa); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f869(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fnmsub_pd(x, _mm_set1_pd(-0.0), y), 0x3); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f870(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sqrt_pd(_mm_fnmsub_pd(_mm_set1_pd(-0.0), x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f871(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(_mm_fnmsub_pd(_mm_set1_pd(-0.0), x, y), _mm_set1_pd(-0.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f872(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(_mm_set1_pd(-0.0), _mm_fnmsub_pd(_mm_set1_pd(-0.0), x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f873(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sub_pd(_mm_setzero_pd(), _mm_fnmsub_pd(_mm_set1_pd(-0.0), x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f874(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_mul_pd(_mm_fnmsub_pd(_mm_set1_pd(-0.0), x, y), _mm_set1_pd(-1.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f875(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_floor_pd(_mm_fnmsub_pd(_mm_set1_pd(-0.0), x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f876(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_ceil_pd(_mm_fnmsub_pd(_mm_set1_pd(-0.0), x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f877(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_round_pd(_mm_fnmsub_pd(_mm_set1_pd(-0.0), x, y), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f878(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fnmsub_pd(_mm_set1_pd(-0.0), x, y), 0x5); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f879(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fnmsub_pd(_mm_set1_pd(-0.0), x, y), 0xa); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f880(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fnmsub_pd(_mm_set1_pd(-0.0), x, y), 0x3); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f881(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sqrt_pd(_mm_fnmsub_pd(x, y, _mm_set1_pd(1.0))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f882(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(_mm_fnmsub_pd(x, y, _mm_set1_pd(1.0)), _mm_set1_pd(-0.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f883(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(_mm_set1_pd(-0.0), _mm_fnmsub_pd(x, y, _mm_set1_pd(1.0))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f884(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sub_pd(_mm_setzero_pd(), _mm_fnmsub_pd(x, y, _mm_set1_pd(1.0))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f885(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_mul_pd(_mm_fnmsub_pd(x, y, _mm_set1_pd(1.0)), _mm_set1_pd(-1.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f886(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_floor_pd(_mm_fnmsub_pd(x, y, _mm_set1_pd(1.0))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f887(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_ceil_pd(_mm_fnmsub_pd(x, y, _mm_set1_pd(1.0))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f888(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_round_pd(_mm_fnmsub_pd(x, y, _mm_set1_pd(1.0)), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f889(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fnmsub_pd(x, y, _mm_set1_pd(1.0)), 0x5); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f890(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fnmsub_pd(x, y, _mm_set1_pd(1.0)), 0xa); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f891(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fnmsub_pd(x, y, _mm_set1_pd(1.0)), 0x3); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f892(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sqrt_pd(_mm_fnmsub_pd(x, _mm_set1_pd(1.0), y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f893(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(_mm_fnmsub_pd(x, _mm_set1_pd(1.0), y), _mm_set1_pd(-0.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f894(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(_mm_set1_pd(-0.0), _mm_fnmsub_pd(x, _mm_set1_pd(1.0), y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f895(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sub_pd(_mm_setzero_pd(), _mm_fnmsub_pd(x, _mm_set1_pd(1.0), y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f896(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_mul_pd(_mm_fnmsub_pd(x, _mm_set1_pd(1.0), y), _mm_set1_pd(-1.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f897(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_floor_pd(_mm_fnmsub_pd(x, _mm_set1_pd(1.0), y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f898(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_ceil_pd(_mm_fnmsub_pd(x, _mm_set1_pd(1.0), y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f899(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_round_pd(_mm_fnmsub_pd(x, _mm_set1_pd(1.0), y), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f900(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fnmsub_pd(x, _mm_set1_pd(1.0), y), 0x5); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f901(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fnmsub_pd(x, _mm_set1_pd(1.0), y), 0xa); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f902(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fnmsub_pd(x, _mm_set1_pd(1.0), y), 0x3); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f903(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sqrt_pd(_mm_fnmsub_pd(_mm_set1_pd(1.0), x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f904(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(_mm_fnmsub_pd(_mm_set1_pd(1.0), x, y), _mm_set1_pd(-0.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f905(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(_mm_set1_pd(-0.0), _mm_fnmsub_pd(_mm_set1_pd(1.0), x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f906(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sub_pd(_mm_setzero_pd(), _mm_fnmsub_pd(_mm_set1_pd(1.0), x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f907(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_mul_pd(_mm_fnmsub_pd(_mm_set1_pd(1.0), x, y), _mm_set1_pd(-1.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f908(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_floor_pd(_mm_fnmsub_pd(_mm_set1_pd(1.0), x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f909(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_ceil_pd(_mm_fnmsub_pd(_mm_set1_pd(1.0), x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f910(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_round_pd(_mm_fnmsub_pd(_mm_set1_pd(1.0), x, y), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f911(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fnmsub_pd(_mm_set1_pd(1.0), x, y), 0x5); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f912(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fnmsub_pd(_mm_set1_pd(1.0), x, y), 0xa); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f913(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fnmsub_pd(_mm_set1_pd(1.0), x, y), 0x3); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f914(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sqrt_pd(_mm_fnmsub_pd(x, y, _mm_set1_pd(-1.0))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f915(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(_mm_fnmsub_pd(x, y, _mm_set1_pd(-1.0)), _mm_set1_pd(-0.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f916(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(_mm_set1_pd(-0.0), _mm_fnmsub_pd(x, y, _mm_set1_pd(-1.0))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f917(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sub_pd(_mm_setzero_pd(), _mm_fnmsub_pd(x, y, _mm_set1_pd(-1.0))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f918(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_mul_pd(_mm_fnmsub_pd(x, y, _mm_set1_pd(-1.0)), _mm_set1_pd(-1.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f919(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_floor_pd(_mm_fnmsub_pd(x, y, _mm_set1_pd(-1.0))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f920(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_ceil_pd(_mm_fnmsub_pd(x, y, _mm_set1_pd(-1.0))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f921(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_round_pd(_mm_fnmsub_pd(x, y, _mm_set1_pd(-1.0)), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f922(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fnmsub_pd(x, y, _mm_set1_pd(-1.0)), 0x5); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f923(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fnmsub_pd(x, y, _mm_set1_pd(-1.0)), 0xa); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f924(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fnmsub_pd(x, y, _mm_set1_pd(-1.0)), 0x3); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f925(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sqrt_pd(_mm_fnmsub_pd(x, _mm_set1_pd(-1.0), y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f926(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(_mm_fnmsub_pd(x, _mm_set1_pd(-1.0), y), _mm_set1_pd(-0.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f927(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(_mm_set1_pd(-0.0), _mm_fnmsub_pd(x, _mm_set1_pd(-1.0), y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f928(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sub_pd(_mm_setzero_pd(), _mm_fnmsub_pd(x, _mm_set1_pd(-1.0), y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f929(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_mul_pd(_mm_fnmsub_pd(x, _mm_set1_pd(-1.0), y), _mm_set1_pd(-1.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f930(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_floor_pd(_mm_fnmsub_pd(x, _mm_set1_pd(-1.0), y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f931(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_ceil_pd(_mm_fnmsub_pd(x, _mm_set1_pd(-1.0), y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f932(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_round_pd(_mm_fnmsub_pd(x, _mm_set1_pd(-1.0), y), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f933(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fnmsub_pd(x, _mm_set1_pd(-1.0), y), 0x5); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f934(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fnmsub_pd(x, _mm_set1_pd(-1.0), y), 0xa); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f935(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fnmsub_pd(x, _mm_set1_pd(-1.0), y), 0x3); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f936(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sqrt_pd(_mm_fnmsub_pd(_mm_set1_pd(-1.0), x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f937(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(_mm_fnmsub_pd(_mm_set1_pd(-1.0), x, y), _mm_set1_pd(-0.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f938(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(_mm_set1_pd(-0.0), _mm_fnmsub_pd(_mm_set1_pd(-1.0), x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f939(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sub_pd(_mm_setzero_pd(), _mm_fnmsub_pd(_mm_set1_pd(-1.0), x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f940(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_mul_pd(_mm_fnmsub_pd(_mm_set1_pd(-1.0), x, y), _mm_set1_pd(-1.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f941(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_floor_pd(_mm_fnmsub_pd(_mm_set1_pd(-1.0), x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f942(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_ceil_pd(_mm_fnmsub_pd(_mm_set1_pd(-1.0), x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f943(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_round_pd(_mm_fnmsub_pd(_mm_set1_pd(-1.0), x, y), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f944(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fnmsub_pd(_mm_set1_pd(-1.0), x, y), 0x5); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f945(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fnmsub_pd(_mm_set1_pd(-1.0), x, y), 0xa); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f946(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fnmsub_pd(_mm_set1_pd(-1.0), x, y), 0x3); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f947(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sqrt_pd(_mm_fnmsub_pd(x, y, _mm_set1_pd(std::numeric_limits<double>::infinity()))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f948(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(_mm_fnmsub_pd(x, y, _mm_set1_pd(std::numeric_limits<double>::infinity())), _mm_set1_pd(-0.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f949(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(_mm_set1_pd(-0.0), _mm_fnmsub_pd(x, y, _mm_set1_pd(std::numeric_limits<double>::infinity()))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f950(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sub_pd(_mm_setzero_pd(), _mm_fnmsub_pd(x, y, _mm_set1_pd(std::numeric_limits<double>::infinity()))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f951(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_mul_pd(_mm_fnmsub_pd(x, y, _mm_set1_pd(std::numeric_limits<double>::infinity())), _mm_set1_pd(-1.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f952(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_floor_pd(_mm_fnmsub_pd(x, y, _mm_set1_pd(std::numeric_limits<double>::infinity()))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f953(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_ceil_pd(_mm_fnmsub_pd(x, y, _mm_set1_pd(std::numeric_limits<double>::infinity()))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f954(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_round_pd(_mm_fnmsub_pd(x, y, _mm_set1_pd(std::numeric_limits<double>::infinity())), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f955(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fnmsub_pd(x, y, _mm_set1_pd(std::numeric_limits<double>::infinity())), 0x5); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f956(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fnmsub_pd(x, y, _mm_set1_pd(std::numeric_limits<double>::infinity())), 0xa); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f957(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fnmsub_pd(x, y, _mm_set1_pd(std::numeric_limits<double>::infinity())), 0x3); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f958(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sqrt_pd(_mm_fnmsub_pd(x, _mm_set1_pd(std::numeric_limits<double>::infinity()), y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f959(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(_mm_fnmsub_pd(x, _mm_set1_pd(std::numeric_limits<double>::infinity()), y), _mm_set1_pd(-0.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f960(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(_mm_set1_pd(-0.0), _mm_fnmsub_pd(x, _mm_set1_pd(std::numeric_limits<double>::infinity()), y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f961(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sub_pd(_mm_setzero_pd(), _mm_fnmsub_pd(x, _mm_set1_pd(std::numeric_limits<double>::infinity()), y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f962(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_mul_pd(_mm_fnmsub_pd(x, _mm_set1_pd(std::numeric_limits<double>::infinity()), y), _mm_set1_pd(-1.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f963(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_floor_pd(_mm_fnmsub_pd(x, _mm_set1_pd(std::numeric_limits<double>::infinity()), y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f964(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_ceil_pd(_mm_fnmsub_pd(x, _mm_set1_pd(std::numeric_limits<double>::infinity()), y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f965(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_round_pd(_mm_fnmsub_pd(x, _mm_set1_pd(std::numeric_limits<double>::infinity()), y), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f966(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fnmsub_pd(x, _mm_set1_pd(std::numeric_limits<double>::infinity()), y), 0x5); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f967(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fnmsub_pd(x, _mm_set1_pd(std::numeric_limits<double>::infinity()), y), 0xa); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f968(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fnmsub_pd(x, _mm_set1_pd(std::numeric_limits<double>::infinity()), y), 0x3); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f969(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sqrt_pd(_mm_fnmsub_pd(_mm_set1_pd(std::numeric_limits<double>::infinity()), x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f970(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(_mm_fnmsub_pd(_mm_set1_pd(std::numeric_limits<double>::infinity()), x, y), _mm_set1_pd(-0.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f971(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(_mm_set1_pd(-0.0), _mm_fnmsub_pd(_mm_set1_pd(std::numeric_limits<double>::infinity()), x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f972(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sub_pd(_mm_setzero_pd(), _mm_fnmsub_pd(_mm_set1_pd(std::numeric_limits<double>::infinity()), x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f973(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_mul_pd(_mm_fnmsub_pd(_mm_set1_pd(std::numeric_limits<double>::infinity()), x, y), _mm_set1_pd(-1.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f974(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_floor_pd(_mm_fnmsub_pd(_mm_set1_pd(std::numeric_limits<double>::infinity()), x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f975(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_ceil_pd(_mm_fnmsub_pd(_mm_set1_pd(std::numeric_limits<double>::infinity()), x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f976(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_round_pd(_mm_fnmsub_pd(_mm_set1_pd(std::numeric_limits<double>::infinity()), x, y), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f977(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fnmsub_pd(_mm_set1_pd(std::numeric_limits<double>::infinity()), x, y), 0x5); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f978(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fnmsub_pd(_mm_set1_pd(std::numeric_limits<double>::infinity()), x, y), 0xa); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f979(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fnmsub_pd(_mm_set1_pd(std::numeric_limits<double>::infinity()), x, y), 0x3); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f980(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sqrt_pd(_mm_fnmsub_pd(x, y, _mm_set1_pd(std::numeric_limits<double>::quiet_NaN()))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f981(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(_mm_fnmsub_pd(x, y, _mm_set1_pd(std::numeric_limits<double>::quiet_NaN())), _mm_set1_pd(-0.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f982(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(_mm_set1_pd(-0.0), _mm_fnmsub_pd(x, y, _mm_set1_pd(std::numeric_limits<double>::quiet_NaN()))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f983(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sub_pd(_mm_setzero_pd(), _mm_fnmsub_pd(x, y, _mm_set1_pd(std::numeric_limits<double>::quiet_NaN()))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f984(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_mul_pd(_mm_fnmsub_pd(x, y, _mm_set1_pd(std::numeric_limits<double>::quiet_NaN())), _mm_set1_pd(-1.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f985(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_floor_pd(_mm_fnmsub_pd(x, y, _mm_set1_pd(std::numeric_limits<double>::quiet_NaN()))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f986(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_ceil_pd(_mm_fnmsub_pd(x, y, _mm_set1_pd(std::numeric_limits<double>::quiet_NaN()))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f987(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_round_pd(_mm_fnmsub_pd(x, y, _mm_set1_pd(std::numeric_limits<double>::quiet_NaN())), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f988(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fnmsub_pd(x, y, _mm_set1_pd(std::numeric_limits<double>::quiet_NaN())), 0x5); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f989(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fnmsub_pd(x, y, _mm_set1_pd(std::numeric_limits<double>::quiet_NaN())), 0xa); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f990(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fnmsub_pd(x, y, _mm_set1_pd(std::numeric_limits<double>::quiet_NaN())), 0x3); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f991(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sqrt_pd(_mm_fnmsub_pd(x, _mm_set1_pd(std::numeric_limits<double>::quiet_NaN()), y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f992(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(_mm_fnmsub_pd(x, _mm_set1_pd(std::numeric_limits<double>::quiet_NaN()), y), _mm_set1_pd(-0.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f993(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(_mm_set1_pd(-0.0), _mm_fnmsub_pd(x, _mm_set1_pd(std::numeric_limits<double>::quiet_NaN()), y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f994(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sub_pd(_mm_setzero_pd(), _mm_fnmsub_pd(x, _mm_set1_pd(std::numeric_limits<double>::quiet_NaN()), y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f995(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_mul_pd(_mm_fnmsub_pd(x, _mm_set1_pd(std::numeric_limits<double>::quiet_NaN()), y), _mm_set1_pd(-1.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f996(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_floor_pd(_mm_fnmsub_pd(x, _mm_set1_pd(std::numeric_limits<double>::quiet_NaN()), y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f997(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_ceil_pd(_mm_fnmsub_pd(x, _mm_set1_pd(std::numeric_limits<double>::quiet_NaN()), y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f998(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_round_pd(_mm_fnmsub_pd(x, _mm_set1_pd(std::numeric_limits<double>::quiet_NaN()), y), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f999(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fnmsub_pd(x, _mm_set1_pd(std::numeric_limits<double>::quiet_NaN()), y), 0x5); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1000(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fnmsub_pd(x, _mm_set1_pd(std::numeric_limits<double>::quiet_NaN()), y), 0xa); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1001(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fnmsub_pd(x, _mm_set1_pd(std::numeric_limits<double>::quiet_NaN()), y), 0x3); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1002(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sqrt_pd(_mm_fnmsub_pd(_mm_set1_pd(std::numeric_limits<double>::quiet_NaN()), x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1003(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(_mm_fnmsub_pd(_mm_set1_pd(std::numeric_limits<double>::quiet_NaN()), x, y), _mm_set1_pd(-0.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1004(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(_mm_set1_pd(-0.0), _mm_fnmsub_pd(_mm_set1_pd(std::numeric_limits<double>::quiet_NaN()), x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1005(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sub_pd(_mm_setzero_pd(), _mm_fnmsub_pd(_mm_set1_pd(std::numeric_limits<double>::quiet_NaN()), x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1006(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_mul_pd(_mm_fnmsub_pd(_mm_set1_pd(std::numeric_limits<double>::quiet_NaN()), x, y), _mm_set1_pd(-1.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1007(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_floor_pd(_mm_fnmsub_pd(_mm_set1_pd(std::numeric_limits<double>::quiet_NaN()), x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1008(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_ceil_pd(_mm_fnmsub_pd(_mm_set1_pd(std::numeric_limits<double>::quiet_NaN()), x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1009(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_round_pd(_mm_fnmsub_pd(_mm_set1_pd(std::numeric_limits<double>::quiet_NaN()), x, y), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1010(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fnmsub_pd(_mm_set1_pd(std::numeric_limits<double>::quiet_NaN()), x, y), 0x5); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1011(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fnmsub_pd(_mm_set1_pd(std::numeric_limits<double>::quiet_NaN()), x, y), 0xa); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1012(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fnmsub_pd(_mm_set1_pd(std::numeric_limits<double>::quiet_NaN()), x, y), 0x3); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1013(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sqrt_pd(_mm_fnmsub_pd(x, y, x)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1014(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(_mm_fnmsub_pd(x, y, x), _mm_set1_pd(-0.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1015(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(_mm_set1_pd(-0.0), _mm_fnmsub_pd(x, y, x)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1016(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sub_pd(_mm_setzero_pd(), _mm_fnmsub_pd(x, y, x)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1017(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_mul_pd(_mm_fnmsub_pd(x, y, x), _mm_set1_pd(-1.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1018(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_floor_pd(_mm_fnmsub_pd(x, y, x)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1019(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_ceil_pd(_mm_fnmsub_pd(x, y, x)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1020(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_round_pd(_mm_fnmsub_pd(x, y, x), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1021(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fnmsub_pd(x, y, x), 0x5); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1022(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fnmsub_pd(x, y, x), 0xa); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1023(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fnmsub_pd(x, y, x), 0x3); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1024(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sqrt_pd(_mm_fnmsub_pd(x, x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1025(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(_mm_fnmsub_pd(x, x, y), _mm_set1_pd(-0.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1026(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(_mm_set1_pd(-0.0), _mm_fnmsub_pd(x, x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1027(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sub_pd(_mm_setzero_pd(), _mm_fnmsub_pd(x, x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1028(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_mul_pd(_mm_fnmsub_pd(x, x, y), _mm_set1_pd(-1.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1029(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_floor_pd(_mm_fnmsub_pd(x, x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1030(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_ceil_pd(_mm_fnmsub_pd(x, x, y)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1031(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_round_pd(_mm_fnmsub_pd(x, x, y), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1032(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fnmsub_pd(x, x, y), 0x5); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1033(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fnmsub_pd(x, x, y), 0xa); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1034(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fnmsub_pd(x, x, y), 0x3); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1035(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sqrt_pd(_mm_fnmsub_pd(x, y, _mm_mul_pd(x, y))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1036(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(_mm_fnmsub_pd(x, y, _mm_mul_pd(x, y)), _mm_set1_pd(-0.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1037(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(_mm_set1_pd(-0.0), _mm_fnmsub_pd(x, y, _mm_mul_pd(x, y))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1038(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sub_pd(_mm_setzero_pd(), _mm_fnmsub_pd(x, y, _mm_mul_pd(x, y))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1039(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_mul_pd(_mm_fnmsub_pd(x, y, _mm_mul_pd(x, y)), _mm_set1_pd(-1.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1040(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_floor_pd(_mm_fnmsub_pd(x, y, _mm_mul_pd(x, y))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1041(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_ceil_pd(_mm_fnmsub_pd(x, y, _mm_mul_pd(x, y))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1042(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_round_pd(_mm_fnmsub_pd(x, y, _mm_mul_pd(x, y)), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1043(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fnmsub_pd(x, y, _mm_mul_pd(x, y)), 0x5); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1044(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fnmsub_pd(x, y, _mm_mul_pd(x, y)), 0xa); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1045(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_fnmsub_pd(x, y, _mm_mul_pd(x, y)), 0x3); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1046(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sqrt_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_GE_OS))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1047(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_GE_OS)), _mm_set1_pd(-0.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1048(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(_mm_set1_pd(-0.0), _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_GE_OS))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1049(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sub_pd(_mm_setzero_pd(), _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_GE_OS))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1050(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_mul_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_GE_OS)), _mm_set1_pd(-1.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1051(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_floor_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_GE_OS))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1052(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_ceil_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_GE_OS))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1053(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_round_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_GE_OS)), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1054(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_GE_OS)), 0x5); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1055(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_GE_OS)), 0xa); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1056(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_GE_OS)), 0x3); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1057(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sqrt_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_GE_OS))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1058(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_GE_OS)), _mm_set1_pd(-0.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1059(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(_mm_set1_pd(-0.0), _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_GE_OS))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1060(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sub_pd(_mm_setzero_pd(), _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_GE_OS))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1061(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_mul_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_GE_OS)), _mm_set1_pd(-1.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1062(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_floor_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_GE_OS))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1063(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_ceil_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_GE_OS))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1064(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_round_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_GE_OS)), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1065(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_GE_OS)), 0x5); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1066(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_GE_OS)), 0xa); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1067(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_GE_OS)), 0x3); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1068(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sqrt_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_NLE_US))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1069(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_NLE_US)), _mm_set1_pd(-0.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1070(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(_mm_set1_pd(-0.0), _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_NLE_US))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1071(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sub_pd(_mm_setzero_pd(), _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_NLE_US))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1072(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_mul_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_NLE_US)), _mm_set1_pd(-1.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1073(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_floor_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_NLE_US))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1074(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_ceil_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_NLE_US))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1075(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_round_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_NLE_US)), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1076(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_NLE_US)), 0x5); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1077(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_NLE_US)), 0xa); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1078(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_NLE_US)), 0x3); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1079(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sqrt_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_NLE_US))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1080(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_NLE_US)), _mm_set1_pd(-0.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1081(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(_mm_set1_pd(-0.0), _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_NLE_US))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1082(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sub_pd(_mm_setzero_pd(), _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_NLE_US))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1083(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_mul_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_NLE_US)), _mm_set1_pd(-1.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1084(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_floor_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_NLE_US))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1085(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_ceil_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_NLE_US))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1086(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_round_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_NLE_US)), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1087(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_NLE_US)), 0x5); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1088(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_NLE_US)), 0xa); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1089(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_NLE_US)), 0x3); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1090(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sqrt_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_NGT_US))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1091(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_NGT_US)), _mm_set1_pd(-0.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1092(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(_mm_set1_pd(-0.0), _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_NGT_US))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1093(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sub_pd(_mm_setzero_pd(), _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_NGT_US))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1094(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_mul_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_NGT_US)), _mm_set1_pd(-1.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1095(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_floor_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_NGT_US))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1096(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_ceil_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_NGT_US))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1097(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_round_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_NGT_US)), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1098(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_NGT_US)), 0x5); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1099(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_NGT_US)), 0xa); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1100(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_NGT_US)), 0x3); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1101(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sqrt_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_NGT_US))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1102(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_NGT_US)), _mm_set1_pd(-0.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1103(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(_mm_set1_pd(-0.0), _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_NGT_US))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1104(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sub_pd(_mm_setzero_pd(), _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_NGT_US))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1105(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_mul_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_NGT_US)), _mm_set1_pd(-1.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1106(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_floor_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_NGT_US))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1107(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_ceil_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_NGT_US))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1108(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_round_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_NGT_US)), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1109(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_NGT_US)), 0x5); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1110(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_NGT_US)), 0xa); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1111(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_NGT_US)), 0x3); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1112(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sqrt_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_LE_OQ))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1113(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_LE_OQ)), _mm_set1_pd(-0.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1114(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(_mm_set1_pd(-0.0), _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_LE_OQ))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1115(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sub_pd(_mm_setzero_pd(), _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_LE_OQ))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1116(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_mul_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_LE_OQ)), _mm_set1_pd(-1.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1117(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_floor_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_LE_OQ))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1118(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_ceil_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_LE_OQ))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1119(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_round_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_LE_OQ)), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1120(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_LE_OQ)), 0x5); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1121(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_LE_OQ)), 0xa); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1122(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_LE_OQ)), 0x3); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1123(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sqrt_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_LE_OQ))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1124(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_LE_OQ)), _mm_set1_pd(-0.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1125(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(_mm_set1_pd(-0.0), _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_LE_OQ))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1126(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sub_pd(_mm_setzero_pd(), _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_LE_OQ))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1127(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_mul_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_LE_OQ)), _mm_set1_pd(-1.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1128(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_floor_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_LE_OQ))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1129(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_ceil_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_LE_OQ))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1130(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_round_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_LE_OQ)), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1131(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_LE_OQ)), 0x5); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1132(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_LE_OQ)), 0xa); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1133(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_LE_OQ)), 0x3); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1134(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sqrt_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_GE_OQ))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1135(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_GE_OQ)), _mm_set1_pd(-0.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1136(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(_mm_set1_pd(-0.0), _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_GE_OQ))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1137(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sub_pd(_mm_setzero_pd(), _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_GE_OQ))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1138(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_mul_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_GE_OQ)), _mm_set1_pd(-1.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1139(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_floor_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_GE_OQ))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1140(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_ceil_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_GE_OQ))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1141(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_round_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_GE_OQ)), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1142(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_GE_OQ)), 0x5); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1143(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_GE_OQ)), 0xa); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1144(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_GE_OQ)), 0x3); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1145(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sqrt_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_GE_OQ))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1146(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_GE_OQ)), _mm_set1_pd(-0.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1147(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(_mm_set1_pd(-0.0), _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_GE_OQ))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1148(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sub_pd(_mm_setzero_pd(), _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_GE_OQ))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1149(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_mul_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_GE_OQ)), _mm_set1_pd(-1.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1150(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_floor_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_GE_OQ))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1151(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_ceil_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_GE_OQ))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1152(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_round_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_GE_OQ)), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1153(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_GE_OQ)), 0x5); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1154(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_GE_OQ)), 0xa); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1155(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_GE_OQ)), 0x3); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1156(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sqrt_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_LT_OQ))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1157(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_LT_OQ)), _mm_set1_pd(-0.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1158(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(_mm_set1_pd(-0.0), _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_LT_OQ))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1159(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sub_pd(_mm_setzero_pd(), _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_LT_OQ))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1160(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_mul_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_LT_OQ)), _mm_set1_pd(-1.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1161(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_floor_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_LT_OQ))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1162(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_ceil_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_LT_OQ))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1163(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_round_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_LT_OQ)), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1164(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_LT_OQ)), 0x5); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1165(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_LT_OQ)), 0xa); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1166(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_LT_OQ)), 0x3); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1167(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sqrt_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_LT_OQ))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1168(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_xor_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_LT_OQ)), _mm_set1_pd(-0.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1169(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_andnot_pd(_mm_set1_pd(-0.0), _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_LT_OQ))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1170(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_sub_pd(_mm_setzero_pd(), _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_LT_OQ))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1171(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_mul_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_LT_OQ)), _mm_set1_pd(-1.0)); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1172(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_floor_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_LT_OQ))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1173(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_ceil_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_LT_OQ))); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1174(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_round_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_LT_OQ)), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1175(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_LT_OQ)), 0x5); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1176(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_LT_OQ)), 0xa); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1177(const void* px, const void* py, void* po) { const __m128d x = _mm_loadu_pd((const double*)px); const __m128d y = _mm_loadu_pd((const double*)py); (void)y; const __m128d r = _mm_permute_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_LT_OQ)), 0x3); _mm_storeu_pd((double*)po, r); }
static NOINLINE void f1178(const void* px, const void* py, void* po) { const __m256i x = _mm256_loadu_si256((const __m256i*)px); const __m256i y = _mm256_loadu_si256((const __m256i*)py); (void)y; const __m256i r = _mm256_abs_epi8(_mm256_abs_epi8(x)); _mm256_storeu_si256((__m256i*)po, r); }
static NOINLINE void f1179(const void* px, const void* py, void* po) { const __m256i x = _mm256_loadu_si256((const __m256i*)px); const __m256i y = _mm256_loadu_si256((const __m256i*)py); (void)y; const __m256i r = _mm256_abs_epi8(_mm256_abs_epi16(x)); _mm256_storeu_si256((__m256i*)po, r); }
static NOINLINE void f1180(const void* px, const void* py, void* po) { const __m256i x = _mm256_loadu_si256((const __m256i*)px); const __m256i y = _mm256_loadu_si256((const __m256i*)py); (void)y; const __m256i r = _mm256_abs_epi8(_mm256_abs_epi32(x)); _mm256_storeu_si256((__m256i*)po, r); }
static NOINLINE void f1181(const void* px, const void* py, void* po) { const __m256i x = _mm256_loadu_si256((const __m256i*)px); const __m256i y = _mm256_loadu_si256((const __m256i*)py); (void)y; const __m256i r = _mm256_abs_epi8(_mm256_sub_epi8(_mm256_setzero_si256(), x)); _mm256_storeu_si256((__m256i*)po, r); }
static NOINLINE void f1182(const void* px, const void* py, void* po) { const __m256i x = _mm256_loadu_si256((const __m256i*)px); const __m256i y = _mm256_loadu_si256((const __m256i*)py); (void)y; const __m256i r = _mm256_abs_epi8(_mm256_sub_epi16(_mm256_setzero_si256(), x)); _mm256_storeu_si256((__m256i*)po, r); }
static NOINLINE void f1183(const void* px, const void* py, void* po) { const __m256i x = _mm256_loadu_si256((const __m256i*)px); const __m256i y = _mm256_loadu_si256((const __m256i*)py); (void)y; const __m256i r = _mm256_abs_epi8(_mm256_sub_epi32(_mm256_setzero_si256(), x)); _mm256_storeu_si256((__m256i*)po, r); }
static NOINLINE void f1184(const void* px, const void* py, void* po) { const __m256i x = _mm256_loadu_si256((const __m256i*)px); const __m256i y = _mm256_loadu_si256((const __m256i*)py); (void)y; const __m256i r = _mm256_abs_epi8(_mm256_sub_epi64(_mm256_setzero_si256(), x)); _mm256_storeu_si256((__m256i*)po, r); }
static NOINLINE void f1185(const void* px, const void* py, void* po) { const __m256i x = _mm256_loadu_si256((const __m256i*)px); const __m256i y = _mm256_loadu_si256((const __m256i*)py); (void)y; const __m256i r = _mm256_abs_epi8(_mm256_xor_si256(x, _mm256_set1_epi8((char)0xffu))); _mm256_storeu_si256((__m256i*)po, r); }
static NOINLINE void f1186(const void* px, const void* py, void* po) { const __m256i x = _mm256_loadu_si256((const __m256i*)px); const __m256i y = _mm256_loadu_si256((const __m256i*)py); (void)y; const __m256i r = _mm256_abs_epi8(_mm256_slli_epi16(x, 1)); _mm256_storeu_si256((__m256i*)po, r); }
static NOINLINE void f1187(const void* px, const void* py, void* po) { const __m256i x = _mm256_loadu_si256((const __m256i*)px); const __m256i y = _mm256_loadu_si256((const __m256i*)py); (void)y; const __m256i r = _mm256_abs_epi8(_mm256_srli_epi16(x, 1)); _mm256_storeu_si256((__m256i*)po, r); }
static NOINLINE void f1188(const void* px, const void* py, void* po) { const __m256i x = _mm256_loadu_si256((const __m256i*)px); const __m256i y = _mm256_loadu_si256((const __m256i*)py); (void)y; const __m256i r = _mm256_abs_epi8(_mm256_srai_epi16(x, 1)); _mm256_storeu_si256((__m256i*)po, r); }
static NOINLINE void f1189(const void* px, const void* py, void* po) { const __m256i x = _mm256_loadu_si256((const __m256i*)px); const __m256i y = _mm256_loadu_si256((const __m256i*)py); (void)y; const __m256i r = _mm256_abs_epi8(_mm256_slli_epi16(x, 15)); _mm256_storeu_si256((__m256i*)po, r); }
static NOINLINE void f1190(const void* px, const void* py, void* po) { const __m256i x = _mm256_loadu_si256((const __m256i*)px); const __m256i y = _mm256_loadu_si256((const __m256i*)py); (void)y; const __m256i r = _mm256_abs_epi8(_mm256_srli_epi16(x, 15)); _mm256_storeu_si256((__m256i*)po, r); }
static NOINLINE void f1191(const void* px, const void* py, void* po) { const __m256i x = _mm256_loadu_si256((const __m256i*)px); const __m256i y = _mm256_loadu_si256((const __m256i*)py); (void)y; const __m256i r = _mm256_abs_epi8(_mm256_srai_epi16(x, 15)); _mm256_storeu_si256((__m256i*)po, r); }
static NOINLINE void f1192(const void* px, const void* py, void* po) { const __m256i x = _mm256_loadu_si256((const __m256i*)px); const __m256i y = _mm256_loadu_si256((const __m256i*)py); (void)y; const __m256i r = _mm256_abs_epi8(_mm256_slli_epi32(x, 1)); _mm256_storeu_si256((__m256i*)po, r); }
static NOINLINE void f1193(const void* px, const void* py, void* po) { const __m256i x = _mm256_loadu_si256((const __m256i*)px); const __m256i y = _mm256_loadu_si256((const __m256i*)py); (void)y; const __m256i r = _mm256_abs_epi8(_mm256_srli_epi32(x, 1)); _mm256_storeu_si256((__m256i*)po, r); }
static NOINLINE void f1194(const void* px, const void* py, void* po) { const __m256i x = _mm256_loadu_si256((const __m256i*)px); const __m256i y = _mm256_loadu_si256((const __m256i*)py); (void)y; const __m256i r = _mm256_abs_epi8(_mm256_srai_epi32(x, 1)); _mm256_storeu_si256((__m256i*)po, r); }
static NOINLINE void f1195(const void* px, const void* py, void* po) { const __m256i x = _mm256_loadu_si256((const __m256i*)px); const __m256i y = _mm256_loadu_si256((const __m256i*)py); (void)y; const __m256i r = _mm256_abs_epi8(_mm256_slli_epi32(x, 31)); _mm256_storeu_si256((__m256i*)po, r); }
static NOINLINE void f1196(const void* px, const void* py, void* po) { const __m256i x = _mm256_loadu_si256((const __m256i*)px); const __m256i y = _mm256_loadu_si256((const __m256i*)py); (void)y; const __m256i r = _mm256_abs_epi8(_mm256_srli_epi32(x, 31)); _mm256_storeu_si256((__m256i*)po, r); }
static NOINLINE void f1197(const void* px, const void* py, void* po) { const __m256i x = _mm256_loadu_si256((const __m256i*)px); const __m256i y = _mm256_loadu_si256((const __m256i*)py); (void)y; const __m256i r = _mm256_abs_epi8(_mm256_srai_epi32(x, 31)); _mm256_storeu_si256((__m256i*)po, r); }
static NOINLINE void f1198(const void* px, const void* py, void* po) { const __m256i x = _mm256_loadu_si256((const __m256i*)px); const __m256i y = _mm256_loadu_si256((const __m256i*)py); (void)y; const __m256i r = _mm256_abs_epi8(_mm256_slli_epi64(x, 1)); _mm256_storeu_si256((__m256i*)po, r); }
static NOINLINE void f1199(const void* px, const void* py, void* po) { const __m256i x = _mm256_loadu_si256((const __m256i*)px); const __m256i y = _mm256_loadu_si256((const __m256i*)py); (void)y; const __m256i r = _mm256_abs_epi8(_mm256_srli_epi64(x, 1)); _mm256_storeu_si256((__m256i*)po, r); }
extern const Entry table_42[] = {
  {"128:_mm_mul_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LT_OQ)), _mm_set1_ps(-1.0f))", f0, 1, 128},
  {"128:_mm_floor_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LT_OQ)))", f1, 1, 128},
  {"128:_mm_ceil_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LT_OQ)))", f2, 1, 128},
  {"128:_mm_round_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LT_OQ)), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)", f3, 1, 128},
  {"128:_mm_permute_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LT_OQ)), 0x1b)", f4, 1, 128},
  {"128:_mm_permute_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LT_OQ)), 0x39)", f5, 1, 128},
  {"128:_mm_permute_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LT_OQ)), 0x93)", f6, 1, 128},
  {"128:_mm_permute_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LT_OQ)), 0x4e)", f7, 1, 128},
  {"128:_mm_cvtepi32_ps(_mm_cvttps_epi32(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LT_OQ))))", f8, 1, 128},
  {"128:_mm_cvtepi32_ps(_mm_cvtps_epi32(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LT_OQ))))", f9, 1, 128},
  {"128:_mm_movehdup_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LT_OQ)))", f10, 1, 128},
  {"128:_mm_sqrt_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LT_OQ)))", f11, 1, 128},
  {"128:_mm_xor_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LT_OQ)), _mm_set1_ps(-0.0f))", f12, 1, 128},
  {"128:_mm_andnot_ps(_mm_set1_ps(-0.0f), _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LT_OQ)))", f13, 1, 128},
  {"128:_mm_sub_ps(_mm_setzero_ps(), _mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LT_OQ)))", f14, 1, 128},
  {"128:_mm_mul_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LT_OQ)), _mm_set1_ps(-1.0f))", f15, 1, 128},
  {"128:_mm_floor_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LT_OQ)))", f16, 1, 128},
  {"128:_mm_ceil_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LT_OQ)))", f17, 1, 128},
  {"128:_mm_round_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LT_OQ)), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)", f18, 1, 128},
  {"128:_mm_permute_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LT_OQ)), 0x1b)", f19, 1, 128},
  {"128:_mm_permute_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LT_OQ)), 0x39)", f20, 1, 128},
  {"128:_mm_permute_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LT_OQ)), 0x93)", f21, 1, 128},
  {"128:_mm_permute_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LT_OQ)), 0x4e)", f22, 1, 128},
  {"128:_mm_cvtepi32_ps(_mm_cvttps_epi32(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LT_OQ))))", f23, 1, 128},
  {"128:_mm_cvtepi32_ps(_mm_cvtps_epi32(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LT_OQ))))", f24, 1, 128},
  {"128:_mm_movehdup_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LT_OQ)))", f25, 1, 128},
  {"128:_mm_fmadd_pd(x, y, _mm_setzero_pd())", f26, 2, 128},
  {"128:_mm_fmadd_pd(x, _mm_setzero_pd(), y)", f27, 2, 128},
  {"128:_mm_fmadd_pd(_mm_setzero_pd(), x, y)", f28, 2, 128},
  {"128:_mm_fmadd_pd(x, y, _mm_set1_pd(-0.0))", f29, 2, 128},
  {"128:_mm_fmadd_pd(x, _mm_set1_pd(-0.0), y)", f30, 2, 128},
  {"128:_mm_fmadd_pd(_mm_set1_pd(-0.0), x, y)", f31, 2, 128},
  {"128:_mm_fmadd_pd(x, y, _mm_set1_pd(1.0))", f32, 2, 128},
  {"128:_mm_fmadd_pd(x, _mm_set1_pd(1.0), y)", f33, 2, 128},
  {"128:_mm_fmadd_pd(_mm_set1_pd(1.0), x, y)", f34, 2, 128},
  {"128:_mm_fmadd_pd(x, y, _mm_set1_pd(-1.0))", f35, 2, 128},
  {"128:_mm_fmadd_pd(x, _mm_set1_pd(-1.0), y)", f36, 2, 128},
  {"128:_mm_fmadd_pd(_mm_set1_pd(-1.0), x, y)", f37, 2, 128},
  {"128:_mm_fmadd_pd(x, y, _mm_set1_pd(std::numeric_limits<double>::infinity()))", f38, 2, 128},
  {"128:_mm_fmadd_pd(x, _mm_set1_pd(std::numeric_limits<double>::infinity()), y)", f39, 2, 128},
  {"128:_mm_fmadd_pd(_mm_set1_pd(std::numeric_limits<double>::infinity()), x, y)", f40, 2, 128},
  {"128:_mm_fmadd_pd(x, y, _mm_set1_pd(std::numeric_limits<double>::quiet_NaN()))", f41, 2, 128},
  {"128:_mm_fmadd_pd(x, _mm_set1_pd(std::numeric_limits<double>::quiet_NaN()), y)", f42, 2, 128},
  {"128:_mm_fmadd_pd(_mm_set1_pd(std::numeric_limits<double>::quiet_NaN()), x, y)", f43, 2, 128},
  {"128:_mm_fmadd_pd(x, y, x)", f44, 2, 128},
  {"128:_mm_fmadd_pd(x, x, y)", f45, 2, 128},
  {"128:_mm_fmadd_pd(x, y, _mm_mul_pd(x, y))", f46, 2, 128},
  {"128:_mm_fmsub_pd(x, y, _mm_setzero_pd())", f47, 2, 128},
  {"128:_mm_fmsub_pd(x, _mm_setzero_pd(), y)", f48, 2, 128},
  {"128:_mm_fmsub_pd(_mm_setzero_pd(), x, y)", f49, 2, 128},
  {"128:_mm_fmsub_pd(x, y, _mm_set1_pd(-0.0))", f50, 2, 128},
  {"128:_mm_fmsub_pd(x, _mm_set1_pd(-0.0), y)", f51, 2, 128},
  {"128:_mm_fmsub_pd(_mm_set1_pd(-0.0), x, y)", f52, 2, 128},
  {"128:_mm_fmsub_pd(x, y, _mm_set1_pd(1.0))", f53, 2, 128},
  {"128:_mm_fmsub_pd(x, _mm_set1_pd(1.0), y)", f54, 2, 128},
  {"128:_mm_fmsub_pd(_mm_set1_pd(1.0), x, y)", f55, 2, 128},
  {"128:_mm_fmsub_pd(x, y, _mm_set1_pd(-1.0))", f56, 2, 128},
  {"128:_mm_fmsub_pd(x, _mm_set1_pd(-1.0), y)", f57, 2, 128},
  {"128:_mm_fmsub_pd(_mm_set1_pd(-1.0), x, y)", f58, 2, 128},
  {"128:_mm_fmsub_pd(x, y, _mm_set1_pd(std::numeric_limits<double>::infinity()))", f59, 2, 128},
  {"128:_mm_fmsub_pd(x, _mm_set1_pd(std::numeric_limits<double>::infinity()), y)", f60, 2, 128},
  {"128:_mm_fmsub_pd(_mm_set1_pd(std::numeric_limits<double>::infinity()), x, y)", f61, 2, 128},
  {"128:_mm_fmsub_pd(x, y, _mm_set1_pd(std::numeric_limits<double>::quiet_NaN()))", f62, 2, 128},
  {"128:_mm_fmsub_pd(x, _mm_set1_pd(std::numeric_limits<double>::quiet_NaN()), y)", f63, 2, 128},
  {"128:_mm_fmsub_pd(_mm_set1_pd(std::numeric_limits<double>::quiet_NaN()), x, y)", f64, 2, 128},
  {"128:_mm_fmsub_pd(x, y, x)", f65, 2, 128},
  {"128:_mm_fmsub_pd(x, x, y)", f66, 2, 128},
  {"128:_mm_fmsub_pd(x, y, _mm_mul_pd(x, y))", f67, 2, 128},
  {"128:_mm_fnmadd_pd(x, y, _mm_setzero_pd())", f68, 2, 128},
  {"128:_mm_fnmadd_pd(x, _mm_setzero_pd(), y)", f69, 2, 128},
  {"128:_mm_fnmadd_pd(_mm_setzero_pd(), x, y)", f70, 2, 128},
  {"128:_mm_fnmadd_pd(x, y, _mm_set1_pd(-0.0))", f71, 2, 128},
  {"128:_mm_fnmadd_pd(x, _mm_set1_pd(-0.0), y)", f72, 2, 128},
  {"128:_mm_fnmadd_pd(_mm_set1_pd(-0.0), x, y)", f73, 2, 128},
  {"128:_mm_fnmadd_pd(x, y, _mm_set1_pd(1.0))", f74, 2, 128},
  {"128:_mm_fnmadd_pd(x, _mm_set1_pd(1.0), y)", f75, 2, 128},
  {"128:_mm_fnmadd_pd(_mm_set1_pd(1.0), x, y)", f76, 2, 128},
  {"128:_mm_fnmadd_pd(x, y, _mm_set1_pd(-1.0))", f77, 2, 128},
  {"128:_mm_fnmadd_pd(x, _mm_set1_pd(-1.0), y)", f78, 2, 128},
  {"128:_mm_fnmadd_pd(_mm_set1_pd(-1.0), x, y)", f79, 2, 128},
  {"128:_mm_fnmadd_pd(x, y, _mm_set1_pd(std::numeric_limits<double>::infinity()))", f80, 2, 128},
  {"128:_mm_fnmadd_pd(x, _mm_set1_pd(std::numeric_limits<double>::infinity()), y)", f81, 2, 128},
  {"128:_mm_fnmadd_pd(_mm_set1_pd(std::numeric_limits<double>::infinity()), x, y)", f82, 2, 128},
  {"128:_mm_fnmadd_pd(x, y, _mm_set1_pd(std::numeric_limits<double>::quiet_NaN()))", f83, 2, 128},
  {"128:_mm_fnmadd_pd(x, _mm_set1_pd(std::numeric_limits<double>::quiet_NaN()), y)", f84, 2, 128},
  {"128:_mm_fnmadd_pd(_mm_set1_pd(std::numeric_limits<double>::quiet_NaN()), x, y)", f85, 2, 128},
  {"128:_mm_fnmadd_pd(x, y, x)", f86, 2, 128},
  {"128:_mm_fnmadd_pd(x, x, y)", f87, 2, 128},
  {"128:_mm_fnmadd_pd(x, y, _mm_mul_pd(x, y))", f88, 2, 128},
  {"128:_mm_fnmsub_pd(x, y, _mm_setzero_pd())", f89, 2, 128},
  {"128:_mm_fnmsub_pd(x, _mm_setzero_pd(), y)", f90, 2, 128},
  {"128:_mm_fnmsub_pd(_mm_setzero_pd(), x, y)", f91, 2, 128},
  {"128:_mm_fnmsub_pd(x, y, _mm_set1_pd(-0.0))", f92, 2, 128},
  {"128:_mm_fnmsub_pd(x, _mm_set1_pd(-0.0), y)", f93, 2, 128},
  {"128:_mm_fnmsub_pd(_mm_set1_pd(-0.0), x, y)", f94, 2, 128},
  {"128:_mm_fnmsub_pd(x, y, _mm_set1_pd(1.0))", f95, 2, 128},
  {"128:_mm_fnmsub_pd(x, _mm_set1_pd(1.0), y)", f96, 2, 128},
  {"128:_mm_fnmsub_pd(_mm_set1_pd(1.0), x, y)", f97, 2, 128},
  {"128:_mm_fnmsub_pd(x, y, _mm_set1_pd(-1.0))", f98, 2, 128},
  {"128:_mm_fnmsub_pd(x, _mm_set1_pd(-1.0), y)", f99, 2, 128},
  {"128:_mm_fnmsub_pd(_mm_set1_pd(-1.0), x, y)", f100, 2, 128},
  {"128:_mm_fnmsub_pd(x, y, _mm_set1_pd(std::numeric_limits<double>::infinity()))", f101, 2, 128},
  {"128:_mm_fnmsub_pd(x, _mm_set1_pd(std::numeric_limits<double>::infinity()), y)", f102, 2, 128},
  {"128:_mm_fnmsub_pd(_mm_set1_pd(std::numeric_limits<double>::infinity()), x, y)", f103, 2, 128},
  {"128:_mm_fnmsub_pd(x, y, _mm_set1_pd(std::numeric_limits<double>::quiet_NaN()))", f104, 2, 128},
  {"128:_mm_fnmsub_pd(x, _mm_set1_pd(std::numeric_limits<double>::quiet_NaN()), y)", f105, 2, 128},
  {"128:_mm_fnmsub_pd(_mm_set1_pd(std::numeric_limits<double>::quiet_NaN()), x, y)", f106, 2, 128},
  {"128:_mm_fnmsub_pd(x, y, x)", f107, 2, 128},
  {"128:_mm_fnmsub_pd(x, x, y)", f108, 2, 128},
  {"128:_mm_fnmsub_pd(x, y, _mm_mul_pd(x, y))", f109, 2, 128},
  {"128:_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_GE_OS))", f110, 2, 128},
  {"128:_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_GE_OS))", f111, 2, 128},
  {"128:_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_NLE_US))", f112, 2, 128},
  {"128:_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_NLE_US))", f113, 2, 128},
  {"128:_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_NGT_US))", f114, 2, 128},
  {"128:_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_NGT_US))", f115, 2, 128},
  {"128:_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_LE_OQ))", f116, 2, 128},
  {"128:_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_LE_OQ))", f117, 2, 128},
  {"128:_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_GE_OQ))", f118, 2, 128},
  {"128:_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_GE_OQ))", f119, 2, 128},
  {"128:_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_LT_OQ))", f120, 2, 128},
  {"128:_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_LT_OQ))", f121, 2, 128},
  {"128:_mm_sqrt_pd(_mm_fmadd_pd(x, y, _mm_setzero_pd()))", f122, 2, 128},
  {"128:_mm_xor_pd(_mm_fmadd_pd(x, y, _mm_setzero_pd()), _mm_set1_pd(-0.0))", f123, 2, 128},
  {"128:_mm_andnot_pd(_mm_set1_pd(-0.0), _mm_fmadd_pd(x, y, _mm_setzero_pd()))", f124, 2, 128},
  {"128:_mm_sub_pd(_mm_setzero_pd(), _mm_fmadd_pd(x, y, _mm_setzero_pd()))", f125, 2, 128},
  {"128:_mm_mul_pd(_mm_fmadd_pd(x, y, _mm_setzero_pd()), _mm_set1_pd(-1.0))", f126, 2, 128},
  {"128:_mm_floor_pd(_mm_fmadd_pd(x, y, _mm_setzero_pd()))", f127, 2, 128},
  {"128:_mm_ceil_pd(_mm_fmadd_pd(x, y, _mm_setzero_pd()))", f128, 2, 128},
  {"128:_mm_round_pd(_mm_fmadd_pd(x, y, _mm_setzero_pd()), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)", f129, 2, 128},
  {"128:_mm_permute_pd(_mm_fmadd_pd(x, y, _mm_setzero_pd()), 0x5)", f130, 2, 128},
  {"128:_mm_permute_pd(_mm_fmadd_pd(x, y, _mm_setzero_pd()), 0xa)", f131, 2, 128},
  {"128:_mm_permute_pd(_mm_fmadd_pd(x, y, _mm_setzero_pd()), 0x3)", f132, 2, 128},
  {"128:_mm_sqrt_pd(_mm_fmadd_pd(x, _mm_setzero_pd(), y))", f133, 2, 128},
  {"128:_mm_xor_pd(_mm_fmadd_pd(x, _mm_setzero_pd(), y), _mm_set1_pd(-0.0))", f134, 2, 128},
  {"128:_mm_andnot_pd(_mm_set1_pd(-0.0), _mm_fmadd_pd(x, _mm_setzero_pd(), y))", f135, 2, 128},
  {"128:_mm_sub_pd(_mm_setzero_pd(), _mm_fmadd_pd(x, _mm_setzero_pd(), y))", f136, 2, 128},
  {"128:_mm_mul_pd(_mm_fmadd_pd(x, _mm_setzero_pd(), y), _mm_set1_pd(-1.0))", f137, 2, 128},
  {"128:_mm_floor_pd(_mm_fmadd_pd(x, _mm_setzero_pd(), y))", f138, 2, 128},
  {"128:_mm_ceil_pd(_mm_fmadd_pd(x, _mm_setzero_pd(), y))", f139, 2, 128},
  {"128:_mm_round_pd(_mm_fmadd_pd(x, _mm_setzero_pd(), y), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)", f140, 2, 128},
  {"128:_mm_permute_pd(_mm_fmadd_pd(x, _mm_setzero_pd(), y), 0x5)", f141, 2, 128},
  {"128:_mm_permute_pd(_mm_fmadd_pd(x, _mm_setzero_pd(), y), 0xa)", f142, 2, 128},
  {"128:_mm_permute_pd(_mm_fmadd_pd(x, _mm_setzero_pd(), y), 0x3)", f143, 2, 128},
  {"128:_mm_sqrt_pd(_mm_fmadd_pd(_mm_setzero_pd(), x, y))", f144, 2, 128},
  {"128:_mm_xor_pd(_mm_fmadd_pd(_mm_setzero_pd(), x, y), _mm_set1_pd(-0.0))", f145, 2, 128},
  {"128:_mm_andnot_pd(_mm_set1_pd(-0.0), _mm_fmadd_pd(_mm_setzero_pd(), x, y))", f146, 2, 128},
  {"128:_mm_sub_pd(_mm_setzero_pd(), _mm_fmadd_pd(_mm_setzero_pd(), x, y))", f147, 2, 128},
  {"128:_mm_mul_pd(_mm_fmadd_pd(_mm_setzero_pd(), x, y), _mm_set1_pd(-1.0))", f148, 2, 128},
  {"128:_mm_floor_pd(_mm_fmadd_pd(_mm_setzero_pd(), x, y))", f149, 2, 128},
  {"128:_mm_ceil_pd(_mm_fmadd_pd(_mm_setzero_pd(), x, y))", f150, 2, 128},
  {"128:_mm_round_pd(_mm_fmadd_pd(_mm_setzero_pd(), x, y), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)", f151, 2, 128},
  {"128:_mm_permute_pd(_mm_fmadd_pd(_mm_setzero_pd(), x, y), 0x5)", f152, 2, 128},
  {"128:_mm_permute_pd(_mm_fmadd_pd(_mm_setzero_pd(), x, y), 0xa)", f153, 2, 128},
  {"128:_mm_permute_pd(_mm_fmadd_pd(_mm_setzero_pd(), x, y), 0x3)", f154, 2, 128},
  {"128:_mm_sqrt_pd(_mm_fmadd_pd(x, y, _mm_set1_pd(-0.0)))", f155, 2, 128},
  {"128:_mm_xor_pd(_mm_fmadd_pd(x, y, _mm_set1_pd(-0.0)), _mm_set1_pd(-0.0))", f156, 2, 128},
  {"128:_mm_andnot_pd(_mm_set1_pd(-0.0), _mm_fmadd_pd(x, y, _mm_set1_pd(-0.0)))", f157, 2, 128},
  {"128:_mm_sub_pd(_mm_setzero_pd(), _mm_fmadd_pd(x, y, _mm_set1_pd(-0.0)))", f158, 2, 128},
  {"128:_mm_mul_pd(_mm_fmadd_pd(x, y, _mm_set1_pd(-0.0)), _mm_set1_pd(-1.0))", f159, 2, 128},
  {"128:_mm_floor_pd(_mm_fmadd_pd(x, y, _mm_set1_pd(-0.0)))", f160, 2, 128},
  {"128:_mm_ceil_pd(_mm_fmadd_pd(x, y, _mm_set1_pd(-0.0)))", f161, 2, 128},
  {"128:_mm_round_pd(_mm_fmadd_pd(x, y, _mm_set1_pd(-0.0)), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)", f162, 2, 128},
  {"128:_mm_permute_pd(_mm_fmadd_pd(x, y, _mm_set1_pd(-0.0)), 0x5)", f163, 2, 128},
  {"128:_mm_permute_pd(_mm_fmadd_pd(x, y, _mm_set1_pd(-0.0)), 0xa)", f164, 2, 128},
  {"128:_mm_permute_pd(_mm_fmadd_pd(x, y, _mm_set1_pd(-0.0)), 0x3)", f165, 2, 128},
  {"128:_mm_sqrt_pd(_mm_fmadd_pd(x, _mm_set1_pd(-0.0), y))", f166, 2, 128},
  {"128:_mm_xor_pd(_mm_fmadd_pd(x, _mm_set1_pd(-0.0), y), _mm_set1_pd(-0.0))", f167, 2, 128},
  {"128:_mm_andnot_pd(_mm_set1_pd(-0.0), _mm_fmadd_pd(x, _mm_set1_pd(-0.0), y))", f168, 2, 128},
  {"128:_mm_sub_pd(_mm_setzero_pd(), _mm_fmadd_pd(x, _mm_set1_pd(-0.0), y))", f169, 2, 128},
  {"128:_mm_mul_pd(_mm_fmadd_pd(x, _mm_set1_pd(-0.0), y), _mm_set1_pd(-1.0))", f170, 2, 128},
  {"128:_mm_floor_pd(_mm_fmadd_pd(x, _mm_set1_pd(-0.0), y))", f171, 2, 128},
  {"128:_mm_ceil_pd(_mm_fmadd_pd(x, _mm_set1_pd(-0.0), y))", f172, 2, 128},
  {"128:_mm_round_pd(_mm_fmadd_pd(x, _mm_set1_pd(-0.0), y), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)", f173, 2, 128},
  {"128:_mm_permute_pd(_mm_fmadd_pd(x, _mm_set1_pd(-0.0), y), 0x5)", f174, 2, 128},
  {"128:_mm_permute_pd(_mm_fmadd_pd(x, _mm_set1_pd(-0.0), y), 0xa)", f175, 2, 128},
  {"128:_mm_permute_pd(_mm_fmadd_pd(x, _mm_set1_pd(-0.0), y), 0x3)", f176, 2, 128},
  {"128:_mm_sqrt_pd(_mm_fmadd_pd(_mm_set1_pd(-0.0), x, y))", f177, 2, 128},
  {"128:_mm_xor_pd(_mm_fmadd_pd(_mm_set1_pd(-0.0), x, y), _mm_set1_pd(-0.0))", f178, 2, 128},
  {"128:_mm_andnot_pd(_mm_set1_pd(-0.0), _mm_fmadd_pd(_mm_set1_pd(-0.0), x, y))", f179, 2, 128},
  {"128:_mm_sub_pd(_mm_setzero_pd(), _mm_fmadd_pd(_mm_set1_pd(-0.0), x, y))", f180, 2, 128},
  {"128:_mm_mul_pd(_mm_fmadd_pd(_mm_set1_pd(-0.0), x, y), _mm_set1_pd(-1.0))", f181, 2, 128},
  {"128:_mm_floor_pd(_mm_fmadd_pd(_mm_set1_pd(-0.0), x, y))", f182, 2, 128},
  {"128:_mm_ceil_pd(_mm_fmadd_pd(_mm_set1_pd(-0.0), x, y))", f183, 2, 128},
  {"128:_mm_round_pd(_mm_fmadd_pd(_mm_set1_pd(-0.0), x, y), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)", f184, 2, 128},
  {"128:_mm_permute_pd(_mm_fmadd_pd(_mm_set1_pd(-0.0), x, y), 0x5)", f185, 2, 128},
  {"128:_mm_permute_pd(_mm_fmadd_pd(_mm_set1_pd(-0.0), x, y), 0xa)", f186, 2, 128},
  {"128:_mm_permute_pd(_mm_fmadd_pd(_mm_set1_pd(-0.0), x, y), 0x3)", f187, 2, 128},
  {"128:_mm_sqrt_pd(_mm_fmadd_pd(x, y, _mm_set1_pd(1.0)))", f188, 2, 128},
  {"128:_mm_xor_pd(_mm_fmadd_pd(x, y, _mm_set1_pd(1.0)), _mm_set1_pd(-0.0))", f189, 2, 128},
  {"128:_mm_andnot_pd(_mm_set1_pd(-0.0), _mm_fmadd_pd(x, y, _mm_set1_pd(1.0)))", f190, 2, 128},
  {"128:_mm_sub_pd(_mm_setzero_pd(), _mm_fmadd_pd(x, y, _mm_set1_pd(1.0)))", f191, 2, 128},
  {"128:_mm_mul_pd(_mm_fmadd_pd(x, y, _mm_set1_pd(1.0)), _mm_set1_pd(-1.0))", f192, 2, 128},
  {"128:_mm_floor_pd(_mm_fmadd_pd(x, y, _mm_set1_pd(1.0)))", f193, 2, 128},
  {"128:_mm_ceil_pd(_mm_fmadd_pd(x, y, _mm_set1_pd(1.0)))", f194, 2, 128},
  {"128:_mm_round_pd(_mm_fmadd_pd(x, y, _mm_set1_pd(1.0)), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)", f195, 2, 128},
  {"128:_mm_permute_pd(_mm_fmadd_pd(x, y, _mm_set1_pd(1.0)), 0x5)", f196, 2, 128},
  {"128:_mm_permute_pd(_mm_fmadd_pd(x, y, _mm_set1_pd(1.0)), 0xa)", f197, 2, 128},
  {"128:_mm_permute_pd(_mm_fmadd_pd(x, y, _mm_set1_pd(1.0)), 0x3)", f198, 2, 128},
  {"128:_mm_sqrt_pd(_mm_fmadd_pd(x, _mm_set1_pd(1.0), y))", f199, 2, 128},
  {"128:_mm_xor_pd(_mm_fmadd_pd(x, _mm_set1_pd(1.0), y), _mm_set1_pd(-0.0))", f200, 2, 128},
  {"128:_mm_andnot_pd(_mm_set1_pd(-0.0), _mm_fmadd_pd(x, _mm_set1_pd(1.0), y))", f201, 2, 128},
  {"128:_mm_sub_pd(_mm_setzero_pd(), _mm_fmadd_pd(x, _mm_set1_pd(1.0), y))", f202, 2, 128},
  {"128:_mm_mul_pd(_mm_fmadd_pd(x, _mm_set1_pd(1.0), y), _mm_set1_pd(-1.0))", f203, 2, 128},
  {"128:_mm_floor_pd(_mm_fmadd_pd(x, _mm_set1_pd(1.0), y))", f204, 2, 128},
  {"128:_mm_ceil_pd(_mm_fmadd_pd(x, _mm_set1_pd(1.0), y))", f205, 2, 128},
  {"128:_mm_round_pd(_mm_fmadd_pd(x, _mm_set1_pd(1.0), y), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)", f206, 2, 128},
  {"128:_mm_permute_pd(_mm_fmadd_pd(x, _mm_set1_pd(1.0), y), 0x5)", f207, 2, 128},
  {"128:_mm_permute_pd(_mm_fmadd_pd(x, _mm_set1_pd(1.0), y), 0xa)", f208, 2, 128},
  {"128:_mm_permute_pd(_mm_fmadd_pd(x, _mm_set1_pd(1.0), y), 0x3)", f209, 2, 128},
  {"128:_mm_sqrt_pd(_mm_fmadd_pd(_mm_set1_pd(1.0), x, y))", f210, 2, 128},
  {"128:_mm_xor_pd(_mm_fmadd_pd(_mm_set1_pd(1.0), x, y), _mm_set1_pd(-0.0))", f211, 2, 128},
  {"128:_mm_andnot_pd(_mm_set1_pd(-0.0), _mm_fmadd_pd(_mm_set1_pd(1.0), x, y))", f212, 2, 128},
  {"128:_mm_sub_pd(_mm_setzero_pd(), _mm_fmadd_pd(_mm_set1_pd(1.0), x, y))", f213, 2, 128},
  {"128:_mm_mul_pd(_mm_fmadd_pd(_mm_set1_pd(1.0), x, y), _mm_set1_pd(-1.0))", f214, 2, 128},
  {"128:_mm_floor_pd(_mm_fmadd_pd(_mm_set1_pd(1.0), x, y))", f215, 2, 128},
  {"128:_mm_ceil_pd(_mm_fmadd_pd(_mm_set1_pd(1.0), x, y))", f216, 2, 128},
  {"128:_mm_round_pd(_mm_fmadd_pd(_mm_set1_pd(1.0), x, y), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)", f217, 2, 128},
  {"128:_mm_permute_pd(_mm_fmadd_pd(_mm_set1_pd(1.0), x, y), 0x5)", f218, 2, 128},
  {"128:_mm_permute_pd(_mm_fmadd_pd(_mm_set1_pd(1.0), x, y), 0xa)", f219, 2, 128},
  {"128:_mm_permute_pd(_mm_fmadd_pd(_mm_set1_pd(1.0), x, y), 0x3)", f220, 2, 128},
  {"128:_mm_sqrt_pd(_mm_fmadd_pd(x, y, _mm_set1_pd(-1.0)))", f221, 2, 128},
  {"128:_mm_xor_pd(_mm_fmadd_pd(x, y, _mm_set1_pd(-1.0)), _mm_set1_pd(-0.0))", f222, 2, 128},
  {"128:_mm_andnot_pd(_mm_set1_pd(-0.0), _mm_fmadd_pd(x, y, _mm_set1_pd(-1.0)))", f223, 2, 128},
  {"128:_mm_sub_pd(_mm_setzero_pd(), _mm_fmadd_pd(x, y, _mm_set1_pd(-1.0)))", f224, 2, 128},
  {"128:_mm_mul_pd(_mm_fmadd_pd(x, y, _mm_set1_pd(-1.0)), _mm_set1_pd(-1.0))", f225, 2, 128},
  {"128:_mm_floor_pd(_mm_fmadd_pd(x, y, _mm_set1_pd(-1.0)))", f226, 2, 128},
  {"128:_mm_ceil_pd(_mm_fmadd_pd(x, y, _mm_set1_pd(-1.0)))", f227, 2, 128},
  {"128:_mm_round_pd(_mm_fmadd_pd(x, y, _mm_set1_pd(-1.0)), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)", f228, 2, 128},
  {"128:_mm_permute_pd(_mm_fmadd_pd(x, y, _mm_set1_pd(-1.0)), 0x5)", f229, 2, 128},
  {"128:_mm_permute_pd(_mm_fmadd_pd(x, y, _mm_set1_pd(-1.0)), 0xa)", f230, 2, 128},
  {"128:_mm_permute_pd(_mm_fmadd_pd(x, y, _mm_set1_pd(-1.0)), 0x3)", f231, 2, 128},
  {"128:_mm_sqrt_pd(_mm_fmadd_pd(x, _mm_set1_pd(-1.0), y))", f232, 2, 128},
  {"128:_mm_xor_pd(_mm_fmadd_pd(x, _mm_set1_pd(-1.0), y), _mm_set1_pd(-0.0))", f233, 2, 128},
  {"128:_mm_andnot_pd(_mm_set1_pd(-0.0), _mm_fmadd_pd(x, _mm_set1_pd(-1.0), y))", f234, 2, 128},
  {"128:_mm_sub_pd(_mm_setzero_pd(), _mm_fmadd_pd(x, _mm_set1_pd(-1.0), y))", f235, 2, 128},
  {"128:_mm_mul_pd(_mm_fmadd_pd(x, _mm_set1_pd(-1.0), y), _mm_set1_pd(-1.0))", f236, 2, 128},
  {"128:_mm_floor_pd(_mm_fmadd_pd(x, _mm_set1_pd(-1.0), y))", f237, 2, 128},
  {"128:_mm_ceil_pd(_mm_fmadd_pd(x, _mm_set1_pd(-1.0), y))", f238, 2, 128},
  {"128:_mm_round_pd(_mm_fmadd_pd(x, _mm_set1_pd(-1.0), y), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)", f239, 2, 128},
  {"128:_mm_permute_pd(_mm_fmadd_pd(x, _mm_set1_pd(-1.0), y), 0x5)", f240, 2, 128},
  {"128:_mm_permute_pd(_mm_fmadd_pd(x, _mm_set1_pd(-1.0), y), 0xa)", f241, 2, 128},
  {"128:_mm_permute_pd(_mm_fmadd_pd(x, _mm_set1_pd(-1.0), y), 0x3)", f242, 2, 128},
  {"128:_mm_sqrt_pd(_mm_fmadd_pd(_mm_set1_pd(-1.0), x, y))", f243, 2, 128},
  {"128:_mm_xor_pd(_mm_fmadd_pd(_mm_set1_pd(-1.0), x, y), _mm_set1_pd(-0.0))", f244, 2, 128},
  {"128:_mm_andnot_pd(_mm_set1_pd(-0.0), _mm_fmadd_pd(_mm_set1_pd(-1.0), x, y))", f245, 2, 128},
  {"128:_mm_sub_pd(_mm_setzero_pd(), _mm_fmadd_pd(_mm_set1_pd(-1.0), x, y))", f246, 2, 128},
  {"128:_mm_mul_pd(_mm_fmadd_pd(_mm_set1_pd(-1.0), x, y), _mm_set1_pd(-1.0))", f247, 2, 128},
  {"128:_mm_floor_pd(_mm_fmadd_pd(_mm_set1_pd(-1.0), x, y))", f248, 2, 128},
  {"128:_mm_ceil_pd(_mm_fmadd_pd(_mm_set1_pd(-1.0), x, y))", f249, 2, 128},
  {"128:_mm_round_pd(_mm_fmadd_pd(_mm_set1_pd(-1.0), x, y), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)", f250, 2, 128},
  {"128:_mm_permute_pd(_mm_fmadd_pd(_mm_set1_pd(-1.0), x, y), 0x5)", f251, 2, 128},
  {"128:_mm_permute_pd(_mm_fmadd_pd(_mm_set1_pd(-1.0), x, y), 0xa)", f252, 2, 128},
  {"128:_mm_permute_pd(_mm_fmadd_pd(_mm_set1_pd(-1.0), x, y), 0x3)", f253, 2, 128},
  {"128:_mm_sqrt_pd(_mm_fmadd_pd(x, y, _mm_set1_pd(std::numeric_limits<double>::infinity())))", f254, 2, 128},
  {"128:_mm_xor_pd(_mm_fmadd_pd(x, y, _mm_set1_pd(std::numeric_limits<double>::infinity())), _mm_set1_pd(-0.0))", f255, 2, 128},
  {"128:_mm_andnot_pd(_mm_set1_pd(-0.0), _mm_fmadd_pd(x, y, _mm_set1_pd(std::numeric_limits<double>::infinity())))", f256, 2, 128},
  {"128:_mm_sub_pd(_mm_setzero_pd(), _mm_fmadd_pd(x, y, _mm_set1_pd(std::numeric_limits<double>::infinity())))", f257, 2, 128},
  {"128:_mm_mul_pd(_mm_fmadd_pd(x, y, _mm_set1_pd(std::numeric_limits<double>::infinity())), _mm_set1_pd(-1.0))", f258, 2, 128},
  {"128:_mm_floor_pd(_mm_fmadd_pd(x, y, _mm_set1_pd(std::numeric_limits<double>::infinity())))", f259, 2, 128},
  {"128:_mm_ceil_pd(_mm_fmadd_pd(x, y, _mm_set1_pd(std::numeric_limits<double>::infinity())))", f260, 2, 128},
  {"128:_mm_round_pd(_mm_fmadd_pd(x, y, _mm_set1_pd(std::numeric_limits<double>::infinity())), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)", f261, 2, 128},
  {"128:_mm_permute_pd(_mm_fmadd_pd(x, y, _mm_set1_pd(std::numeric_limits<double>::infinity())), 0x5)", f262, 2, 128},
  {"128:_mm_permute_pd(_mm_fmadd_pd(x, y, _mm_set1_pd(std::numeric_limits<double>::infinity())), 0xa)", f263, 2, 128},
  {"128:_mm_permute_pd(_mm_fmadd_pd(x, y, _mm_set1_pd(std::numeric_limits<double>::infinity())), 0x3)", f264, 2, 128},
  {"128:_mm_sqrt_pd(_mm_fmadd_pd(x, _mm_set1_pd(std::numeric_limits<double>::infinity()), y))", f265, 2, 128},
  {"128:_mm_xor_pd(_mm_fmadd_pd(x, _mm_set1_pd(std::numeric_limits<double>::infinity()), y), _mm_set1_pd(-0.0))", f266, 2, 128},
  {"128:_mm_andnot_pd(_mm_set1_pd(-0.0), _mm_fmadd_pd(x, _mm_set1_pd(std::numeric_limits<double>::infinity()), y))", f267, 2, 128},
  {"128:_mm_sub_pd(_mm_setzero_pd(), _mm_fmadd_pd(x, _mm_set1_pd(std::numeric_limits<double>::infinity()), y))", f268, 2, 128},
  {"128:_mm_mul_pd(_mm_fmadd_pd(x, _mm_set1_pd(std::numeric_limits<double>::infinity()), y), _mm_set1_pd(-1.0))", f269, 2, 128},
  {"128:_mm_floor_pd(_mm_fmadd_pd(x, _mm_set1_pd(std::numeric_limits<double>::infinity()), y))", f270, 2, 128},
  {"128:_mm_ceil_pd(_mm_fmadd_pd(x, _mm_set1_pd(std::numeric_limits<double>::infinity()), y))", f271, 2, 128},
  {"128:_mm_round_pd(_mm_fmadd_pd(x, _mm_set1_pd(std::numeric_limits<double>::infinity()), y), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)", f272, 2, 128},
  {"128:_mm_permute_pd(_mm_fmadd_pd(x, _mm_set1_pd(std::numeric_limits<double>::infinity()), y), 0x5)", f273, 2, 128},
  {"128:_mm_permute_pd(_mm_fmadd_pd(x, _mm_set1_pd(std::numeric_limits<double>::infinity()), y), 0xa)", f274, 2, 128},
  {"128:_mm_permute_pd(_mm_fmadd_pd(x, _mm_set1_pd(std::numeric_limits<double>::infinity()), y), 0x3)", f275, 2, 128},
  {"128:_mm_sqrt_pd(_mm_fmadd_pd(_mm_set1_pd(std::numeric_limits<double>::infinity()), x, y))", f276, 2, 128},
  {"128:_mm_xor_pd(_mm_fmadd_pd(_mm_set1_pd(std::numeric_limits<double>::infinity()), x, y), _mm_set1_pd(-0.0))", f277, 2, 128},
  {"128:_mm_andnot_pd(_mm_set1_pd(-0.0), _mm_fmadd_pd(_mm_set1_pd(std::numeric_limits<double>::infinity()), x, y))", f278, 2, 128},
  {"128:_mm_sub_pd(_mm_setzero_pd(), _mm_fmadd_pd(_mm_set1_pd(std::numeric_limits<double>::infinity()), x, y))", f279, 2, 128},
  {"128:_mm_mul_pd(_mm_fmadd_pd(_mm_set1_pd(std::numeric_limits<double>::infinity()), x, y), _mm_set1_pd(-1.0))", f280, 2, 128},
  {"128:_mm_floor_pd(_mm_fmadd_pd(_mm_set1_pd(std::numeric_limits<double>::infinity()), x, y))", f281, 2, 128},
  {"128:_mm_ceil_pd(_mm_fmadd_pd(_mm_set1_pd(std::numeric_limits<double>::infinity()), x, y))", f282, 2, 128},
  {"128:_mm_round_pd(_mm_fmadd_pd(_mm_set1_pd(std::numeric_limits<double>::infinity()), x, y), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)", f283, 2, 128},
  {"128:_mm_permute_pd(_mm_fmadd_pd(_mm_set1_pd(std::numeric_limits<double>::infinity()), x, y), 0x5)", f284, 2, 128},
  {"128:_mm_permute_pd(_mm_fmadd_pd(_mm_set1_pd(std::numeric_limits<double>::infinity()), x, y), 0xa)", f285, 2, 128},
  {"128:_mm_permute_pd(_mm_fmadd_pd(_mm_set1_pd(std::numeric_limits<double>::infinity()), x, y), 0x3)", f286, 2, 128},
  {"128:_mm_sqrt_pd(_mm_fmadd_pd(x, y, _mm_set1_pd(std::numeric_limits<double>::quiet_NaN())))", f287, 2, 128},
  {"128:_mm_xor_pd(_mm_fmadd_pd(x, y, _mm_set1_pd(std::numeric_limits<double>::quiet_NaN())), _mm_set1_pd(-0.0))", f288, 2, 128},
  {"128:_mm_andnot_pd(_mm_set1_pd(-0.0), _mm_fmadd_pd(x, y, _mm_set1_pd(std::numeric_limits<double>::quiet_NaN())))", f289, 2, 128},
  {"128:_mm_sub_pd(_mm_setzero_pd(), _mm_fmadd_pd(x, y, _mm_set1_pd(std::numeric_limits<double>::quiet_NaN())))", f290, 2, 128},
  {"128:_mm_mul_pd(_mm_fmadd_pd(x, y, _mm_set1_pd(std::numeric_limits<double>::quiet_NaN())), _mm_set1_pd(-1.0))", f291, 2, 128},
  {"128:_mm_floor_pd(_mm_fmadd_pd(x, y, _mm_set1_pd(std::numeric_limits<double>::quiet_NaN())))", f292, 2, 128},
  {"128:_mm_ceil_pd(_mm_fmadd_pd(x, y, _mm_set1_pd(std::numeric_limits<double>::quiet_NaN())))", f293, 2, 128},
  {"128:_mm_round_pd(_mm_fmadd_pd(x, y, _mm_set1_pd(std::numeric_limits<double>::quiet_NaN())), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)", f294, 2, 128},
  {"128:_mm_permute_pd(_mm_fmadd_pd(x, y, _mm_set1_pd(std::numeric_limits<double>::quiet_NaN())), 0x5)", f295, 2, 128},
  {"128:_mm_permute_pd(_mm_fmadd_pd(x, y, _mm_set1_pd(std::numeric_limits<double>::quiet_NaN())), 0xa)", f296, 2, 128},
  {"128:_mm_permute_pd(_mm_fmadd_pd(x, y, _mm_set1_pd(std::numeric_limits<double>::quiet_NaN())), 0x3)", f297, 2, 128},
  {"128:_mm_sqrt_pd(_mm_fmadd_pd(x, _mm_set1_pd(std::numeric_limits<double>::quiet_NaN()), y))", f298, 2, 128},
  {"128:_mm_xor_pd(_mm_fmadd_pd(x, _mm_set1_pd(std::numeric_limits<double>::quiet_NaN()), y), _mm_set1_pd(-0.0))", f299, 2, 128},
  {"128:_mm_andnot_pd(_mm_set1_pd(-0.0), _mm_fmadd_pd(x, _mm_set1_pd(std::numeric_limits<double>::quiet_NaN()), y))", f300, 2, 128},
  {"128:_mm_sub_pd(_mm_setzero_pd(), _mm_fmadd_pd(x, _mm_set1_pd(std::numeric_limits<double>::quiet_NaN()), y))", f301, 2, 128},
  {"128:_mm_mul_pd(_mm_fmadd_pd(x, _mm_set1_pd(std::numeric_limits<double>::quiet_NaN()), y), _mm_set1_pd(-1.0))", f302, 2, 128},
  {"128:_mm_floor_pd(_mm_fmadd_pd(x, _mm_set1_pd(std::numeric_limits<double>::quiet_NaN()), y))", f303, 2, 128},
  {"128:_mm_ceil_pd(_mm_fmadd_pd(x, _mm_set1_pd(std::numeric_limits<double>::quiet_NaN()), y))", f304, 2, 128},
  {"128:_mm_round_pd(_mm_fmadd_pd(x, _mm_set1_pd(std::numeric_limits<double>::quiet_NaN()), y), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)", f305, 2, 128},
  {"128:_mm_permute_pd(_mm_fmadd_pd(x, _mm_set1_pd(std::numeric_limits<double>::quiet_NaN()), y), 0x5)", f306, 2, 128},
  {"128:_mm_permute_pd(_mm_fmadd_pd(x, _mm_set1_pd(std::numeric_limits<double>::quiet_NaN()), y), 0xa)", f307, 2, 128},
  {"128:_mm_permute_pd(_mm_fmadd_pd(x, _mm_set1_pd(std::numeric_limits<double>::quiet_NaN()), y), 0x3)", f308, 2, 128},
  {"128:_mm_sqrt_pd(_mm_fmadd_pd(_mm_set1_pd(std::numeric_limits<double>::quiet_NaN()), x, y))", f309, 2, 128},
  {"128:_mm_xor_pd(_mm_fmadd_pd(_mm_set1_pd(std::numeric_limits<double>::quiet_NaN()), x, y), _mm_set1_pd(-0.0))", f310, 2, 128},
  {"128:_mm_andnot_pd(_mm_set1_pd(-0.0), _mm_fmadd_pd(_mm_set1_pd(std::numeric_limits<double>::quiet_NaN()), x, y))", f311, 2, 128},
  {"128:_mm_sub_pd(_mm_setzero_pd(), _mm_fmadd_pd(_mm_set1_pd(std::numeric_limits<double>::quiet_NaN()), x, y))", f312, 2, 128},
  {"128:_mm_mul_pd(_mm_fmadd_pd(_mm_set1_pd(std::numeric_limits<double>::quiet_NaN()), x, y), _mm_set1_pd(-1.0))", f313, 2, 128},
  {"128:_mm_floor_pd(_mm_fmadd_pd(_mm_set1_pd(std::numeric_limits<double>::quiet_NaN()), x, y))", f314, 2, 128},
  {"128:_mm_ceil_pd(_mm_fmadd_pd(_mm_set1_pd(std::numeric_limits<double>::quiet_NaN()), x, y))", f315, 2, 128},
  {"128:_mm_round_pd(_mm_fmadd_pd(_mm_set1_pd(std::numeric_limits<double>::quiet_NaN()), x, y), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)", f316, 2, 128},
  {"128:_mm_permute_pd(_mm_fmadd_pd(_mm_set1_pd(std::numeric_limits<double>::quiet_NaN()), x, y), 0x5)", f317, 2, 128},
  {"128:_mm_permute_pd(_mm_fmadd_pd(_mm_set1_pd(std::numeric_limits<double>::quiet_NaN()), x, y), 0xa)", f318, 2, 128},
  {"128:_mm_permute_pd(_mm_fmadd_pd(_mm_set1_pd(std::numeric_limits<double>::quiet_NaN()), x, y), 0x3)", f319, 2, 128},
  {"128:_mm_sqrt_pd(_mm_fmadd_pd(x, y, x))", f320, 2, 128},
  {"128:_mm_xor_pd(_mm_fmadd_pd(x, y, x), _mm_set1_pd(-0.0))", f321, 2, 128},
  {"128:_mm_andnot_pd(_mm_set1_pd(-0.0), _mm_fmadd_pd(x, y, x))", f322, 2, 128},
  {"128:_mm_sub_pd(_mm_setzero_pd(), _mm_fmadd_pd(x, y, x))", f323, 2, 128},
  {"128:_mm_mul_pd(_mm_fmadd_pd(x, y, x), _mm_set1_pd(-1.0))", f324, 2, 128},
  {"128:_mm_floor_pd(_mm_fmadd_pd(x, y, x))", f325, 2, 128},
  {"128:_mm_ceil_pd(_mm_fmadd_pd(x, y, x))", f326, 2, 128},
  {"128:_mm_round_pd(_mm_fmadd_pd(x, y, x), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)", f327, 2, 128},
  {"128:_mm_permute_pd(_mm_fmadd_pd(x, y, x), 0x5)", f328, 2, 128},
  {"128:_mm_permute_pd(_mm_fmadd_pd(x, y, x), 0xa)", f329, 2, 128},
  {"128:_mm_permute_pd(_mm_fmadd_pd(x, y, x), 0x3)", f330, 2, 128},
  {"128:_mm_sqrt_pd(_mm_fmadd_pd(x, x, y))", f331, 2, 128},
  {"128:_mm_xor_pd(_mm_fmadd_pd(x, x, y), _mm_set1_pd(-0.0))", f332, 2, 128},
  {"128:_mm_andnot_pd(_mm_set1_pd(-0.0), _mm_fmadd_pd(x, x, y))", f333, 2, 128},
  {"128:_mm_sub_pd(_mm_setzero_pd(), _mm_fmadd_pd(x, x, y))", f334, 2, 128},
  {"128:_mm_mul_pd(_mm_fmadd_pd(x, x, y), _mm_set1_pd(-1.0))", f335, 2, 128},
  {"128:_mm_floor_pd(_mm_fmadd_pd(x, x, y))", f336, 2, 128},
  {"128:_mm_ceil_pd(_mm_fmadd_pd(x, x, y))", f337, 2, 128},
  {"128:_mm_round_pd(_mm_fmadd_pd(x, x, y), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)", f338, 2, 128},
  {"128:_mm_permute_pd(_mm_fmadd_pd(x, x, y), 0x5)", f339, 2, 128},
  {"128:_mm_permute_pd(_mm_fmadd_pd(x, x, y), 0xa)", f340, 2, 128},
  {"128:_mm_permute_pd(_mm_fmadd_pd(x, x, y), 0x3)", f341, 2, 128},
  {"128:_mm_sqrt_pd(_mm_fmadd_pd(x, y, _mm_mul_pd(x, y)))", f342, 2, 128},
  {"128:_mm_xor_pd(_mm_fmadd_pd(x, y, _mm_mul_pd(x, y)), _mm_set1_pd(-0.0))", f343, 2, 128},
  {"128:_mm_andnot_pd(_mm_set1_pd(-0.0), _mm_fmadd_pd(x, y, _mm_mul_pd(x, y)))", f344, 2, 128},
  {"128:_mm_sub_pd(_mm_setzero_pd(), _mm_fmadd_pd(x, y, _mm_mul_pd(x, y)))", f345, 2, 128},
  {"128:_mm_mul_pd(_mm_fmadd_pd(x, y, _mm_mul_pd(x, y)), _mm_set1_pd(-1.0))", f346, 2, 128},
  {"128:_mm_floor_pd(_mm_fmadd_pd(x, y, _mm_mul_pd(x, y)))", f347, 2, 128},
  {"128:_mm_ceil_pd(_mm_fmadd_pd(x, y, _mm_mul_pd(x, y)))", f348, 2, 128},
  {"128:_mm_round_pd(_mm_fmadd_pd(x, y, _mm_mul_pd(x, y)), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)", f349, 2, 128},
  {"128:_mm_permute_pd(_mm_fmadd_pd(x, y, _mm_mul_pd(x, y)), 0x5)", f350, 2, 128},
  {"128:_mm_permute_pd(_mm_fmadd_pd(x, y, _mm_mul_pd(x, y)), 0xa)", f351, 2, 128},
  {"128:_mm_permute_pd(_mm_fmadd_pd(x, y, _mm_mul_pd(x, y)), 0x3)", f352, 2, 128},
  {"128:_mm_sqrt_pd(_mm_fmsub_pd(x, y, _mm_setzero_pd()))", f353, 2, 128},
  {"128:_mm_xor_pd(_mm_fmsub_pd(x, y, _mm_setzero_pd()), _mm_set1_pd(-0.0))", f354, 2, 128},
  {"128:_mm_andnot_pd(_mm_set1_pd(-0.0), _mm_fmsub_pd(x, y, _mm_setzero_pd()))", f355, 2, 128},
  {"128:_mm_sub_pd(_mm_setzero_pd(), _mm_fmsub_pd(x, y, _mm_setzero_pd()))", f356, 2, 128},
  {"128:_mm_mul_pd(_mm_fmsub_pd(x, y, _mm_setzero_pd()), _mm_set1_pd(-1.0))", f357, 2, 128},
  {"128:_mm_floor_pd(_mm_fmsub_pd(x, y, _mm_setzero_pd()))", f358, 2, 128},
  {"128:_mm_ceil_pd(_mm_fmsub_pd(x, y, _mm_setzero_pd()))", f359, 2, 128},
  {"128:_mm_round_pd(_mm_fmsub_pd(x, y, _mm_setzero_pd()), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)", f360, 2, 128},
  {"128:_mm_permute_pd(_mm_fmsub_pd(x, y, _mm_setzero_pd()), 0x5)", f361, 2, 128},
  {"128:_mm_permute_pd(_mm_fmsub_pd(x, y, _mm_setzero_pd()), 0xa)", f362, 2, 128},
  {"128:_mm_permute_pd(_mm_fmsub_pd(x, y, _mm_setzero_pd()), 0x3)", f363, 2, 128},
  {"128:_mm_sqrt_pd(_mm_fmsub_pd(x, _mm_setzero_pd(), y))", f364, 2, 128},
  {"128:_mm_xor_pd(_mm_fmsub_pd(x, _mm_setzero_pd(), y), _mm_set1_pd(-0.0))", f365, 2, 128},
  {"128:_mm_andnot_pd(_mm_set1_pd(-0.0), _mm_fmsub_pd(x, _mm_setzero_pd(), y))", f366, 2, 128},
  {"128:_mm_sub_pd(_mm_setzero_pd(), _mm_fmsub_pd(x, _mm_setzero_pd(), y))", f367, 2, 128},
  {"128:_mm_mul_pd(_mm_fmsub_pd(x, _mm_setzero_pd(), y), _mm_set1_pd(-1.0))", f368, 2, 128},
  {"128:_mm_floor_pd(_mm_fmsub_pd(x, _mm_setzero_pd(), y))", f369, 2, 128},
  {"128:_mm_ceil_pd(_mm_fmsub_pd(x, _mm_setzero_pd(), y))", f370, 2, 128},
  {"128:_mm_round_pd(_mm_fmsub_pd(x, _mm_setzero_pd(), y), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)", f371, 2, 128},
  {"128:_mm_permute_pd(_mm_fmsub_pd(x, _mm_setzero_pd(), y), 0x5)", f372, 2, 128},
  {"128:_mm_permute_pd(_mm_fmsub_pd(x, _mm_setzero_pd(), y), 0xa)", f373, 2, 128},
  {"128:_mm_permute_pd(_mm_fmsub_pd(x, _mm_setzero_pd(), y), 0x3)", f374, 2, 128},
  {"128:_mm_sqrt_pd(_mm_fmsub_pd(_mm_setzero_pd(), x, y))", f375, 2, 128},
  {"128:_mm_xor_pd(_mm_fmsub_pd(_mm_setzero_pd(), x, y), _mm_set1_pd(-0.0))", f376, 2, 128},
  {"128:_mm_andnot_pd(_mm_set1_pd(-0.0), _mm_fmsub_pd(_mm_setzero_pd(), x, y))", f377, 2, 128},
  {"128:_mm_sub_pd(_mm_setzero_pd(), _mm_fmsub_pd(_mm_setzero_pd(), x, y))", f378, 2, 128},
  {"128:_mm_mul_pd(_mm_fmsub_pd(_mm_setzero_pd(), x, y), _mm_set1_pd(-1.0))", f379, 2, 128},
  {"128:_mm_floor_pd(_mm_fmsub_pd(_mm_setzero_pd(), x, y))", f380, 2, 128},
  {"128:_mm_ceil_pd(_mm_fmsub_pd(_mm_setzero_pd(), x, y))", f381, 2, 128},
  {"128:_mm_round_pd(_mm_fmsub_pd(_mm_setzero_pd(), x, y), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)", f382, 2, 128},
  {"128:_mm_permute_pd(_mm_fmsub_pd(_mm_setzero_pd(), x, y), 0x5)", f383, 2, 128},
  {"128:_mm_permute_pd(_mm_fmsub_pd(_mm_setzero_pd(), x, y), 0xa)", f384, 2, 128},
  {"128:_mm_permute_pd(_mm_fmsub_pd(_mm_setzero_pd(), x, y), 0x3)", f385, 2, 128},
  {"128:_mm_sqrt_pd(_mm_fmsub_pd(x, y, _mm_set1_pd(-0.0)))", f386, 2, 128},
  {"128:_mm_xor_pd(_mm_fmsub_pd(x, y, _mm_set1_pd(-0.0)), _mm_set1_pd(-0.0))", f387, 2, 128},
  {"128:_mm_andnot_pd(_mm_set1_pd(-0.0), _mm_fmsub_pd(x, y, _mm_set1_pd(-0.0)))", f388, 2, 128},
  {"128:_mm_sub_pd(_mm_setzero_pd(), _mm_fmsub_pd(x, y, _mm_set1_pd(-0.0)))", f389, 2, 128},
  {"128:_mm_mul_pd(_mm_fmsub_pd(x, y, _mm_set1_pd(-0.0)), _mm_set1_pd(-1.0))", f390, 2, 128},
  {"128:_mm_floor_pd(_mm_fmsub_pd(x, y, _mm_set1_pd(-0.0)))", f391, 2, 128},
  {"128:_mm_ceil_pd(_mm_fmsub_pd(x, y, _mm_set1_pd(-0.0)))", f392, 2, 128},
  {"128:_mm_round_pd(_mm_fmsub_pd(x, y, _mm_set1_pd(-0.0)), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)", f393, 2, 128},
  {"128:_mm_permute_pd(_mm_fmsub_pd(x, y, _mm_set1_pd(-0.0)), 0x5)", f394, 2, 128},
  {"128:_mm_permute_pd(_mm_fmsub_pd(x, y, _mm_set1_pd(-0.0)), 0xa)", f395, 2, 128},
  {"128:_mm_permute_pd(_mm_fmsub_pd(x, y, _mm_set1_pd(-0.0)), 0x3)", f396, 2, 128},
  {"128:_mm_sqrt_pd(_mm_fmsub_pd(x, _mm_set1_pd(-0.0), y))", f397, 2, 128},
  {"128:_mm_xor_pd(_mm_fmsub_pd(x, _mm_set1_pd(-0.0), y), _mm_set1_pd(-0.0))", f398, 2, 128},
  {"128:_mm_andnot_pd(_mm_set1_pd(-0.0), _mm_fmsub_pd(x, _mm_set1_pd(-0.0), y))", f399, 2, 128},
  {"128:_mm_sub_pd(_mm_setzero_pd(), _mm_fmsub_pd(x, _mm_set1_pd(-0.0), y))", f400, 2, 128},
  {"128:_mm_mul_pd(_mm_fmsub_pd(x, _mm_set1_pd(-0.0), y), _mm_set1_pd(-1.0))", f401, 2, 128},
  {"128:_mm_floor_pd(_mm_fmsub_pd(x, _mm_set1_pd(-0.0), y))", f402, 2, 128},
  {"128:_mm_ceil_pd(_mm_fmsub_pd(x, _mm_set1_pd(-0.0), y))", f403, 2, 128},
  {"128:_mm_round_pd(_mm_fmsub_pd(x, _mm_set1_pd(-0.0), y), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)", f404, 2, 128},
  {"128:_mm_permute_pd(_mm_fmsub_pd(x, _mm_set1_pd(-0.0), y), 0x5)", f405, 2, 128},
  {"128:_mm_permute_pd(_mm_fmsub_pd(x, _mm_set1_pd(-0.0), y), 0xa)", f406, 2, 128},
  {"128:_mm_permute_pd(_mm_fmsub_pd(x, _mm_set1_pd(-0.0), y), 0x3)", f407, 2, 128},
  {"128:_mm_sqrt_pd(_mm_fmsub_pd(_mm_set1_pd(-0.0), x, y))", f408, 2, 128},
  {"128:_mm_xor_pd(_mm_fmsub_pd(_mm_set1_pd(-0.0), x, y), _mm_set1_pd(-0.0))", f409, 2, 128},
  {"128:_mm_andnot_pd(_mm_set1_pd(-0.0), _mm_fmsub_pd(_mm_set1_pd(-0.0), x, y))", f410, 2, 128},
  {"128:_mm_sub_pd(_mm_setzero_pd(), _mm_fmsub_pd(_mm_set1_pd(-0.0), x, y))", f411, 2, 128},
  {"128:_mm_mul_pd(_mm_fmsub_pd(_mm_set1_pd(-0.0), x, y), _mm_set1_pd(-1.0))", f412, 2, 128},
  {"128:_mm_floor_pd(_mm_fmsub_pd(_mm_set1_pd(-0.0), x, y))", f413, 2, 128},
  {"128:_mm_ceil_pd(_mm_fmsub_pd(_mm_set1_pd(-0.0), x, y))", f414, 2, 128},
  {"128:_mm_round_pd(_mm_fmsub_pd(_mm_set1_pd(-0.0), x, y), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)", f415, 2, 128},
  {"128:_mm_permute_pd(_mm_fmsub_pd(_mm_set1_pd(-0.0), x, y), 0x5)", f416, 2, 128},
  {"128:_mm_permute_pd(_mm_fmsub_pd(_mm_set1_pd(-0.0), x, y), 0xa)", f417, 2, 128},
  {"128:_mm_permute_pd(_mm_fmsub_pd(_mm_set1_pd(-0.0), x, y), 0x3)", f418, 2, 128},
  {"128:_mm_sqrt_pd(_mm_fmsub_pd(x, y, _mm_set1_pd(1.0)))", f419, 2, 128},
  {"128:_mm_xor_pd(_mm_fmsub_pd(x, y, _mm_set1_pd(1.0)), _mm_set1_pd(-0.0))", f420, 2, 128},
  {"128:_mm_andnot_pd(_mm_set1_pd(-0.0), _mm_fmsub_pd(x, y, _mm_set1_pd(1.0)))", f421, 2, 128},
  {"128:_mm_sub_pd(_mm_setzero_pd(), _mm_fmsub_pd(x, y, _mm_set1_pd(1.0)))", f422, 2, 128},
  {"128:_mm_mul_pd(_mm_fmsub_pd(x, y, _mm_set1_pd(1.0)), _mm_set1_pd(-1.0))", f423, 2, 128},
  {"128:_mm_floor_pd(_mm_fmsub_pd(x, y, _mm_set1_pd(1.0)))", f424, 2, 128},
  {"128:_mm_ceil_pd(_mm_fmsub_pd(x, y, _mm_set1_pd(1.0)))", f425, 2, 128},
  {"128:_mm_round_pd(_mm_fmsub_pd(x, y, _mm_set1_pd(1.0)), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)", f426, 2, 128},
  {"128:_mm_permute_pd(_mm_fmsub_pd(x, y, _mm_set1_pd(1.0)), 0x5)", f427, 2, 128},
  {"128:_mm_permute_pd(_mm_fmsub_pd(x, y, _mm_set1_pd(1.0)), 0xa)", f428, 2, 128},
  {"128:_mm_permute_pd(_mm_fmsub_pd(x, y, _mm_set1_pd(1.0)), 0x3)", f429, 2, 128},
  {"128:_mm_sqrt_pd(_mm_fmsub_pd(x, _mm_set1_pd(1.0), y))", f430, 2, 128},
  {"128:_mm_xor_pd(_mm_fmsub_pd(x, _mm_set1_pd(1.0), y), _mm_set1_pd(-0.0))", f431, 2, 128},
  {"128:_mm_andnot_pd(_mm_set1_pd(-0.0), _mm_fmsub_pd(x, _mm_set1_pd(1.0), y))", f432, 2, 128},
  {"128:_mm_sub_pd(_mm_setzero_pd(), _mm_fmsub_pd(x, _mm_set1_pd(1.0), y))", f433, 2, 128},
  {"128:_mm_mul_pd(_mm_fmsub_pd(x, _mm_set1_pd(1.0), y), _mm_set1_pd(-1.0))", f434, 2, 128},
  {"128:_mm_floor_pd(_mm_fmsub_pd(x, _mm_set1_pd(1.0), y))", f435, 2, 128},
  {"128:_mm_ceil_pd(_mm_fmsub_pd(x, _mm_set1_pd(1.0), y))", f436, 2, 128},
  {"128:_mm_round_pd(_mm_fmsub_pd(x, _mm_set1_pd(1.0), y), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)", f437, 2, 128},
  {"128:_mm_permute_pd(_mm_fmsub_pd(x, _mm_set1_pd(1.0), y), 0x5)", f438, 2, 128},
  {"128:_mm_permute_pd(_mm_fmsub_pd(x, _mm_set1_pd(1.0), y), 0xa)", f439, 2, 128},
  {"128:_mm_permute_pd(_mm_fmsub_pd(x, _mm_set1_pd(1.0), y), 0x3)", f440, 2, 128},
  {"128:_mm_sqrt_pd(_mm_fmsub_pd(_mm_set1_pd(1.0), x, y))", f441, 2, 128},
  {"128:_mm_xor_pd(_mm_fmsub_pd(_mm_set1_pd(1.0), x, y), _mm_set1_pd(-0.0))", f442, 2, 128},
  {"128:_mm_andnot_pd(_mm_set1_pd(-0.0), _mm_fmsub_pd(_mm_set1_pd(1.0), x, y))", f443, 2, 128},
  {"128:_mm_sub_pd(_mm_setzero_pd(), _mm_fmsub_pd(_mm_set1_pd(1.0), x, y))", f444, 2, 128},
  {"128:_mm_mul_pd(_mm_fmsub_pd(_mm_set1_pd(1.0), x, y), _mm_set1_pd(-1.0))", f445, 2, 128},
  {"128:_mm_floor_pd(_mm_fmsub_pd(_mm_set1_pd(1.0), x, y))", f446, 2, 128},
  {"128:_mm_ceil_pd(_mm_fmsub_pd(_mm_set1_pd(1.0), x, y))", f447, 2, 128},
  {"128:_mm_round_pd(_mm_fmsub_pd(_mm_set1_pd(1.0), x, y), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)", f448, 2, 128},
  {"128:_mm_permute_pd(_mm_fmsub_pd(_mm_set1_pd(1.0), x, y), 0x5)", f449, 2, 128},
  {"128:_mm_permute_pd(_mm_fmsub_pd(_mm_set1_pd(1.0), x, y), 0xa)", f450, 2, 128},
  {"128:_mm_permute_pd(_mm_fmsub_pd(_mm_set1_pd(1.0), x, y), 0x3)", f451, 2, 128},
  {"128:_mm_sqrt_pd(_mm_fmsub_pd(x, y, _mm_set1_pd(-1.0)))", f452, 2, 128},
  {"128:_mm_xor_pd(_mm_fmsub_pd(x, y, _mm_set1_pd(-1.0)), _mm_set1_pd(-0.0))", f453, 2, 128},
  {"128:_mm_andnot_pd(_mm_set1_pd(-0.0), _mm_fmsub_pd(x, y, _mm_set1_pd(-1.0)))", f454, 2, 128},
  {"128:_mm_sub_pd(_mm_setzero_pd(), _mm_fmsub_pd(x, y, _mm_set1_pd(-1.0)))", f455, 2, 128},
  {"128:_mm_mul_pd(_mm_fmsub_pd(x, y, _mm_set1_pd(-1.0)), _mm_set1_pd(-1.0))", f456, 2, 128},
  {"128:_mm_floor_pd(_mm_fmsub_pd(x, y, _mm_set1_pd(-1.0)))", f457, 2, 128},
  {"128:_mm_ceil_pd(_mm_fmsub_pd(x, y, _mm_set1_pd(-1.0)))", f458, 2, 128},
  {"128:_mm_round_pd(_mm_fmsub_pd(x, y, _mm_set1_pd(-1.0)), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)", f459, 2, 128},
  {"128:_mm_permute_pd(_mm_fmsub_pd(x, y, _mm_set1_pd(-1.0)), 0x5)", f460, 2, 128},
  {"128:_mm_permute_pd(_mm_fmsub_pd(x, y, _mm_set1_pd(-1.0)), 0xa)", f461, 2, 128},
  {"128:_mm_permute_pd(_mm_fmsub_pd(x, y, _mm_set1_pd(-1.0)), 0x3)", f462, 2, 128},
  {"128:_mm_sqrt_pd(_mm_fmsub_pd(x, _mm_set1_pd(-1.0), y))", f463, 2, 128},
  {"128:_mm_xor_pd(_mm_fmsub_pd(x, _mm_set1_pd(-1.0), y), _mm_set1_pd(-0.0))", f464, 2, 128},
  {"128:_mm_andnot_pd(_mm_set1_pd(-0.0), _mm_fmsub_pd(x, _mm_set1_pd(-1.0), y))", f465, 2, 128},
  {"128:_mm_sub_pd(_mm_setzero_pd(), _mm_fmsub_pd(x, _mm_set1_pd(-1.0), y))", f466, 2, 128},
  {"128:_mm_mul_pd(_mm_fmsub_pd(x, _mm_set1_pd(-1.0), y), _mm_set1_pd(-1.0))", f467, 2, 128},
  {"128:_mm_floor_pd(_mm_fmsub_pd(x, _mm_set1_pd(-1.0), y))", f468, 2, 128},
  {"128:_mm_ceil_pd(_mm_fmsub_pd(x, _mm_set1_pd(-1.0), y))", f469, 2, 128},
  {"128:_mm_round_pd(_mm_fmsub_pd(x, _mm_set1_pd(-1.0), y), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)", f470, 2, 128},
  {"128:_mm_permute_pd(_mm_fmsub_pd(x, _mm_set1_pd(-1.0), y), 0x5)", f471, 2, 128},
  {"128:_mm_permute_pd(_mm_fmsub_pd(x, _mm_set1_pd(-1.0), y), 0xa)", f472, 2, 128},
  {"128:_mm_permute_pd(_mm_fmsub_pd(x, _mm_set1_pd(-1.0), y), 0x3)", f473, 2, 128},
  {"128:_mm_sqrt_pd(_mm_fmsub_pd(_mm_set1_pd(-1.0), x, y))", f474, 2, 128},
  {"128:_mm_xor_pd(_mm_fmsub_pd(_mm_set1_pd(-1.0), x, y), _mm_set1_pd(-0.0))", f475, 2, 128},
  {"128:_mm_andnot_pd(_mm_set1_pd(-0.0), _mm_fmsub_pd(_mm_set1_pd(-1.0), x, y))", f476, 2, 128},
  {"128:_mm_sub_pd(_mm_setzero_pd(), _mm_fmsub_pd(_mm_set1_pd(-1.0), x, y))", f477, 2, 128},
  {"128:_mm_mul_pd(_mm_fmsub_pd(_mm_set1_pd(-1.0), x, y), _mm_set1_pd(-1.0))", f478, 2, 128},
  {"128:_mm_floor_pd(_mm_fmsub_pd(_mm_set1_pd(-1.0), x, y))", f479, 2, 128},
  {"128:_mm_ceil_pd(_mm_fmsub_pd(_mm_set1_pd(-1.0), x, y))", f480, 2, 128},
  {"128:_mm_round_pd(_mm_fmsub_pd(_mm_set1_pd(-1.0), x, y), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)", f481, 2, 128},
  {"128:_mm_permute_pd(_mm_fmsub_pd(_mm_set1_pd(-1.0), x, y), 0x5)", f482, 2, 128},
  {"128:_mm_permute_pd(_mm_fmsub_pd(_mm_set1_pd(-1.0), x, y), 0xa)", f483, 2, 128},
  {"128:_mm_permute_pd(_mm_fmsub_pd(_mm_set1_pd(-1.0), x, y), 0x3)", f484, 2, 128},
  {"128:_mm_sqrt_pd(_mm_fmsub_pd(x, y, _mm_set1_pd(std::numeric_limits<double>::infinity())))", f485, 2, 128},
  {"128:_mm_xor_pd(_mm_fmsub_pd(x, y, _mm_set1_pd(std::numeric_limits<double>::infinity())), _mm_set1_pd(-0.0))", f486, 2, 128},
  {"128:_mm_andnot_pd(_mm_set1_pd(-0.0), _mm_fmsub_pd(x, y, _mm_set1_pd(std::numeric_limits<double>::infinity())))", f487, 2, 128},
  {"128:_mm_sub_pd(_mm_setzero_pd(), _mm_fmsub_pd(x, y, _mm_set1_pd(std::numeric_limits<double>::infinity())))", f488, 2, 128},
  {"128:_mm_mul_pd(_mm_fmsub_pd(x, y, _mm_set1_pd(std::numeric_limits<double>::infinity())), _mm_set1_pd(-1.0))", f489, 2, 128},
  {"128:_mm_floor_pd(_mm_fmsub_pd(x, y, _mm_set1_pd(std::numeric_limits<double>::infinity())))", f490, 2, 128},
  {"128:_mm_ceil_pd(_mm_fmsub_pd(x, y, _mm_set1_pd(std::numeric_limits<double>::infinity())))", f491, 2, 128},
  {"128:_mm_round_pd(_mm_fmsub_pd(x, y, _mm_set1_pd(std::numeric_limits<double>::infinity())), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)", f492, 2, 128},
  {"128:_mm_permute_pd(_mm_fmsub_pd(x, y, _mm_set1_pd(std::numeric_limits<double>::infinity())), 0x5)", f493, 2, 128},
  {"128:_mm_permute_pd(_mm_fmsub_pd(x, y, _mm_set1_pd(std::numeric_limits<double>::infinity())), 0xa)", f494, 2, 128},
  {"128:_mm_permute_pd(_mm_fmsub_pd(x, y, _mm_set1_pd(std::numeric_limits<double>::infinity())), 0x3)", f495, 2, 128},
  {"128:_mm_sqrt_pd(_mm_fmsub_pd(x, _mm_set1_pd(std::numeric_limits<double>::infinity()), y))", f496, 2, 128},
  {"128:_mm_xor_pd(_mm_fmsub_pd(x, _mm_set1_pd(std::numeric_limits<double>::infinity()), y), _mm_set1_pd(-0.0))", f497, 2, 128},
  {"128:_mm_andnot_pd(_mm_set1_pd(-0.0), _mm_fmsub_pd(x, _mm_set1_pd(std::numeric_limits<double>::infinity()), y))", f498, 2, 128},
  {"128:_mm_sub_pd(_mm_setzero_pd(), _mm_fmsub_pd(x, _mm_set1_pd(std::numeric_limits<double>::infinity()), y))", f499, 2, 128},
  {"128:_mm_mul_pd(_mm_fmsub_pd(x, _mm_set1_pd(std::numeric_limits<double>::infinity()), y), _mm_set1_pd(-1.0))", f500, 2, 128},
  {"128:_mm_floor_pd(_mm_fmsub_pd(x, _mm_set1_pd(std::numeric_limits<double>::infinity()), y))", f501, 2, 128},
  {"128:_mm_ceil_pd(_mm_fmsub_pd(x, _mm_set1_pd(std::numeric_limits<double>::infinity()), y))", f502, 2, 128},
  {"128:_mm_round_pd(_mm_fmsub_pd(x, _mm_set1_pd(std::numeric_limits<double>::infinity()), y), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)", f503, 2, 128},
  {"128:_mm_permute_pd(_mm_fmsub_pd(x, _mm_set1_pd(std::numeric_limits<double>::infinity()), y), 0x5)", f504, 2, 128},
  {"128:_mm_permute_pd(_mm_fmsub_pd(x, _mm_set1_pd(std::numeric_limits<double>::infinity()), y), 0xa)", f505, 2, 128},
  {"128:_mm_permute_pd(_mm_fmsub_pd(x, _mm_set1_pd(std::numeric_limits<double>::infinity()), y), 0x3)", f506, 2, 128},
  {"128:_mm_sqrt_pd(_mm_fmsub_pd(_mm_set1_pd(std::numeric_limits<double>::infinity()), x, y))", f507, 2, 128},
  {"128:_mm_xor_pd(_mm_fmsub_pd(_mm_set1_pd(std::numeric_limits<double>::infinity()), x, y), _mm_set1_pd(-0.0))", f508, 2, 128},
  {"128:_mm_andnot_pd(_mm_set1_pd(-0.0), _mm_fmsub_pd(_mm_set1_pd(std::numeric_limits<double>::infinity()), x, y))", f509, 2, 128},
  {"128:_mm_sub_pd(_mm_setzero_pd(), _mm_fmsub_pd(_mm_set1_pd(std::numeric_limits<double>::infinity()), x, y))", f510, 2, 128},
  {"128:_mm_mul_pd(_mm_fmsub_pd(_mm_set1_pd(std::numeric_limits<double>::infinity()), x, y), _mm_set1_pd(-1.0))", f511, 2, 128},
  {"128:_mm_floor_pd(_mm_fmsub_pd(_mm_set1_pd(std::numeric_limits<double>::infinity()), x, y))", f512, 2, 128},
  {"128:_mm_ceil_pd(_mm_fmsub_pd(_mm_set1_pd(std::numeric_limits<double>::infinity()), x, y))", f513, 2, 128},
  {"128:_mm_round_pd(_mm_fmsub_pd(_mm_set1_pd(std::numeric_limits<double>::infinity()), x, y), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)", f514, 2, 128},
  {"128:_mm_permute_pd(_mm_fmsub_pd(_mm_set1_pd(std::numeric_limits<double>::infinity()), x, y), 0x5)", f515, 2, 128},
  {"128:_mm_permute_pd(_mm_fmsub_pd(_mm_set1_pd(std::numeric_limits<double>::infinity()), x, y), 0xa)", f516, 2, 128},
  {"128:_mm_permute_pd(_mm_fmsub_pd(_mm_set1_pd(std::numeric_limits<double>::infinity()), x, y), 0x3)", f517, 2, 128},
  {"128:_mm_sqrt_pd(_mm_fmsub_pd(x, y, _mm_set1_pd(std::numeric_limits<double>::quiet_NaN())))", f518, 2, 128},
  {"128:_mm_xor_pd(_mm_fmsub_pd(x, y, _mm_set1_pd(std::numeric_limits<double>::quiet_NaN())), _mm_set1_pd(-0.0))", f519, 2, 128},
  {"128:_mm_andnot_pd(_mm_set1_pd(-0.0), _mm_fmsub_pd(x, y, _mm_set1_pd(std::numeric_limits<double>::quiet_NaN())))", f520, 2, 128},
  {"128:_mm_sub_pd(_mm_setzero_pd(), _mm_fmsub_pd(x, y, _mm_set1_pd(std::numeric_limits<double>::quiet_NaN())))", f521, 2, 128},
  {"128:_mm_mul_pd(_mm_fmsub_pd(x, y, _mm_set1_pd(std::numeric_limits<double>::quiet_NaN())), _mm_set1_pd(-1.0))", f522, 2, 128},
  {"128:_mm_floor_pd(_mm_fmsub_pd(x, y, _mm_set1_pd(std::numeric_limits<double>::quiet_NaN())))", f523, 2, 128},
  {"128:_mm_ceil_pd(_mm_fmsub_pd(x, y, _mm_set1_pd(std::numeric_limits<double>::quiet_NaN())))", f524, 2, 128},
  {"128:_mm_round_pd(_mm_fmsub_pd(x, y, _mm_set1_pd(std::numeric_limits<double>::quiet_NaN())), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)", f525, 2, 128},
  {"128:_mm_permute_pd(_mm_fmsub_pd(x, y, _mm_set1_pd(std::numeric_limits<double>::quiet_NaN())), 0x5)", f526, 2, 128},
  {"128:_mm_permute_pd(_mm_fmsub_pd(x, y, _mm_set1_pd(std::numeric_limits<double>::quiet_NaN())), 0xa)", f527, 2, 128},
  {"128:_mm_permute_pd(_mm_fmsub_pd(x, y, _mm_set1_pd(std::numeric_limits<double>::quiet_NaN())), 0x3)", f528, 2, 128},
  {"128:_mm_sqrt_pd(_mm_fmsub_pd(x, _mm_set1_pd(std::numeric_limits<double>::quiet_NaN()), y))", f529, 2, 128},
  {"128:_mm_xor_pd(_mm_fmsub_pd(x, _mm_set1_pd(std::numeric_limits<double>::quiet_NaN()), y), _mm_set1_pd(-0.0))", f530, 2, 128},
  {"128:_mm_andnot_pd(_mm_set1_pd(-0.0), _mm_fmsub_pd(x, _mm_set1_pd(std::numeric_limits<double>::quiet_NaN()), y))", f531, 2, 128},
  {"128:_mm_sub_pd(_mm_setzero_pd(), _mm_fmsub_pd(x, _mm_set1_pd(std::numeric_limits<double>::quiet_NaN()), y))", f532, 2, 128},
  {"128:_mm_mul_pd(_mm_fmsub_pd(x, _mm_set1_pd(std::numeric_limits<double>::quiet_NaN()), y), _mm_set1_pd(-1.0))", f533, 2, 128},
  {"128:_mm_floor_pd(_mm_fmsub_pd(x, _mm_set1_pd(std::numeric_limits<double>::quiet_NaN()), y))", f534, 2, 128},
  {"128:_mm_ceil_pd(_mm_fmsub_pd(x, _mm_set1_pd(std::numeric_limits<double>::quiet_NaN()), y))", f535, 2, 128},
  {"128:_mm_round_pd(_mm_fmsub_pd(x, _mm_set1_pd(std::numeric_limits<double>::quiet_NaN()), y), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)", f536, 2, 128},
  {"128:_mm_permute_pd(_mm_fmsub_pd(x, _mm_set1_pd(std::numeric_limits<double>::quiet_NaN()), y), 0x5)", f537, 2, 128},
  {"128:_mm_permute_pd(_mm_fmsub_pd(x, _mm_set1_pd(std::numeric_limits<double>::quiet_NaN()), y), 0xa)", f538, 2, 128},
  {"128:_mm_permute_pd(_mm_fmsub_pd(x, _mm_set1_pd(std::numeric_limits<double>::quiet_NaN()), y), 0x3)", f539, 2, 128},
  {"128:_mm_sqrt_pd(_mm_fmsub_pd(_mm_set1_pd(std::numeric_limits<double>::quiet_NaN()), x, y))", f540, 2, 128},
  {"128:_mm_xor_pd(_mm_fmsub_pd(_mm_set1_pd(std::numeric_limits<double>::quiet_NaN()), x, y), _mm_set1_pd(-0.0))", f541, 2, 128},
  {"128:_mm_andnot_pd(_mm_set1_pd(-0.0), _mm_fmsub_pd(_mm_set1_pd(std::numeric_limits<double>::quiet_NaN()), x, y))", f542, 2, 128},
  {"128:_mm_sub_pd(_mm_setzero_pd(), _mm_fmsub_pd(_mm_set1_pd(std::numeric_limits<double>::quiet_NaN()), x, y))", f543, 2, 128},
  {"128:_mm_mul_pd(_mm_fmsub_pd(_mm_set1_pd(std::numeric_limits<double>::quiet_NaN()), x, y), _mm_set1_pd(-1.0))", f544, 2, 128},
  {"128:_mm_floor_pd(_mm_fmsub_pd(_mm_set1_pd(std::numeric_limits<double>::quiet_NaN()), x, y))", f545, 2, 128},
  {"128:_mm_ceil_pd(_mm_fmsub_pd(_mm_set1_pd(std::numeric_limits<double>::quiet_NaN()), x, y))", f546, 2, 128},
  {"128:_mm_round_pd(_mm_fmsub_pd(_mm_set1_pd(std::numeric_limits<double>::quiet_NaN()), x, y), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)", f547, 2, 128},
  {"128:_mm_permute_pd(_mm_fmsub_pd(_mm_set1_pd(std::numeric_limits<double>::quiet_NaN()), x, y), 0x5)", f548, 2, 128},
  {"128:_mm_permute_pd(_mm_fmsub_pd(_mm_set1_pd(std::numeric_limits<double>::quiet_NaN()), x, y), 0xa)", f549, 2, 128},
  {"128:_mm_permute_pd(_mm_fmsub_pd(_mm_set1_pd(std::numeric_limits<double>::quiet_NaN()), x, y), 0x3)", f550, 2, 128},
  {"128:_mm_sqrt_pd(_mm_fmsub_pd(x, y, x))", f551, 2, 128},
  {"128:_mm_xor_pd(_mm_fmsub_pd(x, y, x), _mm_set1_pd(-0.0))", f552, 2, 128},
  {"128:_mm_andnot_pd(_mm_set1_pd(-0.0), _mm_fmsub_pd(x, y, x))", f553, 2, 128},
  {"128:_mm_sub_pd(_mm_setzero_pd(), _mm_fmsub_pd(x, y, x))", f554, 2, 128},
  {"128:_mm_mul_pd(_mm_fmsub_pd(x, y, x), _mm_set1_pd(-1.0))", f555, 2, 128},
  {"128:_mm_floor_pd(_mm_fmsub_pd(x, y, x))", f556, 2, 128},
  {"128:_mm_ceil_pd(_mm_fmsub_pd(x, y, x))", f557, 2, 128},
  {"128:_mm_round_pd(_mm_fmsub_pd(x, y, x), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)", f558, 2, 128},
  {"128:_mm_permute_pd(_mm_fmsub_pd(x, y, x), 0x5)", f559, 2, 128},
  {"128:_mm_permute_pd(_mm_fmsub_pd(x, y, x), 0xa)", f560, 2, 128},
  {"128:_mm_permute_pd(_mm_fmsub_pd(x, y, x), 0x3)", f561, 2, 128},
  {"128:_mm_sqrt_pd(_mm_fmsub_pd(x, x, y))", f562, 2, 128},
  {"128:_mm_xor_pd(_mm_fmsub_pd(x, x, y), _mm_set1_pd(-0.0))", f563, 2, 128},
  {"128:_mm_andnot_pd(_mm_set1_pd(-0.0), _mm_fmsub_pd(x, x, y))", f564, 2, 128},
  {"128:_mm_sub_pd(_mm_setzero_pd(), _mm_fmsub_pd(x, x, y))", f565, 2, 128},
  {"128:_mm_mul_pd(_mm_fmsub_pd(x, x, y), _mm_set1_pd(-1.0))", f566, 2, 128},
  {"128:_mm_floor_pd(_mm_fmsub_pd(x, x, y))", f567, 2, 128},
  {"128:_mm_ceil_pd(_mm_fmsub_pd(x, x, y))", f568, 2, 128},
  {"128:_mm_round_pd(_mm_fmsub_pd(x, x, y), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)", f569, 2, 128},
  {"128:_mm_permute_pd(_mm_fmsub_pd(x, x, y), 0x5)", f570, 2, 128},
  {"128:_mm_permute_pd(_mm_fmsub_pd(x, x, y), 0xa)", f571, 2, 128},
  {"128:_mm_permute_pd(_mm_fmsub_pd(x, x, y), 0x3)", f572, 2, 128},
  {"128:_mm_sqrt_pd(_mm_fmsub_pd(x, y, _mm_mul_pd(x, y)))", f573, 2, 128},
  {"128:_mm_xor_pd(_mm_fmsub_pd(x, y, _mm_mul_pd(x, y)), _mm_set1_pd(-0.0))", f574, 2, 128},
  {"128:_mm_andnot_pd(_mm_set1_pd(-0.0), _mm_fmsub_pd(x, y, _mm_mul_pd(x, y)))", f575, 2, 128},
  {"128:_mm_sub_pd(_mm_setzero_pd(), _mm_fmsub_pd(x, y, _mm_mul_pd(x, y)))", f576, 2, 128},
  {"128:_mm_mul_pd(_mm_fmsub_pd(x, y, _mm_mul_pd(x, y)), _mm_set1_pd(-1.0))", f577, 2, 128},
  {"128:_mm_floor_pd(_mm_fmsub_pd(x, y, _mm_mul_pd(x, y)))", f578, 2, 128},
  {"128:_mm_ceil_pd(_mm_fmsub_pd(x, y, _mm_mul_pd(x, y)))", f579, 2, 128},
  {"128:_mm_round_pd(_mm_fmsub_pd(x, y, _mm_mul_pd(x, y)), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)", f580, 2, 128},
  {"128:_mm_permute_pd(_mm_fmsub_pd(x, y, _mm_mul_pd(x, y)), 0x5)", f581, 2, 128},
  {"128:_mm_permute_pd(_mm_fmsub_pd(x, y, _mm_mul_pd(x, y)), 0xa)", f582, 2, 128},
  {"128:_mm_permute_pd(_mm_fmsub_pd(x, y, _mm_mul_pd(x, y)), 0x3)", f583, 2, 128},
  {"128:_mm_sqrt_pd(_mm_fnmadd_pd(x, y, _mm_setzero_pd()))", f584, 2, 128},
  {"128:_mm_xor_pd(_mm_fnmadd_pd(x, y, _mm_setzero_pd()), _mm_set1_pd(-0.0))", f585, 2, 128},
  {"128:_mm_andnot_pd(_mm_set1_pd(-0.0), _mm_fnmadd_pd(x, y, _mm_setzero_pd()))", f586, 2, 128},
  {"128:_mm_sub_pd(_mm_setzero_pd(), _mm_fnmadd_pd(x, y, _mm_setzero_pd()))", f587, 2, 128},
  {"128:_mm_mul_pd(_mm_fnmadd_pd(x, y, _mm_setzero_pd()), _mm_set1_pd(-1.0))", f588, 2, 128},
  {"128:_mm_floor_pd(_mm_fnmadd_pd(x, y, _mm_setzero_pd()))", f589, 2, 128},
  {"128:_mm_ceil_pd(_mm_fnmadd_pd(x, y, _mm_setzero_pd()))", f590, 2, 128},
  {"128:_mm_round_pd(_mm_fnmadd_pd(x, y, _mm_setzero_pd()), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)", f591, 2, 128},
  {"128:_mm_permute_pd(_mm_fnmadd_pd(x, y, _mm_setzero_pd()), 0x5)", f592, 2, 128},
  {"128:_mm_permute_pd(_mm_fnmadd_pd(x, y, _mm_setzero_pd()), 0xa)", f593, 2, 128},
  {"128:_mm_permute_pd(_mm_fnmadd_pd(x, y, _mm_setzero_pd()), 0x3)", f594, 2, 128},
  {"128:_mm_sqrt_pd(_mm_fnmadd_pd(x, _mm_setzero_pd(), y))", f595, 2, 128},
  {"128:_mm_xor_pd(_mm_fnmadd_pd(x, _mm_setzero_pd(), y), _mm_set1_pd(-0.0))", f596, 2, 128},
  {"128:_mm_andnot_pd(_mm_set1_pd(-0.0), _mm_fnmadd_pd(x, _mm_setzero_pd(), y))", f597, 2, 128},
  {"128:_mm_sub_pd(_mm_setzero_pd(), _mm_fnmadd_pd(x, _mm_setzero_pd(), y))", f598, 2, 128},
  {"128:_mm_mul_pd(_mm_fnmadd_pd(x, _mm_setzero_pd(), y), _mm_set1_pd(-1.0))", f599, 2, 128},
  {"128:_mm_floor_pd(_mm_fnmadd_pd(x, _mm_setzero_pd(), y))", f600, 2, 128},
  {"128:_mm_ceil_pd(_mm_fnmadd_pd(x, _mm_setzero_pd(), y))", f601, 2, 128},
  {"128:_mm_round_pd(_mm_fnmadd_pd(x, _mm_setzero_pd(), y), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)", f602, 2, 128},
  {"128:_mm_permute_pd(_mm_fnmadd_pd(x, _mm_setzero_pd(), y), 0x5)", f603, 2, 128},
  {"128:_mm_permute_pd(_mm_fnmadd_pd(x, _mm_setzero_pd(), y), 0xa)", f604, 2, 128},
  {"128:_mm_permute_pd(_mm_fnmadd_pd(x, _mm_setzero_pd(), y), 0x3)", f605, 2, 128},
  {"128:_mm_sqrt_pd(_mm_fnmadd_pd(_mm_setzero_pd(), x, y))", f606, 2, 128},
  {"128:_mm_xor_pd(_mm_fnmadd_pd(_mm_setzero_pd(), x, y), _mm_set1_pd(-0.0))", f607, 2, 128},
  {"128:_mm_andnot_pd(_mm_set1_pd(-0.0), _mm_fnmadd_pd(_mm_setzero_pd(), x, y))", f608, 2, 128},
  {"128:_mm_sub_pd(_mm_setzero_pd(), _mm_fnmadd_pd(_mm_setzero_pd(), x, y))", f609, 2, 128},
  {"128:_mm_mul_pd(_mm_fnmadd_pd(_mm_setzero_pd(), x, y), _mm_set1_pd(-1.0))", f610, 2, 128},
  {"128:_mm_floor_pd(_mm_fnmadd_pd(_mm_setzero_pd(), x, y))", f611, 2, 128},
  {"128:_mm_ceil_pd(_mm_fnmadd_pd(_mm_setzero_pd(), x, y))", f612, 2, 128},
  {"128:_mm_round_pd(_mm_fnmadd_pd(_mm_setzero_pd(), x, y), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)", f613, 2, 128},
  {"128:_mm_permute_pd(_mm_fnmadd_pd(_mm_setzero_pd(), x, y), 0x5)", f614, 2, 128},
  {"128:_mm_permute_pd(_mm_fnmadd_pd(_mm_setzero_pd(), x, y), 0xa)", f615, 2, 128},
  {"128:_mm_permute_pd(_mm_fnmadd_pd(_mm_setzero_pd(), x, y), 0x3)", f616, 2, 128},
  {"128:_mm_sqrt_pd(_mm_fnmadd_pd(x, y, _mm_set1_pd(-0.0)))", f617, 2, 128},
  {"128:_mm_xor_pd(_mm_fnmadd_pd(x, y, _mm_set1_pd(-0.0)), _mm_set1_pd(-0.0))", f618, 2, 128},
  {"128:_mm_andnot_pd(_mm_set1_pd(-0.0), _mm_fnmadd_pd(x, y, _mm_set1_pd(-0.0)))", f619, 2, 128},
  {"128:_mm_sub_pd(_mm_setzero_pd(), _mm_fnmadd_pd(x, y, _mm_set1_pd(-0.0)))", f620, 2, 128},
  {"128:_mm_mul_pd(_mm_fnmadd_pd(x, y, _mm_set1_pd(-0.0)), _mm_set1_pd(-1.0))", f621, 2, 128},
  {"128:_mm_floor_pd(_mm_fnmadd_pd(x, y, _mm_set1_pd(-0.0)))", f622, 2, 128},
  {"128:_mm_ceil_pd(_mm_fnmadd_pd(x, y, _mm_set1_pd(-0.0)))", f623, 2, 128},
  {"128:_mm_round_pd(_mm_fnmadd_pd(x, y, _mm_set1_pd(-0.0)), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)", f624, 2, 128},
  {"128:_mm_permute_pd(_mm_fnmadd_pd(x, y, _mm_set1_pd(-0.0)), 0x5)", f625, 2, 128},
  {"128:_mm_permute_pd(_mm_fnmadd_pd(x, y, _mm_set1_pd(-0.0)), 0xa)", f626, 2, 128},
  {"128:_mm_permute_pd(_mm_fnmadd_pd(x, y, _mm_set1_pd(-0.0)), 0x3)", f627, 2, 128},
  {"128:_mm_sqrt_pd(_mm_fnmadd_pd(x, _mm_set1_pd(-0.0), y))", f628, 2, 128},
  {"128:_mm_xor_pd(_mm_fnmadd_pd(x, _mm_set1_pd(-0.0), y), _mm_set1_pd(-0.0))", f629, 2, 128},
  {"128:_mm_andnot_pd(_mm_set1_pd(-0.0), _mm_fnmadd_pd(x, _mm_set1_pd(-0.0), y))", f630, 2, 128},
  {"128:_mm_sub_pd(_mm_setzero_pd(), _mm_fnmadd_pd(x, _mm_set1_pd(-0.0), y))", f631, 2, 128},
  {"128:_mm_mul_pd(_mm_fnmadd_pd(x, _mm_set1_pd(-0.0), y), _mm_set1_pd(-1.0))", f632, 2, 128},
  {"128:_mm_floor_pd(_mm_fnmadd_pd(x, _mm_set1_pd(-0.0), y))", f633, 2, 128},
  {"128:_mm_ceil_pd(_mm_fnmadd_pd(x, _mm_set1_pd(-0.0), y))", f634, 2, 128},
  {"128:_mm_round_pd(_mm_fnmadd_pd(x, _mm_set1_pd(-0.0), y), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)", f635, 2, 128},
  {"128:_mm_permute_pd(_mm_fnmadd_pd(x, _mm_set1_pd(-0.0), y), 0x5)", f636, 2, 128},
  {"128:_mm_permute_pd(_mm_fnmadd_pd(x, _mm_set1_pd(-0.0), y), 0xa)", f637, 2, 128},
  {"128:_mm_permute_pd(_mm_fnmadd_pd(x, _mm_set1_pd(-0.0), y), 0x3)", f638, 2, 128},
  {"128:_mm_sqrt_pd(_mm_fnmadd_pd(_mm_set1_pd(-0.0), x, y))", f639, 2, 128},
  {"128:_mm_xor_pd(_mm_fnmadd_pd(_mm_set1_pd(-0.0), x, y), _mm_set1_pd(-0.0))", f640, 2, 128},
  {"128:_mm_andnot_pd(_mm_set1_pd(-0.0), _mm_fnmadd_pd(_mm_set1_pd(-0.0), x, y))", f641, 2, 128},
  {"128:_mm_sub_pd(_mm_setzero_pd(), _mm_fnmadd_pd(_mm_set1_pd(-0.0), x, y))", f642, 2, 128},
  {"128:_mm_mul_pd(_mm_fnmadd_pd(_mm_set1_pd(-0.0), x, y), _mm_set1_pd(-1.0))", f643, 2, 128},
  {"128:_mm_floor_pd(_mm_fnmadd_pd(_mm_set1_pd(-0.0), x, y))", f644, 2, 128},
  {"128:_mm_ceil_pd(_mm_fnmadd_pd(_mm_set1_pd(-0.0), x, y))", f645, 2, 128},
  {"128:_mm_round_pd(_mm_fnmadd_pd(_mm_set1_pd(-0.0), x, y), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)", f646, 2, 128},
  {"128:_mm_permute_pd(_mm_fnmadd_pd(_mm_set1_pd(-0.0), x, y), 0x5)", f647, 2, 128},
  {"128:_mm_permute_pd(_mm_fnmadd_pd(_mm_set1_pd(-0.0), x, y), 0xa)", f648, 2, 128},
  {"128:_mm_permute_pd(_mm_fnmadd_pd(_mm_set1_pd(-0.0), x, y), 0x3)", f649, 2, 128},
  {"128:_mm_sqrt_pd(_mm_fnmadd_pd(x, y, _mm_set1_pd(1.0)))", f650, 2, 128},
  {"128:_mm_xor_pd(_mm_fnmadd_pd(x, y, _mm_set1_pd(1.0)), _mm_set1_pd(-0.0))", f651, 2, 128},
  {"128:_mm_andnot_pd(_mm_set1_pd(-0.0), _mm_fnmadd_pd(x, y, _mm_set1_pd(1.0)))", f652, 2, 128},
  {"128:_mm_sub_pd(_mm_setzero_pd(), _mm_fnmadd_pd(x, y, _mm_set1_pd(1.0)))", f653, 2, 128},
  {"128:_mm_mul_pd(_mm_fnmadd_pd(x, y, _mm_set1_pd(1.0)), _mm_set1_pd(-1.0))", f654, 2, 128},
  {"128:_mm_floor_pd(_mm_fnmadd_pd(x, y, _mm_set1_pd(1.0)))", f655, 2, 128},
  {"128:_mm_ceil_pd(_mm_fnmadd_pd(x, y, _mm_set1_pd(1.0)))", f656, 2, 128},
  {"128:_mm_round_pd(_mm_fnmadd_pd(x, y, _mm_set1_pd(1.0)), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)", f657, 2, 128},
  {"128:_mm_permute_pd(_mm_fnmadd_pd(x, y, _mm_set1_pd(1.0)), 0x5)", f658, 2, 128},
  {"128:_mm_permute_pd(_mm_fnmadd_pd(x, y, _mm_set1_pd(1.0)), 0xa)", f659, 2, 128},
  {"128:_mm_permute_pd(_mm_fnmadd_pd(x, y, _mm_set1_pd(1.0)), 0x3)", f660, 2, 128},
  {"128:_mm_sqrt_pd(_mm_fnmadd_pd(x, _mm_set1_pd(1.0), y))", f661, 2, 128},
  {"128:_mm_xor_pd(_mm_fnmadd_pd(x, _mm_set1_pd(1.0), y), _mm_set1_pd(-0.0))", f662, 2, 128},
  {"128:_mm_andnot_pd(_mm_set1_pd(-0.0), _mm_fnmadd_pd(x, _mm_set1_pd(1.0), y))", f663, 2, 128},
  {"128:_mm_sub_pd(_mm_setzero_pd(), _mm_fnmadd_pd(x, _mm_set1_pd(1.0), y))", f664, 2, 128},
  {"128:_mm_mul_pd(_mm_fnmadd_pd(x, _mm_set1_pd(1.0), y), _mm_set1_pd(-1.0))", f665, 2, 128},
  {"128:_mm_floor_pd(_mm_fnmadd_pd(x, _mm_set1_pd(1.0), y))", f666, 2, 128},
  {"128:_mm_ceil_pd(_mm_fnmadd_pd(x, _mm_set1_pd(1.0), y))", f667, 2, 128},
  {"128:_mm_round_pd(_mm_fnmadd_pd(x, _mm_set1_pd(1.0), y), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)", f668, 2, 128},
  {"128:_mm_permute_pd(_mm_fnmadd_pd(x, _mm_set1_pd(1.0), y), 0x5)", f669, 2, 128},
  {"128:_mm_permute_pd(_mm_fnmadd_pd(x, _mm_set1_pd(1.0), y), 0xa)", f670, 2, 128},
  {"128:_mm_permute_pd(_mm_fnmadd_pd(x, _mm_set1_pd(1.0), y), 0x3)", f671, 2, 128},
  {"128:_mm_sqrt_pd(_mm_fnmadd_pd(_mm_set1_pd(1.0), x, y))", f672, 2, 128},
  {"128:_mm_xor_pd(_mm_fnmadd_pd(_mm_set1_pd(1.0), x, y), _mm_set1_pd(-0.0))", f673, 2, 128},
  {"128:_mm_andnot_pd(_mm_set1_pd(-0.0), _mm_fnmadd_pd(_mm_set1_pd(1.0), x, y))", f674, 2, 128},
  {"128:_mm_sub_pd(_mm_setzero_pd(), _mm_fnmadd_pd(_mm_set1_pd(1.0), x, y))", f675, 2, 128},
  {"128:_mm_mul_pd(_mm_fnmadd_pd(_mm_set1_pd(1.0), x, y), _mm_set1_pd(-1.0))", f676, 2, 128},
  {"128:_mm_floor_pd(_mm_fnmadd_pd(_mm_set1_pd(1.0), x, y))", f677, 2, 128},
  {"128:_mm_ceil_pd(_mm_fnmadd_pd(_mm_set1_pd(1.0), x, y))", f678, 2, 128},
  {"128:_mm_round_pd(_mm_fnmadd_pd(_mm_set1_pd(1.0), x, y), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)", f679, 2, 128},
  {"128:_mm_permute_pd(_mm_fnmadd_pd(_mm_set1_pd(1.0), x, y), 0x5)", f680, 2, 128},
  {"128:_mm_permute_pd(_mm_fnmadd_pd(_mm_set1_pd(1.0), x, y), 0xa)", f681, 2, 128},
  {"128:_mm_permute_pd(_mm_fnmadd_pd(_mm_set1_pd(1.0), x, y), 0x3)", f682, 2, 128},
  {"128:_mm_sqrt_pd(_mm_fnmadd_pd(x, y, _mm_set1_pd(-1.0)))", f683, 2, 128},
  {"128:_mm_xor_pd(_mm_fnmadd_pd(x, y, _mm_set1_pd(-1.0)), _mm_set1_pd(-0.0))", f684, 2, 128},
  {"128:_mm_andnot_pd(_mm_set1_pd(-0.0), _mm_fnmadd_pd(x, y, _mm_set1_pd(-1.0)))", f685, 2, 128},
  {"128:_mm_sub_pd(_mm_setzero_pd(), _mm_fnmadd_pd(x, y, _mm_set1_pd(-1.0)))", f686, 2, 128},
  {"128:_mm_mul_pd(_mm_fnmadd_pd(x, y, _mm_set1_pd(-1.0)), _mm_set1_pd(-1.0))", f687, 2, 128},
  {"128:_mm_floor_pd(_mm_fnmadd_pd(x, y, _mm_set1_pd(-1.0)))", f688, 2, 128},
  {"128:_mm_ceil_pd(_mm_fnmadd_pd(x, y, _mm_set1_pd(-1.0)))", f689, 2, 128},
  {"128:_mm_round_pd(_mm_fnmadd_pd(x, y, _mm_set1_pd(-1.0)), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)", f690, 2, 128},
  {"128:_mm_permute_pd(_mm_fnmadd_pd(x, y, _mm_set1_pd(-1.0)), 0x5)", f691, 2, 128},
  {"128:_mm_permute_pd(_mm_fnmadd_pd(x, y, _mm_set1_pd(-1.0)), 0xa)", f692, 2, 128},
  {"128:_mm_permute_pd(_mm_fnmadd_pd(x, y, _mm_set1_pd(-1.0)), 0x3)", f693, 2, 128},
  {"128:_mm_sqrt_pd(_mm_fnmadd_pd(x, _mm_set1_pd(-1.0), y))", f694, 2, 128},
  {"128:_mm_xor_pd(_mm_fnmadd_pd(x, _mm_set1_pd(-1.0), y), _mm_set1_pd(-0.0))", f695, 2, 128},
  {"128:_mm_andnot_pd(_mm_set1_pd(-0.0), _mm_fnmadd_pd(x, _mm_set1_pd(-1.0), y))", f696, 2, 128},
  {"128:_mm_sub_pd(_mm_setzero_pd(), _mm_fnmadd_pd(x, _mm_set1_pd(-1.0), y))", f697, 2, 128},
  {"128:_mm_mul_pd(_mm_fnmadd_pd(x, _mm_set1_pd(-1.0), y), _mm_set1_pd(-1.0))", f698, 2, 128},
  {"128:_mm_floor_pd(_mm_fnmadd_pd(x, _mm_set1_pd(-1.0), y))", f699, 2, 128},
  {"128:_mm_ceil_pd(_mm_fnmadd_pd(x, _mm_set1_pd(-1.0), y))", f700, 2, 128},
  {"128:_mm_round_pd(_mm_fnmadd_pd(x, _mm_set1_pd(-1.0), y), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)", f701, 2, 128},
  {"128:_mm_permute_pd(_mm_fnmadd_pd(x, _mm_set1_pd(-1.0), y), 0x5)", f702, 2, 128},
  {"128:_mm_permute_pd(_mm_fnmadd_pd(x, _mm_set1_pd(-1.0), y), 0xa)", f703, 2, 128},
  {"128:_mm_permute_pd(_mm_fnmadd_pd(x, _mm_set1_pd(-1.0), y), 0x3)", f704, 2, 128},
  {"128:_mm_sqrt_pd(_mm_fnmadd_pd(_mm_set1_pd(-1.0), x, y))", f705, 2, 128},
  {"128:_mm_xor_pd(_mm_fnmadd_pd(_mm_set1_pd(-1.0), x, y), _mm_set1_pd(-0.0))", f706, 2, 128},
  {"128:_mm_andnot_pd(_mm_set1_pd(-0.0), _mm_fnmadd_pd(_mm_set1_pd(-1.0), x, y))", f707, 2, 128},
  {"128:_mm_sub_pd(_mm_setzero_pd(), _mm_fnmadd_pd(_mm_set1_pd(-1.0), x, y))", f708, 2, 128},
  {"128:_mm_mul_pd(_mm_fnmadd_pd(_mm_set1_pd(-1.0), x, y), _mm_set1_pd(-1.0))", f709, 2, 128},
  {"128:_mm_floor_pd(_mm_fnmadd_pd(_mm_set1_pd(-1.0), x, y))", f710, 2, 128},
  {"128:_mm_ceil_pd(_mm_fnmadd_pd(_mm_set1_pd(-1.0), x, y))", f711, 2, 128},
  {"128:_mm_round_pd(_mm_fnmadd_pd(_mm_set1_pd(-1.0), x, y), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)", f712, 2, 128},
  {"128:_mm_permute_pd(_mm_fnmadd_pd(_mm_set1_pd(-1.0), x, y), 0x5)", f713, 2, 128},
  {"128:_mm_permute_pd(_mm_fnmadd_pd(_mm_set1_pd(-1.0), x, y), 0xa)", f714, 2, 128},
  {"128:_mm_permute_pd(_mm_fnmadd_pd(_mm_set1_pd(-1.0), x, y), 0x3)", f715, 2, 128},
  {"128:_mm_sqrt_pd(_mm_fnmadd_pd(x, y, _mm_set1_pd(std::numeric_limits<double>::infinity())))", f716, 2, 128},
  {"128:_mm_xor_pd(_mm_fnmadd_pd(x, y, _mm_set1_pd(std::numeric_limits<double>::infinity())), _mm_set1_pd(-0.0))", f717, 2, 128},
  {"128:_mm_andnot_pd(_mm_set1_pd(-0.0), _mm_fnmadd_pd(x, y, _mm_set1_pd(std::numeric_limits<double>::infinity())))", f718, 2, 128},
  {"128:_mm_sub_pd(_mm_setzero_pd(), _mm_fnmadd_pd(x, y, _mm_set1_pd(std::numeric_limits<double>::infinity())))", f719, 2, 128},
  {"128:_mm_mul_pd(_mm_fnmadd_pd(x, y, _mm_set1_pd(std::numeric_limits<double>::infinity())), _mm_set1_pd(-1.0))", f720, 2, 128},
  {"128:_mm_floor_pd(_mm_fnmadd_pd(x, y, _mm_set1_pd(std::numeric_limits<double>::infinity())))", f721, 2, 128},
  {"128:_mm_ceil_pd(_mm_fnmadd_pd(x, y, _mm_set1_pd(std::numeric_limits<double>::infinity())))", f722, 2, 128},
  {"128:_mm_round_pd(_mm_fnmadd_pd(x, y, _mm_set1_pd(std::numeric_limits<double>::infinity())), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)", f723, 2, 128},
  {"128:_mm_permute_pd(_mm_fnmadd_pd(x, y, _mm_set1_pd(std::numeric_limits<double>::infinity())), 0x5)", f724, 2, 128},
  {"128:_mm_permute_pd(_mm_fnmadd_pd(x, y, _mm_set1_pd(std::numeric_limits<double>::infinity())), 0xa)", f725, 2, 128},
  {"128:_mm_permute_pd(_mm_fnmadd_pd(x, y, _mm_set1_pd(std::numeric_limits<double>::infinity())), 0x3)", f726, 2, 128},
  {"128:_mm_sqrt_pd(_mm_fnmadd_pd(x, _mm_set1_pd(std::numeric_limits<double>::infinity()), y))", f727, 2, 128},
  {"128:_mm_xor_pd(_mm_fnmadd_pd(x, _mm_set1_pd(std::numeric_limits<double>::infinity()), y), _mm_set1_pd(-0.0))", f728, 2, 128},
  {"128:_mm_andnot_pd(_mm_set1_pd(-0.0), _mm_fnmadd_pd(x, _mm_set1_pd(std::numeric_limits<double>::infinity()), y))", f729, 2, 128},
  {"128:_mm_sub_pd(_mm_setzero_pd(), _mm_fnmadd_pd(x, _mm_set1_pd(std::numeric_limits<double>::infinity()), y))", f730, 2, 128},
  {"128:_mm_mul_pd(_mm_fnmadd_pd(x, _mm_set1_pd(std::numeric_limits<double>::infinity()), y), _mm_set1_pd(-1.0))", f731, 2, 128},
  {"128:_mm_floor_pd(_mm_fnmadd_pd(x, _mm_set1_pd(std::numeric_limits<double>::infinity()), y))", f732, 2, 128},
  {"128:_mm_ceil_pd(_mm_fnmadd_pd(x, _mm_set1_pd(std::numeric_limits<double>::infinity()), y))", f733, 2, 128},
  {"128:_mm_round_pd(_mm_fnmadd_pd(x, _mm_set1_pd(std::numeric_limits<double>::infinity()), y), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)", f734, 2, 128},
  {"128:_mm_permute_pd(_mm_fnmadd_pd(x, _mm_set1_pd(std::numeric_limits<double>::infinity()), y), 0x5)", f735, 2, 128},
  {"128:_mm_permute_pd(_mm_fnmadd_pd(x, _mm_set1_pd(std::numeric_limits<double>::infinity()), y), 0xa)", f736, 2, 128},
  {"128:_mm_permute_pd(_mm_fnmadd_pd(x, _mm_set1_pd(std::numeric_limits<double>::infinity()), y), 0x3)", f737, 2, 128},
  {"128:_mm_sqrt_pd(_mm_fnmadd_pd(_mm_set1_pd(std::numeric_limits<double>::infinity()), x, y))", f738, 2, 128},
  {"128:_mm_xor_pd(_mm_fnmadd_pd(_mm_set1_pd(std::numeric_limits<double>::infinity()), x, y), _mm_set1_pd(-0.0))", f739, 2, 128},
  {"128:_mm_andnot_pd(_mm_set1_pd(-0.0), _mm_fnmadd_pd(_mm_set1_pd(std::numeric_limits<double>::infinity()), x, y))", f740, 2, 128},
  {"128:_mm_sub_pd(_mm_setzero_pd(), _mm_fnmadd_pd(_mm_set1_pd(std::numeric_limits<double>::infinity()), x, y))", f741, 2, 128},
  {"128:_mm_mul_pd(_mm_fnmadd_pd(_mm_set1_pd(std::numeric_limits<double>::infinity()), x, y), _mm_set1_pd(-1.0))", f742, 2, 128},
  {"128:_mm_floor_pd(_mm_fnmadd_pd(_mm_set1_pd(std::numeric_limits<double>::infinity()), x, y))", f743, 2, 128},
  {"128:_mm_ceil_pd(_mm_fnmadd_pd(_mm_set1_pd(std::numeric_limits<double>::infinity()), x, y))", f744, 2, 128},
  {"128:_mm_round_pd(_mm_fnmadd_pd(_mm_set1_pd(std::numeric_limits<double>::infinity()), x, y), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)", f745, 2, 128},
  {"128:_mm_permute_pd(_mm_fnmadd_pd(_mm_set1_pd(std::numeric_limits<double>::infinity()), x, y), 0x5)", f746, 2, 128},
  {"128:_mm_permute_pd(_mm_fnmadd_pd(_mm_set1_pd(std::numeric_limits<double>::infinity()), x, y), 0xa)", f747, 2, 128},
  {"128:_mm_permute_pd(_mm_fnmadd_pd(_mm_set1_pd(std::numeric_limits<double>::infinity()), x, y), 0x3)", f748, 2, 128},
  {"128:_mm_sqrt_pd(_mm_fnmadd_pd(x, y, _mm_set1_pd(std::numeric_limits<double>::quiet_NaN())))", f749, 2, 128},
  {"128:_mm_xor_pd(_mm_fnmadd_pd(x, y, _mm_set1_pd(std::numeric_limits<double>::quiet_NaN())), _mm_set1_pd(-0.0))", f750, 2, 128},
  {"128:_mm_andnot_pd(_mm_set1_pd(-0.0), _mm_fnmadd_pd(x, y, _mm_set1_pd(std::numeric_limits<double>::quiet_NaN())))", f751, 2, 128},
  {"128:_mm_sub_pd(_mm_setzero_pd(), _mm_fnmadd_pd(x, y, _mm_set1_pd(std::numeric_limits<double>::quiet_NaN())))", f752, 2, 128},
  {"128:_mm_mul_pd(_mm_fnmadd_pd(x, y, _mm_set1_pd(std::numeric_limits<double>::quiet_NaN())), _mm_set1_pd(-1.0))", f753, 2, 128},
  {"128:_mm_floor_pd(_mm_fnmadd_pd(x, y, _mm_set1_pd(std::numeric_limits<double>::quiet_NaN())))", f754, 2, 128},
  {"128:_mm_ceil_pd(_mm_fnmadd_pd(x, y, _mm_set1_pd(std::numeric_limits<double>::quiet_NaN())))", f755, 2, 128},
  {"128:_mm_round_pd(_mm_fnmadd_pd(x, y, _mm_set1_pd(std::numeric_limits<double>::quiet_NaN())), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)", f756, 2, 128},
  {"128:_mm_permute_pd(_mm_fnmadd_pd(x, y, _mm_set1_pd(std::numeric_limits<double>::quiet_NaN())), 0x5)", f757, 2, 128},
  {"128:_mm_permute_pd(_mm_fnmadd_pd(x, y, _mm_set1_pd(std::numeric_limits<double>::quiet_NaN())), 0xa)", f758, 2, 128},
  {"128:_mm_permute_pd(_mm_fnmadd_pd(x, y, _mm_set1_pd(std::numeric_limits<double>::quiet_NaN())), 0x3)", f759, 2, 128},
  {"128:_mm_sqrt_pd(_mm_fnmadd_pd(x, _mm_set1_pd(std::numeric_limits<double>::quiet_NaN()), y))", f760, 2, 128},
  {"128:_mm_xor_pd(_mm_fnmadd_pd(x, _mm_set1_pd(std::numeric_limits<double>::quiet_NaN()), y), _mm_set1_pd(-0.0))", f761, 2, 128},
  {"128:_mm_andnot_pd(_mm_set1_pd(-0.0), _mm_fnmadd_pd(x, _mm_set1_pd(std::numeric_limits<double>::quiet_NaN()), y))", f762, 2, 128},
  {"128:_mm_sub_pd(_mm_setzero_pd(), _mm_fnmadd_pd(x, _mm_set1_pd(std::numeric_limits<double>::quiet_NaN()), y))", f763, 2, 128},
  {"128:_mm_mul_pd(_mm_fnmadd_pd(x, _mm_set1_pd(std::numeric_limits<double>::quiet_NaN()), y), _mm_set1_pd(-1.0))", f764, 2, 128},
  {"128:_mm_floor_pd(_mm_fnmadd_pd(x, _mm_set1_pd(std::numeric_limits<double>::quiet_NaN()), y))", f765, 2, 128},
  {"128:_mm_ceil_pd(_mm_fnmadd_pd(x, _mm_set1_pd(std::numeric_limits<double>::quiet_NaN()), y))", f766, 2, 128},
  {"128:_mm_round_pd(_mm_fnmadd_pd(x, _mm_set1_pd(std::numeric_limits<double>::quiet_NaN()), y), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)", f767, 2, 128},
  {"128:_mm_permute_pd(_mm_fnmadd_pd(x, _mm_set1_pd(std::numeric_limits<double>::quiet_NaN()), y), 0x5)", f768, 2, 128},
  {"128:_mm_permute_pd(_mm_fnmadd_pd(x, _mm_set1_pd(std::numeric_limits<double>::quiet_NaN()), y), 0xa)", f769, 2, 128},
  {"128:_mm_permute_pd(_mm_fnmadd_pd(x, _mm_set1_pd(std::numeric_limits<double>::quiet_NaN()), y), 0x3)", f770, 2, 128},
  {"128:_mm_sqrt_pd(_mm_fnmadd_pd(_mm_set1_pd(std::numeric_limits<double>::quiet_NaN()), x, y))", f771, 2, 128},
  {"128:_mm_xor_pd(_mm_fnmadd_pd(_mm_set1_pd(std::numeric_limits<double>::quiet_NaN()), x, y), _mm_set1_pd(-0.0))", f772, 2, 128},
  {"128:_mm_andnot_pd(_mm_set1_pd(-0.0), _mm_fnmadd_pd(_mm_set1_pd(std::numeric_limits<double>::quiet_NaN()), x, y))", f773, 2, 128},
  {"128:_mm_sub_pd(_mm_setzero_pd(), _mm_fnmadd_pd(_mm_set1_pd(std::numeric_limits<double>::quiet_NaN()), x, y))", f774, 2, 128},
  {"128:_mm_mul_pd(_mm_fnmadd_pd(_mm_set1_pd(std::numeric_limits<double>::quiet_NaN()), x, y), _mm_set1_pd(-1.0))", f775, 2, 128},
  {"128:_mm_floor_pd(_mm_fnmadd_pd(_mm_set1_pd(std::numeric_limits<double>::quiet_NaN()), x, y))", f776, 2, 128},
  {"128:_mm_ceil_pd(_mm_fnmadd_pd(_mm_set1_pd(std::numeric_limits<double>::quiet_NaN()), x, y))", f777, 2, 128},
  {"128:_mm_round_pd(_mm_fnmadd_pd(_mm_set1_pd(std::numeric_limits<double>::quiet_NaN()), x, y), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)", f778, 2, 128},
  {"128:_mm_permute_pd(_mm_fnmadd_pd(_mm_set1_pd(std::numeric_limits<double>::quiet_NaN()), x, y), 0x5)", f779, 2, 128},
  {"128:_mm_permute_pd(_mm_fnmadd_pd(_mm_set1_pd(std::numeric_limits<double>::quiet_NaN()), x, y), 0xa)", f780, 2, 128},
  {"128:_mm_permute_pd(_mm_fnmadd_pd(_mm_set1_pd(std::numeric_limits<double>::quiet_NaN()), x, y), 0x3)", f781, 2, 128},
  {"128:_mm_sqrt_pd(_mm_fnmadd_pd(x, y, x))", f782, 2, 128},
  {"128:_mm_xor_pd(_mm_fnmadd_pd(x, y, x), _mm_set1_pd(-0.0))", f783, 2, 128},
  {"128:_mm_andnot_pd(_mm_set1_pd(-0.0), _mm_fnmadd_pd(x, y, x))", f784, 2, 128},
  {"128:_mm_sub_pd(_mm_setzero_pd(), _mm_fnmadd_pd(x, y, x))", f785, 2, 128},
  {"128:_mm_mul_pd(_mm_fnmadd_pd(x, y, x), _mm_set1_pd(-1.0))", f786, 2, 128},
  {"128:_mm_floor_pd(_mm_fnmadd_pd(x, y, x))", f787, 2, 128},
  {"128:_mm_ceil_pd(_mm_fnmadd_pd(x, y, x))", f788, 2, 128},
  {"128:_mm_round_pd(_mm_fnmadd_pd(x, y, x), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)", f789, 2, 128},
  {"128:_mm_permute_pd(_mm_fnmadd_pd(x, y, x), 0x5)", f790, 2, 128},
  {"128:_mm_permute_pd(_mm_fnmadd_pd(x, y, x), 0xa)", f791, 2, 128},
  {"128:_mm_permute_pd(_mm_fnmadd_pd(x, y, x), 0x3)", f792, 2, 128},
  {"128:_mm_sqrt_pd(_mm_fnmadd_pd(x, x, y))", f793, 2, 128},
  {"128:_mm_xor_pd(_mm_fnmadd_pd(x, x, y), _mm_set1_pd(-0.0))", f794, 2, 128},
  {"128:_mm_andnot_pd(_mm_set1_pd(-0.0), _mm_fnmadd_pd(x, x, y))", f795, 2, 128},
  {"128:_mm_sub_pd(_mm_setzero_pd(), _mm_fnmadd_pd(x, x, y))", f796, 2, 128},
  {"128:_mm_mul_pd(_mm_fnmadd_pd(x, x, y), _mm_set1_pd(-1.0))", f797, 2, 128},
  {"128:_mm_floor_pd(_mm_fnmadd_pd(x, x, y))", f798, 2, 128},
  {"128:_mm_ceil_pd(_mm_fnmadd_pd(x, x, y))", f799, 2, 128},
  {"128:_mm_round_pd(_mm_fnmadd_pd(x, x, y), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)", f800, 2, 128},
  {"128:_mm_permute_pd(_mm_fnmadd_pd(x, x, y), 0x5)", f801, 2, 128},
  {"128:_mm_permute_pd(_mm_fnmadd_pd(x, x, y), 0xa)", f802, 2, 128},
  {"128:_mm_permute_pd(_mm_fnmadd_pd(x, x, y), 0x3)", f803, 2, 128},
  {"128:_mm_sqrt_pd(_mm_fnmadd_pd(x, y, _mm_mul_pd(x, y)))", f804, 2, 128},
  {"128:_mm_xor_pd(_mm_fnmadd_pd(x, y, _mm_mul_pd(x, y)), _mm_set1_pd(-0.0))", f805, 2, 128},
  {"128:_mm_andnot_pd(_mm_set1_pd(-0.0), _mm_fnmadd_pd(x, y, _mm_mul_pd(x, y)))", f806, 2, 128},
  {"128:_mm_sub_pd(_mm_setzero_pd(), _mm_fnmadd_pd(x, y, _mm_mul_pd(x, y)))", f807, 2, 128},
  {"128:_mm_mul_pd(_mm_fnmadd_pd(x, y, _mm_mul_pd(x, y)), _mm_set1_pd(-1.0))", f808, 2, 128},
  {"128:_mm_floor_pd(_mm_fnmadd_pd(x, y, _mm_mul_pd(x, y)))", f809, 2, 128},
  {"128:_mm_ceil_pd(_mm_fnmadd_pd(x, y, _mm_mul_pd(x, y)))", f810, 2, 128},
  {"128:_mm_round_pd(_mm_fnmadd_pd(x, y, _mm_mul_pd(x, y)), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)", f811, 2, 128},
  {"128:_mm_permute_pd(_mm_fnmadd_pd(x, y, _mm_mul_pd(x, y)), 0x5)", f812, 2, 128},
  {"128:_mm_permute_pd(_mm_fnmadd_pd(x, y, _mm_mul_pd(x, y)), 0xa)", f813, 2, 128},
  {"128:_mm_permute_pd(_mm_fnmadd_pd(x, y, _mm_mul_pd(x, y)), 0x3)", f814, 2, 128},
  {"128:_mm_sqrt_pd(_mm_fnmsub_pd(x, y, _mm_setzero_pd()))", f815, 2, 128},
  {"128:_mm_xor_pd(_mm_fnmsub_pd(x, y, _mm_setzero_pd()), _mm_set1_pd(-0.0))", f816, 2, 128},
  {"128:_mm_andnot_pd(_mm_set1_pd(-0.0), _mm_fnmsub_pd(x, y, _mm_setzero_pd()))", f817, 2, 128},
  {"128:_mm_sub_pd(_mm_setzero_pd(), _mm_fnmsub_pd(x, y, _mm_setzero_pd()))", f818, 2, 128},
  {"128:_mm_mul_pd(_mm_fnmsub_pd(x, y, _mm_setzero_pd()), _mm_set1_pd(-1.0))", f819, 2, 128},
  {"128:_mm_floor_pd(_mm_fnmsub_pd(x, y, _mm_setzero_pd()))", f820, 2, 128},
  {"128:_mm_ceil_pd(_mm_fnmsub_pd(x, y, _mm_setzero_pd()))", f821, 2, 128},
  {"128:_mm_round_pd(_mm_fnmsub_pd(x, y, _mm_setzero_pd()), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)", f822, 2, 128},
  {"128:_mm_permute_pd(_mm_fnmsub_pd(x, y, _mm_setzero_pd()), 0x5)", f823, 2, 128},
  {"128:_mm_permute_pd(_mm_fnmsub_pd(x, y, _mm_setzero_pd()), 0xa)", f824, 2, 128},
  {"128:_mm_permute_pd(_mm_fnmsub_pd(x, y, _mm_setzero_pd()), 0x3)", f825, 2, 128},
  {"128:_mm_sqrt_pd(_mm_fnmsub_pd(x, _mm_setzero_pd(), y))", f826, 2, 128},
  {"128:_mm_xor_pd(_mm_fnmsub_pd(x, _mm_setzero_pd(), y), _mm_set1_pd(-0.0))", f827, 2, 128},
  {"128:_mm_andnot_pd(_mm_set1_pd(-0.0), _mm_fnmsub_pd(x, _mm_setzero_pd(), y))", f828, 2, 128},
  {"128:_mm_sub_pd(_mm_setzero_pd(), _mm_fnmsub_pd(x, _mm_setzero_pd(), y))", f829, 2, 128},
  {"128:_mm_mul_pd(_mm_fnmsub_pd(x, _mm_setzero_pd(), y), _mm_set1_pd(-1.0))", f830, 2, 128},
  {"128:_mm_floor_pd(_mm_fnmsub_pd(x, _mm_setzero_pd(), y))", f831, 2, 128},
  {"128:_mm_ceil_pd(_mm_fnmsub_pd(x, _mm_setzero_pd(), y))", f832, 2, 128},
  {"128:_mm_round_pd(_mm_fnmsub_pd(x, _mm_setzero_pd(), y), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)", f833, 2, 128},
  {"128:_mm_permute_pd(_mm_fnmsub_pd(x, _mm_setzero_pd(), y), 0x5)", f834, 2, 128},
  {"128:_mm_permute_pd(_mm_fnmsub_pd(x, _mm_setzero_pd(), y), 0xa)", f835, 2, 128},
  {"128:_mm_permute_pd(_mm_fnmsub_pd(x, _mm_setzero_pd(), y), 0x3)", f836, 2, 128},
  {"128:_mm_sqrt_pd(_mm_fnmsub_pd(_mm_setzero_pd(), x, y))", f837, 2, 128},
  {"128:_mm_xor_pd(_mm_fnmsub_pd(_mm_setzero_pd(), x, y), _mm_set1_pd(-0.0))", f838, 2, 128},
  {"128:_mm_andnot_pd(_mm_set1_pd(-0.0), _mm_fnmsub_pd(_mm_setzero_pd(), x, y))", f839, 2, 128},
  {"128:_mm_sub_pd(_mm_setzero_pd(), _mm_fnmsub_pd(_mm_setzero_pd(), x, y))", f840, 2, 128},
  {"128:_mm_mul_pd(_mm_fnmsub_pd(_mm_setzero_pd(), x, y), _mm_set1_pd(-1.0))", f841, 2, 128},
  {"128:_mm_floor_pd(_mm_fnmsub_pd(_mm_setzero_pd(), x, y))", f842, 2, 128},
  {"128:_mm_ceil_pd(_mm_fnmsub_pd(_mm_setzero_pd(), x, y))", f843, 2, 128},
  {"128:_mm_round_pd(_mm_fnmsub_pd(_mm_setzero_pd(), x, y), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)", f844, 2, 128},
  {"128:_mm_permute_pd(_mm_fnmsub_pd(_mm_setzero_pd(), x, y), 0x5)", f845, 2, 128},
  {"128:_mm_permute_pd(_mm_fnmsub_pd(_mm_setzero_pd(), x, y), 0xa)", f846, 2, 128},
  {"128:_mm_permute_pd(_mm_fnmsub_pd(_mm_setzero_pd(), x, y), 0x3)", f847, 2, 128},
  {"128:_mm_sqrt_pd(_mm_fnmsub_pd(x, y, _mm_set1_pd(-0.0)))", f848, 2, 128},
  {"128:_mm_xor_pd(_mm_fnmsub_pd(x, y, _mm_set1_pd(-0.0)), _mm_set1_pd(-0.0))", f849, 2, 128},
  {"128:_mm_andnot_pd(_mm_set1_pd(-0.0), _mm_fnmsub_pd(x, y, _mm_set1_pd(-0.0)))", f850, 2, 128},
  {"128:_mm_sub_pd(_mm_setzero_pd(), _mm_fnmsub_pd(x, y, _mm_set1_pd(-0.0)))", f851, 2, 128},
  {"128:_mm_mul_pd(_mm_fnmsub_pd(x, y, _mm_set1_pd(-0.0)), _mm_set1_pd(-1.0))", f852, 2, 128},
  {"128:_mm_floor_pd(_mm_fnmsub_pd(x, y, _mm_set1_pd(-0.0)))", f853, 2, 128},
  {"128:_mm_ceil_pd(_mm_fnmsub_pd(x, y, _mm_set1_pd(-0.0)))", f854, 2, 128},
  {"128:_mm_round_pd(_mm_fnmsub_pd(x, y, _mm_set1_pd(-0.0)), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)", f855, 2, 128},
  {"128:_mm_permute_pd(_mm_fnmsub_pd(x, y, _mm_set1_pd(-0.0)), 0x5)", f856, 2, 128},
  {"128:_mm_permute_pd(_mm_fnmsub_pd(x, y, _mm_set1_pd(-0.0)), 0xa)", f857, 2, 128},
  {"128:_mm_permute_pd(_mm_fnmsub_pd(x, y, _mm_set1_pd(-0.0)), 0x3)", f858, 2, 128},
  {"128:_mm_sqrt_pd(_mm_fnmsub_pd(x, _mm_set1_pd(-0.0), y))", f859, 2, 128},
  {"128:_mm_xor_pd(_mm_fnmsub_pd(x, _mm_set1_pd(-0.0), y), _mm_set1_pd(-0.0))", f860, 2, 128},
  {"128:_mm_andnot_pd(_mm_set1_pd(-0.0), _mm_fnmsub_pd(x, _mm_set1_pd(-0.0), y))", f861, 2, 128},
  {"128:_mm_sub_pd(_mm_setzero_pd(), _mm_fnmsub_pd(x, _mm_set1_pd(-0.0), y))", f862, 2, 128},
  {"128:_mm_mul_pd(_mm_fnmsub_pd(x, _mm_set1_pd(-0.0), y), _mm_set1_pd(-1.0))", f863, 2, 128},
  {"128:_mm_floor_pd(_mm_fnmsub_pd(x, _mm_set1_pd(-0.0), y))", f864, 2, 128},
  {"128:_mm_ceil_pd(_mm_fnmsub_pd(x, _mm_set1_pd(-0.0), y))", f865, 2, 128},
  {"128:_mm_round_pd(_mm_fnmsub_pd(x, _mm_set1_pd(-0.0), y), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)", f866, 2, 128},
  {"128:_mm_permute_pd(_mm_fnmsub_pd(x, _mm_set1_pd(-0.0), y), 0x5)", f867, 2, 128},
  {"128:_mm_permute_pd(_mm_fnmsub_pd(x, _mm_set1_pd(-0.0), y), 0xa)", f868, 2, 128},
  {"128:_mm_permute_pd(_mm_fnmsub_pd(x, _mm_set1_pd(-0.0), y), 0x3)", f869, 2, 128},
  {"128:_mm_sqrt_pd(_mm_fnmsub_pd(_mm_set1_pd(-0.0), x, y))", f870, 2, 128},
  {"128:_mm_xor_pd(_mm_fnmsub_pd(_mm_set1_pd(-0.0), x, y), _mm_set1_pd(-0.0))", f871, 2, 128},
  {"128:_mm_andnot_pd(_mm_set1_pd(-0.0), _mm_fnmsub_pd(_mm_set1_pd(-0.0), x, y))", f872, 2, 128},
  {"128:_mm_sub_pd(_mm_setzero_pd(), _mm_fnmsub_pd(_mm_set1_pd(-0.0), x, y))", f873, 2, 128},
  {"128:_mm_mul_pd(_mm_fnmsub_pd(_mm_set1_pd(-0.0), x, y), _mm_set1_pd(-1.0))", f874, 2, 128},
  {"128:_mm_floor_pd(_mm_fnmsub_pd(_mm_set1_pd(-0.0), x, y))", f875, 2, 128},
  {"128:_mm_ceil_pd(_mm_fnmsub_pd(_mm_set1_pd(-0.0), x, y))", f876, 2, 128},
  {"128:_mm_round_pd(_mm_fnmsub_pd(_mm_set1_pd(-0.0), x, y), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)", f877, 2, 128},
  {"128:_mm_permute_pd(_mm_fnmsub_pd(_mm_set1_pd(-0.0), x, y), 0x5)", f878, 2, 128},
  {"128:_mm_permute_pd(_mm_fnmsub_pd(_mm_set1_pd(-0.0), x, y), 0xa)", f879, 2, 128},
  {"128:_mm_permute_pd(_mm_fnmsub_pd(_mm_set1_pd(-0.0), x, y), 0x3)", f880, 2, 128},
  {"128:_mm_sqrt_pd(_mm_fnmsub_pd(x, y, _mm_set1_pd(1.0)))", f881, 2, 128},
  {"128:_mm_xor_pd(_mm_fnmsub_pd(x, y, _mm_set1_pd(1.0)), _mm_set1_pd(-0.0))", f882, 2, 128},
  {"128:_mm_andnot_pd(_mm_set1_pd(-0.0), _mm_fnmsub_pd(x, y, _mm_set1_pd(1.0)))", f883, 2, 128},
  {"128:_mm_sub_pd(_mm_setzero_pd(), _mm_fnmsub_pd(x, y, _mm_set1_pd(1.0)))", f884, 2, 128},
  {"128:_mm_mul_pd(_mm_fnmsub_pd(x, y, _mm_set1_pd(1.0)), _mm_set1_pd(-1.0))", f885, 2, 128},
  {"128:_mm_floor_pd(_mm_fnmsub_pd(x, y, _mm_set1_pd(1.0)))", f886, 2, 128},
  {"128:_mm_ceil_pd(_mm_fnmsub_pd(x, y, _mm_set1_pd(1.0)))", f887, 2, 128},
  {"128:_mm_round_pd(_mm_fnmsub_pd(x, y, _mm_set1_pd(1.0)), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)", f888, 2, 128},
  {"128:_mm_permute_pd(_mm_fnmsub_pd(x, y, _mm_set1_pd(1.0)), 0x5)", f889, 2, 128},
  {"128:_mm_permute_pd(_mm_fnmsub_pd(x, y, _mm_set1_pd(1.0)), 0xa)", f890, 2, 128},
  {"128:_mm_permute_pd(_mm_fnmsub_pd(x, y, _mm_set1_pd(1.0)), 0x3)", f891, 2, 128},
  {"128:_mm_sqrt_pd(_mm_fnmsub_pd(x, _mm_set1_pd(1.0), y))", f892, 2, 128},
  {"128:_mm_xor_pd(_mm_fnmsub_pd(x, _mm_set1_pd(1.0), y), _mm_set1_pd(-0.0))", f893, 2, 128},
  {"128:_mm_andnot_pd(_mm_set1_pd(-0.0), _mm_fnmsub_pd(x, _mm_set1_pd(1.0), y))", f894, 2, 128},
  {"128:_mm_sub_pd(_mm_setzero_pd(), _mm_fnmsub_pd(x, _mm_set1_pd(1.0), y))", f895, 2, 128},
  {"128:_mm_mul_pd(_mm_fnmsub_pd(x, _mm_set1_pd(1.0), y), _mm_set1_pd(-1.0))", f896, 2, 128},
  {"128:_mm_floor_pd(_mm_fnmsub_pd(x, _mm_set1_pd(1.0), y))", f897, 2, 128},
  {"128:_mm_ceil_pd(_mm_fnmsub_pd(x, _mm_set1_pd(1.0), y))", f898, 2, 128},
  {"128:_mm_round_pd(_mm_fnmsub_pd(x, _mm_set1_pd(1.0), y), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)", f899, 2, 128},
  {"128:_mm_permute_pd(_mm_fnmsub_pd(x, _mm_set1_pd(1.0), y), 0x5)", f900, 2, 128},
  {"128:_mm_permute_pd(_mm_fnmsub_pd(x, _mm_set1_pd(1.0), y), 0xa)", f901, 2, 128},
  {"128:_mm_permute_pd(_mm_fnmsub_pd(x, _mm_set1_pd(1.0), y), 0x3)", f902, 2, 128},
  {"128:_mm_sqrt_pd(_mm_fnmsub_pd(_mm_set1_pd(1.0), x, y))", f903, 2, 128},
  {"128:_mm_xor_pd(_mm_fnmsub_pd(_mm_set1_pd(1.0), x, y), _mm_set1_pd(-0.0))", f904, 2, 128},
  {"128:_mm_andnot_pd(_mm_set1_pd(-0.0), _mm_fnmsub_pd(_mm_set1_pd(1.0), x, y))", f905, 2, 128},
  {"128:_mm_sub_pd(_mm_setzero_pd(), _mm_fnmsub_pd(_mm_set1_pd(1.0), x, y))", f906, 2, 128},
  {"128:_mm_mul_pd(_mm_fnmsub_pd(_mm_set1_pd(1.0), x, y), _mm_set1_pd(-1.0))", f907, 2, 128},
  {"128:_mm_floor_pd(_mm_fnmsub_pd(_mm_set1_pd(1.0), x, y))", f908, 2, 128},
  {"128:_mm_ceil_pd(_mm_fnmsub_pd(_mm_set1_pd(1.0), x, y))", f909, 2, 128},
  {"128:_mm_round_pd(_mm_fnmsub_pd(_mm_set1_pd(1.0), x, y), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)", f910, 2, 128},
  {"128:_mm_permute_pd(_mm_fnmsub_pd(_mm_set1_pd(1.0), x, y), 0x5)", f911, 2, 128},
  {"128:_mm_permute_pd(_mm_fnmsub_pd(_mm_set1_pd(1.0), x, y), 0xa)", f912, 2, 128},
  {"128:_mm_permute_pd(_mm_fnmsub_pd(_mm_set1_pd(1.0), x, y), 0x3)", f913, 2, 128},
  {"128:_mm_sqrt_pd(_mm_fnmsub_pd(x, y, _mm_set1_pd(-1.0)))", f914, 2, 128},
  {"128:_mm_xor_pd(_mm_fnmsub_pd(x, y, _mm_set1_pd(-1.0)), _mm_set1_pd(-0.0))", f915, 2, 128},
  {"128:_mm_andnot_pd(_mm_set1_pd(-0.0), _mm_fnmsub_pd(x, y, _mm_set1_pd(-1.0)))", f916, 2, 128},
  {"128:_mm_sub_pd(_mm_setzero_pd(), _mm_fnmsub_pd(x, y, _mm_set1_pd(-1.0)))", f917, 2, 128},
  {"128:_mm_mul_pd(_mm_fnmsub_pd(x, y, _mm_set1_pd(-1.0)), _mm_set1_pd(-1.0))", f918, 2, 128},
  {"128:_mm_floor_pd(_mm_fnmsub_pd(x, y, _mm_set1_pd(-1.0)))", f919, 2, 128},
  {"128:_mm_ceil_pd(_mm_fnmsub_pd(x, y, _mm_set1_pd(-1.0)))", f920, 2, 128},
  {"128:_mm_round_pd(_mm_fnmsub_pd(x, y, _mm_set1_pd(-1.0)), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)", f921, 2, 128},
  {"128:_mm_permute_pd(_mm_fnmsub_pd(x, y, _mm_set1_pd(-1.0)), 0x5)", f922, 2, 128},
  {"128:_mm_permute_pd(_mm_fnmsub_pd(x, y, _mm_set1_pd(-1.0)), 0xa)", f923, 2, 128},
  {"128:_mm_permute_pd(_mm_fnmsub_pd(x, y, _mm_set1_pd(-1.0)), 0x3)", f924, 2, 128},
  {"128:_mm_sqrt_pd(_mm_fnmsub_pd(x, _mm_set1_pd(-1.0), y))", f925, 2, 128},
  {"128:_mm_xor_pd(_mm_fnmsub_pd(x, _mm_set1_pd(-1.0), y), _mm_set1_pd(-0.0))", f926, 2, 128},
  {"128:_mm_andnot_pd(_mm_set1_pd(-0.0), _mm_fnmsub_pd(x, _mm_set1_pd(-1.0), y))", f927, 2, 128},
  {"128:_mm_sub_pd(_mm_setzero_pd(), _mm_fnmsub_pd(x, _mm_set1_pd(-1.0), y))", f928, 2, 128},
  {"128:_mm_mul_pd(_mm_fnmsub_pd(x, _mm_set1_pd(-1.0), y), _mm_set1_pd(-1.0))", f929, 2, 128},
  {"128:_mm_floor_pd(_mm_fnmsub_pd(x, _mm_set1_pd(-1.0), y))", f930, 2, 128},
  {"128:_mm_ceil_pd(_mm_fnmsub_pd(x, _mm_set1_pd(-1.0), y))", f931, 2, 128},
  {"128:_mm_round_pd(_mm_fnmsub_pd(x, _mm_set1_pd(-1.0), y), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)", f932, 2, 128},
  {"128:_mm_permute_pd(_mm_fnmsub_pd(x, _mm_set1_pd(-1.0), y), 0x5)", f933, 2, 128},
  {"128:_mm_permute_pd(_mm_fnmsub_pd(x, _mm_set1_pd(-1.0), y), 0xa)", f934, 2, 128},
  {"128:_mm_permute_pd(_mm_fnmsub_pd(x, _mm_set1_pd(-1.0), y), 0x3)", f935, 2, 128},
  {"128:_mm_sqrt_pd(_mm_fnmsub_pd(_mm_set1_pd(-1.0), x, y))", f936, 2, 128},
  {"128:_mm_xor_pd(_mm_fnmsub_pd(_mm_set1_pd(-1.0), x, y), _mm_set1_pd(-0.0))", f937, 2, 128},
  {"128:_mm_andnot_pd(_mm_set1_pd(-0.0), _mm_fnmsub_pd(_mm_set1_pd(-1.0), x, y))", f938, 2, 128},
  {"128:_mm_sub_pd(_mm_setzero_pd(), _mm_fnmsub_pd(_mm_set1_pd(-1.0), x, y))", f939, 2, 128},
  {"128:_mm_mul_pd(_mm_fnmsub_pd(_mm_set1_pd(-1.0), x, y), _mm_set1_pd(-1.0))", f940, 2, 128},
  {"128:_mm_floor_pd(_mm_fnmsub_pd(_mm_set1_pd(-1.0), x, y))", f941, 2, 128},
  {"128:_mm_ceil_pd(_mm_fnmsub_pd(_mm_set1_pd(-1.0), x, y))", f942, 2, 128},
  {"128:_mm_round_pd(_mm_fnmsub_pd(_mm_set1_pd(-1.0), x, y), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)", f943, 2, 128},
  {"128:_mm_permute_pd(_mm_fnmsub_pd(_mm_set1_pd(-1.0), x, y), 0x5)", f944, 2, 128},
  {"128:_mm_permute_pd(_mm_fnmsub_pd(_mm_set1_pd(-1.0), x, y), 0xa)", f945, 2, 128},
  {"128:_mm_permute_pd(_mm_fnmsub_pd(_mm_set1_pd(-1.0), x, y), 0x3)", f946, 2, 128},
  {"128:_mm_sqrt_pd(_mm_fnmsub_pd(x, y, _mm_set1_pd(std::numeric_limits<double>::infinity())))", f947, 2, 128},
  {"128:_mm_xor_pd(_mm_fnmsub_pd(x, y, _mm_set1_pd(std::numeric_limits<double>::infinity())), _mm_set1_pd(-0.0))", f948, 2, 128},
  {"128:_mm_andnot_pd(_mm_set1_pd(-0.0), _mm_fnmsub_pd(x, y, _mm_set1_pd(std::numeric_limits<double>::infinity())))", f949, 2, 128},
  {"128:_mm_sub_pd(_mm_setzero_pd(), _mm_fnmsub_pd(x, y, _mm_set1_pd(std::numeric_limits<double>::infinity())))", f950, 2, 128},
  {"128:_mm_mul_pd(_mm_fnmsub_pd(x, y, _mm_set1_pd(std::numeric_limits<double>::infinity())), _mm_set1_pd(-1.0))", f951, 2, 128},
  {"128:_mm_floor_pd(_mm_fnmsub_pd(x, y, _mm_set1_pd(std::numeric_limits<double>::infinity())))", f952, 2, 128},
  {"128:_mm_ceil_pd(_mm_fnmsub_pd(x, y, _mm_set1_pd(std::numeric_limits<double>::infinity())))", f953, 2, 128},
  {"128:_mm_round_pd(_mm_fnmsub_pd(x, y, _mm_set1_pd(std::numeric_limits<double>::infinity())), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)", f954, 2, 128},
  {"128:_mm_permute_pd(_mm_fnmsub_pd(x, y, _mm_set1_pd(std::numeric_limits<double>::infinity())), 0x5)", f955, 2, 128},
  {"128:_mm_permute_pd(_mm_fnmsub_pd(x, y, _mm_set1_pd(std::numeric_limits<double>::infinity())), 0xa)", f956, 2, 128},
  {"128:_mm_permute_pd(_mm_fnmsub_pd(x, y, _mm_set1_pd(std::numeric_limits<double>::infinity())), 0x3)", f957, 2, 128},
  {"128:_mm_sqrt_pd(_mm_fnmsub_pd(x, _mm_set1_pd(std::numeric_limits<double>::infinity()), y))", f958, 2, 128},
  {"128:_mm_xor_pd(_mm_fnmsub_pd(x, _mm_set1_pd(std::numeric_limits<double>::infinity()), y), _mm_set1_pd(-0.0))", f959, 2, 128},
  {"128:_mm_andnot_pd(_mm_set1_pd(-0.0), _mm_fnmsub_pd(x, _mm_set1_pd(std::numeric_limits<double>::infinity()), y))", f960, 2, 128},
  {"128:_mm_sub_pd(_mm_setzero_pd(), _mm_fnmsub_pd(x, _mm_set1_pd(std::numeric_limits<double>::infinity()), y))", f961, 2, 128},
  {"128:_mm_mul_pd(_mm_fnmsub_pd(x, _mm_set1_pd(std::numeric_limits<double>::infinity()), y), _mm_set1_pd(-1.0))", f962, 2, 128},
  {"128:_mm_floor_pd(_mm_fnmsub_pd(x, _mm_set1_pd(std::numeric_limits<double>::infinity()), y))", f963, 2, 128},
  {"128:_mm_ceil_pd(_mm_fnmsub_pd(x, _mm_set1_pd(std::numeric_limits<double>::infinity()), y))", f964, 2, 128},
  {"128:_mm_round_pd(_mm_fnmsub_pd(x, _mm_set1_pd(std::numeric_limits<double>::infinity()), y), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)", f965, 2, 128},
  {"128:_mm_permute_pd(_mm_fnmsub_pd(x, _mm_set1_pd(std::numeric_limits<double>::infinity()), y), 0x5)", f966, 2, 128},
  {"128:_mm_permute_pd(_mm_fnmsub_pd(x, _mm_set1_pd(std::numeric_limits<double>::infinity()), y), 0xa)", f967, 2, 128},
  {"128:_mm_permute_pd(_mm_fnmsub_pd(x, _mm_set1_pd(std::numeric_limits<double>::infinity()), y), 0x3)", f968, 2, 128},
  {"128:_mm_sqrt_pd(_mm_fnmsub_pd(_mm_set1_pd(std::numeric_limits<double>::infinity()), x, y))", f969, 2, 128},
  {"128:_mm_xor_pd(_mm_fnmsub_pd(_mm_set1_pd(std::numeric_limits<double>::infinity()), x, y), _mm_set1_pd(-0.0))", f970, 2, 128},
  {"128:_mm_andnot_pd(_mm_set1_pd(-0.0), _mm_fnmsub_pd(_mm_set1_pd(std::numeric_limits<double>::infinity()), x, y))", f971, 2, 128},
  {"128:_mm_sub_pd(_mm_setzero_pd(), _mm_fnmsub_pd(_mm_set1_pd(std::numeric_limits<double>::infinity()), x, y))", f972, 2, 128},
  {"128:_mm_mul_pd(_mm_fnmsub_pd(_mm_set1_pd(std::numeric_limits<double>::infinity()), x, y), _mm_set1_pd(-1.0))", f973, 2, 128},
  {"128:_mm_floor_pd(_mm_fnmsub_pd(_mm_set1_pd(std::numeric_limits<double>::infinity()), x, y))", f974, 2, 128},
  {"128:_mm_ceil_pd(_mm_fnmsub_pd(_mm_set1_pd(std::numeric_limits<double>::infinity()), x, y))", f975, 2, 128},
  {"128:_mm_round_pd(_mm_fnmsub_pd(_mm_set1_pd(std::numeric_limits<double>::infinity()), x, y), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)", f976, 2, 128},
  {"128:_mm_permute_pd(_mm_fnmsub_pd(_mm_set1_pd(std::numeric_limits<double>::infinity()), x, y), 0x5)", f977, 2, 128},
  {"128:_mm_permute_pd(_mm_fnmsub_pd(_mm_set1_pd(std::numeric_limits<double>::infinity()), x, y), 0xa)", f978, 2, 128},
  {"128:_mm_permute_pd(_mm_fnmsub_pd(_mm_set1_pd(std::numeric_limits<double>::infinity()), x, y), 0x3)", f979, 2, 128},
  {"128:_mm_sqrt_pd(_mm_fnmsub_pd(x, y, _mm_set1_pd(std::numeric_limits<double>::quiet_NaN())))", f980, 2, 128},
  {"128:_mm_xor_pd(_mm_fnmsub_pd(x, y, _mm_set1_pd(std::numeric_limits<double>::quiet_NaN())), _mm_set1_pd(-0.0))", f981, 2, 128},
  {"128:_mm_andnot_pd(_mm_set1_pd(-0.0), _mm_fnmsub_pd(x, y, _mm_set1_pd(std::numeric_limits<double>::quiet_NaN())))", f982, 2, 128},
  {"128:_mm_sub_pd(_mm_setzero_pd(), _mm_fnmsub_pd(x, y, _mm_set1_pd(std::numeric_limits<double>::quiet_NaN())))", f983, 2, 128},
  {"128:_mm_mul_pd(_mm_fnmsub_pd(x, y, _mm_set1_pd(std::numeric_limits<double>::quiet_NaN())), _mm_set1_pd(-1.0))", f984, 2, 128},
  {"128:_mm_floor_pd(_mm_fnmsub_pd(x, y, _mm_set1_pd(std::numeric_limits<double>::quiet_NaN())))", f985, 2, 128},
  {"128:_mm_ceil_pd(_mm_fnmsub_pd(x, y, _mm_set1_pd(std::numeric_limits<double>::quiet_NaN())))", f986, 2, 128},
  {"128:_mm_round_pd(_mm_fnmsub_pd(x, y, _mm_set1_pd(std::numeric_limits<double>::quiet_NaN())), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)", f987, 2, 128},
  {"128:_mm_permute_pd(_mm_fnmsub_pd(x, y, _mm_set1_pd(std::numeric_limits<double>::quiet_NaN())), 0x5)", f988, 2, 128},
  {"128:_mm_permute_pd(_mm_fnmsub_pd(x, y, _mm_set1_pd(std::numeric_limits<double>::quiet_NaN())), 0xa)", f989, 2, 128},
  {"128:_mm_permute_pd(_mm_fnmsub_pd(x, y, _mm_set1_pd(std::numeric_limits<double>::quiet_NaN())), 0x3)", f990, 2, 128},
  {"128:_mm_sqrt_pd(_mm_fnmsub_pd(x, _mm_set1_pd(std::numeric_limits<double>::quiet_NaN()), y))", f991, 2, 128},
  {"128:_mm_xor_pd(_mm_fnmsub_pd(x, _mm_set1_pd(std::numeric_limits<double>::quiet_NaN()), y), _mm_set1_pd(-0.0))", f992, 2, 128},
  {"128:_mm_andnot_pd(_mm_set1_pd(-0.0), _mm_fnmsub_pd(x, _mm_set1_pd(std::numeric_limits<double>::quiet_NaN()), y))", f993, 2, 128},
  {"128:_mm_sub_pd(_mm_setzero_pd(), _mm_fnmsub_pd(x, _mm_set1_pd(std::numeric_limits<double>::quiet_NaN()), y))", f994, 2, 128},
  {"128:_mm_mul_pd(_mm_fnmsub_pd(x, _mm_set1_pd(std::numeric_limits<double>::quiet_NaN()), y), _mm_set1_pd(-1.0))", f995, 2, 128},
  {"128:_mm_floor_pd(_mm_fnmsub_pd(x, _mm_set1_pd(std::numeric_limits<double>::quiet_NaN()), y))", f996, 2, 128},
  {"128:_mm_ceil_pd(_mm_fnmsub_pd(x, _mm_set1_pd(std::numeric_limits<double>::quiet_NaN()), y))", f997, 2, 128},
  {"128:_mm_round_pd(_mm_fnmsub_pd(x, _mm_set1_pd(std::numeric_limits<double>::quiet_NaN()), y), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)", f998, 2, 128},
  {"128:_mm_permute_pd(_mm_fnmsub_pd(x, _mm_set1_pd(std::numeric_limits<double>::quiet_NaN()), y), 0x5)", f999, 2, 128},
  {"128:_mm_permute_pd(_mm_fnmsub_pd(x, _mm_set1_pd(std::numeric_limits<double>::quiet_NaN()), y), 0xa)", f1000, 2, 128},
  {"128:_mm_permute_pd(_mm_fnmsub_pd(x, _mm_set1_pd(std::numeric_limits<double>::quiet_NaN()), y), 0x3)", f1001, 2, 128},
  {"128:_mm_sqrt_pd(_mm_fnmsub_pd(_mm_set1_pd(std::numeric_limits<double>::quiet_NaN()), x, y))", f1002, 2, 128},
  {"128:_mm_xor_pd(_mm_fnmsub_pd(_mm_set1_pd(std::numeric_limits<double>::quiet_NaN()), x, y), _mm_set1_pd(-0.0))", f1003, 2, 128},
  {"128:_mm_andnot_pd(_mm_set1_pd(-0.0), _mm_fnmsub_pd(_mm_set1_pd(std::numeric_limits<double>::quiet_NaN()), x, y))", f1004, 2, 128},
  {"128:_mm_sub_pd(_mm_setzero_pd(), _mm_fnmsub_pd(_mm_set1_pd(std::numeric_limits<double>::quiet_NaN()), x, y))", f1005, 2, 128},
  {"128:_mm_mul_pd(_mm_fnmsub_pd(_mm_set1_pd(std::numeric_limits<double>::quiet_NaN()), x, y), _mm_set1_pd(-1.0))", f1006, 2, 128},
  {"128:_mm_floor_pd(_mm_fnmsub_pd(_mm_set1_pd(std::numeric_limits<double>::quiet_NaN()), x, y))", f1007, 2, 128},
  {"128:_mm_ceil_pd(_mm_fnmsub_pd(_mm_set1_pd(std::numeric_limits<double>::quiet_NaN()), x, y))", f1008, 2, 128},
  {"128:_mm_round_pd(_mm_fnmsub_pd(_mm_set1_pd(std::numeric_limits<double>::quiet_NaN()), x, y), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)", f1009, 2, 128},
  {"128:_mm_permute_pd(_mm_fnmsub_pd(_mm_set1_pd(std::numeric_limits<double>::quiet_NaN()), x, y), 0x5)", f1010, 2, 128},
  {"128:_mm_permute_pd(_mm_fnmsub_pd(_mm_set1_pd(std::numeric_limits<double>::quiet_NaN()), x, y), 0xa)", f1011, 2, 128},
  {"128:_mm_permute_pd(_mm_fnmsub_pd(_mm_set1_pd(std::numeric_limits<double>::quiet_NaN()), x, y), 0x3)", f1012, 2, 128},
  {"128:_mm_sqrt_pd(_mm_fnmsub_pd(x, y, x))", f1013, 2, 128},
  {"128:_mm_xor_pd(_mm_fnmsub_pd(x, y, x), _mm_set1_pd(-0.0))", f1014, 2, 128},
  {"128:_mm_andnot_pd(_mm_set1_pd(-0.0), _mm_fnmsub_pd(x, y, x))", f1015, 2, 128},
  {"128:_mm_sub_pd(_mm_setzero_pd(), _mm_fnmsub_pd(x, y, x))", f1016, 2, 128},
  {"128:_mm_mul_pd(_mm_fnmsub_pd(x, y, x), _mm_set1_pd(-1.0))", f1017, 2, 128},
  {"128:_mm_floor_pd(_mm_fnmsub_pd(x, y, x))", f1018, 2, 128},
  {"128:_mm_ceil_pd(_mm_fnmsub_pd(x, y, x))", f1019, 2, 128},
  {"128:_mm_round_pd(_mm_fnmsub_pd(x, y, x), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)", f1020, 2, 128},
  {"128:_mm_permute_pd(_mm_fnmsub_pd(x, y, x), 0x5)", f1021, 2, 128},
  {"128:_mm_permute_pd(_mm_fnmsub_pd(x, y, x), 0xa)", f1022, 2, 128},
  {"128:_mm_permute_pd(_mm_fnmsub_pd(x, y, x), 0x3)", f1023, 2, 128},
  {"128:_mm_sqrt_pd(_mm_fnmsub_pd(x, x, y))", f1024, 2, 128},
  {"128:_mm_xor_pd(_mm_fnmsub_pd(x, x, y), _mm_set1_pd(-0.0))", f1025, 2, 128},
  {"128:_mm_andnot_pd(_mm_set1_pd(-0.0), _mm_fnmsub_pd(x, x, y))", f1026, 2, 128},
  {"128:_mm_sub_pd(_mm_setzero_pd(), _mm_fnmsub_pd(x, x, y))", f1027, 2, 128},
  {"128:_mm_mul_pd(_mm_fnmsub_pd(x, x, y), _mm_set1_pd(-1.0))", f1028, 2, 128},
  {"128:_mm_floor_pd(_mm_fnmsub_pd(x, x, y))", f1029, 2, 128},
  {"128:_mm_ceil_pd(_mm_fnmsub_pd(x, x, y))", f1030, 2, 128},
  {"128:_mm_round_pd(_mm_fnmsub_pd(x, x, y), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)", f1031, 2, 128},
  {"128:_mm_permute_pd(_mm_fnmsub_pd(x, x, y), 0x5)", f1032, 2, 128},
  {"128:_mm_permute_pd(_mm_fnmsub_pd(x, x, y), 0xa)", f1033, 2, 128},
  {"128:_mm_permute_pd(_mm_fnmsub_pd(x, x, y), 0x3)", f1034, 2, 128},
  {"128:_mm_sqrt_pd(_mm_fnmsub_pd(x, y, _mm_mul_pd(x, y)))", f1035, 2, 128},
  {"128:_mm_xor_pd(_mm_fnmsub_pd(x, y, _mm_mul_pd(x, y)), _mm_set1_pd(-0.0))", f1036, 2, 128},
  {"128:_mm_andnot_pd(_mm_set1_pd(-0.0), _mm_fnmsub_pd(x, y, _mm_mul_pd(x, y)))", f1037, 2, 128},
  {"128:_mm_sub_pd(_mm_setzero_pd(), _mm_fnmsub_pd(x, y, _mm_mul_pd(x, y)))", f1038, 2, 128},
  {"128:_mm_mul_pd(_mm_fnmsub_pd(x, y, _mm_mul_pd(x, y)), _mm_set1_pd(-1.0))", f1039, 2, 128},
  {"128:_mm_floor_pd(_mm_fnmsub_pd(x, y, _mm_mul_pd(x, y)))", f1040, 2, 128},
  {"128:_mm_ceil_pd(_mm_fnmsub_pd(x, y, _mm_mul_pd(x, y)))", f1041, 2, 128},
  {"128:_mm_round_pd(_mm_fnmsub_pd(x, y, _mm_mul_pd(x, y)), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)", f1042, 2, 128},
  {"128:_mm_permute_pd(_mm_fnmsub_pd(x, y, _mm_mul_pd(x, y)), 0x5)", f1043, 2, 128},
  {"128:_mm_permute_pd(_mm_fnmsub_pd(x, y, _mm_mul_pd(x, y)), 0xa)", f1044, 2, 128},
  {"128:_mm_permute_pd(_mm_fnmsub_pd(x, y, _mm_mul_pd(x, y)), 0x3)", f1045, 2, 128},
  {"128:_mm_sqrt_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_GE_OS)))", f1046, 2, 128},
  {"128:_mm_xor_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_GE_OS)), _mm_set1_pd(-0.0))", f1047, 2, 128},
  {"128:_mm_andnot_pd(_mm_set1_pd(-0.0), _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_GE_OS)))", f1048, 2, 128},
  {"128:_mm_sub_pd(_mm_setzero_pd(), _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_GE_OS)))", f1049, 2, 128},
  {"128:_mm_mul_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_GE_OS)), _mm_set1_pd(-1.0))", f1050, 2, 128},
  {"128:_mm_floor_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_GE_OS)))", f1051, 2, 128},
  {"128:_mm_ceil_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_GE_OS)))", f1052, 2, 128},
  {"128:_mm_round_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_GE_OS)), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)", f1053, 2, 128},
  {"128:_mm_permute_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_GE_OS)), 0x5)", f1054, 2, 128},
  {"128:_mm_permute_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_GE_OS)), 0xa)", f1055, 2, 128},
  {"128:_mm_permute_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_GE_OS)), 0x3)", f1056, 2, 128},
  {"128:_mm_sqrt_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_GE_OS)))", f1057, 2, 128},
  {"128:_mm_xor_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_GE_OS)), _mm_set1_pd(-0.0))", f1058, 2, 128},
  {"128:_mm_andnot_pd(_mm_set1_pd(-0.0), _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_GE_OS)))", f1059, 2, 128},
  {"128:_mm_sub_pd(_mm_setzero_pd(), _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_GE_OS)))", f1060, 2, 128},
  {"128:_mm_mul_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_GE_OS)), _mm_set1_pd(-1.0))", f1061, 2, 128},
  {"128:_mm_floor_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_GE_OS)))", f1062, 2, 128},
  {"128:_mm_ceil_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_GE_OS)))", f1063, 2, 128},
  {"128:_mm_round_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_GE_OS)), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)", f1064, 2, 128},
  {"128:_mm_permute_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_GE_OS)), 0x5)", f1065, 2, 128},
  {"128:_mm_permute_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_GE_OS)), 0xa)", f1066, 2, 128},
  {"128:_mm_permute_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_GE_OS)), 0x3)", f1067, 2, 128},
  {"128:_mm_sqrt_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_NLE_US)))", f1068, 2, 128},
  {"128:_mm_xor_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_NLE_US)), _mm_set1_pd(-0.0))", f1069, 2, 128},
  {"128:_mm_andnot_pd(_mm_set1_pd(-0.0), _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_NLE_US)))", f1070, 2, 128},
  {"128:_mm_sub_pd(_mm_setzero_pd(), _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_NLE_US)))", f1071, 2, 128},
  {"128:_mm_mul_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_NLE_US)), _mm_set1_pd(-1.0))", f1072, 2, 128},
  {"128:_mm_floor_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_NLE_US)))", f1073, 2, 128},
  {"128:_mm_ceil_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_NLE_US)))", f1074, 2, 128},
  {"128:_mm_round_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_NLE_US)), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)", f1075, 2, 128},
  {"128:_mm_permute_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_NLE_US)), 0x5)", f1076, 2, 128},
  {"128:_mm_permute_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_NLE_US)), 0xa)", f1077, 2, 128},
  {"128:_mm_permute_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_NLE_US)), 0x3)", f1078, 2, 128},
  {"128:_mm_sqrt_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_NLE_US)))", f1079, 2, 128},
  {"128:_mm_xor_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_NLE_US)), _mm_set1_pd(-0.0))", f1080, 2, 128},
  {"128:_mm_andnot_pd(_mm_set1_pd(-0.0), _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_NLE_US)))", f1081, 2, 128},
  {"128:_mm_sub_pd(_mm_setzero_pd(), _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_NLE_US)))", f1082, 2, 128},
  {"128:_mm_mul_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_NLE_US)), _mm_set1_pd(-1.0))", f1083, 2, 128},
  {"128:_mm_floor_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_NLE_US)))", f1084, 2, 128},
  {"128:_mm_ceil_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_NLE_US)))", f1085, 2, 128},
  {"128:_mm_round_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_NLE_US)), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)", f1086, 2, 128},
  {"128:_mm_permute_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_NLE_US)), 0x5)", f1087, 2, 128},
  {"128:_mm_permute_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_NLE_US)), 0xa)", f1088, 2, 128},
  {"128:_mm_permute_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_NLE_US)), 0x3)", f1089, 2, 128},
  {"128:_mm_sqrt_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_NGT_US)))", f1090, 2, 128},
  {"128:_mm_xor_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_NGT_US)), _mm_set1_pd(-0.0))", f1091, 2, 128},
  {"128:_mm_andnot_pd(_mm_set1_pd(-0.0), _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_NGT_US)))", f1092, 2, 128},
  {"128:_mm_sub_pd(_mm_setzero_pd(), _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_NGT_US)))", f1093, 2, 128},
  {"128:_mm_mul_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_NGT_US)), _mm_set1_pd(-1.0))", f1094, 2, 128},
  {"128:_mm_floor_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_NGT_US)))", f1095, 2, 128},
  {"128:_mm_ceil_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_NGT_US)))", f1096, 2, 128},
  {"128:_mm_round_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_NGT_US)), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)", f1097, 2, 128},
  {"128:_mm_permute_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_NGT_US)), 0x5)", f1098, 2, 128},
  {"128:_mm_permute_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_NGT_US)), 0xa)", f1099, 2, 128},
  {"128:_mm_permute_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_NGT_US)), 0x3)", f1100, 2, 128},
  {"128:_mm_sqrt_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_NGT_US)))", f1101, 2, 128},
  {"128:_mm_xor_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_NGT_US)), _mm_set1_pd(-0.0))", f1102, 2, 128},
  {"128:_mm_andnot_pd(_mm_set1_pd(-0.0), _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_NGT_US)))", f1103, 2, 128},
  {"128:_mm_sub_pd(_mm_setzero_pd(), _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_NGT_US)))", f1104, 2, 128},
  {"128:_mm_mul_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_NGT_US)), _mm_set1_pd(-1.0))", f1105, 2, 128},
  {"128:_mm_floor_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_NGT_US)))", f1106, 2, 128},
  {"128:_mm_ceil_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_NGT_US)))", f1107, 2, 128},
  {"128:_mm_round_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_NGT_US)), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)", f1108, 2, 128},
  {"128:_mm_permute_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_NGT_US)), 0x5)", f1109, 2, 128},
  {"128:_mm_permute_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_NGT_US)), 0xa)", f1110, 2, 128},
  {"128:_mm_permute_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_NGT_US)), 0x3)", f1111, 2, 128},
  {"128:_mm_sqrt_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_LE_OQ)))", f1112, 2, 128},
  {"128:_mm_xor_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_LE_OQ)), _mm_set1_pd(-0.0))", f1113, 2, 128},
  {"128:_mm_andnot_pd(_mm_set1_pd(-0.0), _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_LE_OQ)))", f1114, 2, 128},
  {"128:_mm_sub_pd(_mm_setzero_pd(), _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_LE_OQ)))", f1115, 2, 128},
  {"128:_mm_mul_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_LE_OQ)), _mm_set1_pd(-1.0))", f1116, 2, 128},
  {"128:_mm_floor_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_LE_OQ)))", f1117, 2, 128},
  {"128:_mm_ceil_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_LE_OQ)))", f1118, 2, 128},
  {"128:_mm_round_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_LE_OQ)), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)", f1119, 2, 128},
  {"128:_mm_permute_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_LE_OQ)), 0x5)", f1120, 2, 128},
  {"128:_mm_permute_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_LE_OQ)), 0xa)", f1121, 2, 128},
  {"128:_mm_permute_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_LE_OQ)), 0x3)", f1122, 2, 128},
  {"128:_mm_sqrt_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_LE_OQ)))", f1123, 2, 128},
  {"128:_mm_xor_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_LE_OQ)), _mm_set1_pd(-0.0))", f1124, 2, 128},
  {"128:_mm_andnot_pd(_mm_set1_pd(-0.0), _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_LE_OQ)))", f1125, 2, 128},
  {"128:_mm_sub_pd(_mm_setzero_pd(), _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_LE_OQ)))", f1126, 2, 128},
  {"128:_mm_mul_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_LE_OQ)), _mm_set1_pd(-1.0))", f1127, 2, 128},
  {"128:_mm_floor_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_LE_OQ)))", f1128, 2, 128},
  {"128:_mm_ceil_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_LE_OQ)))", f1129, 2, 128},
  {"128:_mm_round_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_LE_OQ)), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)", f1130, 2, 128},
  {"128:_mm_permute_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_LE_OQ)), 0x5)", f1131, 2, 128},
  {"128:_mm_permute_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_LE_OQ)), 0xa)", f1132, 2, 128},
  {"128:_mm_permute_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_LE_OQ)), 0x3)", f1133, 2, 128},
  {"128:_mm_sqrt_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_GE_OQ)))", f1134, 2, 128},
  {"128:_mm_xor_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_GE_OQ)), _mm_set1_pd(-0.0))", f1135, 2, 128},
  {"128:_mm_andnot_pd(_mm_set1_pd(-0.0), _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_GE_OQ)))", f1136, 2, 128},
  {"128:_mm_sub_pd(_mm_setzero_pd(), _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_GE_OQ)))", f1137, 2, 128},
  {"128:_mm_mul_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_GE_OQ)), _mm_set1_pd(-1.0))", f1138, 2, 128},
  {"128:_mm_floor_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_GE_OQ)))", f1139, 2, 128},
  {"128:_mm_ceil_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_GE_OQ)))", f1140, 2, 128},
  {"128:_mm_round_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_GE_OQ)), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)", f1141, 2, 128},
  {"128:_mm_permute_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_GE_OQ)), 0x5)", f1142, 2, 128},
  {"128:_mm_permute_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_GE_OQ)), 0xa)", f1143, 2, 128},
  {"128:_mm_permute_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_GE_OQ)), 0x3)", f1144, 2, 128},
  {"128:_mm_sqrt_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_GE_OQ)))", f1145, 2, 128},
  {"128:_mm_xor_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_GE_OQ)), _mm_set1_pd(-0.0))", f1146, 2, 128},
  {"128:_mm_andnot_pd(_mm_set1_pd(-0.0), _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_GE_OQ)))", f1147, 2, 128},
  {"128:_mm_sub_pd(_mm_setzero_pd(), _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_GE_OQ)))", f1148, 2, 128},
  {"128:_mm_mul_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_GE_OQ)), _mm_set1_pd(-1.0))", f1149, 2, 128},
  {"128:_mm_floor_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_GE_OQ)))", f1150, 2, 128},
  {"128:_mm_ceil_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_GE_OQ)))", f1151, 2, 128},
  {"128:_mm_round_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_GE_OQ)), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)", f1152, 2, 128},
  {"128:_mm_permute_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_GE_OQ)), 0x5)", f1153, 2, 128},
  {"128:_mm_permute_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_GE_OQ)), 0xa)", f1154, 2, 128},
  {"128:_mm_permute_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_GE_OQ)), 0x3)", f1155, 2, 128},
  {"128:_mm_sqrt_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_LT_OQ)))", f1156, 2, 128},
  {"128:_mm_xor_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_LT_OQ)), _mm_set1_pd(-0.0))", f1157, 2, 128},
  {"128:_mm_andnot_pd(_mm_set1_pd(-0.0), _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_LT_OQ)))", f1158, 2, 128},
  {"128:_mm_sub_pd(_mm_setzero_pd(), _mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_LT_OQ)))", f1159, 2, 128},
  {"128:_mm_mul_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_LT_OQ)), _mm_set1_pd(-1.0))", f1160, 2, 128},
  {"128:_mm_floor_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_LT_OQ)))", f1161, 2, 128},
  {"128:_mm_ceil_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_LT_OQ)))", f1162, 2, 128},
  {"128:_mm_round_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_LT_OQ)), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)", f1163, 2, 128},
  {"128:_mm_permute_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_LT_OQ)), 0x5)", f1164, 2, 128},
  {"128:_mm_permute_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_LT_OQ)), 0xa)", f1165, 2, 128},
  {"128:_mm_permute_pd(_mm_blendv_pd(x, y, _mm_cmp_pd(x, y, _CMP_LT_OQ)), 0x3)", f1166, 2, 128},
  {"128:_mm_sqrt_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_LT_OQ)))", f1167, 2, 128},
  {"128:_mm_xor_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_LT_OQ)), _mm_set1_pd(-0.0))", f1168, 2, 128},
  {"128:_mm_andnot_pd(_mm_set1_pd(-0.0), _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_LT_OQ)))", f1169, 2, 128},
  {"128:_mm_sub_pd(_mm_setzero_pd(), _mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_LT_OQ)))", f1170, 2, 128},
  {"128:_mm_mul_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_LT_OQ)), _mm_set1_pd(-1.0))", f1171, 2, 128},
  {"128:_mm_floor_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_LT_OQ)))", f1172, 2, 128},
  {"128:_mm_ceil_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_LT_OQ)))", f1173, 2, 128},
  {"128:_mm_round_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_LT_OQ)), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)", f1174, 2, 128},
  {"128:_mm_permute_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_LT_OQ)), 0x5)", f1175, 2, 128},
  {"128:_mm_permute_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_LT_OQ)), 0xa)", f1176, 2, 128},
  {"128:_mm_permute_pd(_mm_blendv_pd(y, x, _mm_cmp_pd(x, y, _CMP_LT_OQ)), 0x3)", f1177, 2, 128},
  {"256:_mm256_abs_epi8(_mm256_abs_epi8(x))", f1178, 0, 256},
  {"256:_mm256_abs_epi8(_mm256_abs_epi16(x))", f1179, 0, 256},
  {"256:_mm256_abs_epi8(_mm256_abs_epi32(x))", f1180, 0, 256},
  {"256:_mm256_abs_epi8(_mm256_sub_epi8(_mm256_setzero_si256(), x))", f1181, 0, 256},
  {"256:_mm256_abs_epi8(_mm256_sub_epi16(_mm256_setzero_si256(), x))", f1182, 0, 256},
  {"256:_mm256_abs_epi8(_mm256_sub_epi32(_mm256_setzero_si256(), x))", f1183, 0, 256},
  {"256:_mm256_abs_epi8(_mm256_sub_epi64(_mm256_setzero_si256(), x))", f1184, 0, 256},
  {"256:_mm256_abs_epi8(_mm256_xor_si256(x, _mm256_set1_epi8((char)0xffu)))", f1185, 0, 256},
  {"256:_mm256_abs_epi8(_mm256_slli_epi16(x, 1))", f1186, 0, 256},
  {"256:_mm256_abs_epi8(_mm256_srli_epi16(x, 1))", f1187, 0, 256},
  {"256:_mm256_abs_epi8(_mm256_srai_epi16(x, 1))", f1188, 0, 256},
  {"256:_mm256_abs_epi8(_mm256_slli_epi16(x, 15))", f1189, 0, 256},
  {"256:_mm256_abs_epi8(_mm256_srli_epi16(x, 15))", f1190, 0, 256},
  {"256:_mm256_abs_epi8(_mm256_srai_epi16(x, 15))", f1191, 0, 256},
  {"256:_mm256_abs_epi8(_mm256_slli_epi32(x, 1))", f1192, 0, 256},
  {"256:_mm256_abs_epi8(_mm256_srli_epi32(x, 1))", f1193, 0, 256},
  {"256:_mm256_abs_epi8(_mm256_srai_epi32(x, 1))", f1194, 0, 256},
  {"256:_mm256_abs_epi8(_mm256_slli_epi32(x, 31))", f1195, 0, 256},
  {"256:_mm256_abs_epi8(_mm256_srli_epi32(x, 31))", f1196, 0, 256},
  {"256:_mm256_abs_epi8(_mm256_srai_epi32(x, 31))", f1197, 0, 256},
  {"256:_mm256_abs_epi8(_mm256_slli_epi64(x, 1))", f1198, 0, 256},
  {"256:_mm256_abs_epi8(_mm256_srli_epi64(x, 1))", f1199, 0, 256},
};
extern const int size_42 = 1200;
