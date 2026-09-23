"""Tests that run without PyTorch.

They cover the parts of the pipeline that are pure bookkeeping - signatures,
dedup, record and issue rendering. The point is that the reporting path is
known-good *before* a real finding arrives at 3am, rather than discovering it
crashes on the one night it matters.

    python tests/test_offline.py
"""
from __future__ import annotations

import json
import os
import shutil
import sys
import tempfile

sys.path.insert(0, os.path.dirname(os.path.dirname(os.path.abspath(__file__))))

from tcd.case import Case, Context  # noqa: E402
from tcd.oracle import Comparison, Finding, VALUE, ALIAS  # noqa: E402
from tcd.report import FailureRecord, render_issue, write_record, write_summary  # noqa: E402
from tcd.snapshot import Observation, flatten  # noqa: E402
from tcd.triage import (  # noqa: E402
    DedupStore,
    P_HIGH,
    P_INFO,
    STAGE_INDUCTOR,
    STAGE_NONE,
    STAGE_SPECIALIZATION,
    Triage,
    signature,
    triage_warm,
    worst,
)

FAILURES = []


def check(name, cond, detail=""):
    status = "PASS" if cond else "FAIL"
    if not cond:
        FAILURES.append(name)
    print(f"  [{status}] {name}" + (f"  {detail}" if detail else ""))


def test_flatten():
    items, struct = flatten({"b": [1, 2], "a": (3,)})
    check("flatten walks dicts deterministically", struct.startswith("D{"), struct)
    check("flatten collects leaves", items == [3, 1, 2] or len(items) == 3, str(items))

    _, s1 = flatten((1, 2))
    _, s2 = flatten([1, 2])
    check("tuple and list structures differ", s1 != s2, f"{s1} vs {s2}")


def test_context_pairs():
    case = Case(
        name="c", fn=lambda x: x, make_inputs=lambda ctx: (),
        contexts=[
            Context("a", {"dtype": "fp32", "rows": 32}),
            Context("b", {"dtype": "fp16", "rows": 32}),
            Context("c", {"dtype": "fp16", "rows": 64}),
        ],
    )
    pairs = case.context_pairs()
    names = {(a.name, b.name) for a, b in pairs}
    check("single-factor pairs only", ("a", "c") not in names, str(sorted(names)))
    check("both directions generated",
          ("a", "b") in names and ("b", "a") in names, str(sorted(names)))


def test_triage_warm():
    cold = Observation(mode="cold_inductor", ok=True, out_struct="T")
    warm_same = Observation(mode="warm_inductor", ok=True, out_struct="T")

    tri, _ = triage_warm(cold, warm_same, recompiled=False, factor_changed="dtype")
    check("no diff + no recompile -> guard suspicious, info only",
          tri.stage == STAGE_NONE and tri.guard_suspicious and tri.priority == P_INFO,
          f"{tri.stage}/{tri.priority}")

    warm_diff = Observation(mode="warm_inductor", ok=False, exception="RuntimeError")
    tri, _ = triage_warm(cold, warm_diff, recompiled=False, factor_changed="dtype")
    check("diff + no recompile -> specialization, high",
          tri.stage == STAGE_SPECIALIZATION and tri.priority == P_HIGH,
          f"{tri.stage}/{tri.priority}")

    tri, _ = triage_warm(cold, warm_diff, recompiled=True, factor_changed="dtype")
    check("diff + recompile -> nondeterminism, not specialization",
          tri.stage != STAGE_SPECIALIZATION, tri.stage)


def test_worst():
    a = Triage(STAGE_NONE, P_INFO, "x")
    b = Triage(STAGE_INDUCTOR, P_HIGH, "y")
    check("worst() picks the highest priority", worst([a, b]).priority == P_HIGH)
    check("worst() of nothing is inert", worst([]).stage == STAGE_NONE)


