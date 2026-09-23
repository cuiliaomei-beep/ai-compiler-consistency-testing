"""One-off bookkeeping (2026-09-22 midday): v3 vocabulary, gcc result, host_opt_diff / model_surgery_diff tools launched."""
import os

PLAN = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
ISSUES = os.path.join(os.path.dirname(PLAN), "0920issues")


def edit(path, old, new):
    t = open(path, encoding="utf-8").read()
    if new in t:
        return
    assert old in t, (path, old[:50])
    open(path, "w", encoding="utf-8").write(t.replace(old, new, 1))


edit(os.path.join(ISSUES, "README.md"),
     "| `scripts/cxx_algebra_families.py` |",
     "| `scripts/host_opt_diff.py` | 同一批程序让 Inductor 编两次，只差宿主编译器优化档（`TORCHINDUCTOR_DEBUG_COMPILE=1` → `/Od`），逐位比较；每个编译函数只放 4 个程序（大函数里 MSVC 不做 abs(abs) 折叠，批量大了会漏报——已验证小批量能重新发现 16 号） |\n"
     "| `scripts/model_surgery_diff.py` | 10.3/10.4：76 个\"编译后动模型\"用例（冻结/解冻、改 dtype、换子模块、load_state_dict、共享权重、parametrize、BN/Dropout/LayerNorm 超参数、编译的 optimizer.step 步间改 lr/betas/wd、GradScaler、全局开关）＋ eager 保护机制（anomaly、deterministic、inference tensor、整数除零各形态） |\n"
     "| `scripts/cxx_algebra_families.py` |")
edit(os.path.join(PLAN, "TO_SUBMIT.md"),
     "**台账 43 更正（2026-09-21 深夜）**",
     "10.13 补充（2026-09-22 中午）：词表 v3（FMA 族 + AVX-512 掩码选择/掩码算术，共 124,334 个组合）→ 草稿 18 扩大为\"带等号谓词的 select 折叠\"：`LE_OS`、`GE_OS`、`NLE_US`，128/256 位 `blendv` 与 512 位 `mask_blend`；`NLE_US` 在 SSE 编码的普通 `/O2` 下就错。FMA 与整数掩码算子无差异。**g++ 11.4（Kaggle，98,488 个组合，-O0 对 -O1/2/3）：0 个真实差异**——48 个\"值差异\"全部是 `x * -1.0` 被化成取负后 NaN 符号位不同、再经按位运算显形，属 IEEE 允许（负结果）。clang++ 14 第一次因 `_mm_permute_pd` 立即数越界编译失败，已修并重推。\n\n"
     "10.3 模型手术中期结果：Adam/AdamW 的编译 `step` 与 eager 每步差 ~1e-6（不改超参数也有；偏差修正项在编译路径里用 float32 张量算）→ 精度级，不报；lr/betas/eps/wd 的步间修改都被正确感知。\n\n"
     "**台账 43 更正（2026-09-21 深夜）**")
edit(os.path.join(PLAN, "EXECUTION_REPORT.md"),
     "**当前断点（2026-09-22 上午）**：",
     "**当前断点（2026-09-22 中午）**：后台在跑三件事——① `scripts/host_opt_diff.py` 3 个分片（`results/host_opt/cases_s*.jsonl`，`--report` 看结果）；② `scripts/model_surgery_diff.py --isolate`（`results/surgery/cases.jsonl`，`--report`）；③ Kaggle `tcc-cxxalgebra`（g++ 已出结果：干净；clang++ 重跑中，日志 `kaggle_out/cxxalgebra.log`）。草稿 18 已按词表 v3 的结果扩大（LE/GE/NLE + AVX-512 mask_blend）；草稿 15 补了图内常量张量形式与 46 程序别名普查。接下来：分诊 ①②③ → 10.4 若有 SILENT 并入 #197554 评论稿（04）；再做 10.5 标量算术 / 10.6 全 lowering 表。\n\n"
     "**历史断点（2026-09-22 上午）**：")
mem = r"C:\Users\clm\.claude\projects\d--wsl-personal-dr-paper\memory\tcc-plan-status.md"
t = open(mem, encoding="utf-8").read()
line = ("- 2026-09-22 midday: cxx tool vocabulary v3 (124,334 compositions): draft 18 widened to selects with equality-including predicates (LE_OS/GE_OS/NLE_US; blendv + AVX-512 mask_blend; NLE wrong even at plain /O2). "
        "g++ 11.4 on Kaggle: clean (48 'value' diffs are NaN-sign from x*-1 -> neg, permitted). New tools running: scripts/host_opt_diff.py (Inductor kernels at /Od vs /O2, groups of 4 programs per compile -- larger groups hide the MSVC fold) "
        "and scripts/model_surgery_diff.py (76 post-compile surgery / hyper-parameter / safety-mechanism cases; interim 37/38 ok, Adam drift ~1e-6 is precision-level). Draft 15 gained in-graph constant forms + 46-program alias census.\n")
if line not in t:
    open(mem, "w", encoding="utf-8").write(t + line)
print("recorded")
