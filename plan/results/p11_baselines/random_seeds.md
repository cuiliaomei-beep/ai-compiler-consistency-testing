# Random baseline (B1): per-seed results

Setting: identical to the `B1_random` leg of `tcc.experiments.rq2_baselines` that produced `results/RQ2.md` (`random_plan_builder(budget=12, seed=s, sequences=True, oracles=OUTPUT_ONLY, level="B1")`, backend `eager`, 12 tests per program, all 19 injected faults of `tcc/faults.py`, `check_fixed=False`). Seeds 0-2 are the three seeds whose mean the paper reports; seeds 3-9 are new. Script: `scripts/p11_random_seeds.py`; per-seed JSON: `random_seed<N>.json` (seeds 0-4 here, 5-9 in `seeds5to9/`).

## Per seed

| seed | faults detected (of 19) | tests executed | invalid tests | invalid rate | unique failure clusters | mean TTF (s) | mean tests-to-detect | wall (s) |
|---:|---:|---:|---:|---:|---:|---:|---:|---:|
| 0 | 11 | 458 | 109 | 0.192 | 11 | 0.55 | 5.0 | 45.3 |
| 1 | 12 | 483 | 108 | 0.183 | 13 | 0.54 | 4.83 | 55.7 |
| 2 | 11 | 457 | 120 | 0.208 | 11 | 0.43 | 4.25 | 49.4 |
| 3 | 11 | 499 | 96 | 0.161 | 11 | 0.46 | 4.47 | 51.8 |
| 4 | 11 | 490 | 114 | 0.189 | 12 | 0.61 | 5.58 | 50.6 |
| 5 | 11 | 494 | 75 | 0.132 | 12 | 0.8 | 5.79 | 53.6 |
| 6 | 6 | 559 | 122 | 0.179 | 6 | 1.0 | 5.38 | 79.4 |
| 7 | 10 | 488 | 95 | 0.163 | 10 | 0.48 | 4.71 | 47.2 |
| 8 | 11 | 513 | 110 | 0.177 | 12 | 0.66 | 6.18 | 51.8 |
| 9 | 10 | 486 | 126 | 0.206 | 10 | 0.68 | 5.58 | 56.2 |

## Statistics over the seeds

| quantity | n | mean | median | min | max | std (sample) |
|---|---:|---:|---:|---:|---:|---:|
| faults detected | 10 | 10.4 | 11.0 | 6 | 12 | 1.647 |
| tests executed | 10 | 492.7 | 489.0 | 457 | 559 | 28.86 |
| invalid tests | 10 | 107.5 | 109.5 | 75 | 126 | 15.292 |
| invalid rate | 10 | 0.179 | 0.1809 | 0.1318 | 0.208 | 0.023 |
| unique failure clusters | 10 | 10.8 | 11.0 | 6 | 13 | 1.932 |
| wall time (s) | 10 | 54.1 | 51.8 | 45.3 | 79.4 | 9.529 |

