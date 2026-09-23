#include "common.h"
static NOINLINE void f0(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_round_pd(_mm256_fmsub_pd(_mm256_set1_pd(std::numeric_limits<double>::infinity()), x, y), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f1(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_permute_pd(_mm256_fmsub_pd(_mm256_set1_pd(std::numeric_limits<double>::infinity()), x, y), 0x5); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f2(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_permute_pd(_mm256_fmsub_pd(_mm256_set1_pd(std::numeric_limits<double>::infinity()), x, y), 0xa); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f3(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_permute_pd(_mm256_fmsub_pd(_mm256_set1_pd(std::numeric_limits<double>::infinity()), x, y), 0x3); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f4(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_sqrt_pd(_mm256_fmsub_pd(x, y, _mm256_set1_pd(std::numeric_limits<double>::quiet_NaN()))); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f5(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_xor_pd(_mm256_fmsub_pd(x, y, _mm256_set1_pd(std::numeric_limits<double>::quiet_NaN())), _mm256_set1_pd(-0.0)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f6(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_andnot_pd(_mm256_set1_pd(-0.0), _mm256_fmsub_pd(x, y, _mm256_set1_pd(std::numeric_limits<double>::quiet_NaN()))); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f7(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_sub_pd(_mm256_setzero_pd(), _mm256_fmsub_pd(x, y, _mm256_set1_pd(std::numeric_limits<double>::quiet_NaN()))); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f8(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_mul_pd(_mm256_fmsub_pd(x, y, _mm256_set1_pd(std::numeric_limits<double>::quiet_NaN())), _mm256_set1_pd(-1.0)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f9(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_floor_pd(_mm256_fmsub_pd(x, y, _mm256_set1_pd(std::numeric_limits<double>::quiet_NaN()))); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f10(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_ceil_pd(_mm256_fmsub_pd(x, y, _mm256_set1_pd(std::numeric_limits<double>::quiet_NaN()))); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f11(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_round_pd(_mm256_fmsub_pd(x, y, _mm256_set1_pd(std::numeric_limits<double>::quiet_NaN())), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f12(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_permute_pd(_mm256_fmsub_pd(x, y, _mm256_set1_pd(std::numeric_limits<double>::quiet_NaN())), 0x5); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f13(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_permute_pd(_mm256_fmsub_pd(x, y, _mm256_set1_pd(std::numeric_limits<double>::quiet_NaN())), 0xa); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f14(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_permute_pd(_mm256_fmsub_pd(x, y, _mm256_set1_pd(std::numeric_limits<double>::quiet_NaN())), 0x3); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f15(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_sqrt_pd(_mm256_fmsub_pd(x, _mm256_set1_pd(std::numeric_limits<double>::quiet_NaN()), y)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f16(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_xor_pd(_mm256_fmsub_pd(x, _mm256_set1_pd(std::numeric_limits<double>::quiet_NaN()), y), _mm256_set1_pd(-0.0)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f17(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_andnot_pd(_mm256_set1_pd(-0.0), _mm256_fmsub_pd(x, _mm256_set1_pd(std::numeric_limits<double>::quiet_NaN()), y)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f18(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_sub_pd(_mm256_setzero_pd(), _mm256_fmsub_pd(x, _mm256_set1_pd(std::numeric_limits<double>::quiet_NaN()), y)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f19(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_mul_pd(_mm256_fmsub_pd(x, _mm256_set1_pd(std::numeric_limits<double>::quiet_NaN()), y), _mm256_set1_pd(-1.0)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f20(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_floor_pd(_mm256_fmsub_pd(x, _mm256_set1_pd(std::numeric_limits<double>::quiet_NaN()), y)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f21(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_ceil_pd(_mm256_fmsub_pd(x, _mm256_set1_pd(std::numeric_limits<double>::quiet_NaN()), y)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f22(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_round_pd(_mm256_fmsub_pd(x, _mm256_set1_pd(std::numeric_limits<double>::quiet_NaN()), y), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f23(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_permute_pd(_mm256_fmsub_pd(x, _mm256_set1_pd(std::numeric_limits<double>::quiet_NaN()), y), 0x5); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f24(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_permute_pd(_mm256_fmsub_pd(x, _mm256_set1_pd(std::numeric_limits<double>::quiet_NaN()), y), 0xa); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f25(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_permute_pd(_mm256_fmsub_pd(x, _mm256_set1_pd(std::numeric_limits<double>::quiet_NaN()), y), 0x3); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f26(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_sqrt_pd(_mm256_fmsub_pd(_mm256_set1_pd(std::numeric_limits<double>::quiet_NaN()), x, y)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f27(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_xor_pd(_mm256_fmsub_pd(_mm256_set1_pd(std::numeric_limits<double>::quiet_NaN()), x, y), _mm256_set1_pd(-0.0)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f28(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_andnot_pd(_mm256_set1_pd(-0.0), _mm256_fmsub_pd(_mm256_set1_pd(std::numeric_limits<double>::quiet_NaN()), x, y)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f29(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_sub_pd(_mm256_setzero_pd(), _mm256_fmsub_pd(_mm256_set1_pd(std::numeric_limits<double>::quiet_NaN()), x, y)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f30(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_mul_pd(_mm256_fmsub_pd(_mm256_set1_pd(std::numeric_limits<double>::quiet_NaN()), x, y), _mm256_set1_pd(-1.0)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f31(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_floor_pd(_mm256_fmsub_pd(_mm256_set1_pd(std::numeric_limits<double>::quiet_NaN()), x, y)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f32(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_ceil_pd(_mm256_fmsub_pd(_mm256_set1_pd(std::numeric_limits<double>::quiet_NaN()), x, y)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f33(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_round_pd(_mm256_fmsub_pd(_mm256_set1_pd(std::numeric_limits<double>::quiet_NaN()), x, y), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f34(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_permute_pd(_mm256_fmsub_pd(_mm256_set1_pd(std::numeric_limits<double>::quiet_NaN()), x, y), 0x5); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f35(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_permute_pd(_mm256_fmsub_pd(_mm256_set1_pd(std::numeric_limits<double>::quiet_NaN()), x, y), 0xa); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f36(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_permute_pd(_mm256_fmsub_pd(_mm256_set1_pd(std::numeric_limits<double>::quiet_NaN()), x, y), 0x3); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f37(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_sqrt_pd(_mm256_fmsub_pd(x, y, x)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f38(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_xor_pd(_mm256_fmsub_pd(x, y, x), _mm256_set1_pd(-0.0)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f39(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_andnot_pd(_mm256_set1_pd(-0.0), _mm256_fmsub_pd(x, y, x)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f40(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_sub_pd(_mm256_setzero_pd(), _mm256_fmsub_pd(x, y, x)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f41(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_mul_pd(_mm256_fmsub_pd(x, y, x), _mm256_set1_pd(-1.0)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f42(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_floor_pd(_mm256_fmsub_pd(x, y, x)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f43(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_ceil_pd(_mm256_fmsub_pd(x, y, x)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f44(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_round_pd(_mm256_fmsub_pd(x, y, x), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f45(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_permute_pd(_mm256_fmsub_pd(x, y, x), 0x5); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f46(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_permute_pd(_mm256_fmsub_pd(x, y, x), 0xa); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f47(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_permute_pd(_mm256_fmsub_pd(x, y, x), 0x3); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f48(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_sqrt_pd(_mm256_fmsub_pd(x, x, y)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f49(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_xor_pd(_mm256_fmsub_pd(x, x, y), _mm256_set1_pd(-0.0)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f50(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_andnot_pd(_mm256_set1_pd(-0.0), _mm256_fmsub_pd(x, x, y)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f51(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_sub_pd(_mm256_setzero_pd(), _mm256_fmsub_pd(x, x, y)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f52(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_mul_pd(_mm256_fmsub_pd(x, x, y), _mm256_set1_pd(-1.0)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f53(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_floor_pd(_mm256_fmsub_pd(x, x, y)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f54(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_ceil_pd(_mm256_fmsub_pd(x, x, y)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f55(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_round_pd(_mm256_fmsub_pd(x, x, y), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f56(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_permute_pd(_mm256_fmsub_pd(x, x, y), 0x5); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f57(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_permute_pd(_mm256_fmsub_pd(x, x, y), 0xa); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f58(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_permute_pd(_mm256_fmsub_pd(x, x, y), 0x3); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f59(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_sqrt_pd(_mm256_fmsub_pd(x, y, _mm256_mul_pd(x, y))); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f60(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_xor_pd(_mm256_fmsub_pd(x, y, _mm256_mul_pd(x, y)), _mm256_set1_pd(-0.0)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f61(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_andnot_pd(_mm256_set1_pd(-0.0), _mm256_fmsub_pd(x, y, _mm256_mul_pd(x, y))); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f62(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_sub_pd(_mm256_setzero_pd(), _mm256_fmsub_pd(x, y, _mm256_mul_pd(x, y))); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f63(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_mul_pd(_mm256_fmsub_pd(x, y, _mm256_mul_pd(x, y)), _mm256_set1_pd(-1.0)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f64(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_floor_pd(_mm256_fmsub_pd(x, y, _mm256_mul_pd(x, y))); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f65(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_ceil_pd(_mm256_fmsub_pd(x, y, _mm256_mul_pd(x, y))); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f66(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_round_pd(_mm256_fmsub_pd(x, y, _mm256_mul_pd(x, y)), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f67(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_permute_pd(_mm256_fmsub_pd(x, y, _mm256_mul_pd(x, y)), 0x5); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f68(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_permute_pd(_mm256_fmsub_pd(x, y, _mm256_mul_pd(x, y)), 0xa); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f69(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_permute_pd(_mm256_fmsub_pd(x, y, _mm256_mul_pd(x, y)), 0x3); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f70(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_sqrt_pd(_mm256_fnmadd_pd(x, y, _mm256_setzero_pd())); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f71(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_xor_pd(_mm256_fnmadd_pd(x, y, _mm256_setzero_pd()), _mm256_set1_pd(-0.0)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f72(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_andnot_pd(_mm256_set1_pd(-0.0), _mm256_fnmadd_pd(x, y, _mm256_setzero_pd())); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f73(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_sub_pd(_mm256_setzero_pd(), _mm256_fnmadd_pd(x, y, _mm256_setzero_pd())); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f74(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_mul_pd(_mm256_fnmadd_pd(x, y, _mm256_setzero_pd()), _mm256_set1_pd(-1.0)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f75(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_floor_pd(_mm256_fnmadd_pd(x, y, _mm256_setzero_pd())); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f76(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_ceil_pd(_mm256_fnmadd_pd(x, y, _mm256_setzero_pd())); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f77(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_round_pd(_mm256_fnmadd_pd(x, y, _mm256_setzero_pd()), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f78(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_permute_pd(_mm256_fnmadd_pd(x, y, _mm256_setzero_pd()), 0x5); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f79(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_permute_pd(_mm256_fnmadd_pd(x, y, _mm256_setzero_pd()), 0xa); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f80(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_permute_pd(_mm256_fnmadd_pd(x, y, _mm256_setzero_pd()), 0x3); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f81(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_sqrt_pd(_mm256_fnmadd_pd(x, _mm256_setzero_pd(), y)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f82(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_xor_pd(_mm256_fnmadd_pd(x, _mm256_setzero_pd(), y), _mm256_set1_pd(-0.0)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f83(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_andnot_pd(_mm256_set1_pd(-0.0), _mm256_fnmadd_pd(x, _mm256_setzero_pd(), y)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f84(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_sub_pd(_mm256_setzero_pd(), _mm256_fnmadd_pd(x, _mm256_setzero_pd(), y)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f85(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_mul_pd(_mm256_fnmadd_pd(x, _mm256_setzero_pd(), y), _mm256_set1_pd(-1.0)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f86(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_floor_pd(_mm256_fnmadd_pd(x, _mm256_setzero_pd(), y)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f87(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_ceil_pd(_mm256_fnmadd_pd(x, _mm256_setzero_pd(), y)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f88(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_round_pd(_mm256_fnmadd_pd(x, _mm256_setzero_pd(), y), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f89(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_permute_pd(_mm256_fnmadd_pd(x, _mm256_setzero_pd(), y), 0x5); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f90(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_permute_pd(_mm256_fnmadd_pd(x, _mm256_setzero_pd(), y), 0xa); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f91(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_permute_pd(_mm256_fnmadd_pd(x, _mm256_setzero_pd(), y), 0x3); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f92(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_sqrt_pd(_mm256_fnmadd_pd(_mm256_setzero_pd(), x, y)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f93(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_xor_pd(_mm256_fnmadd_pd(_mm256_setzero_pd(), x, y), _mm256_set1_pd(-0.0)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f94(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_andnot_pd(_mm256_set1_pd(-0.0), _mm256_fnmadd_pd(_mm256_setzero_pd(), x, y)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f95(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_sub_pd(_mm256_setzero_pd(), _mm256_fnmadd_pd(_mm256_setzero_pd(), x, y)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f96(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_mul_pd(_mm256_fnmadd_pd(_mm256_setzero_pd(), x, y), _mm256_set1_pd(-1.0)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f97(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_floor_pd(_mm256_fnmadd_pd(_mm256_setzero_pd(), x, y)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f98(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_ceil_pd(_mm256_fnmadd_pd(_mm256_setzero_pd(), x, y)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f99(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_round_pd(_mm256_fnmadd_pd(_mm256_setzero_pd(), x, y), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f100(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_permute_pd(_mm256_fnmadd_pd(_mm256_setzero_pd(), x, y), 0x5); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f101(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_permute_pd(_mm256_fnmadd_pd(_mm256_setzero_pd(), x, y), 0xa); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f102(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_permute_pd(_mm256_fnmadd_pd(_mm256_setzero_pd(), x, y), 0x3); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f103(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_sqrt_pd(_mm256_fnmadd_pd(x, y, _mm256_set1_pd(-0.0))); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f104(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_xor_pd(_mm256_fnmadd_pd(x, y, _mm256_set1_pd(-0.0)), _mm256_set1_pd(-0.0)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f105(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_andnot_pd(_mm256_set1_pd(-0.0), _mm256_fnmadd_pd(x, y, _mm256_set1_pd(-0.0))); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f106(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_sub_pd(_mm256_setzero_pd(), _mm256_fnmadd_pd(x, y, _mm256_set1_pd(-0.0))); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f107(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_mul_pd(_mm256_fnmadd_pd(x, y, _mm256_set1_pd(-0.0)), _mm256_set1_pd(-1.0)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f108(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_floor_pd(_mm256_fnmadd_pd(x, y, _mm256_set1_pd(-0.0))); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f109(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_ceil_pd(_mm256_fnmadd_pd(x, y, _mm256_set1_pd(-0.0))); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f110(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_round_pd(_mm256_fnmadd_pd(x, y, _mm256_set1_pd(-0.0)), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f111(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_permute_pd(_mm256_fnmadd_pd(x, y, _mm256_set1_pd(-0.0)), 0x5); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f112(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_permute_pd(_mm256_fnmadd_pd(x, y, _mm256_set1_pd(-0.0)), 0xa); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f113(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_permute_pd(_mm256_fnmadd_pd(x, y, _mm256_set1_pd(-0.0)), 0x3); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f114(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_sqrt_pd(_mm256_fnmadd_pd(x, _mm256_set1_pd(-0.0), y)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f115(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_xor_pd(_mm256_fnmadd_pd(x, _mm256_set1_pd(-0.0), y), _mm256_set1_pd(-0.0)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f116(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_andnot_pd(_mm256_set1_pd(-0.0), _mm256_fnmadd_pd(x, _mm256_set1_pd(-0.0), y)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f117(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_sub_pd(_mm256_setzero_pd(), _mm256_fnmadd_pd(x, _mm256_set1_pd(-0.0), y)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f118(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_mul_pd(_mm256_fnmadd_pd(x, _mm256_set1_pd(-0.0), y), _mm256_set1_pd(-1.0)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f119(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_floor_pd(_mm256_fnmadd_pd(x, _mm256_set1_pd(-0.0), y)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f120(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_ceil_pd(_mm256_fnmadd_pd(x, _mm256_set1_pd(-0.0), y)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f121(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_round_pd(_mm256_fnmadd_pd(x, _mm256_set1_pd(-0.0), y), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f122(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_permute_pd(_mm256_fnmadd_pd(x, _mm256_set1_pd(-0.0), y), 0x5); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f123(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_permute_pd(_mm256_fnmadd_pd(x, _mm256_set1_pd(-0.0), y), 0xa); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f124(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_permute_pd(_mm256_fnmadd_pd(x, _mm256_set1_pd(-0.0), y), 0x3); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f125(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_sqrt_pd(_mm256_fnmadd_pd(_mm256_set1_pd(-0.0), x, y)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f126(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_xor_pd(_mm256_fnmadd_pd(_mm256_set1_pd(-0.0), x, y), _mm256_set1_pd(-0.0)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f127(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_andnot_pd(_mm256_set1_pd(-0.0), _mm256_fnmadd_pd(_mm256_set1_pd(-0.0), x, y)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f128(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_sub_pd(_mm256_setzero_pd(), _mm256_fnmadd_pd(_mm256_set1_pd(-0.0), x, y)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f129(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_mul_pd(_mm256_fnmadd_pd(_mm256_set1_pd(-0.0), x, y), _mm256_set1_pd(-1.0)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f130(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_floor_pd(_mm256_fnmadd_pd(_mm256_set1_pd(-0.0), x, y)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f131(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_ceil_pd(_mm256_fnmadd_pd(_mm256_set1_pd(-0.0), x, y)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f132(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_round_pd(_mm256_fnmadd_pd(_mm256_set1_pd(-0.0), x, y), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f133(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_permute_pd(_mm256_fnmadd_pd(_mm256_set1_pd(-0.0), x, y), 0x5); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f134(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_permute_pd(_mm256_fnmadd_pd(_mm256_set1_pd(-0.0), x, y), 0xa); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f135(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_permute_pd(_mm256_fnmadd_pd(_mm256_set1_pd(-0.0), x, y), 0x3); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f136(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_sqrt_pd(_mm256_fnmadd_pd(x, y, _mm256_set1_pd(1.0))); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f137(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_xor_pd(_mm256_fnmadd_pd(x, y, _mm256_set1_pd(1.0)), _mm256_set1_pd(-0.0)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f138(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_andnot_pd(_mm256_set1_pd(-0.0), _mm256_fnmadd_pd(x, y, _mm256_set1_pd(1.0))); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f139(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_sub_pd(_mm256_setzero_pd(), _mm256_fnmadd_pd(x, y, _mm256_set1_pd(1.0))); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f140(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_mul_pd(_mm256_fnmadd_pd(x, y, _mm256_set1_pd(1.0)), _mm256_set1_pd(-1.0)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f141(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_floor_pd(_mm256_fnmadd_pd(x, y, _mm256_set1_pd(1.0))); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f142(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_ceil_pd(_mm256_fnmadd_pd(x, y, _mm256_set1_pd(1.0))); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f143(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_round_pd(_mm256_fnmadd_pd(x, y, _mm256_set1_pd(1.0)), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f144(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_permute_pd(_mm256_fnmadd_pd(x, y, _mm256_set1_pd(1.0)), 0x5); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f145(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_permute_pd(_mm256_fnmadd_pd(x, y, _mm256_set1_pd(1.0)), 0xa); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f146(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_permute_pd(_mm256_fnmadd_pd(x, y, _mm256_set1_pd(1.0)), 0x3); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f147(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_sqrt_pd(_mm256_fnmadd_pd(x, _mm256_set1_pd(1.0), y)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f148(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_xor_pd(_mm256_fnmadd_pd(x, _mm256_set1_pd(1.0), y), _mm256_set1_pd(-0.0)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f149(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_andnot_pd(_mm256_set1_pd(-0.0), _mm256_fnmadd_pd(x, _mm256_set1_pd(1.0), y)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f150(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_sub_pd(_mm256_setzero_pd(), _mm256_fnmadd_pd(x, _mm256_set1_pd(1.0), y)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f151(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_mul_pd(_mm256_fnmadd_pd(x, _mm256_set1_pd(1.0), y), _mm256_set1_pd(-1.0)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f152(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_floor_pd(_mm256_fnmadd_pd(x, _mm256_set1_pd(1.0), y)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f153(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_ceil_pd(_mm256_fnmadd_pd(x, _mm256_set1_pd(1.0), y)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f154(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_round_pd(_mm256_fnmadd_pd(x, _mm256_set1_pd(1.0), y), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f155(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_permute_pd(_mm256_fnmadd_pd(x, _mm256_set1_pd(1.0), y), 0x5); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f156(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_permute_pd(_mm256_fnmadd_pd(x, _mm256_set1_pd(1.0), y), 0xa); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f157(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_permute_pd(_mm256_fnmadd_pd(x, _mm256_set1_pd(1.0), y), 0x3); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f158(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_sqrt_pd(_mm256_fnmadd_pd(_mm256_set1_pd(1.0), x, y)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f159(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_xor_pd(_mm256_fnmadd_pd(_mm256_set1_pd(1.0), x, y), _mm256_set1_pd(-0.0)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f160(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_andnot_pd(_mm256_set1_pd(-0.0), _mm256_fnmadd_pd(_mm256_set1_pd(1.0), x, y)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f161(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_sub_pd(_mm256_setzero_pd(), _mm256_fnmadd_pd(_mm256_set1_pd(1.0), x, y)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f162(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_mul_pd(_mm256_fnmadd_pd(_mm256_set1_pd(1.0), x, y), _mm256_set1_pd(-1.0)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f163(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_floor_pd(_mm256_fnmadd_pd(_mm256_set1_pd(1.0), x, y)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f164(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_ceil_pd(_mm256_fnmadd_pd(_mm256_set1_pd(1.0), x, y)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f165(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_round_pd(_mm256_fnmadd_pd(_mm256_set1_pd(1.0), x, y), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f166(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_permute_pd(_mm256_fnmadd_pd(_mm256_set1_pd(1.0), x, y), 0x5); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f167(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_permute_pd(_mm256_fnmadd_pd(_mm256_set1_pd(1.0), x, y), 0xa); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f168(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_permute_pd(_mm256_fnmadd_pd(_mm256_set1_pd(1.0), x, y), 0x3); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f169(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_sqrt_pd(_mm256_fnmadd_pd(x, y, _mm256_set1_pd(-1.0))); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f170(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_xor_pd(_mm256_fnmadd_pd(x, y, _mm256_set1_pd(-1.0)), _mm256_set1_pd(-0.0)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f171(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_andnot_pd(_mm256_set1_pd(-0.0), _mm256_fnmadd_pd(x, y, _mm256_set1_pd(-1.0))); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f172(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_sub_pd(_mm256_setzero_pd(), _mm256_fnmadd_pd(x, y, _mm256_set1_pd(-1.0))); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f173(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_mul_pd(_mm256_fnmadd_pd(x, y, _mm256_set1_pd(-1.0)), _mm256_set1_pd(-1.0)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f174(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_floor_pd(_mm256_fnmadd_pd(x, y, _mm256_set1_pd(-1.0))); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f175(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_ceil_pd(_mm256_fnmadd_pd(x, y, _mm256_set1_pd(-1.0))); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f176(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_round_pd(_mm256_fnmadd_pd(x, y, _mm256_set1_pd(-1.0)), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f177(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_permute_pd(_mm256_fnmadd_pd(x, y, _mm256_set1_pd(-1.0)), 0x5); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f178(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_permute_pd(_mm256_fnmadd_pd(x, y, _mm256_set1_pd(-1.0)), 0xa); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f179(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_permute_pd(_mm256_fnmadd_pd(x, y, _mm256_set1_pd(-1.0)), 0x3); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f180(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_sqrt_pd(_mm256_fnmadd_pd(x, _mm256_set1_pd(-1.0), y)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f181(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_xor_pd(_mm256_fnmadd_pd(x, _mm256_set1_pd(-1.0), y), _mm256_set1_pd(-0.0)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f182(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_andnot_pd(_mm256_set1_pd(-0.0), _mm256_fnmadd_pd(x, _mm256_set1_pd(-1.0), y)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f183(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_sub_pd(_mm256_setzero_pd(), _mm256_fnmadd_pd(x, _mm256_set1_pd(-1.0), y)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f184(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_mul_pd(_mm256_fnmadd_pd(x, _mm256_set1_pd(-1.0), y), _mm256_set1_pd(-1.0)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f185(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_floor_pd(_mm256_fnmadd_pd(x, _mm256_set1_pd(-1.0), y)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f186(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_ceil_pd(_mm256_fnmadd_pd(x, _mm256_set1_pd(-1.0), y)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f187(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_round_pd(_mm256_fnmadd_pd(x, _mm256_set1_pd(-1.0), y), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f188(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_permute_pd(_mm256_fnmadd_pd(x, _mm256_set1_pd(-1.0), y), 0x5); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f189(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_permute_pd(_mm256_fnmadd_pd(x, _mm256_set1_pd(-1.0), y), 0xa); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f190(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_permute_pd(_mm256_fnmadd_pd(x, _mm256_set1_pd(-1.0), y), 0x3); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f191(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_sqrt_pd(_mm256_fnmadd_pd(_mm256_set1_pd(-1.0), x, y)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f192(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_xor_pd(_mm256_fnmadd_pd(_mm256_set1_pd(-1.0), x, y), _mm256_set1_pd(-0.0)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f193(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_andnot_pd(_mm256_set1_pd(-0.0), _mm256_fnmadd_pd(_mm256_set1_pd(-1.0), x, y)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f194(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_sub_pd(_mm256_setzero_pd(), _mm256_fnmadd_pd(_mm256_set1_pd(-1.0), x, y)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f195(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_mul_pd(_mm256_fnmadd_pd(_mm256_set1_pd(-1.0), x, y), _mm256_set1_pd(-1.0)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f196(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_floor_pd(_mm256_fnmadd_pd(_mm256_set1_pd(-1.0), x, y)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f197(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_ceil_pd(_mm256_fnmadd_pd(_mm256_set1_pd(-1.0), x, y)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f198(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_round_pd(_mm256_fnmadd_pd(_mm256_set1_pd(-1.0), x, y), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f199(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_permute_pd(_mm256_fnmadd_pd(_mm256_set1_pd(-1.0), x, y), 0x5); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f200(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_permute_pd(_mm256_fnmadd_pd(_mm256_set1_pd(-1.0), x, y), 0xa); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f201(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_permute_pd(_mm256_fnmadd_pd(_mm256_set1_pd(-1.0), x, y), 0x3); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f202(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_sqrt_pd(_mm256_fnmadd_pd(x, y, _mm256_set1_pd(std::numeric_limits<double>::infinity()))); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f203(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_xor_pd(_mm256_fnmadd_pd(x, y, _mm256_set1_pd(std::numeric_limits<double>::infinity())), _mm256_set1_pd(-0.0)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f204(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_andnot_pd(_mm256_set1_pd(-0.0), _mm256_fnmadd_pd(x, y, _mm256_set1_pd(std::numeric_limits<double>::infinity()))); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f205(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_sub_pd(_mm256_setzero_pd(), _mm256_fnmadd_pd(x, y, _mm256_set1_pd(std::numeric_limits<double>::infinity()))); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f206(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_mul_pd(_mm256_fnmadd_pd(x, y, _mm256_set1_pd(std::numeric_limits<double>::infinity())), _mm256_set1_pd(-1.0)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f207(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_floor_pd(_mm256_fnmadd_pd(x, y, _mm256_set1_pd(std::numeric_limits<double>::infinity()))); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f208(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_ceil_pd(_mm256_fnmadd_pd(x, y, _mm256_set1_pd(std::numeric_limits<double>::infinity()))); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f209(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_round_pd(_mm256_fnmadd_pd(x, y, _mm256_set1_pd(std::numeric_limits<double>::infinity())), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f210(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_permute_pd(_mm256_fnmadd_pd(x, y, _mm256_set1_pd(std::numeric_limits<double>::infinity())), 0x5); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f211(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_permute_pd(_mm256_fnmadd_pd(x, y, _mm256_set1_pd(std::numeric_limits<double>::infinity())), 0xa); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f212(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_permute_pd(_mm256_fnmadd_pd(x, y, _mm256_set1_pd(std::numeric_limits<double>::infinity())), 0x3); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f213(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_sqrt_pd(_mm256_fnmadd_pd(x, _mm256_set1_pd(std::numeric_limits<double>::infinity()), y)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f214(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_xor_pd(_mm256_fnmadd_pd(x, _mm256_set1_pd(std::numeric_limits<double>::infinity()), y), _mm256_set1_pd(-0.0)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f215(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_andnot_pd(_mm256_set1_pd(-0.0), _mm256_fnmadd_pd(x, _mm256_set1_pd(std::numeric_limits<double>::infinity()), y)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f216(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_sub_pd(_mm256_setzero_pd(), _mm256_fnmadd_pd(x, _mm256_set1_pd(std::numeric_limits<double>::infinity()), y)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f217(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_mul_pd(_mm256_fnmadd_pd(x, _mm256_set1_pd(std::numeric_limits<double>::infinity()), y), _mm256_set1_pd(-1.0)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f218(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_floor_pd(_mm256_fnmadd_pd(x, _mm256_set1_pd(std::numeric_limits<double>::infinity()), y)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f219(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_ceil_pd(_mm256_fnmadd_pd(x, _mm256_set1_pd(std::numeric_limits<double>::infinity()), y)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f220(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_round_pd(_mm256_fnmadd_pd(x, _mm256_set1_pd(std::numeric_limits<double>::infinity()), y), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f221(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_permute_pd(_mm256_fnmadd_pd(x, _mm256_set1_pd(std::numeric_limits<double>::infinity()), y), 0x5); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f222(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_permute_pd(_mm256_fnmadd_pd(x, _mm256_set1_pd(std::numeric_limits<double>::infinity()), y), 0xa); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f223(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_permute_pd(_mm256_fnmadd_pd(x, _mm256_set1_pd(std::numeric_limits<double>::infinity()), y), 0x3); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f224(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_sqrt_pd(_mm256_fnmadd_pd(_mm256_set1_pd(std::numeric_limits<double>::infinity()), x, y)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f225(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_xor_pd(_mm256_fnmadd_pd(_mm256_set1_pd(std::numeric_limits<double>::infinity()), x, y), _mm256_set1_pd(-0.0)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f226(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_andnot_pd(_mm256_set1_pd(-0.0), _mm256_fnmadd_pd(_mm256_set1_pd(std::numeric_limits<double>::infinity()), x, y)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f227(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_sub_pd(_mm256_setzero_pd(), _mm256_fnmadd_pd(_mm256_set1_pd(std::numeric_limits<double>::infinity()), x, y)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f228(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_mul_pd(_mm256_fnmadd_pd(_mm256_set1_pd(std::numeric_limits<double>::infinity()), x, y), _mm256_set1_pd(-1.0)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f229(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_floor_pd(_mm256_fnmadd_pd(_mm256_set1_pd(std::numeric_limits<double>::infinity()), x, y)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f230(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_ceil_pd(_mm256_fnmadd_pd(_mm256_set1_pd(std::numeric_limits<double>::infinity()), x, y)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f231(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_round_pd(_mm256_fnmadd_pd(_mm256_set1_pd(std::numeric_limits<double>::infinity()), x, y), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f232(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_permute_pd(_mm256_fnmadd_pd(_mm256_set1_pd(std::numeric_limits<double>::infinity()), x, y), 0x5); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f233(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_permute_pd(_mm256_fnmadd_pd(_mm256_set1_pd(std::numeric_limits<double>::infinity()), x, y), 0xa); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f234(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_permute_pd(_mm256_fnmadd_pd(_mm256_set1_pd(std::numeric_limits<double>::infinity()), x, y), 0x3); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f235(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_sqrt_pd(_mm256_fnmadd_pd(x, y, _mm256_set1_pd(std::numeric_limits<double>::quiet_NaN()))); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f236(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_xor_pd(_mm256_fnmadd_pd(x, y, _mm256_set1_pd(std::numeric_limits<double>::quiet_NaN())), _mm256_set1_pd(-0.0)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f237(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_andnot_pd(_mm256_set1_pd(-0.0), _mm256_fnmadd_pd(x, y, _mm256_set1_pd(std::numeric_limits<double>::quiet_NaN()))); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f238(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_sub_pd(_mm256_setzero_pd(), _mm256_fnmadd_pd(x, y, _mm256_set1_pd(std::numeric_limits<double>::quiet_NaN()))); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f239(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_mul_pd(_mm256_fnmadd_pd(x, y, _mm256_set1_pd(std::numeric_limits<double>::quiet_NaN())), _mm256_set1_pd(-1.0)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f240(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_floor_pd(_mm256_fnmadd_pd(x, y, _mm256_set1_pd(std::numeric_limits<double>::quiet_NaN()))); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f241(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_ceil_pd(_mm256_fnmadd_pd(x, y, _mm256_set1_pd(std::numeric_limits<double>::quiet_NaN()))); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f242(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_round_pd(_mm256_fnmadd_pd(x, y, _mm256_set1_pd(std::numeric_limits<double>::quiet_NaN())), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f243(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_permute_pd(_mm256_fnmadd_pd(x, y, _mm256_set1_pd(std::numeric_limits<double>::quiet_NaN())), 0x5); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f244(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_permute_pd(_mm256_fnmadd_pd(x, y, _mm256_set1_pd(std::numeric_limits<double>::quiet_NaN())), 0xa); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f245(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_permute_pd(_mm256_fnmadd_pd(x, y, _mm256_set1_pd(std::numeric_limits<double>::quiet_NaN())), 0x3); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f246(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_sqrt_pd(_mm256_fnmadd_pd(x, _mm256_set1_pd(std::numeric_limits<double>::quiet_NaN()), y)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f247(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_xor_pd(_mm256_fnmadd_pd(x, _mm256_set1_pd(std::numeric_limits<double>::quiet_NaN()), y), _mm256_set1_pd(-0.0)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f248(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_andnot_pd(_mm256_set1_pd(-0.0), _mm256_fnmadd_pd(x, _mm256_set1_pd(std::numeric_limits<double>::quiet_NaN()), y)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f249(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_sub_pd(_mm256_setzero_pd(), _mm256_fnmadd_pd(x, _mm256_set1_pd(std::numeric_limits<double>::quiet_NaN()), y)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f250(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_mul_pd(_mm256_fnmadd_pd(x, _mm256_set1_pd(std::numeric_limits<double>::quiet_NaN()), y), _mm256_set1_pd(-1.0)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f251(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_floor_pd(_mm256_fnmadd_pd(x, _mm256_set1_pd(std::numeric_limits<double>::quiet_NaN()), y)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f252(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_ceil_pd(_mm256_fnmadd_pd(x, _mm256_set1_pd(std::numeric_limits<double>::quiet_NaN()), y)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f253(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_round_pd(_mm256_fnmadd_pd(x, _mm256_set1_pd(std::numeric_limits<double>::quiet_NaN()), y), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f254(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_permute_pd(_mm256_fnmadd_pd(x, _mm256_set1_pd(std::numeric_limits<double>::quiet_NaN()), y), 0x5); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f255(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_permute_pd(_mm256_fnmadd_pd(x, _mm256_set1_pd(std::numeric_limits<double>::quiet_NaN()), y), 0xa); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f256(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_permute_pd(_mm256_fnmadd_pd(x, _mm256_set1_pd(std::numeric_limits<double>::quiet_NaN()), y), 0x3); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f257(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_sqrt_pd(_mm256_fnmadd_pd(_mm256_set1_pd(std::numeric_limits<double>::quiet_NaN()), x, y)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f258(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_xor_pd(_mm256_fnmadd_pd(_mm256_set1_pd(std::numeric_limits<double>::quiet_NaN()), x, y), _mm256_set1_pd(-0.0)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f259(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_andnot_pd(_mm256_set1_pd(-0.0), _mm256_fnmadd_pd(_mm256_set1_pd(std::numeric_limits<double>::quiet_NaN()), x, y)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f260(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_sub_pd(_mm256_setzero_pd(), _mm256_fnmadd_pd(_mm256_set1_pd(std::numeric_limits<double>::quiet_NaN()), x, y)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f261(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_mul_pd(_mm256_fnmadd_pd(_mm256_set1_pd(std::numeric_limits<double>::quiet_NaN()), x, y), _mm256_set1_pd(-1.0)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f262(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_floor_pd(_mm256_fnmadd_pd(_mm256_set1_pd(std::numeric_limits<double>::quiet_NaN()), x, y)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f263(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_ceil_pd(_mm256_fnmadd_pd(_mm256_set1_pd(std::numeric_limits<double>::quiet_NaN()), x, y)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f264(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_round_pd(_mm256_fnmadd_pd(_mm256_set1_pd(std::numeric_limits<double>::quiet_NaN()), x, y), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f265(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_permute_pd(_mm256_fnmadd_pd(_mm256_set1_pd(std::numeric_limits<double>::quiet_NaN()), x, y), 0x5); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f266(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_permute_pd(_mm256_fnmadd_pd(_mm256_set1_pd(std::numeric_limits<double>::quiet_NaN()), x, y), 0xa); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f267(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_permute_pd(_mm256_fnmadd_pd(_mm256_set1_pd(std::numeric_limits<double>::quiet_NaN()), x, y), 0x3); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f268(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_sqrt_pd(_mm256_fnmadd_pd(x, y, x)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f269(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_xor_pd(_mm256_fnmadd_pd(x, y, x), _mm256_set1_pd(-0.0)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f270(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_andnot_pd(_mm256_set1_pd(-0.0), _mm256_fnmadd_pd(x, y, x)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f271(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_sub_pd(_mm256_setzero_pd(), _mm256_fnmadd_pd(x, y, x)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f272(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_mul_pd(_mm256_fnmadd_pd(x, y, x), _mm256_set1_pd(-1.0)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f273(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_floor_pd(_mm256_fnmadd_pd(x, y, x)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f274(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_ceil_pd(_mm256_fnmadd_pd(x, y, x)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f275(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_round_pd(_mm256_fnmadd_pd(x, y, x), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f276(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_permute_pd(_mm256_fnmadd_pd(x, y, x), 0x5); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f277(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_permute_pd(_mm256_fnmadd_pd(x, y, x), 0xa); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f278(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_permute_pd(_mm256_fnmadd_pd(x, y, x), 0x3); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f279(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_sqrt_pd(_mm256_fnmadd_pd(x, x, y)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f280(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_xor_pd(_mm256_fnmadd_pd(x, x, y), _mm256_set1_pd(-0.0)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f281(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_andnot_pd(_mm256_set1_pd(-0.0), _mm256_fnmadd_pd(x, x, y)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f282(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_sub_pd(_mm256_setzero_pd(), _mm256_fnmadd_pd(x, x, y)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f283(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_mul_pd(_mm256_fnmadd_pd(x, x, y), _mm256_set1_pd(-1.0)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f284(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_floor_pd(_mm256_fnmadd_pd(x, x, y)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f285(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_ceil_pd(_mm256_fnmadd_pd(x, x, y)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f286(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_round_pd(_mm256_fnmadd_pd(x, x, y), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f287(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_permute_pd(_mm256_fnmadd_pd(x, x, y), 0x5); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f288(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_permute_pd(_mm256_fnmadd_pd(x, x, y), 0xa); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f289(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_permute_pd(_mm256_fnmadd_pd(x, x, y), 0x3); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f290(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_sqrt_pd(_mm256_fnmadd_pd(x, y, _mm256_mul_pd(x, y))); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f291(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_xor_pd(_mm256_fnmadd_pd(x, y, _mm256_mul_pd(x, y)), _mm256_set1_pd(-0.0)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f292(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_andnot_pd(_mm256_set1_pd(-0.0), _mm256_fnmadd_pd(x, y, _mm256_mul_pd(x, y))); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f293(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_sub_pd(_mm256_setzero_pd(), _mm256_fnmadd_pd(x, y, _mm256_mul_pd(x, y))); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f294(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_mul_pd(_mm256_fnmadd_pd(x, y, _mm256_mul_pd(x, y)), _mm256_set1_pd(-1.0)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f295(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_floor_pd(_mm256_fnmadd_pd(x, y, _mm256_mul_pd(x, y))); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f296(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_ceil_pd(_mm256_fnmadd_pd(x, y, _mm256_mul_pd(x, y))); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f297(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_round_pd(_mm256_fnmadd_pd(x, y, _mm256_mul_pd(x, y)), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f298(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_permute_pd(_mm256_fnmadd_pd(x, y, _mm256_mul_pd(x, y)), 0x5); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f299(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_permute_pd(_mm256_fnmadd_pd(x, y, _mm256_mul_pd(x, y)), 0xa); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f300(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_permute_pd(_mm256_fnmadd_pd(x, y, _mm256_mul_pd(x, y)), 0x3); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f301(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_sqrt_pd(_mm256_fnmsub_pd(x, y, _mm256_setzero_pd())); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f302(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_xor_pd(_mm256_fnmsub_pd(x, y, _mm256_setzero_pd()), _mm256_set1_pd(-0.0)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f303(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_andnot_pd(_mm256_set1_pd(-0.0), _mm256_fnmsub_pd(x, y, _mm256_setzero_pd())); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f304(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_sub_pd(_mm256_setzero_pd(), _mm256_fnmsub_pd(x, y, _mm256_setzero_pd())); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f305(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_mul_pd(_mm256_fnmsub_pd(x, y, _mm256_setzero_pd()), _mm256_set1_pd(-1.0)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f306(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_floor_pd(_mm256_fnmsub_pd(x, y, _mm256_setzero_pd())); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f307(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_ceil_pd(_mm256_fnmsub_pd(x, y, _mm256_setzero_pd())); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f308(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_round_pd(_mm256_fnmsub_pd(x, y, _mm256_setzero_pd()), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f309(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_permute_pd(_mm256_fnmsub_pd(x, y, _mm256_setzero_pd()), 0x5); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f310(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_permute_pd(_mm256_fnmsub_pd(x, y, _mm256_setzero_pd()), 0xa); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f311(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_permute_pd(_mm256_fnmsub_pd(x, y, _mm256_setzero_pd()), 0x3); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f312(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_sqrt_pd(_mm256_fnmsub_pd(x, _mm256_setzero_pd(), y)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f313(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_xor_pd(_mm256_fnmsub_pd(x, _mm256_setzero_pd(), y), _mm256_set1_pd(-0.0)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f314(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_andnot_pd(_mm256_set1_pd(-0.0), _mm256_fnmsub_pd(x, _mm256_setzero_pd(), y)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f315(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_sub_pd(_mm256_setzero_pd(), _mm256_fnmsub_pd(x, _mm256_setzero_pd(), y)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f316(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_mul_pd(_mm256_fnmsub_pd(x, _mm256_setzero_pd(), y), _mm256_set1_pd(-1.0)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f317(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_floor_pd(_mm256_fnmsub_pd(x, _mm256_setzero_pd(), y)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f318(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_ceil_pd(_mm256_fnmsub_pd(x, _mm256_setzero_pd(), y)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f319(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_round_pd(_mm256_fnmsub_pd(x, _mm256_setzero_pd(), y), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f320(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_permute_pd(_mm256_fnmsub_pd(x, _mm256_setzero_pd(), y), 0x5); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f321(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_permute_pd(_mm256_fnmsub_pd(x, _mm256_setzero_pd(), y), 0xa); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f322(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_permute_pd(_mm256_fnmsub_pd(x, _mm256_setzero_pd(), y), 0x3); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f323(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_sqrt_pd(_mm256_fnmsub_pd(_mm256_setzero_pd(), x, y)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f324(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_xor_pd(_mm256_fnmsub_pd(_mm256_setzero_pd(), x, y), _mm256_set1_pd(-0.0)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f325(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_andnot_pd(_mm256_set1_pd(-0.0), _mm256_fnmsub_pd(_mm256_setzero_pd(), x, y)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f326(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_sub_pd(_mm256_setzero_pd(), _mm256_fnmsub_pd(_mm256_setzero_pd(), x, y)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f327(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_mul_pd(_mm256_fnmsub_pd(_mm256_setzero_pd(), x, y), _mm256_set1_pd(-1.0)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f328(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_floor_pd(_mm256_fnmsub_pd(_mm256_setzero_pd(), x, y)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f329(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_ceil_pd(_mm256_fnmsub_pd(_mm256_setzero_pd(), x, y)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f330(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_round_pd(_mm256_fnmsub_pd(_mm256_setzero_pd(), x, y), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f331(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_permute_pd(_mm256_fnmsub_pd(_mm256_setzero_pd(), x, y), 0x5); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f332(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_permute_pd(_mm256_fnmsub_pd(_mm256_setzero_pd(), x, y), 0xa); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f333(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_permute_pd(_mm256_fnmsub_pd(_mm256_setzero_pd(), x, y), 0x3); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f334(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_sqrt_pd(_mm256_fnmsub_pd(x, y, _mm256_set1_pd(-0.0))); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f335(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_xor_pd(_mm256_fnmsub_pd(x, y, _mm256_set1_pd(-0.0)), _mm256_set1_pd(-0.0)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f336(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_andnot_pd(_mm256_set1_pd(-0.0), _mm256_fnmsub_pd(x, y, _mm256_set1_pd(-0.0))); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f337(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_sub_pd(_mm256_setzero_pd(), _mm256_fnmsub_pd(x, y, _mm256_set1_pd(-0.0))); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f338(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_mul_pd(_mm256_fnmsub_pd(x, y, _mm256_set1_pd(-0.0)), _mm256_set1_pd(-1.0)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f339(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_floor_pd(_mm256_fnmsub_pd(x, y, _mm256_set1_pd(-0.0))); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f340(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_ceil_pd(_mm256_fnmsub_pd(x, y, _mm256_set1_pd(-0.0))); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f341(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_round_pd(_mm256_fnmsub_pd(x, y, _mm256_set1_pd(-0.0)), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f342(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_permute_pd(_mm256_fnmsub_pd(x, y, _mm256_set1_pd(-0.0)), 0x5); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f343(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_permute_pd(_mm256_fnmsub_pd(x, y, _mm256_set1_pd(-0.0)), 0xa); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f344(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_permute_pd(_mm256_fnmsub_pd(x, y, _mm256_set1_pd(-0.0)), 0x3); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f345(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_sqrt_pd(_mm256_fnmsub_pd(x, _mm256_set1_pd(-0.0), y)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f346(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_xor_pd(_mm256_fnmsub_pd(x, _mm256_set1_pd(-0.0), y), _mm256_set1_pd(-0.0)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f347(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_andnot_pd(_mm256_set1_pd(-0.0), _mm256_fnmsub_pd(x, _mm256_set1_pd(-0.0), y)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f348(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_sub_pd(_mm256_setzero_pd(), _mm256_fnmsub_pd(x, _mm256_set1_pd(-0.0), y)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f349(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_mul_pd(_mm256_fnmsub_pd(x, _mm256_set1_pd(-0.0), y), _mm256_set1_pd(-1.0)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f350(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_floor_pd(_mm256_fnmsub_pd(x, _mm256_set1_pd(-0.0), y)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f351(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_ceil_pd(_mm256_fnmsub_pd(x, _mm256_set1_pd(-0.0), y)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f352(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_round_pd(_mm256_fnmsub_pd(x, _mm256_set1_pd(-0.0), y), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f353(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_permute_pd(_mm256_fnmsub_pd(x, _mm256_set1_pd(-0.0), y), 0x5); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f354(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_permute_pd(_mm256_fnmsub_pd(x, _mm256_set1_pd(-0.0), y), 0xa); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f355(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_permute_pd(_mm256_fnmsub_pd(x, _mm256_set1_pd(-0.0), y), 0x3); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f356(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_sqrt_pd(_mm256_fnmsub_pd(_mm256_set1_pd(-0.0), x, y)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f357(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_xor_pd(_mm256_fnmsub_pd(_mm256_set1_pd(-0.0), x, y), _mm256_set1_pd(-0.0)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f358(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_andnot_pd(_mm256_set1_pd(-0.0), _mm256_fnmsub_pd(_mm256_set1_pd(-0.0), x, y)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f359(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_sub_pd(_mm256_setzero_pd(), _mm256_fnmsub_pd(_mm256_set1_pd(-0.0), x, y)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f360(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_mul_pd(_mm256_fnmsub_pd(_mm256_set1_pd(-0.0), x, y), _mm256_set1_pd(-1.0)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f361(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_floor_pd(_mm256_fnmsub_pd(_mm256_set1_pd(-0.0), x, y)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f362(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_ceil_pd(_mm256_fnmsub_pd(_mm256_set1_pd(-0.0), x, y)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f363(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_round_pd(_mm256_fnmsub_pd(_mm256_set1_pd(-0.0), x, y), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f364(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_permute_pd(_mm256_fnmsub_pd(_mm256_set1_pd(-0.0), x, y), 0x5); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f365(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_permute_pd(_mm256_fnmsub_pd(_mm256_set1_pd(-0.0), x, y), 0xa); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f366(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_permute_pd(_mm256_fnmsub_pd(_mm256_set1_pd(-0.0), x, y), 0x3); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f367(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_sqrt_pd(_mm256_fnmsub_pd(x, y, _mm256_set1_pd(1.0))); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f368(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_xor_pd(_mm256_fnmsub_pd(x, y, _mm256_set1_pd(1.0)), _mm256_set1_pd(-0.0)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f369(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_andnot_pd(_mm256_set1_pd(-0.0), _mm256_fnmsub_pd(x, y, _mm256_set1_pd(1.0))); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f370(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_sub_pd(_mm256_setzero_pd(), _mm256_fnmsub_pd(x, y, _mm256_set1_pd(1.0))); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f371(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_mul_pd(_mm256_fnmsub_pd(x, y, _mm256_set1_pd(1.0)), _mm256_set1_pd(-1.0)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f372(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_floor_pd(_mm256_fnmsub_pd(x, y, _mm256_set1_pd(1.0))); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f373(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_ceil_pd(_mm256_fnmsub_pd(x, y, _mm256_set1_pd(1.0))); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f374(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_round_pd(_mm256_fnmsub_pd(x, y, _mm256_set1_pd(1.0)), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f375(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_permute_pd(_mm256_fnmsub_pd(x, y, _mm256_set1_pd(1.0)), 0x5); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f376(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_permute_pd(_mm256_fnmsub_pd(x, y, _mm256_set1_pd(1.0)), 0xa); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f377(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_permute_pd(_mm256_fnmsub_pd(x, y, _mm256_set1_pd(1.0)), 0x3); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f378(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_sqrt_pd(_mm256_fnmsub_pd(x, _mm256_set1_pd(1.0), y)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f379(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_xor_pd(_mm256_fnmsub_pd(x, _mm256_set1_pd(1.0), y), _mm256_set1_pd(-0.0)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f380(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_andnot_pd(_mm256_set1_pd(-0.0), _mm256_fnmsub_pd(x, _mm256_set1_pd(1.0), y)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f381(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_sub_pd(_mm256_setzero_pd(), _mm256_fnmsub_pd(x, _mm256_set1_pd(1.0), y)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f382(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_mul_pd(_mm256_fnmsub_pd(x, _mm256_set1_pd(1.0), y), _mm256_set1_pd(-1.0)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f383(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_floor_pd(_mm256_fnmsub_pd(x, _mm256_set1_pd(1.0), y)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f384(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_ceil_pd(_mm256_fnmsub_pd(x, _mm256_set1_pd(1.0), y)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f385(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_round_pd(_mm256_fnmsub_pd(x, _mm256_set1_pd(1.0), y), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f386(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_permute_pd(_mm256_fnmsub_pd(x, _mm256_set1_pd(1.0), y), 0x5); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f387(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_permute_pd(_mm256_fnmsub_pd(x, _mm256_set1_pd(1.0), y), 0xa); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f388(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_permute_pd(_mm256_fnmsub_pd(x, _mm256_set1_pd(1.0), y), 0x3); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f389(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_sqrt_pd(_mm256_fnmsub_pd(_mm256_set1_pd(1.0), x, y)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f390(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_xor_pd(_mm256_fnmsub_pd(_mm256_set1_pd(1.0), x, y), _mm256_set1_pd(-0.0)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f391(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_andnot_pd(_mm256_set1_pd(-0.0), _mm256_fnmsub_pd(_mm256_set1_pd(1.0), x, y)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f392(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_sub_pd(_mm256_setzero_pd(), _mm256_fnmsub_pd(_mm256_set1_pd(1.0), x, y)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f393(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_mul_pd(_mm256_fnmsub_pd(_mm256_set1_pd(1.0), x, y), _mm256_set1_pd(-1.0)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f394(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_floor_pd(_mm256_fnmsub_pd(_mm256_set1_pd(1.0), x, y)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f395(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_ceil_pd(_mm256_fnmsub_pd(_mm256_set1_pd(1.0), x, y)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f396(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_round_pd(_mm256_fnmsub_pd(_mm256_set1_pd(1.0), x, y), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f397(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_permute_pd(_mm256_fnmsub_pd(_mm256_set1_pd(1.0), x, y), 0x5); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f398(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_permute_pd(_mm256_fnmsub_pd(_mm256_set1_pd(1.0), x, y), 0xa); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f399(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_permute_pd(_mm256_fnmsub_pd(_mm256_set1_pd(1.0), x, y), 0x3); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f400(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_sqrt_pd(_mm256_fnmsub_pd(x, y, _mm256_set1_pd(-1.0))); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f401(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_xor_pd(_mm256_fnmsub_pd(x, y, _mm256_set1_pd(-1.0)), _mm256_set1_pd(-0.0)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f402(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_andnot_pd(_mm256_set1_pd(-0.0), _mm256_fnmsub_pd(x, y, _mm256_set1_pd(-1.0))); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f403(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_sub_pd(_mm256_setzero_pd(), _mm256_fnmsub_pd(x, y, _mm256_set1_pd(-1.0))); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f404(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_mul_pd(_mm256_fnmsub_pd(x, y, _mm256_set1_pd(-1.0)), _mm256_set1_pd(-1.0)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f405(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_floor_pd(_mm256_fnmsub_pd(x, y, _mm256_set1_pd(-1.0))); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f406(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_ceil_pd(_mm256_fnmsub_pd(x, y, _mm256_set1_pd(-1.0))); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f407(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_round_pd(_mm256_fnmsub_pd(x, y, _mm256_set1_pd(-1.0)), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f408(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_permute_pd(_mm256_fnmsub_pd(x, y, _mm256_set1_pd(-1.0)), 0x5); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f409(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_permute_pd(_mm256_fnmsub_pd(x, y, _mm256_set1_pd(-1.0)), 0xa); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f410(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_permute_pd(_mm256_fnmsub_pd(x, y, _mm256_set1_pd(-1.0)), 0x3); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f411(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_sqrt_pd(_mm256_fnmsub_pd(x, _mm256_set1_pd(-1.0), y)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f412(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_xor_pd(_mm256_fnmsub_pd(x, _mm256_set1_pd(-1.0), y), _mm256_set1_pd(-0.0)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f413(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_andnot_pd(_mm256_set1_pd(-0.0), _mm256_fnmsub_pd(x, _mm256_set1_pd(-1.0), y)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f414(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_sub_pd(_mm256_setzero_pd(), _mm256_fnmsub_pd(x, _mm256_set1_pd(-1.0), y)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f415(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_mul_pd(_mm256_fnmsub_pd(x, _mm256_set1_pd(-1.0), y), _mm256_set1_pd(-1.0)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f416(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_floor_pd(_mm256_fnmsub_pd(x, _mm256_set1_pd(-1.0), y)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f417(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_ceil_pd(_mm256_fnmsub_pd(x, _mm256_set1_pd(-1.0), y)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f418(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_round_pd(_mm256_fnmsub_pd(x, _mm256_set1_pd(-1.0), y), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f419(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_permute_pd(_mm256_fnmsub_pd(x, _mm256_set1_pd(-1.0), y), 0x5); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f420(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_permute_pd(_mm256_fnmsub_pd(x, _mm256_set1_pd(-1.0), y), 0xa); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f421(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_permute_pd(_mm256_fnmsub_pd(x, _mm256_set1_pd(-1.0), y), 0x3); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f422(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_sqrt_pd(_mm256_fnmsub_pd(_mm256_set1_pd(-1.0), x, y)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f423(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_xor_pd(_mm256_fnmsub_pd(_mm256_set1_pd(-1.0), x, y), _mm256_set1_pd(-0.0)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f424(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_andnot_pd(_mm256_set1_pd(-0.0), _mm256_fnmsub_pd(_mm256_set1_pd(-1.0), x, y)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f425(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_sub_pd(_mm256_setzero_pd(), _mm256_fnmsub_pd(_mm256_set1_pd(-1.0), x, y)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f426(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_mul_pd(_mm256_fnmsub_pd(_mm256_set1_pd(-1.0), x, y), _mm256_set1_pd(-1.0)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f427(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_floor_pd(_mm256_fnmsub_pd(_mm256_set1_pd(-1.0), x, y)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f428(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_ceil_pd(_mm256_fnmsub_pd(_mm256_set1_pd(-1.0), x, y)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f429(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_round_pd(_mm256_fnmsub_pd(_mm256_set1_pd(-1.0), x, y), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f430(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_permute_pd(_mm256_fnmsub_pd(_mm256_set1_pd(-1.0), x, y), 0x5); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f431(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_permute_pd(_mm256_fnmsub_pd(_mm256_set1_pd(-1.0), x, y), 0xa); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f432(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_permute_pd(_mm256_fnmsub_pd(_mm256_set1_pd(-1.0), x, y), 0x3); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f433(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_sqrt_pd(_mm256_fnmsub_pd(x, y, _mm256_set1_pd(std::numeric_limits<double>::infinity()))); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f434(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_xor_pd(_mm256_fnmsub_pd(x, y, _mm256_set1_pd(std::numeric_limits<double>::infinity())), _mm256_set1_pd(-0.0)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f435(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_andnot_pd(_mm256_set1_pd(-0.0), _mm256_fnmsub_pd(x, y, _mm256_set1_pd(std::numeric_limits<double>::infinity()))); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f436(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_sub_pd(_mm256_setzero_pd(), _mm256_fnmsub_pd(x, y, _mm256_set1_pd(std::numeric_limits<double>::infinity()))); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f437(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_mul_pd(_mm256_fnmsub_pd(x, y, _mm256_set1_pd(std::numeric_limits<double>::infinity())), _mm256_set1_pd(-1.0)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f438(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_floor_pd(_mm256_fnmsub_pd(x, y, _mm256_set1_pd(std::numeric_limits<double>::infinity()))); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f439(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_ceil_pd(_mm256_fnmsub_pd(x, y, _mm256_set1_pd(std::numeric_limits<double>::infinity()))); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f440(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_round_pd(_mm256_fnmsub_pd(x, y, _mm256_set1_pd(std::numeric_limits<double>::infinity())), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f441(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_permute_pd(_mm256_fnmsub_pd(x, y, _mm256_set1_pd(std::numeric_limits<double>::infinity())), 0x5); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f442(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_permute_pd(_mm256_fnmsub_pd(x, y, _mm256_set1_pd(std::numeric_limits<double>::infinity())), 0xa); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f443(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_permute_pd(_mm256_fnmsub_pd(x, y, _mm256_set1_pd(std::numeric_limits<double>::infinity())), 0x3); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f444(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_sqrt_pd(_mm256_fnmsub_pd(x, _mm256_set1_pd(std::numeric_limits<double>::infinity()), y)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f445(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_xor_pd(_mm256_fnmsub_pd(x, _mm256_set1_pd(std::numeric_limits<double>::infinity()), y), _mm256_set1_pd(-0.0)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f446(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_andnot_pd(_mm256_set1_pd(-0.0), _mm256_fnmsub_pd(x, _mm256_set1_pd(std::numeric_limits<double>::infinity()), y)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f447(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_sub_pd(_mm256_setzero_pd(), _mm256_fnmsub_pd(x, _mm256_set1_pd(std::numeric_limits<double>::infinity()), y)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f448(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_mul_pd(_mm256_fnmsub_pd(x, _mm256_set1_pd(std::numeric_limits<double>::infinity()), y), _mm256_set1_pd(-1.0)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f449(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_floor_pd(_mm256_fnmsub_pd(x, _mm256_set1_pd(std::numeric_limits<double>::infinity()), y)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f450(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_ceil_pd(_mm256_fnmsub_pd(x, _mm256_set1_pd(std::numeric_limits<double>::infinity()), y)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f451(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_round_pd(_mm256_fnmsub_pd(x, _mm256_set1_pd(std::numeric_limits<double>::infinity()), y), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f452(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_permute_pd(_mm256_fnmsub_pd(x, _mm256_set1_pd(std::numeric_limits<double>::infinity()), y), 0x5); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f453(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_permute_pd(_mm256_fnmsub_pd(x, _mm256_set1_pd(std::numeric_limits<double>::infinity()), y), 0xa); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f454(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_permute_pd(_mm256_fnmsub_pd(x, _mm256_set1_pd(std::numeric_limits<double>::infinity()), y), 0x3); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f455(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_sqrt_pd(_mm256_fnmsub_pd(_mm256_set1_pd(std::numeric_limits<double>::infinity()), x, y)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f456(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_xor_pd(_mm256_fnmsub_pd(_mm256_set1_pd(std::numeric_limits<double>::infinity()), x, y), _mm256_set1_pd(-0.0)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f457(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_andnot_pd(_mm256_set1_pd(-0.0), _mm256_fnmsub_pd(_mm256_set1_pd(std::numeric_limits<double>::infinity()), x, y)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f458(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_sub_pd(_mm256_setzero_pd(), _mm256_fnmsub_pd(_mm256_set1_pd(std::numeric_limits<double>::infinity()), x, y)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f459(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_mul_pd(_mm256_fnmsub_pd(_mm256_set1_pd(std::numeric_limits<double>::infinity()), x, y), _mm256_set1_pd(-1.0)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f460(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_floor_pd(_mm256_fnmsub_pd(_mm256_set1_pd(std::numeric_limits<double>::infinity()), x, y)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f461(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_ceil_pd(_mm256_fnmsub_pd(_mm256_set1_pd(std::numeric_limits<double>::infinity()), x, y)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f462(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_round_pd(_mm256_fnmsub_pd(_mm256_set1_pd(std::numeric_limits<double>::infinity()), x, y), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f463(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_permute_pd(_mm256_fnmsub_pd(_mm256_set1_pd(std::numeric_limits<double>::infinity()), x, y), 0x5); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f464(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_permute_pd(_mm256_fnmsub_pd(_mm256_set1_pd(std::numeric_limits<double>::infinity()), x, y), 0xa); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f465(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_permute_pd(_mm256_fnmsub_pd(_mm256_set1_pd(std::numeric_limits<double>::infinity()), x, y), 0x3); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f466(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_sqrt_pd(_mm256_fnmsub_pd(x, y, _mm256_set1_pd(std::numeric_limits<double>::quiet_NaN()))); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f467(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_xor_pd(_mm256_fnmsub_pd(x, y, _mm256_set1_pd(std::numeric_limits<double>::quiet_NaN())), _mm256_set1_pd(-0.0)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f468(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_andnot_pd(_mm256_set1_pd(-0.0), _mm256_fnmsub_pd(x, y, _mm256_set1_pd(std::numeric_limits<double>::quiet_NaN()))); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f469(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_sub_pd(_mm256_setzero_pd(), _mm256_fnmsub_pd(x, y, _mm256_set1_pd(std::numeric_limits<double>::quiet_NaN()))); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f470(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_mul_pd(_mm256_fnmsub_pd(x, y, _mm256_set1_pd(std::numeric_limits<double>::quiet_NaN())), _mm256_set1_pd(-1.0)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f471(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_floor_pd(_mm256_fnmsub_pd(x, y, _mm256_set1_pd(std::numeric_limits<double>::quiet_NaN()))); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f472(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_ceil_pd(_mm256_fnmsub_pd(x, y, _mm256_set1_pd(std::numeric_limits<double>::quiet_NaN()))); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f473(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_round_pd(_mm256_fnmsub_pd(x, y, _mm256_set1_pd(std::numeric_limits<double>::quiet_NaN())), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f474(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_permute_pd(_mm256_fnmsub_pd(x, y, _mm256_set1_pd(std::numeric_limits<double>::quiet_NaN())), 0x5); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f475(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_permute_pd(_mm256_fnmsub_pd(x, y, _mm256_set1_pd(std::numeric_limits<double>::quiet_NaN())), 0xa); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f476(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_permute_pd(_mm256_fnmsub_pd(x, y, _mm256_set1_pd(std::numeric_limits<double>::quiet_NaN())), 0x3); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f477(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_sqrt_pd(_mm256_fnmsub_pd(x, _mm256_set1_pd(std::numeric_limits<double>::quiet_NaN()), y)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f478(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_xor_pd(_mm256_fnmsub_pd(x, _mm256_set1_pd(std::numeric_limits<double>::quiet_NaN()), y), _mm256_set1_pd(-0.0)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f479(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_andnot_pd(_mm256_set1_pd(-0.0), _mm256_fnmsub_pd(x, _mm256_set1_pd(std::numeric_limits<double>::quiet_NaN()), y)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f480(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_sub_pd(_mm256_setzero_pd(), _mm256_fnmsub_pd(x, _mm256_set1_pd(std::numeric_limits<double>::quiet_NaN()), y)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f481(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_mul_pd(_mm256_fnmsub_pd(x, _mm256_set1_pd(std::numeric_limits<double>::quiet_NaN()), y), _mm256_set1_pd(-1.0)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f482(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_floor_pd(_mm256_fnmsub_pd(x, _mm256_set1_pd(std::numeric_limits<double>::quiet_NaN()), y)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f483(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_ceil_pd(_mm256_fnmsub_pd(x, _mm256_set1_pd(std::numeric_limits<double>::quiet_NaN()), y)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f484(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_round_pd(_mm256_fnmsub_pd(x, _mm256_set1_pd(std::numeric_limits<double>::quiet_NaN()), y), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f485(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_permute_pd(_mm256_fnmsub_pd(x, _mm256_set1_pd(std::numeric_limits<double>::quiet_NaN()), y), 0x5); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f486(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_permute_pd(_mm256_fnmsub_pd(x, _mm256_set1_pd(std::numeric_limits<double>::quiet_NaN()), y), 0xa); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f487(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_permute_pd(_mm256_fnmsub_pd(x, _mm256_set1_pd(std::numeric_limits<double>::quiet_NaN()), y), 0x3); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f488(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_sqrt_pd(_mm256_fnmsub_pd(_mm256_set1_pd(std::numeric_limits<double>::quiet_NaN()), x, y)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f489(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_xor_pd(_mm256_fnmsub_pd(_mm256_set1_pd(std::numeric_limits<double>::quiet_NaN()), x, y), _mm256_set1_pd(-0.0)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f490(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_andnot_pd(_mm256_set1_pd(-0.0), _mm256_fnmsub_pd(_mm256_set1_pd(std::numeric_limits<double>::quiet_NaN()), x, y)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f491(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_sub_pd(_mm256_setzero_pd(), _mm256_fnmsub_pd(_mm256_set1_pd(std::numeric_limits<double>::quiet_NaN()), x, y)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f492(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_mul_pd(_mm256_fnmsub_pd(_mm256_set1_pd(std::numeric_limits<double>::quiet_NaN()), x, y), _mm256_set1_pd(-1.0)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f493(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_floor_pd(_mm256_fnmsub_pd(_mm256_set1_pd(std::numeric_limits<double>::quiet_NaN()), x, y)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f494(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_ceil_pd(_mm256_fnmsub_pd(_mm256_set1_pd(std::numeric_limits<double>::quiet_NaN()), x, y)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f495(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_round_pd(_mm256_fnmsub_pd(_mm256_set1_pd(std::numeric_limits<double>::quiet_NaN()), x, y), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f496(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_permute_pd(_mm256_fnmsub_pd(_mm256_set1_pd(std::numeric_limits<double>::quiet_NaN()), x, y), 0x5); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f497(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_permute_pd(_mm256_fnmsub_pd(_mm256_set1_pd(std::numeric_limits<double>::quiet_NaN()), x, y), 0xa); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f498(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_permute_pd(_mm256_fnmsub_pd(_mm256_set1_pd(std::numeric_limits<double>::quiet_NaN()), x, y), 0x3); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f499(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_sqrt_pd(_mm256_fnmsub_pd(x, y, x)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f500(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_xor_pd(_mm256_fnmsub_pd(x, y, x), _mm256_set1_pd(-0.0)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f501(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_andnot_pd(_mm256_set1_pd(-0.0), _mm256_fnmsub_pd(x, y, x)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f502(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_sub_pd(_mm256_setzero_pd(), _mm256_fnmsub_pd(x, y, x)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f503(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_mul_pd(_mm256_fnmsub_pd(x, y, x), _mm256_set1_pd(-1.0)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f504(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_floor_pd(_mm256_fnmsub_pd(x, y, x)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f505(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_ceil_pd(_mm256_fnmsub_pd(x, y, x)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f506(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_round_pd(_mm256_fnmsub_pd(x, y, x), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f507(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_permute_pd(_mm256_fnmsub_pd(x, y, x), 0x5); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f508(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_permute_pd(_mm256_fnmsub_pd(x, y, x), 0xa); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f509(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_permute_pd(_mm256_fnmsub_pd(x, y, x), 0x3); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f510(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_sqrt_pd(_mm256_fnmsub_pd(x, x, y)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f511(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_xor_pd(_mm256_fnmsub_pd(x, x, y), _mm256_set1_pd(-0.0)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f512(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_andnot_pd(_mm256_set1_pd(-0.0), _mm256_fnmsub_pd(x, x, y)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f513(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_sub_pd(_mm256_setzero_pd(), _mm256_fnmsub_pd(x, x, y)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f514(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_mul_pd(_mm256_fnmsub_pd(x, x, y), _mm256_set1_pd(-1.0)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f515(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_floor_pd(_mm256_fnmsub_pd(x, x, y)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f516(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_ceil_pd(_mm256_fnmsub_pd(x, x, y)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f517(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_round_pd(_mm256_fnmsub_pd(x, x, y), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f518(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_permute_pd(_mm256_fnmsub_pd(x, x, y), 0x5); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f519(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_permute_pd(_mm256_fnmsub_pd(x, x, y), 0xa); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f520(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_permute_pd(_mm256_fnmsub_pd(x, x, y), 0x3); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f521(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_sqrt_pd(_mm256_fnmsub_pd(x, y, _mm256_mul_pd(x, y))); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f522(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_xor_pd(_mm256_fnmsub_pd(x, y, _mm256_mul_pd(x, y)), _mm256_set1_pd(-0.0)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f523(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_andnot_pd(_mm256_set1_pd(-0.0), _mm256_fnmsub_pd(x, y, _mm256_mul_pd(x, y))); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f524(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_sub_pd(_mm256_setzero_pd(), _mm256_fnmsub_pd(x, y, _mm256_mul_pd(x, y))); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f525(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_mul_pd(_mm256_fnmsub_pd(x, y, _mm256_mul_pd(x, y)), _mm256_set1_pd(-1.0)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f526(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_floor_pd(_mm256_fnmsub_pd(x, y, _mm256_mul_pd(x, y))); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f527(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_ceil_pd(_mm256_fnmsub_pd(x, y, _mm256_mul_pd(x, y))); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f528(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_round_pd(_mm256_fnmsub_pd(x, y, _mm256_mul_pd(x, y)), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f529(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_permute_pd(_mm256_fnmsub_pd(x, y, _mm256_mul_pd(x, y)), 0x5); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f530(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_permute_pd(_mm256_fnmsub_pd(x, y, _mm256_mul_pd(x, y)), 0xa); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f531(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_permute_pd(_mm256_fnmsub_pd(x, y, _mm256_mul_pd(x, y)), 0x3); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f532(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_sqrt_pd(_mm256_blendv_pd(x, y, _mm256_cmp_pd(x, y, _CMP_GE_OS))); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f533(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_xor_pd(_mm256_blendv_pd(x, y, _mm256_cmp_pd(x, y, _CMP_GE_OS)), _mm256_set1_pd(-0.0)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f534(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_andnot_pd(_mm256_set1_pd(-0.0), _mm256_blendv_pd(x, y, _mm256_cmp_pd(x, y, _CMP_GE_OS))); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f535(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_sub_pd(_mm256_setzero_pd(), _mm256_blendv_pd(x, y, _mm256_cmp_pd(x, y, _CMP_GE_OS))); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f536(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_mul_pd(_mm256_blendv_pd(x, y, _mm256_cmp_pd(x, y, _CMP_GE_OS)), _mm256_set1_pd(-1.0)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f537(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_floor_pd(_mm256_blendv_pd(x, y, _mm256_cmp_pd(x, y, _CMP_GE_OS))); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f538(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_ceil_pd(_mm256_blendv_pd(x, y, _mm256_cmp_pd(x, y, _CMP_GE_OS))); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f539(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_round_pd(_mm256_blendv_pd(x, y, _mm256_cmp_pd(x, y, _CMP_GE_OS)), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f540(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_permute_pd(_mm256_blendv_pd(x, y, _mm256_cmp_pd(x, y, _CMP_GE_OS)), 0x5); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f541(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_permute_pd(_mm256_blendv_pd(x, y, _mm256_cmp_pd(x, y, _CMP_GE_OS)), 0xa); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f542(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_permute_pd(_mm256_blendv_pd(x, y, _mm256_cmp_pd(x, y, _CMP_GE_OS)), 0x3); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f543(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_sqrt_pd(_mm256_blendv_pd(y, x, _mm256_cmp_pd(x, y, _CMP_GE_OS))); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f544(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_xor_pd(_mm256_blendv_pd(y, x, _mm256_cmp_pd(x, y, _CMP_GE_OS)), _mm256_set1_pd(-0.0)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f545(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_andnot_pd(_mm256_set1_pd(-0.0), _mm256_blendv_pd(y, x, _mm256_cmp_pd(x, y, _CMP_GE_OS))); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f546(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_sub_pd(_mm256_setzero_pd(), _mm256_blendv_pd(y, x, _mm256_cmp_pd(x, y, _CMP_GE_OS))); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f547(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_mul_pd(_mm256_blendv_pd(y, x, _mm256_cmp_pd(x, y, _CMP_GE_OS)), _mm256_set1_pd(-1.0)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f548(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_floor_pd(_mm256_blendv_pd(y, x, _mm256_cmp_pd(x, y, _CMP_GE_OS))); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f549(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_ceil_pd(_mm256_blendv_pd(y, x, _mm256_cmp_pd(x, y, _CMP_GE_OS))); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f550(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_round_pd(_mm256_blendv_pd(y, x, _mm256_cmp_pd(x, y, _CMP_GE_OS)), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f551(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_permute_pd(_mm256_blendv_pd(y, x, _mm256_cmp_pd(x, y, _CMP_GE_OS)), 0x5); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f552(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_permute_pd(_mm256_blendv_pd(y, x, _mm256_cmp_pd(x, y, _CMP_GE_OS)), 0xa); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f553(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_permute_pd(_mm256_blendv_pd(y, x, _mm256_cmp_pd(x, y, _CMP_GE_OS)), 0x3); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f554(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_sqrt_pd(_mm256_blendv_pd(x, y, _mm256_cmp_pd(x, y, _CMP_NLE_US))); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f555(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_xor_pd(_mm256_blendv_pd(x, y, _mm256_cmp_pd(x, y, _CMP_NLE_US)), _mm256_set1_pd(-0.0)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f556(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_andnot_pd(_mm256_set1_pd(-0.0), _mm256_blendv_pd(x, y, _mm256_cmp_pd(x, y, _CMP_NLE_US))); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f557(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_sub_pd(_mm256_setzero_pd(), _mm256_blendv_pd(x, y, _mm256_cmp_pd(x, y, _CMP_NLE_US))); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f558(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_mul_pd(_mm256_blendv_pd(x, y, _mm256_cmp_pd(x, y, _CMP_NLE_US)), _mm256_set1_pd(-1.0)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f559(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_floor_pd(_mm256_blendv_pd(x, y, _mm256_cmp_pd(x, y, _CMP_NLE_US))); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f560(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_ceil_pd(_mm256_blendv_pd(x, y, _mm256_cmp_pd(x, y, _CMP_NLE_US))); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f561(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_round_pd(_mm256_blendv_pd(x, y, _mm256_cmp_pd(x, y, _CMP_NLE_US)), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f562(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_permute_pd(_mm256_blendv_pd(x, y, _mm256_cmp_pd(x, y, _CMP_NLE_US)), 0x5); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f563(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_permute_pd(_mm256_blendv_pd(x, y, _mm256_cmp_pd(x, y, _CMP_NLE_US)), 0xa); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f564(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_permute_pd(_mm256_blendv_pd(x, y, _mm256_cmp_pd(x, y, _CMP_NLE_US)), 0x3); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f565(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_sqrt_pd(_mm256_blendv_pd(y, x, _mm256_cmp_pd(x, y, _CMP_NLE_US))); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f566(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_xor_pd(_mm256_blendv_pd(y, x, _mm256_cmp_pd(x, y, _CMP_NLE_US)), _mm256_set1_pd(-0.0)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f567(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_andnot_pd(_mm256_set1_pd(-0.0), _mm256_blendv_pd(y, x, _mm256_cmp_pd(x, y, _CMP_NLE_US))); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f568(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_sub_pd(_mm256_setzero_pd(), _mm256_blendv_pd(y, x, _mm256_cmp_pd(x, y, _CMP_NLE_US))); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f569(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_mul_pd(_mm256_blendv_pd(y, x, _mm256_cmp_pd(x, y, _CMP_NLE_US)), _mm256_set1_pd(-1.0)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f570(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_floor_pd(_mm256_blendv_pd(y, x, _mm256_cmp_pd(x, y, _CMP_NLE_US))); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f571(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_ceil_pd(_mm256_blendv_pd(y, x, _mm256_cmp_pd(x, y, _CMP_NLE_US))); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f572(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_round_pd(_mm256_blendv_pd(y, x, _mm256_cmp_pd(x, y, _CMP_NLE_US)), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f573(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_permute_pd(_mm256_blendv_pd(y, x, _mm256_cmp_pd(x, y, _CMP_NLE_US)), 0x5); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f574(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_permute_pd(_mm256_blendv_pd(y, x, _mm256_cmp_pd(x, y, _CMP_NLE_US)), 0xa); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f575(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_permute_pd(_mm256_blendv_pd(y, x, _mm256_cmp_pd(x, y, _CMP_NLE_US)), 0x3); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f576(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_sqrt_pd(_mm256_blendv_pd(x, y, _mm256_cmp_pd(x, y, _CMP_NGT_US))); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f577(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_xor_pd(_mm256_blendv_pd(x, y, _mm256_cmp_pd(x, y, _CMP_NGT_US)), _mm256_set1_pd(-0.0)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f578(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_andnot_pd(_mm256_set1_pd(-0.0), _mm256_blendv_pd(x, y, _mm256_cmp_pd(x, y, _CMP_NGT_US))); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f579(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_sub_pd(_mm256_setzero_pd(), _mm256_blendv_pd(x, y, _mm256_cmp_pd(x, y, _CMP_NGT_US))); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f580(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_mul_pd(_mm256_blendv_pd(x, y, _mm256_cmp_pd(x, y, _CMP_NGT_US)), _mm256_set1_pd(-1.0)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f581(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_floor_pd(_mm256_blendv_pd(x, y, _mm256_cmp_pd(x, y, _CMP_NGT_US))); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f582(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_ceil_pd(_mm256_blendv_pd(x, y, _mm256_cmp_pd(x, y, _CMP_NGT_US))); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f583(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_round_pd(_mm256_blendv_pd(x, y, _mm256_cmp_pd(x, y, _CMP_NGT_US)), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f584(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_permute_pd(_mm256_blendv_pd(x, y, _mm256_cmp_pd(x, y, _CMP_NGT_US)), 0x5); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f585(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_permute_pd(_mm256_blendv_pd(x, y, _mm256_cmp_pd(x, y, _CMP_NGT_US)), 0xa); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f586(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_permute_pd(_mm256_blendv_pd(x, y, _mm256_cmp_pd(x, y, _CMP_NGT_US)), 0x3); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f587(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_sqrt_pd(_mm256_blendv_pd(y, x, _mm256_cmp_pd(x, y, _CMP_NGT_US))); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f588(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_xor_pd(_mm256_blendv_pd(y, x, _mm256_cmp_pd(x, y, _CMP_NGT_US)), _mm256_set1_pd(-0.0)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f589(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_andnot_pd(_mm256_set1_pd(-0.0), _mm256_blendv_pd(y, x, _mm256_cmp_pd(x, y, _CMP_NGT_US))); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f590(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_sub_pd(_mm256_setzero_pd(), _mm256_blendv_pd(y, x, _mm256_cmp_pd(x, y, _CMP_NGT_US))); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f591(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_mul_pd(_mm256_blendv_pd(y, x, _mm256_cmp_pd(x, y, _CMP_NGT_US)), _mm256_set1_pd(-1.0)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f592(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_floor_pd(_mm256_blendv_pd(y, x, _mm256_cmp_pd(x, y, _CMP_NGT_US))); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f593(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_ceil_pd(_mm256_blendv_pd(y, x, _mm256_cmp_pd(x, y, _CMP_NGT_US))); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f594(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_round_pd(_mm256_blendv_pd(y, x, _mm256_cmp_pd(x, y, _CMP_NGT_US)), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f595(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_permute_pd(_mm256_blendv_pd(y, x, _mm256_cmp_pd(x, y, _CMP_NGT_US)), 0x5); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f596(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_permute_pd(_mm256_blendv_pd(y, x, _mm256_cmp_pd(x, y, _CMP_NGT_US)), 0xa); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f597(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_permute_pd(_mm256_blendv_pd(y, x, _mm256_cmp_pd(x, y, _CMP_NGT_US)), 0x3); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f598(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_sqrt_pd(_mm256_blendv_pd(x, y, _mm256_cmp_pd(x, y, _CMP_LE_OQ))); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f599(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_xor_pd(_mm256_blendv_pd(x, y, _mm256_cmp_pd(x, y, _CMP_LE_OQ)), _mm256_set1_pd(-0.0)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f600(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_andnot_pd(_mm256_set1_pd(-0.0), _mm256_blendv_pd(x, y, _mm256_cmp_pd(x, y, _CMP_LE_OQ))); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f601(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_sub_pd(_mm256_setzero_pd(), _mm256_blendv_pd(x, y, _mm256_cmp_pd(x, y, _CMP_LE_OQ))); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f602(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_mul_pd(_mm256_blendv_pd(x, y, _mm256_cmp_pd(x, y, _CMP_LE_OQ)), _mm256_set1_pd(-1.0)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f603(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_floor_pd(_mm256_blendv_pd(x, y, _mm256_cmp_pd(x, y, _CMP_LE_OQ))); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f604(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_ceil_pd(_mm256_blendv_pd(x, y, _mm256_cmp_pd(x, y, _CMP_LE_OQ))); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f605(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_round_pd(_mm256_blendv_pd(x, y, _mm256_cmp_pd(x, y, _CMP_LE_OQ)), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f606(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_permute_pd(_mm256_blendv_pd(x, y, _mm256_cmp_pd(x, y, _CMP_LE_OQ)), 0x5); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f607(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_permute_pd(_mm256_blendv_pd(x, y, _mm256_cmp_pd(x, y, _CMP_LE_OQ)), 0xa); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f608(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_permute_pd(_mm256_blendv_pd(x, y, _mm256_cmp_pd(x, y, _CMP_LE_OQ)), 0x3); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f609(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_sqrt_pd(_mm256_blendv_pd(y, x, _mm256_cmp_pd(x, y, _CMP_LE_OQ))); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f610(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_xor_pd(_mm256_blendv_pd(y, x, _mm256_cmp_pd(x, y, _CMP_LE_OQ)), _mm256_set1_pd(-0.0)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f611(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_andnot_pd(_mm256_set1_pd(-0.0), _mm256_blendv_pd(y, x, _mm256_cmp_pd(x, y, _CMP_LE_OQ))); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f612(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_sub_pd(_mm256_setzero_pd(), _mm256_blendv_pd(y, x, _mm256_cmp_pd(x, y, _CMP_LE_OQ))); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f613(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_mul_pd(_mm256_blendv_pd(y, x, _mm256_cmp_pd(x, y, _CMP_LE_OQ)), _mm256_set1_pd(-1.0)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f614(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_floor_pd(_mm256_blendv_pd(y, x, _mm256_cmp_pd(x, y, _CMP_LE_OQ))); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f615(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_ceil_pd(_mm256_blendv_pd(y, x, _mm256_cmp_pd(x, y, _CMP_LE_OQ))); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f616(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_round_pd(_mm256_blendv_pd(y, x, _mm256_cmp_pd(x, y, _CMP_LE_OQ)), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f617(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_permute_pd(_mm256_blendv_pd(y, x, _mm256_cmp_pd(x, y, _CMP_LE_OQ)), 0x5); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f618(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_permute_pd(_mm256_blendv_pd(y, x, _mm256_cmp_pd(x, y, _CMP_LE_OQ)), 0xa); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f619(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_permute_pd(_mm256_blendv_pd(y, x, _mm256_cmp_pd(x, y, _CMP_LE_OQ)), 0x3); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f620(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_sqrt_pd(_mm256_blendv_pd(x, y, _mm256_cmp_pd(x, y, _CMP_GE_OQ))); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f621(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_xor_pd(_mm256_blendv_pd(x, y, _mm256_cmp_pd(x, y, _CMP_GE_OQ)), _mm256_set1_pd(-0.0)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f622(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_andnot_pd(_mm256_set1_pd(-0.0), _mm256_blendv_pd(x, y, _mm256_cmp_pd(x, y, _CMP_GE_OQ))); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f623(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_sub_pd(_mm256_setzero_pd(), _mm256_blendv_pd(x, y, _mm256_cmp_pd(x, y, _CMP_GE_OQ))); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f624(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_mul_pd(_mm256_blendv_pd(x, y, _mm256_cmp_pd(x, y, _CMP_GE_OQ)), _mm256_set1_pd(-1.0)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f625(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_floor_pd(_mm256_blendv_pd(x, y, _mm256_cmp_pd(x, y, _CMP_GE_OQ))); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f626(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_ceil_pd(_mm256_blendv_pd(x, y, _mm256_cmp_pd(x, y, _CMP_GE_OQ))); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f627(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_round_pd(_mm256_blendv_pd(x, y, _mm256_cmp_pd(x, y, _CMP_GE_OQ)), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f628(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_permute_pd(_mm256_blendv_pd(x, y, _mm256_cmp_pd(x, y, _CMP_GE_OQ)), 0x5); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f629(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_permute_pd(_mm256_blendv_pd(x, y, _mm256_cmp_pd(x, y, _CMP_GE_OQ)), 0xa); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f630(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_permute_pd(_mm256_blendv_pd(x, y, _mm256_cmp_pd(x, y, _CMP_GE_OQ)), 0x3); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f631(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_sqrt_pd(_mm256_blendv_pd(y, x, _mm256_cmp_pd(x, y, _CMP_GE_OQ))); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f632(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_xor_pd(_mm256_blendv_pd(y, x, _mm256_cmp_pd(x, y, _CMP_GE_OQ)), _mm256_set1_pd(-0.0)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f633(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_andnot_pd(_mm256_set1_pd(-0.0), _mm256_blendv_pd(y, x, _mm256_cmp_pd(x, y, _CMP_GE_OQ))); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f634(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_sub_pd(_mm256_setzero_pd(), _mm256_blendv_pd(y, x, _mm256_cmp_pd(x, y, _CMP_GE_OQ))); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f635(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_mul_pd(_mm256_blendv_pd(y, x, _mm256_cmp_pd(x, y, _CMP_GE_OQ)), _mm256_set1_pd(-1.0)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f636(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_floor_pd(_mm256_blendv_pd(y, x, _mm256_cmp_pd(x, y, _CMP_GE_OQ))); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f637(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_ceil_pd(_mm256_blendv_pd(y, x, _mm256_cmp_pd(x, y, _CMP_GE_OQ))); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f638(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_round_pd(_mm256_blendv_pd(y, x, _mm256_cmp_pd(x, y, _CMP_GE_OQ)), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f639(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_permute_pd(_mm256_blendv_pd(y, x, _mm256_cmp_pd(x, y, _CMP_GE_OQ)), 0x5); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f640(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_permute_pd(_mm256_blendv_pd(y, x, _mm256_cmp_pd(x, y, _CMP_GE_OQ)), 0xa); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f641(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_permute_pd(_mm256_blendv_pd(y, x, _mm256_cmp_pd(x, y, _CMP_GE_OQ)), 0x3); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f642(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_sqrt_pd(_mm256_blendv_pd(x, y, _mm256_cmp_pd(x, y, _CMP_LT_OQ))); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f643(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_xor_pd(_mm256_blendv_pd(x, y, _mm256_cmp_pd(x, y, _CMP_LT_OQ)), _mm256_set1_pd(-0.0)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f644(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_andnot_pd(_mm256_set1_pd(-0.0), _mm256_blendv_pd(x, y, _mm256_cmp_pd(x, y, _CMP_LT_OQ))); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f645(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_sub_pd(_mm256_setzero_pd(), _mm256_blendv_pd(x, y, _mm256_cmp_pd(x, y, _CMP_LT_OQ))); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f646(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_mul_pd(_mm256_blendv_pd(x, y, _mm256_cmp_pd(x, y, _CMP_LT_OQ)), _mm256_set1_pd(-1.0)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f647(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_floor_pd(_mm256_blendv_pd(x, y, _mm256_cmp_pd(x, y, _CMP_LT_OQ))); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f648(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_ceil_pd(_mm256_blendv_pd(x, y, _mm256_cmp_pd(x, y, _CMP_LT_OQ))); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f649(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_round_pd(_mm256_blendv_pd(x, y, _mm256_cmp_pd(x, y, _CMP_LT_OQ)), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f650(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_permute_pd(_mm256_blendv_pd(x, y, _mm256_cmp_pd(x, y, _CMP_LT_OQ)), 0x5); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f651(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_permute_pd(_mm256_blendv_pd(x, y, _mm256_cmp_pd(x, y, _CMP_LT_OQ)), 0xa); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f652(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_permute_pd(_mm256_blendv_pd(x, y, _mm256_cmp_pd(x, y, _CMP_LT_OQ)), 0x3); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f653(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_sqrt_pd(_mm256_blendv_pd(y, x, _mm256_cmp_pd(x, y, _CMP_LT_OQ))); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f654(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_xor_pd(_mm256_blendv_pd(y, x, _mm256_cmp_pd(x, y, _CMP_LT_OQ)), _mm256_set1_pd(-0.0)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f655(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_andnot_pd(_mm256_set1_pd(-0.0), _mm256_blendv_pd(y, x, _mm256_cmp_pd(x, y, _CMP_LT_OQ))); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f656(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_sub_pd(_mm256_setzero_pd(), _mm256_blendv_pd(y, x, _mm256_cmp_pd(x, y, _CMP_LT_OQ))); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f657(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_mul_pd(_mm256_blendv_pd(y, x, _mm256_cmp_pd(x, y, _CMP_LT_OQ)), _mm256_set1_pd(-1.0)); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f658(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_floor_pd(_mm256_blendv_pd(y, x, _mm256_cmp_pd(x, y, _CMP_LT_OQ))); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f659(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_ceil_pd(_mm256_blendv_pd(y, x, _mm256_cmp_pd(x, y, _CMP_LT_OQ))); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f660(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_round_pd(_mm256_blendv_pd(y, x, _mm256_cmp_pd(x, y, _CMP_LT_OQ)), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f661(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_permute_pd(_mm256_blendv_pd(y, x, _mm256_cmp_pd(x, y, _CMP_LT_OQ)), 0x5); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f662(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_permute_pd(_mm256_blendv_pd(y, x, _mm256_cmp_pd(x, y, _CMP_LT_OQ)), 0xa); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f663(const void* px, const void* py, void* po) { const __m256d x = _mm256_loadu_pd((const double*)px); const __m256d y = _mm256_loadu_pd((const double*)py); (void)y; const __m256d r = _mm256_permute_pd(_mm256_blendv_pd(y, x, _mm256_cmp_pd(x, y, _CMP_LT_OQ)), 0x3); _mm256_storeu_pd((double*)po, r); }
static NOINLINE void f664(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_abs_epi8(_mm512_abs_epi8(x)); _mm512_storeu_si512(po, r); }
static NOINLINE void f665(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_abs_epi8(_mm512_abs_epi16(x)); _mm512_storeu_si512(po, r); }
static NOINLINE void f666(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_abs_epi8(_mm512_abs_epi32(x)); _mm512_storeu_si512(po, r); }
static NOINLINE void f667(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_abs_epi8(_mm512_abs_epi64(x)); _mm512_storeu_si512(po, r); }
static NOINLINE void f668(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_abs_epi8(_mm512_sub_epi8(_mm512_setzero_si512(), x)); _mm512_storeu_si512(po, r); }
static NOINLINE void f669(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_abs_epi8(_mm512_sub_epi16(_mm512_setzero_si512(), x)); _mm512_storeu_si512(po, r); }
static NOINLINE void f670(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_abs_epi8(_mm512_sub_epi32(_mm512_setzero_si512(), x)); _mm512_storeu_si512(po, r); }
static NOINLINE void f671(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_abs_epi8(_mm512_sub_epi64(_mm512_setzero_si512(), x)); _mm512_storeu_si512(po, r); }
static NOINLINE void f672(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_abs_epi8(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu))); _mm512_storeu_si512(po, r); }
static NOINLINE void f673(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_abs_epi8(_mm512_slli_epi16(x, 1)); _mm512_storeu_si512(po, r); }
static NOINLINE void f674(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_abs_epi8(_mm512_srli_epi16(x, 1)); _mm512_storeu_si512(po, r); }
static NOINLINE void f675(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_abs_epi8(_mm512_srai_epi16(x, 1)); _mm512_storeu_si512(po, r); }
static NOINLINE void f676(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_abs_epi8(_mm512_slli_epi16(x, 15)); _mm512_storeu_si512(po, r); }
static NOINLINE void f677(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_abs_epi8(_mm512_srli_epi16(x, 15)); _mm512_storeu_si512(po, r); }
static NOINLINE void f678(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_abs_epi8(_mm512_srai_epi16(x, 15)); _mm512_storeu_si512(po, r); }
static NOINLINE void f679(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_abs_epi8(_mm512_slli_epi32(x, 1)); _mm512_storeu_si512(po, r); }
static NOINLINE void f680(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_abs_epi8(_mm512_srli_epi32(x, 1)); _mm512_storeu_si512(po, r); }
static NOINLINE void f681(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_abs_epi8(_mm512_srai_epi32(x, 1)); _mm512_storeu_si512(po, r); }
static NOINLINE void f682(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_abs_epi8(_mm512_slli_epi32(x, 31)); _mm512_storeu_si512(po, r); }
static NOINLINE void f683(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_abs_epi8(_mm512_srli_epi32(x, 31)); _mm512_storeu_si512(po, r); }
static NOINLINE void f684(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_abs_epi8(_mm512_srai_epi32(x, 31)); _mm512_storeu_si512(po, r); }
static NOINLINE void f685(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_abs_epi8(_mm512_slli_epi64(x, 1)); _mm512_storeu_si512(po, r); }
static NOINLINE void f686(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_abs_epi8(_mm512_srli_epi64(x, 1)); _mm512_storeu_si512(po, r); }
static NOINLINE void f687(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_abs_epi8(_mm512_srai_epi64(x, 1)); _mm512_storeu_si512(po, r); }
static NOINLINE void f688(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_abs_epi8(_mm512_slli_epi64(x, 63)); _mm512_storeu_si512(po, r); }
static NOINLINE void f689(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_abs_epi8(_mm512_srli_epi64(x, 63)); _mm512_storeu_si512(po, r); }
static NOINLINE void f690(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_abs_epi8(_mm512_srai_epi64(x, 63)); _mm512_storeu_si512(po, r); }
static NOINLINE void f691(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_abs_epi16(_mm512_abs_epi8(x)); _mm512_storeu_si512(po, r); }
static NOINLINE void f692(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_abs_epi16(_mm512_abs_epi16(x)); _mm512_storeu_si512(po, r); }
static NOINLINE void f693(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_abs_epi16(_mm512_abs_epi32(x)); _mm512_storeu_si512(po, r); }
static NOINLINE void f694(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_abs_epi16(_mm512_abs_epi64(x)); _mm512_storeu_si512(po, r); }
static NOINLINE void f695(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_abs_epi16(_mm512_sub_epi8(_mm512_setzero_si512(), x)); _mm512_storeu_si512(po, r); }
static NOINLINE void f696(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_abs_epi16(_mm512_sub_epi16(_mm512_setzero_si512(), x)); _mm512_storeu_si512(po, r); }
static NOINLINE void f697(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_abs_epi16(_mm512_sub_epi32(_mm512_setzero_si512(), x)); _mm512_storeu_si512(po, r); }
static NOINLINE void f698(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_abs_epi16(_mm512_sub_epi64(_mm512_setzero_si512(), x)); _mm512_storeu_si512(po, r); }
static NOINLINE void f699(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_abs_epi16(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu))); _mm512_storeu_si512(po, r); }
static NOINLINE void f700(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_abs_epi16(_mm512_slli_epi16(x, 1)); _mm512_storeu_si512(po, r); }
static NOINLINE void f701(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_abs_epi16(_mm512_srli_epi16(x, 1)); _mm512_storeu_si512(po, r); }
static NOINLINE void f702(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_abs_epi16(_mm512_srai_epi16(x, 1)); _mm512_storeu_si512(po, r); }
static NOINLINE void f703(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_abs_epi16(_mm512_slli_epi16(x, 15)); _mm512_storeu_si512(po, r); }
static NOINLINE void f704(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_abs_epi16(_mm512_srli_epi16(x, 15)); _mm512_storeu_si512(po, r); }
static NOINLINE void f705(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_abs_epi16(_mm512_srai_epi16(x, 15)); _mm512_storeu_si512(po, r); }
static NOINLINE void f706(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_abs_epi16(_mm512_slli_epi32(x, 1)); _mm512_storeu_si512(po, r); }
static NOINLINE void f707(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_abs_epi16(_mm512_srli_epi32(x, 1)); _mm512_storeu_si512(po, r); }
static NOINLINE void f708(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_abs_epi16(_mm512_srai_epi32(x, 1)); _mm512_storeu_si512(po, r); }
static NOINLINE void f709(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_abs_epi16(_mm512_slli_epi32(x, 31)); _mm512_storeu_si512(po, r); }
static NOINLINE void f710(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_abs_epi16(_mm512_srli_epi32(x, 31)); _mm512_storeu_si512(po, r); }
static NOINLINE void f711(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_abs_epi16(_mm512_srai_epi32(x, 31)); _mm512_storeu_si512(po, r); }
static NOINLINE void f712(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_abs_epi16(_mm512_slli_epi64(x, 1)); _mm512_storeu_si512(po, r); }
static NOINLINE void f713(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_abs_epi16(_mm512_srli_epi64(x, 1)); _mm512_storeu_si512(po, r); }
static NOINLINE void f714(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_abs_epi16(_mm512_srai_epi64(x, 1)); _mm512_storeu_si512(po, r); }
static NOINLINE void f715(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_abs_epi16(_mm512_slli_epi64(x, 63)); _mm512_storeu_si512(po, r); }
static NOINLINE void f716(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_abs_epi16(_mm512_srli_epi64(x, 63)); _mm512_storeu_si512(po, r); }
static NOINLINE void f717(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_abs_epi16(_mm512_srai_epi64(x, 63)); _mm512_storeu_si512(po, r); }
static NOINLINE void f718(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_abs_epi32(_mm512_abs_epi8(x)); _mm512_storeu_si512(po, r); }
static NOINLINE void f719(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_abs_epi32(_mm512_abs_epi16(x)); _mm512_storeu_si512(po, r); }
static NOINLINE void f720(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_abs_epi32(_mm512_abs_epi32(x)); _mm512_storeu_si512(po, r); }
static NOINLINE void f721(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_abs_epi32(_mm512_abs_epi64(x)); _mm512_storeu_si512(po, r); }
static NOINLINE void f722(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_abs_epi32(_mm512_sub_epi8(_mm512_setzero_si512(), x)); _mm512_storeu_si512(po, r); }
static NOINLINE void f723(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_abs_epi32(_mm512_sub_epi16(_mm512_setzero_si512(), x)); _mm512_storeu_si512(po, r); }
static NOINLINE void f724(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_abs_epi32(_mm512_sub_epi32(_mm512_setzero_si512(), x)); _mm512_storeu_si512(po, r); }
static NOINLINE void f725(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_abs_epi32(_mm512_sub_epi64(_mm512_setzero_si512(), x)); _mm512_storeu_si512(po, r); }
static NOINLINE void f726(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_abs_epi32(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu))); _mm512_storeu_si512(po, r); }
static NOINLINE void f727(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_abs_epi32(_mm512_slli_epi16(x, 1)); _mm512_storeu_si512(po, r); }
static NOINLINE void f728(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_abs_epi32(_mm512_srli_epi16(x, 1)); _mm512_storeu_si512(po, r); }
static NOINLINE void f729(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_abs_epi32(_mm512_srai_epi16(x, 1)); _mm512_storeu_si512(po, r); }
static NOINLINE void f730(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_abs_epi32(_mm512_slli_epi16(x, 15)); _mm512_storeu_si512(po, r); }
static NOINLINE void f731(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_abs_epi32(_mm512_srli_epi16(x, 15)); _mm512_storeu_si512(po, r); }
static NOINLINE void f732(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_abs_epi32(_mm512_srai_epi16(x, 15)); _mm512_storeu_si512(po, r); }
static NOINLINE void f733(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_abs_epi32(_mm512_slli_epi32(x, 1)); _mm512_storeu_si512(po, r); }
static NOINLINE void f734(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_abs_epi32(_mm512_srli_epi32(x, 1)); _mm512_storeu_si512(po, r); }
static NOINLINE void f735(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_abs_epi32(_mm512_srai_epi32(x, 1)); _mm512_storeu_si512(po, r); }
static NOINLINE void f736(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_abs_epi32(_mm512_slli_epi32(x, 31)); _mm512_storeu_si512(po, r); }
static NOINLINE void f737(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_abs_epi32(_mm512_srli_epi32(x, 31)); _mm512_storeu_si512(po, r); }
static NOINLINE void f738(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_abs_epi32(_mm512_srai_epi32(x, 31)); _mm512_storeu_si512(po, r); }
static NOINLINE void f739(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_abs_epi32(_mm512_slli_epi64(x, 1)); _mm512_storeu_si512(po, r); }
static NOINLINE void f740(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_abs_epi32(_mm512_srli_epi64(x, 1)); _mm512_storeu_si512(po, r); }
static NOINLINE void f741(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_abs_epi32(_mm512_srai_epi64(x, 1)); _mm512_storeu_si512(po, r); }
static NOINLINE void f742(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_abs_epi32(_mm512_slli_epi64(x, 63)); _mm512_storeu_si512(po, r); }
static NOINLINE void f743(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_abs_epi32(_mm512_srli_epi64(x, 63)); _mm512_storeu_si512(po, r); }
static NOINLINE void f744(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_abs_epi32(_mm512_srai_epi64(x, 63)); _mm512_storeu_si512(po, r); }
static NOINLINE void f745(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_abs_epi64(_mm512_abs_epi8(x)); _mm512_storeu_si512(po, r); }
static NOINLINE void f746(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_abs_epi64(_mm512_abs_epi16(x)); _mm512_storeu_si512(po, r); }
static NOINLINE void f747(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_abs_epi64(_mm512_abs_epi32(x)); _mm512_storeu_si512(po, r); }
static NOINLINE void f748(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_abs_epi64(_mm512_abs_epi64(x)); _mm512_storeu_si512(po, r); }
static NOINLINE void f749(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_abs_epi64(_mm512_sub_epi8(_mm512_setzero_si512(), x)); _mm512_storeu_si512(po, r); }
static NOINLINE void f750(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_abs_epi64(_mm512_sub_epi16(_mm512_setzero_si512(), x)); _mm512_storeu_si512(po, r); }
static NOINLINE void f751(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_abs_epi64(_mm512_sub_epi32(_mm512_setzero_si512(), x)); _mm512_storeu_si512(po, r); }
static NOINLINE void f752(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_abs_epi64(_mm512_sub_epi64(_mm512_setzero_si512(), x)); _mm512_storeu_si512(po, r); }
static NOINLINE void f753(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_abs_epi64(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu))); _mm512_storeu_si512(po, r); }
static NOINLINE void f754(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_abs_epi64(_mm512_slli_epi16(x, 1)); _mm512_storeu_si512(po, r); }
static NOINLINE void f755(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_abs_epi64(_mm512_srli_epi16(x, 1)); _mm512_storeu_si512(po, r); }
static NOINLINE void f756(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_abs_epi64(_mm512_srai_epi16(x, 1)); _mm512_storeu_si512(po, r); }
static NOINLINE void f757(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_abs_epi64(_mm512_slli_epi16(x, 15)); _mm512_storeu_si512(po, r); }
static NOINLINE void f758(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_abs_epi64(_mm512_srli_epi16(x, 15)); _mm512_storeu_si512(po, r); }
static NOINLINE void f759(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_abs_epi64(_mm512_srai_epi16(x, 15)); _mm512_storeu_si512(po, r); }
static NOINLINE void f760(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_abs_epi64(_mm512_slli_epi32(x, 1)); _mm512_storeu_si512(po, r); }
static NOINLINE void f761(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_abs_epi64(_mm512_srli_epi32(x, 1)); _mm512_storeu_si512(po, r); }
static NOINLINE void f762(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_abs_epi64(_mm512_srai_epi32(x, 1)); _mm512_storeu_si512(po, r); }
static NOINLINE void f763(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_abs_epi64(_mm512_slli_epi32(x, 31)); _mm512_storeu_si512(po, r); }
static NOINLINE void f764(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_abs_epi64(_mm512_srli_epi32(x, 31)); _mm512_storeu_si512(po, r); }
static NOINLINE void f765(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_abs_epi64(_mm512_srai_epi32(x, 31)); _mm512_storeu_si512(po, r); }
static NOINLINE void f766(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_abs_epi64(_mm512_slli_epi64(x, 1)); _mm512_storeu_si512(po, r); }
static NOINLINE void f767(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_abs_epi64(_mm512_srli_epi64(x, 1)); _mm512_storeu_si512(po, r); }
static NOINLINE void f768(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_abs_epi64(_mm512_srai_epi64(x, 1)); _mm512_storeu_si512(po, r); }
static NOINLINE void f769(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_abs_epi64(_mm512_slli_epi64(x, 63)); _mm512_storeu_si512(po, r); }
static NOINLINE void f770(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_abs_epi64(_mm512_srli_epi64(x, 63)); _mm512_storeu_si512(po, r); }
static NOINLINE void f771(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_abs_epi64(_mm512_srai_epi64(x, 63)); _mm512_storeu_si512(po, r); }
static NOINLINE void f772(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi8(_mm512_setzero_si512(), _mm512_abs_epi8(x)); _mm512_storeu_si512(po, r); }
static NOINLINE void f773(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi8(_mm512_setzero_si512(), _mm512_abs_epi16(x)); _mm512_storeu_si512(po, r); }
static NOINLINE void f774(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi8(_mm512_setzero_si512(), _mm512_abs_epi32(x)); _mm512_storeu_si512(po, r); }
static NOINLINE void f775(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi8(_mm512_setzero_si512(), _mm512_abs_epi64(x)); _mm512_storeu_si512(po, r); }
static NOINLINE void f776(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi8(_mm512_setzero_si512(), _mm512_sub_epi8(_mm512_setzero_si512(), x)); _mm512_storeu_si512(po, r); }
static NOINLINE void f777(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi8(_mm512_setzero_si512(), _mm512_sub_epi16(_mm512_setzero_si512(), x)); _mm512_storeu_si512(po, r); }
static NOINLINE void f778(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi8(_mm512_setzero_si512(), _mm512_sub_epi32(_mm512_setzero_si512(), x)); _mm512_storeu_si512(po, r); }
static NOINLINE void f779(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi8(_mm512_setzero_si512(), _mm512_sub_epi64(_mm512_setzero_si512(), x)); _mm512_storeu_si512(po, r); }
static NOINLINE void f780(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi8(_mm512_setzero_si512(), _mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu))); _mm512_storeu_si512(po, r); }
static NOINLINE void f781(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi8(_mm512_setzero_si512(), _mm512_slli_epi16(x, 1)); _mm512_storeu_si512(po, r); }
static NOINLINE void f782(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi8(_mm512_setzero_si512(), _mm512_srli_epi16(x, 1)); _mm512_storeu_si512(po, r); }
static NOINLINE void f783(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi8(_mm512_setzero_si512(), _mm512_srai_epi16(x, 1)); _mm512_storeu_si512(po, r); }
static NOINLINE void f784(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi8(_mm512_setzero_si512(), _mm512_slli_epi16(x, 15)); _mm512_storeu_si512(po, r); }
static NOINLINE void f785(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi8(_mm512_setzero_si512(), _mm512_srli_epi16(x, 15)); _mm512_storeu_si512(po, r); }
static NOINLINE void f786(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi8(_mm512_setzero_si512(), _mm512_srai_epi16(x, 15)); _mm512_storeu_si512(po, r); }
static NOINLINE void f787(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi8(_mm512_setzero_si512(), _mm512_slli_epi32(x, 1)); _mm512_storeu_si512(po, r); }
static NOINLINE void f788(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi8(_mm512_setzero_si512(), _mm512_srli_epi32(x, 1)); _mm512_storeu_si512(po, r); }
static NOINLINE void f789(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi8(_mm512_setzero_si512(), _mm512_srai_epi32(x, 1)); _mm512_storeu_si512(po, r); }
static NOINLINE void f790(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi8(_mm512_setzero_si512(), _mm512_slli_epi32(x, 31)); _mm512_storeu_si512(po, r); }
static NOINLINE void f791(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi8(_mm512_setzero_si512(), _mm512_srli_epi32(x, 31)); _mm512_storeu_si512(po, r); }
static NOINLINE void f792(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi8(_mm512_setzero_si512(), _mm512_srai_epi32(x, 31)); _mm512_storeu_si512(po, r); }
static NOINLINE void f793(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi8(_mm512_setzero_si512(), _mm512_slli_epi64(x, 1)); _mm512_storeu_si512(po, r); }
static NOINLINE void f794(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi8(_mm512_setzero_si512(), _mm512_srli_epi64(x, 1)); _mm512_storeu_si512(po, r); }
static NOINLINE void f795(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi8(_mm512_setzero_si512(), _mm512_srai_epi64(x, 1)); _mm512_storeu_si512(po, r); }
static NOINLINE void f796(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi8(_mm512_setzero_si512(), _mm512_slli_epi64(x, 63)); _mm512_storeu_si512(po, r); }
static NOINLINE void f797(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi8(_mm512_setzero_si512(), _mm512_srli_epi64(x, 63)); _mm512_storeu_si512(po, r); }
static NOINLINE void f798(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi8(_mm512_setzero_si512(), _mm512_srai_epi64(x, 63)); _mm512_storeu_si512(po, r); }
static NOINLINE void f799(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi16(_mm512_setzero_si512(), _mm512_abs_epi8(x)); _mm512_storeu_si512(po, r); }
static NOINLINE void f800(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi16(_mm512_setzero_si512(), _mm512_abs_epi16(x)); _mm512_storeu_si512(po, r); }
static NOINLINE void f801(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi16(_mm512_setzero_si512(), _mm512_abs_epi32(x)); _mm512_storeu_si512(po, r); }
static NOINLINE void f802(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi16(_mm512_setzero_si512(), _mm512_abs_epi64(x)); _mm512_storeu_si512(po, r); }
static NOINLINE void f803(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi16(_mm512_setzero_si512(), _mm512_sub_epi8(_mm512_setzero_si512(), x)); _mm512_storeu_si512(po, r); }
static NOINLINE void f804(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi16(_mm512_setzero_si512(), _mm512_sub_epi16(_mm512_setzero_si512(), x)); _mm512_storeu_si512(po, r); }
static NOINLINE void f805(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi16(_mm512_setzero_si512(), _mm512_sub_epi32(_mm512_setzero_si512(), x)); _mm512_storeu_si512(po, r); }
static NOINLINE void f806(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi16(_mm512_setzero_si512(), _mm512_sub_epi64(_mm512_setzero_si512(), x)); _mm512_storeu_si512(po, r); }
static NOINLINE void f807(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi16(_mm512_setzero_si512(), _mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu))); _mm512_storeu_si512(po, r); }
static NOINLINE void f808(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi16(_mm512_setzero_si512(), _mm512_slli_epi16(x, 1)); _mm512_storeu_si512(po, r); }
static NOINLINE void f809(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi16(_mm512_setzero_si512(), _mm512_srli_epi16(x, 1)); _mm512_storeu_si512(po, r); }
static NOINLINE void f810(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi16(_mm512_setzero_si512(), _mm512_srai_epi16(x, 1)); _mm512_storeu_si512(po, r); }
static NOINLINE void f811(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi16(_mm512_setzero_si512(), _mm512_slli_epi16(x, 15)); _mm512_storeu_si512(po, r); }
static NOINLINE void f812(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi16(_mm512_setzero_si512(), _mm512_srli_epi16(x, 15)); _mm512_storeu_si512(po, r); }
static NOINLINE void f813(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi16(_mm512_setzero_si512(), _mm512_srai_epi16(x, 15)); _mm512_storeu_si512(po, r); }
static NOINLINE void f814(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi16(_mm512_setzero_si512(), _mm512_slli_epi32(x, 1)); _mm512_storeu_si512(po, r); }
static NOINLINE void f815(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi16(_mm512_setzero_si512(), _mm512_srli_epi32(x, 1)); _mm512_storeu_si512(po, r); }
static NOINLINE void f816(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi16(_mm512_setzero_si512(), _mm512_srai_epi32(x, 1)); _mm512_storeu_si512(po, r); }
static NOINLINE void f817(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi16(_mm512_setzero_si512(), _mm512_slli_epi32(x, 31)); _mm512_storeu_si512(po, r); }
static NOINLINE void f818(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi16(_mm512_setzero_si512(), _mm512_srli_epi32(x, 31)); _mm512_storeu_si512(po, r); }
static NOINLINE void f819(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi16(_mm512_setzero_si512(), _mm512_srai_epi32(x, 31)); _mm512_storeu_si512(po, r); }
static NOINLINE void f820(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi16(_mm512_setzero_si512(), _mm512_slli_epi64(x, 1)); _mm512_storeu_si512(po, r); }
static NOINLINE void f821(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi16(_mm512_setzero_si512(), _mm512_srli_epi64(x, 1)); _mm512_storeu_si512(po, r); }
static NOINLINE void f822(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi16(_mm512_setzero_si512(), _mm512_srai_epi64(x, 1)); _mm512_storeu_si512(po, r); }
static NOINLINE void f823(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi16(_mm512_setzero_si512(), _mm512_slli_epi64(x, 63)); _mm512_storeu_si512(po, r); }
static NOINLINE void f824(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi16(_mm512_setzero_si512(), _mm512_srli_epi64(x, 63)); _mm512_storeu_si512(po, r); }
static NOINLINE void f825(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi16(_mm512_setzero_si512(), _mm512_srai_epi64(x, 63)); _mm512_storeu_si512(po, r); }
static NOINLINE void f826(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi32(_mm512_setzero_si512(), _mm512_abs_epi8(x)); _mm512_storeu_si512(po, r); }
static NOINLINE void f827(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi32(_mm512_setzero_si512(), _mm512_abs_epi16(x)); _mm512_storeu_si512(po, r); }
static NOINLINE void f828(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi32(_mm512_setzero_si512(), _mm512_abs_epi32(x)); _mm512_storeu_si512(po, r); }
static NOINLINE void f829(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi32(_mm512_setzero_si512(), _mm512_abs_epi64(x)); _mm512_storeu_si512(po, r); }
static NOINLINE void f830(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi32(_mm512_setzero_si512(), _mm512_sub_epi8(_mm512_setzero_si512(), x)); _mm512_storeu_si512(po, r); }
static NOINLINE void f831(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi32(_mm512_setzero_si512(), _mm512_sub_epi16(_mm512_setzero_si512(), x)); _mm512_storeu_si512(po, r); }
static NOINLINE void f832(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi32(_mm512_setzero_si512(), _mm512_sub_epi32(_mm512_setzero_si512(), x)); _mm512_storeu_si512(po, r); }
static NOINLINE void f833(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi32(_mm512_setzero_si512(), _mm512_sub_epi64(_mm512_setzero_si512(), x)); _mm512_storeu_si512(po, r); }
static NOINLINE void f834(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi32(_mm512_setzero_si512(), _mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu))); _mm512_storeu_si512(po, r); }
static NOINLINE void f835(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi32(_mm512_setzero_si512(), _mm512_slli_epi16(x, 1)); _mm512_storeu_si512(po, r); }
static NOINLINE void f836(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi32(_mm512_setzero_si512(), _mm512_srli_epi16(x, 1)); _mm512_storeu_si512(po, r); }
static NOINLINE void f837(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi32(_mm512_setzero_si512(), _mm512_srai_epi16(x, 1)); _mm512_storeu_si512(po, r); }
static NOINLINE void f838(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi32(_mm512_setzero_si512(), _mm512_slli_epi16(x, 15)); _mm512_storeu_si512(po, r); }
static NOINLINE void f839(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi32(_mm512_setzero_si512(), _mm512_srli_epi16(x, 15)); _mm512_storeu_si512(po, r); }
static NOINLINE void f840(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi32(_mm512_setzero_si512(), _mm512_srai_epi16(x, 15)); _mm512_storeu_si512(po, r); }
static NOINLINE void f841(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi32(_mm512_setzero_si512(), _mm512_slli_epi32(x, 1)); _mm512_storeu_si512(po, r); }
static NOINLINE void f842(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi32(_mm512_setzero_si512(), _mm512_srli_epi32(x, 1)); _mm512_storeu_si512(po, r); }
static NOINLINE void f843(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi32(_mm512_setzero_si512(), _mm512_srai_epi32(x, 1)); _mm512_storeu_si512(po, r); }
static NOINLINE void f844(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi32(_mm512_setzero_si512(), _mm512_slli_epi32(x, 31)); _mm512_storeu_si512(po, r); }
static NOINLINE void f845(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi32(_mm512_setzero_si512(), _mm512_srli_epi32(x, 31)); _mm512_storeu_si512(po, r); }
static NOINLINE void f846(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi32(_mm512_setzero_si512(), _mm512_srai_epi32(x, 31)); _mm512_storeu_si512(po, r); }
static NOINLINE void f847(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi32(_mm512_setzero_si512(), _mm512_slli_epi64(x, 1)); _mm512_storeu_si512(po, r); }
static NOINLINE void f848(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi32(_mm512_setzero_si512(), _mm512_srli_epi64(x, 1)); _mm512_storeu_si512(po, r); }
static NOINLINE void f849(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi32(_mm512_setzero_si512(), _mm512_srai_epi64(x, 1)); _mm512_storeu_si512(po, r); }
static NOINLINE void f850(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi32(_mm512_setzero_si512(), _mm512_slli_epi64(x, 63)); _mm512_storeu_si512(po, r); }
static NOINLINE void f851(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi32(_mm512_setzero_si512(), _mm512_srli_epi64(x, 63)); _mm512_storeu_si512(po, r); }
static NOINLINE void f852(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi32(_mm512_setzero_si512(), _mm512_srai_epi64(x, 63)); _mm512_storeu_si512(po, r); }
static NOINLINE void f853(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi64(_mm512_setzero_si512(), _mm512_abs_epi8(x)); _mm512_storeu_si512(po, r); }
static NOINLINE void f854(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi64(_mm512_setzero_si512(), _mm512_abs_epi16(x)); _mm512_storeu_si512(po, r); }
static NOINLINE void f855(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi64(_mm512_setzero_si512(), _mm512_abs_epi32(x)); _mm512_storeu_si512(po, r); }
static NOINLINE void f856(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi64(_mm512_setzero_si512(), _mm512_abs_epi64(x)); _mm512_storeu_si512(po, r); }
static NOINLINE void f857(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi64(_mm512_setzero_si512(), _mm512_sub_epi8(_mm512_setzero_si512(), x)); _mm512_storeu_si512(po, r); }
static NOINLINE void f858(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi64(_mm512_setzero_si512(), _mm512_sub_epi16(_mm512_setzero_si512(), x)); _mm512_storeu_si512(po, r); }
static NOINLINE void f859(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi64(_mm512_setzero_si512(), _mm512_sub_epi32(_mm512_setzero_si512(), x)); _mm512_storeu_si512(po, r); }
static NOINLINE void f860(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi64(_mm512_setzero_si512(), _mm512_sub_epi64(_mm512_setzero_si512(), x)); _mm512_storeu_si512(po, r); }
static NOINLINE void f861(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi64(_mm512_setzero_si512(), _mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu))); _mm512_storeu_si512(po, r); }
static NOINLINE void f862(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi64(_mm512_setzero_si512(), _mm512_slli_epi16(x, 1)); _mm512_storeu_si512(po, r); }
static NOINLINE void f863(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi64(_mm512_setzero_si512(), _mm512_srli_epi16(x, 1)); _mm512_storeu_si512(po, r); }
static NOINLINE void f864(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi64(_mm512_setzero_si512(), _mm512_srai_epi16(x, 1)); _mm512_storeu_si512(po, r); }
static NOINLINE void f865(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi64(_mm512_setzero_si512(), _mm512_slli_epi16(x, 15)); _mm512_storeu_si512(po, r); }
static NOINLINE void f866(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi64(_mm512_setzero_si512(), _mm512_srli_epi16(x, 15)); _mm512_storeu_si512(po, r); }
static NOINLINE void f867(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi64(_mm512_setzero_si512(), _mm512_srai_epi16(x, 15)); _mm512_storeu_si512(po, r); }
static NOINLINE void f868(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi64(_mm512_setzero_si512(), _mm512_slli_epi32(x, 1)); _mm512_storeu_si512(po, r); }
static NOINLINE void f869(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi64(_mm512_setzero_si512(), _mm512_srli_epi32(x, 1)); _mm512_storeu_si512(po, r); }
static NOINLINE void f870(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi64(_mm512_setzero_si512(), _mm512_srai_epi32(x, 1)); _mm512_storeu_si512(po, r); }
static NOINLINE void f871(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi64(_mm512_setzero_si512(), _mm512_slli_epi32(x, 31)); _mm512_storeu_si512(po, r); }
static NOINLINE void f872(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi64(_mm512_setzero_si512(), _mm512_srli_epi32(x, 31)); _mm512_storeu_si512(po, r); }
static NOINLINE void f873(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi64(_mm512_setzero_si512(), _mm512_srai_epi32(x, 31)); _mm512_storeu_si512(po, r); }
static NOINLINE void f874(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi64(_mm512_setzero_si512(), _mm512_slli_epi64(x, 1)); _mm512_storeu_si512(po, r); }
static NOINLINE void f875(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi64(_mm512_setzero_si512(), _mm512_srli_epi64(x, 1)); _mm512_storeu_si512(po, r); }
static NOINLINE void f876(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi64(_mm512_setzero_si512(), _mm512_srai_epi64(x, 1)); _mm512_storeu_si512(po, r); }
static NOINLINE void f877(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi64(_mm512_setzero_si512(), _mm512_slli_epi64(x, 63)); _mm512_storeu_si512(po, r); }
static NOINLINE void f878(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi64(_mm512_setzero_si512(), _mm512_srli_epi64(x, 63)); _mm512_storeu_si512(po, r); }
static NOINLINE void f879(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_sub_epi64(_mm512_setzero_si512(), _mm512_srai_epi64(x, 63)); _mm512_storeu_si512(po, r); }
static NOINLINE void f880(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_xor_si512(_mm512_abs_epi8(x), _mm512_set1_epi8((char)0xffu)); _mm512_storeu_si512(po, r); }
static NOINLINE void f881(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_xor_si512(_mm512_abs_epi16(x), _mm512_set1_epi8((char)0xffu)); _mm512_storeu_si512(po, r); }
static NOINLINE void f882(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_xor_si512(_mm512_abs_epi32(x), _mm512_set1_epi8((char)0xffu)); _mm512_storeu_si512(po, r); }
static NOINLINE void f883(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_xor_si512(_mm512_abs_epi64(x), _mm512_set1_epi8((char)0xffu)); _mm512_storeu_si512(po, r); }
static NOINLINE void f884(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_xor_si512(_mm512_sub_epi8(_mm512_setzero_si512(), x), _mm512_set1_epi8((char)0xffu)); _mm512_storeu_si512(po, r); }
static NOINLINE void f885(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_xor_si512(_mm512_sub_epi16(_mm512_setzero_si512(), x), _mm512_set1_epi8((char)0xffu)); _mm512_storeu_si512(po, r); }
static NOINLINE void f886(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_xor_si512(_mm512_sub_epi32(_mm512_setzero_si512(), x), _mm512_set1_epi8((char)0xffu)); _mm512_storeu_si512(po, r); }
static NOINLINE void f887(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_xor_si512(_mm512_sub_epi64(_mm512_setzero_si512(), x), _mm512_set1_epi8((char)0xffu)); _mm512_storeu_si512(po, r); }
static NOINLINE void f888(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_xor_si512(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), _mm512_set1_epi8((char)0xffu)); _mm512_storeu_si512(po, r); }
static NOINLINE void f889(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_xor_si512(_mm512_slli_epi16(x, 1), _mm512_set1_epi8((char)0xffu)); _mm512_storeu_si512(po, r); }
static NOINLINE void f890(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_xor_si512(_mm512_srli_epi16(x, 1), _mm512_set1_epi8((char)0xffu)); _mm512_storeu_si512(po, r); }
static NOINLINE void f891(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_xor_si512(_mm512_srai_epi16(x, 1), _mm512_set1_epi8((char)0xffu)); _mm512_storeu_si512(po, r); }
static NOINLINE void f892(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_xor_si512(_mm512_slli_epi16(x, 15), _mm512_set1_epi8((char)0xffu)); _mm512_storeu_si512(po, r); }
static NOINLINE void f893(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_xor_si512(_mm512_srli_epi16(x, 15), _mm512_set1_epi8((char)0xffu)); _mm512_storeu_si512(po, r); }
static NOINLINE void f894(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_xor_si512(_mm512_srai_epi16(x, 15), _mm512_set1_epi8((char)0xffu)); _mm512_storeu_si512(po, r); }
static NOINLINE void f895(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_xor_si512(_mm512_slli_epi32(x, 1), _mm512_set1_epi8((char)0xffu)); _mm512_storeu_si512(po, r); }
static NOINLINE void f896(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_xor_si512(_mm512_srli_epi32(x, 1), _mm512_set1_epi8((char)0xffu)); _mm512_storeu_si512(po, r); }
static NOINLINE void f897(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_xor_si512(_mm512_srai_epi32(x, 1), _mm512_set1_epi8((char)0xffu)); _mm512_storeu_si512(po, r); }
static NOINLINE void f898(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_xor_si512(_mm512_slli_epi32(x, 31), _mm512_set1_epi8((char)0xffu)); _mm512_storeu_si512(po, r); }
static NOINLINE void f899(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_xor_si512(_mm512_srli_epi32(x, 31), _mm512_set1_epi8((char)0xffu)); _mm512_storeu_si512(po, r); }
static NOINLINE void f900(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_xor_si512(_mm512_srai_epi32(x, 31), _mm512_set1_epi8((char)0xffu)); _mm512_storeu_si512(po, r); }
static NOINLINE void f901(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_xor_si512(_mm512_slli_epi64(x, 1), _mm512_set1_epi8((char)0xffu)); _mm512_storeu_si512(po, r); }
static NOINLINE void f902(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_xor_si512(_mm512_srli_epi64(x, 1), _mm512_set1_epi8((char)0xffu)); _mm512_storeu_si512(po, r); }
static NOINLINE void f903(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_xor_si512(_mm512_srai_epi64(x, 1), _mm512_set1_epi8((char)0xffu)); _mm512_storeu_si512(po, r); }
static NOINLINE void f904(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_xor_si512(_mm512_slli_epi64(x, 63), _mm512_set1_epi8((char)0xffu)); _mm512_storeu_si512(po, r); }
static NOINLINE void f905(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_xor_si512(_mm512_srli_epi64(x, 63), _mm512_set1_epi8((char)0xffu)); _mm512_storeu_si512(po, r); }
static NOINLINE void f906(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_xor_si512(_mm512_srai_epi64(x, 63), _mm512_set1_epi8((char)0xffu)); _mm512_storeu_si512(po, r); }
static NOINLINE void f907(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_slli_epi16(_mm512_abs_epi8(x), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f908(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_slli_epi16(_mm512_abs_epi16(x), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f909(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_slli_epi16(_mm512_abs_epi32(x), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f910(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_slli_epi16(_mm512_abs_epi64(x), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f911(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_slli_epi16(_mm512_sub_epi8(_mm512_setzero_si512(), x), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f912(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_slli_epi16(_mm512_sub_epi16(_mm512_setzero_si512(), x), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f913(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_slli_epi16(_mm512_sub_epi32(_mm512_setzero_si512(), x), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f914(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_slli_epi16(_mm512_sub_epi64(_mm512_setzero_si512(), x), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f915(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_slli_epi16(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f916(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_slli_epi16(_mm512_slli_epi16(x, 1), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f917(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_slli_epi16(_mm512_srli_epi16(x, 1), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f918(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_slli_epi16(_mm512_srai_epi16(x, 1), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f919(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_slli_epi16(_mm512_slli_epi16(x, 15), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f920(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_slli_epi16(_mm512_srli_epi16(x, 15), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f921(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_slli_epi16(_mm512_srai_epi16(x, 15), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f922(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_slli_epi16(_mm512_slli_epi32(x, 1), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f923(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_slli_epi16(_mm512_srli_epi32(x, 1), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f924(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_slli_epi16(_mm512_srai_epi32(x, 1), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f925(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_slli_epi16(_mm512_slli_epi32(x, 31), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f926(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_slli_epi16(_mm512_srli_epi32(x, 31), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f927(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_slli_epi16(_mm512_srai_epi32(x, 31), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f928(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_slli_epi16(_mm512_slli_epi64(x, 1), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f929(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_slli_epi16(_mm512_srli_epi64(x, 1), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f930(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_slli_epi16(_mm512_srai_epi64(x, 1), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f931(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_slli_epi16(_mm512_slli_epi64(x, 63), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f932(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_slli_epi16(_mm512_srli_epi64(x, 63), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f933(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_slli_epi16(_mm512_srai_epi64(x, 63), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f934(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srli_epi16(_mm512_abs_epi8(x), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f935(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srli_epi16(_mm512_abs_epi16(x), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f936(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srli_epi16(_mm512_abs_epi32(x), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f937(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srli_epi16(_mm512_abs_epi64(x), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f938(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srli_epi16(_mm512_sub_epi8(_mm512_setzero_si512(), x), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f939(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srli_epi16(_mm512_sub_epi16(_mm512_setzero_si512(), x), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f940(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srli_epi16(_mm512_sub_epi32(_mm512_setzero_si512(), x), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f941(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srli_epi16(_mm512_sub_epi64(_mm512_setzero_si512(), x), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f942(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srli_epi16(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f943(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srli_epi16(_mm512_slli_epi16(x, 1), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f944(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srli_epi16(_mm512_srli_epi16(x, 1), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f945(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srli_epi16(_mm512_srai_epi16(x, 1), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f946(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srli_epi16(_mm512_slli_epi16(x, 15), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f947(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srli_epi16(_mm512_srli_epi16(x, 15), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f948(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srli_epi16(_mm512_srai_epi16(x, 15), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f949(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srli_epi16(_mm512_slli_epi32(x, 1), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f950(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srli_epi16(_mm512_srli_epi32(x, 1), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f951(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srli_epi16(_mm512_srai_epi32(x, 1), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f952(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srli_epi16(_mm512_slli_epi32(x, 31), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f953(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srli_epi16(_mm512_srli_epi32(x, 31), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f954(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srli_epi16(_mm512_srai_epi32(x, 31), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f955(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srli_epi16(_mm512_slli_epi64(x, 1), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f956(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srli_epi16(_mm512_srli_epi64(x, 1), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f957(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srli_epi16(_mm512_srai_epi64(x, 1), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f958(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srli_epi16(_mm512_slli_epi64(x, 63), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f959(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srli_epi16(_mm512_srli_epi64(x, 63), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f960(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srli_epi16(_mm512_srai_epi64(x, 63), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f961(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srai_epi16(_mm512_abs_epi8(x), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f962(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srai_epi16(_mm512_abs_epi16(x), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f963(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srai_epi16(_mm512_abs_epi32(x), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f964(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srai_epi16(_mm512_abs_epi64(x), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f965(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srai_epi16(_mm512_sub_epi8(_mm512_setzero_si512(), x), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f966(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srai_epi16(_mm512_sub_epi16(_mm512_setzero_si512(), x), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f967(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srai_epi16(_mm512_sub_epi32(_mm512_setzero_si512(), x), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f968(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srai_epi16(_mm512_sub_epi64(_mm512_setzero_si512(), x), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f969(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srai_epi16(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f970(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srai_epi16(_mm512_slli_epi16(x, 1), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f971(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srai_epi16(_mm512_srli_epi16(x, 1), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f972(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srai_epi16(_mm512_srai_epi16(x, 1), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f973(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srai_epi16(_mm512_slli_epi16(x, 15), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f974(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srai_epi16(_mm512_srli_epi16(x, 15), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f975(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srai_epi16(_mm512_srai_epi16(x, 15), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f976(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srai_epi16(_mm512_slli_epi32(x, 1), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f977(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srai_epi16(_mm512_srli_epi32(x, 1), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f978(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srai_epi16(_mm512_srai_epi32(x, 1), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f979(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srai_epi16(_mm512_slli_epi32(x, 31), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f980(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srai_epi16(_mm512_srli_epi32(x, 31), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f981(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srai_epi16(_mm512_srai_epi32(x, 31), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f982(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srai_epi16(_mm512_slli_epi64(x, 1), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f983(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srai_epi16(_mm512_srli_epi64(x, 1), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f984(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srai_epi16(_mm512_srai_epi64(x, 1), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f985(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srai_epi16(_mm512_slli_epi64(x, 63), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f986(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srai_epi16(_mm512_srli_epi64(x, 63), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f987(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srai_epi16(_mm512_srai_epi64(x, 63), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f988(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_slli_epi16(_mm512_abs_epi8(x), 15); _mm512_storeu_si512(po, r); }
static NOINLINE void f989(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_slli_epi16(_mm512_abs_epi16(x), 15); _mm512_storeu_si512(po, r); }
static NOINLINE void f990(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_slli_epi16(_mm512_abs_epi32(x), 15); _mm512_storeu_si512(po, r); }
static NOINLINE void f991(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_slli_epi16(_mm512_abs_epi64(x), 15); _mm512_storeu_si512(po, r); }
static NOINLINE void f992(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_slli_epi16(_mm512_sub_epi8(_mm512_setzero_si512(), x), 15); _mm512_storeu_si512(po, r); }
static NOINLINE void f993(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_slli_epi16(_mm512_sub_epi16(_mm512_setzero_si512(), x), 15); _mm512_storeu_si512(po, r); }
static NOINLINE void f994(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_slli_epi16(_mm512_sub_epi32(_mm512_setzero_si512(), x), 15); _mm512_storeu_si512(po, r); }
static NOINLINE void f995(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_slli_epi16(_mm512_sub_epi64(_mm512_setzero_si512(), x), 15); _mm512_storeu_si512(po, r); }
static NOINLINE void f996(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_slli_epi16(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), 15); _mm512_storeu_si512(po, r); }
static NOINLINE void f997(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_slli_epi16(_mm512_slli_epi16(x, 1), 15); _mm512_storeu_si512(po, r); }
static NOINLINE void f998(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_slli_epi16(_mm512_srli_epi16(x, 1), 15); _mm512_storeu_si512(po, r); }
static NOINLINE void f999(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_slli_epi16(_mm512_srai_epi16(x, 1), 15); _mm512_storeu_si512(po, r); }
static NOINLINE void f1000(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_slli_epi16(_mm512_slli_epi16(x, 15), 15); _mm512_storeu_si512(po, r); }
static NOINLINE void f1001(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_slli_epi16(_mm512_srli_epi16(x, 15), 15); _mm512_storeu_si512(po, r); }
static NOINLINE void f1002(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_slli_epi16(_mm512_srai_epi16(x, 15), 15); _mm512_storeu_si512(po, r); }
static NOINLINE void f1003(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_slli_epi16(_mm512_slli_epi32(x, 1), 15); _mm512_storeu_si512(po, r); }
static NOINLINE void f1004(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_slli_epi16(_mm512_srli_epi32(x, 1), 15); _mm512_storeu_si512(po, r); }
static NOINLINE void f1005(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_slli_epi16(_mm512_srai_epi32(x, 1), 15); _mm512_storeu_si512(po, r); }
static NOINLINE void f1006(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_slli_epi16(_mm512_slli_epi32(x, 31), 15); _mm512_storeu_si512(po, r); }
static NOINLINE void f1007(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_slli_epi16(_mm512_srli_epi32(x, 31), 15); _mm512_storeu_si512(po, r); }
static NOINLINE void f1008(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_slli_epi16(_mm512_srai_epi32(x, 31), 15); _mm512_storeu_si512(po, r); }
static NOINLINE void f1009(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_slli_epi16(_mm512_slli_epi64(x, 1), 15); _mm512_storeu_si512(po, r); }
static NOINLINE void f1010(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_slli_epi16(_mm512_srli_epi64(x, 1), 15); _mm512_storeu_si512(po, r); }
static NOINLINE void f1011(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_slli_epi16(_mm512_srai_epi64(x, 1), 15); _mm512_storeu_si512(po, r); }
static NOINLINE void f1012(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_slli_epi16(_mm512_slli_epi64(x, 63), 15); _mm512_storeu_si512(po, r); }
static NOINLINE void f1013(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_slli_epi16(_mm512_srli_epi64(x, 63), 15); _mm512_storeu_si512(po, r); }
static NOINLINE void f1014(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_slli_epi16(_mm512_srai_epi64(x, 63), 15); _mm512_storeu_si512(po, r); }
static NOINLINE void f1015(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srli_epi16(_mm512_abs_epi8(x), 15); _mm512_storeu_si512(po, r); }
static NOINLINE void f1016(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srli_epi16(_mm512_abs_epi16(x), 15); _mm512_storeu_si512(po, r); }
static NOINLINE void f1017(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srli_epi16(_mm512_abs_epi32(x), 15); _mm512_storeu_si512(po, r); }
static NOINLINE void f1018(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srli_epi16(_mm512_abs_epi64(x), 15); _mm512_storeu_si512(po, r); }
static NOINLINE void f1019(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srli_epi16(_mm512_sub_epi8(_mm512_setzero_si512(), x), 15); _mm512_storeu_si512(po, r); }
static NOINLINE void f1020(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srli_epi16(_mm512_sub_epi16(_mm512_setzero_si512(), x), 15); _mm512_storeu_si512(po, r); }
static NOINLINE void f1021(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srli_epi16(_mm512_sub_epi32(_mm512_setzero_si512(), x), 15); _mm512_storeu_si512(po, r); }
static NOINLINE void f1022(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srli_epi16(_mm512_sub_epi64(_mm512_setzero_si512(), x), 15); _mm512_storeu_si512(po, r); }
static NOINLINE void f1023(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srli_epi16(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), 15); _mm512_storeu_si512(po, r); }
static NOINLINE void f1024(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srli_epi16(_mm512_slli_epi16(x, 1), 15); _mm512_storeu_si512(po, r); }
static NOINLINE void f1025(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srli_epi16(_mm512_srli_epi16(x, 1), 15); _mm512_storeu_si512(po, r); }
static NOINLINE void f1026(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srli_epi16(_mm512_srai_epi16(x, 1), 15); _mm512_storeu_si512(po, r); }
static NOINLINE void f1027(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srli_epi16(_mm512_slli_epi16(x, 15), 15); _mm512_storeu_si512(po, r); }
static NOINLINE void f1028(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srli_epi16(_mm512_srli_epi16(x, 15), 15); _mm512_storeu_si512(po, r); }
static NOINLINE void f1029(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srli_epi16(_mm512_srai_epi16(x, 15), 15); _mm512_storeu_si512(po, r); }
static NOINLINE void f1030(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srli_epi16(_mm512_slli_epi32(x, 1), 15); _mm512_storeu_si512(po, r); }
static NOINLINE void f1031(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srli_epi16(_mm512_srli_epi32(x, 1), 15); _mm512_storeu_si512(po, r); }
static NOINLINE void f1032(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srli_epi16(_mm512_srai_epi32(x, 1), 15); _mm512_storeu_si512(po, r); }
static NOINLINE void f1033(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srli_epi16(_mm512_slli_epi32(x, 31), 15); _mm512_storeu_si512(po, r); }
static NOINLINE void f1034(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srli_epi16(_mm512_srli_epi32(x, 31), 15); _mm512_storeu_si512(po, r); }
static NOINLINE void f1035(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srli_epi16(_mm512_srai_epi32(x, 31), 15); _mm512_storeu_si512(po, r); }
static NOINLINE void f1036(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srli_epi16(_mm512_slli_epi64(x, 1), 15); _mm512_storeu_si512(po, r); }
static NOINLINE void f1037(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srli_epi16(_mm512_srli_epi64(x, 1), 15); _mm512_storeu_si512(po, r); }
static NOINLINE void f1038(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srli_epi16(_mm512_srai_epi64(x, 1), 15); _mm512_storeu_si512(po, r); }
static NOINLINE void f1039(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srli_epi16(_mm512_slli_epi64(x, 63), 15); _mm512_storeu_si512(po, r); }
static NOINLINE void f1040(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srli_epi16(_mm512_srli_epi64(x, 63), 15); _mm512_storeu_si512(po, r); }
static NOINLINE void f1041(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srli_epi16(_mm512_srai_epi64(x, 63), 15); _mm512_storeu_si512(po, r); }
static NOINLINE void f1042(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srai_epi16(_mm512_abs_epi8(x), 15); _mm512_storeu_si512(po, r); }
static NOINLINE void f1043(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srai_epi16(_mm512_abs_epi16(x), 15); _mm512_storeu_si512(po, r); }
static NOINLINE void f1044(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srai_epi16(_mm512_abs_epi32(x), 15); _mm512_storeu_si512(po, r); }
static NOINLINE void f1045(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srai_epi16(_mm512_abs_epi64(x), 15); _mm512_storeu_si512(po, r); }
static NOINLINE void f1046(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srai_epi16(_mm512_sub_epi8(_mm512_setzero_si512(), x), 15); _mm512_storeu_si512(po, r); }
static NOINLINE void f1047(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srai_epi16(_mm512_sub_epi16(_mm512_setzero_si512(), x), 15); _mm512_storeu_si512(po, r); }
static NOINLINE void f1048(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srai_epi16(_mm512_sub_epi32(_mm512_setzero_si512(), x), 15); _mm512_storeu_si512(po, r); }
static NOINLINE void f1049(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srai_epi16(_mm512_sub_epi64(_mm512_setzero_si512(), x), 15); _mm512_storeu_si512(po, r); }
static NOINLINE void f1050(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srai_epi16(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), 15); _mm512_storeu_si512(po, r); }
static NOINLINE void f1051(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srai_epi16(_mm512_slli_epi16(x, 1), 15); _mm512_storeu_si512(po, r); }
static NOINLINE void f1052(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srai_epi16(_mm512_srli_epi16(x, 1), 15); _mm512_storeu_si512(po, r); }
static NOINLINE void f1053(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srai_epi16(_mm512_srai_epi16(x, 1), 15); _mm512_storeu_si512(po, r); }
static NOINLINE void f1054(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srai_epi16(_mm512_slli_epi16(x, 15), 15); _mm512_storeu_si512(po, r); }
static NOINLINE void f1055(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srai_epi16(_mm512_srli_epi16(x, 15), 15); _mm512_storeu_si512(po, r); }
static NOINLINE void f1056(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srai_epi16(_mm512_srai_epi16(x, 15), 15); _mm512_storeu_si512(po, r); }
static NOINLINE void f1057(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srai_epi16(_mm512_slli_epi32(x, 1), 15); _mm512_storeu_si512(po, r); }
static NOINLINE void f1058(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srai_epi16(_mm512_srli_epi32(x, 1), 15); _mm512_storeu_si512(po, r); }
static NOINLINE void f1059(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srai_epi16(_mm512_srai_epi32(x, 1), 15); _mm512_storeu_si512(po, r); }
static NOINLINE void f1060(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srai_epi16(_mm512_slli_epi32(x, 31), 15); _mm512_storeu_si512(po, r); }
static NOINLINE void f1061(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srai_epi16(_mm512_srli_epi32(x, 31), 15); _mm512_storeu_si512(po, r); }
static NOINLINE void f1062(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srai_epi16(_mm512_srai_epi32(x, 31), 15); _mm512_storeu_si512(po, r); }
static NOINLINE void f1063(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srai_epi16(_mm512_slli_epi64(x, 1), 15); _mm512_storeu_si512(po, r); }
static NOINLINE void f1064(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srai_epi16(_mm512_srli_epi64(x, 1), 15); _mm512_storeu_si512(po, r); }
static NOINLINE void f1065(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srai_epi16(_mm512_srai_epi64(x, 1), 15); _mm512_storeu_si512(po, r); }
static NOINLINE void f1066(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srai_epi16(_mm512_slli_epi64(x, 63), 15); _mm512_storeu_si512(po, r); }
static NOINLINE void f1067(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srai_epi16(_mm512_srli_epi64(x, 63), 15); _mm512_storeu_si512(po, r); }
static NOINLINE void f1068(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srai_epi16(_mm512_srai_epi64(x, 63), 15); _mm512_storeu_si512(po, r); }
static NOINLINE void f1069(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_slli_epi32(_mm512_abs_epi8(x), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f1070(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_slli_epi32(_mm512_abs_epi16(x), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f1071(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_slli_epi32(_mm512_abs_epi32(x), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f1072(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_slli_epi32(_mm512_abs_epi64(x), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f1073(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_slli_epi32(_mm512_sub_epi8(_mm512_setzero_si512(), x), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f1074(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_slli_epi32(_mm512_sub_epi16(_mm512_setzero_si512(), x), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f1075(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_slli_epi32(_mm512_sub_epi32(_mm512_setzero_si512(), x), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f1076(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_slli_epi32(_mm512_sub_epi64(_mm512_setzero_si512(), x), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f1077(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_slli_epi32(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f1078(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_slli_epi32(_mm512_slli_epi16(x, 1), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f1079(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_slli_epi32(_mm512_srli_epi16(x, 1), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f1080(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_slli_epi32(_mm512_srai_epi16(x, 1), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f1081(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_slli_epi32(_mm512_slli_epi16(x, 15), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f1082(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_slli_epi32(_mm512_srli_epi16(x, 15), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f1083(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_slli_epi32(_mm512_srai_epi16(x, 15), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f1084(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_slli_epi32(_mm512_slli_epi32(x, 1), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f1085(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_slli_epi32(_mm512_srli_epi32(x, 1), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f1086(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_slli_epi32(_mm512_srai_epi32(x, 1), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f1087(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_slli_epi32(_mm512_slli_epi32(x, 31), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f1088(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_slli_epi32(_mm512_srli_epi32(x, 31), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f1089(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_slli_epi32(_mm512_srai_epi32(x, 31), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f1090(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_slli_epi32(_mm512_slli_epi64(x, 1), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f1091(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_slli_epi32(_mm512_srli_epi64(x, 1), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f1092(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_slli_epi32(_mm512_srai_epi64(x, 1), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f1093(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_slli_epi32(_mm512_slli_epi64(x, 63), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f1094(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_slli_epi32(_mm512_srli_epi64(x, 63), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f1095(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_slli_epi32(_mm512_srai_epi64(x, 63), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f1096(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srli_epi32(_mm512_abs_epi8(x), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f1097(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srli_epi32(_mm512_abs_epi16(x), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f1098(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srli_epi32(_mm512_abs_epi32(x), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f1099(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srli_epi32(_mm512_abs_epi64(x), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f1100(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srli_epi32(_mm512_sub_epi8(_mm512_setzero_si512(), x), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f1101(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srli_epi32(_mm512_sub_epi16(_mm512_setzero_si512(), x), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f1102(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srli_epi32(_mm512_sub_epi32(_mm512_setzero_si512(), x), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f1103(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srli_epi32(_mm512_sub_epi64(_mm512_setzero_si512(), x), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f1104(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srli_epi32(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f1105(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srli_epi32(_mm512_slli_epi16(x, 1), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f1106(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srli_epi32(_mm512_srli_epi16(x, 1), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f1107(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srli_epi32(_mm512_srai_epi16(x, 1), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f1108(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srli_epi32(_mm512_slli_epi16(x, 15), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f1109(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srli_epi32(_mm512_srli_epi16(x, 15), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f1110(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srli_epi32(_mm512_srai_epi16(x, 15), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f1111(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srli_epi32(_mm512_slli_epi32(x, 1), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f1112(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srli_epi32(_mm512_srli_epi32(x, 1), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f1113(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srli_epi32(_mm512_srai_epi32(x, 1), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f1114(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srli_epi32(_mm512_slli_epi32(x, 31), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f1115(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srli_epi32(_mm512_srli_epi32(x, 31), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f1116(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srli_epi32(_mm512_srai_epi32(x, 31), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f1117(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srli_epi32(_mm512_slli_epi64(x, 1), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f1118(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srli_epi32(_mm512_srli_epi64(x, 1), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f1119(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srli_epi32(_mm512_srai_epi64(x, 1), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f1120(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srli_epi32(_mm512_slli_epi64(x, 63), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f1121(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srli_epi32(_mm512_srli_epi64(x, 63), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f1122(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srli_epi32(_mm512_srai_epi64(x, 63), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f1123(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srai_epi32(_mm512_abs_epi8(x), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f1124(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srai_epi32(_mm512_abs_epi16(x), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f1125(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srai_epi32(_mm512_abs_epi32(x), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f1126(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srai_epi32(_mm512_abs_epi64(x), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f1127(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srai_epi32(_mm512_sub_epi8(_mm512_setzero_si512(), x), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f1128(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srai_epi32(_mm512_sub_epi16(_mm512_setzero_si512(), x), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f1129(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srai_epi32(_mm512_sub_epi32(_mm512_setzero_si512(), x), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f1130(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srai_epi32(_mm512_sub_epi64(_mm512_setzero_si512(), x), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f1131(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srai_epi32(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f1132(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srai_epi32(_mm512_slli_epi16(x, 1), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f1133(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srai_epi32(_mm512_srli_epi16(x, 1), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f1134(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srai_epi32(_mm512_srai_epi16(x, 1), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f1135(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srai_epi32(_mm512_slli_epi16(x, 15), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f1136(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srai_epi32(_mm512_srli_epi16(x, 15), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f1137(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srai_epi32(_mm512_srai_epi16(x, 15), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f1138(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srai_epi32(_mm512_slli_epi32(x, 1), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f1139(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srai_epi32(_mm512_srli_epi32(x, 1), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f1140(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srai_epi32(_mm512_srai_epi32(x, 1), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f1141(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srai_epi32(_mm512_slli_epi32(x, 31), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f1142(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srai_epi32(_mm512_srli_epi32(x, 31), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f1143(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srai_epi32(_mm512_srai_epi32(x, 31), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f1144(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srai_epi32(_mm512_slli_epi64(x, 1), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f1145(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srai_epi32(_mm512_srli_epi64(x, 1), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f1146(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srai_epi32(_mm512_srai_epi64(x, 1), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f1147(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srai_epi32(_mm512_slli_epi64(x, 63), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f1148(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srai_epi32(_mm512_srli_epi64(x, 63), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f1149(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srai_epi32(_mm512_srai_epi64(x, 63), 1); _mm512_storeu_si512(po, r); }
static NOINLINE void f1150(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_slli_epi32(_mm512_abs_epi8(x), 31); _mm512_storeu_si512(po, r); }
static NOINLINE void f1151(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_slli_epi32(_mm512_abs_epi16(x), 31); _mm512_storeu_si512(po, r); }
static NOINLINE void f1152(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_slli_epi32(_mm512_abs_epi32(x), 31); _mm512_storeu_si512(po, r); }
static NOINLINE void f1153(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_slli_epi32(_mm512_abs_epi64(x), 31); _mm512_storeu_si512(po, r); }
static NOINLINE void f1154(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_slli_epi32(_mm512_sub_epi8(_mm512_setzero_si512(), x), 31); _mm512_storeu_si512(po, r); }
static NOINLINE void f1155(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_slli_epi32(_mm512_sub_epi16(_mm512_setzero_si512(), x), 31); _mm512_storeu_si512(po, r); }
static NOINLINE void f1156(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_slli_epi32(_mm512_sub_epi32(_mm512_setzero_si512(), x), 31); _mm512_storeu_si512(po, r); }
static NOINLINE void f1157(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_slli_epi32(_mm512_sub_epi64(_mm512_setzero_si512(), x), 31); _mm512_storeu_si512(po, r); }
static NOINLINE void f1158(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_slli_epi32(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), 31); _mm512_storeu_si512(po, r); }
static NOINLINE void f1159(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_slli_epi32(_mm512_slli_epi16(x, 1), 31); _mm512_storeu_si512(po, r); }
static NOINLINE void f1160(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_slli_epi32(_mm512_srli_epi16(x, 1), 31); _mm512_storeu_si512(po, r); }
static NOINLINE void f1161(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_slli_epi32(_mm512_srai_epi16(x, 1), 31); _mm512_storeu_si512(po, r); }
static NOINLINE void f1162(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_slli_epi32(_mm512_slli_epi16(x, 15), 31); _mm512_storeu_si512(po, r); }
static NOINLINE void f1163(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_slli_epi32(_mm512_srli_epi16(x, 15), 31); _mm512_storeu_si512(po, r); }
static NOINLINE void f1164(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_slli_epi32(_mm512_srai_epi16(x, 15), 31); _mm512_storeu_si512(po, r); }
static NOINLINE void f1165(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_slli_epi32(_mm512_slli_epi32(x, 1), 31); _mm512_storeu_si512(po, r); }
static NOINLINE void f1166(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_slli_epi32(_mm512_srli_epi32(x, 1), 31); _mm512_storeu_si512(po, r); }
static NOINLINE void f1167(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_slli_epi32(_mm512_srai_epi32(x, 1), 31); _mm512_storeu_si512(po, r); }
static NOINLINE void f1168(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_slli_epi32(_mm512_slli_epi32(x, 31), 31); _mm512_storeu_si512(po, r); }
static NOINLINE void f1169(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_slli_epi32(_mm512_srli_epi32(x, 31), 31); _mm512_storeu_si512(po, r); }
static NOINLINE void f1170(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_slli_epi32(_mm512_srai_epi32(x, 31), 31); _mm512_storeu_si512(po, r); }
static NOINLINE void f1171(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_slli_epi32(_mm512_slli_epi64(x, 1), 31); _mm512_storeu_si512(po, r); }
static NOINLINE void f1172(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_slli_epi32(_mm512_srli_epi64(x, 1), 31); _mm512_storeu_si512(po, r); }
static NOINLINE void f1173(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_slli_epi32(_mm512_srai_epi64(x, 1), 31); _mm512_storeu_si512(po, r); }
static NOINLINE void f1174(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_slli_epi32(_mm512_slli_epi64(x, 63), 31); _mm512_storeu_si512(po, r); }
static NOINLINE void f1175(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_slli_epi32(_mm512_srli_epi64(x, 63), 31); _mm512_storeu_si512(po, r); }
static NOINLINE void f1176(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_slli_epi32(_mm512_srai_epi64(x, 63), 31); _mm512_storeu_si512(po, r); }
static NOINLINE void f1177(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srli_epi32(_mm512_abs_epi8(x), 31); _mm512_storeu_si512(po, r); }
static NOINLINE void f1178(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srli_epi32(_mm512_abs_epi16(x), 31); _mm512_storeu_si512(po, r); }
static NOINLINE void f1179(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srli_epi32(_mm512_abs_epi32(x), 31); _mm512_storeu_si512(po, r); }
static NOINLINE void f1180(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srli_epi32(_mm512_abs_epi64(x), 31); _mm512_storeu_si512(po, r); }
static NOINLINE void f1181(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srli_epi32(_mm512_sub_epi8(_mm512_setzero_si512(), x), 31); _mm512_storeu_si512(po, r); }
static NOINLINE void f1182(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srli_epi32(_mm512_sub_epi16(_mm512_setzero_si512(), x), 31); _mm512_storeu_si512(po, r); }
static NOINLINE void f1183(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srli_epi32(_mm512_sub_epi32(_mm512_setzero_si512(), x), 31); _mm512_storeu_si512(po, r); }
static NOINLINE void f1184(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srli_epi32(_mm512_sub_epi64(_mm512_setzero_si512(), x), 31); _mm512_storeu_si512(po, r); }
static NOINLINE void f1185(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srli_epi32(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), 31); _mm512_storeu_si512(po, r); }
static NOINLINE void f1186(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srli_epi32(_mm512_slli_epi16(x, 1), 31); _mm512_storeu_si512(po, r); }
static NOINLINE void f1187(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srli_epi32(_mm512_srli_epi16(x, 1), 31); _mm512_storeu_si512(po, r); }
static NOINLINE void f1188(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srli_epi32(_mm512_srai_epi16(x, 1), 31); _mm512_storeu_si512(po, r); }
static NOINLINE void f1189(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srli_epi32(_mm512_slli_epi16(x, 15), 31); _mm512_storeu_si512(po, r); }
static NOINLINE void f1190(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srli_epi32(_mm512_srli_epi16(x, 15), 31); _mm512_storeu_si512(po, r); }
static NOINLINE void f1191(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srli_epi32(_mm512_srai_epi16(x, 15), 31); _mm512_storeu_si512(po, r); }
static NOINLINE void f1192(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srli_epi32(_mm512_slli_epi32(x, 1), 31); _mm512_storeu_si512(po, r); }
static NOINLINE void f1193(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srli_epi32(_mm512_srli_epi32(x, 1), 31); _mm512_storeu_si512(po, r); }
static NOINLINE void f1194(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srli_epi32(_mm512_srai_epi32(x, 1), 31); _mm512_storeu_si512(po, r); }
static NOINLINE void f1195(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srli_epi32(_mm512_slli_epi32(x, 31), 31); _mm512_storeu_si512(po, r); }
static NOINLINE void f1196(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srli_epi32(_mm512_srli_epi32(x, 31), 31); _mm512_storeu_si512(po, r); }
static NOINLINE void f1197(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srli_epi32(_mm512_srai_epi32(x, 31), 31); _mm512_storeu_si512(po, r); }
static NOINLINE void f1198(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srli_epi32(_mm512_slli_epi64(x, 1), 31); _mm512_storeu_si512(po, r); }
static NOINLINE void f1199(const void* px, const void* py, void* po) { const __m512i x = _mm512_loadu_si512(px); const __m512i y = _mm512_loadu_si512(py); (void)y; const __m512i r = _mm512_srli_epi32(_mm512_srli_epi64(x, 1), 31); _mm512_storeu_si512(po, r); }
extern const Entry table_86[] = {
  {"256:_mm256_round_pd(_mm256_fmsub_pd(_mm256_set1_pd(std::numeric_limits<double>::infinity()), x, y), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)", f0, 2, 256},
  {"256:_mm256_permute_pd(_mm256_fmsub_pd(_mm256_set1_pd(std::numeric_limits<double>::infinity()), x, y), 0x5)", f1, 2, 256},
  {"256:_mm256_permute_pd(_mm256_fmsub_pd(_mm256_set1_pd(std::numeric_limits<double>::infinity()), x, y), 0xa)", f2, 2, 256},
  {"256:_mm256_permute_pd(_mm256_fmsub_pd(_mm256_set1_pd(std::numeric_limits<double>::infinity()), x, y), 0x3)", f3, 2, 256},
  {"256:_mm256_sqrt_pd(_mm256_fmsub_pd(x, y, _mm256_set1_pd(std::numeric_limits<double>::quiet_NaN())))", f4, 2, 256},
  {"256:_mm256_xor_pd(_mm256_fmsub_pd(x, y, _mm256_set1_pd(std::numeric_limits<double>::quiet_NaN())), _mm256_set1_pd(-0.0))", f5, 2, 256},
  {"256:_mm256_andnot_pd(_mm256_set1_pd(-0.0), _mm256_fmsub_pd(x, y, _mm256_set1_pd(std::numeric_limits<double>::quiet_NaN())))", f6, 2, 256},
  {"256:_mm256_sub_pd(_mm256_setzero_pd(), _mm256_fmsub_pd(x, y, _mm256_set1_pd(std::numeric_limits<double>::quiet_NaN())))", f7, 2, 256},
  {"256:_mm256_mul_pd(_mm256_fmsub_pd(x, y, _mm256_set1_pd(std::numeric_limits<double>::quiet_NaN())), _mm256_set1_pd(-1.0))", f8, 2, 256},
  {"256:_mm256_floor_pd(_mm256_fmsub_pd(x, y, _mm256_set1_pd(std::numeric_limits<double>::quiet_NaN())))", f9, 2, 256},
  {"256:_mm256_ceil_pd(_mm256_fmsub_pd(x, y, _mm256_set1_pd(std::numeric_limits<double>::quiet_NaN())))", f10, 2, 256},
  {"256:_mm256_round_pd(_mm256_fmsub_pd(x, y, _mm256_set1_pd(std::numeric_limits<double>::quiet_NaN())), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)", f11, 2, 256},
  {"256:_mm256_permute_pd(_mm256_fmsub_pd(x, y, _mm256_set1_pd(std::numeric_limits<double>::quiet_NaN())), 0x5)", f12, 2, 256},
  {"256:_mm256_permute_pd(_mm256_fmsub_pd(x, y, _mm256_set1_pd(std::numeric_limits<double>::quiet_NaN())), 0xa)", f13, 2, 256},
  {"256:_mm256_permute_pd(_mm256_fmsub_pd(x, y, _mm256_set1_pd(std::numeric_limits<double>::quiet_NaN())), 0x3)", f14, 2, 256},
  {"256:_mm256_sqrt_pd(_mm256_fmsub_pd(x, _mm256_set1_pd(std::numeric_limits<double>::quiet_NaN()), y))", f15, 2, 256},
  {"256:_mm256_xor_pd(_mm256_fmsub_pd(x, _mm256_set1_pd(std::numeric_limits<double>::quiet_NaN()), y), _mm256_set1_pd(-0.0))", f16, 2, 256},
  {"256:_mm256_andnot_pd(_mm256_set1_pd(-0.0), _mm256_fmsub_pd(x, _mm256_set1_pd(std::numeric_limits<double>::quiet_NaN()), y))", f17, 2, 256},
  {"256:_mm256_sub_pd(_mm256_setzero_pd(), _mm256_fmsub_pd(x, _mm256_set1_pd(std::numeric_limits<double>::quiet_NaN()), y))", f18, 2, 256},
  {"256:_mm256_mul_pd(_mm256_fmsub_pd(x, _mm256_set1_pd(std::numeric_limits<double>::quiet_NaN()), y), _mm256_set1_pd(-1.0))", f19, 2, 256},
  {"256:_mm256_floor_pd(_mm256_fmsub_pd(x, _mm256_set1_pd(std::numeric_limits<double>::quiet_NaN()), y))", f20, 2, 256},
  {"256:_mm256_ceil_pd(_mm256_fmsub_pd(x, _mm256_set1_pd(std::numeric_limits<double>::quiet_NaN()), y))", f21, 2, 256},
  {"256:_mm256_round_pd(_mm256_fmsub_pd(x, _mm256_set1_pd(std::numeric_limits<double>::quiet_NaN()), y), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)", f22, 2, 256},
  {"256:_mm256_permute_pd(_mm256_fmsub_pd(x, _mm256_set1_pd(std::numeric_limits<double>::quiet_NaN()), y), 0x5)", f23, 2, 256},
  {"256:_mm256_permute_pd(_mm256_fmsub_pd(x, _mm256_set1_pd(std::numeric_limits<double>::quiet_NaN()), y), 0xa)", f24, 2, 256},
  {"256:_mm256_permute_pd(_mm256_fmsub_pd(x, _mm256_set1_pd(std::numeric_limits<double>::quiet_NaN()), y), 0x3)", f25, 2, 256},
  {"256:_mm256_sqrt_pd(_mm256_fmsub_pd(_mm256_set1_pd(std::numeric_limits<double>::quiet_NaN()), x, y))", f26, 2, 256},
  {"256:_mm256_xor_pd(_mm256_fmsub_pd(_mm256_set1_pd(std::numeric_limits<double>::quiet_NaN()), x, y), _mm256_set1_pd(-0.0))", f27, 2, 256},
  {"256:_mm256_andnot_pd(_mm256_set1_pd(-0.0), _mm256_fmsub_pd(_mm256_set1_pd(std::numeric_limits<double>::quiet_NaN()), x, y))", f28, 2, 256},
  {"256:_mm256_sub_pd(_mm256_setzero_pd(), _mm256_fmsub_pd(_mm256_set1_pd(std::numeric_limits<double>::quiet_NaN()), x, y))", f29, 2, 256},
  {"256:_mm256_mul_pd(_mm256_fmsub_pd(_mm256_set1_pd(std::numeric_limits<double>::quiet_NaN()), x, y), _mm256_set1_pd(-1.0))", f30, 2, 256},
  {"256:_mm256_floor_pd(_mm256_fmsub_pd(_mm256_set1_pd(std::numeric_limits<double>::quiet_NaN()), x, y))", f31, 2, 256},
  {"256:_mm256_ceil_pd(_mm256_fmsub_pd(_mm256_set1_pd(std::numeric_limits<double>::quiet_NaN()), x, y))", f32, 2, 256},
  {"256:_mm256_round_pd(_mm256_fmsub_pd(_mm256_set1_pd(std::numeric_limits<double>::quiet_NaN()), x, y), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)", f33, 2, 256},
  {"256:_mm256_permute_pd(_mm256_fmsub_pd(_mm256_set1_pd(std::numeric_limits<double>::quiet_NaN()), x, y), 0x5)", f34, 2, 256},
  {"256:_mm256_permute_pd(_mm256_fmsub_pd(_mm256_set1_pd(std::numeric_limits<double>::quiet_NaN()), x, y), 0xa)", f35, 2, 256},
  {"256:_mm256_permute_pd(_mm256_fmsub_pd(_mm256_set1_pd(std::numeric_limits<double>::quiet_NaN()), x, y), 0x3)", f36, 2, 256},
  {"256:_mm256_sqrt_pd(_mm256_fmsub_pd(x, y, x))", f37, 2, 256},
  {"256:_mm256_xor_pd(_mm256_fmsub_pd(x, y, x), _mm256_set1_pd(-0.0))", f38, 2, 256},
  {"256:_mm256_andnot_pd(_mm256_set1_pd(-0.0), _mm256_fmsub_pd(x, y, x))", f39, 2, 256},
  {"256:_mm256_sub_pd(_mm256_setzero_pd(), _mm256_fmsub_pd(x, y, x))", f40, 2, 256},
  {"256:_mm256_mul_pd(_mm256_fmsub_pd(x, y, x), _mm256_set1_pd(-1.0))", f41, 2, 256},
  {"256:_mm256_floor_pd(_mm256_fmsub_pd(x, y, x))", f42, 2, 256},
  {"256:_mm256_ceil_pd(_mm256_fmsub_pd(x, y, x))", f43, 2, 256},
  {"256:_mm256_round_pd(_mm256_fmsub_pd(x, y, x), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)", f44, 2, 256},
  {"256:_mm256_permute_pd(_mm256_fmsub_pd(x, y, x), 0x5)", f45, 2, 256},
  {"256:_mm256_permute_pd(_mm256_fmsub_pd(x, y, x), 0xa)", f46, 2, 256},
  {"256:_mm256_permute_pd(_mm256_fmsub_pd(x, y, x), 0x3)", f47, 2, 256},
  {"256:_mm256_sqrt_pd(_mm256_fmsub_pd(x, x, y))", f48, 2, 256},
  {"256:_mm256_xor_pd(_mm256_fmsub_pd(x, x, y), _mm256_set1_pd(-0.0))", f49, 2, 256},
  {"256:_mm256_andnot_pd(_mm256_set1_pd(-0.0), _mm256_fmsub_pd(x, x, y))", f50, 2, 256},
  {"256:_mm256_sub_pd(_mm256_setzero_pd(), _mm256_fmsub_pd(x, x, y))", f51, 2, 256},
  {"256:_mm256_mul_pd(_mm256_fmsub_pd(x, x, y), _mm256_set1_pd(-1.0))", f52, 2, 256},
  {"256:_mm256_floor_pd(_mm256_fmsub_pd(x, x, y))", f53, 2, 256},
  {"256:_mm256_ceil_pd(_mm256_fmsub_pd(x, x, y))", f54, 2, 256},
  {"256:_mm256_round_pd(_mm256_fmsub_pd(x, x, y), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)", f55, 2, 256},
  {"256:_mm256_permute_pd(_mm256_fmsub_pd(x, x, y), 0x5)", f56, 2, 256},
  {"256:_mm256_permute_pd(_mm256_fmsub_pd(x, x, y), 0xa)", f57, 2, 256},
  {"256:_mm256_permute_pd(_mm256_fmsub_pd(x, x, y), 0x3)", f58, 2, 256},
  {"256:_mm256_sqrt_pd(_mm256_fmsub_pd(x, y, _mm256_mul_pd(x, y)))", f59, 2, 256},
  {"256:_mm256_xor_pd(_mm256_fmsub_pd(x, y, _mm256_mul_pd(x, y)), _mm256_set1_pd(-0.0))", f60, 2, 256},
  {"256:_mm256_andnot_pd(_mm256_set1_pd(-0.0), _mm256_fmsub_pd(x, y, _mm256_mul_pd(x, y)))", f61, 2, 256},
  {"256:_mm256_sub_pd(_mm256_setzero_pd(), _mm256_fmsub_pd(x, y, _mm256_mul_pd(x, y)))", f62, 2, 256},
  {"256:_mm256_mul_pd(_mm256_fmsub_pd(x, y, _mm256_mul_pd(x, y)), _mm256_set1_pd(-1.0))", f63, 2, 256},
  {"256:_mm256_floor_pd(_mm256_fmsub_pd(x, y, _mm256_mul_pd(x, y)))", f64, 2, 256},
  {"256:_mm256_ceil_pd(_mm256_fmsub_pd(x, y, _mm256_mul_pd(x, y)))", f65, 2, 256},
  {"256:_mm256_round_pd(_mm256_fmsub_pd(x, y, _mm256_mul_pd(x, y)), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)", f66, 2, 256},
  {"256:_mm256_permute_pd(_mm256_fmsub_pd(x, y, _mm256_mul_pd(x, y)), 0x5)", f67, 2, 256},
  {"256:_mm256_permute_pd(_mm256_fmsub_pd(x, y, _mm256_mul_pd(x, y)), 0xa)", f68, 2, 256},
  {"256:_mm256_permute_pd(_mm256_fmsub_pd(x, y, _mm256_mul_pd(x, y)), 0x3)", f69, 2, 256},
  {"256:_mm256_sqrt_pd(_mm256_fnmadd_pd(x, y, _mm256_setzero_pd()))", f70, 2, 256},
  {"256:_mm256_xor_pd(_mm256_fnmadd_pd(x, y, _mm256_setzero_pd()), _mm256_set1_pd(-0.0))", f71, 2, 256},
  {"256:_mm256_andnot_pd(_mm256_set1_pd(-0.0), _mm256_fnmadd_pd(x, y, _mm256_setzero_pd()))", f72, 2, 256},
  {"256:_mm256_sub_pd(_mm256_setzero_pd(), _mm256_fnmadd_pd(x, y, _mm256_setzero_pd()))", f73, 2, 256},
  {"256:_mm256_mul_pd(_mm256_fnmadd_pd(x, y, _mm256_setzero_pd()), _mm256_set1_pd(-1.0))", f74, 2, 256},
  {"256:_mm256_floor_pd(_mm256_fnmadd_pd(x, y, _mm256_setzero_pd()))", f75, 2, 256},
  {"256:_mm256_ceil_pd(_mm256_fnmadd_pd(x, y, _mm256_setzero_pd()))", f76, 2, 256},
  {"256:_mm256_round_pd(_mm256_fnmadd_pd(x, y, _mm256_setzero_pd()), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)", f77, 2, 256},
  {"256:_mm256_permute_pd(_mm256_fnmadd_pd(x, y, _mm256_setzero_pd()), 0x5)", f78, 2, 256},
  {"256:_mm256_permute_pd(_mm256_fnmadd_pd(x, y, _mm256_setzero_pd()), 0xa)", f79, 2, 256},
  {"256:_mm256_permute_pd(_mm256_fnmadd_pd(x, y, _mm256_setzero_pd()), 0x3)", f80, 2, 256},
  {"256:_mm256_sqrt_pd(_mm256_fnmadd_pd(x, _mm256_setzero_pd(), y))", f81, 2, 256},
  {"256:_mm256_xor_pd(_mm256_fnmadd_pd(x, _mm256_setzero_pd(), y), _mm256_set1_pd(-0.0))", f82, 2, 256},
  {"256:_mm256_andnot_pd(_mm256_set1_pd(-0.0), _mm256_fnmadd_pd(x, _mm256_setzero_pd(), y))", f83, 2, 256},
  {"256:_mm256_sub_pd(_mm256_setzero_pd(), _mm256_fnmadd_pd(x, _mm256_setzero_pd(), y))", f84, 2, 256},
  {"256:_mm256_mul_pd(_mm256_fnmadd_pd(x, _mm256_setzero_pd(), y), _mm256_set1_pd(-1.0))", f85, 2, 256},
  {"256:_mm256_floor_pd(_mm256_fnmadd_pd(x, _mm256_setzero_pd(), y))", f86, 2, 256},
  {"256:_mm256_ceil_pd(_mm256_fnmadd_pd(x, _mm256_setzero_pd(), y))", f87, 2, 256},
  {"256:_mm256_round_pd(_mm256_fnmadd_pd(x, _mm256_setzero_pd(), y), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)", f88, 2, 256},
  {"256:_mm256_permute_pd(_mm256_fnmadd_pd(x, _mm256_setzero_pd(), y), 0x5)", f89, 2, 256},
  {"256:_mm256_permute_pd(_mm256_fnmadd_pd(x, _mm256_setzero_pd(), y), 0xa)", f90, 2, 256},
  {"256:_mm256_permute_pd(_mm256_fnmadd_pd(x, _mm256_setzero_pd(), y), 0x3)", f91, 2, 256},
  {"256:_mm256_sqrt_pd(_mm256_fnmadd_pd(_mm256_setzero_pd(), x, y))", f92, 2, 256},
  {"256:_mm256_xor_pd(_mm256_fnmadd_pd(_mm256_setzero_pd(), x, y), _mm256_set1_pd(-0.0))", f93, 2, 256},
  {"256:_mm256_andnot_pd(_mm256_set1_pd(-0.0), _mm256_fnmadd_pd(_mm256_setzero_pd(), x, y))", f94, 2, 256},
  {"256:_mm256_sub_pd(_mm256_setzero_pd(), _mm256_fnmadd_pd(_mm256_setzero_pd(), x, y))", f95, 2, 256},
  {"256:_mm256_mul_pd(_mm256_fnmadd_pd(_mm256_setzero_pd(), x, y), _mm256_set1_pd(-1.0))", f96, 2, 256},
  {"256:_mm256_floor_pd(_mm256_fnmadd_pd(_mm256_setzero_pd(), x, y))", f97, 2, 256},
  {"256:_mm256_ceil_pd(_mm256_fnmadd_pd(_mm256_setzero_pd(), x, y))", f98, 2, 256},
  {"256:_mm256_round_pd(_mm256_fnmadd_pd(_mm256_setzero_pd(), x, y), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)", f99, 2, 256},
  {"256:_mm256_permute_pd(_mm256_fnmadd_pd(_mm256_setzero_pd(), x, y), 0x5)", f100, 2, 256},
  {"256:_mm256_permute_pd(_mm256_fnmadd_pd(_mm256_setzero_pd(), x, y), 0xa)", f101, 2, 256},
  {"256:_mm256_permute_pd(_mm256_fnmadd_pd(_mm256_setzero_pd(), x, y), 0x3)", f102, 2, 256},
  {"256:_mm256_sqrt_pd(_mm256_fnmadd_pd(x, y, _mm256_set1_pd(-0.0)))", f103, 2, 256},
  {"256:_mm256_xor_pd(_mm256_fnmadd_pd(x, y, _mm256_set1_pd(-0.0)), _mm256_set1_pd(-0.0))", f104, 2, 256},
  {"256:_mm256_andnot_pd(_mm256_set1_pd(-0.0), _mm256_fnmadd_pd(x, y, _mm256_set1_pd(-0.0)))", f105, 2, 256},
  {"256:_mm256_sub_pd(_mm256_setzero_pd(), _mm256_fnmadd_pd(x, y, _mm256_set1_pd(-0.0)))", f106, 2, 256},
  {"256:_mm256_mul_pd(_mm256_fnmadd_pd(x, y, _mm256_set1_pd(-0.0)), _mm256_set1_pd(-1.0))", f107, 2, 256},
  {"256:_mm256_floor_pd(_mm256_fnmadd_pd(x, y, _mm256_set1_pd(-0.0)))", f108, 2, 256},
  {"256:_mm256_ceil_pd(_mm256_fnmadd_pd(x, y, _mm256_set1_pd(-0.0)))", f109, 2, 256},
  {"256:_mm256_round_pd(_mm256_fnmadd_pd(x, y, _mm256_set1_pd(-0.0)), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)", f110, 2, 256},
  {"256:_mm256_permute_pd(_mm256_fnmadd_pd(x, y, _mm256_set1_pd(-0.0)), 0x5)", f111, 2, 256},
  {"256:_mm256_permute_pd(_mm256_fnmadd_pd(x, y, _mm256_set1_pd(-0.0)), 0xa)", f112, 2, 256},
  {"256:_mm256_permute_pd(_mm256_fnmadd_pd(x, y, _mm256_set1_pd(-0.0)), 0x3)", f113, 2, 256},
  {"256:_mm256_sqrt_pd(_mm256_fnmadd_pd(x, _mm256_set1_pd(-0.0), y))", f114, 2, 256},
  {"256:_mm256_xor_pd(_mm256_fnmadd_pd(x, _mm256_set1_pd(-0.0), y), _mm256_set1_pd(-0.0))", f115, 2, 256},
  {"256:_mm256_andnot_pd(_mm256_set1_pd(-0.0), _mm256_fnmadd_pd(x, _mm256_set1_pd(-0.0), y))", f116, 2, 256},
  {"256:_mm256_sub_pd(_mm256_setzero_pd(), _mm256_fnmadd_pd(x, _mm256_set1_pd(-0.0), y))", f117, 2, 256},
  {"256:_mm256_mul_pd(_mm256_fnmadd_pd(x, _mm256_set1_pd(-0.0), y), _mm256_set1_pd(-1.0))", f118, 2, 256},
  {"256:_mm256_floor_pd(_mm256_fnmadd_pd(x, _mm256_set1_pd(-0.0), y))", f119, 2, 256},
  {"256:_mm256_ceil_pd(_mm256_fnmadd_pd(x, _mm256_set1_pd(-0.0), y))", f120, 2, 256},
  {"256:_mm256_round_pd(_mm256_fnmadd_pd(x, _mm256_set1_pd(-0.0), y), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)", f121, 2, 256},
  {"256:_mm256_permute_pd(_mm256_fnmadd_pd(x, _mm256_set1_pd(-0.0), y), 0x5)", f122, 2, 256},
  {"256:_mm256_permute_pd(_mm256_fnmadd_pd(x, _mm256_set1_pd(-0.0), y), 0xa)", f123, 2, 256},
  {"256:_mm256_permute_pd(_mm256_fnmadd_pd(x, _mm256_set1_pd(-0.0), y), 0x3)", f124, 2, 256},
  {"256:_mm256_sqrt_pd(_mm256_fnmadd_pd(_mm256_set1_pd(-0.0), x, y))", f125, 2, 256},
  {"256:_mm256_xor_pd(_mm256_fnmadd_pd(_mm256_set1_pd(-0.0), x, y), _mm256_set1_pd(-0.0))", f126, 2, 256},
  {"256:_mm256_andnot_pd(_mm256_set1_pd(-0.0), _mm256_fnmadd_pd(_mm256_set1_pd(-0.0), x, y))", f127, 2, 256},
  {"256:_mm256_sub_pd(_mm256_setzero_pd(), _mm256_fnmadd_pd(_mm256_set1_pd(-0.0), x, y))", f128, 2, 256},
  {"256:_mm256_mul_pd(_mm256_fnmadd_pd(_mm256_set1_pd(-0.0), x, y), _mm256_set1_pd(-1.0))", f129, 2, 256},
  {"256:_mm256_floor_pd(_mm256_fnmadd_pd(_mm256_set1_pd(-0.0), x, y))", f130, 2, 256},
  {"256:_mm256_ceil_pd(_mm256_fnmadd_pd(_mm256_set1_pd(-0.0), x, y))", f131, 2, 256},
  {"256:_mm256_round_pd(_mm256_fnmadd_pd(_mm256_set1_pd(-0.0), x, y), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)", f132, 2, 256},
  {"256:_mm256_permute_pd(_mm256_fnmadd_pd(_mm256_set1_pd(-0.0), x, y), 0x5)", f133, 2, 256},
  {"256:_mm256_permute_pd(_mm256_fnmadd_pd(_mm256_set1_pd(-0.0), x, y), 0xa)", f134, 2, 256},
  {"256:_mm256_permute_pd(_mm256_fnmadd_pd(_mm256_set1_pd(-0.0), x, y), 0x3)", f135, 2, 256},
  {"256:_mm256_sqrt_pd(_mm256_fnmadd_pd(x, y, _mm256_set1_pd(1.0)))", f136, 2, 256},
  {"256:_mm256_xor_pd(_mm256_fnmadd_pd(x, y, _mm256_set1_pd(1.0)), _mm256_set1_pd(-0.0))", f137, 2, 256},
  {"256:_mm256_andnot_pd(_mm256_set1_pd(-0.0), _mm256_fnmadd_pd(x, y, _mm256_set1_pd(1.0)))", f138, 2, 256},
  {"256:_mm256_sub_pd(_mm256_setzero_pd(), _mm256_fnmadd_pd(x, y, _mm256_set1_pd(1.0)))", f139, 2, 256},
  {"256:_mm256_mul_pd(_mm256_fnmadd_pd(x, y, _mm256_set1_pd(1.0)), _mm256_set1_pd(-1.0))", f140, 2, 256},
  {"256:_mm256_floor_pd(_mm256_fnmadd_pd(x, y, _mm256_set1_pd(1.0)))", f141, 2, 256},
  {"256:_mm256_ceil_pd(_mm256_fnmadd_pd(x, y, _mm256_set1_pd(1.0)))", f142, 2, 256},
  {"256:_mm256_round_pd(_mm256_fnmadd_pd(x, y, _mm256_set1_pd(1.0)), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)", f143, 2, 256},
  {"256:_mm256_permute_pd(_mm256_fnmadd_pd(x, y, _mm256_set1_pd(1.0)), 0x5)", f144, 2, 256},
  {"256:_mm256_permute_pd(_mm256_fnmadd_pd(x, y, _mm256_set1_pd(1.0)), 0xa)", f145, 2, 256},
  {"256:_mm256_permute_pd(_mm256_fnmadd_pd(x, y, _mm256_set1_pd(1.0)), 0x3)", f146, 2, 256},
  {"256:_mm256_sqrt_pd(_mm256_fnmadd_pd(x, _mm256_set1_pd(1.0), y))", f147, 2, 256},
  {"256:_mm256_xor_pd(_mm256_fnmadd_pd(x, _mm256_set1_pd(1.0), y), _mm256_set1_pd(-0.0))", f148, 2, 256},
  {"256:_mm256_andnot_pd(_mm256_set1_pd(-0.0), _mm256_fnmadd_pd(x, _mm256_set1_pd(1.0), y))", f149, 2, 256},
  {"256:_mm256_sub_pd(_mm256_setzero_pd(), _mm256_fnmadd_pd(x, _mm256_set1_pd(1.0), y))", f150, 2, 256},
  {"256:_mm256_mul_pd(_mm256_fnmadd_pd(x, _mm256_set1_pd(1.0), y), _mm256_set1_pd(-1.0))", f151, 2, 256},
  {"256:_mm256_floor_pd(_mm256_fnmadd_pd(x, _mm256_set1_pd(1.0), y))", f152, 2, 256},
  {"256:_mm256_ceil_pd(_mm256_fnmadd_pd(x, _mm256_set1_pd(1.0), y))", f153, 2, 256},
  {"256:_mm256_round_pd(_mm256_fnmadd_pd(x, _mm256_set1_pd(1.0), y), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)", f154, 2, 256},
  {"256:_mm256_permute_pd(_mm256_fnmadd_pd(x, _mm256_set1_pd(1.0), y), 0x5)", f155, 2, 256},
  {"256:_mm256_permute_pd(_mm256_fnmadd_pd(x, _mm256_set1_pd(1.0), y), 0xa)", f156, 2, 256},
  {"256:_mm256_permute_pd(_mm256_fnmadd_pd(x, _mm256_set1_pd(1.0), y), 0x3)", f157, 2, 256},
  {"256:_mm256_sqrt_pd(_mm256_fnmadd_pd(_mm256_set1_pd(1.0), x, y))", f158, 2, 256},
  {"256:_mm256_xor_pd(_mm256_fnmadd_pd(_mm256_set1_pd(1.0), x, y), _mm256_set1_pd(-0.0))", f159, 2, 256},
  {"256:_mm256_andnot_pd(_mm256_set1_pd(-0.0), _mm256_fnmadd_pd(_mm256_set1_pd(1.0), x, y))", f160, 2, 256},
  {"256:_mm256_sub_pd(_mm256_setzero_pd(), _mm256_fnmadd_pd(_mm256_set1_pd(1.0), x, y))", f161, 2, 256},
  {"256:_mm256_mul_pd(_mm256_fnmadd_pd(_mm256_set1_pd(1.0), x, y), _mm256_set1_pd(-1.0))", f162, 2, 256},
  {"256:_mm256_floor_pd(_mm256_fnmadd_pd(_mm256_set1_pd(1.0), x, y))", f163, 2, 256},
  {"256:_mm256_ceil_pd(_mm256_fnmadd_pd(_mm256_set1_pd(1.0), x, y))", f164, 2, 256},
  {"256:_mm256_round_pd(_mm256_fnmadd_pd(_mm256_set1_pd(1.0), x, y), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)", f165, 2, 256},
  {"256:_mm256_permute_pd(_mm256_fnmadd_pd(_mm256_set1_pd(1.0), x, y), 0x5)", f166, 2, 256},
  {"256:_mm256_permute_pd(_mm256_fnmadd_pd(_mm256_set1_pd(1.0), x, y), 0xa)", f167, 2, 256},
  {"256:_mm256_permute_pd(_mm256_fnmadd_pd(_mm256_set1_pd(1.0), x, y), 0x3)", f168, 2, 256},
  {"256:_mm256_sqrt_pd(_mm256_fnmadd_pd(x, y, _mm256_set1_pd(-1.0)))", f169, 2, 256},
  {"256:_mm256_xor_pd(_mm256_fnmadd_pd(x, y, _mm256_set1_pd(-1.0)), _mm256_set1_pd(-0.0))", f170, 2, 256},
  {"256:_mm256_andnot_pd(_mm256_set1_pd(-0.0), _mm256_fnmadd_pd(x, y, _mm256_set1_pd(-1.0)))", f171, 2, 256},
  {"256:_mm256_sub_pd(_mm256_setzero_pd(), _mm256_fnmadd_pd(x, y, _mm256_set1_pd(-1.0)))", f172, 2, 256},
  {"256:_mm256_mul_pd(_mm256_fnmadd_pd(x, y, _mm256_set1_pd(-1.0)), _mm256_set1_pd(-1.0))", f173, 2, 256},
  {"256:_mm256_floor_pd(_mm256_fnmadd_pd(x, y, _mm256_set1_pd(-1.0)))", f174, 2, 256},
  {"256:_mm256_ceil_pd(_mm256_fnmadd_pd(x, y, _mm256_set1_pd(-1.0)))", f175, 2, 256},
  {"256:_mm256_round_pd(_mm256_fnmadd_pd(x, y, _mm256_set1_pd(-1.0)), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)", f176, 2, 256},
  {"256:_mm256_permute_pd(_mm256_fnmadd_pd(x, y, _mm256_set1_pd(-1.0)), 0x5)", f177, 2, 256},
  {"256:_mm256_permute_pd(_mm256_fnmadd_pd(x, y, _mm256_set1_pd(-1.0)), 0xa)", f178, 2, 256},
  {"256:_mm256_permute_pd(_mm256_fnmadd_pd(x, y, _mm256_set1_pd(-1.0)), 0x3)", f179, 2, 256},
  {"256:_mm256_sqrt_pd(_mm256_fnmadd_pd(x, _mm256_set1_pd(-1.0), y))", f180, 2, 256},
  {"256:_mm256_xor_pd(_mm256_fnmadd_pd(x, _mm256_set1_pd(-1.0), y), _mm256_set1_pd(-0.0))", f181, 2, 256},
  {"256:_mm256_andnot_pd(_mm256_set1_pd(-0.0), _mm256_fnmadd_pd(x, _mm256_set1_pd(-1.0), y))", f182, 2, 256},
  {"256:_mm256_sub_pd(_mm256_setzero_pd(), _mm256_fnmadd_pd(x, _mm256_set1_pd(-1.0), y))", f183, 2, 256},
  {"256:_mm256_mul_pd(_mm256_fnmadd_pd(x, _mm256_set1_pd(-1.0), y), _mm256_set1_pd(-1.0))", f184, 2, 256},
  {"256:_mm256_floor_pd(_mm256_fnmadd_pd(x, _mm256_set1_pd(-1.0), y))", f185, 2, 256},
  {"256:_mm256_ceil_pd(_mm256_fnmadd_pd(x, _mm256_set1_pd(-1.0), y))", f186, 2, 256},
  {"256:_mm256_round_pd(_mm256_fnmadd_pd(x, _mm256_set1_pd(-1.0), y), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)", f187, 2, 256},
  {"256:_mm256_permute_pd(_mm256_fnmadd_pd(x, _mm256_set1_pd(-1.0), y), 0x5)", f188, 2, 256},
  {"256:_mm256_permute_pd(_mm256_fnmadd_pd(x, _mm256_set1_pd(-1.0), y), 0xa)", f189, 2, 256},
  {"256:_mm256_permute_pd(_mm256_fnmadd_pd(x, _mm256_set1_pd(-1.0), y), 0x3)", f190, 2, 256},
  {"256:_mm256_sqrt_pd(_mm256_fnmadd_pd(_mm256_set1_pd(-1.0), x, y))", f191, 2, 256},
  {"256:_mm256_xor_pd(_mm256_fnmadd_pd(_mm256_set1_pd(-1.0), x, y), _mm256_set1_pd(-0.0))", f192, 2, 256},
  {"256:_mm256_andnot_pd(_mm256_set1_pd(-0.0), _mm256_fnmadd_pd(_mm256_set1_pd(-1.0), x, y))", f193, 2, 256},
  {"256:_mm256_sub_pd(_mm256_setzero_pd(), _mm256_fnmadd_pd(_mm256_set1_pd(-1.0), x, y))", f194, 2, 256},
  {"256:_mm256_mul_pd(_mm256_fnmadd_pd(_mm256_set1_pd(-1.0), x, y), _mm256_set1_pd(-1.0))", f195, 2, 256},
  {"256:_mm256_floor_pd(_mm256_fnmadd_pd(_mm256_set1_pd(-1.0), x, y))", f196, 2, 256},
  {"256:_mm256_ceil_pd(_mm256_fnmadd_pd(_mm256_set1_pd(-1.0), x, y))", f197, 2, 256},
  {"256:_mm256_round_pd(_mm256_fnmadd_pd(_mm256_set1_pd(-1.0), x, y), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)", f198, 2, 256},
  {"256:_mm256_permute_pd(_mm256_fnmadd_pd(_mm256_set1_pd(-1.0), x, y), 0x5)", f199, 2, 256},
  {"256:_mm256_permute_pd(_mm256_fnmadd_pd(_mm256_set1_pd(-1.0), x, y), 0xa)", f200, 2, 256},
  {"256:_mm256_permute_pd(_mm256_fnmadd_pd(_mm256_set1_pd(-1.0), x, y), 0x3)", f201, 2, 256},
  {"256:_mm256_sqrt_pd(_mm256_fnmadd_pd(x, y, _mm256_set1_pd(std::numeric_limits<double>::infinity())))", f202, 2, 256},
  {"256:_mm256_xor_pd(_mm256_fnmadd_pd(x, y, _mm256_set1_pd(std::numeric_limits<double>::infinity())), _mm256_set1_pd(-0.0))", f203, 2, 256},
  {"256:_mm256_andnot_pd(_mm256_set1_pd(-0.0), _mm256_fnmadd_pd(x, y, _mm256_set1_pd(std::numeric_limits<double>::infinity())))", f204, 2, 256},
  {"256:_mm256_sub_pd(_mm256_setzero_pd(), _mm256_fnmadd_pd(x, y, _mm256_set1_pd(std::numeric_limits<double>::infinity())))", f205, 2, 256},
  {"256:_mm256_mul_pd(_mm256_fnmadd_pd(x, y, _mm256_set1_pd(std::numeric_limits<double>::infinity())), _mm256_set1_pd(-1.0))", f206, 2, 256},
  {"256:_mm256_floor_pd(_mm256_fnmadd_pd(x, y, _mm256_set1_pd(std::numeric_limits<double>::infinity())))", f207, 2, 256},
  {"256:_mm256_ceil_pd(_mm256_fnmadd_pd(x, y, _mm256_set1_pd(std::numeric_limits<double>::infinity())))", f208, 2, 256},
  {"256:_mm256_round_pd(_mm256_fnmadd_pd(x, y, _mm256_set1_pd(std::numeric_limits<double>::infinity())), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)", f209, 2, 256},
  {"256:_mm256_permute_pd(_mm256_fnmadd_pd(x, y, _mm256_set1_pd(std::numeric_limits<double>::infinity())), 0x5)", f210, 2, 256},
  {"256:_mm256_permute_pd(_mm256_fnmadd_pd(x, y, _mm256_set1_pd(std::numeric_limits<double>::infinity())), 0xa)", f211, 2, 256},
  {"256:_mm256_permute_pd(_mm256_fnmadd_pd(x, y, _mm256_set1_pd(std::numeric_limits<double>::infinity())), 0x3)", f212, 2, 256},
  {"256:_mm256_sqrt_pd(_mm256_fnmadd_pd(x, _mm256_set1_pd(std::numeric_limits<double>::infinity()), y))", f213, 2, 256},
  {"256:_mm256_xor_pd(_mm256_fnmadd_pd(x, _mm256_set1_pd(std::numeric_limits<double>::infinity()), y), _mm256_set1_pd(-0.0))", f214, 2, 256},
  {"256:_mm256_andnot_pd(_mm256_set1_pd(-0.0), _mm256_fnmadd_pd(x, _mm256_set1_pd(std::numeric_limits<double>::infinity()), y))", f215, 2, 256},
  {"256:_mm256_sub_pd(_mm256_setzero_pd(), _mm256_fnmadd_pd(x, _mm256_set1_pd(std::numeric_limits<double>::infinity()), y))", f216, 2, 256},
  {"256:_mm256_mul_pd(_mm256_fnmadd_pd(x, _mm256_set1_pd(std::numeric_limits<double>::infinity()), y), _mm256_set1_pd(-1.0))", f217, 2, 256},
  {"256:_mm256_floor_pd(_mm256_fnmadd_pd(x, _mm256_set1_pd(std::numeric_limits<double>::infinity()), y))", f218, 2, 256},
  {"256:_mm256_ceil_pd(_mm256_fnmadd_pd(x, _mm256_set1_pd(std::numeric_limits<double>::infinity()), y))", f219, 2, 256},
  {"256:_mm256_round_pd(_mm256_fnmadd_pd(x, _mm256_set1_pd(std::numeric_limits<double>::infinity()), y), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)", f220, 2, 256},
  {"256:_mm256_permute_pd(_mm256_fnmadd_pd(x, _mm256_set1_pd(std::numeric_limits<double>::infinity()), y), 0x5)", f221, 2, 256},
  {"256:_mm256_permute_pd(_mm256_fnmadd_pd(x, _mm256_set1_pd(std::numeric_limits<double>::infinity()), y), 0xa)", f222, 2, 256},
  {"256:_mm256_permute_pd(_mm256_fnmadd_pd(x, _mm256_set1_pd(std::numeric_limits<double>::infinity()), y), 0x3)", f223, 2, 256},
  {"256:_mm256_sqrt_pd(_mm256_fnmadd_pd(_mm256_set1_pd(std::numeric_limits<double>::infinity()), x, y))", f224, 2, 256},
  {"256:_mm256_xor_pd(_mm256_fnmadd_pd(_mm256_set1_pd(std::numeric_limits<double>::infinity()), x, y), _mm256_set1_pd(-0.0))", f225, 2, 256},
  {"256:_mm256_andnot_pd(_mm256_set1_pd(-0.0), _mm256_fnmadd_pd(_mm256_set1_pd(std::numeric_limits<double>::infinity()), x, y))", f226, 2, 256},
  {"256:_mm256_sub_pd(_mm256_setzero_pd(), _mm256_fnmadd_pd(_mm256_set1_pd(std::numeric_limits<double>::infinity()), x, y))", f227, 2, 256},
  {"256:_mm256_mul_pd(_mm256_fnmadd_pd(_mm256_set1_pd(std::numeric_limits<double>::infinity()), x, y), _mm256_set1_pd(-1.0))", f228, 2, 256},
  {"256:_mm256_floor_pd(_mm256_fnmadd_pd(_mm256_set1_pd(std::numeric_limits<double>::infinity()), x, y))", f229, 2, 256},
  {"256:_mm256_ceil_pd(_mm256_fnmadd_pd(_mm256_set1_pd(std::numeric_limits<double>::infinity()), x, y))", f230, 2, 256},
  {"256:_mm256_round_pd(_mm256_fnmadd_pd(_mm256_set1_pd(std::numeric_limits<double>::infinity()), x, y), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)", f231, 2, 256},
  {"256:_mm256_permute_pd(_mm256_fnmadd_pd(_mm256_set1_pd(std::numeric_limits<double>::infinity()), x, y), 0x5)", f232, 2, 256},
  {"256:_mm256_permute_pd(_mm256_fnmadd_pd(_mm256_set1_pd(std::numeric_limits<double>::infinity()), x, y), 0xa)", f233, 2, 256},
  {"256:_mm256_permute_pd(_mm256_fnmadd_pd(_mm256_set1_pd(std::numeric_limits<double>::infinity()), x, y), 0x3)", f234, 2, 256},
  {"256:_mm256_sqrt_pd(_mm256_fnmadd_pd(x, y, _mm256_set1_pd(std::numeric_limits<double>::quiet_NaN())))", f235, 2, 256},
  {"256:_mm256_xor_pd(_mm256_fnmadd_pd(x, y, _mm256_set1_pd(std::numeric_limits<double>::quiet_NaN())), _mm256_set1_pd(-0.0))", f236, 2, 256},
  {"256:_mm256_andnot_pd(_mm256_set1_pd(-0.0), _mm256_fnmadd_pd(x, y, _mm256_set1_pd(std::numeric_limits<double>::quiet_NaN())))", f237, 2, 256},
  {"256:_mm256_sub_pd(_mm256_setzero_pd(), _mm256_fnmadd_pd(x, y, _mm256_set1_pd(std::numeric_limits<double>::quiet_NaN())))", f238, 2, 256},
  {"256:_mm256_mul_pd(_mm256_fnmadd_pd(x, y, _mm256_set1_pd(std::numeric_limits<double>::quiet_NaN())), _mm256_set1_pd(-1.0))", f239, 2, 256},
  {"256:_mm256_floor_pd(_mm256_fnmadd_pd(x, y, _mm256_set1_pd(std::numeric_limits<double>::quiet_NaN())))", f240, 2, 256},
  {"256:_mm256_ceil_pd(_mm256_fnmadd_pd(x, y, _mm256_set1_pd(std::numeric_limits<double>::quiet_NaN())))", f241, 2, 256},
  {"256:_mm256_round_pd(_mm256_fnmadd_pd(x, y, _mm256_set1_pd(std::numeric_limits<double>::quiet_NaN())), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)", f242, 2, 256},
  {"256:_mm256_permute_pd(_mm256_fnmadd_pd(x, y, _mm256_set1_pd(std::numeric_limits<double>::quiet_NaN())), 0x5)", f243, 2, 256},
  {"256:_mm256_permute_pd(_mm256_fnmadd_pd(x, y, _mm256_set1_pd(std::numeric_limits<double>::quiet_NaN())), 0xa)", f244, 2, 256},
  {"256:_mm256_permute_pd(_mm256_fnmadd_pd(x, y, _mm256_set1_pd(std::numeric_limits<double>::quiet_NaN())), 0x3)", f245, 2, 256},
  {"256:_mm256_sqrt_pd(_mm256_fnmadd_pd(x, _mm256_set1_pd(std::numeric_limits<double>::quiet_NaN()), y))", f246, 2, 256},
  {"256:_mm256_xor_pd(_mm256_fnmadd_pd(x, _mm256_set1_pd(std::numeric_limits<double>::quiet_NaN()), y), _mm256_set1_pd(-0.0))", f247, 2, 256},
  {"256:_mm256_andnot_pd(_mm256_set1_pd(-0.0), _mm256_fnmadd_pd(x, _mm256_set1_pd(std::numeric_limits<double>::quiet_NaN()), y))", f248, 2, 256},
  {"256:_mm256_sub_pd(_mm256_setzero_pd(), _mm256_fnmadd_pd(x, _mm256_set1_pd(std::numeric_limits<double>::quiet_NaN()), y))", f249, 2, 256},
  {"256:_mm256_mul_pd(_mm256_fnmadd_pd(x, _mm256_set1_pd(std::numeric_limits<double>::quiet_NaN()), y), _mm256_set1_pd(-1.0))", f250, 2, 256},
  {"256:_mm256_floor_pd(_mm256_fnmadd_pd(x, _mm256_set1_pd(std::numeric_limits<double>::quiet_NaN()), y))", f251, 2, 256},
  {"256:_mm256_ceil_pd(_mm256_fnmadd_pd(x, _mm256_set1_pd(std::numeric_limits<double>::quiet_NaN()), y))", f252, 2, 256},
  {"256:_mm256_round_pd(_mm256_fnmadd_pd(x, _mm256_set1_pd(std::numeric_limits<double>::quiet_NaN()), y), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)", f253, 2, 256},
  {"256:_mm256_permute_pd(_mm256_fnmadd_pd(x, _mm256_set1_pd(std::numeric_limits<double>::quiet_NaN()), y), 0x5)", f254, 2, 256},
  {"256:_mm256_permute_pd(_mm256_fnmadd_pd(x, _mm256_set1_pd(std::numeric_limits<double>::quiet_NaN()), y), 0xa)", f255, 2, 256},
  {"256:_mm256_permute_pd(_mm256_fnmadd_pd(x, _mm256_set1_pd(std::numeric_limits<double>::quiet_NaN()), y), 0x3)", f256, 2, 256},
  {"256:_mm256_sqrt_pd(_mm256_fnmadd_pd(_mm256_set1_pd(std::numeric_limits<double>::quiet_NaN()), x, y))", f257, 2, 256},
  {"256:_mm256_xor_pd(_mm256_fnmadd_pd(_mm256_set1_pd(std::numeric_limits<double>::quiet_NaN()), x, y), _mm256_set1_pd(-0.0))", f258, 2, 256},
  {"256:_mm256_andnot_pd(_mm256_set1_pd(-0.0), _mm256_fnmadd_pd(_mm256_set1_pd(std::numeric_limits<double>::quiet_NaN()), x, y))", f259, 2, 256},
  {"256:_mm256_sub_pd(_mm256_setzero_pd(), _mm256_fnmadd_pd(_mm256_set1_pd(std::numeric_limits<double>::quiet_NaN()), x, y))", f260, 2, 256},
  {"256:_mm256_mul_pd(_mm256_fnmadd_pd(_mm256_set1_pd(std::numeric_limits<double>::quiet_NaN()), x, y), _mm256_set1_pd(-1.0))", f261, 2, 256},
  {"256:_mm256_floor_pd(_mm256_fnmadd_pd(_mm256_set1_pd(std::numeric_limits<double>::quiet_NaN()), x, y))", f262, 2, 256},
  {"256:_mm256_ceil_pd(_mm256_fnmadd_pd(_mm256_set1_pd(std::numeric_limits<double>::quiet_NaN()), x, y))", f263, 2, 256},
  {"256:_mm256_round_pd(_mm256_fnmadd_pd(_mm256_set1_pd(std::numeric_limits<double>::quiet_NaN()), x, y), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)", f264, 2, 256},
  {"256:_mm256_permute_pd(_mm256_fnmadd_pd(_mm256_set1_pd(std::numeric_limits<double>::quiet_NaN()), x, y), 0x5)", f265, 2, 256},
  {"256:_mm256_permute_pd(_mm256_fnmadd_pd(_mm256_set1_pd(std::numeric_limits<double>::quiet_NaN()), x, y), 0xa)", f266, 2, 256},
  {"256:_mm256_permute_pd(_mm256_fnmadd_pd(_mm256_set1_pd(std::numeric_limits<double>::quiet_NaN()), x, y), 0x3)", f267, 2, 256},
  {"256:_mm256_sqrt_pd(_mm256_fnmadd_pd(x, y, x))", f268, 2, 256},
  {"256:_mm256_xor_pd(_mm256_fnmadd_pd(x, y, x), _mm256_set1_pd(-0.0))", f269, 2, 256},
  {"256:_mm256_andnot_pd(_mm256_set1_pd(-0.0), _mm256_fnmadd_pd(x, y, x))", f270, 2, 256},
  {"256:_mm256_sub_pd(_mm256_setzero_pd(), _mm256_fnmadd_pd(x, y, x))", f271, 2, 256},
  {"256:_mm256_mul_pd(_mm256_fnmadd_pd(x, y, x), _mm256_set1_pd(-1.0))", f272, 2, 256},
  {"256:_mm256_floor_pd(_mm256_fnmadd_pd(x, y, x))", f273, 2, 256},
  {"256:_mm256_ceil_pd(_mm256_fnmadd_pd(x, y, x))", f274, 2, 256},
  {"256:_mm256_round_pd(_mm256_fnmadd_pd(x, y, x), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)", f275, 2, 256},
  {"256:_mm256_permute_pd(_mm256_fnmadd_pd(x, y, x), 0x5)", f276, 2, 256},
  {"256:_mm256_permute_pd(_mm256_fnmadd_pd(x, y, x), 0xa)", f277, 2, 256},
  {"256:_mm256_permute_pd(_mm256_fnmadd_pd(x, y, x), 0x3)", f278, 2, 256},
  {"256:_mm256_sqrt_pd(_mm256_fnmadd_pd(x, x, y))", f279, 2, 256},
  {"256:_mm256_xor_pd(_mm256_fnmadd_pd(x, x, y), _mm256_set1_pd(-0.0))", f280, 2, 256},
  {"256:_mm256_andnot_pd(_mm256_set1_pd(-0.0), _mm256_fnmadd_pd(x, x, y))", f281, 2, 256},
  {"256:_mm256_sub_pd(_mm256_setzero_pd(), _mm256_fnmadd_pd(x, x, y))", f282, 2, 256},
  {"256:_mm256_mul_pd(_mm256_fnmadd_pd(x, x, y), _mm256_set1_pd(-1.0))", f283, 2, 256},
  {"256:_mm256_floor_pd(_mm256_fnmadd_pd(x, x, y))", f284, 2, 256},
  {"256:_mm256_ceil_pd(_mm256_fnmadd_pd(x, x, y))", f285, 2, 256},
  {"256:_mm256_round_pd(_mm256_fnmadd_pd(x, x, y), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)", f286, 2, 256},
  {"256:_mm256_permute_pd(_mm256_fnmadd_pd(x, x, y), 0x5)", f287, 2, 256},
  {"256:_mm256_permute_pd(_mm256_fnmadd_pd(x, x, y), 0xa)", f288, 2, 256},
  {"256:_mm256_permute_pd(_mm256_fnmadd_pd(x, x, y), 0x3)", f289, 2, 256},
  {"256:_mm256_sqrt_pd(_mm256_fnmadd_pd(x, y, _mm256_mul_pd(x, y)))", f290, 2, 256},
  {"256:_mm256_xor_pd(_mm256_fnmadd_pd(x, y, _mm256_mul_pd(x, y)), _mm256_set1_pd(-0.0))", f291, 2, 256},
  {"256:_mm256_andnot_pd(_mm256_set1_pd(-0.0), _mm256_fnmadd_pd(x, y, _mm256_mul_pd(x, y)))", f292, 2, 256},
  {"256:_mm256_sub_pd(_mm256_setzero_pd(), _mm256_fnmadd_pd(x, y, _mm256_mul_pd(x, y)))", f293, 2, 256},
  {"256:_mm256_mul_pd(_mm256_fnmadd_pd(x, y, _mm256_mul_pd(x, y)), _mm256_set1_pd(-1.0))", f294, 2, 256},
  {"256:_mm256_floor_pd(_mm256_fnmadd_pd(x, y, _mm256_mul_pd(x, y)))", f295, 2, 256},
  {"256:_mm256_ceil_pd(_mm256_fnmadd_pd(x, y, _mm256_mul_pd(x, y)))", f296, 2, 256},
  {"256:_mm256_round_pd(_mm256_fnmadd_pd(x, y, _mm256_mul_pd(x, y)), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)", f297, 2, 256},
  {"256:_mm256_permute_pd(_mm256_fnmadd_pd(x, y, _mm256_mul_pd(x, y)), 0x5)", f298, 2, 256},
  {"256:_mm256_permute_pd(_mm256_fnmadd_pd(x, y, _mm256_mul_pd(x, y)), 0xa)", f299, 2, 256},
  {"256:_mm256_permute_pd(_mm256_fnmadd_pd(x, y, _mm256_mul_pd(x, y)), 0x3)", f300, 2, 256},
  {"256:_mm256_sqrt_pd(_mm256_fnmsub_pd(x, y, _mm256_setzero_pd()))", f301, 2, 256},
  {"256:_mm256_xor_pd(_mm256_fnmsub_pd(x, y, _mm256_setzero_pd()), _mm256_set1_pd(-0.0))", f302, 2, 256},
  {"256:_mm256_andnot_pd(_mm256_set1_pd(-0.0), _mm256_fnmsub_pd(x, y, _mm256_setzero_pd()))", f303, 2, 256},
  {"256:_mm256_sub_pd(_mm256_setzero_pd(), _mm256_fnmsub_pd(x, y, _mm256_setzero_pd()))", f304, 2, 256},
  {"256:_mm256_mul_pd(_mm256_fnmsub_pd(x, y, _mm256_setzero_pd()), _mm256_set1_pd(-1.0))", f305, 2, 256},
  {"256:_mm256_floor_pd(_mm256_fnmsub_pd(x, y, _mm256_setzero_pd()))", f306, 2, 256},
  {"256:_mm256_ceil_pd(_mm256_fnmsub_pd(x, y, _mm256_setzero_pd()))", f307, 2, 256},
  {"256:_mm256_round_pd(_mm256_fnmsub_pd(x, y, _mm256_setzero_pd()), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)", f308, 2, 256},
  {"256:_mm256_permute_pd(_mm256_fnmsub_pd(x, y, _mm256_setzero_pd()), 0x5)", f309, 2, 256},
  {"256:_mm256_permute_pd(_mm256_fnmsub_pd(x, y, _mm256_setzero_pd()), 0xa)", f310, 2, 256},
  {"256:_mm256_permute_pd(_mm256_fnmsub_pd(x, y, _mm256_setzero_pd()), 0x3)", f311, 2, 256},
  {"256:_mm256_sqrt_pd(_mm256_fnmsub_pd(x, _mm256_setzero_pd(), y))", f312, 2, 256},
  {"256:_mm256_xor_pd(_mm256_fnmsub_pd(x, _mm256_setzero_pd(), y), _mm256_set1_pd(-0.0))", f313, 2, 256},
  {"256:_mm256_andnot_pd(_mm256_set1_pd(-0.0), _mm256_fnmsub_pd(x, _mm256_setzero_pd(), y))", f314, 2, 256},
  {"256:_mm256_sub_pd(_mm256_setzero_pd(), _mm256_fnmsub_pd(x, _mm256_setzero_pd(), y))", f315, 2, 256},
  {"256:_mm256_mul_pd(_mm256_fnmsub_pd(x, _mm256_setzero_pd(), y), _mm256_set1_pd(-1.0))", f316, 2, 256},
  {"256:_mm256_floor_pd(_mm256_fnmsub_pd(x, _mm256_setzero_pd(), y))", f317, 2, 256},
  {"256:_mm256_ceil_pd(_mm256_fnmsub_pd(x, _mm256_setzero_pd(), y))", f318, 2, 256},
  {"256:_mm256_round_pd(_mm256_fnmsub_pd(x, _mm256_setzero_pd(), y), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)", f319, 2, 256},
  {"256:_mm256_permute_pd(_mm256_fnmsub_pd(x, _mm256_setzero_pd(), y), 0x5)", f320, 2, 256},
  {"256:_mm256_permute_pd(_mm256_fnmsub_pd(x, _mm256_setzero_pd(), y), 0xa)", f321, 2, 256},
  {"256:_mm256_permute_pd(_mm256_fnmsub_pd(x, _mm256_setzero_pd(), y), 0x3)", f322, 2, 256},
  {"256:_mm256_sqrt_pd(_mm256_fnmsub_pd(_mm256_setzero_pd(), x, y))", f323, 2, 256},
  {"256:_mm256_xor_pd(_mm256_fnmsub_pd(_mm256_setzero_pd(), x, y), _mm256_set1_pd(-0.0))", f324, 2, 256},
  {"256:_mm256_andnot_pd(_mm256_set1_pd(-0.0), _mm256_fnmsub_pd(_mm256_setzero_pd(), x, y))", f325, 2, 256},
  {"256:_mm256_sub_pd(_mm256_setzero_pd(), _mm256_fnmsub_pd(_mm256_setzero_pd(), x, y))", f326, 2, 256},
  {"256:_mm256_mul_pd(_mm256_fnmsub_pd(_mm256_setzero_pd(), x, y), _mm256_set1_pd(-1.0))", f327, 2, 256},
  {"256:_mm256_floor_pd(_mm256_fnmsub_pd(_mm256_setzero_pd(), x, y))", f328, 2, 256},
  {"256:_mm256_ceil_pd(_mm256_fnmsub_pd(_mm256_setzero_pd(), x, y))", f329, 2, 256},
  {"256:_mm256_round_pd(_mm256_fnmsub_pd(_mm256_setzero_pd(), x, y), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)", f330, 2, 256},
  {"256:_mm256_permute_pd(_mm256_fnmsub_pd(_mm256_setzero_pd(), x, y), 0x5)", f331, 2, 256},
  {"256:_mm256_permute_pd(_mm256_fnmsub_pd(_mm256_setzero_pd(), x, y), 0xa)", f332, 2, 256},
  {"256:_mm256_permute_pd(_mm256_fnmsub_pd(_mm256_setzero_pd(), x, y), 0x3)", f333, 2, 256},
  {"256:_mm256_sqrt_pd(_mm256_fnmsub_pd(x, y, _mm256_set1_pd(-0.0)))", f334, 2, 256},
  {"256:_mm256_xor_pd(_mm256_fnmsub_pd(x, y, _mm256_set1_pd(-0.0)), _mm256_set1_pd(-0.0))", f335, 2, 256},
  {"256:_mm256_andnot_pd(_mm256_set1_pd(-0.0), _mm256_fnmsub_pd(x, y, _mm256_set1_pd(-0.0)))", f336, 2, 256},
  {"256:_mm256_sub_pd(_mm256_setzero_pd(), _mm256_fnmsub_pd(x, y, _mm256_set1_pd(-0.0)))", f337, 2, 256},
  {"256:_mm256_mul_pd(_mm256_fnmsub_pd(x, y, _mm256_set1_pd(-0.0)), _mm256_set1_pd(-1.0))", f338, 2, 256},
  {"256:_mm256_floor_pd(_mm256_fnmsub_pd(x, y, _mm256_set1_pd(-0.0)))", f339, 2, 256},
  {"256:_mm256_ceil_pd(_mm256_fnmsub_pd(x, y, _mm256_set1_pd(-0.0)))", f340, 2, 256},
  {"256:_mm256_round_pd(_mm256_fnmsub_pd(x, y, _mm256_set1_pd(-0.0)), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)", f341, 2, 256},
  {"256:_mm256_permute_pd(_mm256_fnmsub_pd(x, y, _mm256_set1_pd(-0.0)), 0x5)", f342, 2, 256},
  {"256:_mm256_permute_pd(_mm256_fnmsub_pd(x, y, _mm256_set1_pd(-0.0)), 0xa)", f343, 2, 256},
  {"256:_mm256_permute_pd(_mm256_fnmsub_pd(x, y, _mm256_set1_pd(-0.0)), 0x3)", f344, 2, 256},
  {"256:_mm256_sqrt_pd(_mm256_fnmsub_pd(x, _mm256_set1_pd(-0.0), y))", f345, 2, 256},
  {"256:_mm256_xor_pd(_mm256_fnmsub_pd(x, _mm256_set1_pd(-0.0), y), _mm256_set1_pd(-0.0))", f346, 2, 256},
  {"256:_mm256_andnot_pd(_mm256_set1_pd(-0.0), _mm256_fnmsub_pd(x, _mm256_set1_pd(-0.0), y))", f347, 2, 256},
  {"256:_mm256_sub_pd(_mm256_setzero_pd(), _mm256_fnmsub_pd(x, _mm256_set1_pd(-0.0), y))", f348, 2, 256},
  {"256:_mm256_mul_pd(_mm256_fnmsub_pd(x, _mm256_set1_pd(-0.0), y), _mm256_set1_pd(-1.0))", f349, 2, 256},
  {"256:_mm256_floor_pd(_mm256_fnmsub_pd(x, _mm256_set1_pd(-0.0), y))", f350, 2, 256},
  {"256:_mm256_ceil_pd(_mm256_fnmsub_pd(x, _mm256_set1_pd(-0.0), y))", f351, 2, 256},
  {"256:_mm256_round_pd(_mm256_fnmsub_pd(x, _mm256_set1_pd(-0.0), y), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)", f352, 2, 256},
  {"256:_mm256_permute_pd(_mm256_fnmsub_pd(x, _mm256_set1_pd(-0.0), y), 0x5)", f353, 2, 256},
  {"256:_mm256_permute_pd(_mm256_fnmsub_pd(x, _mm256_set1_pd(-0.0), y), 0xa)", f354, 2, 256},
  {"256:_mm256_permute_pd(_mm256_fnmsub_pd(x, _mm256_set1_pd(-0.0), y), 0x3)", f355, 2, 256},
  {"256:_mm256_sqrt_pd(_mm256_fnmsub_pd(_mm256_set1_pd(-0.0), x, y))", f356, 2, 256},
  {"256:_mm256_xor_pd(_mm256_fnmsub_pd(_mm256_set1_pd(-0.0), x, y), _mm256_set1_pd(-0.0))", f357, 2, 256},
  {"256:_mm256_andnot_pd(_mm256_set1_pd(-0.0), _mm256_fnmsub_pd(_mm256_set1_pd(-0.0), x, y))", f358, 2, 256},
  {"256:_mm256_sub_pd(_mm256_setzero_pd(), _mm256_fnmsub_pd(_mm256_set1_pd(-0.0), x, y))", f359, 2, 256},
  {"256:_mm256_mul_pd(_mm256_fnmsub_pd(_mm256_set1_pd(-0.0), x, y), _mm256_set1_pd(-1.0))", f360, 2, 256},
  {"256:_mm256_floor_pd(_mm256_fnmsub_pd(_mm256_set1_pd(-0.0), x, y))", f361, 2, 256},
  {"256:_mm256_ceil_pd(_mm256_fnmsub_pd(_mm256_set1_pd(-0.0), x, y))", f362, 2, 256},
  {"256:_mm256_round_pd(_mm256_fnmsub_pd(_mm256_set1_pd(-0.0), x, y), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)", f363, 2, 256},
  {"256:_mm256_permute_pd(_mm256_fnmsub_pd(_mm256_set1_pd(-0.0), x, y), 0x5)", f364, 2, 256},
  {"256:_mm256_permute_pd(_mm256_fnmsub_pd(_mm256_set1_pd(-0.0), x, y), 0xa)", f365, 2, 256},
  {"256:_mm256_permute_pd(_mm256_fnmsub_pd(_mm256_set1_pd(-0.0), x, y), 0x3)", f366, 2, 256},
  {"256:_mm256_sqrt_pd(_mm256_fnmsub_pd(x, y, _mm256_set1_pd(1.0)))", f367, 2, 256},
  {"256:_mm256_xor_pd(_mm256_fnmsub_pd(x, y, _mm256_set1_pd(1.0)), _mm256_set1_pd(-0.0))", f368, 2, 256},
  {"256:_mm256_andnot_pd(_mm256_set1_pd(-0.0), _mm256_fnmsub_pd(x, y, _mm256_set1_pd(1.0)))", f369, 2, 256},
  {"256:_mm256_sub_pd(_mm256_setzero_pd(), _mm256_fnmsub_pd(x, y, _mm256_set1_pd(1.0)))", f370, 2, 256},
  {"256:_mm256_mul_pd(_mm256_fnmsub_pd(x, y, _mm256_set1_pd(1.0)), _mm256_set1_pd(-1.0))", f371, 2, 256},
  {"256:_mm256_floor_pd(_mm256_fnmsub_pd(x, y, _mm256_set1_pd(1.0)))", f372, 2, 256},
  {"256:_mm256_ceil_pd(_mm256_fnmsub_pd(x, y, _mm256_set1_pd(1.0)))", f373, 2, 256},
  {"256:_mm256_round_pd(_mm256_fnmsub_pd(x, y, _mm256_set1_pd(1.0)), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)", f374, 2, 256},
  {"256:_mm256_permute_pd(_mm256_fnmsub_pd(x, y, _mm256_set1_pd(1.0)), 0x5)", f375, 2, 256},
  {"256:_mm256_permute_pd(_mm256_fnmsub_pd(x, y, _mm256_set1_pd(1.0)), 0xa)", f376, 2, 256},
  {"256:_mm256_permute_pd(_mm256_fnmsub_pd(x, y, _mm256_set1_pd(1.0)), 0x3)", f377, 2, 256},
  {"256:_mm256_sqrt_pd(_mm256_fnmsub_pd(x, _mm256_set1_pd(1.0), y))", f378, 2, 256},
  {"256:_mm256_xor_pd(_mm256_fnmsub_pd(x, _mm256_set1_pd(1.0), y), _mm256_set1_pd(-0.0))", f379, 2, 256},
  {"256:_mm256_andnot_pd(_mm256_set1_pd(-0.0), _mm256_fnmsub_pd(x, _mm256_set1_pd(1.0), y))", f380, 2, 256},
  {"256:_mm256_sub_pd(_mm256_setzero_pd(), _mm256_fnmsub_pd(x, _mm256_set1_pd(1.0), y))", f381, 2, 256},
  {"256:_mm256_mul_pd(_mm256_fnmsub_pd(x, _mm256_set1_pd(1.0), y), _mm256_set1_pd(-1.0))", f382, 2, 256},
  {"256:_mm256_floor_pd(_mm256_fnmsub_pd(x, _mm256_set1_pd(1.0), y))", f383, 2, 256},
  {"256:_mm256_ceil_pd(_mm256_fnmsub_pd(x, _mm256_set1_pd(1.0), y))", f384, 2, 256},
  {"256:_mm256_round_pd(_mm256_fnmsub_pd(x, _mm256_set1_pd(1.0), y), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)", f385, 2, 256},
  {"256:_mm256_permute_pd(_mm256_fnmsub_pd(x, _mm256_set1_pd(1.0), y), 0x5)", f386, 2, 256},
  {"256:_mm256_permute_pd(_mm256_fnmsub_pd(x, _mm256_set1_pd(1.0), y), 0xa)", f387, 2, 256},
  {"256:_mm256_permute_pd(_mm256_fnmsub_pd(x, _mm256_set1_pd(1.0), y), 0x3)", f388, 2, 256},
  {"256:_mm256_sqrt_pd(_mm256_fnmsub_pd(_mm256_set1_pd(1.0), x, y))", f389, 2, 256},
  {"256:_mm256_xor_pd(_mm256_fnmsub_pd(_mm256_set1_pd(1.0), x, y), _mm256_set1_pd(-0.0))", f390, 2, 256},
  {"256:_mm256_andnot_pd(_mm256_set1_pd(-0.0), _mm256_fnmsub_pd(_mm256_set1_pd(1.0), x, y))", f391, 2, 256},
  {"256:_mm256_sub_pd(_mm256_setzero_pd(), _mm256_fnmsub_pd(_mm256_set1_pd(1.0), x, y))", f392, 2, 256},
  {"256:_mm256_mul_pd(_mm256_fnmsub_pd(_mm256_set1_pd(1.0), x, y), _mm256_set1_pd(-1.0))", f393, 2, 256},
  {"256:_mm256_floor_pd(_mm256_fnmsub_pd(_mm256_set1_pd(1.0), x, y))", f394, 2, 256},
  {"256:_mm256_ceil_pd(_mm256_fnmsub_pd(_mm256_set1_pd(1.0), x, y))", f395, 2, 256},
  {"256:_mm256_round_pd(_mm256_fnmsub_pd(_mm256_set1_pd(1.0), x, y), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)", f396, 2, 256},
  {"256:_mm256_permute_pd(_mm256_fnmsub_pd(_mm256_set1_pd(1.0), x, y), 0x5)", f397, 2, 256},
  {"256:_mm256_permute_pd(_mm256_fnmsub_pd(_mm256_set1_pd(1.0), x, y), 0xa)", f398, 2, 256},
  {"256:_mm256_permute_pd(_mm256_fnmsub_pd(_mm256_set1_pd(1.0), x, y), 0x3)", f399, 2, 256},
  {"256:_mm256_sqrt_pd(_mm256_fnmsub_pd(x, y, _mm256_set1_pd(-1.0)))", f400, 2, 256},
  {"256:_mm256_xor_pd(_mm256_fnmsub_pd(x, y, _mm256_set1_pd(-1.0)), _mm256_set1_pd(-0.0))", f401, 2, 256},
  {"256:_mm256_andnot_pd(_mm256_set1_pd(-0.0), _mm256_fnmsub_pd(x, y, _mm256_set1_pd(-1.0)))", f402, 2, 256},
  {"256:_mm256_sub_pd(_mm256_setzero_pd(), _mm256_fnmsub_pd(x, y, _mm256_set1_pd(-1.0)))", f403, 2, 256},
  {"256:_mm256_mul_pd(_mm256_fnmsub_pd(x, y, _mm256_set1_pd(-1.0)), _mm256_set1_pd(-1.0))", f404, 2, 256},
  {"256:_mm256_floor_pd(_mm256_fnmsub_pd(x, y, _mm256_set1_pd(-1.0)))", f405, 2, 256},
  {"256:_mm256_ceil_pd(_mm256_fnmsub_pd(x, y, _mm256_set1_pd(-1.0)))", f406, 2, 256},
  {"256:_mm256_round_pd(_mm256_fnmsub_pd(x, y, _mm256_set1_pd(-1.0)), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)", f407, 2, 256},
  {"256:_mm256_permute_pd(_mm256_fnmsub_pd(x, y, _mm256_set1_pd(-1.0)), 0x5)", f408, 2, 256},
  {"256:_mm256_permute_pd(_mm256_fnmsub_pd(x, y, _mm256_set1_pd(-1.0)), 0xa)", f409, 2, 256},
  {"256:_mm256_permute_pd(_mm256_fnmsub_pd(x, y, _mm256_set1_pd(-1.0)), 0x3)", f410, 2, 256},
  {"256:_mm256_sqrt_pd(_mm256_fnmsub_pd(x, _mm256_set1_pd(-1.0), y))", f411, 2, 256},
  {"256:_mm256_xor_pd(_mm256_fnmsub_pd(x, _mm256_set1_pd(-1.0), y), _mm256_set1_pd(-0.0))", f412, 2, 256},
  {"256:_mm256_andnot_pd(_mm256_set1_pd(-0.0), _mm256_fnmsub_pd(x, _mm256_set1_pd(-1.0), y))", f413, 2, 256},
  {"256:_mm256_sub_pd(_mm256_setzero_pd(), _mm256_fnmsub_pd(x, _mm256_set1_pd(-1.0), y))", f414, 2, 256},
  {"256:_mm256_mul_pd(_mm256_fnmsub_pd(x, _mm256_set1_pd(-1.0), y), _mm256_set1_pd(-1.0))", f415, 2, 256},
  {"256:_mm256_floor_pd(_mm256_fnmsub_pd(x, _mm256_set1_pd(-1.0), y))", f416, 2, 256},
  {"256:_mm256_ceil_pd(_mm256_fnmsub_pd(x, _mm256_set1_pd(-1.0), y))", f417, 2, 256},
  {"256:_mm256_round_pd(_mm256_fnmsub_pd(x, _mm256_set1_pd(-1.0), y), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)", f418, 2, 256},
  {"256:_mm256_permute_pd(_mm256_fnmsub_pd(x, _mm256_set1_pd(-1.0), y), 0x5)", f419, 2, 256},
  {"256:_mm256_permute_pd(_mm256_fnmsub_pd(x, _mm256_set1_pd(-1.0), y), 0xa)", f420, 2, 256},
  {"256:_mm256_permute_pd(_mm256_fnmsub_pd(x, _mm256_set1_pd(-1.0), y), 0x3)", f421, 2, 256},
  {"256:_mm256_sqrt_pd(_mm256_fnmsub_pd(_mm256_set1_pd(-1.0), x, y))", f422, 2, 256},
  {"256:_mm256_xor_pd(_mm256_fnmsub_pd(_mm256_set1_pd(-1.0), x, y), _mm256_set1_pd(-0.0))", f423, 2, 256},
  {"256:_mm256_andnot_pd(_mm256_set1_pd(-0.0), _mm256_fnmsub_pd(_mm256_set1_pd(-1.0), x, y))", f424, 2, 256},
  {"256:_mm256_sub_pd(_mm256_setzero_pd(), _mm256_fnmsub_pd(_mm256_set1_pd(-1.0), x, y))", f425, 2, 256},
  {"256:_mm256_mul_pd(_mm256_fnmsub_pd(_mm256_set1_pd(-1.0), x, y), _mm256_set1_pd(-1.0))", f426, 2, 256},
  {"256:_mm256_floor_pd(_mm256_fnmsub_pd(_mm256_set1_pd(-1.0), x, y))", f427, 2, 256},
  {"256:_mm256_ceil_pd(_mm256_fnmsub_pd(_mm256_set1_pd(-1.0), x, y))", f428, 2, 256},
  {"256:_mm256_round_pd(_mm256_fnmsub_pd(_mm256_set1_pd(-1.0), x, y), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)", f429, 2, 256},
  {"256:_mm256_permute_pd(_mm256_fnmsub_pd(_mm256_set1_pd(-1.0), x, y), 0x5)", f430, 2, 256},
  {"256:_mm256_permute_pd(_mm256_fnmsub_pd(_mm256_set1_pd(-1.0), x, y), 0xa)", f431, 2, 256},
  {"256:_mm256_permute_pd(_mm256_fnmsub_pd(_mm256_set1_pd(-1.0), x, y), 0x3)", f432, 2, 256},
  {"256:_mm256_sqrt_pd(_mm256_fnmsub_pd(x, y, _mm256_set1_pd(std::numeric_limits<double>::infinity())))", f433, 2, 256},
  {"256:_mm256_xor_pd(_mm256_fnmsub_pd(x, y, _mm256_set1_pd(std::numeric_limits<double>::infinity())), _mm256_set1_pd(-0.0))", f434, 2, 256},
  {"256:_mm256_andnot_pd(_mm256_set1_pd(-0.0), _mm256_fnmsub_pd(x, y, _mm256_set1_pd(std::numeric_limits<double>::infinity())))", f435, 2, 256},
  {"256:_mm256_sub_pd(_mm256_setzero_pd(), _mm256_fnmsub_pd(x, y, _mm256_set1_pd(std::numeric_limits<double>::infinity())))", f436, 2, 256},
  {"256:_mm256_mul_pd(_mm256_fnmsub_pd(x, y, _mm256_set1_pd(std::numeric_limits<double>::infinity())), _mm256_set1_pd(-1.0))", f437, 2, 256},
  {"256:_mm256_floor_pd(_mm256_fnmsub_pd(x, y, _mm256_set1_pd(std::numeric_limits<double>::infinity())))", f438, 2, 256},
  {"256:_mm256_ceil_pd(_mm256_fnmsub_pd(x, y, _mm256_set1_pd(std::numeric_limits<double>::infinity())))", f439, 2, 256},
  {"256:_mm256_round_pd(_mm256_fnmsub_pd(x, y, _mm256_set1_pd(std::numeric_limits<double>::infinity())), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)", f440, 2, 256},
  {"256:_mm256_permute_pd(_mm256_fnmsub_pd(x, y, _mm256_set1_pd(std::numeric_limits<double>::infinity())), 0x5)", f441, 2, 256},
  {"256:_mm256_permute_pd(_mm256_fnmsub_pd(x, y, _mm256_set1_pd(std::numeric_limits<double>::infinity())), 0xa)", f442, 2, 256},
  {"256:_mm256_permute_pd(_mm256_fnmsub_pd(x, y, _mm256_set1_pd(std::numeric_limits<double>::infinity())), 0x3)", f443, 2, 256},
  {"256:_mm256_sqrt_pd(_mm256_fnmsub_pd(x, _mm256_set1_pd(std::numeric_limits<double>::infinity()), y))", f444, 2, 256},
  {"256:_mm256_xor_pd(_mm256_fnmsub_pd(x, _mm256_set1_pd(std::numeric_limits<double>::infinity()), y), _mm256_set1_pd(-0.0))", f445, 2, 256},
  {"256:_mm256_andnot_pd(_mm256_set1_pd(-0.0), _mm256_fnmsub_pd(x, _mm256_set1_pd(std::numeric_limits<double>::infinity()), y))", f446, 2, 256},
  {"256:_mm256_sub_pd(_mm256_setzero_pd(), _mm256_fnmsub_pd(x, _mm256_set1_pd(std::numeric_limits<double>::infinity()), y))", f447, 2, 256},
  {"256:_mm256_mul_pd(_mm256_fnmsub_pd(x, _mm256_set1_pd(std::numeric_limits<double>::infinity()), y), _mm256_set1_pd(-1.0))", f448, 2, 256},
  {"256:_mm256_floor_pd(_mm256_fnmsub_pd(x, _mm256_set1_pd(std::numeric_limits<double>::infinity()), y))", f449, 2, 256},
  {"256:_mm256_ceil_pd(_mm256_fnmsub_pd(x, _mm256_set1_pd(std::numeric_limits<double>::infinity()), y))", f450, 2, 256},
  {"256:_mm256_round_pd(_mm256_fnmsub_pd(x, _mm256_set1_pd(std::numeric_limits<double>::infinity()), y), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)", f451, 2, 256},
  {"256:_mm256_permute_pd(_mm256_fnmsub_pd(x, _mm256_set1_pd(std::numeric_limits<double>::infinity()), y), 0x5)", f452, 2, 256},
  {"256:_mm256_permute_pd(_mm256_fnmsub_pd(x, _mm256_set1_pd(std::numeric_limits<double>::infinity()), y), 0xa)", f453, 2, 256},
  {"256:_mm256_permute_pd(_mm256_fnmsub_pd(x, _mm256_set1_pd(std::numeric_limits<double>::infinity()), y), 0x3)", f454, 2, 256},
  {"256:_mm256_sqrt_pd(_mm256_fnmsub_pd(_mm256_set1_pd(std::numeric_limits<double>::infinity()), x, y))", f455, 2, 256},
  {"256:_mm256_xor_pd(_mm256_fnmsub_pd(_mm256_set1_pd(std::numeric_limits<double>::infinity()), x, y), _mm256_set1_pd(-0.0))", f456, 2, 256},
  {"256:_mm256_andnot_pd(_mm256_set1_pd(-0.0), _mm256_fnmsub_pd(_mm256_set1_pd(std::numeric_limits<double>::infinity()), x, y))", f457, 2, 256},
  {"256:_mm256_sub_pd(_mm256_setzero_pd(), _mm256_fnmsub_pd(_mm256_set1_pd(std::numeric_limits<double>::infinity()), x, y))", f458, 2, 256},
  {"256:_mm256_mul_pd(_mm256_fnmsub_pd(_mm256_set1_pd(std::numeric_limits<double>::infinity()), x, y), _mm256_set1_pd(-1.0))", f459, 2, 256},
  {"256:_mm256_floor_pd(_mm256_fnmsub_pd(_mm256_set1_pd(std::numeric_limits<double>::infinity()), x, y))", f460, 2, 256},
  {"256:_mm256_ceil_pd(_mm256_fnmsub_pd(_mm256_set1_pd(std::numeric_limits<double>::infinity()), x, y))", f461, 2, 256},
  {"256:_mm256_round_pd(_mm256_fnmsub_pd(_mm256_set1_pd(std::numeric_limits<double>::infinity()), x, y), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)", f462, 2, 256},
  {"256:_mm256_permute_pd(_mm256_fnmsub_pd(_mm256_set1_pd(std::numeric_limits<double>::infinity()), x, y), 0x5)", f463, 2, 256},
  {"256:_mm256_permute_pd(_mm256_fnmsub_pd(_mm256_set1_pd(std::numeric_limits<double>::infinity()), x, y), 0xa)", f464, 2, 256},
  {"256:_mm256_permute_pd(_mm256_fnmsub_pd(_mm256_set1_pd(std::numeric_limits<double>::infinity()), x, y), 0x3)", f465, 2, 256},
  {"256:_mm256_sqrt_pd(_mm256_fnmsub_pd(x, y, _mm256_set1_pd(std::numeric_limits<double>::quiet_NaN())))", f466, 2, 256},
  {"256:_mm256_xor_pd(_mm256_fnmsub_pd(x, y, _mm256_set1_pd(std::numeric_limits<double>::quiet_NaN())), _mm256_set1_pd(-0.0))", f467, 2, 256},
  {"256:_mm256_andnot_pd(_mm256_set1_pd(-0.0), _mm256_fnmsub_pd(x, y, _mm256_set1_pd(std::numeric_limits<double>::quiet_NaN())))", f468, 2, 256},
  {"256:_mm256_sub_pd(_mm256_setzero_pd(), _mm256_fnmsub_pd(x, y, _mm256_set1_pd(std::numeric_limits<double>::quiet_NaN())))", f469, 2, 256},
  {"256:_mm256_mul_pd(_mm256_fnmsub_pd(x, y, _mm256_set1_pd(std::numeric_limits<double>::quiet_NaN())), _mm256_set1_pd(-1.0))", f470, 2, 256},
  {"256:_mm256_floor_pd(_mm256_fnmsub_pd(x, y, _mm256_set1_pd(std::numeric_limits<double>::quiet_NaN())))", f471, 2, 256},
  {"256:_mm256_ceil_pd(_mm256_fnmsub_pd(x, y, _mm256_set1_pd(std::numeric_limits<double>::quiet_NaN())))", f472, 2, 256},
  {"256:_mm256_round_pd(_mm256_fnmsub_pd(x, y, _mm256_set1_pd(std::numeric_limits<double>::quiet_NaN())), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)", f473, 2, 256},
  {"256:_mm256_permute_pd(_mm256_fnmsub_pd(x, y, _mm256_set1_pd(std::numeric_limits<double>::quiet_NaN())), 0x5)", f474, 2, 256},
  {"256:_mm256_permute_pd(_mm256_fnmsub_pd(x, y, _mm256_set1_pd(std::numeric_limits<double>::quiet_NaN())), 0xa)", f475, 2, 256},
  {"256:_mm256_permute_pd(_mm256_fnmsub_pd(x, y, _mm256_set1_pd(std::numeric_limits<double>::quiet_NaN())), 0x3)", f476, 2, 256},
  {"256:_mm256_sqrt_pd(_mm256_fnmsub_pd(x, _mm256_set1_pd(std::numeric_limits<double>::quiet_NaN()), y))", f477, 2, 256},
  {"256:_mm256_xor_pd(_mm256_fnmsub_pd(x, _mm256_set1_pd(std::numeric_limits<double>::quiet_NaN()), y), _mm256_set1_pd(-0.0))", f478, 2, 256},
  {"256:_mm256_andnot_pd(_mm256_set1_pd(-0.0), _mm256_fnmsub_pd(x, _mm256_set1_pd(std::numeric_limits<double>::quiet_NaN()), y))", f479, 2, 256},
  {"256:_mm256_sub_pd(_mm256_setzero_pd(), _mm256_fnmsub_pd(x, _mm256_set1_pd(std::numeric_limits<double>::quiet_NaN()), y))", f480, 2, 256},
  {"256:_mm256_mul_pd(_mm256_fnmsub_pd(x, _mm256_set1_pd(std::numeric_limits<double>::quiet_NaN()), y), _mm256_set1_pd(-1.0))", f481, 2, 256},
  {"256:_mm256_floor_pd(_mm256_fnmsub_pd(x, _mm256_set1_pd(std::numeric_limits<double>::quiet_NaN()), y))", f482, 2, 256},
  {"256:_mm256_ceil_pd(_mm256_fnmsub_pd(x, _mm256_set1_pd(std::numeric_limits<double>::quiet_NaN()), y))", f483, 2, 256},
  {"256:_mm256_round_pd(_mm256_fnmsub_pd(x, _mm256_set1_pd(std::numeric_limits<double>::quiet_NaN()), y), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)", f484, 2, 256},
  {"256:_mm256_permute_pd(_mm256_fnmsub_pd(x, _mm256_set1_pd(std::numeric_limits<double>::quiet_NaN()), y), 0x5)", f485, 2, 256},
  {"256:_mm256_permute_pd(_mm256_fnmsub_pd(x, _mm256_set1_pd(std::numeric_limits<double>::quiet_NaN()), y), 0xa)", f486, 2, 256},
  {"256:_mm256_permute_pd(_mm256_fnmsub_pd(x, _mm256_set1_pd(std::numeric_limits<double>::quiet_NaN()), y), 0x3)", f487, 2, 256},
  {"256:_mm256_sqrt_pd(_mm256_fnmsub_pd(_mm256_set1_pd(std::numeric_limits<double>::quiet_NaN()), x, y))", f488, 2, 256},
  {"256:_mm256_xor_pd(_mm256_fnmsub_pd(_mm256_set1_pd(std::numeric_limits<double>::quiet_NaN()), x, y), _mm256_set1_pd(-0.0))", f489, 2, 256},
  {"256:_mm256_andnot_pd(_mm256_set1_pd(-0.0), _mm256_fnmsub_pd(_mm256_set1_pd(std::numeric_limits<double>::quiet_NaN()), x, y))", f490, 2, 256},
  {"256:_mm256_sub_pd(_mm256_setzero_pd(), _mm256_fnmsub_pd(_mm256_set1_pd(std::numeric_limits<double>::quiet_NaN()), x, y))", f491, 2, 256},
  {"256:_mm256_mul_pd(_mm256_fnmsub_pd(_mm256_set1_pd(std::numeric_limits<double>::quiet_NaN()), x, y), _mm256_set1_pd(-1.0))", f492, 2, 256},
  {"256:_mm256_floor_pd(_mm256_fnmsub_pd(_mm256_set1_pd(std::numeric_limits<double>::quiet_NaN()), x, y))", f493, 2, 256},
  {"256:_mm256_ceil_pd(_mm256_fnmsub_pd(_mm256_set1_pd(std::numeric_limits<double>::quiet_NaN()), x, y))", f494, 2, 256},
  {"256:_mm256_round_pd(_mm256_fnmsub_pd(_mm256_set1_pd(std::numeric_limits<double>::quiet_NaN()), x, y), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)", f495, 2, 256},
  {"256:_mm256_permute_pd(_mm256_fnmsub_pd(_mm256_set1_pd(std::numeric_limits<double>::quiet_NaN()), x, y), 0x5)", f496, 2, 256},
  {"256:_mm256_permute_pd(_mm256_fnmsub_pd(_mm256_set1_pd(std::numeric_limits<double>::quiet_NaN()), x, y), 0xa)", f497, 2, 256},
  {"256:_mm256_permute_pd(_mm256_fnmsub_pd(_mm256_set1_pd(std::numeric_limits<double>::quiet_NaN()), x, y), 0x3)", f498, 2, 256},
  {"256:_mm256_sqrt_pd(_mm256_fnmsub_pd(x, y, x))", f499, 2, 256},
  {"256:_mm256_xor_pd(_mm256_fnmsub_pd(x, y, x), _mm256_set1_pd(-0.0))", f500, 2, 256},
  {"256:_mm256_andnot_pd(_mm256_set1_pd(-0.0), _mm256_fnmsub_pd(x, y, x))", f501, 2, 256},
  {"256:_mm256_sub_pd(_mm256_setzero_pd(), _mm256_fnmsub_pd(x, y, x))", f502, 2, 256},
  {"256:_mm256_mul_pd(_mm256_fnmsub_pd(x, y, x), _mm256_set1_pd(-1.0))", f503, 2, 256},
  {"256:_mm256_floor_pd(_mm256_fnmsub_pd(x, y, x))", f504, 2, 256},
  {"256:_mm256_ceil_pd(_mm256_fnmsub_pd(x, y, x))", f505, 2, 256},
  {"256:_mm256_round_pd(_mm256_fnmsub_pd(x, y, x), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)", f506, 2, 256},
  {"256:_mm256_permute_pd(_mm256_fnmsub_pd(x, y, x), 0x5)", f507, 2, 256},
  {"256:_mm256_permute_pd(_mm256_fnmsub_pd(x, y, x), 0xa)", f508, 2, 256},
  {"256:_mm256_permute_pd(_mm256_fnmsub_pd(x, y, x), 0x3)", f509, 2, 256},
  {"256:_mm256_sqrt_pd(_mm256_fnmsub_pd(x, x, y))", f510, 2, 256},
  {"256:_mm256_xor_pd(_mm256_fnmsub_pd(x, x, y), _mm256_set1_pd(-0.0))", f511, 2, 256},
  {"256:_mm256_andnot_pd(_mm256_set1_pd(-0.0), _mm256_fnmsub_pd(x, x, y))", f512, 2, 256},
  {"256:_mm256_sub_pd(_mm256_setzero_pd(), _mm256_fnmsub_pd(x, x, y))", f513, 2, 256},
  {"256:_mm256_mul_pd(_mm256_fnmsub_pd(x, x, y), _mm256_set1_pd(-1.0))", f514, 2, 256},
  {"256:_mm256_floor_pd(_mm256_fnmsub_pd(x, x, y))", f515, 2, 256},
  {"256:_mm256_ceil_pd(_mm256_fnmsub_pd(x, x, y))", f516, 2, 256},
  {"256:_mm256_round_pd(_mm256_fnmsub_pd(x, x, y), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)", f517, 2, 256},
  {"256:_mm256_permute_pd(_mm256_fnmsub_pd(x, x, y), 0x5)", f518, 2, 256},
  {"256:_mm256_permute_pd(_mm256_fnmsub_pd(x, x, y), 0xa)", f519, 2, 256},
  {"256:_mm256_permute_pd(_mm256_fnmsub_pd(x, x, y), 0x3)", f520, 2, 256},
  {"256:_mm256_sqrt_pd(_mm256_fnmsub_pd(x, y, _mm256_mul_pd(x, y)))", f521, 2, 256},
  {"256:_mm256_xor_pd(_mm256_fnmsub_pd(x, y, _mm256_mul_pd(x, y)), _mm256_set1_pd(-0.0))", f522, 2, 256},
  {"256:_mm256_andnot_pd(_mm256_set1_pd(-0.0), _mm256_fnmsub_pd(x, y, _mm256_mul_pd(x, y)))", f523, 2, 256},
  {"256:_mm256_sub_pd(_mm256_setzero_pd(), _mm256_fnmsub_pd(x, y, _mm256_mul_pd(x, y)))", f524, 2, 256},
  {"256:_mm256_mul_pd(_mm256_fnmsub_pd(x, y, _mm256_mul_pd(x, y)), _mm256_set1_pd(-1.0))", f525, 2, 256},
  {"256:_mm256_floor_pd(_mm256_fnmsub_pd(x, y, _mm256_mul_pd(x, y)))", f526, 2, 256},
  {"256:_mm256_ceil_pd(_mm256_fnmsub_pd(x, y, _mm256_mul_pd(x, y)))", f527, 2, 256},
  {"256:_mm256_round_pd(_mm256_fnmsub_pd(x, y, _mm256_mul_pd(x, y)), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)", f528, 2, 256},
  {"256:_mm256_permute_pd(_mm256_fnmsub_pd(x, y, _mm256_mul_pd(x, y)), 0x5)", f529, 2, 256},
  {"256:_mm256_permute_pd(_mm256_fnmsub_pd(x, y, _mm256_mul_pd(x, y)), 0xa)", f530, 2, 256},
  {"256:_mm256_permute_pd(_mm256_fnmsub_pd(x, y, _mm256_mul_pd(x, y)), 0x3)", f531, 2, 256},
  {"256:_mm256_sqrt_pd(_mm256_blendv_pd(x, y, _mm256_cmp_pd(x, y, _CMP_GE_OS)))", f532, 2, 256},
  {"256:_mm256_xor_pd(_mm256_blendv_pd(x, y, _mm256_cmp_pd(x, y, _CMP_GE_OS)), _mm256_set1_pd(-0.0))", f533, 2, 256},
  {"256:_mm256_andnot_pd(_mm256_set1_pd(-0.0), _mm256_blendv_pd(x, y, _mm256_cmp_pd(x, y, _CMP_GE_OS)))", f534, 2, 256},
  {"256:_mm256_sub_pd(_mm256_setzero_pd(), _mm256_blendv_pd(x, y, _mm256_cmp_pd(x, y, _CMP_GE_OS)))", f535, 2, 256},
  {"256:_mm256_mul_pd(_mm256_blendv_pd(x, y, _mm256_cmp_pd(x, y, _CMP_GE_OS)), _mm256_set1_pd(-1.0))", f536, 2, 256},
  {"256:_mm256_floor_pd(_mm256_blendv_pd(x, y, _mm256_cmp_pd(x, y, _CMP_GE_OS)))", f537, 2, 256},
  {"256:_mm256_ceil_pd(_mm256_blendv_pd(x, y, _mm256_cmp_pd(x, y, _CMP_GE_OS)))", f538, 2, 256},
  {"256:_mm256_round_pd(_mm256_blendv_pd(x, y, _mm256_cmp_pd(x, y, _CMP_GE_OS)), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)", f539, 2, 256},
  {"256:_mm256_permute_pd(_mm256_blendv_pd(x, y, _mm256_cmp_pd(x, y, _CMP_GE_OS)), 0x5)", f540, 2, 256},
  {"256:_mm256_permute_pd(_mm256_blendv_pd(x, y, _mm256_cmp_pd(x, y, _CMP_GE_OS)), 0xa)", f541, 2, 256},
  {"256:_mm256_permute_pd(_mm256_blendv_pd(x, y, _mm256_cmp_pd(x, y, _CMP_GE_OS)), 0x3)", f542, 2, 256},
  {"256:_mm256_sqrt_pd(_mm256_blendv_pd(y, x, _mm256_cmp_pd(x, y, _CMP_GE_OS)))", f543, 2, 256},
  {"256:_mm256_xor_pd(_mm256_blendv_pd(y, x, _mm256_cmp_pd(x, y, _CMP_GE_OS)), _mm256_set1_pd(-0.0))", f544, 2, 256},
  {"256:_mm256_andnot_pd(_mm256_set1_pd(-0.0), _mm256_blendv_pd(y, x, _mm256_cmp_pd(x, y, _CMP_GE_OS)))", f545, 2, 256},
  {"256:_mm256_sub_pd(_mm256_setzero_pd(), _mm256_blendv_pd(y, x, _mm256_cmp_pd(x, y, _CMP_GE_OS)))", f546, 2, 256},
  {"256:_mm256_mul_pd(_mm256_blendv_pd(y, x, _mm256_cmp_pd(x, y, _CMP_GE_OS)), _mm256_set1_pd(-1.0))", f547, 2, 256},
  {"256:_mm256_floor_pd(_mm256_blendv_pd(y, x, _mm256_cmp_pd(x, y, _CMP_GE_OS)))", f548, 2, 256},
  {"256:_mm256_ceil_pd(_mm256_blendv_pd(y, x, _mm256_cmp_pd(x, y, _CMP_GE_OS)))", f549, 2, 256},
  {"256:_mm256_round_pd(_mm256_blendv_pd(y, x, _mm256_cmp_pd(x, y, _CMP_GE_OS)), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)", f550, 2, 256},
  {"256:_mm256_permute_pd(_mm256_blendv_pd(y, x, _mm256_cmp_pd(x, y, _CMP_GE_OS)), 0x5)", f551, 2, 256},
  {"256:_mm256_permute_pd(_mm256_blendv_pd(y, x, _mm256_cmp_pd(x, y, _CMP_GE_OS)), 0xa)", f552, 2, 256},
  {"256:_mm256_permute_pd(_mm256_blendv_pd(y, x, _mm256_cmp_pd(x, y, _CMP_GE_OS)), 0x3)", f553, 2, 256},
  {"256:_mm256_sqrt_pd(_mm256_blendv_pd(x, y, _mm256_cmp_pd(x, y, _CMP_NLE_US)))", f554, 2, 256},
  {"256:_mm256_xor_pd(_mm256_blendv_pd(x, y, _mm256_cmp_pd(x, y, _CMP_NLE_US)), _mm256_set1_pd(-0.0))", f555, 2, 256},
  {"256:_mm256_andnot_pd(_mm256_set1_pd(-0.0), _mm256_blendv_pd(x, y, _mm256_cmp_pd(x, y, _CMP_NLE_US)))", f556, 2, 256},
  {"256:_mm256_sub_pd(_mm256_setzero_pd(), _mm256_blendv_pd(x, y, _mm256_cmp_pd(x, y, _CMP_NLE_US)))", f557, 2, 256},
  {"256:_mm256_mul_pd(_mm256_blendv_pd(x, y, _mm256_cmp_pd(x, y, _CMP_NLE_US)), _mm256_set1_pd(-1.0))", f558, 2, 256},
  {"256:_mm256_floor_pd(_mm256_blendv_pd(x, y, _mm256_cmp_pd(x, y, _CMP_NLE_US)))", f559, 2, 256},
  {"256:_mm256_ceil_pd(_mm256_blendv_pd(x, y, _mm256_cmp_pd(x, y, _CMP_NLE_US)))", f560, 2, 256},
  {"256:_mm256_round_pd(_mm256_blendv_pd(x, y, _mm256_cmp_pd(x, y, _CMP_NLE_US)), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)", f561, 2, 256},
  {"256:_mm256_permute_pd(_mm256_blendv_pd(x, y, _mm256_cmp_pd(x, y, _CMP_NLE_US)), 0x5)", f562, 2, 256},
  {"256:_mm256_permute_pd(_mm256_blendv_pd(x, y, _mm256_cmp_pd(x, y, _CMP_NLE_US)), 0xa)", f563, 2, 256},
  {"256:_mm256_permute_pd(_mm256_blendv_pd(x, y, _mm256_cmp_pd(x, y, _CMP_NLE_US)), 0x3)", f564, 2, 256},
  {"256:_mm256_sqrt_pd(_mm256_blendv_pd(y, x, _mm256_cmp_pd(x, y, _CMP_NLE_US)))", f565, 2, 256},
  {"256:_mm256_xor_pd(_mm256_blendv_pd(y, x, _mm256_cmp_pd(x, y, _CMP_NLE_US)), _mm256_set1_pd(-0.0))", f566, 2, 256},
  {"256:_mm256_andnot_pd(_mm256_set1_pd(-0.0), _mm256_blendv_pd(y, x, _mm256_cmp_pd(x, y, _CMP_NLE_US)))", f567, 2, 256},
  {"256:_mm256_sub_pd(_mm256_setzero_pd(), _mm256_blendv_pd(y, x, _mm256_cmp_pd(x, y, _CMP_NLE_US)))", f568, 2, 256},
  {"256:_mm256_mul_pd(_mm256_blendv_pd(y, x, _mm256_cmp_pd(x, y, _CMP_NLE_US)), _mm256_set1_pd(-1.0))", f569, 2, 256},
  {"256:_mm256_floor_pd(_mm256_blendv_pd(y, x, _mm256_cmp_pd(x, y, _CMP_NLE_US)))", f570, 2, 256},
  {"256:_mm256_ceil_pd(_mm256_blendv_pd(y, x, _mm256_cmp_pd(x, y, _CMP_NLE_US)))", f571, 2, 256},
  {"256:_mm256_round_pd(_mm256_blendv_pd(y, x, _mm256_cmp_pd(x, y, _CMP_NLE_US)), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)", f572, 2, 256},
  {"256:_mm256_permute_pd(_mm256_blendv_pd(y, x, _mm256_cmp_pd(x, y, _CMP_NLE_US)), 0x5)", f573, 2, 256},
  {"256:_mm256_permute_pd(_mm256_blendv_pd(y, x, _mm256_cmp_pd(x, y, _CMP_NLE_US)), 0xa)", f574, 2, 256},
  {"256:_mm256_permute_pd(_mm256_blendv_pd(y, x, _mm256_cmp_pd(x, y, _CMP_NLE_US)), 0x3)", f575, 2, 256},
  {"256:_mm256_sqrt_pd(_mm256_blendv_pd(x, y, _mm256_cmp_pd(x, y, _CMP_NGT_US)))", f576, 2, 256},
  {"256:_mm256_xor_pd(_mm256_blendv_pd(x, y, _mm256_cmp_pd(x, y, _CMP_NGT_US)), _mm256_set1_pd(-0.0))", f577, 2, 256},
  {"256:_mm256_andnot_pd(_mm256_set1_pd(-0.0), _mm256_blendv_pd(x, y, _mm256_cmp_pd(x, y, _CMP_NGT_US)))", f578, 2, 256},
  {"256:_mm256_sub_pd(_mm256_setzero_pd(), _mm256_blendv_pd(x, y, _mm256_cmp_pd(x, y, _CMP_NGT_US)))", f579, 2, 256},
  {"256:_mm256_mul_pd(_mm256_blendv_pd(x, y, _mm256_cmp_pd(x, y, _CMP_NGT_US)), _mm256_set1_pd(-1.0))", f580, 2, 256},
  {"256:_mm256_floor_pd(_mm256_blendv_pd(x, y, _mm256_cmp_pd(x, y, _CMP_NGT_US)))", f581, 2, 256},
  {"256:_mm256_ceil_pd(_mm256_blendv_pd(x, y, _mm256_cmp_pd(x, y, _CMP_NGT_US)))", f582, 2, 256},
  {"256:_mm256_round_pd(_mm256_blendv_pd(x, y, _mm256_cmp_pd(x, y, _CMP_NGT_US)), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)", f583, 2, 256},
  {"256:_mm256_permute_pd(_mm256_blendv_pd(x, y, _mm256_cmp_pd(x, y, _CMP_NGT_US)), 0x5)", f584, 2, 256},
  {"256:_mm256_permute_pd(_mm256_blendv_pd(x, y, _mm256_cmp_pd(x, y, _CMP_NGT_US)), 0xa)", f585, 2, 256},
  {"256:_mm256_permute_pd(_mm256_blendv_pd(x, y, _mm256_cmp_pd(x, y, _CMP_NGT_US)), 0x3)", f586, 2, 256},
  {"256:_mm256_sqrt_pd(_mm256_blendv_pd(y, x, _mm256_cmp_pd(x, y, _CMP_NGT_US)))", f587, 2, 256},
  {"256:_mm256_xor_pd(_mm256_blendv_pd(y, x, _mm256_cmp_pd(x, y, _CMP_NGT_US)), _mm256_set1_pd(-0.0))", f588, 2, 256},
  {"256:_mm256_andnot_pd(_mm256_set1_pd(-0.0), _mm256_blendv_pd(y, x, _mm256_cmp_pd(x, y, _CMP_NGT_US)))", f589, 2, 256},
  {"256:_mm256_sub_pd(_mm256_setzero_pd(), _mm256_blendv_pd(y, x, _mm256_cmp_pd(x, y, _CMP_NGT_US)))", f590, 2, 256},
  {"256:_mm256_mul_pd(_mm256_blendv_pd(y, x, _mm256_cmp_pd(x, y, _CMP_NGT_US)), _mm256_set1_pd(-1.0))", f591, 2, 256},
  {"256:_mm256_floor_pd(_mm256_blendv_pd(y, x, _mm256_cmp_pd(x, y, _CMP_NGT_US)))", f592, 2, 256},
  {"256:_mm256_ceil_pd(_mm256_blendv_pd(y, x, _mm256_cmp_pd(x, y, _CMP_NGT_US)))", f593, 2, 256},
  {"256:_mm256_round_pd(_mm256_blendv_pd(y, x, _mm256_cmp_pd(x, y, _CMP_NGT_US)), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)", f594, 2, 256},
  {"256:_mm256_permute_pd(_mm256_blendv_pd(y, x, _mm256_cmp_pd(x, y, _CMP_NGT_US)), 0x5)", f595, 2, 256},
  {"256:_mm256_permute_pd(_mm256_blendv_pd(y, x, _mm256_cmp_pd(x, y, _CMP_NGT_US)), 0xa)", f596, 2, 256},
  {"256:_mm256_permute_pd(_mm256_blendv_pd(y, x, _mm256_cmp_pd(x, y, _CMP_NGT_US)), 0x3)", f597, 2, 256},
  {"256:_mm256_sqrt_pd(_mm256_blendv_pd(x, y, _mm256_cmp_pd(x, y, _CMP_LE_OQ)))", f598, 2, 256},
  {"256:_mm256_xor_pd(_mm256_blendv_pd(x, y, _mm256_cmp_pd(x, y, _CMP_LE_OQ)), _mm256_set1_pd(-0.0))", f599, 2, 256},
  {"256:_mm256_andnot_pd(_mm256_set1_pd(-0.0), _mm256_blendv_pd(x, y, _mm256_cmp_pd(x, y, _CMP_LE_OQ)))", f600, 2, 256},
  {"256:_mm256_sub_pd(_mm256_setzero_pd(), _mm256_blendv_pd(x, y, _mm256_cmp_pd(x, y, _CMP_LE_OQ)))", f601, 2, 256},
  {"256:_mm256_mul_pd(_mm256_blendv_pd(x, y, _mm256_cmp_pd(x, y, _CMP_LE_OQ)), _mm256_set1_pd(-1.0))", f602, 2, 256},
  {"256:_mm256_floor_pd(_mm256_blendv_pd(x, y, _mm256_cmp_pd(x, y, _CMP_LE_OQ)))", f603, 2, 256},
  {"256:_mm256_ceil_pd(_mm256_blendv_pd(x, y, _mm256_cmp_pd(x, y, _CMP_LE_OQ)))", f604, 2, 256},
  {"256:_mm256_round_pd(_mm256_blendv_pd(x, y, _mm256_cmp_pd(x, y, _CMP_LE_OQ)), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)", f605, 2, 256},
  {"256:_mm256_permute_pd(_mm256_blendv_pd(x, y, _mm256_cmp_pd(x, y, _CMP_LE_OQ)), 0x5)", f606, 2, 256},
  {"256:_mm256_permute_pd(_mm256_blendv_pd(x, y, _mm256_cmp_pd(x, y, _CMP_LE_OQ)), 0xa)", f607, 2, 256},
  {"256:_mm256_permute_pd(_mm256_blendv_pd(x, y, _mm256_cmp_pd(x, y, _CMP_LE_OQ)), 0x3)", f608, 2, 256},
  {"256:_mm256_sqrt_pd(_mm256_blendv_pd(y, x, _mm256_cmp_pd(x, y, _CMP_LE_OQ)))", f609, 2, 256},
  {"256:_mm256_xor_pd(_mm256_blendv_pd(y, x, _mm256_cmp_pd(x, y, _CMP_LE_OQ)), _mm256_set1_pd(-0.0))", f610, 2, 256},
  {"256:_mm256_andnot_pd(_mm256_set1_pd(-0.0), _mm256_blendv_pd(y, x, _mm256_cmp_pd(x, y, _CMP_LE_OQ)))", f611, 2, 256},
  {"256:_mm256_sub_pd(_mm256_setzero_pd(), _mm256_blendv_pd(y, x, _mm256_cmp_pd(x, y, _CMP_LE_OQ)))", f612, 2, 256},
  {"256:_mm256_mul_pd(_mm256_blendv_pd(y, x, _mm256_cmp_pd(x, y, _CMP_LE_OQ)), _mm256_set1_pd(-1.0))", f613, 2, 256},
  {"256:_mm256_floor_pd(_mm256_blendv_pd(y, x, _mm256_cmp_pd(x, y, _CMP_LE_OQ)))", f614, 2, 256},
  {"256:_mm256_ceil_pd(_mm256_blendv_pd(y, x, _mm256_cmp_pd(x, y, _CMP_LE_OQ)))", f615, 2, 256},
  {"256:_mm256_round_pd(_mm256_blendv_pd(y, x, _mm256_cmp_pd(x, y, _CMP_LE_OQ)), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)", f616, 2, 256},
  {"256:_mm256_permute_pd(_mm256_blendv_pd(y, x, _mm256_cmp_pd(x, y, _CMP_LE_OQ)), 0x5)", f617, 2, 256},
  {"256:_mm256_permute_pd(_mm256_blendv_pd(y, x, _mm256_cmp_pd(x, y, _CMP_LE_OQ)), 0xa)", f618, 2, 256},
  {"256:_mm256_permute_pd(_mm256_blendv_pd(y, x, _mm256_cmp_pd(x, y, _CMP_LE_OQ)), 0x3)", f619, 2, 256},
  {"256:_mm256_sqrt_pd(_mm256_blendv_pd(x, y, _mm256_cmp_pd(x, y, _CMP_GE_OQ)))", f620, 2, 256},
  {"256:_mm256_xor_pd(_mm256_blendv_pd(x, y, _mm256_cmp_pd(x, y, _CMP_GE_OQ)), _mm256_set1_pd(-0.0))", f621, 2, 256},
  {"256:_mm256_andnot_pd(_mm256_set1_pd(-0.0), _mm256_blendv_pd(x, y, _mm256_cmp_pd(x, y, _CMP_GE_OQ)))", f622, 2, 256},
  {"256:_mm256_sub_pd(_mm256_setzero_pd(), _mm256_blendv_pd(x, y, _mm256_cmp_pd(x, y, _CMP_GE_OQ)))", f623, 2, 256},
  {"256:_mm256_mul_pd(_mm256_blendv_pd(x, y, _mm256_cmp_pd(x, y, _CMP_GE_OQ)), _mm256_set1_pd(-1.0))", f624, 2, 256},
  {"256:_mm256_floor_pd(_mm256_blendv_pd(x, y, _mm256_cmp_pd(x, y, _CMP_GE_OQ)))", f625, 2, 256},
  {"256:_mm256_ceil_pd(_mm256_blendv_pd(x, y, _mm256_cmp_pd(x, y, _CMP_GE_OQ)))", f626, 2, 256},
  {"256:_mm256_round_pd(_mm256_blendv_pd(x, y, _mm256_cmp_pd(x, y, _CMP_GE_OQ)), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)", f627, 2, 256},
  {"256:_mm256_permute_pd(_mm256_blendv_pd(x, y, _mm256_cmp_pd(x, y, _CMP_GE_OQ)), 0x5)", f628, 2, 256},
  {"256:_mm256_permute_pd(_mm256_blendv_pd(x, y, _mm256_cmp_pd(x, y, _CMP_GE_OQ)), 0xa)", f629, 2, 256},
  {"256:_mm256_permute_pd(_mm256_blendv_pd(x, y, _mm256_cmp_pd(x, y, _CMP_GE_OQ)), 0x3)", f630, 2, 256},
  {"256:_mm256_sqrt_pd(_mm256_blendv_pd(y, x, _mm256_cmp_pd(x, y, _CMP_GE_OQ)))", f631, 2, 256},
  {"256:_mm256_xor_pd(_mm256_blendv_pd(y, x, _mm256_cmp_pd(x, y, _CMP_GE_OQ)), _mm256_set1_pd(-0.0))", f632, 2, 256},
  {"256:_mm256_andnot_pd(_mm256_set1_pd(-0.0), _mm256_blendv_pd(y, x, _mm256_cmp_pd(x, y, _CMP_GE_OQ)))", f633, 2, 256},
  {"256:_mm256_sub_pd(_mm256_setzero_pd(), _mm256_blendv_pd(y, x, _mm256_cmp_pd(x, y, _CMP_GE_OQ)))", f634, 2, 256},
  {"256:_mm256_mul_pd(_mm256_blendv_pd(y, x, _mm256_cmp_pd(x, y, _CMP_GE_OQ)), _mm256_set1_pd(-1.0))", f635, 2, 256},
  {"256:_mm256_floor_pd(_mm256_blendv_pd(y, x, _mm256_cmp_pd(x, y, _CMP_GE_OQ)))", f636, 2, 256},
  {"256:_mm256_ceil_pd(_mm256_blendv_pd(y, x, _mm256_cmp_pd(x, y, _CMP_GE_OQ)))", f637, 2, 256},
  {"256:_mm256_round_pd(_mm256_blendv_pd(y, x, _mm256_cmp_pd(x, y, _CMP_GE_OQ)), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)", f638, 2, 256},
  {"256:_mm256_permute_pd(_mm256_blendv_pd(y, x, _mm256_cmp_pd(x, y, _CMP_GE_OQ)), 0x5)", f639, 2, 256},
  {"256:_mm256_permute_pd(_mm256_blendv_pd(y, x, _mm256_cmp_pd(x, y, _CMP_GE_OQ)), 0xa)", f640, 2, 256},
  {"256:_mm256_permute_pd(_mm256_blendv_pd(y, x, _mm256_cmp_pd(x, y, _CMP_GE_OQ)), 0x3)", f641, 2, 256},
  {"256:_mm256_sqrt_pd(_mm256_blendv_pd(x, y, _mm256_cmp_pd(x, y, _CMP_LT_OQ)))", f642, 2, 256},
  {"256:_mm256_xor_pd(_mm256_blendv_pd(x, y, _mm256_cmp_pd(x, y, _CMP_LT_OQ)), _mm256_set1_pd(-0.0))", f643, 2, 256},
  {"256:_mm256_andnot_pd(_mm256_set1_pd(-0.0), _mm256_blendv_pd(x, y, _mm256_cmp_pd(x, y, _CMP_LT_OQ)))", f644, 2, 256},
  {"256:_mm256_sub_pd(_mm256_setzero_pd(), _mm256_blendv_pd(x, y, _mm256_cmp_pd(x, y, _CMP_LT_OQ)))", f645, 2, 256},
  {"256:_mm256_mul_pd(_mm256_blendv_pd(x, y, _mm256_cmp_pd(x, y, _CMP_LT_OQ)), _mm256_set1_pd(-1.0))", f646, 2, 256},
  {"256:_mm256_floor_pd(_mm256_blendv_pd(x, y, _mm256_cmp_pd(x, y, _CMP_LT_OQ)))", f647, 2, 256},
  {"256:_mm256_ceil_pd(_mm256_blendv_pd(x, y, _mm256_cmp_pd(x, y, _CMP_LT_OQ)))", f648, 2, 256},
  {"256:_mm256_round_pd(_mm256_blendv_pd(x, y, _mm256_cmp_pd(x, y, _CMP_LT_OQ)), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)", f649, 2, 256},
  {"256:_mm256_permute_pd(_mm256_blendv_pd(x, y, _mm256_cmp_pd(x, y, _CMP_LT_OQ)), 0x5)", f650, 2, 256},
  {"256:_mm256_permute_pd(_mm256_blendv_pd(x, y, _mm256_cmp_pd(x, y, _CMP_LT_OQ)), 0xa)", f651, 2, 256},
  {"256:_mm256_permute_pd(_mm256_blendv_pd(x, y, _mm256_cmp_pd(x, y, _CMP_LT_OQ)), 0x3)", f652, 2, 256},
  {"256:_mm256_sqrt_pd(_mm256_blendv_pd(y, x, _mm256_cmp_pd(x, y, _CMP_LT_OQ)))", f653, 2, 256},
  {"256:_mm256_xor_pd(_mm256_blendv_pd(y, x, _mm256_cmp_pd(x, y, _CMP_LT_OQ)), _mm256_set1_pd(-0.0))", f654, 2, 256},
  {"256:_mm256_andnot_pd(_mm256_set1_pd(-0.0), _mm256_blendv_pd(y, x, _mm256_cmp_pd(x, y, _CMP_LT_OQ)))", f655, 2, 256},
  {"256:_mm256_sub_pd(_mm256_setzero_pd(), _mm256_blendv_pd(y, x, _mm256_cmp_pd(x, y, _CMP_LT_OQ)))", f656, 2, 256},
  {"256:_mm256_mul_pd(_mm256_blendv_pd(y, x, _mm256_cmp_pd(x, y, _CMP_LT_OQ)), _mm256_set1_pd(-1.0))", f657, 2, 256},
  {"256:_mm256_floor_pd(_mm256_blendv_pd(y, x, _mm256_cmp_pd(x, y, _CMP_LT_OQ)))", f658, 2, 256},
  {"256:_mm256_ceil_pd(_mm256_blendv_pd(y, x, _mm256_cmp_pd(x, y, _CMP_LT_OQ)))", f659, 2, 256},
  {"256:_mm256_round_pd(_mm256_blendv_pd(y, x, _mm256_cmp_pd(x, y, _CMP_LT_OQ)), _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)", f660, 2, 256},
  {"256:_mm256_permute_pd(_mm256_blendv_pd(y, x, _mm256_cmp_pd(x, y, _CMP_LT_OQ)), 0x5)", f661, 2, 256},
  {"256:_mm256_permute_pd(_mm256_blendv_pd(y, x, _mm256_cmp_pd(x, y, _CMP_LT_OQ)), 0xa)", f662, 2, 256},
  {"256:_mm256_permute_pd(_mm256_blendv_pd(y, x, _mm256_cmp_pd(x, y, _CMP_LT_OQ)), 0x3)", f663, 2, 256},
  {"512:_mm512_abs_epi8(_mm512_abs_epi8(x))", f664, 0, 512},
  {"512:_mm512_abs_epi8(_mm512_abs_epi16(x))", f665, 0, 512},
  {"512:_mm512_abs_epi8(_mm512_abs_epi32(x))", f666, 0, 512},
  {"512:_mm512_abs_epi8(_mm512_abs_epi64(x))", f667, 0, 512},
  {"512:_mm512_abs_epi8(_mm512_sub_epi8(_mm512_setzero_si512(), x))", f668, 0, 512},
  {"512:_mm512_abs_epi8(_mm512_sub_epi16(_mm512_setzero_si512(), x))", f669, 0, 512},
  {"512:_mm512_abs_epi8(_mm512_sub_epi32(_mm512_setzero_si512(), x))", f670, 0, 512},
  {"512:_mm512_abs_epi8(_mm512_sub_epi64(_mm512_setzero_si512(), x))", f671, 0, 512},
  {"512:_mm512_abs_epi8(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)))", f672, 0, 512},
  {"512:_mm512_abs_epi8(_mm512_slli_epi16(x, 1))", f673, 0, 512},
  {"512:_mm512_abs_epi8(_mm512_srli_epi16(x, 1))", f674, 0, 512},
  {"512:_mm512_abs_epi8(_mm512_srai_epi16(x, 1))", f675, 0, 512},
  {"512:_mm512_abs_epi8(_mm512_slli_epi16(x, 15))", f676, 0, 512},
  {"512:_mm512_abs_epi8(_mm512_srli_epi16(x, 15))", f677, 0, 512},
  {"512:_mm512_abs_epi8(_mm512_srai_epi16(x, 15))", f678, 0, 512},
  {"512:_mm512_abs_epi8(_mm512_slli_epi32(x, 1))", f679, 0, 512},
  {"512:_mm512_abs_epi8(_mm512_srli_epi32(x, 1))", f680, 0, 512},
  {"512:_mm512_abs_epi8(_mm512_srai_epi32(x, 1))", f681, 0, 512},
  {"512:_mm512_abs_epi8(_mm512_slli_epi32(x, 31))", f682, 0, 512},
  {"512:_mm512_abs_epi8(_mm512_srli_epi32(x, 31))", f683, 0, 512},
  {"512:_mm512_abs_epi8(_mm512_srai_epi32(x, 31))", f684, 0, 512},
  {"512:_mm512_abs_epi8(_mm512_slli_epi64(x, 1))", f685, 0, 512},
  {"512:_mm512_abs_epi8(_mm512_srli_epi64(x, 1))", f686, 0, 512},
  {"512:_mm512_abs_epi8(_mm512_srai_epi64(x, 1))", f687, 0, 512},
  {"512:_mm512_abs_epi8(_mm512_slli_epi64(x, 63))", f688, 0, 512},
  {"512:_mm512_abs_epi8(_mm512_srli_epi64(x, 63))", f689, 0, 512},
  {"512:_mm512_abs_epi8(_mm512_srai_epi64(x, 63))", f690, 0, 512},
  {"512:_mm512_abs_epi16(_mm512_abs_epi8(x))", f691, 0, 512},
  {"512:_mm512_abs_epi16(_mm512_abs_epi16(x))", f692, 0, 512},
  {"512:_mm512_abs_epi16(_mm512_abs_epi32(x))", f693, 0, 512},
  {"512:_mm512_abs_epi16(_mm512_abs_epi64(x))", f694, 0, 512},
  {"512:_mm512_abs_epi16(_mm512_sub_epi8(_mm512_setzero_si512(), x))", f695, 0, 512},
  {"512:_mm512_abs_epi16(_mm512_sub_epi16(_mm512_setzero_si512(), x))", f696, 0, 512},
  {"512:_mm512_abs_epi16(_mm512_sub_epi32(_mm512_setzero_si512(), x))", f697, 0, 512},
  {"512:_mm512_abs_epi16(_mm512_sub_epi64(_mm512_setzero_si512(), x))", f698, 0, 512},
  {"512:_mm512_abs_epi16(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)))", f699, 0, 512},
  {"512:_mm512_abs_epi16(_mm512_slli_epi16(x, 1))", f700, 0, 512},
  {"512:_mm512_abs_epi16(_mm512_srli_epi16(x, 1))", f701, 0, 512},
  {"512:_mm512_abs_epi16(_mm512_srai_epi16(x, 1))", f702, 0, 512},
  {"512:_mm512_abs_epi16(_mm512_slli_epi16(x, 15))", f703, 0, 512},
  {"512:_mm512_abs_epi16(_mm512_srli_epi16(x, 15))", f704, 0, 512},
  {"512:_mm512_abs_epi16(_mm512_srai_epi16(x, 15))", f705, 0, 512},
  {"512:_mm512_abs_epi16(_mm512_slli_epi32(x, 1))", f706, 0, 512},
  {"512:_mm512_abs_epi16(_mm512_srli_epi32(x, 1))", f707, 0, 512},
  {"512:_mm512_abs_epi16(_mm512_srai_epi32(x, 1))", f708, 0, 512},
  {"512:_mm512_abs_epi16(_mm512_slli_epi32(x, 31))", f709, 0, 512},
  {"512:_mm512_abs_epi16(_mm512_srli_epi32(x, 31))", f710, 0, 512},
  {"512:_mm512_abs_epi16(_mm512_srai_epi32(x, 31))", f711, 0, 512},
  {"512:_mm512_abs_epi16(_mm512_slli_epi64(x, 1))", f712, 0, 512},
  {"512:_mm512_abs_epi16(_mm512_srli_epi64(x, 1))", f713, 0, 512},
  {"512:_mm512_abs_epi16(_mm512_srai_epi64(x, 1))", f714, 0, 512},
  {"512:_mm512_abs_epi16(_mm512_slli_epi64(x, 63))", f715, 0, 512},
  {"512:_mm512_abs_epi16(_mm512_srli_epi64(x, 63))", f716, 0, 512},
  {"512:_mm512_abs_epi16(_mm512_srai_epi64(x, 63))", f717, 0, 512},
  {"512:_mm512_abs_epi32(_mm512_abs_epi8(x))", f718, 0, 512},
  {"512:_mm512_abs_epi32(_mm512_abs_epi16(x))", f719, 0, 512},
  {"512:_mm512_abs_epi32(_mm512_abs_epi32(x))", f720, 0, 512},
  {"512:_mm512_abs_epi32(_mm512_abs_epi64(x))", f721, 0, 512},
  {"512:_mm512_abs_epi32(_mm512_sub_epi8(_mm512_setzero_si512(), x))", f722, 0, 512},
  {"512:_mm512_abs_epi32(_mm512_sub_epi16(_mm512_setzero_si512(), x))", f723, 0, 512},
  {"512:_mm512_abs_epi32(_mm512_sub_epi32(_mm512_setzero_si512(), x))", f724, 0, 512},
  {"512:_mm512_abs_epi32(_mm512_sub_epi64(_mm512_setzero_si512(), x))", f725, 0, 512},
  {"512:_mm512_abs_epi32(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)))", f726, 0, 512},
  {"512:_mm512_abs_epi32(_mm512_slli_epi16(x, 1))", f727, 0, 512},
  {"512:_mm512_abs_epi32(_mm512_srli_epi16(x, 1))", f728, 0, 512},
  {"512:_mm512_abs_epi32(_mm512_srai_epi16(x, 1))", f729, 0, 512},
  {"512:_mm512_abs_epi32(_mm512_slli_epi16(x, 15))", f730, 0, 512},
  {"512:_mm512_abs_epi32(_mm512_srli_epi16(x, 15))", f731, 0, 512},
  {"512:_mm512_abs_epi32(_mm512_srai_epi16(x, 15))", f732, 0, 512},
  {"512:_mm512_abs_epi32(_mm512_slli_epi32(x, 1))", f733, 0, 512},
  {"512:_mm512_abs_epi32(_mm512_srli_epi32(x, 1))", f734, 0, 512},
  {"512:_mm512_abs_epi32(_mm512_srai_epi32(x, 1))", f735, 0, 512},
  {"512:_mm512_abs_epi32(_mm512_slli_epi32(x, 31))", f736, 0, 512},
  {"512:_mm512_abs_epi32(_mm512_srli_epi32(x, 31))", f737, 0, 512},
  {"512:_mm512_abs_epi32(_mm512_srai_epi32(x, 31))", f738, 0, 512},
  {"512:_mm512_abs_epi32(_mm512_slli_epi64(x, 1))", f739, 0, 512},
  {"512:_mm512_abs_epi32(_mm512_srli_epi64(x, 1))", f740, 0, 512},
  {"512:_mm512_abs_epi32(_mm512_srai_epi64(x, 1))", f741, 0, 512},
  {"512:_mm512_abs_epi32(_mm512_slli_epi64(x, 63))", f742, 0, 512},
  {"512:_mm512_abs_epi32(_mm512_srli_epi64(x, 63))", f743, 0, 512},
  {"512:_mm512_abs_epi32(_mm512_srai_epi64(x, 63))", f744, 0, 512},
  {"512:_mm512_abs_epi64(_mm512_abs_epi8(x))", f745, 0, 512},
  {"512:_mm512_abs_epi64(_mm512_abs_epi16(x))", f746, 0, 512},
  {"512:_mm512_abs_epi64(_mm512_abs_epi32(x))", f747, 0, 512},
  {"512:_mm512_abs_epi64(_mm512_abs_epi64(x))", f748, 0, 512},
  {"512:_mm512_abs_epi64(_mm512_sub_epi8(_mm512_setzero_si512(), x))", f749, 0, 512},
  {"512:_mm512_abs_epi64(_mm512_sub_epi16(_mm512_setzero_si512(), x))", f750, 0, 512},
  {"512:_mm512_abs_epi64(_mm512_sub_epi32(_mm512_setzero_si512(), x))", f751, 0, 512},
  {"512:_mm512_abs_epi64(_mm512_sub_epi64(_mm512_setzero_si512(), x))", f752, 0, 512},
  {"512:_mm512_abs_epi64(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)))", f753, 0, 512},
  {"512:_mm512_abs_epi64(_mm512_slli_epi16(x, 1))", f754, 0, 512},
  {"512:_mm512_abs_epi64(_mm512_srli_epi16(x, 1))", f755, 0, 512},
  {"512:_mm512_abs_epi64(_mm512_srai_epi16(x, 1))", f756, 0, 512},
  {"512:_mm512_abs_epi64(_mm512_slli_epi16(x, 15))", f757, 0, 512},
  {"512:_mm512_abs_epi64(_mm512_srli_epi16(x, 15))", f758, 0, 512},
  {"512:_mm512_abs_epi64(_mm512_srai_epi16(x, 15))", f759, 0, 512},
  {"512:_mm512_abs_epi64(_mm512_slli_epi32(x, 1))", f760, 0, 512},
  {"512:_mm512_abs_epi64(_mm512_srli_epi32(x, 1))", f761, 0, 512},
  {"512:_mm512_abs_epi64(_mm512_srai_epi32(x, 1))", f762, 0, 512},
  {"512:_mm512_abs_epi64(_mm512_slli_epi32(x, 31))", f763, 0, 512},
  {"512:_mm512_abs_epi64(_mm512_srli_epi32(x, 31))", f764, 0, 512},
  {"512:_mm512_abs_epi64(_mm512_srai_epi32(x, 31))", f765, 0, 512},
  {"512:_mm512_abs_epi64(_mm512_slli_epi64(x, 1))", f766, 0, 512},
  {"512:_mm512_abs_epi64(_mm512_srli_epi64(x, 1))", f767, 0, 512},
  {"512:_mm512_abs_epi64(_mm512_srai_epi64(x, 1))", f768, 0, 512},
  {"512:_mm512_abs_epi64(_mm512_slli_epi64(x, 63))", f769, 0, 512},
  {"512:_mm512_abs_epi64(_mm512_srli_epi64(x, 63))", f770, 0, 512},
  {"512:_mm512_abs_epi64(_mm512_srai_epi64(x, 63))", f771, 0, 512},
  {"512:_mm512_sub_epi8(_mm512_setzero_si512(), _mm512_abs_epi8(x))", f772, 0, 512},
  {"512:_mm512_sub_epi8(_mm512_setzero_si512(), _mm512_abs_epi16(x))", f773, 0, 512},
  {"512:_mm512_sub_epi8(_mm512_setzero_si512(), _mm512_abs_epi32(x))", f774, 0, 512},
  {"512:_mm512_sub_epi8(_mm512_setzero_si512(), _mm512_abs_epi64(x))", f775, 0, 512},
  {"512:_mm512_sub_epi8(_mm512_setzero_si512(), _mm512_sub_epi8(_mm512_setzero_si512(), x))", f776, 0, 512},
  {"512:_mm512_sub_epi8(_mm512_setzero_si512(), _mm512_sub_epi16(_mm512_setzero_si512(), x))", f777, 0, 512},
  {"512:_mm512_sub_epi8(_mm512_setzero_si512(), _mm512_sub_epi32(_mm512_setzero_si512(), x))", f778, 0, 512},
  {"512:_mm512_sub_epi8(_mm512_setzero_si512(), _mm512_sub_epi64(_mm512_setzero_si512(), x))", f779, 0, 512},
  {"512:_mm512_sub_epi8(_mm512_setzero_si512(), _mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)))", f780, 0, 512},
  {"512:_mm512_sub_epi8(_mm512_setzero_si512(), _mm512_slli_epi16(x, 1))", f781, 0, 512},
  {"512:_mm512_sub_epi8(_mm512_setzero_si512(), _mm512_srli_epi16(x, 1))", f782, 0, 512},
  {"512:_mm512_sub_epi8(_mm512_setzero_si512(), _mm512_srai_epi16(x, 1))", f783, 0, 512},
  {"512:_mm512_sub_epi8(_mm512_setzero_si512(), _mm512_slli_epi16(x, 15))", f784, 0, 512},
  {"512:_mm512_sub_epi8(_mm512_setzero_si512(), _mm512_srli_epi16(x, 15))", f785, 0, 512},
  {"512:_mm512_sub_epi8(_mm512_setzero_si512(), _mm512_srai_epi16(x, 15))", f786, 0, 512},
  {"512:_mm512_sub_epi8(_mm512_setzero_si512(), _mm512_slli_epi32(x, 1))", f787, 0, 512},
  {"512:_mm512_sub_epi8(_mm512_setzero_si512(), _mm512_srli_epi32(x, 1))", f788, 0, 512},
  {"512:_mm512_sub_epi8(_mm512_setzero_si512(), _mm512_srai_epi32(x, 1))", f789, 0, 512},
  {"512:_mm512_sub_epi8(_mm512_setzero_si512(), _mm512_slli_epi32(x, 31))", f790, 0, 512},
  {"512:_mm512_sub_epi8(_mm512_setzero_si512(), _mm512_srli_epi32(x, 31))", f791, 0, 512},
  {"512:_mm512_sub_epi8(_mm512_setzero_si512(), _mm512_srai_epi32(x, 31))", f792, 0, 512},
  {"512:_mm512_sub_epi8(_mm512_setzero_si512(), _mm512_slli_epi64(x, 1))", f793, 0, 512},
  {"512:_mm512_sub_epi8(_mm512_setzero_si512(), _mm512_srli_epi64(x, 1))", f794, 0, 512},
  {"512:_mm512_sub_epi8(_mm512_setzero_si512(), _mm512_srai_epi64(x, 1))", f795, 0, 512},
  {"512:_mm512_sub_epi8(_mm512_setzero_si512(), _mm512_slli_epi64(x, 63))", f796, 0, 512},
  {"512:_mm512_sub_epi8(_mm512_setzero_si512(), _mm512_srli_epi64(x, 63))", f797, 0, 512},
  {"512:_mm512_sub_epi8(_mm512_setzero_si512(), _mm512_srai_epi64(x, 63))", f798, 0, 512},
  {"512:_mm512_sub_epi16(_mm512_setzero_si512(), _mm512_abs_epi8(x))", f799, 0, 512},
  {"512:_mm512_sub_epi16(_mm512_setzero_si512(), _mm512_abs_epi16(x))", f800, 0, 512},
  {"512:_mm512_sub_epi16(_mm512_setzero_si512(), _mm512_abs_epi32(x))", f801, 0, 512},
  {"512:_mm512_sub_epi16(_mm512_setzero_si512(), _mm512_abs_epi64(x))", f802, 0, 512},
  {"512:_mm512_sub_epi16(_mm512_setzero_si512(), _mm512_sub_epi8(_mm512_setzero_si512(), x))", f803, 0, 512},
  {"512:_mm512_sub_epi16(_mm512_setzero_si512(), _mm512_sub_epi16(_mm512_setzero_si512(), x))", f804, 0, 512},
  {"512:_mm512_sub_epi16(_mm512_setzero_si512(), _mm512_sub_epi32(_mm512_setzero_si512(), x))", f805, 0, 512},
  {"512:_mm512_sub_epi16(_mm512_setzero_si512(), _mm512_sub_epi64(_mm512_setzero_si512(), x))", f806, 0, 512},
  {"512:_mm512_sub_epi16(_mm512_setzero_si512(), _mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)))", f807, 0, 512},
  {"512:_mm512_sub_epi16(_mm512_setzero_si512(), _mm512_slli_epi16(x, 1))", f808, 0, 512},
  {"512:_mm512_sub_epi16(_mm512_setzero_si512(), _mm512_srli_epi16(x, 1))", f809, 0, 512},
  {"512:_mm512_sub_epi16(_mm512_setzero_si512(), _mm512_srai_epi16(x, 1))", f810, 0, 512},
  {"512:_mm512_sub_epi16(_mm512_setzero_si512(), _mm512_slli_epi16(x, 15))", f811, 0, 512},
  {"512:_mm512_sub_epi16(_mm512_setzero_si512(), _mm512_srli_epi16(x, 15))", f812, 0, 512},
  {"512:_mm512_sub_epi16(_mm512_setzero_si512(), _mm512_srai_epi16(x, 15))", f813, 0, 512},
  {"512:_mm512_sub_epi16(_mm512_setzero_si512(), _mm512_slli_epi32(x, 1))", f814, 0, 512},
  {"512:_mm512_sub_epi16(_mm512_setzero_si512(), _mm512_srli_epi32(x, 1))", f815, 0, 512},
  {"512:_mm512_sub_epi16(_mm512_setzero_si512(), _mm512_srai_epi32(x, 1))", f816, 0, 512},
  {"512:_mm512_sub_epi16(_mm512_setzero_si512(), _mm512_slli_epi32(x, 31))", f817, 0, 512},
  {"512:_mm512_sub_epi16(_mm512_setzero_si512(), _mm512_srli_epi32(x, 31))", f818, 0, 512},
  {"512:_mm512_sub_epi16(_mm512_setzero_si512(), _mm512_srai_epi32(x, 31))", f819, 0, 512},
  {"512:_mm512_sub_epi16(_mm512_setzero_si512(), _mm512_slli_epi64(x, 1))", f820, 0, 512},
  {"512:_mm512_sub_epi16(_mm512_setzero_si512(), _mm512_srli_epi64(x, 1))", f821, 0, 512},
  {"512:_mm512_sub_epi16(_mm512_setzero_si512(), _mm512_srai_epi64(x, 1))", f822, 0, 512},
  {"512:_mm512_sub_epi16(_mm512_setzero_si512(), _mm512_slli_epi64(x, 63))", f823, 0, 512},
  {"512:_mm512_sub_epi16(_mm512_setzero_si512(), _mm512_srli_epi64(x, 63))", f824, 0, 512},
  {"512:_mm512_sub_epi16(_mm512_setzero_si512(), _mm512_srai_epi64(x, 63))", f825, 0, 512},
  {"512:_mm512_sub_epi32(_mm512_setzero_si512(), _mm512_abs_epi8(x))", f826, 0, 512},
  {"512:_mm512_sub_epi32(_mm512_setzero_si512(), _mm512_abs_epi16(x))", f827, 0, 512},
  {"512:_mm512_sub_epi32(_mm512_setzero_si512(), _mm512_abs_epi32(x))", f828, 0, 512},
  {"512:_mm512_sub_epi32(_mm512_setzero_si512(), _mm512_abs_epi64(x))", f829, 0, 512},
  {"512:_mm512_sub_epi32(_mm512_setzero_si512(), _mm512_sub_epi8(_mm512_setzero_si512(), x))", f830, 0, 512},
  {"512:_mm512_sub_epi32(_mm512_setzero_si512(), _mm512_sub_epi16(_mm512_setzero_si512(), x))", f831, 0, 512},
  {"512:_mm512_sub_epi32(_mm512_setzero_si512(), _mm512_sub_epi32(_mm512_setzero_si512(), x))", f832, 0, 512},
  {"512:_mm512_sub_epi32(_mm512_setzero_si512(), _mm512_sub_epi64(_mm512_setzero_si512(), x))", f833, 0, 512},
  {"512:_mm512_sub_epi32(_mm512_setzero_si512(), _mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)))", f834, 0, 512},
  {"512:_mm512_sub_epi32(_mm512_setzero_si512(), _mm512_slli_epi16(x, 1))", f835, 0, 512},
  {"512:_mm512_sub_epi32(_mm512_setzero_si512(), _mm512_srli_epi16(x, 1))", f836, 0, 512},
  {"512:_mm512_sub_epi32(_mm512_setzero_si512(), _mm512_srai_epi16(x, 1))", f837, 0, 512},
  {"512:_mm512_sub_epi32(_mm512_setzero_si512(), _mm512_slli_epi16(x, 15))", f838, 0, 512},
  {"512:_mm512_sub_epi32(_mm512_setzero_si512(), _mm512_srli_epi16(x, 15))", f839, 0, 512},
  {"512:_mm512_sub_epi32(_mm512_setzero_si512(), _mm512_srai_epi16(x, 15))", f840, 0, 512},
  {"512:_mm512_sub_epi32(_mm512_setzero_si512(), _mm512_slli_epi32(x, 1))", f841, 0, 512},
  {"512:_mm512_sub_epi32(_mm512_setzero_si512(), _mm512_srli_epi32(x, 1))", f842, 0, 512},
  {"512:_mm512_sub_epi32(_mm512_setzero_si512(), _mm512_srai_epi32(x, 1))", f843, 0, 512},
  {"512:_mm512_sub_epi32(_mm512_setzero_si512(), _mm512_slli_epi32(x, 31))", f844, 0, 512},
  {"512:_mm512_sub_epi32(_mm512_setzero_si512(), _mm512_srli_epi32(x, 31))", f845, 0, 512},
  {"512:_mm512_sub_epi32(_mm512_setzero_si512(), _mm512_srai_epi32(x, 31))", f846, 0, 512},
  {"512:_mm512_sub_epi32(_mm512_setzero_si512(), _mm512_slli_epi64(x, 1))", f847, 0, 512},
  {"512:_mm512_sub_epi32(_mm512_setzero_si512(), _mm512_srli_epi64(x, 1))", f848, 0, 512},
  {"512:_mm512_sub_epi32(_mm512_setzero_si512(), _mm512_srai_epi64(x, 1))", f849, 0, 512},
  {"512:_mm512_sub_epi32(_mm512_setzero_si512(), _mm512_slli_epi64(x, 63))", f850, 0, 512},
  {"512:_mm512_sub_epi32(_mm512_setzero_si512(), _mm512_srli_epi64(x, 63))", f851, 0, 512},
  {"512:_mm512_sub_epi32(_mm512_setzero_si512(), _mm512_srai_epi64(x, 63))", f852, 0, 512},
  {"512:_mm512_sub_epi64(_mm512_setzero_si512(), _mm512_abs_epi8(x))", f853, 0, 512},
  {"512:_mm512_sub_epi64(_mm512_setzero_si512(), _mm512_abs_epi16(x))", f854, 0, 512},
  {"512:_mm512_sub_epi64(_mm512_setzero_si512(), _mm512_abs_epi32(x))", f855, 0, 512},
  {"512:_mm512_sub_epi64(_mm512_setzero_si512(), _mm512_abs_epi64(x))", f856, 0, 512},
  {"512:_mm512_sub_epi64(_mm512_setzero_si512(), _mm512_sub_epi8(_mm512_setzero_si512(), x))", f857, 0, 512},
  {"512:_mm512_sub_epi64(_mm512_setzero_si512(), _mm512_sub_epi16(_mm512_setzero_si512(), x))", f858, 0, 512},
  {"512:_mm512_sub_epi64(_mm512_setzero_si512(), _mm512_sub_epi32(_mm512_setzero_si512(), x))", f859, 0, 512},
  {"512:_mm512_sub_epi64(_mm512_setzero_si512(), _mm512_sub_epi64(_mm512_setzero_si512(), x))", f860, 0, 512},
  {"512:_mm512_sub_epi64(_mm512_setzero_si512(), _mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)))", f861, 0, 512},
  {"512:_mm512_sub_epi64(_mm512_setzero_si512(), _mm512_slli_epi16(x, 1))", f862, 0, 512},
  {"512:_mm512_sub_epi64(_mm512_setzero_si512(), _mm512_srli_epi16(x, 1))", f863, 0, 512},
  {"512:_mm512_sub_epi64(_mm512_setzero_si512(), _mm512_srai_epi16(x, 1))", f864, 0, 512},
  {"512:_mm512_sub_epi64(_mm512_setzero_si512(), _mm512_slli_epi16(x, 15))", f865, 0, 512},
  {"512:_mm512_sub_epi64(_mm512_setzero_si512(), _mm512_srli_epi16(x, 15))", f866, 0, 512},
  {"512:_mm512_sub_epi64(_mm512_setzero_si512(), _mm512_srai_epi16(x, 15))", f867, 0, 512},
  {"512:_mm512_sub_epi64(_mm512_setzero_si512(), _mm512_slli_epi32(x, 1))", f868, 0, 512},
  {"512:_mm512_sub_epi64(_mm512_setzero_si512(), _mm512_srli_epi32(x, 1))", f869, 0, 512},
  {"512:_mm512_sub_epi64(_mm512_setzero_si512(), _mm512_srai_epi32(x, 1))", f870, 0, 512},
  {"512:_mm512_sub_epi64(_mm512_setzero_si512(), _mm512_slli_epi32(x, 31))", f871, 0, 512},
  {"512:_mm512_sub_epi64(_mm512_setzero_si512(), _mm512_srli_epi32(x, 31))", f872, 0, 512},
  {"512:_mm512_sub_epi64(_mm512_setzero_si512(), _mm512_srai_epi32(x, 31))", f873, 0, 512},
  {"512:_mm512_sub_epi64(_mm512_setzero_si512(), _mm512_slli_epi64(x, 1))", f874, 0, 512},
  {"512:_mm512_sub_epi64(_mm512_setzero_si512(), _mm512_srli_epi64(x, 1))", f875, 0, 512},
  {"512:_mm512_sub_epi64(_mm512_setzero_si512(), _mm512_srai_epi64(x, 1))", f876, 0, 512},
  {"512:_mm512_sub_epi64(_mm512_setzero_si512(), _mm512_slli_epi64(x, 63))", f877, 0, 512},
  {"512:_mm512_sub_epi64(_mm512_setzero_si512(), _mm512_srli_epi64(x, 63))", f878, 0, 512},
  {"512:_mm512_sub_epi64(_mm512_setzero_si512(), _mm512_srai_epi64(x, 63))", f879, 0, 512},
  {"512:_mm512_xor_si512(_mm512_abs_epi8(x), _mm512_set1_epi8((char)0xffu))", f880, 0, 512},
  {"512:_mm512_xor_si512(_mm512_abs_epi16(x), _mm512_set1_epi8((char)0xffu))", f881, 0, 512},
  {"512:_mm512_xor_si512(_mm512_abs_epi32(x), _mm512_set1_epi8((char)0xffu))", f882, 0, 512},
  {"512:_mm512_xor_si512(_mm512_abs_epi64(x), _mm512_set1_epi8((char)0xffu))", f883, 0, 512},
  {"512:_mm512_xor_si512(_mm512_sub_epi8(_mm512_setzero_si512(), x), _mm512_set1_epi8((char)0xffu))", f884, 0, 512},
  {"512:_mm512_xor_si512(_mm512_sub_epi16(_mm512_setzero_si512(), x), _mm512_set1_epi8((char)0xffu))", f885, 0, 512},
  {"512:_mm512_xor_si512(_mm512_sub_epi32(_mm512_setzero_si512(), x), _mm512_set1_epi8((char)0xffu))", f886, 0, 512},
  {"512:_mm512_xor_si512(_mm512_sub_epi64(_mm512_setzero_si512(), x), _mm512_set1_epi8((char)0xffu))", f887, 0, 512},
  {"512:_mm512_xor_si512(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), _mm512_set1_epi8((char)0xffu))", f888, 0, 512},
  {"512:_mm512_xor_si512(_mm512_slli_epi16(x, 1), _mm512_set1_epi8((char)0xffu))", f889, 0, 512},
  {"512:_mm512_xor_si512(_mm512_srli_epi16(x, 1), _mm512_set1_epi8((char)0xffu))", f890, 0, 512},
  {"512:_mm512_xor_si512(_mm512_srai_epi16(x, 1), _mm512_set1_epi8((char)0xffu))", f891, 0, 512},
  {"512:_mm512_xor_si512(_mm512_slli_epi16(x, 15), _mm512_set1_epi8((char)0xffu))", f892, 0, 512},
  {"512:_mm512_xor_si512(_mm512_srli_epi16(x, 15), _mm512_set1_epi8((char)0xffu))", f893, 0, 512},
  {"512:_mm512_xor_si512(_mm512_srai_epi16(x, 15), _mm512_set1_epi8((char)0xffu))", f894, 0, 512},
  {"512:_mm512_xor_si512(_mm512_slli_epi32(x, 1), _mm512_set1_epi8((char)0xffu))", f895, 0, 512},
  {"512:_mm512_xor_si512(_mm512_srli_epi32(x, 1), _mm512_set1_epi8((char)0xffu))", f896, 0, 512},
  {"512:_mm512_xor_si512(_mm512_srai_epi32(x, 1), _mm512_set1_epi8((char)0xffu))", f897, 0, 512},
  {"512:_mm512_xor_si512(_mm512_slli_epi32(x, 31), _mm512_set1_epi8((char)0xffu))", f898, 0, 512},
  {"512:_mm512_xor_si512(_mm512_srli_epi32(x, 31), _mm512_set1_epi8((char)0xffu))", f899, 0, 512},
  {"512:_mm512_xor_si512(_mm512_srai_epi32(x, 31), _mm512_set1_epi8((char)0xffu))", f900, 0, 512},
  {"512:_mm512_xor_si512(_mm512_slli_epi64(x, 1), _mm512_set1_epi8((char)0xffu))", f901, 0, 512},
  {"512:_mm512_xor_si512(_mm512_srli_epi64(x, 1), _mm512_set1_epi8((char)0xffu))", f902, 0, 512},
  {"512:_mm512_xor_si512(_mm512_srai_epi64(x, 1), _mm512_set1_epi8((char)0xffu))", f903, 0, 512},
  {"512:_mm512_xor_si512(_mm512_slli_epi64(x, 63), _mm512_set1_epi8((char)0xffu))", f904, 0, 512},
  {"512:_mm512_xor_si512(_mm512_srli_epi64(x, 63), _mm512_set1_epi8((char)0xffu))", f905, 0, 512},
  {"512:_mm512_xor_si512(_mm512_srai_epi64(x, 63), _mm512_set1_epi8((char)0xffu))", f906, 0, 512},
  {"512:_mm512_slli_epi16(_mm512_abs_epi8(x), 1)", f907, 0, 512},
  {"512:_mm512_slli_epi16(_mm512_abs_epi16(x), 1)", f908, 0, 512},
  {"512:_mm512_slli_epi16(_mm512_abs_epi32(x), 1)", f909, 0, 512},
  {"512:_mm512_slli_epi16(_mm512_abs_epi64(x), 1)", f910, 0, 512},
  {"512:_mm512_slli_epi16(_mm512_sub_epi8(_mm512_setzero_si512(), x), 1)", f911, 0, 512},
  {"512:_mm512_slli_epi16(_mm512_sub_epi16(_mm512_setzero_si512(), x), 1)", f912, 0, 512},
  {"512:_mm512_slli_epi16(_mm512_sub_epi32(_mm512_setzero_si512(), x), 1)", f913, 0, 512},
  {"512:_mm512_slli_epi16(_mm512_sub_epi64(_mm512_setzero_si512(), x), 1)", f914, 0, 512},
  {"512:_mm512_slli_epi16(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), 1)", f915, 0, 512},
  {"512:_mm512_slli_epi16(_mm512_slli_epi16(x, 1), 1)", f916, 0, 512},
  {"512:_mm512_slli_epi16(_mm512_srli_epi16(x, 1), 1)", f917, 0, 512},
  {"512:_mm512_slli_epi16(_mm512_srai_epi16(x, 1), 1)", f918, 0, 512},
  {"512:_mm512_slli_epi16(_mm512_slli_epi16(x, 15), 1)", f919, 0, 512},
  {"512:_mm512_slli_epi16(_mm512_srli_epi16(x, 15), 1)", f920, 0, 512},
  {"512:_mm512_slli_epi16(_mm512_srai_epi16(x, 15), 1)", f921, 0, 512},
  {"512:_mm512_slli_epi16(_mm512_slli_epi32(x, 1), 1)", f922, 0, 512},
  {"512:_mm512_slli_epi16(_mm512_srli_epi32(x, 1), 1)", f923, 0, 512},
  {"512:_mm512_slli_epi16(_mm512_srai_epi32(x, 1), 1)", f924, 0, 512},
  {"512:_mm512_slli_epi16(_mm512_slli_epi32(x, 31), 1)", f925, 0, 512},
  {"512:_mm512_slli_epi16(_mm512_srli_epi32(x, 31), 1)", f926, 0, 512},
  {"512:_mm512_slli_epi16(_mm512_srai_epi32(x, 31), 1)", f927, 0, 512},
  {"512:_mm512_slli_epi16(_mm512_slli_epi64(x, 1), 1)", f928, 0, 512},
  {"512:_mm512_slli_epi16(_mm512_srli_epi64(x, 1), 1)", f929, 0, 512},
  {"512:_mm512_slli_epi16(_mm512_srai_epi64(x, 1), 1)", f930, 0, 512},
  {"512:_mm512_slli_epi16(_mm512_slli_epi64(x, 63), 1)", f931, 0, 512},
  {"512:_mm512_slli_epi16(_mm512_srli_epi64(x, 63), 1)", f932, 0, 512},
  {"512:_mm512_slli_epi16(_mm512_srai_epi64(x, 63), 1)", f933, 0, 512},
  {"512:_mm512_srli_epi16(_mm512_abs_epi8(x), 1)", f934, 0, 512},
  {"512:_mm512_srli_epi16(_mm512_abs_epi16(x), 1)", f935, 0, 512},
  {"512:_mm512_srli_epi16(_mm512_abs_epi32(x), 1)", f936, 0, 512},
  {"512:_mm512_srli_epi16(_mm512_abs_epi64(x), 1)", f937, 0, 512},
  {"512:_mm512_srli_epi16(_mm512_sub_epi8(_mm512_setzero_si512(), x), 1)", f938, 0, 512},
  {"512:_mm512_srli_epi16(_mm512_sub_epi16(_mm512_setzero_si512(), x), 1)", f939, 0, 512},
  {"512:_mm512_srli_epi16(_mm512_sub_epi32(_mm512_setzero_si512(), x), 1)", f940, 0, 512},
  {"512:_mm512_srli_epi16(_mm512_sub_epi64(_mm512_setzero_si512(), x), 1)", f941, 0, 512},
  {"512:_mm512_srli_epi16(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), 1)", f942, 0, 512},
  {"512:_mm512_srli_epi16(_mm512_slli_epi16(x, 1), 1)", f943, 0, 512},
  {"512:_mm512_srli_epi16(_mm512_srli_epi16(x, 1), 1)", f944, 0, 512},
  {"512:_mm512_srli_epi16(_mm512_srai_epi16(x, 1), 1)", f945, 0, 512},
  {"512:_mm512_srli_epi16(_mm512_slli_epi16(x, 15), 1)", f946, 0, 512},
  {"512:_mm512_srli_epi16(_mm512_srli_epi16(x, 15), 1)", f947, 0, 512},
  {"512:_mm512_srli_epi16(_mm512_srai_epi16(x, 15), 1)", f948, 0, 512},
  {"512:_mm512_srli_epi16(_mm512_slli_epi32(x, 1), 1)", f949, 0, 512},
  {"512:_mm512_srli_epi16(_mm512_srli_epi32(x, 1), 1)", f950, 0, 512},
  {"512:_mm512_srli_epi16(_mm512_srai_epi32(x, 1), 1)", f951, 0, 512},
  {"512:_mm512_srli_epi16(_mm512_slli_epi32(x, 31), 1)", f952, 0, 512},
  {"512:_mm512_srli_epi16(_mm512_srli_epi32(x, 31), 1)", f953, 0, 512},
  {"512:_mm512_srli_epi16(_mm512_srai_epi32(x, 31), 1)", f954, 0, 512},
  {"512:_mm512_srli_epi16(_mm512_slli_epi64(x, 1), 1)", f955, 0, 512},
  {"512:_mm512_srli_epi16(_mm512_srli_epi64(x, 1), 1)", f956, 0, 512},
  {"512:_mm512_srli_epi16(_mm512_srai_epi64(x, 1), 1)", f957, 0, 512},
  {"512:_mm512_srli_epi16(_mm512_slli_epi64(x, 63), 1)", f958, 0, 512},
  {"512:_mm512_srli_epi16(_mm512_srli_epi64(x, 63), 1)", f959, 0, 512},
  {"512:_mm512_srli_epi16(_mm512_srai_epi64(x, 63), 1)", f960, 0, 512},
  {"512:_mm512_srai_epi16(_mm512_abs_epi8(x), 1)", f961, 0, 512},
  {"512:_mm512_srai_epi16(_mm512_abs_epi16(x), 1)", f962, 0, 512},
  {"512:_mm512_srai_epi16(_mm512_abs_epi32(x), 1)", f963, 0, 512},
  {"512:_mm512_srai_epi16(_mm512_abs_epi64(x), 1)", f964, 0, 512},
  {"512:_mm512_srai_epi16(_mm512_sub_epi8(_mm512_setzero_si512(), x), 1)", f965, 0, 512},
  {"512:_mm512_srai_epi16(_mm512_sub_epi16(_mm512_setzero_si512(), x), 1)", f966, 0, 512},
  {"512:_mm512_srai_epi16(_mm512_sub_epi32(_mm512_setzero_si512(), x), 1)", f967, 0, 512},
  {"512:_mm512_srai_epi16(_mm512_sub_epi64(_mm512_setzero_si512(), x), 1)", f968, 0, 512},
  {"512:_mm512_srai_epi16(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), 1)", f969, 0, 512},
  {"512:_mm512_srai_epi16(_mm512_slli_epi16(x, 1), 1)", f970, 0, 512},
  {"512:_mm512_srai_epi16(_mm512_srli_epi16(x, 1), 1)", f971, 0, 512},
  {"512:_mm512_srai_epi16(_mm512_srai_epi16(x, 1), 1)", f972, 0, 512},
  {"512:_mm512_srai_epi16(_mm512_slli_epi16(x, 15), 1)", f973, 0, 512},
  {"512:_mm512_srai_epi16(_mm512_srli_epi16(x, 15), 1)", f974, 0, 512},
  {"512:_mm512_srai_epi16(_mm512_srai_epi16(x, 15), 1)", f975, 0, 512},
  {"512:_mm512_srai_epi16(_mm512_slli_epi32(x, 1), 1)", f976, 0, 512},
  {"512:_mm512_srai_epi16(_mm512_srli_epi32(x, 1), 1)", f977, 0, 512},
  {"512:_mm512_srai_epi16(_mm512_srai_epi32(x, 1), 1)", f978, 0, 512},
  {"512:_mm512_srai_epi16(_mm512_slli_epi32(x, 31), 1)", f979, 0, 512},
  {"512:_mm512_srai_epi16(_mm512_srli_epi32(x, 31), 1)", f980, 0, 512},
  {"512:_mm512_srai_epi16(_mm512_srai_epi32(x, 31), 1)", f981, 0, 512},
  {"512:_mm512_srai_epi16(_mm512_slli_epi64(x, 1), 1)", f982, 0, 512},
  {"512:_mm512_srai_epi16(_mm512_srli_epi64(x, 1), 1)", f983, 0, 512},
  {"512:_mm512_srai_epi16(_mm512_srai_epi64(x, 1), 1)", f984, 0, 512},
  {"512:_mm512_srai_epi16(_mm512_slli_epi64(x, 63), 1)", f985, 0, 512},
  {"512:_mm512_srai_epi16(_mm512_srli_epi64(x, 63), 1)", f986, 0, 512},
  {"512:_mm512_srai_epi16(_mm512_srai_epi64(x, 63), 1)", f987, 0, 512},
  {"512:_mm512_slli_epi16(_mm512_abs_epi8(x), 15)", f988, 0, 512},
  {"512:_mm512_slli_epi16(_mm512_abs_epi16(x), 15)", f989, 0, 512},
  {"512:_mm512_slli_epi16(_mm512_abs_epi32(x), 15)", f990, 0, 512},
  {"512:_mm512_slli_epi16(_mm512_abs_epi64(x), 15)", f991, 0, 512},
  {"512:_mm512_slli_epi16(_mm512_sub_epi8(_mm512_setzero_si512(), x), 15)", f992, 0, 512},
  {"512:_mm512_slli_epi16(_mm512_sub_epi16(_mm512_setzero_si512(), x), 15)", f993, 0, 512},
  {"512:_mm512_slli_epi16(_mm512_sub_epi32(_mm512_setzero_si512(), x), 15)", f994, 0, 512},
  {"512:_mm512_slli_epi16(_mm512_sub_epi64(_mm512_setzero_si512(), x), 15)", f995, 0, 512},
  {"512:_mm512_slli_epi16(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), 15)", f996, 0, 512},
  {"512:_mm512_slli_epi16(_mm512_slli_epi16(x, 1), 15)", f997, 0, 512},
  {"512:_mm512_slli_epi16(_mm512_srli_epi16(x, 1), 15)", f998, 0, 512},
  {"512:_mm512_slli_epi16(_mm512_srai_epi16(x, 1), 15)", f999, 0, 512},
  {"512:_mm512_slli_epi16(_mm512_slli_epi16(x, 15), 15)", f1000, 0, 512},
  {"512:_mm512_slli_epi16(_mm512_srli_epi16(x, 15), 15)", f1001, 0, 512},
  {"512:_mm512_slli_epi16(_mm512_srai_epi16(x, 15), 15)", f1002, 0, 512},
  {"512:_mm512_slli_epi16(_mm512_slli_epi32(x, 1), 15)", f1003, 0, 512},
  {"512:_mm512_slli_epi16(_mm512_srli_epi32(x, 1), 15)", f1004, 0, 512},
  {"512:_mm512_slli_epi16(_mm512_srai_epi32(x, 1), 15)", f1005, 0, 512},
  {"512:_mm512_slli_epi16(_mm512_slli_epi32(x, 31), 15)", f1006, 0, 512},
  {"512:_mm512_slli_epi16(_mm512_srli_epi32(x, 31), 15)", f1007, 0, 512},
  {"512:_mm512_slli_epi16(_mm512_srai_epi32(x, 31), 15)", f1008, 0, 512},
  {"512:_mm512_slli_epi16(_mm512_slli_epi64(x, 1), 15)", f1009, 0, 512},
  {"512:_mm512_slli_epi16(_mm512_srli_epi64(x, 1), 15)", f1010, 0, 512},
  {"512:_mm512_slli_epi16(_mm512_srai_epi64(x, 1), 15)", f1011, 0, 512},
  {"512:_mm512_slli_epi16(_mm512_slli_epi64(x, 63), 15)", f1012, 0, 512},
  {"512:_mm512_slli_epi16(_mm512_srli_epi64(x, 63), 15)", f1013, 0, 512},
  {"512:_mm512_slli_epi16(_mm512_srai_epi64(x, 63), 15)", f1014, 0, 512},
  {"512:_mm512_srli_epi16(_mm512_abs_epi8(x), 15)", f1015, 0, 512},
  {"512:_mm512_srli_epi16(_mm512_abs_epi16(x), 15)", f1016, 0, 512},
  {"512:_mm512_srli_epi16(_mm512_abs_epi32(x), 15)", f1017, 0, 512},
  {"512:_mm512_srli_epi16(_mm512_abs_epi64(x), 15)", f1018, 0, 512},
  {"512:_mm512_srli_epi16(_mm512_sub_epi8(_mm512_setzero_si512(), x), 15)", f1019, 0, 512},
  {"512:_mm512_srli_epi16(_mm512_sub_epi16(_mm512_setzero_si512(), x), 15)", f1020, 0, 512},
  {"512:_mm512_srli_epi16(_mm512_sub_epi32(_mm512_setzero_si512(), x), 15)", f1021, 0, 512},
  {"512:_mm512_srli_epi16(_mm512_sub_epi64(_mm512_setzero_si512(), x), 15)", f1022, 0, 512},
  {"512:_mm512_srli_epi16(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), 15)", f1023, 0, 512},
  {"512:_mm512_srli_epi16(_mm512_slli_epi16(x, 1), 15)", f1024, 0, 512},
  {"512:_mm512_srli_epi16(_mm512_srli_epi16(x, 1), 15)", f1025, 0, 512},
  {"512:_mm512_srli_epi16(_mm512_srai_epi16(x, 1), 15)", f1026, 0, 512},
  {"512:_mm512_srli_epi16(_mm512_slli_epi16(x, 15), 15)", f1027, 0, 512},
  {"512:_mm512_srli_epi16(_mm512_srli_epi16(x, 15), 15)", f1028, 0, 512},
  {"512:_mm512_srli_epi16(_mm512_srai_epi16(x, 15), 15)", f1029, 0, 512},
  {"512:_mm512_srli_epi16(_mm512_slli_epi32(x, 1), 15)", f1030, 0, 512},
  {"512:_mm512_srli_epi16(_mm512_srli_epi32(x, 1), 15)", f1031, 0, 512},
  {"512:_mm512_srli_epi16(_mm512_srai_epi32(x, 1), 15)", f1032, 0, 512},
  {"512:_mm512_srli_epi16(_mm512_slli_epi32(x, 31), 15)", f1033, 0, 512},
  {"512:_mm512_srli_epi16(_mm512_srli_epi32(x, 31), 15)", f1034, 0, 512},
  {"512:_mm512_srli_epi16(_mm512_srai_epi32(x, 31), 15)", f1035, 0, 512},
  {"512:_mm512_srli_epi16(_mm512_slli_epi64(x, 1), 15)", f1036, 0, 512},
  {"512:_mm512_srli_epi16(_mm512_srli_epi64(x, 1), 15)", f1037, 0, 512},
  {"512:_mm512_srli_epi16(_mm512_srai_epi64(x, 1), 15)", f1038, 0, 512},
  {"512:_mm512_srli_epi16(_mm512_slli_epi64(x, 63), 15)", f1039, 0, 512},
  {"512:_mm512_srli_epi16(_mm512_srli_epi64(x, 63), 15)", f1040, 0, 512},
  {"512:_mm512_srli_epi16(_mm512_srai_epi64(x, 63), 15)", f1041, 0, 512},
  {"512:_mm512_srai_epi16(_mm512_abs_epi8(x), 15)", f1042, 0, 512},
  {"512:_mm512_srai_epi16(_mm512_abs_epi16(x), 15)", f1043, 0, 512},
  {"512:_mm512_srai_epi16(_mm512_abs_epi32(x), 15)", f1044, 0, 512},
  {"512:_mm512_srai_epi16(_mm512_abs_epi64(x), 15)", f1045, 0, 512},
  {"512:_mm512_srai_epi16(_mm512_sub_epi8(_mm512_setzero_si512(), x), 15)", f1046, 0, 512},
  {"512:_mm512_srai_epi16(_mm512_sub_epi16(_mm512_setzero_si512(), x), 15)", f1047, 0, 512},
  {"512:_mm512_srai_epi16(_mm512_sub_epi32(_mm512_setzero_si512(), x), 15)", f1048, 0, 512},
  {"512:_mm512_srai_epi16(_mm512_sub_epi64(_mm512_setzero_si512(), x), 15)", f1049, 0, 512},
  {"512:_mm512_srai_epi16(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), 15)", f1050, 0, 512},
  {"512:_mm512_srai_epi16(_mm512_slli_epi16(x, 1), 15)", f1051, 0, 512},
  {"512:_mm512_srai_epi16(_mm512_srli_epi16(x, 1), 15)", f1052, 0, 512},
  {"512:_mm512_srai_epi16(_mm512_srai_epi16(x, 1), 15)", f1053, 0, 512},
  {"512:_mm512_srai_epi16(_mm512_slli_epi16(x, 15), 15)", f1054, 0, 512},
  {"512:_mm512_srai_epi16(_mm512_srli_epi16(x, 15), 15)", f1055, 0, 512},
  {"512:_mm512_srai_epi16(_mm512_srai_epi16(x, 15), 15)", f1056, 0, 512},
  {"512:_mm512_srai_epi16(_mm512_slli_epi32(x, 1), 15)", f1057, 0, 512},
  {"512:_mm512_srai_epi16(_mm512_srli_epi32(x, 1), 15)", f1058, 0, 512},
  {"512:_mm512_srai_epi16(_mm512_srai_epi32(x, 1), 15)", f1059, 0, 512},
  {"512:_mm512_srai_epi16(_mm512_slli_epi32(x, 31), 15)", f1060, 0, 512},
  {"512:_mm512_srai_epi16(_mm512_srli_epi32(x, 31), 15)", f1061, 0, 512},
  {"512:_mm512_srai_epi16(_mm512_srai_epi32(x, 31), 15)", f1062, 0, 512},
  {"512:_mm512_srai_epi16(_mm512_slli_epi64(x, 1), 15)", f1063, 0, 512},
  {"512:_mm512_srai_epi16(_mm512_srli_epi64(x, 1), 15)", f1064, 0, 512},
  {"512:_mm512_srai_epi16(_mm512_srai_epi64(x, 1), 15)", f1065, 0, 512},
  {"512:_mm512_srai_epi16(_mm512_slli_epi64(x, 63), 15)", f1066, 0, 512},
  {"512:_mm512_srai_epi16(_mm512_srli_epi64(x, 63), 15)", f1067, 0, 512},
  {"512:_mm512_srai_epi16(_mm512_srai_epi64(x, 63), 15)", f1068, 0, 512},
  {"512:_mm512_slli_epi32(_mm512_abs_epi8(x), 1)", f1069, 0, 512},
  {"512:_mm512_slli_epi32(_mm512_abs_epi16(x), 1)", f1070, 0, 512},
  {"512:_mm512_slli_epi32(_mm512_abs_epi32(x), 1)", f1071, 0, 512},
  {"512:_mm512_slli_epi32(_mm512_abs_epi64(x), 1)", f1072, 0, 512},
  {"512:_mm512_slli_epi32(_mm512_sub_epi8(_mm512_setzero_si512(), x), 1)", f1073, 0, 512},
  {"512:_mm512_slli_epi32(_mm512_sub_epi16(_mm512_setzero_si512(), x), 1)", f1074, 0, 512},
  {"512:_mm512_slli_epi32(_mm512_sub_epi32(_mm512_setzero_si512(), x), 1)", f1075, 0, 512},
  {"512:_mm512_slli_epi32(_mm512_sub_epi64(_mm512_setzero_si512(), x), 1)", f1076, 0, 512},
  {"512:_mm512_slli_epi32(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), 1)", f1077, 0, 512},
  {"512:_mm512_slli_epi32(_mm512_slli_epi16(x, 1), 1)", f1078, 0, 512},
  {"512:_mm512_slli_epi32(_mm512_srli_epi16(x, 1), 1)", f1079, 0, 512},
  {"512:_mm512_slli_epi32(_mm512_srai_epi16(x, 1), 1)", f1080, 0, 512},
  {"512:_mm512_slli_epi32(_mm512_slli_epi16(x, 15), 1)", f1081, 0, 512},
  {"512:_mm512_slli_epi32(_mm512_srli_epi16(x, 15), 1)", f1082, 0, 512},
  {"512:_mm512_slli_epi32(_mm512_srai_epi16(x, 15), 1)", f1083, 0, 512},
  {"512:_mm512_slli_epi32(_mm512_slli_epi32(x, 1), 1)", f1084, 0, 512},
  {"512:_mm512_slli_epi32(_mm512_srli_epi32(x, 1), 1)", f1085, 0, 512},
  {"512:_mm512_slli_epi32(_mm512_srai_epi32(x, 1), 1)", f1086, 0, 512},
  {"512:_mm512_slli_epi32(_mm512_slli_epi32(x, 31), 1)", f1087, 0, 512},
  {"512:_mm512_slli_epi32(_mm512_srli_epi32(x, 31), 1)", f1088, 0, 512},
  {"512:_mm512_slli_epi32(_mm512_srai_epi32(x, 31), 1)", f1089, 0, 512},
  {"512:_mm512_slli_epi32(_mm512_slli_epi64(x, 1), 1)", f1090, 0, 512},
  {"512:_mm512_slli_epi32(_mm512_srli_epi64(x, 1), 1)", f1091, 0, 512},
  {"512:_mm512_slli_epi32(_mm512_srai_epi64(x, 1), 1)", f1092, 0, 512},
  {"512:_mm512_slli_epi32(_mm512_slli_epi64(x, 63), 1)", f1093, 0, 512},
  {"512:_mm512_slli_epi32(_mm512_srli_epi64(x, 63), 1)", f1094, 0, 512},
  {"512:_mm512_slli_epi32(_mm512_srai_epi64(x, 63), 1)", f1095, 0, 512},
  {"512:_mm512_srli_epi32(_mm512_abs_epi8(x), 1)", f1096, 0, 512},
  {"512:_mm512_srli_epi32(_mm512_abs_epi16(x), 1)", f1097, 0, 512},
  {"512:_mm512_srli_epi32(_mm512_abs_epi32(x), 1)", f1098, 0, 512},
  {"512:_mm512_srli_epi32(_mm512_abs_epi64(x), 1)", f1099, 0, 512},
  {"512:_mm512_srli_epi32(_mm512_sub_epi8(_mm512_setzero_si512(), x), 1)", f1100, 0, 512},
  {"512:_mm512_srli_epi32(_mm512_sub_epi16(_mm512_setzero_si512(), x), 1)", f1101, 0, 512},
  {"512:_mm512_srli_epi32(_mm512_sub_epi32(_mm512_setzero_si512(), x), 1)", f1102, 0, 512},
  {"512:_mm512_srli_epi32(_mm512_sub_epi64(_mm512_setzero_si512(), x), 1)", f1103, 0, 512},
  {"512:_mm512_srli_epi32(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), 1)", f1104, 0, 512},
  {"512:_mm512_srli_epi32(_mm512_slli_epi16(x, 1), 1)", f1105, 0, 512},
  {"512:_mm512_srli_epi32(_mm512_srli_epi16(x, 1), 1)", f1106, 0, 512},
  {"512:_mm512_srli_epi32(_mm512_srai_epi16(x, 1), 1)", f1107, 0, 512},
  {"512:_mm512_srli_epi32(_mm512_slli_epi16(x, 15), 1)", f1108, 0, 512},
  {"512:_mm512_srli_epi32(_mm512_srli_epi16(x, 15), 1)", f1109, 0, 512},
  {"512:_mm512_srli_epi32(_mm512_srai_epi16(x, 15), 1)", f1110, 0, 512},
  {"512:_mm512_srli_epi32(_mm512_slli_epi32(x, 1), 1)", f1111, 0, 512},
  {"512:_mm512_srli_epi32(_mm512_srli_epi32(x, 1), 1)", f1112, 0, 512},
  {"512:_mm512_srli_epi32(_mm512_srai_epi32(x, 1), 1)", f1113, 0, 512},
  {"512:_mm512_srli_epi32(_mm512_slli_epi32(x, 31), 1)", f1114, 0, 512},
  {"512:_mm512_srli_epi32(_mm512_srli_epi32(x, 31), 1)", f1115, 0, 512},
  {"512:_mm512_srli_epi32(_mm512_srai_epi32(x, 31), 1)", f1116, 0, 512},
  {"512:_mm512_srli_epi32(_mm512_slli_epi64(x, 1), 1)", f1117, 0, 512},
  {"512:_mm512_srli_epi32(_mm512_srli_epi64(x, 1), 1)", f1118, 0, 512},
  {"512:_mm512_srli_epi32(_mm512_srai_epi64(x, 1), 1)", f1119, 0, 512},
  {"512:_mm512_srli_epi32(_mm512_slli_epi64(x, 63), 1)", f1120, 0, 512},
  {"512:_mm512_srli_epi32(_mm512_srli_epi64(x, 63), 1)", f1121, 0, 512},
  {"512:_mm512_srli_epi32(_mm512_srai_epi64(x, 63), 1)", f1122, 0, 512},
  {"512:_mm512_srai_epi32(_mm512_abs_epi8(x), 1)", f1123, 0, 512},
  {"512:_mm512_srai_epi32(_mm512_abs_epi16(x), 1)", f1124, 0, 512},
  {"512:_mm512_srai_epi32(_mm512_abs_epi32(x), 1)", f1125, 0, 512},
  {"512:_mm512_srai_epi32(_mm512_abs_epi64(x), 1)", f1126, 0, 512},
  {"512:_mm512_srai_epi32(_mm512_sub_epi8(_mm512_setzero_si512(), x), 1)", f1127, 0, 512},
  {"512:_mm512_srai_epi32(_mm512_sub_epi16(_mm512_setzero_si512(), x), 1)", f1128, 0, 512},
  {"512:_mm512_srai_epi32(_mm512_sub_epi32(_mm512_setzero_si512(), x), 1)", f1129, 0, 512},
  {"512:_mm512_srai_epi32(_mm512_sub_epi64(_mm512_setzero_si512(), x), 1)", f1130, 0, 512},
  {"512:_mm512_srai_epi32(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), 1)", f1131, 0, 512},
  {"512:_mm512_srai_epi32(_mm512_slli_epi16(x, 1), 1)", f1132, 0, 512},
  {"512:_mm512_srai_epi32(_mm512_srli_epi16(x, 1), 1)", f1133, 0, 512},
  {"512:_mm512_srai_epi32(_mm512_srai_epi16(x, 1), 1)", f1134, 0, 512},
  {"512:_mm512_srai_epi32(_mm512_slli_epi16(x, 15), 1)", f1135, 0, 512},
  {"512:_mm512_srai_epi32(_mm512_srli_epi16(x, 15), 1)", f1136, 0, 512},
  {"512:_mm512_srai_epi32(_mm512_srai_epi16(x, 15), 1)", f1137, 0, 512},
  {"512:_mm512_srai_epi32(_mm512_slli_epi32(x, 1), 1)", f1138, 0, 512},
  {"512:_mm512_srai_epi32(_mm512_srli_epi32(x, 1), 1)", f1139, 0, 512},
  {"512:_mm512_srai_epi32(_mm512_srai_epi32(x, 1), 1)", f1140, 0, 512},
  {"512:_mm512_srai_epi32(_mm512_slli_epi32(x, 31), 1)", f1141, 0, 512},
  {"512:_mm512_srai_epi32(_mm512_srli_epi32(x, 31), 1)", f1142, 0, 512},
  {"512:_mm512_srai_epi32(_mm512_srai_epi32(x, 31), 1)", f1143, 0, 512},
  {"512:_mm512_srai_epi32(_mm512_slli_epi64(x, 1), 1)", f1144, 0, 512},
  {"512:_mm512_srai_epi32(_mm512_srli_epi64(x, 1), 1)", f1145, 0, 512},
  {"512:_mm512_srai_epi32(_mm512_srai_epi64(x, 1), 1)", f1146, 0, 512},
  {"512:_mm512_srai_epi32(_mm512_slli_epi64(x, 63), 1)", f1147, 0, 512},
  {"512:_mm512_srai_epi32(_mm512_srli_epi64(x, 63), 1)", f1148, 0, 512},
  {"512:_mm512_srai_epi32(_mm512_srai_epi64(x, 63), 1)", f1149, 0, 512},
  {"512:_mm512_slli_epi32(_mm512_abs_epi8(x), 31)", f1150, 0, 512},
  {"512:_mm512_slli_epi32(_mm512_abs_epi16(x), 31)", f1151, 0, 512},
  {"512:_mm512_slli_epi32(_mm512_abs_epi32(x), 31)", f1152, 0, 512},
  {"512:_mm512_slli_epi32(_mm512_abs_epi64(x), 31)", f1153, 0, 512},
  {"512:_mm512_slli_epi32(_mm512_sub_epi8(_mm512_setzero_si512(), x), 31)", f1154, 0, 512},
  {"512:_mm512_slli_epi32(_mm512_sub_epi16(_mm512_setzero_si512(), x), 31)", f1155, 0, 512},
  {"512:_mm512_slli_epi32(_mm512_sub_epi32(_mm512_setzero_si512(), x), 31)", f1156, 0, 512},
  {"512:_mm512_slli_epi32(_mm512_sub_epi64(_mm512_setzero_si512(), x), 31)", f1157, 0, 512},
  {"512:_mm512_slli_epi32(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), 31)", f1158, 0, 512},
  {"512:_mm512_slli_epi32(_mm512_slli_epi16(x, 1), 31)", f1159, 0, 512},
  {"512:_mm512_slli_epi32(_mm512_srli_epi16(x, 1), 31)", f1160, 0, 512},
  {"512:_mm512_slli_epi32(_mm512_srai_epi16(x, 1), 31)", f1161, 0, 512},
  {"512:_mm512_slli_epi32(_mm512_slli_epi16(x, 15), 31)", f1162, 0, 512},
  {"512:_mm512_slli_epi32(_mm512_srli_epi16(x, 15), 31)", f1163, 0, 512},
  {"512:_mm512_slli_epi32(_mm512_srai_epi16(x, 15), 31)", f1164, 0, 512},
  {"512:_mm512_slli_epi32(_mm512_slli_epi32(x, 1), 31)", f1165, 0, 512},
  {"512:_mm512_slli_epi32(_mm512_srli_epi32(x, 1), 31)", f1166, 0, 512},
  {"512:_mm512_slli_epi32(_mm512_srai_epi32(x, 1), 31)", f1167, 0, 512},
  {"512:_mm512_slli_epi32(_mm512_slli_epi32(x, 31), 31)", f1168, 0, 512},
  {"512:_mm512_slli_epi32(_mm512_srli_epi32(x, 31), 31)", f1169, 0, 512},
  {"512:_mm512_slli_epi32(_mm512_srai_epi32(x, 31), 31)", f1170, 0, 512},
  {"512:_mm512_slli_epi32(_mm512_slli_epi64(x, 1), 31)", f1171, 0, 512},
  {"512:_mm512_slli_epi32(_mm512_srli_epi64(x, 1), 31)", f1172, 0, 512},
  {"512:_mm512_slli_epi32(_mm512_srai_epi64(x, 1), 31)", f1173, 0, 512},
  {"512:_mm512_slli_epi32(_mm512_slli_epi64(x, 63), 31)", f1174, 0, 512},
  {"512:_mm512_slli_epi32(_mm512_srli_epi64(x, 63), 31)", f1175, 0, 512},
  {"512:_mm512_slli_epi32(_mm512_srai_epi64(x, 63), 31)", f1176, 0, 512},
  {"512:_mm512_srli_epi32(_mm512_abs_epi8(x), 31)", f1177, 0, 512},
  {"512:_mm512_srli_epi32(_mm512_abs_epi16(x), 31)", f1178, 0, 512},
  {"512:_mm512_srli_epi32(_mm512_abs_epi32(x), 31)", f1179, 0, 512},
  {"512:_mm512_srli_epi32(_mm512_abs_epi64(x), 31)", f1180, 0, 512},
  {"512:_mm512_srli_epi32(_mm512_sub_epi8(_mm512_setzero_si512(), x), 31)", f1181, 0, 512},
  {"512:_mm512_srli_epi32(_mm512_sub_epi16(_mm512_setzero_si512(), x), 31)", f1182, 0, 512},
  {"512:_mm512_srli_epi32(_mm512_sub_epi32(_mm512_setzero_si512(), x), 31)", f1183, 0, 512},
  {"512:_mm512_srli_epi32(_mm512_sub_epi64(_mm512_setzero_si512(), x), 31)", f1184, 0, 512},
  {"512:_mm512_srli_epi32(_mm512_xor_si512(x, _mm512_set1_epi8((char)0xffu)), 31)", f1185, 0, 512},
  {"512:_mm512_srli_epi32(_mm512_slli_epi16(x, 1), 31)", f1186, 0, 512},
  {"512:_mm512_srli_epi32(_mm512_srli_epi16(x, 1), 31)", f1187, 0, 512},
  {"512:_mm512_srli_epi32(_mm512_srai_epi16(x, 1), 31)", f1188, 0, 512},
  {"512:_mm512_srli_epi32(_mm512_slli_epi16(x, 15), 31)", f1189, 0, 512},
  {"512:_mm512_srli_epi32(_mm512_srli_epi16(x, 15), 31)", f1190, 0, 512},
  {"512:_mm512_srli_epi32(_mm512_srai_epi16(x, 15), 31)", f1191, 0, 512},
  {"512:_mm512_srli_epi32(_mm512_slli_epi32(x, 1), 31)", f1192, 0, 512},
  {"512:_mm512_srli_epi32(_mm512_srli_epi32(x, 1), 31)", f1193, 0, 512},
  {"512:_mm512_srli_epi32(_mm512_srai_epi32(x, 1), 31)", f1194, 0, 512},
  {"512:_mm512_srli_epi32(_mm512_slli_epi32(x, 31), 31)", f1195, 0, 512},
  {"512:_mm512_srli_epi32(_mm512_srli_epi32(x, 31), 31)", f1196, 0, 512},
  {"512:_mm512_srli_epi32(_mm512_srai_epi32(x, 31), 31)", f1197, 0, 512},
  {"512:_mm512_srli_epi32(_mm512_slli_epi64(x, 1), 31)", f1198, 0, 512},
  {"512:_mm512_srli_epi32(_mm512_srli_epi64(x, 1), 31)", f1199, 0, 512},
};
extern const int size_86 = 1200;
