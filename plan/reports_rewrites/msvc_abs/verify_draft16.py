"""Compile and run the C++ block of 0920issues/16 verbatim at /Od and /O2, then run its python block."""
import os, re, subprocess, sys, tempfile
sys.path.insert(0, os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__)))))
from tcc.compat import ensure_msvc_env; ensure_msvc_env()
draft = os.path.join(os.path.dirname(os.path.abspath(__file__)), "..", "..", "..", "0920issues", "16-msvc-abs-abs-intrinsics-folded-to-identity.md")
code = re.search(r"```cpp\n(.*?)```", open(draft, encoding="utf-8").read(), re.S).group(1)
d = tempfile.mkdtemp()
open(os.path.join(d, "repro.cpp"), "w").write(code)
for flags in ("/Od", "/O1", "/O2", "/O2 /arch:AVX2"):
    r = subprocess.run(f"cl /nologo /EHsc {flags} repro.cpp", cwd=d, shell=True, capture_output=True, text=True, encoding="mbcs", errors="replace")
    assert r.returncode == 0, r.stdout + r.stderr
    print("==== cl", flags); print(subprocess.run(os.path.join(d, "repro.exe"), capture_output=True, text=True).stdout, end="")
