"""Render results/p01_audit/audit_<backend>.json as the P0-1 Markdown report (P0-1.md) with the counts the FSE
checklist asks for, in the checklist's units: programs / calls / divergence instances / independent root causes.
Root-cause assignment of the non-'same' pairs is given explicitly below (reviewed by hand against the ledger).

    python scripts/gb_p01_summary.py [--backend eager]
"""
import argparse
import json
import os

# program -> (root cause id, verdict, explanation).  Verdicts: defect | known-defect | expected | noise
ROOT_CAUSE = {
    "collections_types": ("C41", "defect", "OrderedDict.move_to_end on a dict that becomes an input of the resume function is not replayed (#198189)"),
    "gen_send": ("C42", "defect", "generator alive across the break is reconstructed as tuple_iterator; .send raises AttributeError (#198190)"),
    "gen_throw": ("C42", "defect", "same reconstruction; .throw raises AttributeError (#198190)"),
    "gen_return_value_stopiteration": ("C42", "defect", "same reconstruction; StopIteration.value becomes None (#198190)"),
    "python_random": ("known-B17", "known-defect", "baseline diverges on both calls (values differ from eager) = the known item B17, random.seed inside a compiled function ignored (fixed upstream); with a break after every statement seed and draws are no longer in one traced frame and the compiled values equal eager, so the divergence disappears"),
    "tensor_subclass_torch_function": ("known-state", "known-defect", "baseline already diverges in the __torch_function__ call log; the break changes which calls are logged, not whether it diverges"),
    "numpy_scalar_types": ("known-numpy", "known-defect", "aot_eager arm only: baseline already diverges (numpy scalar promotion, known family C13/C20); under the break the compiled dtype changes from float32 to float64, still a divergence"),
    "deepcopy_module_state": ("known-deepcopy", "known-defect", "aot_eager arm only: copy.deepcopy(module) inside the compiled function; the 09-22 run had call0 as 'new', this run has it diverging in both arms (baseline 21 instead of 20), so it is a baseline item, not a break finding"),
    "threading_local_state": ("known-state", "known-defect", "baseline already diverges on the threading.local object stored in STATE; the break changes the repr of the object, not the divergence"),
}


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--backend", default="eager")
    ap.add_argument("--out", default=os.path.join("results", "p01_audit"))
    a = ap.parse_args()
    d = json.load(open(os.path.join(a.out, f"audit_{a.backend}.json"), encoding="utf-8"))
    s, rows = d["summary"], d["programs"]
    by = {r["program"]: r for r in rows}
    non_same = {}
    for r in rows:
        for c in r["calls"]:
            if c["pair"] not in ("same", "same-divergence"):
                non_same.setdefault(r["program"], []).append(c)
    L = []
    L.append(f"# P0-1 主实验复算：冻结 185 程序 × 逐语句插入 graph break（backend={s['backend']}，torch {s['torch']}，{s['date']}）\n")
    L.append("同一进程、同一 oracle（返回值精确比较 + STATE 快照 + 异常类型），三臂：eager、编译原程序、编译断点变体。每个程序两次调用。\n")
    L.append("## 计数（分子 / 分母按清单要求分列）\n")
    L.append("| 量 | 值 |\n|---|---|")
    L.append(f"| 冻结程序数 | {s['programs']}（{', '.join(f'{k.split('.')[-1]} {v}' for k, v in s['programs_per_module'].items())}） |")
    L.append(f"| 可运行 / 可改写程序数 | {s['programs_rewritten']} / {s['programs']}（AST 改写失败 0） |")
    L.append(f"| 每臂执行调用数 | {s['calls_per_arm']}（{s['programs']} 程序 × 2 次调用）；三臂合计 {s['executions_total']} |")
    L.append(f"| 静态插入位置数（顶层语句后） | {s['static_insertion_positions']}；插入 0 处的程序 {len(s['programs_with_zero_static_positions'])} 个 |")
    L.append(f"| 实际触发的用户断点数（Dynamo 计数器 `graph_break`：追踪时遇到的用户断点，两次调用合计；帧被重复追踪时可多于静态数，语句未执行到或提前抛出时少于静态数） | {s['user_breaks_actually_hit_total']} |")
    L.append(f"| 所有静态断点都被触发的程序数 | {s['programs_where_all_static_breaks_hit']}；触发数少于插入数的程序 {len(s['programs_where_fewer_breaks_hit'])} 个 |")
    L.append(f"| 图段数（Dynamo `frames.total`，两次调用合计） | 原程序臂 {s['frames_total_baseline']}，断点臂 {s['frames_total_break']} |")
    L.append(f"| 分歧实例（程序×调用） | 原程序臂 {s['baseline_divergent_calls']}，断点臂 {s['break_divergent_calls']}，交集 {s['intersection_calls']} |")
    p = s["pairs"]
    L.append(f"| 成对分类 | 同（无分歧）{p.get('same', 0)}；同一分歧 {p.get('same-divergence', 0)}；新增 {p.get('new', 0)}；消失 {p.get('gone', 0)}；改变 {p.get('changed', 0)} |")
    L.append(f"| 本次运行墙钟 | {s['wall_s_total']} s（eager 臂 {s['wall_s_per_arm_sum']['eager']} s、原程序臂 {s['wall_s_per_arm_sum']['baseline']} s、断点臂 {s['wall_s_per_arm_sum']['break']} s，含编译） |")
    L.append("")
    L.append("## 非“同”配对逐项（程序 × 调用）\n")
    L.append("| 程序 | 调用 | 配对 | 原程序臂 | 断点臂 | 静态插入 | 实际触发 | 图段 原/断 | 根因 | 判定 |\n|---|---|---|---|---|---|---|---|---|---|")
    for prog, calls in non_same.items():
        r = by[prog]
        rc = ROOT_CAUSE.get(prog, ("?", "?", "not classified"))
        for c in calls:
            L.append(f"| `{prog}` | {c['call']} | {c['pair']} | {c['baseline_kind'] or '—'} | {c['break_kind'] or '—'} | {r['static_breaks']} | "
                     f"{r['break_variant']['user_inserted_breaks']} | {r['baseline']['frames_total']} / {r['break_variant']['frames_total']} | {rc[0]} | {rc[1]} |")
    L.append("")
    L.append("## 独立根因（新增分歧去重后）\n")
    new_progs = [pg for pg, cs in non_same.items() if any(c["pair"] == "new" for c in cs)]
    rcs = {}
    for pg in new_progs:
        rcs.setdefault(ROOT_CAUSE[pg][0], []).append(pg)
    L.append(f"新增分歧实例 {p.get('new', 0)} 处，来自 {len(new_progs)} 个程序，去重后 **{len(rcs)} 个独立根因**：\n")
    for k, v in rcs.items():
        L.append(f"- **{k}**：{', '.join('`' + x + '`' for x in v)} —— {ROOT_CAUSE[v[0]][2]}")
    L.append("")
    L.append("消失 / 改变的配对不是新发现：")
    for pg, cs in non_same.items():
        if all(c["pair"] in ("gone", "changed") for c in cs):
            L.append(f"- `{pg}`（{cs[0]['pair']}）：{ROOT_CAUSE[pg][2]}")
    L.append("")
    L.append("预期行为 / 无效项：本语料的 185 程序在断点臂没有被判为预期行为的新增项（`functools.lru_cache` 的内联属于第 4 批程序，不在冻结语料内）。\n")
    L.append("## 代表程序的断点与图段（Dynamo 计数器）\n")
    L.append("| 程序 | 静态插入 | 实际触发 | 图段 原程序臂 | 图段 断点臂 | 其他断点原因（断点臂） |\n|---|---|---|---|---|---|")
    for pg in list(non_same):
        r = by[pg]
        L.append(f"| `{pg}` | {r['static_breaks']} | {r['break_variant']['user_inserted_breaks']} | {r['baseline']['frames_total']} | {r['break_variant']['frames_total']} | {'; '.join(r['break_variant']['other_break_reasons'])[:160] or '—'} |")
    L.append("")
    if s.get("programs_where_fewer_breaks_hit"):
        L.append("触发数少于静态插入数的程序（断点位于未执行到的语句之后，或程序在到达前已抛出）：\n")
        for pg, st, hit in s["programs_where_fewer_breaks_hit"]:
            L.append(f"- `{pg}`：插入 {st}，触发 {hit}")
        L.append("")
    if "timing_baseline" in s:
        L.append("## 成对计时（P1-3；每臂额外 %d 次全新运行，每次 `torch._dynamo.reset()` 后编译 + 两次调用）\n" % s["timing_baseline"]["runs"])
        L.append("| 臂 | 各次总墙钟 (s) | 中位数 | 最小 | 最大 | 逐程序中位数之和 |\n|---|---|---|---|---|---|")
        for arm, lab in (("baseline", "原程序"), ("break", "断点变体")):
            t = s[f"timing_{arm}"]
            L.append(f"| {lab} | {', '.join(str(x) for x in t['total_per_run_s'])} | {t['total_median_s']} | {t['total_min_s']} | {t['total_max_s']} | {t['per_program_median_sum_s']} |")
        L.append("")
    L.append("## 最小复现是否仍需 graph break\n")
    L.append("见 `results/p01_audit/minimal/`：40 号稿（C41）的代码块不含 `graph_break`，运行输出 eager 与 compiled 的 OrderedDict 顺序不同；"
             "41 号稿（C42）的代码块两段：第一段“生成器从编译函数返回”不含 graph break 即复现 `tuple_iterator` 与 `StopIteration.value=None`，"
             "第二段“挂起的生成器上 `.send`”以一个显式 `graph_break()` 作为挂起点。因此 C41 与 C42 的返回路径不需要断点；C42 的帧内 send/throw 形态以断点为触发条件。\n")
    open(os.path.join(a.out, f"P0-1_{a.backend}.md"), "w", encoding="utf-8").write("\n".join(L))
    print("\n".join(L[:14]))
    print(f"... written {os.path.join(a.out, f'P0-1_{a.backend}.md')}")


if __name__ == "__main__":
    main()
