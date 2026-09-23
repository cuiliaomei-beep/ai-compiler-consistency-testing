"""The consistency oracles.

Six comparisons, in the order the research plan prioritises them:

===========  =========================================================
O1 value     numeric agreement, judged against an **fp64 reference**
O2 mutation  did the call change the caller's inputs the same way
O3 alias     did outputs share storage with inputs the same way
O4 exception did both raise, and the same type
O5 metadata  shape / dtype / device of the outputs
O6 gradient  input and parameter gradients, under the same fp64 rule
===========  =========================================================

(The plan's O7, cache behaviour, is not a comparison of two observations:
it is the cold/warm/return-trip *protocol* in :mod:`tcd.execution` and its
verdicts in :mod:`tcd.triage`.)

The fp64 rule is the one that decides whether this project drowns in false
positives. ``torch.compile`` *legitimately* changes numerics: fusion reorders
reductions, TF32 lowers matmul precision, epilogues differ. So a fixed
``|compiled - eager| > eps`` threshold flags mostly non-bugs. Instead we ask
the question PyTorch's own accuracy suite asks:

    is the compiled result *further from the float64 truth* than eager is?

Only then is the compiled path actually less correct. A report built on this
predicate cannot be dismissed on tolerance grounds, because it is the
project's own policy.
"""
from __future__ import annotations

import math
from dataclasses import dataclass, field
from typing import Any, Dict, List, Optional

from .snapshot import Observation, TensorMeta, flatten
from .torchcompat import dynamo_same, torch

# Oracle kinds, most-to-least decisive.
VALUE = "value"
MUTATION = "mutation"
ALIAS = "alias"
#: an alias change on an operator that never promised one - recorded, demoted
ALIAS_NONCONTRACTUAL = "alias_noncontractual"
EXCEPTION = "exception"
METADATA = "metadata"
STRUCTURE = "structure"
GRADIENT = "gradient"


@dataclass
class Config:
    #: compiled error may exceed eager error by this factor before we complain.
    #: PyTorch's own ``same()`` uses a small multiplier for the same purpose.
    fp64_multiplier: float = 4.0
    #: absolute floor, used only when a dtype-aware floor cannot be computed.
    fp64_floor: float = 1e-8
    #: how many units-in-the-last-place of the *test* dtype to forgive when
    #: eager happens to match float64 exactly.
    #:
    #: This matters more than any other constant here. Fusion reorders
    #: reductions, so a compiled result routinely differs from eager by a few
    #: ULP - legitimately. With a fixed 1e-8 floor, one ULP of float32
    #: (eps 1.19e-7) already exceeded the budget twentyfold, and every fused
    #: reduction in the corpus was reported as a miscompilation.
    ulp_slack: float = 4.0
    #: fallback tolerance when no fp64 reference could be built.
    fallback_rtol: float = 1e-3
    fallback_atol: float = 1e-4
    #: strides may legitimately differ after compilation; off by default.
    strict_stride: bool = False
    #: consult ``torch._dynamo.utils.same`` as a cross-check when available.
    use_dynamo_same: bool = True
    #: does the operator under test *promise* output-input aliasing? Set False
    #: per-case for operators whose schema declares no alias relation. The
    #: oracle still runs - the finding is recorded and demoted, not discarded,
    #: because "eager returned a view and the compiler did not" is worth seeing
    #: even when it is not a defect.
    alias_contractual: bool = True


@dataclass
class Finding:
    kind: str
    detail: str
    magnitude: Optional[float] = None
    index: Optional[int] = None
    #: concrete expected/actual evidence - what a maintainer needs to see
    evidence: Dict[str, Any] = field(default_factory=dict)

    def as_dict(self) -> Dict[str, Any]:
        d: Dict[str, Any] = {"kind": self.kind, "detail": self.detail}
        if self.magnitude is not None:
            d["magnitude"] = self.magnitude
        if self.index is not None:
            d["index"] = self.index
        if self.evidence:
            d["evidence"] = self.evidence
        return d


