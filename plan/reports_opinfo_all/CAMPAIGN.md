# Campaign

- started: 2026-09-08 08:22
- programs: 545
- candidates: 11
- tests: 8151
- errors: 0

## Status ledger (plan RQ5)

| status | n |
|---|---:|
| Generated | 0 |
| Submitted | 0 |
| Confirmed | 0 |
| Fixed | 0 |
| Duplicate | 5 |
| Invalid | 5 |
| Pending | 1 |

| signature | program | stage | priority | factor | repro | status |
|---|---|---|---|---|---|---|
| `0211b330cc67` | opinfo_var_mean | inductor_codegen | high | - | 2/2 | Pending |
| `0f1b7b8f1dc6` | opinfo_new_empty | compile_nondeterminism | medium | dtype | 1/2 | Invalid |
| `13828b145f92` | opinfo_new_empty_strided | cache_invalidation | high | dtype | 1/2 | Invalid |
| `282f0b8cd0fa` | opinfo_var_mean | inductor_codegen | high | requires_grad | 2/2 | Duplicate |
| `2c4aa34a458c` | opinfo_new_empty | cache_invalidation | high | requires_grad | 0/2 | Invalid |
| `3b6a5083ff89` | opinfo_var_mean | inductor_codegen | high | compile | 2/2 | Duplicate |
| `3c313d55c8e2` | opinfo_var_mean | inductor_codegen | high | dtype | 2/2 | Duplicate |
| `6468272fac80` | opinfo_max_pool2d_with_indices_backward | dynamo_capture | low | compile | 2/2 | Duplicate |
| `64e82aeff101` | opinfo_new_empty | cache_invalidation | high | dtype | 1/2 | Invalid |
| `7161f764494b` | opinfo_cov | dynamo_capture | low | compile | 2/2 | Duplicate |
| `94da24655a6e` | opinfo_nn_functional_soft_margin_loss | inductor_codegen | high | dtype | 2/2 | Invalid |

conversion (developer-actionable / generated): 0/11
