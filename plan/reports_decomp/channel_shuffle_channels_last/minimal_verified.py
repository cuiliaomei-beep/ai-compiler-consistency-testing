"""F.channel_shuffle on a channels_last input: eager and aot_eager return channels_last, Inductor returns contiguous.

Verified on torch 2.14.0+cpu:
    eager    : shape=(2, 6, 8, 8) stride=(384, 1, 48, 6)    <- channels_last preserved
    aot_eager: shape=(2, 6, 8, 8) stride=(384, 1, 48, 6)
    inductor : shape=(2, 6, 8, 8) stride=(384, 64, 8, 1)    <- contiguous
Same for torch.native_channel_shuffle. group_norm on the same input keeps channels_last under Inductor, so this is
op-specific (the channel_shuffle lowering/decomposition does not carry the input's memory format).
Consequence: a channels_last model (ShuffleNet-style) silently switches layout mid-graph under compile; a
downstream `.stride()` / `is_contiguous(memory_format=...)` check or an `as_strided` view diverges from eager.
Found by the FakeTensor-vs-real stride differential (plan/tcc/decomp_diff.py), variant channels_last.
"""
import torch
import torch.nn.functional as F

x = torch.randn(2, 6, 8, 8).contiguous(memory_format=torch.channels_last)


def f(x):
    return F.channel_shuffle(x, 2)


print(torch.__version__)
print("eager    :", f(x).stride(), f(x).is_contiguous(memory_format=torch.channels_last))
for backend in ("aot_eager", "inductor"):
    torch._dynamo.reset()
    y = torch.compile(f, backend=backend)(x)
    print(f"{backend:<9}:", y.stride(), y.is_contiguous(memory_format=torch.channels_last))
