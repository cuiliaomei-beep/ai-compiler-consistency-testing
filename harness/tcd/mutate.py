"""Structure mutation operators - the method's differentiating step.

The measured gap this exists to close: on a 77-bug torch.compile benchmark,
five state-of-the-art tools detect 6 of 22 memory-related bugs, and the stated
reason is that every in-place *operator* is already covered, but the tools
"fail to synthesise the complex, bug-triggering usage patterns" — the bugs
need those operators applied to **tensor aliases and views constructed via
under-explored patterns**.

LLM-driven mutation samples such patterns. This enumerates them: the static
analysis in :mod:`tcd.analysis` reads the alias/view/mutation structure out of
the program, and the operators here systematically perturb *that structure*
while leaving the computation alone.

**The gate that makes any of this meaningful:** a mutant must not change eager
semantics. If it does, a later eager-vs-compiled divergence is the mutant's
fault, not the compiler's. :func:`validate_mutants` runs that check and
discards the ones that fail — a mutant that alters the reference is not a test,
it is a bug in the test generator.
"""
from __future__ import annotations

import ast
import copy
import inspect
from dataclasses import dataclass, field
from typing import Any, Callable, Dict, List, Optional, Set, Tuple

from .analysis import VIEW_METHODS, _is_inplace_method, analyze_source
from .case import Case, Context

# operator names, as reported by tcd.analysis.Analysis.operators
DEEPEN_VIEW = "DeepenView"
ALIAS_BRANCH = "AliasBranch"
REORDER_MUTATION = "ReorderMutation"
ALIAS_MUTATION = "AliasMutation"
ESCAPE_ALIAS = "EscapeAlias"
NONCONTIGUOUS = "NonContiguous"   # an input transform, applied via Context
# introduction operators: they create alias structure where there was none
INTRODUCE_VIEW = "IntroduceView"
INTRODUCE_ALIAS_WRITE = "IntroduceAliasWrite"
# value-changing operators: only valid in the free-mutation regime
REAL_ALIAS_WRITE = "RealAliasWrite"
CROSS_VIEW_WRITE = "CrossViewWrite"


@dataclass
class Mutant:
    operator: str
    source: str
    description: str
    origin: str = ""
    #: set by validate_mutants
    valid: Optional[bool] = None
    invalid_reason: str = ""

    def as_dict(self) -> Dict[str, Any]:
        return {
            "operator": self.operator, "description": self.description,
            "origin": self.origin, "valid": self.valid,
            "invalid_reason": self.invalid_reason, "source": self.source,
        }


# --------------------------------------------------------------------------
# AST helpers
# --------------------------------------------------------------------------

def _fn_node(src: str) -> Optional[ast.FunctionDef]:
    try:
        tree = ast.parse(src)
    except SyntaxError:
        return None
    for n in tree.body:
        if isinstance(n, (ast.FunctionDef, ast.AsyncFunctionDef)):
            return n  # type: ignore[return-value]
    return None


def _method_call(recv: ast.expr, name: str, *args: ast.expr) -> ast.Call:
    return ast.Call(func=ast.Attribute(value=recv, attr=name, ctx=ast.Load()),
                    args=list(args), keywords=[])


def _const(v: Any) -> ast.Constant:
    return ast.Constant(value=v)


def _render(fn: ast.FunctionDef) -> str:
    mod = ast.Module(body=[fn], type_ignores=[])
    ast.fix_missing_locations(mod)
    return ast.unparse(mod)


def _is_inplace_stmt(node: ast.stmt) -> bool:
    if isinstance(node, ast.Expr) and isinstance(node.value, ast.Call):
        f = node.value.func
        return isinstance(f, ast.Attribute) and _is_inplace_method(f.attr)
    return isinstance(node, ast.AugAssign)


def _inplace_receiver(node: ast.stmt) -> Optional[ast.expr]:
    if isinstance(node, ast.Expr) and isinstance(node.value, ast.Call):
        f = node.value.func
        if isinstance(f, ast.Attribute):
            return f.value
    return None


