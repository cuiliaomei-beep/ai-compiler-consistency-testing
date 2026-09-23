"""Fourth batch (2026-09-22) of Dynamo python-semantics programs, written for the metamorphic-relation sweeps
(scripts/graph_break_insertion_diff.py): structures the first three batches had few of -- with / try / finally /
else flows with tensor work inside, generator protocol driven from the consumer (send / throw / close / yield from
with return values), contextlib-based context managers with state, for-else / while-else, walrus, match,
nonlocal, ordering-sensitive container operations on *input* objects (OrderedDict / deque / list / dict / set),
lazy builtins with side effects (map / filter / any / all short-circuit), exception chaining and notes,
lru_cache, heapq / bisect, dataclass ordering, star-unpacking of tensors.
Every program: f(x) -> anything; may mutate STATE; may raise.
"""
import bisect
import collections
import contextlib
import functools
import heapq
import itertools
import operator

import torch

from .dynamo_semantics import PROGRAMS, STATE


def prog(name):
    def deco(f):
        PROGRAMS[name] = f
        return f
    return deco


# --- context managers -----------------------------------------------------------------------------------------
@prog("cm_contextlib_generator_state")
def _(x):
    @contextlib.contextmanager
    def scope(tag):
        STATE["log"].append(f"enter:{tag}")
        try:
            yield x * 2
        finally:
            STATE["log"].append(f"exit:{tag}")
    with scope("a") as y, scope("b") as z:
        r = y + z
    return r, list(STATE["log"])


@prog("cm_swallows_exception")
def _(x):
    class Quiet:
        def __enter__(self):
            STATE["count"] += 1
            return self
        def __exit__(self, et, ev, tb):
            STATE["log"].append(et.__name__ if et else "none")
            return et is ValueError
    with Quiet():
        y = x * 3
        raise ValueError("swallowed")
    return y.sum(), STATE["log"]


@prog("cm_exit_sees_tensor_error")
def _(x):
    class Rec:
        def __enter__(self):
            return x + 1
        def __exit__(self, et, ev, tb):
            STATE["log"].append(et.__name__ if et else "none")
            return False
    try:
        with Rec() as y:
            return bool(y)  # RuntimeError: ambiguous
    except RuntimeError:
        return "caught", STATE["log"]


@prog("cm_exitstack_callbacks_order")
def _(x):
    with contextlib.ExitStack() as st:
        for i in range(3):
            st.callback(STATE["log"].append, f"cb{i}")
        y = x * (i + 1)
    return y, list(STATE["log"])


@prog("cm_nested_no_grad_enable_grad")
def _(x):
    x = x.clone().requires_grad_(True)
    with torch.no_grad():
        a = x * 2
        with torch.enable_grad():
            b = x * 3
        c = x * 4
    return a.requires_grad, b.requires_grad, c.requires_grad, (b.sum()).requires_grad


@prog("cm_suppress_and_continue")
def _(x):
    out = []
    for i in range(3):
        with contextlib.suppress(ZeroDivisionError):
            out.append(x / (i - 1))
            out.append(1 / (i - 1))
    return out


# --- try / except / else / finally with tensor work -------------------------------------------------------------
@prog("try_else_finally_flow")
def _(x):
    try:
        y = x * 2
    except RuntimeError:
        y = x
    else:
        y = y + 1
    finally:
        STATE["count"] += 1
    return y, STATE["count"]


@prog("try_finally_overrides_return")
def _(x):
    def f():
        try:
            return x * 2
        finally:
            STATE["log"].append("fin")
    return f(), STATE["log"]


@prog("try_reraise_with_chain")
def _(x):
    try:
        try:
            torch.cat([x, x.t()])
        except RuntimeError as e:
            raise ValueError("wrapped") from e
    except ValueError as e2:
        return type(e2.__cause__).__name__, e2.__suppress_context__, x + 1


@prog("try_exception_notes")
def _(x):
    try:
        raise KeyError("k")
    except KeyError as e:
        e.add_note("note1")
        e.add_note(str(x.shape))
        return e.__notes__, x * 2


