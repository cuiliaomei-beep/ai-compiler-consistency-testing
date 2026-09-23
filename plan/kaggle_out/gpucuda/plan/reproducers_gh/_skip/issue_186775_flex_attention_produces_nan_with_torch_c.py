# source: https://github.com/pytorch/pytorch/issues/186775
# title: Flex Attention produces NaN with `torch.compile(flex_attention, dynamic=True)` and batch-dependent mask closures
# state: closed  created: 2026-06-09
# mined automatically; the harness records the torch.compile target and its first call

B, L, H, D = query_states.shape

q = query_states.transpose(1, 2)  # [B, H, L, D]
k = key_states.transpose(1, 2)
v = value_states.transpose(1, 2)

mask_mod = create_mf_mask(sample_id_map, modality_map)

block_mask = create_block_mask(
    mask_mod,
    B=B,
    H=None,
    Q_LEN=L,    # L is varying per batch
    KV_LEN=L,
    BLOCK_SIZE=128,
    _compile=False,
)

compiled_flex_attn = torch.compile(
    flex_attention,
    fullgraph=True,
    dynamic=True,
)

attn_output = compiled_flex_attn(q, k, v, block_mask=block_mask)
