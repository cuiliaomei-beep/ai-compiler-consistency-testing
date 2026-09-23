# source: https://github.com/pytorch/pytorch/issues/187547
# title: Dynamo graph-breaks on raw unbacked SymInt BlockMask lengths in FlexAttention
# state: open  created: 2026-06-17
# mined automatically; the harness records the torch.compile target and its first call

import torch
from torch.fx.experimental.symbolic_shapes import ShapeEnv
from torch._subclasses.fake_tensor import FakeTensorMode
from torch.nn.attention.flex_attention import BlockMask, flex_attention

shape_env = ShapeEnv()
seq = shape_env.create_unbacked_symint()


@torch.compile(backend="eager", fullgraph=True)
def model(q, k, v, block_mask):
    return flex_attention(q, k, v, block_mask=block_mask)


with FakeTensorMode(shape_env=shape_env, allow_non_fake_inputs=True):
    q = torch.empty((1, 1, seq, 8), device="cpu")
    k = torch.empty((1, 1, seq, 8), device="cpu")
    v = torch.empty((1, 1, seq, 8), device="cpu")

    kv_num_blocks = torch.ones((1, 1, 1), dtype=torch.int32)
    kv_indices = torch.zeros((1, 1, 1, 1), dtype=torch.int32)
    block_mask = BlockMask.from_kv_blocks(
        kv_num_blocks,
        kv_indices,
        BLOCK_SIZE=128,
        seq_lengths=(seq, seq),
    )

    model(q, k, v, block_mask)
