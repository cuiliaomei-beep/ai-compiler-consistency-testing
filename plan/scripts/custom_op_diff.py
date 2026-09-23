"""7.4  Custom operators and autograd.Function under torch.compile: eager vs backend eager / aot_eager / inductor.
Covers torch.library.custom_op (with and without register_fake / register_autograd, mutating ops, ops returning views
or aliases, ops on complex input using .mH internally -- the #198118 mechanism, since the compiled runtime runs custom
ops under _AnalyzeCustomOpInputOutputMode), torch.autograd.Function (custom backward, ctx.mark_dirty, save_for_backward
of views, once_differentiable, needs_input_grad), and their combinations with in-place updates and dtype changes.
    python scripts/custom_op_diff.py [--backends eager,aot_eager,inductor]
"""
import argparse
import json
import os
import sys
import tempfile

os.environ.setdefault("TORCHINDUCTOR_CACHE_DIR", tempfile.mkdtemp(prefix="tcc_co_"))
sys.path.insert(0, os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
from tcc.compat import ensure_msvc_env  # noqa: E402

ensure_msvc_env()
import torch  # noqa: E402

torch._dynamo.config.capture_scalar_outputs = True
INF, NAN = float("inf"), float("nan")
X = torch.tensor([1.5, -2.0, 0.0, -0.0, INF, -INF, NAN, 3.0])
C = torch.tensor([[1 + 2j, 2 - 1j, 0.5j], [3.0 + 0j, -1 + 1j, 2 + 2j]], dtype=torch.complex64)

# ---------- custom ops
@torch.library.custom_op("tcc::twice", mutates_args=())
def twice(x: torch.Tensor) -> torch.Tensor:
    return x * 2


@twice.register_fake
def _(x):
    return torch.empty_like(x)


@torch.library.custom_op("tcc::twice_nofake", mutates_args=())
def twice_nofake(x: torch.Tensor) -> torch.Tensor:
    return x * 2


@torch.library.custom_op("tcc::promote", mutates_args=())
def promote(x: torch.Tensor) -> torch.Tensor:          # returns a different dtype than the fake says
    return (x * 2).double()


@promote.register_fake
def _(x):
    return torch.empty_like(x)                          # wrong: says float32


@torch.library.custom_op("tcc::add_inplace", mutates_args={"x"})
def add_inplace(x: torch.Tensor, v: float) -> None:
    x.add_(v)


@torch.library.custom_op("tcc::pinv_via_mh", mutates_args=())
def pinv_via_mh(a: torch.Tensor) -> torch.Tensor:      # complex composite using .mH inside a custom op (the #198118 pattern)
    u, s, vh = torch.linalg.svd(a, full_matrices=False)
    return vh.mH @ torch.diag(1 / s).to(a.dtype) @ u.mH


@pinv_via_mh.register_fake
def _(a):
    return a.new_empty(a.shape[-1], a.shape[-2])


@torch.library.custom_op("tcc::linalg_pinv_wrapped", mutates_args=())
def linalg_pinv_wrapped(a: torch.Tensor) -> torch.Tensor:   # calls the affected ATen composite from inside a custom op
    return torch.linalg.pinv(a)


@linalg_pinv_wrapped.register_fake
def _(a):
    return a.new_empty(a.shape[-1], a.shape[-2])


@torch.library.custom_op("tcc::square_grad", mutates_args=())
def square_grad(x: torch.Tensor) -> torch.Tensor:
    return x * x


@square_grad.register_fake
def _(x):
    return torch.empty_like(x)


def _sq_bw(ctx, grad):
    return grad * 2 * ctx.saved_x


def _sq_setup(ctx, inputs, output):
    ctx.saved_x = inputs[0]


square_grad.register_autograd(_sq_bw, setup_context=_sq_setup)


@torch.library.custom_op("tcc::scalar_out", mutates_args=())
def scalar_out(x: torch.Tensor) -> torch.Tensor:
    return x.sum().reshape(())


@scalar_out.register_fake
def _(x):
    return x.new_empty(())


@torch.library.custom_op("tcc::two_outputs", mutates_args=())
def two_outputs(x: torch.Tensor) -> tuple[torch.Tensor, torch.Tensor]:
    return x + 1, (x * 0).bool()


@two_outputs.register_fake
def _(x):
    return torch.empty_like(x), torch.empty_like(x, dtype=torch.bool)


# ---------- autograd.Function
class Sq(torch.autograd.Function):
    @staticmethod
    def forward(ctx, x):
        ctx.save_for_backward(x)
        return x * x

    @staticmethod
    def backward(ctx, g):
        (x,) = ctx.saved_tensors
        return g * 2 * x


class WrongBackward(torch.autograd.Function):        # backward deliberately not the derivative: compile must reproduce it
    @staticmethod
    def forward(ctx, x):
        return x * 3

    @staticmethod
    def backward(ctx, g):
        return g * 100


class Dirty(torch.autograd.Function):
    @staticmethod
    def forward(ctx, x):
        x.mul_(2)
        ctx.mark_dirty(x)
        return x

    @staticmethod
    def backward(ctx, g):
        return g * 2


class SaveView(torch.autograd.Function):
    @staticmethod
    def forward(ctx, x):
        v = x[1:]
        ctx.save_for_backward(v)
        return v * 2

    @staticmethod
    def backward(ctx, g):
        (v,) = ctx.saved_tensors
        out = torch.zeros(g.shape[0] + 1, dtype=g.dtype)
        out[1:] = g * 2 + 0 * v
        return out


class Once(torch.autograd.Function):
    @staticmethod
    def forward(ctx, x):
        return x.exp()

    @staticmethod
    @torch.autograd.function.once_differentiable
    def backward(ctx, g):
        return g


class NeedsGrad(torch.autograd.Function):
    @staticmethod
    def forward(ctx, x, y):
        ctx.needs = ctx.needs_input_grad
        return x * y

    @staticmethod
    def backward(ctx, g):
        return (g if ctx.needs[0] else None), (g * 2 if ctx.needs[1] else None)


class ComplexMH(torch.autograd.Function):
    @staticmethod
    def forward(ctx, a):
        return (a.mH @ a).real

    @staticmethod
    def backward(ctx, g):
        return None


P = {}


def prog(name, f, *inputs):
    P[name] = (f, inputs)


prog("custom_op with fake", lambda x: twice(x) + 1, X)
prog("custom_op without fake (graph break)", lambda x: twice_nofake(x) + 1, X)
prog("custom_op fake dtype wrong", lambda x: promote(x) + 1, X)
prog("custom_op mutating arg", lambda x: (add_inplace(x, 1.0), x)[1], X.clone())
prog("custom_op mutating arg then use", lambda x: (add_inplace(x, 1.0), x * 2)[1], X.clone())
prog("custom_op complex pinv via mH inside op", lambda a: pinv_via_mh(a), C)
prog("custom_op wrapping torch.linalg.pinv (complex)", lambda a: linalg_pinv_wrapped(a), C)
prog("custom_op wrapping torch.linalg.pinv (real)", lambda a: linalg_pinv_wrapped(a), C.real.contiguous())
prog("custom_op with register_autograd: grad", lambda x: square_grad(x).sum(), X.clone().requires_grad_())
prog("custom_op scalar output + item()", lambda x: scalar_out(x) * 2, X)
prog("custom_op two outputs (bool second)", lambda x: two_outputs(x), X)
prog("custom_op on 0-size input", lambda x: twice(x), X[:0])
prog("custom_op on non-contiguous input", lambda x: twice(x), X.reshape(2, 4).t())
prog("custom_op on inference tensor", lambda x: twice(x), (lambda: (torch.inference_mode().__enter__(), torch.ones(3))[1])())
prog("autograd.Function Sq: grad", lambda x: Sq.apply(x).sum(), X.clone().requires_grad_())
prog("autograd.Function wrong backward: grad", lambda x: WrongBackward.apply(x).sum(), X.clone().requires_grad_())
prog("autograd.Function mark_dirty: value and input", lambda x: Dirty.apply(x), X.clone())
prog("autograd.Function mark_dirty: grad", lambda x: Dirty.apply(x.clone()).sum(), X.clone().requires_grad_())
prog("autograd.Function saves view: grad", lambda x: SaveView.apply(x).sum(), X.clone().requires_grad_())
prog("autograd.Function once_differentiable: grad", lambda x: Once.apply(x).sum(), X.clone().requires_grad_())
prog("autograd.Function needs_input_grad (y no grad)", lambda x, y: NeedsGrad.apply(x, y).sum(), X.clone().requires_grad_(), X.clone())
prog("autograd.Function complex mH in forward", lambda a: ComplexMH.apply(a), C)
prog("autograd.Function returns input (identity)", lambda x: (lambda F: F.apply(x))(type("I", (torch.autograd.Function,), {"forward": staticmethod(lambda ctx, x: x), "backward": staticmethod(lambda ctx, g: g)})), X)


def norm(v):
    if isinstance(v, torch.Tensor):
        t = v.detach()
        if t.is_complex():
            t = torch.view_as_real(t.resolve_conj())
        return {"dtype": str(v.dtype), "shape": list(v.shape), "vals": [repr(x) for x in t.double().flatten().tolist()[:64]], "req": bool(v.requires_grad)}
    if isinstance(v, (tuple, list)):
        return [norm(x) for x in v]
    return repr(v)


def compare(a, b):
    if isinstance(a, dict) and isinstance(b, dict):
        if a["dtype"] != b["dtype"] or a["shape"] != b["shape"]:
            return f"dtype/shape {a['dtype']}{a['shape']} vs {b['dtype']}{b['shape']}"
        for x, y in zip(a["vals"], b["vals"]):
            if x != y:
                fx, fy = float(x), float(y)
                if (fx != fx) and (fy != fy):
                    continue
                if fx == fy or abs(fx - fy) <= 1e-5 * max(1.0, abs(fx), abs(fy)):
                    continue
                return f"value {x} vs {y}"
        return None
    if isinstance(a, list) and isinstance(b, list):
        if len(a) != len(b):
            return f"len {len(a)} vs {len(b)}"
        for x, y in zip(a, b):
            r = compare(x, y)
            if r:
                return r
        return None
    return None if a == b else f"{a} vs {b}"


def observe(f, inputs):
    ins = [x.clone().requires_grad_(x.requires_grad) if isinstance(x, torch.Tensor) and not x.is_inference() else x for x in inputs]
    try:
        out = f(*ins)
    except Exception as e:  # noqa: BLE001
        return {"raised": type(e).__name__, "msg": str(e)[:200]}
    rec = {"out": norm(out), "inputs_after": [norm(x) for x in ins if isinstance(x, torch.Tensor)]}
    if isinstance(out, torch.Tensor) and out.requires_grad and out.dim() == 0:
        try:
            g = torch.autograd.grad(out, [x for x in ins if isinstance(x, torch.Tensor) and x.requires_grad], allow_unused=True)
            rec["grad"] = [norm(x) if x is not None else None for x in g]
        except Exception as e:  # noqa: BLE001
            rec["grad"] = "raises " + type(e).__name__
    return rec


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--backends", default="eager,aot_eager,inductor")
    ap.add_argument("--out", default="results/custom_op/cases.jsonl")
    a = ap.parse_args()
    os.makedirs(os.path.dirname(a.out), exist_ok=True)
    with open(a.out, "w", encoding="utf-8") as f:
        for name, (fn, inputs) in P.items():
            e = observe(fn, inputs)
            rec = {"op": name, "eager": "raises " + e["raised"] if "raised" in e else "ok", "diffs": {}}
            for b in a.backends.split(","):
                torch._dynamo.reset()
                c = observe(torch.compile(fn, backend=b, fullgraph=False), inputs)
                if "raised" in e or "raised" in c:
                    if ("raised" in e) != ("raised" in c):
                        rec["diffs"][b] = ("SILENT eager raises " + e["raised"]) if "raised" in e else f"RAISES {c['raised']}: {c['msg'][:120]}"
                    elif e["raised"] != c["raised"]:
                        rec["diffs"][b] = f"exc-type {e['raised']} vs {c['raised']}"
                    continue
                for key in ("out", "inputs_after", "grad"):
                    if key in e or key in c:
                        r = compare(e.get(key), c.get(key))
                        if r:
                            rec["diffs"][b] = f"{key.upper()} {r}"
                            break
            rec["verdict"] = "ok" if not rec["diffs"] else "DIFF"
            f.write(json.dumps(rec) + "\n")
            print(f"{rec['verdict']:5s} {name:50s} {rec['diffs'] if rec['diffs'] else ''}"[:230], flush=True)


if __name__ == "__main__":
    main()
