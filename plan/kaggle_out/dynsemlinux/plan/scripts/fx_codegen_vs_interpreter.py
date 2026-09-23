"""11.1  torch.fx: the generated Python source versus the node semantics (Interpreter).

An FX graph has two executable meanings: `torch.fx.Interpreter` walks the nodes, `GraphModule.forward` runs Python source
that the code generator prints from them.  #197894 (`operator.pow(-2, x)` printed as `-2 ** x`) and the parameter-named-
`nan` shadowing show that the printed source can mean something else.  This tool builds many small graphs directly
(no tracing, no C++ compiler) and compares, for every graph,

    Interpreter.run(*args)   vs   gm(*args)   vs   the graph after  exec-round-trip of gm.code / deepcopy / pickle

Axes: every `operator.*` function FX pretty-prints (and the in-place ones) x literal operands in either position
(negative ints/floats, inf, nan, -0.0, big ints, complex, bool, None, nested tuples / lists / dicts / slices / Ellipsis,
dtypes, devices, memory formats, strings with quotes and newlines); placeholder names that collide with names the
generated code needs; keyword arguments; default arguments; *args / **kwargs placeholders; call_method / getattr chains.

    python scripts/fx_codegen_vs_interpreter.py            # prints a summary, writes results/fx_codegen/cases.jsonl
"""
import copy
import itertools
import json
import math
import operator
import os
import pickle
import sys

import torch
import torch.fx

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
OUT = os.path.join(ROOT, "results", "fx_codegen")

NUM = [-2, -1, 0, 1, 3, -2.5, 2.5, -0.0, 0.0, float("inf"), float("-inf"), float("nan"), 2 ** 70, -(2 ** 70), True, False, 1e-320, -1e300, (1 + 2j), (-1 - 2j), complex(0, -1)]
BINARY = ["add", "sub", "mul", "truediv", "floordiv", "mod", "pow", "lshift", "rshift", "and_", "or_", "xor", "matmul", "eq", "ne", "lt", "le", "gt", "ge", "getitem",
          "iadd", "isub", "imul", "itruediv", "ifloordiv", "imod", "ipow", "ilshift", "irshift", "iand", "ior", "ixor"]
UNARY = ["neg", "pos", "invert", "not_", "abs", "index", "truth"]
PH_NAMES = ["x", "inf", "nan", "math", "operator", "device", "NoneType", "fx_pytree", "pytree", "builtins", "typing", "int", "float", "None_", "lambda_", "_", "__", "x_1", "getitem", "add", "self_", "cls", "input", "type", "id", "len", "sum", "max"]
OBJ = [None, Ellipsis, slice(None, -1), slice(-3, None, -1), (1, -2), [1, (-2, 3.5)], {"a": -1, "b": (float("inf"), None)}, torch.float16, torch.device("cpu"), torch.channels_last,
       torch.strided, "it's", 'say "hi"\n', "a\\b", b"bytes", range(-3, 3), frozenset([1]), math.pi, -math.e, torch.Size([2, 3]), torch.finfo(torch.float32).min]


def same(a, b):
    if isinstance(a, torch.Tensor) and isinstance(b, torch.Tensor):
        return a.dtype == b.dtype and a.shape == b.shape and torch.equal(torch.nan_to_num(a.to(torch.complex128) if a.is_complex() else a.double(), nan=1234.5),
                                                                          torch.nan_to_num(b.to(torch.complex128) if b.is_complex() else b.double(), nan=1234.5)) \
            and (a.is_complex() or torch.equal(torch.signbit(a.double()), torch.signbit(b.double())))
    if isinstance(a, (tuple, list)) and isinstance(b, (tuple, list)):
        return type(a) is type(b) and len(a) == len(b) and all(same(x, y) for x, y in zip(a, b))
    if isinstance(a, dict) and isinstance(b, dict):
        return a.keys() == b.keys() and all(same(a[k], b[k]) for k in a)
    if isinstance(a, float) and isinstance(b, float):
        return (a != a and b != b) or (a == b and math.copysign(1, a) == math.copysign(1, b))
    if isinstance(a, complex) and isinstance(b, complex):
        return (a == b) or (a != a and b != b)
    return type(a) is type(b) and a == b


def outcome(fn):
    try:
        return ("ok", fn())
    except Exception as e:  # noqa: BLE001
        return ("raise", type(e).__name__)


