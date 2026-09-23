"""Plan section 11: base inputs.

A legal seed comes, in order of preference, from (1) a project unit test,
(2) an issue reproducer, (3) an official example, (4) the function signature
and annotations, (5) a simple random legal input. Sources 1-3 arrive as
recorded calls (``seed_from_call``) or as reproducer files
(``programs_from_dir``); 4 and 5 are synthesised here.
"""
from __future__ import annotations

import ast
import inspect
import os
import textwrap
from typing import Any, Callable, Dict, List, Optional, Tuple

from .compat import default_device, torch
from .program import Context, Program
from .sites import CompilationSite, scan_source

_TENSOR_NAMES = ("x", "y", "z", "w", "a", "b", "q", "k", "v", "input", "inp", "tensor", "t", "h",
                 "hidden", "weight", "bias", "grad", "mask", "logits", "out")
_INT_NAMES = ("n", "k", "m", "dim", "size", "count", "steps", "num", "idx", "index", "axis", "seq_len",
              "block", "stride", "pad", "length", "depth", "width", "rows", "cols")
_BOOL_PREFIX = ("use_", "is_", "has_", "enable", "flag", "fast", "training", "inplace", "keepdim")


def _guess(param: inspect.Parameter, source_hint: str = "") -> Any:
    name = param.name
    ann = param.annotation
    if param.default is not inspect.Parameter.empty:
        d = param.default
        if isinstance(d, (bool, int, float, str)) or d is None:
            return d
    if torch is not None and ann is not inspect.Parameter.empty:
        if ann is torch.Tensor or getattr(ann, "__name__", "") == "Tensor":
            return torch.randn(8, 8, device=default_device())
        if ann is int:
            return 4
        if ann is float:
            return 0.5
        if ann is bool:
            return True
        if ann is str:
            return "sum"
    lname = name.lower()
    if lname in _INT_NAMES or lname.endswith(("_dim", "_size", "_len")):
        return 4
    if lname.startswith(_BOOL_PREFIX) or lname in ("fast", "flag"):
        return True
    if lname in ("mode", "reduction", "kind", "name"):
        return "sum"
    if lname in ("xs", "inputs", "tensors", "args", "items"):
        return [torch.randn(4, 4, device=default_device()) for _ in range(3)] if torch else []
    if lname in ("bias", "mask", "scale") and lname in source_hint and "is None" in source_hint:
        return None
    if lname in _TENSOR_NAMES or torch is None:
        return torch.randn(8, 8, device=default_device()) if torch is not None else None
    # unknown: a tensor is the most likely legal value at a compile boundary
    return torch.randn(8, 8, device=default_device())


def inputs_from_signature(fn: Callable) -> Optional[Callable[[Context], Tuple[Any, ...]]]:
    """Source 4: build a deterministic input factory from the signature."""
    try:
        sig = inspect.signature(fn)
    except (TypeError, ValueError):
        return None
    try:
        src = inspect.getsource(fn)
    except (OSError, TypeError):
        src = ""
    params = [p for p in sig.parameters.values()
              if p.kind in (p.POSITIONAL_ONLY, p.POSITIONAL_OR_KEYWORD)]

    def make_inputs(ctx: Context, _params=params, _src=src) -> Tuple[Any, ...]:
        return tuple(_guess(p, _src) for p in _params)

    return make_inputs


def seed_from_call(fn: Callable, args: Tuple[Any, ...]) -> Callable[[Context], Tuple[Any, ...]]:
    """Sources 1-3: a recorded legal call. Tensors are re-materialised per call."""
    frozen = tuple(a.detach().clone() if torch is not None and isinstance(a, torch.Tensor) else a
                   for a in args)

    def make_inputs(ctx: Context, _f=frozen) -> Tuple[Any, ...]:
        out = []
        for a in _f:
            if torch is not None and isinstance(a, torch.Tensor):
                b = a.detach().clone()
                b.requires_grad_(a.requires_grad)
                out.append(b)
            else:
                out.append(a)
        return tuple(out)

    return make_inputs


