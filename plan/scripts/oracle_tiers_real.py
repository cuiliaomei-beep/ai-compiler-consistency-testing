"""P1-2: oracle-tier analysis over the independent real root causes.

For every root cause in scripts/oracle_tiers_cases.py the stand-alone reproducer is executed ONCE per side
(eager, compiled as the draft specifies) in a child process; every observable is captured into one trace
(return value, dtype/shape/stride/device/layout, alias relation over inputs and outputs, inputs and
module-level state after the call, gradients, exception type / whether the program's own handler caught
it, process exit, float64 or mpmath reference).  The three cumulative oracle tiers are then evaluated
OFFLINE from the saved trace, so all tiers see the same execution:

    T1 = output values + ordinary crash / exception (compiled raises, or the process dies during the compiled
         call, where eager does not)
    T2 = T1 + metadata (dtype, shape, stride / memory layout, device, output structure)
    T3 = T2 + aliasing / identity, side effects / state, gradients, exception routing (both directions,
         exception type, handler), multi-precision reference, process survival (death after the call or
         on either side)

The seven observables of tcc/observe.py and the comparison rules of tcc/oracle.py are reused verbatim
(_o1_value .. _o6_gradient); this script only groups them into tiers and adds the observables the
oracle module does not compare (non-tensor state, opaque-object identity, handler, process, reference
relative error).

    python scripts/oracle_tiers_real.py run [--only C8,C41] [--workers 3]      # real root causes -> traces/
    python scripts/oracle_tiers_real.py control-corpus                          # 29-program corpus control
    python scripts/oracle_tiers_real.py control-autocast --acdtype bfloat16 --shard 0/2   # OpInfo autocast control
    python scripts/oracle_tiers_real.py report                                  # csv + REPORT.md
"""
from __future__ import annotations

import argparse
import csv
import glob
import hashlib
import json
import math
import os
import subprocess
import sys
import tempfile
import time
import traceback
from concurrent.futures import ThreadPoolExecutor, as_completed
from typing import Any, Dict, List, Optional

HERE = os.path.dirname(os.path.abspath(__file__))
PLAN = os.path.dirname(HERE)
sys.path.insert(0, PLAN)
sys.path.insert(0, HERE)

OUT_DIR = os.path.join(PLAN, "results", "p12_oracle_tiers")
TRACE_DIR = os.path.join(OUT_DIR, "traces")
CTRL_DIR = os.path.join(OUT_DIR, "control_traces")
MAX_ELEMS = 4096
TIERS = ("T1", "T2", "T3")


# =============================================================================================
# serialization of one execution (child side)
# =============================================================================================

def _torch():
    import torch
    return torch


def ser(o: Any) -> Any:
    torch = _torch()
    try:
        import numpy as np
    except Exception:  # noqa: BLE001
        np = None
    if isinstance(o, torch.Tensor):
        return ser_tensor(o, "tensor")
    if np is not None and isinstance(o, np.ndarray):
        try:
            return ser_tensor(torch.from_numpy(o.copy()), "ndarray")
        except Exception:  # noqa: BLE001
            return {"__opaque__": "ndarray", "repr": repr(o)[:200]}
    if np is not None and isinstance(o, np.generic):
        return ser(o.item())
    if isinstance(o, bool) or o is None or isinstance(o, (int, str)):
        return o
    if isinstance(o, float):
        return o
    if isinstance(o, complex):
        return {"__complex__": [o.real, o.imag]}
    if isinstance(o, (list, tuple)):
        kind = "list" if isinstance(o, list) else ("tuple" if type(o) is tuple else type(o).__name__)
        return {"__seq__": kind, "items": [ser(v) for v in o]}
    if isinstance(o, dict):
        return {"__map__": type(o).__name__, "items": [[ser(k), ser(v)] for k, v in o.items()]}
    if isinstance(o, torch.dtype):
        return {"__opaque__": "dtype", "repr": str(o)}
    try:
        rp = repr(o)[:200]
    except Exception:  # noqa: BLE001
        rp = "<unprintable>"
    return {"__opaque__": type(o).__name__, "repr": rp}


def ser_tensor(t, kind: str) -> Dict[str, Any]:
    torch = _torch()
    from tcc.observe import TensorMeta
    d: Dict[str, Any] = {"__tensor__": kind}
    m = TensorMeta.of(t)
    d["meta"] = m.as_dict() if m else None
    try:
        x = t.detach()
        if x.is_sparse or x.layout != torch.strided:
            d["values"] = None
            d["hash"] = None
            d["note"] = f"layout {x.layout}"
            return d
        x = x.cpu()
        if x.is_complex():
            x = torch.view_as_real(x.resolve_conj())
            d["complex"] = True
        n = x.numel()
        d["numel"] = int(t.numel())
        if n <= MAX_ELEMS * (2 if d.get("complex") else 1):
            d["values"] = x.reshape(-1).tolist()
        else:
            d["values"] = None
            d["hash"] = hashlib.sha256(x.contiguous().reshape(-1).numpy().tobytes()).hexdigest() if hasattr(x, "numpy") else None
            if x.is_floating_point():
                fin = x[torch.isfinite(x)]
                d["stats"] = {"nan": int(torch.isnan(x).sum()), "inf": int(torch.isinf(x).sum()),
                              "min": float(fin.min()) if fin.numel() else None, "max": float(fin.max()) if fin.numel() else None}
    except Exception as e:  # noqa: BLE001
        d["values"] = None
        d["error"] = f"{type(e).__name__}: {str(e)[:120]}"
    return d


class Opaque:
    """Stand-in for an object the trace could not serialize; never numerically comparable."""

    def __init__(self, type_name: str, rp: str = "", hash_: Optional[str] = None, meta=None):
        self.type_name, self.rp, self.hash, self.meta = type_name, rp, hash_, meta

    def __repr__(self):
        return f"<Opaque {self.type_name} {self.rp[:40]}>"


def deser(o: Any) -> Any:
    torch = _torch()
    if isinstance(o, dict):
        if "__tensor__" in o:
            meta = o.get("meta") or {}
            if o.get("values") is None:
                return Opaque(o["__tensor__"], o.get("note", ""), o.get("hash"), meta)
            try:
                dt = getattr(torch, meta["dtype"].split(".")[-1])
                if o.get("complex"):
                    base = torch.float64 if dt == torch.complex128 else torch.float32
                    t = torch.tensor(o["values"], dtype=base).reshape(-1, 2)
                    t = torch.view_as_complex(t.contiguous())
                else:
                    t = torch.tensor(o["values"], dtype=dt)
                return t.reshape(tuple(meta["shape"]))
            except Exception as e:  # noqa: BLE001
                return Opaque(o["__tensor__"], f"deser failed {e}", o.get("hash"), meta)
        if "__seq__" in o:
            items = [deser(v) for v in o["items"]]
            return items if o["__seq__"] == "list" else tuple(items)
        if "__map__" in o:
            return {deser(k) if not isinstance(k, (dict, list)) else repr(k): deser(v) for k, v in o["items"]}
        if "__complex__" in o:
            return complex(*o["__complex__"])
        if "__opaque__" in o:
            return Opaque(o["__opaque__"], o.get("repr", ""))
    return o


# =============================================================================================
# child: run one side of one sub-case and write the trace
# =============================================================================================

class Runner:
    def __init__(self, side: str, sub, out_path: str):
        self.side, self.sub, self.out_path = side, sub, out_path
        self.records: List[Dict[str, Any]] = []
        self.t0 = time.time()

    def compile(self, fn):
        torch = _torch()
        if self.side == "eager":
            return fn
        return torch.compile(fn, **(self.sub.compile or {}))

    def call(self, fn, args, kwargs=None, state=None, post=None, with_grad=False, note=None):
        from tcc.observe import observe
        kwargs = kwargs or {}
        exc = None
        out = None
        t0 = time.time()
        try:
            out = fn(*args, **kwargs)
            if post is not None:
                out = post(out)
        except KeyboardInterrupt:
            raise
        except BaseException as e:  # noqa: BLE001
            exc = e
        wall = time.time() - t0
        inputs = list(args) + list(kwargs.values())
        obs = observe(self.side, inputs, out, exc, with_grad=with_grad)
        rec = {
            "ok": obs.ok, "exception": obs.exception, "exception_msg": obs.exception_msg,
            "exception_inner": obs.exception_inner, "exc_frame": obs.exc_frame,
            "out_struct": obs.out_struct, "out_meta": [m.as_dict() if m else None for m in obs.out_meta],
            "alias_pairs": sorted(obs.alias), "n_inputs": obs.n_inputs,
            "outputs": ser(obs.outputs) if obs.ok else None,
            "inputs_after": ser(obs.inputs_after),
            "has_grads": obs.grads is not None, "grads": ser(obs.grads) if obs.grads is not None else None,
            "grad_error": obs.grad_error, "wall_s": round(wall, 4), "note": note,
            "caught_by_handler": (obs.ok if self.sub.has_handler else None),
        }
        if state is not None:
            try:
                rec["state_after"] = ser(state())
            except Exception as e:  # noqa: BLE001
                rec["state_after"] = {"__opaque__": "state-error", "repr": f"{type(e).__name__}: {e}"[:200]}
        self.records.append(rec)
        self.flush("calls")
        return rec

    def flush(self, phase: str):
        data = {"side": self.side, "phase": phase, "calls": self.records, "wall_s": round(time.time() - self.t0, 3)}
        tmp = self.out_path + ".tmp"
        with open(tmp, "w", encoding="utf-8") as fh:
            json.dump(data, fh)
        os.replace(tmp, self.out_path)