def variants(gm):
    yield "forward", gm
    yield "deepcopy", copy.deepcopy(gm)
    yield "pickle", pickle.loads(pickle.dumps(gm))
    ns = {}
    g2 = torch.fx.GraphModule(gm, copy.deepcopy(gm.graph))           # re-generate the code from a copied graph
    yield "recodegen", g2


def check(name, build, args, records):
    try:
        g = build()
        gm = torch.fx.GraphModule(torch.nn.Module(), g)
    except Exception as e:  # noqa: BLE001
        records.append({"case": name, "verdict": "BUILD_ERROR", "detail": f"{type(e).__name__}: {str(e)[:120]}"})
        return
    ref = outcome(lambda: torch.fx.Interpreter(gm).run(*[copy.deepcopy(a) for a in args]))
    for vname, make in (("forward", lambda: gm), ("deepcopy", lambda: copy.deepcopy(gm)), ("pickle", lambda: pickle.loads(pickle.dumps(gm)))):
        try:
            m = make()
        except Exception as e:  # noqa: BLE001
            records.append({"case": name, "verdict": "VARIANT_ERROR:" + vname, "detail": f"{type(e).__name__}: {str(e)[:120]}"})
            continue
        got = outcome(lambda: m(*[copy.deepcopy(a) for a in args]))
        if ref[0] == "ok" and got[0] == "ok":
            v = "ok" if same(ref[1], got[1]) else "VALUE"
        elif ref[0] == "raise" and got[0] == "raise":
            v = "ok"                                                  # both reject (exception types may differ: SyntaxError vs TypeError ...)
        else:
            v = "INTERP_OK_CODE_RAISES" if ref[0] == "ok" else "INTERP_RAISES_CODE_OK"
        if v != "ok":
            records.append({"case": name, "variant": vname, "verdict": v, "interpreter": repr(ref[1])[:160], "generated": repr(got[1])[:160], "code": gm.code.strip()[:400]})
            return
    records.append({"case": name, "verdict": "ok"})


