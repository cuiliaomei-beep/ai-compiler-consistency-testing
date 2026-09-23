# Issue-reproducer campaign as a known-bug benchmark

reproducers: reproducers_gh   reports: reports_gh_rerun

| issue state | programs | detected | rate |
|---|---:|---:|---:|
| open | 13 | 11 | 0.85 |

reading: open = defect expected to be present on this version (detected = recall); closed = expected fixed (detected = regression candidate or false positive, review needed)

| program | issue | state | detected | stages | tests |
|---|---|---|---|---|---:|
| issue_185246_torch_compile_silently_accepts_invalid_b | #185246 | open | yes | (earlier run) | 1 |
| issue_185248_torch_compile_silently_accepts_negative | #185248 | open | yes | (earlier run) | 1 |
| issue_185481_inductor_argmax_over_comparison_mask_is | #185481 | open | yes | (earlier run) | 1 |
| issue_193757_inductor_cpu_torch_compile_silently_acce | #193757 | open | yes | (earlier run) | 1 |
| issue_193811_torch_compile_silently_accepts_int32_inp | #193811 | open | yes | (earlier run) | 1 |
| issue_194501_torch_compile_inductor_smooth_l1_loss_wi | #194501 | open | yes | (earlier run) | 1 |
| issue_195488_dynamo_autocast_context_manager_is_lower | #195488 | open | yes | inductor_codegen | 1 |
| issue_195579_meta_decomps_torch_compile_skips_addmm_s | #195579 | open | yes | inductor_codegen | 1 |
| issue_195665_inductor_torch_compile_skips_as_strided | #195665 | open | yes | inductor_codegen | 1 |
| issue_195673_torch_compile_accepts_rand_like_on_an_in | #195673 | open | yes | inductor_codegen | 1 |
| issue_195674_torch_compile_evaluates_subtraction_on_a | #195674 | open | yes | inductor_codegen | 1 |
| issue_183120_torch_compile_inductor_produces_wrong_ou | #183120 | open | - | (earlier run) | 3 |
| issue_196173_torch_compile_produces_incorrect_results | #196173 | open | - |  | 0 |
