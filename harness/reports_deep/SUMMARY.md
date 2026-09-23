# Run summary

- **torch**: 2.14.0+cpu
- **device**: cpu
- **backend**: inductor
- **cases this run**: 1778
- **candidates this run**: 11
- **submittable this run**: 11
- **unique signatures**: 11
- **elapsed**: 6056.6s

## Candidates by priority

### high (11)

| signature | case | stage | probe | factor | oracles |
|---|---|---|---|---|---|
| `7f5fa1ab3262` | op__softmax_backward_data_0 | inductor_codegen | layered | - | value |
| `dae7a940f084` | op__softmax_backward_data_0__IntroduceView_0 | inductor_codegen | layered | - | value |
| `a1e373091f9c` | op__softmax_backward_data_0__IntroduceView_1 | inductor_codegen | layered | - | value |
| `11604603ab08` | op__softmax_backward_data_0__IntroduceAliasWrite_2 | inductor_codegen | layered | - | value |
| `9135bdc06c0d` | op__softmax_backward_data_0__IntroduceAliasWrite_3 | inductor_codegen | layered | - | value |
| `3fe61d49337c` | op__softmax_backward_data_0__IntroduceView+IntroduceView_4 | inductor_codegen | layered | - | value |
| `a8e3a594dd92` | op__softmax_backward_data_0__IntroduceView+IntroduceAliasWrite_5 | inductor_codegen | layered | - | value |
| `f07cb527335f` | op__softmax_backward_data_0__IntroduceView+IntroduceAliasWrite_6 | inductor_codegen | layered | - | value |
| `fb902e3b0182` | op__softmax_backward_data_0__IntroduceView+IntroduceView_7 | inductor_codegen | layered | - | value |
| `f8dffcb29a64` | op__softmax_backward_data_0__IntroduceView+IntroduceAliasWrite_8 | inductor_codegen | layered | - | value |
| `b9a69c06e2cc` | op__softmax_backward_data_0__IntroduceView+IntroduceAliasWrite_9 | inductor_codegen | layered | - | value |