def _to64(args):
    torch = _torch()
    changed = False
    out = []
    for a in args:
        if isinstance(a, torch.Tensor) and a.layout == torch.strided:
            if a.is_floating_point() and a.dtype != torch.float64:
                b = a.detach().to(torch.float64)
                changed = True
            elif a.is_complex() and a.dtype != torch.complex128:
                b = a.detach().to(torch.complex128)
                changed = True
            else:
                b = a.detach().clone()
            if a.requires_grad:
                b.requires_grad_(True)
            out.append(b)
        else:
            out.append(a)
    return tuple(out), changed


def resolve(rc_id: str, sub_idx: int):
    """Return (RootCause-like, Sub) for a real root cause or a control program."""
    import oracle_tiers_cases as C
    if rc_id.startswith("CTRL-corpus:"):
        name = rc_id.split(":", 1)[1]
        import tcc.corpus  # noqa: F401  (registers the programs)
        from tcc.program import get
        p = get(name)

        def make(p=p):
            torch = _torch()
            torch.manual_seed(0)
            args = tuple(p.make_inputs(p.base_context))
            return C.Case(p.fn, args)
        s = C.Sub(name=name, make=make, primary=True, compile=dict(p.compile_options), grad=bool(p.check_grad),
                  fp64=None if p.skip_fp64 else "auto")
        r = C.RootCause(rc_id, [name], "corpus", "tcc/corpus.py", p.notes)
        r.subs = [s]
        return r, s
    r = C.by_id(rc_id)
    return r, r.subs[sub_idx]


def child_main(rc_id: str, sub_idx: int, side: str, out_path: str):
    torch = _torch()
    try:
        from tcc.compat import ensure_msvc_env
        ensure_msvc_env()
    except Exception:  # noqa: BLE001
        pass
    r, sub = resolve(rc_id, sub_idx)
    R = Runner(side, sub, out_path)
    R.flush("start")
    # settings that hold on both sides
    for k, v in (sub.dynamo_config or {}).items():
        setattr(torch._dynamo.config, k, v)
    patch_ctx = None
    if sub.inductor_config:
        patch_ctx = torch._inductor.config.patch(sub.inductor_config)
        patch_ctx.__enter__()
    if sub.pre is not None:
        sub.pre(side)
    torch.manual_seed(0)
    if sub.custom is not None:
        try:
            recs = sub.custom(R)
        except KeyboardInterrupt:
            raise
        except BaseException as e:  # noqa: BLE001  (an error while *building* the case)
            R.records.append({"ok": False, "exception": type(e).__name__, "exception_msg": str(e)[:1500],
                              "exception_inner": type(e).__name__, "exc_frame": None, "out_struct": "", "out_meta": [],
                              "alias_pairs": [], "n_inputs": 0, "outputs": None, "inputs_after": None, "has_grads": False,
                              "grads": None, "grad_error": None, "wall_s": 0.0, "note": "setup-error", "caught_by_handler": None})
    else:
        try:
            case = sub.make()
        except KeyboardInterrupt:
            raise
        except BaseException as e:  # noqa: BLE001
            R.records.append({"ok": False, "exception": type(e).__name__, "exception_msg": str(e)[:1500],
                              "exception_inner": type(e).__name__, "exc_frame": None, "out_struct": "", "out_meta": [],
                              "alias_pairs": [], "n_inputs": 0, "outputs": None, "inputs_after": None, "has_grads": False,
                              "grads": None, "grad_error": None, "wall_s": 0.0, "note": "setup-error", "caught_by_handler": None})
            case = None
        if case is not None:
            fn = R.compile(case.fn)
            calls = case.calls if case.calls is not None else [case.args]
            for args in calls:
                rec = R.call(fn, args, case.kwargs, state=case.state, post=case.post, with_grad=sub.grad)
                if side == "eager":
                    if sub.fp64 == "auto":
                        try:
                            args64, changed = _to64(args)
                            if changed:
                                from tcc.observe import observe
                                exc = None
                                out = None
                                try:
                                    out = case.fn(*args64, **(case.kwargs or {}))
                                    if case.post is not None:
                                        out = case.post(out)
                                except Exception as e:  # noqa: BLE001
                                    exc = e
                                obs = observe("fp64", list(args64), out, exc, with_grad=sub.grad)
                                rec["fp64"] = {"ok": obs.ok, "exception": obs.exception,
                                               "outputs": ser(obs.outputs) if obs.ok else None,
                                               "out_struct": obs.out_struct,
                                               "grads": ser(obs.grads) if obs.grads is not None else None,
                                               "has_grads": obs.grads is not None}
                        except Exception as e:  # noqa: BLE001
                            rec["fp64"] = {"ok": False, "exception": f"reference-error {type(e).__name__}"}
                    if case.ref is not None:
                        try:
                            rec["ref_outputs"] = ser(case.ref(args))
                        except Exception as e:  # noqa: BLE001
                            rec["ref_outputs"] = {"__opaque__": "ref-error", "repr": str(e)[:200]}
                R.flush("calls")
    R.flush("calls_done")
    if sub.teardown is not None:
        sub.teardown()
    R.flush("exit")


# =============================================================================================
# parent: spawn the two sides
# =============================================================================================

def run_side(rc_id: str, sub_idx: int, side: str, out_path: str, timeout: float) -> Dict[str, Any]:
    env = dict(os.environ)
    env["TORCHINDUCTOR_CACHE_DIR"] = tempfile.mkdtemp(prefix="tcc_p12_")
    env["PYTHONIOENCODING"] = "utf-8"
    if os.path.exists(out_path):
        os.remove(out_path)
    cmd = [sys.executable, os.path.abspath(__file__), "--child", rc_id, str(sub_idx), side, out_path]
    t0 = time.time()
    timed_out = False
    try:
        p = subprocess.run(cmd, capture_output=True, text=True, encoding="utf-8", errors="replace", env=env,
                           timeout=timeout, cwd=PLAN)
        rc, out, err = p.returncode, p.stdout, p.stderr
    except subprocess.TimeoutExpired as e:
        rc, out, err, timed_out = None, (e.stdout or ""), (e.stderr or ""), True
        if isinstance(out, bytes):
            out = out.decode("utf-8", "replace")
        if isinstance(err, bytes):
            err = err.decode("utf-8", "replace")
    data: Dict[str, Any] = {"side": side, "phase": "missing", "calls": []}
    if os.path.exists(out_path):
        try:
            data = json.load(open(out_path, encoding="utf-8"))
        except Exception as e:  # noqa: BLE001
            data = {"side": side, "phase": "unreadable", "calls": [], "read_error": str(e)}
    data["exit_code"] = rc
    data["exit_code_hex"] = (hex(rc & 0xFFFFFFFF) if isinstance(rc, int) else None)
    data["timed_out"] = timed_out
    data["wall_s_parent"] = round(time.time() - t0, 2)
    data["stdout_tail"] = out[-1500:]
    data["stderr_tail"] = err[-2500:]
    return data


def spec_of(sub) -> Dict[str, Any]:
    return {"name": sub.name, "primary": sub.primary, "compile": sub.compile, "grad": sub.grad, "fp64": sub.fp64,
            "has_handler": sub.has_handler, "inductor_config": sub.inductor_config, "dynamo_config": sub.dynamo_config,
            "custom": sub.custom is not None, "note": sub.note}


