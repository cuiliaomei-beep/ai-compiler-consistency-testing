"""Plan section 17.1: the consistency oracles.

    O1 value      numeric agreement, judged against a float64 reference
    O2 metadata   shape / dtype / device / layout of the outputs
    O3 exception  raised vs not, and the exception type
    O4 mutation   inputs, mutable objects and module state after the call
    O5 alias      storage-sharing relation over inputs and outputs
    O6 gradient   input gradients (parameter gradients via module params)
    O7 cache      cold / warm / context-switch / recompile behaviour

The value rule is what keeps false positives down: ``torch.compile``
legitimately changes numerics (fusion reorders reductions, TF32, epilogues),
so we do not ask ``|compiled - eager| < eps``. We ask what PyTorch's own
accuracy suite asks: *is the compiled result further from the float64 truth
than eager is?* The dtype-aware tolerance of section 2 is the noise floor:
``ulp_slack * eps(dtype) * magnitude``.
"""
from __future__ import annotations

import math
from dataclasses import dataclass, field
from typing import Any, Dict, List, Optional, Sequence, Set

from .compat import dynamo_same, torch
from .observe import Observation, flatten, is_tensor

VALUE = "value"
METADATA = "metadata"
STRUCTURE = "structure"
EXCEPTION = "exception"
MUTATION = "mutation"
ALIAS = "alias"
ALIAS_NONCONTRACTUAL = "alias_noncontractual"
GRADIENT = "gradient"
CACHE = "cache"

ALL_ORACLES = (VALUE, METADATA, EXCEPTION, MUTATION, ALIAS, GRADIENT)


@dataclass
class Config:
    fp64_multiplier: float = 4.0
    fp64_floor: float = 1e-8
    ulp_slack: float = 4.0
    fallback_rtol: float = 1e-3
    fallback_atol: float = 1e-4
    strict_stride: bool = False
    use_dynamo_same: bool = True
    alias_contractual: bool = True
    grad_multiplier: float = 8.0
    #: let PyTorch's own ``same(fp64_ref=...)`` veto numeric findings it accepts
    defer_to_dynamo_same: bool = True


@dataclass
class Finding:
    kind: str
    detail: str
    magnitude: Optional[float] = None
    index: Optional[int] = None
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


@dataclass
class Comparison:
    ref_mode: str
    test_mode: str
    findings: List[Finding] = field(default_factory=list)
    dynamo_same: Optional[bool] = None
    opaque_outputs: List[int] = field(default_factory=list)
    oracles_run: List[str] = field(default_factory=list)
    #: numeric findings vetoed by the project's own accuracy predicate (kept for the record)
    suppressed: List[Finding] = field(default_factory=list)

    @property
    def differs(self) -> bool:
        return bool(self.findings)

    @property
    def kinds(self) -> List[str]:
        out: List[str] = []
        for f in self.findings:
            if f.kind not in out:
                out.append(f.kind)
        return out

    def as_dict(self) -> Dict[str, Any]:
        return {"ref": self.ref_mode, "test": self.test_mode, "differs": self.differs,
                "kinds": self.kinds, "dynamo_same": self.dynamo_same,
                "opaque_outputs": list(self.opaque_outputs), "oracles_run": self.oracles_run,
                "findings": [f.as_dict() for f in self.findings],
                "suppressed": [f.as_dict() for f in self.suppressed]}


# --------------------------------------------------------------------------
# numeric helpers
# --------------------------------------------------------------------------

def _fmt(x: Any) -> str:
    try:
        if is_tensor(x):
            return f"{x.item():.10g}" if x.numel() == 1 else repr(x)
        if isinstance(x, float):
            return f"{x:.10g}"
        return repr(x)
    except Exception:
        return "<unprintable>"


def _preview(t: Any, limit: int = 8) -> str:
    if not is_tensor(t):
        return _fmt(t)
    try:
        flat = t.detach().reshape(-1)
        head = ", ".join(_fmt(v) for v in flat[:limit].tolist())
        more = f", ... ({flat.numel() - limit} more)" if flat.numel() > limit else ""
        return f"[{head}{more}]"
    except Exception:
        return "<unprintable>"


