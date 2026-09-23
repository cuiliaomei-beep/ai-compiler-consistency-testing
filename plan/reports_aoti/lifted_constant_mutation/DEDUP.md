# Deduplication — in-place update of a lifted constant: export accepts, run_decompositions errors clearly, AOTI hits an INTERNAL ASSERT

Found 2026-09-10 by the export/AOTI differential on OpInfo `nn.functional.instance_norm` (all 8 samples with
running stats), reduced in `minimal_verified.py`: `F.instance_norm(x, RM, RV, use_input_stats=True)` (or
`F.batch_norm(..., training=True)`) where `RM`/`RV` are tensors captured from the enclosing scope, not buffers.
- eager / torch.compile: fine, RM/RV updated in place;
- `torch.export`: succeeds; the update to the (lifted) constant is silently dropped;
- `ep.run_decompositions()`: `RuntimeError: Constant lifted_tensor_0 is mutated in the forward method. Pls register
  it as buffer` (the intended diagnostic);
- `aoti_compile_and_package(ep)`: `false INTERNAL ASSERT FAILED at ".../ATen/RegisterFunctionalization_2.cpp":8058,
  please report a bug to PyTorch. mutating a non-functional tensor ...`.
With registered buffers all steps work.

Tracker (search API + reads, 2026-09-10): #150008 (closed 2026-05-31) "Mutating a non-functional tensor with a
functional tensor is not allowed" — the same functionalization assert class but for a `copy_` into a narrowed
view during `aot_export_module`, different trigger; #185130 (closed) "Fix prim view functionalization in export
decompositions"; nothing for "export constant tensor mutation instance_norm" / "lifted constant mutated in place".

Decision: **candidate** — two inconsistencies in one: export should reject (or at least flag) the constant mutation
at export time as `run_decompositions` does, and AOTI should not surface an internal assert that asks the user to
file a bug. Pending user review.
