"""10.13 C++ toolchain layer: optimisation-level differential over compositions of SIMD intrinsics.

Inductor's CPU backend hands `at::vec::Vectorized<T>` code (thin wrappers over x86 intrinsics) to the host C++
compiler.  0920issues/16 showed that the host compiler can be the faulty layer: MSVC folds abs(abs(x)) to x.
This tool tests that layer directly.  It generates small functions that compose intrinsics in the shapes an
algebraic simplifier looks for

    U(U(x))  U(U(U(x)))  U(B(x,y))  B(U(x),y)  B(U(x),U(y))  B(x,U(x))  B(U(x),x)
    B(x,x)   B1(B2(x,y),y)  B1(x,B2(x,y))  B1(B2(x,y),x)  B1(y,B2(x,y))
    B(x,c)   B(c,x)  B(B(x,c1),c2)                       (c: 0, 1, -1, MIN, MAX / +-0, +-1, inf, nan)

over 128/256/512-bit integer and float vectors (vocabulary v2 adds shuffles, packs, unpack, horizontal ops,
blend/select idioms and int<->float round trips for 128/256 bits; vocabulary v3 adds the FMA family with neutral
constants and AVX-512 mask selects / masked arithmetic), builds the same sources unoptimised (reference) and optimised,
runs both on all pairs of 16 edge values per lane width, and reports every function whose result differs.
Floating-point results are compared twice: bit-exact, and with NaNs canonicalised ("nan-bits" class).

    python scripts/cxx_intrinsic_algebra_diff.py --compiler msvc            # cl /Od vs /O1, /O2, /O2 /arch:AVX2, /O2 /arch:AVX512
    python scripts/cxx_intrinsic_algebra_diff.py --compiler gcc             # g++ -O0 vs -O1/-O2/-O3   (also: clang)
    python scripts/cxx_intrinsic_algebra_diff.py --report
Results: results/cxx_algebra/<compiler>/{src/, *.exe, out_<cfg>.txt, diffs.jsonl}
"""
import argparse
import itertools
import json
import os
import subprocess
import sys
import time

PLAN = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, PLAN)
OUT = os.path.join(PLAN, "results", "cxx_algebra")
PER_TU = 1200


# ---------------------------------------------------------------- vocabulary
class W:
    def __init__(self, bits):
        self.bits = bits
        self.P = {128: "_mm_", 256: "_mm256_", 512: "_mm512_"}[bits]
        self.si = {128: "si128", 256: "si256", 512: "si512"}[bits]
        self.ti = f"__m{bits}i"
        self.tps = f"__m{bits}"
        self.tpd = f"__m{bits}d"

    def set1(self, lane, v):
        cast = {8: "(char)", 16: "(short)", 32: "(int)", 64: "(long long)"}[lane]
        fn = {8: "set1_epi8", 16: "set1_epi16", 32: "set1_epi32", 64: "set1_epi64" if self.bits == 512 else "set1_epi64x"}[lane]
        suffix = "ull" if lane == 64 else "u"
        return f"{self.P}{fn}({cast}0x{v & (2 ** lane - 1):x}{suffix})"


