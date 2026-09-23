"""Plan sections 9 and 10: Semantic Context Signature and Test Obligations.

``SCS(f)`` lists the context dimensions that, *judging from the Python program
itself*, may legitimately change what the compiled artifact computes. It is
not the compiler's cache key and never has to be: it tells the generator
where to spend its budget without reverse-engineering the guard system.

A test obligation is ``TO = <Site, Factor, Constraint, Relation, Oracle>``;
each obligation says what must be executed and why, and turns into concrete
contexts that differ from the base context in exactly one factor.
"""
from __future__ import annotations

import json
from dataclasses import dataclass, field
from typing import Any, Dict, List, Optional, Sequence, Tuple

from .factors import Analysis, analyze_source
from .program import Context

SHAPE = "shape"
DTYPE = "dtype"
DEVICE = "device"
STRIDE = "stride"
CONTIGUOUS = "contiguous"
REQUIRES_GRAD = "requires_grad"
SCALAR = "scalar"
FLAG = "flag"
NONE = "none"
STRING = "string"
ENUM = "enum"
CONTAINER = "container"
COMPILE_FLAG = "compile_flag"
BACKEND = "backend"
RANK = "rank"

_DTYPE_LADDER = ["float16", "float64", "bfloat16"]


@dataclass
class SCS:
    site: str
    params: List[str] = field(default_factory=list)
    shape_dims: List[Tuple[str, Optional[int]]] = field(default_factory=list)
    ranks: List[str] = field(default_factory=list)
    dtypes: List[str] = field(default_factory=list)
    devices: List[str] = field(default_factory=list)
    strides: List[str] = field(default_factory=list)
    contiguity: List[str] = field(default_factory=list)
    requires_grad: List[str] = field(default_factory=list)
    scalars: Dict[str, List[Any]] = field(default_factory=dict)
    flags: Dict[str, List[Any]] = field(default_factory=dict)
    compile_flags: List[str] = field(default_factory=list)
    backends: List[str] = field(default_factory=list)
    #: derived facts that make alias/mutation oracles mandatory
    structural: List[str] = field(default_factory=list)

    def is_empty(self) -> bool:
        return not any([self.shape_dims, self.ranks, self.dtypes, self.devices, self.strides,
                        self.contiguity, self.requires_grad, self.scalars, self.flags,
                        self.compile_flags, self.backends])

    def entries(self) -> List[str]:
        out: List[str] = []
        out += [f"{p}.shape[{d}]" if d is not None else f"{p}.shape" for p, d in self.shape_dims]
        out += [f"{p}.ndim" for p in self.ranks]
        out += [f"{p}.dtype" for p in self.dtypes]
        out += [f"{p}.device" for p in self.devices]
        out += [f"{p}.stride" for p in self.strides]
        out += [f"{p}.is_contiguous()" for p in self.contiguity]
        out += [f"{p}.requires_grad" for p in self.requires_grad]
        out += [f"{p}" for p in self.scalars]
        out += [f"{p}" for p in self.flags]
        out += self.compile_flags + self.backends
        return out

    def as_dict(self) -> Dict[str, Any]:
        return {
            "site": self.site, "params": self.params,
            "shape_dims": [list(t) for t in self.shape_dims], "ranks": self.ranks,
            "dtypes": self.dtypes, "devices": self.devices, "strides": self.strides,
            "contiguity": self.contiguity, "requires_grad": self.requires_grad,
            "scalars": self.scalars, "flags": self.flags,
            "compile_flags": self.compile_flags, "backends": self.backends,
            "structural": self.structural, "entries": self.entries(),
        }


@dataclass
class Obligation:
    site: str
    factor: str
    kind: str
    values: List[Any] = field(default_factory=list)
    constraint: str = ""
    relation: str = "change_only_one_factor"
    oracles: List[str] = field(default_factory=lambda: ["value", "metadata"])
    execution: List[str] = field(default_factory=lambda: ["cold"])
    origin: str = ""
    param: Optional[str] = None
    dim: Optional[int] = None

    def as_dict(self) -> Dict[str, Any]:
        return {"site": self.site, "factor": self.factor, "kind": self.kind,
                "values": self.values, "constraint": self.constraint,
                "relation": self.relation, "oracles": self.oracles,
                "execution": self.execution, "origin": self.origin,
                "param": self.param, "dim": self.dim}


