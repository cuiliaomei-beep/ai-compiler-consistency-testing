#include "common.h"
static NOINLINE void f0(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_slli_epi32(_mm_hadd_epi32(x, y), 31); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_hadd_epi32(_mm_slli_epi32(x, 31), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f2(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_hadd_epi32(x, _mm_slli_epi32(y, 31)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f3(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_hadd_epi32(_mm_slli_epi32(x, 31), _mm_slli_epi32(y, 31)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f4(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_hadd_epi32(x, _mm_slli_epi32(x, 31)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f5(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_hadd_epi32(_mm_slli_epi32(x, 31), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f6(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_slli_epi32(_mm_hsub_epi32(x, y), 31); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f7(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_hsub_epi32(_mm_slli_epi32(x, 31), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f8(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_hsub_epi32(x, _mm_slli_epi32(y, 31)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f9(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_hsub_epi32(_mm_slli_epi32(x, 31), _mm_slli_epi32(y, 31)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f10(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_hsub_epi32(x, _mm_slli_epi32(x, 31)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f11(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_hsub_epi32(_mm_slli_epi32(x, 31), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f12(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_slli_epi32(_mm_mul_epi32(x, y), 31); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f13(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_mul_epi32(_mm_slli_epi32(x, 31), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f14(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_mul_epi32(x, _mm_slli_epi32(y, 31)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f15(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_mul_epi32(_mm_slli_epi32(x, 31), _mm_slli_epi32(y, 31)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f16(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_mul_epi32(x, _mm_slli_epi32(x, 31)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f17(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_mul_epi32(_mm_slli_epi32(x, 31), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f18(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_slli_epi32(_mm_mul_epu32(x, y), 31); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f19(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_mul_epu32(_mm_slli_epi32(x, 31), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f20(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_mul_epu32(x, _mm_slli_epi32(y, 31)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f21(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_mul_epu32(_mm_slli_epi32(x, 31), _mm_slli_epi32(y, 31)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f22(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_mul_epu32(x, _mm_slli_epi32(x, 31)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f23(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_mul_epu32(_mm_slli_epi32(x, 31), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f24(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_slli_epi32(_mm_unpacklo_epi32(x, y), 31); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f25(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_unpacklo_epi32(_mm_slli_epi32(x, 31), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f26(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_unpacklo_epi32(x, _mm_slli_epi32(y, 31)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f27(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_unpacklo_epi32(_mm_slli_epi32(x, 31), _mm_slli_epi32(y, 31)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f28(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_unpacklo_epi32(x, _mm_slli_epi32(x, 31)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f29(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_unpacklo_epi32(_mm_slli_epi32(x, 31), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f30(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_slli_epi32(_mm_unpackhi_epi32(x, y), 31); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f31(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_unpackhi_epi32(_mm_slli_epi32(x, 31), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f32(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_unpackhi_epi32(x, _mm_slli_epi32(y, 31)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f33(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_unpackhi_epi32(_mm_slli_epi32(x, 31), _mm_slli_epi32(y, 31)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f34(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_unpackhi_epi32(x, _mm_slli_epi32(x, 31)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f35(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_unpackhi_epi32(_mm_slli_epi32(x, 31), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f36(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_slli_epi32(_mm_blendv_epi8(x, y, _mm_cmpgt_epi32(x, y)), 31); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f37(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_blendv_epi8(_mm_slli_epi32(x, 31), y, _mm_cmpgt_epi32(_mm_slli_epi32(x, 31), y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f38(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_blendv_epi8(x, _mm_slli_epi32(y, 31), _mm_cmpgt_epi32(x, _mm_slli_epi32(y, 31))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f39(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_blendv_epi8(_mm_slli_epi32(x, 31), _mm_slli_epi32(y, 31), _mm_cmpgt_epi32(_mm_slli_epi32(x, 31), _mm_slli_epi32(y, 31))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f40(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_blendv_epi8(x, _mm_slli_epi32(x, 31), _mm_cmpgt_epi32(x, _mm_slli_epi32(x, 31))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f41(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_blendv_epi8(_mm_slli_epi32(x, 31), x, _mm_cmpgt_epi32(_mm_slli_epi32(x, 31), x)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f42(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_slli_epi32(_mm_blendv_epi8(y, x, _mm_cmpgt_epi32(x, y)), 31); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f43(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_blendv_epi8(y, _mm_slli_epi32(x, 31), _mm_cmpgt_epi32(_mm_slli_epi32(x, 31), y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f44(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_blendv_epi8(_mm_slli_epi32(y, 31), x, _mm_cmpgt_epi32(x, _mm_slli_epi32(y, 31))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f45(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_blendv_epi8(_mm_slli_epi32(y, 31), _mm_slli_epi32(x, 31), _mm_cmpgt_epi32(_mm_slli_epi32(x, 31), _mm_slli_epi32(y, 31))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f46(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_blendv_epi8(_mm_slli_epi32(x, 31), x, _mm_cmpgt_epi32(x, _mm_slli_epi32(x, 31))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f47(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_blendv_epi8(x, _mm_slli_epi32(x, 31), _mm_cmpgt_epi32(_mm_slli_epi32(x, 31), x)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f48(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_slli_epi32(_mm_or_si128(_mm_and_si128(_mm_cmpgt_epi32(x, y), x), _mm_andnot_si128(_mm_cmpgt_epi32(x, y), y)), 31); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f49(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_or_si128(_mm_and_si128(_mm_cmpgt_epi32(_mm_slli_epi32(x, 31), y), _mm_slli_epi32(x, 31)), _mm_andnot_si128(_mm_cmpgt_epi32(_mm_slli_epi32(x, 31), y), y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f50(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_or_si128(_mm_and_si128(_mm_cmpgt_epi32(x, _mm_slli_epi32(y, 31)), x), _mm_andnot_si128(_mm_cmpgt_epi32(x, _mm_slli_epi32(y, 31)), _mm_slli_epi32(y, 31))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f51(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_or_si128(_mm_and_si128(_mm_cmpgt_epi32(_mm_slli_epi32(x, 31), _mm_slli_epi32(y, 31)), _mm_slli_epi32(x, 31)), _mm_andnot_si128(_mm_cmpgt_epi32(_mm_slli_epi32(x, 31), _mm_slli_epi32(y, 31)), _mm_slli_epi32(y, 31))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f52(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_or_si128(_mm_and_si128(_mm_cmpgt_epi32(x, _mm_slli_epi32(x, 31)), x), _mm_andnot_si128(_mm_cmpgt_epi32(x, _mm_slli_epi32(x, 31)), _mm_slli_epi32(x, 31))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f53(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_or_si128(_mm_and_si128(_mm_cmpgt_epi32(_mm_slli_epi32(x, 31), x), _mm_slli_epi32(x, 31)), _mm_andnot_si128(_mm_cmpgt_epi32(_mm_slli_epi32(x, 31), x), x)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f54(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_slli_epi32(_mm_blendv_epi8(x, y, _mm_cmpeq_epi32(x, y)), 31); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f55(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_blendv_epi8(_mm_slli_epi32(x, 31), y, _mm_cmpeq_epi32(_mm_slli_epi32(x, 31), y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f56(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_blendv_epi8(x, _mm_slli_epi32(y, 31), _mm_cmpeq_epi32(x, _mm_slli_epi32(y, 31))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f57(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_blendv_epi8(_mm_slli_epi32(x, 31), _mm_slli_epi32(y, 31), _mm_cmpeq_epi32(_mm_slli_epi32(x, 31), _mm_slli_epi32(y, 31))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f58(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_blendv_epi8(x, _mm_slli_epi32(x, 31), _mm_cmpeq_epi32(x, _mm_slli_epi32(x, 31))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f59(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_blendv_epi8(_mm_slli_epi32(x, 31), x, _mm_cmpeq_epi32(_mm_slli_epi32(x, 31), x)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f60(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_slli_epi32(_mm_blendv_epi8(y, x, _mm_cmpeq_epi32(x, y)), 31); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f61(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_blendv_epi8(y, _mm_slli_epi32(x, 31), _mm_cmpeq_epi32(_mm_slli_epi32(x, 31), y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f62(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_blendv_epi8(_mm_slli_epi32(y, 31), x, _mm_cmpeq_epi32(x, _mm_slli_epi32(y, 31))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f63(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_blendv_epi8(_mm_slli_epi32(y, 31), _mm_slli_epi32(x, 31), _mm_cmpeq_epi32(_mm_slli_epi32(x, 31), _mm_slli_epi32(y, 31))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f64(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_blendv_epi8(_mm_slli_epi32(x, 31), x, _mm_cmpeq_epi32(x, _mm_slli_epi32(x, 31))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f65(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_blendv_epi8(x, _mm_slli_epi32(x, 31), _mm_cmpeq_epi32(_mm_slli_epi32(x, 31), x)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f66(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_slli_epi32(_mm_or_si128(_mm_and_si128(_mm_cmpeq_epi32(x, y), x), _mm_andnot_si128(_mm_cmpeq_epi32(x, y), y)), 31); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f67(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_or_si128(_mm_and_si128(_mm_cmpeq_epi32(_mm_slli_epi32(x, 31), y), _mm_slli_epi32(x, 31)), _mm_andnot_si128(_mm_cmpeq_epi32(_mm_slli_epi32(x, 31), y), y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f68(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_or_si128(_mm_and_si128(_mm_cmpeq_epi32(x, _mm_slli_epi32(y, 31)), x), _mm_andnot_si128(_mm_cmpeq_epi32(x, _mm_slli_epi32(y, 31)), _mm_slli_epi32(y, 31))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f69(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_or_si128(_mm_and_si128(_mm_cmpeq_epi32(_mm_slli_epi32(x, 31), _mm_slli_epi32(y, 31)), _mm_slli_epi32(x, 31)), _mm_andnot_si128(_mm_cmpeq_epi32(_mm_slli_epi32(x, 31), _mm_slli_epi32(y, 31)), _mm_slli_epi32(y, 31))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f70(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_or_si128(_mm_and_si128(_mm_cmpeq_epi32(x, _mm_slli_epi32(x, 31)), x), _mm_andnot_si128(_mm_cmpeq_epi32(x, _mm_slli_epi32(x, 31)), _mm_slli_epi32(x, 31))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f71(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_or_si128(_mm_and_si128(_mm_cmpeq_epi32(_mm_slli_epi32(x, 31), x), _mm_slli_epi32(x, 31)), _mm_andnot_si128(_mm_cmpeq_epi32(_mm_slli_epi32(x, 31), x), x)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f72(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_slli_epi32(_mm_mullo_epi32(x, y), 31); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f73(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_mullo_epi32(_mm_slli_epi32(x, 31), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f74(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_mullo_epi32(x, _mm_slli_epi32(y, 31)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f75(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_mullo_epi32(_mm_slli_epi32(x, 31), _mm_slli_epi32(y, 31)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f76(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_mullo_epi32(x, _mm_slli_epi32(x, 31)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f77(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_mullo_epi32(_mm_slli_epi32(x, 31), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f78(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_slli_epi32(_mm_sllv_epi32(x, y), 31); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f79(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi32(_mm_slli_epi32(x, 31), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f80(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi32(x, _mm_slli_epi32(y, 31)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f81(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi32(_mm_slli_epi32(x, 31), _mm_slli_epi32(y, 31)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f82(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi32(x, _mm_slli_epi32(x, 31)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f83(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi32(_mm_slli_epi32(x, 31), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f84(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_slli_epi32(_mm_srlv_epi32(x, y), 31); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f85(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi32(_mm_slli_epi32(x, 31), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f86(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi32(x, _mm_slli_epi32(y, 31)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f87(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi32(_mm_slli_epi32(x, 31), _mm_slli_epi32(y, 31)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f88(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi32(x, _mm_slli_epi32(x, 31)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f89(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi32(_mm_slli_epi32(x, 31), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f90(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_slli_epi32(_mm_srav_epi32(x, y), 31); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f91(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srav_epi32(_mm_slli_epi32(x, 31), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f92(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srav_epi32(x, _mm_slli_epi32(y, 31)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f93(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srav_epi32(_mm_slli_epi32(x, 31), _mm_slli_epi32(y, 31)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f94(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srav_epi32(x, _mm_slli_epi32(x, 31)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f95(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srav_epi32(_mm_slli_epi32(x, 31), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f96(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srli_epi32(_mm_add_epi32(x, y), 31); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f97(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_add_epi32(_mm_srli_epi32(x, 31), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f98(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_add_epi32(x, _mm_srli_epi32(y, 31)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f99(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_add_epi32(_mm_srli_epi32(x, 31), _mm_srli_epi32(y, 31)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f100(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_add_epi32(x, _mm_srli_epi32(x, 31)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f101(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_add_epi32(_mm_srli_epi32(x, 31), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f102(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srli_epi32(_mm_sub_epi32(x, y), 31); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f103(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sub_epi32(_mm_srli_epi32(x, 31), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f104(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sub_epi32(x, _mm_srli_epi32(y, 31)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f105(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sub_epi32(_mm_srli_epi32(x, 31), _mm_srli_epi32(y, 31)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f106(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sub_epi32(x, _mm_srli_epi32(x, 31)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f107(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sub_epi32(_mm_srli_epi32(x, 31), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f108(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srli_epi32(_mm_min_epi32(x, y), 31); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f109(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_min_epi32(_mm_srli_epi32(x, 31), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f110(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_min_epi32(x, _mm_srli_epi32(y, 31)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f111(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_min_epi32(_mm_srli_epi32(x, 31), _mm_srli_epi32(y, 31)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f112(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_min_epi32(x, _mm_srli_epi32(x, 31)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f113(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_min_epi32(_mm_srli_epi32(x, 31), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f114(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srli_epi32(_mm_max_epi32(x, y), 31); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f115(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_max_epi32(_mm_srli_epi32(x, 31), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f116(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_max_epi32(x, _mm_srli_epi32(y, 31)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f117(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_max_epi32(_mm_srli_epi32(x, 31), _mm_srli_epi32(y, 31)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f118(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_max_epi32(x, _mm_srli_epi32(x, 31)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f119(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_max_epi32(_mm_srli_epi32(x, 31), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f120(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srli_epi32(_mm_min_epu32(x, y), 31); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f121(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_min_epu32(_mm_srli_epi32(x, 31), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f122(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_min_epu32(x, _mm_srli_epi32(y, 31)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f123(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_min_epu32(_mm_srli_epi32(x, 31), _mm_srli_epi32(y, 31)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f124(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_min_epu32(x, _mm_srli_epi32(x, 31)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f125(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_min_epu32(_mm_srli_epi32(x, 31), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f126(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srli_epi32(_mm_max_epu32(x, y), 31); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f127(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_max_epu32(_mm_srli_epi32(x, 31), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f128(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_max_epu32(x, _mm_srli_epi32(y, 31)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f129(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_max_epu32(_mm_srli_epi32(x, 31), _mm_srli_epi32(y, 31)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f130(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_max_epu32(x, _mm_srli_epi32(x, 31)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f131(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_max_epu32(_mm_srli_epi32(x, 31), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f132(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srli_epi32(_mm_and_si128(x, y), 31); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f133(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_and_si128(_mm_srli_epi32(x, 31), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f134(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_and_si128(x, _mm_srli_epi32(y, 31)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f135(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_and_si128(_mm_srli_epi32(x, 31), _mm_srli_epi32(y, 31)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f136(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_and_si128(x, _mm_srli_epi32(x, 31)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f137(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_and_si128(_mm_srli_epi32(x, 31), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f138(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srli_epi32(_mm_or_si128(x, y), 31); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f139(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_or_si128(_mm_srli_epi32(x, 31), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f140(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_or_si128(x, _mm_srli_epi32(y, 31)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f141(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_or_si128(_mm_srli_epi32(x, 31), _mm_srli_epi32(y, 31)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f142(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_or_si128(x, _mm_srli_epi32(x, 31)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f143(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_or_si128(_mm_srli_epi32(x, 31), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f144(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srli_epi32(_mm_xor_si128(x, y), 31); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f145(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_xor_si128(_mm_srli_epi32(x, 31), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f146(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_xor_si128(x, _mm_srli_epi32(y, 31)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f147(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_xor_si128(_mm_srli_epi32(x, 31), _mm_srli_epi32(y, 31)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f148(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_xor_si128(x, _mm_srli_epi32(x, 31)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f149(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_xor_si128(_mm_srli_epi32(x, 31), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f150(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srli_epi32(_mm_andnot_si128(x, y), 31); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f151(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_andnot_si128(_mm_srli_epi32(x, 31), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f152(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_andnot_si128(x, _mm_srli_epi32(y, 31)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f153(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_andnot_si128(_mm_srli_epi32(x, 31), _mm_srli_epi32(y, 31)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f154(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_andnot_si128(x, _mm_srli_epi32(x, 31)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f155(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_andnot_si128(_mm_srli_epi32(x, 31), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f156(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srli_epi32(_mm_cmpeq_epi32(x, y), 31); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f157(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_cmpeq_epi32(_mm_srli_epi32(x, 31), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f158(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_cmpeq_epi32(x, _mm_srli_epi32(y, 31)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f159(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_cmpeq_epi32(_mm_srli_epi32(x, 31), _mm_srli_epi32(y, 31)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f160(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_cmpeq_epi32(x, _mm_srli_epi32(x, 31)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f161(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_cmpeq_epi32(_mm_srli_epi32(x, 31), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f162(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srli_epi32(_mm_cmpgt_epi32(x, y), 31); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f163(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_cmpgt_epi32(_mm_srli_epi32(x, 31), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f164(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_cmpgt_epi32(x, _mm_srli_epi32(y, 31)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f165(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_cmpgt_epi32(_mm_srli_epi32(x, 31), _mm_srli_epi32(y, 31)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f166(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_cmpgt_epi32(x, _mm_srli_epi32(x, 31)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f167(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_cmpgt_epi32(_mm_srli_epi32(x, 31), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f168(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srli_epi32(_mm_sign_epi32(x, y), 31); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f169(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sign_epi32(_mm_srli_epi32(x, 31), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f170(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sign_epi32(x, _mm_srli_epi32(y, 31)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f171(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sign_epi32(_mm_srli_epi32(x, 31), _mm_srli_epi32(y, 31)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f172(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sign_epi32(x, _mm_srli_epi32(x, 31)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f173(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sign_epi32(_mm_srli_epi32(x, 31), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f174(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srli_epi32(_mm_packs_epi32(x, y), 31); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f175(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_packs_epi32(_mm_srli_epi32(x, 31), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f176(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_packs_epi32(x, _mm_srli_epi32(y, 31)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f177(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_packs_epi32(_mm_srli_epi32(x, 31), _mm_srli_epi32(y, 31)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f178(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_packs_epi32(x, _mm_srli_epi32(x, 31)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f179(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_packs_epi32(_mm_srli_epi32(x, 31), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f180(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srli_epi32(_mm_packus_epi32(x, y), 31); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f181(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_packus_epi32(_mm_srli_epi32(x, 31), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f182(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_packus_epi32(x, _mm_srli_epi32(y, 31)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f183(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_packus_epi32(_mm_srli_epi32(x, 31), _mm_srli_epi32(y, 31)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f184(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_packus_epi32(x, _mm_srli_epi32(x, 31)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f185(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_packus_epi32(_mm_srli_epi32(x, 31), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f186(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srli_epi32(_mm_hadd_epi32(x, y), 31); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f187(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_hadd_epi32(_mm_srli_epi32(x, 31), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f188(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_hadd_epi32(x, _mm_srli_epi32(y, 31)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f189(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_hadd_epi32(_mm_srli_epi32(x, 31), _mm_srli_epi32(y, 31)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f190(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_hadd_epi32(x, _mm_srli_epi32(x, 31)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f191(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_hadd_epi32(_mm_srli_epi32(x, 31), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f192(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srli_epi32(_mm_hsub_epi32(x, y), 31); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f193(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_hsub_epi32(_mm_srli_epi32(x, 31), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f194(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_hsub_epi32(x, _mm_srli_epi32(y, 31)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f195(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_hsub_epi32(_mm_srli_epi32(x, 31), _mm_srli_epi32(y, 31)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f196(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_hsub_epi32(x, _mm_srli_epi32(x, 31)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f197(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_hsub_epi32(_mm_srli_epi32(x, 31), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f198(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srli_epi32(_mm_mul_epi32(x, y), 31); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f199(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_mul_epi32(_mm_srli_epi32(x, 31), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f200(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_mul_epi32(x, _mm_srli_epi32(y, 31)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f201(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_mul_epi32(_mm_srli_epi32(x, 31), _mm_srli_epi32(y, 31)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f202(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_mul_epi32(x, _mm_srli_epi32(x, 31)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f203(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_mul_epi32(_mm_srli_epi32(x, 31), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f204(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srli_epi32(_mm_mul_epu32(x, y), 31); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f205(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_mul_epu32(_mm_srli_epi32(x, 31), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f206(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_mul_epu32(x, _mm_srli_epi32(y, 31)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f207(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_mul_epu32(_mm_srli_epi32(x, 31), _mm_srli_epi32(y, 31)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f208(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_mul_epu32(x, _mm_srli_epi32(x, 31)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f209(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_mul_epu32(_mm_srli_epi32(x, 31), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f210(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srli_epi32(_mm_unpacklo_epi32(x, y), 31); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f211(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_unpacklo_epi32(_mm_srli_epi32(x, 31), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f212(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_unpacklo_epi32(x, _mm_srli_epi32(y, 31)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f213(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_unpacklo_epi32(_mm_srli_epi32(x, 31), _mm_srli_epi32(y, 31)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f214(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_unpacklo_epi32(x, _mm_srli_epi32(x, 31)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f215(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_unpacklo_epi32(_mm_srli_epi32(x, 31), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f216(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srli_epi32(_mm_unpackhi_epi32(x, y), 31); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f217(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_unpackhi_epi32(_mm_srli_epi32(x, 31), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f218(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_unpackhi_epi32(x, _mm_srli_epi32(y, 31)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f219(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_unpackhi_epi32(_mm_srli_epi32(x, 31), _mm_srli_epi32(y, 31)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f220(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_unpackhi_epi32(x, _mm_srli_epi32(x, 31)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f221(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_unpackhi_epi32(_mm_srli_epi32(x, 31), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f222(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srli_epi32(_mm_blendv_epi8(x, y, _mm_cmpgt_epi32(x, y)), 31); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f223(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_blendv_epi8(_mm_srli_epi32(x, 31), y, _mm_cmpgt_epi32(_mm_srli_epi32(x, 31), y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f224(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_blendv_epi8(x, _mm_srli_epi32(y, 31), _mm_cmpgt_epi32(x, _mm_srli_epi32(y, 31))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f225(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_blendv_epi8(_mm_srli_epi32(x, 31), _mm_srli_epi32(y, 31), _mm_cmpgt_epi32(_mm_srli_epi32(x, 31), _mm_srli_epi32(y, 31))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f226(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_blendv_epi8(x, _mm_srli_epi32(x, 31), _mm_cmpgt_epi32(x, _mm_srli_epi32(x, 31))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f227(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_blendv_epi8(_mm_srli_epi32(x, 31), x, _mm_cmpgt_epi32(_mm_srli_epi32(x, 31), x)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f228(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srli_epi32(_mm_blendv_epi8(y, x, _mm_cmpgt_epi32(x, y)), 31); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f229(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_blendv_epi8(y, _mm_srli_epi32(x, 31), _mm_cmpgt_epi32(_mm_srli_epi32(x, 31), y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f230(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_blendv_epi8(_mm_srli_epi32(y, 31), x, _mm_cmpgt_epi32(x, _mm_srli_epi32(y, 31))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f231(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_blendv_epi8(_mm_srli_epi32(y, 31), _mm_srli_epi32(x, 31), _mm_cmpgt_epi32(_mm_srli_epi32(x, 31), _mm_srli_epi32(y, 31))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f232(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_blendv_epi8(_mm_srli_epi32(x, 31), x, _mm_cmpgt_epi32(x, _mm_srli_epi32(x, 31))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f233(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_blendv_epi8(x, _mm_srli_epi32(x, 31), _mm_cmpgt_epi32(_mm_srli_epi32(x, 31), x)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f234(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srli_epi32(_mm_or_si128(_mm_and_si128(_mm_cmpgt_epi32(x, y), x), _mm_andnot_si128(_mm_cmpgt_epi32(x, y), y)), 31); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f235(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_or_si128(_mm_and_si128(_mm_cmpgt_epi32(_mm_srli_epi32(x, 31), y), _mm_srli_epi32(x, 31)), _mm_andnot_si128(_mm_cmpgt_epi32(_mm_srli_epi32(x, 31), y), y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f236(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_or_si128(_mm_and_si128(_mm_cmpgt_epi32(x, _mm_srli_epi32(y, 31)), x), _mm_andnot_si128(_mm_cmpgt_epi32(x, _mm_srli_epi32(y, 31)), _mm_srli_epi32(y, 31))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f237(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_or_si128(_mm_and_si128(_mm_cmpgt_epi32(_mm_srli_epi32(x, 31), _mm_srli_epi32(y, 31)), _mm_srli_epi32(x, 31)), _mm_andnot_si128(_mm_cmpgt_epi32(_mm_srli_epi32(x, 31), _mm_srli_epi32(y, 31)), _mm_srli_epi32(y, 31))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f238(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_or_si128(_mm_and_si128(_mm_cmpgt_epi32(x, _mm_srli_epi32(x, 31)), x), _mm_andnot_si128(_mm_cmpgt_epi32(x, _mm_srli_epi32(x, 31)), _mm_srli_epi32(x, 31))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f239(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_or_si128(_mm_and_si128(_mm_cmpgt_epi32(_mm_srli_epi32(x, 31), x), _mm_srli_epi32(x, 31)), _mm_andnot_si128(_mm_cmpgt_epi32(_mm_srli_epi32(x, 31), x), x)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f240(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srli_epi32(_mm_blendv_epi8(x, y, _mm_cmpeq_epi32(x, y)), 31); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f241(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_blendv_epi8(_mm_srli_epi32(x, 31), y, _mm_cmpeq_epi32(_mm_srli_epi32(x, 31), y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f242(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_blendv_epi8(x, _mm_srli_epi32(y, 31), _mm_cmpeq_epi32(x, _mm_srli_epi32(y, 31))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f243(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_blendv_epi8(_mm_srli_epi32(x, 31), _mm_srli_epi32(y, 31), _mm_cmpeq_epi32(_mm_srli_epi32(x, 31), _mm_srli_epi32(y, 31))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f244(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_blendv_epi8(x, _mm_srli_epi32(x, 31), _mm_cmpeq_epi32(x, _mm_srli_epi32(x, 31))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f245(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_blendv_epi8(_mm_srli_epi32(x, 31), x, _mm_cmpeq_epi32(_mm_srli_epi32(x, 31), x)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f246(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srli_epi32(_mm_blendv_epi8(y, x, _mm_cmpeq_epi32(x, y)), 31); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f247(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_blendv_epi8(y, _mm_srli_epi32(x, 31), _mm_cmpeq_epi32(_mm_srli_epi32(x, 31), y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f248(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_blendv_epi8(_mm_srli_epi32(y, 31), x, _mm_cmpeq_epi32(x, _mm_srli_epi32(y, 31))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f249(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_blendv_epi8(_mm_srli_epi32(y, 31), _mm_srli_epi32(x, 31), _mm_cmpeq_epi32(_mm_srli_epi32(x, 31), _mm_srli_epi32(y, 31))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f250(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_blendv_epi8(_mm_srli_epi32(x, 31), x, _mm_cmpeq_epi32(x, _mm_srli_epi32(x, 31))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f251(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_blendv_epi8(x, _mm_srli_epi32(x, 31), _mm_cmpeq_epi32(_mm_srli_epi32(x, 31), x)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f252(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srli_epi32(_mm_or_si128(_mm_and_si128(_mm_cmpeq_epi32(x, y), x), _mm_andnot_si128(_mm_cmpeq_epi32(x, y), y)), 31); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f253(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_or_si128(_mm_and_si128(_mm_cmpeq_epi32(_mm_srli_epi32(x, 31), y), _mm_srli_epi32(x, 31)), _mm_andnot_si128(_mm_cmpeq_epi32(_mm_srli_epi32(x, 31), y), y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f254(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_or_si128(_mm_and_si128(_mm_cmpeq_epi32(x, _mm_srli_epi32(y, 31)), x), _mm_andnot_si128(_mm_cmpeq_epi32(x, _mm_srli_epi32(y, 31)), _mm_srli_epi32(y, 31))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f255(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_or_si128(_mm_and_si128(_mm_cmpeq_epi32(_mm_srli_epi32(x, 31), _mm_srli_epi32(y, 31)), _mm_srli_epi32(x, 31)), _mm_andnot_si128(_mm_cmpeq_epi32(_mm_srli_epi32(x, 31), _mm_srli_epi32(y, 31)), _mm_srli_epi32(y, 31))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f256(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_or_si128(_mm_and_si128(_mm_cmpeq_epi32(x, _mm_srli_epi32(x, 31)), x), _mm_andnot_si128(_mm_cmpeq_epi32(x, _mm_srli_epi32(x, 31)), _mm_srli_epi32(x, 31))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f257(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_or_si128(_mm_and_si128(_mm_cmpeq_epi32(_mm_srli_epi32(x, 31), x), _mm_srli_epi32(x, 31)), _mm_andnot_si128(_mm_cmpeq_epi32(_mm_srli_epi32(x, 31), x), x)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f258(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srli_epi32(_mm_mullo_epi32(x, y), 31); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f259(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_mullo_epi32(_mm_srli_epi32(x, 31), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f260(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_mullo_epi32(x, _mm_srli_epi32(y, 31)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f261(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_mullo_epi32(_mm_srli_epi32(x, 31), _mm_srli_epi32(y, 31)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f262(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_mullo_epi32(x, _mm_srli_epi32(x, 31)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f263(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_mullo_epi32(_mm_srli_epi32(x, 31), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f264(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srli_epi32(_mm_sllv_epi32(x, y), 31); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f265(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi32(_mm_srli_epi32(x, 31), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f266(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi32(x, _mm_srli_epi32(y, 31)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f267(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi32(_mm_srli_epi32(x, 31), _mm_srli_epi32(y, 31)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f268(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi32(x, _mm_srli_epi32(x, 31)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f269(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi32(_mm_srli_epi32(x, 31), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f270(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srli_epi32(_mm_srlv_epi32(x, y), 31); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f271(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi32(_mm_srli_epi32(x, 31), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f272(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi32(x, _mm_srli_epi32(y, 31)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f273(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi32(_mm_srli_epi32(x, 31), _mm_srli_epi32(y, 31)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f274(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi32(x, _mm_srli_epi32(x, 31)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f275(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi32(_mm_srli_epi32(x, 31), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f276(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srli_epi32(_mm_srav_epi32(x, y), 31); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f277(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srav_epi32(_mm_srli_epi32(x, 31), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f278(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srav_epi32(x, _mm_srli_epi32(y, 31)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f279(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srav_epi32(_mm_srli_epi32(x, 31), _mm_srli_epi32(y, 31)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f280(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srav_epi32(x, _mm_srli_epi32(x, 31)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f281(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srav_epi32(_mm_srli_epi32(x, 31), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f282(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srai_epi32(_mm_add_epi32(x, y), 31); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f283(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_add_epi32(_mm_srai_epi32(x, 31), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f284(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_add_epi32(x, _mm_srai_epi32(y, 31)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f285(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_add_epi32(_mm_srai_epi32(x, 31), _mm_srai_epi32(y, 31)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f286(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_add_epi32(x, _mm_srai_epi32(x, 31)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f287(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_add_epi32(_mm_srai_epi32(x, 31), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f288(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srai_epi32(_mm_sub_epi32(x, y), 31); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f289(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sub_epi32(_mm_srai_epi32(x, 31), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f290(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sub_epi32(x, _mm_srai_epi32(y, 31)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f291(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sub_epi32(_mm_srai_epi32(x, 31), _mm_srai_epi32(y, 31)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f292(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sub_epi32(x, _mm_srai_epi32(x, 31)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f293(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sub_epi32(_mm_srai_epi32(x, 31), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f294(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srai_epi32(_mm_min_epi32(x, y), 31); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f295(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_min_epi32(_mm_srai_epi32(x, 31), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f296(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_min_epi32(x, _mm_srai_epi32(y, 31)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f297(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_min_epi32(_mm_srai_epi32(x, 31), _mm_srai_epi32(y, 31)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f298(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_min_epi32(x, _mm_srai_epi32(x, 31)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f299(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_min_epi32(_mm_srai_epi32(x, 31), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f300(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srai_epi32(_mm_max_epi32(x, y), 31); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f301(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_max_epi32(_mm_srai_epi32(x, 31), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f302(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_max_epi32(x, _mm_srai_epi32(y, 31)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f303(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_max_epi32(_mm_srai_epi32(x, 31), _mm_srai_epi32(y, 31)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f304(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_max_epi32(x, _mm_srai_epi32(x, 31)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f305(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_max_epi32(_mm_srai_epi32(x, 31), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f306(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srai_epi32(_mm_min_epu32(x, y), 31); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f307(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_min_epu32(_mm_srai_epi32(x, 31), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f308(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_min_epu32(x, _mm_srai_epi32(y, 31)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f309(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_min_epu32(_mm_srai_epi32(x, 31), _mm_srai_epi32(y, 31)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f310(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_min_epu32(x, _mm_srai_epi32(x, 31)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f311(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_min_epu32(_mm_srai_epi32(x, 31), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f312(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srai_epi32(_mm_max_epu32(x, y), 31); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f313(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_max_epu32(_mm_srai_epi32(x, 31), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f314(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_max_epu32(x, _mm_srai_epi32(y, 31)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f315(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_max_epu32(_mm_srai_epi32(x, 31), _mm_srai_epi32(y, 31)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f316(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_max_epu32(x, _mm_srai_epi32(x, 31)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f317(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_max_epu32(_mm_srai_epi32(x, 31), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f318(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srai_epi32(_mm_and_si128(x, y), 31); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f319(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_and_si128(_mm_srai_epi32(x, 31), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f320(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_and_si128(x, _mm_srai_epi32(y, 31)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f321(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_and_si128(_mm_srai_epi32(x, 31), _mm_srai_epi32(y, 31)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f322(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_and_si128(x, _mm_srai_epi32(x, 31)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f323(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_and_si128(_mm_srai_epi32(x, 31), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f324(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srai_epi32(_mm_or_si128(x, y), 31); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f325(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_or_si128(_mm_srai_epi32(x, 31), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f326(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_or_si128(x, _mm_srai_epi32(y, 31)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f327(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_or_si128(_mm_srai_epi32(x, 31), _mm_srai_epi32(y, 31)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f328(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_or_si128(x, _mm_srai_epi32(x, 31)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f329(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_or_si128(_mm_srai_epi32(x, 31), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f330(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srai_epi32(_mm_xor_si128(x, y), 31); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f331(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_xor_si128(_mm_srai_epi32(x, 31), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f332(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_xor_si128(x, _mm_srai_epi32(y, 31)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f333(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_xor_si128(_mm_srai_epi32(x, 31), _mm_srai_epi32(y, 31)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f334(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_xor_si128(x, _mm_srai_epi32(x, 31)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f335(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_xor_si128(_mm_srai_epi32(x, 31), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f336(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srai_epi32(_mm_andnot_si128(x, y), 31); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f337(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_andnot_si128(_mm_srai_epi32(x, 31), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f338(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_andnot_si128(x, _mm_srai_epi32(y, 31)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f339(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_andnot_si128(_mm_srai_epi32(x, 31), _mm_srai_epi32(y, 31)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f340(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_andnot_si128(x, _mm_srai_epi32(x, 31)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f341(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_andnot_si128(_mm_srai_epi32(x, 31), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f342(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srai_epi32(_mm_cmpeq_epi32(x, y), 31); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f343(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_cmpeq_epi32(_mm_srai_epi32(x, 31), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f344(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_cmpeq_epi32(x, _mm_srai_epi32(y, 31)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f345(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_cmpeq_epi32(_mm_srai_epi32(x, 31), _mm_srai_epi32(y, 31)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f346(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_cmpeq_epi32(x, _mm_srai_epi32(x, 31)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f347(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_cmpeq_epi32(_mm_srai_epi32(x, 31), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f348(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srai_epi32(_mm_cmpgt_epi32(x, y), 31); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f349(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_cmpgt_epi32(_mm_srai_epi32(x, 31), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f350(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_cmpgt_epi32(x, _mm_srai_epi32(y, 31)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f351(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_cmpgt_epi32(_mm_srai_epi32(x, 31), _mm_srai_epi32(y, 31)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f352(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_cmpgt_epi32(x, _mm_srai_epi32(x, 31)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f353(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_cmpgt_epi32(_mm_srai_epi32(x, 31), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f354(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srai_epi32(_mm_sign_epi32(x, y), 31); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f355(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sign_epi32(_mm_srai_epi32(x, 31), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f356(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sign_epi32(x, _mm_srai_epi32(y, 31)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f357(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sign_epi32(_mm_srai_epi32(x, 31), _mm_srai_epi32(y, 31)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f358(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sign_epi32(x, _mm_srai_epi32(x, 31)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f359(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sign_epi32(_mm_srai_epi32(x, 31), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f360(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srai_epi32(_mm_packs_epi32(x, y), 31); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f361(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_packs_epi32(_mm_srai_epi32(x, 31), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f362(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_packs_epi32(x, _mm_srai_epi32(y, 31)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f363(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_packs_epi32(_mm_srai_epi32(x, 31), _mm_srai_epi32(y, 31)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f364(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_packs_epi32(x, _mm_srai_epi32(x, 31)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f365(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_packs_epi32(_mm_srai_epi32(x, 31), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f366(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srai_epi32(_mm_packus_epi32(x, y), 31); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f367(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_packus_epi32(_mm_srai_epi32(x, 31), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f368(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_packus_epi32(x, _mm_srai_epi32(y, 31)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f369(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_packus_epi32(_mm_srai_epi32(x, 31), _mm_srai_epi32(y, 31)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f370(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_packus_epi32(x, _mm_srai_epi32(x, 31)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f371(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_packus_epi32(_mm_srai_epi32(x, 31), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f372(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srai_epi32(_mm_hadd_epi32(x, y), 31); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f373(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_hadd_epi32(_mm_srai_epi32(x, 31), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f374(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_hadd_epi32(x, _mm_srai_epi32(y, 31)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f375(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_hadd_epi32(_mm_srai_epi32(x, 31), _mm_srai_epi32(y, 31)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f376(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_hadd_epi32(x, _mm_srai_epi32(x, 31)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f377(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_hadd_epi32(_mm_srai_epi32(x, 31), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f378(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srai_epi32(_mm_hsub_epi32(x, y), 31); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f379(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_hsub_epi32(_mm_srai_epi32(x, 31), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f380(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_hsub_epi32(x, _mm_srai_epi32(y, 31)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f381(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_hsub_epi32(_mm_srai_epi32(x, 31), _mm_srai_epi32(y, 31)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f382(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_hsub_epi32(x, _mm_srai_epi32(x, 31)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f383(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_hsub_epi32(_mm_srai_epi32(x, 31), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f384(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srai_epi32(_mm_mul_epi32(x, y), 31); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f385(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_mul_epi32(_mm_srai_epi32(x, 31), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f386(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_mul_epi32(x, _mm_srai_epi32(y, 31)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f387(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_mul_epi32(_mm_srai_epi32(x, 31), _mm_srai_epi32(y, 31)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f388(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_mul_epi32(x, _mm_srai_epi32(x, 31)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f389(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_mul_epi32(_mm_srai_epi32(x, 31), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f390(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srai_epi32(_mm_mul_epu32(x, y), 31); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f391(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_mul_epu32(_mm_srai_epi32(x, 31), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f392(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_mul_epu32(x, _mm_srai_epi32(y, 31)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f393(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_mul_epu32(_mm_srai_epi32(x, 31), _mm_srai_epi32(y, 31)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f394(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_mul_epu32(x, _mm_srai_epi32(x, 31)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f395(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_mul_epu32(_mm_srai_epi32(x, 31), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f396(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srai_epi32(_mm_unpacklo_epi32(x, y), 31); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f397(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_unpacklo_epi32(_mm_srai_epi32(x, 31), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f398(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_unpacklo_epi32(x, _mm_srai_epi32(y, 31)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f399(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_unpacklo_epi32(_mm_srai_epi32(x, 31), _mm_srai_epi32(y, 31)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f400(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_unpacklo_epi32(x, _mm_srai_epi32(x, 31)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f401(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_unpacklo_epi32(_mm_srai_epi32(x, 31), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f402(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srai_epi32(_mm_unpackhi_epi32(x, y), 31); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f403(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_unpackhi_epi32(_mm_srai_epi32(x, 31), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f404(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_unpackhi_epi32(x, _mm_srai_epi32(y, 31)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f405(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_unpackhi_epi32(_mm_srai_epi32(x, 31), _mm_srai_epi32(y, 31)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f406(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_unpackhi_epi32(x, _mm_srai_epi32(x, 31)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f407(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_unpackhi_epi32(_mm_srai_epi32(x, 31), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f408(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srai_epi32(_mm_blendv_epi8(x, y, _mm_cmpgt_epi32(x, y)), 31); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f409(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_blendv_epi8(_mm_srai_epi32(x, 31), y, _mm_cmpgt_epi32(_mm_srai_epi32(x, 31), y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f410(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_blendv_epi8(x, _mm_srai_epi32(y, 31), _mm_cmpgt_epi32(x, _mm_srai_epi32(y, 31))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f411(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_blendv_epi8(_mm_srai_epi32(x, 31), _mm_srai_epi32(y, 31), _mm_cmpgt_epi32(_mm_srai_epi32(x, 31), _mm_srai_epi32(y, 31))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f412(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_blendv_epi8(x, _mm_srai_epi32(x, 31), _mm_cmpgt_epi32(x, _mm_srai_epi32(x, 31))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f413(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_blendv_epi8(_mm_srai_epi32(x, 31), x, _mm_cmpgt_epi32(_mm_srai_epi32(x, 31), x)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f414(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srai_epi32(_mm_blendv_epi8(y, x, _mm_cmpgt_epi32(x, y)), 31); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f415(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_blendv_epi8(y, _mm_srai_epi32(x, 31), _mm_cmpgt_epi32(_mm_srai_epi32(x, 31), y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f416(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_blendv_epi8(_mm_srai_epi32(y, 31), x, _mm_cmpgt_epi32(x, _mm_srai_epi32(y, 31))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f417(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_blendv_epi8(_mm_srai_epi32(y, 31), _mm_srai_epi32(x, 31), _mm_cmpgt_epi32(_mm_srai_epi32(x, 31), _mm_srai_epi32(y, 31))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f418(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_blendv_epi8(_mm_srai_epi32(x, 31), x, _mm_cmpgt_epi32(x, _mm_srai_epi32(x, 31))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f419(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_blendv_epi8(x, _mm_srai_epi32(x, 31), _mm_cmpgt_epi32(_mm_srai_epi32(x, 31), x)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f420(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srai_epi32(_mm_or_si128(_mm_and_si128(_mm_cmpgt_epi32(x, y), x), _mm_andnot_si128(_mm_cmpgt_epi32(x, y), y)), 31); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f421(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_or_si128(_mm_and_si128(_mm_cmpgt_epi32(_mm_srai_epi32(x, 31), y), _mm_srai_epi32(x, 31)), _mm_andnot_si128(_mm_cmpgt_epi32(_mm_srai_epi32(x, 31), y), y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f422(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_or_si128(_mm_and_si128(_mm_cmpgt_epi32(x, _mm_srai_epi32(y, 31)), x), _mm_andnot_si128(_mm_cmpgt_epi32(x, _mm_srai_epi32(y, 31)), _mm_srai_epi32(y, 31))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f423(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_or_si128(_mm_and_si128(_mm_cmpgt_epi32(_mm_srai_epi32(x, 31), _mm_srai_epi32(y, 31)), _mm_srai_epi32(x, 31)), _mm_andnot_si128(_mm_cmpgt_epi32(_mm_srai_epi32(x, 31), _mm_srai_epi32(y, 31)), _mm_srai_epi32(y, 31))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f424(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_or_si128(_mm_and_si128(_mm_cmpgt_epi32(x, _mm_srai_epi32(x, 31)), x), _mm_andnot_si128(_mm_cmpgt_epi32(x, _mm_srai_epi32(x, 31)), _mm_srai_epi32(x, 31))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f425(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_or_si128(_mm_and_si128(_mm_cmpgt_epi32(_mm_srai_epi32(x, 31), x), _mm_srai_epi32(x, 31)), _mm_andnot_si128(_mm_cmpgt_epi32(_mm_srai_epi32(x, 31), x), x)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f426(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srai_epi32(_mm_blendv_epi8(x, y, _mm_cmpeq_epi32(x, y)), 31); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f427(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_blendv_epi8(_mm_srai_epi32(x, 31), y, _mm_cmpeq_epi32(_mm_srai_epi32(x, 31), y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f428(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_blendv_epi8(x, _mm_srai_epi32(y, 31), _mm_cmpeq_epi32(x, _mm_srai_epi32(y, 31))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f429(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_blendv_epi8(_mm_srai_epi32(x, 31), _mm_srai_epi32(y, 31), _mm_cmpeq_epi32(_mm_srai_epi32(x, 31), _mm_srai_epi32(y, 31))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f430(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_blendv_epi8(x, _mm_srai_epi32(x, 31), _mm_cmpeq_epi32(x, _mm_srai_epi32(x, 31))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f431(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_blendv_epi8(_mm_srai_epi32(x, 31), x, _mm_cmpeq_epi32(_mm_srai_epi32(x, 31), x)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f432(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srai_epi32(_mm_blendv_epi8(y, x, _mm_cmpeq_epi32(x, y)), 31); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f433(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_blendv_epi8(y, _mm_srai_epi32(x, 31), _mm_cmpeq_epi32(_mm_srai_epi32(x, 31), y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f434(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_blendv_epi8(_mm_srai_epi32(y, 31), x, _mm_cmpeq_epi32(x, _mm_srai_epi32(y, 31))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f435(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_blendv_epi8(_mm_srai_epi32(y, 31), _mm_srai_epi32(x, 31), _mm_cmpeq_epi32(_mm_srai_epi32(x, 31), _mm_srai_epi32(y, 31))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f436(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_blendv_epi8(_mm_srai_epi32(x, 31), x, _mm_cmpeq_epi32(x, _mm_srai_epi32(x, 31))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f437(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_blendv_epi8(x, _mm_srai_epi32(x, 31), _mm_cmpeq_epi32(_mm_srai_epi32(x, 31), x)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f438(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srai_epi32(_mm_or_si128(_mm_and_si128(_mm_cmpeq_epi32(x, y), x), _mm_andnot_si128(_mm_cmpeq_epi32(x, y), y)), 31); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f439(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_or_si128(_mm_and_si128(_mm_cmpeq_epi32(_mm_srai_epi32(x, 31), y), _mm_srai_epi32(x, 31)), _mm_andnot_si128(_mm_cmpeq_epi32(_mm_srai_epi32(x, 31), y), y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f440(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_or_si128(_mm_and_si128(_mm_cmpeq_epi32(x, _mm_srai_epi32(y, 31)), x), _mm_andnot_si128(_mm_cmpeq_epi32(x, _mm_srai_epi32(y, 31)), _mm_srai_epi32(y, 31))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f441(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_or_si128(_mm_and_si128(_mm_cmpeq_epi32(_mm_srai_epi32(x, 31), _mm_srai_epi32(y, 31)), _mm_srai_epi32(x, 31)), _mm_andnot_si128(_mm_cmpeq_epi32(_mm_srai_epi32(x, 31), _mm_srai_epi32(y, 31)), _mm_srai_epi32(y, 31))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f442(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_or_si128(_mm_and_si128(_mm_cmpeq_epi32(x, _mm_srai_epi32(x, 31)), x), _mm_andnot_si128(_mm_cmpeq_epi32(x, _mm_srai_epi32(x, 31)), _mm_srai_epi32(x, 31))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f443(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_or_si128(_mm_and_si128(_mm_cmpeq_epi32(_mm_srai_epi32(x, 31), x), _mm_srai_epi32(x, 31)), _mm_andnot_si128(_mm_cmpeq_epi32(_mm_srai_epi32(x, 31), x), x)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f444(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srai_epi32(_mm_mullo_epi32(x, y), 31); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f445(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_mullo_epi32(_mm_srai_epi32(x, 31), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f446(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_mullo_epi32(x, _mm_srai_epi32(y, 31)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f447(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_mullo_epi32(_mm_srai_epi32(x, 31), _mm_srai_epi32(y, 31)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f448(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_mullo_epi32(x, _mm_srai_epi32(x, 31)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f449(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_mullo_epi32(_mm_srai_epi32(x, 31), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f450(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srai_epi32(_mm_sllv_epi32(x, y), 31); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f451(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi32(_mm_srai_epi32(x, 31), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f452(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi32(x, _mm_srai_epi32(y, 31)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f453(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi32(_mm_srai_epi32(x, 31), _mm_srai_epi32(y, 31)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f454(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi32(x, _mm_srai_epi32(x, 31)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f455(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi32(_mm_srai_epi32(x, 31), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f456(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srai_epi32(_mm_srlv_epi32(x, y), 31); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f457(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi32(_mm_srai_epi32(x, 31), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f458(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi32(x, _mm_srai_epi32(y, 31)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f459(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi32(_mm_srai_epi32(x, 31), _mm_srai_epi32(y, 31)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f460(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi32(x, _mm_srai_epi32(x, 31)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f461(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi32(_mm_srai_epi32(x, 31), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f462(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srai_epi32(_mm_srav_epi32(x, y), 31); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f463(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srav_epi32(_mm_srai_epi32(x, 31), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f464(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srav_epi32(x, _mm_srai_epi32(y, 31)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f465(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srav_epi32(_mm_srai_epi32(x, 31), _mm_srai_epi32(y, 31)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f466(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srav_epi32(x, _mm_srai_epi32(x, 31)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f467(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srav_epi32(_mm_srai_epi32(x, 31), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f468(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_slli_epi64(_mm_add_epi64(x, y), 1); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f469(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_add_epi64(_mm_slli_epi64(x, 1), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f470(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_add_epi64(x, _mm_slli_epi64(y, 1)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f471(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_add_epi64(_mm_slli_epi64(x, 1), _mm_slli_epi64(y, 1)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f472(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_add_epi64(x, _mm_slli_epi64(x, 1)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f473(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_add_epi64(_mm_slli_epi64(x, 1), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f474(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_slli_epi64(_mm_sub_epi64(x, y), 1); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f475(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sub_epi64(_mm_slli_epi64(x, 1), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f476(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sub_epi64(x, _mm_slli_epi64(y, 1)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f477(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sub_epi64(_mm_slli_epi64(x, 1), _mm_slli_epi64(y, 1)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f478(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sub_epi64(x, _mm_slli_epi64(x, 1)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f479(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sub_epi64(_mm_slli_epi64(x, 1), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f480(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_slli_epi64(_mm_and_si128(x, y), 1); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f481(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_and_si128(_mm_slli_epi64(x, 1), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f482(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_and_si128(x, _mm_slli_epi64(y, 1)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f483(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_and_si128(_mm_slli_epi64(x, 1), _mm_slli_epi64(y, 1)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f484(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_and_si128(x, _mm_slli_epi64(x, 1)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f485(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_and_si128(_mm_slli_epi64(x, 1), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f486(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_slli_epi64(_mm_or_si128(x, y), 1); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f487(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_or_si128(_mm_slli_epi64(x, 1), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f488(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_or_si128(x, _mm_slli_epi64(y, 1)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f489(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_or_si128(_mm_slli_epi64(x, 1), _mm_slli_epi64(y, 1)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f490(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_or_si128(x, _mm_slli_epi64(x, 1)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f491(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_or_si128(_mm_slli_epi64(x, 1), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f492(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_slli_epi64(_mm_xor_si128(x, y), 1); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f493(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_xor_si128(_mm_slli_epi64(x, 1), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f494(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_xor_si128(x, _mm_slli_epi64(y, 1)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f495(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_xor_si128(_mm_slli_epi64(x, 1), _mm_slli_epi64(y, 1)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f496(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_xor_si128(x, _mm_slli_epi64(x, 1)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f497(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_xor_si128(_mm_slli_epi64(x, 1), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f498(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_slli_epi64(_mm_andnot_si128(x, y), 1); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f499(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_andnot_si128(_mm_slli_epi64(x, 1), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f500(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_andnot_si128(x, _mm_slli_epi64(y, 1)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f501(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_andnot_si128(_mm_slli_epi64(x, 1), _mm_slli_epi64(y, 1)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f502(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_andnot_si128(x, _mm_slli_epi64(x, 1)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f503(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_andnot_si128(_mm_slli_epi64(x, 1), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f504(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_slli_epi64(_mm_cmpeq_epi64(x, y), 1); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f505(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_cmpeq_epi64(_mm_slli_epi64(x, 1), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f506(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_cmpeq_epi64(x, _mm_slli_epi64(y, 1)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f507(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_cmpeq_epi64(_mm_slli_epi64(x, 1), _mm_slli_epi64(y, 1)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f508(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_cmpeq_epi64(x, _mm_slli_epi64(x, 1)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f509(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_cmpeq_epi64(_mm_slli_epi64(x, 1), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f510(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_slli_epi64(_mm_cmpgt_epi64(x, y), 1); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f511(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_cmpgt_epi64(_mm_slli_epi64(x, 1), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f512(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_cmpgt_epi64(x, _mm_slli_epi64(y, 1)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f513(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_cmpgt_epi64(_mm_slli_epi64(x, 1), _mm_slli_epi64(y, 1)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f514(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_cmpgt_epi64(x, _mm_slli_epi64(x, 1)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f515(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_cmpgt_epi64(_mm_slli_epi64(x, 1), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f516(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_slli_epi64(_mm_unpacklo_epi64(x, y), 1); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f517(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_unpacklo_epi64(_mm_slli_epi64(x, 1), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f518(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_unpacklo_epi64(x, _mm_slli_epi64(y, 1)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f519(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_unpacklo_epi64(_mm_slli_epi64(x, 1), _mm_slli_epi64(y, 1)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f520(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_unpacklo_epi64(x, _mm_slli_epi64(x, 1)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f521(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_unpacklo_epi64(_mm_slli_epi64(x, 1), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f522(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_slli_epi64(_mm_unpackhi_epi64(x, y), 1); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f523(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_unpackhi_epi64(_mm_slli_epi64(x, 1), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f524(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_unpackhi_epi64(x, _mm_slli_epi64(y, 1)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f525(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_unpackhi_epi64(_mm_slli_epi64(x, 1), _mm_slli_epi64(y, 1)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f526(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_unpackhi_epi64(x, _mm_slli_epi64(x, 1)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f527(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_unpackhi_epi64(_mm_slli_epi64(x, 1), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f528(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_slli_epi64(_mm_blendv_epi8(x, y, _mm_cmpgt_epi64(x, y)), 1); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f529(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_blendv_epi8(_mm_slli_epi64(x, 1), y, _mm_cmpgt_epi64(_mm_slli_epi64(x, 1), y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f530(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_blendv_epi8(x, _mm_slli_epi64(y, 1), _mm_cmpgt_epi64(x, _mm_slli_epi64(y, 1))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f531(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_blendv_epi8(_mm_slli_epi64(x, 1), _mm_slli_epi64(y, 1), _mm_cmpgt_epi64(_mm_slli_epi64(x, 1), _mm_slli_epi64(y, 1))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f532(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_blendv_epi8(x, _mm_slli_epi64(x, 1), _mm_cmpgt_epi64(x, _mm_slli_epi64(x, 1))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f533(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_blendv_epi8(_mm_slli_epi64(x, 1), x, _mm_cmpgt_epi64(_mm_slli_epi64(x, 1), x)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f534(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_slli_epi64(_mm_blendv_epi8(y, x, _mm_cmpgt_epi64(x, y)), 1); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f535(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_blendv_epi8(y, _mm_slli_epi64(x, 1), _mm_cmpgt_epi64(_mm_slli_epi64(x, 1), y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f536(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_blendv_epi8(_mm_slli_epi64(y, 1), x, _mm_cmpgt_epi64(x, _mm_slli_epi64(y, 1))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f537(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_blendv_epi8(_mm_slli_epi64(y, 1), _mm_slli_epi64(x, 1), _mm_cmpgt_epi64(_mm_slli_epi64(x, 1), _mm_slli_epi64(y, 1))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f538(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_blendv_epi8(_mm_slli_epi64(x, 1), x, _mm_cmpgt_epi64(x, _mm_slli_epi64(x, 1))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f539(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_blendv_epi8(x, _mm_slli_epi64(x, 1), _mm_cmpgt_epi64(_mm_slli_epi64(x, 1), x)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f540(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_slli_epi64(_mm_or_si128(_mm_and_si128(_mm_cmpgt_epi64(x, y), x), _mm_andnot_si128(_mm_cmpgt_epi64(x, y), y)), 1); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f541(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_or_si128(_mm_and_si128(_mm_cmpgt_epi64(_mm_slli_epi64(x, 1), y), _mm_slli_epi64(x, 1)), _mm_andnot_si128(_mm_cmpgt_epi64(_mm_slli_epi64(x, 1), y), y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f542(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_or_si128(_mm_and_si128(_mm_cmpgt_epi64(x, _mm_slli_epi64(y, 1)), x), _mm_andnot_si128(_mm_cmpgt_epi64(x, _mm_slli_epi64(y, 1)), _mm_slli_epi64(y, 1))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f543(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_or_si128(_mm_and_si128(_mm_cmpgt_epi64(_mm_slli_epi64(x, 1), _mm_slli_epi64(y, 1)), _mm_slli_epi64(x, 1)), _mm_andnot_si128(_mm_cmpgt_epi64(_mm_slli_epi64(x, 1), _mm_slli_epi64(y, 1)), _mm_slli_epi64(y, 1))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f544(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_or_si128(_mm_and_si128(_mm_cmpgt_epi64(x, _mm_slli_epi64(x, 1)), x), _mm_andnot_si128(_mm_cmpgt_epi64(x, _mm_slli_epi64(x, 1)), _mm_slli_epi64(x, 1))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f545(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_or_si128(_mm_and_si128(_mm_cmpgt_epi64(_mm_slli_epi64(x, 1), x), _mm_slli_epi64(x, 1)), _mm_andnot_si128(_mm_cmpgt_epi64(_mm_slli_epi64(x, 1), x), x)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f546(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_slli_epi64(_mm_blendv_epi8(x, y, _mm_cmpeq_epi64(x, y)), 1); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f547(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_blendv_epi8(_mm_slli_epi64(x, 1), y, _mm_cmpeq_epi64(_mm_slli_epi64(x, 1), y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f548(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_blendv_epi8(x, _mm_slli_epi64(y, 1), _mm_cmpeq_epi64(x, _mm_slli_epi64(y, 1))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f549(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_blendv_epi8(_mm_slli_epi64(x, 1), _mm_slli_epi64(y, 1), _mm_cmpeq_epi64(_mm_slli_epi64(x, 1), _mm_slli_epi64(y, 1))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f550(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_blendv_epi8(x, _mm_slli_epi64(x, 1), _mm_cmpeq_epi64(x, _mm_slli_epi64(x, 1))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f551(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_blendv_epi8(_mm_slli_epi64(x, 1), x, _mm_cmpeq_epi64(_mm_slli_epi64(x, 1), x)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f552(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_slli_epi64(_mm_blendv_epi8(y, x, _mm_cmpeq_epi64(x, y)), 1); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f553(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_blendv_epi8(y, _mm_slli_epi64(x, 1), _mm_cmpeq_epi64(_mm_slli_epi64(x, 1), y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f554(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_blendv_epi8(_mm_slli_epi64(y, 1), x, _mm_cmpeq_epi64(x, _mm_slli_epi64(y, 1))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f555(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_blendv_epi8(_mm_slli_epi64(y, 1), _mm_slli_epi64(x, 1), _mm_cmpeq_epi64(_mm_slli_epi64(x, 1), _mm_slli_epi64(y, 1))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f556(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_blendv_epi8(_mm_slli_epi64(x, 1), x, _mm_cmpeq_epi64(x, _mm_slli_epi64(x, 1))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f557(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_blendv_epi8(x, _mm_slli_epi64(x, 1), _mm_cmpeq_epi64(_mm_slli_epi64(x, 1), x)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f558(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_slli_epi64(_mm_or_si128(_mm_and_si128(_mm_cmpeq_epi64(x, y), x), _mm_andnot_si128(_mm_cmpeq_epi64(x, y), y)), 1); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f559(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_or_si128(_mm_and_si128(_mm_cmpeq_epi64(_mm_slli_epi64(x, 1), y), _mm_slli_epi64(x, 1)), _mm_andnot_si128(_mm_cmpeq_epi64(_mm_slli_epi64(x, 1), y), y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f560(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_or_si128(_mm_and_si128(_mm_cmpeq_epi64(x, _mm_slli_epi64(y, 1)), x), _mm_andnot_si128(_mm_cmpeq_epi64(x, _mm_slli_epi64(y, 1)), _mm_slli_epi64(y, 1))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f561(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_or_si128(_mm_and_si128(_mm_cmpeq_epi64(_mm_slli_epi64(x, 1), _mm_slli_epi64(y, 1)), _mm_slli_epi64(x, 1)), _mm_andnot_si128(_mm_cmpeq_epi64(_mm_slli_epi64(x, 1), _mm_slli_epi64(y, 1)), _mm_slli_epi64(y, 1))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f562(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_or_si128(_mm_and_si128(_mm_cmpeq_epi64(x, _mm_slli_epi64(x, 1)), x), _mm_andnot_si128(_mm_cmpeq_epi64(x, _mm_slli_epi64(x, 1)), _mm_slli_epi64(x, 1))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f563(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_or_si128(_mm_and_si128(_mm_cmpeq_epi64(_mm_slli_epi64(x, 1), x), _mm_slli_epi64(x, 1)), _mm_andnot_si128(_mm_cmpeq_epi64(_mm_slli_epi64(x, 1), x), x)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f564(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_slli_epi64(_mm_sllv_epi64(x, y), 1); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f565(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi64(_mm_slli_epi64(x, 1), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f566(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi64(x, _mm_slli_epi64(y, 1)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f567(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi64(_mm_slli_epi64(x, 1), _mm_slli_epi64(y, 1)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f568(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi64(x, _mm_slli_epi64(x, 1)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f569(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi64(_mm_slli_epi64(x, 1), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f570(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_slli_epi64(_mm_srlv_epi64(x, y), 1); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f571(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi64(_mm_slli_epi64(x, 1), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f572(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi64(x, _mm_slli_epi64(y, 1)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f573(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi64(_mm_slli_epi64(x, 1), _mm_slli_epi64(y, 1)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f574(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi64(x, _mm_slli_epi64(x, 1)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f575(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi64(_mm_slli_epi64(x, 1), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f576(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srli_epi64(_mm_add_epi64(x, y), 1); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f577(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_add_epi64(_mm_srli_epi64(x, 1), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f578(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_add_epi64(x, _mm_srli_epi64(y, 1)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f579(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_add_epi64(_mm_srli_epi64(x, 1), _mm_srli_epi64(y, 1)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f580(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_add_epi64(x, _mm_srli_epi64(x, 1)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f581(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_add_epi64(_mm_srli_epi64(x, 1), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f582(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srli_epi64(_mm_sub_epi64(x, y), 1); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f583(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sub_epi64(_mm_srli_epi64(x, 1), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f584(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sub_epi64(x, _mm_srli_epi64(y, 1)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f585(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sub_epi64(_mm_srli_epi64(x, 1), _mm_srli_epi64(y, 1)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f586(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sub_epi64(x, _mm_srli_epi64(x, 1)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f587(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sub_epi64(_mm_srli_epi64(x, 1), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f588(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srli_epi64(_mm_and_si128(x, y), 1); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f589(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_and_si128(_mm_srli_epi64(x, 1), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f590(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_and_si128(x, _mm_srli_epi64(y, 1)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f591(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_and_si128(_mm_srli_epi64(x, 1), _mm_srli_epi64(y, 1)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f592(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_and_si128(x, _mm_srli_epi64(x, 1)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f593(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_and_si128(_mm_srli_epi64(x, 1), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f594(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srli_epi64(_mm_or_si128(x, y), 1); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f595(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_or_si128(_mm_srli_epi64(x, 1), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f596(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_or_si128(x, _mm_srli_epi64(y, 1)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f597(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_or_si128(_mm_srli_epi64(x, 1), _mm_srli_epi64(y, 1)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f598(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_or_si128(x, _mm_srli_epi64(x, 1)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f599(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_or_si128(_mm_srli_epi64(x, 1), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f600(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srli_epi64(_mm_xor_si128(x, y), 1); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f601(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_xor_si128(_mm_srli_epi64(x, 1), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f602(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_xor_si128(x, _mm_srli_epi64(y, 1)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f603(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_xor_si128(_mm_srli_epi64(x, 1), _mm_srli_epi64(y, 1)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f604(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_xor_si128(x, _mm_srli_epi64(x, 1)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f605(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_xor_si128(_mm_srli_epi64(x, 1), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f606(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srli_epi64(_mm_andnot_si128(x, y), 1); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f607(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_andnot_si128(_mm_srli_epi64(x, 1), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f608(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_andnot_si128(x, _mm_srli_epi64(y, 1)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f609(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_andnot_si128(_mm_srli_epi64(x, 1), _mm_srli_epi64(y, 1)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f610(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_andnot_si128(x, _mm_srli_epi64(x, 1)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f611(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_andnot_si128(_mm_srli_epi64(x, 1), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f612(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srli_epi64(_mm_cmpeq_epi64(x, y), 1); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f613(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_cmpeq_epi64(_mm_srli_epi64(x, 1), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f614(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_cmpeq_epi64(x, _mm_srli_epi64(y, 1)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f615(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_cmpeq_epi64(_mm_srli_epi64(x, 1), _mm_srli_epi64(y, 1)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f616(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_cmpeq_epi64(x, _mm_srli_epi64(x, 1)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f617(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_cmpeq_epi64(_mm_srli_epi64(x, 1), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f618(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srli_epi64(_mm_cmpgt_epi64(x, y), 1); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f619(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_cmpgt_epi64(_mm_srli_epi64(x, 1), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f620(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_cmpgt_epi64(x, _mm_srli_epi64(y, 1)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f621(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_cmpgt_epi64(_mm_srli_epi64(x, 1), _mm_srli_epi64(y, 1)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f622(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_cmpgt_epi64(x, _mm_srli_epi64(x, 1)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f623(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_cmpgt_epi64(_mm_srli_epi64(x, 1), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f624(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srli_epi64(_mm_unpacklo_epi64(x, y), 1); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f625(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_unpacklo_epi64(_mm_srli_epi64(x, 1), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f626(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_unpacklo_epi64(x, _mm_srli_epi64(y, 1)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f627(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_unpacklo_epi64(_mm_srli_epi64(x, 1), _mm_srli_epi64(y, 1)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f628(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_unpacklo_epi64(x, _mm_srli_epi64(x, 1)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f629(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_unpacklo_epi64(_mm_srli_epi64(x, 1), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f630(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srli_epi64(_mm_unpackhi_epi64(x, y), 1); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f631(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_unpackhi_epi64(_mm_srli_epi64(x, 1), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f632(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_unpackhi_epi64(x, _mm_srli_epi64(y, 1)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f633(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_unpackhi_epi64(_mm_srli_epi64(x, 1), _mm_srli_epi64(y, 1)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f634(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_unpackhi_epi64(x, _mm_srli_epi64(x, 1)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f635(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_unpackhi_epi64(_mm_srli_epi64(x, 1), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f636(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srli_epi64(_mm_blendv_epi8(x, y, _mm_cmpgt_epi64(x, y)), 1); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f637(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_blendv_epi8(_mm_srli_epi64(x, 1), y, _mm_cmpgt_epi64(_mm_srli_epi64(x, 1), y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f638(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_blendv_epi8(x, _mm_srli_epi64(y, 1), _mm_cmpgt_epi64(x, _mm_srli_epi64(y, 1))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f639(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_blendv_epi8(_mm_srli_epi64(x, 1), _mm_srli_epi64(y, 1), _mm_cmpgt_epi64(_mm_srli_epi64(x, 1), _mm_srli_epi64(y, 1))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f640(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_blendv_epi8(x, _mm_srli_epi64(x, 1), _mm_cmpgt_epi64(x, _mm_srli_epi64(x, 1))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f641(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_blendv_epi8(_mm_srli_epi64(x, 1), x, _mm_cmpgt_epi64(_mm_srli_epi64(x, 1), x)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f642(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srli_epi64(_mm_blendv_epi8(y, x, _mm_cmpgt_epi64(x, y)), 1); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f643(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_blendv_epi8(y, _mm_srli_epi64(x, 1), _mm_cmpgt_epi64(_mm_srli_epi64(x, 1), y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f644(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_blendv_epi8(_mm_srli_epi64(y, 1), x, _mm_cmpgt_epi64(x, _mm_srli_epi64(y, 1))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f645(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_blendv_epi8(_mm_srli_epi64(y, 1), _mm_srli_epi64(x, 1), _mm_cmpgt_epi64(_mm_srli_epi64(x, 1), _mm_srli_epi64(y, 1))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f646(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_blendv_epi8(_mm_srli_epi64(x, 1), x, _mm_cmpgt_epi64(x, _mm_srli_epi64(x, 1))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f647(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_blendv_epi8(x, _mm_srli_epi64(x, 1), _mm_cmpgt_epi64(_mm_srli_epi64(x, 1), x)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f648(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srli_epi64(_mm_or_si128(_mm_and_si128(_mm_cmpgt_epi64(x, y), x), _mm_andnot_si128(_mm_cmpgt_epi64(x, y), y)), 1); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f649(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_or_si128(_mm_and_si128(_mm_cmpgt_epi64(_mm_srli_epi64(x, 1), y), _mm_srli_epi64(x, 1)), _mm_andnot_si128(_mm_cmpgt_epi64(_mm_srli_epi64(x, 1), y), y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f650(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_or_si128(_mm_and_si128(_mm_cmpgt_epi64(x, _mm_srli_epi64(y, 1)), x), _mm_andnot_si128(_mm_cmpgt_epi64(x, _mm_srli_epi64(y, 1)), _mm_srli_epi64(y, 1))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f651(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_or_si128(_mm_and_si128(_mm_cmpgt_epi64(_mm_srli_epi64(x, 1), _mm_srli_epi64(y, 1)), _mm_srli_epi64(x, 1)), _mm_andnot_si128(_mm_cmpgt_epi64(_mm_srli_epi64(x, 1), _mm_srli_epi64(y, 1)), _mm_srli_epi64(y, 1))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f652(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_or_si128(_mm_and_si128(_mm_cmpgt_epi64(x, _mm_srli_epi64(x, 1)), x), _mm_andnot_si128(_mm_cmpgt_epi64(x, _mm_srli_epi64(x, 1)), _mm_srli_epi64(x, 1))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f653(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_or_si128(_mm_and_si128(_mm_cmpgt_epi64(_mm_srli_epi64(x, 1), x), _mm_srli_epi64(x, 1)), _mm_andnot_si128(_mm_cmpgt_epi64(_mm_srli_epi64(x, 1), x), x)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f654(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srli_epi64(_mm_blendv_epi8(x, y, _mm_cmpeq_epi64(x, y)), 1); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f655(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_blendv_epi8(_mm_srli_epi64(x, 1), y, _mm_cmpeq_epi64(_mm_srli_epi64(x, 1), y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f656(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_blendv_epi8(x, _mm_srli_epi64(y, 1), _mm_cmpeq_epi64(x, _mm_srli_epi64(y, 1))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f657(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_blendv_epi8(_mm_srli_epi64(x, 1), _mm_srli_epi64(y, 1), _mm_cmpeq_epi64(_mm_srli_epi64(x, 1), _mm_srli_epi64(y, 1))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f658(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_blendv_epi8(x, _mm_srli_epi64(x, 1), _mm_cmpeq_epi64(x, _mm_srli_epi64(x, 1))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f659(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_blendv_epi8(_mm_srli_epi64(x, 1), x, _mm_cmpeq_epi64(_mm_srli_epi64(x, 1), x)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f660(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srli_epi64(_mm_blendv_epi8(y, x, _mm_cmpeq_epi64(x, y)), 1); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f661(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_blendv_epi8(y, _mm_srli_epi64(x, 1), _mm_cmpeq_epi64(_mm_srli_epi64(x, 1), y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f662(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_blendv_epi8(_mm_srli_epi64(y, 1), x, _mm_cmpeq_epi64(x, _mm_srli_epi64(y, 1))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f663(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_blendv_epi8(_mm_srli_epi64(y, 1), _mm_srli_epi64(x, 1), _mm_cmpeq_epi64(_mm_srli_epi64(x, 1), _mm_srli_epi64(y, 1))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f664(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_blendv_epi8(_mm_srli_epi64(x, 1), x, _mm_cmpeq_epi64(x, _mm_srli_epi64(x, 1))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f665(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_blendv_epi8(x, _mm_srli_epi64(x, 1), _mm_cmpeq_epi64(_mm_srli_epi64(x, 1), x)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f666(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srli_epi64(_mm_or_si128(_mm_and_si128(_mm_cmpeq_epi64(x, y), x), _mm_andnot_si128(_mm_cmpeq_epi64(x, y), y)), 1); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f667(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_or_si128(_mm_and_si128(_mm_cmpeq_epi64(_mm_srli_epi64(x, 1), y), _mm_srli_epi64(x, 1)), _mm_andnot_si128(_mm_cmpeq_epi64(_mm_srli_epi64(x, 1), y), y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f668(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_or_si128(_mm_and_si128(_mm_cmpeq_epi64(x, _mm_srli_epi64(y, 1)), x), _mm_andnot_si128(_mm_cmpeq_epi64(x, _mm_srli_epi64(y, 1)), _mm_srli_epi64(y, 1))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f669(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_or_si128(_mm_and_si128(_mm_cmpeq_epi64(_mm_srli_epi64(x, 1), _mm_srli_epi64(y, 1)), _mm_srli_epi64(x, 1)), _mm_andnot_si128(_mm_cmpeq_epi64(_mm_srli_epi64(x, 1), _mm_srli_epi64(y, 1)), _mm_srli_epi64(y, 1))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f670(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_or_si128(_mm_and_si128(_mm_cmpeq_epi64(x, _mm_srli_epi64(x, 1)), x), _mm_andnot_si128(_mm_cmpeq_epi64(x, _mm_srli_epi64(x, 1)), _mm_srli_epi64(x, 1))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f671(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_or_si128(_mm_and_si128(_mm_cmpeq_epi64(_mm_srli_epi64(x, 1), x), _mm_srli_epi64(x, 1)), _mm_andnot_si128(_mm_cmpeq_epi64(_mm_srli_epi64(x, 1), x), x)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f672(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srli_epi64(_mm_sllv_epi64(x, y), 1); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f673(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi64(_mm_srli_epi64(x, 1), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f674(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi64(x, _mm_srli_epi64(y, 1)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f675(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi64(_mm_srli_epi64(x, 1), _mm_srli_epi64(y, 1)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f676(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi64(x, _mm_srli_epi64(x, 1)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f677(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi64(_mm_srli_epi64(x, 1), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f678(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srli_epi64(_mm_srlv_epi64(x, y), 1); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f679(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi64(_mm_srli_epi64(x, 1), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f680(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi64(x, _mm_srli_epi64(y, 1)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f681(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi64(_mm_srli_epi64(x, 1), _mm_srli_epi64(y, 1)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f682(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi64(x, _mm_srli_epi64(x, 1)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f683(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi64(_mm_srli_epi64(x, 1), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f684(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_slli_epi64(_mm_add_epi64(x, y), 63); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f685(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_add_epi64(_mm_slli_epi64(x, 63), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f686(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_add_epi64(x, _mm_slli_epi64(y, 63)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f687(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_add_epi64(_mm_slli_epi64(x, 63), _mm_slli_epi64(y, 63)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f688(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_add_epi64(x, _mm_slli_epi64(x, 63)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f689(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_add_epi64(_mm_slli_epi64(x, 63), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f690(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_slli_epi64(_mm_sub_epi64(x, y), 63); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f691(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sub_epi64(_mm_slli_epi64(x, 63), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f692(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sub_epi64(x, _mm_slli_epi64(y, 63)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f693(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sub_epi64(_mm_slli_epi64(x, 63), _mm_slli_epi64(y, 63)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f694(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sub_epi64(x, _mm_slli_epi64(x, 63)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f695(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sub_epi64(_mm_slli_epi64(x, 63), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f696(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_slli_epi64(_mm_and_si128(x, y), 63); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f697(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_and_si128(_mm_slli_epi64(x, 63), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f698(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_and_si128(x, _mm_slli_epi64(y, 63)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f699(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_and_si128(_mm_slli_epi64(x, 63), _mm_slli_epi64(y, 63)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f700(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_and_si128(x, _mm_slli_epi64(x, 63)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f701(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_and_si128(_mm_slli_epi64(x, 63), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f702(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_slli_epi64(_mm_or_si128(x, y), 63); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f703(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_or_si128(_mm_slli_epi64(x, 63), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f704(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_or_si128(x, _mm_slli_epi64(y, 63)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f705(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_or_si128(_mm_slli_epi64(x, 63), _mm_slli_epi64(y, 63)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f706(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_or_si128(x, _mm_slli_epi64(x, 63)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f707(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_or_si128(_mm_slli_epi64(x, 63), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f708(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_slli_epi64(_mm_xor_si128(x, y), 63); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f709(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_xor_si128(_mm_slli_epi64(x, 63), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f710(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_xor_si128(x, _mm_slli_epi64(y, 63)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f711(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_xor_si128(_mm_slli_epi64(x, 63), _mm_slli_epi64(y, 63)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f712(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_xor_si128(x, _mm_slli_epi64(x, 63)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f713(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_xor_si128(_mm_slli_epi64(x, 63), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f714(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_slli_epi64(_mm_andnot_si128(x, y), 63); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f715(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_andnot_si128(_mm_slli_epi64(x, 63), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f716(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_andnot_si128(x, _mm_slli_epi64(y, 63)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f717(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_andnot_si128(_mm_slli_epi64(x, 63), _mm_slli_epi64(y, 63)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f718(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_andnot_si128(x, _mm_slli_epi64(x, 63)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f719(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_andnot_si128(_mm_slli_epi64(x, 63), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f720(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_slli_epi64(_mm_cmpeq_epi64(x, y), 63); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f721(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_cmpeq_epi64(_mm_slli_epi64(x, 63), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f722(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_cmpeq_epi64(x, _mm_slli_epi64(y, 63)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f723(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_cmpeq_epi64(_mm_slli_epi64(x, 63), _mm_slli_epi64(y, 63)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f724(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_cmpeq_epi64(x, _mm_slli_epi64(x, 63)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f725(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_cmpeq_epi64(_mm_slli_epi64(x, 63), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f726(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_slli_epi64(_mm_cmpgt_epi64(x, y), 63); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f727(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_cmpgt_epi64(_mm_slli_epi64(x, 63), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f728(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_cmpgt_epi64(x, _mm_slli_epi64(y, 63)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f729(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_cmpgt_epi64(_mm_slli_epi64(x, 63), _mm_slli_epi64(y, 63)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f730(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_cmpgt_epi64(x, _mm_slli_epi64(x, 63)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f731(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_cmpgt_epi64(_mm_slli_epi64(x, 63), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f732(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_slli_epi64(_mm_unpacklo_epi64(x, y), 63); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f733(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_unpacklo_epi64(_mm_slli_epi64(x, 63), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f734(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_unpacklo_epi64(x, _mm_slli_epi64(y, 63)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f735(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_unpacklo_epi64(_mm_slli_epi64(x, 63), _mm_slli_epi64(y, 63)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f736(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_unpacklo_epi64(x, _mm_slli_epi64(x, 63)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f737(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_unpacklo_epi64(_mm_slli_epi64(x, 63), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f738(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_slli_epi64(_mm_unpackhi_epi64(x, y), 63); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f739(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_unpackhi_epi64(_mm_slli_epi64(x, 63), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f740(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_unpackhi_epi64(x, _mm_slli_epi64(y, 63)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f741(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_unpackhi_epi64(_mm_slli_epi64(x, 63), _mm_slli_epi64(y, 63)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f742(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_unpackhi_epi64(x, _mm_slli_epi64(x, 63)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f743(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_unpackhi_epi64(_mm_slli_epi64(x, 63), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f744(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_slli_epi64(_mm_blendv_epi8(x, y, _mm_cmpgt_epi64(x, y)), 63); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f745(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_blendv_epi8(_mm_slli_epi64(x, 63), y, _mm_cmpgt_epi64(_mm_slli_epi64(x, 63), y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f746(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_blendv_epi8(x, _mm_slli_epi64(y, 63), _mm_cmpgt_epi64(x, _mm_slli_epi64(y, 63))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f747(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_blendv_epi8(_mm_slli_epi64(x, 63), _mm_slli_epi64(y, 63), _mm_cmpgt_epi64(_mm_slli_epi64(x, 63), _mm_slli_epi64(y, 63))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f748(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_blendv_epi8(x, _mm_slli_epi64(x, 63), _mm_cmpgt_epi64(x, _mm_slli_epi64(x, 63))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f749(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_blendv_epi8(_mm_slli_epi64(x, 63), x, _mm_cmpgt_epi64(_mm_slli_epi64(x, 63), x)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f750(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_slli_epi64(_mm_blendv_epi8(y, x, _mm_cmpgt_epi64(x, y)), 63); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f751(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_blendv_epi8(y, _mm_slli_epi64(x, 63), _mm_cmpgt_epi64(_mm_slli_epi64(x, 63), y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f752(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_blendv_epi8(_mm_slli_epi64(y, 63), x, _mm_cmpgt_epi64(x, _mm_slli_epi64(y, 63))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f753(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_blendv_epi8(_mm_slli_epi64(y, 63), _mm_slli_epi64(x, 63), _mm_cmpgt_epi64(_mm_slli_epi64(x, 63), _mm_slli_epi64(y, 63))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f754(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_blendv_epi8(_mm_slli_epi64(x, 63), x, _mm_cmpgt_epi64(x, _mm_slli_epi64(x, 63))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f755(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_blendv_epi8(x, _mm_slli_epi64(x, 63), _mm_cmpgt_epi64(_mm_slli_epi64(x, 63), x)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f756(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_slli_epi64(_mm_or_si128(_mm_and_si128(_mm_cmpgt_epi64(x, y), x), _mm_andnot_si128(_mm_cmpgt_epi64(x, y), y)), 63); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f757(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_or_si128(_mm_and_si128(_mm_cmpgt_epi64(_mm_slli_epi64(x, 63), y), _mm_slli_epi64(x, 63)), _mm_andnot_si128(_mm_cmpgt_epi64(_mm_slli_epi64(x, 63), y), y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f758(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_or_si128(_mm_and_si128(_mm_cmpgt_epi64(x, _mm_slli_epi64(y, 63)), x), _mm_andnot_si128(_mm_cmpgt_epi64(x, _mm_slli_epi64(y, 63)), _mm_slli_epi64(y, 63))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f759(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_or_si128(_mm_and_si128(_mm_cmpgt_epi64(_mm_slli_epi64(x, 63), _mm_slli_epi64(y, 63)), _mm_slli_epi64(x, 63)), _mm_andnot_si128(_mm_cmpgt_epi64(_mm_slli_epi64(x, 63), _mm_slli_epi64(y, 63)), _mm_slli_epi64(y, 63))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f760(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_or_si128(_mm_and_si128(_mm_cmpgt_epi64(x, _mm_slli_epi64(x, 63)), x), _mm_andnot_si128(_mm_cmpgt_epi64(x, _mm_slli_epi64(x, 63)), _mm_slli_epi64(x, 63))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f761(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_or_si128(_mm_and_si128(_mm_cmpgt_epi64(_mm_slli_epi64(x, 63), x), _mm_slli_epi64(x, 63)), _mm_andnot_si128(_mm_cmpgt_epi64(_mm_slli_epi64(x, 63), x), x)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f762(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_slli_epi64(_mm_blendv_epi8(x, y, _mm_cmpeq_epi64(x, y)), 63); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f763(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_blendv_epi8(_mm_slli_epi64(x, 63), y, _mm_cmpeq_epi64(_mm_slli_epi64(x, 63), y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f764(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_blendv_epi8(x, _mm_slli_epi64(y, 63), _mm_cmpeq_epi64(x, _mm_slli_epi64(y, 63))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f765(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_blendv_epi8(_mm_slli_epi64(x, 63), _mm_slli_epi64(y, 63), _mm_cmpeq_epi64(_mm_slli_epi64(x, 63), _mm_slli_epi64(y, 63))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f766(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_blendv_epi8(x, _mm_slli_epi64(x, 63), _mm_cmpeq_epi64(x, _mm_slli_epi64(x, 63))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f767(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_blendv_epi8(_mm_slli_epi64(x, 63), x, _mm_cmpeq_epi64(_mm_slli_epi64(x, 63), x)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f768(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_slli_epi64(_mm_blendv_epi8(y, x, _mm_cmpeq_epi64(x, y)), 63); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f769(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_blendv_epi8(y, _mm_slli_epi64(x, 63), _mm_cmpeq_epi64(_mm_slli_epi64(x, 63), y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f770(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_blendv_epi8(_mm_slli_epi64(y, 63), x, _mm_cmpeq_epi64(x, _mm_slli_epi64(y, 63))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f771(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_blendv_epi8(_mm_slli_epi64(y, 63), _mm_slli_epi64(x, 63), _mm_cmpeq_epi64(_mm_slli_epi64(x, 63), _mm_slli_epi64(y, 63))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f772(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_blendv_epi8(_mm_slli_epi64(x, 63), x, _mm_cmpeq_epi64(x, _mm_slli_epi64(x, 63))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f773(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_blendv_epi8(x, _mm_slli_epi64(x, 63), _mm_cmpeq_epi64(_mm_slli_epi64(x, 63), x)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f774(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_slli_epi64(_mm_or_si128(_mm_and_si128(_mm_cmpeq_epi64(x, y), x), _mm_andnot_si128(_mm_cmpeq_epi64(x, y), y)), 63); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f775(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_or_si128(_mm_and_si128(_mm_cmpeq_epi64(_mm_slli_epi64(x, 63), y), _mm_slli_epi64(x, 63)), _mm_andnot_si128(_mm_cmpeq_epi64(_mm_slli_epi64(x, 63), y), y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f776(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_or_si128(_mm_and_si128(_mm_cmpeq_epi64(x, _mm_slli_epi64(y, 63)), x), _mm_andnot_si128(_mm_cmpeq_epi64(x, _mm_slli_epi64(y, 63)), _mm_slli_epi64(y, 63))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f777(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_or_si128(_mm_and_si128(_mm_cmpeq_epi64(_mm_slli_epi64(x, 63), _mm_slli_epi64(y, 63)), _mm_slli_epi64(x, 63)), _mm_andnot_si128(_mm_cmpeq_epi64(_mm_slli_epi64(x, 63), _mm_slli_epi64(y, 63)), _mm_slli_epi64(y, 63))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f778(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_or_si128(_mm_and_si128(_mm_cmpeq_epi64(x, _mm_slli_epi64(x, 63)), x), _mm_andnot_si128(_mm_cmpeq_epi64(x, _mm_slli_epi64(x, 63)), _mm_slli_epi64(x, 63))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f779(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_or_si128(_mm_and_si128(_mm_cmpeq_epi64(_mm_slli_epi64(x, 63), x), _mm_slli_epi64(x, 63)), _mm_andnot_si128(_mm_cmpeq_epi64(_mm_slli_epi64(x, 63), x), x)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f780(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_slli_epi64(_mm_sllv_epi64(x, y), 63); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f781(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi64(_mm_slli_epi64(x, 63), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f782(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi64(x, _mm_slli_epi64(y, 63)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f783(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi64(_mm_slli_epi64(x, 63), _mm_slli_epi64(y, 63)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f784(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi64(x, _mm_slli_epi64(x, 63)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f785(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi64(_mm_slli_epi64(x, 63), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f786(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_slli_epi64(_mm_srlv_epi64(x, y), 63); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f787(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi64(_mm_slli_epi64(x, 63), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f788(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi64(x, _mm_slli_epi64(y, 63)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f789(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi64(_mm_slli_epi64(x, 63), _mm_slli_epi64(y, 63)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f790(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi64(x, _mm_slli_epi64(x, 63)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f791(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi64(_mm_slli_epi64(x, 63), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f792(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srli_epi64(_mm_add_epi64(x, y), 63); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f793(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_add_epi64(_mm_srli_epi64(x, 63), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f794(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_add_epi64(x, _mm_srli_epi64(y, 63)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f795(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_add_epi64(_mm_srli_epi64(x, 63), _mm_srli_epi64(y, 63)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f796(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_add_epi64(x, _mm_srli_epi64(x, 63)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f797(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_add_epi64(_mm_srli_epi64(x, 63), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f798(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srli_epi64(_mm_sub_epi64(x, y), 63); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f799(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sub_epi64(_mm_srli_epi64(x, 63), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f800(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sub_epi64(x, _mm_srli_epi64(y, 63)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f801(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sub_epi64(_mm_srli_epi64(x, 63), _mm_srli_epi64(y, 63)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f802(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sub_epi64(x, _mm_srli_epi64(x, 63)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f803(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sub_epi64(_mm_srli_epi64(x, 63), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f804(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srli_epi64(_mm_and_si128(x, y), 63); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f805(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_and_si128(_mm_srli_epi64(x, 63), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f806(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_and_si128(x, _mm_srli_epi64(y, 63)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f807(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_and_si128(_mm_srli_epi64(x, 63), _mm_srli_epi64(y, 63)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f808(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_and_si128(x, _mm_srli_epi64(x, 63)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f809(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_and_si128(_mm_srli_epi64(x, 63), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f810(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srli_epi64(_mm_or_si128(x, y), 63); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f811(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_or_si128(_mm_srli_epi64(x, 63), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f812(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_or_si128(x, _mm_srli_epi64(y, 63)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f813(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_or_si128(_mm_srli_epi64(x, 63), _mm_srli_epi64(y, 63)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f814(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_or_si128(x, _mm_srli_epi64(x, 63)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f815(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_or_si128(_mm_srli_epi64(x, 63), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f816(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srli_epi64(_mm_xor_si128(x, y), 63); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f817(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_xor_si128(_mm_srli_epi64(x, 63), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f818(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_xor_si128(x, _mm_srli_epi64(y, 63)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f819(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_xor_si128(_mm_srli_epi64(x, 63), _mm_srli_epi64(y, 63)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f820(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_xor_si128(x, _mm_srli_epi64(x, 63)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f821(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_xor_si128(_mm_srli_epi64(x, 63), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f822(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srli_epi64(_mm_andnot_si128(x, y), 63); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f823(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_andnot_si128(_mm_srli_epi64(x, 63), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f824(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_andnot_si128(x, _mm_srli_epi64(y, 63)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f825(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_andnot_si128(_mm_srli_epi64(x, 63), _mm_srli_epi64(y, 63)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f826(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_andnot_si128(x, _mm_srli_epi64(x, 63)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f827(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_andnot_si128(_mm_srli_epi64(x, 63), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f828(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srli_epi64(_mm_cmpeq_epi64(x, y), 63); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f829(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_cmpeq_epi64(_mm_srli_epi64(x, 63), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f830(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_cmpeq_epi64(x, _mm_srli_epi64(y, 63)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f831(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_cmpeq_epi64(_mm_srli_epi64(x, 63), _mm_srli_epi64(y, 63)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f832(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_cmpeq_epi64(x, _mm_srli_epi64(x, 63)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f833(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_cmpeq_epi64(_mm_srli_epi64(x, 63), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f834(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srli_epi64(_mm_cmpgt_epi64(x, y), 63); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f835(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_cmpgt_epi64(_mm_srli_epi64(x, 63), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f836(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_cmpgt_epi64(x, _mm_srli_epi64(y, 63)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f837(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_cmpgt_epi64(_mm_srli_epi64(x, 63), _mm_srli_epi64(y, 63)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f838(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_cmpgt_epi64(x, _mm_srli_epi64(x, 63)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f839(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_cmpgt_epi64(_mm_srli_epi64(x, 63), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f840(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srli_epi64(_mm_unpacklo_epi64(x, y), 63); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f841(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_unpacklo_epi64(_mm_srli_epi64(x, 63), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f842(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_unpacklo_epi64(x, _mm_srli_epi64(y, 63)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f843(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_unpacklo_epi64(_mm_srli_epi64(x, 63), _mm_srli_epi64(y, 63)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f844(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_unpacklo_epi64(x, _mm_srli_epi64(x, 63)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f845(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_unpacklo_epi64(_mm_srli_epi64(x, 63), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f846(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srli_epi64(_mm_unpackhi_epi64(x, y), 63); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f847(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_unpackhi_epi64(_mm_srli_epi64(x, 63), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f848(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_unpackhi_epi64(x, _mm_srli_epi64(y, 63)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f849(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_unpackhi_epi64(_mm_srli_epi64(x, 63), _mm_srli_epi64(y, 63)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f850(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_unpackhi_epi64(x, _mm_srli_epi64(x, 63)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f851(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_unpackhi_epi64(_mm_srli_epi64(x, 63), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f852(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srli_epi64(_mm_blendv_epi8(x, y, _mm_cmpgt_epi64(x, y)), 63); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f853(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_blendv_epi8(_mm_srli_epi64(x, 63), y, _mm_cmpgt_epi64(_mm_srli_epi64(x, 63), y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f854(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_blendv_epi8(x, _mm_srli_epi64(y, 63), _mm_cmpgt_epi64(x, _mm_srli_epi64(y, 63))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f855(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_blendv_epi8(_mm_srli_epi64(x, 63), _mm_srli_epi64(y, 63), _mm_cmpgt_epi64(_mm_srli_epi64(x, 63), _mm_srli_epi64(y, 63))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f856(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_blendv_epi8(x, _mm_srli_epi64(x, 63), _mm_cmpgt_epi64(x, _mm_srli_epi64(x, 63))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f857(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_blendv_epi8(_mm_srli_epi64(x, 63), x, _mm_cmpgt_epi64(_mm_srli_epi64(x, 63), x)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f858(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srli_epi64(_mm_blendv_epi8(y, x, _mm_cmpgt_epi64(x, y)), 63); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f859(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_blendv_epi8(y, _mm_srli_epi64(x, 63), _mm_cmpgt_epi64(_mm_srli_epi64(x, 63), y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f860(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_blendv_epi8(_mm_srli_epi64(y, 63), x, _mm_cmpgt_epi64(x, _mm_srli_epi64(y, 63))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f861(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_blendv_epi8(_mm_srli_epi64(y, 63), _mm_srli_epi64(x, 63), _mm_cmpgt_epi64(_mm_srli_epi64(x, 63), _mm_srli_epi64(y, 63))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f862(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_blendv_epi8(_mm_srli_epi64(x, 63), x, _mm_cmpgt_epi64(x, _mm_srli_epi64(x, 63))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f863(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_blendv_epi8(x, _mm_srli_epi64(x, 63), _mm_cmpgt_epi64(_mm_srli_epi64(x, 63), x)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f864(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srli_epi64(_mm_or_si128(_mm_and_si128(_mm_cmpgt_epi64(x, y), x), _mm_andnot_si128(_mm_cmpgt_epi64(x, y), y)), 63); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f865(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_or_si128(_mm_and_si128(_mm_cmpgt_epi64(_mm_srli_epi64(x, 63), y), _mm_srli_epi64(x, 63)), _mm_andnot_si128(_mm_cmpgt_epi64(_mm_srli_epi64(x, 63), y), y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f866(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_or_si128(_mm_and_si128(_mm_cmpgt_epi64(x, _mm_srli_epi64(y, 63)), x), _mm_andnot_si128(_mm_cmpgt_epi64(x, _mm_srli_epi64(y, 63)), _mm_srli_epi64(y, 63))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f867(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_or_si128(_mm_and_si128(_mm_cmpgt_epi64(_mm_srli_epi64(x, 63), _mm_srli_epi64(y, 63)), _mm_srli_epi64(x, 63)), _mm_andnot_si128(_mm_cmpgt_epi64(_mm_srli_epi64(x, 63), _mm_srli_epi64(y, 63)), _mm_srli_epi64(y, 63))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f868(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_or_si128(_mm_and_si128(_mm_cmpgt_epi64(x, _mm_srli_epi64(x, 63)), x), _mm_andnot_si128(_mm_cmpgt_epi64(x, _mm_srli_epi64(x, 63)), _mm_srli_epi64(x, 63))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f869(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_or_si128(_mm_and_si128(_mm_cmpgt_epi64(_mm_srli_epi64(x, 63), x), _mm_srli_epi64(x, 63)), _mm_andnot_si128(_mm_cmpgt_epi64(_mm_srli_epi64(x, 63), x), x)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f870(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srli_epi64(_mm_blendv_epi8(x, y, _mm_cmpeq_epi64(x, y)), 63); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f871(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_blendv_epi8(_mm_srli_epi64(x, 63), y, _mm_cmpeq_epi64(_mm_srli_epi64(x, 63), y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f872(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_blendv_epi8(x, _mm_srli_epi64(y, 63), _mm_cmpeq_epi64(x, _mm_srli_epi64(y, 63))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f873(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_blendv_epi8(_mm_srli_epi64(x, 63), _mm_srli_epi64(y, 63), _mm_cmpeq_epi64(_mm_srli_epi64(x, 63), _mm_srli_epi64(y, 63))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f874(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_blendv_epi8(x, _mm_srli_epi64(x, 63), _mm_cmpeq_epi64(x, _mm_srli_epi64(x, 63))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f875(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_blendv_epi8(_mm_srli_epi64(x, 63), x, _mm_cmpeq_epi64(_mm_srli_epi64(x, 63), x)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f876(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srli_epi64(_mm_blendv_epi8(y, x, _mm_cmpeq_epi64(x, y)), 63); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f877(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_blendv_epi8(y, _mm_srli_epi64(x, 63), _mm_cmpeq_epi64(_mm_srli_epi64(x, 63), y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f878(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_blendv_epi8(_mm_srli_epi64(y, 63), x, _mm_cmpeq_epi64(x, _mm_srli_epi64(y, 63))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f879(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_blendv_epi8(_mm_srli_epi64(y, 63), _mm_srli_epi64(x, 63), _mm_cmpeq_epi64(_mm_srli_epi64(x, 63), _mm_srli_epi64(y, 63))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f880(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_blendv_epi8(_mm_srli_epi64(x, 63), x, _mm_cmpeq_epi64(x, _mm_srli_epi64(x, 63))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f881(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_blendv_epi8(x, _mm_srli_epi64(x, 63), _mm_cmpeq_epi64(_mm_srli_epi64(x, 63), x)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f882(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srli_epi64(_mm_or_si128(_mm_and_si128(_mm_cmpeq_epi64(x, y), x), _mm_andnot_si128(_mm_cmpeq_epi64(x, y), y)), 63); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f883(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_or_si128(_mm_and_si128(_mm_cmpeq_epi64(_mm_srli_epi64(x, 63), y), _mm_srli_epi64(x, 63)), _mm_andnot_si128(_mm_cmpeq_epi64(_mm_srli_epi64(x, 63), y), y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f884(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_or_si128(_mm_and_si128(_mm_cmpeq_epi64(x, _mm_srli_epi64(y, 63)), x), _mm_andnot_si128(_mm_cmpeq_epi64(x, _mm_srli_epi64(y, 63)), _mm_srli_epi64(y, 63))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f885(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_or_si128(_mm_and_si128(_mm_cmpeq_epi64(_mm_srli_epi64(x, 63), _mm_srli_epi64(y, 63)), _mm_srli_epi64(x, 63)), _mm_andnot_si128(_mm_cmpeq_epi64(_mm_srli_epi64(x, 63), _mm_srli_epi64(y, 63)), _mm_srli_epi64(y, 63))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f886(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_or_si128(_mm_and_si128(_mm_cmpeq_epi64(x, _mm_srli_epi64(x, 63)), x), _mm_andnot_si128(_mm_cmpeq_epi64(x, _mm_srli_epi64(x, 63)), _mm_srli_epi64(x, 63))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f887(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_or_si128(_mm_and_si128(_mm_cmpeq_epi64(_mm_srli_epi64(x, 63), x), _mm_srli_epi64(x, 63)), _mm_andnot_si128(_mm_cmpeq_epi64(_mm_srli_epi64(x, 63), x), x)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f888(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srli_epi64(_mm_sllv_epi64(x, y), 63); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f889(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi64(_mm_srli_epi64(x, 63), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f890(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi64(x, _mm_srli_epi64(y, 63)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f891(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi64(_mm_srli_epi64(x, 63), _mm_srli_epi64(y, 63)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f892(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi64(x, _mm_srli_epi64(x, 63)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f893(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi64(_mm_srli_epi64(x, 63), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f894(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srli_epi64(_mm_srlv_epi64(x, y), 63); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f895(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi64(_mm_srli_epi64(x, 63), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f896(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi64(x, _mm_srli_epi64(y, 63)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f897(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi64(_mm_srli_epi64(x, 63), _mm_srli_epi64(y, 63)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f898(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi64(x, _mm_srli_epi64(x, 63)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f899(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi64(_mm_srli_epi64(x, 63), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f900(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_shuffle_epi32(_mm_add_epi32(x, y), 0x1b); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f901(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_add_epi32(_mm_shuffle_epi32(x, 0x1b), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f902(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_add_epi32(x, _mm_shuffle_epi32(y, 0x1b)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f903(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_add_epi32(_mm_shuffle_epi32(x, 0x1b), _mm_shuffle_epi32(y, 0x1b)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f904(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_add_epi32(x, _mm_shuffle_epi32(x, 0x1b)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f905(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_add_epi32(_mm_shuffle_epi32(x, 0x1b), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f906(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_shuffle_epi32(_mm_sub_epi32(x, y), 0x1b); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f907(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sub_epi32(_mm_shuffle_epi32(x, 0x1b), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f908(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sub_epi32(x, _mm_shuffle_epi32(y, 0x1b)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f909(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sub_epi32(_mm_shuffle_epi32(x, 0x1b), _mm_shuffle_epi32(y, 0x1b)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f910(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sub_epi32(x, _mm_shuffle_epi32(x, 0x1b)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f911(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sub_epi32(_mm_shuffle_epi32(x, 0x1b), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f912(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_shuffle_epi32(_mm_min_epi32(x, y), 0x1b); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f913(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_min_epi32(_mm_shuffle_epi32(x, 0x1b), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f914(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_min_epi32(x, _mm_shuffle_epi32(y, 0x1b)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f915(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_min_epi32(_mm_shuffle_epi32(x, 0x1b), _mm_shuffle_epi32(y, 0x1b)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f916(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_min_epi32(x, _mm_shuffle_epi32(x, 0x1b)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f917(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_min_epi32(_mm_shuffle_epi32(x, 0x1b), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f918(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_shuffle_epi32(_mm_max_epi32(x, y), 0x1b); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f919(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_max_epi32(_mm_shuffle_epi32(x, 0x1b), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f920(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_max_epi32(x, _mm_shuffle_epi32(y, 0x1b)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f921(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_max_epi32(_mm_shuffle_epi32(x, 0x1b), _mm_shuffle_epi32(y, 0x1b)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f922(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_max_epi32(x, _mm_shuffle_epi32(x, 0x1b)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f923(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_max_epi32(_mm_shuffle_epi32(x, 0x1b), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f924(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_shuffle_epi32(_mm_min_epu32(x, y), 0x1b); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f925(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_min_epu32(_mm_shuffle_epi32(x, 0x1b), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f926(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_min_epu32(x, _mm_shuffle_epi32(y, 0x1b)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f927(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_min_epu32(_mm_shuffle_epi32(x, 0x1b), _mm_shuffle_epi32(y, 0x1b)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f928(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_min_epu32(x, _mm_shuffle_epi32(x, 0x1b)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f929(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_min_epu32(_mm_shuffle_epi32(x, 0x1b), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f930(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_shuffle_epi32(_mm_max_epu32(x, y), 0x1b); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f931(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_max_epu32(_mm_shuffle_epi32(x, 0x1b), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f932(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_max_epu32(x, _mm_shuffle_epi32(y, 0x1b)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f933(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_max_epu32(_mm_shuffle_epi32(x, 0x1b), _mm_shuffle_epi32(y, 0x1b)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f934(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_max_epu32(x, _mm_shuffle_epi32(x, 0x1b)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f935(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_max_epu32(_mm_shuffle_epi32(x, 0x1b), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f936(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_shuffle_epi32(_mm_and_si128(x, y), 0x1b); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f937(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_and_si128(_mm_shuffle_epi32(x, 0x1b), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f938(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_and_si128(x, _mm_shuffle_epi32(y, 0x1b)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f939(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_and_si128(_mm_shuffle_epi32(x, 0x1b), _mm_shuffle_epi32(y, 0x1b)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f940(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_and_si128(x, _mm_shuffle_epi32(x, 0x1b)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f941(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_and_si128(_mm_shuffle_epi32(x, 0x1b), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f942(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_shuffle_epi32(_mm_or_si128(x, y), 0x1b); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f943(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_or_si128(_mm_shuffle_epi32(x, 0x1b), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f944(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_or_si128(x, _mm_shuffle_epi32(y, 0x1b)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f945(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_or_si128(_mm_shuffle_epi32(x, 0x1b), _mm_shuffle_epi32(y, 0x1b)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f946(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_or_si128(x, _mm_shuffle_epi32(x, 0x1b)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f947(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_or_si128(_mm_shuffle_epi32(x, 0x1b), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f948(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_shuffle_epi32(_mm_xor_si128(x, y), 0x1b); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f949(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_xor_si128(_mm_shuffle_epi32(x, 0x1b), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f950(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_xor_si128(x, _mm_shuffle_epi32(y, 0x1b)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f951(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_xor_si128(_mm_shuffle_epi32(x, 0x1b), _mm_shuffle_epi32(y, 0x1b)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f952(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_xor_si128(x, _mm_shuffle_epi32(x, 0x1b)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f953(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_xor_si128(_mm_shuffle_epi32(x, 0x1b), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f954(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_shuffle_epi32(_mm_andnot_si128(x, y), 0x1b); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f955(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_andnot_si128(_mm_shuffle_epi32(x, 0x1b), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f956(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_andnot_si128(x, _mm_shuffle_epi32(y, 0x1b)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f957(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_andnot_si128(_mm_shuffle_epi32(x, 0x1b), _mm_shuffle_epi32(y, 0x1b)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f958(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_andnot_si128(x, _mm_shuffle_epi32(x, 0x1b)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f959(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_andnot_si128(_mm_shuffle_epi32(x, 0x1b), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f960(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_shuffle_epi32(_mm_cmpeq_epi32(x, y), 0x1b); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f961(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_cmpeq_epi32(_mm_shuffle_epi32(x, 0x1b), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f962(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_cmpeq_epi32(x, _mm_shuffle_epi32(y, 0x1b)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f963(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_cmpeq_epi32(_mm_shuffle_epi32(x, 0x1b), _mm_shuffle_epi32(y, 0x1b)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f964(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_cmpeq_epi32(x, _mm_shuffle_epi32(x, 0x1b)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f965(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_cmpeq_epi32(_mm_shuffle_epi32(x, 0x1b), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f966(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_shuffle_epi32(_mm_cmpgt_epi32(x, y), 0x1b); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f967(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_cmpgt_epi32(_mm_shuffle_epi32(x, 0x1b), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f968(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_cmpgt_epi32(x, _mm_shuffle_epi32(y, 0x1b)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f969(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_cmpgt_epi32(_mm_shuffle_epi32(x, 0x1b), _mm_shuffle_epi32(y, 0x1b)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f970(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_cmpgt_epi32(x, _mm_shuffle_epi32(x, 0x1b)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f971(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_cmpgt_epi32(_mm_shuffle_epi32(x, 0x1b), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f972(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_shuffle_epi32(_mm_sign_epi32(x, y), 0x1b); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f973(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sign_epi32(_mm_shuffle_epi32(x, 0x1b), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f974(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sign_epi32(x, _mm_shuffle_epi32(y, 0x1b)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f975(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sign_epi32(_mm_shuffle_epi32(x, 0x1b), _mm_shuffle_epi32(y, 0x1b)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f976(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sign_epi32(x, _mm_shuffle_epi32(x, 0x1b)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f977(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sign_epi32(_mm_shuffle_epi32(x, 0x1b), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f978(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_shuffle_epi32(_mm_packs_epi32(x, y), 0x1b); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f979(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_packs_epi32(_mm_shuffle_epi32(x, 0x1b), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f980(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_packs_epi32(x, _mm_shuffle_epi32(y, 0x1b)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f981(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_packs_epi32(_mm_shuffle_epi32(x, 0x1b), _mm_shuffle_epi32(y, 0x1b)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f982(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_packs_epi32(x, _mm_shuffle_epi32(x, 0x1b)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f983(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_packs_epi32(_mm_shuffle_epi32(x, 0x1b), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f984(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_shuffle_epi32(_mm_packus_epi32(x, y), 0x1b); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f985(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_packus_epi32(_mm_shuffle_epi32(x, 0x1b), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f986(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_packus_epi32(x, _mm_shuffle_epi32(y, 0x1b)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f987(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_packus_epi32(_mm_shuffle_epi32(x, 0x1b), _mm_shuffle_epi32(y, 0x1b)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f988(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_packus_epi32(x, _mm_shuffle_epi32(x, 0x1b)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f989(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_packus_epi32(_mm_shuffle_epi32(x, 0x1b), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f990(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_shuffle_epi32(_mm_hadd_epi32(x, y), 0x1b); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f991(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_hadd_epi32(_mm_shuffle_epi32(x, 0x1b), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f992(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_hadd_epi32(x, _mm_shuffle_epi32(y, 0x1b)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f993(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_hadd_epi32(_mm_shuffle_epi32(x, 0x1b), _mm_shuffle_epi32(y, 0x1b)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f994(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_hadd_epi32(x, _mm_shuffle_epi32(x, 0x1b)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f995(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_hadd_epi32(_mm_shuffle_epi32(x, 0x1b), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f996(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_shuffle_epi32(_mm_hsub_epi32(x, y), 0x1b); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f997(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_hsub_epi32(_mm_shuffle_epi32(x, 0x1b), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f998(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_hsub_epi32(x, _mm_shuffle_epi32(y, 0x1b)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f999(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_hsub_epi32(_mm_shuffle_epi32(x, 0x1b), _mm_shuffle_epi32(y, 0x1b)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1000(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_hsub_epi32(x, _mm_shuffle_epi32(x, 0x1b)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1001(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_hsub_epi32(_mm_shuffle_epi32(x, 0x1b), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1002(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_shuffle_epi32(_mm_mul_epi32(x, y), 0x1b); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1003(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_mul_epi32(_mm_shuffle_epi32(x, 0x1b), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1004(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_mul_epi32(x, _mm_shuffle_epi32(y, 0x1b)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1005(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_mul_epi32(_mm_shuffle_epi32(x, 0x1b), _mm_shuffle_epi32(y, 0x1b)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1006(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_mul_epi32(x, _mm_shuffle_epi32(x, 0x1b)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1007(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_mul_epi32(_mm_shuffle_epi32(x, 0x1b), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1008(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_shuffle_epi32(_mm_mul_epu32(x, y), 0x1b); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1009(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_mul_epu32(_mm_shuffle_epi32(x, 0x1b), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1010(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_mul_epu32(x, _mm_shuffle_epi32(y, 0x1b)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1011(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_mul_epu32(_mm_shuffle_epi32(x, 0x1b), _mm_shuffle_epi32(y, 0x1b)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1012(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_mul_epu32(x, _mm_shuffle_epi32(x, 0x1b)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1013(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_mul_epu32(_mm_shuffle_epi32(x, 0x1b), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1014(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_shuffle_epi32(_mm_unpacklo_epi32(x, y), 0x1b); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1015(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_unpacklo_epi32(_mm_shuffle_epi32(x, 0x1b), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1016(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_unpacklo_epi32(x, _mm_shuffle_epi32(y, 0x1b)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1017(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_unpacklo_epi32(_mm_shuffle_epi32(x, 0x1b), _mm_shuffle_epi32(y, 0x1b)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1018(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_unpacklo_epi32(x, _mm_shuffle_epi32(x, 0x1b)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1019(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_unpacklo_epi32(_mm_shuffle_epi32(x, 0x1b), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1020(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_shuffle_epi32(_mm_unpackhi_epi32(x, y), 0x1b); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1021(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_unpackhi_epi32(_mm_shuffle_epi32(x, 0x1b), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1022(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_unpackhi_epi32(x, _mm_shuffle_epi32(y, 0x1b)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1023(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_unpackhi_epi32(_mm_shuffle_epi32(x, 0x1b), _mm_shuffle_epi32(y, 0x1b)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1024(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_unpackhi_epi32(x, _mm_shuffle_epi32(x, 0x1b)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1025(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_unpackhi_epi32(_mm_shuffle_epi32(x, 0x1b), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1026(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_shuffle_epi32(_mm_blendv_epi8(x, y, _mm_cmpgt_epi32(x, y)), 0x1b); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1027(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_blendv_epi8(_mm_shuffle_epi32(x, 0x1b), y, _mm_cmpgt_epi32(_mm_shuffle_epi32(x, 0x1b), y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1028(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_blendv_epi8(x, _mm_shuffle_epi32(y, 0x1b), _mm_cmpgt_epi32(x, _mm_shuffle_epi32(y, 0x1b))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1029(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_blendv_epi8(_mm_shuffle_epi32(x, 0x1b), _mm_shuffle_epi32(y, 0x1b), _mm_cmpgt_epi32(_mm_shuffle_epi32(x, 0x1b), _mm_shuffle_epi32(y, 0x1b))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1030(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_blendv_epi8(x, _mm_shuffle_epi32(x, 0x1b), _mm_cmpgt_epi32(x, _mm_shuffle_epi32(x, 0x1b))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1031(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_blendv_epi8(_mm_shuffle_epi32(x, 0x1b), x, _mm_cmpgt_epi32(_mm_shuffle_epi32(x, 0x1b), x)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1032(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_shuffle_epi32(_mm_blendv_epi8(y, x, _mm_cmpgt_epi32(x, y)), 0x1b); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1033(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_blendv_epi8(y, _mm_shuffle_epi32(x, 0x1b), _mm_cmpgt_epi32(_mm_shuffle_epi32(x, 0x1b), y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1034(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_blendv_epi8(_mm_shuffle_epi32(y, 0x1b), x, _mm_cmpgt_epi32(x, _mm_shuffle_epi32(y, 0x1b))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1035(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_blendv_epi8(_mm_shuffle_epi32(y, 0x1b), _mm_shuffle_epi32(x, 0x1b), _mm_cmpgt_epi32(_mm_shuffle_epi32(x, 0x1b), _mm_shuffle_epi32(y, 0x1b))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1036(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_blendv_epi8(_mm_shuffle_epi32(x, 0x1b), x, _mm_cmpgt_epi32(x, _mm_shuffle_epi32(x, 0x1b))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1037(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_blendv_epi8(x, _mm_shuffle_epi32(x, 0x1b), _mm_cmpgt_epi32(_mm_shuffle_epi32(x, 0x1b), x)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1038(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_shuffle_epi32(_mm_or_si128(_mm_and_si128(_mm_cmpgt_epi32(x, y), x), _mm_andnot_si128(_mm_cmpgt_epi32(x, y), y)), 0x1b); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1039(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_or_si128(_mm_and_si128(_mm_cmpgt_epi32(_mm_shuffle_epi32(x, 0x1b), y), _mm_shuffle_epi32(x, 0x1b)), _mm_andnot_si128(_mm_cmpgt_epi32(_mm_shuffle_epi32(x, 0x1b), y), y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1040(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_or_si128(_mm_and_si128(_mm_cmpgt_epi32(x, _mm_shuffle_epi32(y, 0x1b)), x), _mm_andnot_si128(_mm_cmpgt_epi32(x, _mm_shuffle_epi32(y, 0x1b)), _mm_shuffle_epi32(y, 0x1b))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1041(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_or_si128(_mm_and_si128(_mm_cmpgt_epi32(_mm_shuffle_epi32(x, 0x1b), _mm_shuffle_epi32(y, 0x1b)), _mm_shuffle_epi32(x, 0x1b)), _mm_andnot_si128(_mm_cmpgt_epi32(_mm_shuffle_epi32(x, 0x1b), _mm_shuffle_epi32(y, 0x1b)), _mm_shuffle_epi32(y, 0x1b))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1042(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_or_si128(_mm_and_si128(_mm_cmpgt_epi32(x, _mm_shuffle_epi32(x, 0x1b)), x), _mm_andnot_si128(_mm_cmpgt_epi32(x, _mm_shuffle_epi32(x, 0x1b)), _mm_shuffle_epi32(x, 0x1b))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1043(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_or_si128(_mm_and_si128(_mm_cmpgt_epi32(_mm_shuffle_epi32(x, 0x1b), x), _mm_shuffle_epi32(x, 0x1b)), _mm_andnot_si128(_mm_cmpgt_epi32(_mm_shuffle_epi32(x, 0x1b), x), x)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1044(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_shuffle_epi32(_mm_blendv_epi8(x, y, _mm_cmpeq_epi32(x, y)), 0x1b); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1045(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_blendv_epi8(_mm_shuffle_epi32(x, 0x1b), y, _mm_cmpeq_epi32(_mm_shuffle_epi32(x, 0x1b), y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1046(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_blendv_epi8(x, _mm_shuffle_epi32(y, 0x1b), _mm_cmpeq_epi32(x, _mm_shuffle_epi32(y, 0x1b))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1047(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_blendv_epi8(_mm_shuffle_epi32(x, 0x1b), _mm_shuffle_epi32(y, 0x1b), _mm_cmpeq_epi32(_mm_shuffle_epi32(x, 0x1b), _mm_shuffle_epi32(y, 0x1b))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1048(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_blendv_epi8(x, _mm_shuffle_epi32(x, 0x1b), _mm_cmpeq_epi32(x, _mm_shuffle_epi32(x, 0x1b))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1049(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_blendv_epi8(_mm_shuffle_epi32(x, 0x1b), x, _mm_cmpeq_epi32(_mm_shuffle_epi32(x, 0x1b), x)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1050(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_shuffle_epi32(_mm_blendv_epi8(y, x, _mm_cmpeq_epi32(x, y)), 0x1b); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1051(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_blendv_epi8(y, _mm_shuffle_epi32(x, 0x1b), _mm_cmpeq_epi32(_mm_shuffle_epi32(x, 0x1b), y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1052(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_blendv_epi8(_mm_shuffle_epi32(y, 0x1b), x, _mm_cmpeq_epi32(x, _mm_shuffle_epi32(y, 0x1b))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1053(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_blendv_epi8(_mm_shuffle_epi32(y, 0x1b), _mm_shuffle_epi32(x, 0x1b), _mm_cmpeq_epi32(_mm_shuffle_epi32(x, 0x1b), _mm_shuffle_epi32(y, 0x1b))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1054(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_blendv_epi8(_mm_shuffle_epi32(x, 0x1b), x, _mm_cmpeq_epi32(x, _mm_shuffle_epi32(x, 0x1b))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1055(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_blendv_epi8(x, _mm_shuffle_epi32(x, 0x1b), _mm_cmpeq_epi32(_mm_shuffle_epi32(x, 0x1b), x)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1056(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_shuffle_epi32(_mm_or_si128(_mm_and_si128(_mm_cmpeq_epi32(x, y), x), _mm_andnot_si128(_mm_cmpeq_epi32(x, y), y)), 0x1b); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1057(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_or_si128(_mm_and_si128(_mm_cmpeq_epi32(_mm_shuffle_epi32(x, 0x1b), y), _mm_shuffle_epi32(x, 0x1b)), _mm_andnot_si128(_mm_cmpeq_epi32(_mm_shuffle_epi32(x, 0x1b), y), y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1058(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_or_si128(_mm_and_si128(_mm_cmpeq_epi32(x, _mm_shuffle_epi32(y, 0x1b)), x), _mm_andnot_si128(_mm_cmpeq_epi32(x, _mm_shuffle_epi32(y, 0x1b)), _mm_shuffle_epi32(y, 0x1b))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1059(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_or_si128(_mm_and_si128(_mm_cmpeq_epi32(_mm_shuffle_epi32(x, 0x1b), _mm_shuffle_epi32(y, 0x1b)), _mm_shuffle_epi32(x, 0x1b)), _mm_andnot_si128(_mm_cmpeq_epi32(_mm_shuffle_epi32(x, 0x1b), _mm_shuffle_epi32(y, 0x1b)), _mm_shuffle_epi32(y, 0x1b))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1060(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_or_si128(_mm_and_si128(_mm_cmpeq_epi32(x, _mm_shuffle_epi32(x, 0x1b)), x), _mm_andnot_si128(_mm_cmpeq_epi32(x, _mm_shuffle_epi32(x, 0x1b)), _mm_shuffle_epi32(x, 0x1b))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1061(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_or_si128(_mm_and_si128(_mm_cmpeq_epi32(_mm_shuffle_epi32(x, 0x1b), x), _mm_shuffle_epi32(x, 0x1b)), _mm_andnot_si128(_mm_cmpeq_epi32(_mm_shuffle_epi32(x, 0x1b), x), x)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1062(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_shuffle_epi32(_mm_mullo_epi32(x, y), 0x1b); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1063(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_mullo_epi32(_mm_shuffle_epi32(x, 0x1b), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1064(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_mullo_epi32(x, _mm_shuffle_epi32(y, 0x1b)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1065(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_mullo_epi32(_mm_shuffle_epi32(x, 0x1b), _mm_shuffle_epi32(y, 0x1b)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1066(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_mullo_epi32(x, _mm_shuffle_epi32(x, 0x1b)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1067(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_mullo_epi32(_mm_shuffle_epi32(x, 0x1b), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1068(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_shuffle_epi32(_mm_sllv_epi32(x, y), 0x1b); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1069(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi32(_mm_shuffle_epi32(x, 0x1b), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1070(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi32(x, _mm_shuffle_epi32(y, 0x1b)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1071(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi32(_mm_shuffle_epi32(x, 0x1b), _mm_shuffle_epi32(y, 0x1b)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1072(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi32(x, _mm_shuffle_epi32(x, 0x1b)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1073(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi32(_mm_shuffle_epi32(x, 0x1b), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1074(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_shuffle_epi32(_mm_srlv_epi32(x, y), 0x1b); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1075(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi32(_mm_shuffle_epi32(x, 0x1b), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1076(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi32(x, _mm_shuffle_epi32(y, 0x1b)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1077(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi32(_mm_shuffle_epi32(x, 0x1b), _mm_shuffle_epi32(y, 0x1b)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1078(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi32(x, _mm_shuffle_epi32(x, 0x1b)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1079(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi32(_mm_shuffle_epi32(x, 0x1b), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1080(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_shuffle_epi32(_mm_srav_epi32(x, y), 0x1b); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1081(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srav_epi32(_mm_shuffle_epi32(x, 0x1b), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1082(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srav_epi32(x, _mm_shuffle_epi32(y, 0x1b)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1083(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srav_epi32(_mm_shuffle_epi32(x, 0x1b), _mm_shuffle_epi32(y, 0x1b)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1084(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srav_epi32(x, _mm_shuffle_epi32(x, 0x1b)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1085(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srav_epi32(_mm_shuffle_epi32(x, 0x1b), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1086(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_shuffle_epi32(_mm_add_epi32(x, y), 0x39); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1087(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_add_epi32(_mm_shuffle_epi32(x, 0x39), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1088(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_add_epi32(x, _mm_shuffle_epi32(y, 0x39)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1089(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_add_epi32(_mm_shuffle_epi32(x, 0x39), _mm_shuffle_epi32(y, 0x39)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1090(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_add_epi32(x, _mm_shuffle_epi32(x, 0x39)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1091(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_add_epi32(_mm_shuffle_epi32(x, 0x39), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1092(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_shuffle_epi32(_mm_sub_epi32(x, y), 0x39); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1093(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sub_epi32(_mm_shuffle_epi32(x, 0x39), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1094(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sub_epi32(x, _mm_shuffle_epi32(y, 0x39)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1095(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sub_epi32(_mm_shuffle_epi32(x, 0x39), _mm_shuffle_epi32(y, 0x39)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1096(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sub_epi32(x, _mm_shuffle_epi32(x, 0x39)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1097(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sub_epi32(_mm_shuffle_epi32(x, 0x39), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1098(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_shuffle_epi32(_mm_min_epi32(x, y), 0x39); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1099(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_min_epi32(_mm_shuffle_epi32(x, 0x39), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1100(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_min_epi32(x, _mm_shuffle_epi32(y, 0x39)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1101(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_min_epi32(_mm_shuffle_epi32(x, 0x39), _mm_shuffle_epi32(y, 0x39)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1102(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_min_epi32(x, _mm_shuffle_epi32(x, 0x39)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1103(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_min_epi32(_mm_shuffle_epi32(x, 0x39), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1104(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_shuffle_epi32(_mm_max_epi32(x, y), 0x39); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1105(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_max_epi32(_mm_shuffle_epi32(x, 0x39), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1106(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_max_epi32(x, _mm_shuffle_epi32(y, 0x39)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1107(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_max_epi32(_mm_shuffle_epi32(x, 0x39), _mm_shuffle_epi32(y, 0x39)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1108(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_max_epi32(x, _mm_shuffle_epi32(x, 0x39)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1109(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_max_epi32(_mm_shuffle_epi32(x, 0x39), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1110(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_shuffle_epi32(_mm_min_epu32(x, y), 0x39); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1111(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_min_epu32(_mm_shuffle_epi32(x, 0x39), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1112(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_min_epu32(x, _mm_shuffle_epi32(y, 0x39)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1113(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_min_epu32(_mm_shuffle_epi32(x, 0x39), _mm_shuffle_epi32(y, 0x39)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1114(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_min_epu32(x, _mm_shuffle_epi32(x, 0x39)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1115(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_min_epu32(_mm_shuffle_epi32(x, 0x39), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1116(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_shuffle_epi32(_mm_max_epu32(x, y), 0x39); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1117(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_max_epu32(_mm_shuffle_epi32(x, 0x39), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1118(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_max_epu32(x, _mm_shuffle_epi32(y, 0x39)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1119(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_max_epu32(_mm_shuffle_epi32(x, 0x39), _mm_shuffle_epi32(y, 0x39)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1120(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_max_epu32(x, _mm_shuffle_epi32(x, 0x39)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1121(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_max_epu32(_mm_shuffle_epi32(x, 0x39), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1122(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_shuffle_epi32(_mm_and_si128(x, y), 0x39); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1123(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_and_si128(_mm_shuffle_epi32(x, 0x39), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1124(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_and_si128(x, _mm_shuffle_epi32(y, 0x39)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1125(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_and_si128(_mm_shuffle_epi32(x, 0x39), _mm_shuffle_epi32(y, 0x39)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1126(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_and_si128(x, _mm_shuffle_epi32(x, 0x39)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1127(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_and_si128(_mm_shuffle_epi32(x, 0x39), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1128(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_shuffle_epi32(_mm_or_si128(x, y), 0x39); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1129(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_or_si128(_mm_shuffle_epi32(x, 0x39), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1130(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_or_si128(x, _mm_shuffle_epi32(y, 0x39)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1131(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_or_si128(_mm_shuffle_epi32(x, 0x39), _mm_shuffle_epi32(y, 0x39)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1132(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_or_si128(x, _mm_shuffle_epi32(x, 0x39)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1133(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_or_si128(_mm_shuffle_epi32(x, 0x39), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1134(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_shuffle_epi32(_mm_xor_si128(x, y), 0x39); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1135(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_xor_si128(_mm_shuffle_epi32(x, 0x39), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1136(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_xor_si128(x, _mm_shuffle_epi32(y, 0x39)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1137(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_xor_si128(_mm_shuffle_epi32(x, 0x39), _mm_shuffle_epi32(y, 0x39)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1138(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_xor_si128(x, _mm_shuffle_epi32(x, 0x39)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1139(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_xor_si128(_mm_shuffle_epi32(x, 0x39), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1140(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_shuffle_epi32(_mm_andnot_si128(x, y), 0x39); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1141(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_andnot_si128(_mm_shuffle_epi32(x, 0x39), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1142(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_andnot_si128(x, _mm_shuffle_epi32(y, 0x39)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1143(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_andnot_si128(_mm_shuffle_epi32(x, 0x39), _mm_shuffle_epi32(y, 0x39)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1144(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_andnot_si128(x, _mm_shuffle_epi32(x, 0x39)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1145(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_andnot_si128(_mm_shuffle_epi32(x, 0x39), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1146(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_shuffle_epi32(_mm_cmpeq_epi32(x, y), 0x39); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1147(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_cmpeq_epi32(_mm_shuffle_epi32(x, 0x39), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1148(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_cmpeq_epi32(x, _mm_shuffle_epi32(y, 0x39)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1149(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_cmpeq_epi32(_mm_shuffle_epi32(x, 0x39), _mm_shuffle_epi32(y, 0x39)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1150(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_cmpeq_epi32(x, _mm_shuffle_epi32(x, 0x39)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1151(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_cmpeq_epi32(_mm_shuffle_epi32(x, 0x39), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1152(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_shuffle_epi32(_mm_cmpgt_epi32(x, y), 0x39); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1153(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_cmpgt_epi32(_mm_shuffle_epi32(x, 0x39), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1154(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_cmpgt_epi32(x, _mm_shuffle_epi32(y, 0x39)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1155(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_cmpgt_epi32(_mm_shuffle_epi32(x, 0x39), _mm_shuffle_epi32(y, 0x39)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1156(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_cmpgt_epi32(x, _mm_shuffle_epi32(x, 0x39)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1157(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_cmpgt_epi32(_mm_shuffle_epi32(x, 0x39), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1158(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_shuffle_epi32(_mm_sign_epi32(x, y), 0x39); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1159(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sign_epi32(_mm_shuffle_epi32(x, 0x39), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1160(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sign_epi32(x, _mm_shuffle_epi32(y, 0x39)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1161(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sign_epi32(_mm_shuffle_epi32(x, 0x39), _mm_shuffle_epi32(y, 0x39)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1162(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sign_epi32(x, _mm_shuffle_epi32(x, 0x39)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1163(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sign_epi32(_mm_shuffle_epi32(x, 0x39), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1164(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_shuffle_epi32(_mm_packs_epi32(x, y), 0x39); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1165(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_packs_epi32(_mm_shuffle_epi32(x, 0x39), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1166(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_packs_epi32(x, _mm_shuffle_epi32(y, 0x39)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1167(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_packs_epi32(_mm_shuffle_epi32(x, 0x39), _mm_shuffle_epi32(y, 0x39)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1168(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_packs_epi32(x, _mm_shuffle_epi32(x, 0x39)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1169(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_packs_epi32(_mm_shuffle_epi32(x, 0x39), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1170(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_shuffle_epi32(_mm_packus_epi32(x, y), 0x39); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1171(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_packus_epi32(_mm_shuffle_epi32(x, 0x39), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1172(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_packus_epi32(x, _mm_shuffle_epi32(y, 0x39)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1173(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_packus_epi32(_mm_shuffle_epi32(x, 0x39), _mm_shuffle_epi32(y, 0x39)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1174(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_packus_epi32(x, _mm_shuffle_epi32(x, 0x39)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1175(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_packus_epi32(_mm_shuffle_epi32(x, 0x39), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1176(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_shuffle_epi32(_mm_hadd_epi32(x, y), 0x39); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1177(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_hadd_epi32(_mm_shuffle_epi32(x, 0x39), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1178(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_hadd_epi32(x, _mm_shuffle_epi32(y, 0x39)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1179(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_hadd_epi32(_mm_shuffle_epi32(x, 0x39), _mm_shuffle_epi32(y, 0x39)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1180(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_hadd_epi32(x, _mm_shuffle_epi32(x, 0x39)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1181(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_hadd_epi32(_mm_shuffle_epi32(x, 0x39), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1182(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_shuffle_epi32(_mm_hsub_epi32(x, y), 0x39); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1183(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_hsub_epi32(_mm_shuffle_epi32(x, 0x39), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1184(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_hsub_epi32(x, _mm_shuffle_epi32(y, 0x39)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1185(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_hsub_epi32(_mm_shuffle_epi32(x, 0x39), _mm_shuffle_epi32(y, 0x39)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1186(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_hsub_epi32(x, _mm_shuffle_epi32(x, 0x39)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1187(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_hsub_epi32(_mm_shuffle_epi32(x, 0x39), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1188(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_shuffle_epi32(_mm_mul_epi32(x, y), 0x39); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1189(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_mul_epi32(_mm_shuffle_epi32(x, 0x39), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1190(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_mul_epi32(x, _mm_shuffle_epi32(y, 0x39)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1191(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_mul_epi32(_mm_shuffle_epi32(x, 0x39), _mm_shuffle_epi32(y, 0x39)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1192(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_mul_epi32(x, _mm_shuffle_epi32(x, 0x39)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1193(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_mul_epi32(_mm_shuffle_epi32(x, 0x39), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1194(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_shuffle_epi32(_mm_mul_epu32(x, y), 0x39); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1195(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_mul_epu32(_mm_shuffle_epi32(x, 0x39), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1196(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_mul_epu32(x, _mm_shuffle_epi32(y, 0x39)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1197(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_mul_epu32(_mm_shuffle_epi32(x, 0x39), _mm_shuffle_epi32(y, 0x39)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1198(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_mul_epu32(x, _mm_shuffle_epi32(x, 0x39)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1199(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_mul_epu32(_mm_shuffle_epi32(x, 0x39), x); _mm_storeu_si128((__m128i*)po, r); }
extern const Entry table_4[] = {
  {"128:_mm_slli_epi32(_mm_hadd_epi32(x, y), 31)", f0, 0, 128},
  {"128:_mm_hadd_epi32(_mm_slli_epi32(x, 31), y)", f1, 0, 128},
  {"128:_mm_hadd_epi32(x, _mm_slli_epi32(y, 31))", f2, 0, 128},
  {"128:_mm_hadd_epi32(_mm_slli_epi32(x, 31), _mm_slli_epi32(y, 31))", f3, 0, 128},
  {"128:_mm_hadd_epi32(x, _mm_slli_epi32(x, 31))", f4, 0, 128},
  {"128:_mm_hadd_epi32(_mm_slli_epi32(x, 31), x)", f5, 0, 128},
  {"128:_mm_slli_epi32(_mm_hsub_epi32(x, y), 31)", f6, 0, 128},
  {"128:_mm_hsub_epi32(_mm_slli_epi32(x, 31), y)", f7, 0, 128},
  {"128:_mm_hsub_epi32(x, _mm_slli_epi32(y, 31))", f8, 0, 128},
  {"128:_mm_hsub_epi32(_mm_slli_epi32(x, 31), _mm_slli_epi32(y, 31))", f9, 0, 128},
  {"128:_mm_hsub_epi32(x, _mm_slli_epi32(x, 31))", f10, 0, 128},
  {"128:_mm_hsub_epi32(_mm_slli_epi32(x, 31), x)", f11, 0, 128},
  {"128:_mm_slli_epi32(_mm_mul_epi32(x, y), 31)", f12, 0, 128},
  {"128:_mm_mul_epi32(_mm_slli_epi32(x, 31), y)", f13, 0, 128},
  {"128:_mm_mul_epi32(x, _mm_slli_epi32(y, 31))", f14, 0, 128},
  {"128:_mm_mul_epi32(_mm_slli_epi32(x, 31), _mm_slli_epi32(y, 31))", f15, 0, 128},
  {"128:_mm_mul_epi32(x, _mm_slli_epi32(x, 31))", f16, 0, 128},
  {"128:_mm_mul_epi32(_mm_slli_epi32(x, 31), x)", f17, 0, 128},
  {"128:_mm_slli_epi32(_mm_mul_epu32(x, y), 31)", f18, 0, 128},
  {"128:_mm_mul_epu32(_mm_slli_epi32(x, 31), y)", f19, 0, 128},
  {"128:_mm_mul_epu32(x, _mm_slli_epi32(y, 31))", f20, 0, 128},
  {"128:_mm_mul_epu32(_mm_slli_epi32(x, 31), _mm_slli_epi32(y, 31))", f21, 0, 128},
  {"128:_mm_mul_epu32(x, _mm_slli_epi32(x, 31))", f22, 0, 128},
  {"128:_mm_mul_epu32(_mm_slli_epi32(x, 31), x)", f23, 0, 128},
  {"128:_mm_slli_epi32(_mm_unpacklo_epi32(x, y), 31)", f24, 0, 128},
  {"128:_mm_unpacklo_epi32(_mm_slli_epi32(x, 31), y)", f25, 0, 128},
  {"128:_mm_unpacklo_epi32(x, _mm_slli_epi32(y, 31))", f26, 0, 128},
  {"128:_mm_unpacklo_epi32(_mm_slli_epi32(x, 31), _mm_slli_epi32(y, 31))", f27, 0, 128},
  {"128:_mm_unpacklo_epi32(x, _mm_slli_epi32(x, 31))", f28, 0, 128},
  {"128:_mm_unpacklo_epi32(_mm_slli_epi32(x, 31), x)", f29, 0, 128},
  {"128:_mm_slli_epi32(_mm_unpackhi_epi32(x, y), 31)", f30, 0, 128},
  {"128:_mm_unpackhi_epi32(_mm_slli_epi32(x, 31), y)", f31, 0, 128},
  {"128:_mm_unpackhi_epi32(x, _mm_slli_epi32(y, 31))", f32, 0, 128},
  {"128:_mm_unpackhi_epi32(_mm_slli_epi32(x, 31), _mm_slli_epi32(y, 31))", f33, 0, 128},
  {"128:_mm_unpackhi_epi32(x, _mm_slli_epi32(x, 31))", f34, 0, 128},
  {"128:_mm_unpackhi_epi32(_mm_slli_epi32(x, 31), x)", f35, 0, 128},
  {"128:_mm_slli_epi32(_mm_blendv_epi8(x, y, _mm_cmpgt_epi32(x, y)), 31)", f36, 0, 128},
  {"128:_mm_blendv_epi8(_mm_slli_epi32(x, 31), y, _mm_cmpgt_epi32(_mm_slli_epi32(x, 31), y))", f37, 0, 128},
  {"128:_mm_blendv_epi8(x, _mm_slli_epi32(y, 31), _mm_cmpgt_epi32(x, _mm_slli_epi32(y, 31)))", f38, 0, 128},
  {"128:_mm_blendv_epi8(_mm_slli_epi32(x, 31), _mm_slli_epi32(y, 31), _mm_cmpgt_epi32(_mm_slli_epi32(x, 31), _mm_slli_epi32(y, 31)))", f39, 0, 128},
  {"128:_mm_blendv_epi8(x, _mm_slli_epi32(x, 31), _mm_cmpgt_epi32(x, _mm_slli_epi32(x, 31)))", f40, 0, 128},
  {"128:_mm_blendv_epi8(_mm_slli_epi32(x, 31), x, _mm_cmpgt_epi32(_mm_slli_epi32(x, 31), x))", f41, 0, 128},
  {"128:_mm_slli_epi32(_mm_blendv_epi8(y, x, _mm_cmpgt_epi32(x, y)), 31)", f42, 0, 128},
  {"128:_mm_blendv_epi8(y, _mm_slli_epi32(x, 31), _mm_cmpgt_epi32(_mm_slli_epi32(x, 31), y))", f43, 0, 128},
  {"128:_mm_blendv_epi8(_mm_slli_epi32(y, 31), x, _mm_cmpgt_epi32(x, _mm_slli_epi32(y, 31)))", f44, 0, 128},
  {"128:_mm_blendv_epi8(_mm_slli_epi32(y, 31), _mm_slli_epi32(x, 31), _mm_cmpgt_epi32(_mm_slli_epi32(x, 31), _mm_slli_epi32(y, 31)))", f45, 0, 128},
  {"128:_mm_blendv_epi8(_mm_slli_epi32(x, 31), x, _mm_cmpgt_epi32(x, _mm_slli_epi32(x, 31)))", f46, 0, 128},
  {"128:_mm_blendv_epi8(x, _mm_slli_epi32(x, 31), _mm_cmpgt_epi32(_mm_slli_epi32(x, 31), x))", f47, 0, 128},
  {"128:_mm_slli_epi32(_mm_or_si128(_mm_and_si128(_mm_cmpgt_epi32(x, y), x), _mm_andnot_si128(_mm_cmpgt_epi32(x, y), y)), 31)", f48, 0, 128},
  {"128:_mm_or_si128(_mm_and_si128(_mm_cmpgt_epi32(_mm_slli_epi32(x, 31), y), _mm_slli_epi32(x, 31)), _mm_andnot_si128(_mm_cmpgt_epi32(_mm_slli_epi32(x, 31), y), y))", f49, 0, 128},
  {"128:_mm_or_si128(_mm_and_si128(_mm_cmpgt_epi32(x, _mm_slli_epi32(y, 31)), x), _mm_andnot_si128(_mm_cmpgt_epi32(x, _mm_slli_epi32(y, 31)), _mm_slli_epi32(y, 31)))", f50, 0, 128},
  {"128:_mm_or_si128(_mm_and_si128(_mm_cmpgt_epi32(_mm_slli_epi32(x, 31), _mm_slli_epi32(y, 31)), _mm_slli_epi32(x, 31)), _mm_andnot_si128(_mm_cmpgt_epi32(_mm_slli_epi32(x, 31), _mm_slli_epi32(y, 31)), _mm_slli_epi32(y, 31)))", f51, 0, 128},
  {"128:_mm_or_si128(_mm_and_si128(_mm_cmpgt_epi32(x, _mm_slli_epi32(x, 31)), x), _mm_andnot_si128(_mm_cmpgt_epi32(x, _mm_slli_epi32(x, 31)), _mm_slli_epi32(x, 31)))", f52, 0, 128},
  {"128:_mm_or_si128(_mm_and_si128(_mm_cmpgt_epi32(_mm_slli_epi32(x, 31), x), _mm_slli_epi32(x, 31)), _mm_andnot_si128(_mm_cmpgt_epi32(_mm_slli_epi32(x, 31), x), x))", f53, 0, 128},
  {"128:_mm_slli_epi32(_mm_blendv_epi8(x, y, _mm_cmpeq_epi32(x, y)), 31)", f54, 0, 128},
  {"128:_mm_blendv_epi8(_mm_slli_epi32(x, 31), y, _mm_cmpeq_epi32(_mm_slli_epi32(x, 31), y))", f55, 0, 128},
  {"128:_mm_blendv_epi8(x, _mm_slli_epi32(y, 31), _mm_cmpeq_epi32(x, _mm_slli_epi32(y, 31)))", f56, 0, 128},
  {"128:_mm_blendv_epi8(_mm_slli_epi32(x, 31), _mm_slli_epi32(y, 31), _mm_cmpeq_epi32(_mm_slli_epi32(x, 31), _mm_slli_epi32(y, 31)))", f57, 0, 128},
  {"128:_mm_blendv_epi8(x, _mm_slli_epi32(x, 31), _mm_cmpeq_epi32(x, _mm_slli_epi32(x, 31)))", f58, 0, 128},
  {"128:_mm_blendv_epi8(_mm_slli_epi32(x, 31), x, _mm_cmpeq_epi32(_mm_slli_epi32(x, 31), x))", f59, 0, 128},
  {"128:_mm_slli_epi32(_mm_blendv_epi8(y, x, _mm_cmpeq_epi32(x, y)), 31)", f60, 0, 128},
  {"128:_mm_blendv_epi8(y, _mm_slli_epi32(x, 31), _mm_cmpeq_epi32(_mm_slli_epi32(x, 31), y))", f61, 0, 128},
  {"128:_mm_blendv_epi8(_mm_slli_epi32(y, 31), x, _mm_cmpeq_epi32(x, _mm_slli_epi32(y, 31)))", f62, 0, 128},
  {"128:_mm_blendv_epi8(_mm_slli_epi32(y, 31), _mm_slli_epi32(x, 31), _mm_cmpeq_epi32(_mm_slli_epi32(x, 31), _mm_slli_epi32(y, 31)))", f63, 0, 128},
  {"128:_mm_blendv_epi8(_mm_slli_epi32(x, 31), x, _mm_cmpeq_epi32(x, _mm_slli_epi32(x, 31)))", f64, 0, 128},
  {"128:_mm_blendv_epi8(x, _mm_slli_epi32(x, 31), _mm_cmpeq_epi32(_mm_slli_epi32(x, 31), x))", f65, 0, 128},
  {"128:_mm_slli_epi32(_mm_or_si128(_mm_and_si128(_mm_cmpeq_epi32(x, y), x), _mm_andnot_si128(_mm_cmpeq_epi32(x, y), y)), 31)", f66, 0, 128},
  {"128:_mm_or_si128(_mm_and_si128(_mm_cmpeq_epi32(_mm_slli_epi32(x, 31), y), _mm_slli_epi32(x, 31)), _mm_andnot_si128(_mm_cmpeq_epi32(_mm_slli_epi32(x, 31), y), y))", f67, 0, 128},
  {"128:_mm_or_si128(_mm_and_si128(_mm_cmpeq_epi32(x, _mm_slli_epi32(y, 31)), x), _mm_andnot_si128(_mm_cmpeq_epi32(x, _mm_slli_epi32(y, 31)), _mm_slli_epi32(y, 31)))", f68, 0, 128},
  {"128:_mm_or_si128(_mm_and_si128(_mm_cmpeq_epi32(_mm_slli_epi32(x, 31), _mm_slli_epi32(y, 31)), _mm_slli_epi32(x, 31)), _mm_andnot_si128(_mm_cmpeq_epi32(_mm_slli_epi32(x, 31), _mm_slli_epi32(y, 31)), _mm_slli_epi32(y, 31)))", f69, 0, 128},
  {"128:_mm_or_si128(_mm_and_si128(_mm_cmpeq_epi32(x, _mm_slli_epi32(x, 31)), x), _mm_andnot_si128(_mm_cmpeq_epi32(x, _mm_slli_epi32(x, 31)), _mm_slli_epi32(x, 31)))", f70, 0, 128},
  {"128:_mm_or_si128(_mm_and_si128(_mm_cmpeq_epi32(_mm_slli_epi32(x, 31), x), _mm_slli_epi32(x, 31)), _mm_andnot_si128(_mm_cmpeq_epi32(_mm_slli_epi32(x, 31), x), x))", f71, 0, 128},
  {"128:_mm_slli_epi32(_mm_mullo_epi32(x, y), 31)", f72, 0, 128},
  {"128:_mm_mullo_epi32(_mm_slli_epi32(x, 31), y)", f73, 0, 128},
  {"128:_mm_mullo_epi32(x, _mm_slli_epi32(y, 31))", f74, 0, 128},
  {"128:_mm_mullo_epi32(_mm_slli_epi32(x, 31), _mm_slli_epi32(y, 31))", f75, 0, 128},
  {"128:_mm_mullo_epi32(x, _mm_slli_epi32(x, 31))", f76, 0, 128},
  {"128:_mm_mullo_epi32(_mm_slli_epi32(x, 31), x)", f77, 0, 128},
  {"128:_mm_slli_epi32(_mm_sllv_epi32(x, y), 31)", f78, 0, 128},
  {"128:_mm_sllv_epi32(_mm_slli_epi32(x, 31), y)", f79, 0, 128},
  {"128:_mm_sllv_epi32(x, _mm_slli_epi32(y, 31))", f80, 0, 128},
  {"128:_mm_sllv_epi32(_mm_slli_epi32(x, 31), _mm_slli_epi32(y, 31))", f81, 0, 128},
  {"128:_mm_sllv_epi32(x, _mm_slli_epi32(x, 31))", f82, 0, 128},
  {"128:_mm_sllv_epi32(_mm_slli_epi32(x, 31), x)", f83, 0, 128},
  {"128:_mm_slli_epi32(_mm_srlv_epi32(x, y), 31)", f84, 0, 128},
  {"128:_mm_srlv_epi32(_mm_slli_epi32(x, 31), y)", f85, 0, 128},
  {"128:_mm_srlv_epi32(x, _mm_slli_epi32(y, 31))", f86, 0, 128},
  {"128:_mm_srlv_epi32(_mm_slli_epi32(x, 31), _mm_slli_epi32(y, 31))", f87, 0, 128},
  {"128:_mm_srlv_epi32(x, _mm_slli_epi32(x, 31))", f88, 0, 128},
  {"128:_mm_srlv_epi32(_mm_slli_epi32(x, 31), x)", f89, 0, 128},
  {"128:_mm_slli_epi32(_mm_srav_epi32(x, y), 31)", f90, 0, 128},
  {"128:_mm_srav_epi32(_mm_slli_epi32(x, 31), y)", f91, 0, 128},
  {"128:_mm_srav_epi32(x, _mm_slli_epi32(y, 31))", f92, 0, 128},
  {"128:_mm_srav_epi32(_mm_slli_epi32(x, 31), _mm_slli_epi32(y, 31))", f93, 0, 128},
  {"128:_mm_srav_epi32(x, _mm_slli_epi32(x, 31))", f94, 0, 128},
  {"128:_mm_srav_epi32(_mm_slli_epi32(x, 31), x)", f95, 0, 128},
  {"128:_mm_srli_epi32(_mm_add_epi32(x, y), 31)", f96, 0, 128},
  {"128:_mm_add_epi32(_mm_srli_epi32(x, 31), y)", f97, 0, 128},
  {"128:_mm_add_epi32(x, _mm_srli_epi32(y, 31))", f98, 0, 128},
  {"128:_mm_add_epi32(_mm_srli_epi32(x, 31), _mm_srli_epi32(y, 31))", f99, 0, 128},
  {"128:_mm_add_epi32(x, _mm_srli_epi32(x, 31))", f100, 0, 128},
  {"128:_mm_add_epi32(_mm_srli_epi32(x, 31), x)", f101, 0, 128},
  {"128:_mm_srli_epi32(_mm_sub_epi32(x, y), 31)", f102, 0, 128},
  {"128:_mm_sub_epi32(_mm_srli_epi32(x, 31), y)", f103, 0, 128},
  {"128:_mm_sub_epi32(x, _mm_srli_epi32(y, 31))", f104, 0, 128},
  {"128:_mm_sub_epi32(_mm_srli_epi32(x, 31), _mm_srli_epi32(y, 31))", f105, 0, 128},
  {"128:_mm_sub_epi32(x, _mm_srli_epi32(x, 31))", f106, 0, 128},
  {"128:_mm_sub_epi32(_mm_srli_epi32(x, 31), x)", f107, 0, 128},
  {"128:_mm_srli_epi32(_mm_min_epi32(x, y), 31)", f108, 0, 128},
  {"128:_mm_min_epi32(_mm_srli_epi32(x, 31), y)", f109, 0, 128},
  {"128:_mm_min_epi32(x, _mm_srli_epi32(y, 31))", f110, 0, 128},
  {"128:_mm_min_epi32(_mm_srli_epi32(x, 31), _mm_srli_epi32(y, 31))", f111, 0, 128},
  {"128:_mm_min_epi32(x, _mm_srli_epi32(x, 31))", f112, 0, 128},
  {"128:_mm_min_epi32(_mm_srli_epi32(x, 31), x)", f113, 0, 128},
  {"128:_mm_srli_epi32(_mm_max_epi32(x, y), 31)", f114, 0, 128},
  {"128:_mm_max_epi32(_mm_srli_epi32(x, 31), y)", f115, 0, 128},
  {"128:_mm_max_epi32(x, _mm_srli_epi32(y, 31))", f116, 0, 128},
  {"128:_mm_max_epi32(_mm_srli_epi32(x, 31), _mm_srli_epi32(y, 31))", f117, 0, 128},
  {"128:_mm_max_epi32(x, _mm_srli_epi32(x, 31))", f118, 0, 128},
  {"128:_mm_max_epi32(_mm_srli_epi32(x, 31), x)", f119, 0, 128},
  {"128:_mm_srli_epi32(_mm_min_epu32(x, y), 31)", f120, 0, 128},
  {"128:_mm_min_epu32(_mm_srli_epi32(x, 31), y)", f121, 0, 128},
  {"128:_mm_min_epu32(x, _mm_srli_epi32(y, 31))", f122, 0, 128},
  {"128:_mm_min_epu32(_mm_srli_epi32(x, 31), _mm_srli_epi32(y, 31))", f123, 0, 128},
  {"128:_mm_min_epu32(x, _mm_srli_epi32(x, 31))", f124, 0, 128},
  {"128:_mm_min_epu32(_mm_srli_epi32(x, 31), x)", f125, 0, 128},
  {"128:_mm_srli_epi32(_mm_max_epu32(x, y), 31)", f126, 0, 128},
  {"128:_mm_max_epu32(_mm_srli_epi32(x, 31), y)", f127, 0, 128},
  {"128:_mm_max_epu32(x, _mm_srli_epi32(y, 31))", f128, 0, 128},
  {"128:_mm_max_epu32(_mm_srli_epi32(x, 31), _mm_srli_epi32(y, 31))", f129, 0, 128},
  {"128:_mm_max_epu32(x, _mm_srli_epi32(x, 31))", f130, 0, 128},
  {"128:_mm_max_epu32(_mm_srli_epi32(x, 31), x)", f131, 0, 128},
  {"128:_mm_srli_epi32(_mm_and_si128(x, y), 31)", f132, 0, 128},
  {"128:_mm_and_si128(_mm_srli_epi32(x, 31), y)", f133, 0, 128},
  {"128:_mm_and_si128(x, _mm_srli_epi32(y, 31))", f134, 0, 128},
  {"128:_mm_and_si128(_mm_srli_epi32(x, 31), _mm_srli_epi32(y, 31))", f135, 0, 128},
  {"128:_mm_and_si128(x, _mm_srli_epi32(x, 31))", f136, 0, 128},
  {"128:_mm_and_si128(_mm_srli_epi32(x, 31), x)", f137, 0, 128},
  {"128:_mm_srli_epi32(_mm_or_si128(x, y), 31)", f138, 0, 128},
  {"128:_mm_or_si128(_mm_srli_epi32(x, 31), y)", f139, 0, 128},
  {"128:_mm_or_si128(x, _mm_srli_epi32(y, 31))", f140, 0, 128},
  {"128:_mm_or_si128(_mm_srli_epi32(x, 31), _mm_srli_epi32(y, 31))", f141, 0, 128},
  {"128:_mm_or_si128(x, _mm_srli_epi32(x, 31))", f142, 0, 128},
  {"128:_mm_or_si128(_mm_srli_epi32(x, 31), x)", f143, 0, 128},
  {"128:_mm_srli_epi32(_mm_xor_si128(x, y), 31)", f144, 0, 128},
  {"128:_mm_xor_si128(_mm_srli_epi32(x, 31), y)", f145, 0, 128},
  {"128:_mm_xor_si128(x, _mm_srli_epi32(y, 31))", f146, 0, 128},
  {"128:_mm_xor_si128(_mm_srli_epi32(x, 31), _mm_srli_epi32(y, 31))", f147, 0, 128},
  {"128:_mm_xor_si128(x, _mm_srli_epi32(x, 31))", f148, 0, 128},
  {"128:_mm_xor_si128(_mm_srli_epi32(x, 31), x)", f149, 0, 128},
  {"128:_mm_srli_epi32(_mm_andnot_si128(x, y), 31)", f150, 0, 128},
  {"128:_mm_andnot_si128(_mm_srli_epi32(x, 31), y)", f151, 0, 128},
  {"128:_mm_andnot_si128(x, _mm_srli_epi32(y, 31))", f152, 0, 128},
  {"128:_mm_andnot_si128(_mm_srli_epi32(x, 31), _mm_srli_epi32(y, 31))", f153, 0, 128},
  {"128:_mm_andnot_si128(x, _mm_srli_epi32(x, 31))", f154, 0, 128},
  {"128:_mm_andnot_si128(_mm_srli_epi32(x, 31), x)", f155, 0, 128},
  {"128:_mm_srli_epi32(_mm_cmpeq_epi32(x, y), 31)", f156, 0, 128},
  {"128:_mm_cmpeq_epi32(_mm_srli_epi32(x, 31), y)", f157, 0, 128},
  {"128:_mm_cmpeq_epi32(x, _mm_srli_epi32(y, 31))", f158, 0, 128},
  {"128:_mm_cmpeq_epi32(_mm_srli_epi32(x, 31), _mm_srli_epi32(y, 31))", f159, 0, 128},
  {"128:_mm_cmpeq_epi32(x, _mm_srli_epi32(x, 31))", f160, 0, 128},
  {"128:_mm_cmpeq_epi32(_mm_srli_epi32(x, 31), x)", f161, 0, 128},
  {"128:_mm_srli_epi32(_mm_cmpgt_epi32(x, y), 31)", f162, 0, 128},
  {"128:_mm_cmpgt_epi32(_mm_srli_epi32(x, 31), y)", f163, 0, 128},
  {"128:_mm_cmpgt_epi32(x, _mm_srli_epi32(y, 31))", f164, 0, 128},
  {"128:_mm_cmpgt_epi32(_mm_srli_epi32(x, 31), _mm_srli_epi32(y, 31))", f165, 0, 128},
  {"128:_mm_cmpgt_epi32(x, _mm_srli_epi32(x, 31))", f166, 0, 128},
  {"128:_mm_cmpgt_epi32(_mm_srli_epi32(x, 31), x)", f167, 0, 128},
  {"128:_mm_srli_epi32(_mm_sign_epi32(x, y), 31)", f168, 0, 128},
  {"128:_mm_sign_epi32(_mm_srli_epi32(x, 31), y)", f169, 0, 128},
  {"128:_mm_sign_epi32(x, _mm_srli_epi32(y, 31))", f170, 0, 128},
  {"128:_mm_sign_epi32(_mm_srli_epi32(x, 31), _mm_srli_epi32(y, 31))", f171, 0, 128},
  {"128:_mm_sign_epi32(x, _mm_srli_epi32(x, 31))", f172, 0, 128},
  {"128:_mm_sign_epi32(_mm_srli_epi32(x, 31), x)", f173, 0, 128},
  {"128:_mm_srli_epi32(_mm_packs_epi32(x, y), 31)", f174, 0, 128},
  {"128:_mm_packs_epi32(_mm_srli_epi32(x, 31), y)", f175, 0, 128},
  {"128:_mm_packs_epi32(x, _mm_srli_epi32(y, 31))", f176, 0, 128},
  {"128:_mm_packs_epi32(_mm_srli_epi32(x, 31), _mm_srli_epi32(y, 31))", f177, 0, 128},
  {"128:_mm_packs_epi32(x, _mm_srli_epi32(x, 31))", f178, 0, 128},
  {"128:_mm_packs_epi32(_mm_srli_epi32(x, 31), x)", f179, 0, 128},
  {"128:_mm_srli_epi32(_mm_packus_epi32(x, y), 31)", f180, 0, 128},
  {"128:_mm_packus_epi32(_mm_srli_epi32(x, 31), y)", f181, 0, 128},
  {"128:_mm_packus_epi32(x, _mm_srli_epi32(y, 31))", f182, 0, 128},
  {"128:_mm_packus_epi32(_mm_srli_epi32(x, 31), _mm_srli_epi32(y, 31))", f183, 0, 128},
  {"128:_mm_packus_epi32(x, _mm_srli_epi32(x, 31))", f184, 0, 128},
  {"128:_mm_packus_epi32(_mm_srli_epi32(x, 31), x)", f185, 0, 128},
  {"128:_mm_srli_epi32(_mm_hadd_epi32(x, y), 31)", f186, 0, 128},
  {"128:_mm_hadd_epi32(_mm_srli_epi32(x, 31), y)", f187, 0, 128},
  {"128:_mm_hadd_epi32(x, _mm_srli_epi32(y, 31))", f188, 0, 128},
  {"128:_mm_hadd_epi32(_mm_srli_epi32(x, 31), _mm_srli_epi32(y, 31))", f189, 0, 128},
  {"128:_mm_hadd_epi32(x, _mm_srli_epi32(x, 31))", f190, 0, 128},
  {"128:_mm_hadd_epi32(_mm_srli_epi32(x, 31), x)", f191, 0, 128},
  {"128:_mm_srli_epi32(_mm_hsub_epi32(x, y), 31)", f192, 0, 128},
  {"128:_mm_hsub_epi32(_mm_srli_epi32(x, 31), y)", f193, 0, 128},
  {"128:_mm_hsub_epi32(x, _mm_srli_epi32(y, 31))", f194, 0, 128},
  {"128:_mm_hsub_epi32(_mm_srli_epi32(x, 31), _mm_srli_epi32(y, 31))", f195, 0, 128},
  {"128:_mm_hsub_epi32(x, _mm_srli_epi32(x, 31))", f196, 0, 128},
  {"128:_mm_hsub_epi32(_mm_srli_epi32(x, 31), x)", f197, 0, 128},
  {"128:_mm_srli_epi32(_mm_mul_epi32(x, y), 31)", f198, 0, 128},
  {"128:_mm_mul_epi32(_mm_srli_epi32(x, 31), y)", f199, 0, 128},
  {"128:_mm_mul_epi32(x, _mm_srli_epi32(y, 31))", f200, 0, 128},
  {"128:_mm_mul_epi32(_mm_srli_epi32(x, 31), _mm_srli_epi32(y, 31))", f201, 0, 128},
  {"128:_mm_mul_epi32(x, _mm_srli_epi32(x, 31))", f202, 0, 128},
  {"128:_mm_mul_epi32(_mm_srli_epi32(x, 31), x)", f203, 0, 128},
  {"128:_mm_srli_epi32(_mm_mul_epu32(x, y), 31)", f204, 0, 128},
  {"128:_mm_mul_epu32(_mm_srli_epi32(x, 31), y)", f205, 0, 128},
  {"128:_mm_mul_epu32(x, _mm_srli_epi32(y, 31))", f206, 0, 128},
  {"128:_mm_mul_epu32(_mm_srli_epi32(x, 31), _mm_srli_epi32(y, 31))", f207, 0, 128},
  {"128:_mm_mul_epu32(x, _mm_srli_epi32(x, 31))", f208, 0, 128},
  {"128:_mm_mul_epu32(_mm_srli_epi32(x, 31), x)", f209, 0, 128},
  {"128:_mm_srli_epi32(_mm_unpacklo_epi32(x, y), 31)", f210, 0, 128},
  {"128:_mm_unpacklo_epi32(_mm_srli_epi32(x, 31), y)", f211, 0, 128},
  {"128:_mm_unpacklo_epi32(x, _mm_srli_epi32(y, 31))", f212, 0, 128},
  {"128:_mm_unpacklo_epi32(_mm_srli_epi32(x, 31), _mm_srli_epi32(y, 31))", f213, 0, 128},
  {"128:_mm_unpacklo_epi32(x, _mm_srli_epi32(x, 31))", f214, 0, 128},
  {"128:_mm_unpacklo_epi32(_mm_srli_epi32(x, 31), x)", f215, 0, 128},
  {"128:_mm_srli_epi32(_mm_unpackhi_epi32(x, y), 31)", f216, 0, 128},
  {"128:_mm_unpackhi_epi32(_mm_srli_epi32(x, 31), y)", f217, 0, 128},
  {"128:_mm_unpackhi_epi32(x, _mm_srli_epi32(y, 31))", f218, 0, 128},
  {"128:_mm_unpackhi_epi32(_mm_srli_epi32(x, 31), _mm_srli_epi32(y, 31))", f219, 0, 128},
  {"128:_mm_unpackhi_epi32(x, _mm_srli_epi32(x, 31))", f220, 0, 128},
  {"128:_mm_unpackhi_epi32(_mm_srli_epi32(x, 31), x)", f221, 0, 128},
  {"128:_mm_srli_epi32(_mm_blendv_epi8(x, y, _mm_cmpgt_epi32(x, y)), 31)", f222, 0, 128},
  {"128:_mm_blendv_epi8(_mm_srli_epi32(x, 31), y, _mm_cmpgt_epi32(_mm_srli_epi32(x, 31), y))", f223, 0, 128},
  {"128:_mm_blendv_epi8(x, _mm_srli_epi32(y, 31), _mm_cmpgt_epi32(x, _mm_srli_epi32(y, 31)))", f224, 0, 128},
  {"128:_mm_blendv_epi8(_mm_srli_epi32(x, 31), _mm_srli_epi32(y, 31), _mm_cmpgt_epi32(_mm_srli_epi32(x, 31), _mm_srli_epi32(y, 31)))", f225, 0, 128},
  {"128:_mm_blendv_epi8(x, _mm_srli_epi32(x, 31), _mm_cmpgt_epi32(x, _mm_srli_epi32(x, 31)))", f226, 0, 128},
  {"128:_mm_blendv_epi8(_mm_srli_epi32(x, 31), x, _mm_cmpgt_epi32(_mm_srli_epi32(x, 31), x))", f227, 0, 128},
  {"128:_mm_srli_epi32(_mm_blendv_epi8(y, x, _mm_cmpgt_epi32(x, y)), 31)", f228, 0, 128},
  {"128:_mm_blendv_epi8(y, _mm_srli_epi32(x, 31), _mm_cmpgt_epi32(_mm_srli_epi32(x, 31), y))", f229, 0, 128},
  {"128:_mm_blendv_epi8(_mm_srli_epi32(y, 31), x, _mm_cmpgt_epi32(x, _mm_srli_epi32(y, 31)))", f230, 0, 128},
  {"128:_mm_blendv_epi8(_mm_srli_epi32(y, 31), _mm_srli_epi32(x, 31), _mm_cmpgt_epi32(_mm_srli_epi32(x, 31), _mm_srli_epi32(y, 31)))", f231, 0, 128},
  {"128:_mm_blendv_epi8(_mm_srli_epi32(x, 31), x, _mm_cmpgt_epi32(x, _mm_srli_epi32(x, 31)))", f232, 0, 128},
  {"128:_mm_blendv_epi8(x, _mm_srli_epi32(x, 31), _mm_cmpgt_epi32(_mm_srli_epi32(x, 31), x))", f233, 0, 128},
  {"128:_mm_srli_epi32(_mm_or_si128(_mm_and_si128(_mm_cmpgt_epi32(x, y), x), _mm_andnot_si128(_mm_cmpgt_epi32(x, y), y)), 31)", f234, 0, 128},
  {"128:_mm_or_si128(_mm_and_si128(_mm_cmpgt_epi32(_mm_srli_epi32(x, 31), y), _mm_srli_epi32(x, 31)), _mm_andnot_si128(_mm_cmpgt_epi32(_mm_srli_epi32(x, 31), y), y))", f235, 0, 128},
  {"128:_mm_or_si128(_mm_and_si128(_mm_cmpgt_epi32(x, _mm_srli_epi32(y, 31)), x), _mm_andnot_si128(_mm_cmpgt_epi32(x, _mm_srli_epi32(y, 31)), _mm_srli_epi32(y, 31)))", f236, 0, 128},
  {"128:_mm_or_si128(_mm_and_si128(_mm_cmpgt_epi32(_mm_srli_epi32(x, 31), _mm_srli_epi32(y, 31)), _mm_srli_epi32(x, 31)), _mm_andnot_si128(_mm_cmpgt_epi32(_mm_srli_epi32(x, 31), _mm_srli_epi32(y, 31)), _mm_srli_epi32(y, 31)))", f237, 0, 128},
  {"128:_mm_or_si128(_mm_and_si128(_mm_cmpgt_epi32(x, _mm_srli_epi32(x, 31)), x), _mm_andnot_si128(_mm_cmpgt_epi32(x, _mm_srli_epi32(x, 31)), _mm_srli_epi32(x, 31)))", f238, 0, 128},
  {"128:_mm_or_si128(_mm_and_si128(_mm_cmpgt_epi32(_mm_srli_epi32(x, 31), x), _mm_srli_epi32(x, 31)), _mm_andnot_si128(_mm_cmpgt_epi32(_mm_srli_epi32(x, 31), x), x))", f239, 0, 128},
  {"128:_mm_srli_epi32(_mm_blendv_epi8(x, y, _mm_cmpeq_epi32(x, y)), 31)", f240, 0, 128},
  {"128:_mm_blendv_epi8(_mm_srli_epi32(x, 31), y, _mm_cmpeq_epi32(_mm_srli_epi32(x, 31), y))", f241, 0, 128},
  {"128:_mm_blendv_epi8(x, _mm_srli_epi32(y, 31), _mm_cmpeq_epi32(x, _mm_srli_epi32(y, 31)))", f242, 0, 128},
  {"128:_mm_blendv_epi8(_mm_srli_epi32(x, 31), _mm_srli_epi32(y, 31), _mm_cmpeq_epi32(_mm_srli_epi32(x, 31), _mm_srli_epi32(y, 31)))", f243, 0, 128},
  {"128:_mm_blendv_epi8(x, _mm_srli_epi32(x, 31), _mm_cmpeq_epi32(x, _mm_srli_epi32(x, 31)))", f244, 0, 128},
  {"128:_mm_blendv_epi8(_mm_srli_epi32(x, 31), x, _mm_cmpeq_epi32(_mm_srli_epi32(x, 31), x))", f245, 0, 128},
  {"128:_mm_srli_epi32(_mm_blendv_epi8(y, x, _mm_cmpeq_epi32(x, y)), 31)", f246, 0, 128},
  {"128:_mm_blendv_epi8(y, _mm_srli_epi32(x, 31), _mm_cmpeq_epi32(_mm_srli_epi32(x, 31), y))", f247, 0, 128},
  {"128:_mm_blendv_epi8(_mm_srli_epi32(y, 31), x, _mm_cmpeq_epi32(x, _mm_srli_epi32(y, 31)))", f248, 0, 128},
  {"128:_mm_blendv_epi8(_mm_srli_epi32(y, 31), _mm_srli_epi32(x, 31), _mm_cmpeq_epi32(_mm_srli_epi32(x, 31), _mm_srli_epi32(y, 31)))", f249, 0, 128},
  {"128:_mm_blendv_epi8(_mm_srli_epi32(x, 31), x, _mm_cmpeq_epi32(x, _mm_srli_epi32(x, 31)))", f250, 0, 128},
  {"128:_mm_blendv_epi8(x, _mm_srli_epi32(x, 31), _mm_cmpeq_epi32(_mm_srli_epi32(x, 31), x))", f251, 0, 128},
  {"128:_mm_srli_epi32(_mm_or_si128(_mm_and_si128(_mm_cmpeq_epi32(x, y), x), _mm_andnot_si128(_mm_cmpeq_epi32(x, y), y)), 31)", f252, 0, 128},
  {"128:_mm_or_si128(_mm_and_si128(_mm_cmpeq_epi32(_mm_srli_epi32(x, 31), y), _mm_srli_epi32(x, 31)), _mm_andnot_si128(_mm_cmpeq_epi32(_mm_srli_epi32(x, 31), y), y))", f253, 0, 128},
  {"128:_mm_or_si128(_mm_and_si128(_mm_cmpeq_epi32(x, _mm_srli_epi32(y, 31)), x), _mm_andnot_si128(_mm_cmpeq_epi32(x, _mm_srli_epi32(y, 31)), _mm_srli_epi32(y, 31)))", f254, 0, 128},
  {"128:_mm_or_si128(_mm_and_si128(_mm_cmpeq_epi32(_mm_srli_epi32(x, 31), _mm_srli_epi32(y, 31)), _mm_srli_epi32(x, 31)), _mm_andnot_si128(_mm_cmpeq_epi32(_mm_srli_epi32(x, 31), _mm_srli_epi32(y, 31)), _mm_srli_epi32(y, 31)))", f255, 0, 128},
  {"128:_mm_or_si128(_mm_and_si128(_mm_cmpeq_epi32(x, _mm_srli_epi32(x, 31)), x), _mm_andnot_si128(_mm_cmpeq_epi32(x, _mm_srli_epi32(x, 31)), _mm_srli_epi32(x, 31)))", f256, 0, 128},
  {"128:_mm_or_si128(_mm_and_si128(_mm_cmpeq_epi32(_mm_srli_epi32(x, 31), x), _mm_srli_epi32(x, 31)), _mm_andnot_si128(_mm_cmpeq_epi32(_mm_srli_epi32(x, 31), x), x))", f257, 0, 128},
  {"128:_mm_srli_epi32(_mm_mullo_epi32(x, y), 31)", f258, 0, 128},
  {"128:_mm_mullo_epi32(_mm_srli_epi32(x, 31), y)", f259, 0, 128},
  {"128:_mm_mullo_epi32(x, _mm_srli_epi32(y, 31))", f260, 0, 128},
  {"128:_mm_mullo_epi32(_mm_srli_epi32(x, 31), _mm_srli_epi32(y, 31))", f261, 0, 128},
  {"128:_mm_mullo_epi32(x, _mm_srli_epi32(x, 31))", f262, 0, 128},
  {"128:_mm_mullo_epi32(_mm_srli_epi32(x, 31), x)", f263, 0, 128},
  {"128:_mm_srli_epi32(_mm_sllv_epi32(x, y), 31)", f264, 0, 128},
  {"128:_mm_sllv_epi32(_mm_srli_epi32(x, 31), y)", f265, 0, 128},
  {"128:_mm_sllv_epi32(x, _mm_srli_epi32(y, 31))", f266, 0, 128},
  {"128:_mm_sllv_epi32(_mm_srli_epi32(x, 31), _mm_srli_epi32(y, 31))", f267, 0, 128},
  {"128:_mm_sllv_epi32(x, _mm_srli_epi32(x, 31))", f268, 0, 128},
  {"128:_mm_sllv_epi32(_mm_srli_epi32(x, 31), x)", f269, 0, 128},
  {"128:_mm_srli_epi32(_mm_srlv_epi32(x, y), 31)", f270, 0, 128},
  {"128:_mm_srlv_epi32(_mm_srli_epi32(x, 31), y)", f271, 0, 128},
  {"128:_mm_srlv_epi32(x, _mm_srli_epi32(y, 31))", f272, 0, 128},
  {"128:_mm_srlv_epi32(_mm_srli_epi32(x, 31), _mm_srli_epi32(y, 31))", f273, 0, 128},
  {"128:_mm_srlv_epi32(x, _mm_srli_epi32(x, 31))", f274, 0, 128},
  {"128:_mm_srlv_epi32(_mm_srli_epi32(x, 31), x)", f275, 0, 128},
  {"128:_mm_srli_epi32(_mm_srav_epi32(x, y), 31)", f276, 0, 128},
  {"128:_mm_srav_epi32(_mm_srli_epi32(x, 31), y)", f277, 0, 128},
  {"128:_mm_srav_epi32(x, _mm_srli_epi32(y, 31))", f278, 0, 128},
  {"128:_mm_srav_epi32(_mm_srli_epi32(x, 31), _mm_srli_epi32(y, 31))", f279, 0, 128},
  {"128:_mm_srav_epi32(x, _mm_srli_epi32(x, 31))", f280, 0, 128},
  {"128:_mm_srav_epi32(_mm_srli_epi32(x, 31), x)", f281, 0, 128},
  {"128:_mm_srai_epi32(_mm_add_epi32(x, y), 31)", f282, 0, 128},
  {"128:_mm_add_epi32(_mm_srai_epi32(x, 31), y)", f283, 0, 128},
  {"128:_mm_add_epi32(x, _mm_srai_epi32(y, 31))", f284, 0, 128},
  {"128:_mm_add_epi32(_mm_srai_epi32(x, 31), _mm_srai_epi32(y, 31))", f285, 0, 128},
  {"128:_mm_add_epi32(x, _mm_srai_epi32(x, 31))", f286, 0, 128},
  {"128:_mm_add_epi32(_mm_srai_epi32(x, 31), x)", f287, 0, 128},
  {"128:_mm_srai_epi32(_mm_sub_epi32(x, y), 31)", f288, 0, 128},
  {"128:_mm_sub_epi32(_mm_srai_epi32(x, 31), y)", f289, 0, 128},
  {"128:_mm_sub_epi32(x, _mm_srai_epi32(y, 31))", f290, 0, 128},
  {"128:_mm_sub_epi32(_mm_srai_epi32(x, 31), _mm_srai_epi32(y, 31))", f291, 0, 128},
  {"128:_mm_sub_epi32(x, _mm_srai_epi32(x, 31))", f292, 0, 128},
  {"128:_mm_sub_epi32(_mm_srai_epi32(x, 31), x)", f293, 0, 128},
  {"128:_mm_srai_epi32(_mm_min_epi32(x, y), 31)", f294, 0, 128},
  {"128:_mm_min_epi32(_mm_srai_epi32(x, 31), y)", f295, 0, 128},
  {"128:_mm_min_epi32(x, _mm_srai_epi32(y, 31))", f296, 0, 128},
  {"128:_mm_min_epi32(_mm_srai_epi32(x, 31), _mm_srai_epi32(y, 31))", f297, 0, 128},
  {"128:_mm_min_epi32(x, _mm_srai_epi32(x, 31))", f298, 0, 128},
  {"128:_mm_min_epi32(_mm_srai_epi32(x, 31), x)", f299, 0, 128},
  {"128:_mm_srai_epi32(_mm_max_epi32(x, y), 31)", f300, 0, 128},
  {"128:_mm_max_epi32(_mm_srai_epi32(x, 31), y)", f301, 0, 128},
  {"128:_mm_max_epi32(x, _mm_srai_epi32(y, 31))", f302, 0, 128},
  {"128:_mm_max_epi32(_mm_srai_epi32(x, 31), _mm_srai_epi32(y, 31))", f303, 0, 128},
  {"128:_mm_max_epi32(x, _mm_srai_epi32(x, 31))", f304, 0, 128},
  {"128:_mm_max_epi32(_mm_srai_epi32(x, 31), x)", f305, 0, 128},
  {"128:_mm_srai_epi32(_mm_min_epu32(x, y), 31)", f306, 0, 128},
  {"128:_mm_min_epu32(_mm_srai_epi32(x, 31), y)", f307, 0, 128},
  {"128:_mm_min_epu32(x, _mm_srai_epi32(y, 31))", f308, 0, 128},
  {"128:_mm_min_epu32(_mm_srai_epi32(x, 31), _mm_srai_epi32(y, 31))", f309, 0, 128},
  {"128:_mm_min_epu32(x, _mm_srai_epi32(x, 31))", f310, 0, 128},
  {"128:_mm_min_epu32(_mm_srai_epi32(x, 31), x)", f311, 0, 128},
  {"128:_mm_srai_epi32(_mm_max_epu32(x, y), 31)", f312, 0, 128},
  {"128:_mm_max_epu32(_mm_srai_epi32(x, 31), y)", f313, 0, 128},
  {"128:_mm_max_epu32(x, _mm_srai_epi32(y, 31))", f314, 0, 128},
  {"128:_mm_max_epu32(_mm_srai_epi32(x, 31), _mm_srai_epi32(y, 31))", f315, 0, 128},
  {"128:_mm_max_epu32(x, _mm_srai_epi32(x, 31))", f316, 0, 128},
  {"128:_mm_max_epu32(_mm_srai_epi32(x, 31), x)", f317, 0, 128},
  {"128:_mm_srai_epi32(_mm_and_si128(x, y), 31)", f318, 0, 128},
  {"128:_mm_and_si128(_mm_srai_epi32(x, 31), y)", f319, 0, 128},
  {"128:_mm_and_si128(x, _mm_srai_epi32(y, 31))", f320, 0, 128},
  {"128:_mm_and_si128(_mm_srai_epi32(x, 31), _mm_srai_epi32(y, 31))", f321, 0, 128},
  {"128:_mm_and_si128(x, _mm_srai_epi32(x, 31))", f322, 0, 128},
  {"128:_mm_and_si128(_mm_srai_epi32(x, 31), x)", f323, 0, 128},
  {"128:_mm_srai_epi32(_mm_or_si128(x, y), 31)", f324, 0, 128},
  {"128:_mm_or_si128(_mm_srai_epi32(x, 31), y)", f325, 0, 128},
  {"128:_mm_or_si128(x, _mm_srai_epi32(y, 31))", f326, 0, 128},
  {"128:_mm_or_si128(_mm_srai_epi32(x, 31), _mm_srai_epi32(y, 31))", f327, 0, 128},
  {"128:_mm_or_si128(x, _mm_srai_epi32(x, 31))", f328, 0, 128},
  {"128:_mm_or_si128(_mm_srai_epi32(x, 31), x)", f329, 0, 128},
  {"128:_mm_srai_epi32(_mm_xor_si128(x, y), 31)", f330, 0, 128},
  {"128:_mm_xor_si128(_mm_srai_epi32(x, 31), y)", f331, 0, 128},
  {"128:_mm_xor_si128(x, _mm_srai_epi32(y, 31))", f332, 0, 128},
  {"128:_mm_xor_si128(_mm_srai_epi32(x, 31), _mm_srai_epi32(y, 31))", f333, 0, 128},
  {"128:_mm_xor_si128(x, _mm_srai_epi32(x, 31))", f334, 0, 128},
  {"128:_mm_xor_si128(_mm_srai_epi32(x, 31), x)", f335, 0, 128},
  {"128:_mm_srai_epi32(_mm_andnot_si128(x, y), 31)", f336, 0, 128},
  {"128:_mm_andnot_si128(_mm_srai_epi32(x, 31), y)", f337, 0, 128},
  {"128:_mm_andnot_si128(x, _mm_srai_epi32(y, 31))", f338, 0, 128},
  {"128:_mm_andnot_si128(_mm_srai_epi32(x, 31), _mm_srai_epi32(y, 31))", f339, 0, 128},
  {"128:_mm_andnot_si128(x, _mm_srai_epi32(x, 31))", f340, 0, 128},
  {"128:_mm_andnot_si128(_mm_srai_epi32(x, 31), x)", f341, 0, 128},
  {"128:_mm_srai_epi32(_mm_cmpeq_epi32(x, y), 31)", f342, 0, 128},
  {"128:_mm_cmpeq_epi32(_mm_srai_epi32(x, 31), y)", f343, 0, 128},
  {"128:_mm_cmpeq_epi32(x, _mm_srai_epi32(y, 31))", f344, 0, 128},
  {"128:_mm_cmpeq_epi32(_mm_srai_epi32(x, 31), _mm_srai_epi32(y, 31))", f345, 0, 128},
  {"128:_mm_cmpeq_epi32(x, _mm_srai_epi32(x, 31))", f346, 0, 128},
  {"128:_mm_cmpeq_epi32(_mm_srai_epi32(x, 31), x)", f347, 0, 128},
  {"128:_mm_srai_epi32(_mm_cmpgt_epi32(x, y), 31)", f348, 0, 128},
  {"128:_mm_cmpgt_epi32(_mm_srai_epi32(x, 31), y)", f349, 0, 128},
  {"128:_mm_cmpgt_epi32(x, _mm_srai_epi32(y, 31))", f350, 0, 128},
  {"128:_mm_cmpgt_epi32(_mm_srai_epi32(x, 31), _mm_srai_epi32(y, 31))", f351, 0, 128},
  {"128:_mm_cmpgt_epi32(x, _mm_srai_epi32(x, 31))", f352, 0, 128},
  {"128:_mm_cmpgt_epi32(_mm_srai_epi32(x, 31), x)", f353, 0, 128},
  {"128:_mm_srai_epi32(_mm_sign_epi32(x, y), 31)", f354, 0, 128},
  {"128:_mm_sign_epi32(_mm_srai_epi32(x, 31), y)", f355, 0, 128},
  {"128:_mm_sign_epi32(x, _mm_srai_epi32(y, 31))", f356, 0, 128},
  {"128:_mm_sign_epi32(_mm_srai_epi32(x, 31), _mm_srai_epi32(y, 31))", f357, 0, 128},
  {"128:_mm_sign_epi32(x, _mm_srai_epi32(x, 31))", f358, 0, 128},
  {"128:_mm_sign_epi32(_mm_srai_epi32(x, 31), x)", f359, 0, 128},
  {"128:_mm_srai_epi32(_mm_packs_epi32(x, y), 31)", f360, 0, 128},
  {"128:_mm_packs_epi32(_mm_srai_epi32(x, 31), y)", f361, 0, 128},
  {"128:_mm_packs_epi32(x, _mm_srai_epi32(y, 31))", f362, 0, 128},
  {"128:_mm_packs_epi32(_mm_srai_epi32(x, 31), _mm_srai_epi32(y, 31))", f363, 0, 128},
  {"128:_mm_packs_epi32(x, _mm_srai_epi32(x, 31))", f364, 0, 128},
  {"128:_mm_packs_epi32(_mm_srai_epi32(x, 31), x)", f365, 0, 128},
  {"128:_mm_srai_epi32(_mm_packus_epi32(x, y), 31)", f366, 0, 128},
  {"128:_mm_packus_epi32(_mm_srai_epi32(x, 31), y)", f367, 0, 128},
  {"128:_mm_packus_epi32(x, _mm_srai_epi32(y, 31))", f368, 0, 128},
  {"128:_mm_packus_epi32(_mm_srai_epi32(x, 31), _mm_srai_epi32(y, 31))", f369, 0, 128},
  {"128:_mm_packus_epi32(x, _mm_srai_epi32(x, 31))", f370, 0, 128},
  {"128:_mm_packus_epi32(_mm_srai_epi32(x, 31), x)", f371, 0, 128},
  {"128:_mm_srai_epi32(_mm_hadd_epi32(x, y), 31)", f372, 0, 128},
  {"128:_mm_hadd_epi32(_mm_srai_epi32(x, 31), y)", f373, 0, 128},
  {"128:_mm_hadd_epi32(x, _mm_srai_epi32(y, 31))", f374, 0, 128},
  {"128:_mm_hadd_epi32(_mm_srai_epi32(x, 31), _mm_srai_epi32(y, 31))", f375, 0, 128},
  {"128:_mm_hadd_epi32(x, _mm_srai_epi32(x, 31))", f376, 0, 128},
  {"128:_mm_hadd_epi32(_mm_srai_epi32(x, 31), x)", f377, 0, 128},
  {"128:_mm_srai_epi32(_mm_hsub_epi32(x, y), 31)", f378, 0, 128},
  {"128:_mm_hsub_epi32(_mm_srai_epi32(x, 31), y)", f379, 0, 128},
  {"128:_mm_hsub_epi32(x, _mm_srai_epi32(y, 31))", f380, 0, 128},
  {"128:_mm_hsub_epi32(_mm_srai_epi32(x, 31), _mm_srai_epi32(y, 31))", f381, 0, 128},
  {"128:_mm_hsub_epi32(x, _mm_srai_epi32(x, 31))", f382, 0, 128},
  {"128:_mm_hsub_epi32(_mm_srai_epi32(x, 31), x)", f383, 0, 128},
  {"128:_mm_srai_epi32(_mm_mul_epi32(x, y), 31)", f384, 0, 128},
  {"128:_mm_mul_epi32(_mm_srai_epi32(x, 31), y)", f385, 0, 128},
  {"128:_mm_mul_epi32(x, _mm_srai_epi32(y, 31))", f386, 0, 128},
  {"128:_mm_mul_epi32(_mm_srai_epi32(x, 31), _mm_srai_epi32(y, 31))", f387, 0, 128},
  {"128:_mm_mul_epi32(x, _mm_srai_epi32(x, 31))", f388, 0, 128},
  {"128:_mm_mul_epi32(_mm_srai_epi32(x, 31), x)", f389, 0, 128},
  {"128:_mm_srai_epi32(_mm_mul_epu32(x, y), 31)", f390, 0, 128},
  {"128:_mm_mul_epu32(_mm_srai_epi32(x, 31), y)", f391, 0, 128},
  {"128:_mm_mul_epu32(x, _mm_srai_epi32(y, 31))", f392, 0, 128},
  {"128:_mm_mul_epu32(_mm_srai_epi32(x, 31), _mm_srai_epi32(y, 31))", f393, 0, 128},
  {"128:_mm_mul_epu32(x, _mm_srai_epi32(x, 31))", f394, 0, 128},
  {"128:_mm_mul_epu32(_mm_srai_epi32(x, 31), x)", f395, 0, 128},
  {"128:_mm_srai_epi32(_mm_unpacklo_epi32(x, y), 31)", f396, 0, 128},
  {"128:_mm_unpacklo_epi32(_mm_srai_epi32(x, 31), y)", f397, 0, 128},
  {"128:_mm_unpacklo_epi32(x, _mm_srai_epi32(y, 31))", f398, 0, 128},
  {"128:_mm_unpacklo_epi32(_mm_srai_epi32(x, 31), _mm_srai_epi32(y, 31))", f399, 0, 128},
  {"128:_mm_unpacklo_epi32(x, _mm_srai_epi32(x, 31))", f400, 0, 128},
  {"128:_mm_unpacklo_epi32(_mm_srai_epi32(x, 31), x)", f401, 0, 128},
  {"128:_mm_srai_epi32(_mm_unpackhi_epi32(x, y), 31)", f402, 0, 128},
  {"128:_mm_unpackhi_epi32(_mm_srai_epi32(x, 31), y)", f403, 0, 128},
  {"128:_mm_unpackhi_epi32(x, _mm_srai_epi32(y, 31))", f404, 0, 128},
  {"128:_mm_unpackhi_epi32(_mm_srai_epi32(x, 31), _mm_srai_epi32(y, 31))", f405, 0, 128},
  {"128:_mm_unpackhi_epi32(x, _mm_srai_epi32(x, 31))", f406, 0, 128},
  {"128:_mm_unpackhi_epi32(_mm_srai_epi32(x, 31), x)", f407, 0, 128},
  {"128:_mm_srai_epi32(_mm_blendv_epi8(x, y, _mm_cmpgt_epi32(x, y)), 31)", f408, 0, 128},
  {"128:_mm_blendv_epi8(_mm_srai_epi32(x, 31), y, _mm_cmpgt_epi32(_mm_srai_epi32(x, 31), y))", f409, 0, 128},
  {"128:_mm_blendv_epi8(x, _mm_srai_epi32(y, 31), _mm_cmpgt_epi32(x, _mm_srai_epi32(y, 31)))", f410, 0, 128},
  {"128:_mm_blendv_epi8(_mm_srai_epi32(x, 31), _mm_srai_epi32(y, 31), _mm_cmpgt_epi32(_mm_srai_epi32(x, 31), _mm_srai_epi32(y, 31)))", f411, 0, 128},
  {"128:_mm_blendv_epi8(x, _mm_srai_epi32(x, 31), _mm_cmpgt_epi32(x, _mm_srai_epi32(x, 31)))", f412, 0, 128},
  {"128:_mm_blendv_epi8(_mm_srai_epi32(x, 31), x, _mm_cmpgt_epi32(_mm_srai_epi32(x, 31), x))", f413, 0, 128},
  {"128:_mm_srai_epi32(_mm_blendv_epi8(y, x, _mm_cmpgt_epi32(x, y)), 31)", f414, 0, 128},
  {"128:_mm_blendv_epi8(y, _mm_srai_epi32(x, 31), _mm_cmpgt_epi32(_mm_srai_epi32(x, 31), y))", f415, 0, 128},
  {"128:_mm_blendv_epi8(_mm_srai_epi32(y, 31), x, _mm_cmpgt_epi32(x, _mm_srai_epi32(y, 31)))", f416, 0, 128},
  {"128:_mm_blendv_epi8(_mm_srai_epi32(y, 31), _mm_srai_epi32(x, 31), _mm_cmpgt_epi32(_mm_srai_epi32(x, 31), _mm_srai_epi32(y, 31)))", f417, 0, 128},
  {"128:_mm_blendv_epi8(_mm_srai_epi32(x, 31), x, _mm_cmpgt_epi32(x, _mm_srai_epi32(x, 31)))", f418, 0, 128},
  {"128:_mm_blendv_epi8(x, _mm_srai_epi32(x, 31), _mm_cmpgt_epi32(_mm_srai_epi32(x, 31), x))", f419, 0, 128},
  {"128:_mm_srai_epi32(_mm_or_si128(_mm_and_si128(_mm_cmpgt_epi32(x, y), x), _mm_andnot_si128(_mm_cmpgt_epi32(x, y), y)), 31)", f420, 0, 128},
  {"128:_mm_or_si128(_mm_and_si128(_mm_cmpgt_epi32(_mm_srai_epi32(x, 31), y), _mm_srai_epi32(x, 31)), _mm_andnot_si128(_mm_cmpgt_epi32(_mm_srai_epi32(x, 31), y), y))", f421, 0, 128},
  {"128:_mm_or_si128(_mm_and_si128(_mm_cmpgt_epi32(x, _mm_srai_epi32(y, 31)), x), _mm_andnot_si128(_mm_cmpgt_epi32(x, _mm_srai_epi32(y, 31)), _mm_srai_epi32(y, 31)))", f422, 0, 128},
  {"128:_mm_or_si128(_mm_and_si128(_mm_cmpgt_epi32(_mm_srai_epi32(x, 31), _mm_srai_epi32(y, 31)), _mm_srai_epi32(x, 31)), _mm_andnot_si128(_mm_cmpgt_epi32(_mm_srai_epi32(x, 31), _mm_srai_epi32(y, 31)), _mm_srai_epi32(y, 31)))", f423, 0, 128},
  {"128:_mm_or_si128(_mm_and_si128(_mm_cmpgt_epi32(x, _mm_srai_epi32(x, 31)), x), _mm_andnot_si128(_mm_cmpgt_epi32(x, _mm_srai_epi32(x, 31)), _mm_srai_epi32(x, 31)))", f424, 0, 128},
  {"128:_mm_or_si128(_mm_and_si128(_mm_cmpgt_epi32(_mm_srai_epi32(x, 31), x), _mm_srai_epi32(x, 31)), _mm_andnot_si128(_mm_cmpgt_epi32(_mm_srai_epi32(x, 31), x), x))", f425, 0, 128},
  {"128:_mm_srai_epi32(_mm_blendv_epi8(x, y, _mm_cmpeq_epi32(x, y)), 31)", f426, 0, 128},
  {"128:_mm_blendv_epi8(_mm_srai_epi32(x, 31), y, _mm_cmpeq_epi32(_mm_srai_epi32(x, 31), y))", f427, 0, 128},
  {"128:_mm_blendv_epi8(x, _mm_srai_epi32(y, 31), _mm_cmpeq_epi32(x, _mm_srai_epi32(y, 31)))", f428, 0, 128},
  {"128:_mm_blendv_epi8(_mm_srai_epi32(x, 31), _mm_srai_epi32(y, 31), _mm_cmpeq_epi32(_mm_srai_epi32(x, 31), _mm_srai_epi32(y, 31)))", f429, 0, 128},
  {"128:_mm_blendv_epi8(x, _mm_srai_epi32(x, 31), _mm_cmpeq_epi32(x, _mm_srai_epi32(x, 31)))", f430, 0, 128},
  {"128:_mm_blendv_epi8(_mm_srai_epi32(x, 31), x, _mm_cmpeq_epi32(_mm_srai_epi32(x, 31), x))", f431, 0, 128},
  {"128:_mm_srai_epi32(_mm_blendv_epi8(y, x, _mm_cmpeq_epi32(x, y)), 31)", f432, 0, 128},
  {"128:_mm_blendv_epi8(y, _mm_srai_epi32(x, 31), _mm_cmpeq_epi32(_mm_srai_epi32(x, 31), y))", f433, 0, 128},
  {"128:_mm_blendv_epi8(_mm_srai_epi32(y, 31), x, _mm_cmpeq_epi32(x, _mm_srai_epi32(y, 31)))", f434, 0, 128},
  {"128:_mm_blendv_epi8(_mm_srai_epi32(y, 31), _mm_srai_epi32(x, 31), _mm_cmpeq_epi32(_mm_srai_epi32(x, 31), _mm_srai_epi32(y, 31)))", f435, 0, 128},
  {"128:_mm_blendv_epi8(_mm_srai_epi32(x, 31), x, _mm_cmpeq_epi32(x, _mm_srai_epi32(x, 31)))", f436, 0, 128},
  {"128:_mm_blendv_epi8(x, _mm_srai_epi32(x, 31), _mm_cmpeq_epi32(_mm_srai_epi32(x, 31), x))", f437, 0, 128},
  {"128:_mm_srai_epi32(_mm_or_si128(_mm_and_si128(_mm_cmpeq_epi32(x, y), x), _mm_andnot_si128(_mm_cmpeq_epi32(x, y), y)), 31)", f438, 0, 128},
  {"128:_mm_or_si128(_mm_and_si128(_mm_cmpeq_epi32(_mm_srai_epi32(x, 31), y), _mm_srai_epi32(x, 31)), _mm_andnot_si128(_mm_cmpeq_epi32(_mm_srai_epi32(x, 31), y), y))", f439, 0, 128},
  {"128:_mm_or_si128(_mm_and_si128(_mm_cmpeq_epi32(x, _mm_srai_epi32(y, 31)), x), _mm_andnot_si128(_mm_cmpeq_epi32(x, _mm_srai_epi32(y, 31)), _mm_srai_epi32(y, 31)))", f440, 0, 128},
  {"128:_mm_or_si128(_mm_and_si128(_mm_cmpeq_epi32(_mm_srai_epi32(x, 31), _mm_srai_epi32(y, 31)), _mm_srai_epi32(x, 31)), _mm_andnot_si128(_mm_cmpeq_epi32(_mm_srai_epi32(x, 31), _mm_srai_epi32(y, 31)), _mm_srai_epi32(y, 31)))", f441, 0, 128},
  {"128:_mm_or_si128(_mm_and_si128(_mm_cmpeq_epi32(x, _mm_srai_epi32(x, 31)), x), _mm_andnot_si128(_mm_cmpeq_epi32(x, _mm_srai_epi32(x, 31)), _mm_srai_epi32(x, 31)))", f442, 0, 128},
  {"128:_mm_or_si128(_mm_and_si128(_mm_cmpeq_epi32(_mm_srai_epi32(x, 31), x), _mm_srai_epi32(x, 31)), _mm_andnot_si128(_mm_cmpeq_epi32(_mm_srai_epi32(x, 31), x), x))", f443, 0, 128},
  {"128:_mm_srai_epi32(_mm_mullo_epi32(x, y), 31)", f444, 0, 128},
  {"128:_mm_mullo_epi32(_mm_srai_epi32(x, 31), y)", f445, 0, 128},
  {"128:_mm_mullo_epi32(x, _mm_srai_epi32(y, 31))", f446, 0, 128},
  {"128:_mm_mullo_epi32(_mm_srai_epi32(x, 31), _mm_srai_epi32(y, 31))", f447, 0, 128},
  {"128:_mm_mullo_epi32(x, _mm_srai_epi32(x, 31))", f448, 0, 128},
  {"128:_mm_mullo_epi32(_mm_srai_epi32(x, 31), x)", f449, 0, 128},
  {"128:_mm_srai_epi32(_mm_sllv_epi32(x, y), 31)", f450, 0, 128},
  {"128:_mm_sllv_epi32(_mm_srai_epi32(x, 31), y)", f451, 0, 128},
  {"128:_mm_sllv_epi32(x, _mm_srai_epi32(y, 31))", f452, 0, 128},
  {"128:_mm_sllv_epi32(_mm_srai_epi32(x, 31), _mm_srai_epi32(y, 31))", f453, 0, 128},
  {"128:_mm_sllv_epi32(x, _mm_srai_epi32(x, 31))", f454, 0, 128},
  {"128:_mm_sllv_epi32(_mm_srai_epi32(x, 31), x)", f455, 0, 128},
  {"128:_mm_srai_epi32(_mm_srlv_epi32(x, y), 31)", f456, 0, 128},
  {"128:_mm_srlv_epi32(_mm_srai_epi32(x, 31), y)", f457, 0, 128},
  {"128:_mm_srlv_epi32(x, _mm_srai_epi32(y, 31))", f458, 0, 128},
  {"128:_mm_srlv_epi32(_mm_srai_epi32(x, 31), _mm_srai_epi32(y, 31))", f459, 0, 128},
  {"128:_mm_srlv_epi32(x, _mm_srai_epi32(x, 31))", f460, 0, 128},
  {"128:_mm_srlv_epi32(_mm_srai_epi32(x, 31), x)", f461, 0, 128},
  {"128:_mm_srai_epi32(_mm_srav_epi32(x, y), 31)", f462, 0, 128},
  {"128:_mm_srav_epi32(_mm_srai_epi32(x, 31), y)", f463, 0, 128},
  {"128:_mm_srav_epi32(x, _mm_srai_epi32(y, 31))", f464, 0, 128},
  {"128:_mm_srav_epi32(_mm_srai_epi32(x, 31), _mm_srai_epi32(y, 31))", f465, 0, 128},
  {"128:_mm_srav_epi32(x, _mm_srai_epi32(x, 31))", f466, 0, 128},
  {"128:_mm_srav_epi32(_mm_srai_epi32(x, 31), x)", f467, 0, 128},
  {"128:_mm_slli_epi64(_mm_add_epi64(x, y), 1)", f468, 0, 128},
  {"128:_mm_add_epi64(_mm_slli_epi64(x, 1), y)", f469, 0, 128},
  {"128:_mm_add_epi64(x, _mm_slli_epi64(y, 1))", f470, 0, 128},
  {"128:_mm_add_epi64(_mm_slli_epi64(x, 1), _mm_slli_epi64(y, 1))", f471, 0, 128},
  {"128:_mm_add_epi64(x, _mm_slli_epi64(x, 1))", f472, 0, 128},
  {"128:_mm_add_epi64(_mm_slli_epi64(x, 1), x)", f473, 0, 128},
  {"128:_mm_slli_epi64(_mm_sub_epi64(x, y), 1)", f474, 0, 128},
  {"128:_mm_sub_epi64(_mm_slli_epi64(x, 1), y)", f475, 0, 128},
  {"128:_mm_sub_epi64(x, _mm_slli_epi64(y, 1))", f476, 0, 128},
  {"128:_mm_sub_epi64(_mm_slli_epi64(x, 1), _mm_slli_epi64(y, 1))", f477, 0, 128},
  {"128:_mm_sub_epi64(x, _mm_slli_epi64(x, 1))", f478, 0, 128},
  {"128:_mm_sub_epi64(_mm_slli_epi64(x, 1), x)", f479, 0, 128},
  {"128:_mm_slli_epi64(_mm_and_si128(x, y), 1)", f480, 0, 128},
  {"128:_mm_and_si128(_mm_slli_epi64(x, 1), y)", f481, 0, 128},
  {"128:_mm_and_si128(x, _mm_slli_epi64(y, 1))", f482, 0, 128},
  {"128:_mm_and_si128(_mm_slli_epi64(x, 1), _mm_slli_epi64(y, 1))", f483, 0, 128},
  {"128:_mm_and_si128(x, _mm_slli_epi64(x, 1))", f484, 0, 128},
  {"128:_mm_and_si128(_mm_slli_epi64(x, 1), x)", f485, 0, 128},
  {"128:_mm_slli_epi64(_mm_or_si128(x, y), 1)", f486, 0, 128},
  {"128:_mm_or_si128(_mm_slli_epi64(x, 1), y)", f487, 0, 128},
  {"128:_mm_or_si128(x, _mm_slli_epi64(y, 1))", f488, 0, 128},
  {"128:_mm_or_si128(_mm_slli_epi64(x, 1), _mm_slli_epi64(y, 1))", f489, 0, 128},
  {"128:_mm_or_si128(x, _mm_slli_epi64(x, 1))", f490, 0, 128},
  {"128:_mm_or_si128(_mm_slli_epi64(x, 1), x)", f491, 0, 128},
  {"128:_mm_slli_epi64(_mm_xor_si128(x, y), 1)", f492, 0, 128},
  {"128:_mm_xor_si128(_mm_slli_epi64(x, 1), y)", f493, 0, 128},
  {"128:_mm_xor_si128(x, _mm_slli_epi64(y, 1))", f494, 0, 128},
  {"128:_mm_xor_si128(_mm_slli_epi64(x, 1), _mm_slli_epi64(y, 1))", f495, 0, 128},
  {"128:_mm_xor_si128(x, _mm_slli_epi64(x, 1))", f496, 0, 128},
  {"128:_mm_xor_si128(_mm_slli_epi64(x, 1), x)", f497, 0, 128},
  {"128:_mm_slli_epi64(_mm_andnot_si128(x, y), 1)", f498, 0, 128},
  {"128:_mm_andnot_si128(_mm_slli_epi64(x, 1), y)", f499, 0, 128},
  {"128:_mm_andnot_si128(x, _mm_slli_epi64(y, 1))", f500, 0, 128},
  {"128:_mm_andnot_si128(_mm_slli_epi64(x, 1), _mm_slli_epi64(y, 1))", f501, 0, 128},
  {"128:_mm_andnot_si128(x, _mm_slli_epi64(x, 1))", f502, 0, 128},
  {"128:_mm_andnot_si128(_mm_slli_epi64(x, 1), x)", f503, 0, 128},
  {"128:_mm_slli_epi64(_mm_cmpeq_epi64(x, y), 1)", f504, 0, 128},
  {"128:_mm_cmpeq_epi64(_mm_slli_epi64(x, 1), y)", f505, 0, 128},
  {"128:_mm_cmpeq_epi64(x, _mm_slli_epi64(y, 1))", f506, 0, 128},
  {"128:_mm_cmpeq_epi64(_mm_slli_epi64(x, 1), _mm_slli_epi64(y, 1))", f507, 0, 128},
  {"128:_mm_cmpeq_epi64(x, _mm_slli_epi64(x, 1))", f508, 0, 128},
  {"128:_mm_cmpeq_epi64(_mm_slli_epi64(x, 1), x)", f509, 0, 128},
  {"128:_mm_slli_epi64(_mm_cmpgt_epi64(x, y), 1)", f510, 0, 128},
  {"128:_mm_cmpgt_epi64(_mm_slli_epi64(x, 1), y)", f511, 0, 128},
  {"128:_mm_cmpgt_epi64(x, _mm_slli_epi64(y, 1))", f512, 0, 128},
  {"128:_mm_cmpgt_epi64(_mm_slli_epi64(x, 1), _mm_slli_epi64(y, 1))", f513, 0, 128},
  {"128:_mm_cmpgt_epi64(x, _mm_slli_epi64(x, 1))", f514, 0, 128},
  {"128:_mm_cmpgt_epi64(_mm_slli_epi64(x, 1), x)", f515, 0, 128},
  {"128:_mm_slli_epi64(_mm_unpacklo_epi64(x, y), 1)", f516, 0, 128},
  {"128:_mm_unpacklo_epi64(_mm_slli_epi64(x, 1), y)", f517, 0, 128},
  {"128:_mm_unpacklo_epi64(x, _mm_slli_epi64(y, 1))", f518, 0, 128},
  {"128:_mm_unpacklo_epi64(_mm_slli_epi64(x, 1), _mm_slli_epi64(y, 1))", f519, 0, 128},
  {"128:_mm_unpacklo_epi64(x, _mm_slli_epi64(x, 1))", f520, 0, 128},
  {"128:_mm_unpacklo_epi64(_mm_slli_epi64(x, 1), x)", f521, 0, 128},
  {"128:_mm_slli_epi64(_mm_unpackhi_epi64(x, y), 1)", f522, 0, 128},
  {"128:_mm_unpackhi_epi64(_mm_slli_epi64(x, 1), y)", f523, 0, 128},
  {"128:_mm_unpackhi_epi64(x, _mm_slli_epi64(y, 1))", f524, 0, 128},
  {"128:_mm_unpackhi_epi64(_mm_slli_epi64(x, 1), _mm_slli_epi64(y, 1))", f525, 0, 128},
  {"128:_mm_unpackhi_epi64(x, _mm_slli_epi64(x, 1))", f526, 0, 128},
  {"128:_mm_unpackhi_epi64(_mm_slli_epi64(x, 1), x)", f527, 0, 128},
  {"128:_mm_slli_epi64(_mm_blendv_epi8(x, y, _mm_cmpgt_epi64(x, y)), 1)", f528, 0, 128},
  {"128:_mm_blendv_epi8(_mm_slli_epi64(x, 1), y, _mm_cmpgt_epi64(_mm_slli_epi64(x, 1), y))", f529, 0, 128},
  {"128:_mm_blendv_epi8(x, _mm_slli_epi64(y, 1), _mm_cmpgt_epi64(x, _mm_slli_epi64(y, 1)))", f530, 0, 128},
  {"128:_mm_blendv_epi8(_mm_slli_epi64(x, 1), _mm_slli_epi64(y, 1), _mm_cmpgt_epi64(_mm_slli_epi64(x, 1), _mm_slli_epi64(y, 1)))", f531, 0, 128},
  {"128:_mm_blendv_epi8(x, _mm_slli_epi64(x, 1), _mm_cmpgt_epi64(x, _mm_slli_epi64(x, 1)))", f532, 0, 128},
  {"128:_mm_blendv_epi8(_mm_slli_epi64(x, 1), x, _mm_cmpgt_epi64(_mm_slli_epi64(x, 1), x))", f533, 0, 128},
  {"128:_mm_slli_epi64(_mm_blendv_epi8(y, x, _mm_cmpgt_epi64(x, y)), 1)", f534, 0, 128},
  {"128:_mm_blendv_epi8(y, _mm_slli_epi64(x, 1), _mm_cmpgt_epi64(_mm_slli_epi64(x, 1), y))", f535, 0, 128},
  {"128:_mm_blendv_epi8(_mm_slli_epi64(y, 1), x, _mm_cmpgt_epi64(x, _mm_slli_epi64(y, 1)))", f536, 0, 128},
  {"128:_mm_blendv_epi8(_mm_slli_epi64(y, 1), _mm_slli_epi64(x, 1), _mm_cmpgt_epi64(_mm_slli_epi64(x, 1), _mm_slli_epi64(y, 1)))", f537, 0, 128},
  {"128:_mm_blendv_epi8(_mm_slli_epi64(x, 1), x, _mm_cmpgt_epi64(x, _mm_slli_epi64(x, 1)))", f538, 0, 128},
  {"128:_mm_blendv_epi8(x, _mm_slli_epi64(x, 1), _mm_cmpgt_epi64(_mm_slli_epi64(x, 1), x))", f539, 0, 128},
  {"128:_mm_slli_epi64(_mm_or_si128(_mm_and_si128(_mm_cmpgt_epi64(x, y), x), _mm_andnot_si128(_mm_cmpgt_epi64(x, y), y)), 1)", f540, 0, 128},
  {"128:_mm_or_si128(_mm_and_si128(_mm_cmpgt_epi64(_mm_slli_epi64(x, 1), y), _mm_slli_epi64(x, 1)), _mm_andnot_si128(_mm_cmpgt_epi64(_mm_slli_epi64(x, 1), y), y))", f541, 0, 128},
  {"128:_mm_or_si128(_mm_and_si128(_mm_cmpgt_epi64(x, _mm_slli_epi64(y, 1)), x), _mm_andnot_si128(_mm_cmpgt_epi64(x, _mm_slli_epi64(y, 1)), _mm_slli_epi64(y, 1)))", f542, 0, 128},
  {"128:_mm_or_si128(_mm_and_si128(_mm_cmpgt_epi64(_mm_slli_epi64(x, 1), _mm_slli_epi64(y, 1)), _mm_slli_epi64(x, 1)), _mm_andnot_si128(_mm_cmpgt_epi64(_mm_slli_epi64(x, 1), _mm_slli_epi64(y, 1)), _mm_slli_epi64(y, 1)))", f543, 0, 128},
  {"128:_mm_or_si128(_mm_and_si128(_mm_cmpgt_epi64(x, _mm_slli_epi64(x, 1)), x), _mm_andnot_si128(_mm_cmpgt_epi64(x, _mm_slli_epi64(x, 1)), _mm_slli_epi64(x, 1)))", f544, 0, 128},
  {"128:_mm_or_si128(_mm_and_si128(_mm_cmpgt_epi64(_mm_slli_epi64(x, 1), x), _mm_slli_epi64(x, 1)), _mm_andnot_si128(_mm_cmpgt_epi64(_mm_slli_epi64(x, 1), x), x))", f545, 0, 128},
  {"128:_mm_slli_epi64(_mm_blendv_epi8(x, y, _mm_cmpeq_epi64(x, y)), 1)", f546, 0, 128},
  {"128:_mm_blendv_epi8(_mm_slli_epi64(x, 1), y, _mm_cmpeq_epi64(_mm_slli_epi64(x, 1), y))", f547, 0, 128},
  {"128:_mm_blendv_epi8(x, _mm_slli_epi64(y, 1), _mm_cmpeq_epi64(x, _mm_slli_epi64(y, 1)))", f548, 0, 128},
  {"128:_mm_blendv_epi8(_mm_slli_epi64(x, 1), _mm_slli_epi64(y, 1), _mm_cmpeq_epi64(_mm_slli_epi64(x, 1), _mm_slli_epi64(y, 1)))", f549, 0, 128},
  {"128:_mm_blendv_epi8(x, _mm_slli_epi64(x, 1), _mm_cmpeq_epi64(x, _mm_slli_epi64(x, 1)))", f550, 0, 128},
  {"128:_mm_blendv_epi8(_mm_slli_epi64(x, 1), x, _mm_cmpeq_epi64(_mm_slli_epi64(x, 1), x))", f551, 0, 128},
  {"128:_mm_slli_epi64(_mm_blendv_epi8(y, x, _mm_cmpeq_epi64(x, y)), 1)", f552, 0, 128},
  {"128:_mm_blendv_epi8(y, _mm_slli_epi64(x, 1), _mm_cmpeq_epi64(_mm_slli_epi64(x, 1), y))", f553, 0, 128},
  {"128:_mm_blendv_epi8(_mm_slli_epi64(y, 1), x, _mm_cmpeq_epi64(x, _mm_slli_epi64(y, 1)))", f554, 0, 128},
  {"128:_mm_blendv_epi8(_mm_slli_epi64(y, 1), _mm_slli_epi64(x, 1), _mm_cmpeq_epi64(_mm_slli_epi64(x, 1), _mm_slli_epi64(y, 1)))", f555, 0, 128},
  {"128:_mm_blendv_epi8(_mm_slli_epi64(x, 1), x, _mm_cmpeq_epi64(x, _mm_slli_epi64(x, 1)))", f556, 0, 128},
  {"128:_mm_blendv_epi8(x, _mm_slli_epi64(x, 1), _mm_cmpeq_epi64(_mm_slli_epi64(x, 1), x))", f557, 0, 128},
  {"128:_mm_slli_epi64(_mm_or_si128(_mm_and_si128(_mm_cmpeq_epi64(x, y), x), _mm_andnot_si128(_mm_cmpeq_epi64(x, y), y)), 1)", f558, 0, 128},
  {"128:_mm_or_si128(_mm_and_si128(_mm_cmpeq_epi64(_mm_slli_epi64(x, 1), y), _mm_slli_epi64(x, 1)), _mm_andnot_si128(_mm_cmpeq_epi64(_mm_slli_epi64(x, 1), y), y))", f559, 0, 128},
  {"128:_mm_or_si128(_mm_and_si128(_mm_cmpeq_epi64(x, _mm_slli_epi64(y, 1)), x), _mm_andnot_si128(_mm_cmpeq_epi64(x, _mm_slli_epi64(y, 1)), _mm_slli_epi64(y, 1)))", f560, 0, 128},
  {"128:_mm_or_si128(_mm_and_si128(_mm_cmpeq_epi64(_mm_slli_epi64(x, 1), _mm_slli_epi64(y, 1)), _mm_slli_epi64(x, 1)), _mm_andnot_si128(_mm_cmpeq_epi64(_mm_slli_epi64(x, 1), _mm_slli_epi64(y, 1)), _mm_slli_epi64(y, 1)))", f561, 0, 128},
  {"128:_mm_or_si128(_mm_and_si128(_mm_cmpeq_epi64(x, _mm_slli_epi64(x, 1)), x), _mm_andnot_si128(_mm_cmpeq_epi64(x, _mm_slli_epi64(x, 1)), _mm_slli_epi64(x, 1)))", f562, 0, 128},
  {"128:_mm_or_si128(_mm_and_si128(_mm_cmpeq_epi64(_mm_slli_epi64(x, 1), x), _mm_slli_epi64(x, 1)), _mm_andnot_si128(_mm_cmpeq_epi64(_mm_slli_epi64(x, 1), x), x))", f563, 0, 128},
  {"128:_mm_slli_epi64(_mm_sllv_epi64(x, y), 1)", f564, 0, 128},
  {"128:_mm_sllv_epi64(_mm_slli_epi64(x, 1), y)", f565, 0, 128},
  {"128:_mm_sllv_epi64(x, _mm_slli_epi64(y, 1))", f566, 0, 128},
  {"128:_mm_sllv_epi64(_mm_slli_epi64(x, 1), _mm_slli_epi64(y, 1))", f567, 0, 128},
  {"128:_mm_sllv_epi64(x, _mm_slli_epi64(x, 1))", f568, 0, 128},
  {"128:_mm_sllv_epi64(_mm_slli_epi64(x, 1), x)", f569, 0, 128},
  {"128:_mm_slli_epi64(_mm_srlv_epi64(x, y), 1)", f570, 0, 128},
  {"128:_mm_srlv_epi64(_mm_slli_epi64(x, 1), y)", f571, 0, 128},
  {"128:_mm_srlv_epi64(x, _mm_slli_epi64(y, 1))", f572, 0, 128},
  {"128:_mm_srlv_epi64(_mm_slli_epi64(x, 1), _mm_slli_epi64(y, 1))", f573, 0, 128},
  {"128:_mm_srlv_epi64(x, _mm_slli_epi64(x, 1))", f574, 0, 128},
  {"128:_mm_srlv_epi64(_mm_slli_epi64(x, 1), x)", f575, 0, 128},
  {"128:_mm_srli_epi64(_mm_add_epi64(x, y), 1)", f576, 0, 128},
  {"128:_mm_add_epi64(_mm_srli_epi64(x, 1), y)", f577, 0, 128},
  {"128:_mm_add_epi64(x, _mm_srli_epi64(y, 1))", f578, 0, 128},
  {"128:_mm_add_epi64(_mm_srli_epi64(x, 1), _mm_srli_epi64(y, 1))", f579, 0, 128},
  {"128:_mm_add_epi64(x, _mm_srli_epi64(x, 1))", f580, 0, 128},
  {"128:_mm_add_epi64(_mm_srli_epi64(x, 1), x)", f581, 0, 128},
  {"128:_mm_srli_epi64(_mm_sub_epi64(x, y), 1)", f582, 0, 128},
  {"128:_mm_sub_epi64(_mm_srli_epi64(x, 1), y)", f583, 0, 128},
  {"128:_mm_sub_epi64(x, _mm_srli_epi64(y, 1))", f584, 0, 128},
  {"128:_mm_sub_epi64(_mm_srli_epi64(x, 1), _mm_srli_epi64(y, 1))", f585, 0, 128},
  {"128:_mm_sub_epi64(x, _mm_srli_epi64(x, 1))", f586, 0, 128},
  {"128:_mm_sub_epi64(_mm_srli_epi64(x, 1), x)", f587, 0, 128},
  {"128:_mm_srli_epi64(_mm_and_si128(x, y), 1)", f588, 0, 128},
  {"128:_mm_and_si128(_mm_srli_epi64(x, 1), y)", f589, 0, 128},
  {"128:_mm_and_si128(x, _mm_srli_epi64(y, 1))", f590, 0, 128},
  {"128:_mm_and_si128(_mm_srli_epi64(x, 1), _mm_srli_epi64(y, 1))", f591, 0, 128},
  {"128:_mm_and_si128(x, _mm_srli_epi64(x, 1))", f592, 0, 128},
  {"128:_mm_and_si128(_mm_srli_epi64(x, 1), x)", f593, 0, 128},
  {"128:_mm_srli_epi64(_mm_or_si128(x, y), 1)", f594, 0, 128},
  {"128:_mm_or_si128(_mm_srli_epi64(x, 1), y)", f595, 0, 128},
  {"128:_mm_or_si128(x, _mm_srli_epi64(y, 1))", f596, 0, 128},
  {"128:_mm_or_si128(_mm_srli_epi64(x, 1), _mm_srli_epi64(y, 1))", f597, 0, 128},
  {"128:_mm_or_si128(x, _mm_srli_epi64(x, 1))", f598, 0, 128},
  {"128:_mm_or_si128(_mm_srli_epi64(x, 1), x)", f599, 0, 128},
  {"128:_mm_srli_epi64(_mm_xor_si128(x, y), 1)", f600, 0, 128},
  {"128:_mm_xor_si128(_mm_srli_epi64(x, 1), y)", f601, 0, 128},
  {"128:_mm_xor_si128(x, _mm_srli_epi64(y, 1))", f602, 0, 128},
  {"128:_mm_xor_si128(_mm_srli_epi64(x, 1), _mm_srli_epi64(y, 1))", f603, 0, 128},
  {"128:_mm_xor_si128(x, _mm_srli_epi64(x, 1))", f604, 0, 128},
  {"128:_mm_xor_si128(_mm_srli_epi64(x, 1), x)", f605, 0, 128},
  {"128:_mm_srli_epi64(_mm_andnot_si128(x, y), 1)", f606, 0, 128},
  {"128:_mm_andnot_si128(_mm_srli_epi64(x, 1), y)", f607, 0, 128},
  {"128:_mm_andnot_si128(x, _mm_srli_epi64(y, 1))", f608, 0, 128},
  {"128:_mm_andnot_si128(_mm_srli_epi64(x, 1), _mm_srli_epi64(y, 1))", f609, 0, 128},
  {"128:_mm_andnot_si128(x, _mm_srli_epi64(x, 1))", f610, 0, 128},
  {"128:_mm_andnot_si128(_mm_srli_epi64(x, 1), x)", f611, 0, 128},
  {"128:_mm_srli_epi64(_mm_cmpeq_epi64(x, y), 1)", f612, 0, 128},
  {"128:_mm_cmpeq_epi64(_mm_srli_epi64(x, 1), y)", f613, 0, 128},
  {"128:_mm_cmpeq_epi64(x, _mm_srli_epi64(y, 1))", f614, 0, 128},
  {"128:_mm_cmpeq_epi64(_mm_srli_epi64(x, 1), _mm_srli_epi64(y, 1))", f615, 0, 128},
  {"128:_mm_cmpeq_epi64(x, _mm_srli_epi64(x, 1))", f616, 0, 128},
  {"128:_mm_cmpeq_epi64(_mm_srli_epi64(x, 1), x)", f617, 0, 128},
  {"128:_mm_srli_epi64(_mm_cmpgt_epi64(x, y), 1)", f618, 0, 128},
  {"128:_mm_cmpgt_epi64(_mm_srli_epi64(x, 1), y)", f619, 0, 128},
  {"128:_mm_cmpgt_epi64(x, _mm_srli_epi64(y, 1))", f620, 0, 128},
  {"128:_mm_cmpgt_epi64(_mm_srli_epi64(x, 1), _mm_srli_epi64(y, 1))", f621, 0, 128},
  {"128:_mm_cmpgt_epi64(x, _mm_srli_epi64(x, 1))", f622, 0, 128},
  {"128:_mm_cmpgt_epi64(_mm_srli_epi64(x, 1), x)", f623, 0, 128},
  {"128:_mm_srli_epi64(_mm_unpacklo_epi64(x, y), 1)", f624, 0, 128},
  {"128:_mm_unpacklo_epi64(_mm_srli_epi64(x, 1), y)", f625, 0, 128},
  {"128:_mm_unpacklo_epi64(x, _mm_srli_epi64(y, 1))", f626, 0, 128},
  {"128:_mm_unpacklo_epi64(_mm_srli_epi64(x, 1), _mm_srli_epi64(y, 1))", f627, 0, 128},
  {"128:_mm_unpacklo_epi64(x, _mm_srli_epi64(x, 1))", f628, 0, 128},
  {"128:_mm_unpacklo_epi64(_mm_srli_epi64(x, 1), x)", f629, 0, 128},
  {"128:_mm_srli_epi64(_mm_unpackhi_epi64(x, y), 1)", f630, 0, 128},
  {"128:_mm_unpackhi_epi64(_mm_srli_epi64(x, 1), y)", f631, 0, 128},
  {"128:_mm_unpackhi_epi64(x, _mm_srli_epi64(y, 1))", f632, 0, 128},
  {"128:_mm_unpackhi_epi64(_mm_srli_epi64(x, 1), _mm_srli_epi64(y, 1))", f633, 0, 128},
  {"128:_mm_unpackhi_epi64(x, _mm_srli_epi64(x, 1))", f634, 0, 128},
  {"128:_mm_unpackhi_epi64(_mm_srli_epi64(x, 1), x)", f635, 0, 128},
  {"128:_mm_srli_epi64(_mm_blendv_epi8(x, y, _mm_cmpgt_epi64(x, y)), 1)", f636, 0, 128},
  {"128:_mm_blendv_epi8(_mm_srli_epi64(x, 1), y, _mm_cmpgt_epi64(_mm_srli_epi64(x, 1), y))", f637, 0, 128},
  {"128:_mm_blendv_epi8(x, _mm_srli_epi64(y, 1), _mm_cmpgt_epi64(x, _mm_srli_epi64(y, 1)))", f638, 0, 128},
  {"128:_mm_blendv_epi8(_mm_srli_epi64(x, 1), _mm_srli_epi64(y, 1), _mm_cmpgt_epi64(_mm_srli_epi64(x, 1), _mm_srli_epi64(y, 1)))", f639, 0, 128},
  {"128:_mm_blendv_epi8(x, _mm_srli_epi64(x, 1), _mm_cmpgt_epi64(x, _mm_srli_epi64(x, 1)))", f640, 0, 128},
  {"128:_mm_blendv_epi8(_mm_srli_epi64(x, 1), x, _mm_cmpgt_epi64(_mm_srli_epi64(x, 1), x))", f641, 0, 128},
  {"128:_mm_srli_epi64(_mm_blendv_epi8(y, x, _mm_cmpgt_epi64(x, y)), 1)", f642, 0, 128},
  {"128:_mm_blendv_epi8(y, _mm_srli_epi64(x, 1), _mm_cmpgt_epi64(_mm_srli_epi64(x, 1), y))", f643, 0, 128},
  {"128:_mm_blendv_epi8(_mm_srli_epi64(y, 1), x, _mm_cmpgt_epi64(x, _mm_srli_epi64(y, 1)))", f644, 0, 128},
  {"128:_mm_blendv_epi8(_mm_srli_epi64(y, 1), _mm_srli_epi64(x, 1), _mm_cmpgt_epi64(_mm_srli_epi64(x, 1), _mm_srli_epi64(y, 1)))", f645, 0, 128},
  {"128:_mm_blendv_epi8(_mm_srli_epi64(x, 1), x, _mm_cmpgt_epi64(x, _mm_srli_epi64(x, 1)))", f646, 0, 128},
  {"128:_mm_blendv_epi8(x, _mm_srli_epi64(x, 1), _mm_cmpgt_epi64(_mm_srli_epi64(x, 1), x))", f647, 0, 128},
  {"128:_mm_srli_epi64(_mm_or_si128(_mm_and_si128(_mm_cmpgt_epi64(x, y), x), _mm_andnot_si128(_mm_cmpgt_epi64(x, y), y)), 1)", f648, 0, 128},
  {"128:_mm_or_si128(_mm_and_si128(_mm_cmpgt_epi64(_mm_srli_epi64(x, 1), y), _mm_srli_epi64(x, 1)), _mm_andnot_si128(_mm_cmpgt_epi64(_mm_srli_epi64(x, 1), y), y))", f649, 0, 128},
  {"128:_mm_or_si128(_mm_and_si128(_mm_cmpgt_epi64(x, _mm_srli_epi64(y, 1)), x), _mm_andnot_si128(_mm_cmpgt_epi64(x, _mm_srli_epi64(y, 1)), _mm_srli_epi64(y, 1)))", f650, 0, 128},
  {"128:_mm_or_si128(_mm_and_si128(_mm_cmpgt_epi64(_mm_srli_epi64(x, 1), _mm_srli_epi64(y, 1)), _mm_srli_epi64(x, 1)), _mm_andnot_si128(_mm_cmpgt_epi64(_mm_srli_epi64(x, 1), _mm_srli_epi64(y, 1)), _mm_srli_epi64(y, 1)))", f651, 0, 128},
  {"128:_mm_or_si128(_mm_and_si128(_mm_cmpgt_epi64(x, _mm_srli_epi64(x, 1)), x), _mm_andnot_si128(_mm_cmpgt_epi64(x, _mm_srli_epi64(x, 1)), _mm_srli_epi64(x, 1)))", f652, 0, 128},
  {"128:_mm_or_si128(_mm_and_si128(_mm_cmpgt_epi64(_mm_srli_epi64(x, 1), x), _mm_srli_epi64(x, 1)), _mm_andnot_si128(_mm_cmpgt_epi64(_mm_srli_epi64(x, 1), x), x))", f653, 0, 128},
  {"128:_mm_srli_epi64(_mm_blendv_epi8(x, y, _mm_cmpeq_epi64(x, y)), 1)", f654, 0, 128},
  {"128:_mm_blendv_epi8(_mm_srli_epi64(x, 1), y, _mm_cmpeq_epi64(_mm_srli_epi64(x, 1), y))", f655, 0, 128},
  {"128:_mm_blendv_epi8(x, _mm_srli_epi64(y, 1), _mm_cmpeq_epi64(x, _mm_srli_epi64(y, 1)))", f656, 0, 128},
  {"128:_mm_blendv_epi8(_mm_srli_epi64(x, 1), _mm_srli_epi64(y, 1), _mm_cmpeq_epi64(_mm_srli_epi64(x, 1), _mm_srli_epi64(y, 1)))", f657, 0, 128},
  {"128:_mm_blendv_epi8(x, _mm_srli_epi64(x, 1), _mm_cmpeq_epi64(x, _mm_srli_epi64(x, 1)))", f658, 0, 128},
  {"128:_mm_blendv_epi8(_mm_srli_epi64(x, 1), x, _mm_cmpeq_epi64(_mm_srli_epi64(x, 1), x))", f659, 0, 128},
  {"128:_mm_srli_epi64(_mm_blendv_epi8(y, x, _mm_cmpeq_epi64(x, y)), 1)", f660, 0, 128},
  {"128:_mm_blendv_epi8(y, _mm_srli_epi64(x, 1), _mm_cmpeq_epi64(_mm_srli_epi64(x, 1), y))", f661, 0, 128},
  {"128:_mm_blendv_epi8(_mm_srli_epi64(y, 1), x, _mm_cmpeq_epi64(x, _mm_srli_epi64(y, 1)))", f662, 0, 128},
  {"128:_mm_blendv_epi8(_mm_srli_epi64(y, 1), _mm_srli_epi64(x, 1), _mm_cmpeq_epi64(_mm_srli_epi64(x, 1), _mm_srli_epi64(y, 1)))", f663, 0, 128},
  {"128:_mm_blendv_epi8(_mm_srli_epi64(x, 1), x, _mm_cmpeq_epi64(x, _mm_srli_epi64(x, 1)))", f664, 0, 128},
  {"128:_mm_blendv_epi8(x, _mm_srli_epi64(x, 1), _mm_cmpeq_epi64(_mm_srli_epi64(x, 1), x))", f665, 0, 128},
  {"128:_mm_srli_epi64(_mm_or_si128(_mm_and_si128(_mm_cmpeq_epi64(x, y), x), _mm_andnot_si128(_mm_cmpeq_epi64(x, y), y)), 1)", f666, 0, 128},
  {"128:_mm_or_si128(_mm_and_si128(_mm_cmpeq_epi64(_mm_srli_epi64(x, 1), y), _mm_srli_epi64(x, 1)), _mm_andnot_si128(_mm_cmpeq_epi64(_mm_srli_epi64(x, 1), y), y))", f667, 0, 128},
  {"128:_mm_or_si128(_mm_and_si128(_mm_cmpeq_epi64(x, _mm_srli_epi64(y, 1)), x), _mm_andnot_si128(_mm_cmpeq_epi64(x, _mm_srli_epi64(y, 1)), _mm_srli_epi64(y, 1)))", f668, 0, 128},
  {"128:_mm_or_si128(_mm_and_si128(_mm_cmpeq_epi64(_mm_srli_epi64(x, 1), _mm_srli_epi64(y, 1)), _mm_srli_epi64(x, 1)), _mm_andnot_si128(_mm_cmpeq_epi64(_mm_srli_epi64(x, 1), _mm_srli_epi64(y, 1)), _mm_srli_epi64(y, 1)))", f669, 0, 128},
  {"128:_mm_or_si128(_mm_and_si128(_mm_cmpeq_epi64(x, _mm_srli_epi64(x, 1)), x), _mm_andnot_si128(_mm_cmpeq_epi64(x, _mm_srli_epi64(x, 1)), _mm_srli_epi64(x, 1)))", f670, 0, 128},
  {"128:_mm_or_si128(_mm_and_si128(_mm_cmpeq_epi64(_mm_srli_epi64(x, 1), x), _mm_srli_epi64(x, 1)), _mm_andnot_si128(_mm_cmpeq_epi64(_mm_srli_epi64(x, 1), x), x))", f671, 0, 128},
  {"128:_mm_srli_epi64(_mm_sllv_epi64(x, y), 1)", f672, 0, 128},
  {"128:_mm_sllv_epi64(_mm_srli_epi64(x, 1), y)", f673, 0, 128},
  {"128:_mm_sllv_epi64(x, _mm_srli_epi64(y, 1))", f674, 0, 128},
  {"128:_mm_sllv_epi64(_mm_srli_epi64(x, 1), _mm_srli_epi64(y, 1))", f675, 0, 128},
  {"128:_mm_sllv_epi64(x, _mm_srli_epi64(x, 1))", f676, 0, 128},
  {"128:_mm_sllv_epi64(_mm_srli_epi64(x, 1), x)", f677, 0, 128},
  {"128:_mm_srli_epi64(_mm_srlv_epi64(x, y), 1)", f678, 0, 128},
  {"128:_mm_srlv_epi64(_mm_srli_epi64(x, 1), y)", f679, 0, 128},
  {"128:_mm_srlv_epi64(x, _mm_srli_epi64(y, 1))", f680, 0, 128},
  {"128:_mm_srlv_epi64(_mm_srli_epi64(x, 1), _mm_srli_epi64(y, 1))", f681, 0, 128},
  {"128:_mm_srlv_epi64(x, _mm_srli_epi64(x, 1))", f682, 0, 128},
  {"128:_mm_srlv_epi64(_mm_srli_epi64(x, 1), x)", f683, 0, 128},
  {"128:_mm_slli_epi64(_mm_add_epi64(x, y), 63)", f684, 0, 128},
  {"128:_mm_add_epi64(_mm_slli_epi64(x, 63), y)", f685, 0, 128},
  {"128:_mm_add_epi64(x, _mm_slli_epi64(y, 63))", f686, 0, 128},
  {"128:_mm_add_epi64(_mm_slli_epi64(x, 63), _mm_slli_epi64(y, 63))", f687, 0, 128},
  {"128:_mm_add_epi64(x, _mm_slli_epi64(x, 63))", f688, 0, 128},
  {"128:_mm_add_epi64(_mm_slli_epi64(x, 63), x)", f689, 0, 128},
  {"128:_mm_slli_epi64(_mm_sub_epi64(x, y), 63)", f690, 0, 128},
  {"128:_mm_sub_epi64(_mm_slli_epi64(x, 63), y)", f691, 0, 128},
  {"128:_mm_sub_epi64(x, _mm_slli_epi64(y, 63))", f692, 0, 128},
  {"128:_mm_sub_epi64(_mm_slli_epi64(x, 63), _mm_slli_epi64(y, 63))", f693, 0, 128},
  {"128:_mm_sub_epi64(x, _mm_slli_epi64(x, 63))", f694, 0, 128},
  {"128:_mm_sub_epi64(_mm_slli_epi64(x, 63), x)", f695, 0, 128},
  {"128:_mm_slli_epi64(_mm_and_si128(x, y), 63)", f696, 0, 128},
  {"128:_mm_and_si128(_mm_slli_epi64(x, 63), y)", f697, 0, 128},
  {"128:_mm_and_si128(x, _mm_slli_epi64(y, 63))", f698, 0, 128},
  {"128:_mm_and_si128(_mm_slli_epi64(x, 63), _mm_slli_epi64(y, 63))", f699, 0, 128},
  {"128:_mm_and_si128(x, _mm_slli_epi64(x, 63))", f700, 0, 128},
  {"128:_mm_and_si128(_mm_slli_epi64(x, 63), x)", f701, 0, 128},
  {"128:_mm_slli_epi64(_mm_or_si128(x, y), 63)", f702, 0, 128},
  {"128:_mm_or_si128(_mm_slli_epi64(x, 63), y)", f703, 0, 128},
  {"128:_mm_or_si128(x, _mm_slli_epi64(y, 63))", f704, 0, 128},
  {"128:_mm_or_si128(_mm_slli_epi64(x, 63), _mm_slli_epi64(y, 63))", f705, 0, 128},
  {"128:_mm_or_si128(x, _mm_slli_epi64(x, 63))", f706, 0, 128},
  {"128:_mm_or_si128(_mm_slli_epi64(x, 63), x)", f707, 0, 128},
  {"128:_mm_slli_epi64(_mm_xor_si128(x, y), 63)", f708, 0, 128},
  {"128:_mm_xor_si128(_mm_slli_epi64(x, 63), y)", f709, 0, 128},
  {"128:_mm_xor_si128(x, _mm_slli_epi64(y, 63))", f710, 0, 128},
  {"128:_mm_xor_si128(_mm_slli_epi64(x, 63), _mm_slli_epi64(y, 63))", f711, 0, 128},
  {"128:_mm_xor_si128(x, _mm_slli_epi64(x, 63))", f712, 0, 128},
  {"128:_mm_xor_si128(_mm_slli_epi64(x, 63), x)", f713, 0, 128},
  {"128:_mm_slli_epi64(_mm_andnot_si128(x, y), 63)", f714, 0, 128},
  {"128:_mm_andnot_si128(_mm_slli_epi64(x, 63), y)", f715, 0, 128},
  {"128:_mm_andnot_si128(x, _mm_slli_epi64(y, 63))", f716, 0, 128},
  {"128:_mm_andnot_si128(_mm_slli_epi64(x, 63), _mm_slli_epi64(y, 63))", f717, 0, 128},
  {"128:_mm_andnot_si128(x, _mm_slli_epi64(x, 63))", f718, 0, 128},
  {"128:_mm_andnot_si128(_mm_slli_epi64(x, 63), x)", f719, 0, 128},
  {"128:_mm_slli_epi64(_mm_cmpeq_epi64(x, y), 63)", f720, 0, 128},
  {"128:_mm_cmpeq_epi64(_mm_slli_epi64(x, 63), y)", f721, 0, 128},
  {"128:_mm_cmpeq_epi64(x, _mm_slli_epi64(y, 63))", f722, 0, 128},
  {"128:_mm_cmpeq_epi64(_mm_slli_epi64(x, 63), _mm_slli_epi64(y, 63))", f723, 0, 128},
  {"128:_mm_cmpeq_epi64(x, _mm_slli_epi64(x, 63))", f724, 0, 128},
  {"128:_mm_cmpeq_epi64(_mm_slli_epi64(x, 63), x)", f725, 0, 128},
  {"128:_mm_slli_epi64(_mm_cmpgt_epi64(x, y), 63)", f726, 0, 128},
  {"128:_mm_cmpgt_epi64(_mm_slli_epi64(x, 63), y)", f727, 0, 128},
  {"128:_mm_cmpgt_epi64(x, _mm_slli_epi64(y, 63))", f728, 0, 128},
  {"128:_mm_cmpgt_epi64(_mm_slli_epi64(x, 63), _mm_slli_epi64(y, 63))", f729, 0, 128},
  {"128:_mm_cmpgt_epi64(x, _mm_slli_epi64(x, 63))", f730, 0, 128},
  {"128:_mm_cmpgt_epi64(_mm_slli_epi64(x, 63), x)", f731, 0, 128},
  {"128:_mm_slli_epi64(_mm_unpacklo_epi64(x, y), 63)", f732, 0, 128},
  {"128:_mm_unpacklo_epi64(_mm_slli_epi64(x, 63), y)", f733, 0, 128},
  {"128:_mm_unpacklo_epi64(x, _mm_slli_epi64(y, 63))", f734, 0, 128},
  {"128:_mm_unpacklo_epi64(_mm_slli_epi64(x, 63), _mm_slli_epi64(y, 63))", f735, 0, 128},
  {"128:_mm_unpacklo_epi64(x, _mm_slli_epi64(x, 63))", f736, 0, 128},
  {"128:_mm_unpacklo_epi64(_mm_slli_epi64(x, 63), x)", f737, 0, 128},
  {"128:_mm_slli_epi64(_mm_unpackhi_epi64(x, y), 63)", f738, 0, 128},
  {"128:_mm_unpackhi_epi64(_mm_slli_epi64(x, 63), y)", f739, 0, 128},
  {"128:_mm_unpackhi_epi64(x, _mm_slli_epi64(y, 63))", f740, 0, 128},
  {"128:_mm_unpackhi_epi64(_mm_slli_epi64(x, 63), _mm_slli_epi64(y, 63))", f741, 0, 128},
  {"128:_mm_unpackhi_epi64(x, _mm_slli_epi64(x, 63))", f742, 0, 128},
  {"128:_mm_unpackhi_epi64(_mm_slli_epi64(x, 63), x)", f743, 0, 128},
  {"128:_mm_slli_epi64(_mm_blendv_epi8(x, y, _mm_cmpgt_epi64(x, y)), 63)", f744, 0, 128},
  {"128:_mm_blendv_epi8(_mm_slli_epi64(x, 63), y, _mm_cmpgt_epi64(_mm_slli_epi64(x, 63), y))", f745, 0, 128},
  {"128:_mm_blendv_epi8(x, _mm_slli_epi64(y, 63), _mm_cmpgt_epi64(x, _mm_slli_epi64(y, 63)))", f746, 0, 128},
  {"128:_mm_blendv_epi8(_mm_slli_epi64(x, 63), _mm_slli_epi64(y, 63), _mm_cmpgt_epi64(_mm_slli_epi64(x, 63), _mm_slli_epi64(y, 63)))", f747, 0, 128},
  {"128:_mm_blendv_epi8(x, _mm_slli_epi64(x, 63), _mm_cmpgt_epi64(x, _mm_slli_epi64(x, 63)))", f748, 0, 128},
  {"128:_mm_blendv_epi8(_mm_slli_epi64(x, 63), x, _mm_cmpgt_epi64(_mm_slli_epi64(x, 63), x))", f749, 0, 128},
  {"128:_mm_slli_epi64(_mm_blendv_epi8(y, x, _mm_cmpgt_epi64(x, y)), 63)", f750, 0, 128},
  {"128:_mm_blendv_epi8(y, _mm_slli_epi64(x, 63), _mm_cmpgt_epi64(_mm_slli_epi64(x, 63), y))", f751, 0, 128},
  {"128:_mm_blendv_epi8(_mm_slli_epi64(y, 63), x, _mm_cmpgt_epi64(x, _mm_slli_epi64(y, 63)))", f752, 0, 128},
  {"128:_mm_blendv_epi8(_mm_slli_epi64(y, 63), _mm_slli_epi64(x, 63), _mm_cmpgt_epi64(_mm_slli_epi64(x, 63), _mm_slli_epi64(y, 63)))", f753, 0, 128},
  {"128:_mm_blendv_epi8(_mm_slli_epi64(x, 63), x, _mm_cmpgt_epi64(x, _mm_slli_epi64(x, 63)))", f754, 0, 128},
  {"128:_mm_blendv_epi8(x, _mm_slli_epi64(x, 63), _mm_cmpgt_epi64(_mm_slli_epi64(x, 63), x))", f755, 0, 128},
  {"128:_mm_slli_epi64(_mm_or_si128(_mm_and_si128(_mm_cmpgt_epi64(x, y), x), _mm_andnot_si128(_mm_cmpgt_epi64(x, y), y)), 63)", f756, 0, 128},
  {"128:_mm_or_si128(_mm_and_si128(_mm_cmpgt_epi64(_mm_slli_epi64(x, 63), y), _mm_slli_epi64(x, 63)), _mm_andnot_si128(_mm_cmpgt_epi64(_mm_slli_epi64(x, 63), y), y))", f757, 0, 128},
  {"128:_mm_or_si128(_mm_and_si128(_mm_cmpgt_epi64(x, _mm_slli_epi64(y, 63)), x), _mm_andnot_si128(_mm_cmpgt_epi64(x, _mm_slli_epi64(y, 63)), _mm_slli_epi64(y, 63)))", f758, 0, 128},
  {"128:_mm_or_si128(_mm_and_si128(_mm_cmpgt_epi64(_mm_slli_epi64(x, 63), _mm_slli_epi64(y, 63)), _mm_slli_epi64(x, 63)), _mm_andnot_si128(_mm_cmpgt_epi64(_mm_slli_epi64(x, 63), _mm_slli_epi64(y, 63)), _mm_slli_epi64(y, 63)))", f759, 0, 128},
  {"128:_mm_or_si128(_mm_and_si128(_mm_cmpgt_epi64(x, _mm_slli_epi64(x, 63)), x), _mm_andnot_si128(_mm_cmpgt_epi64(x, _mm_slli_epi64(x, 63)), _mm_slli_epi64(x, 63)))", f760, 0, 128},
  {"128:_mm_or_si128(_mm_and_si128(_mm_cmpgt_epi64(_mm_slli_epi64(x, 63), x), _mm_slli_epi64(x, 63)), _mm_andnot_si128(_mm_cmpgt_epi64(_mm_slli_epi64(x, 63), x), x))", f761, 0, 128},
  {"128:_mm_slli_epi64(_mm_blendv_epi8(x, y, _mm_cmpeq_epi64(x, y)), 63)", f762, 0, 128},
  {"128:_mm_blendv_epi8(_mm_slli_epi64(x, 63), y, _mm_cmpeq_epi64(_mm_slli_epi64(x, 63), y))", f763, 0, 128},
  {"128:_mm_blendv_epi8(x, _mm_slli_epi64(y, 63), _mm_cmpeq_epi64(x, _mm_slli_epi64(y, 63)))", f764, 0, 128},
  {"128:_mm_blendv_epi8(_mm_slli_epi64(x, 63), _mm_slli_epi64(y, 63), _mm_cmpeq_epi64(_mm_slli_epi64(x, 63), _mm_slli_epi64(y, 63)))", f765, 0, 128},
  {"128:_mm_blendv_epi8(x, _mm_slli_epi64(x, 63), _mm_cmpeq_epi64(x, _mm_slli_epi64(x, 63)))", f766, 0, 128},
  {"128:_mm_blendv_epi8(_mm_slli_epi64(x, 63), x, _mm_cmpeq_epi64(_mm_slli_epi64(x, 63), x))", f767, 0, 128},
  {"128:_mm_slli_epi64(_mm_blendv_epi8(y, x, _mm_cmpeq_epi64(x, y)), 63)", f768, 0, 128},
  {"128:_mm_blendv_epi8(y, _mm_slli_epi64(x, 63), _mm_cmpeq_epi64(_mm_slli_epi64(x, 63), y))", f769, 0, 128},
  {"128:_mm_blendv_epi8(_mm_slli_epi64(y, 63), x, _mm_cmpeq_epi64(x, _mm_slli_epi64(y, 63)))", f770, 0, 128},
  {"128:_mm_blendv_epi8(_mm_slli_epi64(y, 63), _mm_slli_epi64(x, 63), _mm_cmpeq_epi64(_mm_slli_epi64(x, 63), _mm_slli_epi64(y, 63)))", f771, 0, 128},
  {"128:_mm_blendv_epi8(_mm_slli_epi64(x, 63), x, _mm_cmpeq_epi64(x, _mm_slli_epi64(x, 63)))", f772, 0, 128},
  {"128:_mm_blendv_epi8(x, _mm_slli_epi64(x, 63), _mm_cmpeq_epi64(_mm_slli_epi64(x, 63), x))", f773, 0, 128},
  {"128:_mm_slli_epi64(_mm_or_si128(_mm_and_si128(_mm_cmpeq_epi64(x, y), x), _mm_andnot_si128(_mm_cmpeq_epi64(x, y), y)), 63)", f774, 0, 128},
  {"128:_mm_or_si128(_mm_and_si128(_mm_cmpeq_epi64(_mm_slli_epi64(x, 63), y), _mm_slli_epi64(x, 63)), _mm_andnot_si128(_mm_cmpeq_epi64(_mm_slli_epi64(x, 63), y), y))", f775, 0, 128},
  {"128:_mm_or_si128(_mm_and_si128(_mm_cmpeq_epi64(x, _mm_slli_epi64(y, 63)), x), _mm_andnot_si128(_mm_cmpeq_epi64(x, _mm_slli_epi64(y, 63)), _mm_slli_epi64(y, 63)))", f776, 0, 128},
  {"128:_mm_or_si128(_mm_and_si128(_mm_cmpeq_epi64(_mm_slli_epi64(x, 63), _mm_slli_epi64(y, 63)), _mm_slli_epi64(x, 63)), _mm_andnot_si128(_mm_cmpeq_epi64(_mm_slli_epi64(x, 63), _mm_slli_epi64(y, 63)), _mm_slli_epi64(y, 63)))", f777, 0, 128},
  {"128:_mm_or_si128(_mm_and_si128(_mm_cmpeq_epi64(x, _mm_slli_epi64(x, 63)), x), _mm_andnot_si128(_mm_cmpeq_epi64(x, _mm_slli_epi64(x, 63)), _mm_slli_epi64(x, 63)))", f778, 0, 128},
  {"128:_mm_or_si128(_mm_and_si128(_mm_cmpeq_epi64(_mm_slli_epi64(x, 63), x), _mm_slli_epi64(x, 63)), _mm_andnot_si128(_mm_cmpeq_epi64(_mm_slli_epi64(x, 63), x), x))", f779, 0, 128},
  {"128:_mm_slli_epi64(_mm_sllv_epi64(x, y), 63)", f780, 0, 128},
  {"128:_mm_sllv_epi64(_mm_slli_epi64(x, 63), y)", f781, 0, 128},
  {"128:_mm_sllv_epi64(x, _mm_slli_epi64(y, 63))", f782, 0, 128},
  {"128:_mm_sllv_epi64(_mm_slli_epi64(x, 63), _mm_slli_epi64(y, 63))", f783, 0, 128},
  {"128:_mm_sllv_epi64(x, _mm_slli_epi64(x, 63))", f784, 0, 128},
  {"128:_mm_sllv_epi64(_mm_slli_epi64(x, 63), x)", f785, 0, 128},
  {"128:_mm_slli_epi64(_mm_srlv_epi64(x, y), 63)", f786, 0, 128},
  {"128:_mm_srlv_epi64(_mm_slli_epi64(x, 63), y)", f787, 0, 128},
  {"128:_mm_srlv_epi64(x, _mm_slli_epi64(y, 63))", f788, 0, 128},
  {"128:_mm_srlv_epi64(_mm_slli_epi64(x, 63), _mm_slli_epi64(y, 63))", f789, 0, 128},
  {"128:_mm_srlv_epi64(x, _mm_slli_epi64(x, 63))", f790, 0, 128},
  {"128:_mm_srlv_epi64(_mm_slli_epi64(x, 63), x)", f791, 0, 128},
  {"128:_mm_srli_epi64(_mm_add_epi64(x, y), 63)", f792, 0, 128},
  {"128:_mm_add_epi64(_mm_srli_epi64(x, 63), y)", f793, 0, 128},
  {"128:_mm_add_epi64(x, _mm_srli_epi64(y, 63))", f794, 0, 128},
  {"128:_mm_add_epi64(_mm_srli_epi64(x, 63), _mm_srli_epi64(y, 63))", f795, 0, 128},
  {"128:_mm_add_epi64(x, _mm_srli_epi64(x, 63))", f796, 0, 128},
  {"128:_mm_add_epi64(_mm_srli_epi64(x, 63), x)", f797, 0, 128},
  {"128:_mm_srli_epi64(_mm_sub_epi64(x, y), 63)", f798, 0, 128},
  {"128:_mm_sub_epi64(_mm_srli_epi64(x, 63), y)", f799, 0, 128},
  {"128:_mm_sub_epi64(x, _mm_srli_epi64(y, 63))", f800, 0, 128},
  {"128:_mm_sub_epi64(_mm_srli_epi64(x, 63), _mm_srli_epi64(y, 63))", f801, 0, 128},
  {"128:_mm_sub_epi64(x, _mm_srli_epi64(x, 63))", f802, 0, 128},
  {"128:_mm_sub_epi64(_mm_srli_epi64(x, 63), x)", f803, 0, 128},
  {"128:_mm_srli_epi64(_mm_and_si128(x, y), 63)", f804, 0, 128},
  {"128:_mm_and_si128(_mm_srli_epi64(x, 63), y)", f805, 0, 128},
  {"128:_mm_and_si128(x, _mm_srli_epi64(y, 63))", f806, 0, 128},
  {"128:_mm_and_si128(_mm_srli_epi64(x, 63), _mm_srli_epi64(y, 63))", f807, 0, 128},
  {"128:_mm_and_si128(x, _mm_srli_epi64(x, 63))", f808, 0, 128},
  {"128:_mm_and_si128(_mm_srli_epi64(x, 63), x)", f809, 0, 128},
  {"128:_mm_srli_epi64(_mm_or_si128(x, y), 63)", f810, 0, 128},
  {"128:_mm_or_si128(_mm_srli_epi64(x, 63), y)", f811, 0, 128},
  {"128:_mm_or_si128(x, _mm_srli_epi64(y, 63))", f812, 0, 128},
  {"128:_mm_or_si128(_mm_srli_epi64(x, 63), _mm_srli_epi64(y, 63))", f813, 0, 128},
  {"128:_mm_or_si128(x, _mm_srli_epi64(x, 63))", f814, 0, 128},
  {"128:_mm_or_si128(_mm_srli_epi64(x, 63), x)", f815, 0, 128},
  {"128:_mm_srli_epi64(_mm_xor_si128(x, y), 63)", f816, 0, 128},
  {"128:_mm_xor_si128(_mm_srli_epi64(x, 63), y)", f817, 0, 128},
  {"128:_mm_xor_si128(x, _mm_srli_epi64(y, 63))", f818, 0, 128},
  {"128:_mm_xor_si128(_mm_srli_epi64(x, 63), _mm_srli_epi64(y, 63))", f819, 0, 128},
  {"128:_mm_xor_si128(x, _mm_srli_epi64(x, 63))", f820, 0, 128},
  {"128:_mm_xor_si128(_mm_srli_epi64(x, 63), x)", f821, 0, 128},
  {"128:_mm_srli_epi64(_mm_andnot_si128(x, y), 63)", f822, 0, 128},
  {"128:_mm_andnot_si128(_mm_srli_epi64(x, 63), y)", f823, 0, 128},
  {"128:_mm_andnot_si128(x, _mm_srli_epi64(y, 63))", f824, 0, 128},
  {"128:_mm_andnot_si128(_mm_srli_epi64(x, 63), _mm_srli_epi64(y, 63))", f825, 0, 128},
  {"128:_mm_andnot_si128(x, _mm_srli_epi64(x, 63))", f826, 0, 128},
  {"128:_mm_andnot_si128(_mm_srli_epi64(x, 63), x)", f827, 0, 128},
  {"128:_mm_srli_epi64(_mm_cmpeq_epi64(x, y), 63)", f828, 0, 128},
  {"128:_mm_cmpeq_epi64(_mm_srli_epi64(x, 63), y)", f829, 0, 128},
  {"128:_mm_cmpeq_epi64(x, _mm_srli_epi64(y, 63))", f830, 0, 128},
  {"128:_mm_cmpeq_epi64(_mm_srli_epi64(x, 63), _mm_srli_epi64(y, 63))", f831, 0, 128},
  {"128:_mm_cmpeq_epi64(x, _mm_srli_epi64(x, 63))", f832, 0, 128},
  {"128:_mm_cmpeq_epi64(_mm_srli_epi64(x, 63), x)", f833, 0, 128},
  {"128:_mm_srli_epi64(_mm_cmpgt_epi64(x, y), 63)", f834, 0, 128},
  {"128:_mm_cmpgt_epi64(_mm_srli_epi64(x, 63), y)", f835, 0, 128},
  {"128:_mm_cmpgt_epi64(x, _mm_srli_epi64(y, 63))", f836, 0, 128},
  {"128:_mm_cmpgt_epi64(_mm_srli_epi64(x, 63), _mm_srli_epi64(y, 63))", f837, 0, 128},
  {"128:_mm_cmpgt_epi64(x, _mm_srli_epi64(x, 63))", f838, 0, 128},
  {"128:_mm_cmpgt_epi64(_mm_srli_epi64(x, 63), x)", f839, 0, 128},
  {"128:_mm_srli_epi64(_mm_unpacklo_epi64(x, y), 63)", f840, 0, 128},
  {"128:_mm_unpacklo_epi64(_mm_srli_epi64(x, 63), y)", f841, 0, 128},
  {"128:_mm_unpacklo_epi64(x, _mm_srli_epi64(y, 63))", f842, 0, 128},
  {"128:_mm_unpacklo_epi64(_mm_srli_epi64(x, 63), _mm_srli_epi64(y, 63))", f843, 0, 128},
  {"128:_mm_unpacklo_epi64(x, _mm_srli_epi64(x, 63))", f844, 0, 128},
  {"128:_mm_unpacklo_epi64(_mm_srli_epi64(x, 63), x)", f845, 0, 128},
  {"128:_mm_srli_epi64(_mm_unpackhi_epi64(x, y), 63)", f846, 0, 128},
  {"128:_mm_unpackhi_epi64(_mm_srli_epi64(x, 63), y)", f847, 0, 128},
  {"128:_mm_unpackhi_epi64(x, _mm_srli_epi64(y, 63))", f848, 0, 128},
  {"128:_mm_unpackhi_epi64(_mm_srli_epi64(x, 63), _mm_srli_epi64(y, 63))", f849, 0, 128},
  {"128:_mm_unpackhi_epi64(x, _mm_srli_epi64(x, 63))", f850, 0, 128},
  {"128:_mm_unpackhi_epi64(_mm_srli_epi64(x, 63), x)", f851, 0, 128},
  {"128:_mm_srli_epi64(_mm_blendv_epi8(x, y, _mm_cmpgt_epi64(x, y)), 63)", f852, 0, 128},
  {"128:_mm_blendv_epi8(_mm_srli_epi64(x, 63), y, _mm_cmpgt_epi64(_mm_srli_epi64(x, 63), y))", f853, 0, 128},
  {"128:_mm_blendv_epi8(x, _mm_srli_epi64(y, 63), _mm_cmpgt_epi64(x, _mm_srli_epi64(y, 63)))", f854, 0, 128},
  {"128:_mm_blendv_epi8(_mm_srli_epi64(x, 63), _mm_srli_epi64(y, 63), _mm_cmpgt_epi64(_mm_srli_epi64(x, 63), _mm_srli_epi64(y, 63)))", f855, 0, 128},
  {"128:_mm_blendv_epi8(x, _mm_srli_epi64(x, 63), _mm_cmpgt_epi64(x, _mm_srli_epi64(x, 63)))", f856, 0, 128},
  {"128:_mm_blendv_epi8(_mm_srli_epi64(x, 63), x, _mm_cmpgt_epi64(_mm_srli_epi64(x, 63), x))", f857, 0, 128},
  {"128:_mm_srli_epi64(_mm_blendv_epi8(y, x, _mm_cmpgt_epi64(x, y)), 63)", f858, 0, 128},
  {"128:_mm_blendv_epi8(y, _mm_srli_epi64(x, 63), _mm_cmpgt_epi64(_mm_srli_epi64(x, 63), y))", f859, 0, 128},
  {"128:_mm_blendv_epi8(_mm_srli_epi64(y, 63), x, _mm_cmpgt_epi64(x, _mm_srli_epi64(y, 63)))", f860, 0, 128},
  {"128:_mm_blendv_epi8(_mm_srli_epi64(y, 63), _mm_srli_epi64(x, 63), _mm_cmpgt_epi64(_mm_srli_epi64(x, 63), _mm_srli_epi64(y, 63)))", f861, 0, 128},
  {"128:_mm_blendv_epi8(_mm_srli_epi64(x, 63), x, _mm_cmpgt_epi64(x, _mm_srli_epi64(x, 63)))", f862, 0, 128},
  {"128:_mm_blendv_epi8(x, _mm_srli_epi64(x, 63), _mm_cmpgt_epi64(_mm_srli_epi64(x, 63), x))", f863, 0, 128},
  {"128:_mm_srli_epi64(_mm_or_si128(_mm_and_si128(_mm_cmpgt_epi64(x, y), x), _mm_andnot_si128(_mm_cmpgt_epi64(x, y), y)), 63)", f864, 0, 128},
  {"128:_mm_or_si128(_mm_and_si128(_mm_cmpgt_epi64(_mm_srli_epi64(x, 63), y), _mm_srli_epi64(x, 63)), _mm_andnot_si128(_mm_cmpgt_epi64(_mm_srli_epi64(x, 63), y), y))", f865, 0, 128},
  {"128:_mm_or_si128(_mm_and_si128(_mm_cmpgt_epi64(x, _mm_srli_epi64(y, 63)), x), _mm_andnot_si128(_mm_cmpgt_epi64(x, _mm_srli_epi64(y, 63)), _mm_srli_epi64(y, 63)))", f866, 0, 128},
  {"128:_mm_or_si128(_mm_and_si128(_mm_cmpgt_epi64(_mm_srli_epi64(x, 63), _mm_srli_epi64(y, 63)), _mm_srli_epi64(x, 63)), _mm_andnot_si128(_mm_cmpgt_epi64(_mm_srli_epi64(x, 63), _mm_srli_epi64(y, 63)), _mm_srli_epi64(y, 63)))", f867, 0, 128},
  {"128:_mm_or_si128(_mm_and_si128(_mm_cmpgt_epi64(x, _mm_srli_epi64(x, 63)), x), _mm_andnot_si128(_mm_cmpgt_epi64(x, _mm_srli_epi64(x, 63)), _mm_srli_epi64(x, 63)))", f868, 0, 128},
  {"128:_mm_or_si128(_mm_and_si128(_mm_cmpgt_epi64(_mm_srli_epi64(x, 63), x), _mm_srli_epi64(x, 63)), _mm_andnot_si128(_mm_cmpgt_epi64(_mm_srli_epi64(x, 63), x), x))", f869, 0, 128},
  {"128:_mm_srli_epi64(_mm_blendv_epi8(x, y, _mm_cmpeq_epi64(x, y)), 63)", f870, 0, 128},
  {"128:_mm_blendv_epi8(_mm_srli_epi64(x, 63), y, _mm_cmpeq_epi64(_mm_srli_epi64(x, 63), y))", f871, 0, 128},
  {"128:_mm_blendv_epi8(x, _mm_srli_epi64(y, 63), _mm_cmpeq_epi64(x, _mm_srli_epi64(y, 63)))", f872, 0, 128},
  {"128:_mm_blendv_epi8(_mm_srli_epi64(x, 63), _mm_srli_epi64(y, 63), _mm_cmpeq_epi64(_mm_srli_epi64(x, 63), _mm_srli_epi64(y, 63)))", f873, 0, 128},
  {"128:_mm_blendv_epi8(x, _mm_srli_epi64(x, 63), _mm_cmpeq_epi64(x, _mm_srli_epi64(x, 63)))", f874, 0, 128},
  {"128:_mm_blendv_epi8(_mm_srli_epi64(x, 63), x, _mm_cmpeq_epi64(_mm_srli_epi64(x, 63), x))", f875, 0, 128},
  {"128:_mm_srli_epi64(_mm_blendv_epi8(y, x, _mm_cmpeq_epi64(x, y)), 63)", f876, 0, 128},
  {"128:_mm_blendv_epi8(y, _mm_srli_epi64(x, 63), _mm_cmpeq_epi64(_mm_srli_epi64(x, 63), y))", f877, 0, 128},
  {"128:_mm_blendv_epi8(_mm_srli_epi64(y, 63), x, _mm_cmpeq_epi64(x, _mm_srli_epi64(y, 63)))", f878, 0, 128},
  {"128:_mm_blendv_epi8(_mm_srli_epi64(y, 63), _mm_srli_epi64(x, 63), _mm_cmpeq_epi64(_mm_srli_epi64(x, 63), _mm_srli_epi64(y, 63)))", f879, 0, 128},
  {"128:_mm_blendv_epi8(_mm_srli_epi64(x, 63), x, _mm_cmpeq_epi64(x, _mm_srli_epi64(x, 63)))", f880, 0, 128},
  {"128:_mm_blendv_epi8(x, _mm_srli_epi64(x, 63), _mm_cmpeq_epi64(_mm_srli_epi64(x, 63), x))", f881, 0, 128},
  {"128:_mm_srli_epi64(_mm_or_si128(_mm_and_si128(_mm_cmpeq_epi64(x, y), x), _mm_andnot_si128(_mm_cmpeq_epi64(x, y), y)), 63)", f882, 0, 128},
  {"128:_mm_or_si128(_mm_and_si128(_mm_cmpeq_epi64(_mm_srli_epi64(x, 63), y), _mm_srli_epi64(x, 63)), _mm_andnot_si128(_mm_cmpeq_epi64(_mm_srli_epi64(x, 63), y), y))", f883, 0, 128},
  {"128:_mm_or_si128(_mm_and_si128(_mm_cmpeq_epi64(x, _mm_srli_epi64(y, 63)), x), _mm_andnot_si128(_mm_cmpeq_epi64(x, _mm_srli_epi64(y, 63)), _mm_srli_epi64(y, 63)))", f884, 0, 128},
  {"128:_mm_or_si128(_mm_and_si128(_mm_cmpeq_epi64(_mm_srli_epi64(x, 63), _mm_srli_epi64(y, 63)), _mm_srli_epi64(x, 63)), _mm_andnot_si128(_mm_cmpeq_epi64(_mm_srli_epi64(x, 63), _mm_srli_epi64(y, 63)), _mm_srli_epi64(y, 63)))", f885, 0, 128},
  {"128:_mm_or_si128(_mm_and_si128(_mm_cmpeq_epi64(x, _mm_srli_epi64(x, 63)), x), _mm_andnot_si128(_mm_cmpeq_epi64(x, _mm_srli_epi64(x, 63)), _mm_srli_epi64(x, 63)))", f886, 0, 128},
  {"128:_mm_or_si128(_mm_and_si128(_mm_cmpeq_epi64(_mm_srli_epi64(x, 63), x), _mm_srli_epi64(x, 63)), _mm_andnot_si128(_mm_cmpeq_epi64(_mm_srli_epi64(x, 63), x), x))", f887, 0, 128},
  {"128:_mm_srli_epi64(_mm_sllv_epi64(x, y), 63)", f888, 0, 128},
  {"128:_mm_sllv_epi64(_mm_srli_epi64(x, 63), y)", f889, 0, 128},
  {"128:_mm_sllv_epi64(x, _mm_srli_epi64(y, 63))", f890, 0, 128},
  {"128:_mm_sllv_epi64(_mm_srli_epi64(x, 63), _mm_srli_epi64(y, 63))", f891, 0, 128},
  {"128:_mm_sllv_epi64(x, _mm_srli_epi64(x, 63))", f892, 0, 128},
  {"128:_mm_sllv_epi64(_mm_srli_epi64(x, 63), x)", f893, 0, 128},
  {"128:_mm_srli_epi64(_mm_srlv_epi64(x, y), 63)", f894, 0, 128},
  {"128:_mm_srlv_epi64(_mm_srli_epi64(x, 63), y)", f895, 0, 128},
  {"128:_mm_srlv_epi64(x, _mm_srli_epi64(y, 63))", f896, 0, 128},
  {"128:_mm_srlv_epi64(_mm_srli_epi64(x, 63), _mm_srli_epi64(y, 63))", f897, 0, 128},
  {"128:_mm_srlv_epi64(x, _mm_srli_epi64(x, 63))", f898, 0, 128},
  {"128:_mm_srlv_epi64(_mm_srli_epi64(x, 63), x)", f899, 0, 128},
  {"128:_mm_shuffle_epi32(_mm_add_epi32(x, y), 0x1b)", f900, 0, 128},
  {"128:_mm_add_epi32(_mm_shuffle_epi32(x, 0x1b), y)", f901, 0, 128},
  {"128:_mm_add_epi32(x, _mm_shuffle_epi32(y, 0x1b))", f902, 0, 128},
  {"128:_mm_add_epi32(_mm_shuffle_epi32(x, 0x1b), _mm_shuffle_epi32(y, 0x1b))", f903, 0, 128},
  {"128:_mm_add_epi32(x, _mm_shuffle_epi32(x, 0x1b))", f904, 0, 128},
  {"128:_mm_add_epi32(_mm_shuffle_epi32(x, 0x1b), x)", f905, 0, 128},
  {"128:_mm_shuffle_epi32(_mm_sub_epi32(x, y), 0x1b)", f906, 0, 128},
  {"128:_mm_sub_epi32(_mm_shuffle_epi32(x, 0x1b), y)", f907, 0, 128},
  {"128:_mm_sub_epi32(x, _mm_shuffle_epi32(y, 0x1b))", f908, 0, 128},
  {"128:_mm_sub_epi32(_mm_shuffle_epi32(x, 0x1b), _mm_shuffle_epi32(y, 0x1b))", f909, 0, 128},
  {"128:_mm_sub_epi32(x, _mm_shuffle_epi32(x, 0x1b))", f910, 0, 128},
  {"128:_mm_sub_epi32(_mm_shuffle_epi32(x, 0x1b), x)", f911, 0, 128},
  {"128:_mm_shuffle_epi32(_mm_min_epi32(x, y), 0x1b)", f912, 0, 128},
  {"128:_mm_min_epi32(_mm_shuffle_epi32(x, 0x1b), y)", f913, 0, 128},
  {"128:_mm_min_epi32(x, _mm_shuffle_epi32(y, 0x1b))", f914, 0, 128},
  {"128:_mm_min_epi32(_mm_shuffle_epi32(x, 0x1b), _mm_shuffle_epi32(y, 0x1b))", f915, 0, 128},
  {"128:_mm_min_epi32(x, _mm_shuffle_epi32(x, 0x1b))", f916, 0, 128},
  {"128:_mm_min_epi32(_mm_shuffle_epi32(x, 0x1b), x)", f917, 0, 128},
  {"128:_mm_shuffle_epi32(_mm_max_epi32(x, y), 0x1b)", f918, 0, 128},
  {"128:_mm_max_epi32(_mm_shuffle_epi32(x, 0x1b), y)", f919, 0, 128},
  {"128:_mm_max_epi32(x, _mm_shuffle_epi32(y, 0x1b))", f920, 0, 128},
  {"128:_mm_max_epi32(_mm_shuffle_epi32(x, 0x1b), _mm_shuffle_epi32(y, 0x1b))", f921, 0, 128},
  {"128:_mm_max_epi32(x, _mm_shuffle_epi32(x, 0x1b))", f922, 0, 128},
  {"128:_mm_max_epi32(_mm_shuffle_epi32(x, 0x1b), x)", f923, 0, 128},
  {"128:_mm_shuffle_epi32(_mm_min_epu32(x, y), 0x1b)", f924, 0, 128},
  {"128:_mm_min_epu32(_mm_shuffle_epi32(x, 0x1b), y)", f925, 0, 128},
  {"128:_mm_min_epu32(x, _mm_shuffle_epi32(y, 0x1b))", f926, 0, 128},
  {"128:_mm_min_epu32(_mm_shuffle_epi32(x, 0x1b), _mm_shuffle_epi32(y, 0x1b))", f927, 0, 128},
  {"128:_mm_min_epu32(x, _mm_shuffle_epi32(x, 0x1b))", f928, 0, 128},
  {"128:_mm_min_epu32(_mm_shuffle_epi32(x, 0x1b), x)", f929, 0, 128},
  {"128:_mm_shuffle_epi32(_mm_max_epu32(x, y), 0x1b)", f930, 0, 128},
  {"128:_mm_max_epu32(_mm_shuffle_epi32(x, 0x1b), y)", f931, 0, 128},
  {"128:_mm_max_epu32(x, _mm_shuffle_epi32(y, 0x1b))", f932, 0, 128},
  {"128:_mm_max_epu32(_mm_shuffle_epi32(x, 0x1b), _mm_shuffle_epi32(y, 0x1b))", f933, 0, 128},
  {"128:_mm_max_epu32(x, _mm_shuffle_epi32(x, 0x1b))", f934, 0, 128},
  {"128:_mm_max_epu32(_mm_shuffle_epi32(x, 0x1b), x)", f935, 0, 128},
  {"128:_mm_shuffle_epi32(_mm_and_si128(x, y), 0x1b)", f936, 0, 128},
  {"128:_mm_and_si128(_mm_shuffle_epi32(x, 0x1b), y)", f937, 0, 128},
  {"128:_mm_and_si128(x, _mm_shuffle_epi32(y, 0x1b))", f938, 0, 128},
  {"128:_mm_and_si128(_mm_shuffle_epi32(x, 0x1b), _mm_shuffle_epi32(y, 0x1b))", f939, 0, 128},
  {"128:_mm_and_si128(x, _mm_shuffle_epi32(x, 0x1b))", f940, 0, 128},
  {"128:_mm_and_si128(_mm_shuffle_epi32(x, 0x1b), x)", f941, 0, 128},
  {"128:_mm_shuffle_epi32(_mm_or_si128(x, y), 0x1b)", f942, 0, 128},
  {"128:_mm_or_si128(_mm_shuffle_epi32(x, 0x1b), y)", f943, 0, 128},
  {"128:_mm_or_si128(x, _mm_shuffle_epi32(y, 0x1b))", f944, 0, 128},
  {"128:_mm_or_si128(_mm_shuffle_epi32(x, 0x1b), _mm_shuffle_epi32(y, 0x1b))", f945, 0, 128},
  {"128:_mm_or_si128(x, _mm_shuffle_epi32(x, 0x1b))", f946, 0, 128},
  {"128:_mm_or_si128(_mm_shuffle_epi32(x, 0x1b), x)", f947, 0, 128},
  {"128:_mm_shuffle_epi32(_mm_xor_si128(x, y), 0x1b)", f948, 0, 128},
  {"128:_mm_xor_si128(_mm_shuffle_epi32(x, 0x1b), y)", f949, 0, 128},
  {"128:_mm_xor_si128(x, _mm_shuffle_epi32(y, 0x1b))", f950, 0, 128},
  {"128:_mm_xor_si128(_mm_shuffle_epi32(x, 0x1b), _mm_shuffle_epi32(y, 0x1b))", f951, 0, 128},
  {"128:_mm_xor_si128(x, _mm_shuffle_epi32(x, 0x1b))", f952, 0, 128},
  {"128:_mm_xor_si128(_mm_shuffle_epi32(x, 0x1b), x)", f953, 0, 128},
  {"128:_mm_shuffle_epi32(_mm_andnot_si128(x, y), 0x1b)", f954, 0, 128},
  {"128:_mm_andnot_si128(_mm_shuffle_epi32(x, 0x1b), y)", f955, 0, 128},
  {"128:_mm_andnot_si128(x, _mm_shuffle_epi32(y, 0x1b))", f956, 0, 128},
  {"128:_mm_andnot_si128(_mm_shuffle_epi32(x, 0x1b), _mm_shuffle_epi32(y, 0x1b))", f957, 0, 128},
  {"128:_mm_andnot_si128(x, _mm_shuffle_epi32(x, 0x1b))", f958, 0, 128},
  {"128:_mm_andnot_si128(_mm_shuffle_epi32(x, 0x1b), x)", f959, 0, 128},
  {"128:_mm_shuffle_epi32(_mm_cmpeq_epi32(x, y), 0x1b)", f960, 0, 128},
  {"128:_mm_cmpeq_epi32(_mm_shuffle_epi32(x, 0x1b), y)", f961, 0, 128},
  {"128:_mm_cmpeq_epi32(x, _mm_shuffle_epi32(y, 0x1b))", f962, 0, 128},
  {"128:_mm_cmpeq_epi32(_mm_shuffle_epi32(x, 0x1b), _mm_shuffle_epi32(y, 0x1b))", f963, 0, 128},
  {"128:_mm_cmpeq_epi32(x, _mm_shuffle_epi32(x, 0x1b))", f964, 0, 128},
  {"128:_mm_cmpeq_epi32(_mm_shuffle_epi32(x, 0x1b), x)", f965, 0, 128},
  {"128:_mm_shuffle_epi32(_mm_cmpgt_epi32(x, y), 0x1b)", f966, 0, 128},
  {"128:_mm_cmpgt_epi32(_mm_shuffle_epi32(x, 0x1b), y)", f967, 0, 128},
  {"128:_mm_cmpgt_epi32(x, _mm_shuffle_epi32(y, 0x1b))", f968, 0, 128},
  {"128:_mm_cmpgt_epi32(_mm_shuffle_epi32(x, 0x1b), _mm_shuffle_epi32(y, 0x1b))", f969, 0, 128},
  {"128:_mm_cmpgt_epi32(x, _mm_shuffle_epi32(x, 0x1b))", f970, 0, 128},
  {"128:_mm_cmpgt_epi32(_mm_shuffle_epi32(x, 0x1b), x)", f971, 0, 128},
  {"128:_mm_shuffle_epi32(_mm_sign_epi32(x, y), 0x1b)", f972, 0, 128},
  {"128:_mm_sign_epi32(_mm_shuffle_epi32(x, 0x1b), y)", f973, 0, 128},
  {"128:_mm_sign_epi32(x, _mm_shuffle_epi32(y, 0x1b))", f974, 0, 128},
  {"128:_mm_sign_epi32(_mm_shuffle_epi32(x, 0x1b), _mm_shuffle_epi32(y, 0x1b))", f975, 0, 128},
  {"128:_mm_sign_epi32(x, _mm_shuffle_epi32(x, 0x1b))", f976, 0, 128},
  {"128:_mm_sign_epi32(_mm_shuffle_epi32(x, 0x1b), x)", f977, 0, 128},
  {"128:_mm_shuffle_epi32(_mm_packs_epi32(x, y), 0x1b)", f978, 0, 128},
  {"128:_mm_packs_epi32(_mm_shuffle_epi32(x, 0x1b), y)", f979, 0, 128},
  {"128:_mm_packs_epi32(x, _mm_shuffle_epi32(y, 0x1b))", f980, 0, 128},
  {"128:_mm_packs_epi32(_mm_shuffle_epi32(x, 0x1b), _mm_shuffle_epi32(y, 0x1b))", f981, 0, 128},
  {"128:_mm_packs_epi32(x, _mm_shuffle_epi32(x, 0x1b))", f982, 0, 128},
  {"128:_mm_packs_epi32(_mm_shuffle_epi32(x, 0x1b), x)", f983, 0, 128},
  {"128:_mm_shuffle_epi32(_mm_packus_epi32(x, y), 0x1b)", f984, 0, 128},
  {"128:_mm_packus_epi32(_mm_shuffle_epi32(x, 0x1b), y)", f985, 0, 128},
  {"128:_mm_packus_epi32(x, _mm_shuffle_epi32(y, 0x1b))", f986, 0, 128},
  {"128:_mm_packus_epi32(_mm_shuffle_epi32(x, 0x1b), _mm_shuffle_epi32(y, 0x1b))", f987, 0, 128},
  {"128:_mm_packus_epi32(x, _mm_shuffle_epi32(x, 0x1b))", f988, 0, 128},
  {"128:_mm_packus_epi32(_mm_shuffle_epi32(x, 0x1b), x)", f989, 0, 128},
  {"128:_mm_shuffle_epi32(_mm_hadd_epi32(x, y), 0x1b)", f990, 0, 128},
  {"128:_mm_hadd_epi32(_mm_shuffle_epi32(x, 0x1b), y)", f991, 0, 128},
  {"128:_mm_hadd_epi32(x, _mm_shuffle_epi32(y, 0x1b))", f992, 0, 128},
  {"128:_mm_hadd_epi32(_mm_shuffle_epi32(x, 0x1b), _mm_shuffle_epi32(y, 0x1b))", f993, 0, 128},
  {"128:_mm_hadd_epi32(x, _mm_shuffle_epi32(x, 0x1b))", f994, 0, 128},
  {"128:_mm_hadd_epi32(_mm_shuffle_epi32(x, 0x1b), x)", f995, 0, 128},
  {"128:_mm_shuffle_epi32(_mm_hsub_epi32(x, y), 0x1b)", f996, 0, 128},
  {"128:_mm_hsub_epi32(_mm_shuffle_epi32(x, 0x1b), y)", f997, 0, 128},
  {"128:_mm_hsub_epi32(x, _mm_shuffle_epi32(y, 0x1b))", f998, 0, 128},
  {"128:_mm_hsub_epi32(_mm_shuffle_epi32(x, 0x1b), _mm_shuffle_epi32(y, 0x1b))", f999, 0, 128},
  {"128:_mm_hsub_epi32(x, _mm_shuffle_epi32(x, 0x1b))", f1000, 0, 128},
  {"128:_mm_hsub_epi32(_mm_shuffle_epi32(x, 0x1b), x)", f1001, 0, 128},
  {"128:_mm_shuffle_epi32(_mm_mul_epi32(x, y), 0x1b)", f1002, 0, 128},
  {"128:_mm_mul_epi32(_mm_shuffle_epi32(x, 0x1b), y)", f1003, 0, 128},
  {"128:_mm_mul_epi32(x, _mm_shuffle_epi32(y, 0x1b))", f1004, 0, 128},
  {"128:_mm_mul_epi32(_mm_shuffle_epi32(x, 0x1b), _mm_shuffle_epi32(y, 0x1b))", f1005, 0, 128},
  {"128:_mm_mul_epi32(x, _mm_shuffle_epi32(x, 0x1b))", f1006, 0, 128},
  {"128:_mm_mul_epi32(_mm_shuffle_epi32(x, 0x1b), x)", f1007, 0, 128},
  {"128:_mm_shuffle_epi32(_mm_mul_epu32(x, y), 0x1b)", f1008, 0, 128},
  {"128:_mm_mul_epu32(_mm_shuffle_epi32(x, 0x1b), y)", f1009, 0, 128},
  {"128:_mm_mul_epu32(x, _mm_shuffle_epi32(y, 0x1b))", f1010, 0, 128},
  {"128:_mm_mul_epu32(_mm_shuffle_epi32(x, 0x1b), _mm_shuffle_epi32(y, 0x1b))", f1011, 0, 128},
  {"128:_mm_mul_epu32(x, _mm_shuffle_epi32(x, 0x1b))", f1012, 0, 128},
  {"128:_mm_mul_epu32(_mm_shuffle_epi32(x, 0x1b), x)", f1013, 0, 128},
  {"128:_mm_shuffle_epi32(_mm_unpacklo_epi32(x, y), 0x1b)", f1014, 0, 128},
  {"128:_mm_unpacklo_epi32(_mm_shuffle_epi32(x, 0x1b), y)", f1015, 0, 128},
  {"128:_mm_unpacklo_epi32(x, _mm_shuffle_epi32(y, 0x1b))", f1016, 0, 128},
  {"128:_mm_unpacklo_epi32(_mm_shuffle_epi32(x, 0x1b), _mm_shuffle_epi32(y, 0x1b))", f1017, 0, 128},
  {"128:_mm_unpacklo_epi32(x, _mm_shuffle_epi32(x, 0x1b))", f1018, 0, 128},
  {"128:_mm_unpacklo_epi32(_mm_shuffle_epi32(x, 0x1b), x)", f1019, 0, 128},
  {"128:_mm_shuffle_epi32(_mm_unpackhi_epi32(x, y), 0x1b)", f1020, 0, 128},
  {"128:_mm_unpackhi_epi32(_mm_shuffle_epi32(x, 0x1b), y)", f1021, 0, 128},
  {"128:_mm_unpackhi_epi32(x, _mm_shuffle_epi32(y, 0x1b))", f1022, 0, 128},
  {"128:_mm_unpackhi_epi32(_mm_shuffle_epi32(x, 0x1b), _mm_shuffle_epi32(y, 0x1b))", f1023, 0, 128},
  {"128:_mm_unpackhi_epi32(x, _mm_shuffle_epi32(x, 0x1b))", f1024, 0, 128},
  {"128:_mm_unpackhi_epi32(_mm_shuffle_epi32(x, 0x1b), x)", f1025, 0, 128},
  {"128:_mm_shuffle_epi32(_mm_blendv_epi8(x, y, _mm_cmpgt_epi32(x, y)), 0x1b)", f1026, 0, 128},
  {"128:_mm_blendv_epi8(_mm_shuffle_epi32(x, 0x1b), y, _mm_cmpgt_epi32(_mm_shuffle_epi32(x, 0x1b), y))", f1027, 0, 128},
  {"128:_mm_blendv_epi8(x, _mm_shuffle_epi32(y, 0x1b), _mm_cmpgt_epi32(x, _mm_shuffle_epi32(y, 0x1b)))", f1028, 0, 128},
  {"128:_mm_blendv_epi8(_mm_shuffle_epi32(x, 0x1b), _mm_shuffle_epi32(y, 0x1b), _mm_cmpgt_epi32(_mm_shuffle_epi32(x, 0x1b), _mm_shuffle_epi32(y, 0x1b)))", f1029, 0, 128},
  {"128:_mm_blendv_epi8(x, _mm_shuffle_epi32(x, 0x1b), _mm_cmpgt_epi32(x, _mm_shuffle_epi32(x, 0x1b)))", f1030, 0, 128},
  {"128:_mm_blendv_epi8(_mm_shuffle_epi32(x, 0x1b), x, _mm_cmpgt_epi32(_mm_shuffle_epi32(x, 0x1b), x))", f1031, 0, 128},
  {"128:_mm_shuffle_epi32(_mm_blendv_epi8(y, x, _mm_cmpgt_epi32(x, y)), 0x1b)", f1032, 0, 128},
  {"128:_mm_blendv_epi8(y, _mm_shuffle_epi32(x, 0x1b), _mm_cmpgt_epi32(_mm_shuffle_epi32(x, 0x1b), y))", f1033, 0, 128},
  {"128:_mm_blendv_epi8(_mm_shuffle_epi32(y, 0x1b), x, _mm_cmpgt_epi32(x, _mm_shuffle_epi32(y, 0x1b)))", f1034, 0, 128},
  {"128:_mm_blendv_epi8(_mm_shuffle_epi32(y, 0x1b), _mm_shuffle_epi32(x, 0x1b), _mm_cmpgt_epi32(_mm_shuffle_epi32(x, 0x1b), _mm_shuffle_epi32(y, 0x1b)))", f1035, 0, 128},
  {"128:_mm_blendv_epi8(_mm_shuffle_epi32(x, 0x1b), x, _mm_cmpgt_epi32(x, _mm_shuffle_epi32(x, 0x1b)))", f1036, 0, 128},
  {"128:_mm_blendv_epi8(x, _mm_shuffle_epi32(x, 0x1b), _mm_cmpgt_epi32(_mm_shuffle_epi32(x, 0x1b), x))", f1037, 0, 128},
  {"128:_mm_shuffle_epi32(_mm_or_si128(_mm_and_si128(_mm_cmpgt_epi32(x, y), x), _mm_andnot_si128(_mm_cmpgt_epi32(x, y), y)), 0x1b)", f1038, 0, 128},
  {"128:_mm_or_si128(_mm_and_si128(_mm_cmpgt_epi32(_mm_shuffle_epi32(x, 0x1b), y), _mm_shuffle_epi32(x, 0x1b)), _mm_andnot_si128(_mm_cmpgt_epi32(_mm_shuffle_epi32(x, 0x1b), y), y))", f1039, 0, 128},
  {"128:_mm_or_si128(_mm_and_si128(_mm_cmpgt_epi32(x, _mm_shuffle_epi32(y, 0x1b)), x), _mm_andnot_si128(_mm_cmpgt_epi32(x, _mm_shuffle_epi32(y, 0x1b)), _mm_shuffle_epi32(y, 0x1b)))", f1040, 0, 128},
  {"128:_mm_or_si128(_mm_and_si128(_mm_cmpgt_epi32(_mm_shuffle_epi32(x, 0x1b), _mm_shuffle_epi32(y, 0x1b)), _mm_shuffle_epi32(x, 0x1b)), _mm_andnot_si128(_mm_cmpgt_epi32(_mm_shuffle_epi32(x, 0x1b), _mm_shuffle_epi32(y, 0x1b)), _mm_shuffle_epi32(y, 0x1b)))", f1041, 0, 128},
  {"128:_mm_or_si128(_mm_and_si128(_mm_cmpgt_epi32(x, _mm_shuffle_epi32(x, 0x1b)), x), _mm_andnot_si128(_mm_cmpgt_epi32(x, _mm_shuffle_epi32(x, 0x1b)), _mm_shuffle_epi32(x, 0x1b)))", f1042, 0, 128},
  {"128:_mm_or_si128(_mm_and_si128(_mm_cmpgt_epi32(_mm_shuffle_epi32(x, 0x1b), x), _mm_shuffle_epi32(x, 0x1b)), _mm_andnot_si128(_mm_cmpgt_epi32(_mm_shuffle_epi32(x, 0x1b), x), x))", f1043, 0, 128},
  {"128:_mm_shuffle_epi32(_mm_blendv_epi8(x, y, _mm_cmpeq_epi32(x, y)), 0x1b)", f1044, 0, 128},
  {"128:_mm_blendv_epi8(_mm_shuffle_epi32(x, 0x1b), y, _mm_cmpeq_epi32(_mm_shuffle_epi32(x, 0x1b), y))", f1045, 0, 128},
  {"128:_mm_blendv_epi8(x, _mm_shuffle_epi32(y, 0x1b), _mm_cmpeq_epi32(x, _mm_shuffle_epi32(y, 0x1b)))", f1046, 0, 128},
  {"128:_mm_blendv_epi8(_mm_shuffle_epi32(x, 0x1b), _mm_shuffle_epi32(y, 0x1b), _mm_cmpeq_epi32(_mm_shuffle_epi32(x, 0x1b), _mm_shuffle_epi32(y, 0x1b)))", f1047, 0, 128},
  {"128:_mm_blendv_epi8(x, _mm_shuffle_epi32(x, 0x1b), _mm_cmpeq_epi32(x, _mm_shuffle_epi32(x, 0x1b)))", f1048, 0, 128},
  {"128:_mm_blendv_epi8(_mm_shuffle_epi32(x, 0x1b), x, _mm_cmpeq_epi32(_mm_shuffle_epi32(x, 0x1b), x))", f1049, 0, 128},
  {"128:_mm_shuffle_epi32(_mm_blendv_epi8(y, x, _mm_cmpeq_epi32(x, y)), 0x1b)", f1050, 0, 128},
  {"128:_mm_blendv_epi8(y, _mm_shuffle_epi32(x, 0x1b), _mm_cmpeq_epi32(_mm_shuffle_epi32(x, 0x1b), y))", f1051, 0, 128},
  {"128:_mm_blendv_epi8(_mm_shuffle_epi32(y, 0x1b), x, _mm_cmpeq_epi32(x, _mm_shuffle_epi32(y, 0x1b)))", f1052, 0, 128},
  {"128:_mm_blendv_epi8(_mm_shuffle_epi32(y, 0x1b), _mm_shuffle_epi32(x, 0x1b), _mm_cmpeq_epi32(_mm_shuffle_epi32(x, 0x1b), _mm_shuffle_epi32(y, 0x1b)))", f1053, 0, 128},
  {"128:_mm_blendv_epi8(_mm_shuffle_epi32(x, 0x1b), x, _mm_cmpeq_epi32(x, _mm_shuffle_epi32(x, 0x1b)))", f1054, 0, 128},
  {"128:_mm_blendv_epi8(x, _mm_shuffle_epi32(x, 0x1b), _mm_cmpeq_epi32(_mm_shuffle_epi32(x, 0x1b), x))", f1055, 0, 128},
  {"128:_mm_shuffle_epi32(_mm_or_si128(_mm_and_si128(_mm_cmpeq_epi32(x, y), x), _mm_andnot_si128(_mm_cmpeq_epi32(x, y), y)), 0x1b)", f1056, 0, 128},
  {"128:_mm_or_si128(_mm_and_si128(_mm_cmpeq_epi32(_mm_shuffle_epi32(x, 0x1b), y), _mm_shuffle_epi32(x, 0x1b)), _mm_andnot_si128(_mm_cmpeq_epi32(_mm_shuffle_epi32(x, 0x1b), y), y))", f1057, 0, 128},
  {"128:_mm_or_si128(_mm_and_si128(_mm_cmpeq_epi32(x, _mm_shuffle_epi32(y, 0x1b)), x), _mm_andnot_si128(_mm_cmpeq_epi32(x, _mm_shuffle_epi32(y, 0x1b)), _mm_shuffle_epi32(y, 0x1b)))", f1058, 0, 128},
  {"128:_mm_or_si128(_mm_and_si128(_mm_cmpeq_epi32(_mm_shuffle_epi32(x, 0x1b), _mm_shuffle_epi32(y, 0x1b)), _mm_shuffle_epi32(x, 0x1b)), _mm_andnot_si128(_mm_cmpeq_epi32(_mm_shuffle_epi32(x, 0x1b), _mm_shuffle_epi32(y, 0x1b)), _mm_shuffle_epi32(y, 0x1b)))", f1059, 0, 128},
  {"128:_mm_or_si128(_mm_and_si128(_mm_cmpeq_epi32(x, _mm_shuffle_epi32(x, 0x1b)), x), _mm_andnot_si128(_mm_cmpeq_epi32(x, _mm_shuffle_epi32(x, 0x1b)), _mm_shuffle_epi32(x, 0x1b)))", f1060, 0, 128},
  {"128:_mm_or_si128(_mm_and_si128(_mm_cmpeq_epi32(_mm_shuffle_epi32(x, 0x1b), x), _mm_shuffle_epi32(x, 0x1b)), _mm_andnot_si128(_mm_cmpeq_epi32(_mm_shuffle_epi32(x, 0x1b), x), x))", f1061, 0, 128},
  {"128:_mm_shuffle_epi32(_mm_mullo_epi32(x, y), 0x1b)", f1062, 0, 128},
  {"128:_mm_mullo_epi32(_mm_shuffle_epi32(x, 0x1b), y)", f1063, 0, 128},
  {"128:_mm_mullo_epi32(x, _mm_shuffle_epi32(y, 0x1b))", f1064, 0, 128},
  {"128:_mm_mullo_epi32(_mm_shuffle_epi32(x, 0x1b), _mm_shuffle_epi32(y, 0x1b))", f1065, 0, 128},
  {"128:_mm_mullo_epi32(x, _mm_shuffle_epi32(x, 0x1b))", f1066, 0, 128},
  {"128:_mm_mullo_epi32(_mm_shuffle_epi32(x, 0x1b), x)", f1067, 0, 128},
  {"128:_mm_shuffle_epi32(_mm_sllv_epi32(x, y), 0x1b)", f1068, 0, 128},
  {"128:_mm_sllv_epi32(_mm_shuffle_epi32(x, 0x1b), y)", f1069, 0, 128},
  {"128:_mm_sllv_epi32(x, _mm_shuffle_epi32(y, 0x1b))", f1070, 0, 128},
  {"128:_mm_sllv_epi32(_mm_shuffle_epi32(x, 0x1b), _mm_shuffle_epi32(y, 0x1b))", f1071, 0, 128},
  {"128:_mm_sllv_epi32(x, _mm_shuffle_epi32(x, 0x1b))", f1072, 0, 128},
  {"128:_mm_sllv_epi32(_mm_shuffle_epi32(x, 0x1b), x)", f1073, 0, 128},
  {"128:_mm_shuffle_epi32(_mm_srlv_epi32(x, y), 0x1b)", f1074, 0, 128},
  {"128:_mm_srlv_epi32(_mm_shuffle_epi32(x, 0x1b), y)", f1075, 0, 128},
  {"128:_mm_srlv_epi32(x, _mm_shuffle_epi32(y, 0x1b))", f1076, 0, 128},
  {"128:_mm_srlv_epi32(_mm_shuffle_epi32(x, 0x1b), _mm_shuffle_epi32(y, 0x1b))", f1077, 0, 128},
  {"128:_mm_srlv_epi32(x, _mm_shuffle_epi32(x, 0x1b))", f1078, 0, 128},
  {"128:_mm_srlv_epi32(_mm_shuffle_epi32(x, 0x1b), x)", f1079, 0, 128},
  {"128:_mm_shuffle_epi32(_mm_srav_epi32(x, y), 0x1b)", f1080, 0, 128},
  {"128:_mm_srav_epi32(_mm_shuffle_epi32(x, 0x1b), y)", f1081, 0, 128},
  {"128:_mm_srav_epi32(x, _mm_shuffle_epi32(y, 0x1b))", f1082, 0, 128},
  {"128:_mm_srav_epi32(_mm_shuffle_epi32(x, 0x1b), _mm_shuffle_epi32(y, 0x1b))", f1083, 0, 128},
  {"128:_mm_srav_epi32(x, _mm_shuffle_epi32(x, 0x1b))", f1084, 0, 128},
  {"128:_mm_srav_epi32(_mm_shuffle_epi32(x, 0x1b), x)", f1085, 0, 128},
  {"128:_mm_shuffle_epi32(_mm_add_epi32(x, y), 0x39)", f1086, 0, 128},
  {"128:_mm_add_epi32(_mm_shuffle_epi32(x, 0x39), y)", f1087, 0, 128},
  {"128:_mm_add_epi32(x, _mm_shuffle_epi32(y, 0x39))", f1088, 0, 128},
  {"128:_mm_add_epi32(_mm_shuffle_epi32(x, 0x39), _mm_shuffle_epi32(y, 0x39))", f1089, 0, 128},
  {"128:_mm_add_epi32(x, _mm_shuffle_epi32(x, 0x39))", f1090, 0, 128},
  {"128:_mm_add_epi32(_mm_shuffle_epi32(x, 0x39), x)", f1091, 0, 128},
  {"128:_mm_shuffle_epi32(_mm_sub_epi32(x, y), 0x39)", f1092, 0, 128},
  {"128:_mm_sub_epi32(_mm_shuffle_epi32(x, 0x39), y)", f1093, 0, 128},
  {"128:_mm_sub_epi32(x, _mm_shuffle_epi32(y, 0x39))", f1094, 0, 128},
  {"128:_mm_sub_epi32(_mm_shuffle_epi32(x, 0x39), _mm_shuffle_epi32(y, 0x39))", f1095, 0, 128},
  {"128:_mm_sub_epi32(x, _mm_shuffle_epi32(x, 0x39))", f1096, 0, 128},
  {"128:_mm_sub_epi32(_mm_shuffle_epi32(x, 0x39), x)", f1097, 0, 128},
  {"128:_mm_shuffle_epi32(_mm_min_epi32(x, y), 0x39)", f1098, 0, 128},
  {"128:_mm_min_epi32(_mm_shuffle_epi32(x, 0x39), y)", f1099, 0, 128},
  {"128:_mm_min_epi32(x, _mm_shuffle_epi32(y, 0x39))", f1100, 0, 128},
  {"128:_mm_min_epi32(_mm_shuffle_epi32(x, 0x39), _mm_shuffle_epi32(y, 0x39))", f1101, 0, 128},
  {"128:_mm_min_epi32(x, _mm_shuffle_epi32(x, 0x39))", f1102, 0, 128},
  {"128:_mm_min_epi32(_mm_shuffle_epi32(x, 0x39), x)", f1103, 0, 128},
  {"128:_mm_shuffle_epi32(_mm_max_epi32(x, y), 0x39)", f1104, 0, 128},
  {"128:_mm_max_epi32(_mm_shuffle_epi32(x, 0x39), y)", f1105, 0, 128},
  {"128:_mm_max_epi32(x, _mm_shuffle_epi32(y, 0x39))", f1106, 0, 128},
  {"128:_mm_max_epi32(_mm_shuffle_epi32(x, 0x39), _mm_shuffle_epi32(y, 0x39))", f1107, 0, 128},
  {"128:_mm_max_epi32(x, _mm_shuffle_epi32(x, 0x39))", f1108, 0, 128},
  {"128:_mm_max_epi32(_mm_shuffle_epi32(x, 0x39), x)", f1109, 0, 128},
  {"128:_mm_shuffle_epi32(_mm_min_epu32(x, y), 0x39)", f1110, 0, 128},
  {"128:_mm_min_epu32(_mm_shuffle_epi32(x, 0x39), y)", f1111, 0, 128},
  {"128:_mm_min_epu32(x, _mm_shuffle_epi32(y, 0x39))", f1112, 0, 128},
  {"128:_mm_min_epu32(_mm_shuffle_epi32(x, 0x39), _mm_shuffle_epi32(y, 0x39))", f1113, 0, 128},
  {"128:_mm_min_epu32(x, _mm_shuffle_epi32(x, 0x39))", f1114, 0, 128},
  {"128:_mm_min_epu32(_mm_shuffle_epi32(x, 0x39), x)", f1115, 0, 128},
  {"128:_mm_shuffle_epi32(_mm_max_epu32(x, y), 0x39)", f1116, 0, 128},
  {"128:_mm_max_epu32(_mm_shuffle_epi32(x, 0x39), y)", f1117, 0, 128},
  {"128:_mm_max_epu32(x, _mm_shuffle_epi32(y, 0x39))", f1118, 0, 128},
  {"128:_mm_max_epu32(_mm_shuffle_epi32(x, 0x39), _mm_shuffle_epi32(y, 0x39))", f1119, 0, 128},
  {"128:_mm_max_epu32(x, _mm_shuffle_epi32(x, 0x39))", f1120, 0, 128},
  {"128:_mm_max_epu32(_mm_shuffle_epi32(x, 0x39), x)", f1121, 0, 128},
  {"128:_mm_shuffle_epi32(_mm_and_si128(x, y), 0x39)", f1122, 0, 128},
  {"128:_mm_and_si128(_mm_shuffle_epi32(x, 0x39), y)", f1123, 0, 128},
  {"128:_mm_and_si128(x, _mm_shuffle_epi32(y, 0x39))", f1124, 0, 128},
  {"128:_mm_and_si128(_mm_shuffle_epi32(x, 0x39), _mm_shuffle_epi32(y, 0x39))", f1125, 0, 128},
  {"128:_mm_and_si128(x, _mm_shuffle_epi32(x, 0x39))", f1126, 0, 128},
  {"128:_mm_and_si128(_mm_shuffle_epi32(x, 0x39), x)", f1127, 0, 128},
  {"128:_mm_shuffle_epi32(_mm_or_si128(x, y), 0x39)", f1128, 0, 128},
  {"128:_mm_or_si128(_mm_shuffle_epi32(x, 0x39), y)", f1129, 0, 128},
  {"128:_mm_or_si128(x, _mm_shuffle_epi32(y, 0x39))", f1130, 0, 128},
  {"128:_mm_or_si128(_mm_shuffle_epi32(x, 0x39), _mm_shuffle_epi32(y, 0x39))", f1131, 0, 128},
  {"128:_mm_or_si128(x, _mm_shuffle_epi32(x, 0x39))", f1132, 0, 128},
  {"128:_mm_or_si128(_mm_shuffle_epi32(x, 0x39), x)", f1133, 0, 128},
  {"128:_mm_shuffle_epi32(_mm_xor_si128(x, y), 0x39)", f1134, 0, 128},
  {"128:_mm_xor_si128(_mm_shuffle_epi32(x, 0x39), y)", f1135, 0, 128},
  {"128:_mm_xor_si128(x, _mm_shuffle_epi32(y, 0x39))", f1136, 0, 128},
  {"128:_mm_xor_si128(_mm_shuffle_epi32(x, 0x39), _mm_shuffle_epi32(y, 0x39))", f1137, 0, 128},
  {"128:_mm_xor_si128(x, _mm_shuffle_epi32(x, 0x39))", f1138, 0, 128},
  {"128:_mm_xor_si128(_mm_shuffle_epi32(x, 0x39), x)", f1139, 0, 128},
  {"128:_mm_shuffle_epi32(_mm_andnot_si128(x, y), 0x39)", f1140, 0, 128},
  {"128:_mm_andnot_si128(_mm_shuffle_epi32(x, 0x39), y)", f1141, 0, 128},
  {"128:_mm_andnot_si128(x, _mm_shuffle_epi32(y, 0x39))", f1142, 0, 128},
  {"128:_mm_andnot_si128(_mm_shuffle_epi32(x, 0x39), _mm_shuffle_epi32(y, 0x39))", f1143, 0, 128},
  {"128:_mm_andnot_si128(x, _mm_shuffle_epi32(x, 0x39))", f1144, 0, 128},
  {"128:_mm_andnot_si128(_mm_shuffle_epi32(x, 0x39), x)", f1145, 0, 128},
  {"128:_mm_shuffle_epi32(_mm_cmpeq_epi32(x, y), 0x39)", f1146, 0, 128},
  {"128:_mm_cmpeq_epi32(_mm_shuffle_epi32(x, 0x39), y)", f1147, 0, 128},
  {"128:_mm_cmpeq_epi32(x, _mm_shuffle_epi32(y, 0x39))", f1148, 0, 128},
  {"128:_mm_cmpeq_epi32(_mm_shuffle_epi32(x, 0x39), _mm_shuffle_epi32(y, 0x39))", f1149, 0, 128},
  {"128:_mm_cmpeq_epi32(x, _mm_shuffle_epi32(x, 0x39))", f1150, 0, 128},
  {"128:_mm_cmpeq_epi32(_mm_shuffle_epi32(x, 0x39), x)", f1151, 0, 128},
  {"128:_mm_shuffle_epi32(_mm_cmpgt_epi32(x, y), 0x39)", f1152, 0, 128},
  {"128:_mm_cmpgt_epi32(_mm_shuffle_epi32(x, 0x39), y)", f1153, 0, 128},
  {"128:_mm_cmpgt_epi32(x, _mm_shuffle_epi32(y, 0x39))", f1154, 0, 128},
  {"128:_mm_cmpgt_epi32(_mm_shuffle_epi32(x, 0x39), _mm_shuffle_epi32(y, 0x39))", f1155, 0, 128},
  {"128:_mm_cmpgt_epi32(x, _mm_shuffle_epi32(x, 0x39))", f1156, 0, 128},
  {"128:_mm_cmpgt_epi32(_mm_shuffle_epi32(x, 0x39), x)", f1157, 0, 128},
  {"128:_mm_shuffle_epi32(_mm_sign_epi32(x, y), 0x39)", f1158, 0, 128},
  {"128:_mm_sign_epi32(_mm_shuffle_epi32(x, 0x39), y)", f1159, 0, 128},
  {"128:_mm_sign_epi32(x, _mm_shuffle_epi32(y, 0x39))", f1160, 0, 128},
  {"128:_mm_sign_epi32(_mm_shuffle_epi32(x, 0x39), _mm_shuffle_epi32(y, 0x39))", f1161, 0, 128},
  {"128:_mm_sign_epi32(x, _mm_shuffle_epi32(x, 0x39))", f1162, 0, 128},
  {"128:_mm_sign_epi32(_mm_shuffle_epi32(x, 0x39), x)", f1163, 0, 128},
  {"128:_mm_shuffle_epi32(_mm_packs_epi32(x, y), 0x39)", f1164, 0, 128},
  {"128:_mm_packs_epi32(_mm_shuffle_epi32(x, 0x39), y)", f1165, 0, 128},
  {"128:_mm_packs_epi32(x, _mm_shuffle_epi32(y, 0x39))", f1166, 0, 128},
  {"128:_mm_packs_epi32(_mm_shuffle_epi32(x, 0x39), _mm_shuffle_epi32(y, 0x39))", f1167, 0, 128},
  {"128:_mm_packs_epi32(x, _mm_shuffle_epi32(x, 0x39))", f1168, 0, 128},
  {"128:_mm_packs_epi32(_mm_shuffle_epi32(x, 0x39), x)", f1169, 0, 128},
  {"128:_mm_shuffle_epi32(_mm_packus_epi32(x, y), 0x39)", f1170, 0, 128},
  {"128:_mm_packus_epi32(_mm_shuffle_epi32(x, 0x39), y)", f1171, 0, 128},
  {"128:_mm_packus_epi32(x, _mm_shuffle_epi32(y, 0x39))", f1172, 0, 128},
  {"128:_mm_packus_epi32(_mm_shuffle_epi32(x, 0x39), _mm_shuffle_epi32(y, 0x39))", f1173, 0, 128},
  {"128:_mm_packus_epi32(x, _mm_shuffle_epi32(x, 0x39))", f1174, 0, 128},
  {"128:_mm_packus_epi32(_mm_shuffle_epi32(x, 0x39), x)", f1175, 0, 128},
  {"128:_mm_shuffle_epi32(_mm_hadd_epi32(x, y), 0x39)", f1176, 0, 128},
  {"128:_mm_hadd_epi32(_mm_shuffle_epi32(x, 0x39), y)", f1177, 0, 128},
  {"128:_mm_hadd_epi32(x, _mm_shuffle_epi32(y, 0x39))", f1178, 0, 128},
  {"128:_mm_hadd_epi32(_mm_shuffle_epi32(x, 0x39), _mm_shuffle_epi32(y, 0x39))", f1179, 0, 128},
  {"128:_mm_hadd_epi32(x, _mm_shuffle_epi32(x, 0x39))", f1180, 0, 128},
  {"128:_mm_hadd_epi32(_mm_shuffle_epi32(x, 0x39), x)", f1181, 0, 128},
  {"128:_mm_shuffle_epi32(_mm_hsub_epi32(x, y), 0x39)", f1182, 0, 128},
  {"128:_mm_hsub_epi32(_mm_shuffle_epi32(x, 0x39), y)", f1183, 0, 128},
  {"128:_mm_hsub_epi32(x, _mm_shuffle_epi32(y, 0x39))", f1184, 0, 128},
  {"128:_mm_hsub_epi32(_mm_shuffle_epi32(x, 0x39), _mm_shuffle_epi32(y, 0x39))", f1185, 0, 128},
  {"128:_mm_hsub_epi32(x, _mm_shuffle_epi32(x, 0x39))", f1186, 0, 128},
  {"128:_mm_hsub_epi32(_mm_shuffle_epi32(x, 0x39), x)", f1187, 0, 128},
  {"128:_mm_shuffle_epi32(_mm_mul_epi32(x, y), 0x39)", f1188, 0, 128},
  {"128:_mm_mul_epi32(_mm_shuffle_epi32(x, 0x39), y)", f1189, 0, 128},
  {"128:_mm_mul_epi32(x, _mm_shuffle_epi32(y, 0x39))", f1190, 0, 128},
  {"128:_mm_mul_epi32(_mm_shuffle_epi32(x, 0x39), _mm_shuffle_epi32(y, 0x39))", f1191, 0, 128},
  {"128:_mm_mul_epi32(x, _mm_shuffle_epi32(x, 0x39))", f1192, 0, 128},
  {"128:_mm_mul_epi32(_mm_shuffle_epi32(x, 0x39), x)", f1193, 0, 128},
  {"128:_mm_shuffle_epi32(_mm_mul_epu32(x, y), 0x39)", f1194, 0, 128},
  {"128:_mm_mul_epu32(_mm_shuffle_epi32(x, 0x39), y)", f1195, 0, 128},
  {"128:_mm_mul_epu32(x, _mm_shuffle_epi32(y, 0x39))", f1196, 0, 128},
  {"128:_mm_mul_epu32(_mm_shuffle_epi32(x, 0x39), _mm_shuffle_epi32(y, 0x39))", f1197, 0, 128},
  {"128:_mm_mul_epu32(x, _mm_shuffle_epi32(x, 0x39))", f1198, 0, 128},
  {"128:_mm_mul_epu32(_mm_shuffle_epi32(x, 0x39), x)", f1199, 0, 128},
};
extern const int size_4 = 1200;
