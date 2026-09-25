# P0-2 证据口径核验 — audit ledger (generated 2026-09-25, read-only GitHub queries via `gh api -X GET`)

Files: `items.csv` (73 report items, one row each), `historical_pairs.csv` (35 buggy/fixed pairs), this summary. Nothing under `paper_tcc/`, `0913issues/`, `0920issues/` was modified; no tracker was written to. Scratch inputs (raw API dumps, builder scripts) are in `%TEMP%\claude\...\scratchpad\p02\` (`recheck_items.json`, `recheck_pairs.json`, `pairs_commits.json`, `build_items.py`, `build_pairs.py`, `build_audit.py`).

## Part A — 73 reported items

### A.1 Summary

| quantity | value | how computed |
|---|---|---|
| report items | 73 | rows of `paper_tcc/data/findings.csv` (= rows of the 论文口径 table: 27 + 46) |
| by kind | 55 new issues, 15 comments, 3 vendor reports | `kind` column |
| by target | pytorch 68, msvc 3, numba 1, jax 1 | `target` column |
| candidates (numbered ledger rows in `plan/TO_SUBMIT.md`) | 102 | rows `| N |`; 72 of them are cited by the 73 items' `source_run`; 30 are not: 21 negative-result rows (59, 62, 63, 64, 70, 73, 74, 78, 79, 80, 83, 84, 86, 87, 88, 91, 92, 93, 96, 98, 101), 2 declined by the user (26, 29), 7 other (19, 61, 66, 67, 95, 97, 102: merged into another report, duplicate of an existing issue, infrastructure note, or corpus-experiment record) |
| candidates rejected before the ledger numbering | 22 | rows of the unnumbered `## 不提交的` table (duplicates / invalid / eager-side) |
| items without a ledger row | 2 | C33, C43 (supplementary comments; their evidence path is still recorded in the draft header) |
| independent root causes (RC ids) | 64 | one id per mechanism; 6 ids cover more than one item: RC01 = B1, C32, C33, C39 (complex conj view not materialised inside composite linalg k); RC30 = C3, C26 (cached graph keeps a stale specialised Python scalar (float ); RC49 = C22, C31 (ops.constant wraps an out-of-range Python scalar into the te); RC56 = C30, C37, C38 (decompositions compute on dtypes whose eager kernels raise N); RC62 = C42, C43 (escaped generator reconstructed as an exhausted tuple_iterat); RC63 = C44, C45 (IndexError from a tensor op skips the user's except handler) |
| root causes among the 55 new issues only | 54 | B1 and C32 share RC01, otherwise one per issue |
| contract validity (eager == compiled) | yes 66 (yes: 49, yes (artifact path): 2, yes (metadata): 1, yes (exception parity): 5, yes (alias): 1, yes (torch.fx contract): 3, yes (state): 2, yes (type/alias): 1, yes (exception): 2); n/a (other target) 4; no 2; expected-behavior 1 | `contract_valid` column; 'n/a (other target)' = MSVC/Numba reports (contract is O0 vs O2 / nopython vs NumPy); 'no' = B16 (eager-side crash on both paths) and C12 (JAX eager and jit both hang); 'expected-behavior' = B13 (#197096) |
| items whose draft header names no platform | 14 | B6, B12, B13, B14, B15, B20, B23, B24, B25, C5, C6, C18, C19, C33: header says only `torch 2.14.0+cpu (git 08187d9e…)`; `0913issues/README.md` states all 27 round-1 drafts were re-checked on Windows and Linux, but the per-draft header does not record the Linux run for these — recorded as 'Windows (local run)' here |

### A.2 Four-bucket counts: snapshot (ISSUE_OUTCOMES.md, 2026-09-23 13:05) vs re-check (2026-09-25)

| 轮次 | 提交 | 已修复 (09-23 → 09-25) | 已确认 (09-23 → 09-25) | Pending (09-23 → 09-25) | 拒绝 (09-23 → 09-25) |
|---|---|---|---|---|---|
| round 1 (0913) | 27 | 10 → 9 | 7 → 9 | 9 → 8 | 1 → 1 |
| round 2 (0920) | 46 | 4 → 6 | 3 → 5 | 39 → 35 | 0 → 0 |
| 合计 | 73 | 14 → 15 | 10 → 14 | 48 → 43 | 1 → 1 |

`findings.csv` (the paper's data file) carries the 2026-09-23 buckets exactly (14 / 10 / 48 / 1); `stats.json` agrees. The re-check moves the following items (rule order 已修复 > 已确认 > Pending > 拒绝; a PR that GitHub shows as *closed* counts as landed only when the issue was closed by a commit, because pytorch lands through pytorchmergebot):

| item | issue | 09-23 bucket | 2026-09-25 bucket | evidence |
|---|---|---|---|---|
| B16 | 197099 | 已修复 | 已确认 | CHANGED since 09-23: fix PR #197152 was closed unmerged on 2026-09-24 (no mergebot merge, issue still open); chinmayirm posted the root cause on 09-21 -> 已确认 |
| B22 | 197106 | Pending | 已确认 | CHANGED since 09-23: TANGBUDU (CONTRIBUTOR) reproduced on f28a8c4796 and described a lowering fix (09-22); no PR yet |
| C8 | 197893 | 已确认 | 已修复 | CHANGED since 09-23: fix PR #198446 'Preserve user-visible output aliasing' (Fixes) opened; chinmayirm root cause 09-21; wwoosshh reproduced a scatter variant 09-22 |
| C29 | 198081 | Pending | 已确认 | CHANGED since 09-23: vikrambal located the root cause (reduce_any lowering bypasses _refs.any dtype handling, 09-22); no PR yet |
| C37 | 198155 | Pending | 已确认 | AMBIGUOUS: maintainer eellison (09-22) questions restricting compile for an eager limitation; draft PR #198316 (no 'Fixes' keyword) covers 6 bitwise ops (09-23). Counted 已确认 (maintainer engaged); by the letter of rule 1 a fix PR exists -> could be 已修复; by eell |
| C41 | 198189 | Pending | 已修复 | CHANGED since 09-23: fix PR #198518 '[dynamo] Fix silent dropped mutation for OrderedDict.move_to_end' (Fixes) opened; vikrambal root cause 09-22 |
| C42 | 198190 | Pending | 已确认 | CHANGED since 09-23 (judgement call): JEWEL169 analysed LocalGeneratorObjectVariable reconstruction and argues it is a bug (09-22); no maintainer comment, no PR |

Reconciliation: all 73 items of `ISSUE_OUTCOMES.md` are present in `items.csv` with the same tracker URL (55 issues by number, 15 comments by comment id, 3 Developer Community ids). The 2026-09-23 per-round counts (27 = 10/7/9/1; 46 = 4/3/39/0) are reproduced from `findings.csv`'s `status` column. The 2026-09-25 re-check disagrees only through the 7 moves listed above, all caused by GitHub activity between 09-23 and 2026-09-25 (one fix PR closed unmerged, two new fix PRs, four new contributor analyses, one maintainer pushback). The ISSUE_OUTCOMES generator (`plan/scripts/issue_outcomes.py`) would not see these moves by itself: its `VERDICT` table is hand-maintained and its `has_fix_pr` test reads the `fixes` flag of PRs in the timeline, so re-running `issue_status_report.py && issue_outcomes.py` refreshes the raw data but the buckets change only after the VERDICT table is edited.

Label note: 15 of the Pending PyTorch issues now carry a `triaged` label applied by a human (frgossen, release triage) with no comment: B1, B3, B6, B9, C3, C13, C14, C16, C17, C20, C22, C34, C35, C36, C46. Under the current 口径 (label alone is not confirmation) they stay Pending; if the user ever counts human triage labels as confirmation, 已确认 rises by that amount.

### A.3 Per-item ledger

`items.csv` columns: item_id, round, draft, kind, target, tracker_url, source_run (TO_SUBMIT row numbers + evidence paths from the draft header), program_or_operator, torch_versions_reproduced, platforms, verification_text (draft header 验证版本 verbatim, truncated), contract_valid, duplicate_relation, root_cause_id, root_cause_label, layer/symptom/axis/oracle/attribution (from findings.csv), status_bucket (2026-09-25), status_findings_csv (09-23), status_date, status_evidence, fix_merged, new_since_snapshot.

| item | draft | kind | tracker | RC | versions | platforms | contract | bucket 09-25 | fix merged |
|---|---|---|---|---|---|---|---|---|---|
| B1 | 0913/01 | new issue | #197084 | RC01 | 2.14.0+cpu; 2.15.0.dev20260911 | Windows, Linux | yes | Pending | no |
| B2 | 0913/02 | new issue | #197085 | RC02 | 2.14.0+cpu; 2.15.0.dev20260911 | Windows, Linux | yes | 已修复 | no (open fix PR #197768, #198062) |
| B3 | 0913/03 | new issue | #197086 | RC04 | 2.14.0+cpu; 2.15.0.dev20260911 | Windows, Linux | yes | Pending | no |
| B4 | 0913/04 | new issue | #197087 | RC05 | 2.14.0+cpu | Windows | yes | 已确认 | no |
| B5 | 0913/05 | new issue | #197088 | RC06 | 2.14.0+cu130; 2.10.0+cu128 | Linux, CUDA T4 | yes | 已确认 | no |
| B6 | 0913/06 | new issue | #197089 | RC07 | 2.14.0+cpu | Windows (header names no platform; local run) | yes | Pending | no |
| B7 | 0913/07 | new issue | #197090 | RC08 | 2.14.0+cpu; 2.15.0.dev20260911 | Windows, Linux | yes | Pending | no |
| B8 | 0913/08 | new issue | #197091 | RC09 | 2.14.0+cpu; 2.14.0+cu130; 2.15.0.dev20260911 | Windows, Linux, CUDA T4 | yes | 已修复 | no (open fix PR #197162) |
| B9 | 0913/09 | new issue | #197092 | RC10 | 2.14.0+cpu; 2.15.0.dev20260911 | Windows, Linux | yes | Pending | no |
| B10 | 0913/10 | new issue | #197093 | RC11 | 2.14.0+cpu; 2.15.0.dev20260911 | Windows, Linux | yes | 已确认 | no |
| B11 | 0913/11 | new issue | #197094 | RC12 | 2.14.0+cpu; 2.15.0.dev20260911 | Windows, Linux | yes | 已确认 | no |
| B12 | 0913/12 | new issue | #197095 | RC13 | 2.14.0+cpu | Windows (header names no platform; local run) | yes | 已确认 | no |
| B13 | 0913/13 | new issue | #197096 | RC14 | 2.14.0+cpu | Windows (header names no platform; local run) | expected-behavior | 拒绝 | no |
| B14 | 0913/14 | new issue | #197097 | RC15 | 2.14.0+cpu | Windows (header names no platform; local run) | yes | 已修复 | no (open fix PR #197231) |
| B15 | 0913/15 | new issue | #197098 | RC16 | 2.14.0+cpu | Windows (header names no platform; local run) | yes | Pending | no |
| B16 | 0913/16 | new issue | #197099 | RC17 | 2.14.0+cpu | Windows | no | 已确认 | no |
| B17 | 0913/17 | new issue | #197101 | RC03 | 2.14.0+cpu; 2.15.0.dev20260911 | Windows, Linux | yes | 已修复 | yes: closed by commit c8e4ab54e0 |
| B18 | 0913/18 | new issue | #197102 | RC18 | 2.14.0+cpu; 2.15.0.dev20260911 | Windows, Linux | yes | Pending | no |
| B19 | 0913/19 | new issue | #197103 | RC19 | 2.14.0+cpu | Windows | yes | Pending | no |
| B20 | 0913/20 | new issue | #197104 | RC20 | 2.14.0+cpu | Windows (header names no platform; local run) | yes (artifact path) | 已修复 | yes: closed by commit bc77d149b7 |
| B21 | 0913/21 | new issue | #197105 | RC21 | 2.14.0+cpu; 2.14.0+cu130; 2.15.0.dev20260911 | Windows, Linux, CUDA T4 | yes | 已修复 | no (open fix PR #197193) |
| B22 | 0913/22 | new issue | #197106 | RC22 | 2.14.0+cpu; 2.15.0.dev20260911 | Windows, Linux | yes | 已确认 | no |
| B23 | 0913/23 | new issue | #197107 | RC23 | 2.14.0+cpu | Windows (header names no platform; local run) | yes | 已修复 | no (open fix PR #197214) |
| B24 | 0913/24 | new issue | #197108 | RC24 | 2.14.0+cpu | Windows (header names no platform; local run) | yes | 已修复 | no (open fix PR #197165) |
| B25 | 0913/25 | new issue | #197109 | RC25 | 2.14.0+cpu | Windows (header names no platform; local run) | yes (metadata) | 已确认 | no |
| B26 | 0913/26 | new issue | #197110 | RC26 | 2.14.0+cpu; 2.15.0.dev20260911 | Windows, Linux | yes | 已修复 | yes: closed by commit 887633d60b |
| B27 | 0913/27 | new issue | #197112 | RC27 | 2.14.0+cpu; 2.15.0.dev20260911 | Windows, Linux | yes | 已确认 | no |
| C1 | 0920/01 | new issue | #197887 | RC28 | 2.14.0+cpu; 2.14.0+cu130; 2.15.0.dev20260911; 2.15.0.dev2026 | Windows, Linux, CUDA T4 | yes | 已修复 | no (open fix PR #198035) |
| C2 | 0920/02 | new issue | #197888 | RC29 | 2.14.0+cpu; 2.14.0+cu130; 2.15.0.dev20260911; 2.15.0.dev2026 | Windows, Linux, CUDA T4 | yes | 已确认 | no |
| C3 | 0920/02b | new issue | #197889 | RC30 | 2.14.0+cpu; 2.14.0+cu130; 2.15.0.dev20260911; 2.15.0.dev2026 | Windows, Linux, CUDA T4 | yes | Pending | no |
| C4 | 0920/03 | comment | #143649 (comment) | RC31 | 2.14.0+cpu; 2.15.0.dev20260911; 2.15.0.dev20260921 | Windows, Linux | yes | Pending | n/a (comment) |
| C5 | 0920/04 | comment | #197554 (comment) | RC32 | 2.14.0+cpu | Windows (header names no platform; local run) | yes (exception parity) | Pending | n/a (comment) |
| C6 | 0920/05 | vendor report | DevCom MSVC-x64-optimizer-folds-two-consecutive/11155532 | RC33 | MSVC 19.44.35228 | Windows (header names no platform; local run) | n/a (other target) | Pending | no |
| C7 | 0920/06 | new issue | numba/numba/issues/10845 | RC34 | numba 0.67.0 | Windows, Linux | n/a (other target) | Pending | no |
| C8 | 0920/07 | new issue | #197893 | RC35 | 2.14.0+cpu; 2.14.0+cu130; 2.15.0.dev20260911; 2.15.0.dev2026 | Windows, Linux, CUDA T4 | yes (alias) | 已修复 | no (open fix PR #198446) |
| C9 | 0920/08 | new issue | #197894 | RC36 | 2.14.0+cpu; 2.15.0.dev20260911; 2.15.0.dev20260921 | Windows, Linux | yes (torch.fx contract) | 已修复 | no (open fix PR #198053) |
| C10 | 0920/09 | new issue | #197895 | RC37 | 2.14.0+cpu; 2.14.0+cu130; 2.15.0.dev20260911; 2.15.0.dev2026 | Windows, Linux, CUDA T4 | yes | 已确认 | no |
| C11 | 0920/10 | new issue | #197896 | RC38 | 2.14.0+cpu; 2.15.0.dev20260911; 2.15.0.dev20260920 | Windows, Linux | yes (state) | 已修复 | no (open fix PR #198055) |
| C12 | 0920/11 | new issue | jax-ml/jax/issues/40840 | RC39 | jax 0.11.2 | Windows, Linux | no | 已修复 | no (open fix PR #40842) |
| C13 | 0920/12 | new issue | #198052 | RC40 | 2.14.0+cpu; 2.15.0.dev20260911 | Windows | yes | Pending | no |
| C14 | 0920/13 | new issue | #198057 | RC41 | 2.14.0+cpu; 2.15.0.dev20260911; 2.15.0.dev20260920 | Windows, Linux, CUDA T4 | yes | Pending | no |
| C15 | 0920/14 | comment | #191499 (comment) | RC42 | 2.14.0+cpu; 2.15.0.dev20260911; 2.15.0.dev20260920 | Windows, Linux, CUDA T4 | yes | Pending | n/a (comment) |
| C16 | 0920/15 | new issue | #198064 | RC43 | 2.14.0+cpu; 2.15.0.dev20260911; 2.15.0.dev20260921 | Windows, Linux | yes | Pending | no |
| C17 | 0920/16 | new issue | #198070 | RC44 | 2.14.0+cpu; 2.15.0.dev20260911; 2.15.0.dev20260921 | Windows, Linux | yes | Pending | no |
| C18 | 0920/17 | vendor report | DevCom MSVC-x64-optimizer-removes-_mm_add_psx/11155535 | RC45 | MSVC 19.44.35228 | Windows (header names no platform; local run) | n/a (other target) | Pending | no |
| C19 | 0920/18 | vendor report | DevCom MSVC-x64-optimizer-folds-compare-and-ble/11155537 | RC46 | MSVC 19.44.35228 | Windows (header names no platform; local run) | n/a (other target) | Pending | no |
| C20 | 0920/19 | new issue | #198056 | RC47 | 2.14.0+cpu; 2.15.0.dev20260911 | Windows | yes | Pending | no |
| C21 | 0920/20 | comment | #185337 (comment) | RC48 | 2.14.0+cpu; 2.14.0+cu130; 2.15.0.dev20260911; 2.15.0.dev2026 | Windows, Linux, CUDA T4 | yes | Pending | n/a (comment) |
| C22 | 0920/21 | new issue | #198071 | RC49 | 2.14.0+cpu; 2.14.0+cu130; 2.15.0.dev20260911 | Windows, Linux, CUDA T4 | yes | Pending | no |
| C23 | 0920/22 | comment | #197554 (comment) | RC50 | 2.14.0+cpu; 2.14.0+cu130; 2.15.0.dev20260911; 2.15.0.dev2026 | Windows, Linux, CUDA T4 | yes (exception parity) | Pending | n/a (comment) |
| C24 | 0920/23 | new issue | #198072 | RC51 | 2.14.0+cpu; 2.15.0.dev20260911; 2.15.0.dev20260921 | Windows, Linux | yes (torch.fx contract) | Pending | no |
| C25 | 0920/24 | comment | #174386 (comment) | RC52 | 2.14.0+cpu; 2.14.0+cu130; 2.15.0.dev20260911; 2.15.0.dev2026 | Windows, Linux, CUDA T4 | yes | Pending | n/a (comment) |
| C26 | 0920/25 | comment | #197889 (comment) | RC30 | 2.14.0+cpu; 2.15.0.dev20260911 | Windows | yes | Pending | n/a (comment) |
| C27 | 0920/26 | new issue | #198077 | RC53 | 2.14.0+cpu; 2.15.0.dev20260911; 2.15.0.dev20260921 | Windows, Linux | yes (torch.fx contract) | Pending | no |
| C28 | 0920/27 | comment | #183607 (comment) | RC54 | 2.14.0+cpu; 2.14.0+cu130; 2.15.0.dev20260911; 2.15.0.dev2026 | Windows, Linux, CUDA T4 | yes | Pending | n/a (comment) |
| C29 | 0920/28 | new issue | #198081 | RC55 | 2.14.0+cpu; 2.14.0+cu130; 2.15.0.dev20260911; 2.15.0.dev2026 | Windows, Linux, CUDA T4 | yes | 已确认 | no |
| C30 | 0920/29 | comment | #197554 (comment) | RC56 | 2.14.0+cpu; 2.15.0.dev20260911 | Windows | yes (exception parity) | Pending | n/a (comment) |
| C31 | 0920/30 | comment | #198071 (comment) | RC49 | 2.14.0+cpu; 2.15.0.dev20260911 | Windows | yes | Pending | n/a (comment) |
| C32 | 0920/31 | new issue | #198118 | RC01 | 2.14.0+cpu; 2.14.0+cu130; 2.15.0.dev20260911 | Windows, Linux, CUDA T4 | yes | Pending | no |
| C33 | 0920/32 | comment | #197084 (comment) | RC01 | 2.14.0+cpu; 2.15.0.dev20260911 | Windows (header names no platform; local run) | yes | Pending | n/a (comment) |
| C34 | 0920/33 | new issue | #198119 | RC57 | 2.14.0+cpu; 2.14.0+cu130; 2.15.0.dev20260911 | Windows, Linux, CUDA T4 | yes | Pending | no |
| C35 | 0920/34 | new issue | #198133 | RC58 | 2.14.0+cpu; 2.14.0+cu130; 2.15.0.dev20260911 | Windows, Linux, CUDA T4 | yes | Pending | no |
| C36 | 0920/35 | new issue | #198134 | RC59 | 2.14.0+cpu; 2.15.0.dev20260911 | Windows, Linux, CUDA T4 | yes | Pending | no |
| C37 | 0920/36 | new issue | #198155 | RC56 | 2.14.0; 2.15.0.dev20260911 | Windows, Linux | yes (exception parity) | 已确认 | no (open PR referencing it: #198316) |
| C38 | 0920/37 | comment | #198155 (comment) | RC56 | 2.14.0+cu130 | Linux, CUDA T4 | yes (exception parity) | Pending | n/a (comment) |
| C39 | 0920/38 | comment | #198118 (comment) | RC01 | 2.14.0+cpu; 2.15.0.dev20260911 | Windows | yes | Pending | n/a (comment) |
| C40 | 0920/39 | new issue | #198183 | RC60 | 2.14.0+cpu; 2.15.0.dev20260911; 2.15.0.dev20260922 | Windows, Linux | yes | Pending | no |
| C41 | 0920/40 | new issue | #198189 | RC61 | 2.14.0+cpu; 2.15.0.dev20260911; 2.15.0.dev20260922 | Windows, Linux | yes (state) | 已修复 | no (open fix PR #198518) |
| C42 | 0920/41 | new issue | #198190 | RC62 | 2.14.0+cpu; 2.15.0.dev20260911; 2.15.0.dev20260922 | Windows, Linux | yes (type/alias) | 已确认 | no |
| C43 | 0920/41b | comment | #198190 (comment) | RC62 | 2.14.0+cpu; 2.15.0.dev20260911 | Windows | yes | Pending | n/a (comment) |
| C44 | 0920/42 | new issue | #198192 | RC63 | 2.14.0+cpu; 2.15.0.dev20260911 | Windows | yes (exception) | Pending | no |
| C45 | 0920/42b | comment | #198192 (comment) | RC63 | 2.14.0+cpu; 2.15.0.dev20260921 | Windows | yes (exception) | Pending | n/a (comment) |
| C46 | 0920/43 | new issue | #198205 | RC64 | 2.14.0+cpu; 2.15.0.dev20260911 | Windows, Linux | yes (artifact path) | Pending | no |

## Part B — 35 historical buggy/fixed pairs

### B.1 Summary

| quantity | value | how computed |
|---|---|---|
| pairs | 35 | `plan/benchmark/fix_status_2.14.json` = the 35 `Kind: fixed` entries of `plan/benchmark/historical_bugs.json` (closed issue, detected on 2.10.0+cpu, not detected on 2.14.0+cpu) |
| same device and platform | 35 / 35 | both sides are Kaggle Linux CPU notebooks running the same `plan_kaggle.zip` (`plan/kaggle/jobs/bench210.py` / `bench214.py` differ only in the torch version string): side A `kaggle_out/chenyuefei_notebookf4aab87efb/plan/reports_gh_cpu_2.10` (torch 2.10.0+cpu, Python 3.12.13, Linux 6.12.90+, glibc 2.35, g++), side B `kaggle_out/chenyuefei_notebook955c6cac50/plan/reports_gh_cpu_2.14` (torch 2.14.0+cpu; only `isolated_children.log` records the version, no environment.txt was pulled) |
| detection rates behind the paper's RQ5 sentence | closed 50/123 = 40.7% → 16/123 = 13.0%; open 32/70 = 45.7% → 29/70 = 41.4% | `KNOWN_BUGS.md` headers of the two report dirs; 193 programs on both sides |
| fix commit recorded and contained in v2.14.0 | 19 yes, 1 probable, 15 unknown | 12 from the closing-event commit (`fix_status_2.14.json`, compare API status `behind` = ancestor of the tag; v2.14.0 tag commit 2026-08-27, release 2026-09-02) + 7 more from landed PRs found on 2026-09-25 by searching main for `Pull Request resolved: .../pull/N` (PRs #176842, #177875, #177270, #184359 ×2, #187024, #189529) |
| evidence type | 19 version-diff + fix commit, 16 version-diff only | `evidence_type` column |
| old-side divergence kind (2.10) | compiled raises where eager returns (exception): 15, value oracle: 14, metadata+value oracle: 3, diverged (kind unknown): 2, alias+mutation oracle: 1 | `record.json` triage.kinds of the Kaggle 2.10 run; for 6 programs whose record dirs were not pulled the kind comes from the T4 2.10.0+cu128 run, for #178964 and #185330 it is unknown |
| new-side result (2.14) | 35 ok (no divergence, no harness error) | `run_results.json` of the 2.14 run: n_records = 0, error = null |

The checklist's '12 of 35 have a fix commit recorded' matches `fix_status_2.14.json` (12 × `in_release: true`). The re-check raises the number of pairs with a fix commit known to be in v2.14.0 to 19 (+1 probable); 15 pairs rest on the version difference alone.

### B.2 Pairs where only a version difference exists (no landed fix commit found)

| issue | closed | note |
|---|---|---|
| #166514 | closed (completed), closed 2026-05-16 | PR #168107 closed, no landed commit found by commit search (Fixes) |
| #175496 | closed (completed), closed 2026-05-15 | no closing commit and no cross-referenced PR found |
| #175632 | closed (completed), closed 2026-03-25 | no closing commit and no cross-referenced PR found |
| #177629 | closed (completed), closed 2026-06-09 | no closing commit and no cross-referenced PR found |
| #178262 | closed (completed), closed 2026-03-24 | no closing commit and no cross-referenced PR found |
| #179383 | closed (completed), closed 2026-05-21 | PR #179389 closed, no landed commit found by commit search (Fixes) |
| #179807 | closed (completed), closed 2026-04-15 | no closing commit and no cross-referenced PR found |
| #181625 | closed (completed), closed 2026-04-29 | no closing commit and no cross-referenced PR found |
| #182399 | closed (duplicate), closed 2026-05-05 | issue was closed as DUPLICATE, not completed |
| #182965 | closed (completed), closed 2026-06-14 | PR #185559 closed, no landed commit found by commit search |
| #183121 | closed (completed), closed 2026-05-12 | PR #183373 closed, no landed commit found by commit search |
| #185330 | closed (completed), closed 2026-06-01 | no closing commit and no cross-referenced PR found |
| #187027 | closed (completed), closed 2026-08-28 | PR #184392 closed, no landed commit found by commit search (Fixes) |
| #188084 | closed (completed), closed 2026-06-24 | no closing commit and no cross-referenced PR found |
| #195422 | closed (completed), closed 2026-09-01 | no closing commit and no cross-referenced PR found |

### B.3 Caveats found

- #182399 was closed as *duplicate* (of #181870), not as completed; its 'fix' is #181870's PR #182004 (in v2.14.0). Counting it as an independent pair double-counts one fix.
- #178125 / #178128: the closing-event commit 3d99896d47 (2026-08-03) is in v2.14.0, but the PR that says `Fixes` for both (#188328) landed 2026-09-16, after the tag; what 3d99896d47 is was not resolved (compare API only). The two issues share one commit, so they are one fix.
- #183763 / #183765 share PR #184359; #183767 is closed but only referenced (not `Fixes`) by the same PR.
- Old-side kinds for #113641, #178125, #181625, #182399, #187027, #189528 come from the T4 run; the Kaggle CPU pull contains 96 of the 2.10 record dirs and only 7 of the 2.14 ones. #178964 and #185330: kind unknown.
- Both Kaggle notebook logs (`notebookf4aab87efb.log`, `notebook955c6cac50.log`) are 0 bytes; the 2.14 side's Python/kernel version is therefore not on record (2.10 side: environment.txt in every record dir).
- Cross-references from forks or other repositories (PR numbers below 100000, e.g. `#43`, `#95`, `#4300`, `#47238`) appear in the GitHub timelines and were dropped; only pytorch/pytorch PRs are counted.
- Paper text vs figure: `05-evaluation.tex` says detection of open issues 'stays at 41%' across 2.10 and 2.14; the data (and `fig-rq1-history.tex`) give 45.7% → 41.4%.

### B.4 Per-pair table (full detail in `historical_pairs.csv`)

| BugID | issue | reproducer | 2.10 result | 2.14 result | fix | in 2.14 | evidence |
|---|---|---|---|---|---|---|---|
| PT-0001 | #113641 | issue_113641_compiling_double_inplace_clamp_on_stride.py | compiled raises where eager returns (exception) | ok: no divergence | closing commit e736d27e38; PR #113838 landed e736d27e38 | yes | version-diff + fix commit |
| PT-0002 | #166514 | issue_166514_inductor_fails_with_stride_mismatch_for.py | compiled raises where eager returns (exception) | ok: no divergence | none found (closed manually; no landed PR cross-referenced) | unknown | version-diff only |
| PT-0003 | #174969 | issue_174969_torch_compile_outputs_incorrect_results.py | value oracle | ok: no divergence | closing commit ae81c1491f; PR #175623 landed ae81c1491f | yes | version-diff + fix commit |
| PT-0004 | #175156 | issue_175156_inductor_multiple_randint_calls_cause_in.py | value oracle | ok: no divergence | PR #176842 landed ea0a353f21 | yes | version-diff + fix commit |
| PT-0005 | #175496 | issue_175496_inductor_model_with_torch_compile_output.py | value oracle | ok: no divergence | none found (closed manually; no landed PR cross-referenced) | unknown | version-diff only |
| PT-0006 | #175632 | issue_175632_inductor_torch_compile_produces_inconsis.py | value oracle | ok: no divergence | none found (closed manually; no landed PR cross-referenced) | unknown | version-diff only |
| PT-0007 | #175919 | issue_175919_inductor_out_of_bounds_memory_read_via_r.py | value oracle | ok: no divergence | closing commit fd55c516bd | yes | version-diff + fix commit |
| PT-0008 | #176854 | issue_176854_torch_compile_does_not_correctly_propaga.py | value oracle | ok: no divergence | PR #177875 landed e534ad5160 | yes | version-diff + fix commit |
| PT-0009 | #177252 | issue_177252_inductor_assertionerror_wrong_number_of.py | metadata+value oracle | ok: no divergence | PR #177270 landed 6548add3ea | yes | version-diff + fix commit |
| PT-0010 | #177629 | issue_177629_torch_compile_backend_inductor_silently.py | compiled raises where eager returns (exception) | ok: no divergence | none found (closed manually; no landed PR cross-referenced) | unknown | version-diff only |
| PT-0011 | #178125 | issue_178125_conv_transpose1d_meta_implementation_all.py | compiled raises where eager returns (exception) | ok: no divergence | closing commit 3d99896d47; PR #188328 landed 0ce048439f | yes | version-diff + fix commit |
| PT-0012 | #178128 | issue_178128_conv_transpose3d_meta_execution_produces.py | compiled raises where eager returns (exception) | ok: no divergence | closing commit 3d99896d47; PR #188328 landed 0ce048439f | yes | version-diff + fix commit |
| PT-0013 | #178262 | issue_178262_inductor_incorrect_stride_calculation_in.py | value oracle | ok: no divergence | none found (closed manually; no landed PR cross-referenced) | unknown | version-diff only |
| PT-0014 | #178964 | issue_178964_inductor_max_returns_incorrect_indices_w.py | diverged (kind unknown) | ok: no divergence | closing commit 93c689cc25; PR #179525 landed 93c689cc25 | yes | version-diff + fix commit |
| PT-0015 | #179383 | issue_179383_torch_quantile_and_torch_nanquantile_fai.py | compiled raises where eager returns (exception) | ok: no divergence | none found (closed manually; no landed PR cross-referenced) | unknown | version-diff only |
| PT-0016 | #179534 | issue_179534_torch_compile_fails_on_aten_sparse_csr_t.py | compiled raises where eager returns (exception) | ok: no divergence | closing commit d565abc641 | yes | version-diff + fix commit |
| PT-0017 | #179807 | issue_179807_torch_compile_inductor_crash_f_pad_follo.py | compiled raises where eager returns (exception) | ok: no divergence | none found (closed manually; no landed PR cross-referenced) | unknown | version-diff only |
| PT-0018 | #181175 | issue_181175_aot_autograd_runtimeerror_cannot_call_nu.py | compiled raises where eager returns (exception) | ok: no divergence | closing commit 849eb888e5; PR #184659 landed 849eb888e5 | yes | version-diff + fix commit |
| PT-0019 | #181625 | issue_181625_assertionerror_expected_size_stride_mism.py | compiled raises where eager returns (exception) | ok: no divergence | none found (closed manually; no landed PR cross-referenced) | unknown | version-diff only |
| PT-0020 | #181870 | issue_181870_torch_compile_dynamic_true_fails_on_f_cr.py | compiled raises where eager returns (exception) | ok: no divergence | closing commit 44932144f5; PR #182004 landed 44932144f5 | yes | version-diff + fix commit |
| PT-0021 | #182399 | issue_182399_torch_compile_dynamic_true_fails_on_f_cr.py | compiled raises where eager returns (exception) | ok: no divergence | none found (closed manually; no landed PR cross-referenced) | unknown | version-diff only |
| PT-0022 | #182965 | issue_182965_torch_compile_silently_returns_a_result.py | compiled raises where eager returns (exception) | ok: no divergence | none found (closed manually; no landed PR cross-referenced) | unknown | version-diff only |
| PT-0023 | #183082 | issue_183082_inductor_cpu_returns_wrong_argmax_after.py | value oracle | ok: no divergence | closing commit b298938ef6; PR #183655 landed b298938ef6 | yes | version-diff + fix commit |
| PT-0024 | #183121 | issue_183121_torch_compile_returns_wrong_shape_for_to.py | metadata+value oracle | ok: no divergence | none found (closed manually; no landed PR cross-referenced) | unknown | version-diff only |
| PT-0025 | #183763 | issue_183763_torch_compile_overflows_torch_sinh_near.py | value oracle | ok: no divergence | PR #184359 landed abb46fd178 | yes | version-diff + fix commit |
| PT-0026 | #183765 | issue_183765_torch_compile_overflows_torch_cosh_near.py | value oracle | ok: no divergence | PR #184359 landed abb46fd178 | yes | version-diff + fix commit |
| PT-0027 | #183767 | issue_183767_torch_compile_returns_inf_for_torch_asin.py | value oracle | ok: no divergence | candidate: PR #184359 (references the issue, no Fixes keywor | probable: in v2.14.0 | version-diff only |
| PT-0028 | #185330 | issue_185330_inductor_torch_index_select_on_uint16_in.py | diverged (kind unknown) | ok: no divergence | none found (closed manually; no landed PR cross-referenced) | unknown | version-diff only |
| PT-0029 | #187018 | issue_187018_abs_on_uint8_silently_miscompiled_via_st.py | value oracle | ok: no divergence | PR #187024 landed ef129df4d6 | yes | version-diff + fix commit |
| PT-0030 | #187027 | issue_187027_flip_after_repeat_interleave_generates_n.py | value oracle | ok: no divergence | none found (closed manually; no landed PR cross-referenced) | unknown | version-diff only |
| PT-0031 | #188084 | issue_188084_bug_inductor_reinplaces_index_put_on_exp.py | compiled raises where eager returns (exception) | ok: no divergence | none found (closed manually; no landed PR cross-referenced) | unknown | version-diff only |
| PT-0032 | #189518 | issue_189518_inductor_s_pointless_cumsum_replacement.py | metadata+value oracle | ok: no divergence | closing commit 62cdf554bc; PR #189533 landed 62cdf554bc | yes | version-diff + fix commit |
| PT-0033 | #189528 | issue_189528_cond_inductor_nameerror_on_inner_dim_bra.py | compiled raises where eager returns (exception) | ok: no divergence | PR #189529 landed 9a2bccfb87 | yes | version-diff + fix commit |
| PT-0034 | #190755 | issue_190755_some_dynamo_descriptors_tp_descr_get_imp.py | value oracle | ok: no divergence | closing commit 809044678a; PR #190776 landed 809044678a | yes | version-diff + fix commit |
| PT-0035 | #195422 | issue_195422_inductor_torch_compile_silently_drops_an.py | alias+mutation oracle | ok: no divergence | none found (closed manually; no landed PR cross-referenced) | unknown | version-diff only |

## Part C — corpus batch sanity

| module | `@prog` decorators | unique names | cumulative unique |
|---|---|---|---|
| `plan/tcc/dynamo_semantics.py` | 77 | 77 | 77 |
| `plan/tcc/dynamo_semantics_more.py` | 74 | 74 | 151 |
| `plan/tcc/dynamo_semantics_batch3.py` | 34 | 34 | **185** |
| `plan/tcc/dynamo_semantics_batch4.py` | 57 | 57 (1 name, `chained_comparison_tensor_scalar`, repeats a batch-3 name) | **241** |
| `plan/tcc/dynamo_semantics_batch5.py` | 33 | 33 | **274** |

185 = first three batches, 241 = + batch 4 (242 decorators, 241 distinct names because of the duplicate; TO_SUBMIT row 102 records that the batch-4 duplicate overrode the batch-3 program until the audit script reloaded batch 3), 274 = + batch 5. Confirmed.

Places that mention a corpus size (report only, nothing edited):

| file | line | size | context |
|---|---|---|---|
| `paper_tcc/sections/00-abstract.tex` | 18 | 185 | 'On a 185-program corpus that program-only differential testing under three configurations had already covered' — frozen graph-break experiment |
| `paper_tcc/sections/01-introduction.tex` | 60 | 185 | same sentence as the abstract |
| `paper_tcc/sections/03-approach.tex` | 70 | 274 | '274 programs at the time of writing' — full corpus |
| `paper_tcc/sections/04-analyzers.tex` | 41 | 274 | 'runs the 274 Python programs twice' — full corpus |
| `paper_tcc/sections/05-evaluation.tex` | 33 | 274 | seeds: 'the 274-program Python corpus' |
| `paper_tcc/sections/05-evaluation.tex` | 47 | 185 | 'the 185 programs of the corpus at that time' — RQ1 graph-break experiment |
| `paper_tcc/sections/05-evaluation.tex` | 86 | 185 | RQ1 answer: '185-program corpus ... the 90 programs added afterwards' (185 + 89 distinct = 274; '90' counts the duplicate-named batch-4 program) |
| `plan/TO_SUBMIT.md` | 218 | 185 | row 89: graph-break insertion on the 185-program corpus |
| `plan/TO_SUBMIT.md` | 224 | 241 | row 95: graph-break insertion × 241-program corpus (eager + aot_eager) — intermediate size, not used in the paper |
| `plan/TO_SUBMIT.md` | 231 | 185 | row 102: P0-1 recomputation freezes 185 = 77 + 74 + 34 |

The paper uses two sizes consistently (185 = corpus frozen for the graph-break experiment, 274 = corpus at the time of writing) and never 241. One arithmetic slip: `05-evaluation.tex` line 86 says 'the 90 programs added afterwards'; 274 − 185 = 89 distinct programs (90 decorators, one duplicate name). TO_SUBMIT mixes all three sizes because it is chronological (rows 89 → 95 → 100/102).

## Open questions (evidence missing; nothing invented)

- A: C37 (#198155) bucket. Maintainer eellison (09-22) argues compile need not mirror an eager dtype limitation; a draft PR (#198316, no `Fixes` keyword) covers 6 of the 134 operators. Ledger says 已确认; by rule 1 it could be 已修复, by eellison's view part of the report may end as 拒绝. Resolve when a maintainer states the intended behaviour for the whole family.
- A: C42 (#198190) marked 已确认 on the strength of a contributor's root-cause analysis (JEWEL169, 09-22) with no maintainer comment; if the 口径 requires a reproduction statement rather than an analysis, it stays Pending.
- A: B16 (#197099): fix PR #197152 was closed on 2026-09-24; its comment thread has no `Merge started` from pytorchmergebot and the issue stayed open, so it did not land. Why it was closed (superseded? abandoned?) was not examined. If a replacement PR exists, the bucket returns to 已修复.
- A: MSVC Developer Community items (C6, C18, C19) were not re-checked (no read API); status 'new' is from the 0920 README.
- A: `verification_text` is the draft header as written; the audit did not re-run the 70 snippets (that is `scripts/run_issue_snippet.py`'s job, already done at filing).
- B: 15 pairs have no landed fix commit in the API data (issues closed manually or PR not cross-referenced). Resolving them needs the issue comments (which PR the closer named) or a bisection between 2.10 and 2.14; both are outside the read-only scope used here.
- B: the 2.14 Kaggle side has no environment.txt in the pull and an empty notebook log; Python/kernel version of side B is unrecorded (side A: Python 3.12.13, Linux 6.12.90+). Re-pulling the notebook output would settle it.
- B: #178125/#178128's closing commit 3d99896d47 — which PR it belongs to was not looked up (only the compare status).
- C: `05-evaluation.tex` line 86 '90 programs added afterwards' vs 89 distinct names; and 'open issues stays at 41%' vs 45.7% → 41.4% in the figure. Report only; the paper was not edited.

