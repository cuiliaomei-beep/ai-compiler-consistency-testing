"""Second batch of Dynamo python-semantics programs (registered into dynamo_semantics.PROGRAMS on import).

Themes: more random/numpy, builtin edge cases, string/bytes, exceptions across graph breaks, generators with
state, class machinery (__call__/__getattr__/__slots__/properties/classmethods), operator overloading on
plain python objects, torch.Size/dtype/device as python values, mutation of inputs/containers visible to
the caller, in-place + views, `is` identity, hashing, sorting tensors, enumerate/zip edge cases, while/try
interplay, nested functions + default args, functools.reduce/lru_cache, contextlib.suppress/ExitStack,
itertools groupby/zip_longest/pairwise, dict views, sets of tensors, `del`, walrus, match statement.
"""
import contextlib
import functools
import itertools
import math
import operator
import random

import numpy as np
import torch

from .dynamo_semantics import PROGRAMS, STATE


def prog(name):
    def deco(f):
        PROGRAMS[name] = f
        return f
    return deco


# --- random / numpy continued ---
@prog("random_choice_weights")
def _(x):
    random.seed(1)
    return random.choices([1, 2, 3], weights=[1, 1, 8], k=4), random.betavariate(2, 3), random.expovariate(1.5)


@prog("random_randbytes_getrandbits")
def _(x):
    random.seed(2)
    return random.getrandbits(16), len(random.randbytes(3)), random.triangular(0, 1)


@prog("random_instance_methods")
def _(x):
    r = random.Random(5)
    lst = [1, 2, 3, 4]
    r.shuffle(lst)
    return lst, r.sample(range(10), 3), r.random(), r.randint(0, 9)


@prog("torch_rand_in_fn")
def _(x):
    torch.manual_seed(11)
    a = torch.rand(3)
    b = torch.randint(0, 10, (3,))
    c = torch.randn_like(x)
    return a, b, c.shape, torch.rand(()).item() < 2


@prog("np_random_in_fn")
def _(x):
    rng = np.random.default_rng(3)
    return float(rng.random()), torch.from_numpy(rng.standard_normal(3).astype(np.float32))


@prog("np_array_ops")
def _(x):
    n = x.numpy()
    a = np.concatenate([n, n[:1]], axis=0)
    b = a.reshape(-1)[::2].copy()
    c = np.where(a > 0, a, 0).sum(axis=0)
    return torch.from_numpy(b), torch.from_numpy(c), a.shape, int(a.argmax()), a.dtype == np.float32, np.allclose(a, a)


@prog("np_scalar_math")
def _(x):
    a = np.float64(2.5)
    return math.floor(a), a.item(), int(a) + x.shape[0], x * a, np.int32(7) // np.int32(2), type(np.int32(7) // 2).__name__


# --- builtins edge cases ---
@prog("builtins_misc")
def _(x):
    n = x.shape[0]
    return (bin(n), hex(n * 255), oct(n), ord("a") + n, chr(65 + n), round(1.23456, 3), round(x.sum().item(), 2),
            sorted({3, n, 1}, reverse=True), list(range(n, 0, -1)), divmod(7, n), max(range(n)), sum(range(n), 10))