# --------------------------------------------------------------------------
# the operators
# --------------------------------------------------------------------------

def op_deepen_view(src: str) -> List[Mutant]:
    """Route a view through a longer identity chain.

    ``x.view(-1)`` becomes ``x.view(-1).unsqueeze(0).squeeze(0)`` — the same
    tensor, reached through more view nodes. Stride and storage-offset
    reasoning has to survive the extra hops.
    """
    out: List[Mutant] = []
    base = _fn_node(src)
    if base is None:
        return out

    targets = [n for n in ast.walk(base)
               if isinstance(n, ast.Call) and isinstance(n.func, ast.Attribute)
               and n.func.attr in VIEW_METHODS]
    for k in range(len(targets)):
        fn = copy.deepcopy(base)
        hits = [n for n in ast.walk(fn)
                if isinstance(n, ast.Call) and isinstance(n.func, ast.Attribute)
                and n.func.attr in VIEW_METHODS]
        if k >= len(hits):
            continue
        victim = hits[k]

        class _Wrap(ast.NodeTransformer):
            def visit_Call(self, node: ast.Call) -> ast.AST:
                self.generic_visit(node)
                if node is victim:
                    return _method_call(_method_call(node, "unsqueeze", _const(0)),
                                        "squeeze", _const(0))
                return node

        fn = _Wrap().visit(fn)
        out.append(Mutant(
            DEEPEN_VIEW, _render(fn),
            f"view #{k} routed through unsqueeze(0).squeeze(0)",
            origin=f"view call #{k}",
        ))
    return out


def op_alias_mutation(src: str) -> List[Mutant]:
    """Retarget an in-place write through a full-slice view of the receiver.

    ``x.add_(1)`` becomes ``x[:].add_(1)``: the same elements are written, but
    the write now goes through a view. Functionalization has to prove those are
    the same storage.
    """
    out: List[Mutant] = []
    base = _fn_node(src)
    if base is None:
        return out

    n_stmts = sum(1 for n in ast.walk(base) if _is_inplace_stmt(n))
    for k in range(n_stmts):
        fn = copy.deepcopy(base)
        seen = [0]

        class _Retarget(ast.NodeTransformer):
            def visit_Expr(self, node: ast.Expr) -> ast.AST:
                if _is_inplace_stmt(node):
                    idx = seen[0]
                    seen[0] += 1
                    if idx == k and isinstance(node.value, ast.Call):
                        f = node.value.func
                        if isinstance(f, ast.Attribute):
                            f.value = ast.Subscript(
                                value=f.value,
                                slice=ast.Slice(lower=None, upper=None, step=None),
                                ctx=ast.Load())
                return node

        fn = _Retarget().visit(fn)
        rendered = _render(fn)
        if rendered != _render(base):
            out.append(Mutant(
                ALIAS_MUTATION, rendered,
                f"in-place write #{k} retargeted through a full-slice view",
                origin=f"in-place stmt #{k}",
            ))
    return out


def op_alias_branch(src: str) -> List[Mutant]:
    """Add a second, overlapping view of a base that is already mutated.

    The extra view is touched with an identity in-place op (``add_(0)``), so
    values are unchanged while the compiler must now track two live aliases of
    the same storage across the write.
    """
    out: List[Mutant] = []
    base = _fn_node(src)
    if base is None:
        return out

    for i, stmt in enumerate(base.body):
        if not _is_inplace_stmt(stmt):
            continue
        recv = _inplace_receiver(stmt)
        if recv is None:
            continue
        fn = copy.deepcopy(base)
        alias_name = "_tcd_alias"
        mk = ast.Assign(
            targets=[ast.Name(id=alias_name, ctx=ast.Store())],
            value=ast.Subscript(value=copy.deepcopy(recv),
                                slice=ast.Slice(None, None, None), ctx=ast.Load()))
        touch = ast.Expr(value=_method_call(
            ast.Name(id=alias_name, ctx=ast.Load()), "add_", _const(0)))
        fn.body[i:i] = [mk, touch]
        out.append(Mutant(
            ALIAS_BRANCH, _render(fn),
            f"a second overlapping view of the receiver is created and touched "
            f"with an identity write, before in-place statement #{i}",
            origin=f"stmt #{i}",
        ))
    return out