def _fmt(x: Any) -> str:
    try:
        if torch is not None and isinstance(x, torch.Tensor):
            return f"{x.item():.10g}" if x.numel() == 1 else repr(x)
        if isinstance(x, float):
            return f"{x:.10g}"
        return repr(x)
    except Exception:
        return "<unprintable>"


def _preview(t: Any, limit: int = 8) -> str:
    """A short, honest rendering of a tensor: never dump a million numbers."""
    if torch is None or not isinstance(t, torch.Tensor):
        return _fmt(t)
    try:
        flat = t.detach().reshape(-1)
        head = ", ".join(_fmt(v) for v in flat[:limit].tolist())
        more = f", ... ({flat.numel() - limit} more)" if flat.numel() > limit else ""
        return f"[{head}{more}]"
    except Exception:
        return "<unprintable>"


def tensor_evidence(ref: Any, test: Any, atol: float = 0.0) -> Dict[str, Any]:
    """Where and by how much two tensors disagree.

    An issue that says only "the values differ" costs the maintainer the work
    of finding out *how*. This produces the expected/actual pair, the first
    mismatching position, and the size of the disagreement, so the report
    carries its own evidence.
    """
    ev: Dict[str, Any] = {}
    if torch is None or not (isinstance(ref, torch.Tensor) and isinstance(test, torch.Tensor)):
        ev["expected"] = _fmt(ref)
        ev["actual"] = _fmt(test)
        return ev
    try:
        ev["shape"] = list(ref.shape)
        ev["dtype"] = str(ref.dtype)
        if ref.shape != test.shape:
            ev["actual_shape"] = list(test.shape)
            return ev

        a = ref.detach().reshape(-1)
        b = test.detach().reshape(-1)
        if ref.is_floating_point():
            diff = (a.double() - b.double()).abs()
            bad = diff > atol
            ev["max_abs_error"] = float(diff.max().item()) if diff.numel() else 0.0
            denom = a.double().abs().clamp_min(1e-12)
            ev["max_rel_error"] = float((diff / denom).max().item()) if diff.numel() else 0.0
        else:
            bad = a != b

        n_bad = int(bad.sum().item())
        ev["n_mismatch"] = n_bad
        ev["n_total"] = int(a.numel())
        if n_bad:
            pos = int(bad.nonzero()[0].item())
            try:
                import numpy as np  # noqa: F401
                coord = list(map(int, torch.unravel_index(
                    torch.tensor(pos), ref.shape)))
            except Exception:
                coord = [pos]
            ev["first_mismatch_index"] = coord
            ev["first_mismatch_expected"] = _fmt(a[pos])
            ev["first_mismatch_actual"] = _fmt(b[pos])
        ev["expected_preview"] = _preview(ref)
        ev["actual_preview"] = _preview(test)
    except Exception as e:  # evidence is best-effort; never break the run for it
        ev["evidence_error"] = f"{type(e).__name__}: {str(e)[:80]}"
    return ev


@dataclass
class Comparison:
    ref_mode: str
    test_mode: str
    findings: List[Finding] = field(default_factory=list)
    dynamo_same: Optional[bool] = None
    #: output positions that could not be compared (generators, opaque objects)
    opaque_outputs: List[int] = field(default_factory=list)

    @property
    def differs(self) -> bool:
        return bool(self.findings)

    @property
    def kinds(self) -> List[str]:
        seen: List[str] = []
        for f in self.findings:
            if f.kind not in seen:
                seen.append(f.kind)
        return seen

    def as_dict(self) -> Dict[str, Any]:
        return {
            "ref": self.ref_mode,
            "test": self.test_mode,
            "differs": self.differs,
            "kinds": self.kinds,
            "dynamo_same": self.dynamo_same,
            "opaque_outputs": list(self.opaque_outputs),
            "findings": [f.as_dict() for f in self.findings],
        }


# --------------------------------------------------------------------------
# numeric helpers
# --------------------------------------------------------------------------

def _is_float(t: Any) -> bool:
    return torch is not None and isinstance(t, torch.Tensor) and t.is_floating_point()


