"""Root-cause registry for the oracle-tier analysis (P1-2).

One entry per INDEPENDENT real root cause among the 58 pipeline-attributed report items of
paper_tcc/data/findings.csv (the 5 cross-compiler items and the 10 items attributed outside the
pipeline are excluded; comments are merged into their parent issue; items that the ledger says share
one root cause are merged).  Every entry carries the stand-alone reproducer taken from the first
```python block of the issue draft (0913issues/, 0920issues/), re-expressed as (fn, args) so that
scripts/oracle_tiers_real.py can run ONE eager and ONE compiled execution per sub-case in a child
process and capture every observable in a single trace.

A root cause may have several sub-cases (the draft's own list of triggering programs).  The first
sub-case marked ``primary`` is the minimal trigger; the others are the draft's additional members.
"""
from __future__ import annotations

import collections
import contextlib
import gc
import math
import operator
import os
import random
import sys
import tempfile
from dataclasses import dataclass, field
from typing import Any, Callable, Dict, List, Optional

import torch
import torch.nn.functional as F


@dataclass
class Case:
    fn: Callable
    args: tuple = ()
    kwargs: Optional[dict] = None
    #: a sequence of argument tuples: every call is observed (stale-cache / RNG root causes)
    calls: Optional[List[tuple]] = None
    #: module-level / closure state to snapshot after the call(s)
    state: Optional[Callable[[], Any]] = None
    #: applied to the raw output outside the compiled region before it is observed
    post: Optional[Callable[[Any], Any]] = None
    #: high-precision reference for the outputs (mpmath); receives the args, returns a list of float64 tensors
    ref: Optional[Callable[[tuple], list]] = None


@dataclass
class Sub:
    name: str
    make: Callable[[], Case]
    primary: bool = False
    compile: Dict[str, Any] = field(default_factory=dict)      # kwargs of torch.compile
    grad: bool = False                                          # compute gradients w.r.t. leaf inputs
    fp64: Optional[str] = "auto"                                # float64 reference ("auto" or None)
    has_handler: bool = False                                   # the program contains its own except handler
    pre: Optional[Callable[[str], None]] = None                 # setup on both sides (deterministic mode, ...)
    inductor_config: Dict[str, Any] = field(default_factory=dict)
    dynamo_config: Dict[str, Any] = field(default_factory=dict)
    #: fully custom runner: custom(R) -> list of R.record(inputs, outputs, exception, ...)
    custom: Optional[Callable] = None
    teardown: Optional[Callable[[], None]] = None               # runs after the trace is written (C46)
    note: str = ""


@dataclass
class RootCause:
    id: str
    members: List[str]
    layer: str
    reproducer: str
    title: str
    reproducible: bool = True
    reason: str = ""
    status: str = ""
    subs: List[Sub] = field(default_factory=list)


CASES: List[RootCause] = []


def rc(id, members, layer, reproducer, title, reproducible=True, reason="", status=""):
    r = RootCause(id, members, layer, reproducer, title, reproducible, reason, status)
    CASES.append(r)
    return r


def sub(r: RootCause, name, make, primary=False, **kw):
    r.subs.append(Sub(name, make, primary, **kw))


def by_id(i: str) -> RootCause:
    for r in CASES:
        if r.id == i:
            return r
    raise KeyError(i)


# ---------------------------------------------------------------------------------------------
# round 1 (0913issues)
# ---------------------------------------------------------------------------------------------

r = rc("B2", ["B2"], "Dy", "0913issues/02-dynamo-random-shuffle-sample-frozen.md",
       "random.shuffle / sample return the same permutation on every call", status="fixed")


def _b2_shuffle():
    def shuffle_fn(x):
        lst = [1, 2, 3, 4, 5]
        random.shuffle(lst)
        return x + lst[0], lst
    return Case(shuffle_fn, calls=[(torch.zeros(1),) for _ in range(3)])


def _b2_sample():
    def sample_fn(x):
        s = random.sample(range(100), 2)
        return x + s[0], s
    return Case(sample_fn, calls=[(torch.zeros(1),) for _ in range(3)])


sub(r, "shuffle", _b2_shuffle, primary=True, compile=dict(backend="eager"), fp64=None,
    pre=lambda side: random.seed(7))
sub(r, "sample", _b2_sample, compile=dict(backend="eager"), fp64=None, pre=lambda side: random.seed(7))

r = rc("B3", ["B3"], "AOT", "0913issues/03-aot-autograd-jvp-ldexp-process-crash.md",
       "jvp over ldexp terminates the interpreter under aot_eager")


def _b3():
    torch.manual_seed(0)
    e = torch.randint(-3, 3, (3, 4)).float()
    f = lambda a: torch.ldexp(a, e)  # noqa: E731
    x, t = torch.randn(3, 4), torch.randn(3, 4)
    return Case(lambda x, t: torch.func.jvp(f, (x,), (t,)), (x, t))


sub(r, "jvp_ldexp", _b3, primary=True, compile=dict(backend="aot_eager"), fp64=None)

r = rc("B4", ["B4"], "In", "0913issues/04-inductor-cpu-argmin-dynamic-pow-in-cpp.md",
       "argmin/argmax under dynamic=True emit Python ** into C++", status="confirmed")


def _b4():
    torch.manual_seed(0)
    x = torch.randn(3, 4, 4)
    m = torch.randn(1, 4, 4)
    return Case(lambda x, m: (x + m).argmin(), (x, m))


sub(r, "argmin_dynamic", _b4, primary=True, compile=dict(dynamic=True))

r = rc("B5", ["B5"], "In", "0913issues/05-inductor-cudagraphs-new-zeros-cpu-device.md",
       "new_zeros(device=cpu) returns a CUDA tensor under cudagraphs", reproducible=False,
       reason="needs CUDA (triton.cudagraphs); this machine has no GPU", status="confirmed")


def _b5():
    x = torch.randn(5, device="cuda")
    return Case(lambda x: x.new_zeros((2, 3), device="cpu"), (x,))


sub(r, "new_zeros_cudagraphs", _b5, primary=True, inductor_config={"triton.cudagraphs": True}, fp64=None)

r = rc("B6", ["B6"], "In", "0913issues/06-inductor-cpu-std-var-fp32-accumulation.md",
       "std/var accumulate in float32: inf/NaN and zero gradient at extreme magnitudes")


def _b6_large():
    torch.manual_seed(0)
    x = torch.randn(4, 8) * 1e30
    return Case(torch.std, (x,))


def _b6_tiny():
    torch.manual_seed(0)
    torch.randn(4, 8)  # keep the draft's RNG order
    x = (torch.randn(5) * 1e-30).requires_grad_()
    return Case(torch.std, (x,))


