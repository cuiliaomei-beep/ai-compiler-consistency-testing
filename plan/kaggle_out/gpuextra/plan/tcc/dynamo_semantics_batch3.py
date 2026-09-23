"""Third batch of Dynamo python-semantics programs: generator protocol details, Tensor subclasses and
__torch_function__, weakref, threading.local, pickle round-trips, deepcopy of modules, descriptors,
__slots__ classes with tensors, metaclasses, class attributes vs instance attributes, iter protocol on
custom objects, augmented assignment on containers, chained comparisons with tensors, `id`/`is` semantics
after ops, string/bytes formatting of tensors, exception attributes (args, __notes__), int/bool subclass
handling, zip/enumerate of tensors with strict, sorted with cmp_to_key.
"""
import copy
import functools
import io
import pickle
import threading
import weakref

import torch

from .dynamo_semantics import PROGRAMS, STATE


def prog(name):
    def deco(f):
        PROGRAMS[name] = f
        return f
    return deco


# --- generator protocol ---
@prog("gen_return_value_stopiteration")
def _(x):
    def g():
        yield x * 1
        return 42
    it = g()
    first = next(it)
    try:
        next(it)
    except StopIteration as e:
        rv = e.value
    return first, rv


@prog("gen_throw")
def _(x):
    def g():
        try:
            yield x
        except ValueError:
            yield x * 100
    it = g()
    next(it)
    return it.throw(ValueError("v"))


@prog("gen_expression_lazy_side_effect")
def _(x):
    log = []
    gen = (log.append(i) or x * i for i in range(3))
    before = len(log)
    lst = list(gen)
    return before, len(log), lst


@prog("nested_generator_closure_var")
def _(x):
    k = 2
    def outer():
        for i in range(2):
            yield from (x * (i + j) * k for j in range(2))
    return list(outer())


@prog("iter_protocol_custom_object")
def _(x):
    class Rows:
        def __init__(self, t):
            self.t = t
        def __iter__(self):
            for i in range(self.t.shape[0]):
                yield self.t[i]
        def __len__(self):
            return self.t.shape[0]
        def __reversed__(self):
            return iter(self.t.flip(0).unbind(0))
    r = Rows(x)
    return list(r)[0], len(r), list(reversed(r))[0], [a.sum() for a in r]


# --- Tensor subclasses / __torch_function__ ---
@prog("tensor_subclass_torch_function")
def _(x):
    class Scaled(torch.Tensor):
        @classmethod
        def __torch_function__(cls, func, types, args=(), kwargs=None):
            kwargs = kwargs or {}
            STATE["log"].append(getattr(func, "__name__", str(func)))
            out = super().__torch_function__(func, types, args, kwargs)
            return out
    s = x.as_subclass(Scaled)
    y = s * 2 + 1
    return type(y).__name__, y.sum().item(), len(STATE["log"]) > 0


@prog("torch_function_mode")
def _(x):
    from torch.overrides import TorchFunctionMode
    class Count(TorchFunctionMode):
        def __torch_function__(self, func, types, args=(), kwargs=None):
            STATE["count"] += 1
            return func(*args, **(kwargs or {}))
    with Count():
        y = x * 2 + 1
    return y, STATE["count"]


@prog("parameter_subclass_attrs")
def _(x):
    p = torch.nn.Parameter(x.clone())
    return isinstance(p, torch.nn.Parameter), p.requires_grad, type(p * 2).__name__, (p * 2).requires_grad, repr(type(p))


# --- weakref / threading / pickle / deepcopy ---
@prog("weakref_to_object")
def _(x):
    class Holder:
        pass
    h = Holder()
    h.t = x
    r = weakref.ref(h)
    alive = r() is h
    d = weakref.WeakValueDictionary()
    d["k"] = h
    return alive, "k" in d, r().t.sum()


@prog("threading_local_state")
def _(x):
    loc = STATE.setdefault("tl", threading.local())
    loc.n = getattr(loc, "n", 0) + 1
    return x * loc.n, loc.n


@prog("pickle_roundtrip_tensor")
def _(x):
    buf = io.BytesIO()
    torch.save(x, buf)
    buf.seek(0)
    y = torch.load(buf)
    z = pickle.loads(pickle.dumps({"a": x.shape, "b": 3}))
    return torch.equal(x, y), z


@prog("deepcopy_nested_containers_with_tensors")
def _(x):
    d = {"a": [x, (x * 2, {"c": x * 3})]}
    e = copy.deepcopy(d)
    e["a"][0].add_(1)
    return torch.equal(d["a"][0], x), e["a"][1][1]["c"] is d["a"][1][1]["c"], e["a"][0].sum() - x.sum()


@prog("deepcopy_module_forward")
def _(x):
    m = torch.nn.Sequential(torch.nn.Linear(4, 4), torch.nn.ReLU())
    m2 = copy.deepcopy(m)
    with torch.no_grad():
        m2[0].weight.zero_()
    return torch.equal(m(x), m2(x)), (m2(x) - m2[0].bias.clamp_min(0)).abs().max() < 1e-6


# --- descriptors / metaclasses / class attributes ---
@prog("descriptor_property_cached")
def _(x):
    class Lazy:
        def __init__(self, t):
            self.t = t
            self.calls = 0
        @functools.cached_property
        def double(self):
            self.calls += 1
            return self.t * 2
    o = Lazy(x)
    a = o.double
    b = o.double
    return a is b, o.calls, a.sum()


@prog("class_attr_vs_instance_attr")
def _(x):
    class C:
        scale = 2
        items = []
        def __init__(self):
            self.own = []
    c1, c2 = C(), C()
    c1.items.append(1)
    c1.own.append(1)
    c2.scale = 5
    return len(c2.items), len(c2.own), C.scale, c2.scale, x * c1.scale, x * c2.scale


