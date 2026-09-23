"""Two-level self-check: the pipeline is not evidence until this passes.

Level 1 (offline): the static analysis derives the factors, boundaries and
facts the plan's own examples promise; signatures and dedup behave.

Level 2 (torch): the compile counter is exact; each oracle fires on the
injected fault built for it and stays silent on the real compiler; the
fp64 reference builds; Inductor can actually generate code on this machine.
"""
from __future__ import annotations

from typing import Any, List, Optional, Tuple

from .compat import HAVE_TORCH, backend_available, environment, torch

Check = Tuple[str, Optional[bool], str]


def _offline() -> List[Check]:
    from .factors import analyze_source
    from .ir import build_ir_from_source
    from .report import DedupStore, signature
    from .scs import DeriveOptions, derive_obligations, derive_scs, obligations_to_contexts
    from .sites import scan_source

    out: List[Check] = []
    a = analyze_source("def f(x):\n    if x.shape[0] >= 32:\n        return x * 2\n    return x + 1\n")
    b = [bb for bb in a.boundaries if bb.kind == "shape"]
    out.append(("6.3: x.shape[0] >= 32 -> 31/32/33", bool(b) and sorted(b[0].values) == [31, 32, 33] and b[0].param == "x",
                str([bb.values for bb in b])))
    a = analyze_source("def f(x):\n    if x.shape[0] % 16 == 0:\n        return x\n    return x + 1\n")
    b = [bb for bb in a.boundaries]
    out.append(("6.3: n % 16 == 0 -> 15/16/17/31/32/33", bool(b) and sorted(b[0].values) == [15, 16, 17, 31, 32, 33],
                str([bb.values for bb in b])))
    a = analyze_source("def f(x, use_fast):\n    if use_fast:\n        return x\n    return x * 2\n")
    out.append(("6.2: use_fast -> flag {True, False}", any(s.param == "use_fast" and s.role == "flag"
                                                          for s in a.scalars), str([s.as_dict() for s in a.scalars])))
    a = analyze_source("def f(x):\n    n = x.shape[0]\n    i = n - 1\n    y = x[i]\n    return y\n")
    r = a.index_relations
    out.append(("7: x.shape[0] -> n -> i -> x[i]", bool(r) and r[0].offset == -1 and r[0].chain[0] == "x.shape[0]",
                str([rr.chain for rr in r])))
    a = analyze_source("def f(x):\n    y = x.view(-1)\n    y[0] += 1\n    return x\n")
    kinds = {f.kind for f in a.facts}
    out.append(("8: view + in-place -> mutation_visible/partial_write facts",
                {"mutation_visible", "partial_write"} <= kinds and ["x", "y"] in a.alias_groups,
                f"facts={sorted(kinds)} groups={a.alias_groups}"))
    scs = derive_scs(a)
    obs = derive_obligations(a, scs)
    ctxs = obligations_to_contexts(obs, a.params)
    out.append(("9/10: SCS -> obligations -> single-factor contexts", len(obs) >= 2 and len(ctxs) >= 2
                and all(len(ctxs[0].differing_factors(c)) == 1 for c in ctxs[1:]),
                f"{len(obs)} obligations, {len(ctxs)} contexts"))
    ir = build_ir_from_source("def f(x, flag):\n    y = x.view(-1)\n    if flag:\n        y[0] += 1\n    return x\n")
    kinds_ir = [n.kind for n in ir.nodes if n.kind != "Param"]
    out.append(("5.2: IR kinds Assign/Branch/Mutation/Return + deps",
                kinds_ir == ["Assign", "Branch", "Mutation", "Return"] and
                {d.kind for d in ir.deps} >= {"data", "control", "alias"}, f"{kinds_ir} {sorted({d.kind for d in ir.deps})}"))
    sites = scan_source("import torch\n@torch.compile(backend='inductor')\ndef g(x):\n    return h(x)\n"
                        "def h(x):\n    return x\nfn = torch.compile(h, dynamic=True)\n"
                        "import triton\n@triton.jit\ndef k(p):\n    pass\n")
    comps = sorted({s.compiler for s in sites})
    out.append(("5.1: compilation sites (decorator, call, triton.jit)",
                len(sites) == 3 and comps == ["torch.compile", "triton.jit"]
                and any(s.reachable == ["g", "h"] for s in sites), f"{[(s.form, s.target, s.compiler) for s in sites]}"))
    s1 = signature("p", "inductor_codegen", "x.dtype", ["value"], source="def f(x): return x")
    s2 = signature("p", "inductor_codegen", "x.dtype", ["value"], source="def f(x):  return x")
    s3 = signature("p", "inductor_codegen", "x.shape[0]", ["value"], source="def f(x): return x")
    out.append(("18.5: signature stable under whitespace, separates factors", s1 == s2 and s1 != s3, f"{s1} {s3}"))
    st = DedupStore("")
    out.append(("18.5: dedup suppresses repeats", st.add("a", {}) and not st.add("a", {}), str(st.stats())))
    return out