def tensor_evidence(ref: Any, test: Any, atol: float = 0.0) -> Dict[str, Any]:
    ev: Dict[str, Any] = {}
    if not (is_tensor(ref) and is_tensor(test)):
        ev["expected"], ev["actual"] = _fmt(ref), _fmt(test)
        return ev
    try:
        ev["shape"], ev["dtype"] = list(ref.shape), str(ref.dtype)
        if ref.shape != test.shape:
            ev["actual_shape"] = list(test.shape)
            return ev
        a = ref.detach().reshape(-1)
        b = test.detach().reshape(-1)
        if ref.is_floating_point():
            diff = (a.double() - b.double()).abs()
            diff = torch.where(torch.isnan(diff), torch.zeros_like(diff), diff)
            bad = diff > atol
            ev["max_abs_error"] = float(diff.max().item()) if diff.numel() else 0.0
            denom = a.double().abs().clamp_min(1e-12)
            ev["max_rel_error"] = float((diff / denom).max().item()) if diff.numel() else 0.0
        else:
            bad = a != b
        n_bad = int(bad.sum().item())
        ev["n_mismatch"], ev["n_total"] = n_bad, int(a.numel())
        if n_bad:
            pos = int(bad.nonzero()[0].item())
            try:
                coord = [int(c) for c in torch.unravel_index(torch.tensor(pos), ref.shape)]
            except Exception:
                coord = [pos]
            ev["first_mismatch_index"] = coord
            ev["first_mismatch_expected"] = _fmt(a[pos])
            ev["first_mismatch_actual"] = _fmt(b[pos])
        ev["expected_preview"] = _preview(ref)
        ev["actual_preview"] = _preview(test)
    except Exception as e:
        ev["evidence_error"] = f"{type(e).__name__}: {str(e)[:80]}"
    return ev


def _is_float(t: Any) -> bool:
    return is_tensor(t) and t.is_floating_point()


def noise_floor(ref: Any, cfg: Config) -> float:
    """dtype-aware tolerance: ``ulp_slack * eps(dtype) * max(|ref|, 1)``."""
    if not _is_float(ref):
        return cfg.fp64_floor
    try:
        eps = torch.finfo(ref.dtype).eps
        a = ref.detach().abs()
        finite = a[torch.isfinite(a)]
        scale = float(finite.max().item()) if finite.numel() else 1.0
        if not math.isfinite(scale):
            scale = 1.0
        return max(cfg.ulp_slack * eps * max(scale, 1.0), cfg.fp64_floor)
    except Exception:
        return cfg.fp64_floor


def abs_error(a: Any, b: Any) -> Optional[float]:
    if not (is_tensor(a) and is_tensor(b)) or a.shape != b.shape:
        return None
    try:
        d = (a.detach().to(torch.float64) - b.detach().to(torch.float64)).abs()
        d = torch.where(torch.isnan(d), torch.zeros_like(d), d)
        return float(d.max().item()) if d.numel() else 0.0
    except Exception:
        return None


_COMPARABLE = (int, float, complex, bool, str, bytes, type(None))


def is_comparable(x: Any) -> bool:
    if is_tensor(x):
        try:
            return x.layout == torch.strided
        except Exception:
            return False
    return isinstance(x, _COMPARABLE)


def _exact_equal(a: Any, b: Any) -> Optional[bool]:
    if is_tensor(a) and is_tensor(b):
        if a.shape != b.shape or a.dtype != b.dtype:
            return False
        try:
            return bool(torch.equal(a.detach().cpu(), b.detach().cpu()))
        except Exception:
            return None
    if isinstance(a, float) and isinstance(b, float):
        return (math.isnan(a) and math.isnan(b)) or a == b
    try:
        return bool(a == b)
    except Exception:
        return None


