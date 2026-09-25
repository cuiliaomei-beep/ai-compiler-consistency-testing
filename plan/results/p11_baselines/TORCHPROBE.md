# TorchProbe (Su, Geng, Pekhimenko, Si; APLAS 2023) against torch.compile 2.14 -- attempt log and results

Date of the attempt: 2026-09-25 (clock). Machine: Windows 11 Pro for Workstations, Python 3.14.7, torch 2.14.0+cpu,
nnsmith 0.1.0, MSVC 14.44 (Build Tools 2022), no GPU. Working copy of the tool and all temporary files:
`C:\Users\clm\AppData\Local\Temp\claude\d--wsl-personal-dr-paper\712b330c-4254-4beb-b7b3-ad57d91dc2ee\scratchpad\p11\`.

## 1. Locating the artifact

* The paper (arXiv 2310.20078, Springer 10.1007/978-981-99-8311-7_15) contains no repository URL. Its Section 4.2
  points to the bug lists `github.com/pytorch/pytorch/issues/created_by/soodoshll` and
  `github.com/openai/triton/issues/created_by/soodoshll`; `soodoshll` is the first author's GitHub account.
* GitHub repository search for "TorchProbe" returns only two unrelated projects (`kkew3/torchprobe`,
  `KurisuNya/torchprobe`, both PyTorch inspection utilities). The authors' home pages and Xujie Si's artifact page
  list no code for this paper.
* Listing `soodoshll`'s repositories gives **`https://github.com/soodoshll/temisu`** (created 2023-03-06, last push
  2023-03-21, 19 commits, no description, no stars). Its README is the paper's abstract in short form:
  "A fuzzing tool built upon NNSmith to find bugs in the new compilers of PyTorch, covering more dynamic features
  to be tested (control flow, loops, tensor manipulation, etc). Already found ~20 bugs of PyTorch compiler (see
  .../issues/created_by/soodoshll ...)". Its transformation list (true conditional blocks, operator resolution,
  modify-then-recover, functionalize/sub-function, compound data types) is the paper's Section 3. This is the
  TorchProbe implementation ("temisu" is its working name).
* Cloned at commit **`3aa039c4882f34400cdde9199fc39e688823d4a4`** (2023-03-20, "Update readme.md"). Size:
  `temisu/ir.py` 577 lines, `temisu/mutator.py` 294, `temisu/fuzz.py` 164, `temisu/logging.py` 5, `readme.md` 47
  (1087 lines; the paper says "approximately 1000 lines of Python code on the top of NNSmith").

## 2. What the tool is (from reading the code)

