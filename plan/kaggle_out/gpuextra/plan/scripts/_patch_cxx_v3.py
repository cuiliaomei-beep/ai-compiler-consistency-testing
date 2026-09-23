"""One-off: vocabulary v3 for cxx_intrinsic_algebra_diff.py -- FMA family with neutral constants, AVX-512 mask selects / masked arithmetic."""
import os
p = os.path.join(os.path.dirname(os.path.abspath(__file__)), "cxx_intrinsic_algebra_diff.py")
s = open(p, encoding="utf-8").read()
assert "vocabulary v3" not in s
EXTRAS = '''

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
'''
s = s.replace("\n\ndef compose(un, bi, consts_for, compatible):", EXTRAS + "\n\ndef compose(un, bi, consts_for, compatible):", 1)
s = s.replace("            fns += [(kind, bits, e) for e in compose(un, bi, lambda nb: consts, lambda a, b: True)]\n",
              "            fns += [(kind, bits, e) for e in compose(un, bi, lambda nb: consts, lambda a, b: True)]\n        fns += [(kind, bits, e) for kind, e in extras(w)]\n", 1)
s = s.replace("blend/select idioms and int<->float round trips for 128/256 bits),", "blend/select idioms and int<->float round trips for 128/256 bits; vocabulary v3 adds the FMA family with neutral\nconstants and AVX-512 mask selects / masked arithmetic),", 1)
open(p, "w", encoding="utf-8").write(s)
print("patched")
