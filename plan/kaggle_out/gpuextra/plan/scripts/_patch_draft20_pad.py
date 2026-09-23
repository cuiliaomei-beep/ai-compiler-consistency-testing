"""One-off: add the negative-padding member (found by symshape_index_diff.py) to 0920issues/20."""
import glob
import os

ISSUES = os.path.join(os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__)))), "0920issues")
p = glob.glob(os.path.join(ISSUES, "20-*.md"))[0]
s = open(p, encoding="utf-8").read()


def rep(old, new):
    global s
    if new in s:
        return
    assert old in s, old[:60]
    s = s.replace(old, new, 1)


rep("import torch\n\ndef outcome(fn, check, *args, backend=None, deterministic=False):",
    "import torch, torch.nn.functional as F\n\ndef outcome(fn, check, *args, backend=None, deterministic=False):")
rep('    "deterministic mode: int32 empty is filled with INT_MAX": (lambda x: x.new_empty(4, dtype=torch.int32), lambda y: bool((y == 2**31 - 1).all()), lambda: (torch.ones(6),), True),\n}',
    '    "deterministic mode: int32 empty is filled with INT_MAX": (lambda x: x.new_empty(4, dtype=torch.int32), lambda y: bool((y == 2**31 - 1).all()), lambda: (torch.ones(6),), True),\n'
    '    "F.pad cropping more than the input has: pad(x[3], (-4, 4))": (lambda x: F.pad(x, (-4, 4)), lambda y: y.tolist(), lambda: (torch.arange(1.0, 4.0),), False),\n}')
rep("deterministic mode: int32 empty is filled with INT_MAX\n    None       returns True\n    aot_eager  returns True\n    inductor   returns False\n```",
    "deterministic mode: int32 empty is filled with INT_MAX\n    None       returns True\n    aot_eager  returns True\n    inductor   returns False\n"
    "F.pad cropping more than the input has: pad(x[3], (-4, 4))\n    None       raises RuntimeError: narrow(): length must be non-negative.\n    aot_eager  raises RuntimeError: narrow(): length must be non-negative.\n    inductor   returns [0.0, 0.0, 0.0]\n```")
rep("Three more members, of a slightly different kind:", "Four more members. The first three are of a slightly different kind:")
rep("All three behave like eager under `backend=\"aot_eager\"` and differ only under Inductor", "All four behave like eager under `backend=\"aot_eager\"` and differ only under Inductor")
rep("\nPossible fixes: (1)",
    "4. **`F.pad` with a negative pad larger than the dimension.** `F.pad(x, (-4, 4))` on a length-3 tensor asks to crop four elements from a side that has three; eager raises from `narrow()`, the Inductor `constant_pad_nd` lowering returns a tensor made only of the fill value (`[0., 0., 0.]`, or `[9., 9., 9.]` with `value=9`). Same for 2-D inputs and for either side. (An ordinary argument validation, like the ones in my previous comment; found later with a sweep over symbolic slice / pad / roll amounts.)\n"
    "\nPossible fixes: (1)")
rep("as is already done for some scatter lowerings; (3)", "as is already done for some scatter lowerings; (3)")
rep("(and guard on the flag).", "(and guard on the flag); (4) check `-pad <= size` per side in the `constant_pad_nd` lowering (the meta function can raise the same error).")
rep("| 证据包 | `plan/reports_surgery/safety_mechanisms_lost.py`（10 行对照）",
    "| 第 4 项来源 | `plan/scripts/symshape_index_diff.py`（10.5b，用例 `pad_both`）；隔离 `plan/reports_symshape/negative_pad_beyond_input.py`（9 种写法 × eager/aot_eager/inductor 静态与动态）；2.14 + nightly；查重（`constant_pad_nd negative padding inductor` 等 3 组）无同报告，邻近但不同：#195582（open，BatchNorm 后接收缩 pad 的错值）、#194558（closed，就地 pad 优化崩溃） |\n"
    "| 证据包 | `plan/reports_surgery/safety_mechanisms_lost.py`（10 行对照）")
open(p, "w", encoding="utf-8").write(s)
print("patched")
