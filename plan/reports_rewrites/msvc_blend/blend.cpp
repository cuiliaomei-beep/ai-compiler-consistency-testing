// select idiom blendv(x, y, x <= y) followed by another operation: MSVC /O1,/O2 turns it into max/min with the wrong tie/NaN behaviour
#include <immintrin.h>
#include <cstdio>
#include <cmath>
#include <limits>

#if defined(_MSC_VER)
#define NOINLINE __declspec(noinline)
#else
#define NOINLINE __attribute__((noinline))
#endif

NOINLINE void sel_only(const float* px, const float* py, float* po) {
    __m128 x = _mm_loadu_ps(px), y = _mm_loadu_ps(py);
    _mm_storeu_ps(po, _mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LE_OS)));          // (x <= y) ? y : x
}
NOINLINE void sel_then_sqrt(const float* px, const float* py, float* po) {
    __m128 x = _mm_loadu_ps(px), y = _mm_loadu_ps(py);
    _mm_storeu_ps(po, _mm_sqrt_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LE_OS))));
}
NOINLINE void sel_then_neg(const float* px, const float* py, float* po) {
    __m128 x = _mm_loadu_ps(px), y = _mm_loadu_ps(py);
    _mm_storeu_ps(po, _mm_xor_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LE_OS)), _mm_set1_ps(-0.0f)));
}
NOINLINE void sel_lt_then_sqrt(const float* px, const float* py, float* po) {
    __m128 x = _mm_loadu_ps(px), y = _mm_loadu_ps(py);
    _mm_storeu_ps(po, _mm_sqrt_ps(_mm_blendv_ps(x, y, _mm_cmp_ps(x, y, _CMP_LT_OS))));
}

static void show(const char* name, const float* o) {
    std::printf("%-46s", name);
    for (int i = 0; i < 4; ++i) std::printf(" %s%g", std::signbit(o[i]) && o[i] == 0 ? "" : "", o[i]);
    std::printf("\n");
}

int main() {
    const float nan = std::numeric_limits<float>::quiet_NaN();
    float x[4] = {+0.0f, -0.0f, nan, 4.0f}, y[4] = {-0.0f, +0.0f, 9.0f, nan}, o[4];
    std::printf("x = +0 -0 nan 4     y = -0 +0 9 nan\n");
    sel_only(x, y, o);         show("(x<=y)?y:x", o);
    sel_then_sqrt(x, y, o);    show("sqrt((x<=y)?y:x)", o);
    sel_then_neg(x, y, o);     show("-((x<=y)?y:x)", o);
    sel_lt_then_sqrt(x, y, o); show("sqrt((x<y)?y:x)", o);
    return 0;
}
