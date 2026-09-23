"""Binding-form factor: *how* a scalar reaches the operator (NEXT_DIRECTIONS 5.4).

The same Python scalar (``dim=1``, ``kernel_size=2``, ``alpha=0.5``, ``mode="nearest"``)
can arrive at an operator as a literal, a positional parameter, a default
parameter, ``**kwargs``, a closure cell, a module global, an object attribute,
a list or dict element, or ``tensor.item()``. Dynamo specialises each source
differently (constant / SymInt / guarded read / unbacked SymInt / graph break),
so the binding form is a semantic factor of the Python program that no input
perturbation can exercise. This module rewrites one OpInfo call per variant
(exactly one scalar re-bound, everything else literal), then checks

- ``static``  : torch.compile(f) vs eager
- ``dynamic`` : torch.compile(f, dynamic=True) vs eager  (int parameters become SymInts)
- ``rebind``  : call the compiled artefact, change the bound value through the
                same path (mutate the global / attribute / list / dict, pass a
                new argument, rebuild the closure), call again, compare with eager
                at the new value - a missing guard shows up as a stale result.

All forms are semantically identical, so eager agreement across forms holds by
construction; a form-specific divergence is attributable to the compiler.
"""
from __future__ import annotations

import json
import os
import time
from dataclasses import dataclass, field
from typing import Any, Callable, Dict, List, Optional, Sequence, Tuple

from .compat import compile_fn, dynamo_reset, seed_everything, torch
from .decomp_diff import _clone, _clones, _fp64, _run, _eligible, _describe
from .observe import Observation, is_tensor
from .oracle import Config, compare

FORMS = ("literal", "pos_param", "default_param", "kwargs_param", "closure", "global", "attribute",
         "list_elem", "dict_elem", "kwargs_expand", "tensor_item")


def _is_scalar(v: Any) -> bool:
    if isinstance(v, bool) or isinstance(v, (int, float, str)):
        return True
    if isinstance(v, (tuple, list)) and v and all(isinstance(e, (int, float)) and not isinstance(e, bool) for e in v):
        return True
    return False


def _alt_values(v: Any) -> List[Any]:
    """Candidate second values for the rebind check (checked in eager before use)."""
    if isinstance(v, bool):
        return [not v]
    if isinstance(v, int):
        return [v + 1, v - 1, v * 2, 0]
    if isinstance(v, float):
        return [v * 1.5 + 0.25, v / 2.0, 0.0]
    if isinstance(v, (tuple, list)):
        return [type(v)(e + 1 for e in v), type(v)(max(e - 1, 1) if isinstance(e, int) else e / 2 for e in v)]
    return []


def _literal(v: Any) -> str:
    """Python source for a scalar; ``repr(inf)`` is not valid source."""
    import math
    if isinstance(v, float) and not math.isfinite(v):
        return f"float({repr(str(v))})"
    if isinstance(v, (tuple, list)):
        inner = ", ".join(_literal(e) for e in v)
        return f"({inner},)" if isinstance(v, tuple) else f"[{inner}]"
    return repr(v)


@dataclass
class Slot:
    kind: str          # "arg" | "kw"
    key: Any           # positional index or keyword name
    value: Any

    @property
    def label(self) -> str:
        return f"{self.key}" if self.kind == "kw" else f"arg{self.key}"


@dataclass
class Variant:
    form: str
    source: str
    fn: Callable
    extra_args: Tuple[Any, ...]          # appended to the tensor arguments
    extra_kwargs: Dict[str, Any]
    rebind: Optional[Callable[[Any], Tuple[Tuple[Any, ...], Dict[str, Any], Callable]]]
    #: rebind(v2) -> (extra_args, extra_kwargs, fn) to use for the second call