def int_ops(w):
    P, si, big = w.P, w.si, w.bits == 512
    zero = f"{P}setzero_{si}()"
    un, bi = {}, {}
    for L in (8, 16, 32) + ((64,) if big else ()):
        un[f"abs_epi{L}"] = (L, lambda a, L=L: f"{P}abs_epi{L}({a})")
    for L in (8, 16, 32, 64):
        un[f"neg{L}"] = (L, lambda a, L=L: f"{P}sub_epi{L}({zero}, {a})")
        bi[f"add_epi{L}"] = (L, lambda a, b, L=L: f"{P}add_epi{L}({a}, {b})")
        bi[f"sub_epi{L}"] = (L, lambda a, b, L=L: f"{P}sub_epi{L}({a}, {b})")
    un["not"] = (0, lambda a: f"{P}xor_{si}({a}, {w.set1(8, 0xff)})")
    for L in (16, 32, 64):
        for k in (1, L - 1):
            un[f"slli_epi{L}_{k}"] = (L, lambda a, L=L, k=k: f"{P}slli_epi{L}({a}, {k})")
            un[f"srli_epi{L}_{k}"] = (L, lambda a, L=L, k=k: f"{P}srli_epi{L}({a}, {k})")
            if L != 64 or big:
                un[f"srai_epi{L}_{k}"] = (L, lambda a, L=L, k=k: f"{P}srai_epi{L}({a}, {k})")
    for L in (8, 16):
        for s in ("epi", "epu"):
            bi[f"adds_{s}{L}"] = (L, lambda a, b, L=L, s=s: f"{P}adds_{s}{L}({a}, {b})")
            bi[f"subs_{s}{L}"] = (L, lambda a, b, L=L, s=s: f"{P}subs_{s}{L}({a}, {b})")
        bi[f"avg_epu{L}"] = (L, lambda a, b, L=L: f"{P}avg_epu{L}({a}, {b})")
    for L in (8, 16, 32) + ((64,) if big else ()):
        for s in ("epi", "epu"):
            for m in ("min", "max"):
                bi[f"{m}_{s}{L}"] = (L, lambda a, b, L=L, s=s, m=m: f"{P}{m}_{s}{L}({a}, {b})")
    for name in ("and", "or", "xor", "andnot"):
        bi[name] = (0, lambda a, b, name=name: f"{P}{name}_{si}({a}, {b})")
    if not big:                                   # the 512-bit compares return masks
        for L in (8, 16, 32, 64):
            bi[f"cmpeq_epi{L}"] = (L, lambda a, b, L=L: f"{P}cmpeq_epi{L}({a}, {b})")
            bi[f"cmpgt_epi{L}"] = (L, lambda a, b, L=L: f"{P}cmpgt_epi{L}({a}, {b})")
        for L in (8, 16, 32):
            bi[f"sign_epi{L}"] = (L, lambda a, b, L=L: f"{P}sign_epi{L}({a}, {b})")
    if not big:                                   # vocabulary v2: data movement, narrowing, select idioms, float round trips
        for imm in (0x1B, 0x39, 0x93, 0x4E):
            un[f"shuffle_epi32_{imm:02x}"] = (32, lambda a, imm=imm: f"{P}shuffle_epi32({a}, 0x{imm:02x})")
            if w.bits == 256:
                un[f"permute4x64_{imm:02x}"] = (64, lambda a, imm=imm: f"{P}permute4x64_epi64({a}, 0x{imm:02x})")
        un["bslli_1"] = (0, lambda a: f"{P}bslli_{'si128' if w.bits == 128 else 'epi128'}({a}, 1)")
        un["bsrli_1"] = (0, lambda a: f"{P}bsrli_{'si128' if w.bits == 128 else 'epi128'}({a}, 1)")
        un["i2f2i_trunc"] = (32, lambda a: f"{P}cvttps_epi32({P}cvtepi32_ps({a}))")
        un["i2f2i_round"] = (32, lambda a: f"{P}cvtps_epi32({P}cvtepi32_ps({a}))")
        for name, L in (("packs_epi16", 16), ("packus_epi16", 16), ("packs_epi32", 32), ("packus_epi32", 32),
                        ("hadd_epi16", 16), ("hadd_epi32", 32), ("hsub_epi16", 16), ("hsub_epi32", 32), ("hadds_epi16", 16),
                        ("madd_epi16", 16), ("maddubs_epi16", 8), ("mul_epi32", 32), ("mul_epu32", 32), ("shuffle_epi8", 8),
                        ("unpacklo_epi8", 8), ("unpackhi_epi8", 8), ("unpacklo_epi16", 16), ("unpackhi_epi16", 16),
                        ("unpacklo_epi32", 32), ("unpackhi_epi32", 32), ("unpacklo_epi64", 64), ("unpackhi_epi64", 64)):
            bi[name] = (L, lambda a, b, name=name: f"{P}{name}({a}, {b})")
        for L in (8, 16, 32, 64):
            for cmp in ("cmpgt", "cmpeq"):
                m = lambda a, b, L=L, cmp=cmp: f"{P}{cmp}_epi{L}({a}, {b})"
                bi[f"blend_ab_{cmp}{L}"] = (L, lambda a, b, m=m: f"{P}blendv_epi8({a}, {b}, {m(a, b)})")
                bi[f"blend_ba_{cmp}{L}"] = (L, lambda a, b, m=m: f"{P}blendv_epi8({b}, {a}, {m(a, b)})")
                bi[f"selbits_{cmp}{L}"] = (L, lambda a, b, m=m: f"{P}or_{si}({P}and_{si}({m(a, b)}, {a}), {P}andnot_{si}({m(a, b)}, {b}))")
    bi["mullo_epi16"] = (16, lambda a, b: f"{P}mullo_epi16({a}, {b})")
    bi["mullo_epi32"] = (32, lambda a, b: f"{P}mullo_epi32({a}, {b})")
    bi["mulhi_epi16"] = (16, lambda a, b: f"{P}mulhi_epi16({a}, {b})")
    bi["mulhi_epu16"] = (16, lambda a, b: f"{P}mulhi_epu16({a}, {b})")
    for L in (32, 64):
        bi[f"sllv_epi{L}"] = (L, lambda a, b, L=L: f"{P}sllv_epi{L}({a}, {b})")
        bi[f"srlv_epi{L}"] = (L, lambda a, b, L=L: f"{P}srlv_epi{L}({a}, {b})")
    bi["srav_epi32"] = (32, lambda a, b: f"{P}srav_epi32({a}, {b})")
    consts = {L: [w.set1(L, v) for v in (0, 1, -1, 2 ** (L - 1) - 1, 2 ** (L - 1))] for L in (8, 16, 32, 64)}
    consts[0] = consts[32]
    return un, bi, consts