def cases():
    T = torch.tensor([1.5, -2.0, 3.0])
    TI = torch.tensor([1, -2, 3])
    # 1. operator with a literal on the left / right / both sides
    for opn in BINARY:
        op = getattr(operator, opn)
        for lit in NUM:
            for side in ("L", "R"):
                def build(op=op, lit=lit, side=side):
                    g = torch.fx.Graph(); x = g.placeholder("x")
                    g.output(g.call_function(op, (lit, x) if side == "L" else (x, lit))); return g
                for aname, arg in (("f", T), ("i", TI), ("py", 3), ("pyf", -2.5)):
                    if _explodes(opn, lit, arg):
                        continue
                    yield f"bin:{opn}:{side}:{lit!r}:{aname}", build, (arg,)
        for a, b in itertools.product(NUM[:12], repeat=2):              # both operands literal: pure constant folding of the printed text
            if _explodes(opn, a, b):
                continue
            def build2(op=op, a=a, b=b):
                g = torch.fx.Graph(); g.placeholder("x"); g.output(g.call_function(op, (a, b))); return g
            yield f"const:{opn}:{a!r}:{b!r}", build2, (T,)
    for opn in UNARY:
        op = getattr(operator, opn)
        for lit in NUM:
            def buildu(op=op, lit=lit):
                g = torch.fx.Graph(); g.placeholder("x"); g.output(g.call_function(op, (lit,))); return g
            yield f"un:{opn}:{lit!r}", buildu, (T,)
        def buildux(op=op):
            g = torch.fx.Graph(); x = g.placeholder("x"); g.output(g.call_function(op, (x,))); return g
        for aname, arg in (("f", T), ("i", TI), ("py", -3)):
            yield f"un:{opn}:x:{aname}", buildux, (arg,)
    # 2. nested operator results as operands (precedence between two pretty-printed operators cannot arise: operands are names) -- but literals inside containers can
    for obj in OBJ + NUM:
        def buildo(obj=obj):
            g = torch.fx.Graph(); x = g.placeholder("x")
            g.output(g.call_function(_ident, (x, obj), {"kw": obj})); return g
        yield f"obj:{obj!r}"[:80], buildo, (T,)
        def buildl(obj=obj):
            g = torch.fx.Graph(); x = g.placeholder("x")
            g.output(g.call_function(_ident, (x, [obj, (obj, {"k": obj})]))); return g
        yield f"objnest:{obj!r}"[:80], buildl, (T,)
    # 3. placeholder names x constants the generated code prints as bare names
    for ph in PH_NAMES:
        for const in (float("inf"), float("nan"), float("-inf"), None, torch.device("cpu"), torch.float32, math.pi):
            def buildp(ph=ph, const=const):
                g = torch.fx.Graph(); x = g.placeholder(ph)
                g.output(g.call_function(_ident, (x, const))); return g
            yield f"ph:{ph}:{const!r}", buildp, (T,)
        def buildm(ph=ph):
            g = torch.fx.Graph(); x = g.placeholder(ph)
            g.output(g.call_method("clamp", (x,), {"min": -float("inf"), "max": float("inf")})); return g
        yield f"ph:{ph}:method", buildm, (T,)
    # 4. defaults, *args, **kwargs, keyword-only style names
    for default in NUM[:14] + OBJ[:12]:
        def buildd(default=default):
            g = torch.fx.Graph(); x = g.placeholder("x"); y = g.placeholder("y", default_value=default)
            g.output(g.call_function(_ident, (x, y))); return g
        yield f"default:{default!r}"[:80], buildd, (T,)
    def buildstar():
        g = torch.fx.Graph(); a = g.placeholder("*args"); k = g.placeholder("**kwargs")
        g.output(g.call_function(_ident, (a, k))); return g
    yield "star", buildstar, (T, T)
    # 5. call_method / getattr targets and kwargs named like keywords or with odd characters
    for meth in ("add", "__add__", "__rpow__", "__rsub__", "__rtruediv__", "__rfloordiv__", "__rmod__", "__neg__", "__getitem__", "__invert__"):
        for lit in (-2, -2.5, float("inf"), 2):
            def buildcm(meth=meth, lit=lit):
                g = torch.fx.Graph(); x = g.placeholder("x")
                g.output(g.call_method(meth, (x, lit) if meth not in ("__neg__", "__invert__") else (x,))); return g
            for aname, arg in (("f", T), ("i", TI)):
                yield f"method:{meth}:{lit!r}:{aname}", buildcm, (arg,)
    for kw in ("class", "lambda", "in", "from", "None", "True", "async", "match", "inf", "nan", "self", "a b", "a-b", "1x", ""):
        def buildkw(kw=kw):
            g = torch.fx.Graph(); x = g.placeholder("x")
            g.output(g.call_function(_kw, (x,), {kw: 1})); return g
        yield f"kwarg:{kw!r}", buildkw, (T,)


def _explodes(opn, a, b):
    """pow / shift with astronomically large Python ints never returns (2 ** 2 ** 70); keep those out."""
    big = lambda v: isinstance(v, int) and not isinstance(v, bool) and abs(v) > 64
    return opn in ("pow", "ipow", "lshift", "ilshift") and (big(a) or big(b))


def _ident(*a, **k):
    return (a, tuple(sorted(k.items(), key=lambda kv: kv[0])))


def _kw(x, **k):
    return tuple(sorted(k.items()))


torch.fx.wrap("_ident")
torch.fx.wrap("_kw")


def main():
    os.makedirs(OUT, exist_ok=True)
    records = []
    n = 0
    for name, build, args in cases():
        n += 1
        check(name, build, args, records)
    path = os.path.join(OUT, f"cases_{torch.__version__.split('+')[0]}.jsonl")
    with open(path, "w", encoding="utf-8") as f:
        for r in records:
            f.write(json.dumps(r, ensure_ascii=False) + "\n")
    from collections import Counter
    c = Counter(r["verdict"] for r in records)
    print("torch", torch.__version__, "|", n, "graphs |", dict(c))
    fam = {}
    for r in records:
        if r["verdict"] != "ok":
            key = (r["verdict"], r["case"].split(":")[0], r["case"].split(":")[1] if ":" in r["case"] else "")
            fam.setdefault(key, []).append(r)
    for key, rs in sorted(fam.items(), key=lambda kv: (kv[0][0], -len(kv[1]))):
        r = rs[0]
        print(f"\n[{key[0]}] {key[1]}:{key[2]}  x{len(rs)}   e.g. {r['case']}")
        print("     interpreter:", r.get("interpreter", r.get("detail")), "\n     generated  :", r.get("generated", ""))
        if r.get("code"):
            print("     " + r["code"].splitlines()[1].strip() if len(r["code"].splitlines()) > 1 else "")


if __name__ == "__main__":
    main()