def run_subcase(rc, sub_idx: int, trace_dir: str, timeout: float) -> str:
    sub = rc.subs[sub_idx]
    safe = "".join(ch if ch.isalnum() or ch in "-_." else "_" for ch in sub.name)
    base = os.path.join(trace_dir, f"{rc.id.replace(':', '_')}__{sub_idx:02d}_{safe}")
    sides = {}
    for side in ("eager", "compiled"):
        sides[side] = run_side(rc.id, sub_idx, side, base + f".{side}.part.json", timeout)
        try:
            os.remove(base + f".{side}.part.json")
        except OSError:
            pass
    import torch
    trace = {"rc": rc.id, "members": rc.members, "layer": rc.layer, "reproducer": rc.reproducer, "title": rc.title,
             "status": rc.status, "sub": spec_of(sub), "sub_index": sub_idx, "torch": torch.__version__,
             "python": sys.version.split()[0], "platform": sys.platform, "when": time.strftime("%Y-%m-%d %H:%M:%S"),
             "eager": sides["eager"], "compiled": sides["compiled"]}
    path = base + ".json"
    with open(path, "w", encoding="utf-8") as fh:
        json.dump(trace, fh, indent=1)
    return path


def cmd_run(args):
    import oracle_tiers_cases as C
    os.makedirs(TRACE_DIR, exist_ok=True)
    only = set(args.only.split(",")) if args.only else None
    jobs = []
    for rc in C.CASES:
        if only and rc.id not in only:
            continue
        if not rc.reproducible:
            print(f"[skip] {rc.id}: not reproducible here ({rc.reason})", flush=True)
            continue
        for i, s in enumerate(rc.subs):
            if args.primary_only and not s.primary:
                continue
            jobs.append((rc, i))
    print(f"{len(jobs)} sub-cases, {args.workers} workers", flush=True)
    t0 = time.time()

    def work(job):
        rc, i = job
        t = time.time()
        p = run_subcase(rc, i, TRACE_DIR, args.timeout)
        ev = evaluate(json.load(open(p, encoding="utf-8")))
        return rc.id, rc.subs[i].name, p, ev, time.time() - t

    with ThreadPoolExecutor(max_workers=args.workers) as ex:
        futs = [ex.submit(work, j) for j in jobs]
        for f in as_completed(futs):
            try:
                rid, name, p, ev, dt = f.result()
                tiers = [t for t in TIERS if ev[t]]
                print(f"[{time.time() - t0:6.0f}s] {rid:4s} {name:34s} {dt:5.0f}s  weakest={ev['weakest'] or '-':3s}  "
                      f"{','.join(ev['observables'].get(ev['weakest'], [])) if ev['weakest'] else ''}", flush=True)
            except Exception as e:  # noqa: BLE001
                print("JOB FAILED:", type(e).__name__, e, flush=True)
                traceback.print_exc()
    print("RUN DONE", flush=True)


# =============================================================================================
# offline tier evaluation from a saved trace
# =============================================================================================

def _obs_from(rec: Dict[str, Any], mode: str):
    from tcc.observe import Observation, TensorMeta
    o = Observation(mode=mode, ok=bool(rec.get("ok")), exception=rec.get("exception"), exception_msg=rec.get("exception_msg"),
                    exception_inner=rec.get("exception_inner"), exc_frame=rec.get("exc_frame"))
    o.outputs = deser(rec.get("outputs")) if rec.get("ok") else None
    o.out_struct = rec.get("out_struct") or ""
    metas = []
    for m in rec.get("out_meta") or []:
        if m is None:
            metas.append(None)
        else:
            metas.append(TensorMeta(tuple(m["shape"]), m["dtype"], m["device"], tuple(m["stride"]), m["contiguous"],
                                    m["requires_grad"], m["storage_offset"], m["is_view"]))
    o.out_meta = metas
    o.inputs_after = deser(rec.get("inputs_after"))
    o.alias = frozenset(tuple(p) for p in rec.get("alias_pairs") or [])
    o.n_inputs = rec.get("n_inputs") or 0
    o.grads = deser(rec.get("grads")) if rec.get("has_grads") else None
    o.grad_error = rec.get("grad_error")
    return o


def _fp64_obs(rec: Dict[str, Any]):
    from tcc.observe import Observation
    f = rec.get("fp64")
    if not f or not f.get("ok"):
        return None
    o = Observation(mode="fp64", ok=True)
    o.outputs = deser(f.get("outputs"))
    o.out_struct = f.get("out_struct") or ""
    o.grads = deser(f.get("grads")) if f.get("has_grads") else None
    return o


def _walk_pairs(a: Any, b: Any, path: str, out: List):
    """Parallel walk over two serialized trees; yields (path, a_leaf, b_leaf) for leaves."""
    if isinstance(a, dict) and isinstance(b, dict):
        if "__seq__" in a and "__seq__" in b:
            if a["__seq__"] != b["__seq__"]:
                out.append((path, {"__type__": a["__seq__"]}, {"__type__": b["__seq__"]}))
            for i, (x, y) in enumerate(zip(a["items"], b["items"])):
                _walk_pairs(x, y, f"{path}[{i}]", out)
            if len(a["items"]) != len(b["items"]):
                out.append((path + ".len", len(a["items"]), len(b["items"])))
            return
        if "__map__" in a and "__map__" in b:
            ka = [json.dumps(k, sort_keys=True) for k, _ in a["items"]]
            kb = [json.dumps(k, sort_keys=True) for k, _ in b["items"]]
            if ka != kb:
                out.append((path + ".keys", ka, kb))
            da = {json.dumps(k, sort_keys=True): v for k, v in a["items"]}
            db = {json.dumps(k, sort_keys=True): v for k, v in b["items"]}
            for k in da:
                if k in db:
                    _walk_pairs(da[k], db[k], f"{path}[{k}]", out)
            return
        out.append((path, a, b))
        return
    out.append((path, a, b))


def _nontensor_diffs(a: Any, b: Any, label: str) -> List[str]:
    """Differences between two serialized trees, ignoring tensor contents (those go through O4)."""
    pairs: List = []
    _walk_pairs(a, b, label, pairs)
    diffs = []
    for path, x, y in pairs:
        if isinstance(x, dict) and "__tensor__" in x:
            continue
        if isinstance(y, dict) and "__tensor__" in y:
            diffs.append(f"{path}: tensor on one side only")
            continue
        if isinstance(x, dict) and "__opaque__" in x and isinstance(y, dict) and "__opaque__" in y:
            if x["__opaque__"] != y["__opaque__"]:
                diffs.append(f"{path}: object type {x['__opaque__']} vs {y['__opaque__']}")
            continue
        if isinstance(x, float) and isinstance(y, float) and math.isnan(x) and math.isnan(y):
            continue
        if x != y:
            diffs.append(f"{path}: {json.dumps(x)[:60]} vs {json.dumps(y)[:60]}")
    return diffs


def _identity_diffs(a: Any, b: Any) -> List[str]:
    pairs: List = []
    _walk_pairs(a, b, "output", pairs)
    diffs = []
    for path, x, y in pairs:
        if isinstance(x, dict) and isinstance(y, dict):
            tx = x.get("__opaque__") or x.get("__type__")
            ty = y.get("__opaque__") or y.get("__type__")
            if tx and ty and tx != ty:
                diffs.append(f"{path}: returned object type {tx} vs {ty}")
    return diffs


def _hash_diffs(a: Any, b: Any) -> List[str]:
    pairs: List = []
    _walk_pairs(a, b, "output", pairs)
    diffs = []
    for path, x, y in pairs:
        if isinstance(x, dict) and isinstance(y, dict) and x.get("hash") and y.get("hash") and x["hash"] != y["hash"]:
            diffs.append(f"{path}: large tensor content differs (sha256)")
    return diffs


def _dtype_only_difference(ref_out, comp_out, finding) -> bool:
    """True when an O1 'non-float values differ exactly' finding is caused by the dtype alone: integer / bool
    tensors whose values agree after casting to int64 (tcc.oracle._exact_equal treats a dtype mismatch as a value
    mismatch; here the dtype belongs to T2, the values to T1)."""
    torch = _torch()
    from tcc.observe import flatten, is_tensor
    if finding.index is None or "non-float values differ exactly" not in finding.detail:
        return False
    ri, _ = flatten(ref_out)
    ci, _ = flatten(comp_out)
    i = finding.index
    if i >= len(ri) or i >= len(ci):
        return False
    a, b = ri[i], ci[i]
    if not (is_tensor(a) and is_tensor(b)) or a.dtype == b.dtype or a.shape != b.shape:
        return False
    if a.is_floating_point() or b.is_floating_point() or a.is_complex() or b.is_complex():
        return False
    try:
        return bool(torch.equal(a.to(torch.int64), b.to(torch.int64)))
    except Exception:  # noqa: BLE001
        return False


