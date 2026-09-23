"""6.5: reuse of a compiled function under (a) 0/1 specialisation and (b) runtime environment changes.

(a) compile with batch 3 (static and dynamic=True), then call with batch 0, 1, 2 -> compare with eager.
(b) compile once, then flip an environment flag and call again: autocast, set_grad_enabled / no_grad,
    default dtype, deterministic algorithms, flush_denormal, num_threads, mkldnn enabled, requires_grad of
    the input, a global python constant read by the function, module.training / eval, a buffer mutated
    outside, inference_mode -> the compiled result must equal eager under the NEW environment.

    python scripts/reuse_env_diff.py [--device cpu] [--only names] [--out results/reuse_env]
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

torch._dynamo.config.recompile_limit = 10 ** 4
torch._dynamo.config.accumulated_recompile_limit = 10 ** 6

GLOBAL_SCALE = 1.0


def _sig(v):
    if isinstance(v, Exception):
        return f"raise:{type(v).__name__}"
    if isinstance(v, torch.Tensor):
        return ("T", str(v.dtype), tuple(v.shape), v.requires_grad, v.detach().to(torch.float64 if v.is_floating_point() else v.dtype).reshape(-1).tolist()[:32])
    if isinstance(v, (tuple, list)):
        return tuple(_sig(x) for x in v)
    return v


def _eq(a, b, tol=1e-6):
    if type(a) != type(b):
        return False
    if isinstance(a, tuple) and len(a) == 5 and a[0] == "T":
        if a[1:4] != b[1:4]:
            return False
        return all((x != x and y != y) or (abs(x - y) <= tol * max(1.0, abs(x), abs(y))) if isinstance(x, float) else x == y for x, y in zip(a[4], b[4]))
    if isinstance(a, tuple):
        return len(a) == len(b) and all(_eq(x, y, tol) for x, y in zip(a, b))
    return a == b


def _call(fn, *args):
    try:
        return _sig(fn(*args))
    except Exception as e:  # noqa: BLE001
        return _sig(e)


# ---------------------------------------------------------------- programs for 0/1 specialisation
PROGS_01 = {
    "mean_over_batch": lambda x: x.mean(0),
    "softmax_batch": lambda x: torch.softmax(x, 0),
    "batch_norm_train": lambda x: F.batch_norm(x, None, None, training=True),
    "layer_norm": lambda x: F.layer_norm(x, x.shape[1:]),
    "reshape_minus1": lambda x: x.reshape(-1, 2).sum(0),
    "expand_from_batch": lambda x: x[:1].expand(x.shape[0], -1) + x,
    "index_last": lambda x: x[-1] if x.shape[0] else x.sum(0),
    "cat_with_self": lambda x: torch.cat([x, x[:1]], 0),
    "var_unbiased": lambda x: x.var(0),
    "max_over_batch": lambda x: x.max(0)[0] if x.shape[0] else x.sum(0),
    "bmm_batch": lambda x: torch.bmm(x.unsqueeze(-1), x.unsqueeze(1)),
    "std_mean": lambda x: torch.std_mean(x, 0),
    "cumsum_batch": lambda x: torch.cumsum(x, 0),
    "repeat_interleave_shape": lambda x: x.repeat_interleave(2, 0),
    "nonzero_count": lambda x: (x > 0).sum().item() if x.numel() else 0,
    "squeeze_batch": lambda x: x.squeeze(0).shape,
    "linear": lambda x: F.linear(x, torch.ones(2, 4)),
    "conv1d": lambda x: F.conv1d(x.unsqueeze(1), torch.ones(1, 1, 3)),
    "embedding_bag": lambda x: F.embedding_bag(torch.arange(x.shape[0]) % 3, torch.ones(3, 4), offsets=torch.tensor([0]) if x.shape[0] else torch.tensor([0]), mode="sum"),
    "pad_batch": lambda x: F.pad(x, (0, 0, 1, 1)),
}


def zero_one(a, out_rows, flagged):
    g = torch.Generator().manual_seed(0)
    for name, fn in PROGS_01.items():
        for dyn in (False, True, None):
            torch._dynamo.reset()
            cf = torch.compile(fn, dynamic=dyn)
            x3 = torch.randn(3, 4, generator=g).to(a.device)
            _call(cf, x3)                                     # compile on batch 3
            for n in (0, 1, 2, 5):
                x = torch.randn(n, 4, generator=g).to(a.device)
                e, c = _call(fn, x), _call(cf, x)
                rec = {"angle": "0/1", "prog": name, "dynamic": dyn, "batch": n, "eager": str(e)[:160], "compiled": str(c)[:160]}
                ok = _eq(e, c)
                rec["flag"] = not ok
                out_rows.append(rec)
                if not ok:
                    flagged.append(rec)
                    print(f"  FLAG 0/1 {name:<24} dynamic={dyn!s:<5} batch={n}: eager={str(e)[:70]} compiled={str(c)[:70]}")
    print(f"[0/1] done ({len(flagged)} flagged so far)", flush=True)


# ---------------------------------------------------------------- environment flips
class M(torch.nn.Module):
    def __init__(self):
        super().__init__()
        self.lin = torch.nn.Linear(4, 4)
        self.bn = torch.nn.BatchNorm1d(4)
        self.drop = torch.nn.Dropout(0.5)
        self.register_buffer("scale", torch.ones(4))

    def forward(self, x):
        return self.drop(self.bn(self.lin(x))) * self.scale * GLOBAL_SCALE


def env_cases(device):
    """name -> (fn, make_input, setup_before_second_call, teardown)."""
    torch.manual_seed(0)
    m = M().to(device).eval()
    g = torch.Generator().manual_seed(1)
    mk = lambda: torch.randn(3, 4, generator=g).to(device)

    def with_grad_out(x):
        y = m(x)
        return y, y.requires_grad, torch.is_grad_enabled()

    def mixed(x):
        return F.linear(x, torch.ones(4, 4, device=x.device)) + x.sum() + torch.tensor(1.5, device=x.device)

    def reduce(x):
        return x.sum(), x.mean(), torch.mm(x, x.T)

    def denorm(x):
        return x * 1e-40 * 1e-40 / 1e-40

    cases = {}

    def add(name, fn, setup, teardown=lambda: None, inp=mk):
        cases[name] = (fn, inp, setup, teardown)

    add("autocast_bf16", mixed, lambda: torch.autocast("cpu", dtype=torch.bfloat16).__enter__(), lambda: torch.set_autocast_enabled("cpu", False))
    add("no_grad", with_grad_out, lambda: torch.set_grad_enabled(False), lambda: torch.set_grad_enabled(True))
    add("input_requires_grad", with_grad_out, lambda: None, inp=lambda: mk().requires_grad_())
    add("default_dtype_float64", lambda x: x.sum() + torch.tensor(1.5) + torch.zeros(2).dtype.itemsize, lambda: torch.set_default_dtype(torch.float64), lambda: torch.set_default_dtype(torch.float32))
    add("deterministic", lambda x: torch.zeros(3, 4).index_add(0, torch.tensor([0, 0, 1]), x), lambda: torch.use_deterministic_algorithms(True), lambda: torch.use_deterministic_algorithms(False))
    add("flush_denormal", denorm, lambda: torch.set_flush_denormal(True), lambda: torch.set_flush_denormal(False))
    add("num_threads_1", reduce, lambda: torch.set_num_threads(1), lambda: torch.set_num_threads(max(1, os.cpu_count() // 2)))
    add("mkldnn_off", lambda x: F.linear(x, torch.ones(4, 4)), lambda: setattr(torch.backends.mkldnn, "enabled", False), lambda: setattr(torch.backends.mkldnn, "enabled", True))
    add("global_python_constant", m, lambda: globals().__setitem__("GLOBAL_SCALE", 3.0), lambda: globals().__setitem__("GLOBAL_SCALE", 1.0))
    add("module_train_mode", m, lambda: (torch.manual_seed(5), m.train()), lambda: m.eval())
    add("buffer_mutated_outside", m, lambda: m.scale.fill_(2.0), lambda: m.scale.fill_(1.0))
    add("param_mutated_outside", m, lambda: m.lin.weight.data.mul_(0.5), lambda: m.lin.weight.data.mul_(2.0))
    add("inference_mode", with_grad_out, lambda: torch.inference_mode().__enter__(), lambda: torch.inference_mode(False).__enter__())
    add("grad_mode_via_ctx_no_grad_fn", lambda x: (x * 2).requires_grad, lambda: torch.set_grad_enabled(False), lambda: torch.set_grad_enabled(True), inp=lambda: mk().requires_grad_())
    add("manual_seed_before_call", lambda x: x + torch.rand(4), lambda: torch.manual_seed(123))
    add("cudnn_flags_irrelevant_cpu", reduce, lambda: setattr(torch.backends.cudnn, "deterministic", True), lambda: setattr(torch.backends.cudnn, "deterministic", False))
    add("float32_matmul_precision", reduce, lambda: torch.set_float32_matmul_precision("medium"), lambda: torch.set_float32_matmul_precision("highest"))
    add("input_becomes_noncontig", lambda x: x.sum(1) + x[:, 0], lambda: None, inp=lambda: mk().T.contiguous().T)
    add("input_dtype_switch", lambda x: x.sum(1), lambda: None, inp=lambda: mk().double())
    add("input_channels_last_4d", lambda x: F.conv2d(x, torch.ones(1, 1, 1, 1)).sum(), lambda: None, inp=lambda: torch.randn(2, 1, 3, 3, generator=g).contiguous(memory_format=torch.channels_last))
    return cases


def env_flips(a, out_rows, flagged):
    cases = env_cases(a.device)
    for name, (fn, mk, setup, teardown) in cases.items():
        if a.only and name not in a.only.split(","):
            continue
        torch._dynamo.reset()
        cf = torch.compile(fn)
        x0 = mk()
        try:
            e0, c0 = _call(fn, x0), _call(cf, x0)                # baseline environment
            setup()
            x1 = mk()
            e1, c1 = _call(fn, x1), _call(cf, x1)                # flipped environment
        finally:
            try:
                teardown()
            except Exception:  # noqa: BLE001
                pass
        rec = {"angle": "env", "case": name, "baseline_eq": _eq(e0, c0), "flipped_eq": _eq(e1, c1),
               "eager_flipped": str(e1)[:160], "compiled_flipped": str(c1)[:160], "eager_base": str(e0)[:100], "compiled_base": str(c0)[:100]}
        rec["flag"] = not rec["flipped_eq"] and rec["baseline_eq"]
        out_rows.append(rec)
        if rec["flag"]:
            flagged.append(rec)
            print(f"  FLAG env {name:<28}: after flip eager={str(e1)[:80]} compiled={str(c1)[:80]}")
        elif not rec["baseline_eq"]:
            print(f"  (baseline already differs) {name}: eager={str(e0)[:60]} compiled={str(c0)[:60]}")
    print(f"[env] done ({len(flagged)} flagged total)", flush=True)


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--device", default="cpu")
    ap.add_argument("--only", default=None)
    ap.add_argument("--skip", default="", help="comma list of angles to skip: 01,env")
    ap.add_argument("--out", default=os.path.join(os.path.dirname(os.path.dirname(os.path.abspath(__file__))), "results", "reuse_env"))
    a = ap.parse_args()
    os.makedirs(a.out, exist_ok=True)
    print("torch", torch.__version__, "| device", a.device)
    rows, flagged, t0 = [], [], time.time()
    if "01" not in a.skip:
        zero_one(a, rows, flagged)
    if "env" not in a.skip:
        env_flips(a, rows, flagged)
    with open(os.path.join(a.out, "reuse_env.jsonl"), "w", encoding="utf-8") as fh:
        for r in rows:
            fh.write(json.dumps(r) + "\n")
    lines = [f"# reuse under 0/1 specialisation and environment flips (torch {torch.__version__}, {a.device})", "",
             f"- checks: {len(rows)}, flagged: {len(flagged)}; wall {time.time() - t0:.0f} s", "", "| angle | case | detail |", "|---|---|---|"]
    for r in flagged:
        if r["angle"] == "0/1":
            lines.append(f"| 0/1 | {r['prog']} dynamic={r['dynamic']} batch={r['batch']} | eager `{r['eager'][:90]}` vs compiled `{r['compiled'][:90]}` |")
        else:
            lines.append(f"| env | {r['case']} | eager `{r['eager_flipped'][:90]}` vs compiled `{r['compiled_flipped'][:90]}` |")
    open(os.path.join(a.out, "REUSE_ENV.md"), "w", encoding="utf-8").write("\n".join(lines) + "\n")
    print(json.dumps({"checks": len(rows), "flagged": len(flagged), "wall_s": round(time.time() - t0, 1)}))
    print("written", os.path.join(a.out, "REUSE_ENV.md"))


if __name__ == "__main__":
    main()
