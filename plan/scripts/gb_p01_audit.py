"""P0-1 recomputation of the graph-break main experiment on the FROZEN 185-program corpus.

For every program (first three batches of tcc/dynamo_semantics*.py) and both calls, runs in ONE process and with ONE
oracle: eager, compiled baseline (no rewrite), compiled top-level graph-break variant.  Records per program:
  * static insertion positions (breaks inserted by the AST rewrite),
  * graph breaks Dynamo actually hit and the number of graph segments (frames) it produced, per arm,
  * per-call outcome and divergence kind (return / raise / state / none) per arm,
  * the paired classification (same / new / gone / changed).
--timing N adds N extra fresh runs per arm (torch._dynamo.reset before each) and stores per-run wall time.

    python scripts/gb_p01_audit.py [--backend eager] [--timing 3] [--out results/p01_audit]
"""
import argparse
import copy
import json
import os
import random
import statistics
import sys
import tempfile
import time

os.environ.setdefault("TORCHINDUCTOR_CACHE_DIR", tempfile.mkdtemp(prefix="tcc_p01_"))
sys.path.insert(0, os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
from tcc.compat import ensure_msvc_env  # noqa: E402

ensure_msvc_env()
import torch  # noqa: E402
import torch._dynamo  # noqa: E402
from torch._dynamo.utils import counters  # noqa: E402

from tcc import dynamo_semantics as ds  # noqa: E402
from graph_break_insertion_diff import rewrite  # noqa: E402  (scripts/ is on sys.path when run as a script)

FROZEN_MODULES = ("tcc.dynamo_semantics", "tcc.dynamo_semantics_more", "tcc.dynamo_semantics_batch3")


def frozen_programs():
    # batch 4 re-registered "chained_comparison_tensor_scalar" over the batch-3 program of the same name (which is why
    # 185 + 57 = 241, not 242).  Reload batch 3 so its original definitions win, as they did in the 2026-09-22 run.
    import importlib
    from tcc import dynamo_semantics_batch3
    importlib.reload(dynamo_semantics_batch3)
    progs = {n: f for n, f in ds.PROGRAMS.items() if f.__module__ in FROZEN_MODULES}
    per_mod = {m: sum(1 for f in progs.values() if f.__module__ == m) for m in FROZEN_MODULES}
    return progs, per_mod


def run_side(fn, compiled, backend, seed=0):
    """Two calls with accumulated STATE, exactly as ds.sweep does. Returns outcomes, states, counters, wall."""
    g = torch.Generator().manual_seed(seed)
    x0 = torch.randn(3, 4, generator=g)
    ds._reset_state()
    random.seed(123)
    if compiled:
        torch._dynamo.reset()
        counters.clear()
        fn = torch.compile(fn, backend=backend)
    outs, states = [], []
    t0 = time.perf_counter()
    for _ in range(2):
        outs.append(ds._run(fn, x0.clone()))
        states.append(ds._state_snapshot())
    wall = time.perf_counter() - t0
    cnt = None
    if compiled:
        gb = counters.get("graph_break", {})
        cnt = {"graph_breaks": int(sum(gb.values())),
               "user_inserted_breaks": int(sum(v for k, v in gb.items() if "graph_break()" in k)),
               "other_break_reasons": sorted({k.splitlines()[0][:90] for k in gb if "graph_break()" not in k}),
               "frames_total": int(counters.get("frames", {}).get("total", 0)),
               "frames_ok": int(counters.get("frames", {}).get("ok", 0)),
               "unique_graphs": int(counters.get("stats", {}).get("unique_graphs", 0)),
               "calls_captured": int(counters.get("stats", {}).get("calls_captured", 0))}
    return outs, states, cnt, wall


def kind(e_out, e_state, c_out, c_state):
    if e_out != c_out:
        er = isinstance(e_out, str) and e_out.startswith("raise")
        cr = isinstance(c_out, str) and c_out.startswith("raise")
        return "raise" if er != cr else "return"
    if e_state != c_state:
        return "state"
    return None


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--backend", default="eager")
    ap.add_argument("--timing", type=int, default=0, help="extra fresh runs per arm for wall-time statistics")
    ap.add_argument("--out", default=os.path.join("results", "p01_audit"))
    a = ap.parse_args()
    os.makedirs(a.out, exist_ok=True)
    torch._dynamo.config.recompile_limit = 10 ** 4
    progs, per_mod = frozen_programs()
    assert len(progs) == 185, (len(progs), per_mod)
    print(f"torch {torch.__version__}; frozen corpus {len(progs)} = {per_mod}; backend {a.backend}", flush=True)

    rows = []
    t_start = time.perf_counter()
    for i, (name, f) in enumerate(progs.items()):
        rw, n_static = rewrite(f, False, "graph_break")
        e_out, e_state, _, e_wall = run_side(f, False, a.backend)
        b_out, b_state, b_cnt, b_wall = run_side(f, True, a.backend)
        g_out, g_state, g_cnt, g_wall = run_side(rw, True, a.backend)
        calls = []
        for c in range(2):
            kb = kind(e_out[c], e_state[c], b_out[c], b_state[c])
            kg = kind(e_out[c], e_state[c], g_out[c], g_state[c])
            if kb is None and kg is None:
                pair = "same"
            elif kb is None:
                pair = "new"
            elif kg is None:
                pair = "gone"
            elif (b_out[c], b_state[c]) != (g_out[c], g_state[c]):
                pair = "changed"
            else:
                pair = "same-divergence"
            calls.append({"call": c, "baseline_kind": kb, "break_kind": kg, "pair": pair,
                          "eager": repr(e_out[c])[:200], "baseline": repr(b_out[c])[:200], "break": repr(g_out[c])[:200],
                          "eager_state": repr(e_state[c])[:200], "baseline_state": repr(b_state[c])[:200],
                          "break_state": repr(g_state[c])[:200]})
        row = {"program": name, "module": f.__module__.split(".")[-1], "static_breaks": n_static,
               "baseline": b_cnt, "break_variant": g_cnt, "calls": calls,
               "wall_s": {"eager": round(e_wall, 4), "baseline": round(b_wall, 4), "break": round(g_wall, 4)}}
        if a.timing:
            tb, tg = [], []
            for _ in range(a.timing):
                tb.append(run_side(f, True, a.backend)[3])
                tg.append(run_side(rw, True, a.backend)[3])
            row["timing_runs"] = {"baseline": [round(t, 4) for t in tb], "break": [round(t, 4) for t in tg]}
        rows.append(row)
        tag = "".join(c["pair"][0].upper() if c["pair"] != "same" else "." for c in calls)
        print(f"[{i + 1:3d}/185] {name:<40} static={n_static:<3} hit={g_cnt['user_inserted_breaks']:<3} "
              f"frames base={b_cnt['frames_total']} gb={g_cnt['frames_total']}  {tag}", flush=True)

    # ---- aggregate
    n_calls = sum(len(r["calls"]) for r in rows)
    base_div = [(r["program"], c["call"]) for r in rows for c in r["calls"] if c["baseline_kind"]]
    gb_div = [(r["program"], c["call"]) for r in rows for c in r["calls"] if c["break_kind"]]
    pairs = {}
    for r in rows:
        for c in r["calls"]:
            pairs.setdefault(c["pair"], []).append(f"{r['program']}#{c['call']}")
    summary = {
        "torch": torch.__version__, "backend": a.backend, "date": time.strftime("%Y-%m-%d %H:%M"),
        "programs": len(rows), "programs_per_module": per_mod, "programs_rewritten": len(rows),
        "calls_per_arm": n_calls, "arms": 3, "executions_total": 3 * n_calls,
        "static_insertion_positions": sum(r["static_breaks"] for r in rows),
        "programs_with_zero_static_positions": [r["program"] for r in rows if r["static_breaks"] == 0],
        "user_breaks_actually_hit_total": sum(r["break_variant"]["user_inserted_breaks"] for r in rows),
        "programs_where_all_static_breaks_hit": sum(1 for r in rows if r["break_variant"]["user_inserted_breaks"] >= r["static_breaks"] > 0),
        "programs_where_fewer_breaks_hit": [(r["program"], r["static_breaks"], r["break_variant"]["user_inserted_breaks"]) for r in rows if r["break_variant"]["user_inserted_breaks"] < r["static_breaks"]],
        "frames_total_baseline": sum(r["baseline"]["frames_total"] for r in rows),
        "frames_total_break": sum(r["break_variant"]["frames_total"] for r in rows),
        "baseline_divergent_calls": len(base_div), "break_divergent_calls": len(gb_div),
        "intersection_calls": len(set(base_div) & set(gb_div)),
        "pairs": {k: len(v) for k, v in pairs.items()}, "pair_members": {k: v for k, v in pairs.items() if k != "same"},
        "wall_s_total": round(time.perf_counter() - t_start, 1),
        "wall_s_per_arm_sum": {k: round(sum(r["wall_s"][k] for r in rows), 2) for k in ("eager", "baseline", "break")},
    }
    if a.timing:
        for arm in ("baseline", "break"):
            per_prog_med = [statistics.median(r["timing_runs"][arm]) for r in rows]
            totals = [sum(r["timing_runs"][arm][k] for r in rows) for k in range(a.timing)]
            summary[f"timing_{arm}"] = {"runs": a.timing, "total_per_run_s": [round(t, 2) for t in totals],
                                        "total_median_s": round(statistics.median(totals), 2),
                                        "total_min_s": round(min(totals), 2), "total_max_s": round(max(totals), 2),
                                        "per_program_median_sum_s": round(sum(per_prog_med), 2)}
    json.dump({"summary": summary, "programs": rows}, open(os.path.join(a.out, f"audit_{a.backend}.json"), "w", encoding="utf-8"), indent=1)
    with open(os.path.join(a.out, f"pairs_{a.backend}.csv"), "w", encoding="utf-8") as fh:
        fh.write("program,module,call,static_breaks,breaks_hit,frames_baseline,frames_break,baseline_kind,break_kind,pair\n")
        for r in rows:
            for c in r["calls"]:
                fh.write(f"{r['program']},{r['module']},{c['call']},{r['static_breaks']},{r['break_variant']['user_inserted_breaks']},"
                         f"{r['baseline']['frames_total']},{r['break_variant']['frames_total']},{c['baseline_kind'] or ''},{c['break_kind'] or ''},{c['pair']}\n")
    print(json.dumps(summary, indent=1, ensure_ascii=False), flush=True)
    print("DONE", flush=True)


if __name__ == "__main__":
    main()
