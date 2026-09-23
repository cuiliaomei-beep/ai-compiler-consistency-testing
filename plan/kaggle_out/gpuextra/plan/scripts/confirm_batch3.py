"""Seed-1 / grad sweep follow-ups: pixel_unshuffle on empty input, channel_shuffle strides, expand on 0-d, softmax int64."""
import os
import sys

HERE = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, HERE)
from tcc.compat import ensure_msvc_env  # noqa: E402

ensure_msvc_env()
import torch  # noqa: E402
import torch.nn.functional as F  # noqa: E402

print(torch.__version__)


def show(r):
    if isinstance(r, torch.Tensor):
        return f"shape={tuple(r.shape)} stride={tuple(r.stride())} dtype={str(r.dtype).replace('torch.', '')}"
    return repr(r)


def run(label, fn, *args, backends=("aot_eager", "inductor")):
    try:
        es = show(fn(*args))
    except Exception as ex:  # noqa: BLE001
        es = f"{type(ex).__name__}: {str(ex)[:90]}"
    out = [f"eager: {es}"]
    for b in backends:
        torch._dynamo.reset()
        try:
            out.append(f"{b}: {show(torch.compile(fn, backend=b)(*args))}")
        except Exception as ex:  # noqa: BLE001
            inner = ex
            while getattr(inner, '__cause__', None) is not None:
                inner = inner.__cause__
            out.append(f"{b}: {type(inner).__name__}: {str(inner)[:110]}")
    print(f"[{label}]\n   " + "\n   ".join(out))


# 1. pixel_unshuffle / pixel_shuffle on an empty batch
run("pixel_unshuffle (0,1,6,6) factor 3", lambda x: F.pixel_unshuffle(x, 3), torch.empty(0, 1, 6, 6))
run("pixel_unshuffle (2,1,6,6) factor 3", lambda x: F.pixel_unshuffle(x, 3), torch.randn(2, 1, 6, 6))
run("pixel_unshuffle (2,1,0,6) factor 3", lambda x: F.pixel_unshuffle(x, 3), torch.empty(2, 1, 0, 6))
run("pixel_shuffle (0,9,2,2) factor 3", lambda x: F.pixel_shuffle(x, 3), torch.empty(0, 9, 2, 2))
run("pixel_shuffle (2,9,2,2) factor 3", lambda x: F.pixel_shuffle(x, 3), torch.randn(2, 9, 2, 2))
# 2. channel_shuffle on a channels_last input: output memory format
x = torch.randn(2, 6, 8, 8).contiguous(memory_format=torch.channels_last)
run("channel_shuffle channels_last groups=2", lambda x: F.channel_shuffle(x, 2), x)
run("native_channel_shuffle channels_last", lambda x: torch.native_channel_shuffle(x, 2), x)
run("group_norm channels_last (stride)", lambda x: F.group_norm(x, 2), x)
# 3. expand on a 0-d tensor with -1
run("expand 0-d (-1,5,5)", lambda x: x.expand(-1, 5, 5), torch.tensor(1.5))
run("expand 0-d (5,5)", lambda x: x.expand(5, 5), torch.tensor(1.5))
# 4. softmax on int64 input with dtype=float32
run("softmax int64 dtype=float32", lambda x: torch.softmax(x, dim=0, dtype=torch.float32), torch.arange(5))
run("softmax int64 no dtype", lambda x: torch.softmax(x, dim=0), torch.arange(5))
run("softmin int64 dtype=float32", lambda x: F.softmin(x, dim=0, dtype=torch.float32), torch.arange(5))
run("log_softmax int64 dtype=float32", lambda x: torch.log_softmax(x, dim=0, dtype=torch.float32), torch.arange(5))