* **Seed programs**: NNSmith computational graphs (`nnsmith.graph_gen.model_gen`, `max_nodes=10` hard-coded in
  `fuzz.py`; the paper's evaluation used 20 operators), rendered by `ir.py::TFunction` into a straight-line Python
  function `forward(mlist, v0, v1, ...)` whose statements are NNSmith operators (`renderReLU`, `renderMatMul`,
  `renderSlice`, ... 60 renderers). Inputs are the NNSmith oracle's concrete tensors; weights live in `mlist`.
* **Mutations** (`mutator.py`, applied cumulatively: test k contains mutations 1..k):
  `origin` (unmutated), `modify_then_recover` (back up one element of an intermediate tensor, overwrite it, restore
  it before its next use), `desolve_op` ("operator resolution": one element-wise op rewritten as a `for` loop over
  one axis with slice assignment), `insert_tcb` (wrap a statement range in an always-true `if` whose condition
  compares two scalarised tensors of the value profile), `subfunction` (wrap a statement range in a nested
  function that returns every defined variable). `matmul_then_inverse` exists but is commented out of the list.
  Every mutation needs a **concrete value profile** of every statement (`Mutator.profile` executes the instruction
  list eagerly), so a seed must be executable straight-line SSA tensor code with tensor-only inputs.
* **Oracle** (`fuzz.py`): `torch.compile(forward, backend="inductor")` under `torch.no_grad()`, output compared with
  NNSmith's eager oracle by `np.allclose(rtol=1e-2, atol=1e-4)`, NaN/Inf outputs skipped. Any exception is a
  "compiler crash"; any mismatch an "inconsistent result". Values only: no alias, mutation, gradient, exception-type
  or recompilation check.
* **Pinned versions**: none. No `requirements.txt`, `setup.py` or lock file. README: "newest PyTorch compiled from
  source", "NNSmith". Written for Python <= 3.10 (see 3.2).

## 3. Running it

### 3.1 Verbatim (`python -m temisu.fuzz`, unmodified clone)

Blocking error (full log `scratchpad/p11/verbatim_run.log`):

```
  File "...\temisu\fuzz.py", line 38, in <module>      # th_model.to(device) with device = 'cuda'
  ...
  File "...\torch\cuda\__init__.py", line 584, in _lazy_init
    raise AssertionError("Torch not compiled with CUDA enabled")
AssertionError: Torch not compiled with CUDA enabled
```

`fuzz.py` hard-codes `device = 'cuda'` at module level and has no CLI; the module body is an unbounded
`while True` fuzzing loop that also deletes `./report` on start.

### 3.2 Two changes needed to run on this machine (both recorded, nothing else touched)

1. **Driver** `scratchpad/p11/run_temisu.py`: the loop body of `fuzz.py` copied verbatim with `device` as a
   parameter (`cpu`), a bounded number of seeds, `model_gen(..., seed=s)` for reproducibility (fuzz.py passes no
   seed), the MSVC environment imported the way `run.py` does (`tcc.compat.ensure_msvc_env`, otherwise Inductor
   fails with `InvalidCxxCompiler: Compiler: cl is not found`), and one extra diagnostic: each mutated program is
   also executed **eagerly** against the NNSmith oracle, so an invalid mutation can be told from a compiler
   divergence (fuzz.py attributes every failure to the compiler). Programs and inputs are saved for Setting B.
2. **One-line patch to the tool** (`git diff` in `scratchpad/p11/temisu`):
   `mutator.py:46  random.sample(tensor_map.items(), 2)` -> `random.sample(list(tensor_map.items()), 2)`.
   Python >= 3.11 raises `TypeError: Population must be a sequence. For dicts or sets, use sorted(d).` here, so
   the `insert_tcb` mutation (and every later one, since mutations are cumulative) cannot run on Python 3.11+
   without it. This is the only Python-version incompatibility found; every nnsmith API the tool imports exists in
   nnsmith 0.1.0 (`Model.init/from_gir/refine_weights/make_oracle`, `native_model.instructions/mlist/ir/output_map`,
   `narrow_spec.auto_opset`, `util.op_filter`, `materialize.torch.dialect.{Flatten,Linear,TorchReduceSum}`).

No separate virtual environment was needed: the tool pins nothing, and after the two changes it runs on Python
3.14 / torch 2.14.0+cpu / nnsmith 0.1.0. (`py -0` lists only Python 3.14 on this machine, so an older interpreter
was not available anyway.)

### 3.3 Results on its own seed programs (real compiler, CPU Inductor, torch 2.14.0+cpu)

See Section 5 (filled from `tests.jsonl` after the runs).

## 4. Applicability to our programs

TorchProbe's seed is an NNSmith GIR: straight-line SSA tensor code, tensor-only inputs, operators from NNSmith's
opset with a `render*` method in `ir.py`, and a concrete value profile per statement. None of its four mutations
reads a Python program; they edit the instruction list. Our programs are Python functions, so the question is
which of them *could* be expressed as such an instruction list. `scripts/p11_torchprobe_applicability.py`
classifies each program by AST (per-program rows in `torchprobe_applicability.json`, corpus table in
`torchprobe_applicability_corpus29.md`, totals in `torchprobe_applicability_summary.json`).

| corpus | programs | expressible as a TorchProbe seed | blockers (a program may have several) |
|---|---:|---:|---|
| 29-program controlled-fault corpus (`tcc/corpus.py`) | 29 | **3** (`alias_returned`, `requires_grad_switch`, `dtype_reduce`) | control flow 16, Python reads of tensor metadata (`shape/dtype/stride/ndim/is_contiguous/device`) 11, operators without a renderer 10, non-tensor arguments 9, in-place mutation 5, non-static indexing 4, Python calls 3, module global 1, closure variable 1 |
| Python-semantics corpus, first 185 programs (`dynamo_semantics` 77, `_more` 74, `_batch3` 33, plus one `_batch4` program registered in between) | 185 | **0** | Python calls 185, operators without a renderer 143, control flow 117, metadata reads 91, in-place mutation 64, module globals 35, non-static indexing 31, `global`/`nonlocal` 2 |

For the three expressible corpus programs the mutations with a candidate site would be: `alias_returned`
(`y = x.transpose(0, 1); return y`) -- insert_tcb, modify_then_recover, subfunction; `requires_grad_switch`
(`(x * 3.0).relu().sum()`) -- all four; `dtype_reduce` -- desolve_op, subfunction. Even for these three the
comparison would be moot: TorchProbe runs under `torch.no_grad()` and compares values only, whereas the faults
attached to these programs in the benchmark are an alias fault (`functionalize_alias_to_copy`), a gradient /
requires_grad fault (`autograd_wrong_gradient`, `underspec_requires_grad`) and dtype cache faults exercised by a
warm context switch (`underspec_dtype`, `cache_stale_on_return`) -- none is observable with one input, one
context, values only. TorchProbe was therefore not run on our programs; running it "on our programs" would mean
re-implementing its four mutations as Python AST rewrites, which is a different tool (our own
`scripts/graph_break_insertion_diff.py` is such an AST-level transformation and is already in the paper).

The converse direction is possible and was done: TorchProbe's own generated programs were loaded into our harness
(Setting B, same as the NNSmith leg of RQ2) and judged against the 19 injected faults -- Section 6.

## 5. Results on TorchProbe's own seed programs (real compiler)

Setting exactly as `fuzz.py`: NNSmith graphs, `dtype_choices=['bool','f32','int32','i64','f64']`, opset filter of
`fuzz.py`, `torch.compile(backend="inductor")` (CPU, C++/MSVC codegen), `torch.no_grad()`, oracle `np.allclose(rtol=1e-2,
atol=1e-4)` against NNSmith's eager output. Five tests per seed (mutations are cumulative: `origin`, +`modify_then_recover`,
+`desolve_op`, +`insert_tcb`, +`subfunction`). "eager-valid" is our added check that the mutated program still matches the
oracle when run uncompiled; "code unchanged" counts mutations that found no candidate site and returned the program as is
(the tool still runs and counts them as tests).

