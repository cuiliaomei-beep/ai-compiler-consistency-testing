"""Fifth batch (2026-09-22): exception semantics around errors RAISED BY TENSOR OPS (batch 4 found that a fake-tensor
IndexError skips the user's handler, #198192).  Every program here provokes a tensor-op error of some type inside a
Python construct that must observe it: except clauses of various types / tuples / bases, except-as attribute access,
finally ordering, contextlib.suppress, __exit__ swallowing, re-raise, raise-from, exception in loops / comprehensions /
nested calls / generators / lambdas, assert on tensor, torch._check, sys.exc_info, warnings, custom exception carrying
a tensor, `except*` groups, and errors of types other than RuntimeError (IndexError, TypeError, ValueError,
NotImplementedError, ZeroDivisionError from tensor.item()).
Every program: f(x) -> anything; may mutate STATE; may raise.
"""
import contextlib
import sys
import warnings

import torch

from .dynamo_semantics import PROGRAMS, STATE


def prog(name):
    def deco(f):
        PROGRAMS[name] = f
        return f
    return deco


# --- IndexError-family tensor errors inside handlers of different shapes ----------------------------------------
@prog("exc_index_caught_as_Exception")
def _(x):
    try:
        return x[10]
    except Exception as e:
        return type(e).__name__, x + 1


@prog("exc_index_caught_as_LookupError")
def _(x):
    try:
        return x.select(0, 10)
    except LookupError as e:
        return type(e).__name__, str(e)[:20]


@prog("exc_index_caught_by_tuple")
def _(x):
    try:
        return x.sum(dim=5)
    except (KeyError, IndexError, RuntimeError) as e:
        return type(e).__name__


@prog("exc_index_uncaught_wrong_type")
def _(x):
    try:
        return x.transpose(0, 7)
    except ValueError:
        return "wrong handler"


@prog("exc_index_in_nested_call")
def _(x):
    def inner(t):
        return t.softmax(dim=6)
    try:
        return inner(x)
    except IndexError:
        return "caught in caller", x * 2


@prog("exc_index_in_loop_continue")
def _(x):
    out = []
    for d in (0, 1, 5, -1):
        try:
            out.append(x.sum(dim=d).sum())
        except IndexError:
            out.append("bad dim")
            continue
    return out


@prog("exc_index_in_comprehension")
def _(x):
    def safe(d):
        try:
            return x.sum(dim=d).sum()
        except IndexError:
            return None
    return [safe(d) for d in (0, 1, 9)]


@prog("exc_index_in_generator_consumer")
def _(x):
    def gen():
        for d in (0, 9, 1):
            yield x.mean(dim=d).sum()
    out = []
    it = gen()
    while True:
        try:
            out.append(next(it))
        except IndexError:
            out.append("gen raised")
        except StopIteration:
            break
    return out


@prog("exc_index_then_finally_order")
def _(x):
    try:
        try:
            return x.chunk(2, dim=6)
        finally:
            STATE["log"].append("finally")
    except IndexError:
        STATE["log"].append("except")
        return list(STATE["log"])


@prog("exc_index_reraise_as_custom")
def _(x):
    class ShapeProblem(Exception):
        pass
    try:
        try:
            return x.squeeze(9)
        except IndexError as e:
            raise ShapeProblem(str(e)[:15]) from e
    except ShapeProblem as e2:
        return "custom", type(e2.__cause__).__name__


@prog("exc_index_reraise_bare")
def _(x):
    try:
        try:
            return x.flatten(3)
        except IndexError:
            STATE["count"] += 1
            raise
    except IndexError:
        return "outer", STATE["count"]


@prog("exc_index_suppress")
def _(x):
    with contextlib.suppress(IndexError):
        return x.index_select(5, torch.tensor([0]))
    return "suppressed", x + 1


@prog("exc_index_exit_swallows")
def _(x):
    class Swallow:
        def __enter__(self):
            return self
        def __exit__(self, et, ev, tb):
            STATE["log"].append(et.__name__ if et else "none")
            return True
    with Swallow():
        return x[100]
    return "swallowed", list(STATE["log"])


@prog("exc_index_else_branch")
def _(x):
    try:
        y = x.unsqueeze(7)
    except IndexError:
        y = x.unsqueeze(0)
    else:
        y = y * 100
    return y.shape


