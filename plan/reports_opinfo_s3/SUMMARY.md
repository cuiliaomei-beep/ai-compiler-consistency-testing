# Run summary

- **torch**: 2.14.0+cpu
- **device**: cpu
- **backend**: inductor
- **programs**: 540
- **candidates**: 21
- **submittable**: 9
- **unique signatures**: 21
- **elapsed**: 5947.2s

## Candidates by priority

### high (6)

| signature | program | stage | probe | factor | oracles | repro |
|---|---|---|---|---|---|---|
| `11ddea7fd13c` | opinfo_nn_functional_multi_margin_loss | aot_functionalization | layered | dtype | exception | 2/2 |
| `43d01b3bbeec` | opinfo_new_empty | cache_invalidation | matrix | dtype | value | 2/2 |
| `d1765495c781` | opinfo_new_empty_strided | cache_invalidation | matrix | dtype | value | 1/2 |
| `e2ff23c37250` | opinfo_new_empty_strided | cache_invalidation | matrix | requires_grad | value | 0/2 |
| `37e7d7870f21` | opinfo_new_empty_strided | aot_functionalization | layered | compile | value | 0/2 |
| `645be2109059` | opinfo_new_empty_strided | aot_functionalization | layered | dtype | value | 1/2 |

### medium (3)

| signature | program | stage | probe | factor | oracles | repro |
|---|---|---|---|---|---|---|
| `13837d85e4fa` | opinfo_new_empty | compile_nondeterminism | matrix | requires_grad | value | 1/2 |
| `8b04478377ff` | opinfo_new_empty | compile_nondeterminism | matrix | dtype | value | 1/2 |
| `42f770c843c0` | opinfo_new_empty_strided | compile_nondeterminism | matrix | dtype | value | 1/2 |

### low (12)

| signature | program | stage | probe | factor | oracles | repro |
|---|---|---|---|---|---|---|
| `32499290a129` | opinfo_max_pool2d_with_indices_backward | dynamo_capture | layered | compile | exception | 2/2 |
| `149531700f54` | opinfo_nn_functional_binary_cross_entropy_with_logits | dynamo_capture | layered | resize | exception | 2/2 |
| `956b02bb30e6` | opinfo_nn_functional_local_response_norm | dynamo_capture | layered | rank | exception | 2/2 |
| `bdd560632a42` | opinfo_nn_functional_interpolate_linear | dynamo_capture | layered | rank | exception | 2/2 |
| `c0176ec1bfeb` | opinfo_nn_functional_interpolate_bicubic | dynamo_capture | layered | rank | exception | 2/2 |
| `34fa9b83500e` | opinfo_nn_functional_interpolate_trilinear | dynamo_capture | layered | rank | exception | 2/2 |
| `335edb1af632` | opinfo_nn_functional_interpolate_area | dynamo_capture | layered | rank | exception | 2/2 |
| `9953fe7318e2` | opinfo_nn_functional_binary_cross_entropy | dynamo_capture | layered | resize | exception | 2/2 |
| `6c59eb427924` | opinfo_new_empty | dynamo_capture | layered | dtype | value | 1/2 |
| `a8bd5795d4ba` | opinfo_new_empty | dynamo_capture | layered | compile | value | 1/2 |
| `c4398b2ccfef` | opinfo_new_empty_strided | dynamo_capture | layered | requires_grad | value | 1/2 |
| `7733daf44630` | opinfo_new_empty_strided | dynamo_capture | layered | compile | value | 0/2 |

