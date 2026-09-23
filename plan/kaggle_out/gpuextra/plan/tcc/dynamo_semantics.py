"""6.6 Dynamo Python-semantics differential: small Python programs (generators, try/finally, context managers,
closures, dict/set/list mutation, exceptions, python RNG, numpy interop, graph breaks, ...) run eager vs
torch.compile(backend="eager"). The backend is a no-op, so any divergence is Dynamo's bytecode translation.

Compared per program: the returned value (tensors exactly, python values by ==), the module-level STATE dict
the program may mutate, and the exception type if it raises. Every program is run twice on each side (the
second call exercises guards / cached code / accumulated state).

    python run.py dynsem [--dynamic] [--only names] [--out results/dynsem]
"""
import collections
import contextlib
import copy
import functools
import itertools
import json
import math
import os
import random
import time
from dataclasses import dataclass, asdict, field
from typing import Any, Callable, Dict, List, Optional, Tuple

import numpy as np
import torch

STATE: Dict[str, Any] = {}


def _reset_state():
    STATE.clear()
    STATE.update({"count": 0, "log": [], "d": {}, "s": set()})


# --------------------------------------------------------------------------
# programs: f(x) -> anything; may mutate STATE; may raise
# --------------------------------------------------------------------------
PROGRAMS: Dict[str, Callable[[torch.Tensor], Any]] = {}


def prog(name):
    def deco(f):
        PROGRAMS[name] = f
        return f
    return deco


# --- generators ---
@prog("gen_list")
def _(x):
    def gen(t):
        for i in range(t.shape[0]):
            yield t[i] * (i + 1)
    return list(gen(x))


@prog("gen_expr_sum")
def _(x):
    return sum(t.sum() for t in x)


@prog("gen_yield_from")
def _(x):
    def inner(t):
        yield t + 1
        yield t + 2
    def outer(t):
        yield from inner(t)
        yield t + 3
    return torch.stack(list(outer(x)))


@prog("gen_early_close")
def _(x):
    def gen(t):
        try:
            yield t * 2
            yield t * 3
        finally:
            STATE["log"].append("closed")
    g = gen(x)
    first = next(g)
    g.close()
    return first, list(STATE["log"])


@prog("gen_send")
def _(x):
    def acc(t):
        total = t * 0
        while True:
            v = yield total
            if v is None:
                return
            total = total + v
    g = acc(x)
    next(g)
    out = [g.send(x), g.send(x * 2)]
    return out


# --- try / except / finally ---
@prog("try_except_shape_error")
def _(x):
    try:
        y = x + torch.ones(x.shape[0] + 1)
    except RuntimeError as e:
        STATE["log"].append(type(e).__name__)
        y = x - 1
    finally:
        STATE["count"] += 1
    return y, STATE["count"], list(STATE["log"])


@prog("try_finally_return")
def _(x):
    def f(t):
        try:
            return t * 2
        finally:
            STATE["count"] += 10
    return f(x), STATE["count"]


@prog("raise_custom")
def _(x):
    class MyErr(ValueError):
        pass
    if x.shape[0] > 1:
        raise MyErr(f"bad shape {tuple(x.shape)}")
    return x


@prog("assert_message")
def _(x):
    assert x.shape[0] == 99, f"shape is {x.shape[0]}"
    return x


@prog("except_index_error")
def _(x):
    lst = [1, 2, 3]
    try:
        v = lst[x.shape[0] + 5]
    except IndexError:
        v = -1
    return x * v


@prog("nested_exception_reraise")
def _(x):
    try:
        try:
            raise KeyError("k")
        except KeyError:
            STATE["log"].append("inner")
            raise
    except KeyError:
        STATE["log"].append("outer")
    return x + len(STATE["log"]), list(STATE["log"])


@prog("stopiteration_default")
def _(x):
    it = iter([])
    v = next(it, 7)
    return x * v


# --- context managers ---
@prog("ctx_class")
def _(x):
    class Ctx:
        def __enter__(self):
            STATE["log"].append("enter")
            return 3
        def __exit__(self, *a):
            STATE["log"].append("exit")
            return False
    with Ctx() as k:
        y = x * k
    return y, list(STATE["log"])


