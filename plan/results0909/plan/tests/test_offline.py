"""Offline tests (no torch needed for most): run with ``python tests/test_offline.py``."""
from __future__ import annotations

import os
import sys
import tempfile

sys.path.insert(0, os.path.dirname(os.path.dirname(os.path.abspath(__file__))))

from tcc.factors import analyze_source  # noqa: E402
from tcc.generate import context_switch_sequences  # noqa: E402
from tcc.ir import build_ir_from_source  # noqa: E402
from tcc.localize import STAGE_NONE, Triage  # noqa: E402
from tcc.program import Context, single_factor_pairs  # noqa: E402
from tcc.report import DedupStore, FailureRecord, render_issue, sanitize_text, signature, write_report  # noqa: E402
from tcc.scs import (DeriveOptions, combination_contexts, derive_obligations, derive_scs, obligations_to_contexts,  # noqa: E402
                     obligations_to_yaml)
from tcc.sites import scan_source  # noqa: E402

CHECKS = []


def check(name, cond, detail=""):
    CHECKS.append((name, bool(cond), detail))


def test_sites():
    src = ("import torch\nimport triton\n"
           "def helper(x):\n    return x + G\nG = 1\n"
           "@torch.compile(backend='inductor', dynamic=True)\ndef f(x):\n    return helper(x)\n"
           "def wrap(m):\n    return torch.compile(m, mode='max-autotune')\n"
           "@triton.jit\ndef k(ptr, BLOCK: tl.constexpr):\n    pass\n"
           "scripted = torch.jit.script(helper)\n")
    sites = scan_source(src, "m.py")
    forms = sorted((s.form, s.compiler, s.target) for s in sites)
    check("sites: 4 boundaries incl. wrapper + jit.script", len(sites) == 4, str(forms))
    f = next(s for s in sites if s.target == "f")
    check("sites: reachable functions and external state", f.reachable == ["f", "helper"] and f.external_state == ["G"],
          f"{f.reachable} {f.external_state}")
    check("sites: options captured", f.options.get("dynamic") == "True", str(f.options))


def test_ir():
    ir = build_ir_from_source("def f(x, n):\n    y = x.view(-1)\n    for i in range(n):\n        y[i] += 1\n"
                              "    if n > 2:\n        raise ValueError()\n    return x\n")
    kinds = [nd.kind for nd in ir.nodes]
    check("ir: kinds", kinds == ["Param", "Assign", "Loop", "Mutation", "Branch", "Raise", "Return"], str(kinds))
    check("ir: mutation depends on view (data) and view aliases param (alias)",
          any(d.kind == "alias" for d in ir.deps) and any(d.kind == "data" and d.name == "y" for d in ir.deps))
    mut = next(nd for nd in ir.nodes if nd.kind == "Mutation")
    check("ir: mutation reaches observable", ir.reaches_observable(mut.id))
    ret = next(nd for nd in ir.nodes if nd.kind == "Return")
    back = ir.backward_slice([ret.id])
    check("ir: backward slice of return includes the view and the mutation", {1, 3} <= back, str(sorted(back)))


def test_factors():
    a = analyze_source("def f(x, flag, mode=None):\n    n = x.shape[0]\n    if flag and n % 16 == 0:\n"
                       "        z = x[:, ::2]\n        z.copy_(x[:, 1::2])\n    if mode is None:\n"
                       "        return x\n    i = n - 1\n    return x[i]\n")
    b = [bb for bb in a.boundaries if bb.kind == "shape"]
    check("factors: n % 16 resolves back to x.shape[0]", bool(b) and b[0].param == "x" and b[0].dim == 0 and 16 in b[0].values,
          str([bb.as_dict() for bb in a.boundaries]))
    check("factors: predicate group flag+x", ["flag", "x"] in a.predicate_groups or ["x", "flag"] in a.predicate_groups,
          str(a.predicate_groups))
    kinds = {f.kind for f in a.facts}
    check("factors: conditional partial write facts", {"mutation_visible", "partial_write", "conditional_mutation"} <= kinds, str(kinds))
    check("factors: none check", any(s.role == "none_check" and s.param == "mode" for s in a.scalars))
    check("factors: index relation n-1", any(r.offset == -1 for r in a.index_relations))
    a2 = analyze_source("def g(x):\n    n = x.shape[0]\n    idx = torch.arange(n - 1)\n    return x.index_select(0, idx)\n")
    check("factors: index chain through torch.arange", any(r.op == "index_select" for r in a2.index_relations),
          str([r.chain for r in a2.index_relations]))