def fp_ops(w, t):
    P, big = w.P, w.bits == 512
    lit = (lambda v: v + "f") if t == "ps" else (lambda v: v)
    set1 = lambda v: f"{P}set1_{t}({v})"
    zero, mzero = f"{P}setzero_{t}()", set1(lit("-0.0"))
    un = {"sqrt": lambda a: f"{P}sqrt_{t}({a})",
          "neg_xor": lambda a: f"{P}xor_{t}({a}, {mzero})",
          "abs_andnot": lambda a: f"{P}andnot_{t}({mzero}, {a})",
          "zero_minus": lambda a: f"{P}sub_{t}({zero}, {a})",
          "times_m1": lambda a: f"{P}mul_{t}({a}, {set1(lit('-1.0'))})"}
    if big:
        for name, imm in (("floor", 1), ("ceil", 2), ("round", 0)):
            un[name] = lambda a, imm=imm: f"{P}roundscale_{t}({a}, {imm} | _MM_FROUND_NO_EXC)"
    else:
        un["floor"] = lambda a: f"{P}floor_{t}({a})"
        un["ceil"] = lambda a: f"{P}ceil_{t}({a})"
        un["round"] = lambda a: f"{P}round_{t}({a}, _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC)"
    bi = {}
    for name in ("add", "sub", "mul", "div", "min", "max", "and", "or", "xor", "andnot"):
        bi[name] = lambda a, b, name=name: f"{P}{name}_{t}({a}, {b})"
    if not big:
        for pred in ("_CMP_EQ_OQ", "_CMP_LT_OS", "_CMP_LE_OS", "_CMP_NEQ_UQ", "_CMP_UNORD_Q", "_CMP_NLT_US", "_CMP_GT_OS"):
            bi["cmp" + pred[4:]] = lambda a, b, pred=pred: f"{P}cmp_{t}({a}, {b}, {pred})"
    if not big:                                   # vocabulary v2
        for pred in ("_CMP_LT_OS", "_CMP_LE_OS", "_CMP_GT_OS", "_CMP_NLT_US", "_CMP_EQ_OQ", "_CMP_UNORD_Q"):
            m = lambda a, b, pred=pred: f"{P}cmp_{t}({a}, {b}, {pred})"
            bi["blend_ab" + pred[4:]] = lambda a, b, m=m: f"{P}blendv_{t}({a}, {b}, {m(a, b)})"
            bi["blend_ba" + pred[4:]] = lambda a, b, m=m: f"{P}blendv_{t}({b}, {a}, {m(a, b)})"
            bi["selbits" + pred[4:]] = lambda a, b, m=m: f"{P}or_{t}({P}and_{t}({m(a, b)}, {a}), {P}andnot_{t}({m(a, b)}, {b}))"
        for name in ("unpacklo", "unpackhi", "hadd", "hsub"):
            bi[name] = lambda a, b, name=name: f"{P}{name}_{t}({a}, {b})"
        if t == "ps":
            for imm in (0x1B, 0x39, 0x93, 0x4E):
                un[f"permute_{imm:02x}"] = lambda a, imm=imm: f"{P}permute_ps({a}, 0x{imm:02x})"
                bi[f"shuffle_{imm:02x}"] = lambda a, b, imm=imm: f"{P}shuffle_ps({a}, {b}, 0x{imm:02x})"
            un["f2i2f_trunc"] = lambda a: f"{P}cvtepi32_ps({P}cvttps_epi32({a}))"
            un["f2i2f_round"] = lambda a: f"{P}cvtepi32_ps({P}cvtps_epi32({a}))"
            un["movehdup"] = lambda a: f"{P}movehdup_ps({a})"
        else:
            for imm in ((0x1, 0x2, 0x3) if w.bits == 128 else (0x5, 0xA, 0x3)):   # _mm_permute_pd takes a 2-bit immediate (clang rejects more)
                un[f"permute_{imm:x}"] = lambda a, imm=imm: f"{P}permute_pd({a}, 0x{imm:x})"
    nan = "std::numeric_limits<float>::quiet_NaN()" if t == "ps" else "std::numeric_limits<double>::quiet_NaN()"
    inf = "std::numeric_limits<float>::infinity()" if t == "ps" else "std::numeric_limits<double>::infinity()"
    consts = [zero, mzero, set1(lit("1.0")), set1(lit("-1.0")), set1(inf), set1(nan)]
    return un, bi, consts