@prog("ctx_contextlib")
def _(x):
    @contextlib.contextmanager
    def cm():
        STATE["count"] += 1
        try:
            yield STATE["count"]
        finally:
            STATE["count"] += 100
    with cm() as c:
        y = x + c
    return y, STATE["count"]


@prog("ctx_exception_inside")
def _(x):
    class Ctx:
        def __enter__(self):
            return self
        def __exit__(self, et, ev, tb):
            STATE["log"].append(et.__name__ if et else "none")
            return True          # swallow
    with Ctx():
        raise RuntimeError("boom")
    return x, list(STATE["log"])


@prog("ctx_no_grad_nested")
def _(x):
    x = x.clone().requires_grad_()
    with torch.no_grad():
        a = x * 2
        with torch.enable_grad():
            b = x * 3
    return a.requires_grad, b.requires_grad, torch.is_grad_enabled()


@prog("ctx_set_grad_enabled")
def _(x):
    x = x.clone().requires_grad_()
    torch.set_grad_enabled(False)
    a = x * 2
    torch.set_grad_enabled(True)
    b = x * 2
    return a.requires_grad, b.requires_grad


# --- closures / nonlocal ---
@prog("closure_nonlocal_counter")
def _(x):
    n = 0
    def bump(t):
        nonlocal n
        n += 1
        return t + n
    y = bump(bump(x))
    return y, n


@prog("closure_late_binding")
def _(x):
    fs = [lambda t, i=i: t * i for i in range(3)]
    gs = [lambda t: t * i for i in range(3)]      # late binding: all use i == 2
    return [f(x) for f in fs], [g(x) for g in gs]


@prog("closure_mutable_default")
def _(x):
    def f(t, acc=[]):
        acc.append(t.sum())
        return len(acc)
    return f(x), f(x)


@prog("partial_kwargs")
def _(x):
    def f(t, a, b=1, *, c=2):
        return t * a + b - c
    p = functools.partial(f, b=5)
    return p(x, 2), p(x, 2, c=10)


@prog("args_kwargs_forward")
def _(x):
    def inner(a, b=0, *rest, k=1, **kw):
        return a + b + sum(rest) + k + sum(kw.values())
    def outer(*args, **kwargs):
        return inner(*args, **kwargs)
    return outer(x, 1, 2, 3, k=4, z=5)


# --- dict / set / list ---
@prog("dict_order_and_ops")
def _(x):
    d = {"b": x * 2, "a": x * 1}
    d["c"] = x * 3
    del d["b"]
    d["b"] = x * 4
    d.setdefault("a", x * 9)
    v = d.pop("c")
    return list(d.keys()), v, {k: t.sum() for k, t in d.items()}


@prog("dict_update_merge")
def _(x):
    d = {i: x[i] for i in range(x.shape[0])}
    e = {**d, "extra": x.sum()}
    e.update({0: x[0] * 10})
    last = e.popitem()
    return sorted(str(k) for k in e), last[0]


@prog("set_ops")
def _(x):
    s = {int(v) for v in range(x.shape[0])}
    s.add(1)
    s |= {10, 11}
    s.discard(0)
    return sorted(s), len(s & {1, 10, 99})


@prog("list_slice_assign")
def _(x):
    lst = [x[i] for i in range(x.shape[0])]
    lst[0:2] = [x.sum(), x.mean()]
    lst.insert(1, x.amax())
    lst.pop()
    lst.reverse()
    return lst


@prog("list_sort_key")
def _(x):
    lst = [(i, x[i].sum().item()) for i in range(x.shape[0])]
    lst.sort(key=lambda p: -p[1])
    return [i for i, _ in lst]


@prog("list_extend_in_loop")
def _(x):
    out = []
    for i in range(x.shape[0]):
        out.extend([x[i], x[i] * 2])
        if i == 1:
            out.append(torch.zeros(1))
    return out


@prog("collections_types")
def _(x):
    od = collections.OrderedDict()
    od["z"] = x * 1
    od["a"] = x * 2
    od.move_to_end("z")
    dd = collections.defaultdict(list)
    dd["k"].append(x.sum())
    cnt = collections.Counter([int(v) % 2 for v in range(x.shape[0])])
    dq = collections.deque([x, x * 2], maxlen=2)
    dq.append(x * 3)
    return list(od.keys()), dict(dd), dict(cnt), list(dq)


