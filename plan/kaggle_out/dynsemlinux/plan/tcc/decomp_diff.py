"""Decomposition-vs-kernel and meta-vs-real differentials (NEXT_DIRECTIONS 5.1 / 5.2).

Inductor does not run aten kernels; it runs the Python *decompositions* in
``torch._inductor.decomposition``. A decomposition that disagrees with the
eager kernel is a compiled-vs-eager divergence that needs no compiler run to
find. This module executes an OpInfo sample twice - once normally, once under
a dispatch mode that swaps every aten op for its decomposition - and compares
with the same fp64-reference oracle the rest of the pipeline uses. Thousands
of inputs per second, so the edge-input space (empty / size-1 / 0-d /
non-contiguous / integer dtypes / NaN-Inf / extreme values) can be swept.

The meta differential runs the sample under FakeTensorMode and compares the
inferred shape / dtype / stride with the real result: a wrong meta kernel is
a compile crash or a wrong-stride bug waiting to happen.

A mismatch is *confirmed* by compiling the operator with ``torch.compile`` on
the same inputs, so what is reported has gone through the real pipeline too.
"""
from __future__ import annotations

import json
import os
import time
from dataclasses import dataclass, field
from typing import Any, Callable, Dict, List, Optional, Sequence, Tuple

from .compat import seed_everything, torch
from .observe import Observation, flatten, is_tensor, observe
from .oracle import Config, compare
from .program import make_noncontiguous, resize_dim


# --------------------------------------------------------------------------
# the decomposition dispatch mode
# --------------------------------------------------------------------------

class DecompMode:
    """Run ``fn`` with every aten op replaced by its Inductor decomposition."""

    def __init__(self, table: Optional[Dict[Any, Callable]] = None):
        from torch._inductor import decomposition as ID
        self.table = table if table is not None else ID.select_decomp_table()
        self.hits: List[str] = []

    def run(self, fn: Callable, *args, **kwargs):
        from torch.utils._python_dispatch import TorchDispatchMode
        table, hits = self.table, self.hits
        active: List[Any] = []

        class _Mode(TorchDispatchMode):
            def __torch_dispatch__(self, func, types, a=(), kw=None):
                kw = kw or {}
                d = table.get(func)
                if d is not None and func not in active:
                    active.append(func)
                    try:
                        r = d(*a, **kw)
                    finally:
                        active.pop()
                    # some Inductor decompositions return NotImplemented to say "use the
                    # default kernel for these argument types" (e.g. add with a Python scalar)
                    if r is NotImplemented:
                        return func(*a, **kw)
                    hits.append(str(func))
                    return r
                return func(*a, **kw)

        with _Mode():
            return fn(*args, **kwargs)


# --------------------------------------------------------------------------
# edge-input variants
# --------------------------------------------------------------------------

