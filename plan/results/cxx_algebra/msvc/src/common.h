#pragma once
#include <immintrin.h>
#include <cstdint>
#include <cstdio>
#include <cstring>
#include <limits>
#if defined(_MSC_VER)
#define NOINLINE __declspec(noinline)
#else
#define NOINLINE __attribute__((noinline))
#endif
struct Entry { const char* name; void (*fn)(const void*, const void*, void*); int kind; int bits; };