def op_reorder_mutation(src: str) -> List[Mutant]:
    """Swap two adjacent in-place statements.

    Only correct when the two writes are disjoint, which we cannot prove
    statically — so this operator deliberately produces *candidate* mutants and
    relies on :func:`validate_mutants` to throw away the ones that change eager
    behaviour. The survivors are exactly the reorderings the compiler must also
    preserve.
    """
    out: List[Mutant] = []
    base = _fn_node(src)
    if base is None:
        return out
    for i in range(len(base.body) - 1):
        if _is_inplace_stmt(base.body[i]) and _is_inplace_stmt(base.body[i + 1]):
            fn = copy.deepcopy(base)
            fn.body[i], fn.body[i + 1] = fn.body[i + 1], fn.body[i]
            out.append(Mutant(
                REORDER_MUTATION, _render(fn),
                f"in-place statements #{i} and #{i + 1} swapped",
                origin=f"stmts #{i},#{i + 1}",
            ))
    return out


def op_escape_alias(src: str) -> List[Mutant]:
    """Let a view escape into a container that outlives the call.

    An alias stashed in a module-level list cannot be optimised away, so the
    compiler must keep it consistent with the tensor it views.
    """
    out: List[Mutant] = []
    base = _fn_node(src)
    if base is None:
        return out

    names: List[str] = []
    for stmt in base.body:
        if isinstance(stmt, ast.Assign) and len(stmt.targets) == 1 \
                and isinstance(stmt.targets[0], ast.Name):
            v = stmt.value
            if (isinstance(v, ast.Call) and isinstance(v.func, ast.Attribute)
                    and v.func.attr in VIEW_METHODS) or isinstance(v, ast.Subscript):
                names.append(stmt.targets[0].id)

    for name in names[:2]:
        fn = copy.deepcopy(base)
        idx = next((i for i, s in enumerate(fn.body)
                    if isinstance(s, ast.Assign) and len(s.targets) == 1
                    and isinstance(s.targets[0], ast.Name)
                    and s.targets[0].id == name), None)
        if idx is None:
            continue
        stash = ast.Expr(value=_method_call(
            ast.Name(id="_TCD_ESCAPED", ctx=ast.Load()), "append",
            ast.Name(id=name, ctx=ast.Load())))
        fn.body.insert(idx + 1, stash)
        out.append(Mutant(
            ESCAPE_ALIAS, _render(fn),
            f"the view `{name}` escapes into a module-level container",
            origin=name,
        ))
    return out


_ALIAS_PREFIX = "_tcd_v"


def _existing_aliases(fn: ast.FunctionDef) -> List[str]:
    """Alias variables this operator has already introduced, in order."""
    found: List[str] = []
    for node in ast.walk(fn):
        if isinstance(node, ast.Name) and node.id.startswith(_ALIAS_PREFIX):
            if node.id not in found:
                found.append(node.id)
    return sorted(found)


def _layer_view(base_expr: ast.expr, level: int) -> ast.expr:
    """A different view shape at each depth, so layers are not redundant.

    Composition is only worth anything if each application adds structure the
    previous one did not: alternating a full slice, a strided slice and an
    unsqueeze/squeeze round-trip produces layered views with differing strides
    and offsets, which is the structure the targeted bug class needs.
    """
    kind = level % 3
    if kind == 0:
        return ast.Subscript(value=base_expr, slice=ast.Slice(None, None, None),
                             ctx=ast.Load())
    if kind == 1:
        return ast.Subscript(value=base_expr,
                             slice=ast.Slice(None, None, _const(2)), ctx=ast.Load())
    return _method_call(_method_call(base_expr, "unsqueeze", _const(0)),
                        "squeeze", _const(0))