def _variants(args: Tuple[Any, ...]) -> List[Tuple[str, Tuple[Any, ...]]]:
    """Cheap, meaning-preserving-or-legal perturbations of a sample's tensors."""
    out: List[Tuple[str, Tuple[Any, ...]]] = [("base", args)]
    ti = [i for i, a in enumerate(args) if is_tensor(a)]
    if not ti:
        return out
    first = ti[0]
    t = args[first]

    def swap(i: int, new: Any) -> Tuple[Any, ...]:
        b = list(args)
        b[i] = new
        return tuple(b)

    if t.dim() >= 1 and t.shape[0] > 0:
        out.append(("empty_dim0", swap(first, resize_dim(t, 0, 0) if False else t[:0].clone())))
        out.append(("size1_dim0", swap(first, t[:1].clone())))
    if t.dim() >= 2:
        out.append(("empty_last", swap(first, t[..., :0].clone())))
        out.append(("size1_last", swap(first, t[..., :1].clone())))
        out.append(("prime_dim0", swap(first, resize_dim(t, 0, 7))))
    if t.dim() >= 1:
        out.append(("noncontig", tuple(make_noncontiguous(a) if is_tensor(a) else a for a in args)))
    if t.dim() >= 2 and all(s >= 2 for s in t.shape):
        # every dim a distinct prime: vectorisation tails / tiling remainders in every loop
        z = t
        for d, p in zip(range(t.dim()), (7, 11, 13, 5, 3, 17)):
            z = resize_dim(z, d, p)
        out.append(("prime_all", swap(first, z)))
    if t.numel() > 0 and t.dim() >= 1:
        out.append(("zero_dim", swap(first, t.reshape(-1)[0].clone())))
    if t.dim() == 4:
        out.append(("channels_last", swap(first, t.contiguous(memory_format=torch.channels_last))))
    if t.is_floating_point():
        out.append(("dtype_int64", tuple(a.round().to(torch.int64) if is_tensor(a) and a.is_floating_point() else a
                                         for a in args)))
        out.append(("dtype_bool", swap(first, t != 0)))
        z = t.clone().contiguous()
        if z.numel():
            flat = z.view(-1)
            flat[0] = float("nan")
            if flat.numel() > 1:
                flat[1] = float("inf")
        out.append(("nan_inf", swap(first, z)))
        out.append(("huge", swap(first, t * 1e30)))
        out.append(("tiny", swap(first, t * 1e-30)))
        for dt in (torch.float16, torch.bfloat16):
            out.append((f"dtype_{str(dt).split('.')[-1]}",
                        tuple(a.to(dt) if is_tensor(a) and a.is_floating_point() else a for a in args)))
        # 6.3 (2026-09-12): complex inputs (Inductor mostly falls back / decomposes via view_as_real)
        out.append(("dtype_complex64",
                    tuple(torch.complex(a, 0.5 * a.flip(0) if a.dim() else 0.5 * a) if is_tensor(a) and a.is_floating_point() else a
                          for a in args)))
        # 6.3: long reduction axis (1e5 elements): fp32 accumulation vs eager's double accumulation (item 05 family)
        if t.dim() >= 1 and t.numel() > 0 and t.numel() // t.shape[-1] <= 64:
            big = resize_dim(t, -1, 100_003)
            out.append(("large_reduce", swap(first, big)))
            out.append(("large_reduce_bf16", tuple(a.to(torch.bfloat16) if is_tensor(a) and a.is_floating_point() else a
                                                  for a in swap(first, big))))
    return out


# --------------------------------------------------------------------------
# records
# --------------------------------------------------------------------------

@dataclass
class Mismatch:
    op: str
    variant: str
    kind: str                 # decomp | meta
    detail: str
    decomps_hit: List[str] = field(default_factory=list)
    confirmed: Optional[bool] = None
    confirm_detail: str = ""
    shapes: List[Any] = field(default_factory=list)
    dtypes: List[str] = field(default_factory=list)
    recipe: str = ""

    def as_dict(self) -> Dict[str, Any]:
        return dict(vars(self))


def _describe(args: Tuple[Any, ...]) -> Tuple[List[Any], List[str]]:
    shapes, dtypes = [], []
    for a in args:
        if is_tensor(a):
            shapes.append(list(a.shape))
            dtypes.append(str(a.dtype))
    return shapes, dtypes


def _clone(t: Any) -> Any:
    """Fresh copy that keeps the layout (``clone()`` would make a strided slice contiguous)."""
    if not is_tensor(t):
        return t
    try:
        out = torch.empty_strided(t.shape, t.stride(), dtype=t.dtype, device=t.device)
        out.copy_(t.detach())
        return out
    except Exception:
        return t.detach().clone()


def _clones(args: Sequence[Any], kwargs: Dict[str, Any]) -> Tuple[Tuple[Any, ...], Dict[str, Any]]:
    return tuple(_clone(a) for a in args), {k: _clone(v) for k, v in kwargs.items()}


def with_grad(fn: Callable) -> Callable:
    """forward + backward as one function: returns (outputs..., grad of each float input...).

    Run under the decomposition mode, the backward ops go through their
    decompositions too (the *_backward table is where 44 of the mined issues live).
    """
    def fn_g(*args, **kwargs):
        leaves = []
        new_args = []
        for a in args:
            if is_tensor(a) and a.is_floating_point() and not a.is_complex():
                b = a.detach().clone().requires_grad_(True)
                leaves.append(b)
                new_args.append(b)
            else:
                new_args.append(a)
        out = fn(*new_args, **kwargs)     # keyword tensors (weight=, running_mean=...) are not differentiated
        items, _ = flatten(out)
        outs = [o for o in items if is_tensor(o) and o.requires_grad]
        if not leaves or not outs:
            return out
        with torch.no_grad():
            # deterministic, non-uniform weights that can also be built under FakeTensorMode
            # (eager, decomposed, fp64, fake and compiled runs must weight the outputs identically)
            weights = [((torch.arange(o.numel(), device=o.device, dtype=torch.float32) % 7) - 3.0)
                       .reshape(o.shape).to(o.dtype) * 0.25 for o in outs]
        terms = [(o * w).sum() for o, w in zip(outs, weights)]
        loss = terms[0]
        for t in terms[1:]:          # not sum(): that starts from the int 0 and confuses the dispatch mode
            loss = loss + t
        grads = torch.autograd.grad(loss, leaves, allow_unused=True)
        return tuple(items) + tuple(g if g is not None else torch.zeros(()) for g in grads)
    fn_g.__name__ = getattr(fn, "__name__", "fn") + "_grad"
    return fn_g