def noise_floor(ref: Any, cfg: "Config") -> float:
    """Error below which a difference is arithmetic noise, not a defect.

    Scaled by the dtype's epsilon and the magnitude of the values, because a
    "small" absolute error means nothing without both. One ULP of float32 at
    magnitude 2.5 is 3e-7; at magnitude 1e6 it is 0.12. A single fixed
    threshold is wrong at almost every scale.
    """
    if torch is None or not isinstance(ref, torch.Tensor) or not ref.is_floating_point():
        return cfg.fp64_floor
    try:
        eps = torch.finfo(ref.dtype).eps
        if ref.numel():
            # NaN/Inf must not reach the scale: max() over a tensor containing
            # NaN *is* NaN, the floor becomes NaN, and every comparison against
            # it is then false - so a one-ULP difference gets reported. Take the
            # magnitude over the finite entries only.
            a = ref.detach().abs()
            finite = a[torch.isfinite(a)]
            scale = float(finite.max().item()) if finite.numel() else 1.0
        else:
            scale = 1.0
        if not math.isfinite(scale):
            scale = 1.0
        return max(cfg.ulp_slack * eps * max(scale, 1.0), cfg.fp64_floor)
    except Exception:
        return cfg.fp64_floor


def abs_error(a: Any, b: Any) -> Optional[float]:
    """max |a - b| in float64, or None when not comparable numerically."""
    if torch is None:
        return None
    if not (isinstance(a, torch.Tensor) and isinstance(b, torch.Tensor)):
        return None
    if a.shape != b.shape:
        return None
    try:
        x = a.detach().to(torch.float64)
        y = b.detach().to(torch.float64)
        d = (x - y).abs()
        d = torch.where(torch.isnan(d), torch.zeros_like(d), d)
        if d.numel() == 0:
            return 0.0
        return float(d.max().item())
    except Exception:
        return None


#: leaf types whose ``==`` actually means "same value"
_COMPARABLE = (int, float, complex, bool, str, bytes, type(None))


def is_comparable(x: Any) -> bool:
    """Can two of these be meaningfully compared for equality?

    Two classes are excluded, both learned from real runs:

    * Generators, iterators and arbitrary objects fall back to identity
      comparison, so two runs *always* look different. A function returning
      ``map(f, x)`` was reported as a miscompilation on every execution.
    * Non-strided tensors (sparse COO/CSR, nested) do not support the
      subtraction and indexing this module's comparisons use. The comparison
      fails, and a failed comparison is not a divergence - reporting it as one
      turned every ``sparse.*`` operator into a false candidate.

    Excluding them costs coverage, which is recorded rather than hidden.
    """
    if torch is not None and isinstance(x, torch.Tensor):
        try:
            return x.layout == torch.strided
        except Exception:
            return False
    return isinstance(x, _COMPARABLE)


def _exact_equal(a: Any, b: Any) -> Optional[bool]:
    """Exact comparison for non-float tensors and plain scalars."""
    if torch is not None and isinstance(a, torch.Tensor) and isinstance(b, torch.Tensor):
        if a.shape != b.shape or a.dtype != b.dtype:
            return False
        try:
            return bool(torch.equal(a.detach().cpu(), b.detach().cpu()))
        except Exception:
            return None
    if isinstance(a, float) and isinstance(b, float):
        if math.isnan(a) and math.isnan(b):
            return True
        return a == b
    try:
        return bool(a == b)
    except Exception:
        return None


def _nan_pattern_differs(a: Any, b: Any) -> bool:
    """A NaN/Inf appearing on only one side is always worth reporting."""
    if torch is None or not (_is_float(a) and _is_float(b)):
        return False
    try:
        an = torch.isnan(a).any().item() or torch.isinf(a).any().item()
        bn = torch.isnan(b).any().item() or torch.isinf(b).any().item()
        return bool(an) != bool(bn)
    except Exception:
        return False


# --------------------------------------------------------------------------
# O1 value
# --------------------------------------------------------------------------

