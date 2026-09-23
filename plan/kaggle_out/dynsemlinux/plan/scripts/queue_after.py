"""Wait until the given marker files exist, then run a command (detached local job queue).
usage: python scripts/queue_after.py <marker1> [<marker2> ...] -- <command...>
"""
import os, subprocess, sys, time
i = sys.argv.index("--")
markers, cmd = sys.argv[1:i], sys.argv[i + 1:]
while not all(os.path.exists(m) for m in markers):
    time.sleep(120)
print("markers present, running:", " ".join(cmd), flush=True)
sys.exit(subprocess.run(cmd).returncode)