def op_introduce_view(src: str) -> List[Mutant]:
    """Make each parameter reach the body through a view.

    ``def f(x): ...`` becomes ``def f(x): x = x[:]; ...`` — the same values,
    now behind an alias. The operators above can only *perturb* existing
    alias structure, and most real reproducers are purely functional
    (``full_like``, ``interpolate``), so without this the targeted bug class
    has nothing to act on. Introduction is what makes the class reachable
    from an arbitrary program.
    """
    out: List[Mutant] = []
    base = _fn_node(src)
    if base is None:
        return out
    params = [a.arg for a in base.args.args]
    for name in params:
        # How many times has this parameter already been rebound? Each further
        # application uses a different view shape, so a chain deepens the view
        # instead of repeating one line.
        level = 0
        for stmt in base.body:
            if (isinstance(stmt, ast.Assign) and len(stmt.targets) == 1
                    and isinstance(stmt.targets[0], ast.Name)
                    and stmt.targets[0].id == name):
                level += 1
            else:
                break

        fn = copy.deepcopy(base)
        rebind = ast.Assign(
            targets=[ast.Name(id=name, ctx=ast.Store())],
            value=_layer_view(ast.Name(id=name, ctx=ast.Load()), level))
        fn.body.insert(level, rebind)
        out.append(Mutant(
            INTRODUCE_VIEW, _render(fn),
            f"parameter `{name}` rebound to a depth-{level} view of itself",
            origin=name,
        ))
    return out


def op_introduce_alias_write(src: str) -> List[Mutant]:
    """Add an identity in-place write through a view of a parameter.

    ``_v = x[:]; _v.add_(0)`` changes nothing observable, but forces
    functionalization to reason about a live alias that is written through —
    the exact shape of the memory-related bugs existing tools miss.
    """
    out: List[Mutant] = []
    base = _fn_node(src)
    if base is None:
        return out

    # Layering, not repetition: each application takes its view *of the
    # previous alias* with a different view shape. Rebinding one name to the
    # same full slice three times is redundant code, and composition would buy
    # nothing.
    existing = _existing_aliases(base)
    level = len(existing)
    alias = f"{_ALIAS_PREFIX}{level}"
    sources = [existing[-1]] if existing else [a.arg for a in base.args.args]

    for name in sources:
        fn = copy.deepcopy(base)
        mk = ast.Assign(
            targets=[ast.Name(id=alias, ctx=ast.Store())],
            value=_layer_view(ast.Name(id=name, ctx=ast.Load()), level))
        touch = ast.Expr(value=_method_call(
            ast.Name(id=alias, ctx=ast.Load()), "add_", _const(0)))
        at = 0
        for i, s in enumerate(fn.body):
            if _is_inplace_stmt(s):
                at = i + 1
        fn.body[at:at] = [mk, touch]
        out.append(Mutant(
            INTRODUCE_ALIAS_WRITE, _render(fn),
            f"identity in-place write through a depth-{level} view of `{name}`",
            origin=name,
        ))
    return out


