#include "common.h"
static NOINLINE void f0(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srli_epi32(_mm512_srai_epi64(x, 1), 31); _mm512_storeu_si512(po, r); }
static NOINLINE void f1(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srli_epi32(_mm512_slli_epi64(x, 63), 31); _mm512_storeu_si512(po, r); }
static NOINLINE void f2(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srli_epi32(_mm512_srli_epi64(x, 63), 31); _mm512_storeu_si512(po, r); }
static NOINLINE void f3(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srli_epi32(_mm512_srai_epi64(x, 63), 31); _mm512_storeu_si512(po, r); }
static NOINLINE void f4(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srai_epi32(_mm512_abs_epi8(x), 31); _mm512_storeu_si512(po, r); }
static NOINLINE void f5(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srai_epi32(_mm512_abs_epi16(x), 31); _mm512_storeu_si512(po, r); }
static NOINLINE void f6(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srai_epi32(_mm512_abs_epi32(x), 31); _mm512_storeu_si512(po, r); }
static NOINLINE void f7(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srai_epi32(_mm512_abs_epi64(x), 31); _mm512_storeu_si512(po, r); }
static NOINLINE void f8(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srai_epi32(_mm512_sub_epi8(_mm512_setzero_si512(), x), 31); _mm512_storeu_si512(po, r); }
static NOINLINE void f9(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srai_epi32(_mm512_sub_epi16(_mm512_setzero_si512(), x), 31); _mm512_storeu_si512(po, r); }
static NOINLINE void f10(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srai_epi32(_mm512_sub_epi32(_mm512_setzero_si512(), x), 31); _mm512_storeu_si512(po, r); }
static NOINLINE void f11(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srai_epi32(_mm512_sub_epi64(_mm512_setzero_si512(), x), 31); _mm512_storeu_si512(po, r); }
static NOINLINE void f12(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srai_epi32(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), 31); _mm512_storeu_si512(po, r); }
static NOINLINE void f13(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srai_epi32(_mm512_slli_epi16(x, 1), 31); _mm512_storeu_si512(po, r); }
static NOINLINE void f14(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srai_epi32(_mm512_srli_epi16(x, 1), 31); _mm512_storeu_si512(po, r); }
static NOINLINE void f15(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srai_epi32(_mm512_srai_epi16(x, 1), 31); _mm512_storeu_si512(po, r); }
static NOINLINE void f16(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srai_epi32(_mm512_slli_epi16(x, 15), 31); _mm512_storeu_si512(po, r); }
static NOINLINE void f17(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srai_epi32(_mm512_srli_epi16(x, 15), 31); _mm512_storeu_si512(po, r); }
static NOINLINE void f18(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srai_epi32(_mm512_srai_epi16(x, 15), 31); _mm512_storeu_si512(po, r); }
static NOINLINE void f19(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srai_epi32(_mm512_slli_epi32(x, 1), 31); _mm512_storeu_si512(po, r); }
static NOINLINE void f20(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srai_epi32(_mm512_srli_epi32(x, 1), 31); _mm512_storeu_si512(po, r); }
static NOINLINE void f21(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srai_epi32(_mm512_srai_epi32(x, 1), 31); _mm512_storeu_si512(po, r); }
static NOINLINE void f22(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srai_epi32(_mm512_slli_epi32(x, 31), 31); _mm512_storeu_si512(po, r); }
static NOINLINE void f23(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srai_epi32(_mm512_srli_epi32(x, 31), 31); _mm512_storeu_si512(po, r); }
static NOINLINE void f24(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srai_epi32(_mm512_srai_epi32(x, 31), 31); _mm512_storeu_si512(po, r); }
static NOINLINE void f25(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srai_epi32(_mm512_slli_epi64(x, 1), 31); _mm512_storeu_si512(po, r); }
static NOINLINE void f26(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srai_epi32(_mm512_srli_epi64(x, 1), 31); _mm512_storeu_si512(po, r); }
static NOINLINE void f27(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srai_epi32(_mm512_srai_epi64(x, 1), 31); _mm512_storeu_si512(po, r); }
static NOINLINE void f28(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srai_epi32(_mm512_slli_epi64(x, 63), 31); _mm512_storeu_si512(po, r); }
static NOINLINE void f29(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srai_epi32(_mm512_srli_epi64(x, 63), 31); _mm512_storeu_si512(po, r); }
static NOINLINE void f30(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srai_epi32(_mm512_srai_epi64(x, 63), 31); _mm512_storeu_si512(po, r); }
static NOINLINE void f31(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_slli_epi64(_mm512_abs_epi8(x), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f32(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_slli_epi64(_mm512_abs_epi16(x), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f33(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_slli_epi64(_mm512_abs_epi32(x), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f34(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_slli_epi64(_mm512_abs_epi64(x), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f35(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_slli_epi64(_mm512_sub_epi8(_mm512_setzero_si512(), x), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f36(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_slli_epi64(_mm512_sub_epi16(_mm512_setzero_si512(), x), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f37(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_slli_epi64(_mm512_sub_epi32(_mm512_setzero_si512(), x), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f38(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_slli_epi64(_mm512_sub_epi64(_mm512_setzero_si512(), x), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f39(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_slli_epi64(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f40(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_slli_epi64(_mm512_slli_epi16(x, 1), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f41(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_slli_epi64(_mm512_srli_epi16(x, 1), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f42(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_slli_epi64(_mm512_srai_epi16(x, 1), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f43(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_slli_epi64(_mm512_slli_epi16(x, 15), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f44(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_slli_epi64(_mm512_srli_epi16(x, 15), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f45(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_slli_epi64(_mm512_srai_epi16(x, 15), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f46(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_slli_epi64(_mm512_slli_epi32(x, 1), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f47(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_slli_epi64(_mm512_srli_epi32(x, 1), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f48(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_slli_epi64(_mm512_srai_epi32(x, 1), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f49(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_slli_epi64(_mm512_slli_epi32(x, 31), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f50(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_slli_epi64(_mm512_srli_epi32(x, 31), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f51(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_slli_epi64(_mm512_srai_epi32(x, 31), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f52(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_slli_epi64(_mm512_slli_epi64(x, 1), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f53(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_slli_epi64(_mm512_srli_epi64(x, 1), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f54(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_slli_epi64(_mm512_srai_epi64(x, 1), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f55(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_slli_epi64(_mm512_slli_epi64(x, 63), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f56(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_slli_epi64(_mm512_srli_epi64(x, 63), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f57(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_slli_epi64(_mm512_srai_epi64(x, 63), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f58(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srli_epi64(_mm512_abs_epi8(x), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f59(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srli_epi64(_mm512_abs_epi16(x), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f60(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srli_epi64(_mm512_abs_epi32(x), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f61(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srli_epi64(_mm512_abs_epi64(x), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f62(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srli_epi64(_mm512_sub_epi8(_mm512_setzero_si512(), x), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f63(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srli_epi64(_mm512_sub_epi16(_mm512_setzero_si512(), x), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f64(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srli_epi64(_mm512_sub_epi32(_mm512_setzero_si512(), x), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f65(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srli_epi64(_mm512_sub_epi64(_mm512_setzero_si512(), x), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f66(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srli_epi64(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f67(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srli_epi64(_mm512_slli_epi16(x, 1), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f68(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srli_epi64(_mm512_srli_epi16(x, 1), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f69(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srli_epi64(_mm512_srai_epi16(x, 1), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f70(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srli_epi64(_mm512_slli_epi16(x, 15), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f71(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srli_epi64(_mm512_srli_epi16(x, 15), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f72(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srli_epi64(_mm512_srai_epi16(x, 15), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f73(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srli_epi64(_mm512_slli_epi32(x, 1), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f74(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srli_epi64(_mm512_srli_epi32(x, 1), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f75(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srli_epi64(_mm512_srai_epi32(x, 1), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f76(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srli_epi64(_mm512_slli_epi32(x, 31), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f77(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srli_epi64(_mm512_srli_epi32(x, 31), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f78(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srli_epi64(_mm512_srai_epi32(x, 31), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f79(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srli_epi64(_mm512_slli_epi64(x, 1), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f80(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srli_epi64(_mm512_srli_epi64(x, 1), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f81(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srli_epi64(_mm512_srai_epi64(x, 1), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f82(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srli_epi64(_mm512_slli_epi64(x, 63), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f83(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srli_epi64(_mm512_srli_epi64(x, 63), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f84(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srli_epi64(_mm512_srai_epi64(x, 63), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f85(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srai_epi64(_mm512_abs_epi8(x), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f86(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srai_epi64(_mm512_abs_epi16(x), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f87(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srai_epi64(_mm512_abs_epi32(x), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f88(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srai_epi64(_mm512_abs_epi64(x), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f89(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srai_epi64(_mm512_sub_epi8(_mm512_setzero_si512(), x), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f90(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srai_epi64(_mm512_sub_epi16(_mm512_setzero_si512(), x), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f91(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srai_epi64(_mm512_sub_epi32(_mm512_setzero_si512(), x), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f92(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srai_epi64(_mm512_sub_epi64(_mm512_setzero_si512(), x), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f93(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srai_epi64(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f94(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srai_epi64(_mm512_slli_epi16(x, 1), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f95(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srai_epi64(_mm512_srli_epi16(x, 1), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f96(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srai_epi64(_mm512_srai_epi16(x, 1), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f97(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srai_epi64(_mm512_slli_epi16(x, 15), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f98(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srai_epi64(_mm512_srli_epi16(x, 15), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f99(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srai_epi64(_mm512_srai_epi16(x, 15), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f100(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srai_epi64(_mm512_slli_epi32(x, 1), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f101(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srai_epi64(_mm512_srli_epi32(x, 1), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f102(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srai_epi64(_mm512_srai_epi32(x, 1), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f103(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srai_epi64(_mm512_slli_epi32(x, 31), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f104(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srai_epi64(_mm512_srli_epi32(x, 31), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f105(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srai_epi64(_mm512_srai_epi32(x, 31), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f106(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srai_epi64(_mm512_slli_epi64(x, 1), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f107(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srai_epi64(_mm512_srli_epi64(x, 1), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f108(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srai_epi64(_mm512_srai_epi64(x, 1), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f109(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srai_epi64(_mm512_slli_epi64(x, 63), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f110(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srai_epi64(_mm512_srli_epi64(x, 63), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f111(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srai_epi64(_mm512_srai_epi64(x, 63), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f112(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_slli_epi64(_mm512_abs_epi8(x), 63); _mm512_storeu_si512(po, r); }
static NOINLINE void f113(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_slli_epi64(_mm512_abs_epi16(x), 63); _mm512_storeu_si512(po, r); }
static NOINLINE void f114(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_slli_epi64(_mm512_abs_epi32(x), 63); _mm512_storeu_si512(po, r); }
static NOINLINE void f115(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_slli_epi64(_mm512_abs_epi64(x), 63); _mm512_storeu_si512(po, r); }
static NOINLINE void f116(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_slli_epi64(_mm512_sub_epi8(_mm512_setzero_si512(), x), 63); _mm512_storeu_si512(po, r); }
static NOINLINE void f117(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_slli_epi64(_mm512_sub_epi16(_mm512_setzero_si512(), x), 63); _mm512_storeu_si512(po, r); }
static NOINLINE void f118(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_slli_epi64(_mm512_sub_epi32(_mm512_setzero_si512(), x), 63); _mm512_storeu_si512(po, r); }
static NOINLINE void f119(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_slli_epi64(_mm512_sub_epi64(_mm512_setzero_si512(), x), 63); _mm512_storeu_si512(po, r); }
static NOINLINE void f120(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_slli_epi64(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), 63); _mm512_storeu_si512(po, r); }
static NOINLINE void f121(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_slli_epi64(_mm512_slli_epi16(x, 1), 63); _mm512_storeu_si512(po, r); }
static NOINLINE void f122(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_slli_epi64(_mm512_srli_epi16(x, 1), 63); _mm512_storeu_si512(po, r); }
static NOINLINE void f123(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_slli_epi64(_mm512_srai_epi16(x, 1), 63); _mm512_storeu_si512(po, r); }
static NOINLINE void f124(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_slli_epi64(_mm512_slli_epi16(x, 15), 63); _mm512_storeu_si512(po, r); }
static NOINLINE void f125(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_slli_epi64(_mm512_srli_epi16(x, 15), 63); _mm512_storeu_si512(po, r); }
static NOINLINE void f126(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_slli_epi64(_mm512_srai_epi16(x, 15), 63); _mm512_storeu_si512(po, r); }
static NOINLINE void f127(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_slli_epi64(_mm512_slli_epi32(x, 1), 63); _mm512_storeu_si512(po, r); }
static NOINLINE void f128(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_slli_epi64(_mm512_srli_epi32(x, 1), 63); _mm512_storeu_si512(po, r); }
static NOINLINE void f129(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_slli_epi64(_mm512_srai_epi32(x, 1), 63); _mm512_storeu_si512(po, r); }
static NOINLINE void f130(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_slli_epi64(_mm512_slli_epi32(x, 31), 63); _mm512_storeu_si512(po, r); }
static NOINLINE void f131(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_slli_epi64(_mm512_srli_epi32(x, 31), 63); _mm512_storeu_si512(po, r); }
static NOINLINE void f132(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_slli_epi64(_mm512_srai_epi32(x, 31), 63); _mm512_storeu_si512(po, r); }
static NOINLINE void f133(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_slli_epi64(_mm512_slli_epi64(x, 1), 63); _mm512_storeu_si512(po, r); }
static NOINLINE void f134(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_slli_epi64(_mm512_srli_epi64(x, 1), 63); _mm512_storeu_si512(po, r); }
static NOINLINE void f135(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_slli_epi64(_mm512_srai_epi64(x, 1), 63); _mm512_storeu_si512(po, r); }
static NOINLINE void f136(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_slli_epi64(_mm512_slli_epi64(x, 63), 63); _mm512_storeu_si512(po, r); }
static NOINLINE void f137(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_slli_epi64(_mm512_srli_epi64(x, 63), 63); _mm512_storeu_si512(po, r); }
static NOINLINE void f138(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_slli_epi64(_mm512_srai_epi64(x, 63), 63); _mm512_storeu_si512(po, r); }
static NOINLINE void f139(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srli_epi64(_mm512_abs_epi8(x), 63); _mm512_storeu_si512(po, r); }
static NOINLINE void f140(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srli_epi64(_mm512_abs_epi16(x), 63); _mm512_storeu_si512(po, r); }
static NOINLINE void f141(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srli_epi64(_mm512_abs_epi32(x), 63); _mm512_storeu_si512(po, r); }
static NOINLINE void f142(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srli_epi64(_mm512_abs_epi64(x), 63); _mm512_storeu_si512(po, r); }
static NOINLINE void f143(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srli_epi64(_mm512_sub_epi8(_mm512_setzero_si512(), x), 63); _mm512_storeu_si512(po, r); }
static NOINLINE void f144(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srli_epi64(_mm512_sub_epi16(_mm512_setzero_si512(), x), 63); _mm512_storeu_si512(po, r); }
static NOINLINE void f145(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srli_epi64(_mm512_sub_epi32(_mm512_setzero_si512(), x), 63); _mm512_storeu_si512(po, r); }
static NOINLINE void f146(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srli_epi64(_mm512_sub_epi64(_mm512_setzero_si512(), x), 63); _mm512_storeu_si512(po, r); }
static NOINLINE void f147(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srli_epi64(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), 63); _mm512_storeu_si512(po, r); }
static NOINLINE void f148(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srli_epi64(_mm512_slli_epi16(x, 1), 63); _mm512_storeu_si512(po, r); }
static NOINLINE void f149(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srli_epi64(_mm512_srli_epi16(x, 1), 63); _mm512_storeu_si512(po, r); }
static NOINLINE void f150(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srli_epi64(_mm512_srai_epi16(x, 1), 63); _mm512_storeu_si512(po, r); }
static NOINLINE void f151(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srli_epi64(_mm512_slli_epi16(x, 15), 63); _mm512_storeu_si512(po, r); }
static NOINLINE void f152(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srli_epi64(_mm512_srli_epi16(x, 15), 63); _mm512_storeu_si512(po, r); }
static NOINLINE void f153(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srli_epi64(_mm512_srai_epi16(x, 15), 63); _mm512_storeu_si512(po, r); }
static NOINLINE void f154(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srli_epi64(_mm512_slli_epi32(x, 1), 63); _mm512_storeu_si512(po, r); }
static NOINLINE void f155(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srli_epi64(_mm512_srli_epi32(x, 1), 63); _mm512_storeu_si512(po, r); }
static NOINLINE void f156(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srli_epi64(_mm512_srai_epi32(x, 1), 63); _mm512_storeu_si512(po, r); }
static NOINLINE void f157(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srli_epi64(_mm512_slli_epi32(x, 31), 63); _mm512_storeu_si512(po, r); }
static NOINLINE void f158(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srli_epi64(_mm512_srli_epi32(x, 31), 63); _mm512_storeu_si512(po, r); }
static NOINLINE void f159(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srli_epi64(_mm512_srai_epi32(x, 31), 63); _mm512_storeu_si512(po, r); }
static NOINLINE void f160(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srli_epi64(_mm512_slli_epi64(x, 1), 63); _mm512_storeu_si512(po, r); }
static NOINLINE void f161(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srli_epi64(_mm512_srli_epi64(x, 1), 63); _mm512_storeu_si512(po, r); }
static NOINLINE void f162(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srli_epi64(_mm512_srai_epi64(x, 1), 63); _mm512_storeu_si512(po, r); }
static NOINLINE void f163(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srli_epi64(_mm512_slli_epi64(x, 63), 63); _mm512_storeu_si512(po, r); }
static NOINLINE void f164(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srli_epi64(_mm512_srli_epi64(x, 63), 63); _mm512_storeu_si512(po, r); }
static NOINLINE void f165(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srli_epi64(_mm512_srai_epi64(x, 63), 63); _mm512_storeu_si512(po, r); }
static NOINLINE void f166(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srai_epi64(_mm512_abs_epi8(x), 63); _mm512_storeu_si512(po, r); }
static NOINLINE void f167(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srai_epi64(_mm512_abs_epi16(x), 63); _mm512_storeu_si512(po, r); }
static NOINLINE void f168(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srai_epi64(_mm512_abs_epi32(x), 63); _mm512_storeu_si512(po, r); }
static NOINLINE void f169(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srai_epi64(_mm512_abs_epi64(x), 63); _mm512_storeu_si512(po, r); }
static NOINLINE void f170(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srai_epi64(_mm512_sub_epi8(_mm512_setzero_si512(), x), 63); _mm512_storeu_si512(po, r); }
static NOINLINE void f171(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srai_epi64(_mm512_sub_epi16(_mm512_setzero_si512(), x), 63); _mm512_storeu_si512(po, r); }
static NOINLINE void f172(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srai_epi64(_mm512_sub_epi32(_mm512_setzero_si512(), x), 63); _mm512_storeu_si512(po, r); }
static NOINLINE void f173(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srai_epi64(_mm512_sub_epi64(_mm512_setzero_si512(), x), 63); _mm512_storeu_si512(po, r); }
static NOINLINE void f174(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srai_epi64(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), 63); _mm512_storeu_si512(po, r); }
static NOINLINE void f175(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srai_epi64(_mm512_slli_epi16(x, 1), 63); _mm512_storeu_si512(po, r); }
static NOINLINE void f176(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srai_epi64(_mm512_srli_epi16(x, 1), 63); _mm512_storeu_si512(po, r); }
static NOINLINE void f177(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srai_epi64(_mm512_srai_epi16(x, 1), 63); _mm512_storeu_si512(po, r); }
static NOINLINE void f178(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srai_epi64(_mm512_slli_epi16(x, 15), 63); _mm512_storeu_si512(po, r); }
static NOINLINE void f179(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srai_epi64(_mm512_srli_epi16(x, 15), 63); _mm512_storeu_si512(po, r); }
static NOINLINE void f180(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srai_epi64(_mm512_srai_epi16(x, 15), 63); _mm512_storeu_si512(po, r); }
static NOINLINE void f181(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srai_epi64(_mm512_slli_epi32(x, 1), 63); _mm512_storeu_si512(po, r); }
static NOINLINE void f182(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srai_epi64(_mm512_srli_epi32(x, 1), 63); _mm512_storeu_si512(po, r); }
static NOINLINE void f183(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srai_epi64(_mm512_srai_epi32(x, 1), 63); _mm512_storeu_si512(po, r); }
static NOINLINE void f184(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srai_epi64(_mm512_slli_epi32(x, 31), 63); _mm512_storeu_si512(po, r); }
static NOINLINE void f185(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srai_epi64(_mm512_srli_epi32(x, 31), 63); _mm512_storeu_si512(po, r); }
static NOINLINE void f186(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srai_epi64(_mm512_srai_epi32(x, 31), 63); _mm512_storeu_si512(po, r); }
static NOINLINE void f187(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srai_epi64(_mm512_slli_epi64(x, 1), 63); _mm512_storeu_si512(po, r); }
static NOINLINE void f188(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srai_epi64(_mm512_srli_epi64(x, 1), 63); _mm512_storeu_si512(po, r); }
static NOINLINE void f189(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srai_epi64(_mm512_srai_epi64(x, 1), 63); _mm512_storeu_si512(po, r); }
static NOINLINE void f190(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srai_epi64(_mm512_slli_epi64(x, 63), 63); _mm512_storeu_si512(po, r); }
static NOINLINE void f191(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srai_epi64(_mm512_srli_epi64(x, 63), 63); _mm512_storeu_si512(po, r); }
static NOINLINE void f192(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srai_epi64(_mm512_srai_epi64(x, 63), 63); _mm512_storeu_si512(po, r); }
static NOINLINE void f193(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_abs_epi8(_mm512_abs_epi8(_mm512_abs_epi8(x))); _mm512_storeu_si512(po, r); }
static NOINLINE void f194(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_abs_epi16(_mm512_abs_epi16(_mm512_abs_epi16(x))); _mm512_storeu_si512(po, r); }
static NOINLINE void f195(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_abs_epi32(_mm512_abs_epi32(_mm512_abs_epi32(x))); _mm512_storeu_si512(po, r); }
static NOINLINE void f196(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_abs_epi64(_mm512_abs_epi64(_mm512_abs_epi64(x))); _mm512_storeu_si512(po, r); }
static NOINLINE void f197(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi8(_mm512_setzero_si512(), _mm512_sub_epi8(_mm512_setzero_si512(), _mm512_sub_epi8(_mm512_setzero_si512(), x))); _mm512_storeu_si512(po, r); }
static NOINLINE void f198(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi16(_mm512_setzero_si512(), _mm512_sub_epi16(_mm512_setzero_si512(), _mm512_sub_epi16(_mm512_setzero_si512(), x))); _mm512_storeu_si512(po, r); }
static NOINLINE void f199(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi32(_mm512_setzero_si512(), _mm512_sub_epi32(_mm512_setzero_si512(), _mm512_sub_epi32(_mm512_setzero_si512(), x))); _mm512_storeu_si512(po, r); }
static NOINLINE void f200(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi64(_mm512_setzero_si512(), _mm512_sub_epi64(_mm512_setzero_si512(), _mm512_sub_epi64(_mm512_setzero_si512(), x))); _mm512_storeu_si512(po, r); }
static NOINLINE void f201(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_xor_si512(_mm512_xor_si512(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), _mm512_set1_epi8((char)0xffu)), _mm512_set1_epi8((char)0xffu)); _mm512_storeu_si512(po, r); }
static NOINLINE void f202(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_slli_epi16(_mm512_slli_epi16(_mm512_slli_epi16(x, 1), 1), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f203(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srli_epi16(_mm512_srli_epi16(_mm512_srli_epi16(x, 1), 1), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f204(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srai_epi16(_mm512_srai_epi16(_mm512_srai_epi16(x, 1), 1), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f205(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_slli_epi16(_mm512_slli_epi16(_mm512_slli_epi16(x, 15), 15), 15); _mm512_storeu_si512(po, r); }
static NOINLINE void f206(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srli_epi16(_mm512_srli_epi16(_mm512_srli_epi16(x, 15), 15), 15); _mm512_storeu_si512(po, r); }
static NOINLINE void f207(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srai_epi16(_mm512_srai_epi16(_mm512_srai_epi16(x, 15), 15), 15); _mm512_storeu_si512(po, r); }
static NOINLINE void f208(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_slli_epi32(_mm512_slli_epi32(_mm512_slli_epi32(x, 1), 1), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f209(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srli_epi32(_mm512_srli_epi32(_mm512_srli_epi32(x, 1), 1), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f210(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srai_epi32(_mm512_srai_epi32(_mm512_srai_epi32(x, 1), 1), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f211(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_slli_epi32(_mm512_slli_epi32(_mm512_slli_epi32(x, 31), 31), 31); _mm512_storeu_si512(po, r); }
static NOINLINE void f212(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srli_epi32(_mm512_srli_epi32(_mm512_srli_epi32(x, 31), 31), 31); _mm512_storeu_si512(po, r); }
static NOINLINE void f213(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srai_epi32(_mm512_srai_epi32(_mm512_srai_epi32(x, 31), 31), 31); _mm512_storeu_si512(po, r); }
static NOINLINE void f214(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_slli_epi64(_mm512_slli_epi64(_mm512_slli_epi64(x, 1), 1), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f215(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srli_epi64(_mm512_srli_epi64(_mm512_srli_epi64(x, 1), 1), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f216(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srai_epi64(_mm512_srai_epi64(_mm512_srai_epi64(x, 1), 1), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f217(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_slli_epi64(_mm512_slli_epi64(_mm512_slli_epi64(x, 63), 63), 63); _mm512_storeu_si512(po, r); }
static NOINLINE void f218(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srli_epi64(_mm512_srli_epi64(_mm512_srli_epi64(x, 63), 63), 63); _mm512_storeu_si512(po, r); }
static NOINLINE void f219(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srai_epi64(_mm512_srai_epi64(_mm512_srai_epi64(x, 63), 63), 63); _mm512_storeu_si512(po, r); }
static NOINLINE void f220(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_abs_epi8(_mm512_add_epi8(x, y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f221(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_add_epi8(_mm512_abs_epi8(x), y); _mm512_storeu_si512(po, r); }
static NOINLINE void f222(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_add_epi8(x, _mm512_abs_epi8(y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f223(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_add_epi8(_mm512_abs_epi8(x), _mm512_abs_epi8(y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f224(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_add_epi8(x, _mm512_abs_epi8(x)); _mm512_storeu_si512(po, r); }
static NOINLINE void f225(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_add_epi8(_mm512_abs_epi8(x), x); _mm512_storeu_si512(po, r); }
static NOINLINE void f226(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_abs_epi8(_mm512_sub_epi8(x, y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f227(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi8(_mm512_abs_epi8(x), y); _mm512_storeu_si512(po, r); }
static NOINLINE void f228(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi8(x, _mm512_abs_epi8(y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f229(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi8(_mm512_abs_epi8(x), _mm512_abs_epi8(y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f230(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi8(x, _mm512_abs_epi8(x)); _mm512_storeu_si512(po, r); }
static NOINLINE void f231(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi8(_mm512_abs_epi8(x), x); _mm512_storeu_si512(po, r); }
static NOINLINE void f232(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_abs_epi8(_mm512_adds_epi8(x, y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f233(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_adds_epi8(_mm512_abs_epi8(x), y); _mm512_storeu_si512(po, r); }
static NOINLINE void f234(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_adds_epi8(x, _mm512_abs_epi8(y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f235(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_adds_epi8(_mm512_abs_epi8(x), _mm512_abs_epi8(y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f236(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_adds_epi8(x, _mm512_abs_epi8(x)); _mm512_storeu_si512(po, r); }
static NOINLINE void f237(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_adds_epi8(_mm512_abs_epi8(x), x); _mm512_storeu_si512(po, r); }
static NOINLINE void f238(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_abs_epi8(_mm512_subs_epi8(x, y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f239(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_subs_epi8(_mm512_abs_epi8(x), y); _mm512_storeu_si512(po, r); }
static NOINLINE void f240(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_subs_epi8(x, _mm512_abs_epi8(y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f241(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_subs_epi8(_mm512_abs_epi8(x), _mm512_abs_epi8(y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f242(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_subs_epi8(x, _mm512_abs_epi8(x)); _mm512_storeu_si512(po, r); }
static NOINLINE void f243(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_subs_epi8(_mm512_abs_epi8(x), x); _mm512_storeu_si512(po, r); }
static NOINLINE void f244(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_abs_epi8(_mm512_adds_epu8(x, y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f245(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_adds_epu8(_mm512_abs_epi8(x), y); _mm512_storeu_si512(po, r); }
static NOINLINE void f246(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_adds_epu8(x, _mm512_abs_epi8(y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f247(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_adds_epu8(_mm512_abs_epi8(x), _mm512_abs_epi8(y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f248(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_adds_epu8(x, _mm512_abs_epi8(x)); _mm512_storeu_si512(po, r); }
static NOINLINE void f249(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_adds_epu8(_mm512_abs_epi8(x), x); _mm512_storeu_si512(po, r); }
static NOINLINE void f250(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_abs_epi8(_mm512_subs_epu8(x, y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f251(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_subs_epu8(_mm512_abs_epi8(x), y); _mm512_storeu_si512(po, r); }
static NOINLINE void f252(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_subs_epu8(x, _mm512_abs_epi8(y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f253(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_subs_epu8(_mm512_abs_epi8(x), _mm512_abs_epi8(y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f254(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_subs_epu8(x, _mm512_abs_epi8(x)); _mm512_storeu_si512(po, r); }
static NOINLINE void f255(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_subs_epu8(_mm512_abs_epi8(x), x); _mm512_storeu_si512(po, r); }
static NOINLINE void f256(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_abs_epi8(_mm512_avg_epu8(x, y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f257(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_avg_epu8(_mm512_abs_epi8(x), y); _mm512_storeu_si512(po, r); }
static NOINLINE void f258(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_avg_epu8(x, _mm512_abs_epi8(y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f259(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_avg_epu8(_mm512_abs_epi8(x), _mm512_abs_epi8(y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f260(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_avg_epu8(x, _mm512_abs_epi8(x)); _mm512_storeu_si512(po, r); }
static NOINLINE void f261(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_avg_epu8(_mm512_abs_epi8(x), x); _mm512_storeu_si512(po, r); }
static NOINLINE void f262(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_abs_epi8(_mm512_min_epi8(x, y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f263(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_min_epi8(_mm512_abs_epi8(x), y); _mm512_storeu_si512(po, r); }
static NOINLINE void f264(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_min_epi8(x, _mm512_abs_epi8(y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f265(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_min_epi8(_mm512_abs_epi8(x), _mm512_abs_epi8(y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f266(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_min_epi8(x, _mm512_abs_epi8(x)); _mm512_storeu_si512(po, r); }
static NOINLINE void f267(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_min_epi8(_mm512_abs_epi8(x), x); _mm512_storeu_si512(po, r); }
static NOINLINE void f268(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_abs_epi8(_mm512_max_epi8(x, y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f269(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_max_epi8(_mm512_abs_epi8(x), y); _mm512_storeu_si512(po, r); }
static NOINLINE void f270(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_max_epi8(x, _mm512_abs_epi8(y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f271(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_max_epi8(_mm512_abs_epi8(x), _mm512_abs_epi8(y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f272(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_max_epi8(x, _mm512_abs_epi8(x)); _mm512_storeu_si512(po, r); }
static NOINLINE void f273(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_max_epi8(_mm512_abs_epi8(x), x); _mm512_storeu_si512(po, r); }
static NOINLINE void f274(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_abs_epi8(_mm512_min_epu8(x, y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f275(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_min_epu8(_mm512_abs_epi8(x), y); _mm512_storeu_si512(po, r); }
static NOINLINE void f276(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_min_epu8(x, _mm512_abs_epi8(y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f277(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_min_epu8(_mm512_abs_epi8(x), _mm512_abs_epi8(y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f278(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_min_epu8(x, _mm512_abs_epi8(x)); _mm512_storeu_si512(po, r); }
static NOINLINE void f279(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_min_epu8(_mm512_abs_epi8(x), x); _mm512_storeu_si512(po, r); }
static NOINLINE void f280(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_abs_epi8(_mm512_max_epu8(x, y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f281(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_max_epu8(_mm512_abs_epi8(x), y); _mm512_storeu_si512(po, r); }
static NOINLINE void f282(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_max_epu8(x, _mm512_abs_epi8(y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f283(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_max_epu8(_mm512_abs_epi8(x), _mm512_abs_epi8(y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f284(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_max_epu8(x, _mm512_abs_epi8(x)); _mm512_storeu_si512(po, r); }
static NOINLINE void f285(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_max_epu8(_mm512_abs_epi8(x), x); _mm512_storeu_si512(po, r); }
static NOINLINE void f286(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_abs_epi8(_mm512_and_si512(x, y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f287(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_and_si512(_mm512_abs_epi8(x), y); _mm512_storeu_si512(po, r); }
static NOINLINE void f288(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_and_si512(x, _mm512_abs_epi8(y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f289(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_and_si512(_mm512_abs_epi8(x), _mm512_abs_epi8(y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f290(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_and_si512(x, _mm512_abs_epi8(x)); _mm512_storeu_si512(po, r); }
static NOINLINE void f291(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_and_si512(_mm512_abs_epi8(x), x); _mm512_storeu_si512(po, r); }
static NOINLINE void f292(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_abs_epi8(_mm512_or_si512(x, y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f293(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_or_si512(_mm512_abs_epi8(x), y); _mm512_storeu_si512(po, r); }
static NOINLINE void f294(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_or_si512(x, _mm512_abs_epi8(y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f295(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_or_si512(_mm512_abs_epi8(x), _mm512_abs_epi8(y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f296(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_or_si512(x, _mm512_abs_epi8(x)); _mm512_storeu_si512(po, r); }
static NOINLINE void f297(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_or_si512(_mm512_abs_epi8(x), x); _mm512_storeu_si512(po, r); }
static NOINLINE void f298(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_abs_epi8(_mm512_xor_si512(x, y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f299(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_xor_si512(_mm512_abs_epi8(x), y); _mm512_storeu_si512(po, r); }
static NOINLINE void f300(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_xor_si512(x, _mm512_abs_epi8(y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f301(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_xor_si512(_mm512_abs_epi8(x), _mm512_abs_epi8(y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f302(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_xor_si512(x, _mm512_abs_epi8(x)); _mm512_storeu_si512(po, r); }
static NOINLINE void f303(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_xor_si512(_mm512_abs_epi8(x), x); _mm512_storeu_si512(po, r); }
static NOINLINE void f304(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_abs_epi8(_mm512_andnot_si512(x, y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f305(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_andnot_si512(_mm512_abs_epi8(x), y); _mm512_storeu_si512(po, r); }
static NOINLINE void f306(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_andnot_si512(x, _mm512_abs_epi8(y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f307(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_andnot_si512(_mm512_abs_epi8(x), _mm512_abs_epi8(y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f308(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_andnot_si512(x, _mm512_abs_epi8(x)); _mm512_storeu_si512(po, r); }
static NOINLINE void f309(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_andnot_si512(_mm512_abs_epi8(x), x); _mm512_storeu_si512(po, r); }
static NOINLINE void f310(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_abs_epi16(_mm512_add_epi16(x, y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f311(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_add_epi16(_mm512_abs_epi16(x), y); _mm512_storeu_si512(po, r); }
static NOINLINE void f312(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_add_epi16(x, _mm512_abs_epi16(y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f313(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_add_epi16(_mm512_abs_epi16(x), _mm512_abs_epi16(y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f314(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_add_epi16(x, _mm512_abs_epi16(x)); _mm512_storeu_si512(po, r); }
static NOINLINE void f315(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_add_epi16(_mm512_abs_epi16(x), x); _mm512_storeu_si512(po, r); }
static NOINLINE void f316(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_abs_epi16(_mm512_sub_epi16(x, y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f317(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi16(_mm512_abs_epi16(x), y); _mm512_storeu_si512(po, r); }
static NOINLINE void f318(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi16(x, _mm512_abs_epi16(y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f319(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi16(_mm512_abs_epi16(x), _mm512_abs_epi16(y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f320(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi16(x, _mm512_abs_epi16(x)); _mm512_storeu_si512(po, r); }
static NOINLINE void f321(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi16(_mm512_abs_epi16(x), x); _mm512_storeu_si512(po, r); }
static NOINLINE void f322(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_abs_epi16(_mm512_adds_epi16(x, y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f323(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_adds_epi16(_mm512_abs_epi16(x), y); _mm512_storeu_si512(po, r); }
static NOINLINE void f324(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_adds_epi16(x, _mm512_abs_epi16(y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f325(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_adds_epi16(_mm512_abs_epi16(x), _mm512_abs_epi16(y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f326(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_adds_epi16(x, _mm512_abs_epi16(x)); _mm512_storeu_si512(po, r); }
static NOINLINE void f327(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_adds_epi16(_mm512_abs_epi16(x), x); _mm512_storeu_si512(po, r); }
static NOINLINE void f328(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_abs_epi16(_mm512_subs_epi16(x, y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f329(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_subs_epi16(_mm512_abs_epi16(x), y); _mm512_storeu_si512(po, r); }
static NOINLINE void f330(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_subs_epi16(x, _mm512_abs_epi16(y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f331(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_subs_epi16(_mm512_abs_epi16(x), _mm512_abs_epi16(y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f332(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_subs_epi16(x, _mm512_abs_epi16(x)); _mm512_storeu_si512(po, r); }
static NOINLINE void f333(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_subs_epi16(_mm512_abs_epi16(x), x); _mm512_storeu_si512(po, r); }
static NOINLINE void f334(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_abs_epi16(_mm512_adds_epu16(x, y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f335(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_adds_epu16(_mm512_abs_epi16(x), y); _mm512_storeu_si512(po, r); }
static NOINLINE void f336(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_adds_epu16(x, _mm512_abs_epi16(y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f337(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_adds_epu16(_mm512_abs_epi16(x), _mm512_abs_epi16(y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f338(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_adds_epu16(x, _mm512_abs_epi16(x)); _mm512_storeu_si512(po, r); }
static NOINLINE void f339(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_adds_epu16(_mm512_abs_epi16(x), x); _mm512_storeu_si512(po, r); }
static NOINLINE void f340(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_abs_epi16(_mm512_subs_epu16(x, y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f341(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_subs_epu16(_mm512_abs_epi16(x), y); _mm512_storeu_si512(po, r); }
static NOINLINE void f342(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_subs_epu16(x, _mm512_abs_epi16(y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f343(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_subs_epu16(_mm512_abs_epi16(x), _mm512_abs_epi16(y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f344(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_subs_epu16(x, _mm512_abs_epi16(x)); _mm512_storeu_si512(po, r); }
static NOINLINE void f345(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_subs_epu16(_mm512_abs_epi16(x), x); _mm512_storeu_si512(po, r); }
static NOINLINE void f346(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_abs_epi16(_mm512_avg_epu16(x, y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f347(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_avg_epu16(_mm512_abs_epi16(x), y); _mm512_storeu_si512(po, r); }
static NOINLINE void f348(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_avg_epu16(x, _mm512_abs_epi16(y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f349(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_avg_epu16(_mm512_abs_epi16(x), _mm512_abs_epi16(y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f350(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_avg_epu16(x, _mm512_abs_epi16(x)); _mm512_storeu_si512(po, r); }
static NOINLINE void f351(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_avg_epu16(_mm512_abs_epi16(x), x); _mm512_storeu_si512(po, r); }
static NOINLINE void f352(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_abs_epi16(_mm512_min_epi16(x, y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f353(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_min_epi16(_mm512_abs_epi16(x), y); _mm512_storeu_si512(po, r); }
static NOINLINE void f354(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_min_epi16(x, _mm512_abs_epi16(y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f355(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_min_epi16(_mm512_abs_epi16(x), _mm512_abs_epi16(y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f356(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_min_epi16(x, _mm512_abs_epi16(x)); _mm512_storeu_si512(po, r); }
static NOINLINE void f357(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_min_epi16(_mm512_abs_epi16(x), x); _mm512_storeu_si512(po, r); }
static NOINLINE void f358(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_abs_epi16(_mm512_max_epi16(x, y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f359(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_max_epi16(_mm512_abs_epi16(x), y); _mm512_storeu_si512(po, r); }
static NOINLINE void f360(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_max_epi16(x, _mm512_abs_epi16(y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f361(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_max_epi16(_mm512_abs_epi16(x), _mm512_abs_epi16(y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f362(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_max_epi16(x, _mm512_abs_epi16(x)); _mm512_storeu_si512(po, r); }
static NOINLINE void f363(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_max_epi16(_mm512_abs_epi16(x), x); _mm512_storeu_si512(po, r); }
static NOINLINE void f364(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_abs_epi16(_mm512_min_epu16(x, y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f365(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_min_epu16(_mm512_abs_epi16(x), y); _mm512_storeu_si512(po, r); }
static NOINLINE void f366(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_min_epu16(x, _mm512_abs_epi16(y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f367(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_min_epu16(_mm512_abs_epi16(x), _mm512_abs_epi16(y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f368(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_min_epu16(x, _mm512_abs_epi16(x)); _mm512_storeu_si512(po, r); }
static NOINLINE void f369(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_min_epu16(_mm512_abs_epi16(x), x); _mm512_storeu_si512(po, r); }
static NOINLINE void f370(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_abs_epi16(_mm512_max_epu16(x, y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f371(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_max_epu16(_mm512_abs_epi16(x), y); _mm512_storeu_si512(po, r); }
static NOINLINE void f372(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_max_epu16(x, _mm512_abs_epi16(y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f373(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_max_epu16(_mm512_abs_epi16(x), _mm512_abs_epi16(y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f374(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_max_epu16(x, _mm512_abs_epi16(x)); _mm512_storeu_si512(po, r); }
static NOINLINE void f375(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_max_epu16(_mm512_abs_epi16(x), x); _mm512_storeu_si512(po, r); }
static NOINLINE void f376(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_abs_epi16(_mm512_and_si512(x, y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f377(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_and_si512(_mm512_abs_epi16(x), y); _mm512_storeu_si512(po, r); }
static NOINLINE void f378(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_and_si512(x, _mm512_abs_epi16(y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f379(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_and_si512(_mm512_abs_epi16(x), _mm512_abs_epi16(y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f380(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_and_si512(x, _mm512_abs_epi16(x)); _mm512_storeu_si512(po, r); }
static NOINLINE void f381(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_and_si512(_mm512_abs_epi16(x), x); _mm512_storeu_si512(po, r); }
static NOINLINE void f382(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_abs_epi16(_mm512_or_si512(x, y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f383(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_or_si512(_mm512_abs_epi16(x), y); _mm512_storeu_si512(po, r); }
static NOINLINE void f384(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_or_si512(x, _mm512_abs_epi16(y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f385(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_or_si512(_mm512_abs_epi16(x), _mm512_abs_epi16(y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f386(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_or_si512(x, _mm512_abs_epi16(x)); _mm512_storeu_si512(po, r); }
static NOINLINE void f387(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_or_si512(_mm512_abs_epi16(x), x); _mm512_storeu_si512(po, r); }
static NOINLINE void f388(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_abs_epi16(_mm512_xor_si512(x, y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f389(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_xor_si512(_mm512_abs_epi16(x), y); _mm512_storeu_si512(po, r); }
static NOINLINE void f390(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_xor_si512(x, _mm512_abs_epi16(y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f391(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_xor_si512(_mm512_abs_epi16(x), _mm512_abs_epi16(y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f392(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_xor_si512(x, _mm512_abs_epi16(x)); _mm512_storeu_si512(po, r); }
static NOINLINE void f393(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_xor_si512(_mm512_abs_epi16(x), x); _mm512_storeu_si512(po, r); }
static NOINLINE void f394(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_abs_epi16(_mm512_andnot_si512(x, y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f395(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_andnot_si512(_mm512_abs_epi16(x), y); _mm512_storeu_si512(po, r); }
static NOINLINE void f396(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_andnot_si512(x, _mm512_abs_epi16(y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f397(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_andnot_si512(_mm512_abs_epi16(x), _mm512_abs_epi16(y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f398(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_andnot_si512(x, _mm512_abs_epi16(x)); _mm512_storeu_si512(po, r); }
static NOINLINE void f399(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_andnot_si512(_mm512_abs_epi16(x), x); _mm512_storeu_si512(po, r); }
static NOINLINE void f400(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_abs_epi16(_mm512_mullo_epi16(x, y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f401(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_mullo_epi16(_mm512_abs_epi16(x), y); _mm512_storeu_si512(po, r); }
static NOINLINE void f402(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_mullo_epi16(x, _mm512_abs_epi16(y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f403(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_mullo_epi16(_mm512_abs_epi16(x), _mm512_abs_epi16(y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f404(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_mullo_epi16(x, _mm512_abs_epi16(x)); _mm512_storeu_si512(po, r); }
static NOINLINE void f405(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_mullo_epi16(_mm512_abs_epi16(x), x); _mm512_storeu_si512(po, r); }
static NOINLINE void f406(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_abs_epi16(_mm512_mulhi_epi16(x, y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f407(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_mulhi_epi16(_mm512_abs_epi16(x), y); _mm512_storeu_si512(po, r); }
static NOINLINE void f408(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_mulhi_epi16(x, _mm512_abs_epi16(y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f409(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_mulhi_epi16(_mm512_abs_epi16(x), _mm512_abs_epi16(y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f410(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_mulhi_epi16(x, _mm512_abs_epi16(x)); _mm512_storeu_si512(po, r); }
static NOINLINE void f411(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_mulhi_epi16(_mm512_abs_epi16(x), x); _mm512_storeu_si512(po, r); }
static NOINLINE void f412(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_abs_epi16(_mm512_mulhi_epu16(x, y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f413(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_mulhi_epu16(_mm512_abs_epi16(x), y); _mm512_storeu_si512(po, r); }
static NOINLINE void f414(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_mulhi_epu16(x, _mm512_abs_epi16(y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f415(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_mulhi_epu16(_mm512_abs_epi16(x), _mm512_abs_epi16(y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f416(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_mulhi_epu16(x, _mm512_abs_epi16(x)); _mm512_storeu_si512(po, r); }
static NOINLINE void f417(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_mulhi_epu16(_mm512_abs_epi16(x), x); _mm512_storeu_si512(po, r); }
static NOINLINE void f418(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_abs_epi32(_mm512_add_epi32(x, y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f419(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_add_epi32(_mm512_abs_epi32(x), y); _mm512_storeu_si512(po, r); }
static NOINLINE void f420(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_add_epi32(x, _mm512_abs_epi32(y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f421(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_add_epi32(_mm512_abs_epi32(x), _mm512_abs_epi32(y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f422(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_add_epi32(x, _mm512_abs_epi32(x)); _mm512_storeu_si512(po, r); }
static NOINLINE void f423(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_add_epi32(_mm512_abs_epi32(x), x); _mm512_storeu_si512(po, r); }
static NOINLINE void f424(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_abs_epi32(_mm512_sub_epi32(x, y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f425(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi32(_mm512_abs_epi32(x), y); _mm512_storeu_si512(po, r); }
static NOINLINE void f426(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi32(x, _mm512_abs_epi32(y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f427(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi32(_mm512_abs_epi32(x), _mm512_abs_epi32(y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f428(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi32(x, _mm512_abs_epi32(x)); _mm512_storeu_si512(po, r); }
static NOINLINE void f429(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi32(_mm512_abs_epi32(x), x); _mm512_storeu_si512(po, r); }
static NOINLINE void f430(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_abs_epi32(_mm512_min_epi32(x, y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f431(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_min_epi32(_mm512_abs_epi32(x), y); _mm512_storeu_si512(po, r); }
static NOINLINE void f432(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_min_epi32(x, _mm512_abs_epi32(y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f433(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_min_epi32(_mm512_abs_epi32(x), _mm512_abs_epi32(y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f434(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_min_epi32(x, _mm512_abs_epi32(x)); _mm512_storeu_si512(po, r); }
static NOINLINE void f435(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_min_epi32(_mm512_abs_epi32(x), x); _mm512_storeu_si512(po, r); }
static NOINLINE void f436(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_abs_epi32(_mm512_max_epi32(x, y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f437(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_max_epi32(_mm512_abs_epi32(x), y); _mm512_storeu_si512(po, r); }
static NOINLINE void f438(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_max_epi32(x, _mm512_abs_epi32(y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f439(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_max_epi32(_mm512_abs_epi32(x), _mm512_abs_epi32(y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f440(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_max_epi32(x, _mm512_abs_epi32(x)); _mm512_storeu_si512(po, r); }
static NOINLINE void f441(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_max_epi32(_mm512_abs_epi32(x), x); _mm512_storeu_si512(po, r); }
static NOINLINE void f442(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_abs_epi32(_mm512_min_epu32(x, y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f443(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_min_epu32(_mm512_abs_epi32(x), y); _mm512_storeu_si512(po, r); }
static NOINLINE void f444(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_min_epu32(x, _mm512_abs_epi32(y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f445(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_min_epu32(_mm512_abs_epi32(x), _mm512_abs_epi32(y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f446(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_min_epu32(x, _mm512_abs_epi32(x)); _mm512_storeu_si512(po, r); }
static NOINLINE void f447(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_min_epu32(_mm512_abs_epi32(x), x); _mm512_storeu_si512(po, r); }
static NOINLINE void f448(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_abs_epi32(_mm512_max_epu32(x, y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f449(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_max_epu32(_mm512_abs_epi32(x), y); _mm512_storeu_si512(po, r); }
static NOINLINE void f450(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_max_epu32(x, _mm512_abs_epi32(y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f451(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_max_epu32(_mm512_abs_epi32(x), _mm512_abs_epi32(y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f452(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_max_epu32(x, _mm512_abs_epi32(x)); _mm512_storeu_si512(po, r); }
static NOINLINE void f453(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_max_epu32(_mm512_abs_epi32(x), x); _mm512_storeu_si512(po, r); }
static NOINLINE void f454(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_abs_epi32(_mm512_and_si512(x, y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f455(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_and_si512(_mm512_abs_epi32(x), y); _mm512_storeu_si512(po, r); }
static NOINLINE void f456(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_and_si512(x, _mm512_abs_epi32(y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f457(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_and_si512(_mm512_abs_epi32(x), _mm512_abs_epi32(y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f458(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_and_si512(x, _mm512_abs_epi32(x)); _mm512_storeu_si512(po, r); }
static NOINLINE void f459(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_and_si512(_mm512_abs_epi32(x), x); _mm512_storeu_si512(po, r); }
static NOINLINE void f460(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_abs_epi32(_mm512_or_si512(x, y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f461(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_or_si512(_mm512_abs_epi32(x), y); _mm512_storeu_si512(po, r); }
static NOINLINE void f462(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_or_si512(x, _mm512_abs_epi32(y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f463(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_or_si512(_mm512_abs_epi32(x), _mm512_abs_epi32(y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f464(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_or_si512(x, _mm512_abs_epi32(x)); _mm512_storeu_si512(po, r); }
static NOINLINE void f465(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_or_si512(_mm512_abs_epi32(x), x); _mm512_storeu_si512(po, r); }
static NOINLINE void f466(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_abs_epi32(_mm512_xor_si512(x, y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f467(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_xor_si512(_mm512_abs_epi32(x), y); _mm512_storeu_si512(po, r); }
static NOINLINE void f468(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_xor_si512(x, _mm512_abs_epi32(y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f469(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_xor_si512(_mm512_abs_epi32(x), _mm512_abs_epi32(y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f470(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_xor_si512(x, _mm512_abs_epi32(x)); _mm512_storeu_si512(po, r); }
static NOINLINE void f471(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_xor_si512(_mm512_abs_epi32(x), x); _mm512_storeu_si512(po, r); }
static NOINLINE void f472(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_abs_epi32(_mm512_andnot_si512(x, y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f473(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_andnot_si512(_mm512_abs_epi32(x), y); _mm512_storeu_si512(po, r); }
static NOINLINE void f474(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_andnot_si512(x, _mm512_abs_epi32(y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f475(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_andnot_si512(_mm512_abs_epi32(x), _mm512_abs_epi32(y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f476(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_andnot_si512(x, _mm512_abs_epi32(x)); _mm512_storeu_si512(po, r); }
static NOINLINE void f477(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_andnot_si512(_mm512_abs_epi32(x), x); _mm512_storeu_si512(po, r); }
static NOINLINE void f478(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_abs_epi32(_mm512_mullo_epi32(x, y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f479(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_mullo_epi32(_mm512_abs_epi32(x), y); _mm512_storeu_si512(po, r); }
static NOINLINE void f480(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_mullo_epi32(x, _mm512_abs_epi32(y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f481(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_mullo_epi32(_mm512_abs_epi32(x), _mm512_abs_epi32(y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f482(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_mullo_epi32(x, _mm512_abs_epi32(x)); _mm512_storeu_si512(po, r); }
static NOINLINE void f483(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_mullo_epi32(_mm512_abs_epi32(x), x); _mm512_storeu_si512(po, r); }
static NOINLINE void f484(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_abs_epi32(_mm512_sllv_epi32(x, y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f485(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sllv_epi32(_mm512_abs_epi32(x), y); _mm512_storeu_si512(po, r); }
static NOINLINE void f486(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sllv_epi32(x, _mm512_abs_epi32(y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f487(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sllv_epi32(_mm512_abs_epi32(x), _mm512_abs_epi32(y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f488(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sllv_epi32(x, _mm512_abs_epi32(x)); _mm512_storeu_si512(po, r); }
static NOINLINE void f489(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sllv_epi32(_mm512_abs_epi32(x), x); _mm512_storeu_si512(po, r); }
static NOINLINE void f490(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_abs_epi32(_mm512_srlv_epi32(x, y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f491(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srlv_epi32(_mm512_abs_epi32(x), y); _mm512_storeu_si512(po, r); }
static NOINLINE void f492(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srlv_epi32(x, _mm512_abs_epi32(y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f493(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srlv_epi32(_mm512_abs_epi32(x), _mm512_abs_epi32(y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f494(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srlv_epi32(x, _mm512_abs_epi32(x)); _mm512_storeu_si512(po, r); }
static NOINLINE void f495(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srlv_epi32(_mm512_abs_epi32(x), x); _mm512_storeu_si512(po, r); }
static NOINLINE void f496(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_abs_epi32(_mm512_srav_epi32(x, y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f497(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srav_epi32(_mm512_abs_epi32(x), y); _mm512_storeu_si512(po, r); }
static NOINLINE void f498(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srav_epi32(x, _mm512_abs_epi32(y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f499(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srav_epi32(_mm512_abs_epi32(x), _mm512_abs_epi32(y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f500(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srav_epi32(x, _mm512_abs_epi32(x)); _mm512_storeu_si512(po, r); }
static NOINLINE void f501(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srav_epi32(_mm512_abs_epi32(x), x); _mm512_storeu_si512(po, r); }
static NOINLINE void f502(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_abs_epi64(_mm512_add_epi64(x, y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f503(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_add_epi64(_mm512_abs_epi64(x), y); _mm512_storeu_si512(po, r); }
static NOINLINE void f504(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_add_epi64(x, _mm512_abs_epi64(y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f505(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_add_epi64(_mm512_abs_epi64(x), _mm512_abs_epi64(y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f506(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_add_epi64(x, _mm512_abs_epi64(x)); _mm512_storeu_si512(po, r); }
static NOINLINE void f507(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_add_epi64(_mm512_abs_epi64(x), x); _mm512_storeu_si512(po, r); }
static NOINLINE void f508(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_abs_epi64(_mm512_sub_epi64(x, y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f509(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi64(_mm512_abs_epi64(x), y); _mm512_storeu_si512(po, r); }
static NOINLINE void f510(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi64(x, _mm512_abs_epi64(y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f511(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi64(_mm512_abs_epi64(x), _mm512_abs_epi64(y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f512(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi64(x, _mm512_abs_epi64(x)); _mm512_storeu_si512(po, r); }
static NOINLINE void f513(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi64(_mm512_abs_epi64(x), x); _mm512_storeu_si512(po, r); }
static NOINLINE void f514(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_abs_epi64(_mm512_min_epi64(x, y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f515(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_min_epi64(_mm512_abs_epi64(x), y); _mm512_storeu_si512(po, r); }
static NOINLINE void f516(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_min_epi64(x, _mm512_abs_epi64(y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f517(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_min_epi64(_mm512_abs_epi64(x), _mm512_abs_epi64(y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f518(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_min_epi64(x, _mm512_abs_epi64(x)); _mm512_storeu_si512(po, r); }
static NOINLINE void f519(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_min_epi64(_mm512_abs_epi64(x), x); _mm512_storeu_si512(po, r); }
static NOINLINE void f520(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_abs_epi64(_mm512_max_epi64(x, y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f521(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_max_epi64(_mm512_abs_epi64(x), y); _mm512_storeu_si512(po, r); }
static NOINLINE void f522(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_max_epi64(x, _mm512_abs_epi64(y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f523(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_max_epi64(_mm512_abs_epi64(x), _mm512_abs_epi64(y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f524(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_max_epi64(x, _mm512_abs_epi64(x)); _mm512_storeu_si512(po, r); }
static NOINLINE void f525(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_max_epi64(_mm512_abs_epi64(x), x); _mm512_storeu_si512(po, r); }
static NOINLINE void f526(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_abs_epi64(_mm512_min_epu64(x, y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f527(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_min_epu64(_mm512_abs_epi64(x), y); _mm512_storeu_si512(po, r); }
static NOINLINE void f528(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_min_epu64(x, _mm512_abs_epi64(y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f529(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_min_epu64(_mm512_abs_epi64(x), _mm512_abs_epi64(y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f530(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_min_epu64(x, _mm512_abs_epi64(x)); _mm512_storeu_si512(po, r); }
static NOINLINE void f531(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_min_epu64(_mm512_abs_epi64(x), x); _mm512_storeu_si512(po, r); }
static NOINLINE void f532(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_abs_epi64(_mm512_max_epu64(x, y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f533(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_max_epu64(_mm512_abs_epi64(x), y); _mm512_storeu_si512(po, r); }
static NOINLINE void f534(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_max_epu64(x, _mm512_abs_epi64(y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f535(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_max_epu64(_mm512_abs_epi64(x), _mm512_abs_epi64(y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f536(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_max_epu64(x, _mm512_abs_epi64(x)); _mm512_storeu_si512(po, r); }
static NOINLINE void f537(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_max_epu64(_mm512_abs_epi64(x), x); _mm512_storeu_si512(po, r); }
static NOINLINE void f538(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_abs_epi64(_mm512_and_si512(x, y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f539(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_and_si512(_mm512_abs_epi64(x), y); _mm512_storeu_si512(po, r); }
static NOINLINE void f540(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_and_si512(x, _mm512_abs_epi64(y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f541(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_and_si512(_mm512_abs_epi64(x), _mm512_abs_epi64(y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f542(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_and_si512(x, _mm512_abs_epi64(x)); _mm512_storeu_si512(po, r); }
static NOINLINE void f543(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_and_si512(_mm512_abs_epi64(x), x); _mm512_storeu_si512(po, r); }
static NOINLINE void f544(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_abs_epi64(_mm512_or_si512(x, y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f545(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_or_si512(_mm512_abs_epi64(x), y); _mm512_storeu_si512(po, r); }
static NOINLINE void f546(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_or_si512(x, _mm512_abs_epi64(y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f547(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_or_si512(_mm512_abs_epi64(x), _mm512_abs_epi64(y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f548(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_or_si512(x, _mm512_abs_epi64(x)); _mm512_storeu_si512(po, r); }
static NOINLINE void f549(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_or_si512(_mm512_abs_epi64(x), x); _mm512_storeu_si512(po, r); }
static NOINLINE void f550(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_abs_epi64(_mm512_xor_si512(x, y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f551(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_xor_si512(_mm512_abs_epi64(x), y); _mm512_storeu_si512(po, r); }
static NOINLINE void f552(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_xor_si512(x, _mm512_abs_epi64(y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f553(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_xor_si512(_mm512_abs_epi64(x), _mm512_abs_epi64(y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f554(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_xor_si512(x, _mm512_abs_epi64(x)); _mm512_storeu_si512(po, r); }
static NOINLINE void f555(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_xor_si512(_mm512_abs_epi64(x), x); _mm512_storeu_si512(po, r); }
static NOINLINE void f556(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_abs_epi64(_mm512_andnot_si512(x, y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f557(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_andnot_si512(_mm512_abs_epi64(x), y); _mm512_storeu_si512(po, r); }
static NOINLINE void f558(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_andnot_si512(x, _mm512_abs_epi64(y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f559(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_andnot_si512(_mm512_abs_epi64(x), _mm512_abs_epi64(y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f560(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_andnot_si512(x, _mm512_abs_epi64(x)); _mm512_storeu_si512(po, r); }
static NOINLINE void f561(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_andnot_si512(_mm512_abs_epi64(x), x); _mm512_storeu_si512(po, r); }
static NOINLINE void f562(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_abs_epi64(_mm512_sllv_epi64(x, y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f563(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sllv_epi64(_mm512_abs_epi64(x), y); _mm512_storeu_si512(po, r); }
static NOINLINE void f564(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sllv_epi64(x, _mm512_abs_epi64(y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f565(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sllv_epi64(_mm512_abs_epi64(x), _mm512_abs_epi64(y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f566(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sllv_epi64(x, _mm512_abs_epi64(x)); _mm512_storeu_si512(po, r); }
static NOINLINE void f567(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sllv_epi64(_mm512_abs_epi64(x), x); _mm512_storeu_si512(po, r); }
static NOINLINE void f568(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_abs_epi64(_mm512_srlv_epi64(x, y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f569(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srlv_epi64(_mm512_abs_epi64(x), y); _mm512_storeu_si512(po, r); }
static NOINLINE void f570(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srlv_epi64(x, _mm512_abs_epi64(y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f571(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srlv_epi64(_mm512_abs_epi64(x), _mm512_abs_epi64(y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f572(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srlv_epi64(x, _mm512_abs_epi64(x)); _mm512_storeu_si512(po, r); }
static NOINLINE void f573(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srlv_epi64(_mm512_abs_epi64(x), x); _mm512_storeu_si512(po, r); }
static NOINLINE void f574(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi8(_mm512_setzero_si512(), _mm512_add_epi8(x, y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f575(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_add_epi8(_mm512_sub_epi8(_mm512_setzero_si512(), x), y); _mm512_storeu_si512(po, r); }
static NOINLINE void f576(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_add_epi8(x, _mm512_sub_epi8(_mm512_setzero_si512(), y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f577(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_add_epi8(_mm512_sub_epi8(_mm512_setzero_si512(), x), _mm512_sub_epi8(_mm512_setzero_si512(), y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f578(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_add_epi8(x, _mm512_sub_epi8(_mm512_setzero_si512(), x)); _mm512_storeu_si512(po, r); }
static NOINLINE void f579(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_add_epi8(_mm512_sub_epi8(_mm512_setzero_si512(), x), x); _mm512_storeu_si512(po, r); }
static NOINLINE void f580(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi8(_mm512_setzero_si512(), _mm512_sub_epi8(x, y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f581(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi8(_mm512_sub_epi8(_mm512_setzero_si512(), x), y); _mm512_storeu_si512(po, r); }
static NOINLINE void f582(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi8(x, _mm512_sub_epi8(_mm512_setzero_si512(), y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f583(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi8(_mm512_sub_epi8(_mm512_setzero_si512(), x), _mm512_sub_epi8(_mm512_setzero_si512(), y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f584(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi8(x, _mm512_sub_epi8(_mm512_setzero_si512(), x)); _mm512_storeu_si512(po, r); }
static NOINLINE void f585(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi8(_mm512_sub_epi8(_mm512_setzero_si512(), x), x); _mm512_storeu_si512(po, r); }
static NOINLINE void f586(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi8(_mm512_setzero_si512(), _mm512_adds_epi8(x, y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f587(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_adds_epi8(_mm512_sub_epi8(_mm512_setzero_si512(), x), y); _mm512_storeu_si512(po, r); }
static NOINLINE void f588(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_adds_epi8(x, _mm512_sub_epi8(_mm512_setzero_si512(), y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f589(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_adds_epi8(_mm512_sub_epi8(_mm512_setzero_si512(), x), _mm512_sub_epi8(_mm512_setzero_si512(), y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f590(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_adds_epi8(x, _mm512_sub_epi8(_mm512_setzero_si512(), x)); _mm512_storeu_si512(po, r); }
static NOINLINE void f591(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_adds_epi8(_mm512_sub_epi8(_mm512_setzero_si512(), x), x); _mm512_storeu_si512(po, r); }
static NOINLINE void f592(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi8(_mm512_setzero_si512(), _mm512_subs_epi8(x, y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f593(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_subs_epi8(_mm512_sub_epi8(_mm512_setzero_si512(), x), y); _mm512_storeu_si512(po, r); }
static NOINLINE void f594(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_subs_epi8(x, _mm512_sub_epi8(_mm512_setzero_si512(), y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f595(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_subs_epi8(_mm512_sub_epi8(_mm512_setzero_si512(), x), _mm512_sub_epi8(_mm512_setzero_si512(), y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f596(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_subs_epi8(x, _mm512_sub_epi8(_mm512_setzero_si512(), x)); _mm512_storeu_si512(po, r); }
static NOINLINE void f597(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_subs_epi8(_mm512_sub_epi8(_mm512_setzero_si512(), x), x); _mm512_storeu_si512(po, r); }
static NOINLINE void f598(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi8(_mm512_setzero_si512(), _mm512_adds_epu8(x, y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f599(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_adds_epu8(_mm512_sub_epi8(_mm512_setzero_si512(), x), y); _mm512_storeu_si512(po, r); }
static NOINLINE void f600(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_adds_epu8(x, _mm512_sub_epi8(_mm512_setzero_si512(), y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f601(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_adds_epu8(_mm512_sub_epi8(_mm512_setzero_si512(), x), _mm512_sub_epi8(_mm512_setzero_si512(), y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f602(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_adds_epu8(x, _mm512_sub_epi8(_mm512_setzero_si512(), x)); _mm512_storeu_si512(po, r); }
static NOINLINE void f603(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_adds_epu8(_mm512_sub_epi8(_mm512_setzero_si512(), x), x); _mm512_storeu_si512(po, r); }
static NOINLINE void f604(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi8(_mm512_setzero_si512(), _mm512_subs_epu8(x, y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f605(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_subs_epu8(_mm512_sub_epi8(_mm512_setzero_si512(), x), y); _mm512_storeu_si512(po, r); }
static NOINLINE void f606(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_subs_epu8(x, _mm512_sub_epi8(_mm512_setzero_si512(), y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f607(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_subs_epu8(_mm512_sub_epi8(_mm512_setzero_si512(), x), _mm512_sub_epi8(_mm512_setzero_si512(), y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f608(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_subs_epu8(x, _mm512_sub_epi8(_mm512_setzero_si512(), x)); _mm512_storeu_si512(po, r); }
static NOINLINE void f609(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_subs_epu8(_mm512_sub_epi8(_mm512_setzero_si512(), x), x); _mm512_storeu_si512(po, r); }
static NOINLINE void f610(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi8(_mm512_setzero_si512(), _mm512_avg_epu8(x, y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f611(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_avg_epu8(_mm512_sub_epi8(_mm512_setzero_si512(), x), y); _mm512_storeu_si512(po, r); }
static NOINLINE void f612(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_avg_epu8(x, _mm512_sub_epi8(_mm512_setzero_si512(), y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f613(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_avg_epu8(_mm512_sub_epi8(_mm512_setzero_si512(), x), _mm512_sub_epi8(_mm512_setzero_si512(), y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f614(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_avg_epu8(x, _mm512_sub_epi8(_mm512_setzero_si512(), x)); _mm512_storeu_si512(po, r); }
static NOINLINE void f615(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_avg_epu8(_mm512_sub_epi8(_mm512_setzero_si512(), x), x); _mm512_storeu_si512(po, r); }
static NOINLINE void f616(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi8(_mm512_setzero_si512(), _mm512_min_epi8(x, y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f617(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_min_epi8(_mm512_sub_epi8(_mm512_setzero_si512(), x), y); _mm512_storeu_si512(po, r); }
static NOINLINE void f618(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_min_epi8(x, _mm512_sub_epi8(_mm512_setzero_si512(), y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f619(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_min_epi8(_mm512_sub_epi8(_mm512_setzero_si512(), x), _mm512_sub_epi8(_mm512_setzero_si512(), y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f620(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_min_epi8(x, _mm512_sub_epi8(_mm512_setzero_si512(), x)); _mm512_storeu_si512(po, r); }
static NOINLINE void f621(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_min_epi8(_mm512_sub_epi8(_mm512_setzero_si512(), x), x); _mm512_storeu_si512(po, r); }
static NOINLINE void f622(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi8(_mm512_setzero_si512(), _mm512_max_epi8(x, y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f623(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_max_epi8(_mm512_sub_epi8(_mm512_setzero_si512(), x), y); _mm512_storeu_si512(po, r); }
static NOINLINE void f624(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_max_epi8(x, _mm512_sub_epi8(_mm512_setzero_si512(), y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f625(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_max_epi8(_mm512_sub_epi8(_mm512_setzero_si512(), x), _mm512_sub_epi8(_mm512_setzero_si512(), y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f626(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_max_epi8(x, _mm512_sub_epi8(_mm512_setzero_si512(), x)); _mm512_storeu_si512(po, r); }
static NOINLINE void f627(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_max_epi8(_mm512_sub_epi8(_mm512_setzero_si512(), x), x); _mm512_storeu_si512(po, r); }
static NOINLINE void f628(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi8(_mm512_setzero_si512(), _mm512_min_epu8(x, y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f629(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_min_epu8(_mm512_sub_epi8(_mm512_setzero_si512(), x), y); _mm512_storeu_si512(po, r); }
static NOINLINE void f630(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_min_epu8(x, _mm512_sub_epi8(_mm512_setzero_si512(), y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f631(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_min_epu8(_mm512_sub_epi8(_mm512_setzero_si512(), x), _mm512_sub_epi8(_mm512_setzero_si512(), y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f632(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_min_epu8(x, _mm512_sub_epi8(_mm512_setzero_si512(), x)); _mm512_storeu_si512(po, r); }
static NOINLINE void f633(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_min_epu8(_mm512_sub_epi8(_mm512_setzero_si512(), x), x); _mm512_storeu_si512(po, r); }
static NOINLINE void f634(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi8(_mm512_setzero_si512(), _mm512_max_epu8(x, y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f635(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_max_epu8(_mm512_sub_epi8(_mm512_setzero_si512(), x), y); _mm512_storeu_si512(po, r); }
static NOINLINE void f636(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_max_epu8(x, _mm512_sub_epi8(_mm512_setzero_si512(), y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f637(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_max_epu8(_mm512_sub_epi8(_mm512_setzero_si512(), x), _mm512_sub_epi8(_mm512_setzero_si512(), y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f638(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_max_epu8(x, _mm512_sub_epi8(_mm512_setzero_si512(), x)); _mm512_storeu_si512(po, r); }
static NOINLINE void f639(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_max_epu8(_mm512_sub_epi8(_mm512_setzero_si512(), x), x); _mm512_storeu_si512(po, r); }
static NOINLINE void f640(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi8(_mm512_setzero_si512(), _mm512_and_si512(x, y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f641(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_and_si512(_mm512_sub_epi8(_mm512_setzero_si512(), x), y); _mm512_storeu_si512(po, r); }
static NOINLINE void f642(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_and_si512(x, _mm512_sub_epi8(_mm512_setzero_si512(), y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f643(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_and_si512(_mm512_sub_epi8(_mm512_setzero_si512(), x), _mm512_sub_epi8(_mm512_setzero_si512(), y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f644(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_and_si512(x, _mm512_sub_epi8(_mm512_setzero_si512(), x)); _mm512_storeu_si512(po, r); }
static NOINLINE void f645(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_and_si512(_mm512_sub_epi8(_mm512_setzero_si512(), x), x); _mm512_storeu_si512(po, r); }
static NOINLINE void f646(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi8(_mm512_setzero_si512(), _mm512_or_si512(x, y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f647(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_or_si512(_mm512_sub_epi8(_mm512_setzero_si512(), x), y); _mm512_storeu_si512(po, r); }
static NOINLINE void f648(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_or_si512(x, _mm512_sub_epi8(_mm512_setzero_si512(), y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f649(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_or_si512(_mm512_sub_epi8(_mm512_setzero_si512(), x), _mm512_sub_epi8(_mm512_setzero_si512(), y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f650(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_or_si512(x, _mm512_sub_epi8(_mm512_setzero_si512(), x)); _mm512_storeu_si512(po, r); }
static NOINLINE void f651(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_or_si512(_mm512_sub_epi8(_mm512_setzero_si512(), x), x); _mm512_storeu_si512(po, r); }
static NOINLINE void f652(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi8(_mm512_setzero_si512(), _mm512_xor_si512(x, y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f653(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_xor_si512(_mm512_sub_epi8(_mm512_setzero_si512(), x), y); _mm512_storeu_si512(po, r); }
static NOINLINE void f654(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_xor_si512(x, _mm512_sub_epi8(_mm512_setzero_si512(), y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f655(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_xor_si512(_mm512_sub_epi8(_mm512_setzero_si512(), x), _mm512_sub_epi8(_mm512_setzero_si512(), y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f656(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_xor_si512(x, _mm512_sub_epi8(_mm512_setzero_si512(), x)); _mm512_storeu_si512(po, r); }
static NOINLINE void f657(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_xor_si512(_mm512_sub_epi8(_mm512_setzero_si512(), x), x); _mm512_storeu_si512(po, r); }
static NOINLINE void f658(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi8(_mm512_setzero_si512(), _mm512_andnot_si512(x, y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f659(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_andnot_si512(_mm512_sub_epi8(_mm512_setzero_si512(), x), y); _mm512_storeu_si512(po, r); }
static NOINLINE void f660(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_andnot_si512(x, _mm512_sub_epi8(_mm512_setzero_si512(), y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f661(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_andnot_si512(_mm512_sub_epi8(_mm512_setzero_si512(), x), _mm512_sub_epi8(_mm512_setzero_si512(), y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f662(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_andnot_si512(x, _mm512_sub_epi8(_mm512_setzero_si512(), x)); _mm512_storeu_si512(po, r); }
static NOINLINE void f663(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_andnot_si512(_mm512_sub_epi8(_mm512_setzero_si512(), x), x); _mm512_storeu_si512(po, r); }
static NOINLINE void f664(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi16(_mm512_setzero_si512(), _mm512_add_epi16(x, y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f665(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_add_epi16(_mm512_sub_epi16(_mm512_setzero_si512(), x), y); _mm512_storeu_si512(po, r); }
static NOINLINE void f666(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_add_epi16(x, _mm512_sub_epi16(_mm512_setzero_si512(), y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f667(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_add_epi16(_mm512_sub_epi16(_mm512_setzero_si512(), x), _mm512_sub_epi16(_mm512_setzero_si512(), y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f668(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_add_epi16(x, _mm512_sub_epi16(_mm512_setzero_si512(), x)); _mm512_storeu_si512(po, r); }
static NOINLINE void f669(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_add_epi16(_mm512_sub_epi16(_mm512_setzero_si512(), x), x); _mm512_storeu_si512(po, r); }
static NOINLINE void f670(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi16(_mm512_setzero_si512(), _mm512_sub_epi16(x, y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f671(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi16(_mm512_sub_epi16(_mm512_setzero_si512(), x), y); _mm512_storeu_si512(po, r); }
static NOINLINE void f672(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi16(x, _mm512_sub_epi16(_mm512_setzero_si512(), y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f673(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi16(_mm512_sub_epi16(_mm512_setzero_si512(), x), _mm512_sub_epi16(_mm512_setzero_si512(), y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f674(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi16(x, _mm512_sub_epi16(_mm512_setzero_si512(), x)); _mm512_storeu_si512(po, r); }
static NOINLINE void f675(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi16(_mm512_sub_epi16(_mm512_setzero_si512(), x), x); _mm512_storeu_si512(po, r); }
static NOINLINE void f676(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi16(_mm512_setzero_si512(), _mm512_adds_epi16(x, y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f677(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_adds_epi16(_mm512_sub_epi16(_mm512_setzero_si512(), x), y); _mm512_storeu_si512(po, r); }
static NOINLINE void f678(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_adds_epi16(x, _mm512_sub_epi16(_mm512_setzero_si512(), y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f679(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_adds_epi16(_mm512_sub_epi16(_mm512_setzero_si512(), x), _mm512_sub_epi16(_mm512_setzero_si512(), y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f680(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_adds_epi16(x, _mm512_sub_epi16(_mm512_setzero_si512(), x)); _mm512_storeu_si512(po, r); }
static NOINLINE void f681(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_adds_epi16(_mm512_sub_epi16(_mm512_setzero_si512(), x), x); _mm512_storeu_si512(po, r); }
static NOINLINE void f682(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi16(_mm512_setzero_si512(), _mm512_subs_epi16(x, y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f683(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_subs_epi16(_mm512_sub_epi16(_mm512_setzero_si512(), x), y); _mm512_storeu_si512(po, r); }
static NOINLINE void f684(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_subs_epi16(x, _mm512_sub_epi16(_mm512_setzero_si512(), y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f685(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_subs_epi16(_mm512_sub_epi16(_mm512_setzero_si512(), x), _mm512_sub_epi16(_mm512_setzero_si512(), y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f686(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_subs_epi16(x, _mm512_sub_epi16(_mm512_setzero_si512(), x)); _mm512_storeu_si512(po, r); }
static NOINLINE void f687(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_subs_epi16(_mm512_sub_epi16(_mm512_setzero_si512(), x), x); _mm512_storeu_si512(po, r); }
static NOINLINE void f688(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi16(_mm512_setzero_si512(), _mm512_adds_epu16(x, y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f689(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_adds_epu16(_mm512_sub_epi16(_mm512_setzero_si512(), x), y); _mm512_storeu_si512(po, r); }
static NOINLINE void f690(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_adds_epu16(x, _mm512_sub_epi16(_mm512_setzero_si512(), y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f691(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_adds_epu16(_mm512_sub_epi16(_mm512_setzero_si512(), x), _mm512_sub_epi16(_mm512_setzero_si512(), y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f692(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_adds_epu16(x, _mm512_sub_epi16(_mm512_setzero_si512(), x)); _mm512_storeu_si512(po, r); }
static NOINLINE void f693(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_adds_epu16(_mm512_sub_epi16(_mm512_setzero_si512(), x), x); _mm512_storeu_si512(po, r); }
static NOINLINE void f694(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi16(_mm512_setzero_si512(), _mm512_subs_epu16(x, y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f695(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_subs_epu16(_mm512_sub_epi16(_mm512_setzero_si512(), x), y); _mm512_storeu_si512(po, r); }
static NOINLINE void f696(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_subs_epu16(x, _mm512_sub_epi16(_mm512_setzero_si512(), y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f697(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_subs_epu16(_mm512_sub_epi16(_mm512_setzero_si512(), x), _mm512_sub_epi16(_mm512_setzero_si512(), y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f698(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_subs_epu16(x, _mm512_sub_epi16(_mm512_setzero_si512(), x)); _mm512_storeu_si512(po, r); }
static NOINLINE void f699(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_subs_epu16(_mm512_sub_epi16(_mm512_setzero_si512(), x), x); _mm512_storeu_si512(po, r); }
static NOINLINE void f700(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi16(_mm512_setzero_si512(), _mm512_avg_epu16(x, y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f701(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_avg_epu16(_mm512_sub_epi16(_mm512_setzero_si512(), x), y); _mm512_storeu_si512(po, r); }
static NOINLINE void f702(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_avg_epu16(x, _mm512_sub_epi16(_mm512_setzero_si512(), y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f703(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_avg_epu16(_mm512_sub_epi16(_mm512_setzero_si512(), x), _mm512_sub_epi16(_mm512_setzero_si512(), y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f704(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_avg_epu16(x, _mm512_sub_epi16(_mm512_setzero_si512(), x)); _mm512_storeu_si512(po, r); }
static NOINLINE void f705(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_avg_epu16(_mm512_sub_epi16(_mm512_setzero_si512(), x), x); _mm512_storeu_si512(po, r); }
static NOINLINE void f706(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi16(_mm512_setzero_si512(), _mm512_min_epi16(x, y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f707(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_min_epi16(_mm512_sub_epi16(_mm512_setzero_si512(), x), y); _mm512_storeu_si512(po, r); }
static NOINLINE void f708(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_min_epi16(x, _mm512_sub_epi16(_mm512_setzero_si512(), y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f709(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_min_epi16(_mm512_sub_epi16(_mm512_setzero_si512(), x), _mm512_sub_epi16(_mm512_setzero_si512(), y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f710(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_min_epi16(x, _mm512_sub_epi16(_mm512_setzero_si512(), x)); _mm512_storeu_si512(po, r); }
static NOINLINE void f711(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_min_epi16(_mm512_sub_epi16(_mm512_setzero_si512(), x), x); _mm512_storeu_si512(po, r); }
static NOINLINE void f712(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi16(_mm512_setzero_si512(), _mm512_max_epi16(x, y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f713(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_max_epi16(_mm512_sub_epi16(_mm512_setzero_si512(), x), y); _mm512_storeu_si512(po, r); }
static NOINLINE void f714(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_max_epi16(x, _mm512_sub_epi16(_mm512_setzero_si512(), y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f715(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_max_epi16(_mm512_sub_epi16(_mm512_setzero_si512(), x), _mm512_sub_epi16(_mm512_setzero_si512(), y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f716(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_max_epi16(x, _mm512_sub_epi16(_mm512_setzero_si512(), x)); _mm512_storeu_si512(po, r); }
static NOINLINE void f717(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_max_epi16(_mm512_sub_epi16(_mm512_setzero_si512(), x), x); _mm512_storeu_si512(po, r); }
static NOINLINE void f718(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi16(_mm512_setzero_si512(), _mm512_min_epu16(x, y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f719(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_min_epu16(_mm512_sub_epi16(_mm512_setzero_si512(), x), y); _mm512_storeu_si512(po, r); }
static NOINLINE void f720(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_min_epu16(x, _mm512_sub_epi16(_mm512_setzero_si512(), y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f721(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_min_epu16(_mm512_sub_epi16(_mm512_setzero_si512(), x), _mm512_sub_epi16(_mm512_setzero_si512(), y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f722(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_min_epu16(x, _mm512_sub_epi16(_mm512_setzero_si512(), x)); _mm512_storeu_si512(po, r); }
static NOINLINE void f723(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_min_epu16(_mm512_sub_epi16(_mm512_setzero_si512(), x), x); _mm512_storeu_si512(po, r); }
static NOINLINE void f724(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi16(_mm512_setzero_si512(), _mm512_max_epu16(x, y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f725(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_max_epu16(_mm512_sub_epi16(_mm512_setzero_si512(), x), y); _mm512_storeu_si512(po, r); }
static NOINLINE void f726(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_max_epu16(x, _mm512_sub_epi16(_mm512_setzero_si512(), y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f727(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_max_epu16(_mm512_sub_epi16(_mm512_setzero_si512(), x), _mm512_sub_epi16(_mm512_setzero_si512(), y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f728(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_max_epu16(x, _mm512_sub_epi16(_mm512_setzero_si512(), x)); _mm512_storeu_si512(po, r); }
static NOINLINE void f729(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_max_epu16(_mm512_sub_epi16(_mm512_setzero_si512(), x), x); _mm512_storeu_si512(po, r); }
static NOINLINE void f730(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi16(_mm512_setzero_si512(), _mm512_and_si512(x, y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f731(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_and_si512(_mm512_sub_epi16(_mm512_setzero_si512(), x), y); _mm512_storeu_si512(po, r); }
static NOINLINE void f732(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_and_si512(x, _mm512_sub_epi16(_mm512_setzero_si512(), y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f733(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_and_si512(_mm512_sub_epi16(_mm512_setzero_si512(), x), _mm512_sub_epi16(_mm512_setzero_si512(), y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f734(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_and_si512(x, _mm512_sub_epi16(_mm512_setzero_si512(), x)); _mm512_storeu_si512(po, r); }
static NOINLINE void f735(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_and_si512(_mm512_sub_epi16(_mm512_setzero_si512(), x), x); _mm512_storeu_si512(po, r); }
static NOINLINE void f736(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi16(_mm512_setzero_si512(), _mm512_or_si512(x, y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f737(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_or_si512(_mm512_sub_epi16(_mm512_setzero_si512(), x), y); _mm512_storeu_si512(po, r); }
static NOINLINE void f738(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_or_si512(x, _mm512_sub_epi16(_mm512_setzero_si512(), y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f739(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_or_si512(_mm512_sub_epi16(_mm512_setzero_si512(), x), _mm512_sub_epi16(_mm512_setzero_si512(), y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f740(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_or_si512(x, _mm512_sub_epi16(_mm512_setzero_si512(), x)); _mm512_storeu_si512(po, r); }
static NOINLINE void f741(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_or_si512(_mm512_sub_epi16(_mm512_setzero_si512(), x), x); _mm512_storeu_si512(po, r); }
static NOINLINE void f742(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi16(_mm512_setzero_si512(), _mm512_xor_si512(x, y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f743(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_xor_si512(_mm512_sub_epi16(_mm512_setzero_si512(), x), y); _mm512_storeu_si512(po, r); }
static NOINLINE void f744(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_xor_si512(x, _mm512_sub_epi16(_mm512_setzero_si512(), y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f745(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_xor_si512(_mm512_sub_epi16(_mm512_setzero_si512(), x), _mm512_sub_epi16(_mm512_setzero_si512(), y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f746(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_xor_si512(x, _mm512_sub_epi16(_mm512_setzero_si512(), x)); _mm512_storeu_si512(po, r); }
static NOINLINE void f747(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_xor_si512(_mm512_sub_epi16(_mm512_setzero_si512(), x), x); _mm512_storeu_si512(po, r); }
static NOINLINE void f748(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi16(_mm512_setzero_si512(), _mm512_andnot_si512(x, y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f749(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_andnot_si512(_mm512_sub_epi16(_mm512_setzero_si512(), x), y); _mm512_storeu_si512(po, r); }
static NOINLINE void f750(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_andnot_si512(x, _mm512_sub_epi16(_mm512_setzero_si512(), y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f751(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_andnot_si512(_mm512_sub_epi16(_mm512_setzero_si512(), x), _mm512_sub_epi16(_mm512_setzero_si512(), y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f752(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_andnot_si512(x, _mm512_sub_epi16(_mm512_setzero_si512(), x)); _mm512_storeu_si512(po, r); }
static NOINLINE void f753(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_andnot_si512(_mm512_sub_epi16(_mm512_setzero_si512(), x), x); _mm512_storeu_si512(po, r); }
static NOINLINE void f754(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi16(_mm512_setzero_si512(), _mm512_mullo_epi16(x, y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f755(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_mullo_epi16(_mm512_sub_epi16(_mm512_setzero_si512(), x), y); _mm512_storeu_si512(po, r); }
static NOINLINE void f756(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_mullo_epi16(x, _mm512_sub_epi16(_mm512_setzero_si512(), y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f757(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_mullo_epi16(_mm512_sub_epi16(_mm512_setzero_si512(), x), _mm512_sub_epi16(_mm512_setzero_si512(), y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f758(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_mullo_epi16(x, _mm512_sub_epi16(_mm512_setzero_si512(), x)); _mm512_storeu_si512(po, r); }
static NOINLINE void f759(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_mullo_epi16(_mm512_sub_epi16(_mm512_setzero_si512(), x), x); _mm512_storeu_si512(po, r); }
static NOINLINE void f760(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi16(_mm512_setzero_si512(), _mm512_mulhi_epi16(x, y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f761(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_mulhi_epi16(_mm512_sub_epi16(_mm512_setzero_si512(), x), y); _mm512_storeu_si512(po, r); }
static NOINLINE void f762(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_mulhi_epi16(x, _mm512_sub_epi16(_mm512_setzero_si512(), y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f763(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_mulhi_epi16(_mm512_sub_epi16(_mm512_setzero_si512(), x), _mm512_sub_epi16(_mm512_setzero_si512(), y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f764(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_mulhi_epi16(x, _mm512_sub_epi16(_mm512_setzero_si512(), x)); _mm512_storeu_si512(po, r); }
static NOINLINE void f765(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_mulhi_epi16(_mm512_sub_epi16(_mm512_setzero_si512(), x), x); _mm512_storeu_si512(po, r); }
static NOINLINE void f766(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi16(_mm512_setzero_si512(), _mm512_mulhi_epu16(x, y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f767(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_mulhi_epu16(_mm512_sub_epi16(_mm512_setzero_si512(), x), y); _mm512_storeu_si512(po, r); }
static NOINLINE void f768(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_mulhi_epu16(x, _mm512_sub_epi16(_mm512_setzero_si512(), y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f769(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_mulhi_epu16(_mm512_sub_epi16(_mm512_setzero_si512(), x), _mm512_sub_epi16(_mm512_setzero_si512(), y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f770(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_mulhi_epu16(x, _mm512_sub_epi16(_mm512_setzero_si512(), x)); _mm512_storeu_si512(po, r); }
static NOINLINE void f771(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_mulhi_epu16(_mm512_sub_epi16(_mm512_setzero_si512(), x), x); _mm512_storeu_si512(po, r); }
static NOINLINE void f772(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi32(_mm512_setzero_si512(), _mm512_add_epi32(x, y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f773(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_add_epi32(_mm512_sub_epi32(_mm512_setzero_si512(), x), y); _mm512_storeu_si512(po, r); }
static NOINLINE void f774(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_add_epi32(x, _mm512_sub_epi32(_mm512_setzero_si512(), y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f775(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_add_epi32(_mm512_sub_epi32(_mm512_setzero_si512(), x), _mm512_sub_epi32(_mm512_setzero_si512(), y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f776(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_add_epi32(x, _mm512_sub_epi32(_mm512_setzero_si512(), x)); _mm512_storeu_si512(po, r); }
static NOINLINE void f777(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_add_epi32(_mm512_sub_epi32(_mm512_setzero_si512(), x), x); _mm512_storeu_si512(po, r); }
static NOINLINE void f778(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi32(_mm512_setzero_si512(), _mm512_sub_epi32(x, y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f779(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi32(_mm512_sub_epi32(_mm512_setzero_si512(), x), y); _mm512_storeu_si512(po, r); }
static NOINLINE void f780(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi32(x, _mm512_sub_epi32(_mm512_setzero_si512(), y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f781(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi32(_mm512_sub_epi32(_mm512_setzero_si512(), x), _mm512_sub_epi32(_mm512_setzero_si512(), y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f782(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi32(x, _mm512_sub_epi32(_mm512_setzero_si512(), x)); _mm512_storeu_si512(po, r); }
static NOINLINE void f783(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi32(_mm512_sub_epi32(_mm512_setzero_si512(), x), x); _mm512_storeu_si512(po, r); }
static NOINLINE void f784(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi32(_mm512_setzero_si512(), _mm512_min_epi32(x, y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f785(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_min_epi32(_mm512_sub_epi32(_mm512_setzero_si512(), x), y); _mm512_storeu_si512(po, r); }
static NOINLINE void f786(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_min_epi32(x, _mm512_sub_epi32(_mm512_setzero_si512(), y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f787(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_min_epi32(_mm512_sub_epi32(_mm512_setzero_si512(), x), _mm512_sub_epi32(_mm512_setzero_si512(), y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f788(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_min_epi32(x, _mm512_sub_epi32(_mm512_setzero_si512(), x)); _mm512_storeu_si512(po, r); }
static NOINLINE void f789(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_min_epi32(_mm512_sub_epi32(_mm512_setzero_si512(), x), x); _mm512_storeu_si512(po, r); }
static NOINLINE void f790(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi32(_mm512_setzero_si512(), _mm512_max_epi32(x, y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f791(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_max_epi32(_mm512_sub_epi32(_mm512_setzero_si512(), x), y); _mm512_storeu_si512(po, r); }
static NOINLINE void f792(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_max_epi32(x, _mm512_sub_epi32(_mm512_setzero_si512(), y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f793(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_max_epi32(_mm512_sub_epi32(_mm512_setzero_si512(), x), _mm512_sub_epi32(_mm512_setzero_si512(), y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f794(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_max_epi32(x, _mm512_sub_epi32(_mm512_setzero_si512(), x)); _mm512_storeu_si512(po, r); }
static NOINLINE void f795(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_max_epi32(_mm512_sub_epi32(_mm512_setzero_si512(), x), x); _mm512_storeu_si512(po, r); }
static NOINLINE void f796(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi32(_mm512_setzero_si512(), _mm512_min_epu32(x, y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f797(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_min_epu32(_mm512_sub_epi32(_mm512_setzero_si512(), x), y); _mm512_storeu_si512(po, r); }
static NOINLINE void f798(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_min_epu32(x, _mm512_sub_epi32(_mm512_setzero_si512(), y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f799(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_min_epu32(_mm512_sub_epi32(_mm512_setzero_si512(), x), _mm512_sub_epi32(_mm512_setzero_si512(), y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f800(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_min_epu32(x, _mm512_sub_epi32(_mm512_setzero_si512(), x)); _mm512_storeu_si512(po, r); }
static NOINLINE void f801(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_min_epu32(_mm512_sub_epi32(_mm512_setzero_si512(), x), x); _mm512_storeu_si512(po, r); }
static NOINLINE void f802(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi32(_mm512_setzero_si512(), _mm512_max_epu32(x, y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f803(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_max_epu32(_mm512_sub_epi32(_mm512_setzero_si512(), x), y); _mm512_storeu_si512(po, r); }
static NOINLINE void f804(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_max_epu32(x, _mm512_sub_epi32(_mm512_setzero_si512(), y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f805(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_max_epu32(_mm512_sub_epi32(_mm512_setzero_si512(), x), _mm512_sub_epi32(_mm512_setzero_si512(), y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f806(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_max_epu32(x, _mm512_sub_epi32(_mm512_setzero_si512(), x)); _mm512_storeu_si512(po, r); }
static NOINLINE void f807(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_max_epu32(_mm512_sub_epi32(_mm512_setzero_si512(), x), x); _mm512_storeu_si512(po, r); }
static NOINLINE void f808(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi32(_mm512_setzero_si512(), _mm512_and_si512(x, y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f809(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_and_si512(_mm512_sub_epi32(_mm512_setzero_si512(), x), y); _mm512_storeu_si512(po, r); }
static NOINLINE void f810(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_and_si512(x, _mm512_sub_epi32(_mm512_setzero_si512(), y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f811(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_and_si512(_mm512_sub_epi32(_mm512_setzero_si512(), x), _mm512_sub_epi32(_mm512_setzero_si512(), y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f812(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_and_si512(x, _mm512_sub_epi32(_mm512_setzero_si512(), x)); _mm512_storeu_si512(po, r); }
static NOINLINE void f813(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_and_si512(_mm512_sub_epi32(_mm512_setzero_si512(), x), x); _mm512_storeu_si512(po, r); }
static NOINLINE void f814(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi32(_mm512_setzero_si512(), _mm512_or_si512(x, y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f815(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_or_si512(_mm512_sub_epi32(_mm512_setzero_si512(), x), y); _mm512_storeu_si512(po, r); }
static NOINLINE void f816(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_or_si512(x, _mm512_sub_epi32(_mm512_setzero_si512(), y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f817(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_or_si512(_mm512_sub_epi32(_mm512_setzero_si512(), x), _mm512_sub_epi32(_mm512_setzero_si512(), y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f818(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_or_si512(x, _mm512_sub_epi32(_mm512_setzero_si512(), x)); _mm512_storeu_si512(po, r); }
static NOINLINE void f819(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_or_si512(_mm512_sub_epi32(_mm512_setzero_si512(), x), x); _mm512_storeu_si512(po, r); }
static NOINLINE void f820(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi32(_mm512_setzero_si512(), _mm512_xor_si512(x, y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f821(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_xor_si512(_mm512_sub_epi32(_mm512_setzero_si512(), x), y); _mm512_storeu_si512(po, r); }
static NOINLINE void f822(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_xor_si512(x, _mm512_sub_epi32(_mm512_setzero_si512(), y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f823(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_xor_si512(_mm512_sub_epi32(_mm512_setzero_si512(), x), _mm512_sub_epi32(_mm512_setzero_si512(), y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f824(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_xor_si512(x, _mm512_sub_epi32(_mm512_setzero_si512(), x)); _mm512_storeu_si512(po, r); }
static NOINLINE void f825(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_xor_si512(_mm512_sub_epi32(_mm512_setzero_si512(), x), x); _mm512_storeu_si512(po, r); }
static NOINLINE void f826(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi32(_mm512_setzero_si512(), _mm512_andnot_si512(x, y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f827(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_andnot_si512(_mm512_sub_epi32(_mm512_setzero_si512(), x), y); _mm512_storeu_si512(po, r); }
static NOINLINE void f828(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_andnot_si512(x, _mm512_sub_epi32(_mm512_setzero_si512(), y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f829(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_andnot_si512(_mm512_sub_epi32(_mm512_setzero_si512(), x), _mm512_sub_epi32(_mm512_setzero_si512(), y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f830(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_andnot_si512(x, _mm512_sub_epi32(_mm512_setzero_si512(), x)); _mm512_storeu_si512(po, r); }
static NOINLINE void f831(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_andnot_si512(_mm512_sub_epi32(_mm512_setzero_si512(), x), x); _mm512_storeu_si512(po, r); }
static NOINLINE void f832(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi32(_mm512_setzero_si512(), _mm512_mullo_epi32(x, y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f833(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_mullo_epi32(_mm512_sub_epi32(_mm512_setzero_si512(), x), y); _mm512_storeu_si512(po, r); }
static NOINLINE void f834(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_mullo_epi32(x, _mm512_sub_epi32(_mm512_setzero_si512(), y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f835(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_mullo_epi32(_mm512_sub_epi32(_mm512_setzero_si512(), x), _mm512_sub_epi32(_mm512_setzero_si512(), y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f836(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_mullo_epi32(x, _mm512_sub_epi32(_mm512_setzero_si512(), x)); _mm512_storeu_si512(po, r); }
static NOINLINE void f837(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_mullo_epi32(_mm512_sub_epi32(_mm512_setzero_si512(), x), x); _mm512_storeu_si512(po, r); }
static NOINLINE void f838(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi32(_mm512_setzero_si512(), _mm512_sllv_epi32(x, y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f839(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sllv_epi32(_mm512_sub_epi32(_mm512_setzero_si512(), x), y); _mm512_storeu_si512(po, r); }
static NOINLINE void f840(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sllv_epi32(x, _mm512_sub_epi32(_mm512_setzero_si512(), y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f841(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sllv_epi32(_mm512_sub_epi32(_mm512_setzero_si512(), x), _mm512_sub_epi32(_mm512_setzero_si512(), y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f842(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sllv_epi32(x, _mm512_sub_epi32(_mm512_setzero_si512(), x)); _mm512_storeu_si512(po, r); }
static NOINLINE void f843(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sllv_epi32(_mm512_sub_epi32(_mm512_setzero_si512(), x), x); _mm512_storeu_si512(po, r); }
static NOINLINE void f844(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi32(_mm512_setzero_si512(), _mm512_srlv_epi32(x, y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f845(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srlv_epi32(_mm512_sub_epi32(_mm512_setzero_si512(), x), y); _mm512_storeu_si512(po, r); }
static NOINLINE void f846(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srlv_epi32(x, _mm512_sub_epi32(_mm512_setzero_si512(), y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f847(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srlv_epi32(_mm512_sub_epi32(_mm512_setzero_si512(), x), _mm512_sub_epi32(_mm512_setzero_si512(), y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f848(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srlv_epi32(x, _mm512_sub_epi32(_mm512_setzero_si512(), x)); _mm512_storeu_si512(po, r); }
static NOINLINE void f849(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srlv_epi32(_mm512_sub_epi32(_mm512_setzero_si512(), x), x); _mm512_storeu_si512(po, r); }
static NOINLINE void f850(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi32(_mm512_setzero_si512(), _mm512_srav_epi32(x, y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f851(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srav_epi32(_mm512_sub_epi32(_mm512_setzero_si512(), x), y); _mm512_storeu_si512(po, r); }
static NOINLINE void f852(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srav_epi32(x, _mm512_sub_epi32(_mm512_setzero_si512(), y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f853(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srav_epi32(_mm512_sub_epi32(_mm512_setzero_si512(), x), _mm512_sub_epi32(_mm512_setzero_si512(), y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f854(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srav_epi32(x, _mm512_sub_epi32(_mm512_setzero_si512(), x)); _mm512_storeu_si512(po, r); }
static NOINLINE void f855(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srav_epi32(_mm512_sub_epi32(_mm512_setzero_si512(), x), x); _mm512_storeu_si512(po, r); }
static NOINLINE void f856(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi64(_mm512_setzero_si512(), _mm512_add_epi64(x, y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f857(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_add_epi64(_mm512_sub_epi64(_mm512_setzero_si512(), x), y); _mm512_storeu_si512(po, r); }
static NOINLINE void f858(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_add_epi64(x, _mm512_sub_epi64(_mm512_setzero_si512(), y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f859(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_add_epi64(_mm512_sub_epi64(_mm512_setzero_si512(), x), _mm512_sub_epi64(_mm512_setzero_si512(), y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f860(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_add_epi64(x, _mm512_sub_epi64(_mm512_setzero_si512(), x)); _mm512_storeu_si512(po, r); }
static NOINLINE void f861(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_add_epi64(_mm512_sub_epi64(_mm512_setzero_si512(), x), x); _mm512_storeu_si512(po, r); }
static NOINLINE void f862(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi64(_mm512_setzero_si512(), _mm512_sub_epi64(x, y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f863(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi64(_mm512_sub_epi64(_mm512_setzero_si512(), x), y); _mm512_storeu_si512(po, r); }
static NOINLINE void f864(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi64(x, _mm512_sub_epi64(_mm512_setzero_si512(), y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f865(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi64(_mm512_sub_epi64(_mm512_setzero_si512(), x), _mm512_sub_epi64(_mm512_setzero_si512(), y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f866(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi64(x, _mm512_sub_epi64(_mm512_setzero_si512(), x)); _mm512_storeu_si512(po, r); }
static NOINLINE void f867(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi64(_mm512_sub_epi64(_mm512_setzero_si512(), x), x); _mm512_storeu_si512(po, r); }
static NOINLINE void f868(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi64(_mm512_setzero_si512(), _mm512_min_epi64(x, y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f869(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_min_epi64(_mm512_sub_epi64(_mm512_setzero_si512(), x), y); _mm512_storeu_si512(po, r); }
static NOINLINE void f870(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_min_epi64(x, _mm512_sub_epi64(_mm512_setzero_si512(), y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f871(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_min_epi64(_mm512_sub_epi64(_mm512_setzero_si512(), x), _mm512_sub_epi64(_mm512_setzero_si512(), y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f872(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_min_epi64(x, _mm512_sub_epi64(_mm512_setzero_si512(), x)); _mm512_storeu_si512(po, r); }
static NOINLINE void f873(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_min_epi64(_mm512_sub_epi64(_mm512_setzero_si512(), x), x); _mm512_storeu_si512(po, r); }
static NOINLINE void f874(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi64(_mm512_setzero_si512(), _mm512_max_epi64(x, y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f875(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_max_epi64(_mm512_sub_epi64(_mm512_setzero_si512(), x), y); _mm512_storeu_si512(po, r); }
static NOINLINE void f876(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_max_epi64(x, _mm512_sub_epi64(_mm512_setzero_si512(), y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f877(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_max_epi64(_mm512_sub_epi64(_mm512_setzero_si512(), x), _mm512_sub_epi64(_mm512_setzero_si512(), y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f878(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_max_epi64(x, _mm512_sub_epi64(_mm512_setzero_si512(), x)); _mm512_storeu_si512(po, r); }
static NOINLINE void f879(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_max_epi64(_mm512_sub_epi64(_mm512_setzero_si512(), x), x); _mm512_storeu_si512(po, r); }
static NOINLINE void f880(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi64(_mm512_setzero_si512(), _mm512_min_epu64(x, y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f881(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_min_epu64(_mm512_sub_epi64(_mm512_setzero_si512(), x), y); _mm512_storeu_si512(po, r); }
static NOINLINE void f882(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_min_epu64(x, _mm512_sub_epi64(_mm512_setzero_si512(), y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f883(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_min_epu64(_mm512_sub_epi64(_mm512_setzero_si512(), x), _mm512_sub_epi64(_mm512_setzero_si512(), y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f884(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_min_epu64(x, _mm512_sub_epi64(_mm512_setzero_si512(), x)); _mm512_storeu_si512(po, r); }
static NOINLINE void f885(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_min_epu64(_mm512_sub_epi64(_mm512_setzero_si512(), x), x); _mm512_storeu_si512(po, r); }
static NOINLINE void f886(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi64(_mm512_setzero_si512(), _mm512_max_epu64(x, y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f887(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_max_epu64(_mm512_sub_epi64(_mm512_setzero_si512(), x), y); _mm512_storeu_si512(po, r); }
static NOINLINE void f888(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_max_epu64(x, _mm512_sub_epi64(_mm512_setzero_si512(), y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f889(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_max_epu64(_mm512_sub_epi64(_mm512_setzero_si512(), x), _mm512_sub_epi64(_mm512_setzero_si512(), y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f890(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_max_epu64(x, _mm512_sub_epi64(_mm512_setzero_si512(), x)); _mm512_storeu_si512(po, r); }
static NOINLINE void f891(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_max_epu64(_mm512_sub_epi64(_mm512_setzero_si512(), x), x); _mm512_storeu_si512(po, r); }
static NOINLINE void f892(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi64(_mm512_setzero_si512(), _mm512_and_si512(x, y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f893(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_and_si512(_mm512_sub_epi64(_mm512_setzero_si512(), x), y); _mm512_storeu_si512(po, r); }
static NOINLINE void f894(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_and_si512(x, _mm512_sub_epi64(_mm512_setzero_si512(), y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f895(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_and_si512(_mm512_sub_epi64(_mm512_setzero_si512(), x), _mm512_sub_epi64(_mm512_setzero_si512(), y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f896(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_and_si512(x, _mm512_sub_epi64(_mm512_setzero_si512(), x)); _mm512_storeu_si512(po, r); }
static NOINLINE void f897(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_and_si512(_mm512_sub_epi64(_mm512_setzero_si512(), x), x); _mm512_storeu_si512(po, r); }
static NOINLINE void f898(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi64(_mm512_setzero_si512(), _mm512_or_si512(x, y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f899(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_or_si512(_mm512_sub_epi64(_mm512_setzero_si512(), x), y); _mm512_storeu_si512(po, r); }
static NOINLINE void f900(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_or_si512(x, _mm512_sub_epi64(_mm512_setzero_si512(), y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f901(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_or_si512(_mm512_sub_epi64(_mm512_setzero_si512(), x), _mm512_sub_epi64(_mm512_setzero_si512(), y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f902(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_or_si512(x, _mm512_sub_epi64(_mm512_setzero_si512(), x)); _mm512_storeu_si512(po, r); }
static NOINLINE void f903(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_or_si512(_mm512_sub_epi64(_mm512_setzero_si512(), x), x); _mm512_storeu_si512(po, r); }
static NOINLINE void f904(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi64(_mm512_setzero_si512(), _mm512_xor_si512(x, y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f905(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_xor_si512(_mm512_sub_epi64(_mm512_setzero_si512(), x), y); _mm512_storeu_si512(po, r); }
static NOINLINE void f906(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_xor_si512(x, _mm512_sub_epi64(_mm512_setzero_si512(), y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f907(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_xor_si512(_mm512_sub_epi64(_mm512_setzero_si512(), x), _mm512_sub_epi64(_mm512_setzero_si512(), y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f908(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_xor_si512(x, _mm512_sub_epi64(_mm512_setzero_si512(), x)); _mm512_storeu_si512(po, r); }
static NOINLINE void f909(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_xor_si512(_mm512_sub_epi64(_mm512_setzero_si512(), x), x); _mm512_storeu_si512(po, r); }
static NOINLINE void f910(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi64(_mm512_setzero_si512(), _mm512_andnot_si512(x, y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f911(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_andnot_si512(_mm512_sub_epi64(_mm512_setzero_si512(), x), y); _mm512_storeu_si512(po, r); }
static NOINLINE void f912(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_andnot_si512(x, _mm512_sub_epi64(_mm512_setzero_si512(), y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f913(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_andnot_si512(_mm512_sub_epi64(_mm512_setzero_si512(), x), _mm512_sub_epi64(_mm512_setzero_si512(), y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f914(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_andnot_si512(x, _mm512_sub_epi64(_mm512_setzero_si512(), x)); _mm512_storeu_si512(po, r); }
static NOINLINE void f915(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_andnot_si512(_mm512_sub_epi64(_mm512_setzero_si512(), x), x); _mm512_storeu_si512(po, r); }
static NOINLINE void f916(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi64(_mm512_setzero_si512(), _mm512_sllv_epi64(x, y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f917(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sllv_epi64(_mm512_sub_epi64(_mm512_setzero_si512(), x), y); _mm512_storeu_si512(po, r); }
static NOINLINE void f918(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sllv_epi64(x, _mm512_sub_epi64(_mm512_setzero_si512(), y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f919(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sllv_epi64(_mm512_sub_epi64(_mm512_setzero_si512(), x), _mm512_sub_epi64(_mm512_setzero_si512(), y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f920(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sllv_epi64(x, _mm512_sub_epi64(_mm512_setzero_si512(), x)); _mm512_storeu_si512(po, r); }
static NOINLINE void f921(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sllv_epi64(_mm512_sub_epi64(_mm512_setzero_si512(), x), x); _mm512_storeu_si512(po, r); }
static NOINLINE void f922(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi64(_mm512_setzero_si512(), _mm512_srlv_epi64(x, y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f923(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srlv_epi64(_mm512_sub_epi64(_mm512_setzero_si512(), x), y); _mm512_storeu_si512(po, r); }
static NOINLINE void f924(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srlv_epi64(x, _mm512_sub_epi64(_mm512_setzero_si512(), y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f925(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srlv_epi64(_mm512_sub_epi64(_mm512_setzero_si512(), x), _mm512_sub_epi64(_mm512_setzero_si512(), y)); _mm512_storeu_si512(po, r); }
static NOINLINE void f926(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srlv_epi64(x, _mm512_sub_epi64(_mm512_setzero_si512(), x)); _mm512_storeu_si512(po, r); }
static NOINLINE void f927(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srlv_epi64(_mm512_sub_epi64(_mm512_setzero_si512(), x), x); _mm512_storeu_si512(po, r); }
static NOINLINE void f928(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_xor_si512(_mm512_add_epi8(x, y), _mm512_set1_epi8((char)0xffu)); _mm512_storeu_si512(po, r); }
static NOINLINE void f929(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_add_epi8(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), y); _mm512_storeu_si512(po, r); }
static NOINLINE void f930(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_add_epi8(x, _mm512_xor_si512(y, _mm512_set1_epi8((char)0xffu))); _mm512_storeu_si512(po, r); }
static NOINLINE void f931(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_add_epi8(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), _mm512_xor_si512(y, _mm512_set1_epi8((char)0xffu))); _mm512_storeu_si512(po, r); }
static NOINLINE void f932(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_add_epi8(x, _mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu))); _mm512_storeu_si512(po, r); }
static NOINLINE void f933(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_add_epi8(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), x); _mm512_storeu_si512(po, r); }
static NOINLINE void f934(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_xor_si512(_mm512_sub_epi8(x, y), _mm512_set1_epi8((char)0xffu)); _mm512_storeu_si512(po, r); }
static NOINLINE void f935(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi8(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), y); _mm512_storeu_si512(po, r); }
static NOINLINE void f936(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi8(x, _mm512_xor_si512(y, _mm512_set1_epi8((char)0xffu))); _mm512_storeu_si512(po, r); }
static NOINLINE void f937(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi8(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), _mm512_xor_si512(y, _mm512_set1_epi8((char)0xffu))); _mm512_storeu_si512(po, r); }
static NOINLINE void f938(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi8(x, _mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu))); _mm512_storeu_si512(po, r); }
static NOINLINE void f939(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi8(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), x); _mm512_storeu_si512(po, r); }
static NOINLINE void f940(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_xor_si512(_mm512_add_epi16(x, y), _mm512_set1_epi8((char)0xffu)); _mm512_storeu_si512(po, r); }
static NOINLINE void f941(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_add_epi16(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), y); _mm512_storeu_si512(po, r); }
static NOINLINE void f942(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_add_epi16(x, _mm512_xor_si512(y, _mm512_set1_epi8((char)0xffu))); _mm512_storeu_si512(po, r); }
static NOINLINE void f943(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_add_epi16(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), _mm512_xor_si512(y, _mm512_set1_epi8((char)0xffu))); _mm512_storeu_si512(po, r); }
static NOINLINE void f944(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_add_epi16(x, _mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu))); _mm512_storeu_si512(po, r); }
static NOINLINE void f945(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_add_epi16(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), x); _mm512_storeu_si512(po, r); }
static NOINLINE void f946(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_xor_si512(_mm512_sub_epi16(x, y), _mm512_set1_epi8((char)0xffu)); _mm512_storeu_si512(po, r); }
static NOINLINE void f947(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi16(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), y); _mm512_storeu_si512(po, r); }
static NOINLINE void f948(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi16(x, _mm512_xor_si512(y, _mm512_set1_epi8((char)0xffu))); _mm512_storeu_si512(po, r); }
static NOINLINE void f949(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi16(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), _mm512_xor_si512(y, _mm512_set1_epi8((char)0xffu))); _mm512_storeu_si512(po, r); }
static NOINLINE void f950(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi16(x, _mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu))); _mm512_storeu_si512(po, r); }
static NOINLINE void f951(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi16(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), x); _mm512_storeu_si512(po, r); }
static NOINLINE void f952(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_xor_si512(_mm512_add_epi32(x, y), _mm512_set1_epi8((char)0xffu)); _mm512_storeu_si512(po, r); }
static NOINLINE void f953(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_add_epi32(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), y); _mm512_storeu_si512(po, r); }
static NOINLINE void f954(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_add_epi32(x, _mm512_xor_si512(y, _mm512_set1_epi8((char)0xffu))); _mm512_storeu_si512(po, r); }
static NOINLINE void f955(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_add_epi32(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), _mm512_xor_si512(y, _mm512_set1_epi8((char)0xffu))); _mm512_storeu_si512(po, r); }
static NOINLINE void f956(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_add_epi32(x, _mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu))); _mm512_storeu_si512(po, r); }
static NOINLINE void f957(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_add_epi32(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), x); _mm512_storeu_si512(po, r); }
static NOINLINE void f958(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_xor_si512(_mm512_sub_epi32(x, y), _mm512_set1_epi8((char)0xffu)); _mm512_storeu_si512(po, r); }
static NOINLINE void f959(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi32(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), y); _mm512_storeu_si512(po, r); }
static NOINLINE void f960(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi32(x, _mm512_xor_si512(y, _mm512_set1_epi8((char)0xffu))); _mm512_storeu_si512(po, r); }
static NOINLINE void f961(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi32(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), _mm512_xor_si512(y, _mm512_set1_epi8((char)0xffu))); _mm512_storeu_si512(po, r); }
static NOINLINE void f962(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi32(x, _mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu))); _mm512_storeu_si512(po, r); }
static NOINLINE void f963(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi32(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), x); _mm512_storeu_si512(po, r); }
static NOINLINE void f964(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_xor_si512(_mm512_add_epi64(x, y), _mm512_set1_epi8((char)0xffu)); _mm512_storeu_si512(po, r); }
static NOINLINE void f965(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_add_epi64(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), y); _mm512_storeu_si512(po, r); }
static NOINLINE void f966(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_add_epi64(x, _mm512_xor_si512(y, _mm512_set1_epi8((char)0xffu))); _mm512_storeu_si512(po, r); }
static NOINLINE void f967(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_add_epi64(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), _mm512_xor_si512(y, _mm512_set1_epi8((char)0xffu))); _mm512_storeu_si512(po, r); }
static NOINLINE void f968(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_add_epi64(x, _mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu))); _mm512_storeu_si512(po, r); }
static NOINLINE void f969(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_add_epi64(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), x); _mm512_storeu_si512(po, r); }
static NOINLINE void f970(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_xor_si512(_mm512_sub_epi64(x, y), _mm512_set1_epi8((char)0xffu)); _mm512_storeu_si512(po, r); }
static NOINLINE void f971(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi64(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), y); _mm512_storeu_si512(po, r); }
static NOINLINE void f972(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi64(x, _mm512_xor_si512(y, _mm512_set1_epi8((char)0xffu))); _mm512_storeu_si512(po, r); }
static NOINLINE void f973(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi64(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), _mm512_xor_si512(y, _mm512_set1_epi8((char)0xffu))); _mm512_storeu_si512(po, r); }
static NOINLINE void f974(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi64(x, _mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu))); _mm512_storeu_si512(po, r); }
static NOINLINE void f975(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi64(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), x); _mm512_storeu_si512(po, r); }
static NOINLINE void f976(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_xor_si512(_mm512_adds_epi8(x, y), _mm512_set1_epi8((char)0xffu)); _mm512_storeu_si512(po, r); }
static NOINLINE void f977(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_adds_epi8(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), y); _mm512_storeu_si512(po, r); }
static NOINLINE void f978(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_adds_epi8(x, _mm512_xor_si512(y, _mm512_set1_epi8((char)0xffu))); _mm512_storeu_si512(po, r); }
static NOINLINE void f979(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_adds_epi8(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), _mm512_xor_si512(y, _mm512_set1_epi8((char)0xffu))); _mm512_storeu_si512(po, r); }
static NOINLINE void f980(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_adds_epi8(x, _mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu))); _mm512_storeu_si512(po, r); }
static NOINLINE void f981(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_adds_epi8(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), x); _mm512_storeu_si512(po, r); }
static NOINLINE void f982(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_xor_si512(_mm512_subs_epi8(x, y), _mm512_set1_epi8((char)0xffu)); _mm512_storeu_si512(po, r); }
static NOINLINE void f983(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_subs_epi8(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), y); _mm512_storeu_si512(po, r); }
static NOINLINE void f984(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_subs_epi8(x, _mm512_xor_si512(y, _mm512_set1_epi8((char)0xffu))); _mm512_storeu_si512(po, r); }
static NOINLINE void f985(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_subs_epi8(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), _mm512_xor_si512(y, _mm512_set1_epi8((char)0xffu))); _mm512_storeu_si512(po, r); }
static NOINLINE void f986(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_subs_epi8(x, _mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu))); _mm512_storeu_si512(po, r); }
static NOINLINE void f987(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_subs_epi8(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), x); _mm512_storeu_si512(po, r); }
static NOINLINE void f988(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_xor_si512(_mm512_adds_epu8(x, y), _mm512_set1_epi8((char)0xffu)); _mm512_storeu_si512(po, r); }
static NOINLINE void f989(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_adds_epu8(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), y); _mm512_storeu_si512(po, r); }
static NOINLINE void f990(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_adds_epu8(x, _mm512_xor_si512(y, _mm512_set1_epi8((char)0xffu))); _mm512_storeu_si512(po, r); }
static NOINLINE void f991(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_adds_epu8(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), _mm512_xor_si512(y, _mm512_set1_epi8((char)0xffu))); _mm512_storeu_si512(po, r); }
static NOINLINE void f992(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_adds_epu8(x, _mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu))); _mm512_storeu_si512(po, r); }
static NOINLINE void f993(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_adds_epu8(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), x); _mm512_storeu_si512(po, r); }
static NOINLINE void f994(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_xor_si512(_mm512_subs_epu8(x, y), _mm512_set1_epi8((char)0xffu)); _mm512_storeu_si512(po, r); }
static NOINLINE void f995(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_subs_epu8(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), y); _mm512_storeu_si512(po, r); }
static NOINLINE void f996(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_subs_epu8(x, _mm512_xor_si512(y, _mm512_set1_epi8((char)0xffu))); _mm512_storeu_si512(po, r); }
static NOINLINE void f997(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_subs_epu8(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), _mm512_xor_si512(y, _mm512_set1_epi8((char)0xffu))); _mm512_storeu_si512(po, r); }
static NOINLINE void f998(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_subs_epu8(x, _mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu))); _mm512_storeu_si512(po, r); }
static NOINLINE void f999(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_subs_epu8(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), x); _mm512_storeu_si512(po, r); }
static NOINLINE void f1000(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_xor_si512(_mm512_avg_epu8(x, y), _mm512_set1_epi8((char)0xffu)); _mm512_storeu_si512(po, r); }
static NOINLINE void f1001(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_avg_epu8(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), y); _mm512_storeu_si512(po, r); }
static NOINLINE void f1002(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_avg_epu8(x, _mm512_xor_si512(y, _mm512_set1_epi8((char)0xffu))); _mm512_storeu_si512(po, r); }
static NOINLINE void f1003(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_avg_epu8(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), _mm512_xor_si512(y, _mm512_set1_epi8((char)0xffu))); _mm512_storeu_si512(po, r); }
static NOINLINE void f1004(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_avg_epu8(x, _mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu))); _mm512_storeu_si512(po, r); }
static NOINLINE void f1005(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_avg_epu8(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), x); _mm512_storeu_si512(po, r); }
static NOINLINE void f1006(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_xor_si512(_mm512_adds_epi16(x, y), _mm512_set1_epi8((char)0xffu)); _mm512_storeu_si512(po, r); }
static NOINLINE void f1007(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_adds_epi16(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), y); _mm512_storeu_si512(po, r); }
static NOINLINE void f1008(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_adds_epi16(x, _mm512_xor_si512(y, _mm512_set1_epi8((char)0xffu))); _mm512_storeu_si512(po, r); }
static NOINLINE void f1009(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_adds_epi16(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), _mm512_xor_si512(y, _mm512_set1_epi8((char)0xffu))); _mm512_storeu_si512(po, r); }
static NOINLINE void f1010(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_adds_epi16(x, _mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu))); _mm512_storeu_si512(po, r); }
static NOINLINE void f1011(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_adds_epi16(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), x); _mm512_storeu_si512(po, r); }
static NOINLINE void f1012(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_xor_si512(_mm512_subs_epi16(x, y), _mm512_set1_epi8((char)0xffu)); _mm512_storeu_si512(po, r); }
static NOINLINE void f1013(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_subs_epi16(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), y); _mm512_storeu_si512(po, r); }
static NOINLINE void f1014(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_subs_epi16(x, _mm512_xor_si512(y, _mm512_set1_epi8((char)0xffu))); _mm512_storeu_si512(po, r); }
static NOINLINE void f1015(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_subs_epi16(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), _mm512_xor_si512(y, _mm512_set1_epi8((char)0xffu))); _mm512_storeu_si512(po, r); }
static NOINLINE void f1016(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_subs_epi16(x, _mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu))); _mm512_storeu_si512(po, r); }
static NOINLINE void f1017(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_subs_epi16(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), x); _mm512_storeu_si512(po, r); }
static NOINLINE void f1018(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_xor_si512(_mm512_adds_epu16(x, y), _mm512_set1_epi8((char)0xffu)); _mm512_storeu_si512(po, r); }
static NOINLINE void f1019(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_adds_epu16(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), y); _mm512_storeu_si512(po, r); }
static NOINLINE void f1020(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_adds_epu16(x, _mm512_xor_si512(y, _mm512_set1_epi8((char)0xffu))); _mm512_storeu_si512(po, r); }
static NOINLINE void f1021(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_adds_epu16(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), _mm512_xor_si512(y, _mm512_set1_epi8((char)0xffu))); _mm512_storeu_si512(po, r); }
static NOINLINE void f1022(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_adds_epu16(x, _mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu))); _mm512_storeu_si512(po, r); }
static NOINLINE void f1023(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_adds_epu16(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), x); _mm512_storeu_si512(po, r); }
static NOINLINE void f1024(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_xor_si512(_mm512_subs_epu16(x, y), _mm512_set1_epi8((char)0xffu)); _mm512_storeu_si512(po, r); }
static NOINLINE void f1025(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_subs_epu16(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), y); _mm512_storeu_si512(po, r); }
static NOINLINE void f1026(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_subs_epu16(x, _mm512_xor_si512(y, _mm512_set1_epi8((char)0xffu))); _mm512_storeu_si512(po, r); }
static NOINLINE void f1027(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_subs_epu16(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), _mm512_xor_si512(y, _mm512_set1_epi8((char)0xffu))); _mm512_storeu_si512(po, r); }
static NOINLINE void f1028(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_subs_epu16(x, _mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu))); _mm512_storeu_si512(po, r); }
static NOINLINE void f1029(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_subs_epu16(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), x); _mm512_storeu_si512(po, r); }
static NOINLINE void f1030(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_xor_si512(_mm512_avg_epu16(x, y), _mm512_set1_epi8((char)0xffu)); _mm512_storeu_si512(po, r); }
static NOINLINE void f1031(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_avg_epu16(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), y); _mm512_storeu_si512(po, r); }
static NOINLINE void f1032(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_avg_epu16(x, _mm512_xor_si512(y, _mm512_set1_epi8((char)0xffu))); _mm512_storeu_si512(po, r); }
static NOINLINE void f1033(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_avg_epu16(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), _mm512_xor_si512(y, _mm512_set1_epi8((char)0xffu))); _mm512_storeu_si512(po, r); }
static NOINLINE void f1034(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_avg_epu16(x, _mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu))); _mm512_storeu_si512(po, r); }
static NOINLINE void f1035(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_avg_epu16(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), x); _mm512_storeu_si512(po, r); }
static NOINLINE void f1036(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_xor_si512(_mm512_min_epi8(x, y), _mm512_set1_epi8((char)0xffu)); _mm512_storeu_si512(po, r); }
static NOINLINE void f1037(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_min_epi8(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), y); _mm512_storeu_si512(po, r); }
static NOINLINE void f1038(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_min_epi8(x, _mm512_xor_si512(y, _mm512_set1_epi8((char)0xffu))); _mm512_storeu_si512(po, r); }
static NOINLINE void f1039(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_min_epi8(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), _mm512_xor_si512(y, _mm512_set1_epi8((char)0xffu))); _mm512_storeu_si512(po, r); }
static NOINLINE void f1040(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_min_epi8(x, _mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu))); _mm512_storeu_si512(po, r); }
static NOINLINE void f1041(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_min_epi8(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), x); _mm512_storeu_si512(po, r); }
static NOINLINE void f1042(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_xor_si512(_mm512_max_epi8(x, y), _mm512_set1_epi8((char)0xffu)); _mm512_storeu_si512(po, r); }
static NOINLINE void f1043(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_max_epi8(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), y); _mm512_storeu_si512(po, r); }
static NOINLINE void f1044(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_max_epi8(x, _mm512_xor_si512(y, _mm512_set1_epi8((char)0xffu))); _mm512_storeu_si512(po, r); }
static NOINLINE void f1045(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_max_epi8(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), _mm512_xor_si512(y, _mm512_set1_epi8((char)0xffu))); _mm512_storeu_si512(po, r); }
static NOINLINE void f1046(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_max_epi8(x, _mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu))); _mm512_storeu_si512(po, r); }
static NOINLINE void f1047(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_max_epi8(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), x); _mm512_storeu_si512(po, r); }
static NOINLINE void f1048(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_xor_si512(_mm512_min_epu8(x, y), _mm512_set1_epi8((char)0xffu)); _mm512_storeu_si512(po, r); }
static NOINLINE void f1049(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_min_epu8(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), y); _mm512_storeu_si512(po, r); }
static NOINLINE void f1050(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_min_epu8(x, _mm512_xor_si512(y, _mm512_set1_epi8((char)0xffu))); _mm512_storeu_si512(po, r); }
static NOINLINE void f1051(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_min_epu8(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), _mm512_xor_si512(y, _mm512_set1_epi8((char)0xffu))); _mm512_storeu_si512(po, r); }
static NOINLINE void f1052(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_min_epu8(x, _mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu))); _mm512_storeu_si512(po, r); }
static NOINLINE void f1053(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_min_epu8(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), x); _mm512_storeu_si512(po, r); }
static NOINLINE void f1054(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_xor_si512(_mm512_max_epu8(x, y), _mm512_set1_epi8((char)0xffu)); _mm512_storeu_si512(po, r); }
static NOINLINE void f1055(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_max_epu8(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), y); _mm512_storeu_si512(po, r); }
static NOINLINE void f1056(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_max_epu8(x, _mm512_xor_si512(y, _mm512_set1_epi8((char)0xffu))); _mm512_storeu_si512(po, r); }
static NOINLINE void f1057(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_max_epu8(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), _mm512_xor_si512(y, _mm512_set1_epi8((char)0xffu))); _mm512_storeu_si512(po, r); }
static NOINLINE void f1058(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_max_epu8(x, _mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu))); _mm512_storeu_si512(po, r); }
static NOINLINE void f1059(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_max_epu8(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), x); _mm512_storeu_si512(po, r); }
static NOINLINE void f1060(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_xor_si512(_mm512_min_epi16(x, y), _mm512_set1_epi8((char)0xffu)); _mm512_storeu_si512(po, r); }
static NOINLINE void f1061(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_min_epi16(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), y); _mm512_storeu_si512(po, r); }
static NOINLINE void f1062(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_min_epi16(x, _mm512_xor_si512(y, _mm512_set1_epi8((char)0xffu))); _mm512_storeu_si512(po, r); }
static NOINLINE void f1063(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_min_epi16(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), _mm512_xor_si512(y, _mm512_set1_epi8((char)0xffu))); _mm512_storeu_si512(po, r); }
static NOINLINE void f1064(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_min_epi16(x, _mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu))); _mm512_storeu_si512(po, r); }
static NOINLINE void f1065(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_min_epi16(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), x); _mm512_storeu_si512(po, r); }
static NOINLINE void f1066(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_xor_si512(_mm512_max_epi16(x, y), _mm512_set1_epi8((char)0xffu)); _mm512_storeu_si512(po, r); }
static NOINLINE void f1067(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_max_epi16(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), y); _mm512_storeu_si512(po, r); }
static NOINLINE void f1068(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_max_epi16(x, _mm512_xor_si512(y, _mm512_set1_epi8((char)0xffu))); _mm512_storeu_si512(po, r); }
static NOINLINE void f1069(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_max_epi16(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), _mm512_xor_si512(y, _mm512_set1_epi8((char)0xffu))); _mm512_storeu_si512(po, r); }
static NOINLINE void f1070(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_max_epi16(x, _mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu))); _mm512_storeu_si512(po, r); }
static NOINLINE void f1071(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_max_epi16(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), x); _mm512_storeu_si512(po, r); }
static NOINLINE void f1072(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_xor_si512(_mm512_min_epu16(x, y), _mm512_set1_epi8((char)0xffu)); _mm512_storeu_si512(po, r); }
static NOINLINE void f1073(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_min_epu16(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), y); _mm512_storeu_si512(po, r); }
static NOINLINE void f1074(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_min_epu16(x, _mm512_xor_si512(y, _mm512_set1_epi8((char)0xffu))); _mm512_storeu_si512(po, r); }
static NOINLINE void f1075(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_min_epu16(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), _mm512_xor_si512(y, _mm512_set1_epi8((char)0xffu))); _mm512_storeu_si512(po, r); }
static NOINLINE void f1076(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_min_epu16(x, _mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu))); _mm512_storeu_si512(po, r); }
static NOINLINE void f1077(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_min_epu16(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), x); _mm512_storeu_si512(po, r); }
static NOINLINE void f1078(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_xor_si512(_mm512_max_epu16(x, y), _mm512_set1_epi8((char)0xffu)); _mm512_storeu_si512(po, r); }
static NOINLINE void f1079(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_max_epu16(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), y); _mm512_storeu_si512(po, r); }
static NOINLINE void f1080(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_max_epu16(x, _mm512_xor_si512(y, _mm512_set1_epi8((char)0xffu))); _mm512_storeu_si512(po, r); }
static NOINLINE void f1081(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_max_epu16(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), _mm512_xor_si512(y, _mm512_set1_epi8((char)0xffu))); _mm512_storeu_si512(po, r); }
static NOINLINE void f1082(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_max_epu16(x, _mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu))); _mm512_storeu_si512(po, r); }
static NOINLINE void f1083(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_max_epu16(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), x); _mm512_storeu_si512(po, r); }
static NOINLINE void f1084(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_xor_si512(_mm512_min_epi32(x, y), _mm512_set1_epi8((char)0xffu)); _mm512_storeu_si512(po, r); }
static NOINLINE void f1085(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_min_epi32(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), y); _mm512_storeu_si512(po, r); }
static NOINLINE void f1086(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_min_epi32(x, _mm512_xor_si512(y, _mm512_set1_epi8((char)0xffu))); _mm512_storeu_si512(po, r); }
static NOINLINE void f1087(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_min_epi32(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), _mm512_xor_si512(y, _mm512_set1_epi8((char)0xffu))); _mm512_storeu_si512(po, r); }
static NOINLINE void f1088(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_min_epi32(x, _mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu))); _mm512_storeu_si512(po, r); }
static NOINLINE void f1089(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_min_epi32(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), x); _mm512_storeu_si512(po, r); }
static NOINLINE void f1090(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_xor_si512(_mm512_max_epi32(x, y), _mm512_set1_epi8((char)0xffu)); _mm512_storeu_si512(po, r); }
static NOINLINE void f1091(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_max_epi32(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), y); _mm512_storeu_si512(po, r); }
static NOINLINE void f1092(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_max_epi32(x, _mm512_xor_si512(y, _mm512_set1_epi8((char)0xffu))); _mm512_storeu_si512(po, r); }
static NOINLINE void f1093(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_max_epi32(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), _mm512_xor_si512(y, _mm512_set1_epi8((char)0xffu))); _mm512_storeu_si512(po, r); }
static NOINLINE void f1094(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_max_epi32(x, _mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu))); _mm512_storeu_si512(po, r); }
static NOINLINE void f1095(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_max_epi32(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), x); _mm512_storeu_si512(po, r); }
static NOINLINE void f1096(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_xor_si512(_mm512_min_epu32(x, y), _mm512_set1_epi8((char)0xffu)); _mm512_storeu_si512(po, r); }
static NOINLINE void f1097(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_min_epu32(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), y); _mm512_storeu_si512(po, r); }
static NOINLINE void f1098(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_min_epu32(x, _mm512_xor_si512(y, _mm512_set1_epi8((char)0xffu))); _mm512_storeu_si512(po, r); }
static NOINLINE void f1099(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_min_epu32(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), _mm512_xor_si512(y, _mm512_set1_epi8((char)0xffu))); _mm512_storeu_si512(po, r); }
static NOINLINE void f1100(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_min_epu32(x, _mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu))); _mm512_storeu_si512(po, r); }
static NOINLINE void f1101(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_min_epu32(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), x); _mm512_storeu_si512(po, r); }
static NOINLINE void f1102(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_xor_si512(_mm512_max_epu32(x, y), _mm512_set1_epi8((char)0xffu)); _mm512_storeu_si512(po, r); }
static NOINLINE void f1103(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_max_epu32(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), y); _mm512_storeu_si512(po, r); }
static NOINLINE void f1104(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_max_epu32(x, _mm512_xor_si512(y, _mm512_set1_epi8((char)0xffu))); _mm512_storeu_si512(po, r); }
static NOINLINE void f1105(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_max_epu32(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), _mm512_xor_si512(y, _mm512_set1_epi8((char)0xffu))); _mm512_storeu_si512(po, r); }
static NOINLINE void f1106(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_max_epu32(x, _mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu))); _mm512_storeu_si512(po, r); }
static NOINLINE void f1107(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_max_epu32(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), x); _mm512_storeu_si512(po, r); }
static NOINLINE void f1108(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_xor_si512(_mm512_min_epi64(x, y), _mm512_set1_epi8((char)0xffu)); _mm512_storeu_si512(po, r); }
static NOINLINE void f1109(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_min_epi64(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), y); _mm512_storeu_si512(po, r); }
static NOINLINE void f1110(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_min_epi64(x, _mm512_xor_si512(y, _mm512_set1_epi8((char)0xffu))); _mm512_storeu_si512(po, r); }
static NOINLINE void f1111(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_min_epi64(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), _mm512_xor_si512(y, _mm512_set1_epi8((char)0xffu))); _mm512_storeu_si512(po, r); }
static NOINLINE void f1112(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_min_epi64(x, _mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu))); _mm512_storeu_si512(po, r); }
static NOINLINE void f1113(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_min_epi64(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), x); _mm512_storeu_si512(po, r); }
static NOINLINE void f1114(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_xor_si512(_mm512_max_epi64(x, y), _mm512_set1_epi8((char)0xffu)); _mm512_storeu_si512(po, r); }
static NOINLINE void f1115(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_max_epi64(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), y); _mm512_storeu_si512(po, r); }
static NOINLINE void f1116(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_max_epi64(x, _mm512_xor_si512(y, _mm512_set1_epi8((char)0xffu))); _mm512_storeu_si512(po, r); }
static NOINLINE void f1117(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_max_epi64(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), _mm512_xor_si512(y, _mm512_set1_epi8((char)0xffu))); _mm512_storeu_si512(po, r); }
static NOINLINE void f1118(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_max_epi64(x, _mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu))); _mm512_storeu_si512(po, r); }
static NOINLINE void f1119(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_max_epi64(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), x); _mm512_storeu_si512(po, r); }
static NOINLINE void f1120(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_xor_si512(_mm512_min_epu64(x, y), _mm512_set1_epi8((char)0xffu)); _mm512_storeu_si512(po, r); }
static NOINLINE void f1121(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_min_epu64(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), y); _mm512_storeu_si512(po, r); }
static NOINLINE void f1122(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_min_epu64(x, _mm512_xor_si512(y, _mm512_set1_epi8((char)0xffu))); _mm512_storeu_si512(po, r); }
static NOINLINE void f1123(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_min_epu64(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), _mm512_xor_si512(y, _mm512_set1_epi8((char)0xffu))); _mm512_storeu_si512(po, r); }
static NOINLINE void f1124(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_min_epu64(x, _mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu))); _mm512_storeu_si512(po, r); }
static NOINLINE void f1125(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_min_epu64(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), x); _mm512_storeu_si512(po, r); }
static NOINLINE void f1126(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_xor_si512(_mm512_max_epu64(x, y), _mm512_set1_epi8((char)0xffu)); _mm512_storeu_si512(po, r); }
static NOINLINE void f1127(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_max_epu64(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), y); _mm512_storeu_si512(po, r); }
static NOINLINE void f1128(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_max_epu64(x, _mm512_xor_si512(y, _mm512_set1_epi8((char)0xffu))); _mm512_storeu_si512(po, r); }
static NOINLINE void f1129(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_max_epu64(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), _mm512_xor_si512(y, _mm512_set1_epi8((char)0xffu))); _mm512_storeu_si512(po, r); }
static NOINLINE void f1130(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_max_epu64(x, _mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu))); _mm512_storeu_si512(po, r); }
static NOINLINE void f1131(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_max_epu64(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), x); _mm512_storeu_si512(po, r); }
static NOINLINE void f1132(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_xor_si512(_mm512_and_si512(x, y), _mm512_set1_epi8((char)0xffu)); _mm512_storeu_si512(po, r); }
static NOINLINE void f1133(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_and_si512(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), y); _mm512_storeu_si512(po, r); }
static NOINLINE void f1134(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_and_si512(x, _mm512_xor_si512(y, _mm512_set1_epi8((char)0xffu))); _mm512_storeu_si512(po, r); }
static NOINLINE void f1135(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_and_si512(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), _mm512_xor_si512(y, _mm512_set1_epi8((char)0xffu))); _mm512_storeu_si512(po, r); }
static NOINLINE void f1136(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_and_si512(x, _mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu))); _mm512_storeu_si512(po, r); }
static NOINLINE void f1137(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_and_si512(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), x); _mm512_storeu_si512(po, r); }
static NOINLINE void f1138(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_xor_si512(_mm512_or_si512(x, y), _mm512_set1_epi8((char)0xffu)); _mm512_storeu_si512(po, r); }
static NOINLINE void f1139(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_or_si512(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), y); _mm512_storeu_si512(po, r); }
static NOINLINE void f1140(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_or_si512(x, _mm512_xor_si512(y, _mm512_set1_epi8((char)0xffu))); _mm512_storeu_si512(po, r); }
static NOINLINE void f1141(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_or_si512(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), _mm512_xor_si512(y, _mm512_set1_epi8((char)0xffu))); _mm512_storeu_si512(po, r); }
static NOINLINE void f1142(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_or_si512(x, _mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu))); _mm512_storeu_si512(po, r); }
static NOINLINE void f1143(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_or_si512(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), x); _mm512_storeu_si512(po, r); }
static NOINLINE void f1144(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_xor_si512(_mm512_xor_si512(x, y), _mm512_set1_epi8((char)0xffu)); _mm512_storeu_si512(po, r); }
static NOINLINE void f1145(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_xor_si512(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), y); _mm512_storeu_si512(po, r); }
static NOINLINE void f1146(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_xor_si512(x, _mm512_xor_si512(y, _mm512_set1_epi8((char)0xffu))); _mm512_storeu_si512(po, r); }
static NOINLINE void f1147(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_xor_si512(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), _mm512_xor_si512(y, _mm512_set1_epi8((char)0xffu))); _mm512_storeu_si512(po, r); }
static NOINLINE void f1148(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_xor_si512(x, _mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu))); _mm512_storeu_si512(po, r); }
static NOINLINE void f1149(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_xor_si512(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), x); _mm512_storeu_si512(po, r); }
static NOINLINE void f1150(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_xor_si512(_mm512_andnot_si512(x, y), _mm512_set1_epi8((char)0xffu)); _mm512_storeu_si512(po, r); }
static NOINLINE void f1151(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_andnot_si512(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), y); _mm512_storeu_si512(po, r); }
static NOINLINE void f1152(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_andnot_si512(x, _mm512_xor_si512(y, _mm512_set1_epi8((char)0xffu))); _mm512_storeu_si512(po, r); }
static NOINLINE void f1153(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_andnot_si512(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), _mm512_xor_si512(y, _mm512_set1_epi8((char)0xffu))); _mm512_storeu_si512(po, r); }
static NOINLINE void f1154(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_andnot_si512(x, _mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu))); _mm512_storeu_si512(po, r); }
static NOINLINE void f1155(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_andnot_si512(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), x); _mm512_storeu_si512(po, r); }
static NOINLINE void f1156(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_xor_si512(_mm512_mullo_epi16(x, y), _mm512_set1_epi8((char)0xffu)); _mm512_storeu_si512(po, r); }
static NOINLINE void f1157(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_mullo_epi16(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), y); _mm512_storeu_si512(po, r); }
static NOINLINE void f1158(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_mullo_epi16(x, _mm512_xor_si512(y, _mm512_set1_epi8((char)0xffu))); _mm512_storeu_si512(po, r); }
static NOINLINE void f1159(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_mullo_epi16(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), _mm512_xor_si512(y, _mm512_set1_epi8((char)0xffu))); _mm512_storeu_si512(po, r); }
static NOINLINE void f1160(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_mullo_epi16(x, _mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu))); _mm512_storeu_si512(po, r); }
static NOINLINE void f1161(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_mullo_epi16(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), x); _mm512_storeu_si512(po, r); }
static NOINLINE void f1162(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_xor_si512(_mm512_mullo_epi32(x, y), _mm512_set1_epi8((char)0xffu)); _mm512_storeu_si512(po, r); }
static NOINLINE void f1163(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_mullo_epi32(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), y); _mm512_storeu_si512(po, r); }
static NOINLINE void f1164(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_mullo_epi32(x, _mm512_xor_si512(y, _mm512_set1_epi8((char)0xffu))); _mm512_storeu_si512(po, r); }
static NOINLINE void f1165(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_mullo_epi32(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), _mm512_xor_si512(y, _mm512_set1_epi8((char)0xffu))); _mm512_storeu_si512(po, r); }
static NOINLINE void f1166(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_mullo_epi32(x, _mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu))); _mm512_storeu_si512(po, r); }
static NOINLINE void f1167(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_mullo_epi32(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), x); _mm512_storeu_si512(po, r); }
static NOINLINE void f1168(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_xor_si512(_mm512_mulhi_epi16(x, y), _mm512_set1_epi8((char)0xffu)); _mm512_storeu_si512(po, r); }
static NOINLINE void f1169(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_mulhi_epi16(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), y); _mm512_storeu_si512(po, r); }
static NOINLINE void f1170(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_mulhi_epi16(x, _mm512_xor_si512(y, _mm512_set1_epi8((char)0xffu))); _mm512_storeu_si512(po, r); }
static NOINLINE void f1171(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_mulhi_epi16(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), _mm512_xor_si512(y, _mm512_set1_epi8((char)0xffu))); _mm512_storeu_si512(po, r); }
static NOINLINE void f1172(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_mulhi_epi16(x, _mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu))); _mm512_storeu_si512(po, r); }
static NOINLINE void f1173(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_mulhi_epi16(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), x); _mm512_storeu_si512(po, r); }
static NOINLINE void f1174(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_xor_si512(_mm512_mulhi_epu16(x, y), _mm512_set1_epi8((char)0xffu)); _mm512_storeu_si512(po, r); }
static NOINLINE void f1175(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_mulhi_epu16(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), y); _mm512_storeu_si512(po, r); }
static NOINLINE void f1176(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_mulhi_epu16(x, _mm512_xor_si512(y, _mm512_set1_epi8((char)0xffu))); _mm512_storeu_si512(po, r); }
static NOINLINE void f1177(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_mulhi_epu16(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), _mm512_xor_si512(y, _mm512_set1_epi8((char)0xffu))); _mm512_storeu_si512(po, r); }
static NOINLINE void f1178(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_mulhi_epu16(x, _mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu))); _mm512_storeu_si512(po, r); }
static NOINLINE void f1179(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_mulhi_epu16(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), x); _mm512_storeu_si512(po, r); }
static NOINLINE void f1180(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_xor_si512(_mm512_sllv_epi32(x, y), _mm512_set1_epi8((char)0xffu)); _mm512_storeu_si512(po, r); }
static NOINLINE void f1181(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sllv_epi32(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), y); _mm512_storeu_si512(po, r); }
static NOINLINE void f1182(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sllv_epi32(x, _mm512_xor_si512(y, _mm512_set1_epi8((char)0xffu))); _mm512_storeu_si512(po, r); }
static NOINLINE void f1183(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sllv_epi32(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), _mm512_xor_si512(y, _mm512_set1_epi8((char)0xffu))); _mm512_storeu_si512(po, r); }
static NOINLINE void f1184(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sllv_epi32(x, _mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu))); _mm512_storeu_si512(po, r); }
static NOINLINE void f1185(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sllv_epi32(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), x); _mm512_storeu_si512(po, r); }
static NOINLINE void f1186(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_xor_si512(_mm512_srlv_epi32(x, y), _mm512_set1_epi8((char)0xffu)); _mm512_storeu_si512(po, r); }
static NOINLINE void f1187(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srlv_epi32(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), y); _mm512_storeu_si512(po, r); }
static NOINLINE void f1188(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srlv_epi32(x, _mm512_xor_si512(y, _mm512_set1_epi8((char)0xffu))); _mm512_storeu_si512(po, r); }
static NOINLINE void f1189(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srlv_epi32(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), _mm512_xor_si512(y, _mm512_set1_epi8((char)0xffu))); _mm512_storeu_si512(po, r); }
static NOINLINE void f1190(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srlv_epi32(x, _mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu))); _mm512_storeu_si512(po, r); }
static NOINLINE void f1191(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srlv_epi32(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), x); _mm512_storeu_si512(po, r); }
static NOINLINE void f1192(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_xor_si512(_mm512_sllv_epi64(x, y), _mm512_set1_epi8((char)0xffu)); _mm512_storeu_si512(po, r); }
static NOINLINE void f1193(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sllv_epi64(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), y); _mm512_storeu_si512(po, r); }
static NOINLINE void f1194(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sllv_epi64(x, _mm512_xor_si512(y, _mm512_set1_epi8((char)0xffu))); _mm512_storeu_si512(po, r); }
static NOINLINE void f1195(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sllv_epi64(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), _mm512_xor_si512(y, _mm512_set1_epi8((char)0xffu))); _mm512_storeu_si512(po, r); }
static NOINLINE void f1196(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sllv_epi64(x, _mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu))); _mm512_storeu_si512(po, r); }
static NOINLINE void f1197(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sllv_epi64(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), x); _mm512_storeu_si512(po, r); }
static NOINLINE void f1198(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_xor_si512(_mm512_srlv_epi64(x, y), _mm512_set1_epi8((char)0xffu)); _mm512_storeu_si512(po, r); }
static NOINLINE void f1199(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srlv_epi64(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), y); _mm512_storeu_si512(po, r); }
extern const Entry table_87[] = {
  {"512:_mm512_srli_epi32(_mm512_srai_epi64(x, 1), 31)", f0, 0, 512},
  {"512:_mm512_srli_epi32(_mm512_slli_epi64(x, 63), 31)", f1, 0, 512},
  {"512:_mm512_srli_epi32(_mm512_srli_epi64(x, 63), 31)", f2, 0, 512},
  {"512:_mm512_srli_epi32(_mm512_srai_epi64(x, 63), 31)", f3, 0, 512},
  {"512:_mm512_srai_epi32(_mm512_abs_epi8(x), 31)", f4, 0, 512},
  {"512:_mm512_srai_epi32(_mm512_abs_epi16(x), 31)", f5, 0, 512},
  {"512:_mm512_srai_epi32(_mm512_abs_epi32(x), 31)", f6, 0, 512},
  {"512:_mm512_srai_epi32(_mm512_abs_epi64(x), 31)", f7, 0, 512},
  {"512:_mm512_srai_epi32(_mm512_sub_epi8(_mm512_setzero_si512(), x), 31)", f8, 0, 512},
  {"512:_mm512_srai_epi32(_mm512_sub_epi16(_mm512_setzero_si512(), x), 31)", f9, 0, 512},
  {"512:_mm512_srai_epi32(_mm512_sub_epi32(_mm512_setzero_si512(), x), 31)", f10, 0, 512},
  {"512:_mm512_srai_epi32(_mm512_sub_epi64(_mm512_setzero_si512(), x), 31)", f11, 0, 512},
  {"512:_mm512_srai_epi32(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), 31)", f12, 0, 512},
  {"512:_mm512_srai_epi32(_mm512_slli_epi16(x, 1), 31)", f13, 0, 512},
  {"512:_mm512_srai_epi32(_mm512_srli_epi16(x, 1), 31)", f14, 0, 512},
  {"512:_mm512_srai_epi32(_mm512_srai_epi16(x, 1), 31)", f15, 0, 512},
  {"512:_mm512_srai_epi32(_mm512_slli_epi16(x, 15), 31)", f16, 0, 512},
  {"512:_mm512_srai_epi32(_mm512_srli_epi16(x, 15), 31)", f17, 0, 512},
  {"512:_mm512_srai_epi32(_mm512_srai_epi16(x, 15), 31)", f18, 0, 512},
  {"512:_mm512_srai_epi32(_mm512_slli_epi32(x, 1), 31)", f19, 0, 512},
  {"512:_mm512_srai_epi32(_mm512_srli_epi32(x, 1), 31)", f20, 0, 512},
  {"512:_mm512_srai_epi32(_mm512_srai_epi32(x, 1), 31)", f21, 0, 512},
  {"512:_mm512_srai_epi32(_mm512_slli_epi32(x, 31), 31)", f22, 0, 512},
  {"512:_mm512_srai_epi32(_mm512_srli_epi32(x, 31), 31)", f23, 0, 512},
  {"512:_mm512_srai_epi32(_mm512_srai_epi32(x, 31), 31)", f24, 0, 512},
  {"512:_mm512_srai_epi32(_mm512_slli_epi64(x, 1), 31)", f25, 0, 512},
  {"512:_mm512_srai_epi32(_mm512_srli_epi64(x, 1), 31)", f26, 0, 512},
  {"512:_mm512_srai_epi32(_mm512_srai_epi64(x, 1), 31)", f27, 0, 512},
  {"512:_mm512_srai_epi32(_mm512_slli_epi64(x, 63), 31)", f28, 0, 512},
  {"512:_mm512_srai_epi32(_mm512_srli_epi64(x, 63), 31)", f29, 0, 512},
  {"512:_mm512_srai_epi32(_mm512_srai_epi64(x, 63), 31)", f30, 0, 512},
  {"512:_mm512_slli_epi64(_mm512_abs_epi8(x), 1)", f31, 0, 512},
  {"512:_mm512_slli_epi64(_mm512_abs_epi16(x), 1)", f32, 0, 512},
  {"512:_mm512_slli_epi64(_mm512_abs_epi32(x), 1)", f33, 0, 512},
  {"512:_mm512_slli_epi64(_mm512_abs_epi64(x), 1)", f34, 0, 512},
  {"512:_mm512_slli_epi64(_mm512_sub_epi8(_mm512_setzero_si512(), x), 1)", f35, 0, 512},
  {"512:_mm512_slli_epi64(_mm512_sub_epi16(_mm512_setzero_si512(), x), 1)", f36, 0, 512},
  {"512:_mm512_slli_epi64(_mm512_sub_epi32(_mm512_setzero_si512(), x), 1)", f37, 0, 512},
  {"512:_mm512_slli_epi64(_mm512_sub_epi64(_mm512_setzero_si512(), x), 1)", f38, 0, 512},
  {"512:_mm512_slli_epi64(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), 1)", f39, 0, 512},
  {"512:_mm512_slli_epi64(_mm512_slli_epi16(x, 1), 1)", f40, 0, 512},
  {"512:_mm512_slli_epi64(_mm512_srli_epi16(x, 1), 1)", f41, 0, 512},
  {"512:_mm512_slli_epi64(_mm512_srai_epi16(x, 1), 1)", f42, 0, 512},
  {"512:_mm512_slli_epi64(_mm512_slli_epi16(x, 15), 1)", f43, 0, 512},
  {"512:_mm512_slli_epi64(_mm512_srli_epi16(x, 15), 1)", f44, 0, 512},
  {"512:_mm512_slli_epi64(_mm512_srai_epi16(x, 15), 1)", f45, 0, 512},
  {"512:_mm512_slli_epi64(_mm512_slli_epi32(x, 1), 1)", f46, 0, 512},
  {"512:_mm512_slli_epi64(_mm512_srli_epi32(x, 1), 1)", f47, 0, 512},
  {"512:_mm512_slli_epi64(_mm512_srai_epi32(x, 1), 1)", f48, 0, 512},
  {"512:_mm512_slli_epi64(_mm512_slli_epi32(x, 31), 1)", f49, 0, 512},
  {"512:_mm512_slli_epi64(_mm512_srli_epi32(x, 31), 1)", f50, 0, 512},
  {"512:_mm512_slli_epi64(_mm512_srai_epi32(x, 31), 1)", f51, 0, 512},
  {"512:_mm512_slli_epi64(_mm512_slli_epi64(x, 1), 1)", f52, 0, 512},
  {"512:_mm512_slli_epi64(_mm512_srli_epi64(x, 1), 1)", f53, 0, 512},
  {"512:_mm512_slli_epi64(_mm512_srai_epi64(x, 1), 1)", f54, 0, 512},
  {"512:_mm512_slli_epi64(_mm512_slli_epi64(x, 63), 1)", f55, 0, 512},
  {"512:_mm512_slli_epi64(_mm512_srli_epi64(x, 63), 1)", f56, 0, 512},
  {"512:_mm512_slli_epi64(_mm512_srai_epi64(x, 63), 1)", f57, 0, 512},
  {"512:_mm512_srli_epi64(_mm512_abs_epi8(x), 1)", f58, 0, 512},
  {"512:_mm512_srli_epi64(_mm512_abs_epi16(x), 1)", f59, 0, 512},
  {"512:_mm512_srli_epi64(_mm512_abs_epi32(x), 1)", f60, 0, 512},
  {"512:_mm512_srli_epi64(_mm512_abs_epi64(x), 1)", f61, 0, 512},
  {"512:_mm512_srli_epi64(_mm512_sub_epi8(_mm512_setzero_si512(), x), 1)", f62, 0, 512},
  {"512:_mm512_srli_epi64(_mm512_sub_epi16(_mm512_setzero_si512(), x), 1)", f63, 0, 512},
  {"512:_mm512_srli_epi64(_mm512_sub_epi32(_mm512_setzero_si512(), x), 1)", f64, 0, 512},
  {"512:_mm512_srli_epi64(_mm512_sub_epi64(_mm512_setzero_si512(), x), 1)", f65, 0, 512},
  {"512:_mm512_srli_epi64(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), 1)", f66, 0, 512},
  {"512:_mm512_srli_epi64(_mm512_slli_epi16(x, 1), 1)", f67, 0, 512},
  {"512:_mm512_srli_epi64(_mm512_srli_epi16(x, 1), 1)", f68, 0, 512},
  {"512:_mm512_srli_epi64(_mm512_srai_epi16(x, 1), 1)", f69, 0, 512},
  {"512:_mm512_srli_epi64(_mm512_slli_epi16(x, 15), 1)", f70, 0, 512},
  {"512:_mm512_srli_epi64(_mm512_srli_epi16(x, 15), 1)", f71, 0, 512},
  {"512:_mm512_srli_epi64(_mm512_srai_epi16(x, 15), 1)", f72, 0, 512},
  {"512:_mm512_srli_epi64(_mm512_slli_epi32(x, 1), 1)", f73, 0, 512},
  {"512:_mm512_srli_epi64(_mm512_srli_epi32(x, 1), 1)", f74, 0, 512},
  {"512:_mm512_srli_epi64(_mm512_srai_epi32(x, 1), 1)", f75, 0, 512},
  {"512:_mm512_srli_epi64(_mm512_slli_epi32(x, 31), 1)", f76, 0, 512},
  {"512:_mm512_srli_epi64(_mm512_srli_epi32(x, 31), 1)", f77, 0, 512},
  {"512:_mm512_srli_epi64(_mm512_srai_epi32(x, 31), 1)", f78, 0, 512},
  {"512:_mm512_srli_epi64(_mm512_slli_epi64(x, 1), 1)", f79, 0, 512},
  {"512:_mm512_srli_epi64(_mm512_srli_epi64(x, 1), 1)", f80, 0, 512},
  {"512:_mm512_srli_epi64(_mm512_srai_epi64(x, 1), 1)", f81, 0, 512},
  {"512:_mm512_srli_epi64(_mm512_slli_epi64(x, 63), 1)", f82, 0, 512},
  {"512:_mm512_srli_epi64(_mm512_srli_epi64(x, 63), 1)", f83, 0, 512},
  {"512:_mm512_srli_epi64(_mm512_srai_epi64(x, 63), 1)", f84, 0, 512},
  {"512:_mm512_srai_epi64(_mm512_abs_epi8(x), 1)", f85, 0, 512},
  {"512:_mm512_srai_epi64(_mm512_abs_epi16(x), 1)", f86, 0, 512},
  {"512:_mm512_srai_epi64(_mm512_abs_epi32(x), 1)", f87, 0, 512},
  {"512:_mm512_srai_epi64(_mm512_abs_epi64(x), 1)", f88, 0, 512},
  {"512:_mm512_srai_epi64(_mm512_sub_epi8(_mm512_setzero_si512(), x), 1)", f89, 0, 512},
  {"512:_mm512_srai_epi64(_mm512_sub_epi16(_mm512_setzero_si512(), x), 1)", f90, 0, 512},
  {"512:_mm512_srai_epi64(_mm512_sub_epi32(_mm512_setzero_si512(), x), 1)", f91, 0, 512},
  {"512:_mm512_srai_epi64(_mm512_sub_epi64(_mm512_setzero_si512(), x), 1)", f92, 0, 512},
  {"512:_mm512_srai_epi64(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), 1)", f93, 0, 512},
  {"512:_mm512_srai_epi64(_mm512_slli_epi16(x, 1), 1)", f94, 0, 512},
  {"512:_mm512_srai_epi64(_mm512_srli_epi16(x, 1), 1)", f95, 0, 512},
  {"512:_mm512_srai_epi64(_mm512_srai_epi16(x, 1), 1)", f96, 0, 512},
  {"512:_mm512_srai_epi64(_mm512_slli_epi16(x, 15), 1)", f97, 0, 512},
  {"512:_mm512_srai_epi64(_mm512_srli_epi16(x, 15), 1)", f98, 0, 512},
  {"512:_mm512_srai_epi64(_mm512_srai_epi16(x, 15), 1)", f99, 0, 512},
  {"512:_mm512_srai_epi64(_mm512_slli_epi32(x, 1), 1)", f100, 0, 512},
  {"512:_mm512_srai_epi64(_mm512_srli_epi32(x, 1), 1)", f101, 0, 512},
  {"512:_mm512_srai_epi64(_mm512_srai_epi32(x, 1), 1)", f102, 0, 512},
  {"512:_mm512_srai_epi64(_mm512_slli_epi32(x, 31), 1)", f103, 0, 512},
  {"512:_mm512_srai_epi64(_mm512_srli_epi32(x, 31), 1)", f104, 0, 512},
  {"512:_mm512_srai_epi64(_mm512_srai_epi32(x, 31), 1)", f105, 0, 512},
  {"512:_mm512_srai_epi64(_mm512_slli_epi64(x, 1), 1)", f106, 0, 512},
  {"512:_mm512_srai_epi64(_mm512_srli_epi64(x, 1), 1)", f107, 0, 512},
  {"512:_mm512_srai_epi64(_mm512_srai_epi64(x, 1), 1)", f108, 0, 512},
  {"512:_mm512_srai_epi64(_mm512_slli_epi64(x, 63), 1)", f109, 0, 512},
  {"512:_mm512_srai_epi64(_mm512_srli_epi64(x, 63), 1)", f110, 0, 512},
  {"512:_mm512_srai_epi64(_mm512_srai_epi64(x, 63), 1)", f111, 0, 512},
  {"512:_mm512_slli_epi64(_mm512_abs_epi8(x), 63)", f112, 0, 512},
  {"512:_mm512_slli_epi64(_mm512_abs_epi16(x), 63)", f113, 0, 512},
  {"512:_mm512_slli_epi64(_mm512_abs_epi32(x), 63)", f114, 0, 512},
  {"512:_mm512_slli_epi64(_mm512_abs_epi64(x), 63)", f115, 0, 512},
  {"512:_mm512_slli_epi64(_mm512_sub_epi8(_mm512_setzero_si512(), x), 63)", f116, 0, 512},
  {"512:_mm512_slli_epi64(_mm512_sub_epi16(_mm512_setzero_si512(), x), 63)", f117, 0, 512},
  {"512:_mm512_slli_epi64(_mm512_sub_epi32(_mm512_setzero_si512(), x), 63)", f118, 0, 512},
  {"512:_mm512_slli_epi64(_mm512_sub_epi64(_mm512_setzero_si512(), x), 63)", f119, 0, 512},
  {"512:_mm512_slli_epi64(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), 63)", f120, 0, 512},
  {"512:_mm512_slli_epi64(_mm512_slli_epi16(x, 1), 63)", f121, 0, 512},
  {"512:_mm512_slli_epi64(_mm512_srli_epi16(x, 1), 63)", f122, 0, 512},
  {"512:_mm512_slli_epi64(_mm512_srai_epi16(x, 1), 63)", f123, 0, 512},
  {"512:_mm512_slli_epi64(_mm512_slli_epi16(x, 15), 63)", f124, 0, 512},
  {"512:_mm512_slli_epi64(_mm512_srli_epi16(x, 15), 63)", f125, 0, 512},
  {"512:_mm512_slli_epi64(_mm512_srai_epi16(x, 15), 63)", f126, 0, 512},
  {"512:_mm512_slli_epi64(_mm512_slli_epi32(x, 1), 63)", f127, 0, 512},
  {"512:_mm512_slli_epi64(_mm512_srli_epi32(x, 1), 63)", f128, 0, 512},
  {"512:_mm512_slli_epi64(_mm512_srai_epi32(x, 1), 63)", f129, 0, 512},
  {"512:_mm512_slli_epi64(_mm512_slli_epi32(x, 31), 63)", f130, 0, 512},
  {"512:_mm512_slli_epi64(_mm512_srli_epi32(x, 31), 63)", f131, 0, 512},
  {"512:_mm512_slli_epi64(_mm512_srai_epi32(x, 31), 63)", f132, 0, 512},
  {"512:_mm512_slli_epi64(_mm512_slli_epi64(x, 1), 63)", f133, 0, 512},
  {"512:_mm512_slli_epi64(_mm512_srli_epi64(x, 1), 63)", f134, 0, 512},
  {"512:_mm512_slli_epi64(_mm512_srai_epi64(x, 1), 63)", f135, 0, 512},
  {"512:_mm512_slli_epi64(_mm512_slli_epi64(x, 63), 63)", f136, 0, 512},
  {"512:_mm512_slli_epi64(_mm512_srli_epi64(x, 63), 63)", f137, 0, 512},
  {"512:_mm512_slli_epi64(_mm512_srai_epi64(x, 63), 63)", f138, 0, 512},
  {"512:_mm512_srli_epi64(_mm512_abs_epi8(x), 63)", f139, 0, 512},
  {"512:_mm512_srli_epi64(_mm512_abs_epi16(x), 63)", f140, 0, 512},
  {"512:_mm512_srli_epi64(_mm512_abs_epi32(x), 63)", f141, 0, 512},
  {"512:_mm512_srli_epi64(_mm512_abs_epi64(x), 63)", f142, 0, 512},
  {"512:_mm512_srli_epi64(_mm512_sub_epi8(_mm512_setzero_si512(), x), 63)", f143, 0, 512},
  {"512:_mm512_srli_epi64(_mm512_sub_epi16(_mm512_setzero_si512(), x), 63)", f144, 0, 512},
  {"512:_mm512_srli_epi64(_mm512_sub_epi32(_mm512_setzero_si512(), x), 63)", f145, 0, 512},
  {"512:_mm512_srli_epi64(_mm512_sub_epi64(_mm512_setzero_si512(), x), 63)", f146, 0, 512},
  {"512:_mm512_srli_epi64(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), 63)", f147, 0, 512},
  {"512:_mm512_srli_epi64(_mm512_slli_epi16(x, 1), 63)", f148, 0, 512},
  {"512:_mm512_srli_epi64(_mm512_srli_epi16(x, 1), 63)", f149, 0, 512},
  {"512:_mm512_srli_epi64(_mm512_srai_epi16(x, 1), 63)", f150, 0, 512},
  {"512:_mm512_srli_epi64(_mm512_slli_epi16(x, 15), 63)", f151, 0, 512},
  {"512:_mm512_srli_epi64(_mm512_srli_epi16(x, 15), 63)", f152, 0, 512},
  {"512:_mm512_srli_epi64(_mm512_srai_epi16(x, 15), 63)", f153, 0, 512},
  {"512:_mm512_srli_epi64(_mm512_slli_epi32(x, 1), 63)", f154, 0, 512},
  {"512:_mm512_srli_epi64(_mm512_srli_epi32(x, 1), 63)", f155, 0, 512},
  {"512:_mm512_srli_epi64(_mm512_srai_epi32(x, 1), 63)", f156, 0, 512},
  {"512:_mm512_srli_epi64(_mm512_slli_epi32(x, 31), 63)", f157, 0, 512},
  {"512:_mm512_srli_epi64(_mm512_srli_epi32(x, 31), 63)", f158, 0, 512},
  {"512:_mm512_srli_epi64(_mm512_srai_epi32(x, 31), 63)", f159, 0, 512},
  {"512:_mm512_srli_epi64(_mm512_slli_epi64(x, 1), 63)", f160, 0, 512},
  {"512:_mm512_srli_epi64(_mm512_srli_epi64(x, 1), 63)", f161, 0, 512},
  {"512:_mm512_srli_epi64(_mm512_srai_epi64(x, 1), 63)", f162, 0, 512},
  {"512:_mm512_srli_epi64(_mm512_slli_epi64(x, 63), 63)", f163, 0, 512},
  {"512:_mm512_srli_epi64(_mm512_srli_epi64(x, 63), 63)", f164, 0, 512},
  {"512:_mm512_srli_epi64(_mm512_srai_epi64(x, 63), 63)", f165, 0, 512},
  {"512:_mm512_srai_epi64(_mm512_abs_epi8(x), 63)", f166, 0, 512},
  {"512:_mm512_srai_epi64(_mm512_abs_epi16(x), 63)", f167, 0, 512},
  {"512:_mm512_srai_epi64(_mm512_abs_epi32(x), 63)", f168, 0, 512},
  {"512:_mm512_srai_epi64(_mm512_abs_epi64(x), 63)", f169, 0, 512},
  {"512:_mm512_srai_epi64(_mm512_sub_epi8(_mm512_setzero_si512(), x), 63)", f170, 0, 512},
  {"512:_mm512_srai_epi64(_mm512_sub_epi16(_mm512_setzero_si512(), x), 63)", f171, 0, 512},
  {"512:_mm512_srai_epi64(_mm512_sub_epi32(_mm512_setzero_si512(), x), 63)", f172, 0, 512},
  {"512:_mm512_srai_epi64(_mm512_sub_epi64(_mm512_setzero_si512(), x), 63)", f173, 0, 512},
  {"512:_mm512_srai_epi64(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), 63)", f174, 0, 512},
  {"512:_mm512_srai_epi64(_mm512_slli_epi16(x, 1), 63)", f175, 0, 512},
  {"512:_mm512_srai_epi64(_mm512_srli_epi16(x, 1), 63)", f176, 0, 512},
  {"512:_mm512_srai_epi64(_mm512_srai_epi16(x, 1), 63)", f177, 0, 512},
  {"512:_mm512_srai_epi64(_mm512_slli_epi16(x, 15), 63)", f178, 0, 512},
  {"512:_mm512_srai_epi64(_mm512_srli_epi16(x, 15), 63)", f179, 0, 512},
  {"512:_mm512_srai_epi64(_mm512_srai_epi16(x, 15), 63)", f180, 0, 512},
  {"512:_mm512_srai_epi64(_mm512_slli_epi32(x, 1), 63)", f181, 0, 512},
  {"512:_mm512_srai_epi64(_mm512_srli_epi32(x, 1), 63)", f182, 0, 512},
  {"512:_mm512_srai_epi64(_mm512_srai_epi32(x, 1), 63)", f183, 0, 512},
  {"512:_mm512_srai_epi64(_mm512_slli_epi32(x, 31), 63)", f184, 0, 512},
  {"512:_mm512_srai_epi64(_mm512_srli_epi32(x, 31), 63)", f185, 0, 512},
  {"512:_mm512_srai_epi64(_mm512_srai_epi32(x, 31), 63)", f186, 0, 512},
  {"512:_mm512_srai_epi64(_mm512_slli_epi64(x, 1), 63)", f187, 0, 512},
  {"512:_mm512_srai_epi64(_mm512_srli_epi64(x, 1), 63)", f188, 0, 512},
  {"512:_mm512_srai_epi64(_mm512_srai_epi64(x, 1), 63)", f189, 0, 512},
  {"512:_mm512_srai_epi64(_mm512_slli_epi64(x, 63), 63)", f190, 0, 512},
  {"512:_mm512_srai_epi64(_mm512_srli_epi64(x, 63), 63)", f191, 0, 512},
  {"512:_mm512_srai_epi64(_mm512_srai_epi64(x, 63), 63)", f192, 0, 512},
  {"512:_mm512_abs_epi8(_mm512_abs_epi8(_mm512_abs_epi8(x)))", f193, 0, 512},
  {"512:_mm512_abs_epi16(_mm512_abs_epi16(_mm512_abs_epi16(x)))", f194, 0, 512},
  {"512:_mm512_abs_epi32(_mm512_abs_epi32(_mm512_abs_epi32(x)))", f195, 0, 512},
  {"512:_mm512_abs_epi64(_mm512_abs_epi64(_mm512_abs_epi64(x)))", f196, 0, 512},
  {"512:_mm512_sub_epi8(_mm512_setzero_si512(), _mm512_sub_epi8(_mm512_setzero_si512(), _mm512_sub_epi8(_mm512_setzero_si512(), x)))", f197, 0, 512},
  {"512:_mm512_sub_epi16(_mm512_setzero_si512(), _mm512_sub_epi16(_mm512_setzero_si512(), _mm512_sub_epi16(_mm512_setzero_si512(), x)))", f198, 0, 512},
  {"512:_mm512_sub_epi32(_mm512_setzero_si512(), _mm512_sub_epi32(_mm512_setzero_si512(), _mm512_sub_epi32(_mm512_setzero_si512(), x)))", f199, 0, 512},
  {"512:_mm512_sub_epi64(_mm512_setzero_si512(), _mm512_sub_epi64(_mm512_setzero_si512(), _mm512_sub_epi64(_mm512_setzero_si512(), x)))", f200, 0, 512},
  {"512:_mm512_xor_si512(_mm512_xor_si512(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), _mm512_set1_epi8((char)0xffu)), _mm512_set1_epi8((char)0xffu))", f201, 0, 512},
  {"512:_mm512_slli_epi16(_mm512_slli_epi16(_mm512_slli_epi16(x, 1), 1), 1)", f202, 0, 512},
  {"512:_mm512_srli_epi16(_mm512_srli_epi16(_mm512_srli_epi16(x, 1), 1), 1)", f203, 0, 512},
  {"512:_mm512_srai_epi16(_mm512_srai_epi16(_mm512_srai_epi16(x, 1), 1), 1)", f204, 0, 512},
  {"512:_mm512_slli_epi16(_mm512_slli_epi16(_mm512_slli_epi16(x, 15), 15), 15)", f205, 0, 512},
  {"512:_mm512_srli_epi16(_mm512_srli_epi16(_mm512_srli_epi16(x, 15), 15), 15)", f206, 0, 512},
  {"512:_mm512_srai_epi16(_mm512_srai_epi16(_mm512_srai_epi16(x, 15), 15), 15)", f207, 0, 512},
  {"512:_mm512_slli_epi32(_mm512_slli_epi32(_mm512_slli_epi32(x, 1), 1), 1)", f208, 0, 512},
  {"512:_mm512_srli_epi32(_mm512_srli_epi32(_mm512_srli_epi32(x, 1), 1), 1)", f209, 0, 512},
  {"512:_mm512_srai_epi32(_mm512_srai_epi32(_mm512_srai_epi32(x, 1), 1), 1)", f210, 0, 512},
  {"512:_mm512_slli_epi32(_mm512_slli_epi32(_mm512_slli_epi32(x, 31), 31), 31)", f211, 0, 512},
  {"512:_mm512_srli_epi32(_mm512_srli_epi32(_mm512_srli_epi32(x, 31), 31), 31)", f212, 0, 512},
  {"512:_mm512_srai_epi32(_mm512_srai_epi32(_mm512_srai_epi32(x, 31), 31), 31)", f213, 0, 512},
  {"512:_mm512_slli_epi64(_mm512_slli_epi64(_mm512_slli_epi64(x, 1), 1), 1)", f214, 0, 512},
  {"512:_mm512_srli_epi64(_mm512_srli_epi64(_mm512_srli_epi64(x, 1), 1), 1)", f215, 0, 512},
  {"512:_mm512_srai_epi64(_mm512_srai_epi64(_mm512_srai_epi64(x, 1), 1), 1)", f216, 0, 512},
  {"512:_mm512_slli_epi64(_mm512_slli_epi64(_mm512_slli_epi64(x, 63), 63), 63)", f217, 0, 512},
  {"512:_mm512_srli_epi64(_mm512_srli_epi64(_mm512_srli_epi64(x, 63), 63), 63)", f218, 0, 512},
  {"512:_mm512_srai_epi64(_mm512_srai_epi64(_mm512_srai_epi64(x, 63), 63), 63)", f219, 0, 512},
  {"512:_mm512_abs_epi8(_mm512_add_epi8(x, y))", f220, 0, 512},
  {"512:_mm512_add_epi8(_mm512_abs_epi8(x), y)", f221, 0, 512},
  {"512:_mm512_add_epi8(x, _mm512_abs_epi8(y))", f222, 0, 512},
  {"512:_mm512_add_epi8(_mm512_abs_epi8(x), _mm512_abs_epi8(y))", f223, 0, 512},
  {"512:_mm512_add_epi8(x, _mm512_abs_epi8(x))", f224, 0, 512},
  {"512:_mm512_add_epi8(_mm512_abs_epi8(x), x)", f225, 0, 512},
  {"512:_mm512_abs_epi8(_mm512_sub_epi8(x, y))", f226, 0, 512},
  {"512:_mm512_sub_epi8(_mm512_abs_epi8(x), y)", f227, 0, 512},
  {"512:_mm512_sub_epi8(x, _mm512_abs_epi8(y))", f228, 0, 512},
  {"512:_mm512_sub_epi8(_mm512_abs_epi8(x), _mm512_abs_epi8(y))", f229, 0, 512},
  {"512:_mm512_sub_epi8(x, _mm512_abs_epi8(x))", f230, 0, 512},
  {"512:_mm512_sub_epi8(_mm512_abs_epi8(x), x)", f231, 0, 512},
  {"512:_mm512_abs_epi8(_mm512_adds_epi8(x, y))", f232, 0, 512},
  {"512:_mm512_adds_epi8(_mm512_abs_epi8(x), y)", f233, 0, 512},
  {"512:_mm512_adds_epi8(x, _mm512_abs_epi8(y))", f234, 0, 512},
  {"512:_mm512_adds_epi8(_mm512_abs_epi8(x), _mm512_abs_epi8(y))", f235, 0, 512},
  {"512:_mm512_adds_epi8(x, _mm512_abs_epi8(x))", f236, 0, 512},
  {"512:_mm512_adds_epi8(_mm512_abs_epi8(x), x)", f237, 0, 512},
  {"512:_mm512_abs_epi8(_mm512_subs_epi8(x, y))", f238, 0, 512},
  {"512:_mm512_subs_epi8(_mm512_abs_epi8(x), y)", f239, 0, 512},
  {"512:_mm512_subs_epi8(x, _mm512_abs_epi8(y))", f240, 0, 512},
  {"512:_mm512_subs_epi8(_mm512_abs_epi8(x), _mm512_abs_epi8(y))", f241, 0, 512},
  {"512:_mm512_subs_epi8(x, _mm512_abs_epi8(x))", f242, 0, 512},
  {"512:_mm512_subs_epi8(_mm512_abs_epi8(x), x)", f243, 0, 512},
  {"512:_mm512_abs_epi8(_mm512_adds_epu8(x, y))", f244, 0, 512},
  {"512:_mm512_adds_epu8(_mm512_abs_epi8(x), y)", f245, 0, 512},
  {"512:_mm512_adds_epu8(x, _mm512_abs_epi8(y))", f246, 0, 512},
  {"512:_mm512_adds_epu8(_mm512_abs_epi8(x), _mm512_abs_epi8(y))", f247, 0, 512},
  {"512:_mm512_adds_epu8(x, _mm512_abs_epi8(x))", f248, 0, 512},
  {"512:_mm512_adds_epu8(_mm512_abs_epi8(x), x)", f249, 0, 512},
  {"512:_mm512_abs_epi8(_mm512_subs_epu8(x, y))", f250, 0, 512},
  {"512:_mm512_subs_epu8(_mm512_abs_epi8(x), y)", f251, 0, 512},
  {"512:_mm512_subs_epu8(x, _mm512_abs_epi8(y))", f252, 0, 512},
  {"512:_mm512_subs_epu8(_mm512_abs_epi8(x), _mm512_abs_epi8(y))", f253, 0, 512},
  {"512:_mm512_subs_epu8(x, _mm512_abs_epi8(x))", f254, 0, 512},
  {"512:_mm512_subs_epu8(_mm512_abs_epi8(x), x)", f255, 0, 512},
  {"512:_mm512_abs_epi8(_mm512_avg_epu8(x, y))", f256, 0, 512},
  {"512:_mm512_avg_epu8(_mm512_abs_epi8(x), y)", f257, 0, 512},
  {"512:_mm512_avg_epu8(x, _mm512_abs_epi8(y))", f258, 0, 512},
  {"512:_mm512_avg_epu8(_mm512_abs_epi8(x), _mm512_abs_epi8(y))", f259, 0, 512},
  {"512:_mm512_avg_epu8(x, _mm512_abs_epi8(x))", f260, 0, 512},
  {"512:_mm512_avg_epu8(_mm512_abs_epi8(x), x)", f261, 0, 512},
  {"512:_mm512_abs_epi8(_mm512_min_epi8(x, y))", f262, 0, 512},
  {"512:_mm512_min_epi8(_mm512_abs_epi8(x), y)", f263, 0, 512},
  {"512:_mm512_min_epi8(x, _mm512_abs_epi8(y))", f264, 0, 512},
  {"512:_mm512_min_epi8(_mm512_abs_epi8(x), _mm512_abs_epi8(y))", f265, 0, 512},
  {"512:_mm512_min_epi8(x, _mm512_abs_epi8(x))", f266, 0, 512},
  {"512:_mm512_min_epi8(_mm512_abs_epi8(x), x)", f267, 0, 512},
  {"512:_mm512_abs_epi8(_mm512_max_epi8(x, y))", f268, 0, 512},
  {"512:_mm512_max_epi8(_mm512_abs_epi8(x), y)", f269, 0, 512},
  {"512:_mm512_max_epi8(x, _mm512_abs_epi8(y))", f270, 0, 512},
  {"512:_mm512_max_epi8(_mm512_abs_epi8(x), _mm512_abs_epi8(y))", f271, 0, 512},
  {"512:_mm512_max_epi8(x, _mm512_abs_epi8(x))", f272, 0, 512},
  {"512:_mm512_max_epi8(_mm512_abs_epi8(x), x)", f273, 0, 512},
  {"512:_mm512_abs_epi8(_mm512_min_epu8(x, y))", f274, 0, 512},
  {"512:_mm512_min_epu8(_mm512_abs_epi8(x), y)", f275, 0, 512},
  {"512:_mm512_min_epu8(x, _mm512_abs_epi8(y))", f276, 0, 512},
  {"512:_mm512_min_epu8(_mm512_abs_epi8(x), _mm512_abs_epi8(y))", f277, 0, 512},
  {"512:_mm512_min_epu8(x, _mm512_abs_epi8(x))", f278, 0, 512},
  {"512:_mm512_min_epu8(_mm512_abs_epi8(x), x)", f279, 0, 512},
  {"512:_mm512_abs_epi8(_mm512_max_epu8(x, y))", f280, 0, 512},
  {"512:_mm512_max_epu8(_mm512_abs_epi8(x), y)", f281, 0, 512},
  {"512:_mm512_max_epu8(x, _mm512_abs_epi8(y))", f282, 0, 512},
  {"512:_mm512_max_epu8(_mm512_abs_epi8(x), _mm512_abs_epi8(y))", f283, 0, 512},
  {"512:_mm512_max_epu8(x, _mm512_abs_epi8(x))", f284, 0, 512},
  {"512:_mm512_max_epu8(_mm512_abs_epi8(x), x)", f285, 0, 512},
  {"512:_mm512_abs_epi8(_mm512_and_si512(x, y))", f286, 0, 512},
  {"512:_mm512_and_si512(_mm512_abs_epi8(x), y)", f287, 0, 512},
  {"512:_mm512_and_si512(x, _mm512_abs_epi8(y))", f288, 0, 512},
  {"512:_mm512_and_si512(_mm512_abs_epi8(x), _mm512_abs_epi8(y))", f289, 0, 512},
  {"512:_mm512_and_si512(x, _mm512_abs_epi8(x))", f290, 0, 512},
  {"512:_mm512_and_si512(_mm512_abs_epi8(x), x)", f291, 0, 512},
  {"512:_mm512_abs_epi8(_mm512_or_si512(x, y))", f292, 0, 512},
  {"512:_mm512_or_si512(_mm512_abs_epi8(x), y)", f293, 0, 512},
  {"512:_mm512_or_si512(x, _mm512_abs_epi8(y))", f294, 0, 512},
  {"512:_mm512_or_si512(_mm512_abs_epi8(x), _mm512_abs_epi8(y))", f295, 0, 512},
  {"512:_mm512_or_si512(x, _mm512_abs_epi8(x))", f296, 0, 512},
  {"512:_mm512_or_si512(_mm512_abs_epi8(x), x)", f297, 0, 512},
  {"512:_mm512_abs_epi8(_mm512_xor_si512(x, y))", f298, 0, 512},
  {"512:_mm512_xor_si512(_mm512_abs_epi8(x), y)", f299, 0, 512},
  {"512:_mm512_xor_si512(x, _mm512_abs_epi8(y))", f300, 0, 512},
  {"512:_mm512_xor_si512(_mm512_abs_epi8(x), _mm512_abs_epi8(y))", f301, 0, 512},
  {"512:_mm512_xor_si512(x, _mm512_abs_epi8(x))", f302, 0, 512},
  {"512:_mm512_xor_si512(_mm512_abs_epi8(x), x)", f303, 0, 512},
  {"512:_mm512_abs_epi8(_mm512_andnot_si512(x, y))", f304, 0, 512},
  {"512:_mm512_andnot_si512(_mm512_abs_epi8(x), y)", f305, 0, 512},
  {"512:_mm512_andnot_si512(x, _mm512_abs_epi8(y))", f306, 0, 512},
  {"512:_mm512_andnot_si512(_mm512_abs_epi8(x), _mm512_abs_epi8(y))", f307, 0, 512},
  {"512:_mm512_andnot_si512(x, _mm512_abs_epi8(x))", f308, 0, 512},
  {"512:_mm512_andnot_si512(_mm512_abs_epi8(x), x)", f309, 0, 512},
  {"512:_mm512_abs_epi16(_mm512_add_epi16(x, y))", f310, 0, 512},
  {"512:_mm512_add_epi16(_mm512_abs_epi16(x), y)", f311, 0, 512},
  {"512:_mm512_add_epi16(x, _mm512_abs_epi16(y))", f312, 0, 512},
  {"512:_mm512_add_epi16(_mm512_abs_epi16(x), _mm512_abs_epi16(y))", f313, 0, 512},
  {"512:_mm512_add_epi16(x, _mm512_abs_epi16(x))", f314, 0, 512},
  {"512:_mm512_add_epi16(_mm512_abs_epi16(x), x)", f315, 0, 512},
  {"512:_mm512_abs_epi16(_mm512_sub_epi16(x, y))", f316, 0, 512},
  {"512:_mm512_sub_epi16(_mm512_abs_epi16(x), y)", f317, 0, 512},
  {"512:_mm512_sub_epi16(x, _mm512_abs_epi16(y))", f318, 0, 512},
  {"512:_mm512_sub_epi16(_mm512_abs_epi16(x), _mm512_abs_epi16(y))", f319, 0, 512},
  {"512:_mm512_sub_epi16(x, _mm512_abs_epi16(x))", f320, 0, 512},
  {"512:_mm512_sub_epi16(_mm512_abs_epi16(x), x)", f321, 0, 512},
  {"512:_mm512_abs_epi16(_mm512_adds_epi16(x, y))", f322, 0, 512},
  {"512:_mm512_adds_epi16(_mm512_abs_epi16(x), y)", f323, 0, 512},
  {"512:_mm512_adds_epi16(x, _mm512_abs_epi16(y))", f324, 0, 512},
  {"512:_mm512_adds_epi16(_mm512_abs_epi16(x), _mm512_abs_epi16(y))", f325, 0, 512},
  {"512:_mm512_adds_epi16(x, _mm512_abs_epi16(x))", f326, 0, 512},
  {"512:_mm512_adds_epi16(_mm512_abs_epi16(x), x)", f327, 0, 512},
  {"512:_mm512_abs_epi16(_mm512_subs_epi16(x, y))", f328, 0, 512},
  {"512:_mm512_subs_epi16(_mm512_abs_epi16(x), y)", f329, 0, 512},
  {"512:_mm512_subs_epi16(x, _mm512_abs_epi16(y))", f330, 0, 512},
  {"512:_mm512_subs_epi16(_mm512_abs_epi16(x), _mm512_abs_epi16(y))", f331, 0, 512},
  {"512:_mm512_subs_epi16(x, _mm512_abs_epi16(x))", f332, 0, 512},
  {"512:_mm512_subs_epi16(_mm512_abs_epi16(x), x)", f333, 0, 512},
  {"512:_mm512_abs_epi16(_mm512_adds_epu16(x, y))", f334, 0, 512},
  {"512:_mm512_adds_epu16(_mm512_abs_epi16(x), y)", f335, 0, 512},
  {"512:_mm512_adds_epu16(x, _mm512_abs_epi16(y))", f336, 0, 512},
  {"512:_mm512_adds_epu16(_mm512_abs_epi16(x), _mm512_abs_epi16(y))", f337, 0, 512},
  {"512:_mm512_adds_epu16(x, _mm512_abs_epi16(x))", f338, 0, 512},
  {"512:_mm512_adds_epu16(_mm512_abs_epi16(x), x)", f339, 0, 512},
  {"512:_mm512_abs_epi16(_mm512_subs_epu16(x, y))", f340, 0, 512},
  {"512:_mm512_subs_epu16(_mm512_abs_epi16(x), y)", f341, 0, 512},
  {"512:_mm512_subs_epu16(x, _mm512_abs_epi16(y))", f342, 0, 512},
  {"512:_mm512_subs_epu16(_mm512_abs_epi16(x), _mm512_abs_epi16(y))", f343, 0, 512},
  {"512:_mm512_subs_epu16(x, _mm512_abs_epi16(x))", f344, 0, 512},
  {"512:_mm512_subs_epu16(_mm512_abs_epi16(x), x)", f345, 0, 512},
  {"512:_mm512_abs_epi16(_mm512_avg_epu16(x, y))", f346, 0, 512},
  {"512:_mm512_avg_epu16(_mm512_abs_epi16(x), y)", f347, 0, 512},
  {"512:_mm512_avg_epu16(x, _mm512_abs_epi16(y))", f348, 0, 512},
  {"512:_mm512_avg_epu16(_mm512_abs_epi16(x), _mm512_abs_epi16(y))", f349, 0, 512},
  {"512:_mm512_avg_epu16(x, _mm512_abs_epi16(x))", f350, 0, 512},
  {"512:_mm512_avg_epu16(_mm512_abs_epi16(x), x)", f351, 0, 512},
  {"512:_mm512_abs_epi16(_mm512_min_epi16(x, y))", f352, 0, 512},
  {"512:_mm512_min_epi16(_mm512_abs_epi16(x), y)", f353, 0, 512},
  {"512:_mm512_min_epi16(x, _mm512_abs_epi16(y))", f354, 0, 512},
  {"512:_mm512_min_epi16(_mm512_abs_epi16(x), _mm512_abs_epi16(y))", f355, 0, 512},
  {"512:_mm512_min_epi16(x, _mm512_abs_epi16(x))", f356, 0, 512},
  {"512:_mm512_min_epi16(_mm512_abs_epi16(x), x)", f357, 0, 512},
  {"512:_mm512_abs_epi16(_mm512_max_epi16(x, y))", f358, 0, 512},
  {"512:_mm512_max_epi16(_mm512_abs_epi16(x), y)", f359, 0, 512},
  {"512:_mm512_max_epi16(x, _mm512_abs_epi16(y))", f360, 0, 512},
  {"512:_mm512_max_epi16(_mm512_abs_epi16(x), _mm512_abs_epi16(y))", f361, 0, 512},
  {"512:_mm512_max_epi16(x, _mm512_abs_epi16(x))", f362, 0, 512},
  {"512:_mm512_max_epi16(_mm512_abs_epi16(x), x)", f363, 0, 512},
  {"512:_mm512_abs_epi16(_mm512_min_epu16(x, y))", f364, 0, 512},
  {"512:_mm512_min_epu16(_mm512_abs_epi16(x), y)", f365, 0, 512},
  {"512:_mm512_min_epu16(x, _mm512_abs_epi16(y))", f366, 0, 512},
  {"512:_mm512_min_epu16(_mm512_abs_epi16(x), _mm512_abs_epi16(y))", f367, 0, 512},
  {"512:_mm512_min_epu16(x, _mm512_abs_epi16(x))", f368, 0, 512},
  {"512:_mm512_min_epu16(_mm512_abs_epi16(x), x)", f369, 0, 512},
  {"512:_mm512_abs_epi16(_mm512_max_epu16(x, y))", f370, 0, 512},
  {"512:_mm512_max_epu16(_mm512_abs_epi16(x), y)", f371, 0, 512},
  {"512:_mm512_max_epu16(x, _mm512_abs_epi16(y))", f372, 0, 512},
  {"512:_mm512_max_epu16(_mm512_abs_epi16(x), _mm512_abs_epi16(y))", f373, 0, 512},
  {"512:_mm512_max_epu16(x, _mm512_abs_epi16(x))", f374, 0, 512},
  {"512:_mm512_max_epu16(_mm512_abs_epi16(x), x)", f375, 0, 512},
  {"512:_mm512_abs_epi16(_mm512_and_si512(x, y))", f376, 0, 512},
  {"512:_mm512_and_si512(_mm512_abs_epi16(x), y)", f377, 0, 512},
  {"512:_mm512_and_si512(x, _mm512_abs_epi16(y))", f378, 0, 512},
  {"512:_mm512_and_si512(_mm512_abs_epi16(x), _mm512_abs_epi16(y))", f379, 0, 512},
  {"512:_mm512_and_si512(x, _mm512_abs_epi16(x))", f380, 0, 512},
  {"512:_mm512_and_si512(_mm512_abs_epi16(x), x)", f381, 0, 512},
  {"512:_mm512_abs_epi16(_mm512_or_si512(x, y))", f382, 0, 512},
  {"512:_mm512_or_si512(_mm512_abs_epi16(x), y)", f383, 0, 512},
  {"512:_mm512_or_si512(x, _mm512_abs_epi16(y))", f384, 0, 512},
  {"512:_mm512_or_si512(_mm512_abs_epi16(x), _mm512_abs_epi16(y))", f385, 0, 512},
  {"512:_mm512_or_si512(x, _mm512_abs_epi16(x))", f386, 0, 512},
  {"512:_mm512_or_si512(_mm512_abs_epi16(x), x)", f387, 0, 512},
  {"512:_mm512_abs_epi16(_mm512_xor_si512(x, y))", f388, 0, 512},
  {"512:_mm512_xor_si512(_mm512_abs_epi16(x), y)", f389, 0, 512},
  {"512:_mm512_xor_si512(x, _mm512_abs_epi16(y))", f390, 0, 512},
  {"512:_mm512_xor_si512(_mm512_abs_epi16(x), _mm512_abs_epi16(y))", f391, 0, 512},
  {"512:_mm512_xor_si512(x, _mm512_abs_epi16(x))", f392, 0, 512},
  {"512:_mm512_xor_si512(_mm512_abs_epi16(x), x)", f393, 0, 512},
  {"512:_mm512_abs_epi16(_mm512_andnot_si512(x, y))", f394, 0, 512},
  {"512:_mm512_andnot_si512(_mm512_abs_epi16(x), y)", f395, 0, 512},
  {"512:_mm512_andnot_si512(x, _mm512_abs_epi16(y))", f396, 0, 512},
  {"512:_mm512_andnot_si512(_mm512_abs_epi16(x), _mm512_abs_epi16(y))", f397, 0, 512},
  {"512:_mm512_andnot_si512(x, _mm512_abs_epi16(x))", f398, 0, 512},
  {"512:_mm512_andnot_si512(_mm512_abs_epi16(x), x)", f399, 0, 512},
  {"512:_mm512_abs_epi16(_mm512_mullo_epi16(x, y))", f400, 0, 512},
  {"512:_mm512_mullo_epi16(_mm512_abs_epi16(x), y)", f401, 0, 512},
  {"512:_mm512_mullo_epi16(x, _mm512_abs_epi16(y))", f402, 0, 512},
  {"512:_mm512_mullo_epi16(_mm512_abs_epi16(x), _mm512_abs_epi16(y))", f403, 0, 512},
  {"512:_mm512_mullo_epi16(x, _mm512_abs_epi16(x))", f404, 0, 512},
  {"512:_mm512_mullo_epi16(_mm512_abs_epi16(x), x)", f405, 0, 512},
  {"512:_mm512_abs_epi16(_mm512_mulhi_epi16(x, y))", f406, 0, 512},
  {"512:_mm512_mulhi_epi16(_mm512_abs_epi16(x), y)", f407, 0, 512},
  {"512:_mm512_mulhi_epi16(x, _mm512_abs_epi16(y))", f408, 0, 512},
  {"512:_mm512_mulhi_epi16(_mm512_abs_epi16(x), _mm512_abs_epi16(y))", f409, 0, 512},
  {"512:_mm512_mulhi_epi16(x, _mm512_abs_epi16(x))", f410, 0, 512},
  {"512:_mm512_mulhi_epi16(_mm512_abs_epi16(x), x)", f411, 0, 512},
  {"512:_mm512_abs_epi16(_mm512_mulhi_epu16(x, y))", f412, 0, 512},
  {"512:_mm512_mulhi_epu16(_mm512_abs_epi16(x), y)", f413, 0, 512},
  {"512:_mm512_mulhi_epu16(x, _mm512_abs_epi16(y))", f414, 0, 512},
  {"512:_mm512_mulhi_epu16(_mm512_abs_epi16(x), _mm512_abs_epi16(y))", f415, 0, 512},
  {"512:_mm512_mulhi_epu16(x, _mm512_abs_epi16(x))", f416, 0, 512},
  {"512:_mm512_mulhi_epu16(_mm512_abs_epi16(x), x)", f417, 0, 512},
  {"512:_mm512_abs_epi32(_mm512_add_epi32(x, y))", f418, 0, 512},
  {"512:_mm512_add_epi32(_mm512_abs_epi32(x), y)", f419, 0, 512},
  {"512:_mm512_add_epi32(x, _mm512_abs_epi32(y))", f420, 0, 512},
  {"512:_mm512_add_epi32(_mm512_abs_epi32(x), _mm512_abs_epi32(y))", f421, 0, 512},
  {"512:_mm512_add_epi32(x, _mm512_abs_epi32(x))", f422, 0, 512},
  {"512:_mm512_add_epi32(_mm512_abs_epi32(x), x)", f423, 0, 512},
  {"512:_mm512_abs_epi32(_mm512_sub_epi32(x, y))", f424, 0, 512},
  {"512:_mm512_sub_epi32(_mm512_abs_epi32(x), y)", f425, 0, 512},
  {"512:_mm512_sub_epi32(x, _mm512_abs_epi32(y))", f426, 0, 512},
  {"512:_mm512_sub_epi32(_mm512_abs_epi32(x), _mm512_abs_epi32(y))", f427, 0, 512},
  {"512:_mm512_sub_epi32(x, _mm512_abs_epi32(x))", f428, 0, 512},
  {"512:_mm512_sub_epi32(_mm512_abs_epi32(x), x)", f429, 0, 512},
  {"512:_mm512_abs_epi32(_mm512_min_epi32(x, y))", f430, 0, 512},
  {"512:_mm512_min_epi32(_mm512_abs_epi32(x), y)", f431, 0, 512},
  {"512:_mm512_min_epi32(x, _mm512_abs_epi32(y))", f432, 0, 512},
  {"512:_mm512_min_epi32(_mm512_abs_epi32(x), _mm512_abs_epi32(y))", f433, 0, 512},
  {"512:_mm512_min_epi32(x, _mm512_abs_epi32(x))", f434, 0, 512},
  {"512:_mm512_min_epi32(_mm512_abs_epi32(x), x)", f435, 0, 512},
  {"512:_mm512_abs_epi32(_mm512_max_epi32(x, y))", f436, 0, 512},
  {"512:_mm512_max_epi32(_mm512_abs_epi32(x), y)", f437, 0, 512},
  {"512:_mm512_max_epi32(x, _mm512_abs_epi32(y))", f438, 0, 512},
  {"512:_mm512_max_epi32(_mm512_abs_epi32(x), _mm512_abs_epi32(y))", f439, 0, 512},
  {"512:_mm512_max_epi32(x, _mm512_abs_epi32(x))", f440, 0, 512},
  {"512:_mm512_max_epi32(_mm512_abs_epi32(x), x)", f441, 0, 512},
  {"512:_mm512_abs_epi32(_mm512_min_epu32(x, y))", f442, 0, 512},
  {"512:_mm512_min_epu32(_mm512_abs_epi32(x), y)", f443, 0, 512},
  {"512:_mm512_min_epu32(x, _mm512_abs_epi32(y))", f444, 0, 512},
  {"512:_mm512_min_epu32(_mm512_abs_epi32(x), _mm512_abs_epi32(y))", f445, 0, 512},
  {"512:_mm512_min_epu32(x, _mm512_abs_epi32(x))", f446, 0, 512},
  {"512:_mm512_min_epu32(_mm512_abs_epi32(x), x)", f447, 0, 512},
  {"512:_mm512_abs_epi32(_mm512_max_epu32(x, y))", f448, 0, 512},
  {"512:_mm512_max_epu32(_mm512_abs_epi32(x), y)", f449, 0, 512},
  {"512:_mm512_max_epu32(x, _mm512_abs_epi32(y))", f450, 0, 512},
  {"512:_mm512_max_epu32(_mm512_abs_epi32(x), _mm512_abs_epi32(y))", f451, 0, 512},
  {"512:_mm512_max_epu32(x, _mm512_abs_epi32(x))", f452, 0, 512},
  {"512:_mm512_max_epu32(_mm512_abs_epi32(x), x)", f453, 0, 512},
  {"512:_mm512_abs_epi32(_mm512_and_si512(x, y))", f454, 0, 512},
  {"512:_mm512_and_si512(_mm512_abs_epi32(x), y)", f455, 0, 512},
  {"512:_mm512_and_si512(x, _mm512_abs_epi32(y))", f456, 0, 512},
  {"512:_mm512_and_si512(_mm512_abs_epi32(x), _mm512_abs_epi32(y))", f457, 0, 512},
  {"512:_mm512_and_si512(x, _mm512_abs_epi32(x))", f458, 0, 512},
  {"512:_mm512_and_si512(_mm512_abs_epi32(x), x)", f459, 0, 512},
  {"512:_mm512_abs_epi32(_mm512_or_si512(x, y))", f460, 0, 512},
  {"512:_mm512_or_si512(_mm512_abs_epi32(x), y)", f461, 0, 512},
  {"512:_mm512_or_si512(x, _mm512_abs_epi32(y))", f462, 0, 512},
  {"512:_mm512_or_si512(_mm512_abs_epi32(x), _mm512_abs_epi32(y))", f463, 0, 512},
  {"512:_mm512_or_si512(x, _mm512_abs_epi32(x))", f464, 0, 512},
  {"512:_mm512_or_si512(_mm512_abs_epi32(x), x)", f465, 0, 512},
  {"512:_mm512_abs_epi32(_mm512_xor_si512(x, y))", f466, 0, 512},
  {"512:_mm512_xor_si512(_mm512_abs_epi32(x), y)", f467, 0, 512},
  {"512:_mm512_xor_si512(x, _mm512_abs_epi32(y))", f468, 0, 512},
  {"512:_mm512_xor_si512(_mm512_abs_epi32(x), _mm512_abs_epi32(y))", f469, 0, 512},
  {"512:_mm512_xor_si512(x, _mm512_abs_epi32(x))", f470, 0, 512},
  {"512:_mm512_xor_si512(_mm512_abs_epi32(x), x)", f471, 0, 512},
  {"512:_mm512_abs_epi32(_mm512_andnot_si512(x, y))", f472, 0, 512},
  {"512:_mm512_andnot_si512(_mm512_abs_epi32(x), y)", f473, 0, 512},
  {"512:_mm512_andnot_si512(x, _mm512_abs_epi32(y))", f474, 0, 512},
  {"512:_mm512_andnot_si512(_mm512_abs_epi32(x), _mm512_abs_epi32(y))", f475, 0, 512},
  {"512:_mm512_andnot_si512(x, _mm512_abs_epi32(x))", f476, 0, 512},
  {"512:_mm512_andnot_si512(_mm512_abs_epi32(x), x)", f477, 0, 512},
  {"512:_mm512_abs_epi32(_mm512_mullo_epi32(x, y))", f478, 0, 512},
  {"512:_mm512_mullo_epi32(_mm512_abs_epi32(x), y)", f479, 0, 512},
  {"512:_mm512_mullo_epi32(x, _mm512_abs_epi32(y))", f480, 0, 512},
  {"512:_mm512_mullo_epi32(_mm512_abs_epi32(x), _mm512_abs_epi32(y))", f481, 0, 512},
  {"512:_mm512_mullo_epi32(x, _mm512_abs_epi32(x))", f482, 0, 512},
  {"512:_mm512_mullo_epi32(_mm512_abs_epi32(x), x)", f483, 0, 512},
  {"512:_mm512_abs_epi32(_mm512_sllv_epi32(x, y))", f484, 0, 512},
  {"512:_mm512_sllv_epi32(_mm512_abs_epi32(x), y)", f485, 0, 512},
  {"512:_mm512_sllv_epi32(x, _mm512_abs_epi32(y))", f486, 0, 512},
  {"512:_mm512_sllv_epi32(_mm512_abs_epi32(x), _mm512_abs_epi32(y))", f487, 0, 512},
  {"512:_mm512_sllv_epi32(x, _mm512_abs_epi32(x))", f488, 0, 512},
  {"512:_mm512_sllv_epi32(_mm512_abs_epi32(x), x)", f489, 0, 512},
  {"512:_mm512_abs_epi32(_mm512_srlv_epi32(x, y))", f490, 0, 512},
  {"512:_mm512_srlv_epi32(_mm512_abs_epi32(x), y)", f491, 0, 512},
  {"512:_mm512_srlv_epi32(x, _mm512_abs_epi32(y))", f492, 0, 512},
  {"512:_mm512_srlv_epi32(_mm512_abs_epi32(x), _mm512_abs_epi32(y))", f493, 0, 512},
  {"512:_mm512_srlv_epi32(x, _mm512_abs_epi32(x))", f494, 0, 512},
  {"512:_mm512_srlv_epi32(_mm512_abs_epi32(x), x)", f495, 0, 512},
  {"512:_mm512_abs_epi32(_mm512_srav_epi32(x, y))", f496, 0, 512},
  {"512:_mm512_srav_epi32(_mm512_abs_epi32(x), y)", f497, 0, 512},
  {"512:_mm512_srav_epi32(x, _mm512_abs_epi32(y))", f498, 0, 512},
  {"512:_mm512_srav_epi32(_mm512_abs_epi32(x), _mm512_abs_epi32(y))", f499, 0, 512},
  {"512:_mm512_srav_epi32(x, _mm512_abs_epi32(x))", f500, 0, 512},
  {"512:_mm512_srav_epi32(_mm512_abs_epi32(x), x)", f501, 0, 512},
  {"512:_mm512_abs_epi64(_mm512_add_epi64(x, y))", f502, 0, 512},
  {"512:_mm512_add_epi64(_mm512_abs_epi64(x), y)", f503, 0, 512},
  {"512:_mm512_add_epi64(x, _mm512_abs_epi64(y))", f504, 0, 512},
  {"512:_mm512_add_epi64(_mm512_abs_epi64(x), _mm512_abs_epi64(y))", f505, 0, 512},
  {"512:_mm512_add_epi64(x, _mm512_abs_epi64(x))", f506, 0, 512},
  {"512:_mm512_add_epi64(_mm512_abs_epi64(x), x)", f507, 0, 512},
  {"512:_mm512_abs_epi64(_mm512_sub_epi64(x, y))", f508, 0, 512},
  {"512:_mm512_sub_epi64(_mm512_abs_epi64(x), y)", f509, 0, 512},
  {"512:_mm512_sub_epi64(x, _mm512_abs_epi64(y))", f510, 0, 512},
  {"512:_mm512_sub_epi64(_mm512_abs_epi64(x), _mm512_abs_epi64(y))", f511, 0, 512},
  {"512:_mm512_sub_epi64(x, _mm512_abs_epi64(x))", f512, 0, 512},
  {"512:_mm512_sub_epi64(_mm512_abs_epi64(x), x)", f513, 0, 512},
  {"512:_mm512_abs_epi64(_mm512_min_epi64(x, y))", f514, 0, 512},
  {"512:_mm512_min_epi64(_mm512_abs_epi64(x), y)", f515, 0, 512},
  {"512:_mm512_min_epi64(x, _mm512_abs_epi64(y))", f516, 0, 512},
  {"512:_mm512_min_epi64(_mm512_abs_epi64(x), _mm512_abs_epi64(y))", f517, 0, 512},
  {"512:_mm512_min_epi64(x, _mm512_abs_epi64(x))", f518, 0, 512},
  {"512:_mm512_min_epi64(_mm512_abs_epi64(x), x)", f519, 0, 512},
  {"512:_mm512_abs_epi64(_mm512_max_epi64(x, y))", f520, 0, 512},
  {"512:_mm512_max_epi64(_mm512_abs_epi64(x), y)", f521, 0, 512},
  {"512:_mm512_max_epi64(x, _mm512_abs_epi64(y))", f522, 0, 512},
  {"512:_mm512_max_epi64(_mm512_abs_epi64(x), _mm512_abs_epi64(y))", f523, 0, 512},
  {"512:_mm512_max_epi64(x, _mm512_abs_epi64(x))", f524, 0, 512},
  {"512:_mm512_max_epi64(_mm512_abs_epi64(x), x)", f525, 0, 512},
  {"512:_mm512_abs_epi64(_mm512_min_epu64(x, y))", f526, 0, 512},
  {"512:_mm512_min_epu64(_mm512_abs_epi64(x), y)", f527, 0, 512},
  {"512:_mm512_min_epu64(x, _mm512_abs_epi64(y))", f528, 0, 512},
  {"512:_mm512_min_epu64(_mm512_abs_epi64(x), _mm512_abs_epi64(y))", f529, 0, 512},
  {"512:_mm512_min_epu64(x, _mm512_abs_epi64(x))", f530, 0, 512},
  {"512:_mm512_min_epu64(_mm512_abs_epi64(x), x)", f531, 0, 512},
  {"512:_mm512_abs_epi64(_mm512_max_epu64(x, y))", f532, 0, 512},
  {"512:_mm512_max_epu64(_mm512_abs_epi64(x), y)", f533, 0, 512},
  {"512:_mm512_max_epu64(x, _mm512_abs_epi64(y))", f534, 0, 512},
  {"512:_mm512_max_epu64(_mm512_abs_epi64(x), _mm512_abs_epi64(y))", f535, 0, 512},
  {"512:_mm512_max_epu64(x, _mm512_abs_epi64(x))", f536, 0, 512},
  {"512:_mm512_max_epu64(_mm512_abs_epi64(x), x)", f537, 0, 512},
  {"512:_mm512_abs_epi64(_mm512_and_si512(x, y))", f538, 0, 512},
  {"512:_mm512_and_si512(_mm512_abs_epi64(x), y)", f539, 0, 512},
  {"512:_mm512_and_si512(x, _mm512_abs_epi64(y))", f540, 0, 512},
  {"512:_mm512_and_si512(_mm512_abs_epi64(x), _mm512_abs_epi64(y))", f541, 0, 512},
  {"512:_mm512_and_si512(x, _mm512_abs_epi64(x))", f542, 0, 512},
  {"512:_mm512_and_si512(_mm512_abs_epi64(x), x)", f543, 0, 512},
  {"512:_mm512_abs_epi64(_mm512_or_si512(x, y))", f544, 0, 512},
  {"512:_mm512_or_si512(_mm512_abs_epi64(x), y)", f545, 0, 512},
  {"512:_mm512_or_si512(x, _mm512_abs_epi64(y))", f546, 0, 512},
  {"512:_mm512_or_si512(_mm512_abs_epi64(x), _mm512_abs_epi64(y))", f547, 0, 512},
  {"512:_mm512_or_si512(x, _mm512_abs_epi64(x))", f548, 0, 512},
  {"512:_mm512_or_si512(_mm512_abs_epi64(x), x)", f549, 0, 512},
  {"512:_mm512_abs_epi64(_mm512_xor_si512(x, y))", f550, 0, 512},
  {"512:_mm512_xor_si512(_mm512_abs_epi64(x), y)", f551, 0, 512},
  {"512:_mm512_xor_si512(x, _mm512_abs_epi64(y))", f552, 0, 512},
  {"512:_mm512_xor_si512(_mm512_abs_epi64(x), _mm512_abs_epi64(y))", f553, 0, 512},
  {"512:_mm512_xor_si512(x, _mm512_abs_epi64(x))", f554, 0, 512},
  {"512:_mm512_xor_si512(_mm512_abs_epi64(x), x)", f555, 0, 512},
  {"512:_mm512_abs_epi64(_mm512_andnot_si512(x, y))", f556, 0, 512},
  {"512:_mm512_andnot_si512(_mm512_abs_epi64(x), y)", f557, 0, 512},
  {"512:_mm512_andnot_si512(x, _mm512_abs_epi64(y))", f558, 0, 512},
  {"512:_mm512_andnot_si512(_mm512_abs_epi64(x), _mm512_abs_epi64(y))", f559, 0, 512},
  {"512:_mm512_andnot_si512(x, _mm512_abs_epi64(x))", f560, 0, 512},
  {"512:_mm512_andnot_si512(_mm512_abs_epi64(x), x)", f561, 0, 512},
  {"512:_mm512_abs_epi64(_mm512_sllv_epi64(x, y))", f562, 0, 512},
  {"512:_mm512_sllv_epi64(_mm512_abs_epi64(x), y)", f563, 0, 512},
  {"512:_mm512_sllv_epi64(x, _mm512_abs_epi64(y))", f564, 0, 512},
  {"512:_mm512_sllv_epi64(_mm512_abs_epi64(x), _mm512_abs_epi64(y))", f565, 0, 512},
  {"512:_mm512_sllv_epi64(x, _mm512_abs_epi64(x))", f566, 0, 512},
  {"512:_mm512_sllv_epi64(_mm512_abs_epi64(x), x)", f567, 0, 512},
  {"512:_mm512_abs_epi64(_mm512_srlv_epi64(x, y))", f568, 0, 512},
  {"512:_mm512_srlv_epi64(_mm512_abs_epi64(x), y)", f569, 0, 512},
  {"512:_mm512_srlv_epi64(x, _mm512_abs_epi64(y))", f570, 0, 512},
  {"512:_mm512_srlv_epi64(_mm512_abs_epi64(x), _mm512_abs_epi64(y))", f571, 0, 512},
  {"512:_mm512_srlv_epi64(x, _mm512_abs_epi64(x))", f572, 0, 512},
  {"512:_mm512_srlv_epi64(_mm512_abs_epi64(x), x)", f573, 0, 512},
  {"512:_mm512_sub_epi8(_mm512_setzero_si512(), _mm512_add_epi8(x, y))", f574, 0, 512},
  {"512:_mm512_add_epi8(_mm512_sub_epi8(_mm512_setzero_si512(), x), y)", f575, 0, 512},
  {"512:_mm512_add_epi8(x, _mm512_sub_epi8(_mm512_setzero_si512(), y))", f576, 0, 512},
  {"512:_mm512_add_epi8(_mm512_sub_epi8(_mm512_setzero_si512(), x), _mm512_sub_epi8(_mm512_setzero_si512(), y))", f577, 0, 512},
  {"512:_mm512_add_epi8(x, _mm512_sub_epi8(_mm512_setzero_si512(), x))", f578, 0, 512},
  {"512:_mm512_add_epi8(_mm512_sub_epi8(_mm512_setzero_si512(), x), x)", f579, 0, 512},
  {"512:_mm512_sub_epi8(_mm512_setzero_si512(), _mm512_sub_epi8(x, y))", f580, 0, 512},
  {"512:_mm512_sub_epi8(_mm512_sub_epi8(_mm512_setzero_si512(), x), y)", f581, 0, 512},
  {"512:_mm512_sub_epi8(x, _mm512_sub_epi8(_mm512_setzero_si512(), y))", f582, 0, 512},
  {"512:_mm512_sub_epi8(_mm512_sub_epi8(_mm512_setzero_si512(), x), _mm512_sub_epi8(_mm512_setzero_si512(), y))", f583, 0, 512},
  {"512:_mm512_sub_epi8(x, _mm512_sub_epi8(_mm512_setzero_si512(), x))", f584, 0, 512},
  {"512:_mm512_sub_epi8(_mm512_sub_epi8(_mm512_setzero_si512(), x), x)", f585, 0, 512},
  {"512:_mm512_sub_epi8(_mm512_setzero_si512(), _mm512_adds_epi8(x, y))", f586, 0, 512},
  {"512:_mm512_adds_epi8(_mm512_sub_epi8(_mm512_setzero_si512(), x), y)", f587, 0, 512},
  {"512:_mm512_adds_epi8(x, _mm512_sub_epi8(_mm512_setzero_si512(), y))", f588, 0, 512},
  {"512:_mm512_adds_epi8(_mm512_sub_epi8(_mm512_setzero_si512(), x), _mm512_sub_epi8(_mm512_setzero_si512(), y))", f589, 0, 512},
  {"512:_mm512_adds_epi8(x, _mm512_sub_epi8(_mm512_setzero_si512(), x))", f590, 0, 512},
  {"512:_mm512_adds_epi8(_mm512_sub_epi8(_mm512_setzero_si512(), x), x)", f591, 0, 512},
  {"512:_mm512_sub_epi8(_mm512_setzero_si512(), _mm512_subs_epi8(x, y))", f592, 0, 512},
  {"512:_mm512_subs_epi8(_mm512_sub_epi8(_mm512_setzero_si512(), x), y)", f593, 0, 512},
  {"512:_mm512_subs_epi8(x, _mm512_sub_epi8(_mm512_setzero_si512(), y))", f594, 0, 512},
  {"512:_mm512_subs_epi8(_mm512_sub_epi8(_mm512_setzero_si512(), x), _mm512_sub_epi8(_mm512_setzero_si512(), y))", f595, 0, 512},
  {"512:_mm512_subs_epi8(x, _mm512_sub_epi8(_mm512_setzero_si512(), x))", f596, 0, 512},
  {"512:_mm512_subs_epi8(_mm512_sub_epi8(_mm512_setzero_si512(), x), x)", f597, 0, 512},
  {"512:_mm512_sub_epi8(_mm512_setzero_si512(), _mm512_adds_epu8(x, y))", f598, 0, 512},
  {"512:_mm512_adds_epu8(_mm512_sub_epi8(_mm512_setzero_si512(), x), y)", f599, 0, 512},
  {"512:_mm512_adds_epu8(x, _mm512_sub_epi8(_mm512_setzero_si512(), y))", f600, 0, 512},
  {"512:_mm512_adds_epu8(_mm512_sub_epi8(_mm512_setzero_si512(), x), _mm512_sub_epi8(_mm512_setzero_si512(), y))", f601, 0, 512},
  {"512:_mm512_adds_epu8(x, _mm512_sub_epi8(_mm512_setzero_si512(), x))", f602, 0, 512},
  {"512:_mm512_adds_epu8(_mm512_sub_epi8(_mm512_setzero_si512(), x), x)", f603, 0, 512},
  {"512:_mm512_sub_epi8(_mm512_setzero_si512(), _mm512_subs_epu8(x, y))", f604, 0, 512},
  {"512:_mm512_subs_epu8(_mm512_sub_epi8(_mm512_setzero_si512(), x), y)", f605, 0, 512},
  {"512:_mm512_subs_epu8(x, _mm512_sub_epi8(_mm512_setzero_si512(), y))", f606, 0, 512},
  {"512:_mm512_subs_epu8(_mm512_sub_epi8(_mm512_setzero_si512(), x), _mm512_sub_epi8(_mm512_setzero_si512(), y))", f607, 0, 512},
  {"512:_mm512_subs_epu8(x, _mm512_sub_epi8(_mm512_setzero_si512(), x))", f608, 0, 512},
  {"512:_mm512_subs_epu8(_mm512_sub_epi8(_mm512_setzero_si512(), x), x)", f609, 0, 512},
  {"512:_mm512_sub_epi8(_mm512_setzero_si512(), _mm512_avg_epu8(x, y))", f610, 0, 512},
  {"512:_mm512_avg_epu8(_mm512_sub_epi8(_mm512_setzero_si512(), x), y)", f611, 0, 512},
  {"512:_mm512_avg_epu8(x, _mm512_sub_epi8(_mm512_setzero_si512(), y))", f612, 0, 512},
  {"512:_mm512_avg_epu8(_mm512_sub_epi8(_mm512_setzero_si512(), x), _mm512_sub_epi8(_mm512_setzero_si512(), y))", f613, 0, 512},
  {"512:_mm512_avg_epu8(x, _mm512_sub_epi8(_mm512_setzero_si512(), x))", f614, 0, 512},
  {"512:_mm512_avg_epu8(_mm512_sub_epi8(_mm512_setzero_si512(), x), x)", f615, 0, 512},
  {"512:_mm512_sub_epi8(_mm512_setzero_si512(), _mm512_min_epi8(x, y))", f616, 0, 512},
  {"512:_mm512_min_epi8(_mm512_sub_epi8(_mm512_setzero_si512(), x), y)", f617, 0, 512},
  {"512:_mm512_min_epi8(x, _mm512_sub_epi8(_mm512_setzero_si512(), y))", f618, 0, 512},
  {"512:_mm512_min_epi8(_mm512_sub_epi8(_mm512_setzero_si512(), x), _mm512_sub_epi8(_mm512_setzero_si512(), y))", f619, 0, 512},
  {"512:_mm512_min_epi8(x, _mm512_sub_epi8(_mm512_setzero_si512(), x))", f620, 0, 512},
  {"512:_mm512_min_epi8(_mm512_sub_epi8(_mm512_setzero_si512(), x), x)", f621, 0, 512},
  {"512:_mm512_sub_epi8(_mm512_setzero_si512(), _mm512_max_epi8(x, y))", f622, 0, 512},
  {"512:_mm512_max_epi8(_mm512_sub_epi8(_mm512_setzero_si512(), x), y)", f623, 0, 512},
  {"512:_mm512_max_epi8(x, _mm512_sub_epi8(_mm512_setzero_si512(), y))", f624, 0, 512},
  {"512:_mm512_max_epi8(_mm512_sub_epi8(_mm512_setzero_si512(), x), _mm512_sub_epi8(_mm512_setzero_si512(), y))", f625, 0, 512},
  {"512:_mm512_max_epi8(x, _mm512_sub_epi8(_mm512_setzero_si512(), x))", f626, 0, 512},
  {"512:_mm512_max_epi8(_mm512_sub_epi8(_mm512_setzero_si512(), x), x)", f627, 0, 512},
  {"512:_mm512_sub_epi8(_mm512_setzero_si512(), _mm512_min_epu8(x, y))", f628, 0, 512},
  {"512:_mm512_min_epu8(_mm512_sub_epi8(_mm512_setzero_si512(), x), y)", f629, 0, 512},
  {"512:_mm512_min_epu8(x, _mm512_sub_epi8(_mm512_setzero_si512(), y))", f630, 0, 512},
  {"512:_mm512_min_epu8(_mm512_sub_epi8(_mm512_setzero_si512(), x), _mm512_sub_epi8(_mm512_setzero_si512(), y))", f631, 0, 512},
  {"512:_mm512_min_epu8(x, _mm512_sub_epi8(_mm512_setzero_si512(), x))", f632, 0, 512},
  {"512:_mm512_min_epu8(_mm512_sub_epi8(_mm512_setzero_si512(), x), x)", f633, 0, 512},
  {"512:_mm512_sub_epi8(_mm512_setzero_si512(), _mm512_max_epu8(x, y))", f634, 0, 512},
  {"512:_mm512_max_epu8(_mm512_sub_epi8(_mm512_setzero_si512(), x), y)", f635, 0, 512},
  {"512:_mm512_max_epu8(x, _mm512_sub_epi8(_mm512_setzero_si512(), y))", f636, 0, 512},
  {"512:_mm512_max_epu8(_mm512_sub_epi8(_mm512_setzero_si512(), x), _mm512_sub_epi8(_mm512_setzero_si512(), y))", f637, 0, 512},
  {"512:_mm512_max_epu8(x, _mm512_sub_epi8(_mm512_setzero_si512(), x))", f638, 0, 512},
  {"512:_mm512_max_epu8(_mm512_sub_epi8(_mm512_setzero_si512(), x), x)", f639, 0, 512},
  {"512:_mm512_sub_epi8(_mm512_setzero_si512(), _mm512_and_si512(x, y))", f640, 0, 512},
  {"512:_mm512_and_si512(_mm512_sub_epi8(_mm512_setzero_si512(), x), y)", f641, 0, 512},
  {"512:_mm512_and_si512(x, _mm512_sub_epi8(_mm512_setzero_si512(), y))", f642, 0, 512},
  {"512:_mm512_and_si512(_mm512_sub_epi8(_mm512_setzero_si512(), x), _mm512_sub_epi8(_mm512_setzero_si512(), y))", f643, 0, 512},
  {"512:_mm512_and_si512(x, _mm512_sub_epi8(_mm512_setzero_si512(), x))", f644, 0, 512},
  {"512:_mm512_and_si512(_mm512_sub_epi8(_mm512_setzero_si512(), x), x)", f645, 0, 512},
  {"512:_mm512_sub_epi8(_mm512_setzero_si512(), _mm512_or_si512(x, y))", f646, 0, 512},
  {"512:_mm512_or_si512(_mm512_sub_epi8(_mm512_setzero_si512(), x), y)", f647, 0, 512},
  {"512:_mm512_or_si512(x, _mm512_sub_epi8(_mm512_setzero_si512(), y))", f648, 0, 512},
  {"512:_mm512_or_si512(_mm512_sub_epi8(_mm512_setzero_si512(), x), _mm512_sub_epi8(_mm512_setzero_si512(), y))", f649, 0, 512},
  {"512:_mm512_or_si512(x, _mm512_sub_epi8(_mm512_setzero_si512(), x))", f650, 0, 512},
  {"512:_mm512_or_si512(_mm512_sub_epi8(_mm512_setzero_si512(), x), x)", f651, 0, 512},
  {"512:_mm512_sub_epi8(_mm512_setzero_si512(), _mm512_xor_si512(x, y))", f652, 0, 512},
  {"512:_mm512_xor_si512(_mm512_sub_epi8(_mm512_setzero_si512(), x), y)", f653, 0, 512},
  {"512:_mm512_xor_si512(x, _mm512_sub_epi8(_mm512_setzero_si512(), y))", f654, 0, 512},
  {"512:_mm512_xor_si512(_mm512_sub_epi8(_mm512_setzero_si512(), x), _mm512_sub_epi8(_mm512_setzero_si512(), y))", f655, 0, 512},
  {"512:_mm512_xor_si512(x, _mm512_sub_epi8(_mm512_setzero_si512(), x))", f656, 0, 512},
  {"512:_mm512_xor_si512(_mm512_sub_epi8(_mm512_setzero_si512(), x), x)", f657, 0, 512},
  {"512:_mm512_sub_epi8(_mm512_setzero_si512(), _mm512_andnot_si512(x, y))", f658, 0, 512},
  {"512:_mm512_andnot_si512(_mm512_sub_epi8(_mm512_setzero_si512(), x), y)", f659, 0, 512},
  {"512:_mm512_andnot_si512(x, _mm512_sub_epi8(_mm512_setzero_si512(), y))", f660, 0, 512},
  {"512:_mm512_andnot_si512(_mm512_sub_epi8(_mm512_setzero_si512(), x), _mm512_sub_epi8(_mm512_setzero_si512(), y))", f661, 0, 512},
  {"512:_mm512_andnot_si512(x, _mm512_sub_epi8(_mm512_setzero_si512(), x))", f662, 0, 512},
  {"512:_mm512_andnot_si512(_mm512_sub_epi8(_mm512_setzero_si512(), x), x)", f663, 0, 512},
  {"512:_mm512_sub_epi16(_mm512_setzero_si512(), _mm512_add_epi16(x, y))", f664, 0, 512},
  {"512:_mm512_add_epi16(_mm512_sub_epi16(_mm512_setzero_si512(), x), y)", f665, 0, 512},
  {"512:_mm512_add_epi16(x, _mm512_sub_epi16(_mm512_setzero_si512(), y))", f666, 0, 512},
  {"512:_mm512_add_epi16(_mm512_sub_epi16(_mm512_setzero_si512(), x), _mm512_sub_epi16(_mm512_setzero_si512(), y))", f667, 0, 512},
  {"512:_mm512_add_epi16(x, _mm512_sub_epi16(_mm512_setzero_si512(), x))", f668, 0, 512},
  {"512:_mm512_add_epi16(_mm512_sub_epi16(_mm512_setzero_si512(), x), x)", f669, 0, 512},
  {"512:_mm512_sub_epi16(_mm512_setzero_si512(), _mm512_sub_epi16(x, y))", f670, 0, 512},
  {"512:_mm512_sub_epi16(_mm512_sub_epi16(_mm512_setzero_si512(), x), y)", f671, 0, 512},
  {"512:_mm512_sub_epi16(x, _mm512_sub_epi16(_mm512_setzero_si512(), y))", f672, 0, 512},
  {"512:_mm512_sub_epi16(_mm512_sub_epi16(_mm512_setzero_si512(), x), _mm512_sub_epi16(_mm512_setzero_si512(), y))", f673, 0, 512},
  {"512:_mm512_sub_epi16(x, _mm512_sub_epi16(_mm512_setzero_si512(), x))", f674, 0, 512},
  {"512:_mm512_sub_epi16(_mm512_sub_epi16(_mm512_setzero_si512(), x), x)", f675, 0, 512},
  {"512:_mm512_sub_epi16(_mm512_setzero_si512(), _mm512_adds_epi16(x, y))", f676, 0, 512},
  {"512:_mm512_adds_epi16(_mm512_sub_epi16(_mm512_setzero_si512(), x), y)", f677, 0, 512},
  {"512:_mm512_adds_epi16(x, _mm512_sub_epi16(_mm512_setzero_si512(), y))", f678, 0, 512},
  {"512:_mm512_adds_epi16(_mm512_sub_epi16(_mm512_setzero_si512(), x), _mm512_sub_epi16(_mm512_setzero_si512(), y))", f679, 0, 512},
  {"512:_mm512_adds_epi16(x, _mm512_sub_epi16(_mm512_setzero_si512(), x))", f680, 0, 512},
  {"512:_mm512_adds_epi16(_mm512_sub_epi16(_mm512_setzero_si512(), x), x)", f681, 0, 512},
  {"512:_mm512_sub_epi16(_mm512_setzero_si512(), _mm512_subs_epi16(x, y))", f682, 0, 512},
  {"512:_mm512_subs_epi16(_mm512_sub_epi16(_mm512_setzero_si512(), x), y)", f683, 0, 512},
  {"512:_mm512_subs_epi16(x, _mm512_sub_epi16(_mm512_setzero_si512(), y))", f684, 0, 512},
  {"512:_mm512_subs_epi16(_mm512_sub_epi16(_mm512_setzero_si512(), x), _mm512_sub_epi16(_mm512_setzero_si512(), y))", f685, 0, 512},
  {"512:_mm512_subs_epi16(x, _mm512_sub_epi16(_mm512_setzero_si512(), x))", f686, 0, 512},
  {"512:_mm512_subs_epi16(_mm512_sub_epi16(_mm512_setzero_si512(), x), x)", f687, 0, 512},
  {"512:_mm512_sub_epi16(_mm512_setzero_si512(), _mm512_adds_epu16(x, y))", f688, 0, 512},
  {"512:_mm512_adds_epu16(_mm512_sub_epi16(_mm512_setzero_si512(), x), y)", f689, 0, 512},
  {"512:_mm512_adds_epu16(x, _mm512_sub_epi16(_mm512_setzero_si512(), y))", f690, 0, 512},
  {"512:_mm512_adds_epu16(_mm512_sub_epi16(_mm512_setzero_si512(), x), _mm512_sub_epi16(_mm512_setzero_si512(), y))", f691, 0, 512},
  {"512:_mm512_adds_epu16(x, _mm512_sub_epi16(_mm512_setzero_si512(), x))", f692, 0, 512},
  {"512:_mm512_adds_epu16(_mm512_sub_epi16(_mm512_setzero_si512(), x), x)", f693, 0, 512},
  {"512:_mm512_sub_epi16(_mm512_setzero_si512(), _mm512_subs_epu16(x, y))", f694, 0, 512},
  {"512:_mm512_subs_epu16(_mm512_sub_epi16(_mm512_setzero_si512(), x), y)", f695, 0, 512},
  {"512:_mm512_subs_epu16(x, _mm512_sub_epi16(_mm512_setzero_si512(), y))", f696, 0, 512},
  {"512:_mm512_subs_epu16(_mm512_sub_epi16(_mm512_setzero_si512(), x), _mm512_sub_epi16(_mm512_setzero_si512(), y))", f697, 0, 512},
  {"512:_mm512_subs_epu16(x, _mm512_sub_epi16(_mm512_setzero_si512(), x))", f698, 0, 512},
  {"512:_mm512_subs_epu16(_mm512_sub_epi16(_mm512_setzero_si512(), x), x)", f699, 0, 512},
  {"512:_mm512_sub_epi16(_mm512_setzero_si512(), _mm512_avg_epu16(x, y))", f700, 0, 512},
  {"512:_mm512_avg_epu16(_mm512_sub_epi16(_mm512_setzero_si512(), x), y)", f701, 0, 512},
  {"512:_mm512_avg_epu16(x, _mm512_sub_epi16(_mm512_setzero_si512(), y))", f702, 0, 512},
  {"512:_mm512_avg_epu16(_mm512_sub_epi16(_mm512_setzero_si512(), x), _mm512_sub_epi16(_mm512_setzero_si512(), y))", f703, 0, 512},
  {"512:_mm512_avg_epu16(x, _mm512_sub_epi16(_mm512_setzero_si512(), x))", f704, 0, 512},
  {"512:_mm512_avg_epu16(_mm512_sub_epi16(_mm512_setzero_si512(), x), x)", f705, 0, 512},
  {"512:_mm512_sub_epi16(_mm512_setzero_si512(), _mm512_min_epi16(x, y))", f706, 0, 512},
  {"512:_mm512_min_epi16(_mm512_sub_epi16(_mm512_setzero_si512(), x), y)", f707, 0, 512},
  {"512:_mm512_min_epi16(x, _mm512_sub_epi16(_mm512_setzero_si512(), y))", f708, 0, 512},
  {"512:_mm512_min_epi16(_mm512_sub_epi16(_mm512_setzero_si512(), x), _mm512_sub_epi16(_mm512_setzero_si512(), y))", f709, 0, 512},
  {"512:_mm512_min_epi16(x, _mm512_sub_epi16(_mm512_setzero_si512(), x))", f710, 0, 512},
  {"512:_mm512_min_epi16(_mm512_sub_epi16(_mm512_setzero_si512(), x), x)", f711, 0, 512},
  {"512:_mm512_sub_epi16(_mm512_setzero_si512(), _mm512_max_epi16(x, y))", f712, 0, 512},
  {"512:_mm512_max_epi16(_mm512_sub_epi16(_mm512_setzero_si512(), x), y)", f713, 0, 512},
  {"512:_mm512_max_epi16(x, _mm512_sub_epi16(_mm512_setzero_si512(), y))", f714, 0, 512},
  {"512:_mm512_max_epi16(_mm512_sub_epi16(_mm512_setzero_si512(), x), _mm512_sub_epi16(_mm512_setzero_si512(), y))", f715, 0, 512},
  {"512:_mm512_max_epi16(x, _mm512_sub_epi16(_mm512_setzero_si512(), x))", f716, 0, 512},
  {"512:_mm512_max_epi16(_mm512_sub_epi16(_mm512_setzero_si512(), x), x)", f717, 0, 512},
  {"512:_mm512_sub_epi16(_mm512_setzero_si512(), _mm512_min_epu16(x, y))", f718, 0, 512},
  {"512:_mm512_min_epu16(_mm512_sub_epi16(_mm512_setzero_si512(), x), y)", f719, 0, 512},
  {"512:_mm512_min_epu16(x, _mm512_sub_epi16(_mm512_setzero_si512(), y))", f720, 0, 512},
  {"512:_mm512_min_epu16(_mm512_sub_epi16(_mm512_setzero_si512(), x), _mm512_sub_epi16(_mm512_setzero_si512(), y))", f721, 0, 512},
  {"512:_mm512_min_epu16(x, _mm512_sub_epi16(_mm512_setzero_si512(), x))", f722, 0, 512},
  {"512:_mm512_min_epu16(_mm512_sub_epi16(_mm512_setzero_si512(), x), x)", f723, 0, 512},
  {"512:_mm512_sub_epi16(_mm512_setzero_si512(), _mm512_max_epu16(x, y))", f724, 0, 512},
  {"512:_mm512_max_epu16(_mm512_sub_epi16(_mm512_setzero_si512(), x), y)", f725, 0, 512},
  {"512:_mm512_max_epu16(x, _mm512_sub_epi16(_mm512_setzero_si512(), y))", f726, 0, 512},
  {"512:_mm512_max_epu16(_mm512_sub_epi16(_mm512_setzero_si512(), x), _mm512_sub_epi16(_mm512_setzero_si512(), y))", f727, 0, 512},
  {"512:_mm512_max_epu16(x, _mm512_sub_epi16(_mm512_setzero_si512(), x))", f728, 0, 512},
  {"512:_mm512_max_epu16(_mm512_sub_epi16(_mm512_setzero_si512(), x), x)", f729, 0, 512},
  {"512:_mm512_sub_epi16(_mm512_setzero_si512(), _mm512_and_si512(x, y))", f730, 0, 512},
  {"512:_mm512_and_si512(_mm512_sub_epi16(_mm512_setzero_si512(), x), y)", f731, 0, 512},
  {"512:_mm512_and_si512(x, _mm512_sub_epi16(_mm512_setzero_si512(), y))", f732, 0, 512},
  {"512:_mm512_and_si512(_mm512_sub_epi16(_mm512_setzero_si512(), x), _mm512_sub_epi16(_mm512_setzero_si512(), y))", f733, 0, 512},
  {"512:_mm512_and_si512(x, _mm512_sub_epi16(_mm512_setzero_si512(), x))", f734, 0, 512},
  {"512:_mm512_and_si512(_mm512_sub_epi16(_mm512_setzero_si512(), x), x)", f735, 0, 512},
  {"512:_mm512_sub_epi16(_mm512_setzero_si512(), _mm512_or_si512(x, y))", f736, 0, 512},
  {"512:_mm512_or_si512(_mm512_sub_epi16(_mm512_setzero_si512(), x), y)", f737, 0, 512},
  {"512:_mm512_or_si512(x, _mm512_sub_epi16(_mm512_setzero_si512(), y))", f738, 0, 512},
  {"512:_mm512_or_si512(_mm512_sub_epi16(_mm512_setzero_si512(), x), _mm512_sub_epi16(_mm512_setzero_si512(), y))", f739, 0, 512},
  {"512:_mm512_or_si512(x, _mm512_sub_epi16(_mm512_setzero_si512(), x))", f740, 0, 512},
  {"512:_mm512_or_si512(_mm512_sub_epi16(_mm512_setzero_si512(), x), x)", f741, 0, 512},
  {"512:_mm512_sub_epi16(_mm512_setzero_si512(), _mm512_xor_si512(x, y))", f742, 0, 512},
  {"512:_mm512_xor_si512(_mm512_sub_epi16(_mm512_setzero_si512(), x), y)", f743, 0, 512},
  {"512:_mm512_xor_si512(x, _mm512_sub_epi16(_mm512_setzero_si512(), y))", f744, 0, 512},
  {"512:_mm512_xor_si512(_mm512_sub_epi16(_mm512_setzero_si512(), x), _mm512_sub_epi16(_mm512_setzero_si512(), y))", f745, 0, 512},
  {"512:_mm512_xor_si512(x, _mm512_sub_epi16(_mm512_setzero_si512(), x))", f746, 0, 512},
  {"512:_mm512_xor_si512(_mm512_sub_epi16(_mm512_setzero_si512(), x), x)", f747, 0, 512},
  {"512:_mm512_sub_epi16(_mm512_setzero_si512(), _mm512_andnot_si512(x, y))", f748, 0, 512},
  {"512:_mm512_andnot_si512(_mm512_sub_epi16(_mm512_setzero_si512(), x), y)", f749, 0, 512},
  {"512:_mm512_andnot_si512(x, _mm512_sub_epi16(_mm512_setzero_si512(), y))", f750, 0, 512},
  {"512:_mm512_andnot_si512(_mm512_sub_epi16(_mm512_setzero_si512(), x), _mm512_sub_epi16(_mm512_setzero_si512(), y))", f751, 0, 512},
  {"512:_mm512_andnot_si512(x, _mm512_sub_epi16(_mm512_setzero_si512(), x))", f752, 0, 512},
  {"512:_mm512_andnot_si512(_mm512_sub_epi16(_mm512_setzero_si512(), x), x)", f753, 0, 512},
  {"512:_mm512_sub_epi16(_mm512_setzero_si512(), _mm512_mullo_epi16(x, y))", f754, 0, 512},
  {"512:_mm512_mullo_epi16(_mm512_sub_epi16(_mm512_setzero_si512(), x), y)", f755, 0, 512},
  {"512:_mm512_mullo_epi16(x, _mm512_sub_epi16(_mm512_setzero_si512(), y))", f756, 0, 512},
  {"512:_mm512_mullo_epi16(_mm512_sub_epi16(_mm512_setzero_si512(), x), _mm512_sub_epi16(_mm512_setzero_si512(), y))", f757, 0, 512},
  {"512:_mm512_mullo_epi16(x, _mm512_sub_epi16(_mm512_setzero_si512(), x))", f758, 0, 512},
  {"512:_mm512_mullo_epi16(_mm512_sub_epi16(_mm512_setzero_si512(), x), x)", f759, 0, 512},
  {"512:_mm512_sub_epi16(_mm512_setzero_si512(), _mm512_mulhi_epi16(x, y))", f760, 0, 512},
  {"512:_mm512_mulhi_epi16(_mm512_sub_epi16(_mm512_setzero_si512(), x), y)", f761, 0, 512},
  {"512:_mm512_mulhi_epi16(x, _mm512_sub_epi16(_mm512_setzero_si512(), y))", f762, 0, 512},
  {"512:_mm512_mulhi_epi16(_mm512_sub_epi16(_mm512_setzero_si512(), x), _mm512_sub_epi16(_mm512_setzero_si512(), y))", f763, 0, 512},
  {"512:_mm512_mulhi_epi16(x, _mm512_sub_epi16(_mm512_setzero_si512(), x))", f764, 0, 512},
  {"512:_mm512_mulhi_epi16(_mm512_sub_epi16(_mm512_setzero_si512(), x), x)", f765, 0, 512},
  {"512:_mm512_sub_epi16(_mm512_setzero_si512(), _mm512_mulhi_epu16(x, y))", f766, 0, 512},
  {"512:_mm512_mulhi_epu16(_mm512_sub_epi16(_mm512_setzero_si512(), x), y)", f767, 0, 512},
  {"512:_mm512_mulhi_epu16(x, _mm512_sub_epi16(_mm512_setzero_si512(), y))", f768, 0, 512},
  {"512:_mm512_mulhi_epu16(_mm512_sub_epi16(_mm512_setzero_si512(), x), _mm512_sub_epi16(_mm512_setzero_si512(), y))", f769, 0, 512},
  {"512:_mm512_mulhi_epu16(x, _mm512_sub_epi16(_mm512_setzero_si512(), x))", f770, 0, 512},
  {"512:_mm512_mulhi_epu16(_mm512_sub_epi16(_mm512_setzero_si512(), x), x)", f771, 0, 512},
  {"512:_mm512_sub_epi32(_mm512_setzero_si512(), _mm512_add_epi32(x, y))", f772, 0, 512},
  {"512:_mm512_add_epi32(_mm512_sub_epi32(_mm512_setzero_si512(), x), y)", f773, 0, 512},
  {"512:_mm512_add_epi32(x, _mm512_sub_epi32(_mm512_setzero_si512(), y))", f774, 0, 512},
  {"512:_mm512_add_epi32(_mm512_sub_epi32(_mm512_setzero_si512(), x), _mm512_sub_epi32(_mm512_setzero_si512(), y))", f775, 0, 512},
  {"512:_mm512_add_epi32(x, _mm512_sub_epi32(_mm512_setzero_si512(), x))", f776, 0, 512},
  {"512:_mm512_add_epi32(_mm512_sub_epi32(_mm512_setzero_si512(), x), x)", f777, 0, 512},
  {"512:_mm512_sub_epi32(_mm512_setzero_si512(), _mm512_sub_epi32(x, y))", f778, 0, 512},
  {"512:_mm512_sub_epi32(_mm512_sub_epi32(_mm512_setzero_si512(), x), y)", f779, 0, 512},
  {"512:_mm512_sub_epi32(x, _mm512_sub_epi32(_mm512_setzero_si512(), y))", f780, 0, 512},
  {"512:_mm512_sub_epi32(_mm512_sub_epi32(_mm512_setzero_si512(), x), _mm512_sub_epi32(_mm512_setzero_si512(), y))", f781, 0, 512},
  {"512:_mm512_sub_epi32(x, _mm512_sub_epi32(_mm512_setzero_si512(), x))", f782, 0, 512},
  {"512:_mm512_sub_epi32(_mm512_sub_epi32(_mm512_setzero_si512(), x), x)", f783, 0, 512},
  {"512:_mm512_sub_epi32(_mm512_setzero_si512(), _mm512_min_epi32(x, y))", f784, 0, 512},
  {"512:_mm512_min_epi32(_mm512_sub_epi32(_mm512_setzero_si512(), x), y)", f785, 0, 512},
  {"512:_mm512_min_epi32(x, _mm512_sub_epi32(_mm512_setzero_si512(), y))", f786, 0, 512},
  {"512:_mm512_min_epi32(_mm512_sub_epi32(_mm512_setzero_si512(), x), _mm512_sub_epi32(_mm512_setzero_si512(), y))", f787, 0, 512},
  {"512:_mm512_min_epi32(x, _mm512_sub_epi32(_mm512_setzero_si512(), x))", f788, 0, 512},
  {"512:_mm512_min_epi32(_mm512_sub_epi32(_mm512_setzero_si512(), x), x)", f789, 0, 512},
  {"512:_mm512_sub_epi32(_mm512_setzero_si512(), _mm512_max_epi32(x, y))", f790, 0, 512},
  {"512:_mm512_max_epi32(_mm512_sub_epi32(_mm512_setzero_si512(), x), y)", f791, 0, 512},
  {"512:_mm512_max_epi32(x, _mm512_sub_epi32(_mm512_setzero_si512(), y))", f792, 0, 512},
  {"512:_mm512_max_epi32(_mm512_sub_epi32(_mm512_setzero_si512(), x), _mm512_sub_epi32(_mm512_setzero_si512(), y))", f793, 0, 512},
  {"512:_mm512_max_epi32(x, _mm512_sub_epi32(_mm512_setzero_si512(), x))", f794, 0, 512},
  {"512:_mm512_max_epi32(_mm512_sub_epi32(_mm512_setzero_si512(), x), x)", f795, 0, 512},
  {"512:_mm512_sub_epi32(_mm512_setzero_si512(), _mm512_min_epu32(x, y))", f796, 0, 512},
  {"512:_mm512_min_epu32(_mm512_sub_epi32(_mm512_setzero_si512(), x), y)", f797, 0, 512},
  {"512:_mm512_min_epu32(x, _mm512_sub_epi32(_mm512_setzero_si512(), y))", f798, 0, 512},
  {"512:_mm512_min_epu32(_mm512_sub_epi32(_mm512_setzero_si512(), x), _mm512_sub_epi32(_mm512_setzero_si512(), y))", f799, 0, 512},
  {"512:_mm512_min_epu32(x, _mm512_sub_epi32(_mm512_setzero_si512(), x))", f800, 0, 512},
  {"512:_mm512_min_epu32(_mm512_sub_epi32(_mm512_setzero_si512(), x), x)", f801, 0, 512},
  {"512:_mm512_sub_epi32(_mm512_setzero_si512(), _mm512_max_epu32(x, y))", f802, 0, 512},
  {"512:_mm512_max_epu32(_mm512_sub_epi32(_mm512_setzero_si512(), x), y)", f803, 0, 512},
  {"512:_mm512_max_epu32(x, _mm512_sub_epi32(_mm512_setzero_si512(), y))", f804, 0, 512},
  {"512:_mm512_max_epu32(_mm512_sub_epi32(_mm512_setzero_si512(), x), _mm512_sub_epi32(_mm512_setzero_si512(), y))", f805, 0, 512},
  {"512:_mm512_max_epu32(x, _mm512_sub_epi32(_mm512_setzero_si512(), x))", f806, 0, 512},
  {"512:_mm512_max_epu32(_mm512_sub_epi32(_mm512_setzero_si512(), x), x)", f807, 0, 512},
  {"512:_mm512_sub_epi32(_mm512_setzero_si512(), _mm512_and_si512(x, y))", f808, 0, 512},
  {"512:_mm512_and_si512(_mm512_sub_epi32(_mm512_setzero_si512(), x), y)", f809, 0, 512},
  {"512:_mm512_and_si512(x, _mm512_sub_epi32(_mm512_setzero_si512(), y))", f810, 0, 512},
  {"512:_mm512_and_si512(_mm512_sub_epi32(_mm512_setzero_si512(), x), _mm512_sub_epi32(_mm512_setzero_si512(), y))", f811, 0, 512},
  {"512:_mm512_and_si512(x, _mm512_sub_epi32(_mm512_setzero_si512(), x))", f812, 0, 512},
  {"512:_mm512_and_si512(_mm512_sub_epi32(_mm512_setzero_si512(), x), x)", f813, 0, 512},
  {"512:_mm512_sub_epi32(_mm512_setzero_si512(), _mm512_or_si512(x, y))", f814, 0, 512},
  {"512:_mm512_or_si512(_mm512_sub_epi32(_mm512_setzero_si512(), x), y)", f815, 0, 512},
  {"512:_mm512_or_si512(x, _mm512_sub_epi32(_mm512_setzero_si512(), y))", f816, 0, 512},
  {"512:_mm512_or_si512(_mm512_sub_epi32(_mm512_setzero_si512(), x), _mm512_sub_epi32(_mm512_setzero_si512(), y))", f817, 0, 512},
  {"512:_mm512_or_si512(x, _mm512_sub_epi32(_mm512_setzero_si512(), x))", f818, 0, 512},
  {"512:_mm512_or_si512(_mm512_sub_epi32(_mm512_setzero_si512(), x), x)", f819, 0, 512},
  {"512:_mm512_sub_epi32(_mm512_setzero_si512(), _mm512_xor_si512(x, y))", f820, 0, 512},
  {"512:_mm512_xor_si512(_mm512_sub_epi32(_mm512_setzero_si512(), x), y)", f821, 0, 512},
  {"512:_mm512_xor_si512(x, _mm512_sub_epi32(_mm512_setzero_si512(), y))", f822, 0, 512},
  {"512:_mm512_xor_si512(_mm512_sub_epi32(_mm512_setzero_si512(), x), _mm512_sub_epi32(_mm512_setzero_si512(), y))", f823, 0, 512},
  {"512:_mm512_xor_si512(x, _mm512_sub_epi32(_mm512_setzero_si512(), x))", f824, 0, 512},
  {"512:_mm512_xor_si512(_mm512_sub_epi32(_mm512_setzero_si512(), x), x)", f825, 0, 512},
  {"512:_mm512_sub_epi32(_mm512_setzero_si512(), _mm512_andnot_si512(x, y))", f826, 0, 512},
  {"512:_mm512_andnot_si512(_mm512_sub_epi32(_mm512_setzero_si512(), x), y)", f827, 0, 512},
  {"512:_mm512_andnot_si512(x, _mm512_sub_epi32(_mm512_setzero_si512(), y))", f828, 0, 512},
  {"512:_mm512_andnot_si512(_mm512_sub_epi32(_mm512_setzero_si512(), x), _mm512_sub_epi32(_mm512_setzero_si512(), y))", f829, 0, 512},
  {"512:_mm512_andnot_si512(x, _mm512_sub_epi32(_mm512_setzero_si512(), x))", f830, 0, 512},
  {"512:_mm512_andnot_si512(_mm512_sub_epi32(_mm512_setzero_si512(), x), x)", f831, 0, 512},
  {"512:_mm512_sub_epi32(_mm512_setzero_si512(), _mm512_mullo_epi32(x, y))", f832, 0, 512},
  {"512:_mm512_mullo_epi32(_mm512_sub_epi32(_mm512_setzero_si512(), x), y)", f833, 0, 512},
  {"512:_mm512_mullo_epi32(x, _mm512_sub_epi32(_mm512_setzero_si512(), y))", f834, 0, 512},
  {"512:_mm512_mullo_epi32(_mm512_sub_epi32(_mm512_setzero_si512(), x), _mm512_sub_epi32(_mm512_setzero_si512(), y))", f835, 0, 512},
  {"512:_mm512_mullo_epi32(x, _mm512_sub_epi32(_mm512_setzero_si512(), x))", f836, 0, 512},
  {"512:_mm512_mullo_epi32(_mm512_sub_epi32(_mm512_setzero_si512(), x), x)", f837, 0, 512},
  {"512:_mm512_sub_epi32(_mm512_setzero_si512(), _mm512_sllv_epi32(x, y))", f838, 0, 512},
  {"512:_mm512_sllv_epi32(_mm512_sub_epi32(_mm512_setzero_si512(), x), y)", f839, 0, 512},
  {"512:_mm512_sllv_epi32(x, _mm512_sub_epi32(_mm512_setzero_si512(), y))", f840, 0, 512},
  {"512:_mm512_sllv_epi32(_mm512_sub_epi32(_mm512_setzero_si512(), x), _mm512_sub_epi32(_mm512_setzero_si512(), y))", f841, 0, 512},
  {"512:_mm512_sllv_epi32(x, _mm512_sub_epi32(_mm512_setzero_si512(), x))", f842, 0, 512},
  {"512:_mm512_sllv_epi32(_mm512_sub_epi32(_mm512_setzero_si512(), x), x)", f843, 0, 512},
  {"512:_mm512_sub_epi32(_mm512_setzero_si512(), _mm512_srlv_epi32(x, y))", f844, 0, 512},
  {"512:_mm512_srlv_epi32(_mm512_sub_epi32(_mm512_setzero_si512(), x), y)", f845, 0, 512},
  {"512:_mm512_srlv_epi32(x, _mm512_sub_epi32(_mm512_setzero_si512(), y))", f846, 0, 512},
  {"512:_mm512_srlv_epi32(_mm512_sub_epi32(_mm512_setzero_si512(), x), _mm512_sub_epi32(_mm512_setzero_si512(), y))", f847, 0, 512},
  {"512:_mm512_srlv_epi32(x, _mm512_sub_epi32(_mm512_setzero_si512(), x))", f848, 0, 512},
  {"512:_mm512_srlv_epi32(_mm512_sub_epi32(_mm512_setzero_si512(), x), x)", f849, 0, 512},
  {"512:_mm512_sub_epi32(_mm512_setzero_si512(), _mm512_srav_epi32(x, y))", f850, 0, 512},
  {"512:_mm512_srav_epi32(_mm512_sub_epi32(_mm512_setzero_si512(), x), y)", f851, 0, 512},
  {"512:_mm512_srav_epi32(x, _mm512_sub_epi32(_mm512_setzero_si512(), y))", f852, 0, 512},
  {"512:_mm512_srav_epi32(_mm512_sub_epi32(_mm512_setzero_si512(), x), _mm512_sub_epi32(_mm512_setzero_si512(), y))", f853, 0, 512},
  {"512:_mm512_srav_epi32(x, _mm512_sub_epi32(_mm512_setzero_si512(), x))", f854, 0, 512},
  {"512:_mm512_srav_epi32(_mm512_sub_epi32(_mm512_setzero_si512(), x), x)", f855, 0, 512},
  {"512:_mm512_sub_epi64(_mm512_setzero_si512(), _mm512_add_epi64(x, y))", f856, 0, 512},
  {"512:_mm512_add_epi64(_mm512_sub_epi64(_mm512_setzero_si512(), x), y)", f857, 0, 512},
  {"512:_mm512_add_epi64(x, _mm512_sub_epi64(_mm512_setzero_si512(), y))", f858, 0, 512},
  {"512:_mm512_add_epi64(_mm512_sub_epi64(_mm512_setzero_si512(), x), _mm512_sub_epi64(_mm512_setzero_si512(), y))", f859, 0, 512},
  {"512:_mm512_add_epi64(x, _mm512_sub_epi64(_mm512_setzero_si512(), x))", f860, 0, 512},
  {"512:_mm512_add_epi64(_mm512_sub_epi64(_mm512_setzero_si512(), x), x)", f861, 0, 512},
  {"512:_mm512_sub_epi64(_mm512_setzero_si512(), _mm512_sub_epi64(x, y))", f862, 0, 512},
  {"512:_mm512_sub_epi64(_mm512_sub_epi64(_mm512_setzero_si512(), x), y)", f863, 0, 512},
  {"512:_mm512_sub_epi64(x, _mm512_sub_epi64(_mm512_setzero_si512(), y))", f864, 0, 512},
  {"512:_mm512_sub_epi64(_mm512_sub_epi64(_mm512_setzero_si512(), x), _mm512_sub_epi64(_mm512_setzero_si512(), y))", f865, 0, 512},
  {"512:_mm512_sub_epi64(x, _mm512_sub_epi64(_mm512_setzero_si512(), x))", f866, 0, 512},
  {"512:_mm512_sub_epi64(_mm512_sub_epi64(_mm512_setzero_si512(), x), x)", f867, 0, 512},
  {"512:_mm512_sub_epi64(_mm512_setzero_si512(), _mm512_min_epi64(x, y))", f868, 0, 512},
  {"512:_mm512_min_epi64(_mm512_sub_epi64(_mm512_setzero_si512(), x), y)", f869, 0, 512},
  {"512:_mm512_min_epi64(x, _mm512_sub_epi64(_mm512_setzero_si512(), y))", f870, 0, 512},
  {"512:_mm512_min_epi64(_mm512_sub_epi64(_mm512_setzero_si512(), x), _mm512_sub_epi64(_mm512_setzero_si512(), y))", f871, 0, 512},
  {"512:_mm512_min_epi64(x, _mm512_sub_epi64(_mm512_setzero_si512(), x))", f872, 0, 512},
  {"512:_mm512_min_epi64(_mm512_sub_epi64(_mm512_setzero_si512(), x), x)", f873, 0, 512},
  {"512:_mm512_sub_epi64(_mm512_setzero_si512(), _mm512_max_epi64(x, y))", f874, 0, 512},
  {"512:_mm512_max_epi64(_mm512_sub_epi64(_mm512_setzero_si512(), x), y)", f875, 0, 512},
  {"512:_mm512_max_epi64(x, _mm512_sub_epi64(_mm512_setzero_si512(), y))", f876, 0, 512},
  {"512:_mm512_max_epi64(_mm512_sub_epi64(_mm512_setzero_si512(), x), _mm512_sub_epi64(_mm512_setzero_si512(), y))", f877, 0, 512},
  {"512:_mm512_max_epi64(x, _mm512_sub_epi64(_mm512_setzero_si512(), x))", f878, 0, 512},
  {"512:_mm512_max_epi64(_mm512_sub_epi64(_mm512_setzero_si512(), x), x)", f879, 0, 512},
  {"512:_mm512_sub_epi64(_mm512_setzero_si512(), _mm512_min_epu64(x, y))", f880, 0, 512},
  {"512:_mm512_min_epu64(_mm512_sub_epi64(_mm512_setzero_si512(), x), y)", f881, 0, 512},
  {"512:_mm512_min_epu64(x, _mm512_sub_epi64(_mm512_setzero_si512(), y))", f882, 0, 512},
  {"512:_mm512_min_epu64(_mm512_sub_epi64(_mm512_setzero_si512(), x), _mm512_sub_epi64(_mm512_setzero_si512(), y))", f883, 0, 512},
  {"512:_mm512_min_epu64(x, _mm512_sub_epi64(_mm512_setzero_si512(), x))", f884, 0, 512},
  {"512:_mm512_min_epu64(_mm512_sub_epi64(_mm512_setzero_si512(), x), x)", f885, 0, 512},
  {"512:_mm512_sub_epi64(_mm512_setzero_si512(), _mm512_max_epu64(x, y))", f886, 0, 512},
  {"512:_mm512_max_epu64(_mm512_sub_epi64(_mm512_setzero_si512(), x), y)", f887, 0, 512},
  {"512:_mm512_max_epu64(x, _mm512_sub_epi64(_mm512_setzero_si512(), y))", f888, 0, 512},
  {"512:_mm512_max_epu64(_mm512_sub_epi64(_mm512_setzero_si512(), x), _mm512_sub_epi64(_mm512_setzero_si512(), y))", f889, 0, 512},
  {"512:_mm512_max_epu64(x, _mm512_sub_epi64(_mm512_setzero_si512(), x))", f890, 0, 512},
  {"512:_mm512_max_epu64(_mm512_sub_epi64(_mm512_setzero_si512(), x), x)", f891, 0, 512},
  {"512:_mm512_sub_epi64(_mm512_setzero_si512(), _mm512_and_si512(x, y))", f892, 0, 512},
  {"512:_mm512_and_si512(_mm512_sub_epi64(_mm512_setzero_si512(), x), y)", f893, 0, 512},
  {"512:_mm512_and_si512(x, _mm512_sub_epi64(_mm512_setzero_si512(), y))", f894, 0, 512},
  {"512:_mm512_and_si512(_mm512_sub_epi64(_mm512_setzero_si512(), x), _mm512_sub_epi64(_mm512_setzero_si512(), y))", f895, 0, 512},
  {"512:_mm512_and_si512(x, _mm512_sub_epi64(_mm512_setzero_si512(), x))", f896, 0, 512},
  {"512:_mm512_and_si512(_mm512_sub_epi64(_mm512_setzero_si512(), x), x)", f897, 0, 512},
  {"512:_mm512_sub_epi64(_mm512_setzero_si512(), _mm512_or_si512(x, y))", f898, 0, 512},
  {"512:_mm512_or_si512(_mm512_sub_epi64(_mm512_setzero_si512(), x), y)", f899, 0, 512},
  {"512:_mm512_or_si512(x, _mm512_sub_epi64(_mm512_setzero_si512(), y))", f900, 0, 512},
  {"512:_mm512_or_si512(_mm512_sub_epi64(_mm512_setzero_si512(), x), _mm512_sub_epi64(_mm512_setzero_si512(), y))", f901, 0, 512},
  {"512:_mm512_or_si512(x, _mm512_sub_epi64(_mm512_setzero_si512(), x))", f902, 0, 512},
  {"512:_mm512_or_si512(_mm512_sub_epi64(_mm512_setzero_si512(), x), x)", f903, 0, 512},
  {"512:_mm512_sub_epi64(_mm512_setzero_si512(), _mm512_xor_si512(x, y))", f904, 0, 512},
  {"512:_mm512_xor_si512(_mm512_sub_epi64(_mm512_setzero_si512(), x), y)", f905, 0, 512},
  {"512:_mm512_xor_si512(x, _mm512_sub_epi64(_mm512_setzero_si512(), y))", f906, 0, 512},
  {"512:_mm512_xor_si512(_mm512_sub_epi64(_mm512_setzero_si512(), x), _mm512_sub_epi64(_mm512_setzero_si512(), y))", f907, 0, 512},
  {"512:_mm512_xor_si512(x, _mm512_sub_epi64(_mm512_setzero_si512(), x))", f908, 0, 512},
  {"512:_mm512_xor_si512(_mm512_sub_epi64(_mm512_setzero_si512(), x), x)", f909, 0, 512},
  {"512:_mm512_sub_epi64(_mm512_setzero_si512(), _mm512_andnot_si512(x, y))", f910, 0, 512},
  {"512:_mm512_andnot_si512(_mm512_sub_epi64(_mm512_setzero_si512(), x), y)", f911, 0, 512},
  {"512:_mm512_andnot_si512(x, _mm512_sub_epi64(_mm512_setzero_si512(), y))", f912, 0, 512},
  {"512:_mm512_andnot_si512(_mm512_sub_epi64(_mm512_setzero_si512(), x), _mm512_sub_epi64(_mm512_setzero_si512(), y))", f913, 0, 512},
  {"512:_mm512_andnot_si512(x, _mm512_sub_epi64(_mm512_setzero_si512(), x))", f914, 0, 512},
  {"512:_mm512_andnot_si512(_mm512_sub_epi64(_mm512_setzero_si512(), x), x)", f915, 0, 512},
  {"512:_mm512_sub_epi64(_mm512_setzero_si512(), _mm512_sllv_epi64(x, y))", f916, 0, 512},
  {"512:_mm512_sllv_epi64(_mm512_sub_epi64(_mm512_setzero_si512(), x), y)", f917, 0, 512},
  {"512:_mm512_sllv_epi64(x, _mm512_sub_epi64(_mm512_setzero_si512(), y))", f918, 0, 512},
  {"512:_mm512_sllv_epi64(_mm512_sub_epi64(_mm512_setzero_si512(), x), _mm512_sub_epi64(_mm512_setzero_si512(), y))", f919, 0, 512},
  {"512:_mm512_sllv_epi64(x, _mm512_sub_epi64(_mm512_setzero_si512(), x))", f920, 0, 512},
  {"512:_mm512_sllv_epi64(_mm512_sub_epi64(_mm512_setzero_si512(), x), x)", f921, 0, 512},
  {"512:_mm512_sub_epi64(_mm512_setzero_si512(), _mm512_srlv_epi64(x, y))", f922, 0, 512},
  {"512:_mm512_srlv_epi64(_mm512_sub_epi64(_mm512_setzero_si512(), x), y)", f923, 0, 512},
  {"512:_mm512_srlv_epi64(x, _mm512_sub_epi64(_mm512_setzero_si512(), y))", f924, 0, 512},
  {"512:_mm512_srlv_epi64(_mm512_sub_epi64(_mm512_setzero_si512(), x), _mm512_sub_epi64(_mm512_setzero_si512(), y))", f925, 0, 512},
  {"512:_mm512_srlv_epi64(x, _mm512_sub_epi64(_mm512_setzero_si512(), x))", f926, 0, 512},
  {"512:_mm512_srlv_epi64(_mm512_sub_epi64(_mm512_setzero_si512(), x), x)", f927, 0, 512},
  {"512:_mm512_xor_si512(_mm512_add_epi8(x, y), _mm512_set1_epi8((char)0xffu))", f928, 0, 512},
  {"512:_mm512_add_epi8(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), y)", f929, 0, 512},
  {"512:_mm512_add_epi8(x, _mm512_xor_si512(y, _mm512_set1_epi8((char)0xffu)))", f930, 0, 512},
  {"512:_mm512_add_epi8(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), _mm512_xor_si512(y, _mm512_set1_epi8((char)0xffu)))", f931, 0, 512},
  {"512:_mm512_add_epi8(x, _mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)))", f932, 0, 512},
  {"512:_mm512_add_epi8(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), x)", f933, 0, 512},
  {"512:_mm512_xor_si512(_mm512_sub_epi8(x, y), _mm512_set1_epi8((char)0xffu))", f934, 0, 512},
  {"512:_mm512_sub_epi8(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), y)", f935, 0, 512},
  {"512:_mm512_sub_epi8(x, _mm512_xor_si512(y, _mm512_set1_epi8((char)0xffu)))", f936, 0, 512},
  {"512:_mm512_sub_epi8(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), _mm512_xor_si512(y, _mm512_set1_epi8((char)0xffu)))", f937, 0, 512},
  {"512:_mm512_sub_epi8(x, _mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)))", f938, 0, 512},
  {"512:_mm512_sub_epi8(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), x)", f939, 0, 512},
  {"512:_mm512_xor_si512(_mm512_add_epi16(x, y), _mm512_set1_epi8((char)0xffu))", f940, 0, 512},
  {"512:_mm512_add_epi16(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), y)", f941, 0, 512},
  {"512:_mm512_add_epi16(x, _mm512_xor_si512(y, _mm512_set1_epi8((char)0xffu)))", f942, 0, 512},
  {"512:_mm512_add_epi16(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), _mm512_xor_si512(y, _mm512_set1_epi8((char)0xffu)))", f943, 0, 512},
  {"512:_mm512_add_epi16(x, _mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)))", f944, 0, 512},
  {"512:_mm512_add_epi16(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), x)", f945, 0, 512},
  {"512:_mm512_xor_si512(_mm512_sub_epi16(x, y), _mm512_set1_epi8((char)0xffu))", f946, 0, 512},
  {"512:_mm512_sub_epi16(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), y)", f947, 0, 512},
  {"512:_mm512_sub_epi16(x, _mm512_xor_si512(y, _mm512_set1_epi8((char)0xffu)))", f948, 0, 512},
  {"512:_mm512_sub_epi16(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), _mm512_xor_si512(y, _mm512_set1_epi8((char)0xffu)))", f949, 0, 512},
  {"512:_mm512_sub_epi16(x, _mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)))", f950, 0, 512},
  {"512:_mm512_sub_epi16(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), x)", f951, 0, 512},
  {"512:_mm512_xor_si512(_mm512_add_epi32(x, y), _mm512_set1_epi8((char)0xffu))", f952, 0, 512},
  {"512:_mm512_add_epi32(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), y)", f953, 0, 512},
  {"512:_mm512_add_epi32(x, _mm512_xor_si512(y, _mm512_set1_epi8((char)0xffu)))", f954, 0, 512},
  {"512:_mm512_add_epi32(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), _mm512_xor_si512(y, _mm512_set1_epi8((char)0xffu)))", f955, 0, 512},
  {"512:_mm512_add_epi32(x, _mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)))", f956, 0, 512},
  {"512:_mm512_add_epi32(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), x)", f957, 0, 512},
  {"512:_mm512_xor_si512(_mm512_sub_epi32(x, y), _mm512_set1_epi8((char)0xffu))", f958, 0, 512},
  {"512:_mm512_sub_epi32(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), y)", f959, 0, 512},
  {"512:_mm512_sub_epi32(x, _mm512_xor_si512(y, _mm512_set1_epi8((char)0xffu)))", f960, 0, 512},
  {"512:_mm512_sub_epi32(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), _mm512_xor_si512(y, _mm512_set1_epi8((char)0xffu)))", f961, 0, 512},
  {"512:_mm512_sub_epi32(x, _mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)))", f962, 0, 512},
  {"512:_mm512_sub_epi32(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), x)", f963, 0, 512},
  {"512:_mm512_xor_si512(_mm512_add_epi64(x, y), _mm512_set1_epi8((char)0xffu))", f964, 0, 512},
  {"512:_mm512_add_epi64(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), y)", f965, 0, 512},
  {"512:_mm512_add_epi64(x, _mm512_xor_si512(y, _mm512_set1_epi8((char)0xffu)))", f966, 0, 512},
  {"512:_mm512_add_epi64(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), _mm512_xor_si512(y, _mm512_set1_epi8((char)0xffu)))", f967, 0, 512},
  {"512:_mm512_add_epi64(x, _mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)))", f968, 0, 512},
  {"512:_mm512_add_epi64(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), x)", f969, 0, 512},
  {"512:_mm512_xor_si512(_mm512_sub_epi64(x, y), _mm512_set1_epi8((char)0xffu))", f970, 0, 512},
  {"512:_mm512_sub_epi64(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), y)", f971, 0, 512},
  {"512:_mm512_sub_epi64(x, _mm512_xor_si512(y, _mm512_set1_epi8((char)0xffu)))", f972, 0, 512},
  {"512:_mm512_sub_epi64(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), _mm512_xor_si512(y, _mm512_set1_epi8((char)0xffu)))", f973, 0, 512},
  {"512:_mm512_sub_epi64(x, _mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)))", f974, 0, 512},
  {"512:_mm512_sub_epi64(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), x)", f975, 0, 512},
  {"512:_mm512_xor_si512(_mm512_adds_epi8(x, y), _mm512_set1_epi8((char)0xffu))", f976, 0, 512},
  {"512:_mm512_adds_epi8(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), y)", f977, 0, 512},
  {"512:_mm512_adds_epi8(x, _mm512_xor_si512(y, _mm512_set1_epi8((char)0xffu)))", f978, 0, 512},
  {"512:_mm512_adds_epi8(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), _mm512_xor_si512(y, _mm512_set1_epi8((char)0xffu)))", f979, 0, 512},
  {"512:_mm512_adds_epi8(x, _mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)))", f980, 0, 512},
  {"512:_mm512_adds_epi8(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), x)", f981, 0, 512},
  {"512:_mm512_xor_si512(_mm512_subs_epi8(x, y), _mm512_set1_epi8((char)0xffu))", f982, 0, 512},
  {"512:_mm512_subs_epi8(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), y)", f983, 0, 512},
  {"512:_mm512_subs_epi8(x, _mm512_xor_si512(y, _mm512_set1_epi8((char)0xffu)))", f984, 0, 512},
  {"512:_mm512_subs_epi8(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), _mm512_xor_si512(y, _mm512_set1_epi8((char)0xffu)))", f985, 0, 512},
  {"512:_mm512_subs_epi8(x, _mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)))", f986, 0, 512},
  {"512:_mm512_subs_epi8(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), x)", f987, 0, 512},
  {"512:_mm512_xor_si512(_mm512_adds_epu8(x, y), _mm512_set1_epi8((char)0xffu))", f988, 0, 512},
  {"512:_mm512_adds_epu8(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), y)", f989, 0, 512},
  {"512:_mm512_adds_epu8(x, _mm512_xor_si512(y, _mm512_set1_epi8((char)0xffu)))", f990, 0, 512},
  {"512:_mm512_adds_epu8(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), _mm512_xor_si512(y, _mm512_set1_epi8((char)0xffu)))", f991, 0, 512},
  {"512:_mm512_adds_epu8(x, _mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)))", f992, 0, 512},
  {"512:_mm512_adds_epu8(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), x)", f993, 0, 512},
  {"512:_mm512_xor_si512(_mm512_subs_epu8(x, y), _mm512_set1_epi8((char)0xffu))", f994, 0, 512},
  {"512:_mm512_subs_epu8(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), y)", f995, 0, 512},
  {"512:_mm512_subs_epu8(x, _mm512_xor_si512(y, _mm512_set1_epi8((char)0xffu)))", f996, 0, 512},
  {"512:_mm512_subs_epu8(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), _mm512_xor_si512(y, _mm512_set1_epi8((char)0xffu)))", f997, 0, 512},
  {"512:_mm512_subs_epu8(x, _mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)))", f998, 0, 512},
  {"512:_mm512_subs_epu8(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), x)", f999, 0, 512},
  {"512:_mm512_xor_si512(_mm512_avg_epu8(x, y), _mm512_set1_epi8((char)0xffu))", f1000, 0, 512},
  {"512:_mm512_avg_epu8(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), y)", f1001, 0, 512},
  {"512:_mm512_avg_epu8(x, _mm512_xor_si512(y, _mm512_set1_epi8((char)0xffu)))", f1002, 0, 512},
  {"512:_mm512_avg_epu8(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), _mm512_xor_si512(y, _mm512_set1_epi8((char)0xffu)))", f1003, 0, 512},
  {"512:_mm512_avg_epu8(x, _mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)))", f1004, 0, 512},
  {"512:_mm512_avg_epu8(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), x)", f1005, 0, 512},
  {"512:_mm512_xor_si512(_mm512_adds_epi16(x, y), _mm512_set1_epi8((char)0xffu))", f1006, 0, 512},
  {"512:_mm512_adds_epi16(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), y)", f1007, 0, 512},
  {"512:_mm512_adds_epi16(x, _mm512_xor_si512(y, _mm512_set1_epi8((char)0xffu)))", f1008, 0, 512},
  {"512:_mm512_adds_epi16(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), _mm512_xor_si512(y, _mm512_set1_epi8((char)0xffu)))", f1009, 0, 512},
  {"512:_mm512_adds_epi16(x, _mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)))", f1010, 0, 512},
  {"512:_mm512_adds_epi16(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), x)", f1011, 0, 512},
  {"512:_mm512_xor_si512(_mm512_subs_epi16(x, y), _mm512_set1_epi8((char)0xffu))", f1012, 0, 512},
  {"512:_mm512_subs_epi16(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), y)", f1013, 0, 512},
  {"512:_mm512_subs_epi16(x, _mm512_xor_si512(y, _mm512_set1_epi8((char)0xffu)))", f1014, 0, 512},
  {"512:_mm512_subs_epi16(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), _mm512_xor_si512(y, _mm512_set1_epi8((char)0xffu)))", f1015, 0, 512},
  {"512:_mm512_subs_epi16(x, _mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)))", f1016, 0, 512},
  {"512:_mm512_subs_epi16(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), x)", f1017, 0, 512},
  {"512:_mm512_xor_si512(_mm512_adds_epu16(x, y), _mm512_set1_epi8((char)0xffu))", f1018, 0, 512},
  {"512:_mm512_adds_epu16(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), y)", f1019, 0, 512},
  {"512:_mm512_adds_epu16(x, _mm512_xor_si512(y, _mm512_set1_epi8((char)0xffu)))", f1020, 0, 512},
  {"512:_mm512_adds_epu16(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), _mm512_xor_si512(y, _mm512_set1_epi8((char)0xffu)))", f1021, 0, 512},
  {"512:_mm512_adds_epu16(x, _mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)))", f1022, 0, 512},
  {"512:_mm512_adds_epu16(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), x)", f1023, 0, 512},
  {"512:_mm512_xor_si512(_mm512_subs_epu16(x, y), _mm512_set1_epi8((char)0xffu))", f1024, 0, 512},
  {"512:_mm512_subs_epu16(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), y)", f1025, 0, 512},
  {"512:_mm512_subs_epu16(x, _mm512_xor_si512(y, _mm512_set1_epi8((char)0xffu)))", f1026, 0, 512},
  {"512:_mm512_subs_epu16(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), _mm512_xor_si512(y, _mm512_set1_epi8((char)0xffu)))", f1027, 0, 512},
  {"512:_mm512_subs_epu16(x, _mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)))", f1028, 0, 512},
  {"512:_mm512_subs_epu16(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), x)", f1029, 0, 512},
  {"512:_mm512_xor_si512(_mm512_avg_epu16(x, y), _mm512_set1_epi8((char)0xffu))", f1030, 0, 512},
  {"512:_mm512_avg_epu16(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), y)", f1031, 0, 512},
  {"512:_mm512_avg_epu16(x, _mm512_xor_si512(y, _mm512_set1_epi8((char)0xffu)))", f1032, 0, 512},
  {"512:_mm512_avg_epu16(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), _mm512_xor_si512(y, _mm512_set1_epi8((char)0xffu)))", f1033, 0, 512},
  {"512:_mm512_avg_epu16(x, _mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)))", f1034, 0, 512},
  {"512:_mm512_avg_epu16(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), x)", f1035, 0, 512},
  {"512:_mm512_xor_si512(_mm512_min_epi8(x, y), _mm512_set1_epi8((char)0xffu))", f1036, 0, 512},
  {"512:_mm512_min_epi8(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), y)", f1037, 0, 512},
  {"512:_mm512_min_epi8(x, _mm512_xor_si512(y, _mm512_set1_epi8((char)0xffu)))", f1038, 0, 512},
  {"512:_mm512_min_epi8(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), _mm512_xor_si512(y, _mm512_set1_epi8((char)0xffu)))", f1039, 0, 512},
  {"512:_mm512_min_epi8(x, _mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)))", f1040, 0, 512},
  {"512:_mm512_min_epi8(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), x)", f1041, 0, 512},
  {"512:_mm512_xor_si512(_mm512_max_epi8(x, y), _mm512_set1_epi8((char)0xffu))", f1042, 0, 512},
  {"512:_mm512_max_epi8(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), y)", f1043, 0, 512},
  {"512:_mm512_max_epi8(x, _mm512_xor_si512(y, _mm512_set1_epi8((char)0xffu)))", f1044, 0, 512},
  {"512:_mm512_max_epi8(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), _mm512_xor_si512(y, _mm512_set1_epi8((char)0xffu)))", f1045, 0, 512},
  {"512:_mm512_max_epi8(x, _mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)))", f1046, 0, 512},
  {"512:_mm512_max_epi8(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), x)", f1047, 0, 512},
  {"512:_mm512_xor_si512(_mm512_min_epu8(x, y), _mm512_set1_epi8((char)0xffu))", f1048, 0, 512},
  {"512:_mm512_min_epu8(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), y)", f1049, 0, 512},
  {"512:_mm512_min_epu8(x, _mm512_xor_si512(y, _mm512_set1_epi8((char)0xffu)))", f1050, 0, 512},
  {"512:_mm512_min_epu8(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), _mm512_xor_si512(y, _mm512_set1_epi8((char)0xffu)))", f1051, 0, 512},
  {"512:_mm512_min_epu8(x, _mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)))", f1052, 0, 512},
  {"512:_mm512_min_epu8(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), x)", f1053, 0, 512},
  {"512:_mm512_xor_si512(_mm512_max_epu8(x, y), _mm512_set1_epi8((char)0xffu))", f1054, 0, 512},
  {"512:_mm512_max_epu8(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), y)", f1055, 0, 512},
  {"512:_mm512_max_epu8(x, _mm512_xor_si512(y, _mm512_set1_epi8((char)0xffu)))", f1056, 0, 512},
  {"512:_mm512_max_epu8(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), _mm512_xor_si512(y, _mm512_set1_epi8((char)0xffu)))", f1057, 0, 512},
  {"512:_mm512_max_epu8(x, _mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)))", f1058, 0, 512},
  {"512:_mm512_max_epu8(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), x)", f1059, 0, 512},
  {"512:_mm512_xor_si512(_mm512_min_epi16(x, y), _mm512_set1_epi8((char)0xffu))", f1060, 0, 512},
  {"512:_mm512_min_epi16(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), y)", f1061, 0, 512},
  {"512:_mm512_min_epi16(x, _mm512_xor_si512(y, _mm512_set1_epi8((char)0xffu)))", f1062, 0, 512},
  {"512:_mm512_min_epi16(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), _mm512_xor_si512(y, _mm512_set1_epi8((char)0xffu)))", f1063, 0, 512},
  {"512:_mm512_min_epi16(x, _mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)))", f1064, 0, 512},
  {"512:_mm512_min_epi16(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), x)", f1065, 0, 512},
  {"512:_mm512_xor_si512(_mm512_max_epi16(x, y), _mm512_set1_epi8((char)0xffu))", f1066, 0, 512},
  {"512:_mm512_max_epi16(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), y)", f1067, 0, 512},
  {"512:_mm512_max_epi16(x, _mm512_xor_si512(y, _mm512_set1_epi8((char)0xffu)))", f1068, 0, 512},
  {"512:_mm512_max_epi16(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), _mm512_xor_si512(y, _mm512_set1_epi8((char)0xffu)))", f1069, 0, 512},
  {"512:_mm512_max_epi16(x, _mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)))", f1070, 0, 512},
  {"512:_mm512_max_epi16(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), x)", f1071, 0, 512},
  {"512:_mm512_xor_si512(_mm512_min_epu16(x, y), _mm512_set1_epi8((char)0xffu))", f1072, 0, 512},
  {"512:_mm512_min_epu16(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), y)", f1073, 0, 512},
  {"512:_mm512_min_epu16(x, _mm512_xor_si512(y, _mm512_set1_epi8((char)0xffu)))", f1074, 0, 512},
  {"512:_mm512_min_epu16(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), _mm512_xor_si512(y, _mm512_set1_epi8((char)0xffu)))", f1075, 0, 512},
  {"512:_mm512_min_epu16(x, _mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)))", f1076, 0, 512},
  {"512:_mm512_min_epu16(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), x)", f1077, 0, 512},
  {"512:_mm512_xor_si512(_mm512_max_epu16(x, y), _mm512_set1_epi8((char)0xffu))", f1078, 0, 512},
  {"512:_mm512_max_epu16(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), y)", f1079, 0, 512},
  {"512:_mm512_max_epu16(x, _mm512_xor_si512(y, _mm512_set1_epi8((char)0xffu)))", f1080, 0, 512},
  {"512:_mm512_max_epu16(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), _mm512_xor_si512(y, _mm512_set1_epi8((char)0xffu)))", f1081, 0, 512},
  {"512:_mm512_max_epu16(x, _mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)))", f1082, 0, 512},
  {"512:_mm512_max_epu16(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), x)", f1083, 0, 512},
  {"512:_mm512_xor_si512(_mm512_min_epi32(x, y), _mm512_set1_epi8((char)0xffu))", f1084, 0, 512},
  {"512:_mm512_min_epi32(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), y)", f1085, 0, 512},
  {"512:_mm512_min_epi32(x, _mm512_xor_si512(y, _mm512_set1_epi8((char)0xffu)))", f1086, 0, 512},
  {"512:_mm512_min_epi32(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), _mm512_xor_si512(y, _mm512_set1_epi8((char)0xffu)))", f1087, 0, 512},
  {"512:_mm512_min_epi32(x, _mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)))", f1088, 0, 512},
  {"512:_mm512_min_epi32(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), x)", f1089, 0, 512},
  {"512:_mm512_xor_si512(_mm512_max_epi32(x, y), _mm512_set1_epi8((char)0xffu))", f1090, 0, 512},
  {"512:_mm512_max_epi32(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), y)", f1091, 0, 512},
  {"512:_mm512_max_epi32(x, _mm512_xor_si512(y, _mm512_set1_epi8((char)0xffu)))", f1092, 0, 512},
  {"512:_mm512_max_epi32(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), _mm512_xor_si512(y, _mm512_set1_epi8((char)0xffu)))", f1093, 0, 512},
  {"512:_mm512_max_epi32(x, _mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)))", f1094, 0, 512},
  {"512:_mm512_max_epi32(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), x)", f1095, 0, 512},
  {"512:_mm512_xor_si512(_mm512_min_epu32(x, y), _mm512_set1_epi8((char)0xffu))", f1096, 0, 512},
  {"512:_mm512_min_epu32(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), y)", f1097, 0, 512},
  {"512:_mm512_min_epu32(x, _mm512_xor_si512(y, _mm512_set1_epi8((char)0xffu)))", f1098, 0, 512},
  {"512:_mm512_min_epu32(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), _mm512_xor_si512(y, _mm512_set1_epi8((char)0xffu)))", f1099, 0, 512},
  {"512:_mm512_min_epu32(x, _mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)))", f1100, 0, 512},
  {"512:_mm512_min_epu32(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), x)", f1101, 0, 512},
  {"512:_mm512_xor_si512(_mm512_max_epu32(x, y), _mm512_set1_epi8((char)0xffu))", f1102, 0, 512},
  {"512:_mm512_max_epu32(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), y)", f1103, 0, 512},
  {"512:_mm512_max_epu32(x, _mm512_xor_si512(y, _mm512_set1_epi8((char)0xffu)))", f1104, 0, 512},
  {"512:_mm512_max_epu32(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), _mm512_xor_si512(y, _mm512_set1_epi8((char)0xffu)))", f1105, 0, 512},
  {"512:_mm512_max_epu32(x, _mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)))", f1106, 0, 512},
  {"512:_mm512_max_epu32(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), x)", f1107, 0, 512},
  {"512:_mm512_xor_si512(_mm512_min_epi64(x, y), _mm512_set1_epi8((char)0xffu))", f1108, 0, 512},
  {"512:_mm512_min_epi64(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), y)", f1109, 0, 512},
  {"512:_mm512_min_epi64(x, _mm512_xor_si512(y, _mm512_set1_epi8((char)0xffu)))", f1110, 0, 512},
  {"512:_mm512_min_epi64(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), _mm512_xor_si512(y, _mm512_set1_epi8((char)0xffu)))", f1111, 0, 512},
  {"512:_mm512_min_epi64(x, _mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)))", f1112, 0, 512},
  {"512:_mm512_min_epi64(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), x)", f1113, 0, 512},
  {"512:_mm512_xor_si512(_mm512_max_epi64(x, y), _mm512_set1_epi8((char)0xffu))", f1114, 0, 512},
  {"512:_mm512_max_epi64(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), y)", f1115, 0, 512},
  {"512:_mm512_max_epi64(x, _mm512_xor_si512(y, _mm512_set1_epi8((char)0xffu)))", f1116, 0, 512},
  {"512:_mm512_max_epi64(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), _mm512_xor_si512(y, _mm512_set1_epi8((char)0xffu)))", f1117, 0, 512},
  {"512:_mm512_max_epi64(x, _mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)))", f1118, 0, 512},
  {"512:_mm512_max_epi64(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), x)", f1119, 0, 512},
  {"512:_mm512_xor_si512(_mm512_min_epu64(x, y), _mm512_set1_epi8((char)0xffu))", f1120, 0, 512},
  {"512:_mm512_min_epu64(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), y)", f1121, 0, 512},
  {"512:_mm512_min_epu64(x, _mm512_xor_si512(y, _mm512_set1_epi8((char)0xffu)))", f1122, 0, 512},
  {"512:_mm512_min_epu64(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), _mm512_xor_si512(y, _mm512_set1_epi8((char)0xffu)))", f1123, 0, 512},
  {"512:_mm512_min_epu64(x, _mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)))", f1124, 0, 512},
  {"512:_mm512_min_epu64(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), x)", f1125, 0, 512},
  {"512:_mm512_xor_si512(_mm512_max_epu64(x, y), _mm512_set1_epi8((char)0xffu))", f1126, 0, 512},
  {"512:_mm512_max_epu64(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), y)", f1127, 0, 512},
  {"512:_mm512_max_epu64(x, _mm512_xor_si512(y, _mm512_set1_epi8((char)0xffu)))", f1128, 0, 512},
  {"512:_mm512_max_epu64(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), _mm512_xor_si512(y, _mm512_set1_epi8((char)0xffu)))", f1129, 0, 512},
  {"512:_mm512_max_epu64(x, _mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)))", f1130, 0, 512},
  {"512:_mm512_max_epu64(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), x)", f1131, 0, 512},
  {"512:_mm512_xor_si512(_mm512_and_si512(x, y), _mm512_set1_epi8((char)0xffu))", f1132, 0, 512},
  {"512:_mm512_and_si512(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), y)", f1133, 0, 512},
  {"512:_mm512_and_si512(x, _mm512_xor_si512(y, _mm512_set1_epi8((char)0xffu)))", f1134, 0, 512},
  {"512:_mm512_and_si512(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), _mm512_xor_si512(y, _mm512_set1_epi8((char)0xffu)))", f1135, 0, 512},
  {"512:_mm512_and_si512(x, _mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)))", f1136, 0, 512},
  {"512:_mm512_and_si512(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), x)", f1137, 0, 512},
  {"512:_mm512_xor_si512(_mm512_or_si512(x, y), _mm512_set1_epi8((char)0xffu))", f1138, 0, 512},
  {"512:_mm512_or_si512(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), y)", f1139, 0, 512},
  {"512:_mm512_or_si512(x, _mm512_xor_si512(y, _mm512_set1_epi8((char)0xffu)))", f1140, 0, 512},
  {"512:_mm512_or_si512(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), _mm512_xor_si512(y, _mm512_set1_epi8((char)0xffu)))", f1141, 0, 512},
  {"512:_mm512_or_si512(x, _mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)))", f1142, 0, 512},
  {"512:_mm512_or_si512(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), x)", f1143, 0, 512},
  {"512:_mm512_xor_si512(_mm512_xor_si512(x, y), _mm512_set1_epi8((char)0xffu))", f1144, 0, 512},
  {"512:_mm512_xor_si512(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), y)", f1145, 0, 512},
  {"512:_mm512_xor_si512(x, _mm512_xor_si512(y, _mm512_set1_epi8((char)0xffu)))", f1146, 0, 512},
  {"512:_mm512_xor_si512(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), _mm512_xor_si512(y, _mm512_set1_epi8((char)0xffu)))", f1147, 0, 512},
  {"512:_mm512_xor_si512(x, _mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)))", f1148, 0, 512},
  {"512:_mm512_xor_si512(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), x)", f1149, 0, 512},
  {"512:_mm512_xor_si512(_mm512_andnot_si512(x, y), _mm512_set1_epi8((char)0xffu))", f1150, 0, 512},
  {"512:_mm512_andnot_si512(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), y)", f1151, 0, 512},
  {"512:_mm512_andnot_si512(x, _mm512_xor_si512(y, _mm512_set1_epi8((char)0xffu)))", f1152, 0, 512},
  {"512:_mm512_andnot_si512(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), _mm512_xor_si512(y, _mm512_set1_epi8((char)0xffu)))", f1153, 0, 512},
  {"512:_mm512_andnot_si512(x, _mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)))", f1154, 0, 512},
  {"512:_mm512_andnot_si512(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), x)", f1155, 0, 512},
  {"512:_mm512_xor_si512(_mm512_mullo_epi16(x, y), _mm512_set1_epi8((char)0xffu))", f1156, 0, 512},
  {"512:_mm512_mullo_epi16(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), y)", f1157, 0, 512},
  {"512:_mm512_mullo_epi16(x, _mm512_xor_si512(y, _mm512_set1_epi8((char)0xffu)))", f1158, 0, 512},
  {"512:_mm512_mullo_epi16(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), _mm512_xor_si512(y, _mm512_set1_epi8((char)0xffu)))", f1159, 0, 512},
  {"512:_mm512_mullo_epi16(x, _mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)))", f1160, 0, 512},
  {"512:_mm512_mullo_epi16(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), x)", f1161, 0, 512},
  {"512:_mm512_xor_si512(_mm512_mullo_epi32(x, y), _mm512_set1_epi8((char)0xffu))", f1162, 0, 512},
  {"512:_mm512_mullo_epi32(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), y)", f1163, 0, 512},
  {"512:_mm512_mullo_epi32(x, _mm512_xor_si512(y, _mm512_set1_epi8((char)0xffu)))", f1164, 0, 512},
  {"512:_mm512_mullo_epi32(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), _mm512_xor_si512(y, _mm512_set1_epi8((char)0xffu)))", f1165, 0, 512},
  {"512:_mm512_mullo_epi32(x, _mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)))", f1166, 0, 512},
  {"512:_mm512_mullo_epi32(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), x)", f1167, 0, 512},
  {"512:_mm512_xor_si512(_mm512_mulhi_epi16(x, y), _mm512_set1_epi8((char)0xffu))", f1168, 0, 512},
  {"512:_mm512_mulhi_epi16(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), y)", f1169, 0, 512},
  {"512:_mm512_mulhi_epi16(x, _mm512_xor_si512(y, _mm512_set1_epi8((char)0xffu)))", f1170, 0, 512},
  {"512:_mm512_mulhi_epi16(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), _mm512_xor_si512(y, _mm512_set1_epi8((char)0xffu)))", f1171, 0, 512},
  {"512:_mm512_mulhi_epi16(x, _mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)))", f1172, 0, 512},
  {"512:_mm512_mulhi_epi16(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), x)", f1173, 0, 512},
  {"512:_mm512_xor_si512(_mm512_mulhi_epu16(x, y), _mm512_set1_epi8((char)0xffu))", f1174, 0, 512},
  {"512:_mm512_mulhi_epu16(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), y)", f1175, 0, 512},
  {"512:_mm512_mulhi_epu16(x, _mm512_xor_si512(y, _mm512_set1_epi8((char)0xffu)))", f1176, 0, 512},
  {"512:_mm512_mulhi_epu16(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), _mm512_xor_si512(y, _mm512_set1_epi8((char)0xffu)))", f1177, 0, 512},
  {"512:_mm512_mulhi_epu16(x, _mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)))", f1178, 0, 512},
  {"512:_mm512_mulhi_epu16(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), x)", f1179, 0, 512},
  {"512:_mm512_xor_si512(_mm512_sllv_epi32(x, y), _mm512_set1_epi8((char)0xffu))", f1180, 0, 512},
  {"512:_mm512_sllv_epi32(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), y)", f1181, 0, 512},
  {"512:_mm512_sllv_epi32(x, _mm512_xor_si512(y, _mm512_set1_epi8((char)0xffu)))", f1182, 0, 512},
  {"512:_mm512_sllv_epi32(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), _mm512_xor_si512(y, _mm512_set1_epi8((char)0xffu)))", f1183, 0, 512},
  {"512:_mm512_sllv_epi32(x, _mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)))", f1184, 0, 512},
  {"512:_mm512_sllv_epi32(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), x)", f1185, 0, 512},
  {"512:_mm512_xor_si512(_mm512_srlv_epi32(x, y), _mm512_set1_epi8((char)0xffu))", f1186, 0, 512},
  {"512:_mm512_srlv_epi32(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), y)", f1187, 0, 512},
  {"512:_mm512_srlv_epi32(x, _mm512_xor_si512(y, _mm512_set1_epi8((char)0xffu)))", f1188, 0, 512},
  {"512:_mm512_srlv_epi32(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), _mm512_xor_si512(y, _mm512_set1_epi8((char)0xffu)))", f1189, 0, 512},
  {"512:_mm512_srlv_epi32(x, _mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)))", f1190, 0, 512},
  {"512:_mm512_srlv_epi32(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), x)", f1191, 0, 512},
  {"512:_mm512_xor_si512(_mm512_sllv_epi64(x, y), _mm512_set1_epi8((char)0xffu))", f1192, 0, 512},
  {"512:_mm512_sllv_epi64(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), y)", f1193, 0, 512},
  {"512:_mm512_sllv_epi64(x, _mm512_xor_si512(y, _mm512_set1_epi8((char)0xffu)))", f1194, 0, 512},
  {"512:_mm512_sllv_epi64(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), _mm512_xor_si512(y, _mm512_set1_epi8((char)0xffu)))", f1195, 0, 512},
  {"512:_mm512_sllv_epi64(x, _mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)))", f1196, 0, 512},
  {"512:_mm512_sllv_epi64(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), x)", f1197, 0, 512},
  {"512:_mm512_xor_si512(_mm512_srlv_epi64(x, y), _mm512_set1_epi8((char)0xffu))", f1198, 0, 512},
  {"512:_mm512_srlv_epi64(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), y)", f1199, 0, 512},
};
extern const int size_87 = 1200;
