"""Shared helpers for the round-4/5 sweeps (error parity, integer UB, layout/alias).

Every sweep follows the same shape:
  * a --only NAME[,NAME] argument selects work items,
  * results are appended to a jsonl file (one line per case) so runs can resume,
  * --isolate runs each work item in a fresh interpreter (crashes and state leakage
    become visible instead of poisoning later items).
"""
import json
import os
import subprocess
import sys
import time

try:
    import torch
except ImportError:  # cross-target sweeps (numba, jax) run in an interpreter without torch
    torch = None


def jsonl_append(path, rec):
    with open(path, "a", encoding="utf-8") as f:
        f.write(json.dumps(rec, default=str) + "\n")


def jsonl_done(path, key="op"):
    done = set()
    if os.path.exists(path):
        with open(path, encoding="utf-8") as f:
            for line in f:
                try:
                    done.add(json.loads(line)[key])
                except Exception:
                    pass
    return done


def run_isolated(script, items, extra_args, out_jsonl, timeout=900, key="op", label=""):
    """Spawn `python script --only ITEM extra_args...` once per item; record crashes/timeouts."""
    done = jsonl_done(out_jsonl, key)
    todo = [i for i in items if i not in done]
    print(f"[isolate{label}] {len(todo)} items to run ({len(done)} already done)", flush=True)
    env = dict(os.environ, PYTHONUTF8="1", TCC_ISOLATED_CHILD="1")
    t_all = time.time()
    for n, item in enumerate(todo, 1):
        t0 = time.time()
        cmd = [sys.executable, script, "--only", item, "--out-jsonl", out_jsonl] + list(extra_args)
        try:
            p = subprocess.run(cmd, capture_output=True, text=True, timeout=timeout, env=env, encoding="utf-8", errors="replace")
            rc = p.returncode
            tail = (p.stderr or p.stdout or "")[-1500:]
        except subprocess.TimeoutExpired:
            rc, tail = "timeout", ""
        if rc != 0:
            jsonl_append(out_jsonl, {key: item, "verdict": "CRASH", "returncode": rc, "tail": tail})
            print(f"  [{n}/{len(todo)}] {item}: CRASH rc={rc} ({time.time() - t0:.0f}s)", flush=True)
        elif n % 10 == 0 or time.time() - t0 > 60:
            print(f"  [{n}/{len(todo)}] {item} ({time.time() - t0:.0f}s, total {time.time() - t_all:.0f}s)", flush=True)
    print(f"[isolate{label}] finished in {time.time() - t_all:.0f}s", flush=True)


def tensors_of(o):
    if isinstance(o, torch.Tensor):
        return [o]
    if isinstance(o, (tuple, list)):
        return [t for x in o for t in tensors_of(x)]
    if isinstance(o, dict):
        return [t for x in o.values() for t in tensors_of(x)]
    return []


def to_double(t):
    if t.is_complex():
        return t.to(torch.complex128)
    if t.is_floating_point():
        return t.to(torch.float64)
    return t


def compare(eager, comp, ref=None, rtol=1e-4, atol=1e-5, ref_factor=10.0):
    """Compare compiled outputs with eager outputs.

    Returns (verdict, detail).  verdict in {"ok", "shape", "dtype", "nonfinite", "value"}.
    If a float64 reference `ref` is given, a value mismatch is only reported when the
    compiled result is `ref_factor` times farther from the reference than eager is
    (the standard 'compiled is much worse than eager' oracle that avoids fp noise).
    Integer/bool outputs must match exactly.
    """
    if len(eager) != len(comp):
        return "shape", f"num outputs {len(eager)} vs {len(comp)}"
    for i, (e, c) in enumerate(zip(eager, comp)):
        if e.shape != c.shape:
            return "shape", f"out{i} {tuple(e.shape)} vs {tuple(c.shape)}"
        if e.dtype != c.dtype:
            return "dtype", f"out{i} {e.dtype} vs {c.dtype}"
        if e.numel() == 0:
            continue
        if not (e.is_floating_point() or e.is_complex()):
            if not torch.equal(e, c):
                bad = (e != c)
                return "value", f"out{i} {int(bad.sum())}/{e.numel()} elements differ; eager {e.flatten()[bad.flatten()][:4].tolist()} comp {c.flatten()[bad.flatten()][:4].tolist()}"
            continue
        fe, fc = torch.isfinite(e), torch.isfinite(c)
        if not torch.equal(fe, fc) or not torch.equal(torch.isnan(e), torch.isnan(c)):
            return "nonfinite", f"out{i} finite/nan pattern differs (eager nonfinite {int((~fe).sum())}, comp {int((~fc).sum())})"
        m = fe
        if not m.any():
            continue
        ed, cd = to_double(e)[m], to_double(c)[m]
        diff = (ed - cd).abs().max().item()
        scale = max(ed.abs().max().item(), 1e-30)
        if diff <= atol + rtol * scale:
            continue
        if ref is not None and i < len(ref) and ref[i].shape == e.shape:
            rd = to_double(ref[i])[m]
            err_e = (ed - rd).abs().max().item()
            err_c = (cd - rd).abs().max().item()
            if err_c <= ref_factor * max(err_e, atol):
                continue
            return "value", f"out{i} |comp-ref|={err_c:.3g} vs |eager-ref|={err_e:.3g} (scale {scale:.3g})"
        return "value", f"out{i} maxdiff {diff:.3g} (scale {scale:.3g})"
    return "ok", ""


def exc_info(e):
    return f"{type(e).__module__}.{type(e).__name__}: {str(e)[:400]}"