def op_real_alias_write(src: str) -> List[Mutant]:
    """An in-place write through a view that actually changes values.

    The identity-write operators exist because a semantics-preserving mutant
    must not change anything - but ``add_(0)`` is the case a compiler handles
    most easily: it is either folded away or passed through. A write that
    genuinely modifies the tensor is what forces functionalization to insert
    copies, order the write against the read, and keep the view in sync.

    Only usable in the free-mutation regime, where each mutant is tested
    against its own eager reference rather than the original's.
    """
    out: List[Mutant] = []
    base = _fn_node(src)
    if base is None:
        return out

    existing = _existing_aliases(base)
    level = len(existing)
    alias = f"{_ALIAS_PREFIX}{level}"
    sources = [existing[-1]] if existing else [a.arg for a in base.args.args]

    for name in sources:
        fn = copy.deepcopy(base)
        mk = ast.Assign(
            targets=[ast.Name(id=alias, ctx=ast.Store())],
            value=_layer_view(ast.Name(id=name, ctx=ast.Load()), level))
        # Scale *down*, never up. Many operators have a restricted domain -
        # asin/acos accept [-1, 1], atanh accepts (-1, 1) - so doubling a valid
        # input pushes it outside and yields NaN. The whole output then becomes
        # noise, and every such operator turns into a false candidate.
        # Halving stays inside any domain that contains the original input.
        write = ast.Expr(value=_method_call(
            ast.Name(id=alias, ctx=ast.Load()), "mul_", _const(0.5)))
        at = 0
        for i, s in enumerate(fn.body):
            if _is_inplace_stmt(s):
                at = i + 1
        fn.body[at:at] = [mk, write]
        out.append(Mutant(
            REAL_ALIAS_WRITE, _render(fn),
            f"value-changing in-place write (mul_ 0.5) through a depth-{level} "
            f"view of `{name}`",
            origin=name,
        ))
    return out


def op_cross_view_write(src: str) -> List[Mutant]:
    """Write one region of a tensor from another region of the same tensor.

    ``x[:k] = x[k:2k]`` reads and writes overlapping storage in one statement.
    Getting this right requires the compiler to know the read must complete
    before the write, which is exactly the ordering constraint that
    functionalization has to reconstruct.
    """
    out: List[Mutant] = []
    base = _fn_node(src)
    if base is None:
        return out

    for name in [a.arg for a in base.args.args][:2]:
        fn = copy.deepcopy(base)
        src_view = ast.Subscript(
            value=ast.Name(id=name, ctx=ast.Load()),
            slice=ast.Slice(lower=_const(1), upper=None, step=None), ctx=ast.Load())
        dst_view = ast.Subscript(
            value=ast.Name(id=name, ctx=ast.Load()),
            slice=ast.Slice(lower=None, upper=_const(-1), step=None), ctx=ast.Load())
        stmt = ast.Expr(value=_method_call(dst_view, "copy_", src_view))
        fn.body.insert(0, stmt)
        out.append(Mutant(
            CROSS_VIEW_WRITE, _render(fn),
            f"`{name}[:-1]` is written from `{name}[1:]` - overlapping read and "
            f"write on one storage",
            origin=name,
        ))
    return out


OPERATORS: Dict[str, Callable[[str], List[Mutant]]] = {
    DEEPEN_VIEW: op_deepen_view,
    ALIAS_MUTATION: op_alias_mutation,
    ALIAS_BRANCH: op_alias_branch,
    REORDER_MUTATION: op_reorder_mutation,
    ESCAPE_ALIAS: op_escape_alias,
    INTRODUCE_VIEW: op_introduce_view,
    INTRODUCE_ALIAS_WRITE: op_introduce_alias_write,
    REAL_ALIAS_WRITE: op_real_alias_write,
    CROSS_VIEW_WRITE: op_cross_view_write,
}

#: applicable to any function with a tensor parameter, so they are not gated on
#: the static analysis having found existing structure
ALWAYS_APPLICABLE = {INTRODUCE_VIEW, INTRODUCE_ALIAS_WRITE}

#: these change values, so they are only offered when mutants are tested
#: against their own eager reference rather than the original's
VALUE_CHANGING = {REAL_ALIAS_WRITE, CROSS_VIEW_WRITE}


# --------------------------------------------------------------------------
# generation + validation
# --------------------------------------------------------------------------

def _case_source(case: Case) -> Optional[str]:
    if case.source:
        return case.source
    try:
        return inspect.getsource(case.fn)
    except (OSError, TypeError):
        # functions built by exec (imported seeds, OpInfo cases) have no
        # retrievable source unless the case carries it
        return None


