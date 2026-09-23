"""Plan sections 9 and 10: the Semantic Context Signature and Test Obligations.

These two are the interface between the static analysis and the test
generator, and their absence was the single largest deviation from the plan:
the analysis produced facts and boundary values that nothing ever consumed,
while the generator ran on three hard-coded contexts identical for every
function under test. The plan's central claim - *statically decide which
factors are worth changing, rather than mutating tensor attributes without a
target* - was therefore not implemented at all.

**SCS** (section 9) answers: for this particular function, which context
changes could legitimately change its semantics? It is deliberately *not* the
compiler's real cache key - it is what the Python program itself implies, so
the method never has to reverse-engineer a framework's guard system.

**Test obligation** (section 10) answers: given that, what must be executed?

    TO = <Site, Factor, Constraint, Relation, Oracle>

Obligations then become contexts, so every context traces back to a reason
found in the program.
"""
from __future__ import annotations

from dataclasses import dataclass, field
from typing import Any, Dict, List, Optional, Sequence, Tuple

from .analysis import Analysis, analyze_source
from .case import Context

# factor kinds
SHAPE = "shape"
DTYPE = "dtype"
STRIDE = "stride"
CONTIGUOUS = "contiguous"
REQUIRES_GRAD = "requires_grad"
SCALAR = "scalar"
FLAG = "flag"


@dataclass
class SCS:
    """Semantic Context Signature - which context dimensions this function reads.

    Everything here was *observed in the source*. A function that never reads
    ``x.dtype`` and has no dtype-sensitive operation gets no dtype entry, and
    so is never probed along that axis - which is the whole point: the budget
    goes where the program says it might matter.
    """

    site: str
    params: List[str] = field(default_factory=list)
    #: (param, dim) shape positions the program branches on
    shape_dims: List[Tuple[str, Optional[int]]] = field(default_factory=list)
    #: params whose dtype the program reads or whose numerics depend on it
    dtypes: List[str] = field(default_factory=list)
    strides: List[str] = field(default_factory=list)
    contiguity: List[str] = field(default_factory=list)
    requires_grad: List[str] = field(default_factory=list)
    #: param -> concrete values worth covering
    scalars: Dict[str, List[Any]] = field(default_factory=dict)
    flags: Dict[str, List[Any]] = field(default_factory=dict)

    def is_empty(self) -> bool:
        return not (self.shape_dims or self.dtypes or self.strides
                    or self.contiguity or self.requires_grad
                    or self.scalars or self.flags)

    def as_dict(self) -> Dict[str, Any]:
        return {
            "site": self.site, "params": self.params,
            "shape_dims": [list(t) for t in self.shape_dims],
            "dtypes": self.dtypes, "strides": self.strides,
            "contiguity": self.contiguity, "requires_grad": self.requires_grad,
            "scalars": self.scalars, "flags": self.flags,
        }


@dataclass
class Obligation:
    """One thing the tests must cover, and why. Plan section 10."""

    site: str
    factor: str
    kind: str
    values: List[Any] = field(default_factory=list)
    relation: str = "change_only_one_factor"
    oracles: List[str] = field(default_factory=lambda: ["value", "metadata"])
    execution: List[str] = field(default_factory=lambda: ["cold"])
    #: the source evidence that produced this obligation
    origin: str = ""
    #: which parameter it acts on, and along which dimension
    param: Optional[str] = None
    dim: Optional[int] = None

    def as_dict(self) -> Dict[str, Any]:
        return {
            "site": self.site, "factor": self.factor, "kind": self.kind,
            "values": self.values, "relation": self.relation,
            "oracles": self.oracles, "execution": self.execution,
            "origin": self.origin, "param": self.param, "dim": self.dim,
        }


# --------------------------------------------------------------------------
# section 9: derive the signature
# --------------------------------------------------------------------------

