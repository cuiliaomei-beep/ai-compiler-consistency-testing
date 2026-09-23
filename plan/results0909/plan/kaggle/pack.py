"""Pack plan/ for upload with forward-slash entry names (Compress-Archive on
Windows PowerShell 5.1 writes backslashes, which Kaggle rejects).

    python plan/kaggle/pack.py            -> toxic_compile/plan_kaggle.zip
"""
import os
import zipfile

HERE = os.path.dirname(os.path.abspath(__file__))
PLAN = os.path.dirname(HERE)
ROOT = os.path.dirname(PLAN)
OUT = os.path.join(ROOT, "plan_kaggle.zip")
KEEP = ["tcc", "tests", "scripts", "kaggle", "benchmark", "reproducers_gh", "reproducers_example",
        "run.py", "README.md", "EXECUTION_REPORT.md", "TO_SUBMIT.md"]


def main() -> None:
    n = 0
    with zipfile.ZipFile(OUT, "w", zipfile.ZIP_DEFLATED) as z:
        for k in KEEP:
            src = os.path.join(PLAN, k)
            if os.path.isfile(src):
                z.write(src, "plan/" + k)
                n += 1
                continue
            for root, dirs, files in os.walk(src):
                dirs[:] = [d for d in dirs if d != "__pycache__"]
                for f in files:
                    full = os.path.join(root, f)
                    rel = os.path.relpath(full, PLAN).replace(os.sep, "/")
                    z.write(full, "plan/" + rel)
                    n += 1
    print(f"written {OUT}: {n} files, {os.path.getsize(OUT) / 1e6:.1f} MB")


if __name__ == "__main__":
    main()