def _value_findings_nanaware(ref_out, comp_out) -> List[str]:
    """Position-wise NaN/Inf pattern and finite-value comparison for float tensor pairs.

    tcc.oracle._float_pair_findings (reused for T1) derives its no-reference tolerance from max|eager|, which is
    NaN when the eager output contains a NaN; ``err > nan`` is then always False and every finite difference in the
    same tensor is masked (found 2026-09-25 on C13: np.fix gives 2.0 vs 1.0 next to a NaN element and nothing fired).
    Its NaN rule also only asks whether *any* NaN/Inf is present on one side.  This check restores the intended
    semantics: same dtype-aware tolerance (fallback_atol + fallback_rtol * max|finite eager|, floored by the ULP
    floor) over the finite positions, and a position-wise NaN / +-Inf pattern comparison."""
    torch = _torch()
    from tcc.observe import flatten, is_tensor
    from tcc import oracle as O
    cfg = O.Config()
    ri, _ = flatten(ref_out)
    ci, _ = flatten(comp_out)
    out = []
    for i, (a, b) in enumerate(zip(ri, ci)):
        if not (is_tensor(a) and is_tensor(b)) or a.shape != b.shape:
            continue
        if a.is_complex() and b.is_complex():
            a, b = torch.view_as_real(a.resolve_conj()), torch.view_as_real(b.resolve_conj())
        if not (a.is_floating_point() and b.is_floating_point()):
            continue
        a64, b64 = a.detach().double().reshape(-1), b.detach().double().reshape(-1)
        if a64.numel() == 0:
            continue
        na, nb = torch.isnan(a64), torch.isnan(b64)
        ia, ib = torch.isinf(a64), torch.isinf(b64)
        if not bool((na == nb).all()) or not bool((ia == ib).all()) or not bool((torch.sign(a64)[ia & ib] == torch.sign(b64)[ia & ib]).all()):
            k = int((na != nb).nonzero()[0]) if bool((na != nb).any()) else int((ia != ib).nonzero()[0]) if bool((ia != ib).any()) else -1
            out.append(f"output[{i}]: NaN/Inf pattern differs position-wise (first at flat index {k}: eager {float(a64[k]) if k >= 0 else '?'} vs compiled {float(b64[k]) if k >= 0 else '?'})")
            continue
        fin = ~(na | ia)
        if not bool(fin.any()):
            continue
        d = (a64[fin] - b64[fin]).abs()
        scale = float(a64[fin].abs().max())
        tol = max(cfg.fallback_atol + cfg.fallback_rtol * scale, O.noise_floor(a, cfg))
        err = float(d.max())
        if err > tol:
            k = int(d.argmax())
            out.append(f"output[{i}]: |eager-compiled| = {err:.3e} exceeds dtype-aware tolerance {tol:.3e} at a finite position "
                       f"(eager {float(a64[fin][k]):.6g} vs compiled {float(b64[fin][k]):.6g}; NaN-aware check)")
    return out


def _rel_ref_findings(ref_out, comp_out, truth, label: str) -> List[str]:
    """The relative-error criterion of scripts/special_vs_mpmath.py: compiled relative error > 1e-6 and
    > 100 x max(eager relative error, eps/4); plus NaN/Inf pattern vs the truth."""
    torch = _torch()
    from tcc.observe import flatten, is_tensor
    ri, _ = flatten(ref_out)
    ci, _ = flatten(comp_out)
    ti, _ = flatten(truth)
    out = []
    for i, (a, b) in enumerate(zip(ri, ci)):
        if i >= len(ti):
            break
        r = ti[i]
        if not (is_tensor(a) and is_tensor(b) and is_tensor(r)) or not a.is_floating_point() or not b.is_floating_point():
            continue
        if a.shape != b.shape or a.shape != r.shape:
            continue
        eps = torch.finfo(a.dtype).eps
        a64, b64, r64 = a.double().reshape(-1), b.double().reshape(-1), r.double().reshape(-1)
        fa, fb, fr = torch.isfinite(a64), torch.isfinite(b64), torch.isfinite(r64)
        if bool((fa == fr).all()) and not bool((fb == fr).all()):
            out.append(f"{label}[{i}]: compiled NaN/Inf pattern differs from the reference while eager matches it")
            continue
        m = fa & fb & fr & (r64 != 0)
        if not bool(m.any()):
            continue
        rel_e = ((a64 - r64).abs() / r64.abs())[m]
        rel_c = ((b64 - r64).abs() / r64.abs())[m]
        bad = (rel_c > 1e-6) & (rel_c > 100 * torch.clamp(rel_e, min=eps / 4))
        if bool(bad.any()):
            k = int(rel_c[bad].argmax())
            out.append(f"{label}[{i}]: compiled rel err {float(rel_c[bad][k]):.2e} vs eager {float(rel_e[bad][k]):.2e} "
                       f"against the reference ({int(bad.sum())} of {int(m.sum())} elements)")
    return out


def evaluate(trace: Dict[str, Any]) -> Dict[str, Any]:
    """Evaluate the three cumulative tiers from one saved trace (both sides)."""
    from tcc import oracle as O
    E, Cc = trace["eager"], trace["compiled"]
    e_calls, c_calls = E.get("calls", []), Cc.get("calls", [])
    planned = max(len(e_calls), len(c_calls), 1)
    findings: Dict[str, List[Dict[str, str]]] = {"T1": [], "T2": [], "T3": []}

    def add(tier, observable, detail):
        findings[tier].append({"observable": observable, "detail": str(detail)[:400]})

    def clean(side):
        return side.get("exit_code") == 0 and side.get("phase") == "exit" and not side.get("timed_out")

    def died_during_call(side, n_other):
        return (not clean(side)) and side.get("phase") in ("start", "calls", "missing", "unreadable") and len(side.get("calls", [])) < max(n_other, 1)

    cfg_strict = O.Config(strict_stride=True)
    cfg_lenient = O.Config(strict_stride=False)
    t2_lenient_hits = 0

    # ---- process level ----
    if died_during_call(Cc, len(e_calls)) and not died_during_call(E, len(c_calls)):
        add("T1", "crash", f"process died during the compiled call (exit {Cc.get('exit_code_hex')}, timed_out={Cc.get('timed_out')}); "
                           f"eager completed {len(e_calls)} call(s)")
    elif died_during_call(E, len(c_calls)):
        add("T3", "process", f"process died during the EAGER call (exit {E.get('exit_code_hex')})")
    for side_name, side in (("eager", E), ("compiled", Cc)):
        if not clean(side) and not died_during_call(side, planned):
            add("T3", "process", f"{side_name} process did not exit cleanly after the call(s): phase={side.get('phase')} "
                                 f"exit={side.get('exit_code_hex')} timed_out={side.get('timed_out')}")

    # ---- per call ----
    for i, (er, cr) in enumerate(zip(e_calls, c_calls)):
        tag = f"call{i}" if planned > 1 else ""
        ref, test = _obs_from(er, "eager"), _obs_from(cr, "compiled")
        fp64 = _fp64_obs(er)
        # T1: compiled raises where eager returned
        if ref.ok and not test.ok:
            add("T1", "exception", f"{tag} compiled raised {test.exception} ({(test.exception_msg or '')[:120]}), eager returned")
        # T3: routing in the other direction / type parity / handler
        if (not ref.ok) and test.ok:
            add("T3", "exception-routing", f"{tag} eager raised {ref.exception} ({(ref.exception_msg or '')[:100]}), compiled returned")
        if (not ref.ok) and (not test.ok):
            a, b = O._program_exception(ref), O._program_exception(test)
            if a != b:
                add("T3", "exception-type", f"{tag} exception type differs: eager {ref.exception}/{a} vs compiled {test.exception}/{b}")
        if er.get("caught_by_handler") is not None and cr.get("caught_by_handler") is not None \
                and er["caught_by_handler"] != cr["caught_by_handler"]:
            add("T3", "handler", f"{tag} program's own handler caught the error on eager={er['caught_by_handler']} compiled={cr['caught_by_handler']}")
        if not (ref.ok and test.ok):
            # nothing else is comparable when one side raised; inputs / state may still differ
            if er.get("inputs_after") is not None and cr.get("inputs_after") is not None:
                for d in _nontensor_diffs(er.get("inputs_after"), cr.get("inputs_after"), "input"):
                    add("T3", "state", f"{tag} {d}")
            continue
        # T1 value
        opaque: List[int] = []
        o1 = [f for f in O._o1_value(ref, test, None, cfg_lenient, opaque) if not _dtype_only_difference(ref.outputs, test.outputs, f)]
        for f in o1:
            add("T1", "value", f"{tag} {f.detail}")
        flagged = {f.index for f in o1 if f.index is not None}
        for d in _value_findings_nanaware(ref.outputs, test.outputs):
            idx = int(d.split("]")[0].split("[")[1]) if d.startswith("output[") else None
            if idx not in flagged:
                add("T1", "value", f"{tag} {d}")
        for d in _hash_diffs(er.get("outputs"), cr.get("outputs")):
            add("T1", "value", f"{tag} {d}")
        # T2 metadata (strict stride); count the lenient variant separately
        for f in O._o2_metadata(ref, test, cfg_strict):
            add("T2", "metadata" if f.kind == O.METADATA else "structure", f"{tag} {f.detail}")
        t2_lenient_hits += len(O._o2_metadata(ref, test, cfg_lenient))
        # T3 alias / identity
        for f in O._o5_alias(ref, test, True):
            add("T3", "alias", f"{tag} {f.detail}")
        for d in _identity_diffs(er.get("outputs"), cr.get("outputs")):
            add("T3", "identity", f"{tag} {d}")
        # T3 mutation of tensor inputs + non-tensor inputs + module-level state
        for f in O._o4_mutation(ref, test, cfg_lenient):
            add("T3", "mutation", f"{tag} {f.detail}")
        for d in _nontensor_diffs(er.get("inputs_after"), cr.get("inputs_after"), "input"):
            add("T3", "state", f"{tag} {d}")
        if er.get("state_after") is not None or cr.get("state_after") is not None:
            for d in _nontensor_diffs(er.get("state_after"), cr.get("state_after"), "state"):
                add("T3", "state", f"{tag} {d}")
            # tensors inside the state snapshot
            sa, sb = deser(er.get("state_after")), deser(cr.get("state_after"))
            from tcc.observe import Observation
            oa, ob = Observation("eager"), Observation("compiled")
            oa.inputs_after, ob.inputs_after = sa, sb
            for f in O._o4_mutation(oa, ob, cfg_lenient):
                add("T3", "state", f"{tag} module-level state: {f.detail}")
        # T3 gradients
        for f in O._o6_gradient(ref, test, fp64, cfg_lenient):
            add("T3", "gradient", f"{tag} {f.detail}")
        # T3 multi-precision reference
        if fp64 is not None:
            for f in O._o1_value(ref, test, fp64, cfg_lenient, []):
                if "fp64" in f.detail or "float64" in f.detail:
                    add("T3", "reference", f"{tag} {f.detail}")
            for d in _rel_ref_findings(ref.outputs, test.outputs, fp64.outputs, "float64 reference"):
                add("T3", "reference", f"{tag} {d}")
        if er.get("ref_outputs") is not None:
            truth = deser(er["ref_outputs"])
            for d in _rel_ref_findings(ref.outputs, test.outputs, truth, "mpmath reference"):
                add("T3", "reference", f"{tag} {d}")
    # cumulative sets
    det = {"T1": bool(findings["T1"]), "T2": bool(findings["T1"] or findings["T2"]),
           "T3": bool(findings["T1"] or findings["T2"] or findings["T3"])}
    weakest = next((t for t in TIERS if det[t]), None)
    observables = {t: sorted({f["observable"] for f in findings[t]}) for t in TIERS}
    return {"detected": det, "weakest": weakest, "observables": observables, "findings": findings,
            "T1": findings["T1"], "T2": findings["T2"], "T3": findings["T3"],
            "t2_lenient_hits": t2_lenient_hits, "t2_new_strict_only": bool(findings["T2"]) and t2_lenient_hits == 0}