def test_scs_and_plan():
    a = analyze_source("def f(x, use_fast):\n    if use_fast and x.shape[0] >= 32:\n        return x.sum()\n    return x.mean()\n")
    scs = derive_scs(a)
    check("scs: entries", "x.shape[0]" in scs.entries() and "use_fast" in scs.entries(), str(scs.entries()))
    obs = derive_obligations(a, scs)
    ctxs = obligations_to_contexts(obs, a.params, Context("base", {}))
    check("plan: single-factor contexts", all(len(ctxs[0].differing_factors(c)) == 1 for c in ctxs[1:]))
    combos = combination_contexts(a, obs, a.params)
    check("plan: 2x2 combination contexts exist", len(combos) >= 4, str([c.name for c in combos]))
    pairs = single_factor_pairs(ctxs)
    seqs = context_switch_sequences(pairs)
    check("plan: sequences A->B, B->A, A->B->A", any(len(s) == 3 for s in seqs) and any(len(s) == 2 for s in seqs))
    y = obligations_to_yaml(obs)
    check("obligations: yaml has site/factor/values/oracle", all(k in y for k in ("site:", "factor:", "values:", "oracle:")))
    obs_ex = derive_obligations(a, derive_scs(a, DeriveOptions(scs_prune=False)), DeriveOptions(scs_prune=False))
    check("ablation: no-prune enumerates more obligations", len(obs_ex) > len(obs), f"{len(obs)} -> {len(obs_ex)}")


def test_report():
    tri = Triage("specialization_cache", "high", "why", ["value"], recompiled=False, warm_only=True)
    rec = FailureRecord(signature="abc", program="p", project="pytorch/pytorch", triage=tri, probe="matrix",
                        context={"name": "A", "factors": {"dtype": "float16"}},
                        context_b={"name": "B", "factors": {"dtype": "float32"}}, factor_changed="dtype",
                        controlled={"shape": "unchanged"}, cache={"cold_vs_warm": {"differs": True},
                                                                  "eager_vs_cold": {"differs": False},
                                                                  "eager_vs_warm": {"differs": True},
                                                                  "recompiled_on_switch": False},
                        reruns_agreeing=3, reruns_total=3, reproducer="print(1)\n",
                        expected_text="[1.0]", actual_text="[2.0]")
    rec.env["platform"] = r"C:\Users\someone\secret ghp_abcdefghijklmnopqrstuvwxyz0123"
    md = render_issue(rec)
    for sec in ("## Summary", "## Environment", "## Minimal Reproducer", "## Expected Behavior", "## Actual Behavior",
                "## Trigger Condition", "## Cache / Specialization Evidence", "## Difference", "## Suspected Stage",
                "## Reproducibility"):
        check(f"issue.md has {sec}", sec in md)
    check("issue: trigger line", "dtype: float16 -> float32" in md)
    with tempfile.TemporaryDirectory() as d:
        out = write_report(d, rec)
        files = sorted(os.listdir(out))
        check("report dir: 18.4 files", {"issue.md", "minimal.py", "environment.txt", "expected.txt", "actual.txt",
                                         "execution_trace.json", "semantic_factor.json", "metadata.json"} <= set(files), str(files))
        txt = open(os.path.join(out, "environment.txt"), encoding="utf-8").read()
        check("sanitised: no home path or token", "someone" not in txt and "ghp_" not in txt, txt)
    s1 = signature("pytorch/pytorch", "inductor_codegen", "x.shape[0]=31", ["value"], source="def f(x):\n return x\n")
    s2 = signature("pytorch/pytorch", "inductor_codegen", "x.shape[0]=33", ["value"], source="def f(x):\n    return x\n")
    check("signature: same bug under two boundary values clusters together", s1 == s2, f"{s1} {s2}")
    st = DedupStore("")
    check("dedup", st.add(s1, {}) and not st.add(s2, {}))


def test_exception_canonical():
    from tcc.oracle import canonical_exception
    check("O3: TorchRuntimeError unwraps to RuntimeError",
          canonical_exception("TorchRuntimeError", "RuntimeError when making fake tensor call ...") == "RuntimeError")
    check("O3: plain exception unchanged", canonical_exception("ValueError", "bad") == "ValueError")
    check("O3: inner error wins over the envelope's leading word",
          canonical_exception("TorchRuntimeError", "RuntimeError when making fake tensor call\n  Explanation: ... "
                              "got ValueError('Target size must match')") == "ValueError")
    check("O3: wrapper without a wrapped type stays", canonical_exception("Unsupported", "call_method x") == "Unsupported")


def main() -> int:
    for t in (test_sites, test_ir, test_factors, test_scs_and_plan, test_report, test_exception_canonical):
        try:
            t()
        except Exception as e:  # noqa: BLE001
            CHECKS.append((f"{t.__name__} raised", False, f"{type(e).__name__}: {e}"))
    w = max(len(n) for n, _, _ in CHECKS)
    bad = 0
    for n, ok, d in CHECKS:
        print(f"  [{'PASS' if ok else 'FAIL'}] {n.ljust(w)}  {d if not ok else ''}")
        bad += 0 if ok else 1
    print(f"\n  {len(CHECKS) - bad}/{len(CHECKS)} offline checks passed")
    return 1 if bad else 0


if __name__ == "__main__":
    raise SystemExit(main())
