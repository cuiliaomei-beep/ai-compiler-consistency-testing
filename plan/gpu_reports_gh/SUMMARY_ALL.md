# Campaign summary (rebuilt from metadata)

- programs completed: 336
- records: 234
- submittable (high/medium): 145
- torch: 2.10.0+cu128

## high (145)

| signature | program | stage | probe | factor | oracles | repro | status |
|---|---|---|---|---|---|---|---|
| `002f5bbedce7` | issue_122381_torch_compile_a_potential_oob_access_ | inductor_codegen | layered | compile | value | 2/2 | Generated |
| `07ae4dff030b` | issue_122381_torch_compile_a_potential_oob_access_ | inductor_codegen | layered | - | value | 2/2 | Generated |
| `bff0d93a5f10` | issue_122381_torch_compile_a_potential_oob_access_ | inductor_codegen | layered | requires_grad | value | 2/2 | Generated |
| `cd9c7a7f8494` | issue_122381_torch_compile_a_potential_oob_access_ | inductor_codegen | layered | dtype | value | 2/2 | Generated |
| `6be6054cf276` | issue_160840_torch_nn_functional_interpolate_gener | aot_functionalization | layered | compile | value | 2/2 | Generated |
| `b082e0f17097` | issue_160840_torch_nn_functional_interpolate_gener | aot_functionalization | layered | - | value | 2/2 | Generated |
| `bbfc461be8a7` | issue_160840_torch_nn_functional_interpolate_gener | aot_functionalization | layered | requires_grad | value | 2/2 | Generated |
| `7238fca2848c` | issue_160840_torch_nn_functional_interpolate_gener | inductor_codegen | layered | dtype | value | 2/2 | Generated |
| `0bb1c3b7130e` | issue_162522_torch_compile_generated_wrong_graph_w | aot_functionalization | layered | requires_grad | gradient | 2/2 | Generated |
| `4e0f76a0f6d6` | issue_171190_torch_compile_inductor_silently_ignor | inductor_codegen | layered | - | exception | 2/2 | Generated |
| `66441a9e53df` | issue_171191_torch_compile_inductor_ignores_float6 | inductor_codegen | layered | - | exception | 2/2 | Generated |
| `3da1c4b2e8aa` | issue_171493_incorrect_fusion_and_re_ordering_of_a | inductor_codegen | layered | requires_grad | value | 2/2 | Generated |
| `8076328a8810` | issue_171493_incorrect_fusion_and_re_ordering_of_a | inductor_codegen | layered | compile | value | 2/2 | Generated |
| `906e3fc1d83a` | issue_171493_incorrect_fusion_and_re_ordering_of_a | inductor_codegen | layered | - | value | 2/2 | Generated |
| `b20e267bf146` | issue_171493_incorrect_fusion_and_re_ordering_of_a | inductor_codegen | layered | dtype | value | 2/2 | Generated |
| `95c1c10902fa` | issue_172183_torch_compile_silently_bypasses_dtype | inductor_codegen | layered | - | exception | 2/2 | Generated |
| `43245bcf5fe4` | issue_172184_torch_compile_silently_bypasses_devic | inductor_codegen | layered | - | exception | 2/2 | Generated |
| `0179993fd606` | issue_173133_inductor_cuda_torch_bucketize_produce | inductor_codegen | layered | - | value | 2/2 | Generated |
| `4c730c4ba954` | issue_173133_inductor_cuda_torch_bucketize_produce | inductor_codegen | layered | compile | value | 2/2 | Generated |
| `5be76596664f` | issue_173133_inductor_cuda_torch_bucketize_produce | inductor_codegen | layered | requires_grad | value | 2/2 | Generated |
| `82934d5c9fc7` | issue_173133_inductor_cuda_torch_bucketize_produce | inductor_codegen | layered | dtype | value | 2/2 | Generated |
| `4168ee822801` | issue_174069_inductor_argmax_max_returns_incorrect | inductor_codegen | layered | - | value | 2/2 | Generated |
| `798e66d7ed9c` | issue_174069_inductor_argmax_max_returns_incorrect | inductor_codegen | layered | compile | value | 2/2 | Generated |
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
| `86d5094614d6` | issue_175966_silently_incorrect_results_for_torch_ | inductor_codegen | layered | - | value | 2/2 | Generated |
| `9241c3cf0755` | issue_175966_silently_incorrect_results_for_torch_ | inductor_codegen | layered | requires_grad | value | 2/2 | Generated |
| `94312a5f3039` | issue_175966_silently_incorrect_results_for_torch_ | inductor_codegen | layered | device | value | 2/2 | Generated |
| `bdc8ec26aacf` | issue_175966_silently_incorrect_results_for_torch_ | inductor_codegen | layered | dtype | value | 2/2 | Generated |
| `e1d84205f6df` | issue_175966_silently_incorrect_results_for_torch_ | inductor_codegen | layered | compile | value | 2/2 | Generated |
| `31ffbabcc81b` | issue_177252_inductor_assertionerror_wrong_number_ | aot_functionalization | layered | requires_grad | metadata, value | 2/2 | Generated |
| `4a05b43de793` | issue_177252_inductor_assertionerror_wrong_number_ | aot_functionalization | layered | compile | metadata, value | 2/2 | Generated |
| `9b560cc9c2f8` | issue_177252_inductor_assertionerror_wrong_number_ | aot_functionalization | layered | dtype | metadata, value | 2/2 | Generated |
| `e088e5445458` | issue_177252_inductor_assertionerror_wrong_number_ | aot_functionalization | layered | - | metadata, value | 2/2 | Generated |
| `419c745be494` | issue_177629_torch_compile_backend_inductor_silent | inductor_codegen | layered | - | exception | 2/2 | Generated |
| `e93563bcb9bc` | issue_177630_torch_compile_backend_inductor_silent | inductor_codegen | layered | - | exception | 2/2 | Generated |
| `070b704bdbba` | issue_179561_inductor_x_to_torch_bfloat16_float_pr | inductor_codegen | layered | - | value | 2/2 | Generated |
| `75454563d981` | issue_179561_inductor_x_to_torch_bfloat16_float_pr | inductor_codegen | layered | compile | value | 2/2 | Generated |
| `a275c9e95b2f` | issue_179561_inductor_x_to_torch_bfloat16_float_pr | inductor_codegen | layered | requires_grad | value, gradient | 2/2 | Generated |
| `df0347a934a5` | issue_179561_inductor_x_to_torch_bfloat16_float_pr | inductor_codegen | layered | dtype | value | 2/2 | Generated |
| `4f425f4c53be` | issue_180771_inductor_torch_compile_produces_wrong | inductor_codegen | layered | requires_grad | gradient | 2/2 | Generated |
| `013c4ae3e934` | issue_181625_assertionerror_expected_size_stride_m | inductor_codegen | layered | compile | exception | 2/2 | Generated |
| `277c49ca719d` | issue_181625_assertionerror_expected_size_stride_m | inductor_codegen | layered | compile | exception | 2/2 | Generated |
| `5830d06a5f70` | issue_181625_assertionerror_expected_size_stride_m | inductor_codegen | layered | - | exception | 2/2 | Generated |
| `02a53bfe419d` | issue_181693_nn_hardswish_produces_wrong_output_un | inductor_codegen | layered | compile | value | 2/2 | Generated |
| `644c6e8989e2` | issue_181693_nn_hardswish_produces_wrong_output_un | inductor_codegen | layered | - | value | 2/2 | Generated |
| `2d6a9ef101c3` | issue_181694_torch_addcdiv_produces_wrong_output_u | inductor_codegen | layered | - | value | 2/2 | Generated |
| `5eaac3595429` | issue_181694_torch_addcdiv_produces_wrong_output_u | inductor_codegen | layered | compile | value | 2/2 | Generated |
| `450b71f4c193` | issue_181695_torch_where_with_broadcast_shapes_pro | inductor_codegen | layered | - | value | 2/2 | Generated |
| `6d957df4ef4e` | issue_181695_torch_where_with_broadcast_shapes_pro | inductor_codegen | layered | compile | value | 2/2 | Generated |
| `918b26d08035` | issue_182012_torch_compile_silently_produces_all_z | inductor_codegen | layered | requires_grad | gradient | 2/2 | Generated |
| `26cc08f9e08f` | issue_182131_torch_compile_inductor_produces_diffe | inductor_codegen | layered | dtype | value | 2/2 | Generated |
| `7d78158b9809` | issue_182131_torch_compile_inductor_produces_diffe | inductor_codegen | layered | compile | value | 2/2 | Generated |
| `d2f60327ea7c` | issue_182131_torch_compile_inductor_produces_diffe | inductor_codegen | layered | requires_grad | value | 2/2 | Generated |
| `edb2ef25b17e` | issue_182131_torch_compile_inductor_produces_diffe | inductor_codegen | layered | - | value | 2/2 | Generated |
| `4a3d00053ff8` | issue_182200_torch_compile_crashes_on_stft_fftn_rf | inductor_codegen | layered | requires_grad | gradient | 2/2 | Generated |
| `6044e7ab968c` | issue_182343_torch_inductor_searchsorted_sliceview | inductor_codegen | layered | compile | value | 2/2 | Generated |
| `9555c684f368` | issue_182343_torch_inductor_searchsorted_sliceview | inductor_codegen | layered | - | value | 2/2 | Generated |
| `d40758f973ac` | issue_182766_torch_compile_crashes_on_sdpa_backwar | inductor_codegen | layered | requires_grad | gradient | 2/2 | Generated |
| `4fdc112db257` | issue_182965_torch_compile_silently_returns_a_resu | aot_functionalization | layered | - | exception | 2/2 | Generated |
| `5ffb5476b45d` | issue_183120_torch_compile_inductor_produces_wrong | inductor_codegen | layered | compile | value | 2/2 | Generated |
| `c5c29791d04a` | issue_183120_torch_compile_inductor_produces_wrong | inductor_codegen | layered | - | value | 2/2 | Generated |
| `2cdd2a7076b6` | issue_183121_torch_compile_returns_wrong_shape_for | inductor_codegen | layered | - | metadata, value | 2/2 | Generated |
| `c13830db798e` | issue_183121_torch_compile_returns_wrong_shape_for | inductor_codegen | layered | dtype | metadata, value | 2/2 | Generated |
| `e6a678ddfbd9` | issue_183121_torch_compile_returns_wrong_shape_for | inductor_codegen | layered | compile | metadata, value | 2/2 | Generated |
| `6a0b31b53c0c` | issue_183249_torch_compile_produces_wrong_results_ | inductor_codegen | layered | - | value | 2/2 | Generated |
| `b206051cde1b` | issue_183249_torch_compile_produces_wrong_results_ | inductor_codegen | layered | compile | value | 2/2 | Generated |
| `33e02cf82893` | issue_183601_torch_compile_inductor_produces_wrong | inductor_codegen | layered | compile | value | 2/2 | Generated |
| `b7260f42d43d` | issue_183601_torch_compile_inductor_produces_wrong | inductor_codegen | layered | - | value | 2/2 | Generated |
| `a1927317a81d` | issue_183607_torch_compile_changes_fp16_overflow_b | inductor_codegen | layered | requires_grad | value | 2/2 | Generated |
| `b610f2aee5d6` | issue_183607_torch_compile_changes_fp16_overflow_b | inductor_codegen | layered | compile | value | 2/2 | Generated |
| `bb4d985139a3` | issue_183607_torch_compile_changes_fp16_overflow_b | inductor_codegen | layered | dtype | value | 2/2 | Generated |
| `eacb6b88db9c` | issue_183607_torch_compile_changes_fp16_overflow_b | inductor_codegen | layered | - | value | 2/2 | Generated |
| `bdefa77fa547` | issue_183986_torch_compile_silently_produces_wrong | inductor_codegen | layered | compile | value | 2/2 | Generated |
| `d05da498e28a` | issue_183986_torch_compile_silently_produces_wrong | inductor_codegen | layered | - | value | 2/2 | Generated |
| `f1583263b909` | issue_183986_torch_compile_silently_produces_wrong | inductor_codegen | layered | requires_grad | value | 2/2 | Generated |
| `07d1d13245f8` | issue_184415_inductor_torch_foreach_sub_silently_i | inductor_codegen | layered | - | value | 2/2 | Generated |
| `a10a2e3bdd00` | issue_184415_inductor_torch_foreach_sub_silently_i | inductor_codegen | layered | compile | value | 2/2 | Generated |
| `ddc30b59b7f0` | issue_185246_torch_compile_silently_accepts_invali | inductor_codegen | layered | - | exception | 2/2 | Generated |
| `0b19429353f5` | issue_185248_torch_compile_silently_accepts_negati | inductor_codegen | layered | - | exception | 2/2 | Generated |
| `45f47fa6b0a4` | issue_185464_torch_compile_produces_wrong_results_ | aot_functionalization | layered | - | value | 2/2 | Generated |
| `feba701ff6c2` | issue_185464_torch_compile_produces_wrong_results_ | aot_functionalization | layered | compile | value | 2/2 | Generated |
| `4b073e5a902f` | issue_185481_inductor_argmax_over_comparison_mask_ | inductor_codegen | layered | - | exception | 2/2 | Generated |
| `399ffb634e52` | issue_185543_inductor_gradient_mismatch_between_ea | inductor_codegen | layered | requires_grad | gradient | 2/2 | Generated |
| `51c49eddc26e` | issue_185587_inductor_numerical_inconsistency_poly | inductor_codegen | layered | - | value | 2/2 | Generated |
| `cc4d9affb449` | issue_185587_inductor_numerical_inconsistency_poly | inductor_codegen | layered | requires_grad | value | 2/2 | Generated |
| `d134e53413bd` | issue_185587_inductor_numerical_inconsistency_poly | inductor_codegen | layered | compile | value | 2/2 | Generated |
| `319c8df0b7e5` | issue_186536_inductor_dynamic_shape_searchsorted_d | inductor_codegen | layered | - | exception | 0/2 | Generated |
| `7d73c2553d18` | issue_187027_flip_after_repeat_interleave_generate | inductor_codegen | layered | compile | value | 2/2 | Generated |
| `249983e43ca7` | issue_187935_inductor_cuda_torch_signbit_loses_neg | inductor_codegen | layered | requires_grad | value | 2/2 | Generated |
| `63de67285085` | issue_187935_inductor_cuda_torch_signbit_loses_neg | inductor_codegen | layered | - | value | 2/2 | Generated |
| `e69606bc94fb` | issue_187935_inductor_cuda_torch_signbit_loses_neg | inductor_codegen | layered | compile | value | 2/2 | Generated |
| `33f5c077c6d6` | issue_188541_inductor_cuda_f_logsigmoid_flushes_ne | inductor_codegen | layered | dtype | value | 2/2 | Generated |
| `52038452cf37` | issue_188541_inductor_cuda_f_logsigmoid_flushes_ne | inductor_codegen | layered | compile | value | 2/2 | Generated |
| `8f1af855d201` | issue_188541_inductor_cuda_f_logsigmoid_flushes_ne | inductor_codegen | layered | requires_grad | value | 2/2 | Generated |
| `d8921d1911c3` | issue_188541_inductor_cuda_f_logsigmoid_flushes_ne | inductor_codegen | layered | - | value | 2/2 | Generated |
| `549bae5e5b87` | issue_189518_inductor_s_pointless_cumsum_replaceme | inductor_codegen | layered | - | metadata, value | 2/2 | Generated |
| `df1a52a1416e` | issue_189518_inductor_s_pointless_cumsum_replaceme | inductor_codegen | layered | compile | metadata, value | 2/2 | Generated |
| `a6e334da4975` | issue_189787_inductor_constant_folds_sum_softmax_t | inductor_codegen | layered | dtype | value | 2/2 | Generated |
| `327da7e6c556` | issue_189895_inductor_silent_wrong_results_constan | inductor_codegen | layered | - | value | 2/2 | Generated |
| `d6540d2ceaf8` | issue_189895_inductor_silent_wrong_results_constan | inductor_codegen | layered | compile | value | 2/2 | Generated |
| `aef2dbdf9580` | issue_190093_test_interpolate_propagate_real_tenso | inductor_codegen | layered | compile | value | 2/2 | Generated |
| `e1dd16c79a91` | issue_190093_test_interpolate_propagate_real_tenso | inductor_codegen | layered | - | value | 2/2 | Generated |
| `7b538a63c5b1` | issue_191445_inductor_generated_aotautograd_forwar | inductor_codegen | layered | requires_grad | gradient | 2/2 | Generated |
| `59a9e5d82fb1` | issue_191571_torch_compile_silently_returns_stale_ | inductor_codegen | layered | compile | value | 2/2 | Generated |
| `7ae944555353` | issue_191571_torch_compile_silently_returns_stale_ | inductor_codegen | layered | requires_grad | value, gradient | 2/2 | Generated |
| `8b7f97e9bfa0` | issue_191571_torch_compile_silently_returns_stale_ | inductor_codegen | layered | - | value | 2/2 | Generated |
| `afe59e47a959` | issue_191571_torch_compile_silently_returns_stale_ | inductor_codegen | layered | dtype | value | 2/2 | Generated |
| `093d6127d075` | issue_193661_inductor_wrong_argmax_after_fused_tra | inductor_codegen | layered | requires_grad | value | 2/2 | Generated |
| `0ef98537b363` | issue_193661_inductor_wrong_argmax_after_fused_tra | inductor_codegen | layered | dtype | value | 2/2 | Generated |
| `3b8951712f43` | issue_193661_inductor_wrong_argmax_after_fused_tra | inductor_codegen | layered | - | value | 2/2 | Generated |
| `5bb974e08155` | issue_193661_inductor_wrong_argmax_after_fused_tra | inductor_codegen | layered | compile | value | 2/2 | Generated |
| `4a33347a73a5` | issue_193710_inductor_fallback_node_due_to_unsuppo | aot_functionalization | layered | requires_grad | gradient | 2/2 | Generated |
| `af4f302cca46` | issue_193811_torch_compile_silently_accepts_int32_ | aot_functionalization | layered | - | exception | 2/2 | Generated |
| `0ec09af1e3ee` | issue_194062_inductor_silent_incorrectness_torch_f | inductor_codegen | layered | - | value | 2/2 | Generated |
| `40170d036777` | issue_194062_inductor_silent_incorrectness_torch_f | inductor_codegen | layered | compile | value | 2/2 | Generated |
| `4ffe3c68cc0e` | issue_194345_inductor_cuda_torch_remainder_torch_f | inductor_codegen | layered | compile | value | 2/2 | Generated |
| `6d95da7a45b5` | issue_194345_inductor_cuda_torch_remainder_torch_f | inductor_codegen | layered | - | value | 2/2 | Generated |
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