@prog("itertools_mix")
def _(x):
    pairs = list(itertools.product(range(2), repeat=2))
    ch = list(itertools.chain([x], [x * 2]))
    acc = list(itertools.accumulate([x, x, x]))
    return pairs, ch, acc[-1]


@prog("zip_strict_error")
def _(x):
    try:
        z = list(zip([x, x], [x], strict=True))
    except ValueError:
        return x * 0
    return z


# --- python numbers ---
@prog("int_semantics")
def _(x):
    n = x.shape[0]
    return (-7 // 2, -7 % 2, round(2.5), round(3.5), divmod(-n, 3), 2 ** 62 * 2, n / 2, n // 2, 0 < n <= 3,
            abs(-n), pow(2, 10, 1000), int(True) + n)


@prog("float_nan_semantics")
def _(x):
    nan = float("nan")
    return (nan == nan, nan != nan, max(1.0, 2.0), math.isnan(nan), min([1.5, 0.5]), 1e308 * 10, math.inf > 1e308)


@prog("shape_arith")
def _(x):
    s = x.shape
    return (s[-1] * 2, s.index(s[0]), s.count(s[0]), list(s[::-1]), math.prod(s), tuple(s) + (1,), s == torch.Size(s),
            len(s) * 3, sum(s), max(s))


@prog("bigint_to_tensor")
def _(x):
    return x + (2 ** 40), x * 1e-300, torch.tensor(2 ** 31 - 1) + 1


# --- tensor iteration / indexing / python conversion ---
@prog("iterate_rows")
def _(x):
    out = []
    for i, row in enumerate(x):
        out.append(row * i)
    a, b = x[:2]
    return out, a - b, list(reversed(x))[0]


@prog("unpack_and_star")
def _(x):
    first, *rest = x
    shape = [*x.shape, 1]
    return first, len(rest), torch.zeros(*shape).shape, x.reshape(*reversed(x.shape)).shape


@prog("fancy_index")
def _(x):
    y = x.clone()
    y[[0, 1]] = 0
    y[..., None]
    z = y[::2]
    w = y[torch.tensor([1, 0])]
    y[y > 0] = 7
    return y, z, w, x[x.sum(-1) > 0].shape if x.dim() > 1 else x


@prog("item_and_python_math")
def _(x):
    v = x.sum().item()
    lst = x.tolist()
    return math.floor(v), f"{v:.3f}", len(lst), int(x[0].sum()) if x.dim() else int(x)


@prog("bool_tensor_branch")
def _(x):
    if x.sum() > 0:
        y = x * 2
    else:
        y = x * 3
    return y


@prog("data_dependent_shape")
def _(x):
    nz = torch.nonzero(x > 0)
    return nz.shape[0] * 2, x[x > 0].numel()


@prog("string_ops")
def _(x):
    s = "shape=" + str(tuple(x.shape))
    t = "{} {}".format(x.dtype, x.shape[0])
    u = "%d-%s" % (x.shape[0], "a")
    return s.upper(), t.split(), u, s.startswith("shape"), f"{x.shape[0]:03d}", repr(x.dtype)


# --- graph breaks / resume functions ---
@prog("graph_break_in_loop")
def _(x):
    acc = x * 0
    for i in range(3):
        acc = acc + x * i
        torch._dynamo.graph_break()
        acc = acc * 2
    return acc


@prog("print_in_middle")
def _(x):
    y = x * 2
    print("mid", y.shape)          # graph break with a side effect
    z = y + 1
    STATE["count"] += 1
    return z, STATE["count"]


@prog("many_locals_resume")
def _(x):
    a, b, c, d, e = x, x * 2, x * 3, x * 4, x * 5
    lst = [a, b]
    dct = {"c": c}
    torch._dynamo.graph_break()
    f = a + b + c + d + e + lst[1] + dct["c"]
    torch._dynamo.graph_break()
    return f, len(lst), list(dct)


@prog("break_inside_try")
def _(x):
    try:
        y = x * 2
        torch._dynamo.graph_break()
        y = y + 1
    except Exception:
        y = x
    finally:
        STATE["count"] += 1
    return y, STATE["count"]