sub(r, "std_1e30", _b6_large, primary=True)
sub(r, "std_1e-30_grad", _b6_tiny, grad=True)

r = rc("B7", ["B7"], "Dy", "0913issues/07-dynamo-jvp-make-dual-internal-assert.md",
       "jvp of quantile / addr: internal assertion on every backend")


# The draft's program text, executed in a __main__-like namespace.  The assert only fires when a jvp already ran
# in the process (the draft calls the eager jvp first) and, empirically, only when `f`/`g` are defined the way the
# draft defines them: the same functions defined inside this module make Dynamo swallow the assert and fall back
# silently (bisected 2026-09-25: exec'd draft text raises, module-level definitions here return).
_B7_TEXT = """
import torch
torch.manual_seed(0)
x, t = torch.randn(3, 4), torch.randn(3, 4)
q = torch.tensor([0.25, 0.75])
f = lambda a: torch.quantile(a, q, dim=0)
def g(x, t):
    return torch.func.jvp(f, (x,), (t,))
"""


def _b7_custom(R):
    ns: Dict[str, Any] = {"__name__": "__main__"}
    exec(_B7_TEXT, ns)  # noqa: S102
    g, x, t = ns["g"], ns["x"], ns["t"]
    g(x, t)                     # the draft's eager call, made on both sides
    return [R.call(R.compile(g), (x, t))]


def _draft_block(rel_path: str, index: int = 0) -> str:
    import re
    root = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
    md = open(os.path.join(root, rel_path), encoding="utf-8").read()
    return re.findall(r"```python\n(.*?)```", md, re.S)[index]


def _b7_verbatim(R):
    """The draft's first code block executed verbatim (what scripts/run_issue_snippet.py does).  The eager side
    runs the block up to and including the eager jvp; the compiled side runs the whole block, whose loop compiles
    the jvp with backend eager / aot_eager / inductor itself."""
    text = _draft_block("0913issues/07-dynamo-jvp-make-dual-internal-assert.md")
    head = text.split("for backend in")[0]
    ns: Dict[str, Any] = {"__name__": "__main__"}

    def program():
        exec(head if R.side == "eager" else text, ns)  # noqa: S102
        return torch.func.jvp(ns["f"], (ns["x"],), (ns["t"],))[1].shape
    return [R.call(program, ())]


sub(r, "draft_block_verbatim", lambda: Case(lambda: None), primary=True, fp64=None, custom=_b7_verbatim,
    note="compiled side = the draft's whole first code block (its own torch.compile calls); eager side = the block's eager prefix")
sub(r, "jvp_quantile_eager_backend", lambda: Case(lambda: None), compile=dict(backend="eager"), fp64=None, custom=_b7_custom)
sub(r, "jvp_quantile_aot_eager", lambda: Case(lambda: None), compile=dict(backend="aot_eager"), fp64=None, custom=_b7_custom)

r = rc("B8", ["B8"], "In", "0913issues/08-inductor-ldexp-output-dtype.md",
       "ldexp output dtype wrong in both directions", status="fixed")


def _b8(kind):
    def make():
        torch.manual_seed(0)
        cases = {
            "bool_x_fp16": (torch.ones(3, 4, dtype=torch.bool), torch.randn(3, 4).half()),
            "int64_x_bf16": (torch.randint(1, 4, (3, 4)), torch.randn(3, 4).bfloat16()),
            "fp16_x_fp32": (torch.randn(3, 4).half(), torch.randn(3, 4)),
            "fp16_x_bf16": (torch.randn(3, 4).half(), torch.randn(3, 4).bfloat16()),
            "bf16_x_fp64": (torch.randn(3, 4).bfloat16(), torch.randn(3, 4).double()),
        }
        return Case(torch.ldexp, cases[kind])
    return make


for i, k in enumerate(["bool_x_fp16", "int64_x_bf16", "fp16_x_fp32", "fp16_x_bf16", "bf16_x_fp64"]):
    sub(r, k, _b8(k), primary=(i == 0), fp64=None)

r = rc("B9", ["B9"], "AOT", "0913issues/09-compiled-autograd-interpolate-isintlist-assert.md",
       "compiled autograd: interpolate backward hits an internal assertion")


def _b9_custom(R):
    torch.manual_seed(0)
    x = torch.randn(1, 2, 4, 4, requires_grad=True)

    def program(x):
        x.grad = None
        F.interpolate(x, scale_factor=2, mode="bilinear").sum().backward()
        return x.grad
    if R.side == "eager":
        return [R.call(program, (x,))]
    with torch._dynamo.compiled_autograd._enable(torch.compile(backend="eager")):
        return [R.call(program, (x,))]


sub(r, "compiled_autograd_interpolate", lambda: Case(lambda: None), primary=True, custom=_b9_custom, fp64=None)

r = rc("B10", ["B10"], "Dy", "0913issues/10-dynamo-dynamic-fstring-format-spec.md",
       "f-string format spec on a symbolic size: internal Dynamo error", status="confirmed")
sub(r, "fstring_d", lambda: Case(lambda x: f"{x.shape[0]:d}", (torch.randn(3, 4),)), primary=True,
    compile=dict(backend="eager", dynamic=True), fp64=None)

r = rc("B11", ["B11"], "In", "0913issues/11-inductor-compiled-sgd-foreach-complex.md",
       "compiled SGD.step with foreach=True and complex parameters: lowering assertion", status="confirmed")


def _b11_custom(R):
    torch.manual_seed(0)
    p = torch.nn.Parameter(torch.complex(torch.randn(3, 2), torch.randn(3, 2)))
    opt = torch.optim.SGD([p], lr=0.1, foreach=True)
    p.grad = torch.ones_like(p)

    def program():
        step = opt.step if R.side == "eager" else torch.compile(opt.step)
        step()
        return p.detach().clone()
    return [R.call(program, ())]


sub(r, "sgd_foreach_complex", lambda: Case(lambda: None), primary=True, custom=_b11_custom, fp64=None)

r = rc("B12", ["B12"], "De", "0913issues/12-inductor-interpolate-zero-size-oob-nan.md",
       "interpolate on an empty spatial dim returns uninitialised data instead of raising", status="confirmed")
sub(r, "interpolate_empty", lambda: Case(lambda x: F.interpolate(x, size=3, mode="nearest"), (torch.empty(2, 3, 0),)),
    primary=True, fp64=None)

r = rc("B13", ["B13"], "Ex", "0913issues/13-export-aoti-lifted-constant-mutation.md",
       "mutated captured tensor: export accepts and AOTInductor asserts", status="rejected")


