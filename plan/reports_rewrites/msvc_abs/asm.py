import os, subprocess, sys, re
sys.path.insert(0, os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__)))))
from tcc.compat import ensure_msvc_env; ensure_msvc_env()
here = os.path.dirname(os.path.abspath(__file__))
subprocess.run('cl /nologo /c /EHsc /O2 /arch:AVX2 /FAs /Faabs_abs_O2.asm /Foabs_abs_O2.obj abs_abs.cpp', cwd=here, shell=True, capture_output=True)
s = open(os.path.join(here, "abs_abs_O2.asm"), encoding="mbcs", errors="replace").read()
for fn in ("abs1_256", "abs2_256", "abs3_256"):
    m = re.search(r"(\?%s@@[^\n]* PROC.*?ENDP)" % fn, s, re.S)
    body = [l for l in m.group(1).splitlines() if l.startswith("\t") and not l.strip().startswith(";")]
    print("----", fn); print("\n".join(body))
