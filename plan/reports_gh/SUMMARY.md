# Run summary

- **torch**: 2.14.0+cpu
- **device**: cpu
- **backend**: inductor
- **programs**: 50
- **candidates**: 29
- **submittable**: 9
- **unique signatures**: 60
- **elapsed**: 2154.3s

## Candidates by priority

### high (9)

| signature | program | stage | probe | factor | oracles | repro |
|---|---|---|---|---|---|---|
| `3cf2966cd879` | issue_192872_dynamo_mutation_to_a_load_build_class_cr | cache_invalidation | matrix | dtype | value | 2/2 |
| `297eb0e49aa6` | issue_194062_inductor_silent_incorrectness_torch_full | inductor_codegen | layered | - | value | 2/2 |
| `54f05e4ce33c` | issue_194062_inductor_silent_incorrectness_torch_full | inductor_codegen | layered | compile | value | 2/2 |
| `66903ed30514` | issue_194547_torch_compile_silently_promotes_dtype_fo | inductor_codegen | layered | - | exception | 2/2 |
| `d2f7fb6e942a` | issue_194547_torch_compile_silently_promotes_dtype_fo | inductor_codegen | layered | requires_grad | exception | 2/2 |
| `73272a44e230` | issue_194547_torch_compile_silently_promotes_dtype_fo | inductor_codegen | layered | compile | exception | 2/2 |
| `a767d9a17774` | issue_195320_inductor_sdpa_fusion_matches_a_permuted | inductor_codegen | layered | - | value | 2/2 |
| `19d4074d336e` | issue_195320_inductor_sdpa_fusion_matches_a_permuted | inductor_codegen | layered | requires_grad | value | 2/2 |
| `daac7f1bbabc` | issue_195320_inductor_sdpa_fusion_matches_a_permuted | inductor_codegen | layered | compile | value | 2/2 |

### low (20)

| signature | program | stage | probe | factor | oracles | repro |
|---|---|---|---|---|---|---|
| `642a2fac6e2d` | issue_192872_dynamo_mutation_to_a_load_build_class_cr | dynamo_capture | layered | - | value | 2/2 |
| `c30c811c31cf` | issue_192872_dynamo_mutation_to_a_load_build_class_cr | dynamo_capture | layered | dtype | value | 2/2 |
| `aa92cf17a769` | issue_192905_nested_nested_compile_region_silently_re | dynamo_capture | layered | - | value | 2/2 |
| `6f5e106b1e3a` | issue_192905_nested_nested_compile_region_silently_re | dynamo_capture | layered | dtype | value | 2/2 |
| `78e98fd2378d` | issue_192905_nested_nested_compile_region_silently_re | dynamo_capture | layered | requires_grad | value | 2/2 |
| `a0f1c0dabe46` | issue_192905_nested_nested_compile_region_silently_re | dynamo_capture | layered | compile | value | 2/2 |
| `0ae5b597660d` | issue_192906_reuse_hash_fn_leaves_a_subscripted_captu | dynamo_capture | layered | - | value | 2/2 |
| `e8b8bacce1f2` | issue_192906_reuse_hash_fn_leaves_a_subscripted_captu | dynamo_capture | layered | dtype | value | 2/2 |
| `7cc71067c738` | issue_192906_reuse_hash_fn_leaves_a_subscripted_captu | dynamo_capture | layered | requires_grad | value | 2/2 |
| `2ed38ba24729` | issue_192906_reuse_hash_fn_leaves_a_subscripted_captu | dynamo_capture | layered | compile | value | 2/2 |
| `cc621b6eb9c8` | issue_192985_dynamo_silently_drops_custom_jvp_of_auto | dynamo_capture | layered | - | value | 2/2 |
| `8f3381e7f0d4` | issue_192985_dynamo_silently_drops_custom_jvp_of_auto | dynamo_capture | layered | dtype | value | 2/2 |
| `3c79a52a92f2` | issue_192985_dynamo_silently_drops_custom_jvp_of_auto | dynamo_capture | layered | requires_grad | value | 2/2 |
| `44a7b3ebf5a5` | issue_192985_dynamo_silently_drops_custom_jvp_of_auto | dynamo_capture | layered | compile | value | 2/2 |
| `1b19cd3eb780` | issue_193279_dynamo_silently_drops_custom_backward_of | dynamo_capture | layered | - | value | 2/2 |
| `efc45343c177` | issue_193279_dynamo_silently_drops_custom_backward_of | dynamo_capture | layered | dtype | value | 2/2 |
| `7814f2bdefd6` | issue_193279_dynamo_silently_drops_custom_backward_of | dynamo_capture | layered | requires_grad | value | 2/2 |
| `9d71358d2c58` | issue_193279_dynamo_silently_drops_custom_backward_of | dynamo_capture | layered | compile | value | 2/2 |
| `087f1e8abb9e` | issue_194103_torch_compile_dynamic_true_fails_for_sca | dynamo_capture | layered | compile | exception | 2/2 |
| `5606657d1d94` | issue_196285_torch_compile_dynamic_true_fails_to_hand | dynamo_capture | layered | compile | exception | 2/2 |