def _b13_custom(R):
    from torch.export import export
    from torch._inductor import aoti_compile_and_package, aoti_load_package
    torch.manual_seed(0)
    RM, RV = torch.zeros(3), torch.ones(3)

    class M(torch.nn.Module):
        def forward(self, x):
            return F.instance_norm(x, RM, RV, use_input_stats=True)
    x = torch.randn(2, 3, 4, 4)
    m = M()
    if R.side == "eager":
        return [R.call(m, (x,), state=lambda: (RM.clone(), RV.clone()))]

    def program(x):
        ep = export(m, (x,))
        pkg = aoti_compile_and_package(ep, package_path=os.path.join(tempfile.mkdtemp(), "m.pt2"))
        return aoti_load_package(pkg)(x)
    return [R.call(program, (x,), state=lambda: (RM.clone(), RV.clone()))]


sub(r, "aoti_lifted_constant_mutation", lambda: Case(lambda: None), primary=True, custom=_b13_custom, fp64=None)

r = rc("B14", ["B14"], "De", "0913issues/14-refs-vector-norm-negative-dim-empty-batch.md",
       "vector_norm(ord=inf) on an empty batch fails for negative dim", status="fixed")
sub(r, "vector_norm_inf_empty", lambda: Case(lambda x: torch.linalg.vector_norm(x, ord=float("inf"), dim=-1), (torch.empty(0, 5),)),
    primary=True)

r = rc("B15", ["B15"], "In", "0913issues/15-inductor-bce-huber-loss-mixed-dtype.md",
       "binary_cross_entropy / huber_loss return float32 for half-precision inputs")


def _b15():
    torch.manual_seed(0)
    p = torch.rand(4, 3).to(torch.bfloat16)
    t = torch.rand(4, 3).to(torch.bfloat16)
    w = torch.rand(4, 3)
    return Case(lambda p, t, w: F.binary_cross_entropy(p, t, weight=w), (p, t, w))


sub(r, "bce_weight_fp32", _b15, primary=True, fp64=None)

r = rc("B17", ["B17"], "Dy", "0913issues/17-dynamo-random-seed-first-call.md",
       "random.seed inside the function is ignored on the first call", status="fixed")


def _b17():
    def seed_fn(x):
        random.seed(0)
        return x + random.random(), random.random(), random.randint(0, 100)
    return Case(seed_fn, calls=[(torch.zeros(1),) for _ in range(3)])


sub(r, "seed_inside", _b17, primary=True, compile=dict(backend="eager"), fp64=None)

r = rc("B18", ["B18"], "Dy", "0913issues/18-dynamo-dynamic-namedtuple-eq-recursion-py314.md",
       "namedtuple == with tensor fields overflows the stack (Python 3.14 + dynamic)")
NT = collections.namedtuple("NT", "u v")
sub(r, "namedtuple_eq", lambda: Case(lambda x: NT(x, x + 1) == NT(x, x + 1), (torch.randn(3, 4),)), primary=True,
    compile=dict(backend="eager", dynamic=True), fp64=None)

r = rc("B19", ["B19"], "In", "0913issues/19-inductor-windows-bmm-max-autotune-export.md",
       "bmm under max_autotune: missing symbol export in a C++ template (Windows)")


def _b19():
    torch.manual_seed(0)
    a, b = torch.randn(4, 8, 8), torch.randn(4, 8, 8)
    return Case(torch.bmm, (a, b))


sub(r, "bmm_max_autotune", _b19, primary=True, inductor_config={"max_autotune": True, "max_autotune_gemm": True})

r = rc("B20", ["B20"], "Ex", "0913issues/20-aoti-return-types-namedtuple-packaging.md",
       "AOTInductor cannot package models returning torch.return_types.*", status="fixed")


def _b20_custom(R):
    from torch.export import export
    from torch._inductor import aoti_compile_and_package, aoti_load_package
    torch.manual_seed(0)

    class MaxDim(torch.nn.Module):
        def forward(self, x):
            return torch.max(x, dim=0)
    x = torch.randn(4, 5)
    m = MaxDim()
    if R.side == "eager":
        return [R.call(m, (x,))]

    def program(x):
        ep = export(m, (x,))
        pkg = aoti_compile_and_package(ep, package_path=os.path.join(tempfile.mkdtemp(), "m.pt2"))
        return aoti_load_package(pkg)(x)
    return [R.call(program, (x,))]


sub(r, "aoti_return_types_max", lambda: Case(lambda: None), primary=True, custom=_b20_custom, fp64=None)

r = rc("B21", ["B21"], "De", "0913issues/21-inductor-lerp-bool-scalar-weight.md",
       "lerp of Boolean tensors with a 0-d weight fails to compile", status="fixed")


def _b21():
    torch.manual_seed(0)
    a = torch.randint(0, 2, (3, 4)).bool()
    return Case(lambda a, w: torch.lerp(a, a, w), (a, torch.tensor(0.3)))


sub(r, "lerp_bool", _b21, primary=True, fp64=None)

r = rc("B22", ["B22"], "In", "0913issues/22-inductor-cpu-sum-prod-dtype-bool.md",
       "sum / prod with dtype=torch.bool: C++ error / assertion")
sub(r, "sum_half_dtype_bool", lambda: Case(lambda a: torch.sum(a, dtype=torch.bool), (torch.randn(3, 4).half(),)),
    primary=True, fp64=None)
sub(r, "prod_dtype_bool", lambda: Case(lambda a: torch.prod(a, dtype=torch.bool), (torch.randn(3, 4),)), fp64=None)

r = rc("B23", ["B23"], "In", "0913issues/23-inductor-addmm-scalar-bias-max-autotune.md",
       "addmm with a 0-d bias under max_autotune: IndexError in lowering", status="fixed")


def _b23():
    torch.manual_seed(0)
    x, y = torch.randn(2, 2), torch.randn(2, 3)
    return Case(lambda b, x, y: torch.addmm(b, x, y), (torch.tensor(0.5), x, y))


sub(r, "addmm_0d_bias", _b23, primary=True, inductor_config={"max_autotune": True, "max_autotune_gemm": True})

r = rc("B24", ["B24"], "In", "0913issues/24-inductor-var-mean-empty-mean-zero.md",
       "var_mean / std_mean of an empty tensor: mean is 0 instead of NaN", status="fixed")
sub(r, "var_mean_empty", lambda: Case(torch.var_mean, (torch.randn(0),)), primary=True)
sub(r, "std_mean_empty", lambda: Case(torch.std_mean, (torch.randn(0),)))

r = rc("B25", ["B25"], "In", "0913issues/25-inductor-channel-shuffle-channels-last.md",
       "channel_shuffle loses the channels_last layout", status="confirmed")