@dataclass
class DeriveOptions:
    """Which analyses feed the signature (RQ3 ablation levels toggle these)."""
    tensor_metadata: bool = True      # A1: dtype / contiguity / requires_grad reads
    flow_dependency: bool = True      # A2: flags and scalars from branch predicates
    shape_index: bool = True          # A3: boundaries and index relations
    alias_mutation: bool = True       # A4: structural facts -> mutation/alias oracles + layout
    scs_prune: bool = True            # A5: only factors in the SCS (else every dimension)
    cache_sequence: bool = True       # A6: warm sequences on every obligation
    include_default_dtype: bool = True
    include_default_requires_grad: bool = True
    include_compile_flags: bool = True


def derive_scs(a: Analysis, opt: Optional[DeriveOptions] = None) -> SCS:
    opt = opt or DeriveOptions()
    scs = SCS(site=a.function, params=list(a.params))
    if a.error:
        return scs

    if opt.shape_index:
        for b in a.boundaries:
            if b.param not in a.params:
                continue
            if b.kind == "shape" and (b.param, b.dim) not in scs.shape_dims:
                scs.shape_dims.append((b.param, b.dim))
            elif b.kind == "rank" and b.param not in scs.ranks:
                scs.ranks.append(b.param)
            elif b.kind == "stride" and b.param not in scs.strides:
                scs.strides.append(b.param)
            elif b.kind == "scalar":
                scs.scalars.setdefault(b.param, [])
                for v in b.values:
                    if v not in scs.scalars[b.param]:
                        scs.scalars[b.param].append(v)
        for r in a.index_relations:
            key = (r.source_param, r.source_dim)
            if key not in scs.shape_dims:
                scs.shape_dims.append(key)
        for f in a.factors:
            if f.kind == "shape" and f.in_branch and (f.param, f.dim) not in scs.shape_dims:
                scs.shape_dims.append((f.param, f.dim))
            if f.kind == "rank" and f.param not in scs.ranks:
                scs.ranks.append(f.param)

    if opt.flow_dependency:
        for s in a.scalars:
            if s.role in ("flag", "none_check", "string", "enum", "container"):
                scs.flags.setdefault(s.param, [])
                for v in s.values:
                    if v not in scs.flags[s.param]:
                        scs.flags[s.param].append(v)
            else:
                scs.scalars.setdefault(s.param, [])
                for v in s.values:
                    if v not in scs.scalars[s.param]:
                        scs.scalars[s.param].append(v)

    if opt.tensor_metadata:
        for f in a.factors:
            if f.param not in a.params:
                continue
            if f.kind == "dtype" and f.param not in scs.dtypes:
                scs.dtypes.append(f.param)
            elif f.kind == "device" and f.param not in scs.devices:
                scs.devices.append(f.param)
            elif f.kind == "stride" and f.param not in scs.strides:
                scs.strides.append(f.param)
            elif f.kind == "contiguous" and f.param not in scs.contiguity:
                scs.contiguity.append(f.param)
            elif f.kind == "requires_grad" and f.param not in scs.requires_grad:
                scs.requires_grad.append(f.param)
            elif f.kind == "layout" and f.param not in scs.contiguity:
                scs.contiguity.append(f.param)

    if opt.alias_mutation:
        if a.mutations or a.aliases:
            for p in a.params:
                ts = next((t for t in a.tensor_states if t.param == p), None)
                if ts and (ts.mutated or len(ts.alias_group) > 1) and p not in scs.contiguity:
                    scs.contiguity.append(p)
        scs.structural = [f.id + ":" + f.kind for f in a.facts]

    if opt.include_compile_flags:
        scs.compile_flags = ["dynamic"]
        scs.backends = ["aot_eager", "inductor"]
    return scs


