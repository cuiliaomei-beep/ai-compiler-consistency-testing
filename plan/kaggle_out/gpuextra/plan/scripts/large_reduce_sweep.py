"""6.3 large-reduction accumulation sweep (item 05 family): eager vs torch.compile vs float64 truth.

Inductor accumulates fp32 reductions in fp32 (and bf16/fp16 in fp32), CPU eager often accumulates in double
or with pairwise summation. On long reduction axes / ill-conditioned values the compiled result can be
far worse than eager's. Flag = compiled error > max(4 x eager error, atol) against the fp64 truth.

    python scripts/large_reduce_sweep.py [--n 100003] [--device cpu] [--only sum,mean] [--out results/large_reduce]
"""
import argparse
import json
import os
import sys
import time

sys.path.insert(0, os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
from tcc.compat import ensure_msvc_env  # noqa: E402

ensure_msvc_env()
import torch  # noqa: E402
import torch.nn.functional as F  # noqa: E402

OPS = {
    "sum": lambda x: x.sum(-1),
    "mean": lambda x: x.mean(-1),
    "nansum": lambda x: torch.nansum(x, -1),
    "nanmean": lambda x: torch.nanmean(x, -1),
    "prod_small": lambda x: (1 + x * 1e-6).prod(-1),
    "var": lambda x: x.var(-1),
    "std": lambda x: x.std(-1),
    "var_mean": lambda x: torch.var_mean(x, -1)[0],
    "std_unbiased0": lambda x: x.std(-1, correction=0),
    "norm2": lambda x: x.norm(dim=-1),
    "norm1": lambda x: x.norm(p=1, dim=-1),
    "vector_norm_inf": lambda x: torch.linalg.vector_norm(x, ord=float("inf"), dim=-1),
    "logsumexp": lambda x: torch.logsumexp(x, -1),
    "softmax_sum": lambda x: torch.softmax(x, -1).sum(-1),
    "log_softmax_max": lambda x: torch.log_softmax(x, -1).amax(-1),
    "cumsum_last": lambda x: torch.cumsum(x, -1)[..., -1],
    "cumprod_last": lambda x: torch.cumprod(1 + x * 1e-6, -1)[..., -1],
    "dist": lambda x: torch.dist(x, x.flip(-1)),
    "layer_norm": lambda x: F.layer_norm(x, x.shape[-1:]).abs().amax(-1),
    "rms_norm": lambda x: F.rms_norm(x, x.shape[-1:]).abs().amax(-1),
    "group_norm": lambda x: F.group_norm(x.reshape(1, x.shape[0], -1), 1).abs().amax(-1),
    "batch_norm": lambda x: F.batch_norm(x.mT.contiguous(), None, None, training=True).abs().amax(0),
    "mse_loss": lambda x: F.mse_loss(x, x.flip(-1)),
    "l1_loss": lambda x: F.l1_loss(x, x.flip(-1)),
    "cross_entropy_wide": lambda x: F.cross_entropy(x, torch.zeros(x.shape[0], dtype=torch.long, device=x.device)),
    "cosine_similarity": lambda x: F.cosine_similarity(x, x.flip(-1) + 1e-3, dim=-1),
    "matmul_dot": lambda x: (x @ x.mT).diagonal(),
    "einsum_ij_ij": lambda x: torch.einsum("ij,ij->i", x, x.flip(-1)),
    "amax_minus_amin": lambda x: x.amax(-1) - x.amin(-1),
    "kthvalue_mid": lambda x: x.kthvalue(x.shape[-1] // 2, -1)[0],
    "median": lambda x: x.median(-1)[0],
}

VALUES = {
    "randn": lambda g, shape: torch.randn(shape, generator=g),
    "offset1e3": lambda g, shape: torch.randn(shape, generator=g) + 1e3,          # cancellation
    "offset1e5": lambda g, shape: torch.randn(shape, generator=g) + 1e5,
    "scale1e18": lambda g, shape: torch.randn(shape, generator=g) * 1e18,          # squares overflow fp32
    "scale1e-20": lambda g, shape: torch.randn(shape, generator=g) * 1e-20,        # squares underflow fp32
    "scale1e-30": lambda g, shape: torch.randn(shape, generator=g) * 1e-30,        # squares flush to 0 in fp32 (item 05)
    "scale1e30": lambda g, shape: torch.randn(shape, generator=g) * 1e30,            # squares overflow to inf in fp32
    "alternating": lambda g, shape: torch.ones(shape) * torch.tensor([1.0, -1.0]).repeat(shape[-1] // 2 + 1)[: shape[-1]] + 1e-7,
    "tiny_spread": lambda g, shape: 1.0 + torch.randn(shape, generator=g) * 1e-4,  # var of nearly-equal values
}


def err(a, truth):
    a = a.double()
    d = (a - truth).abs()
    finite = torch.isfinite(truth)
    if not finite.all():
        # NaN/Inf pattern must match; where truth is finite compare values
        if not torch.equal(torch.isnan(a), torch.isnan(truth)) or not torch.equal(torch.isinf(a), torch.isinf(truth)):
            return float("inf")
        d = d[finite]
    if d.numel() == 0:
        return 0.0
    scale = truth[finite].abs().amax().item() if finite.any() else 1.0
    return (d.amax().item() / max(scale, 1e-30))


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--n", type=int, default=100_003)
    ap.add_argument("--rows", type=int, default=4)
    ap.add_argument("--device", default="cpu")
    ap.add_argument("--dtypes", default="float32,bfloat16,float16")
    ap.add_argument("--only", default=None)
    ap.add_argument("--values", default=None)
    ap.add_argument("--out", default=os.path.join(os.path.dirname(os.path.dirname(os.path.abspath(__file__))), "results", "large_reduce"))
    a = ap.parse_args()
    os.makedirs(a.out, exist_ok=True)
    torch._dynamo.config.recompile_limit = 10 ** 6
    torch._dynamo.config.accumulated_recompile_limit = 10 ** 6
    dts = [getattr(torch, d) for d in a.dtypes.split(",")]
    ops = {k: v for k, v in OPS.items() if not a.only or k in a.only.split(",")}
    vals = {k: v for k, v in VALUES.items() if not a.values or k in a.values.split(",")}
    print(f"torch {torch.__version__} | device {a.device} | n={a.n} rows={a.rows} | {len(ops)} ops x {len(vals)} value sets x {len(dts)} dtypes")
    g = torch.Generator().manual_seed(0)
    flagged, rows, t0 = [], [], time.time()
    jsonl = open(os.path.join(a.out, "large_reduce.jsonl"), "a", encoding="utf-8")
    for name, fn in ops.items():
        torch._dynamo.reset()
        cfn = torch.compile(fn, dynamic=False)
        for vname, mk in vals.items():
            base = mk(g, (a.rows, a.n))
            for dt in dts:
                x = base.to(dt).to(a.device)
                try:
                    with torch.no_grad():
                        truth = fn(base.double().to(a.device))
                        re = fn(x)
                        rc = cfn(x)
                    if a.device != "cpu":
                        torch.cuda.synchronize()
                except Exception as e:  # noqa: BLE001
                    rec = {"op": name, "values": vname, "dtype": str(dt).split(".")[-1], "error": f"{type(e).__name__}: {str(e)[:100]}"}
                    jsonl.write(json.dumps(rec) + "\n")
                    print(f"  ERR  {name:<20} {vname:<12} {rec['dtype']:<9} {rec['error']}")
                    continue
                ee, ec = err(re, truth.double()), err(rc, truth.double())
                # tolerance: what the dtype can represent at all
                atol = {torch.float32: 1e-5, torch.bfloat16: 1e-2, torch.float16: 2e-3, torch.float64: 1e-12}.get(dt, 1e-5)
                bad = ec > max(4 * ee, atol) and not (ec == float("inf") and ee == float("inf"))
                rec = {"op": name, "values": vname, "dtype": str(dt).split(".")[-1], "eager_err": ee, "compiled_err": ec, "flag": bad,
                       "eager_sample": re.flatten()[:2].tolist(), "compiled_sample": rc.flatten()[:2].tolist(), "truth_sample": truth.flatten()[:2].tolist()}
                jsonl.write(json.dumps(rec) + "\n")
                rows.append(rec)
                if bad:
                    flagged.append(rec)
                    print(f"  FLAG {name:<20} {vname:<12} {rec['dtype']:<9} eager_err={ee:.2e} compiled_err={ec:.2e}  eager={rec['eager_sample'][0]!r} compiled={rec['compiled_sample'][0]!r} truth={rec['truth_sample'][0]!r}")
        print(f"[{name}] done ({time.time() - t0:.0f}s, {len(flagged)} flagged)", flush=True)
    jsonl.close()
    lines = [f"# large-reduction accumulation sweep (torch {torch.__version__}, {a.device}, n={a.n}, rows={a.rows})", "",
             f"- cases: {len(rows)}, flagged: {len(flagged)} (compiled error > 4x eager error against float64 truth)", "",
             "| op | values | dtype | eager rel-err | compiled rel-err | eager[0] | compiled[0] | truth[0] |", "|---|---|---|---|---|---|---|---|"]
    for r in flagged:
        lines.append(f"| {r['op']} | {r['values']} | {r['dtype']} | {r['eager_err']:.2e} | {r['compiled_err']:.2e} | {r['eager_sample'][0]!r} | {r['compiled_sample'][0]!r} | {r['truth_sample'][0]!r} |")
    open(os.path.join(a.out, "LARGE_REDUCE.md"), "w", encoding="utf-8").write("\n".join(lines) + "\n")
    print(json.dumps({"cases": len(rows), "flagged": len(flagged), "wall_s": round(time.time() - t0, 1)}))
    print("written", os.path.join(a.out, "LARGE_REDUCE.md"))


if __name__ == "__main__":
    main()