@prog("metaclass_and_init_subclass")
def _(x):
    registry = []
    class Base:
        def __init_subclass__(cls, **kw):
            registry.append(cls.__name__)
    class A(Base):
        pass
    class B(A):
        pass
    return registry, x * len(registry), B.__mro__[1].__name__


@prog("dunder_getitem_setitem_delitem")
def _(x):
    class Store:
        def __init__(self):
            self.d = {}
        def __getitem__(self, k):
            return self.d.get(k, x * 0)
        def __setitem__(self, k, v):
            self.d[k] = v
        def __delitem__(self, k):
            del self.d[k]
        def __contains__(self, k):
            return k in self.d
    s = Store()
    s["a"] = x
    s["b"] = x * 2
    del s["a"]
    return s["a"], s["b"], "a" in s, "b" in s, len(s.d)


@prog("augmented_assign_containers")
def _(x):
    lst = [x]
    lst += [x * 2]
    t = (1,)
    t += (2,)
    d = {"a": 1}
    d |= {"b": 2}
    s = {1}
    s |= {2}
    y = x.clone()
    y += 1
    y *= 2
    return len(lst), t, d, sorted(s), y


@prog("chained_comparison_tensor_scalar")
def _(x):
    v = x[0, 0]
    return (0.0 < v.item() < 100.0, bool((v > -100) & (v < 100)), torch.where(x > 0, x, -x).min() >= 0, (x == x).all().item())


@prog("identity_after_ops")
def _(x):
    y = x.view(-1).view(x.shape)
    z = x + 0
    w = x.contiguous()
    v = x[:]
    return y is x, z is x, w is x, v is x, y.data_ptr() == x.data_ptr(), v.data_ptr() == x.data_ptr()


@prog("exception_args_and_notes")
def _(x):
    try:
        raise ValueError("a", 1, x.shape[0])
    except ValueError as e:
        e.add_note("note1")
        return e.args, e.__notes__, str(e)


@prog("int_bool_subclass_handling")
def _(x):
    class MyInt(int):
        pass
    n = MyInt(2)
    return x * n, isinstance(n, int), type(n + 1).__name__, x[True.__index__()].shape, x * True


@prog("zip_enumerate_strict_tensors")
def _(x):
    out = []
    for i, (a, b) in enumerate(zip(x, x * 2, strict=True)):
        out.append((i, (a + b).sum()))
    try:
        list(zip(x, x[:2], strict=True))
        err = None
    except ValueError as e:
        err = type(e).__name__
    return out, err


@prog("sorted_cmp_to_key")
def _(x):
    vals = [x[i].sum().item() for i in range(x.shape[0])]
    order = sorted(range(len(vals)), key=functools.cmp_to_key(lambda i, j: (vals[i] > vals[j]) - (vals[i] < vals[j])))
    return order, x[order]


@prog("string_format_tensor_repr")
def _(x):
    t = x[0, 0]
    return f"{t}", f"{t:.2f}" if False else str(t.item())[:6], f"{x.shape}", "%s" % (x.dtype,), f"{t!r}"[:12]


@prog("bytes_from_tensor")
def _(x):
    b = x.numpy().tobytes()
    y = torch.frombuffer(bytearray(b), dtype=torch.float32).reshape(x.shape)
    return len(b), torch.equal(x, y)


@prog("nonlocal_generator_state_machine")
def _(x):
    state = {"n": 0}
    def step():
        while True:
            state["n"] += 1
            yield x * state["n"]
    it = step()
    a = next(it)
    b = next(it)
    return a, b, state["n"]


@prog("list_of_lambdas_dispatch_on_shape")
def _(x):
    table = [lambda t: t.sum(), lambda t: t.mean(), lambda t: t.amax()]
    return table[x.shape[0] % 3](x), [f(x) for f in table[::-1]]


@prog("try_except_else_finally_order")
def _(x):
    order = []
    try:
        order.append("try")
        y = x * 2
    except Exception:
        order.append("except")
    else:
        order.append("else")
    finally:
        order.append("finally")
    return y, order


@prog("with_multiple_context_managers")
def _(x):
    class Ctx:
        def __init__(self, n):
            self.n = n
        def __enter__(self):
            STATE["log"].append(f"in{self.n}")
            return self.n
        def __exit__(self, *a):
            STATE["log"].append(f"out{self.n}")
    with Ctx(1) as a, Ctx(2) as b:
        y = x * (a + b)
    return y, list(STATE["log"])


@prog("global_dict_mutation_across_calls")
def _(x):
    STATE["d"].setdefault("hits", 0)
    STATE["d"]["hits"] += 1
    STATE["d"]["last"] = x.sum().item()
    return dict(STATE["d"])


@prog("tensor_in_set_and_dict_key_identity")
def _(x):
    y = x
    z = x.clone()
    s = {x, y, z}
    d = {x: "x"}
    d[z] = "z"
    return len(s), len(d), d[y]


@prog("callable_module_list_in_loop")
def _(x):
    mods = torch.nn.ModuleList([torch.nn.Linear(4, 4) for _ in range(3)])
    y = x
    for i, m in enumerate(mods):
        if i == 1:
            continue
        y = m(y)
    return y.shape, len(mods), mods[-1].weight.shape


@prog("dict_comprehension_with_tensor_values_sorted")
def _(x):
    d = {f"k{i}": x[i].sum() for i in range(x.shape[0])}
    top = sorted(d.items(), key=lambda kv: kv[1].item(), reverse=True)[:2]
    return [k for k, _ in top], sum(d.values())