def program_from_function(fn: Callable, name: Optional[str] = None,
                          args: Optional[Tuple[Any, ...]] = None, **kw) -> Optional[Program]:
    mk = seed_from_call(fn, args) if args is not None else inputs_from_signature(fn)
    if mk is None:
        return None
    return Program(name=name or getattr(fn, "__name__", "fn"), fn=fn, make_inputs=mk, **kw)


# --------------------------------------------------------------------------
# reproducer files (issue reproducers, official examples, external tools)
# --------------------------------------------------------------------------

_FORBIDDEN = ("subprocess", "os.system", "shutil.rmtree", "socket", "requests", "urllib",
              "open(", "eval(", "__import__", "exec(", "sys.exit", "os.remove", "pickle")


def _safe(src: str) -> Optional[str]:
    """Reject code that could touch the machine. Comments do not count."""
    try:
        code = ast.unparse(ast.parse(src))   # drops comments, keeps executable text
    except SyntaxError:
        code = src
    low = code.lower()
    import re as _re
    for f in _FORBIDDEN:
        if f in ("eval(", "exec(", "open("):
            # bare builtins only: `model.eval()` and `f.open()` are not the builtins
            if _re.search(r"(?<![\w.])" + _re.escape(f), low):
                return f"forbidden pattern {f!r}"
        elif f in low:
            return f"forbidden pattern {f!r}"
    return None


class _Recorder:
    """Stand-in for ``torch.compile`` that captures the target and its first call."""

    def __init__(self) -> None:
        self.target: Any = None
        self.args: Optional[Tuple[Any, ...]] = None
        self.kwargs: Dict[str, Any] = {}
        self.options: Dict[str, Any] = {}

    def _compile(self, fn=None, *a, **kw):
        if fn is None:                       # @torch.compile(backend=..., ...)
            return lambda f: self._compile(f, **kw)
        if not callable(fn):
            return fn
        self.options = {k: v for k, v in kw.items() if isinstance(v, (str, bool, int, float))}
        rec = self

        def wrapped(*args, **kwargs):
            if rec.target is None:
                rec.target, rec.args, rec.kwargs = fn, args, dict(kwargs)
            return fn(*args, **kwargs)
        return wrapped

    def _optimize(self, backend=None, *a, **kw):
        return lambda f: self._compile(f, backend=backend)

    def patched(self):
        import contextlib

        @contextlib.contextmanager
        def cm():
            if torch is None:
                yield
                return
            saved = (torch.compile, getattr(torch._dynamo, "optimize", None))
            torch.compile = self._compile
            try:
                torch._dynamo.optimize = self._optimize
            except Exception:
                pass
            try:
                yield
            finally:
                torch.compile = saved[0]
                if saved[1] is not None:
                    try:
                        torch._dynamo.optimize = saved[1]
                    except Exception:
                        pass
        return cm()

    def as_program_parts(self) -> Tuple[Any, Optional[Tuple[Any, ...]]]:
        fn = self.target
        if self.kwargs:
            base, kws = fn, dict(self.kwargs)

            def fn(*args, _b=base, _k=kws):
                return _b(*args, **_k)
            fn.__name__ = getattr(base, "__name__", type(base).__name__)
        return fn, self.args


