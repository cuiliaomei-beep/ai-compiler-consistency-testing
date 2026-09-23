# source: https://github.com/pytorch/pytorch/issues/185248
# title: `torch.compile` silently accepts negative standard deviations in `torch.normal` that eager mode rejects
# state: open  created: 2026-05-26
# mined automatically; the harness records the torch.compile target and its first call

import traceback
import torch

def model():
    mean = torch.zeros((4,), dtype=torch.float32)
    std = torch.full((4,), -1.0, dtype=torch.float32)
    return torch.normal(mean, std)

def run(label, fn):
    torch.manual_seed(0)
    try:
        out = fn()
    except Exception:
        print(f"{label}: raised")
        print(traceback.format_exc())
        return None
    print(f"{label}: returned {out}")
    return out

if __name__ == "__main__":
    print("torch", torch.__version__)
    eager = run("eager", model)
    compiled = run("compiled", lambda: torch.compile(model, backend="inductor")())
    if eager is None and compiled is not None:
        print("BUG: compiled execution accepted negative normal std.")