def _run(fn: Callable, args: Tuple[Any, ...], mode: str) -> Observation:
    exc = None
    out = None
    try:
        out = fn(*args)
    except Exception as e:  # noqa: BLE001
        exc = e
    return observe(mode, args, out, exc, with_grad=False)


def _fp64(fn: Callable, args: Tuple[Any, ...]) -> Optional[Observation]:
    from .execute import to_fp64
    try:
        a64 = to_fp64(args)
        o = _run(fn, a64, "fp64")
        return o if o.ok else None
    except Exception:
        return None


_DATA_DEPENDENT = ("DataDependentOutputException", "GuardOnDataDependentSymNode", "DynamicOutputShapeException")


def _meta_check(fn: Callable, args: Tuple[Any, ...], kwargs: Dict[str, Any],
                real: Observation) -> Tuple[Optional[str], str]:
    """(problem, kind): shape / dtype / stride the fake path infers vs what eager produced.

    kind is ``meta`` for a real disagreement and ``data_dependent`` when the
    operator legitimately cannot run on fake tensors (compile graph-breaks there).
    """
    from torch._subclasses.fake_tensor import FakeTensorMode
    if not real.ok:
        return None, ""
    try:
        from torch.utils._pytree import tree_map
        with FakeTensorMode() as m:
            conv = lambda a: m.from_tensor(a) if is_tensor(a) else a  # noqa: E731
            fargs, fkw = tree_map(conv, tuple(args)), tree_map(conv, dict(kwargs))
            out = fn(*fargs, **fkw)
    except Exception as e:  # noqa: BLE001
        kind = "data_dependent" if type(e).__name__ in _DATA_DEPENDENT else "meta"
        return f"fake-tensor path raised {type(e).__name__}: {str(e)[:120]}", kind
    items, struct = flatten(out)
    if struct != real.out_struct:
        return f"structure {struct} vs real {real.out_struct}", "meta"
    for i, (fm, rm) in enumerate(zip([a for a in items], real.out_meta)):
        if rm is None or not is_tensor(fm):
            continue
        if tuple(fm.shape) != rm.shape:
            return f"output[{i}] shape {tuple(fm.shape)} vs real {rm.shape}", "meta"
        if str(fm.dtype) != rm.dtype:
            return f"output[{i}] dtype {fm.dtype} vs real {rm.dtype}", "meta"
        try:
            # strides of size-1 dims are insignificant (PyTorch's own check_significant_strides rule)
            sig_f = tuple(st for s, st in zip(fm.shape, fm.stride()) if s > 1)
            sig_r = tuple(st for s, st in zip(rm.shape, rm.stride) if s > 1)
            if sig_f != sig_r and fm.numel() > 1:
                return f"output[{i}] stride {tuple(fm.stride())} vs real {rm.stride}", "meta_stride"
        except Exception:
            pass
    return None, ""


# --------------------------------------------------------------------------
# the sweep
# --------------------------------------------------------------------------

def _eligible(op, dt) -> bool:
    from .seeds import _NONDETERMINISTIC_OPS
    name = op.name
    base = name.split(".")[-1]
    if name.startswith(("_", "sparse", "special.")) or base in _NONDETERMINISTIC_OPS \
            or base.startswith(("empty", "rand", "new_empty")):
        return False
    try:
        return dt in op.supported_dtypes("cpu")
    except Exception:
        return False


def list_ops(dtype: str = "float32", limit: int = 0) -> List[str]:
    """OpInfo names the sweep would visit, in op_db order (used by the isolated driver)."""
    from torch.testing._internal.common_methods_invocations import op_db
    dt = getattr(torch, dtype)
    names: List[str] = []
    for op in op_db:
        if _eligible(op, dt):
            names.append(op.name)
            if limit and len(names) >= limit:
                break
    return names