@prog("int_float_conversion")
def _(x):
    n = x.shape[0]
    return (float(n) / 2, n / 2 == 1.5, int(2.9), int(-2.9), 7 // -2, 7 % -2, -7 // 2, 2 ** -1, 10 ** n, float("1e3"), int("42") + n)


@prog("bool_ops_on_python")
def _(x):
    n = x.shape[0]
    return (n and 5, 0 or n, not n, n > 2 > 1, (n, 1) < (n, 2), [1, 2] < [1, 3], "a" < "b", None is None, bool([]), bool([0]))


@prog("string_methods_more")
def _(x):
    s = "abc,def,ghi"
    parts = s.split(",")
    return (",".join(reversed(parts)), s.replace("def", str(x.shape[0])), s.find("def"), s.count(","), s[::-1],
            s.title(), "x" * x.shape[0], f"{'abc':>6}|{'abc':<6}|{'abc':^7}", "%05.1f" % 3.14159, "abc".encode()[0])


@prog("bytes_and_bytearray")
def _(x):
    b = bytes([1, 2, 3])
    ba = bytearray(b)
    ba.append(x.shape[0])
    return len(ba), ba[-1], b.hex(), bytes(ba)[:2]


@prog("tuple_ops")
def _(x):
    t = (1, 2) + (3,)
    return t * 2, t.index(3), t.count(1), t[1:], tuple(x.shape) * 2, (x.shape[0],) + tuple(x.shape)


@prog("list_comprehension_conditions")
def _(x):
    return ([i for i in range(6) if i % 2 if i > 1], [(i, j) for i in range(2) for j in range(2) if i != j],
            [x[i] for i in range(x.shape[0]) if x[i].sum() > 0] or [x[0]], {i: i * i for i in range(3) if i},
            {i % 2 for i in range(5)})


@prog("walrus_and_match")
def _(x):
    if (n := x.shape[0]) > 2:
        y = x * n
    else:
        y = x
    match n:
        case 3:
            tag = "three"
        case _:
            tag = "other"
    match (n, "k"):
        case (3, str() as s):
            tag2 = s + "3"
        case _:
            tag2 = "no"
    return y, tag, tag2


@prog("del_and_rebind")
def _(x):
    a = x * 2
    lst = [a, x]
    d = {"a": a}
    del lst[0]
    del d["a"]
    b = a
    del a
    return b, lst, d


@prog("slicing_negative_steps")
def _(x):
    return x[::-1], x[:, ::-1] if x.dim() > 1 else x, x[-2:], x[::2, 1::2] if x.dim() > 1 else x, x[1:-1], x[..., -1]


@prog("ellipsis_none_indexing")
def _(x):
    return x[None].shape, x[..., None, :].shape, x[None, ..., None].shape, x[(Ellipsis, 0)].shape, x[()] is x


# --- exceptions across graph breaks ---
@prog("exception_after_graph_break")
def _(x):
    y = x * 2
    torch._dynamo.graph_break()
    try:
        raise KeyError("after break")
    except KeyError as e:
        return y + 1, str(e)


@prog("exception_from_torch_op_caught")
def _(x):
    try:
        torch.cat([x, torch.zeros(2, 3)])
    except RuntimeError as e:
        msg = "cat failed"
    else:
        msg = "no error"
    return x, msg


@prog("exception_in_generator")
def _(x):
    def gen():
        yield 1
        raise ValueError("gen")
    g = gen()
    out = [next(g)]
    try:
        next(g)
    except ValueError:
        out.append(-1)
    return x * out[0], out


@prog("exception_chaining")
def _(x):
    try:
        try:
            raise ValueError("a")
        except ValueError as e:
            raise TypeError("b") from e
    except TypeError as e:
        return x, type(e.__cause__).__name__, str(e)


@prog("finally_overrides_return")
def _(x):
    def f(t):
        try:
            return t * 1
        finally:
            STATE["count"] += 1
            t = t * 100
    return f(x), STATE["count"]


@prog("exception_group")
def _(x):
    try:
        raise ExceptionGroup("eg", [ValueError("v"), TypeError("t")])
    except* ValueError as eg:
        STATE["log"].append("v")
    except* TypeError:
        STATE["log"].append("t")
    return x, list(STATE["log"])


@prog("assert_tensor_shape_ok")
def _(x):
    assert x.shape[0] > 0, "empty"
    assert x.dim() == 2
    return x


@prog("contextlib_suppress_exitstack")
def _(x):
    with contextlib.suppress(KeyError):
        {}["missing"]
        STATE["log"].append("not reached")
    with contextlib.ExitStack() as st:
        st.callback(lambda: STATE["log"].append("cb"))
        y = x + 1
    return y, list(STATE["log"])


# --- generators with state ---
@prog("generator_stateful_class")
def _(x):
    class Counter:
        def __init__(self):
            self.i = 0
        def __iter__(self):
            return self
        def __next__(self):
            self.i += 1
            if self.i > 3:
                raise StopIteration
            return self.i
    c = Counter()
    return [x * i for i in c], c.i


@prog("generator_infinite_islice")
def _(x):
    def nat():
        i = 0
        while True:
            yield i
            i += 1
    return [x.sum() * i for i in itertools.islice(nat(), 3)]


@prog("genexpr_any_short_circuit")
def _(x):
    seen = []
    def chk(i):
        seen.append(i)
        return i == 1
    return any(chk(i) for i in range(5)), list(seen), all(chk(i) for i in range(2)), list(seen)


@prog("itertools_more")
def _(x):
    data = [1, 1, 2, 3, 3, 3]
    groups = [(k, len(list(g))) for k, g in itertools.groupby(data)]
    zl = list(itertools.zip_longest([1, 2], [3], fillvalue=0))
    pw = list(itertools.pairwise([1, 2, 3]))
    tk = list(itertools.takewhile(lambda v: v < 3, data))
    cyc = list(itertools.islice(itertools.cycle([x, x * 2]), 3))
    return groups, zl, pw, tk, cyc, list(itertools.starmap(operator.mul, [(2, 3), (4, 5)]))


@prog("functools_reduce_lru")
def _(x):
    total = functools.reduce(operator.add, [x, x, x])
    @functools.lru_cache(maxsize=None)
    def sq(n):
        STATE["count"] += 1
        return n * n
    return total, sq(3) + sq(3) + sq(4), STATE["count"]


# --- class machinery ---
@prog("class_call_getattr")
def _(x):
    class Scale:
        def __init__(self, s):
            self.s = s
        def __call__(self, t):
            return t * self.s
        def __getattr__(self, name):
            if name.startswith("times_"):
                return lambda t: t * int(name[6:])
            raise AttributeError(name)
    sc = Scale(2)
    return sc(x), sc.times_3(x), hasattr(sc, "times_5"), hasattr(sc, "nope")


@prog("class_slots_property_classmethod")
def _(x):
    class P:
        __slots__ = ("a", "_b")
        def __init__(self, a):
            self.a = a
            self._b = a * 2
        @property
        def b(self):
            return self._b
        @b.setter
        def b(self, v):
            self._b = v
        @classmethod
        def make(cls, t):
            return cls(t + 1)
        @staticmethod
        def twice(t):
            return t * 2
    p = P.make(x)
    p.b = p.b + 1
    return p.a, p.b, P.twice(x), hasattr(p, "__dict__")


@prog("operator_overloading_python_obj")
def _(x):
    class V:
        def __init__(self, t):
            self.t = t
        def __add__(self, o):
            return V(self.t + (o.t if isinstance(o, V) else o))
        __radd__ = __add__
        def __mul__(self, k):
            return V(self.t * k)
        def __neg__(self):
            return V(-self.t)
        def __len__(self):
            return self.t.shape[0]
        def __getitem__(self, i):
            return self.t[i]
        def __iter__(self):
            return iter(self.t.unbind(0))
        def __bool__(self):
            return True
        def __eq__(self, o):
            return torch.equal(self.t, o.t)
        def __hash__(self):
            return 7
    v = V(x)
    w = -(v + 1 + v) * 2
    return w.t, len(w), w[0], [r.sum() for r in w], v == V(x), bool(v), hash(v)


@prog("inheritance_super_mro")
def _(x):
    class A:
        def f(self, t):
            return t + 1
    class B(A):
        def f(self, t):
            return super().f(t) * 2
    class C(B):
        pass
    return C().f(x), [k.__name__ for k in C.__mro__[:3]], isinstance(C(), A), issubclass(C, B)


@prog("dunder_contains_and_in")
def _(x):
    class Bag:
        def __init__(self):
            self.items = [1, 2, 3]
        def __contains__(self, v):
            STATE["count"] += 1
            return v in self.items
    b = Bag()
    return (2 in b, 9 in b, STATE["count"], x.shape[0] in [1, 2, 3], "a" in "cat", 3 in range(5),
            x.shape[0] in {3: 1}, 0.5 in torch.tensor([0.5, 1.0]))


@prog("module_as_python_value")
def _(x):
    m = torch.nn.Linear(4, 2)
    STATE["d"]["mod"] = m
    mods = [m, torch.nn.ReLU()]
    return len(list(m.parameters())), m.in_features, type(mods[1]).__name__, sum(p.numel() for p in m.parameters()), m.weight.shape


# --- torch python values ---
@prog("size_dtype_device_values")
def _(x):
    return (x.shape == (3, 4), x.shape[0] == 3, x.size() == torch.Size([3, 4]), x.dtype == torch.float32, x.dtype.is_floating_point,
            x.dtype.itemsize, str(x.device), x.device.type == "cpu", x.element_size() * x.numel(), torch.finfo(x.dtype).eps,
            torch.iinfo(torch.int32).max, x.dtype in (torch.float32, torch.float64), torch.float32 == torch.float)


@prog("tensor_python_protocol")
def _(x):
    return (len(x), x.shape.numel(), list(x.shape), [*x.shape], x.ndim, x.T.shape if x.dim() == 2 else x.shape,
            x.numel() > 0, x.is_floating_point(), x.dtype.is_complex, x.layout == torch.strided, x.storage_offset())


@prog("tensor_hash_id_set")
def _(x):
    y = x * 1
    s = {x, y}
    d = {x: 1, y: 2}
    return len(s), d[x], x in s, hash(x) == hash(x), id(x) == id(x), x is y


@prog("sorted_tensors_key")
def _(x):
    rows = list(x.unbind(0))
    s = sorted(rows, key=lambda r: r.sum().item())
    m = max(rows, key=lambda r: r.abs().sum())
    return torch.stack(s), m


@prog("min_max_builtin_on_tensors")
def _(x):
    return max(x[0, 0], x[0, 1]), min(x[0, 0], x[0, 1], x[0, 2]), max([x.sum(), x.mean()]), abs(x[0, 0]), round(x[0, 0].item(), 1)


# --- mutation visible to caller ---
@prog("mutate_input_list_arg")
def _(x):
    lst = STATE["log"]
    lst.append(x.sum())
    lst.extend([1, 2])
    lst[0] = lst[0] * 2 if isinstance(lst[0], torch.Tensor) else lst[0]
    return len(lst), lst[1:]


@prog("mutate_input_dict_nested")
def _(x):
    d = STATE["d"]
    d.setdefault("n", {})["k"] = x.sum()
    d["n"]["k2"] = d["n"]["k"] + 1
    d["list"] = d.get("list", []) + [x.shape[0]]
    return sorted(d["n"]), d["list"]


@prog("inplace_on_input_then_view")
def _(x):
    x.mul_(2)
    v = x[:, 0]
    v.add_(100)
    return x.sum(), v


@prog("inplace_resize_and_set")
def _(x):
    y = x.clone()
    z = torch.zeros(2)
    z.set_(y.view(-1)[:2])
    y.view(-1)[0] = 42
    return z, y[0, 0]


@prog("requires_grad_toggle_inside")
def _(x):
    y = x.clone()
    y.requires_grad_(True)
    z = y * 2
    y.requires_grad_(False)
    w = y * 2
    return z.requires_grad, w.requires_grad


@prog("inplace_views_overlap")
def _(x):
    y = x.clone()
    a = y[0:2]
    b = y[1:3]
    a.add_(1)
    return b, y


@prog("out_kwarg")
def _(x):
    out = torch.empty_like(x)
    torch.add(x, 1, out=out)
    out2 = torch.empty(0)
    torch.mul(x, 2, out=out2)
    return out, out2.shape


@prog("as_strided_unfold")
def _(x):
    y = x.contiguous()
    a = torch.as_strided(y, (2, 2), (1, 2))
    u = y.unfold(1, 2, 1) if y.dim() == 2 else y
    return a, u.shape, a.is_contiguous()


# --- control flow ---
@prog("nested_loops_break_labels")
def _(x):
    acc = x * 0
    found = None
    for i in range(3):
        for j in range(3):
            if i * j == 2:
                found = (i, j)
                break
            acc = acc + x * (i + j)
        if found:
            break
    return acc, found


@prog("loop_over_dict_mutating_copy")
def _(x):
    d = {i: x[i] for i in range(x.shape[0])}
    for k in list(d):
        if k % 2:
            d.pop(k)
        else:
            d[k + 10] = d[k] * 2
    return sorted(d)


@prog("while_with_tensor_condition_item")
def _(x):
    t = x.abs().sum()
    n = 0
    while t.item() > 1 and n < 20:
        t = t / 2
        n += 1
    return n, t


@prog("ternary_chains_and_or")
def _(x):
    n = x.shape[0]
    a = x if n > 5 else x * 2 if n > 2 else x * 3
    b = (n > 2 and x.sum()) or x.mean()
    c = None or 0 or [] or x.shape[0]
    return a, b, c


@prog("enumerate_start_zip_three")
def _(x):
    out = []
    for i, (a, b, c) in enumerate(zip(x, x.flip(0), range(10)), start=5):
        out.append((i, c, (a + b).sum()))
    return out


@prog("default_args_evaluated_once")
def _(x):
    def f(t, cache={}):
        cache[len(cache)] = t.sum()
        return len(cache)
    return f(x), f(x), f(x)


@prog("nonlocal_in_loop_closure")
def _(x):
    total = x * 0
    count = 0
    def add(t):
        nonlocal total, count
        total = total + t
        count += 1
    for row in x:
        add(row)
    return total, count


@prog("recursion_with_memo_dict")
def _(x):
    memo = {}
    def fib(n):
        if n < 2:
            return n
        if n not in memo:
            memo[n] = fib(n - 1) + fib(n - 2)
        return memo[n]
    return x * fib(10), len(memo)


@prog("lambda_in_dict_dispatch")
def _(x):
    ops = {"a": lambda t: t + 1, "m": lambda t: t * 2, "n": torch.neg}
    return [ops[k](x) for k in sorted(ops)], ops.get("zz", lambda t: t)(x)


@prog("global_constant_folding")
def _(x):
    return x * math.pi + math.e, math.sqrt(x.shape[0]), math.log2(8), math.gcd(12, x.shape[0] * 3), math.comb(5, 2), math.isclose(0.1 + 0.2, 0.3)


@prog("print_format_side_effect_count")
def _(x):
    for i in range(2):
        print(f"step {i}: {x.sum().item():.2f}")
    return x


@prog("string_join_of_tensor_values")
def _(x):
    return ", ".join(str(round(v, 2)) for v in x[0].tolist()), " ".join(map(str, x.shape))


@prog("dict_views_and_iteration_order")
def _(x):
    d = {"b": 1, "a": 2, "c": 3}
    ks = d.keys()
    d["d"] = 4
    return list(ks), list(d.values()), list(d.items())[-1], list(reversed(d)), dict(sorted(d.items())), "a" in ks


@prog("set_of_shapes_and_frozenset")
def _(x):
    s = {x.shape, torch.Size([3, 4]), (3, 4)}
    fs = frozenset([1, 2]) | {3}
    return len(s), sorted(fs), (3, 4) in s


@prog("deepcopy_module_state")
def _(x):
    import copy
    m = torch.nn.Linear(4, 2)
    m2 = copy.deepcopy(m)
    m2.weight.data.fill_(0)
    return torch.equal(m.weight, m2.weight), m2(x).abs().sum() == m2.bias.abs().sum() * x.shape[0]


@prog("torch_no_grad_decorator")
def _(x):
    @torch.no_grad()
    def f(t):
        return t * 2
    y = x.clone().requires_grad_()
    return f(y).requires_grad, (y * 2).requires_grad


@prog("autocast_inside")
def _(x):
    with torch.autocast("cpu", dtype=torch.bfloat16):
        y = torch.nn.functional.linear(x, torch.randn(2, 4))
        z = x + 1
    return y.dtype, z.dtype, torch.is_autocast_enabled("cpu")


@prog("inference_mode_inside")
def _(x):
    with torch.inference_mode():
        y = x * 2
    return y.is_inference(), y.requires_grad


@prog("tensor_bool_in_if_after_item")
def _(x):
    flag = bool((x > 100).any())
    n = int((x > 0).sum())
    return x * (2 if flag else 3), n, [i for i in range(n)][:3]


@prog("complex_python_numbers")
def _(x):
    c = 1 + 2j
    return x * c.real + c.imag, abs(c), c.conjugate(), (x.to(torch.complex64) * c).dtype, complex(x.shape[0], 1)


@prog("format_spec_on_shape_and_item")
def _(x):
    n = x.shape[0]
    v = x.sum().item()
    return f"{n:03d}", f"{n / 2:.1f}", f"{v:+.2e}", f"{n!r}", f"{x.dtype!s}", "{:>4}".format(n), "%d" % n, f"{n:,}"


@prog("dataclass_frozen_and_field_default")
def _(x):
    from dataclasses import dataclass, field
    @dataclass(frozen=True)
    class F:
        a: int
        b: tuple = (1, 2)
    @dataclass
    class G:
        items: list = field(default_factory=list)
    f = F(x.shape[0])
    g = G()
    g.items.append(x.sum())
    try:
        f.a = 1
        frozen_ok = False
    except Exception:
        frozen_ok = True
    return f.a, f.b, len(g.items), frozen_ok, f == F(3), hash(f) == hash(F(3))


@prog("enum_usage")
def _(x):
    import enum
    class Mode(enum.Enum):
        A = 1
        B = 2
    class Flag(enum.IntFlag):
        R = 1
        W = 2
    m = Mode.A if x.shape[0] > 2 else Mode.B
    return m.name, m.value, m is Mode.A, (Flag.R | Flag.W) & Flag.W == Flag.W, [e.name for e in Mode], x * m.value


@prog("typing_and_isinstance_union")
def _(x):
    def f(v: int | torch.Tensor):
        return isinstance(v, (int, torch.Tensor)), isinstance(v, int | float)
    return f(x), f(3), f(1.5), type(x) is torch.Tensor, type(x).__mro__[1].__name__