# =============================================================================================
# controls
# =============================================================================================

def cmd_control_corpus(args):
    import tcc.corpus  # noqa: F401
    from tcc.program import all_programs, EXPECT_CONSISTENT
    import oracle_tiers_cases as C
    os.makedirs(CTRL_DIR, exist_ok=True)
    progs = [p for p in all_programs() if p.expect == EXPECT_CONSISTENT]
    print(f"{len(progs)} corpus programs (expect=consistent)", flush=True)

    def work(p):
        rc, s = resolve(f"CTRL-corpus:{p.name}", 0)
        t = time.time()
        path = run_subcase(rc, 0, CTRL_DIR, args.timeout)
        ev = evaluate(json.load(open(path, encoding="utf-8")))
        return p.name, path, ev, time.time() - t

    with ThreadPoolExecutor(max_workers=args.workers) as ex:
        for f in as_completed([ex.submit(work, p) for p in progs]):
            name, path, ev, dt = f.result()
            print(f"{name:24s} {dt:5.0f}s weakest={ev['weakest'] or '-'} {ev['observables'].get(ev['weakest'], []) if ev['weakest'] else ''}", flush=True)
    print("CORPUS CONTROL DONE", flush=True)


def cmd_control_autocast(args):
    """OpInfo ops under autocast (the 8.11 negative result: 530 ops x 2 dtypes, 0 differences).
    Both sides run in this process (one long child); the same trace schema and evaluate() are used."""
    try:
        from tcc.compat import ensure_msvc_env
        ensure_msvc_env()
    except Exception:  # noqa: BLE001
        pass
    import torch
    from torch.testing._internal.common_methods_invocations import op_db
    import opinfo_edge_sweep as oes
    import autocast_sweep as acs
    import oracle_tiers_cases as C
    acdt = getattr(torch, args.acdtype)
    os.makedirs(OUT_DIR, exist_ok=True)
    shard_i, shard_n = (int(x) for x in args.shard.split("/"))
    out_path = os.path.join(OUT_DIR, f"control_autocast_{args.acdtype}_s{shard_i}.jsonl")
    # the control set = ops whose sweep verdict was "ok" (the paper's consistent set)
    ok_ops = None
    sweep = os.path.join(PLAN, "results", "autocast", f"{args.acdtype}.jsonl")
    if os.path.exists(sweep):
        ok_ops = {json.loads(l)["op"] for l in open(sweep, encoding="utf-8") if json.loads(l).get("verdict") == "ok"}
    done = set()
    if os.path.exists(out_path):
        for line in open(out_path, encoding="utf-8"):
            try:
                done.add(json.loads(line)["op"])
            except Exception:  # noqa: BLE001
                pass
    ops = [op for op in op_db if not any(s in op.name for s in oes.SKIP_SUBSTR) and (ok_ops is None or op.name in ok_ops)]
    seen = set()
    uniq = []
    for op in ops:
        if op.name not in seen:
            seen.add(op.name)
            uniq.append(op)
    ops = [op for k, op in enumerate(uniq) if k % shard_n == shard_i and op.name not in done]
    print(f"torch {torch.__version__}; autocast {acdt}; shard {shard_i}/{shard_n}: {len(ops)} ops to do ({len(done)} done)", flush=True)
    sub = C.Sub(name="autocast", make=lambda: None, primary=True, compile={}, grad=False, fp64=None)
    t_all = time.time()
    for n, op in enumerate(ops, 1):
        rec = {"op": op.name, "acdtype": args.acdtype, "samples": 0, "results": []}
        t0 = time.time()
        try:
            if not op.supports_dtype(torch.float32, "cpu"):
                rec["verdict"] = "NO_SAMPLES:dtype"
            else:
                samples = acs.take_samples(op.sample_inputs("cpu", torch.float32, requires_grad=False), args.samples)
                fn = op.get_op()
                for si, s in enumerate(samples):
                    inp, a_, kw = s.input, s.args, s.kwargs
                    sides = {}
                    for side in ("eager", "compiled"):
                        torch._dynamo.reset()
                        import gc
                        gc.collect()
                        tmp = os.path.join(tempfile.gettempdir(), f"tcc_p12_ac_{os.getpid()}.json")
                        R = Runner(side, sub, tmp)
                        # fresh copies so that in-place ops do not leak between the sides
                        from tcc.observe import clone_tree
                        inp2, a2, kw2 = clone_tree(inp), clone_tree(a_), clone_tree(kw)
                        g = fn if side == "eager" else torch.compile(fn)
                        with torch.autocast("cpu", dtype=acdt):
                            R.call(g, (inp2, *a2), kw2, with_grad=False)
                        sides[side] = {"side": side, "phase": "exit", "calls": R.records, "exit_code": 0, "timed_out": False}
                        try:
                            os.remove(tmp)
                        except OSError:
                            pass
                    trace = {"rc": f"CTRL-autocast:{op.name}", "sub": spec_of(sub), "eager": sides["eager"], "compiled": sides["compiled"]}
                    ev = evaluate(trace)
                    rec["samples"] += 1
                    rec["results"].append({"i": si, "detected": ev["detected"], "weakest": ev["weakest"], "observables": ev["observables"],
                                           "findings": {t: ev["findings"][t][:3] for t in TIERS},
                                           "t2_lenient_hits": ev["t2_lenient_hits"],
                                           "eager_exc": sides["eager"]["calls"][0].get("exception"),
                                           "compiled_exc": sides["compiled"]["calls"][0].get("exception")})
                rec["verdict"] = "alarm" if any(r_["weakest"] for r_ in rec["results"]) else "ok"
        except Exception as e:  # noqa: BLE001
            rec["verdict"] = "ERROR:" + type(e).__name__
            rec["error"] = str(e)[:300]
        with open(out_path, "a", encoding="utf-8") as fh:
            fh.write(json.dumps(rec) + "\n")
        if rec["verdict"] != "ok" or n % 25 == 0:
            print(f"[{n}/{len(ops)}] {op.name}: {rec['verdict']} ({time.time() - t0:.0f}s, total {time.time() - t_all:.0f}s)"
                  + (f"  {[r_['weakest'] for r_ in rec['results']]}" if rec.get("results") else ""), flush=True)
    print("AUTOCAST CONTROL DONE", flush=True)


