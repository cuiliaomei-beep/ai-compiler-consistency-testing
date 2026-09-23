"""Run the first ```python block of an issue draft exactly as written (after importing the MSVC environment).

    python scripts/run_issue_snippet.py <draft.md> [block index, default 0]
Used to check that the output quoted in a draft is what the snippet really prints.
"""
import os
import re
import subprocess
import sys
import tempfile

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
md = open(sys.argv[1], encoding="utf-8").read()
blocks = re.findall(r"```python\n(.*?)```", md, re.S)
code = blocks[int(sys.argv[2]) if len(sys.argv) > 2 else 0]
pre = f"import sys; sys.path.insert(0, {ROOT!r})\ntry:\n    from tcc.compat import ensure_msvc_env; ensure_msvc_env()\nexcept Exception:\n    pass\n"
path = os.path.join(tempfile.gettempdir(), "issue_snippet.py")
open(path, "w", encoding="utf-8").write(pre + code)
p = subprocess.run([os.environ.get("TCC_PY", sys.executable), path], capture_output=True, text=True, encoding="utf-8", errors="replace")
print(p.stdout[-3000:])
if p.returncode:
    print("EXIT", hex(p.returncode & 0xFFFFFFFF), p.stderr[-800:])
