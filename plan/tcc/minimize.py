"""Plan section 17.2: failure minimization.

Input minimization shrinks, in order: rank, shape, tensor values, arguments,
container size, flags. Program minimization deletes statements, trying first
the ones the static slice says are unrelated to the target semantic factor,
then unrelated branches / calls / parameters.

Two rules: shrink toward the *same* failure (same stage, same oracle kinds),
never toward any failure; and stay within a budget, because each step costs
a compile.
"""
from __future__ import annotations

import ast
import copy
from dataclasses import dataclass, field
from typing import Any, Callable, Dict, List, Optional, Sequence, Set, Tuple

from .compat import torch
from .ir import build_ir_from_source
from .program import Context, Program


@dataclass
class Target:
    stage: str
    kinds: Tuple[str, ...]
    probe: str                       # layered | matrix
    factor: str = ""

    def matches(self, stage: str, kinds: Sequence[str]) -> bool:
        return stage == self.stage and tuple(sorted(kinds)) == tuple(sorted(self.kinds))


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
    original_numel: int = 0
    final_numel: int = 0
    compiles: int = 0

    def as_dict(self) -> Dict[str, Any]:
        return {"reproduces": self.reproduces, "steps_tried": self.steps_tried,
                "steps_kept": self.steps_kept, "original_lines": self.original_lines,
                "final_lines": self.final_lines, "original_numel": self.original_numel,
                "final_numel": self.final_numel, "input_recipe": self.input_recipe,
                "log": self.log, "source": self.source}


Predicate = Callable[[Program, Context, Optional[Context]], bool]


# --------------------------------------------------------------------------
# predicate: does this still fail the same way?
# --------------------------------------------------------------------------

def make_predicate(target: Target, compiler_factory: Callable[[], Any], seed: int = 0,
                   layers=None, oracles=None) -> Predicate:
    from .execute import execution_matrix, run_fp64, run_layered
    from .localize import triage_layers, triage_matrix
    from .oracle import Config
    cfg = Config()

    def still_fails(program: Program, ctx: Context, ctx_b: Optional[Context]) -> bool:
        try:
            if target.probe == "matrix" and ctx_b is not None:
                m = execution_matrix(program, ctx, ctx_b, compiler_factory(), seed=seed)
                tri, _ = triage_matrix(m, cfg, oracles)
            else:
                fp64 = run_fp64(program, ctx, seed)
                layers_obs = run_layered(program, ctx, seed=seed, layers=layers)
                tri, _ = triage_layers(layers_obs, fp64, cfg, oracles)
        except Exception:
            return False
        return target.matches(tri.stage, tri.kinds)

    return still_fails


# --------------------------------------------------------------------------
# input minimization
# --------------------------------------------------------------------------

def _clone_program(p: Program, **changes: Any) -> Program:
    kw = dict(name=p.name, fn=p.fn, make_inputs=p.make_inputs, base_context=p.base_context,
              tags=list(p.tags), notes=p.notes, expect=p.expect, source=p.source,
              project=p.project, skip_fp64=p.skip_fp64, check_grad=p.check_grad,
              compile_options=dict(p.compile_options), site=p.site, contexts=list(p.contexts),
              reset=p.reset)
    kw.update(changes)
    return Program(**kw)


def _with_transform(p: Program, t: Callable[[Tuple[Any, ...]], Tuple[Any, ...]]) -> Program:
    base = p.make_inputs

    def make_inputs(ctx: Context, _b=base, _t=t) -> Tuple[Any, ...]:
        args = _b(ctx)
        if not isinstance(args, tuple):
            args = (args,)
        return _t(args)

    return _clone_program(p, make_inputs=make_inputs)


def _t_drop_rank(arg_i: Optional[int] = None) -> Callable:
    def t(args):
        out = list(args)
        for i, a in enumerate(out):
            if arg_i is not None and i != arg_i:
                continue
            if torch is not None and isinstance(a, torch.Tensor) and a.dim() > 1:
                rg = a.requires_grad
                b = a.detach().select(0, 0).clone()
                if rg:
                    b.requires_grad_(True)
                out[i] = b
        return tuple(out)
    return t