def extras(w):
    """vocabulary v3: expressions that do not go through the cross product.  [(kind, expr)]"""
    P, out = w.P, []
    for kind, t in ((1, "ps"), (2, "pd")):
        un, _, consts = fp_ops(w, t)
        exprs = []
        for op in ("fmadd", "fmsub", "fnmadd", "fnmsub"):
            for c in consts:
                exprs += [f"{P}{op}_{t}(x, y, {c})", f"{P}{op}_{t}(x, {c}, y)", f"{P}{op}_{t}({c}, x, y)"]
            exprs += [f"{P}{op}_{t}(x, y, x)", f"{P}{op}_{t}(x, x, y)", f"{P}{op}_{t}(x, y, {P}mul_{t}(x, y))"]
        if w.bits == 512:
            for pred in ("_CMP_LT_OS", "_CMP_LE_OS", "_CMP_GT_OS", "_CMP_GE_OS", "_CMP_NLT_US", "_CMP_NLE_US", "_CMP_EQ_OQ", "_CMP_NEQ_UQ", "_CMP_UNORD_Q"):
                k = f"{P}cmp_{t}_mask(x, y, {pred})"
                exprs += [f"{P}mask_blend_{t}({k}, x, y)", f"{P}mask_blend_{t}({k}, y, x)", f"{P}mask_add_{t}(x, {k}, x, y)",
                          f"{P}maskz_sub_{t}({k}, x, y)", f"{P}mask_mul_{t}(y, {k}, x, x)", f"{P}mask_sqrt_{t}(x, {k}, y)"]
        else:
            for pred in ("_CMP_GE_OS", "_CMP_NLE_US", "_CMP_NGT_US", "_CMP_LE_OQ", "_CMP_GE_OQ", "_CMP_LT_OQ"):
                k = f"{P}cmp_{t}(x, y, {pred})"
                exprs += [f"{P}blendv_{t}(x, y, {k})", f"{P}blendv_{t}(y, x, {k})"]
        out += [(kind, e) for e in exprs] + [(kind, f(e)) for e in exprs for f in un.values()]
    if w.bits == 512:
        exprs = []
        for L in (8, 16, 32, 64):
            for cmp in ("cmpgt", "cmpeq", "cmple", "cmplt", "cmpge", "cmpneq"):
                for sg in ("epi", "epu"):
                    k = f"{P}{cmp}_{sg}{L}_mask(x, y)"
                    exprs += [f"{P}mask_blend_epi{L}({k}, x, y)", f"{P}mask_blend_epi{L}({k}, y, x)", f"{P}mask_add_epi{L}(x, {k}, x, y)",
                              f"{P}maskz_sub_epi{L}({k}, x, y)", f"{P}mask_abs_epi{L}(y, {k}, x)"]
        iu, _, _ = int_ops(w)
        out += [(0, e) for e in exprs] + [(0, f[1](e)) for e in exprs for f in iu.values()]
    return out


