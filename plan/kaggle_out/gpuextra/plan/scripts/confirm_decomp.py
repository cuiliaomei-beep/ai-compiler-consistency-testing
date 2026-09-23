"""Standalone confirmation of decomposition-differential findings."""
import sys
import warnings

sys.path.insert(0, ".")
warnings.filterwarnings("ignore")
from tcc.compat import ensure_msvc_env  # noqa: E402

ensure_msvc_env()
import torch  # noqa: E402

torch.manual_seed(0)
from torch.testing._internal.common_methods_invocations import op_db  # noqa: E402

print("=== index_add with an empty last dimension ===")
op = next(o for o in op_db if o.name == "index_add")
for s in op.sample_inputs("cpu", torch.float32):
    args = (s.input,) + tuple(s.args)
    tens = [a for a in args if isinstance(a, torch.Tensor)]
    if len(tens) == 3 and tuple(tens[0].shape) == (5, 5):
        x, dim_or_idx = s.input, s.args
        kw = dict(s.kwargs)
        print("sample args:", [(tuple(a.shape) if isinstance(a, torch.Tensor) else a) for a in s.args], "kwargs", kw)
        x0 = x[..., :0].clone()

        def f(x, *rest):
            return op.op(x, *rest, **kw)

        rest = tuple(a.clone() if isinstance(a, torch.Tensor) else a for a in s.args)
        try:
            e = f(x0.clone(), *rest)
            print("eager ok", tuple(e.shape))
        except Exception as ex:
            print("eager raised", type(ex).__name__, str(ex)[:100])
            break
        for be in ("aot_eager", "inductor"):
            torch._dynamo.reset()
            try:
                c = torch.compile(f, backend=be)(x0.clone(), *rest)
                print(be, "ok, equal:", torch.equal(c, e))
            except Exception as ex:
                msg = str(ex)
                i = msg.find("got ")
                print(be, "FAIL", type(ex).__name__, (msg[i:i + 160] if i >= 0 else msg[:160]).replace("\n", " "))
        break

print("=== std_mean / var on 1e30-scale values ===")
x = torch.randn(5, 5) * 1e30
for name, g in (("std_mean", lambda a: torch.std_mean(a)), ("var", lambda a: torch.var(a)),
                ("var_mean", lambda a: torch.var_mean(a)), ("std", lambda a: torch.std(a))):
    e = g(x)
    torch._dynamo.reset()
    ind = torch.compile(g, backend="inductor")(x)
    torch._dynamo.reset()
    aot = torch.compile(g, backend="aot_eager")(x)
    print(f"{name:<9} eager={e}  inductor={ind}  aot_eager={aot}")
print("fp64 truth std_mean:", torch.std_mean(x.double()))
