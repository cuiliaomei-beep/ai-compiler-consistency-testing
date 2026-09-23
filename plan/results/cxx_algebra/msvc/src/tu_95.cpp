#include "common.h"
static NOINLINE void f0(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_andnot_pd(x, _mm512_sub_pd(_mm512_setzero_pd(), x)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_andnot_pd(_mm512_sub_pd(_mm512_setzero_pd(), x), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f2(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_mul_pd(_mm512_add_pd(x, y), _mm512_set1_pd(-1.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f3(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_add_pd(_mm512_mul_pd(x, _mm512_set1_pd(-1.0)), y); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f4(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_add_pd(x, _mm512_mul_pd(y, _mm512_set1_pd(-1.0))); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f5(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_add_pd(_mm512_mul_pd(x, _mm512_set1_pd(-1.0)), _mm512_mul_pd(y, _mm512_set1_pd(-1.0))); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f6(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_add_pd(x, _mm512_mul_pd(x, _mm512_set1_pd(-1.0))); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f7(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_add_pd(_mm512_mul_pd(x, _mm512_set1_pd(-1.0)), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f8(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_mul_pd(_mm512_sub_pd(x, y), _mm512_set1_pd(-1.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f9(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_sub_pd(_mm512_mul_pd(x, _mm512_set1_pd(-1.0)), y); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f10(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_sub_pd(x, _mm512_mul_pd(y, _mm512_set1_pd(-1.0))); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f11(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_sub_pd(_mm512_mul_pd(x, _mm512_set1_pd(-1.0)), _mm512_mul_pd(y, _mm512_set1_pd(-1.0))); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f12(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_sub_pd(x, _mm512_mul_pd(x, _mm512_set1_pd(-1.0))); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f13(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_sub_pd(_mm512_mul_pd(x, _mm512_set1_pd(-1.0)), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f14(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_mul_pd(_mm512_mul_pd(x, y), _mm512_set1_pd(-1.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f15(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_mul_pd(_mm512_mul_pd(x, _mm512_set1_pd(-1.0)), y); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f16(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_mul_pd(x, _mm512_mul_pd(y, _mm512_set1_pd(-1.0))); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f17(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_mul_pd(_mm512_mul_pd(x, _mm512_set1_pd(-1.0)), _mm512_mul_pd(y, _mm512_set1_pd(-1.0))); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f18(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_mul_pd(x, _mm512_mul_pd(x, _mm512_set1_pd(-1.0))); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f19(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_mul_pd(_mm512_mul_pd(x, _mm512_set1_pd(-1.0)), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f20(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_mul_pd(_mm512_div_pd(x, y), _mm512_set1_pd(-1.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f21(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_div_pd(_mm512_mul_pd(x, _mm512_set1_pd(-1.0)), y); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f22(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_div_pd(x, _mm512_mul_pd(y, _mm512_set1_pd(-1.0))); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f23(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_div_pd(_mm512_mul_pd(x, _mm512_set1_pd(-1.0)), _mm512_mul_pd(y, _mm512_set1_pd(-1.0))); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f24(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_div_pd(x, _mm512_mul_pd(x, _mm512_set1_pd(-1.0))); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f25(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_div_pd(_mm512_mul_pd(x, _mm512_set1_pd(-1.0)), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f26(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_mul_pd(_mm512_min_pd(x, y), _mm512_set1_pd(-1.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f27(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_min_pd(_mm512_mul_pd(x, _mm512_set1_pd(-1.0)), y); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f28(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_min_pd(x, _mm512_mul_pd(y, _mm512_set1_pd(-1.0))); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f29(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_min_pd(_mm512_mul_pd(x, _mm512_set1_pd(-1.0)), _mm512_mul_pd(y, _mm512_set1_pd(-1.0))); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f30(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_min_pd(x, _mm512_mul_pd(x, _mm512_set1_pd(-1.0))); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f31(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_min_pd(_mm512_mul_pd(x, _mm512_set1_pd(-1.0)), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f32(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_mul_pd(_mm512_max_pd(x, y), _mm512_set1_pd(-1.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f33(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_max_pd(_mm512_mul_pd(x, _mm512_set1_pd(-1.0)), y); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f34(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_max_pd(x, _mm512_mul_pd(y, _mm512_set1_pd(-1.0))); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f35(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_max_pd(_mm512_mul_pd(x, _mm512_set1_pd(-1.0)), _mm512_mul_pd(y, _mm512_set1_pd(-1.0))); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f36(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_max_pd(x, _mm512_mul_pd(x, _mm512_set1_pd(-1.0))); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f37(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_max_pd(_mm512_mul_pd(x, _mm512_set1_pd(-1.0)), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f38(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_mul_pd(_mm512_and_pd(x, y), _mm512_set1_pd(-1.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f39(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_and_pd(_mm512_mul_pd(x, _mm512_set1_pd(-1.0)), y); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f40(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_and_pd(x, _mm512_mul_pd(y, _mm512_set1_pd(-1.0))); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f41(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_and_pd(_mm512_mul_pd(x, _mm512_set1_pd(-1.0)), _mm512_mul_pd(y, _mm512_set1_pd(-1.0))); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f42(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_and_pd(x, _mm512_mul_pd(x, _mm512_set1_pd(-1.0))); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f43(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_and_pd(_mm512_mul_pd(x, _mm512_set1_pd(-1.0)), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f44(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_mul_pd(_mm512_or_pd(x, y), _mm512_set1_pd(-1.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f45(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_or_pd(_mm512_mul_pd(x, _mm512_set1_pd(-1.0)), y); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f46(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_or_pd(x, _mm512_mul_pd(y, _mm512_set1_pd(-1.0))); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f47(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_or_pd(_mm512_mul_pd(x, _mm512_set1_pd(-1.0)), _mm512_mul_pd(y, _mm512_set1_pd(-1.0))); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f48(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_or_pd(x, _mm512_mul_pd(x, _mm512_set1_pd(-1.0))); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f49(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_or_pd(_mm512_mul_pd(x, _mm512_set1_pd(-1.0)), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f50(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_mul_pd(_mm512_xor_pd(x, y), _mm512_set1_pd(-1.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f51(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_xor_pd(_mm512_mul_pd(x, _mm512_set1_pd(-1.0)), y); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f52(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_xor_pd(x, _mm512_mul_pd(y, _mm512_set1_pd(-1.0))); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f53(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_xor_pd(_mm512_mul_pd(x, _mm512_set1_pd(-1.0)), _mm512_mul_pd(y, _mm512_set1_pd(-1.0))); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f54(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_xor_pd(x, _mm512_mul_pd(x, _mm512_set1_pd(-1.0))); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f55(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_xor_pd(_mm512_mul_pd(x, _mm512_set1_pd(-1.0)), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f56(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_mul_pd(_mm512_andnot_pd(x, y), _mm512_set1_pd(-1.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f57(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_andnot_pd(_mm512_mul_pd(x, _mm512_set1_pd(-1.0)), y); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f58(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_andnot_pd(x, _mm512_mul_pd(y, _mm512_set1_pd(-1.0))); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f59(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_andnot_pd(_mm512_mul_pd(x, _mm512_set1_pd(-1.0)), _mm512_mul_pd(y, _mm512_set1_pd(-1.0))); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f60(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_andnot_pd(x, _mm512_mul_pd(x, _mm512_set1_pd(-1.0))); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f61(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_andnot_pd(_mm512_mul_pd(x, _mm512_set1_pd(-1.0)), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f62(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_roundscale_pd(_mm512_add_pd(x, y), 1 | _MM_FROUND_NO_EXC); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f63(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_add_pd(_mm512_roundscale_pd(x, 1 | _MM_FROUND_NO_EXC), y); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f64(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_add_pd(x, _mm512_roundscale_pd(y, 1 | _MM_FROUND_NO_EXC)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f65(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_add_pd(_mm512_roundscale_pd(x, 1 | _MM_FROUND_NO_EXC), _mm512_roundscale_pd(y, 1 | _MM_FROUND_NO_EXC)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f66(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_add_pd(x, _mm512_roundscale_pd(x, 1 | _MM_FROUND_NO_EXC)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f67(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_add_pd(_mm512_roundscale_pd(x, 1 | _MM_FROUND_NO_EXC), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f68(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_roundscale_pd(_mm512_sub_pd(x, y), 1 | _MM_FROUND_NO_EXC); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f69(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_sub_pd(_mm512_roundscale_pd(x, 1 | _MM_FROUND_NO_EXC), y); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f70(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_sub_pd(x, _mm512_roundscale_pd(y, 1 | _MM_FROUND_NO_EXC)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f71(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_sub_pd(_mm512_roundscale_pd(x, 1 | _MM_FROUND_NO_EXC), _mm512_roundscale_pd(y, 1 | _MM_FROUND_NO_EXC)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f72(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_sub_pd(x, _mm512_roundscale_pd(x, 1 | _MM_FROUND_NO_EXC)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f73(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_sub_pd(_mm512_roundscale_pd(x, 1 | _MM_FROUND_NO_EXC), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f74(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_roundscale_pd(_mm512_mul_pd(x, y), 1 | _MM_FROUND_NO_EXC); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f75(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_mul_pd(_mm512_roundscale_pd(x, 1 | _MM_FROUND_NO_EXC), y); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f76(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_mul_pd(x, _mm512_roundscale_pd(y, 1 | _MM_FROUND_NO_EXC)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f77(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_mul_pd(_mm512_roundscale_pd(x, 1 | _MM_FROUND_NO_EXC), _mm512_roundscale_pd(y, 1 | _MM_FROUND_NO_EXC)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f78(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_mul_pd(x, _mm512_roundscale_pd(x, 1 | _MM_FROUND_NO_EXC)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f79(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_mul_pd(_mm512_roundscale_pd(x, 1 | _MM_FROUND_NO_EXC), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f80(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_roundscale_pd(_mm512_div_pd(x, y), 1 | _MM_FROUND_NO_EXC); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f81(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_div_pd(_mm512_roundscale_pd(x, 1 | _MM_FROUND_NO_EXC), y); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f82(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_div_pd(x, _mm512_roundscale_pd(y, 1 | _MM_FROUND_NO_EXC)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f83(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_div_pd(_mm512_roundscale_pd(x, 1 | _MM_FROUND_NO_EXC), _mm512_roundscale_pd(y, 1 | _MM_FROUND_NO_EXC)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f84(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_div_pd(x, _mm512_roundscale_pd(x, 1 | _MM_FROUND_NO_EXC)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f85(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_div_pd(_mm512_roundscale_pd(x, 1 | _MM_FROUND_NO_EXC), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f86(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_roundscale_pd(_mm512_min_pd(x, y), 1 | _MM_FROUND_NO_EXC); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f87(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_min_pd(_mm512_roundscale_pd(x, 1 | _MM_FROUND_NO_EXC), y); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f88(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_min_pd(x, _mm512_roundscale_pd(y, 1 | _MM_FROUND_NO_EXC)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f89(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_min_pd(_mm512_roundscale_pd(x, 1 | _MM_FROUND_NO_EXC), _mm512_roundscale_pd(y, 1 | _MM_FROUND_NO_EXC)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f90(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_min_pd(x, _mm512_roundscale_pd(x, 1 | _MM_FROUND_NO_EXC)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f91(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_min_pd(_mm512_roundscale_pd(x, 1 | _MM_FROUND_NO_EXC), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f92(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_roundscale_pd(_mm512_max_pd(x, y), 1 | _MM_FROUND_NO_EXC); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f93(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_max_pd(_mm512_roundscale_pd(x, 1 | _MM_FROUND_NO_EXC), y); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f94(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_max_pd(x, _mm512_roundscale_pd(y, 1 | _MM_FROUND_NO_EXC)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f95(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_max_pd(_mm512_roundscale_pd(x, 1 | _MM_FROUND_NO_EXC), _mm512_roundscale_pd(y, 1 | _MM_FROUND_NO_EXC)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f96(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_max_pd(x, _mm512_roundscale_pd(x, 1 | _MM_FROUND_NO_EXC)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f97(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_max_pd(_mm512_roundscale_pd(x, 1 | _MM_FROUND_NO_EXC), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f98(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_roundscale_pd(_mm512_and_pd(x, y), 1 | _MM_FROUND_NO_EXC); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f99(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_and_pd(_mm512_roundscale_pd(x, 1 | _MM_FROUND_NO_EXC), y); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f100(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_and_pd(x, _mm512_roundscale_pd(y, 1 | _MM_FROUND_NO_EXC)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f101(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_and_pd(_mm512_roundscale_pd(x, 1 | _MM_FROUND_NO_EXC), _mm512_roundscale_pd(y, 1 | _MM_FROUND_NO_EXC)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f102(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_and_pd(x, _mm512_roundscale_pd(x, 1 | _MM_FROUND_NO_EXC)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f103(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_and_pd(_mm512_roundscale_pd(x, 1 | _MM_FROUND_NO_EXC), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f104(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_roundscale_pd(_mm512_or_pd(x, y), 1 | _MM_FROUND_NO_EXC); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f105(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_or_pd(_mm512_roundscale_pd(x, 1 | _MM_FROUND_NO_EXC), y); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f106(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_or_pd(x, _mm512_roundscale_pd(y, 1 | _MM_FROUND_NO_EXC)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f107(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_or_pd(_mm512_roundscale_pd(x, 1 | _MM_FROUND_NO_EXC), _mm512_roundscale_pd(y, 1 | _MM_FROUND_NO_EXC)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f108(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_or_pd(x, _mm512_roundscale_pd(x, 1 | _MM_FROUND_NO_EXC)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f109(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_or_pd(_mm512_roundscale_pd(x, 1 | _MM_FROUND_NO_EXC), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f110(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_roundscale_pd(_mm512_xor_pd(x, y), 1 | _MM_FROUND_NO_EXC); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f111(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_xor_pd(_mm512_roundscale_pd(x, 1 | _MM_FROUND_NO_EXC), y); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f112(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_xor_pd(x, _mm512_roundscale_pd(y, 1 | _MM_FROUND_NO_EXC)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f113(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_xor_pd(_mm512_roundscale_pd(x, 1 | _MM_FROUND_NO_EXC), _mm512_roundscale_pd(y, 1 | _MM_FROUND_NO_EXC)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f114(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_xor_pd(x, _mm512_roundscale_pd(x, 1 | _MM_FROUND_NO_EXC)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f115(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_xor_pd(_mm512_roundscale_pd(x, 1 | _MM_FROUND_NO_EXC), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f116(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_roundscale_pd(_mm512_andnot_pd(x, y), 1 | _MM_FROUND_NO_EXC); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f117(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_andnot_pd(_mm512_roundscale_pd(x, 1 | _MM_FROUND_NO_EXC), y); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f118(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_andnot_pd(x, _mm512_roundscale_pd(y, 1 | _MM_FROUND_NO_EXC)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f119(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_andnot_pd(_mm512_roundscale_pd(x, 1 | _MM_FROUND_NO_EXC), _mm512_roundscale_pd(y, 1 | _MM_FROUND_NO_EXC)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f120(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_andnot_pd(x, _mm512_roundscale_pd(x, 1 | _MM_FROUND_NO_EXC)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f121(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_andnot_pd(_mm512_roundscale_pd(x, 1 | _MM_FROUND_NO_EXC), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f122(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_roundscale_pd(_mm512_add_pd(x, y), 2 | _MM_FROUND_NO_EXC); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f123(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_add_pd(_mm512_roundscale_pd(x, 2 | _MM_FROUND_NO_EXC), y); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f124(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_add_pd(x, _mm512_roundscale_pd(y, 2 | _MM_FROUND_NO_EXC)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f125(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_add_pd(_mm512_roundscale_pd(x, 2 | _MM_FROUND_NO_EXC), _mm512_roundscale_pd(y, 2 | _MM_FROUND_NO_EXC)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f126(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_add_pd(x, _mm512_roundscale_pd(x, 2 | _MM_FROUND_NO_EXC)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f127(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_add_pd(_mm512_roundscale_pd(x, 2 | _MM_FROUND_NO_EXC), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f128(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_roundscale_pd(_mm512_sub_pd(x, y), 2 | _MM_FROUND_NO_EXC); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f129(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_sub_pd(_mm512_roundscale_pd(x, 2 | _MM_FROUND_NO_EXC), y); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f130(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_sub_pd(x, _mm512_roundscale_pd(y, 2 | _MM_FROUND_NO_EXC)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f131(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_sub_pd(_mm512_roundscale_pd(x, 2 | _MM_FROUND_NO_EXC), _mm512_roundscale_pd(y, 2 | _MM_FROUND_NO_EXC)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f132(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_sub_pd(x, _mm512_roundscale_pd(x, 2 | _MM_FROUND_NO_EXC)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f133(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_sub_pd(_mm512_roundscale_pd(x, 2 | _MM_FROUND_NO_EXC), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f134(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_roundscale_pd(_mm512_mul_pd(x, y), 2 | _MM_FROUND_NO_EXC); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f135(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_mul_pd(_mm512_roundscale_pd(x, 2 | _MM_FROUND_NO_EXC), y); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f136(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_mul_pd(x, _mm512_roundscale_pd(y, 2 | _MM_FROUND_NO_EXC)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f137(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_mul_pd(_mm512_roundscale_pd(x, 2 | _MM_FROUND_NO_EXC), _mm512_roundscale_pd(y, 2 | _MM_FROUND_NO_EXC)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f138(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_mul_pd(x, _mm512_roundscale_pd(x, 2 | _MM_FROUND_NO_EXC)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f139(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_mul_pd(_mm512_roundscale_pd(x, 2 | _MM_FROUND_NO_EXC), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f140(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_roundscale_pd(_mm512_div_pd(x, y), 2 | _MM_FROUND_NO_EXC); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f141(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_div_pd(_mm512_roundscale_pd(x, 2 | _MM_FROUND_NO_EXC), y); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f142(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_div_pd(x, _mm512_roundscale_pd(y, 2 | _MM_FROUND_NO_EXC)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f143(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_div_pd(_mm512_roundscale_pd(x, 2 | _MM_FROUND_NO_EXC), _mm512_roundscale_pd(y, 2 | _MM_FROUND_NO_EXC)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f144(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_div_pd(x, _mm512_roundscale_pd(x, 2 | _MM_FROUND_NO_EXC)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f145(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_div_pd(_mm512_roundscale_pd(x, 2 | _MM_FROUND_NO_EXC), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f146(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_roundscale_pd(_mm512_min_pd(x, y), 2 | _MM_FROUND_NO_EXC); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f147(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_min_pd(_mm512_roundscale_pd(x, 2 | _MM_FROUND_NO_EXC), y); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f148(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_min_pd(x, _mm512_roundscale_pd(y, 2 | _MM_FROUND_NO_EXC)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f149(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_min_pd(_mm512_roundscale_pd(x, 2 | _MM_FROUND_NO_EXC), _mm512_roundscale_pd(y, 2 | _MM_FROUND_NO_EXC)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f150(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_min_pd(x, _mm512_roundscale_pd(x, 2 | _MM_FROUND_NO_EXC)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f151(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_min_pd(_mm512_roundscale_pd(x, 2 | _MM_FROUND_NO_EXC), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f152(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_roundscale_pd(_mm512_max_pd(x, y), 2 | _MM_FROUND_NO_EXC); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f153(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_max_pd(_mm512_roundscale_pd(x, 2 | _MM_FROUND_NO_EXC), y); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f154(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_max_pd(x, _mm512_roundscale_pd(y, 2 | _MM_FROUND_NO_EXC)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f155(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_max_pd(_mm512_roundscale_pd(x, 2 | _MM_FROUND_NO_EXC), _mm512_roundscale_pd(y, 2 | _MM_FROUND_NO_EXC)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f156(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_max_pd(x, _mm512_roundscale_pd(x, 2 | _MM_FROUND_NO_EXC)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f157(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_max_pd(_mm512_roundscale_pd(x, 2 | _MM_FROUND_NO_EXC), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f158(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_roundscale_pd(_mm512_and_pd(x, y), 2 | _MM_FROUND_NO_EXC); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f159(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_and_pd(_mm512_roundscale_pd(x, 2 | _MM_FROUND_NO_EXC), y); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f160(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_and_pd(x, _mm512_roundscale_pd(y, 2 | _MM_FROUND_NO_EXC)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f161(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_and_pd(_mm512_roundscale_pd(x, 2 | _MM_FROUND_NO_EXC), _mm512_roundscale_pd(y, 2 | _MM_FROUND_NO_EXC)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f162(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_and_pd(x, _mm512_roundscale_pd(x, 2 | _MM_FROUND_NO_EXC)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f163(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_and_pd(_mm512_roundscale_pd(x, 2 | _MM_FROUND_NO_EXC), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f164(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_roundscale_pd(_mm512_or_pd(x, y), 2 | _MM_FROUND_NO_EXC); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f165(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_or_pd(_mm512_roundscale_pd(x, 2 | _MM_FROUND_NO_EXC), y); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f166(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_or_pd(x, _mm512_roundscale_pd(y, 2 | _MM_FROUND_NO_EXC)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f167(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_or_pd(_mm512_roundscale_pd(x, 2 | _MM_FROUND_NO_EXC), _mm512_roundscale_pd(y, 2 | _MM_FROUND_NO_EXC)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f168(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_or_pd(x, _mm512_roundscale_pd(x, 2 | _MM_FROUND_NO_EXC)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f169(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_or_pd(_mm512_roundscale_pd(x, 2 | _MM_FROUND_NO_EXC), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f170(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_roundscale_pd(_mm512_xor_pd(x, y), 2 | _MM_FROUND_NO_EXC); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f171(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_xor_pd(_mm512_roundscale_pd(x, 2 | _MM_FROUND_NO_EXC), y); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f172(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_xor_pd(x, _mm512_roundscale_pd(y, 2 | _MM_FROUND_NO_EXC)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f173(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_xor_pd(_mm512_roundscale_pd(x, 2 | _MM_FROUND_NO_EXC), _mm512_roundscale_pd(y, 2 | _MM_FROUND_NO_EXC)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f174(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_xor_pd(x, _mm512_roundscale_pd(x, 2 | _MM_FROUND_NO_EXC)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f175(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_xor_pd(_mm512_roundscale_pd(x, 2 | _MM_FROUND_NO_EXC), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f176(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_roundscale_pd(_mm512_andnot_pd(x, y), 2 | _MM_FROUND_NO_EXC); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f177(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_andnot_pd(_mm512_roundscale_pd(x, 2 | _MM_FROUND_NO_EXC), y); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f178(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_andnot_pd(x, _mm512_roundscale_pd(y, 2 | _MM_FROUND_NO_EXC)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f179(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_andnot_pd(_mm512_roundscale_pd(x, 2 | _MM_FROUND_NO_EXC), _mm512_roundscale_pd(y, 2 | _MM_FROUND_NO_EXC)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f180(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_andnot_pd(x, _mm512_roundscale_pd(x, 2 | _MM_FROUND_NO_EXC)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f181(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_andnot_pd(_mm512_roundscale_pd(x, 2 | _MM_FROUND_NO_EXC), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f182(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_roundscale_pd(_mm512_add_pd(x, y), 0 | _MM_FROUND_NO_EXC); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f183(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_add_pd(_mm512_roundscale_pd(x, 0 | _MM_FROUND_NO_EXC), y); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f184(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_add_pd(x, _mm512_roundscale_pd(y, 0 | _MM_FROUND_NO_EXC)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f185(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_add_pd(_mm512_roundscale_pd(x, 0 | _MM_FROUND_NO_EXC), _mm512_roundscale_pd(y, 0 | _MM_FROUND_NO_EXC)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f186(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_add_pd(x, _mm512_roundscale_pd(x, 0 | _MM_FROUND_NO_EXC)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f187(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_add_pd(_mm512_roundscale_pd(x, 0 | _MM_FROUND_NO_EXC), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f188(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_roundscale_pd(_mm512_sub_pd(x, y), 0 | _MM_FROUND_NO_EXC); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f189(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_sub_pd(_mm512_roundscale_pd(x, 0 | _MM_FROUND_NO_EXC), y); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f190(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_sub_pd(x, _mm512_roundscale_pd(y, 0 | _MM_FROUND_NO_EXC)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f191(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_sub_pd(_mm512_roundscale_pd(x, 0 | _MM_FROUND_NO_EXC), _mm512_roundscale_pd(y, 0 | _MM_FROUND_NO_EXC)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f192(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_sub_pd(x, _mm512_roundscale_pd(x, 0 | _MM_FROUND_NO_EXC)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f193(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_sub_pd(_mm512_roundscale_pd(x, 0 | _MM_FROUND_NO_EXC), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f194(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_roundscale_pd(_mm512_mul_pd(x, y), 0 | _MM_FROUND_NO_EXC); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f195(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_mul_pd(_mm512_roundscale_pd(x, 0 | _MM_FROUND_NO_EXC), y); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f196(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_mul_pd(x, _mm512_roundscale_pd(y, 0 | _MM_FROUND_NO_EXC)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f197(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_mul_pd(_mm512_roundscale_pd(x, 0 | _MM_FROUND_NO_EXC), _mm512_roundscale_pd(y, 0 | _MM_FROUND_NO_EXC)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f198(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_mul_pd(x, _mm512_roundscale_pd(x, 0 | _MM_FROUND_NO_EXC)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f199(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_mul_pd(_mm512_roundscale_pd(x, 0 | _MM_FROUND_NO_EXC), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f200(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_roundscale_pd(_mm512_div_pd(x, y), 0 | _MM_FROUND_NO_EXC); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f201(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_div_pd(_mm512_roundscale_pd(x, 0 | _MM_FROUND_NO_EXC), y); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f202(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_div_pd(x, _mm512_roundscale_pd(y, 0 | _MM_FROUND_NO_EXC)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f203(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_div_pd(_mm512_roundscale_pd(x, 0 | _MM_FROUND_NO_EXC), _mm512_roundscale_pd(y, 0 | _MM_FROUND_NO_EXC)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f204(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_div_pd(x, _mm512_roundscale_pd(x, 0 | _MM_FROUND_NO_EXC)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f205(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_div_pd(_mm512_roundscale_pd(x, 0 | _MM_FROUND_NO_EXC), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f206(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_roundscale_pd(_mm512_min_pd(x, y), 0 | _MM_FROUND_NO_EXC); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f207(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_min_pd(_mm512_roundscale_pd(x, 0 | _MM_FROUND_NO_EXC), y); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f208(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_min_pd(x, _mm512_roundscale_pd(y, 0 | _MM_FROUND_NO_EXC)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f209(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_min_pd(_mm512_roundscale_pd(x, 0 | _MM_FROUND_NO_EXC), _mm512_roundscale_pd(y, 0 | _MM_FROUND_NO_EXC)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f210(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_min_pd(x, _mm512_roundscale_pd(x, 0 | _MM_FROUND_NO_EXC)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f211(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_min_pd(_mm512_roundscale_pd(x, 0 | _MM_FROUND_NO_EXC), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f212(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_roundscale_pd(_mm512_max_pd(x, y), 0 | _MM_FROUND_NO_EXC); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f213(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_max_pd(_mm512_roundscale_pd(x, 0 | _MM_FROUND_NO_EXC), y); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f214(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_max_pd(x, _mm512_roundscale_pd(y, 0 | _MM_FROUND_NO_EXC)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f215(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_max_pd(_mm512_roundscale_pd(x, 0 | _MM_FROUND_NO_EXC), _mm512_roundscale_pd(y, 0 | _MM_FROUND_NO_EXC)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f216(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_max_pd(x, _mm512_roundscale_pd(x, 0 | _MM_FROUND_NO_EXC)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f217(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_max_pd(_mm512_roundscale_pd(x, 0 | _MM_FROUND_NO_EXC), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f218(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_roundscale_pd(_mm512_and_pd(x, y), 0 | _MM_FROUND_NO_EXC); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f219(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_and_pd(_mm512_roundscale_pd(x, 0 | _MM_FROUND_NO_EXC), y); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f220(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_and_pd(x, _mm512_roundscale_pd(y, 0 | _MM_FROUND_NO_EXC)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f221(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_and_pd(_mm512_roundscale_pd(x, 0 | _MM_FROUND_NO_EXC), _mm512_roundscale_pd(y, 0 | _MM_FROUND_NO_EXC)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f222(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_and_pd(x, _mm512_roundscale_pd(x, 0 | _MM_FROUND_NO_EXC)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f223(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_and_pd(_mm512_roundscale_pd(x, 0 | _MM_FROUND_NO_EXC), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f224(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_roundscale_pd(_mm512_or_pd(x, y), 0 | _MM_FROUND_NO_EXC); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f225(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_or_pd(_mm512_roundscale_pd(x, 0 | _MM_FROUND_NO_EXC), y); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f226(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_or_pd(x, _mm512_roundscale_pd(y, 0 | _MM_FROUND_NO_EXC)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f227(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_or_pd(_mm512_roundscale_pd(x, 0 | _MM_FROUND_NO_EXC), _mm512_roundscale_pd(y, 0 | _MM_FROUND_NO_EXC)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f228(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_or_pd(x, _mm512_roundscale_pd(x, 0 | _MM_FROUND_NO_EXC)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f229(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_or_pd(_mm512_roundscale_pd(x, 0 | _MM_FROUND_NO_EXC), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f230(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_roundscale_pd(_mm512_xor_pd(x, y), 0 | _MM_FROUND_NO_EXC); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f231(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_xor_pd(_mm512_roundscale_pd(x, 0 | _MM_FROUND_NO_EXC), y); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f232(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_xor_pd(x, _mm512_roundscale_pd(y, 0 | _MM_FROUND_NO_EXC)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f233(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_xor_pd(_mm512_roundscale_pd(x, 0 | _MM_FROUND_NO_EXC), _mm512_roundscale_pd(y, 0 | _MM_FROUND_NO_EXC)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f234(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_xor_pd(x, _mm512_roundscale_pd(x, 0 | _MM_FROUND_NO_EXC)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f235(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_xor_pd(_mm512_roundscale_pd(x, 0 | _MM_FROUND_NO_EXC), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f236(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_roundscale_pd(_mm512_andnot_pd(x, y), 0 | _MM_FROUND_NO_EXC); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f237(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_andnot_pd(_mm512_roundscale_pd(x, 0 | _MM_FROUND_NO_EXC), y); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f238(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_andnot_pd(x, _mm512_roundscale_pd(y, 0 | _MM_FROUND_NO_EXC)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f239(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_andnot_pd(_mm512_roundscale_pd(x, 0 | _MM_FROUND_NO_EXC), _mm512_roundscale_pd(y, 0 | _MM_FROUND_NO_EXC)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f240(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_andnot_pd(x, _mm512_roundscale_pd(x, 0 | _MM_FROUND_NO_EXC)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f241(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_andnot_pd(_mm512_roundscale_pd(x, 0 | _MM_FROUND_NO_EXC), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f242(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_add_pd(x, x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f243(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_add_pd(x, _mm512_setzero_pd()); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f244(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_add_pd(_mm512_setzero_pd(), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f245(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_add_pd(x, _mm512_set1_pd(-0.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f246(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_add_pd(_mm512_set1_pd(-0.0), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f247(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_add_pd(x, _mm512_set1_pd(1.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f248(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_add_pd(_mm512_set1_pd(1.0), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f249(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_add_pd(x, _mm512_set1_pd(-1.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f250(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_add_pd(_mm512_set1_pd(-1.0), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f251(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_add_pd(x, _mm512_set1_pd(std::numeric_limits<double>::infinity())); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f252(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_add_pd(_mm512_set1_pd(std::numeric_limits<double>::infinity()), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f253(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_add_pd(x, _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN())); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f254(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_add_pd(_mm512_set1_pd(std::numeric_limits<double>::quiet_NaN()), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f255(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_add_pd(_mm512_add_pd(x, _mm512_setzero_pd()), _mm512_setzero_pd()); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f256(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_add_pd(_mm512_add_pd(x, _mm512_setzero_pd()), _mm512_set1_pd(-0.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f257(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_add_pd(_mm512_add_pd(x, _mm512_setzero_pd()), _mm512_set1_pd(1.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f258(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_add_pd(_mm512_add_pd(x, _mm512_setzero_pd()), _mm512_set1_pd(-1.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f259(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_add_pd(_mm512_add_pd(x, _mm512_setzero_pd()), _mm512_set1_pd(std::numeric_limits<double>::infinity())); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f260(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_add_pd(_mm512_add_pd(x, _mm512_setzero_pd()), _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN())); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f261(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_add_pd(_mm512_add_pd(x, _mm512_set1_pd(-0.0)), _mm512_setzero_pd()); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f262(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_add_pd(_mm512_add_pd(x, _mm512_set1_pd(-0.0)), _mm512_set1_pd(-0.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f263(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_add_pd(_mm512_add_pd(x, _mm512_set1_pd(-0.0)), _mm512_set1_pd(1.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f264(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_add_pd(_mm512_add_pd(x, _mm512_set1_pd(-0.0)), _mm512_set1_pd(-1.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f265(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_add_pd(_mm512_add_pd(x, _mm512_set1_pd(-0.0)), _mm512_set1_pd(std::numeric_limits<double>::infinity())); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f266(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_add_pd(_mm512_add_pd(x, _mm512_set1_pd(-0.0)), _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN())); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f267(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_add_pd(_mm512_add_pd(x, _mm512_set1_pd(1.0)), _mm512_setzero_pd()); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f268(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_add_pd(_mm512_add_pd(x, _mm512_set1_pd(1.0)), _mm512_set1_pd(-0.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f269(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_add_pd(_mm512_add_pd(x, _mm512_set1_pd(1.0)), _mm512_set1_pd(1.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f270(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_add_pd(_mm512_add_pd(x, _mm512_set1_pd(1.0)), _mm512_set1_pd(-1.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f271(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_add_pd(_mm512_add_pd(x, _mm512_set1_pd(1.0)), _mm512_set1_pd(std::numeric_limits<double>::infinity())); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f272(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_add_pd(_mm512_add_pd(x, _mm512_set1_pd(1.0)), _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN())); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f273(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_add_pd(_mm512_add_pd(x, _mm512_set1_pd(-1.0)), _mm512_setzero_pd()); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f274(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_add_pd(_mm512_add_pd(x, _mm512_set1_pd(-1.0)), _mm512_set1_pd(-0.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f275(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_add_pd(_mm512_add_pd(x, _mm512_set1_pd(-1.0)), _mm512_set1_pd(1.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f276(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_add_pd(_mm512_add_pd(x, _mm512_set1_pd(-1.0)), _mm512_set1_pd(-1.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f277(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_add_pd(_mm512_add_pd(x, _mm512_set1_pd(-1.0)), _mm512_set1_pd(std::numeric_limits<double>::infinity())); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f278(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_add_pd(_mm512_add_pd(x, _mm512_set1_pd(-1.0)), _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN())); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f279(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_add_pd(_mm512_add_pd(x, _mm512_set1_pd(std::numeric_limits<double>::infinity())), _mm512_setzero_pd()); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f280(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_add_pd(_mm512_add_pd(x, _mm512_set1_pd(std::numeric_limits<double>::infinity())), _mm512_set1_pd(-0.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f281(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_add_pd(_mm512_add_pd(x, _mm512_set1_pd(std::numeric_limits<double>::infinity())), _mm512_set1_pd(1.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f282(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_add_pd(_mm512_add_pd(x, _mm512_set1_pd(std::numeric_limits<double>::infinity())), _mm512_set1_pd(-1.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f283(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_add_pd(_mm512_add_pd(x, _mm512_set1_pd(std::numeric_limits<double>::infinity())), _mm512_set1_pd(std::numeric_limits<double>::infinity())); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f284(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_add_pd(_mm512_add_pd(x, _mm512_set1_pd(std::numeric_limits<double>::infinity())), _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN())); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f285(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_add_pd(_mm512_add_pd(x, _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN())), _mm512_setzero_pd()); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f286(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_add_pd(_mm512_add_pd(x, _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN())), _mm512_set1_pd(-0.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f287(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_add_pd(_mm512_add_pd(x, _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN())), _mm512_set1_pd(1.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f288(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_add_pd(_mm512_add_pd(x, _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN())), _mm512_set1_pd(-1.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f289(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_add_pd(_mm512_add_pd(x, _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN())), _mm512_set1_pd(std::numeric_limits<double>::infinity())); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f290(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_add_pd(_mm512_add_pd(x, _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN())), _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN())); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f291(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_sub_pd(x, x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f292(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_sub_pd(x, _mm512_setzero_pd()); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f293(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_sub_pd(_mm512_setzero_pd(), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f294(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_sub_pd(x, _mm512_set1_pd(-0.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f295(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_sub_pd(_mm512_set1_pd(-0.0), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f296(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_sub_pd(x, _mm512_set1_pd(1.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f297(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_sub_pd(_mm512_set1_pd(1.0), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f298(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_sub_pd(x, _mm512_set1_pd(-1.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f299(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_sub_pd(_mm512_set1_pd(-1.0), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f300(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_sub_pd(x, _mm512_set1_pd(std::numeric_limits<double>::infinity())); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f301(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_sub_pd(_mm512_set1_pd(std::numeric_limits<double>::infinity()), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f302(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_sub_pd(x, _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN())); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f303(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_sub_pd(_mm512_set1_pd(std::numeric_limits<double>::quiet_NaN()), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f304(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_sub_pd(_mm512_sub_pd(x, _mm512_setzero_pd()), _mm512_setzero_pd()); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f305(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_sub_pd(_mm512_sub_pd(x, _mm512_setzero_pd()), _mm512_set1_pd(-0.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f306(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_sub_pd(_mm512_sub_pd(x, _mm512_setzero_pd()), _mm512_set1_pd(1.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f307(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_sub_pd(_mm512_sub_pd(x, _mm512_setzero_pd()), _mm512_set1_pd(-1.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f308(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_sub_pd(_mm512_sub_pd(x, _mm512_setzero_pd()), _mm512_set1_pd(std::numeric_limits<double>::infinity())); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f309(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_sub_pd(_mm512_sub_pd(x, _mm512_setzero_pd()), _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN())); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f310(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_sub_pd(_mm512_sub_pd(x, _mm512_set1_pd(-0.0)), _mm512_setzero_pd()); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f311(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_sub_pd(_mm512_sub_pd(x, _mm512_set1_pd(-0.0)), _mm512_set1_pd(-0.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f312(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_sub_pd(_mm512_sub_pd(x, _mm512_set1_pd(-0.0)), _mm512_set1_pd(1.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f313(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_sub_pd(_mm512_sub_pd(x, _mm512_set1_pd(-0.0)), _mm512_set1_pd(-1.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f314(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_sub_pd(_mm512_sub_pd(x, _mm512_set1_pd(-0.0)), _mm512_set1_pd(std::numeric_limits<double>::infinity())); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f315(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_sub_pd(_mm512_sub_pd(x, _mm512_set1_pd(-0.0)), _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN())); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f316(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_sub_pd(_mm512_sub_pd(x, _mm512_set1_pd(1.0)), _mm512_setzero_pd()); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f317(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_sub_pd(_mm512_sub_pd(x, _mm512_set1_pd(1.0)), _mm512_set1_pd(-0.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f318(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_sub_pd(_mm512_sub_pd(x, _mm512_set1_pd(1.0)), _mm512_set1_pd(1.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f319(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_sub_pd(_mm512_sub_pd(x, _mm512_set1_pd(1.0)), _mm512_set1_pd(-1.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f320(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_sub_pd(_mm512_sub_pd(x, _mm512_set1_pd(1.0)), _mm512_set1_pd(std::numeric_limits<double>::infinity())); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f321(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_sub_pd(_mm512_sub_pd(x, _mm512_set1_pd(1.0)), _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN())); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f322(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_sub_pd(_mm512_sub_pd(x, _mm512_set1_pd(-1.0)), _mm512_setzero_pd()); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f323(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_sub_pd(_mm512_sub_pd(x, _mm512_set1_pd(-1.0)), _mm512_set1_pd(-0.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f324(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_sub_pd(_mm512_sub_pd(x, _mm512_set1_pd(-1.0)), _mm512_set1_pd(1.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f325(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_sub_pd(_mm512_sub_pd(x, _mm512_set1_pd(-1.0)), _mm512_set1_pd(-1.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f326(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_sub_pd(_mm512_sub_pd(x, _mm512_set1_pd(-1.0)), _mm512_set1_pd(std::numeric_limits<double>::infinity())); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f327(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_sub_pd(_mm512_sub_pd(x, _mm512_set1_pd(-1.0)), _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN())); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f328(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_sub_pd(_mm512_sub_pd(x, _mm512_set1_pd(std::numeric_limits<double>::infinity())), _mm512_setzero_pd()); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f329(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_sub_pd(_mm512_sub_pd(x, _mm512_set1_pd(std::numeric_limits<double>::infinity())), _mm512_set1_pd(-0.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f330(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_sub_pd(_mm512_sub_pd(x, _mm512_set1_pd(std::numeric_limits<double>::infinity())), _mm512_set1_pd(1.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f331(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_sub_pd(_mm512_sub_pd(x, _mm512_set1_pd(std::numeric_limits<double>::infinity())), _mm512_set1_pd(-1.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f332(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_sub_pd(_mm512_sub_pd(x, _mm512_set1_pd(std::numeric_limits<double>::infinity())), _mm512_set1_pd(std::numeric_limits<double>::infinity())); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f333(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_sub_pd(_mm512_sub_pd(x, _mm512_set1_pd(std::numeric_limits<double>::infinity())), _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN())); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f334(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_sub_pd(_mm512_sub_pd(x, _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN())), _mm512_setzero_pd()); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f335(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_sub_pd(_mm512_sub_pd(x, _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN())), _mm512_set1_pd(-0.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f336(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_sub_pd(_mm512_sub_pd(x, _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN())), _mm512_set1_pd(1.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f337(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_sub_pd(_mm512_sub_pd(x, _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN())), _mm512_set1_pd(-1.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f338(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_sub_pd(_mm512_sub_pd(x, _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN())), _mm512_set1_pd(std::numeric_limits<double>::infinity())); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f339(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_sub_pd(_mm512_sub_pd(x, _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN())), _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN())); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f340(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_mul_pd(x, x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f341(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_mul_pd(x, _mm512_setzero_pd()); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f342(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_mul_pd(_mm512_setzero_pd(), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f343(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_mul_pd(x, _mm512_set1_pd(-0.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f344(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_mul_pd(_mm512_set1_pd(-0.0), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f345(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_mul_pd(x, _mm512_set1_pd(1.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f346(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_mul_pd(_mm512_set1_pd(1.0), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f347(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_mul_pd(x, _mm512_set1_pd(-1.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f348(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_mul_pd(_mm512_set1_pd(-1.0), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f349(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_mul_pd(x, _mm512_set1_pd(std::numeric_limits<double>::infinity())); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f350(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_mul_pd(_mm512_set1_pd(std::numeric_limits<double>::infinity()), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f351(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_mul_pd(x, _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN())); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f352(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_mul_pd(_mm512_set1_pd(std::numeric_limits<double>::quiet_NaN()), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f353(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_mul_pd(_mm512_mul_pd(x, _mm512_setzero_pd()), _mm512_setzero_pd()); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f354(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_mul_pd(_mm512_mul_pd(x, _mm512_setzero_pd()), _mm512_set1_pd(-0.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f355(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_mul_pd(_mm512_mul_pd(x, _mm512_setzero_pd()), _mm512_set1_pd(1.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f356(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_mul_pd(_mm512_mul_pd(x, _mm512_setzero_pd()), _mm512_set1_pd(-1.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f357(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_mul_pd(_mm512_mul_pd(x, _mm512_setzero_pd()), _mm512_set1_pd(std::numeric_limits<double>::infinity())); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f358(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_mul_pd(_mm512_mul_pd(x, _mm512_setzero_pd()), _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN())); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f359(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_mul_pd(_mm512_mul_pd(x, _mm512_set1_pd(-0.0)), _mm512_setzero_pd()); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f360(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_mul_pd(_mm512_mul_pd(x, _mm512_set1_pd(-0.0)), _mm512_set1_pd(-0.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f361(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_mul_pd(_mm512_mul_pd(x, _mm512_set1_pd(-0.0)), _mm512_set1_pd(1.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f362(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_mul_pd(_mm512_mul_pd(x, _mm512_set1_pd(-0.0)), _mm512_set1_pd(-1.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f363(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_mul_pd(_mm512_mul_pd(x, _mm512_set1_pd(-0.0)), _mm512_set1_pd(std::numeric_limits<double>::infinity())); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f364(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_mul_pd(_mm512_mul_pd(x, _mm512_set1_pd(-0.0)), _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN())); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f365(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_mul_pd(_mm512_mul_pd(x, _mm512_set1_pd(1.0)), _mm512_setzero_pd()); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f366(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_mul_pd(_mm512_mul_pd(x, _mm512_set1_pd(1.0)), _mm512_set1_pd(-0.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f367(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_mul_pd(_mm512_mul_pd(x, _mm512_set1_pd(1.0)), _mm512_set1_pd(1.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f368(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_mul_pd(_mm512_mul_pd(x, _mm512_set1_pd(1.0)), _mm512_set1_pd(-1.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f369(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_mul_pd(_mm512_mul_pd(x, _mm512_set1_pd(1.0)), _mm512_set1_pd(std::numeric_limits<double>::infinity())); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f370(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_mul_pd(_mm512_mul_pd(x, _mm512_set1_pd(1.0)), _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN())); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f371(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_mul_pd(_mm512_mul_pd(x, _mm512_set1_pd(-1.0)), _mm512_setzero_pd()); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f372(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_mul_pd(_mm512_mul_pd(x, _mm512_set1_pd(-1.0)), _mm512_set1_pd(-0.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f373(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_mul_pd(_mm512_mul_pd(x, _mm512_set1_pd(-1.0)), _mm512_set1_pd(1.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f374(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_mul_pd(_mm512_mul_pd(x, _mm512_set1_pd(-1.0)), _mm512_set1_pd(std::numeric_limits<double>::infinity())); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f375(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_mul_pd(_mm512_mul_pd(x, _mm512_set1_pd(-1.0)), _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN())); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f376(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_mul_pd(_mm512_mul_pd(x, _mm512_set1_pd(std::numeric_limits<double>::infinity())), _mm512_setzero_pd()); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f377(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_mul_pd(_mm512_mul_pd(x, _mm512_set1_pd(std::numeric_limits<double>::infinity())), _mm512_set1_pd(-0.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f378(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_mul_pd(_mm512_mul_pd(x, _mm512_set1_pd(std::numeric_limits<double>::infinity())), _mm512_set1_pd(1.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f379(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_mul_pd(_mm512_mul_pd(x, _mm512_set1_pd(std::numeric_limits<double>::infinity())), _mm512_set1_pd(-1.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f380(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_mul_pd(_mm512_mul_pd(x, _mm512_set1_pd(std::numeric_limits<double>::infinity())), _mm512_set1_pd(std::numeric_limits<double>::infinity())); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f381(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_mul_pd(_mm512_mul_pd(x, _mm512_set1_pd(std::numeric_limits<double>::infinity())), _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN())); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f382(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_mul_pd(_mm512_mul_pd(x, _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN())), _mm512_setzero_pd()); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f383(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_mul_pd(_mm512_mul_pd(x, _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN())), _mm512_set1_pd(-0.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f384(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_mul_pd(_mm512_mul_pd(x, _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN())), _mm512_set1_pd(1.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f385(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_mul_pd(_mm512_mul_pd(x, _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN())), _mm512_set1_pd(-1.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f386(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_mul_pd(_mm512_mul_pd(x, _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN())), _mm512_set1_pd(std::numeric_limits<double>::infinity())); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f387(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_mul_pd(_mm512_mul_pd(x, _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN())), _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN())); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f388(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_div_pd(x, x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f389(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_div_pd(x, _mm512_setzero_pd()); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f390(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_div_pd(_mm512_setzero_pd(), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f391(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_div_pd(x, _mm512_set1_pd(-0.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f392(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_div_pd(_mm512_set1_pd(-0.0), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f393(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_div_pd(x, _mm512_set1_pd(1.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f394(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_div_pd(_mm512_set1_pd(1.0), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f395(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_div_pd(x, _mm512_set1_pd(-1.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f396(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_div_pd(_mm512_set1_pd(-1.0), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f397(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_div_pd(x, _mm512_set1_pd(std::numeric_limits<double>::infinity())); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f398(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_div_pd(_mm512_set1_pd(std::numeric_limits<double>::infinity()), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f399(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_div_pd(x, _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN())); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f400(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_div_pd(_mm512_set1_pd(std::numeric_limits<double>::quiet_NaN()), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f401(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_div_pd(_mm512_div_pd(x, _mm512_setzero_pd()), _mm512_setzero_pd()); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f402(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_div_pd(_mm512_div_pd(x, _mm512_setzero_pd()), _mm512_set1_pd(-0.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f403(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_div_pd(_mm512_div_pd(x, _mm512_setzero_pd()), _mm512_set1_pd(1.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f404(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_div_pd(_mm512_div_pd(x, _mm512_setzero_pd()), _mm512_set1_pd(-1.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f405(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_div_pd(_mm512_div_pd(x, _mm512_setzero_pd()), _mm512_set1_pd(std::numeric_limits<double>::infinity())); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f406(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_div_pd(_mm512_div_pd(x, _mm512_setzero_pd()), _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN())); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f407(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_div_pd(_mm512_div_pd(x, _mm512_set1_pd(-0.0)), _mm512_setzero_pd()); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f408(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_div_pd(_mm512_div_pd(x, _mm512_set1_pd(-0.0)), _mm512_set1_pd(-0.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f409(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_div_pd(_mm512_div_pd(x, _mm512_set1_pd(-0.0)), _mm512_set1_pd(1.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f410(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_div_pd(_mm512_div_pd(x, _mm512_set1_pd(-0.0)), _mm512_set1_pd(-1.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f411(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_div_pd(_mm512_div_pd(x, _mm512_set1_pd(-0.0)), _mm512_set1_pd(std::numeric_limits<double>::infinity())); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f412(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_div_pd(_mm512_div_pd(x, _mm512_set1_pd(-0.0)), _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN())); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f413(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_div_pd(_mm512_div_pd(x, _mm512_set1_pd(1.0)), _mm512_setzero_pd()); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f414(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_div_pd(_mm512_div_pd(x, _mm512_set1_pd(1.0)), _mm512_set1_pd(-0.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f415(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_div_pd(_mm512_div_pd(x, _mm512_set1_pd(1.0)), _mm512_set1_pd(1.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f416(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_div_pd(_mm512_div_pd(x, _mm512_set1_pd(1.0)), _mm512_set1_pd(-1.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f417(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_div_pd(_mm512_div_pd(x, _mm512_set1_pd(1.0)), _mm512_set1_pd(std::numeric_limits<double>::infinity())); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f418(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_div_pd(_mm512_div_pd(x, _mm512_set1_pd(1.0)), _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN())); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f419(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_div_pd(_mm512_div_pd(x, _mm512_set1_pd(-1.0)), _mm512_setzero_pd()); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f420(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_div_pd(_mm512_div_pd(x, _mm512_set1_pd(-1.0)), _mm512_set1_pd(-0.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f421(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_div_pd(_mm512_div_pd(x, _mm512_set1_pd(-1.0)), _mm512_set1_pd(1.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f422(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_div_pd(_mm512_div_pd(x, _mm512_set1_pd(-1.0)), _mm512_set1_pd(-1.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f423(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_div_pd(_mm512_div_pd(x, _mm512_set1_pd(-1.0)), _mm512_set1_pd(std::numeric_limits<double>::infinity())); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f424(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_div_pd(_mm512_div_pd(x, _mm512_set1_pd(-1.0)), _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN())); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f425(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_div_pd(_mm512_div_pd(x, _mm512_set1_pd(std::numeric_limits<double>::infinity())), _mm512_setzero_pd()); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f426(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_div_pd(_mm512_div_pd(x, _mm512_set1_pd(std::numeric_limits<double>::infinity())), _mm512_set1_pd(-0.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f427(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_div_pd(_mm512_div_pd(x, _mm512_set1_pd(std::numeric_limits<double>::infinity())), _mm512_set1_pd(1.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f428(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_div_pd(_mm512_div_pd(x, _mm512_set1_pd(std::numeric_limits<double>::infinity())), _mm512_set1_pd(-1.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f429(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_div_pd(_mm512_div_pd(x, _mm512_set1_pd(std::numeric_limits<double>::infinity())), _mm512_set1_pd(std::numeric_limits<double>::infinity())); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f430(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_div_pd(_mm512_div_pd(x, _mm512_set1_pd(std::numeric_limits<double>::infinity())), _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN())); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f431(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_div_pd(_mm512_div_pd(x, _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN())), _mm512_setzero_pd()); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f432(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_div_pd(_mm512_div_pd(x, _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN())), _mm512_set1_pd(-0.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f433(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_div_pd(_mm512_div_pd(x, _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN())), _mm512_set1_pd(1.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f434(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_div_pd(_mm512_div_pd(x, _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN())), _mm512_set1_pd(-1.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f435(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_div_pd(_mm512_div_pd(x, _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN())), _mm512_set1_pd(std::numeric_limits<double>::infinity())); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f436(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_div_pd(_mm512_div_pd(x, _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN())), _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN())); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f437(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_min_pd(x, x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f438(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_min_pd(x, _mm512_setzero_pd()); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f439(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_min_pd(_mm512_setzero_pd(), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f440(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_min_pd(x, _mm512_set1_pd(-0.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f441(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_min_pd(_mm512_set1_pd(-0.0), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f442(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_min_pd(x, _mm512_set1_pd(1.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f443(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_min_pd(_mm512_set1_pd(1.0), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f444(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_min_pd(x, _mm512_set1_pd(-1.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f445(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_min_pd(_mm512_set1_pd(-1.0), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f446(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_min_pd(x, _mm512_set1_pd(std::numeric_limits<double>::infinity())); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f447(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_min_pd(_mm512_set1_pd(std::numeric_limits<double>::infinity()), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f448(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_min_pd(x, _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN())); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f449(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_min_pd(_mm512_set1_pd(std::numeric_limits<double>::quiet_NaN()), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f450(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_min_pd(_mm512_min_pd(x, _mm512_setzero_pd()), _mm512_setzero_pd()); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f451(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_min_pd(_mm512_min_pd(x, _mm512_setzero_pd()), _mm512_set1_pd(-0.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f452(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_min_pd(_mm512_min_pd(x, _mm512_setzero_pd()), _mm512_set1_pd(1.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f453(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_min_pd(_mm512_min_pd(x, _mm512_setzero_pd()), _mm512_set1_pd(-1.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f454(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_min_pd(_mm512_min_pd(x, _mm512_setzero_pd()), _mm512_set1_pd(std::numeric_limits<double>::infinity())); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f455(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_min_pd(_mm512_min_pd(x, _mm512_setzero_pd()), _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN())); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f456(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_min_pd(_mm512_min_pd(x, _mm512_set1_pd(-0.0)), _mm512_setzero_pd()); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f457(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_min_pd(_mm512_min_pd(x, _mm512_set1_pd(-0.0)), _mm512_set1_pd(-0.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f458(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_min_pd(_mm512_min_pd(x, _mm512_set1_pd(-0.0)), _mm512_set1_pd(1.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f459(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_min_pd(_mm512_min_pd(x, _mm512_set1_pd(-0.0)), _mm512_set1_pd(-1.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f460(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_min_pd(_mm512_min_pd(x, _mm512_set1_pd(-0.0)), _mm512_set1_pd(std::numeric_limits<double>::infinity())); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f461(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_min_pd(_mm512_min_pd(x, _mm512_set1_pd(-0.0)), _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN())); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f462(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_min_pd(_mm512_min_pd(x, _mm512_set1_pd(1.0)), _mm512_setzero_pd()); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f463(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_min_pd(_mm512_min_pd(x, _mm512_set1_pd(1.0)), _mm512_set1_pd(-0.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f464(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_min_pd(_mm512_min_pd(x, _mm512_set1_pd(1.0)), _mm512_set1_pd(1.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f465(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_min_pd(_mm512_min_pd(x, _mm512_set1_pd(1.0)), _mm512_set1_pd(-1.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f466(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_min_pd(_mm512_min_pd(x, _mm512_set1_pd(1.0)), _mm512_set1_pd(std::numeric_limits<double>::infinity())); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f467(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_min_pd(_mm512_min_pd(x, _mm512_set1_pd(1.0)), _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN())); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f468(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_min_pd(_mm512_min_pd(x, _mm512_set1_pd(-1.0)), _mm512_setzero_pd()); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f469(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_min_pd(_mm512_min_pd(x, _mm512_set1_pd(-1.0)), _mm512_set1_pd(-0.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f470(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_min_pd(_mm512_min_pd(x, _mm512_set1_pd(-1.0)), _mm512_set1_pd(1.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f471(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_min_pd(_mm512_min_pd(x, _mm512_set1_pd(-1.0)), _mm512_set1_pd(-1.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f472(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_min_pd(_mm512_min_pd(x, _mm512_set1_pd(-1.0)), _mm512_set1_pd(std::numeric_limits<double>::infinity())); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f473(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_min_pd(_mm512_min_pd(x, _mm512_set1_pd(-1.0)), _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN())); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f474(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_min_pd(_mm512_min_pd(x, _mm512_set1_pd(std::numeric_limits<double>::infinity())), _mm512_setzero_pd()); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f475(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_min_pd(_mm512_min_pd(x, _mm512_set1_pd(std::numeric_limits<double>::infinity())), _mm512_set1_pd(-0.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f476(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_min_pd(_mm512_min_pd(x, _mm512_set1_pd(std::numeric_limits<double>::infinity())), _mm512_set1_pd(1.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f477(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_min_pd(_mm512_min_pd(x, _mm512_set1_pd(std::numeric_limits<double>::infinity())), _mm512_set1_pd(-1.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f478(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_min_pd(_mm512_min_pd(x, _mm512_set1_pd(std::numeric_limits<double>::infinity())), _mm512_set1_pd(std::numeric_limits<double>::infinity())); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f479(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_min_pd(_mm512_min_pd(x, _mm512_set1_pd(std::numeric_limits<double>::infinity())), _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN())); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f480(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_min_pd(_mm512_min_pd(x, _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN())), _mm512_setzero_pd()); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f481(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_min_pd(_mm512_min_pd(x, _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN())), _mm512_set1_pd(-0.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f482(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_min_pd(_mm512_min_pd(x, _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN())), _mm512_set1_pd(1.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f483(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_min_pd(_mm512_min_pd(x, _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN())), _mm512_set1_pd(-1.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f484(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_min_pd(_mm512_min_pd(x, _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN())), _mm512_set1_pd(std::numeric_limits<double>::infinity())); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f485(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_min_pd(_mm512_min_pd(x, _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN())), _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN())); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f486(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_max_pd(x, x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f487(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_max_pd(x, _mm512_setzero_pd()); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f488(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_max_pd(_mm512_setzero_pd(), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f489(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_max_pd(x, _mm512_set1_pd(-0.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f490(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_max_pd(_mm512_set1_pd(-0.0), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f491(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_max_pd(x, _mm512_set1_pd(1.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f492(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_max_pd(_mm512_set1_pd(1.0), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f493(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_max_pd(x, _mm512_set1_pd(-1.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f494(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_max_pd(_mm512_set1_pd(-1.0), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f495(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_max_pd(x, _mm512_set1_pd(std::numeric_limits<double>::infinity())); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f496(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_max_pd(_mm512_set1_pd(std::numeric_limits<double>::infinity()), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f497(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_max_pd(x, _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN())); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f498(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_max_pd(_mm512_set1_pd(std::numeric_limits<double>::quiet_NaN()), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f499(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_max_pd(_mm512_max_pd(x, _mm512_setzero_pd()), _mm512_setzero_pd()); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f500(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_max_pd(_mm512_max_pd(x, _mm512_setzero_pd()), _mm512_set1_pd(-0.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f501(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_max_pd(_mm512_max_pd(x, _mm512_setzero_pd()), _mm512_set1_pd(1.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f502(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_max_pd(_mm512_max_pd(x, _mm512_setzero_pd()), _mm512_set1_pd(-1.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f503(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_max_pd(_mm512_max_pd(x, _mm512_setzero_pd()), _mm512_set1_pd(std::numeric_limits<double>::infinity())); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f504(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_max_pd(_mm512_max_pd(x, _mm512_setzero_pd()), _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN())); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f505(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_max_pd(_mm512_max_pd(x, _mm512_set1_pd(-0.0)), _mm512_setzero_pd()); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f506(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_max_pd(_mm512_max_pd(x, _mm512_set1_pd(-0.0)), _mm512_set1_pd(-0.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f507(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_max_pd(_mm512_max_pd(x, _mm512_set1_pd(-0.0)), _mm512_set1_pd(1.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f508(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_max_pd(_mm512_max_pd(x, _mm512_set1_pd(-0.0)), _mm512_set1_pd(-1.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f509(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_max_pd(_mm512_max_pd(x, _mm512_set1_pd(-0.0)), _mm512_set1_pd(std::numeric_limits<double>::infinity())); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f510(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_max_pd(_mm512_max_pd(x, _mm512_set1_pd(-0.0)), _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN())); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f511(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_max_pd(_mm512_max_pd(x, _mm512_set1_pd(1.0)), _mm512_setzero_pd()); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f512(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_max_pd(_mm512_max_pd(x, _mm512_set1_pd(1.0)), _mm512_set1_pd(-0.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f513(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_max_pd(_mm512_max_pd(x, _mm512_set1_pd(1.0)), _mm512_set1_pd(1.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f514(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_max_pd(_mm512_max_pd(x, _mm512_set1_pd(1.0)), _mm512_set1_pd(-1.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f515(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_max_pd(_mm512_max_pd(x, _mm512_set1_pd(1.0)), _mm512_set1_pd(std::numeric_limits<double>::infinity())); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f516(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_max_pd(_mm512_max_pd(x, _mm512_set1_pd(1.0)), _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN())); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f517(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_max_pd(_mm512_max_pd(x, _mm512_set1_pd(-1.0)), _mm512_setzero_pd()); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f518(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_max_pd(_mm512_max_pd(x, _mm512_set1_pd(-1.0)), _mm512_set1_pd(-0.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f519(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_max_pd(_mm512_max_pd(x, _mm512_set1_pd(-1.0)), _mm512_set1_pd(1.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f520(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_max_pd(_mm512_max_pd(x, _mm512_set1_pd(-1.0)), _mm512_set1_pd(-1.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f521(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_max_pd(_mm512_max_pd(x, _mm512_set1_pd(-1.0)), _mm512_set1_pd(std::numeric_limits<double>::infinity())); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f522(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_max_pd(_mm512_max_pd(x, _mm512_set1_pd(-1.0)), _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN())); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f523(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_max_pd(_mm512_max_pd(x, _mm512_set1_pd(std::numeric_limits<double>::infinity())), _mm512_setzero_pd()); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f524(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_max_pd(_mm512_max_pd(x, _mm512_set1_pd(std::numeric_limits<double>::infinity())), _mm512_set1_pd(-0.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f525(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_max_pd(_mm512_max_pd(x, _mm512_set1_pd(std::numeric_limits<double>::infinity())), _mm512_set1_pd(1.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f526(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_max_pd(_mm512_max_pd(x, _mm512_set1_pd(std::numeric_limits<double>::infinity())), _mm512_set1_pd(-1.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f527(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_max_pd(_mm512_max_pd(x, _mm512_set1_pd(std::numeric_limits<double>::infinity())), _mm512_set1_pd(std::numeric_limits<double>::infinity())); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f528(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_max_pd(_mm512_max_pd(x, _mm512_set1_pd(std::numeric_limits<double>::infinity())), _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN())); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f529(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_max_pd(_mm512_max_pd(x, _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN())), _mm512_setzero_pd()); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f530(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_max_pd(_mm512_max_pd(x, _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN())), _mm512_set1_pd(-0.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f531(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_max_pd(_mm512_max_pd(x, _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN())), _mm512_set1_pd(1.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f532(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_max_pd(_mm512_max_pd(x, _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN())), _mm512_set1_pd(-1.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f533(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_max_pd(_mm512_max_pd(x, _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN())), _mm512_set1_pd(std::numeric_limits<double>::infinity())); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f534(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_max_pd(_mm512_max_pd(x, _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN())), _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN())); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f535(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_and_pd(x, x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f536(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_and_pd(x, _mm512_setzero_pd()); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f537(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_and_pd(_mm512_setzero_pd(), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f538(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_and_pd(x, _mm512_set1_pd(-0.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f539(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_and_pd(_mm512_set1_pd(-0.0), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f540(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_and_pd(x, _mm512_set1_pd(1.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f541(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_and_pd(_mm512_set1_pd(1.0), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f542(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_and_pd(x, _mm512_set1_pd(-1.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f543(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_and_pd(_mm512_set1_pd(-1.0), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f544(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_and_pd(x, _mm512_set1_pd(std::numeric_limits<double>::infinity())); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f545(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_and_pd(_mm512_set1_pd(std::numeric_limits<double>::infinity()), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f546(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_and_pd(x, _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN())); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f547(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_and_pd(_mm512_set1_pd(std::numeric_limits<double>::quiet_NaN()), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f548(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_and_pd(_mm512_and_pd(x, _mm512_setzero_pd()), _mm512_setzero_pd()); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f549(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_and_pd(_mm512_and_pd(x, _mm512_setzero_pd()), _mm512_set1_pd(-0.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f550(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_and_pd(_mm512_and_pd(x, _mm512_setzero_pd()), _mm512_set1_pd(1.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f551(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_and_pd(_mm512_and_pd(x, _mm512_setzero_pd()), _mm512_set1_pd(-1.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f552(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_and_pd(_mm512_and_pd(x, _mm512_setzero_pd()), _mm512_set1_pd(std::numeric_limits<double>::infinity())); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f553(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_and_pd(_mm512_and_pd(x, _mm512_setzero_pd()), _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN())); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f554(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_and_pd(_mm512_and_pd(x, _mm512_set1_pd(-0.0)), _mm512_setzero_pd()); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f555(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_and_pd(_mm512_and_pd(x, _mm512_set1_pd(-0.0)), _mm512_set1_pd(-0.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f556(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_and_pd(_mm512_and_pd(x, _mm512_set1_pd(-0.0)), _mm512_set1_pd(1.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f557(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_and_pd(_mm512_and_pd(x, _mm512_set1_pd(-0.0)), _mm512_set1_pd(-1.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f558(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_and_pd(_mm512_and_pd(x, _mm512_set1_pd(-0.0)), _mm512_set1_pd(std::numeric_limits<double>::infinity())); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f559(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_and_pd(_mm512_and_pd(x, _mm512_set1_pd(-0.0)), _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN())); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f560(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_and_pd(_mm512_and_pd(x, _mm512_set1_pd(1.0)), _mm512_setzero_pd()); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f561(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_and_pd(_mm512_and_pd(x, _mm512_set1_pd(1.0)), _mm512_set1_pd(-0.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f562(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_and_pd(_mm512_and_pd(x, _mm512_set1_pd(1.0)), _mm512_set1_pd(1.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f563(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_and_pd(_mm512_and_pd(x, _mm512_set1_pd(1.0)), _mm512_set1_pd(-1.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f564(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_and_pd(_mm512_and_pd(x, _mm512_set1_pd(1.0)), _mm512_set1_pd(std::numeric_limits<double>::infinity())); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f565(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_and_pd(_mm512_and_pd(x, _mm512_set1_pd(1.0)), _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN())); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f566(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_and_pd(_mm512_and_pd(x, _mm512_set1_pd(-1.0)), _mm512_setzero_pd()); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f567(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_and_pd(_mm512_and_pd(x, _mm512_set1_pd(-1.0)), _mm512_set1_pd(-0.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f568(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_and_pd(_mm512_and_pd(x, _mm512_set1_pd(-1.0)), _mm512_set1_pd(1.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f569(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_and_pd(_mm512_and_pd(x, _mm512_set1_pd(-1.0)), _mm512_set1_pd(-1.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f570(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_and_pd(_mm512_and_pd(x, _mm512_set1_pd(-1.0)), _mm512_set1_pd(std::numeric_limits<double>::infinity())); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f571(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_and_pd(_mm512_and_pd(x, _mm512_set1_pd(-1.0)), _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN())); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f572(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_and_pd(_mm512_and_pd(x, _mm512_set1_pd(std::numeric_limits<double>::infinity())), _mm512_setzero_pd()); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f573(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_and_pd(_mm512_and_pd(x, _mm512_set1_pd(std::numeric_limits<double>::infinity())), _mm512_set1_pd(-0.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f574(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_and_pd(_mm512_and_pd(x, _mm512_set1_pd(std::numeric_limits<double>::infinity())), _mm512_set1_pd(1.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f575(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_and_pd(_mm512_and_pd(x, _mm512_set1_pd(std::numeric_limits<double>::infinity())), _mm512_set1_pd(-1.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f576(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_and_pd(_mm512_and_pd(x, _mm512_set1_pd(std::numeric_limits<double>::infinity())), _mm512_set1_pd(std::numeric_limits<double>::infinity())); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f577(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_and_pd(_mm512_and_pd(x, _mm512_set1_pd(std::numeric_limits<double>::infinity())), _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN())); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f578(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_and_pd(_mm512_and_pd(x, _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN())), _mm512_setzero_pd()); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f579(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_and_pd(_mm512_and_pd(x, _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN())), _mm512_set1_pd(-0.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f580(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_and_pd(_mm512_and_pd(x, _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN())), _mm512_set1_pd(1.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f581(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_and_pd(_mm512_and_pd(x, _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN())), _mm512_set1_pd(-1.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f582(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_and_pd(_mm512_and_pd(x, _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN())), _mm512_set1_pd(std::numeric_limits<double>::infinity())); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f583(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_and_pd(_mm512_and_pd(x, _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN())), _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN())); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f584(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_or_pd(x, x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f585(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_or_pd(x, _mm512_setzero_pd()); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f586(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_or_pd(_mm512_setzero_pd(), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f587(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_or_pd(x, _mm512_set1_pd(-0.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f588(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_or_pd(_mm512_set1_pd(-0.0), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f589(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_or_pd(x, _mm512_set1_pd(1.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f590(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_or_pd(_mm512_set1_pd(1.0), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f591(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_or_pd(x, _mm512_set1_pd(-1.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f592(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_or_pd(_mm512_set1_pd(-1.0), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f593(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_or_pd(x, _mm512_set1_pd(std::numeric_limits<double>::infinity())); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f594(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_or_pd(_mm512_set1_pd(std::numeric_limits<double>::infinity()), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f595(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_or_pd(x, _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN())); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f596(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_or_pd(_mm512_set1_pd(std::numeric_limits<double>::quiet_NaN()), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f597(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_or_pd(_mm512_or_pd(x, _mm512_setzero_pd()), _mm512_setzero_pd()); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f598(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_or_pd(_mm512_or_pd(x, _mm512_setzero_pd()), _mm512_set1_pd(-0.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f599(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_or_pd(_mm512_or_pd(x, _mm512_setzero_pd()), _mm512_set1_pd(1.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f600(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_or_pd(_mm512_or_pd(x, _mm512_setzero_pd()), _mm512_set1_pd(-1.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f601(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_or_pd(_mm512_or_pd(x, _mm512_setzero_pd()), _mm512_set1_pd(std::numeric_limits<double>::infinity())); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f602(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_or_pd(_mm512_or_pd(x, _mm512_setzero_pd()), _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN())); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f603(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_or_pd(_mm512_or_pd(x, _mm512_set1_pd(-0.0)), _mm512_setzero_pd()); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f604(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_or_pd(_mm512_or_pd(x, _mm512_set1_pd(-0.0)), _mm512_set1_pd(-0.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f605(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_or_pd(_mm512_or_pd(x, _mm512_set1_pd(-0.0)), _mm512_set1_pd(1.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f606(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_or_pd(_mm512_or_pd(x, _mm512_set1_pd(-0.0)), _mm512_set1_pd(-1.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f607(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_or_pd(_mm512_or_pd(x, _mm512_set1_pd(-0.0)), _mm512_set1_pd(std::numeric_limits<double>::infinity())); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f608(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_or_pd(_mm512_or_pd(x, _mm512_set1_pd(-0.0)), _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN())); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f609(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_or_pd(_mm512_or_pd(x, _mm512_set1_pd(1.0)), _mm512_setzero_pd()); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f610(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_or_pd(_mm512_or_pd(x, _mm512_set1_pd(1.0)), _mm512_set1_pd(-0.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f611(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_or_pd(_mm512_or_pd(x, _mm512_set1_pd(1.0)), _mm512_set1_pd(1.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f612(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_or_pd(_mm512_or_pd(x, _mm512_set1_pd(1.0)), _mm512_set1_pd(-1.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f613(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_or_pd(_mm512_or_pd(x, _mm512_set1_pd(1.0)), _mm512_set1_pd(std::numeric_limits<double>::infinity())); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f614(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_or_pd(_mm512_or_pd(x, _mm512_set1_pd(1.0)), _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN())); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f615(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_or_pd(_mm512_or_pd(x, _mm512_set1_pd(-1.0)), _mm512_setzero_pd()); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f616(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_or_pd(_mm512_or_pd(x, _mm512_set1_pd(-1.0)), _mm512_set1_pd(-0.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f617(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_or_pd(_mm512_or_pd(x, _mm512_set1_pd(-1.0)), _mm512_set1_pd(1.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f618(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_or_pd(_mm512_or_pd(x, _mm512_set1_pd(-1.0)), _mm512_set1_pd(-1.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f619(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_or_pd(_mm512_or_pd(x, _mm512_set1_pd(-1.0)), _mm512_set1_pd(std::numeric_limits<double>::infinity())); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f620(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_or_pd(_mm512_or_pd(x, _mm512_set1_pd(-1.0)), _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN())); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f621(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_or_pd(_mm512_or_pd(x, _mm512_set1_pd(std::numeric_limits<double>::infinity())), _mm512_setzero_pd()); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f622(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_or_pd(_mm512_or_pd(x, _mm512_set1_pd(std::numeric_limits<double>::infinity())), _mm512_set1_pd(-0.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f623(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_or_pd(_mm512_or_pd(x, _mm512_set1_pd(std::numeric_limits<double>::infinity())), _mm512_set1_pd(1.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f624(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_or_pd(_mm512_or_pd(x, _mm512_set1_pd(std::numeric_limits<double>::infinity())), _mm512_set1_pd(-1.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f625(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_or_pd(_mm512_or_pd(x, _mm512_set1_pd(std::numeric_limits<double>::infinity())), _mm512_set1_pd(std::numeric_limits<double>::infinity())); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f626(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_or_pd(_mm512_or_pd(x, _mm512_set1_pd(std::numeric_limits<double>::infinity())), _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN())); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f627(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_or_pd(_mm512_or_pd(x, _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN())), _mm512_setzero_pd()); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f628(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_or_pd(_mm512_or_pd(x, _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN())), _mm512_set1_pd(-0.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f629(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_or_pd(_mm512_or_pd(x, _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN())), _mm512_set1_pd(1.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f630(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_or_pd(_mm512_or_pd(x, _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN())), _mm512_set1_pd(-1.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f631(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_or_pd(_mm512_or_pd(x, _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN())), _mm512_set1_pd(std::numeric_limits<double>::infinity())); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f632(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_or_pd(_mm512_or_pd(x, _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN())), _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN())); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f633(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_xor_pd(x, x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f634(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_xor_pd(x, _mm512_setzero_pd()); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f635(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_xor_pd(_mm512_setzero_pd(), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f636(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_xor_pd(x, _mm512_set1_pd(-0.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f637(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_xor_pd(_mm512_set1_pd(-0.0), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f638(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_xor_pd(x, _mm512_set1_pd(1.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f639(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_xor_pd(_mm512_set1_pd(1.0), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f640(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_xor_pd(x, _mm512_set1_pd(-1.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f641(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_xor_pd(_mm512_set1_pd(-1.0), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f642(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_xor_pd(x, _mm512_set1_pd(std::numeric_limits<double>::infinity())); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f643(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_xor_pd(_mm512_set1_pd(std::numeric_limits<double>::infinity()), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f644(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_xor_pd(x, _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN())); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f645(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_xor_pd(_mm512_set1_pd(std::numeric_limits<double>::quiet_NaN()), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f646(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_xor_pd(_mm512_xor_pd(x, _mm512_setzero_pd()), _mm512_setzero_pd()); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f647(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_xor_pd(_mm512_xor_pd(x, _mm512_setzero_pd()), _mm512_set1_pd(-0.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f648(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_xor_pd(_mm512_xor_pd(x, _mm512_setzero_pd()), _mm512_set1_pd(1.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f649(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_xor_pd(_mm512_xor_pd(x, _mm512_setzero_pd()), _mm512_set1_pd(-1.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f650(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_xor_pd(_mm512_xor_pd(x, _mm512_setzero_pd()), _mm512_set1_pd(std::numeric_limits<double>::infinity())); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f651(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_xor_pd(_mm512_xor_pd(x, _mm512_setzero_pd()), _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN())); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f652(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_xor_pd(_mm512_xor_pd(x, _mm512_set1_pd(-0.0)), _mm512_setzero_pd()); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f653(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_xor_pd(_mm512_xor_pd(x, _mm512_set1_pd(-0.0)), _mm512_set1_pd(1.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f654(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_xor_pd(_mm512_xor_pd(x, _mm512_set1_pd(-0.0)), _mm512_set1_pd(-1.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f655(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_xor_pd(_mm512_xor_pd(x, _mm512_set1_pd(-0.0)), _mm512_set1_pd(std::numeric_limits<double>::infinity())); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f656(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_xor_pd(_mm512_xor_pd(x, _mm512_set1_pd(-0.0)), _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN())); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f657(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_xor_pd(_mm512_xor_pd(x, _mm512_set1_pd(1.0)), _mm512_setzero_pd()); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f658(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_xor_pd(_mm512_xor_pd(x, _mm512_set1_pd(1.0)), _mm512_set1_pd(-0.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f659(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_xor_pd(_mm512_xor_pd(x, _mm512_set1_pd(1.0)), _mm512_set1_pd(1.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f660(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_xor_pd(_mm512_xor_pd(x, _mm512_set1_pd(1.0)), _mm512_set1_pd(-1.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f661(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_xor_pd(_mm512_xor_pd(x, _mm512_set1_pd(1.0)), _mm512_set1_pd(std::numeric_limits<double>::infinity())); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f662(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_xor_pd(_mm512_xor_pd(x, _mm512_set1_pd(1.0)), _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN())); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f663(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_xor_pd(_mm512_xor_pd(x, _mm512_set1_pd(-1.0)), _mm512_setzero_pd()); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f664(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_xor_pd(_mm512_xor_pd(x, _mm512_set1_pd(-1.0)), _mm512_set1_pd(-0.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f665(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_xor_pd(_mm512_xor_pd(x, _mm512_set1_pd(-1.0)), _mm512_set1_pd(1.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f666(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_xor_pd(_mm512_xor_pd(x, _mm512_set1_pd(-1.0)), _mm512_set1_pd(-1.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f667(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_xor_pd(_mm512_xor_pd(x, _mm512_set1_pd(-1.0)), _mm512_set1_pd(std::numeric_limits<double>::infinity())); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f668(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_xor_pd(_mm512_xor_pd(x, _mm512_set1_pd(-1.0)), _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN())); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f669(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_xor_pd(_mm512_xor_pd(x, _mm512_set1_pd(std::numeric_limits<double>::infinity())), _mm512_setzero_pd()); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f670(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_xor_pd(_mm512_xor_pd(x, _mm512_set1_pd(std::numeric_limits<double>::infinity())), _mm512_set1_pd(-0.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f671(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_xor_pd(_mm512_xor_pd(x, _mm512_set1_pd(std::numeric_limits<double>::infinity())), _mm512_set1_pd(1.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f672(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_xor_pd(_mm512_xor_pd(x, _mm512_set1_pd(std::numeric_limits<double>::infinity())), _mm512_set1_pd(-1.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f673(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_xor_pd(_mm512_xor_pd(x, _mm512_set1_pd(std::numeric_limits<double>::infinity())), _mm512_set1_pd(std::numeric_limits<double>::infinity())); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f674(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_xor_pd(_mm512_xor_pd(x, _mm512_set1_pd(std::numeric_limits<double>::infinity())), _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN())); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f675(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_xor_pd(_mm512_xor_pd(x, _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN())), _mm512_setzero_pd()); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f676(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_xor_pd(_mm512_xor_pd(x, _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN())), _mm512_set1_pd(-0.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f677(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_xor_pd(_mm512_xor_pd(x, _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN())), _mm512_set1_pd(1.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f678(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_xor_pd(_mm512_xor_pd(x, _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN())), _mm512_set1_pd(-1.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f679(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_xor_pd(_mm512_xor_pd(x, _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN())), _mm512_set1_pd(std::numeric_limits<double>::infinity())); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f680(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_xor_pd(_mm512_xor_pd(x, _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN())), _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN())); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f681(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_andnot_pd(x, x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f682(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_andnot_pd(x, _mm512_setzero_pd()); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f683(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_andnot_pd(_mm512_setzero_pd(), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f684(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_andnot_pd(x, _mm512_set1_pd(-0.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f685(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_andnot_pd(_mm512_set1_pd(-0.0), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f686(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_andnot_pd(x, _mm512_set1_pd(1.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f687(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_andnot_pd(_mm512_set1_pd(1.0), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f688(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_andnot_pd(x, _mm512_set1_pd(-1.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f689(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_andnot_pd(_mm512_set1_pd(-1.0), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f690(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_andnot_pd(x, _mm512_set1_pd(std::numeric_limits<double>::infinity())); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f691(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_andnot_pd(_mm512_set1_pd(std::numeric_limits<double>::infinity()), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f692(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_andnot_pd(x, _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN())); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f693(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_andnot_pd(_mm512_set1_pd(std::numeric_limits<double>::quiet_NaN()), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f694(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_andnot_pd(_mm512_andnot_pd(x, _mm512_setzero_pd()), _mm512_setzero_pd()); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f695(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_andnot_pd(_mm512_andnot_pd(x, _mm512_setzero_pd()), _mm512_set1_pd(-0.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f696(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_andnot_pd(_mm512_andnot_pd(x, _mm512_setzero_pd()), _mm512_set1_pd(1.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f697(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_andnot_pd(_mm512_andnot_pd(x, _mm512_setzero_pd()), _mm512_set1_pd(-1.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f698(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_andnot_pd(_mm512_andnot_pd(x, _mm512_setzero_pd()), _mm512_set1_pd(std::numeric_limits<double>::infinity())); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f699(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_andnot_pd(_mm512_andnot_pd(x, _mm512_setzero_pd()), _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN())); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f700(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_andnot_pd(_mm512_andnot_pd(x, _mm512_set1_pd(-0.0)), _mm512_setzero_pd()); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f701(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_andnot_pd(_mm512_andnot_pd(x, _mm512_set1_pd(-0.0)), _mm512_set1_pd(-0.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f702(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_andnot_pd(_mm512_andnot_pd(x, _mm512_set1_pd(-0.0)), _mm512_set1_pd(1.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f703(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_andnot_pd(_mm512_andnot_pd(x, _mm512_set1_pd(-0.0)), _mm512_set1_pd(-1.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f704(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_andnot_pd(_mm512_andnot_pd(x, _mm512_set1_pd(-0.0)), _mm512_set1_pd(std::numeric_limits<double>::infinity())); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f705(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_andnot_pd(_mm512_andnot_pd(x, _mm512_set1_pd(-0.0)), _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN())); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f706(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_andnot_pd(_mm512_andnot_pd(x, _mm512_set1_pd(1.0)), _mm512_setzero_pd()); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f707(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_andnot_pd(_mm512_andnot_pd(x, _mm512_set1_pd(1.0)), _mm512_set1_pd(-0.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f708(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_andnot_pd(_mm512_andnot_pd(x, _mm512_set1_pd(1.0)), _mm512_set1_pd(1.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f709(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_andnot_pd(_mm512_andnot_pd(x, _mm512_set1_pd(1.0)), _mm512_set1_pd(-1.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f710(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_andnot_pd(_mm512_andnot_pd(x, _mm512_set1_pd(1.0)), _mm512_set1_pd(std::numeric_limits<double>::infinity())); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f711(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_andnot_pd(_mm512_andnot_pd(x, _mm512_set1_pd(1.0)), _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN())); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f712(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_andnot_pd(_mm512_andnot_pd(x, _mm512_set1_pd(-1.0)), _mm512_setzero_pd()); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f713(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_andnot_pd(_mm512_andnot_pd(x, _mm512_set1_pd(-1.0)), _mm512_set1_pd(-0.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f714(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_andnot_pd(_mm512_andnot_pd(x, _mm512_set1_pd(-1.0)), _mm512_set1_pd(1.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f715(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_andnot_pd(_mm512_andnot_pd(x, _mm512_set1_pd(-1.0)), _mm512_set1_pd(-1.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f716(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_andnot_pd(_mm512_andnot_pd(x, _mm512_set1_pd(-1.0)), _mm512_set1_pd(std::numeric_limits<double>::infinity())); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f717(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_andnot_pd(_mm512_andnot_pd(x, _mm512_set1_pd(-1.0)), _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN())); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f718(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_andnot_pd(_mm512_andnot_pd(x, _mm512_set1_pd(std::numeric_limits<double>::infinity())), _mm512_setzero_pd()); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f719(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_andnot_pd(_mm512_andnot_pd(x, _mm512_set1_pd(std::numeric_limits<double>::infinity())), _mm512_set1_pd(-0.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f720(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_andnot_pd(_mm512_andnot_pd(x, _mm512_set1_pd(std::numeric_limits<double>::infinity())), _mm512_set1_pd(1.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f721(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_andnot_pd(_mm512_andnot_pd(x, _mm512_set1_pd(std::numeric_limits<double>::infinity())), _mm512_set1_pd(-1.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f722(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_andnot_pd(_mm512_andnot_pd(x, _mm512_set1_pd(std::numeric_limits<double>::infinity())), _mm512_set1_pd(std::numeric_limits<double>::infinity())); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f723(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_andnot_pd(_mm512_andnot_pd(x, _mm512_set1_pd(std::numeric_limits<double>::infinity())), _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN())); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f724(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_andnot_pd(_mm512_andnot_pd(x, _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN())), _mm512_setzero_pd()); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f725(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_andnot_pd(_mm512_andnot_pd(x, _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN())), _mm512_set1_pd(-0.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f726(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_andnot_pd(_mm512_andnot_pd(x, _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN())), _mm512_set1_pd(1.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f727(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_andnot_pd(_mm512_andnot_pd(x, _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN())), _mm512_set1_pd(-1.0)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f728(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_andnot_pd(_mm512_andnot_pd(x, _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN())), _mm512_set1_pd(std::numeric_limits<double>::infinity())); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f729(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_andnot_pd(_mm512_andnot_pd(x, _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN())), _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN())); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f730(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_add_pd(_mm512_add_pd(x, y), y); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f731(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_add_pd(x, _mm512_add_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f732(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_add_pd(_mm512_add_pd(x, y), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f733(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_add_pd(y, _mm512_add_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f734(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_add_pd(_mm512_sub_pd(x, y), y); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f735(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_add_pd(x, _mm512_sub_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f736(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_add_pd(_mm512_sub_pd(x, y), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f737(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_add_pd(y, _mm512_sub_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f738(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_add_pd(_mm512_mul_pd(x, y), y); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f739(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_add_pd(x, _mm512_mul_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f740(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_add_pd(_mm512_mul_pd(x, y), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f741(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_add_pd(y, _mm512_mul_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f742(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_add_pd(_mm512_div_pd(x, y), y); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f743(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_add_pd(x, _mm512_div_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f744(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_add_pd(_mm512_div_pd(x, y), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f745(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_add_pd(y, _mm512_div_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f746(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_add_pd(_mm512_min_pd(x, y), y); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f747(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_add_pd(x, _mm512_min_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f748(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_add_pd(_mm512_min_pd(x, y), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f749(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_add_pd(y, _mm512_min_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f750(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_add_pd(_mm512_max_pd(x, y), y); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f751(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_add_pd(x, _mm512_max_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f752(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_add_pd(_mm512_max_pd(x, y), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f753(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_add_pd(y, _mm512_max_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f754(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_add_pd(_mm512_and_pd(x, y), y); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f755(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_add_pd(x, _mm512_and_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f756(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_add_pd(_mm512_and_pd(x, y), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f757(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_add_pd(y, _mm512_and_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f758(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_add_pd(_mm512_or_pd(x, y), y); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f759(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_add_pd(x, _mm512_or_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f760(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_add_pd(_mm512_or_pd(x, y), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f761(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_add_pd(y, _mm512_or_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f762(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_add_pd(_mm512_xor_pd(x, y), y); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f763(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_add_pd(x, _mm512_xor_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f764(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_add_pd(_mm512_xor_pd(x, y), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f765(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_add_pd(y, _mm512_xor_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f766(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_add_pd(_mm512_andnot_pd(x, y), y); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f767(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_add_pd(x, _mm512_andnot_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f768(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_add_pd(_mm512_andnot_pd(x, y), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f769(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_add_pd(y, _mm512_andnot_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f770(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_sub_pd(_mm512_add_pd(x, y), y); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f771(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_sub_pd(x, _mm512_add_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f772(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_sub_pd(_mm512_add_pd(x, y), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f773(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_sub_pd(y, _mm512_add_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f774(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_sub_pd(_mm512_sub_pd(x, y), y); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f775(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_sub_pd(x, _mm512_sub_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f776(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_sub_pd(_mm512_sub_pd(x, y), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f777(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_sub_pd(y, _mm512_sub_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f778(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_sub_pd(_mm512_mul_pd(x, y), y); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f779(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_sub_pd(x, _mm512_mul_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f780(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_sub_pd(_mm512_mul_pd(x, y), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f781(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_sub_pd(y, _mm512_mul_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f782(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_sub_pd(_mm512_div_pd(x, y), y); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f783(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_sub_pd(x, _mm512_div_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f784(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_sub_pd(_mm512_div_pd(x, y), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f785(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_sub_pd(y, _mm512_div_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f786(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_sub_pd(_mm512_min_pd(x, y), y); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f787(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_sub_pd(x, _mm512_min_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f788(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_sub_pd(_mm512_min_pd(x, y), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f789(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_sub_pd(y, _mm512_min_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f790(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_sub_pd(_mm512_max_pd(x, y), y); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f791(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_sub_pd(x, _mm512_max_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f792(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_sub_pd(_mm512_max_pd(x, y), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f793(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_sub_pd(y, _mm512_max_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f794(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_sub_pd(_mm512_and_pd(x, y), y); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f795(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_sub_pd(x, _mm512_and_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f796(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_sub_pd(_mm512_and_pd(x, y), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f797(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_sub_pd(y, _mm512_and_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f798(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_sub_pd(_mm512_or_pd(x, y), y); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f799(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_sub_pd(x, _mm512_or_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f800(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_sub_pd(_mm512_or_pd(x, y), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f801(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_sub_pd(y, _mm512_or_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f802(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_sub_pd(_mm512_xor_pd(x, y), y); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f803(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_sub_pd(x, _mm512_xor_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f804(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_sub_pd(_mm512_xor_pd(x, y), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f805(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_sub_pd(y, _mm512_xor_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f806(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_sub_pd(_mm512_andnot_pd(x, y), y); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f807(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_sub_pd(x, _mm512_andnot_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f808(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_sub_pd(_mm512_andnot_pd(x, y), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f809(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_sub_pd(y, _mm512_andnot_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f810(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_mul_pd(_mm512_add_pd(x, y), y); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f811(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_mul_pd(x, _mm512_add_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f812(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_mul_pd(_mm512_add_pd(x, y), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f813(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_mul_pd(y, _mm512_add_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f814(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_mul_pd(_mm512_sub_pd(x, y), y); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f815(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_mul_pd(x, _mm512_sub_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f816(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_mul_pd(_mm512_sub_pd(x, y), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f817(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_mul_pd(y, _mm512_sub_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f818(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_mul_pd(_mm512_mul_pd(x, y), y); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f819(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_mul_pd(x, _mm512_mul_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f820(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_mul_pd(_mm512_mul_pd(x, y), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f821(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_mul_pd(y, _mm512_mul_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f822(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_mul_pd(_mm512_div_pd(x, y), y); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f823(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_mul_pd(x, _mm512_div_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f824(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_mul_pd(_mm512_div_pd(x, y), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f825(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_mul_pd(y, _mm512_div_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f826(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_mul_pd(_mm512_min_pd(x, y), y); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f827(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_mul_pd(x, _mm512_min_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f828(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_mul_pd(_mm512_min_pd(x, y), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f829(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_mul_pd(y, _mm512_min_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f830(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_mul_pd(_mm512_max_pd(x, y), y); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f831(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_mul_pd(x, _mm512_max_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f832(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_mul_pd(_mm512_max_pd(x, y), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f833(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_mul_pd(y, _mm512_max_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f834(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_mul_pd(_mm512_and_pd(x, y), y); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f835(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_mul_pd(x, _mm512_and_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f836(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_mul_pd(_mm512_and_pd(x, y), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f837(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_mul_pd(y, _mm512_and_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f838(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_mul_pd(_mm512_or_pd(x, y), y); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f839(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_mul_pd(x, _mm512_or_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f840(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_mul_pd(_mm512_or_pd(x, y), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f841(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_mul_pd(y, _mm512_or_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f842(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_mul_pd(_mm512_xor_pd(x, y), y); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f843(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_mul_pd(x, _mm512_xor_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f844(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_mul_pd(_mm512_xor_pd(x, y), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f845(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_mul_pd(y, _mm512_xor_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f846(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_mul_pd(_mm512_andnot_pd(x, y), y); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f847(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_mul_pd(x, _mm512_andnot_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f848(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_mul_pd(_mm512_andnot_pd(x, y), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f849(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_mul_pd(y, _mm512_andnot_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f850(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_div_pd(_mm512_add_pd(x, y), y); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f851(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_div_pd(x, _mm512_add_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f852(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_div_pd(_mm512_add_pd(x, y), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f853(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_div_pd(y, _mm512_add_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f854(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_div_pd(_mm512_sub_pd(x, y), y); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f855(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_div_pd(x, _mm512_sub_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f856(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_div_pd(_mm512_sub_pd(x, y), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f857(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_div_pd(y, _mm512_sub_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f858(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_div_pd(_mm512_mul_pd(x, y), y); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f859(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_div_pd(x, _mm512_mul_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f860(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_div_pd(_mm512_mul_pd(x, y), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f861(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_div_pd(y, _mm512_mul_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f862(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_div_pd(_mm512_div_pd(x, y), y); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f863(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_div_pd(x, _mm512_div_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f864(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_div_pd(_mm512_div_pd(x, y), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f865(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_div_pd(y, _mm512_div_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f866(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_div_pd(_mm512_min_pd(x, y), y); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f867(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_div_pd(x, _mm512_min_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f868(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_div_pd(_mm512_min_pd(x, y), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f869(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_div_pd(y, _mm512_min_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f870(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_div_pd(_mm512_max_pd(x, y), y); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f871(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_div_pd(x, _mm512_max_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f872(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_div_pd(_mm512_max_pd(x, y), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f873(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_div_pd(y, _mm512_max_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f874(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_div_pd(_mm512_and_pd(x, y), y); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f875(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_div_pd(x, _mm512_and_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f876(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_div_pd(_mm512_and_pd(x, y), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f877(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_div_pd(y, _mm512_and_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f878(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_div_pd(_mm512_or_pd(x, y), y); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f879(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_div_pd(x, _mm512_or_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f880(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_div_pd(_mm512_or_pd(x, y), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f881(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_div_pd(y, _mm512_or_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f882(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_div_pd(_mm512_xor_pd(x, y), y); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f883(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_div_pd(x, _mm512_xor_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f884(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_div_pd(_mm512_xor_pd(x, y), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f885(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_div_pd(y, _mm512_xor_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f886(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_div_pd(_mm512_andnot_pd(x, y), y); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f887(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_div_pd(x, _mm512_andnot_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f888(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_div_pd(_mm512_andnot_pd(x, y), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f889(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_div_pd(y, _mm512_andnot_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f890(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_min_pd(_mm512_add_pd(x, y), y); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f891(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_min_pd(x, _mm512_add_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f892(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_min_pd(_mm512_add_pd(x, y), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f893(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_min_pd(y, _mm512_add_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f894(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_min_pd(_mm512_sub_pd(x, y), y); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f895(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_min_pd(x, _mm512_sub_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f896(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_min_pd(_mm512_sub_pd(x, y), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f897(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_min_pd(y, _mm512_sub_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f898(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_min_pd(_mm512_mul_pd(x, y), y); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f899(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_min_pd(x, _mm512_mul_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f900(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_min_pd(_mm512_mul_pd(x, y), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f901(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_min_pd(y, _mm512_mul_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f902(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_min_pd(_mm512_div_pd(x, y), y); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f903(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_min_pd(x, _mm512_div_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f904(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_min_pd(_mm512_div_pd(x, y), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f905(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_min_pd(y, _mm512_div_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f906(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_min_pd(_mm512_min_pd(x, y), y); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f907(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_min_pd(x, _mm512_min_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f908(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_min_pd(_mm512_min_pd(x, y), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f909(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_min_pd(y, _mm512_min_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f910(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_min_pd(_mm512_max_pd(x, y), y); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f911(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_min_pd(x, _mm512_max_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f912(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_min_pd(_mm512_max_pd(x, y), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f913(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_min_pd(y, _mm512_max_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f914(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_min_pd(_mm512_and_pd(x, y), y); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f915(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_min_pd(x, _mm512_and_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f916(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_min_pd(_mm512_and_pd(x, y), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f917(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_min_pd(y, _mm512_and_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f918(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_min_pd(_mm512_or_pd(x, y), y); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f919(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_min_pd(x, _mm512_or_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f920(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_min_pd(_mm512_or_pd(x, y), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f921(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_min_pd(y, _mm512_or_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f922(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_min_pd(_mm512_xor_pd(x, y), y); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f923(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_min_pd(x, _mm512_xor_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f924(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_min_pd(_mm512_xor_pd(x, y), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f925(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_min_pd(y, _mm512_xor_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f926(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_min_pd(_mm512_andnot_pd(x, y), y); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f927(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_min_pd(x, _mm512_andnot_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f928(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_min_pd(_mm512_andnot_pd(x, y), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f929(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_min_pd(y, _mm512_andnot_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f930(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_max_pd(_mm512_add_pd(x, y), y); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f931(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_max_pd(x, _mm512_add_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f932(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_max_pd(_mm512_add_pd(x, y), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f933(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_max_pd(y, _mm512_add_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f934(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_max_pd(_mm512_sub_pd(x, y), y); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f935(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_max_pd(x, _mm512_sub_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f936(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_max_pd(_mm512_sub_pd(x, y), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f937(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_max_pd(y, _mm512_sub_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f938(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_max_pd(_mm512_mul_pd(x, y), y); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f939(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_max_pd(x, _mm512_mul_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f940(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_max_pd(_mm512_mul_pd(x, y), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f941(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_max_pd(y, _mm512_mul_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f942(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_max_pd(_mm512_div_pd(x, y), y); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f943(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_max_pd(x, _mm512_div_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f944(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_max_pd(_mm512_div_pd(x, y), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f945(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_max_pd(y, _mm512_div_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f946(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_max_pd(_mm512_min_pd(x, y), y); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f947(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_max_pd(x, _mm512_min_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f948(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_max_pd(_mm512_min_pd(x, y), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f949(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_max_pd(y, _mm512_min_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f950(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_max_pd(_mm512_max_pd(x, y), y); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f951(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_max_pd(x, _mm512_max_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f952(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_max_pd(_mm512_max_pd(x, y), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f953(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_max_pd(y, _mm512_max_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f954(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_max_pd(_mm512_and_pd(x, y), y); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f955(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_max_pd(x, _mm512_and_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f956(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_max_pd(_mm512_and_pd(x, y), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f957(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_max_pd(y, _mm512_and_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f958(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_max_pd(_mm512_or_pd(x, y), y); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f959(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_max_pd(x, _mm512_or_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f960(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_max_pd(_mm512_or_pd(x, y), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f961(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_max_pd(y, _mm512_or_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f962(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_max_pd(_mm512_xor_pd(x, y), y); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f963(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_max_pd(x, _mm512_xor_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f964(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_max_pd(_mm512_xor_pd(x, y), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f965(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_max_pd(y, _mm512_xor_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f966(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_max_pd(_mm512_andnot_pd(x, y), y); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f967(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_max_pd(x, _mm512_andnot_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f968(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_max_pd(_mm512_andnot_pd(x, y), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f969(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_max_pd(y, _mm512_andnot_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f970(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_and_pd(_mm512_add_pd(x, y), y); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f971(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_and_pd(x, _mm512_add_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f972(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_and_pd(_mm512_add_pd(x, y), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f973(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_and_pd(y, _mm512_add_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f974(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_and_pd(_mm512_sub_pd(x, y), y); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f975(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_and_pd(x, _mm512_sub_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f976(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_and_pd(_mm512_sub_pd(x, y), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f977(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_and_pd(y, _mm512_sub_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f978(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_and_pd(_mm512_mul_pd(x, y), y); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f979(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_and_pd(x, _mm512_mul_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f980(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_and_pd(_mm512_mul_pd(x, y), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f981(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_and_pd(y, _mm512_mul_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f982(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_and_pd(_mm512_div_pd(x, y), y); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f983(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_and_pd(x, _mm512_div_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f984(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_and_pd(_mm512_div_pd(x, y), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f985(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_and_pd(y, _mm512_div_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f986(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_and_pd(_mm512_min_pd(x, y), y); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f987(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_and_pd(x, _mm512_min_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f988(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_and_pd(_mm512_min_pd(x, y), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f989(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_and_pd(y, _mm512_min_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f990(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_and_pd(_mm512_max_pd(x, y), y); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f991(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_and_pd(x, _mm512_max_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f992(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_and_pd(_mm512_max_pd(x, y), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f993(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_and_pd(y, _mm512_max_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f994(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_and_pd(_mm512_and_pd(x, y), y); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f995(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_and_pd(x, _mm512_and_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f996(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_and_pd(_mm512_and_pd(x, y), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f997(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_and_pd(y, _mm512_and_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f998(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_and_pd(_mm512_or_pd(x, y), y); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f999(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_and_pd(x, _mm512_or_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1000(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_and_pd(_mm512_or_pd(x, y), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1001(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_and_pd(y, _mm512_or_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1002(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_and_pd(_mm512_xor_pd(x, y), y); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1003(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_and_pd(x, _mm512_xor_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1004(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_and_pd(_mm512_xor_pd(x, y), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1005(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_and_pd(y, _mm512_xor_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1006(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_and_pd(_mm512_andnot_pd(x, y), y); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1007(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_and_pd(x, _mm512_andnot_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1008(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_and_pd(_mm512_andnot_pd(x, y), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1009(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_and_pd(y, _mm512_andnot_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1010(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_or_pd(_mm512_add_pd(x, y), y); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1011(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_or_pd(x, _mm512_add_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1012(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_or_pd(_mm512_add_pd(x, y), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1013(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_or_pd(y, _mm512_add_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1014(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_or_pd(_mm512_sub_pd(x, y), y); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1015(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_or_pd(x, _mm512_sub_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1016(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_or_pd(_mm512_sub_pd(x, y), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1017(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_or_pd(y, _mm512_sub_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1018(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_or_pd(_mm512_mul_pd(x, y), y); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1019(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_or_pd(x, _mm512_mul_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1020(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_or_pd(_mm512_mul_pd(x, y), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1021(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_or_pd(y, _mm512_mul_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1022(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_or_pd(_mm512_div_pd(x, y), y); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1023(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_or_pd(x, _mm512_div_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1024(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_or_pd(_mm512_div_pd(x, y), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1025(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_or_pd(y, _mm512_div_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1026(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_or_pd(_mm512_min_pd(x, y), y); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1027(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_or_pd(x, _mm512_min_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1028(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_or_pd(_mm512_min_pd(x, y), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1029(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_or_pd(y, _mm512_min_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1030(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_or_pd(_mm512_max_pd(x, y), y); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1031(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_or_pd(x, _mm512_max_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1032(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_or_pd(_mm512_max_pd(x, y), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1033(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_or_pd(y, _mm512_max_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1034(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_or_pd(_mm512_and_pd(x, y), y); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1035(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_or_pd(x, _mm512_and_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1036(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_or_pd(_mm512_and_pd(x, y), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1037(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_or_pd(y, _mm512_and_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1038(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_or_pd(_mm512_or_pd(x, y), y); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1039(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_or_pd(x, _mm512_or_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1040(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_or_pd(_mm512_or_pd(x, y), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1041(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_or_pd(y, _mm512_or_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1042(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_or_pd(_mm512_xor_pd(x, y), y); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1043(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_or_pd(x, _mm512_xor_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1044(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_or_pd(_mm512_xor_pd(x, y), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1045(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_or_pd(y, _mm512_xor_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1046(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_or_pd(_mm512_andnot_pd(x, y), y); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1047(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_or_pd(x, _mm512_andnot_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1048(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_or_pd(_mm512_andnot_pd(x, y), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1049(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_or_pd(y, _mm512_andnot_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1050(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_xor_pd(_mm512_add_pd(x, y), y); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1051(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_xor_pd(x, _mm512_add_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1052(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_xor_pd(_mm512_add_pd(x, y), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1053(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_xor_pd(y, _mm512_add_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1054(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_xor_pd(_mm512_sub_pd(x, y), y); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1055(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_xor_pd(x, _mm512_sub_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1056(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_xor_pd(_mm512_sub_pd(x, y), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1057(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_xor_pd(y, _mm512_sub_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1058(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_xor_pd(_mm512_mul_pd(x, y), y); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1059(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_xor_pd(x, _mm512_mul_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1060(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_xor_pd(_mm512_mul_pd(x, y), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1061(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_xor_pd(y, _mm512_mul_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1062(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_xor_pd(_mm512_div_pd(x, y), y); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1063(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_xor_pd(x, _mm512_div_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1064(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_xor_pd(_mm512_div_pd(x, y), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1065(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_xor_pd(y, _mm512_div_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1066(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_xor_pd(_mm512_min_pd(x, y), y); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1067(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_xor_pd(x, _mm512_min_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1068(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_xor_pd(_mm512_min_pd(x, y), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1069(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_xor_pd(y, _mm512_min_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1070(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_xor_pd(_mm512_max_pd(x, y), y); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1071(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_xor_pd(x, _mm512_max_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1072(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_xor_pd(_mm512_max_pd(x, y), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1073(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_xor_pd(y, _mm512_max_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1074(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_xor_pd(_mm512_and_pd(x, y), y); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1075(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_xor_pd(x, _mm512_and_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1076(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_xor_pd(_mm512_and_pd(x, y), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1077(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_xor_pd(y, _mm512_and_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1078(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_xor_pd(_mm512_or_pd(x, y), y); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1079(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_xor_pd(x, _mm512_or_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1080(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_xor_pd(_mm512_or_pd(x, y), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1081(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_xor_pd(y, _mm512_or_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1082(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_xor_pd(_mm512_xor_pd(x, y), y); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1083(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_xor_pd(x, _mm512_xor_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1084(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_xor_pd(_mm512_xor_pd(x, y), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1085(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_xor_pd(y, _mm512_xor_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1086(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_xor_pd(_mm512_andnot_pd(x, y), y); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1087(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_xor_pd(x, _mm512_andnot_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1088(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_xor_pd(_mm512_andnot_pd(x, y), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1089(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_xor_pd(y, _mm512_andnot_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1090(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_andnot_pd(_mm512_add_pd(x, y), y); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1091(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_andnot_pd(x, _mm512_add_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1092(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_andnot_pd(_mm512_add_pd(x, y), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1093(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_andnot_pd(y, _mm512_add_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1094(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_andnot_pd(_mm512_sub_pd(x, y), y); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1095(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_andnot_pd(x, _mm512_sub_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1096(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_andnot_pd(_mm512_sub_pd(x, y), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1097(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_andnot_pd(y, _mm512_sub_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1098(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_andnot_pd(_mm512_mul_pd(x, y), y); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1099(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_andnot_pd(x, _mm512_mul_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1100(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_andnot_pd(_mm512_mul_pd(x, y), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1101(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_andnot_pd(y, _mm512_mul_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1102(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_andnot_pd(_mm512_div_pd(x, y), y); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1103(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_andnot_pd(x, _mm512_div_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1104(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_andnot_pd(_mm512_div_pd(x, y), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1105(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_andnot_pd(y, _mm512_div_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1106(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_andnot_pd(_mm512_min_pd(x, y), y); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1107(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_andnot_pd(x, _mm512_min_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1108(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_andnot_pd(_mm512_min_pd(x, y), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1109(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_andnot_pd(y, _mm512_min_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1110(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_andnot_pd(_mm512_max_pd(x, y), y); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1111(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_andnot_pd(x, _mm512_max_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1112(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_andnot_pd(_mm512_max_pd(x, y), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1113(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_andnot_pd(y, _mm512_max_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1114(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_andnot_pd(_mm512_and_pd(x, y), y); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1115(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_andnot_pd(x, _mm512_and_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1116(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_andnot_pd(_mm512_and_pd(x, y), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1117(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_andnot_pd(y, _mm512_and_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1118(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_andnot_pd(_mm512_or_pd(x, y), y); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1119(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_andnot_pd(x, _mm512_or_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1120(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_andnot_pd(_mm512_or_pd(x, y), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1121(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_andnot_pd(y, _mm512_or_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1122(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_andnot_pd(_mm512_xor_pd(x, y), y); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1123(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_andnot_pd(x, _mm512_xor_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1124(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_andnot_pd(_mm512_xor_pd(x, y), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1125(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_andnot_pd(y, _mm512_xor_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1126(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_andnot_pd(_mm512_andnot_pd(x, y), y); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1127(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_andnot_pd(x, _mm512_andnot_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1128(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_andnot_pd(_mm512_andnot_pd(x, y), x); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1129(const void* px, const void* py, void* po) { const __m512d x = _mm512_loadu_pd((const double*)px); const __m512d y = _mm512_loadu_pd((const double*)py); (void)y; const __m512d r = _mm512_andnot_pd(y, _mm512_andnot_pd(x, y)); _mm512_storeu_pd((double*)po, r); }
static NOINLINE void f1130(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_fmadd_ps(x, y, _mm512_setzero_ps()); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f1131(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_fmadd_ps(x, _mm512_setzero_ps(), y); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f1132(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_fmadd_ps(_mm512_setzero_ps(), x, y); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f1133(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_fmadd_ps(x, y, _mm512_set1_ps(-0.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f1134(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_fmadd_ps(x, _mm512_set1_ps(-0.0f), y); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f1135(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_fmadd_ps(_mm512_set1_ps(-0.0f), x, y); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f1136(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_fmadd_ps(x, y, _mm512_set1_ps(1.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f1137(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_fmadd_ps(x, _mm512_set1_ps(1.0f), y); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f1138(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_fmadd_ps(_mm512_set1_ps(1.0f), x, y); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f1139(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_fmadd_ps(x, y, _mm512_set1_ps(-1.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f1140(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_fmadd_ps(x, _mm512_set1_ps(-1.0f), y); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f1141(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_fmadd_ps(_mm512_set1_ps(-1.0f), x, y); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f1142(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_fmadd_ps(x, y, _mm512_set1_ps(std::numeric_limits<float>::infinity())); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f1143(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_fmadd_ps(x, _mm512_set1_ps(std::numeric_limits<float>::infinity()), y); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f1144(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_fmadd_ps(_mm512_set1_ps(std::numeric_limits<float>::infinity()), x, y); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f1145(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_fmadd_ps(x, y, _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN())); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f1146(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_fmadd_ps(x, _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN()), y); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f1147(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_fmadd_ps(_mm512_set1_ps(std::numeric_limits<float>::quiet_NaN()), x, y); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f1148(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_fmadd_ps(x, y, x); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f1149(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_fmadd_ps(x, x, y); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f1150(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_fmadd_ps(x, y, _mm512_mul_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f1151(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_fmsub_ps(x, y, _mm512_setzero_ps()); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f1152(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_fmsub_ps(x, _mm512_setzero_ps(), y); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f1153(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_fmsub_ps(_mm512_setzero_ps(), x, y); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f1154(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_fmsub_ps(x, y, _mm512_set1_ps(-0.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f1155(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_fmsub_ps(x, _mm512_set1_ps(-0.0f), y); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f1156(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_fmsub_ps(_mm512_set1_ps(-0.0f), x, y); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f1157(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_fmsub_ps(x, y, _mm512_set1_ps(1.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f1158(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_fmsub_ps(x, _mm512_set1_ps(1.0f), y); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f1159(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_fmsub_ps(_mm512_set1_ps(1.0f), x, y); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f1160(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_fmsub_ps(x, y, _mm512_set1_ps(-1.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f1161(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_fmsub_ps(x, _mm512_set1_ps(-1.0f), y); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f1162(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_fmsub_ps(_mm512_set1_ps(-1.0f), x, y); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f1163(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_fmsub_ps(x, y, _mm512_set1_ps(std::numeric_limits<float>::infinity())); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f1164(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_fmsub_ps(x, _mm512_set1_ps(std::numeric_limits<float>::infinity()), y); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f1165(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_fmsub_ps(_mm512_set1_ps(std::numeric_limits<float>::infinity()), x, y); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f1166(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_fmsub_ps(x, y, _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN())); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f1167(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_fmsub_ps(x, _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN()), y); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f1168(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_fmsub_ps(_mm512_set1_ps(std::numeric_limits<float>::quiet_NaN()), x, y); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f1169(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_fmsub_ps(x, y, x); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f1170(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_fmsub_ps(x, x, y); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f1171(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_fmsub_ps(x, y, _mm512_mul_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f1172(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_fnmadd_ps(x, y, _mm512_setzero_ps()); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f1173(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_fnmadd_ps(x, _mm512_setzero_ps(), y); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f1174(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_fnmadd_ps(_mm512_setzero_ps(), x, y); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f1175(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_fnmadd_ps(x, y, _mm512_set1_ps(-0.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f1176(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_fnmadd_ps(x, _mm512_set1_ps(-0.0f), y); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f1177(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_fnmadd_ps(_mm512_set1_ps(-0.0f), x, y); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f1178(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_fnmadd_ps(x, y, _mm512_set1_ps(1.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f1179(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_fnmadd_ps(x, _mm512_set1_ps(1.0f), y); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f1180(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_fnmadd_ps(_mm512_set1_ps(1.0f), x, y); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f1181(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_fnmadd_ps(x, y, _mm512_set1_ps(-1.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f1182(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_fnmadd_ps(x, _mm512_set1_ps(-1.0f), y); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f1183(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_fnmadd_ps(_mm512_set1_ps(-1.0f), x, y); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f1184(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_fnmadd_ps(x, y, _mm512_set1_ps(std::numeric_limits<float>::infinity())); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f1185(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_fnmadd_ps(x, _mm512_set1_ps(std::numeric_limits<float>::infinity()), y); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f1186(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_fnmadd_ps(_mm512_set1_ps(std::numeric_limits<float>::infinity()), x, y); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f1187(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_fnmadd_ps(x, y, _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN())); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f1188(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_fnmadd_ps(x, _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN()), y); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f1189(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_fnmadd_ps(_mm512_set1_ps(std::numeric_limits<float>::quiet_NaN()), x, y); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f1190(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_fnmadd_ps(x, y, x); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f1191(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_fnmadd_ps(x, x, y); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f1192(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_fnmadd_ps(x, y, _mm512_mul_ps(x, y)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f1193(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_fnmsub_ps(x, y, _mm512_setzero_ps()); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f1194(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_fnmsub_ps(x, _mm512_setzero_ps(), y); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f1195(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_fnmsub_ps(_mm512_setzero_ps(), x, y); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f1196(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_fnmsub_ps(x, y, _mm512_set1_ps(-0.0f)); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f1197(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_fnmsub_ps(x, _mm512_set1_ps(-0.0f), y); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f1198(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_fnmsub_ps(_mm512_set1_ps(-0.0f), x, y); _mm512_storeu_ps((float*)po, r); }
static NOINLINE void f1199(const void* px, const void* py, void* po) { const __m512 x = _mm512_loadu_ps((const float*)px); const __m512 y = _mm512_loadu_ps((const float*)py); (void)y; const __m512 r = _mm512_fnmsub_ps(x, y, _mm512_set1_ps(1.0f)); _mm512_storeu_ps((float*)po, r); }
extern const Entry table_95[] = {
  {"512:_mm512_andnot_pd(x, _mm512_sub_pd(_mm512_setzero_pd(), x))", f0, 2, 512},
  {"512:_mm512_andnot_pd(_mm512_sub_pd(_mm512_setzero_pd(), x), x)", f1, 2, 512},
  {"512:_mm512_mul_pd(_mm512_add_pd(x, y), _mm512_set1_pd(-1.0))", f2, 2, 512},
  {"512:_mm512_add_pd(_mm512_mul_pd(x, _mm512_set1_pd(-1.0)), y)", f3, 2, 512},
  {"512:_mm512_add_pd(x, _mm512_mul_pd(y, _mm512_set1_pd(-1.0)))", f4, 2, 512},
  {"512:_mm512_add_pd(_mm512_mul_pd(x, _mm512_set1_pd(-1.0)), _mm512_mul_pd(y, _mm512_set1_pd(-1.0)))", f5, 2, 512},
  {"512:_mm512_add_pd(x, _mm512_mul_pd(x, _mm512_set1_pd(-1.0)))", f6, 2, 512},
  {"512:_mm512_add_pd(_mm512_mul_pd(x, _mm512_set1_pd(-1.0)), x)", f7, 2, 512},
  {"512:_mm512_mul_pd(_mm512_sub_pd(x, y), _mm512_set1_pd(-1.0))", f8, 2, 512},
  {"512:_mm512_sub_pd(_mm512_mul_pd(x, _mm512_set1_pd(-1.0)), y)", f9, 2, 512},
  {"512:_mm512_sub_pd(x, _mm512_mul_pd(y, _mm512_set1_pd(-1.0)))", f10, 2, 512},
  {"512:_mm512_sub_pd(_mm512_mul_pd(x, _mm512_set1_pd(-1.0)), _mm512_mul_pd(y, _mm512_set1_pd(-1.0)))", f11, 2, 512},
  {"512:_mm512_sub_pd(x, _mm512_mul_pd(x, _mm512_set1_pd(-1.0)))", f12, 2, 512},
  {"512:_mm512_sub_pd(_mm512_mul_pd(x, _mm512_set1_pd(-1.0)), x)", f13, 2, 512},
  {"512:_mm512_mul_pd(_mm512_mul_pd(x, y), _mm512_set1_pd(-1.0))", f14, 2, 512},
  {"512:_mm512_mul_pd(_mm512_mul_pd(x, _mm512_set1_pd(-1.0)), y)", f15, 2, 512},
  {"512:_mm512_mul_pd(x, _mm512_mul_pd(y, _mm512_set1_pd(-1.0)))", f16, 2, 512},
  {"512:_mm512_mul_pd(_mm512_mul_pd(x, _mm512_set1_pd(-1.0)), _mm512_mul_pd(y, _mm512_set1_pd(-1.0)))", f17, 2, 512},
  {"512:_mm512_mul_pd(x, _mm512_mul_pd(x, _mm512_set1_pd(-1.0)))", f18, 2, 512},
  {"512:_mm512_mul_pd(_mm512_mul_pd(x, _mm512_set1_pd(-1.0)), x)", f19, 2, 512},
  {"512:_mm512_mul_pd(_mm512_div_pd(x, y), _mm512_set1_pd(-1.0))", f20, 2, 512},
  {"512:_mm512_div_pd(_mm512_mul_pd(x, _mm512_set1_pd(-1.0)), y)", f21, 2, 512},
  {"512:_mm512_div_pd(x, _mm512_mul_pd(y, _mm512_set1_pd(-1.0)))", f22, 2, 512},
  {"512:_mm512_div_pd(_mm512_mul_pd(x, _mm512_set1_pd(-1.0)), _mm512_mul_pd(y, _mm512_set1_pd(-1.0)))", f23, 2, 512},
  {"512:_mm512_div_pd(x, _mm512_mul_pd(x, _mm512_set1_pd(-1.0)))", f24, 2, 512},
  {"512:_mm512_div_pd(_mm512_mul_pd(x, _mm512_set1_pd(-1.0)), x)", f25, 2, 512},
  {"512:_mm512_mul_pd(_mm512_min_pd(x, y), _mm512_set1_pd(-1.0))", f26, 2, 512},
  {"512:_mm512_min_pd(_mm512_mul_pd(x, _mm512_set1_pd(-1.0)), y)", f27, 2, 512},
  {"512:_mm512_min_pd(x, _mm512_mul_pd(y, _mm512_set1_pd(-1.0)))", f28, 2, 512},
  {"512:_mm512_min_pd(_mm512_mul_pd(x, _mm512_set1_pd(-1.0)), _mm512_mul_pd(y, _mm512_set1_pd(-1.0)))", f29, 2, 512},
  {"512:_mm512_min_pd(x, _mm512_mul_pd(x, _mm512_set1_pd(-1.0)))", f30, 2, 512},
  {"512:_mm512_min_pd(_mm512_mul_pd(x, _mm512_set1_pd(-1.0)), x)", f31, 2, 512},
  {"512:_mm512_mul_pd(_mm512_max_pd(x, y), _mm512_set1_pd(-1.0))", f32, 2, 512},
  {"512:_mm512_max_pd(_mm512_mul_pd(x, _mm512_set1_pd(-1.0)), y)", f33, 2, 512},
  {"512:_mm512_max_pd(x, _mm512_mul_pd(y, _mm512_set1_pd(-1.0)))", f34, 2, 512},
  {"512:_mm512_max_pd(_mm512_mul_pd(x, _mm512_set1_pd(-1.0)), _mm512_mul_pd(y, _mm512_set1_pd(-1.0)))", f35, 2, 512},
  {"512:_mm512_max_pd(x, _mm512_mul_pd(x, _mm512_set1_pd(-1.0)))", f36, 2, 512},
  {"512:_mm512_max_pd(_mm512_mul_pd(x, _mm512_set1_pd(-1.0)), x)", f37, 2, 512},
  {"512:_mm512_mul_pd(_mm512_and_pd(x, y), _mm512_set1_pd(-1.0))", f38, 2, 512},
  {"512:_mm512_and_pd(_mm512_mul_pd(x, _mm512_set1_pd(-1.0)), y)", f39, 2, 512},
  {"512:_mm512_and_pd(x, _mm512_mul_pd(y, _mm512_set1_pd(-1.0)))", f40, 2, 512},
  {"512:_mm512_and_pd(_mm512_mul_pd(x, _mm512_set1_pd(-1.0)), _mm512_mul_pd(y, _mm512_set1_pd(-1.0)))", f41, 2, 512},
  {"512:_mm512_and_pd(x, _mm512_mul_pd(x, _mm512_set1_pd(-1.0)))", f42, 2, 512},
  {"512:_mm512_and_pd(_mm512_mul_pd(x, _mm512_set1_pd(-1.0)), x)", f43, 2, 512},
  {"512:_mm512_mul_pd(_mm512_or_pd(x, y), _mm512_set1_pd(-1.0))", f44, 2, 512},
  {"512:_mm512_or_pd(_mm512_mul_pd(x, _mm512_set1_pd(-1.0)), y)", f45, 2, 512},
  {"512:_mm512_or_pd(x, _mm512_mul_pd(y, _mm512_set1_pd(-1.0)))", f46, 2, 512},
  {"512:_mm512_or_pd(_mm512_mul_pd(x, _mm512_set1_pd(-1.0)), _mm512_mul_pd(y, _mm512_set1_pd(-1.0)))", f47, 2, 512},
  {"512:_mm512_or_pd(x, _mm512_mul_pd(x, _mm512_set1_pd(-1.0)))", f48, 2, 512},
  {"512:_mm512_or_pd(_mm512_mul_pd(x, _mm512_set1_pd(-1.0)), x)", f49, 2, 512},
  {"512:_mm512_mul_pd(_mm512_xor_pd(x, y), _mm512_set1_pd(-1.0))", f50, 2, 512},
  {"512:_mm512_xor_pd(_mm512_mul_pd(x, _mm512_set1_pd(-1.0)), y)", f51, 2, 512},
  {"512:_mm512_xor_pd(x, _mm512_mul_pd(y, _mm512_set1_pd(-1.0)))", f52, 2, 512},
  {"512:_mm512_xor_pd(_mm512_mul_pd(x, _mm512_set1_pd(-1.0)), _mm512_mul_pd(y, _mm512_set1_pd(-1.0)))", f53, 2, 512},
  {"512:_mm512_xor_pd(x, _mm512_mul_pd(x, _mm512_set1_pd(-1.0)))", f54, 2, 512},
  {"512:_mm512_xor_pd(_mm512_mul_pd(x, _mm512_set1_pd(-1.0)), x)", f55, 2, 512},
  {"512:_mm512_mul_pd(_mm512_andnot_pd(x, y), _mm512_set1_pd(-1.0))", f56, 2, 512},
  {"512:_mm512_andnot_pd(_mm512_mul_pd(x, _mm512_set1_pd(-1.0)), y)", f57, 2, 512},
  {"512:_mm512_andnot_pd(x, _mm512_mul_pd(y, _mm512_set1_pd(-1.0)))", f58, 2, 512},
  {"512:_mm512_andnot_pd(_mm512_mul_pd(x, _mm512_set1_pd(-1.0)), _mm512_mul_pd(y, _mm512_set1_pd(-1.0)))", f59, 2, 512},
  {"512:_mm512_andnot_pd(x, _mm512_mul_pd(x, _mm512_set1_pd(-1.0)))", f60, 2, 512},
  {"512:_mm512_andnot_pd(_mm512_mul_pd(x, _mm512_set1_pd(-1.0)), x)", f61, 2, 512},
  {"512:_mm512_roundscale_pd(_mm512_add_pd(x, y), 1 | _MM_FROUND_NO_EXC)", f62, 2, 512},
  {"512:_mm512_add_pd(_mm512_roundscale_pd(x, 1 | _MM_FROUND_NO_EXC), y)", f63, 2, 512},
  {"512:_mm512_add_pd(x, _mm512_roundscale_pd(y, 1 | _MM_FROUND_NO_EXC))", f64, 2, 512},
  {"512:_mm512_add_pd(_mm512_roundscale_pd(x, 1 | _MM_FROUND_NO_EXC), _mm512_roundscale_pd(y, 1 | _MM_FROUND_NO_EXC))", f65, 2, 512},
  {"512:_mm512_add_pd(x, _mm512_roundscale_pd(x, 1 | _MM_FROUND_NO_EXC))", f66, 2, 512},
  {"512:_mm512_add_pd(_mm512_roundscale_pd(x, 1 | _MM_FROUND_NO_EXC), x)", f67, 2, 512},
  {"512:_mm512_roundscale_pd(_mm512_sub_pd(x, y), 1 | _MM_FROUND_NO_EXC)", f68, 2, 512},
  {"512:_mm512_sub_pd(_mm512_roundscale_pd(x, 1 | _MM_FROUND_NO_EXC), y)", f69, 2, 512},
  {"512:_mm512_sub_pd(x, _mm512_roundscale_pd(y, 1 | _MM_FROUND_NO_EXC))", f70, 2, 512},
  {"512:_mm512_sub_pd(_mm512_roundscale_pd(x, 1 | _MM_FROUND_NO_EXC), _mm512_roundscale_pd(y, 1 | _MM_FROUND_NO_EXC))", f71, 2, 512},
  {"512:_mm512_sub_pd(x, _mm512_roundscale_pd(x, 1 | _MM_FROUND_NO_EXC))", f72, 2, 512},
  {"512:_mm512_sub_pd(_mm512_roundscale_pd(x, 1 | _MM_FROUND_NO_EXC), x)", f73, 2, 512},
  {"512:_mm512_roundscale_pd(_mm512_mul_pd(x, y), 1 | _MM_FROUND_NO_EXC)", f74, 2, 512},
  {"512:_mm512_mul_pd(_mm512_roundscale_pd(x, 1 | _MM_FROUND_NO_EXC), y)", f75, 2, 512},
  {"512:_mm512_mul_pd(x, _mm512_roundscale_pd(y, 1 | _MM_FROUND_NO_EXC))", f76, 2, 512},
  {"512:_mm512_mul_pd(_mm512_roundscale_pd(x, 1 | _MM_FROUND_NO_EXC), _mm512_roundscale_pd(y, 1 | _MM_FROUND_NO_EXC))", f77, 2, 512},
  {"512:_mm512_mul_pd(x, _mm512_roundscale_pd(x, 1 | _MM_FROUND_NO_EXC))", f78, 2, 512},
  {"512:_mm512_mul_pd(_mm512_roundscale_pd(x, 1 | _MM_FROUND_NO_EXC), x)", f79, 2, 512},
  {"512:_mm512_roundscale_pd(_mm512_div_pd(x, y), 1 | _MM_FROUND_NO_EXC)", f80, 2, 512},
  {"512:_mm512_div_pd(_mm512_roundscale_pd(x, 1 | _MM_FROUND_NO_EXC), y)", f81, 2, 512},
  {"512:_mm512_div_pd(x, _mm512_roundscale_pd(y, 1 | _MM_FROUND_NO_EXC))", f82, 2, 512},
  {"512:_mm512_div_pd(_mm512_roundscale_pd(x, 1 | _MM_FROUND_NO_EXC), _mm512_roundscale_pd(y, 1 | _MM_FROUND_NO_EXC))", f83, 2, 512},
  {"512:_mm512_div_pd(x, _mm512_roundscale_pd(x, 1 | _MM_FROUND_NO_EXC))", f84, 2, 512},
  {"512:_mm512_div_pd(_mm512_roundscale_pd(x, 1 | _MM_FROUND_NO_EXC), x)", f85, 2, 512},
  {"512:_mm512_roundscale_pd(_mm512_min_pd(x, y), 1 | _MM_FROUND_NO_EXC)", f86, 2, 512},
  {"512:_mm512_min_pd(_mm512_roundscale_pd(x, 1 | _MM_FROUND_NO_EXC), y)", f87, 2, 512},
  {"512:_mm512_min_pd(x, _mm512_roundscale_pd(y, 1 | _MM_FROUND_NO_EXC))", f88, 2, 512},
  {"512:_mm512_min_pd(_mm512_roundscale_pd(x, 1 | _MM_FROUND_NO_EXC), _mm512_roundscale_pd(y, 1 | _MM_FROUND_NO_EXC))", f89, 2, 512},
  {"512:_mm512_min_pd(x, _mm512_roundscale_pd(x, 1 | _MM_FROUND_NO_EXC))", f90, 2, 512},
  {"512:_mm512_min_pd(_mm512_roundscale_pd(x, 1 | _MM_FROUND_NO_EXC), x)", f91, 2, 512},
  {"512:_mm512_roundscale_pd(_mm512_max_pd(x, y), 1 | _MM_FROUND_NO_EXC)", f92, 2, 512},
  {"512:_mm512_max_pd(_mm512_roundscale_pd(x, 1 | _MM_FROUND_NO_EXC), y)", f93, 2, 512},
  {"512:_mm512_max_pd(x, _mm512_roundscale_pd(y, 1 | _MM_FROUND_NO_EXC))", f94, 2, 512},
  {"512:_mm512_max_pd(_mm512_roundscale_pd(x, 1 | _MM_FROUND_NO_EXC), _mm512_roundscale_pd(y, 1 | _MM_FROUND_NO_EXC))", f95, 2, 512},
  {"512:_mm512_max_pd(x, _mm512_roundscale_pd(x, 1 | _MM_FROUND_NO_EXC))", f96, 2, 512},
  {"512:_mm512_max_pd(_mm512_roundscale_pd(x, 1 | _MM_FROUND_NO_EXC), x)", f97, 2, 512},
  {"512:_mm512_roundscale_pd(_mm512_and_pd(x, y), 1 | _MM_FROUND_NO_EXC)", f98, 2, 512},
  {"512:_mm512_and_pd(_mm512_roundscale_pd(x, 1 | _MM_FROUND_NO_EXC), y)", f99, 2, 512},
  {"512:_mm512_and_pd(x, _mm512_roundscale_pd(y, 1 | _MM_FROUND_NO_EXC))", f100, 2, 512},
  {"512:_mm512_and_pd(_mm512_roundscale_pd(x, 1 | _MM_FROUND_NO_EXC), _mm512_roundscale_pd(y, 1 | _MM_FROUND_NO_EXC))", f101, 2, 512},
  {"512:_mm512_and_pd(x, _mm512_roundscale_pd(x, 1 | _MM_FROUND_NO_EXC))", f102, 2, 512},
  {"512:_mm512_and_pd(_mm512_roundscale_pd(x, 1 | _MM_FROUND_NO_EXC), x)", f103, 2, 512},
  {"512:_mm512_roundscale_pd(_mm512_or_pd(x, y), 1 | _MM_FROUND_NO_EXC)", f104, 2, 512},
  {"512:_mm512_or_pd(_mm512_roundscale_pd(x, 1 | _MM_FROUND_NO_EXC), y)", f105, 2, 512},
  {"512:_mm512_or_pd(x, _mm512_roundscale_pd(y, 1 | _MM_FROUND_NO_EXC))", f106, 2, 512},
  {"512:_mm512_or_pd(_mm512_roundscale_pd(x, 1 | _MM_FROUND_NO_EXC), _mm512_roundscale_pd(y, 1 | _MM_FROUND_NO_EXC))", f107, 2, 512},
  {"512:_mm512_or_pd(x, _mm512_roundscale_pd(x, 1 | _MM_FROUND_NO_EXC))", f108, 2, 512},
  {"512:_mm512_or_pd(_mm512_roundscale_pd(x, 1 | _MM_FROUND_NO_EXC), x)", f109, 2, 512},
  {"512:_mm512_roundscale_pd(_mm512_xor_pd(x, y), 1 | _MM_FROUND_NO_EXC)", f110, 2, 512},
  {"512:_mm512_xor_pd(_mm512_roundscale_pd(x, 1 | _MM_FROUND_NO_EXC), y)", f111, 2, 512},
  {"512:_mm512_xor_pd(x, _mm512_roundscale_pd(y, 1 | _MM_FROUND_NO_EXC))", f112, 2, 512},
  {"512:_mm512_xor_pd(_mm512_roundscale_pd(x, 1 | _MM_FROUND_NO_EXC), _mm512_roundscale_pd(y, 1 | _MM_FROUND_NO_EXC))", f113, 2, 512},
  {"512:_mm512_xor_pd(x, _mm512_roundscale_pd(x, 1 | _MM_FROUND_NO_EXC))", f114, 2, 512},
  {"512:_mm512_xor_pd(_mm512_roundscale_pd(x, 1 | _MM_FROUND_NO_EXC), x)", f115, 2, 512},
  {"512:_mm512_roundscale_pd(_mm512_andnot_pd(x, y), 1 | _MM_FROUND_NO_EXC)", f116, 2, 512},
  {"512:_mm512_andnot_pd(_mm512_roundscale_pd(x, 1 | _MM_FROUND_NO_EXC), y)", f117, 2, 512},
  {"512:_mm512_andnot_pd(x, _mm512_roundscale_pd(y, 1 | _MM_FROUND_NO_EXC))", f118, 2, 512},
  {"512:_mm512_andnot_pd(_mm512_roundscale_pd(x, 1 | _MM_FROUND_NO_EXC), _mm512_roundscale_pd(y, 1 | _MM_FROUND_NO_EXC))", f119, 2, 512},
  {"512:_mm512_andnot_pd(x, _mm512_roundscale_pd(x, 1 | _MM_FROUND_NO_EXC))", f120, 2, 512},
  {"512:_mm512_andnot_pd(_mm512_roundscale_pd(x, 1 | _MM_FROUND_NO_EXC), x)", f121, 2, 512},
  {"512:_mm512_roundscale_pd(_mm512_add_pd(x, y), 2 | _MM_FROUND_NO_EXC)", f122, 2, 512},
  {"512:_mm512_add_pd(_mm512_roundscale_pd(x, 2 | _MM_FROUND_NO_EXC), y)", f123, 2, 512},
  {"512:_mm512_add_pd(x, _mm512_roundscale_pd(y, 2 | _MM_FROUND_NO_EXC))", f124, 2, 512},
  {"512:_mm512_add_pd(_mm512_roundscale_pd(x, 2 | _MM_FROUND_NO_EXC), _mm512_roundscale_pd(y, 2 | _MM_FROUND_NO_EXC))", f125, 2, 512},
  {"512:_mm512_add_pd(x, _mm512_roundscale_pd(x, 2 | _MM_FROUND_NO_EXC))", f126, 2, 512},
  {"512:_mm512_add_pd(_mm512_roundscale_pd(x, 2 | _MM_FROUND_NO_EXC), x)", f127, 2, 512},
  {"512:_mm512_roundscale_pd(_mm512_sub_pd(x, y), 2 | _MM_FROUND_NO_EXC)", f128, 2, 512},
  {"512:_mm512_sub_pd(_mm512_roundscale_pd(x, 2 | _MM_FROUND_NO_EXC), y)", f129, 2, 512},
  {"512:_mm512_sub_pd(x, _mm512_roundscale_pd(y, 2 | _MM_FROUND_NO_EXC))", f130, 2, 512},
  {"512:_mm512_sub_pd(_mm512_roundscale_pd(x, 2 | _MM_FROUND_NO_EXC), _mm512_roundscale_pd(y, 2 | _MM_FROUND_NO_EXC))", f131, 2, 512},
  {"512:_mm512_sub_pd(x, _mm512_roundscale_pd(x, 2 | _MM_FROUND_NO_EXC))", f132, 2, 512},
  {"512:_mm512_sub_pd(_mm512_roundscale_pd(x, 2 | _MM_FROUND_NO_EXC), x)", f133, 2, 512},
  {"512:_mm512_roundscale_pd(_mm512_mul_pd(x, y), 2 | _MM_FROUND_NO_EXC)", f134, 2, 512},
  {"512:_mm512_mul_pd(_mm512_roundscale_pd(x, 2 | _MM_FROUND_NO_EXC), y)", f135, 2, 512},
  {"512:_mm512_mul_pd(x, _mm512_roundscale_pd(y, 2 | _MM_FROUND_NO_EXC))", f136, 2, 512},
  {"512:_mm512_mul_pd(_mm512_roundscale_pd(x, 2 | _MM_FROUND_NO_EXC), _mm512_roundscale_pd(y, 2 | _MM_FROUND_NO_EXC))", f137, 2, 512},
  {"512:_mm512_mul_pd(x, _mm512_roundscale_pd(x, 2 | _MM_FROUND_NO_EXC))", f138, 2, 512},
  {"512:_mm512_mul_pd(_mm512_roundscale_pd(x, 2 | _MM_FROUND_NO_EXC), x)", f139, 2, 512},
  {"512:_mm512_roundscale_pd(_mm512_div_pd(x, y), 2 | _MM_FROUND_NO_EXC)", f140, 2, 512},
  {"512:_mm512_div_pd(_mm512_roundscale_pd(x, 2 | _MM_FROUND_NO_EXC), y)", f141, 2, 512},
  {"512:_mm512_div_pd(x, _mm512_roundscale_pd(y, 2 | _MM_FROUND_NO_EXC))", f142, 2, 512},
  {"512:_mm512_div_pd(_mm512_roundscale_pd(x, 2 | _MM_FROUND_NO_EXC), _mm512_roundscale_pd(y, 2 | _MM_FROUND_NO_EXC))", f143, 2, 512},
  {"512:_mm512_div_pd(x, _mm512_roundscale_pd(x, 2 | _MM_FROUND_NO_EXC))", f144, 2, 512},
  {"512:_mm512_div_pd(_mm512_roundscale_pd(x, 2 | _MM_FROUND_NO_EXC), x)", f145, 2, 512},
  {"512:_mm512_roundscale_pd(_mm512_min_pd(x, y), 2 | _MM_FROUND_NO_EXC)", f146, 2, 512},
  {"512:_mm512_min_pd(_mm512_roundscale_pd(x, 2 | _MM_FROUND_NO_EXC), y)", f147, 2, 512},
  {"512:_mm512_min_pd(x, _mm512_roundscale_pd(y, 2 | _MM_FROUND_NO_EXC))", f148, 2, 512},
  {"512:_mm512_min_pd(_mm512_roundscale_pd(x, 2 | _MM_FROUND_NO_EXC), _mm512_roundscale_pd(y, 2 | _MM_FROUND_NO_EXC))", f149, 2, 512},
  {"512:_mm512_min_pd(x, _mm512_roundscale_pd(x, 2 | _MM_FROUND_NO_EXC))", f150, 2, 512},
  {"512:_mm512_min_pd(_mm512_roundscale_pd(x, 2 | _MM_FROUND_NO_EXC), x)", f151, 2, 512},
  {"512:_mm512_roundscale_pd(_mm512_max_pd(x, y), 2 | _MM_FROUND_NO_EXC)", f152, 2, 512},
  {"512:_mm512_max_pd(_mm512_roundscale_pd(x, 2 | _MM_FROUND_NO_EXC), y)", f153, 2, 512},
  {"512:_mm512_max_pd(x, _mm512_roundscale_pd(y, 2 | _MM_FROUND_NO_EXC))", f154, 2, 512},
  {"512:_mm512_max_pd(_mm512_roundscale_pd(x, 2 | _MM_FROUND_NO_EXC), _mm512_roundscale_pd(y, 2 | _MM_FROUND_NO_EXC))", f155, 2, 512},
  {"512:_mm512_max_pd(x, _mm512_roundscale_pd(x, 2 | _MM_FROUND_NO_EXC))", f156, 2, 512},
  {"512:_mm512_max_pd(_mm512_roundscale_pd(x, 2 | _MM_FROUND_NO_EXC), x)", f157, 2, 512},
  {"512:_mm512_roundscale_pd(_mm512_and_pd(x, y), 2 | _MM_FROUND_NO_EXC)", f158, 2, 512},
  {"512:_mm512_and_pd(_mm512_roundscale_pd(x, 2 | _MM_FROUND_NO_EXC), y)", f159, 2, 512},
  {"512:_mm512_and_pd(x, _mm512_roundscale_pd(y, 2 | _MM_FROUND_NO_EXC))", f160, 2, 512},
  {"512:_mm512_and_pd(_mm512_roundscale_pd(x, 2 | _MM_FROUND_NO_EXC), _mm512_roundscale_pd(y, 2 | _MM_FROUND_NO_EXC))", f161, 2, 512},
  {"512:_mm512_and_pd(x, _mm512_roundscale_pd(x, 2 | _MM_FROUND_NO_EXC))", f162, 2, 512},
  {"512:_mm512_and_pd(_mm512_roundscale_pd(x, 2 | _MM_FROUND_NO_EXC), x)", f163, 2, 512},
  {"512:_mm512_roundscale_pd(_mm512_or_pd(x, y), 2 | _MM_FROUND_NO_EXC)", f164, 2, 512},
  {"512:_mm512_or_pd(_mm512_roundscale_pd(x, 2 | _MM_FROUND_NO_EXC), y)", f165, 2, 512},
  {"512:_mm512_or_pd(x, _mm512_roundscale_pd(y, 2 | _MM_FROUND_NO_EXC))", f166, 2, 512},
  {"512:_mm512_or_pd(_mm512_roundscale_pd(x, 2 | _MM_FROUND_NO_EXC), _mm512_roundscale_pd(y, 2 | _MM_FROUND_NO_EXC))", f167, 2, 512},
  {"512:_mm512_or_pd(x, _mm512_roundscale_pd(x, 2 | _MM_FROUND_NO_EXC))", f168, 2, 512},
  {"512:_mm512_or_pd(_mm512_roundscale_pd(x, 2 | _MM_FROUND_NO_EXC), x)", f169, 2, 512},
  {"512:_mm512_roundscale_pd(_mm512_xor_pd(x, y), 2 | _MM_FROUND_NO_EXC)", f170, 2, 512},
  {"512:_mm512_xor_pd(_mm512_roundscale_pd(x, 2 | _MM_FROUND_NO_EXC), y)", f171, 2, 512},
  {"512:_mm512_xor_pd(x, _mm512_roundscale_pd(y, 2 | _MM_FROUND_NO_EXC))", f172, 2, 512},
  {"512:_mm512_xor_pd(_mm512_roundscale_pd(x, 2 | _MM_FROUND_NO_EXC), _mm512_roundscale_pd(y, 2 | _MM_FROUND_NO_EXC))", f173, 2, 512},
  {"512:_mm512_xor_pd(x, _mm512_roundscale_pd(x, 2 | _MM_FROUND_NO_EXC))", f174, 2, 512},
  {"512:_mm512_xor_pd(_mm512_roundscale_pd(x, 2 | _MM_FROUND_NO_EXC), x)", f175, 2, 512},
  {"512:_mm512_roundscale_pd(_mm512_andnot_pd(x, y), 2 | _MM_FROUND_NO_EXC)", f176, 2, 512},
  {"512:_mm512_andnot_pd(_mm512_roundscale_pd(x, 2 | _MM_FROUND_NO_EXC), y)", f177, 2, 512},
  {"512:_mm512_andnot_pd(x, _mm512_roundscale_pd(y, 2 | _MM_FROUND_NO_EXC))", f178, 2, 512},
  {"512:_mm512_andnot_pd(_mm512_roundscale_pd(x, 2 | _MM_FROUND_NO_EXC), _mm512_roundscale_pd(y, 2 | _MM_FROUND_NO_EXC))", f179, 2, 512},
  {"512:_mm512_andnot_pd(x, _mm512_roundscale_pd(x, 2 | _MM_FROUND_NO_EXC))", f180, 2, 512},
  {"512:_mm512_andnot_pd(_mm512_roundscale_pd(x, 2 | _MM_FROUND_NO_EXC), x)", f181, 2, 512},
  {"512:_mm512_roundscale_pd(_mm512_add_pd(x, y), 0 | _MM_FROUND_NO_EXC)", f182, 2, 512},
  {"512:_mm512_add_pd(_mm512_roundscale_pd(x, 0 | _MM_FROUND_NO_EXC), y)", f183, 2, 512},
  {"512:_mm512_add_pd(x, _mm512_roundscale_pd(y, 0 | _MM_FROUND_NO_EXC))", f184, 2, 512},
  {"512:_mm512_add_pd(_mm512_roundscale_pd(x, 0 | _MM_FROUND_NO_EXC), _mm512_roundscale_pd(y, 0 | _MM_FROUND_NO_EXC))", f185, 2, 512},
  {"512:_mm512_add_pd(x, _mm512_roundscale_pd(x, 0 | _MM_FROUND_NO_EXC))", f186, 2, 512},
  {"512:_mm512_add_pd(_mm512_roundscale_pd(x, 0 | _MM_FROUND_NO_EXC), x)", f187, 2, 512},
  {"512:_mm512_roundscale_pd(_mm512_sub_pd(x, y), 0 | _MM_FROUND_NO_EXC)", f188, 2, 512},
  {"512:_mm512_sub_pd(_mm512_roundscale_pd(x, 0 | _MM_FROUND_NO_EXC), y)", f189, 2, 512},
  {"512:_mm512_sub_pd(x, _mm512_roundscale_pd(y, 0 | _MM_FROUND_NO_EXC))", f190, 2, 512},
  {"512:_mm512_sub_pd(_mm512_roundscale_pd(x, 0 | _MM_FROUND_NO_EXC), _mm512_roundscale_pd(y, 0 | _MM_FROUND_NO_EXC))", f191, 2, 512},
  {"512:_mm512_sub_pd(x, _mm512_roundscale_pd(x, 0 | _MM_FROUND_NO_EXC))", f192, 2, 512},
  {"512:_mm512_sub_pd(_mm512_roundscale_pd(x, 0 | _MM_FROUND_NO_EXC), x)", f193, 2, 512},
  {"512:_mm512_roundscale_pd(_mm512_mul_pd(x, y), 0 | _MM_FROUND_NO_EXC)", f194, 2, 512},
  {"512:_mm512_mul_pd(_mm512_roundscale_pd(x, 0 | _MM_FROUND_NO_EXC), y)", f195, 2, 512},
  {"512:_mm512_mul_pd(x, _mm512_roundscale_pd(y, 0 | _MM_FROUND_NO_EXC))", f196, 2, 512},
  {"512:_mm512_mul_pd(_mm512_roundscale_pd(x, 0 | _MM_FROUND_NO_EXC), _mm512_roundscale_pd(y, 0 | _MM_FROUND_NO_EXC))", f197, 2, 512},
  {"512:_mm512_mul_pd(x, _mm512_roundscale_pd(x, 0 | _MM_FROUND_NO_EXC))", f198, 2, 512},
  {"512:_mm512_mul_pd(_mm512_roundscale_pd(x, 0 | _MM_FROUND_NO_EXC), x)", f199, 2, 512},
  {"512:_mm512_roundscale_pd(_mm512_div_pd(x, y), 0 | _MM_FROUND_NO_EXC)", f200, 2, 512},
  {"512:_mm512_div_pd(_mm512_roundscale_pd(x, 0 | _MM_FROUND_NO_EXC), y)", f201, 2, 512},
  {"512:_mm512_div_pd(x, _mm512_roundscale_pd(y, 0 | _MM_FROUND_NO_EXC))", f202, 2, 512},
  {"512:_mm512_div_pd(_mm512_roundscale_pd(x, 0 | _MM_FROUND_NO_EXC), _mm512_roundscale_pd(y, 0 | _MM_FROUND_NO_EXC))", f203, 2, 512},
  {"512:_mm512_div_pd(x, _mm512_roundscale_pd(x, 0 | _MM_FROUND_NO_EXC))", f204, 2, 512},
  {"512:_mm512_div_pd(_mm512_roundscale_pd(x, 0 | _MM_FROUND_NO_EXC), x)", f205, 2, 512},
  {"512:_mm512_roundscale_pd(_mm512_min_pd(x, y), 0 | _MM_FROUND_NO_EXC)", f206, 2, 512},
  {"512:_mm512_min_pd(_mm512_roundscale_pd(x, 0 | _MM_FROUND_NO_EXC), y)", f207, 2, 512},
  {"512:_mm512_min_pd(x, _mm512_roundscale_pd(y, 0 | _MM_FROUND_NO_EXC))", f208, 2, 512},
  {"512:_mm512_min_pd(_mm512_roundscale_pd(x, 0 | _MM_FROUND_NO_EXC), _mm512_roundscale_pd(y, 0 | _MM_FROUND_NO_EXC))", f209, 2, 512},
  {"512:_mm512_min_pd(x, _mm512_roundscale_pd(x, 0 | _MM_FROUND_NO_EXC))", f210, 2, 512},
  {"512:_mm512_min_pd(_mm512_roundscale_pd(x, 0 | _MM_FROUND_NO_EXC), x)", f211, 2, 512},
  {"512:_mm512_roundscale_pd(_mm512_max_pd(x, y), 0 | _MM_FROUND_NO_EXC)", f212, 2, 512},
  {"512:_mm512_max_pd(_mm512_roundscale_pd(x, 0 | _MM_FROUND_NO_EXC), y)", f213, 2, 512},
  {"512:_mm512_max_pd(x, _mm512_roundscale_pd(y, 0 | _MM_FROUND_NO_EXC))", f214, 2, 512},
  {"512:_mm512_max_pd(_mm512_roundscale_pd(x, 0 | _MM_FROUND_NO_EXC), _mm512_roundscale_pd(y, 0 | _MM_FROUND_NO_EXC))", f215, 2, 512},
  {"512:_mm512_max_pd(x, _mm512_roundscale_pd(x, 0 | _MM_FROUND_NO_EXC))", f216, 2, 512},
  {"512:_mm512_max_pd(_mm512_roundscale_pd(x, 0 | _MM_FROUND_NO_EXC), x)", f217, 2, 512},
  {"512:_mm512_roundscale_pd(_mm512_and_pd(x, y), 0 | _MM_FROUND_NO_EXC)", f218, 2, 512},
  {"512:_mm512_and_pd(_mm512_roundscale_pd(x, 0 | _MM_FROUND_NO_EXC), y)", f219, 2, 512},
  {"512:_mm512_and_pd(x, _mm512_roundscale_pd(y, 0 | _MM_FROUND_NO_EXC))", f220, 2, 512},
  {"512:_mm512_and_pd(_mm512_roundscale_pd(x, 0 | _MM_FROUND_NO_EXC), _mm512_roundscale_pd(y, 0 | _MM_FROUND_NO_EXC))", f221, 2, 512},
  {"512:_mm512_and_pd(x, _mm512_roundscale_pd(x, 0 | _MM_FROUND_NO_EXC))", f222, 2, 512},
  {"512:_mm512_and_pd(_mm512_roundscale_pd(x, 0 | _MM_FROUND_NO_EXC), x)", f223, 2, 512},
  {"512:_mm512_roundscale_pd(_mm512_or_pd(x, y), 0 | _MM_FROUND_NO_EXC)", f224, 2, 512},
  {"512:_mm512_or_pd(_mm512_roundscale_pd(x, 0 | _MM_FROUND_NO_EXC), y)", f225, 2, 512},
  {"512:_mm512_or_pd(x, _mm512_roundscale_pd(y, 0 | _MM_FROUND_NO_EXC))", f226, 2, 512},
  {"512:_mm512_or_pd(_mm512_roundscale_pd(x, 0 | _MM_FROUND_NO_EXC), _mm512_roundscale_pd(y, 0 | _MM_FROUND_NO_EXC))", f227, 2, 512},
  {"512:_mm512_or_pd(x, _mm512_roundscale_pd(x, 0 | _MM_FROUND_NO_EXC))", f228, 2, 512},
  {"512:_mm512_or_pd(_mm512_roundscale_pd(x, 0 | _MM_FROUND_NO_EXC), x)", f229, 2, 512},
  {"512:_mm512_roundscale_pd(_mm512_xor_pd(x, y), 0 | _MM_FROUND_NO_EXC)", f230, 2, 512},
  {"512:_mm512_xor_pd(_mm512_roundscale_pd(x, 0 | _MM_FROUND_NO_EXC), y)", f231, 2, 512},
  {"512:_mm512_xor_pd(x, _mm512_roundscale_pd(y, 0 | _MM_FROUND_NO_EXC))", f232, 2, 512},
  {"512:_mm512_xor_pd(_mm512_roundscale_pd(x, 0 | _MM_FROUND_NO_EXC), _mm512_roundscale_pd(y, 0 | _MM_FROUND_NO_EXC))", f233, 2, 512},
  {"512:_mm512_xor_pd(x, _mm512_roundscale_pd(x, 0 | _MM_FROUND_NO_EXC))", f234, 2, 512},
  {"512:_mm512_xor_pd(_mm512_roundscale_pd(x, 0 | _MM_FROUND_NO_EXC), x)", f235, 2, 512},
  {"512:_mm512_roundscale_pd(_mm512_andnot_pd(x, y), 0 | _MM_FROUND_NO_EXC)", f236, 2, 512},
  {"512:_mm512_andnot_pd(_mm512_roundscale_pd(x, 0 | _MM_FROUND_NO_EXC), y)", f237, 2, 512},
  {"512:_mm512_andnot_pd(x, _mm512_roundscale_pd(y, 0 | _MM_FROUND_NO_EXC))", f238, 2, 512},
  {"512:_mm512_andnot_pd(_mm512_roundscale_pd(x, 0 | _MM_FROUND_NO_EXC), _mm512_roundscale_pd(y, 0 | _MM_FROUND_NO_EXC))", f239, 2, 512},
  {"512:_mm512_andnot_pd(x, _mm512_roundscale_pd(x, 0 | _MM_FROUND_NO_EXC))", f240, 2, 512},
  {"512:_mm512_andnot_pd(_mm512_roundscale_pd(x, 0 | _MM_FROUND_NO_EXC), x)", f241, 2, 512},
  {"512:_mm512_add_pd(x, x)", f242, 2, 512},
  {"512:_mm512_add_pd(x, _mm512_setzero_pd())", f243, 2, 512},
  {"512:_mm512_add_pd(_mm512_setzero_pd(), x)", f244, 2, 512},
  {"512:_mm512_add_pd(x, _mm512_set1_pd(-0.0))", f245, 2, 512},
  {"512:_mm512_add_pd(_mm512_set1_pd(-0.0), x)", f246, 2, 512},
  {"512:_mm512_add_pd(x, _mm512_set1_pd(1.0))", f247, 2, 512},
  {"512:_mm512_add_pd(_mm512_set1_pd(1.0), x)", f248, 2, 512},
  {"512:_mm512_add_pd(x, _mm512_set1_pd(-1.0))", f249, 2, 512},
  {"512:_mm512_add_pd(_mm512_set1_pd(-1.0), x)", f250, 2, 512},
  {"512:_mm512_add_pd(x, _mm512_set1_pd(std::numeric_limits<double>::infinity()))", f251, 2, 512},
  {"512:_mm512_add_pd(_mm512_set1_pd(std::numeric_limits<double>::infinity()), x)", f252, 2, 512},
  {"512:_mm512_add_pd(x, _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN()))", f253, 2, 512},
  {"512:_mm512_add_pd(_mm512_set1_pd(std::numeric_limits<double>::quiet_NaN()), x)", f254, 2, 512},
  {"512:_mm512_add_pd(_mm512_add_pd(x, _mm512_setzero_pd()), _mm512_setzero_pd())", f255, 2, 512},
  {"512:_mm512_add_pd(_mm512_add_pd(x, _mm512_setzero_pd()), _mm512_set1_pd(-0.0))", f256, 2, 512},
  {"512:_mm512_add_pd(_mm512_add_pd(x, _mm512_setzero_pd()), _mm512_set1_pd(1.0))", f257, 2, 512},
  {"512:_mm512_add_pd(_mm512_add_pd(x, _mm512_setzero_pd()), _mm512_set1_pd(-1.0))", f258, 2, 512},
  {"512:_mm512_add_pd(_mm512_add_pd(x, _mm512_setzero_pd()), _mm512_set1_pd(std::numeric_limits<double>::infinity()))", f259, 2, 512},
  {"512:_mm512_add_pd(_mm512_add_pd(x, _mm512_setzero_pd()), _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN()))", f260, 2, 512},
  {"512:_mm512_add_pd(_mm512_add_pd(x, _mm512_set1_pd(-0.0)), _mm512_setzero_pd())", f261, 2, 512},
  {"512:_mm512_add_pd(_mm512_add_pd(x, _mm512_set1_pd(-0.0)), _mm512_set1_pd(-0.0))", f262, 2, 512},
  {"512:_mm512_add_pd(_mm512_add_pd(x, _mm512_set1_pd(-0.0)), _mm512_set1_pd(1.0))", f263, 2, 512},
  {"512:_mm512_add_pd(_mm512_add_pd(x, _mm512_set1_pd(-0.0)), _mm512_set1_pd(-1.0))", f264, 2, 512},
  {"512:_mm512_add_pd(_mm512_add_pd(x, _mm512_set1_pd(-0.0)), _mm512_set1_pd(std::numeric_limits<double>::infinity()))", f265, 2, 512},
  {"512:_mm512_add_pd(_mm512_add_pd(x, _mm512_set1_pd(-0.0)), _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN()))", f266, 2, 512},
  {"512:_mm512_add_pd(_mm512_add_pd(x, _mm512_set1_pd(1.0)), _mm512_setzero_pd())", f267, 2, 512},
  {"512:_mm512_add_pd(_mm512_add_pd(x, _mm512_set1_pd(1.0)), _mm512_set1_pd(-0.0))", f268, 2, 512},
  {"512:_mm512_add_pd(_mm512_add_pd(x, _mm512_set1_pd(1.0)), _mm512_set1_pd(1.0))", f269, 2, 512},
  {"512:_mm512_add_pd(_mm512_add_pd(x, _mm512_set1_pd(1.0)), _mm512_set1_pd(-1.0))", f270, 2, 512},
  {"512:_mm512_add_pd(_mm512_add_pd(x, _mm512_set1_pd(1.0)), _mm512_set1_pd(std::numeric_limits<double>::infinity()))", f271, 2, 512},
  {"512:_mm512_add_pd(_mm512_add_pd(x, _mm512_set1_pd(1.0)), _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN()))", f272, 2, 512},
  {"512:_mm512_add_pd(_mm512_add_pd(x, _mm512_set1_pd(-1.0)), _mm512_setzero_pd())", f273, 2, 512},
  {"512:_mm512_add_pd(_mm512_add_pd(x, _mm512_set1_pd(-1.0)), _mm512_set1_pd(-0.0))", f274, 2, 512},
  {"512:_mm512_add_pd(_mm512_add_pd(x, _mm512_set1_pd(-1.0)), _mm512_set1_pd(1.0))", f275, 2, 512},
  {"512:_mm512_add_pd(_mm512_add_pd(x, _mm512_set1_pd(-1.0)), _mm512_set1_pd(-1.0))", f276, 2, 512},
  {"512:_mm512_add_pd(_mm512_add_pd(x, _mm512_set1_pd(-1.0)), _mm512_set1_pd(std::numeric_limits<double>::infinity()))", f277, 2, 512},
  {"512:_mm512_add_pd(_mm512_add_pd(x, _mm512_set1_pd(-1.0)), _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN()))", f278, 2, 512},
  {"512:_mm512_add_pd(_mm512_add_pd(x, _mm512_set1_pd(std::numeric_limits<double>::infinity())), _mm512_setzero_pd())", f279, 2, 512},
  {"512:_mm512_add_pd(_mm512_add_pd(x, _mm512_set1_pd(std::numeric_limits<double>::infinity())), _mm512_set1_pd(-0.0))", f280, 2, 512},
  {"512:_mm512_add_pd(_mm512_add_pd(x, _mm512_set1_pd(std::numeric_limits<double>::infinity())), _mm512_set1_pd(1.0))", f281, 2, 512},
  {"512:_mm512_add_pd(_mm512_add_pd(x, _mm512_set1_pd(std::numeric_limits<double>::infinity())), _mm512_set1_pd(-1.0))", f282, 2, 512},
  {"512:_mm512_add_pd(_mm512_add_pd(x, _mm512_set1_pd(std::numeric_limits<double>::infinity())), _mm512_set1_pd(std::numeric_limits<double>::infinity()))", f283, 2, 512},
  {"512:_mm512_add_pd(_mm512_add_pd(x, _mm512_set1_pd(std::numeric_limits<double>::infinity())), _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN()))", f284, 2, 512},
  {"512:_mm512_add_pd(_mm512_add_pd(x, _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN())), _mm512_setzero_pd())", f285, 2, 512},
  {"512:_mm512_add_pd(_mm512_add_pd(x, _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN())), _mm512_set1_pd(-0.0))", f286, 2, 512},
  {"512:_mm512_add_pd(_mm512_add_pd(x, _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN())), _mm512_set1_pd(1.0))", f287, 2, 512},
  {"512:_mm512_add_pd(_mm512_add_pd(x, _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN())), _mm512_set1_pd(-1.0))", f288, 2, 512},
  {"512:_mm512_add_pd(_mm512_add_pd(x, _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN())), _mm512_set1_pd(std::numeric_limits<double>::infinity()))", f289, 2, 512},
  {"512:_mm512_add_pd(_mm512_add_pd(x, _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN())), _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN()))", f290, 2, 512},
  {"512:_mm512_sub_pd(x, x)", f291, 2, 512},
  {"512:_mm512_sub_pd(x, _mm512_setzero_pd())", f292, 2, 512},
  {"512:_mm512_sub_pd(_mm512_setzero_pd(), x)", f293, 2, 512},
  {"512:_mm512_sub_pd(x, _mm512_set1_pd(-0.0))", f294, 2, 512},
  {"512:_mm512_sub_pd(_mm512_set1_pd(-0.0), x)", f295, 2, 512},
  {"512:_mm512_sub_pd(x, _mm512_set1_pd(1.0))", f296, 2, 512},
  {"512:_mm512_sub_pd(_mm512_set1_pd(1.0), x)", f297, 2, 512},
  {"512:_mm512_sub_pd(x, _mm512_set1_pd(-1.0))", f298, 2, 512},
  {"512:_mm512_sub_pd(_mm512_set1_pd(-1.0), x)", f299, 2, 512},
  {"512:_mm512_sub_pd(x, _mm512_set1_pd(std::numeric_limits<double>::infinity()))", f300, 2, 512},
  {"512:_mm512_sub_pd(_mm512_set1_pd(std::numeric_limits<double>::infinity()), x)", f301, 2, 512},
  {"512:_mm512_sub_pd(x, _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN()))", f302, 2, 512},
  {"512:_mm512_sub_pd(_mm512_set1_pd(std::numeric_limits<double>::quiet_NaN()), x)", f303, 2, 512},
  {"512:_mm512_sub_pd(_mm512_sub_pd(x, _mm512_setzero_pd()), _mm512_setzero_pd())", f304, 2, 512},
  {"512:_mm512_sub_pd(_mm512_sub_pd(x, _mm512_setzero_pd()), _mm512_set1_pd(-0.0))", f305, 2, 512},
  {"512:_mm512_sub_pd(_mm512_sub_pd(x, _mm512_setzero_pd()), _mm512_set1_pd(1.0))", f306, 2, 512},
  {"512:_mm512_sub_pd(_mm512_sub_pd(x, _mm512_setzero_pd()), _mm512_set1_pd(-1.0))", f307, 2, 512},
  {"512:_mm512_sub_pd(_mm512_sub_pd(x, _mm512_setzero_pd()), _mm512_set1_pd(std::numeric_limits<double>::infinity()))", f308, 2, 512},
  {"512:_mm512_sub_pd(_mm512_sub_pd(x, _mm512_setzero_pd()), _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN()))", f309, 2, 512},
  {"512:_mm512_sub_pd(_mm512_sub_pd(x, _mm512_set1_pd(-0.0)), _mm512_setzero_pd())", f310, 2, 512},
  {"512:_mm512_sub_pd(_mm512_sub_pd(x, _mm512_set1_pd(-0.0)), _mm512_set1_pd(-0.0))", f311, 2, 512},
  {"512:_mm512_sub_pd(_mm512_sub_pd(x, _mm512_set1_pd(-0.0)), _mm512_set1_pd(1.0))", f312, 2, 512},
  {"512:_mm512_sub_pd(_mm512_sub_pd(x, _mm512_set1_pd(-0.0)), _mm512_set1_pd(-1.0))", f313, 2, 512},
  {"512:_mm512_sub_pd(_mm512_sub_pd(x, _mm512_set1_pd(-0.0)), _mm512_set1_pd(std::numeric_limits<double>::infinity()))", f314, 2, 512},
  {"512:_mm512_sub_pd(_mm512_sub_pd(x, _mm512_set1_pd(-0.0)), _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN()))", f315, 2, 512},
  {"512:_mm512_sub_pd(_mm512_sub_pd(x, _mm512_set1_pd(1.0)), _mm512_setzero_pd())", f316, 2, 512},
  {"512:_mm512_sub_pd(_mm512_sub_pd(x, _mm512_set1_pd(1.0)), _mm512_set1_pd(-0.0))", f317, 2, 512},
  {"512:_mm512_sub_pd(_mm512_sub_pd(x, _mm512_set1_pd(1.0)), _mm512_set1_pd(1.0))", f318, 2, 512},
  {"512:_mm512_sub_pd(_mm512_sub_pd(x, _mm512_set1_pd(1.0)), _mm512_set1_pd(-1.0))", f319, 2, 512},
  {"512:_mm512_sub_pd(_mm512_sub_pd(x, _mm512_set1_pd(1.0)), _mm512_set1_pd(std::numeric_limits<double>::infinity()))", f320, 2, 512},
  {"512:_mm512_sub_pd(_mm512_sub_pd(x, _mm512_set1_pd(1.0)), _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN()))", f321, 2, 512},
  {"512:_mm512_sub_pd(_mm512_sub_pd(x, _mm512_set1_pd(-1.0)), _mm512_setzero_pd())", f322, 2, 512},
  {"512:_mm512_sub_pd(_mm512_sub_pd(x, _mm512_set1_pd(-1.0)), _mm512_set1_pd(-0.0))", f323, 2, 512},
  {"512:_mm512_sub_pd(_mm512_sub_pd(x, _mm512_set1_pd(-1.0)), _mm512_set1_pd(1.0))", f324, 2, 512},
  {"512:_mm512_sub_pd(_mm512_sub_pd(x, _mm512_set1_pd(-1.0)), _mm512_set1_pd(-1.0))", f325, 2, 512},
  {"512:_mm512_sub_pd(_mm512_sub_pd(x, _mm512_set1_pd(-1.0)), _mm512_set1_pd(std::numeric_limits<double>::infinity()))", f326, 2, 512},
  {"512:_mm512_sub_pd(_mm512_sub_pd(x, _mm512_set1_pd(-1.0)), _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN()))", f327, 2, 512},
  {"512:_mm512_sub_pd(_mm512_sub_pd(x, _mm512_set1_pd(std::numeric_limits<double>::infinity())), _mm512_setzero_pd())", f328, 2, 512},
  {"512:_mm512_sub_pd(_mm512_sub_pd(x, _mm512_set1_pd(std::numeric_limits<double>::infinity())), _mm512_set1_pd(-0.0))", f329, 2, 512},
  {"512:_mm512_sub_pd(_mm512_sub_pd(x, _mm512_set1_pd(std::numeric_limits<double>::infinity())), _mm512_set1_pd(1.0))", f330, 2, 512},
  {"512:_mm512_sub_pd(_mm512_sub_pd(x, _mm512_set1_pd(std::numeric_limits<double>::infinity())), _mm512_set1_pd(-1.0))", f331, 2, 512},
  {"512:_mm512_sub_pd(_mm512_sub_pd(x, _mm512_set1_pd(std::numeric_limits<double>::infinity())), _mm512_set1_pd(std::numeric_limits<double>::infinity()))", f332, 2, 512},
  {"512:_mm512_sub_pd(_mm512_sub_pd(x, _mm512_set1_pd(std::numeric_limits<double>::infinity())), _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN()))", f333, 2, 512},
  {"512:_mm512_sub_pd(_mm512_sub_pd(x, _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN())), _mm512_setzero_pd())", f334, 2, 512},
  {"512:_mm512_sub_pd(_mm512_sub_pd(x, _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN())), _mm512_set1_pd(-0.0))", f335, 2, 512},
  {"512:_mm512_sub_pd(_mm512_sub_pd(x, _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN())), _mm512_set1_pd(1.0))", f336, 2, 512},
  {"512:_mm512_sub_pd(_mm512_sub_pd(x, _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN())), _mm512_set1_pd(-1.0))", f337, 2, 512},
  {"512:_mm512_sub_pd(_mm512_sub_pd(x, _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN())), _mm512_set1_pd(std::numeric_limits<double>::infinity()))", f338, 2, 512},
  {"512:_mm512_sub_pd(_mm512_sub_pd(x, _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN())), _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN()))", f339, 2, 512},
  {"512:_mm512_mul_pd(x, x)", f340, 2, 512},
  {"512:_mm512_mul_pd(x, _mm512_setzero_pd())", f341, 2, 512},
  {"512:_mm512_mul_pd(_mm512_setzero_pd(), x)", f342, 2, 512},
  {"512:_mm512_mul_pd(x, _mm512_set1_pd(-0.0))", f343, 2, 512},
  {"512:_mm512_mul_pd(_mm512_set1_pd(-0.0), x)", f344, 2, 512},
  {"512:_mm512_mul_pd(x, _mm512_set1_pd(1.0))", f345, 2, 512},
  {"512:_mm512_mul_pd(_mm512_set1_pd(1.0), x)", f346, 2, 512},
  {"512:_mm512_mul_pd(x, _mm512_set1_pd(-1.0))", f347, 2, 512},
  {"512:_mm512_mul_pd(_mm512_set1_pd(-1.0), x)", f348, 2, 512},
  {"512:_mm512_mul_pd(x, _mm512_set1_pd(std::numeric_limits<double>::infinity()))", f349, 2, 512},
  {"512:_mm512_mul_pd(_mm512_set1_pd(std::numeric_limits<double>::infinity()), x)", f350, 2, 512},
  {"512:_mm512_mul_pd(x, _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN()))", f351, 2, 512},
  {"512:_mm512_mul_pd(_mm512_set1_pd(std::numeric_limits<double>::quiet_NaN()), x)", f352, 2, 512},
  {"512:_mm512_mul_pd(_mm512_mul_pd(x, _mm512_setzero_pd()), _mm512_setzero_pd())", f353, 2, 512},
  {"512:_mm512_mul_pd(_mm512_mul_pd(x, _mm512_setzero_pd()), _mm512_set1_pd(-0.0))", f354, 2, 512},
  {"512:_mm512_mul_pd(_mm512_mul_pd(x, _mm512_setzero_pd()), _mm512_set1_pd(1.0))", f355, 2, 512},
  {"512:_mm512_mul_pd(_mm512_mul_pd(x, _mm512_setzero_pd()), _mm512_set1_pd(-1.0))", f356, 2, 512},
  {"512:_mm512_mul_pd(_mm512_mul_pd(x, _mm512_setzero_pd()), _mm512_set1_pd(std::numeric_limits<double>::infinity()))", f357, 2, 512},
  {"512:_mm512_mul_pd(_mm512_mul_pd(x, _mm512_setzero_pd()), _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN()))", f358, 2, 512},
  {"512:_mm512_mul_pd(_mm512_mul_pd(x, _mm512_set1_pd(-0.0)), _mm512_setzero_pd())", f359, 2, 512},
  {"512:_mm512_mul_pd(_mm512_mul_pd(x, _mm512_set1_pd(-0.0)), _mm512_set1_pd(-0.0))", f360, 2, 512},
  {"512:_mm512_mul_pd(_mm512_mul_pd(x, _mm512_set1_pd(-0.0)), _mm512_set1_pd(1.0))", f361, 2, 512},
  {"512:_mm512_mul_pd(_mm512_mul_pd(x, _mm512_set1_pd(-0.0)), _mm512_set1_pd(-1.0))", f362, 2, 512},
  {"512:_mm512_mul_pd(_mm512_mul_pd(x, _mm512_set1_pd(-0.0)), _mm512_set1_pd(std::numeric_limits<double>::infinity()))", f363, 2, 512},
  {"512:_mm512_mul_pd(_mm512_mul_pd(x, _mm512_set1_pd(-0.0)), _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN()))", f364, 2, 512},
  {"512:_mm512_mul_pd(_mm512_mul_pd(x, _mm512_set1_pd(1.0)), _mm512_setzero_pd())", f365, 2, 512},
  {"512:_mm512_mul_pd(_mm512_mul_pd(x, _mm512_set1_pd(1.0)), _mm512_set1_pd(-0.0))", f366, 2, 512},
  {"512:_mm512_mul_pd(_mm512_mul_pd(x, _mm512_set1_pd(1.0)), _mm512_set1_pd(1.0))", f367, 2, 512},
  {"512:_mm512_mul_pd(_mm512_mul_pd(x, _mm512_set1_pd(1.0)), _mm512_set1_pd(-1.0))", f368, 2, 512},
  {"512:_mm512_mul_pd(_mm512_mul_pd(x, _mm512_set1_pd(1.0)), _mm512_set1_pd(std::numeric_limits<double>::infinity()))", f369, 2, 512},
  {"512:_mm512_mul_pd(_mm512_mul_pd(x, _mm512_set1_pd(1.0)), _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN()))", f370, 2, 512},
  {"512:_mm512_mul_pd(_mm512_mul_pd(x, _mm512_set1_pd(-1.0)), _mm512_setzero_pd())", f371, 2, 512},
  {"512:_mm512_mul_pd(_mm512_mul_pd(x, _mm512_set1_pd(-1.0)), _mm512_set1_pd(-0.0))", f372, 2, 512},
  {"512:_mm512_mul_pd(_mm512_mul_pd(x, _mm512_set1_pd(-1.0)), _mm512_set1_pd(1.0))", f373, 2, 512},
  {"512:_mm512_mul_pd(_mm512_mul_pd(x, _mm512_set1_pd(-1.0)), _mm512_set1_pd(std::numeric_limits<double>::infinity()))", f374, 2, 512},
  {"512:_mm512_mul_pd(_mm512_mul_pd(x, _mm512_set1_pd(-1.0)), _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN()))", f375, 2, 512},
  {"512:_mm512_mul_pd(_mm512_mul_pd(x, _mm512_set1_pd(std::numeric_limits<double>::infinity())), _mm512_setzero_pd())", f376, 2, 512},
  {"512:_mm512_mul_pd(_mm512_mul_pd(x, _mm512_set1_pd(std::numeric_limits<double>::infinity())), _mm512_set1_pd(-0.0))", f377, 2, 512},
  {"512:_mm512_mul_pd(_mm512_mul_pd(x, _mm512_set1_pd(std::numeric_limits<double>::infinity())), _mm512_set1_pd(1.0))", f378, 2, 512},
  {"512:_mm512_mul_pd(_mm512_mul_pd(x, _mm512_set1_pd(std::numeric_limits<double>::infinity())), _mm512_set1_pd(-1.0))", f379, 2, 512},
  {"512:_mm512_mul_pd(_mm512_mul_pd(x, _mm512_set1_pd(std::numeric_limits<double>::infinity())), _mm512_set1_pd(std::numeric_limits<double>::infinity()))", f380, 2, 512},
  {"512:_mm512_mul_pd(_mm512_mul_pd(x, _mm512_set1_pd(std::numeric_limits<double>::infinity())), _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN()))", f381, 2, 512},
  {"512:_mm512_mul_pd(_mm512_mul_pd(x, _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN())), _mm512_setzero_pd())", f382, 2, 512},
  {"512:_mm512_mul_pd(_mm512_mul_pd(x, _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN())), _mm512_set1_pd(-0.0))", f383, 2, 512},
  {"512:_mm512_mul_pd(_mm512_mul_pd(x, _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN())), _mm512_set1_pd(1.0))", f384, 2, 512},
  {"512:_mm512_mul_pd(_mm512_mul_pd(x, _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN())), _mm512_set1_pd(-1.0))", f385, 2, 512},
  {"512:_mm512_mul_pd(_mm512_mul_pd(x, _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN())), _mm512_set1_pd(std::numeric_limits<double>::infinity()))", f386, 2, 512},
  {"512:_mm512_mul_pd(_mm512_mul_pd(x, _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN())), _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN()))", f387, 2, 512},
  {"512:_mm512_div_pd(x, x)", f388, 2, 512},
  {"512:_mm512_div_pd(x, _mm512_setzero_pd())", f389, 2, 512},
  {"512:_mm512_div_pd(_mm512_setzero_pd(), x)", f390, 2, 512},
  {"512:_mm512_div_pd(x, _mm512_set1_pd(-0.0))", f391, 2, 512},
  {"512:_mm512_div_pd(_mm512_set1_pd(-0.0), x)", f392, 2, 512},
  {"512:_mm512_div_pd(x, _mm512_set1_pd(1.0))", f393, 2, 512},
  {"512:_mm512_div_pd(_mm512_set1_pd(1.0), x)", f394, 2, 512},
  {"512:_mm512_div_pd(x, _mm512_set1_pd(-1.0))", f395, 2, 512},
  {"512:_mm512_div_pd(_mm512_set1_pd(-1.0), x)", f396, 2, 512},
  {"512:_mm512_div_pd(x, _mm512_set1_pd(std::numeric_limits<double>::infinity()))", f397, 2, 512},
  {"512:_mm512_div_pd(_mm512_set1_pd(std::numeric_limits<double>::infinity()), x)", f398, 2, 512},
  {"512:_mm512_div_pd(x, _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN()))", f399, 2, 512},
  {"512:_mm512_div_pd(_mm512_set1_pd(std::numeric_limits<double>::quiet_NaN()), x)", f400, 2, 512},
  {"512:_mm512_div_pd(_mm512_div_pd(x, _mm512_setzero_pd()), _mm512_setzero_pd())", f401, 2, 512},
  {"512:_mm512_div_pd(_mm512_div_pd(x, _mm512_setzero_pd()), _mm512_set1_pd(-0.0))", f402, 2, 512},
  {"512:_mm512_div_pd(_mm512_div_pd(x, _mm512_setzero_pd()), _mm512_set1_pd(1.0))", f403, 2, 512},
  {"512:_mm512_div_pd(_mm512_div_pd(x, _mm512_setzero_pd()), _mm512_set1_pd(-1.0))", f404, 2, 512},
  {"512:_mm512_div_pd(_mm512_div_pd(x, _mm512_setzero_pd()), _mm512_set1_pd(std::numeric_limits<double>::infinity()))", f405, 2, 512},
  {"512:_mm512_div_pd(_mm512_div_pd(x, _mm512_setzero_pd()), _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN()))", f406, 2, 512},
  {"512:_mm512_div_pd(_mm512_div_pd(x, _mm512_set1_pd(-0.0)), _mm512_setzero_pd())", f407, 2, 512},
  {"512:_mm512_div_pd(_mm512_div_pd(x, _mm512_set1_pd(-0.0)), _mm512_set1_pd(-0.0))", f408, 2, 512},
  {"512:_mm512_div_pd(_mm512_div_pd(x, _mm512_set1_pd(-0.0)), _mm512_set1_pd(1.0))", f409, 2, 512},
  {"512:_mm512_div_pd(_mm512_div_pd(x, _mm512_set1_pd(-0.0)), _mm512_set1_pd(-1.0))", f410, 2, 512},
  {"512:_mm512_div_pd(_mm512_div_pd(x, _mm512_set1_pd(-0.0)), _mm512_set1_pd(std::numeric_limits<double>::infinity()))", f411, 2, 512},
  {"512:_mm512_div_pd(_mm512_div_pd(x, _mm512_set1_pd(-0.0)), _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN()))", f412, 2, 512},
  {"512:_mm512_div_pd(_mm512_div_pd(x, _mm512_set1_pd(1.0)), _mm512_setzero_pd())", f413, 2, 512},
  {"512:_mm512_div_pd(_mm512_div_pd(x, _mm512_set1_pd(1.0)), _mm512_set1_pd(-0.0))", f414, 2, 512},
  {"512:_mm512_div_pd(_mm512_div_pd(x, _mm512_set1_pd(1.0)), _mm512_set1_pd(1.0))", f415, 2, 512},
  {"512:_mm512_div_pd(_mm512_div_pd(x, _mm512_set1_pd(1.0)), _mm512_set1_pd(-1.0))", f416, 2, 512},
  {"512:_mm512_div_pd(_mm512_div_pd(x, _mm512_set1_pd(1.0)), _mm512_set1_pd(std::numeric_limits<double>::infinity()))", f417, 2, 512},
  {"512:_mm512_div_pd(_mm512_div_pd(x, _mm512_set1_pd(1.0)), _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN()))", f418, 2, 512},
  {"512:_mm512_div_pd(_mm512_div_pd(x, _mm512_set1_pd(-1.0)), _mm512_setzero_pd())", f419, 2, 512},
  {"512:_mm512_div_pd(_mm512_div_pd(x, _mm512_set1_pd(-1.0)), _mm512_set1_pd(-0.0))", f420, 2, 512},
  {"512:_mm512_div_pd(_mm512_div_pd(x, _mm512_set1_pd(-1.0)), _mm512_set1_pd(1.0))", f421, 2, 512},
  {"512:_mm512_div_pd(_mm512_div_pd(x, _mm512_set1_pd(-1.0)), _mm512_set1_pd(-1.0))", f422, 2, 512},
  {"512:_mm512_div_pd(_mm512_div_pd(x, _mm512_set1_pd(-1.0)), _mm512_set1_pd(std::numeric_limits<double>::infinity()))", f423, 2, 512},
  {"512:_mm512_div_pd(_mm512_div_pd(x, _mm512_set1_pd(-1.0)), _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN()))", f424, 2, 512},
  {"512:_mm512_div_pd(_mm512_div_pd(x, _mm512_set1_pd(std::numeric_limits<double>::infinity())), _mm512_setzero_pd())", f425, 2, 512},
  {"512:_mm512_div_pd(_mm512_div_pd(x, _mm512_set1_pd(std::numeric_limits<double>::infinity())), _mm512_set1_pd(-0.0))", f426, 2, 512},
  {"512:_mm512_div_pd(_mm512_div_pd(x, _mm512_set1_pd(std::numeric_limits<double>::infinity())), _mm512_set1_pd(1.0))", f427, 2, 512},
  {"512:_mm512_div_pd(_mm512_div_pd(x, _mm512_set1_pd(std::numeric_limits<double>::infinity())), _mm512_set1_pd(-1.0))", f428, 2, 512},
  {"512:_mm512_div_pd(_mm512_div_pd(x, _mm512_set1_pd(std::numeric_limits<double>::infinity())), _mm512_set1_pd(std::numeric_limits<double>::infinity()))", f429, 2, 512},
  {"512:_mm512_div_pd(_mm512_div_pd(x, _mm512_set1_pd(std::numeric_limits<double>::infinity())), _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN()))", f430, 2, 512},
  {"512:_mm512_div_pd(_mm512_div_pd(x, _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN())), _mm512_setzero_pd())", f431, 2, 512},
  {"512:_mm512_div_pd(_mm512_div_pd(x, _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN())), _mm512_set1_pd(-0.0))", f432, 2, 512},
  {"512:_mm512_div_pd(_mm512_div_pd(x, _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN())), _mm512_set1_pd(1.0))", f433, 2, 512},
  {"512:_mm512_div_pd(_mm512_div_pd(x, _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN())), _mm512_set1_pd(-1.0))", f434, 2, 512},
  {"512:_mm512_div_pd(_mm512_div_pd(x, _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN())), _mm512_set1_pd(std::numeric_limits<double>::infinity()))", f435, 2, 512},
  {"512:_mm512_div_pd(_mm512_div_pd(x, _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN())), _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN()))", f436, 2, 512},
  {"512:_mm512_min_pd(x, x)", f437, 2, 512},
  {"512:_mm512_min_pd(x, _mm512_setzero_pd())", f438, 2, 512},
  {"512:_mm512_min_pd(_mm512_setzero_pd(), x)", f439, 2, 512},
  {"512:_mm512_min_pd(x, _mm512_set1_pd(-0.0))", f440, 2, 512},
  {"512:_mm512_min_pd(_mm512_set1_pd(-0.0), x)", f441, 2, 512},
  {"512:_mm512_min_pd(x, _mm512_set1_pd(1.0))", f442, 2, 512},
  {"512:_mm512_min_pd(_mm512_set1_pd(1.0), x)", f443, 2, 512},
  {"512:_mm512_min_pd(x, _mm512_set1_pd(-1.0))", f444, 2, 512},
  {"512:_mm512_min_pd(_mm512_set1_pd(-1.0), x)", f445, 2, 512},
  {"512:_mm512_min_pd(x, _mm512_set1_pd(std::numeric_limits<double>::infinity()))", f446, 2, 512},
  {"512:_mm512_min_pd(_mm512_set1_pd(std::numeric_limits<double>::infinity()), x)", f447, 2, 512},
  {"512:_mm512_min_pd(x, _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN()))", f448, 2, 512},
  {"512:_mm512_min_pd(_mm512_set1_pd(std::numeric_limits<double>::quiet_NaN()), x)", f449, 2, 512},
  {"512:_mm512_min_pd(_mm512_min_pd(x, _mm512_setzero_pd()), _mm512_setzero_pd())", f450, 2, 512},
  {"512:_mm512_min_pd(_mm512_min_pd(x, _mm512_setzero_pd()), _mm512_set1_pd(-0.0))", f451, 2, 512},
  {"512:_mm512_min_pd(_mm512_min_pd(x, _mm512_setzero_pd()), _mm512_set1_pd(1.0))", f452, 2, 512},
  {"512:_mm512_min_pd(_mm512_min_pd(x, _mm512_setzero_pd()), _mm512_set1_pd(-1.0))", f453, 2, 512},
  {"512:_mm512_min_pd(_mm512_min_pd(x, _mm512_setzero_pd()), _mm512_set1_pd(std::numeric_limits<double>::infinity()))", f454, 2, 512},
  {"512:_mm512_min_pd(_mm512_min_pd(x, _mm512_setzero_pd()), _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN()))", f455, 2, 512},
  {"512:_mm512_min_pd(_mm512_min_pd(x, _mm512_set1_pd(-0.0)), _mm512_setzero_pd())", f456, 2, 512},
  {"512:_mm512_min_pd(_mm512_min_pd(x, _mm512_set1_pd(-0.0)), _mm512_set1_pd(-0.0))", f457, 2, 512},
  {"512:_mm512_min_pd(_mm512_min_pd(x, _mm512_set1_pd(-0.0)), _mm512_set1_pd(1.0))", f458, 2, 512},
  {"512:_mm512_min_pd(_mm512_min_pd(x, _mm512_set1_pd(-0.0)), _mm512_set1_pd(-1.0))", f459, 2, 512},
  {"512:_mm512_min_pd(_mm512_min_pd(x, _mm512_set1_pd(-0.0)), _mm512_set1_pd(std::numeric_limits<double>::infinity()))", f460, 2, 512},
  {"512:_mm512_min_pd(_mm512_min_pd(x, _mm512_set1_pd(-0.0)), _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN()))", f461, 2, 512},
  {"512:_mm512_min_pd(_mm512_min_pd(x, _mm512_set1_pd(1.0)), _mm512_setzero_pd())", f462, 2, 512},
  {"512:_mm512_min_pd(_mm512_min_pd(x, _mm512_set1_pd(1.0)), _mm512_set1_pd(-0.0))", f463, 2, 512},
  {"512:_mm512_min_pd(_mm512_min_pd(x, _mm512_set1_pd(1.0)), _mm512_set1_pd(1.0))", f464, 2, 512},
  {"512:_mm512_min_pd(_mm512_min_pd(x, _mm512_set1_pd(1.0)), _mm512_set1_pd(-1.0))", f465, 2, 512},
  {"512:_mm512_min_pd(_mm512_min_pd(x, _mm512_set1_pd(1.0)), _mm512_set1_pd(std::numeric_limits<double>::infinity()))", f466, 2, 512},
  {"512:_mm512_min_pd(_mm512_min_pd(x, _mm512_set1_pd(1.0)), _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN()))", f467, 2, 512},
  {"512:_mm512_min_pd(_mm512_min_pd(x, _mm512_set1_pd(-1.0)), _mm512_setzero_pd())", f468, 2, 512},
  {"512:_mm512_min_pd(_mm512_min_pd(x, _mm512_set1_pd(-1.0)), _mm512_set1_pd(-0.0))", f469, 2, 512},
  {"512:_mm512_min_pd(_mm512_min_pd(x, _mm512_set1_pd(-1.0)), _mm512_set1_pd(1.0))", f470, 2, 512},
  {"512:_mm512_min_pd(_mm512_min_pd(x, _mm512_set1_pd(-1.0)), _mm512_set1_pd(-1.0))", f471, 2, 512},
  {"512:_mm512_min_pd(_mm512_min_pd(x, _mm512_set1_pd(-1.0)), _mm512_set1_pd(std::numeric_limits<double>::infinity()))", f472, 2, 512},
  {"512:_mm512_min_pd(_mm512_min_pd(x, _mm512_set1_pd(-1.0)), _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN()))", f473, 2, 512},
  {"512:_mm512_min_pd(_mm512_min_pd(x, _mm512_set1_pd(std::numeric_limits<double>::infinity())), _mm512_setzero_pd())", f474, 2, 512},
  {"512:_mm512_min_pd(_mm512_min_pd(x, _mm512_set1_pd(std::numeric_limits<double>::infinity())), _mm512_set1_pd(-0.0))", f475, 2, 512},
  {"512:_mm512_min_pd(_mm512_min_pd(x, _mm512_set1_pd(std::numeric_limits<double>::infinity())), _mm512_set1_pd(1.0))", f476, 2, 512},
  {"512:_mm512_min_pd(_mm512_min_pd(x, _mm512_set1_pd(std::numeric_limits<double>::infinity())), _mm512_set1_pd(-1.0))", f477, 2, 512},
  {"512:_mm512_min_pd(_mm512_min_pd(x, _mm512_set1_pd(std::numeric_limits<double>::infinity())), _mm512_set1_pd(std::numeric_limits<double>::infinity()))", f478, 2, 512},
  {"512:_mm512_min_pd(_mm512_min_pd(x, _mm512_set1_pd(std::numeric_limits<double>::infinity())), _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN()))", f479, 2, 512},
  {"512:_mm512_min_pd(_mm512_min_pd(x, _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN())), _mm512_setzero_pd())", f480, 2, 512},
  {"512:_mm512_min_pd(_mm512_min_pd(x, _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN())), _mm512_set1_pd(-0.0))", f481, 2, 512},
  {"512:_mm512_min_pd(_mm512_min_pd(x, _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN())), _mm512_set1_pd(1.0))", f482, 2, 512},
  {"512:_mm512_min_pd(_mm512_min_pd(x, _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN())), _mm512_set1_pd(-1.0))", f483, 2, 512},
  {"512:_mm512_min_pd(_mm512_min_pd(x, _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN())), _mm512_set1_pd(std::numeric_limits<double>::infinity()))", f484, 2, 512},
  {"512:_mm512_min_pd(_mm512_min_pd(x, _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN())), _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN()))", f485, 2, 512},
  {"512:_mm512_max_pd(x, x)", f486, 2, 512},
  {"512:_mm512_max_pd(x, _mm512_setzero_pd())", f487, 2, 512},
  {"512:_mm512_max_pd(_mm512_setzero_pd(), x)", f488, 2, 512},
  {"512:_mm512_max_pd(x, _mm512_set1_pd(-0.0))", f489, 2, 512},
  {"512:_mm512_max_pd(_mm512_set1_pd(-0.0), x)", f490, 2, 512},
  {"512:_mm512_max_pd(x, _mm512_set1_pd(1.0))", f491, 2, 512},
  {"512:_mm512_max_pd(_mm512_set1_pd(1.0), x)", f492, 2, 512},
  {"512:_mm512_max_pd(x, _mm512_set1_pd(-1.0))", f493, 2, 512},
  {"512:_mm512_max_pd(_mm512_set1_pd(-1.0), x)", f494, 2, 512},
  {"512:_mm512_max_pd(x, _mm512_set1_pd(std::numeric_limits<double>::infinity()))", f495, 2, 512},
  {"512:_mm512_max_pd(_mm512_set1_pd(std::numeric_limits<double>::infinity()), x)", f496, 2, 512},
  {"512:_mm512_max_pd(x, _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN()))", f497, 2, 512},
  {"512:_mm512_max_pd(_mm512_set1_pd(std::numeric_limits<double>::quiet_NaN()), x)", f498, 2, 512},
  {"512:_mm512_max_pd(_mm512_max_pd(x, _mm512_setzero_pd()), _mm512_setzero_pd())", f499, 2, 512},
  {"512:_mm512_max_pd(_mm512_max_pd(x, _mm512_setzero_pd()), _mm512_set1_pd(-0.0))", f500, 2, 512},
  {"512:_mm512_max_pd(_mm512_max_pd(x, _mm512_setzero_pd()), _mm512_set1_pd(1.0))", f501, 2, 512},
  {"512:_mm512_max_pd(_mm512_max_pd(x, _mm512_setzero_pd()), _mm512_set1_pd(-1.0))", f502, 2, 512},
  {"512:_mm512_max_pd(_mm512_max_pd(x, _mm512_setzero_pd()), _mm512_set1_pd(std::numeric_limits<double>::infinity()))", f503, 2, 512},
  {"512:_mm512_max_pd(_mm512_max_pd(x, _mm512_setzero_pd()), _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN()))", f504, 2, 512},
  {"512:_mm512_max_pd(_mm512_max_pd(x, _mm512_set1_pd(-0.0)), _mm512_setzero_pd())", f505, 2, 512},
  {"512:_mm512_max_pd(_mm512_max_pd(x, _mm512_set1_pd(-0.0)), _mm512_set1_pd(-0.0))", f506, 2, 512},
  {"512:_mm512_max_pd(_mm512_max_pd(x, _mm512_set1_pd(-0.0)), _mm512_set1_pd(1.0))", f507, 2, 512},
  {"512:_mm512_max_pd(_mm512_max_pd(x, _mm512_set1_pd(-0.0)), _mm512_set1_pd(-1.0))", f508, 2, 512},
  {"512:_mm512_max_pd(_mm512_max_pd(x, _mm512_set1_pd(-0.0)), _mm512_set1_pd(std::numeric_limits<double>::infinity()))", f509, 2, 512},
  {"512:_mm512_max_pd(_mm512_max_pd(x, _mm512_set1_pd(-0.0)), _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN()))", f510, 2, 512},
  {"512:_mm512_max_pd(_mm512_max_pd(x, _mm512_set1_pd(1.0)), _mm512_setzero_pd())", f511, 2, 512},
  {"512:_mm512_max_pd(_mm512_max_pd(x, _mm512_set1_pd(1.0)), _mm512_set1_pd(-0.0))", f512, 2, 512},
  {"512:_mm512_max_pd(_mm512_max_pd(x, _mm512_set1_pd(1.0)), _mm512_set1_pd(1.0))", f513, 2, 512},
  {"512:_mm512_max_pd(_mm512_max_pd(x, _mm512_set1_pd(1.0)), _mm512_set1_pd(-1.0))", f514, 2, 512},
  {"512:_mm512_max_pd(_mm512_max_pd(x, _mm512_set1_pd(1.0)), _mm512_set1_pd(std::numeric_limits<double>::infinity()))", f515, 2, 512},
  {"512:_mm512_max_pd(_mm512_max_pd(x, _mm512_set1_pd(1.0)), _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN()))", f516, 2, 512},
  {"512:_mm512_max_pd(_mm512_max_pd(x, _mm512_set1_pd(-1.0)), _mm512_setzero_pd())", f517, 2, 512},
  {"512:_mm512_max_pd(_mm512_max_pd(x, _mm512_set1_pd(-1.0)), _mm512_set1_pd(-0.0))", f518, 2, 512},
  {"512:_mm512_max_pd(_mm512_max_pd(x, _mm512_set1_pd(-1.0)), _mm512_set1_pd(1.0))", f519, 2, 512},
  {"512:_mm512_max_pd(_mm512_max_pd(x, _mm512_set1_pd(-1.0)), _mm512_set1_pd(-1.0))", f520, 2, 512},
  {"512:_mm512_max_pd(_mm512_max_pd(x, _mm512_set1_pd(-1.0)), _mm512_set1_pd(std::numeric_limits<double>::infinity()))", f521, 2, 512},
  {"512:_mm512_max_pd(_mm512_max_pd(x, _mm512_set1_pd(-1.0)), _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN()))", f522, 2, 512},
  {"512:_mm512_max_pd(_mm512_max_pd(x, _mm512_set1_pd(std::numeric_limits<double>::infinity())), _mm512_setzero_pd())", f523, 2, 512},
  {"512:_mm512_max_pd(_mm512_max_pd(x, _mm512_set1_pd(std::numeric_limits<double>::infinity())), _mm512_set1_pd(-0.0))", f524, 2, 512},
  {"512:_mm512_max_pd(_mm512_max_pd(x, _mm512_set1_pd(std::numeric_limits<double>::infinity())), _mm512_set1_pd(1.0))", f525, 2, 512},
  {"512:_mm512_max_pd(_mm512_max_pd(x, _mm512_set1_pd(std::numeric_limits<double>::infinity())), _mm512_set1_pd(-1.0))", f526, 2, 512},
  {"512:_mm512_max_pd(_mm512_max_pd(x, _mm512_set1_pd(std::numeric_limits<double>::infinity())), _mm512_set1_pd(std::numeric_limits<double>::infinity()))", f527, 2, 512},
  {"512:_mm512_max_pd(_mm512_max_pd(x, _mm512_set1_pd(std::numeric_limits<double>::infinity())), _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN()))", f528, 2, 512},
  {"512:_mm512_max_pd(_mm512_max_pd(x, _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN())), _mm512_setzero_pd())", f529, 2, 512},
  {"512:_mm512_max_pd(_mm512_max_pd(x, _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN())), _mm512_set1_pd(-0.0))", f530, 2, 512},
  {"512:_mm512_max_pd(_mm512_max_pd(x, _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN())), _mm512_set1_pd(1.0))", f531, 2, 512},
  {"512:_mm512_max_pd(_mm512_max_pd(x, _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN())), _mm512_set1_pd(-1.0))", f532, 2, 512},
  {"512:_mm512_max_pd(_mm512_max_pd(x, _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN())), _mm512_set1_pd(std::numeric_limits<double>::infinity()))", f533, 2, 512},
  {"512:_mm512_max_pd(_mm512_max_pd(x, _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN())), _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN()))", f534, 2, 512},
  {"512:_mm512_and_pd(x, x)", f535, 2, 512},
  {"512:_mm512_and_pd(x, _mm512_setzero_pd())", f536, 2, 512},
  {"512:_mm512_and_pd(_mm512_setzero_pd(), x)", f537, 2, 512},
  {"512:_mm512_and_pd(x, _mm512_set1_pd(-0.0))", f538, 2, 512},
  {"512:_mm512_and_pd(_mm512_set1_pd(-0.0), x)", f539, 2, 512},
  {"512:_mm512_and_pd(x, _mm512_set1_pd(1.0))", f540, 2, 512},
  {"512:_mm512_and_pd(_mm512_set1_pd(1.0), x)", f541, 2, 512},
  {"512:_mm512_and_pd(x, _mm512_set1_pd(-1.0))", f542, 2, 512},
  {"512:_mm512_and_pd(_mm512_set1_pd(-1.0), x)", f543, 2, 512},
  {"512:_mm512_and_pd(x, _mm512_set1_pd(std::numeric_limits<double>::infinity()))", f544, 2, 512},
  {"512:_mm512_and_pd(_mm512_set1_pd(std::numeric_limits<double>::infinity()), x)", f545, 2, 512},
  {"512:_mm512_and_pd(x, _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN()))", f546, 2, 512},
  {"512:_mm512_and_pd(_mm512_set1_pd(std::numeric_limits<double>::quiet_NaN()), x)", f547, 2, 512},
  {"512:_mm512_and_pd(_mm512_and_pd(x, _mm512_setzero_pd()), _mm512_setzero_pd())", f548, 2, 512},
  {"512:_mm512_and_pd(_mm512_and_pd(x, _mm512_setzero_pd()), _mm512_set1_pd(-0.0))", f549, 2, 512},
  {"512:_mm512_and_pd(_mm512_and_pd(x, _mm512_setzero_pd()), _mm512_set1_pd(1.0))", f550, 2, 512},
  {"512:_mm512_and_pd(_mm512_and_pd(x, _mm512_setzero_pd()), _mm512_set1_pd(-1.0))", f551, 2, 512},
  {"512:_mm512_and_pd(_mm512_and_pd(x, _mm512_setzero_pd()), _mm512_set1_pd(std::numeric_limits<double>::infinity()))", f552, 2, 512},
  {"512:_mm512_and_pd(_mm512_and_pd(x, _mm512_setzero_pd()), _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN()))", f553, 2, 512},
  {"512:_mm512_and_pd(_mm512_and_pd(x, _mm512_set1_pd(-0.0)), _mm512_setzero_pd())", f554, 2, 512},
  {"512:_mm512_and_pd(_mm512_and_pd(x, _mm512_set1_pd(-0.0)), _mm512_set1_pd(-0.0))", f555, 2, 512},
  {"512:_mm512_and_pd(_mm512_and_pd(x, _mm512_set1_pd(-0.0)), _mm512_set1_pd(1.0))", f556, 2, 512},
  {"512:_mm512_and_pd(_mm512_and_pd(x, _mm512_set1_pd(-0.0)), _mm512_set1_pd(-1.0))", f557, 2, 512},
  {"512:_mm512_and_pd(_mm512_and_pd(x, _mm512_set1_pd(-0.0)), _mm512_set1_pd(std::numeric_limits<double>::infinity()))", f558, 2, 512},
  {"512:_mm512_and_pd(_mm512_and_pd(x, _mm512_set1_pd(-0.0)), _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN()))", f559, 2, 512},
  {"512:_mm512_and_pd(_mm512_and_pd(x, _mm512_set1_pd(1.0)), _mm512_setzero_pd())", f560, 2, 512},
  {"512:_mm512_and_pd(_mm512_and_pd(x, _mm512_set1_pd(1.0)), _mm512_set1_pd(-0.0))", f561, 2, 512},
  {"512:_mm512_and_pd(_mm512_and_pd(x, _mm512_set1_pd(1.0)), _mm512_set1_pd(1.0))", f562, 2, 512},
  {"512:_mm512_and_pd(_mm512_and_pd(x, _mm512_set1_pd(1.0)), _mm512_set1_pd(-1.0))", f563, 2, 512},
  {"512:_mm512_and_pd(_mm512_and_pd(x, _mm512_set1_pd(1.0)), _mm512_set1_pd(std::numeric_limits<double>::infinity()))", f564, 2, 512},
  {"512:_mm512_and_pd(_mm512_and_pd(x, _mm512_set1_pd(1.0)), _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN()))", f565, 2, 512},
  {"512:_mm512_and_pd(_mm512_and_pd(x, _mm512_set1_pd(-1.0)), _mm512_setzero_pd())", f566, 2, 512},
  {"512:_mm512_and_pd(_mm512_and_pd(x, _mm512_set1_pd(-1.0)), _mm512_set1_pd(-0.0))", f567, 2, 512},
  {"512:_mm512_and_pd(_mm512_and_pd(x, _mm512_set1_pd(-1.0)), _mm512_set1_pd(1.0))", f568, 2, 512},
  {"512:_mm512_and_pd(_mm512_and_pd(x, _mm512_set1_pd(-1.0)), _mm512_set1_pd(-1.0))", f569, 2, 512},
  {"512:_mm512_and_pd(_mm512_and_pd(x, _mm512_set1_pd(-1.0)), _mm512_set1_pd(std::numeric_limits<double>::infinity()))", f570, 2, 512},
  {"512:_mm512_and_pd(_mm512_and_pd(x, _mm512_set1_pd(-1.0)), _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN()))", f571, 2, 512},
  {"512:_mm512_and_pd(_mm512_and_pd(x, _mm512_set1_pd(std::numeric_limits<double>::infinity())), _mm512_setzero_pd())", f572, 2, 512},
  {"512:_mm512_and_pd(_mm512_and_pd(x, _mm512_set1_pd(std::numeric_limits<double>::infinity())), _mm512_set1_pd(-0.0))", f573, 2, 512},
  {"512:_mm512_and_pd(_mm512_and_pd(x, _mm512_set1_pd(std::numeric_limits<double>::infinity())), _mm512_set1_pd(1.0))", f574, 2, 512},
  {"512:_mm512_and_pd(_mm512_and_pd(x, _mm512_set1_pd(std::numeric_limits<double>::infinity())), _mm512_set1_pd(-1.0))", f575, 2, 512},
  {"512:_mm512_and_pd(_mm512_and_pd(x, _mm512_set1_pd(std::numeric_limits<double>::infinity())), _mm512_set1_pd(std::numeric_limits<double>::infinity()))", f576, 2, 512},
  {"512:_mm512_and_pd(_mm512_and_pd(x, _mm512_set1_pd(std::numeric_limits<double>::infinity())), _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN()))", f577, 2, 512},
  {"512:_mm512_and_pd(_mm512_and_pd(x, _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN())), _mm512_setzero_pd())", f578, 2, 512},
  {"512:_mm512_and_pd(_mm512_and_pd(x, _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN())), _mm512_set1_pd(-0.0))", f579, 2, 512},
  {"512:_mm512_and_pd(_mm512_and_pd(x, _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN())), _mm512_set1_pd(1.0))", f580, 2, 512},
  {"512:_mm512_and_pd(_mm512_and_pd(x, _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN())), _mm512_set1_pd(-1.0))", f581, 2, 512},
  {"512:_mm512_and_pd(_mm512_and_pd(x, _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN())), _mm512_set1_pd(std::numeric_limits<double>::infinity()))", f582, 2, 512},
  {"512:_mm512_and_pd(_mm512_and_pd(x, _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN())), _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN()))", f583, 2, 512},
  {"512:_mm512_or_pd(x, x)", f584, 2, 512},
  {"512:_mm512_or_pd(x, _mm512_setzero_pd())", f585, 2, 512},
  {"512:_mm512_or_pd(_mm512_setzero_pd(), x)", f586, 2, 512},
  {"512:_mm512_or_pd(x, _mm512_set1_pd(-0.0))", f587, 2, 512},
  {"512:_mm512_or_pd(_mm512_set1_pd(-0.0), x)", f588, 2, 512},
  {"512:_mm512_or_pd(x, _mm512_set1_pd(1.0))", f589, 2, 512},
  {"512:_mm512_or_pd(_mm512_set1_pd(1.0), x)", f590, 2, 512},
  {"512:_mm512_or_pd(x, _mm512_set1_pd(-1.0))", f591, 2, 512},
  {"512:_mm512_or_pd(_mm512_set1_pd(-1.0), x)", f592, 2, 512},
  {"512:_mm512_or_pd(x, _mm512_set1_pd(std::numeric_limits<double>::infinity()))", f593, 2, 512},
  {"512:_mm512_or_pd(_mm512_set1_pd(std::numeric_limits<double>::infinity()), x)", f594, 2, 512},
  {"512:_mm512_or_pd(x, _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN()))", f595, 2, 512},
  {"512:_mm512_or_pd(_mm512_set1_pd(std::numeric_limits<double>::quiet_NaN()), x)", f596, 2, 512},
  {"512:_mm512_or_pd(_mm512_or_pd(x, _mm512_setzero_pd()), _mm512_setzero_pd())", f597, 2, 512},
  {"512:_mm512_or_pd(_mm512_or_pd(x, _mm512_setzero_pd()), _mm512_set1_pd(-0.0))", f598, 2, 512},
  {"512:_mm512_or_pd(_mm512_or_pd(x, _mm512_setzero_pd()), _mm512_set1_pd(1.0))", f599, 2, 512},
  {"512:_mm512_or_pd(_mm512_or_pd(x, _mm512_setzero_pd()), _mm512_set1_pd(-1.0))", f600, 2, 512},
  {"512:_mm512_or_pd(_mm512_or_pd(x, _mm512_setzero_pd()), _mm512_set1_pd(std::numeric_limits<double>::infinity()))", f601, 2, 512},
  {"512:_mm512_or_pd(_mm512_or_pd(x, _mm512_setzero_pd()), _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN()))", f602, 2, 512},
  {"512:_mm512_or_pd(_mm512_or_pd(x, _mm512_set1_pd(-0.0)), _mm512_setzero_pd())", f603, 2, 512},
  {"512:_mm512_or_pd(_mm512_or_pd(x, _mm512_set1_pd(-0.0)), _mm512_set1_pd(-0.0))", f604, 2, 512},
  {"512:_mm512_or_pd(_mm512_or_pd(x, _mm512_set1_pd(-0.0)), _mm512_set1_pd(1.0))", f605, 2, 512},
  {"512:_mm512_or_pd(_mm512_or_pd(x, _mm512_set1_pd(-0.0)), _mm512_set1_pd(-1.0))", f606, 2, 512},
  {"512:_mm512_or_pd(_mm512_or_pd(x, _mm512_set1_pd(-0.0)), _mm512_set1_pd(std::numeric_limits<double>::infinity()))", f607, 2, 512},
  {"512:_mm512_or_pd(_mm512_or_pd(x, _mm512_set1_pd(-0.0)), _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN()))", f608, 2, 512},
  {"512:_mm512_or_pd(_mm512_or_pd(x, _mm512_set1_pd(1.0)), _mm512_setzero_pd())", f609, 2, 512},
  {"512:_mm512_or_pd(_mm512_or_pd(x, _mm512_set1_pd(1.0)), _mm512_set1_pd(-0.0))", f610, 2, 512},
  {"512:_mm512_or_pd(_mm512_or_pd(x, _mm512_set1_pd(1.0)), _mm512_set1_pd(1.0))", f611, 2, 512},
  {"512:_mm512_or_pd(_mm512_or_pd(x, _mm512_set1_pd(1.0)), _mm512_set1_pd(-1.0))", f612, 2, 512},
  {"512:_mm512_or_pd(_mm512_or_pd(x, _mm512_set1_pd(1.0)), _mm512_set1_pd(std::numeric_limits<double>::infinity()))", f613, 2, 512},
  {"512:_mm512_or_pd(_mm512_or_pd(x, _mm512_set1_pd(1.0)), _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN()))", f614, 2, 512},
  {"512:_mm512_or_pd(_mm512_or_pd(x, _mm512_set1_pd(-1.0)), _mm512_setzero_pd())", f615, 2, 512},
  {"512:_mm512_or_pd(_mm512_or_pd(x, _mm512_set1_pd(-1.0)), _mm512_set1_pd(-0.0))", f616, 2, 512},
  {"512:_mm512_or_pd(_mm512_or_pd(x, _mm512_set1_pd(-1.0)), _mm512_set1_pd(1.0))", f617, 2, 512},
  {"512:_mm512_or_pd(_mm512_or_pd(x, _mm512_set1_pd(-1.0)), _mm512_set1_pd(-1.0))", f618, 2, 512},
  {"512:_mm512_or_pd(_mm512_or_pd(x, _mm512_set1_pd(-1.0)), _mm512_set1_pd(std::numeric_limits<double>::infinity()))", f619, 2, 512},
  {"512:_mm512_or_pd(_mm512_or_pd(x, _mm512_set1_pd(-1.0)), _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN()))", f620, 2, 512},
  {"512:_mm512_or_pd(_mm512_or_pd(x, _mm512_set1_pd(std::numeric_limits<double>::infinity())), _mm512_setzero_pd())", f621, 2, 512},
  {"512:_mm512_or_pd(_mm512_or_pd(x, _mm512_set1_pd(std::numeric_limits<double>::infinity())), _mm512_set1_pd(-0.0))", f622, 2, 512},
  {"512:_mm512_or_pd(_mm512_or_pd(x, _mm512_set1_pd(std::numeric_limits<double>::infinity())), _mm512_set1_pd(1.0))", f623, 2, 512},
  {"512:_mm512_or_pd(_mm512_or_pd(x, _mm512_set1_pd(std::numeric_limits<double>::infinity())), _mm512_set1_pd(-1.0))", f624, 2, 512},
  {"512:_mm512_or_pd(_mm512_or_pd(x, _mm512_set1_pd(std::numeric_limits<double>::infinity())), _mm512_set1_pd(std::numeric_limits<double>::infinity()))", f625, 2, 512},
  {"512:_mm512_or_pd(_mm512_or_pd(x, _mm512_set1_pd(std::numeric_limits<double>::infinity())), _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN()))", f626, 2, 512},
  {"512:_mm512_or_pd(_mm512_or_pd(x, _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN())), _mm512_setzero_pd())", f627, 2, 512},
  {"512:_mm512_or_pd(_mm512_or_pd(x, _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN())), _mm512_set1_pd(-0.0))", f628, 2, 512},
  {"512:_mm512_or_pd(_mm512_or_pd(x, _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN())), _mm512_set1_pd(1.0))", f629, 2, 512},
  {"512:_mm512_or_pd(_mm512_or_pd(x, _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN())), _mm512_set1_pd(-1.0))", f630, 2, 512},
  {"512:_mm512_or_pd(_mm512_or_pd(x, _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN())), _mm512_set1_pd(std::numeric_limits<double>::infinity()))", f631, 2, 512},
  {"512:_mm512_or_pd(_mm512_or_pd(x, _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN())), _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN()))", f632, 2, 512},
  {"512:_mm512_xor_pd(x, x)", f633, 2, 512},
  {"512:_mm512_xor_pd(x, _mm512_setzero_pd())", f634, 2, 512},
  {"512:_mm512_xor_pd(_mm512_setzero_pd(), x)", f635, 2, 512},
  {"512:_mm512_xor_pd(x, _mm512_set1_pd(-0.0))", f636, 2, 512},
  {"512:_mm512_xor_pd(_mm512_set1_pd(-0.0), x)", f637, 2, 512},
  {"512:_mm512_xor_pd(x, _mm512_set1_pd(1.0))", f638, 2, 512},
  {"512:_mm512_xor_pd(_mm512_set1_pd(1.0), x)", f639, 2, 512},
  {"512:_mm512_xor_pd(x, _mm512_set1_pd(-1.0))", f640, 2, 512},
  {"512:_mm512_xor_pd(_mm512_set1_pd(-1.0), x)", f641, 2, 512},
  {"512:_mm512_xor_pd(x, _mm512_set1_pd(std::numeric_limits<double>::infinity()))", f642, 2, 512},
  {"512:_mm512_xor_pd(_mm512_set1_pd(std::numeric_limits<double>::infinity()), x)", f643, 2, 512},
  {"512:_mm512_xor_pd(x, _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN()))", f644, 2, 512},
  {"512:_mm512_xor_pd(_mm512_set1_pd(std::numeric_limits<double>::quiet_NaN()), x)", f645, 2, 512},
  {"512:_mm512_xor_pd(_mm512_xor_pd(x, _mm512_setzero_pd()), _mm512_setzero_pd())", f646, 2, 512},
  {"512:_mm512_xor_pd(_mm512_xor_pd(x, _mm512_setzero_pd()), _mm512_set1_pd(-0.0))", f647, 2, 512},
  {"512:_mm512_xor_pd(_mm512_xor_pd(x, _mm512_setzero_pd()), _mm512_set1_pd(1.0))", f648, 2, 512},
  {"512:_mm512_xor_pd(_mm512_xor_pd(x, _mm512_setzero_pd()), _mm512_set1_pd(-1.0))", f649, 2, 512},
  {"512:_mm512_xor_pd(_mm512_xor_pd(x, _mm512_setzero_pd()), _mm512_set1_pd(std::numeric_limits<double>::infinity()))", f650, 2, 512},
  {"512:_mm512_xor_pd(_mm512_xor_pd(x, _mm512_setzero_pd()), _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN()))", f651, 2, 512},
  {"512:_mm512_xor_pd(_mm512_xor_pd(x, _mm512_set1_pd(-0.0)), _mm512_setzero_pd())", f652, 2, 512},
  {"512:_mm512_xor_pd(_mm512_xor_pd(x, _mm512_set1_pd(-0.0)), _mm512_set1_pd(1.0))", f653, 2, 512},
  {"512:_mm512_xor_pd(_mm512_xor_pd(x, _mm512_set1_pd(-0.0)), _mm512_set1_pd(-1.0))", f654, 2, 512},
  {"512:_mm512_xor_pd(_mm512_xor_pd(x, _mm512_set1_pd(-0.0)), _mm512_set1_pd(std::numeric_limits<double>::infinity()))", f655, 2, 512},
  {"512:_mm512_xor_pd(_mm512_xor_pd(x, _mm512_set1_pd(-0.0)), _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN()))", f656, 2, 512},
  {"512:_mm512_xor_pd(_mm512_xor_pd(x, _mm512_set1_pd(1.0)), _mm512_setzero_pd())", f657, 2, 512},
  {"512:_mm512_xor_pd(_mm512_xor_pd(x, _mm512_set1_pd(1.0)), _mm512_set1_pd(-0.0))", f658, 2, 512},
  {"512:_mm512_xor_pd(_mm512_xor_pd(x, _mm512_set1_pd(1.0)), _mm512_set1_pd(1.0))", f659, 2, 512},
  {"512:_mm512_xor_pd(_mm512_xor_pd(x, _mm512_set1_pd(1.0)), _mm512_set1_pd(-1.0))", f660, 2, 512},
  {"512:_mm512_xor_pd(_mm512_xor_pd(x, _mm512_set1_pd(1.0)), _mm512_set1_pd(std::numeric_limits<double>::infinity()))", f661, 2, 512},
  {"512:_mm512_xor_pd(_mm512_xor_pd(x, _mm512_set1_pd(1.0)), _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN()))", f662, 2, 512},
  {"512:_mm512_xor_pd(_mm512_xor_pd(x, _mm512_set1_pd(-1.0)), _mm512_setzero_pd())", f663, 2, 512},
  {"512:_mm512_xor_pd(_mm512_xor_pd(x, _mm512_set1_pd(-1.0)), _mm512_set1_pd(-0.0))", f664, 2, 512},
  {"512:_mm512_xor_pd(_mm512_xor_pd(x, _mm512_set1_pd(-1.0)), _mm512_set1_pd(1.0))", f665, 2, 512},
  {"512:_mm512_xor_pd(_mm512_xor_pd(x, _mm512_set1_pd(-1.0)), _mm512_set1_pd(-1.0))", f666, 2, 512},
  {"512:_mm512_xor_pd(_mm512_xor_pd(x, _mm512_set1_pd(-1.0)), _mm512_set1_pd(std::numeric_limits<double>::infinity()))", f667, 2, 512},
  {"512:_mm512_xor_pd(_mm512_xor_pd(x, _mm512_set1_pd(-1.0)), _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN()))", f668, 2, 512},
  {"512:_mm512_xor_pd(_mm512_xor_pd(x, _mm512_set1_pd(std::numeric_limits<double>::infinity())), _mm512_setzero_pd())", f669, 2, 512},
  {"512:_mm512_xor_pd(_mm512_xor_pd(x, _mm512_set1_pd(std::numeric_limits<double>::infinity())), _mm512_set1_pd(-0.0))", f670, 2, 512},
  {"512:_mm512_xor_pd(_mm512_xor_pd(x, _mm512_set1_pd(std::numeric_limits<double>::infinity())), _mm512_set1_pd(1.0))", f671, 2, 512},
  {"512:_mm512_xor_pd(_mm512_xor_pd(x, _mm512_set1_pd(std::numeric_limits<double>::infinity())), _mm512_set1_pd(-1.0))", f672, 2, 512},
  {"512:_mm512_xor_pd(_mm512_xor_pd(x, _mm512_set1_pd(std::numeric_limits<double>::infinity())), _mm512_set1_pd(std::numeric_limits<double>::infinity()))", f673, 2, 512},
  {"512:_mm512_xor_pd(_mm512_xor_pd(x, _mm512_set1_pd(std::numeric_limits<double>::infinity())), _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN()))", f674, 2, 512},
  {"512:_mm512_xor_pd(_mm512_xor_pd(x, _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN())), _mm512_setzero_pd())", f675, 2, 512},
  {"512:_mm512_xor_pd(_mm512_xor_pd(x, _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN())), _mm512_set1_pd(-0.0))", f676, 2, 512},
  {"512:_mm512_xor_pd(_mm512_xor_pd(x, _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN())), _mm512_set1_pd(1.0))", f677, 2, 512},
  {"512:_mm512_xor_pd(_mm512_xor_pd(x, _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN())), _mm512_set1_pd(-1.0))", f678, 2, 512},
  {"512:_mm512_xor_pd(_mm512_xor_pd(x, _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN())), _mm512_set1_pd(std::numeric_limits<double>::infinity()))", f679, 2, 512},
  {"512:_mm512_xor_pd(_mm512_xor_pd(x, _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN())), _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN()))", f680, 2, 512},
  {"512:_mm512_andnot_pd(x, x)", f681, 2, 512},
  {"512:_mm512_andnot_pd(x, _mm512_setzero_pd())", f682, 2, 512},
  {"512:_mm512_andnot_pd(_mm512_setzero_pd(), x)", f683, 2, 512},
  {"512:_mm512_andnot_pd(x, _mm512_set1_pd(-0.0))", f684, 2, 512},
  {"512:_mm512_andnot_pd(_mm512_set1_pd(-0.0), x)", f685, 2, 512},
  {"512:_mm512_andnot_pd(x, _mm512_set1_pd(1.0))", f686, 2, 512},
  {"512:_mm512_andnot_pd(_mm512_set1_pd(1.0), x)", f687, 2, 512},
  {"512:_mm512_andnot_pd(x, _mm512_set1_pd(-1.0))", f688, 2, 512},
  {"512:_mm512_andnot_pd(_mm512_set1_pd(-1.0), x)", f689, 2, 512},
  {"512:_mm512_andnot_pd(x, _mm512_set1_pd(std::numeric_limits<double>::infinity()))", f690, 2, 512},
  {"512:_mm512_andnot_pd(_mm512_set1_pd(std::numeric_limits<double>::infinity()), x)", f691, 2, 512},
  {"512:_mm512_andnot_pd(x, _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN()))", f692, 2, 512},
  {"512:_mm512_andnot_pd(_mm512_set1_pd(std::numeric_limits<double>::quiet_NaN()), x)", f693, 2, 512},
  {"512:_mm512_andnot_pd(_mm512_andnot_pd(x, _mm512_setzero_pd()), _mm512_setzero_pd())", f694, 2, 512},
  {"512:_mm512_andnot_pd(_mm512_andnot_pd(x, _mm512_setzero_pd()), _mm512_set1_pd(-0.0))", f695, 2, 512},
  {"512:_mm512_andnot_pd(_mm512_andnot_pd(x, _mm512_setzero_pd()), _mm512_set1_pd(1.0))", f696, 2, 512},
  {"512:_mm512_andnot_pd(_mm512_andnot_pd(x, _mm512_setzero_pd()), _mm512_set1_pd(-1.0))", f697, 2, 512},
  {"512:_mm512_andnot_pd(_mm512_andnot_pd(x, _mm512_setzero_pd()), _mm512_set1_pd(std::numeric_limits<double>::infinity()))", f698, 2, 512},
  {"512:_mm512_andnot_pd(_mm512_andnot_pd(x, _mm512_setzero_pd()), _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN()))", f699, 2, 512},
  {"512:_mm512_andnot_pd(_mm512_andnot_pd(x, _mm512_set1_pd(-0.0)), _mm512_setzero_pd())", f700, 2, 512},
  {"512:_mm512_andnot_pd(_mm512_andnot_pd(x, _mm512_set1_pd(-0.0)), _mm512_set1_pd(-0.0))", f701, 2, 512},
  {"512:_mm512_andnot_pd(_mm512_andnot_pd(x, _mm512_set1_pd(-0.0)), _mm512_set1_pd(1.0))", f702, 2, 512},
  {"512:_mm512_andnot_pd(_mm512_andnot_pd(x, _mm512_set1_pd(-0.0)), _mm512_set1_pd(-1.0))", f703, 2, 512},
  {"512:_mm512_andnot_pd(_mm512_andnot_pd(x, _mm512_set1_pd(-0.0)), _mm512_set1_pd(std::numeric_limits<double>::infinity()))", f704, 2, 512},
  {"512:_mm512_andnot_pd(_mm512_andnot_pd(x, _mm512_set1_pd(-0.0)), _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN()))", f705, 2, 512},
  {"512:_mm512_andnot_pd(_mm512_andnot_pd(x, _mm512_set1_pd(1.0)), _mm512_setzero_pd())", f706, 2, 512},
  {"512:_mm512_andnot_pd(_mm512_andnot_pd(x, _mm512_set1_pd(1.0)), _mm512_set1_pd(-0.0))", f707, 2, 512},
  {"512:_mm512_andnot_pd(_mm512_andnot_pd(x, _mm512_set1_pd(1.0)), _mm512_set1_pd(1.0))", f708, 2, 512},
  {"512:_mm512_andnot_pd(_mm512_andnot_pd(x, _mm512_set1_pd(1.0)), _mm512_set1_pd(-1.0))", f709, 2, 512},
  {"512:_mm512_andnot_pd(_mm512_andnot_pd(x, _mm512_set1_pd(1.0)), _mm512_set1_pd(std::numeric_limits<double>::infinity()))", f710, 2, 512},
  {"512:_mm512_andnot_pd(_mm512_andnot_pd(x, _mm512_set1_pd(1.0)), _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN()))", f711, 2, 512},
  {"512:_mm512_andnot_pd(_mm512_andnot_pd(x, _mm512_set1_pd(-1.0)), _mm512_setzero_pd())", f712, 2, 512},
  {"512:_mm512_andnot_pd(_mm512_andnot_pd(x, _mm512_set1_pd(-1.0)), _mm512_set1_pd(-0.0))", f713, 2, 512},
  {"512:_mm512_andnot_pd(_mm512_andnot_pd(x, _mm512_set1_pd(-1.0)), _mm512_set1_pd(1.0))", f714, 2, 512},
  {"512:_mm512_andnot_pd(_mm512_andnot_pd(x, _mm512_set1_pd(-1.0)), _mm512_set1_pd(-1.0))", f715, 2, 512},
  {"512:_mm512_andnot_pd(_mm512_andnot_pd(x, _mm512_set1_pd(-1.0)), _mm512_set1_pd(std::numeric_limits<double>::infinity()))", f716, 2, 512},
  {"512:_mm512_andnot_pd(_mm512_andnot_pd(x, _mm512_set1_pd(-1.0)), _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN()))", f717, 2, 512},
  {"512:_mm512_andnot_pd(_mm512_andnot_pd(x, _mm512_set1_pd(std::numeric_limits<double>::infinity())), _mm512_setzero_pd())", f718, 2, 512},
  {"512:_mm512_andnot_pd(_mm512_andnot_pd(x, _mm512_set1_pd(std::numeric_limits<double>::infinity())), _mm512_set1_pd(-0.0))", f719, 2, 512},
  {"512:_mm512_andnot_pd(_mm512_andnot_pd(x, _mm512_set1_pd(std::numeric_limits<double>::infinity())), _mm512_set1_pd(1.0))", f720, 2, 512},
  {"512:_mm512_andnot_pd(_mm512_andnot_pd(x, _mm512_set1_pd(std::numeric_limits<double>::infinity())), _mm512_set1_pd(-1.0))", f721, 2, 512},
  {"512:_mm512_andnot_pd(_mm512_andnot_pd(x, _mm512_set1_pd(std::numeric_limits<double>::infinity())), _mm512_set1_pd(std::numeric_limits<double>::infinity()))", f722, 2, 512},
  {"512:_mm512_andnot_pd(_mm512_andnot_pd(x, _mm512_set1_pd(std::numeric_limits<double>::infinity())), _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN()))", f723, 2, 512},
  {"512:_mm512_andnot_pd(_mm512_andnot_pd(x, _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN())), _mm512_setzero_pd())", f724, 2, 512},
  {"512:_mm512_andnot_pd(_mm512_andnot_pd(x, _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN())), _mm512_set1_pd(-0.0))", f725, 2, 512},
  {"512:_mm512_andnot_pd(_mm512_andnot_pd(x, _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN())), _mm512_set1_pd(1.0))", f726, 2, 512},
  {"512:_mm512_andnot_pd(_mm512_andnot_pd(x, _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN())), _mm512_set1_pd(-1.0))", f727, 2, 512},
  {"512:_mm512_andnot_pd(_mm512_andnot_pd(x, _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN())), _mm512_set1_pd(std::numeric_limits<double>::infinity()))", f728, 2, 512},
  {"512:_mm512_andnot_pd(_mm512_andnot_pd(x, _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN())), _mm512_set1_pd(std::numeric_limits<double>::quiet_NaN()))", f729, 2, 512},
  {"512:_mm512_add_pd(_mm512_add_pd(x, y), y)", f730, 2, 512},
  {"512:_mm512_add_pd(x, _mm512_add_pd(x, y))", f731, 2, 512},
  {"512:_mm512_add_pd(_mm512_add_pd(x, y), x)", f732, 2, 512},
  {"512:_mm512_add_pd(y, _mm512_add_pd(x, y))", f733, 2, 512},
  {"512:_mm512_add_pd(_mm512_sub_pd(x, y), y)", f734, 2, 512},
  {"512:_mm512_add_pd(x, _mm512_sub_pd(x, y))", f735, 2, 512},
  {"512:_mm512_add_pd(_mm512_sub_pd(x, y), x)", f736, 2, 512},
  {"512:_mm512_add_pd(y, _mm512_sub_pd(x, y))", f737, 2, 512},
  {"512:_mm512_add_pd(_mm512_mul_pd(x, y), y)", f738, 2, 512},
  {"512:_mm512_add_pd(x, _mm512_mul_pd(x, y))", f739, 2, 512},
  {"512:_mm512_add_pd(_mm512_mul_pd(x, y), x)", f740, 2, 512},
  {"512:_mm512_add_pd(y, _mm512_mul_pd(x, y))", f741, 2, 512},
  {"512:_mm512_add_pd(_mm512_div_pd(x, y), y)", f742, 2, 512},
  {"512:_mm512_add_pd(x, _mm512_div_pd(x, y))", f743, 2, 512},
  {"512:_mm512_add_pd(_mm512_div_pd(x, y), x)", f744, 2, 512},
  {"512:_mm512_add_pd(y, _mm512_div_pd(x, y))", f745, 2, 512},
  {"512:_mm512_add_pd(_mm512_min_pd(x, y), y)", f746, 2, 512},
  {"512:_mm512_add_pd(x, _mm512_min_pd(x, y))", f747, 2, 512},
  {"512:_mm512_add_pd(_mm512_min_pd(x, y), x)", f748, 2, 512},
  {"512:_mm512_add_pd(y, _mm512_min_pd(x, y))", f749, 2, 512},
  {"512:_mm512_add_pd(_mm512_max_pd(x, y), y)", f750, 2, 512},
  {"512:_mm512_add_pd(x, _mm512_max_pd(x, y))", f751, 2, 512},
  {"512:_mm512_add_pd(_mm512_max_pd(x, y), x)", f752, 2, 512},
  {"512:_mm512_add_pd(y, _mm512_max_pd(x, y))", f753, 2, 512},
  {"512:_mm512_add_pd(_mm512_and_pd(x, y), y)", f754, 2, 512},
  {"512:_mm512_add_pd(x, _mm512_and_pd(x, y))", f755, 2, 512},
  {"512:_mm512_add_pd(_mm512_and_pd(x, y), x)", f756, 2, 512},
  {"512:_mm512_add_pd(y, _mm512_and_pd(x, y))", f757, 2, 512},
  {"512:_mm512_add_pd(_mm512_or_pd(x, y), y)", f758, 2, 512},
  {"512:_mm512_add_pd(x, _mm512_or_pd(x, y))", f759, 2, 512},
  {"512:_mm512_add_pd(_mm512_or_pd(x, y), x)", f760, 2, 512},
  {"512:_mm512_add_pd(y, _mm512_or_pd(x, y))", f761, 2, 512},
  {"512:_mm512_add_pd(_mm512_xor_pd(x, y), y)", f762, 2, 512},
  {"512:_mm512_add_pd(x, _mm512_xor_pd(x, y))", f763, 2, 512},
  {"512:_mm512_add_pd(_mm512_xor_pd(x, y), x)", f764, 2, 512},
  {"512:_mm512_add_pd(y, _mm512_xor_pd(x, y))", f765, 2, 512},
  {"512:_mm512_add_pd(_mm512_andnot_pd(x, y), y)", f766, 2, 512},
  {"512:_mm512_add_pd(x, _mm512_andnot_pd(x, y))", f767, 2, 512},
  {"512:_mm512_add_pd(_mm512_andnot_pd(x, y), x)", f768, 2, 512},
  {"512:_mm512_add_pd(y, _mm512_andnot_pd(x, y))", f769, 2, 512},
  {"512:_mm512_sub_pd(_mm512_add_pd(x, y), y)", f770, 2, 512},
  {"512:_mm512_sub_pd(x, _mm512_add_pd(x, y))", f771, 2, 512},
  {"512:_mm512_sub_pd(_mm512_add_pd(x, y), x)", f772, 2, 512},
  {"512:_mm512_sub_pd(y, _mm512_add_pd(x, y))", f773, 2, 512},
  {"512:_mm512_sub_pd(_mm512_sub_pd(x, y), y)", f774, 2, 512},
  {"512:_mm512_sub_pd(x, _mm512_sub_pd(x, y))", f775, 2, 512},
  {"512:_mm512_sub_pd(_mm512_sub_pd(x, y), x)", f776, 2, 512},
  {"512:_mm512_sub_pd(y, _mm512_sub_pd(x, y))", f777, 2, 512},
  {"512:_mm512_sub_pd(_mm512_mul_pd(x, y), y)", f778, 2, 512},
  {"512:_mm512_sub_pd(x, _mm512_mul_pd(x, y))", f779, 2, 512},
  {"512:_mm512_sub_pd(_mm512_mul_pd(x, y), x)", f780, 2, 512},
  {"512:_mm512_sub_pd(y, _mm512_mul_pd(x, y))", f781, 2, 512},
  {"512:_mm512_sub_pd(_mm512_div_pd(x, y), y)", f782, 2, 512},
  {"512:_mm512_sub_pd(x, _mm512_div_pd(x, y))", f783, 2, 512},
  {"512:_mm512_sub_pd(_mm512_div_pd(x, y), x)", f784, 2, 512},
  {"512:_mm512_sub_pd(y, _mm512_div_pd(x, y))", f785, 2, 512},
  {"512:_mm512_sub_pd(_mm512_min_pd(x, y), y)", f786, 2, 512},
  {"512:_mm512_sub_pd(x, _mm512_min_pd(x, y))", f787, 2, 512},
  {"512:_mm512_sub_pd(_mm512_min_pd(x, y), x)", f788, 2, 512},
  {"512:_mm512_sub_pd(y, _mm512_min_pd(x, y))", f789, 2, 512},
  {"512:_mm512_sub_pd(_mm512_max_pd(x, y), y)", f790, 2, 512},
  {"512:_mm512_sub_pd(x, _mm512_max_pd(x, y))", f791, 2, 512},
  {"512:_mm512_sub_pd(_mm512_max_pd(x, y), x)", f792, 2, 512},
  {"512:_mm512_sub_pd(y, _mm512_max_pd(x, y))", f793, 2, 512},
  {"512:_mm512_sub_pd(_mm512_and_pd(x, y), y)", f794, 2, 512},
  {"512:_mm512_sub_pd(x, _mm512_and_pd(x, y))", f795, 2, 512},
  {"512:_mm512_sub_pd(_mm512_and_pd(x, y), x)", f796, 2, 512},
  {"512:_mm512_sub_pd(y, _mm512_and_pd(x, y))", f797, 2, 512},
  {"512:_mm512_sub_pd(_mm512_or_pd(x, y), y)", f798, 2, 512},
  {"512:_mm512_sub_pd(x, _mm512_or_pd(x, y))", f799, 2, 512},
  {"512:_mm512_sub_pd(_mm512_or_pd(x, y), x)", f800, 2, 512},
  {"512:_mm512_sub_pd(y, _mm512_or_pd(x, y))", f801, 2, 512},
  {"512:_mm512_sub_pd(_mm512_xor_pd(x, y), y)", f802, 2, 512},
  {"512:_mm512_sub_pd(x, _mm512_xor_pd(x, y))", f803, 2, 512},
  {"512:_mm512_sub_pd(_mm512_xor_pd(x, y), x)", f804, 2, 512},
  {"512:_mm512_sub_pd(y, _mm512_xor_pd(x, y))", f805, 2, 512},
  {"512:_mm512_sub_pd(_mm512_andnot_pd(x, y), y)", f806, 2, 512},
  {"512:_mm512_sub_pd(x, _mm512_andnot_pd(x, y))", f807, 2, 512},
  {"512:_mm512_sub_pd(_mm512_andnot_pd(x, y), x)", f808, 2, 512},
  {"512:_mm512_sub_pd(y, _mm512_andnot_pd(x, y))", f809, 2, 512},
  {"512:_mm512_mul_pd(_mm512_add_pd(x, y), y)", f810, 2, 512},
  {"512:_mm512_mul_pd(x, _mm512_add_pd(x, y))", f811, 2, 512},
  {"512:_mm512_mul_pd(_mm512_add_pd(x, y), x)", f812, 2, 512},
  {"512:_mm512_mul_pd(y, _mm512_add_pd(x, y))", f813, 2, 512},
  {"512:_mm512_mul_pd(_mm512_sub_pd(x, y), y)", f814, 2, 512},
  {"512:_mm512_mul_pd(x, _mm512_sub_pd(x, y))", f815, 2, 512},
  {"512:_mm512_mul_pd(_mm512_sub_pd(x, y), x)", f816, 2, 512},
  {"512:_mm512_mul_pd(y, _mm512_sub_pd(x, y))", f817, 2, 512},
  {"512:_mm512_mul_pd(_mm512_mul_pd(x, y), y)", f818, 2, 512},
  {"512:_mm512_mul_pd(x, _mm512_mul_pd(x, y))", f819, 2, 512},
  {"512:_mm512_mul_pd(_mm512_mul_pd(x, y), x)", f820, 2, 512},
  {"512:_mm512_mul_pd(y, _mm512_mul_pd(x, y))", f821, 2, 512},
  {"512:_mm512_mul_pd(_mm512_div_pd(x, y), y)", f822, 2, 512},
  {"512:_mm512_mul_pd(x, _mm512_div_pd(x, y))", f823, 2, 512},
  {"512:_mm512_mul_pd(_mm512_div_pd(x, y), x)", f824, 2, 512},
  {"512:_mm512_mul_pd(y, _mm512_div_pd(x, y))", f825, 2, 512},
  {"512:_mm512_mul_pd(_mm512_min_pd(x, y), y)", f826, 2, 512},
  {"512:_mm512_mul_pd(x, _mm512_min_pd(x, y))", f827, 2, 512},
  {"512:_mm512_mul_pd(_mm512_min_pd(x, y), x)", f828, 2, 512},
  {"512:_mm512_mul_pd(y, _mm512_min_pd(x, y))", f829, 2, 512},
  {"512:_mm512_mul_pd(_mm512_max_pd(x, y), y)", f830, 2, 512},
  {"512:_mm512_mul_pd(x, _mm512_max_pd(x, y))", f831, 2, 512},
  {"512:_mm512_mul_pd(_mm512_max_pd(x, y), x)", f832, 2, 512},
  {"512:_mm512_mul_pd(y, _mm512_max_pd(x, y))", f833, 2, 512},
  {"512:_mm512_mul_pd(_mm512_and_pd(x, y), y)", f834, 2, 512},
  {"512:_mm512_mul_pd(x, _mm512_and_pd(x, y))", f835, 2, 512},
  {"512:_mm512_mul_pd(_mm512_and_pd(x, y), x)", f836, 2, 512},
  {"512:_mm512_mul_pd(y, _mm512_and_pd(x, y))", f837, 2, 512},
  {"512:_mm512_mul_pd(_mm512_or_pd(x, y), y)", f838, 2, 512},
  {"512:_mm512_mul_pd(x, _mm512_or_pd(x, y))", f839, 2, 512},
  {"512:_mm512_mul_pd(_mm512_or_pd(x, y), x)", f840, 2, 512},
  {"512:_mm512_mul_pd(y, _mm512_or_pd(x, y))", f841, 2, 512},
  {"512:_mm512_mul_pd(_mm512_xor_pd(x, y), y)", f842, 2, 512},
  {"512:_mm512_mul_pd(x, _mm512_xor_pd(x, y))", f843, 2, 512},
  {"512:_mm512_mul_pd(_mm512_xor_pd(x, y), x)", f844, 2, 512},
  {"512:_mm512_mul_pd(y, _mm512_xor_pd(x, y))", f845, 2, 512},
  {"512:_mm512_mul_pd(_mm512_andnot_pd(x, y), y)", f846, 2, 512},
  {"512:_mm512_mul_pd(x, _mm512_andnot_pd(x, y))", f847, 2, 512},
  {"512:_mm512_mul_pd(_mm512_andnot_pd(x, y), x)", f848, 2, 512},
  {"512:_mm512_mul_pd(y, _mm512_andnot_pd(x, y))", f849, 2, 512},
  {"512:_mm512_div_pd(_mm512_add_pd(x, y), y)", f850, 2, 512},
  {"512:_mm512_div_pd(x, _mm512_add_pd(x, y))", f851, 2, 512},
  {"512:_mm512_div_pd(_mm512_add_pd(x, y), x)", f852, 2, 512},
  {"512:_mm512_div_pd(y, _mm512_add_pd(x, y))", f853, 2, 512},
  {"512:_mm512_div_pd(_mm512_sub_pd(x, y), y)", f854, 2, 512},
  {"512:_mm512_div_pd(x, _mm512_sub_pd(x, y))", f855, 2, 512},
  {"512:_mm512_div_pd(_mm512_sub_pd(x, y), x)", f856, 2, 512},
  {"512:_mm512_div_pd(y, _mm512_sub_pd(x, y))", f857, 2, 512},
  {"512:_mm512_div_pd(_mm512_mul_pd(x, y), y)", f858, 2, 512},
  {"512:_mm512_div_pd(x, _mm512_mul_pd(x, y))", f859, 2, 512},
  {"512:_mm512_div_pd(_mm512_mul_pd(x, y), x)", f860, 2, 512},
  {"512:_mm512_div_pd(y, _mm512_mul_pd(x, y))", f861, 2, 512},
  {"512:_mm512_div_pd(_mm512_div_pd(x, y), y)", f862, 2, 512},
  {"512:_mm512_div_pd(x, _mm512_div_pd(x, y))", f863, 2, 512},
  {"512:_mm512_div_pd(_mm512_div_pd(x, y), x)", f864, 2, 512},
  {"512:_mm512_div_pd(y, _mm512_div_pd(x, y))", f865, 2, 512},
  {"512:_mm512_div_pd(_mm512_min_pd(x, y), y)", f866, 2, 512},
  {"512:_mm512_div_pd(x, _mm512_min_pd(x, y))", f867, 2, 512},
  {"512:_mm512_div_pd(_mm512_min_pd(x, y), x)", f868, 2, 512},
  {"512:_mm512_div_pd(y, _mm512_min_pd(x, y))", f869, 2, 512},
  {"512:_mm512_div_pd(_mm512_max_pd(x, y), y)", f870, 2, 512},
  {"512:_mm512_div_pd(x, _mm512_max_pd(x, y))", f871, 2, 512},
  {"512:_mm512_div_pd(_mm512_max_pd(x, y), x)", f872, 2, 512},
  {"512:_mm512_div_pd(y, _mm512_max_pd(x, y))", f873, 2, 512},
  {"512:_mm512_div_pd(_mm512_and_pd(x, y), y)", f874, 2, 512},
  {"512:_mm512_div_pd(x, _mm512_and_pd(x, y))", f875, 2, 512},
  {"512:_mm512_div_pd(_mm512_and_pd(x, y), x)", f876, 2, 512},
  {"512:_mm512_div_pd(y, _mm512_and_pd(x, y))", f877, 2, 512},
  {"512:_mm512_div_pd(_mm512_or_pd(x, y), y)", f878, 2, 512},
  {"512:_mm512_div_pd(x, _mm512_or_pd(x, y))", f879, 2, 512},
  {"512:_mm512_div_pd(_mm512_or_pd(x, y), x)", f880, 2, 512},
  {"512:_mm512_div_pd(y, _mm512_or_pd(x, y))", f881, 2, 512},
  {"512:_mm512_div_pd(_mm512_xor_pd(x, y), y)", f882, 2, 512},
  {"512:_mm512_div_pd(x, _mm512_xor_pd(x, y))", f883, 2, 512},
  {"512:_mm512_div_pd(_mm512_xor_pd(x, y), x)", f884, 2, 512},
  {"512:_mm512_div_pd(y, _mm512_xor_pd(x, y))", f885, 2, 512},
  {"512:_mm512_div_pd(_mm512_andnot_pd(x, y), y)", f886, 2, 512},
  {"512:_mm512_div_pd(x, _mm512_andnot_pd(x, y))", f887, 2, 512},
  {"512:_mm512_div_pd(_mm512_andnot_pd(x, y), x)", f888, 2, 512},
  {"512:_mm512_div_pd(y, _mm512_andnot_pd(x, y))", f889, 2, 512},
  {"512:_mm512_min_pd(_mm512_add_pd(x, y), y)", f890, 2, 512},
  {"512:_mm512_min_pd(x, _mm512_add_pd(x, y))", f891, 2, 512},
  {"512:_mm512_min_pd(_mm512_add_pd(x, y), x)", f892, 2, 512},
  {"512:_mm512_min_pd(y, _mm512_add_pd(x, y))", f893, 2, 512},
  {"512:_mm512_min_pd(_mm512_sub_pd(x, y), y)", f894, 2, 512},
  {"512:_mm512_min_pd(x, _mm512_sub_pd(x, y))", f895, 2, 512},
  {"512:_mm512_min_pd(_mm512_sub_pd(x, y), x)", f896, 2, 512},
  {"512:_mm512_min_pd(y, _mm512_sub_pd(x, y))", f897, 2, 512},
  {"512:_mm512_min_pd(_mm512_mul_pd(x, y), y)", f898, 2, 512},
  {"512:_mm512_min_pd(x, _mm512_mul_pd(x, y))", f899, 2, 512},
  {"512:_mm512_min_pd(_mm512_mul_pd(x, y), x)", f900, 2, 512},
  {"512:_mm512_min_pd(y, _mm512_mul_pd(x, y))", f901, 2, 512},
  {"512:_mm512_min_pd(_mm512_div_pd(x, y), y)", f902, 2, 512},
  {"512:_mm512_min_pd(x, _mm512_div_pd(x, y))", f903, 2, 512},
  {"512:_mm512_min_pd(_mm512_div_pd(x, y), x)", f904, 2, 512},
  {"512:_mm512_min_pd(y, _mm512_div_pd(x, y))", f905, 2, 512},
  {"512:_mm512_min_pd(_mm512_min_pd(x, y), y)", f906, 2, 512},
  {"512:_mm512_min_pd(x, _mm512_min_pd(x, y))", f907, 2, 512},
  {"512:_mm512_min_pd(_mm512_min_pd(x, y), x)", f908, 2, 512},
  {"512:_mm512_min_pd(y, _mm512_min_pd(x, y))", f909, 2, 512},
  {"512:_mm512_min_pd(_mm512_max_pd(x, y), y)", f910, 2, 512},
  {"512:_mm512_min_pd(x, _mm512_max_pd(x, y))", f911, 2, 512},
  {"512:_mm512_min_pd(_mm512_max_pd(x, y), x)", f912, 2, 512},
  {"512:_mm512_min_pd(y, _mm512_max_pd(x, y))", f913, 2, 512},
  {"512:_mm512_min_pd(_mm512_and_pd(x, y), y)", f914, 2, 512},
  {"512:_mm512_min_pd(x, _mm512_and_pd(x, y))", f915, 2, 512},
  {"512:_mm512_min_pd(_mm512_and_pd(x, y), x)", f916, 2, 512},
  {"512:_mm512_min_pd(y, _mm512_and_pd(x, y))", f917, 2, 512},
  {"512:_mm512_min_pd(_mm512_or_pd(x, y), y)", f918, 2, 512},
  {"512:_mm512_min_pd(x, _mm512_or_pd(x, y))", f919, 2, 512},
  {"512:_mm512_min_pd(_mm512_or_pd(x, y), x)", f920, 2, 512},
  {"512:_mm512_min_pd(y, _mm512_or_pd(x, y))", f921, 2, 512},
  {"512:_mm512_min_pd(_mm512_xor_pd(x, y), y)", f922, 2, 512},
  {"512:_mm512_min_pd(x, _mm512_xor_pd(x, y))", f923, 2, 512},
  {"512:_mm512_min_pd(_mm512_xor_pd(x, y), x)", f924, 2, 512},
  {"512:_mm512_min_pd(y, _mm512_xor_pd(x, y))", f925, 2, 512},
  {"512:_mm512_min_pd(_mm512_andnot_pd(x, y), y)", f926, 2, 512},
  {"512:_mm512_min_pd(x, _mm512_andnot_pd(x, y))", f927, 2, 512},
  {"512:_mm512_min_pd(_mm512_andnot_pd(x, y), x)", f928, 2, 512},
  {"512:_mm512_min_pd(y, _mm512_andnot_pd(x, y))", f929, 2, 512},
  {"512:_mm512_max_pd(_mm512_add_pd(x, y), y)", f930, 2, 512},
  {"512:_mm512_max_pd(x, _mm512_add_pd(x, y))", f931, 2, 512},
  {"512:_mm512_max_pd(_mm512_add_pd(x, y), x)", f932, 2, 512},
  {"512:_mm512_max_pd(y, _mm512_add_pd(x, y))", f933, 2, 512},
  {"512:_mm512_max_pd(_mm512_sub_pd(x, y), y)", f934, 2, 512},
  {"512:_mm512_max_pd(x, _mm512_sub_pd(x, y))", f935, 2, 512},
  {"512:_mm512_max_pd(_mm512_sub_pd(x, y), x)", f936, 2, 512},
  {"512:_mm512_max_pd(y, _mm512_sub_pd(x, y))", f937, 2, 512},
  {"512:_mm512_max_pd(_mm512_mul_pd(x, y), y)", f938, 2, 512},
  {"512:_mm512_max_pd(x, _mm512_mul_pd(x, y))", f939, 2, 512},
  {"512:_mm512_max_pd(_mm512_mul_pd(x, y), x)", f940, 2, 512},
  {"512:_mm512_max_pd(y, _mm512_mul_pd(x, y))", f941, 2, 512},
  {"512:_mm512_max_pd(_mm512_div_pd(x, y), y)", f942, 2, 512},
  {"512:_mm512_max_pd(x, _mm512_div_pd(x, y))", f943, 2, 512},
  {"512:_mm512_max_pd(_mm512_div_pd(x, y), x)", f944, 2, 512},
  {"512:_mm512_max_pd(y, _mm512_div_pd(x, y))", f945, 2, 512},
  {"512:_mm512_max_pd(_mm512_min_pd(x, y), y)", f946, 2, 512},
  {"512:_mm512_max_pd(x, _mm512_min_pd(x, y))", f947, 2, 512},
  {"512:_mm512_max_pd(_mm512_min_pd(x, y), x)", f948, 2, 512},
  {"512:_mm512_max_pd(y, _mm512_min_pd(x, y))", f949, 2, 512},
  {"512:_mm512_max_pd(_mm512_max_pd(x, y), y)", f950, 2, 512},
  {"512:_mm512_max_pd(x, _mm512_max_pd(x, y))", f951, 2, 512},
  {"512:_mm512_max_pd(_mm512_max_pd(x, y), x)", f952, 2, 512},
  {"512:_mm512_max_pd(y, _mm512_max_pd(x, y))", f953, 2, 512},
  {"512:_mm512_max_pd(_mm512_and_pd(x, y), y)", f954, 2, 512},
  {"512:_mm512_max_pd(x, _mm512_and_pd(x, y))", f955, 2, 512},
  {"512:_mm512_max_pd(_mm512_and_pd(x, y), x)", f956, 2, 512},
  {"512:_mm512_max_pd(y, _mm512_and_pd(x, y))", f957, 2, 512},
  {"512:_mm512_max_pd(_mm512_or_pd(x, y), y)", f958, 2, 512},
  {"512:_mm512_max_pd(x, _mm512_or_pd(x, y))", f959, 2, 512},
  {"512:_mm512_max_pd(_mm512_or_pd(x, y), x)", f960, 2, 512},
  {"512:_mm512_max_pd(y, _mm512_or_pd(x, y))", f961, 2, 512},
  {"512:_mm512_max_pd(_mm512_xor_pd(x, y), y)", f962, 2, 512},
  {"512:_mm512_max_pd(x, _mm512_xor_pd(x, y))", f963, 2, 512},
  {"512:_mm512_max_pd(_mm512_xor_pd(x, y), x)", f964, 2, 512},
  {"512:_mm512_max_pd(y, _mm512_xor_pd(x, y))", f965, 2, 512},
  {"512:_mm512_max_pd(_mm512_andnot_pd(x, y), y)", f966, 2, 512},
  {"512:_mm512_max_pd(x, _mm512_andnot_pd(x, y))", f967, 2, 512},
  {"512:_mm512_max_pd(_mm512_andnot_pd(x, y), x)", f968, 2, 512},
  {"512:_mm512_max_pd(y, _mm512_andnot_pd(x, y))", f969, 2, 512},
  {"512:_mm512_and_pd(_mm512_add_pd(x, y), y)", f970, 2, 512},
  {"512:_mm512_and_pd(x, _mm512_add_pd(x, y))", f971, 2, 512},
  {"512:_mm512_and_pd(_mm512_add_pd(x, y), x)", f972, 2, 512},
  {"512:_mm512_and_pd(y, _mm512_add_pd(x, y))", f973, 2, 512},
  {"512:_mm512_and_pd(_mm512_sub_pd(x, y), y)", f974, 2, 512},
  {"512:_mm512_and_pd(x, _mm512_sub_pd(x, y))", f975, 2, 512},
  {"512:_mm512_and_pd(_mm512_sub_pd(x, y), x)", f976, 2, 512},
  {"512:_mm512_and_pd(y, _mm512_sub_pd(x, y))", f977, 2, 512},
  {"512:_mm512_and_pd(_mm512_mul_pd(x, y), y)", f978, 2, 512},
  {"512:_mm512_and_pd(x, _mm512_mul_pd(x, y))", f979, 2, 512},
  {"512:_mm512_and_pd(_mm512_mul_pd(x, y), x)", f980, 2, 512},
  {"512:_mm512_and_pd(y, _mm512_mul_pd(x, y))", f981, 2, 512},
  {"512:_mm512_and_pd(_mm512_div_pd(x, y), y)", f982, 2, 512},
  {"512:_mm512_and_pd(x, _mm512_div_pd(x, y))", f983, 2, 512},
  {"512:_mm512_and_pd(_mm512_div_pd(x, y), x)", f984, 2, 512},
  {"512:_mm512_and_pd(y, _mm512_div_pd(x, y))", f985, 2, 512},
  {"512:_mm512_and_pd(_mm512_min_pd(x, y), y)", f986, 2, 512},
  {"512:_mm512_and_pd(x, _mm512_min_pd(x, y))", f987, 2, 512},
  {"512:_mm512_and_pd(_mm512_min_pd(x, y), x)", f988, 2, 512},
  {"512:_mm512_and_pd(y, _mm512_min_pd(x, y))", f989, 2, 512},
  {"512:_mm512_and_pd(_mm512_max_pd(x, y), y)", f990, 2, 512},
  {"512:_mm512_and_pd(x, _mm512_max_pd(x, y))", f991, 2, 512},
  {"512:_mm512_and_pd(_mm512_max_pd(x, y), x)", f992, 2, 512},
  {"512:_mm512_and_pd(y, _mm512_max_pd(x, y))", f993, 2, 512},
  {"512:_mm512_and_pd(_mm512_and_pd(x, y), y)", f994, 2, 512},
  {"512:_mm512_and_pd(x, _mm512_and_pd(x, y))", f995, 2, 512},
  {"512:_mm512_and_pd(_mm512_and_pd(x, y), x)", f996, 2, 512},
  {"512:_mm512_and_pd(y, _mm512_and_pd(x, y))", f997, 2, 512},
  {"512:_mm512_and_pd(_mm512_or_pd(x, y), y)", f998, 2, 512},
  {"512:_mm512_and_pd(x, _mm512_or_pd(x, y))", f999, 2, 512},
  {"512:_mm512_and_pd(_mm512_or_pd(x, y), x)", f1000, 2, 512},
  {"512:_mm512_and_pd(y, _mm512_or_pd(x, y))", f1001, 2, 512},
  {"512:_mm512_and_pd(_mm512_xor_pd(x, y), y)", f1002, 2, 512},
  {"512:_mm512_and_pd(x, _mm512_xor_pd(x, y))", f1003, 2, 512},
  {"512:_mm512_and_pd(_mm512_xor_pd(x, y), x)", f1004, 2, 512},
  {"512:_mm512_and_pd(y, _mm512_xor_pd(x, y))", f1005, 2, 512},
  {"512:_mm512_and_pd(_mm512_andnot_pd(x, y), y)", f1006, 2, 512},
  {"512:_mm512_and_pd(x, _mm512_andnot_pd(x, y))", f1007, 2, 512},
  {"512:_mm512_and_pd(_mm512_andnot_pd(x, y), x)", f1008, 2, 512},
  {"512:_mm512_and_pd(y, _mm512_andnot_pd(x, y))", f1009, 2, 512},
  {"512:_mm512_or_pd(_mm512_add_pd(x, y), y)", f1010, 2, 512},
  {"512:_mm512_or_pd(x, _mm512_add_pd(x, y))", f1011, 2, 512},
  {"512:_mm512_or_pd(_mm512_add_pd(x, y), x)", f1012, 2, 512},
  {"512:_mm512_or_pd(y, _mm512_add_pd(x, y))", f1013, 2, 512},
  {"512:_mm512_or_pd(_mm512_sub_pd(x, y), y)", f1014, 2, 512},
  {"512:_mm512_or_pd(x, _mm512_sub_pd(x, y))", f1015, 2, 512},
  {"512:_mm512_or_pd(_mm512_sub_pd(x, y), x)", f1016, 2, 512},
  {"512:_mm512_or_pd(y, _mm512_sub_pd(x, y))", f1017, 2, 512},
  {"512:_mm512_or_pd(_mm512_mul_pd(x, y), y)", f1018, 2, 512},
  {"512:_mm512_or_pd(x, _mm512_mul_pd(x, y))", f1019, 2, 512},
  {"512:_mm512_or_pd(_mm512_mul_pd(x, y), x)", f1020, 2, 512},
  {"512:_mm512_or_pd(y, _mm512_mul_pd(x, y))", f1021, 2, 512},
  {"512:_mm512_or_pd(_mm512_div_pd(x, y), y)", f1022, 2, 512},
  {"512:_mm512_or_pd(x, _mm512_div_pd(x, y))", f1023, 2, 512},
  {"512:_mm512_or_pd(_mm512_div_pd(x, y), x)", f1024, 2, 512},
  {"512:_mm512_or_pd(y, _mm512_div_pd(x, y))", f1025, 2, 512},
  {"512:_mm512_or_pd(_mm512_min_pd(x, y), y)", f1026, 2, 512},
  {"512:_mm512_or_pd(x, _mm512_min_pd(x, y))", f1027, 2, 512},
  {"512:_mm512_or_pd(_mm512_min_pd(x, y), x)", f1028, 2, 512},
  {"512:_mm512_or_pd(y, _mm512_min_pd(x, y))", f1029, 2, 512},
  {"512:_mm512_or_pd(_mm512_max_pd(x, y), y)", f1030, 2, 512},
  {"512:_mm512_or_pd(x, _mm512_max_pd(x, y))", f1031, 2, 512},
  {"512:_mm512_or_pd(_mm512_max_pd(x, y), x)", f1032, 2, 512},
  {"512:_mm512_or_pd(y, _mm512_max_pd(x, y))", f1033, 2, 512},
  {"512:_mm512_or_pd(_mm512_and_pd(x, y), y)", f1034, 2, 512},
  {"512:_mm512_or_pd(x, _mm512_and_pd(x, y))", f1035, 2, 512},
  {"512:_mm512_or_pd(_mm512_and_pd(x, y), x)", f1036, 2, 512},
  {"512:_mm512_or_pd(y, _mm512_and_pd(x, y))", f1037, 2, 512},
  {"512:_mm512_or_pd(_mm512_or_pd(x, y), y)", f1038, 2, 512},
  {"512:_mm512_or_pd(x, _mm512_or_pd(x, y))", f1039, 2, 512},
  {"512:_mm512_or_pd(_mm512_or_pd(x, y), x)", f1040, 2, 512},
  {"512:_mm512_or_pd(y, _mm512_or_pd(x, y))", f1041, 2, 512},
  {"512:_mm512_or_pd(_mm512_xor_pd(x, y), y)", f1042, 2, 512},
  {"512:_mm512_or_pd(x, _mm512_xor_pd(x, y))", f1043, 2, 512},
  {"512:_mm512_or_pd(_mm512_xor_pd(x, y), x)", f1044, 2, 512},
  {"512:_mm512_or_pd(y, _mm512_xor_pd(x, y))", f1045, 2, 512},
  {"512:_mm512_or_pd(_mm512_andnot_pd(x, y), y)", f1046, 2, 512},
  {"512:_mm512_or_pd(x, _mm512_andnot_pd(x, y))", f1047, 2, 512},
  {"512:_mm512_or_pd(_mm512_andnot_pd(x, y), x)", f1048, 2, 512},
  {"512:_mm512_or_pd(y, _mm512_andnot_pd(x, y))", f1049, 2, 512},
  {"512:_mm512_xor_pd(_mm512_add_pd(x, y), y)", f1050, 2, 512},
  {"512:_mm512_xor_pd(x, _mm512_add_pd(x, y))", f1051, 2, 512},
  {"512:_mm512_xor_pd(_mm512_add_pd(x, y), x)", f1052, 2, 512},
  {"512:_mm512_xor_pd(y, _mm512_add_pd(x, y))", f1053, 2, 512},
  {"512:_mm512_xor_pd(_mm512_sub_pd(x, y), y)", f1054, 2, 512},
  {"512:_mm512_xor_pd(x, _mm512_sub_pd(x, y))", f1055, 2, 512},
  {"512:_mm512_xor_pd(_mm512_sub_pd(x, y), x)", f1056, 2, 512},
  {"512:_mm512_xor_pd(y, _mm512_sub_pd(x, y))", f1057, 2, 512},
  {"512:_mm512_xor_pd(_mm512_mul_pd(x, y), y)", f1058, 2, 512},
  {"512:_mm512_xor_pd(x, _mm512_mul_pd(x, y))", f1059, 2, 512},
  {"512:_mm512_xor_pd(_mm512_mul_pd(x, y), x)", f1060, 2, 512},
  {"512:_mm512_xor_pd(y, _mm512_mul_pd(x, y))", f1061, 2, 512},
  {"512:_mm512_xor_pd(_mm512_div_pd(x, y), y)", f1062, 2, 512},
  {"512:_mm512_xor_pd(x, _mm512_div_pd(x, y))", f1063, 2, 512},
  {"512:_mm512_xor_pd(_mm512_div_pd(x, y), x)", f1064, 2, 512},
  {"512:_mm512_xor_pd(y, _mm512_div_pd(x, y))", f1065, 2, 512},
  {"512:_mm512_xor_pd(_mm512_min_pd(x, y), y)", f1066, 2, 512},
  {"512:_mm512_xor_pd(x, _mm512_min_pd(x, y))", f1067, 2, 512},
  {"512:_mm512_xor_pd(_mm512_min_pd(x, y), x)", f1068, 2, 512},
  {"512:_mm512_xor_pd(y, _mm512_min_pd(x, y))", f1069, 2, 512},
  {"512:_mm512_xor_pd(_mm512_max_pd(x, y), y)", f1070, 2, 512},
  {"512:_mm512_xor_pd(x, _mm512_max_pd(x, y))", f1071, 2, 512},
  {"512:_mm512_xor_pd(_mm512_max_pd(x, y), x)", f1072, 2, 512},
  {"512:_mm512_xor_pd(y, _mm512_max_pd(x, y))", f1073, 2, 512},
  {"512:_mm512_xor_pd(_mm512_and_pd(x, y), y)", f1074, 2, 512},
  {"512:_mm512_xor_pd(x, _mm512_and_pd(x, y))", f1075, 2, 512},
  {"512:_mm512_xor_pd(_mm512_and_pd(x, y), x)", f1076, 2, 512},
  {"512:_mm512_xor_pd(y, _mm512_and_pd(x, y))", f1077, 2, 512},
  {"512:_mm512_xor_pd(_mm512_or_pd(x, y), y)", f1078, 2, 512},
  {"512:_mm512_xor_pd(x, _mm512_or_pd(x, y))", f1079, 2, 512},
  {"512:_mm512_xor_pd(_mm512_or_pd(x, y), x)", f1080, 2, 512},
  {"512:_mm512_xor_pd(y, _mm512_or_pd(x, y))", f1081, 2, 512},
  {"512:_mm512_xor_pd(_mm512_xor_pd(x, y), y)", f1082, 2, 512},
  {"512:_mm512_xor_pd(x, _mm512_xor_pd(x, y))", f1083, 2, 512},
  {"512:_mm512_xor_pd(_mm512_xor_pd(x, y), x)", f1084, 2, 512},
  {"512:_mm512_xor_pd(y, _mm512_xor_pd(x, y))", f1085, 2, 512},
  {"512:_mm512_xor_pd(_mm512_andnot_pd(x, y), y)", f1086, 2, 512},
  {"512:_mm512_xor_pd(x, _mm512_andnot_pd(x, y))", f1087, 2, 512},
  {"512:_mm512_xor_pd(_mm512_andnot_pd(x, y), x)", f1088, 2, 512},
  {"512:_mm512_xor_pd(y, _mm512_andnot_pd(x, y))", f1089, 2, 512},
  {"512:_mm512_andnot_pd(_mm512_add_pd(x, y), y)", f1090, 2, 512},
  {"512:_mm512_andnot_pd(x, _mm512_add_pd(x, y))", f1091, 2, 512},
  {"512:_mm512_andnot_pd(_mm512_add_pd(x, y), x)", f1092, 2, 512},
  {"512:_mm512_andnot_pd(y, _mm512_add_pd(x, y))", f1093, 2, 512},
  {"512:_mm512_andnot_pd(_mm512_sub_pd(x, y), y)", f1094, 2, 512},
  {"512:_mm512_andnot_pd(x, _mm512_sub_pd(x, y))", f1095, 2, 512},
  {"512:_mm512_andnot_pd(_mm512_sub_pd(x, y), x)", f1096, 2, 512},
  {"512:_mm512_andnot_pd(y, _mm512_sub_pd(x, y))", f1097, 2, 512},
  {"512:_mm512_andnot_pd(_mm512_mul_pd(x, y), y)", f1098, 2, 512},
  {"512:_mm512_andnot_pd(x, _mm512_mul_pd(x, y))", f1099, 2, 512},
  {"512:_mm512_andnot_pd(_mm512_mul_pd(x, y), x)", f1100, 2, 512},
  {"512:_mm512_andnot_pd(y, _mm512_mul_pd(x, y))", f1101, 2, 512},
  {"512:_mm512_andnot_pd(_mm512_div_pd(x, y), y)", f1102, 2, 512},
  {"512:_mm512_andnot_pd(x, _mm512_div_pd(x, y))", f1103, 2, 512},
  {"512:_mm512_andnot_pd(_mm512_div_pd(x, y), x)", f1104, 2, 512},
  {"512:_mm512_andnot_pd(y, _mm512_div_pd(x, y))", f1105, 2, 512},
  {"512:_mm512_andnot_pd(_mm512_min_pd(x, y), y)", f1106, 2, 512},
  {"512:_mm512_andnot_pd(x, _mm512_min_pd(x, y))", f1107, 2, 512},
  {"512:_mm512_andnot_pd(_mm512_min_pd(x, y), x)", f1108, 2, 512},
  {"512:_mm512_andnot_pd(y, _mm512_min_pd(x, y))", f1109, 2, 512},
  {"512:_mm512_andnot_pd(_mm512_max_pd(x, y), y)", f1110, 2, 512},
  {"512:_mm512_andnot_pd(x, _mm512_max_pd(x, y))", f1111, 2, 512},
  {"512:_mm512_andnot_pd(_mm512_max_pd(x, y), x)", f1112, 2, 512},
  {"512:_mm512_andnot_pd(y, _mm512_max_pd(x, y))", f1113, 2, 512},
  {"512:_mm512_andnot_pd(_mm512_and_pd(x, y), y)", f1114, 2, 512},
  {"512:_mm512_andnot_pd(x, _mm512_and_pd(x, y))", f1115, 2, 512},
  {"512:_mm512_andnot_pd(_mm512_and_pd(x, y), x)", f1116, 2, 512},
  {"512:_mm512_andnot_pd(y, _mm512_and_pd(x, y))", f1117, 2, 512},
  {"512:_mm512_andnot_pd(_mm512_or_pd(x, y), y)", f1118, 2, 512},
  {"512:_mm512_andnot_pd(x, _mm512_or_pd(x, y))", f1119, 2, 512},
  {"512:_mm512_andnot_pd(_mm512_or_pd(x, y), x)", f1120, 2, 512},
  {"512:_mm512_andnot_pd(y, _mm512_or_pd(x, y))", f1121, 2, 512},
  {"512:_mm512_andnot_pd(_mm512_xor_pd(x, y), y)", f1122, 2, 512},
  {"512:_mm512_andnot_pd(x, _mm512_xor_pd(x, y))", f1123, 2, 512},
  {"512:_mm512_andnot_pd(_mm512_xor_pd(x, y), x)", f1124, 2, 512},
  {"512:_mm512_andnot_pd(y, _mm512_xor_pd(x, y))", f1125, 2, 512},
  {"512:_mm512_andnot_pd(_mm512_andnot_pd(x, y), y)", f1126, 2, 512},
  {"512:_mm512_andnot_pd(x, _mm512_andnot_pd(x, y))", f1127, 2, 512},
  {"512:_mm512_andnot_pd(_mm512_andnot_pd(x, y), x)", f1128, 2, 512},
  {"512:_mm512_andnot_pd(y, _mm512_andnot_pd(x, y))", f1129, 2, 512},
  {"512:_mm512_fmadd_ps(x, y, _mm512_setzero_ps())", f1130, 1, 512},
  {"512:_mm512_fmadd_ps(x, _mm512_setzero_ps(), y)", f1131, 1, 512},
  {"512:_mm512_fmadd_ps(_mm512_setzero_ps(), x, y)", f1132, 1, 512},
  {"512:_mm512_fmadd_ps(x, y, _mm512_set1_ps(-0.0f))", f1133, 1, 512},
  {"512:_mm512_fmadd_ps(x, _mm512_set1_ps(-0.0f), y)", f1134, 1, 512},
  {"512:_mm512_fmadd_ps(_mm512_set1_ps(-0.0f), x, y)", f1135, 1, 512},
  {"512:_mm512_fmadd_ps(x, y, _mm512_set1_ps(1.0f))", f1136, 1, 512},
  {"512:_mm512_fmadd_ps(x, _mm512_set1_ps(1.0f), y)", f1137, 1, 512},
  {"512:_mm512_fmadd_ps(_mm512_set1_ps(1.0f), x, y)", f1138, 1, 512},
  {"512:_mm512_fmadd_ps(x, y, _mm512_set1_ps(-1.0f))", f1139, 1, 512},
  {"512:_mm512_fmadd_ps(x, _mm512_set1_ps(-1.0f), y)", f1140, 1, 512},
  {"512:_mm512_fmadd_ps(_mm512_set1_ps(-1.0f), x, y)", f1141, 1, 512},
  {"512:_mm512_fmadd_ps(x, y, _mm512_set1_ps(std::numeric_limits<float>::infinity()))", f1142, 1, 512},
  {"512:_mm512_fmadd_ps(x, _mm512_set1_ps(std::numeric_limits<float>::infinity()), y)", f1143, 1, 512},
  {"512:_mm512_fmadd_ps(_mm512_set1_ps(std::numeric_limits<float>::infinity()), x, y)", f1144, 1, 512},
  {"512:_mm512_fmadd_ps(x, y, _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN()))", f1145, 1, 512},
  {"512:_mm512_fmadd_ps(x, _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN()), y)", f1146, 1, 512},
  {"512:_mm512_fmadd_ps(_mm512_set1_ps(std::numeric_limits<float>::quiet_NaN()), x, y)", f1147, 1, 512},
  {"512:_mm512_fmadd_ps(x, y, x)", f1148, 1, 512},
  {"512:_mm512_fmadd_ps(x, x, y)", f1149, 1, 512},
  {"512:_mm512_fmadd_ps(x, y, _mm512_mul_ps(x, y))", f1150, 1, 512},
  {"512:_mm512_fmsub_ps(x, y, _mm512_setzero_ps())", f1151, 1, 512},
  {"512:_mm512_fmsub_ps(x, _mm512_setzero_ps(), y)", f1152, 1, 512},
  {"512:_mm512_fmsub_ps(_mm512_setzero_ps(), x, y)", f1153, 1, 512},
  {"512:_mm512_fmsub_ps(x, y, _mm512_set1_ps(-0.0f))", f1154, 1, 512},
  {"512:_mm512_fmsub_ps(x, _mm512_set1_ps(-0.0f), y)", f1155, 1, 512},
  {"512:_mm512_fmsub_ps(_mm512_set1_ps(-0.0f), x, y)", f1156, 1, 512},
  {"512:_mm512_fmsub_ps(x, y, _mm512_set1_ps(1.0f))", f1157, 1, 512},
  {"512:_mm512_fmsub_ps(x, _mm512_set1_ps(1.0f), y)", f1158, 1, 512},
  {"512:_mm512_fmsub_ps(_mm512_set1_ps(1.0f), x, y)", f1159, 1, 512},
  {"512:_mm512_fmsub_ps(x, y, _mm512_set1_ps(-1.0f))", f1160, 1, 512},
  {"512:_mm512_fmsub_ps(x, _mm512_set1_ps(-1.0f), y)", f1161, 1, 512},
  {"512:_mm512_fmsub_ps(_mm512_set1_ps(-1.0f), x, y)", f1162, 1, 512},
  {"512:_mm512_fmsub_ps(x, y, _mm512_set1_ps(std::numeric_limits<float>::infinity()))", f1163, 1, 512},
  {"512:_mm512_fmsub_ps(x, _mm512_set1_ps(std::numeric_limits<float>::infinity()), y)", f1164, 1, 512},
  {"512:_mm512_fmsub_ps(_mm512_set1_ps(std::numeric_limits<float>::infinity()), x, y)", f1165, 1, 512},
  {"512:_mm512_fmsub_ps(x, y, _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN()))", f1166, 1, 512},
  {"512:_mm512_fmsub_ps(x, _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN()), y)", f1167, 1, 512},
  {"512:_mm512_fmsub_ps(_mm512_set1_ps(std::numeric_limits<float>::quiet_NaN()), x, y)", f1168, 1, 512},
  {"512:_mm512_fmsub_ps(x, y, x)", f1169, 1, 512},
  {"512:_mm512_fmsub_ps(x, x, y)", f1170, 1, 512},
  {"512:_mm512_fmsub_ps(x, y, _mm512_mul_ps(x, y))", f1171, 1, 512},
  {"512:_mm512_fnmadd_ps(x, y, _mm512_setzero_ps())", f1172, 1, 512},
  {"512:_mm512_fnmadd_ps(x, _mm512_setzero_ps(), y)", f1173, 1, 512},
  {"512:_mm512_fnmadd_ps(_mm512_setzero_ps(), x, y)", f1174, 1, 512},
  {"512:_mm512_fnmadd_ps(x, y, _mm512_set1_ps(-0.0f))", f1175, 1, 512},
  {"512:_mm512_fnmadd_ps(x, _mm512_set1_ps(-0.0f), y)", f1176, 1, 512},
  {"512:_mm512_fnmadd_ps(_mm512_set1_ps(-0.0f), x, y)", f1177, 1, 512},
  {"512:_mm512_fnmadd_ps(x, y, _mm512_set1_ps(1.0f))", f1178, 1, 512},
  {"512:_mm512_fnmadd_ps(x, _mm512_set1_ps(1.0f), y)", f1179, 1, 512},
  {"512:_mm512_fnmadd_ps(_mm512_set1_ps(1.0f), x, y)", f1180, 1, 512},
  {"512:_mm512_fnmadd_ps(x, y, _mm512_set1_ps(-1.0f))", f1181, 1, 512},
  {"512:_mm512_fnmadd_ps(x, _mm512_set1_ps(-1.0f), y)", f1182, 1, 512},
  {"512:_mm512_fnmadd_ps(_mm512_set1_ps(-1.0f), x, y)", f1183, 1, 512},
  {"512:_mm512_fnmadd_ps(x, y, _mm512_set1_ps(std::numeric_limits<float>::infinity()))", f1184, 1, 512},
  {"512:_mm512_fnmadd_ps(x, _mm512_set1_ps(std::numeric_limits<float>::infinity()), y)", f1185, 1, 512},
  {"512:_mm512_fnmadd_ps(_mm512_set1_ps(std::numeric_limits<float>::infinity()), x, y)", f1186, 1, 512},
  {"512:_mm512_fnmadd_ps(x, y, _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN()))", f1187, 1, 512},
  {"512:_mm512_fnmadd_ps(x, _mm512_set1_ps(std::numeric_limits<float>::quiet_NaN()), y)", f1188, 1, 512},
  {"512:_mm512_fnmadd_ps(_mm512_set1_ps(std::numeric_limits<float>::quiet_NaN()), x, y)", f1189, 1, 512},
  {"512:_mm512_fnmadd_ps(x, y, x)", f1190, 1, 512},
  {"512:_mm512_fnmadd_ps(x, x, y)", f1191, 1, 512},
  {"512:_mm512_fnmadd_ps(x, y, _mm512_mul_ps(x, y))", f1192, 1, 512},
  {"512:_mm512_fnmsub_ps(x, y, _mm512_setzero_ps())", f1193, 1, 512},
  {"512:_mm512_fnmsub_ps(x, _mm512_setzero_ps(), y)", f1194, 1, 512},
  {"512:_mm512_fnmsub_ps(_mm512_setzero_ps(), x, y)", f1195, 1, 512},
  {"512:_mm512_fnmsub_ps(x, y, _mm512_set1_ps(-0.0f))", f1196, 1, 512},
  {"512:_mm512_fnmsub_ps(x, _mm512_set1_ps(-0.0f), y)", f1197, 1, 512},
  {"512:_mm512_fnmsub_ps(_mm512_set1_ps(-0.0f), x, y)", f1198, 1, 512},
  {"512:_mm512_fnmsub_ps(x, y, _mm512_set1_ps(1.0f))", f1199, 1, 512},
};
extern const int size_95 = 1200;