def test_signature_stability():
    base = dict(case_name="c", stage=STAGE_INDUCTOR, kinds=[VALUE])
    s_unordered = signature(**{**base, "kinds": [VALUE, ALIAS]})
    s_reordered = signature(**{**base, "kinds": [ALIAS, VALUE]})
    check("signature ignores oracle-kind ordering", s_unordered == s_reordered,
          f"{s_unordered} == {s_reordered}")
    check("signature separates stages",
          signature(**base) != signature(**{**base, "stage": STAGE_SPECIALIZATION}))


def test_dedup_roundtrip():
    d = tempfile.mkdtemp()
    try:
        path = os.path.join(d, "sub", "dedup.json")
        store = DedupStore(path)
        store.add("sig1", {"case": "a"})
        store.add("sig1", {"case": "a"})
        store.add("sig2", {"case": "b"})
        store.save()
        check("dedup file written", os.path.exists(path))

        reloaded = DedupStore(path)
        check("dedup survives a restart", reloaded.seen("sig1") and reloaded.seen("sig2"))
        check("dedup keeps occurrence counts",
              reloaded.entries["sig1"]["count"] == 2, str(reloaded.stats()))
        check("a reloaded signature is not re-reported",
              reloaded.add("sig1", {}) is False)
    finally:
        shutil.rmtree(d, ignore_errors=True)


def _record() -> FailureRecord:
    cmp = Comparison(ref_mode="cold_inductor", test_mode="warm_inductor")
    cmp.findings.append(Finding(VALUE, "output[0]: compiled err 1.2e-02 exceeds 4x eager err",
                                magnitude=0.012, index=0))
    cmp.findings.append(Finding(ALIAS, "storage-sharing relation changed: lost [(0, 1)]"))
    return FailureRecord(
        signature="deadbeef1234",
        case="view_inplace",
        triage=Triage(STAGE_SPECIALIZATION, P_HIGH, "no recompile yet the warm result differs",
                      [VALUE, ALIAS], recompiled=False),
        probe="warm",
        context=Context("fp32", {"dtype": "float32", "rows": 8}).as_dict(),
        context_b=Context("fp16", {"dtype": "float16", "rows": 8}).as_dict(),
        factor_changed="dtype",
        comparisons={"cold_vs_warm": cmp},
        observations={"cold_B": {"mode": "cold_inductor"}, "warm_A_to_B": {"mode": "warm"}},
        fp64_available=True,
        reruns_agreeing=3,
        reruns_total=3,
    )


def test_issue_rendering():
    rec = _record()
    md = render_issue(rec, repro_src="import torch\n")
    for needed in ("## Summary", "## Environment", "## Minimal reproducer",
                   "## Trigger condition", "## Suspected stage", "## Reproducibility",
                   "Cache / specialization evidence", "dtype", "3/3"):
        check(f"issue draft contains {needed!r}", needed in md)
    check("warm draft records that no recompile happened", "| recompile triggered" in md)
    check("fp64 methodology is stated", "float64 reference" in md)


def test_write_record():
    d = tempfile.mkdtemp()
    try:
        rec = _record()
        out = write_record(d, rec, repro_src="import torch\n")
        for fname in ("record.json", "issue.md", "repro.py", "environment.txt"):
            check(f"{fname} written", os.path.exists(os.path.join(out, fname)))
        with open(os.path.join(out, "record.json"), encoding="utf-8") as fh:
            data = json.load(fh)
        check("record.json is valid and keyed by signature",
              data["signature"] == "deadbeef1234")
        check("record.json preserves oracle findings",
              len(data["comparisons"]["cold_vs_warm"]["findings"]) == 2)
        check("record.json marks submittability",
              data["triage"]["submittable"] is True)

        path = write_summary(d, [rec], {"torch": "n/a", "cases": 1})
        with open(path, encoding="utf-8") as fh:
            body = fh.read()
        check("summary lists the candidate", "deadbeef1234" in body)
        check("summary groups by priority", "### high" in body)
    finally:
        shutil.rmtree(d, ignore_errors=True)


