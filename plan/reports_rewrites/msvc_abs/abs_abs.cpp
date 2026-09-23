// abs(abs(x)) on packed integers: MSVC /O2 folds two consecutive pabs* intrinsics into a no-op.
#include <immintrin.h>
#include <cstdio>
#include <cstdint>

#if defined(_MSC_VER)
#define NOINLINE __declspec(noinline)
#else
#define NOINLINE __attribute__((noinline))
#endif

NOINLINE void abs1_256(const int32_t* in, int32_t* out) {
    __m256i v = _mm256_loadu_si256((const __m256i*)in);
    _mm256_storeu_si256((__m256i*)out, _mm256_abs_epi32(v));
}
NOINLINE void abs2_256(const int32_t* in, int32_t* out) {
    __m256i v = _mm256_loadu_si256((const __m256i*)in);
    _mm256_storeu_si256((__m256i*)out, _mm256_abs_epi32(_mm256_abs_epi32(v)));
}
NOINLINE void abs3_256(const int32_t* in, int32_t* out) {
    __m256i v = _mm256_loadu_si256((const __m256i*)in);
    _mm256_storeu_si256((__m256i*)out, _mm256_abs_epi32(_mm256_abs_epi32(_mm256_abs_epi32(v))));
}
NOINLINE void abs2_128(const int32_t* in, int32_t* out) {
    __m128i v = _mm_loadu_si128((const __m128i*)in);
    _mm_storeu_si128((__m128i*)out, _mm_abs_epi32(_mm_abs_epi32(v)));
}
NOINLINE void abs2_256_i8(const int8_t* in, int8_t* out) {
    __m256i v = _mm256_loadu_si256((const __m256i*)in);
    _mm256_storeu_si256((__m256i*)out, _mm256_abs_epi8(_mm256_abs_epi8(v)));
}
#ifdef __AVX512F__
NOINLINE void abs2_512(const int32_t* in, int32_t* out) {
    __m512i v = _mm512_loadu_si512(in);
    _mm512_storeu_si512(out, _mm512_abs_epi32(_mm512_abs_epi32(v)));
}
#endif

static void show(const char* name, const int32_t* o, int n) {
    std::printf("%-28s", name);
    for (int i = 0; i < n; ++i) std::printf(" %d", o[i]);
    std::printf("\n");
}

int main() {
    int32_t in[16], out[16];
    for (int i = 0; i < 16; ++i) in[i] = i - 8;
    show("input", in, 8);
    abs1_256(in, out); show("abs            (256)", out, 8);
    abs2_256(in, out); show("abs(abs)       (256)", out, 8);
    abs3_256(in, out); show("abs(abs(abs))  (256)", out, 8);
    abs2_128(in, out); show("abs(abs)       (128)", out, 4);
#ifdef __AVX512F__
    abs2_512(in, out); show("abs(abs)       (512)", out, 8);
#endif
    int8_t in8[32], out8[32];
    for (int i = 0; i < 32; ++i) in8[i] = (int8_t)(i - 8);
    abs2_256_i8(in8, out8);
    std::printf("%-28s", "abs(abs) int8  (256)");
    for (int i = 0; i < 8; ++i) std::printf(" %d", out8[i]);
    std::printf("\n");
    return 0;
}