### 5.1 `max_nodes=10` (the value hard-coded in `fuzz.py`), seeds 0-34: 175 tests, 175 pass, 0 inconsistent, 0 crash

| mutation | tests | pass | inconsistent | compile/run error | eager-valid | eager-invalid | code unchanged by mutation | wall sum (s) | wall median (s) |
|---|---:|---:|---:|---:|---:|---:|---:|---:|---:|
| origin | 35 | 35 | 0 | 0 | 35 | 0 | - | 134.0 | 2.91 |
| modify_then_recover | 35 | 35 | 0 | 0 | 35 | 0 | 9 | 59.1 | 0.52 |
| desolve_op | 35 | 35 | 0 | 0 | 35 | 0 | 9 | 81.3 | 2.43 |
| insert_tcb | 35 | 35 | 0 | 0 | 35 | 0 | 2 | 167.4 | 4.95 |
| subfunction | 35 | 35 | 0 | 0 | 35 | 0 | 0 | 142.2 | 2.73 |
| **all** | 175 | 175 | 0 | 0 | 175 | 0 | 20 | 583.9 | 2.79 |

Wall: 583.9 s for the 175 tests (median 2.79 s per test; the first compile of a
process is 18.7 s), seed generation 2.3 s. Records: `torchprobe_tests_n10.jsonl`; programs: `torchprobe_programs_n10/`.

### 5.2 `max_nodes=20` (the paper's setting), seeds 100-109: 47 tests, 47 pass, 0 inconsistent, 0 crash

| mutation | tests | pass | inconsistent | compile/run error | eager-valid | eager-invalid | code unchanged by mutation | wall sum (s) | wall median (s) |
|---|---:|---:|---:|---:|---:|---:|---:|---:|---:|
| origin | 10 | 10 | 0 | 0 | 10 | 0 | - | 85.2 | 6.37 |
| modify_then_recover | 10 | 10 | 0 | 0 | 10 | 0 | 2 | 34.9 | 0.93 |
| desolve_op | 9 | 9 | 0 | 0 | 9 | 0 | 5 | 32.5 | 0.3 |
| insert_tcb | 9 | 9 | 0 | 0 | 9 | 0 | 0 | 98.9 | 11.03 |
| subfunction | 9 | 9 | 0 | 0 | 9 | 0 | 0 | 97.8 | 10.38 |
| **all** | 47 | 47 | 0 | 0 | 47 | 0 | 7 | 349.4 | 6.82 |

This batch was started with 15 seeds and was cut by the 10-minute command limit after 47 tests (seed 109 incomplete);
it also ran while another session's `scripts/oracle_tiers_real.py` workers were using the CPU, so its wall times
(349.4 s, median 6.82 s per test) are inflated relative to 5.1. Records:
`torchprobe_tests_n20.jsonl`; programs: `torchprobe_programs_n20/`.