def _b25():
    torch.manual_seed(0)
    x = torch.randn(2, 6, 8, 8).contiguous(memory_format=torch.channels_last)
    return Case(lambda x: F.channel_shuffle(x, 2), (x,))


sub(r, "channel_shuffle_chlast", _b25, primary=True)

r = rc("B26", ["B26"], "Dy", "0913issues/26-dynamo-keyerror-str-quotes.md",
       "str(KeyError(k)) loses the quotes CPython adds", status="fixed")


def _b26():
    def f(x):
        try:
            raise KeyError("k")
        except KeyError as e:
            return x, str(e), f"key error: {e}"
    return Case(f, (torch.zeros(1),))


sub(r, "keyerror_str", _b26, primary=True, compile=dict(backend="eager", fullgraph=True), fp64=None)

r = rc("B27", ["B27"], "De", "0913issues/27-meta-abs-complex-out-dtype.md",
       "abs(complex out=float64) rejected by the meta kernel", status="confirmed")


def _b27():
    torch.manual_seed(0)
    z = torch.complex(torch.rand(3, 4) + 0.5, torch.rand(3, 4))
    return Case(lambda a: torch.abs(a, out=torch.empty(0, dtype=torch.float64)), (z,))


sub(r, "abs_complex_out_f64", _b27, primary=True, compile=dict(backend="aot_eager"), fp64=None)

# ---------------------------------------------------------------------------------------------
# round 2 (0920issues)
# ---------------------------------------------------------------------------------------------

r = rc("C1", ["C1"], "AOT", "0920issues/01-inductor-saved-view-version-check-lost-wrong-gradient.md",
       "autograd's in-place-modification check lost when a view of an input is saved for backward", status="fixed")


def _c1_custom(R):
    def f(x, w):
        return x @ w
    x = torch.arange(6.).reshape(2, 3) / 7
    w = (torch.arange(9.).reshape(3, 3) / 5).requires_grad_()
    g = R.compile(f)

    def program(xb, wb):
        out = g(xb, wb)
        xb.add_(1)                       # input modified between forward and backward
        out.sum().backward()
        return wb.grad
    return [R.call(program, (x.clone(), w.detach().clone().requires_grad_()))]


sub(r, "saved_view_mutated_before_backward", lambda: Case(lambda: None), primary=True, custom=_c1_custom, fp64=None)

r = rc("C3", ["C3", "C26"], "Dy", "0920issues/02b-stale-python-float-baked-into-cached-graph-norm-eps-interpolate-losses.md",
       "changing Python float argument (and integers derived from it) baked into the cached graph")
_S = (0.9, 0.5, 0.25, 2.0)


def _c3(kind):
    def make():
        torch.manual_seed(0)
        x, y = torch.randn(4, 4), torch.randn(4, 4)
        progs = {
            "rms_norm_eps": lambda s: F.rms_norm(x * s, (4,), eps=s + 1e-3),
            "huber_delta": lambda s: F.huber_loss(x * s, y, delta=s + 0.1),
            "interpolate_scale": lambda s: F.interpolate((x * s)[None], scale_factor=1.0 + s),
        }
        return Case(progs[kind], calls=[(s,) for s in _S])
    return make


def _c26(kind):
    def make():
        torch.manual_seed(0)
        x = torch.randn(8, 8)
        progs = {
            "cumsum_dim_from_float": lambda s: (x * s).cumsum(int(s * 2) % 2),
            "round_decimals_from_float": lambda s: (x * s).round(decimals=int(s * 4)),
        }
        return Case(progs[kind], calls=[(s,) for s in (0.9, 0.5, 0.25, 1.0)])
    return make


sub(r, "rms_norm_eps", _c3("rms_norm_eps"), primary=True, fp64=None)
sub(r, "huber_delta", _c3("huber_delta"), fp64=None)
sub(r, "interpolate_scale", _c3("interpolate_scale"), fp64=None)
sub(r, "C26_cumsum_dim_from_float", _c26("cumsum_dim_from_float"), fp64=None)
sub(r, "C26_round_decimals_from_float", _c26("round_decimals_from_float"), fp64=None)

r = rc("C5", ["C5"], "De", "0920issues/04-comment-on-197554-validation-lost-sweep.md",
       "ten members of the maintainers' 'validation lost' umbrella (eager error inputs accepted by the compiled path)")
_I = lambda *v: torch.tensor(v)  # noqa: E731
_C5 = {
    "index_add_shape_mismatch": lambda: Case(lambda x, i, s: torch.index_add(x, 0, i, s), (torch.zeros(3, 2), _I(0, 2), torch.tensor([3., 4.]))),
    "index_copy_negative_index": lambda: Case(lambda x, i, s: torch.index_copy(x, 0, i, s), (torch.zeros(4, 3), _I(-1), torch.ones(1, 3))),
    "bce_input_gt_1": lambda: Case(lambda x, t: F.binary_cross_entropy(x, t), (torch.tensor([1.5, 0.2]), torch.tensor([1., 0.]))),
    "repeat_interleave_wrong_output_size": lambda: Case(lambda x, r: torch.repeat_interleave(x, r, output_size=9), (torch.arange(3.), _I(1, 2, 3))),
    "softmax_int64": lambda: Case(lambda x: torch.softmax(x, 0), (_I(1, 2, 3),)),
    "layer_norm_f64_weight": lambda: Case(lambda x, w: F.layer_norm(x, (3,), w), (torch.arange(6.).reshape(2, 3), torch.ones(3, dtype=torch.float64))),
    "one_hot_float": lambda: Case(lambda x: F.one_hot(x, 5), (torch.tensor([0.5, 1.5, 2.5]),)),
    "int64_mul__float": lambda: Case(lambda x, y: x.mul_(y), (_I(1, 2, 3), torch.tensor([.5, .5, .5]))),
    "float_add__1j": lambda: Case(lambda x: x.add_(1j), (torch.ones(3),)),
    "take_out_overlapping": lambda: Case(lambda x: torch.take(x, _I(1, 2), out=x[:2]), (torch.arange(3),)),
}
for i, (k, mk) in enumerate(_C5.items()):
    sub(r, k, mk, primary=(i == 0), fp64=None)

r = rc("C8", ["C8"], "In", "0920issues/07-inductor-noop-elimination-returns-input-itself.md",
       "x*1 / x+0 / x/1.0 as a graph output return the input tensor itself", status="confirmed")
sub(r, "logits_div_1.0", lambda: Case(lambda logits, temperature: logits / temperature, (torch.ones(3), 1.0)), primary=True)
sub(r, "buf_mul_1.0", lambda: Case(lambda buf, momentum: buf * momentum, (torch.ones(3), 1.0)))
sub(r, "x_add_0", lambda: Case(lambda x, bias: x + bias, (torch.ones(3), 0)))

