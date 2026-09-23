import os, re, subprocess, sys
sys.path.insert(0, os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__)))))
from tcc.compat import ensure_msvc_env; ensure_msvc_env()
here = os.path.dirname(os.path.abspath(__file__))
kw = dict(capture_output=True, text=True, encoding="mbcs", errors="replace", cwd=here, shell=True)
for k, flags in enumerate(("/Od", "/Od /arch:AVX2", "/O2", "/O1 /arch:AVX2", "/O2 /arch:AVX2", "/O2 /arch:AVX2 /fp:strict", "/O2 /arch:AVX512")):
    exe = f"blend_{k}.exe"
    r = subprocess.run(f"cl /nologo /EHsc {flags} blend.cpp /Fe{exe}", **kw)
    assert r.returncode == 0, r.stdout + r.stderr
    print("==== cl", flags); print(subprocess.run(os.path.join(here, exe), capture_output=True, text=True).stdout)
for flags in ("/O2", "/O2 /arch:AVX2"):
    subprocess.run(f"cl /nologo /c /EHsc {flags} /FAs /Fablend.asm blend.cpp", **kw)
    s = open(os.path.join(here, "blend.asm"), encoding="mbcs", errors="replace").read()
    for fn in ("sel_only", "sel_then_sqrt"):
        m = re.search(r"(\?%s@@[^\n]* PROC.*?ENDP)" % fn, s, re.S)
        print("----", flags, fn); print("\n".join(l for l in m.group(1).splitlines() if l.startswith("\t") and not l.strip().startswith(";")))