def derive_scs(analysis: Analysis) -> SCS:
    """Read the signature out of the analysis. No guessing, no defaults."""
    scs = SCS(site=analysis.function, params=list(analysis.params))
    if analysis.error:
        return scs

    for b in analysis.boundaries:
        if b.param is None or b.param not in analysis.params:
            continue
        if b.kind == "shape":
            key = (b.param, b.dim)
            if key not in scs.shape_dims:
                scs.shape_dims.append(key)
        elif b.kind == "stride" and b.param not in scs.strides:
            scs.strides.append(b.param)
        elif b.kind == "scalar":
            scs.scalars.setdefault(b.param, [])
            for v in b.values:
                if v not in scs.scalars[b.param]:
                    scs.scalars[b.param].append(v)

    for fl in analysis.flags:
        scs.flags.setdefault(fl.param, [])
        for v in fl.values:
            if v not in scs.flags[fl.param]:
                scs.flags[fl.param].append(v)

    # attribute reads recorded by the analysis
    for f in analysis.factors:
        head = f.expr.split(".")[0].split("[")[0]
        if head not in analysis.params:
            continue
        if f.kind == "dtype" and head not in scs.dtypes:
            scs.dtypes.append(head)
        elif f.kind == "stride" and head not in scs.strides:
            scs.strides.append(head)
        elif f.kind == "contiguous" and head not in scs.contiguity:
            scs.contiguity.append(head)
        elif f.kind == "requires_grad" and head not in scs.requires_grad:
            scs.requires_grad.append(head)

    # An alias structure written through is layout-sensitive whether or not the
    # source mentions stride: a non-contiguous input changes what the compiler
    # must reason about, so contiguity enters the signature.
    if analysis.mutations and analysis.aliases:
        for p in analysis.params:
            if p not in scs.contiguity:
                scs.contiguity.append(p)

    return scs


# --------------------------------------------------------------------------
# section 10: turn the signature into obligations
# --------------------------------------------------------------------------

#: dtypes probed when the program's numerics could depend on precision
_DTYPE_LADDER = ["float16", "float64"]


def derive_obligations(analysis: Analysis, scs: Optional[SCS] = None,
                       include_default_dtype: bool = True) -> List[Obligation]:
    """Produce the obligations implied by a function's signature.

    ``include_default_dtype`` adds one dtype obligation even when the source
    never mentions dtype. That is a deliberate, declared exception: numerical
    behaviour depends on precision whether or not the program says so, and it
    is the canonical warm-cache probe. Everything else here is derived.
    """
    scs = scs or derive_scs(analysis)
    site = scs.site
    out: List[Obligation] = []

    for rel in analysis.index_relations:
        key = (rel.source_param, rel.source_dim)
        if key not in scs.shape_dims:
            scs.shape_dims.append(key)

    for param, dim in scs.shape_dims:
        vals = sorted({v for b in analysis.boundaries
                       if b.param == param and b.dim == dim and b.kind == "shape"
                       for v in b.values if v > 0})
        if not vals:
            continue
        origin = next((f"{b.expr} {b.op} {b.constant} (line {b.line})"
                       for b in analysis.boundaries
                       if b.param == param and b.dim == dim), "")
        out.append(Obligation(
            site=site, factor=f"{param}.shape[{dim}]", kind=SHAPE, values=vals,
            oracles=["value", "metadata"], execution=["cold"],
            origin=f"branch predicate {origin}", param=param, dim=dim))

    # Section 7: an index derived from a shape gives a boundary of its own -
    # the size at which that index stops being valid. These are usually
    # different from the sizes any branch predicate mentions.
    for rel in analysis.index_relations:
        sizes = rel.probe_sizes()
        key = (rel.source_param, rel.source_dim)
        already = {v for ob in out if ob.kind == SHAPE
                   and (ob.param, ob.dim) == key for v in ob.values}
        fresh = [s for s in sizes if s not in already]
        if not fresh:
            continue
        out.append(Obligation(
            site=site, factor=f"{rel.source_param}.shape[{rel.source_dim}]",
            kind=SHAPE, values=fresh,
            oracles=["value", "metadata", "exception"], execution=["cold"],
            origin=f"index relation {' -> '.join(rel.chain)}; {rel.constraint()}",
            param=rel.source_param, dim=rel.source_dim))

    for param, values in scs.flags.items():
        out.append(Obligation(
            site=site, factor=param, kind=FLAG, values=list(values),
            oracles=["value", "metadata", "exception"],
            execution=["cold", "warm_sequence"],
            origin="parameter steers control flow", param=param))

    for param, values in scs.scalars.items():
        if param in scs.flags:
            continue
        out.append(Obligation(
            site=site, factor=param, kind=SCALAR, values=list(values),
            oracles=["value"], execution=["cold", "warm_sequence"],
            origin="parameter compared against a constant", param=param))

    dtype_params = list(scs.dtypes)
    if include_default_dtype and not dtype_params and scs.params:
        dtype_params = [scs.params[0]]
    for param in dtype_params:
        out.append(Obligation(
            site=site, factor=f"{param}.dtype", kind=DTYPE,
            values=list(_DTYPE_LADDER), oracles=["value", "metadata"],
            execution=["cold", "warm_sequence"],
            origin=("dtype read in the source" if param in scs.dtypes
                    else "numerics depend on precision regardless of source"),
            param=param))

    for param in scs.contiguity:
        out.append(Obligation(
            site=site, factor=f"{param}.is_contiguous()", kind=CONTIGUOUS,
            values=[False], oracles=["value", "metadata", "alias", "mutation"],
            execution=["cold"],
            origin="alias structure is written through, so layout matters",
            param=param))

    for param in scs.requires_grad:
        out.append(Obligation(
            site=site, factor=f"{param}.requires_grad", kind=REQUIRES_GRAD,
            values=[True], oracles=["value", "metadata"],
            execution=["cold", "warm_sequence"],
            origin="requires_grad read in the source", param=param))

    return out


