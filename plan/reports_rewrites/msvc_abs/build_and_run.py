import os, subprocess, sys
sys.path.insert(0, os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__)))))
from tcc.compat import ensure_msvc_env; ensure_msvc_env()
here = os.path.dirname(os.path.abspath(__file__))
print(subprocess.run("cl", capture_output=True, text=True, encoding="mbcs", errors="replace").stderr.splitlines()[0])
for flags in ("/Od", "/O2", "/O2 /arch:AVX2", "/O2 /arch:AVX512"):
    exe = os.path.join(here, "abs_abs_" + flags.replace("/", "").replace(" ", "_").replace(":", "") + ".exe")
    r = subprocess.run(f'cl /nologo /EHsc {flags} "{os.path.join(here, "abs_abs.cpp")}" /Fe"{exe}" /Fo"{exe}.obj"', capture_output=True, text=True, encoding="mbcs", errors="replace", cwd=here, shell=True)
    if r.returncode:
        print(flags, "COMPILE FAILED", r.stdout[-400:], r.stderr[-400:]); continue
    print("==== cl", flags)
    print(subprocess.run(exe, capture_output=True, text=True, encoding="mbcs", errors="replace").stdout)