def compose(un, bi, consts_for, compatible):
    """Yield C expressions over x, y."""
    U, B = list(un.items()), list(bi.items())
    for _, f in U:
        yield f("x")
    for _, g in B:
        yield g("x", "y")
    for (_, f), (_, g) in itertools.product(U, U):
        yield f(g("x"))
    for _, f in U:
        yield f(f(f("x")))
    for (nu, f), (nb, g) in itertools.product(U, B):
        if not compatible(nu, nb):
            continue
        yield f(g("x", "y"))
        yield g(f("x"), "y")
        yield g("x", f("y"))
        yield g(f("x"), f("y"))
        yield g("x", f("x"))
        yield g(f("x"), "x")
    for nb, g in B:
        yield g("x", "x")
        cs = consts_for(nb)
        for c in cs:
            yield g("x", c)
            yield g(c, "x")
        for c1, c2 in itertools.product(cs, cs):
            yield g(g("x", c1), c2)
    for (n1, g1), (n2, g2) in itertools.product(B, B):
        if not compatible(n1, n2):
            continue
        yield g1(g2("x", "y"), "y")
        yield g1("x", g2("x", "y"))
        yield g1(g2("x", "y"), "x")
        yield g1("y", g2("x", "y"))


def all_functions(widths):
    """[(kind, bits, expr)]  kind: 0 int, 1 ps, 2 pd."""
    fns = []
    for bits in widths:
        w = W(bits)
        un, bi, consts = int_ops(w)
        lane = {**{k: v[0] for k, v in un.items()}, **{k: v[0] for k, v in bi.items()}}
        un1, bi1 = {k: v[1] for k, v in un.items()}, {k: v[1] for k, v in bi.items()}
        comp = lambda a, b: lane[a] == lane[b] or lane[a] == 0 or lane[b] == 0
        fns += [(0, bits, e) for e in compose(un1, bi1, lambda nb: consts[lane[nb]], comp)]
        for kind, t in ((1, "ps"), (2, "pd")):
            un, bi, consts = fp_ops(w, t)
            fns += [(kind, bits, e) for e in compose(un, bi, lambda nb: consts, lambda a, b: True)]
        fns += [(kind, bits, e) for kind, e in extras(w)]
    seen, out = set(), []
    for f in fns:
        if f not in seen:
            seen.add(f)
            out.append(f)
    return out


# ---------------------------------------------------------------- C++ generation
COMMON_H = r'''#pragma once
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
'''

