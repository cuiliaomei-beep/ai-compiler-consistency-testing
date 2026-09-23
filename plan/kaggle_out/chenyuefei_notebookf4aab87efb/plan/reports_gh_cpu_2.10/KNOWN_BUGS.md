# Issue-reproducer campaign as a known-bug benchmark

reproducers: reproducers_gh   reports: reports_gh_cpu_2.10

| issue state | programs | detected | rate |
|---|---:|---:|---:|
| closed | 123 | 50 | 0.41 |
| open | 70 | 32 | 0.46 |

reading: open = defect expected to be present on this version (detected = recall); closed = expected fixed (detected = regression candidate or false positive, review needed)

| program | issue | state | detected | stages | tests |
|---|---|---|---|---|---:|
| issue_113641_compiling_double_inplace_clamp_on_stride | #113641 | closed | yes | dynamo_capture | 16 |
| issue_160840_torch_nn_functional_interpolate_generate | #160840 | closed | yes | aot_functionalization, inductor_codegen | 8 |
| issue_166514_inductor_fails_with_stride_mismatch_for | #166514 | closed | yes | inductor_codegen | 14 |
| issue_170666_inductor_fails_to_compile_models_contain | #170666 | closed | yes | inductor_codegen | 6 |
| issue_172711_torch_compile_produces_wrong_output_chan | #172711 | closed | yes | inductor_codegen | 6 |
| issue_174386_torch_compile_ignores_torch_use_determin | #174386 | closed | yes | inductor_codegen | 3 |
| issue_174969_torch_compile_outputs_incorrect_results | #174969 | closed | yes | inductor_codegen | 16 |
| issue_175156_inductor_multiple_randint_calls_cause_in | #175156 | closed | yes | inductor_codegen | 3 |
| issue_175496_inductor_model_with_torch_compile_output | #175496 | closed | yes | inductor_codegen | 16 |
| issue_175632_inductor_torch_compile_produces_inconsis | #175632 | closed | yes | inductor_codegen | 16 |
| issue_175919_inductor_out_of_bounds_memory_read_via_r | #175919 | closed | yes | inductor_codegen | 16 |
| issue_176679_torch_compile_produces_incorrect_results | #176679 | closed | yes | dynamo_capture | 3 |
| issue_176854_torch_compile_does_not_correctly_propaga | #176854 | closed | yes | dynamo_capture | 16 |
| issue_177252_inductor_assertionerror_wrong_number_of | #177252 | closed | yes | aot_functionalization | 16 |
| issue_177629_torch_compile_backend_inductor_silently | #177629 | closed | yes | inductor_codegen | 16 |
| issue_177821_inductor_torch_compile_ignores_a_complex | #177821 | closed | yes | inductor_codegen | 3 |
| issue_178125_conv_transpose1d_meta_implementation_all | #178125 | closed | yes | dynamo_capture | 3 |
| issue_178128_conv_transpose3d_meta_execution_produces | #178128 | closed | yes | dynamo_capture | 3 |
| issue_178262_inductor_incorrect_stride_calculation_in | #178262 | closed | yes | inductor_codegen | 6 |
| issue_178964_inductor_max_returns_incorrect_indices_w | #178964 | closed | yes | inductor_codegen | 16 |
| issue_179383_torch_quantile_and_torch_nanquantile_fai | #179383 | closed | yes | dynamo_capture | 9 |
| issue_179534_torch_compile_fails_on_aten_sparse_csr_t | #179534 | closed | yes | dynamo_capture | 6 |
| issue_179807_torch_compile_inductor_crash_f_pad_follo | #179807 | closed | yes | inductor_codegen | 16 |
| issue_181175_aot_autograd_runtimeerror_cannot_call_nu | #181175 | closed | yes | dynamo_capture | 6 |
| issue_181568_torch_compile_mismatch_for_matmul_follow | #181568 | closed | yes | inductor_codegen | 16 |
| issue_181625_assertionerror_expected_size_stride_mism | #181625 | closed | yes | inductor_codegen | 3 |
| issue_181693_nn_hardswish_produces_wrong_output_under | #181693 | closed | yes | inductor_codegen | 3 |
| issue_181694_torch_addcdiv_produces_wrong_output_unde | #181694 | closed | yes | inductor_codegen | 3 |
| issue_181695_torch_where_with_broadcast_shapes_produc | #181695 | closed | yes | inductor_codegen | 3 |
| issue_181870_torch_compile_dynamic_true_fails_on_f_cr | #181870 | closed | yes | dynamo_capture | 16 |
| issue_182131_torch_compile_inductor_produces_differen | #182131 | closed | yes | inductor_codegen | 16 |
| issue_182399_torch_compile_dynamic_true_fails_on_f_cr | #182399 | closed | yes | dynamo_capture | 16 |
| issue_182965_torch_compile_silently_returns_a_result | #182965 | closed | yes | aot_functionalization | 1 |
| issue_183082_inductor_cpu_returns_wrong_argmax_after | #183082 | closed | yes | inductor_codegen | 16 |
| issue_183121_torch_compile_returns_wrong_shape_for_to | #183121 | closed | yes | inductor_codegen | 16 |
| issue_183601_torch_compile_inductor_produces_wrong_ou | #183601 | closed | yes | inductor_codegen | 3 |
| issue_183763_torch_compile_overflows_torch_sinh_near | #183763 | closed | yes | inductor_codegen | 16 |
| issue_183765_torch_compile_overflows_torch_cosh_near | #183765 | closed | yes | inductor_codegen | 16 |
| issue_183767_torch_compile_returns_inf_for_torch_asin | #183767 | closed | yes | inductor_codegen | 16 |
| issue_185330_inductor_torch_index_select_on_uint16_in | #185330 | closed | yes | inductor_codegen | 1 |
| issue_187018_abs_on_uint8_silently_miscompiled_via_st | #187018 | closed | yes | inductor_codegen | 3 |
| issue_187027_flip_after_repeat_interleave_generates_n | #187027 | closed | yes | inductor_codegen | 3 |
| issue_188084_bug_inductor_reinplaces_index_put_on_exp | #188084 | closed | yes | dynamo_capture | 14 |
| issue_189518_inductor_s_pointless_cumsum_replacement | #189518 | closed | yes | inductor_codegen | 3 |
| issue_189528_cond_inductor_nameerror_on_inner_dim_bra | #189528 | closed | yes | dynamo_capture | 1 |
| issue_190755_some_dynamo_descriptors_tp_descr_get_imp | #190755 | closed | yes | dynamo_capture | 16 |
| issue_193279_dynamo_silently_drops_custom_backward_of | #193279 | closed | yes | dynamo_capture | 16 |
| issue_193661_inductor_wrong_argmax_after_fused_traili | #193661 | closed | yes | inductor_codegen | 16 |
| issue_195422_inductor_torch_compile_silently_drops_an | #195422 | closed | yes | aot_functionalization | 16 |
| issue_95161_aotautograd_based_torch_compile_doesn_t | #95161 | closed | yes | inductor_codegen | 3 |
| issue_114415_aotautograd_should_detect_aliasing_of_in | #114415 | open | yes | dynamo_capture | 16 |
| issue_181428_torch_compile_torch_func_grad_superlinea | #181428 | open | yes | dynamo_capture | 16 |
| issue_181653_torch_compile_torch_func_grad_fn_hangs_i | #181653 | open | yes | dynamo_capture | 16 |
| issue_183120_torch_compile_inductor_produces_wrong_ou | #183120 | open | yes | inductor_codegen | 3 |
| issue_183607_torch_compile_changes_fp16_overflow_beha | #183607 | open | yes | inductor_codegen | 16 |
| issue_183768_torch_compile_returns_inf_for_torch_acos | #183768 | open | yes | inductor_codegen | 16 |
| issue_185246_torch_compile_silently_accepts_invalid_b | #185246 | open | yes | inductor_codegen | 1 |
| issue_185248_torch_compile_silently_accepts_negative | #185248 | open | yes | inductor_codegen | 1 |
| issue_185481_inductor_argmax_over_comparison_mask_is | #185481 | open | yes | inductor_codegen | 1 |
| issue_186799_torch_compile_silently_produces_wrong_gr | #186799 | open | yes | inductor_codegen | 16 |
| issue_189787_inductor_constant_folds_sum_softmax_to_e | #189787 | open | yes | inductor_codegen | 16 |
| issue_190758_memory_budget_partitioner_recomputes_rng | #190758 | open | yes | aot_functionalization, inductor_codegen | 6 |
| issue_190855_inductor_wrong_hessian_torch_compile_tor | #190855 | open | yes | dynamo_capture | 6 |
| issue_192905_nested_nested_compile_region_silently_re | #192905 | open | yes | dynamo_capture | 16 |
| issue_192985_dynamo_silently_drops_custom_jvp_of_auto | #192985 | open | yes | dynamo_capture | 16 |
| issue_193710_inductor_fallback_node_due_to_unsupporte | #193710 | open | yes | aot_functionalization | 16 |
| issue_193757_inductor_cpu_torch_compile_silently_acce | #193757 | open | yes | inductor_codegen | 1 |
| issue_193811_torch_compile_silently_accepts_int32_inp | #193811 | open | yes | aot_functionalization | 1 |
| issue_194062_inductor_silent_incorrectness_torch_full | #194062 | open | yes | inductor_codegen | 3 |
| issue_194103_torch_compile_dynamic_true_fails_for_sca | #194103 | open | yes | dynamo_capture | 16 |
| issue_194501_torch_compile_inductor_smooth_l1_loss_wi | #194501 | open | yes | inductor_codegen | 1 |
| issue_194547_torch_compile_silently_promotes_dtype_fo | #194547 | open | yes | inductor_codegen | 16 |
| issue_195320_inductor_sdpa_fusion_matches_a_permuted | #195320 | open | yes | inductor_codegen | 6 |
| issue_195488_dynamo_autocast_context_manager_is_lower | #195488 | open | yes | inductor_codegen | 1 |
| issue_195579_meta_decomps_torch_compile_skips_addmm_s | #195579 | open | yes | inductor_codegen | 1 |
| issue_195665_inductor_torch_compile_skips_as_strided | #195665 | open | yes | inductor_codegen | 1 |
| issue_195673_torch_compile_accepts_rand_like_on_an_in | #195673 | open | yes | inductor_codegen | 1 |
| issue_195674_torch_compile_evaluates_subtraction_on_a | #195674 | open | yes | inductor_codegen | 1 |
| issue_195675_torch_clamp_with_a_bound_unrepresentable | #195675 | open | yes | inductor_codegen | 4 |
| issue_195977_scan_inductor_refuses_a_tanh_sigmoid_rec | #195977 | open | yes | dynamo_capture | 1 |
| issue_196221_torch_compile_crashes_with_an_internal_f | #196221 | open | yes | dynamo_capture | 16 |
| issue_196285_torch_compile_dynamic_true_fails_to_hand | #196285 | open | yes | dynamo_capture | 16 |
| issue_108432_wrong_result_of_first_run_with_torch_com | #108432 | closed | - |  | 3 |
| issue_109105_inductor_compiled_modules_produce_incorr | #109105 | closed | - | (earlier run) | 0 |
| issue_124357_torch_compile_produces_wrong_result_for | #124357 | closed | - |  | 3 |
| issue_126848_torch_compile_generates_wrong_code_on_cp | #126848 | closed | - |  | 16 |
| issue_128202_wrong_result_for_inplace_tensor_update_o | #128202 | closed | - | (earlier run) | 0 |
| issue_135432_torch_compile_cannot_handle_torch_tensor | #135432 | closed | - |  | 3 |
| issue_136662_composition_of_torch_compile_and_torch_f | #136662 | closed | - |  | 14 |
| issue_145372_xpu_torch_nn_functional_pad_brings_wrong | #145372 | closed | - | (earlier run) | 0 |
| issue_145466_torch_sin_cos_tan_torch_floor_round_may | #145466 | closed | - |  | 14 |
| issue_158626_freezing_layers_for_fine_tuning_leaves_t | #158626 | closed | - | (earlier run) | 0 |
| issue_159408_int64_mps_repeat_interleave_is_incorrect | #159408 | closed | - | (earlier run) | 0 |
| issue_160873_torch_compile_inductor_fails_on_mkl_dnn | #160873 | closed | - | (earlier run) | 0 |
| issue_161150_multiplication_and_softmax_throws_incorr | #161150 | closed | - |  | 16 |
| issue_161763_neg_add_computation_including_uint_tenso | #161763 | closed | - |  | 16 |
| issue_161905_mps_torch_compile_resnet_18_model_fails | #161905 | closed | - | (earlier run) | 0 |
| issue_167629_compile_error_torchdynamo_fails_to_compi | #167629 | closed | - | (earlier run) | 0 |
| issue_167636_torchdynamo_compilation_error_invalid_st | #167636 | closed | - | (earlier run) | 0 |
| issue_167641_torch_compile_fails_with_stride_mismatch | #167641 | closed | - | (earlier run) | 0 |
| issue_167780_inductor_combo_kernel_fails_with_cppsche | #167780 | closed | - |  | 16 |
| issue_170937_inductor_f_lp_pool_1_2_3_d_fail_with_ove | #170937 | closed | - |  | 16 |
| issue_170939_inductor_f_pdist_fails_with_runtimeerror | #170939 | closed | - |  | 9 |
| issue_171979_inductor_fails_to_compile_models_using_t | #171979 | closed | - |  | 16 |
| issue_172207_torch_compile_changes_random_mask_genera | #172207 | closed | - | (earlier run) | 0 |
| issue_174549_inconsistency_torch_nn_fractionalmaxpool | #174549 | closed | - |  | 14 |
| issue_174719_pallas_argmax_with_keepdim_true_on_middl | #174719 | closed | - |  | 3 |
| issue_175604_torch_compile_produces_stale_read_with_g | #175604 | closed | - | (earlier run) | 0 |
| issue_175791_inductor_incorrect_output_when_compiling | #175791 | closed | - |  | 16 |
| issue_175903_inductor_incorrect_results_in_index_put | #175903 | closed | - |  | 16 |
| issue_176596_torch_compile_does_not_correctly_invoke | #176596 | closed | - |  | 16 |
| issue_176599_torch_compile_bypasses_property_setter_a | #176599 | closed | - |  | 3 |
| issue_176686_tensor_subclass_using_torch_function_pro | #176686 | closed | - |  | 3 |
| issue_177451_torch_compile_fails_on_conv2d_with_kerne | #177451 | closed | - |  | 1 |
| issue_177631_inductor_torch_compile_produces_incorrec | #177631 | closed | - |  | 16 |
| issue_177652_inductor_torch_compile_s_rng_state_is_in | #177652 | closed | - |  | 16 |
| issue_177839_inductor_torch_compile_on_cpu_produces_i | #177839 | closed | - |  | 16 |
| issue_178259_inductor_c_compilation_error_when_conver | #178259 | closed | - |  | 3 |
| issue_178382_torch_compile_data_dependent_guard_fails | #178382 | closed | - |  | 3 |
| issue_178869_eager_then_compile_crashes_with_indexerr | #178869 | closed | - |  | 16 |
| issue_179026_torch_compile_guard_evaluation_crash_eva | #179026 | closed | - |  | 16 |
| issue_180841_inductor_importerror_file_too_short_when | #180841 | closed | - | (earlier run) | 0 |
| issue_180848_torch_compile_produces_wrong_results_whe | #180848 | closed | - | (earlier run) | 0 |
| issue_181115_inductor_torch_compile_dynamic_true_cras | #181115 | closed | - |  | 3 |
| issue_181384_aot_autograd_runtimeerror_pytorch_build | #181384 | closed | - |  | 3 |
| issue_181688_heap_corruption_sigabrt_when_compiling_c | #181688 | closed | - | (earlier run) | 0 |
| issue_182225_torch_compile_mismatch_for_bfloat16_rope | #182225 | closed | - |  | 16 |
| issue_182317_dynamo_leaks_torchfunctionmode_onto_stac | #182317 | closed | - |  | 3 |
| issue_183605_torch_compile_changes_fp16_nan_behavior | #183605 | closed | - |  | 14 |
| issue_183606_torch_compile_changes_signed_zero_behavi | #183606 | closed | - |  | 3 |
| issue_183761_torch_compile_produces_different_fp16_re | #183761 | closed | - | (earlier run) | 0 |
| issue_183889_torch_compile_fails_with_pendingunbacked | #183889 | closed | - | (earlier run) | 0 |
| issue_183894_torch_compile_returns_wrong_argmin_after | #183894 | closed | - | (earlier run) | 0 |
| issue_184405_torch_compile_backend_inductor_returns_s | #184405 | closed | - |  | 3 |
| issue_185405_inductor_assertionerror_len_index_len_st | #185405 | closed | - |  | 1 |
| issue_185488_dynamo_lazybatchnorm2d_fails_under_torch | #185488 | closed | - |  | 14 |
| issue_185515_inductor_tensor_view_dtype_after_transpo | #185515 | closed | - |  | 3 |
| issue_185575_inductor_upsample_mode_area_fails_under | #185575 | closed | - |  | 3 |
| issue_186671_dynamo_set_subclass_overriding_iter_give | #186671 | closed | - |  | 3 |
| issue_188074_torch_compile_produces_inconsistent_outp | #188074 | closed | - | (earlier run) | 0 |
| issue_188420_torch_compile_produces_inconsistent_outp | #188420 | closed | - | (earlier run) | 0 |
| issue_188425_torch_compile_produces_drastically_incor | #188425 | closed | - | (earlier run) | 0 |
| issue_188430_torch_compile_produces_large_absolute_er | #188430 | closed | - | (earlier run) | 0 |
| issue_188432_torch_compile_produces_inconsistent_outp | #188432 | closed | - | (earlier run) | 0 |
| issue_189271_inductor_keyerror_in_scheduler_compute_a | #189271 | closed | - |  | 1 |
| issue_189341_torch_compile_causes_segmentation_fault | #189341 | closed | - | (earlier run) | 0 |
| issue_189925_dynamo_io_text_encoding_causes_a_graph_b | #189925 | closed | - |  | 3 |
| issue_193876_inductor_compiling_two_torch_full_cumsum | #193876 | closed | - |  | 3 |
| issue_194558_inductor_in_place_padding_optimization_m | #194558 | closed | - |  | 6 |
| issue_195418_dynamo_canonicalize_output_graph_node_or | #195418 | closed | - | (earlier run) | 0 |
| issue_93357_pt2_compiled_model_with_cat_and_expand_g | #93357 | closed | - |  | 3 |
| issue_93363_aotautograd_returns_wrong_result_for_in | #93363 | closed | - |  | 16 |
| issue_93365_pt2_compiled_function_with_cat_and_mul_g | #93365 | closed | - |  | 3 |
| issue_95695_torch_ge_produces_wrong_results_in_compi | #95695 | closed | - |  | 3 |
| issue_96728_redundant_statement_leads_to_wrong_outpu | #96728 | closed | - |  | 16 |
| issue_139257_error_compiling_the_torch_library_custom | #139257 | open | - |  | 6 |
| issue_158561_torch_compile_in_place_operation_raises | #158561 | open | - |  | 6 |
| issue_177372_add_torch_narrow_scatter_operator_to_com | #177372 | open | - | (earlier run) | 0 |
| issue_178482_torch_compile_dynamic_true_ignores_incom | #178482 | open | - |  | 3 |
| issue_181851_register_fake_to_throw_error_if_signatur | #181851 | open | - |  | 16 |
| issue_182217_torch_compile_crashes_on_f_layer_norm_ne | #182217 | open | - | (earlier run) | 0 |
| issue_182318_dynamo_codegen_leaks_torch_function_enab | #182318 | open | - |  | 3 |
| issue_185494_dynamo_lazybatchnorm2d_fails_under_torch | #185494 | open | - |  | 14 |
| issue_185587_inductor_numerical_inconsistency_polygam | #185587 | open | - |  | 6 |
| issue_185589_inductor_severe_numerical_inconsistency | #185589 | open | - |  | 6 |
| issue_186875_inductor_fmod_remainder_with_python_floa | #186875 | open | - |  | 11 |
| issue_187953_torch_compile_out_variants_of_compositei | #187953 | open | - |  | 16 |
| issue_188536_graph_break_reconstruction_loses_identit | #188536 | open | - | (earlier run) | 0 |
| issue_188680_test_opinfo_gap_allclose_based_compile_v | #188680 | open | - | (earlier run) | 0 |
| issue_189808_inductor_sqrt_produces_negative_nan_0xff | #189808 | open | - |  | 16 |
| issue_190274_inductor_runtimeerror_self_stride_0_must | #190274 | open | - |  | 3 |
| issue_191136_inductor_torch_view_copy_fails_on_expand | #191136 | open | - |  | 16 |
| issue_191499_inductor_cpu_torch_compile_returns_0_for | #191499 | open | - |  | 3 |
| issue_191833_constraintviolationerror_is_not_raised_w | #191833 | open | - |  | 16 |
| issue_192872_dynamo_mutation_to_a_load_build_class_cr | #192872 | open | - | (earlier run) | 0 |
| issue_192906_reuse_hash_fn_leaves_a_subscripted_captu | #192906 | open | - | (earlier run) | 0 |
| issue_193490_inductor_batch_linear_lhs_fusion_leaks_w | #193490 | open | - | (earlier run) | 0 |
| issue_193809_torch_compile_torch_func_vjp_raises_inte | #193809 | open | - |  | 16 |
| issue_194001_aotautogradcache_stale_guards_expr_from | #194001 | open | - | (earlier run) | 0 |
| issue_194005_graphs_containing_linalg_cholesky_inv_so | #194005 | open | - |  | 9 |
| issue_194444_inductor_sdpa_fusion_silently_lost_when | #194444 | open | - |  | 16 |
| issue_194503_torch_compile_gaussian_nll_loss_fails_wi | #194503 | open | - |  | 16 |
| issue_194504_torch_compile_batchnorm1d_momentum_none | #194504 | open | - |  | 3 |
| issue_194548_torch_compile_silently_accepts_zero_batc | #194548 | open | - | (earlier run) | 0 |
| issue_194593_torch_compile_kl_divergence_binomial_bin | #194593 | open | - |  | 16 |
| issue_194596_torch_compile_wishart_mean_with_tensor_v | #194596 | open | - |  | 9 |
| issue_194765_torch_compile_adaptivelogsoftmaxwithloss | #194765 | open | - |  | 3 |
| issue_194766_torch_compile_torch_masked_median_fails | #194766 | open | - |  | 3 |
| issue_195282_inductor_dynamo_fake_tensor_tracing_reje | #195282 | open | - |  | 16 |
| issue_195582_inductor_silent_wrong_and_non_reproducib | #195582 | open | - |  | 6 |
| issue_195969_torch_compile_isinstance_x_protoa_protob | #195969 | open | - |  | 3 |
| issue_196173_torch_compile_produces_incorrect_results | #196173 | open | - |  | 0 |
| issue_196198_fullgraph_true_does_not_enforce_graph_br | #196198 | open | - |  | 16 |