def _nan_pattern_differs(a: Any, b: Any) -> bool:
    if not (_is_float(a) and _is_float(b)):
        return False
    try:
        an = bool(torch.isnan(a).any().item() or torch.isinf(a).any().item())
        bn = bool(torch.isnan(b).any().item() or torch.isinf(b).any().item())
        return an != bn
    except Exception:
        return False


def _float_pair_findings(kind: str, label: str, a: Any, b: Any, ref64: Any, cfg: Config,
                         mult: float, i: int) -> Optional[Finding]:
    """Shared fp64-rule comparison used by O1 and O6."""
    if _nan_pattern_differs(a, b):
        # With a float64 reference the *truth* decides: a compiled result that is
        # finite where eager overflowed to inf (fp16 loss computed in fp32 by
        # Inductor) is more accurate, not a defect. Without a reference, any
        # one-sided NaN/Inf is reported.
        if _is_float(ref64):
            if _nan_pattern_differs(b, ref64):
                return Finding(kind, f"{label}: NaN/Inf pattern differs from the float64 truth", index=i,
                               evidence=tensor_evidence(a, b))
            return None
        return Finding(kind, f"{label}: NaN/Inf present on one side only", index=i,
                       evidence=tensor_evidence(a, b))
    if _is_float(ref64):
        err_ref, err_test = abs_error(a, ref64), abs_error(b, ref64)
        if err_ref is not None and err_test is not None:
            floor = noise_floor(a, cfg)
            budget = max(err_ref * mult, floor)
            if err_test > budget:
                ev = tensor_evidence(a, b, atol=budget)
                ev.update({"eager_err_vs_fp64": err_ref, "compiled_err_vs_fp64": err_test,
                           "budget": budget, "noise_floor": floor})
                return Finding(kind, f"{label}: compiled err vs fp64 = {err_test:.3e} exceeds "
                                     f"{mult}x eager err {err_ref:.3e}", magnitude=err_test,
                               index=i, evidence=ev)
            return None
    err = abs_error(a, b)
    if err is None:
        if _exact_equal(a, b) is False:
            return Finding(kind, f"{label}: values differ (not numerically comparable)", index=i,
                           evidence=tensor_evidence(a, b))
        return None
    try:
        scale = float(a.detach().abs().max().item()) if a.numel() else 0.0
    except Exception:
        scale = 0.0
    tol = max(cfg.fallback_atol + cfg.fallback_rtol * scale, noise_floor(a, cfg))
    if err > tol:
        return Finding(kind, f"{label}: |ref-test| = {err:.3e} exceeds dtype-aware tolerance {tol:.3e}"
                             " (no fp64 reference)", magnitude=err, index=i,
                       evidence=tensor_evidence(a, b, atol=tol))
    return None


# --------------------------------------------------------------------------
# O1 value
# --------------------------------------------------------------------------

def _o1_value(ref: Observation, test: Observation, fp64: Optional[Observation],
              cfg: Config, opaque: List[int]) -> List[Finding]:
    out: List[Finding] = []
    ri, _ = flatten(ref.outputs)
    ti, _ = flatten(test.outputs)
    fi: List[Any] = flatten(fp64.outputs)[0] if (fp64 is not None and fp64.ok) else []
    for i, (a, b) in enumerate(zip(ri, ti)):
        if not (is_comparable(a) and is_comparable(b)):
            opaque.append(i)
            continue
        ref64 = fi[i] if i < len(fi) else None
        if is_tensor(a) and a.is_complex() and is_tensor(b) and b.is_complex():
            # complex outputs: compare (re, im) as floats so NaN/Inf and tolerance rules apply
            a, b = torch.view_as_real(a.detach().resolve_conj()), torch.view_as_real(b.detach().resolve_conj())
            if is_tensor(ref64) and ref64.is_complex():
                ref64 = torch.view_as_real(ref64.detach().resolve_conj())
        if not (_is_float(a) and _is_float(b)):
            if _exact_equal(a, b) is False:
                out.append(Finding(VALUE, f"output[{i}]: non-float values differ exactly", index=i,
                                   evidence=tensor_evidence(a, b)))
            continue
        f = _float_pair_findings(VALUE, f"output[{i}]", a, b, ref64, cfg, cfg.fp64_multiplier, i)
        if f is not None:
            out.append(f)
    return out


