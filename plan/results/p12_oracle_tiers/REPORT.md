# P1-2 Oracle-tier analysis over independent real root causes

Generated 2026-09-25 17:55 on win32, torch 2.14.0+cpu, Python 3.14.7 (CPU only; the machine that produced the drafts).

## Method

* **Unit of analysis.** The 73 report items of `paper_tcc/data/findings.csv` minus the 5 cross-compiler items (C6, C7, C12, C18, C19) and the 10 items attributed outside the pipeline (B1, B16, C2, C4, C9, C24, C27, C32, C33, C39) leave 58 pipeline-attributed items. Comments were merged into their parent issue (C26->C3, C31->C22, C30/C38->C37, C43->C42, C45->C44) and no other pair shares a root cause according to the ledger (B2 and B17 have different fix PRs, #197768 vs #197221; drafts 20 and 27 argue different mechanisms for C21 and C28). Result: **52 root causes** (`root_causes.csv`). Comments filed under issues owned by others (C15, C21, C25, C28) are root causes of their own that we contributed to.
* **Reproducer.** The first ```python block of each issue draft, re-expressed as (fn, args) in `scripts/oracle_tiers_cases.py`; the draft's list of triggering programs becomes the root cause's sub-cases, the first (minimal trigger) is marked *primary*. Compilation follows the draft (backend, dynamic, fullgraph, Inductor/Dynamo config, compiled autograd, optimizer step, export + AOTInductor).
* **One execution per side.** `scripts/oracle_tiers_real.py run` executes every sub-case once in eager and once compiled, each in its own child process with a fresh Inductor cache, and stores one trace (`traces/*.json`) holding all observables: return value (tensors serialized with values, dtype, shape, stride, device, contiguity, storage offset, is_view), the storage-sharing relation over inputs and outputs (tcc.observe.alias_relation), inputs and module-level state after the call, gradients (tcc.observe._gradients when the draft computes them), exception type / inner type / whether the program's own handler caught it, process exit code and exit phase (died during the call vs after it), a float64 re-execution of the same eager call and, for the accuracy findings, an mpmath 30-digit reference.
* **Tiers, evaluated offline from the same trace** (`evaluate()`): T1 = `tcc.oracle._o1_value` without reference (dtype-aware tolerance) + compiled raises where eager returned + process death during the compiled call; T2 = T1 + `_o2_metadata` with `strict_stride=True` (shape, dtype, device, stride, output structure); T3 = T2 + `_o5_alias`, opaque-object identity, `_o4_mutation` on tensor inputs, exact comparison of non-tensor inputs and module-level state, `_o6_gradient`, exception routing (eager raises / compiled returns, exception-type parity, handler parity), the float64 rule of `_o1_value(fp64=...)` plus the relative criterion of `scripts/special_vs_mpmath.py` (compiled rel. err > 1e-6 and > 100 x max(eager rel. err, eps/4)), and process survival (death after the call or on the eager side). A root cause is detected at a tier when any of its sub-cases is; *primary-only* numbers use the minimal trigger alone.

## Results over the root causes

| | T1 | T2 (cum.) | T3 (cum.) | not detected / not reproducible here |
|---|---|---|---|---|
| all sub-cases (51 root causes reproduced) | 36 | 38 | 51 | 1 |
| primary sub-case only | 34 | 38 | 51 | |

Weakest detecting tier (all sub-cases): T1: 36, T2: 2, T3: 13; primary only: T1: 34, T2: 4, T3: 13.

Unique to a tier (all sub-cases): T2 adds ['B15', 'B25']; T3 adds ['B12', 'B18', 'C1', 'C11', 'C22', 'C23', 'C34', 'C37', 'C40', 'C41', 'C46', 'C5', 'C8'].  Primary only: T2 adds ['B15', 'B25', 'B8', 'C29']; T3 adds ['B12', 'B18', 'C1', 'C11', 'C22', 'C23', 'C34', 'C37', 'C40', 'C41', 'C46', 'C5', 'C8'].

Detected at T1: B10, B11, B13, B14, B17, B19, B2, B20, B21, B22, B23, B24, B26, B27, B3, B4, B6, B7, B8, B9, C10, C13, C14, C15, C16, C17, C20, C21, C25, C28, C29, C3, C35, C36, C42, C44

Detected only from T2: B15, B25

Detected only from T3: B12, B18, C1, C11, C22, C23, C34, C37, C40, C41, C46, C5, C8

### Per root cause

| RC | members | layer | status | T1 | T2 | T3 | weakest (all) | observable | weakest (primary) | observable (primary) | sub-cases run |
|---|---|---|---|---|---|---|---|---|---|---|---|
| B2 | B2 | Dy | fixed | 1 | 1 | 1 | T1 | value | T1 | value | 2/2 |
| B3 | B3 | AOT | pending | 1 | 1 | 1 | T1 | crash | T1 | crash | 1/1 |
| B4 | B4 | In | confirmed | 1 | 1 | 1 | T1 | exception | T1 | exception | 1/1 |
| B5 | B5 | In | confirmed |  |  |  |  |  |  |  | 0/1 |
| B6 | B6 | In | pending | 1 | 1 | 1 | T1 | value | T1 | value | 2/2 |
| B7 | B7 | Dy | pending | 1 | 1 | 1 | T1 | exception | T1 | exception | 3/3 |
| B8 | B8 | In | fixed | 1 | 1 | 1 | T1 | value | T2 | metadata | 5/5 |
| B9 | B9 | AOT | pending | 1 | 1 | 1 | T1 | exception | T1 | exception | 1/1 |
| B10 | B10 | Dy | confirmed | 1 | 1 | 1 | T1 | exception | T1 | exception | 1/1 |
| B11 | B11 | In | confirmed | 1 | 1 | 1 | T1 | exception | T1 | exception | 1/1 |
| B12 | B12 | De | confirmed | 0 | 0 | 1 | T3 | exception-routing | T3 | exception-routing | 1/1 |
| B13 | B13 | Ex | rejected | 1 | 1 | 1 | T1 | exception | T1 | exception | 1/1 |
| B14 | B14 | De | fixed | 1 | 1 | 1 | T1 | exception | T1 | exception | 1/1 |
| B15 | B15 | In | pending | 0 | 1 | 1 | T2 | metadata | T2 | metadata | 1/1 |
| B17 | B17 | Dy | fixed | 1 | 1 | 1 | T1 | value | T1 | value | 1/1 |
| B18 | B18 | Dy | pending | 0 | 0 | 1 | T3 | exception-type | T3 | exception-type | 1/1 |
| B19 | B19 | In | pending | 1 | 1 | 1 | T1 | exception | T1 | exception | 1/1 |
| B20 | B20 | Ex | fixed | 1 | 1 | 1 | T1 | exception | T1 | exception | 1/1 |
| B21 | B21 | De | fixed | 1 | 1 | 1 | T1 | exception | T1 | exception | 1/1 |
| B22 | B22 | In | pending | 1 | 1 | 1 | T1 | exception | T1 | exception | 2/2 |
| B23 | B23 | In | fixed | 1 | 1 | 1 | T1 | exception | T1 | exception | 1/1 |
| B24 | B24 | In | fixed | 1 | 1 | 1 | T1 | value | T1 | value | 2/2 |
| B25 | B25 | In | confirmed | 0 | 1 | 1 | T2 | metadata | T2 | metadata | 1/1 |
| B26 | B26 | Dy | fixed | 1 | 1 | 1 | T1 | value | T1 | value | 1/1 |
| B27 | B27 | De | confirmed | 1 | 1 | 1 | T1 | exception | T1 | exception | 1/1 |
| C1 | C1 | AOT | fixed | 0 | 0 | 1 | T3 | exception-routing | T3 | exception-routing | 1/1 |
| C3 | C3;C26 | Dy | pending | 1 | 1 | 1 | T1 | value | T1 | value | 5/5 |
| C5 | C5 | De | pending | 0 | 0 | 1 | T3 | exception-routing | T3 | exception-routing | 10/10 |
| C8 | C8 | In | confirmed | 0 | 0 | 1 | T3 | alias | T3 | alias | 3/3 |
| C10 | C10 | In | confirmed | 1 | 1 | 1 | T1 | value | T1 | value | 2/2 |
| C11 | C11 | Dy | fixed | 0 | 0 | 1 | T3 | state | T3 | state | 4/4 |
| C13 | C13 | Dy | pending | 1 | 1 | 1 | T1 | value | T1 | value | 6/6 |
| C14 | C14 | In | pending | 1 | 1 | 1 | T1 | value | T1 | value | 1/1 |
| C15 | C15 | In | pending | 1 | 1 | 1 | T1 | value | T1 | value | 4/4 |
| C16 | C16 | Dy | pending | 1 | 1 | 1 | T1 | value | T1 | value | 2/2 |
| C17 | C17 | Dy | pending | 1 | 1 | 1 | T1 | value | T1 | value | 2/2 |
| C20 | C20 | Dy | pending | 1 | 1 | 1 | T1 | exception;value | T1 | value | 5/5 |
| C21 | C21 | In | pending | 1 | 1 | 1 | T1 | value | T1 | value | 2/2 |
| C22 | C22;C31 | In | pending | 0 | 0 | 1 | T3 | exception-routing | T3 | exception-routing | 4/4 |
| C23 | C23 | In | pending | 0 | 0 | 1 | T3 | exception-routing | T3 | exception-routing | 3/3 |
| C25 | C25 | In | pending | 1 | 1 | 1 | T1 | value | T1 | value | 2/2 |
| C28 | C28 | In | pending | 1 | 1 | 1 | T1 | value | T1 | value | 1/1 |
| C29 | C29 | In | pending | 1 | 1 | 1 | T1 | value | T2 | metadata | 3/3 |
| C34 | C34 | In | pending | 0 | 0 | 1 | T3 | gradient | T3 | gradient | 2/2 |
| C35 | C35 | In | pending | 1 | 1 | 1 | T1 | value | T1 | value | 2/2 |
| C36 | C36 | In | pending | 1 | 1 | 1 | T1 | value | T1 | value | 2/2 |
| C37 | C37;C30;C38 | In | pending | 0 | 0 | 1 | T3 | exception-routing | T3 | exception-routing | 14/14 |
| C40 | C40 | In | pending | 0 | 0 | 1 | T3 | reference | T3 | reference | 2/2 |
| C41 | C41 | Dy | pending | 0 | 0 | 1 | T3 | state | T3 | state | 2/2 |
| C42 | C42;C43 | Dy | pending | 1 | 1 | 1 | T1 | value | T1 | value | 3/3 |
| C44 | C44;C45 | Dy | pending | 1 | 1 | 1 | T1 | exception | T1 | exception | 5/5 |
| C46 | C46 | Ex | pending | 0 | 0 | 1 | T3 | process | T3 | process | 1/1 |

### Per sub-case

| RC | sub-case | primary | weakest | observables | eager exc | compiled exc | compiled exit | first finding |
|---|---|---|---|---|---|---|---|---|
| B2 | shuffle | 1 | T1 | value |  |  | 0x0/exit | call1 output[0]: /ref-test/ = 2.000e+00 exceeds dtype-aware tolerance 3.100e-03 (no fp64 reference) |
| B2 | sample | 0 | T1 | value |  |  | 0x0/exit | call1 output[0]: /ref-test/ = 9.000e+00 exceeds dtype-aware tolerance 5.010e-02 (no fp64 reference) |
| B3 | jvp_ldexp | 1 | T1 | crash |  |  | 0xc0000005/start | process died during the compiled call (exit 0xc0000005, timed_out=False); eager completed 1 call(s) |
| B4 | argmin_dynamic | 1 | T1 | exception |  | InductorError | 0x0/exit |  compiled raised InductorError (CppCompileError: C++ compile error

Command:
cl /I C:/Users/clm/AppData/Local/Python/pythoncore-3.14-64/Include /I C:/Us), eager returned |
| B6 | std_1e30 | 1 | T1 | value |  |  | 0x0/exit |  output[0]: NaN/Inf present on one side only |
| B6 | std_1e-30_grad | 0 | T3 | gradient;reference |  |  | 0x0/exit |  grad[0]: compiled err vs fp64 = 3.250e-01 exceeds 8.0x eager err 1.578e-08 |
| B7 | draft_block_verbatim | 1 | T1 | exception |  | RuntimeError | 0x0/exit |  compiled raised RuntimeError (InferenceMode::is_enabled() && primal.is_inference() && tangent.is_inference() INTERNAL ASSERT FAILED at "C:\\actions-ru), eager returned |
| B7 | jvp_quantile_eager_backend | 0 | none |  |  |  | 0x0/exit |  |
| B7 | jvp_quantile_aot_eager | 0 | none |  |  |  | 0x0/exit |  |
| B8 | bool_x_fp16 | 1 | T2 | metadata |  |  | 0x0/exit |  output[0].dtype: torch.float16 vs torch.float32 |
| B8 | int64_x_bf16 | 0 | T2 | metadata |  |  | 0x0/exit |  output[0].dtype: torch.bfloat16 vs torch.float32 |
| B8 | fp16_x_fp32 | 0 | T2 | metadata |  |  | 0x0/exit |  output[0].dtype: torch.float32 vs torch.float16 |
| B8 | fp16_x_bf16 | 0 | T1 | value |  |  | 0x0/exit |  output[0]: /ref-test/ = 7.660e-03 exceeds dtype-aware tolerance 4.076e-03 (no fp64 reference) |
| B8 | bf16_x_fp64 | 0 | T1 | value |  |  | 0x0/exit |  output[0]: /ref-test/ = 3.437e-03 exceeds dtype-aware tolerance 1.736e-03 (no fp64 reference) |
| B9 | compiled_autograd_interpolate | 1 | T1 | exception |  | TorchRuntimeError | 0x0/exit |  compiled raised TorchRuntimeError (RuntimeError when making fake tensor call
  Explanation: Dynamo failed to run FX node with fake tensors: call_function t), eager returned |
| B10 | fstring_d | 1 | T1 | exception |  | InternalTorchDynamoError | 0x0/exit |  compiled raised InternalTorchDynamoError (ValueError: Unknown format code 'd' for object of type 'str'

from user code:
   File "D:\wsl\personal\dr\paper\toxic_co), eager returned |
| B11 | sgd_foreach_complex | 1 | T1 | exception |  | InductorError | 0x0/exit |  compiled raised InductorError (AssertionError: <built-in function getitem> is not an OpOverload

Set TORCHDYNAMO_VERBOSE=1 for the internal stack trace), eager returned |
| B12 | interpolate_empty | 1 | T3 | exception-routing | RuntimeError |  | 0x0/exit |  eager raised RuntimeError (Input and output sizes should be greater than 0, but got input (W: 0) and output (W: 3)), compiled returned |
| B13 | aoti_lifted_constant_mutation | 1 | T1 | exception |  | RuntimeError | 0x0/exit |  compiled raised RuntimeError (false INTERNAL ASSERT FAILED at "C:\\actions-runner\\_work\\pytorch\\pytorch\\build\\aten\\src\\ATen\\RegisterFunctional), eager returned |
| B14 | vector_norm_inf_empty | 1 | T1 | exception |  | TorchRuntimeError | 0x0/exit |  compiled raised TorchRuntimeError (RuntimeError when making fake tensor call
  Explanation: Dynamo failed to run FX node with fake tensors: call_function <), eager returned |
| B15 | bce_weight_fp32 | 1 | T2 | metadata |  |  | 0x0/exit |  output[0].dtype: torch.bfloat16 vs torch.float32 |
| B17 | seed_inside | 1 | T1 | value |  |  | 0x0/exit | call0 output[0]: /ref-test/ = 5.869e-02 exceeds dtype-aware tolerance 9.444e-04 (no fp64 reference) |
| B18 | namedtuple_eq | 1 | T3 | exception-type | RuntimeError | RecursionError | 0x0/exit |  exception type differs: eager RuntimeError/RuntimeError vs compiled RecursionError/RecursionError |
| B19 | bmm_max_autotune | 1 | T1 | exception |  | InductorError | 0x0/exit |  compiled raised InductorError (LoweringException: AttributeError: function 'cpp_CppMicroGemmFP32Vec' not found
  target: aten.bmm.default
  args[0]: Te), eager returned |
| B20 | aoti_return_types_max | 1 | T1 | exception |  | NotImplementedError | 0x0/exit |  compiled raised NotImplementedError (No registered serialization name for <class 'torch.return_types.max'> found. Please update your _register_pytree_node ca), eager returned |
| B21 | lerp_bool | 1 | T1 | exception |  | BackendCompilerFailed | 0x0/exit |  compiled raised BackendCompilerFailed (backend='inductor' raised:
NotImplementedError: Subtraction, the `-` operator, with two bool tensors is not supported. U), eager returned |
| B22 | sum_half_dtype_bool | 1 | T1 | exception |  | InductorError | 0x0/exit |  compiled raised InductorError (CppCompileError: C++ compile error

Command:
cl /I C:/Users/clm/AppData/Local/Python/pythoncore-3.14-64/Include /I C:/Us), eager returned |
| B22 | prod_dtype_bool | 0 | T1 | exception |  | InductorError | 0x0/exit |  compiled raised InductorError (AssertionError: expected reduction_type in ("min", "max", "any", "sum")

Set TORCHDYNAMO_VERBOSE=1 for the internal stac), eager returned |
| B23 | addmm_0d_bias | 1 | T1 | exception |  | InductorError | 0x0/exit |  compiled raised InductorError (LoweringException: IndexError: list index out of range
  target: aten.addmm.default
  args[0]: TensorBox(StorageBox(
   ), eager returned |
| B24 | var_mean_empty | 1 | T1 | value |  |  | 0x0/exit |  output[1]: NaN/Inf present on one side only |
| B24 | std_mean_empty | 0 | T1 | value |  |  | 0x0/exit |  output[1]: NaN/Inf present on one side only |
| B25 | channel_shuffle_chlast | 1 | T2 | metadata |  |  | 0x0/exit |  output[0].stride: (384, 1, 48, 6) vs (384, 64, 8, 1) |
| B26 | keyerror_str | 1 | T1 | value |  |  | 0x0/exit |  output[1]: non-float values differ exactly |
| B27 | abs_complex_out_f64 | 1 | T1 | exception |  | TorchRuntimeError | 0x0/exit |  compiled raised TorchRuntimeError (RuntimeError when making fake tensor call
  Explanation: Dynamo failed to run FX node with fake tensors: call_function <), eager returned |
| C1 | saved_view_mutated_before_backward | 1 | T3 | exception-routing | RuntimeError |  | 0x0/exit |  eager raised RuntimeError (one of the variables needed for gradient computation has been modified by an inplace operation: [tor), compiled returned |
| C3 | rms_norm_eps | 1 | T1 | value |  |  | 0x0/exit | call2 output[0]: /ref-test/ = 2.175e-01 exceeds dtype-aware tolerance 1.005e-03 (no fp64 reference) |
| C3 | huber_delta | 0 | T1 | value |  |  | 0x0/exit | call2 output[0]: /ref-test/ = 1.196e-01 exceeds dtype-aware tolerance 3.511e-04 (no fp64 reference) |
| C3 | interpolate_scale | 0 | T1 | value |  |  | 0x0/exit | call2 output[0]: values differ (not numerically comparable) |
| C3 | C26_cumsum_dim_from_float | 0 | T1 | value |  |  | 0x0/exit | call2 output[0]: /ref-test/ = 1.794e+00 exceeds dtype-aware tolerance 1.285e-03 (no fp64 reference) |
| C3 | C26_round_decimals_from_float | 0 | T1 | value |  |  | 0x0/exit | call2 output[0]: /ref-test/ = 5.000e-02 exceeds dtype-aware tolerance 1.000e-03 (no fp64 reference) |
| C5 | index_add_shape_mismatch | 1 | T3 | exception-routing | RuntimeError |  | 0x0/exit |  eager raised RuntimeError (source tensor shape must match self tensor shape, excluding the specified dimension. Got self.shape ), compiled returned |
| C5 | index_copy_negative_index | 0 | T3 | exception-routing | IndexError |  | 0x0/exit |  eager raised IndexError (index_copy_(): index -1 is out of bounds for dimension 0 with size 4), compiled returned |
| C5 | bce_input_gt_1 | 0 | T3 | exception-routing | RuntimeError |  | 0x0/exit |  eager raised RuntimeError (all elements of input should be between 0 and 1), compiled returned |
| C5 | repeat_interleave_wrong_output_size | 0 | T3 | exception-routing | RuntimeError |  | 0x0/exit |  eager raised RuntimeError (allocated size does not match required size), compiled returned |
| C5 | softmax_int64 | 0 | T3 | exception-routing | NotImplementedError |  | 0x0/exit |  eager raised NotImplementedError ("softmax_lastdim_kernel_impl" not implemented for 'Long'), compiled returned |
| C5 | layer_norm_f64_weight | 0 | T3 | exception-routing | RuntimeError |  | 0x0/exit |  eager raised RuntimeError (mixed dtype (CPU): expect parameter to have scalar type of Float), compiled returned |
| C5 | one_hot_float | 0 | T3 | exception-routing | RuntimeError |  | 0x0/exit |  eager raised RuntimeError (one_hot is only applicable to index tensor of type LongTensor.), compiled returned |
| C5 | int64_mul__float | 0 | T3 | exception-routing | RuntimeError |  | 0x0/exit |  eager raised RuntimeError (result type Float can't be cast to the desired output type Long), compiled returned |
| C5 | float_add__1j | 0 | T3 | exception-routing | RuntimeError |  | 0x0/exit |  eager raised RuntimeError (result type ComplexFloat can't be cast to the desired output type Float), compiled returned |
| C5 | take_out_overlapping | 0 | T3 | exception-routing | RuntimeError |  | 0x0/exit |  eager raised RuntimeError (unsupported operation: some elements of the input tensor and the written-to tensor refer to a single), compiled returned |
| C8 | logits_div_1.0 | 1 | T3 | alias |  |  | 0x0/exit |  storage-sharing relation changed: gained [(0, 2)] (indices < 2 are inputs, >= 2 outputs) |
| C8 | buf_mul_1.0 | 0 | T3 | alias |  |  | 0x0/exit |  storage-sharing relation changed: gained [(0, 2)] (indices < 2 are inputs, >= 2 outputs) |
| C8 | x_add_0 | 0 | T3 | alias |  |  | 0x0/exit |  storage-sharing relation changed: gained [(0, 2)] (indices < 2 are inputs, >= 2 outputs) |
| C10 | f32_floordiv | 1 | T1 | value |  |  | 0x0/exit |  output[0]: /ref-test/ = 1.000e+00 exceeds dtype-aware tolerance 2.910e-02 (no fp64 reference) |
| C10 | f64_div_floor | 0 | T1 | value |  |  | 0x0/exit |  output[0]: /ref-test/ = 1.000e+00 exceeds dtype-aware tolerance 2.910e-02 (no fp64 reference) |
| C11 | dict_+= | 1 | T3 | state |  |  | 0x0/exit | call0 state["n"]: 1 vs 0 |
| C11 | dict_setitem | 0 | T3 | state |  |  | 0x0/exit | call0 state.keys: ["\"n\"", "\"k\""] vs ["\"n\""] |
| C11 | list_append | 0 | T3 | state |  |  | 0x0/exit | call0 state.len: 1 vs 0 |
| C11 | list_+= | 0 | T3 | state |  |  | 0x0/exit | call0 state.len: 1 vs 0 |
| C13 | np_fix | 1 | T1 | value |  |  | 0x0/exit |  output[0]: /eager-compiled/ = 1.000e+00 exceeds dtype-aware tolerance 8.100e-03 at a finite position (eager 1 vs compiled 2; NaN-aware check) |
| C13 | np_cbrt | 0 | T1 | value |  |  | 0x0/exit |  output[0]: NaN/Inf pattern differs position-wise (first at flat index 1: eager -1.1447142362594604 vs compiled nan) |
| C13 | np_sign | 0 | T1 | value |  |  | 0x0/exit |  output[0]: NaN/Inf present on one side only |
| C13 | np_heaviside | 0 | T1 | value |  |  | 0x0/exit |  output[0]: NaN/Inf present on one side only |
| C13 | np_clip_int8 | 0 | T1 | value |  |  | 0x0/exit |  output[0]: non-float values differ exactly |
| C13 | np_clip_uint8 | 0 | T1 | value |  |  | 0x0/exit |  output[0]: non-float values differ exactly |
| C14 | remainder_n8 | 1 | T1 | value |  |  | 0x0/exit |  output[0]: NaN/Inf present on one side only |
| C15 | uint8_argmin | 1 | T1 | value |  |  | 0x0/exit |  output[0]: non-float values differ exactly |
| C15 | uint8_min | 0 | T1 | value |  |  | 0x0/exit |  output[0]: non-float values differ exactly |
| C15 | int8_neg_max | 0 | T1 | value |  |  | 0x0/exit |  output[0]: non-float values differ exactly |
| C15 | int8_neg_argmax | 0 | T1 | value |  |  | 0x0/exit |  output[0]: non-float values differ exactly |
| C16 | round_shape_neg1 | 1 | T1 | value |  |  | 0x0/exit | call0 output[0]: non-float values differ exactly |
| C16 | x_times_round | 0 | T1 | value |  |  | 0x0/exit | call1 output[0]: /ref-test/ = 5.000e+00 exceeds dtype-aware tolerance 8.010e-02 (no fp64 reference) |
| C17 | nan_self_compare | 1 | T1 | value |  |  | 0x0/exit |  output[0]: NaN/Inf present on one side only |
| C17 | inf_minus_inf_item | 0 | T1 | value |  |  | 0x0/exit |  output[0]: non-float values differ exactly |
| C20 | np_cumsum_int8 | 1 | T1 | value |  |  | 0x0/exit |  output[0]: non-float values differ exactly |
| C20 | np_square_int8 | 0 | T1 | value |  |  | 0x0/exit |  output[0]: non-float values differ exactly |
| C20 | np_median_f32 | 0 | T2 | structure |  |  | 0x0/exit |  output structure differs: float32 vs ndarray |
| C20 | np_any_uint8 | 0 | T2 | structure |  |  | 0x0/exit |  output structure differs: bool vs ndarray |
| C20 | uint16_plus_1 | 0 | T1 | exception |  | NotImplementedError | 0x0/exit |  compiled raised NotImplementedError ("add_stub" not implemented for 'UInt16'), eager returned |
| C21 | half_float_roundtrip | 1 | T1 | value |  |  | 0x0/exit |  output[0]: NaN/Inf present on one side only |
| C21 | bf16_float_roundtrip | 0 | T1 | value |  |  | 0x0/exit |  output[0]: /ref-test/ = 1.440e+02 exceeds dtype-aware tolerance 7.014e+01 (no fp64 reference) |
| C22 | clamp_int8_wide | 1 | T3 | exception-routing | RuntimeError |  | 0x0/exit |  eager raised RuntimeError (value cannot be converted to type int8_t without overflow), compiled returned |
| C22 | clamp_int8_max300 | 0 | T3 | exception-routing | RuntimeError |  | 0x0/exit |  eager raised RuntimeError (value cannot be converted to type int8_t without overflow), compiled returned |
| C22 | C31_pad_uint8_value_-1 | 0 | T3 | exception-routing | RuntimeError |  | 0x0/exit |  eager raised RuntimeError (value cannot be converted to type uint8_t without overflow), compiled returned |
| C22 | C31_pad_int8_value_300 | 0 | T3 | exception-routing | RuntimeError |  | 0x0/exit |  eager raised RuntimeError (value cannot be converted to type int8_t without overflow), compiled returned |
| C23 | inplace_on_inference_tensor | 1 | T3 | exception-routing | RuntimeError |  | 0x0/exit |  eager raised RuntimeError (Inplace update to inference tensor outside InferenceMode is not allowed.You can make a clone to get ), compiled returned |
| C23 | deterministic_put__duplicate | 0 | T3 | exception-routing | RuntimeError |  | 0x0/exit |  eager raised RuntimeError (put_ does not have a deterministic implementation, but you set 'torch.use_deterministic_algorithms(T), compiled returned |
| C23 | pad_crops_more_than_input | 0 | T3 | exception-routing | RuntimeError |  | 0x0/exit |  eager raised RuntimeError (narrow(): length must be non-negative.), compiled returned |
| C25 | empty_like_randn | 1 | T1 | value |  |  | 0x0/exit |  output[0]: NaN/Inf present on one side only |
| C25 | empty_int32 | 0 | T1 | value |  |  | 0x0/exit |  output[0]: non-float values differ exactly |
| C28 | fp16_chain | 1 | T1 | value |  |  | 0x0/exit |  output[1]: NaN/Inf present on one side only |
| C29 | any_uint8 | 1 | T2 | metadata |  |  | 0x0/exit |  output[0].dtype: torch.uint8 vs torch.bool |
| C29 | any_uint8_dim0 | 0 | T2 | metadata |  |  | 0x0/exit |  output[0].dtype: torch.uint8 vs torch.bool |
| C29 | any_times_200_plus_100 | 0 | T1 | value |  |  | 0x0/exit |  output[0]: non-float values differ exactly |
| C34 | avg_pool1d_ceil_grad | 1 | T3 | gradient |  |  | 0x0/exit |  grad[0]: compiled err vs fp64 = 1.667e-01 exceeds 8.0x eager err 3.974e-08 |
| C34 | avg_pool2d_ceil_grad | 0 | T3 | gradient |  |  | 0x0/exit |  grad[0]: compiled err vs fp64 = 2.500e-01 exceeds 8.0x eager err 3.311e-08 |
| C35 | erfinv_f32_near_1 | 1 | T1 | value |  |  | 0x0/exit |  output[0]: /ref-test/ = 2.892e-02 exceeds dtype-aware tolerance 3.933e-03 (no fp64 reference) |
| C35 | erfinv_f64_near_1 | 0 | T1 | value |  |  | 0x0/exit |  output[0]: /ref-test/ = 2.090e-02 exceeds dtype-aware tolerance 5.964e-03 (no fp64 reference) |
| C36 | acosh_f64_1e200_n8 | 1 | T1 | value |  |  | 0x0/exit |  output[0]: NaN/Inf present on one side only |
| C36 | acosh_f64_1.35e154_n16 | 0 | T1 | value |  |  | 0x0/exit |  output[0]: NaN/Inf present on one side only |
| C37 | softmax_int64 | 1 | T3 | exception-routing | NotImplementedError |  | 0x0/exit |  eager raised NotImplementedError ("softmax_lastdim_kernel_impl" not implemented for 'Long'), compiled returned |
| C37 | avg_pool2d_int8 | 0 | T3 | exception-routing | NotImplementedError |  | 0x0/exit |  eager raised NotImplementedError ("avg_pool2d" not implemented for 'Char'), compiled returned |
| C37 | bitwise_not_f32 | 0 | T3 | exception-routing | NotImplementedError |  | 0x0/exit |  eager raised NotImplementedError ("bitwise_not_cpu" not implemented for 'Float'), compiled returned |
| C37 | conv2d_bool | 0 | T3 | exception-routing | NotImplementedError |  | 0x0/exit |  eager raised NotImplementedError ("slow_conv2d_cpu" not implemented for 'Bool'), compiled returned |
| C37 | argmax_bool | 0 | T3 | exception-routing | RuntimeError |  | 0x0/exit |  eager raised RuntimeError (argmax(): does not support bool input), compiled returned |
| C37 | one_hot_f32 | 0 | T3 | exception-routing | RuntimeError |  | 0x0/exit |  eager raised RuntimeError (one_hot is only applicable to index tensor of type LongTensor.), compiled returned |
| C37 | bessel_j0_f16 | 0 | T3 | exception-routing | NotImplementedError |  | 0x0/exit |  eager raised NotImplementedError ("bessel_j0_cpu" not implemented for 'Half'), compiled returned |
| C37 | batch_norm_c64 | 0 | T3 | exception-routing | NotImplementedError |  | 0x0/exit |  eager raised NotImplementedError ("batch_norm" not implemented for 'ComplexFloat'), compiled returned |
| C37 | mse_loss_c64 | 0 | T3 | exception-routing | NotImplementedError |  | 0x0/exit |  eager raised NotImplementedError ("mse_cpu" not implemented for 'ComplexFloat'), compiled returned |
| C37 | C30_round_int8_decimals-1 | 0 | T3 | exception-routing | NotImplementedError |  | 0x0/exit |  eager raised NotImplementedError ("round_cpu" not implemented for 'Char'), compiled returned |
| C37 | C30_round_uint8_decimals1 | 0 | T3 | exception-routing | NotImplementedError |  | 0x0/exit |  eager raised NotImplementedError ("round_cpu" not implemented for 'Byte'), compiled returned |
| C37 | C30_ceil_bool | 0 | T3 | exception-routing | NotImplementedError |  | 0x0/exit |  eager raised NotImplementedError ("ceil_vml_cpu" not implemented for 'Bool'), compiled returned |
| C37 | C30_glu_int8 | 0 | T3 | exception-routing | NotImplementedError |  | 0x0/exit |  eager raised NotImplementedError ("glu_cpu" not implemented for 'Char'), compiled returned |
| C37 | C30_adaptive_max_pool2d_int8 | 0 | T3 | exception-routing | NotImplementedError |  | 0x0/exit |  eager raised NotImplementedError ("adaptive_max_pool2d" not implemented for 'Char'), compiled returned |
| C40 | erf_f32_near_0_n64 | 1 | T3 | reference |  |  | 0x0/exit |  float64 reference[0]: compiled rel err 1.00e+00 vs eager 6.77e-09 against the reference (64 of 64 elements) |
| C40 | atanh_f32_eps | 0 | T3 | reference |  |  | 0x0/exit |  float64 reference[0]: compiled rel err 1.00e+00 vs eager 2.22e-16 against the reference (16 of 64 elements) |
| C41 | move_to_end_input_dict | 1 | T3 | state |  |  | 0x0/exit |  input[0].keys: ["\"b\"", "\"c\"", "\"a\""] vs ["\"a\"", "\"b\"", "\"c\""] |
| C41 | lru_eviction | 0 | T3 | state |  |  | 0x0/exit |  state[0]: "a" vs "b" |
| C42 | generator_returned | 1 | T1 | value |  |  | 0x0/exit |  output[0]: non-float values differ exactly |
| C42 | C43_yield_op | 0 | T1 | value |  |  | 0x0/exit |  output[0]: non-float values differ exactly |
| C42 | C43_started_no_op | 0 | none |  |  |  | 0x0/exit |  |
| C44 | guarded_x[10] | 1 | T1 | exception |  | IndexError | 0x0/exit |  compiled raised IndexError (index 10 is out of bounds for dimension 0 with size 3

from user code:
   File "D:\wsl\personal\dr\paper\toxic_compile\p), eager returned |
| C44 | guarded_sum_dim5 | 0 | T1 | exception |  | IndexError | 0x0/exit |  compiled raised IndexError (Dimension out of range (expected to be in range of [-2, 1], but got 5)

from user code:
   File "D:\wsl\personal\dr\pape), eager returned |
| C44 | C45_except_Exception | 0 | T1 | exception |  | IndexError | 0x0/exit |  compiled raised IndexError (index 10 is out of bounds for dimension 0 with size 3

from user code:
   File "D:\wsl\personal\dr\paper\toxic_compile\p), eager returned |
| C44 | C45_contextlib_suppress | 0 | T1 | exception |  | IndexError | 0x0/exit |  compiled raised IndexError (Dimension out of range (expected to be in range of [-2, 1], but got 5)

from user code:
   File "D:\wsl\personal\dr\pape), eager returned |
| C44 | C45_NotImplementedError | 0 | T1 | exception |  | NotImplementedError | 0x0/exit |  compiled raised NotImplementedError ("bitwise_and_cpu" not implemented for 'Float'), eager returned |
| C46 | aoti_runner_destroyed_n4096 | 1 | T3 | process |  |  | 0xc0000005/calls_done | compiled process did not exit cleanly after the call(s): phase=calls_done exit=0xc0000005 timed_out=False |

## Not reproducible here / not detected

* **B5** (B5; In): new_zeros(device=cpu) returns a CUDA tensor under cudagraphs -- needs CUDA (triton.cudagraphs); this machine has no GPU

Sub-case notes:
* B7 / draft_block_verbatim: compiled side = the draft's whole first code block (its own torch.compile calls); eager side = the block's eager prefix
* C42 / C43_started_no_op: draft 41b's NEGATIVE example (no tensor work in the body: the generator is reconstructed correctly); expected to fire nothing
* C46 / aoti_runner_destroyed_n4096: the call itself succeeds; the process dies when the runner is destroyed afterwards

## Harness observations (affect how the numbers should be read)

* **T1 crash vs T3 process.** T1 counts a process that dies *during* the compiled call (B3: the trace has no call record and a non-zero exit). C46 finishes the call correctly and dies when the AOTI runner is destroyed afterwards; the harness records the call, then the teardown kills the process before the exit marker is written, so it is a T3 'process survival' finding, not T1.
* **tcc.oracle fallback tolerance is undefined when the eager output contains NaN.** `_float_pair_findings` scales its no-reference tolerance by `max|eager|`, which is NaN when any element is NaN, and `err > nan` is always False; its NaN rule only asks whether *any* NaN/Inf exists on one side. C13 (`np.fix`: 2.0 vs 1.0 next to a NaN element) fired nothing until the position-wise, NaN-aware check `_value_findings_nanaware` was added to T1 (same tolerance over finite positions). tcc/ itself was not modified (hard rule); the paper's harness normally has a float64 reference, whose `noise_floor` is finite-aware, so the reference path is not affected.
* **Value vs dtype.** `tcc.oracle._exact_equal` treats a dtype mismatch of integer/bool tensors as a value mismatch; for the tier separation T1 ignores such a finding when the values agree after casting to int64 (C29: uint8 `1` vs bool `True` is a T2 metadata finding, its downstream `any(x)*200+100` = 44 vs 300 a T1 value finding). Float outputs of different dtype are compared numerically, so B8's fp16 x bf16 / bf16 x fp64 sub-cases are T1 (the wrong dtype loses precision) while its primary sub-case is T2.
* **B7 is state dependent.** The internal assert only fires when a jvp already ran in the process (the draft calls the eager jvp first). Re-expressing the draft as module-level functions of the registry made Dynamo skip the frame and fall back to eager *successfully* (no tier fires); the draft's code block executed verbatim (as `scripts/run_issue_snippet.py` does) raises, and that verbatim sub-case is the primary one. The two re-expressed sub-cases are kept in `subcases.csv` with weakest = none.
* **C42 is a T1 finding through the program's output.** The draft's program drains the returned generator outside the compiled region (`consume()`); the observed output is that list (type name, yielded values, `StopIteration.value`), and the `StopIteration.value` 'done' vs None difference is a plain value difference. The paper's table attributes C42 to the identity observable; with the bare generator as output (no consumer) it would be an opaque-object type difference (T3 identity / T2 structure).
* **Exception-routing direction.** Everything the paper calls 'validation lost' (B12, C5, C22 on 2.14, C23, C37/C30) is *eager raises, compiled returns*: invisible to T1 by construction, detected only by the two-directional exception oracle of T3. C22 is T3 here because the 2.14 eager `clamp` raises; on nightly eager returns the input unchanged and the same case would be a T1 value finding.
* **B18** raises on both sides (eager: RuntimeError from the ambiguous tensor bool; compiled: RecursionError), so only the exception-type parity of T3 sees it.
* **Autocast control alarms** are value differences of a few bf16 ULPs under `autocast(bfloat16)` (no float64 reference is possible under autocast); the paper's sweep used a 3e-2 relative tolerance and its harness lets `torch._dynamo.utils.same(fp64_ref)` veto such findings, so they count as T1 false positives of the tolerance rule used here.

## False positives on the consistent control sets

**Corpus control**: the 29 unmodified programs of the controlled benchmark (`tcc/corpus.py`, expect=consistent), eager vs `torch.compile` with the program's own compile options, same tracer and tiers. Alarms: T1 0, T2 0 (T2 with the paper's non-strict stride rule: 0), T3 0 of 29.

**Autocast control** (the 8.11 negative result of `tab-negative.tex`: OpInfo ops whose sweep verdict was ok, float32 samples under `torch.autocast('cpu', dtype=bfloat16/float16)`, eager vs `torch.compile`, both sides traced in one process): 924 ops, 924 samples, 922 ok, 0 not runnable. Alarms (ops): T1 2, T2 2 (non-strict stride: 2), T3 2.

| op | sample | weakest | observables | first finding |
|---|---|---|---|---|
| nn.functional.bilinear | 0 | T1 | value |  output[0]: /ref-test/ = 1.729e-02 exceeds dtype-aware tolerance 7.185e-03 (no fp64 reference) |
| linalg.polar | 0 | T1 | value |  output[0]: /ref-test/ = 1.921e-03 exceeds dtype-aware tolerance 9.398e-04 (no fp64 reference) |

The other rows of `tab-negative.tex` (593 ops x 20 Inductor configurations, 520 export/AOTI ops, 678 vmap ops, ...) were not re-run for this analysis; their original sweeps used the paper's oracles, not these tiers, so no false-positive number is claimed for them.

## Manual review time (from the ledgers)

Source: `plan/TO_SUBMIT.md` and `plan/EXECUTION_REPORT.md`; only clock times the ledger records are used, nothing is estimated. The ledgers carry clock times only for 2026-09-22 (the day the round-2 drafts 33-43 were written); earlier entries carry dates or order-of-day markers ('morning', 'night') only, so their elapsed times are *not recorded*.

| RC | first divergence (sweep / triage) | confirmed (isolated reproducer) | draft ready / filed | elapsed (recorded) | source |
|---|---|---|---|---|---|
| B2 | 2026-09-12 | 2026-09-15 (independent re-check in a fresh process, 2.14 + nightly) | draft 2026-09-13 (0913issues/); independent re-check 2026-09-15 (verify_0913_issues.py); filed 2026-09-15 | not recorded (ledger has dates only) | TO_SUBMIT 14; 0913issues/README.md; EXECUTION_REPORT 2026-09-13/15 breakpoints |
| B3 | 2026-09-13 | 2026-09-15 (independent re-check in a fresh process, 2.14 + nightly) | draft 2026-09-13 (0913issues/); independent re-check 2026-09-15 (verify_0913_issues.py); filed 2026-09-15 | not recorded (ledger has dates only) | TO_SUBMIT 27; 0913issues/README.md; EXECUTION_REPORT 2026-09-13/15 breakpoints |
| B4 | 2026-09-10 | 2026-09-15 (independent re-check in a fresh process, 2.14 + nightly) | draft 2026-09-13 (0913issues/); independent re-check 2026-09-15 (verify_0913_issues.py); filed 2026-09-15 | not recorded (ledger has dates only) | TO_SUBMIT 6; 0913issues/README.md; EXECUTION_REPORT 2026-09-13/15 breakpoints |
| B5 | 2026-09-11 (Kaggle T4) | 2026-09-15 (independent re-check in a fresh process, 2.14 + nightly) | draft 2026-09-13 (0913issues/); independent re-check 2026-09-15 (verify_0913_issues.py); filed 2026-09-15 | not recorded (ledger has dates only) | TO_SUBMIT 13; 0913issues/README.md; EXECUTION_REPORT 2026-09-13/15 breakpoints |
| B6 | 2026-09-09 (fwd); 2026-09-10 (zero gradient) | 2026-09-15 (independent re-check in a fresh process, 2.14 + nightly) | draft 2026-09-13 (0913issues/); independent re-check 2026-09-15 (verify_0913_issues.py); filed 2026-09-15 | not recorded (ledger has dates only) | TO_SUBMIT 2; 0913issues/README.md; EXECUTION_REPORT 2026-09-13/15 breakpoints |
| B7 | date not recorded; re-checked 2026-09-15 | 2026-09-15 (independent re-check in a fresh process, 2.14 + nightly) | draft 2026-09-13 (0913issues/); independent re-check 2026-09-15 (verify_0913_issues.py); filed 2026-09-15 | not recorded (ledger has dates only) | TO_SUBMIT 28; 0913issues/README.md; EXECUTION_REPORT 2026-09-13/15 breakpoints |
| B8 | 2026-09-12 | 2026-09-15 (independent re-check in a fresh process, 2.14 + nightly) | draft 2026-09-13 (0913issues/); independent re-check 2026-09-15 (verify_0913_issues.py); filed 2026-09-15 | not recorded (ledger has dates only) | TO_SUBMIT 18; 0913issues/README.md; EXECUTION_REPORT 2026-09-13/15 breakpoints |
| B9 | 2026-09-13 | 2026-09-15 (independent re-check in a fresh process, 2.14 + nightly) | draft 2026-09-13 (0913issues/); independent re-check 2026-09-15 (verify_0913_issues.py); filed 2026-09-15 | not recorded (ledger has dates only) | TO_SUBMIT 25; 0913issues/README.md; EXECUTION_REPORT 2026-09-13/15 breakpoints |
| B10 | 2026-09-12 | 2026-09-15 (independent re-check in a fresh process, 2.14 + nightly) | draft 2026-09-13 (0913issues/); independent re-check 2026-09-15 (verify_0913_issues.py); filed 2026-09-15 | not recorded (ledger has dates only) | TO_SUBMIT 16; 0913issues/README.md; EXECUTION_REPORT 2026-09-13/15 breakpoints |
| B11 | 2026-09-12 | 2026-09-15 (independent re-check in a fresh process, 2.14 + nightly) | draft 2026-09-13 (0913issues/); independent re-check 2026-09-15 (verify_0913_issues.py); filed 2026-09-15 | not recorded (ledger has dates only) | TO_SUBMIT 23; 0913issues/README.md; EXECUTION_REPORT 2026-09-13/15 breakpoints |
| B12 | 2026-09-09 | 2026-09-15 (independent re-check in a fresh process, 2.14 + nightly) | draft 2026-09-13 (0913issues/); independent re-check 2026-09-15 (verify_0913_issues.py); filed 2026-09-15 | not recorded (ledger has dates only) | TO_SUBMIT 3; 0913issues/README.md; EXECUTION_REPORT 2026-09-13/15 breakpoints |
| B13 | 2026-09-10 | 2026-09-15 (independent re-check in a fresh process, 2.14 + nightly) | draft 2026-09-13 (0913issues/); independent re-check 2026-09-15 (verify_0913_issues.py); filed 2026-09-15 | not recorded (ledger has dates only) | TO_SUBMIT 12; 0913issues/README.md; EXECUTION_REPORT 2026-09-13/15 breakpoints |
| B14 | 2026-09-09 | 2026-09-15 (independent re-check in a fresh process, 2.14 + nightly) | draft 2026-09-13 (0913issues/); independent re-check 2026-09-15 (verify_0913_issues.py); filed 2026-09-15 | not recorded (ledger has dates only) | TO_SUBMIT 4; 0913issues/README.md; EXECUTION_REPORT 2026-09-13/15 breakpoints |
| B15 | 2026-09-09 | 2026-09-15 (independent re-check in a fresh process, 2.14 + nightly) | draft 2026-09-13 (0913issues/); independent re-check 2026-09-15 (verify_0913_issues.py); filed 2026-09-15 | not recorded (ledger has dates only) | TO_SUBMIT 5; 0913issues/README.md; EXECUTION_REPORT 2026-09-13/15 breakpoints |
| B17 | 2026-09-12 | 2026-09-15 (independent re-check in a fresh process, 2.14 + nightly) | draft 2026-09-13 (0913issues/); independent re-check 2026-09-15 (verify_0913_issues.py); filed 2026-09-15 | not recorded (ledger has dates only) | TO_SUBMIT 15; 0913issues/README.md; EXECUTION_REPORT 2026-09-13/15 breakpoints |
| B18 | 2026-09-12 | 2026-09-15 (independent re-check in a fresh process, 2.14 + nightly) | draft 2026-09-13 (0913issues/); independent re-check 2026-09-15 (verify_0913_issues.py); filed 2026-09-15 | not recorded (ledger has dates only) | TO_SUBMIT 17; 0913issues/README.md; EXECUTION_REPORT 2026-09-13/15 breakpoints |
| B19 | 2026-09-10 | 2026-09-15 (independent re-check in a fresh process, 2.14 + nightly) | draft 2026-09-13 (0913issues/); independent re-check 2026-09-15 (verify_0913_issues.py); filed 2026-09-15 | not recorded (ledger has dates only) | TO_SUBMIT 8; 0913issues/README.md; EXECUTION_REPORT 2026-09-13/15 breakpoints |
| B20 | 2026-09-10 | 2026-09-15 (independent re-check in a fresh process, 2.14 + nightly) | draft 2026-09-13 (0913issues/); independent re-check 2026-09-15 (verify_0913_issues.py); filed 2026-09-15 | not recorded (ledger has dates only) | TO_SUBMIT 11; 0913issues/README.md; EXECUTION_REPORT 2026-09-13/15 breakpoints |
| B21 | date not recorded | 2026-09-15 (independent re-check in a fresh process, 2.14 + nightly) | draft 2026-09-13 (0913issues/); independent re-check 2026-09-15 (verify_0913_issues.py); filed 2026-09-15 | not recorded (ledger has dates only) | TO_SUBMIT 20; 0913issues/README.md; EXECUTION_REPORT 2026-09-13/15 breakpoints |
| B22 | date not recorded | 2026-09-15 (independent re-check in a fresh process, 2.14 + nightly) | draft 2026-09-13 (0913issues/); independent re-check 2026-09-15 (verify_0913_issues.py); filed 2026-09-15 | not recorded (ledger has dates only) | TO_SUBMIT 21; 0913issues/README.md; EXECUTION_REPORT 2026-09-13/15 breakpoints |
| B23 | 2026-09-10 | 2026-09-15 (independent re-check in a fresh process, 2.14 + nightly) | draft 2026-09-13 (0913issues/); independent re-check 2026-09-15 (verify_0913_issues.py); filed 2026-09-15 | not recorded (ledger has dates only) | TO_SUBMIT 9; 0913issues/README.md; EXECUTION_REPORT 2026-09-13/15 breakpoints |
| B24 | 2026-09-08 | 2026-09-15 (independent re-check in a fresh process, 2.14 + nightly) | draft 2026-09-13 (0913issues/); independent re-check 2026-09-15 (verify_0913_issues.py); filed 2026-09-15 | not recorded (ledger has dates only) | TO_SUBMIT 1; 0913issues/README.md; EXECUTION_REPORT 2026-09-13/15 breakpoints |
| B25 | 2026-09-10 | 2026-09-15 (independent re-check in a fresh process, 2.14 + nightly) | draft 2026-09-13 (0913issues/); independent re-check 2026-09-15 (verify_0913_issues.py); filed 2026-09-15 | not recorded (ledger has dates only) | TO_SUBMIT 7; 0913issues/README.md; EXECUTION_REPORT 2026-09-13/15 breakpoints |
| B26 | 2026-09-12 | 2026-09-15 (independent re-check in a fresh process, 2.14 + nightly) | draft 2026-09-13 (0913issues/); independent re-check 2026-09-15 (verify_0913_issues.py); filed 2026-09-15 | not recorded (ledger has dates only) | TO_SUBMIT 22; 0913issues/README.md; EXECUTION_REPORT 2026-09-13/15 breakpoints |
| B27 | date not recorded | 2026-09-15 (independent re-check in a fresh process, 2.14 + nightly) | draft 2026-09-13 (0913issues/); independent re-check 2026-09-15 (verify_0913_issues.py); filed 2026-09-15 | not recorded (ledger has dates only) | TO_SUBMIT 30; 0913issues/README.md; EXECUTION_REPORT 2026-09-13/15 breakpoints |
| C1 | 2026-09-20 evening (error_parity_batch2) | isolated reproducer (saved_view_variants.py, 12 variants x 3 backends) - date only | filed 2026-09-21 (#197887) | not recorded (ledger has dates only) | TO_SUBMIT 31; EXECUTION_REPORT 2026-09-20/21 breakpoints (part-of-day markers only); FILED.md |
| C3 | 2026-09-21 evening (scalar_arg_sequence_diff on nightly) | norm_eps_stale_min.py cache 2x2 matrix - date only | filed 2026-09-21 (#197889); C26 comment 2026-09-22 | not recorded (ledger has dates only) | TO_SUBMIT 54, 57; EXECUTION_REPORT 2026-09-20/21 breakpoints (part-of-day markers only); FILED.md |
| C5 | 2026-09-20 (error_parity_sweep 8.1) | diag_error_parity_leads.py per-case processes 2026-09-20 | comment posted 2026-09-21 | not recorded (ledger has dates only) | TO_SUBMIT 34; EXECUTION_REPORT 2026-09-20/21 breakpoints (part-of-day markers only); FILED.md |
| C8 | 2026-09-21 early morning (rewrite_precondition_diff 10.1) | noop_returns_input_alias.py - date only | filed 2026-09-21 (#197893) | not recorded (ledger has dates only) | TO_SUBMIT 45; EXECUTION_REPORT 2026-09-20/21 breakpoints (part-of-day markers only); FILED.md |
| C10 | 2026-09-21 (int_ub_sweep 8.2) | floor_divide_python_example.py - date only | filed 2026-09-21 (#197895) | not recorded (ledger has dates only) | TO_SUBMIT 38; EXECUTION_REPORT 2026-09-20/21 breakpoints (part-of-day markers only); FILED.md |
| C11 | 2026-09-21 early morning (side_effect_diff) | closure_mutation_min2.py - date only | filed 2026-09-21 (#197896) | not recorded (ledger has dates only) | TO_SUBMIT 42; EXECUTION_REPORT 2026-09-20/21 breakpoints (part-of-day markers only); FILED.md |
| C13 | 2026-09-20 (xtarget_numpy_diff --target dynamo) | dynamo_numpy_semantics.py - date only | filed 2026-09-22 (#198052) | not recorded (ledger has dates only) | TO_SUBMIT 32; EXECUTION_REPORT 2026-09-20/21 breakpoints (part-of-day markers only); FILED.md |
| C14 | 2026-09-21 (int_ub_sweep 8.2) | remainder_vector_vs_tail.py - date only | filed 2026-09-22 (#198057) | not recorded (ledger has dates only) | TO_SUBMIT 39; EXECUTION_REPORT 2026-09-20/21 breakpoints (part-of-day markers only); FILED.md |
| C15 | 2026-09-21 (int_ub_sweep 8.2) | int8_minmax_vector_padding.py; Linux re-check (Kaggle) - date only | comment posted 2026-09-22 | not recorded (ledger has dates only) | TO_SUBMIT 37; EXECUTION_REPORT 2026-09-20/21 breakpoints (part-of-day markers only); FILED.md |
| C16 | 2026-09-21 evening (symint_arith_diff 10.5) | scalar_semantics_leads.py - date only | filed 2026-09-22 (#198064) | not recorded (ledger has dates only) | TO_SUBMIT 52; EXECUTION_REPORT 2026-09-20/21 breakpoints (part-of-day markers only); FILED.md |
| C17 | 2026-09-21 evening (symint_arith_diff 10.5) | nan_self_compare.py (11 forms x 3 backends) - date only | filed 2026-09-22 (#198070) | not recorded (ledger has dates only) | TO_SUBMIT 53; EXECUTION_REPORT 2026-09-20/21 breakpoints (part-of-day markers only); FILED.md |
| C20 | 2026-09-20 (xtarget_numpy_diff --target dynamo) | dynamo_numpy_semantics.py - date only | filed 2026-09-22 (#198056) | not recorded (ledger has dates only) | TO_SUBMIT 33; EXECUTION_REPORT 2026-09-20/21 breakpoints (part-of-day markers only); FILED.md |
| C21 | 2026-09-21 (int_ub_sweep 8.2, cast_half_back) | inductor_value_leads.py - date only | comment posted 2026-09-22 | not recorded (ledger has dates only) | TO_SUBMIT 40; EXECUTION_REPORT 2026-09-20/21 breakpoints (part-of-day markers only); FILED.md |
| C22 | 2026-09-21 (int_ub_sweep 8.2, clamp_wide); C31 2026-09-22 (12.1) | inductor_value_leads.py / dtype_not_implemented_lost.py - date only | filed 2026-09-22 (#198071); C31 comment 2026-09-22 | not recorded (ledger has dates only) | TO_SUBMIT 41, 69; EXECUTION_REPORT 2026-09-20/21 breakpoints (part-of-day markers only); FILED.md |
| C23 | 2026-09-21 evening (model_surgery_diff 10.4); item 4 2026-09-21 late night (symshape_index_diff 10.5b) | safety_mechanisms_lost.py - date only | comment posted 2026-09-22 | not recorded (ledger has dates only) | TO_SUBMIT 50; EXECUTION_REPORT 2026-09-20/21 breakpoints (part-of-day markers only); FILED.md |
| C25 | 2026-09-22 (split out of draft 22 on the morning of 2026-09-22) | issue_174386_recheck.py - date only | comment posted 2026-09-22 (before 09:40) | not recorded (no clock time for the first divergence) | TO_SUBMIT 56; EXECUTION_REPORT 2026-09-22 07:40/09:40 blocks |
| C28 | 2026-09-22 morning (11.4 edge sweep, f16/bf16 group) | half_intermediates_cpu.py - date only | comment written before ~10:00; posted 2026-09-22 (ledger blocks 09:40 and ~10:00 disagree on the order) | not recorded (ledger times inconsistent) | TO_SUBMIT 60; EXECUTION_REPORT 2026-09-22 09:40 / ~10:00 blocks |
| C29 | 2026-09-22 before 09:40 (11.4 opinfo_edge_sweep int group, Linux) | cuda_scan_and_any_u8.py - date only | draft ready by 09:40 (checker passed); filed by 11:15 (#198081) | draft->filed <= 1 h 35 min (09:40 -> 11:15, upper bound); sweep->draft not recorded | TO_SUBMIT 65; EXECUTION_REPORT 2026-09-22 09:40 and 11:15 blocks |
| C34 | 2026-09-22 before 11:15 (opinfo_edge_sweep --grad, 12.2) | avg_pool_ceil_mode_backward.py - no clock time | draft ready by 11:15; filed before 14:00 (#198119) | draft->filed <= 2 h 45 min (11:15 -> 14:00, upper bound); sweep->draft not recorded | TO_SUBMIT 72-73; EXECUTION_REPORT 2026-09-22 11:15 and 22:24 blocks |
| C35 | 2026-09-22 between 11:15 and 14:00 (large_arg_special_functions.py probe) | vector_acosh_erfinv.py (mpmath 30 digits) - no clock time | filed before 14:00 (#198133) | probe->filed <= 2 h 45 min (11:15 -> 14:00, upper bound) | TO_SUBMIT 75; EXECUTION_REPORT 2026-09-22 22:24 block (34, 35 added before 14:00) |
| C36 | 2026-09-22 between 11:15 and 14:00 (large_arg_special_functions.py probe) | vector_acosh_erfinv.py - no clock time | filed before 14:00 (#198134) | probe->filed <= 2 h 45 min (11:15 -> 14:00, upper bound) | TO_SUBMIT 76; EXECUTION_REPORT 2026-09-22 22:24 block |
| C37 | Kaggle edgeunsup results retrieved 14:05 2026-09-22 (sweep launch time not recorded) | triage + unsupported_dtype_family.py (41 cases re-checked locally) by 14:55 | draft 36 ready 14:55; filed by 15:40 (#198155); C38 comment: GPU results triaged -> comment ready 16:05, posted by 16:40 | retrieval->draft 50 min (14:05 -> 14:55); draft->filed <= 45 min; C38: comment ready->posted <= 35 min | TO_SUBMIT 77, 81; EXECUTION_REPORT 2026-09-22 14:55 / 15:40 / 16:05 / 16:40 entries |
| C40 | special_vs_mpmath sweep launched after 17:00 2026-09-22 (nothing running at 17:00); hits triaged by 18:45 | reproducer in draft, checker passed, Linux re-check (tcc-erflinux) by 18:45 | draft ready 18:45; filed 18:56 (#198183) | sweep launch->draft ready <= 1 h 45 min (17:00 -> 18:45, upper bound); draft->filed 11 min (18:45 -> 18:56) | TO_SUBMIT 85 ('2026-09-22 18:56'); EXECUTION_REPORT 2026-09-22 17:00 / 18:45 entries |
| C41 | graph_break_insertion_diff (7.6) launched after 19:15 2026-09-22; minimized ($TEMP/od_input.py, od_variants.py, od_bisect.py) | checker passed, 2.14 + nightly outputs real, by 19:30 | draft 40 ready 19:30; filed by 19:49 (#198189) | sweep launch->draft ready <= 15 min (19:15 -> 19:30, upper bound); draft->filed <= 19 min | TO_SUBMIT 89; EXECUTION_REPORT 2026-09-22 19:15 / 19:30 / 19:49 entries |
| C42 | same 7.6 sweep, after 19:15 2026-09-22; C43 family from reconstruct_diff (12.6), triaged 19:49 | checker passed by 19:30; Linux re-check (tcc-dynsemlinux) 19:49 | draft 41 ready 19:30; filed by 19:49 (#198190); C43 comment posted by 20:12 | sweep launch->draft ready <= 15 min (upper bound); draft->filed <= 19 min; C43: triage 19:49 -> posted <= 23 min | TO_SUBMIT 89-90; EXECUTION_REPORT 2026-09-22 19:30 / 19:49 / 20:12 entries |
| C44 | corpus batch 4 (57 programs) written and run after 19:52 2026-09-22 (nothing running at 19:52) | $TEMP/exc_types.py (25 operator errors) - within the same window | draft 42 ready and filed by 20:12 (#198192); C45 comment (batch 5, 33 programs) posted 22:03 | batch launch->filed <= 20 min (19:52 -> 20:12, upper bound); C45: <= 1 h 38 min after 20:25 (batch 5 not yet running at 20:25) | TO_SUBMIT 94, 100; EXECUTION_REPORT 2026-09-22 19:52 / 20:12 / 20:25 / 22:03 entries |
| C46 | export_roundtrip_edge (7.7) running at 20:25 2026-09-22; segfault at slice_scatter found when the sweep finished | minimized ($TEMP/ss_min.py, ss_var.py, ss_size.py, ss_omp.py: element count >= 4096, 4 avoidance conditions) by 21:39 | draft 43 ready and filed by 21:39 (#198205) | sweep running->filed <= 1 h 14 min (20:25 -> 21:39, upper bound; sweep runtime included) | TO_SUBMIT 99; EXECUTION_REPORT 2026-09-22 20:25 / 21:39 entries |

## Files

* `root_causes.csv` -- root_cause_id, member_items, layer, reproducer_path, reproducible_here (+reason, status, title)
* `tiers.csv` -- root_cause_id, T1, T2, T3, weakest_tier, observable_that_fires (+ primary-only columns)
* `subcases.csv` -- one row per executed sub-case
* `traces/*.json` -- one trace per sub-case (both sides); `control_traces/*.json` -- corpus control; `control_autocast_*.jsonl` -- autocast control
* `summary.json` -- machine-readable summary; `review_times.csv` -- ledger extraction