# =============================================================================================
# report
# =============================================================================================

def _load_traces(d: str) -> List[Dict[str, Any]]:
    out = []
    for p in sorted(glob.glob(os.path.join(d, "*.json"))):
        if p.endswith(".part.json"):
            continue
        try:
            out.append(json.load(open(p, encoding="utf-8")))
        except Exception as e:  # noqa: BLE001
            print("unreadable trace", p, e)
    return out


def cmd_report(args):
    import oracle_tiers_cases as C
    traces = _load_traces(TRACE_DIR)
    by_rc: Dict[str, List[Dict[str, Any]]] = {}
    for t in traces:
        by_rc.setdefault(t["rc"], []).append(t)
    rows_rc, rows_tiers = [], []
    per_sub_rows = []
    agg = {"all": {t: set() for t in TIERS}, "primary": {t: set() for t in TIERS}}
    weakest_hist = {"all": {}, "primary": {}}
    not_repro = []
    for rc in C.CASES:
        tr = sorted(by_rc.get(rc.id, []), key=lambda t: t["sub_index"])
        repro_here = rc.reproducible
        reason = rc.reason
        evs = [(t, evaluate(t)) for t in tr]
        # a root cause whose every sub-case ran but nothing fired is "not detected" (reported honestly), not "not reproducible"
        if rc.reproducible and not tr:
            repro_here, reason = False, "no trace (not run)"
        det_all = {t: any(ev["detected"][t] for _, ev in evs) for t in TIERS}
        prim = [(t, ev) for t, ev in evs if t["sub"]["primary"]]
        det_p = {t: any(ev["detected"][t] for _, ev in prim) for t in TIERS}
        weakest_all = next((t for t in TIERS if det_all[t]), None)
        weakest_p = next((t for t in TIERS if det_p[t]), None)
        obs_all = sorted({o for _, ev in evs if ev["weakest"] == weakest_all for o in ev["observables"].get(weakest_all, [])}) if weakest_all else []
        obs_p = sorted({o for _, ev in prim if ev["weakest"] == weakest_p for o in ev["observables"].get(weakest_p, [])}) if weakest_p else []
        rows_rc.append({"root_cause_id": rc.id, "member_items": ";".join(rc.members), "layer": rc.layer,
                        "reproducer_path": rc.reproducer, "reproducible_here": "yes" if (repro_here and weakest_all) else ("no" if not repro_here else "ran, no tier fired"),
                        "reason": reason, "status": rc.status, "title": rc.title, "n_subcases": len(rc.subs), "n_subcases_run": len(tr)})
        if repro_here and weakest_all:
            for t in TIERS:
                if det_all[t]:
                    agg["all"][t].add(rc.id)
                if det_p[t]:
                    agg["primary"][t].add(rc.id)
            weakest_hist["all"][weakest_all] = weakest_hist["all"].get(weakest_all, 0) + 1
            if weakest_p:
                weakest_hist["primary"][weakest_p] = weakest_hist["primary"].get(weakest_p, 0) + 1
        else:
            not_repro.append((rc, reason if not repro_here else "all sub-cases ran; no tier fired on this machine"))
        rows_tiers.append({"root_cause_id": rc.id, "T1": int(det_all["T1"]) if repro_here else "", "T2": int(det_all["T2"]) if repro_here else "",
                           "T3": int(det_all["T3"]) if repro_here else "", "weakest_tier": weakest_all or ("" if not repro_here else "none"),
                           "observable_that_fires": ";".join(obs_all),
                           "T1_primary": int(det_p["T1"]) if repro_here else "", "T2_primary": int(det_p["T2"]) if repro_here else "",
                           "T3_primary": int(det_p["T3"]) if repro_here else "", "weakest_tier_primary": weakest_p or ("" if not repro_here else "none"),
                           "observable_primary": ";".join(obs_p), "n_subcases_run": len(tr),
                           "reproducible_here": rows_rc[-1]["reproducible_here"]})
        for t, ev in evs:
            per_sub_rows.append({"root_cause_id": rc.id, "subcase": t["sub"]["name"], "primary": int(t["sub"]["primary"]),
                                 "weakest": ev["weakest"] or "none",
                                 "T1": int(ev["detected"]["T1"]), "T2": int(ev["detected"]["T2"]), "T3": int(ev["detected"]["T3"]),
                                 "observables": ";".join(ev["observables"].get(ev["weakest"], [])) if ev["weakest"] else "",
                                 "eager_exc": (t["eager"]["calls"][0].get("exception") if t["eager"].get("calls") else None),
                                 "compiled_exc": (t["compiled"]["calls"][0].get("exception") if t["compiled"].get("calls") else None),
                                 "compiled_exit": t["compiled"].get("exit_code_hex"), "compiled_phase": t["compiled"].get("phase"),
                                 "first_finding": (next((f["detail"] for tt in TIERS for f in ev["findings"][tt]), ""))[:200]})
    os.makedirs(OUT_DIR, exist_ok=True)
    with open(os.path.join(OUT_DIR, "root_causes.csv"), "w", newline="", encoding="utf-8") as fh:
        w = csv.DictWriter(fh, fieldnames=list(rows_rc[0].keys()))
        w.writeheader()
        w.writerows(rows_rc)
    with open(os.path.join(OUT_DIR, "tiers.csv"), "w", newline="", encoding="utf-8") as fh:
        w = csv.DictWriter(fh, fieldnames=list(rows_tiers[0].keys()))
        w.writeheader()
        w.writerows(rows_tiers)
    with open(os.path.join(OUT_DIR, "subcases.csv"), "w", newline="", encoding="utf-8") as fh:
        w = csv.DictWriter(fh, fieldnames=list(per_sub_rows[0].keys()))
        w.writeheader()
        w.writerows(per_sub_rows)

    # ---- controls ----
    ctrl_corpus = _load_traces(CTRL_DIR)
    corpus_rows = []
    for t in ctrl_corpus:
        ev = evaluate(t)
        corpus_rows.append({"program": t["rc"].split(":", 1)[1], "weakest": ev["weakest"], "detected": ev["detected"],
                            "observables": ev["observables"], "t2_lenient_hits": ev["t2_lenient_hits"],
                            "findings": {tt: ev["findings"][tt][:3] for tt in TIERS},
                            "eager_exc": (t["eager"]["calls"][0].get("exception") if t["eager"].get("calls") else None),
                            "compiled_exc": (t["compiled"]["calls"][0].get("exception") if t["compiled"].get("calls") else None)})
    ac_rows = []
    for p in sorted(glob.glob(os.path.join(OUT_DIR, "control_autocast_*_s*.jsonl"))):
        for line in open(p, encoding="utf-8"):
            try:
                ac_rows.append(json.loads(line))
            except Exception:  # noqa: BLE001
                pass
    summary = {"n_root_causes": len(C.CASES), "n_reproducible_detected": len(C.CASES) - len(not_repro),
               "detected_all": {t: sorted(agg["all"][t]) for t in TIERS}, "detected_primary": {t: sorted(agg["primary"][t]) for t in TIERS},
               "weakest_hist_all": weakest_hist["all"], "weakest_hist_primary": weakest_hist["primary"],
               "not_reproducible": [(r.id, why) for r, why in not_repro],
               "corpus_control": corpus_rows, "autocast_control_n": len(ac_rows),
               "autocast_alarms": [r for r in ac_rows if r.get("verdict") not in ("ok", "NO_SAMPLES:dtype")]}
    with open(os.path.join(OUT_DIR, "summary.json"), "w", encoding="utf-8") as fh:
        json.dump(summary, fh, indent=1, default=str)
    write_report(C, rows_rc, rows_tiers, per_sub_rows, summary, corpus_rows, ac_rows, not_repro)
    print(json.dumps({k: (v if not isinstance(v, list) or len(v) < 20 else len(v)) for k, v in summary.items()
                      if k not in ("corpus_control", "autocast_alarms")}, indent=1, default=str))


