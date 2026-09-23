"""7.2-7.6 / 8.9  Side effects and state: hooks, custom backward, caller-visible mutation, effects before an
exception, graph-break replay, guard sequences.

Each case is `case(C)`: a small program in which `C` wraps whatever gets compiled (identity in the eager run) and
which returns an *observation* -- any nesting of tensors, numbers, strings, lists.  The observation of the compiled
run must equal the eager one (tensors: dtype, shape, values within a tight tolerance).  An exception is part of
the observation (type name only).

    python scripts/side_effect_diff.py --isolate [--backends eager,aot_eager,inductor]
    python scripts/side_effect_diff.py --report
"""
import argparse
import json
import os
import sys

sys.path.insert(0, os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
from tcc.compat import ensure_msvc_env  # noqa: E402

ensure_msvc_env()
import torch  # noqa: E402
import torch.nn as nn  # noqa: E402
import torch.nn.functional as F  # noqa: E402

from tcc.sweep_common import jsonl_append, run_isolated  # noqa: E402

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
torch._dynamo.config.recompile_limit = 10 ** 4
CASES = {}


def case(fn):
    CASES[fn.__name__] = fn
    return fn


def T(*s):
    n = 1
    for d in s:
        n *= d
    return (torch.arange(1.0, n + 1).reshape(*s) / 7) - 0.9


def lin(i=3, o=2):
    m = nn.Linear(i, o)
    with torch.no_grad():
        m.weight.copy_(T(o, i))
        m.bias.copy_(T(o))
    return m


# ---- 7.3 hooks ---------------------------------------------------------------------------------------------------
@case
def forward_hook_called_and_modifies_output(C):
    m, log = lin(), []
    m.register_forward_hook(lambda mod, inp, out: (log.append("fwd"), out * 2)[1])
    cm = C(m)
    return [cm(T(2, 3)), cm(T(2, 3)), log]
@case
def forward_pre_hook_modifies_input(C):
    m, log = lin(), []
    m.register_forward_pre_hook(lambda mod, inp: (log.append(tuple(inp[0].shape)), (inp[0] + 1,))[1])
    cm = C(m)
    return [cm(T(2, 3)), log]
@case
def forward_hook_registered_after_compile(C):
    m, log = lin(), []
    cm = C(m)
    a = cm(T(2, 3))
    m.register_forward_hook(lambda mod, inp, out: (log.append("late"), out + 100)[1])
    return [a, cm(T(2, 3)), log]
@case
def forward_hook_removed_after_compile(C):
    m, log = lin(), []
    h = m.register_forward_hook(lambda mod, inp, out: (log.append("h"), out + 100)[1])
    cm = C(m)
    a = cm(T(2, 3)); h.remove()
    return [a, cm(T(2, 3)), log]
@case
def submodule_forward_hook(C):
    m, log = nn.Sequential(lin(3, 3), nn.ReLU(), lin(3, 2)), []
    m[0].register_forward_hook(lambda mod, inp, out: log.append(round(out.sum().item(), 4)))
    cm = C(m)
    return [cm(T(2, 3)), cm(T(2, 3) * 2), log]
@case
def forward_hook_with_kwargs(C):
    m, log = lin(), []
    m.register_forward_hook(lambda mod, args, kwargs, out: (log.append(sorted(kwargs)), out - 1)[1], with_kwargs=True)
    return [C(m)(T(2, 3)), log]
@case
def full_backward_hook_scales_grad(C):
    m, log = lin(), []
    m.register_full_backward_hook(lambda mod, gin, gout: (log.append(len(gin)), tuple(g * 3 for g in gin))[1])
    x = T(2, 3).requires_grad_()
    C(m)(x).sum().backward()
    return [x.grad, m.weight.grad, log]
@case
def full_backward_pre_hook(C):
    m, log = lin(), []
    m.register_full_backward_pre_hook(lambda mod, gout: (log.append("pre"), tuple(g * 0.5 for g in gout))[1])
    x = T(2, 3).requires_grad_()
    C(m)(x).sum().backward()
    return [x.grad, m.weight.grad, log]
@case
def tensor_hook_inside_compiled(C):
    log = []
    def f(x):
        y = x * 2
        y.register_hook(lambda g: g * 10)
        return (y * y).sum()
    x = T(3).requires_grad_()
    C(f)(x).backward()
    return [x.grad]
@case
def tensor_hook_on_input_before_compile(C):
    log = []
    x = T(3).requires_grad_()
    x.register_hook(lambda g: (log.append("hook"), g + 1)[1])
    C(lambda x: (x * x).sum())(x).backward()
    return [x.grad, log]
@case
def tensor_hook_on_output_after_compile(C):
    x = T(3).requires_grad_()
    out = C(lambda x: x * 3)(x)
    out.register_hook(lambda g: g * 5)
    out.sum().backward()
    return [x.grad]
@case
def tensor_hook_on_intermediate_returned(C):
    def f(x):
        h = x.exp()
        return h, (h * 2).sum()
    x = T(3).requires_grad_()
    h, loss = C(f)(x)
    h.register_hook(lambda g: g * 0)
    loss.backward()
    return [x.grad]
@case
def retain_grad_on_intermediate(C):
    def f(x):
        h = x * 2
        h.retain_grad()
        return h, (h * h).sum()
    x = T(3).requires_grad_()
    h, loss = C(f)(x)
    loss.backward()
    return [x.grad, h.grad]
@case
def post_accumulate_grad_hook(C):
    m, log = lin(), []
    m.weight.register_post_accumulate_grad_hook(lambda p: log.append(round(p.grad.sum().item(), 4)))
    C(m)(T(2, 3)).sum().backward()
    return [log, m.weight.grad]
@case
def state_dict_hook_unaffected(C):
    m = lin()
    cm = C(m); cm(T(2, 3))
    return [sorted(m.state_dict().keys())]
# ---- 7.4 custom backward -----------------------------------------------------------------------------------------
class DoubleGrad(torch.autograd.Function):
    @staticmethod
    def forward(ctx, x):
        ctx.save_for_backward(x)
        return x * 1.0
    @staticmethod
    def backward(ctx, g):
        (x,) = ctx.saved_tensors
        return g * 2 + x * 0
class STE(torch.autograd.Function):
    @staticmethod
    def forward(ctx, x):
        return x.round()
    @staticmethod
    def backward(ctx, g):
        return g
class NonDiffOut(torch.autograd.Function):
    @staticmethod
    def forward(ctx, x):
        idx = x.argmax(dim=-1)
        ctx.mark_non_differentiable(idx)
        return x * 2, idx
    @staticmethod
    def backward(ctx, g, _):
        return g * 2
class InplaceDirty(torch.autograd.Function):
    @staticmethod
    def forward(ctx, x):
        x.mul_(2)
        ctx.mark_dirty(x)
        return x
    @staticmethod
    def backward(ctx, g):
        return g * 7
class NeedsInputGrad(torch.autograd.Function):
    @staticmethod
    def forward(ctx, a, b):
        ctx.flags = None
        return a * b
    @staticmethod
    def backward(ctx, g):
        return (g * 11 if ctx.needs_input_grad[0] else None), (g * 13 if ctx.needs_input_grad[1] else None)
class CtxAttr(torch.autograd.Function):
    @staticmethod
    def forward(ctx, x, k):
        ctx.k = k
        return x * k
    @staticmethod
    def backward(ctx, g):
        return g * ctx.k * 100, None
class SetupContext(torch.autograd.Function):
    @staticmethod
    def forward(x, s):
        return x * s
    @staticmethod
    def setup_context(ctx, inputs, output):
        ctx.s = inputs[1]
    @staticmethod
    def backward(ctx, g):
        return g * ctx.s * 5, None
class OnceDiff(torch.autograd.Function):
    @staticmethod
    def forward(ctx, x):
        return x * 3
    @staticmethod
    @torch.autograd.function.once_differentiable
    def backward(ctx, g):
        return g * 4


def _grad(C, f, *xs):
    xs = [x.clone().requires_grad_() for x in xs]
    out = C(f)(*xs)
    outs = out if isinstance(out, tuple) else (out,)
    sum(o.sum() for o in outs if o.is_floating_point() and o.requires_grad).backward()
    return [out] + [x.grad for x in xs]
@case
def custom_fn_double_grad(C): return _grad(C, lambda x: DoubleGrad.apply(x).sin(), T(4))
@case
def custom_fn_straight_through(C): return _grad(C, lambda x: STE.apply(x * 3) * x, T(4))
@case
def custom_fn_non_differentiable_output(C): return _grad(C, lambda x: NonDiffOut.apply(x)[0], T(2, 3))
@case
def custom_fn_mark_dirty(C): return _grad(C, lambda x: InplaceDirty.apply(x * 1.0) + 1, T(4))
@case
def custom_fn_needs_input_grad(C):
    a, b = T(3).requires_grad_(), T(3)
    C(lambda a, b: NeedsInputGrad.apply(a, b))(a, b).sum().backward()
    return [a.grad]
@case
def custom_fn_ctx_attribute(C): return _grad(C, lambda x: CtxAttr.apply(x, 3.0), T(4))
@case
def custom_fn_setup_context(C): return _grad(C, lambda x: SetupContext.apply(x, 2.0), T(4))
@case
def custom_fn_once_differentiable(C): return _grad(C, lambda x: OnceDiff.apply(x).cos(), T(4))
@case
def custom_fn_in_module_twice(C):
    class M(nn.Module):
        def forward(self, x):
            return DoubleGrad.apply(DoubleGrad.apply(x)) * x
    return _grad(C, M(), T(4))
@case
def custom_fn_under_no_grad(C):
    def f(x):
        with torch.no_grad():
            y = DoubleGrad.apply(x)
        return y * x
    return _grad(C, f, T(4))
@case
def detach_in_graph(C): return _grad(C, lambda x: x.detach() * x + x.data.sin(), T(4))
@case
def grad_mode_toggle_inside(C):
    def f(x):
        torch.set_grad_enabled(False)
        y = x * 2
        torch.set_grad_enabled(True)
        return y * x
    return _grad(C, f, T(4))
@case
def requires_grad_set_inside(C):
    def f(x):
        y = x * 2
        z = y.detach().requires_grad_(True)
        return (z * z).sum(), z
    loss, z = C(f)(T(3))
    loss.backward()
    return [z.grad, z.is_leaf]
# ---- 7.2 caller-visible mutation -----------------------------------------------------------------------------------
@case
def mutate_input(C):
    x = T(4); r = C(lambda x: x.add_(1).mul_(2))(x)
    return [x, r, r.data_ptr() == x.data_ptr()]
@case
def mutate_input_view(C):
    x = T(2, 3); C(lambda x: x[0].zero_())(x)
    return [x]
@case
def mutate_view_passed_in(C):
    x = T(6); v = x[::2]
    C(lambda v: v.add_(10))(v)
    return [x, v]
@case
def mutate_transposed_view(C):
    x = T(2, 3); C(lambda v: v.mul_(torch.arange(2.0)))(x.t())
    return [x]
@case
def mutate_two_aliased_inputs(C):
    x = T(6)
    def f(a, b):
        a.add_(1); b.mul_(2)
        return a + b
    return [C(f)(x[:4], x[2:]), x]
@case
def mutate_same_tensor_twice_as_args(C):
    x = T(4)
    def f(a, b):
        a.add_(1); b.add_(1)
        return a * 1
    return [C(f)(x, x), x]
@case
def mutation_order_with_read(C):
    x = T(4)
    def f(x):
        a = x * 2; x.zero_(); b = x + 1
        return a, b
    return [C(f)(x), x]
@case
def mutate_buffer_in_module(C):
    class M(nn.Module):
        def __init__(self):
            super().__init__(); self.register_buffer("n", torch.zeros(()))
        def forward(self, x):
            self.n += 1
            return x * self.n
    m = M(); cm = C(m)
    return [cm(T(3)), cm(T(3)), m.n]
@case
def mutate_python_attribute(C):
    class M(nn.Module):
        def __init__(self):
            super().__init__(); self.calls = 0
        def forward(self, x):
            self.calls += 1
            return x * self.calls
    m = M(); cm = C(m)
    return [cm(T(3)), cm(T(3)), cm(T(3)), m.calls]
@case
def mutate_global_list(C):
    log = []
    def f(x):
        log.append(x.shape[0]); log.append("s")
        return x + len(log)
    cf = C(f)
    return [cf(T(3)), cf(T(3)), cf(T(4)), log]
@case
def mutate_dict_argument(C):
    d = {"k": 0}
    def f(x, d):
        d["k"] += 1; d["new"] = x.shape[0]
        return x * d["k"]
    cf = C(f)
    return [cf(T(3), d), cf(T(3), d), sorted(d.items())]
@case
def copy_into_input_slice(C):
    x = T(2, 4)
    C(lambda x, y: x[:, 1:3].copy_(y))(x, torch.ones(2, 2))
    return [x]
@case
def index_put_inplace_duplicate_indices(C):
    x = torch.zeros(4)
    C(lambda x, i, v: x.index_put_((i,), v, accumulate=True))(x, torch.tensor([1, 1, 3]), torch.ones(3))
    return [x]
@case
def setitem_bool_mask(C):
    x = T(5)
    def f(x):
        x[x > 0] = 0.0
        return x.sum()
    return [C(f)(x), x]
@case
def resize_and_fill(C):
    x = torch.zeros(2)
    def f(x):
        x.resize_(4); x.fill_(3.0)
        return x.sum()
    return [C(f)(x), x]
@case
def out_kwarg_writes_caller_tensor(C):
    out = torch.zeros(3)
    r = C(lambda a, out: torch.add(a, 1, out=out))(T(3), out)
    return [out, r.data_ptr() == out.data_ptr()]
@case
def returned_view_aliases_input(C):
    x = T(4); v = C(lambda x: x[1:3])(x)
    v.add_(100)
    return [x]
@case
def returned_input_identity(C):
    x = T(4); y = C(lambda x: x)(x)
    return [y is x]
@case
def data_ptr_stable_across_calls(C):
    x = T(4); cf = C(lambda x: x.mul_(2))
    cf(x); cf(x)
    return [x]
@case
def version_counter_after_mutation(C):
    x = T(4); C(lambda x: x.add_(1))(x)
    return [x._version > 0]
# ---- 8.9 effects before an exception / graph-break replay ------------------------------------------------------------
@case
def mutation_then_raise(C):
    x = T(3)
    def f(x):
        x.add_(1)
        raise ValueError("boom")
    try:
        C(f)(x)
    except ValueError:
        pass
    return [x]
@case
def mutation_then_tensor_error(C):
    x = T(3)
    def f(x):
        x.add_(1)
        return x @ torch.ones(5)
    try:
        C(f)(x)
    except RuntimeError:
        pass
    return [x]
@case
def list_append_then_raise(C):
    log = []
    def f(x):
        log.append(1); y = x * 2; log.append(2)
        if y.shape[0] == 3:
            raise KeyError("k")
        return y
    try:
        C(f)(T(3))
    except KeyError:
        pass
    return [log]
@case
def graph_break_does_not_replay_effects(C):
    log = []
    def f(x):
        log.append("a"); x = x + 1
        torch._dynamo.graph_break()
        log.append("b"); x = x * 2
        torch._dynamo.graph_break()
        log.append("c")
        return x
    cf = C(f)
    return [cf(T(3)), cf(T(3)), log]
@case
def graph_break_with_inplace(C):
    x = T(3)
    def f(x):
        x.add_(1)
        torch._dynamo.graph_break()
        x.mul_(2)
        return x.sum()
    return [C(f)(x), x]
@case
def graph_break_print_side_effect(C):
    import io, contextlib
    buf = io.StringIO()
    def f(x):
        print("before", x.shape[0]); y = x + 1
        print("after"); return y
    with contextlib.redirect_stdout(buf):
        cf = C(f); cf(T(2)); cf(T(2))
    return [buf.getvalue()]
@case
def graph_break_in_loop_counter(C):
    cnt = {"n": 0}
    def f(x):
        for i in range(3):
            cnt["n"] += 1
            if i == 1:
                torch._dynamo.graph_break()
            x = x + i
        return x
    cf = C(f)
    return [cf(T(2)), cf(T(2)), cnt["n"]]
@case
def try_finally_effects(C):
    log = []
    def f(x):
        try:
            log.append("try"); y = x * 2
            if y.shape[0] == 2:
                raise RuntimeError("r")
        finally:
            log.append("finally")
        return y
    try:
        C(f)(T(2))
    except RuntimeError:
        log.append("caught")
    return [log]
@case
def context_manager_exit_runs(C):
    log = []
    class CM:
        def __enter__(self): log.append("enter"); return self
        def __exit__(self, *a): log.append("exit"); return False
    def f(x):
        with CM():
            y = x + 1
        return y * 2
    cf = C(f)
    return [cf(T(2)), cf(T(2)), log]
@case
def generator_side_effects(C):
    log = []
    def gen(n):
        for i in range(n):
            log.append(i); yield i
    return [C(lambda x: x + sum(gen(3)))(T(2)), log]
@case
def nonlocal_counter(C):
    def make():
        n = 0
        def f(x):
            nonlocal n
            n += 1
            return x * n
        return f, lambda: n
    f, get = make(); cf = C(f)
    return [cf(T(2)), cf(T(2)), get()]
@case
def global_tensor_mutated(C):
    g = {"t": torch.zeros(2)}
    def f(x):
        g["t"] = g["t"] + x
        return g["t"] * 2
    cf = C(f)
    return [cf(torch.ones(2)), cf(torch.ones(2)), g["t"]]
# ---- 7.5 guard / recompile sequences ---------------------------------------------------------------------------------
def _seq(C, f, inputs):
    cf = C(f)
    return [cf(*i) if isinstance(i, tuple) else cf(i) for i in inputs]
@case
def seq_dtype_changes(C): return _seq(C, lambda x: x / 3 + x.sum(), [T(4), T(4).double(), T(4).half(), T(4).to(torch.int32), T(4)])
@case
def seq_layout_changes(C): return _seq(C, lambda x: x.cumsum(-1) * 2, [T(2, 3), T(3, 2).t(), T(2, 6)[:, ::2], T(2, 3)])
@case
def seq_requires_grad_changes(C):
    f = lambda x: (x * x).sum()
    cf, outs = C(f), []
    for rg in (False, True, False, True):
        x = T(3).requires_grad_(rg); y = cf(x)
        if rg:
            y.backward(); outs.append(x.grad)
        outs.append(y.detach())
    return outs
@case
def seq_optional_none_to_tensor(C):
    f = lambda x, b=None: x * 2 if b is None else x * 2 + b
    cf = C(f)
    return [cf(T(3)), cf(T(3), T(3)), cf(T(3)), cf(T(3), b=T(3) * 0)]
@case
def seq_python_scalar_0_1_2(C):
    cf = C(lambda x, k: x * k + k)
    return [cf(T(3), k) for k in (2, 0, 1, 1.5, True, 2, -1)]
@case
def seq_train_eval(C):
    m = nn.Sequential(lin(3, 3), nn.BatchNorm1d(3)); cm, outs = C(m), []
    for mode in (True, False, True, False):
        m.train(mode); outs.append(cm(T(4, 3)))
    return outs + [m[1].running_mean, m[1].num_batches_tracked]
@case
def seq_module_attribute_changed(C):
    class M(nn.Module):
        def __init__(self):
            super().__init__(); self.scale = 2.0; self.flag = True
        def forward(self, x):
            return x * self.scale if self.flag else x - self.scale
    m = M(); cm = C(m); outs = [cm(T(3))]
    m.scale = 5.0; outs.append(cm(T(3)))
    m.flag = False; outs.append(cm(T(3)))
    return outs
@case
def seq_parameter_replaced(C):
    m = lin(); cm = C(m); outs = [cm(T(2, 3))]
    m.weight = nn.Parameter(m.weight.detach() * 0); outs.append(cm(T(2, 3)))
    with torch.no_grad():
        m.bias.add_(1)
    outs.append(cm(T(2, 3)))
    return outs
@case
def seq_list_length_changes(C):
    cf = C(lambda xs: sum(xs) * len(xs))
    return [cf([T(2)]), cf([T(2), T(2)]), cf([T(2), T(2), T(2)]), cf([T(2)])]
@case
def seq_dict_keys_change(C):
    cf = C(lambda d: sum(v * (i + 1) for i, (k, v) in enumerate(sorted(d.items()))))
    return [cf({"a": T(2)}), cf({"a": T(2), "b": T(2)}), cf({"b": T(2), "a": T(2) * 3}), cf({"z": T(2)})]
@case
def seq_global_flag(C):
    flags = {"on": True}
    cf = C(lambda x: x + 1 if flags["on"] else x - 1); outs = [cf(T(2))]
    flags["on"] = False; outs.append(cf(T(2)))
    flags["on"] = True; outs.append(cf(T(2)))
    return outs
@case
def seq_default_dtype_switch(C):
    cf = C(lambda x: x + torch.tensor(1.5) + torch.ones(2)); outs = [cf(torch.zeros(2, dtype=torch.float64))]
    torch.set_default_dtype(torch.float64)
    try:
        outs.append(cf(torch.zeros(2, dtype=torch.float64)))
    finally:
        torch.set_default_dtype(torch.float32)
    outs.append(cf(torch.zeros(2, dtype=torch.float64)))
    return outs
@case
def seq_shape_0_1_many(C):
    cf = C(lambda x: (x.mean(0), x.sum(), x.shape[0]))
    return [cf(T(3, 2)), cf(T(1, 2)), cf(torch.zeros(0, 2)), cf(T(5, 2)), cf(T(1, 2))]
@case
def seq_inference_mode_then_grad(C):
    cf, outs = C(lambda x: x.exp().sum()), []
    with torch.inference_mode():
        outs.append(cf(T(3)).clone())
    x = T(3).requires_grad_(); y = cf(x); y.backward()
    return outs + [y.detach(), x.grad]
@case
def seq_autocast_on_off(C):
    cf, outs = C(lambda a, b: a @ b), []
    outs.append(cf(T(2, 2), T(2, 2)))
    with torch.autocast("cpu", dtype=torch.bfloat16):
        outs.append(cf(T(2, 2), T(2, 2)))
    outs.append(cf(T(2, 2), T(2, 2)))
    return outs


# ---- comparison ------------------------------------------------------------------------------------------------------
def norm(o):
    if isinstance(o, torch.Tensor):
        t = o.detach()
        return {"T": str(t.dtype), "shape": list(t.shape), "v": [round(float(v), 5) if v == v else "nan" for v in t.flatten().double().tolist()]}
    if isinstance(o, (list, tuple)):
        return [norm(x) for x in o]
    if isinstance(o, dict):
        return {str(k): norm(v) for k, v in o.items()}
    if isinstance(o, float):
        return round(o, 5)
    if isinstance(o, (int, bool, str)) or o is None:
        return o
    return repr(type(o).__name__)


def close(a, b):
    if isinstance(a, dict) and isinstance(b, dict) and "T" in a and "T" in b:
        if a["T"] != b["T"] or a["shape"] != b["shape"] or len(a["v"]) != len(b["v"]):
            return False
        return all((x == y) or (isinstance(x, float) and isinstance(y, float) and abs(x - y) <= 1e-4 * max(1.0, abs(x), abs(y))) for x, y in zip(a["v"], b["v"]))
    if isinstance(a, list) and isinstance(b, list):
        return len(a) == len(b) and all(close(x, y) for x, y in zip(a, b))
    if isinstance(a, dict) and isinstance(b, dict):
        return a.keys() == b.keys() and all(close(a[k], b[k]) for k in a)
    return a == b


def observe(name, backend):
    torch._dynamo.reset()
    torch.manual_seed(0)
    C = (lambda f: f) if backend is None else (lambda f: torch.compile(f, backend=backend))
    try:
        return norm(CASES[name](C))
    except Exception as e:  # noqa: BLE001
        return {"raised": type(e).__name__, "msg": str(e).splitlines()[0][:160] if str(e) else ""}


def report(path):
    from collections import Counter
    rows = [json.loads(l) for l in open(path, encoding="utf-8") if l.strip()]
    print(len(rows), dict(Counter(r["verdict"] for r in rows)))
    for r in rows:
        if r["verdict"] == "ok":
            continue
        print(f"\n[{r['verdict']}] {r['op']}")
        if r["verdict"] == "CRASH":
            print("   rc", r.get("returncode"), r.get("tail", "")[-200:]); continue
        print("   eager    :", json.dumps(r["eager"])[:330])
        for b, x in r["backends"].items():
            if not x["same"]:
                print(f"   {b:9s}:", json.dumps(x["obs"])[:330])


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--only", default=None)
    ap.add_argument("--backends", default="eager,aot_eager,inductor")
    ap.add_argument("--isolate", action="store_true")
    ap.add_argument("--report", action="store_true")
    ap.add_argument("--out-jsonl", default=os.path.join(ROOT, "results", "side_effects", "cases.jsonl"))
    a = ap.parse_args()
    os.makedirs(os.path.dirname(a.out_jsonl), exist_ok=True)
    if a.report:
        return report(a.out_jsonl)
    names = a.only.split(",") if a.only else list(CASES)
    if a.isolate:
        run_isolated(os.path.abspath(__file__), names, ["--backends", a.backends], a.out_jsonl, timeout=1200)
        return
    for n in names:
        e = observe(n, None)
        rec = {"op": n, "eager": e, "backends": {}}
        bad = []
        for b in a.backends.split(","):
            o = observe(n, b)
            same = close(e, o)
            if isinstance(e, dict) and "raised" in e and isinstance(o, dict) and "raised" in o:
                same = True          # both raise: exception-type wrapping is known noise
            rec["backends"][b] = {"same": same, "obs": o}
            if not same:
                bad.append(b)
        rec["verdict"] = "ok" if not bad else "DIFF:" + "+".join(bad)
        jsonl_append(a.out_jsonl, rec)
        if bad:
            print(f"  !! {n}: differs under {bad}", flush=True)


if __name__ == "__main__":
    main()