### 5.3 Divergences found

**None.** In 222 TorchProbe tests (45 seed graphs) against torch 2.14.0+cpu Inductor, every compiled output
matched the NNSmith oracle within TorchProbe's tolerance and no compile or run raised. Every mutated program was also
eager-valid, so no test was invalid. Consequently there is nothing to map onto the paper's findings (`paper_tcc/data/findings.csv`,
B1-B27 / C1-C46): TorchProbe on its own seeds reproduces none of them and finds nothing new. This is consistent with what the
tool can observe: its 20 reported bugs (Table 1 of the paper, PyTorch issues #96432-#97807 and Triton #1328-#1342, March 2023)
were crashes and value mismatches in a two-month-old compiler; our findings are dominated by aliasing/mutation, exception routing,
Python-object reconstruction, gradients, dtype/cache specialisation and platform-specific codegen, none of which TorchProbe's
values-only, single-input, `no_grad`, single-context oracle measures.

## 6. Setting B: TorchProbe's programs judged by our harness against the 19 injected faults

Same leg as `B3_nnsmith_native` in `results/RQ2.md`: each program with the tool's own single input, cold
eager-vs-compiled, all oracles, one test per (fault, program); backend `eager`; `scripts/p11_torchprobe_setting_b.py`
(a copy of `tcc.experiments._external_bench(native=True)` that also runs the fixed-version pass and keeps per-fault
detail). Programs: the 35 seed graphs of Section 5.1 as rendered by TorchProbe unmutated (`origin`) and after all four
mutations (`subfunction`, cumulative). Every one of the 70 programs is clean on the unmodified compiler (fixed-version pass:
0 false positives).

| program set | programs | tests | invalid | faults "detected" as the harness counts them | of which by a value / alias / structure oracle | of which only through an exception | wall (s) |
|---|---:|---:|---:|---:|---:|---:|---:|
| TorchProbe `origin` (35 unmutated NNSmith graphs, TorchProbe renderer) | 35 | 665 | 0 | 6/19 | **5**/19 | 1 | 127.9 |
| TorchProbe `subfunction` (same 35 graphs after modify_then_recover + desolve_op + insert_tcb + subfunction) | 35 | 665 | 0 | 15/19 | **6**/19 | 9 | 310.1 |
| NNSmith native, 8 models (`results/RQ2.md`, and `nnsmith_seeds.md`: 6/19 in each of 3 model seeds) | 8 | 152 | 0 | 6/19 | see note | see note | - |

Per fault (`origin` / `subfunction`; count = detecting programs; "exc" = exception-only):

| fault | origin value/alias/structure | origin exc | subfunction value/alias/structure | subfunction exc |
|---|---:|---:|---:|---:|
| codegen_value | 32 | 0 | 32 | 0 |
| codegen_boundary_32 | 0 | 0 | 0 | 0 |
| codegen_boundary_31 | 0 | 0 | 0 | 0 |
| codegen_mod16_tail | 18 | 0 | 18 | 0 |
| codegen_index_last | 18 | 0 | 18 | 0 |
| codegen_noncontig | 0 | 0 | 0 | 0 |
| codegen_fp16_rounding | 0 | 0 | 0 | 0 |
| codegen_dynamic_flag | 0 | 0 | 0 | 1 |
| codegen_scalar_edge | 0 | 8 | 0 | 9 |
| functionalize_drop_mutation | 1 | 0 | 1 | 1 |
| functionalize_alias_to_copy | 1 | 0 | 1 | 1 |
| capture_swallow_exception | 0 | 0 | 2 | 0 |
| autograd_wrong_gradient | 0 | 0 | 0 | 4 |
| underspec_dtype | 0 | 0 | 0 | 4 |
| underspec_scalar | 0 | 0 | 0 | 4 |
| underspec_layout | 0 | 0 | 0 | 4 |
| underspec_requires_grad | 0 | 0 | 0 | 4 |
| cache_stale_on_return | 0 | 0 | 0 | 5 |
| cache_result_memo | 0 | 0 | 0 | 7 |

**Reading the exception column.** The harness counts an exception on the faulty compiler where eager returns normally as a
detection (kind `exception`). Here none of these is the injected fault being observed:

1. `codegen_scalar_edge` (8 programs in `origin`, 9 in `subfunction`): the fault wrapper `_make_scalar_boundary(1, 4)` tests
   `args[1] == 4`; on a program whose second argument is a tensor this is a tensor comparison and `if <tensor>` raises
   `RuntimeError: Boolean value of Tensor with more than one value is ambiguous` inside the wrapper. In the corpus the fault is
   restricted to `scalar_compare` / `loop_bound` (`Fault.programs`), but `_external_bench` applies every fault to every foreign
   program. The same artifact is in the NNSmith leg: on model seed 0 it fires on `nnsmith_6` (four tensor inputs), so
   NNSmith's 6/19 in `results/RQ2.md` contains one such count as well (its `control_flow 1/2` is this fault; `capture_swallow_exception`
   needs eager to raise, which NNSmith models never do). Verified 2026-09-25 by re-running the two faults over the seed-0 models.
