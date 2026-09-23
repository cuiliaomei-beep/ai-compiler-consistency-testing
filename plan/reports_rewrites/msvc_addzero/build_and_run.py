import os, subprocess, sys
sys.path.insert(0, os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__)))))
from tcc.compat import ensure_msvc_env; ensure_msvc_env()
here = os.path.dirname(os.path.abspath(__file__))
kw = dict(capture_output=True, text=True, encoding="mbcs", errors="replace", cwd=here, shell=True)
for flags in ("/Od", "/O2", "/O2 /fp:strict", "/O2 /arch:AVX2"):
    r = subprocess.run(f"cl /nologo /EHsc {flags} add_zero.cpp /Feadd_zero.exe", **kw)
    assert r.returncode == 0, r.stdout + r.stderr
    print("==== cl", flags); print(subprocess.run(os.path.join(here, "add_zero.exe"), capture_output=True, text=True).stdout)
r = subprocess.run("cl /nologo /c /EHsc /O2 /FAs /Faadd_zero.asm add_zero.cpp", **kw)
s = open(os.path.join(here, "add_zero.asm"), encoding="mbcs", errors="replace").read()
import re
for fn in ("scalar_f", "avx_ps"):
    m = re.search(r"(\?%s@@[^\n]* PROC.*?ENDP)" % fn, s, re.S)
    print("----", fn); print("\n".join(l for l in m.group(1).splitlines() if l.startswith("\t") and not l.strip().startswith(";")))