def _apply_once(src: str, operators: Optional[List[str]] = None,
                extra: Optional[set] = None) -> List[Mutant]:
    """One round of mutation over a source string."""
    analysis = analyze_source(src)
    applicable = set(operators) if operators else \
        (set(analysis.operators) | ALWAYS_APPLICABLE)
    if extra:
        applicable |= set(extra)

    out: List[Mutant] = []
    for name, fn in OPERATORS.items():
        if name not in applicable:
            continue
        try:
            out.extend(fn(src))
        except Exception:
            continue
    return out


def generate(case: Case, operators: Optional[List[str]] = None,
             depth: int = 1, max_per_depth: int = 24,
             allow_value_changing: bool = False) -> List[Mutant]:
    """Produce structural variants, optionally composing operators.

    ``depth=1`` applies one operator. Higher depths feed each mutant back
    through the operator set, so ``IntroduceView`` followed by
    ``DeepenView`` followed by ``AliasBranch`` builds a layered alias
    structure that no single operator reaches.

    Depth is the dial that matters for the targeted bug class. PyTorch's own CI
    already runs every OpInfo operator through Inductor, so single-operator
    variants of those programs are close to pre-tested ground; the unexplored
    region is *composed* structure - which is what "complex tensor aliases or
    views constructed via under-explored patterns" names.

    ``max_per_depth`` caps the fan-out, because composition multiplies.
    """
    src = _case_source(case)
    if not src:
        return []
    extra = VALUE_CHANGING if allow_value_changing else set()

    frontier: List[Tuple[str, str]] = [(src, "")]
    seen: Set[str] = {src}
    produced: List[Mutant] = []

    for level in range(max(1, depth)):
        next_frontier: List[Tuple[str, str]] = []
        for parent_src, parent_chain in frontier:
            for m in _apply_once(parent_src, operators, extra):
                if m.source in seen:
                    continue
                seen.add(m.source)
                chain = f"{parent_chain}+{m.operator}" if parent_chain else m.operator
                m.operator = chain
                m.origin = f"depth {level + 1}"
                produced.append(m)
                next_frontier.append((m.source, chain))
                if len(next_frontier) >= max_per_depth:
                    break
            if len(next_frontier) >= max_per_depth:
                break
        if not next_frontier:
            break
        frontier = next_frontier
    return produced


def _rebuild(case: Case, source: str) -> Optional[Callable]:
    """Compile a mutant back into a callable, in the original function's scope."""
    ns: Dict[str, Any] = dict(getattr(case.fn, "__globals__", {}))
    ns.setdefault("_TCD_ESCAPED", [])
    try:
        exec(compile(source, f"<mutant:{case.name}>", "exec"), ns)
    except Exception:
        return None
    fn = ns.get(getattr(case.fn, "__name__", ""))
    return fn if callable(fn) else None


def _is_deterministic(case: Case, ctx: Context, seed: int) -> Tuple[bool, str]:
    """Does this program give the same answer twice?

    When mutants are no longer required to preserve the original's semantics,
    this becomes the validity gate in its place, and it is the more fundamental
    one: the oracle asks "does compiled agree with eager *for this program*",
    which is only a meaningful question if the program agrees with itself.
    Programs reading uninitialised memory (``torch.empty``) or unseeded
    randomness would otherwise divergence-report on every run.
    """
    from .execution import run_eager
    from .oracle import Config, compare

    try:
        a = run_eager(case, ctx, seed)
        b = run_eager(case, ctx, seed)
    except Exception as e:
        return False, f"eager run failed: {type(e).__name__}: {str(e)[:100]}"
    if not a.ok:
        return False, f"eager raised {a.exception}"
    if not b.ok:
        return False, f"eager raised {b.exception} on the second run"
    cmp = compare(a, b, None, Config())
    if cmp.differs:
        return False, ("nondeterministic: two eager runs with the same seed "
                       "disagree - " + "; ".join(f.detail for f in cmp.findings)[:120])
    return True, "ok"


