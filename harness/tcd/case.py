"""Test cases and the semantic contexts they are executed under.

A :class:`Case` is a compilable function plus a way to build fresh inputs for
each *semantic context*. A :class:`Context` names one point in the factor space
the plan cares about — dtype, shape, stride/contiguity, device, requires_grad,
Python scalars and flags.

**The one contract you must not break:** ``make_inputs`` has to return *newly
allocated* tensors on every call. The mutation oracle compares the caller's
inputs after the call, so a case that hands out the same tensor twice will see
the first run's in-place writes during the second and report a phantom
divergence.
"""
from __future__ import annotations

from dataclasses import dataclass, field
from typing import Any, Callable, Dict, List, Optional, Tuple

# expect values
CONSISTENT = "consistent"          # a real case: any divergence is a candidate bug
SELFCHECK_DIVERGE = "selfcheck_diverge"   # deliberately inconsistent, proves the oracle fires
SELFCHECK_SAME = "selfcheck_same"         # deliberately clean, proves we do not false-positive


@dataclass(frozen=True)
class Context:
    """One point in the semantic factor space."""

    name: str
    factors: Dict[str, Any] = field(default_factory=dict)

    def get(self, key: str, default: Any = None) -> Any:
        return self.factors.get(key, default)

    def differing_factors(self, other: "Context") -> List[str]:
        keys = set(self.factors) | set(other.factors)
        return sorted(k for k in keys if self.factors.get(k) != other.factors.get(k))

    def as_dict(self) -> Dict[str, Any]:
        return {"name": self.name, "factors": dict(self.factors)}


@dataclass
class Case:
    """A compilable function under test."""

    name: str
    fn: Callable
    make_inputs: Callable[[Context], Tuple[Any, ...]]
    contexts: List[Context]
    tags: List[str] = field(default_factory=list)
    notes: str = ""
    expect: str = CONSISTENT
    #: skip fp64 reference (ops with no float64 kernel on the target device)
    skip_fp64: bool = False
    #: source of ``fn``, for cases whose function was built by ``exec`` and so
    #: is invisible to ``inspect.getsource``. Structure mutation needs it.
    source: Optional[str] = None
    #: does the operator under test *promise* output-input aliasing? ``False``
    #: suppresses the alias oracle: an op whose schema declares no alias
    #: relation (``unsafe_chunk`` and friends) may legally return copies after
    #: compilation even though eager happens to return views.
    alias_contract: Optional[bool] = None
    #: O6: parameters whose gradients should be observed in addition to the
    #: inputs' - a module case exposes ``module.parameters()`` here. Called
    #: fresh for every execution so it always sees the live objects.
    parameters: Optional[Callable[[], Any]] = None

    def context_pairs(self) -> List[Tuple[Context, Context]]:
        """Ordered pairs differing in exactly one factor.

        These are the warm-cache probes: compile under A, then execute under B
        without a reset. Restricting to single-factor differences is what makes
        a divergence attributable.
        """
        pairs: List[Tuple[Context, Context]] = []
        for a in self.contexts:
            for b in self.contexts:
                if a is b:
                    continue
                if len(a.differing_factors(b)) == 1:
                    pairs.append((a, b))
        return pairs

    def as_dict(self) -> Dict[str, Any]:
        return {
            "name": self.name,
            "tags": list(self.tags),
            "notes": self.notes,
            "expect": self.expect,
            "contexts": [c.as_dict() for c in self.contexts],
        }


# --------------------------------------------------------------------------
# registry
# --------------------------------------------------------------------------

_REGISTRY: Dict[str, Case] = {}


def register(case: Case) -> Case:
    if case.name in _REGISTRY:
        raise ValueError(f"duplicate case name: {case.name}")
    _REGISTRY[case.name] = case
    return case


def get(name: str) -> Case:
    return _REGISTRY[name]


def all_cases(tag: Optional[str] = None, expect: Optional[str] = None) -> List[Case]:
    cases = list(_REGISTRY.values())
    if tag:
        cases = [c for c in cases if tag in c.tags]
    if expect:
        cases = [c for c in cases if c.expect == expect]
    return cases


def clear() -> None:
    _REGISTRY.clear()