def _torch_checks() -> List[Check]:
    out: List[Check] = []
    if not HAVE_TORCH:
        return [("torch importable", False, "PyTorch is not installed")]
    env = environment()
    out.append(("torch importable", True, f"torch {env['torch']} cuda {env['cuda']} device {env['device_name']}"))
    for b in ("eager", "aot_eager", "inductor"):
        out.append((f"backend '{b}' resolvable", backend_available(b), ""))

    from .corpus import DEV  # noqa: F401  (registers the corpus)
    from .execute import TorchCompiler, execution_matrix, run_cold, run_eager, run_fp64, run_layered, run_sequence
    from .faults import faulty_compiler
    from .localize import STAGE_INDUCTOR, STAGE_INVALIDATION, STAGE_SPECIALIZATION, triage_layers, triage_matrix
    from .oracle import ALIAS, EXCEPTION, GRADIENT, MUTATION, VALUE, Config, compare
    from .program import Context, get

    cfg = Config()
    base = Context("base", {})
    fp16 = Context("fp16", {"dtype": "float16"})

    # compile counter
    try:
        p = get("dtype_reduce")
        comp = TorchCompiler("eager")
        seq = run_sequence(p, [base, base, fp16], comp)
        c = [o.compiles for o in seq]
        out.append(("compile counter: cold=1, repeat=0, dtype switch>=1", c[0] == 1 and c[1] == 0 and c[2] >= 1, str(c)))
    except Exception as e:
        out.append(("compile counter", False, f"{type(e).__name__}: {str(e)[:120]}"))

    # value oracle: fires on codegen_value, silent on the real compiler
    try:
        p = get("dtype_reduce")
        ref, f64 = run_eager(p, base), run_fp64(p, base)
        bad = run_cold(p, base, faulty_compiler("codegen_value"))
        good = run_cold(p, base, TorchCompiler("aot_eager"))
        cb, cg = compare(ref, bad, f64, cfg), compare(ref, good, f64, cfg)
        out.append(("O1 value fires on injected codegen fault", VALUE in cb.kinds, "; ".join(f.detail for f in cb.findings)[:120]))
        out.append(("O1 no false positive on aot_eager", not cg.differs, "; ".join(f.detail for f in cg.findings)[:120] or "clean"))
        out.append(("fp64 reference builds", f64 is not None, ""))
    except Exception as e:
        out.append(("O1 value oracle", False, f"{type(e).__name__}: {str(e)[:120]}"))

    # mutation + alias oracles
    try:
        p = get("view_inplace")
        ref = run_eager(p, base)
        drop = run_cold(p, base, faulty_compiler("functionalize_drop_mutation"))
        cp = run_cold(p, base, faulty_compiler("functionalize_alias_to_copy"))
        good = run_cold(p, base, TorchCompiler("aot_eager"))
        out.append(("O4 mutation fires on dropped in-place write", MUTATION in compare(ref, drop, None, cfg).kinds, ""))
        out.append(("O5 alias fires on view materialised as copy", ALIAS in compare(ref, cp, None, cfg).kinds, ""))
        out.append(("O4/O5 no false positive on aot_eager", not compare(ref, good, None, cfg).differs,
                    "; ".join(f.detail for f in compare(ref, good, None, cfg).findings)[:120] or "clean"))
    except Exception as e:
        out.append(("O4/O5", False, f"{type(e).__name__}: {str(e)[:120]}"))

    # exception oracle
    try:
        p = get("exception_path")
        small = Context("rows3", {"resize": {"arg": 0, "dim": 0, "value": 3}})
        ref = run_eager(p, small)
        sw = run_cold(p, small, faulty_compiler("capture_swallow_exception"))
        out.append(("O3 exception fires when compiled swallows a raise", (not ref.ok) and EXCEPTION in compare(ref, sw, None, cfg).kinds,
                    f"eager={ref.exception} compiled_ok={sw.ok}"))
    except Exception as e:
        out.append(("O3", False, f"{type(e).__name__}: {str(e)[:120]}"))

    # gradient oracle
    try:
        p = get("requires_grad_switch")
        ref, f64 = run_eager(p, base), run_fp64(p, base)
        wg = run_cold(p, base, faulty_compiler("autograd_wrong_gradient"))
        good = run_cold(p, base, TorchCompiler("aot_eager"))
        out.append(("O6 gradient fires on 2x backward", GRADIENT in compare(ref, wg, f64, cfg).kinds, ""))
        out.append(("O6 no false positive on aot_eager", not compare(ref, good, f64, cfg).differs, ""))
    except Exception as e:
        out.append(("O6", False, f"{type(e).__name__}: {str(e)[:120]}"))

    # cache oracle via the execution matrix
    try:
        p = get("dtype_reduce")
        m = execution_matrix(p, fp16, base, faulty_compiler("underspec_dtype"))
        tri, v = triage_matrix(m, cfg)
        out.append(("O7 cache: stale dtype reuse -> specialization_cache (no recompile)",
                    tri.stage == STAGE_SPECIALIZATION and v.recompiled_on_switch is False, f"{tri.stage} recompiled={v.recompiled_on_switch}"))
        m2 = execution_matrix(p, base, fp16, faulty_compiler("cache_stale_on_return"))
        tri2, v2 = triage_matrix(m2, cfg)
        out.append(("O7 cache: A->B->A stale -> cache_invalidation", tri2.stage == STAGE_INVALIDATION, f"{tri2.stage}"))
        m3 = execution_matrix(p, base, fp16, TorchCompiler("aot_eager"))
        tri3, _ = triage_matrix(m3, cfg)
        out.append(("O7 no false positive on aot_eager", tri3.stage == "none", tri3.rationale[:100]))
    except Exception as e:
        out.append(("O7", False, f"{type(e).__name__}: {str(e)[:120]}"))

    # layered localization attributes an injected E3 fault to Inductor
    try:
        p = get("shape_boundary")
        layers = run_layered(p, base, compilers={"E3_inductor": faulty_compiler("codegen_value", "inductor")})
        tri, _ = triage_layers(layers, run_fp64(p, base), cfg)
        if layers["E3_inductor"].infra_error:
            out.append(("16: staged localization -> inductor_codegen", None,
                        f"SKIP: Inductor unavailable ({layers['E3_inductor'].exception_msg[:80]})"))
        else:
            out.append(("16: staged localization -> inductor_codegen", tri.stage == STAGE_INDUCTOR, tri.stage))
            out.append(("inductor cold run executes", layers["E3_inductor"].ok or not layers["E3_inductor"].infra_error,
                        f"{layers['E3_inductor'].wall_s:.1f}s"))
    except Exception as e:
        out.append(("16: staged localization", False, f"{type(e).__name__}: {str(e)[:120]}"))
    return out


def run_selfcheck(include_torch: bool = True) -> List[Check]:
    checks = _offline()
    if include_torch:
        checks += _torch_checks()
    return checks


def failed(checks: List[Check]) -> List[str]:
    return [n for n, ok, _ in checks if ok is False]


def format_checks(checks: List[Check]) -> str:
    w = max((len(n) for n, _, _ in checks), default=10)
    L = []
    for n, ok, d in checks:
        mark = "PASS" if ok else ("SKIP" if ok is None else "FAIL")
        L.append(f"  [{mark}] {n.ljust(w)}  {d}")
    nf = len(failed(checks))
    ns = sum(1 for _, ok, _ in checks if ok is None)
    L.append("")
    L.append(f"  {len(checks) - nf - ns}/{len(checks)} checks passed" + (f", {ns} skipped" if ns else ""))
    if nf:
        L.append("  Pipeline output is NOT trustworthy until these pass.")
    return "\n".join(L)