def _render(op_expr: str, n_tensors: int, args: Sequence[Any], kwargs: Dict[str, Any],
            slot: Slot, form: str, op: Callable) -> Optional[Variant]:
    """Build one variant function whose ``slot`` is bound through ``form``."""
    names = [f"x{i}" for i in range(n_tensors)]
    v = slot.value
    lit = _literal(v)
    params = list(names)
    prelude = ""
    expr = lit
    extra_args: Tuple[Any, ...] = ()
    extra_kwargs: Dict[str, Any] = {}
    call_kw_expand = None    # (dict_name) for kwargs_expand on a keyword slot
    call_arg_expand = None   # (list_name) for kwargs_expand on a positional slot
    ns: Dict[str, Any] = {"OP": op, "torch": torch}
    rebind = None

    if form == "literal":
        pass
    elif form == "pos_param":
        params.append("k")
        expr = "k"
        extra_args = (v,)
    elif form == "default_param":
        params.append(f"k={lit}")
        expr = "k"
    elif form == "kwargs_param":
        params.append("**kw")
        expr = "kw['k']"
        extra_kwargs = {"k": v}
    elif form == "global":
        prelude = f"K = {lit}\n"
        expr = "K"
    elif form == "attribute":
        prelude = f"class Cfg:\n    pass\ncfg = Cfg()\ncfg.k = {lit}\n"
        expr = "cfg.k"
    elif form == "list_elem":
        prelude = f"ks = [{lit}]\n"
        expr = "ks[0]"
    elif form == "dict_elem":
        prelude = f"d = {{'k': {lit}}}\n"
        expr = "d['k']"
    elif form == "kwargs_expand":
        if slot.kind == "kw":
            prelude = f"opts = {{{slot.key!r}: {lit}}}\n"
            call_kw_expand = "opts"
        else:
            prelude = f"extra = [{lit}]\n"
            call_arg_expand = "extra"
    elif form == "tensor_item":
        if not isinstance(v, (int, float)) or isinstance(v, bool):
            return None
        params.append("kt")
        expr = "kt.item()"
        extra_args = (torch.tensor(v),)
    elif form == "closure":
        expr = "k"
    else:
        return None

    # the call expression: positional args in order, then keywords
    call_parts: List[str] = []
    ti = 0
    for i, a in enumerate(args):
        if is_tensor(a):
            call_parts.append(names[ti])
            ti += 1
        elif slot.kind == "arg" and slot.key == i:
            if call_arg_expand:
                call_parts.append(f"*{call_arg_expand}")
            else:
                call_parts.append(expr)
        else:
            call_parts.append(repr(a))
    for k, kv in kwargs.items():
        if slot.kind == "kw" and slot.key == k:
            if call_kw_expand:
                call_parts.append(f"**{call_kw_expand}")
            else:
                call_parts.append(f"{k}={expr}")
        else:
            call_parts.append(f"{k}={repr(kv)}")
    call = f"OP({', '.join(call_parts)})"

    if form == "closure":
        body = (f"def make(k):\n    def f({', '.join(names)}):\n        return {call}\n    return f\n"
                f"f = make({lit})\n")
    else:
        body = f"def f({', '.join(params)}):\n    return {call}\n"
    src = prelude + body
    try:
        exec(compile(src, f"<binding:{form}>", "exec"), ns)
    except Exception:
        return None
    fn = ns["f"]

    # how to move to a second value through the same path
    def _rb_pos(v2, _fn=fn):
        return (v2,), {}, _fn

    def _rb_kw(v2, _fn=fn):
        return (), {"k": v2}, _fn

    def _rb_item(v2, _fn=fn):
        return (torch.tensor(v2),), {}, _fn

    def _rb_global(v2, _fn=fn, _ns=ns):
        _ns["K"] = v2
        return (), {}, _fn

    def _rb_attr(v2, _fn=fn, _ns=ns):
        _ns["cfg"].k = v2
        return (), {}, _fn

    def _rb_list(v2, _fn=fn, _ns=ns):
        _ns["ks"][0] = v2
        return (), {}, _fn

    def _rb_dict(v2, _fn=fn, _ns=ns):
        _ns["d"]["k"] = v2
        return (), {}, _fn

    def _rb_expand(v2, _fn=fn, _ns=ns, _slot=slot):
        if _slot.kind == "kw":
            _ns["opts"][_slot.key] = v2
        else:
            _ns["extra"][0] = v2
        return (), {}, _fn

    def _rb_closure(v2, _ns=ns):
        return (), {}, _ns["make"](v2)

    rebind = {"pos_param": _rb_pos, "kwargs_param": _rb_kw, "tensor_item": _rb_item, "global": _rb_global,
              "attribute": _rb_attr, "list_elem": _rb_list, "dict_elem": _rb_dict,
              "kwargs_expand": _rb_expand, "closure": _rb_closure}.get(form)
    shown = src.replace("OP(", op_expr + "(")
    return Variant(form, shown, fn, extra_args, extra_kwargs, rebind)


