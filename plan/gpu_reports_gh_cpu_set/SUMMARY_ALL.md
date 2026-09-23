# Campaign summary (rebuilt from metadata)

- programs completed: 193
- records: 137
- submittable (high/medium): 85
- torch: 2.10.0+cu128

## high (85)

| signature | program | stage | probe | factor | oracles | repro | status |
|---|---|---|---|---|---|---|---|
| `6be6054cf276` | issue_160840_torch_nn_functional_interpolate_gener | aot_functionalization | layered | compile | value | 2/2 | Generated |
| `b082e0f17097` | issue_160840_torch_nn_functional_interpolate_gener | aot_functionalization | layered | - | value | 2/2 | Generated |
| `bbfc461be8a7` | issue_160840_torch_nn_functional_interpolate_gener | aot_functionalization | layered | requires_grad | value | 2/2 | Generated |
| `7238fca2848c` | issue_160840_torch_nn_functional_interpolate_gener | inductor_codegen | layered | dtype | value | 2/2 | Generated |
| `138a850da12b` | issue_174386_torch_compile_ignores_torch_use_deter | inductor_codegen | layered | - | value | 2/2 | Generated |
| `c8e3da048a2f` | issue_174386_torch_compile_ignores_torch_use_deter | inductor_codegen | layered | compile | value | 2/2 | Generated |
| `b737f71fffcb` | issue_174719_pallas_argmax_with_keepdim_true_on_mi | inductor_codegen | layered | - | value | 2/2 | Generated |
| `f79e81acc67b` | issue_174719_pallas_argmax_with_keepdim_true_on_mi | inductor_codegen | layered | compile | value | 2/2 | Generated |
| `645182fe9713` | issue_175156_inductor_multiple_randint_calls_cause | inductor_codegen | layered | - | value | 2/2 | Generated |
| `a6d67c365760` | issue_175156_inductor_multiple_randint_calls_cause | inductor_codegen | layered | compile | value | 2/2 | Generated |
| `315368b35d1b` | issue_175632_inductor_torch_compile_produces_incon | inductor_codegen | layered | compile | value | 2/2 | Generated |
| `bec282093f70` | issue_175632_inductor_torch_compile_produces_incon | inductor_codegen | layered | dtype | value | 2/2 | Generated |
| `c6585a76c04d` | issue_175632_inductor_torch_compile_produces_incon | inductor_codegen | layered | - | value | 2/2 | Generated |
| `a80d240e8eeb` | issue_175903_inductor_incorrect_results_in_index_p | inductor_codegen | layered | - | value, mutation | 2/2 | Generated |
| `1c6361e3fda0` | issue_175919_inductor_out_of_bounds_memory_read_vi | inductor_codegen | layered | compile | value | 2/2 | Generated |
| `8d9767847a77` | issue_175919_inductor_out_of_bounds_memory_read_vi | inductor_codegen | layered | dtype | value | 2/2 | Generated |
| `b3ffd22a7829` | issue_175919_inductor_out_of_bounds_memory_read_vi | inductor_codegen | layered | - | value | 2/2 | Generated |
| `31ffbabcc81b` | issue_177252_inductor_assertionerror_wrong_number_ | aot_functionalization | layered | requires_grad | metadata, value | 2/2 | Generated |
| `4a05b43de793` | issue_177252_inductor_assertionerror_wrong_number_ | aot_functionalization | layered | compile | metadata, value | 2/2 | Generated |
| `9b560cc9c2f8` | issue_177252_inductor_assertionerror_wrong_number_ | aot_functionalization | layered | dtype | metadata, value | 2/2 | Generated |
| `e088e5445458` | issue_177252_inductor_assertionerror_wrong_number_ | aot_functionalization | layered | - | metadata, value | 2/2 | Generated |
| `419c745be494` | issue_177629_torch_compile_backend_inductor_silent | inductor_codegen | layered | - | exception | 2/2 | Generated |
| `1b36156538f8` | issue_181568_torch_compile_mismatch_for_matmul_fol | inductor_codegen | layered | requires_grad | value, gradient | 2/2 | Generated |
| `2141064c29a5` | issue_181568_torch_compile_mismatch_for_matmul_fol | inductor_codegen | layered | compile | value | 2/2 | Generated |
| `bd0e5e06be92` | issue_181568_torch_compile_mismatch_for_matmul_fol | inductor_codegen | layered | dtype | value | 2/2 | Generated |
| `dfce1bcf7769` | issue_181568_torch_compile_mismatch_for_matmul_fol | inductor_codegen | layered | - | value | 2/2 | Generated |
| `013c4ae3e934` | issue_181625_assertionerror_expected_size_stride_m | inductor_codegen | layered | compile | exception | 2/2 | Generated |
| `277c49ca719d` | issue_181625_assertionerror_expected_size_stride_m | inductor_codegen | layered | compile | exception | 2/2 | Generated |
| `5830d06a5f70` | issue_181625_assertionerror_expected_size_stride_m | inductor_codegen | layered | - | exception | 2/2 | Generated |
| `02a53bfe419d` | issue_181693_nn_hardswish_produces_wrong_output_un | inductor_codegen | layered | compile | value | 2/2 | Generated |
| `644c6e8989e2` | issue_181693_nn_hardswish_produces_wrong_output_un | inductor_codegen | layered | - | value | 2/2 | Generated |
| `2d6a9ef101c3` | issue_181694_torch_addcdiv_produces_wrong_output_u | inductor_codegen | layered | - | value | 2/2 | Generated |
| `5eaac3595429` | issue_181694_torch_addcdiv_produces_wrong_output_u | inductor_codegen | layered | compile | value | 2/2 | Generated |
| `450b71f4c193` | issue_181695_torch_where_with_broadcast_shapes_pro | inductor_codegen | layered | - | value | 2/2 | Generated |
| `6d957df4ef4e` | issue_181695_torch_where_with_broadcast_shapes_pro | inductor_codegen | layered | compile | value | 2/2 | Generated |
| `26cc08f9e08f` | issue_182131_torch_compile_inductor_produces_diffe | inductor_codegen | layered | dtype | value | 2/2 | Generated |
| `7d78158b9809` | issue_182131_torch_compile_inductor_produces_diffe | inductor_codegen | layered | compile | value | 2/2 | Generated |
| `d2f60327ea7c` | issue_182131_torch_compile_inductor_produces_diffe | inductor_codegen | layered | requires_grad | value | 2/2 | Generated |
| `edb2ef25b17e` | issue_182131_torch_compile_inductor_produces_diffe | inductor_codegen | layered | - | value | 2/2 | Generated |
| `4fdc112db257` | issue_182965_torch_compile_silently_returns_a_resu | aot_functionalization | layered | - | exception | 2/2 | Generated |
| `5ffb5476b45d` | issue_183120_torch_compile_inductor_produces_wrong | inductor_codegen | layered | compile | value | 2/2 | Generated |
| `c5c29791d04a` | issue_183120_torch_compile_inductor_produces_wrong | inductor_codegen | layered | - | value | 2/2 | Generated |
| `2cdd2a7076b6` | issue_183121_torch_compile_returns_wrong_shape_for | inductor_codegen | layered | - | metadata, value | 2/2 | Generated |
| `c13830db798e` | issue_183121_torch_compile_returns_wrong_shape_for | inductor_codegen | layered | dtype | metadata, value | 2/2 | Generated |
| `e6a678ddfbd9` | issue_183121_torch_compile_returns_wrong_shape_for | inductor_codegen | layered | compile | metadata, value | 2/2 | Generated |
| `33e02cf82893` | issue_183601_torch_compile_inductor_produces_wrong | inductor_codegen | layered | compile | value | 2/2 | Generated |
| `b7260f42d43d` | issue_183601_torch_compile_inductor_produces_wrong | inductor_codegen | layered | - | value | 2/2 | Generated |
| `a1927317a81d` | issue_183607_torch_compile_changes_fp16_overflow_b | inductor_codegen | layered | requires_grad | value | 2/2 | Generated |
| `b610f2aee5d6` | issue_183607_torch_compile_changes_fp16_overflow_b | inductor_codegen | layered | compile | value | 2/2 | Generated |
| `bb4d985139a3` | issue_183607_torch_compile_changes_fp16_overflow_b | inductor_codegen | layered | dtype | value | 2/2 | Generated |
| `eacb6b88db9c` | issue_183607_torch_compile_changes_fp16_overflow_b | inductor_codegen | layered | - | value | 2/2 | Generated |
| `ddc30b59b7f0` | issue_185246_torch_compile_silently_accepts_invali | inductor_codegen | layered | - | exception | 2/2 | Generated |
| `0b19429353f5` | issue_185248_torch_compile_silently_accepts_negati | inductor_codegen | layered | - | exception | 2/2 | Generated |
| `4b073e5a902f` | issue_185481_inductor_argmax_over_comparison_mask_ | inductor_codegen | layered | - | exception | 2/2 | Generated |
| `51c49eddc26e` | issue_185587_inductor_numerical_inconsistency_poly | inductor_codegen | layered | - | value | 2/2 | Generated |
| `cc4d9affb449` | issue_185587_inductor_numerical_inconsistency_poly | inductor_codegen | layered | requires_grad | value | 2/2 | Generated |
| `d134e53413bd` | issue_185587_inductor_numerical_inconsistency_poly | inductor_codegen | layered | compile | value | 2/2 | Generated |
| `7d73c2553d18` | issue_187027_flip_after_repeat_interleave_generate | inductor_codegen | layered | compile | value | 2/2 | Generated |
| `549bae5e5b87` | issue_189518_inductor_s_pointless_cumsum_replaceme | inductor_codegen | layered | - | metadata, value | 2/2 | Generated |
| `df1a52a1416e` | issue_189518_inductor_s_pointless_cumsum_replaceme | inductor_codegen | layered | compile | metadata, value | 2/2 | Generated |
| `a6e334da4975` | issue_189787_inductor_constant_folds_sum_softmax_t | inductor_codegen | layered | dtype | value | 2/2 | Generated |
| `093d6127d075` | issue_193661_inductor_wrong_argmax_after_fused_tra | inductor_codegen | layered | requires_grad | value | 2/2 | Generated |
| `0ef98537b363` | issue_193661_inductor_wrong_argmax_after_fused_tra | inductor_codegen | layered | dtype | value | 2/2 | Generated |
| `3b8951712f43` | issue_193661_inductor_wrong_argmax_after_fused_tra | inductor_codegen | layered | - | value | 2/2 | Generated |
| `5bb974e08155` | issue_193661_inductor_wrong_argmax_after_fused_tra | inductor_codegen | layered | compile | value | 2/2 | Generated |
| `4a33347a73a5` | issue_193710_inductor_fallback_node_due_to_unsuppo | aot_functionalization | layered | requires_grad | gradient | 2/2 | Generated |
| `af4f302cca46` | issue_193811_torch_compile_silently_accepts_int32_ | aot_functionalization | layered | - | exception | 2/2 | Generated |
| `0ec09af1e3ee` | issue_194062_inductor_silent_incorrectness_torch_f | inductor_codegen | layered | - | value | 2/2 | Generated |
| `40170d036777` | issue_194062_inductor_silent_incorrectness_torch_f | inductor_codegen | layered | compile | value | 2/2 | Generated |
| `c2e79ca22ff0` | issue_194501_torch_compile_inductor_smooth_l1_loss | inductor_codegen | layered | - | exception | 2/2 | Generated |
| `aedb91e190c6` | issue_194547_torch_compile_silently_promotes_dtype | inductor_codegen | layered | compile | metadata | 2/2 | Generated |
| `d769053952ec` | issue_194547_torch_compile_silently_promotes_dtype | inductor_codegen | layered | - | metadata | 2/2 | Generated |
| `fec14e8e686c` | issue_194547_torch_compile_silently_promotes_dtype | inductor_codegen | layered | requires_grad | metadata | 2/2 | Generated |
| `2ad86ba19172` | issue_195320_inductor_sdpa_fusion_matches_a_permut | inductor_codegen | layered | - | value | 2/2 | Generated |
| `3a6b57762a33` | issue_195320_inductor_sdpa_fusion_matches_a_permut | inductor_codegen | layered | requires_grad | value | 2/2 | Generated |
| `e9ca0c44112a` | issue_195320_inductor_sdpa_fusion_matches_a_permut | inductor_codegen | layered | compile | value | 2/2 | Generated |
| `278a68befe59` | issue_195422_inductor_torch_compile_silently_drops | aot_functionalization | layered | compile | mutation, alias | 2/2 | Generated |
| `653c84c285b9` | issue_195422_inductor_torch_compile_silently_drops | aot_functionalization | layered | - | mutation, alias | 2/2 | Generated |
| `8fa2747fe54b` | issue_195422_inductor_torch_compile_silently_drops | aot_functionalization | layered | dtype | mutation, alias | 2/2 | Generated |
| `23aea4ad6e5f` | issue_195665_inductor_torch_compile_skips_as_strid | inductor_codegen | layered | - | exception | 2/2 | Generated |
| `b3f89a009fcc` | issue_195673_torch_compile_accepts_rand_like_on_an | inductor_codegen | layered | - | exception | 2/2 | Generated |
| `063be0ee1994` | issue_195674_torch_compile_evaluates_subtraction_o | inductor_codegen | layered | - | exception | 2/2 | Generated |
| `d7540d909e40` | issue_195675_torch_clamp_with_a_bound_unrepresenta | inductor_codegen | layered | - | exception | 2/2 | Generated |
| `71b953dfc7ab` | issue_95161_aotautograd_based_torch_compile_doesn_ | inductor_codegen | layered | - | value | 2/2 | Generated |
| `daba1be0d104` | issue_95161_aotautograd_based_torch_compile_doesn_ | inductor_codegen | layered | compile | value | 2/2 | Generated |

