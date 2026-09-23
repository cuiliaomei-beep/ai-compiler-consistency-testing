import os, sys
sys.path.insert(0, os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
try:
    from tcc.compat import ensure_msvc_env; ensure_msvc_env()
except Exception:
    pass
import torch, torch.nn.functional as F
print("torch", torch.__version__)
cases = {"pad(x[3], (-7, 7))": (lambda x: F.pad(x, (-7, 7)), (3,)), "pad(x[3], (-4, 4))": (lambda x: F.pad(x, (-4, 4)), (3,)), "pad(x[3], (-3, 3))": (lambda x: F.pad(x, (-3, 3)), (3,)),
         "pad(x[3], (7, -7))": (lambda x: F.pad(x, (7, -7)), (3,)), "pad(x[3], (-2, 0))": (lambda x: F.pad(x, (-2, 0)), (3,)), "pad(x[3], (-4, 0))": (lambda x: F.pad(x, (-4, 0)), (3,)),
         "pad(x[2,3], (-5, 5))": (lambda x: F.pad(x, (-5, 5)), (2, 3)), "pad(x[2,3], (0, 0, -3, 3))": (lambda x: F.pad(x, (0, 0, -3, 3)), (2, 3)),
         "constant_pad_nd value=9": (lambda x: F.pad(x, (-7, 7), value=9.0), (3,))}
for name, (f, shape) in cases.items():
    row = []
    for backend, dyn in ((None, None), ("aot_eager", False), ("inductor", False), ("inductor", True)):
        torch._dynamo.reset()
        x = torch.arange(1.0, 1 + torch.Size(shape).numel()).reshape(shape)
        try:
            y = (f if backend is None else torch.compile(f, backend=backend, dynamic=dyn))(x)
            row.append(f"returns shape {list(y.shape)} {y.flatten().tolist()}")
        except Exception as e:
            row.append("raises " + type(e).__name__ + ": " + str(e).splitlines()[0][:60])
    print(name); [print("     ", lab, r) for lab, r in zip(("eager           ", "aot_eager       ", "inductor        ", "inductor dynamic"), row)]