# --------------------------------------------------------------------------
# obligations -> contexts
# --------------------------------------------------------------------------

def obligations_to_contexts(obligations: Sequence[Obligation],
                            params: Sequence[str],
                            max_contexts: int = 12) -> List[Context]:
    """Turn obligations into executable contexts.

    Each context differs from the base in **exactly one** factor - plan section
    12 - so that a divergence is attributable, and ``Case.context_pairs`` can
    build the warm-cache sequences from them.
    """
    idx = {p: i for i, p in enumerate(params)}
    contexts: List[Context] = [Context("base", {"variant": "base"})]

    for ob in obligations:
        if ob.param is None or ob.param not in idx:
            continue
        pi = idx[ob.param]
        for v in ob.values:
            f: Dict[str, Any] = {"variant": "base"}
            name: str
            if ob.kind == SHAPE:
                f["resize"] = {"arg": pi, "dim": ob.dim or 0, "value": v}
                name = f"{ob.param}dim{ob.dim}_{v}"
            elif ob.kind == DTYPE:
                f["dtype"] = v
                name = f"dtype_{v}"
            elif ob.kind == CONTIGUOUS:
                f["variant"] = "noncontig"
                name = "noncontig"
            elif ob.kind == REQUIRES_GRAD:
                f["requires_grad"] = {"arg": pi, "value": bool(v)}
                name = f"{ob.param}_grad"
            elif ob.kind in (FLAG, SCALAR):
                f["substitute"] = {"arg": pi, "value": v}
                name = f"{ob.param}_{v}"
            else:
                continue
            if any(c.name == name for c in contexts):
                continue
            contexts.append(Context(name, f))
            if len(contexts) >= max_contexts:
                return contexts
    return contexts


def contexts_for_source(src: str, max_contexts: int = 12
                        ) -> Tuple[List[Context], SCS, List[Obligation]]:
    """The whole chain: source -> analysis -> SCS -> obligations -> contexts."""
    analysis = analyze_source(src)
    scs = derive_scs(analysis)
    obligations = derive_obligations(analysis, scs)
    return obligations_to_contexts(obligations, analysis.params, max_contexts), scs, obligations


def format_obligations(scs: SCS, obligations: Sequence[Obligation]) -> str:
    lines = [f"  SCS({scs.site}):"]
    for label, val in (("shape dims", scs.shape_dims), ("dtypes", scs.dtypes),
                       ("strides", scs.strides), ("contiguity", scs.contiguity),
                       ("requires_grad", scs.requires_grad),
                       ("scalars", scs.scalars), ("flags", scs.flags)):
        if val:
            lines.append(f"      {label:<15}: {val}")
    if scs.is_empty():
        lines.append("      (no context dimension is read by this function)")
    lines.append(f"  obligations ({len(obligations)}):")
    for ob in obligations:
        lines.append(f"      [{ob.kind:<13}] {ob.factor:<22} values={ob.values}")
        lines.append(f"      {'':<15}   exec={','.join(ob.execution)}  "
                     f"oracles={','.join(ob.oracles)}")
        lines.append(f"      {'':<15}   why: {ob.origin}")
    return "\n".join(lines)
