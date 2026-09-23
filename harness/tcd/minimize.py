"""Plan section 17.2: failure minimization.

A maintainer reading a bug report should not have to work out which of forty
lines matters. Until now ``minimal.py`` held the *original* case source, which
made the filename a lie; this reduces both the program and its inputs until
nothing more can be removed without losing the failure.

Two rules govern the whole thing.

**Shrink toward the same failure, not just any failure.** Every candidate is
re-probed and accepted only if the verdict still has the same stage and the
same oracle kinds. Without that check a minimizer happily drifts from the bug
under investigation to some unrelated one it stumbles into, and the reported
reproducer then demonstrates the wrong thing.

**Every step must be cheap enough to be worth taking.** Each candidate costs a
compile - seconds, not milliseconds - so the search is greedy and budgeted
rather than exhaustive. A slightly larger reproducer that arrives today beats a
minimal one that arrives after the maintainer has lost interest.
"""
from __future__ import annotations

import ast
import copy
from dataclasses import dataclass, field
from typing import Any, Callable, Dict, List, Optional, Sequence, Tuple

from .case import Case, Context
from .torchcompat import torch


@dataclass
class Target:
    """The failure we are shrinking toward."""
    stage: str
    kinds: Tuple[str, ...]
    probe: str  # "layered" | "warm"

    def matches(self, stage: str, kinds: Sequence[str]) -> bool:
        return stage == self.stage and tuple(sorted(kinds)) == self.kinds


@dataclass
class Minimized:
    source: str
    input_recipe: str
    reproduces: bool
    steps_tried: int = 0
    steps_kept: int = 0
    log: List[str] = field(default_factory=list)
    original_lines: int = 0
    final_lines: int = 0

    def as_dict(self) -> Dict[str, Any]:
        return {
            "reproduces": self.reproduces,
            "steps_tried": self.steps_tried, "steps_kept": self.steps_kept,
            "original_lines": self.original_lines, "final_lines": self.final_lines,
            "input_recipe": self.input_recipe, "log": self.log,
        }


# --------------------------------------------------------------------------
# the predicate
# --------------------------------------------------------------------------

def make_predicate(target: Target, backend: str, seed: int,
                   ctx_b: Optional[Context] = None) -> Callable[[Case, Context], bool]:
    """Build "does this still fail the same way?" for a target verdict."""
    from .execution import run_cold, run_fp64_reference, run_layered, run_warm_pair
    from .oracle import Config
    from .triage import triage_layers, triage_warm

    cfg = Config()

    def still_fails(case: Case, ctx: Context) -> bool:
        try:
            if target.probe == "warm" and ctx_b is not None:
                fp64 = run_fp64_reference(case, ctx_b, seed=seed)
                cold = run_cold(case, ctx_b, backend=backend, seed=seed)
                warm, recompiled = run_warm_pair(case, ctx, ctx_b,
                                                 backend=backend, seed=seed)
                factor = (ctx.differing_factors(ctx_b) or ["<none>"])[0]
                tri, _ = triage_warm(cold, warm, recompiled, factor, fp64, cfg)
            else:
                fp64 = run_fp64_reference(case, ctx, seed=seed)
                layers = run_layered(case, ctx, seed=seed)
                tri, _ = triage_layers(layers, fp64, cfg)
        except Exception:
            return False
        return target.matches(tri.stage, tri.kinds)

    return still_fails


# --------------------------------------------------------------------------
# input minimization (plan 17.2, first list)
# --------------------------------------------------------------------------

def _with_transform(case: Case, transform: Callable[[Tuple[Any, ...]], Tuple[Any, ...]],
                    label: str) -> Case:
    base = case.make_inputs

    def make_inputs(ctx: Context, _b=base, _t=transform) -> Tuple[Any, ...]:
        return _t(_b(ctx))

    return Case(name=f"{case.name}[{label}]", fn=case.fn, make_inputs=make_inputs,
                contexts=list(case.contexts), tags=list(case.tags), notes=case.notes,
                source=case.source, alias_contract=case.alias_contract,
                skip_fp64=case.skip_fp64)