# --------------------------------------------------------------------------
# O2 metadata / O3 exception / O4 mutation / O5 alias / O6 gradient
# --------------------------------------------------------------------------

def _o2_metadata(ref: Observation, test: Observation, cfg: Config) -> List[Finding]:
    out: List[Finding] = []
    if ref.out_struct != test.out_struct:
        return [Finding(STRUCTURE, f"output structure differs: {ref.out_struct} vs {test.out_struct}")]
    for i, (a, b) in enumerate(zip(ref.out_meta, test.out_meta)):
        if a is None or b is None:
            continue
        for attr in ("shape", "dtype", "device"):
            if getattr(a, attr) != getattr(b, attr):
                out.append(Finding(METADATA, f"output[{i}].{attr}: {getattr(a, attr)} vs {getattr(b, attr)}",
                                   index=i))
        if cfg.strict_stride and a.stride != b.stride:
            out.append(Finding(METADATA, f"output[{i}].stride: {a.stride} vs {b.stride}", index=i))
    return out


_WRAPPERS = ("TorchRuntimeError", "InternalTorchDynamoError", "BackendCompilerFailed", "Unsupported",
             "UserError", "TorchDynamoException")


def canonical_exception(name: Optional[str], msg: Optional[str]) -> Optional[str]:
    """Strip the compiler's wrapper around the program's own exception.

    Dynamo re-raises the error a program hits during tracing as
    ``TorchRuntimeError("RuntimeError when making fake tensor call ...")``.
    The *program* behaved the same way in both worlds; only the envelope
    differs. Comparing envelopes reports every input-validation error as a
    graph-capture divergence.
    """
    if not name:
        return name
    if name in _WRAPPERS and msg:
        import re
        # the innermost error the program raised comes first: "... got ValueError('...')";
        # the envelope's own leading word ("RuntimeError when making fake tensor call") is
        # only a fallback
        m = re.search(r"got ([A-Za-z_]*(?:Error|Exception))\(", msg)
        if m:
            return m.group(1)
        m = re.match(r"\s*([A-Za-z_]*(?:Error|Exception))\b", msg)
        if m:
            return m.group(1)
    return name


def _program_exception(obs: Observation) -> Optional[str]:
    """The exception type the *program* raised: the innermost one when the
    compiler wrapped it, else the message-derived canonical type."""
    if obs.exception in _WRAPPERS and obs.exception_inner and obs.exception_inner not in _WRAPPERS:
        return obs.exception_inner
    return canonical_exception(obs.exception, obs.exception_msg)


def _o3_exception(ref: Observation, test: Observation) -> List[Finding]:
    if ref.ok and test.ok:
        return []
    if ref.ok != test.ok:
        raiser, quiet = ("test", "ref") if ref.ok else ("ref", "test")
        exc = test.exception if ref.ok else ref.exception
        msg = (test.exception_msg if ref.ok else ref.exception_msg) or ""
        return [Finding(EXCEPTION, f"{raiser} raised {exc}, {quiet} returned normally",
                        evidence={"exception": exc, "message": msg[:200]})]
    a = _program_exception(ref)
    b = _program_exception(test)
    if a != b:
        return [Finding(EXCEPTION, f"exception type differs: {ref.exception} vs {test.exception}",
                        evidence={"ref_message": (ref.exception_msg or "")[:200],
                                  "test_message": (test.exception_msg or "")[:200]})]
    return []


