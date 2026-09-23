"""8.1 Error parity: invalid inputs must fail under torch.compile exactly when they fail in eager.

Sources of invalid inputs:
  * OpInfo.error_inputs (226 operators ship them, with the expected exception type/regex),
  * EXTRA_CASES below: out-of-bounds indices and shape mismatches for the indexing family,
    where a missing check means a silent read of garbage rather than an exception.

Verdicts per (op, case, backend):
  SILENT         eager raises, compiled returns a value          <- the interesting one
  OTHER_TYPE     both raise, but the compiled exception is neither the same type nor a
                 Dynamo/Inductor wrapper carrying the eager message
  WRAPPED        compiled raises a Dynamo/Inductor wrapper whose text contains the eager message
  WRAPPED_OTHER  wrapper whose text does not mention the eager error at all
  ok             same exception type (message may differ)
  COMPILE_RAISES eager ok but compiled raises (only for 'ok:' control cases)

    python scripts/error_parity_sweep.py --isolate [--backends eager,aot_eager,inductor]
    python scripts/error_parity_sweep.py --only index_select --backends inductor --verbose
"""
import argparse
import os
import re
import sys
import traceback

sys.path.insert(0, os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
from tcc.compat import ensure_msvc_env  # noqa: E402

ensure_msvc_env()
import torch  # noqa: E402
import torch.nn.functional as F  # noqa: E402
from torch.testing._internal.common_methods_invocations import op_db  # noqa: E402

from tcc.sweep_common import exc_info, jsonl_append, run_isolated, tensors_of  # noqa: E402

torch._dynamo.config.recompile_limit = 10 ** 4
torch._dynamo.config.accumulated_recompile_limit = 10 ** 6
torch._dynamo.config.suppress_errors = False

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
WRAPPERS = ("TorchRuntimeError", "BackendCompilerFailed", "Unsupported", "InternalTorchDynamoError",
            "UserError", "LoweringException", "InductorError", "TorchDynamoException")


def T(*shape):
    return torch.randn(*shape)


def I(*vals):
    return torch.tensor(list(vals))


# name -> list of (label, builder).  builder() -> (args, kwargs); fn(*args, **kwargs) is expected to
# raise in eager.  A label starting with 'ok:' marks a valid control case (must NOT raise anywhere).
EXTRA_CASES = {
    "index_select": [
        ("oob_pos", lambda: ((T(4, 5), 0, I(0, 4)), {})),
        ("oob_neg", lambda: ((T(4, 5), 1, I(-6)), {})),
        ("ok:neg_in_range", lambda: ((T(4, 5), 1, I(-1, 0)), {})),
    ],
    "gather": [
        ("oob_pos", lambda: ((T(4, 5), 1, torch.tensor([[0, 5], [1, 2], [0, 0], [4, 4]])), {})),
        ("oob_neg", lambda: ((T(4, 5), 0, torch.tensor([[-5, 0, 1, 2, 3]])), {})),
    ],
    "take": [
        ("oob", lambda: ((T(4, 5), I(0, 20)), {})),
        ("oob_neg", lambda: ((T(4, 5), I(-21)), {})),
    ],
    "take_along_dim": [
        ("oob", lambda: ((T(4, 5), torch.tensor([[0, 5, 1, 1, 1]]), 1), {})),
    ],
    "scatter": [
        ("oob_index", lambda: ((torch.zeros(4, 5), 1, torch.tensor([[0, 5]]), torch.ones(1, 2)), {})),
    ],
    "scatter_add": [
        ("oob_index", lambda: ((torch.zeros(4, 5), 0, torch.tensor([[4, 0]]), torch.ones(1, 2)), {})),
    ],
    "scatter_reduce": [
        ("oob_index", lambda: ((torch.zeros(4, 5), 0, torch.tensor([[4, 0]]), torch.ones(1, 2), "sum"), {})),
    ],
    "index_add": [
        ("oob_index", lambda: ((torch.zeros(4, 5), 0, I(0, 4), torch.ones(2, 5)), {})),
    ],
    "index_copy": [
        ("oob_index", lambda: ((torch.zeros(4, 5), 1, I(0, 5), torch.ones(4, 2)), {})),
    ],
    "index_fill": [
        ("oob_index", lambda: ((torch.zeros(4, 5), 1, I(5), 1.0), {})),
    ],
    "index_put": [
        ("oob_index", lambda: ((torch.zeros(4, 5), (I(0, 4),), torch.ones(2, 5)), {})),
        ("oob_index_accumulate", lambda: ((torch.zeros(4, 5), (I(4),), torch.ones(5)), {"accumulate": True})),
    ],
    "__getitem__": [
        ("adv_oob", lambda: ((T(4, 5), I(0, 4)), {})),
        ("adv_oob_neg", lambda: ((T(4, 5), I(-5)), {})),
        ("adv_2d_oob", lambda: ((T(4, 5), (I(0, 1), I(0, 5))), {})),
        ("int_oob", lambda: ((T(4, 5), 4), {})),
        ("bool_mask_shape", lambda: ((T(4, 5), torch.tensor([True, False, True])), {})),
        ("ok:slice_oob_is_fine", lambda: ((T(4, 5), slice(0, 100)), {})),
        ("ok:adv_neg_in_range", lambda: ((T(4, 5), I(-4, 3)), {})),
    ],
    "nn.functional.embedding": [
        ("oob", lambda: ((I(0, 10), T(10, 3)), {})),
        ("oob_neg", lambda: ((I(-1), T(10, 3)), {})),
        ("oob_padding_idx", lambda: ((I(0, 10), T(10, 3)), {"padding_idx": 0})),
    ],
    "nn.functional.embedding_bag": [
        ("oob", lambda: ((I(0, 10), T(10, 3), I(0)), {})),
    ],
    "nn.functional.one_hot": [
        ("oob", lambda: ((I(0, 5),), {"num_classes": 5})),
        ("neg", lambda: ((I(-1, 1),), {"num_classes": 5})),
    ],
    "nn.functional.nll_loss": [
        ("target_oob", lambda: ((T(3, 5).log_softmax(1), I(0, 5, 1)), {})),
        ("target_neg", lambda: ((T(3, 5).log_softmax(1), I(0, -2, 1)), {})),
        ("target_oob_nored", lambda: ((T(3, 5).log_softmax(1), I(0, 5, 1)), {"reduction": "none"})),
        ("ok:ignore_index", lambda: ((T(3, 5).log_softmax(1), I(0, -100, 1)), {})),
    ],
    "nn.functional.cross_entropy": [
        ("target_oob", lambda: ((T(3, 5), I(0, 5, 1)), {})),
        ("target_oob_nored", lambda: ((T(3, 5), I(0, 7, 1)), {"reduction": "none"})),
        ("target_oob_smoothing", lambda: ((T(3, 5), I(0, 5, 1)), {"label_smoothing": 0.1})),
    ],
    "nn.functional.multi_margin_loss": [
        ("target_oob", lambda: ((T(3, 5), I(0, 5, 1)), {})),
    ],
    "narrow": [
        ("oob", lambda: ((T(4, 5), 1, 3, 4), {})),
    ],
    "select": [
        ("oob", lambda: ((T(4, 5), 0, 4), {})),
    ],
    "view": [
        ("bad_numel", lambda: ((T(4, 5), 3, 7), {})),
    ],
    "reshape": [
        ("bad_numel", lambda: ((T(4, 5), 3, -1), {})),
    ],
    "cat": [
        ("shape_mismatch", lambda: (([T(2, 3), T(3, 4)],), {})),
    ],
    "stack": [
        ("shape_mismatch", lambda: (([T(2, 3), T(3, 3)],), {})),
    ],
    "bmm": [
        ("shape_mismatch", lambda: ((T(2, 3, 4), T(2, 5, 4)), {})),
    ],
    "matmul": [
        ("shape_mismatch", lambda: ((T(3, 4), T(5, 4)), {})),
    ],
    "add": [
        ("broadcast_mismatch", lambda: ((T(3, 4), T(3)), {})),
    ],
    "where": [
        ("broadcast_mismatch", lambda: ((torch.tensor([True, False]), T(3), T(3)), {})),
    ],
    "multinomial": [
        ("neg_prob", lambda: ((torch.tensor([0.5, -0.5, 1.0]), 1), {})),
        ("zero_prob_sum", lambda: ((torch.tensor([0.0, 0.0]), 1), {})),
        ("too_many_without_replacement", lambda: ((torch.tensor([0.5, 0.5]), 3), {})),
    ],
    "randint": [
        ("low_ge_high", lambda: ((5, 5, (3,)), {})),
    ],
    "arange": [
        ("zero_step", lambda: ((0, 5, 0), {})),
        ("inf_size", lambda: ((0, float("inf"), 1), {})),
    ],
    "linspace": [
        ("neg_steps", lambda: ((0.0, 1.0, -1), {})),
    ],
    "full": [
        ("neg_shape", lambda: (((-1, 2), 1.0), {})),
    ],
    "repeat_interleave": [
        ("neg_repeats", lambda: ((T(3), I(1, -1, 2)), {})),
        ("bad_repeats_len", lambda: ((T(3), I(1, 2)), {})),
    ],
    "split": [
        ("bad_sizes", lambda: ((T(5), [2, 2]), {})),
    ],
    "chunk": [
        ("zero_chunks", lambda: ((T(5), 0), {})),
    ],
    "unfold": [
        ("size_too_big", lambda: ((T(5), 0, 6, 1), {})),
    ],
    "as_strided": [
        ("oob_storage", lambda: ((T(5), (10,), (1,)), {})),
    ],
    "nn.functional.pad": [
        ("neg_pad_too_big", lambda: ((T(1, 3), (-2, -2)), {})),
        ("reflect_too_big", lambda: ((T(1, 1, 3), (3, 3)), {"mode": "reflect"})),
    ],
    "nn.functional.interpolate": [
        ("zero_size", lambda: ((T(1, 1, 4),), {"size": 0})),
    ],
    "diagonal": [
        ("same_dims", lambda: ((T(3, 3),), {"dim1": 0, "dim2": 0})),
    ],
    "roll": [
        ("bad_dims", lambda: ((T(3, 3), (1, 1), 0), {})),
    ],
    "bincount": [
        ("negative", lambda: ((I(0, -1, 2),), {})),
    ],
    "nn.functional.max_pool2d": [
        ("kernel_too_big", lambda: ((T(1, 1, 3, 3), 5), {})),
    ],
    "nn.functional.conv2d": [
        ("channel_mismatch", lambda: ((T(1, 3, 5, 5), T(2, 4, 3, 3)), {})),
        ("groups_mismatch", lambda: ((T(1, 4, 5, 5), T(4, 4, 3, 3)), {"groups": 2})),
    ],
    "nn.functional.batch_norm": [
        ("single_batch_training", lambda: ((T(1, 3), None, None), {"training": True})),
    ],
    "nn.functional.layer_norm": [
        ("bad_shape", lambda: ((T(2, 3), (4,)), {})),
    ],
    "nn.functional.group_norm": [
        ("indivisible", lambda: ((T(2, 5, 3), 2), {})),
    ],
    "nn.functional.softmax": [
        ("dim_oob", lambda: ((T(2, 3), 2), {})),
    ],
    "sum": [
        ("dim_oob", lambda: ((T(2, 3), 2), {})),
        ("dup_dims", lambda: ((T(2, 3), (0, 0)), {})),
    ],
    "topk": [
        ("k_too_big", lambda: ((T(3), 4), {})),
    ],
    "kthvalue": [
        ("k_zero", lambda: ((T(3), 0), {})),
    ],
    "tril_indices": [
        ("neg", lambda: ((-1, 3), {})),
    ],
    "eye": [
        ("neg", lambda: ((-1,), {})),
    ],
    "nn.functional.ctc_loss": [
        ("blank_oob", lambda: ((T(4, 1, 3).log_softmax(2), torch.tensor([[1, 1]]), I(4), I(2)), {"blank": 3})),
    ],
    "searchsorted": [
        ("wrong_side", lambda: ((torch.tensor([1.0, 2.0]), torch.tensor([1.5])), {"side": "middle"})),
    ],
    "nn.functional.grid_sample": [
        ("bad_grid_last_dim", lambda: ((T(1, 1, 3, 3), T(1, 2, 2, 3)), {"align_corners": False})),
    ],
}

_FNS = {
    "__getitem__": lambda x, idx: x[idx],
    "nn.functional.embedding": F.embedding, "nn.functional.embedding_bag": F.embedding_bag,
    "nn.functional.one_hot": F.one_hot, "nn.functional.nll_loss": F.nll_loss,
    "nn.functional.cross_entropy": F.cross_entropy, "nn.functional.multi_margin_loss": F.multi_margin_loss,
    "nn.functional.pad": F.pad, "nn.functional.interpolate": F.interpolate,
    "nn.functional.max_pool2d": F.max_pool2d, "nn.functional.conv2d": F.conv2d,
    "nn.functional.batch_norm": F.batch_norm, "nn.functional.layer_norm": F.layer_norm,
    "nn.functional.group_norm": F.group_norm, "nn.functional.softmax": F.softmax,
    "nn.functional.ctc_loss": F.ctc_loss, "nn.functional.grid_sample": F.grid_sample,
    "view": lambda x, *s: x.view(*s), "reshape": lambda x, *s: x.reshape(*s),
    "unfold": lambda x, d, s, st: x.unfold(d, s, st), "as_strided": torch.as_strided,
    "split": torch.split, "chunk": torch.chunk, "repeat_interleave": torch.repeat_interleave,
}


def fn_for(name):
    if name in _FNS:
        return _FNS[name]
    return getattr(torch, name)


def classify(eager_exc, comp_exc, regex):
    if eager_exc is None:
        return "COMPILE_RAISES" if comp_exc is not None else "ok_valid"
    if comp_exc is None:
        return "SILENT"
    if isinstance(comp_exc, type(eager_exc)):
        return "ok"
    ctext, etext = str(comp_exc), str(eager_exc)
    mod = type(comp_exc).__module__
    if type(comp_exc).__name__ in WRAPPERS or mod.startswith("torch._dynamo") or mod.startswith("torch._inductor"):
        if type(eager_exc).__name__ in ctext or etext[:60] in ctext or (regex and re.search(regex, ctext)):
            return "WRAPPED"
        return "WRAPPED_OTHER"
    return "OTHER_TYPE"


def run_case(fn, args, kwargs, backends, regex, verbose):
    out = {}
    eager_exc = None
    try:
        with torch.no_grad():
            fn(*args, **kwargs)
    except Exception as e:  # noqa: BLE001
        eager_exc = e
    out["eager_ref"] = exc_info(eager_exc) if eager_exc else "no error"
    for b in backends:
        torch._dynamo.reset()
        comp_exc, comp_val = None, None
        try:
            cf = torch.compile(fn, backend=b)
            with torch.no_grad():
                comp_val = cf(*args, **kwargs)
        except Exception as e:  # noqa: BLE001
            comp_exc = e
        v = classify(eager_exc, comp_exc, regex)
        out[b] = {"verdict": v, "exc": exc_info(comp_exc) if comp_exc else None}
        if comp_exc is None and comp_val is not None:
            ts = tensors_of(comp_val)
            out[b]["value"] = [f"{tuple(t.shape)} {t.dtype} {t.flatten()[:6].tolist()}" for t in ts][:3]
        if verbose:
            print(f"    {b}: {v} {out[b]['exc'] or out[b].get('value')}", flush=True)
    return out


def cases_for(name, device="cpu"):
    """Yield (label, fn, args, kwargs, regex)."""
    if name in EXTRA_CASES:
        fn = fn_for(name)
        for label, build in EXTRA_CASES[name]:
            args, kwargs = build()
            yield f"extra:{label}", fn, args, kwargs, None
    for op in op_db:
        if op.name != name or op.error_inputs_func is None:
            continue
        try:
            eis = list(op.error_inputs(device))
        except Exception as e:  # noqa: BLE001
            print(f"  error_inputs({name}) failed: {e}")
            continue
        for k, ei in enumerate(eis):
            si = ei.sample_input
            yield f"opinfo:{k}:{ei.error_type.__name__}", op.op, (si.input,) + tuple(si.args), dict(si.kwargs), ei.error_regex


def all_names():
    return sorted(set(EXTRA_CASES) | {o.name for o in op_db if o.error_inputs_func is not None})


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--only", default=None)
    ap.add_argument("--skip", default="")
    ap.add_argument("--backends", default="eager,aot_eager,inductor")
    ap.add_argument("--isolate", action="store_true")
    ap.add_argument("--timeout", type=int, default=900)
    ap.add_argument("--verbose", action="store_true")
    ap.add_argument("--out-jsonl", default=os.path.join(ROOT, "results", "error_parity", "cases.jsonl"))
    a = ap.parse_args()
    os.makedirs(os.path.dirname(a.out_jsonl), exist_ok=True)
    backends = a.backends.split(",")
    skip = set(a.skip.split(",")) if a.skip else set()
    names = [n for n in (a.only.split(",") if a.only else all_names()) if n not in skip]
    if a.isolate:
        run_isolated(os.path.abspath(__file__), names, ["--backends", a.backends], a.out_jsonl, timeout=a.timeout)
        return
    print(f"torch {torch.__version__} | {len(names)} ops | backends {backends}", flush=True)
    for name in names:
        n_cases = 0
        for label, fn, args, kwargs, regex in cases_for(name):
            n_cases += 1
            if a.verbose:
                print(f"  {name} {label}", flush=True)
            try:
                res = run_case(fn, args, kwargs, backends, regex, a.verbose)
            except Exception as e:  # noqa: BLE001
                res = {"harness_error": exc_info(e), "tb": traceback.format_exc()[-800:]}
            worst = "ok"
            for b in backends:
                v = res.get(b, {}).get("verdict", "ok") if isinstance(res.get(b), dict) else "ok"
                if v == "SILENT" or (v in ("OTHER_TYPE", "WRAPPED_OTHER", "COMPILE_RAISES") and worst != "SILENT"):
                    worst = v
            jsonl_append(a.out_jsonl, {"op": name, "case": label, "verdict": worst, **res})
            if worst != "ok":
                print(f"  !! {name} {label}: {worst} | eager={res.get('eager_ref')} | "
                      + " | ".join(f"{b}={res.get(b, {}).get('verdict')}" for b in backends), flush=True)
        if n_cases == 0:
            jsonl_append(a.out_jsonl, {"op": name, "case": None, "verdict": "no_cases"})


if __name__ == "__main__":
    main()