def load_reproducer(path: str) -> Tuple[Optional[Program], str]:
    """A ``.py`` file defining ``f`` (or one compiled function) and ``args``.

    Returns ``(program, reason)``; ``program`` is ``None`` when rejected.
    The file is executed, so the safety gate above is deliberately strict.
    """
    try:
        with open(path, encoding="utf-8") as fh:
            src = fh.read()
    except OSError as e:
        return None, f"unreadable: {e}"
    bad = _safe(src)
    if bad:
        return None, bad
    try:
        code_only = ast.unparse(ast.parse(src))
    except SyntaxError:
        code_only = src
    if "cuda" in code_only and not (torch is not None and torch.cuda.is_available()):
        return None, "requires a GPU"
    ns: Dict[str, Any] = {"__name__": f"_repro_{os.path.basename(path)}"}
    # Record mode: the script's own ``torch.compile(...)`` is replaced by a recorder
    # that runs the target eagerly and remembers the target and its first call's
    # arguments. Issue reproducers rarely define ``args``; they call the compiled
    # function, and that call *is* the legal seed (plan 11, source 2).
    rec = _Recorder()
    import contextlib
    import io
    try:
        with rec.patched(), contextlib.redirect_stdout(io.StringIO()), contextlib.redirect_stderr(io.StringIO()):
            exec(compile(src, path, "exec"), ns)
    except Exception as e:  # noqa: BLE001
        if rec.target is None:
            return None, f"does not run: {type(e).__name__}: {str(e)[:80]}"
        # the script failed *after* the first compiled call (e.g. its own assert
        # comparing eager vs compiled); the recorded call is still a valid seed
    fn = ns.get("f")
    args = ns.get("args")
    if (fn is None or not callable(fn) or args is None) and rec.target is not None:
        fn, args = rec.as_program_parts()
    if fn is None or not callable(fn):
        sites = scan_source(src, path)
        target = next((s.target for s in sites if s.target and callable(ns.get(s.target))), None)
        fn = ns.get(target) if target else None
    if fn is None:
        fns = [v for k, v in ns.items() if inspect.isfunction(v) and v.__module__ == ns["__name__"]]
        fn = fns[0] if len(fns) == 1 else None
    if fn is None:
        return None, "no compiled function found (define `f`, or call torch.compile(fn)(...) in the script)"
    if args is None:
        mk = inputs_from_signature(fn)
        if mk is None:
            return None, "no `args` and the signature could not be resolved"
    else:
        if not isinstance(args, tuple):
            args = (args,)
        if any(a is None for a in args) and not all(isinstance(a, (torch.Tensor, int, float, bool, str, list, tuple, dict)) or a is None for a in args):
            return None, "recorded arguments contain unsupported objects"
        mk = seed_from_call(fn, args)
    fsrc = None
    fn_name = getattr(fn, "__name__", None) or type(fn).__name__
    is_module = torch is not None and isinstance(fn, torch.nn.Module)
    try:
        tree = ast.parse(src)
        if is_module:
            # the compiled target is a module: analyse its forward
            for n in ast.walk(tree):
                if isinstance(n, ast.ClassDef) and n.name == type(fn).__name__:
                    for m in n.body:
                        if isinstance(m, ast.FunctionDef) and m.name == "forward":
                            fsrc = ast.get_source_segment(src, m)
                    break
        else:
            for n in ast.walk(tree):
                if isinstance(n, ast.FunctionDef) and n.name == fn_name:
                    fsrc = ast.get_source_segment(src, n)
                    break
    except SyntaxError:
        pass
    title = next((ln[len("# title:"):].strip() for ln in src.splitlines() if ln.startswith("# title:")), "")
    url = next((ln[len("# source:"):].strip() for ln in src.splitlines() if ln.startswith("# source:")), "")
    notes = f"loaded from {path}" + (f"\n{title}" if title else "") + (f"\n{url}" if url else "")
    if rec.target is not None and rec.options:
        notes += f"\ncompile options in the issue: {rec.options}"
    reset = None
    if is_module:
        import copy
        try:
            state0 = copy.deepcopy(fn.state_dict())

            def reset(_m=fn, _s=state0):
                _m.load_state_dict(copy.deepcopy(_s))
        except Exception:
            reset = None
    return Program(name=os.path.splitext(os.path.basename(path))[0], fn=fn, make_inputs=mk,
                   tags=["reproducer"] + (["module"] if is_module else []), notes=notes, source=fsrc,
                   site={"file": path, "url": url}, check_grad=not is_module, reset=reset), "ok"