def write_report(C, rows_rc, rows_tiers, per_sub_rows, summary, corpus_rows, ac_rows, not_repro):
    import torch
    L = []
    A = L.append
    det = summary["detected_all"]
    detp = summary["detected_primary"]
    n_det = summary["n_reproducible_detected"]
    A("# P1-2 Oracle-tier analysis over independent real root causes\n")
    A(f"Generated {time.strftime('%Y-%m-%d %H:%M')} on {sys.platform}, torch {torch.__version__}, Python {sys.version.split()[0]} "
      f"(CPU only; the machine that produced the drafts).\n")
    A("## Method\n")
    A("* **Unit of analysis.** The 73 report items of `paper_tcc/data/findings.csv` minus the 5 cross-compiler items "
      f"({', '.join(C.EXCLUDED_CROSS_COMPILER)}) and the 10 items attributed outside the pipeline ({', '.join(C.EXCLUDED_OUTSIDE_PIPELINE)}) "
      f"leave 58 pipeline-attributed items. Comments were merged into their parent issue (C26->C3, C31->C22, C30/C38->C37, C43->C42, C45->C44) "
      f"and no other pair shares a root cause according to the ledger (B2 and B17 have different fix PRs, #197768 vs #197221; drafts 20 and 27 "
      f"argue different mechanisms for C21 and C28). Result: **{summary['n_root_causes']} root causes** (`root_causes.csv`). Comments filed under "
      "issues owned by others (C15, C21, C25, C28) are root causes of their own that we contributed to.")
    A("* **Reproducer.** The first ```python block of each issue draft, re-expressed as (fn, args) in `scripts/oracle_tiers_cases.py`; the draft's "
      "list of triggering programs becomes the root cause's sub-cases, the first (minimal trigger) is marked *primary*. Compilation follows the draft "
      "(backend, dynamic, fullgraph, Inductor/Dynamo config, compiled autograd, optimizer step, export + AOTInductor).")
    A("* **One execution per side.** `scripts/oracle_tiers_real.py run` executes every sub-case once in eager and once compiled, each in its own child "
      "process with a fresh Inductor cache, and stores one trace (`traces/*.json`) holding all observables: return value (tensors serialized with values, "
      "dtype, shape, stride, device, contiguity, storage offset, is_view), the storage-sharing relation over inputs and outputs (tcc.observe.alias_relation), "
      "inputs and module-level state after the call, gradients (tcc.observe._gradients when the draft computes them), exception type / inner type / whether the "
      "program's own handler caught it, process exit code and exit phase (died during the call vs after it), a float64 re-execution of the same eager call and, "
      "for the accuracy findings, an mpmath 30-digit reference.")
    A("* **Tiers, evaluated offline from the same trace** (`evaluate()`): T1 = `tcc.oracle._o1_value` without reference (dtype-aware tolerance) + "
      "compiled raises where eager returned + process death during the compiled call; T2 = T1 + `_o2_metadata` with `strict_stride=True` (shape, dtype, "
      "device, stride, output structure); T3 = T2 + `_o5_alias`, opaque-object identity, `_o4_mutation` on tensor inputs, exact comparison of non-tensor "
      "inputs and module-level state, `_o6_gradient`, exception routing (eager raises / compiled returns, exception-type parity, handler parity), the "
      "float64 rule of `_o1_value(fp64=...)` plus the relative criterion of `scripts/special_vs_mpmath.py` (compiled rel. err > 1e-6 and > 100 x max(eager rel. "
      "err, eps/4)), and process survival (death after the call or on the eager side). A root cause is detected at a tier when any of its sub-cases is; "
      "*primary-only* numbers use the minimal trigger alone.")
    A("\n## Results over the root causes\n")
    A(f"| | T1 | T2 (cum.) | T3 (cum.) | not detected / not reproducible here |\n|---|---|---|---|---|")
    A(f"| all sub-cases ({n_det} root causes reproduced) | {len(det['T1'])} | {len(det['T2'])} | {len(det['T3'])} | {len(not_repro)} |")
    A(f"| primary sub-case only | {len(detp['T1'])} | {len(detp['T2'])} | {len(detp['T3'])} | |")
    A("\nWeakest detecting tier (all sub-cases): " + ", ".join(f"{t}: {summary['weakest_hist_all'].get(t, 0)}" for t in TIERS)
      + f"; primary only: " + ", ".join(f"{t}: {summary['weakest_hist_primary'].get(t, 0)}" for t in TIERS) + ".")
    A(f"\nUnique to a tier (all sub-cases): T2 adds {sorted(set(det['T2']) - set(det['T1']))}; T3 adds {sorted(set(det['T3']) - set(det['T2']))}.  "
      f"Primary only: T2 adds {sorted(set(detp['T2']) - set(detp['T1']))}; T3 adds {sorted(set(detp['T3']) - set(detp['T2']))}.")
    A(f"\nDetected at T1: {', '.join(det['T1'])}\n\nDetected only from T2: {', '.join(sorted(set(det['T2']) - set(det['T1'])))}\n\n"
      f"Detected only from T3: {', '.join(sorted(set(det['T3']) - set(det['T2'])))}")
    A("\n### Per root cause\n")
    A("| RC | members | layer | status | T1 | T2 | T3 | weakest (all) | observable | weakest (primary) | observable (primary) | sub-cases run |")
    A("|---|---|---|---|---|---|---|---|---|---|---|---|")
    for r_, t_ in zip(rows_rc, rows_tiers):
        A(f"| {r_['root_cause_id']} | {r_['member_items']} | {r_['layer']} | {r_['status'] or 'pending'} | {t_['T1']} | {t_['T2']} | {t_['T3']} | "
          f"{t_['weakest_tier']} | {t_['observable_that_fires']} | {t_['weakest_tier_primary']} | {t_['observable_primary']} | {t_['n_subcases_run']}/{r_['n_subcases']} |")
    A("\n### Per sub-case\n")
    A("| RC | sub-case | primary | weakest | observables | eager exc | compiled exc | compiled exit | first finding |")
    A("|---|---|---|---|---|---|---|---|---|")
    for s in per_sub_rows:
        A(f"| {s['root_cause_id']} | {s['subcase']} | {s['primary']} | {s['weakest']} | {s['observables']} | {s['eager_exc'] or ''} | "
          f"{s['compiled_exc'] or ''} | {s['compiled_exit'] or ''}/{s['compiled_phase']} | {s['first_finding'].replace('|', '/')} |")
    A("\n## Not reproducible here / not detected\n")
    if not_repro:
        for r_, why in not_repro:
            A(f"* **{r_.id}** ({', '.join(r_.members)}; {r_.layer}): {r_.title} -- {why}")
    else:
        A("(none)")
    notes = [(rc.id, s.name, s.note) for rc in C.CASES for s in rc.subs if s.note]
    if notes:
        A("\nSub-case notes:")
        for rid, name, note in notes:
            A(f"* {rid} / {name}: {note}")
    A("\n## Harness observations (affect how the numbers should be read)\n")
    A("* **T1 crash vs T3 process.** T1 counts a process that dies *during* the compiled call (B3: the trace has no call record and a "
      "non-zero exit). C46 finishes the call correctly and dies when the AOTI runner is destroyed afterwards; the harness records the "
      "call, then the teardown kills the process before the exit marker is written, so it is a T3 'process survival' finding, not T1.")
    A("* **tcc.oracle fallback tolerance is undefined when the eager output contains NaN.** `_float_pair_findings` scales its "
      "no-reference tolerance by `max|eager|`, which is NaN when any element is NaN, and `err > nan` is always False; its NaN rule only "
      "asks whether *any* NaN/Inf exists on one side. C13 (`np.fix`: 2.0 vs 1.0 next to a NaN element) fired nothing until the "
      "position-wise, NaN-aware check `_value_findings_nanaware` was added to T1 (same tolerance over finite positions). tcc/ itself was "
      "not modified (hard rule); the paper's harness normally has a float64 reference, whose `noise_floor` is finite-aware, so the "
      "reference path is not affected.")
    A("* **Value vs dtype.** `tcc.oracle._exact_equal` treats a dtype mismatch of integer/bool tensors as a value mismatch; for the "
      "tier separation T1 ignores such a finding when the values agree after casting to int64 (C29: uint8 `1` vs bool `True` is a T2 "
      "metadata finding, its downstream `any(x)*200+100` = 44 vs 300 a T1 value finding). Float outputs of different dtype are compared "
      "numerically, so B8's fp16 x bf16 / bf16 x fp64 sub-cases are T1 (the wrong dtype loses precision) while its primary sub-case is T2.")
    A("* **B7 is state dependent.** The internal assert only fires when a jvp already ran in the process (the draft calls the eager jvp "
      "first). Re-expressing the draft as module-level functions of the registry made Dynamo skip the frame and fall back to eager "
      "*successfully* (no tier fires); the draft's code block executed verbatim (as `scripts/run_issue_snippet.py` does) raises, and that "
      "verbatim sub-case is the primary one. The two re-expressed sub-cases are kept in `subcases.csv` with weakest = none.")
    A("* **C42 is a T1 finding through the program's output.** The draft's program drains the returned generator outside the compiled "
      "region (`consume()`); the observed output is that list (type name, yielded values, `StopIteration.value`), and the "
      "`StopIteration.value` 'done' vs None difference is a plain value difference. The paper's table attributes C42 to the identity "
      "observable; with the bare generator as output (no consumer) it would be an opaque-object type difference (T3 identity / T2 structure).")
    A("* **Exception-routing direction.** Everything the paper calls 'validation lost' (B12, C5, C22 on 2.14, C23, C37/C30) is *eager raises, "
      "compiled returns*: invisible to T1 by construction, detected only by the two-directional exception oracle of T3. C22 is T3 here "
      "because the 2.14 eager `clamp` raises; on nightly eager returns the input unchanged and the same case would be a T1 value finding.")
    A("* **B18** raises on both sides (eager: RuntimeError from the ambiguous tensor bool; compiled: RecursionError), so only the "
      "exception-type parity of T3 sees it.")
    A("* **Autocast control alarms** are value differences of a few bf16 ULPs under `autocast(bfloat16)` (no float64 reference is "
      "possible under autocast); the paper's sweep used a 3e-2 relative tolerance and its harness lets `torch._dynamo.utils.same(fp64_ref)` "
      "veto such findings, so they count as T1 false positives of the tolerance rule used here.")
    # ---- false positives ----
    A("\n## False positives on the consistent control sets\n")
    fp = {t: sum(1 for r_ in corpus_rows if r_["detected"][t]) for t in TIERS}
    fp_lenient_t2 = sum(1 for r_ in corpus_rows if r_["detected"]["T1"] or r_["t2_lenient_hits"])
    A(f"**Corpus control**: the {len(corpus_rows)} unmodified programs of the controlled benchmark (`tcc/corpus.py`, expect=consistent), eager vs "
      f"`torch.compile` with the program's own compile options, same tracer and tiers. Alarms: T1 {fp['T1']}, T2 {fp['T2']} "
      f"(T2 with the paper's non-strict stride rule: {fp_lenient_t2}), T3 {fp['T3']} of {len(corpus_rows)}.")
    if any(r_["weakest"] for r_ in corpus_rows):
        A("\n| program | weakest | observables | first finding |\n|---|---|---|---|")
        for r_ in corpus_rows:
            if r_["weakest"]:
                ff = next((f["detail"] for tt in TIERS for f in r_["findings"][tt]), "")
                A(f"| {r_['program']} | {r_['weakest']} | {';'.join(r_['observables'].get(r_['weakest'], []))} | {ff[:160].replace('|', '/')} |")
    n_ops = len(ac_rows)
    n_samples = sum(r_.get("samples", 0) for r_ in ac_rows)
    n_ok = sum(1 for r_ in ac_rows if r_.get("verdict") == "ok")
    n_err = sum(1 for r_ in ac_rows if str(r_.get("verdict", "")).startswith("ERROR") or r_.get("verdict") == "NO_SAMPLES:dtype")
    alarms = [r_ for r_ in ac_rows if r_.get("verdict") == "alarm"]
    per_tier = {t: 0 for t in TIERS}
    per_tier_lenient = 0
    for r_ in alarms:
        for t in TIERS:
            if any(x["detected"][t] for x in r_["results"]):
                per_tier[t] += 1
        if any(x["detected"]["T1"] or x["t2_lenient_hits"] for x in r_["results"]):
            per_tier_lenient += 1
    dtypes = sorted({r_.get("acdtype") for r_ in ac_rows})
    A(f"\n**Autocast control** (the 8.11 negative result of `tab-negative.tex`: OpInfo ops whose sweep verdict was ok, float32 samples under "
      f"`torch.autocast('cpu', dtype={'/'.join(map(str, dtypes)) or '-'})`, eager vs `torch.compile`, both sides traced in one process): {n_ops} ops, {n_samples} samples, "
      f"{n_ok} ok, {n_err} not runnable. Alarms (ops): T1 {per_tier['T1']}, T2 {per_tier['T2']} (non-strict stride: {per_tier_lenient}), T3 {per_tier['T3']}.")
    if alarms:
        A("\n| op | sample | weakest | observables | first finding |\n|---|---|---|---|---|")
        for r_ in alarms:
            for x in r_["results"]:
                if x["weakest"]:
                    ff = next((f["detail"] for tt in TIERS for f in x["findings"][tt]), "")
                    A(f"| {r_['op']} | {x['i']} | {x['weakest']} | {';'.join(x['observables'].get(x['weakest'], []))} | {ff[:160].replace('|', '/')} |")
    A("\nThe other rows of `tab-negative.tex` (593 ops x 20 Inductor configurations, 520 export/AOTI ops, 678 vmap ops, ...) were not re-run for this "
      "analysis; their original sweeps used the paper's oracles, not these tiers, so no false-positive number is claimed for them.")
    # ---- review time ----
    rt = os.path.join(OUT_DIR, "review_times.csv")
    A("\n## Manual review time (from the ledgers)\n")
    if os.path.exists(rt):
        A("Source: `plan/TO_SUBMIT.md` and `plan/EXECUTION_REPORT.md`; only clock times the ledger records are used, nothing is estimated. "
          "The ledgers carry clock times only for 2026-09-22 (the day the round-2 drafts 33-43 were written); earlier entries carry dates or "
          "order-of-day markers ('morning', 'night') only, so their elapsed times are *not recorded*.\n")
        A("| RC | first divergence (sweep / triage) | confirmed (isolated reproducer) | draft ready / filed | elapsed (recorded) | source |")
        A("|---|---|---|---|---|---|")
        for row in csv.DictReader(open(rt, encoding="utf-8")):
            A(f"| {row['root_cause_id']} | {row['first_divergence']} | {row['confirmed']} | {row['draft_or_filed']} | {row['elapsed']} | {row['source']} |")
    else:
        A("review_times.csv not present.")
    A("\n## Files\n")
    A("* `root_causes.csv` -- root_cause_id, member_items, layer, reproducer_path, reproducible_here (+reason, status, title)")
    A("* `tiers.csv` -- root_cause_id, T1, T2, T3, weakest_tier, observable_that_fires (+ primary-only columns)")
    A("* `subcases.csv` -- one row per executed sub-case")
    A("* `traces/*.json` -- one trace per sub-case (both sides); `control_traces/*.json` -- corpus control; `control_autocast_*.jsonl` -- autocast control")
    A("* `summary.json` -- machine-readable summary; `review_times.csv` -- ledger extraction")
    with open(os.path.join(OUT_DIR, "REPORT.md"), "w", encoding="utf-8") as fh:
        fh.write("\n".join(L) + "\n")


