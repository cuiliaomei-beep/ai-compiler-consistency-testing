# P11-1 baseline comparison: TorchProbe attempt and Random per-seed results

Run on 2026-09-25 (clock). Environment: Windows 11 Pro for Workstations 10.0.26200, Python 3.14.7 (the only
interpreter on the machine, `py -0`), torch 2.14.0+cpu, nnsmith 0.1.0, numpy 2.5.2, MSVC 14.44.35207 (Visual Studio
2022 Build Tools; imported through `tcc.compat.ensure_msvc_env`, as `run.py` does), no GPU. All commands were run from
`D:\wsl\personal\dr\paper\toxic_compile\plan`. Temporary files, the TorchProbe clone and the generated programs
with their tensors live in
`C:\Users\clm\AppData\Local\Temp\claude\d--wsl-personal-dr-paper\712b330c-4254-4beb-b7b3-ad57d91dc2ee\scratchpad\p11\`
(`temisu/` clone, `run_temisu.py` driver, `tp_out/`, `tp_out20/`, `verbatim_run.log`, `torchprobe.pdf/.txt`).
Nothing under `tcc/`, `paper_tcc/` or the issue drafts was modified; no tracker was written to.

## Files

| file | content |
|---|---|
| `TORCHPROBE.md` | TorchProbe: where the artifact is, what it does, how it was run, applicability to our programs, results on its own seeds, results of its programs under our harness |
| `torchprobe_run_n10_seeds0to34.{json,md}` | TorchProbe on its own seeds, `max_nodes=10` as in `fuzz.py`, seeds 0-34 (175 tests) |
| `torchprobe_run_n20_seeds100to114.{json,md}` | same with the paper's 20 operators per graph, seeds 100-114 |
| `torchprobe_tests_n10.jsonl`, `torchprobe_tests_n20.jsonl` | one record per TorchProbe test (status, eager validity, wall) |
| `torchprobe_programs_n10/`, `torchprobe_programs_n20/` | the generated programs (source only; tensors stay in the scratchpad `.pt` files) |
| `torchprobe_setting_b_origin.json`, `torchprobe_setting_b_subfunction.json` (+ `.log`) | TorchProbe programs judged by our harness against the 19 injected faults (Setting B), with fixed-version pass; `_origin_a/_origin_b/_probe5` are superseded partial runs |
| `nnsmith_seeds.md` | NNSmith per-seed table |
| `torchprobe_applicability*.{json,md}` | AST classification of our 29 + 185 programs against TorchProbe's seed format |
| `random_seeds.csv`, `random_seeds.md`, `random_seeds_summary.json`, `random_seeds_per_fault.csv` | Random baseline (B1), seeds 0-9, per seed and per fault |
| `random_seed{0..4}.json`, `seeds5to9/random_seed{5..9}.json` | full `run_benchmark` output per seed (51 fault x program entries each) |
| `random_seeds.log`, `random_seeds_5to9.log` | console logs of the two Random runs |
| `nnsmith_native_seed*.json`, `nnsmith_seeds_summary.json` | NNSmith (B3, native input) per model seed |

## How the paper's numbers were produced (found, not re-derived)

`results/RQ2.md` / `results/rq2_baselines.json` / `results/rq2_baselines.log` (2026-09-08 07:58) come from
`python -u run.py baselines --backend eager --budget 12` (`scripts/run_experiments.ps1`, step `rq2_baselines`,
875 s for all legs). `tcc.experiments.rq2_baselines` runs `run_benchmark` three times with
`random_plan_builder(budget=12, seed=s, sequences=True, oracles=OUTPUT_ONLY, level="B1")`, `s = 0, 1, 2`, and
`_agg` keeps only the mean over the runs (`"runs": 3`); **per-seed results were not saved**. "11.3 of 19 faults
(mean of three seeds) in 465 tests, 19% invalid" = `detected 11.33`, `tests_executed 464.7`,
`valid_rate 0.805`. "NNSmith ... 9" = `B3_nnsmith_plus_our_contexts` (4 models with our contexts, 9/19; the
native-input leg with 8 models is 6/19), one model seed (0).

## Commands run here

```
# Random baseline, per seed (same setting as the B1 leg of rq2_baselines)
python -u scripts/p11_random_seeds.py --seeds 5 --budget 12 --out results/p11_baselines                       # seeds 0-4, 253 s
python -u scripts/p11_random_seeds.py --first-seed 5 --seeds 5 --budget 12 --out results/p11_baselines/seeds5to9  # seeds 5-9, 288 s
python scripts/p11_merge_random_seeds.py results/p11_baselines results/p11_baselines/seeds5to9 --out results/p11_baselines
python scripts/p11_random_seeds_md.py --dir results/p11_baselines --extra results/p11_baselines/random_seeds_notes.md

