"""Kaggle GPU job: 32-bit indexing boundary (reports_symshape/int32_indexing_boundary.py) on torch 2.14.0 and nightly."""
import base64
import os
import py_compile

HERE = os.path.dirname(os.path.abspath(__file__))
src_path = os.path.join(os.path.dirname(HERE), "reports_symshape", "int32_indexing_boundary.py")
py_compile.compile(src_path, doraise=True)
b = base64.b64encode(open(src_path, "rb").read()).decode()
install = '[["--upgrade", "torch==2.14.0"], ["--pre", "--upgrade", "torch", "--index-url", "https://download.pytorch.org/whl/nightly/cu130"]]'
path = os.path.join(HERE, "jobs", "int32gpu.py")
with open(path, "w", encoding="utf-8") as f:
    f.write("# Kaggle script kernel (GPU): 32-bit indexing boundary, release and nightly.\n"
            "import base64, subprocess, sys\n"
            f'open("int32_indexing_boundary.py", "wb").write(base64.b64decode("{b}"))\n'
            f"for spec in {install}:\n"
            '    subprocess.run(["pip", "-q", "install", *spec])\n'
            '    subprocess.run([sys.executable, "int32_indexing_boundary.py"])\n'
            'print("JOB DONE", flush=True)\n')
py_compile.compile(path, doraise=True)
d = open(os.path.join(HERE, "drive.py"), encoding="utf-8").read()
if '"int32gpu"' not in d:
    d = d.replace('    "symintlinux": ("tcc-symintlinux", False),\n', '    "symintlinux": ("tcc-symintlinux", False),\n    "int32gpu": ("tcc-int32gpu", True),\n')
    open(os.path.join(HERE, "drive.py"), "w", encoding="utf-8").write(d)
print("job written")