def _o4_mutation(ref: Observation, test: Observation, cfg: Config) -> List[Finding]:
    out: List[Finding] = []
    ai, _ = flatten(ref.inputs_after)
    bi, _ = flatten(test.inputs_after)
    if len(ai) != len(bi):
        return [Finding(MUTATION, "input arity changed between executions")]
    for i, (a, b) in enumerate(zip(ai, bi)):
        if not is_tensor(a) or not (is_comparable(a) and is_comparable(b)):
            continue
        if _is_float(a) and _is_float(b):
            err = abs_error(a, b)
            if err is None:
                continue
            tol = max(cfg.fallback_atol, noise_floor(a, cfg))
            if err > tol:
                out.append(Finding(MUTATION, f"input[{i}] holds a different value after the call "
                                             f"(max diff {err:.3e}); in-place effects diverge",
                                   magnitude=err, index=i, evidence=tensor_evidence(a, b, atol=tol)))
        elif _exact_equal(a, b) is False:
            out.append(Finding(MUTATION, f"input[{i}] differs after the call (exact)", index=i,
                               evidence=tensor_evidence(a, b)))
    return out


def _o5_alias(ref: Observation, test: Observation, contractual: bool) -> List[Finding]:
    if ref.alias == test.alias:
        return []
    bits = []
    lost, gained = sorted(ref.alias - test.alias), sorted(test.alias - ref.alias)
    if lost:
        bits.append(f"lost {lost}")
    if gained:
        bits.append(f"gained {gained}")
    detail = ("storage-sharing relation changed: " + "; ".join(bits)
              + f" (indices < {ref.n_inputs} are inputs, >= {ref.n_inputs} outputs)")
    if contractual:
        return [Finding(ALIAS, detail, evidence={"lost": lost, "gained": gained})]
    return [Finding(ALIAS_NONCONTRACTUAL, detail + " - the operator's schema declares no alias relation")]


def _o6_gradient(ref: Observation, test: Observation, fp64: Optional[Observation],
                 cfg: Config) -> List[Finding]:
    out: List[Finding] = []
    if ref.grads is None and test.grads is None:
        return out
    if (ref.grads is None) != (test.grads is None):
        which = "ref" if ref.grads is None else "test"
        err = ref.grad_error if ref.grads is None else test.grad_error
        return [Finding(GRADIENT, f"gradient unavailable on the {which} side only ({err})")]
    assert ref.grads is not None and test.grads is not None
    f64 = fp64.grads if (fp64 is not None and fp64.ok and fp64.grads) else []
    for i, (a, b) in enumerate(zip(ref.grads, test.grads)):
        if (a is None) != (b is None):
            out.append(Finding(GRADIENT, f"grad[{i}]: present on one side only", index=i))
            continue
        if a is None:
            continue
        ref64 = f64[i] if i < len(f64) else None
        f = _float_pair_findings(GRADIENT, f"grad[{i}]", a, b, ref64, cfg, cfg.grad_multiplier, i)
        if f is not None:
            out.append(f)
    return out


# --------------------------------------------------------------------------
# entry point
# --------------------------------------------------------------------------

def compare(ref: Observation, test: Observation, fp64: Optional[Observation] = None,
            cfg: Optional[Config] = None, oracles: Optional[Sequence[str]] = None) -> Comparison:
    cfg = cfg or Config()
    active: Set[str] = set(oracles) if oracles else set(ALL_ORACLES)
    cmp = Comparison(ref_mode=ref.mode, test_mode=test.mode, oracles_run=sorted(active))

    if EXCEPTION in active:
        exc = _o3_exception(ref, test)
        if exc:
            cmp.findings.extend(exc)
            return cmp
    if not ref.ok or not test.ok:
        return cmp  # both raised (or exception oracle disabled): nothing else comparable

    if METADATA in active:
        cmp.findings.extend(_o2_metadata(ref, test, cfg))
        if any(f.kind == STRUCTURE for f in cmp.findings):
            return cmp
    opaque: List[int] = []
    if VALUE in active:
        cmp.findings.extend(_o1_value(ref, test, fp64, cfg, opaque))
        cmp.opaque_outputs = opaque
    if MUTATION in active:
        cmp.findings.extend(_o4_mutation(ref, test, cfg))
    if ALIAS in active:
        cmp.findings.extend(_o5_alias(ref, test, cfg.alias_contractual))
    if GRADIENT in active:
        cmp.findings.extend(_o6_gradient(ref, test, fp64, cfg))
    if cfg.use_dynamo_same and VALUE in active:
        fp64_out = fp64.outputs if (fp64 is not None and fp64.ok) else None
        cmp.dynamo_same = dynamo_same(ref.outputs, test.outputs, fp64_ref=fp64_out)
        # The project's own accuracy predicate has the last word on *numeric*
        # findings when a float64 reference exists (plan 17.1: dtype-aware
        # tolerance = the project's policy). Our ULP floor is scaled by the
        # output magnitude, so a sum that cancels (small output, large terms)
        # looks worse than it is; `same()` judges it the way PyTorch CI does.
        if cfg.defer_to_dynamo_same and cmp.dynamo_same is True and fp64_out is not None:
            kept = []
            for f in cmp.findings:
                if f.kind == VALUE and "fp64" in f.detail and "NaN/Inf" not in f.detail:
                    f.evidence["suppressed_by"] = "torch._dynamo.utils.same(fp64_ref) accepted the result"
                    cmp.suppressed.append(f)
                else:
                    kept.append(f)
            cmp.findings = kept
    return cmp


