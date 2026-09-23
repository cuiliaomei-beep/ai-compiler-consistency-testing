# Issue drafts (2026-09-10) — pytorch/pytorch

10 drafts, all against torch 2.14.0+cpu (git `08187d9e`, Windows 11, MSVC 19.44). Each file: submission info (link, template,
dedup query links, evidence bundle) + English **Title** and **Body** laid out along the target template, ready to paste.
**None has been filed; the user decides.** Dedup pass of 2026-09-10 (5 queries per item, GitHub search API): `results/dedup_0910.md`.

Files are numbered by suggested submission priority: root cause pinned to a line and no related report first, then value/crash
severity, then low-severity siblings of already-fixed reports.

| # | problem | template | dedup verdict | file |
|---|---|---|---|---|
| 01 | CPU Inductor `dynamic=True`: argmin/argmax index printed with Python `**` → C++ compile error (`cpp.py` 3749 / 256) | pt2-bug-report | no report | [01-argmin-pow-dynamic-cpp.md](01-argmin-pow-dynamic-cpp.md) |
| 02 | Windows `max_autotune`: bmm C++ template kernel not exported (`cpp_bmm_template.py` 44 lacks `{{export_declaration}}`) | pt2-bug-report | no report | [02-bmm-max-autotune-windows-export.md](02-bmm-max-autotune-windows-export.md) |
| 03 | `F.interpolate` on a 0-size spatial dim: Inductor returns NaN garbage (OOB read), eager raises | pt2-bug-report | no report (family: #193811, #195550) | [03-interpolate-zero-size-oob.md](03-interpolate-zero-size-oob.md) |
| 04 | `vector_norm(ord=inf, dim=-1)` on an empty batch fails at trace time (`_refs/linalg` checks the un-normalized negative dim; `dim=1` works) | pt2-bug-report | no report | [04-vector-norm-empty-batch.md](04-vector-norm-empty-batch.md) |
| 05 | `std`/`std_mean` fp32 accumulation: 1e30 → inf/NaN; 1e-30 → 0 **and zero gradient** | pt2-bug-report | related open #173793 (LayerNorm); std/var + gradient not reported | [05-std-var-fp32-accumulation-zero-grad.md](05-std-var-fp32-accumulation-zero-grad.md) |
| 06 | `var_mean`/`std_mean` on an empty tensor: Inductor mean `0.` instead of `nan` | pt2-bug-report | no report | [06-var-mean-empty-mean-zero.md](06-var-mean-empty-mean-zero.md) |
| 07 | **eager**: backward of `F.pdist` on zero rows crashes the process (SIGSEGV on Linux 2.10, int div-by-zero on Windows 2.14) | bug-report | no report | [07-pdist-backward-empty-crash.md](07-pdist-backward-empty-crash.md) |
| 08 | `binary_cross_entropy` bf16/fp16 + fp32 weight → Inductor float32 (sibling of fixed #171282) | pt2-bug-report | no report; sibling fixed | [08-bce-weight-dtype.md](08-bce-weight-dtype.md) |
| 09 | `channel_shuffle` drops channels_last under Inductor (family of fixed #187195 / #179272 / #179837) | pt2-bug-report | no report; family fixed | [09-channel-shuffle-channels-last.md](09-channel-shuffle-channels-last.md) |
| 10 | `max_autotune` + `addmm` 0-d bias → IndexError in `tuned_addmm` (`kernel/mm.py` 714) | pt2-bug-report | no report; same line as open PR #185578 — comment there is the alternative | [10-addmm-scalar-bias-max-autotune.md](10-addmm-scalar-bias-max-autotune.md) |
| 11 | `aoti_compile_and_package` fails for any model returning a `torch.return_types.*` named tuple | pt2-bug-report | no report; related open PR #113258 | [11-aoti-return-types-packaging.md](11-aoti-return-types-packaging.md) |
| 12 | export silently drops an in-place update of a lifted constant (instance_norm running stats as captured tensors); AOTI then INTERNAL ASSERTs | pt2-bug-report | no report; #150008 is the same assert class, different trigger | [12-export-lifted-constant-mutation.md](12-export-lifted-constant-mutation.md) |
| 13 | **CUDA**: `x.new_zeros(shape, device="cpu")` returns a CUDA tensor under `triton.cudagraphs` (eager / default config: CPU) — torch 2.14.0+cu130, T4 | pt2-bug-report | no report; family of open PR #190555 (cross-device fallbacks in cudagraphs) | [13-cudagraphs-new-zeros-cpu-device.md](13-cudagraphs-new-zeros-cpu-device.md) |
| 14 | **Dynamo**: `random.shuffle` / `random.sample` inside a compiled function return the same result on every call (eager advances the RNG); global RNG state diverges too — 2.14 + nightly, Windows + Linux | pt2-bug-report | no report; related open #196437 (random.Random + dynamic), PR #188083 (merged, seed routing) | [14-dynamo-random-shuffle-sample-frozen.md](14-dynamo-random-shuffle-sample-frozen.md) |
| 15 | **Dynamo**: `random.seed(k)` inside a compiled function is ignored on the first (compiling) call — 2.14 + nightly, Windows + Linux | pt2-bug-report | no report (can be merged into 14) | [15-dynamo-random-seed-first-call.md](15-dynamo-random-seed-first-call.md) |
| 16 | **Dynamo** `dynamic=True`: f-string with a format spec on a SymInt/SymFloat → `InternalTorchDynamoError: Unknown format code 'd' for object of type 'str'` — 2.14 + nightly, Windows (Py3.14) + Linux (Py3.11) | pt2-bug-report | no report | [16-dynamo-dynamic-fstring-format-spec.md](16-dynamo-dynamic-fstring-format-spec.md) |
| 17 | **Dynamo** `dynamic=True` + **Python 3.14**: `==` between namedtuples holding tensors → RecursionError (eager: True / RuntimeError); Python 3.11 Linux not affected | pt2-bug-report | no report | [17-dynamo-dynamic-namedtuple-eq-recursion.md](17-dynamo-dynamic-namedtuple-eq-recursion.md) |
| 18 | **Inductor**: `torch.ldexp` output dtype differs from eager in both directions (int/bool×half→fp32, half×fp32→half); aot_eager agrees with eager; CPU + CUDA, 2.14 + nightly | pt2-bug-report | no report; source PR #171721 (native ldexp lowering) | [18-inductor-ldexp-output-dtype.md](18-inductor-ldexp-output-dtype.md) |
| 19 | `F.huber_loss(fp16, fp32)` → Inductor float32, eager float16 — same mechanism as 08, **added to draft 08** as a second op | — | see 08 | [08-bce-weight-dtype.md](08-bce-weight-dtype.md) |
| 20 | **Inductor**: `torch.lerp(bool, bool, 0-d float weight)` works in eager (float result), fails to compile (`Subtraction ... two bool tensors is not supported`); CPU + CUDA | pt2-bug-report | no report | [20-inductor-lerp-bool-scalar-weight.md](20-inductor-lerp-bool-scalar-weight.md) |
| 21 | **Inductor CPU**: `torch.sum(half, dtype=torch.bool)` C++ compile error; `torch.prod(x, dtype=torch.bool)` AssertionError `expected reduction_type in (min, max, any, sum)`; eager returns bool — Windows/MSVC + Linux/g++, 2.14 + nightly | pt2-bug-report | no report | [21-inductor-sum-prod-dtype-bool.md](21-inductor-sum-prod-dtype-bool.md) |
| 22 | **Dynamo**: `str(KeyError(...))` inside a fully traced function drops CPython's repr-quoting (`"'k'"` eager vs `'k'` compiled) — 2.14 + nightly | pt2-bug-report | no report | [22-dynamo-keyerror-str-quotes.md](22-dynamo-keyerror-str-quotes.md) |
| 23 | **Inductor**: `torch.compile(opt.step)` for SGD + `foreach=True` + complex params → `AssertionError: <built-in function getitem> is not an OpOverload`; eager/aot_eager fine; other optimizers fine — 2.14 + nightly | pt2-bug-report | no report; unmerged PR #178192 touches the same assertion | [23-inductor-compiled-sgd-foreach-complex.md](23-inductor-compiled-sgd-foreach-complex.md) |
| 24 | **AOTAutograd**: gradients of `torch.linalg.pinv` and `linalg.matrix_sqrth` for complex inputs are wrong under compile (aot_eager + inductor; gradcheck fails), eager / functorch / Dynamo-only correct; real input fine; other complex linalg grads fine — 2.14 + nightly | pt2-bug-report | no report; related open #184101 is a different (Inductor stride) complex-backward bug | [24-aot-pinv-complex-gradient-wrong.md](24-aot-pinv-complex-gradient-wrong.md) |
| 25 | **compiled autograd**: backward of `F.interpolate` in bilinear/bicubic/linear/trilinear modes → `isIntList() INTERNAL ASSERT` in the meta of `upsample_*_backward`; nearest/area fine; eager backward fine — 2.14 + nightly | pt2-bug-report | no report | [25-compiled-autograd-interpolate-isintlist.md](25-compiled-autograd-interpolate-isintlist.md) |
| 26 | Inductor evaluates `bitwise_not/and/or/xor` on float tensors (eager + aot_eager raise NotImplementedError) and returns bit-pattern garbage — 2.14 + nightly, Win + Linux | — | **partial duplicate of open #144247** (and/or/xor; says bitwise_not unaffected — now it is; fix PR #186016 closed unmerged) → comment there, no new issue | `scripts/diag_bitwise_float.py` |
| 27 | **AOTAutograd**: `compile(jvp(ldexp), backend="aot_eager")` crashes the process (0xC0000005); eager jvp, Dynamo-only, inductor fine — 2.14 + nightly | pt2-bug-report | no report | [27-aot-jvp-ldexp-access-violation.md](27-aot-jvp-ldexp-access-violation.md) |
| 28 | **Dynamo**: `jvp` inside compile → `_make_dual` INTERNAL ASSERT for `quantile(a, q_tensor)` (all backends) and `addr` / `quantile` / `nanquantile` (backend=eager) — 2.14 + nightly | pt2-bug-report | no report | [28-dynamo-jvp-make-dual-internal-assert.md](28-dynamo-jvp-make-dual-internal-assert.md) |
| 29 | Inductor fails to compile `nan_to_num(complex)` (`Complex dtype is not supported for isneginf`); eager/aot_eager fine | — | **duplicate of open #190275** (and closed #147109) → optional comment | `scripts/diag_unary_out_complex.py` |
| 30 | compile rejects `abs(complex64, out=float64/bfloat16)` that eager accepts (meta out-dtype check stricter than eager); `out=float32` and `angle(..., out=float64)` fine — 2.14 + nightly | pt2-bug-report (low) | no report | `scripts/diag_unary_out_complex.py` (no separate draft yet) |

Cross-platform status (2026-09-11, `tcc-gpuverify` v3 on Kaggle: torch 2.14.0+cu130, Tesla T4 + Linux CPU): 03/04/06/10 also reproduce on CUDA; 01 also fails under GCC (Linux CPU) and is fine on Triton; 05/08/09 are CPU-only (CUDA eager agrees with Inductor); 07 is a CPU-kernel crash (CUDA fine); 02 is Windows-only; 11/12 reproduce on Linux. Each draft carries the corresponding sentence.

Second round (2026-09-12 evening, NEXT_DIRECTIONS §6): drafts 14–21 come from the Dynamo python-semantics differential (`tcc/dynamo_semantics.py`) and the dtype-promotion matrix (`tcc/dtype_matrix.py`); evidence in `results/dynsem*`, `results/dtypes_aot`, `kaggle_out/dtypesgpu`, `kaggle_out/randomlinux.txt`, `kaggle_out/leadslinux.txt`; dedup in `results/dedup_0912.txt`. Nothing filed.

Nightly status (2026-09-12, `tcc-nightlygpu` on Kaggle: torch 2.15.0.dev20260911+cu130, git fb8ff0f1, Tesla T4 + Linux CPU; log `kaggle_out/nightlygpu.txt`): **all 13 still reproduce on `main`** with the same outcomes as on 2.14.0 (01 GCC compile error, 03/04/06/10 CPU+CUDA, 05/08/09 CPU-only, 07 SIGSEGV on CPU, 11/12 CPU+CUDA, 13 cudagraphs). 02 is Windows-only and reproduces on the Windows nightly wheel (2.15.0.dev20260911+cpu, MSVC; `cpp_bmm_template.py` on `main` still lacks `{{export_declaration}}`). The same Windows nightly (`../venv_nightly`, `results/nightly_verify_windows.txt`) also reproduces 01/03–12 with identical outcomes (07 exits with 0xC0000094). Each draft carries a "Still present on nightly" sentence. Nothing has been filed.

Submit links: torch.compile issues → https://github.com/pytorch/pytorch/issues/new?template=pt2-bug-report.yml ;
plain bug (07) → https://github.com/pytorch/pytorch/issues/new?template=bug-report.yml .

## Not filed as new issues — comment drafts for existing threads

**#70398** (open) `torch.broadcast_to` can create tensor with negative dimension — our 0-d `expand(-1, ...)` finding is the same
missing check (evidence: `reports_decomp/expand_neg_dim/`). Comment:

> Still reproduces on 2.14.0, and there is a second entry point: for a **0-dim** source, `-1` in a *new* leading dimension is
> accepted too, although the 1-dim source correctly raises.
> ```python
> torch.tensor(1.5).expand(-1, 5, 5).shape   # torch.Size([-1, 5, 5]); numel() == -25; .clone() raises
> torch.tensor(1.5).expand(-1).shape         # torch.Size([-1])
> torch.tensor([1.5]).expand(-1, 5)          # RuntimeError: The expanded size of the tensor (-1) isn't allowed in a leading, non-existing dimension 0  (correct)
> ```
> `torch.compile` (aot_eager / inductor) rejects both with "Trying to create tensor with negative dimension -1", so the fake-tensor
> path already has the check that eager's `inferExpandGeometry` skips when the source has no dims.

**#175154** (open, high priority) interpolate under torch.compile produces incorrect result when mode is `nearest` — our
binding-form rebind check hit the same shortcut with `bilinear` (evidence: `scripts/confirm_interp_scale.py`). Comment:

> On 2.14.0+cpu the same divergence also shows for `mode="bilinear"`, not only `nearest`: with `x = torch.randn(1, 2, 4, 6)` and
> `scale_factor=1.15` (output size equals input size after flooring), `F.interpolate(x, scale_factor=1.15, mode="bilinear")`
> differs between eager and `torch.compile` by up to 2.7 (nearest: 3.6); `nearest-exact` and `bicubic` agree, and the 1-D
> case agrees. So whatever fix lands for the nearest shortcut should cover the linear path as well.

**#185533 / PR #185578** (open) addmm max-autotune SliceView bias guard — alternative to draft 10:

> A related crash on the same line (`kernel/mm.py` `tuned_addmm`, `inp.get_stride()[0] == 0 and len(inp.get_size()) == 2`):
> with a **0-d** bias `get_stride()` is `()` and the `[0]` raises `IndexError: list index out of range` under `max_autotune`
> (`torch.compile(lambda b, x, y: torch.addmm(b, x, y))(torch.tensor(0.5), torch.randn(2, 2), torch.randn(2, 3))`, 2.14.0).
> `maybe_get_stride()` alone would not cover it; checking `len(inp.get_size()) == 2` before indexing the stride does.

## Recorded but not worth a report (see `TO_SUBMIT.md` bottom table)

index_reduce out-of-range index (#186532 / #185977 family) · ~40 ops accepting int64/bool inputs that eager rejects (#144362) ·
`native_batch_norm` N=1 ZeroDivisionError (legacy op) · NaN-propagation differences in `multilabel_margin_loss` /
`hardswish` / `smooth_l1_loss` gradients · `max_pool2d` indices for an all-padding window · `pixel_unshuffle` empty batch (eager
bug, dup #192816) · `linalg.eigvals` NaN → MKL abort (eager, #93124 closed but reproduces, #185247 open).