MAIN_CPP = r'''#include "common.h"
#include <cstdlib>
%(externs)s
static const Entry* tables[] = {%(tables)s};
static const int sizes[] = {%(sizes)s};

static const uint64_t I8[16]  = {0x00,0x01,0x7f,0x80,0xff,0xfe,0x81,0x02,0x40,0xc0,0x7e,0x10,0x55,0xaa,0x0f,0xf0};
static const uint64_t I16[16] = {0x0000,0x0001,0x7fff,0x8000,0xffff,0xfffe,0x8001,0x0002,0x00ff,0xff00,0x0100,0x7ffe,0x5555,0xaaaa,0x0010,0x4000};
static const uint64_t I32[16] = {0x00000000,0x00000001,0x7fffffff,0x80000000,0xffffffff,0xfffffffe,0x80000001,0x00000002,0x0000ffff,0xffff0000,0x00010000,0x7ffffffe,0x55555555,0xaaaaaaaa,0x00000020,0x0000001f};
static const uint64_t I64[16] = {0x0ull,0x1ull,0x7fffffffffffffffull,0x8000000000000000ull,0xffffffffffffffffull,0xfffffffffffffffeull,0x8000000000000001ull,0x2ull,0xffffffffull,0xffffffff00000000ull,0x100000000ull,0x7ffffffffffffffeull,0x5555555555555555ull,0xaaaaaaaaaaaaaaaaull,0x40ull,0x3full};

static void fill_int(unsigned char* buf, int lane, int r) {
    const uint64_t* v = lane == 8 ? I8 : lane == 16 ? I16 : lane == 32 ? I32 : I64;
    int nb = lane / 8;
    for (int i = 0; i < 64 / nb; ++i) std::memcpy(buf + i * nb, &v[(i + r) %% 16], nb);
}
template <class T> static void fill_fp(unsigned char* buf, int r) {
    const T inf = std::numeric_limits<T>::infinity(), nan = std::numeric_limits<T>::quiet_NaN();
    const T v[16] = {T(0), -T(0), T(1), T(-1), inf, -inf, nan, std::numeric_limits<T>::denorm_min(),
                     -std::numeric_limits<T>::denorm_min(), std::numeric_limits<T>::max(), -std::numeric_limits<T>::max(),
                     std::numeric_limits<T>::min(), T(0.5), T(-2.5), T(3), T(1e-3)};
    for (int i = 0; i < int(64 / sizeof(T)); ++i) std::memcpy(buf + i * sizeof(T), &v[(i + r) %% 16], sizeof(T));
}
static void canon(unsigned char* o, int kind, int nbytes) {
    if (kind == 1) for (int i = 0; i < nbytes; i += 4) { uint32_t u; std::memcpy(&u, o + i, 4); if ((u & 0x7f800000u) == 0x7f800000u && (u & 0x007fffffu)) { u = 0x7fc00000u; std::memcpy(o + i, &u, 4); } }
    if (kind == 2) for (int i = 0; i < nbytes; i += 8) { uint64_t u; std::memcpy(&u, o + i, 8); if ((u & 0x7ff0000000000000ull) == 0x7ff0000000000000ull && (u & 0x000fffffffffffffull)) { u = 0x7ff8000000000000ull; std::memcpy(o + i, &u, 8); } }
}
static void fnv(uint64_t& h, const unsigned char* p, int n) { for (int i = 0; i < n; ++i) { h ^= p[i]; h *= 1099511628211ull; } }
static void hex(const char* tag, const unsigned char* p, int n) { std::printf("  %%s", tag); for (int i = 0; i < n; ++i) std::printf("%%02x", p[i]); std::printf("\n"); }

int main(int argc, char** argv) {
    long dump = argc > 1 ? std::atol(argv[1]) : -1;
    alignas(64) unsigned char x[64], y[64], o[64];
    long idx = 0;
    for (size_t t = 0; t < sizeof(sizes) / sizeof(sizes[0]); ++t)
        for (int k = 0; k < sizes[t]; ++k, ++idx) {
            const Entry& e = tables[t][k];
            if (dump >= 0 && idx != dump) continue;
            uint64_t h_raw = 1469598103934665603ull, h_canon = h_raw;
            int nbytes = e.bits / 8;
            int nl = e.kind == 0 ? 4 : 1;
            for (int li = 0; li < nl; ++li)
                for (int r1 = 0; r1 < 16; ++r1)
                    for (int r2 = 0; r2 < 16; ++r2) {
                        if (e.kind == 0) { int lane = 8 << li; fill_int(x, lane, r1); fill_int(y, lane, r2); }
                        else if (e.kind == 1) { fill_fp<float>(x, r1); fill_fp<float>(y, r2); }
                        else { fill_fp<double>(x, r1); fill_fp<double>(y, r2); }
                        std::memset(o, 0, 64);
                        e.fn(x, y, o);
                        fnv(h_raw, o, nbytes);
                        if (dump >= 0) { std::printf("in lane=%%d r1=%%d r2=%%d\n", e.kind == 0 ? (8 << li) : 0, r1, r2); hex("x ", x, nbytes); hex("y ", y, nbytes); hex("o ", o, nbytes); }
                        canon(o, e.kind, nbytes);
                        fnv(h_canon, o, nbytes);
                    }
            if (dump < 0) std::printf("%%ld\t%%016llx\t%%016llx\t%%s\n", idx, (unsigned long long)h_raw, (unsigned long long)h_canon, e.name);
        }
    return 0;
}
'''