def derive_obligations(a: Analysis, scs: Optional[SCS] = None,
                       opt: Optional[DeriveOptions] = None) -> List[Obligation]:
    opt = opt or DeriveOptions()
    scs = scs or derive_scs(a, opt)
    site = scs.site
    out: List[Obligation] = []
    warm = ["cold", "warm_sequence"] if opt.cache_sequence else ["cold"]
    struct_oracles = ["mutation", "alias"] if (opt.alias_mutation and a.facts) else []

    # shape boundaries (6.3) and index-derived sizes (7)
    for param, dim in scs.shape_dims:
        vals: List[int] = []
        for b in a.boundaries:
            if b.param == param and b.dim == dim and b.kind == "shape":
                vals += [v for v in b.values if v > 0 and v not in vals]   # analysis order: k, k+1, k-1
        origin = "; ".join(f"{b.expr} {b.op} {b.constant} (line {b.line})" for b in a.boundaries
                           if b.param == param and b.dim == dim and b.kind == "shape")
        for r in a.index_relations:
            if (r.source_param, r.source_dim) == (param, dim):
                vals += [v for v in r.probe_sizes() if v not in vals]
                origin += ("; " if origin else "") + f"index relation {' -> '.join(r.chain)}"
        if not vals:
            # read in a branch but no constant: probe 1 / 2 / 33 to change the predicate
            vals = [1, 2, 33]
            origin = origin or "shape read inside a branch predicate"
        # shape changes are guarded by every compiler; cold probes at the boundary
        # values are the plan's example for this obligation (section 10)
        out.append(Obligation(site, f"{param}.shape[{dim}]", SHAPE, vals,
                              constraint=origin, oracles=["value", "metadata", "exception"] + struct_oracles,
                              execution=["cold"], origin=f"branch/index predicate: {origin}",
                              param=param, dim=dim if dim is not None else 0))

    for param in scs.ranks:
        out.append(Obligation(site, f"{param}.ndim", RANK, ["+1", "-1"],
                              constraint="rank read in a predicate", oracles=["value", "metadata", "exception"],
                              execution=["cold"], origin="rank steers control flow", param=param))

    # python flags / scalars (6.2)
    for param, values in scs.flags.items():
        out.append(Obligation(site, param, FLAG, list(values), constraint="T/F both paths",
                              oracles=["value", "metadata", "exception"] + struct_oracles,
                              execution=warm, origin="parameter steers control flow", param=param))
    for param, values in scs.scalars.items():
        if param in scs.flags:
            continue
        out.append(Obligation(site, param, SCALAR, list(values), constraint="boundary +-1",
                              oracles=["value", "exception"], execution=warm,
                              origin="parameter compared against a constant / used as index or bound",
                              param=param))

    # dtype
    dtype_params = list(scs.dtypes)
    if opt.include_default_dtype and not dtype_params and a.params:
        dtype_params = [a.params[0]]
    for param in dtype_params:
        out.append(Obligation(site, f"{param}.dtype", DTYPE, list(_DTYPE_LADDER),
                              constraint="float dtype ladder", oracles=["value", "metadata"] + struct_oracles,
                              execution=warm,
                              origin=("dtype read in the source" if param in scs.dtypes
                                      else "numerics depend on precision regardless of source"),
                              param=param))

    for param in scs.contiguity:
        out.append(Obligation(site, f"{param}.is_contiguous()", CONTIGUOUS, ["noncontig", "transposed"],
                              constraint="layout variants with identical values",
                              oracles=["value", "metadata", "alias", "mutation"], execution=warm,
                              origin="layout read, or alias structure is written through", param=param))
    for param in scs.strides:
        if param not in scs.contiguity:
            out.append(Obligation(site, f"{param}.stride", STRIDE, ["noncontig", "transposed"],
                                  constraint="stride variants", oracles=["value", "metadata"],
                                  execution=warm, origin="stride read in the source", param=param))
    grad_params = list(scs.requires_grad)
    if opt.include_default_requires_grad and opt.tensor_metadata and not grad_params and a.params:
        grad_params = [a.params[0]]
    for param in grad_params:
        out.append(Obligation(site, f"{param}.requires_grad", REQUIRES_GRAD, [True, False],
                              constraint="grad on/off", oracles=["value", "metadata", "gradient"],
                              execution=warm,
                              origin=("requires_grad read in the source" if param in scs.requires_grad
                                      else "requires_grad changes the traced graph regardless of source"),
                              param=param))
    for param in scs.devices:
        out.append(Obligation(site, f"{param}.device", DEVICE, ["cpu", "cuda"],
                              constraint="device switch", oracles=["value", "metadata", "exception"],
                              execution=warm, origin="device read in the source", param=param))

    if opt.include_compile_flags:
        out.append(Obligation(site, "compile.dynamic", COMPILE_FLAG, [True, False],
                              constraint="dynamic shapes on/off", oracles=["value", "metadata"],
                              execution=["cold"], origin="compile flag changes specialization"))

    if not opt.scs_prune:
        # exhaustive factor enumeration: every family on every parameter, whether or
        # not the program reads it (the A0-A4 ablation baseline of RQ3)
        have = {(o.kind, o.param) for o in out}
        for p in a.params:
            if (DTYPE, p) not in have:
                out.append(Obligation(site, f"{p}.dtype", DTYPE, list(_DTYPE_LADDER), constraint="enumerated",
                                      execution=warm, origin="exhaustive enumeration (no SCS pruning)", param=p))
            if (CONTIGUOUS, p) not in have and (STRIDE, p) not in have:
                out.append(Obligation(site, f"{p}.is_contiguous()", CONTIGUOUS, ["noncontig", "transposed"],
                                      constraint="enumerated", execution=warm,
                                      origin="exhaustive enumeration (no SCS pruning)", param=p))
            if (REQUIRES_GRAD, p) not in have:
                out.append(Obligation(site, f"{p}.requires_grad", REQUIRES_GRAD, [True, False],
                                      constraint="enumerated", oracles=["value", "gradient"], execution=warm,
                                      origin="exhaustive enumeration (no SCS pruning)", param=p))
            if (SHAPE, p) not in have:
                out.append(Obligation(site, f"{p}.shape[0]", SHAPE, [1, 2, 33], constraint="enumerated",
                                      execution=["cold"], origin="exhaustive enumeration (no SCS pruning)",
                                      param=p, dim=0))
            if (FLAG, p) not in have and (SCALAR, p) not in have:
                out.append(Obligation(site, p, FLAG, [True, False, 0, 1, None], constraint="enumerated",
                                      execution=warm, origin="exhaustive enumeration (no SCS pruning)", param=p))
    return out