# TorchProbe (see TORCHPROBE.md for the two changes needed to run it)
git clone https://github.com/soodoshll/temisu  <scratchpad>/p11/temisu      # commit 3aa039c4882f34400cdde9199fc39e688823d4a4
python -m temisu.fuzz                                                       # verbatim: AssertionError: Torch not compiled with CUDA enabled
python -u <scratchpad>/p11/run_temisu.py --device cpu --seeds 10 --first-seed 0 --out tp_out    # 158 s
python -u <scratchpad>/p11/run_temisu.py --device cpu --seeds 25 --first-seed 10 --out tp_out   # 428 s
python -u <scratchpad>/p11/run_temisu.py --device cpu --seeds 15 --first-seed 100 --max-nodes 20 --out tp_out20
python scripts/p11_torchprobe_summary.py <scratchpad>/p11/tp_out/tests.jsonl --out results/p11_baselines --tag n10_seeds0to34
python scripts/p11_torchprobe_applicability.py --out results/p11_baselines
python scripts/p11_torchprobe_setting_b.py --programs <scratchpad>/p11/tp_out/programs --temisu <scratchpad>/p11/temisu --mutations <m> ...

# NNSmith (B3 native leg of rq2_baselines) per model seed
python scripts/p11_nnsmith_seeds.py --seeds 3 --models 8 --budget 12 --out results/p11_baselines
```

New scripts (all under `scripts/`, nothing under `tcc/` changed): `p11_random_seeds.py`, `p11_merge_random_seeds.py`,
`p11_random_seeds_md.py`, `p11_nnsmith_seeds.py`, `p11_torchprobe_applicability.py`, `p11_torchprobe_setting_b.py`,
`p11_torchprobe_summary.py`.

## Headline numbers

* **TorchProbe runs** on torch 2.14.0+cpu after two recorded changes (CPU device instead of the hard-coded `cuda`; a one-line
  Python>=3.11 fix in `mutator.py`). Repository `https://github.com/soodoshll/temisu`, commit `3aa039c4882f34400cdde9199fc39e688823d4a4`.
  On its own seeds: 175 tests / 35 graphs at 10 operators (583.9 s) and 47 tests / 10 graphs at 20 operators
  (349.4 s): **222 pass, 0 inconsistent, 0 crash, 0 invalid**. No divergence, so nothing to map onto
  `findings.csv` and nothing new.
* **Applicability to our programs**: 3 of the 29 corpus programs and 0 of the 185 Python-semantics programs are expressible as
  a TorchProbe seed (NNSmith straight-line SSA tensor code); the rest have control flow, Python reads of tensor metadata,
  non-tensor arguments, in-place mutation, non-static indexing, operators without a renderer, globals or closures.
* **TorchProbe programs under our harness (Setting B)**: 35 unmutated programs -> 6/19 as counted, **5/19** after removing a
  fault-wrapper artifact; 35 fully mutated programs -> 15/19 as counted, **6/19** after removing the same artifact and a
  Dynamo crash (`dictionary changed size during iteration`, upstream PR #191281, fixed on main 2026-08-20, still in v2.14.0)
  that the mutated programs trigger after ~300 compile/reset cycles in one process. 0 false positives on the real compiler.
* **Random baseline (B1), 10 seeds**: detections mean 10.4, median 11.0, min 6, max 12,
  sd 1.647; seeds 0-2 give 11.333 (the paper's 11.3); tests 492.7 mean, invalid rate 0.179;
  wall 54.1 s mean per seed. Six faults never found by Random (four need a non-value oracle, two are budget effects).
* **NNSmith (B3 native), 3 model seeds**: 6/19 in every seed (mean 6.0, sd 0.0); one of the six is the same
  fault-wrapper artifact (`codegen_scalar_edge` on a four-input model), so 5/19 on the same footing as TorchProbe.
* Caveat on wall times: from 17:25 another session's `scripts/oracle_tiers_real.py` workers shared the CPU; the Random seeds
  (finished 17:17) are unaffected, TorchProbe batch 2/3, NNSmith and Setting B are not.