def _compare_values(
    ref: Observation,
    test: Observation,
    fp64: Optional[Observation],
    cfg: Config,
    opaque: Optional[List[int]] = None,
) -> List[Finding]:
    out: List[Finding] = []
    if opaque is None:
        opaque = []
    ref_items, _ = flatten(ref.outputs)
    test_items, _ = flatten(test.outputs)
    fp64_items: List[Any] = []
    if fp64 is not None and fp64.ok:
        fp64_items, _ = flatten(fp64.outputs)

    for i, (a, b) in enumerate(zip(ref_items, test_items)):
        if not (is_comparable(a) and is_comparable(b)):
            # e.g. a returned generator: equality would be identity, so any
            # verdict here is noise. Count it so the reduced coverage is
            # visible instead of silent.
            opaque.append(i)
            continue

        if _nan_pattern_differs(a, b):
            out.append(Finding(VALUE, f"output[{i}]: NaN/Inf present on one side only", index=i))
            continue

        if not (_is_float(a) and _is_float(b)):
            eq = _exact_equal(a, b)
            if eq is False:
                out.append(Finding(
                    VALUE, f"output[{i}]: non-float values differ exactly",
                    index=i, evidence=tensor_evidence(a, b)))
            continue

        f64 = fp64_items[i] if i < len(fp64_items) else None
        finding = _float_divergence(VALUE, f"output[{i}]", a, b, f64, cfg, i)
        if finding is not None:
            out.append(finding)
    return out


def _float_divergence(kind: str, label: str, a: Any, b: Any, f64: Any,
                      cfg: Config, index: int) -> Optional[Finding]:
    """The fp64 rule for one float pair; ``None`` when they agree within budget.

    Shared by O1 (outputs) and O6 (gradients) so both are judged by the same
    policy - a gradient is a number like any other, and a fixed tolerance would
    misjudge it at exactly the scales it misjudges outputs.
    """
    # --- the fp64 rule ---
    if f64 is not None and _is_float(f64):
        err_ref = abs_error(a, f64)
        err_test = abs_error(b, f64)
        if err_ref is not None and err_test is not None:
            # Two ways a difference can be acceptable: eager is no better
            # (the multiplier branch), or the gap is within arithmetic
            # noise for this dtype and magnitude (the ULP branch).
            floor = noise_floor(a, cfg)
            budget = max(err_ref * cfg.fp64_multiplier, floor)
            if err_test > budget:
                ev = tensor_evidence(a, b, atol=budget)
                ev["eager_err_vs_fp64"] = err_ref
                ev["compiled_err_vs_fp64"] = err_test
                ev["budget"] = budget
                ev["noise_floor"] = floor
                ev["ulp_slack"] = cfg.ulp_slack
                return Finding(
                    kind,
                    f"{label}: compiled err vs fp64 = {err_test:.3e} exceeds "
                    f"{cfg.fp64_multiplier}x eager err {err_ref:.3e}",
                    magnitude=err_test, index=index, evidence=ev)
            return None  # fp64 reference is authoritative; skip the fallback

    # --- fallback: no usable fp64 reference ---
    err = abs_error(a, b)
    if err is None:
        if _exact_equal(a, b) is False:
            return Finding(kind, f"{label}: values differ (no fp64 ref)", index=index)
        return None
    try:
        scale = float(a.detach().abs().max().item()) if a.numel() else 0.0
    except Exception:
        scale = 0.0
    tol = max(cfg.fallback_atol + cfg.fallback_rtol * scale, noise_floor(a, cfg))
    if err > tol:
        return Finding(
            kind,
            f"{label}: |ref-test| = {err:.3e} (no fp64 ref; fallback tolerance)",
            magnitude=err, index=index, evidence=tensor_evidence(a, b, atol=tol))
    return None


# --------------------------------------------------------------------------
# O6 gradient
# --------------------------------------------------------------------------

