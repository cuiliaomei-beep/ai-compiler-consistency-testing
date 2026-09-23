# Run summary

- **torch**: 2.14.0+cpu
- **device**: cpu
- **backend**: inductor
- **cases**: 343
- **candidates**: 9
- **submittable**: 5
- **unique signatures**: 9
- **elapsed**: 832.5s

## Candidates by priority

### high (5)

| signature | case | stage | probe | factor | oracles |
|---|---|---|---|---|---|
| `33bbb869e4f3` | op_unsafe_chunk_0__IntroduceAliasWrite_1 | aot_functionalization | layered | - | alias |
| `dfc95bc3db02` | op_unsafe_chunk_0__IntroduceAliasWrite_1 | aot_functionalization | layered | - | alias |
| `3ad82ec17aab` | op_unsafe_chunk_0__IntroduceAliasWrite_1 | aot_functionalization | layered | - | alias |
| `7566a89437bb` | op_sparse_sampled_addmm_0 | specialization_cache | warm | dtype | mutation |
| `3502d8b578ed` | op_sparse_mm_0 | specialization_cache | warm | dtype | mutation |

### low (4)

| signature | case | stage | probe | factor | oracles |
|---|---|---|---|---|---|
| `7fde1e1178c1` | op_sparse_sampled_addmm_0 | dynamo_capture | layered | - | mutation |
| `8e9c5afdba33` | op_sparse_sampled_addmm_0 | dynamo_capture | layered | - | mutation |
| `0d1fd30073b0` | op_sparse_mm_0 | dynamo_capture | layered | - | mutation |
| `ced9065a5c66` | op_sparse_mm_0 | dynamo_capture | layered | - | mutation |

