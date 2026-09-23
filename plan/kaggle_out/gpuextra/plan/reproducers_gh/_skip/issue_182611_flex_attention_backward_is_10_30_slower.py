# source: https://github.com/pytorch/pytorch/issues/182611
# title: `flex_attention` backward is 10-30× slower than SDPA backward under `torch.compile(backend="aot_eager")` (math fallback materializes O(S²) and runs 114 ATen ops/layer)
# state: closed  created: 2026-05-06
# mined automatically; the harness records the torch.compile target and its first call

torch.compile(model, backend="aot_eager")
# + annotate flex_attention HOPs with compile_with_inductor (regional_inductor pass)
