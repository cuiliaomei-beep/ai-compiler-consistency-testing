# Campaign

- started: 2026-09-08 10:52
- programs: 540
- candidates: 21
- tests: 7962
- errors: 0

## Status ledger (plan RQ5)

| status | n |
|---|---:|
| Generated | 0 |
| Submitted | 0 |
| Confirmed | 0 |
| Fixed | 0 |
| Duplicate | 2 |
| Invalid | 19 |
| Pending | 0 |

| signature | program | stage | priority | factor | repro | status |
|---|---|---|---|---|---|---|
| `11ddea7fd13c` | opinfo_nn_functional_multi_margin_loss | aot_functionalization | high | dtype | 2/2 | Duplicate |
| `13837d85e4fa` | opinfo_new_empty | compile_nondeterminism | medium | requires_grad | 1/2 | Invalid |
| `149531700f54` | opinfo_nn_functional_binary_cross_entropy_with_logits | dynamo_capture | low | resize | 2/2 | Invalid |
| `32499290a129` | opinfo_max_pool2d_with_indices_backward | dynamo_capture | low | compile | 2/2 | Duplicate |
| `335edb1af632` | opinfo_nn_functional_interpolate_area | dynamo_capture | low | rank | 2/2 | Invalid |
| `34fa9b83500e` | opinfo_nn_functional_interpolate_trilinear | dynamo_capture | low | rank | 2/2 | Invalid |
| `37e7d7870f21` | opinfo_new_empty_strided | aot_functionalization | high | compile | 0/2 | Invalid |
| `42f770c843c0` | opinfo_new_empty_strided | compile_nondeterminism | medium | dtype | 1/2 | Invalid |
| `43d01b3bbeec` | opinfo_new_empty | cache_invalidation | high | dtype | 2/2 | Invalid |
| `645be2109059` | opinfo_new_empty_strided | aot_functionalization | high | dtype | 1/2 | Invalid |
| `6c59eb427924` | opinfo_new_empty | dynamo_capture | low | dtype | 1/2 | Invalid |
| `7733daf44630` | opinfo_new_empty_strided | dynamo_capture | low | compile | 0/2 | Invalid |
| `8b04478377ff` | opinfo_new_empty | compile_nondeterminism | medium | dtype | 1/2 | Invalid |
| `956b02bb30e6` | opinfo_nn_functional_local_response_norm | dynamo_capture | low | rank | 2/2 | Invalid |
| `9953fe7318e2` | opinfo_nn_functional_binary_cross_entropy | dynamo_capture | low | resize | 2/2 | Invalid |
| `a8bd5795d4ba` | opinfo_new_empty | dynamo_capture | low | compile | 1/2 | Invalid |
| `bdd560632a42` | opinfo_nn_functional_interpolate_linear | dynamo_capture | low | rank | 2/2 | Invalid |
| `c0176ec1bfeb` | opinfo_nn_functional_interpolate_bicubic | dynamo_capture | low | rank | 2/2 | Invalid |
| `c4398b2ccfef` | opinfo_new_empty_strided | dynamo_capture | low | requires_grad | 1/2 | Invalid |
| `d1765495c781` | opinfo_new_empty_strided | cache_invalidation | high | dtype | 1/2 | Invalid |
| `e2ff23c37250` | opinfo_new_empty_strided | cache_invalidation | high | requires_grad | 0/2 | Invalid |

conversion (developer-actionable / generated): 0/21