@prog("try_in_loop_break_finally")
def _(x):
    acc = x * 0
    for i in range(5):
        try:
            if i == 3:
                break
            acc = acc + x * i
        finally:
            STATE["log"].append(i)
    return acc, list(STATE["log"])


@prog("try_error_in_except_handler")
def _(x):
    try:
        try:
            torch.cat([x, x.t()])
        except RuntimeError:
            return x[10]  # IndexError inside handler
    except IndexError as e:
        return "index", type(e.__context__).__name__


# --- generators driven from the consumer ------------------------------------------------------------------------
@prog("gen_send_running_mean")
def _(x):
    def avg():
        total, n = x * 0, 0
        while True:
            v = yield (total / n if n else None)
            if v is None:
                return n
            total, n = total + v, n + 1
    g = avg()
    next(g)
    outs = [g.send(x), g.send(x * 3)]
    try:
        g.send(None)
    except StopIteration as e:
        outs.append(e.value)
    return outs


@prog("gen_throw_handled_inside")
def _(x):
    def g():
        try:
            yield x * 1
        except ValueError:
            yield x * 100
        yield x * 1000
    it = g()
    next(it)
    a = it.throw(ValueError("v"))
    b = next(it)
    return a, b


@prog("gen_close_runs_finally")
def _(x):
    def g():
        try:
            yield x * 1
            yield x * 2
        finally:
            STATE["log"].append("closed")
    it = g()
    first = next(it)
    it.close()
    return first, list(STATE["log"])


@prog("gen_yield_from_return_value")
def _(x):
    def inner():
        yield x * 1
        return x.sum()
    def outer():
        r = yield from inner()
        yield r * 2
    return list(outer())


@prog("gen_partial_then_list")
def _(x):
    def g():
        for i in range(4):
            yield x * i
    it = g()
    next(it)
    rest = list(it)
    return len(rest), rest[-1]


@prog("gen_expr_lazy_side_effect")
def _(x):
    ge = (STATE["log"].append(i) or x * i for i in range(3))
    before = list(STATE["log"])
    first = next(ge)
    mid = list(STATE["log"])
    rest = list(ge)
    return before, mid, list(STATE["log"]), first, rest[-1]


@prog("gen_two_generators_interleaved")
def _(x):
    def g(k):
        for i in range(3):
            yield x * (i + k)
    a, b = g(0), g(10)
    return [next(a), next(b), next(a), next(b), next(a), next(b)]


@prog("gen_in_zip_strict_uneven")
def _(x):
    def g():
        yield x
        yield x * 2
    try:
        return list(zip(g(), [1, 2, 3], strict=True))
    except ValueError as e:
        return "strict", str(e)[:20]


# --- for / while else, walrus, match, nonlocal -----------------------------------------------------------------
@prog("for_else_no_break")
def _(x):
    for i in range(3):
        if x.shape[0] > 100:
            break
    else:
        return x * 7
    return x


@prog("while_else_with_break")
def _(x):
    i = 0
    while i < 5:
        i += 1
        if i == 2:
            break
    else:
        return "no-break"
    return "break", x * i


@prog("walrus_in_condition")
def _(x):
    if (n := x.shape[0] * 2) > 3:
        return n, x * n
    return n


@prog("match_statement_tensor_shape")
def _(x):
    match tuple(x.shape):
        case (3, 4):
            return x * 1
        case (r, c):
            return x * (r + c)
        case _:
            return x


@prog("match_class_pattern_namedtuple")
def _(x):
    P = collections.namedtuple("P", "a b")
    match P(x, 2):
        case P(a=t, b=2):
            return t * 2
        case _:
            return x


@prog("nonlocal_counter_in_closure")
def _(x):
    n = 0
    def bump(t):
        nonlocal n
        n += 1
        return t * n
    return bump(x), bump(x), n


@prog("closure_late_binding_in_loop")
def _(x):
    fs = [lambda t: t * i for i in range(3)]
    gs = [lambda t, i=i: t * i for i in range(3)]
    return [f(x)[0, 0] for f in fs], [g(x)[0, 0] for g in gs]


