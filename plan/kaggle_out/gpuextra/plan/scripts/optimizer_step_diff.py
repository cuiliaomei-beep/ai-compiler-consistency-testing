"""6.4: compiled optimizer.step() vs eager, over optimizers x flags x parameter dtypes / grad patterns.

For each configuration: two identical models, same grads (deterministic), N steps eager vs N steps with
`torch.compile(opt.step)`; compare parameters (max abs diff relative to param scale) and optimizer state
(step counts, exp_avg, ...). Flags: foreach / fused / capturable / maximize / weight_decay / amsgrad /
nesterov / differentiable; params: fp32, bf16, complex64 (where allowed), a param with grad None, sparse.

    python scripts/optimizer_step_diff.py [--steps 3] [--device cpu] [--only Adam,SGD] [--out results/optim]
"""
import argparse
import copy
import itertools
import json
import os
import sys
import time

sys.path.insert(0, os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
from tcc.compat import ensure_msvc_env  # noqa: E402

ensure_msvc_env()
import torch  # noqa: E402

OPTIMS = {
    "SGD": (torch.optim.SGD, dict(lr=0.1), [{"momentum": 0.9}, {"momentum": 0.9, "nesterov": True}, {"weight_decay": 0.1}, {"maximize": True}, {"momentum": 0.5, "dampening": 0.5}]),
    "Adam": (torch.optim.Adam, dict(lr=0.01), [{"amsgrad": True}, {"weight_decay": 0.1}, {"maximize": True}, {"capturable": True}, {"differentiable": True}]),
    "AdamW": (torch.optim.AdamW, dict(lr=0.01), [{"amsgrad": True}, {"weight_decay": 0.5}, {"capturable": True}]),
    "RMSprop": (torch.optim.RMSprop, dict(lr=0.01), [{"momentum": 0.9}, {"centered": True}, {"weight_decay": 0.1}, {"maximize": True}]),
    "Adagrad": (torch.optim.Adagrad, dict(lr=0.1), [{"lr_decay": 0.1}, {"weight_decay": 0.1}, {"maximize": True}]),
    "Adamax": (torch.optim.Adamax, dict(lr=0.01), [{"weight_decay": 0.1}, {"maximize": True}]),
    "NAdam": (torch.optim.NAdam, dict(lr=0.01), [{"momentum_decay": 0.01}, {"decoupled_weight_decay": True, "weight_decay": 0.1}]),
    "RAdam": (torch.optim.RAdam, dict(lr=0.01), [{"decoupled_weight_decay": True, "weight_decay": 0.1}]),
    "ASGD": (torch.optim.ASGD, dict(lr=0.01), [{"t0": 1}, {"weight_decay": 0.1}]),
    "Adadelta": (torch.optim.Adadelta, dict(lr=1.0), [{"rho": 0.5}, {"weight_decay": 0.1}]),
    "Rprop": (torch.optim.Rprop, dict(lr=0.01), [{"etas": (0.4, 1.3)}, {"maximize": True}]),
}
IMPLS = [{}, {"foreach": True}, {"foreach": False}, {"fused": True}]
PARAM_SETS = {
    "fp32": lambda g: [torch.randn(4, 3, generator=g), torch.randn(3, generator=g)],
    "bf16": lambda g: [torch.randn(4, 3, generator=g).bfloat16(), torch.randn(3, generator=g).bfloat16()],
    "fp64": lambda g: [torch.randn(4, 3, generator=g).double()],
    "complex64": lambda g: [torch.complex(torch.randn(3, 2, generator=g), torch.randn(3, 2, generator=g))],
    "mixed_and_nograd": lambda g: [torch.randn(2, 2, generator=g), torch.randn(3, generator=g).bfloat16(), torch.randn(2, generator=g)],
    "scalar_param": lambda g: [torch.randn((), generator=g)],
}


def make_params(name, g, device):
    ps = [torch.nn.Parameter(t.to(device)) for t in PARAM_SETS[name](g)]
    return ps


def set_grads(params, step, g, name):
    for i, p in enumerate(params):
        if name == "mixed_and_nograd" and i == 2:
            p.grad = None
            continue
        gr = torch.randn(p.shape, generator=g, dtype=torch.float32).to(p.dtype).to(p.device)
        if p.is_complex():
            gr = torch.complex(torch.randn(p.shape, generator=g), torch.randn(p.shape, generator=g)).to(p.dtype).to(p.device)
        p.grad = gr * (0.5 + step)


def run(opt_cls, base_kw, flag_kw, impl_kw, pname, steps, device, compiled, seed=0):
    g = torch.Generator().manual_seed(seed)
    params = make_params(pname, g, device)
    opt = opt_cls(params, **base_kw, **flag_kw, **impl_kw)
    step_fn = torch.compile(opt.step) if compiled else opt.step
    gg = torch.Generator().manual_seed(seed + 1)
    for s in range(steps):
        set_grads(params, s, gg, pname)
        step_fn()
    return [p.detach().clone() for p in params], opt.state_dict()


def state_sig(sd):
    out = {}
    for k, st in sd["state"].items():
        for name, v in st.items():
            out[f"{k}.{name}"] = v.detach().clone() if isinstance(v, torch.Tensor) else v
    return out


def cmp(a, b):
    if isinstance(a, torch.Tensor) and isinstance(b, torch.Tensor):
        if a.shape != b.shape or a.dtype != b.dtype:
            return f"meta {a.dtype}{tuple(a.shape)} vs {b.dtype}{tuple(b.shape)}"
        a64, b64 = a.detach().to(torch.complex128 if a.is_complex() else torch.float64), b.detach().to(torch.complex128 if b.is_complex() else torch.float64)
        if not torch.equal(torch.isfinite(a64), torch.isfinite(b64)):
            return "finite-pattern"
        d = (a64 - b64).abs().max().item() if a64.numel() else 0.0
        scale = max(a64.abs().max().item() if a64.numel() else 0.0, 1e-12)
        tol = {torch.bfloat16: 2e-2, torch.float16: 4e-3}.get(a.dtype, 1e-5)
        return f"{d / scale:.2e}" if d / scale > tol else None
    if a != b:
        return f"{a!r} vs {b!r}"
    return None


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--steps", type=int, default=3)
    ap.add_argument("--device", default="cpu")
    ap.add_argument("--only", default=None)
    ap.add_argument("--out", default=os.path.join(os.path.dirname(os.path.dirname(os.path.abspath(__file__))), "results", "optim"))
    a = ap.parse_args()
    os.makedirs(a.out, exist_ok=True)
    torch._dynamo.config.recompile_limit = 10 ** 5
    torch._dynamo.config.accumulated_recompile_limit = 10 ** 6
    print("torch", torch.__version__, "| device", a.device)
    rows, flagged, t0 = [], [], time.time()
    jl = open(os.path.join(a.out, "optim.jsonl"), "a", encoding="utf-8")
    for oname, (cls, base_kw, flag_list) in OPTIMS.items():
        if a.only and oname not in a.only.split(","):
            continue
        for flag_kw, impl_kw, pname in itertools.product([{}] + flag_list, IMPLS, PARAM_SETS):
            label = f"{oname} {flag_kw} {impl_kw} {pname}"
            rec = {"optim": oname, "flags": flag_kw, "impl": impl_kw, "params": pname}
            try:
                pe, se = run(cls, base_kw, flag_kw, impl_kw, pname, a.steps, a.device, compiled=False)
            except Exception as e:  # noqa: BLE001
                rec["eager_error"] = f"{type(e).__name__}: {str(e).splitlines()[0][:100]}"
                try:
                    torch._dynamo.reset()
                    run(cls, base_kw, flag_kw, impl_kw, pname, a.steps, a.device, compiled=True)
                    rec["compiled_error"] = None
                    rec["flag"] = "eager raises, compiled runs"
                    flagged.append(rec)
                    print(f"  FLAG {label}: eager {rec['eager_error']} | compiled OK")
                except Exception as e2:  # noqa: BLE001
                    rec["compiled_error"] = f"{type(e2).__name__}: {str(e2).splitlines()[0][:100]}"
                jl.write(json.dumps(rec) + "\n"); rows.append(rec)
                continue
            try:
                torch._dynamo.reset()
                pc, sc = run(cls, base_kw, flag_kw, impl_kw, pname, a.steps, a.device, compiled=True)
            except Exception as e:  # noqa: BLE001
                rec["compiled_error"] = f"{type(e).__name__}: {str(e).splitlines()[0][:120]}"
                rec["flag"] = "compiled raises, eager runs"
                flagged.append(rec)
                print(f"  FLAG {label}: compiled {rec['compiled_error']}")
                jl.write(json.dumps(rec) + "\n"); rows.append(rec)
                continue
            diffs = {}
            for i, (x, y) in enumerate(zip(pe, pc)):
                d = cmp(x, y)
                if d:
                    diffs[f"param{i}"] = d
            se_, sc_ = state_sig(se), state_sig(sc)
            for k in sorted(set(se_) | set(sc_)):
                if k not in se_ or k not in sc_:
                    diffs[k] = "missing on one side"
                    continue
                d = cmp(se_[k], sc_[k])
                if d:
                    diffs[k] = d
            rec["diffs"] = diffs
            if diffs:
                rec["flag"] = "param/state mismatch"
                flagged.append(rec)
                print(f"  FLAG {label}: {diffs}")
            jl.write(json.dumps(rec) + "\n"); rows.append(rec)
        print(f"[{oname}] done ({time.time() - t0:.0f}s, {len(flagged)} flagged so far)", flush=True)
    jl.close()
    lines = [f"# compiled optimizer.step differential (torch {torch.__version__}, {a.device}, steps={a.steps})", "",
             f"- configurations: {len(rows)}, flagged: {len(flagged)}", "", "| optim | flags | impl | params | finding |", "|---|---|---|---|---|"]
    for r in flagged:
        finding = r.get("diffs") or r.get("compiled_error") or r.get("eager_error")
        lines.append(f"| {r['optim']} | {r['flags']} | {r['impl']} | {r['params']} | {str(finding)[:160]} |")
    open(os.path.join(a.out, "OPTIM.md"), "w", encoding="utf-8").write("\n".join(lines) + "\n")
    print(json.dumps({"configs": len(rows), "flagged": len(flagged), "wall_s": round(time.time() - t0, 1)}))
    print("written", os.path.join(a.out, "OPTIM.md"))


if __name__ == "__main__":
    main()
