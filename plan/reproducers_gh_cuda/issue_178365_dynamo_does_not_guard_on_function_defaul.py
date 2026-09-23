# source: https://github.com/pytorch/pytorch/issues/178365
# title: Dynamo does not guard on function.__defaults__, causing silent correctness bugs with flex_attention
# state: closed  created: 2026-03-25
# mined automatically; the harness records the torch.compile target and its first call

"""
Minimal repro: Dynamo does not guard on function.__defaults__,
causing stale compiled graphs when mask_mod closures differ only
in their default-arg values.

flex_attention's mask_mod is inlined during compilation.  When a
compiled function is re-invoked with a new BlockMask whose mask_mod
has the same __code__ but different __defaults__, Dynamo reuses the
first graph (wrong offset baked in) instead of recompiling.
"""

import argparse

import torch
import torch._dynamo
from torch.nn.attention.flex_attention import (
    AuxRequest,
    create_block_mask,
    flex_attention,
)


@torch.compile(fullgraph=True)
def flex_chunk(q, k, v, block_mask, scale):
    out, aux = flex_attention(
        q, k, v, block_mask=block_mask, scale=scale, return_aux=AuxRequest(lse=True)
    )
    return out, aux.lse


def merge(out, lse, new_out, new_lse):
    lse, new_lse = lse.unsqueeze(-1), new_lse.unsqueeze(-1)
    mx = torch.maximum(lse, new_lse)
    e0, e1 = torch.exp(lse - mx), torch.exp(new_lse - mx)
    d = e0 + e1
    return (out * e0 + new_out * e1) / d, (mx + torch.log(d)).squeeze(-1)


@torch.compile(fullgraph=True)
def ref_attn(q, k, v, block_mask, scale):
    return flex_attention(q, k, v, block_mask=block_mask, scale=scale)


def main(fix_bug: bool = False):
    torch.manual_seed(42)
    B, H, S, D = 1, 1, 512, 16
    device = "cuda"
    NUM_CHUNKS = 4
    chunk_size = S // NUM_CHUNKS

    q = torch.randn(B, H, S, D, device=device)
    k = torch.randn(B, H, S, D, device=device)
    v = torch.randn(B, H, S, D, device=device)
    scale = D**-0.5

    merged_out = merged_lse = None
    for step in range(NUM_CHUNKS):
        kv_offset = step * chunk_size

        def mask_mod(b, h, q_idx, kv_idx, _offset=kv_offset):
            return q_idx >= kv_idx + _offset

        bm = create_block_mask(
            mask_mod, B=B, H=H, Q_LEN=S, KV_LEN=chunk_size, device=device
        )
        if fix_bug:
            torch._dynamo.reset()
        out, lse = flex_chunk(
            q, k[:, :, kv_offset : kv_offset + chunk_size],
            v[:, :, kv_offset : kv_offset + chunk_size], bm, scale,
        )
        if merged_out is None:
            merged_out, merged_lse = out, lse
        else:
            merged_out, merged_lse = merge(merged_out, merged_lse, out, lse)

    def causal(b, h, q_idx, kv_idx):
        return q_idx >= kv_idx

    ref_bm = create_block_mask(causal, B=B, H=H, Q_LEN=S, KV_LEN=S, device=device)
    ref_out = ref_attn(q, k, v, ref_bm, scale)

    diff = (merged_out - ref_out).abs()
    max_diff = diff.max().item()
    num_bad = (diff > 1e-4).sum().item()
    total = diff.numel()
    print(f"Max abs diff:       {max_diff:.6f}")
    print(f"Mismatched (>1e-4): {num_bad} / {total} ({100*num_bad/total:.1f}%)")

    if max_diff < 1e-3:
        print("PASS - __defaults__ properly guarded")
    else:
        print(
            "FAIL - __defaults__ NOT guarded; mask_mod offset baked in from first call"
        )


if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument("--fix-bug", action="store_true")
    args = parser.parse_args()
    main(fix_bug=args.fix_bug)