@dataclass
class Finding:
    op: str
    slot: str
    value: Any
    form: str
    mode: str              # static | dynamic | rebind
    detail: str
    literal_same: Optional[bool] = None   # did the literal form pass the same mode?
    source: str = ""
    shapes: List[Any] = field(default_factory=list)
    dtypes: List[str] = field(default_factory=list)

    def as_dict(self) -> Dict[str, Any]:
        return dict(vars(self))


def _call(fn: Callable, tensors: Tuple[Any, ...], extra: Tuple[Any, ...], kw: Dict[str, Any], mode: str) -> Observation:
    if kw:
        return _run(lambda *a: fn(*a, **kw), tensors + extra, mode)
    return _run(fn, tensors + extra, mode)


def sweep(limit: int = 0, samples_per_op: int = 1, seed: int = 0, dtype: str = "float32",
          backend: str = "inductor", forms: Sequence[str] = FORMS, modes: Sequence[str] = ("static", "dynamic", "rebind"),
          max_slots: int = 1, log=print, only: Optional[str] = None, jsonl: Optional[str] = None,
          device: str = "cpu") -> Dict[str, Any]:
    from torch.testing._internal.common_methods_invocations import op_db
    import random as _r
    cfg = Config()
    rng = _r.Random(seed)
    dt = getattr(torch, dtype)
    t0 = time.perf_counter()
    stats = {"ops": 0, "samples": 0, "slots": 0, "variants": 0, "compiles": 0, "checks": 0,
             "findings": 0, "form_specific": 0, "infra": 0}
    out: List[Finding] = []
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
            samples = list(op.sample_inputs(device, dt, requires_grad=False))
        except Exception:
            emit({"done": name})
            continue
        samples = [s for s in samples if is_tensor(s.input)
                   and all(not is_tensor(a) or a.layout == torch.strided for a in s.args)
                   and (any(_is_scalar(a) for a in s.args) or any(_is_scalar(v) for v in s.kwargs.values()))]
        if not samples:
            emit({"done": name})
            continue
        stats["ops"] += 1
        op_expr = f"torch.{name}"
        for s in rng.sample(samples, min(samples_per_op, len(samples))):
            stats["samples"] += 1
            args = (s.input,) + tuple(s.args)
            kwargs = dict(s.kwargs)
            tensors = tuple(a for a in args if is_tensor(a))
            slots = [Slot("arg", i, a) for i, a in enumerate(args) if _is_scalar(a)]
            slots += [Slot("kw", k, v) for k, v in kwargs.items() if _is_scalar(v)]
            # ints first (SymInt specialisation is where the action is), then the rest
            slots.sort(key=lambda sl: (0 if isinstance(sl.value, int) and not isinstance(sl.value, bool) else 1))
            shapes, dtypes = _describe(args)
            for slot in slots[:max_slots]:
                stats["slots"] += 1
                variants: Dict[str, Variant] = {}
                for form in forms:
                    var = _render(op_expr, len(tensors), args, kwargs, slot, form, op.op)
                    if var is not None:
                        variants[form] = var
                if "literal" not in variants:
                    continue
                lit = variants["literal"]
                seed_everything(seed)
                real = _call(lit.fn, _clones(tensors, {})[0], lit.extra_args, lit.extra_kwargs, "eager")
                if real.infra_error:
                    continue
                ref64 = _fp64(lambda *a: lit.fn(*a), tensors) if real.ok else None
                # second value for the rebind check, validated in eager
                v2 = None
                real2 = None
                if "rebind" in modes:
                    for cand in _alt_values(slot.value):
                        if cand == slot.value:
                            continue
                        probe = _render(op_expr, len(tensors), args, kwargs, Slot(slot.kind, slot.key, cand),
                                        "literal", op.op)
                        if probe is None:
                            continue
                        r2 = _call(probe.fn, _clones(tensors, {})[0], (), {}, "eager")
                        if r2.ok:
                            v2, real2 = cand, r2
                            break
                ref64_2 = None
                if v2 is not None and real2 is not None and real2.ok:
                    probe = _render(op_expr, len(tensors), args, kwargs, Slot(slot.kind, slot.key, v2), "literal", op.op)
                    ref64_2 = _fp64(lambda *a, _p=probe: _p.fn(*a), tensors) if probe else None

                results: Dict[Tuple[str, str], Optional[bool]] = {}   # (form, mode) -> differs?
                details: Dict[Tuple[str, str], str] = {}
                for form, var in variants.items():
                    stats["variants"] += 1
                    for mode in modes:
                        if mode == "rebind" and (var.rebind is None or v2 is None):
                            continue
                        stats["checks"] += 1
                        dynamo_reset()
                        try:
                            cf = compile_fn(var.fn, backend, dynamic=True if mode == "dynamic" else None)
                            got = _call(cf, _clones(tensors, {})[0], var.extra_args, var.extra_kwargs, f"compiled[{mode}]")
                            stats["compiles"] += 1
                            if mode == "rebind" and not got.infra_error:
                                ea, ek, fn2 = var.rebind(v2)
                                cf2 = cf if fn2 is var.fn else compile_fn(fn2, backend)
                                got = _call(cf2, _clones(tensors, {})[0], ea, ek, "compiled[rebind]")
                                # restore the holder for later forms (closure/pos forms are stateless)
                                var.rebind(slot.value)
                        except Exception as e:  # noqa: BLE001
                            stats["infra"] += 1
                            details[(form, mode)] = f"infra {type(e).__name__}: {str(e)[:100]}"
                            results[(form, mode)] = None
                            continue
                        finally:
                            dynamo_reset()
                        if got.infra_error:
                            stats["infra"] += 1
                            results[(form, mode)] = None
                            details[(form, mode)] = f"infra {got.exception}: {(got.exception_msg or '')[:100]}"
                            continue
                        ref = real2 if mode == "rebind" else real
                        r64 = ref64_2 if mode == "rebind" else ref64
                        c = compare(ref, got, r64, cfg, ["value", "metadata", "exception"])
                        results[(form, mode)] = c.differs
                        if c.differs:
                            f0 = c.findings[0]
                            d = f"[{f0.kind}] {f0.detail}"
                            if f0.kind == "exception" and not got.ok:
                                d += f" :: {(got.exception_msg or '')[:120]}"
                            details[(form, mode)] = d
                for (form, mode), differs in results.items():
                    if not differs:
                        continue
                    lit_same = results.get(("literal", mode))
                    # the literal form has no rebind path: "literal passes" is not applicable there
                    fd = Finding(name, slot.label, slot.value, form, mode, details[(form, mode)][:300],
                                 literal_same=(None if mode == "rebind" else lit_same is False),
                                 source=variants[form].source, shapes=shapes, dtypes=dtypes)
                    out.append(fd)
                    emit(fd.as_dict())
                    stats["findings"] += 1
                    if fd.literal_same and form != "literal":
                        stats["form_specific"] += 1
                    log(f"  {mode:<7} {name:<30} {slot.label}={slot.value!r:<8} {form:<13} {fd.detail[:70]}"
                        f"  literal_ok={fd.literal_same}")
        emit({"done": name})
    stats["wall_s"] = round(time.perf_counter() - t0, 1)
    emit({"stats": stats})
    if sink is not None:
        sink.close()
    return {"stats": stats, "mismatches": [f.as_dict() for f in out]}