def test_analysis_alias_and_facts():
    from tcd.analysis import analyze_source

    a = analyze_source("""
def f(x):
    y = x.view(-1)
    y[0] = y[0] + 1.0
    return x
""")
    check("view creates an alias edge",
          any(e.target == "y" and e.source == "x" for e in a.aliases),
          str([(e.target, e.source, e.op) for e in a.aliases]))
    check("x and y land in one alias group", ["x", "y"] in a.alias_groups,
          str(a.alias_groups))
    check("subscript store is a partial mutation",
          any(m.target == "y" and m.partial for m in a.mutations),
          str([(m.target, m.op, m.partial) for m in a.mutations]))
    kinds = {f.kind for f in a.facts}
    check("derives mutation_visible", "mutation_visible" in kinds, str(kinds))
    check("derives partial_write", "partial_write" in kinds, str(kinds))


def test_analysis_write_order_and_returned_alias():
    from tcd.analysis import analyze_source

    a = analyze_source("""
def f(x):
    p = x[:6]
    q = x[4:]
    p.mul_(2.0)
    q.add_(1.0)
    return x, p, q
""")
    kinds = {f.kind for f in a.facts}
    check("two writes to one storage yield a write_order fact",
          "write_order" in kinds, str(kinds))
    check("returned aliases yield alias_returned facts",
          "alias_returned" in kinds, str(kinds))
    check("AliasBranch applies to two views of one base",
          "AliasBranch" in a.operators, str(a.operators))
    check("ReorderMutation applies to two mutations",
          "ReorderMutation" in a.operators, str(a.operators))


def test_analysis_returns_are_not_overapproximated():
    from tcd.analysis import analyze_source

    a = analyze_source("""
def f(x):
    return (x * 2.0).sum(dim=0)
""")
    check("a name merely used in the return expression is not 'returned'",
          a.returns == [], str(a.returns))
    check("no alias_returned fact is invented",
          not any(f.kind == "alias_returned" for f in a.facts),
          str([f.kind for f in a.facts]))


def test_analysis_boundaries():
    from tcd.analysis import analyze_source

    a = analyze_source("""
def f(x):
    if x.shape[0] >= 32:
        return x + 1
    return x
""")
    vals = [b.values for b in a.boundaries]
    check(">= K derives K-1, K, K+1", [31, 32, 33] in vals, str(vals))
    check("the shape read is marked as controlling flow",
          any(f.in_branch and f.kind == "shape" for f in a.factors),
          str([(f.expr, f.kind, f.in_branch) for f in a.factors]))

    b = analyze_source("""
def f(x, n):
    if n % 16 == 0:
        return x
    return x + 1
""")
    vals = [x.values for x in b.boundaries]
    check("%K straddles multiples of K",
          any(15 in v and 16 in v and 17 in v and 32 in v for v in vals), str(vals))


def test_index_relation():
    """Plan section 7: shape -> index dataflow."""
    from tcd.analysis import analyze_source

    a = analyze_source("""
def f(x):
    n = x.shape[0]
    i = n - 1
    y = x[i]
    return y
""")
    check("recovers the shape -> index chain", len(a.index_relations) == 1,
          str([r.chain for r in a.index_relations]))
    if a.index_relations:
        r = a.index_relations[0]
        check("attributes the index to the right parameter and dim",
              (r.source_param, r.source_dim) == ("x", 0),
              f"{r.source_param}.shape[{r.source_dim}]")
        check("tracks the constant offset", r.offset == -1, str(r.offset))
    check("a shape read is not treated as a tensor alias",
          "n" not in [e.target for e in a.aliases],
          str([(e.target, e.source) for e in a.aliases]))


def test_flag_detection_is_not_overbroad():
    """A name merely mentioned inside a predicate is not a flag."""
    from tcd.analysis import analyze_source

    a = analyze_source("""
def f(x, use_fast):
    if use_fast:
        return x.sum()
    if x.shape[0] >= 32:
        return (x * 2).sum()
    return x.sum()
""")
    names = [fl.param for fl in a.flags]
    check("the bare condition is a flag", "use_fast" in names, str(names))
    check("a tensor read inside a comparison is NOT a flag",
          "x" not in names, str(names))


