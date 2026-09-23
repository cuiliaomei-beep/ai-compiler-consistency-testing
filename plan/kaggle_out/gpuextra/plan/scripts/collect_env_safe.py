"""torch.utils.collect_env on a non-English Windows console: decode subprocess output leniently."""
import locale
import subprocess

import torch.utils.collect_env as ce


def run(command):
    p = subprocess.Popen(command, stdout=subprocess.PIPE, stderr=subprocess.PIPE, shell=True)
    raw_output, raw_err = p.communicate()
    enc = "oem" if ce.get_platform() == "win32" else locale.getpreferredencoding()
    try:
        output, err = raw_output.decode(enc), raw_err.decode(enc)
    except Exception:  # noqa: BLE001
        output, err = raw_output.decode("utf-8", errors="replace"), raw_err.decode("utf-8", errors="replace")
    return p.returncode, output.strip(), err.strip()


ce.run = run
print(ce.get_pretty_env_info())
