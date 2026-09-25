# Outcome of every filed issue (both rounds) — snapshot 2026-09-25 17:37

Regenerate: `python scripts/issue_status_report.py && python scripts/issue_outcomes.py` (read-only GitHub queries). Raw data: `plan/results/issue_status/raw.json`.
Verdict definitions are at the top of `plan/scripts/issue_outcomes.py`; every verdict quotes its evidence. On pytorch/pytorch the `triaged` label is frequently applied by `github-actions[bot]`, so a label alone is **not** counted as confirmation.

## 论文口径（四档：已修复 = 已合入或已有开发者提交修复 PR；已确认 = 维护者口头确认或有人复现；Pending = 尚无人工回应；拒绝 = 维护者认为是预期行为。为 0 的档不列。）

| 轮次 | 提交 | 已修复 | 已确认 | Pending | 拒绝 |
|---|---|---|---|---|---|
| round 1 (0913) | 27 | 10 | 8 | 8 | 1 |
| round 2 (0920) | 46 | 6 | 5 | 35 | 0 |
| 合计 | 73 | 16 | 13 | 43 | 1 |

- round 1 (0913) 已修复（10）：#197085, #197091, #197097, #197099, #197101, #197104, #197105, #197107, #197108, #197110
- round 1 (0913) 已确认（8）：#197087, #197088, #197093, #197094, #197095, #197106, #197109, #197112
- round 1 (0913) Pending（8）：#197084, #197086, #197089, #197090, #197092, #197098, #197102, #197103
- round 1 (0913) 拒绝（1）：#197096
- round 2 (0920) 已修复（6）：#197887, #197893, #197894, #197896, #198189, #40840
- round 2 (0920) 已确认（5）：#197888, #197895, #198081, #198155, #198190
- round 2 (0920) Pending（35）：#197889, #198052, #198056, #198057, #198064, #198070, #198071, #198072, #198077, #198118, #198119, #198133, #198134, #198183, #198192, #198205, #10845, comment under #143649, comment under #197554, Developer Community 11155532, Developer Community 11155535, Developer Community 11155537, comment under #191499, comment under #185337 (closed), second comment under #197554, comment under #174386 (closed), comment under own #197889, comment under #183607, third comment under #197554, comment under own #198071, correction comment under own #197084, comment under own #198155 (CUDA numbers), comment under own #198118 (lstsq backward, FlopCounterMode), comment under own #198190 (trigger condition, iterator family), comment under own #198192 (handler shapes)

## Counts

**round 1 (0913): 27 filed**
- FIXED: 2 — #197101, #197104
- CONFIRMED: 6 — #197085, #197088, #197094, #197095, #197109, #197110
- REPRODUCED: 10 — #197087, #197091, #197093, #197097, #197099, #197105, #197106, #197107, #197108, #197112
- DISPUTED: 1 — #197096
- NO RESPONSE: 8 — #197084, #197086, #197089, #197090, #197092, #197098, #197102, #197103

**round 2 (0920): 46 filed**
- CONFIRMED: 3 — #197888, #197896, #40840
- REPRODUCED: 8 — #197887, #197893, #197894, #197895, #198081, #198155, #198189, #198190
- NO RESPONSE: 35 — #197889, #198052, #198056, #198057, #198064, #198070, #198071, #198072, #198077, #198118, #198119, #198133, #198134, #198183, #198192, #198205, #10845, comment under #143649, comment under #197554, Developer Community 11155532, Developer Community 11155535, Developer Community 11155537, comment under #191499, comment under #185337 (closed), second comment under #197554, comment under #174386 (closed), comment under own #197889, comment under #183607, third comment under #197554, comment under own #198071, correction comment under own #197084, comment under own #198155 (CUDA numbers), comment under own #198118 (lstsq backward, FlopCounterMode), comment under own #198190 (trigger condition, iterator family), comment under own #198192 (handler shapes)

Round 1 in the paper's terms: 2 fixed; 8 confirmed by maintainers (fixed + CONFIRMED); 18 confirmed if independent reproductions / open fix PRs are included; 14 fix PRs are open and would raise the fixed count when they land.

**Paper numbers come only from the 论文口径 table above (four buckets fixed by the user on 2026-09-23).**

## All items

