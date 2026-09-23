import os, sys, warnings
sys.path.insert(0, os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
try:
    from tcc.compat import ensure_msvc_env; ensure_msvc_env()
except Exception:
    pass
import torch
warnings.simplefilter("ignore")
print("torch", torch.__version__)

def show(name, make_call):
    row = []
    for backend in (None, "aot_eager", "inductor"):
        torch._dynamo.reset()
        try:
            r = make_call((lambda f: f) if backend is None else (lambda f: torch.compile(f, backend=backend)))
            row.append(f"returns {r}")
        except Exception as e:
            row.append(f"raises {type(e).__name__}")
    print(f"{name:52s} eager: {row[0]:32s} aot_eager: {row[1]:32s} inductor: {row[2]}")

def inference_inplace(C):
    with torch.inference_mode():
        x = torch.ones(3)
    C(lambda t: t.add_(1))(x)
    return x.tolist()
def inference_inplace_mul(C):
    with torch.inference_mode():
        x = torch.ones(3)
    C(lambda t: t.mul_(2).sum())(x)
    return x.tolist()
def det(fn):
    def run(C):
        torch.use_deterministic_algorithms(True)
        try:
            return fn(C)
        finally:
            torch.use_deterministic_algorithms(False)
    return run
show("in-place on inference tensor outside InferenceMode", inference_inplace)
show("in-place mul_ on inference tensor (+ reduction)", inference_inplace_mul)
show("deterministic: put_(accumulate=False)", det(lambda C: C(lambda x, i, v: x.put_(i, v, accumulate=False))(torch.zeros(4), torch.tensor([1, 1]), torch.tensor([1.0, 2.0])).tolist()))
show("deterministic: torch.put (functional)", det(lambda C: C(lambda x, i, v: torch.put(x, i, v))(torch.zeros(4), torch.tensor([1, 1]), torch.tensor([1.0, 2.0])).tolist()))
show("deterministic: empty() is NaN-filled", det(lambda C: bool(torch.isnan(C(lambda x: torch.empty(5) + 0 * x.sum())(torch.ones(2))).all())))
show("deterministic: empty_like() is NaN-filled", det(lambda C: bool(torch.isnan(C(lambda x: torch.empty_like(x))(torch.ones(6))).all())))
show("deterministic: new_empty() is NaN-filled", det(lambda C: bool(torch.isnan(C(lambda x: x.new_empty(4))(torch.ones(2))).all())))
show("deterministic: empty(int32) is MAX-filled", det(lambda C: C(lambda: torch.empty(3, dtype=torch.int32))().tolist() == [2 ** 31 - 1] * 3))
show("deterministic: resize_ tail is NaN-filled", det(lambda C: bool(torch.isnan(C(lambda x: x.clone().resize_(6))(torch.ones(2))[2:]).all())))
show("deterministic: empty_strided is NaN-filled", det(lambda C: bool(torch.isnan(C(lambda x: torch.empty_strided((4,), (1,)) + 0 * x.sum())(torch.ones(2))).all())))
