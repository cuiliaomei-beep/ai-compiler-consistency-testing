"""Compile the first ```cpp block of an issue draft verbatim with MSVC at the given option sets and run it.

    python scripts/run_issue_cpp_snippet.py ../0920issues/17-*.md "/Od" "/O2 /fp:strict"
"""
import glob
import os
import re
import subprocess
import sys
import tempfile

sys.path.insert(0, os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
from tcc.compat import ensure_msvc_env

ensure_msvc_env()
draft = glob.glob(sys.argv[1])[0]
code = re.search(r"```cpp\n(.*?)```", open(draft, encoding="utf-8").read(), re.S).group(1)
d = tempfile.mkdtemp()
open(os.path.join(d, "repro.cpp"), "w").write(code)
for flags in sys.argv[2:] or ["/Od", "/O2"]:
    r = subprocess.run(f"cl /nologo /EHsc {flags} repro.cpp", cwd=d, shell=True, capture_output=True, text=True, encoding="mbcs", errors="replace")
    assert r.returncode == 0, r.stdout + r.stderr
    print("==== cl", flags)
    print(subprocess.run(os.path.join(d, "repro.exe"), capture_output=True, text=True).stdout, end="")
