"""dtype-matrix leads (Inductor): ldexp result dtype, huber_loss mixed low precision, lerp 0-d fp16 weight on bool, sum(dtype=bool)."""
import os, sys
sys.path.insert(0, os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
try:
    from tcc.compat import ensure_msvc_env; ensure_msvc_env()
except Exception:
    pass
import torch, torch.nn.functional as F
print("torch", torch.__version__)
torch._dynamo.config.recompile_limit = 1000
dev = sys.argv[1] if len(sys.argv) > 1 else "cpu"


def run(label, fn, *args):
    torch._dynamo.reset()
    out = []
    for name, f in (("eager", fn), ("aot_eager", torch.compile(fn, backend="aot_eager")), ("inductor", torch.compile(fn))):
        try:
            r = f(*args); out.append(f"{name}={str(r.dtype).split('.')[-1]}{tuple(r.shape)}")
        except Exception as e:
            out.append(f"{name}=raise {type(e).__name__}: {str(e).splitlines()[0][:90]}")
    print(f"[{label}] " + " | ".join(out))


f16 = torch.randn(3, 4, device=dev).half(); bf = torch.randn(3, 4, device=dev).bfloat16(); f32 = torch.randn(3, 4, device=dev)
i64 = torch.randint(1, 4, (3, 4), device=dev); b = i64 > 2
run("ldexp(bool, fp16)", torch.ldexp, b, f16)
run("ldexp(int64, fp16)", torch.ldexp, i64, f16)
run("ldexp(int64, bf16)", torch.ldexp, i64, bf)
run("ldexp(fp16, fp32)", torch.ldexp, f16, f32)
run("ldexp(fp16, bf16)", torch.ldexp, f16, bf)
run("ldexp(bf16, fp64)", torch.ldexp, bf, f32.double())
run("ldexp(fp16, fp16)", torch.ldexp, f16, f16)
run("ldexp(fp32, int64)", torch.ldexp, f32, i64)
run("huber_loss(fp16, bf16)", F.huber_loss, f16, bf)
run("huber_loss(fp16, fp32)", F.huber_loss, f16, f32)
run("huber_loss(bf16, fp16)", F.huber_loss, bf, f16)
run("smooth_l1_loss(fp16, fp32)", F.smooth_l1_loss, f16, f32)
run("mse_loss(fp16, fp32)", F.mse_loss, f16, f32)
run("l1_loss(fp16, fp32)", F.l1_loss, f16, f32)
run("huber_loss(fp16, fp32, delta=0.5)", lambda a, c: F.huber_loss(a, c, delta=0.5), f16, f32)
run("huber_loss(fp16, fp32, reduction=none)", lambda a, c: F.huber_loss(a, c, reduction="none"), f16, f32)
run("bce(fp16, fp16, weight=fp32)", lambda p, t, w: F.binary_cross_entropy(p, t, weight=w), f16.sigmoid(), f16.sigmoid(), f32.abs())
run("lerp(bool, bool, w=0-d fp16)", lambda a, w: torch.lerp(a, a, w), b, torch.tensor(0.3, dtype=torch.float16, device=dev))
run("lerp(bool, bool, w=fp16 tensor)", lambda a, w: torch.lerp(a, a, w), b, f16)
run("lerp(int64, int64, w=0-d fp16)", lambda a, w: torch.lerp(a, a, w), i64, torch.tensor(0.3, dtype=torch.float16, device=dev))
run("lerp(fp32, fp32, w=0-d fp16)", lambda a, w: torch.lerp(a, a, w), f32, torch.tensor(0.3, dtype=torch.float16, device=dev))
run("lerp(bool, bool, w=0-d fp32)", lambda a, w: torch.lerp(a, a, w), b, torch.tensor(0.3, device=dev))
run("sum(fp16, dtype=bool)", lambda a: torch.sum(a, dtype=torch.bool), f16)
run("sum(fp32, dtype=bool)", lambda a: torch.sum(a, dtype=torch.bool), f32)
run("sum(fp16, dtype=bool, dim=0)", lambda a: torch.sum(a, 0, dtype=torch.bool), f16)
run("cumsum(fp16, dtype=bool)", lambda a: torch.cumsum(a, 0, dtype=torch.bool), f16)
run("prod(fp32, dtype=bool)", lambda a: torch.prod(a, dtype=torch.bool), f32)
run("mean(int64, dtype=bool)", lambda a: torch.mean(a, dtype=torch.bool), i64)