def combination_contexts(a: Analysis, obligations: Sequence[Obligation], params: Sequence[str],
                         base: Optional[Context] = None, max_extra: int = 8) -> List[Context]:
    """Plan experiment C: predicates such as ``flag and x.shape[0] > 32`` need the
    full T/T, T/F, F/T, F/F table, which single-factor contexts cannot reach.
    For each predicate that reads two factors, combine their obligation values
    pairwise (still only two factors away from the base, and both traceable)."""
    base = base or Context("base", {})
    idx = {p: i for i, p in enumerate(params)}
    out: List[Context] = []
    by_param: Dict[str, List[Obligation]] = {}
    for ob in obligations:
        if ob.param:
            by_param.setdefault(ob.param, []).append(ob)
    for group in getattr(a, "predicate_groups", []):
        names = [n for n in group if n in by_param]
        if len(names) < 2:
            continue
        p1, p2 = names[0], names[1]
        for o1 in by_param[p1][:1]:
            for o2 in by_param[p2][:1]:
                # the first two values of every obligation straddle its predicate,
                # so 2 x 2 is exactly the T/T, T/F, F/T, F/F table
                for v1 in o1.values[:2]:
                    for v2 in o2.values[:2]:
                        f = dict(base.factors)
                        parts = []
                        for ob, v in ((o1, v1), (o2, v2)):
                            pi = idx.get(ob.param)
                            if pi is None:
                                continue
                            if ob.kind == SHAPE:
                                f["resize"] = {"arg": pi, "dim": ob.dim or 0, "value": int(v)}
                                parts.append(f"{ob.param}.dim{ob.dim}={v}")
                            elif ob.kind in (FLAG, SCALAR) and not isinstance(v, str):
                                f["substitute"] = {"arg": pi, "value": v}
                                parts.append(f"{ob.param}={v}")
                            elif ob.kind == DTYPE:
                                f["dtype"] = v
                                parts.append(f"dtype={v}")
                        if len(parts) == 2:
                            out.append(Context("+".join(parts), f, warm=False,
                                               origin=f"{o1.factor} x {o2.factor}"))
                        if len(out) >= max_extra:
                            return out
    return out


# --------------------------------------------------------------------------
# obligations -> contexts (each differs from base in exactly one factor)
# --------------------------------------------------------------------------

def obligations_to_contexts(obligations: Sequence[Obligation], params: Sequence[str],
                            base: Optional[Context] = None, max_contexts: int = 16) -> List[Context]:
    base = base or Context("base", {})
    idx = {p: i for i, p in enumerate(params)}
    contexts: List[Context] = [base]
    names = {base.name}

    def add(name: str, factors: Dict[str, Any], ob: Obligation) -> None:
        if name in names or len(contexts) >= max_contexts:
            return
        f = dict(base.factors)
        f.update(factors)
        contexts.append(Context(name, f, warm="warm_sequence" in ob.execution, origin=ob.factor))
        names.add(name)

    # round-robin over obligations: the first value of every factor before the
    # second value of any, so a small budget still touches each factor once
    longest = max((len(ob.values) for ob in obligations), default=0)
    for j in range(longest):
        for ob in obligations:
            if j >= len(ob.values):
                continue
            v = ob.values[j]
            pi = idx.get(ob.param) if ob.param else None
            item = _context_for(ob, v, pi)
            if item is not None:
                add(item[0], item[1], ob)
    return contexts