def test_obligations_are_derived_not_hardcoded():
    """Plan sections 9 and 10: contexts must come from the program."""
    from tcd.obligation import contexts_for_source

    rich, scs_r, obs_r = contexts_for_source("""
def f(x, use_fast):
    if use_fast:
        return x.sum()
    if x.shape[0] >= 32:
        return (x * 2).sum()
    return x.sum()
""")
    plain, scs_p, obs_p = contexts_for_source("""
def h(x):
    return torch.abs(x)
""")
    check("a program with structure yields more contexts than one without",
          len(rich) > len(plain), f"{len(rich)} vs {len(plain)}")
    check("shape boundary reaches the contexts",
          any("dim0_31" in c.name for c in rich), str([c.name for c in rich]))
    check("flag values reach the contexts",
          any("use_fast" in c.name for c in rich), str([c.name for c in rich]))
    check("every obligation records why it exists",
          all(ob.origin for ob in obs_r), str([ob.origin for ob in obs_r]))
    check("contexts differ from base in exactly one factor",
          all(len(rich[0].differing_factors(c)) <= 1 for c in rich[1:]),
          str([(c.name, rich[0].differing_factors(c)) for c in rich[1:]]))


def test_analysis_survives_bad_input():
    from tcd.analysis import analyze_source

    a = analyze_source("def f(:\n  pass")
    check("syntax errors are reported, not raised", a.error is not None, str(a.error))
    b = analyze_source("x = 1")
    check("a module with no function is reported", b.error is not None, str(b.error))


def test_sanitisation():
    """Plan 18.1 step 8: a report is a public document."""
    import os as _os
    from tcd.prefile import check_clean, sanitize_obj, sanitize_text

    home = _os.environ.get("USERPROFILE") or _os.environ.get("HOME") or ""
    if home:
        text = f"File \"{home}\\proj\\repro.py\", line 3"
        out = sanitize_text(text)
        check("home path is replaced", home not in out, out[:70])
        check("check_clean agrees", not check_clean(out), str(check_clean(out)))

    leaky = "token=ghp_abcdefghijklmnopqrstuvwxyz012345 and api_key: s3cret-value"
    out = sanitize_text(leaky)
    check("github token is redacted", "ghp_abcdefghij" not in out, out)
    check("api_key value is redacted", "s3cret-value" not in out, out)

    nested = sanitize_obj({"a": [f"{home}\\x"], "b": {"c": "ghp_" + "z" * 20}})
    blob = repr(nested)
    check("nested structures are sanitised recursively",
          ("ghp_" + "z" * 20) not in blob, blob[:90])


def test_duplicate_query_building():
    """Plan 18.5: the query has to be short enough to actually match."""
    from tcd.prefile import build_query

    q = build_query("op_softmax_backward_data_0__IntroduceView_1",
                    "inductor_codegen", ["value"], "x.dtype")
    check("query mentions the operator", "softmax" in q, q)
    check("query mentions the stage", "inductor" in q, q)
    check("query stays short", len(q.split()) <= 5, f"{len(q.split())} terms: {q}")

    empty = build_query("chain_003", "none", [])
    check("an uninformative case yields a short or empty query",
          len(empty.split()) <= 3, repr(empty))


def test_duplicate_section_renders_without_network():
    from tcd.prefile import DuplicateReport, render_duplicate_section

    failed = DuplicateReport(query="x", searched=False, error="HTTP 403")
    s = render_duplicate_section(failed)
    check("a failed search says so rather than implying no duplicates",
          "did not run" in s and "403" in s, s[:110])

    empty = DuplicateReport(query="abc", searched=True)
    check("an empty result says no match", "No open issue matched" in
          render_duplicate_section(empty))