def _probe_in_subprocess(file: str, timeout_s: float) -> Tuple[bool, str]:
    """Load one reproducer in a throwaway interpreter first.

    Issue scripts can abort the process from native code or never return; a
    crash must cost one file, not the whole campaign.
    """
    import subprocess
    import sys as _sys
    here = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
    # After loading, touch the accelerator: a device-side assert raised by the script
    # is asynchronous and would otherwise surface later, in the main process, where it
    # poisons the CUDA context for every program that follows.
    code = ("import sys; sys.path.insert(0, %r); from tcc.seeds import load_reproducer; "
            "p, why = load_reproducer(%r); "
            "import torch\n"
            "if torch.cuda.is_available():\n"
            "    try:\n"
            "        torch.cuda.synchronize(); (torch.ones(2, device='cuda') + 1).sum().item()\n"
            "    except Exception as e:\n"
            "        print('TCC_REJECT cuda context poisoned: ' + type(e).__name__); raise SystemExit(0)\n"
            "print('TCC_OK' if p is not None else 'TCC_REJECT ' + why)"
            % (here, file))
    env = dict(os.environ)
    env.setdefault("CUDA_LAUNCH_BLOCKING", "1")   # make device asserts synchronous inside the probe
    try:
        r = subprocess.run([_sys.executable, "-c", code], capture_output=True, text=True, timeout=timeout_s,
                           cwd=here, env=env)
    except subprocess.TimeoutExpired:
        return False, f"timeout after {timeout_s:.0f}s in isolation"
    except Exception as e:  # noqa: BLE001
        return False, f"probe failed: {type(e).__name__}"
    out = (r.stdout or "").strip().splitlines()
    last = out[-1] if out else ""
    if last == "TCC_OK":
        return True, "ok"
    if last.startswith("TCC_REJECT"):
        return False, last[len("TCC_REJECT "):]
    return False, f"crashed in isolation (exit {r.returncode})"


def programs_from_dir(path: str, isolate: bool = True, timeout_s: float = 90.0
                      ) -> Tuple[List[Program], List[Tuple[str, str]]]:
    ok: List[Program] = []
    rejected: List[Tuple[str, str]] = []
    if not os.path.isdir(path):
        return ok, [(path, "not a directory")]
    for nm in sorted(os.listdir(path)):
        if not nm.endswith(".py") or nm.startswith("_"):
            continue
        full = os.path.join(path, nm)
        if isolate:
            alive, why = _probe_in_subprocess(full, timeout_s)
            if not alive:
                rejected.append((nm, why))
                continue
        try:
            p, why = load_reproducer(full)
        except Exception as e:  # noqa: BLE001 - one bad file must not stop the loading
            p, why = None, f"load error: {type(e).__name__}: {str(e)[:80]}"
        if p is None:
            rejected.append((nm, why))
        else:
            ok.append(p)
    return ok, rejected


_NONDETERMINISTIC_OPS = {
    "empty", "empty_like", "empty_strided", "empty_permuted", "new_empty", "new_empty_strided",
    "rand", "rand_like", "randn", "randn_like", "randint", "randint_like", "randperm", "normal",
    "bernoulli", "multinomial", "poisson", "cauchy", "exponential", "geometric", "log_normal", "uniform",
    "dropout", "alpha_dropout", "feature_alpha_dropout", "rrelu", "native_dropout", "fractional_max_pool2d",
    "fractional_max_pool3d",
}