## low (89)

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
| `0ea07dba7b08` | issue_168358_index_reduce_returns_nan_during_backw | dynamo_capture | layered | device | exception | 2/2 | Generated |
| `33202abf2730` | issue_168358_index_reduce_returns_nan_during_backw | dynamo_capture | layered | - | exception | 2/2 | Generated |
| `9061647cce29` | issue_168358_index_reduce_returns_nan_during_backw | dynamo_capture | layered | compile | exception | 2/2 | Generated |
| `f0ca34a103ee` | issue_168358_index_reduce_returns_nan_during_backw | dynamo_capture | layered | dtype | exception | 2/2 | Generated |
| `fed182b608f2` | issue_168358_index_reduce_returns_nan_during_backw | dynamo_capture | layered | requires_grad | exception | 2/2 | Generated |
| `35b890588972` | issue_170642_cudnn_init_dropout_state_crashes_with | dynamo_capture | layered | - | exception | 2/2 | Generated |
| `07641a01161f` | issue_170684_bug_inductor_numerical_inconsistency_ | dynamo_capture | layered | compile | exception | 2/2 | Generated |
| `676f2734aad6` | issue_170684_bug_inductor_numerical_inconsistency_ | dynamo_capture | layered | - | exception | 2/2 | Generated |
| `27c0f385cb13` | issue_171258_inductor_torchinductor_produces_incon | dynamo_capture | layered | compile | exception | 2/2 | Generated |
| `a2a9c440226c` | issue_171258_inductor_torchinductor_produces_incon | dynamo_capture | layered | - | exception | 2/2 | Generated |
| `781e52b7cbfe` | issue_171259_torch_acceleratorerror_cuda_error_dev | dynamo_capture | layered | - | exception | 2/2 | Generated |
| `c1ddfb20d1c6` | issue_171259_torch_acceleratorerror_cuda_error_dev | dynamo_capture | layered | compile | exception | 2/2 | Generated |
| `006630c5d3df` | issue_171282_inconsistency_inductor_binary_cross_e | dynamo_capture | layered | compile | exception | 2/2 | Generated |
| `c1bbfe9ffa8d` | issue_171282_inconsistency_inductor_binary_cross_e | dynamo_capture | layered | - | exception | 2/2 | Generated |
| `b9d1d2303aaf` | issue_171366_inconsistency_aten_view_copy_produces | dynamo_capture | layered | compile | exception | 2/2 | Generated |
| `c67c03644e53` | issue_171366_inconsistency_aten_view_copy_produces | dynamo_capture | layered | - | exception | 2/2 | Generated |
| `1c50e054b39b` | issue_173054_inconsistency_torchinductor_produces_ | dynamo_capture | layered | - | exception | 2/2 | Generated |
| `b1b79cb065a9` | issue_173054_inconsistency_torchinductor_produces_ | dynamo_capture | layered | compile | exception | 2/2 | Generated |
| `00a3be5ae7c2` | issue_173307_inconsistency_numerical_divergence_be | dynamo_capture | layered | compile | exception | 2/2 | Generated |
| `d7cd67ccd9c5` | issue_173307_inconsistency_numerical_divergence_be | dynamo_capture | layered | - | exception | 2/2 | Generated |
| `3725815730af` | issue_176310_inductor_cudagraph_trees_breaks_with_ | dynamo_capture | layered | - | exception | 2/2 | Generated |
| `32b1c63feaab` | issue_176679_torch_compile_produces_incorrect_resu | dynamo_capture | layered | compile | exception | 2/2 | Generated |
| `dd20f71ed3d1` | issue_176679_torch_compile_produces_incorrect_resu | dynamo_capture | layered | - | exception | 2/2 | Generated |
| `08ffaf94c6c3` | issue_176854_torch_compile_does_not_correctly_prop | dynamo_capture | layered | requires_grad | value | 2/2 | Generated |
| `2460662f23a8` | issue_178046_torch_compile_silently_accepts_nn_par | dynamo_capture | layered | - | exception | 2/2 | Generated |
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
| `03ec1fd0db34` | issue_182217_torch_compile_crashes_on_f_layer_norm | dynamo_capture | layered | dtype | exception | 2/2 | Generated |
| `12a620d8240b` | issue_182217_torch_compile_crashes_on_f_layer_norm | dynamo_capture | layered | compile | exception | 2/2 | Generated |
| `8025137b054c` | issue_182217_torch_compile_crashes_on_f_layer_norm | dynamo_capture | layered | requires_grad | exception | 2/2 | Generated |
| `ab06ab0b38d6` | issue_182217_torch_compile_crashes_on_f_layer_norm | dynamo_capture | layered | - | exception | 2/2 | Generated |
| `ab535633192b` | issue_182275_inductor_sympifyerror_cannot_sympify_ | dynamo_capture | layered | requires_grad | gradient | 2/2 | Generated |
| `b75670df639b` | issue_182399_torch_compile_dynamic_true_fails_on_f | dynamo_capture | layered | compile | exception | 2/2 | Generated |
| `263a040add0c` | issue_182606_flex_attention_mask_mod_closure_over_ | dynamo_capture | layered | - | exception | 2/2 | Generated |
| `6e67a1cf4ccc` | issue_182606_flex_attention_mask_mod_closure_over_ | dynamo_capture | layered | compile | exception | 2/2 | Generated |
| `ce1151c6a78a` | issue_182606_flex_attention_mask_mod_closure_over_ | dynamo_capture | layered | dtype | exception | 2/2 | Generated |
| `9f32c9f7d3c7` | issue_183018_torch_compile_torch_higher_order_ops_ | dynamo_capture | layered | - | exception | 2/2 | Generated |
| `bb1f5dbfe21f` | issue_183018_torch_compile_torch_higher_order_ops_ | dynamo_capture | layered | compile | exception | 2/2 | Generated |
| `54fd02aa90ec` | issue_183369_torch_compile_crashes_on_nested_tenso | dynamo_capture | layered | dtype | exception | 2/2 | Generated |
| `65582dce328c` | issue_183369_torch_compile_crashes_on_nested_tenso | dynamo_capture | layered | compile | exception | 2/2 | Generated |
| `a69f9400f3fc` | issue_183369_torch_compile_crashes_on_nested_tenso | dynamo_capture | layered | requires_grad | exception | 2/2 | Generated |
| `fbcba22f5504` | issue_183369_torch_compile_crashes_on_nested_tenso | dynamo_capture | layered | - | exception | 2/2 | Generated |
| `6d650bf30f35` | issue_184405_torch_compile_backend_inductor_return | dynamo_capture | layered | - | exception | 2/2 | Generated |
| `90551be8cf06` | issue_184405_torch_compile_backend_inductor_return | dynamo_capture | layered | compile | exception | 2/2 | Generated |
| `1ff4c4b659d6` | issue_185543_inductor_gradient_mismatch_between_ea | dynamo_capture | layered | compile | exception | 2/2 | Generated |
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

