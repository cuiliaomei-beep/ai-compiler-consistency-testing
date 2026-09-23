"""torch.use_deterministic_algorithms(True): ops documented to raise (no deterministic implementation) -- does the compiled program still raise?
Forward and backward, CPU and (if available) CUDA.  Also: is `fill_uninitialized_memory` honoured?"""
import sys, warnings
try:
    import os
    sys.path.insert(0, os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
    from tcc.compat import ensure_msvc_env; ensure_msvc_env()
except Exception:
    pass
import torch, torch.nn.functional as F
warnings.simplefilter("ignore")
print("torch", torch.__version__, "cuda", torch.cuda.is_available(), flush=True)

def cases(dev):
    g = torch.Generator().manual_seed(0)
    R = lambda *s: torch.rand(*s, generator=g).to(dev)
    idx = torch.tensor([1, 1, 2], device=dev)
    fwd = {
        "put_(accumulate=False)": lambda: (lambda x, i, v: x.put_(i, v), (torch.zeros(4, device=dev), idx, R(3))),
        "kthvalue": lambda: (lambda x: torch.kthvalue(x, 2)[0], (R(3, 5),)),
        "median(dim) indices": lambda: (lambda x: torch.median(x, 1)[1], (R(3, 5),)),
        "bincount": lambda: (lambda i: torch.bincount(i, minlength=4), (idx,)),
        "histc": lambda: (lambda x: torch.histc(x, bins=4, min=0, max=1), (R(16),)),
        "cumsum": lambda: (lambda x: torch.cumsum(x, 0), (R(16),)),
        "scatter_(src tensor, dup idx)": lambda: (lambda x, i, s: x.scatter_(0, i, s), (torch.zeros(4, device=dev), idx, R(3))),
        "scatter_reduce prod": lambda: (lambda x, i, s: x.scatter_reduce(0, i, s, "prod"), (torch.ones(4, device=dev), idx, R(3))),
        "index_put_(accumulate=False, dup)": lambda: (lambda x, i, v: x.index_put_((i,), v), (torch.zeros(4, device=dev), idx, R(3))),
        "index_copy": lambda: (lambda x, i, s: x.index_copy(0, i, s), (torch.zeros(4, device=dev), idx, R(3))),
        "resize_ quantized-free": lambda: (lambda x: x.clone().resize_(8)[:2], (R(2),)),
    }
    bwd = {
        "interpolate bilinear backward": lambda: (lambda x: F.interpolate(x, scale_factor=2, mode="bilinear"), (R(1, 1, 4, 4),)),
        "interpolate bicubic backward": lambda: (lambda x: F.interpolate(x, scale_factor=2, mode="bicubic"), (R(1, 1, 4, 4),)),
        "interpolate linear backward": lambda: (lambda x: F.interpolate(x, scale_factor=2, mode="linear"), (R(1, 1, 4),)),
        "interpolate trilinear backward": lambda: (lambda x: F.interpolate(x, scale_factor=2, mode="trilinear"), (R(1, 1, 2, 2, 2),)),
        "grid_sample backward": lambda: (lambda x: F.grid_sample(x, torch.zeros(1, 2, 2, 2, device=dev), align_corners=False), (R(1, 1, 4, 4),)),
        "max_pool3d backward": lambda: (lambda x: F.max_pool3d(x, 2), (R(1, 1, 4, 4, 4),)),
        "adaptive_max_pool2d backward": lambda: (lambda x: F.adaptive_max_pool2d(x, 3), (R(1, 1, 7, 7),)),
        "adaptive_avg_pool2d backward": lambda: (lambda x: F.adaptive_avg_pool2d(x, 3), (R(1, 1, 7, 7),)),
        "adaptive_avg_pool3d backward": lambda: (lambda x: F.adaptive_avg_pool3d(x, 2), (R(1, 1, 5, 5, 5),)),
        "avg_pool3d backward": lambda: (lambda x: F.avg_pool3d(x, 2), (R(1, 1, 4, 4, 4),)),
        "fractional_max_pool2d backward": lambda: (lambda x: F.fractional_max_pool2d(x, 2, output_size=3, _random_samples=torch.full((1, 1, 2), 0.5, device=dev)), (R(1, 1, 7, 7),)),
        "reflection_pad1d backward": lambda: (lambda x: F.pad(x, (2, 2), mode="reflect"), (R(1, 1, 6),)),
        "reflection_pad2d backward": lambda: (lambda x: F.pad(x, (2, 2, 2, 2), mode="reflect"), (R(1, 1, 6, 6),)),
        "replication_pad1d backward": lambda: (lambda x: F.pad(x, (2, 2), mode="replicate"), (R(1, 1, 6),)),
        "replication_pad2d backward": lambda: (lambda x: F.pad(x, (2, 2, 2, 2), mode="replicate"), (R(1, 1, 6, 6),)),
        "nll_loss 2d backward": lambda: (lambda x: F.nll_loss(x, torch.zeros(1, 3, 3, dtype=torch.long, device=dev)), (R(1, 2, 3, 3),)),
        "ctc_loss backward": lambda: (lambda x: F.ctc_loss(x.log_softmax(2), torch.tensor([[1, 2]], device=dev), torch.tensor([5]), torch.tensor([2])), (R(5, 1, 4),)),
        "embedding_bag max backward": lambda: (lambda w: F.embedding_bag(torch.tensor([0, 1, 1, 2], device=dev), w, torch.tensor([0, 2], device=dev), mode="max"), (R(4, 3),)),
        "index_add backward-free fwd": lambda: (lambda x: torch.zeros(4, device=dev).index_add(0, idx, x), (R(3),)),
        "scatter_add fwd": lambda: (lambda x: torch.zeros(4, device=dev).scatter_add(0, idx, x), (R(3),)),
        "gather backward (dup idx)": lambda: (lambda x: x.gather(0, idx), (R(4),)),
        "take_along_dim backward": lambda: (lambda x: torch.take_along_dim(x, idx, 0), (R(4),)),
        "index_select backward": lambda: (lambda x: x.index_select(0, idx), (R(4),)),
        "repeat_interleave backward": lambda: (lambda x: x.repeat_interleave(idx), (R(3),)),
        "cumsum backward": lambda: (lambda x: torch.cumsum(x, 0), (R(16),)),
    }
    return fwd, bwd

def outcome(make, backend, backward):
    torch._dynamo.reset()
    f, args = make()
    args = tuple(a.clone().requires_grad_() if (backward and a.is_floating_point()) else a.clone() for a in args)
    g = f if backend is None else torch.compile(f, backend=backend)
    torch.use_deterministic_algorithms(True)
    try:
        y = g(*args)
        if backward:
            y.sum().backward()
        return "runs"
    except Exception as e:
        return "raises" if "deterministic" in str(e) else "ERR " + type(e).__name__
    finally:
        torch.use_deterministic_algorithms(False)

for dev in ["cpu"] + (["cuda"] if torch.cuda.is_available() else []):
    fwd, bwd = cases(dev)
    for backward, table in ((False, fwd), (True, bwd)):
        for name, make in table.items():
            row = [outcome(make, b, backward) for b in (None, "aot_eager", "inductor")]
            flag = "!!" if row[0] == "raises" and "runs" in row[1:] else "  "
            print(f"{flag} {dev:4s} {name:36s} eager: {row[0]:12s} aot_eager: {row[1]:12s} inductor: {row[2]}", flush=True)
    print("--- fill_uninitialized_memory on", dev, flush=True)
    fills = {"empty(5)": lambda x: torch.empty(5, device=dev), "empty_like(x)": lambda x: torch.empty_like(x), "x.new_empty(4)": lambda x: x.new_empty(4),
             "empty(3, int32)": lambda x: torch.empty(3, dtype=torch.int32, device=dev), "empty_strided": lambda x: torch.empty_strided((4,), (1,), device=dev),
             "empty_permuted": lambda x: torch.empty_permuted((2, 3), (1, 0), device=dev), "x.new_empty_strided": lambda x: x.new_empty_strided((4,), (1,))}
    for name, f in fills.items():
        row = []
        for b in (None, "aot_eager", "inductor"):
            torch._dynamo.reset(); torch.use_deterministic_algorithms(True)
            try:
                y = (f if b is None else torch.compile(f, backend=b))(torch.ones(6, device=dev))
                row.append("filled" if (torch.isnan(y).all() if y.is_floating_point() else (y == torch.iinfo(y.dtype).max).all()) else "NOT filled")
            except Exception as e:
                row.append("ERR " + type(e).__name__)
            finally:
                torch.use_deterministic_algorithms(False)
        flag = "!!" if row[0] == "filled" and "NOT filled" in row else "  "
        print(f"{flag} {dev:4s} {name:36s} eager: {row[0]:12s} aot_eager: {row[1]:12s} inductor: {row[2]}", flush=True)