def write_report(res: Dict[str, Any], out_dir: str) -> str:
    os.makedirs(out_dir, exist_ok=True)
    with open(os.path.join(out_dir, "binding.json"), "w", encoding="utf-8") as fh:
        json.dump(res, fh, indent=2, default=str)
    st = res["stats"]
    L = ["# Binding-form factor: how a scalar reaches the operator", "",
         f"- operators: {st.get('ops', 0)}, samples: {st.get('samples', 0)}, scalar slots: {st.get('slots', 0)}, "
         f"variants: {st.get('variants', 0)}, checks: {st.get('checks', 0)}, compiles: {st.get('compiles', 0)}, "
         f"infra: {st.get('infra', 0)}",
         f"- findings: {st.get('findings', 0)}, of which **form-specific** (the literal form passes the same mode): "
         f"{st.get('form_specific', 0)}", f"- wall: {st.get('wall_s', 0)} s", ""]
    if res.get("crashes"):
        L.append("- operators whose child interpreter died: "
                 + ", ".join(f"{c['crash']} (rc {c['rc']})" for c in res["crashes"]))
        L.append("")
    L += ["| mode | op | slot | form | detail | literal form passes |", "|---|---|---|---|---|---|"]
    for m in res["mismatches"]:
        L.append(f"| {m.get('mode')} | {m['op']} | {m.get('slot')}={m.get('value')!r} | {m.get('form')} | "
                 f"{m['detail'][:100].replace('|', '/')} | {m.get('literal_same')} |")
    path = os.path.join(out_dir, "BINDING.md")
    with open(path, "w", encoding="utf-8") as fh:
        fh.write("\n".join(L) + "\n")
    return path