def sweep(limit: int = 0, samples_per_op: int = 2, seed: int = 0, dtype: str = "float32",
          confirm: bool = True, confirm_backend: str = "inductor", log=print,
          only: Optional[str] = None, jsonl: Optional[str] = None, grad: bool = False,
          variants: Optional[Sequence[str]] = None) -> Dict[str, Any]:
    """Run the differential; ``jsonl`` (if given) receives every mismatch and a
    ``{"done": op}`` marker per operator as they happen, so a native crash loses nothing.
    ``grad``: compare forward *and* input gradients (backward decompositions).
    ``variants``: restrict to these variant names (default: all)."""
    from torch.testing._internal.common_methods_invocations import op_db
    import random as _r
    cfg = Config()
    rng = _r.Random(seed)
    dm = DecompMode()
    dt = getattr(torch, dtype)
    t0 = time.perf_counter()
    stats = {"ops": 0, "samples": 0, "variants": 0, "decomp_covered": 0, "decomp_mismatch": 0,
             "meta_mismatch": 0, "data_dependent": 0, "errors": 0}
    mismatches: List[Mismatch] = []
    wanted = {s.strip() for s in only.split(",")} if only else None
    sink = open(jsonl, "a", encoding="utf-8") if jsonl else None

    def emit(rec: Dict[str, Any]) -> None:
        if sink is not None:
            sink.write(json.dumps(rec, default=str) + "\n")
            sink.flush()

    for op in op_db:
        name = op.name
        if wanted and name not in wanted:
            continue
        if not _eligible(op, dt):
            continue
        if limit and stats["ops"] >= limit:
            break
        try:
            samples = list(op.sample_inputs("cpu", dt, requires_grad=False))
        except Exception:
            emit({"done": name})
            continue
        samples = [s for s in samples if is_tensor(s.input)
                   and all(not is_tensor(a) or a.layout == torch.strided for a in s.args)]
        if not samples:
            emit({"done": name})
            continue
        stats["ops"] += 1
        seen_keys: set = set()
        for s in rng.sample(samples, min(samples_per_op, len(samples))):
            stats["samples"] += 1
            kwargs = dict(s.kwargs)
            fn_op = op.op

            def fn(*a, _op=fn_op, **kw):
                return _op(*a, **kw)
            wrap = None
            fn_inner = fn
            if grad:
                if not any(is_tensor(a) and a.is_floating_point() for a in (s.input,) + tuple(s.args)):
                    continue
                fn = with_grad(fn_inner)   # kwargs stay explicit so the fake-tensor check converts them too
                wrap = with_grad           # confirmation compiles the forward and differentiates through it
            args0 = (s.input,) + tuple(s.args)
            try:
                sample_variants = _variants(args0)
            except Exception as e:  # noqa: BLE001 - an exotic sample must not stop the sweep
                stats["errors"] += 1
                sample_variants = [("base", args0)]
            if variants:
                sample_variants = [(n, a) for n, a in sample_variants if n in variants]
            for vname, args in sample_variants:
                stats["variants"] += 1
                seed_everything(seed)
                fresh, fkw = _clones(args, kwargs)
                real = _run(lambda *a: fn(*a, **fkw), fresh, "eager")
                if real.infra_error:
                    continue
                # ---- decomposition differential ----
                dm.hits.clear()
                fresh2, fkw2 = _clones(args, kwargs)
                try:
                    dec = _run(lambda *a: dm.run(fn, *a, **fkw2), fresh2, "decomp")
                except Exception as e:  # noqa: BLE001
                    stats["errors"] += 1
                    continue
                hits = list(dict.fromkeys(dm.hits))
                if hits:
                    stats["decomp_covered"] += 1
                    ref64 = _fp64(lambda *a: fn(*a, **fkw), args) if real.ok else None
                    cmp = compare(real, dec, ref64, cfg, ["value", "metadata", "exception"])
                    if cmp.differs:
                        f = cmp.findings[0]
                        detail = f"[{f.kind}] {f.detail}"
                        if f.kind == "exception" and not dec.ok:
                            msg = dec.exception_msg or ""
                            if "Multiple dispatch failed" in msg or "not implemented for" in msg and "Meta" in msg:
                                continue   # our raw call of the decomposition, not the compiler's
                            detail += f" :: {msg[:100]}"
                        key = (name, vname, detail[:120])
                        if key in seen_keys:
                            continue
                        seen_keys.add(key)
                        stats["decomp_mismatch"] += 1
                        shapes, dtypes = _describe(args)
                        m = Mismatch(name, vname, "decomp", detail[:220], hits[:6], shapes=shapes, dtypes=dtypes)
                        if confirm:
                            target = (lambda *a: fn_inner(*a, **fkw))
                            m.confirmed, m.confirm_detail = _confirm(
                                target, args, real, ref64, cfg, confirm_backend, wrap=wrap)
                        mismatches.append(m)
                        emit(m.as_dict())
                        log(f"  DECOMP {name:<36} {vname:<14} {m.detail[:80]}  confirmed={m.confirmed}")
                # ---- meta differential ----
                why, kind = _meta_check(fn, *_clones(args, kwargs), real)
                if why:
                    key = (name, vname, kind, why[:80])
                    if key in seen_keys:
                        continue
                    seen_keys.add(key)
                    stats["meta_mismatch" if kind != "data_dependent" else "data_dependent"] = \
                        stats.get("meta_mismatch" if kind != "data_dependent" else "data_dependent", 0) + 1
                    shapes, dtypes = _describe(args)
                    mm = Mismatch(name, vname, kind, why[:200], shapes=shapes, dtypes=dtypes)
                    mismatches.append(mm)
                    emit(mm.as_dict())
                    if kind != "data_dependent":
                        log(f"  META   {name:<36} {vname:<14} {why[:80]}")
        emit({"done": name})
    stats["wall_s"] = round(time.perf_counter() - t0, 1)
    emit({"stats": stats})
    if sink is not None:
        sink.close()
    return {"stats": stats, "mismatches": [m.as_dict() for m in mismatches]}


