"""8.8  Compile composition laws: the same program run eager and under every composition of torch.compile that
should be semantically transparent -- compile(compile(f)), a compiled function calling another compiled function,
compile around torch._dynamo.disable / allow_in_graph / graph_break wrappers, compile(mod) vs mod.compile() vs
compile(mod.forward), the same function compiled twice with different backends / options, fullgraph on/off,
dynamic on/off, compile inside torch.no_grad / autocast / inference_mode, compile of a function with a compiled
closure, re-compile after torch._dynamo.reset.  Every observation (outputs, grads, in-place effects, exception
type) must equal eager's.
    python scripts/compile_composition_diff.py            -> results/compile_composition.jsonl
"""
import json
import math
import os
import sys
import tempfile
import traceback

os.environ.setdefault("TORCHINDUCTOR_CACHE_DIR", tempfile.mkdtemp(prefix="tcc_cc_"))
sys.path.insert(0, os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
from tcc.compat import ensure_msvc_env  # noqa: E402

ensure_msvc_env()
import torch  # noqa: E402
import torch.nn as nn  # noqa: E402
import torch.nn.functional as F  # noqa: E402

torch._dynamo.config.recompile_limit = 10 ** 4
torch.manual_seed(0)
PROGS = {}


def prog(fn):
    PROGS[fn.__name__] = fn
    return fn


# ----- programs: each returns (callable f, input builder, kind) ; kind 'fn' or 'mod' ---------------------------
class Mod(nn.Module):
    def __init__(self):
        super().__init__()
        self.lin = nn.Linear(8, 8)
        self.register_buffer("count", torch.zeros(()))
        self.ln = nn.LayerNorm(8)

    def forward(self, x):
        self.count += 1
        y = self.ln(F.gelu(self.lin(x)))
        if y.sum() > 1e9:
            return y * 0
        return y + self.count


@prog
def mlp_with_buffer_effect():
    return Mod(), lambda: torch.randn(4, 8), "mod"


class ModGB(nn.Module):
    def __init__(self):
        super().__init__()
        self.lin = nn.Linear(8, 8)
        self.log = []

    def forward(self, x):
        y = self.lin(x)
        self.log.append(int(y.shape[0]))
        torch._dynamo.graph_break()
        return torch.tanh(y) * len(self.log)


@prog
def module_with_graph_break_and_list():
    return ModGB(), lambda: torch.randn(3, 8), "mod"


@prog
def pure_math():
    def f(x):
        return torch.erf(x * 0.5).sum() + torch.special.i0e(x).mean() * torch.logsumexp(x, 0).sum()
    return f, lambda: torch.randn(64), "fn"


@prog
def inplace_on_input():
    def f(x):
        x.mul_(2).add_(1)
        return x.sum(), x.max()
    return f, lambda: torch.arange(12.0).reshape(3, 4), "fn"


@prog
def python_control_flow():
    def f(x, n):
        acc = torch.zeros_like(x)
        for i in range(n):
            if i % 2 == 0:
                acc = acc + x * i
            else:
                acc = acc - torch.sin(x) / (i + 1)
        return acc, n * 2
    return f, lambda: (torch.randn(5), 7), "fn"


@prog
def grad_through():
    def f(x):
        w = x * 3
        y = (w.sigmoid() * torch.arange(8.0)).sum()
        (g,) = torch.autograd.grad(y, x, create_graph=True)
        return g, (g * g).sum()
    return f, lambda: torch.randn(8, requires_grad=True), "fn"


@prog
def dtype_promotion_chain():
    def f(a, b, c):
        return (a + b) * c, (a.int() // 3).float() + b.double(), torch.where(c > 0, a, b.half()).float()
    return f, lambda: (torch.arange(6, dtype=torch.int64), torch.randn(6, dtype=torch.float32), torch.randn(6, dtype=torch.float64)), "fn"


@prog
def views_and_strides():
    def f(x):
        v = x.t()[1::2, :3]
        v.add_(1)
        return x.clone(), v.contiguous().sum(), x.as_strided((2, 2), (1, 3)).sum()
    return f, lambda: torch.arange(24.0).reshape(4, 6), "fn"


@prog
def closure_state_counter():
    state = {"n": 0}

    def f(x):
        state["n"] += 1
        return x * state["n"], state["n"]
    return f, lambda: torch.ones(4), "fn"


@prog
def dynamic_shapes_sequence():
    def f(x):
        return x.sum(0), x.shape[0] * 2, x[: x.shape[0] // 2].mean()
    return f, lambda: torch.randn(torch.randint(2, 20, ()).item(), 3), "fn"


@prog
def exception_after_effect():
    def f(x):
        x.add_(1)
        if x.sum() > 0:
            raise ValueError("positive")
        return x
    return f, lambda: torch.ones(3), "fn"


@prog
def complex_and_conj():
    def f(z):
        h = z.mH
        return (h @ z).real.sum(), torch.linalg.norm(z.conj() * z), z.abs().max()
    return f, lambda: torch.randn(4, 4, dtype=torch.complex64), "fn"


@prog
def reductions_int():
    def f(x):
        return x.prod(), x.cumsum(0)[-1], x.sum(dtype=torch.int32), (x // 3).float().var()
    return f, lambda: torch.arange(-20, 21, dtype=torch.int64), "fn"


@prog
def nested_module_in_fn():
    m = nn.Sequential(nn.Linear(4, 4), nn.ReLU(), nn.Dropout(0.0), nn.Linear(4, 2))

    def f(x):
        y = m(x)
        return y.softmax(-1), y.abs().sum()
    return f, lambda: torch.randn(3, 4), "fn"


# ----- composition modes: name -> (wrap(f) for fn kind, wrap(mod) for mod kind) ------------------------------
def c(f, **kw):
    return torch.compile(f, **kw)


def calls_other_compiled(f):
    g = torch.compile(f)

    def outer(*a):
        return g(*a)
    return torch.compile(outer)


def disable_wrapped(f):
    inner = torch._dynamo.disable(f)

    def outer(*a):
        return inner(*a)
    return torch.compile(outer)


def allow_in_graph_wrapped(f):
    inner = torch._dynamo.allow_in_graph(f)

    def outer(*a):
        return inner(*a)
    return torch.compile(outer)


def graph_break_around(f):
    def outer(*a):
        torch._dynamo.graph_break()
        r = f(*a)
        torch._dynamo.graph_break()
        return r
    return torch.compile(outer)


import contextlib


def clones(args):
    return [x.detach().clone().requires_grad_(x.requires_grad) if isinstance(x, torch.Tensor) else x for x in args]


# pre-run sequences: list of (context factory, backend-or-None); each pre-run happens on cloned inputs and its
# exception (if any) is swallowed; the eager reference replays the SAME sequence on a fresh eager instance, so
# programs with state (closure counters, module buffers, mutated inputs) stay comparable.
PRE = {
    "inductor_after_aot_eager": [(contextlib.nullcontext, "aot_eager")],
    "inductor_after_eager_backend": [(contextlib.nullcontext, "eager")],
    "no_grad_first": [(torch.no_grad, None)],
    "inference_mode_first": [(torch.inference_mode, None)],
    "autocast_first": [(lambda: torch.autocast("cpu", dtype=torch.bfloat16), None)],
    "reset_between": [(contextlib.nullcontext, None)],
    "warm_twice_then_dynamic": [(contextlib.nullcontext, None), (contextlib.nullcontext, None)],
}


def with_pre(mname, f, wrap_main):
    """Returns g(*args): runs the pre-run sequence (each with its own compiled copy) then the main compiled f."""
    seq = PRE.get(mname, [])
    main = wrap_main(f)

    def outer(*args):
        for ctx, backend in seq:
            h = torch.compile(f, backend=backend) if backend else torch.compile(f)
            with ctx():
                try:
                    h(*clones(args))
                except Exception:  # noqa: BLE001
                    pass
            if mname == "reset_between":
                torch._dynamo.reset()
        return main(*args)
    return outer


def eager_with_pre(mname, f):
    seq = PRE.get(mname, [])

    def outer(*args):
        for ctx, _ in seq:
            with ctx():
                try:
                    f(*clones(args))
                except Exception:  # noqa: BLE001
                    pass
        return f(*args)
    return outer


MODES_FN = {
    "compile": lambda f: c(f), "compile_compile": lambda f: c(c(f)), "compile_fullgraph_in_compile": lambda f: c(c(f, fullgraph=True)),
    "calls_other_compiled": calls_other_compiled, "disable_wrapped": disable_wrapped, "allow_in_graph_wrapped": allow_in_graph_wrapped,
    "graph_break_around": graph_break_around, "dynamic_true": lambda f: c(f, dynamic=True), "dynamic_false": lambda f: c(f, dynamic=False),
    "inductor_after_aot_eager": lambda f: c(f), "inductor_after_eager_backend": lambda f: c(f), "reset_between": lambda f: c(f),
    "no_grad_first": lambda f: c(f), "inference_mode_first": lambda f: c(f), "autocast_first": lambda f: c(f),
    "warm_twice_then_dynamic": lambda f: c(f, dynamic=True),
    "mode_reduce_overhead": lambda f: c(f, mode="reduce-overhead"), "mode_max_autotune_no_cudagraphs": lambda f: c(f, mode="max-autotune-no-cudagraphs"),
}
MODES_MOD = {
    "compile_mod": lambda m: torch.compile(m), "mod_dot_compile": lambda m: (m.compile(), m)[1], "compile_forward": lambda m: (setattr(m, "forward", torch.compile(m.forward)), m)[1],
    "compile_compile_mod": lambda m: torch.compile(torch.compile(m)), "compile_mod_fullgraph": lambda m: torch.compile(m, fullgraph=True),
    "compile_mod_dynamic": lambda m: torch.compile(m, dynamic=True), "compile_mod_in_fn": lambda m: torch.compile(lambda x: m(x)),
    "compile_mod_in_compiled_fn": lambda m: (lambda cm: torch.compile(lambda x: cm(x)))(torch.compile(m)),
}


def observe(f, args):
    try:
        r = f(*args)
        return ("ok", r)
    except Exception as ex:  # noqa: BLE001
        return ("exc", type(ex).__name__)


def flat(o):
    if isinstance(o, torch.Tensor):
        return [o]
    if isinstance(o, (list, tuple)):
        return [t for x in o for t in flat(x)]
    return []


def same(a, b, tol=1e-4):
    if a[0] != b[0]:
        return False, f"{a[0]} vs {b[0]}"
    if a[0] == "exc":
        return a[1] == b[1], f"{a[1]} vs {b[1]}"
    ta, tb = flat(a[1]), flat(b[1])
    if len(ta) != len(tb):
        return False, "tensor count"
    for x, y in zip(ta, tb):
        if x.dtype != y.dtype or x.shape != y.shape:
            return False, f"dtype/shape {x.dtype}{tuple(x.shape)} vs {y.dtype}{tuple(y.shape)}"
        if x.is_complex() or x.is_floating_point():
            xx, yy = x.detach().double(), y.detach().double()
            if not (torch.isnan(xx) == torch.isnan(yy)).all():
                return False, "nan pattern"
            d = (xx - yy).abs().nan_to_num(0) / (xx.abs().nan_to_num(0) + 1)
            if d.max() > tol:
                return False, f"max rel diff {d.max().item():.3g}"
        elif not torch.equal(x.detach(), y.detach()):
            return False, "int/bool mismatch"
    na = [x for x in a[1]] if isinstance(a[1], (list, tuple)) else [a[1]]
    nb = [x for x in b[1]] if isinstance(b[1], (list, tuple)) else [b[1]]
    for x, y in zip(na, nb):
        if not isinstance(x, torch.Tensor) and x != y:
            return False, f"python value {x!r} vs {y!r}"
    return True, ""


def run():
    out = open("results/compile_composition.jsonl", "w", encoding="utf-8")
    n_bad = 0
    for pname, build in PROGS.items():
        torch.manual_seed(0)
        f0, mk, kind = build()
        modes = MODES_MOD if kind == "mod" else MODES_FN
        # eager reference: fresh program instance + same inputs (seeded)
        for mname, wrap in modes.items():
            # eager reference for THIS mode (same pre-run sequence, fresh instance, same seeded inputs)
            torch.manual_seed(0); fr, _, _ = build(); torch.manual_seed(1); args = mk(); args = args if isinstance(args, tuple) else (args,)
            ref = observe(eager_with_pre(mname, fr) if kind == "fn" else fr, [a.clone() if isinstance(a, torch.Tensor) else a for a in args])
            torch._dynamo.reset(); torch.manual_seed(0)
            f1, _, _ = build()  # fresh instance so buffers / closure state start equal
            try:
                g = with_pre(mname, f1, wrap) if kind == "fn" else wrap(f1)
            except Exception as ex:  # noqa: BLE001
                out.write(json.dumps({"prog": pname, "mode": mname, "verdict": "WRAP_ERROR", "err": type(ex).__name__}) + "\n"); continue
            torch.manual_seed(1); a2 = mk(); a2 = a2 if isinstance(a2, tuple) else (a2,)
            a2c = [x.clone() if isinstance(x, torch.Tensor) else x for x in a2]
            try:
                got = observe(g, a2c)
            except BaseException as ex:  # noqa: BLE001
                got = ("crash", type(ex).__name__)
            ok, why = same(ref, got)
            # compare effects: rerun eager on a copy to get post-state
            torch.manual_seed(1); a3 = mk(); a3 = a3 if isinstance(a3, tuple) else (a3,)
            a3c = [x.clone() if isinstance(x, torch.Tensor) else x for x in a3]
            torch.manual_seed(0); f2, _, _ = build(); observe(eager_with_pre(mname, f2) if kind == "fn" else f2, a3c)
            for x, y in zip(a2c, a3c):
                if isinstance(x, torch.Tensor) and not torch.allclose(x.detach().double(), y.detach().double(), rtol=1e-4, atol=1e-6, equal_nan=True):
                    ok, why = False, why or "input mutation differs"
            # mod kind: buffers / python state on the module
            if kind == "mod":
                m_ref, _, _ = build(); torch.manual_seed(1); a4 = mk(); observe(m_ref, [a4.clone()])
                m_got = f1
                for (n1, b1), (n2, b2) in zip(m_ref.named_buffers(), m_got.named_buffers()):
                    if not torch.allclose(b1.double(), b2.double()):
                        ok, why = False, why or f"buffer {n1} {b1.item() if b1.numel() == 1 else ''} vs {b2.item() if b2.numel() == 1 else ''}"
                if hasattr(m_ref, "log") and m_ref.log != m_got.log:
                    ok, why = False, why or f"python list {m_ref.log} vs {m_got.log}"
            rec = {"prog": pname, "mode": mname, "verdict": "OK" if ok else "DIFF", "why": why, "ref": ref[0] if ref[0] == "ok" else ref[1], "got": got[0] if got[0] == "ok" else got[1]}
            out.write(json.dumps(rec) + "\n"); out.flush()
            if not ok:
                n_bad += 1
                print(f"!! {pname:32s} {mname:34s} {why}  (eager {rec['ref']}, got {rec['got']})", flush=True)
    print(f"DONE: {n_bad} differences", flush=True)


if __name__ == "__main__":
    run()
