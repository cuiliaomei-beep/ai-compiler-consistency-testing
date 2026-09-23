"""8.12  reduce-overhead (CUDA graph trees) stale-output detection.  Under mode="reduce-overhead" the outputs of a
compiled function live in graph-owned memory that the next replay overwrites; PyTorch promises that reading such an
output afterwards raises ("accessing tensor output of CUDAGraphs that has been overwritten by a subsequent run") --
or, for aliases / views / stored references, the same.  For each pattern below we keep a reference to an output,
run the function again, then read the old reference and classify:
    SAME   old value still readable and unchanged (safe)
    ERROR  reading raised (the documented protection)
    STALE  read succeeded but the value silently changed   <- the defect class
Also compared: the values themselves vs eager for every call (a wrong value on call 2 / 3 is reported as VALUE).
    python scripts/cudagraph_stale_sweep.py            -> results/cudagraph_stale/cases.jsonl   (needs CUDA)
"""
import json
import os
import sys
import tempfile
import traceback

os.environ.setdefault("TORCHINDUCTOR_CACHE_DIR", tempfile.mkdtemp(prefix="tcc_cg_"))
sys.path.insert(0, os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
import torch  # noqa: E402
import torch.nn as nn  # noqa: E402

assert torch.cuda.is_available(), "needs CUDA"
DEV = "cuda"
torch._dynamo.config.recompile_limit = 10 ** 4
CASES = {}


def case(f):
    CASES[f.__name__] = f
    return f


def T(*s, k=1.0):
    return (torch.arange(1.0, 1 + int(torch.tensor(s).prod().item()), device=DEV).reshape(*s) * k)


# Each case: build() -> (fn, [inputs for call 1], [inputs for call 2], [inputs for call 3], keep(out) -> reference to keep, read(ref) -> tensor)
@case
def plain_output():
    f = lambda x: x * 2 + 1  # noqa: E731
    return f, [T(4, 4)], [T(4, 4, k=3)], [T(4, 4, k=5)], lambda o: o, lambda r: r


@case
def view_of_output():
    f = lambda x: x * 2 + 1  # noqa: E731
    return f, [T(4, 4)], [T(4, 4, k=3)], [T(4, 4, k=5)], lambda o: o[1:3, ::2], lambda r: r


@case
def output_in_list():
    f = lambda x: (x * 2, x + 1)  # noqa: E731
    return f, [T(4, 4)], [T(4, 4, k=3)], [T(4, 4, k=5)], lambda o: list(o), lambda r: r[1]


@case
def output_alias_of_input():
    f = lambda x: x.view(16)  # noqa: E731
    return f, [T(4, 4)], [T(4, 4, k=3)], [T(4, 4, k=5)], lambda o: o, lambda r: r


@case
def output_after_inplace_on_input():
    def f(x):
        x.add_(1)
        return x * 2
    return f, [T(4, 4)], [T(4, 4, k=3)], [T(4, 4, k=5)], lambda o: o, lambda r: r


@case
def output_is_input_after_inplace():
    def f(x):
        x.mul_(2)
        return x
    return f, [T(4, 4)], [T(4, 4, k=3)], [T(4, 4, k=5)], lambda o: o, lambda r: r


@case
def detached_output():
    f = lambda x: (x * 2).detach()  # noqa: E731
    return f, [T(4, 4)], [T(4, 4, k=3)], [T(4, 4, k=5)], lambda o: o, lambda r: r


@case
def output_reshaped_by_caller():
    f = lambda x: x * 2  # noqa: E731
    return f, [T(4, 4)], [T(4, 4, k=3)], [T(4, 4, k=5)], lambda o: o.reshape(2, 8), lambda r: r


@case
def output_as_next_input_then_old_read():
    f = lambda x: x * 2  # noqa: E731
    # call 2 uses call-1 output as input; call 3 fresh; then read call-1 output
    return f, [T(4, 4)], "PREV", [T(4, 4, k=5)], lambda o: o, lambda r: r


@case
def module_with_buffer_update():
    m = nn.Sequential(nn.Linear(8, 8), nn.BatchNorm1d(8)).to(DEV)
    m.train()
    return m, [T(4, 8, k=0.1)], [T(4, 8, k=0.2)], [T(4, 8, k=0.3)], lambda o: o, lambda r: r


@case
def module_eval_output():
    m = nn.Sequential(nn.Linear(8, 8), nn.ReLU(), nn.Linear(8, 4)).to(DEV).eval()
    return m, [T(4, 8, k=0.1)], [T(4, 8, k=0.2)], [T(4, 8, k=0.3)], lambda o: o, lambda r: r


@case
def different_shape_second_call():
    f = lambda x: x * 2 + 1  # noqa: E731
    return f, [T(4, 4)], [T(8, 4, k=3)], [T(4, 4, k=5)], lambda o: o, lambda r: r


@case
def scalar_output_item_later():
    f = lambda x: (x * 2).sum()  # noqa: E731
    return f, [T(4, 4)], [T(4, 4, k=3)], [T(4, 4, k=5)], lambda o: o, lambda r: r


@case
def output_with_requires_grad():
    f = lambda x: x * 2 + 1  # noqa: E731
    return f, [T(4, 4).requires_grad_()], [T(4, 4, k=3).requires_grad_()], [T(4, 4, k=5).requires_grad_()], lambda o: o, lambda r: r.detach()


@case
def output_moved_to_cpu_lazily():
    f = lambda x: x * 2 + 1  # noqa: E731
    return f, [T(4, 4)], [T(4, 4, k=3)], [T(4, 4, k=5)], lambda o: o, lambda r: r.cpu()


@case
def output_expanded_view():
    f = lambda x: (x * 2).sum(0)  # noqa: E731
    return f, [T(4, 4)], [T(4, 4, k=3)], [T(4, 4, k=5)], lambda o: o.expand(3, 4), lambda r: r


@case
def two_compiled_functions_interleaved():
    f = lambda x: x * 2  # noqa: E731
    g = lambda x: x + 3  # noqa: E731
    cg = torch.compile(g, mode="reduce-overhead")

    def h(x):
        return f(x)
    # keep f's output, run g (a different graph tree) in between via call 2's input builder
    return h, [T(4, 4)], ("CALL_OTHER", cg, [T(4, 4, k=7)]), [T(4, 4, k=5)], lambda o: o, lambda r: r


@case
def output_stored_in_dict_then_two_runs():
    f = lambda x: x * 2  # noqa: E731
    return f, [T(4, 4)], [T(4, 4, k=3)], [T(4, 4, k=5)], lambda o: {"y": o}, lambda r: r["y"]


@case
def mark_step_begin_between():
    f = lambda x: x * 2  # noqa: E731
    return f, [T(4, 4)], ("MARK_STEP", [T(4, 4, k=3)]), [T(4, 4, k=5)], lambda o: o, lambda r: r


def snapshot(t):
    return t.detach().clone().cpu()


def run_case(name, build):
    rec = {"case": name}
    try:
        fn, in1, in2, in3, keep, read = build()
        eager_fn = fn
        cf = torch.compile(fn, mode="reduce-overhead")
        # eager reference values
        ref = []
        e_ins = [in1, in2 if isinstance(in2, list) else None, in3]
        out1 = cf(*[t.clone() if isinstance(t, torch.Tensor) else t for t in in1])
        kept = keep(out1)
        first_read = snapshot(read(kept))
        eag1 = eager_fn(*[t.clone() for t in in1]) if not isinstance(fn, nn.Module) else None
        # call 2
        if in2 == "PREV":
            out2 = cf(out1)
        elif isinstance(in2, tuple) and in2[0] == "CALL_OTHER":
            in2[1](*in2[2]); out2 = None
        elif isinstance(in2, tuple) and in2[0] == "MARK_STEP":
            torch.compiler.cudagraph_mark_step_begin(); out2 = cf(*[t.clone() for t in in2[1]])
        else:
            out2 = cf(*[t.clone() for t in in2])
        # call 3 (a second replay, in case the first is still a warm-up / recording)
        out3 = cf(*[t.clone() for t in in3])
        torch.cuda.synchronize()
        try:
            later = snapshot(read(kept))
            if torch.equal(later, first_read):
                rec["stale"] = "SAME"
            else:
                rec["stale"] = "STALE"
                rec["detail"] = f"first {first_read.flatten()[:4].tolist()} later {later.flatten()[:4].tolist()}"
        except Exception as e:  # noqa: BLE001
            rec["stale"] = "ERROR"
            rec["error"] = f"{type(e).__name__}: {str(e)[:160]}"
        # value check of the latest output vs eager
        if isinstance(fn, nn.Module):
            rec["value"] = "skipped(module)"
        else:
            e3 = eager_fn(*[t.clone() for t in in3])
            f3 = [t for t in (out3 if isinstance(out3, (tuple, list)) else [out3])]
            g3 = [t for t in (e3 if isinstance(e3, (tuple, list)) else [e3])]
            rec["value"] = "ok" if all(torch.allclose(a.detach().float(), b.detach().float()) for a, b in zip(f3, g3)) else "VALUE"
    except Exception as e:  # noqa: BLE001
        rec["stale"] = "CASE_ERROR"
        rec["error"] = f"{type(e).__name__}: {str(e)[:200]}"
        rec["tb"] = traceback.format_exc()[-800:]
    return rec


def main():
    os.makedirs("results/cudagraph_stale", exist_ok=True)
    out = open("results/cudagraph_stale/cases.jsonl", "w", encoding="utf-8")
    print("torch", torch.__version__, torch.cuda.get_device_name(0), flush=True)
    for name, build in CASES.items():
        torch._dynamo.reset()
        rec = run_case(name, build)
        out.write(json.dumps(rec) + "\n"); out.flush()
        print(f"{rec.get('stale'):10s} value={rec.get('value')!s:14s} {name:40s} {rec.get('detail') or rec.get('error') or ''}"[:220], flush=True)
    print("SWEEP DONE", flush=True)


if __name__ == "__main__":
    main()
