"""One-off: extend cxx_intrinsic_algebra_diff.py with vocabulary v2 (shuffles, packs, unpack, select idioms, int<->float round trips)."""
import os
p = os.path.join(os.path.dirname(os.path.abspath(__file__)), "cxx_intrinsic_algebra_diff.py")
s = open(p, encoding="utf-8").read()
assert "vocabulary v2" not in s

INT_V2 = '''    if not big:                                   # vocabulary v2: data movement, narrowing, select idioms, float round trips
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
'''
s = s.replace("    bi[\"mullo_epi16\"] = (16, lambda a, b: f\"{P}mullo_epi16({a}, {b})\")\n", INT_V2 + "    bi[\"mullo_epi16\"] = (16, lambda a, b: f\"{P}mullo_epi16({a}, {b})\")\n", 1)

FP_V2 = '''    if not big:                                   # vocabulary v2
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
            for imm in (0x5, 0xA, 0x3):
                un[f"permute_{imm:x}"] = lambda a, imm=imm: f"{P}permute_pd({a}, 0x{imm:x})"
'''
s = s.replace("    nan = \"std::numeric_limits<float>::quiet_NaN()\" if t == \"ps\"", FP_V2 + "    nan = \"std::numeric_limits<float>::quiet_NaN()\" if t == \"ps\"", 1)
s = s.replace("over 128/256/512-bit integer and float vectors,", "over 128/256/512-bit integer and float vectors (vocabulary v2 adds shuffles, packs, unpack, horizontal ops,\nblend/select idioms and int<->float round trips for 128/256 bits),", 1)
open(p, "w", encoding="utf-8").write(s)
print("patched")