def validate_mutants(case: Case, mutants: List[Mutant], seed: int = 0,
                     require_semantics: bool = True
                     ) -> Tuple[List[Mutant], List[Mutant]]:
    """Filter mutants down to the ones that are valid tests.

    Two regimes, and the choice matters:

    * ``require_semantics=True`` - a mutant must reproduce the original's eager
      behaviour. This makes a later divergence attributable to the *operator*,
      which the ablation study needs. But it also rejects every mutation that
      actually changes values, so the operators are reduced to identity writes
      (``add_(0)``) and full slices - precisely the constructs a compiler
      handles most easily, either optimised away or passed through untouched.

    * ``require_semantics=False`` - a mutant is simply a different program,
      tested against *its own* eager reference. That is what the oracle
      compares anyway, so nothing is weakened; what is gained is the ability to
      use real in-place writes and genuinely different alias structure. The
      validity gate becomes determinism (see :func:`_is_deterministic`).
    """
    from .execution import run_eager
    from .oracle import Config, compare

    cfg = Config()
    valid: List[Mutant] = []
    invalid: List[Mutant] = []
    ctx = case.contexts[0] if case.contexts else Context("base", {})

    reference = None
    if require_semantics:
        try:
            reference = run_eager(case, ctx, seed)
        except Exception as e:
            for m in mutants:
                m.valid, m.invalid_reason = False, f"reference eager run failed: {e}"
            return [], list(mutants)
        if not reference.ok:
            for m in mutants:
                m.valid, m.invalid_reason = False, "reference eager run raised"
            return [], list(mutants)

    for m in mutants:
        fn = _rebuild(case, m.source)
        if fn is None:
            m.valid, m.invalid_reason = False, "mutant source did not compile"
            invalid.append(m)
            continue
        probe = Case(name=f"{case.name}::{m.operator}", fn=fn,
                     make_inputs=case.make_inputs, contexts=[ctx],
                     tags=list(case.tags) + ["mutant"], notes=case.notes,
                     alias_contract=case.alias_contract,
                     skip_fp64=case.skip_fp64, source=m.source)

        if not require_semantics:
            ok, why = _is_deterministic(probe, ctx, seed)
            m.valid, m.invalid_reason = ok, ("" if ok else why)
            (valid if ok else invalid).append(m)
            continue

        try:
            got = run_eager(probe, ctx, seed)
        except Exception as e:
            m.valid, m.invalid_reason = False, f"mutant eager run failed: {e}"
            invalid.append(m)
            continue
        if not got.ok:
            m.valid, m.invalid_reason = False, f"mutant raised {got.exception}"
            invalid.append(m)
            continue
        cmp = compare(reference, got, None, cfg)
        if cmp.differs:
            m.valid = False
            m.invalid_reason = "changes eager semantics: " + \
                               "; ".join(f.detail for f in cmp.findings)[:160]
            invalid.append(m)
        else:
            m.valid = True
            valid.append(m)
    return valid, invalid


def mutant_cases(case: Case, mutants: List[Mutant]) -> List[Case]:
    """Turn validated mutants into probeable cases."""
    out: List[Case] = []
    for i, m in enumerate(mutants):
        fn = _rebuild(case, m.source)
        if fn is None:
            continue
        out.append(Case(
            name=f"{case.name}__{m.operator}_{i}",
            fn=fn,
            make_inputs=case.make_inputs,
            contexts=list(case.contexts),
            tags=list(case.tags) + ["mutant", m.operator],
            notes=f"{case.notes}\n[mutant: {m.description}]",
            # A mutant tests the same operator, so it inherits that operator's
            # contracts. Dropping alias_contract here made every `unsafe_*`
            # mutant report a non-defect as submittable.
            alias_contract=case.alias_contract,
            skip_fp64=case.skip_fp64,
            expect=case.expect,
            source=m.source,
        ))
    return out