# --------------------------------------------------------------------------
# isolated driver: chunks of operators in child interpreters (native aborts survive)
# --------------------------------------------------------------------------

def read_jsonl(path: str) -> Tuple[List[Dict[str, Any]], set, Dict[str, int], List[Dict[str, Any]]]:
    mism: List[Dict[str, Any]] = []
    done: set = set()
    stats: Dict[str, int] = {}
    crashes: List[Dict[str, Any]] = []
    if not os.path.exists(path):
        return mism, done, stats, crashes
    with open(path, encoding="utf-8") as fh:
        for ln in fh:
            ln = ln.strip()
            if not ln:
                continue
            try:
                rec = json.loads(ln)
            except Exception:
                continue
            if "done" in rec:
                done.add(rec["done"])
            elif "crash" in rec:
                crashes.append(rec)
                done.add(rec["crash"])
            elif "stats" in rec:
                for k, v in rec["stats"].items():
                    if isinstance(v, (int, float)):
                        stats[k] = stats.get(k, 0) + v
            else:
                mism.append(rec)
    return mism, done, stats, crashes


def isolated_sweep(out_dir: str, child_args: List[str], dtype: str = "float32", limit: int = 0,
                   chunk_size: int = 25, child_timeout: float = 1200.0, log=print,
                   subcommand: str = "decomp", ops: Optional[List[str]] = None,
                   jsonl_name: str = "decomp_diff.jsonl", report=None) -> Dict[str, Any]:
    """Parent scheduler: ``run.py <subcommand> --only <chunk> --jsonl ...`` per chunk; a chunk whose
    child dies is replayed one operator at a time so the crasher is named and skipped."""
    import subprocess
    import sys as _sys
    os.makedirs(out_dir, exist_ok=True)
    jsonl = os.path.join(out_dir, jsonl_name)
    here = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
    ops = list(ops) if ops is not None else list_ops(dtype, limit)
    _, done, _, _ = read_jsonl(jsonl)
    todo = [o for o in ops if o not in done]
    log(f"isolated {subcommand} sweep: {len(ops)} operators, {len(done)} already done, {len(todo)} to go")

    def run_child(names: List[str]) -> int:
        argv = [_sys.executable, "-u", os.path.join(here, "run.py"), subcommand, "--only", ",".join(names),
                "--jsonl", jsonl, "--out", os.path.join(out_dir, "_child")] + child_args
        try:
            r = subprocess.run(argv, capture_output=True, text=True, timeout=child_timeout,
                               encoding="utf-8", errors="replace")
        except subprocess.TimeoutExpired:
            return -999
        for ln in (r.stdout or "").splitlines():
            if ln.startswith("  DECOMP") or ln.startswith("  META"):
                log(ln)
        if r.returncode != 0:
            tail = "\n".join((r.stderr or "").splitlines()[-4:])
            log(f"  child exit {r.returncode}: {tail[-300:]}")
        return r.returncode

    t0 = time.time()
    i = 0
    while i < len(todo):
        chunk = todo[i:i + chunk_size]
        i += chunk_size
        log(f"[{i}/{len(todo)}] {chunk[0]} .. {chunk[-1]}")
        rc = run_child(chunk)
        if rc == 0:
            continue
        # replay the unfinished operators of this chunk one by one
        _, done, _, _ = read_jsonl(jsonl)
        for name in chunk:
            if name in done:
                continue
            rc1 = run_child([name])
            _, done, _, _ = read_jsonl(jsonl)
            if rc1 != 0 and name not in done:
                with open(jsonl, "a", encoding="utf-8") as fh:
                    fh.write(json.dumps({"crash": name, "rc": rc1}) + "\n")
                log(f"  CRASH  {name:<36} process exit {rc1} (timeout if -999)")
    mism, done, stats, crashes = read_jsonl(jsonl)
    stats["wall_s"] = round(time.time() - t0, 1)
    stats["crashes"] = len(crashes)
    res = {"stats": stats, "mismatches": mism, "crashes": crashes}
    (report or write_report)(res, out_dir)
    return res


