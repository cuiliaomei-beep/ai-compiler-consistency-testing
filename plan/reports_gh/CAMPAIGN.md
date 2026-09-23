# Campaign

- started: 2026-09-08 19:27
- programs: 161
- candidates: 60
- tests: 1337
- errors: 0

## Status ledger (plan RQ5)

| status | n |
|---|---:|
| Generated | 0 |
| Submitted | 0 |
| Confirmed | 0 |
| Fixed | 0 |
| Duplicate | 39 |
| Invalid | 10 |
| Pending | 11 |

| signature | program | stage | priority | factor | repro | status |
|---|---|---|---|---|---|---|
| `01e7d7ff690e` | issue_181693_nn_hardswish_produces_wrong_output_under | inductor_codegen | high | - | 2/2 | Invalid |
| `087f1e8abb9e` | issue_194103_torch_compile_dynamic_true_fails_for_sca | dynamo_capture | low | compile | 2/2 | Duplicate |
| `0aa4b5592adc` | issue_172711_torch_compile_produces_wrong_output_chan | inductor_codegen | high | requires_grad | 2/2 | Duplicate |
| `0ae5b597660d` | issue_192906_reuse_hash_fn_leaves_a_subscripted_captu | dynamo_capture | low | - | 2/2 | Duplicate |
| `16f619d5caa2` | issue_181568_torch_compile_mismatch_for_matmul_follow | inductor_codegen | high | compile | 2/2 | Invalid |
| `19d4074d336e` | issue_195320_inductor_sdpa_fusion_matches_a_permuted | inductor_codegen | high | requires_grad | 2/2 | Duplicate |
| `1b19cd3eb780` | issue_193279_dynamo_silently_drops_custom_backward_of | dynamo_capture | low | - | 2/2 | Duplicate |
| `1bab95a74251` | issue_183607_torch_compile_changes_fp16_overflow_beha | inductor_codegen | high | compile | 2/2 | Duplicate |
| `23701500fc91` | issue_183601_torch_compile_inductor_produces_wrong_ou | inductor_codegen | high | - | 2/2 | Invalid |
| `297eb0e49aa6` | issue_194062_inductor_silent_incorrectness_torch_full | inductor_codegen | high | - | 2/2 | Duplicate |
| `29a72882c400` | issue_177821_inductor_torch_compile_ignores_a_complex | inductor_codegen | high | - | 2/2 | Pending |
| `2ed38ba24729` | issue_192906_reuse_hash_fn_leaves_a_subscripted_captu | dynamo_capture | low | compile | 2/2 | Duplicate |
| `33d6ea524997` | issue_177821_inductor_torch_compile_ignores_a_complex | inductor_codegen | high | compile | 2/2 | Pending |
| `3c79a52a92f2` | issue_192985_dynamo_silently_drops_custom_jvp_of_auto | dynamo_capture | low | requires_grad | 2/2 | Duplicate |
| `3cf2966cd879` | issue_192872_dynamo_mutation_to_a_load_build_class_cr | cache_invalidation | high | dtype | 2/2 | Duplicate |
| `44a7b3ebf5a5` | issue_192985_dynamo_silently_drops_custom_jvp_of_auto | dynamo_capture | low | compile | 2/2 | Duplicate |
| `455f85ff6f45` | issue_172711_torch_compile_produces_wrong_output_chan | inductor_codegen | high | - | 2/2 | Duplicate |
| `46c241b62b30` | issue_176679_torch_compile_produces_incorrect_results | aot_functionalization | high | compile | 2/2 | Pending |
| `48bc41f22c8a` | issue_114415_aotautograd_should_detect_aliasing_of_in | dynamo_capture | low | dtype | 2/2 | Duplicate |
| `546b2345fbad` | issue_114415_aotautograd_should_detect_aliasing_of_in | dynamo_capture | low | compile | 2/2 | Duplicate |
| `54d84b9d07cb` | issue_183607_torch_compile_changes_fp16_overflow_beha | inductor_codegen | high | requires_grad | 2/2 | Duplicate |
| `54f05e4ce33c` | issue_194062_inductor_silent_incorrectness_torch_full | inductor_codegen | high | compile | 2/2 | Duplicate |
| `55710877a073` | issue_184405_torch_compile_backend_inductor_returns_s | inductor_codegen | high | compile | 1/2 | Pending |
| `5606657d1d94` | issue_196285_torch_compile_dynamic_true_fails_to_hand | dynamo_capture | low | compile | 2/2 | Duplicate |
| `642a2fac6e2d` | issue_192872_dynamo_mutation_to_a_load_build_class_cr | dynamo_capture | low | - | 2/2 | Duplicate |
| `66903ed30514` | issue_194547_torch_compile_silently_promotes_dtype_fo | inductor_codegen | high | - | 2/2 | Duplicate |
| `6f5e106b1e3a` | issue_192905_nested_nested_compile_region_silently_re | dynamo_capture | low | dtype | 2/2 | Duplicate |
| `73272a44e230` | issue_194547_torch_compile_silently_promotes_dtype_fo | inductor_codegen | high | compile | 2/2 | Duplicate |
| `735009ab83bf` | issue_182131_torch_compile_inductor_produces_differen | inductor_codegen | high | compile | 2/2 | Pending |
| `77b2ff947cf2` | issue_181695_torch_where_with_broadcast_shapes_produc | inductor_codegen | high | compile | 2/2 | Invalid |
| `7814f2bdefd6` | issue_193279_dynamo_silently_drops_custom_backward_of | dynamo_capture | low | requires_grad | 2/2 | Duplicate |
| `787386a59a0e` | issue_183601_torch_compile_inductor_produces_wrong_ou | inductor_codegen | high | compile | 2/2 | Invalid |
| `78e98fd2378d` | issue_192905_nested_nested_compile_region_silently_re | dynamo_capture | low | requires_grad | 2/2 | Duplicate |
| `7bdd3ea240a8` | issue_176679_torch_compile_produces_incorrect_results | aot_functionalization | high | - | 2/2 | Pending |
| `7cc71067c738` | issue_192906_reuse_hash_fn_leaves_a_subscripted_captu | dynamo_capture | low | requires_grad | 2/2 | Duplicate |
| `7fbdcd800863` | issue_181695_torch_where_with_broadcast_shapes_produc | inductor_codegen | high | - | 2/2 | Invalid |
| `814d8b39a8c7` | issue_160840_torch_nn_functional_interpolate_generate | inductor_codegen | high | dtype | 2/2 | Invalid |
| `8f3381e7f0d4` | issue_192985_dynamo_silently_drops_custom_jvp_of_auto | dynamo_capture | low | dtype | 2/2 | Duplicate |
| `929255de0d82` | issue_174386_torch_compile_ignores_torch_use_determin | inductor_codegen | high | - | 1/2 | Pending |
| `974eac1c1602` | issue_183607_torch_compile_changes_fp16_overflow_beha | inductor_codegen | high | dtype | 2/2 | Duplicate |
| `9b051c26b4a5` | issue_174386_torch_compile_ignores_torch_use_determin | inductor_codegen | high | compile | 0/2 | Pending |
| `9d71358d2c58` | issue_193279_dynamo_silently_drops_custom_backward_of | dynamo_capture | low | compile | 2/2 | Duplicate |
| `9fbf8d021588` | issue_182131_torch_compile_inductor_produces_differen | inductor_codegen | high | - | 2/2 | Pending |
| `a0f1c0dabe46` | issue_192905_nested_nested_compile_region_silently_re | dynamo_capture | low | compile | 2/2 | Duplicate |
| `a137aebe2584` | issue_181568_torch_compile_mismatch_for_matmul_follow | inductor_codegen | high | - | 2/2 | Invalid |
| `a767d9a17774` | issue_195320_inductor_sdpa_fusion_matches_a_permuted | inductor_codegen | high | - | 2/2 | Duplicate |
| `aa92cf17a769` | issue_192905_nested_nested_compile_region_silently_re | dynamo_capture | low | - | 2/2 | Duplicate |
| `c30c811c31cf` | issue_192872_dynamo_mutation_to_a_load_build_class_cr | dynamo_capture | low | dtype | 2/2 | Duplicate |
| `c6eeac238c56` | issue_182131_torch_compile_inductor_produces_differen | inductor_codegen | high | dtype | 2/2 | Pending |
| `cc621b6eb9c8` | issue_192985_dynamo_silently_drops_custom_jvp_of_auto | dynamo_capture | low | - | 2/2 | Duplicate |
| `d2f7fb6e942a` | issue_194547_torch_compile_silently_promotes_dtype_fo | inductor_codegen | high | requires_grad | 2/2 | Duplicate |
| `d4ba77da5bc4` | issue_114415_aotautograd_should_detect_aliasing_of_in | dynamo_capture | low | - | 2/2 | Duplicate |
| `daac7f1bbabc` | issue_195320_inductor_sdpa_fusion_matches_a_permuted | inductor_codegen | high | compile | 2/2 | Duplicate |
| `de67951c9994` | issue_182131_torch_compile_inductor_produces_differen | inductor_codegen | high | requires_grad | 2/2 | Pending |
| `e362df449001` | issue_183607_torch_compile_changes_fp16_overflow_beha | inductor_codegen | high | - | 2/2 | Duplicate |
| `e8b8bacce1f2` | issue_192906_reuse_hash_fn_leaves_a_subscripted_captu | dynamo_capture | low | dtype | 2/2 | Duplicate |
| `efc45343c177` | issue_193279_dynamo_silently_drops_custom_backward_of | dynamo_capture | low | dtype | 2/2 | Duplicate |
| `f76f742463ff` | issue_181568_torch_compile_mismatch_for_matmul_follow | inductor_codegen | high | requires_grad | 2/2 | Invalid |
| `fe1f0d83bc76` | issue_181693_nn_hardswish_produces_wrong_output_under | inductor_codegen | high | compile | 2/2 | Invalid |
| `ff6b6c3f13b6` | issue_189787_inductor_constant_folds_sum_softmax_to_e | inductor_codegen | high | dtype | 2/2 | Duplicate |

conversion (developer-actionable / generated): 0/60
