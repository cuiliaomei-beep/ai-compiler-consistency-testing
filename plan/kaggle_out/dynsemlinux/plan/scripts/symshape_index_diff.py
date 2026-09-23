"""10.5b  Symbolic sizes flowing into slicing / indexing / shape operators, at the awkward values.

Under `dynamic=True` an integer derived from `x.shape[0]` stays symbolic when it is used as a slice bound, a step, a
roll amount, a pad width, a repeat count, a split size ...  Python / eager semantics at the boundaries (negative bounds
counted from the end, bounds clamped to the length, empty results, zero counts, negative pads that crop, errors for
invalid values) have to be reproduced by symbolic reasoning that is decided once, at trace time.  One compiled function
per program is called with a sequence of lengths chosen so that the derived integer crosses zero, the length, and
twice the length; every output must equal eager's (dtype, shape, values; exceptions by kind).

    python scripts/symshape_index_diff.py --isolate
    python scripts/symshape_index_diff.py --report
"""
import argparse
import json
import os
import sys

sys.path.insert(0, os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
from tcc.compat import ensure_msvc_env  # noqa: E402

ensure_msvc_env()
import torch  # noqa: E402
import torch.nn.functional as F  # noqa: E402

from tcc.sweep_common import jsonl_append, run_isolated  # noqa: E402

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
torch._dynamo.config.recompile_limit = 10 ** 4
LENGTHS = [12, 7, 10, 3, 20, 11, 9, 1, 25, 10, 2, 13]        # k = n - 10 takes -3, 0, -7, 10, 1, -1, -9, 15, 0, -8, 3, 2

# x: 1-D float tensor of length n (values 1..n);  m: 2-D (n, 4);  k = n - 10 (crosses zero);  h = n // 2
P = {
    "slice_from_k": lambda x, m, n, k, h: x[k:], "slice_to_k": lambda x, m, n, k, h: x[:k], "slice_k_to_h": lambda x, m, n, k, h: x[k:h], "slice_h_to_k": lambda x, m, n, k, h: x[h:k],
    "slice_neg_k": lambda x, m, n, k, h: x[-k:], "slice_to_neg_k": lambda x, m, n, k, h: x[:-k], "slice_beyond": lambda x, m, n, k, h: x[: n * 2], "slice_from_beyond": lambda x, m, n, k, h: x[n + 3:],
    "slice_from_neg_beyond": lambda x, m, n, k, h: x[-(n + 3):], "slice_step_h": lambda x, m, n, k, h: x[:: max(h, 1)], "slice_step_k": lambda x, m, n, k, h: x[::k], "slice_k_step2": lambda x, m, n, k, h: x[k::2],
    "slice_2d_rows": lambda x, m, n, k, h: m[k:, 1:], "slice_2d_cols": lambda x, m, n, k, h: m[:, k:], "index_k": lambda x, m, n, k, h: x[k], "index_neg_h": lambda x, m, n, k, h: x[-h],
    "index_n_minus_1": lambda x, m, n, k, h: x[n - 1], "index_n": lambda x, m, n, k, h: x[n], "setitem_slice_k": lambda x, m, n, k, h: _set(x, slice(k, None), 0.0),
    "setitem_slice_to_k": lambda x, m, n, k, h: _set(x, slice(None, k), 0.0), "setitem_index_k": lambda x, m, n, k, h: _set(x, k, 0.0), "narrow_k": lambda x, m, n, k, h: x.narrow(0, k, 2),
    "narrow_len_k": lambda x, m, n, k, h: x.narrow(0, 0, k), "narrow_neg_start": lambda x, m, n, k, h: x.narrow(0, -h, h), "select_k": lambda x, m, n, k, h: m.select(0, k),
    "roll_k": lambda x, m, n, k, h: torch.roll(x, k), "roll_big": lambda x, m, n, k, h: torch.roll(x, n * 3 + 1), "roll_2d": lambda x, m, n, k, h: torch.roll(m, (k, -k), (0, 1)),
    "pad_k_left": lambda x, m, n, k, h: F.pad(x, (k, 0)), "pad_k_right": lambda x, m, n, k, h: F.pad(x, (0, k)), "pad_both": lambda x, m, n, k, h: F.pad(x, (k, -k)),
    "pad_reflect_h": lambda x, m, n, k, h: F.pad(x[None, None], (min(h, n - 1), 0), mode="reflect"), "pad_replicate_k": lambda x, m, n, k, h: F.pad(x[None, None], (k, 1), mode="replicate"),
    "pad_circular_h": lambda x, m, n, k, h: F.pad(x[None, None], (h, h), mode="circular"), "repeat_k": lambda x, m, n, k, h: x.repeat(k), "repeat_mod": lambda x, m, n, k, h: x.repeat(n % 3),
    "repeat_interleave_h": lambda x, m, n, k, h: x.repeat_interleave(h), "expand_k": lambda x, m, n, k, h: x[:1].expand(k), "tile_mod": lambda x, m, n, k, h: torch.tile(x, (n % 3,)),
    "split_h": lambda x, m, n, k, h: list(x.split(max(h, 1))), "split_k": lambda x, m, n, k, h: list(x.split(k)), "split_sizes": lambda x, m, n, k, h: list(x.split([h, n - h])),
    "chunk_h": lambda x, m, n, k, h: list(x.chunk(max(h, 1))), "chunk_k": lambda x, m, n, k, h: list(x.chunk(k)), "tensor_split_h": lambda x, m, n, k, h: list(x.tensor_split(max(h, 1))),
    "tensor_split_idx": lambda x, m, n, k, h: list(x.tensor_split([k, h])), "unfold_h": lambda x, m, n, k, h: x.unfold(0, max(h, 1), 2), "unfold_k": lambda x, m, n, k, h: x.unfold(0, k, 1),
    "view_h": lambda x, m, n, k, h: x[: h * 2].view(2, h), "view_neg1": lambda x, m, n, k, h: x[: h * 2].view(-1, max(h, 1)), "reshape_k": lambda x, m, n, k, h: x[:k].reshape(1, k),
    "flatten_unflatten": lambda x, m, n, k, h: m.flatten().unflatten(0, (n, 4)), "arange_n": lambda x, m, n, k, h: torch.arange(n), "arange_k": lambda x, m, n, k, h: torch.arange(k),
    "arange_k_n": lambda x, m, n, k, h: torch.arange(k, n), "arange_desc": lambda x, m, n, k, h: torch.arange(n, 0, -2), "arange_step_k": lambda x, m, n, k, h: torch.arange(0, n, k),
    "arange_float_step": lambda x, m, n, k, h: torch.arange(0, 1, 1 / n), "linspace_n": lambda x, m, n, k, h: torch.linspace(0, 1, n), "linspace_k": lambda x, m, n, k, h: torch.linspace(0, 1, k),
    "zeros_k": lambda x, m, n, k, h: torch.zeros(k), "ones_k_h": lambda x, m, n, k, h: torch.ones(k, h), "full_k": lambda x, m, n, k, h: torch.full((max(k, 0),), float(k)), "eye_h_k": lambda x, m, n, k, h: torch.eye(h, k),
    "tril_k": lambda x, m, n, k, h: torch.ones(4, 4).tril(k), "triu_neg_k": lambda x, m, n, k, h: torch.ones(4, 4).triu(-k), "diag_k": lambda x, m, n, k, h: torch.diag(m, k), "diagonal_k": lambda x, m, n, k, h: m.diagonal(k),
    "diag_embed_k": lambda x, m, n, k, h: torch.diag_embed(x[:3], k), "topk_h": lambda x, m, n, k, h: x.topk(h).values, "topk_k": lambda x, m, n, k, h: x.topk(k).values, "kthvalue_h": lambda x, m, n, k, h: x.kthvalue(max(h, 1)).values,
    "cumsum_dim_neg": lambda x, m, n, k, h: m.cumsum(k % 2 - 2), "sum_dim_mod": lambda x, m, n, k, h: m.sum(n % 2), "transpose_mod": lambda x, m, n, k, h: m.transpose(n % 2, 1), "flip_mod": lambda x, m, n, k, h: m.flip(n % 2),
    "movedim_mod": lambda x, m, n, k, h: m[None].movedim(0, n % 3), "squeeze_mod": lambda x, m, n, k, h: m[:1].squeeze(n % 2), "unsqueeze_neg": lambda x, m, n, k, h: x.unsqueeze(-(n % 2) - 1),
    "cat_slices": lambda x, m, n, k, h: torch.cat([x[k:], x[:k]]), "stack_mod": lambda x, m, n, k, h: torch.stack([x] * (n % 3 + 1)), "list_mul_k": lambda x, m, n, k, h: torch.stack([x[:1]] * k) if k > 0 else x[:0],
    "index_select_mod": lambda x, m, n, k, h: x.index_select(0, torch.tensor([n % 3, -1 % n])), "gather_clamped": lambda x, m, n, k, h: x.gather(0, torch.tensor([min(max(k, 0), n - 1)])),
    "take_neg": lambda x, m, n, k, h: x.take(torch.tensor([-1, k % n])), "roll_then_slice": lambda x, m, n, k, h: torch.roll(x, k)[:h], "pixel_like_view": lambda x, m, n, k, h: m[: h * 2].view(h, 2, 4).transpose(0, 1),
    "as_strided_h": lambda x, m, n, k, h: x.as_strided((h,), (2,)), "as_strided_off_k": lambda x, m, n, k, h: x.as_strided((2,), (1,), max(k, 0)), "new_empty_shape": lambda x, m, n, k, h: x.new_zeros(max(k, 0), 2).shape,
    "numel_branch": lambda x, m, n, k, h: x[k:].numel() == 0, "len_slice": lambda x, m, n, k, h: len(x[k:h]), "size_arith": lambda x, m, n, k, h: x[k:].shape[0] * 2 - x[:k].shape[0],
    "interp_size_h": lambda x, m, n, k, h: F.interpolate(x[None, None], size=max(h, 1)), "interp_scale": lambda x, m, n, k, h: F.interpolate(x[None, None], scale_factor=1 + (n % 3) / 2),
    "avg_pool_kernel_h": lambda x, m, n, k, h: F.avg_pool1d(x[None, None], max(min(h, 3), 1)), "max_pool_stride_mod": lambda x, m, n, k, h: F.max_pool1d(x[None, None], 2, n % 2 + 1),
    "adaptive_pool_h": lambda x, m, n, k, h: F.adaptive_avg_pool1d(x[None, None], max(h, 1)), "unfold_im2col": lambda x, m, n, k, h: F.unfold(m[None, None], (min(h, 2) or 1, 2)),
    "one_hot_mod": lambda x, m, n, k, h: F.one_hot(torch.arange(3) % (n % 3 + 1), n % 3 + 1), "embedding_idx_mod": lambda x, m, n, k, h: F.embedding(torch.tensor([n % 4, (n - 1) % 4]), torch.arange(8.0).view(4, 2)),
    "bincount_minlength_k": lambda x, m, n, k, h: torch.bincount(torch.tensor([0, 1, 1]), minlength=max(k, 0)), "randperm_free_sort": lambda x, m, n, k, h: torch.sort(x, descending=bool(n % 2)).values,
    "clamp_by_size": lambda x, m, n, k, h: x.clamp(min=k, max=h), "fill_by_size": lambda x, m, n, k, h: torch.full_like(x, k / n), "pow_by_size": lambda x, m, n, k, h: x ** (n % 3), "mul_sign": lambda x, m, n, k, h: x * (1 if k >= 0 else -1),
    "where_by_size": lambda x, m, n, k, h: torch.where(x > h, x, torch.zeros(())), "mask_by_arange": lambda x, m, n, k, h: x * (torch.arange(n) < k), "shift_by_size": lambda x, m, n, k, h: x.long() << (n % 5),
    "floor_div_by_size": lambda x, m, n, k, h: x.long() // (k if k != 0 else 1), "remainder_by_size": lambda x, m, n, k, h: x.long() % (k if k != 0 else 1),
}


def _set(x, key, v):
    y = x.clone()
    y[key] = v
    return y


def norm(o):
    if isinstance(o, torch.Tensor):
        return {"T": str(o.dtype), "shape": list(o.shape), "v": [("nan" if v != v else round(float(v), 5)) for v in o.flatten().double().tolist()]}
    if isinstance(o, (list, tuple, torch.Size)):
        return [norm(x) for x in o]
    if isinstance(o, float):
        return round(o, 6)
    return o if isinstance(o, (int, bool, str)) or o is None else repr(type(o).__name__)


def observe(f, n):
    x = torch.arange(1.0, n + 1)
    m = torch.arange(1.0, n * 4 + 1).view(n, 4)
    try:
        return norm(f(x, m))
    except Exception as e:  # noqa: BLE001
        return {"raised": type(e).__name__}


def run_case(name, backends):
    e = P[name]
    prog = lambda x, m: e(x, m, x.shape[0], x.shape[0] - 10, x.shape[0] // 2)
    rec = {"op": name, "diffs": []}
    for backend in backends:
        torch._dynamo.reset()
        cf = torch.compile(prog, backend=backend, dynamic=True)
        for n in LENGTHS:
            want, got = observe(prog, n), observe(cf, n)
            if want != got:
                er, cr = isinstance(want, dict) and "raised" in want, isinstance(got, dict) and "raised" in got
                cls = "exc-type" if er and cr else "SILENT" if er else "RAISES" if cr else "VALUE"
                rec["diffs"].append({"backend": backend, "n": n, "class": cls, "eager": want, "compiled": got})
    classes = sorted({d["class"] for d in rec["diffs"]} - {"exc-type"})
    rec["verdict"] = "ok" if not classes else "DIFF:" + "+".join(classes)
    return rec


def report(path):
    from collections import Counter
    rows = [json.loads(l) for l in open(path, encoding="utf-8") if l.strip()]
    print(len(rows), dict(Counter(r["verdict"] for r in rows)))
    for r in rows:
        if r["verdict"] == "ok":
            continue
        print(f"\n[{r['verdict']}] {r['op']}")
        if r["verdict"] == "CRASH":
            print("   rc", r.get("returncode"), r.get("tail", "")[-300:]); continue
        shown = set()
        for d in r["diffs"]:
            key = (d["backend"], d["class"])
            if key in shown or d["class"] == "exc-type":
                continue
            shown.add(key)
            ns = [x["n"] for x in r["diffs"] if (x["backend"], x["class"]) == key]
            print(f"   {d['backend']:9s} {d['class']:7s} n={ns}: eager {json.dumps(d['eager'])[:140]}  compiled {json.dumps(d['compiled'])[:140]}")


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--only", default=None)
    ap.add_argument("--backends", default="eager,aot_eager,inductor")
    ap.add_argument("--isolate", action="store_true")
    ap.add_argument("--report", action="store_true")
    ap.add_argument("--out-jsonl", default=os.path.join(ROOT, "results", "symshape", "cases.jsonl"))
    a = ap.parse_args()
    os.makedirs(os.path.dirname(a.out_jsonl), exist_ok=True)
    if a.report:
        return report(a.out_jsonl)
    names = a.only.split(",") if a.only else list(P)
    if a.isolate:
        return run_isolated(os.path.abspath(__file__), names, ["--backends", a.backends], a.out_jsonl, timeout=2400)
    for n in names:
        rec = run_case(n, a.backends.split(","))
        jsonl_append(a.out_jsonl, rec)
        if rec["verdict"] != "ok":
            print(f"  !! {n}: {rec['verdict']}", flush=True)


if __name__ == "__main__":
    main()