@prog("break_inside_with")
def _(x):
    x = x.clone().requires_grad_()
    with torch.no_grad():
        y = x * 2
        torch._dynamo.graph_break()
        z = y + 1
    return z.requires_grad, (z * 1).requires_grad


# --- python RNG / numpy ---
@prog("python_random")
def _(x):
    random.seed(0)
    a = random.random()
    b = random.randint(0, 10)
    c = random.choice([1, 2, 3])
    return x * a + b + c, a, b, c


@prog("python_random_no_seed_state")
def _(x):
    r = random.Random(42)
    return x * r.random(), r.randrange(5)


@prog("numpy_interop")
def _(x):
    n = x.numpy()
    m = np.sqrt(np.abs(n)) + np.float32(1.5)
    return torch.from_numpy(m), float(n.sum()), n.shape, n.dtype.name


@prog("numpy_scalar_types")
def _(x):
    a = np.int64(3)
    b = np.float32(0.5)
    return x * a + b, type(a * 2).__name__, int(a) + x.shape[0]


# --- state / objects ---
@prog("global_state_counter")
def _(x):
    STATE["count"] += 1
    STATE["d"][STATE["count"]] = x.sum()
    return STATE["count"], sorted(STATE["d"])


@prog("object_attr_mutation")
def _(x):
    class Obj:
        def __init__(self):
            self.n = 0
            self.items = []
    o = Obj()
    for i in range(3):
        o.n += i
        o.items.append(x * i)
    return o.n, o.items


@prog("module_python_state")
def _(x):
    class M(torch.nn.Module):
        def __init__(self):
            super().__init__()
            self.calls = 0
            self.register_buffer("buf", torch.zeros(1))
            self.hist = []
        def forward(self, t):
            self.calls += 1
            self.buf.add_(1)
            self.hist.append(t.sum())
            return t + self.buf, self.calls, len(self.hist)
    m = STATE.setdefault("module", M())
    return m(x)


@prog("dataclass_namedtuple")
def _(x):
    from dataclasses import dataclass as dc
    @dc
    class P:
        a: torch.Tensor
        b: int = 1
    NT = collections.namedtuple("NT", "u v")
    p = P(x * 2)
    nt = NT(x, x + 1)
    p.b += 1
    return p.a, p.b, nt.u + nt.v, nt._asdict()["v"], nt == NT(x, x + 1)


@prog("isinstance_dispatch")
def _(x):
    def f(v):
        if isinstance(v, torch.Tensor):
            return v * 2
        if isinstance(v, (int, float)):
            return v + 1
        if isinstance(v, list):
            return [f(i) for i in v]
        return str(v)
    return f(x), f(3), f([x, 1.5]), f("s"), type(x).__name__, hasattr(x, "nope"), getattr(x, "nope", 5)


@prog("tensor_attribute_monkeypatch")
def _(x):
    y = x.clone()
    y.foo = 3
    return y * y.foo, hasattr(y, "foo")


@prog("aliasing_view_inplace")
def _(x):
    x = x.clone()
    v = x.view(-1)
    v.add_(1)
    w = x[0]
    w.mul_(2)
    return x, v.sum(), x[0] is w


@prog("inplace_leaf_error")
def _(x):
    y = x.clone().requires_grad_()
    y.add_(1)
    return y


@prog("detach_identity")
def _(x):
    y = x.clone().requires_grad_()
    d = y.detach()
    return d is y, d.data_ptr() == y.data_ptr(), y.requires_grad, d.requires_grad, (y.data * 2).requires_grad


@prog("grad_attr")
def _(x):
    y = x.clone().requires_grad_()
    (y * 3).sum().backward()
    g = y.grad
    return g, g is None


@prog("copy_deepcopy")
def _(x):
    lst = [x, [x * 2]]
    c = copy.copy(lst)
    d = copy.deepcopy(lst)
    c[1].append(x)
    return len(lst[1]), len(d[1]), d[0] is x, torch.equal(d[0], x)


@prog("while_break_continue_else")
def _(x):
    i, acc = 0, x * 0
    while i < 10:
        i += 1
        if i % 2:
            continue
        if i > 6:
            break
        acc = acc + x * i
    else:
        acc = acc - 1000
    for j in range(2):
        pass
    else:
        acc = acc + 1
    return acc, i


