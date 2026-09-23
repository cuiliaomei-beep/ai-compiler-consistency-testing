// x + (+0.0) must turn -0.0 into +0.0 under /fp:precise; MSVC /O1,/O2 removes the vector addition.
#include <immintrin.h>
#include <cstdio>
#include <cmath>

#if defined(_MSC_VER)
#define NOINLINE __declspec(noinline)
#else
#define NOINLINE __attribute__((noinline))
#endif

NOINLINE float  scalar_f(float x)   { return x + 0.0f; }
NOINLINE double scalar_d(double x)  { return x + 0.0; }
NOINLINE void sse_ps(const float* in, float* out)  { _mm_storeu_ps(out, _mm_add_ps(_mm_loadu_ps(in), _mm_setzero_ps())); }
NOINLINE void sse_ps_set1(const float* in, float* out)  { _mm_storeu_ps(out, _mm_add_ps(_mm_loadu_ps(in), _mm_set1_ps(0.0f))); }
NOINLINE void avx_ps(const float* in, float* out)  { _mm256_storeu_ps(out, _mm256_add_ps(_mm256_loadu_ps(in), _mm256_setzero_ps())); }
NOINLINE void avx_pd(const double* in, double* out) { _mm256_storeu_pd(out, _mm256_add_pd(_mm256_loadu_pd(in), _mm256_setzero_pd())); }
NOINLINE void avx_ps_rev(const float* in, float* out)  { _mm256_storeu_ps(out, _mm256_add_ps(_mm256_setzero_ps(), _mm256_loadu_ps(in))); }
NOINLINE void avx_ps_sub(const float* in, float* out)  { _mm256_storeu_ps(out, _mm256_sub_ps(_mm256_loadu_ps(in), _mm256_set1_ps(-0.0f))); }

static const char* sz(double v) { return std::signbit(v) ? "-0" : "+0"; }

int main() {
    float in[8] = {-0.0f, -0.0f, -0.0f, -0.0f, -0.0f, -0.0f, -0.0f, -0.0f}, out[8];
    double ind[4] = {-0.0, -0.0, -0.0, -0.0}, outd[4];
    volatile float vf = -0.0f; volatile double vd = -0.0;
    std::printf("scalar float   -0.0f + 0.0f        = %s\n", sz(scalar_f(vf)));
    std::printf("scalar double  -0.0  + 0.0         = %s\n", sz(scalar_d(vd)));
    sse_ps(in, out);       std::printf("_mm_add_ps(x, _mm_setzero_ps())       = %s\n", sz(out[0]));
    sse_ps_set1(in, out);  std::printf("_mm_add_ps(x, _mm_set1_ps(0.0f))      = %s\n", sz(out[0]));
    avx_ps(in, out);       std::printf("_mm256_add_ps(x, _mm256_setzero_ps()) = %s\n", sz(out[0]));
    avx_ps_rev(in, out);   std::printf("_mm256_add_ps(_mm256_setzero_ps(), x) = %s\n", sz(out[0]));
    avx_pd(ind, outd);     std::printf("_mm256_add_pd(x, _mm256_setzero_pd()) = %s\n", sz(outd[0]));
    avx_ps_sub(in, out);   std::printf("_mm256_sub_ps(x, set1(-0.0f))         = %s\n", sz(out[0]));
    return 0;
}