@prog("exc_index_sys_exc_info")
def _(x):
    try:
        return x.narrow(5, 0, 1)
    except Exception:
        et, ev, tb = sys.exc_info()
        return et.__name__, tb is not None


@prog("exc_index_message_kept")
def _(x):
    try:
        return x.sum(dim=3)
    except IndexError as e:
        return "Dimension out of range" in str(e), e.args[0][:24]


# --- other exception types raised by tensor ops ----------------------------------------------------------------
@prog("exc_type_error_tensor_plus_str")
def _(x):
    try:
        return x + "s"
    except TypeError:
        return "TypeError", x + 1


@prog("exc_type_error_bad_dtype_kwarg")
def _(x):
    try:
        return x.to(dtype="float99")
    except TypeError:
        return "TypeError", x + 1


@prog("exc_not_implemented_bitwise_float")
def _(x):
    try:
        return x & x
    except (NotImplementedError, RuntimeError) as e:
        return type(e).__name__


@prog("exc_zero_division_item")
def _(x):
    try:
        return 1.0 / (x.sum() * 0).item()
    except ZeroDivisionError:
        return "ZeroDivisionError", x + 1


@prog("exc_value_error_from_op")
def _(x):
    try:
        return torch.cat([])
    except (ValueError, RuntimeError) as e:
        return type(e).__name__


@prog("exc_runtime_bool_ambiguous")
def _(x):
    try:
        if x:
            return 1
    except RuntimeError:
        return "RuntimeError", x + 1


@prog("exc_runtime_shape_mismatch_handler_then_index")
def _(x):
    try:
        torch.cat([x, x.t()])
    except RuntimeError:
        try:
            return x[10]
        except IndexError:
            return "inner index caught"


@prog("exc_index_from_python_list_vs_tensor")
def _(x):
    out = []
    for obj in ([1, 2], x):
        try:
            out.append(obj[10])
        except IndexError:
            out.append(f"{type(obj).__name__} IndexError")
    return out


@prog("exc_key_error_dict_vs_index_tensor")
def _(x):
    d = {"a": x}
    try:
        d["b"]
    except KeyError:
        try:
            return x[7]
        except IndexError:
            return "both caught"


@prog("exc_assert_on_tensor_shape")
def _(x):
    try:
        assert x.shape[0] == 99, "bad batch"
    except AssertionError as e:
        return str(e), x + 1


@prog("exc_torch_check_message")
def _(x):
    try:
        torch._check(x.shape[0] == 99, lambda: "batch must be 99")
    except RuntimeError as e:
        return str(e)[:17]


@prog("exc_warning_then_index")
def _(x):
    with warnings.catch_warnings(record=True) as w:
        warnings.simplefilter("always")
        warnings.warn("careful")
        try:
            return x.sum(dim=4)
        except IndexError:
            return len(w), x + 1


@prog("exc_custom_carries_tensor")
def _(x):
    class TensorError(Exception):
        def __init__(self, t):
            super().__init__("bad")
            self.t = t
    try:
        raise TensorError(x * 2)
    except TensorError as e:
        return e.t.sum(), e.args


@prog("exc_group_except_star")
def _(x):
    try:
        raise ExceptionGroup("g", [IndexError("i"), ValueError("v")])
    except* IndexError as eg:
        STATE["log"].append(len(eg.exceptions))
    except* ValueError as eg:
        STATE["log"].append(-len(eg.exceptions))
    return list(STATE["log"]), x + 1


@prog("exc_index_lambda_in_map")
def _(x):
    def safe(d):
        try:
            return x.sum(dim=d).sum()
        except IndexError:
            return -1
    return list(map(safe, [0, 1, 8]))


@prog("exc_index_after_graph_break_pattern")
def _(x):
    y = x * 2
    STATE["log"].append("mid")
    try:
        return y.sum(dim=5)
    except IndexError:
        return "caught after effect", list(STATE["log"])


@prog("exc_index_in_with_no_grad")
def _(x):
    with torch.no_grad():
        try:
            return x.select(1, 40)
        except IndexError:
            return "caught in no_grad", torch.is_grad_enabled()
