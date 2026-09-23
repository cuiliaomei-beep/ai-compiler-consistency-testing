"""Stand-alone confirmation of the four SILENT leads of the error-parity sweep (8.1).

Every (case, backend) runs in a fresh interpreter.  Usage:
    python scripts/diag_error_parity_leads.py            # all cases
    python scripts/diag_error_parity_leads.py CASE BACKEND   (child mode)
"""
import os
import subprocess
import sys

sys.path.insert(0, os.path.dirname(os.path.dirname(os.path.abspath(__file__))))

CASES = ["index_add_shape", "index_add_shape_2d", "index_select_neg", "index_select_neg_dim0", "take_out_overlap",
         "complex_out_dtype", "index_copy_shape", "index_add_shape_dynamic"]
BACKENDS = ["none", "eager", "aot_eager", "inductor"]


def build(case):
    import torch
    if case == "index_add_shape":
        x, idx, src = torch.zeros(3, 2), torch.tensor([0, 2]), torch.tensor([3.0, 4.0])
        return (lambda x, idx, src: torch.index_add(x, 0, idx, src)), (x, idx, src)
    if case == "index_add_shape_dynamic":
        x, idx, src = torch.zeros(3, 2), torch.tensor([0, 2]), torch.tensor([3.0, 4.0])
        return (lambda x, idx, src: torch.index_add(x, 0, idx, src)), (x, idx, src)
    if case == "index_add_shape_2d":
        x, idx, src = torch.zeros(4, 3), torch.tensor([0, 2]), torch.ones(2, 1)
        return (lambda x, idx, src: torch.index_add(x, 0, idx, src)), (x, idx, src)
    if case == "index_copy_shape":
        x, idx, src = torch.zeros(3, 2), torch.tensor([0, 2]), torch.tensor([3.0, 4.0])
        return (lambda x, idx, src: torch.index_copy(x, 0, idx, src)), (x, idx, src)
    if case == "index_select_neg":
        x, idx = torch.arange(20.).reshape(4, 5), torch.tensor([-1, 0])
        return (lambda x, idx: torch.index_select(x, 1, idx)), (x, idx)
    if case == "index_select_neg_dim0":
        x, idx = torch.arange(20.).reshape(4, 5), torch.tensor([-4])
        return (lambda x, idx: torch.index_select(x, 0, idx)), (x, idx)
    if case == "take_out_overlap":
        x = torch.arange(3)
        return (lambda x: torch.take(x, torch.tensor([1, 2]), out=x[:2])), (x,)
    if case == "complex_out_dtype":
        a, b = torch.randn(3), torch.randn(3)
        return (lambda a, b: torch.complex(a, b, out=torch.empty(3, dtype=torch.complex128))), (a, b)
    raise SystemExit(case)


def child(case, backend):
    from tcc.compat import ensure_msvc_env
    ensure_msvc_env()
    import torch
    fn, args = build(case)
    if backend != "none":
        fn = torch.compile(fn, backend=backend, dynamic=case.endswith("dynamic"))
    try:
        out = fn(*args)
        print(f"RESULT returned {tuple(out.shape)} {out.dtype} {out.flatten().tolist()[:8]}")
    except Exception as e:  # noqa: BLE001
        print(f"RESULT raised {type(e).__name__}: {str(e).splitlines()[0][:150]}")


def main():
    if len(sys.argv) == 3:
        return child(sys.argv[1], sys.argv[2])
    import torch
    print("torch", torch.__version__, sys.version.split()[0])
    for case in CASES:
        print(f"== {case}")
        for b in BACKENDS:
            p = subprocess.run([sys.executable, os.path.abspath(__file__), case, b], capture_output=True, text=True,
                               timeout=900, encoding="utf-8", errors="replace", env=dict(os.environ, PYTHONUTF8="1"))
            line = [l for l in p.stdout.splitlines() if l.startswith("RESULT")]
            print(f"   {b:10s} {line[0][7:] if line else 'exit=' + hex(p.returncode & 0xffffffff)}")


if __name__ == "__main__":
    main()
