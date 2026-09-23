"""export / AOTInductor differential (NEXT_DIRECTIONS 5.8).

``torch.export`` + ``aoti_compile_and_package`` is a second compilation pipeline: it
shares the decompositions with ``torch.compile`` but uses pre-dispatch export,
the C++ wrapper and a separate runtime. For every OpInfo sample the sweep runs

    E0  eager
    EX  torch.export(...).module()          (export path, no Inductor)
    AO  aoti_compile_and_package + load     (export + Inductor C++ wrapper + AOTI runtime)
    E3  torch.compile(backend="inductor")   (for attribution only)

and compares EX and AO with eager under the usual fp64-referenced oracle. A
divergence in AO but not in E3 is attributable to the export/AOTI pipeline; one
shared by both is an Inductor defect seen through two front ends.
"""
from __future__ import annotations

import json
import os
import tempfile
import time
from dataclasses import dataclass, field
from typing import Any, Callable, Dict, List, Optional, Sequence, Tuple

from .compat import compile_fn, dynamo_reset, seed_everything, torch
from .decomp_diff import _clones, _describe, _eligible, _fp64, _run
from .observe import Observation, is_tensor
from .oracle import Config, compare


class _Wrap(torch.nn.Module if torch is not None else object):
    def __init__(self, fn: Callable, kwargs: Dict[str, Any]):
        super().__init__()
        self._fn = fn
        self._kw = kwargs

    def forward(self, *args):
        return self._fn(*args, **self._kw)


@dataclass
class Finding:
    op: str
    path: str            # export | aoti
    detail: str
    also_inductor: Optional[bool]     # does torch.compile(inductor) show the same divergence?
    shapes: List[Any] = field(default_factory=list)
    dtypes: List[str] = field(default_factory=list)
    kwargs: str = ""

    def as_dict(self) -> Dict[str, Any]:
        return dict(vars(self))


def _export_run(mod, args: Tuple[Any, ...], mode: str) -> Tuple[Observation, Optional[Any]]:
    """Return (observation of the exported module, ExportedProgram or None)."""
    from torch.export import export
    try:
        ep = export(mod, tuple(_clones(args, {})[0]))
    except Exception as e:  # noqa: BLE001
        o = _run(lambda *a: (_ for _ in ()).throw(e), args, mode)
        o.infra_error = True
        return o, None
    return _run(ep.module(), _clones(args, {})[0], mode), ep


def _aoti_run(ep, args: Tuple[Any, ...], mode: str, work: str) -> Observation:
    from torch._inductor import aoti_compile_and_package, aoti_load_package
    try:
        path = aoti_compile_and_package(ep, package_path=os.path.join(work, "m.pt2"))
        runner = aoti_load_package(path)
    except Exception as e:  # noqa: BLE001
        o = _run(lambda *a: (_ for _ in ()).throw(e), args, mode)
        o.infra_error = True
        return o
    return _run(runner, _clones(args, {})[0], mode)


