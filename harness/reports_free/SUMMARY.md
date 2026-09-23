# Run summary

- **torch**: 2.14.0+cpu
- **device**: cpu
- **backend**: inductor
- **cases this run**: 3182
- **candidates this run**: 18
- **submittable this run**: 18
- **unique signatures**: 18
- **elapsed**: 11872.7s

## Candidates by priority

### high (18)

| signature | case | stage | probe | factor | oracles |
|---|---|---|---|---|---|
| `cb32ebbd479d` | op_acos_0__RealAliasWrite_2 | inductor_codegen | layered | - | value |
| `2717ce1764d3` | op_acos_0__IntroduceView+RealAliasWrite_5 | inductor_codegen | layered | - | value |
| `4e13bbb8bd79` | op_acos_0__RealAliasWrite+AliasMutation_10 | inductor_codegen | layered | - | value |
| `20d4406836c5` | op_acos_0__RealAliasWrite+IntroduceView_11 | inductor_codegen | layered | - | value |
| `d72d02c08a8c` | op_asin_0__RealAliasWrite_2 | inductor_codegen | layered | - | value |
| `de2f97eae4ed` | op_asin_0__IntroduceView+RealAliasWrite_5 | inductor_codegen | layered | - | value |
| `06d45a28fe37` | op_asin_0__IntroduceAliasWrite+RealAliasWrite_9 | inductor_codegen | layered | - | value |
| `75aa787f190f` | op_asin_0__RealAliasWrite+AliasMutation_10 | inductor_codegen | layered | - | value |
| `a71c09eb8adc` | op_asin_0__RealAliasWrite+IntroduceView_11 | inductor_codegen | layered | - | value |
| `7af43d80742e` | op_asin_0__RealAliasWrite+IntroduceAliasWrite_12 | inductor_codegen | layered | - | value |
| `49bbd1c35b46` | op_asin_0__RealAliasWrite+RealAliasWrite_13 | inductor_codegen | layered | - | value |
| `0f056efcbd22` | op_atanh_0__RealAliasWrite_2 | inductor_codegen | layered | - | value |
| `5c6d61f40718` | op_atanh_0__IntroduceView+RealAliasWrite_5 | inductor_codegen | layered | - | value |
| `1751c028092d` | op_atanh_0__IntroduceAliasWrite+RealAliasWrite_9 | inductor_codegen | layered | - | value |
| `a18775e2115a` | op_atanh_0__RealAliasWrite+AliasMutation_10 | inductor_codegen | layered | - | value |
| `7e32d0f34b83` | op_atanh_0__RealAliasWrite+IntroduceView_11 | inductor_codegen | layered | - | value |
| `cd47c23251cc` | op_atanh_0__RealAliasWrite+IntroduceAliasWrite_12 | inductor_codegen | layered | - | value |
| `8ef21a6cddbf` | op_atanh_0__RealAliasWrite+RealAliasWrite_13 | inductor_codegen | layered | - | value |