- inductor_codegen: 129
- dynamo_capture: 89
- aot_functionalization: 16

## programs with submittable records

- issue_175966_silently_incorrect_results_for_torch_ara: 5
- issue_122381_torch_compile_a_potential_oob_access_in: 4
- issue_173133_inductor_cuda_torch_bucketize_produces_i: 4
- issue_179561_inductor_x_to_torch_bfloat16_float_preci: 4
- issue_193661_inductor_wrong_argmax_after_fused_traili: 4
- issue_182131_torch_compile_inductor_produces_differen: 4
- issue_177252_inductor_assertionerror_wrong_number_of: 4
- issue_188541_inductor_cuda_f_logsigmoid_flushes_negat: 4
- issue_171493_incorrect_fusion_and_re_ordering_of_an_i: 4
- issue_191571_torch_compile_silently_returns_stale_zer: 4
- issue_160840_torch_nn_functional_interpolate_generate: 4
- issue_183607_torch_compile_changes_fp16_overflow_beha: 4
- issue_181625_assertionerror_expected_size_stride_mism: 3
- issue_175919_inductor_out_of_bounds_memory_read_via_r: 3
- issue_187935_inductor_cuda_torch_signbit_loses_negati: 3
- issue_195422_inductor_torch_compile_silently_drops_an: 3
- issue_195320_inductor_sdpa_fusion_matches_a_permuted: 3
- issue_183121_torch_compile_returns_wrong_shape_for_to: 3
- issue_175632_inductor_torch_compile_produces_inconsis: 3
- issue_185587_inductor_numerical_inconsistency_polygam: 3
- issue_194547_torch_compile_silently_promotes_dtype_fo: 3
- issue_183986_torch_compile_silently_produces_wrong_re: 3
- issue_181693_nn_hardswish_produces_wrong_output_under: 2
- issue_184415_inductor_torch_foreach_sub_silently_igno: 2
- issue_194062_inductor_silent_incorrectness_torch_full: 2
- issue_174386_torch_compile_ignores_torch_use_determin: 2
- issue_181694_torch_addcdiv_produces_wrong_output_unde: 2
- issue_189895_inductor_silent_wrong_results_constant_p: 2
- issue_183601_torch_compile_inductor_produces_wrong_ou: 2
- issue_174069_inductor_argmax_max_returns_incorrect_in: 2
- issue_181695_torch_where_with_broadcast_shapes_produc: 2
- issue_185464_torch_compile_produces_wrong_results_for: 2
- issue_194345_inductor_cuda_torch_remainder_torch_fmod: 2
- issue_189518_inductor_s_pointless_cumsum_replacement: 2
- issue_183120_torch_compile_inductor_produces_wrong_ou: 2
- issue_182343_torch_inductor_searchsorted_sliceview_bu: 2
- issue_175156_inductor_multiple_randint_calls_cause_in: 2
- issue_183249_torch_compile_produces_wrong_results_for: 2
- issue_95161_aotautograd_based_torch_compile_doesn_t: 2
- issue_190093_test_interpolate_propagate_real_tensors: 2
- issue_174719_pallas_argmax_with_keepdim_true_on_middl: 2
- issue_195674_torch_compile_evaluates_subtraction_on_a: 1
- issue_185248_torch_compile_silently_accepts_negative: 1
- issue_162522_torch_compile_generated_wrong_graph_when: 1
- issue_195665_inductor_torch_compile_skips_as_strided: 1
- issue_186536_inductor_dynamic_shape_searchsorted_deri: 1
- issue_185543_inductor_gradient_mismatch_between_eager: 1
- issue_177629_torch_compile_backend_inductor_silently: 1
- issue_172184_torch_compile_silently_bypasses_device_m: 1
- issue_193710_inductor_fallback_node_due_to_unsupporte: 1
- issue_182200_torch_compile_crashes_on_stft_fftn_rfftn: 1
- issue_185481_inductor_argmax_over_comparison_mask_is: 1
- issue_171190_torch_compile_inductor_silently_ignores: 1
- issue_180771_inductor_torch_compile_produces_wrong_gr: 1
- issue_182965_torch_compile_silently_returns_a_result: 1
- issue_171191_torch_compile_inductor_ignores_float64_f: 1
- issue_191445_inductor_generated_aotautograd_forward_w: 1
- issue_187027_flip_after_repeat_interleave_generates_n: 1
- issue_182012_torch_compile_silently_produces_all_zero: 1
- issue_172183_torch_compile_silently_bypasses_dtype_mi: 1
- issue_189787_inductor_constant_folds_sum_softmax_to_e: 1
- issue_175903_inductor_incorrect_results_in_index_put: 1
- issue_193811_torch_compile_silently_accepts_int32_inp: 1
- issue_195673_torch_compile_accepts_rand_like_on_an_in: 1
- issue_194501_torch_compile_inductor_smooth_l1_loss_wi: 1
- issue_182766_torch_compile_crashes_on_sdpa_backward_w: 1
- issue_195675_torch_clamp_with_a_bound_unrepresentable: 1
- issue_185246_torch_compile_silently_accepts_invalid_b: 1
- issue_177630_torch_compile_backend_inductor_silently: 1