| draft | issue | filed | state | verdict | evidence | title |
|---|---|---|---|---|---|---|
| 0913/01 | pytorch/pytorch #197084 | 2026-09-15 | open | **NO RESPONSE** | only bot-applied labels / no human reaction yet | [aot_autograd] wrong gradients for `torch.linalg.pinv` and `torch.linalg.matrix_sqrth` with complex input unde |
| 0913/02 | pytorch/pytorch #197085 | 2026-09-15 | open | **CONFIRMED** | human-triaged by williamwen42, who also added `module: correctness (silent)`; fix PR #197768 open (“Fixes”) | [dynamo] random.shuffle / random.sample inside a compiled function return the same permutation on every call ( |
| 0913/03 | pytorch/pytorch #197086 | 2026-09-15 | open | **NO RESPONSE** | only bot-applied labels / no human reaction yet | [aot_autograd] process crash (access violation) when `torch.func.jvp` over `torch.ldexp` is compiled with `bac |
| 0913/04 | pytorch/pytorch #197087 | 2026-09-15 | open | **REPRODUCED** | chinmayirm located the cause (index expression printed with Python `str()`, `**` reaches the C++ kernel); no maintainer comment yet | [inductor][cpu] argmin/argmax under `dynamic=True` emits the index expression with Python `**` into C++ → CppC |
| 0913/05 | pytorch/pytorch #197088 | 2026-09-15 | open | **CONFIRMED** | assigned to contributor oonyshch (“Taking a look”, 2026-09-17) | [inductor][cudagraphs] `x.new_zeros(shape, device="cpu")` inside a compiled function returns a **CUDA** tensor |
| 0913/06 | pytorch/pytorch #197089 | 2026-09-15 | open | **NO RESPONSE** | only bot-applied labels / no human reaction yet | [inductor][cpu] `torch.std`/`var` accumulate in float32: inf/NaN for 1e30-scale inputs, and **zero output with |
| 0913/07 | pytorch/pytorch #197090 | 2026-09-15 | open | **NO RESPONSE** | only bot-applied labels / no human reaction yet | [dynamo] `torch.func.jvp` inside a compiled function hits `INTERNAL ASSERT FAILED: InferenceMode::is_enabled() |
| 0913/08 | pytorch/pytorch #197091 | 2026-09-15 | open | **REPRODUCED** | fix PR #197162 open (“Fixes”), no maintainer comment yet | [inductor] `torch.ldexp` output dtype differs from eager in both directions (int/bool × half → float32; half × |
| 0913/09 | pytorch/pytorch #197092 | 2026-09-15 | open | **NO RESPONSE** | only bot-applied labels / no human reaction yet | [compiled autograd] backward of `F.interpolate(mode="bilinear"/"bicubic"/"linear"/"trilinear")` fails with `is |
| 0913/10 | pytorch/pytorch #197093 | 2026-09-15 | open | **REPRODUCED** | tsho reproduced it on 2.14.0 and a source build and located the cause (`LazySymNodeFormatString.__repr__`); waits for the `actionable` label before sending a PR | [dynamo] `dynamic=True`: f-string with a format spec on a SymInt/SymFloat (`f"{x.shape[0]:d}"`) raises Interna |
| 0913/11 | pytorch/pytorch #197094 | 2026-09-15 | open | **CONFIRMED** | williamwen42 (MEMBER) triaged it, added `has workaround`, cc'd and assigned hameerabbasi | [inductor] `torch.compile(optimizer.step)` fails for SGD with `foreach=True` on complex parameters: "Assertion |
| 0913/12 | pytorch/pytorch #197095 | 2026-09-15 | open | **CONFIRMED** | malfet (core maintainer): “eager raises correctly and the compiled path bypasses it”; made a member of his umbrella #197554 “[PT2] Validation lost”; yashb98 volunteered a fix | [inductor] `F.interpolate` on a zero-size spatial dim returns uninitialised data (NaN) from an out-of-bounds r |
| 0913/13 | pytorch/pytorch #197096 | 2026-09-15 | open | **DISPUTED** | yushangdi (AOTI maintainer): “kinda expected behavior” — mutation of lifted constants is unsupported after functionalization; still open | [export][aoti] mutated lifted constant (instance_norm running stats captured from closure): export succeeds, r |
| 0913/14 | pytorch/pytorch #197097 | 2026-09-15 | open | **REPRODUCED** | fix PR #197231 open (“Fixes”) | [pt2] `linalg.vector_norm(ord=inf / -inf / negative, dim=-1)` on an empty *batch* fails at trace time — the em |
| 0913/15 | pytorch/pytorch #197098 | 2026-09-15 | open | **NO RESPONSE** | only bot-applied labels / no human reaction yet | [inductor] `binary_cross_entropy` with a weight of another dtype and `huber_loss` with mixed low-precision inp |
| 0913/16 | pytorch/pytorch #197099 | 2026-09-15 | open | **REPRODUCED** | chinmayirm root-caused the backward (2026-09-21); fix PR #197152 (“Fixes”) was closed unmerged on 2026-09-24 (re-checked 2026-09-25) | Backward of `F.pdist` on an input with zero rows crashes the process (SIGSEGV on Linux, integer division by ze |
| 0913/17 | pytorch/pytorch #197101 | 2026-09-15 | closed (completed) | **FIXED** | PR #197221 “Fixes #197101” landed as c8e4ab54e0 (2026-09-17); human-triaged by williamwen42 (`triaged`, `dynamo-triaged`) | [dynamo] `random.seed()` inside a compiled function is ignored on the first (compiling) call — first call retu |
| 0913/18 | pytorch/pytorch #197102 | 2026-09-15 | open | **NO RESPONSE** | only bot-applied labels / no human reaction yet | [dynamo] Python 3.14 + `dynamic=True`: `==` between namedtuples that hold tensors overflows the stack (Recursi |
| 0913/19 | pytorch/pytorch #197103 | 2026-09-15 | open | **NO RESPONSE** | only bot-applied labels / no human reaction yet | [inductor][cpu][windows] `max_autotune`: bmm C++ template kernel is not exported (`extern "C"` without `__decl |
| 0913/20 | pytorch/pytorch #197104 | 2026-09-15 | closed (completed) | **FIXED** | PR #197128 by maintainer yushangdi landed as bc77d149b7 (2026-09-16); issue was assigned to yushangdi | [aoti] `aoti_compile_and_package` fails for any model returning a `torch.return_types.*` named tuple (`torch.m |
| 0913/21 | pytorch/pytorch #197105 | 2026-09-15 | open | **REPRODUCED** | contributor N0AHZACH took it; fix PR #197193 open | [inductor] `torch.lerp(bool_tensor, bool_tensor, scalar_tensor_weight)` works in eager but fails to compile: " |
| 0913/22 | pytorch/pytorch #197106 | 2026-09-15 | open | **REPRODUCED** | contributor TANGBUDU reproduced it on f28a8c4796 with CPU vectorization and proposed a lowering fix using `any` for boolean sums (2026-09-22); no PR yet (re-checked 2026-09-25) | [inductor] `torch.sum(x_half, dtype=torch.bool)` fails with a C++ compile error and `torch.prod(x, dtype=torch |
| 0913/23 | pytorch/pytorch #197107 | 2026-09-15 | open | **REPRODUCED** | two volunteers; fix PR #197214 open | [inductor] `max_autotune`: `torch.addmm` with a 0-d (scalar) bias fails in `tuned_addmm` with `IndexError: lis |
| 0913/24 | pytorch/pytorch #197108 | 2026-09-15 | open | **REPRODUCED** | contributor he-yufeng root-caused it to the Welford lowering path; fix PR #197165 open | [inductor] `torch.var_mean` / `torch.std_mean` on an empty tensor return mean `0.` instead of `nan` under `tor |
| 0913/25 | pytorch/pytorch #197109 | 2026-09-15 | open | **CONFIRMED** | eellison (maintainer) diagnosed it (“This is due to the decomp not preserving channels last”), retitled it “[Fake Tensor/Decomps] …” and added `module: fakeTensor`, `module: decompositions` | [Fake Tensor/Decomps] `F.channel_shuffle` / `native_channel_shuffle` drop the channels_last memory format of t |
| 0913/26 | pytorch/pytorch #197110 | 2026-09-15 | closed (completed) | **CONFIRMED** | human-triaged by williamwen42, who told a volunteer “feel free to open a PR”; fix PR #197443 open | [dynamo] `str(KeyError(...))` inside a traced region omits the quotes CPython adds (`"'k'"` in eager, `'k'` co |
| 0913/27 | pytorch/pytorch #197112 | 2026-09-15 | open | **REPRODUCED** | DannyChee1 reproduced it on nightly 2.15.0.dev20260915 and traced it to `exact_dtype=True` on the `abs` ref (#140288) | [fake tensor] `torch.abs(complex, out=real_tensor_of_other_dtype)` is accepted by eager but rejected under tor |
| 0920/01 | pytorch/pytorch #197887 | 2026-09-21 | open | **REPRODUCED** | fix PR #198035 “[aot_autograd] Restore version checks for saved input views” open (“Fixes”); chinmayirm confirmed the `_reinterpret_tensor` / version-counter analysis | [inductor] Autograd's "modified by an inplace operation" check is lost when a view of a graph input is saved f |
| 0920/02 | pytorch/pytorch #197888 | 2026-09-21 | open | **CONFIRMED** | eellison added `high priority` and the issue was assigned to mlazos within a day; a volunteer offered a fix | `adaptive_max_pool3d_backward` and `fractional_max_pool{2,3}d_backward` read a non-contiguous `indices` tensor |
| 0920/02b | pytorch/pytorch #197889 | 2026-09-21 | open | **NO RESPONSE** | only bot-applied labels / no human reaction yet | [pt2] Python float argument that changes between calls goes stale in the cached graph (residual of #194976): n |
| 0920/07 | pytorch/pytorch #197893 | 2026-09-21 | open | **REPRODUCED** | chinmayirm confirmed the root cause in `joint_graph.remove_no_ops` (2026-09-21); wwoosshh reproduced a scatter variant on CUDA; fix PR #198446 “Preserve user-visible output aliasing” open (“Fixes”, re-checked 2026-09-25) | [inductor] `x + 0` / `x * 1` / `x / 1.0` as a graph output returns the input tensor itself (`out is x`), so an |
| 0920/08 | pytorch/pytorch #197894 | 2026-09-21 | open | **REPRODUCED** | fix PR #198053 “Fix FX codegen precedence for negative pow bases” open (“Fixes”, by buyan-kh); a second volunteer asked to be assigned | [fx] Generated code for `operator.pow(-2, x)` is `-2 ** x`, which Python evaluates as `-(2 ** x)`: `GraphModul |
| 0920/09 | pytorch/pytorch #197895 | 2026-09-21 | open | **REPRODUCED** | chinmayirm confirmed the `floor(div_rn(a, b))` analysis and volunteered | [inductor] Floating-point floor division is off by one: `torch.compile` makes `1.0 // 0.1` return `10.0` (eage |
| 0920/10 | pytorch/pytorch #197896 | 2026-09-21 | open | **CONFIRMED** | ezyang (core maintainer) added `actionable`; syerva-g posted a root-cause analysis and opened fix PR #198055 (“Fixes”; closed and reopened, open as of 2026-09-23) | [dynamo] Mutations of a closure-captured list/dict are silently dropped when they happen in a method of a loca |
| 0920/12 | pytorch/pytorch #198052 | 2026-09-21 | open | **NO RESPONSE** | only bot-applied labels / no human reaction yet | [dynamo][numpy] NumPy code under `torch.compile` returns wrong values: `np.fix` rounds instead of truncating,  |
| 0920/19 | pytorch/pytorch #198056 | 2026-09-21 | open | **NO RESPONSE** | only bot-applied labels / no human reaction yet | [dynamo][numpy] dtype and shape divergences of NumPy code under `torch.compile`: `np.cumsum(int8)` overflows i |
| 0920/13 | pytorch/pytorch #198057 | 2026-09-21 | open | **NO RESPONSE** | only bot-applied labels / no human reaction yet | [inductor][cpu] Vectorized `torch.remainder` / `%` returns NaN for an infinite divisor and 0 for large quotien |
| 0920/15 | pytorch/pytorch #198064 | 2026-09-22 | open | **NO RESPONSE** | only bot-applied labels / no human reaction yet | [dynamic shapes] `round(x.shape[0], -1)` is a no-op on SymInt (`SymInt.__round__` ignores a negative `ndigits` |
| 0920/16 | pytorch/pytorch #198070 | 2026-09-22 | open | **NO RESPONSE** | only bot-applied labels / no human reaction yet | [dynamic shapes] With `capture_scalar_outputs=True`, the NaN check `v != v` on `v = loss.item()` is folded to  |
| 0920/21 | pytorch/pytorch #198071 | 2026-09-22 | open | **NO RESPONSE** | only bot-applied labels / no human reaction yet | [inductor] `torch.clamp` with a Python bound outside the dtype's range wraps the bound: `clamp(int8_tensor, -1 |
| 0920/23 | pytorch/pytorch #198072 | 2026-09-22 | open | **NO RESPONSE** | only bot-applied labels / no human reaction yet | [fx] A `forward` parameter named `nan` or `inf` shadows the float constant that the generated code prints as t |
| 0920/26 | pytorch/pytorch #198077 | 2026-09-22 | open | **NO RESPONSE** | only bot-applied labels / no human reaction yet | [fx] A pickle / `torch.save` round trip silently changes what a `GraphModule` computes: in-place operator node |
| 0920/28 | pytorch/pytorch #198081 | 2026-09-22 | open | **REPRODUCED** | vikrambal located the cause in Inductor's `reduce_any` lowering, which bypasses `_refs.any` (2026-09-22); no PR yet (re-checked 2026-09-25) | [inductor] `torch.any` on a uint8 tensor returns bool under `torch.compile` (eager and `torch.all` keep uint8) |
| 0920/31 | pytorch/pytorch #198118 | 2026-09-22 | open | **NO RESPONSE** | only bot-applied labels / no human reaction yet | Complex `linalg.pinv` / `linalg.polar` / `linalg.matrix_sqrth` return wrong values under any `TorchDispatchMod |
| 0920/33 | pytorch/pytorch #198119 | 2026-09-22 | open | **NO RESPONSE** | only bot-applied labels / no human reaction yet | [inductor] `avg_pool1d/2d` backward with `ceil_mode=True` divides the overhanging last window by the full kern |
| 0920/34 | pytorch/pytorch #198133 | 2026-09-22 | open | **NO RESPONSE** | only bot-applied labels / no human reaction yet | [inductor][cpu] `torch.erfinv` loses accuracy near ±1 under `torch.compile`: relative error up to 7.5e-3 in fl |
| 0920/35 | pytorch/pytorch #198134 | 2026-09-22 | open | **NO RESPONSE** | only bot-applied labels / no human reaction yet | [inductor][cpu] Vectorized float64 `torch.acosh` returns `inf` for inputs above 1.34e154 under `torch.compile` |
| 0920/36 | pytorch/pytorch #198155 | 2026-09-22 | open | **REPRODUCED** | shyamsharmas124 opened draft PR #198316 covering 6 of the 134 operators (2026-09-23); contributor eellison argues compile need not mirror the eager restriction (re-checked 2026-09-25) | [inductor] 134 operators run under `torch.compile` on dtypes their eager kernels reject with `NotImplementedEr |
| 0920/39 | pytorch/pytorch #198183 | 2026-09-22 | open | **NO RESPONSE** | only bot-applied labels / no human reaction yet | [inductor][cpu] Vectorized float32 `torch.erf` loses all relative accuracy near 0 under `torch.compile` (retur |
| 0920/40 | pytorch/pytorch #198189 | 2026-09-22 | open | **REPRODUCED** | vikrambal root-caused it to `OrderedDictVariable.move_to_end` (2026-09-22); fix PR #198518 open (“Fixes”, re-checked 2026-09-25); frgossen applied `triaged` / `low priority` | [dynamo] `OrderedDict.move_to_end()` on a dict passed into a compiled function is silently dropped: the reorde |
| 0920/41 | pytorch/pytorch #198190 | 2026-09-22 | open | **REPRODUCED** | JEWEL169 analysed `LocalGeneratorObjectVariable` and argued it is a defect rather than a documented limitation (2026-09-22); no PR yet (re-checked 2026-09-25) | [dynamo] A generator that leaves a compiled region (returned, or alive across a graph break) comes back as an  |
| 0920/42 | pytorch/pytorch #198192 | 2026-09-22 | open | **NO RESPONSE** | only bot-applied labels / no human reaction yet | [dynamo] `IndexError` raised by a tensor op inside a compiled function skips the user's own `except IndexError |
| 0920/43 | pytorch/pytorch #198205 | 2026-09-22 | open | **NO RESPONSE** | only bot-applied labels / no human reaction yet | [aoti][windows] Destroying an AOTI runner right after a run crashes the process (access violation) whenever th |
| 0920/06 | numba/numba #10845 | 2026-09-21 | open | **NO RESPONSE** | only bot-applied labels / no human reaction yet | `np.remainder` / `np.mod` / `np.divmod` on signed integer arrays kill the process for `MIN_INT % -1` in nopyth |
| 0920/11 | jax-ml/jax #40840 | 2026-09-21 | open | **CONFIRMED** | JAX maintainer jakevdp self-assigned, thanked for the report and noted the same bug in NumPy (< 2.4.0 for gcd, still present for lcm in 2.5.3); fix PR #40842 open with a regression test | `jnp.gcd` / `jnp.lcm` never terminate when an argument is the minimum integer of its dtype (eager and jit) |
| 0920/03 | pytorch/pytorch | 2026-09-21 | open | **NO RESPONSE** | no reply yet | comment under #143649: https://github.com/pytorch/pytorch/issues/143649#issuecomment-5761796627 |
| 0920/04 | pytorch/pytorch | 2026-09-21 | open | **NO RESPONSE** | no reply yet | comment under #197554: https://github.com/pytorch/pytorch/issues/197554#issuecomment-5761854781 |
| 0920/05 | Microsoft Visual C++ | 2026-09-21 | open | **NO RESPONSE** | status: new | Developer Community 11155532: https://developercommunity.visualstudio.com/t/MSVC-x64-optimizer-folds-two-consecutive/11155532 |
| 0920/17 | Microsoft Visual C++ | 2026-09-21 | open | **NO RESPONSE** | status: new | Developer Community 11155535: https://developercommunity.visualstudio.com/t/MSVC-x64-optimizer-removes-_mm_add_psx/11155535 |
| 0920/18 | Microsoft Visual C++ | 2026-09-21 | open | **NO RESPONSE** | status: new | Developer Community 11155537: https://developercommunity.visualstudio.com/t/MSVC-x64-optimizer-folds-compare-and-ble/11155537 |
| 0920/14 | pytorch/pytorch | 2026-09-22 | open | **NO RESPONSE** | no reply yet | comment under #191499: https://github.com/pytorch/pytorch/issues/191499#issuecomment-5769459765 |
| 0920/20 | pytorch/pytorch | 2026-09-22 | open | **NO RESPONSE** | no reply yet; asked for reopen | comment under #185337 (closed): https://github.com/pytorch/pytorch/issues/185337#issuecomment-5769623200 |
| 0920/22 | pytorch/pytorch | 2026-09-22 | open | **NO RESPONSE** | no reply yet | second comment under #197554: https://github.com/pytorch/pytorch/issues/197554#issuecomment-5769650186 |
| 0920/24 | pytorch/pytorch | 2026-09-22 | open | **NO RESPONSE** | no reply yet; asked for reopen | comment under #174386 (closed): https://github.com/pytorch/pytorch/issues/174386#issuecomment-5769669193 |
| 0920/25 | pytorch/pytorch | 2026-09-22 | open | **NO RESPONSE** | supplement to own issue | comment under own #197889: https://github.com/pytorch/pytorch/issues/197889#issuecomment-5769751990 |
| 0920/27 | pytorch/pytorch | 2026-09-22 | open | **NO RESPONSE** | no reply yet | comment under #183607: https://github.com/pytorch/pytorch/issues/183607#issuecomment-5769757314 |
| 0920/29 | pytorch/pytorch | 2026-09-22 | open | **NO RESPONSE** | no reply yet | third comment under #197554: https://github.com/pytorch/pytorch/issues/197554#issuecomment-5770289099 |
| 0920/30 | pytorch/pytorch | 2026-09-22 | open | **NO RESPONSE** | supplement to own issue | comment under own #198071: https://github.com/pytorch/pytorch/issues/198071#issuecomment-5770296071 |
| 0920/32 | pytorch/pytorch | 2026-09-22 | open | **NO RESPONSE** | points to #198118 as the root cause | correction comment under own #197084: https://github.com/pytorch/pytorch/issues/197084#issuecomment-5770677350 |
| 0920/37 | pytorch/pytorch | 2026-09-22 | open | **NO RESPONSE** | supplement to own issue | comment under own #198155 (CUDA numbers): https://github.com/pytorch/pytorch/issues/198155#issuecomment-5773214257 |
| 0920/38 | pytorch/pytorch | 2026-09-22 | open | **NO RESPONSE** | supplement to own issue | comment under own #198118 (lstsq backward, FlopCounterMode): https://github.com/pytorch/pytorch/issues/198118#issuecomment-5773243640 |
| 0920/41b | pytorch/pytorch | 2026-09-22 | open | **NO RESPONSE** | supplement to own issue | comment under own #198190 (trigger condition, iterator family): https://github.com/pytorch/pytorch/issues/198190#issuecomment-5776320367 |
| 0920/42b | pytorch/pytorch | 2026-09-22 | open | **NO RESPONSE** | supplement to own issue | comment under own #198192 (handler shapes): https://github.com/pytorch/pytorch/issues/198192#issuecomment-5778031868 |