def _compare_grads(ref: Observation, test: Observation,
                   fp64: Optional[Observation], cfg: Config) -> List[Finding]:
    """Did backward produce the same gradients, judged by the fp64 rule?

    Three shapes of divergence, in decreasing severity:

    * backward *ran* on one side only - typically the compiled function
      returned outputs that no longer require grad, so the model cannot train;
    * a leaf received a gradient on one side and ``None`` on the other - the
      compiled graph dropped a dependency;
    * both produced a gradient, and the compiled one is further from the
      float64 truth than eager's by more than the budget.
    """
    ran_ref = ref.grads is not None
    ran_test = test.grads is not None
    if not ran_ref and not ran_test:
        if bool(ref.grad_error) != bool(test.grad_error):
            which = "compiled" if test.grad_error else "eager"
            return [Finding(GRADIENT,
                            f"backward failed on the {which} side only: "
                            f"{test.grad_error or ref.grad_error}")]
        return []
    if ran_ref != ran_test:
        side = "compiled" if not ran_test else "eager"
        why = test.grad_error if not ran_test else ref.grad_error
        return [Finding(GRADIENT, f"backward ran on one side only ({side} could not: "
                                  f"{why or 'nothing to differentiate'})")]

    assert ref.grads is not None and test.grads is not None
    if len(ref.grads) != len(test.grads):
        return [Finding(GRADIENT, f"number of differentiable leaves differs: "
                                  f"{len(ref.grads)} vs {len(test.grads)}")]

    f64_grads: List[Any] = []
    if fp64 is not None and fp64.ok and fp64.grads is not None:
        f64_grads = list(fp64.grads)

    out: List[Finding] = []
    for i, (a, b) in enumerate(zip(ref.grads, test.grads)):
        if a is None and b is None:
            continue
        if (a is None) != (b is None):
            side = "compiled" if b is None else "eager"
            out.append(Finding(GRADIENT,
                               f"grad[{i}] is None on the {side} side only: the "
                               "compiled graph lost a dependency on this leaf",
                               index=i))
            continue
        if not (is_comparable(a) and is_comparable(b)):
            continue
        if _nan_pattern_differs(a, b):
            out.append(Finding(GRADIENT, f"grad[{i}]: NaN/Inf present on one side only",
                               index=i))
            continue
        if not (_is_float(a) and _is_float(b)):
            if _exact_equal(a, b) is False:
                out.append(Finding(GRADIENT, f"grad[{i}]: values differ exactly",
                                   index=i, evidence=tensor_evidence(a, b)))
            continue
        f64 = f64_grads[i] if i < len(f64_grads) else None
        finding = _float_divergence(GRADIENT, f"grad[{i}]", a, b, f64, cfg, i)
        if finding is not None:
            out.append(finding)
    return out


# --------------------------------------------------------------------------
# O2 mutation / O3 alias / O4 exception / O5 metadata
# --------------------------------------------------------------------------

def _compare_mutation(ref: Observation, test: Observation, cfg: Config) -> List[Finding]:
    """Did the call write back into the caller's tensors the same way?"""
    out: List[Finding] = []
    a_items, _ = flatten(ref.inputs_after)
    b_items, _ = flatten(test.inputs_after)
    if len(a_items) != len(b_items):
        return [Finding(MUTATION, "input arity changed between executions")]
    for i, (a, b) in enumerate(zip(a_items, b_items)):
        if torch is None or not isinstance(a, torch.Tensor):
            continue
        if not (is_comparable(a) and is_comparable(b)):
            continue  # sparse/nested: no comparison is possible, so no verdict
        if _is_float(a) and _is_float(b):
            err = abs_error(a, b)
            if err is None:
                continue  # not comparable is not the same as different
            if err > cfg.fallback_atol:
                out.append(
                    Finding(
                        MUTATION,
                        f"input[{i}] holds a different value after the call "
                        f"(max diff {err:.3e}) - in-place effects diverge",
                        magnitude=err,
                        index=i,
                        evidence=tensor_evidence(a, b, atol=cfg.fallback_atol),
                    )
                )
        else:
            if _exact_equal(a, b) is False:
                out.append(
                    Finding(MUTATION, f"input[{i}] differs after the call (exact)",
                            index=i, evidence=tensor_evidence(a, b))
                )
    return out