## low (52)

| signature | program | stage | probe | factor | oracles | repro | status |
|---|---|---|---|---|---|---|---|
| `015e900d1dd8` | issue_113641_compiling_double_inplace_clamp_on_str | dynamo_capture | layered | device | exception | 2/2 | Generated |
| `9287cdd0377a` | issue_113641_compiling_double_inplace_clamp_on_str | dynamo_capture | layered | compile | exception | 2/2 | Generated |
| `9f2778cffcff` | issue_113641_compiling_double_inplace_clamp_on_str | dynamo_capture | layered | - | exception | 2/2 | Generated |
| `af0e1cdc17d8` | issue_113641_compiling_double_inplace_clamp_on_str | dynamo_capture | layered | dtype | exception | 2/2 | Generated |
| `c104dbaa9664` | issue_113641_compiling_double_inplace_clamp_on_str | dynamo_capture | layered | requires_grad | exception | 2/2 | Generated |
| `2af77973fefe` | issue_114415_aotautograd_should_detect_aliasing_of | dynamo_capture | layered | - | exception | 2/2 | Generated |
| `7ab06356e264` | issue_114415_aotautograd_should_detect_aliasing_of | dynamo_capture | layered | compile | exception | 2/2 | Generated |
| `cf2f28ba0709` | issue_114415_aotautograd_should_detect_aliasing_of | dynamo_capture | layered | dtype | exception | 2/2 | Generated |
| `32b1c63feaab` | issue_176679_torch_compile_produces_incorrect_resu | dynamo_capture | layered | compile | exception | 2/2 | Generated |
| `dd20f71ed3d1` | issue_176679_torch_compile_produces_incorrect_resu | dynamo_capture | layered | - | exception | 2/2 | Generated |
| `08ffaf94c6c3` | issue_176854_torch_compile_does_not_correctly_prop | dynamo_capture | layered | requires_grad | value | 2/2 | Generated |
| `7495eef02f9e` | issue_178125_conv_transpose1d_meta_implementation_ | dynamo_capture | layered | compile | exception | 2/2 | Generated |
| `cb87c86c653a` | issue_178125_conv_transpose1d_meta_implementation_ | dynamo_capture | layered | - | exception | 2/2 | Generated |
| `005073e88f34` | issue_178128_conv_transpose3d_meta_execution_produ | dynamo_capture | layered | - | exception | 2/2 | Generated |
| `27e3f8bed866` | issue_178128_conv_transpose3d_meta_execution_produ | dynamo_capture | layered | compile | exception | 2/2 | Generated |
| `5c13fdde0656` | issue_179383_torch_quantile_and_torch_nanquantile_ | dynamo_capture | layered | compile | exception | 2/2 | Generated |
| `b40d0d03026a` | issue_181175_aot_autograd_runtimeerror_cannot_call | dynamo_capture | layered | - | exception | 2/2 | Generated |
| `33a570b3d793` | issue_181428_torch_compile_torch_func_grad_superli | dynamo_capture | layered | dtype | exception | 2/2 | Generated |
| `74b6f5ae2795` | issue_181428_torch_compile_torch_func_grad_superli | dynamo_capture | layered | requires_grad | exception | 2/2 | Generated |
| `deacc361fead` | issue_181428_torch_compile_torch_func_grad_superli | dynamo_capture | layered | - | exception | 2/2 | Generated |
| `f748589093f8` | issue_181428_torch_compile_torch_func_grad_superli | dynamo_capture | layered | compile | exception | 2/2 | Generated |
| `77980ec8237d` | issue_181653_torch_compile_torch_func_grad_fn_hang | dynamo_capture | layered | dtype | exception | 2/2 | Generated |
| `8a443851507d` | issue_181653_torch_compile_torch_func_grad_fn_hang | dynamo_capture | layered | - | exception | 2/2 | Generated |
| `aafd62a347fe` | issue_181653_torch_compile_torch_func_grad_fn_hang | dynamo_capture | layered | compile | exception | 2/2 | Generated |
| `e12844eef0cb` | issue_181653_torch_compile_torch_func_grad_fn_hang | dynamo_capture | layered | requires_grad | exception | 2/2 | Generated |
| `656533664503` | issue_181870_torch_compile_dynamic_true_fails_on_f | dynamo_capture | layered | compile | exception | 2/2 | Generated |
| `b75670df639b` | issue_182399_torch_compile_dynamic_true_fails_on_f | dynamo_capture | layered | compile | exception | 2/2 | Generated |
| `6d650bf30f35` | issue_184405_torch_compile_backend_inductor_return | dynamo_capture | layered | - | exception | 2/2 | Generated |
| `90551be8cf06` | issue_184405_torch_compile_backend_inductor_return | dynamo_capture | layered | compile | exception | 2/2 | Generated |
| `9f9f17163842` | issue_188084_bug_inductor_reinplaces_index_put_on_ | dynamo_capture | layered | - | exception | 2/2 | Generated |
| `f254bb88c24f` | issue_189528_cond_inductor_nameerror_on_inner_dim_ | dynamo_capture | layered | - | exception | 2/2 | Generated |
| `5760a6f4149a` | issue_190755_some_dynamo_descriptors_tp_descr_get_ | dynamo_capture | layered | compile | value | 2/2 | Generated |
| `65cdb9cbf304` | issue_190755_some_dynamo_descriptors_tp_descr_get_ | dynamo_capture | layered | - | value | 2/2 | Generated |
| `77712ec1d6ab` | issue_190755_some_dynamo_descriptors_tp_descr_get_ | dynamo_capture | layered | dtype | value | 2/2 | Generated |
| `f95ad207a5a8` | issue_190755_some_dynamo_descriptors_tp_descr_get_ | dynamo_capture | layered | requires_grad | value | 2/2 | Generated |
| `c11e3d242a45` | issue_190855_inductor_wrong_hessian_torch_compile_ | dynamo_capture | layered | - | exception | 2/2 | Generated |
| `e6235471dcc8` | issue_192905_nested_nested_compile_region_silently | dynamo_capture | layered | requires_grad | gradient | 2/2 | Generated |
| `0943fd907367` | issue_192985_dynamo_silently_drops_custom_jvp_of_a | dynamo_capture | layered | - | value | 2/2 | Generated |
| `465daa651bc8` | issue_192985_dynamo_silently_drops_custom_jvp_of_a | dynamo_capture | layered | dtype | value | 2/2 | Generated |
| `6218c276f95d` | issue_192985_dynamo_silently_drops_custom_jvp_of_a | dynamo_capture | layered | requires_grad | value, gradient | 2/2 | Generated |
| `c5a6f7958c59` | issue_192985_dynamo_silently_drops_custom_jvp_of_a | dynamo_capture | layered | compile | value | 2/2 | Generated |
| `1e1f7eb0f7aa` | issue_193279_dynamo_silently_drops_custom_backward | dynamo_capture | layered | - | exception | 2/2 | Generated |
| `32ae1243eda5` | issue_193279_dynamo_silently_drops_custom_backward | dynamo_capture | layered | dtype | exception | 2/2 | Generated |
| `661c68135450` | issue_193279_dynamo_silently_drops_custom_backward | dynamo_capture | layered | compile | exception | 2/2 | Generated |
| `de9f07323b0a` | issue_193279_dynamo_silently_drops_custom_backward | dynamo_capture | layered | requires_grad | exception | 2/2 | Generated |
| `a858b000314e` | issue_194103_torch_compile_dynamic_true_fails_for_ | dynamo_capture | layered | compile | exception | 2/2 | Generated |
| `9956d139f5a5` | issue_195977_scan_inductor_refuses_a_tanh_sigmoid_ | dynamo_capture | layered | - | exception | 2/2 | Generated |
| `20940ca4f2ca` | issue_196221_torch_compile_crashes_with_an_interna | dynamo_capture | layered | compile | exception | 2/2 | Generated |
| `62917c405e50` | issue_196221_torch_compile_crashes_with_an_interna | dynamo_capture | layered | dtype | exception | 2/2 | Generated |
| `74a043c71b8d` | issue_196221_torch_compile_crashes_with_an_interna | dynamo_capture | layered | - | exception | 2/2 | Generated |
| `e822c4aa9d24` | issue_196221_torch_compile_crashes_with_an_interna | dynamo_capture | layered | requires_grad | exception | 2/2 | Generated |
| `0040e8a6753e` | issue_196285_torch_compile_dynamic_true_fails_to_h | dynamo_capture | layered | compile | exception | 2/2 | Generated |