def generate(src, widths):
    os.makedirs(src, exist_ok=True)
    fns = all_functions(widths)
    open(os.path.join(src, "common.h"), "w").write(COMMON_H)
    ntu = (len(fns) + PER_TU - 1) // PER_TU
    for t in range(ntu):
        chunk = fns[t * PER_TU:(t + 1) * PER_TU]
        lines = ['#include "common.h"']
        for i, (kind, bits, expr) in enumerate(chunk):
            w = W(bits)
            if kind == 0:
                ty, load, store = w.ti, (f"{w.P}loadu_{w.si}((const {w.ti}*)%s)" if bits != 512 else "_mm512_loadu_si512(%s)"), (f"{w.P}storeu_{w.si}(({w.ti}*)po, r)" if bits != 512 else "_mm512_storeu_si512(po, r)")
            else:
                t_, c = ("ps", "float") if kind == 1 else ("pd", "double")
                ty, load, store = (w.tps if kind == 1 else w.tpd), f"{w.P}loadu_{t_}((const {c}*)%s)", f"{w.P}storeu_{t_}(({c}*)po, r)"
            lines.append(f"static NOINLINE void f{i}(const void* px, const void* py, void* po) {{ const {ty} x = {load % 'px'}; const {ty} y = {load % 'py'}; (void)y; const {ty} r = {expr}; {store}; }}")
        lines.append(f"extern const Entry table_{t}[] = {{")
        for i, (kind, bits, expr) in enumerate(chunk):
            lines.append(f'  {{"{bits}:{expr}", f{i}, {kind}, {bits}}},')
        lines.append("};")
        lines.append(f"extern const int size_{t} = {len(chunk)};")
        open(os.path.join(src, f"tu_{t}.cpp"), "w").write("\n".join(lines) + "\n")
    open(os.path.join(src, "main.cpp"), "w").write(MAIN_CPP % {
        "externs": "\n".join(f"extern const Entry table_{t}[]; extern const int size_{t};" for t in range(ntu)),
        "tables": ", ".join(f"table_{t}" for t in range(ntu)),
        "sizes": ", ".join(f"size_{t}" for t in range(ntu))})
    return len(fns), ntu


# ---------------------------------------------------------------- build / run / compare
CONFIGS = {
    "msvc": [("Od", "/Od"), ("O1", "/O1"), ("O2", "/O2"), ("O2_avx2", "/O2 /arch:AVX2"), ("O2_avx512", "/O2 /arch:AVX512")],
    "gcc": [("O0", "-O0"), ("O1", "-O1"), ("O2", "-O2"), ("O3", "-O3")],
    "clang": [("O0", "-O0"), ("O1", "-O1"), ("O2", "-O2"), ("O3", "-O3")],
}


