#include "common.h"
static NOINLINE void f0(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_mulhi_epu16(_mm_cmpgt_epi16(x, y), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f1(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_mulhi_epu16(x, _mm_cmpgt_epi16(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f2(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_mulhi_epu16(_mm_cmpgt_epi16(x, y), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f3(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_mulhi_epu16(y, _mm_cmpgt_epi16(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f4(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_mulhi_epu16(_mm_sign_epi16(x, y), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f5(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_mulhi_epu16(x, _mm_sign_epi16(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f6(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_mulhi_epu16(_mm_sign_epi16(x, y), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f7(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_mulhi_epu16(y, _mm_sign_epi16(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f8(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_mulhi_epu16(_mm_packs_epi16(x, y), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f9(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_mulhi_epu16(x, _mm_packs_epi16(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f10(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_mulhi_epu16(_mm_packs_epi16(x, y), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f11(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_mulhi_epu16(y, _mm_packs_epi16(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f12(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_mulhi_epu16(_mm_packus_epi16(x, y), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f13(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_mulhi_epu16(x, _mm_packus_epi16(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f14(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_mulhi_epu16(_mm_packus_epi16(x, y), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f15(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_mulhi_epu16(y, _mm_packus_epi16(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f16(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_mulhi_epu16(_mm_hadd_epi16(x, y), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f17(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_mulhi_epu16(x, _mm_hadd_epi16(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f18(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_mulhi_epu16(_mm_hadd_epi16(x, y), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f19(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_mulhi_epu16(y, _mm_hadd_epi16(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f20(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_mulhi_epu16(_mm_hsub_epi16(x, y), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f21(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_mulhi_epu16(x, _mm_hsub_epi16(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f22(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_mulhi_epu16(_mm_hsub_epi16(x, y), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f23(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_mulhi_epu16(y, _mm_hsub_epi16(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f24(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_mulhi_epu16(_mm_hadds_epi16(x, y), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f25(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_mulhi_epu16(x, _mm_hadds_epi16(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f26(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_mulhi_epu16(_mm_hadds_epi16(x, y), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f27(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_mulhi_epu16(y, _mm_hadds_epi16(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f28(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_mulhi_epu16(_mm_madd_epi16(x, y), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f29(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_mulhi_epu16(x, _mm_madd_epi16(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f30(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_mulhi_epu16(_mm_madd_epi16(x, y), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f31(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_mulhi_epu16(y, _mm_madd_epi16(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f32(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_mulhi_epu16(_mm_unpacklo_epi16(x, y), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f33(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_mulhi_epu16(x, _mm_unpacklo_epi16(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f34(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_mulhi_epu16(_mm_unpacklo_epi16(x, y), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f35(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_mulhi_epu16(y, _mm_unpacklo_epi16(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f36(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_mulhi_epu16(_mm_unpackhi_epi16(x, y), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f37(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_mulhi_epu16(x, _mm_unpackhi_epi16(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f38(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_mulhi_epu16(_mm_unpackhi_epi16(x, y), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f39(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_mulhi_epu16(y, _mm_unpackhi_epi16(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f40(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_mulhi_epu16(_mm_blendv_epi8(x, y, _mm_cmpgt_epi16(x, y)), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f41(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_mulhi_epu16(x, _mm_blendv_epi8(x, y, _mm_cmpgt_epi16(x, y))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f42(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_mulhi_epu16(_mm_blendv_epi8(x, y, _mm_cmpgt_epi16(x, y)), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f43(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_mulhi_epu16(y, _mm_blendv_epi8(x, y, _mm_cmpgt_epi16(x, y))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f44(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_mulhi_epu16(_mm_blendv_epi8(y, x, _mm_cmpgt_epi16(x, y)), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f45(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_mulhi_epu16(x, _mm_blendv_epi8(y, x, _mm_cmpgt_epi16(x, y))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f46(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_mulhi_epu16(_mm_blendv_epi8(y, x, _mm_cmpgt_epi16(x, y)), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f47(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_mulhi_epu16(y, _mm_blendv_epi8(y, x, _mm_cmpgt_epi16(x, y))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f48(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_mulhi_epu16(_mm_or_si128(_mm_and_si128(_mm_cmpgt_epi16(x, y), x), _mm_andnot_si128(_mm_cmpgt_epi16(x, y), y)), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f49(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_mulhi_epu16(x, _mm_or_si128(_mm_and_si128(_mm_cmpgt_epi16(x, y), x), _mm_andnot_si128(_mm_cmpgt_epi16(x, y), y))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f50(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_mulhi_epu16(_mm_or_si128(_mm_and_si128(_mm_cmpgt_epi16(x, y), x), _mm_andnot_si128(_mm_cmpgt_epi16(x, y), y)), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f51(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_mulhi_epu16(y, _mm_or_si128(_mm_and_si128(_mm_cmpgt_epi16(x, y), x), _mm_andnot_si128(_mm_cmpgt_epi16(x, y), y))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f52(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_mulhi_epu16(_mm_blendv_epi8(x, y, _mm_cmpeq_epi16(x, y)), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f53(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_mulhi_epu16(x, _mm_blendv_epi8(x, y, _mm_cmpeq_epi16(x, y))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f54(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_mulhi_epu16(_mm_blendv_epi8(x, y, _mm_cmpeq_epi16(x, y)), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f55(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_mulhi_epu16(y, _mm_blendv_epi8(x, y, _mm_cmpeq_epi16(x, y))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f56(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_mulhi_epu16(_mm_blendv_epi8(y, x, _mm_cmpeq_epi16(x, y)), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f57(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_mulhi_epu16(x, _mm_blendv_epi8(y, x, _mm_cmpeq_epi16(x, y))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f58(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_mulhi_epu16(_mm_blendv_epi8(y, x, _mm_cmpeq_epi16(x, y)), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f59(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_mulhi_epu16(y, _mm_blendv_epi8(y, x, _mm_cmpeq_epi16(x, y))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f60(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_mulhi_epu16(_mm_or_si128(_mm_and_si128(_mm_cmpeq_epi16(x, y), x), _mm_andnot_si128(_mm_cmpeq_epi16(x, y), y)), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f61(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_mulhi_epu16(x, _mm_or_si128(_mm_and_si128(_mm_cmpeq_epi16(x, y), x), _mm_andnot_si128(_mm_cmpeq_epi16(x, y), y))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f62(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_mulhi_epu16(_mm_or_si128(_mm_and_si128(_mm_cmpeq_epi16(x, y), x), _mm_andnot_si128(_mm_cmpeq_epi16(x, y), y)), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f63(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_mulhi_epu16(y, _mm_or_si128(_mm_and_si128(_mm_cmpeq_epi16(x, y), x), _mm_andnot_si128(_mm_cmpeq_epi16(x, y), y))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f64(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_mulhi_epu16(_mm_mullo_epi16(x, y), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f65(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_mulhi_epu16(x, _mm_mullo_epi16(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f66(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_mulhi_epu16(_mm_mullo_epi16(x, y), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f67(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_mulhi_epu16(y, _mm_mullo_epi16(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f68(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_mulhi_epu16(_mm_mulhi_epi16(x, y), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f69(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_mulhi_epu16(x, _mm_mulhi_epi16(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f70(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_mulhi_epu16(_mm_mulhi_epi16(x, y), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f71(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_mulhi_epu16(y, _mm_mulhi_epi16(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f72(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_mulhi_epu16(_mm_mulhi_epu16(x, y), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f73(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_mulhi_epu16(x, _mm_mulhi_epu16(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f74(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_mulhi_epu16(_mm_mulhi_epu16(x, y), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f75(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_mulhi_epu16(y, _mm_mulhi_epu16(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f76(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi32(_mm_add_epi32(x, y), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f77(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi32(x, _mm_add_epi32(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f78(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi32(_mm_add_epi32(x, y), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f79(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi32(y, _mm_add_epi32(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f80(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi32(_mm_sub_epi32(x, y), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f81(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi32(x, _mm_sub_epi32(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f82(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi32(_mm_sub_epi32(x, y), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f83(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi32(y, _mm_sub_epi32(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f84(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi32(_mm_min_epi32(x, y), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f85(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi32(x, _mm_min_epi32(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f86(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi32(_mm_min_epi32(x, y), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f87(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi32(y, _mm_min_epi32(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f88(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi32(_mm_max_epi32(x, y), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f89(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi32(x, _mm_max_epi32(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f90(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi32(_mm_max_epi32(x, y), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f91(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi32(y, _mm_max_epi32(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f92(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi32(_mm_min_epu32(x, y), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f93(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi32(x, _mm_min_epu32(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f94(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi32(_mm_min_epu32(x, y), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f95(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi32(y, _mm_min_epu32(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f96(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi32(_mm_max_epu32(x, y), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f97(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi32(x, _mm_max_epu32(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f98(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi32(_mm_max_epu32(x, y), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f99(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi32(y, _mm_max_epu32(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f100(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi32(_mm_and_si128(x, y), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f101(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi32(x, _mm_and_si128(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f102(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi32(_mm_and_si128(x, y), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f103(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi32(y, _mm_and_si128(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f104(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi32(_mm_or_si128(x, y), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f105(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi32(x, _mm_or_si128(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f106(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi32(_mm_or_si128(x, y), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f107(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi32(y, _mm_or_si128(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f108(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi32(_mm_xor_si128(x, y), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f109(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi32(x, _mm_xor_si128(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f110(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi32(_mm_xor_si128(x, y), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f111(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi32(y, _mm_xor_si128(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f112(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi32(_mm_andnot_si128(x, y), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f113(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi32(x, _mm_andnot_si128(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f114(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi32(_mm_andnot_si128(x, y), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f115(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi32(y, _mm_andnot_si128(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f116(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi32(_mm_cmpeq_epi32(x, y), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f117(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi32(x, _mm_cmpeq_epi32(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f118(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi32(_mm_cmpeq_epi32(x, y), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f119(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi32(y, _mm_cmpeq_epi32(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f120(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi32(_mm_cmpgt_epi32(x, y), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f121(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi32(x, _mm_cmpgt_epi32(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f122(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi32(_mm_cmpgt_epi32(x, y), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f123(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi32(y, _mm_cmpgt_epi32(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f124(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi32(_mm_sign_epi32(x, y), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f125(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi32(x, _mm_sign_epi32(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f126(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi32(_mm_sign_epi32(x, y), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f127(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi32(y, _mm_sign_epi32(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f128(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi32(_mm_packs_epi32(x, y), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f129(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi32(x, _mm_packs_epi32(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f130(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi32(_mm_packs_epi32(x, y), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f131(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi32(y, _mm_packs_epi32(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f132(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi32(_mm_packus_epi32(x, y), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f133(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi32(x, _mm_packus_epi32(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f134(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi32(_mm_packus_epi32(x, y), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f135(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi32(y, _mm_packus_epi32(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f136(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi32(_mm_hadd_epi32(x, y), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f137(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi32(x, _mm_hadd_epi32(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f138(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi32(_mm_hadd_epi32(x, y), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f139(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi32(y, _mm_hadd_epi32(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f140(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi32(_mm_hsub_epi32(x, y), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f141(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi32(x, _mm_hsub_epi32(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f142(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi32(_mm_hsub_epi32(x, y), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f143(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi32(y, _mm_hsub_epi32(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f144(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi32(_mm_mul_epi32(x, y), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f145(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi32(x, _mm_mul_epi32(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f146(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi32(_mm_mul_epi32(x, y), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f147(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi32(y, _mm_mul_epi32(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f148(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi32(_mm_mul_epu32(x, y), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f149(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi32(x, _mm_mul_epu32(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f150(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi32(_mm_mul_epu32(x, y), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f151(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi32(y, _mm_mul_epu32(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f152(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi32(_mm_unpacklo_epi32(x, y), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f153(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi32(x, _mm_unpacklo_epi32(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f154(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi32(_mm_unpacklo_epi32(x, y), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f155(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi32(y, _mm_unpacklo_epi32(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f156(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi32(_mm_unpackhi_epi32(x, y), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f157(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi32(x, _mm_unpackhi_epi32(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f158(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi32(_mm_unpackhi_epi32(x, y), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f159(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi32(y, _mm_unpackhi_epi32(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f160(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi32(_mm_blendv_epi8(x, y, _mm_cmpgt_epi32(x, y)), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f161(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi32(x, _mm_blendv_epi8(x, y, _mm_cmpgt_epi32(x, y))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f162(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi32(_mm_blendv_epi8(x, y, _mm_cmpgt_epi32(x, y)), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f163(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi32(y, _mm_blendv_epi8(x, y, _mm_cmpgt_epi32(x, y))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f164(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi32(_mm_blendv_epi8(y, x, _mm_cmpgt_epi32(x, y)), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f165(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi32(x, _mm_blendv_epi8(y, x, _mm_cmpgt_epi32(x, y))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f166(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi32(_mm_blendv_epi8(y, x, _mm_cmpgt_epi32(x, y)), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f167(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi32(y, _mm_blendv_epi8(y, x, _mm_cmpgt_epi32(x, y))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f168(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi32(_mm_or_si128(_mm_and_si128(_mm_cmpgt_epi32(x, y), x), _mm_andnot_si128(_mm_cmpgt_epi32(x, y), y)), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f169(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi32(x, _mm_or_si128(_mm_and_si128(_mm_cmpgt_epi32(x, y), x), _mm_andnot_si128(_mm_cmpgt_epi32(x, y), y))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f170(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi32(_mm_or_si128(_mm_and_si128(_mm_cmpgt_epi32(x, y), x), _mm_andnot_si128(_mm_cmpgt_epi32(x, y), y)), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f171(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi32(y, _mm_or_si128(_mm_and_si128(_mm_cmpgt_epi32(x, y), x), _mm_andnot_si128(_mm_cmpgt_epi32(x, y), y))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f172(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi32(_mm_blendv_epi8(x, y, _mm_cmpeq_epi32(x, y)), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f173(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi32(x, _mm_blendv_epi8(x, y, _mm_cmpeq_epi32(x, y))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f174(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi32(_mm_blendv_epi8(x, y, _mm_cmpeq_epi32(x, y)), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f175(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi32(y, _mm_blendv_epi8(x, y, _mm_cmpeq_epi32(x, y))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f176(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi32(_mm_blendv_epi8(y, x, _mm_cmpeq_epi32(x, y)), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f177(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi32(x, _mm_blendv_epi8(y, x, _mm_cmpeq_epi32(x, y))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f178(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi32(_mm_blendv_epi8(y, x, _mm_cmpeq_epi32(x, y)), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f179(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi32(y, _mm_blendv_epi8(y, x, _mm_cmpeq_epi32(x, y))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f180(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi32(_mm_or_si128(_mm_and_si128(_mm_cmpeq_epi32(x, y), x), _mm_andnot_si128(_mm_cmpeq_epi32(x, y), y)), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f181(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi32(x, _mm_or_si128(_mm_and_si128(_mm_cmpeq_epi32(x, y), x), _mm_andnot_si128(_mm_cmpeq_epi32(x, y), y))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f182(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi32(_mm_or_si128(_mm_and_si128(_mm_cmpeq_epi32(x, y), x), _mm_andnot_si128(_mm_cmpeq_epi32(x, y), y)), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f183(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi32(y, _mm_or_si128(_mm_and_si128(_mm_cmpeq_epi32(x, y), x), _mm_andnot_si128(_mm_cmpeq_epi32(x, y), y))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f184(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi32(_mm_mullo_epi32(x, y), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f185(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi32(x, _mm_mullo_epi32(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f186(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi32(_mm_mullo_epi32(x, y), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f187(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi32(y, _mm_mullo_epi32(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f188(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi32(_mm_sllv_epi32(x, y), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f189(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi32(x, _mm_sllv_epi32(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f190(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi32(_mm_sllv_epi32(x, y), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f191(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi32(y, _mm_sllv_epi32(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f192(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi32(_mm_srlv_epi32(x, y), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f193(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi32(x, _mm_srlv_epi32(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f194(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi32(_mm_srlv_epi32(x, y), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f195(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi32(y, _mm_srlv_epi32(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f196(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi32(_mm_srav_epi32(x, y), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f197(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi32(x, _mm_srav_epi32(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f198(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi32(_mm_srav_epi32(x, y), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f199(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi32(y, _mm_srav_epi32(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f200(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi32(_mm_add_epi32(x, y), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f201(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi32(x, _mm_add_epi32(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f202(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi32(_mm_add_epi32(x, y), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f203(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi32(y, _mm_add_epi32(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f204(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi32(_mm_sub_epi32(x, y), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f205(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi32(x, _mm_sub_epi32(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f206(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi32(_mm_sub_epi32(x, y), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f207(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi32(y, _mm_sub_epi32(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f208(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi32(_mm_min_epi32(x, y), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f209(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi32(x, _mm_min_epi32(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f210(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi32(_mm_min_epi32(x, y), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f211(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi32(y, _mm_min_epi32(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f212(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi32(_mm_max_epi32(x, y), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f213(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi32(x, _mm_max_epi32(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f214(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi32(_mm_max_epi32(x, y), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f215(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi32(y, _mm_max_epi32(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f216(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi32(_mm_min_epu32(x, y), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f217(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi32(x, _mm_min_epu32(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f218(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi32(_mm_min_epu32(x, y), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f219(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi32(y, _mm_min_epu32(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f220(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi32(_mm_max_epu32(x, y), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f221(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi32(x, _mm_max_epu32(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f222(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi32(_mm_max_epu32(x, y), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f223(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi32(y, _mm_max_epu32(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f224(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi32(_mm_and_si128(x, y), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f225(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi32(x, _mm_and_si128(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f226(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi32(_mm_and_si128(x, y), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f227(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi32(y, _mm_and_si128(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f228(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi32(_mm_or_si128(x, y), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f229(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi32(x, _mm_or_si128(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f230(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi32(_mm_or_si128(x, y), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f231(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi32(y, _mm_or_si128(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f232(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi32(_mm_xor_si128(x, y), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f233(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi32(x, _mm_xor_si128(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f234(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi32(_mm_xor_si128(x, y), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f235(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi32(y, _mm_xor_si128(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f236(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi32(_mm_andnot_si128(x, y), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f237(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi32(x, _mm_andnot_si128(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f238(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi32(_mm_andnot_si128(x, y), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f239(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi32(y, _mm_andnot_si128(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f240(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi32(_mm_cmpeq_epi32(x, y), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f241(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi32(x, _mm_cmpeq_epi32(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f242(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi32(_mm_cmpeq_epi32(x, y), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f243(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi32(y, _mm_cmpeq_epi32(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f244(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi32(_mm_cmpgt_epi32(x, y), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f245(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi32(x, _mm_cmpgt_epi32(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f246(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi32(_mm_cmpgt_epi32(x, y), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f247(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi32(y, _mm_cmpgt_epi32(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f248(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi32(_mm_sign_epi32(x, y), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f249(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi32(x, _mm_sign_epi32(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f250(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi32(_mm_sign_epi32(x, y), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f251(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi32(y, _mm_sign_epi32(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f252(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi32(_mm_packs_epi32(x, y), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f253(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi32(x, _mm_packs_epi32(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f254(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi32(_mm_packs_epi32(x, y), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f255(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi32(y, _mm_packs_epi32(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f256(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi32(_mm_packus_epi32(x, y), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f257(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi32(x, _mm_packus_epi32(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f258(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi32(_mm_packus_epi32(x, y), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f259(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi32(y, _mm_packus_epi32(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f260(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi32(_mm_hadd_epi32(x, y), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f261(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi32(x, _mm_hadd_epi32(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f262(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi32(_mm_hadd_epi32(x, y), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f263(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi32(y, _mm_hadd_epi32(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f264(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi32(_mm_hsub_epi32(x, y), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f265(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi32(x, _mm_hsub_epi32(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f266(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi32(_mm_hsub_epi32(x, y), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f267(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi32(y, _mm_hsub_epi32(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f268(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi32(_mm_mul_epi32(x, y), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f269(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi32(x, _mm_mul_epi32(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f270(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi32(_mm_mul_epi32(x, y), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f271(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi32(y, _mm_mul_epi32(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f272(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi32(_mm_mul_epu32(x, y), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f273(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi32(x, _mm_mul_epu32(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f274(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi32(_mm_mul_epu32(x, y), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f275(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi32(y, _mm_mul_epu32(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f276(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi32(_mm_unpacklo_epi32(x, y), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f277(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi32(x, _mm_unpacklo_epi32(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f278(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi32(_mm_unpacklo_epi32(x, y), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f279(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi32(y, _mm_unpacklo_epi32(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f280(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi32(_mm_unpackhi_epi32(x, y), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f281(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi32(x, _mm_unpackhi_epi32(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f282(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi32(_mm_unpackhi_epi32(x, y), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f283(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi32(y, _mm_unpackhi_epi32(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f284(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi32(_mm_blendv_epi8(x, y, _mm_cmpgt_epi32(x, y)), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f285(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi32(x, _mm_blendv_epi8(x, y, _mm_cmpgt_epi32(x, y))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f286(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi32(_mm_blendv_epi8(x, y, _mm_cmpgt_epi32(x, y)), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f287(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi32(y, _mm_blendv_epi8(x, y, _mm_cmpgt_epi32(x, y))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f288(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi32(_mm_blendv_epi8(y, x, _mm_cmpgt_epi32(x, y)), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f289(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi32(x, _mm_blendv_epi8(y, x, _mm_cmpgt_epi32(x, y))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f290(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi32(_mm_blendv_epi8(y, x, _mm_cmpgt_epi32(x, y)), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f291(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi32(y, _mm_blendv_epi8(y, x, _mm_cmpgt_epi32(x, y))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f292(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi32(_mm_or_si128(_mm_and_si128(_mm_cmpgt_epi32(x, y), x), _mm_andnot_si128(_mm_cmpgt_epi32(x, y), y)), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f293(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi32(x, _mm_or_si128(_mm_and_si128(_mm_cmpgt_epi32(x, y), x), _mm_andnot_si128(_mm_cmpgt_epi32(x, y), y))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f294(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi32(_mm_or_si128(_mm_and_si128(_mm_cmpgt_epi32(x, y), x), _mm_andnot_si128(_mm_cmpgt_epi32(x, y), y)), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f295(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi32(y, _mm_or_si128(_mm_and_si128(_mm_cmpgt_epi32(x, y), x), _mm_andnot_si128(_mm_cmpgt_epi32(x, y), y))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f296(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi32(_mm_blendv_epi8(x, y, _mm_cmpeq_epi32(x, y)), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f297(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi32(x, _mm_blendv_epi8(x, y, _mm_cmpeq_epi32(x, y))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f298(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi32(_mm_blendv_epi8(x, y, _mm_cmpeq_epi32(x, y)), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f299(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi32(y, _mm_blendv_epi8(x, y, _mm_cmpeq_epi32(x, y))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f300(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi32(_mm_blendv_epi8(y, x, _mm_cmpeq_epi32(x, y)), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f301(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi32(x, _mm_blendv_epi8(y, x, _mm_cmpeq_epi32(x, y))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f302(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi32(_mm_blendv_epi8(y, x, _mm_cmpeq_epi32(x, y)), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f303(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi32(y, _mm_blendv_epi8(y, x, _mm_cmpeq_epi32(x, y))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f304(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi32(_mm_or_si128(_mm_and_si128(_mm_cmpeq_epi32(x, y), x), _mm_andnot_si128(_mm_cmpeq_epi32(x, y), y)), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f305(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi32(x, _mm_or_si128(_mm_and_si128(_mm_cmpeq_epi32(x, y), x), _mm_andnot_si128(_mm_cmpeq_epi32(x, y), y))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f306(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi32(_mm_or_si128(_mm_and_si128(_mm_cmpeq_epi32(x, y), x), _mm_andnot_si128(_mm_cmpeq_epi32(x, y), y)), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f307(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi32(y, _mm_or_si128(_mm_and_si128(_mm_cmpeq_epi32(x, y), x), _mm_andnot_si128(_mm_cmpeq_epi32(x, y), y))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f308(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi32(_mm_mullo_epi32(x, y), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f309(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi32(x, _mm_mullo_epi32(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f310(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi32(_mm_mullo_epi32(x, y), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f311(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi32(y, _mm_mullo_epi32(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f312(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi32(_mm_sllv_epi32(x, y), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f313(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi32(x, _mm_sllv_epi32(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f314(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi32(_mm_sllv_epi32(x, y), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f315(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi32(y, _mm_sllv_epi32(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f316(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi32(_mm_srlv_epi32(x, y), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f317(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi32(x, _mm_srlv_epi32(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f318(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi32(_mm_srlv_epi32(x, y), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f319(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi32(y, _mm_srlv_epi32(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f320(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi32(_mm_srav_epi32(x, y), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f321(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi32(x, _mm_srav_epi32(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f322(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi32(_mm_srav_epi32(x, y), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f323(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi32(y, _mm_srav_epi32(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f324(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi64(_mm_add_epi64(x, y), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f325(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi64(x, _mm_add_epi64(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f326(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi64(_mm_add_epi64(x, y), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f327(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi64(y, _mm_add_epi64(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f328(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi64(_mm_sub_epi64(x, y), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f329(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi64(x, _mm_sub_epi64(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f330(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi64(_mm_sub_epi64(x, y), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f331(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi64(y, _mm_sub_epi64(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f332(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi64(_mm_and_si128(x, y), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f333(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi64(x, _mm_and_si128(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f334(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi64(_mm_and_si128(x, y), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f335(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi64(y, _mm_and_si128(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f336(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi64(_mm_or_si128(x, y), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f337(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi64(x, _mm_or_si128(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f338(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi64(_mm_or_si128(x, y), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f339(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi64(y, _mm_or_si128(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f340(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi64(_mm_xor_si128(x, y), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f341(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi64(x, _mm_xor_si128(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f342(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi64(_mm_xor_si128(x, y), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f343(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi64(y, _mm_xor_si128(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f344(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi64(_mm_andnot_si128(x, y), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f345(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi64(x, _mm_andnot_si128(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f346(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi64(_mm_andnot_si128(x, y), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f347(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi64(y, _mm_andnot_si128(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f348(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi64(_mm_cmpeq_epi64(x, y), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f349(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi64(x, _mm_cmpeq_epi64(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f350(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi64(_mm_cmpeq_epi64(x, y), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f351(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi64(y, _mm_cmpeq_epi64(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f352(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi64(_mm_cmpgt_epi64(x, y), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f353(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi64(x, _mm_cmpgt_epi64(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f354(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi64(_mm_cmpgt_epi64(x, y), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f355(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi64(y, _mm_cmpgt_epi64(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f356(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi64(_mm_unpacklo_epi64(x, y), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f357(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi64(x, _mm_unpacklo_epi64(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f358(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi64(_mm_unpacklo_epi64(x, y), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f359(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi64(y, _mm_unpacklo_epi64(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f360(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi64(_mm_unpackhi_epi64(x, y), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f361(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi64(x, _mm_unpackhi_epi64(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f362(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi64(_mm_unpackhi_epi64(x, y), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f363(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi64(y, _mm_unpackhi_epi64(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f364(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi64(_mm_blendv_epi8(x, y, _mm_cmpgt_epi64(x, y)), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f365(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi64(x, _mm_blendv_epi8(x, y, _mm_cmpgt_epi64(x, y))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f366(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi64(_mm_blendv_epi8(x, y, _mm_cmpgt_epi64(x, y)), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f367(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi64(y, _mm_blendv_epi8(x, y, _mm_cmpgt_epi64(x, y))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f368(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi64(_mm_blendv_epi8(y, x, _mm_cmpgt_epi64(x, y)), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f369(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi64(x, _mm_blendv_epi8(y, x, _mm_cmpgt_epi64(x, y))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f370(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi64(_mm_blendv_epi8(y, x, _mm_cmpgt_epi64(x, y)), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f371(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi64(y, _mm_blendv_epi8(y, x, _mm_cmpgt_epi64(x, y))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f372(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi64(_mm_or_si128(_mm_and_si128(_mm_cmpgt_epi64(x, y), x), _mm_andnot_si128(_mm_cmpgt_epi64(x, y), y)), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f373(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi64(x, _mm_or_si128(_mm_and_si128(_mm_cmpgt_epi64(x, y), x), _mm_andnot_si128(_mm_cmpgt_epi64(x, y), y))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f374(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi64(_mm_or_si128(_mm_and_si128(_mm_cmpgt_epi64(x, y), x), _mm_andnot_si128(_mm_cmpgt_epi64(x, y), y)), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f375(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi64(y, _mm_or_si128(_mm_and_si128(_mm_cmpgt_epi64(x, y), x), _mm_andnot_si128(_mm_cmpgt_epi64(x, y), y))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f376(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi64(_mm_blendv_epi8(x, y, _mm_cmpeq_epi64(x, y)), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f377(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi64(x, _mm_blendv_epi8(x, y, _mm_cmpeq_epi64(x, y))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f378(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi64(_mm_blendv_epi8(x, y, _mm_cmpeq_epi64(x, y)), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f379(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi64(y, _mm_blendv_epi8(x, y, _mm_cmpeq_epi64(x, y))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f380(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi64(_mm_blendv_epi8(y, x, _mm_cmpeq_epi64(x, y)), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f381(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi64(x, _mm_blendv_epi8(y, x, _mm_cmpeq_epi64(x, y))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f382(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi64(_mm_blendv_epi8(y, x, _mm_cmpeq_epi64(x, y)), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f383(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi64(y, _mm_blendv_epi8(y, x, _mm_cmpeq_epi64(x, y))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f384(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi64(_mm_or_si128(_mm_and_si128(_mm_cmpeq_epi64(x, y), x), _mm_andnot_si128(_mm_cmpeq_epi64(x, y), y)), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f385(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi64(x, _mm_or_si128(_mm_and_si128(_mm_cmpeq_epi64(x, y), x), _mm_andnot_si128(_mm_cmpeq_epi64(x, y), y))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f386(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi64(_mm_or_si128(_mm_and_si128(_mm_cmpeq_epi64(x, y), x), _mm_andnot_si128(_mm_cmpeq_epi64(x, y), y)), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f387(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi64(y, _mm_or_si128(_mm_and_si128(_mm_cmpeq_epi64(x, y), x), _mm_andnot_si128(_mm_cmpeq_epi64(x, y), y))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f388(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi64(_mm_sllv_epi64(x, y), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f389(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi64(x, _mm_sllv_epi64(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f390(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi64(_mm_sllv_epi64(x, y), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f391(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi64(y, _mm_sllv_epi64(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f392(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi64(_mm_srlv_epi64(x, y), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f393(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi64(x, _mm_srlv_epi64(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f394(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi64(_mm_srlv_epi64(x, y), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f395(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_sllv_epi64(y, _mm_srlv_epi64(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f396(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi64(_mm_add_epi64(x, y), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f397(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi64(x, _mm_add_epi64(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f398(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi64(_mm_add_epi64(x, y), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f399(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi64(y, _mm_add_epi64(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f400(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi64(_mm_sub_epi64(x, y), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f401(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi64(x, _mm_sub_epi64(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f402(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi64(_mm_sub_epi64(x, y), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f403(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi64(y, _mm_sub_epi64(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f404(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi64(_mm_and_si128(x, y), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f405(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi64(x, _mm_and_si128(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f406(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi64(_mm_and_si128(x, y), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f407(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi64(y, _mm_and_si128(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f408(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi64(_mm_or_si128(x, y), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f409(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi64(x, _mm_or_si128(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f410(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi64(_mm_or_si128(x, y), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f411(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi64(y, _mm_or_si128(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f412(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi64(_mm_xor_si128(x, y), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f413(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi64(x, _mm_xor_si128(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f414(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi64(_mm_xor_si128(x, y), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f415(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi64(y, _mm_xor_si128(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f416(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi64(_mm_andnot_si128(x, y), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f417(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi64(x, _mm_andnot_si128(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f418(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi64(_mm_andnot_si128(x, y), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f419(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi64(y, _mm_andnot_si128(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f420(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi64(_mm_cmpeq_epi64(x, y), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f421(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi64(x, _mm_cmpeq_epi64(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f422(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi64(_mm_cmpeq_epi64(x, y), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f423(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi64(y, _mm_cmpeq_epi64(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f424(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi64(_mm_cmpgt_epi64(x, y), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f425(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi64(x, _mm_cmpgt_epi64(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f426(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi64(_mm_cmpgt_epi64(x, y), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f427(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi64(y, _mm_cmpgt_epi64(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f428(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi64(_mm_unpacklo_epi64(x, y), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f429(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi64(x, _mm_unpacklo_epi64(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f430(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi64(_mm_unpacklo_epi64(x, y), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f431(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi64(y, _mm_unpacklo_epi64(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f432(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi64(_mm_unpackhi_epi64(x, y), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f433(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi64(x, _mm_unpackhi_epi64(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f434(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi64(_mm_unpackhi_epi64(x, y), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f435(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi64(y, _mm_unpackhi_epi64(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f436(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi64(_mm_blendv_epi8(x, y, _mm_cmpgt_epi64(x, y)), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f437(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi64(x, _mm_blendv_epi8(x, y, _mm_cmpgt_epi64(x, y))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f438(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi64(_mm_blendv_epi8(x, y, _mm_cmpgt_epi64(x, y)), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f439(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi64(y, _mm_blendv_epi8(x, y, _mm_cmpgt_epi64(x, y))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f440(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi64(_mm_blendv_epi8(y, x, _mm_cmpgt_epi64(x, y)), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f441(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi64(x, _mm_blendv_epi8(y, x, _mm_cmpgt_epi64(x, y))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f442(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi64(_mm_blendv_epi8(y, x, _mm_cmpgt_epi64(x, y)), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f443(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi64(y, _mm_blendv_epi8(y, x, _mm_cmpgt_epi64(x, y))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f444(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi64(_mm_or_si128(_mm_and_si128(_mm_cmpgt_epi64(x, y), x), _mm_andnot_si128(_mm_cmpgt_epi64(x, y), y)), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f445(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi64(x, _mm_or_si128(_mm_and_si128(_mm_cmpgt_epi64(x, y), x), _mm_andnot_si128(_mm_cmpgt_epi64(x, y), y))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f446(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi64(_mm_or_si128(_mm_and_si128(_mm_cmpgt_epi64(x, y), x), _mm_andnot_si128(_mm_cmpgt_epi64(x, y), y)), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f447(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi64(y, _mm_or_si128(_mm_and_si128(_mm_cmpgt_epi64(x, y), x), _mm_andnot_si128(_mm_cmpgt_epi64(x, y), y))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f448(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi64(_mm_blendv_epi8(x, y, _mm_cmpeq_epi64(x, y)), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f449(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi64(x, _mm_blendv_epi8(x, y, _mm_cmpeq_epi64(x, y))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f450(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi64(_mm_blendv_epi8(x, y, _mm_cmpeq_epi64(x, y)), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f451(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi64(y, _mm_blendv_epi8(x, y, _mm_cmpeq_epi64(x, y))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f452(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi64(_mm_blendv_epi8(y, x, _mm_cmpeq_epi64(x, y)), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f453(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi64(x, _mm_blendv_epi8(y, x, _mm_cmpeq_epi64(x, y))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f454(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi64(_mm_blendv_epi8(y, x, _mm_cmpeq_epi64(x, y)), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f455(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi64(y, _mm_blendv_epi8(y, x, _mm_cmpeq_epi64(x, y))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f456(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi64(_mm_or_si128(_mm_and_si128(_mm_cmpeq_epi64(x, y), x), _mm_andnot_si128(_mm_cmpeq_epi64(x, y), y)), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f457(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi64(x, _mm_or_si128(_mm_and_si128(_mm_cmpeq_epi64(x, y), x), _mm_andnot_si128(_mm_cmpeq_epi64(x, y), y))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f458(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi64(_mm_or_si128(_mm_and_si128(_mm_cmpeq_epi64(x, y), x), _mm_andnot_si128(_mm_cmpeq_epi64(x, y), y)), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f459(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi64(y, _mm_or_si128(_mm_and_si128(_mm_cmpeq_epi64(x, y), x), _mm_andnot_si128(_mm_cmpeq_epi64(x, y), y))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f460(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi64(_mm_sllv_epi64(x, y), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f461(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi64(x, _mm_sllv_epi64(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f462(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi64(_mm_sllv_epi64(x, y), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f463(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi64(y, _mm_sllv_epi64(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f464(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi64(_mm_srlv_epi64(x, y), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f465(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi64(x, _mm_srlv_epi64(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f466(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi64(_mm_srlv_epi64(x, y), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f467(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srlv_epi64(y, _mm_srlv_epi64(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f468(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srav_epi32(_mm_add_epi32(x, y), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f469(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srav_epi32(x, _mm_add_epi32(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f470(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srav_epi32(_mm_add_epi32(x, y), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f471(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srav_epi32(y, _mm_add_epi32(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f472(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srav_epi32(_mm_sub_epi32(x, y), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f473(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srav_epi32(x, _mm_sub_epi32(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f474(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srav_epi32(_mm_sub_epi32(x, y), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f475(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srav_epi32(y, _mm_sub_epi32(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f476(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srav_epi32(_mm_min_epi32(x, y), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f477(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srav_epi32(x, _mm_min_epi32(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f478(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srav_epi32(_mm_min_epi32(x, y), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f479(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srav_epi32(y, _mm_min_epi32(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f480(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srav_epi32(_mm_max_epi32(x, y), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f481(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srav_epi32(x, _mm_max_epi32(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f482(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srav_epi32(_mm_max_epi32(x, y), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f483(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srav_epi32(y, _mm_max_epi32(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f484(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srav_epi32(_mm_min_epu32(x, y), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f485(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srav_epi32(x, _mm_min_epu32(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f486(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srav_epi32(_mm_min_epu32(x, y), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f487(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srav_epi32(y, _mm_min_epu32(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f488(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srav_epi32(_mm_max_epu32(x, y), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f489(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srav_epi32(x, _mm_max_epu32(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f490(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srav_epi32(_mm_max_epu32(x, y), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f491(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srav_epi32(y, _mm_max_epu32(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f492(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srav_epi32(_mm_and_si128(x, y), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f493(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srav_epi32(x, _mm_and_si128(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f494(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srav_epi32(_mm_and_si128(x, y), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f495(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srav_epi32(y, _mm_and_si128(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f496(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srav_epi32(_mm_or_si128(x, y), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f497(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srav_epi32(x, _mm_or_si128(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f498(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srav_epi32(_mm_or_si128(x, y), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f499(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srav_epi32(y, _mm_or_si128(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f500(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srav_epi32(_mm_xor_si128(x, y), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f501(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srav_epi32(x, _mm_xor_si128(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f502(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srav_epi32(_mm_xor_si128(x, y), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f503(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srav_epi32(y, _mm_xor_si128(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f504(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srav_epi32(_mm_andnot_si128(x, y), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f505(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srav_epi32(x, _mm_andnot_si128(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f506(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srav_epi32(_mm_andnot_si128(x, y), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f507(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srav_epi32(y, _mm_andnot_si128(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f508(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srav_epi32(_mm_cmpeq_epi32(x, y), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f509(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srav_epi32(x, _mm_cmpeq_epi32(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f510(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srav_epi32(_mm_cmpeq_epi32(x, y), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f511(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srav_epi32(y, _mm_cmpeq_epi32(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f512(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srav_epi32(_mm_cmpgt_epi32(x, y), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f513(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srav_epi32(x, _mm_cmpgt_epi32(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f514(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srav_epi32(_mm_cmpgt_epi32(x, y), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f515(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srav_epi32(y, _mm_cmpgt_epi32(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f516(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srav_epi32(_mm_sign_epi32(x, y), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f517(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srav_epi32(x, _mm_sign_epi32(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f518(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srav_epi32(_mm_sign_epi32(x, y), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f519(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srav_epi32(y, _mm_sign_epi32(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f520(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srav_epi32(_mm_packs_epi32(x, y), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f521(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srav_epi32(x, _mm_packs_epi32(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f522(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srav_epi32(_mm_packs_epi32(x, y), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f523(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srav_epi32(y, _mm_packs_epi32(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f524(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srav_epi32(_mm_packus_epi32(x, y), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f525(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srav_epi32(x, _mm_packus_epi32(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f526(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srav_epi32(_mm_packus_epi32(x, y), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f527(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srav_epi32(y, _mm_packus_epi32(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f528(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srav_epi32(_mm_hadd_epi32(x, y), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f529(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srav_epi32(x, _mm_hadd_epi32(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f530(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srav_epi32(_mm_hadd_epi32(x, y), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f531(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srav_epi32(y, _mm_hadd_epi32(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f532(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srav_epi32(_mm_hsub_epi32(x, y), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f533(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srav_epi32(x, _mm_hsub_epi32(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f534(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srav_epi32(_mm_hsub_epi32(x, y), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f535(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srav_epi32(y, _mm_hsub_epi32(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f536(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srav_epi32(_mm_mul_epi32(x, y), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f537(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srav_epi32(x, _mm_mul_epi32(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f538(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srav_epi32(_mm_mul_epi32(x, y), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f539(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srav_epi32(y, _mm_mul_epi32(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f540(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srav_epi32(_mm_mul_epu32(x, y), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f541(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srav_epi32(x, _mm_mul_epu32(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f542(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srav_epi32(_mm_mul_epu32(x, y), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f543(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srav_epi32(y, _mm_mul_epu32(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f544(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srav_epi32(_mm_unpacklo_epi32(x, y), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f545(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srav_epi32(x, _mm_unpacklo_epi32(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f546(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srav_epi32(_mm_unpacklo_epi32(x, y), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f547(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srav_epi32(y, _mm_unpacklo_epi32(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f548(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srav_epi32(_mm_unpackhi_epi32(x, y), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f549(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srav_epi32(x, _mm_unpackhi_epi32(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f550(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srav_epi32(_mm_unpackhi_epi32(x, y), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f551(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srav_epi32(y, _mm_unpackhi_epi32(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f552(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srav_epi32(_mm_blendv_epi8(x, y, _mm_cmpgt_epi32(x, y)), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f553(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srav_epi32(x, _mm_blendv_epi8(x, y, _mm_cmpgt_epi32(x, y))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f554(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srav_epi32(_mm_blendv_epi8(x, y, _mm_cmpgt_epi32(x, y)), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f555(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srav_epi32(y, _mm_blendv_epi8(x, y, _mm_cmpgt_epi32(x, y))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f556(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srav_epi32(_mm_blendv_epi8(y, x, _mm_cmpgt_epi32(x, y)), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f557(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srav_epi32(x, _mm_blendv_epi8(y, x, _mm_cmpgt_epi32(x, y))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f558(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srav_epi32(_mm_blendv_epi8(y, x, _mm_cmpgt_epi32(x, y)), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f559(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srav_epi32(y, _mm_blendv_epi8(y, x, _mm_cmpgt_epi32(x, y))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f560(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srav_epi32(_mm_or_si128(_mm_and_si128(_mm_cmpgt_epi32(x, y), x), _mm_andnot_si128(_mm_cmpgt_epi32(x, y), y)), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f561(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srav_epi32(x, _mm_or_si128(_mm_and_si128(_mm_cmpgt_epi32(x, y), x), _mm_andnot_si128(_mm_cmpgt_epi32(x, y), y))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f562(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srav_epi32(_mm_or_si128(_mm_and_si128(_mm_cmpgt_epi32(x, y), x), _mm_andnot_si128(_mm_cmpgt_epi32(x, y), y)), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f563(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srav_epi32(y, _mm_or_si128(_mm_and_si128(_mm_cmpgt_epi32(x, y), x), _mm_andnot_si128(_mm_cmpgt_epi32(x, y), y))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f564(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srav_epi32(_mm_blendv_epi8(x, y, _mm_cmpeq_epi32(x, y)), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f565(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srav_epi32(x, _mm_blendv_epi8(x, y, _mm_cmpeq_epi32(x, y))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f566(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srav_epi32(_mm_blendv_epi8(x, y, _mm_cmpeq_epi32(x, y)), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f567(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srav_epi32(y, _mm_blendv_epi8(x, y, _mm_cmpeq_epi32(x, y))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f568(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srav_epi32(_mm_blendv_epi8(y, x, _mm_cmpeq_epi32(x, y)), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f569(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srav_epi32(x, _mm_blendv_epi8(y, x, _mm_cmpeq_epi32(x, y))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f570(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srav_epi32(_mm_blendv_epi8(y, x, _mm_cmpeq_epi32(x, y)), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f571(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srav_epi32(y, _mm_blendv_epi8(y, x, _mm_cmpeq_epi32(x, y))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f572(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srav_epi32(_mm_or_si128(_mm_and_si128(_mm_cmpeq_epi32(x, y), x), _mm_andnot_si128(_mm_cmpeq_epi32(x, y), y)), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f573(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srav_epi32(x, _mm_or_si128(_mm_and_si128(_mm_cmpeq_epi32(x, y), x), _mm_andnot_si128(_mm_cmpeq_epi32(x, y), y))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f574(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srav_epi32(_mm_or_si128(_mm_and_si128(_mm_cmpeq_epi32(x, y), x), _mm_andnot_si128(_mm_cmpeq_epi32(x, y), y)), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f575(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srav_epi32(y, _mm_or_si128(_mm_and_si128(_mm_cmpeq_epi32(x, y), x), _mm_andnot_si128(_mm_cmpeq_epi32(x, y), y))); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f576(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srav_epi32(_mm_mullo_epi32(x, y), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f577(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srav_epi32(x, _mm_mullo_epi32(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f578(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srav_epi32(_mm_mullo_epi32(x, y), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f579(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srav_epi32(y, _mm_mullo_epi32(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f580(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srav_epi32(_mm_sllv_epi32(x, y), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f581(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srav_epi32(x, _mm_sllv_epi32(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f582(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srav_epi32(_mm_sllv_epi32(x, y), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f583(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srav_epi32(y, _mm_sllv_epi32(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f584(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srav_epi32(_mm_srlv_epi32(x, y), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f585(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srav_epi32(x, _mm_srlv_epi32(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f586(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srav_epi32(_mm_srlv_epi32(x, y), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f587(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srav_epi32(y, _mm_srlv_epi32(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f588(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srav_epi32(_mm_srav_epi32(x, y), y); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f589(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srav_epi32(x, _mm_srav_epi32(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f590(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srav_epi32(_mm_srav_epi32(x, y), x); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f591(const void* px, const void* py, void* po) { const __m128i x = _mm_loadu_si128((const __m128i*)px); const __m128i y = _mm_loadu_si128((const __m128i*)py); (void)y; const __m128i r = _mm_srav_epi32(y, _mm_srav_epi32(x, y)); _mm_storeu_si128((__m128i*)po, r); }
static NOINLINE void f592(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_sqrt_ps(_mm_sqrt_ps(x)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f593(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_sqrt_ps(_mm_xor_ps(x, _mm_set1_ps(-0.0f))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f594(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_sqrt_ps(_mm_andnot_ps(_mm_set1_ps(-0.0f), x)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f595(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_sqrt_ps(_mm_sub_ps(_mm_setzero_ps(), x)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f596(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_sqrt_ps(_mm_mul_ps(x, _mm_set1_ps(-1.0f))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f597(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_sqrt_ps(_mm_floor_ps(x)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f598(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_sqrt_ps(_mm_ceil_ps(x)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f599(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_sqrt_ps(_mm_round_ps(x, _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f600(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_sqrt_ps(_mm_permute_ps(x, 0x1b)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f601(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_sqrt_ps(_mm_permute_ps(x, 0x39)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f602(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_sqrt_ps(_mm_permute_ps(x, 0x93)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f603(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_sqrt_ps(_mm_permute_ps(x, 0x4e)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f604(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_sqrt_ps(_mm_cvtepi32_ps(_mm_cvttps_epi32(x))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f605(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_sqrt_ps(_mm_cvtepi32_ps(_mm_cvtps_epi32(x))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f606(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_sqrt_ps(_mm_movehdup_ps(x)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f607(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(_mm_sqrt_ps(x), _mm_set1_ps(-0.0f)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f608(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(_mm_xor_ps(x, _mm_set1_ps(-0.0f)), _mm_set1_ps(-0.0f)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f609(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(_mm_andnot_ps(_mm_set1_ps(-0.0f), x), _mm_set1_ps(-0.0f)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f610(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(_mm_sub_ps(_mm_setzero_ps(), x), _mm_set1_ps(-0.0f)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f611(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(_mm_mul_ps(x, _mm_set1_ps(-1.0f)), _mm_set1_ps(-0.0f)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f612(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(_mm_floor_ps(x), _mm_set1_ps(-0.0f)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f613(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(_mm_ceil_ps(x), _mm_set1_ps(-0.0f)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f614(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(_mm_round_ps(x, _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC), _mm_set1_ps(-0.0f)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f615(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(_mm_permute_ps(x, 0x1b), _mm_set1_ps(-0.0f)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f616(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(_mm_permute_ps(x, 0x39), _mm_set1_ps(-0.0f)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f617(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(_mm_permute_ps(x, 0x93), _mm_set1_ps(-0.0f)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f618(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(_mm_permute_ps(x, 0x4e), _mm_set1_ps(-0.0f)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f619(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(_mm_cvtepi32_ps(_mm_cvttps_epi32(x)), _mm_set1_ps(-0.0f)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f620(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(_mm_cvtepi32_ps(_mm_cvtps_epi32(x)), _mm_set1_ps(-0.0f)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f621(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(_mm_movehdup_ps(x), _mm_set1_ps(-0.0f)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f622(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_andnot_ps(_mm_set1_ps(-0.0f), _mm_sqrt_ps(x)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f623(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_andnot_ps(_mm_set1_ps(-0.0f), _mm_xor_ps(x, _mm_set1_ps(-0.0f))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f624(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_andnot_ps(_mm_set1_ps(-0.0f), _mm_andnot_ps(_mm_set1_ps(-0.0f), x)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f625(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_andnot_ps(_mm_set1_ps(-0.0f), _mm_sub_ps(_mm_setzero_ps(), x)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f626(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_andnot_ps(_mm_set1_ps(-0.0f), _mm_mul_ps(x, _mm_set1_ps(-1.0f))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f627(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_andnot_ps(_mm_set1_ps(-0.0f), _mm_floor_ps(x)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f628(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_andnot_ps(_mm_set1_ps(-0.0f), _mm_ceil_ps(x)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f629(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_andnot_ps(_mm_set1_ps(-0.0f), _mm_round_ps(x, _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f630(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_andnot_ps(_mm_set1_ps(-0.0f), _mm_permute_ps(x, 0x1b)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f631(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_andnot_ps(_mm_set1_ps(-0.0f), _mm_permute_ps(x, 0x39)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f632(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_andnot_ps(_mm_set1_ps(-0.0f), _mm_permute_ps(x, 0x93)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f633(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_andnot_ps(_mm_set1_ps(-0.0f), _mm_permute_ps(x, 0x4e)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f634(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_andnot_ps(_mm_set1_ps(-0.0f), _mm_cvtepi32_ps(_mm_cvttps_epi32(x))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f635(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_andnot_ps(_mm_set1_ps(-0.0f), _mm_cvtepi32_ps(_mm_cvtps_epi32(x))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f636(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_andnot_ps(_mm_set1_ps(-0.0f), _mm_movehdup_ps(x)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f637(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_sub_ps(_mm_setzero_ps(), _mm_sqrt_ps(x)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f638(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_sub_ps(_mm_setzero_ps(), _mm_xor_ps(x, _mm_set1_ps(-0.0f))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f639(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_sub_ps(_mm_setzero_ps(), _mm_andnot_ps(_mm_set1_ps(-0.0f), x)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f640(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_sub_ps(_mm_setzero_ps(), _mm_sub_ps(_mm_setzero_ps(), x)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f641(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_sub_ps(_mm_setzero_ps(), _mm_mul_ps(x, _mm_set1_ps(-1.0f))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f642(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_sub_ps(_mm_setzero_ps(), _mm_floor_ps(x)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f643(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_sub_ps(_mm_setzero_ps(), _mm_ceil_ps(x)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f644(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_sub_ps(_mm_setzero_ps(), _mm_round_ps(x, _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f645(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_sub_ps(_mm_setzero_ps(), _mm_permute_ps(x, 0x1b)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f646(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_sub_ps(_mm_setzero_ps(), _mm_permute_ps(x, 0x39)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f647(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_sub_ps(_mm_setzero_ps(), _mm_permute_ps(x, 0x93)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f648(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_sub_ps(_mm_setzero_ps(), _mm_permute_ps(x, 0x4e)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f649(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_sub_ps(_mm_setzero_ps(), _mm_cvtepi32_ps(_mm_cvttps_epi32(x))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f650(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_sub_ps(_mm_setzero_ps(), _mm_cvtepi32_ps(_mm_cvtps_epi32(x))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f651(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_sub_ps(_mm_setzero_ps(), _mm_movehdup_ps(x)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f652(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_mul_ps(_mm_sqrt_ps(x), _mm_set1_ps(-1.0f)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f653(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_mul_ps(_mm_xor_ps(x, _mm_set1_ps(-0.0f)), _mm_set1_ps(-1.0f)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f654(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_mul_ps(_mm_andnot_ps(_mm_set1_ps(-0.0f), x), _mm_set1_ps(-1.0f)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f655(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_mul_ps(_mm_sub_ps(_mm_setzero_ps(), x), _mm_set1_ps(-1.0f)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f656(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_mul_ps(_mm_mul_ps(x, _mm_set1_ps(-1.0f)), _mm_set1_ps(-1.0f)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f657(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_mul_ps(_mm_floor_ps(x), _mm_set1_ps(-1.0f)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f658(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_mul_ps(_mm_ceil_ps(x), _mm_set1_ps(-1.0f)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f659(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_mul_ps(_mm_round_ps(x, _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC), _mm_set1_ps(-1.0f)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f660(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_mul_ps(_mm_permute_ps(x, 0x1b), _mm_set1_ps(-1.0f)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f661(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_mul_ps(_mm_permute_ps(x, 0x39), _mm_set1_ps(-1.0f)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f662(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_mul_ps(_mm_permute_ps(x, 0x93), _mm_set1_ps(-1.0f)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f663(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_mul_ps(_mm_permute_ps(x, 0x4e), _mm_set1_ps(-1.0f)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f664(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_mul_ps(_mm_cvtepi32_ps(_mm_cvttps_epi32(x)), _mm_set1_ps(-1.0f)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f665(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_mul_ps(_mm_cvtepi32_ps(_mm_cvtps_epi32(x)), _mm_set1_ps(-1.0f)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f666(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_mul_ps(_mm_movehdup_ps(x), _mm_set1_ps(-1.0f)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f667(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_floor_ps(_mm_sqrt_ps(x)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f668(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_floor_ps(_mm_xor_ps(x, _mm_set1_ps(-0.0f))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f669(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_floor_ps(_mm_andnot_ps(_mm_set1_ps(-0.0f), x)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f670(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_floor_ps(_mm_sub_ps(_mm_setzero_ps(), x)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f671(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_floor_ps(_mm_mul_ps(x, _mm_set1_ps(-1.0f))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f672(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_floor_ps(_mm_floor_ps(x)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f673(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_floor_ps(_mm_ceil_ps(x)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f674(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_floor_ps(_mm_round_ps(x, _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f675(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_floor_ps(_mm_permute_ps(x, 0x1b)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f676(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_floor_ps(_mm_permute_ps(x, 0x39)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f677(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_floor_ps(_mm_permute_ps(x, 0x93)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f678(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_floor_ps(_mm_permute_ps(x, 0x4e)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f679(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_floor_ps(_mm_cvtepi32_ps(_mm_cvttps_epi32(x))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f680(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_floor_ps(_mm_cvtepi32_ps(_mm_cvtps_epi32(x))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f681(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_floor_ps(_mm_movehdup_ps(x)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f682(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_ceil_ps(_mm_sqrt_ps(x)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f683(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_ceil_ps(_mm_xor_ps(x, _mm_set1_ps(-0.0f))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f684(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_ceil_ps(_mm_andnot_ps(_mm_set1_ps(-0.0f), x)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f685(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_ceil_ps(_mm_sub_ps(_mm_setzero_ps(), x)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f686(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_ceil_ps(_mm_mul_ps(x, _mm_set1_ps(-1.0f))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f687(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_ceil_ps(_mm_floor_ps(x)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f688(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_ceil_ps(_mm_ceil_ps(x)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f689(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_ceil_ps(_mm_round_ps(x, _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f690(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_ceil_ps(_mm_permute_ps(x, 0x1b)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f691(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_ceil_ps(_mm_permute_ps(x, 0x39)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f692(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_ceil_ps(_mm_permute_ps(x, 0x93)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f693(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_ceil_ps(_mm_permute_ps(x, 0x4e)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f694(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_ceil_ps(_mm_cvtepi32_ps(_mm_cvttps_epi32(x))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f695(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_ceil_ps(_mm_cvtepi32_ps(_mm_cvtps_epi32(x))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f696(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_ceil_ps(_mm_movehdup_ps(x)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f697(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_round_ps(_mm_sqrt_ps(x), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f698(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_round_ps(_mm_xor_ps(x, _mm_set1_ps(-0.0f)), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f699(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_round_ps(_mm_andnot_ps(_mm_set1_ps(-0.0f), x), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f700(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_round_ps(_mm_sub_ps(_mm_setzero_ps(), x), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f701(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_round_ps(_mm_mul_ps(x, _mm_set1_ps(-1.0f)), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f702(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_round_ps(_mm_floor_ps(x), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f703(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_round_ps(_mm_ceil_ps(x), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f704(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_round_ps(_mm_round_ps(x, _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f705(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_round_ps(_mm_permute_ps(x, 0x1b), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f706(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_round_ps(_mm_permute_ps(x, 0x39), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f707(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_round_ps(_mm_permute_ps(x, 0x93), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f708(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_round_ps(_mm_permute_ps(x, 0x4e), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f709(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_round_ps(_mm_cvtepi32_ps(_mm_cvttps_epi32(x)), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f710(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_round_ps(_mm_cvtepi32_ps(_mm_cvtps_epi32(x)), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f711(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_round_ps(_mm_movehdup_ps(x), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f712(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_permute_ps(_mm_sqrt_ps(x), 0x1b); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f713(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_permute_ps(_mm_xor_ps(x, _mm_set1_ps(-0.0f)), 0x1b); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f714(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_permute_ps(_mm_andnot_ps(_mm_set1_ps(-0.0f), x), 0x1b); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f715(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_permute_ps(_mm_sub_ps(_mm_setzero_ps(), x), 0x1b); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f716(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_permute_ps(_mm_mul_ps(x, _mm_set1_ps(-1.0f)), 0x1b); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f717(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_permute_ps(_mm_floor_ps(x), 0x1b); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f718(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_permute_ps(_mm_ceil_ps(x), 0x1b); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f719(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_permute_ps(_mm_round_ps(x, _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC), 0x1b); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f720(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_permute_ps(_mm_permute_ps(x, 0x1b), 0x1b); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f721(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_permute_ps(_mm_permute_ps(x, 0x39), 0x1b); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f722(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_permute_ps(_mm_permute_ps(x, 0x93), 0x1b); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f723(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_permute_ps(_mm_permute_ps(x, 0x4e), 0x1b); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f724(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_permute_ps(_mm_cvtepi32_ps(_mm_cvttps_epi32(x)), 0x1b); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f725(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_permute_ps(_mm_cvtepi32_ps(_mm_cvtps_epi32(x)), 0x1b); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f726(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_permute_ps(_mm_movehdup_ps(x), 0x1b); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f727(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_permute_ps(_mm_sqrt_ps(x), 0x39); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f728(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_permute_ps(_mm_xor_ps(x, _mm_set1_ps(-0.0f)), 0x39); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f729(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_permute_ps(_mm_andnot_ps(_mm_set1_ps(-0.0f), x), 0x39); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f730(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_permute_ps(_mm_sub_ps(_mm_setzero_ps(), x), 0x39); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f731(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_permute_ps(_mm_mul_ps(x, _mm_set1_ps(-1.0f)), 0x39); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f732(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_permute_ps(_mm_floor_ps(x), 0x39); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f733(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_permute_ps(_mm_ceil_ps(x), 0x39); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f734(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_permute_ps(_mm_round_ps(x, _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC), 0x39); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f735(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_permute_ps(_mm_permute_ps(x, 0x1b), 0x39); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f736(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_permute_ps(_mm_permute_ps(x, 0x39), 0x39); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f737(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_permute_ps(_mm_permute_ps(x, 0x93), 0x39); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f738(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_permute_ps(_mm_permute_ps(x, 0x4e), 0x39); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f739(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_permute_ps(_mm_cvtepi32_ps(_mm_cvttps_epi32(x)), 0x39); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f740(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_permute_ps(_mm_cvtepi32_ps(_mm_cvtps_epi32(x)), 0x39); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f741(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_permute_ps(_mm_movehdup_ps(x), 0x39); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f742(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_permute_ps(_mm_sqrt_ps(x), 0x93); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f743(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_permute_ps(_mm_xor_ps(x, _mm_set1_ps(-0.0f)), 0x93); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f744(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_permute_ps(_mm_andnot_ps(_mm_set1_ps(-0.0f), x), 0x93); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f745(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_permute_ps(_mm_sub_ps(_mm_setzero_ps(), x), 0x93); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f746(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_permute_ps(_mm_mul_ps(x, _mm_set1_ps(-1.0f)), 0x93); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f747(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_permute_ps(_mm_floor_ps(x), 0x93); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f748(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_permute_ps(_mm_ceil_ps(x), 0x93); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f749(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_permute_ps(_mm_round_ps(x, _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC), 0x93); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f750(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_permute_ps(_mm_permute_ps(x, 0x1b), 0x93); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f751(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_permute_ps(_mm_permute_ps(x, 0x39), 0x93); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f752(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_permute_ps(_mm_permute_ps(x, 0x93), 0x93); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f753(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_permute_ps(_mm_permute_ps(x, 0x4e), 0x93); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f754(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_permute_ps(_mm_cvtepi32_ps(_mm_cvttps_epi32(x)), 0x93); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f755(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_permute_ps(_mm_cvtepi32_ps(_mm_cvtps_epi32(x)), 0x93); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f756(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_permute_ps(_mm_movehdup_ps(x), 0x93); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f757(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_permute_ps(_mm_sqrt_ps(x), 0x4e); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f758(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_permute_ps(_mm_xor_ps(x, _mm_set1_ps(-0.0f)), 0x4e); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f759(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_permute_ps(_mm_andnot_ps(_mm_set1_ps(-0.0f), x), 0x4e); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f760(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_permute_ps(_mm_sub_ps(_mm_setzero_ps(), x), 0x4e); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f761(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_permute_ps(_mm_mul_ps(x, _mm_set1_ps(-1.0f)), 0x4e); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f762(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_permute_ps(_mm_floor_ps(x), 0x4e); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f763(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_permute_ps(_mm_ceil_ps(x), 0x4e); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f764(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_permute_ps(_mm_round_ps(x, _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC), 0x4e); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f765(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_permute_ps(_mm_permute_ps(x, 0x1b), 0x4e); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f766(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_permute_ps(_mm_permute_ps(x, 0x39), 0x4e); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f767(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_permute_ps(_mm_permute_ps(x, 0x93), 0x4e); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f768(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_permute_ps(_mm_permute_ps(x, 0x4e), 0x4e); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f769(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_permute_ps(_mm_cvtepi32_ps(_mm_cvttps_epi32(x)), 0x4e); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f770(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_permute_ps(_mm_cvtepi32_ps(_mm_cvtps_epi32(x)), 0x4e); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f771(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_permute_ps(_mm_movehdup_ps(x), 0x4e); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f772(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_cvtepi32_ps(_mm_cvttps_epi32(_mm_sqrt_ps(x))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f773(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_cvtepi32_ps(_mm_cvttps_epi32(_mm_xor_ps(x, _mm_set1_ps(-0.0f)))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f774(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_cvtepi32_ps(_mm_cvttps_epi32(_mm_andnot_ps(_mm_set1_ps(-0.0f), x))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f775(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_cvtepi32_ps(_mm_cvttps_epi32(_mm_sub_ps(_mm_setzero_ps(), x))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f776(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_cvtepi32_ps(_mm_cvttps_epi32(_mm_mul_ps(x, _mm_set1_ps(-1.0f)))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f777(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_cvtepi32_ps(_mm_cvttps_epi32(_mm_floor_ps(x))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f778(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_cvtepi32_ps(_mm_cvttps_epi32(_mm_ceil_ps(x))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f779(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_cvtepi32_ps(_mm_cvttps_epi32(_mm_round_ps(x, _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f780(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_cvtepi32_ps(_mm_cvttps_epi32(_mm_permute_ps(x, 0x1b))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f781(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_cvtepi32_ps(_mm_cvttps_epi32(_mm_permute_ps(x, 0x39))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f782(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_cvtepi32_ps(_mm_cvttps_epi32(_mm_permute_ps(x, 0x93))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f783(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_cvtepi32_ps(_mm_cvttps_epi32(_mm_permute_ps(x, 0x4e))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f784(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_cvtepi32_ps(_mm_cvttps_epi32(_mm_cvtepi32_ps(_mm_cvttps_epi32(x)))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f785(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_cvtepi32_ps(_mm_cvttps_epi32(_mm_cvtepi32_ps(_mm_cvtps_epi32(x)))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f786(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_cvtepi32_ps(_mm_cvttps_epi32(_mm_movehdup_ps(x))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f787(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_cvtepi32_ps(_mm_cvtps_epi32(_mm_sqrt_ps(x))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f788(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_cvtepi32_ps(_mm_cvtps_epi32(_mm_xor_ps(x, _mm_set1_ps(-0.0f)))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f789(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_cvtepi32_ps(_mm_cvtps_epi32(_mm_andnot_ps(_mm_set1_ps(-0.0f), x))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f790(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_cvtepi32_ps(_mm_cvtps_epi32(_mm_sub_ps(_mm_setzero_ps(), x))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f791(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_cvtepi32_ps(_mm_cvtps_epi32(_mm_mul_ps(x, _mm_set1_ps(-1.0f)))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f792(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_cvtepi32_ps(_mm_cvtps_epi32(_mm_floor_ps(x))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f793(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_cvtepi32_ps(_mm_cvtps_epi32(_mm_ceil_ps(x))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f794(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_cvtepi32_ps(_mm_cvtps_epi32(_mm_round_ps(x, _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f795(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_cvtepi32_ps(_mm_cvtps_epi32(_mm_permute_ps(x, 0x1b))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f796(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_cvtepi32_ps(_mm_cvtps_epi32(_mm_permute_ps(x, 0x39))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f797(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_cvtepi32_ps(_mm_cvtps_epi32(_mm_permute_ps(x, 0x93))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f798(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_cvtepi32_ps(_mm_cvtps_epi32(_mm_permute_ps(x, 0x4e))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f799(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_cvtepi32_ps(_mm_cvtps_epi32(_mm_cvtepi32_ps(_mm_cvttps_epi32(x)))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f800(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_cvtepi32_ps(_mm_cvtps_epi32(_mm_cvtepi32_ps(_mm_cvtps_epi32(x)))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f801(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_cvtepi32_ps(_mm_cvtps_epi32(_mm_movehdup_ps(x))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f802(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_movehdup_ps(_mm_sqrt_ps(x)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f803(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_movehdup_ps(_mm_xor_ps(x, _mm_set1_ps(-0.0f))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f804(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_movehdup_ps(_mm_andnot_ps(_mm_set1_ps(-0.0f), x)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f805(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_movehdup_ps(_mm_sub_ps(_mm_setzero_ps(), x)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f806(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_movehdup_ps(_mm_mul_ps(x, _mm_set1_ps(-1.0f))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f807(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_movehdup_ps(_mm_floor_ps(x)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f808(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_movehdup_ps(_mm_ceil_ps(x)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f809(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_movehdup_ps(_mm_round_ps(x, _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f810(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_movehdup_ps(_mm_permute_ps(x, 0x1b)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f811(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_movehdup_ps(_mm_permute_ps(x, 0x39)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f812(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_movehdup_ps(_mm_permute_ps(x, 0x93)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f813(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_movehdup_ps(_mm_permute_ps(x, 0x4e)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f814(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_movehdup_ps(_mm_cvtepi32_ps(_mm_cvttps_epi32(x))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f815(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_movehdup_ps(_mm_cvtepi32_ps(_mm_cvtps_epi32(x))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f816(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_movehdup_ps(_mm_movehdup_ps(x)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f817(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_sqrt_ps(_mm_sqrt_ps(_mm_sqrt_ps(x))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f818(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(_mm_xor_ps(_mm_xor_ps(x, _mm_set1_ps(-0.0f)), _mm_set1_ps(-0.0f)), _mm_set1_ps(-0.0f)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f819(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_andnot_ps(_mm_set1_ps(-0.0f), _mm_andnot_ps(_mm_set1_ps(-0.0f), _mm_andnot_ps(_mm_set1_ps(-0.0f), x))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f820(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_sub_ps(_mm_setzero_ps(), _mm_sub_ps(_mm_setzero_ps(), _mm_sub_ps(_mm_setzero_ps(), x))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f821(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_mul_ps(_mm_mul_ps(_mm_mul_ps(x, _mm_set1_ps(-1.0f)), _mm_set1_ps(-1.0f)), _mm_set1_ps(-1.0f)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f822(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_floor_ps(_mm_floor_ps(_mm_floor_ps(x))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f823(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_ceil_ps(_mm_ceil_ps(_mm_ceil_ps(x))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f824(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_round_ps(_mm_round_ps(_mm_round_ps(x, _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f825(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_permute_ps(_mm_permute_ps(_mm_permute_ps(x, 0x1b), 0x1b), 0x1b); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f826(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_permute_ps(_mm_permute_ps(_mm_permute_ps(x, 0x39), 0x39), 0x39); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f827(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_permute_ps(_mm_permute_ps(_mm_permute_ps(x, 0x93), 0x93), 0x93); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f828(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_permute_ps(_mm_permute_ps(_mm_permute_ps(x, 0x4e), 0x4e), 0x4e); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f829(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_cvtepi32_ps(_mm_cvttps_epi32(_mm_cvtepi32_ps(_mm_cvttps_epi32(_mm_cvtepi32_ps(_mm_cvttps_epi32(x)))))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f830(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_cvtepi32_ps(_mm_cvtps_epi32(_mm_cvtepi32_ps(_mm_cvtps_epi32(_mm_cvtepi32_ps(_mm_cvtps_epi32(x)))))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f831(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_movehdup_ps(_mm_movehdup_ps(_mm_movehdup_ps(x))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f832(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_sqrt_ps(_mm_add_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f833(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_add_ps(_mm_sqrt_ps(x), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f834(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_add_ps(x, _mm_sqrt_ps(y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f835(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_add_ps(_mm_sqrt_ps(x), _mm_sqrt_ps(y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f836(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_add_ps(x, _mm_sqrt_ps(x)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f837(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_add_ps(_mm_sqrt_ps(x), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f838(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_sqrt_ps(_mm_sub_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f839(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_sub_ps(_mm_sqrt_ps(x), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f840(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_sub_ps(x, _mm_sqrt_ps(y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f841(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_sub_ps(_mm_sqrt_ps(x), _mm_sqrt_ps(y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f842(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_sub_ps(x, _mm_sqrt_ps(x)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f843(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_sub_ps(_mm_sqrt_ps(x), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f844(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_sqrt_ps(_mm_mul_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f845(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_mul_ps(_mm_sqrt_ps(x), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f846(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_mul_ps(x, _mm_sqrt_ps(y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f847(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_mul_ps(_mm_sqrt_ps(x), _mm_sqrt_ps(y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f848(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_mul_ps(x, _mm_sqrt_ps(x)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f849(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_mul_ps(_mm_sqrt_ps(x), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f850(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_sqrt_ps(_mm_div_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f851(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_div_ps(_mm_sqrt_ps(x), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f852(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_div_ps(x, _mm_sqrt_ps(y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f853(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_div_ps(_mm_sqrt_ps(x), _mm_sqrt_ps(y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f854(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_div_ps(x, _mm_sqrt_ps(x)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f855(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_div_ps(_mm_sqrt_ps(x), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f856(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_sqrt_ps(_mm_min_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f857(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_min_ps(_mm_sqrt_ps(x), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f858(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_min_ps(x, _mm_sqrt_ps(y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f859(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_min_ps(_mm_sqrt_ps(x), _mm_sqrt_ps(y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f860(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_min_ps(x, _mm_sqrt_ps(x)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f861(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_min_ps(_mm_sqrt_ps(x), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f862(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_sqrt_ps(_mm_max_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f863(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_max_ps(_mm_sqrt_ps(x), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f864(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_max_ps(x, _mm_sqrt_ps(y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f865(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_max_ps(_mm_sqrt_ps(x), _mm_sqrt_ps(y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f866(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_max_ps(x, _mm_sqrt_ps(x)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f867(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_max_ps(_mm_sqrt_ps(x), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f868(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_sqrt_ps(_mm_and_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f869(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_and_ps(_mm_sqrt_ps(x), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f870(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_and_ps(x, _mm_sqrt_ps(y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f871(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_and_ps(_mm_sqrt_ps(x), _mm_sqrt_ps(y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f872(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_and_ps(x, _mm_sqrt_ps(x)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f873(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_and_ps(_mm_sqrt_ps(x), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f874(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_sqrt_ps(_mm_or_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f875(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(_mm_sqrt_ps(x), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f876(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(x, _mm_sqrt_ps(y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f877(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(_mm_sqrt_ps(x), _mm_sqrt_ps(y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f878(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(x, _mm_sqrt_ps(x)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f879(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(_mm_sqrt_ps(x), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f880(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_sqrt_ps(_mm_xor_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f881(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(_mm_sqrt_ps(x), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f882(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(x, _mm_sqrt_ps(y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f883(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(_mm_sqrt_ps(x), _mm_sqrt_ps(y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f884(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(x, _mm_sqrt_ps(x)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f885(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(_mm_sqrt_ps(x), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f886(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_sqrt_ps(_mm_andnot_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f887(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_andnot_ps(_mm_sqrt_ps(x), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f888(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_andnot_ps(x, _mm_sqrt_ps(y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f889(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_andnot_ps(_mm_sqrt_ps(x), _mm_sqrt_ps(y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f890(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_andnot_ps(x, _mm_sqrt_ps(x)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f891(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_andnot_ps(_mm_sqrt_ps(x), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f892(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_sqrt_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f893(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_cmp_ps(_mm_sqrt_ps(x), y, _CMP_EQ_OQ); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f894(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_cmp_ps(x, _mm_sqrt_ps(y), _CMP_EQ_OQ); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f895(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_cmp_ps(_mm_sqrt_ps(x), _mm_sqrt_ps(y), _CMP_EQ_OQ); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f896(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_cmp_ps(x, _mm_sqrt_ps(x), _CMP_EQ_OQ); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f897(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_cmp_ps(_mm_sqrt_ps(x), x, _CMP_EQ_OQ); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f898(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_sqrt_ps(_mm_cmp_ps(x, y, _CMP_LT_OS)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f899(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_cmp_ps(_mm_sqrt_ps(x), y, _CMP_LT_OS); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f900(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_cmp_ps(x, _mm_sqrt_ps(y), _CMP_LT_OS); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f901(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_cmp_ps(_mm_sqrt_ps(x), _mm_sqrt_ps(y), _CMP_LT_OS); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f902(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_cmp_ps(x, _mm_sqrt_ps(x), _CMP_LT_OS); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f903(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_cmp_ps(_mm_sqrt_ps(x), x, _CMP_LT_OS); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f904(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_sqrt_ps(_mm_cmp_ps(x, y, _CMP_LE_OS)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f905(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_cmp_ps(_mm_sqrt_ps(x), y, _CMP_LE_OS); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f906(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_cmp_ps(x, _mm_sqrt_ps(y), _CMP_LE_OS); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f907(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_cmp_ps(_mm_sqrt_ps(x), _mm_sqrt_ps(y), _CMP_LE_OS); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f908(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_cmp_ps(x, _mm_sqrt_ps(x), _CMP_LE_OS); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f909(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_cmp_ps(_mm_sqrt_ps(x), x, _CMP_LE_OS); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f910(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_sqrt_ps(_mm_cmp_ps(x, y, _CMP_NEQ_UQ)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f911(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_cmp_ps(_mm_sqrt_ps(x), y, _CMP_NEQ_UQ); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f912(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_cmp_ps(x, _mm_sqrt_ps(y), _CMP_NEQ_UQ); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f913(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_cmp_ps(_mm_sqrt_ps(x), _mm_sqrt_ps(y), _CMP_NEQ_UQ); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f914(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_cmp_ps(x, _mm_sqrt_ps(x), _CMP_NEQ_UQ); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f915(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_cmp_ps(_mm_sqrt_ps(x), x, _CMP_NEQ_UQ); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f916(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_sqrt_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f917(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_cmp_ps(_mm_sqrt_ps(x), y, _CMP_UNORD_Q); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f918(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_cmp_ps(x, _mm_sqrt_ps(y), _CMP_UNORD_Q); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f919(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_cmp_ps(_mm_sqrt_ps(x), _mm_sqrt_ps(y), _CMP_UNORD_Q); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f920(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_cmp_ps(x, _mm_sqrt_ps(x), _CMP_UNORD_Q); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f921(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_cmp_ps(_mm_sqrt_ps(x), x, _CMP_UNORD_Q); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f922(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_sqrt_ps(_mm_cmp_ps(x, y, _CMP_NLT_US)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f923(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_cmp_ps(_mm_sqrt_ps(x), y, _CMP_NLT_US); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f924(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_cmp_ps(x, _mm_sqrt_ps(y), _CMP_NLT_US); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f925(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_cmp_ps(_mm_sqrt_ps(x), _mm_sqrt_ps(y), _CMP_NLT_US); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f926(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_cmp_ps(x, _mm_sqrt_ps(x), _CMP_NLT_US); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f927(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_cmp_ps(_mm_sqrt_ps(x), x, _CMP_NLT_US); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f928(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_sqrt_ps(_mm_cmp_ps(x, y, _CMP_GT_OS)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f929(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_cmp_ps(_mm_sqrt_ps(x), y, _CMP_GT_OS); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f930(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_cmp_ps(x, _mm_sqrt_ps(y), _CMP_GT_OS); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f931(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_cmp_ps(_mm_sqrt_ps(x), _mm_sqrt_ps(y), _CMP_GT_OS); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f932(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_cmp_ps(x, _mm_sqrt_ps(x), _CMP_GT_OS); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f933(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_cmp_ps(_mm_sqrt_ps(x), x, _CMP_GT_OS); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f934(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_sqrt_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LT_OS))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f935(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_blendv_ps(_mm_sqrt_ps(x), y, _mm_cmp_ps(_mm_sqrt_ps(x), y, _CMP_LT_OS)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f936(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_blendv_ps(x, _mm_sqrt_ps(y), _mm_cmp_ps(x, _mm_sqrt_ps(y), _CMP_LT_OS)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f937(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_blendv_ps(_mm_sqrt_ps(x), _mm_sqrt_ps(y), _mm_cmp_ps(_mm_sqrt_ps(x), _mm_sqrt_ps(y), _CMP_LT_OS)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f938(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_blendv_ps(x, _mm_sqrt_ps(x), _mm_cmp_ps(x, _mm_sqrt_ps(x), _CMP_LT_OS)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f939(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_blendv_ps(_mm_sqrt_ps(x), x, _mm_cmp_ps(_mm_sqrt_ps(x), x, _CMP_LT_OS)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f940(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_sqrt_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LT_OS))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f941(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_blendv_ps(y, _mm_sqrt_ps(x), _mm_cmp_ps(_mm_sqrt_ps(x), y, _CMP_LT_OS)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f942(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_blendv_ps(_mm_sqrt_ps(y), x, _mm_cmp_ps(x, _mm_sqrt_ps(y), _CMP_LT_OS)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f943(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_blendv_ps(_mm_sqrt_ps(y), _mm_sqrt_ps(x), _mm_cmp_ps(_mm_sqrt_ps(x), _mm_sqrt_ps(y), _CMP_LT_OS)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f944(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_blendv_ps(_mm_sqrt_ps(x), x, _mm_cmp_ps(x, _mm_sqrt_ps(x), _CMP_LT_OS)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f945(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_blendv_ps(x, _mm_sqrt_ps(x), _mm_cmp_ps(_mm_sqrt_ps(x), x, _CMP_LT_OS)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f946(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_sqrt_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), y))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f947(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(_mm_and_ps(_mm_cmp_ps(_mm_sqrt_ps(x), y, _CMP_LT_OS), _mm_sqrt_ps(x)), _mm_andnot_ps(_mm_cmp_ps(_mm_sqrt_ps(x), y, _CMP_LT_OS), y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f948(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, _mm_sqrt_ps(y), _CMP_LT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, _mm_sqrt_ps(y), _CMP_LT_OS), _mm_sqrt_ps(y))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f949(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(_mm_and_ps(_mm_cmp_ps(_mm_sqrt_ps(x), _mm_sqrt_ps(y), _CMP_LT_OS), _mm_sqrt_ps(x)), _mm_andnot_ps(_mm_cmp_ps(_mm_sqrt_ps(x), _mm_sqrt_ps(y), _CMP_LT_OS), _mm_sqrt_ps(y))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f950(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, _mm_sqrt_ps(x), _CMP_LT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, _mm_sqrt_ps(x), _CMP_LT_OS), _mm_sqrt_ps(x))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f951(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(_mm_and_ps(_mm_cmp_ps(_mm_sqrt_ps(x), x, _CMP_LT_OS), _mm_sqrt_ps(x)), _mm_andnot_ps(_mm_cmp_ps(_mm_sqrt_ps(x), x, _CMP_LT_OS), x)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f952(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_sqrt_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LE_OS))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f953(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_blendv_ps(_mm_sqrt_ps(x), y, _mm_cmp_ps(_mm_sqrt_ps(x), y, _CMP_LE_OS)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f954(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_blendv_ps(x, _mm_sqrt_ps(y), _mm_cmp_ps(x, _mm_sqrt_ps(y), _CMP_LE_OS)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f955(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_blendv_ps(_mm_sqrt_ps(x), _mm_sqrt_ps(y), _mm_cmp_ps(_mm_sqrt_ps(x), _mm_sqrt_ps(y), _CMP_LE_OS)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f956(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_blendv_ps(x, _mm_sqrt_ps(x), _mm_cmp_ps(x, _mm_sqrt_ps(x), _CMP_LE_OS)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f957(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_blendv_ps(_mm_sqrt_ps(x), x, _mm_cmp_ps(_mm_sqrt_ps(x), x, _CMP_LE_OS)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f958(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_sqrt_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LE_OS))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f959(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_blendv_ps(y, _mm_sqrt_ps(x), _mm_cmp_ps(_mm_sqrt_ps(x), y, _CMP_LE_OS)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f960(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_blendv_ps(_mm_sqrt_ps(y), x, _mm_cmp_ps(x, _mm_sqrt_ps(y), _CMP_LE_OS)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f961(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_blendv_ps(_mm_sqrt_ps(y), _mm_sqrt_ps(x), _mm_cmp_ps(_mm_sqrt_ps(x), _mm_sqrt_ps(y), _CMP_LE_OS)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f962(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_blendv_ps(_mm_sqrt_ps(x), x, _mm_cmp_ps(x, _mm_sqrt_ps(x), _CMP_LE_OS)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f963(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_blendv_ps(x, _mm_sqrt_ps(x), _mm_cmp_ps(_mm_sqrt_ps(x), x, _CMP_LE_OS)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f964(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_sqrt_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), y))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f965(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(_mm_and_ps(_mm_cmp_ps(_mm_sqrt_ps(x), y, _CMP_LE_OS), _mm_sqrt_ps(x)), _mm_andnot_ps(_mm_cmp_ps(_mm_sqrt_ps(x), y, _CMP_LE_OS), y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f966(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, _mm_sqrt_ps(y), _CMP_LE_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, _mm_sqrt_ps(y), _CMP_LE_OS), _mm_sqrt_ps(y))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f967(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(_mm_and_ps(_mm_cmp_ps(_mm_sqrt_ps(x), _mm_sqrt_ps(y), _CMP_LE_OS), _mm_sqrt_ps(x)), _mm_andnot_ps(_mm_cmp_ps(_mm_sqrt_ps(x), _mm_sqrt_ps(y), _CMP_LE_OS), _mm_sqrt_ps(y))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f968(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, _mm_sqrt_ps(x), _CMP_LE_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, _mm_sqrt_ps(x), _CMP_LE_OS), _mm_sqrt_ps(x))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f969(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(_mm_and_ps(_mm_cmp_ps(_mm_sqrt_ps(x), x, _CMP_LE_OS), _mm_sqrt_ps(x)), _mm_andnot_ps(_mm_cmp_ps(_mm_sqrt_ps(x), x, _CMP_LE_OS), x)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f970(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_sqrt_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_GT_OS))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f971(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_blendv_ps(_mm_sqrt_ps(x), y, _mm_cmp_ps(_mm_sqrt_ps(x), y, _CMP_GT_OS)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f972(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_blendv_ps(x, _mm_sqrt_ps(y), _mm_cmp_ps(x, _mm_sqrt_ps(y), _CMP_GT_OS)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f973(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_blendv_ps(_mm_sqrt_ps(x), _mm_sqrt_ps(y), _mm_cmp_ps(_mm_sqrt_ps(x), _mm_sqrt_ps(y), _CMP_GT_OS)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f974(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_blendv_ps(x, _mm_sqrt_ps(x), _mm_cmp_ps(x, _mm_sqrt_ps(x), _CMP_GT_OS)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f975(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_blendv_ps(_mm_sqrt_ps(x), x, _mm_cmp_ps(_mm_sqrt_ps(x), x, _CMP_GT_OS)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f976(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_sqrt_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_GT_OS))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f977(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_blendv_ps(y, _mm_sqrt_ps(x), _mm_cmp_ps(_mm_sqrt_ps(x), y, _CMP_GT_OS)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f978(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_blendv_ps(_mm_sqrt_ps(y), x, _mm_cmp_ps(x, _mm_sqrt_ps(y), _CMP_GT_OS)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f979(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_blendv_ps(_mm_sqrt_ps(y), _mm_sqrt_ps(x), _mm_cmp_ps(_mm_sqrt_ps(x), _mm_sqrt_ps(y), _CMP_GT_OS)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f980(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_blendv_ps(_mm_sqrt_ps(x), x, _mm_cmp_ps(x, _mm_sqrt_ps(x), _CMP_GT_OS)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f981(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_blendv_ps(x, _mm_sqrt_ps(x), _mm_cmp_ps(_mm_sqrt_ps(x), x, _CMP_GT_OS)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f982(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_sqrt_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), y))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f983(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(_mm_and_ps(_mm_cmp_ps(_mm_sqrt_ps(x), y, _CMP_GT_OS), _mm_sqrt_ps(x)), _mm_andnot_ps(_mm_cmp_ps(_mm_sqrt_ps(x), y, _CMP_GT_OS), y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f984(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, _mm_sqrt_ps(y), _CMP_GT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, _mm_sqrt_ps(y), _CMP_GT_OS), _mm_sqrt_ps(y))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f985(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(_mm_and_ps(_mm_cmp_ps(_mm_sqrt_ps(x), _mm_sqrt_ps(y), _CMP_GT_OS), _mm_sqrt_ps(x)), _mm_andnot_ps(_mm_cmp_ps(_mm_sqrt_ps(x), _mm_sqrt_ps(y), _CMP_GT_OS), _mm_sqrt_ps(y))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f986(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, _mm_sqrt_ps(x), _CMP_GT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, _mm_sqrt_ps(x), _CMP_GT_OS), _mm_sqrt_ps(x))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f987(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(_mm_and_ps(_mm_cmp_ps(_mm_sqrt_ps(x), x, _CMP_GT_OS), _mm_sqrt_ps(x)), _mm_andnot_ps(_mm_cmp_ps(_mm_sqrt_ps(x), x, _CMP_GT_OS), x)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f988(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_sqrt_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_NLT_US))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f989(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_blendv_ps(_mm_sqrt_ps(x), y, _mm_cmp_ps(_mm_sqrt_ps(x), y, _CMP_NLT_US)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f990(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_blendv_ps(x, _mm_sqrt_ps(y), _mm_cmp_ps(x, _mm_sqrt_ps(y), _CMP_NLT_US)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f991(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_blendv_ps(_mm_sqrt_ps(x), _mm_sqrt_ps(y), _mm_cmp_ps(_mm_sqrt_ps(x), _mm_sqrt_ps(y), _CMP_NLT_US)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f992(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_blendv_ps(x, _mm_sqrt_ps(x), _mm_cmp_ps(x, _mm_sqrt_ps(x), _CMP_NLT_US)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f993(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_blendv_ps(_mm_sqrt_ps(x), x, _mm_cmp_ps(_mm_sqrt_ps(x), x, _CMP_NLT_US)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f994(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_sqrt_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_NLT_US))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f995(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_blendv_ps(y, _mm_sqrt_ps(x), _mm_cmp_ps(_mm_sqrt_ps(x), y, _CMP_NLT_US)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f996(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_blendv_ps(_mm_sqrt_ps(y), x, _mm_cmp_ps(x, _mm_sqrt_ps(y), _CMP_NLT_US)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f997(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_blendv_ps(_mm_sqrt_ps(y), _mm_sqrt_ps(x), _mm_cmp_ps(_mm_sqrt_ps(x), _mm_sqrt_ps(y), _CMP_NLT_US)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f998(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_blendv_ps(_mm_sqrt_ps(x), x, _mm_cmp_ps(x, _mm_sqrt_ps(x), _CMP_NLT_US)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f999(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_blendv_ps(x, _mm_sqrt_ps(x), _mm_cmp_ps(_mm_sqrt_ps(x), x, _CMP_NLT_US)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1000(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_sqrt_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), y))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1001(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(_mm_and_ps(_mm_cmp_ps(_mm_sqrt_ps(x), y, _CMP_NLT_US), _mm_sqrt_ps(x)), _mm_andnot_ps(_mm_cmp_ps(_mm_sqrt_ps(x), y, _CMP_NLT_US), y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1002(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, _mm_sqrt_ps(y), _CMP_NLT_US), x), _mm_andnot_ps(_mm_cmp_ps(x, _mm_sqrt_ps(y), _CMP_NLT_US), _mm_sqrt_ps(y))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1003(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(_mm_and_ps(_mm_cmp_ps(_mm_sqrt_ps(x), _mm_sqrt_ps(y), _CMP_NLT_US), _mm_sqrt_ps(x)), _mm_andnot_ps(_mm_cmp_ps(_mm_sqrt_ps(x), _mm_sqrt_ps(y), _CMP_NLT_US), _mm_sqrt_ps(y))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1004(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, _mm_sqrt_ps(x), _CMP_NLT_US), x), _mm_andnot_ps(_mm_cmp_ps(x, _mm_sqrt_ps(x), _CMP_NLT_US), _mm_sqrt_ps(x))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1005(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(_mm_and_ps(_mm_cmp_ps(_mm_sqrt_ps(x), x, _CMP_NLT_US), _mm_sqrt_ps(x)), _mm_andnot_ps(_mm_cmp_ps(_mm_sqrt_ps(x), x, _CMP_NLT_US), x)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1006(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_sqrt_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_EQ_OQ))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1007(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_blendv_ps(_mm_sqrt_ps(x), y, _mm_cmp_ps(_mm_sqrt_ps(x), y, _CMP_EQ_OQ)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1008(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_blendv_ps(x, _mm_sqrt_ps(y), _mm_cmp_ps(x, _mm_sqrt_ps(y), _CMP_EQ_OQ)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1009(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_blendv_ps(_mm_sqrt_ps(x), _mm_sqrt_ps(y), _mm_cmp_ps(_mm_sqrt_ps(x), _mm_sqrt_ps(y), _CMP_EQ_OQ)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1010(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_blendv_ps(x, _mm_sqrt_ps(x), _mm_cmp_ps(x, _mm_sqrt_ps(x), _CMP_EQ_OQ)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1011(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_blendv_ps(_mm_sqrt_ps(x), x, _mm_cmp_ps(_mm_sqrt_ps(x), x, _CMP_EQ_OQ)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1012(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_sqrt_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_EQ_OQ))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1013(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_blendv_ps(y, _mm_sqrt_ps(x), _mm_cmp_ps(_mm_sqrt_ps(x), y, _CMP_EQ_OQ)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1014(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_blendv_ps(_mm_sqrt_ps(y), x, _mm_cmp_ps(x, _mm_sqrt_ps(y), _CMP_EQ_OQ)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1015(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_blendv_ps(_mm_sqrt_ps(y), _mm_sqrt_ps(x), _mm_cmp_ps(_mm_sqrt_ps(x), _mm_sqrt_ps(y), _CMP_EQ_OQ)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1016(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_blendv_ps(_mm_sqrt_ps(x), x, _mm_cmp_ps(x, _mm_sqrt_ps(x), _CMP_EQ_OQ)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1017(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_blendv_ps(x, _mm_sqrt_ps(x), _mm_cmp_ps(_mm_sqrt_ps(x), x, _CMP_EQ_OQ)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1018(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_sqrt_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), y))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1019(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(_mm_and_ps(_mm_cmp_ps(_mm_sqrt_ps(x), y, _CMP_EQ_OQ), _mm_sqrt_ps(x)), _mm_andnot_ps(_mm_cmp_ps(_mm_sqrt_ps(x), y, _CMP_EQ_OQ), y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1020(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, _mm_sqrt_ps(y), _CMP_EQ_OQ), x), _mm_andnot_ps(_mm_cmp_ps(x, _mm_sqrt_ps(y), _CMP_EQ_OQ), _mm_sqrt_ps(y))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1021(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(_mm_and_ps(_mm_cmp_ps(_mm_sqrt_ps(x), _mm_sqrt_ps(y), _CMP_EQ_OQ), _mm_sqrt_ps(x)), _mm_andnot_ps(_mm_cmp_ps(_mm_sqrt_ps(x), _mm_sqrt_ps(y), _CMP_EQ_OQ), _mm_sqrt_ps(y))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1022(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, _mm_sqrt_ps(x), _CMP_EQ_OQ), x), _mm_andnot_ps(_mm_cmp_ps(x, _mm_sqrt_ps(x), _CMP_EQ_OQ), _mm_sqrt_ps(x))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1023(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(_mm_and_ps(_mm_cmp_ps(_mm_sqrt_ps(x), x, _CMP_EQ_OQ), _mm_sqrt_ps(x)), _mm_andnot_ps(_mm_cmp_ps(_mm_sqrt_ps(x), x, _CMP_EQ_OQ), x)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1024(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_sqrt_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_UNORD_Q))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1025(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_blendv_ps(_mm_sqrt_ps(x), y, _mm_cmp_ps(_mm_sqrt_ps(x), y, _CMP_UNORD_Q)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1026(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_blendv_ps(x, _mm_sqrt_ps(y), _mm_cmp_ps(x, _mm_sqrt_ps(y), _CMP_UNORD_Q)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1027(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_blendv_ps(_mm_sqrt_ps(x), _mm_sqrt_ps(y), _mm_cmp_ps(_mm_sqrt_ps(x), _mm_sqrt_ps(y), _CMP_UNORD_Q)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1028(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_blendv_ps(x, _mm_sqrt_ps(x), _mm_cmp_ps(x, _mm_sqrt_ps(x), _CMP_UNORD_Q)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1029(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_blendv_ps(_mm_sqrt_ps(x), x, _mm_cmp_ps(_mm_sqrt_ps(x), x, _CMP_UNORD_Q)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1030(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_sqrt_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_UNORD_Q))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1031(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_blendv_ps(y, _mm_sqrt_ps(x), _mm_cmp_ps(_mm_sqrt_ps(x), y, _CMP_UNORD_Q)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1032(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_blendv_ps(_mm_sqrt_ps(y), x, _mm_cmp_ps(x, _mm_sqrt_ps(y), _CMP_UNORD_Q)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1033(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_blendv_ps(_mm_sqrt_ps(y), _mm_sqrt_ps(x), _mm_cmp_ps(_mm_sqrt_ps(x), _mm_sqrt_ps(y), _CMP_UNORD_Q)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1034(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_blendv_ps(_mm_sqrt_ps(x), x, _mm_cmp_ps(x, _mm_sqrt_ps(x), _CMP_UNORD_Q)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1035(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_blendv_ps(x, _mm_sqrt_ps(x), _mm_cmp_ps(_mm_sqrt_ps(x), x, _CMP_UNORD_Q)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1036(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_sqrt_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), y))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1037(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(_mm_and_ps(_mm_cmp_ps(_mm_sqrt_ps(x), y, _CMP_UNORD_Q), _mm_sqrt_ps(x)), _mm_andnot_ps(_mm_cmp_ps(_mm_sqrt_ps(x), y, _CMP_UNORD_Q), y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1038(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, _mm_sqrt_ps(y), _CMP_UNORD_Q), x), _mm_andnot_ps(_mm_cmp_ps(x, _mm_sqrt_ps(y), _CMP_UNORD_Q), _mm_sqrt_ps(y))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1039(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(_mm_and_ps(_mm_cmp_ps(_mm_sqrt_ps(x), _mm_sqrt_ps(y), _CMP_UNORD_Q), _mm_sqrt_ps(x)), _mm_andnot_ps(_mm_cmp_ps(_mm_sqrt_ps(x), _mm_sqrt_ps(y), _CMP_UNORD_Q), _mm_sqrt_ps(y))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1040(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, _mm_sqrt_ps(x), _CMP_UNORD_Q), x), _mm_andnot_ps(_mm_cmp_ps(x, _mm_sqrt_ps(x), _CMP_UNORD_Q), _mm_sqrt_ps(x))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1041(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(_mm_and_ps(_mm_cmp_ps(_mm_sqrt_ps(x), x, _CMP_UNORD_Q), _mm_sqrt_ps(x)), _mm_andnot_ps(_mm_cmp_ps(_mm_sqrt_ps(x), x, _CMP_UNORD_Q), x)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1042(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_sqrt_ps(_mm_unpacklo_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1043(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_unpacklo_ps(_mm_sqrt_ps(x), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1044(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_unpacklo_ps(x, _mm_sqrt_ps(y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1045(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_unpacklo_ps(_mm_sqrt_ps(x), _mm_sqrt_ps(y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1046(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_unpacklo_ps(x, _mm_sqrt_ps(x)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1047(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_unpacklo_ps(_mm_sqrt_ps(x), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1048(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_sqrt_ps(_mm_unpackhi_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1049(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_unpackhi_ps(_mm_sqrt_ps(x), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1050(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_unpackhi_ps(x, _mm_sqrt_ps(y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1051(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_unpackhi_ps(_mm_sqrt_ps(x), _mm_sqrt_ps(y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1052(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_unpackhi_ps(x, _mm_sqrt_ps(x)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1053(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_unpackhi_ps(_mm_sqrt_ps(x), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1054(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_sqrt_ps(_mm_hadd_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1055(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hadd_ps(_mm_sqrt_ps(x), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1056(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hadd_ps(x, _mm_sqrt_ps(y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1057(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hadd_ps(_mm_sqrt_ps(x), _mm_sqrt_ps(y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1058(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hadd_ps(x, _mm_sqrt_ps(x)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1059(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hadd_ps(_mm_sqrt_ps(x), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1060(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_sqrt_ps(_mm_hsub_ps(x, y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1061(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hsub_ps(_mm_sqrt_ps(x), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1062(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hsub_ps(x, _mm_sqrt_ps(y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1063(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hsub_ps(_mm_sqrt_ps(x), _mm_sqrt_ps(y)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1064(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hsub_ps(x, _mm_sqrt_ps(x)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1065(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_hsub_ps(_mm_sqrt_ps(x), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1066(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_sqrt_ps(_mm_shuffle_ps(x, y, 0x1b)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1067(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_sqrt_ps(x), y, 0x1b); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1068(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(x, _mm_sqrt_ps(y), 0x1b); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1069(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_sqrt_ps(x), _mm_sqrt_ps(y), 0x1b); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1070(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(x, _mm_sqrt_ps(x), 0x1b); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1071(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_sqrt_ps(x), x, 0x1b); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1072(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_sqrt_ps(_mm_shuffle_ps(x, y, 0x39)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1073(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_sqrt_ps(x), y, 0x39); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1074(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(x, _mm_sqrt_ps(y), 0x39); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1075(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_sqrt_ps(x), _mm_sqrt_ps(y), 0x39); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1076(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(x, _mm_sqrt_ps(x), 0x39); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1077(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_sqrt_ps(x), x, 0x39); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1078(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_sqrt_ps(_mm_shuffle_ps(x, y, 0x93)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1079(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_sqrt_ps(x), y, 0x93); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1080(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(x, _mm_sqrt_ps(y), 0x93); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1081(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_sqrt_ps(x), _mm_sqrt_ps(y), 0x93); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1082(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(x, _mm_sqrt_ps(x), 0x93); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1083(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_sqrt_ps(x), x, 0x93); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1084(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_sqrt_ps(_mm_shuffle_ps(x, y, 0x4e)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1085(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_sqrt_ps(x), y, 0x4e); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1086(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(x, _mm_sqrt_ps(y), 0x4e); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1087(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_sqrt_ps(x), _mm_sqrt_ps(y), 0x4e); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1088(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(x, _mm_sqrt_ps(x), 0x4e); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1089(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_shuffle_ps(_mm_sqrt_ps(x), x, 0x4e); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1090(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(_mm_add_ps(x, y), _mm_set1_ps(-0.0f)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1091(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_add_ps(_mm_xor_ps(x, _mm_set1_ps(-0.0f)), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1092(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_add_ps(x, _mm_xor_ps(y, _mm_set1_ps(-0.0f))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1093(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_add_ps(_mm_xor_ps(x, _mm_set1_ps(-0.0f)), _mm_xor_ps(y, _mm_set1_ps(-0.0f))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1094(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_add_ps(x, _mm_xor_ps(x, _mm_set1_ps(-0.0f))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1095(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_add_ps(_mm_xor_ps(x, _mm_set1_ps(-0.0f)), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1096(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(_mm_sub_ps(x, y), _mm_set1_ps(-0.0f)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1097(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_sub_ps(_mm_xor_ps(x, _mm_set1_ps(-0.0f)), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1098(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_sub_ps(x, _mm_xor_ps(y, _mm_set1_ps(-0.0f))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1099(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_sub_ps(_mm_xor_ps(x, _mm_set1_ps(-0.0f)), _mm_xor_ps(y, _mm_set1_ps(-0.0f))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1100(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_sub_ps(x, _mm_xor_ps(x, _mm_set1_ps(-0.0f))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1101(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_sub_ps(_mm_xor_ps(x, _mm_set1_ps(-0.0f)), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1102(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(_mm_mul_ps(x, y), _mm_set1_ps(-0.0f)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1103(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_mul_ps(_mm_xor_ps(x, _mm_set1_ps(-0.0f)), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1104(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_mul_ps(x, _mm_xor_ps(y, _mm_set1_ps(-0.0f))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1105(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_mul_ps(_mm_xor_ps(x, _mm_set1_ps(-0.0f)), _mm_xor_ps(y, _mm_set1_ps(-0.0f))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1106(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_mul_ps(x, _mm_xor_ps(x, _mm_set1_ps(-0.0f))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1107(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_mul_ps(_mm_xor_ps(x, _mm_set1_ps(-0.0f)), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1108(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(_mm_div_ps(x, y), _mm_set1_ps(-0.0f)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1109(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_div_ps(_mm_xor_ps(x, _mm_set1_ps(-0.0f)), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1110(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_div_ps(x, _mm_xor_ps(y, _mm_set1_ps(-0.0f))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1111(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_div_ps(_mm_xor_ps(x, _mm_set1_ps(-0.0f)), _mm_xor_ps(y, _mm_set1_ps(-0.0f))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1112(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_div_ps(x, _mm_xor_ps(x, _mm_set1_ps(-0.0f))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1113(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_div_ps(_mm_xor_ps(x, _mm_set1_ps(-0.0f)), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1114(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(_mm_min_ps(x, y), _mm_set1_ps(-0.0f)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1115(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_min_ps(_mm_xor_ps(x, _mm_set1_ps(-0.0f)), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1116(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_min_ps(x, _mm_xor_ps(y, _mm_set1_ps(-0.0f))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1117(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_min_ps(_mm_xor_ps(x, _mm_set1_ps(-0.0f)), _mm_xor_ps(y, _mm_set1_ps(-0.0f))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1118(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_min_ps(x, _mm_xor_ps(x, _mm_set1_ps(-0.0f))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1119(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_min_ps(_mm_xor_ps(x, _mm_set1_ps(-0.0f)), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1120(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(_mm_max_ps(x, y), _mm_set1_ps(-0.0f)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1121(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_max_ps(_mm_xor_ps(x, _mm_set1_ps(-0.0f)), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1122(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_max_ps(x, _mm_xor_ps(y, _mm_set1_ps(-0.0f))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1123(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_max_ps(_mm_xor_ps(x, _mm_set1_ps(-0.0f)), _mm_xor_ps(y, _mm_set1_ps(-0.0f))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1124(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_max_ps(x, _mm_xor_ps(x, _mm_set1_ps(-0.0f))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1125(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_max_ps(_mm_xor_ps(x, _mm_set1_ps(-0.0f)), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1126(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(_mm_and_ps(x, y), _mm_set1_ps(-0.0f)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1127(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_and_ps(_mm_xor_ps(x, _mm_set1_ps(-0.0f)), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1128(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_and_ps(x, _mm_xor_ps(y, _mm_set1_ps(-0.0f))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1129(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_and_ps(_mm_xor_ps(x, _mm_set1_ps(-0.0f)), _mm_xor_ps(y, _mm_set1_ps(-0.0f))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1130(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_and_ps(x, _mm_xor_ps(x, _mm_set1_ps(-0.0f))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1131(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_and_ps(_mm_xor_ps(x, _mm_set1_ps(-0.0f)), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1132(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(_mm_or_ps(x, y), _mm_set1_ps(-0.0f)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1133(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(_mm_xor_ps(x, _mm_set1_ps(-0.0f)), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1134(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(x, _mm_xor_ps(y, _mm_set1_ps(-0.0f))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1135(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(_mm_xor_ps(x, _mm_set1_ps(-0.0f)), _mm_xor_ps(y, _mm_set1_ps(-0.0f))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1136(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(x, _mm_xor_ps(x, _mm_set1_ps(-0.0f))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1137(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_or_ps(_mm_xor_ps(x, _mm_set1_ps(-0.0f)), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1138(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(_mm_xor_ps(x, y), _mm_set1_ps(-0.0f)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1139(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(_mm_xor_ps(x, _mm_set1_ps(-0.0f)), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1140(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(x, _mm_xor_ps(y, _mm_set1_ps(-0.0f))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1141(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(_mm_xor_ps(x, _mm_set1_ps(-0.0f)), _mm_xor_ps(y, _mm_set1_ps(-0.0f))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1142(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(x, _mm_xor_ps(x, _mm_set1_ps(-0.0f))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1143(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(_mm_xor_ps(x, _mm_set1_ps(-0.0f)), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1144(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(_mm_andnot_ps(x, y), _mm_set1_ps(-0.0f)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1145(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_andnot_ps(_mm_xor_ps(x, _mm_set1_ps(-0.0f)), y); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1146(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_andnot_ps(x, _mm_xor_ps(y, _mm_set1_ps(-0.0f))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1147(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_andnot_ps(_mm_xor_ps(x, _mm_set1_ps(-0.0f)), _mm_xor_ps(y, _mm_set1_ps(-0.0f))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1148(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_andnot_ps(x, _mm_xor_ps(x, _mm_set1_ps(-0.0f))); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1149(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_andnot_ps(_mm_xor_ps(x, _mm_set1_ps(-0.0f)), x); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1150(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), _mm_set1_ps(-0.0f)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1151(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_cmp_ps(_mm_xor_ps(x, _mm_set1_ps(-0.0f)), y, _CMP_EQ_OQ); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1152(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_cmp_ps(x, _mm_xor_ps(y, _mm_set1_ps(-0.0f)), _CMP_EQ_OQ); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1153(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_cmp_ps(_mm_xor_ps(x, _mm_set1_ps(-0.0f)), _mm_xor_ps(y, _mm_set1_ps(-0.0f)), _CMP_EQ_OQ); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1154(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_cmp_ps(x, _mm_xor_ps(x, _mm_set1_ps(-0.0f)), _CMP_EQ_OQ); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1155(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_cmp_ps(_mm_xor_ps(x, _mm_set1_ps(-0.0f)), x, _CMP_EQ_OQ); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1156(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), _mm_set1_ps(-0.0f)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1157(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_cmp_ps(_mm_xor_ps(x, _mm_set1_ps(-0.0f)), y, _CMP_LT_OS); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1158(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_cmp_ps(x, _mm_xor_ps(y, _mm_set1_ps(-0.0f)), _CMP_LT_OS); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1159(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_cmp_ps(_mm_xor_ps(x, _mm_set1_ps(-0.0f)), _mm_xor_ps(y, _mm_set1_ps(-0.0f)), _CMP_LT_OS); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1160(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_cmp_ps(x, _mm_xor_ps(x, _mm_set1_ps(-0.0f)), _CMP_LT_OS); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1161(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_cmp_ps(_mm_xor_ps(x, _mm_set1_ps(-0.0f)), x, _CMP_LT_OS); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1162(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), _mm_set1_ps(-0.0f)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1163(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_cmp_ps(_mm_xor_ps(x, _mm_set1_ps(-0.0f)), y, _CMP_LE_OS); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1164(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_cmp_ps(x, _mm_xor_ps(y, _mm_set1_ps(-0.0f)), _CMP_LE_OS); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1165(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_cmp_ps(_mm_xor_ps(x, _mm_set1_ps(-0.0f)), _mm_xor_ps(y, _mm_set1_ps(-0.0f)), _CMP_LE_OS); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1166(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_cmp_ps(x, _mm_xor_ps(x, _mm_set1_ps(-0.0f)), _CMP_LE_OS); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1167(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_cmp_ps(_mm_xor_ps(x, _mm_set1_ps(-0.0f)), x, _CMP_LE_OS); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1168(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(_mm_cmp_ps(x, y, _CMP_NEQ_UQ), _mm_set1_ps(-0.0f)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1169(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_cmp_ps(_mm_xor_ps(x, _mm_set1_ps(-0.0f)), y, _CMP_NEQ_UQ); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1170(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_cmp_ps(x, _mm_xor_ps(y, _mm_set1_ps(-0.0f)), _CMP_NEQ_UQ); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1171(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_cmp_ps(_mm_xor_ps(x, _mm_set1_ps(-0.0f)), _mm_xor_ps(y, _mm_set1_ps(-0.0f)), _CMP_NEQ_UQ); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1172(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_cmp_ps(x, _mm_xor_ps(x, _mm_set1_ps(-0.0f)), _CMP_NEQ_UQ); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1173(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_cmp_ps(_mm_xor_ps(x, _mm_set1_ps(-0.0f)), x, _CMP_NEQ_UQ); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1174(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), _mm_set1_ps(-0.0f)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1175(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_cmp_ps(_mm_xor_ps(x, _mm_set1_ps(-0.0f)), y, _CMP_UNORD_Q); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1176(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_cmp_ps(x, _mm_xor_ps(y, _mm_set1_ps(-0.0f)), _CMP_UNORD_Q); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1177(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_cmp_ps(_mm_xor_ps(x, _mm_set1_ps(-0.0f)), _mm_xor_ps(y, _mm_set1_ps(-0.0f)), _CMP_UNORD_Q); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1178(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_cmp_ps(x, _mm_xor_ps(x, _mm_set1_ps(-0.0f)), _CMP_UNORD_Q); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1179(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_cmp_ps(_mm_xor_ps(x, _mm_set1_ps(-0.0f)), x, _CMP_UNORD_Q); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1180(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), _mm_set1_ps(-0.0f)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1181(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_cmp_ps(_mm_xor_ps(x, _mm_set1_ps(-0.0f)), y, _CMP_NLT_US); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1182(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_cmp_ps(x, _mm_xor_ps(y, _mm_set1_ps(-0.0f)), _CMP_NLT_US); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1183(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_cmp_ps(_mm_xor_ps(x, _mm_set1_ps(-0.0f)), _mm_xor_ps(y, _mm_set1_ps(-0.0f)), _CMP_NLT_US); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1184(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_cmp_ps(x, _mm_xor_ps(x, _mm_set1_ps(-0.0f)), _CMP_NLT_US); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1185(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_cmp_ps(_mm_xor_ps(x, _mm_set1_ps(-0.0f)), x, _CMP_NLT_US); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1186(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), _mm_set1_ps(-0.0f)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1187(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_cmp_ps(_mm_xor_ps(x, _mm_set1_ps(-0.0f)), y, _CMP_GT_OS); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1188(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_cmp_ps(x, _mm_xor_ps(y, _mm_set1_ps(-0.0f)), _CMP_GT_OS); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1189(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_cmp_ps(_mm_xor_ps(x, _mm_set1_ps(-0.0f)), _mm_xor_ps(y, _mm_set1_ps(-0.0f)), _CMP_GT_OS); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1190(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_cmp_ps(x, _mm_xor_ps(x, _mm_set1_ps(-0.0f)), _CMP_GT_OS); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1191(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_cmp_ps(_mm_xor_ps(x, _mm_set1_ps(-0.0f)), x, _CMP_GT_OS); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1192(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LT_OS)), _mm_set1_ps(-0.0f)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1193(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_blendv_ps(_mm_xor_ps(x, _mm_set1_ps(-0.0f)), y, _mm_cmp_ps(_mm_xor_ps(x, _mm_set1_ps(-0.0f)), y, _CMP_LT_OS)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1194(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_blendv_ps(x, _mm_xor_ps(y, _mm_set1_ps(-0.0f)), _mm_cmp_ps(x, _mm_xor_ps(y, _mm_set1_ps(-0.0f)), _CMP_LT_OS)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1195(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_blendv_ps(_mm_xor_ps(x, _mm_set1_ps(-0.0f)), _mm_xor_ps(y, _mm_set1_ps(-0.0f)), _mm_cmp_ps(_mm_xor_ps(x, _mm_set1_ps(-0.0f)), _mm_xor_ps(y, _mm_set1_ps(-0.0f)), _CMP_LT_OS)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1196(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_blendv_ps(x, _mm_xor_ps(x, _mm_set1_ps(-0.0f)), _mm_cmp_ps(x, _mm_xor_ps(x, _mm_set1_ps(-0.0f)), _CMP_LT_OS)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1197(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_blendv_ps(_mm_xor_ps(x, _mm_set1_ps(-0.0f)), x, _mm_cmp_ps(_mm_xor_ps(x, _mm_set1_ps(-0.0f)), x, _CMP_LT_OS)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1198(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_xor_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LT_OS)), _mm_set1_ps(-0.0f)); _mm_storeu_ps((float*)po, r); }
static NOINLINE void f1199(const void* px, const void* py, void* po) { const __m128 x = _mm_loadu_ps((const float*)px); const __m128 y = _mm_loadu_ps((const float*)py); (void)y; const __m128 r = _mm_blendv_ps(y, _mm_xor_ps(x, _mm_set1_ps(-0.0f)), _mm_cmp_ps(_mm_xor_ps(x, _mm_set1_ps(-0.0f)), y, _CMP_LT_OS)); _mm_storeu_ps((float*)po, r); }
extern const Entry table_20[] = {
  {"128:_mm_mulhi_epu16(_mm_cmpgt_epi16(x, y), y)", f0, 0, 128},
  {"128:_mm_mulhi_epu16(x, _mm_cmpgt_epi16(x, y))", f1, 0, 128},
  {"128:_mm_mulhi_epu16(_mm_cmpgt_epi16(x, y), x)", f2, 0, 128},
  {"128:_mm_mulhi_epu16(y, _mm_cmpgt_epi16(x, y))", f3, 0, 128},
  {"128:_mm_mulhi_epu16(_mm_sign_epi16(x, y), y)", f4, 0, 128},
  {"128:_mm_mulhi_epu16(x, _mm_sign_epi16(x, y))", f5, 0, 128},
  {"128:_mm_mulhi_epu16(_mm_sign_epi16(x, y), x)", f6, 0, 128},
  {"128:_mm_mulhi_epu16(y, _mm_sign_epi16(x, y))", f7, 0, 128},
  {"128:_mm_mulhi_epu16(_mm_packs_epi16(x, y), y)", f8, 0, 128},
  {"128:_mm_mulhi_epu16(x, _mm_packs_epi16(x, y))", f9, 0, 128},
  {"128:_mm_mulhi_epu16(_mm_packs_epi16(x, y), x)", f10, 0, 128},
  {"128:_mm_mulhi_epu16(y, _mm_packs_epi16(x, y))", f11, 0, 128},
  {"128:_mm_mulhi_epu16(_mm_packus_epi16(x, y), y)", f12, 0, 128},
  {"128:_mm_mulhi_epu16(x, _mm_packus_epi16(x, y))", f13, 0, 128},
  {"128:_mm_mulhi_epu16(_mm_packus_epi16(x, y), x)", f14, 0, 128},
  {"128:_mm_mulhi_epu16(y, _mm_packus_epi16(x, y))", f15, 0, 128},
  {"128:_mm_mulhi_epu16(_mm_hadd_epi16(x, y), y)", f16, 0, 128},
  {"128:_mm_mulhi_epu16(x, _mm_hadd_epi16(x, y))", f17, 0, 128},
  {"128:_mm_mulhi_epu16(_mm_hadd_epi16(x, y), x)", f18, 0, 128},
  {"128:_mm_mulhi_epu16(y, _mm_hadd_epi16(x, y))", f19, 0, 128},
  {"128:_mm_mulhi_epu16(_mm_hsub_epi16(x, y), y)", f20, 0, 128},
  {"128:_mm_mulhi_epu16(x, _mm_hsub_epi16(x, y))", f21, 0, 128},
  {"128:_mm_mulhi_epu16(_mm_hsub_epi16(x, y), x)", f22, 0, 128},
  {"128:_mm_mulhi_epu16(y, _mm_hsub_epi16(x, y))", f23, 0, 128},
  {"128:_mm_mulhi_epu16(_mm_hadds_epi16(x, y), y)", f24, 0, 128},
  {"128:_mm_mulhi_epu16(x, _mm_hadds_epi16(x, y))", f25, 0, 128},
  {"128:_mm_mulhi_epu16(_mm_hadds_epi16(x, y), x)", f26, 0, 128},
  {"128:_mm_mulhi_epu16(y, _mm_hadds_epi16(x, y))", f27, 0, 128},
  {"128:_mm_mulhi_epu16(_mm_madd_epi16(x, y), y)", f28, 0, 128},
  {"128:_mm_mulhi_epu16(x, _mm_madd_epi16(x, y))", f29, 0, 128},
  {"128:_mm_mulhi_epu16(_mm_madd_epi16(x, y), x)", f30, 0, 128},
  {"128:_mm_mulhi_epu16(y, _mm_madd_epi16(x, y))", f31, 0, 128},
  {"128:_mm_mulhi_epu16(_mm_unpacklo_epi16(x, y), y)", f32, 0, 128},
  {"128:_mm_mulhi_epu16(x, _mm_unpacklo_epi16(x, y))", f33, 0, 128},
  {"128:_mm_mulhi_epu16(_mm_unpacklo_epi16(x, y), x)", f34, 0, 128},
  {"128:_mm_mulhi_epu16(y, _mm_unpacklo_epi16(x, y))", f35, 0, 128},
  {"128:_mm_mulhi_epu16(_mm_unpackhi_epi16(x, y), y)", f36, 0, 128},
  {"128:_mm_mulhi_epu16(x, _mm_unpackhi_epi16(x, y))", f37, 0, 128},
  {"128:_mm_mulhi_epu16(_mm_unpackhi_epi16(x, y), x)", f38, 0, 128},
  {"128:_mm_mulhi_epu16(y, _mm_unpackhi_epi16(x, y))", f39, 0, 128},
  {"128:_mm_mulhi_epu16(_mm_blendv_epi8(x, y, _mm_cmpgt_epi16(x, y)), y)", f40, 0, 128},
  {"128:_mm_mulhi_epu16(x, _mm_blendv_epi8(x, y, _mm_cmpgt_epi16(x, y)))", f41, 0, 128},
  {"128:_mm_mulhi_epu16(_mm_blendv_epi8(x, y, _mm_cmpgt_epi16(x, y)), x)", f42, 0, 128},
  {"128:_mm_mulhi_epu16(y, _mm_blendv_epi8(x, y, _mm_cmpgt_epi16(x, y)))", f43, 0, 128},
  {"128:_mm_mulhi_epu16(_mm_blendv_epi8(y, x, _mm_cmpgt_epi16(x, y)), y)", f44, 0, 128},
  {"128:_mm_mulhi_epu16(x, _mm_blendv_epi8(y, x, _mm_cmpgt_epi16(x, y)))", f45, 0, 128},
  {"128:_mm_mulhi_epu16(_mm_blendv_epi8(y, x, _mm_cmpgt_epi16(x, y)), x)", f46, 0, 128},
  {"128:_mm_mulhi_epu16(y, _mm_blendv_epi8(y, x, _mm_cmpgt_epi16(x, y)))", f47, 0, 128},
  {"128:_mm_mulhi_epu16(_mm_or_si128(_mm_and_si128(_mm_cmpgt_epi16(x, y), x), _mm_andnot_si128(_mm_cmpgt_epi16(x, y), y)), y)", f48, 0, 128},
  {"128:_mm_mulhi_epu16(x, _mm_or_si128(_mm_and_si128(_mm_cmpgt_epi16(x, y), x), _mm_andnot_si128(_mm_cmpgt_epi16(x, y), y)))", f49, 0, 128},
  {"128:_mm_mulhi_epu16(_mm_or_si128(_mm_and_si128(_mm_cmpgt_epi16(x, y), x), _mm_andnot_si128(_mm_cmpgt_epi16(x, y), y)), x)", f50, 0, 128},
  {"128:_mm_mulhi_epu16(y, _mm_or_si128(_mm_and_si128(_mm_cmpgt_epi16(x, y), x), _mm_andnot_si128(_mm_cmpgt_epi16(x, y), y)))", f51, 0, 128},
  {"128:_mm_mulhi_epu16(_mm_blendv_epi8(x, y, _mm_cmpeq_epi16(x, y)), y)", f52, 0, 128},
  {"128:_mm_mulhi_epu16(x, _mm_blendv_epi8(x, y, _mm_cmpeq_epi16(x, y)))", f53, 0, 128},
  {"128:_mm_mulhi_epu16(_mm_blendv_epi8(x, y, _mm_cmpeq_epi16(x, y)), x)", f54, 0, 128},
  {"128:_mm_mulhi_epu16(y, _mm_blendv_epi8(x, y, _mm_cmpeq_epi16(x, y)))", f55, 0, 128},
  {"128:_mm_mulhi_epu16(_mm_blendv_epi8(y, x, _mm_cmpeq_epi16(x, y)), y)", f56, 0, 128},
  {"128:_mm_mulhi_epu16(x, _mm_blendv_epi8(y, x, _mm_cmpeq_epi16(x, y)))", f57, 0, 128},
  {"128:_mm_mulhi_epu16(_mm_blendv_epi8(y, x, _mm_cmpeq_epi16(x, y)), x)", f58, 0, 128},
  {"128:_mm_mulhi_epu16(y, _mm_blendv_epi8(y, x, _mm_cmpeq_epi16(x, y)))", f59, 0, 128},
  {"128:_mm_mulhi_epu16(_mm_or_si128(_mm_and_si128(_mm_cmpeq_epi16(x, y), x), _mm_andnot_si128(_mm_cmpeq_epi16(x, y), y)), y)", f60, 0, 128},
  {"128:_mm_mulhi_epu16(x, _mm_or_si128(_mm_and_si128(_mm_cmpeq_epi16(x, y), x), _mm_andnot_si128(_mm_cmpeq_epi16(x, y), y)))", f61, 0, 128},
  {"128:_mm_mulhi_epu16(_mm_or_si128(_mm_and_si128(_mm_cmpeq_epi16(x, y), x), _mm_andnot_si128(_mm_cmpeq_epi16(x, y), y)), x)", f62, 0, 128},
  {"128:_mm_mulhi_epu16(y, _mm_or_si128(_mm_and_si128(_mm_cmpeq_epi16(x, y), x), _mm_andnot_si128(_mm_cmpeq_epi16(x, y), y)))", f63, 0, 128},
  {"128:_mm_mulhi_epu16(_mm_mullo_epi16(x, y), y)", f64, 0, 128},
  {"128:_mm_mulhi_epu16(x, _mm_mullo_epi16(x, y))", f65, 0, 128},
  {"128:_mm_mulhi_epu16(_mm_mullo_epi16(x, y), x)", f66, 0, 128},
  {"128:_mm_mulhi_epu16(y, _mm_mullo_epi16(x, y))", f67, 0, 128},
  {"128:_mm_mulhi_epu16(_mm_mulhi_epi16(x, y), y)", f68, 0, 128},
  {"128:_mm_mulhi_epu16(x, _mm_mulhi_epi16(x, y))", f69, 0, 128},
  {"128:_mm_mulhi_epu16(_mm_mulhi_epi16(x, y), x)", f70, 0, 128},
  {"128:_mm_mulhi_epu16(y, _mm_mulhi_epi16(x, y))", f71, 0, 128},
  {"128:_mm_mulhi_epu16(_mm_mulhi_epu16(x, y), y)", f72, 0, 128},
  {"128:_mm_mulhi_epu16(x, _mm_mulhi_epu16(x, y))", f73, 0, 128},
  {"128:_mm_mulhi_epu16(_mm_mulhi_epu16(x, y), x)", f74, 0, 128},
  {"128:_mm_mulhi_epu16(y, _mm_mulhi_epu16(x, y))", f75, 0, 128},
  {"128:_mm_sllv_epi32(_mm_add_epi32(x, y), y)", f76, 0, 128},
  {"128:_mm_sllv_epi32(x, _mm_add_epi32(x, y))", f77, 0, 128},
  {"128:_mm_sllv_epi32(_mm_add_epi32(x, y), x)", f78, 0, 128},
  {"128:_mm_sllv_epi32(y, _mm_add_epi32(x, y))", f79, 0, 128},
  {"128:_mm_sllv_epi32(_mm_sub_epi32(x, y), y)", f80, 0, 128},
  {"128:_mm_sllv_epi32(x, _mm_sub_epi32(x, y))", f81, 0, 128},
  {"128:_mm_sllv_epi32(_mm_sub_epi32(x, y), x)", f82, 0, 128},
  {"128:_mm_sllv_epi32(y, _mm_sub_epi32(x, y))", f83, 0, 128},
  {"128:_mm_sllv_epi32(_mm_min_epi32(x, y), y)", f84, 0, 128},
  {"128:_mm_sllv_epi32(x, _mm_min_epi32(x, y))", f85, 0, 128},
  {"128:_mm_sllv_epi32(_mm_min_epi32(x, y), x)", f86, 0, 128},
  {"128:_mm_sllv_epi32(y, _mm_min_epi32(x, y))", f87, 0, 128},
  {"128:_mm_sllv_epi32(_mm_max_epi32(x, y), y)", f88, 0, 128},
  {"128:_mm_sllv_epi32(x, _mm_max_epi32(x, y))", f89, 0, 128},
  {"128:_mm_sllv_epi32(_mm_max_epi32(x, y), x)", f90, 0, 128},
  {"128:_mm_sllv_epi32(y, _mm_max_epi32(x, y))", f91, 0, 128},
  {"128:_mm_sllv_epi32(_mm_min_epu32(x, y), y)", f92, 0, 128},
  {"128:_mm_sllv_epi32(x, _mm_min_epu32(x, y))", f93, 0, 128},
  {"128:_mm_sllv_epi32(_mm_min_epu32(x, y), x)", f94, 0, 128},
  {"128:_mm_sllv_epi32(y, _mm_min_epu32(x, y))", f95, 0, 128},
  {"128:_mm_sllv_epi32(_mm_max_epu32(x, y), y)", f96, 0, 128},
  {"128:_mm_sllv_epi32(x, _mm_max_epu32(x, y))", f97, 0, 128},
  {"128:_mm_sllv_epi32(_mm_max_epu32(x, y), x)", f98, 0, 128},
  {"128:_mm_sllv_epi32(y, _mm_max_epu32(x, y))", f99, 0, 128},
  {"128:_mm_sllv_epi32(_mm_and_si128(x, y), y)", f100, 0, 128},
  {"128:_mm_sllv_epi32(x, _mm_and_si128(x, y))", f101, 0, 128},
  {"128:_mm_sllv_epi32(_mm_and_si128(x, y), x)", f102, 0, 128},
  {"128:_mm_sllv_epi32(y, _mm_and_si128(x, y))", f103, 0, 128},
  {"128:_mm_sllv_epi32(_mm_or_si128(x, y), y)", f104, 0, 128},
  {"128:_mm_sllv_epi32(x, _mm_or_si128(x, y))", f105, 0, 128},
  {"128:_mm_sllv_epi32(_mm_or_si128(x, y), x)", f106, 0, 128},
  {"128:_mm_sllv_epi32(y, _mm_or_si128(x, y))", f107, 0, 128},
  {"128:_mm_sllv_epi32(_mm_xor_si128(x, y), y)", f108, 0, 128},
  {"128:_mm_sllv_epi32(x, _mm_xor_si128(x, y))", f109, 0, 128},
  {"128:_mm_sllv_epi32(_mm_xor_si128(x, y), x)", f110, 0, 128},
  {"128:_mm_sllv_epi32(y, _mm_xor_si128(x, y))", f111, 0, 128},
  {"128:_mm_sllv_epi32(_mm_andnot_si128(x, y), y)", f112, 0, 128},
  {"128:_mm_sllv_epi32(x, _mm_andnot_si128(x, y))", f113, 0, 128},
  {"128:_mm_sllv_epi32(_mm_andnot_si128(x, y), x)", f114, 0, 128},
  {"128:_mm_sllv_epi32(y, _mm_andnot_si128(x, y))", f115, 0, 128},
  {"128:_mm_sllv_epi32(_mm_cmpeq_epi32(x, y), y)", f116, 0, 128},
  {"128:_mm_sllv_epi32(x, _mm_cmpeq_epi32(x, y))", f117, 0, 128},
  {"128:_mm_sllv_epi32(_mm_cmpeq_epi32(x, y), x)", f118, 0, 128},
  {"128:_mm_sllv_epi32(y, _mm_cmpeq_epi32(x, y))", f119, 0, 128},
  {"128:_mm_sllv_epi32(_mm_cmpgt_epi32(x, y), y)", f120, 0, 128},
  {"128:_mm_sllv_epi32(x, _mm_cmpgt_epi32(x, y))", f121, 0, 128},
  {"128:_mm_sllv_epi32(_mm_cmpgt_epi32(x, y), x)", f122, 0, 128},
  {"128:_mm_sllv_epi32(y, _mm_cmpgt_epi32(x, y))", f123, 0, 128},
  {"128:_mm_sllv_epi32(_mm_sign_epi32(x, y), y)", f124, 0, 128},
  {"128:_mm_sllv_epi32(x, _mm_sign_epi32(x, y))", f125, 0, 128},
  {"128:_mm_sllv_epi32(_mm_sign_epi32(x, y), x)", f126, 0, 128},
  {"128:_mm_sllv_epi32(y, _mm_sign_epi32(x, y))", f127, 0, 128},
  {"128:_mm_sllv_epi32(_mm_packs_epi32(x, y), y)", f128, 0, 128},
  {"128:_mm_sllv_epi32(x, _mm_packs_epi32(x, y))", f129, 0, 128},
  {"128:_mm_sllv_epi32(_mm_packs_epi32(x, y), x)", f130, 0, 128},
  {"128:_mm_sllv_epi32(y, _mm_packs_epi32(x, y))", f131, 0, 128},
  {"128:_mm_sllv_epi32(_mm_packus_epi32(x, y), y)", f132, 0, 128},
  {"128:_mm_sllv_epi32(x, _mm_packus_epi32(x, y))", f133, 0, 128},
  {"128:_mm_sllv_epi32(_mm_packus_epi32(x, y), x)", f134, 0, 128},
  {"128:_mm_sllv_epi32(y, _mm_packus_epi32(x, y))", f135, 0, 128},
  {"128:_mm_sllv_epi32(_mm_hadd_epi32(x, y), y)", f136, 0, 128},
  {"128:_mm_sllv_epi32(x, _mm_hadd_epi32(x, y))", f137, 0, 128},
  {"128:_mm_sllv_epi32(_mm_hadd_epi32(x, y), x)", f138, 0, 128},
  {"128:_mm_sllv_epi32(y, _mm_hadd_epi32(x, y))", f139, 0, 128},
  {"128:_mm_sllv_epi32(_mm_hsub_epi32(x, y), y)", f140, 0, 128},
  {"128:_mm_sllv_epi32(x, _mm_hsub_epi32(x, y))", f141, 0, 128},
  {"128:_mm_sllv_epi32(_mm_hsub_epi32(x, y), x)", f142, 0, 128},
  {"128:_mm_sllv_epi32(y, _mm_hsub_epi32(x, y))", f143, 0, 128},
  {"128:_mm_sllv_epi32(_mm_mul_epi32(x, y), y)", f144, 0, 128},
  {"128:_mm_sllv_epi32(x, _mm_mul_epi32(x, y))", f145, 0, 128},
  {"128:_mm_sllv_epi32(_mm_mul_epi32(x, y), x)", f146, 0, 128},
  {"128:_mm_sllv_epi32(y, _mm_mul_epi32(x, y))", f147, 0, 128},
  {"128:_mm_sllv_epi32(_mm_mul_epu32(x, y), y)", f148, 0, 128},
  {"128:_mm_sllv_epi32(x, _mm_mul_epu32(x, y))", f149, 0, 128},
  {"128:_mm_sllv_epi32(_mm_mul_epu32(x, y), x)", f150, 0, 128},
  {"128:_mm_sllv_epi32(y, _mm_mul_epu32(x, y))", f151, 0, 128},
  {"128:_mm_sllv_epi32(_mm_unpacklo_epi32(x, y), y)", f152, 0, 128},
  {"128:_mm_sllv_epi32(x, _mm_unpacklo_epi32(x, y))", f153, 0, 128},
  {"128:_mm_sllv_epi32(_mm_unpacklo_epi32(x, y), x)", f154, 0, 128},
  {"128:_mm_sllv_epi32(y, _mm_unpacklo_epi32(x, y))", f155, 0, 128},
  {"128:_mm_sllv_epi32(_mm_unpackhi_epi32(x, y), y)", f156, 0, 128},
  {"128:_mm_sllv_epi32(x, _mm_unpackhi_epi32(x, y))", f157, 0, 128},
  {"128:_mm_sllv_epi32(_mm_unpackhi_epi32(x, y), x)", f158, 0, 128},
  {"128:_mm_sllv_epi32(y, _mm_unpackhi_epi32(x, y))", f159, 0, 128},
  {"128:_mm_sllv_epi32(_mm_blendv_epi8(x, y, _mm_cmpgt_epi32(x, y)), y)", f160, 0, 128},
  {"128:_mm_sllv_epi32(x, _mm_blendv_epi8(x, y, _mm_cmpgt_epi32(x, y)))", f161, 0, 128},
  {"128:_mm_sllv_epi32(_mm_blendv_epi8(x, y, _mm_cmpgt_epi32(x, y)), x)", f162, 0, 128},
  {"128:_mm_sllv_epi32(y, _mm_blendv_epi8(x, y, _mm_cmpgt_epi32(x, y)))", f163, 0, 128},
  {"128:_mm_sllv_epi32(_mm_blendv_epi8(y, x, _mm_cmpgt_epi32(x, y)), y)", f164, 0, 128},
  {"128:_mm_sllv_epi32(x, _mm_blendv_epi8(y, x, _mm_cmpgt_epi32(x, y)))", f165, 0, 128},
  {"128:_mm_sllv_epi32(_mm_blendv_epi8(y, x, _mm_cmpgt_epi32(x, y)), x)", f166, 0, 128},
  {"128:_mm_sllv_epi32(y, _mm_blendv_epi8(y, x, _mm_cmpgt_epi32(x, y)))", f167, 0, 128},
  {"128:_mm_sllv_epi32(_mm_or_si128(_mm_and_si128(_mm_cmpgt_epi32(x, y), x), _mm_andnot_si128(_mm_cmpgt_epi32(x, y), y)), y)", f168, 0, 128},
  {"128:_mm_sllv_epi32(x, _mm_or_si128(_mm_and_si128(_mm_cmpgt_epi32(x, y), x), _mm_andnot_si128(_mm_cmpgt_epi32(x, y), y)))", f169, 0, 128},
  {"128:_mm_sllv_epi32(_mm_or_si128(_mm_and_si128(_mm_cmpgt_epi32(x, y), x), _mm_andnot_si128(_mm_cmpgt_epi32(x, y), y)), x)", f170, 0, 128},
  {"128:_mm_sllv_epi32(y, _mm_or_si128(_mm_and_si128(_mm_cmpgt_epi32(x, y), x), _mm_andnot_si128(_mm_cmpgt_epi32(x, y), y)))", f171, 0, 128},
  {"128:_mm_sllv_epi32(_mm_blendv_epi8(x, y, _mm_cmpeq_epi32(x, y)), y)", f172, 0, 128},
  {"128:_mm_sllv_epi32(x, _mm_blendv_epi8(x, y, _mm_cmpeq_epi32(x, y)))", f173, 0, 128},
  {"128:_mm_sllv_epi32(_mm_blendv_epi8(x, y, _mm_cmpeq_epi32(x, y)), x)", f174, 0, 128},
  {"128:_mm_sllv_epi32(y, _mm_blendv_epi8(x, y, _mm_cmpeq_epi32(x, y)))", f175, 0, 128},
  {"128:_mm_sllv_epi32(_mm_blendv_epi8(y, x, _mm_cmpeq_epi32(x, y)), y)", f176, 0, 128},
  {"128:_mm_sllv_epi32(x, _mm_blendv_epi8(y, x, _mm_cmpeq_epi32(x, y)))", f177, 0, 128},
  {"128:_mm_sllv_epi32(_mm_blendv_epi8(y, x, _mm_cmpeq_epi32(x, y)), x)", f178, 0, 128},
  {"128:_mm_sllv_epi32(y, _mm_blendv_epi8(y, x, _mm_cmpeq_epi32(x, y)))", f179, 0, 128},
  {"128:_mm_sllv_epi32(_mm_or_si128(_mm_and_si128(_mm_cmpeq_epi32(x, y), x), _mm_andnot_si128(_mm_cmpeq_epi32(x, y), y)), y)", f180, 0, 128},
  {"128:_mm_sllv_epi32(x, _mm_or_si128(_mm_and_si128(_mm_cmpeq_epi32(x, y), x), _mm_andnot_si128(_mm_cmpeq_epi32(x, y), y)))", f181, 0, 128},
  {"128:_mm_sllv_epi32(_mm_or_si128(_mm_and_si128(_mm_cmpeq_epi32(x, y), x), _mm_andnot_si128(_mm_cmpeq_epi32(x, y), y)), x)", f182, 0, 128},
  {"128:_mm_sllv_epi32(y, _mm_or_si128(_mm_and_si128(_mm_cmpeq_epi32(x, y), x), _mm_andnot_si128(_mm_cmpeq_epi32(x, y), y)))", f183, 0, 128},
  {"128:_mm_sllv_epi32(_mm_mullo_epi32(x, y), y)", f184, 0, 128},
  {"128:_mm_sllv_epi32(x, _mm_mullo_epi32(x, y))", f185, 0, 128},
  {"128:_mm_sllv_epi32(_mm_mullo_epi32(x, y), x)", f186, 0, 128},
  {"128:_mm_sllv_epi32(y, _mm_mullo_epi32(x, y))", f187, 0, 128},
  {"128:_mm_sllv_epi32(_mm_sllv_epi32(x, y), y)", f188, 0, 128},
  {"128:_mm_sllv_epi32(x, _mm_sllv_epi32(x, y))", f189, 0, 128},
  {"128:_mm_sllv_epi32(_mm_sllv_epi32(x, y), x)", f190, 0, 128},
  {"128:_mm_sllv_epi32(y, _mm_sllv_epi32(x, y))", f191, 0, 128},
  {"128:_mm_sllv_epi32(_mm_srlv_epi32(x, y), y)", f192, 0, 128},
  {"128:_mm_sllv_epi32(x, _mm_srlv_epi32(x, y))", f193, 0, 128},
  {"128:_mm_sllv_epi32(_mm_srlv_epi32(x, y), x)", f194, 0, 128},
  {"128:_mm_sllv_epi32(y, _mm_srlv_epi32(x, y))", f195, 0, 128},
  {"128:_mm_sllv_epi32(_mm_srav_epi32(x, y), y)", f196, 0, 128},
  {"128:_mm_sllv_epi32(x, _mm_srav_epi32(x, y))", f197, 0, 128},
  {"128:_mm_sllv_epi32(_mm_srav_epi32(x, y), x)", f198, 0, 128},
  {"128:_mm_sllv_epi32(y, _mm_srav_epi32(x, y))", f199, 0, 128},
  {"128:_mm_srlv_epi32(_mm_add_epi32(x, y), y)", f200, 0, 128},
  {"128:_mm_srlv_epi32(x, _mm_add_epi32(x, y))", f201, 0, 128},
  {"128:_mm_srlv_epi32(_mm_add_epi32(x, y), x)", f202, 0, 128},
  {"128:_mm_srlv_epi32(y, _mm_add_epi32(x, y))", f203, 0, 128},
  {"128:_mm_srlv_epi32(_mm_sub_epi32(x, y), y)", f204, 0, 128},
  {"128:_mm_srlv_epi32(x, _mm_sub_epi32(x, y))", f205, 0, 128},
  {"128:_mm_srlv_epi32(_mm_sub_epi32(x, y), x)", f206, 0, 128},
  {"128:_mm_srlv_epi32(y, _mm_sub_epi32(x, y))", f207, 0, 128},
  {"128:_mm_srlv_epi32(_mm_min_epi32(x, y), y)", f208, 0, 128},
  {"128:_mm_srlv_epi32(x, _mm_min_epi32(x, y))", f209, 0, 128},
  {"128:_mm_srlv_epi32(_mm_min_epi32(x, y), x)", f210, 0, 128},
  {"128:_mm_srlv_epi32(y, _mm_min_epi32(x, y))", f211, 0, 128},
  {"128:_mm_srlv_epi32(_mm_max_epi32(x, y), y)", f212, 0, 128},
  {"128:_mm_srlv_epi32(x, _mm_max_epi32(x, y))", f213, 0, 128},
  {"128:_mm_srlv_epi32(_mm_max_epi32(x, y), x)", f214, 0, 128},
  {"128:_mm_srlv_epi32(y, _mm_max_epi32(x, y))", f215, 0, 128},
  {"128:_mm_srlv_epi32(_mm_min_epu32(x, y), y)", f216, 0, 128},
  {"128:_mm_srlv_epi32(x, _mm_min_epu32(x, y))", f217, 0, 128},
  {"128:_mm_srlv_epi32(_mm_min_epu32(x, y), x)", f218, 0, 128},
  {"128:_mm_srlv_epi32(y, _mm_min_epu32(x, y))", f219, 0, 128},
  {"128:_mm_srlv_epi32(_mm_max_epu32(x, y), y)", f220, 0, 128},
  {"128:_mm_srlv_epi32(x, _mm_max_epu32(x, y))", f221, 0, 128},
  {"128:_mm_srlv_epi32(_mm_max_epu32(x, y), x)", f222, 0, 128},
  {"128:_mm_srlv_epi32(y, _mm_max_epu32(x, y))", f223, 0, 128},
  {"128:_mm_srlv_epi32(_mm_and_si128(x, y), y)", f224, 0, 128},
  {"128:_mm_srlv_epi32(x, _mm_and_si128(x, y))", f225, 0, 128},
  {"128:_mm_srlv_epi32(_mm_and_si128(x, y), x)", f226, 0, 128},
  {"128:_mm_srlv_epi32(y, _mm_and_si128(x, y))", f227, 0, 128},
  {"128:_mm_srlv_epi32(_mm_or_si128(x, y), y)", f228, 0, 128},
  {"128:_mm_srlv_epi32(x, _mm_or_si128(x, y))", f229, 0, 128},
  {"128:_mm_srlv_epi32(_mm_or_si128(x, y), x)", f230, 0, 128},
  {"128:_mm_srlv_epi32(y, _mm_or_si128(x, y))", f231, 0, 128},
  {"128:_mm_srlv_epi32(_mm_xor_si128(x, y), y)", f232, 0, 128},
  {"128:_mm_srlv_epi32(x, _mm_xor_si128(x, y))", f233, 0, 128},
  {"128:_mm_srlv_epi32(_mm_xor_si128(x, y), x)", f234, 0, 128},
  {"128:_mm_srlv_epi32(y, _mm_xor_si128(x, y))", f235, 0, 128},
  {"128:_mm_srlv_epi32(_mm_andnot_si128(x, y), y)", f236, 0, 128},
  {"128:_mm_srlv_epi32(x, _mm_andnot_si128(x, y))", f237, 0, 128},
  {"128:_mm_srlv_epi32(_mm_andnot_si128(x, y), x)", f238, 0, 128},
  {"128:_mm_srlv_epi32(y, _mm_andnot_si128(x, y))", f239, 0, 128},
  {"128:_mm_srlv_epi32(_mm_cmpeq_epi32(x, y), y)", f240, 0, 128},
  {"128:_mm_srlv_epi32(x, _mm_cmpeq_epi32(x, y))", f241, 0, 128},
  {"128:_mm_srlv_epi32(_mm_cmpeq_epi32(x, y), x)", f242, 0, 128},
  {"128:_mm_srlv_epi32(y, _mm_cmpeq_epi32(x, y))", f243, 0, 128},
  {"128:_mm_srlv_epi32(_mm_cmpgt_epi32(x, y), y)", f244, 0, 128},
  {"128:_mm_srlv_epi32(x, _mm_cmpgt_epi32(x, y))", f245, 0, 128},
  {"128:_mm_srlv_epi32(_mm_cmpgt_epi32(x, y), x)", f246, 0, 128},
  {"128:_mm_srlv_epi32(y, _mm_cmpgt_epi32(x, y))", f247, 0, 128},
  {"128:_mm_srlv_epi32(_mm_sign_epi32(x, y), y)", f248, 0, 128},
  {"128:_mm_srlv_epi32(x, _mm_sign_epi32(x, y))", f249, 0, 128},
  {"128:_mm_srlv_epi32(_mm_sign_epi32(x, y), x)", f250, 0, 128},
  {"128:_mm_srlv_epi32(y, _mm_sign_epi32(x, y))", f251, 0, 128},
  {"128:_mm_srlv_epi32(_mm_packs_epi32(x, y), y)", f252, 0, 128},
  {"128:_mm_srlv_epi32(x, _mm_packs_epi32(x, y))", f253, 0, 128},
  {"128:_mm_srlv_epi32(_mm_packs_epi32(x, y), x)", f254, 0, 128},
  {"128:_mm_srlv_epi32(y, _mm_packs_epi32(x, y))", f255, 0, 128},
  {"128:_mm_srlv_epi32(_mm_packus_epi32(x, y), y)", f256, 0, 128},
  {"128:_mm_srlv_epi32(x, _mm_packus_epi32(x, y))", f257, 0, 128},
  {"128:_mm_srlv_epi32(_mm_packus_epi32(x, y), x)", f258, 0, 128},
  {"128:_mm_srlv_epi32(y, _mm_packus_epi32(x, y))", f259, 0, 128},
  {"128:_mm_srlv_epi32(_mm_hadd_epi32(x, y), y)", f260, 0, 128},
  {"128:_mm_srlv_epi32(x, _mm_hadd_epi32(x, y))", f261, 0, 128},
  {"128:_mm_srlv_epi32(_mm_hadd_epi32(x, y), x)", f262, 0, 128},
  {"128:_mm_srlv_epi32(y, _mm_hadd_epi32(x, y))", f263, 0, 128},
  {"128:_mm_srlv_epi32(_mm_hsub_epi32(x, y), y)", f264, 0, 128},
  {"128:_mm_srlv_epi32(x, _mm_hsub_epi32(x, y))", f265, 0, 128},
  {"128:_mm_srlv_epi32(_mm_hsub_epi32(x, y), x)", f266, 0, 128},
  {"128:_mm_srlv_epi32(y, _mm_hsub_epi32(x, y))", f267, 0, 128},
  {"128:_mm_srlv_epi32(_mm_mul_epi32(x, y), y)", f268, 0, 128},
  {"128:_mm_srlv_epi32(x, _mm_mul_epi32(x, y))", f269, 0, 128},
  {"128:_mm_srlv_epi32(_mm_mul_epi32(x, y), x)", f270, 0, 128},
  {"128:_mm_srlv_epi32(y, _mm_mul_epi32(x, y))", f271, 0, 128},
  {"128:_mm_srlv_epi32(_mm_mul_epu32(x, y), y)", f272, 0, 128},
  {"128:_mm_srlv_epi32(x, _mm_mul_epu32(x, y))", f273, 0, 128},
  {"128:_mm_srlv_epi32(_mm_mul_epu32(x, y), x)", f274, 0, 128},
  {"128:_mm_srlv_epi32(y, _mm_mul_epu32(x, y))", f275, 0, 128},
  {"128:_mm_srlv_epi32(_mm_unpacklo_epi32(x, y), y)", f276, 0, 128},
  {"128:_mm_srlv_epi32(x, _mm_unpacklo_epi32(x, y))", f277, 0, 128},
  {"128:_mm_srlv_epi32(_mm_unpacklo_epi32(x, y), x)", f278, 0, 128},
  {"128:_mm_srlv_epi32(y, _mm_unpacklo_epi32(x, y))", f279, 0, 128},
  {"128:_mm_srlv_epi32(_mm_unpackhi_epi32(x, y), y)", f280, 0, 128},
  {"128:_mm_srlv_epi32(x, _mm_unpackhi_epi32(x, y))", f281, 0, 128},
  {"128:_mm_srlv_epi32(_mm_unpackhi_epi32(x, y), x)", f282, 0, 128},
  {"128:_mm_srlv_epi32(y, _mm_unpackhi_epi32(x, y))", f283, 0, 128},
  {"128:_mm_srlv_epi32(_mm_blendv_epi8(x, y, _mm_cmpgt_epi32(x, y)), y)", f284, 0, 128},
  {"128:_mm_srlv_epi32(x, _mm_blendv_epi8(x, y, _mm_cmpgt_epi32(x, y)))", f285, 0, 128},
  {"128:_mm_srlv_epi32(_mm_blendv_epi8(x, y, _mm_cmpgt_epi32(x, y)), x)", f286, 0, 128},
  {"128:_mm_srlv_epi32(y, _mm_blendv_epi8(x, y, _mm_cmpgt_epi32(x, y)))", f287, 0, 128},
  {"128:_mm_srlv_epi32(_mm_blendv_epi8(y, x, _mm_cmpgt_epi32(x, y)), y)", f288, 0, 128},
  {"128:_mm_srlv_epi32(x, _mm_blendv_epi8(y, x, _mm_cmpgt_epi32(x, y)))", f289, 0, 128},
  {"128:_mm_srlv_epi32(_mm_blendv_epi8(y, x, _mm_cmpgt_epi32(x, y)), x)", f290, 0, 128},
  {"128:_mm_srlv_epi32(y, _mm_blendv_epi8(y, x, _mm_cmpgt_epi32(x, y)))", f291, 0, 128},
  {"128:_mm_srlv_epi32(_mm_or_si128(_mm_and_si128(_mm_cmpgt_epi32(x, y), x), _mm_andnot_si128(_mm_cmpgt_epi32(x, y), y)), y)", f292, 0, 128},
  {"128:_mm_srlv_epi32(x, _mm_or_si128(_mm_and_si128(_mm_cmpgt_epi32(x, y), x), _mm_andnot_si128(_mm_cmpgt_epi32(x, y), y)))", f293, 0, 128},
  {"128:_mm_srlv_epi32(_mm_or_si128(_mm_and_si128(_mm_cmpgt_epi32(x, y), x), _mm_andnot_si128(_mm_cmpgt_epi32(x, y), y)), x)", f294, 0, 128},
  {"128:_mm_srlv_epi32(y, _mm_or_si128(_mm_and_si128(_mm_cmpgt_epi32(x, y), x), _mm_andnot_si128(_mm_cmpgt_epi32(x, y), y)))", f295, 0, 128},
  {"128:_mm_srlv_epi32(_mm_blendv_epi8(x, y, _mm_cmpeq_epi32(x, y)), y)", f296, 0, 128},
  {"128:_mm_srlv_epi32(x, _mm_blendv_epi8(x, y, _mm_cmpeq_epi32(x, y)))", f297, 0, 128},
  {"128:_mm_srlv_epi32(_mm_blendv_epi8(x, y, _mm_cmpeq_epi32(x, y)), x)", f298, 0, 128},
  {"128:_mm_srlv_epi32(y, _mm_blendv_epi8(x, y, _mm_cmpeq_epi32(x, y)))", f299, 0, 128},
  {"128:_mm_srlv_epi32(_mm_blendv_epi8(y, x, _mm_cmpeq_epi32(x, y)), y)", f300, 0, 128},
  {"128:_mm_srlv_epi32(x, _mm_blendv_epi8(y, x, _mm_cmpeq_epi32(x, y)))", f301, 0, 128},
  {"128:_mm_srlv_epi32(_mm_blendv_epi8(y, x, _mm_cmpeq_epi32(x, y)), x)", f302, 0, 128},
  {"128:_mm_srlv_epi32(y, _mm_blendv_epi8(y, x, _mm_cmpeq_epi32(x, y)))", f303, 0, 128},
  {"128:_mm_srlv_epi32(_mm_or_si128(_mm_and_si128(_mm_cmpeq_epi32(x, y), x), _mm_andnot_si128(_mm_cmpeq_epi32(x, y), y)), y)", f304, 0, 128},
  {"128:_mm_srlv_epi32(x, _mm_or_si128(_mm_and_si128(_mm_cmpeq_epi32(x, y), x), _mm_andnot_si128(_mm_cmpeq_epi32(x, y), y)))", f305, 0, 128},
  {"128:_mm_srlv_epi32(_mm_or_si128(_mm_and_si128(_mm_cmpeq_epi32(x, y), x), _mm_andnot_si128(_mm_cmpeq_epi32(x, y), y)), x)", f306, 0, 128},
  {"128:_mm_srlv_epi32(y, _mm_or_si128(_mm_and_si128(_mm_cmpeq_epi32(x, y), x), _mm_andnot_si128(_mm_cmpeq_epi32(x, y), y)))", f307, 0, 128},
  {"128:_mm_srlv_epi32(_mm_mullo_epi32(x, y), y)", f308, 0, 128},
  {"128:_mm_srlv_epi32(x, _mm_mullo_epi32(x, y))", f309, 0, 128},
  {"128:_mm_srlv_epi32(_mm_mullo_epi32(x, y), x)", f310, 0, 128},
  {"128:_mm_srlv_epi32(y, _mm_mullo_epi32(x, y))", f311, 0, 128},
  {"128:_mm_srlv_epi32(_mm_sllv_epi32(x, y), y)", f312, 0, 128},
  {"128:_mm_srlv_epi32(x, _mm_sllv_epi32(x, y))", f313, 0, 128},
  {"128:_mm_srlv_epi32(_mm_sllv_epi32(x, y), x)", f314, 0, 128},
  {"128:_mm_srlv_epi32(y, _mm_sllv_epi32(x, y))", f315, 0, 128},
  {"128:_mm_srlv_epi32(_mm_srlv_epi32(x, y), y)", f316, 0, 128},
  {"128:_mm_srlv_epi32(x, _mm_srlv_epi32(x, y))", f317, 0, 128},
  {"128:_mm_srlv_epi32(_mm_srlv_epi32(x, y), x)", f318, 0, 128},
  {"128:_mm_srlv_epi32(y, _mm_srlv_epi32(x, y))", f319, 0, 128},
  {"128:_mm_srlv_epi32(_mm_srav_epi32(x, y), y)", f320, 0, 128},
  {"128:_mm_srlv_epi32(x, _mm_srav_epi32(x, y))", f321, 0, 128},
  {"128:_mm_srlv_epi32(_mm_srav_epi32(x, y), x)", f322, 0, 128},
  {"128:_mm_srlv_epi32(y, _mm_srav_epi32(x, y))", f323, 0, 128},
  {"128:_mm_sllv_epi64(_mm_add_epi64(x, y), y)", f324, 0, 128},
  {"128:_mm_sllv_epi64(x, _mm_add_epi64(x, y))", f325, 0, 128},
  {"128:_mm_sllv_epi64(_mm_add_epi64(x, y), x)", f326, 0, 128},
  {"128:_mm_sllv_epi64(y, _mm_add_epi64(x, y))", f327, 0, 128},
  {"128:_mm_sllv_epi64(_mm_sub_epi64(x, y), y)", f328, 0, 128},
  {"128:_mm_sllv_epi64(x, _mm_sub_epi64(x, y))", f329, 0, 128},
  {"128:_mm_sllv_epi64(_mm_sub_epi64(x, y), x)", f330, 0, 128},
  {"128:_mm_sllv_epi64(y, _mm_sub_epi64(x, y))", f331, 0, 128},
  {"128:_mm_sllv_epi64(_mm_and_si128(x, y), y)", f332, 0, 128},
  {"128:_mm_sllv_epi64(x, _mm_and_si128(x, y))", f333, 0, 128},
  {"128:_mm_sllv_epi64(_mm_and_si128(x, y), x)", f334, 0, 128},
  {"128:_mm_sllv_epi64(y, _mm_and_si128(x, y))", f335, 0, 128},
  {"128:_mm_sllv_epi64(_mm_or_si128(x, y), y)", f336, 0, 128},
  {"128:_mm_sllv_epi64(x, _mm_or_si128(x, y))", f337, 0, 128},
  {"128:_mm_sllv_epi64(_mm_or_si128(x, y), x)", f338, 0, 128},
  {"128:_mm_sllv_epi64(y, _mm_or_si128(x, y))", f339, 0, 128},
  {"128:_mm_sllv_epi64(_mm_xor_si128(x, y), y)", f340, 0, 128},
  {"128:_mm_sllv_epi64(x, _mm_xor_si128(x, y))", f341, 0, 128},
  {"128:_mm_sllv_epi64(_mm_xor_si128(x, y), x)", f342, 0, 128},
  {"128:_mm_sllv_epi64(y, _mm_xor_si128(x, y))", f343, 0, 128},
  {"128:_mm_sllv_epi64(_mm_andnot_si128(x, y), y)", f344, 0, 128},
  {"128:_mm_sllv_epi64(x, _mm_andnot_si128(x, y))", f345, 0, 128},
  {"128:_mm_sllv_epi64(_mm_andnot_si128(x, y), x)", f346, 0, 128},
  {"128:_mm_sllv_epi64(y, _mm_andnot_si128(x, y))", f347, 0, 128},
  {"128:_mm_sllv_epi64(_mm_cmpeq_epi64(x, y), y)", f348, 0, 128},
  {"128:_mm_sllv_epi64(x, _mm_cmpeq_epi64(x, y))", f349, 0, 128},
  {"128:_mm_sllv_epi64(_mm_cmpeq_epi64(x, y), x)", f350, 0, 128},
  {"128:_mm_sllv_epi64(y, _mm_cmpeq_epi64(x, y))", f351, 0, 128},
  {"128:_mm_sllv_epi64(_mm_cmpgt_epi64(x, y), y)", f352, 0, 128},
  {"128:_mm_sllv_epi64(x, _mm_cmpgt_epi64(x, y))", f353, 0, 128},
  {"128:_mm_sllv_epi64(_mm_cmpgt_epi64(x, y), x)", f354, 0, 128},
  {"128:_mm_sllv_epi64(y, _mm_cmpgt_epi64(x, y))", f355, 0, 128},
  {"128:_mm_sllv_epi64(_mm_unpacklo_epi64(x, y), y)", f356, 0, 128},
  {"128:_mm_sllv_epi64(x, _mm_unpacklo_epi64(x, y))", f357, 0, 128},
  {"128:_mm_sllv_epi64(_mm_unpacklo_epi64(x, y), x)", f358, 0, 128},
  {"128:_mm_sllv_epi64(y, _mm_unpacklo_epi64(x, y))", f359, 0, 128},
  {"128:_mm_sllv_epi64(_mm_unpackhi_epi64(x, y), y)", f360, 0, 128},
  {"128:_mm_sllv_epi64(x, _mm_unpackhi_epi64(x, y))", f361, 0, 128},
  {"128:_mm_sllv_epi64(_mm_unpackhi_epi64(x, y), x)", f362, 0, 128},
  {"128:_mm_sllv_epi64(y, _mm_unpackhi_epi64(x, y))", f363, 0, 128},
  {"128:_mm_sllv_epi64(_mm_blendv_epi8(x, y, _mm_cmpgt_epi64(x, y)), y)", f364, 0, 128},
  {"128:_mm_sllv_epi64(x, _mm_blendv_epi8(x, y, _mm_cmpgt_epi64(x, y)))", f365, 0, 128},
  {"128:_mm_sllv_epi64(_mm_blendv_epi8(x, y, _mm_cmpgt_epi64(x, y)), x)", f366, 0, 128},
  {"128:_mm_sllv_epi64(y, _mm_blendv_epi8(x, y, _mm_cmpgt_epi64(x, y)))", f367, 0, 128},
  {"128:_mm_sllv_epi64(_mm_blendv_epi8(y, x, _mm_cmpgt_epi64(x, y)), y)", f368, 0, 128},
  {"128:_mm_sllv_epi64(x, _mm_blendv_epi8(y, x, _mm_cmpgt_epi64(x, y)))", f369, 0, 128},
  {"128:_mm_sllv_epi64(_mm_blendv_epi8(y, x, _mm_cmpgt_epi64(x, y)), x)", f370, 0, 128},
  {"128:_mm_sllv_epi64(y, _mm_blendv_epi8(y, x, _mm_cmpgt_epi64(x, y)))", f371, 0, 128},
  {"128:_mm_sllv_epi64(_mm_or_si128(_mm_and_si128(_mm_cmpgt_epi64(x, y), x), _mm_andnot_si128(_mm_cmpgt_epi64(x, y), y)), y)", f372, 0, 128},
  {"128:_mm_sllv_epi64(x, _mm_or_si128(_mm_and_si128(_mm_cmpgt_epi64(x, y), x), _mm_andnot_si128(_mm_cmpgt_epi64(x, y), y)))", f373, 0, 128},
  {"128:_mm_sllv_epi64(_mm_or_si128(_mm_and_si128(_mm_cmpgt_epi64(x, y), x), _mm_andnot_si128(_mm_cmpgt_epi64(x, y), y)), x)", f374, 0, 128},
  {"128:_mm_sllv_epi64(y, _mm_or_si128(_mm_and_si128(_mm_cmpgt_epi64(x, y), x), _mm_andnot_si128(_mm_cmpgt_epi64(x, y), y)))", f375, 0, 128},
  {"128:_mm_sllv_epi64(_mm_blendv_epi8(x, y, _mm_cmpeq_epi64(x, y)), y)", f376, 0, 128},
  {"128:_mm_sllv_epi64(x, _mm_blendv_epi8(x, y, _mm_cmpeq_epi64(x, y)))", f377, 0, 128},
  {"128:_mm_sllv_epi64(_mm_blendv_epi8(x, y, _mm_cmpeq_epi64(x, y)), x)", f378, 0, 128},
  {"128:_mm_sllv_epi64(y, _mm_blendv_epi8(x, y, _mm_cmpeq_epi64(x, y)))", f379, 0, 128},
  {"128:_mm_sllv_epi64(_mm_blendv_epi8(y, x, _mm_cmpeq_epi64(x, y)), y)", f380, 0, 128},
  {"128:_mm_sllv_epi64(x, _mm_blendv_epi8(y, x, _mm_cmpeq_epi64(x, y)))", f381, 0, 128},
  {"128:_mm_sllv_epi64(_mm_blendv_epi8(y, x, _mm_cmpeq_epi64(x, y)), x)", f382, 0, 128},
  {"128:_mm_sllv_epi64(y, _mm_blendv_epi8(y, x, _mm_cmpeq_epi64(x, y)))", f383, 0, 128},
  {"128:_mm_sllv_epi64(_mm_or_si128(_mm_and_si128(_mm_cmpeq_epi64(x, y), x), _mm_andnot_si128(_mm_cmpeq_epi64(x, y), y)), y)", f384, 0, 128},
  {"128:_mm_sllv_epi64(x, _mm_or_si128(_mm_and_si128(_mm_cmpeq_epi64(x, y), x), _mm_andnot_si128(_mm_cmpeq_epi64(x, y), y)))", f385, 0, 128},
  {"128:_mm_sllv_epi64(_mm_or_si128(_mm_and_si128(_mm_cmpeq_epi64(x, y), x), _mm_andnot_si128(_mm_cmpeq_epi64(x, y), y)), x)", f386, 0, 128},
  {"128:_mm_sllv_epi64(y, _mm_or_si128(_mm_and_si128(_mm_cmpeq_epi64(x, y), x), _mm_andnot_si128(_mm_cmpeq_epi64(x, y), y)))", f387, 0, 128},
  {"128:_mm_sllv_epi64(_mm_sllv_epi64(x, y), y)", f388, 0, 128},
  {"128:_mm_sllv_epi64(x, _mm_sllv_epi64(x, y))", f389, 0, 128},
  {"128:_mm_sllv_epi64(_mm_sllv_epi64(x, y), x)", f390, 0, 128},
  {"128:_mm_sllv_epi64(y, _mm_sllv_epi64(x, y))", f391, 0, 128},
  {"128:_mm_sllv_epi64(_mm_srlv_epi64(x, y), y)", f392, 0, 128},
  {"128:_mm_sllv_epi64(x, _mm_srlv_epi64(x, y))", f393, 0, 128},
  {"128:_mm_sllv_epi64(_mm_srlv_epi64(x, y), x)", f394, 0, 128},
  {"128:_mm_sllv_epi64(y, _mm_srlv_epi64(x, y))", f395, 0, 128},
  {"128:_mm_srlv_epi64(_mm_add_epi64(x, y), y)", f396, 0, 128},
  {"128:_mm_srlv_epi64(x, _mm_add_epi64(x, y))", f397, 0, 128},
  {"128:_mm_srlv_epi64(_mm_add_epi64(x, y), x)", f398, 0, 128},
  {"128:_mm_srlv_epi64(y, _mm_add_epi64(x, y))", f399, 0, 128},
  {"128:_mm_srlv_epi64(_mm_sub_epi64(x, y), y)", f400, 0, 128},
  {"128:_mm_srlv_epi64(x, _mm_sub_epi64(x, y))", f401, 0, 128},
  {"128:_mm_srlv_epi64(_mm_sub_epi64(x, y), x)", f402, 0, 128},
  {"128:_mm_srlv_epi64(y, _mm_sub_epi64(x, y))", f403, 0, 128},
  {"128:_mm_srlv_epi64(_mm_and_si128(x, y), y)", f404, 0, 128},
  {"128:_mm_srlv_epi64(x, _mm_and_si128(x, y))", f405, 0, 128},
  {"128:_mm_srlv_epi64(_mm_and_si128(x, y), x)", f406, 0, 128},
  {"128:_mm_srlv_epi64(y, _mm_and_si128(x, y))", f407, 0, 128},
  {"128:_mm_srlv_epi64(_mm_or_si128(x, y), y)", f408, 0, 128},
  {"128:_mm_srlv_epi64(x, _mm_or_si128(x, y))", f409, 0, 128},
  {"128:_mm_srlv_epi64(_mm_or_si128(x, y), x)", f410, 0, 128},
  {"128:_mm_srlv_epi64(y, _mm_or_si128(x, y))", f411, 0, 128},
  {"128:_mm_srlv_epi64(_mm_xor_si128(x, y), y)", f412, 0, 128},
  {"128:_mm_srlv_epi64(x, _mm_xor_si128(x, y))", f413, 0, 128},
  {"128:_mm_srlv_epi64(_mm_xor_si128(x, y), x)", f414, 0, 128},
  {"128:_mm_srlv_epi64(y, _mm_xor_si128(x, y))", f415, 0, 128},
  {"128:_mm_srlv_epi64(_mm_andnot_si128(x, y), y)", f416, 0, 128},
  {"128:_mm_srlv_epi64(x, _mm_andnot_si128(x, y))", f417, 0, 128},
  {"128:_mm_srlv_epi64(_mm_andnot_si128(x, y), x)", f418, 0, 128},
  {"128:_mm_srlv_epi64(y, _mm_andnot_si128(x, y))", f419, 0, 128},
  {"128:_mm_srlv_epi64(_mm_cmpeq_epi64(x, y), y)", f420, 0, 128},
  {"128:_mm_srlv_epi64(x, _mm_cmpeq_epi64(x, y))", f421, 0, 128},
  {"128:_mm_srlv_epi64(_mm_cmpeq_epi64(x, y), x)", f422, 0, 128},
  {"128:_mm_srlv_epi64(y, _mm_cmpeq_epi64(x, y))", f423, 0, 128},
  {"128:_mm_srlv_epi64(_mm_cmpgt_epi64(x, y), y)", f424, 0, 128},
  {"128:_mm_srlv_epi64(x, _mm_cmpgt_epi64(x, y))", f425, 0, 128},
  {"128:_mm_srlv_epi64(_mm_cmpgt_epi64(x, y), x)", f426, 0, 128},
  {"128:_mm_srlv_epi64(y, _mm_cmpgt_epi64(x, y))", f427, 0, 128},
  {"128:_mm_srlv_epi64(_mm_unpacklo_epi64(x, y), y)", f428, 0, 128},
  {"128:_mm_srlv_epi64(x, _mm_unpacklo_epi64(x, y))", f429, 0, 128},
  {"128:_mm_srlv_epi64(_mm_unpacklo_epi64(x, y), x)", f430, 0, 128},
  {"128:_mm_srlv_epi64(y, _mm_unpacklo_epi64(x, y))", f431, 0, 128},
  {"128:_mm_srlv_epi64(_mm_unpackhi_epi64(x, y), y)", f432, 0, 128},
  {"128:_mm_srlv_epi64(x, _mm_unpackhi_epi64(x, y))", f433, 0, 128},
  {"128:_mm_srlv_epi64(_mm_unpackhi_epi64(x, y), x)", f434, 0, 128},
  {"128:_mm_srlv_epi64(y, _mm_unpackhi_epi64(x, y))", f435, 0, 128},
  {"128:_mm_srlv_epi64(_mm_blendv_epi8(x, y, _mm_cmpgt_epi64(x, y)), y)", f436, 0, 128},
  {"128:_mm_srlv_epi64(x, _mm_blendv_epi8(x, y, _mm_cmpgt_epi64(x, y)))", f437, 0, 128},
  {"128:_mm_srlv_epi64(_mm_blendv_epi8(x, y, _mm_cmpgt_epi64(x, y)), x)", f438, 0, 128},
  {"128:_mm_srlv_epi64(y, _mm_blendv_epi8(x, y, _mm_cmpgt_epi64(x, y)))", f439, 0, 128},
  {"128:_mm_srlv_epi64(_mm_blendv_epi8(y, x, _mm_cmpgt_epi64(x, y)), y)", f440, 0, 128},
  {"128:_mm_srlv_epi64(x, _mm_blendv_epi8(y, x, _mm_cmpgt_epi64(x, y)))", f441, 0, 128},
  {"128:_mm_srlv_epi64(_mm_blendv_epi8(y, x, _mm_cmpgt_epi64(x, y)), x)", f442, 0, 128},
  {"128:_mm_srlv_epi64(y, _mm_blendv_epi8(y, x, _mm_cmpgt_epi64(x, y)))", f443, 0, 128},
  {"128:_mm_srlv_epi64(_mm_or_si128(_mm_and_si128(_mm_cmpgt_epi64(x, y), x), _mm_andnot_si128(_mm_cmpgt_epi64(x, y), y)), y)", f444, 0, 128},
  {"128:_mm_srlv_epi64(x, _mm_or_si128(_mm_and_si128(_mm_cmpgt_epi64(x, y), x), _mm_andnot_si128(_mm_cmpgt_epi64(x, y), y)))", f445, 0, 128},
  {"128:_mm_srlv_epi64(_mm_or_si128(_mm_and_si128(_mm_cmpgt_epi64(x, y), x), _mm_andnot_si128(_mm_cmpgt_epi64(x, y), y)), x)", f446, 0, 128},
  {"128:_mm_srlv_epi64(y, _mm_or_si128(_mm_and_si128(_mm_cmpgt_epi64(x, y), x), _mm_andnot_si128(_mm_cmpgt_epi64(x, y), y)))", f447, 0, 128},
  {"128:_mm_srlv_epi64(_mm_blendv_epi8(x, y, _mm_cmpeq_epi64(x, y)), y)", f448, 0, 128},
  {"128:_mm_srlv_epi64(x, _mm_blendv_epi8(x, y, _mm_cmpeq_epi64(x, y)))", f449, 0, 128},
  {"128:_mm_srlv_epi64(_mm_blendv_epi8(x, y, _mm_cmpeq_epi64(x, y)), x)", f450, 0, 128},
  {"128:_mm_srlv_epi64(y, _mm_blendv_epi8(x, y, _mm_cmpeq_epi64(x, y)))", f451, 0, 128},
  {"128:_mm_srlv_epi64(_mm_blendv_epi8(y, x, _mm_cmpeq_epi64(x, y)), y)", f452, 0, 128},
  {"128:_mm_srlv_epi64(x, _mm_blendv_epi8(y, x, _mm_cmpeq_epi64(x, y)))", f453, 0, 128},
  {"128:_mm_srlv_epi64(_mm_blendv_epi8(y, x, _mm_cmpeq_epi64(x, y)), x)", f454, 0, 128},
  {"128:_mm_srlv_epi64(y, _mm_blendv_epi8(y, x, _mm_cmpeq_epi64(x, y)))", f455, 0, 128},
  {"128:_mm_srlv_epi64(_mm_or_si128(_mm_and_si128(_mm_cmpeq_epi64(x, y), x), _mm_andnot_si128(_mm_cmpeq_epi64(x, y), y)), y)", f456, 0, 128},
  {"128:_mm_srlv_epi64(x, _mm_or_si128(_mm_and_si128(_mm_cmpeq_epi64(x, y), x), _mm_andnot_si128(_mm_cmpeq_epi64(x, y), y)))", f457, 0, 128},
  {"128:_mm_srlv_epi64(_mm_or_si128(_mm_and_si128(_mm_cmpeq_epi64(x, y), x), _mm_andnot_si128(_mm_cmpeq_epi64(x, y), y)), x)", f458, 0, 128},
  {"128:_mm_srlv_epi64(y, _mm_or_si128(_mm_and_si128(_mm_cmpeq_epi64(x, y), x), _mm_andnot_si128(_mm_cmpeq_epi64(x, y), y)))", f459, 0, 128},
  {"128:_mm_srlv_epi64(_mm_sllv_epi64(x, y), y)", f460, 0, 128},
  {"128:_mm_srlv_epi64(x, _mm_sllv_epi64(x, y))", f461, 0, 128},
  {"128:_mm_srlv_epi64(_mm_sllv_epi64(x, y), x)", f462, 0, 128},
  {"128:_mm_srlv_epi64(y, _mm_sllv_epi64(x, y))", f463, 0, 128},
  {"128:_mm_srlv_epi64(_mm_srlv_epi64(x, y), y)", f464, 0, 128},
  {"128:_mm_srlv_epi64(x, _mm_srlv_epi64(x, y))", f465, 0, 128},
  {"128:_mm_srlv_epi64(_mm_srlv_epi64(x, y), x)", f466, 0, 128},
  {"128:_mm_srlv_epi64(y, _mm_srlv_epi64(x, y))", f467, 0, 128},
  {"128:_mm_srav_epi32(_mm_add_epi32(x, y), y)", f468, 0, 128},
  {"128:_mm_srav_epi32(x, _mm_add_epi32(x, y))", f469, 0, 128},
  {"128:_mm_srav_epi32(_mm_add_epi32(x, y), x)", f470, 0, 128},
  {"128:_mm_srav_epi32(y, _mm_add_epi32(x, y))", f471, 0, 128},
  {"128:_mm_srav_epi32(_mm_sub_epi32(x, y), y)", f472, 0, 128},
  {"128:_mm_srav_epi32(x, _mm_sub_epi32(x, y))", f473, 0, 128},
  {"128:_mm_srav_epi32(_mm_sub_epi32(x, y), x)", f474, 0, 128},
  {"128:_mm_srav_epi32(y, _mm_sub_epi32(x, y))", f475, 0, 128},
  {"128:_mm_srav_epi32(_mm_min_epi32(x, y), y)", f476, 0, 128},
  {"128:_mm_srav_epi32(x, _mm_min_epi32(x, y))", f477, 0, 128},
  {"128:_mm_srav_epi32(_mm_min_epi32(x, y), x)", f478, 0, 128},
  {"128:_mm_srav_epi32(y, _mm_min_epi32(x, y))", f479, 0, 128},
  {"128:_mm_srav_epi32(_mm_max_epi32(x, y), y)", f480, 0, 128},
  {"128:_mm_srav_epi32(x, _mm_max_epi32(x, y))", f481, 0, 128},
  {"128:_mm_srav_epi32(_mm_max_epi32(x, y), x)", f482, 0, 128},
  {"128:_mm_srav_epi32(y, _mm_max_epi32(x, y))", f483, 0, 128},
  {"128:_mm_srav_epi32(_mm_min_epu32(x, y), y)", f484, 0, 128},
  {"128:_mm_srav_epi32(x, _mm_min_epu32(x, y))", f485, 0, 128},
  {"128:_mm_srav_epi32(_mm_min_epu32(x, y), x)", f486, 0, 128},
  {"128:_mm_srav_epi32(y, _mm_min_epu32(x, y))", f487, 0, 128},
  {"128:_mm_srav_epi32(_mm_max_epu32(x, y), y)", f488, 0, 128},
  {"128:_mm_srav_epi32(x, _mm_max_epu32(x, y))", f489, 0, 128},
  {"128:_mm_srav_epi32(_mm_max_epu32(x, y), x)", f490, 0, 128},
  {"128:_mm_srav_epi32(y, _mm_max_epu32(x, y))", f491, 0, 128},
  {"128:_mm_srav_epi32(_mm_and_si128(x, y), y)", f492, 0, 128},
  {"128:_mm_srav_epi32(x, _mm_and_si128(x, y))", f493, 0, 128},
  {"128:_mm_srav_epi32(_mm_and_si128(x, y), x)", f494, 0, 128},
  {"128:_mm_srav_epi32(y, _mm_and_si128(x, y))", f495, 0, 128},
  {"128:_mm_srav_epi32(_mm_or_si128(x, y), y)", f496, 0, 128},
  {"128:_mm_srav_epi32(x, _mm_or_si128(x, y))", f497, 0, 128},
  {"128:_mm_srav_epi32(_mm_or_si128(x, y), x)", f498, 0, 128},
  {"128:_mm_srav_epi32(y, _mm_or_si128(x, y))", f499, 0, 128},
  {"128:_mm_srav_epi32(_mm_xor_si128(x, y), y)", f500, 0, 128},
  {"128:_mm_srav_epi32(x, _mm_xor_si128(x, y))", f501, 0, 128},
  {"128:_mm_srav_epi32(_mm_xor_si128(x, y), x)", f502, 0, 128},
  {"128:_mm_srav_epi32(y, _mm_xor_si128(x, y))", f503, 0, 128},
  {"128:_mm_srav_epi32(_mm_andnot_si128(x, y), y)", f504, 0, 128},
  {"128:_mm_srav_epi32(x, _mm_andnot_si128(x, y))", f505, 0, 128},
  {"128:_mm_srav_epi32(_mm_andnot_si128(x, y), x)", f506, 0, 128},
  {"128:_mm_srav_epi32(y, _mm_andnot_si128(x, y))", f507, 0, 128},
  {"128:_mm_srav_epi32(_mm_cmpeq_epi32(x, y), y)", f508, 0, 128},
  {"128:_mm_srav_epi32(x, _mm_cmpeq_epi32(x, y))", f509, 0, 128},
  {"128:_mm_srav_epi32(_mm_cmpeq_epi32(x, y), x)", f510, 0, 128},
  {"128:_mm_srav_epi32(y, _mm_cmpeq_epi32(x, y))", f511, 0, 128},
  {"128:_mm_srav_epi32(_mm_cmpgt_epi32(x, y), y)", f512, 0, 128},
  {"128:_mm_srav_epi32(x, _mm_cmpgt_epi32(x, y))", f513, 0, 128},
  {"128:_mm_srav_epi32(_mm_cmpgt_epi32(x, y), x)", f514, 0, 128},
  {"128:_mm_srav_epi32(y, _mm_cmpgt_epi32(x, y))", f515, 0, 128},
  {"128:_mm_srav_epi32(_mm_sign_epi32(x, y), y)", f516, 0, 128},
  {"128:_mm_srav_epi32(x, _mm_sign_epi32(x, y))", f517, 0, 128},
  {"128:_mm_srav_epi32(_mm_sign_epi32(x, y), x)", f518, 0, 128},
  {"128:_mm_srav_epi32(y, _mm_sign_epi32(x, y))", f519, 0, 128},
  {"128:_mm_srav_epi32(_mm_packs_epi32(x, y), y)", f520, 0, 128},
  {"128:_mm_srav_epi32(x, _mm_packs_epi32(x, y))", f521, 0, 128},
  {"128:_mm_srav_epi32(_mm_packs_epi32(x, y), x)", f522, 0, 128},
  {"128:_mm_srav_epi32(y, _mm_packs_epi32(x, y))", f523, 0, 128},
  {"128:_mm_srav_epi32(_mm_packus_epi32(x, y), y)", f524, 0, 128},
  {"128:_mm_srav_epi32(x, _mm_packus_epi32(x, y))", f525, 0, 128},
  {"128:_mm_srav_epi32(_mm_packus_epi32(x, y), x)", f526, 0, 128},
  {"128:_mm_srav_epi32(y, _mm_packus_epi32(x, y))", f527, 0, 128},
  {"128:_mm_srav_epi32(_mm_hadd_epi32(x, y), y)", f528, 0, 128},
  {"128:_mm_srav_epi32(x, _mm_hadd_epi32(x, y))", f529, 0, 128},
  {"128:_mm_srav_epi32(_mm_hadd_epi32(x, y), x)", f530, 0, 128},
  {"128:_mm_srav_epi32(y, _mm_hadd_epi32(x, y))", f531, 0, 128},
  {"128:_mm_srav_epi32(_mm_hsub_epi32(x, y), y)", f532, 0, 128},
  {"128:_mm_srav_epi32(x, _mm_hsub_epi32(x, y))", f533, 0, 128},
  {"128:_mm_srav_epi32(_mm_hsub_epi32(x, y), x)", f534, 0, 128},
  {"128:_mm_srav_epi32(y, _mm_hsub_epi32(x, y))", f535, 0, 128},
  {"128:_mm_srav_epi32(_mm_mul_epi32(x, y), y)", f536, 0, 128},
  {"128:_mm_srav_epi32(x, _mm_mul_epi32(x, y))", f537, 0, 128},
  {"128:_mm_srav_epi32(_mm_mul_epi32(x, y), x)", f538, 0, 128},
  {"128:_mm_srav_epi32(y, _mm_mul_epi32(x, y))", f539, 0, 128},
  {"128:_mm_srav_epi32(_mm_mul_epu32(x, y), y)", f540, 0, 128},
  {"128:_mm_srav_epi32(x, _mm_mul_epu32(x, y))", f541, 0, 128},
  {"128:_mm_srav_epi32(_mm_mul_epu32(x, y), x)", f542, 0, 128},
  {"128:_mm_srav_epi32(y, _mm_mul_epu32(x, y))", f543, 0, 128},
  {"128:_mm_srav_epi32(_mm_unpacklo_epi32(x, y), y)", f544, 0, 128},
  {"128:_mm_srav_epi32(x, _mm_unpacklo_epi32(x, y))", f545, 0, 128},
  {"128:_mm_srav_epi32(_mm_unpacklo_epi32(x, y), x)", f546, 0, 128},
  {"128:_mm_srav_epi32(y, _mm_unpacklo_epi32(x, y))", f547, 0, 128},
  {"128:_mm_srav_epi32(_mm_unpackhi_epi32(x, y), y)", f548, 0, 128},
  {"128:_mm_srav_epi32(x, _mm_unpackhi_epi32(x, y))", f549, 0, 128},
  {"128:_mm_srav_epi32(_mm_unpackhi_epi32(x, y), x)", f550, 0, 128},
  {"128:_mm_srav_epi32(y, _mm_unpackhi_epi32(x, y))", f551, 0, 128},
  {"128:_mm_srav_epi32(_mm_blendv_epi8(x, y, _mm_cmpgt_epi32(x, y)), y)", f552, 0, 128},
  {"128:_mm_srav_epi32(x, _mm_blendv_epi8(x, y, _mm_cmpgt_epi32(x, y)))", f553, 0, 128},
  {"128:_mm_srav_epi32(_mm_blendv_epi8(x, y, _mm_cmpgt_epi32(x, y)), x)", f554, 0, 128},
  {"128:_mm_srav_epi32(y, _mm_blendv_epi8(x, y, _mm_cmpgt_epi32(x, y)))", f555, 0, 128},
  {"128:_mm_srav_epi32(_mm_blendv_epi8(y, x, _mm_cmpgt_epi32(x, y)), y)", f556, 0, 128},
  {"128:_mm_srav_epi32(x, _mm_blendv_epi8(y, x, _mm_cmpgt_epi32(x, y)))", f557, 0, 128},
  {"128:_mm_srav_epi32(_mm_blendv_epi8(y, x, _mm_cmpgt_epi32(x, y)), x)", f558, 0, 128},
  {"128:_mm_srav_epi32(y, _mm_blendv_epi8(y, x, _mm_cmpgt_epi32(x, y)))", f559, 0, 128},
  {"128:_mm_srav_epi32(_mm_or_si128(_mm_and_si128(_mm_cmpgt_epi32(x, y), x), _mm_andnot_si128(_mm_cmpgt_epi32(x, y), y)), y)", f560, 0, 128},
  {"128:_mm_srav_epi32(x, _mm_or_si128(_mm_and_si128(_mm_cmpgt_epi32(x, y), x), _mm_andnot_si128(_mm_cmpgt_epi32(x, y), y)))", f561, 0, 128},
  {"128:_mm_srav_epi32(_mm_or_si128(_mm_and_si128(_mm_cmpgt_epi32(x, y), x), _mm_andnot_si128(_mm_cmpgt_epi32(x, y), y)), x)", f562, 0, 128},
  {"128:_mm_srav_epi32(y, _mm_or_si128(_mm_and_si128(_mm_cmpgt_epi32(x, y), x), _mm_andnot_si128(_mm_cmpgt_epi32(x, y), y)))", f563, 0, 128},
  {"128:_mm_srav_epi32(_mm_blendv_epi8(x, y, _mm_cmpeq_epi32(x, y)), y)", f564, 0, 128},
  {"128:_mm_srav_epi32(x, _mm_blendv_epi8(x, y, _mm_cmpeq_epi32(x, y)))", f565, 0, 128},
  {"128:_mm_srav_epi32(_mm_blendv_epi8(x, y, _mm_cmpeq_epi32(x, y)), x)", f566, 0, 128},
  {"128:_mm_srav_epi32(y, _mm_blendv_epi8(x, y, _mm_cmpeq_epi32(x, y)))", f567, 0, 128},
  {"128:_mm_srav_epi32(_mm_blendv_epi8(y, x, _mm_cmpeq_epi32(x, y)), y)", f568, 0, 128},
  {"128:_mm_srav_epi32(x, _mm_blendv_epi8(y, x, _mm_cmpeq_epi32(x, y)))", f569, 0, 128},
  {"128:_mm_srav_epi32(_mm_blendv_epi8(y, x, _mm_cmpeq_epi32(x, y)), x)", f570, 0, 128},
  {"128:_mm_srav_epi32(y, _mm_blendv_epi8(y, x, _mm_cmpeq_epi32(x, y)))", f571, 0, 128},
  {"128:_mm_srav_epi32(_mm_or_si128(_mm_and_si128(_mm_cmpeq_epi32(x, y), x), _mm_andnot_si128(_mm_cmpeq_epi32(x, y), y)), y)", f572, 0, 128},
  {"128:_mm_srav_epi32(x, _mm_or_si128(_mm_and_si128(_mm_cmpeq_epi32(x, y), x), _mm_andnot_si128(_mm_cmpeq_epi32(x, y), y)))", f573, 0, 128},
  {"128:_mm_srav_epi32(_mm_or_si128(_mm_and_si128(_mm_cmpeq_epi32(x, y), x), _mm_andnot_si128(_mm_cmpeq_epi32(x, y), y)), x)", f574, 0, 128},
  {"128:_mm_srav_epi32(y, _mm_or_si128(_mm_and_si128(_mm_cmpeq_epi32(x, y), x), _mm_andnot_si128(_mm_cmpeq_epi32(x, y), y)))", f575, 0, 128},
  {"128:_mm_srav_epi32(_mm_mullo_epi32(x, y), y)", f576, 0, 128},
  {"128:_mm_srav_epi32(x, _mm_mullo_epi32(x, y))", f577, 0, 128},
  {"128:_mm_srav_epi32(_mm_mullo_epi32(x, y), x)", f578, 0, 128},
  {"128:_mm_srav_epi32(y, _mm_mullo_epi32(x, y))", f579, 0, 128},
  {"128:_mm_srav_epi32(_mm_sllv_epi32(x, y), y)", f580, 0, 128},
  {"128:_mm_srav_epi32(x, _mm_sllv_epi32(x, y))", f581, 0, 128},
  {"128:_mm_srav_epi32(_mm_sllv_epi32(x, y), x)", f582, 0, 128},
  {"128:_mm_srav_epi32(y, _mm_sllv_epi32(x, y))", f583, 0, 128},
  {"128:_mm_srav_epi32(_mm_srlv_epi32(x, y), y)", f584, 0, 128},
  {"128:_mm_srav_epi32(x, _mm_srlv_epi32(x, y))", f585, 0, 128},
  {"128:_mm_srav_epi32(_mm_srlv_epi32(x, y), x)", f586, 0, 128},
  {"128:_mm_srav_epi32(y, _mm_srlv_epi32(x, y))", f587, 0, 128},
  {"128:_mm_srav_epi32(_mm_srav_epi32(x, y), y)", f588, 0, 128},
  {"128:_mm_srav_epi32(x, _mm_srav_epi32(x, y))", f589, 0, 128},
  {"128:_mm_srav_epi32(_mm_srav_epi32(x, y), x)", f590, 0, 128},
  {"128:_mm_srav_epi32(y, _mm_srav_epi32(x, y))", f591, 0, 128},
  {"128:_mm_sqrt_ps(_mm_sqrt_ps(x))", f592, 1, 128},
  {"128:_mm_sqrt_ps(_mm_xor_ps(x, _mm_set1_ps(-0.0f)))", f593, 1, 128},
  {"128:_mm_sqrt_ps(_mm_andnot_ps(_mm_set1_ps(-0.0f), x))", f594, 1, 128},
  {"128:_mm_sqrt_ps(_mm_sub_ps(_mm_setzero_ps(), x))", f595, 1, 128},
  {"128:_mm_sqrt_ps(_mm_mul_ps(x, _mm_set1_ps(-1.0f)))", f596, 1, 128},
  {"128:_mm_sqrt_ps(_mm_floor_ps(x))", f597, 1, 128},
  {"128:_mm_sqrt_ps(_mm_ceil_ps(x))", f598, 1, 128},
  {"128:_mm_sqrt_ps(_mm_round_ps(x, _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC))", f599, 1, 128},
  {"128:_mm_sqrt_ps(_mm_permute_ps(x, 0x1b))", f600, 1, 128},
  {"128:_mm_sqrt_ps(_mm_permute_ps(x, 0x39))", f601, 1, 128},
  {"128:_mm_sqrt_ps(_mm_permute_ps(x, 0x93))", f602, 1, 128},
  {"128:_mm_sqrt_ps(_mm_permute_ps(x, 0x4e))", f603, 1, 128},
  {"128:_mm_sqrt_ps(_mm_cvtepi32_ps(_mm_cvttps_epi32(x)))", f604, 1, 128},
  {"128:_mm_sqrt_ps(_mm_cvtepi32_ps(_mm_cvtps_epi32(x)))", f605, 1, 128},
  {"128:_mm_sqrt_ps(_mm_movehdup_ps(x))", f606, 1, 128},
  {"128:_mm_xor_ps(_mm_sqrt_ps(x), _mm_set1_ps(-0.0f))", f607, 1, 128},
  {"128:_mm_xor_ps(_mm_xor_ps(x, _mm_set1_ps(-0.0f)), _mm_set1_ps(-0.0f))", f608, 1, 128},
  {"128:_mm_xor_ps(_mm_andnot_ps(_mm_set1_ps(-0.0f), x), _mm_set1_ps(-0.0f))", f609, 1, 128},
  {"128:_mm_xor_ps(_mm_sub_ps(_mm_setzero_ps(), x), _mm_set1_ps(-0.0f))", f610, 1, 128},
  {"128:_mm_xor_ps(_mm_mul_ps(x, _mm_set1_ps(-1.0f)), _mm_set1_ps(-0.0f))", f611, 1, 128},
  {"128:_mm_xor_ps(_mm_floor_ps(x), _mm_set1_ps(-0.0f))", f612, 1, 128},
  {"128:_mm_xor_ps(_mm_ceil_ps(x), _mm_set1_ps(-0.0f))", f613, 1, 128},
  {"128:_mm_xor_ps(_mm_round_ps(x, _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC), _mm_set1_ps(-0.0f))", f614, 1, 128},
  {"128:_mm_xor_ps(_mm_permute_ps(x, 0x1b), _mm_set1_ps(-0.0f))", f615, 1, 128},
  {"128:_mm_xor_ps(_mm_permute_ps(x, 0x39), _mm_set1_ps(-0.0f))", f616, 1, 128},
  {"128:_mm_xor_ps(_mm_permute_ps(x, 0x93), _mm_set1_ps(-0.0f))", f617, 1, 128},
  {"128:_mm_xor_ps(_mm_permute_ps(x, 0x4e), _mm_set1_ps(-0.0f))", f618, 1, 128},
  {"128:_mm_xor_ps(_mm_cvtepi32_ps(_mm_cvttps_epi32(x)), _mm_set1_ps(-0.0f))", f619, 1, 128},
  {"128:_mm_xor_ps(_mm_cvtepi32_ps(_mm_cvtps_epi32(x)), _mm_set1_ps(-0.0f))", f620, 1, 128},
  {"128:_mm_xor_ps(_mm_movehdup_ps(x), _mm_set1_ps(-0.0f))", f621, 1, 128},
  {"128:_mm_andnot_ps(_mm_set1_ps(-0.0f), _mm_sqrt_ps(x))", f622, 1, 128},
  {"128:_mm_andnot_ps(_mm_set1_ps(-0.0f), _mm_xor_ps(x, _mm_set1_ps(-0.0f)))", f623, 1, 128},
  {"128:_mm_andnot_ps(_mm_set1_ps(-0.0f), _mm_andnot_ps(_mm_set1_ps(-0.0f), x))", f624, 1, 128},
  {"128:_mm_andnot_ps(_mm_set1_ps(-0.0f), _mm_sub_ps(_mm_setzero_ps(), x))", f625, 1, 128},
  {"128:_mm_andnot_ps(_mm_set1_ps(-0.0f), _mm_mul_ps(x, _mm_set1_ps(-1.0f)))", f626, 1, 128},
  {"128:_mm_andnot_ps(_mm_set1_ps(-0.0f), _mm_floor_ps(x))", f627, 1, 128},
  {"128:_mm_andnot_ps(_mm_set1_ps(-0.0f), _mm_ceil_ps(x))", f628, 1, 128},
  {"128:_mm_andnot_ps(_mm_set1_ps(-0.0f), _mm_round_ps(x, _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC))", f629, 1, 128},
  {"128:_mm_andnot_ps(_mm_set1_ps(-0.0f), _mm_permute_ps(x, 0x1b))", f630, 1, 128},
  {"128:_mm_andnot_ps(_mm_set1_ps(-0.0f), _mm_permute_ps(x, 0x39))", f631, 1, 128},
  {"128:_mm_andnot_ps(_mm_set1_ps(-0.0f), _mm_permute_ps(x, 0x93))", f632, 1, 128},
  {"128:_mm_andnot_ps(_mm_set1_ps(-0.0f), _mm_permute_ps(x, 0x4e))", f633, 1, 128},
  {"128:_mm_andnot_ps(_mm_set1_ps(-0.0f), _mm_cvtepi32_ps(_mm_cvttps_epi32(x)))", f634, 1, 128},
  {"128:_mm_andnot_ps(_mm_set1_ps(-0.0f), _mm_cvtepi32_ps(_mm_cvtps_epi32(x)))", f635, 1, 128},
  {"128:_mm_andnot_ps(_mm_set1_ps(-0.0f), _mm_movehdup_ps(x))", f636, 1, 128},
  {"128:_mm_sub_ps(_mm_setzero_ps(), _mm_sqrt_ps(x))", f637, 1, 128},
  {"128:_mm_sub_ps(_mm_setzero_ps(), _mm_xor_ps(x, _mm_set1_ps(-0.0f)))", f638, 1, 128},
  {"128:_mm_sub_ps(_mm_setzero_ps(), _mm_andnot_ps(_mm_set1_ps(-0.0f), x))", f639, 1, 128},
  {"128:_mm_sub_ps(_mm_setzero_ps(), _mm_sub_ps(_mm_setzero_ps(), x))", f640, 1, 128},
  {"128:_mm_sub_ps(_mm_setzero_ps(), _mm_mul_ps(x, _mm_set1_ps(-1.0f)))", f641, 1, 128},
  {"128:_mm_sub_ps(_mm_setzero_ps(), _mm_floor_ps(x))", f642, 1, 128},
  {"128:_mm_sub_ps(_mm_setzero_ps(), _mm_ceil_ps(x))", f643, 1, 128},
  {"128:_mm_sub_ps(_mm_setzero_ps(), _mm_round_ps(x, _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC))", f644, 1, 128},
  {"128:_mm_sub_ps(_mm_setzero_ps(), _mm_permute_ps(x, 0x1b))", f645, 1, 128},
  {"128:_mm_sub_ps(_mm_setzero_ps(), _mm_permute_ps(x, 0x39))", f646, 1, 128},
  {"128:_mm_sub_ps(_mm_setzero_ps(), _mm_permute_ps(x, 0x93))", f647, 1, 128},
  {"128:_mm_sub_ps(_mm_setzero_ps(), _mm_permute_ps(x, 0x4e))", f648, 1, 128},
  {"128:_mm_sub_ps(_mm_setzero_ps(), _mm_cvtepi32_ps(_mm_cvttps_epi32(x)))", f649, 1, 128},
  {"128:_mm_sub_ps(_mm_setzero_ps(), _mm_cvtepi32_ps(_mm_cvtps_epi32(x)))", f650, 1, 128},
  {"128:_mm_sub_ps(_mm_setzero_ps(), _mm_movehdup_ps(x))", f651, 1, 128},
  {"128:_mm_mul_ps(_mm_sqrt_ps(x), _mm_set1_ps(-1.0f))", f652, 1, 128},
  {"128:_mm_mul_ps(_mm_xor_ps(x, _mm_set1_ps(-0.0f)), _mm_set1_ps(-1.0f))", f653, 1, 128},
  {"128:_mm_mul_ps(_mm_andnot_ps(_mm_set1_ps(-0.0f), x), _mm_set1_ps(-1.0f))", f654, 1, 128},
  {"128:_mm_mul_ps(_mm_sub_ps(_mm_setzero_ps(), x), _mm_set1_ps(-1.0f))", f655, 1, 128},
  {"128:_mm_mul_ps(_mm_mul_ps(x, _mm_set1_ps(-1.0f)), _mm_set1_ps(-1.0f))", f656, 1, 128},
  {"128:_mm_mul_ps(_mm_floor_ps(x), _mm_set1_ps(-1.0f))", f657, 1, 128},
  {"128:_mm_mul_ps(_mm_ceil_ps(x), _mm_set1_ps(-1.0f))", f658, 1, 128},
  {"128:_mm_mul_ps(_mm_round_ps(x, _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC), _mm_set1_ps(-1.0f))", f659, 1, 128},
  {"128:_mm_mul_ps(_mm_permute_ps(x, 0x1b), _mm_set1_ps(-1.0f))", f660, 1, 128},
  {"128:_mm_mul_ps(_mm_permute_ps(x, 0x39), _mm_set1_ps(-1.0f))", f661, 1, 128},
  {"128:_mm_mul_ps(_mm_permute_ps(x, 0x93), _mm_set1_ps(-1.0f))", f662, 1, 128},
  {"128:_mm_mul_ps(_mm_permute_ps(x, 0x4e), _mm_set1_ps(-1.0f))", f663, 1, 128},
  {"128:_mm_mul_ps(_mm_cvtepi32_ps(_mm_cvttps_epi32(x)), _mm_set1_ps(-1.0f))", f664, 1, 128},
  {"128:_mm_mul_ps(_mm_cvtepi32_ps(_mm_cvtps_epi32(x)), _mm_set1_ps(-1.0f))", f665, 1, 128},
  {"128:_mm_mul_ps(_mm_movehdup_ps(x), _mm_set1_ps(-1.0f))", f666, 1, 128},
  {"128:_mm_floor_ps(_mm_sqrt_ps(x))", f667, 1, 128},
  {"128:_mm_floor_ps(_mm_xor_ps(x, _mm_set1_ps(-0.0f)))", f668, 1, 128},
  {"128:_mm_floor_ps(_mm_andnot_ps(_mm_set1_ps(-0.0f), x))", f669, 1, 128},
  {"128:_mm_floor_ps(_mm_sub_ps(_mm_setzero_ps(), x))", f670, 1, 128},
  {"128:_mm_floor_ps(_mm_mul_ps(x, _mm_set1_ps(-1.0f)))", f671, 1, 128},
  {"128:_mm_floor_ps(_mm_floor_ps(x))", f672, 1, 128},
  {"128:_mm_floor_ps(_mm_ceil_ps(x))", f673, 1, 128},
  {"128:_mm_floor_ps(_mm_round_ps(x, _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC))", f674, 1, 128},
  {"128:_mm_floor_ps(_mm_permute_ps(x, 0x1b))", f675, 1, 128},
  {"128:_mm_floor_ps(_mm_permute_ps(x, 0x39))", f676, 1, 128},
  {"128:_mm_floor_ps(_mm_permute_ps(x, 0x93))", f677, 1, 128},
  {"128:_mm_floor_ps(_mm_permute_ps(x, 0x4e))", f678, 1, 128},
  {"128:_mm_floor_ps(_mm_cvtepi32_ps(_mm_cvttps_epi32(x)))", f679, 1, 128},
  {"128:_mm_floor_ps(_mm_cvtepi32_ps(_mm_cvtps_epi32(x)))", f680, 1, 128},
  {"128:_mm_floor_ps(_mm_movehdup_ps(x))", f681, 1, 128},
  {"128:_mm_ceil_ps(_mm_sqrt_ps(x))", f682, 1, 128},
  {"128:_mm_ceil_ps(_mm_xor_ps(x, _mm_set1_ps(-0.0f)))", f683, 1, 128},
  {"128:_mm_ceil_ps(_mm_andnot_ps(_mm_set1_ps(-0.0f), x))", f684, 1, 128},
  {"128:_mm_ceil_ps(_mm_sub_ps(_mm_setzero_ps(), x))", f685, 1, 128},
  {"128:_mm_ceil_ps(_mm_mul_ps(x, _mm_set1_ps(-1.0f)))", f686, 1, 128},
  {"128:_mm_ceil_ps(_mm_floor_ps(x))", f687, 1, 128},
  {"128:_mm_ceil_ps(_mm_ceil_ps(x))", f688, 1, 128},
  {"128:_mm_ceil_ps(_mm_round_ps(x, _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC))", f689, 1, 128},
  {"128:_mm_ceil_ps(_mm_permute_ps(x, 0x1b))", f690, 1, 128},
  {"128:_mm_ceil_ps(_mm_permute_ps(x, 0x39))", f691, 1, 128},
  {"128:_mm_ceil_ps(_mm_permute_ps(x, 0x93))", f692, 1, 128},
  {"128:_mm_ceil_ps(_mm_permute_ps(x, 0x4e))", f693, 1, 128},
  {"128:_mm_ceil_ps(_mm_cvtepi32_ps(_mm_cvttps_epi32(x)))", f694, 1, 128},
  {"128:_mm_ceil_ps(_mm_cvtepi32_ps(_mm_cvtps_epi32(x)))", f695, 1, 128},
  {"128:_mm_ceil_ps(_mm_movehdup_ps(x))", f696, 1, 128},
  {"128:_mm_round_ps(_mm_sqrt_ps(x), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)", f697, 1, 128},
  {"128:_mm_round_ps(_mm_xor_ps(x, _mm_set1_ps(-0.0f)), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)", f698, 1, 128},
  {"128:_mm_round_ps(_mm_andnot_ps(_mm_set1_ps(-0.0f), x), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)", f699, 1, 128},
  {"128:_mm_round_ps(_mm_sub_ps(_mm_setzero_ps(), x), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)", f700, 1, 128},
  {"128:_mm_round_ps(_mm_mul_ps(x, _mm_set1_ps(-1.0f)), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)", f701, 1, 128},
  {"128:_mm_round_ps(_mm_floor_ps(x), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)", f702, 1, 128},
  {"128:_mm_round_ps(_mm_ceil_ps(x), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)", f703, 1, 128},
  {"128:_mm_round_ps(_mm_round_ps(x, _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)", f704, 1, 128},
  {"128:_mm_round_ps(_mm_permute_ps(x, 0x1b), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)", f705, 1, 128},
  {"128:_mm_round_ps(_mm_permute_ps(x, 0x39), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)", f706, 1, 128},
  {"128:_mm_round_ps(_mm_permute_ps(x, 0x93), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)", f707, 1, 128},
  {"128:_mm_round_ps(_mm_permute_ps(x, 0x4e), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)", f708, 1, 128},
  {"128:_mm_round_ps(_mm_cvtepi32_ps(_mm_cvttps_epi32(x)), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)", f709, 1, 128},
  {"128:_mm_round_ps(_mm_cvtepi32_ps(_mm_cvtps_epi32(x)), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)", f710, 1, 128},
  {"128:_mm_round_ps(_mm_movehdup_ps(x), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)", f711, 1, 128},
  {"128:_mm_permute_ps(_mm_sqrt_ps(x), 0x1b)", f712, 1, 128},
  {"128:_mm_permute_ps(_mm_xor_ps(x, _mm_set1_ps(-0.0f)), 0x1b)", f713, 1, 128},
  {"128:_mm_permute_ps(_mm_andnot_ps(_mm_set1_ps(-0.0f), x), 0x1b)", f714, 1, 128},
  {"128:_mm_permute_ps(_mm_sub_ps(_mm_setzero_ps(), x), 0x1b)", f715, 1, 128},
  {"128:_mm_permute_ps(_mm_mul_ps(x, _mm_set1_ps(-1.0f)), 0x1b)", f716, 1, 128},
  {"128:_mm_permute_ps(_mm_floor_ps(x), 0x1b)", f717, 1, 128},
  {"128:_mm_permute_ps(_mm_ceil_ps(x), 0x1b)", f718, 1, 128},
  {"128:_mm_permute_ps(_mm_round_ps(x, _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC), 0x1b)", f719, 1, 128},
  {"128:_mm_permute_ps(_mm_permute_ps(x, 0x1b), 0x1b)", f720, 1, 128},
  {"128:_mm_permute_ps(_mm_permute_ps(x, 0x39), 0x1b)", f721, 1, 128},
  {"128:_mm_permute_ps(_mm_permute_ps(x, 0x93), 0x1b)", f722, 1, 128},
  {"128:_mm_permute_ps(_mm_permute_ps(x, 0x4e), 0x1b)", f723, 1, 128},
  {"128:_mm_permute_ps(_mm_cvtepi32_ps(_mm_cvttps_epi32(x)), 0x1b)", f724, 1, 128},
  {"128:_mm_permute_ps(_mm_cvtepi32_ps(_mm_cvtps_epi32(x)), 0x1b)", f725, 1, 128},
  {"128:_mm_permute_ps(_mm_movehdup_ps(x), 0x1b)", f726, 1, 128},
  {"128:_mm_permute_ps(_mm_sqrt_ps(x), 0x39)", f727, 1, 128},
  {"128:_mm_permute_ps(_mm_xor_ps(x, _mm_set1_ps(-0.0f)), 0x39)", f728, 1, 128},
  {"128:_mm_permute_ps(_mm_andnot_ps(_mm_set1_ps(-0.0f), x), 0x39)", f729, 1, 128},
  {"128:_mm_permute_ps(_mm_sub_ps(_mm_setzero_ps(), x), 0x39)", f730, 1, 128},
  {"128:_mm_permute_ps(_mm_mul_ps(x, _mm_set1_ps(-1.0f)), 0x39)", f731, 1, 128},
  {"128:_mm_permute_ps(_mm_floor_ps(x), 0x39)", f732, 1, 128},
  {"128:_mm_permute_ps(_mm_ceil_ps(x), 0x39)", f733, 1, 128},
  {"128:_mm_permute_ps(_mm_round_ps(x, _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC), 0x39)", f734, 1, 128},
  {"128:_mm_permute_ps(_mm_permute_ps(x, 0x1b), 0x39)", f735, 1, 128},
  {"128:_mm_permute_ps(_mm_permute_ps(x, 0x39), 0x39)", f736, 1, 128},
  {"128:_mm_permute_ps(_mm_permute_ps(x, 0x93), 0x39)", f737, 1, 128},
  {"128:_mm_permute_ps(_mm_permute_ps(x, 0x4e), 0x39)", f738, 1, 128},
  {"128:_mm_permute_ps(_mm_cvtepi32_ps(_mm_cvttps_epi32(x)), 0x39)", f739, 1, 128},
  {"128:_mm_permute_ps(_mm_cvtepi32_ps(_mm_cvtps_epi32(x)), 0x39)", f740, 1, 128},
  {"128:_mm_permute_ps(_mm_movehdup_ps(x), 0x39)", f741, 1, 128},
  {"128:_mm_permute_ps(_mm_sqrt_ps(x), 0x93)", f742, 1, 128},
  {"128:_mm_permute_ps(_mm_xor_ps(x, _mm_set1_ps(-0.0f)), 0x93)", f743, 1, 128},
  {"128:_mm_permute_ps(_mm_andnot_ps(_mm_set1_ps(-0.0f), x), 0x93)", f744, 1, 128},
  {"128:_mm_permute_ps(_mm_sub_ps(_mm_setzero_ps(), x), 0x93)", f745, 1, 128},
  {"128:_mm_permute_ps(_mm_mul_ps(x, _mm_set1_ps(-1.0f)), 0x93)", f746, 1, 128},
  {"128:_mm_permute_ps(_mm_floor_ps(x), 0x93)", f747, 1, 128},
  {"128:_mm_permute_ps(_mm_ceil_ps(x), 0x93)", f748, 1, 128},
  {"128:_mm_permute_ps(_mm_round_ps(x, _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC), 0x93)", f749, 1, 128},
  {"128:_mm_permute_ps(_mm_permute_ps(x, 0x1b), 0x93)", f750, 1, 128},
  {"128:_mm_permute_ps(_mm_permute_ps(x, 0x39), 0x93)", f751, 1, 128},
  {"128:_mm_permute_ps(_mm_permute_ps(x, 0x93), 0x93)", f752, 1, 128},
  {"128:_mm_permute_ps(_mm_permute_ps(x, 0x4e), 0x93)", f753, 1, 128},
  {"128:_mm_permute_ps(_mm_cvtepi32_ps(_mm_cvttps_epi32(x)), 0x93)", f754, 1, 128},
  {"128:_mm_permute_ps(_mm_cvtepi32_ps(_mm_cvtps_epi32(x)), 0x93)", f755, 1, 128},
  {"128:_mm_permute_ps(_mm_movehdup_ps(x), 0x93)", f756, 1, 128},
  {"128:_mm_permute_ps(_mm_sqrt_ps(x), 0x4e)", f757, 1, 128},
  {"128:_mm_permute_ps(_mm_xor_ps(x, _mm_set1_ps(-0.0f)), 0x4e)", f758, 1, 128},
  {"128:_mm_permute_ps(_mm_andnot_ps(_mm_set1_ps(-0.0f), x), 0x4e)", f759, 1, 128},
  {"128:_mm_permute_ps(_mm_sub_ps(_mm_setzero_ps(), x), 0x4e)", f760, 1, 128},
  {"128:_mm_permute_ps(_mm_mul_ps(x, _mm_set1_ps(-1.0f)), 0x4e)", f761, 1, 128},
  {"128:_mm_permute_ps(_mm_floor_ps(x), 0x4e)", f762, 1, 128},
  {"128:_mm_permute_ps(_mm_ceil_ps(x), 0x4e)", f763, 1, 128},
  {"128:_mm_permute_ps(_mm_round_ps(x, _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC), 0x4e)", f764, 1, 128},
  {"128:_mm_permute_ps(_mm_permute_ps(x, 0x1b), 0x4e)", f765, 1, 128},
  {"128:_mm_permute_ps(_mm_permute_ps(x, 0x39), 0x4e)", f766, 1, 128},
  {"128:_mm_permute_ps(_mm_permute_ps(x, 0x93), 0x4e)", f767, 1, 128},
  {"128:_mm_permute_ps(_mm_permute_ps(x, 0x4e), 0x4e)", f768, 1, 128},
  {"128:_mm_permute_ps(_mm_cvtepi32_ps(_mm_cvttps_epi32(x)), 0x4e)", f769, 1, 128},
  {"128:_mm_permute_ps(_mm_cvtepi32_ps(_mm_cvtps_epi32(x)), 0x4e)", f770, 1, 128},
  {"128:_mm_permute_ps(_mm_movehdup_ps(x), 0x4e)", f771, 1, 128},
  {"128:_mm_cvtepi32_ps(_mm_cvttps_epi32(_mm_sqrt_ps(x)))", f772, 1, 128},
  {"128:_mm_cvtepi32_ps(_mm_cvttps_epi32(_mm_xor_ps(x, _mm_set1_ps(-0.0f))))", f773, 1, 128},
  {"128:_mm_cvtepi32_ps(_mm_cvttps_epi32(_mm_andnot_ps(_mm_set1_ps(-0.0f), x)))", f774, 1, 128},
  {"128:_mm_cvtepi32_ps(_mm_cvttps_epi32(_mm_sub_ps(_mm_setzero_ps(), x)))", f775, 1, 128},
  {"128:_mm_cvtepi32_ps(_mm_cvttps_epi32(_mm_mul_ps(x, _mm_set1_ps(-1.0f))))", f776, 1, 128},
  {"128:_mm_cvtepi32_ps(_mm_cvttps_epi32(_mm_floor_ps(x)))", f777, 1, 128},
  {"128:_mm_cvtepi32_ps(_mm_cvttps_epi32(_mm_ceil_ps(x)))", f778, 1, 128},
  {"128:_mm_cvtepi32_ps(_mm_cvttps_epi32(_mm_round_ps(x, _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)))", f779, 1, 128},
  {"128:_mm_cvtepi32_ps(_mm_cvttps_epi32(_mm_permute_ps(x, 0x1b)))", f780, 1, 128},
  {"128:_mm_cvtepi32_ps(_mm_cvttps_epi32(_mm_permute_ps(x, 0x39)))", f781, 1, 128},
  {"128:_mm_cvtepi32_ps(_mm_cvttps_epi32(_mm_permute_ps(x, 0x93)))", f782, 1, 128},
  {"128:_mm_cvtepi32_ps(_mm_cvttps_epi32(_mm_permute_ps(x, 0x4e)))", f783, 1, 128},
  {"128:_mm_cvtepi32_ps(_mm_cvttps_epi32(_mm_cvtepi32_ps(_mm_cvttps_epi32(x))))", f784, 1, 128},
  {"128:_mm_cvtepi32_ps(_mm_cvttps_epi32(_mm_cvtepi32_ps(_mm_cvtps_epi32(x))))", f785, 1, 128},
  {"128:_mm_cvtepi32_ps(_mm_cvttps_epi32(_mm_movehdup_ps(x)))", f786, 1, 128},
  {"128:_mm_cvtepi32_ps(_mm_cvtps_epi32(_mm_sqrt_ps(x)))", f787, 1, 128},
  {"128:_mm_cvtepi32_ps(_mm_cvtps_epi32(_mm_xor_ps(x, _mm_set1_ps(-0.0f))))", f788, 1, 128},
  {"128:_mm_cvtepi32_ps(_mm_cvtps_epi32(_mm_andnot_ps(_mm_set1_ps(-0.0f), x)))", f789, 1, 128},
  {"128:_mm_cvtepi32_ps(_mm_cvtps_epi32(_mm_sub_ps(_mm_setzero_ps(), x)))", f790, 1, 128},
  {"128:_mm_cvtepi32_ps(_mm_cvtps_epi32(_mm_mul_ps(x, _mm_set1_ps(-1.0f))))", f791, 1, 128},
  {"128:_mm_cvtepi32_ps(_mm_cvtps_epi32(_mm_floor_ps(x)))", f792, 1, 128},
  {"128:_mm_cvtepi32_ps(_mm_cvtps_epi32(_mm_ceil_ps(x)))", f793, 1, 128},
  {"128:_mm_cvtepi32_ps(_mm_cvtps_epi32(_mm_round_ps(x, _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)))", f794, 1, 128},
  {"128:_mm_cvtepi32_ps(_mm_cvtps_epi32(_mm_permute_ps(x, 0x1b)))", f795, 1, 128},
  {"128:_mm_cvtepi32_ps(_mm_cvtps_epi32(_mm_permute_ps(x, 0x39)))", f796, 1, 128},
  {"128:_mm_cvtepi32_ps(_mm_cvtps_epi32(_mm_permute_ps(x, 0x93)))", f797, 1, 128},
  {"128:_mm_cvtepi32_ps(_mm_cvtps_epi32(_mm_permute_ps(x, 0x4e)))", f798, 1, 128},
  {"128:_mm_cvtepi32_ps(_mm_cvtps_epi32(_mm_cvtepi32_ps(_mm_cvttps_epi32(x))))", f799, 1, 128},
  {"128:_mm_cvtepi32_ps(_mm_cvtps_epi32(_mm_cvtepi32_ps(_mm_cvtps_epi32(x))))", f800, 1, 128},
  {"128:_mm_cvtepi32_ps(_mm_cvtps_epi32(_mm_movehdup_ps(x)))", f801, 1, 128},
  {"128:_mm_movehdup_ps(_mm_sqrt_ps(x))", f802, 1, 128},
  {"128:_mm_movehdup_ps(_mm_xor_ps(x, _mm_set1_ps(-0.0f)))", f803, 1, 128},
  {"128:_mm_movehdup_ps(_mm_andnot_ps(_mm_set1_ps(-0.0f), x))", f804, 1, 128},
  {"128:_mm_movehdup_ps(_mm_sub_ps(_mm_setzero_ps(), x))", f805, 1, 128},
  {"128:_mm_movehdup_ps(_mm_mul_ps(x, _mm_set1_ps(-1.0f)))", f806, 1, 128},
  {"128:_mm_movehdup_ps(_mm_floor_ps(x))", f807, 1, 128},
  {"128:_mm_movehdup_ps(_mm_ceil_ps(x))", f808, 1, 128},
  {"128:_mm_movehdup_ps(_mm_round_ps(x, _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC))", f809, 1, 128},
  {"128:_mm_movehdup_ps(_mm_permute_ps(x, 0x1b))", f810, 1, 128},
  {"128:_mm_movehdup_ps(_mm_permute_ps(x, 0x39))", f811, 1, 128},
  {"128:_mm_movehdup_ps(_mm_permute_ps(x, 0x93))", f812, 1, 128},
  {"128:_mm_movehdup_ps(_mm_permute_ps(x, 0x4e))", f813, 1, 128},
  {"128:_mm_movehdup_ps(_mm_cvtepi32_ps(_mm_cvttps_epi32(x)))", f814, 1, 128},
  {"128:_mm_movehdup_ps(_mm_cvtepi32_ps(_mm_cvtps_epi32(x)))", f815, 1, 128},
  {"128:_mm_movehdup_ps(_mm_movehdup_ps(x))", f816, 1, 128},
  {"128:_mm_sqrt_ps(_mm_sqrt_ps(_mm_sqrt_ps(x)))", f817, 1, 128},
  {"128:_mm_xor_ps(_mm_xor_ps(_mm_xor_ps(x, _mm_set1_ps(-0.0f)), _mm_set1_ps(-0.0f)), _mm_set1_ps(-0.0f))", f818, 1, 128},
  {"128:_mm_andnot_ps(_mm_set1_ps(-0.0f), _mm_andnot_ps(_mm_set1_ps(-0.0f), _mm_andnot_ps(_mm_set1_ps(-0.0f), x)))", f819, 1, 128},
  {"128:_mm_sub_ps(_mm_setzero_ps(), _mm_sub_ps(_mm_setzero_ps(), _mm_sub_ps(_mm_setzero_ps(), x)))", f820, 1, 128},
  {"128:_mm_mul_ps(_mm_mul_ps(_mm_mul_ps(x, _mm_set1_ps(-1.0f)), _mm_set1_ps(-1.0f)), _mm_set1_ps(-1.0f))", f821, 1, 128},
  {"128:_mm_floor_ps(_mm_floor_ps(_mm_floor_ps(x)))", f822, 1, 128},
  {"128:_mm_ceil_ps(_mm_ceil_ps(_mm_ceil_ps(x)))", f823, 1, 128},
  {"128:_mm_round_ps(_mm_round_ps(_mm_round_ps(x, _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)", f824, 1, 128},
  {"128:_mm_permute_ps(_mm_permute_ps(_mm_permute_ps(x, 0x1b), 0x1b), 0x1b)", f825, 1, 128},
  {"128:_mm_permute_ps(_mm_permute_ps(_mm_permute_ps(x, 0x39), 0x39), 0x39)", f826, 1, 128},
  {"128:_mm_permute_ps(_mm_permute_ps(_mm_permute_ps(x, 0x93), 0x93), 0x93)", f827, 1, 128},
  {"128:_mm_permute_ps(_mm_permute_ps(_mm_permute_ps(x, 0x4e), 0x4e), 0x4e)", f828, 1, 128},
  {"128:_mm_cvtepi32_ps(_mm_cvttps_epi32(_mm_cvtepi32_ps(_mm_cvttps_epi32(_mm_cvtepi32_ps(_mm_cvttps_epi32(x))))))", f829, 1, 128},
  {"128:_mm_cvtepi32_ps(_mm_cvtps_epi32(_mm_cvtepi32_ps(_mm_cvtps_epi32(_mm_cvtepi32_ps(_mm_cvtps_epi32(x))))))", f830, 1, 128},
  {"128:_mm_movehdup_ps(_mm_movehdup_ps(_mm_movehdup_ps(x)))", f831, 1, 128},
  {"128:_mm_sqrt_ps(_mm_add_ps(x, y))", f832, 1, 128},
  {"128:_mm_add_ps(_mm_sqrt_ps(x), y)", f833, 1, 128},
  {"128:_mm_add_ps(x, _mm_sqrt_ps(y))", f834, 1, 128},
  {"128:_mm_add_ps(_mm_sqrt_ps(x), _mm_sqrt_ps(y))", f835, 1, 128},
  {"128:_mm_add_ps(x, _mm_sqrt_ps(x))", f836, 1, 128},
  {"128:_mm_add_ps(_mm_sqrt_ps(x), x)", f837, 1, 128},
  {"128:_mm_sqrt_ps(_mm_sub_ps(x, y))", f838, 1, 128},
  {"128:_mm_sub_ps(_mm_sqrt_ps(x), y)", f839, 1, 128},
  {"128:_mm_sub_ps(x, _mm_sqrt_ps(y))", f840, 1, 128},
  {"128:_mm_sub_ps(_mm_sqrt_ps(x), _mm_sqrt_ps(y))", f841, 1, 128},
  {"128:_mm_sub_ps(x, _mm_sqrt_ps(x))", f842, 1, 128},
  {"128:_mm_sub_ps(_mm_sqrt_ps(x), x)", f843, 1, 128},
  {"128:_mm_sqrt_ps(_mm_mul_ps(x, y))", f844, 1, 128},
  {"128:_mm_mul_ps(_mm_sqrt_ps(x), y)", f845, 1, 128},
  {"128:_mm_mul_ps(x, _mm_sqrt_ps(y))", f846, 1, 128},
  {"128:_mm_mul_ps(_mm_sqrt_ps(x), _mm_sqrt_ps(y))", f847, 1, 128},
  {"128:_mm_mul_ps(x, _mm_sqrt_ps(x))", f848, 1, 128},
  {"128:_mm_mul_ps(_mm_sqrt_ps(x), x)", f849, 1, 128},
  {"128:_mm_sqrt_ps(_mm_div_ps(x, y))", f850, 1, 128},
  {"128:_mm_div_ps(_mm_sqrt_ps(x), y)", f851, 1, 128},
  {"128:_mm_div_ps(x, _mm_sqrt_ps(y))", f852, 1, 128},
  {"128:_mm_div_ps(_mm_sqrt_ps(x), _mm_sqrt_ps(y))", f853, 1, 128},
  {"128:_mm_div_ps(x, _mm_sqrt_ps(x))", f854, 1, 128},
  {"128:_mm_div_ps(_mm_sqrt_ps(x), x)", f855, 1, 128},
  {"128:_mm_sqrt_ps(_mm_min_ps(x, y))", f856, 1, 128},
  {"128:_mm_min_ps(_mm_sqrt_ps(x), y)", f857, 1, 128},
  {"128:_mm_min_ps(x, _mm_sqrt_ps(y))", f858, 1, 128},
  {"128:_mm_min_ps(_mm_sqrt_ps(x), _mm_sqrt_ps(y))", f859, 1, 128},
  {"128:_mm_min_ps(x, _mm_sqrt_ps(x))", f860, 1, 128},
  {"128:_mm_min_ps(_mm_sqrt_ps(x), x)", f861, 1, 128},
  {"128:_mm_sqrt_ps(_mm_max_ps(x, y))", f862, 1, 128},
  {"128:_mm_max_ps(_mm_sqrt_ps(x), y)", f863, 1, 128},
  {"128:_mm_max_ps(x, _mm_sqrt_ps(y))", f864, 1, 128},
  {"128:_mm_max_ps(_mm_sqrt_ps(x), _mm_sqrt_ps(y))", f865, 1, 128},
  {"128:_mm_max_ps(x, _mm_sqrt_ps(x))", f866, 1, 128},
  {"128:_mm_max_ps(_mm_sqrt_ps(x), x)", f867, 1, 128},
  {"128:_mm_sqrt_ps(_mm_and_ps(x, y))", f868, 1, 128},
  {"128:_mm_and_ps(_mm_sqrt_ps(x), y)", f869, 1, 128},
  {"128:_mm_and_ps(x, _mm_sqrt_ps(y))", f870, 1, 128},
  {"128:_mm_and_ps(_mm_sqrt_ps(x), _mm_sqrt_ps(y))", f871, 1, 128},
  {"128:_mm_and_ps(x, _mm_sqrt_ps(x))", f872, 1, 128},
  {"128:_mm_and_ps(_mm_sqrt_ps(x), x)", f873, 1, 128},
  {"128:_mm_sqrt_ps(_mm_or_ps(x, y))", f874, 1, 128},
  {"128:_mm_or_ps(_mm_sqrt_ps(x), y)", f875, 1, 128},
  {"128:_mm_or_ps(x, _mm_sqrt_ps(y))", f876, 1, 128},
  {"128:_mm_or_ps(_mm_sqrt_ps(x), _mm_sqrt_ps(y))", f877, 1, 128},
  {"128:_mm_or_ps(x, _mm_sqrt_ps(x))", f878, 1, 128},
  {"128:_mm_or_ps(_mm_sqrt_ps(x), x)", f879, 1, 128},
  {"128:_mm_sqrt_ps(_mm_xor_ps(x, y))", f880, 1, 128},
  {"128:_mm_xor_ps(_mm_sqrt_ps(x), y)", f881, 1, 128},
  {"128:_mm_xor_ps(x, _mm_sqrt_ps(y))", f882, 1, 128},
  {"128:_mm_xor_ps(_mm_sqrt_ps(x), _mm_sqrt_ps(y))", f883, 1, 128},
  {"128:_mm_xor_ps(x, _mm_sqrt_ps(x))", f884, 1, 128},
  {"128:_mm_xor_ps(_mm_sqrt_ps(x), x)", f885, 1, 128},
  {"128:_mm_sqrt_ps(_mm_andnot_ps(x, y))", f886, 1, 128},
  {"128:_mm_andnot_ps(_mm_sqrt_ps(x), y)", f887, 1, 128},
  {"128:_mm_andnot_ps(x, _mm_sqrt_ps(y))", f888, 1, 128},
  {"128:_mm_andnot_ps(_mm_sqrt_ps(x), _mm_sqrt_ps(y))", f889, 1, 128},
  {"128:_mm_andnot_ps(x, _mm_sqrt_ps(x))", f890, 1, 128},
  {"128:_mm_andnot_ps(_mm_sqrt_ps(x), x)", f891, 1, 128},
  {"128:_mm_sqrt_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ))", f892, 1, 128},
  {"128:_mm_cmp_ps(_mm_sqrt_ps(x), y, _CMP_EQ_OQ)", f893, 1, 128},
  {"128:_mm_cmp_ps(x, _mm_sqrt_ps(y), _CMP_EQ_OQ)", f894, 1, 128},
  {"128:_mm_cmp_ps(_mm_sqrt_ps(x), _mm_sqrt_ps(y), _CMP_EQ_OQ)", f895, 1, 128},
  {"128:_mm_cmp_ps(x, _mm_sqrt_ps(x), _CMP_EQ_OQ)", f896, 1, 128},
  {"128:_mm_cmp_ps(_mm_sqrt_ps(x), x, _CMP_EQ_OQ)", f897, 1, 128},
  {"128:_mm_sqrt_ps(_mm_cmp_ps(x, y, _CMP_LT_OS))", f898, 1, 128},
  {"128:_mm_cmp_ps(_mm_sqrt_ps(x), y, _CMP_LT_OS)", f899, 1, 128},
  {"128:_mm_cmp_ps(x, _mm_sqrt_ps(y), _CMP_LT_OS)", f900, 1, 128},
  {"128:_mm_cmp_ps(_mm_sqrt_ps(x), _mm_sqrt_ps(y), _CMP_LT_OS)", f901, 1, 128},
  {"128:_mm_cmp_ps(x, _mm_sqrt_ps(x), _CMP_LT_OS)", f902, 1, 128},
  {"128:_mm_cmp_ps(_mm_sqrt_ps(x), x, _CMP_LT_OS)", f903, 1, 128},
  {"128:_mm_sqrt_ps(_mm_cmp_ps(x, y, _CMP_LE_OS))", f904, 1, 128},
  {"128:_mm_cmp_ps(_mm_sqrt_ps(x), y, _CMP_LE_OS)", f905, 1, 128},
  {"128:_mm_cmp_ps(x, _mm_sqrt_ps(y), _CMP_LE_OS)", f906, 1, 128},
  {"128:_mm_cmp_ps(_mm_sqrt_ps(x), _mm_sqrt_ps(y), _CMP_LE_OS)", f907, 1, 128},
  {"128:_mm_cmp_ps(x, _mm_sqrt_ps(x), _CMP_LE_OS)", f908, 1, 128},
  {"128:_mm_cmp_ps(_mm_sqrt_ps(x), x, _CMP_LE_OS)", f909, 1, 128},
  {"128:_mm_sqrt_ps(_mm_cmp_ps(x, y, _CMP_NEQ_UQ))", f910, 1, 128},
  {"128:_mm_cmp_ps(_mm_sqrt_ps(x), y, _CMP_NEQ_UQ)", f911, 1, 128},
  {"128:_mm_cmp_ps(x, _mm_sqrt_ps(y), _CMP_NEQ_UQ)", f912, 1, 128},
  {"128:_mm_cmp_ps(_mm_sqrt_ps(x), _mm_sqrt_ps(y), _CMP_NEQ_UQ)", f913, 1, 128},
  {"128:_mm_cmp_ps(x, _mm_sqrt_ps(x), _CMP_NEQ_UQ)", f914, 1, 128},
  {"128:_mm_cmp_ps(_mm_sqrt_ps(x), x, _CMP_NEQ_UQ)", f915, 1, 128},
  {"128:_mm_sqrt_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q))", f916, 1, 128},
  {"128:_mm_cmp_ps(_mm_sqrt_ps(x), y, _CMP_UNORD_Q)", f917, 1, 128},
  {"128:_mm_cmp_ps(x, _mm_sqrt_ps(y), _CMP_UNORD_Q)", f918, 1, 128},
  {"128:_mm_cmp_ps(_mm_sqrt_ps(x), _mm_sqrt_ps(y), _CMP_UNORD_Q)", f919, 1, 128},
  {"128:_mm_cmp_ps(x, _mm_sqrt_ps(x), _CMP_UNORD_Q)", f920, 1, 128},
  {"128:_mm_cmp_ps(_mm_sqrt_ps(x), x, _CMP_UNORD_Q)", f921, 1, 128},
  {"128:_mm_sqrt_ps(_mm_cmp_ps(x, y, _CMP_NLT_US))", f922, 1, 128},
  {"128:_mm_cmp_ps(_mm_sqrt_ps(x), y, _CMP_NLT_US)", f923, 1, 128},
  {"128:_mm_cmp_ps(x, _mm_sqrt_ps(y), _CMP_NLT_US)", f924, 1, 128},
  {"128:_mm_cmp_ps(_mm_sqrt_ps(x), _mm_sqrt_ps(y), _CMP_NLT_US)", f925, 1, 128},
  {"128:_mm_cmp_ps(x, _mm_sqrt_ps(x), _CMP_NLT_US)", f926, 1, 128},
  {"128:_mm_cmp_ps(_mm_sqrt_ps(x), x, _CMP_NLT_US)", f927, 1, 128},
  {"128:_mm_sqrt_ps(_mm_cmp_ps(x, y, _CMP_GT_OS))", f928, 1, 128},
  {"128:_mm_cmp_ps(_mm_sqrt_ps(x), y, _CMP_GT_OS)", f929, 1, 128},
  {"128:_mm_cmp_ps(x, _mm_sqrt_ps(y), _CMP_GT_OS)", f930, 1, 128},
  {"128:_mm_cmp_ps(_mm_sqrt_ps(x), _mm_sqrt_ps(y), _CMP_GT_OS)", f931, 1, 128},
  {"128:_mm_cmp_ps(x, _mm_sqrt_ps(x), _CMP_GT_OS)", f932, 1, 128},
  {"128:_mm_cmp_ps(_mm_sqrt_ps(x), x, _CMP_GT_OS)", f933, 1, 128},
  {"128:_mm_sqrt_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LT_OS)))", f934, 1, 128},
  {"128:_mm_blendv_ps(_mm_sqrt_ps(x), y, _mm_cmp_ps(_mm_sqrt_ps(x), y, _CMP_LT_OS))", f935, 1, 128},
  {"128:_mm_blendv_ps(x, _mm_sqrt_ps(y), _mm_cmp_ps(x, _mm_sqrt_ps(y), _CMP_LT_OS))", f936, 1, 128},
  {"128:_mm_blendv_ps(_mm_sqrt_ps(x), _mm_sqrt_ps(y), _mm_cmp_ps(_mm_sqrt_ps(x), _mm_sqrt_ps(y), _CMP_LT_OS))", f937, 1, 128},
  {"128:_mm_blendv_ps(x, _mm_sqrt_ps(x), _mm_cmp_ps(x, _mm_sqrt_ps(x), _CMP_LT_OS))", f938, 1, 128},
  {"128:_mm_blendv_ps(_mm_sqrt_ps(x), x, _mm_cmp_ps(_mm_sqrt_ps(x), x, _CMP_LT_OS))", f939, 1, 128},
  {"128:_mm_sqrt_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LT_OS)))", f940, 1, 128},
  {"128:_mm_blendv_ps(y, _mm_sqrt_ps(x), _mm_cmp_ps(_mm_sqrt_ps(x), y, _CMP_LT_OS))", f941, 1, 128},
  {"128:_mm_blendv_ps(_mm_sqrt_ps(y), x, _mm_cmp_ps(x, _mm_sqrt_ps(y), _CMP_LT_OS))", f942, 1, 128},
  {"128:_mm_blendv_ps(_mm_sqrt_ps(y), _mm_sqrt_ps(x), _mm_cmp_ps(_mm_sqrt_ps(x), _mm_sqrt_ps(y), _CMP_LT_OS))", f943, 1, 128},
  {"128:_mm_blendv_ps(_mm_sqrt_ps(x), x, _mm_cmp_ps(x, _mm_sqrt_ps(x), _CMP_LT_OS))", f944, 1, 128},
  {"128:_mm_blendv_ps(x, _mm_sqrt_ps(x), _mm_cmp_ps(_mm_sqrt_ps(x), x, _CMP_LT_OS))", f945, 1, 128},
  {"128:_mm_sqrt_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), y)))", f946, 1, 128},
  {"128:_mm_or_ps(_mm_and_ps(_mm_cmp_ps(_mm_sqrt_ps(x), y, _CMP_LT_OS), _mm_sqrt_ps(x)), _mm_andnot_ps(_mm_cmp_ps(_mm_sqrt_ps(x), y, _CMP_LT_OS), y))", f947, 1, 128},
  {"128:_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, _mm_sqrt_ps(y), _CMP_LT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, _mm_sqrt_ps(y), _CMP_LT_OS), _mm_sqrt_ps(y)))", f948, 1, 128},
  {"128:_mm_or_ps(_mm_and_ps(_mm_cmp_ps(_mm_sqrt_ps(x), _mm_sqrt_ps(y), _CMP_LT_OS), _mm_sqrt_ps(x)), _mm_andnot_ps(_mm_cmp_ps(_mm_sqrt_ps(x), _mm_sqrt_ps(y), _CMP_LT_OS), _mm_sqrt_ps(y)))", f949, 1, 128},
  {"128:_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, _mm_sqrt_ps(x), _CMP_LT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, _mm_sqrt_ps(x), _CMP_LT_OS), _mm_sqrt_ps(x)))", f950, 1, 128},
  {"128:_mm_or_ps(_mm_and_ps(_mm_cmp_ps(_mm_sqrt_ps(x), x, _CMP_LT_OS), _mm_sqrt_ps(x)), _mm_andnot_ps(_mm_cmp_ps(_mm_sqrt_ps(x), x, _CMP_LT_OS), x))", f951, 1, 128},
  {"128:_mm_sqrt_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LE_OS)))", f952, 1, 128},
  {"128:_mm_blendv_ps(_mm_sqrt_ps(x), y, _mm_cmp_ps(_mm_sqrt_ps(x), y, _CMP_LE_OS))", f953, 1, 128},
  {"128:_mm_blendv_ps(x, _mm_sqrt_ps(y), _mm_cmp_ps(x, _mm_sqrt_ps(y), _CMP_LE_OS))", f954, 1, 128},
  {"128:_mm_blendv_ps(_mm_sqrt_ps(x), _mm_sqrt_ps(y), _mm_cmp_ps(_mm_sqrt_ps(x), _mm_sqrt_ps(y), _CMP_LE_OS))", f955, 1, 128},
  {"128:_mm_blendv_ps(x, _mm_sqrt_ps(x), _mm_cmp_ps(x, _mm_sqrt_ps(x), _CMP_LE_OS))", f956, 1, 128},
  {"128:_mm_blendv_ps(_mm_sqrt_ps(x), x, _mm_cmp_ps(_mm_sqrt_ps(x), x, _CMP_LE_OS))", f957, 1, 128},
  {"128:_mm_sqrt_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LE_OS)))", f958, 1, 128},
  {"128:_mm_blendv_ps(y, _mm_sqrt_ps(x), _mm_cmp_ps(_mm_sqrt_ps(x), y, _CMP_LE_OS))", f959, 1, 128},
  {"128:_mm_blendv_ps(_mm_sqrt_ps(y), x, _mm_cmp_ps(x, _mm_sqrt_ps(y), _CMP_LE_OS))", f960, 1, 128},
  {"128:_mm_blendv_ps(_mm_sqrt_ps(y), _mm_sqrt_ps(x), _mm_cmp_ps(_mm_sqrt_ps(x), _mm_sqrt_ps(y), _CMP_LE_OS))", f961, 1, 128},
  {"128:_mm_blendv_ps(_mm_sqrt_ps(x), x, _mm_cmp_ps(x, _mm_sqrt_ps(x), _CMP_LE_OS))", f962, 1, 128},
  {"128:_mm_blendv_ps(x, _mm_sqrt_ps(x), _mm_cmp_ps(_mm_sqrt_ps(x), x, _CMP_LE_OS))", f963, 1, 128},
  {"128:_mm_sqrt_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), y)))", f964, 1, 128},
  {"128:_mm_or_ps(_mm_and_ps(_mm_cmp_ps(_mm_sqrt_ps(x), y, _CMP_LE_OS), _mm_sqrt_ps(x)), _mm_andnot_ps(_mm_cmp_ps(_mm_sqrt_ps(x), y, _CMP_LE_OS), y))", f965, 1, 128},
  {"128:_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, _mm_sqrt_ps(y), _CMP_LE_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, _mm_sqrt_ps(y), _CMP_LE_OS), _mm_sqrt_ps(y)))", f966, 1, 128},
  {"128:_mm_or_ps(_mm_and_ps(_mm_cmp_ps(_mm_sqrt_ps(x), _mm_sqrt_ps(y), _CMP_LE_OS), _mm_sqrt_ps(x)), _mm_andnot_ps(_mm_cmp_ps(_mm_sqrt_ps(x), _mm_sqrt_ps(y), _CMP_LE_OS), _mm_sqrt_ps(y)))", f967, 1, 128},
  {"128:_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, _mm_sqrt_ps(x), _CMP_LE_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, _mm_sqrt_ps(x), _CMP_LE_OS), _mm_sqrt_ps(x)))", f968, 1, 128},
  {"128:_mm_or_ps(_mm_and_ps(_mm_cmp_ps(_mm_sqrt_ps(x), x, _CMP_LE_OS), _mm_sqrt_ps(x)), _mm_andnot_ps(_mm_cmp_ps(_mm_sqrt_ps(x), x, _CMP_LE_OS), x))", f969, 1, 128},
  {"128:_mm_sqrt_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_GT_OS)))", f970, 1, 128},
  {"128:_mm_blendv_ps(_mm_sqrt_ps(x), y, _mm_cmp_ps(_mm_sqrt_ps(x), y, _CMP_GT_OS))", f971, 1, 128},
  {"128:_mm_blendv_ps(x, _mm_sqrt_ps(y), _mm_cmp_ps(x, _mm_sqrt_ps(y), _CMP_GT_OS))", f972, 1, 128},
  {"128:_mm_blendv_ps(_mm_sqrt_ps(x), _mm_sqrt_ps(y), _mm_cmp_ps(_mm_sqrt_ps(x), _mm_sqrt_ps(y), _CMP_GT_OS))", f973, 1, 128},
  {"128:_mm_blendv_ps(x, _mm_sqrt_ps(x), _mm_cmp_ps(x, _mm_sqrt_ps(x), _CMP_GT_OS))", f974, 1, 128},
  {"128:_mm_blendv_ps(_mm_sqrt_ps(x), x, _mm_cmp_ps(_mm_sqrt_ps(x), x, _CMP_GT_OS))", f975, 1, 128},
  {"128:_mm_sqrt_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_GT_OS)))", f976, 1, 128},
  {"128:_mm_blendv_ps(y, _mm_sqrt_ps(x), _mm_cmp_ps(_mm_sqrt_ps(x), y, _CMP_GT_OS))", f977, 1, 128},
  {"128:_mm_blendv_ps(_mm_sqrt_ps(y), x, _mm_cmp_ps(x, _mm_sqrt_ps(y), _CMP_GT_OS))", f978, 1, 128},
  {"128:_mm_blendv_ps(_mm_sqrt_ps(y), _mm_sqrt_ps(x), _mm_cmp_ps(_mm_sqrt_ps(x), _mm_sqrt_ps(y), _CMP_GT_OS))", f979, 1, 128},
  {"128:_mm_blendv_ps(_mm_sqrt_ps(x), x, _mm_cmp_ps(x, _mm_sqrt_ps(x), _CMP_GT_OS))", f980, 1, 128},
  {"128:_mm_blendv_ps(x, _mm_sqrt_ps(x), _mm_cmp_ps(_mm_sqrt_ps(x), x, _CMP_GT_OS))", f981, 1, 128},
  {"128:_mm_sqrt_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), y)))", f982, 1, 128},
  {"128:_mm_or_ps(_mm_and_ps(_mm_cmp_ps(_mm_sqrt_ps(x), y, _CMP_GT_OS), _mm_sqrt_ps(x)), _mm_andnot_ps(_mm_cmp_ps(_mm_sqrt_ps(x), y, _CMP_GT_OS), y))", f983, 1, 128},
  {"128:_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, _mm_sqrt_ps(y), _CMP_GT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, _mm_sqrt_ps(y), _CMP_GT_OS), _mm_sqrt_ps(y)))", f984, 1, 128},
  {"128:_mm_or_ps(_mm_and_ps(_mm_cmp_ps(_mm_sqrt_ps(x), _mm_sqrt_ps(y), _CMP_GT_OS), _mm_sqrt_ps(x)), _mm_andnot_ps(_mm_cmp_ps(_mm_sqrt_ps(x), _mm_sqrt_ps(y), _CMP_GT_OS), _mm_sqrt_ps(y)))", f985, 1, 128},
  {"128:_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, _mm_sqrt_ps(x), _CMP_GT_OS), x), _mm_andnot_ps(_mm_cmp_ps(x, _mm_sqrt_ps(x), _CMP_GT_OS), _mm_sqrt_ps(x)))", f986, 1, 128},
  {"128:_mm_or_ps(_mm_and_ps(_mm_cmp_ps(_mm_sqrt_ps(x), x, _CMP_GT_OS), _mm_sqrt_ps(x)), _mm_andnot_ps(_mm_cmp_ps(_mm_sqrt_ps(x), x, _CMP_GT_OS), x))", f987, 1, 128},
  {"128:_mm_sqrt_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_NLT_US)))", f988, 1, 128},
  {"128:_mm_blendv_ps(_mm_sqrt_ps(x), y, _mm_cmp_ps(_mm_sqrt_ps(x), y, _CMP_NLT_US))", f989, 1, 128},
  {"128:_mm_blendv_ps(x, _mm_sqrt_ps(y), _mm_cmp_ps(x, _mm_sqrt_ps(y), _CMP_NLT_US))", f990, 1, 128},
  {"128:_mm_blendv_ps(_mm_sqrt_ps(x), _mm_sqrt_ps(y), _mm_cmp_ps(_mm_sqrt_ps(x), _mm_sqrt_ps(y), _CMP_NLT_US))", f991, 1, 128},
  {"128:_mm_blendv_ps(x, _mm_sqrt_ps(x), _mm_cmp_ps(x, _mm_sqrt_ps(x), _CMP_NLT_US))", f992, 1, 128},
  {"128:_mm_blendv_ps(_mm_sqrt_ps(x), x, _mm_cmp_ps(_mm_sqrt_ps(x), x, _CMP_NLT_US))", f993, 1, 128},
  {"128:_mm_sqrt_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_NLT_US)))", f994, 1, 128},
  {"128:_mm_blendv_ps(y, _mm_sqrt_ps(x), _mm_cmp_ps(_mm_sqrt_ps(x), y, _CMP_NLT_US))", f995, 1, 128},
  {"128:_mm_blendv_ps(_mm_sqrt_ps(y), x, _mm_cmp_ps(x, _mm_sqrt_ps(y), _CMP_NLT_US))", f996, 1, 128},
  {"128:_mm_blendv_ps(_mm_sqrt_ps(y), _mm_sqrt_ps(x), _mm_cmp_ps(_mm_sqrt_ps(x), _mm_sqrt_ps(y), _CMP_NLT_US))", f997, 1, 128},
  {"128:_mm_blendv_ps(_mm_sqrt_ps(x), x, _mm_cmp_ps(x, _mm_sqrt_ps(x), _CMP_NLT_US))", f998, 1, 128},
  {"128:_mm_blendv_ps(x, _mm_sqrt_ps(x), _mm_cmp_ps(_mm_sqrt_ps(x), x, _CMP_NLT_US))", f999, 1, 128},
  {"128:_mm_sqrt_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), y)))", f1000, 1, 128},
  {"128:_mm_or_ps(_mm_and_ps(_mm_cmp_ps(_mm_sqrt_ps(x), y, _CMP_NLT_US), _mm_sqrt_ps(x)), _mm_andnot_ps(_mm_cmp_ps(_mm_sqrt_ps(x), y, _CMP_NLT_US), y))", f1001, 1, 128},
  {"128:_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, _mm_sqrt_ps(y), _CMP_NLT_US), x), _mm_andnot_ps(_mm_cmp_ps(x, _mm_sqrt_ps(y), _CMP_NLT_US), _mm_sqrt_ps(y)))", f1002, 1, 128},
  {"128:_mm_or_ps(_mm_and_ps(_mm_cmp_ps(_mm_sqrt_ps(x), _mm_sqrt_ps(y), _CMP_NLT_US), _mm_sqrt_ps(x)), _mm_andnot_ps(_mm_cmp_ps(_mm_sqrt_ps(x), _mm_sqrt_ps(y), _CMP_NLT_US), _mm_sqrt_ps(y)))", f1003, 1, 128},
  {"128:_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, _mm_sqrt_ps(x), _CMP_NLT_US), x), _mm_andnot_ps(_mm_cmp_ps(x, _mm_sqrt_ps(x), _CMP_NLT_US), _mm_sqrt_ps(x)))", f1004, 1, 128},
  {"128:_mm_or_ps(_mm_and_ps(_mm_cmp_ps(_mm_sqrt_ps(x), x, _CMP_NLT_US), _mm_sqrt_ps(x)), _mm_andnot_ps(_mm_cmp_ps(_mm_sqrt_ps(x), x, _CMP_NLT_US), x))", f1005, 1, 128},
  {"128:_mm_sqrt_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_EQ_OQ)))", f1006, 1, 128},
  {"128:_mm_blendv_ps(_mm_sqrt_ps(x), y, _mm_cmp_ps(_mm_sqrt_ps(x), y, _CMP_EQ_OQ))", f1007, 1, 128},
  {"128:_mm_blendv_ps(x, _mm_sqrt_ps(y), _mm_cmp_ps(x, _mm_sqrt_ps(y), _CMP_EQ_OQ))", f1008, 1, 128},
  {"128:_mm_blendv_ps(_mm_sqrt_ps(x), _mm_sqrt_ps(y), _mm_cmp_ps(_mm_sqrt_ps(x), _mm_sqrt_ps(y), _CMP_EQ_OQ))", f1009, 1, 128},
  {"128:_mm_blendv_ps(x, _mm_sqrt_ps(x), _mm_cmp_ps(x, _mm_sqrt_ps(x), _CMP_EQ_OQ))", f1010, 1, 128},
  {"128:_mm_blendv_ps(_mm_sqrt_ps(x), x, _mm_cmp_ps(_mm_sqrt_ps(x), x, _CMP_EQ_OQ))", f1011, 1, 128},
  {"128:_mm_sqrt_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_EQ_OQ)))", f1012, 1, 128},
  {"128:_mm_blendv_ps(y, _mm_sqrt_ps(x), _mm_cmp_ps(_mm_sqrt_ps(x), y, _CMP_EQ_OQ))", f1013, 1, 128},
  {"128:_mm_blendv_ps(_mm_sqrt_ps(y), x, _mm_cmp_ps(x, _mm_sqrt_ps(y), _CMP_EQ_OQ))", f1014, 1, 128},
  {"128:_mm_blendv_ps(_mm_sqrt_ps(y), _mm_sqrt_ps(x), _mm_cmp_ps(_mm_sqrt_ps(x), _mm_sqrt_ps(y), _CMP_EQ_OQ))", f1015, 1, 128},
  {"128:_mm_blendv_ps(_mm_sqrt_ps(x), x, _mm_cmp_ps(x, _mm_sqrt_ps(x), _CMP_EQ_OQ))", f1016, 1, 128},
  {"128:_mm_blendv_ps(x, _mm_sqrt_ps(x), _mm_cmp_ps(_mm_sqrt_ps(x), x, _CMP_EQ_OQ))", f1017, 1, 128},
  {"128:_mm_sqrt_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), y)))", f1018, 1, 128},
  {"128:_mm_or_ps(_mm_and_ps(_mm_cmp_ps(_mm_sqrt_ps(x), y, _CMP_EQ_OQ), _mm_sqrt_ps(x)), _mm_andnot_ps(_mm_cmp_ps(_mm_sqrt_ps(x), y, _CMP_EQ_OQ), y))", f1019, 1, 128},
  {"128:_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, _mm_sqrt_ps(y), _CMP_EQ_OQ), x), _mm_andnot_ps(_mm_cmp_ps(x, _mm_sqrt_ps(y), _CMP_EQ_OQ), _mm_sqrt_ps(y)))", f1020, 1, 128},
  {"128:_mm_or_ps(_mm_and_ps(_mm_cmp_ps(_mm_sqrt_ps(x), _mm_sqrt_ps(y), _CMP_EQ_OQ), _mm_sqrt_ps(x)), _mm_andnot_ps(_mm_cmp_ps(_mm_sqrt_ps(x), _mm_sqrt_ps(y), _CMP_EQ_OQ), _mm_sqrt_ps(y)))", f1021, 1, 128},
  {"128:_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, _mm_sqrt_ps(x), _CMP_EQ_OQ), x), _mm_andnot_ps(_mm_cmp_ps(x, _mm_sqrt_ps(x), _CMP_EQ_OQ), _mm_sqrt_ps(x)))", f1022, 1, 128},
  {"128:_mm_or_ps(_mm_and_ps(_mm_cmp_ps(_mm_sqrt_ps(x), x, _CMP_EQ_OQ), _mm_sqrt_ps(x)), _mm_andnot_ps(_mm_cmp_ps(_mm_sqrt_ps(x), x, _CMP_EQ_OQ), x))", f1023, 1, 128},
  {"128:_mm_sqrt_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_UNORD_Q)))", f1024, 1, 128},
  {"128:_mm_blendv_ps(_mm_sqrt_ps(x), y, _mm_cmp_ps(_mm_sqrt_ps(x), y, _CMP_UNORD_Q))", f1025, 1, 128},
  {"128:_mm_blendv_ps(x, _mm_sqrt_ps(y), _mm_cmp_ps(x, _mm_sqrt_ps(y), _CMP_UNORD_Q))", f1026, 1, 128},
  {"128:_mm_blendv_ps(_mm_sqrt_ps(x), _mm_sqrt_ps(y), _mm_cmp_ps(_mm_sqrt_ps(x), _mm_sqrt_ps(y), _CMP_UNORD_Q))", f1027, 1, 128},
  {"128:_mm_blendv_ps(x, _mm_sqrt_ps(x), _mm_cmp_ps(x, _mm_sqrt_ps(x), _CMP_UNORD_Q))", f1028, 1, 128},
  {"128:_mm_blendv_ps(_mm_sqrt_ps(x), x, _mm_cmp_ps(_mm_sqrt_ps(x), x, _CMP_UNORD_Q))", f1029, 1, 128},
  {"128:_mm_sqrt_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_UNORD_Q)))", f1030, 1, 128},
  {"128:_mm_blendv_ps(y, _mm_sqrt_ps(x), _mm_cmp_ps(_mm_sqrt_ps(x), y, _CMP_UNORD_Q))", f1031, 1, 128},
  {"128:_mm_blendv_ps(_mm_sqrt_ps(y), x, _mm_cmp_ps(x, _mm_sqrt_ps(y), _CMP_UNORD_Q))", f1032, 1, 128},
  {"128:_mm_blendv_ps(_mm_sqrt_ps(y), _mm_sqrt_ps(x), _mm_cmp_ps(_mm_sqrt_ps(x), _mm_sqrt_ps(y), _CMP_UNORD_Q))", f1033, 1, 128},
  {"128:_mm_blendv_ps(_mm_sqrt_ps(x), x, _mm_cmp_ps(x, _mm_sqrt_ps(x), _CMP_UNORD_Q))", f1034, 1, 128},
  {"128:_mm_blendv_ps(x, _mm_sqrt_ps(x), _mm_cmp_ps(_mm_sqrt_ps(x), x, _CMP_UNORD_Q))", f1035, 1, 128},
  {"128:_mm_sqrt_ps(_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), x), _mm_andnot_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), y)))", f1036, 1, 128},
  {"128:_mm_or_ps(_mm_and_ps(_mm_cmp_ps(_mm_sqrt_ps(x), y, _CMP_UNORD_Q), _mm_sqrt_ps(x)), _mm_andnot_ps(_mm_cmp_ps(_mm_sqrt_ps(x), y, _CMP_UNORD_Q), y))", f1037, 1, 128},
  {"128:_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, _mm_sqrt_ps(y), _CMP_UNORD_Q), x), _mm_andnot_ps(_mm_cmp_ps(x, _mm_sqrt_ps(y), _CMP_UNORD_Q), _mm_sqrt_ps(y)))", f1038, 1, 128},
  {"128:_mm_or_ps(_mm_and_ps(_mm_cmp_ps(_mm_sqrt_ps(x), _mm_sqrt_ps(y), _CMP_UNORD_Q), _mm_sqrt_ps(x)), _mm_andnot_ps(_mm_cmp_ps(_mm_sqrt_ps(x), _mm_sqrt_ps(y), _CMP_UNORD_Q), _mm_sqrt_ps(y)))", f1039, 1, 128},
  {"128:_mm_or_ps(_mm_and_ps(_mm_cmp_ps(x, _mm_sqrt_ps(x), _CMP_UNORD_Q), x), _mm_andnot_ps(_mm_cmp_ps(x, _mm_sqrt_ps(x), _CMP_UNORD_Q), _mm_sqrt_ps(x)))", f1040, 1, 128},
  {"128:_mm_or_ps(_mm_and_ps(_mm_cmp_ps(_mm_sqrt_ps(x), x, _CMP_UNORD_Q), _mm_sqrt_ps(x)), _mm_andnot_ps(_mm_cmp_ps(_mm_sqrt_ps(x), x, _CMP_UNORD_Q), x))", f1041, 1, 128},
  {"128:_mm_sqrt_ps(_mm_unpacklo_ps(x, y))", f1042, 1, 128},
  {"128:_mm_unpacklo_ps(_mm_sqrt_ps(x), y)", f1043, 1, 128},
  {"128:_mm_unpacklo_ps(x, _mm_sqrt_ps(y))", f1044, 1, 128},
  {"128:_mm_unpacklo_ps(_mm_sqrt_ps(x), _mm_sqrt_ps(y))", f1045, 1, 128},
  {"128:_mm_unpacklo_ps(x, _mm_sqrt_ps(x))", f1046, 1, 128},
  {"128:_mm_unpacklo_ps(_mm_sqrt_ps(x), x)", f1047, 1, 128},
  {"128:_mm_sqrt_ps(_mm_unpackhi_ps(x, y))", f1048, 1, 128},
  {"128:_mm_unpackhi_ps(_mm_sqrt_ps(x), y)", f1049, 1, 128},
  {"128:_mm_unpackhi_ps(x, _mm_sqrt_ps(y))", f1050, 1, 128},
  {"128:_mm_unpackhi_ps(_mm_sqrt_ps(x), _mm_sqrt_ps(y))", f1051, 1, 128},
  {"128:_mm_unpackhi_ps(x, _mm_sqrt_ps(x))", f1052, 1, 128},
  {"128:_mm_unpackhi_ps(_mm_sqrt_ps(x), x)", f1053, 1, 128},
  {"128:_mm_sqrt_ps(_mm_hadd_ps(x, y))", f1054, 1, 128},
  {"128:_mm_hadd_ps(_mm_sqrt_ps(x), y)", f1055, 1, 128},
  {"128:_mm_hadd_ps(x, _mm_sqrt_ps(y))", f1056, 1, 128},
  {"128:_mm_hadd_ps(_mm_sqrt_ps(x), _mm_sqrt_ps(y))", f1057, 1, 128},
  {"128:_mm_hadd_ps(x, _mm_sqrt_ps(x))", f1058, 1, 128},
  {"128:_mm_hadd_ps(_mm_sqrt_ps(x), x)", f1059, 1, 128},
  {"128:_mm_sqrt_ps(_mm_hsub_ps(x, y))", f1060, 1, 128},
  {"128:_mm_hsub_ps(_mm_sqrt_ps(x), y)", f1061, 1, 128},
  {"128:_mm_hsub_ps(x, _mm_sqrt_ps(y))", f1062, 1, 128},
  {"128:_mm_hsub_ps(_mm_sqrt_ps(x), _mm_sqrt_ps(y))", f1063, 1, 128},
  {"128:_mm_hsub_ps(x, _mm_sqrt_ps(x))", f1064, 1, 128},
  {"128:_mm_hsub_ps(_mm_sqrt_ps(x), x)", f1065, 1, 128},
  {"128:_mm_sqrt_ps(_mm_shuffle_ps(x, y, 0x1b))", f1066, 1, 128},
  {"128:_mm_shuffle_ps(_mm_sqrt_ps(x), y, 0x1b)", f1067, 1, 128},
  {"128:_mm_shuffle_ps(x, _mm_sqrt_ps(y), 0x1b)", f1068, 1, 128},
  {"128:_mm_shuffle_ps(_mm_sqrt_ps(x), _mm_sqrt_ps(y), 0x1b)", f1069, 1, 128},
  {"128:_mm_shuffle_ps(x, _mm_sqrt_ps(x), 0x1b)", f1070, 1, 128},
  {"128:_mm_shuffle_ps(_mm_sqrt_ps(x), x, 0x1b)", f1071, 1, 128},
  {"128:_mm_sqrt_ps(_mm_shuffle_ps(x, y, 0x39))", f1072, 1, 128},
  {"128:_mm_shuffle_ps(_mm_sqrt_ps(x), y, 0x39)", f1073, 1, 128},
  {"128:_mm_shuffle_ps(x, _mm_sqrt_ps(y), 0x39)", f1074, 1, 128},
  {"128:_mm_shuffle_ps(_mm_sqrt_ps(x), _mm_sqrt_ps(y), 0x39)", f1075, 1, 128},
  {"128:_mm_shuffle_ps(x, _mm_sqrt_ps(x), 0x39)", f1076, 1, 128},
  {"128:_mm_shuffle_ps(_mm_sqrt_ps(x), x, 0x39)", f1077, 1, 128},
  {"128:_mm_sqrt_ps(_mm_shuffle_ps(x, y, 0x93))", f1078, 1, 128},
  {"128:_mm_shuffle_ps(_mm_sqrt_ps(x), y, 0x93)", f1079, 1, 128},
  {"128:_mm_shuffle_ps(x, _mm_sqrt_ps(y), 0x93)", f1080, 1, 128},
  {"128:_mm_shuffle_ps(_mm_sqrt_ps(x), _mm_sqrt_ps(y), 0x93)", f1081, 1, 128},
  {"128:_mm_shuffle_ps(x, _mm_sqrt_ps(x), 0x93)", f1082, 1, 128},
  {"128:_mm_shuffle_ps(_mm_sqrt_ps(x), x, 0x93)", f1083, 1, 128},
  {"128:_mm_sqrt_ps(_mm_shuffle_ps(x, y, 0x4e))", f1084, 1, 128},
  {"128:_mm_shuffle_ps(_mm_sqrt_ps(x), y, 0x4e)", f1085, 1, 128},
  {"128:_mm_shuffle_ps(x, _mm_sqrt_ps(y), 0x4e)", f1086, 1, 128},
  {"128:_mm_shuffle_ps(_mm_sqrt_ps(x), _mm_sqrt_ps(y), 0x4e)", f1087, 1, 128},
  {"128:_mm_shuffle_ps(x, _mm_sqrt_ps(x), 0x4e)", f1088, 1, 128},
  {"128:_mm_shuffle_ps(_mm_sqrt_ps(x), x, 0x4e)", f1089, 1, 128},
  {"128:_mm_xor_ps(_mm_add_ps(x, y), _mm_set1_ps(-0.0f))", f1090, 1, 128},
  {"128:_mm_add_ps(_mm_xor_ps(x, _mm_set1_ps(-0.0f)), y)", f1091, 1, 128},
  {"128:_mm_add_ps(x, _mm_xor_ps(y, _mm_set1_ps(-0.0f)))", f1092, 1, 128},
  {"128:_mm_add_ps(_mm_xor_ps(x, _mm_set1_ps(-0.0f)), _mm_xor_ps(y, _mm_set1_ps(-0.0f)))", f1093, 1, 128},
  {"128:_mm_add_ps(x, _mm_xor_ps(x, _mm_set1_ps(-0.0f)))", f1094, 1, 128},
  {"128:_mm_add_ps(_mm_xor_ps(x, _mm_set1_ps(-0.0f)), x)", f1095, 1, 128},
  {"128:_mm_xor_ps(_mm_sub_ps(x, y), _mm_set1_ps(-0.0f))", f1096, 1, 128},
  {"128:_mm_sub_ps(_mm_xor_ps(x, _mm_set1_ps(-0.0f)), y)", f1097, 1, 128},
  {"128:_mm_sub_ps(x, _mm_xor_ps(y, _mm_set1_ps(-0.0f)))", f1098, 1, 128},
  {"128:_mm_sub_ps(_mm_xor_ps(x, _mm_set1_ps(-0.0f)), _mm_xor_ps(y, _mm_set1_ps(-0.0f)))", f1099, 1, 128},
  {"128:_mm_sub_ps(x, _mm_xor_ps(x, _mm_set1_ps(-0.0f)))", f1100, 1, 128},
  {"128:_mm_sub_ps(_mm_xor_ps(x, _mm_set1_ps(-0.0f)), x)", f1101, 1, 128},
  {"128:_mm_xor_ps(_mm_mul_ps(x, y), _mm_set1_ps(-0.0f))", f1102, 1, 128},
  {"128:_mm_mul_ps(_mm_xor_ps(x, _mm_set1_ps(-0.0f)), y)", f1103, 1, 128},
  {"128:_mm_mul_ps(x, _mm_xor_ps(y, _mm_set1_ps(-0.0f)))", f1104, 1, 128},
  {"128:_mm_mul_ps(_mm_xor_ps(x, _mm_set1_ps(-0.0f)), _mm_xor_ps(y, _mm_set1_ps(-0.0f)))", f1105, 1, 128},
  {"128:_mm_mul_ps(x, _mm_xor_ps(x, _mm_set1_ps(-0.0f)))", f1106, 1, 128},
  {"128:_mm_mul_ps(_mm_xor_ps(x, _mm_set1_ps(-0.0f)), x)", f1107, 1, 128},
  {"128:_mm_xor_ps(_mm_div_ps(x, y), _mm_set1_ps(-0.0f))", f1108, 1, 128},
  {"128:_mm_div_ps(_mm_xor_ps(x, _mm_set1_ps(-0.0f)), y)", f1109, 1, 128},
  {"128:_mm_div_ps(x, _mm_xor_ps(y, _mm_set1_ps(-0.0f)))", f1110, 1, 128},
  {"128:_mm_div_ps(_mm_xor_ps(x, _mm_set1_ps(-0.0f)), _mm_xor_ps(y, _mm_set1_ps(-0.0f)))", f1111, 1, 128},
  {"128:_mm_div_ps(x, _mm_xor_ps(x, _mm_set1_ps(-0.0f)))", f1112, 1, 128},
  {"128:_mm_div_ps(_mm_xor_ps(x, _mm_set1_ps(-0.0f)), x)", f1113, 1, 128},
  {"128:_mm_xor_ps(_mm_min_ps(x, y), _mm_set1_ps(-0.0f))", f1114, 1, 128},
  {"128:_mm_min_ps(_mm_xor_ps(x, _mm_set1_ps(-0.0f)), y)", f1115, 1, 128},
  {"128:_mm_min_ps(x, _mm_xor_ps(y, _mm_set1_ps(-0.0f)))", f1116, 1, 128},
  {"128:_mm_min_ps(_mm_xor_ps(x, _mm_set1_ps(-0.0f)), _mm_xor_ps(y, _mm_set1_ps(-0.0f)))", f1117, 1, 128},
  {"128:_mm_min_ps(x, _mm_xor_ps(x, _mm_set1_ps(-0.0f)))", f1118, 1, 128},
  {"128:_mm_min_ps(_mm_xor_ps(x, _mm_set1_ps(-0.0f)), x)", f1119, 1, 128},
  {"128:_mm_xor_ps(_mm_max_ps(x, y), _mm_set1_ps(-0.0f))", f1120, 1, 128},
  {"128:_mm_max_ps(_mm_xor_ps(x, _mm_set1_ps(-0.0f)), y)", f1121, 1, 128},
  {"128:_mm_max_ps(x, _mm_xor_ps(y, _mm_set1_ps(-0.0f)))", f1122, 1, 128},
  {"128:_mm_max_ps(_mm_xor_ps(x, _mm_set1_ps(-0.0f)), _mm_xor_ps(y, _mm_set1_ps(-0.0f)))", f1123, 1, 128},
  {"128:_mm_max_ps(x, _mm_xor_ps(x, _mm_set1_ps(-0.0f)))", f1124, 1, 128},
  {"128:_mm_max_ps(_mm_xor_ps(x, _mm_set1_ps(-0.0f)), x)", f1125, 1, 128},
  {"128:_mm_xor_ps(_mm_and_ps(x, y), _mm_set1_ps(-0.0f))", f1126, 1, 128},
  {"128:_mm_and_ps(_mm_xor_ps(x, _mm_set1_ps(-0.0f)), y)", f1127, 1, 128},
  {"128:_mm_and_ps(x, _mm_xor_ps(y, _mm_set1_ps(-0.0f)))", f1128, 1, 128},
  {"128:_mm_and_ps(_mm_xor_ps(x, _mm_set1_ps(-0.0f)), _mm_xor_ps(y, _mm_set1_ps(-0.0f)))", f1129, 1, 128},
  {"128:_mm_and_ps(x, _mm_xor_ps(x, _mm_set1_ps(-0.0f)))", f1130, 1, 128},
  {"128:_mm_and_ps(_mm_xor_ps(x, _mm_set1_ps(-0.0f)), x)", f1131, 1, 128},
  {"128:_mm_xor_ps(_mm_or_ps(x, y), _mm_set1_ps(-0.0f))", f1132, 1, 128},
  {"128:_mm_or_ps(_mm_xor_ps(x, _mm_set1_ps(-0.0f)), y)", f1133, 1, 128},
  {"128:_mm_or_ps(x, _mm_xor_ps(y, _mm_set1_ps(-0.0f)))", f1134, 1, 128},
  {"128:_mm_or_ps(_mm_xor_ps(x, _mm_set1_ps(-0.0f)), _mm_xor_ps(y, _mm_set1_ps(-0.0f)))", f1135, 1, 128},
  {"128:_mm_or_ps(x, _mm_xor_ps(x, _mm_set1_ps(-0.0f)))", f1136, 1, 128},
  {"128:_mm_or_ps(_mm_xor_ps(x, _mm_set1_ps(-0.0f)), x)", f1137, 1, 128},
  {"128:_mm_xor_ps(_mm_xor_ps(x, y), _mm_set1_ps(-0.0f))", f1138, 1, 128},
  {"128:_mm_xor_ps(_mm_xor_ps(x, _mm_set1_ps(-0.0f)), y)", f1139, 1, 128},
  {"128:_mm_xor_ps(x, _mm_xor_ps(y, _mm_set1_ps(-0.0f)))", f1140, 1, 128},
  {"128:_mm_xor_ps(_mm_xor_ps(x, _mm_set1_ps(-0.0f)), _mm_xor_ps(y, _mm_set1_ps(-0.0f)))", f1141, 1, 128},
  {"128:_mm_xor_ps(x, _mm_xor_ps(x, _mm_set1_ps(-0.0f)))", f1142, 1, 128},
  {"128:_mm_xor_ps(_mm_xor_ps(x, _mm_set1_ps(-0.0f)), x)", f1143, 1, 128},
  {"128:_mm_xor_ps(_mm_andnot_ps(x, y), _mm_set1_ps(-0.0f))", f1144, 1, 128},
  {"128:_mm_andnot_ps(_mm_xor_ps(x, _mm_set1_ps(-0.0f)), y)", f1145, 1, 128},
  {"128:_mm_andnot_ps(x, _mm_xor_ps(y, _mm_set1_ps(-0.0f)))", f1146, 1, 128},
  {"128:_mm_andnot_ps(_mm_xor_ps(x, _mm_set1_ps(-0.0f)), _mm_xor_ps(y, _mm_set1_ps(-0.0f)))", f1147, 1, 128},
  {"128:_mm_andnot_ps(x, _mm_xor_ps(x, _mm_set1_ps(-0.0f)))", f1148, 1, 128},
  {"128:_mm_andnot_ps(_mm_xor_ps(x, _mm_set1_ps(-0.0f)), x)", f1149, 1, 128},
  {"128:_mm_xor_ps(_mm_cmp_ps(x, y, _CMP_EQ_OQ), _mm_set1_ps(-0.0f))", f1150, 1, 128},
  {"128:_mm_cmp_ps(_mm_xor_ps(x, _mm_set1_ps(-0.0f)), y, _CMP_EQ_OQ)", f1151, 1, 128},
  {"128:_mm_cmp_ps(x, _mm_xor_ps(y, _mm_set1_ps(-0.0f)), _CMP_EQ_OQ)", f1152, 1, 128},
  {"128:_mm_cmp_ps(_mm_xor_ps(x, _mm_set1_ps(-0.0f)), _mm_xor_ps(y, _mm_set1_ps(-0.0f)), _CMP_EQ_OQ)", f1153, 1, 128},
  {"128:_mm_cmp_ps(x, _mm_xor_ps(x, _mm_set1_ps(-0.0f)), _CMP_EQ_OQ)", f1154, 1, 128},
  {"128:_mm_cmp_ps(_mm_xor_ps(x, _mm_set1_ps(-0.0f)), x, _CMP_EQ_OQ)", f1155, 1, 128},
  {"128:_mm_xor_ps(_mm_cmp_ps(x, y, _CMP_LT_OS), _mm_set1_ps(-0.0f))", f1156, 1, 128},
  {"128:_mm_cmp_ps(_mm_xor_ps(x, _mm_set1_ps(-0.0f)), y, _CMP_LT_OS)", f1157, 1, 128},
  {"128:_mm_cmp_ps(x, _mm_xor_ps(y, _mm_set1_ps(-0.0f)), _CMP_LT_OS)", f1158, 1, 128},
  {"128:_mm_cmp_ps(_mm_xor_ps(x, _mm_set1_ps(-0.0f)), _mm_xor_ps(y, _mm_set1_ps(-0.0f)), _CMP_LT_OS)", f1159, 1, 128},
  {"128:_mm_cmp_ps(x, _mm_xor_ps(x, _mm_set1_ps(-0.0f)), _CMP_LT_OS)", f1160, 1, 128},
  {"128:_mm_cmp_ps(_mm_xor_ps(x, _mm_set1_ps(-0.0f)), x, _CMP_LT_OS)", f1161, 1, 128},
  {"128:_mm_xor_ps(_mm_cmp_ps(x, y, _CMP_LE_OS), _mm_set1_ps(-0.0f))", f1162, 1, 128},
  {"128:_mm_cmp_ps(_mm_xor_ps(x, _mm_set1_ps(-0.0f)), y, _CMP_LE_OS)", f1163, 1, 128},
  {"128:_mm_cmp_ps(x, _mm_xor_ps(y, _mm_set1_ps(-0.0f)), _CMP_LE_OS)", f1164, 1, 128},
  {"128:_mm_cmp_ps(_mm_xor_ps(x, _mm_set1_ps(-0.0f)), _mm_xor_ps(y, _mm_set1_ps(-0.0f)), _CMP_LE_OS)", f1165, 1, 128},
  {"128:_mm_cmp_ps(x, _mm_xor_ps(x, _mm_set1_ps(-0.0f)), _CMP_LE_OS)", f1166, 1, 128},
  {"128:_mm_cmp_ps(_mm_xor_ps(x, _mm_set1_ps(-0.0f)), x, _CMP_LE_OS)", f1167, 1, 128},
  {"128:_mm_xor_ps(_mm_cmp_ps(x, y, _CMP_NEQ_UQ), _mm_set1_ps(-0.0f))", f1168, 1, 128},
  {"128:_mm_cmp_ps(_mm_xor_ps(x, _mm_set1_ps(-0.0f)), y, _CMP_NEQ_UQ)", f1169, 1, 128},
  {"128:_mm_cmp_ps(x, _mm_xor_ps(y, _mm_set1_ps(-0.0f)), _CMP_NEQ_UQ)", f1170, 1, 128},
  {"128:_mm_cmp_ps(_mm_xor_ps(x, _mm_set1_ps(-0.0f)), _mm_xor_ps(y, _mm_set1_ps(-0.0f)), _CMP_NEQ_UQ)", f1171, 1, 128},
  {"128:_mm_cmp_ps(x, _mm_xor_ps(x, _mm_set1_ps(-0.0f)), _CMP_NEQ_UQ)", f1172, 1, 128},
  {"128:_mm_cmp_ps(_mm_xor_ps(x, _mm_set1_ps(-0.0f)), x, _CMP_NEQ_UQ)", f1173, 1, 128},
  {"128:_mm_xor_ps(_mm_cmp_ps(x, y, _CMP_UNORD_Q), _mm_set1_ps(-0.0f))", f1174, 1, 128},
  {"128:_mm_cmp_ps(_mm_xor_ps(x, _mm_set1_ps(-0.0f)), y, _CMP_UNORD_Q)", f1175, 1, 128},
  {"128:_mm_cmp_ps(x, _mm_xor_ps(y, _mm_set1_ps(-0.0f)), _CMP_UNORD_Q)", f1176, 1, 128},
  {"128:_mm_cmp_ps(_mm_xor_ps(x, _mm_set1_ps(-0.0f)), _mm_xor_ps(y, _mm_set1_ps(-0.0f)), _CMP_UNORD_Q)", f1177, 1, 128},
  {"128:_mm_cmp_ps(x, _mm_xor_ps(x, _mm_set1_ps(-0.0f)), _CMP_UNORD_Q)", f1178, 1, 128},
  {"128:_mm_cmp_ps(_mm_xor_ps(x, _mm_set1_ps(-0.0f)), x, _CMP_UNORD_Q)", f1179, 1, 128},
  {"128:_mm_xor_ps(_mm_cmp_ps(x, y, _CMP_NLT_US), _mm_set1_ps(-0.0f))", f1180, 1, 128},
  {"128:_mm_cmp_ps(_mm_xor_ps(x, _mm_set1_ps(-0.0f)), y, _CMP_NLT_US)", f1181, 1, 128},
  {"128:_mm_cmp_ps(x, _mm_xor_ps(y, _mm_set1_ps(-0.0f)), _CMP_NLT_US)", f1182, 1, 128},
  {"128:_mm_cmp_ps(_mm_xor_ps(x, _mm_set1_ps(-0.0f)), _mm_xor_ps(y, _mm_set1_ps(-0.0f)), _CMP_NLT_US)", f1183, 1, 128},
  {"128:_mm_cmp_ps(x, _mm_xor_ps(x, _mm_set1_ps(-0.0f)), _CMP_NLT_US)", f1184, 1, 128},
  {"128:_mm_cmp_ps(_mm_xor_ps(x, _mm_set1_ps(-0.0f)), x, _CMP_NLT_US)", f1185, 1, 128},
  {"128:_mm_xor_ps(_mm_cmp_ps(x, y, _CMP_GT_OS), _mm_set1_ps(-0.0f))", f1186, 1, 128},
  {"128:_mm_cmp_ps(_mm_xor_ps(x, _mm_set1_ps(-0.0f)), y, _CMP_GT_OS)", f1187, 1, 128},
  {"128:_mm_cmp_ps(x, _mm_xor_ps(y, _mm_set1_ps(-0.0f)), _CMP_GT_OS)", f1188, 1, 128},
  {"128:_mm_cmp_ps(_mm_xor_ps(x, _mm_set1_ps(-0.0f)), _mm_xor_ps(y, _mm_set1_ps(-0.0f)), _CMP_GT_OS)", f1189, 1, 128},
  {"128:_mm_cmp_ps(x, _mm_xor_ps(x, _mm_set1_ps(-0.0f)), _CMP_GT_OS)", f1190, 1, 128},
  {"128:_mm_cmp_ps(_mm_xor_ps(x, _mm_set1_ps(-0.0f)), x, _CMP_GT_OS)", f1191, 1, 128},
  {"128:_mm_xor_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LT_OS)), _mm_set1_ps(-0.0f))", f1192, 1, 128},
  {"128:_mm_blendv_ps(_mm_xor_ps(x, _mm_set1_ps(-0.0f)), y, _mm_cmp_ps(_mm_xor_ps(x, _mm_set1_ps(-0.0f)), y, _CMP_LT_OS))", f1193, 1, 128},
  {"128:_mm_blendv_ps(x, _mm_xor_ps(y, _mm_set1_ps(-0.0f)), _mm_cmp_ps(x, _mm_xor_ps(y, _mm_set1_ps(-0.0f)), _CMP_LT_OS))", f1194, 1, 128},
  {"128:_mm_blendv_ps(_mm_xor_ps(x, _mm_set1_ps(-0.0f)), _mm_xor_ps(y, _mm_set1_ps(-0.0f)), _mm_cmp_ps(_mm_xor_ps(x, _mm_set1_ps(-0.0f)), _mm_xor_ps(y, _mm_set1_ps(-0.0f)), _CMP_LT_OS))", f1195, 1, 128},
  {"128:_mm_blendv_ps(x, _mm_xor_ps(x, _mm_set1_ps(-0.0f)), _mm_cmp_ps(x, _mm_xor_ps(x, _mm_set1_ps(-0.0f)), _CMP_LT_OS))", f1196, 1, 128},
  {"128:_mm_blendv_ps(_mm_xor_ps(x, _mm_set1_ps(-0.0f)), x, _mm_cmp_ps(_mm_xor_ps(x, _mm_set1_ps(-0.0f)), x, _CMP_LT_OS))", f1197, 1, 128},
  {"128:_mm_xor_ps(_mm_blendv_ps(y, x, _mm_cmp_ps(x, y, _CMP_LT_OS)), _mm_set1_ps(-0.0f))", f1198, 1, 128},
  {"128:_mm_blendv_ps(y, _mm_xor_ps(x, _mm_set1_ps(-0.0f)), _mm_cmp_ps(_mm_xor_ps(x, _mm_set1_ps(-0.0f)), y, _CMP_LT_OS))", f1199, 1, 128},
};
extern const int size_20 = 1200;