@prog("recursion_depth")
def _(x):
    def rec(t, n):
        if n == 0:
            return t
        return rec(t * 2, n - 1) + 1
    return rec(x, x.shape[0])


@prog("map_filter_any_all")
def _(x):
    ts = [x, x * 0, x * 2]
    m = list(map(lambda t: t.sum(), ts))
    f = list(filter(lambda t: bool(t.abs().sum() > 0), ts))
    return m, len(f), any(t.sum() == 0 for t in ts), all(isinstance(t, torch.Tensor) for t in ts), sum(ts, torch.zeros(1))


@prog("sum_generator_of_tensors")
def _(x):
    return sum((x[i] for i in range(x.shape[0])), start=torch.zeros_like(x[0])), torch.cat(list(t.unsqueeze(0) for t in x))


@prog("dict_zip_enumerate_unbind")
def _(x):
    d = dict(zip(range(x.shape[0]), x.unbind(0)))
    e = {i: t.sum() for i, t in enumerate(x.unbind(0))}
    return d, e, sorted(d)


@prog("chained_bool_tensor_props")
def _(x):
    ok = x.shape[0] == 3 and x.dtype == torch.float32 and not x.is_cuda
    return ok, x is x, x == None, torch.is_tensor(x), x.is_contiguous(), x.dim() > 0 or x.numel() == 1  # noqa: E711


@prog("setitem_mask_and_slices")
def _(x):
    y = x.clone()
    y[y < 0] = 0
    y[0] = y[0] + 1
    y[-1:] = 5
    y[:, ::2] = -1 if y.dim() > 1 else 1
    return y


@prog("torch_func_inside")
def _(x):
    g = torch.func.grad(lambda t: (t ** 2).sum())(x.clone())
    return g


@prog("autograd_grad_inside")
def _(x):
    y = x.clone().requires_grad_()
    (g,) = torch.autograd.grad((y ** 3).sum(), y)
    return g


@prog("manual_seed_inside")
def _(x):
    torch.manual_seed(1)
    a = torch.rand(2)
    torch.manual_seed(1)
    b = torch.rand(2)
    return torch.equal(a, b), x + a


@prog("dropout_train_eval")
def _(x):
    m = torch.nn.Dropout(0.5)
    m.eval()
    a = m(x)
    m.train()
    torch.manual_seed(3)
    b = m(x)
    torch.manual_seed(3)
    c = m(x)
    return a, torch.equal(b, c)


@prog("list_of_tensors_equality")
def _(x):
    try:
        return [x] == [x], (x, 1) == (x, 1)
    except RuntimeError as e:
        return "raise:" + type(e).__name__


@prog("exception_message_with_value")
def _(x):
    v = x.sum().item()
    if v != 12345:
        raise ValueError(f"unexpected {v:.2f}")
    return x


@prog("nested_function_defaults_from_tensor")
def _(x):
    def f(t, n=x.shape[0], s=x.sum()):
        return t * n + s
    return f(x), f(x, 2)