## by stage

- inductor_codegen: 72
- dynamo_capture: 52
- aot_functionalization: 13

## programs with submittable records

- issue_193661_inductor_wrong_argmax_after_fused_traili: 4
- issue_181568_torch_compile_mismatch_for_matmul_follow: 4
- issue_182131_torch_compile_inductor_produces_differen: 4
- issue_177252_inductor_assertionerror_wrong_number_of: 4
- issue_160840_torch_nn_functional_interpolate_generate: 4
- issue_183607_torch_compile_changes_fp16_overflow_beha: 4
- issue_181625_assertionerror_expected_size_stride_mism: 3
- issue_175919_inductor_out_of_bounds_memory_read_via_r: 3
- issue_195422_inductor_torch_compile_silently_drops_an: 3
- issue_195320_inductor_sdpa_fusion_matches_a_permuted: 3
- issue_183121_torch_compile_returns_wrong_shape_for_to: 3
- issue_175632_inductor_torch_compile_produces_inconsis: 3
- issue_185587_inductor_numerical_inconsistency_polygam: 3
- issue_194547_torch_compile_silently_promotes_dtype_fo: 3
- issue_181693_nn_hardswish_produces_wrong_output_under: 2
- issue_194062_inductor_silent_incorrectness_torch_full: 2
- issue_174386_torch_compile_ignores_torch_use_determin: 2
- issue_181694_torch_addcdiv_produces_wrong_output_unde: 2
- issue_183601_torch_compile_inductor_produces_wrong_ou: 2
- issue_181695_torch_where_with_broadcast_shapes_produc: 2
- issue_189518_inductor_s_pointless_cumsum_replacement: 2
- issue_183120_torch_compile_inductor_produces_wrong_ou: 2
- issue_175156_inductor_multiple_randint_calls_cause_in: 2
- issue_95161_aotautograd_based_torch_compile_doesn_t: 2
- issue_174719_pallas_argmax_with_keepdim_true_on_middl: 2
- issue_195674_torch_compile_evaluates_subtraction_on_a: 1
- issue_185248_torch_compile_silently_accepts_negative: 1
- issue_195665_inductor_torch_compile_skips_as_strided: 1
- issue_177629_torch_compile_backend_inductor_silently: 1
- issue_193710_inductor_fallback_node_due_to_unsupporte: 1
- issue_185481_inductor_argmax_over_comparison_mask_is: 1
- issue_182965_torch_compile_silently_returns_a_result: 1
- issue_187027_flip_after_repeat_interleave_generates_n: 1
- issue_189787_inductor_constant_folds_sum_softmax_to_e: 1
- issue_175903_inductor_incorrect_results_in_index_put: 1
- issue_193811_torch_compile_silently_accepts_int32_inp: 1
- issue_195673_torch_compile_accepts_rand_like_on_an_in: 1
- issue_194501_torch_compile_inductor_smooth_l1_loss_wi: 1
- issue_195675_torch_clamp_with_a_bound_unrepresentable: 1
- issue_185246_torch_compile_silently_accepts_invalid_b: 1