def _confirm(fn: Callable, args: Tuple[Any, ...], real: Observation, ref64: Optional[Observation],
             cfg: Config, backend: str, wrap: Optional[Callable] = None) -> Tuple[Optional[bool], str]:
    """Does torch.compile show the same divergence on these inputs? ``wrap`` (grad mode) turns the
    compiled forward into forward + backward, so the backward goes through AOTAutograd/Inductor."""
    from .compat import compile_fn, dynamo_reset
    try:
        dynamo_reset()
        cf = compile_fn(fn, backend)
        if wrap is not None:
            cf = wrap(cf)
        fresh = tuple(_clone(a) for a in args)
        got = _run(cf, fresh, f"compiled[{backend}]")
        dynamo_reset()
        if got.infra_error:
            return None, f"compile infra failure: {got.exception}"
        cmp = compare(real, got, ref64, cfg, ["value", "metadata", "exception"])
        if cmp.differs:
            return True, cmp.findings[0].detail[:160]
        return False, "compiled matches eager"
    except Exception as e:  # noqa: BLE001
        return None, f"{type(e).__name__}: {str(e)[:100]}"


def write_report(res: Dict[str, Any], out_dir: str) -> str:
    os.makedirs(out_dir, exist_ok=True)
    with open(os.path.join(out_dir, "decomp_diff.json"), "w", encoding="utf-8") as fh:
        json.dump(res, fh, indent=2, default=str)
    st = res["stats"]
    L = ["# Decomposition / meta differential", "",
         f"- operators: {st['ops']}, samples: {st['samples']}, input variants: {st['variants']}",
         f"- variants where at least one decomposition ran: {st['decomp_covered']}",
         f"- decomposition mismatches: {st['decomp_mismatch']}  (confirmed by torch.compile: "
         f"{sum(1 for m in res['mismatches'] if m['kind'] == 'decomp' and m['confirmed'])})",
         f"- meta / fake-tensor mismatches: {st['meta_mismatch']} (data-dependent ops that cannot run on fake "
         f"tensors, not counted: {st.get('data_dependent', 0)})", f"- wall: {st.get('wall_s', 0)} s", ""]
    if res.get("crashes"):
        L.append(f"- operators whose child interpreter died (native abort / timeout): "
                 + ", ".join(f"{c['crash']} (rc {c['rc']})" for c in res["crashes"]))
        L.append("")
    L += ["| kind | op | variant | shapes | dtypes | detail | confirmed |", "|---|---|---|---|---|---|---|"]
    for m in res["mismatches"]:
        if m.get("kind") == "data_dependent":
            continue
        L.append(f"| {m['kind']} | {m['op']} | {m['variant']} | {m['shapes']} | {m['dtypes']} | "
                 f"{m['detail'][:90].replace('|', '/')} | {m['confirmed']} |")
    path = os.path.join(out_dir, "DECOMP_DIFF.md")
    with open(path, "w", encoding="utf-8") as fh:
        fh.write("\n".join(L) + "\n")
    return path
