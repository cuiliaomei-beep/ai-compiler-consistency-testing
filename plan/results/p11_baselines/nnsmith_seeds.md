# NNSmith baseline (B3, native input): per model seed

Setting: the `B3_nnsmith_native` leg of `tcc.experiments.rq2_baselines` (`nnsmith_programs(n=8, seed=s)`, the tool's own single input, cold eager-vs-compiled, all oracles, every injected fault, backend `eager`, budget 12). `rq2_baselines` used model seed 0 only (`results/RQ2.md`: 6.0/19, 152 tests, valid rate 1.0). Script: `scripts/p11_nnsmith_seeds.py`; per-seed JSON `nnsmith_native_seed<N>.json`. `_external_bench` returns the `_agg` aggregate, so fault ids are not retained per seed (per-category counts are).

| model seed | models | detected (of 19) | tests | invalid | unique failure clusters | mean TTF (s) | bench wall (s) |
|---:|---:|---:|---:|---:|---:|---:|---:|
| 0 | 8 | 6 | 152 | 0 | 6.0 | 2.28 | 331.9 |
| 1 | 8 | 6 | 152 | 0 | 6.0 | 2.27 | 324.9 |
| 2 | 8 | 6 | 152 | 0 | 9.0 | 2.64 | 296.5 |

Detections over 3 seeds: mean 6.0, median 6.0, min 6, max 6, sd 0.0.
Per category (seed 0): codegen 1/4, shape 2/4, dtype 0/1, control_flow 1/2, alias_mutation 2/2, specialization 0/4, cache 0/2.

Bench wall times were measured while another session's `scripts/oracle_tiers_real.py` workers shared the CPU (from 17:25 on 2026-09-25).