@prog("torch_size_and_int_mixing")
def _(x):
    n = x.shape[0]
    idx = list(range(n))[::-1]
    return x[idx], x[n - 1], x[-n], x.narrow(0, 0, n // 2 + 1).shape


# --------------------------------------------------------------------------
# runner
# --------------------------------------------------------------------------

def _norm(v):
    """Normalize a returned value for comparison / printing."""
    if isinstance(v, Exception):
        return f"raise:{type(v).__name__}"
    if isinstance(v, torch.Tensor):
        return ("T", str(v.dtype), tuple(v.shape), v.detach().reshape(-1).tolist()[:64], v.requires_grad, v.stride())
    if isinstance(v, torch.Size):
        return ("Size", tuple(v))
    if isinstance(v, (list, tuple)):
        return type(v).__name__, [_norm(i) for i in v]
    if isinstance(v, dict):
        return ("dict", [(str(k), _norm(w)) for k, w in v.items()])
    if isinstance(v, set):
        return ("set", sorted(str(i) for i in v))
    if isinstance(v, (np.ndarray,)):
        return ("np", v.dtype.name, v.shape, v.reshape(-1).tolist()[:64])
    if isinstance(v, (np.generic,)):
        return ("npscalar", type(v).__name__, v.item())
    if isinstance(v, float) and math.isnan(v):
        return "nan"
    if isinstance(v, torch.nn.Module):
        return ("Module", type(v).__name__)
    return v


def _run(fn, x):
    try:
        return _norm(fn(x))
    except Exception as e:  # noqa: BLE001
        return _norm(e)


def _state_snapshot():
    return _norm({k: v for k, v in STATE.items() if k != "module"})


@dataclass
class Divergence:
    program: str
    call: int
    what: str          # "return" | "state" | "raise"
    eager: str
    compiled: str
    mode: str = ""


def sweep(dynamic: Optional[bool] = False, only: Optional[List[str]] = None, backend: str = "eager",
          log=print, jsonl: Optional[str] = None, seed: int = 0) -> Dict[str, Any]:
    import torch._dynamo
    torch._dynamo.config.recompile_limit = 10 ** 4
    divs: List[Divergence] = []
    n = 0
    t0 = time.time()
    names = [k for k in PROGRAMS if not only or k in only]
    mode = f"{backend}{'/dynamic' if dynamic else ''}"
    for name in names:
        f = PROGRAMS[name]
        g = torch.Generator().manual_seed(seed)
        x0 = torch.randn(3, 4, generator=g)
        # eager side: two calls with accumulated STATE
        _reset_state()
        random.seed(123)
        eager_out, eager_state = [], []
        for c in range(2):
            eager_out.append(_run(f, x0.clone()))
            eager_state.append(_state_snapshot())
        # compiled side
        _reset_state()
        random.seed(123)
        torch._dynamo.reset()
        cf = torch.compile(f, backend=backend, dynamic=dynamic)
        comp_out, comp_state = [], []
        for c in range(2):
            comp_out.append(_run(cf, x0.clone()))
            comp_state.append(_state_snapshot())
        n += 1
        for c in range(2):
            if eager_out[c] != comp_out[c]:
                what = "raise" if (isinstance(eager_out[c], str) and str(eager_out[c]).startswith("raise")) != (
                    isinstance(comp_out[c], str) and str(comp_out[c]).startswith("raise")) else "return"
                d = Divergence(name, c, what, repr(eager_out[c])[:300], repr(comp_out[c])[:300], mode)
                divs.append(d)
                log(f"  DYNSEM {name:<32} call{c} {what:<6} eager={d.eager[:90]}  compiled={d.compiled[:90]}")
            elif eager_state[c] != comp_state[c]:
                d = Divergence(name, c, "state", repr(eager_state[c])[:300], repr(comp_state[c])[:300], mode)
                divs.append(d)
                log(f"  DYNSEM {name:<32} call{c} state  eager={d.eager[:90]}  compiled={d.compiled[:90]}")
            if jsonl and divs and divs[-1].program == name and divs[-1].call == c:
                with open(jsonl, "a", encoding="utf-8") as fh:
                    fh.write(json.dumps(asdict(divs[-1])) + "\n")
    log(f"dynsem: {n} programs, {len(divs)} divergences, {time.time() - t0:.0f}s ({mode})")
    return {"mode": mode, "programs": n, "divergences": [asdict(d) for d in divs], "wall_s": round(time.time() - t0, 1)}


def write_report(res: Dict[str, Any], out_dir: str) -> str:
    os.makedirs(out_dir, exist_ok=True)
    json.dump(res, open(os.path.join(out_dir, "dynsem.json"), "w"), indent=1)
    lines = [f"# Dynamo python-semantics differential ({res['mode']})", "",
             f"- programs: {res['programs']}, divergences: {len(res['divergences'])}; wall {res['wall_s']} s", "",
             "| program | call | what | eager | compiled |", "|---|---|---|---|---|"]
    for d in res["divergences"]:
        e = d["eager"].replace("|", "\\|")[:160]
        c = d["compiled"].replace("|", "\\|")[:160]
        lines.append(f"| {d['program']} | {d['call']} | {d['what']} | `{e}` | `{c}` |")
    p = os.path.join(out_dir, "DYNSEM.md")
    open(p, "w", encoding="utf-8").write("\n".join(lines) + "\n")
    return p


# second batch of programs (registered on import)
from . import dynamo_semantics_more  # noqa: E402,F401
from . import dynamo_semantics_batch3  # noqa: E402,F401
from . import dynamo_semantics_batch4  # noqa: E402,F401
