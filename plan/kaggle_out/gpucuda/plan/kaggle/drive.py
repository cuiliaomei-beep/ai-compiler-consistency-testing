"""Drive Kaggle from this machine (no clicking): upload the dataset, push jobs, poll, pull outputs.

One-time: Kaggle -> Settings -> API -> Create New Token -> save kaggle.json to %USERPROFILE%\\.kaggle\\kaggle.json

    python kaggle/drive.py dataset                 # create / add a version of dataset <user>/tcc-plan from plan_kaggle.zip
    python kaggle/drive.py push bench214           # push + start a job (jobs: bench210 bench214 gpusweeps bindinggpu)
    python kaggle/drive.py status bench214         # running / complete / error
    python kaggle/drive.py log bench214            # last lines of the job log
    python kaggle/drive.py pull bench214           # download the job's output into plan/kaggle_out/<job>/
    python kaggle/drive.py wait bench214 bench210  # poll until all finished, then pull

Jobs are plain Python scripts in kaggle/jobs/ run as Kaggle "script" kernels; every job starts by copying the
dataset into /kaggle/working/plan, so outputs land under /kaggle/working and come back with `pull`.
"""
import json
import os
import shutil
import subprocess
import sys
import time

HERE = os.path.dirname(os.path.abspath(__file__))
PLAN = os.path.dirname(HERE)
ROOT = os.path.dirname(PLAN)
DATASET_SLUG = "tcc-plan"
JOBS = {
    # job name: (title, needs_gpu)
    "bench210": ("tcc bench torch 2.10 cpu", False),
    "bench214": ("tcc bench torch 2.14 cpu", False),
    "gpusweeps": ("tcc gpu sweeps", True),
    "bindinggpu": ("tcc binding variants gpu", True),
    "models": ("tcc real models gpu", True),
}


def sh(*args, check=True, capture=False):
    if args and args[0] == "kaggle":          # the CLI's script dir is not on PATH here; call the module instead
        args = (sys.executable, "-m", "kaggle.cli") + tuple(args[1:])
    r = subprocess.run(list(args), text=True, capture_output=capture, encoding="utf-8", errors="replace")
    if check and r.returncode != 0:
        raise SystemExit(f"command failed ({r.returncode}): {' '.join(args)}\n{(r.stdout or '') + (r.stderr or '')}")
    return r


_USER = None


def username():
    """From kaggle.json (legacy) or from `kaggle config view` (access-token auth)."""
    global _USER
    if _USER:
        return _USER
    p = os.environ.get("KAGGLE_CONFIG_DIR") or os.path.join(os.path.expanduser("~"), ".kaggle")
    f = os.path.join(p, "kaggle.json")
    if os.path.exists(f):
        _USER = json.load(open(f))["username"]
        return _USER
    r = sh("kaggle", "config", "view", check=False, capture=True)
    for ln in (r.stdout or "").splitlines():
        if "username:" in ln:
            _USER = ln.split("username:", 1)[1].strip()
            return _USER
    raise SystemExit(f"no Kaggle credentials: save the access token to {p}\\access_token "
                     "(Kaggle -> Settings -> API -> Create New Token)")


def cmd_dataset():
    user = username()
    zip_path = os.path.join(ROOT, "plan_kaggle.zip")
    if not os.path.exists(zip_path):
        sh(sys.executable, os.path.join(HERE, "pack.py"))
    stage = os.path.join(PLAN, "kaggle_out", "_dataset")
    shutil.rmtree(stage, ignore_errors=True)
    os.makedirs(stage)
    shutil.copy(zip_path, stage)
    shutil.copy(os.path.join(HERE, "bootstrap.sh"), stage)
    meta = {"title": DATASET_SLUG, "id": f"{user}/{DATASET_SLUG}", "licenses": [{"name": "CC0-1.0"}]}
    json.dump(meta, open(os.path.join(stage, "dataset-metadata.json"), "w"))
    exists = sh("kaggle", "datasets", "list", "-m", "-s", DATASET_SLUG, check=False, capture=True)
    if f"{user}/{DATASET_SLUG}" in (exists.stdout or ""):
        sh("kaggle", "datasets", "version", "-p", stage, "-m", f"update {time.strftime('%Y-%m-%d %H:%M')}", "--dir-mode", "zip")
    else:
        sh("kaggle", "datasets", "create", "-p", stage, "--dir-mode", "zip")
    print(f"dataset {user}/{DATASET_SLUG} uploaded; Kaggle needs a minute to process the version")