def programs_from_opinfo(limit: int = 50, dtype: str = "float32", alias_first: bool = True,
                         seed: int = 0, samples_per_op: int = 1) -> Tuple[List[Program], List[Tuple[str, str]]]:
    """Source 1 of plan section 11: PyTorch's own operator test database.

    Each OpInfo sample becomes one program (``op(*args, **kwargs)``) whose seed
    is the sample the project's tests use. Operators whose schema declares an
    alias relation come first when ``alias_first`` (plan section 8 focus).
    """
    out: List[Program] = []
    rejected: List[Tuple[str, str]] = []
    if torch is None:
        return out, [("opinfo", "torch unavailable")]
    try:
        from torch.testing._internal.common_methods_invocations import op_db  # type: ignore
    except Exception as e:  # noqa: BLE001
        return out, [("opinfo", f"op_db unavailable: {type(e).__name__}: {e}")]
    from .compat import declares_aliasing
    dt = getattr(torch, dtype)
    ops = list(op_db)
    if alias_first:
        ops.sort(key=lambda o: 0 if declares_aliasing(o.name.split(".")[0]) else 1)
    import random as _r
    rng = _r.Random(seed)
    for op in ops:
        if len(out) >= limit:
            break
        name = op.name
        if any(name.startswith(p) for p in ("_", "nn.functional.rnn", "sparse", "special.")):
            continue
        # no oracle applies: uninitialised memory, or randomness whose stream
        # legitimately differs between eager and compiled code
        base = name.split(".")[-1]
        if base in _NONDETERMINISTIC_OPS or any(base.startswith(p) for p in ("empty", "rand", "new_empty")):
            rejected.append((name, "returns uninitialised memory or fresh randomness"))
            continue
        try:
            if dt not in op.supported_dtypes("cpu"):
                continue
            samples = list(op.sample_inputs("cpu", dt, requires_grad=False))
        except Exception as e:  # noqa: BLE001
            rejected.append((name, f"sample_inputs: {type(e).__name__}"))
            continue
        samples = [s for s in samples if isinstance(s.input, torch.Tensor) and s.input.dim() >= 1
                   and all(not isinstance(a, torch.Tensor) or a.layout == torch.strided for a in s.args)]
        if not samples:
            rejected.append((name, "no strided tensor sample"))
            continue
        for s in rng.sample(samples, min(samples_per_op, len(samples))):
          fn_op = op.op
          kwargs = dict(s.kwargs)
          tensor_args = [a for a in s.args if isinstance(a, torch.Tensor)]
          other_args = [a for a in s.args if not isinstance(a, torch.Tensor)]
          if other_args and tensor_args:
              continue  # mixed positional layouts are ambiguous to re-bind
          n_t = 1 + len(tensor_args)

          def fn(*args, _op=fn_op, _kw=kwargs, _extra=tuple(other_args), _n=n_t):
              return _op(*args[:_n], *_extra, **_kw)
          variant = getattr(op, "variant_test_name", "") or ""
          fn.__name__ = f"opinfo_{name.replace('.', '_')}" + (f"_{variant}" if variant else "")
          if any(p.name == fn.__name__ for p in out):
              fn.__name__ += f"_{len(out)}"

          seeds = tuple([s.input.detach().clone()] + [t.detach().clone() for t in tensor_args])
          mk = seed_from_call(fn, seeds)
          alias = declares_aliasing(name.split(".")[0])
          try:
              fn(*mk(Context("base", {})))
          except Exception as e:  # noqa: BLE001
              rejected.append((name, f"does not run: {type(e).__name__}"))
              continue
          def _lit(v: Any) -> str:
              if isinstance(v, torch.Tensor):
                  return f"torch.tensor({v.tolist()!r}, dtype={v.dtype})"
              return repr(v)
          kw_src = ", ".join(f"{k}={_lit(v)}" for k, v in kwargs.items())
          extra_src = "".join(f", {_lit(v)}" for v in other_args)
          # the reproducer must show what actually runs: many OpInfo entries wrap
          # the operator in a helper (forward + backward, reference impls, ...)
          callee = f"torch.{name}"
          prelude = ""
          try:
              import inspect as _inspect
              mod = getattr(fn_op, "__module__", "") or ""
              # public torch API (torch.*, torch.nn.functional.*) is referenced by name;
              # only test-infrastructure helpers get their source inlined
              if "testing._internal" in mod or not mod.startswith("torch"):
                  helper_src = _inspect.getsource(fn_op)
                  if "def " in helper_src:
                      prelude = textwrap.dedent(helper_src).rstrip() + "\n\n"
                      callee = fn_op.__name__
          except Exception:
              pass
          out.append(Program(name=fn.__name__, fn=fn, make_inputs=mk,
                             tags=["opinfo", "official-test"] + (["alias"] if alias else []),
                             notes=f"OpInfo {name} sample; aliasing declared={alias}",
                             source=f"{prelude}def {fn.__name__}(*args):\n    return {callee}(*args{extra_src}"
                                    f"{', ' + kw_src if kw_src else ''})\n",
                             check_grad=False))
    return out, rejected


