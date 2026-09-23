# Kaggle CPU: is the conj-under-dispatch-mode bug a regression?  torch 2.10 .. 2.14
import base64, subprocess, sys
open("r.py", "wb").write(base64.b64decode("aW1wb3J0IHRvcmNoCmZyb20gdG9yY2gudXRpbHMuX3B5dGhvbl9kaXNwYXRjaCBpbXBvcnQgVG9yY2hEaXNwYXRjaE1vZGUKY2xhc3MgRm9yd2FyZChUb3JjaERpc3BhdGNoTW9kZSk6CiAgICBkZWYgX190b3JjaF9kaXNwYXRjaF9fKHNlbGYsIGZ1bmMsIHR5cGVzLCBhcmdzPSgpLCBrd2FyZ3M9Tm9uZSk6IHJldHVybiBmdW5jKCphcmdzLCAqKihrd2FyZ3Mgb3Ige30pKQp0b3JjaC5tYW51YWxfc2VlZCgwKQpBID0gdG9yY2gucmFuZG4oNCwgMywgZHR5cGU9dG9yY2guY29tcGxleDY0KQpyZWYgPSB0b3JjaC5saW5hbGcucGludihBKTsgcmVmUCA9IHRvcmNoLmxpbmFsZy5wb2xhcihBKVsxXQp3aXRoIEZvcndhcmQoKTogbSA9IHRvcmNoLmxpbmFsZy5waW52KEEpOyBtUCA9IHRvcmNoLmxpbmFsZy5wb2xhcihBKVsxXQp0cnk6CiAgICB0b3JjaC5fZHluYW1vLnJlc2V0KCk7IGMgPSB0b3JjaC5jb21waWxlKHRvcmNoLmxpbmFsZy5waW52LCBiYWNrZW5kPSJhb3RfZWFnZXIiKShBKTsgY2QgPSAoYyAtIHJlZikuYWJzKCkubWF4KCkuaXRlbSgpCmV4Y2VwdCBFeGNlcHRpb24gYXMgZTogY2QgPSB0eXBlKGUpLl9fbmFtZV9fCnByaW50KGYidG9yY2gge3RvcmNoLl9fdmVyc2lvbl9ffTogcGludiB8bW9kZSAtIGVhZ2VyfCB7KG0gLSByZWYpLmFicygpLm1heCgpLml0ZW0oKTouM2d9ICBwb2xhciBQIHxtb2RlIC0gZWFnZXJ8IHsobVAgLSByZWZQKS5hYnMoKS5tYXgoKS5pdGVtKCk6LjNnfSAgcGludiB8YW90X2VhZ2VyIGNvbXBpbGUgLSBlYWdlcnwge2NkfSIsIGZsdXNoPVRydWUpCg=="))
for v in ("2.10.0", "2.11.0", "2.12.0", "2.13.0", "2.14.0"):
    r = subprocess.run(["pip", "-q", "install", f"torch=={v}", "--index-url", "https://download.pytorch.org/whl/cpu"], capture_output=True, text=True)
    if r.returncode: print("install", v, "failed:", r.stderr[-200:], flush=True); continue
    subprocess.run([sys.executable, "r.py"])
print("JOB DONE", flush=True)