def sweep(limit: int = 0, samples_per_op: int = 1, seed: int = 0, dtype: str = "float32",
          paths: Sequence[str] = ("export", "aoti"), log=print, only: Optional[str] = None,
          jsonl: Optional[str] = None, device: str = "cpu") -> Dict[str, Any]:
    from torch.testing._internal.common_methods_invocations import op_db
    import random as _r
    cfg = Config()
    rng = _r.Random(seed)
    dt = getattr(torch, dtype)
    t0 = time.perf_counter()
    stats = {"ops": 0, "samples": 0, "export_ok": 0, "export_fail": 0, "aoti_ok": 0, "aoti_fail": 0,
             "findings": 0, "export_only": 0, "aoti_only": 0, "shared_with_inductor": 0}
    out: List[Finding] = []
    wanted = {s.strip() for s in only.split(",")} if only else None
    sink = open(jsonl, "a", encoding="utf-8") if jsonl else None
    work = tempfile.mkdtemp(prefix="tcc_aoti_")

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
                   and all(not is_tensor(a) or a.layout == torch.strided for a in s.args)]
        if not samples:
            emit({"done": name})
            continue
        stats["ops"] += 1
        for s in rng.sample(samples, min(samples_per_op, len(samples))):
            stats["samples"] += 1
            kwargs = dict(s.kwargs)
            args = (s.input,) + tuple(s.args)
            mod = _Wrap(op.op, kwargs)
            shapes, dtypes = _describe(args)
            seed_everything(seed)
            real = _run(mod, _clones(args, {})[0], "eager")
            if real.infra_error or not real.ok:
                continue   # export needs a working eager call
            ref64 = _fp64(mod, args)
            inductor_obs: Optional[Observation] = None

            def _inductor():
                nonlocal inductor_obs
                if inductor_obs is None:
                    dynamo_reset()
                    try:
                        inductor_obs = _run(compile_fn(mod, "inductor"), _clones(args, {})[0], "inductor")
                    except Exception as e:  # noqa: BLE001
                        inductor_obs = _run(lambda *a: (_ for _ in ()).throw(e), args, "inductor")
                    finally:
                        dynamo_reset()
                return inductor_obs

            def _record(path: str, c) -> None:
                f0 = c.findings[0]
                detail = f"[{f0.kind}] {f0.detail}"
                ind = _inductor()
                also = None if ind.infra_error else compare(real, ind, ref64, cfg, ["value", "metadata", "exception"]).differs
                fd = Finding(name, path, detail[:240], also, shapes, dtypes, repr(kwargs)[:120])
                out.append(fd)
                emit(fd.as_dict())
                stats["findings"] += 1
                stats["shared_with_inductor" if also else f"{path}_only"] += 1
                log(f"  {path:<6} {name:<34} {fd.detail[:80]}  inductor_too={also}")

            ep = None
            if "export" in paths:
                ex, ep = _export_run(mod, args, "export")
                if ex.infra_error:
                    stats["export_fail"] += 1
                else:
                    stats["export_ok"] += 1
                    c = compare(real, ex, ref64, cfg, ["value", "metadata", "exception"])
                    if c.differs:
                        _record("export", c)
            if "aoti" in paths and ep is not None:
                ao = _aoti_run(ep, args, "aoti", work)
                if ao.infra_error:
                    stats["aoti_fail"] += 1
                    emit({"aoti_fail": name, "why": (ao.exception_msg or "")[:200]})
                else:
                    stats["aoti_ok"] += 1
                    c = compare(real, ao, ref64, cfg, ["value", "metadata", "exception"])
                    if c.differs:
                        _record("aoti", c)
        emit({"done": name})
    stats["wall_s"] = round(time.perf_counter() - t0, 1)
    emit({"stats": stats})
    if sink is not None:
        sink.close()
    return {"stats": stats, "mismatches": [f.as_dict() for f in out]}


def write_report(res: Dict[str, Any], out_dir: str) -> str:
    os.makedirs(out_dir, exist_ok=True)
    with open(os.path.join(out_dir, "aoti.json"), "w", encoding="utf-8") as fh:
        json.dump(res, fh, indent=2, default=str)
    st = res["stats"]
    L = ["# export / AOTInductor differential", "",
         f"- operators: {st.get('ops', 0)}, samples: {st.get('samples', 0)}; export ok/fail: {st.get('export_ok', 0)}/"
         f"{st.get('export_fail', 0)}; AOTI ok/fail: {st.get('aoti_ok', 0)}/{st.get('aoti_fail', 0)}",
         f"- findings: {st.get('findings', 0)} — export-only {st.get('export_only', 0)}, aoti-only {st.get('aoti_only', 0)}, "
         f"shared with torch.compile(inductor) {st.get('shared_with_inductor', 0)}", f"- wall: {st.get('wall_s', 0)} s", ""]
    if res.get("crashes"):
        L.append("- operators whose child interpreter died: "
                 + ", ".join(f"{c['crash']} (rc {c['rc']})" for c in res["crashes"]))
        L.append("")
    L += ["| path | op | kwargs | shapes | dtypes | detail | inductor too |", "|---|---|---|---|---|---|---|"]
    for m in res["mismatches"]:
        if "op" not in m:      # the JSONL also carries {"aoti_fail": ...} records
            continue
        L.append(f"| {m.get('path')} | {m['op']} | {m.get('kwargs', '')[:40].replace('|', '/')} | {m['shapes']} | {m['dtypes']} | "
                 f"{m['detail'][:100].replace('|', '/')} | {m.get('also_inductor')} |")
    path = os.path.join(out_dir, "AOTI.md")
    with open(path, "w", encoding="utf-8") as fh:
        fh.write("\n".join(L) + "\n")
    return path