def programs_on_device(programs: List[Program], device: str) -> List[Program]:
    """Same programs, seed tensors moved to ``device`` (GPU campaigns)."""
    if torch is None:
        return programs
    out: List[Program] = []
    for p in programs:
        base = p.make_inputs

        def make_inputs(ctx: Context, _b=base, _d=device) -> Tuple[Any, ...]:
            args = _b(ctx)
            if not isinstance(args, tuple):
                args = (args,)
            moved = []
            for a in args:
                if isinstance(a, torch.Tensor):
                    rg = a.requires_grad
                    b = a.detach().to(_d)
                    if rg:
                        b.requires_grad_(True)
                    moved.append(b)
                elif isinstance(a, list) and a and all(isinstance(t, torch.Tensor) for t in a):
                    moved.append([t.detach().to(_d) for t in a])
                else:
                    moved.append(a)
            return tuple(moved)

        fn = p.fn
        if isinstance(fn, torch.nn.Module):
            try:
                fn = fn.to(device)
            except Exception:
                pass
        q = Program(name=p.name, fn=fn, make_inputs=make_inputs, base_context=p.base_context,
                    tags=list(p.tags) + [device], notes=p.notes, expect=p.expect, source=p.source,
                    project=p.project, skip_fp64=p.skip_fp64, check_grad=p.check_grad,
                    compile_options=dict(p.compile_options), site=p.site, contexts=list(p.contexts),
                    reset=p.reset)
        out.append(q)
    return out


def programs_from_sites(sites: List[CompilationSite]) -> Tuple[List[Program], List[Tuple[str, str]]]:
    """Turn discovered compilation sites into programs with signature-derived seeds."""
    ok: List[Program] = []
    rejected: List[Tuple[str, str]] = []
    for s in sites:
        if not s.target_source:
            rejected.append((f"{s.file}:{s.line}", "target source unavailable"))
            continue
        bad = _safe(s.target_source)
        if bad:
            rejected.append((f"{s.file}:{s.line}", bad))
            continue
        ns: Dict[str, Any] = {"__name__": "_site", "torch": torch}
        try:
            exec(compile(textwrap.dedent(s.target_source), s.file, "exec"), ns)
        except Exception as e:  # noqa: BLE001
            rejected.append((f"{s.file}:{s.line}", f"target does not define standalone: {type(e).__name__}"))
            continue
        fn = ns.get(s.target)
        if not callable(fn):
            rejected.append((f"{s.file}:{s.line}", "target not callable"))
            continue
        mk = inputs_from_signature(fn)
        if mk is None:
            rejected.append((f"{s.file}:{s.line}", "signature unresolved"))
            continue
        ok.append(Program(name=f"{os.path.splitext(os.path.basename(s.file))[0]}.{s.target}", fn=fn,
                          make_inputs=mk, tags=["site", s.compiler], notes=f"{s.compiler} at {s.file}:{s.line}",
                          source=s.target_source, site=s.as_dict()))
    return ok, rejected