r = rc("C10", ["C10"], "In", "0920issues/09-inductor-float-floor-divide-off-by-one.md",
       "floating-point floor division off by one under compile", status="confirmed")


def _c10(dtype, kind):
    def make():
        a = torch.tensor([1.0, 0.5, 6.0, 1.0], dtype=dtype)
        b = torch.tensor([0.1, 0.1, 0.2, 1 / 3], dtype=dtype)
        fn = (lambda a, b: a // b) if kind == "floordiv" else (lambda a, b: torch.div(a, b, rounding_mode="floor"))
        return Case(fn, (a, b))
    return make


sub(r, "f32_floordiv", _c10(torch.float32, "floordiv"), primary=True)
sub(r, "f64_div_floor", _c10(torch.float64, "div_floor"))

r = rc("C11", ["C11"], "Dy", "0920issues/10-dynamo-closure-mutation-lost-in-method-of-object-created-in-graph.md",
       "Dynamo silently drops closure mutations made in methods of locally defined classes", status="fixed")


def _c11(kind):
    def make():
        state = {"n": 0} if kind.startswith("dict") else []

        class Helper:
            def touch(self):
                if kind == "dict +=":
                    state["n"] += 1
                elif kind == "dict setitem":
                    state["k"] = 1
                elif kind == "list append":
                    state.append(1)
                elif kind == "list +=":
                    state.extend([1])

        def f(x):
            Helper().touch()
            return x + 1
        return Case(f, calls=[(torch.ones(1),), (torch.ones(1),)], state=lambda: state)
    return make


for i, k in enumerate(["dict +=", "dict setitem", "list append", "list +="]):
    sub(r, k.replace(" ", "_"), _c11(k), primary=(i == 0), compile=dict(backend="eager", fullgraph=True), fp64=None)

r = rc("C13", ["C13"], "Dy", "0920issues/12-dynamo-numpy-wrong-values-fix-cbrt-clip-sign.md",
       "compiled NumPy code returns wrong values (np.fix / cbrt / clip / sign)")


def _c13(kind):
    def make():
        import numpy as np
        f4 = np.array([1.5, -1.5, 2.5, -0.5, 8.0, -8.0, np.nan], dtype=np.float32)
        i8 = np.array([-128, -100, -3, 0, 5, 100, 127], dtype=np.int8)
        u8 = np.array([0, 1, 3, 200, 255], dtype=np.uint8)
        cases = {
            "np_fix": (lambda x: np.fix(x), f4),
            "np_cbrt": (lambda x: np.cbrt(x), f4),
            "np_sign": (lambda x: np.sign(x), f4),
            "np_heaviside": (lambda x: np.heaviside(x, np.float32(0.5)), f4),
            "np_clip_int8": (lambda x: np.clip(x, -1000, 1000), i8),
            "np_clip_uint8": (lambda x: np.clip(x, -2, 5), u8),
        }
        fn, arg = cases[kind]
        return Case(fn, (arg.copy(),))
    return make


for i, k in enumerate(["np_fix", "np_cbrt", "np_sign", "np_heaviside", "np_clip_int8", "np_clip_uint8"]):
    sub(r, k, _c13(k), primary=(i == 0), compile=dict(backend="eager"), fp64=None)

r = rc("C14", ["C14"], "In", "0920issues/13-inductor-cpu-vectorized-remainder-nan-and-length-dependent.md",
       "vectorized remainder: NaN for infinite divisor and 0 for large quotients")


def _c14():
    INF = float("inf")
    a = torch.tensor([5.5, -5.5, 0.0, 1e20, 2147483648.0, 7.0, 1.0, -0.0])
    b = torch.tensor([INF, -INF, INF, 3.0, 3.0, 0.7, 0.1, 1.0])
    return Case(torch.remainder, (a, b))


sub(r, "remainder_n8", _c14, primary=True)

r = rc("C15", ["C15"], "In", "0920issues/14-comment-on-191499-int8-minmax-argmin-x86.md",
       "int8/uint8 min/max/argmin/argmax wrong for >=16 elements on x86")
_POS = [5, 1, 100, 3, 7, 8, 9, 13, 100, 120, 127, 2, 6, 4, 11, 12, 90, 80]


def _c15(dtype, neg, op):
    def make():
        x = torch.tensor(_POS)
        x = (-x if neg else x).to(dtype)
        return Case(op, (x,))
    return make


sub(r, "uint8_argmin", _c15(torch.uint8, False, torch.argmin), primary=True, fp64=None)
sub(r, "uint8_min", _c15(torch.uint8, False, torch.min), fp64=None)
sub(r, "int8_neg_max", _c15(torch.int8, True, torch.max), fp64=None)
sub(r, "int8_neg_argmax", _c15(torch.int8, True, torch.argmax), fp64=None)

r = rc("C16", ["C16"], "Dy", "0920issues/15-symint-round-negative-ndigits-is-identity.md",
       "round(SymInt -1) is the identity; round disappears from the graph")
sub(r, "round_shape_neg1", lambda: Case(lambda x: round(x.shape[0], -1), calls=[(torch.ones(n),) for n in (14, 15, 16, 25)]),
    primary=True, compile=dict(backend="eager", dynamic=True), fp64=None)
sub(r, "x_times_round", lambda: Case(lambda x: x * round(x.shape[0] * 5, -1), calls=[(torch.ones(n),) for n in (14, 15, 16, 25)]),
    compile=dict(backend="eager", dynamic=True), fp64=None)

r = rc("C17", ["C17"], "Dy", "0920issues/16-symfloat-nan-self-comparison-folded.md",
       "NaN self-comparison of an .item() value folded to a constant under capture_scalar_outputs")


def _c17():
    def step(loss, param):
        v = loss.item()
        if v != v:
            return param
        return param - 0.1 * v
    return Case(step, (torch.tensor(float("nan")), torch.ones(2)))


sub(r, "nan_self_compare", _c17, primary=True, compile=dict(backend="eager"), dynamo_config={"capture_scalar_outputs": True}, fp64=None)
sub(r, "inf_minus_inf_item", lambda: Case(lambda t: t.item() - t.item(), (torch.tensor(float("inf")),)),
    dynamo_config={"capture_scalar_outputs": True}, fp64=None)

r = rc("C20", ["C20"], "Dy", "0920issues/19-dynamo-numpy-dtype-shape-divergences.md",
       "compiled NumPy code: different dtype / shape rules (cumsum int8 overflow, square->float64, median shape)")


def _c20(kind):
    def make():
        import numpy as np
        i8 = np.array([-128, -100, -3, 0, 5, 100, 127], dtype=np.int8)
        u8 = np.array([0, 1, 3, 200, 255], dtype=np.uint8)
        f4 = np.array([1.5, -1.5, 2.5, -0.5, 8.0], dtype=np.float32)
        cases = {
            "np_cumsum_int8": (lambda x: np.cumsum(x), i8),
            "np_square_int8": (lambda x: np.square(x), i8),
            "np_median_f32": (lambda x: np.median(x), f4),
            "np_any_uint8": (lambda x: np.any(x), u8),
            "uint16_plus_1": (lambda x: x.astype(np.uint16) + np.uint16(1), u8),
        }
        fn, arg = cases[kind]
        return Case(fn, (arg.copy(),))
    return make


for i, k in enumerate(["np_cumsum_int8", "np_square_int8", "np_median_f32", "np_any_uint8", "uint16_plus_1"]):
    sub(r, k, _c20(k), primary=(i == 0), compile=dict(backend="eager"), fp64=None)

r = rc("C21", ["C21"], "In", "0920issues/20-comment-on-185337-explicit-half-cast-roundtrip-still-elided.md",
       "explicit half().float() round trip removed by Inductor")
sub(r, "half_float_roundtrip", lambda: Case(lambda x: x.to(torch.float16).to(torch.float32), (torch.tensor([0.1, 0.001, 1 / 3, 70000.0]),)),
    primary=True, fp64=None)
sub(r, "bf16_float_roundtrip", lambda: Case(lambda x: x.to(torch.bfloat16).to(torch.float32), (torch.tensor([0.1, 0.001, 1 / 3, 70000.0]),)),
    fp64=None)

r = rc("C22", ["C22", "C31"], "In", "0920issues/21-inductor-clamp-out-of-range-python-bounds-wrap.md",
       "clamp / pad Python bounds and fill values wrapped into the integer dtype")
sub(r, "clamp_int8_wide", lambda: Case(lambda t: torch.clamp(t, -1000, 1000), (torch.tensor([-128, -3, 0, 5, 127], dtype=torch.int8),)),
    primary=True, fp64=None)
sub(r, "clamp_int8_max300", lambda: Case(lambda t: torch.clamp(t, max=300), (torch.tensor([-128, -3, 0, 5, 127], dtype=torch.int8),)), fp64=None)
sub(r, "C31_pad_uint8_value_-1", lambda: Case(lambda x: F.pad(x, (1, 1), value=-1), (torch.tensor([1, 200, 3], dtype=torch.uint8),)), fp64=None)
sub(r, "C31_pad_int8_value_300", lambda: Case(lambda x: F.pad(x, (1, 0), value=300), (torch.tensor([[1, -2], [3, 4]], dtype=torch.int8),)), fp64=None)

r = rc("C23", ["C23"], "In", "0920issues/22-comment-on-197554-inference-tensor-and-deterministic-mode-checks-lost.md",
       "three protections lost under Inductor (inference tensor in-place, deterministic put_, F.pad over-cropping)")


def _c23_inference():
    with torch.inference_mode():
        t = torch.ones(3)
    return Case(lambda t: t.add_(1), (t,))


def _det(side):
    torch.use_deterministic_algorithms(True)


sub(r, "inplace_on_inference_tensor", _c23_inference, primary=True, fp64=None)
sub(r, "deterministic_put__duplicate", lambda: Case(lambda x, i, v: x.put_(i, v), (torch.zeros(4), torch.tensor([1, 1]), torch.tensor([1.0, 2.0]))),
    pre=_det, fp64=None)
sub(r, "pad_crops_more_than_input", lambda: Case(lambda x: F.pad(x, (-4, 4)), (torch.arange(1.0, 4.0),)), fp64=None)

r = rc("C25", ["C25"], "In", "0920issues/24-comment-on-174386-deterministic-empty-still-unfilled-on-cpu.md",
       "deterministic mode: empty* not filled with NaN / max on Inductor CPU")
sub(r, "empty_like_randn", lambda: Case(lambda x: torch.empty_like(torch.randn(4, 4)), (torch.ones(4, 4),)), primary=True,
    pre=_det, inductor_config={"fallback_random": True}, fp64=None)
sub(r, "empty_int32", lambda: Case(lambda x: torch.empty(3, dtype=torch.int32), (torch.ones(4, 4),)),
    pre=_det, inductor_config={"fallback_random": True}, fp64=None)

r = rc("C28", ["C28"], "In", "0920issues/27-comment-on-183607-fp16-fused-chain-y-inf-but-isinf-false.md",
       "float16 fused chains: intermediates not rounded to float16; isinf(y) False while y is inf")


def _c28():
    def f(x):
        y = x * x
        return y, y / x, torch.isinf(y), torch.where(torch.isinf(y), torch.zeros_like(y), y)
    return Case(f, (torch.full((40,), 300.0, dtype=torch.float16),))


sub(r, "fp16_chain", _c28, primary=True, fp64=None)

r = rc("C29", ["C29"], "In", "0920issues/28-inductor-any-uint8-returns-bool.md",
       "torch.any(uint8) returns bool instead of uint8 under Inductor")
_U8 = lambda: torch.tensor([[0, 3], [0, 0]], dtype=torch.uint8)  # noqa: E731
sub(r, "any_uint8", lambda: Case(lambda x: torch.any(x), (_U8(),)), primary=True, fp64=None)
sub(r, "any_uint8_dim0", lambda: Case(lambda x: x.any(0), (_U8(),)), fp64=None)
sub(r, "any_times_200_plus_100", lambda: Case(lambda x: torch.any(x) * 200 + 100, (_U8(),)), fp64=None)

r = rc("C34", ["C34"], "In", "0920issues/33-inductor-avg-pool-backward-ceil-mode-wrong-divisor.md",
       "avg_pool backward with ceil_mode uses the full kernel size as divisor for the last window")
sub(r, "avg_pool1d_ceil_grad", lambda: Case(lambda x: F.avg_pool1d(x, 3, stride=2, ceil_mode=True), (torch.arange(6.0).reshape(1, 1, 6).requires_grad_(),)),
    primary=True, grad=True)
sub(r, "avg_pool2d_ceil_grad", lambda: Case(lambda x: F.avg_pool2d(x, 3, stride=2, padding=1, ceil_mode=True), (torch.arange(36.0).reshape(1, 1, 6, 6).requires_grad_(),)),
    grad=True)


def _mp_ref(fn_name):
    def ref(args):
        from mpmath import mp
        mp.dps = 30
        f = getattr(mp, fn_name)
        x = args[0].detach().to(torch.float64).reshape(-1).tolist()
        vals = []
        for v in x:
            try:
                vals.append(float(f(mp.mpf(v))))
            except Exception:  # noqa: BLE001
                vals.append(float("nan"))
        return [torch.tensor(vals, dtype=torch.float64).reshape(args[0].shape)]
    return ref


r = rc("C35", ["C35"], "In", "0920issues/34-inductor-cpu-erfinv-loses-accuracy-near-one.md",
       "erfinv loses accuracy near +-1 on Inductor CPU")
sub(r, "erfinv_f32_near_1", lambda: Case(torch.erfinv, (torch.tensor([0.99, 0.9999, 0.999999, 0.9999999, 0.99999994] * 4, dtype=torch.float32),),
                                         ref=_mp_ref("erfinv")), primary=True)
sub(r, "erfinv_f64_near_1", lambda: Case(torch.erfinv, (torch.tensor([0.999, 0.999999999, 1 - 1e-12, 1 - 1e-14, 1 - 1e-16] * 4, dtype=torch.float64),),
                                         ref=_mp_ref("erfinv")), fp64=None)

r = rc("C36", ["C36"], "In", "0920issues/35-inductor-cpu-vector-acosh-float64-overflow.md",
       "vectorized float64 acosh overflows for x > 1.34e154")
sub(r, "acosh_f64_1e200_n8", lambda: Case(torch.acosh, (torch.full((8,), 1e200, dtype=torch.float64),), ref=_mp_ref("acosh")), primary=True, fp64=None)
sub(r, "acosh_f64_1.35e154_n16", lambda: Case(torch.acosh, (torch.full((16,), 1.35e154, dtype=torch.float64),), ref=_mp_ref("acosh")), fp64=None)

r = rc("C37", ["C37", "C30", "C38"], "In", "0920issues/36-inductor-runs-ops-on-dtypes-eager-rejects-full-list.md",
       "operators run under compile on dtypes their eager kernels reject (418 pairs; CUDA family in C38; C30 family)")


def _c37(kind):
    def make():
        i64 = torch.tensor([[1, -2, 3], [4, 0, -6]])
        b = torch.tensor([[True, False, True], [False, True, True]])
        f32 = torch.tensor([[1.5, -2.25, 3.0], [0.5, 0.0, -6.0]])
        c64 = f32.to(torch.complex64)
        cases = {
            "softmax_int64": (lambda x: torch.softmax(x, 1), i64),
            "avg_pool2d_int8": (lambda x: F.avg_pool2d(x.to(torch.int8)[None], 2), i64),
            "bitwise_not_f32": (lambda x: torch.bitwise_not(x), f32),
            "conv2d_bool": (lambda x: F.conv2d(x[None, None].expand(1, 1, 2, 3), torch.ones(1, 1, 2, 2, dtype=torch.bool)), b),
            "argmax_bool": (lambda x: torch.argmax(x), b),
            "one_hot_f32": (lambda x: F.one_hot(x.abs().long().float(), 7), f32),
            "bessel_j0_f16": (lambda x: torch.special.bessel_j0(x.half()), f32),
            "batch_norm_c64": (lambda x: F.batch_norm(x, None, None, training=True), c64),
            "mse_loss_c64": (lambda x: F.mse_loss(x, x), c64),
            # C30 (comment on 197554): "dtype not implemented in eager" family
            "C30_round_int8_decimals-1": (lambda x: torch.round(x, decimals=-1), torch.tensor([[1, -2], [3, 4]], dtype=torch.int8)),
            "C30_round_uint8_decimals1": (lambda x: torch.round(x, decimals=1), torch.tensor([1, 200, 3], dtype=torch.uint8)),
            "C30_ceil_bool": (lambda x: torch.ceil(x), torch.tensor([True, False, True])),
            "C30_glu_int8": (lambda x: F.glu(x), torch.tensor([[1, -2], [3, 4]], dtype=torch.int8)),
            "C30_adaptive_max_pool2d_int8": (lambda x: F.adaptive_max_pool2d(x[None], (1, 1)), torch.tensor([[1, -2], [3, 4]], dtype=torch.int8)),
        }
        fn, arg = cases[kind]
        return Case(fn, (arg,))
    return make


for i, k in enumerate(["softmax_int64", "avg_pool2d_int8", "bitwise_not_f32", "conv2d_bool", "argmax_bool", "one_hot_f32", "bessel_j0_f16",
                       "batch_norm_c64", "mse_loss_c64", "C30_round_int8_decimals-1", "C30_round_uint8_decimals1", "C30_ceil_bool",
                       "C30_glu_int8", "C30_adaptive_max_pool2d_int8"]):
    sub(r, k, _c37(k), primary=(i == 0), fp64=None)

r = rc("C40", ["C40"], "In", "0920issues/39-inductor-cpu-vector-erf-atanh-lose-accuracy-near-zero.md",
       "vectorized float32 erf loses all relative accuracy near 0; vector atanh returns 0 below eps")
_VALS = [1e-8, 1e-7, 2e-7, 5e-7, 1e-6, 1e-5, 1e-4, 1e-3]
sub(r, "erf_f32_near_0_n64", lambda: Case(torch.erf, (torch.tensor(_VALS * 8, dtype=torch.float32),), ref=_mp_ref("erf")), primary=True)
sub(r, "atanh_f32_eps", lambda: Case(torch.atanh, (torch.tensor([torch.finfo(torch.float32).eps / 4, torch.finfo(torch.float32).eps / 2,
                                                                  torch.finfo(torch.float32).eps, 1e-3] * 16, dtype=torch.float32),),
                                     ref=_mp_ref("atanh")))

r = rc("C41", ["C41"], "Dy", "0920issues/40-dynamo-ordereddict-move-to-end-side-effect-dropped.md",
       "OrderedDict.move_to_end on an input dict is silently dropped")


def _c41_touch():
    def touch(cache, x):
        cache.move_to_end("a")
        return x + 1
    return Case(touch, (collections.OrderedDict(a=1, b=2, c=3), torch.ones(2)))


def _c41_lru():
    class LRU:
        def __init__(self, cap):
            self.d, self.cap = collections.OrderedDict(), cap

        def get(self, k):
            self.d.move_to_end(k)
            return self.d[k]

        def put(self, k, v):
            self.d[k] = v
            if len(self.d) > self.cap:
                self.d.popitem(last=False)
    cache = LRU(2)
    cache.put("a", 1)
    cache.put("b", 2)

    def step(cache, x):
        cache.get("a")
        return x + 1

    def state():
        cache.put("c", 3)      # outside the compiled region: evicts the least recently used entry
        return list(cache.d)
    return Case(step, (cache, torch.ones(2)), state=state)


sub(r, "move_to_end_input_dict", _c41_touch, primary=True, compile=dict(backend="eager", fullgraph=True), fp64=None)
sub(r, "lru_eviction", _c41_lru, compile=dict(backend="eager"), fp64=None)

r = rc("C42", ["C42", "C43"], "Dy", "0920issues/41-dynamo-generator-reconstructed-as-exhausted-tuple-iterator.md",
       "a generator that escapes the compiled region comes back as an exhausted tuple_iterator")


def _consume(it):
    out = [type(it).__name__]
    try:
        while True:
            v = next(it)
            out.append(v.sum().item() if isinstance(v, torch.Tensor) else v)
    except StopIteration as e:
        out.append(f"StopIteration.value={e.value!r}")
    return out


def _c42_make():
    def make(x):
        def gen():
            yield x * 1
            yield x * 2
            return "done"
        return gen()
    return Case(make, (torch.ones(2),), post=_consume)


def _c43(kind):
    def make():
        def yield_op(x):
            def g():
                yield x * 1
                return 7
            return g()

        def started_no_op(x):
            def g():
                yield x
                yield x
                return 7
            it = g()
            next(it)
            return it
        return Case({"yield_op": yield_op, "started_no_op": started_no_op}[kind], (torch.ones(2),), post=_consume)
    return make


sub(r, "generator_returned", _c42_make, primary=True, compile=dict(backend="eager"), fp64=None)
sub(r, "C43_yield_op", _c43("yield_op"), compile=dict(backend="eager"), fp64=None)
sub(r, "C43_started_no_op", _c43("started_no_op"), compile=dict(backend="eager"), fp64=None,
    note="draft 41b's NEGATIVE example (no tensor work in the body: the generator is reconstructed correctly); expected to fire nothing")

r = rc("C44", ["C44", "C45"], "Dy", "0920issues/42-dynamo-indexerror-skips-user-except-handler.md",
       "IndexError raised by a tensor op skips the user's except handler")


def _c44(kind):
    def make():
        ops = {"x[10]": lambda x: x[10], "x.sum(dim=5)": lambda x: x.sum(dim=5), "x.softmax(dim=4)": lambda x: x.softmax(dim=4)}

        def guarded(x, op):
            try:
                return op(x)
            except (IndexError, RuntimeError) as e:
                return f"fallback after {type(e).__name__}"
        return Case(guarded, (torch.ones(3, 4), ops[kind]))
    return make


def _c45(kind):
    def make():
        import contextlib as cl

        def as_exception(x):
            try:
                return x[10]
            except Exception as e:  # noqa: BLE001
                return f"caught {type(e).__name__}"

        def suppressed(x):
            with cl.suppress(IndexError):
                return x.sum(dim=5)
            return "suppressed"

        def not_implemented(x):
            try:
                return x & x
            except NotImplementedError as e:
                return f"caught {type(e).__name__}"
        return Case({"as_exception": as_exception, "suppressed": suppressed, "not_implemented": not_implemented}[kind], (torch.ones(3, 4),))
    return make


sub(r, "guarded_x[10]", _c44("x[10]"), primary=True, compile=dict(backend="eager", fullgraph=True), has_handler=True, fp64=None)
sub(r, "guarded_sum_dim5", _c44("x.sum(dim=5)"), compile=dict(backend="eager", fullgraph=True), has_handler=True, fp64=None)
sub(r, "C45_except_Exception", _c45("as_exception"), compile=dict(backend="eager"), has_handler=True, fp64=None)
sub(r, "C45_contextlib_suppress", _c45("suppressed"), compile=dict(backend="eager"), has_handler=True, fp64=None)
sub(r, "C45_NotImplementedError", _c45("not_implemented"), compile=dict(backend="eager"), has_handler=True, fp64=None)

r = rc("C46", ["C46"], "Ex", "0920issues/43-aoti-windows-runner-destroyed-openmp-access-violation.md",
       "destroying an AOTI runner right after a run crashes the process on Windows (OpenMP workers still spinning)")
_HOLD: Dict[str, Any] = {}


def _c46_custom(R):
    from torch._inductor import aoti_compile_and_package, aoti_load_package
    torch.manual_seed(0)

    class M(torch.nn.Module):
        def forward(self, x):
            return x + 1
    x = torch.randn(4096)
    m = M()
    if R.side == "eager":
        return [R.call(m, (x,))]

    def program(x):
        ep = torch.export.export(m, (x,))
        pkg = aoti_compile_and_package(ep, package_path=os.path.join(tempfile.mkdtemp(), "m.pt2"))
        runner = aoti_load_package(pkg)
        _HOLD["runner"] = runner
        return runner(x)
    return [R.call(program, (x,))]


def _c46_teardown():
    _HOLD.pop("runner", None)      # unloads the model DLL while the OpenMP workers may still spin
    gc.collect()


sub(r, "aoti_runner_destroyed_n4096", lambda: Case(lambda: None), primary=True, custom=_c46_custom, teardown=_c46_teardown, fp64=None,
    note="the call itself succeeds; the process dies when the runner is destroyed afterwards")


# ---------------------------------------------------------------------------------------------
# the 58 -> root causes bookkeeping (for root_causes.csv)
# ---------------------------------------------------------------------------------------------

PIPELINE_ITEMS = [
    "B2", "B3", "B4", "B5", "B6", "B7", "B8", "B9", "B10", "B11", "B12", "B13", "B14", "B15", "B17", "B18", "B19", "B20", "B21", "B22",
    "B23", "B24", "B25", "B26", "B27",
    "C1", "C3", "C5", "C8", "C10", "C11", "C13", "C14", "C15", "C16", "C17", "C20", "C21", "C22", "C23", "C25", "C26", "C28", "C29", "C30",
    "C31", "C34", "C35", "C36", "C37", "C38", "C40", "C41", "C42", "C43", "C44", "C45", "C46",
]
EXCLUDED_CROSS_COMPILER = ["C6", "C7", "C12", "C18", "C19"]
EXCLUDED_OUTSIDE_PIPELINE = ["B1", "B16", "C2", "C4", "C9", "C24", "C27", "C32", "C33", "C39"]

if __name__ == "__main__":
    covered = sorted({m for c in CASES for m in c.members}, key=lambda s: (s[0], int(s[1:])))
    print(len(CASES), "root causes;", len(covered), "member items")
    missing = sorted(set(PIPELINE_ITEMS) - set(covered))
    extra = sorted(set(covered) - set(PIPELINE_ITEMS))
    print("missing:", missing, "extra:", extra)
    for c in CASES:
        print(f"{c.id:4s} {','.join(c.members):16s} {c.layer:3s} subs={len(c.subs):2d} {'' if c.reproducible else 'NOT REPRODUCIBLE: ' + c.reason}")