def kernel_id(job):
    return f"{username()}/tcc-{job}"


def cmd_push(job):
    title, gpu = JOBS[job]
    user = username()
    src = os.path.join(HERE, "jobs", f"{job}.py")
    if not os.path.exists(src):
        raise SystemExit(f"no job script {src}")
    stage = os.path.join(PLAN, "kaggle_out", "_kernel_" + job)
    shutil.rmtree(stage, ignore_errors=True)
    os.makedirs(stage)
    shutil.copy(src, os.path.join(stage, f"{job}.py"))
    meta = {
        "id": kernel_id(job), "title": title, "code_file": f"{job}.py", "language": "python",
        "kernel_type": "script", "is_private": "true", "enable_gpu": "true" if gpu else "false",
        "enable_tpu": "false", "enable_internet": "true",
        "dataset_sources": [f"{user}/{DATASET_SLUG}"], "competition_sources": [], "kernel_sources": [], "model_sources": [],
    }
    json.dump(meta, open(os.path.join(stage, "kernel-metadata.json"), "w"), indent=2)
    sh("kaggle", "kernels", "push", "-p", stage)
    print(f"pushed {kernel_id(job)}  (gpu={gpu}); it queues and runs on Kaggle now")


def cmd_status(job):
    r = sh("kaggle", "kernels", "status", kernel_id(job), check=False, capture=True)
    print((r.stdout or r.stderr).strip())
    return (r.stdout or "")


def cmd_log(job, n=40):
    dest = os.path.join(PLAN, "kaggle_out", "_log_" + job)
    shutil.rmtree(dest, ignore_errors=True)
    r = sh("kaggle", "kernels", "output", kernel_id(job), "-p", dest, check=False, capture=True)
    logs = [f for f in os.listdir(dest) if f.endswith(".log")] if os.path.isdir(dest) else []
    if not logs:
        print((r.stdout or r.stderr).strip()[-500:])
        return
    lines = open(os.path.join(dest, logs[0]), encoding="utf-8", errors="replace").read().splitlines()
    print("\n".join(lines[-n:]))


def cmd_pull(job):
    dest = os.path.join(PLAN, "kaggle_out", job)
    os.makedirs(dest, exist_ok=True)
    sh("kaggle", "kernels", "output", kernel_id(job), "-p", dest)
    print(f"output of {job} in {dest}")


def cmd_wait(jobs, every=300):
    pending = list(jobs)
    while pending:
        for j in list(pending):
            s = cmd_status(j)
            if "complete" in s.lower():
                cmd_pull(j)
                pending.remove(j)
            elif "error" in s.lower() or "cancel" in s.lower():
                print(f"{j}: failed -> log:")
                cmd_log(j)
                pending.remove(j)
        if pending:
            time.sleep(every)


def main():
    if len(sys.argv) < 2:
        print(__doc__)
        return 1
    cmd, rest = sys.argv[1], sys.argv[2:]
    if cmd == "dataset":
        cmd_dataset()
    elif cmd == "push":
        for j in rest:
            cmd_push(j)
    elif cmd == "status":
        for j in rest:
            cmd_status(j)
    elif cmd == "log":
        cmd_log(rest[0])
    elif cmd == "pull":
        for j in rest:
            cmd_pull(j)
    elif cmd == "wait":
        cmd_wait(rest)
    else:
        print(__doc__)
        return 1
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
