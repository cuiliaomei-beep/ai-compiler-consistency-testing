# source: https://github.com/pytorch/pytorch/issues/182217
# title: `torch.compile` crashes on `F.layer_norm(NestedTensor)` — `InternalTorchDynamoError` in guard building
# state: open  created: 2026-05-02
# mined automatically; the harness records the torch.compile target and its first call

@torch.compile(backend="inductor")
def fn(v, o):
    nt = torch.nested.nested_tensor_from_jagged(v, o)
    return (nt - nt.mean(-1, keepdim=True)).values().sum()

fn(values, offsets)  # Same crash