Mean over seeds 0-2 (the paper's three seeds): **11.333** faults detected.
Mean over all 10 seeds: **10.4** (median 11.0, min 6, max 12, sd 1.647).

## Per fault: detection frequency and time to first detection

`ttd` = tests executed on that fault's programs (in `programs_for(fault)` order) up to and including the first detecting test; `ttf` = wall seconds over the same span. Statistics are over the seeds that detected the fault.

| fault | category | detected in seeds | ttd mean | ttd median | ttd min | ttd max | ttf mean (s) | ttf max (s) | detecting programs |
|---|---|---:|---:|---:|---:|---:|---:|---:|---|
| codegen_value | codegen | 10/10 | 1 | 1.0 | 1 | 1 | 0.849 | 2.201 | dtype_reduce |
| codegen_boundary_32 | shape | 10/10 | 1 | 1.0 | 1 | 1 | 0.101 | 0.132 | shape_boundary |
| codegen_boundary_31 | shape | 0/10 | - | - | - | - | - | - | - |
| codegen_mod16_tail | shape | 8/10 | 12.5 | 14.0 | 2 | 23 | 1.477 | 2.587 | mod_tiling, shape_boundary |
| codegen_index_last | shape | 6/10 | 4.5 | 3.5 | 2 | 11 | 0.556 | 1.676 | index_chain |
| codegen_noncontig | codegen | 10/10 | 21.8 | 20.0 | 2 | 47 | 2.556 | 9.591 | contiguous_read, noncontig_copy, stride_read, view_inplace |
| codegen_fp16_rounding | dtype | 4/10 | 22.25 | 21.5 | 11 | 35 | 2.603 | 3.408 | dtype_reduce, python_flag_semantic, shape_boundary |
| codegen_dynamic_flag | codegen | 8/10 | 12.875 | 9.5 | 2 | 35 | 2.017 | 8.176 | dtype_reduce, python_flag_semantic |
| codegen_scalar_edge | control_flow | 0/10 | - | - | - | - | - | - | - |
| functionalize_drop_mutation | alias_mutation | 0/10 | - | - | - | - | - | - | - |
| functionalize_alias_to_copy | alias_mutation | 0/10 | - | - | - | - | - | - | - |
| capture_swallow_exception | control_flow | 7/10 | 5.857 | 5 | 2 | 11 | 0.852 | 1.448 | exception_path |
| autograd_wrong_gradient | codegen | 0/10 | - | - | - | - | - | - | - |
| underspec_dtype | specialization | 7/10 | 12.143 | 16 | 4 | 22 | 1.352 | 2.604 | dtype_reduce, shape_boundary |
| underspec_scalar | specialization | 7/10 | 24.429 | 24 | 15 | 36 | 2.238 | 3.114 | scalar_compare, string_mode |
| underspec_layout | specialization | 10/10 | 27 | 27.0 | 3 | 48 | 2.506 | 4.032 | contiguous_read, noncontig_copy, stride_read, view_inplace |
| underspec_requires_grad | specialization | 0/10 | - | - | - | - | - | - | - |
| cache_stale_on_return | cache | 8/10 | 12.375 | 13.5 | 3 | 24 | 1.438 | 2.742 | dtype_reduce, shape_boundary |
| cache_result_memo | cache | 9/10 | 14.333 | 15 | 3 | 33 | 1.832 | 3.318 | dtype_reduce, python_flag_semantic, shape_boundary |

Never detected by Random in any seed (6): codegen_boundary_31, codegen_scalar_edge, functionalize_drop_mutation, functionalize_alias_to_copy, autograd_wrong_gradient, underspec_requires_grad.
Detected in every seed (4): codegen_value, codegen_boundary_32, codegen_noncontig, underspec_layout.


## Notes

* Seeds 0-2 reproduce the paper's figure: 11 / 12 / 11 detections, mean 11.33 (`results/RQ2.md`: 11.33/19, 464.7 tests, valid rate 0.805). Tests executed per seed differ slightly from the 2026-09-08 run (466.0 vs 464.7 mean over the three seeds) because `run_benchmark` stops a fault's program at the first detecting test and the harness prunes contexts whose inputs are identical to the base; the detection counts are identical.
* Seed 6 (6/19) has no errors (`seeds5to9/random_seed6.json`, 51 entries, `error` null everywhere, every program ran its full 12 tests). Its random draws simply never produced the warm dtype / scalar switch that `underspec_dtype`, `underspec_scalar`, `cache_stale_on_return`, `cache_result_memo` and `codegen_fp16_rounding` need on their programs. This is the tail of the distribution, not a harness failure; it is why the paper's three-seed mean (11.3) sits above the ten-seed mean (10.4).
* Six faults are never found by Random in any of the ten seeds. Four are invisible to the output-only oracle Random uses: `functionalize_drop_mutation` and `functionalize_alias_to_copy` (mutation / alias oracles), `autograd_wrong_gradient` and `underspec_requires_grad` (gradient oracle); `B1_random_full_oracle` in `results/RQ2.md` (14/19 with all oracles) is the same generator with those oracles on. The other two are budget effects: `codegen_scalar_edge` needs `n == 4` on `scalar_compare`/`loop_bound` and `codegen_boundary_31` needs `x.shape[0] == 31` on `shape_boundary`; Random did draw the triggering context in seed 8 (`rand:arg1=4`, position 8 of the 12 contexts) and in seed 5 (`rand:arg0.dim0=31`, position 9), but the runner schedules one cold probe and one warm matrix per context in plan order, so a 12-test budget is exhausted before the eighth context is reached (re-run of those two entries: 12 tests executed, 0 detections, no error). In the other seeds the value was not drawn at all (Random's substitute list does contain 4 and its resize list does contain 31, but the family, argument and value are all drawn uniformly).
* `codegen_value`, `codegen_boundary_32`, `codegen_noncontig` and `underspec_layout` are found in every seed; `codegen_value` and `codegen_boundary_32` always on the first test.
* Wall time is the per-seed total of `run_benchmark` (all 51 fault x program entries), measured on the same machine as `results/RQ2.md` (torch 2.14.0+cpu, Python 3.14.7, Windows 11), with the TorchProbe applicability classifier and a one-seed TorchProbe smoke test sharing the CPU during seeds 5-9.