@prog("global_statement_counter")
def _(x):
    global _BATCH4_COUNTER
    _BATCH4_COUNTER = STATE["count"] + 1  # reset through STATE so eager and compiled runs start equal
    STATE["count"] = _BATCH4_COUNTER
    return x * _BATCH4_COUNTER, _BATCH4_COUNTER


# --- ordering-sensitive container operations on input / state objects -------------------------------------------
@prog("od_move_to_end_on_state")
def _(x):
    od = STATE["d"].setdefault("od", collections.OrderedDict([("z", 1), ("a", 2)]))
    od.move_to_end("z")
    return list(od), x + 1


@prog("od_move_to_end_then_iterate_later")
def _(x):
    od = collections.OrderedDict([("z", x), ("a", x * 2)])
    STATE["d"]["od2"] = od
    od.move_to_end("z")
    STATE["log"].append(list(od))
    return x + 1


@prog("deque_rotate_on_state")
def _(x):
    dq = STATE["d"].setdefault("dq", collections.deque([1, 2, 3]))
    dq.rotate(1)
    dq.appendleft(x.shape[0])
    return list(dq), x + 1


@prog("list_slice_assignment_on_state")
def _(x):
    lst = STATE["d"].setdefault("lst", [0, 1, 2, 3, 4])
    lst[1:3] = [9, 9, 9]
    lst[::2] = [7] * len(lst[::2])
    del lst[0]
    return list(lst), x + 1


@prog("list_sort_key_reverse_on_state")
def _(x):
    lst = STATE["d"].setdefault("lst2", [3, 1, 2])
    lst.sort(key=lambda v: -v)
    lst.insert(1, 10)
    lst.reverse()
    return list(lst), x * lst[0]


@prog("dict_pop_reinsert_order_on_state")
def _(x):
    d = STATE["d"].setdefault("dd", {"a": 1, "b": 2, "c": 3})
    d["a"] = d.pop("a")
    d.update(b=20)
    return list(d.items()), x + 1


@prog("set_ops_on_state")
def _(x):
    s = STATE["s"]
    s.update({1, 2, 3})
    s.discard(2)
    s ^= {3, 4}
    return sorted(s), x + 1


@prog("dict_views_reflect_mutation")
def _(x):
    d = {"a": x}
    ks = d.keys()
    d["b"] = x * 2
    return list(ks), len(ks), "b" in ks


@prog("heapq_bisect_on_state")
def _(x):
    h = STATE["d"].setdefault("heap", [])
    for v in (5, 1, 3):
        heapq.heappush(h, v)
    bl = STATE["d"].setdefault("bl", [1, 4, 9])
    bisect.insort(bl, 5)
    return heapq.heappop(h), list(h), list(bl), x + 1


@prog("counter_most_common_update")
def _(x):
    c = collections.Counter("abracadabra")
    c.update("aa")
    c.subtract("b")
    return c.most_common(2), x + c["a"]


# --- lazy builtins with side effects -------------------------------------------------------------------------
@prog("any_short_circuit_side_effect")
def _(x):
    def pred(i):
        STATE["log"].append(i)
        return i == 1
    r = any(pred(i) for i in range(5))
    return r, list(STATE["log"]), x + 1


@prog("all_short_circuit_map")
def _(x):
    def pred(i):
        STATE["log"].append(i)
        return i < 2
    r = all(map(pred, range(5)))
    return r, list(STATE["log"]), x + 1


@prog("filter_lazy_partial_consume")
def _(x):
    def pred(t):
        STATE["count"] += 1
        return t.sum() > 0
    it = filter(pred, [x, -x, x, -x])
    first = next(it)
    return first, STATE["count"]


@prog("sorted_stability_and_key_calls")
def _(x):
    calls = []
    def key(p):
        calls.append(p[0])
        return p[1]
    r = sorted([("a", 2), ("b", 1), ("c", 2), ("d", 1)], key=key)
    return [p[0] for p in r], len(calls), x + 1


@prog("min_max_with_key_default")
def _(x):
    return max([x, x * 2, x * -3], key=lambda t: t.sum()).sum(), min([], default=x.shape[0]), max(x.shape, default=0)


