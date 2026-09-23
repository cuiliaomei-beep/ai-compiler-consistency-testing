# source: https://github.com/pytorch/pytorch/issues/182225
# title: torch.compile mismatch for bfloat16 RoPE-style computation involving rotate_half and broadcasted sin/cos
# state: closed  created: 2026-05-02
# mined automatically; the harness records the torch.compile target and its first call

import torch

print("torch:", torch.__version__)

def rotate_half(x):
    half = x.shape[-1] // 2
    return torch.cat((-x[..., half:], x[..., :half]), dim=-1)

def rope(q, k, cos, sin):
    cos = cos.unsqueeze(1)
    sin = sin.unsqueeze(1)
    q_out = (q * cos) + (rotate_half(q) * sin)
    k_out = (k * cos) + (rotate_half(k) * sin)
    return q_out, k_out

def run(dtype):
    torch._dynamo.reset()
    torch.manual_seed(123)

    q = torch.randn(1, 2, 7, 16, dtype=dtype)
    k = torch.randn(1, 1, 7, 16, dtype=dtype)
    cos = torch.randn(1, 7, 16, dtype=dtype)
    sin = torch.randn(1, 7, 16, dtype=dtype)

    eager = rope(q, k, cos, sin)
    compiled = torch.compile(
        rope,
        backend="inductor",
        fullgraph=True,
        dynamic=True,
    )(q, k, cos, sin)

    print(f"\n=== {dtype} ===")

    failures = []
    for name, e, c in zip(["q", "k"], eager, compiled):
        diff = (e.float() - c.float()).abs()
        print(
            name,
            "max_abs_diff=", diff.max().item(),
            "mean_abs_diff=", diff.mean().item(),
            "raw_diff_count=", int((diff != 0).sum()),
            "numel=", e.numel(),
        )
        try:
            torch.testing.assert_close(e, c)
        except Exception as exc:
            print(name, "assert_close failed")
            failures.append(f"{name}: {type(exc).__name__}: {str(exc).splitlines()[0]}")

    if failures:
        raise AssertionError("; ".join(failures))

    print("PASS")

run(torch.float32)
run(torch.bfloat16)
