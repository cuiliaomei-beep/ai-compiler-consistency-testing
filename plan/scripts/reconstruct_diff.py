"""12.6  Reconstruction differential: a compiled function (backend=eager) returns a Python object that Dynamo has to
*reconstruct* from its VariableTracker (iterators, generators, range, functools.partial, itertools objects, dict views,
namedtuples, exceptions, slices, ...).  For each object we compare, eager vs compiled: type(), repr-shape, remaining
behaviour (list(), len(), attribute access, calling), and identity where eager returns the input object itself.
The 41-draft mechanism (generator -> tuple_iterator) is one instance; this script asks the same question of every
reconstruct() path.
    python scripts/reconstruct_diff.py            -> results/reconstruct/cases.jsonl
"""
import collections
import functools
import itertools
import json
import operator
import os
import sys
import tempfile
import types

os.environ.setdefault("TORCHINDUCTOR_CACHE_DIR", tempfile.mkdtemp(prefix="tcc_rc_"))
sys.path.insert(0, os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
from tcc.compat import ensure_msvc_env  # noqa: E402

ensure_msvc_env()
import torch  # noqa: E402

torch._dynamo.config.recompile_limit = 10 ** 4
Point = collections.namedtuple("Point", "x y")
CASES = {}


def case(f):
    CASES[f.__name__] = f
    return f


# ---- each case: f(x, obj) -> object to inspect; `obj` is a pre-existing input so identity can be checked --------
@case
def ret_range(x, obj): return range(int(x.shape[0]), 10, 2)
@case
def ret_range_iter(x, obj): return iter(range(int(x.shape[0]), 10, 2))
@case
def ret_enumerate(x, obj): return enumerate([x, x * 2], start=3)
@case
def ret_zip(x, obj): return zip([x, x * 2], "ab", strict=False)
@case
def ret_map(x, obj): return map(lambda t: t.sum(), [x, x * 2])
@case
def ret_filter(x, obj): return filter(lambda t: t.sum() > 0, [x, -x])
@case
def ret_reversed(x, obj): return reversed([x, x * 2, x * 3])
@case
def ret_list_iter_partial(x, obj):
    it = iter([x, x * 2, x * 3]); next(it); return it
@case
def ret_tuple_iter(x, obj): return iter((x, 1, "s"))
@case
def ret_dict_keys(x, obj): return {"a": x, "b": 2}.keys()
@case
def ret_dict_values(x, obj): return {"a": x, "b": 2}.values()
@case
def ret_dict_items(x, obj): return {"a": x, "b": 2}.items()
@case
def ret_dict_iter(x, obj): return iter({"a": x, "b": 2})
@case
def ret_input_dict_keys(x, obj): return obj.keys()
@case
def ret_str_iter(x, obj): return iter("abc")
@case
def ret_genexpr(x, obj): return (t * 2 for t in [x, x + 1])
@case
def ret_generator_with_return(x, obj):
    def g():
        yield x
        return 7
    return g()
@case
def ret_itertools_count(x, obj): return itertools.count(int(x.shape[0]))
@case
def ret_itertools_chain(x, obj): return itertools.chain([x], [x * 2])
@case
def ret_itertools_islice(x, obj): return itertools.islice([x, x * 2, x * 3], 2)
@case
def ret_itertools_repeat(x, obj): return itertools.repeat(x, 3)
@case
def ret_itertools_accumulate(x, obj): return itertools.accumulate([1, 2, 3])
@case
def ret_itertools_product(x, obj): return itertools.product([1, 2], "ab")
@case
def ret_itertools_cycle_islice(x, obj): return itertools.islice(itertools.cycle([x, x * 2]), 5)
@case
def ret_itertools_groupby(x, obj): return itertools.groupby([1, 1, 2])
@case
def ret_itertools_tee(x, obj): return itertools.tee([x, x * 2])[0]
@case
def ret_itertools_zip_longest(x, obj): return itertools.zip_longest([x], [1, 2])
@case
def ret_partial(x, obj): return functools.partial(torch.add, x, alpha=2)
@case
def ret_partial_of_partial(x, obj): return functools.partial(functools.partial(torch.add, alpha=2), x)
@case
def ret_lambda_closure(x, obj):
    k = x.shape[0]
    return lambda t: t * k
@case
def ret_nested_def(x, obj):
    def inner(t, m=x.sum()):
        return t + m
    return inner
@case
def ret_bound_method(x, obj): return x.add
@case
def ret_builtin_method_of_list(x, obj): return [x].append
@case
def ret_operator_itemgetter(x, obj): return operator.itemgetter(1)
@case
def ret_operator_methodcaller(x, obj): return operator.methodcaller("sum")
@case
def ret_slice(x, obj): return slice(1, int(x.shape[0]), 2)
@case
def ret_namedtuple(x, obj): return Point(x, x * 2)
@case
def ret_namedtuple_from_method(x, obj): return Point(1, 2)._replace(x=x)
@case
def ret_defaultdict(x, obj):
    d = collections.defaultdict(list); d["k"].append(x); return d
@case
def ret_counter(x, obj): return collections.Counter("abca")
@case
def ret_ordereddict(x, obj):
    d = collections.OrderedDict(a=x, b=2); d.move_to_end("a"); return d
@case
def ret_deque(x, obj): return collections.deque([x, 1], maxlen=3)
@case
def ret_chainmap(x, obj): return collections.ChainMap({"a": x}, {"b": 1})
@case
def ret_frozenset(x, obj): return frozenset({1, 2, int(x.shape[0])})
@case
def ret_set(x, obj): return {1, 2, int(x.shape[0])}
@case
def ret_bytes_bytearray(x, obj): return bytes([1, 2]), bytearray(b"ab")
@case
def ret_exception_instance(x, obj):
    try:
        raise ValueError("boom", int(x.shape[0]))
    except ValueError as e:
        return e
@case
def ret_exception_with_cause(x, obj):
    try:
        try:
            raise KeyError("k")
        except KeyError as e:
            raise ValueError("v") from e
    except ValueError as e2:
        return e2
@case
def ret_exception_class(x, obj): return ValueError
@case
def ret_type_object(x, obj): return type(x), torch.float32, torch.Size([2, 3])
@case
def ret_torch_size_iter(x, obj): return iter(x.shape)
@case
def ret_torch_device_dtype(x, obj): return x.device, x.dtype, x.layout
@case
def ret_tensor_iter(x, obj): return iter(x)
@case
def ret_module_children(x, obj): return torch.nn.Sequential(torch.nn.ReLU(), torch.nn.Tanh()).children()
@case
def ret_module_named_params(x, obj): return torch.nn.Linear(2, 2).named_parameters()
@case
def ret_input_object_identity(x, obj): return obj
@case
def ret_input_object_in_tuple(x, obj): return (obj, x + 1)
@case
def ret_input_list_after_append(x, obj):
    lst = obj["lst"]; lst.append(x); return lst
@case
def ret_new_class_instance(x, obj):
    class C:
        def __init__(self, v): self.v = v
        def get(self): return self.v * 2
    return C(x)
@case
def ret_dataclass_like(x, obj):
    import dataclasses
    @dataclasses.dataclass
    class D:
        a: object
        b: int = 3
    return D(x)
@case
def ret_property_object(x, obj): return property(lambda s: 1)
@case
def ret_staticmethod_obj(x, obj): return staticmethod(lambda: 1)
@case
def ret_super_object(x, obj):
    class A:
        def f(self): return 1
    class B(A):
        def f(self): return super()
    return B().f()
@case
def ret_weakref(x, obj):
    import weakref
    return weakref.ref(obj["holder"])
@case
def ret_memoryview(x, obj): return memoryview(b"abc")
@case
def ret_random_instance(x, obj):
    import random
    return random.Random(0)
@case
def ret_contextmanager_obj(x, obj): return torch.no_grad()
@case
def ret_autograd_function_ctx(x, obj): return torch.autograd.grad_mode.set_grad_enabled(False)
@case
def ret_str_methods(x, obj): return "a,b".split, "abc".upper()
@case
def ret_int_big(x, obj): return 2 ** 70, -(2 ** 70), 1 << int(x.shape[0])
@case
def ret_float_special(x, obj): return float("nan"), float("inf"), -0.0
@case
def ret_complex_scalar(x, obj): return 1 + 2j
@case
def ret_ellipsis_notimplemented(x, obj): return Ellipsis, NotImplemented, None
@case
def ret_sorted_iter(x, obj): return iter(sorted([3, 1, 2]))
@case
def ret_list_reverseiter(x, obj): return reversed([1, 2, 3])
@case
def ret_dict_reverse(x, obj): return reversed({"a": 1, "b": 2})
@case
def ret_enumerate_of_iter(x, obj): return enumerate(iter([x, 1]))
@case
def ret_exhausted_iter(x, obj):
    it = iter([x]); next(it); return it
@case
def ret_generator_partially_consumed(x, obj):
    def g():
        yield x
        yield x * 2
        yield x * 3
    it = g(); next(it); return it


class Holder:
    pass


def probe(o):
    """Observable description of an object: type, remaining behaviour, key attributes."""
    d = {"type": type(o).__name__}
    try:
        d["repr"] = repr(o)[:60] if not isinstance(o, (types.GeneratorType, functools.partial)) else "<skip>"
    except Exception as ex:  # noqa: BLE001
        d["repr"] = f"repr raises {type(ex).__name__}"
    if isinstance(o, tuple) and not hasattr(o, "_fields"):
        d["items"] = [probe(i) for i in o]
        return d
    for attr in ("__len__", "send", "throw", "close", "gi_frame", "args", "__cause__", "func", "keywords", "start", "stop", "step", "maxlen", "_fields", "default_factory", "__name__", "__self__"):
        if hasattr(o, attr):
            v = getattr(o, attr)
            try:
                d[attr] = "callable" if callable(v) and attr not in ("func", "__self__") else (repr(v)[:40] if not isinstance(v, torch.Tensor) else f"T{tuple(v.shape)}")
            except Exception as ex:  # noqa: BLE001
                d[attr] = f"raises {type(ex).__name__}"
    if isinstance(o, BaseException):
        d["exc_args"] = [str(a)[:30] for a in o.args]
        d["cause"] = type(o.__cause__).__name__ if o.__cause__ else None
        d["context"] = type(o.__context__).__name__ if o.__context__ else None
    try:
        if hasattr(o, "__iter__") and not isinstance(o, (str, bytes, torch.Tensor, dict)) and not isinstance(o, types.ModuleType):
            items = []
            it = iter(o)
            for _ in range(8):
                try:
                    v = next(it)
                except StopIteration as e:
                    d["stop_value"] = repr(e.value)[:30]
                    break
                items.append(f"T{tuple(v.shape)}" if isinstance(v, torch.Tensor) else (repr(v)[:30] if not isinstance(v, tuple) else str([f"T{tuple(w.shape)}" if isinstance(w, torch.Tensor) else repr(w)[:15] for w in v])))
            d["first_items"] = items
        if isinstance(o, dict):
            d["dict_items"] = [(str(k)[:20], f"T{tuple(v.shape)}" if isinstance(v, torch.Tensor) else repr(v)[:20]) for k, v in o.items()]
    except Exception as ex:  # noqa: BLE001
        d["iter_error"] = type(ex).__name__
    if callable(o) and not isinstance(o, type):
        x = torch.ones(2, 3)
        for args in ((), (x,), (x, x)):
            try:
                r = o(*args)
                d[f"call{len(args)}"] = f"T{tuple(r.shape)}" if isinstance(r, torch.Tensor) else repr(r)[:30]
                break
            except Exception as ex:  # noqa: BLE001
                d[f"call{len(args)}"] = f"raises {type(ex).__name__}"
    return d


def main():
    os.makedirs("results/reconstruct", exist_ok=True)
    out = open("results/reconstruct/cases.jsonl", "w", encoding="utf-8")
    n_diff = 0
    print("torch", torch.__version__, flush=True)
    for name, f in CASES.items():
        def mk():
            h = Holder(); return {"lst": [1], "holder": h, "k": 1}
        x = torch.ones(2, 3)
        obj_e, obj_c = mk(), mk()
        try:
            e = f(x, obj_e); pe = probe(e); ide = (e is obj_e) or (isinstance(e, tuple) and any(i is obj_e for i in e)) or (e is obj_e.get("lst") if isinstance(e, list) else False)
        except Exception as ex:  # noqa: BLE001
            pe, ide = {"raises": type(ex).__name__}, None
        torch._dynamo.reset()
        try:
            c = torch.compile(f, backend="eager")(x, obj_c); pc = probe(c); idc = (c is obj_c) or (isinstance(c, tuple) and any(i is obj_c for i in c)) or (c is obj_c.get("lst") if isinstance(c, list) else False)
        except Exception as ex:  # noqa: BLE001
            pc, idc = {"raises": f"{type(ex).__name__}: {str(ex)[:80]}"}, None
        diffs = {k: (pe.get(k), pc.get(k)) for k in set(pe) | set(pc) if pe.get(k) != pc.get(k)}
        if ide != idc:
            diffs["identity"] = (ide, idc)
        rec = {"case": name, "eager": pe, "compiled": pc, "diff": {k: list(v) for k, v in diffs.items()}}
        out.write(json.dumps(rec, default=str) + "\n"); out.flush()
        if diffs:
            n_diff += 1
            loud = "raises" in pc
            print(f"{'LOUD ' if loud else 'DIFF '}{name:36s} {json.dumps({k: list(v) for k, v in diffs.items()}, default=str)[:260]}", flush=True)
    print(f"DONE: {n_diff}/{len(CASES)} cases differ", flush=True)


if __name__ == "__main__":
    main()