2. Every other exception-only entry (`codegen_dynamic_flag` 1, `functionalize_*` 1 each, `autograd_wrong_gradient` 4,
   `underspec_dtype/scalar/layout/requires_grad` 4 each, `cache_stale_on_return` 5, `cache_result_memo` 7; programs
   seed12/21/22/23/27/28/30) is one and the same error raised by Dynamo while *tracing the mutated program*:
   `InternalTorchDynamoError: RuntimeError: dictionary changed size during iteration`. It appears only after several hundred
   compile/reset cycles in one process (each program is recompiled for every fault; the batch order is fault-major) and never
   standalone: each of these programs passes with `backend=eager|inductor`, `dynamic=None|False|True` in a fresh process
   (`scratchpad/p11/repro_dyn23.py`, `repro_exc.py`). It is upstream PyTorch PR #191281 ("[dynamo] Snapshot dict items in
   get_items_from_dict to avoid mutation race", merged to main 2026-08-20, fixes the flaky-test issue #190612): on Python 3.14
   Dynamo iterates a function's `globals()` through the live `dict.items()` view returned by
   `torch/_dynamo/utils.py::get_items_from_dict`, while `CleanupHook` weakref callbacks fired by garbage collection delete the
   `__compiled_fn_*` / `__resume_at_*` names Dynamo wrote into that same dict. TorchProbe's programs are `exec`-ed with a private
   globals dict that accumulates those names across the 20 compiles per program, which is the precondition. The v2.14.0 tag still
   has `return obj.items()` (line 3152); main has the `list(...)` snapshot. Not in our ledgers before today (no hit for
   191281 / 190612 / CleanupHook / the message in `TO_SUBMIT.md`, `findings.csv`, the drafts); one earlier occurrence of the same
   message sits unremarked in `kaggle_out/gpucuda/plan/gpu_results_binding/binding.jsonl`. Fixed upstream before we saw it, so
   it is recorded here and not proposed as an issue. Confirmed with `TORCHDYNAMO_VERBOSE=1`
   (`scratchpad/p11/diag_batch5.py`, log `diag_batch5.log`, first occurrence after 304 `run_program` calls, 133-143 s into the
   batch in three replays): the crash is raised while Dynamo inlines the nested `subfunc` and meets `LOAD_GLOBAL torch` --
   `symbolic_convert.py::_load_global -> get_globals_source_and_value -> VariableBuilder._wrap` (`builder.py:1220`, `dict(...)` over
   `enumerate_items_with_dict_position(value)`) `-> utils.py:3174` iterating the live `.items()` view of the program's globals dict, which
   `get_items_from_dict` (line 3152 in v2.14.0) returns unsnapshotted. In the same process, right after the crash, the same program
   compiled cleanly on one retry and crashed again on the next (race with garbage collection); in a fresh process it never crashes.
   The `origin` programs (no nested function, no `LOAD_GLOBAL` inside an inlined frame) never hit it, which is why the
   `origin` leg has only the `codegen_scalar_edge` artifact.

**Honest Setting B count.** Excluding both artifacts, TorchProbe's programs let our harness find **5 of 19** faults unmutated
(codegen_index_last, codegen_mod16_tail, codegen_value, functionalize_alias_to_copy, functionalize_drop_mutation) and **6 of 19** after all four mutations (capture_swallow_exception, codegen_index_last, codegen_mod16_tail, codegen_value, functionalize_alias_to_copy, functionalize_drop_mutation); the mutation that adds a detection is the
always-true `if` block (`insert_tcb`), whose condition on some programs makes eager raise on the faulty path and so exposes
`capture_swallow_exception` (structure oracle) on seed21 and seed23. Everything that needs a second context (dtype / layout /
scalar / requires_grad switch, warm cache, return trip) or a gradient stays out of reach with one input per program, exactly as
for NNSmith. With the same exclusion applied to NNSmith (`nnsmith_6` artifact), NNSmith native is 5 of 19.