def _t_halve_dim(dim: int) -> Callable:
    def t(args):
        out = list(args)
        for i, a in enumerate(out):
            if torch is not None and isinstance(a, torch.Tensor) and a.dim() > dim and a.shape[dim] > 1:
                rg = a.requires_grad
                b = a.detach().narrow(dim, 0, max(1, a.shape[dim] // 2)).clone()
                if rg:
                    b.requires_grad_(True)
                out[i] = b
        return tuple(out)
    return t


def _t_simple_values() -> Callable:
    def t(args):
        out = list(args)
        for i, a in enumerate(out):
            if torch is not None and isinstance(a, torch.Tensor) and a.is_floating_point():
                n = a.numel()
                v = (torch.arange(n, dtype=torch.float64).reshape(a.shape) / max(1, n)).to(a.dtype)
                v = v.to(a.device)
                if a.requires_grad:
                    v.requires_grad_(True)
                out[i] = v
        return tuple(out)
    return t


def _t_shrink_container() -> Callable:
    def t(args):
        out = list(args)
        for i, a in enumerate(out):
            if isinstance(a, (list, tuple)) and len(a) > 1:
                out[i] = type(a)(list(a)[:max(1, len(a) // 2)])
            elif isinstance(a, dict) and len(a) > 1:
                keys = list(a)[:max(1, len(a) // 2)]
                out[i] = {k: a[k] for k in keys}
        return tuple(out)
    return t


def _t_default_flags() -> Callable:
    def t(args):
        out = list(args)
        for i, a in enumerate(out):
            if isinstance(a, bool) and a:
                out[i] = False
            elif isinstance(a, int) and not isinstance(a, bool) and a not in (0, 1):
                out[i] = 1
            elif isinstance(a, float) and a not in (0.0, 1.0):
                out[i] = 1.0
        return tuple(out)
    return t


def _numel(args: Sequence[Any]) -> int:
    n = 0
    for a in args:
        if torch is not None and isinstance(a, torch.Tensor):
            n += a.numel()
    return n


def _shape_key(p: Program, ctx: Context) -> Tuple:
    try:
        args = p.make_inputs(ctx)
        if not isinstance(args, tuple):
            args = (args,)
        return tuple(tuple(a.shape) if torch is not None and isinstance(a, torch.Tensor) else repr(a)
                     for a in args)
    except Exception:
        return ()


def describe_inputs(args: Sequence[Any]) -> str:
    parts = []
    for a in args:
        if torch is not None and isinstance(a, torch.Tensor):
            shape = ", ".join(str(int(d)) for d in a.shape)
            call = f"torch.randn({shape})" if a.is_floating_point() else f"torch.randint(0, 4, ({shape},))"
            if not shape:
                call = "torch.randn(())" if a.is_floating_point() else "torch.tensor(1)"
            if a.dtype not in (torch.float32, torch.int64):
                call += f".to({a.dtype})"
            if not a.is_contiguous():
                call = f"_noncontig({call})"   # helper emitted by render_reproducer
            if a.requires_grad:
                call += ".requires_grad_(True)"
            parts.append(call)
        else:
            try:
                parts.append(repr(a))
            except Exception:
                parts.append(f"<{type(a).__name__}>")
    return parts[0] + "," if len(parts) == 1 else ", ".join(parts)


def minimize_inputs(p: Program, ctx: Context, ctx_b: Optional[Context], still_fails: Predicate,
                    budget: int = 14) -> Tuple[Program, List[str], int]:
    cur = p
    log: List[str] = []
    tried = 0
    steps: List[Tuple[str, Callable]] = [("drop rank", _t_drop_rank())]
    for d in range(3):
        steps.append((f"halve dim {d}", _t_halve_dim(d)))
    steps += [("simplify values", _t_simple_values()), ("shrink containers", _t_shrink_container()),
              ("default flags", _t_default_flags())]
    changed = True
    once_only = {"simplify values", "shrink containers", "default flags"}
    done: set = set()
    while changed and tried < budget:
        changed = False
        for label, t in steps:
            if tried >= budget:
                break
            if label in done:
                continue
            cand = _with_transform(cur, t)
            before = _shape_key(cur, ctx)
            try:
                after_args = cand.make_inputs(ctx)
            except Exception:
                continue
            if not after_args:
                continue
            if _shape_key(cand, ctx) == before and label not in once_only:
                continue  # converged for this shape transform
            if label in once_only and _numel(after_args) == 0:
                done.add(label)
                continue  # nothing to simplify in an empty input
            tried += 1
            if label in once_only:
                done.add(label)  # value/flag simplifications are idempotent: apply once
            if still_fails(cand, ctx, ctx_b):
                cur = cand
                log.append(f"kept: {label}")
                changed = True
    return cur, log, tried


# --------------------------------------------------------------------------
# program minimization (slice-guided statement deletion)
# --------------------------------------------------------------------------

def _fn_node(src: str) -> Optional[ast.FunctionDef]:
    try:
        tree = ast.parse(src)
    except SyntaxError:
        return None
    for n in ast.walk(tree):
        if isinstance(n, (ast.FunctionDef, ast.AsyncFunctionDef)):
            return n  # type: ignore[return-value]
    return None


def _render(fn: ast.AST) -> str:
    fn = copy.deepcopy(fn)
    fn.decorator_list = []  # type: ignore[attr-defined]
    mod = ast.Module(body=[fn], type_ignores=[])
    ast.fix_missing_locations(mod)
    return ast.unparse(mod)


def _rebuild(p: Program, source: str) -> Optional[Callable]:
    ns: Dict[str, Any] = dict(getattr(p.fn, "__globals__", {}))
    ns.setdefault("torch", torch)
    try:
        exec(compile(source, f"<min:{p.name}>", "exec"), ns)
    except Exception:
        return None
    fn = ns.get(getattr(p.fn, "__name__", "f"))
    return fn if callable(fn) else None


def _assigned(stmt: ast.stmt) -> List[str]:
    out: List[str] = []
    for n in ast.walk(stmt):
        if isinstance(n, ast.Name) and isinstance(n.ctx, ast.Store):
            out.append(n.id)
    return out


def _used(stmt: ast.stmt) -> Set[str]:
    return {n.id for n in ast.walk(stmt) if isinstance(n, ast.Name) and isinstance(n.ctx, ast.Load)}


def _dependents(body: List[ast.stmt], i: int) -> List[int]:
    group = {i}
    tainted = set(_assigned(body[i]))
    for j in range(i + 1, len(body)):
        if tainted & _used(body[j]):
            group.add(j)
            tainted |= set(_assigned(body[j]))
    return sorted(group)


def _last_bound(body: Sequence[ast.stmt]) -> Optional[str]:
    for s in reversed(list(body)):
        names = _assigned(s)
        if names:
            return names[-1]
    return None


def _factor_lines(source: str, factor: str) -> Set[int]:
    """Lines the target factor's IR slice touches: try deleting the others first."""
    ir = build_ir_from_source(source)
    if ir.error:
        return set()
    head = factor.split(".")[0].split("[")[0]
    roots = [n.id for n in ir.nodes if head in n.uses or head in n.defs
             or any(head in s for s in n.state)]
    keep = ir.forward_slice(roots, {"data", "control", "alias"}) | ir.backward_slice(roots)
    return {ir.nodes[i].line for i in keep if i < len(ir.nodes)}


def minimize_program(p: Program, ctx: Context, ctx_b: Optional[Context], still_fails: Predicate,
                     budget: int = 24, factor: str = "") -> Tuple[Program, List[str], int]:
    src = p.get_source()
    if not src:
        return p, ["source unavailable; program not minimized"], 0
    import textwrap
    src = textwrap.dedent(src)
    log: List[str] = []
    tried = 0
    cur, cur_src = p, src
    related = _factor_lines(src, factor) if factor else set()
    changed = True
    while changed and tried < budget:
        changed = False
        fn = _fn_node(cur_src)
        if fn is None or len(fn.body) <= 1:
            break
        order = list(range(len(fn.body) - 1, -1, -1))
        # unrelated statements first (slice-guided), then the rest
        order.sort(key=lambda i: (getattr(fn.body[i], "lineno", 0) in related, -i))
        for i in order:
            if tried >= budget:
                break
            if isinstance(fn.body[i], ast.Return):
                continue
            group = _dependents(fn.body, i)
            trial = copy.deepcopy(fn)
            for j in reversed(group):
                trial.body.pop(j)
            if not trial.body:
                continue
            if any(isinstance(fn.body[j], ast.Return) for j in group):
                surv = _last_bound(trial.body)
                if surv is None:
                    continue
                trial.body.append(ast.Return(value=ast.Name(id=surv, ctx=ast.Load())))
            cand_src = _render(trial)
            new_fn = _rebuild(cur, cand_src)
            if new_fn is None:
                continue
            tried += 1
            cand = _clone_program(cur, fn=new_fn, source=cand_src)
            if still_fails(cand, ctx, ctx_b):
                cur, cur_src = cand, cand_src
                names = "; ".join(ast.unparse(fn.body[j]).splitlines()[0][:40] for j in group[:3])
                log.append(f"removed {len(group)} statement(s): {names}")
                changed = True
                break
    # drop parameters the body no longer mentions
    fn = _fn_node(cur_src)
    if fn is not None and len(fn.args.args) > 1:
        body_names = {n.id for s in fn.body for n in ast.walk(s) if isinstance(n, ast.Name)}
        keep_idx = [i for i, a in enumerate(fn.args.args) if a.arg in body_names]
        if keep_idx and len(keep_idx) < len(fn.args.args):
            trimmed = copy.deepcopy(fn)
            trimmed.args.args = [fn.args.args[i] for i in keep_idx]
            new_src = _render(trimmed)
            new_fn = _rebuild(cur, new_src)
            if new_fn is not None:
                base = cur.make_inputs

                def make_inputs(c: Context, _b=base, _k=tuple(keep_idx)) -> Tuple[Any, ...]:
                    args = _b(c)
                    if not isinstance(args, tuple):
                        args = (args,)
                    return tuple(args[i] for i in _k if i < len(args))

                cand = _clone_program(cur, fn=new_fn, source=new_src, make_inputs=make_inputs)
                tried += 1
                if still_fails(cand, ctx, ctx_b):
                    cur, cur_src = cand, new_src
                    log.append("removed unused parameters")
    return cur, log, tried


# --------------------------------------------------------------------------
# entry point
# --------------------------------------------------------------------------

def minimize(p: Program, ctx: Context, target: Target, still_fails: Predicate,
             ctx_b: Optional[Context] = None, input_budget: int = 14, program_budget: int = 24
             ) -> Minimized:
    src = p.get_source() or ""
    orig_lines = len(src.strip().splitlines())
    try:
        orig_numel = _numel(p.make_inputs(ctx))
    except Exception:
        orig_numel = 0
    if not still_fails(p, ctx, ctx_b):
        return Minimized(src, "", False, original_lines=orig_lines, final_lines=orig_lines,
                         original_numel=orig_numel, final_numel=orig_numel,
                         log=["the failure did not reproduce before minimizing; nothing changed"])
    cur, plog, ptried = minimize_program(p, ctx, ctx_b, still_fails, program_budget, target.factor)
    cur, ilog, itried = minimize_inputs(cur, ctx, ctx_b, still_fails, input_budget)
    try:
        from .execute import build_inputs
        final_args = build_inputs(cur, ctx)
        recipe = describe_inputs(final_args)
        final_numel = _numel(final_args)
    except Exception:
        recipe, final_numel = "", 0
    final_src = cur.get_source() or src
    return Minimized(final_src, recipe, True, ptried + itried, len(plog) + len(ilog), plog + ilog,
                     orig_lines, len(final_src.strip().splitlines()), orig_numel, final_numel)


def render_reproducer(source: str, recipe: str, fn_name: str, ctx: Context,
                      ctx_b: Optional[Context] = None, backend: str = "inductor",
                      compile_kwargs: str = "", recipe_b: str = "") -> str:
    import textwrap
    L = ["import torch", "torch.manual_seed(0)", ""]
    if "_noncontig(" in (recipe or "") + (recipe_b or ""):
        L += ["def _noncontig(t):",
              "    # same values, non-unit innermost stride (a strided view of a wider buffer)",
              "    big = torch.empty(*t.shape[:-1], t.shape[-1] * 2, dtype=t.dtype)",
              "    v = big[..., ::2]",
              "    v.copy_(t)",
              "    return v", ""]
    L += [textwrap.dedent(source).rstrip(), ""]
    L.append(f"args = ({recipe})" if recipe else "args = (...)  # see execution_trace.json")
    L.append("")
    if ctx_b is not None:
        L += [
            "# context A then context B on the same compiled callable (no reset)",
            f"# A = {ctx.factors or '{} (base)'}",
            f"# B = {ctx_b.factors or '{} (base)'}",
            (f"args_b = ({recipe_b})" if recipe_b else
             "args_b = (...)  # the same inputs with only the changed factor applied"),
            "torch._dynamo.reset()",
            f"compiled = torch.compile({fn_name}, backend={backend!r}{compile_kwargs})",
            "compiled(*args)              # warm the cache under A",
            "warm = compiled(*args_b)     # execute under B without a reset",
            "torch._dynamo.reset()",
            f"cold = torch.compile({fn_name}, backend={backend!r}{compile_kwargs})(*args_b)",
            f"eager = {fn_name}(*args_b)",
            "print('eager :', eager)",
            "print('cold  :', cold)",
            "print('warm  :', warm)",
        ]
    else:
        L += [
            f"eager = {fn_name}(*args)",
            "torch._dynamo.reset()",
            f"compiled = torch.compile({fn_name}, backend={backend!r}{compile_kwargs})(*args)",
            "print('eager   :', eager)",
            "print('compiled:', compiled)",
        ]
    return "\n".join(L) + "\n"
