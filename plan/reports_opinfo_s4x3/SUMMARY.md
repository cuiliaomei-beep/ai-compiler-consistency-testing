# Run summary

- **torch**: 2.14.0+cpu
- **device**: cpu
- **backend**: inductor
- **programs**: 1393
- **candidates**: 28
- **submittable**: 23
- **unique signatures**: 28
- **elapsed**: 15706.0s

## Candidates by priority

### high (23)

| signature | program | stage | probe | factor | oracles | repro |
|---|---|---|---|---|---|---|
| `d8fa75a4992b` | opinfo_var_mean_387 | inductor_codegen | layered | - | value | 2/2 |
| `0b907dc52c0c` | opinfo_var_mean_387 | inductor_codegen | layered | dtype | value | 2/2 |
| `6f527eb7f35b` | opinfo_var_mean_387 | inductor_codegen | layered | requires_grad | value | 2/2 |
| `9706dd9bbe58` | opinfo_var_mean_387 | inductor_codegen | layered | compile | value | 2/2 |
| `b1ab6da49f57` | opinfo_var_mean_unbiased | inductor_codegen | layered | - | value | 2/2 |
| `6f29e637cd30` | opinfo_var_mean_unbiased | inductor_codegen | layered | dtype | value | 2/2 |
| `4b7f97942e7f` | opinfo_var_mean_unbiased | inductor_codegen | layered | requires_grad | value | 2/2 |
| `919e3837134c` | opinfo_var_mean_unbiased | inductor_codegen | layered | compile | value | 2/2 |
| `b19bc7524c12` | opinfo_var_mean_unbiased_390 | inductor_codegen | layered | - | value | 2/2 |
| `29535294ac13` | opinfo_var_mean_unbiased_390 | inductor_codegen | layered | dtype | value | 2/2 |
| `6ee561ffc715` | opinfo_var_mean_unbiased_390 | inductor_codegen | layered | requires_grad | value | 2/2 |
| `13e889a7edd1` | opinfo_var_mean_unbiased_390 | inductor_codegen | layered | compile | value | 2/2 |
| `9da4e67e2fc0` | opinfo_std_mean_unbiased | inductor_codegen | layered | - | value | 2/2 |
| `3870c46d9909` | opinfo_std_mean_unbiased | inductor_codegen | layered | dtype | value | 2/2 |
| `20fc1e95204f` | opinfo_std_mean_unbiased | inductor_codegen | layered | requires_grad | value | 2/2 |
| `6a2474403458` | opinfo_std_mean_unbiased | inductor_codegen | layered | compile | value | 2/2 |
| `6db295e17ce5` | opinfo_std_mean_unbiased_397 | inductor_codegen | layered | - | value | 2/2 |
| `7796c9a71bb6` | opinfo_std_mean_unbiased_397 | inductor_codegen | layered | dtype | value | 2/2 |
| `8490bb1ecf58` | opinfo_std_mean_unbiased_397 | inductor_codegen | layered | requires_grad | value | 2/2 |
| `64d6517384dd` | opinfo_std_mean_unbiased_397 | inductor_codegen | layered | compile | value | 2/2 |
| `63f1de6d4bae` | opinfo_nn_functional_hinge_embedding_loss_1105 | inductor_codegen | layered | - | value | 2/2 |
| `7921f5376c5e` | opinfo_nn_functional_hinge_embedding_loss_1105 | inductor_codegen | layered | requires_grad | value | 2/2 |
| `5365f53b0420` | opinfo_nn_functional_hinge_embedding_loss_1105 | inductor_codegen | layered | compile | value | 2/2 |

### low (5)

| signature | program | stage | probe | factor | oracles | repro |
|---|---|---|---|---|---|---|
| `61562db3dff1` | opinfo_max_pool2d_with_indices_backward | dynamo_capture | layered | compile | exception | 2/2 |
| `ddfe4581389c` | opinfo_max_pool2d_with_indices_backward_50 | dynamo_capture | layered | compile | exception | 2/2 |
| `f1a08b407096` | opinfo_max_pool2d_with_indices_backward_51 | dynamo_capture | layered | compile | exception | 2/2 |
| `bdbf758e9efa` | opinfo_cov | dynamo_capture | layered | compile | exception | 2/2 |
| `5b07dfb7d786` | opinfo_cov_252 | dynamo_capture | layered | compile | exception | 2/2 |