def build(compiler, src, exe, flags, ntu, widths=(128, 256, 512)):
    files = ["main.cpp"] + [f"tu_{t}.cpp" for t in range(ntu)]
    if compiler == "msvc":
        objdir = exe + "_obj"
        os.makedirs(objdir, exist_ok=True)
        cmd = f'cl /nologo /EHsc /MP /bigobj {flags} {" ".join(files)} /Fo"{objdir}\\\\" /Fe"{exe}"'
    else:
        cxx = "g++" if compiler == "gcc" else "clang++"
        isa = "-mavx2 -mfma" + (" -mavx512f -mavx512bw -mavx512dq -mavx512vl" if 512 in widths else "")   # EVEX code would SIGILL on a CPU without AVX-512
        cmd = f'{cxx} -std=c++17 {flags} -ffp-contract=off {isa} {" ".join(files)} -o "{exe}"'
    t0 = time.time()
    r = subprocess.run(cmd, cwd=src, shell=True, capture_output=True, text=True, encoding="mbcs" if os.name == "nt" else "utf-8", errors="replace")
    if r.returncode:
        print("BUILD FAILED", cmd, (r.stdout + r.stderr)[-3000:])
        sys.exit(1)
    print(f"built {os.path.basename(exe)} ({flags}) in {time.time() - t0:.0f}s", flush=True)


def run(exe, *args):
    r = subprocess.run([exe, *args], capture_output=True, text=True)
    if r.returncode:
        print(f"{os.path.basename(exe)} exited with {r.returncode} after {len(r.stdout.splitlines())} lines", flush=True)
    return r.stdout


def parse(text):
    rows = {}
    for line in text.splitlines():
        p = line.split("\t", 3)
        if len(p) == 4:
            rows[int(p[0])] = (p[1], p[2], p[3])
    return rows


def first_diff(ref_exe, exe, idx):
    a, b = run(ref_exe, str(idx)).splitlines(), run(exe, str(idx)).splitlines()
    for i in range(0, min(len(a), len(b)), 4):
        if a[i:i + 4] != b[i:i + 4]:
            return {"input": a[i], "x": a[i + 1].split()[-1], "y": a[i + 2].split()[-1], "ref": a[i + 3].split()[-1], "opt": b[i + 3].split()[-1]}
    return None


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--compiler", default="msvc", choices=list(CONFIGS))
    ap.add_argument("--widths", default="128,256,512")
    ap.add_argument("--report", action="store_true")
    a = ap.parse_args()
    if a.report:
        for comp in CONFIGS:
            p = os.path.join(OUT, comp, "diffs.jsonl")
            if os.path.exists(p):
                rows = [json.loads(l) for l in open(p, encoding="utf-8")]
                print(f"== {comp}: {len(rows)} differing (function, config) pairs")
                for r in rows[:80]:
                    print(f"[{r['class']}] {r['config']}: {r['name']}\n      {r['first']}")
        return
    if a.compiler == "msvc":
        from tcc.compat import ensure_msvc_env
        ensure_msvc_env()
    widths = [int(x) for x in a.widths.split(",")]
    root = os.path.join(OUT, a.compiler)
    src = os.path.join(root, "src")
    n, ntu = generate(src, widths)
    print(f"{n} functions in {ntu} translation units", flush=True)
    ext = ".exe" if os.name == "nt" else ""
    outs, exes = {}, {}
    for tag, flags in CONFIGS[a.compiler]:
        exes[tag] = os.path.join(root, f"algebra_{tag}{ext}")
        build(a.compiler, src, exes[tag], flags, ntu, widths)
        text = run(exes[tag])
        open(os.path.join(root, f"out_{tag}.txt"), "w").write(text)
        outs[tag] = parse(text)
        assert len(outs[tag]) == n, (tag, len(outs[tag]), n)
    ref_tag = CONFIGS[a.compiler][0][0]
    ref = outs[ref_tag]
    diffs = []
    for tag, rows in outs.items():
        if tag == ref_tag:
            continue
        for idx, (raw, can, name) in rows.items():
            if (raw, can) != ref[idx][:2]:
                cls = "value" if can != ref[idx][1] else "nan-bits"
                diffs.append({"config": tag, "idx": idx, "name": name, "class": cls, "first": first_diff(exes[ref_tag], exes[tag], idx)})
    with open(os.path.join(root, "diffs.jsonl"), "w", encoding="utf-8") as f:
        for d in diffs:
            f.write(json.dumps(d) + "\n")
    by = {}
    for d in diffs:
        by[(d["config"], d["class"])] = by.get((d["config"], d["class"]), 0) + 1
    print(f"{n} functions; differing vs {ref_tag}: {by}")


if __name__ == "__main__":
    main()