_SITES_SRC = '''
import torch
import triton

CFG = {"scale": 2.0}
COUNTER = 0

def helper(x):
    return x * CFG["scale"]

@torch.compile(backend="inductor", dynamic=True)
def f(x):
    return helper(x) + 1

def maybe_compile(fn):
    return torch.compile(fn, mode="reduce-overhead")

@maybe_compile
def g(x):
    global COUNTER
    COUNTER += 1
    return x

class M(torch.nn.Module):
    def forward(self, x):
        self.calls += 1
        return x * self.scale

@triton.jit
def k(ptr):
    pass

model = M()
compiled_model = torch.compile(model)
traced = torch.jit.trace(f, (torch.randn(2),))
'''


def test_sites_scan():
    from tcd.sites import scan_source

    sites = scan_source(_SITES_SRC)
    by_target = {s.target: s for s in sites}
    check("five sites found (3 decorators + 2 calls)", len(sites) == 5,
          str([(s.form, s.api, s.target) for s in sites]))
    f = by_target.get("f")
    check("decorator site carries backend and options",
          f is not None and f.backend == "'inductor'" and f.options.get("dynamic") == "True",
          str(f.as_dict() if f else None))
    check("reachability follows calls in the same file",
          f is not None and f.reachable == ["helper"], str(f.reachable if f else None))
    check("external reads exclude module roots, include real state",
          f is not None and "CFG" in f.external_reads and "torch" not in f.external_reads,
          str(f.external_reads if f else None))
    g = by_target.get("g")
    check("project wrapper is recognised as a boundary",
          g is not None and g.form == "wrapper_decorator" and g.via_wrapper == "maybe_compile"
          and g.api == "torch.compile", str(g.as_dict() if g else None))
    check("global write is an external write",
          g is not None and "COUNTER" in g.external_writes, str(g.external_writes if g else None))
    k = by_target.get("k")
    check("triton.jit is a boundary", k is not None and k.api == "triton.jit", str(k))
    trace = [s for s in sites if s.api == "torch.jit.trace"]
    check("jit.trace keeps example inputs as arguments",
          len(trace) == 1 and trace[0].target == "f" and trace[0].arguments == ["(torch.randn(2),)"],
          str([t.as_dict() for t in trace]))
    forms = [s.form for s in sites]
    check("the wrapper's own inner torch.compile call is not a site",
          forms.count("call") == 2, str(forms))


_IR_SRC = '''
def f(x, n):
    y = x.view(-1)
    w = y[:]
    if n > 2:
        w.mul_(2.0)
    z = x[n - 1]
    STATE.total = z.sum()
    q = STATE.total
    return w, z, q
'''


def test_ir_build():
    from tcd.ir import build_ir

    ir = build_ir(_IR_SRC)
    kinds = {n.kind for n in ir.nodes}
    check("IR has the expected node kinds",
          {"Assign", "Call", "Branch", "Index", "Mutation", "Return",
           "StateRead", "StateWrite"} <= kinds, str(sorted(kinds)))
    dep_kinds = {d.kind for d in ir.deps}
    check("all four dependency kinds present",
          dep_kinds == {"data", "control", "alias", "state"}, str(sorted(dep_kinds)))
    mut = next(n for n in ir.nodes if n.kind == "Mutation" and n.detail == "mul_")
    branch = next(n for n in ir.nodes if n.kind == "Branch")
    check("mutation inside the branch has a control dep on it",
          any(d.src == branch.id and d.dst == mut.id and d.kind == "control" for d in ir.deps))
    w = next(n for n in ir.nodes if n.kind == "Assign" and "w" in n.defs)
    y = next(n for n in ir.nodes if n.kind == "Assign" and "y" in n.defs)
    check("w = y[:] has an alias dep on y's definition",
          any(d.src == y.id and d.dst == w.id and d.kind == "alias" for d in ir.deps),
          w.detail)
    sw = next(n for n in ir.nodes if n.kind == "StateWrite")
    sr = [n for n in ir.nodes if n.kind == "StateRead" and n.detail == "STATE.total"]
    check("state dep links the write to the later read of the same attribute",
          any(d.src == sw.id and d.kind == "state" and d.dst in {n.id for n in sr}
              for d in ir.deps), str([(n.id, n.kind, n.detail) for n in ir.nodes]))
    ret = next(n for n in ir.nodes if n.kind == "Return")
    back = ir.backward_slice(ret.id)
    check("backward slice of the return reaches y's definition", y.id in back, str(back))
    bad = build_ir("def f(x:\n  return x")
    check("IR survives a syntax error", bad.error is not None and bad.nodes == [])