# --- lru_cache, itertools, operator -----------------------------------------------------------------------------
@prog("lru_cache_hits_and_info")
def _(x):
    @functools.lru_cache(maxsize=None)
    def f(n):
        STATE["count"] += 1
        return n * 2
    r = [f(1), f(2), f(1), f(2)]
    return r, STATE["count"], f.cache_info().hits, x + 1


@prog("itertools_groupby_tensor_keys")
def _(x):
    data = [(int(v) % 2, v) for v in x.flatten().abs().mul(10).long().tolist()]
    data.sort(key=operator.itemgetter(0))
    return [(k, len(list(g))) for k, g in itertools.groupby(data, key=operator.itemgetter(0))], x + 1


@prog("itertools_accumulate_tensors")
def _(x):
    return list(itertools.accumulate([x, x, x], operator.add))[-1], list(itertools.accumulate([1, 2, 3], initial=10))


@prog("operator_attrgetter_methodcaller")
def _(x):
    return operator.attrgetter("shape", "dtype")(x), operator.methodcaller("sum", 0)(x), operator.itemgetter(1, 0)([x, x * 2])[0]


# --- dataclass / class semantics ----------------------------------------------------------------------------------
@prog("dataclass_order_and_frozen")
def _(x):
    import dataclasses
    @dataclasses.dataclass(order=True, frozen=True)
    class V:
        k: int
        t: torch.Tensor = dataclasses.field(compare=False)
    a, b = V(1, x), V(2, x * 2)
    try:
        a.k = 5
    except dataclasses.FrozenInstanceError:
        frozen = True
    return a < b, sorted([b, a])[0].k, frozen, dataclasses.astuple(a)[0]


@prog("class_eq_hash_in_set_dict")
def _(x):
    class K:
        def __init__(self, v):
            self.v = v
        def __eq__(self, o):
            return isinstance(o, K) and self.v == o.v
        def __hash__(self):
            return hash(self.v)
    s = {K(1), K(1), K(2)}
    d = {K(1): x, K(1): x * 2}
    return len(s), len(d), d[K(1)]


@prog("property_setter_validates")
def _(x):
    class M:
        def __init__(self):
            self._s = 1.0
        @property
        def scale(self):
            return self._s
        @scale.setter
        def scale(self, v):
            if v < 0:
                raise ValueError("neg")
            self._s = v
    m = M()
    m.scale = 2.0
    try:
        m.scale = -1.0
    except ValueError:
        pass
    return x * m.scale, m.scale


@prog("slots_class_with_tensor")
def _(x):
    class S:
        __slots__ = ("t", "n")
        def __init__(self, t):
            self.t = t
            self.n = 0
    s = S(x)
    s.n += 1
    try:
        s.other = 1
    except AttributeError:
        ok = True
    return s.t * s.n, ok


# --- unpacking / misc builtins -------------------------------------------------------------------------------------
@prog("star_unpack_tensor_rows")
def _(x):
    first, *middle, last = x
    a, b = x[0, :2]
    return first + last, len(middle), a + b


@prog("divmod_round_abs_on_tensor")
def _(x):
    q, r = divmod(x * 10, 3)
    return q, r, round(x), abs(x), round(2.5), round(x.sum().item(), 1)


@prog("format_spec_tensor_items")
def _(x):
    v = x[0, 0].item()
    return f"{v:.3f}|{v!r:>12}|{x.shape[0]:03d}|{x.dtype}", format(x.sum().item(), ".2e")


@prog("chained_comparison_tensor_scalar")
def _(x):
    s = x.sum().item()
    return (0 < x.shape[0] <= 3), (s < s + 1 < s + 2), (x.shape[0] == 3 != 4)


@prog("del_local_then_use_raises")
def _(x):
    y = x * 2
    del y
    try:
        return y
    except UnboundLocalError:
        return "unbound", x + 1


@prog("augmented_assign_dict_attr_item")
def _(x):
    class O:
        pass
    o = O()
    o.v = x
    o.v += 1
    d = {"k": x}
    d["k"] *= 2
    lst = [x]
    lst[0] -= 1
    return o.v, d["k"], lst[0]
