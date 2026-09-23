# Issue-reproducer campaign as a known-bug benchmark

reproducers: reproducers_gh_cuda   reports: gpu_reports_gh

| issue state | programs | detected | rate |
|---|---:|---:|---:|
| closed | 236 | 75 | 0.32 |
| open | 100 | 34 | 0.34 |

reading: open = defect expected to be present on this version (detected = recall); closed = expected fixed (detected = regression candidate or false positive, review needed)

| program | issue | state | detected | stages | tests |
|---|---|---|---|---|---:|
| issue_113641_compiling_double_inplace_clamp_on_stride | #113641 | closed | yes | dynamo_capture | 16 |
| issue_122381_torch_compile_a_potential_oob_access_in | #122381 | closed | yes | inductor_codegen | 16 |
| issue_160840_torch_nn_functional_interpolate_generate | #160840 | closed | yes | aot_functionalization, inductor_codegen | 8 |
| issue_162522_torch_compile_generated_wrong_graph_when | #162522 | closed | yes | aot_functionalization | 16 |
| issue_168358_index_reduce_returns_nan_during_backward | #168358 | closed | yes | dynamo_capture | 16 |
| issue_170642_cudnn_init_dropout_state_crashes_with_dt | #170642 | closed | yes | dynamo_capture | 1 |
| issue_170684_bug_inductor_numerical_inconsistency_wit | #170684 | closed | yes | dynamo_capture | 3 |
| issue_171190_torch_compile_inductor_silently_ignores | #171190 | closed | yes | inductor_codegen | 1 |
| issue_171191_torch_compile_inductor_ignores_float64_f | #171191 | closed | yes | inductor_codegen | 16 |
| issue_171258_inductor_torchinductor_produces_inconsis | #171258 | closed | yes | dynamo_capture | 3 |
| issue_171259_torch_acceleratorerror_cuda_error_device | #171259 | closed | yes | dynamo_capture | 3 |
| issue_171282_inconsistency_inductor_binary_cross_entr | #171282 | closed | yes | dynamo_capture | 3 |
| issue_171366_inconsistency_aten_view_copy_produces_in | #171366 | closed | yes | dynamo_capture | 3 |
| issue_171493_incorrect_fusion_and_re_ordering_of_an_i | #171493 | closed | yes | inductor_codegen | 16 |
| issue_172183_torch_compile_silently_bypasses_dtype_mi | #172183 | closed | yes | inductor_codegen | 1 |
| issue_172184_torch_compile_silently_bypasses_device_m | #172184 | closed | yes | inductor_codegen | 1 |
| issue_173054_inconsistency_torchinductor_produces_inc | #173054 | closed | yes | dynamo_capture | 3 |
| issue_173133_inductor_cuda_torch_bucketize_produces_i | #173133 | closed | yes | inductor_codegen | 16 |
| issue_173307_inconsistency_numerical_divergence_betwe | #173307 | closed | yes | dynamo_capture | 3 |
| issue_174069_inductor_argmax_max_returns_incorrect_in | #174069 | closed | yes | inductor_codegen | 3 |
| issue_174386_torch_compile_ignores_torch_use_determin | #174386 | closed | yes | inductor_codegen | 3 |
| issue_174719_pallas_argmax_with_keepdim_true_on_middl | #174719 | closed | yes | inductor_codegen | 3 |
| issue_175156_inductor_multiple_randint_calls_cause_in | #175156 | closed | yes | inductor_codegen | 3 |
| issue_175632_inductor_torch_compile_produces_inconsis | #175632 | closed | yes | inductor_codegen | 16 |
| issue_175903_inductor_incorrect_results_in_index_put | #175903 | closed | yes | inductor_codegen | 16 |
| issue_175919_inductor_out_of_bounds_memory_read_via_r | #175919 | closed | yes | inductor_codegen | 16 |
| issue_175966_silently_incorrect_results_for_torch_ara | #175966 | closed | yes | inductor_codegen | 16 |
| issue_176310_inductor_cudagraph_trees_breaks_with_par | #176310 | closed | yes | dynamo_capture | 1 |
| issue_176679_torch_compile_produces_incorrect_results | #176679 | closed | yes | dynamo_capture | 3 |
| issue_176854_torch_compile_does_not_correctly_propaga | #176854 | closed | yes | dynamo_capture | 16 |
| issue_177252_inductor_assertionerror_wrong_number_of | #177252 | closed | yes | aot_functionalization | 16 |
| issue_177629_torch_compile_backend_inductor_silently | #177629 | closed | yes | inductor_codegen | 16 |
| issue_177630_torch_compile_backend_inductor_silently | #177630 | closed | yes | inductor_codegen | 16 |
| issue_178046_torch_compile_silently_accepts_nn_parame | #178046 | closed | yes | dynamo_capture | 1 |
| issue_178125_conv_transpose1d_meta_implementation_all | #178125 | closed | yes | dynamo_capture | 3 |
| issue_178128_conv_transpose3d_meta_execution_produces | #178128 | closed | yes | dynamo_capture | 3 |
| issue_179383_torch_quantile_and_torch_nanquantile_fai | #179383 | closed | yes | dynamo_capture | 9 |
| issue_179561_inductor_x_to_torch_bfloat16_float_preci | #179561 | closed | yes | inductor_codegen | 16 |
| issue_180771_inductor_torch_compile_produces_wrong_gr | #180771 | closed | yes | inductor_codegen | 16 |
| issue_181175_aot_autograd_runtimeerror_cannot_call_nu | #181175 | closed | yes | dynamo_capture | 1 |
| issue_181625_assertionerror_expected_size_stride_mism | #181625 | closed | yes | inductor_codegen | 3 |
| issue_181693_nn_hardswish_produces_wrong_output_under | #181693 | closed | yes | inductor_codegen | 3 |
| issue_181694_torch_addcdiv_produces_wrong_output_unde | #181694 | closed | yes | inductor_codegen | 3 |
| issue_181695_torch_where_with_broadcast_shapes_produc | #181695 | closed | yes | inductor_codegen | 3 |
| issue_181870_torch_compile_dynamic_true_fails_on_f_cr | #181870 | closed | yes | dynamo_capture | 16 |
| issue_182012_torch_compile_silently_produces_all_zero | #182012 | closed | yes | inductor_codegen | 16 |
| issue_182131_torch_compile_inductor_produces_differen | #182131 | closed | yes | inductor_codegen | 16 |
| issue_182275_inductor_sympifyerror_cannot_sympify_sha | #182275 | closed | yes | dynamo_capture | 16 |
| issue_182343_torch_inductor_searchsorted_sliceview_bu | #182343 | closed | yes | inductor_codegen | 3 |
| issue_182399_torch_compile_dynamic_true_fails_on_f_cr | #182399 | closed | yes | dynamo_capture | 16 |
| issue_182606_flex_attention_mask_mod_closure_over_a_d | #182606 | closed | yes | dynamo_capture | 11 |
| issue_182766_torch_compile_crashes_on_sdpa_backward_w | #182766 | closed | yes | inductor_codegen | 16 |
| issue_182965_torch_compile_silently_returns_a_result | #182965 | closed | yes | aot_functionalization | 1 |
| issue_183018_torch_compile_torch_higher_order_ops_map | #183018 | closed | yes | dynamo_capture | 3 |
| issue_183121_torch_compile_returns_wrong_shape_for_to | #183121 | closed | yes | inductor_codegen | 16 |
| issue_183601_torch_compile_inductor_produces_wrong_ou | #183601 | closed | yes | inductor_codegen | 3 |
| issue_183986_torch_compile_silently_produces_wrong_re | #183986 | closed | yes | inductor_codegen | 6 |
| issue_184405_torch_compile_backend_inductor_returns_s | #184405 | closed | yes | dynamo_capture | 3 |
| issue_184415_inductor_torch_foreach_sub_silently_igno | #184415 | closed | yes | inductor_codegen | 3 |
| issue_185464_torch_compile_produces_wrong_results_for | #185464 | closed | yes | aot_functionalization | 3 |
| issue_185543_inductor_gradient_mismatch_between_eager | #185543 | closed | yes | dynamo_capture, inductor_codegen | 6 |
| issue_186536_inductor_dynamic_shape_searchsorted_deri | #186536 | closed | yes | inductor_codegen | 16 |
| issue_187027_flip_after_repeat_interleave_generates_n | #187027 | closed | yes | inductor_codegen | 3 |
| issue_187935_inductor_cuda_torch_signbit_loses_negati | #187935 | closed | yes | inductor_codegen | 14 |
| issue_188084_bug_inductor_reinplaces_index_put_on_exp | #188084 | closed | yes | dynamo_capture | 1 |
| issue_189518_inductor_s_pointless_cumsum_replacement | #189518 | closed | yes | inductor_codegen | 3 |
| issue_189528_cond_inductor_nameerror_on_inner_dim_bra | #189528 | closed | yes | dynamo_capture | 1 |
| issue_189895_inductor_silent_wrong_results_constant_p | #189895 | closed | yes | inductor_codegen | 3 |
| issue_190093_test_interpolate_propagate_real_tensors | #190093 | closed | yes | inductor_codegen | 3 |
| issue_190755_some_dynamo_descriptors_tp_descr_get_imp | #190755 | closed | yes | dynamo_capture | 16 |
| issue_191571_torch_compile_silently_returns_stale_zer | #191571 | closed | yes | inductor_codegen | 16 |
| issue_193279_dynamo_silently_drops_custom_backward_of | #193279 | closed | yes | dynamo_capture | 16 |
| issue_193661_inductor_wrong_argmax_after_fused_traili | #193661 | closed | yes | inductor_codegen | 16 |
| issue_195422_inductor_torch_compile_silently_drops_an | #195422 | closed | yes | aot_functionalization | 16 |
| issue_95161_aotautograd_based_torch_compile_doesn_t | #95161 | closed | yes | inductor_codegen | 3 |
| issue_114415_aotautograd_should_detect_aliasing_of_in | #114415 | open | yes | dynamo_capture | 16 |
| issue_181428_torch_compile_torch_func_grad_superlinea | #181428 | open | yes | dynamo_capture | 16 |
| issue_181653_torch_compile_torch_func_grad_fn_hangs_i | #181653 | open | yes | dynamo_capture | 16 |
| issue_182200_torch_compile_crashes_on_stft_fftn_rfftn | #182200 | open | yes | inductor_codegen | 14 |
| issue_182217_torch_compile_crashes_on_f_layer_norm_ne | #182217 | open | yes | dynamo_capture | 16 |
| issue_183120_torch_compile_inductor_produces_wrong_ou | #183120 | open | yes | inductor_codegen | 3 |
| issue_183249_torch_compile_produces_wrong_results_for | #183249 | open | yes | inductor_codegen | 3 |
| issue_183369_torch_compile_crashes_on_nested_tensor_f | #183369 | open | yes | dynamo_capture | 16 |
| issue_183607_torch_compile_changes_fp16_overflow_beha | #183607 | open | yes | inductor_codegen | 16 |
| issue_185246_torch_compile_silently_accepts_invalid_b | #185246 | open | yes | inductor_codegen | 1 |
| issue_185248_torch_compile_silently_accepts_negative | #185248 | open | yes | inductor_codegen | 1 |
| issue_185481_inductor_argmax_over_comparison_mask_is | #185481 | open | yes | inductor_codegen | 1 |
| issue_185587_inductor_numerical_inconsistency_polygam | #185587 | open | yes | inductor_codegen | 6 |
| issue_188541_inductor_cuda_f_logsigmoid_flushes_negat | #188541 | open | yes | inductor_codegen | 16 |
| issue_189787_inductor_constant_folds_sum_softmax_to_e | #189787 | open | yes | inductor_codegen | 16 |
| issue_190855_inductor_wrong_hessian_torch_compile_tor | #190855 | open | yes | dynamo_capture | 1 |
| issue_191445_inductor_generated_aotautograd_forward_w | #191445 | open | yes | inductor_codegen | 16 |
| issue_192905_nested_nested_compile_region_silently_re | #192905 | open | yes | dynamo_capture | 16 |
| issue_192985_dynamo_silently_drops_custom_jvp_of_auto | #192985 | open | yes | dynamo_capture | 16 |
| issue_193710_inductor_fallback_node_due_to_unsupporte | #193710 | open | yes | aot_functionalization | 16 |
| issue_193811_torch_compile_silently_accepts_int32_inp | #193811 | open | yes | aot_functionalization | 1 |
| issue_194062_inductor_silent_incorrectness_torch_full | #194062 | open | yes | inductor_codegen | 3 |
| issue_194103_torch_compile_dynamic_true_fails_for_sca | #194103 | open | yes | dynamo_capture | 16 |
| issue_194345_inductor_cuda_torch_remainder_torch_fmod | #194345 | open | yes | inductor_codegen | 3 |
| issue_194501_torch_compile_inductor_smooth_l1_loss_wi | #194501 | open | yes | inductor_codegen | 1 |
| issue_194547_torch_compile_silently_promotes_dtype_fo | #194547 | open | yes | inductor_codegen | 16 |
| issue_195320_inductor_sdpa_fusion_matches_a_permuted | #195320 | open | yes | inductor_codegen | 6 |
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
| issue_130394_inductor_incorrect_strides_for_function | #130394 | closed | - |  | 16 |
| issue_135432_torch_compile_cannot_handle_torch_tensor | #135432 | closed | - |  | 3 |
| issue_136662_composition_of_torch_compile_and_torch_f | #136662 | closed | - |  | 1 |
| issue_145372_xpu_torch_nn_functional_pad_brings_wrong | #145372 | closed | - | (earlier run) | 0 |
| issue_145466_torch_sin_cos_tan_torch_floor_round_may | #145466 | closed | - |  | 14 |
| issue_154168_potential_indexing_issues_in_compile_for | #154168 | closed | - | (earlier run) | 0 |
| issue_157248_inductor_triton_backend_conv2d_unsqueeze | #157248 | closed | - |  | 4 |
| issue_157909_inconsistent_behavior_between_eager_and | #157909 | closed | - | (earlier run) | 0 |
| issue_158003_inuctor_triton_torch_cumsum_outputs_inco | #158003 | closed | - | (earlier run) | 0 |
| issue_158626_freezing_layers_for_fine_tuning_leaves_t | #158626 | closed | - | (earlier run) | 0 |
| issue_158930_torch_compile_produces_incorrect_output | #158930 | closed | - |  | 6 |
| issue_159408_int64_mps_repeat_interleave_is_incorrect | #159408 | closed | - | (earlier run) | 0 |
| issue_160873_torch_compile_inductor_fails_on_mkl_dnn | #160873 | closed | - | (earlier run) | 0 |
| issue_161010_torch_compile_doesn_t_preserve_stride_wi | #161010 | closed | - |  | 9 |
| issue_161150_multiplication_and_softmax_throws_incorr | #161150 | closed | - |  | 1 |
| issue_161763_neg_add_computation_including_uint_tenso | #161763 | closed | - |  | 16 |
| issue_161905_mps_torch_compile_resnet_18_model_fails | #161905 | closed | - | (earlier run) | 0 |
| issue_161906_torch_compile_fails_with_aten_complex_de | #161906 | closed | - |  | 3 |
| issue_163834_inductor_conv_layout_permute_conv1d_thro | #163834 | closed | - |  | 6 |
| issue_164703_fuzzer_eager_compile_divergence_assertio | #164703 | closed | - |  | 1 |
| issue_166514_inductor_fails_with_stride_mismatch_for | #166514 | closed | - |  | 14 |
| issue_167629_compile_error_torchdynamo_fails_to_compi | #167629 | closed | - | (earlier run) | 0 |
| issue_167636_torchdynamo_compilation_error_invalid_st | #167636 | closed | - | (earlier run) | 0 |
| issue_167641_torch_compile_fails_with_stride_mismatch | #167641 | closed | - | (earlier run) | 0 |
| issue_167780_inductor_combo_kernel_fails_with_cppsche | #167780 | closed | - |  | 16 |
| issue_168937_inductor_rocm_combo_kernels_produce_inco | #168937 | closed | - |  | 16 |
| issue_170049_torch_compile_fails_to_capture_user_defi | #170049 | closed | - |  | 16 |
| issue_170666_inductor_fails_to_compile_models_contain | #170666 | closed | - |  | 6 |
| issue_170937_inductor_f_lp_pool_1_2_3_d_fail_with_ove | #170937 | closed | - |  | 16 |
| issue_170939_inductor_f_pdist_fails_with_runtimeerror | #170939 | closed | - |  | 9 |
| issue_171306_the_precision_of_pow_x_0_5_and_libdevice | #171306 | closed | - |  | 16 |
| issue_171979_inductor_fails_to_compile_models_using_t | #171979 | closed | - |  | 16 |
| issue_172207_torch_compile_changes_random_mask_genera | #172207 | closed | - | (earlier run) | 0 |
| issue_172208_torch_compile_produces_inconsistent_resu | #172208 | closed | - | (earlier run) | 0 |
| issue_172209_torch_compile_changes_autocast_behavior | #172209 | closed | - | (earlier run) | 0 |
| issue_172211_systemic_inconsistency_in_torch_compile | #172211 | closed | - | (earlier run) | 0 |
| issue_172711_torch_compile_produces_wrong_output_chan | #172711 | closed | - |  | 1 |
| issue_174016_inductor_cumprod_backward_produces_incor | #174016 | closed | - |  | 16 |
| issue_174379_inductor_pytorch_2_10_runtimeerror_in_na | #174379 | closed | - |  | 6 |
| issue_174549_inconsistency_torch_nn_fractionalmaxpool | #174549 | closed | - |  | 14 |
| issue_174923_flexattention_cuda_error_an_illegal_memo | #174923 | closed | - |  | 16 |
| issue_174969_torch_compile_outputs_incorrect_results | #174969 | closed | - |  | 16 |
| issue_175496_inductor_model_with_torch_compile_output | #175496 | closed | - |  | 16 |
| issue_175604_torch_compile_produces_stale_read_with_g | #175604 | closed | - | (earlier run) | 0 |
| issue_175791_inductor_incorrect_output_when_compiling | #175791 | closed | - |  | 16 |
| issue_175830_numerical_discrepancy_in_nn_lstm_between | #175830 | closed | - | (earlier run) | 0 |
| issue_175831_numerical_discrepancy_in_nn_linear_betwe | #175831 | closed | - | (earlier run) | 0 |
| issue_175854_numerical_consistency_significant_drift | #175854 | closed | - |  | 3 |
| issue_176565_inductor_mismatch_between_eager_and_comp | #176565 | closed | - | (earlier run) | 0 |
| issue_176596_torch_compile_does_not_correctly_invoke | #176596 | closed | - |  | 16 |
| issue_176599_torch_compile_bypasses_property_setter_a | #176599 | closed | - |  | 3 |
| issue_176686_tensor_subclass_using_torch_function_pro | #176686 | closed | - |  | 3 |
| issue_177451_torch_compile_fails_on_conv2d_with_kerne | #177451 | closed | - |  | 1 |
| issue_177600_dynamo_crashes_on_triton_autotune_config | #177600 | closed | - | (earlier run) | 0 |
| issue_177631_inductor_torch_compile_produces_incorrec | #177631 | closed | - |  | 16 |
| issue_177652_inductor_torch_compile_s_rng_state_is_in | #177652 | closed | - |  | 16 |
| issue_177821_inductor_torch_compile_ignores_a_complex | #177821 | closed | - |  | 3 |
| issue_177839_inductor_torch_compile_on_cpu_produces_i | #177839 | closed | - |  | 16 |
| issue_178040_torch_compile_raises_runtimeerror_on_val | #178040 | closed | - |  | 16 |
| issue_178179_dynamo_triton_heuristics_triton_autotune | #178179 | closed | - | (earlier run) | 0 |
| issue_178259_inductor_c_compilation_error_when_conver | #178259 | closed | - |  | 3 |
| issue_178262_inductor_incorrect_stride_calculation_in | #178262 | closed | - |  | 6 |
| issue_178365_dynamo_does_not_guard_on_function_defaul | #178365 | closed | - | (earlier run) | 0 |
| issue_178382_torch_compile_data_dependent_guard_fails | #178382 | closed | - |  | 3 |
| issue_178530_pytorch_2_11_regression_division_by_zero | #178530 | closed | - |  | 14 |
| issue_178676_torch_compile_crashes_with_cantsplit_typ | #178676 | closed | - |  | 6 |
| issue_178869_eager_then_compile_crashes_with_indexerr | #178869 | closed | - |  | 16 |
| issue_178871_incorrect_output_for_non_power_of_2_size | #178871 | closed | - |  | 16 |
| issue_178964_inductor_max_returns_incorrect_indices_w | #178964 | closed | - |  | 16 |
| issue_179026_torch_compile_guard_evaluation_crash_eva | #179026 | closed | - |  | 16 |
| issue_179534_torch_compile_fails_on_aten_sparse_csr_t | #179534 | closed | - |  | 1 |
| issue_179571_torch_compile_raises_error_for_constant | #179571 | closed | - |  | 6 |
| issue_179807_torch_compile_inductor_crash_f_pad_follo | #179807 | closed | - |  | 1 |
| issue_180807_inductor_static_launcher_missing_runtime | #180807 | closed | - |  | 16 |
| issue_180841_inductor_importerror_file_too_short_when | #180841 | closed | - | (earlier run) | 0 |
| issue_180848_torch_compile_produces_wrong_results_whe | #180848 | closed | - |  | 14 |
| issue_180956_torch_compile_produces_wrong_results_for | #180956 | closed | - |  | 14 |
| issue_181115_inductor_torch_compile_dynamic_true_cras | #181115 | closed | - |  | 3 |
| issue_181384_aot_autograd_runtimeerror_pytorch_build | #181384 | closed | - |  | 3 |
| issue_181581_torch_compile_silently_drops_higher_orde | #181581 | closed | - |  | 4 |
| issue_181584_inductor_associative_scan_crashes_with_d | #181584 | closed | - |  | 3 |
| issue_181688_heap_corruption_sigabrt_when_compiling_c | #181688 | closed | - | (earlier run) | 0 |
| issue_181735_vllm_inductor_triton_decompose_triton_ke | #181735 | closed | - |  | 1 |
| issue_182225_torch_compile_mismatch_for_bfloat16_rope | #182225 | closed | - |  | 16 |
| issue_182317_dynamo_leaks_torchfunctionmode_onto_stac | #182317 | closed | - |  | 3 |
| issue_182611_flex_attention_backward_is_10_30_slower | #182611 | closed | - | (earlier run) | 0 |
| issue_182765_torch_compile_silently_produces_all_zero | #182765 | closed | - |  | 16 |
| issue_183082_inductor_cpu_returns_wrong_argmax_after | #183082 | closed | - |  | 16 |
| issue_183605_torch_compile_changes_fp16_nan_behavior | #183605 | closed | - |  | 14 |
| issue_183606_torch_compile_changes_signed_zero_behavi | #183606 | closed | - |  | 3 |
| issue_183677_hop_alias_mutation_fake_traces_should_ig | #183677 | closed | - |  | 3 |
| issue_183761_torch_compile_produces_different_fp16_re | #183761 | closed | - | (earlier run) | 0 |
| issue_183763_torch_compile_overflows_torch_sinh_near | #183763 | closed | - |  | 16 |
| issue_183765_torch_compile_overflows_torch_cosh_near | #183765 | closed | - |  | 16 |
| issue_183767_torch_compile_returns_inf_for_torch_asin | #183767 | closed | - |  | 16 |
| issue_183833_inductor_hop_flexattention_should_bind_d | #183833 | closed | - | (earlier run) | 0 |
| issue_183889_torch_compile_fails_with_pendingunbacked | #183889 | closed | - | (earlier run) | 0 |
| issue_183894_torch_compile_returns_wrong_argmin_after | #183894 | closed | - | (earlier run) | 0 |
| issue_183898_torch_compile_produces_wrong_gradient_fo | #183898 | closed | - | (earlier run) | 0 |
| issue_183902_torch_compile_skips_device_mismatch_erro | #183902 | closed | - | (earlier run) | 0 |
| issue_183987_torch_compile_crashes_on_addcmul_addcdiv | #183987 | closed | - |  | 16 |
| issue_184013_inductor_torch_compile_crashes_on_conv2d | #184013 | closed | - |  | 16 |
| issue_184014_inductor_force_layout_optimization_true | #184014 | closed | - |  | 16 |
| issue_184026_inductor_torch_compile_crashes_on_conv_t | #184026 | closed | - |  | 16 |
| issue_184247_inductor_incorrect_epilogue_fusion_for_u | #184247 | closed | - | (earlier run) | 0 |
| issue_184714_tma_failure_when_running_slice_view_oper | #184714 | closed | - |  | 11 |
| issue_185330_inductor_torch_index_select_on_uint16_in | #185330 | closed | - |  | 3 |
| issue_185382_torch_compile_inductor_silently_produces | #185382 | closed | - |  | 16 |
| issue_185396_inductor_cuda_internal_keyerror_complex6 | #185396 | closed | - |  | 1 |
| issue_185405_inductor_assertionerror_len_index_len_st | #185405 | closed | - |  | 1 |
| issue_185449_flash_attention_backend_type_not_stored | #185449 | closed | - | (earlier run) | 0 |
| issue_185472_inductor_f_hardtanh_compiled_backward_si | #185472 | closed | - |  | 3 |
| issue_185488_dynamo_lazybatchnorm2d_fails_under_torch | #185488 | closed | - |  | 14 |
| issue_185509_inductor_silent_incorrect_gradients_with | #185509 | closed | - |  | 1 |
| issue_185515_inductor_tensor_view_dtype_after_transpo | #185515 | closed | - |  | 3 |
| issue_185575_inductor_upsample_mode_area_fails_under | #185575 | closed | - |  | 3 |
| issue_185715_internal_assert_failed_nyi_symint_equali | #185715 | closed | - |  | 1 |
| issue_186241_tma_descriptor_loads_use_stale_xoffset_i | #186241 | closed | - |  | 1 |
| issue_186577_torch_compile_produces_wrong_results_whe | #186577 | closed | - |  | 16 |
| issue_186671_dynamo_set_subclass_overriding_iter_give | #186671 | closed | - |  | 3 |
| issue_186775_flex_attention_produces_nan_with_torch_c | #186775 | closed | - | (earlier run) | 0 |
| issue_187018_abs_on_uint8_silently_miscompiled_via_st | #187018 | closed | - |  | 3 |
| issue_187269_torch_inductor_config_combo_kernels_true | #187269 | closed | - |  | 1 |
| issue_187284_torch_compile_with_inductor_backend_sile | #187284 | closed | - |  | 16 |
| issue_187715_torch_compile_mode_reduce_overhead_silen | #187715 | closed | - | (earlier run) | 0 |
| issue_188048_inductor_cuda_torch_div_rounding_mode_fl | #188048 | closed | - | (earlier run) | 0 |
| issue_188074_torch_compile_produces_inconsistent_outp | #188074 | closed | - | (earlier run) | 0 |
| issue_188151_torch_cond_fails_in_torch_compile_with_s | #188151 | closed | - |  | 1 |
| issue_188420_torch_compile_produces_inconsistent_outp | #188420 | closed | - | (earlier run) | 0 |
| issue_188425_torch_compile_produces_drastically_incor | #188425 | closed | - | (earlier run) | 0 |
| issue_188430_torch_compile_produces_large_absolute_er | #188430 | closed | - | (earlier run) | 0 |
| issue_188432_torch_compile_produces_inconsistent_outp | #188432 | closed | - | (earlier run) | 0 |
| issue_188545_pt2_output_mismatch_between_eager_and_to | #188545 | closed | - |  | 3 |
| issue_188871_flexattention_flash_backend_cute_where_i | #188871 | closed | - |  | 11 |
| issue_188878_flexattention_flash_backend_silently_wro | #188878 | closed | - |  | 1 |
| issue_189054_compile_2_10_and_2_11_but_not_in_2_12_1 | #189054 | closed | - |  | 1 |
| issue_189271_inductor_keyerror_in_scheduler_compute_a | #189271 | closed | - |  | 1 |
| issue_189341_torch_compile_causes_segmentation_fault | #189341 | closed | - | (earlier run) | 0 |
| issue_189925_dynamo_io_text_encoding_causes_a_graph_b | #189925 | closed | - |  | 3 |
| issue_190796_inductor_mix_order_reduction_silently_co | #190796 | closed | - |  | 6 |
| issue_190857_flexattention_backward_crashes_with_cuda | #190857 | closed | - | (earlier run) | 0 |
| issue_190946_cumsum_appears_non_deterministic_under_t | #190946 | closed | - |  | 3 |
| issue_192219_bug_inductor_as_strided_silently_reads_o | #192219 | closed | - |  | 3 |
| issue_192226_bug_out_of_bounds_reads_with_offset_stri | #192226 | closed | - |  | 3 |
| issue_193061_torch_compile_silently_computes_wrong_gr | #193061 | closed | - |  | 16 |
| issue_193876_inductor_compiling_two_torch_full_cumsum | #193876 | closed | - |  | 3 |
| issue_193938_inductor_cuda_align_random_eager_true_ma | #193938 | closed | - | (earlier run) | 0 |
| issue_194558_inductor_in_place_padding_optimization_m | #194558 | closed | - |  | 6 |
| issue_194976_torch_compile_inductor_silent_wrong_resu | #194976 | closed | - |  | 16 |
| issue_195418_dynamo_canonicalize_output_graph_node_or | #195418 | closed | - | (earlier run) | 0 |
| issue_93357_pt2_compiled_model_with_cat_and_expand_g | #93357 | closed | - |  | 3 |
| issue_93363_aotautograd_returns_wrong_result_for_in | #93363 | closed | - |  | 16 |
| issue_93365_pt2_compiled_function_with_cat_and_mul_g | #93365 | closed | - |  | 3 |
| issue_93815_pt2_compile_gives_wrong_result_for_argma | #93815 | closed | - |  | 3 |
| issue_95695_torch_ge_produces_wrong_results_in_compi | #95695 | closed | - |  | 3 |
| issue_96728_redundant_statement_leads_to_wrong_outpu | #96728 | closed | - |  | 16 |
| issue_139257_error_compiling_the_torch_library_custom | #139257 | open | - |  | 6 |
| issue_158561_torch_compile_in_place_operation_raises | #158561 | open | - |  | 6 |
| issue_177372_add_torch_narrow_scatter_operator_to_com | #177372 | open | - | (earlier run) | 0 |
| issue_178482_torch_compile_dynamic_true_ignores_incom | #178482 | open | - |  | 3 |
| issue_178677_torch_compile_silently_succeeds_on_trans | #178677 | open | - |  | 3 |
| issue_181108_use_of_dynamic_shapes_impedes_inductor_f | #181108 | open | - | (earlier run) | 0 |
| issue_181851_register_fake_to_throw_error_if_signatur | #181851 | open | - |  | 16 |
| issue_182318_dynamo_codegen_leaks_torch_function_enab | #182318 | open | - |  | 3 |
| issue_183768_torch_compile_returns_inf_for_torch_acos | #183768 | open | - |  | 16 |
| issue_183901_torch_compile_produces_int32_overflowed | #183901 | open | - | (earlier run) | 0 |
| issue_184027_inductor_torch_compile_crashes_on_convol | #184027 | open | - |  | 16 |
| issue_184101_torch_compile_backward_crashes_for_abs_a | #184101 | open | - |  | 3 |
| issue_184394_inductor_merge_sympy_printer_path_into_t | #184394 | open | - |  | 16 |
| issue_185470_inductor_f_threshold_bf16_miscompilation | #185470 | open | - |  | 11 |
| issue_185494_dynamo_lazybatchnorm2d_fails_under_torch | #185494 | open | - |  | 14 |
| issue_185510_dynamo_typeerror_cannot_determine_truth | #185510 | open | - |  | 1 |
| issue_185589_inductor_severe_numerical_inconsistency | #185589 | open | - |  | 6 |
| issue_186799_torch_compile_silently_produces_wrong_gr | #186799 | open | - |  | 16 |
| issue_186875_inductor_fmod_remainder_with_python_floa | #186875 | open | - |  | 11 |
| issue_187340_torch_compile_inductor_cuda_torch_nextaf | #187340 | open | - |  | 14 |
| issue_187547_dynamo_graph_breaks_on_raw_unbacked_symi | #187547 | open | - |  | 0 |
| issue_187953_torch_compile_out_variants_of_compositei | #187953 | open | - |  | 16 |
| issue_188405_torch_compile_reconstructs_a_graph_creat | #188405 | open | - | (earlier run) | 0 |
| issue_188536_graph_break_reconstruction_loses_identit | #188536 | open | - | (earlier run) | 0 |
| issue_188680_test_opinfo_gap_allclose_based_compile_v | #188680 | open | - | (earlier run) | 0 |
| issue_189522_nested_compile_region_input_mutation_a_f | #189522 | open | - |  | 1 |
| issue_189808_inductor_sqrt_produces_negative_nan_0xff | #189808 | open | - |  | 16 |
| issue_189940_inductor_torch_compile_of_torch_cat_with | #189940 | open | - |  | 11 |
| issue_190274_inductor_runtimeerror_self_stride_0_must | #190274 | open | - |  | 3 |
| issue_190758_memory_budget_partitioner_recomputes_rng | #190758 | open | - |  | 1 |
| issue_191136_inductor_torch_view_copy_fails_on_expand | #191136 | open | - |  | 16 |
| issue_191433_inductor_triton_cuda_sm_120_bf16_autocas | #191433 | open | - |  | 3 |
| issue_191499_inductor_cpu_torch_compile_returns_0_for | #191499 | open | - |  | 3 |
| issue_191833_constraintviolationerror_is_not_raised_w | #191833 | open | - |  | 16 |
| issue_192343_torch_bincount_causes_d2h_and_potentiall | #192343 | open | - |  | 3 |
| issue_192872_dynamo_mutation_to_a_load_build_class_cr | #192872 | open | - | (earlier run) | 0 |
| issue_192906_reuse_hash_fn_leaves_a_subscripted_captu | #192906 | open | - | (earlier run) | 0 |
| issue_193490_inductor_batch_linear_lhs_fusion_leaks_w | #193490 | open | - | (earlier run) | 0 |
| issue_193757_inductor_cpu_torch_compile_silently_acce | #193757 | open | - |  | 0 |
| issue_193760_inductor_cuda_view_torch_bool_copy_y_vie | #193760 | open | - |  | 16 |
| issue_193802_block_scaled_1x128_triton_backend_genera | #193802 | open | - |  | 1 |
| issue_193809_torch_compile_torch_func_vjp_raises_inte | #193809 | open | - |  | 16 |
| issue_194001_aotautogradcache_stale_guards_expr_from | #194001 | open | - | (earlier run) | 0 |
| issue_194005_graphs_containing_linalg_cholesky_inv_so | #194005 | open | - |  | 9 |
| issue_194166_inductor_backend_exception_not_a_graph_b | #194166 | open | - |  | 14 |
| issue_194170_nameerror_in_ast_to_ttir_when_a_triton_j | #194170 | open | - |  | 3 |
| issue_194187_inductor_int64_scatter_reduce_none_on_gp | #194187 | open | - |  | 6 |
| issue_194329_inductor_aot_autograd_autocast_dynamic_s | #194329 | open | - |  | 6 |
| issue_194444_inductor_sdpa_fusion_silently_lost_when | #194444 | open | - |  | 16 |
| issue_194503_torch_compile_gaussian_nll_loss_fails_wi | #194503 | open | - |  | 16 |
| issue_194504_torch_compile_batchnorm1d_momentum_none | #194504 | open | - |  | 3 |
| issue_194548_torch_compile_silently_accepts_zero_batc | #194548 | open | - | (earlier run) | 0 |
| issue_194593_torch_compile_kl_divergence_binomial_bin | #194593 | open | - |  | 16 |
| issue_194596_torch_compile_wishart_mean_with_tensor_v | #194596 | open | - |  | 9 |
| issue_194765_torch_compile_adaptivelogsoftmaxwithloss | #194765 | open | - |  | 3 |
| issue_194766_torch_compile_torch_masked_median_fails | #194766 | open | - |  | 3 |
| issue_194972_inductor_simdkernel_split_iteration_rang | #194972 | open | - |  | 3 |
| issue_195282_inductor_dynamo_fake_tensor_tracing_reje | #195282 | open | - |  | 16 |
| issue_195402_inductor_out_of_bounds_index_aborts_the | #195402 | open | - |  | 0 |
| issue_195442_torchinductor_batch_aten_sub_miscompilat | #195442 | open | - |  | 16 |
| issue_195488_dynamo_autocast_context_manager_is_lower | #195488 | open | - |  | 0 |
| issue_195579_meta_decomps_torch_compile_skips_addmm_s | #195579 | open | - |  | 1 |
| issue_195582_inductor_silent_wrong_and_non_reproducib | #195582 | open | - |  | 6 |
| issue_195969_torch_compile_isinstance_x_protoa_protob | #195969 | open | - |  | 3 |
| issue_196173_torch_compile_produces_incorrect_results | #196173 | open | - |  | 0 |
| issue_196198_fullgraph_true_does_not_enforce_graph_br | #196198 | open | - |  | 16 |