# --------------------------------------------------------------------------
# O7 cache oracle
# --------------------------------------------------------------------------

@dataclass
class CacheVerdict:
    """What the cold / warm / return-trip executions say about caching."""
    factor: str
    recompiled_on_switch: Optional[bool]
    cold_vs_warm: Comparison
    eager_vs_cold: Optional[Comparison] = None
    eager_vs_warm: Optional[Comparison] = None
    return_trip: Optional[Comparison] = None
    recompiled_on_return: Optional[bool] = None

    @property
    def warm_only_failure(self) -> bool:
        """E2 == C2cold and E2 != C2warm: the plan's strongest cache signal."""
        cold_ok = self.eager_vs_cold is None or not self.eager_vs_cold.differs
        warm_bad = self.eager_vs_warm is not None and self.eager_vs_warm.differs
        return cold_ok and (warm_bad or self.cold_vs_warm.differs)

    @property
    def stale_reuse(self) -> bool:
        return self.cold_vs_warm.differs and self.recompiled_on_switch is False

    @property
    def guard_suspicious(self) -> bool:
        return (not self.cold_vs_warm.differs) and self.recompiled_on_switch is False

    @property
    def invalidation_failure(self) -> bool:
        return self.return_trip is not None and self.return_trip.differs

    def findings(self) -> List[Finding]:
        out: List[Finding] = []
        if self.stale_reuse:
            out.append(Finding(CACHE, f"switching '{self.factor}' did not recompile, yet the warm result "
                                      "differs from a cold compile: stale artifact reused"))
        elif self.cold_vs_warm.differs:
            out.append(Finding(CACHE, f"switching '{self.factor}' recompiled, but the warm result still "
                                      "differs from a cold compile: state leaks across compilations"))
        if self.invalidation_failure:
            out.append(Finding(CACHE, f"after '{self.factor}' A -> B -> A the original context no longer "
                                      "returns its original result: incorrect cache invalidation"))
        if self.guard_suspicious:
            out.append(Finding(CACHE, f"'{self.factor}' changed without a recompile; result matched "
                                      "(guard may be under-specified; informational)"))
        return out

    def as_dict(self) -> Dict[str, Any]:
        return {
            "factor": self.factor,
            "recompiled_on_switch": self.recompiled_on_switch,
            "recompiled_on_return": self.recompiled_on_return,
            "cold_vs_warm": self.cold_vs_warm.as_dict(),
            "eager_vs_cold": self.eager_vs_cold.as_dict() if self.eager_vs_cold else None,
            "eager_vs_warm": self.eager_vs_warm.as_dict() if self.eager_vs_warm else None,
            "return_trip": self.return_trip.as_dict() if self.return_trip else None,
            "warm_only_failure": self.warm_only_failure, "stale_reuse": self.stale_reuse,
            "guard_suspicious": self.guard_suspicious,
            "invalidation_failure": self.invalidation_failure,
            "findings": [f.as_dict() for f in self.findings()],
        }