def _context_for(ob: Obligation, v: Any, pi: Optional[int]) -> Optional[Tuple[str, Dict[str, Any]]]:
    """(context name, structured factors) for one obligation value, or None."""
    if ob.kind == SHAPE and pi is not None:
        return f"{ob.param}.dim{ob.dim}={v}", {"resize": {"arg": pi, "dim": ob.dim or 0, "value": int(v)}}
    if ob.kind == DTYPE:
        return f"dtype={v}", {"dtype": v}
    if ob.kind in (CONTIGUOUS, STRIDE):
        return f"layout={v}", {"layout": v}
    if ob.kind == REQUIRES_GRAD and pi is not None:
        return f"{ob.param}.grad={v}", {"requires_grad": {"arg": pi, "value": bool(v)}}
    if ob.kind in (FLAG, SCALAR) and pi is not None:
        if isinstance(v, str) and (v.startswith("not:") or v == "<non-None>" or v in ("in", "not-in")):
            return None  # symbolic values need a seed-specific substitute
        return f"{ob.param}={v}", {"substitute": {"arg": pi, "value": v}}
    if ob.kind == DEVICE:
        return f"device={v}", {"device": v}
    if ob.kind == COMPILE_FLAG:
        return f"compile.dynamic={v}", {"compile": {"dynamic": bool(v)}}
    if ob.kind == RANK and pi is not None:
        return f"{ob.param}.ndim{v}", {"rank": {"arg": pi, "delta": 1 if v == "+1" else -1}}
    return None


def plan_for_source(src: str, base: Optional[Context] = None, max_contexts: int = 16,
                    opt: Optional[DeriveOptions] = None
                    ) -> Tuple[Analysis, SCS, List[Obligation], List[Context]]:
    a = analyze_source(src)
    scs = derive_scs(a, opt)
    obs = derive_obligations(a, scs, opt)
    return a, scs, obs, obligations_to_contexts(obs, a.params, base, max_contexts)


# --------------------------------------------------------------------------
# rendering (YAML per plan section 10; no PyYAML dependency)
# --------------------------------------------------------------------------

def _yaml_scalar(v: Any) -> str:
    if v is None:
        return "null"
    if isinstance(v, bool):
        return "true" if v else "false"
    if isinstance(v, (int, float)):
        return str(v)
    s = str(v)
    if any(c in s for c in ":#{}[],&*?|<>=!%@`'\"") or s.strip() != s or not s:
        return json.dumps(s)
    return s


def obligations_to_yaml(obligations: Sequence[Obligation]) -> str:
    L: List[str] = []
    for ob in obligations:
        L.append(f"- site: {_yaml_scalar(ob.site)}")
        L.append(f"  factor: {_yaml_scalar(ob.factor)}")
        L.append(f"  kind: {ob.kind}")
        L.append(f"  relation: {ob.relation}")
        if ob.constraint:
            L.append(f"  constraint: {_yaml_scalar(ob.constraint)}")
        L.append("  values:")
        for v in ob.values:
            L.append(f"    - {_yaml_scalar(v)}")
        L.append("  oracle:")
        for o in ob.oracles:
            L.append(f"    - {o}")
        L.append("  execution:")
        for e in ob.execution:
            L.append(f"    - {e}")
        L.append(f"  origin: {_yaml_scalar(ob.origin)}")
    return "\n".join(L) + "\n"


def format_obligations(scs: SCS, obligations: Sequence[Obligation]) -> str:
    L = [f"  SCS({scs.site}) = {{"]
    for e in scs.entries():
        L.append(f"      {e},")
    if scs.structural:
        L.append(f"      structural: {scs.structural},")
    L.append("  }")
    L.append(f"  obligations ({len(obligations)}):")
    for ob in obligations:
        L.append(f"      [{ob.kind:<13}] {ob.factor:<24} values={ob.values}")
        L.append(f"      {'':<15}   exec={','.join(ob.execution)}  oracles={','.join(ob.oracles)}")
        L.append(f"      {'':<15}   why: {ob.origin}")
    return "\n".join(L)
