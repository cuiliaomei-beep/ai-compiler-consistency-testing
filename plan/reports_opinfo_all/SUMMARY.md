# Run summary

- **torch**: 2.14.0+cpu
- **device**: cpu
- **backend**: inductor
- **programs**: 545
- **candidates**: 11
- **submittable**: 9
- **unique signatures**: 11
- **elapsed**: 5843.3s

## Candidates by priority

### high (8)

| signature | program | stage | probe | factor | oracles | repro |
|---|---|---|---|---|---|---|
| `0211b330cc67` | opinfo_var_mean | inductor_codegen | layered | - | value | 2/2 |
| `3c313d55c8e2` | opinfo_var_mean | inductor_codegen | layered | dtype | value | 2/2 |
| `282f0b8cd0fa` | opinfo_var_mean | inductor_codegen | layered | requires_grad | value | 2/2 |
| `3b6a5083ff89` | opinfo_var_mean | inductor_codegen | layered | compile | value | 2/2 |
| `94da24655a6e` | opinfo_nn_functional_soft_margin_loss | inductor_codegen | layered | dtype | value | 2/2 |
| `64e82aeff101` | opinfo_new_empty | cache_invalidation | matrix | dtype | value | 1/2 |
| `2c4aa34a458c` | opinfo_new_empty | cache_invalidation | matrix | requires_grad | value | 0/2 |
| `13828b145f92` | opinfo_new_empty_strided | cache_invalidation | matrix | dtype | value | 1/2 |

### medium (1)

| signature | program | stage | probe | factor | oracles | repro |
|---|---|---|---|---|---|---|
| `0f1b7b8f1dc6` | opinfo_new_empty | compile_nondeterminism | matrix | dtype | value | 1/2 |

### low (2)

| signature | program | stage | probe | factor | oracles | repro |
|---|---|---|---|---|---|---|
| `6468272fac80` | opinfo_max_pool2d_with_indices_backward | dynamo_capture | layered | compile | exception | 2/2 |
| `7161f764494b` | opinfo_cov | dynamo_capture | layered | compile | exception | 2/2 |