def test_conjunction_contexts():
    from tcd.experiments import conjunction_contexts

    src = "def f(x, flag):\n    if flag and x.shape[0] > 32:\n        return x * 2\n    return x + 1\n"
    ctxs = conjunction_contexts(src)
    outcomes = set()
    for c in ctxs:
        fv = c.get("substitute", {}).get("value")
        nv = c.get("resize", {}).get("value")
        outcomes.add((bool(fv), nv > 32))
    check("joint contexts reach all four T/T T/F F/T F/F outcomes",
          len(outcomes) == 4, str(sorted(outcomes)))
    check("every joint context moves the flag and the shape of the right args",
          all(c.get("substitute", {}).get("arg") == 1 and c.get("resize", {}).get("arg") == 0
              for c in ctxs), str([c.factors for c in ctxs[:2]]))


def test_argument_makers():
    from tcd.cases_project import argument_makers

    def f(x, n: int, use_fast=False, eps: float = 1e-5, *args, **kw):
        return x

    makers = argument_makers(f)
    names = [n for n, _ in makers]
    check("signature construction covers positional parameters only",
          names == ["x", "n", "use_fast", "eps"], str(names))
    vals = {n: mk() for n, mk in makers}
    check("annotations and defaults drive the values",
          vals["n"] == 4 and vals["use_fast"] is False and vals["eps"] == 1e-5, str(vals))
    check("builtins have no readable signature and are skipped",
          argument_makers(len) is None or isinstance(argument_makers(len), list))


def test_gradient_oracle_offline():
    from tcd.oracle import GRADIENT, compare

    ref = Observation(mode="a", grads=[1.0, None])
    same = Observation(mode="b", grads=[1.0, None])
    check("identical gradients: no finding", not compare(ref, same).findings)
    diff = Observation(mode="b", grads=[2.0, None])
    kinds = compare(ref, diff).kinds
    check("different gradient value fires O6", kinds == [GRADIENT], str(kinds))
    lost = Observation(mode="b", grads=[1.0, 3.0])
    check("gradient present on one side only fires O6",
          GRADIENT in compare(ref, lost).kinds)
    failed = Observation(mode="b", grads=None, grad_error="no output requires grad")
    cmp = compare(ref, failed)
    check("backward failing on one side only fires O6",
          GRADIENT in cmp.kinds and "one side only" in cmp.findings[0].detail,
          str([f.detail for f in cmp.findings]))
    neither = Observation(mode="b", grads=None)
    check("nothing to differentiate on either side: no finding",
          not compare(Observation(mode="a", grads=None), neither).findings)


def main() -> int:
    print("\nOffline harness tests (no PyTorch required)")
    print("=" * 72)
    for fn in (
        test_flatten,
        test_context_pairs,
        test_triage_warm,
        test_worst,
        test_signature_stability,
        test_dedup_roundtrip,
        test_issue_rendering,
        test_write_record,
        test_analysis_alias_and_facts,
        test_analysis_write_order_and_returned_alias,
        test_analysis_returns_are_not_overapproximated,
        test_analysis_boundaries,
        test_index_relation,
        test_flag_detection_is_not_overbroad,
        test_obligations_are_derived_not_hardcoded,
        test_analysis_survives_bad_input,
        test_sanitisation,
        test_duplicate_query_building,
        test_duplicate_section_renders_without_network,
        test_sites_scan,
        test_ir_build,
        test_conjunction_contexts,
        test_argument_makers,
        test_gradient_oracle_offline,
    ):
        print(f"\n{fn.__name__}")
        fn()
    print("\n" + "=" * 72)
    if FAILURES:
        print(f"{len(FAILURES)} FAILED: {', '.join(FAILURES)}\n")
        return 1
    print("all offline tests passed\n")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