def _compare_alias(ref: Observation, test: Observation,
                   contractual: bool = True) -> List[Finding]:
    """Compare storage-sharing *relations* (never raw pointers)."""
    if ref.alias == test.alias:
        return []
    only_ref = sorted(ref.alias - test.alias)
    only_test = sorted(test.alias - ref.alias)
    bits = []
    if only_ref:
        bits.append(f"lost {only_ref}")
    if only_test:
        bits.append(f"gained {only_test}")
    n = ref.n_inputs
    detail = ("storage-sharing relation changed: " + "; ".join(bits)
              + f" (indices < {n} are inputs, >= {n} are outputs)")
    if contractual:
        return [Finding(ALIAS, detail)]
    return [Finding(
        ALIAS_NONCONTRACTUAL,
        detail + " - NOTE: this operator's schema declares no alias relation, "
                 "so eager returning views is an implementation detail rather "
                 "than a promise; not a defect on its own",
    )]


def _compare_exception(ref: Observation, test: Observation) -> List[Finding]:
    if ref.ok and test.ok:
        return []
    if ref.ok != test.ok:
        raiser, quiet = ("test", "ref") if ref.ok else ("ref", "test")
        exc = test.exception if ref.ok else ref.exception
        return [Finding(EXCEPTION, f"{raiser} raised {exc}, {quiet} returned normally")]
    if ref.exception != test.exception:
        return [Finding(EXCEPTION, f"exception type differs: {ref.exception} vs {test.exception}")]
    return []


def _compare_metadata(ref: Observation, test: Observation, cfg: Config) -> List[Finding]:
    out: List[Finding] = []
    if ref.out_struct != test.out_struct:
        out.append(
            Finding(STRUCTURE, f"output structure differs: {ref.out_struct} vs {test.out_struct}")
        )
        return out
    for i, (a, b) in enumerate(zip(ref.out_meta, test.out_meta)):
        if a is None or b is None:
            continue
        for attr in ("shape", "dtype", "device"):
            if getattr(a, attr) != getattr(b, attr):
                out.append(
                    Finding(
                        METADATA,
                        f"output[{i}].{attr}: {getattr(a, attr)} vs {getattr(b, attr)}",
                        index=i,
                    )
                )
        if cfg.strict_stride and a.stride != b.stride:
            out.append(
                Finding(METADATA, f"output[{i}].stride: {a.stride} vs {b.stride}", index=i)
            )
    return out


# --------------------------------------------------------------------------
# entry point
# --------------------------------------------------------------------------

def compare(
    ref: Observation,
    test: Observation,
    fp64: Optional[Observation] = None,
    cfg: Optional[Config] = None,
) -> Comparison:
    """Run all six oracles over a pair of observations."""
    cfg = cfg or Config()
    cmp = Comparison(ref_mode=ref.mode, test_mode=test.mode)

    exc = _compare_exception(ref, test)
    if exc:
        cmp.findings.extend(exc)
        return cmp  # values are meaningless once one side blew up

    if not ref.ok and not test.ok:
        return cmp  # both raised the same thing: consistent

    cmp.findings.extend(_compare_metadata(ref, test, cfg))
    if any(f.kind == STRUCTURE for f in cmp.findings):
        return cmp

    opaque: List[int] = []
    cmp.findings.extend(_compare_values(ref, test, fp64, cfg, opaque))
    cmp.opaque_outputs = opaque
    cmp.findings.extend(_compare_mutation(ref, test, cfg))
    cmp.findings.extend(_compare_alias(ref, test, cfg.alias_contractual))
    cmp.findings.extend(_compare_grads(ref, test, fp64, cfg))

    if cfg.use_dynamo_same:
        fp64_out = fp64.outputs if (fp64 is not None and fp64.ok) else None
        cmp.dynamo_same = dynamo_same(ref.outputs, test.outputs, fp64_ref=fp64_out)

    return cmp