# =============================================================================================

def main():
    if len(sys.argv) > 1 and sys.argv[1] == "--child":
        rc_id, sub_idx, side, out = sys.argv[2], int(sys.argv[3]), sys.argv[4], sys.argv[5]
        child_main(rc_id, sub_idx, side, out)
        return
    ap = argparse.ArgumentParser()
    sp = ap.add_subparsers(dest="cmd", required=True)
    a = sp.add_parser("run")
    a.add_argument("--only", default=None)
    a.add_argument("--workers", type=int, default=3)
    a.add_argument("--timeout", type=float, default=600)
    a.add_argument("--primary-only", action="store_true")
    a = sp.add_parser("control-corpus")
    a.add_argument("--workers", type=int, default=3)
    a.add_argument("--timeout", type=float, default=600)
    a = sp.add_parser("control-autocast")
    a.add_argument("--acdtype", default="bfloat16")
    a.add_argument("--samples", type=int, default=1)
    a.add_argument("--shard", default="0/1")
    a = sp.add_parser("report")
    a = sp.add_parser("eval")
    a.add_argument("trace")
    args = ap.parse_args()
    if args.cmd == "run":
        cmd_run(args)
    elif args.cmd == "control-corpus":
        cmd_control_corpus(args)
    elif args.cmd == "control-autocast":
        cmd_control_autocast(args)
    elif args.cmd == "report":
        cmd_report(args)
    elif args.cmd == "eval":
        ev = evaluate(json.load(open(args.trace, encoding="utf-8")))
        print(json.dumps(ev, indent=1))


if __name__ == "__main__":
    main()
