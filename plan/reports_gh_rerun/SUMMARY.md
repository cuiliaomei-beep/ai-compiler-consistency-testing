# Run summary

- **torch**: 2.14.0+cpu
- **device**: cpu
- **backend**: inductor
- **programs**: 6
- **candidates**: 5
- **submittable**: 5
- **unique signatures**: 11
- **elapsed**: 61.2s

## Candidates by priority

### high (5)

| signature | program | stage | probe | factor | oracles | repro |
|---|---|---|---|---|---|---|
| `68b4b8d4ff32` | issue_195488_dynamo_autocast_context_manager_is_lower | inductor_codegen | layered | - | exception | 2/2 |
| `279d05c1a28a` | issue_195579_meta_decomps_torch_compile_skips_addmm_s | inductor_codegen | layered | - | exception | 2/2 |
| `86b5afca9d32` | issue_195665_inductor_torch_compile_skips_as_strided | inductor_codegen | layered | - | exception | 2/2 |
| `3d44087f6f0e` | issue_195673_torch_compile_accepts_rand_like_on_an_in | inductor_codegen | layered | - | exception | 2/2 |
| `9499c8c9c436` | issue_195674_torch_compile_evaluates_subtraction_on_a | inductor_codegen | layered | - | exception | 2/2 |