def _t_halve_dim(dim: int) -> Callable:
    def t(args: Tuple[Any, ...]) -> Tuple[Any, ...]:
        out = list(args)
        for i, a in enumerate(out):
            if torch is not None and isinstance(a, torch.Tensor) and a.dim() > dim:
                n = a.shape[dim]
                if n > 1:
                    out[i] = a.narrow(dim, 0, max(1, n // 2)).clone()
        return tuple(out)
    return t


def _t_squeeze() -> Callable:
    def t(args: Tuple[Any, ...]) -> Tuple[Any, ...]:
        out = list(args)
        for i, a in enumerate(out):
            if torch is not None and isinstance(a, torch.Tensor) and a.dim() > 1:
                if 1 in tuple(a.shape):
                    out[i] = a.squeeze().clone()
        return tuple(out)
    return t


def _t_simple_values() -> Callable:
    """Replace random data with a readable ramp.

    A report whose reproducer says ``torch.arange(6).reshape(2, 3)`` is far
    easier to act on than one carrying forty random decimals, and if the
    failure survives the substitution the values were never the point.
    """
    def t(args: Tuple[Any, ...]) -> Tuple[Any, ...]:
        out = list(args)
        for i, a in enumerate(out):
            if torch is not None and isinstance(a, torch.Tensor) and a.is_floating_point():
                n = a.numel()
                v = torch.arange(n, dtype=a.dtype).reshape(a.shape) / max(1, n)
                v.requires_grad_(a.requires_grad)
                out[i] = v
        return tuple(out)
    return t


def _describe_inputs(args: Sequence[Any]) -> str:
    """Render arguments as runnable Python.

    Shapes go in as an unpacked tuple (``torch.randn(1, 1)``), and a single
    argument still needs its trailing comma so the caller gets a tuple rather
    than a parenthesised expression - a reproducer that is not valid Python is
    worse than none.
    """
    parts = []
    for a in args:
        if torch is not None and isinstance(a, torch.Tensor):
            shape = ", ".join(str(int(d)) for d in a.shape) or ""
            call = f"torch.randn({shape})" if shape else "torch.randn(())"
            if a.dtype != torch.float32:
                call += f".to({a.dtype})"
            if a.requires_grad:
                call += ".requires_grad_(True)"
            parts.append(call)
        else:
            parts.append(repr(a))
    if len(parts) == 1:
        return parts[0] + ","
    return ", ".join(parts)


def minimize_inputs(case: Case, ctx: Context, still_fails: Callable,
                    budget: int = 14) -> Tuple[Case, List[str], int]:
    """Shrink rank, then shape, then values - the order the plan gives."""
    current = case
    log: List[str] = []
    tried = 0

    steps: List[Tuple[str, Callable]] = [("squeeze rank", _t_squeeze())]
    for d in range(3):
        steps.append((f"halve dim {d}", _t_halve_dim(d)))
    steps.append(("simplify values", _t_simple_values()))

    def shape_key(c: Case) -> Tuple:
        try:
            return tuple(tuple(a.shape) if torch is not None
                         and isinstance(a, torch.Tensor) else repr(a)
                         for a in c.make_inputs(ctx))
        except Exception:
            return ()

    applied: Dict[str, int] = {}
    changed = True
    while changed and tried < budget:
        changed = False
        for label, t in steps:
            if tried >= budget:
                break
            before = shape_key(current)
            candidate = _with_transform(current, t, label)
            tried += 1
            try:
                args = candidate.make_inputs(ctx)
            except Exception:
                continue
            if not args:
                continue
            # A transform that changed nothing has converged; re-applying it
            # would keep succeeding and pad the log with repeats that look
            # like progress.
            if shape_key(candidate) == before:
                continue
            if still_fails(candidate, ctx):
                current = candidate
                applied[label] = applied.get(label, 0) + 1
                changed = True

    for label, n in applied.items():
        log.append(f"kept: {label}" + (f" x{n}" if n > 1 else ""))
    return current, log, tried


# --------------------------------------------------------------------------
# program minimization (plan 17.2, second list)
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


def _render(fn: ast.AST) -> str:
    mod = ast.Module(body=[fn], type_ignores=[])
    ast.fix_missing_locations(mod)
    return ast.unparse(mod)


def _rebuild(case: Case, source: str) -> Optional[Callable]:
    ns: Dict[str, Any] = dict(getattr(case.fn, "__globals__", {}))
    ns.setdefault("torch", torch)
    try:
        exec(compile(source, f"<min:{case.name}>", "exec"), ns)
    except Exception:
        return None
    fn = ns.get(getattr(case.fn, "__name__", "f"))
    return fn if callable(fn) else None


def _assigned_names(stmt: ast.stmt) -> List[str]:
    out: List[str] = []
    if isinstance(stmt, ast.Assign):
        for t in stmt.targets:
            if isinstance(t, ast.Name):
                out.append(t.id)
    elif isinstance(stmt, (ast.AugAssign, ast.AnnAssign)) and \
            isinstance(getattr(stmt, "target", None), ast.Name):
        out.append(stmt.target.id)  # type: ignore[union-attr]
    return out


def _used_names(stmt: ast.stmt) -> List[str]:
    return [n.id for n in ast.walk(stmt) if isinstance(n, ast.Name)]


def _dependents(body: List[ast.stmt], i: int) -> List[int]:
    """Indices of ``body[i]`` and everything downstream that depends on it.

    Removing a statement alone fails whenever a later line still references the
    name it bound - the candidate does not even compile, so a purely
    line-at-a-time slicer gets stuck on the first link of any dead chain. Taking
    the whole chain at once is what lets dead code actually leave.
    """
    group = {i}
    tainted = set(_assigned_names(body[i]))
    for j in range(i + 1, len(body)):
        if tainted & set(_used_names(body[j])):
            group.add(j)
            tainted |= set(_assigned_names(body[j]))
    return sorted(group)


def _last_bound_name(body: Sequence[ast.stmt]) -> Optional[str]:
    """The last name bound in this body, to serve as a replacement return."""
    for stmt in reversed(list(body)):
        names = _assigned_names(stmt)
        if names:
            return names[-1]
    return None


def minimize_program(case: Case, ctx: Context, still_fails: Callable,
                     budget: int = 24) -> Tuple[Case, List[str], int]:
    """Remove statements the failure does not need.

    Greedy rather than exhaustive delta debugging: for each statement, try
    deleting it *together with everything that depends on it*, and keep the
    deletion when the same failure survives. The predicate is what guarantees
    correctness - a deletion that breaks the program or changes the verdict is
    rejected.
    """
    src = case.source
    if not src:
        return case, [], 0
    log: List[str] = []
    tried = 0
    current_case = case
    current_src = src

    changed = True
    while changed and tried < budget:
        changed = False
        fn = _fn_node(current_src)
        if fn is None or len(fn.body) <= 1:
            break
        for i in range(len(fn.body) - 1, -1, -1):
            if tried >= budget:
                break
            if isinstance(fn.body[i], ast.Return):
                continue  # a function without a return has nothing to compare
            group = _dependents(fn.body, i)

            trial = copy.deepcopy(fn)
            for j in reversed(group):
                trial.body.pop(j)
            if not trial.body:
                continue

            # Almost every statement reaches the return through some chain, so
            # refusing to touch any group that contains it disables slicing
            # entirely. Instead, delete the group and rewrite the return to use
            # a value that still exists - the predicate then decides whether
            # the shortened program still fails the same way.
            if any(isinstance(fn.body[j], ast.Return) for j in group):
                survivor = _last_bound_name(trial.body)
                if survivor is None:
                    continue
                trial.body.append(ast.Return(
                    value=ast.Name(id=survivor, ctx=ast.Load())))
            candidate_src = _render(trial)
            tried += 1
            new_fn = _rebuild(current_case, candidate_src)
            if new_fn is None:
                continue
            candidate = Case(name=current_case.name, fn=new_fn,
                             make_inputs=current_case.make_inputs,
                             contexts=list(current_case.contexts),
                             tags=list(current_case.tags), notes=current_case.notes,
                             source=candidate_src,
                             alias_contract=current_case.alias_contract,
                             skip_fp64=current_case.skip_fp64)
            if still_fails(candidate, ctx):
                current_src = candidate_src
                current_case = candidate
                names = ", ".join(ast.unparse(fn.body[j]).splitlines()[0][:40]
                                  for j in group[:3])
                log.append(f"removed {len(group)} statement(s): {names}")
                changed = True
                break
    return current_case, log, tried


def drop_unused_params(case: Case) -> Case:
    """Remove parameters the body never mentions (plan 17.2: unrelated parameter)."""
    src = case.source
    fn = _fn_node(src) if src else None
    if fn is None or len(fn.args.args) <= 1:
        return case
    body_names = {n.id for n in ast.walk(ast.Module(body=fn.body, type_ignores=[]))
                  if isinstance(n, ast.Name)}
    keep = [a for a in fn.args.args if a.arg in body_names]
    if len(keep) == len(fn.args.args) or not keep:
        return case
    trimmed = copy.deepcopy(fn)
    kept_idx = [i for i, a in enumerate(fn.args.args) if a.arg in body_names]
    trimmed.args.args = keep
    new_src = _render(trimmed)
    new_fn = _rebuild(case, new_src)
    if new_fn is None:
        return case

    base = case.make_inputs

    def make_inputs(ctx: Context, _b=base, _idx=tuple(kept_idx)) -> Tuple[Any, ...]:
        args = _b(ctx)
        return tuple(args[i] for i in _idx if i < len(args))

    return Case(name=case.name, fn=new_fn, make_inputs=make_inputs,
                contexts=list(case.contexts), tags=list(case.tags),
                notes=case.notes, source=new_src,
                alias_contract=case.alias_contract, skip_fp64=case.skip_fp64)


# --------------------------------------------------------------------------
# entry point
# --------------------------------------------------------------------------

def minimize(case: Case, ctx: Context, target: Target,
             backend: str = "inductor", seed: int = 0,
             ctx_b: Optional[Context] = None,
             input_budget: int = 14, program_budget: int = 24) -> Minimized:
    """Shrink program and inputs while the same failure survives."""
    still_fails = make_predicate(target, backend, seed, ctx_b)

    original_lines = len((case.source or "").strip().splitlines())
    if not still_fails(case, ctx):
        return Minimized(source=case.source or "", input_recipe="",
                         reproduces=False, original_lines=original_lines,
                         final_lines=original_lines,
                         log=["the failure did not reproduce before minimizing; "
                              "nothing was changed"])

    current, plog, ptried = minimize_program(case, ctx, still_fails, program_budget)
    trimmed = drop_unused_params(current)
    if trimmed is not current and still_fails(trimmed, ctx):
        current = trimmed
        plog.append("removed unused parameters")

    current, ilog, itried = minimize_inputs(current, ctx, still_fails, input_budget)

    try:
        recipe = _describe_inputs(current.make_inputs(ctx))
    except Exception:
        recipe = ""

    final_src = current.source or case.source or ""
    return Minimized(
        source=final_src,
        input_recipe=recipe,
        reproduces=True,
        steps_tried=ptried + itried,
        steps_kept=len(plog) + len(ilog),
        log=plog + ilog,
        original_lines=original_lines,
        final_lines=len(final_src.strip().splitlines()),
    )


def render_reproducer(m: Minimized, fn_name: str = "f") -> str:
    """A standalone script a maintainer can paste and run."""
    lines = ["import torch", ""]
    lines.append(m.source.rstrip())
    lines.append("")
    if m.input_recipe:
        lines.append(f"args = ({m.input_recipe})")
    else:
        lines.append("args = (...)  # inputs could not be rendered; see record.json")
    lines += [
        "",
        f"eager = {fn_name}(*args)",
        "torch._dynamo.reset()",
        f"compiled = torch.compile({fn_name})(*args)",
        "",
        "print('eager   :', eager)",
        "print('compiled:', compiled)",
    ]
    return "\n".join(lines) + "\n"
