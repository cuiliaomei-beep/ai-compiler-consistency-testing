# Run summary

- **torch**: 2.14.0+cpu
- **device**: cpu
- **backend**: inductor
- **programs**: 49
- **candidates**: 42
- **submittable**: 0
- **unique signatures**: 42
- **elapsed**: 3041.1s

## Candidates by priority

### low (1)

| signature | program | stage | probe | factor | oracles | repro |
|---|---|---|---|---|---|---|
| `ef3585a82404` | nnsmith_100003 | dynamo_capture | layered | resize | exception | 2/2 |

### info (41)

| signature | program | stage | probe | factor | oracles | repro |
|---|---|---|---|---|---|---|
| `97541e82b64b` | nnsmith_100003 | none | matrix | dtype | - | 2/2 |
| `1d30f7707696` | nnsmith_100003 | none | matrix | requires_grad | - | 2/2 |
| `4d3d0365fc14` | nnsmith_100003 | none | matrix | layout | - | 2/2 |
| `404b6c5ab1ce` | shape_boundary | none | matrix | requires_grad | - | 2/2 |
| `9b62aa28bb62` | mod_tiling | none | matrix | requires_grad | - | 2/2 |
| `5567023bc198` | index_chain | none | matrix | requires_grad | - | 2/2 |
| `788460929de0` | dtype_read | none | matrix | requires_grad | - | 2/2 |
| `e6c0072e671f` | python_flag | none | matrix | substitute | - | 2/2 |
| `1ea700571f38` | python_flag | none | matrix | requires_grad | - | 2/2 |
| `535948ab4726` | python_flag_semantic | none | matrix | substitute | - | 2/2 |
| `9c6539724e4c` | python_flag_semantic | none | matrix | requires_grad | - | 2/2 |
| `1037ba9ff2ad` | scalar_compare | none | matrix | requires_grad | - | 2/2 |
| `3a3ce2964870` | none_check | none | matrix | substitute | - | 2/2 |
| `5e2f8b24e501` | none_check | none | matrix | requires_grad | - | 2/2 |
| `38c8b6b226ad` | view_inplace | none | matrix | requires_grad | - | 2/2 |
| `d83c26b2f482` | noncontig_copy | none | matrix | requires_grad | - | 2/2 |
| `9fb2e0b5ad7d` | overlapping_views | none | matrix | layout | - | 2/2 |
| `bb2b76c5bb8e` | overlapping_views | none | matrix | requires_grad | - | 2/2 |
| `8b5ffaa330f0` | alias_returned | none | matrix | requires_grad | - | 2/2 |
| `d50d18ee373c` | conditional_mutation | none | matrix | requires_grad | - | 2/2 |
| `3c44df087cfc` | chunk_inplace | none | matrix | requires_grad | - | 2/2 |
| `3f9865ad4840` | requires_grad_switch | none | matrix | requires_grad | - | 2/2 |
| `a8433989db27` | global_state | none | matrix | requires_grad | - | 2/2 |
| `e3a815cf6108` | closure_fn | none | matrix | requires_grad | - | 2/2 |
| `ee5019cff0ab` | reshape_dim | none | matrix | requires_grad | - | 2/2 |
| `76a4b17ab74c` | reshape_dim | none | matrix | substitute | - | 2/2 |
| `34f98a7df17a` | loop_bound | none | matrix | substitute | - | 2/2 |
| `ffd7a8a355eb` | loop_bound | none | matrix | requires_grad | - | 2/2 |
| `45ed91db84e2` | exception_path | none | matrix | requires_grad | - | 2/2 |
| `ff46220c21da` | container_len | none | matrix | dtype | - | 2/2 |
| `55603fdb2ebd` | container_len | none | matrix | requires_grad | - | 2/2 |
| `a4c7a78f896f` | string_mode | none | matrix | substitute | - | 2/2 |
| `34438b5f90d9` | string_mode | none | matrix | requires_grad | - | 2/2 |
| `e42c7e9f39a6` | stride_read | none | matrix | requires_grad | - | 2/2 |
| `4a3058ba69ca` | mask_index | none | matrix | requires_grad | - | 2/2 |
| `b3094e170d6c` | gather_shape | none | matrix | device | - | 2/2 |
| `0168b0754232` | gather_shape | none | matrix | requires_grad | - | 2/2 |
| `5ed295070666` | dtype_reduce | none | matrix | requires_grad | - | 2/2 |
| `55a4ae0c7269` | contiguous_read | none | matrix | requires_grad | - | 2/2 |
| `f916d1e19225` | rank_read | none | matrix | requires_grad | - | 2/2 |
| `80eb3d8d214b` | flag_and_shape | none | matrix | substitute | - | 2/2 |

