# RQ2 baselines

backend eager, budget 12 tests/program, 3 random seeds

| generator | bugs found | unique failure clusters | tests | valid rate | TTF (s) | FP(fixed) | BugDetectionRate | TestEfficiency |
|---|---:|---:|---:|---:|---:|---:|---:|---:|
| B1_random | 11.33/19 | 11.7 | 464.7 | 0.805 | 0.38 | 0 | 0.596 | 0.0252 |
| B1_random_full_oracle | 14.0/19 | 18.0 | 355.0 | 0.765 | 0.32 | 0 | 0.737 | 0.0507 |
| B3_nnsmith_native | 6.0/19 | 6.0 | 152.0 | 1.0 | 1.01 | 0 | 0.316 | 0.0395 |
| B3_nnsmith_plus_our_contexts | 9.0/19 | 9.0 | 496.0 | 1.0 | 2.53 | 0 | 0.474 | 0.0181 |
| B5_ours | 19.0/19 | 23.0 | 235.0 | 0.936 | 0.34 | 0 | 1.0 | 0.0979 |

External tools (Setting A needs the tool's own runner; Setting B loads their outputs with --external DIR):

- FreeFuzz (ICSE 2022): not installed - clone https://github.com/ise-uiuc/FreeFuzz and export generated API calls as f/args files
- NNSmith (ASPLOS 2023): available - pip install nnsmith; run `nnsmith.model_gen backend.type=torchjit` and export models as f/args files
- TorchProbe (APLAS 2023): not installed - clone the TorchProbe artifact (arXiv 2310.20078) and export transformed programs as f/args files
- TitanFuzz (ISSTA 2023): not installed - clone https://github.com/ise-uiuc/TitanFuzz and export generated programs as f/args files
- DeepREL (ESEC/FSE 2022): not installed - clone https://github.com/ise-uiuc/DeepREL (supplemental baseline)
