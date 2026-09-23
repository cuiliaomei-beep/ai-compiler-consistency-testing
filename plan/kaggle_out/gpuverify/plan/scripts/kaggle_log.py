"""Print the stdout/stderr text of a Kaggle kernel log (the .log is a JSON array of stream chunks).

usage: python scripts/kaggle_log.py kaggle_out/<job>/<name>.log [grep-regex]
"""
import json
import re
import sys

path = sys.argv[1]
pat = re.compile(sys.argv[2]) if len(sys.argv) > 2 else None
txt = open(path, encoding="utf-8", errors="replace").read()
try:
    chunks = json.loads(txt)
except json.JSONDecodeError:
    # tolerate a truncated / oddly framed file: pull the objects out one by one
    chunks = [json.loads(m.group(0)) for m in re.finditer(r'\{"stream_name":"[a-z]+","time":[0-9.]+,"data":"(?:[^"\\]|\\.)*"\}', txt)]
full = "".join(c.get("data", "") for c in chunks)
for ln in full.splitlines():
    if pat is None or pat.search(ln):
        print(ln)
